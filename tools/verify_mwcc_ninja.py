#!/usr/bin/env python3
"""Check tools/patch_mwcc_ninja.py against stock GC/1.3.2 on all the Ninja code we have.

usage: tools/verify_mwcc_ninja.py
       (after `ninja` and `tools/match/asmindex.py build`; builds build/compilers/GC/1.3.2nj)

For each compiler it compiles every Ninja unit built with 1.3.2nj (src/ninja/*.c except osreport.c,
which uses the SDK compiler) and diffs every function against the original with tools/match/fdiff.py.
A function counts as a match when fdiff prints no difference. Every function that matches with stock
1.3.2 must still match with 1.3.2nj (the regression check), and every function in the Ninja sources
must match with 1.3.2nj, the compiler configure.py builds them with. The ones that match only with
the patch are listed. Game code is not compiled with it: the game was built
with stock 1.3.2 behaviour (docs/ninja.md, "Copy pattern").
"""
import json
import os
import re
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


def defined_functions(src, names):
    text = open(src).read()
    return [n for n in names if re.search(r"^[A-Za-z][^\n;=]*\b" + n + r"\s*\(", text, re.M)]


def diff_counts(src, fns, ccv):
    out = {}
    for i in range(0, len(fns), 60):
        o = subprocess.run([sys.executable, "tools/match/fdiff.py", src] + fns[i:i + 60], cwd=ROOT,
                           capture_output=True, text=True, env=dict(os.environ, CCV=ccv)).stdout
        cur = None
        for line in o.splitlines():
            m = re.match(r"^== (\S+): orig \d+ mine \d+", line)
            if m:
                cur = m.group(1)
                out[cur] = 0
            elif cur and re.match(r"^[+-](?![+-])", line):
                out[cur] += 1
    return out


def main():
    os.chdir(ROOT)
    subprocess.run([sys.executable, "tools/patch_mwcc_ninja.py"], check=True)
    report = json.load(open("build/GEAE8P/report.json"))
    units = {u["name"].rsplit("/", 1)[-1]: [f["name"] for f in u.get("functions", [])]
             for u in report["units"] if "/ninja/" in u["name"]}
    srcs = sorted(f for f in os.listdir("src/ninja") if f.endswith(".c") and f != "osreport.c")
    ok = True
    total_keep = total_lost = total_only = total_bad = 0
    for name in srcs:
        src = "src/ninja/" + name
        ninja = defined_functions(src, units.get(name[:-2], []))
        if not ninja:
            print(f"{src}: no functions yet")
            continue
        stock = diff_counts(src, ninja, "1.3.2")
        patched = diff_counts(src, ninja, "1.3.2nj")
        keep = [f for f in ninja if stock.get(f) == 0]
        lost = [f for f in keep if patched.get(f) != 0]
        only = [f for f in ninja if patched.get(f) == 0 and stock.get(f) != 0]
        bad = [f for f in ninja if patched.get(f) != 0 and f not in lost]
        print(f"{src}: {len(ninja)} functions; {len(keep)} match with 1.3.2, "
              f"{len(keep) - len(lost)} of them still with 1.3.2nj")
        for f in lost:
            print(f"  lost: {f} ({patched.get(f)} diff lines)")
        if only:
            print(f"  {len(only)} match only with 1.3.2nj: {' '.join(only)}")
        for f in bad:
            print(f"  no match with 1.3.2nj: {f} ({patched.get(f)} diff lines)")
        total_keep += len(keep)
        total_lost += len(lost)
        total_only += len(only)
        total_bad += len(bad)
        ok = ok and not lost and not bad
    print(f"all Ninja units: {total_keep} match with 1.3.2, {total_keep - total_lost} still with 1.3.2nj; "
          f"{total_only} only with 1.3.2nj; {total_bad} with neither")
    print("OK" if ok else "FAILED")
    sys.exit(0 if ok else 1)


if __name__ == "__main__":
    main()
