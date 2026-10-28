Library code (SDK / MSL / TRK / MusyX)
======================================

Layout of the library region
----------------------------

Game code runs from `0x80005600` to about `0x80231A7C`. Everything after that, up to the end of
`.text` at `0x802AC7E0` (~490 KB), is library code:

| Range (approx.) | Contents |
|---|---|
| `0x80231A7C`–`0x80266878` | Dolphin SDK (PPCArch, OS, DB, MTX, DVD, VI, PAD, AI, AR/ARQ, DSP, CARD, GX), MetroTRK, Metrowerks runtime, MSL C, MSL math, ODEMU, EXI, SI |
| `0x80266878`–`0x80286EE8` (~132 KB) | **MusyX 2.0.0** (Factor 5's sound system), in source-file order from `seq.c` to `Chorus/chorus_fx.c`. No Nintendo AX: what looked like AXFX `reverb_hi` is MusyX's `StdReverb`, which shares its code |
| `0x80286EE8`–`0x802AC7E0` (~150 KB) | **Sega's Ninja library** (GameCube, on GX). No reference source exists, so it's named by behavior; see [ninja.md](ninja.md) |

Imported source
---------------

SDK / MSL / TRK files built from C come from [tw2004](https://github.com/mitsevox/tw2004), which uses
the same SDK build. MusyX comes from [AxioDL/musyx](https://github.com/AxioDL/musyx), vendored in
`extern/musyx` at the commit Metroid Prime's decomp pins. See `extern/README.md` for provenance and
licenses, `config/GEAE8P/lib_import.json` for the list, and the status block in the README for
current numbers.

To re-run the import (it's idempotent, and a second pass can pick up a few more files once the
first pass has named their neighbors):

```sh
git clone https://github.com/mitsevox/tw2004 ../tw2004
git -C ../tw2004 checkout e90a46609ba8ec4d2e656aa1dc4d6c858d246ca3
python tools/import_libs.py ../tw2004
python configure.py && ninja
```

Tools
-----

| Tool | What it does |
|---|---|
| `tools/tusplit.py <obj>` | Places a compiled object in `main.dol`. Code (`.text` and `.init`) is matched by bytes (relocations masked) and by where its calls land, with tiny ambiguous functions and same-byte look-alikes resolved by position; a function is never matched to an address the original names differently. Global data whose name the original already has is anchored by name, so data-only files place too. Data symbols are anchored through code relocations and checked byte-for-byte; unanchored trailing .bss is accepted when it exactly fills the space before the next known object, and merged `$localstatic` data or data used only by stripped functions (in `.bss`, `.sbss`, `.sdata2`) may be missing and is never placed. Prints a `splits.txt` block and, with `--symbols`, the names of everything it placed or referenced. Fails on different code, different function order, references to a different symbol than the original's, mismatched data, or data Skies doesn't have. |
| `tools/fixsplits.py` | Reconciles split boundaries with dtk's guessed data symbols. Extends a split over trailing zero padding, otherwise trims the guessed symbol. Also closes a gap of under 8 zero bytes before the next split when no symbol starts in it. |
| `tools/import_libs.py <tw2004>` | Runs the whole pipeline: copy sources, compile candidates (tw2004's, the `ALTERNATES` from other vendored trees, and every file of the `LOCAL_LIBS` such as MusyX, with Skies' flag changes in `FLAG_SUBST`), place, select, write `splits.txt`, the `configure.py` block, `symbols.txt` names and the manifest. |
| `tools/cwprobe.py` | Compiler-version probing for game code. See `docs/compiler.md`. |

Why files get rejected
----------------------

About a third of the library region's code matches *some* function in tw2004's sources, but only
files that match as a whole can be linked. What's left are **source revision differences** between
the Sep 2002 SDK in Skies and the (mostly newer) revisions upstream:

- **Partial matches.** Some functions in the file differ, or the file is mostly stripped and the
  rest differs, so its data can't be anchored (e.g. `OSFont.c`, `dvd.c`, `vi.c`, `printf.c`,
  `alloc.c`, most of MetroTRK).
- **Different layout.** Functions or data in a different order (`CARDMount.c`, `ctype.c`).

`tools/import_libs.py`'s `EXCLUDE` list is currently empty. Every MusyX file Skies links is built
from C. `CheapReverb`, `Delay`, `hw_lib_dolphin.c` and `profile.c` aren't in the game. `dsp_import.c`
(MusyX's DSP microcode as a byte array) isn't vendored; see `extern/musyx/README.md`, which means
the microcode at its place in `.data` stays as extracted data.

The easy near misses (a missing accessor, a dropped lock, a build flag) are done; see below. What's
left needs some functions decompiled against Skies' revision. That's still much cheaper than
starting from assembly, since most of each file already matches. When you edit a file under
`extern/`, record it in `extern/README.md`. You can also move it into `src/` with its own entry in
`configure.py`.

To see why a file fails, compile it with tw2004's flags and run `tools/tusplit.py <obj> --verbose`.
It lists functions that weren't found, unmatched functions inside the range, misplaced data and
mismatched references. Diff a function against the original with `build/tools/dtk elf disasm` on
the object and the matching file in `build/GEAE8P/asm/`.

### Lessons from the first round of near misses

Several files that looked like revision differences weren't:

- **"Extra" .bss that is really there.** `FifoObj` (GXInit), `__savedGXdata` (GXDisplayList) and the
  tail variables of `dvdlow.c`, `SIBios.c` and `Pad.c` are used through a section base pointer
  (`addi r3, r31, 0x4f8`), so no relocation anchors them. Each fills the unclaimed space before the
  next object exactly. `tusplit.py` now accepts trailing .bss that fits like that.
- **Data stripped with its only user.** `OS.c`'s `ZeroF` / `ZeroPS` are used only by `__OSFPRInit`,
  which isn't linked into Skies, so the linker drops them too. The asm function must stay in the
  source: its presence turns MWCC's peephole pass off for the functions after it
  (`OSGetConsoleType` has `bne` + `b` instead of `bnelr`).
- **Misnamed signatures.** `CARDRead` and `CARDWrite` compile to the same bytes once relocations are
  masked, and dtk had named Skies' `CARDRead` as `CARDWrite`, which made `CARDWrite.c` look out of
  order. Likewise dtk's `__CARDIsWritable` was `__CARDAccess`. `tusplit.py` no longer matches a
  function to an address the original names differently, and it checks that each external
  reference lands on the original's symbol of the same name.
- **Locking and inlining in MSL.** Skies' `fwrite`, `fseek` and `ftell` don't take critical
  regions, and its `fclose` calls `fflush` instead of inlining it. MSL is built with
  `-inline deferred`, which emits functions in reverse source order, so `fseek` before `_fseek`
  isn't a reorder.
- **Inline-function statics.** A section that holds nothing but `$localstatic` data (e.g.
  `sqrtf`'s constants in `e_fmod.c`) has nothing of its own to place; the linker merges it.
- **.init code.** `__ppc_eabi_init.cpp`'s `__init_hardware` and `__flush_cache` are placed in `.init`.
- **Data that goes with stripped code depends on the section.** Data used only by functions the
  linker stripped is gone in `.bss`, `.sbss` and `.sdata2` (`OS.c`'s `ZeroF`, `snd3d.c`'s
  `em$1187`, `snd_math.c`'s `@121`) but stays in `.data` (`dsp_task.c`'s `@294` string). That's
  empirical; tusplit follows it and the DOL hash has the final word.
- **Base-pointer access hides users.** MusyX's `synthvoice.c` reaches four arrays as `vidList` + an
  offset through a register, so by relocations only a stripped function uses them. Data bracketed by
  placed symbols whose spacing matches the object's is placed regardless.
- **Inline-function statics are never placed by position.** `sqrtf`'s `_half` / `_three` exist once
  in the link, wherever the first file put them; placing `hardware.c`'s copies by offset landed on
  `snd_math.c`'s `0.5`.
- **Look-alike functions.** Two functions with the same bytes once relocations are masked
  (`sndSeqSetMidiCtrl` / `sndSeqSetMidiCtrl14`; a MusyX helper calling `salFree` and a game function
  calling the game's own `free`) are told apart by position and by where their calls land.
- **Zero constants aren't padding.** A `0.0f` that tusplit matched by bytes turned out to belong to
  the next file. Data placed only because its bytes match is weak evidence when the bytes are zero.
- **Pre-2003 CARD library.** Skies' `CARDReadAsync` calls `__CARDAccess`, then `__CARDIsWritable`
  on `CARD_RESULT_NOPERM`: the `CARD_PATCH_2003=0` branch of the sources.

Compilers seen in the library region
------------------------------------

These are taken from tw2004's and Metroid Prime's per-library settings, which match:

| Library | Compiler |
|---|---|
| Dolphin SDK | GC/1.2.5n |
| MetroTRK | GC/1.3.2 |
| MSL / runtime / math | GC/1.3 (some MSL files GC/1.3.2) |
| MusyX 2.0.0 | GC/1.3.2, `-O4,p -inline auto,depth=4` (`-O4,s` matches far less) |

MusyX code calls `_savegpr_NN` / `_restgpr_NN` where the rest of the game uses `stmw` / `lmw`. That's
how GC/1.3.2 compiles it without `-use_lmw_stmw on`, not a sign of size optimization.

Second pass (SDK 47% to 93% linked)
-----------------------------------

What the first import couldn't place was mostly Skies' own SDK revision (Sep 2002), not missing source. Per-file recipe:
compile the vendored file with its library flags, diff each function against the original asm (the object's functions
map to original ones by name, else by order and similarity), rewrite the differing functions from the asm, drop what
the original linker stripped, then place the file with `tools/tusplit.py` (or by hand where it can't anchor data) and
check the DOL SHA-1. Things that bit:

- **Stripped code hides its data.** Statics used only by dropped functions are gone from `.bss`/`.sdata2` but stay in
  `.data`/`.rodata` (version strings, `strerror`'s messages). A split's data range has to cover everything the object
  emits, or the linker pads and the whole section shifts.
- **`tusplit` doesn't verify pooled floats.** C_QUATSlerp compiles to the right code but its `.sdata2` pool comes out in
  another order (1.0f before 0.0f), which only the DOL hash shows; it stays unlinked (`extern/sdk/dolphin/mtx/quat.c`).
- **Local symbols referenced from asm units must be global** (`lc_base`), or dtk's mangled name is undefined at link.
- **Renamed symbols**: linking a file names the functions its calls resolve to, so game C that declared
  `fn_8025CB24` etc. now calls `sprintf`, `rand`, `strcat`, `strcpy`, `OSPanic`, `VIConfigure`, `GXSetDrawSync` ...
- **Weak functions** (`OSReport`) sit at the end of `.text`; OSError.c is linked without them.
- Skies' libm has real `sinf`/`cosf`/`acosf`; its MetroTRK is the old v0.10 protocol build.

Still unlinked, with the reason: `CARDStatEx.c` (CARDSetAttributes: 2 instructions), `DebuggerDriver.c` (7 of 13), the
TRK files with near misses (msgbuf: the original calls `TRKAppendBuffer` where the compiler inlines it; nubinit, msg,
dispatch, serpoll, support: 1-10 lines each, in `build/agents` style notes were kept locally), `dolphin_trk_glue.c`,
`mem_TRK.c` (`TRK_fill_mem`), mutex_TRK (three identical 8-byte functions), `quat.c`, the 0x80262A7C-0x80262ABC AMC/EXI2
stubs and a few 12-48 byte fragments (OSModule, a DVD callback at 0x8023D7E8, PAD code at 0x8023F91C-0x8023FBD0).
