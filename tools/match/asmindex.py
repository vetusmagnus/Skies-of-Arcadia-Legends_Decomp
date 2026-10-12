#!/usr/bin/env python3
"""Call graph, reference and string index over dtk's asm (build/GEAE8P/asm), for research and
for tools/match/fdiff.py. Rebuild the index after `ninja` regenerates the asm (renames, splits).

usage: asmindex.py build              (re)build the index (build/match/asmindex.pickle)
       asmindex.py asm FN...          print a function's original asm (address + instruction)
       asmindex.py strings REGEX      strings in the data sections, with the functions using them
       cg.py callers FN...     who calls FN (bl / b / address loads)
       cg.py callees FN...     what FN calls
       cg.py refs LBL...       functions that reference a data label
       cg.py data FN...        data labels FN references
       cg.py tree FN [DEPTH]   callee tree
       cg.py up FN [DEPTH]     caller tree
       cg.py info FN...        size and file
"""
import os, re, sys, pickle, glob

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
ASM = os.path.join(ROOT, "build", "GEAE8P", "asm")
IDX = os.path.join(ROOT, "build", "match", "asmindex.pickle")

FN_RE = re.compile(r"^\.fn (\S+?),")
END_RE = re.compile(r"^\.endfn")
INS_RE = re.compile(r"^/\* ([0-9A-F]{8}) [0-9A-F]{8}  (?:[0-9A-F]{2} ){4}\*/\s+(\S+)\s*(.*)$")
SYM_RE = re.compile(r"\b((?:fn|lbl|jumptable|gap)_[0-9A-Fa-f_]+[0-9A-Fa-f]|[A-Za-z_][A-Za-z0-9_]*)(?:@[a-z0-9]+)?")


def build():
    files = []
    for f in glob.glob(os.path.join(ASM, "**", "*.s"), recursive=True):
        files.append((os.path.getmtime(f), f))
    files.sort()  # newest last wins
    funcs = {}
    for _, f in files:
        cur = None
        with open(f, errors="replace") as fh:
            for line in fh:
                m = FN_RE.match(line)
                if m:
                    cur = {"name": m.group(1), "file": os.path.basename(f), "addr": None, "end": None,
                           "calls": [], "tails": [], "data": set(), "fnrefs": set(), "n": 0}
                    continue
                if cur is None:
                    continue
                if END_RE.match(line):
                    if cur["addr"] is not None:
                        funcs[cur["addr"]] = cur
                    cur = None
                    continue
                m = INS_RE.match(line)
                if not m:
                    continue
                addr = int(m.group(1), 16)
                if cur["addr"] is None:
                    cur["addr"] = addr
                cur["end"] = addr + 4
                cur["n"] += 1
                op, args = m.group(2), m.group(3)
                if op == "bl":
                    cur["calls"].append(args.strip())
                elif op == "b" and not args.startswith(".L"):
                    cur["tails"].append(args.strip())
                for s in re.findall(r"\b(lbl_[0-9A-F]+|fn_[0-9A-F]+|jumptable_[0-9A-F]+|[A-Za-z_][A-Za-z0-9_]*)@", args):
                    if s.startswith("fn_") or (not s.startswith("lbl_") and not s.startswith("jumptable_")):
                        cur["fnrefs"].add(s)
                    else:
                        cur["data"].add(s)
    byname = {}
    for a, f in funcs.items():
        f["data"] = sorted(f["data"])
        f["fnrefs"] = sorted(f["fnrefs"])
        byname[f["name"]] = f
    callers = {}
    for f in funcs.values():
        for c in f["calls"] + f["tails"] + f["fnrefs"]:
            callers.setdefault(c, []).append(f["name"])
    refs = {}
    for f in funcs.values():
        for d in f["data"]:
            refs.setdefault(d, []).append(f["name"])
    os.makedirs(os.path.dirname(IDX), exist_ok=True)
    strings = {}
    for f in sorted(glob.glob(os.path.join(ASM, "auto_0[4-9]_*.s")), key=os.path.getmtime):
        cur = None
        for line in open(f, errors="replace"):
            m = re.match(r"^\.obj (\S+?),", line)
            if m:
                cur = m.group(1)
                continue
            m = re.match(r'^\s*\.string "(.*)"$', line)
            if m and cur:
                strings.setdefault(cur, []).append(m.group(1))
    with open(IDX, "wb") as fh:
        pickle.dump({"by": byname, "callers": callers, "refs": refs, "strings": strings}, fh)
    print(len(byname), "functions")


def load():
    with open(IDX, "rb") as fh:
        return pickle.load(fh)


def uniq(xs):
    seen, out = set(), []
    for x in xs:
        if x not in seen:
            seen.add(x)
            out.append(x)
    return out


def fmt(D, n):
    f = D["by"].get(n)
    if not f:
        return n
    return f"{n} (0x{f['end'] - f['addr']:X})"


def main():
    if len(sys.argv) < 2:
        print(__doc__)
        return
    cmd = sys.argv[1]
    if cmd == "build":
        build()
        return
    D = load()
    args = sys.argv[2:]
    if cmd == "asm":
        for n in args:
            f = D["by"][n]
            path = glob.glob(os.path.join(ASM, "**", f["file"]), recursive=True)[0]
            on = False
            for line in open(path, errors="replace"):
                if line.startswith(".fn " + n + ","):
                    on = True
                if on:
                    print(re.sub(r"^/\* ([0-9A-F]{8}) [0-9A-F]{8}  (?:[0-9A-F]{2} ){4}\*/\t?", r"\1 ", line), end="")
                    if line.startswith(".endfn"):
                        break
        return
    if cmd == "strings":
        rx = re.compile(args[0], re.I)
        for lbl, ss in D["strings"].items():
            for s in ss:
                if rx.search(s):
                    print(lbl, " ".join(sorted(set(D["refs"].get(lbl, [])))) or "-", "|", s[:100])
        return
    if cmd == "callers":
        for n in args:
            print(n + ":", " ".join(fmt(D, x) for x in uniq(D["callers"].get(n, []))))
    elif cmd == "callees":
        for n in args:
            f = D["by"][n]
            print(n + ":", " ".join(uniq(f["calls"] + ["b:" + t for t in f["tails"]] + ["&" + r for r in f["fnrefs"]])))
    elif cmd == "refs":
        for n in args:
            print(n + ":", " ".join(fmt(D, x) for x in uniq(D["refs"].get(n, []))))
    elif cmd == "data":
        for n in args:
            print(n + ":", " ".join(D["by"][n]["data"]))
    elif cmd == "info":
        for n in args:
            f = D["by"][n]
            print(f"{n} 0x{f['addr']:08X}-0x{f['end']:08X} size 0x{f['end'] - f['addr']:X} {f['file']} callers={len(uniq(D['callers'].get(n, [])))}")
    elif cmd in ("tree", "up"):
        root = args[0]
        depth = int(args[1]) if len(args) > 1 else 3
        seen = set()

        def walk(n, d, pre):
            kids = uniq(D["by"][n]["calls"] + D["by"][n]["tails"]) if cmd == "tree" and n in D["by"] else \
                uniq(D["callers"].get(n, [])) if cmd == "up" else []
            for k in kids:
                rep = k in seen
                print(pre + fmt(D, k) + (" ..." if rep and d < depth else ""))
                if not rep and d < depth:
                    seen.add(k)
                    walk(k, d + 1, pre + "  ")
        print(fmt(D, root))
        walk(root, 1, "  ")


if __name__ == "__main__":
    main()
