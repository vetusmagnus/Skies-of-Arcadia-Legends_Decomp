#!/usr/bin/env python3
"""Group functions whose code is identical once addresses are masked.

usage: dupes.py [-o docs/duplicates.txt]

Reads dtk's asm (build/GEAE8P/asm/auto_*.s), masks symbol names, branch targets and @ha/@l/@sda
operands, and groups functions with the same masked instruction stream. Members that are defined in
src/ count as matched; a group needs matching only once, then the others are copies to re-verify.
Singletons are not listed. Groups are ordered by size, largest first.
"""
import glob, os, re, sys, collections

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
INSN = re.compile(r"^/\* ([0-9A-F]{8}) [0-9A-F]{8}  (?:[0-9A-F]{2} ){4}\*/\t(.*)$")
SYM = re.compile(r"\.L_[0-9A-F]+|(?:fn|lbl|jumptable|gap|zz)_[0-9A-Fa-f]+|\b[A-Za-z_][\w.$]*@(?:ha|l|sda21|sda2|h)\b")
SYM2 = re.compile(r"(?:\b[A-Za-z_][\w.$]*)?@(?:ha|l|h|sda21|sda2)\b")


def mask(line):
    line = SYM.sub("SYM", line)
    return SYM2.sub("SYM", line)


def functions():
    for path in sorted(glob.glob(os.path.join(ROOT, "build", "GEAE8P", "asm", "auto_*.s"))):
        name, body = None, []
        for raw in open(path, encoding="utf-8", errors="replace"):
            raw = raw.rstrip("\n")
            if raw.startswith(".fn "):
                name, body = raw.split()[1].rstrip(","), []
            elif raw.startswith(".endfn"):
                if name and body:
                    yield name, body
                name = None
            elif name:
                m = INSN.match(raw)
                if m:
                    body.append((m.group(1), mask(m.group(2))))


def defined_in_src():
    names = set()
    for p in glob.glob(os.path.join(ROOT, "src", "game", "*.c")):
        for l in open(p, encoding="utf-8", errors="replace"):
            m = re.match(r"^[A-Za-z_][\w \*]*?\b(fn_[0-9A-F]{8})\s*\(.*\)\s*\{?\s*$", l)
            if m and not l.rstrip().endswith(";"):
                names.add(m.group(1))
    return names


def main():
    out = "docs/duplicates.txt"
    if "-o" in sys.argv:
        out = sys.argv[sys.argv.index("-o") + 1]
    groups = collections.defaultdict(list)
    seen = set()
    total = 0
    for name, body in functions():
        if name in seen:  # the asm files overlap where splits were added
            continue
        seen.add(name)
        total += 1
        groups[tuple(i for _, i in body)].append((name, len(body) * 4))
    done = defined_in_src()
    dup = [g for g in groups.values() if len(g) > 1]
    dup.sort(key=lambda g: (-g[0][1], g[0][0]))
    extra = sum(len(g) - 1 for g in dup)
    with open(os.path.join(ROOT, out), "w", newline="\n") as fh:
        fh.write("Duplicate functions (identical code once symbols and branch targets are masked)\n")
        fh.write("Regenerate with: python tools/match/dupes.py\n")
        fh.write("%d functions, %d unique, %d duplicate groups covering %d functions (%d copies)\n"
                 % (total, len(groups), len(dup), sum(len(g) for g in dup), extra))
        fh.write("Format: group size members (* = defined in src/)\n\n")
        for i, g in enumerate(dup, 1):
            mem = " ".join(n[3:] + ("*" if n in done else "") for n, _ in sorted(g))
            fh.write("%d 0x%X %s\n" % (i, g[0][1], mem))
    print("functions %d unique %d groups %d copies %d" % (total, len(groups), len(dup), extra))


main()
