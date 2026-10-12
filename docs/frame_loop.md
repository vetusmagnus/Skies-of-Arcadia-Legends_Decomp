The frame loop and frame pacing
===============================

What one frame of Skies does, and why it runs at 30 fps. This is the ground work for a 60 fps
port. Function names are in `config/GEAE8P/symbols.txt`; the VI and GX framebuffer functions were
identified by their size and order against the Sep 2002 SDK (`extern/sdk`).

`main`
------

`main` (`0x801DCB28`) calls `fn_801DC62C` (setup: Ninja init `fn_802970A0`, `njInitMatrix`,
`njSetAspect(1.1, 1.0)`, `VISetPostRetraceCallback(fn_801DC3AC)`) and then loops, once per frame:

| Call | What it does |
|---|---|
| `VIGetRetraceCount` -> `lbl_8034768C` | remembers the retrace count at the start of the frame |
| `fn_801D23E0`, `fn_80296F6C`, `GXSetViewportJitter` (field rendering only) | frame setup |
| `fn_80290ED4` | full-screen background quad, with a colour per corner |
| `fn_801D6E58`, `fn_801D74FC`, `fn_801C7904`, `fn_801DBF94` | game update |
| `fn_801D1268`, `fn_801DC288` | `fn_801DC288` dispatches on the game mode (`lbl_803475CC`) and increments the frame counter `lbl_803475C0` |
| `fn_801D0F80` | submits the frame: Ninja's model renderers, then the recorded display lists by layer (`fn_802A8AE4` with `GXFlush` between layers), then the screen effects (`fn_801D1714`) |
| `fn_80210338`, `fn_8010CC74`, `fn_801E1F3C`, `fn_800FF4B0`, `fn_8011B820` | menus, text and HUD (order depends on `lbl_80347490`) |
| `fn_801CB8E0`, `fn_801C6224`, `fn_801D168C`/`fn_801D150C` | overlays and late updates |
| `fn_801DC420` | end of frame, below |

`fn_801DC420`, end of frame
---------------------------

1. Updates an FPS counter from `OSGetTick` (`lbl_803475B8`, frames counted in `lbl_803475C0`).
2. `GXCopyDisp(lbl_803476AC, 1)`: copies the frame into the next XFB.
3. Waits until `VIGetRetraceCount() - lbl_8034768C >= 1`: at least one retrace since the frame began.
4. `VISetNextFrameBuffer`, `VIFlush`, `fn_80296F48`, then `VIWaitForRetrace`.
5. Swaps the two XFBs (`lbl_803476AC` / `lbl_803476B0` / `lbl_803476B4`).

So a frame takes at least two retraces: 30 fps on a 60 Hz display, which is the rate the game runs
at on hardware.

Rendering is recorded, then replayed
-------------------------------------

The 3D scene isn't drawn straight to the GPU. The game's per-layer scene functions (`fn_801CC6BC`,
`fn_801CCD90`, `fn_801CD118`, `fn_801CD73C`, `fn_801CDC68`, `fn_801CE1A4`, `fn_801CE6D0`,
`fn_801CF248`, `fn_801D0DCC`, `fn_801D0ED4`) open a display list through `fn_802A8D64` /
`fn_802A8E50` (`GXBeginDisplayList` into an `NGDL` block holding up to two `NGGD` lists), draw
through Ninja, and close it. `fn_801D0F80` (and `fn_801D1714` for the effects) later replays the
blocks with `fn_802A8AE4` (`GXCallDisplayList`). Matrices are loaded with `GXLoadPosMtxImm` while
recording, so they're baked into the lists: replaying a list again can't move anything, and an
in-between frame has to run the scene functions again with interpolated transforms.

Fixed step
----------

Nothing reads the retrace count apart from that wait, and the frame counter is a plain increment:
the game logic advances one fixed step per frame. Letting the loop run at 60 fps (dropping the wait
in step 3) would make the whole game run twice as fast. A 60 fps port has to keep the logic at 30 Hz
and draw in-between frames. Because the matrices are baked into the recorded lists and Ninja's model
renderers transform vertices on the CPU (the positions in the GX stream are already in view space),
the recomp does this below the game: it records each frame's GX stream and replays it with vertex
positions and matrices halfway to the previous frame's (`../SkiesOfArcadiaLegends-Recomp`, NOTES
*60 fps*). A game-side alternative would have to run the per-mode scene functions above a second time
with interpolated object and camera state.

The recomp uses exactly this for its battle speed option: in battle (game mode 7) it skips the wait in
step 3 (2x) and some of the `VIWaitForRetrace` calls in step 4 (3x, 4x), through whole-call wrappers at
`0x801DC498` and `0x801DC4D8` (`patches/game/qol.c`, [qol_cheats.md](qol_cheats.md)). The music isn't tied
to the frame loop (MusyX runs from the audio interrupt).

GPU sync and the "GPU hang" recovery
------------------------------------

`fn_801DC420` (at `0x801DC488`) and two other callers (`0x80030034`, `0x80226D50`) call `fn_801D22CC`,
which makes sure the GPU has finished the frame:

1. clears the retrace counter `lbl_80347600` (incremented per retrace around `0x801D1E50`) and sends
   draw-sync token `0xB00B` through `fn_8024DF5C` (`GXSetDrawSync`);
2. polls `fn_8024E014` (`GXReadDrawSync`, the PE token register) until it reads `0xB00B`;
3. if two or more retraces pass first, decides the GPU has hung: optionally `OSReport`s, calls
   `fn_801D20D8` / `fn_801D1ED4`, `fn_8024E020` (`GXDrawDone`-like: token, `GXFlush`, sleep until
   done), then re-initialises the FIFO on `VIGetNextFrameBuffer()`'s memory (`GXInitFifoBase`,
   `GXSetCPUFifo`, `GXSetGPFifo`, limits `0x3C000` / `0x10000`) and leaves the loop.

On hardware the GPU is never that far behind. In an emulator with a separate GPU thread it can be,
and the reset pulls the FIFO out from under that thread: this is Skies' dual-core desync ("Unknown
Opcode") and why Dolphin forces single core for it. The recomp fixes it below the game: a PE token
read waits until the GPU thread has worked through the FIFO (`../SkiesOfArcadiaLegends-Recomp`, NOTES
*60 fps on Android: dual core*). The main FIFO is 256 KiB (high watermark 240 KiB, low 64 KiB, overflow
interrupt on); in practice the CPU stays within ~54 KiB of the GPU thread.
