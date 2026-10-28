Sega Ninja library (GameCube)
=============================

`0x80286EE8`–`0x802AC7E0` (~150 KB, 452 functions), the last part of `.text`, is Sega's **Ninja**
graphics library in its GameCube form, built on GX. There's no decomp or symbol map of GC Ninja to
match against, so functions are named here by behavior, using Ninja's public API (Dreamcast
documentation, Sonic Adventure PC symbols). The region is one NonMatching unit, `src/ninja/ninja.c`
(shared types in `include/ninja_lib.h`); see "Matching status" below.

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
| `0x803463C0` | 2D (orthographic) projection matrix built by `C_MTXOrtho`; `lbl_803464D0` is its position matrix |
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

Where things are
----------------

- **Projection:** `njSetAspect`, `njSetScreen`, `njClipZ` and the other callers of
  `C_MTXFrustum` / `C_MTXOrtho` in `0x80299188`–`0x802994xx`; everything funnels into the
  projection matrix at `0x80346400` and the GX loads in `0x8029C8A0`–`0x8029CC2C`.
- **Model drawing:** the two renderers at `0x80286EE8` and `0x8028B498`, and the display-list
  path at `0x802A8AE4`.

Matching status
---------------

211 of 452 functions match byte for byte (`src/ninja/ninja.c`, objdiff and `tools/match/fdiff.py`
plus `floatcheck.py` agree; main.dol still hashes OK). The unit covers the whole region
(`0x80286EE8`-`0x802AC7DC`) because no real file boundary has turned up: the `.sdata2` pool is
contiguous in text order, so the data gives no edge, and no edge has been checked against
padding yet. Add a split only when evidence shows one (padding, a data pool edge, a known Ninja file
layout).

**Compiler.** The library builds with the game's flags (GC/1.3.2, `-O4,p`, `-inline noauto`).
`-O1` makes `njSin`/`njCos`/`njTan` match but breaks about half of the other functions, so that is
a coincidence of one conversion pattern, not the library's setting.

**Source forms that matched.**
- A null matrix argument means the current matrix: `m ? m : (lbl_80347F70 = 5, lbl_80347EB4)`
  as a ternary. `if (!m) m = ...` gives a different branch shape (`bne` instead of `beq; b`).
- Ninja matrices are `Float[16]` but the SDK takes `Mtx`, so the PSMTX/PSVEC routines are declared
  in `ninja_lib.h` with flat `f32*` pointers.
- Rotation helpers read `Angle` as `a * 9.58737801e-05f` (the pool constant is `0x38C90FD8`, not
  the nearest decimal of 2*pi/65536: `floatcheck.py` caught the first guess).
- Self-recursive `inline` functions unroll four levels (the node-tree walkers). They are emitted
  out of line only because a caller calls them (`fn_802A9338` / `fn_802A9B94` call `fn_802A907C` /
  `fn_802A98D8`). The motion walkers `fn_80294A0C` / `fn_80295738` match as four `static inline`
  levels plus the outer function (`MOTION_WALK` in `ninja.c`); one self-recursive `inline` doesn't.
- A function that is both inlined in this unit and called from game code (`fn_8029D010`) is a
  `static inline` helper plus an out-of-line wrapper.
- The two light setters index the table directly after `n--`; a `NjLight*` local keeps the
  table's +8 as a separate `addi`.
- `fn_8029D010` keeps the blend factors in `u16` locals: that is where the `clrlwi` before
  `GXSetBlendMode` comes from.
- The 16-byte-stride vertex loops copy the strip's index list with `do { } while (--n)`.

**Types** (`include/ninja_lib.h`, one definition each, derived from every matched user):
- `NjObj` (evalflags, model, pos, rot, scl, child, sibling, qw/radius) is the node the motion
  walkers and the model drawers share; `rot` is `Angle[3]` or the quaternion xyz. `NjModel` is the
  chunk model it points to (vlist, plist, center, r); model callbacks are `s32 (*)(NjModel*)`.
  `fn_802AB23C(obj)` takes the node (its callers leave it in r3).
- `NJS_MOTION` (mdata, nbFrame, type, inp_fn) and `NJS_MOTION_LINK` (two motions, two frames):
  `fn_80295140` / `fn_802A9B94` take a link and a blend rate, `fn_80295E6C` / `fn_802A9338` a motion
  and a frame. `NjMotState` (`lbl_80347E64`) holds the key count/flags and the five key getters.
- `NjLightTbl` (`lbl_80344DE0`, `lbl_80345350`): a dirty flag, a word, 8 `NjLight` entries of 0x60
  from +0x8, then the `GXSetChanCtrl` mask/diffuse/attenuation for COLOR0 and ALPHA0 at +0x30C.
- Textures: `NJS_TEXNAME.texaddr` points at an `NjTexRef` (`lbl_80347ED4`, 0x18 bytes) whose `mem`
  is an `NjTexMem` slot (`lbl_80347ECC`, 0x48: id, a 0x20-byte `NjTexBody` handed to the loaders,
  the `GXTexObj`, a refcount). `lbl_803457F8` is `NjTexErr` (texlist index, global index, error
  code) and `lbl_80346500` is a lone `NjTexBody`.
- `NjGxState` (`lbl_803457A8`, 0x50 bytes): state words, the blend mode at +0x22, a mode at
  +0x2A and the current texlist at +0x44.

### Near misses (same instructions, different order or registers)

Logged, not integrated as matches. Functions marked * are in the unit as NonMatching.
- Conversion store order: `njSin*`, `njCos*`, `njTan*` (2 lines each: `stw r3` before `stw r0`
  for the int-to-float magic). ~15 source forms tried.
- `njInitMatrix*` (the limit is stored before the base), `fn_802928F4*`, `fn_80292A00*`,
  `fn_80297504*` (register order).
- **GX immediate-mode FIFO writers (about 30 functions, the biggest blocker).** The original
  hoists several separate copies of the FIFO address (`lis rN,0xcc01` then `mr` copies, one per
  store after the second) and reloads the shared 0.0f/1.0f constants before every store. Every form
  tried compiles to one shared register: SDK `GXPosition*` inlines, `GXWGFifo` direct, a fixed
  address `volatile` union, `(volatile T*)0xCC008000` macros, inline helpers with 1/3/7 arguments,
  local pointer variables. Affected: `fn_8028A056`-`fn_8028A8C0`, `fn_80290ED4`, `fn_80291064`,
  `fn_802911CC`, `fn_80296918`, `fn_8029DCD0`, the strip drawers `fn_8029DEDC`-`fn_802A2E18`
  (`fn_8029EE78`, `fn_8029F2A8`, `fn_8029F528` are 4 lines off, `fn_8029F9F8`, `fn_8029FB54`,
  `fn_8029FCB0`, `fn_802A018C` 2 lines), `fn_802A5738`, `fn_802A58DC`, `fn_802AAE5C`, `fn_802AB608`,
  `fn_802AB8FC`, `fn_802ABB9C`.
  - The ARGB-to-RGBA colour swap is `__rlwinm(c, 8, 0, 31)` (gives `rotlwi r0,r0,8`);
    `(c << 8) | (c >> 24)` gives `srwi` + `rlwimi` here. With that, `fn_8028A0F4`, `fn_80291064`
    and `fn_8029681C` differ only in the address registers.
  - The register pattern is per write, not per call: within one vertex the first two writes share
    the hoisted `lis`, and every later write has its own copy (`fn_8029681C` has a single
    `GXPosition3f32` and still copies the address for z). `fn_80289B70`, unrolled 8 times, keeps
    24 separate copies and spills some to the stack, so the address was a separate value per write
    before unrolling.
  - Also ruled out (all fold to one register): every GC compiler from 1.0 to 3.0a5.2 at
    `-O2`..`-O4,p`/`-O4,s`, `-opt` no-cse/no-prop/no-lifetimes/no-loop-invariants and other
    switches, `-inline` deferred/auto/smart, C++ mode; `extern volatile` / non-volatile `AT_ADDRESS`
    unions, unions and structs with `volatile` members, separate same-address symbols, const/enum/global-const addresses, pointers returned by
    an inline function, `register` pointers, pointer parameters per write and per call, nested
    `POS2`+`POS1` helpers, inlines defined after use, indexed and pointer loops. Test files are in
    `build/agents/fifo/` (local).
- Register allocation or scheduling only: `fn_80286EE8`, `fn_8028B498`, `fn_80288C68`,
  `fn_8028F884`, `fn_8028FD98`, `fn_8028FEA4`, `fn_802904E8`, `fn_802907D0`, `fn_80290918`,
  `fn_80291700` (Bezier), `fn_802917C8` (Catmull-Rom), `fn_80291888`, `fn_802918DC`, `fn_80291978`,
  `fn_80291A5C`, `fn_802915C8`, `fn_802938C8`, `fn_802939C4`, `fn_80293B34`, `fn_80293B4C`,
  `fn_80293C2C`, `fn_80293F20`, `fn_802947D4`, `fn_80296090`, `fn_802960A8`, `fn_80296EEC`,
  `fn_80297804`, `fn_80297DC8`, `fn_8029800C`, `fn_802982F0`, `fn_802986C8`, `fn_80298700`,
  `fn_80298BCC`, `fn_80298BF8`, `fn_80299040`, `fn_80299500`, `fn_8029D0F4`, `fn_802A0668`,
  `fn_802A0B38`, `fn_802A0C90`, `njColorBlendingMode`, `fn_802AB340`, `fn_802AB460`, `fn_802AC160`.
- Large walkers close in structure but not allocation: `fn_80287610`, `fn_80287D98`, `fn_80289228`,
  `fn_80289390`, `fn_802873BC`, `fn_802A93CC`, `fn_80296424`, `fn_802AC31C`.
- Not attempted: paired-single code (`fn_802A5B48`, `fn_802A5D20`, `fn_802A21C4`), the 2.9 KB
  `fn_802AA2F0`, `fn_8029B248` (5.7 KB), `fn_8028BE90`, `fn_8028DD5C`, `fn_80287F00`, `fn_802A6398`,
  `fn_8028CF20` and the other functions over 3,000 bytes.

### Recurring blockers in the rest of the unit

- **Result copied through r0.** A call's result (or an inline helper's return value) goes
  `mr r0, r3` then into its saved register or `mr r3, r0` at the end: `fn_80298700`, `fn_80299500`,
  `fn_80297864`, `fn_802954EC`, `fn_80297804` (`mr. r0, r3`). int/s32/u32/s16 result variables,
  `register`, inner scopes and inline helpers don't reproduce it.
- **Scheduling of one early instruction** (a constant load, a `li`, a `cmpw`): `fn_802907D0`,
  `fn_802915C8`, `fn_80296DC8`, `fn_80296E4C`, `fn_80298FE4`, `fn_80293690`, `fn_80296B60`,
  and the r3/r4 swap around a table-index `mulli` (`fn_80293B34`, `fn_80296090`, `fn_80298BCC`).
- **Generic key tables.** `fn_802938C8` / `fn_802939C4` search byte-strided key tables and hand back
  `s16*` / `s32*` key pointers, but some callers read the keys as `u16` (`fn_80294100`, `lhz`) or
  `f32` (`fn_802946D0`, `fn_80294770`); without one key type per caller these need casts, as does
  the search itself (`fn_80293AF4`).
- **Flat matrices vs `Mtx`.** `ninja_lib.h` declares the PSMTX routines with `f32*`; code that also
  hands a matrix to `GXLoadPosMtxImm` / `GXLoadTexMtxImm` (`fn_8029CB1C`, `fn_8029CA58`,
  `fn_8029C9B0`) can't satisfy both without a cast.
- **Constant copies per unrolled store** (`fn_80295FEC` zero-fill), the same shape as the FIFO
  address copies.

### Matched in isolation, not merged

Every agent match that verified on its own is merged except three:
- `fn_8029CB1C` loads the current matrix with `GXLoadPosMtxImm(lbl_80347EB4, 3)`. The SDK takes
  `const f32 (*)[4]` and `lbl_80347EB4` is `f32*`, so it needs a cast; the clean fix is a 3x4
  `NJS_MATRIX`, which changes the size of the game's `NJS_MATRIX` locals.
- `fn_8029EFD0`, `fn_8029F400` (position-only strip drawers) step the strip pointer by
  `nuv * 2` bytes. `strips += nuv` allocates registers differently; only a byte cast or
  `nuv * 2 ... / 2` matches.
