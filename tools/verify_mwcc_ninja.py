#!/usr/bin/env python3
"""Check tools/patch_mwcc_ninja.py against stock GC/1.3.2 on all the Ninja code we have.

usage: tools/verify_mwcc_ninja.py
       (after `ninja` and `tools/match/asmindex.py build`; builds build/compilers/GC/1.3.2nj)

For each compiler it compiles src/ninja/ninja.c and the plain-C files in docs/mwcc_ninja/ and
diffs every function against the original with tools/match/fdiff.py. A function counts as a
match when fdiff prints no difference. The patched compiler must keep every ninja.c function
that matches with stock and match the docs/mwcc_ninja/ functions. Game code is not compiled
with it: the game was built with stock 1.3.2 behaviour (docs/ninja.md, "Copy pattern").
"""
import glob
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
    names = [f["name"] for u in report["units"] if u["name"].endswith("ninja/ninja")
             for f in u.get("functions", [])]
    ninja = defined_functions("src/ninja/ninja.c", names)
    stock = diff_counts("src/ninja/ninja.c", ninja, "1.3.2")
    patched = diff_counts("src/ninja/ninja.c", ninja, "1.3.2nj")
    keep = [f for f in ninja if stock.get(f) == 0]
    lost = [f for f in keep if patched.get(f) != 0]
    print(f"src/ninja/ninja.c: {len(keep)} functions match with 1.3.2; "
          f"{len(keep) - len(lost)} still match with 1.3.2nj")
    for f in lost:
        print(f"  lost: {f} ({patched.get(f)} diff lines)")
    ok = not lost
    for path in sorted(glob.glob("docs/mwcc_ninja/*.c")):
        fn = os.path.splitext(os.path.basename(path))[0]
        s, p = diff_counts(path, [fn], "1.3.2").get(fn), diff_counts(path, [fn], "1.3.2nj").get(fn)
        print(f"{path}: 1.3.2 {s} diff lines, 1.3.2nj {p}")
        ok &= p == 0
    print("OK" if ok else "FAILED")
    sys.exit(0 if ok else 1)


if __name__ == "__main__":
    main()
