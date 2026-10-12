Projection, the 2D layer and widescreen
=======================================

How Skies draws its 3D view and its 2D layer through Ninja, and what a widescreen patch has to change.
The patch built on this is in the recomp project
(`../SkiesOfArcadiaLegends-Recomp/patches/game/widescreen.c`). Function names are in
`config/GEAE8P/symbols.txt`, and the Ninja ones are explained in [ninja.md](ninja.md).

The screen parameters
---------------------

`lbl_80345878` is Ninja's screen block, as `njProjectScreen` and the projection setters read it:

| Offset | Value (unpatched) | Meaning |
|---|---|---|
| `0x00` | `aspect_x * dist` | x scale from view space to pixels |
| `0x04` | `-(aspect_y * dist)` | y scale (negative: y points down on screen) |
| `0x08` / `0x0C` | 320 / 240 | screen centre |
| `0x10` / `0x14` | reciprocals of `0x00` / `0x04` | used to build the frustum |
| `0x18` | `dist` | screen distance, set from the field of view by `fn_802992F8` |
| `0x1C` / `0x20` | 1.1 / 1.0 | `aspect_x` / `aspect_y`, set by `njSetAspect` |
| `0x24` | `aspect_y / aspect_x` | |
| `0x28` / `0x2C` | 640 / 480 | screen size |

`lbl_80345850` is the view volume: `[0]` far and `[1]` near (both stored positive, 60000 and 1.1 in
the first battle), then the screen extents around the centre that the frustum is built from.

Every function that rebuilds the perspective matrix at `0x80346400` (`njSetAspect`, `njSetScreen`,
`fn_802992F8`, `njClipZ`) reads `aspect_x` from the screen block. `njProjectScreen` uses the same
numbers, and game code culls with it (for example `fn_800BE6EC`, which draws a battle object only if
its projected point lies on screen), so culling follows whatever the projection does.

### The 1.1

`main`'s setup function `fn_801DC62C` calls `njSetAspect(1.1, 1.0)` once at boot (the constant
`lbl_8034BED8` is used nowhere else). 1.1 is 704/640: the game's 640-pixel line covers the analog
picture's 704-pixel active width, so a 4:3 TV shows it at `4/3 * 640/704`, about 1.21. Dolphin
applies the same correction, which is why its "Force 16:9" output comes out at about 1.62:1. To fill
a display of aspect `A`, multiply `aspect_x` by `(4/3 * 640/704) / A`: 0.75 for 16:9 (`aspect_x`
0.825 for Dolphin's analog-correct 16:9).

The 2D layer
------------

`lbl_803463C0` is the 2D projection, an orthographic `Mtx44` built once by `fn_802970A0` (Ninja's
init) with `C_MTXOrtho(240, -240, -320, 320, ...)`. `lbl_803464D0` is the matching position matrix,
which moves screen pixels (0..640, 0..480) to the centre. `fn_8029CB74` loads both into GX
(`GXSetProjection` with the orthographic flag, `GXLoadPosMtxImm`) and is called before every 2D draw,
unconditionally; `fn_8029CA58` switches back to the perspective matrix (`lbl_80347F6C` tracks which
one GX holds).

So `[0][0]` of the orthographic matrix (1/320) is the single knob for the width of all 2D: scaling it
by 0.75 shows the 2D layer at its original shape in the middle of a 16:9 picture, and everything in
the HUD keeps its position relative to the others.

Most game-side 2D goes through two Ninja primitives that draw triangle strips in screen pixels:

| Function | Vertex | Notes |
|---|---|---|
| `fn_80290ED4(verts, count, mode)` | x, y, z, colour (`0x10` bytes) | `main` draws a full-screen background quad with it every frame; `fn_801CB8E0` a full-screen colour overlay |
| `fn_80291064(verts, count, mode)` | x, y, z, u, v, colour (`0x18` bytes) | textured; most menus and HUD |

`fn_8028A26C` / `fn_8028A6BC` only set up 2D drawing (projection and material) for code that writes
its own vertices.

Full-screen 2D
--------------

Anything that has to cover the whole picture must be drawn with the full-width matrix:

- Ninja's screen effects: `fn_802AB608` (clear plus a full-screen quad) and `fn_802AB460`, which
  copies the frame to a texture (`GXSetTexCopySrc` / `GXSetTexCopyDst` / `GXCopyTex`) and draws it
  back through `fn_802ABB9C` and `fn_802AB8FC`. `fn_801D1714` calls them every frame; they make the
  cutscene afterimage, blur and fade effects (squeezed, they leave ghost bands at the 4:3 edges).
- `fn_800AF8F8`, a game effect that copies the screen and draws it back with `fn_80291064`.
- `fn_80226D14` only copies the frame to a texture; its callers draw it.
- Backgrounds and overlays drawn with the two primitives above. A polygon that reaches both screen
  edges (x <= 0 and x >= 640) is a reliable sign.
- The battle-entry shatters are 3D, sized to the game's own field of view, so the widened projection
  squeezed them into the middle 4:3 (found 2026-10-09 with the recomp's projection trace: the only chain
  new during the transition is `fn_8029C8A0` (perspective load) <- `fn_80287C14` <- `fn_80288DE4` <-
  `fn_80287B38`, Ninja's object draw). Two variants:
  - spinning card: `fn_802297C4`, a screen-effect task callback (set up by `fn_80228C50`, `fn_80228E00`,
    `fn_80229124`, `fn_802293E0`), draws the copied screen as 3D tiles through `fn_80287B38` at
    `0x80229974` / `0x80229BA8`;
  - falling triangles: `fn_80101828` copies the screen (`fn_80226D14`) and calls `fn_80097CA4` (four
    sites), which draws through `fn_80097B0C` -> `fn_80097CEC` -> `fn_80098DA4` (rotated pieces), each
    reached only on this path.
  The recomp's patch draws both at the unwidened aspect (`aspect_x` / factor, rebuilt with `njClipZ`;
  Ninja reloads the perspective matrix for every 3D draw). The 2D path the task `fn_800B0FD0` uses
  (`fn_800B0278`, `fn_800AF780` / `fn_800AF8F8`) is a different transition. Other `fn_80226D14` callers:
  `fn_8002FF70` (battle task list), `fn_800D81E8` (callback set at `0x800D8514`), `ScreenWipeDraw`,
  `fn_8011CE6C`.

UI parked off-screen
--------------------

Menus keep UI they aren't showing yet just outside the 4:3 frame: the next page of the party status
screen sits to the right, and the save/continue screens' card slot cursor comes in from the left
edge. With the 2D layer squeezed into the middle of a wider picture, that space is visible. Every
such element is a UiObj moved to a parked position; the positions per screen, and what a fix at
that level could look like, are in [ui.md](ui.md#off-screen-parking-and-widescreen).

The recomp's patch clips to the 4:3 area with `GXSetScissor` whenever the squeezed 2D projection is
loaded (Ninja's loaders `fn_8029C8A0`, `fn_8029C93C`, `fn_8029CA58`, `fn_8029CB1C`, `fn_8029CB74` all
go through `GXSetProjection`, and nothing else sets the projection after `GXInit`; the game itself
only sets a full-screen scissor, in `fn_801D1B28` / `fn_801D1ED4`). It writes the matching scissor on
every projection load. A first version wrote it only when the clip turned on or off, and that cut the
3D scene to 4:3 in some rooms: projection loads also happen while the scene is recorded into display
lists ([frame_loop.md](frame_loop.md)), so the CPU's order of loads isn't the GPU's. Writing on
every load keeps the scissor with its projection, recorded or not.

The script fade `ScreenFadeDraw` (`fn_80210390`, one caller, always 0 .. 640 x 0 .. 480) loads the
2D projection through `fn_8028A26C` and draws with Ninja's own `fn_8028A0F4`, so the patch runs it
with the full-width projection. Its state is at `lbl_8030CEA0 + 0xC5C` (enabled), `+ 0xC60` (ARGB,
drawn when alpha isn't 0) and `+ 0xC64` (z).

2D placed at 3D points
----------------------

Battle name labels, HP bars and damage numbers are 2D drawn at points from `njProjectScreen`:
`fn_80029B70` and `fn_8002A574` (the battle UI, which also runs the label manager `fn_8021C62C`;
found by tracing which code loads the 2D projection) round the projected point to pixels and draw
there, and `fn_800B522C` / `fn_800B8028` project the four corners of 2D quads. With the 3D view widened and the 2D layer
squeezed, they would land toward the centre; in 2D units the right x is
`centre + (x - centre) / factor`, which is exactly the unwidened projection. The other callers of
`njProjectScreen` (`fn_800A432C`, `fn_800A8FE0`, `fn_800B8CB8`, `fn_800BE6EC`, `fn_800E178C`,
`fn_8011E72C`) compare the result with the screen bounds, so they cull and need the widened one.
Not classified yet: `fn_800B676C` (projects two endpoints of an effect), `fn_8011BD5C` (copies the
point into a vertex list), `fn_801EB330` (projects, then calls `fn_80291E18`).

Ship battle HUD
---------------

(2026-10-11.) The ship battle's 2D, by code: `fn_8012B054` Spirit gauge and the long bar (its max digits
through `TextPrintf`), `fn_8012C744` command ring, `fn_8012E640` the ring's lists, `fn_801331AC` crew
member and ship panels, `fn_801303D0` the turn bar over the grid, `fn_80131734` the command grid,
`fn_8012F958` the action name banner, `fn_8015887C` the HP plates (an object per ship: position at
+0x88 / +0x8C, set each frame from the index at +0x10: plate 0, the party's ship, at (42, 114), the
others at (502, 74 + 40 * index); it draws through `fn_8021C62C` at `0x80158994` and the status icon
`fn_80159610` at `0x8015899C`, which places itself by the same index), and the damage popups
`fn_8021F330` / `fn_8021F0EC` (shared code; their sprite at +0xC, x first, drawn by `fn_80005D98` at
`0x8021F84C` / `0x8021F880` / `0x8021F308`). The recomp's anchors for them: patches/game/widescreen.c and
the recomp's NOTES *Ship battle HUD*.

Frame loop
----------

See [frame_loop.md](frame_loop.md).
