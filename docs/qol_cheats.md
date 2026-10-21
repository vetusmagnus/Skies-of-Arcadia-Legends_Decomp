Quality-of-life cheats: encounters, EXP, battle speed, invincibility
=====================================================================

Research for Pixel-Remaster-style options in the recomp (2026-10-11), all implemented there since (see
*Implemented in the recomp* at the end; the hook sites first proposed below in the middle of functions
were replaced by whole-call hooks). Addresses are GEAE8P (USA).
Starting points were the published US Action Replay codes (almarsguides.com), decrypted with
Dolphin's `Core/Cheats/ARDecrypt.cpp`:

| AR code (as published) | Decrypted | What it really does |
|---|---|---|
| No Random Battles | `0430B7AC 00000000` | zeroes the word holding the encounter-rate byte `0x8030B7AD` (and its neighbours) |
| Battles Happen Faster | `040C200C 38000001` | replaces `lfs f0, 14400.0` in the encounter check with `li r0, 1`: f0 keeps 0.0, the rate divides by zero, encounters come at once. It's an encounter-rate code, not battle speed |
| Max Experience (Vyse / Aika / Fina) | `0430B818` / `0430B874` / `0430B8D0` `05F5E0FF` | EXP of party slot 0 / 1 / 2 |

Game mode `lbl_803475CC` (dispatched by `fn_801DC288`, jump table `0x802F6660`, set by
`fn_801DBE6C`): 3, 6 = field (`fn_80101828`), 7 = battle (`fn_8000A118`), 9. Read from savestates 03
and 02, and from a random encounter on the world map (`16-deck-battle-ws10`): those are deck battles,
mode 7 like ground battles. Ship-versus-ship battles run inside field mode 6, on maps 500-599 (see
*Ship battles* below).

Random encounters
-----------------

`fn_800C1C24` runs every frame in the field. With `steps` = `lbl_80346D28` (frames since the last
battle) and `rate` = the area's u16 at `-0x82` of its 0x84-byte entry in the table at `lbl_803474BC`:

    chance = 0.5 * max(0, (steps + 1 - 30) * rate / 14400)          // 0x800C1FC8..0x800C2078
    if (s8 modifier = 0x8030B7AD) != -1: chance *= modifier / 50     // set by event scripts (0x801EEC44)
    roll   = rand() * 100 / 32768 - 50, wrapped into [0, 100)
    if steps >= 480: roll /= steps * 6 / 480                          // the chance climbs after 16 s
    battle if roll < chance                                            // 0x800C2110

First idea for a factor: `0x800C2074 lfs f0, 0.5` / `0x800C2078 fmuls f31, f31, f0`, the `lfs` replaced
with a `bl` to a stub loading `0.5 * factor`. Built instead (whole call): the roll's `rand` call at
`0x800C207C` returns the rand whose roll is roll / factor, which is exact; Off also clears `steps`,
because after 480 frames the shrinking roll would still trigger a battle. Don't write `0x8030B7AD`:
it's game state the scripts set, and it's saved with the game.

EXP
---

Party records: `lbl_8030B7F4`, 0x5C bytes each, EXP at +0x24; gold at `0x8030B7F4 + 0x34C`, capped at
99,999,999. All EXP goes through `fn_801F2A34(slot, new_exp)` (cap and level-ups). Battle awards:

| Battle | Results function | EXP source | Share |
|---|---|---|---|
| Ground | `fn_8006F4B0` (state machine on `lbl_80347338`) | `lwz r8, 0x30(r3)` at `0x8006F5E8`, r3 = `lbl_80347390` | ceil(EXP / members standing) -> `lbl_803082F8+0`, added at `0x8006F9E4` |
| Ship | `fn_80144E60` (called at `0x8015C6B4`) | `lwz r8, 0x18(r3)` at `0x80144F2C`, r3 = `lbl_8034727C` | EXP / r9 + 1 -> `lbl_803082F8+0`, added at `0x80145114` |

First idea for a factor: replace each `lwz r8` with a `bl` to a stub that loads and scales. Built
instead (whole call): the battle data itself is scaled once per battle right before the results read
it (ground: the member count call at `0x8006F5B8`, the first in the reward step; ship: the call of
`fn_80144E60` at `0x8015C6B4`), so EXP, gold and magic EXP and the results screen all agree.

Ground battle data (`lbl_80347390`), checked in the first battle (`0x80EC0640`): +0x01 = magic EXP
(s8, 2), +0x30 = EXP (3), +0x34 = gold (5).

| Reward | Ground | Ship | Lands in |
|---|---|---|---|
| Gold | `lwz r8, 0x34(r3)` at `0x8006F614` -> results +8, added to `0x8030BB40` (cap 99,999,999) | `lwz r8, 0x1c(r3)` at `0x80144F50` | `lbl_8030B7F4 + 0x34C` |
| Magic EXP | `lbz r6, 0x1(r5)` at `0x8006FB1C`, `extsb r6` at `0x8006FB28`; the shown number is `lbz r4, 0x1(r3)` / `extsb r4` at `0x8006F60C` -> results +4 | none (results +4 = 0) | member +0x44 + colour * 4 (u32, cap 9999 in `fn_801F2ED4`); colour = battle `0x100`; one member gets it twice (`0x8006FB30`) |

(First idea for magic EXP: a stub on the two `extsb`; built: the s8 in the battle data is scaled, capped
at 127.) Magic levels are member +0x34..+0x39; the second per-member
record (`lbl_8030B4D4`, 0x78 bytes each) mirrors stats. Not battle awards, leave alone:
`fn_801F3024` (recompute) and `fn_801F3CB0` (a joining member's starting EXP).

Battle speed
------------

The logic is a fixed step per frame (`frame_loop.md`); `fn_801DC420` holds a frame to two retraces:
the loop at `0x801DC490..0x801DC4A8` (at least one retrace since the frame began), then
`VIWaitForRetrace` at `0x801DC4D8`. Skipping the first wait when the mode is 7 runs battles at 2x;
skipping `VIWaitForRetrace` on some frames too gives 3x/4x with dropped frames (built: the two calls
were wrapped, `qol_retrace_count` and `qol_wait_retrace`; since ws15 the first is done by moving
main's frame-start mark `lbl_8034768C`, which only that loop reads, from `qol_frame` before
`fn_801DC420` runs: the hook inside the polling loop caught savestates in patch code). Music is driven by MusyX from the audio
interrupt, not the frame loop, so it should keep its tempo (not listened to yet). Costs: the host runs
2x-4x the battle logic: a desktop PC holds 4x at full speed, the Retroid Pocket 5 tops out near 2.5x
(3x / 4x ran at 0.85x / 0.65x emulation, so the recomp steps such a battle down to 2x); the recomp's 60
fps interpolation stands down while a battle runs fast (real frames already come at 60). The toggle
(a Z tap in battle) lives in the runtime's pad filter (`VideoCommon/SkiesMenu.cpp`, CPU thread, mode
read from `0x803475CC`).

Buttons in ground and deck battles (game pad block `lbl_80311C4C`, 0x1C per pad: held +0, pressed +8,
released +0xC; read through the pointer table `lbl_80311A60`): A/B/D-pad/stick drive the menus; L, R
(digital and analog), the C-stick and X move the camera (`fn_800125A8`); Start skips scripted battle
sequences (`fn_80037AF0`). Y is only read by field and ship code (`fn_800D1630`, `fn_800EE450`,
`fn_80119AF4`, `fn_80141610`). Z is never read as a button: the only use is `lbl_80347634`, which
makes Z and Start equivalent and is turned on by `fn_80228A20` (mode 3). Pressing Y, Z, Start and B at
the command wheel (state 02, `tools/button-probe-win.sh` in the recomp) changed nothing. So a Z tap is
free for the speed toggle in battle (Z+Start stays the settings menu). Ship battles: not checked.

**Fixed (2026-10-21), not the game's doing:** the freeze came from the recomp's CPU core under the
emulated-CPU overclock of 3x / 4x (1.5 / 2.0). Every spell and S-move plays one stream (*Spells and
special attacks* below) and its action waits for the stream's end; with the overclock at 1.5 or more the
stream stalled (MusyX's `streamInfo` at `0x8032C730` never saw the play position move, so the game's
refill callback `fn_802163FC` wasn't called again) and the battle waited forever. Dolphin's JIT with the
same overclock played it: the recomp advanced the guest timebase by overclocked cycles inside a native
burst (recomp `patches/recompcore-overclock-timebase.patch`, development notes *A battle can freeze*).
The user's frozen state holds Cutlass Fury's stream (`KO0036`) stuck in both channels. Earlier notes:

**Open (2026-10-11):** changing the speed while a round plays out can freeze the battle for good: the
round stops with a damage number on screen, every battle task stays on its step, no DVD read is pending,
and the freeze survives a savestate reload. Seen on the Retroid (Antonio fight, several Z taps plus the
recomp's step-down from 3x / 4x to 2x) and reproduced in the recomp on Windows in 5 of 12 rounds with
mid-round speed changes, with Invincible on or off. The logic itself is a fixed step per frame, so
the suspects are what a speed change touches outside it: the emulated-CPU overclock used at 3x / 4x and
the recomp's frame interpolation (stood down at speed). Recomp NOTES.md *Known issues* has the states and
the method.

Spells and special attacks
--------------------------

Measured 2026-10-21 (recomp, Windows, audio dumps): a spell's or an S-move's sound is **one pre-mixed
stereo stream** from the disc, `SOUND/KO00NN_L.dsp` / `_R.dsp` (NN = the skill id: 0-35 the 36 spells,
2.5-13 s; 36-59 the S-moves, 10-33 s; 62-67 short ones), voice and effects together: no `SePlay`
happens while it plays. The action's last step waits for the stream's end. An enemy special plays a
voice stream (`B702NNNN`, `fn_8003F890`). So with the end-of-frame waits skipped the animation ends
early and the battle sits until the sound is done (Cutlass Fury, 11.6 s: animation 10.1 s at 1x,
5.0 s at 2x, 2.5 s at 4x).

What runs them:

| Address | What |
|---|---|
| `lbl_80309174` | 12 command records, 0x20 each (party 0-3, enemies 4-11): +0 command type, +4 target, +6 skill / item id, +0xD a flag cleared at the action's start |
| `lbl_80309700` | 12 action task pointers; the task's first word is the function it runs, +0x19 its step, +0x24 -> work (+0 the unit) |
| `lbl_80309730` | 12 x 0x10: +0 the unit's current motion (set by `fn_80081168` / `fn_800811E4`), +4 a unit index (compared with the acting unit), +7 the skill id |
| `lbl_80347334` | the unit acting (s8) |
| `fn_80086C68` | the party's dispatcher, by command type: 0 `fn_80085ADC`, 1 / 2 (magic / S-move) `fn_80085064`, 3 attack `fn_80086308` (+6 != 0: `fn_80085CE0`), 4 `fn_80085C88`, 5 `fn_80084A08`, 6 `fn_800858B8`, 8 `fn_80084E38` / `fn_80084C78` |
| `fn_8008B9E0` | the enemies' dispatcher: 1 and 0xC `fn_80087074`, 3 `fn_80087F6C` / `fn_80087844`, 4 `fn_80088ABC`, 6 `fn_80088B14`; every enemy action ends in `fn_80087054` |
| `fn_8008A424` | enemy AI: a rule list at the unit record's +0x110 (+0x8A: kind, code, next); code 0x226 attack (type 3), 0x227 type 4, 0x228 type 6, 500+ magic (type 1, id = code - 500), others a special (type 0xC, id = code) |
| `lbl_802C4BF0` | the skill table, 0x30 per skill (magic 0-0x23, S-moves from 0x24; Cutlass Fury 0x24) |
| `lbl_803475A8` | the root task; the task list is linked through +4 |

The recomp's game patch ws27 plays these at normal speed: `qol_fast` is false while any unit's action
task runs `fn_80085064` or `fn_80087074` (`patches/game/qol.c`, issue #7). Ship battles: ws28, *Ship
battles* below.

Field speed
-----------

The same end-of-frame waits hold the field (game mode 6) to 30 frames a second: towns, dungeons, the
world map and every cutscene (the game has no movie files; its cutscenes are scripted field scenes, the
opening's included). Skipping them in mode 6 too speeds all of it up (recomp ws26, 2026-10-20: the
frontend sets bit 0x100 of `qol_input`'s speed word outside battle). Measured in the recomp on Windows
at 1x resolution: 2x = 60 game frames a second at full emulation speed in the opening cutscene, on the
Valuan ship and on the world map. A world map frame takes about a retrace of the emulated CPU's time
(like a ship battle's), so 3x there needs the CPU clocked at 2x (1.5x stayed at 60); it then reached
~88 game frames a second, the host's limit at 0.97x, and the ship's corridors and the opening
cutscene couldn't hold 90 either. On a Retroid Pocket 5 (Snapdragon 865) plain 2x ran at only
0.71x-0.85x emulation, so the recomp paces speeds in quarters (each frame takes 2, 1 or 0 retraces
from a budget, averaging 2 / speed) and that device settles at 1.5x on foot, 1.25x on the world map and
in cutscenes, at full emulation speed. Random encounters count frames, so at 2x they come twice as often
in real time but at the same distance travelled. Unlike battle, Z is the game's in the field (the
minimap on foot, the Map / To Bridge / Save menu on the world map), so the recomp switches the field
speed with Z+X.

Implemented in the recomp (2026-10-11)
--------------------------------------

`patches/game/qol.c` / `qol.S` (DOL ws12), all whole-call hooks: `qol_encounter_rand` at `0x800C207C`
returns the rand whose roll is roll * 100 / percent (exactly the chance times percent / 100; Off also
clears `lbl_80346D28` so the chance stays 0); `qol_ground_member` at `0x8006F5B8` (the member count
loop just before the rewards are read) scales the ground battle data's EXP / gold / magic EXP once per
battle; `qol_ship_results` at `0x8015C6B4` does the ship battle's EXP and gold; `qol_frame` (from
`ws_frame_end`, before `fn_801DC420`; `qol_retrace_count` at `0x801DC498` until ws14) and
`qol_wait_retrace` (`0x801DC4D8`) skip the end-of-frame waits in battle for 2x-4x.
The results screen shows the scaled numbers. Checked: first battle 3 / 10 / 2+4 (EXP / gold / magic
EXP) at Normal, 12 / 40 / 8+16 at 4x; encounters from the world-map state after 29 / 20 / 8 s at 1/4 /
Normal / 4x, none in 60 s Off; battles run 30 / 61 / 92 / 122 game frames per second at 1x-4x with the
emulation at 1.00x. Invincible (`qol_damage` around `fn_8002DC14`, its 13 calls and the handler table
entry, plus a per-frame refill; see the next section): the deck battle state's Vyse stays at 589/589
where the run without it is knocked out. The frontend side (menu rows, Z tap in battle for the speed,
L3 / R3 for Invincible read from the real controller, interpolation off at speed, the step-down when the
host can't keep up) is in the recomp's `VideoCommon/SkiesMenu.cpp`.

Battle records and invincibility
--------------------------------

`lbl_80309DE4` is the battle's unit table (party 0-3, then enemies): HP +0x14 and max +0x18 (s32),
MP +0xFE and max +0xFF (s8), status flags +0x1C (0x8000 = low HP, set by `fn_80010474` when HP is a
quarter of max or less). The Spirit gauge is in the battle data (`lbl_80347390`): max +0x6, current
+0x8 / +0xA (s16). `fn_8002DC14(action, target)` applies damage: HP -= action +0x8, clamped at 0, then
`fn_8002BC4C` and `fn_80010474`; it has 13 direct calls and is entry 0 of the action handler table
`lbl_802DBB10` (0x13C bytes). The healing effects (`fn_8002C51C`, `fn_8002C61C`, `fn_8002CBF8`,
`fn_8002DBA8`) add action +0x8 to HP (and +0xC to MP) clamped to max. The recomp's qol.c zeroes the
damage to the party and refills HP / MP / Spirit every battle frame.

**What the player sees (checked on Windows, 2026-10-11, deck battle state 16):** turning Invincible on while choosing
commands refills the unit records at once (and the SP gauge, which `fn_80027C04` reads live), but the party status box
keeps the HP / MP it showed when the turn began until the round plays out; after one round it reads full. Writing the
battle HUD panel (`lbl_80302AB0[slot]`, from `fn_8002969C`: HP shown +0x20 float, target +0x28, max +0x2C; the game's
own sync is `fn_8002942C(slot, 2)`) changed neither the digits nor the bar during command input, so that box isn't
redrawn from memory then. Knocked-out members (HP 0) are left alone, so they stay down with their MP as it was.

Ship battles
------------

Researched 2026-10-11 with a savestate made for it (the recomp's `tools/shipbattle-state-win.sh`).

**Entering one.** A ship battle is a field map numbered 500-599 (`a5xxa.mld`, script `me5xxa.sct`;
`me500a` is Baltor's Blackbeard, the first). `fn_8012A26C` (leaving a map) does the ship battle
teardown only when the map ID (`lbl_80311AC0 + 4`) is 500 or more; `fn_801D184C` tests 500-599 too.
A map change is a script name in `lbl_80305CF0` ("me500a.sct": `m`, `e`, three digits = map, a letter
= entry point) and field state 0xF in `lbl_80311AD4 + 0x18` (`0x80311AEC`), as `fn_80100270` does;
state 0xF runs `fn_80101494`, which tears the map down, parses the name into `lbl_80311AC0`
(`fn_801004C4`: +0 previous map, +4 map, +8 entry) and re-enters the field (mode 6). Setting state 0xC
instead (fade, then 0xD-0xF) hung the game. The field states (`fn_80101828`, jump table `0x802E471C`):
0 init, 8 running, 9-0xB leave for a battle (mode 7), 0xC-0xF leave for another map.

**The party's ship.** The save holds one ship record at `lbl_8030B7F4 + 0x1568` (`0x8030CD5C`):
+0 ship (-1 = none; 0 Little Jack, 2 Delphinus; names and base stats in `lbl_802D6740`, 0x64 each),
+2 name (0x11), +0x14 HP (s32), +0x18 five weapon slots (s16 item IDs, -1 empty; ship weapons are
0x190+ in `lbl_802D7E4C`, 0x24 each: 0x190 Main Cannon, 0x19A 3"Cannon). `fn_8021BD7C(ship)` sets it
(`fn_8021B91C` for ship 0); a game before the story hands out the Little Jack has -1, and a ship
battle entered then has an empty ship at 0 HP. The battle builds the party side in `lbl_803063F0`
(0x348, `fn_80135598` returns it): Spirit max +0x6, gauge +0x8, per-turn gain +0xC (s16; the turn's
start, `fn_801447A0`, adds +0xC to +0x8, capped at +0x6), crew entries at +0x1C6 (4 x 0x1C, from
`fn_80135290`: name, +0xB party record index, +0xC level, +0xD MP max, +0xE MP, copied from the record's
+0xE / +0xD), and the ship at +0x238 (`fn_80134E7C` from the record: name, +0x14 max HP, +0x18 HP
(s32), weapons at +0x60, 5 x 0x22). The enemy ships are at `lbl_80305FC0` (0x10C each, same layout).
The command input works from the Spirit the turn began with, so a gauge written during input shows
from the next turn on.

**The battle.** `fn_801453D0` allocates the ship battle data (0xAB4 bytes) into `lbl_8034727C`: +0x18
EXP, +0x1C gold (set from `lbl_802D6934` when the enemy sinks), +0x20 the party's ship, +0x24 the
enemy's, phases of 0x90 from +0x0 (+0x12C party heal, +0x130 damage to the party, +0x5AC enemy heal,
+0x5B0 damage to the enemy). `fn_8014419C(phase, side)` (one call, at `0x80144E3C` in `fn_80144CE4`)
applies a phase's HP changes for the side acting and then ends the battle as lost when the party's
ship is at 0. **The game frees the data after the battle but never clears `lbl_8034727C`**, so it isn't
a "ship battle running" test: the map number is. A ship battle frame costs about a full retrace of
emulated CPU time, so skipping the end-of-frame waits takes it to 60 frames per second (2x) and no
further; 3x and 4x need the emulated CPU clocked up (Dolphin's overclock: 4x reached 114 frames per
second at 3.0).

**In the recomp (ws14, 2026-10-11).** `qol_ship_phase` wraps `fn_8014419C` at `0x80144E3C` and zeroes
+0x130 for the enemy's side while invincible; the per-frame refill also fills the ship's HP, the Spirit
gauge and the crew's MP (entries and party records); battle speed counts ship battles as battle (mode 6
on map 500-599 with the data pointer set), and the frontend overclocks the emulated CPU by speed / 2 at
3x / 4x. Checked on Windows from the Baltor state: 30 / 59 / 92 / 116 game frames per second at 1x-4x;
Invincible keeps the Little Jack at 10000 (8140 after the same turn without it), Spirit and MP full
from the next turn; the battle won the normal way goes on to map 205 with 410 EXP / 300 gold at 100%
(Vyse 25 -> 231) and twice that at 200% (25 -> 436, +600 gold). Setting the enemy's HP by hand doesn't
sink it (the battle goes on, or restarts after the results): don't test the ending that way.

**How a turn plays (2026-10-21).** Researched from a random encounter reached by changing the map to
`me550a` from the Baltor state (the Black Pirates; maps 550+ are the sky's random ship battles, no
tutorial), recomp test build on Windows. Ship battles play no streams: every caller of the battle
streams (`KO%04dS%s` and `B702...` at `lbl_802AD328`, built in `fn_8003E464` / `fn_8003FF94`) is
ground battle code, and the only stream the ship code asks for (`fn_80155B78`, `/SOUND/f71000NN`) is
the debug sound test. Their spells and specials are sound effects on a timeline, so nothing waits for a
sound; at speed the effects just run behind the picture.

The command input fills the turn's phases; then the turn plays on a timeline of frames:

| Address | What |
|---|---|
| `lbl_803472E0` | the turn's frame (a float, counted from 0; 500 per phase) |
| `lbl_803472DC` | 1.0 while the turn plays, 0 at the command input (`fn_8015AA18` takes the input path then) |
| `lbl_803472A4` | the phase playing's record, 0x58 each: +0x0 index, +0x4 length (500), +0x8 first frame, then the windows `fn_8015BB58` steps through: +0x8..+0xC set-up (`fn_8015C1E4` works out both sides' actions), +0xC..+0x14 the side acting first, +0x14..+0x18 the turn-around, +0x18..end the side acting second. Phase 0: 0, 10, 70, 250, 310; phase 1: 500, 510, 570, 750, 810 |
| `lbl_803472B4` | the phase playing |
| `lbl_80306E38` | the phase's actions **in acting order**, 0x90 each: +0 count (s16), from +0x10 0x10 each: +0 kind, +1 side (0 the party, 1 the enemy), +2 crew member / enemy ship, +5 weapon slot, +8 id. `fn_8015C1E4` fills them through `fn_80144CE4(phase, 0)` and `(phase, 1)`, which ask `fn_80147CC8` who acts first (`lbl_80347064` = 1 when the enemy does) |
| `lbl_803063F0` + 0x298 | the party's weapons in battle, 0x22 each: name, +0x12 item id, +0x16 attack, +0x1A accuracy (0xFFFF: the S-Cannons). Slot 4 of the Little Jack held the Harpoon Cannon (0x1AE) |

Who acts first changes from turn to turn: the same save state gave the party's Sacri first in some runs
and the enemy's Focus first in others.

Action kinds, from the banner name `fn_80159D48` picks: 0 Flee, 3 Evasive Action, 4 a cannon (the
weapon's name), 5 magic (the skill table `lbl_802C4BF0`, id +8: Sacri 6), 1 a ship item
(`lbl_802D8A2C`, id - 0x1E0: bombs, repair kits), 2 a crew item (`lbl_802C7C34`, id - 0xF0), 6 Focus /
Taking Aim / Preparing Attack (id 0-2), 7 a crew member's special (`lbl_802D8E64`: Lawrence, Don,
Kirala, Polly...), 8 an enemy's action by id: 0 Awaiting Orders, 1 Target Lost, 2 Assessing Damage,
3 Hull Ram, 4 Red Ray, 5 Fist of Grendel, 6 Boulder Throw, 7 Stomp, 8 Flee. The S-Cannon fires a
weapon like any cannon (kind 4), so it's told by the weapon: Harpoon Cannon 0x1AE, MoonStone Cannon
0x1AF. It's offered only on a phase the turn bar marks "C!"; this battle's C! phases came at random
and none came up in the time tested, so the S-Cannon wasn't seen playing. The European and Japanese
code is the same (the European banner function differs only in its name tables).

**In the recomp (ws28, 2026-10-21).** `qol_fast` is false while the window playing (first side: record
0, second: record 1) has magic, a crew special, an enemy special attack (kind 8, ids 3-7) or the
party's S-Cannon. Measured on Windows from the `me550a` state with Aika's Sacri: 29.8-30.1 frames a
second in its window at 2x and 4x, whichever side acted first; the enemy's Focus in the same phase at
60 / 121; 1x unchanged.
