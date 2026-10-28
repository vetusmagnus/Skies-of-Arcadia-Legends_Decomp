# Borrowed library source

Skies of Arcadia Legends links Nintendo's Dolphin SDK (Sep 5 2002 build, `0x2301`), the Metrowerks
runtime and MSL C library, MetroTRK, and Factor 5's MusyX sound system. That code has already been
decompiled and matched by other projects, so it's reused here instead of being decompiled again.

`musyx/` comes from [AxioDL/musyx](https://github.com/AxioDL/musyx) (MIT); see
[musyx/README.md](musyx/README.md) for the commit and what was copied. Everything else in this
directory was taken from **[mitsevox/tw2004](https://github.com/mitsevox/tw2004)**
(CC0-1.0, commit `e90a46609ba8ec4d2e656aa1dc4d6c858d246ca3`). Tiger Woods PGA Tour 2004 links the
same SDK build, and tw2004 vendors the matched source from these upstream projects:

| Directory | Upstream | License |
|---|---|---|
| `sdk/`  | [PrimeDecomp/prime](https://github.com/PrimeDecomp/prime) | CC0-1.0 |
| `ffcc/` | [zcanann/FFCC-Decomp](https://github.com/zcanann/FFCC-Decomp) | CC0-1.0 |
| `trk/`  | [projectPiki/pikmin2](https://github.com/projectPiki/pikmin2) (MetroTRK) | CC0-1.0 |
| `tww/`  | [zeldaret/tww](https://github.com/zeldaret/tww) | CC0-1.0 |

Each directory's own `README.md` / `CREDITS.md` gives the exact upstream commit. tw2004 also carries
source from the Gauntlet: Dark Legacy decomp, which states no license; none of it is used here.

`include/types.h`, `include/asm_types.h` and `include/GameVersions.h` are small glue headers from
tw2004 itself (CC0-1.0) that these trees expect. `include/compat/dolphin/base/PPCArch.h` is ours: it
forwards MusyX's include of the newer SDK header layout to `sdk/`'s `dolphin/PPCArch.h`.

## How files are chosen

`tools/import_libs.py` compiles every matched library file from tw2004 with tw2004's own flags, and
every MusyX file with Metroid Prime's MusyX flags. It keeps a file only if `tools/tusplit.py` can place it in Skies' `main.dol` with:
- identical code (relocations masked), with each call and data reference landing on the
  original's symbol of the same name
- the same function order
- identical data contents
- no data that Skies doesn't have

`config/GEAE8P/lib_import.json` lists the files currently imported. See `docs/sdk_import.md`.

## Local modifications

Keep this list current. Everything else is byte-identical to tw2004 (or, for `musyx/`, to
AxioDL/musyx).

- `tww/include/dolphin/dvd/dvd.h`: `DVDCancelAsync` is declared `static` upstream (TWW never calls it
  from outside `dvd.c`). Skies' game code calls it, so it's non-static here.
- `sdk/dolphin/gx/GXFifo.c`, `sdk/include/dolphin/gx/GXFifo.h`: added `GXGetOverflowCount` after
  `GXGetGPFifo`. Skies' revision of the file has it (`0x8024CC34`), and game code calls it.
- `sdk/runtime/FILE_POS.c`, `ffcc/src/MSL_C/PPCEABI/bare/H/direct_io.c`: removed the
  `__begin/__end_critical_region` calls from `ftell`, `fseek` and `fwrite`. Skies' MSL doesn't lock
  there.
- `ffcc/src/MSL_C/PPCEABI/bare/H/file_io.c`: `#pragma auto_inline off` around `fflush`. Skies'
  `fclose` calls it rather than inlining it.

- Files reworked from the original asm so they match Skies' SDK build (older or newer revisions than the vendored
  copies; unused functions the linker drops are mostly kept): `sdk/dolphin/ai.c`, `ar/ar.c`, `ar/arq.c`, `vi.c`,
  `dvd/dvd.c`, `dvd/dvdfs.c`, `card/CARDMount.c`, `exi/EXIBios.c`, `gx/GXMisc.c`, `GXFrameBuf.c`, `GXLight.c`,
  `GXTexture.c`, `GXBump.c`, `mtx/vec.c` (subtract, magnitude and dot product, in asm like the SDK's), `mtx/mtxvec.c`
  (the array transforms), and under `sdk/runtime/`: `sys_alloc.c`, `s_ceil.c`, `strtoul.c`, `string.c` (strerror from ffcc),
  `printf.c`, `uart_console_io.c`, `mathf.c` (ours: out-of-line `sinf`, `cosf`, `acosf`; `libc/math.h` keeps them inline
  unless `SKIES_FLOAT_MATH_EXTERN` is defined, which the mtx files need). `libc/errno.h` has the full errno list.
  `trk/MetroTRK/mainloop.c`, `nubevent.c`, `msghndlr.c`, `notify.c`, `targimpl.c`, `dolphin_trk.c`, `main_TRK.c` are
  rewritten for Skies' older MetroTRK (v0.10); `dolphin_trk.c` exports `lc_base` because `__TRK_reset` reads it.

Build settings that differ from tw2004's (in `tools/import_libs.py`, not in the sources):
- The SDK is compiled with `-DCARD_PATCH_2003=0`. Skies' memory card library predates that patch.
- `sdk/`'s copies of `CARDBios.c`, `CARDOpen.c`, `CARDStat.c` and `CARDWrite.c` are used where tw2004
  builds those objects from another tree (`ALTERNATES`).
