#!/usr/bin/env python3
"""Try text substitutions in a source file and report each variant's diff line count.

usage: tools/match/vrun.py SRC FN 'OLD' 'NEW1' ['NEW2' ...]   (999 = didn't compile)
"""
import sys
from _common import score

src, fn, old = sys.argv[1], sys.argv[2], sys.argv[3]
text = open(src).read()
assert old in text, "OLD not found"
print(f"[base] {score(text, [fn], 'base')}")
for i, new in enumerate(sys.argv[4:]):
    print(f"[{i}] {score(text.replace(old, new), [fn], i)}: {new[:90]!r}")
