#!/usr/bin/env python3
"""Set up a decomp-permuter directory for one game function (works on Windows, no cpp needed).

usage: tools/match/permsetup.py SRC FN [OUTDIR]     (default OUTDIR: build/permuter/FN)
then:  python <decomp-permuter>/permuter.py OUTDIR -j8 --stop-on-zero

Writes base.c (SRC preprocessed by MWCC, every function body except FN's and the inline helpers
removed), target.o (FN's original asm, assembled), compile.sh (the game's compiler and flags) and
settings.toml. Needs `ninja` to have run (asm, compilers) and build/binutils (`ninja build/binutils`).
decomp-permuter calls `cpp` to preprocess base.c. Plain Windows has none: patch the permuter's
src/preprocess.py to return the file as is when `shutil.which("cpp")` is None (base.c is already
preprocessed here).

Permuter output is a hint, not a match: check what each candidate does (the permuter happily
changes behaviour), rewrite it as reasonable C, and confirm with fdiff.py and the full build.
"""
import os, re, subprocess, sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from fdiff import FLAGS, WINDOWS  # noqa: E402

EXE = ".exe" if WINDOWS else ""


def fwd(p):
    return os.path.abspath(p).replace("\\", "/")


def bracket_end(text, i):
    depth = 0
    while i < len(text):
        if text[i] == "{":
            depth += 1
        elif text[i] == "}":
            depth -= 1
            if depth == 0:
                return i
        i += 1
    raise ValueError("unbalanced braces")


def strip_bodies(text, keep):
    """Replace function bodies with ';', keeping FN and the inline functions without asm."""
    out, pos = [], 0
    rx = re.compile(r"^[^\n;{}#]*?\b(\w+)\s*\([^;{}]*\)\s*\{", re.M)
    while True:
        m = rx.search(text, pos)
        if not m:
            out.append(text[pos:])
            return "".join(out)
        end = bracket_end(text, m.end() - 1)
        head = text[m.start():m.end() - 1]
        body = text[m.end():end]
        # pycparser can't read MWCC's asm blocks (SDK inlines), so those become prototypes too.
        if m.group(1) == keep or (re.search(r"\binline\b", head) and not re.search(r"\basm\b", body)):
            out.append(text[pos:end + 1])
        else:
            out.append(text[pos:m.start()] + head.rstrip() + ";")
        pos = end + 1


def target_asm(fn):
    for dp, _, fs in os.walk(os.path.join(ROOT, "build", "GEAE8P", "asm")):
        for f in fs:
            if not f.endswith(".s"):
                continue
            lines, on = [], False
            for line in open(os.path.join(dp, f), errors="replace"):
                if line.startswith(f".fn {fn},"):
                    on = True
                if on:
                    lines.append(line)
                    if line.startswith(f".endfn {fn}"):
                        return lines
    sys.exit(f"{fn} not found in build/GEAE8P/asm (run ninja)")


def main():
    src, fn = sys.argv[1], sys.argv[2]
    out = sys.argv[3] if len(sys.argv) > 3 else os.path.join(ROOT, "build", "permuter", fn)
    os.makedirs(out, exist_ok=True)
    cc = os.path.join(ROOT, "build", "compilers", "GC", "1.3.2", "mwcceppc.exe")
    wrap = "" if WINDOWS else f'"{fwd(os.path.join(ROOT, "build", "tools", "wibo"))}" '
    pre = subprocess.run(f'{wrap}"{cc}" {FLAGS} -EP "{os.path.abspath(src)}"', shell=True, cwd=ROOT,
                         check=True, capture_output=True, text=True).stdout
    with open(os.path.join(out, "base.c"), "w", encoding="utf-8") as f:
        f.write(strip_bodies(pre, fn))
    with open(os.path.join(out, "target.s"), "w") as f:
        f.write('.include "macros.inc"\n.text\n' + "".join(target_asm(fn)))
    subprocess.run([os.path.join(ROOT, "build", "binutils", "powerpc-eabi-as" + EXE), "-mgekko",
                    "-I", os.path.join(ROOT, "build", "GEAE8P", "include"),
                    os.path.join(out, "target.s"), "-o", os.path.join(out, "target.o")], check=True)
    flags = FLAGS.replace("-i include -i build/GEAE8P/include", "").replace(
        "-i extern/sdk/include -i extern/sdk/libc", "")
    with open(os.path.join(out, "compile.sh"), "w", newline="\n") as f:
        f.write(f'#!/bin/bash\n{wrap}"{fwd(cc)}" {flags} -c "$1" -o "$3"\n')
    objdump = fwd(os.path.join(ROOT, "build", "binutils", "powerpc-eabi-objdump" + EXE))
    with open(os.path.join(out, "settings.toml"), "w") as f:
        f.write(f'func_name = "{fn}"\ncompiler_type = "mwcc"\n'
                f'objdump_command = "{objdump} -drz -m powerpc"\n')
    print(out)


if __name__ == "__main__":
    main()
