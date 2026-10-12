#!/usr/bin/env python3
"""Swap in whole-function variants and report diff counts.

usage: tools/match/fvar.py SRC FN VARFILE   (VARFILE: complete definitions of FN separated by lines
'@@@'; each replaces FN from its definition line to the next line that is exactly '}')
  DIFF="FN1 FN2"  diff these functions instead (e.g. the callers of a changed inline)
"""
import os, re, sys
from _common import score

src, fn, vf = sys.argv[1:4]
lines = open(src).read().split("\n")
start = next(i for i, l in enumerate(lines) if re.match(r"^\S.*\b" + re.escape(fn) + r"\(", l) and not l.endswith(";"))
end = next(i for i in range(start, len(lines)) if lines[i] == "}")
fns = os.environ.get("DIFF", fn).split()
for k, body in enumerate(open(vf).read().split("\n@@@\n")):
    text = "\n".join(lines[:start] + [body.strip("\n")] + lines[end + 1:])
    print(f"[{k}] {score(text, fns, k)}: {body.strip().splitlines()[0][:80]}")
