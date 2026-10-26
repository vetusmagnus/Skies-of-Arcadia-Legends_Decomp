Progress and handoff
====================

State of the game-code work as of 2026-10-25. Numbers live in the README status block and on
[ByteMatch](https://bytematch.dev/vetusmagnus/SoAL-Decomp); this page covers what's in flight.

Game files
----------

| File | Range | Status |
|---|---|---|
| `drawstate.c` | 0x801CA8D8-0x801CAE84 | linked |
| `uiobj.c` | 0x801C2FA0-0x801C5758 | 40 of 44; near: UiDrawNumber, UiLayoutDrawPart, UiLayoutDraw, UiSpriteDraw |
| `text.c` | 0x801E1F3C-0x801E3874 | 29 of 33; near: FontFindGlyph, TextNodeNew/NewN (0x8197 constant hoisted out of the copy loop), TextReadChar (extra `clrlwi`/`mr`) |
| `motion.c` | 0x801E3874-0x801E48A8 | 9 of 11; near: fn_801E3DE0 (u8 index mask), fn_801E41E0 (one extra saved register); fn_801E461C has no C |
| `flags.c` | 0x801E48A8-0x801E4C2C | 8 of 11; near: fn_801E48A8 (unrolled loop shape), fn_801E4984 (add operand order), fn_801E4AB0 (`mr` of a shift constant). The end is a guess |
| `model.c` | 0x801E4C2C-0x801E6148 | 17 of 17 so far; the file continues past 0x801E6148 (fn_801E6148, fn_801E6438, ... use its constants) |
| `tasks.c` | 0x80035918-0x8003DEE0 | 230 of 235 |

### tasks.c: what blocks linking

- Near misses: fn_80035918 (block layout of the null check), fn_80035C38 (two locals swap
  r29/r31; all 5040 declaration orders tried), fn_8003DBAC (divide/modulo scheduling),
  fn_8003DCF4 (register colouring in the third TargetMatch), fn_8003D2E4 (string addressing only,
  see below).
- Strings: the original keeps this file's literals in `.rodata` (0x802AD220-0x802AD28A). The game
  flags put them in `.data`; the object needs `-str reuse,readonly`. With that, fn_8003D2E4's offsets
  match.
- `.sdata2`: fn_8003DBAC's `"ABG"` local initialiser comes out last; the original has it first
  (0x803485D0), which shifts the rest by 4.
- `.data`: a 4-byte zero gap at 0x802DD234, between fn_8003617C's jump table and the task table
  `lbl_802DD238`, can't be reproduced. It may mean a file boundary around fn_8003617C.
- The file's start (0x80035918) comes from the constant pools (a new 0.0f at 0x803485E4, the
  `.sdata2` run from 0x803485D0); check it again when linking.

Agent batches
-------------

The 264 functions above (outside drawstate/uiobj/text) came from parallel agent batches. What
worked:

- One agent per batch of ~10-20 functions that are contiguous or siblings. Sonnet matched almost
  everything under 400 bytes, including every member of the task-handler family; Opus took the
  larger ones. The near misses were register allocation and block layout, not size, so batches of
  handler-style code up to ~0x300 bytes can go to Sonnet too.
- Each agent works only in `build/agents/<id>/`, one self-contained `fn_<addr>.c` per function, and
  verifies with `tools/match/fdiff.py`. Nothing touches `src/`, git or the build until a person
  (or the coordinating session) re-verifies every claimed match and integrates.
- Integration is its own step: merge a file's functions into one translation unit with shared
  types, then re-run fdiff over every function. Shared `static inline` helpers matter: the task
  allocation (`TaskAlloc`/`TaskNew`, the "Error: tasSetTask" checks) is inlined into 84 handlers,
  and several functions only match once their helper is defined once, before its users.
- Families pay off: matching one member and adapting it gave 86 handlers. Look for runs of
  functions with the same call pattern (`tools/match/asmindex.py`).

The brief each matching agent got (kept short; the prompt adds the agent id and its function
list):

> Match the assigned functions as plain C, one at a time, in your own folder
> `build/agents/<id>/`; don't edit `src/`, `include/`, `configure.py`, `config/`, docs or git, and
> don't run ninja/configure/git/pip. No inline asm, `#pragma`, register pinning or fakematches; the
> C must behave like the original. Keep unknown globals as `extern` with their label names. Tools:
> `asmindex.py asm FN` for the original, `fdiff.py FILE FN...` for the diff (a match prints only the
> header and maybe `unplaced N`; `-reloc`/`-branch` lines are real mismatches), `perm.py` and
> `vrun.py` for variant searches. Read `docs/matching.md` first. Stop after ~15-20 variants on one
> function. Report MATCHED / NEAR (diff lines, what differs) / SKIPPED, plus types and purposes
> worth naming.

Good next targets
-----------------

- `model.c` onwards from 0x801E6148: fn_801E6148, fn_801E6438, fn_801E66E0, ... (same constant
  pool, so the same file).
- The regions next to `tasks.c`: before 0x80035918 (resource loading, fn_80033050 ... fn_80035708)
  and after 0x8003DEE0 (sound sample loading, `.SAMP` strings at 0x802AD2CC).
- The near misses above, ideally with decomp-permuter (`tools/match/permsetup.py`) running in the
  background while new code is matched.
- The Ninja library (0x80286EE8-0x802AC7E0), 0% so far; see [ninja.md](ninja.md).
