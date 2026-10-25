#!/usr/bin/env python3
"""Reject matching shortcuts in game code.

usage: tools/check_game_src.py [--stamp FILE] PATH...

Game code under src/game/ and include/game/ must be plain C that the compiler turns into the
original bytes. This fails (exit 1, one line per hit) on anything that would let the build match
without that:
  - inline assembly (`asm`, `__asm`, `asm { }` blocks, `nofralloc`)
  - `#pragma` of any kind (optimization, scheduling, register and peephole pragmas included)
  - assembly or binary includes (`#include "*.s"`, `.incbin`, `INCLUDE_ASM`)
  - fakematch markers (`FAKEMATCH`, `NONMATCHING`, `fakematch`)
Library code under extern/ is not checked: its asm functions are asm in the original libraries.
Comments and string literals are ignored. With --stamp, FILE is touched on success (for ninja).
"""
import os, re, sys

RULES = [
    (re.compile(r"\b(?:__asm__|__asm|asm)\b"), "inline assembly"),
    (re.compile(r"\bnofralloc\b"), "inline assembly"),
    (re.compile(r"^\s*#\s*pragma\b"), "#pragma"),
    (re.compile(r"^\s*#\s*include\s*[<\"][^>\"]*\.(?:s|S|inc|bin)[>\"]"), "assembly or binary include"),
    (re.compile(r"\.incbin\b|\bINCLUDE_ASM\b|\bINCLUDE_RODATA\b"), "assembly or binary include"),
    (re.compile(r"\b(?:FAKEMATCH|NONMATCHING|fakematch)\b"), "fakematch marker"),
]
EXTS = (".c", ".cpp", ".h", ".hpp", ".inc")


def strip(text):
    """Blank out comments and string/char literals, keeping line numbers."""
    out, i, n = [], 0, len(text)
    while i < n:
        c = text[i]
        if text.startswith("/*", i):
            j = text.find("*/", i + 2)
            j = n if j < 0 else j + 2
            out.append(re.sub(r"[^\n]", " ", text[i:j]))
            i = j
        elif text.startswith("//", i):
            j = text.find("\n", i)
            j = n if j < 0 else j
            out.append(" " * (j - i))
            i = j
        elif c in "\"'":
            j = i + 1
            while j < n and text[j] != c and text[j] != "\n":
                j += 2 if text[j] == "\\" else 1
            j = min(j + 1, n)
            out.append(c + " " * (j - i - 2) + c if j - i >= 2 else text[i:j])
            i = j
        else:
            out.append(c)
            i += 1
    return "".join(out)


def files(paths):
    for p in paths:
        if os.path.isdir(p):
            for dp, _, fs in os.walk(p):
                for f in sorted(fs):
                    if f.endswith(EXTS):
                        yield os.path.join(dp, f)
        elif os.path.exists(p):
            yield p


def main():
    args, stamp = sys.argv[1:], None
    if args[:1] == ["--stamp"]:
        stamp, args = args[1], args[2:]
    hits = 0
    for path in files(args):
        with open(path, encoding="utf-8", errors="replace") as f:
            lines = strip(f.read()).splitlines()
        for no, line in enumerate(lines, 1):
            for rx, what in RULES:
                if rx.search(line):
                    print(f"{path}:{no}: {what} is not allowed in game code")
                    hits += 1
                    break
    if hits:
        print(f"check_game_src: {hits} problem(s); game code must be plain C")
        return 1
    if stamp:
        os.makedirs(os.path.dirname(stamp) or ".", exist_ok=True)
        open(stamp, "w").close()
    return 0


if __name__ == "__main__":
    sys.exit(main())
