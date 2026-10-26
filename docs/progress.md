Progress and handoff
====================

State of the game-code work as of 2026-10-26 (after batch 7). Numbers live in the README status block and on
[ByteMatch](https://bytematch.dev/vetusmagnus/SoAL-Decomp); this page covers what's in flight.

Game files
----------

| File | Range | Status |
|---|---|---|
| `bevent.c` | 0x8002A034-0x8002C010 | 8 of 12; near: fn_8002B124 (epilogue reloads `lwz r0` before `lwz r31`, 2 lines), fn_8002B200 (one float register swap), fn_8002B40C (the original converts its four `s16` arguments with `psq_l`/`qr5` loads, the Dolphin fast cast; plain C gives 126 instructions against 94), fn_8002BD88 (register allocation). The start is a guess |
| `battle.c` | 0x8002C010-0x80031254 | 83 of 101; near: fn_8002C51C, fn_8002C8FC, fn_8002CA54, fn_8002CBF8 (clamp temps in swapped registers), fn_8002D72C (the original keeps a dead loop counter), fn_8002E320 (`mulli -1` vs `neg`), fn_8002E5D0 (register colouring only), fn_8002EEFC, fn_8002F35C, fn_8002F598, fn_8002F630 (base pointer folded into an `addi`), fn_8002F6D4, fn_8002F80C, fn_8002FA00, fn_80030100, fn_80030280, fn_800303EC, fn_800308FC (string offsets only; the strings sit at lbl_802AD0F8+0x78, so `-str reuse,readonly` like tasks.c). The start is a guess |
| `btlchar.c` | 0x80031254-0x80032E78 | 22 of 23; near: fn_80032C6C (prologue registers; an inline `Lookup` for the table search gets it to 14 lines, `build/agents/r6_1/`). The start is a guess |
| `draw2d.c` | 0x80032E78-0x80035918 | 31 of 35; near: fn_800334B8 (r0/r4 swap only in the textured branch, 96 lines in `build/agents/r6_2/`), fn_80033888 (a `frsp` from a double-typed value), fn_8003529C (saved-register order; the only fix found was a long-to-int local copy, rejected), fn_80035518 (12 lines in `build/agents/r6_2/`) |
| `tasks.c` | 0x80035918-0x8003DEE0 | 230 of 235 |
| `sound.c` | 0x8003DEE0-0x80040010 | 26 of 28; fn_8003E1BC and fn_8003ECF4 differ only in string offsets (see below) |
| `effect.c` | 0x80040010-0x800506B0 | 60 of 62 defined; near: fn_80041E64 (operand order of one `add`), fn_800470F0 (register allocation in the quad loop). Not in the file, as near misses: fn_800472DC (a 3-iteration copy loop ends `blt`; `i < 3` unrolls, `i != 3` gives `bne`), fn_80047A68 (counter and value swap r5/r6 in the alpha loop), fn_80048570 (register naming), fn_80048654 (callee-saved colouring), fn_8004C1E4 (`node` r26 vs r27, ribbon effect; 394 lines), fn_8004DD54 (register numbering), fn_8004E474 (two pointers swap r26/r27), fn_8004E7F0 (`addi; extsh` vs `extsh; addi`, 4 lines), fn_8004EEF0 (float load scheduling, 4 lines), fn_8004F664 (one `mr` before `lfd`, 2 lines), fn_8004F868 (`lwz r5` vs r0, 2 lines), fn_8004FF8C (f30 hoist, signed vs unsigned range check). The end is a guess; the file stops after fn_8004FF8C, the next function is 0x800506B0 |
| `drawstate.c` | 0x801CA8D8-0x801CAE84 | linked |
| `uiobj.c` | 0x801C2FA0-0x801C5758 | 40 of 44; near: UiDrawNumber, UiLayoutDrawPart, UiLayoutDraw, UiSpriteDraw |
| `text.c` | 0x801E1F3C-0x801E3874 | 29 of 33; near: FontFindGlyph, TextNodeNew/NewN (0x8197 constant hoisted out of the copy loop), TextReadChar (extra `clrlwi`/`mr`) |
| `motion.c` | 0x801E3874-0x801E48A8 | 9 of 11; near: fn_801E3DE0 (u8 index mask), fn_801E41E0 (one extra saved register); fn_801E461C has no C |
| `flags.c` | 0x801E48A8-0x801E4C2C | 8 of 11; near: fn_801E48A8 (unrolled loop shape), fn_801E4984 (add operand order), fn_801E4AB0 (`mr` of a shift constant). The end is a guess |
| `model.c` | 0x801E4C2C-0x801E7654 | 38 of 39; near: fn_801E735C (one `addi` hoisted above the bounds check). Ends where a second u32-to-float constant starts (0x8034C018) |
| `chunk.c` | 0x801E7654-0x801E8CA4 | 14 of 15; near: fn_801E85BC (two locals swap registers). The end is a guess |
| `evobj.c` | 0x801E8CA4-0x801F224C | 26 of 39 (batch 3 added 21 from 0x801EE324: fn_801EE324/EE344, the equipment-stat and item helpers fn_801EF054-FFFC, fn_801F01E4, fn_801F039C, fn_801F0588, fn_801F11C8, fn_801F1280/1590/1774; near-misses outside the file: fn_801EE5A4 (register allocation, 15 saved registers), fn_801EF000 (MWCC turns every counted loop into `mtctr`/`bdnz`; the original uses `cmpwi`/`blt`), fn_801EF300 (a 4-byte combine into `sig`), fn_801EF7E0, fn_801EF9A8 and fn_801F0020 (an 11- and 17-byte copy loop: the original has no pre-loop guard), fn_801F0284 (one extra `mr r31`), fn_801F1F80 (unrolled 4-byte party check, plus scheduling in case 0)); older: near: fn_801E8CA4 (camera-vector stores fold their offsets), fn_801E9AE0 (20 lines in `build/agents/r6_4/`), fn_801EB01C (6 lines, two `addi` swapped), fn_801EBC5C (8, a state store scheduled after the next compare), fn_801EE140 (3, indexed `stbx` vs a walked pointer), fn_801EDF24 (same), fn_801EC854, fn_801ECA2C, fn_801ED074, fn_801ED69C, fn_801EDAC0 (register colouring around the ObjTurn inline), fn_801EA2DC and fn_801EB330 (large, far off). The end is a guess |

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
137 functions, 126 matched after Opus retries and merging), batch 2 (16 agents on 177 functions, 103
matched; Sonnet only) and batch 3 (16 agents on 86 functions, 62 matched: 1 Haiku agent on the 21
functions under 200 bytes, 20 matched, and 15 Sonnet agents on the rest, plus 3 Sonnet merge agents).
Agent contexts stayed at 105-230k tokens. Merging into an existing file is the costly part: every new
function brings its own `extern` types, and they conflict (one `lbl_` global declared with several struct
types). The merge agents unified them into one declaration per global; `build/agents/merge.py` only
renames clashing typedefs.

**Model rule (from 2026-10-26, for usage):** no Opus agents or Opus retries. Haiku (`model: "haiku"`) for
functions under 200 bytes, Sonnet (`model: "sonnet"`) for everything else, merging included; set the model
explicitly on every Agent call. Cap each function at ~10 variants and log the rest as near misses. In batch 1
most of the cost was five Opus retry agents and the Opus merges; agent contexts peaked at 90-230k tokens.

Duplicates
----------

`python tools/match/dupes.py` masks symbols and branch targets across the asm and writes
[duplicates.txt](duplicates.txt): of 5,830 functions, 5,347 are unique and 170 groups hold 653 functions
(483 copies). Hand an agent one member of a group and copy the source to the others (re-run fdiff on
each copy). Most groups are one- and two-instruction stubs; the largest is 0x12A0 bytes
(fn_800AE4E0 / fn_800DA744). Members defined in `src/` are starred. The earlier estimate of 4,555 unique
groups masked immediates too; these groups keep register numbers and offsets, so they are exact.

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
  verifies with `tools/match/fdiff.py`. All scratch stays in the repo's gitignored `build/`: the
  tools in `tools/match/` already write their per-attempt files to `build/match/` and delete them,
  and an agent's own scripts write candidates into its folder and delete each one after scoring.
  No `tempfile.mkdtemp()` or other writes to `%TEMP%`: 16 agents scoring thousands of variants each
  leave hundreds of thousands of folders there that nothing cleans up. Nothing touches `src/`, git or the build until a person
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
> `vrun.py` for variant searches. Scripts of your own write their candidate files into your folder
> and delete each one after scoring; never `tempfile`/`%TEMP%`. Read `docs/matching.md` first. Stop after ~15-20 variants on one
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

Haiku batch 4 (56-88 byte functions)
------------------------------------

Same setup (16 Haiku agents, 20 functions each, one representative per duplicate group), over the whole
game range 0x80005B50-0x80286EE8 except batch 3's ranges (0x8002B124-0x8004F868, 0x801EE324-0x801F1F80).
It took the 320 smallest unmatched representatives, 0x38 to 0x58 bytes. 254 match (every one re-checked
with fdiff, and `main.dol` still rebuilds byte-identical). Matches inside an existing `unit_*.c` range went
into that unit (14 units grew); the rest went into 12 new units (`unit_80005B50.c`, `unit_80020B50.c`,
`unit_800553B4.c`, `unit_801C09A4.c`, `unit_801C5A60.c`, `unit_801CBA60.c`, `unit_801CED24.c`,
`unit_801D1AE8.c`, `unit_801E1A74.c`, `unit_801F5334.c`, `unit_80219378.c`, `unit_8022D34C.c`; ranges again
guessed). Merging the per-function files needed a Haiku pass per unit for clashing extern types.

Skipped on purpose: the SDK range (0x80231A7C and up, built with another compiler version); i16's
matches there only work with 1.2.5n.

Near misses (diff lines): fn_80012020/80012078 (2, a reloaded 0.0f), fn_80014F50 (11), fn_80018498 (19,
`cntlzw` compare), fn_8005121C (3, a dead `cmpwi r0,0xc` guard before unrolled stores), fn_80095360 (4,
arguments saved to r5/r6 first), fn_800BF7AC (2, doubled `beq`), fn_800CF944 (10), fn_800D2048 (6),
fn_800D23F8/800D244C (1, a second `li r0,1`), fn_800DE554 (12, `orc` with a held constant), fn_800DE598 (2),
fn_800E3554 (2), fn_80108DF8 (3), fn_80117B9C (20), fn_8012A900 (4), fn_8013A320 (18), fn_80143158 (16),
fn_801464B4/80146500 (7), fn_80146DE4 (6), fn_8015128C (9), fn_801545AC (24), fn_80155CD8 (5),
fn_80155D2C (10), fn_80157E04 (6), fn_8015C468/C4A0 (2, missing `extsb`), fn_801673D8 (3), fn_8016AA64 (18),
fn_801940AC (13), fn_801949AC (8), fn_801954EC (6), fn_8019E3A8 (2), fn_801C2C4C/C84 (22),
fn_801D1A40/1A94 (4/2, `stfsu` update-form stores), fn_801D6DE8 (21, `mulhwu` of a u64 product),
fn_801DA484/DA4D0 (13/21), fn_801E0D0C (1), fn_801F3F88 (26), fn_8021A83C (13), fn_80226120 (14),
fn_8022BA10 (11, `addc/subfe`).

Next batch: start at 0x58 bytes (a few 0x58 representatives are still open) and go up, same ranges.
Functions of 0x34 bytes or less outside 0x80050000-0x801C0000 were never attempted (0x80005B50-0x80050000,
0x801C0000 and up).

Haiku batch 5 (88-140 byte functions, plus small ones outside)
--------------------------------------------------------------

16 Haiku agents, 20 functions each, one representative per duplicate group, over the unmatched game
functions from 0x58 bytes up in 0x80050000-0x801C0000 (the 216 smallest, 0x58-0x8C) and the untried
functions of 0x34 bytes or less outside it (104; the SDK range and batch 3's ranges were skipped).
269 of 320 match (every one re-checked with fdiff; `main.dol` still rebuilds byte-identical). Matches went
into the existing `unit_*.c` they fall in (28 units grew; merge fixes were Haiku passes per unit), plus a new
`unit_801F224C.c` (0x801F224C-0x801F5334, guessed; 6 functions). Unit files now hold 821 functions that
all pass fdiff.

Near misses (diff lines): fn_80018764 (20), fn_80077D40 (13, CTR loop vs counter compare), fn_8005535C (2),
fn_80056F30 (2), fn_80061114 (4), fn_80069150 (27), fn_8006ADAC (40), fn_8006E5BC (41), fn_8006F424 (28),
fn_800749DC (4), fn_8008AD04 (6), fn_800A35E0 (2, repeated `li r3,2; blr`), fn_800B0F54 (33), fn_800C32D8 (2),
fn_800C35C4 (8), fn_800C8EC0 (13), fn_800CC9EC (9), fn_800CCA6C (10), fn_800CCC48 (3, `lwzu`), fn_800CD16C (30),
fn_800E07AC (2, dead second `beq`), fn_8010062C (10), fn_80109D74 (3), fn_8013A794 (12), fn_8013DBDC (18),
fn_80141314 (30), fn_80143200 (6, `cntlzw` bool), fn_80149070 (4), fn_801283A4 (14), fn_80128670 (20),
fn_8012C474 (30), fn_80131658 (20), fn_80158B7C (6), fn_8015EB8C (29), fn_80166B2C (31), fn_8016C808 (5),
fn_801838C8 (4), fn_80194B18 (4), fn_80194E6C (26), fn_801956EC (9), fn_801A2C58 (3), fn_801A6650 (12),
fn_801B5868 (28), fn_801B90E4 (10), fn_801BE608 (12), fn_801BEA70 (4), fn_801D13C0 (4).
Not matched: fn_80090518 (38, unrolled memset loop), fn_8010C384 (not attempted).

Next batch: start at 0x8C bytes in 0x80050000-0x801C0000 (216 of the 2,136 candidates were taken, so about
1,900 remain, all larger), then 0x58 bytes and up outside it.
Haiku batch 6 (140-236 byte functions)
--------------------------------------

16 Haiku agents, 20 functions each, one representative per duplicate group: the 320 smallest unmatched
functions of 0x8C bytes and up in 0x80050000-0x801C0000 (0x8C-0xEC; 1,879 candidates, about 1,560 remain).
176 of 320 match (every one re-checked with fdiff; `main.dol` still rebuilds byte-identical). They went
into 13 existing units (Haiku merge passes per unit for clashing extern types); no new unit was needed.
Beyond roughly 0xA0 bytes the hit rate drops to about 55%: the misses are almost all register
allocation and loop shape (MWCC turns counted loops into `mtctr`/`bdnz` where the original compares).

Near misses (diff lines): fn_80074D9C (2, two branch targets), fn_80083ACC (11), fn_8007629C (13), fn_80075C70 (16),
fn_800763D0 (23), fn_8007DEE0 (21), fn_80077DA0 (22, rotated loop without CTR), fn_80083C50 (1, extra `mr`),
fn_80083F34, fn_800899C0 (18), fn_8008F084/F138/F1F8 (9), fn_8008F434 (13), fn_80090598 (6), fn_80095110 (6),
fn_80099830 (10), fn_8009D5BC (18), fn_80097A1C (24), fn_8009B3F4/B4C0 (28), fn_8009D190 (36), fn_8009877C (34),
fn_800C09E4 (3, doubled `beq`), fn_800C63A4 (8), fn_800C8FCC (7), fn_800D6240 (14), fn_800D62DC (19),
fn_800BF0CC (35, the 32-word copy is `bdnz` in the original), fn_800A3680/A3744 (30), fn_800B0900 (29),
fn_80109DCC/EEC (5), fn_8010A164 (4), fn_8010B88C (6), fn_8011768C (19), fn_8010DDBC (23),
fn_80118948 (8), fn_801189F0 (16), fn_80126E24 (18), fn_80128E7C (17), fn_801281E8/82C4/8DA4 (21),
fn_80129058 (10), fn_801295EC (9), fn_8012C670 (6), fn_80129814 (22),
fn_8013ECF4 (11), fn_801353A8 (8), fn_8013A818 (24), fn_80148024 (14), fn_801486CC (11),
fn_80148BE8 (19), fn_801525F8 (17), fn_801557A8 (15), fn_80156CC4 (4), fn_80158590 (4), fn_801589BC (6),
fn_8015FAD4 (3), fn_80167578/67604 (4, `addi+lwzx` vs `add+lwz`), fn_801752F4 (4), fn_8017A6A4 (9), fn_8018E73C (14),
fn_80194150 (8), fn_801942A4 (17), fn_801A372C (7), fn_801AAFAC (4), fn_801B5644 (2, LR reload order).
The `neg/or/srwi` boolean idiom (`!x` on a word) blocked fn_800FF4EC, fn_800FF6B4, fn_80194CC8, fn_80161F04,
fn_801942A4: plain C always gives `cntlzw` or `and.`.
Not matched at all (far): fn_80051EC8, fn_80051FA0, fn_80075F2C, fn_80076478, fn_80078A20, fn_800783A8,
fn_8007C9CC, fn_8007E44C, fn_8007FD20, fn_800801A8, fn_8008066C, fn_80082340, fn_80090A7C, fn_801559BC, fn_801A4684.

Lessons: an `extern T x[];` with no size makes MWCC use `lis/addi`; give the real size (`[2]` for an 8-byte
sbss object) to get `sda21`. A callee's `s8` argument fixes `extsb`. `switch` reproduces `bne; b` layouts.

Next batch: start at 0xF0 bytes in 0x80050000-0x801C0000 (about 1,560 candidates left), then 0x58 bytes and up
outside it (0x80005B50-0x80050000 and 0x801C0000 and up; skip the SDK range). Selection recipe: group by
`tools/match/dupes.py`, drop groups with a member already in `src/`, take the lowest address of each group,
sort by size, skip the names listed in this file as near misses.

Sonnet batch 7 (240-332 byte functions)
---------------------------------------

16 Sonnet agents, 20 functions each, one representative per duplicate group: the 320 smallest unmatched
functions of 0xF0 bytes and up in 0x80050000-0x801C0000 (0xF0-0x14C; 1,551 candidates, 1,231 remain).
226 of 320 match (71%); every one was re-checked with fdiff over the whole unit files (1,221 functions, all
clean). They went into 13 existing units, plus a new `unit_800540DC.c` (0x800540DC-0x800553B4, guessed;
fn_800540DC sits in the gap after `effect.c`). Merging was one Sonnet agent per unit. `main.dol` still
rebuilds byte-identical (the unit objects are `NonMatching`, so that check says little).

fdiff does not compare float constants (the compiler's `@N` literals are "unplaced"), and the agents'
matches were wrong in five places: fn_8009D88C compared against 1.0f where the original loads 0.0f,
fn_80100178/fn_80101494 stored 0.0f where the original stores FLT_MAX (`3.4028235e38f`), and two literals were
one float step off (fn_800CF7BC's `9.999999e-09f`, fn_800E340C's `-1.0799999f`). All fixed. Check constants
after merging: compile each unit, disassemble it, and compare the bytes of every `lfs`/`lfd` pool entry
against the original's `.sdata2` (`build/agents/floatcheck.py`, gitignored). This is worth adding to `tools/match`.

Dropped to keep an older match: fn_801B71E8 and fn_801B7274 need text.h's `TextPrint(s16, s16, ...)`, but the
existing fn_801B0B2C only matches with an `s32` prototype (no `extsh`), and the two cannot share a unit.
fn_801B0B2C stays; the other two are near misses.

Near misses (diff lines): fn_80077B88 (43), fn_8008100C (8), fn_80081648 (20), fn_80081DE0 (78), fn_80082840 (46),
fn_8008328C (73), fn_800839D8 (43), fn_80088E4C (61), fn_80088F64 (25), fn_80089074 (27), fn_80089184/892AC (67),
fn_800893D4/894FC/89624/8974C/89874 (56, one "pick a random living unit not flagged" shape; the original reuses
dead registers), fn_80089AA0/89BA4/89CA8 (67), fn_8008A174 (6), fn_8008BFDC (6), fn_8008C98C (8), fn_8008FFA4 (58),
fn_80090DBC (61, `psq_l` s16-to-float casts), fn_80094E50 (24), fn_80095220 (11), fn_80097388 (4),
fn_80098C58 (26), fn_80099078 (54), fn_8009DDA8 (25), fn_800A12D8 (29), fn_800A1998 (10), fn_800A37E8 (30,
`subfic/cntlzw` compare), fn_800AB834 (4), fn_800BBC3C (42), fn_800C23CC (18), fn_800C9144 (20), fn_800CF6A8 (32),
fn_800CF988 (52), fn_800D3464 (130, a big init the compiler folds onto one base register), fn_800EEDD4 (10),
fn_800F113C (23), fn_801004C4 (40), fn_80109F90 (34), fn_8010B940 (28), fn_8010E074 (4, `lis; subi` for
0x7FFFFFFF), fn_8010F3A8 (4), fn_80114950 (8), fn_80116898 (14), fn_8011AEE4 (47), fn_8011B024 (34),
fn_801222A8 (36), fn_80125B60 (12), fn_80129AA4 (23), fn_8012A26C (3), fn_8012CFC8 (14), fn_80130B64 (92),
fn_80135290 (3), fn_80135474 (17), fn_8013D938 (14), fn_8013FCF0 (25), fn_80140800 (42), fn_80143060 (4),
fn_80144680 (7), fn_80145E0C (44), fn_80147054 (24), fn_80148228 (12), fn_8014836C (37), fn_80148CAC (10),
fn_8014F834 (36), fn_80152284 (50), fn_8015519C (28), fn_8015983C (15), fn_8015D124 (28), fn_80167690 (89),
fn_80168908 (14), fn_8016CED8 (1, extra `b` after a one-case `switch`), fn_8016E6E8 (56), fn_80173688 (8),
fn_80174E18 (22), fn_8017567C (10), fn_80175DC4 (44), fn_801763B8 (16), fn_8017F540 (9), fn_80184E2C (3),
fn_80186BE4 (71), fn_801918C4 (20), fn_80195540 (4), fn_801A3A10 (35), fn_801B65CC (18).
Not matched, no usable file: fn_800823E4, fn_80165DE8.

Lessons: a local `f32 zero = 0.0f;` (or `one`) used in the compare flips `fcmpu` operand order; `p / 128.0f`
gives the `fmuls` by the reciprocal; `static inline` search helpers (`FindEntry`) reproduce search loops that
return NULL; `s32 ready = x >= 500; if (ready != 0)` gives the `srwi/subfc/adde.` form; declaring a
float-taking prototype with the colour argument last fixed a caller's scheduling (fn_8010C87C).

Next batch: start at 0x14C bytes in 0x80050000-0x801C0000 (about 1,230 candidates left), then 0x58 bytes and up
outside it. `docs/duplicates.txt` was not regenerated: `dupes.py` reads the dtk asm, which no longer lists the
functions that sit in unit files, so run it from a checkout where those are still in the auto asm.

Good next targets
-----------------

- Past the guessed ends: `effect.c` from 0x800506B0, `evobj.c` from 0x801F224C. Before 0x8002A034 (the start
  of `bevent.c` is a guess).
- Check `duplicates.txt` before handing out a range.
- Batch 2 lessons: a callee's real parameter type (`s8` vs `int`) removes `extsb` diffs, and the caller's
  local should have the same narrow type (fn_80033A18's `s8 mode`); single-case `switch` with `default:`
  reproduces `beq; b` layouts; declare stack `Vec` locals in reverse stack order.
- Batch 3 lessons: `do { ... i++; p++; } while (i < n)` stops MWCC unrolling a `for`; `case 0: default:` first and an empty `case 2:` reproduce odd compare trees; a callee's real `u8`/`s8`/`s16` parameter fixes `extsb`/`extsh` diffs (fn_8022E734 takes `u8 kind`); a u8 field read into an `int` local gives `cmpwi` where a `u8` local gives `cmplwi`.
- The near misses above, ideally with decomp-permuter (`tools/match/permsetup.py`) running in the
  background while new code is matched.
- The Ninja library (0x80286EE8-0x802AC7E0), 0% so far; see [ninja.md](ninja.md).
