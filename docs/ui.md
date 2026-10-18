Menus, HUD and the 2D layer
===========================

How Skies builds its menus and HUD on top of Ninja's 2D drawing, and where each screen puts its
elements, including the ones parked off-screen. Research from 2026-10-07; function names are in
`config/GEAE8P/symbols.txt` (names given from behavior, since the game's own names aren't known).
The projection side (the 2D matrix, what widescreen changes) is in [widescreen.md](widescreen.md).

Decompiled so far: `src/game/drawstate.c` (linked), `src/game/uiobj.c` (UiObj, layouts and
sprites: 40 of 44 functions match) and `src/game/text.c` (28 of 33). The last two link once their
remaining functions match; what's left is register allocation and scheduling (see [Open](#open)).

Layers
------

| Layer | What it does | Where |
|---|---|---|
| Ninja 2D primitives | triangle strips in screen pixels (`fn_80290ED4`, `fn_80291064`), and Ninja's own `fn_8028A0F4` / `fn_8028A56C` after `fn_8028A26C` / `fn_8028A6BC` | [widescreen.md](widescreen.md) |
| Draw state stack | blend mode, constant material colour, fog for whatever is drawn next | `drawstate.c` |
| Text queue | strings are queued during the frame and drawn together by `main` | `text.c` |
| Layouts and sprites | a screen element is a list of sprite parts, each a few textured quads | `0x801C3AEC`–`0x801C5400` |
| UI objects | an element's position, target and animation; every panel, window and cursor has one | `uiobj.c` |
| Tasks | each element is a task with its own update/draw function | `TaskDelete`, `fn_802267AC`, `fn_802268E8` |
| Screens | the camp (pause) menu, save/load, shops, battle and field HUD | below |

### Draw state stack

`DrawStatePush` copies a `DrawState` onto a 32-deep stack (`drawstate_stack`) and applies it;
`DrawStatePop` drops it. A state is Ninja's 3D control flags, constant attributes, constant material
colour (`NJS_ARGB`), source/destination blending (`njColorBlendingMode`, alpha blend by default) and
a fog switch. Callers start from `DrawStateDefault2D` / `DrawStateDefault3D`, change a field or two,
push, draw and pop; `DrawStateApply` only reloads what differs from Ninja's current values. The same
file keeps a clip distance stack (`ClipZPush` / `ClipZPop` / `ClipZSet` around `njClipZ`).

### Text queue

`src/game/text.c` (28 of 33 functions match; not linked yet). `TextPrint(x, y, str)` doesn't draw:
`TextNodeNew` converts the string (ASCII, or Shift-JIS with lead bytes 0x81-0x98; anything else
becomes 0x8197) into 16-bit codes in a node from `heap_main`, together with a copy of the current
`text_state` (colour, position, z, character scale, clip rectangle), and appends it to the queue
(`text_head` / `text_tail` / `text_count`). `TextPrintN`, `TextPrintNumber` (with zero or space
padding), `TextPrintf` and `TextContinueN` (carry on where the last string ended) are variants.
`main` calls `TextFlush` once per frame: it loads the 2D projection (`fn_8029CB74`), sets its own
vertex format and draws every node with `TextDrawNode`, not through the two primitives. A space
advances 12 px times the x scale, a newline 24 px times the y scale.

Each glyph (`TextDrawGlyph`) is rendered into one of 512 24x24 I4 textures (`glyph_ring`, 0x120
bytes each) and drawn as one quad written straight to the GX FIFO. The bitmap comes from the game
font when it's loaded: an `'AFNT'` file (`font_path`) whose pointers `FontRelocate` fixes up,
read by a three-state loader (`FontInit`, `FontUpdate` through `font_state_funcs`). `FontFindGlyph`
maps a code to a glyph through four code ranges (`font_ranges`) and 15 special codes
(`font_specials`); a glyph is stored raw or run-length encoded (`FontExpandRle`). Codes the font
doesn't cover fall back to the SDK font. `TextSetColor` / `TextPushColor` / `TextPopColor` work on
an 8-deep colour stack (`text_color_stack`), `TextSetZ` sets the depth (menus pass their element's
z minus 27.5) and `TextSetScale` the character scale.

### Layouts and sprites

In `uiobj.c` after the UiObj code. `UiLayoutDraw(texlists, parts, count, pos, z, ...)` draws
`count` layout parts (walking backwards) at `pos` plus each part's offset; `UiLayoutDrawPart` draws
one. A part is 0x14 bytes: `u16 bank`, `u16 sprite`, `f32 x, y, z`, `u16 texlist`,
`u16 flags`; the sprite comes from a bank in `lbl_803082D0` (loaded from the menu's files, so
sprite sizes aren't in the DOL). `UiSpriteDraw` draws a sprite's pieces as textured quads
(`fn_801C4F24` builds the vertices, `fn_80297DC8` sets the texture, `fn_80291064` draws), with a
draw state pushed around it. `UiSpriteDrawEx` and the `SpriteObjDraw*` family are the same with
flags (bit 0: the polygon mode, bit 2: an attribute bit, bit 1: additive blending, bit 3: one colour
for every piece), an origin, or a scale and UV flip (`SpriteQuadBuildScaled`, `SpriteQuadSetUV`).
`UiDrawNumber` draws a number of up to 10 digits from digit sprites, `UiDrawNumberText` as text.
`UiSpritesLoad` / `UiSpritesFree` load the menu's sprite banks into `menu_sprites`;
`Ui2DBegin` / `Ui2DEnd` bracket 2D drawing. The camp menu's panels draw their frames through `CampPanelDrawFrame`
-> `fn_801D49E4` / `fn_801D5210` -> `fn_801D4A2C` -> `fn_80291064`.

### UI objects

Every menu element embeds a `UiObj` (`include/game/uiobj.h`): position, target, per-frame step,
a "raise" offset and alpha for the highlight, frames left, a start delay, a command and a sound.

- `UiObjMoveTo(obj, frames, se, x, y)` (and the `X` / `Y` / `XIfChanged` variants) set the target
  and step = (target - position) / frames. Moves are linear.
- `UiObjSetCommand(obj, cmd, delay)` starts a sequence that `UiObjUpdate` runs each frame:
  5 raise, sound, move, lower; 10 lower, sound, move, raise; 15 sound, move; 20 / 21 lower / raise;
  24 / 25 the same without alpha; 26 lower then 15. "Raised" means offset (12, 4) and alpha 1.0,
  "lowered" (0, 0) and 0.7, stepped by 4 px (and 4/3) and 0.1 per frame.
- `UiObjFinish` snaps to the end of the running command (pressing A or B mid-slide).
- `MenuPartsBusy` / `MenuPartsFinish` / `MenuPartFree` work on the 19-entry part table at
  `+0x1F8` of the save/load (and shop) screen work.

The menu sound ids go through `menu_se_table` (27 entries of bank and id) to `SePlay`;
`MenuPlaySe` is the out-of-line version and `UiObjUpdate` has it inlined. The table's id is a `u8`
and `SePlay` takes `s8` arguments (it sign-extends them itself); converting one to the other is what
gives the original's `lbz r0` / `extsb r5, r0`.

Screens
-------

### Camp (pause) menu

`CampMenuCreate` (from the field) starts `CampMenuTask`, which on open creates every panel at once
(`CampMenuCreatePanels`, up to 157 panel tasks, kept in `camp_work + 0x10 + 4 * id`) and keeps them
until the menu closes. `camp_screen` (0..19) picks the screen function from `camp_screen_funcs`
(`CampMenuRunScreen`); each screen is a switch on its own state word at
`camp_work + 0x2F4 + 4 * screen`. A screen's entry calls `CampMenuHideAllPanels` (finish every
panel's UiObj, clear every panel's visible flag at work+0), then marks its own panels visible and
slides them in. Panel tasks draw whenever their visible flag is set, wherever their x is.

Panels sit in two columns at x = -8 and x = 328, rows at y = 61 + 64 * i; the help window sits at
(24, 384). Hidden panels are moved 340 px out, to x = -348 or 668 (help window: (632, 480)), and
stay visible there. Each screen has its own copies of these constants in `.sdata2`.

The party status screen (screen 3, `CampScreenStatus`) has three pages of rows (panel slots
0x23-0x26, 0x27-0x2B, 0x2C-0x31), and marks all three visible. On Left/Right, `CampStatusInput`
slides the new page 668 -> 328 (command 5, 6 frames) and the old one 328 -> 668 (command 10). So the
pages that aren't showing are drawn every frame at x = 668 and beyond.

### Save and load

Save (from a save point, `SaveLoadOpenSave`) and load (title screen Continue, `SaveLoadOpenLoad`)
are one module, `0x8019E248`-`0x801A6BDC`, plus the memory card driver `w_memdrv.c`
(`0x801A2500`-`0x801A4A00`). `SaveLoadTask` steps a 33-state table (`lbl_802EBD30`). Every piece is
a part task with a 0x6C-byte UiObj-based widget; `SaveLoadCreateParts` creates and slides them in,
`SaveLoadSlideAllOut` parks them.

| Part | Parked | On screen |
|---|---|---|
| Header ("Save" / "Load"), card slot tabs | x = -340 | x = -8 |
| Card slot cursor (`SaveLoadCursorCreate` / `SaveLoadCursorDraw`), a bar about 280 px wide | (-330, 160) | x = 160 |
| Yes / No windows | x = -240 | x = -8 |
| File windows (`lbl_802B690C`) | x = 676 | x = 336 |
| Message window | (640, 480) | (24, 384) |

The constants are in `.sdata2` (`lbl_8034B63C`-`lbl_8034B6E4`, `lbl_8034B768`, `lbl_8034B780`).

The task's step is `+0x19` (dispatched through `lbl_802EBD30`), its work (0x270 bytes) `+0x24`.
Traced live in the recomp loading a save from the title (2026-10-11): step 4 waits on the card slot
(Slot A / B), step 9 on the file list (cursor work `+0x05`, file 1 = 0), step 15 on "Load this file.
Is this ok?" (cursor work `+0x08`, 0 = Yes), step 19 loads; the result goes to `lbl_803473C4`
(0 running, 1 loaded, 2 cancelled), which the title's Continue task waits on. A closed load screen
leaves its task idle on step 32. The title menu (New Game / Continue) is a task running
`fn_801D8DBC` (waits on step 5, cursor work `+0x01`, 1 = Continue, the default when a save exists);
choosing Continue switches the same task to `fn_801D8B94`, which calls `SaveLoadOpenLoad` and waits.
Tasks are heap blocks: a 0x20-byte header (`[0]` the task's address, `[4]` size, `[8]` 0,
`[0xC]` 0xFFFFFFFF), then the task (function pointer at `+0`).
The backdrop (`fn_801A4B40`) tiles 64 px squares from x = 0 to 640 only.

### Loading a save without the load screen

Traced 2026-10-12 for the recomp's Continue (`patches/game/autoload.c` there).

**Card files.** Card A's saves are `SA_LEGENDS.000` to `.006` (7 at most; the load screen's list shows
them as #01-#07), 0x6000 bytes (3 blocks) each: header text, banner and icon up to 0x1440, then the
save payload P (0x3200 bytes). P starts with the version string `"EA_LEGEND v1.01"` (`0x802EBDD0`) and
ends with a 32-bit XOR of its first 0x31FC bytes at P+0x31FC (`fn_801A4684`). P+0x10 holds
`lbl_8030B7F4` (0x16A0, party / items / flags), P+0x16B0 the map (`lbl_80311AC0`), P+0x16E8..0x171C
positions, P+0x2370 `lbl_80310B3C` (0xD58, event flags), P+0x30C8 `lbl_80310A1C` (0x120); P+0x31E8..
the list preview (save point, chapter, a 10-byte stamp from `lbl_80308198`).

**The load path through the load screen** (steps of `lbl_802EBD30`): 0-3 open and create the parts,
4 slot, 5-8 mount and scan (step 6 starts the list task `fn_801A343C` / `fn_801A2D60`, which reads every
file and fills 7 entries at work+0x20+i*0x2C: status 0 empty, 1 good, 2 bad XOR, 4 wrong version),
9 file list, 14-15 "Is this ok?", **17** `fn_8019F730` calls `fn_801A4070`, **18** `fn_8019F44C` polls
and applies, 19 and 28-32 close; **32** `fn_8019E294` writes the result `lbl_803473C4` (1 loaded,
2 not) and clears bit 31 of `lbl_80310B3C`+0x84 after a load.

- `fn_801A4070(task)`: builds `"SA_LEGENDS" + ".%03d"` from work+7, allocates a 0x6000 buffer (its
  descriptor `0x803081A4`, pointer at work+0x258), mounts the slot in work+4 synchronously
  (`fn_801A2500`: a 0xA000 work area in `lbl_8034718C[slot]`, `CARDMountAsync` + `CARDCheckExAsync`,
  waited), `CARDOpen`s the file (`0x80308164`) and starts `CARDReadAsync` of 0x6000. 0 if the mount or
  open failed.
- `fn_801A3A10(slot, task)`: `CARDGetResultCode`: -1 busy, 0 done (and then `CARDClose`,
  `CARDUnmount`, the mount work freed), else a CARD error (nothing closed: `fn_801A372C` unmounts both
  slots and frees their work areas).
- `fn_801A4354(P)`: copies the payload into the game's data (above), resets the names from the ROM
  tables, sets the positions, then `fn_801CAE98` (clears transient flags), `fn_801EF7E0` (party
  totals), `fn_8021B2B4`, `lbl_803475D4 = 1`, `fn_801F7B04(20000)`.
- `fn_801A41C0(desc)` frees the buffer.

Both card functions read only the task's work (+0x24): +1 = 1 (load; 0 = save), +4 slot, +7 file
index. So a load needs no load screen: a 0x28-byte task whose +0x24 is a zeroed 0x270 work with those
three bytes, `fn_801A4070`, `fn_801A3A10` each frame until it isn't -1, the XOR (and the version, as the
list does), `fn_801A4354`, `fn_801A41C0`, then what step 32 does.

**Starting the game from it.** The title (mode 3, `fn_80228A20`, called from `0x801DC350`) runs a state
machine on `lbl_80311AD4`[3] through `lbl_802F91AC`: 0 init, 1 waits for the font, then the intro
(7 / 8: field scenes, mode 6, `fn_8022A29C` / `fn_8022A25C`) or, with `lbl_8034782C` set (after the
intro has played once), 9 the title proper; 10-13 "Press Start" and the menu (task `fn_801D8DBC`); the
menu's Continue sets `lbl_80347634` (`fn_801D71BC(1)`, Z counts as Start) and 16 starts the Continue task
(`fn_801D8B2C` / `fn_801D8B94`: `SaveLoadOpenLoad(.., 1)`, waits for `lbl_803473C4`); 17
(`fn_80228AD4`) then sets state 0x12 (an empty state) and `fn_801DBE6C(6)` (mode 6, the field, which
starts from the loaded data), or goes back to 9 when nothing was loaded. The recomp's direct load runs
in state 1 once the font is ready and ends the same way.

**The logos also load the resident files** (found 2026-10-17, after the direct load had shipped
without this). On a cold boot state 1 goes to the logos first: 2 (`fn_8022A548`, logo textures and
fade colours), 3 and 4 (`fn_8022A46C`, `fn_8022A38C`), then 5 and 6 back to 1. State 4 calls
`fn_8022A854(&lbl_80347828)` every frame and leaves only when it returns 1: a state machine that
checks the table `lbl_803165C8` (16 entries of 0x20 bytes, 0x204 bytes summed into `lbl_80346860`),
and if the sum is wrong clears it, `DVDChangeDir("/")`, reads the 16 files of `lbl_802F91F8` one per
step (`fn_801CC67C` / `fn_801CC5BC`, the disc error screen `fn_801D168C` / `fn_801D150C` meanwhile),
copies each to ARAM from base + 0x800000 (`ARQPostRequest`, waits for its callback `fn_8022AE88`),
records it in the table (+0x10 / +0x14 / +0x18 / +0x1C), and at the end stores the sum: state 5,
returns 1. `fn_801DB1A4(i)` looks entry i up through `fn_8022AE04` (NULL when the sum is wrong), and
the battle's loading (`fn_8000A118` state 3 -> `fn_801D67DC`) takes entries 0 and 3 and reads
`+4` from them unchecked: skip the logos and the first battle reads `0x00000004`. On a normal boot the
table is filled 5-15 s after power on. The European `fn_8022A854` (`0x8022D944`, 0x44C bytes) builds
the names of entries 0 and 3 from the text language (`fn_801DD188`); otherwise the same.

### Shops

The shop screens (around `0x801BE000`-`0x801C2FA0`; "Wshop" strings) use the same widgets and park
windows at x = 648 and x = -260.

### Battle and field HUD

| Function | What | Position |
|---|---|---|
| `BattleHudDraw` (task) | the battle HUD | |
| `BattleLabelPlace` | name label at a combatant's projected point | x clamped to [0, 544] (640 minus the 96 px label) |
| `BattleIconColumnDraw` | status icon column (`stsicon.mld`) | x 598..630, y 74 + 40 * i: right edge |
| `fn_80159610` | the same column in ship battles | x 598 |
| `FieldPartyStatusDraw` | field party status | icons x 598..630, labels 502..566: right edge |
| `MessageWindowDraw` | the message window (one per frame, `lbl_80346E60`) | band x 0..640 (full width), next-page arrow at window x + 576 |
| `ScreenFadeDraw` | script fade, a 640 x 480 colour quad | full screen, drawn through Ninja's own primitive (`fn_8028A0F4`); state at `lbl_8030CEA0 + 0xC5C` |
| `ScreenWipeDraw` | screen grab drawn back; `fn_8011B6E0` slides it by +-640 or +-480 for wipe transitions | full screen |

Found later with the recomp's deep projection trace (2026-10-10; draw tasks, all through the sprite path
`fn_801D5DD8` -> `fn_80005D98`): the battle party status panels `fn_80022F74`, the command wheel
`fn_80025624`, the wheel's lists (S-move, Magic, Item) `fn_800240EC`, the SP gauge `fn_80027C04` (it reads the Spirit points from the battle data, `lbl_80347390` +0x6 max and
+0xA current; [qol_cheats.md](qol_cheats.md) *Battle records*); on the world
map the altitude gauge `fn_8016B434` and the compass `fn_8016C204`; the dungeon minimap is drawn by
`fn_800E23B0` through `fn_800E340C`, `fn_800E3058`, `fn_800E2D0C` and `fn_801E4F88`. The recomp's widescreen
patch moves these to the wide edges, or to the edges of a narrower centred area the player picks (recomp
NOTES.md *Widescreen HUD at the edges* and *HUD placement*). The meter and compass are drawn through the
recorded display lists like the rest ([frame_loop.md](frame_loop.md)): while the world map's menu is
open they're replayed, so a change of the 2D projection then shows only once it closes.

Battle HUD panel per unit (2026-10-11, while checking the recomp's Invincible): `fn_8002969C(slot)` creates a
`BattleHudDraw` task and keeps its data block in `lbl_80302AB0[slot]`: state +0x12, HP shown +0x20 (float,
animated by the step +0x24), HP it heads for +0x28, max +0x2C, bar fraction +0x1E4. `BattleHudDraw` follows the
unit's HP (`lbl_80309DE4[slot]` +0x14) only in panel states 3-8; `fn_8002942C(slot, 2)` syncs +0x28 / +0x20 to
it at once. During command input the party status box changed neither when these fields nor when the unit's HP
were written; it shows the turn's starting HP / MP until the round plays out (its source is still unknown;
[qol_cheats.md](qol_cheats.md) *Battle records*).

### Title screen

Traced in the recomp (every projection load with its callers, 2026-10-07): the title draws its 2D as
`main`'s full-screen background quad, one `fn_80290A60` call from `fn_801D129C`, and four sprite parts
per frame from `fn_801D5DD8` (a multi-part sprite at a position: parts from a layout list, colour and
alpha from `njSetConstantMaterial`) through `fn_80005D98`, a generic rotated sprite quad (`njSin` /
`njCos`, then `fn_80291064`) with about 20 callers. The clouds are 3D (Ninja model draws through
`fn_80288DE4`); the lower layer is about 120 alike draws, one fewer every second or two as it scrolls.

Off-screen parking and widescreen
---------------------------------

With the 2D layer squeezed into the middle of a 16:9 picture (widescreen.md), 2D x from about -149
to 789 is visible instead of 0 to 640. The menus' parking spots fall inside that range:

| Parked x | Who |
|---|---|
| -348 / 668 | camp menu panels (left / right column), incl. the status screen's inactive pages |
| -340 / -330 / -240 | save/load header and tabs / card slot cursor / Yes-No windows |
| 676 / 640 | save/load file windows / message window |
| -260 / 648 | shop windows |
| 632 | camp menu help window |

Everything is parked by moving a UiObj, so a fix can work at that level instead of clipping all 2D:
skip drawing an element whose UiObj is idle (`cmd == 0`) at a parked position, or rewrite the
parking constants further out (the slides keep their frame counts, since the step is computed from
the distance). The right-edge HUD (icon columns, party status) stays inside the 4:3 area unless it
is moved out to the wide edge on purpose.

The recomp's patch clips squeezed 2D to 4:3 with `GXSetScissor` instead, written on every projection
load ([widescreen.md](widescreen.md#ui-parked-off-screen)). An earlier version that only wrote the
scissor when the clip turned on or off cut the 3D scene down to 4:3 in places (the Valuan ship's red
alert room), because the scene is recorded into display lists ([frame_loop.md](frame_loop.md)) and the
CPU's order of projection loads isn't the GPU's. With the scissor right, the UiObj-level fix above isn't
needed; it remains an option if the clip ever hides something that should show.

Open
----

- Not matching yet: `UiDrawNumber` (register allocation in its unrolled divide/modulo chain),
  `UiLayoutDraw` / `UiLayoutDrawPart` (6 lines of argument scheduling), `UiSpriteDraw` (the vertex
  buffer address in a callee-saved register vs the hoisted int-to-float constant), and in
  `text.c` `FontFindGlyph`, `TextNodeNew` / `TextNodeNewN` (the 0x8197 fallback constant is
  hoisted out of the copy loop; the original keeps it in its branch), `TextPrintNumber` and
  `TextReadChar` (a register reused for zero, an extra mask).
- Prototypes: the int/float order of parameters doesn't change the PowerPC calling convention, so
  it's free to choose, and it changes scheduling: `UiSpriteDrawEx` only matches with its floats
  before `texlist` and `flags`.
- The battle-entry shatters are 3D: `fn_802297C4` (spinning card) and `fn_80097CA4` (falling
  triangles, from `fn_80101828`); see [widescreen.md](widescreen.md#full-screen-2d).
- The shop module's layout; `fn_802267AC` / `fn_802268E8` (task create).
