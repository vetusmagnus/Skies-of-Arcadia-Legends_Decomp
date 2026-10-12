#!/usr/bin/env python3
"""Compile a C file with the game's flags and diff functions against the original asm.

usage: tools/match/fdiff.py SRC FN [FN...]
  CCV=<version>  compiler (default GC/1.3.2, the game's)
  XF="<flags>"   extra compiler flags
Prints `== FN: orig N mine M` per function, then a unified diff (empty = match). Relocated operands
(symbols, @ha/@l/@sda21) and call targets are masked, so names don't need to agree. Function names
are looked up in build/match/asmindex.pickle: run tools/match/asmindex.py build after renames.
"""
import os, re, subprocess, sys, difflib, pickle, glob

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
WORK = os.path.join(ROOT, "build", "match")
FLAGS = ('-nodefaults -proc gekko -align powerpc -enum int -fp hardware -Cpp_exceptions off -O4,p '
         '-inline auto -pragma "cats off" -pragma "warn_notinlined off" -maxerrors 1 -nosyspath -RTTI off '
         '-fp_contract on -str reuse -multibyte -i include -i build/GEAE8P/include -use_lmw_stmw on '
         '-i extern/sdk/include -i extern/sdk/libc -inline noauto')
INS = re.compile(r"^/\* [0-9A-F]{8} [0-9A-F]{8}  (?:[0-9A-F]{2} ){4}\*/\s+(.*)$")


def simp(x):
    x = re.sub(r"\s+", " ", x.strip())
    x = re.sub(r"(\"[^\"]*\"|[A-Za-z_@$][\w@$.]*)@(ha|l|h|sda21)\b", "S", x)
    x = re.sub(r"\"[^\"]*\"", "S", x)
    x = re.sub(r"^(bl|b) (?!\.L)\S+$", r"\1 S", x)
    x = re.sub(r"\b(lbl|jumptable|fn)_[0-9A-F]+", "S", x)
    x = re.sub(r"\.L_[0-9A-F]+", "L", x)
    return x


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
                out.append(m.group(1))
    return out


def main():
    src, fns = os.path.abspath(sys.argv[1]), sys.argv[2:]
    os.makedirs(WORK, exist_ok=True)
    obj = os.path.join(WORK, f"fd_{os.getpid()}.o")
    asm = os.path.join(WORK, f"fd_{os.getpid()}.s")
    ccv = os.environ.get("CCV", "1.3.2")
    cmd = f"build/tools/wibo build/compilers/GC/{ccv}/mwcceppc.exe {FLAGS} {os.environ.get('XF', '')} -c {src} -o {obj}"
    subprocess.run(cmd, shell=True, check=True, cwd=ROOT)
    subprocess.run([os.path.join(ROOT, "build/tools/dtk"), "elf", "disasm", obj, asm], check=True, capture_output=True)
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
                mine[cur].append(m.group(1))
    os.remove(obj)
    os.remove(asm)
    D = pickle.load(open(os.path.join(WORK, "asmindex.pickle"), "rb"))
    for fn in fns:
        o, m = [simp(x) for x in original(D, fn)], [simp(x) for x in mine.get(fn, [])]
        print(f"== {fn}: orig {len(o)} mine {len(m)}")
        for line in difflib.unified_diff(o, m, "orig", "mine", lineterm="", n=2):
            print(line)


if __name__ == "__main__":
    main()
