Progress and handoff
====================

State of the game-code work as of 2026-10-26 (after batch 2). Numbers live in the README status block and on
[ByteMatch](https://bytematch.dev/vetusmagnus/SoAL-Decomp); this page covers what's in flight.

Game files
----------

| File | Range | Status |
|---|---|---|
| `battle.c` | 0x8002C010-0x80031254 | 83 of 101; near: fn_8002C51C, fn_8002C8FC, fn_8002CA54, fn_8002CBF8 (clamp temps in swapped registers), fn_8002D72C (the original keeps a dead loop counter), fn_8002E320 (`mulli -1` vs `neg`), fn_8002E5D0 (register colouring only), fn_8002EEFC, fn_8002F35C, fn_8002F598, fn_8002F630 (base pointer folded into an `addi`), fn_8002F6D4, fn_8002F80C, fn_8002FA00, fn_80030100, fn_80030280, fn_800303EC, fn_800308FC (string offsets only; the strings sit at lbl_802AD0F8+0x78, so `-str reuse,readonly` like tasks.c). The start is a guess |
| `btlchar.c` | 0x80031254-0x80032E78 | 22 of 23; near: fn_80032C6C (prologue registers; an inline `Lookup` for the table search gets it to 14 lines, `build/agents/r6_1/`). The start is a guess |
| `draw2d.c` | 0x80032E78-0x80035918 | 31 of 35; near: fn_800334B8 (r0/r4 swap only in the textured branch, 96 lines in `build/agents/r6_2/`), fn_80033888 (a `frsp` from a double-typed value), fn_8003529C (saved-register order; the only fix found was a long-to-int local copy, rejected), fn_80035518 (12 lines in `build/agents/r6_2/`) |
| `tasks.c` | 0x80035918-0x8003DEE0 | 230 of 235 |
| `sound.c` | 0x8003DEE0-0x80040010 | 26 of 28; fn_8003E1BC and fn_8003ECF4 differ only in string offsets (see below) |
| `effect.c` | 0x80040010-0x80047214 | 27 of 29; near: fn_80041E64 (operand order of one `add`), fn_800470F0 (register allocation in the quad loop). The end is a guess |
| `drawstate.c` | 0x801CA8D8-0x801CAE84 | linked |
| `uiobj.c` | 0x801C2FA0-0x801C5758 | 40 of 44; near: UiDrawNumber, UiLayoutDrawPart, UiLayoutDraw, UiSpriteDraw |
| `text.c` | 0x801E1F3C-0x801E3874 | 29 of 33; near: FontFindGlyph, TextNodeNew/NewN (0x8197 constant hoisted out of the copy loop), TextReadChar (extra `clrlwi`/`mr`) |
| `motion.c` | 0x801E3874-0x801E48A8 | 9 of 11; near: fn_801E3DE0 (u8 index mask), fn_801E41E0 (one extra saved register); fn_801E461C has no C |
| `flags.c` | 0x801E48A8-0x801E4C2C | 8 of 11; near: fn_801E48A8 (unrolled loop shape), fn_801E4984 (add operand order), fn_801E4AB0 (`mr` of a shift constant). The end is a guess |
| `model.c` | 0x801E4C2C-0x801E7654 | 38 of 39; near: fn_801E735C (one `addi` hoisted above the bounds check). Ends where a second u32-to-float constant starts (0x8034C018) |
| `chunk.c` | 0x801E7654-0x801E8CA4 | 14 of 15; near: fn_801E85BC (two locals swap registers). The end is a guess |
| `evobj.c` | 0x801E8CA4-0x801EE324 | 5 of 18; near: fn_801E8CA4 (camera-vector stores fold their offsets), fn_801E9AE0 (20 lines in `build/agents/r6_4/`), fn_801EB01C (6 lines, two `addi` swapped), fn_801EBC5C (8, a state store scheduled after the next compare), fn_801EE140 (3, indexed `stbx` vs a walked pointer), fn_801EDF24 (same), fn_801EC854, fn_801ECA2C, fn_801ED074, fn_801ED69C, fn_801EDAC0 (register colouring around the ObjTurn inline), fn_801EA2DC and fn_801EB330 (large, far off). The end is a guess |

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

The functions above outside drawstate/uiobj/text came from parallel agent batches: batch 1 (16 agents on
137 functions, 126 matched after Opus retries and merging) and batch 2 (16 agents on 177 functions, 103
matched; Sonnet only).

**Model rule (from 2026-10-26, for usage):** no Opus agents or Opus retries. Haiku (`model: "haiku"`) for
functions under 200 bytes, Sonnet (`model: "sonnet"`) for everything else, merging included; set the model
explicitly on every Agent call. Cap each function at ~10 variants and log the rest as near misses. In batch 1
most of the cost was five Opus retry agents and the Opus merges; agent contexts peaked at 90-230k tokens.

What worked:

- Batch 1 used Opus for a second pass on the near misses, starting from the first pass's file. The
  fixes it found are worth trying first: inline helpers for a repeated
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

Haiku small-function batch
--------------------------

A separate batch (16 Haiku agents, 20 functions each) took the 320 smallest unmatched functions between
0x80050000 and 0x801C0000, one representative per duplicate group. 298 match, in 17 new units
`src/game/unit_<start>.c` (one per agent's address run, merged by `build/agents/merge.py`; the unit
ranges in `splits.txt` run from an agent's first function to the next agent's first, so most of each
range is still unmatched). The unit names and ranges are guesses; the file boundaries are unknown.
Copies of the duplicate groups (`docs/duplicates.txt`) were not added yet; they need their own
`extern` labels, so each has to be re-verified.

Near misses (diff lines): fn_8006BD84 (13, table base in r6 with the zero in r3), fn_8008B470 (19, the
`xor/srawi/cntlzw` compare idiom), fn_8008B4A0 (16) and fn_8008B4D0 (6) (load order of two `s16`s),
fn_80095630 (4, address of lbl_80346C44 loaded between the float stores), fn_8009701C (12),
fn_800976F8 (18), fn_8009E49C/E4B8/E4D4 (paired-single `psq_st`/`psq_l` conversions, no plain C found),
fn_800BE430 (3, a dead second `beq`), fn_800CE4B4 (18), fn_800D1018 (4), fn_8011A960 (12),
fn_80128108 (2, `li` scheduled before the first `lfs`), fn_8012C3DC (4, `extsb` source register),
fn_80193FF8 (4), fn_80194378 (1, missing `extsb`), fn_80194C18 (6), fn_801957D8 (10), fn_801968B8 (3),
fn_801A2C40 (3, the first of two stores to lbl_80347170 is kept in the original).

Stopped at size 0x34 (52 bytes): the 320 smallest representatives in the range top out there, so the
next batch should start at 0x38 bytes in the same range (and cover 0x80050000-0x801C0000 first, then
the regions outside it).

Good next targets
-----------------

- Past the guessed ends: `effect.c` from 0x80047214 (fn_80047214, fn_800472DC, fn_8004754C, ...),
  `evobj.c` from 0x801EE324 (fn_801EE324, fn_801EE344, fn_801EE5A4, ...).
- Before 0x8002C010 (the start of `battle.c` is a guess): 0x8002B000-0x8002C010 is mostly small
  functions, good Haiku/Sonnet work.
- Batch 2 lessons: a callee's real parameter type (`s8` vs `int`) removes `extsb` diffs, and the caller's
  local should have the same narrow type (fn_80033A18's `s8 mode`); single-case `switch` with `default:`
  reproduces `beq; b` layouts; declare stack `Vec` locals in reverse stack order.
- The near misses above, ideally with decomp-permuter (`tools/match/permsetup.py`) running in the
  background while new code is matched.
- The Ninja library (0x80286EE8-0x802AC7E0), 0% so far; see [ninja.md](ninja.md).
