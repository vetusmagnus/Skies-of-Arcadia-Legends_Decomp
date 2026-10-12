Cameras, and what a modern camera would take
============================================

Research for a right-stick (C-stick) camera in the recomp, 2026-10-11. Controls were checked by
pressing each input from a savestate on the Windows build (`tools/button-probe-win.sh` in the recomp)
and the camera state by memory dumps and pokes through the automation interface.

The camera manager
------------------

`lbl_80311970` (0xF0 bytes) is the game camera the view is built from, updated by `fn_8022D384`
(jump table `0x802F9330` on the mode at +0):

| Offset | What |
|---|---|
| +0x0 | mode (0..10). Field and world map run mode 2: copy the eye and angles from two pointers |
| +0x8 / +0xC | pointers to the eye position (3 floats) and angles (pitch, yaw, roll as ints, 0x10000 = 360 deg) |
| +0x10..+0x18 | eye position (written every frame, so pokes don't stick) |
| +0x1C / +0x20 / +0x24 | pitch / yaw / roll |
| +0x7C..+0x84 | view direction |
| +0x88 | field of view, `0x2AAA` = 60 deg |
| +0x90..+0xA0 | a button table: A, B, L, R, Y |
| +0xEC | the C-stick X value the field camera used last |

In mode 2 both pointers lead into one object, `0x80302F18` (eye at +0x7C, angles at +0x88), which is
shared by the field and the world map: their own code fills it.

Field (towns, dungeons, ship interiors; game mode 6)
---------------------------------------------------

Controls on foot (state `03b-valuan-ship-thirdperson`): stick moves, C-stick X and the L/R triggers
turn the camera around Vyse (`fn_80090DBC`: rate = C-stick X / -44 * 512 per frame, triggers / +-150;
L+R together recentres; a flag at `lbl_80310B3C + 0x84` bit 3 inverts it), C-stick Y does nothing,
X = status, Y = first-person look (stick looks around), Z = minimap.

Camera object `0x80302F18` in that room: look-at +0x0C / +0x24 (Vyse, at head height 30), pitch base
+0x40 (`0xF7E9`, -11.4 deg), yaw +0x44, an offset preset +0x58 (35, 24, -35), eye/angle targets
+0x64..+0x74, output eye +0x7C and angles +0x88 / +0x8C. The eye is `look-at + R(yaw) * (49.5, 24)`:
distance and height are fixed, so pitch is a constant. Poking the pitch (+0x40 / +0x70) tilts the
view but the eye doesn't move (the camera looks at the floor); poking the offset does nothing. The
per-room camera type is the halfword at +0x8 (2 here; `fn_80095910` dispatches 0..3 to
`fn_80095220`, `fn_80094E50`, `fn_80091040` / `fn_80094800`, `fn_80094B20`).

World map (game mode 6, map ID `lbl_80311AC0 + 4` = 0x63; 0x65 in the Valuan ship)
--------------------------------------------------------------------------------

Controls (state `10-worldmap-android`): stick steers, C-stick Y climbs /
descends, and so do the L/R triggers, C-stick X does nothing, X = status, Y = map, Z = a menu (Map /
To Bridge / Save), A and B: no clear effect from a 2 s hold. The camera is a chase camera behind the
ship, filled into the same object: look-at +0x0C (the ship, ~15 units from the eye), eye +0x7C.

Battle (game mode 7; ground and the world map's deck battles)
------------------------------------------------------------

`fn_800125A8` (command input): C-stick X and the L/R triggers orbit around the acting character (close
enough to pass through it), C-stick Y does nothing, X switches what the camera/panels show. Start skips
scripted sequences. Ship-versus-ship battles run inside field mode 6 and weren't checked.

Other things found on the way
-----------------------------

- Soft reset: B + X + Start held with the C-stick centred for 500 ms (`fn_801DBF94`, `lbl_803476D0`)
  -> `OSResetSystem`. A recomp menu combo must not use it.
- Mode 3 code (`fn_80228A20`, title) makes Z and Start equivalent (`lbl_80347634`).

What a modern camera would take
-------------------------------

One hook covers the field and the world map: in `fn_8022D384`'s mode 2 (`0x8022D424`), after it copies
the eye and angles, rotate the eye around a pivot by a player orbit (yaw, pitch) and optionally scale
the distance, and add the same angles. Pivot: the object's look-at (+0x0C / +0x24), which is Vyse on
foot and the ship on the world map. Written as game-patch C like `widescreen.c`, reading the C-stick
from the pad block (`lbl_80311C4C + 0x18 / 0x1A`), with its state in a config block.

| Mode | Today | With the hook |
|---|---|---|
| Field | yaw on C-stick X / triggers, fixed pitch and distance | C-stick Y adds pitch (and zoom if wanted); the game's yaw stays |
| World map | fixed chase cam; C-stick Y and triggers both change altitude | C-stick orbits the ship (yaw + pitch); altitude stays on the triggers. The recomp's pad filter withholds C-stick Y from the game there (mode 6 + map 0x63), so nothing in the game has to change; face buttons could take altitude too if A/B turn out free |
| Battle | orbit on C-stick X / triggers, X switches views | already player-controlled; C-stick Y pitch could be added the same way, but the battle camera is a different manager mode |
| First-person look (Y on foot) | stick looks | already free look |

Risks: no camera collision anywhere (the field distance is short and fixed, so a pitched or longer
camera can go through walls and ceilings in small rooms; clamp pitch, keep the game's distance indoors);
areas built for the low fixed view may show unfinished geometry from above; the world map's cloud
layers and fog are tuned for the chase view. The recomp's interpolation and widescreen work on the
final matrices, so they need nothing.

Implemented in the recomp (2026-10-11)
--------------------------------------

`patches/game/camera.c` (in `widescreen.json`): `cam_view` replaces the call to `fn_8022D1F8` at
`0x8022D910` (the camera shake, called with the view's eye `lbl_803119E0`, the manager and the angle
buffer just before the view direction and matrix are built). In mode 2 with the field camera object
as the source, it puts the eye at `look-at - distance * zoom * forward(yaw + yaw_off, pitch +
pitch_off)` and writes the angles to match; the camera object itself is never written, so the game's
camera logic and camera-relative movement are untouched. The offsets come from `cam_input`
(`0x80002EC0`, 'CAMC'), written by the runtime's pad filter (`VideoCommon/SkiesMenu.cpp`, namespace
`camera`): hold Z, C-stick up/down tilts, the triggers zoom (R out, L in), and on the world map the
C-stick also turns the camera around the ship and eases back when let go.

Limits. In towns and dungeons the camera stays between the game's own camera and Vyse: no higher than
the game's eye (`cam_input.rise`; tilting further down brings it closer instead), no further than the
game's distance (zoom 0.5-1.0), pitch -40 to -1 degrees. A first try with the eye allowed 10 units
higher went through the ceiling of the Valuan ship's cabin, and longer distances can go through the
wall behind: the game has no camera collision. World map (open sky): pitch -35 to +25, zoom 0.6-2.0.
First-person look and battles aren't affected (the manager isn't following the field camera object
there). `[Skies] CameraControl` (menu: Camera) turns it off. Checked on Windows with
`tools/camera-test-win.sh` (world map and the ship cabin, 2026-10-11).
