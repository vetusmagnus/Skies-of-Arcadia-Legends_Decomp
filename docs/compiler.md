Compiler identification
=======================

Findings as of 2026-10-05. Every claim below was tested against the original `main.dol`.

Summary
-------

| Question | Answer | Confidence |
|---|---|---|
| Language | C (practically no mangled names, vtables or RTTI) | High |
| Compiler | Metrowerks CodeWarrior (MetroTRK linked in) | Certain |
| Game code version | **GC/1.3.2** (settled 2026-10-07 by a bit test only 1.3.2 compiles that way) | High |
| Required flags | `-O4,p -proc gekko -fp hardware -use_lmw_stmw on -inline noauto` (+ template defaults) | High |
| Dolphin SDK | Sep 5 2002 build `(0x2301)`, prebuilt by Nintendo (behaves like GC/1.2.5n) | Certain |

Layout of `.text`
-----------------

| Range | Contents | Prologue style |
|---|---|---|
| `0x80005600`–`0x80231A7B` (~2.2 MB) | Game code | 0 `mflr`-first / ~2,800 `stwu`-first |
| `0x80231A7C`–`0x802AC7DF` | Dolphin SDK, MSL, MetroTRK, other prebuilt libraries | 233 `mflr`-first / 477 `stwu`-first |

The library boundary was refined to `0x80231A7C` (`PPCMfhid2`) during the SDK import. Per-library compilers are in `docs/sdk_import.md`.

Evidence
--------

| Test | Result | Rules out |
|---|---|---|
| Prologue shape | Game code is `stwu`-first throughout | GC/1.2.5 and older |
| `fn_8000CC84` (bit set/clear on a global) | Matches on 1.3.2–2.7, not on 1.3 | GC/1.3 |
| `fn_8009E4F8`, `fn_801AB98C` (int→float) | Match on 1.3.2–2.7, fail on 2.0p1 | GC/2.0p1 |
| Compiler build dates (`mwcceppc -version`) | 1.3.2 = May 7 2002, **2.0 = Sep 16 2002**, 2.5 = Feb 20 2003 | GC/2.5+ (US build is Dec 19 2002, JP build Nov 12 2002) |
| 1.3.2-only codegen for `(x & BIT) == BIT` (`subf`/`cntlzw`/`srwi 5`) | 3 hits in prebuilt SDK; in game code at least `fn_801C3C40` (`(flags & 0x8000) == 0x8000`, the constant built with `lis`/`addi -0x8000`, which the first scan missed) | **Rules out 2.0**, which compiles it to one `extrwi` |
| `stmw` vs `_savegpr_NN` | 1,024 game functions use `stmw`, none call `_savegpr` | needs `-use_lmw_stmw on` |

The 1.3.2/2.0 differential came from compiling doldecomp's dolsdk2001 source (1,777 functions) with both versions. Only 12 differ: mostly `(x & BIT) == BIT` bit tests (GX getters) plus one `s64` compare schedule (`InsertAlarm`). Across three synthetic corpora (~75 functions covering bitfields, int↔float, loops, switch tables, `long long`, varargs, matrix math and struct copies), 1.3.2, 2.0, 2.5, 2.6 and 2.7 produced identical output. These versions are extremely close.

The game code is built with GC/1.3.2: everything matched so far (`src/game/`) is identical under 1.3.2 and 2.0, and `fn_801C3C40`'s bit test only comes out right under 1.3.2 (the rest of that function isn't matched yet).

No auto-inlining
----------------

Game code was built without auto-inlining. In `src/game/drawstate.c`, `DrawStatePush` calls
`DrawStateApply` and `DrawStateInit` calls `DrawStateDefault`, although both callees are small and
defined earlier in the same file; with the template's `-inline auto` MWCC inlines them and the
functions come out 60 and 7 instructions too long. `-inline noauto` (or `off`) matches all 14
functions; `-inline on` and `smart` still inline them. Functions declared `inline` are still
inlined: `src/game/uiobj.c` has helpers whose bodies appear inside several callers (the UiObj snap
and tween, the menu sound lookup) as well as out of line.

Layout of uninitialized globals
-------------------------------

The order of a file's `.bss` / `.sbss` variables doesn't follow their definition order when they
are defined before the functions that use them: no permutation of the five definitions at the top of
`drawstate.c`, with or without `static` or prior `extern` declarations, reproduced the original
layout. Declaring them `extern` first (in the header) and defining them after the last function, in
reverse order, does. That's the form used there; whether it's what the original source did, or just
an equivalent, isn't known.

Matched probe functions
-----------------------

`probe/probe{1,2,3}.c`: 14 game functions matching byte-for-byte (relocations masked) on GC/1.3.2 and GC/2.0:
- `fn_80005954`, `fn_80007514`, `fn_80008258`, `fn_80009860`, `fn_80009FBC`
- `fn_8000A38C`, `fn_8000CC84`, `fn_8000F0A4`, `fn_80010CBC`, `fn_8009E4F8`
- `fn_8012ADE8`, `fn_8012AE28`, `fn_801AB98C`, `fn_802136A8`

Re-run with:

```sh
python tools/cwprobe.py probe/probe1.c -v 1.3.2 2.0 --verbose
```

Open questions
--------------

- `-inline noauto` vs `off`: both match so far; they differ only for functions declared `inline`, and `uiobj.c` needs those inlined, so `noauto` it is.
- `-O4,p` vs `-O4,s`; `-str` pooling; small-data thresholds; `-common on/off`.
- `mw_comment_version` (currently 10) and the linker version (the template's GC/1.3.2 `mwldeppc`) are now confirmed to work with compiled source: the library objects built from C (see the README Status block) link into a byte-identical DOL. Confirmed with game code too: `src/game/drawstate.c` links.
- The library region past `0x80266878` (~270 KB) is mostly unidentified: AX audio plus probable Sega middleware. Identify it before choosing compilers there. See `docs/sdk_import.md`.


Deferred codegen and reversed source order
------------------------------------------

Found 2026-10-26 on `sound.c` and `tasks.c`: some game files were built with `-inline deferred` (the
build flags are `-inline noauto,deferred`) and `-str reuse,readonly`. A three-function test shows what
deferred does: the functions are emitted in reverse source order, a local array initialiser is
written to `.rodata` first, and the string literals follow in codegen order (so the *last*
function in the source gets the *first* string). The original `.rodata` of sound.c is
`[table][STV%02d.SAMP][B7000000.SAMP]...` with the table used by the sixth function; reproducing
that needs the functions written from the highest address down. Data defined at file scope is
emitted at parse time, before every jump table, so a file that has `[jump table][data][jump
tables]` in the DOL (the old "tasks.c" did) is two files. Without deferred, each function's strings
and template land at its own position, which is what the older units already match with.

How to convert a file: `build/agents`-style scripts aren't needed. Move the typedefs, externs,
prototypes and `inline` helpers to the top, keep data definitions after them, then list the
functions in descending address order; add the two flags in `configure.py`. Check `.rodata` with a
compile (`mwcceppc ... -c`) and compare the object's sections with the original bytes.
