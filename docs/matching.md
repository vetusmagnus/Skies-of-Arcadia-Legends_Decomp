Matching game code
==================

How the game code under `src/game/` was matched, and what MWCC (GC/1.3.2, see
[compiler.md](compiler.md)) turned out to care about. Written 2026-10-07 after the first three files
(`drawstate.c`, `uiobj.c`, `text.c`).

Workflow
--------

1. **Find the file.** File names are ours; boundaries come from the data. A file's `.sdata2` starts
   8-aligned and its float constants are pooled per file (a function using another block's `12.0f`
   is in the same file; a second `0.0f` means a new file). In `.data`, a file's strings come before
   its jump tables. `tools/match/asmindex.py` lists callers, callees, data references and strings.
2. **Write C per function** and diff it: `tools/match/fdiff.py src/game/foo.c FN...` compiles with
   the game's flags and diffs against the original asm (an empty diff is a match). Instructions are
   aligned with symbols and call targets masked, then every aligned pair is checked again: a global
   both sides can name must be the same address, and a branch must land on the aligned target, so a
   load from the wrong global shows up as a `-reloc`/`+reloc` pair. Symbols only one side can name
   (the compiler's `@N` literals, statics not in `symbols.txt` yet) are counted as `unplaced`;
   the full build is the final check for those. Run `tools/match/asmindex.py build` first, and
   again after `ninja` regenerates the asm (renames, new splits).
3. **Search variants** when only registers or scheduling differ:
   - `tools/match/vrun.py` tries text substitutions;
   - `tools/match/perm.py` tries every order of a block of declarations;
   - `tools/match/fvar.py` swaps in whole-function variants (`DIFF=` to check the callers of an
     inline you changed).
   - `tools/match/permsetup.py SRC FN` sets up a [decomp-permuter](https://github.com/simonlindholm/decomp-permuter)
     directory (`build/permuter/FN`); run `permuter.py build/permuter/FN -j8 --stop-on-zero`. Treat
     what it finds as a hint: keep only changes that are reasonable C and don't change behaviour.
4. **Place it.** Compile the object, `tools/tusplit.py <obj> --name game/foo.c` for the `splits.txt`
   entry, `tools/fixsplits.py`, then `Object(Matching, ...)` in `configure.py` and `ninja` must end
   with `main.dol: OK`. A file only links when every function in it matches (its constants and
   jump tables are shared); until then it's `NonMatching` with just its `.text` (and whatever data
   you're sure of) in `splits.txt`, and objdiff tracks it.
5. **Name** what's understood in `symbols.txt` (`scope:global`).

Game code is plain C: no inline asm, pragmas or fakematches. `tools/check_game_src.py` enforces
it as the first build step.

What MWCC cares about
---------------------

- **No auto-inlining** (`-inline noauto`): a small function defined earlier in the file is still
  called. A block repeated inside several functions is an `inline` function; its parameters get
  their own registers, which can be what makes the allocation match.
- **Declaration order drives register allocation and stack layout.** Most register-only diffs were
  fixed by reordering locals (`perm.py`), or by holding a value in a named local instead of re-reading
  the expression (or the reverse).
- **Types at the call:** a `u8` field passed to an `s8` parameter gives `lbz r0` / `extsb rN, r0`
  (`menu_se_table.id` into `SePlay`). A `u8` local adds `clrlwi` masks; re-reading `*p` keeps the
  loaded byte's known range instead.
- **Casting a `void*`** where the original had a typed field changes CSE (`MenuPartFree`).
- **Switch tables** that start at 0 need an explicit `case 0:`.
- **Uninitialized globals:** declared `extern` in the header and defined after the last function,
  in reverse order, they come out in the original `.bss` order (see compiler.md).
- **Parameter order between ints and floats** doesn't change the PowerPC calling convention (they
  use separate registers), so it's free; it does change scheduling (`UiSpriteDrawEx` only matches
  with its floats before `texlist` and `flags`). Callers show it too: an argument the original
  loads last is often a later parameter than guessed. `UiLayoutDrawPart` takes its `u16 index`
  after the three floats, and `UiDrawNumberText` its value after the position; each fix matched or
  nearly matched several shop functions at once.
- **volatile** was needed for a byte-by-byte colour copy that the original does load/store
  alternating (`text.c`).
- **The game's types:** Ninja's matrix is the Dreamcast `Float[16]` (`include/ninja.h`); small
  structs in `.sbss` must stay separate globals if the original accesses them with `sda21`.

Large functions
---------------

Found matching `fn_801A6BDC` (the 16.6 KB shop state machine in `unit_80199B9C.c`):

- **MWCC's inline budget is per caller and size-based.** An `inline` helper stops expanding once
  the calling function gets big (around 2,500 instructions here, counting the caller's own code),
  biggest helpers first, then all of them. No flag changes it (`deferred`, `level=`, `-O4,s` all
  cut off in the same place). So a function this size can't rely on `inline` helpers: repeated
  blocks are macros.
- **Shared tails are `goto`s.** MWCC does not merge identical code. Where the original jumps into
  another case's code (a state that sets a value and then branches into the middle of another
  state), the source has a label there.
- **A value the original keeps in a register across stores is a local**, often assigned inside a
  condition: `if ((n = t->w->xa) != 4) { a->h = n; b->h = n; }`, or a loop bound reused after
  the loop: `for (cnt = 0; cnt < (i = t->w->xb); cnt++)`.
- **`addi 8; add; lha 2` (an array element's address kept, then the field read)** comes from
  copying the address through a second pointer: `ShopEntry* cur_ = &buf->out[i]; e = cur_;`. A
  single assignment folds into `lhax` with offset `0xa`.
- **`?:` between two constants becomes branchless code**; `cmd = 20; if (x) cmd = 21;` gives the
  `li`/`bne`/`li` the original has.
- **Register-only differences in a big function were variable identity, not declaration order**:
  a declaration-order search changed nothing, while swapping which variable plays the loop index
  and which the counter fixed it. Block-scoped temporaries (in the macros) get their own
  registers and were what the original's temporaries needed.

From `fn_801AD1D4` (10.4 KB, the shop's stat-comparison windows, same file; a near miss kept in
[near/fn_801AD1D4.c](near/fn_801AD1D4.c)):

- **A function can reach its file's data through the section base.** It loads
  `lis r31, lbl_802B6A18@ha; addi r31, r31, lbl_802B6A18@l` once and reads every table at a fixed
  offset from it (`addi r4, r31, 0x2434`). That's MWCC pooling a section it references many
  times, and it does this for globals as well as statics. The base is the start of the original
  file's `.rodata`, so the code only comes out this way if the file's data is defined in C, before
  any other `.rodata` the file emits, with every object at its original offset.
  `tools/match/gen_rodata.py` writes such a range as C (objects sized to the next boundary,
  padding included, pointer tables kept as relocations); `tools/match/rodata_80199B9C.py` has the
  extra boundaries and typed objects for `unit_80199B9C.c`. With that block in the unit, all of its
  matching functions still match. Six functions in the file use the base (fn_801AD1D4,
  fn_801B02F4, fn_801B0B9C, fn_801B11EC, fn_801B1B3C, fn_801B28D4).
- **fdiff masks section symbols** (`...rodata.0@ha`) now, the same as named ones.
- **Unrolled 7-stat blocks are macros**: the original repeats the block for each stat, and
  MWCC doesn't unroll any loop form of it (`s32`, `s16`, `int` counters, with or without temps).
- **Where the registers stand**: the instruction stream is exact (2612/2612 with registers
  masked); 433 lines are register numbers. What moved it: block-local variables per display
  block (1268 → 1060 changed lines), a declaration order per block instance (→ 930), the colour
  row's `cy` at function scope (→ 870), the diff block using a function-scope `iy` (→ 866).
  Reshaping the number macro (temps, an inline helper, value first) changed nothing. What's left
  is systematic: in the ship windows the original keeps the drawn value in r21 in every copy and
  swaps the roles of r27/r29 (`ix`/`iy`), and each window's header holds the party pointer in r7
  where we use r6. One register for every copy of a value looks like a single variable whose live
  range spans the whole function, but hoisting `v` alone makes it worse (996).

From `fn_801B28D4` (6.7 KB, the shop's equip/compare window, same file; a near miss kept in
[near/fn_801B28D4.c](near/fn_801B28D4.c), which includes the unit, so plain fdiff works on it):

- **Case bodies come out in source order**, so the order of the case code in the asm is the order
  of the `case`s in the source: here 0, 2, 1, 3. Writing them 0-3 cost 20 lines.
- **Stack slots tell the order of conversions.** Each float-to-int temporary gets its own slot,
  later ones at lower offsets. The slots showed `iy` (with its row offset) converted before `ix`;
  swapping them took the diff from 120 to 51 lines.
- **Two equally typed stack buffers** take their offsets from declaration order (`CmpEq eq;
  CmpEq eq2;` puts `eq2` at the lower address).
- **Float temporaries can be shared across blocks with swapped roles.** The colour rows put the
  row in f31 and the column in f29, the opposite of the window's own `x`/`y`. Reusing `x`/`y` the
  other way round there, plus block-local temporaries in the macros, took the register diff from
  207 to 119. The comment at the macro says so.
- **The permuter scores differently from fdiff**: its best candidate here (3570 → 2680 by its
  measure) was worse by ours (74 lines instead of 31), using a `volatile` and dead code. Read its
  output as a hint only.
- **Still open**: the arguments of the `UiLayoutDrawPart` call are scheduled differently (the
  original loads the index last; no parameter type or spelling moved it), the loop counters start
  differently (the original copies `i`'s zero and reloads `i` from its stack slot), and the
  page-2 `fn_801B6BB4` calls compute the item id before the object and position. (The
  `UiLayoutDrawPart` one is solved: its index is the last parameter.)

From `fn_801BA9CC` (6.8 KB, the discoveries window, same file; near miss in
[near/fn_801BA9CC.c](near/fn_801BA9CC.c)):

- **An `extsh` that the original has and we don't is an `s16` parameter boundary.** MWCC knows a
  value loaded with `lha` is extended and drops conversions of it, including through `s32`
  variables; it extends again where the value enters an `s16` parameter of an inline from a
  wider one. So a helper doing `if (id == -1)` on a raw value and then `extsh` before the rest
  is an `s32` helper calling an `s16` one.
- **A load that comes too early (scheduled into an earlier test) is read earlier in the source.**
  The guild level is loaded once inside the first flag test: the text getter reads it at its top
  and passes it on, instead of each rank check reading it.
- **A boolean kept as 0/1 before a branch** (`neg; or; srwi.`) is `f = (...) != 0; f = f != 0;`.
- **`inline` (not `static`) functions are emitted out of line at the end of the file**, so a
  small function sitting near the end of a unit with its body inlined into earlier callers is
  one; callers before its definition call it, later ones inline it.
- **Variable identity beats declaration order** again: after the structure was exact, the
  remaining register swap (task and a part pointer, r29/r31) didn't move with declaration order,
  scope, hoisting, helper shape or the permuter.

Open
----

The near-misses in `uiobj.c` and `text.c` are listed in [ui.md](ui.md#open). They resisted the
variant searches above; a real permuter (decomp-permuter with MWCC under wibo) is the next tool to
try.
