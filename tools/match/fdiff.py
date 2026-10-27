#!/usr/bin/env python3
"""Compile a C file with the game's flags and diff functions against the original asm.

usage: tools/match/fdiff.py SRC FN [FN...]
  CCV=<version>  compiler (default GC/1.3.2, the game's)
  XF="<flags>"   extra compiler flags
Prints `== FN: orig N mine M` per function, then a unified diff (empty = match). Function names
are looked up in build/match/asmindex.pickle: run tools/match/asmindex.py build after renames.

The diff aligns on instructions with relocated operands (symbols, @ha/@l/@sda21) and call targets
masked, so names don't need to agree. Masking alone would accept a load from the wrong global or a
branch to the wrong label, so each aligned pair is then checked again:
  - a symbol both sides can place (a name in symbols.txt, or a fn_/lbl_ address name) must be the
    same address, plus the same offset;
  - a local branch must land on the instruction aligned with the original's target.
A mismatch prints as a `-reloc`/`+reloc` (or `-branch`/`+branch`) pair and counts as a diff.
Symbols one side can't place (the compiler's own @N literals and strings, statics not in
symbols.txt yet), and branches into unaligned code, are counted on the `unplaced` line: the full build is still the final check.
"""
import os, re, subprocess, sys, difflib, pickle, glob

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
WORK = os.path.join(ROOT, "build", "match")
FLAGS = ('-nodefaults -proc gekko -align powerpc -enum int -fp hardware -Cpp_exceptions off -O4,p '
         '-inline auto -pragma "cats off" -pragma "warn_notinlined off" -maxerrors 1 -nosyspath -RTTI off '
         '-fp_contract on -str reuse -multibyte -i include -i build/GEAE8P/include -use_lmw_stmw on '
         '-i extern/sdk/include -i extern/sdk/libc -inline noauto')
INS = re.compile(r"^/\* ([0-9A-F]{8}) [0-9A-F]{8}  (?:[0-9A-F]{2} ){4}\*/\s+(.*)$")
SYM = re.compile(r"(\"[^\"]*\"|[A-Za-z_@$.][\w@$.]*)((?:[+-]0x[0-9A-Fa-f]+)?)@(ha|l|h|sda21)\b")
CALL = re.compile(r"^(?:bl|b) (?!\.L)(\S+)$")
LABEL = re.compile(r"\.L_([0-9A-F]+)")
ADDR_NAME = re.compile(r"^(?:fn|lbl|jumptable)_([0-9A-F]{8})$")
POOLS = (".sdata2", ".rodata")
WINDOWS = os.name == "nt"


def tool(path):
    return os.path.join(ROOT, path + (".exe" if WINDOWS else ""))


def load_symbols():
    syms = {}
    for line in open(os.path.join(ROOT, "config", "GEAE8P", "symbols.txt"), errors="replace"):
        m = re.match(r"^(\S+) = (\.\w+):0x([0-9A-Fa-f]+);", line)
        if m:
            syms[m.group(1)] = (int(m.group(3), 16), m.group(2))
    return syms


def place(name, off, syms, orig):
    """Address a symbol refers to, or None if this side can't tell."""
    if name.startswith('"') or name.startswith("@"):
        return None
    if name in syms:
        addr, sect = syms[name]
        # The original's unnamed literal-pool entries are the compiler's own @N symbols on our side.
        if orig and sect in POOLS and ADDR_NAME.match(name):
            return None
    else:
        m = ADDR_NAME.match(name)
        if not m:
            return None
        addr = int(m.group(1), 16)
    return addr + (int(off, 16) if off else 0)


def simp(x):
    x = re.sub(r"\s+", " ", x.strip())
    x = re.sub(r"(\"[^\"]*\"|[A-Za-z_@$.][\w@$.]*)(?:[+-]0x[0-9A-Fa-f]+)?@(ha|l|h|sda21)\b", "S", x)
    x = re.sub(r"\"[^\"]*\"", "S", x)
    x = re.sub(r"^(bl|b) (?!\.L)\S+$", r"\1 S", x)
    x = re.sub(r"\b(lbl|jumptable|fn)_[0-9A-F]+", "S", x)
    x = re.sub(r"\.L_[0-9A-F]+", "L", x)
    return x


def refs(addr, text, start, syms, orig):
    """What one instruction points at: [('reloc', name, address|None) | ('branch', index)]."""
    text = re.sub(r"\s+", " ", text.strip())
    out = [("reloc", n + o, place(n, o, syms, orig)) for n, o, _ in SYM.findall(text)]
    m = CALL.match(text)
    if m:
        out.append(("reloc", m.group(1), place(m.group(1), "", syms, orig)))
    for lab in LABEL.findall(text):
        out.append(("branch", (int(lab, 16) - start) // 4))
    return out


def original(D, fn):
    f = D["by"][fn]
    path = glob.glob(os.path.join(ROOT, "build", "GEAE8P", "asm", "**", f["file"]), recursive=True)[0]
    out, on = [], False
    for line in open(path, errors="replace"):
        if line.startswith(".fn " + fn + ","):
            on = True
        elif on and line.startswith(".endfn"):
            break
        elif on:
            m = INS.match(line)
            if m:
                out.append((int(m.group(1), 16), m.group(2)))
    return out


def check(o, m, syms):
    """Compare what aligned, mask-equal instructions point at. Returns (diff lines, unplaced)."""
    so, sm = [simp(t) for _, t in o], [simp(t) for _, t in m]
    o0 = o[0][0] if o else 0
    m0 = m[0][0] if m else 0
    lines, unplaced = [], 0
    ops = [op for op in difflib.SequenceMatcher(None, so, sm, autojunk=False).get_opcodes() if op[0] == "equal"]
    # Branch targets are compared through the alignment, so an extra instruction elsewhere
    # doesn't flag every branch that jumps over it.
    to_mine = {i1 + k: j1 + k for _, i1, i2, j1, _ in ops for k in range(i2 - i1)}
    for _, i1, i2, j1, _ in ops:
        for k in range(i2 - i1):
            (oa, ot), (ma, mt) = o[i1 + k], m[j1 + k]
            for ro, rm in zip(refs(oa, ot, o0, syms, True), refs(ma, mt, m0, syms, False)):
                if ro[0] == "branch":
                    if ro[1] not in to_mine:
                        unplaced += 1
                    elif to_mine[ro[1]] != rm[1]:
                        lines += [f"-branch {(oa - o0) // 4}: {ot.strip()} -> insn {ro[1]}",
                                  f"+branch {(oa - o0) // 4}: {mt.strip()} -> insn {rm[1]}"]
                elif ro[2] is None or rm[2] is None:
                    unplaced += 1
                elif ro[2] != rm[2]:
                    lines += [f"-reloc {(oa - o0) // 4}: {ro[1]} ({ro[2]:#010x})",
                              f"+reloc {(oa - o0) // 4}: {rm[1]} ({rm[2]:#010x})"]
    return lines, unplaced


def main():
    src, fns = os.path.abspath(sys.argv[1]), sys.argv[2:]
    os.makedirs(WORK, exist_ok=True)
    obj = os.path.join(WORK, f"fd_{os.getpid()}.o")
    asm = os.path.join(WORK, f"fd_{os.getpid()}.s")
    ccv = os.environ.get("CCV", "1.3.2")
    cc = os.path.join("build", "compilers", "GC", ccv, "mwcceppc.exe")
    if not WINDOWS:
        cc = "build/tools/wibo " + cc
    cmd = f'{cc} {FLAGS} {os.environ.get("XF", "")} -c "{src}" -o "{obj}"'
    subprocess.run(cmd, shell=True, check=True, cwd=ROOT)
    subprocess.run([tool("build/tools/dtk"), "elf", "disasm", obj, asm], check=True, capture_output=True)
    mine, cur = {}, None
    for line in open(asm):
        m = re.match(r"^\.fn (\S+?),", line)
        if m:
            cur = m.group(1)
            mine[cur] = []
        elif line.startswith(".endfn"):
            cur = None
        elif cur:
            m = INS.match(line)
            if m:
                mine[cur].append((int(m.group(1), 16), m.group(2)))
    os.remove(obj)
    os.remove(asm)
    D = pickle.load(open(os.path.join(WORK, "asmindex.pickle"), "rb"))
    syms = load_symbols()
    for fn in fns:
        if fn not in D["by"]:
            print(f"== {fn}: not in the original (inline helper or a stale name?)")
            continue
        o, m = original(D, fn), mine.get(fn, [])
        so, sm = [simp(t) for _, t in o], [simp(t) for _, t in m]
        print(f"== {fn}: orig {len(so)} mine {len(sm)}")
        for line in difflib.unified_diff(so, sm, "orig", "mine", lineterm="", n=2):
            print(line)
        lines, unplaced = check(o, m, syms)
        for line in lines:
            print(line)
        if unplaced:
            print(f"   unplaced {unplaced} (symbols only one side can name; the full build checks them)")


if __name__ == "__main__":
    main()
