#!/usr/bin/env python3
"""Try every order of a block of declaration lines in one function (MWCC's register allocation and
stack layout follow declaration order), 8 at a time, best first.

usage: tools/match/perm.py SRC FN 'decl1;' 'decl2;' ...   (the lines must appear contiguously, in this
order, indented by 4 spaces)
"""
import sys, itertools
from concurrent.futures import ThreadPoolExecutor
from _common import score

src, fn, decls = sys.argv[1], sys.argv[2], sys.argv[3:]
text = open(src).read()
block = "\n".join("    " + d for d in decls)
assert block in text, "declaration block not found"
perms = list(itertools.permutations(decls))
def run(a):
    k, p = a
    return score(text.replace(block, "\n".join("    " + d for d in p)), [fn], k), p
with ThreadPoolExecutor(8) as ex:
    res = sorted(ex.map(run, enumerate(perms)))
for n, p in res[:10]:
    print(n, " ".join(p))
