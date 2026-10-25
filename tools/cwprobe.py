#!/usr/bin/env python3
"""Compile a C file with several MWCC versions and compare against original functions.

Used to pin down which CodeWarrior version (and flags) the game was built with.
Relocated fields are masked on both sides, like objdiff does.

Usage:
    python tools/cwprobe.py probe.c [-v 1.3.2 2.0 2.6] [-f "-O4,p" ...]

Each function in probe.c must be named after the original symbol in
config/GEAE8P/symbols.txt (e.g. fn_80012345). The target is read from the
dtk-split objects in build/GEAE8P/obj.
"""

import argparse
import glob
import shlex
import struct
import os
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
VERSION = "GEAE8P"
DEFAULT_VERSIONS = ["1.3.2", "2.0"]
DEFAULT_FLAGS = [
    "-nodefaults", "-proc gekko", "-align powerpc", "-enum int", "-fp hardware",
    "-Cpp_exceptions off", "-O4,p", "-inline auto", '-pragma "cats off"',
    '-pragma "warn_notinlined off"', "-maxerrors 1", "-nosyspath", "-RTTI off",
    "-fp_contract on", "-str reuse", "-multibyte", "-i include", "-use_lmw_stmw on",
]

# Bits rewritten by each PPC relocation type.
RELOC_MASKS = {
    1: 0xFFFFFFFF,  # R_PPC_ADDR32
    4: 0x0000FFFF,  # R_PPC_ADDR16_LO
    5: 0x0000FFFF,  # R_PPC_ADDR16_HI
    6: 0x0000FFFF,  # R_PPC_ADDR16_HA
    10: 0x03FFFFFC,  # R_PPC_REL24
    11: 0x0000FFFC,  # R_PPC_REL14
    109: 0x001FFFFF,  # R_PPC_EMB_SDA21
}


def read_elf(path):
    """Return {func_name: [masked instruction words]} for every .text function."""
    data = Path(path).read_bytes()
    assert data[:4] == b"\x7fELF" and data[5] == 2, f"{path}: not a big-endian ELF"
    shoff, = struct.unpack_from(">I", data, 0x20)
    shentsize, shnum, shstrndx = struct.unpack_from(">HHH", data, 0x2E)
    shdrs = [struct.unpack_from(">IIIIIIIIII", data, shoff + i * shentsize) for i in range(shnum)]
    strtab_off = shdrs[shstrndx][4]

    def cstr(off):
        return data[off:data.index(b"\0", off)].decode()

    names = [cstr(strtab_off + s[0]) for s in shdrs]
    funcs = {}
    for idx, sh in enumerate(shdrs):
        if sh[1] != 2:  # SHT_SYMTAB
            continue
        sym_str_off = shdrs[sh[6]][4]
        syms = []
        for i in range(sh[5] // 16):
            name_off, value, size, info, _, shndx = struct.unpack_from(">IIIBBH", data, sh[4] + i * 16)
            syms.append((cstr(sym_str_off + name_off), value, size, info & 0xF, shndx))
        # Relocations targeting each section.
        relocs = {}
        for rsh in shdrs:
            if rsh[1] == 4 and rsh[6] == idx:  # SHT_RELA against this symtab
                for i in range(rsh[5] // 12):
                    r_off, r_info, _ = struct.unpack_from(">IIi", data, rsh[4] + i * 12)
                    relocs.setdefault(rsh[7], {})[r_off & ~3] = RELOC_MASKS.get(r_info & 0xFF, 0xFFFFFFFF)
        for name, value, size, typ, shndx in syms:
            if typ != 2 or shndx == 0 or shndx >= len(shdrs) or not names[shndx].startswith(".text"):
                continue
            sec = shdrs[shndx]
            words = []
            for off in range(value, value + size, 4):
                w, = struct.unpack_from(">I", data, sec[4] + off)
                words.append(w & ~relocs.get(shndx, {}).get(off, 0))
            funcs[name] = words
    return funcs


def load_targets():
    targets = {}
    for obj in glob.glob(str(ROOT / "build" / VERSION / "obj" / "*.o")):
        targets.update(read_elf(obj))
    if not targets:
        sys.exit("No split objects found; run `ninja` first.")
    return targets


def compile_c(src, mw_version, flags, out):
    cc = ROOT / "build" / "compilers" / "GC" / mw_version / "mwcceppc.exe"
    cmd = [str(cc), *shlex.split(" ".join(flags)), "-c", str(src), "-o", str(out)]
    if os.name != "nt":
        cmd.insert(0, str(ROOT / "build" / "tools" / "wibo"))
    res = subprocess.run(cmd, cwd=ROOT, capture_output=True, text=True)
    if res.returncode != 0:
        return res.stdout + res.stderr
    return None


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("source")
    ap.add_argument("-v", "--versions", nargs="+", default=DEFAULT_VERSIONS)
    ap.add_argument("-f", "--flags", nargs="+", default=[], help="extra flags appended to the defaults")
    ap.add_argument("--verbose", action="store_true", help="show first differing word per function")
    args = ap.parse_args()

    targets = load_targets()
    flags = DEFAULT_FLAGS + args.flags
    with tempfile.TemporaryDirectory() as tmp:
        for v in args.versions:
            out = Path(tmp) / f"{v}.o"
            err = compile_c(args.source, v, flags, out)
            if err:
                print(f"{v:>6}: compile error\n{err}")
                continue
            ours = read_elf(out)
            results = []
            for name, words in ours.items():
                tgt = targets.get(name)
                if tgt is None:
                    results.append(f"{name}=?")
                    continue
                same = sum(a == b for a, b in zip(words, tgt))
                ok = words == tgt
                results.append(f"{name}={'MATCH' if ok else f'{same}/{len(tgt)}'}")
                if args.verbose and not ok:
                    for i, (a, b) in enumerate(zip(words, tgt)):
                        if a != b:
                            results[-1] += f" (+{i*4:#x}: {a:08x} vs {b:08x}, len {len(words)} vs {len(tgt)})"
                            break
                    else:
                        results[-1] += f" (len {len(words)} vs {len(tgt)})"
            print(f"{v:>6}: " + "  ".join(results))


if __name__ == "__main__":
    main()
