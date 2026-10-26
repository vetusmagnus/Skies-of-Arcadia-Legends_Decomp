The sound layer (music, sound effects, streams)
===============================================

What sits between the game and MusyX, and how to tell from RAM (or silence with one wrapped call)
which music the game is playing. Everything here is read from the disassembly (`build/GEAE8P/asm`), the
DOL strings and the disc files; nothing was run. Unverified points are collected under "Open".

All addresses are USA Rev 0 (GEAE8P). Function names below are working names; only `SePlay` is in
`symbols.txt`, the rest are `fn_xxxxxxxx`.

Layers
------

(`0x80214908`..`0x80215590` just before the shim are script opcode handlers for other subsystems, not sound.)

```
game code / script VM  -->  shim (0x802159E0..0x8021A044, "Manatee on MusyX")  -->  MusyX 2.0 (0x80266878..)
 sdMidi*/sdShot*/sdPstm*-style calls,           handles, banks, music lists, SE slots,              sndSeq*, sndStream*,
 DC file names, (bank, num) pairs               streams, async bank loads                           sndPushGroup, ...
```

* The game keeps the Dreamcast model: a sound **bank** is a DC `.MLT` unit (`mNNNN`, `tone`, ...) and a
  sound is addressed by **(bank number, data number)**. The shim turns that into MusyX calls.
* The DC bank number is the **slot** in the shim's bank table (0..10). DC and GC use the same numbers
  and the same data numbers (see "DC mapping", checked on 432 files).
* Music is MusyX *sequences* (`sndSeqPlayEx`), exactly like sound effects. Streams (`*_L.dsp`/`*_R.dsp`)
  are MusyX streams (`sndStreamAllocEx`). There is no other path to the DSP in game code.
* `sndSeqPlayEx` is called from exactly two places in the whole game: `SePlay` (`0x80218280`, effects)
  and the music update `fn_80218678` (`0x8021882C`, music). So the music start is one call site.
* `sndSeqSpeed`, `sndSeqMute` are never called (no `sdMidiSetSpeed` equivalent exists). `sndSeqSetMidiCtrl`
  is called from 3 places (adaptive town/dungeon music, below).

Handles ("ports")
-----------------

The shim returns small integers; every control function takes one.

| Handle | Meaning | State |
|---|---|---|
| `1` | the one music (BGM) slot. Every music call ignores its first argument (`li r3, 0`, the DC port). | `0x803477E0` |
| `0x10`, `0x11` | PCM stream 0 / 1 (`handle - 0x10` indexes `0x803477C8`) | `0x803477C8[2]` |
| `0x100 + seqId` | a sound effect started by `SePlay` (MusyX sequence id + 0x100); `0` = failed | SE slot table |

Function table
--------------

### Initialisation, frame update, shutdown

| Address | Working name | What it does |
|---|---|---|
| `0x80219D78` | `SndInit` | `sndInit(0x40 voices, ...)`, reverb HI + chorus aux, `sndVolume(0x7F)`, allocates the 4 stream channels (`sndStreamAllocEx`, callback `fn_802163FC`), sets bank states to -6, `lbl_803474E0 = 1`, loads `/sound/tone` (`lbl_802D6730`) into slot 0. Called once from `fn_801DBE88` (`0x801DBEB8`). |
| `0x80218678` | `SndUpdate` | **Once per frame** from the mode dispatcher `fn_801DC288` (`0x801DC38C`), only while `lbl_803474E0 == 1`. Pumps async bank loads, clears the music/SE state of sequences that ended, starts the next music sequence, runs the stream fade-out. See "Music". |
| `0x80219C84` | `SndShutdown` | `fn_80217CB0`, frees streams and banks, `sndQuit`. From `fn_801DC504` (`0x801DC550`). |
| `0x801DC2D8`.. | boot | `fn_801DC288` sets `lbl_803474E0 = 1`, loads `/sound/s1000000` (slot 1, `0x801DC2E8`), `sndOutputMode(OSGetSoundMode)`, loads `/sound/b7000000.mlt` (slot 7, `0x801DC308`). |

So after boot the common banks 0 (`tone`), 1 (`s1000000`) and 7 (`b7000000`) are always resident.

### Music (the `sdMidi*` family)

| Address | Working name | DC equivalent | Arguments, behaviour |
|---|---|---|---|
| `0x80218570` | `MusicPlay(port, bank, num)` | `sdMidiPlay` | `bank`, `num` are `s8`. Builds a one-element list and queues it (below). Returns 1. |
| `0x802182F4` | `MusicPlayList(port, n, bank0, num0, bank1, num1, ...)` | chain of `sdMidiPlay` | Variadic (PPC varargs, `crclr cr1eq`), `n` pairs, at most 16. Queues a play list (below). Returns 1. |
| `0x80217830` | `SndStop(handle)` | `sdMidiStop` / `sdShotStop` / `sdPstmStop` | Handle 1: `sndSeqVolume(0, 500, seq, STOP)`, `bgm_seq = -1`, clears the current and pending list counts. 0x10/0x11: stops both channels of the stream now. >= 0x100: fades that effect out (100 ms, stop). |
| `0x8021730C` | `SndFadeStop(handle, ms)` | `sdMidiSetVol(-127, fade)` + stop | Handle 1: `SndSetVol(1, -127, ms)` (fade to 0 then stop) and clears the current list count. Streams: sets `lbl_803477C0 = 0x20`, `lbl_803477BC = port` (fade over 32 frames, run by `SndUpdate`). Called by script opcode 0x38. |
| `0x80217380` | `SndFadeStop1s(handle)` | same, 1000 ms | Same as above with a fixed 1000 (capped to 500 by `SndSetVol`). |
| `0x802173F4` | `SndSetVol(handle, s8 vol, s16 ms)` | `sdMidiSetVol` / `sdShotSetVol` | Music: `sndSeqVolume(((vol+128)/2) * bankDefault >> 7, min(ms, 500), seq, mode)` with `mode = STOP` when `vol <= -127`, else CONTINUE. Effects: same on that effect's slot (skipped if it is the music sequence). |
| `0x802172C8` | `SndSetVolNow(handle, s8 vol)` | `sdMidiSetVol(h, vol, 0)` | `SndSetVol(h, max(vol, -126), 0)`; handle 0 is ignored. |
| `0x802171F0` | `SndMasterVol(s8 vol)` | `sdSndSetMasterVol` | Applies `((vol+128)/2) * bankDefault >> 7` (music) or `* slot volume >> 7` (effects) to the music sequence and all 6 effect slots, 500 ms. Camp menu open uses -31 (`0x801BE728`). |
| `0x80217134` | `SndMasterVolReset` | | Same with 127 (full). Camp menu close (`0x801BEA04`). |
| `0x80217608` | `MusicPause` | `sdMidiPause` | If music plays: `sndSeqVolume(0, 500, seq, PAUSE)`, `sndSeqPause`, copies the current list to the saved list `0x80315434`, `paused_seq/bank = seq/bank`, current list count = 0, `bgm_seq = -1`. |
| `0x80217554` | `MusicContinue` | `sdMidiContinue` | If something is paused: when new music is already playing the paused sequence is stopped; otherwise `sndSeqContinue`, restores list/bank/seq, `sndSeqVolume(bankDefault, 500, seq, 0)`. |
| `0x8021768C` | `ContinueAll` | | `MusicContinue` plus `sndSeqContinue` on every paused effect. Camp menu close (`0x801BEA30`). |
| `0x80217790` | `PauseSEs` | | `sndSeqPause` on every effect slot (flag +0xC = 1). Camp menu open (`0x801BE7A0`). |
| `0x80216F48` | `SndIsPlaying(handle)` | `sdMidiGetStat`-like | 1: `bgm_seq != -1` (no MusyX query). 0x10/0x11: is channel pair alive. >= 0x100: `sndSeqGetValid`. |
| `0x80217800` | `StopIfBank(bank)` | | If `bank == bgm_bank` then `SndStop(1)`. Called with 4 at `0x800E3618`. |
| `0x80218DC4` | `BgmSeqIfBank2` | | Returns `bgm_seq` if `bgm_bank == 2`, else -1. Used by the layered town music (below). |
| `0x80217CB0` | `SndStopAll` | `sdSndStopAll` | Stops music and all effects, closes both streams, `sndSilence`. |
| `0x80217B98`, `0x80217C24` | `StopSEs` | `sdShotStopAll` | Stops all effect sequences except the music one (two copies). |
| `0x80218DDC` | `SndReset` | | Scene change clean-up: stops music if there is no current list, pops banks while more than 3 are loaded, closes streams, stops effects. Called once, `0x801F716C`. |

### Effects (the `sdShot*` family)

| Address | Working name | Notes |
|---|---|---|
| `0x80217FF4` (`SePlay`) | `SePlay(prio, bank, id)` | `s8` arguments (it sign-extends). `prio` ranks the effect for slot stealing: score `prio > 0 ? 0x1388 - prio*100 : 0` stored in the slot (`+8`); every new effect adds 1 to all scores and the slot with the highest score is stolen (free slots hold 0x2710). `bank` is a slot index (0..10), `id` the data number. Returns `seqId + 0x100`, or 0. Bank remap by `lbl_803477E4`: variant 1 sends bank 3 to slot 9; variant 2 also sends bank 7 to slot 10. Same-frame duplicate (`id*16+bank` == `lbl_803477D0`) is dropped. A bank in state -5..-1 is loaded on demand (blocking); below -5 it returns 0. Then `sndSeqPlayEx(group, firstSid + id, info + 4*tab[id], 0, 0)` and `sndSeqVolume(bankDefault)`. |
| `0x80217FD4` | thunk to `SePlay` | |
| `0x80216F1C` | `SePlay(15, a, b)` | Used by the sound test. |

`SePlay` is the effect start for everything the game plays through `sdShotPlay`: menu sounds
(`menu_se_table` in `docs/ui.md`: `SePlay(table.bank, 1, table.id)`, so slot 1 = `s1000000`), script
opcode 0x33 and the code paths in the table of callers below.

### Banks (`sdMultiUnitDownload`)

| Address | Working name | Notes |
|---|---|---|
| `0x80219378`, `0x80218D84` | `BankLoad(path)` | Blocking: `BankLoadStart` then `fn_80219B7C` until done (two identical copies). |
| `0x80216CB4` | `BankLoadAsync(path)` | Start only; `fn_80216CA4` returns 1 when idle (`lbl_803477E8 == 0`); `fn_80216CD8` finishes. Script opcode 0xF8. |
| `0x802193BC` | `BankLoadStart(path, preloaded)` | Core. Copies the path up to the first `.` (so `.mlt` and `.samp` both work, at most 63 chars), maps the name to a slot (`fn_80219998`), and if that slot already holds the same name (case-insensitive) does nothing. Otherwise pops the most recently loaded banks until the slot is free, stores the name at slot `+0x14`, reads `NAME.info` into the heap, `NAME.samp` into main RAM (both `DVDReadAsync`, callbacks `fn_80219B24` / `fn_80219ACC` set flags in slot `+0x34`). |
| `0x80219B7C` | `BankPump` | When both reads are done: `sndPushGroup(info + pool, group id, samples, info + sdir, info + pool)`, stores the group id (`+8`) and first song id (`+0xC`), `+0x10 = loadCounter++`. This is the moment a bank becomes usable. |
| `0x80219998` | `BankSlotForName(name)` | Slot and default volume from the first letter after the last `/` (table below). |
| `0x80219834` | `BankPopNewest(force)` | Unloads the most recently loaded bank (`sndPopGroup` is a stack). Stops sequences using it (refuses, returns -1, if music uses it and `force == 0`). Returns the slot freed. |
| `0x80219324` | `BankUnload(slot)` | Pops until that slot is free. Used at `0x80101AF8` for slots 5 and 6. |

### Streams (the `sdPstm*` family)

| Address | Working name | Notes |
|---|---|---|
| `0x802159E0` | `PcmPrepare(...)` | Core of `sndPCMReq`. Takes the stream name in the last register argument (`r10`), **drops the last character before the `.`** (`"m02s.p16"` -> `"m02"`, `"f7100000s.p04"` -> `"f7100000"`), appends `_L.dsp` / `_R.dsp`, opens both with `DVDOpen`, reads the two 0x60-byte DSP headers, fills a descriptor in `lbl_80314940` (2 x 0x60). Returns the handle `0x10` or `0x11` (slots alternate via `lbl_803477C4`), or 0. The other arguments (`1, 2, 0x5622/0xAC44, 2, ...`) are Dreamcast leftovers; the sample rate comes from the DSP header. A previous stream in the same slot is stopped first. |
| `0x80215EA0`, `0x80215F14` | `PcmPrepare` wrappers | `0x80215EA0` takes a stack size (credits/ending: `0x3C000`), `0x80215F14` uses `0x8000` (voice). |
| `0x80216E38` | `PcmPrepareScript(type, name)` | Script opcode 0xD7. Builds `"/sound/" + name`, `type 0` = 22.05 kHz class (`0x4000` buffer), `type 1` = 44.1 kHz class (`0x100000`). Stores the handle in `lbl_803477B8`. |
| `0x80215F94` | `PcmStart(handle)` | If the slot is prepared and no stream is running there: `fn_802168CC(descL, descR, 0x78)`, stores the stream id in `0x803477C8[h-0x10]`, `lbl_803477C0 = 0`. |
| `0x80216D98` | `PcmStartPending` | Script opcode 0xD8. Same for `lbl_803477B8`. |
| `0x80216D14` | `PcmStopPending` | Fades out / stops `lbl_803477B8` (32 frames for a stream). Called at `0x800EB520`. |
| `0x802168CC` | `PcmStartCore` | Picks two free stream channels (`fn_80216B88`), pan 0 / 0x7F via `fn_80216A9C`, volume 0x78, starts the two async reads with callback `fn_80216030` (double-buffering into ARAM, `sndStreamARAMUpdate`, `sndStreamActivate`). |
| `0x802163FC` | stream callback | Passed to `sndStreamAllocEx`; refills ARAM, releases the channel at end of file. |

Banks: slot table
-----------------

Table `lbl_80315120` = `0x803148C0 + 0x860`, 11 entries of 0x3C bytes (`bank_table[slot]`).

| Offset | Type | Meaning |
|---|---|---|
| `+0x00` | `void*` | `.info` data (heap). Header: three `u16`, then `u16 tab[]`: `tab[0]*4` pool offset, `tab[1]*4` project offset, `tab[2]*4` sample directory offset; `u16` at `+6+2*id` (x4) is the offset of data number `id`'s sequence data. |
| `+0x04` | `void*` | `.samp` data (main RAM) |
| `+0x08` | `u32` | MusyX group id (first group in the project) |
| `+0x0C` | `u32` | first song id of that group; sequence for data number `id` is `+0x0C + id` |
| `+0x10` | `s32` | state: `-6` never loaded, `-1` unloaded (name remembered), `<-1` load pending/failed, `>= 0` loaded (the load counter value; the stack order) |
| `+0x14` | `char[0x20]` | name without extension, as passed (for example `/sound/m0231`, `/SOUND/STV05`) |
| `+0x34` | `u32` | load flags: bit0 info read, bit1 samples read, bit4 error |
| `+0x38` | `u8` | default volume for sequences of this bank (0x64 for M02..M04, 0x78 for `s1000000`, 0x7F otherwise) |

Name to slot (`fn_80219998`, first letter after the last `/`, case-insensitive for B, C, E, F, K, M, S, T):

| Name | Slot | Default volume | DC unit |
|---|---|---|---|
| `tone` | 0 | 0x7F | `ARESNEW.MLT` bank 0 (samples; tone.info has no sequences) |
| `s1000000` | 1 | 0x78 | `ARESNEW.MLT` bank 1 (no `S1000000.MLT` on DC) |
| `m02NN`, `m03NN`, `m04NN` (4 digits) | 2, 3, 4 (third digit) | 0x64 | `SOUND/M0NNN.MLT` |
| `m5NNNNNN` | 5 | 0x7F | `SOUND/M5NNNNNN.MLT` |
| `e6xNNN` | 6 | 0x7F | `SOUND/E6xNNN.MLT` |
| `b7000000`, `f7000000` | 7 | 0x7F | `ARESNEW.MLT` bank 7 / `F7000000.MLT` |
| `k8NNNNNN` | 8 | 0x7F | `SOUND/K8NNNNNN.MLT` |
| `stvNN`, other `s*` | 9 | 0x7F | `STVNN.MLT` (on DC its sequences are in bank 3) |
| `f3NNNNNN` | 3 | 0x7F | `F3NNNNNN.MLT` (shares slot 3 with `m03NN`) |
| `cr0NN`, `cr1NN` | 9 / 10 (`cr0NN` is remapped from 11 to 9) | 0x7F | `CRNNN.MLT` (on DC its sequences are in bank 3) |
| anything else | 0 | 0x7F | |

`lbl_803477E4` (variant): set by the loads: `stv`/`cr0` set 1 or 2, a normal slot 3 or 7 load clears it
(`fn_802193BC`, `0x802194CC..`). While it is 1 or 2, `SePlay` sends bank 3 (and 7 for variant 2) to
slot 9 (or 10), because on the GC the STV / CR banks do not fit slot 3 / 7.

Other related state, all absolute addresses (sdata, written with `@sda21`):

| Address | Type | Meaning |
|---|---|---|
| `0x803474E0` | `s32` | sound system running (1 after boot) |
| `0x803477E8` | `bank_entry*` | entry being loaded (0 = idle) |
| `0x803477EC` | `s32` | load counter |
| `0x803477E4` | `s32` | variant, see above |

Music
-----

One music sequence at a time. The game queues **lists** of (bank, num) pairs; `SndUpdate` plays one
pair after the other.

### Music list records

`struct MusicList { s32 idx; s32 count; s8 pair[count][2]; }` (0x28 bytes, so at most 16 pairs).
`pair[i][0]` is the bank slot, `pair[i][1]` the data number (the `sdMidiPlay` arguments).

| Address | Meaning |
|---|---|
| `0x8031545C` | pending request. `+0` is 1 when the first bank of the list is negative (then the first pair is skipped), else 0. `+4` count (0 = none). |
| `0x80315484` | current list. `+0` is the index of the next pair to start, `+4` count (0 = none). |
| `0x80315434` | saved current list while music is paused. |

### Music state variables

| Address | Meaning |
|---|---|
| `0x803477E0` | **music MusyX sequence id**; -1 = none. Set right after `sndSeqPlayEx`; cleared when the sequence ends, on stop and on pause. |
| `0x803477DC` | bank slot of the current music sequence. Valid while `0x803477E0 != -1`. |
| `0x803477D8` | MusyX sequence id of the paused music; -1 = none. |
| `0x803477D4` | bank slot of the paused music. |

### How a song starts (`MusicPlay` / `MusicPlayList` -> `SndUpdate`)

1. `MusicPlay` / `MusicPlayList` fill a new record. If it equals the current list (same count and pairs)
   they only clear the pending count and return, nothing restarts. Otherwise: if music is playing, a
   list of one pair fades it out (`sndSeqVolume(0, 500, seq, STOP)`, the sequence stays valid until the
   fade ends), a longer list stops it at once (`sndSeqStop`, `bgm_seq = -1`); current list count is set
   to 0; the record is copied to the pending list (`0x8031545C`).
2. `SndUpdate`, once per frame: if `bgm_seq` is set but `sndSeqGetValid` fails, the sequence is stopped
   and `bgm_seq = -1`. If `bgm_seq == -1` and a list is pending, the pending list is copied over the
   current list (`+0` becomes the idx) and its count cleared.
3. If `bgm_seq == -1` and `idx < count`: `bgm_bank = pair[idx][0]`; the bank is loaded on demand if its
   state is -5..-1 (blocking, `fn_802193BC`); `sndSeqPlayEx(group, firstSid + num, info + 4 * tab[num],
   NULL, 0)` **at `0x8021882C`**; `bgm_seq = result`; `sndSeqVolume(bankDefault, 0, seq, 0)` (at
   `0x80218850`); `idx++`; when `idx >= count`: `idx = 0` if `count == 1`, else `idx = 1`.
4. So a list plays pair 0, pair 1, ... and then loops pairs 1..count-1 (pair 0 is the intro). A single
   pair relies on the sequence's own loop. The next pair starts the frame after the previous sequence
   became invalid (it ended), so GC sequences are the timing master.

Known lists (bank 4 = the battle music bank `m0460` / `m0462`, loaded with `"/sound/m04%02d.samp"`):
`fn_80009874` (game over screen, `0x80009C78..`) builds `[4:12, 4:0, 4:1, 4:2, 4:3, 4:4, 4:5, 4:6, 4:7]`
(9 pairs) or `[4:9, 4:0, 4:1, 4:2, 4:3]`, `[4:8, 4:4, 4:5]` (3 pairs) and `MusicPlay(4, 0)`;
`fn_80097720` and `fn_8007D42C` (battle start) build similar lists. These are segment lists (intro
then loop sections), so one battle theme is several DC data numbers in a row.

### Where music is requested (known callers)

| Call site | Function | Request |
|---|---|---|
| `0x8000996C` | `fn_80009874` (game over) | `MusicPlay(0, 3, 0)` after loading `/sound/m0367.mlt` (`m0367` has 2 sequences) |
| `0x80009CE4`, `D2C`, `DAC`, `DD8`, `DEC` | `fn_80009874` | battle lists, `MusicPlay(4, 0)` |
| `0x80097914`..`0x800979BC` | `fn_80097720` | battle lists |
| `0x8007D750`..`0x8007DE14` | `fn_8007D42C` | battle lists |
| `0x80101D80` | `fn_80101828` | `MusicPlay(4, 0)`; the same function pauses (`0x80101AF0`) and resumes (`0x80101904`) the music, likely around a battle (not confirmed) |
| `0x8001B358`, `0x800E3628` | `fn_8001B1B0`, `fn_800E3594` (the latter loads `/field/HRS_BEND.BIN`) | `MusicPlay(1, 18)` (data 18 of `s1000000`, the 3.4 KB sequence in both DC and GC) |
| `0x801FA488` | script opcode 0x37 | `MusicPlay(arg0, arg1)`, both `s8` script integers |

Most field/town/dungeon music (`m0231`..`m0384`, one sequence each, data number 0) and the `m5xxxxxx`
event music (31..37 sequences each) are started by scripts through opcode 0x37 with bank/num in the
script data (compressed in `field/*.sct`, `field/*.mld`), so they are not visible as constants in the
DOL. Bank 3 and 4 are loaded by opcode 0x45 / 0xF8 first.

### Pause, volume, stop

* Pause: `MusicPause` (`0x80217608`): `sndSeqVolume(0, 500, seq, PAUSE)` at `0x80217630`,
  `sndSeqPause` at `0x80217638`. Continue: `0x80217554`: `sndSeqContinue` at `0x802175AC`, volume at
  `0x802175E8`; `0x8021768C`: `0x802176EC`/`0x8021775C`, volume at `0x80217728`.
* Volume: `bankDefault` is applied by the shim: the MusyX volume is `v * bankDefault >> 7` with
  `v = (vol + 128) / 2` for the `s8` volume the game passes (-127 = silence and stop, 127 = full). The
  time is in milliseconds, capped at 500. Nothing about volume or fade is stored in game RAM.
* Stop with fade: script opcode 0x38 -> `SndFadeStop(1, ms)` -> `SndSetVol(1, -127, ms)`.
  Stop at once: `SndStop(1)` fades 500 ms and clears the state.
* Master volume (camp menu): `SndMasterVol(-31)` open, `SndMasterVolReset` close.

The 16 `sndSeqVolume` call sites of the shim (all of them are in the shim):

| Site | Function | Affects |
|---|---|---|
| `0x80217188` | `SndMasterVolReset` | music |
| `0x802171C4` | `SndMasterVolReset` | effects |
| `0x8021725C` | `SndMasterVol` | music |
| `0x80217298` | `SndMasterVol` | effects |
| `0x80217484` | `SndSetVol` | music |
| `0x8021750C` | `SndSetVol` | effects |
| `0x802175E8` | `MusicContinue` | music |
| `0x80217630` | `MusicPause` | music (mode PAUSE) |
| `0x80217728` | `ContinueAll` | music |
| `0x8021786C` | `SndStop` | music (mode STOP) |
| `0x80217B4C` | `SndStop` | effect (mode STOP) |
| `0x802182B4` | `SePlay` | effect |
| `0x80218404`, `0x80218538`, `0x80218638` | `MusicPlayList`/`MusicPlay` | old music fade out (mode STOP) |
| `0x80218850` | `SndUpdate` | new music start volume |

(MusyX modes: 0 continue, 1 stop after fade, 2 pause after fade, 3 mute.)

### Adaptive music

`fn_8009CBBC` (`sndSeqSetMidiCtrl` at `0x8009CD5C`) and `fn_8009CDB8` (`0x8009CF5C`, `0x8009CF7C`) set MIDI
controller 7 (volume) of channels 10.. on the music sequence returned by `0x80218DC4` (only while the
music bank is 2), by the camera distance to fixed points. It is a per-channel layer fade in the `M02xx`
town/dungeon music. `fn_8009CBBC` sets channels 10-15 (`r24 + 10`, six points), `fn_8009CDB8` channels
12-14 (three points) and, for the third, channel 17 too with the same value (`r23 + 15` when
`r23 == 2`): MusyX channels from 16 up have no Dreamcast counterpart (the Manatee message is
`port << 4 | channel`), so 17 looks like a GameCube-side split of channel 14. Both run every frame
(the world map sends 0 to 12, 13, 14 and 17 each frame).

Bonito's sequences (the Dreamcast data) don't end: at the end the port status word at +0x18 becomes 1
and the port holds, still flagged playing; the GameCube conversions end (`sndSeqGetValid` fails), which
is what `SndUpdate` waits for. Measured on `M0460` (segments 9, 0-3): 3.733 / 19.870 / 13.253 / 13.264 /
13.259 s on the Dreamcast driver against 3.72 / 19.92 / 13.28 / 13.18 / 13.28 s start to start in the
game, so the conversions kept the lengths.

DC mapping
----------

Question: does the game pass DC (bank, data number), so the same numbers index the DC SMSB?
Yes. Evidence:

* File names are the same: every GC `sound/mNNNN`, `m5NNNNNN`, `e6xNNN`, `f3NNNNNN`, `f7000000`,
  `k8NNNNNN`, `cr0NN`, `stvNN`, `b7000000` has a DC `SOUND/<NAME>.MLT`. `tone` + `s1000000` +
  `b7000000` are the three banks of `ARESNEW.MLT` (0, 1, 7). DC `B7000000.MLT` also exists.
* Sequence counts. GC `.info` data numbers = the non-zero `u16` entries at `+6` (contiguous from 0);
  DC = `u32` count at SMSB `+0x0C` (`tools/dcmusic/mltinfo.py` for the unit). Of 432 comparable files
  394 match exactly, including all `m02NN`/`m03NN`/`m04NN` (1 sequence each, `m0367` and `m0282`: 2,
  `m0460`: 14, `m0462`: 15), `f7000000` (28 = 28), `b7000000` (106 = ARESNEW bank 7: 106).
* The differences:
  * `m5NNNNNN`: GC has 30..37 (DC 36 or 37, `m5270000` 7 vs 36); the GC list is the DC list with the tail
    cut (the cut DC sequences are ~0x28 bytes, empty).
  * `e6f007`, `e6g003`, `e6h004`, `e6h011`: GC has one fewer than DC (3/4, 13/14, 2/3, 17/18).
  * `s1000000`: GC 39, DC bank 1 in `ARESNEW.MLT`: 34. The size curves of data 0..33 line up (correlation
    0.98, the large data 18 is 3424 bytes on DC and 5088 on GC), so 34..38 are GC additions at the end.
  * `k8900001`: GC 0, DC 1. `tone`: GC 0 (sequences of banks 0 and 1 are in other files).
* The sequence data formats differ (DC `SMSD`, GC MusyX song data at `info + 4*tab[id]`) but the order
  matches: for `b7000000` vs ARESNEW bank 7 and for `m0460`/`m0462` the per-sequence size is monotonic
  with the DC one.
* DC does not have the extra STV/CR bank slots: `STVNN.MLT`/`CRNNN.MLT` contain `SMSB 3` (sequences) and
  `SMPB 6` (samples) on DC; the GC loads them into slot 9/10 and `SePlay` remaps the requested bank 3.
  For a DC mapping use bank = the number the game passed (before the remap), `3`.

How to map a GC event to the DC bank:

1. `file = lowercase(basename(bank_table[bank].name))` -> DC unit `file.upper() + ".MLT"` in `SOUND/`,
   except `tone`, `s1000000`, `b7000000` -> `ARESNEW.MLT` (or `B7000000.MLT`).
2. DC bank number = the slot (`bank`). DC data number = `num`, the GC data number.
3. `num` for a music sequence start = `sid - bank_table[bank].firstSid` (+0x0C) where `sid` is the
   second argument of `sndSeqPlayEx` at `0x8021882C`.

Streams (streamed music)
------------------------

* GC files: `sound/m01_L.dsp` / `m01_R.dsp` .. `m04`; DC: `SOUND/M01S.P04` and `SOUND/M02S.P16`
  (disc 1 only has these two; `M03S`/`M04S` are probably on disc 2). The game asks for the DC name
  (`m01s.p04`, `/sound/m02s.p16`, `/sound/m04s.p16`, `/SOUND/f7100000s.p04`) and `PcmPrepare` rewrites
  it to `<name without last letter>_L.dsp`/`_R.dsp`. Same engine for voices: `B702NNNNS.P04`,
  `KONNNNS`, `NNNS.P04`, `f71000NNs.p04`, so **music is told from voice by the name** (`m01`..`m04`).
* Two stream slots, handles `0x10`/`0x11`. Playing: `0x803477C8[h-0x10] != -1` (the stream id).
  Current names: left file path `0x80314900 + 0x20*(h-0x10)`, right file path `0x803148C0 +
  0x20*(h-0x10)` (set by `PcmPrepare`, valid until the slot is reused).
* Channel table `lbl_80314B80` = `0x803148C0 + 0x2C0`: 4 channels x 0x80. `+0` state (0 free, 1 taken,
  2 buffer being filled, 3 ready, 4 playing), `+4` stream id, `+8` / `+0xC` the partner channel, `+0x14`
  volume byte (0x78), `+0x15` pan (0 left, 0x7F right), `+0x18` `DVDFileInfo`, `+0x54` MusyX stream
  handle, `+0x60` buffer, `+0x64` size (0x6280). Id counter at `0x803148C0 + 0x4C0`.
* Start: scripts. Opcode 0xD7 (`fn_801FEE54`) -> `PcmPrepareScript(type, name)`; opcode 0xD8
  (`fn_801FEDD0`) -> `PcmStartPending`. `field/me299a.sct` contains `m01s.p04`, `me298a.sct` `m03s.p..`,
  `a035ah24.mld` `M02s`, `a131i.mld` `m04s` (strings visible without decompression; more are
  compressed). Code: the staff roll `fn_80228E00` (`0x80229048`, `/sound/m02s.p16`, restarted when it
  ends and 92 s elapsed) and `fn_80229124`/`fn_80229E54`, the ending `fn_801C9198` (`0x801C92D8`,
  `/sound/m04s.p16`). Voices: `fn_8003F890` (`0x8003F9C4`, `"/SOUND/%s"` + `B702%04dS%s`).
* **Battle streams** (2026-10-21): every spell and S-move plays `SOUND/KO00NN` (NN = the skill id, one
  pre-mixed stereo track with voice and effects; no sound effects start during it), battle voices are
  `B702NNNN` (`fn_8003F890`, two prepared slots at `lbl_8030A10C` +0xCC / +0xD0..+0xD4), the victory
  line e.g. `153`. MusyX side: `streamInfo` (`0x8032C730`, 64 x 0x64) per channel; `last` (+0x20)
  moves between 0 and half the buffer while a stream plays.
* Stop: `SndStop(0x10/0x11)` / `SndStopAll` (closes both channels at once), or fade:
  `SndFadeStop(0x10/0x11, ms)` sets `lbl_803477C0 = 0x20` and `lbl_803477BC = port`; `SndUpdate`
  (`0x802188EC..`) counts it down and sets stream volume to `counter * 0x78 / 32`, then stops.
  Streams end by themselves when the file ends (callback `fn_80216030` -> channel freed, handle
  becomes -1).
* `sndPCMReq`, `MLT SE`, `X Bank=%d No=%d`, `STREAM SET`, `SE REQUEST` are strings of the debug sound
  test (`fn_80155B78` PCM request with `/SOUND/f7100000s.p04`, `fn_80155DB4` effect test,
  `fn_80155E60` loads `/SOUND/F3000012.mlt`). Not reachable in the retail game.

Script opcodes that reach the shim
-----------------------------------

The script VM handler table is `lbl_802F7940` (266 entries x 12 bytes: `u32 flag, u32 arg info,
handler`; the opcode is the index). Arguments are read with `fn_801F6120`-style readers (script ints
are float-encoded).

| Opcode | Handler | Calls |
|---|---|---|
| `0x33` | `fn_801FA060` | `SePlay(clamp(16 - arg1), arg2 bank, arg3 id)` |
| `0x37` | `fn_801FA398` | `MusicPlay(0, bank, num)` (`s8`) |
| `0x38` | `fn_801FA290` | `SndFadeStop(1, frames converted to ms)` |
| `0x45` | `fn_801FA1D0` | `BankLoad("/sound/" + name + ".mlt")` (`lbl_80346848` -> `"/sound/"`) |
| `0x65`, `0x66` | `fn_801F984C`, `fn_801F9668` | `SndStop(handle)` |
| `0x67` | `fn_801F9614` | `StopSEs` |
| `0xB1` | `fn_8020DD1C` | `SndIsPlaying` / `SndSetVol` (inside a large handler) |
| `0xCF` | `fn_8020BDB0` | `SndSetVol` |
| `0xD7` / `0xD8` | `fn_801FEE54` / `fn_801FEDD0` | stream prepare / start |
| `0xF7` | `fn_801F95C0` | `SndStopAll` |
| `0xF8` | `fn_801F7C18` | `BankLoadAsync("/sound/" + name + ".mlt")` |

Hooks for a frontend
--------------------

To know exactly "music started bank B data N", "stopped", "paused / continued", "volume V over T ms":

**Polling RAM once per frame (after `SndUpdate`, `0x80218678`)** gives these, which is enough for
start/stop/pause but not for volume:

* start of a sequence = `*(s32*)0x803477E0` goes from -1 (or another id) to a new id. `bank =
  *(s32*)0x803477DC`. `file` = `bank_table[bank].name` (`0x80315120 + 0x3C*bank + 0x14`). `num` is the
  `pair[k][1]` of the pair just started: `k = idx - 1` where `idx = *(s32*)0x80315484` (list index
  after the start), except that after a wrap `idx == 1` can mean `k == 0` or `k == count - 1`; compare
  with the idx seen on the previous frame (a start moves `idx` by +1, or to 1 on wrap) when `count > 1`.
  This ambiguity is why a hook is better for the exact `num` (below).
* stop / end = `0x803477E0` becomes -1 without `0x803477D8` being set.
* pause = `0x803477E0` becomes -1 and `0x803477D8` becomes the old id (`0x803477D4` = its bank);
  continue = `0x803477D8` goes back to -1 and `0x803477E0` is restored.
* master/music volume and fade: **not in RAM**; only by hooking (or reading MusyX's synth volume
  groups, not worth it).

**Hooks (recommended)**, all whole-call wrappers at the `bl` sites in `auto_01_801E3874_text.s`:

| Wrap | Sites | Gives |
|---|---|---|
| `sndSeqPlayEx` | `0x8021882C` only (music) | exact `sgid`, `sid`, `num = sid - bank.firstSid`, bank in `0x803477DC`, file name |
| `sndSeqVolume` | the sites in the table above with `seq == *(u32*)0x803477E0` (or the paused id) | `vol` (0..127), `ms`, `mode` (0 volume, 1 fade then stop, 2 fade then pause) |
| `sndSeqPause` | `0x80217638` | pause |
| `sndSeqContinue` | `0x802175AC`, `0x802176EC`, `0x8021775C` | continue |
| `sndSeqStop` | music sites `0x8021758C`, `0x802176CC` (stop a replaced paused song), `0x802183E4`, `0x80218518`, `0x80218618` (new request replaces old), `0x802186B4` (ended), `0x80217CE4` (stop all), `0x80218E14`, `0x80219570`, `0x802198B0` (bank unload) | stop |

Or wrap the shim functions themselves (fewer sites, same events with the game's own arguments):
`MusicPlay` (`0x80218570`), `MusicPlayList` (`0x802182F4`), `SndSetVol` (`0x802173F4`) with handle 1,
`SndMasterVol` (`0x802171F0`), `SndMasterVolReset` (`0x80217134`), `SndStop` (`0x80217830`) with handle 1,
`SndFadeStop` (`0x8021730C`/`0x80217380`), `MusicPause` (`0x80217608`), `MusicContinue` (`0x80217554`),
`ContinueAll` (`0x8021768C`), `SndStopAll` (`0x80217CB0`), `BankLoadStart` (`0x802193BC`) /
`BankPump` (`0x80219B7C`, `sndPushGroup` at `0x80219C48` = bank is usable).

Mapping to the DC driver, with the GC sequence kept as the timing master:

| GC event | DC call |
|---|---|
| bank pushed (`0x80219C48`) for a slot 2..5 file | `sdMultiUnitDownload(<file>.MLT)` (the bank number comes from the file) |
| music sequence start (`0x8021882C`) | `sdMidiPlay(0, bank, num, prio)` |
| sequence end / `bgm_seq` -> -1 / `SndStop(1)` after its fade | `sdMidiStop(0)` |
| `sndSeqVolume` mode 0 on the music sequence | `sdMidiSetVol(0, vol, ms)` (the DC vol is `s8`; the game's own value is `0x802173F4`'s `vol` argument) |
| mode 1 | `sdMidiSetVol(0, -127, ms)` then stop |
| `sndSeqPause` / `sndSeqContinue` on the music | `sdMidiPause(0)` / `sdMidiContinue(0)` |

The shim's own entry points carry the raw `s8` volume and the raw millisecond fade, so wrapping
`SndSetVol` (`0x802173F4`), `SndMasterVol` and `SndFadeStop` forwards the Manatee call 1:1; the
`sndSeqVolume` sites only have the converted 0..127 value.

Silencing only the music
------------------------

**Recommended: mute the track mask at the start, one wrapper.** Wrap the `bl sndSeqPlayEx` at
`0x8021882C` (the only music start; the other call site `0x80218280` is `SePlay`). The wrapper calls
`sndSeqPlayEx(sgid, sid, arr, para, studio)` with a `SND_PLAYPARA` whose `flags = 1` (TRACKMUTE) and
`trackMute = {0, 0}` instead of the NULL the game passes (`r6 = 0`); set it only when the DC music for
that (bank, num) is available:

```c
/* 0x28 bytes in guest memory, zeroed except flags */
SND_PLAYPARA para = { .flags = SND_PLAYPARA_TRACKMUTE, .trackMute = {0, 0} };
return sndSeqPlayEx(sgid, sid, arr, use_dc ? &para : NULL, studio);
```

Checked against the DOL: `seqStartPlay` (`0x802668E0`) tests bit 0 of `para->flags` (`0x80266C78`) and
copies `para+4`/`para+8` to the sequence instance at `+0x11C`/`+0x120` (`trackMute`); the sequencer
(`seq.c`) starts a note only when the track's mask bit is set, so with 0/0 no note of that sequence is
ever started. The sequence keeps running (timing, loops, end-of-sequence, `sndSeqGetValid`,
`SndIsPlaying`, pause/continue, the playlist advance) so the game's bookkeeping is identical. All
volume changes and fades still apply to the silent sequence without effect. The decision is taken per
sequence, so music without DC data still plays normally, and sound effects (`SePlay`) are not touched.

Alternative (no PLAYPARA): force `vol = 0` when `mode == 0 && seq == *(u32*)0x803477E0` in a wrapper
around `sndSeqVolume` at `0x80217188`, `0x8021725C`, `0x80217484`, `0x802175E8`, `0x80217728`,
`0x80218850` (the six sites that carry music volume with mode 0). More sites, and a bank default
volume reset by any missed site would be audible.

**Not recommended**: skipping `sndSeqPlayEx` (returning -1): `SndUpdate` then does not advance the list
(`0x8021883C` branches before `idx++`), re-calls it every frame and `SndIsPlaying(1)` is false, which
breaks scripts that wait on the music. Returning a fake id fails `sndSeqGetValid` (`0x802186A4`) and
the game thinks the song ended at once.

**Streams (m01..m04)** are not covered by the above. The simplest wrapper is on `PcmStartCore`
(`0x802168CC`): its third argument is the volume byte (0x78); pass 0 when the name set by `PcmPrepare`
(`0x80314900 + 0x20*(h-0x10)`) is a music stream. The fade-out in `SndUpdate` and the buffer callback
`fn_80216030` rewrite the volume from the channel's `+0x14` byte (`sndStreamMixParameterEx` sites
`0x80216148`.., `0x80218A28`.., `0x802161x8`), so also zero `+0x14` of the two channels or wrap
`sndStreamMixParameterEx` (`0x8026FED4`) and force its volume for music channels. Not tested.

Region differences (European 50 Hz, Japanese voices)
---------------------------------------------------

Found 2026-10-21 by comparing the three GameCube discs' `sound/` folders (same 1799 names on each).

* **A stream ends at its header's nibble count, not at the file's end.** `PcmPrepare` (`0x802159E0`)
  copies the DSP header's coefficients (`+0x1C`) into the descriptor, its rate (`+8`) to `+4`, sets the
  data start `+8` = `0x60` and the end `+0xC` = `(nibbles >> 1) & ~0x1F` (`0x80215E40`); the refill
  `fn_80216744` reads up to that end and zero-fills past it. A shorter stream can keep its file's size.
* **European release (GEAP8P), made for 50 Hz.** The game has no 50 Hz compensation in code (it runs
  5/6 speed at 50 Hz), so its data was retimed:
  * 223 stream pairs (`KO00NN`, most `B702NNNN`, `f71000NN`, 3 victory lines) are time-stretched,
    pitch kept, to 1.2 times the USA length (13 re-edited longer, Cutlass Fury `KO0036` with a fade-out
    tail); the music streams `m01`-`m04`, 25 `B702`, 54 victory lines and 2 field voices are the USA
    files. Some European field streams are 18000 Hz where the USA ones are 22050.
  * In every enemy bank (`e6*.info`, all 279) and `m5100000.info`, each sequence's tempo is 5/6 of the
    USA one: the song header's initial tempo (`+0x10`, a `u32`), the tempo table at the offset in `+0xC`
    (`{u32 tick, u32 tempo}` pairs; the `0xFFFFFFFF` terminator also holds a tempo) and a few more tempo
    fields (120 → 100, 250 → 208, 60 → 50, 150 → 125). The `.samp` data, the field, voice, crew,
    common and music banks are unchanged. `m0328.info`, `e6k006.info`, `e6p001.info` have a few
    other changed bytes (not tempos).
  * The cutscenes set to a stream (`field/me299a.sct` the intro, `me298a` / `me250a` `m03`) divide
    their waits and motion times by 1.2 (expression words `0x04000000 x 0x04000000 0x3F99999A 0x13`).
* **Japanese release (GEAJ8P): other voices, same layout.** All the voice files differ (streams
  `NNN`, `B702`, `KO`, `f71`, banks `stv`, `cr`, `e6`), most with other sizes; sequence counts match
  except `e6h011` / `k8900001` (one extra at the end). The other banks' `.info` files differ only in
  MusyX object IDs (numbered project-wide: the Japanese set has other counts), so a mix of USA and
  Japanese banks could collide; the music `.samp` data is identical. 30 of the 66 `KO` streams have
  other lengths (up to -1.6 / +1.2 s).

Open
----

* The (bank, num) lists of every music request are not enumerated: field/town/dungeon/event music is
  requested by scripts (compressed). A runtime log of `0x8021882C` gives the full table.
* `idx`/`flag` semantics of the list record when the first bank is negative (skip of pair 0) are read
  from the code, no call with a negative bank was found.
* Whether the DC's `sdMidiSetVol` volume scale equals the shim's `s8` (-127 = off) is assumed from the
  host protocol (`vol + 0x80` in the record).
* `s1000000` data 34..38 and the missing tail sequences in `m5NNNNNN` and `e6*` are assumed to be GC
  additions / removed empty ones, not checked event by event.
* The DC music streams `M03S`/`M04S` are not on DC disc 1.
* The stream channel and descriptor field names beyond the ones listed were not decoded.
* Which game moments use which `m5NNNNNN` file and numbers is not mapped (needs the scripts).
