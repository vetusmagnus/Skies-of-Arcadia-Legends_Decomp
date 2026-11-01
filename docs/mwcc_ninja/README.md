The Ninja library's compiler: a patched GC/1.3.2
================================================

Skies of Arcadia Legends links Sega's Ninja graphics library (0x80286EE8-0x802AC75C). About 30 of its
functions could not be matched with any public compiler. This directory and `tools/patch_mwcc_ninja.py`
describe a one-pass difference that reproduces them, how it was found, and how it was checked.

The shape no compiler produced
------------------------------

A value hoisted out of a loop is shared by its first two uses, and every later use gets its own `mr` copy:

    lis r30, 0xcc01            ; GX FIFO address, hoisted out of the loop
    mr  r31, r30
    loop:
      stfs f0, -0x8000(r30)    ; x
      stfs f1, -0x8000(r30)    ; y
      stfs f2, -0x8000(r31)    ; z

The same shape appears for constants (`li r9,0; mr r7,r9; mr r6,r9; mr r5,r9` in fn_80298544's leftover loop)
and data addresses. Every GC and Wii build in the decomp.dev bundle, GC/1.2.5e on decomp.me and SN ProDG
merge the copies into one register, with any optimization level, `-opt` switch or recognised pragma, and
with about 100 source forms (docs/ninja.md lists them).

Where it comes from
-------------------

1.3.2's PCode optimizer runs copy propagation (AddPropagation.c) eleven times. Found in two steps:

1. **Pass knock-outs.** Replacing each pass call in the PCode optimizer driver (0x4FF6A0) and the backend
   driver (0x433C60) with NOPs, one at a time, and recompiling two test functions: only skipping the copy
   propagation right after VALUE NUMBERING 2 (call at 0x4FFA18) produces the shape, in both test cases,
   with every other instruction unchanged.
2. **PCode dumps.** The pass listings are compiled out of the release build, so the PCode was read from
   memory under gdb (a trap at the pass entry; the block, instruction and operand layouts match the
   public MWCC reconstructions). Value numbering 2 turns the re-materialised `lis`/`li` in a loop
   preheader into `mr` copies of the first one; the copy propagation that follows rewrites their uses
   inside the loop, so they vanish. When the copies survive, the register allocator does the rest: a
   copy's destination doesn't interfere with its source, so the first copy coalesces into the source and
   the next ones interfere with the merged register. That is exactly "first two share, later uses get a
   copy"; the allocator needs no change.

What Ninja needs from that one run is propagation within a block only. Earlier runs must stay global:
source-level copies such as `u8 type = n;` in fn_802A1374/fn_802A7894 are propagated into loops by the
first runs, and the Ninja code shows that.

The patch
---------

`tools/patch_mwcc_ninja.py` turns stock GC/1.3.2 (Version 2.4.2 build 81, SHA-1
d8f9c36d62f66c2a044d5a20a132b79eeb2f36e5) into `build/compilers/GC/1.3.2nj`:

- 0x4FFA15: that call passes mode 2 instead of 1 (`push 1` -> `push 2`). Copy propagation stores the mode
  in 0x5E1C00 and otherwise only tests it against zero, so every other behaviour is unchanged.
- 0x5699B0, the cross-block path of the propagation legality callback (0x5698A0): a jump to a 5-instruction
  stub in the unused tail of .text that answers "can't propagate" in mode 2 and otherwise runs the two
  overwritten instructions and returns.
- .text VirtualSize is raised to its raw size so the stub is mapped, and one base-relocation block is
  appended for the stub's absolute operand (the build runs the compiler inside sjiswrap.exe, away from its
  preferred base).

Checks
------

`tools/verify_mwcc_ninja.py` rebuilds the patched compiler and diffs every function:

- All 277 functions in src/ninja/ninja.c that match with stock 1.3.2 still match.
- The four files here match as plain C, with the SDK's own GXVert.h inlines and the game's own vertex
  layouts; with stock 1.3.2 they are 25-36 lines off.
- Stock GC/1.3 matches 269 of the 277 and 1.2.5n 53, so 1.3.2 is the closest public base.

Alternatives that were ruled out, each against all 277 functions: dropping the late run entirely (255),
block-local or loop-weight-limited propagation in every run (274/275), a pessimistic available-copies start
in every run (275), no register coalescing (146).

Scope and open questions
------------------------

- **Ninja only.** Building the whole game with the patched compiler changes 145 game and library functions,
  so the game was compiled with stock behaviour and Ninja, a library Sega shipped prebuilt, with a different
  compiler. The project already uses per-library compilers (OSReport with 1.2.5n, MusyX, the SDK).
- **Which compiler that was** isn't known. The compiler hunt lists CW 1.3.1 (between 1.3 build 53 and 1.3.2
  build 81) as missing; a build from that window is a natural candidate. Anyone with another 1.3-era build
  can test it with the four files here (no headers needed beyond the repo's).
- **Two models fit equally well** so far: block-local propagation in the late run, and a pessimistic
  available-copies start in the late run only. They differ only for a copy used in a later block that isn't
  deeper in a loop; nothing in the Ninja code matched so far tells them apart. The patch uses the simpler one.
- fn_802A1160 still differs: the original also keeps preheader copies of values loaded before the loop,
  which 1.3.2's coalescing merges. That may be a second difference.
