#!/usr/bin/env python3
"""Reconcile splits.txt boundaries with dtk's guessed data symbols in symbols.txt.

dtk refuses a split that starts or ends inside a symbol. For each split boundary that does:
  - end inside a symbol whose remainder is zero padding -> extend the split end to the symbol end
    (only if that doesn't run into the next split)
  - otherwise -> trim the guessed symbol so it stops at the boundary (dtk's sizes are guesses)
It also extends a split end over a gap of fewer than 8 zero bytes to the next split when no symbol
starts in the gap (alignment padding; otherwise dtk makes an odd-sized gap object of it).

Usage: python tools/fixsplits.py [--dry-run]
"""

import argparse
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from tusplit import DOL, SYMBOLS, Dol  # noqa: E402

ROOT = Path(__file__).resolve().parent.parent
SPLITS = ROOT / "config" / "GEAE8P" / "splits.txt"
SYM_RE = re.compile(r"^(\S+) = (\.\w+):0x([0-9A-Fa-f]+); // (.*)$")
SPLIT_RE = re.compile(r"^(\s+)(\S+)(\s+)start:0x([0-9A-Fa-f]+) end:0x([0-9A-Fa-f]+)(.*)$")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--dry-run", action="store_true")
    args = ap.parse_args()
    dol = Dol(DOL)

    sym_lines = SYMBOLS.read_text().splitlines()
    syms = []  # (line index, section, addr, size)
    for i, line in enumerate(sym_lines):
        m = SYM_RE.match(line)
        if m:
            size = re.search(r"size:0x([0-9A-Fa-f]+)", m.group(4))
            if size:
                syms.append([i, m.group(2), int(m.group(3), 16), int(size.group(1), 16)])

    split_lines = SPLITS.read_text().splitlines()
    ranges = {}  # section -> [(start, end, line index)]
    for i, line in enumerate(split_lines):
        m = SPLIT_RE.match(line)
        if m:
            ranges.setdefault(m.group(2), []).append([int(m.group(4), 16), int(m.group(5), 16), i])
    for r in ranges.values():
        r.sort()

    changes = 0
    for sec, rs in ranges.items():
        sec_syms = [s for s in syms if s[1] == sec]
        for k, r in enumerate(rs):
            start, end, li = r
            next_start = rs[k + 1][0] if k + 1 < len(rs) else None
            for s in sec_syms:
                _, _, a, size = s
                # split end lands inside a symbol
                if a < end < a + size:
                    tail = dol.read(end, a + size - end)
                    is_bss = tail is None
                    fits = next_start is None or a + size <= next_start
                    if fits and (is_bss or not any(tail)) and (a + size - end) < 8:
                        print(f"{sec} extend split end {end:#x} -> {a + size:#x} (padding)")
                        r[1] = a + size
                        end = a + size
                    else:
                        print(f"{sec} trim symbol at {a:#x} size {size:#x} -> {end - a:#x}")
                        s[3] = end - a
                    changes += 1
                # split start lands inside a symbol
                if a < start < a + size:
                    print(f"{sec} trim symbol at {a:#x} size {size:#x} -> {start - a:#x}")
                    s[3] = start - a
                    changes += 1

        for k, r in enumerate(rs):
            start, end, li = r
            nxt = rs[k + 1][0] if k + 1 < len(rs) else None
            if nxt is None or not 0 < nxt - end < 8 or any(end <= s[2] < nxt for s in sec_syms):
                continue
            gap = dol.read(end, nxt - end)
            if gap is None or not any(gap):
                print(f"{sec} extend split end {end:#x} -> {nxt:#x} (padding before next split)")
                r[1] = nxt
                changes += 1

    if args.dry_run or not changes:
        print(f"{changes} change(s){' (dry run)' if args.dry_run else ''}")
        return
    for i, sec, a, size in syms:
        sym_lines[i] = re.sub(r"size:0x[0-9A-Fa-f]+", f"size:0x{size:X}", sym_lines[i])
    for rs in ranges.values():
        for start, end, li in rs:
            m = SPLIT_RE.match(split_lines[li])
            split_lines[li] = f"{m.group(1)}{m.group(2)}{m.group(3)}start:0x{start:08X} end:0x{end:08X}{m.group(6)}"
    SYMBOLS.write_text("\n".join(sym_lines) + "\n")
    SPLITS.write_text("\n".join(split_lines) + "\n")
    print(f"{changes} change(s) written")


if __name__ == "__main__":
    main()
