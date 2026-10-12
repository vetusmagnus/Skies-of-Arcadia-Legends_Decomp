Sega Ninja library (GameCube)
=============================

`0x80286EE8`–`0x802AC7E0` (~150 KB, 452 functions), the last part of `.text`, is Sega's **Ninja**
graphics library in its GameCube form, built on GX. There's no decomp or symbol map of GC Ninja to
match against, so functions are named here by behavior, using Ninja's public API (Dreamcast
documentation, Sonic Adventure PC symbols). Nothing in this region builds from C yet.

Evidence that it's Ninja
------------------------

- **16-bit angles.** Ninja's `Angle` type makes `0x10000` one turn. The library's constants
  (`0x8034CF80`–`0x8034D204`) contain 2π/65536 a dozen times, and game code converts radians with
  65536/2π all over the place. `njSin` / `njCos` / `njTan` are exactly `sin((float)ang * 2π/65536)`.
- **Ninja's matrix model.** A matrix stack with a current-matrix pointer, where passing `NULL` means
  "the current matrix", and push/pop/translate/rotate/scale functions shaped like Ninja's
  (`njRotateXYZ` and `njRotateZXY` both exist, with those rotation orders).
- **Model data.** The disc's models are Ninja chunk models (`NJCM` / GJ chunks inside `.mld`).

Named functions
---------------

All in `config/GEAE8P/symbols.txt`. "Likely" means the behavior fits but the Ninja name is inferred.

| Address | Name | Evidence |
|---|---|---|
| `0x80291930` / `0x802916B8` / `0x80291B3C` | `njSin` / `njCos` / `njTan` | Angle × 2π/65536, then `sin` / `cos` / `tan` |
| `0x80291B84` / `0x80291BB4` | `njCalcPoint` / `njCalcPoints` | `PSMTXMultVec` / `…Array` on `m` or the current matrix |
| `0x80291BE4` / `0x80291C14` | `njCalcVector` / `njCalcVectors` | `PSMTXMultVecSR` / `…ArraySR` |
| `0x80291C64` | `njGetTranslation` | copies the matrix's translation column |
| `0x80291C90` | `njInitMatrix` | sets up the stack (32-byte aligned buffer, depth limit), loads identity |
| `0x80291CD8` / `0x80292438` / `0x80292458` | `njInnerProduct` / `njScalor` / `njScalor2` | `PSVECDotProduct` / `PSVECMag` / `PSVECSquareMag` |
| `0x80291D18` / `0x80291DAC` | `njInvertMatrix` / `njMultiMatrix` | `PSMTXInverse` / `PSMTXConcat` |
| `0x80291DE4` | `njOuterProduct` | `PSVECCrossProduct`, returns the length |
| `0x80291E54` | `njProjectScreen` | point → screen using the screen parameters |
| `0x80291F10` / `0x8029295C` / `0x80292924` | `njPushMatrix` / `njPushMatrixEx` / `njPopMatrixEx` | stack depth ±1, copy into the next slot |
| `0x80291F84` | `njRotate` | `PSMTXRotAxisRad` |
| `0x80292000` / `0x802921B0` / `0x80292230` | `njRotateX` / `njRotateY` / `njRotateZ` | `PSMTXRotRad` with `'X'` / `'Y'` / `'Z'` |
| `0x80292080` / `0x802922B0` | `njRotateXYZ` / `njRotateZXY` | M·Rz·Ry·Rx / M·Ry·Rx·Rz |
| `0x80292A60` | `njRotateEx` | `Angle[3]` on the current matrix, order chosen by `lv` |
| `0x802923E0` / `0x802924E0` / `0x80292538` | `njScale` / `njTranslate` / `njTranslateV` | `PSMTXScale` / `PSMTXTrans` + concat |
| `0x80292BDC` / `0x80292C28` | `njScaleEx` / `njTranslateEx` | the same, vector argument, current matrix |
| `0x80292478` | `njSetMatrix` | copies `ms` into `md` (or the current matrix) |
| `0x802924BC` | `njSubVector` | `PSVECSubtract` in place |
| `0x8029259C` | `njUnitMatrix` | `PSMTXIdentity` |
| `0x802925D4` / `0x8029261C` | `njUnitRotPortion` / `njUnitTransPortion` | resets the rotation part / zeroes the translation |
| `0x80292648` | `njUnitVector` | normalizes, returns the length |
| `0x80288F88` | `njControl3D` (likely) | stores its argument in `_nj_control_3d_flag_`; game code passes Ninja-style flag words (`0x32C` for 2D, `0xB28` for 3D) |
| `0x80288F7C` | `njSetConstantAttr` (likely) | stores and/or attribute words in `_nj_constant_attr_and_` / `_nj_constant_attr_or_` |
| `0x80288F54` | `njSetConstantMaterial` (likely) | copies four floats (ARGB) to `_nj_constant_material_` |
| `0x80296CAC` | `njColorBlendingMode` | `(target, mode)`: target 0 / 1 = source / destination; the 12 modes index a table in Dreamcast order, and the game's default is 8 / 6 (`SRCALPHA` / `INVSRCALPHA`) |
| `0x802AC6EC` | `njMemCopy` (likely) | `memmove(dst, src, count * 4)` |
| `0x80299188` | `njClipZ` (likely) | clamps near/far, recomputes the frustum |
| `0x80299238` | `njSetAspect` (likely) | stores the aspect, recomputes the frustum |
| `0x802993C8` | `njSetScreen` (likely) | takes a screen struct, recomputes the frustum |

The SDK matrix/vector routines these call (`PSMTX*`, `PSVEC*`, `C_MTXFrustum`, `C_MTXOrtho`) were
named at the same time, from compiled `mtx.c` and from their paired-single code.

Globals
-------

Not renamed in `symbols.txt` (the real Ninja names aren't known), but useful when reading the asm:

| Address | What |
|---|---|
| `lbl_80347EB4` | current matrix pointer (Ninja's `_nj_curr_matrix_`) |
| `lbl_80347EB0` / `lbl_80347EA8` / `lbl_80347EAC` | matrix stack base / depth / depth limit |
| `_nj_control_3d_flag_` / `_nj_constant_attr_and_` / `_nj_constant_attr_or_` / `_nj_constant_material_` | what the setters above store (named in `symbols.txt`, Ninja's DC names) |
| `lbl_80347F70` | "matrix changed" flag (set to 5 by anything that edits a matrix) |
| `lbl_80347F6C` | "projection changed" flag (set to 2) |
| `0x80345878` | screen parameters (distance, center, aspect), read by `njProjectScreen` |
| `0x80345850` | view volume (near, far, frustum extents) |
| `0x80346400` | perspective projection matrix built by `C_MTXFrustum` |
| `0x803463C0` | 2D (orthographic) projection matrix built by `C_MTXOrtho`; `lbl_803464D0` is its position matrix (see [widescreen.md](widescreen.md)) |
| `0x803007C8` | identity matrix constant |

Layout (approximate)
--------------------

Inferred from what each stretch calls; file boundaries aren't known yet.

| Range | Contents |
|---|---|
| `0x80286EE8`–`0x80290ED4` | Two model renderers. Each starts with the same light-transform routine over its own light table (`0x80286EE8` → `0x80344DE0`, `0x8028B498` → `0x80345350`); called ~160 times each |
| `0x80290ED4`–`0x802913D4` | Immediate-mode drawing through `GXBegin` (polygons, lines) |
| `0x802913D4`–`0x80292E9C` | Math and matrix library (the table above) |
| `0x80296xxx`–`0x80299040` | GX render state: Z mode, blend mode, background clear |
| `0x80299188`–`0x80299600` | Screen and projection setup |
| `0x80299BD8`–`0x8029C8A0` | Material / TEV setup (library-internal) |
| `0x8029C8A0`–`0x8029CC2C` | Loads the projection and position matrices into GX |
| `0x802A8AE4`–`0x802A8F40` | `NGDL` / `NGGD` display-list models (Sega's GC format) drawn with `GXCallDisplayList` |
| `0x802AB460`–`0x802AC75C` | Screen clear / fade |
| `0x802AC75C` | `OSReport` (a `vprintf` wrapper) |

Hook points for a port
----------------------

- **Widescreen / resolution:** `njSetAspect`, `njSetScreen`, `njClipZ` and the other callers of
  `C_MTXFrustum` / `C_MTXOrtho` in `0x80299188`–`0x802994xx`; everything funnels into the
  projection matrix at `0x80346400` and the GX loads in `0x8029C8A0`–`0x8029CC2C`.
- **Frame interpolation (60 fps):** game logic runs at a fixed 30 Hz ([frame_loop.md](frame_loop.md)),
  so a port draws in-between frames. Tagging the matrix functions above (as N64 recomps do with
  RT64's matrix groups) isn't enough here: the model renderers transform vertices on the CPU and send
  them to GX already in view space, so the XF matrices barely change between frames (about 2 of
  2,400 loads per frame in the opening cutscene) and the motion, camera included, is in the vertex
  positions. The recomp interpolates in the video code instead, blending each draw's positions with
  the previous frame's (`../SkiesOfArcadiaLegends-Recomp`, NOTES *60 fps*).
- **Widescreen:** done as a patch on these functions and the 2D layer; see [widescreen.md](widescreen.md).
- **Model drawing:** the two renderers at `0x80286EE8` and `0x8028B498`, and the display-list
  path at `0x802A8AE4`.

Hot in profiles
---------------

`perf` on the native recomp (`../SkiesOfArcadiaLegends-Recomp`, LLVM backend, opening cutscene,
2026-10-05) puts these unnamed Ninja functions among the hottest guest code. They're the best
next targets for naming here, and for native replacements in a port:

| Address | Size | Share of the game thread |
|---|---|---|
| `fn_802A21C4` (with `fn_802A2394` in the same region) | `0x1D0` | ~5–6% |
| `fn_802A49F4` | `0x22C` | ~2% |
| `fn_802A5F2C` (with `fn_802A6184`) | `0x258` | ~0.7% |

Also hot outside Ninja: the SDK's `PSMTX*` paired-single matrix functions (`0x80238B60`–`0x80238FE8`)
and `GXSetProjection` / `GXLoad*MtxImm` (`0x80251F8C`–`0x8025228C`). The SDK scheduler's idle spin in
`SelectThread` (`0x80237BA8`) was hot too, and the recomp now skips it (`StaticRecompIdlePC`).
