# MusyX

Factor 5's MusyX sound system (2.0.0), as decompiled by [AxioDL/musyx](https://github.com/AxioDL/musyx)
(MIT, commit `ec4697520f70bf1a5f361413c1b3d4292ecf7b90`, the one Metroid Prime's decomp pins).

Copied: `include/`, `LICENSE` and the Dolphin runtime under `src/musyx/runtime/`. The PC backend
(`hw_pc*`), the debugger, `txwin` and the test harness are left out, and so is `dsp_import.c`: it's
MusyX's DSP microcode as a byte array, i.e. a binary blob that's also in Skies' DOL, and this repo
doesn't carry extracted binaries. It's data-only, so the import couldn't place it anyway.

Skies builds it the way Metroid Prime does: GC/1.3.2, `-O4,p`, `-inline auto,depth=4`,
`MUSY_VERSION` 2.0.0. See `tools/import_libs.py` and `docs/sdk_import.md`.
