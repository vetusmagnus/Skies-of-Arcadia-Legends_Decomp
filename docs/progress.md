Progress and handoff
====================

State of the game-code work as of 2026-10-26. Numbers live in the README status block and on
[ByteMatch](https://bytematch.dev/vetusmagnus/SoAL-Decomp); this page covers what's in flight.

Game files
----------

| File | Range | Status |
|---|---|---|
| `btlchar.c` | 0x80031254-0x80032E78 | 22 of 23; near: fn_80032C6C (prologue registers; an inline `Lookup` for the table search gets it to 14 lines, `build/agents/r6_1/`). The start is a guess |
| `draw2d.c` | 0x80032E78-0x80035918 | 31 of 35; near: fn_800334B8 (r0/r4 swap only in the textured branch, 96 lines in `build/agents/r6_2/`), fn_80033888 (a `frsp` from a double-typed value), fn_8003529C (saved-register order; the only fix found was a long-to-int local copy, rejected), fn_80035518 (12 lines in `build/agents/r6_2/`) |
| `tasks.c` | 0x80035918-0x8003DEE0 | 230 of 235 |
| `sound.c` | 0x8003DEE0-0x80040010 | 26 of 28; fn_8003E1BC and fn_8003ECF4 differ only in string offsets (see below) |
| `effect.c` | 0x80040010-0x80041238 | 11 of 11 so far; the file continues past 0x80041238 (fn_80041238 uses its constants) |
| `drawstate.c` | 0x801CA8D8-0x801CAE84 | linked |
| `uiobj.c` | 0x801C2FA0-0x801C5758 | 40 of 44; near: UiDrawNumber, UiLayoutDrawPart, UiLayoutDraw, UiSpriteDraw |
| `text.c` | 0x801E1F3C-0x801E3874 | 29 of 33; near: FontFindGlyph, TextNodeNew/NewN (0x8197 constant hoisted out of the copy loop), TextReadChar (extra `clrlwi`/`mr`) |
| `motion.c` | 0x801E3874-0x801E48A8 | 9 of 11; near: fn_801E3DE0 (u8 index mask), fn_801E41E0 (one extra saved register); fn_801E461C has no C |
| `flags.c` | 0x801E48A8-0x801E4C2C | 8 of 11; near: fn_801E48A8 (unrolled loop shape), fn_801E4984 (add operand order), fn_801E4AB0 (`mr` of a shift constant). The end is a guess |
| `model.c` | 0x801E4C2C-0x801E7654 | 38 of 39; near: fn_801E735C (one `addi` hoisted above the bounds check). Ends where a second u32-to-float constant starts (0x8034C018) |
| `chunk.c` | 0x801E7654-0x801E8CA4 | 14 of 15; near: fn_801E85BC (two locals swap registers). The end is a guess |
| `evobj.c` | 0x801E8CA4-0x801EA2DC | 1 of 3; near: fn_801E8CA4 (camera-vector stores fold their offsets), fn_801E9AE0 (20 lines in `build/agents/r6_4/`: unroll the scale loop with `f32* q` inside the body and a `CamDist` inline). The file continues past 0x801EA2DC |

`build/agents/` is gitignored, so the per-function work mentioned above only exists on the machine that ran
the batch.

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

### sound.c: strings

Like tasks.c, sound.c keeps its strings in `.rodata`: fn_8003E7A4's s16 table at lbl_802AD290 comes
first, then the strings in first-use order ("/SOUND/" is in `.sdata2`). With `-str reuse,readonly`
fn_8003ECF4's offsets match; fn_8003E1BC is still 0x3C off, because a local array initialiser is
emitted when its function is compiled, after the earlier strings. tasks.c's `.rodata` ends at
0x802AD28A and sound.c's starts at 0x802AD290, so the two may turn out to be one file.

Agent batches
-------------

The functions above outside drawstate/uiobj/text came from parallel agent batches (the 2026-10-26 batch: 16 agents on 137 functions, about 113 matched on the first pass and 126 after Opus retries and merging). What
worked:

- Sonnet for functions under ~1 KB, Opus for larger ones and for a second pass on the near misses,
  starting from the first pass's file. The second pass is worth it: inline helpers for a repeated
  block, pointer-walked destination arrays (`pv++` as the loop's last statement), a `switch` with
  `default:` first to stop constants being hoisted, and narrow return types (`s8`/`s16`) fixed most
  register and scheduling diffs.
- Merging is also a job for agents (one per file, Sonnet for small files), but re-run fdiff over every
  function of the merged file yourself, with no agent running (parallel runs of the tools can
  report false diffs), and reject tricks that only exist for the bytes: padding arrays sized for
  the frame, type-changing copies of a parameter.
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

- The files that continue past their guessed ends: `effect.c` from 0x80041238, `evobj.c` from
  0x801EA2DC (fn_801EA2DC, fn_801EB01C, ... share its constants).
- Before 0x80031254 (the start of `btlchar.c` is a guess; fn_80030B34 and fn_80030C94 are its task
  callbacks).
- The near misses above, ideally with decomp-permuter (`tools/match/permsetup.py`) running in the
  background while new code is matched.
- The Ninja library (0x80286EE8-0x802AC7E0), 0% so far; see [ninja.md](ninja.md).
