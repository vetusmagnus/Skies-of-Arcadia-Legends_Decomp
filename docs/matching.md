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
  with its floats before `texlist` and `flags`).
- **volatile** was needed for a byte-by-byte colour copy that the original does load/store
  alternating (`text.c`).
- **The game's types:** Ninja's matrix is the Dreamcast `Float[16]` (`include/ninja.h`); small
  structs in `.sbss` must stay separate globals if the original accesses them with `sda21`.

Open
----

The near-misses in `uiobj.c` and `text.c` are listed in [ui.md](ui.md#open). They resisted the
variant searches above; a real permuter (decomp-permuter with MWCC under wibo) is the next tool to
try.
