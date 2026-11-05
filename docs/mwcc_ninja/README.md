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
- 0x569909, the same callback's operand test: `and edi,3 ; cmp edi,3` becomes `and edi,2 ; cmp edi,2`
  (see "Copies into a redefining instruction" below).
- .text VirtualSize is raised to its raw size so the stub is mapped, and one base-relocation block is
  appended for the stub's absolute operand (the build runs the compiler inside sjiswrap.exe, away from its
  preferred base).

Copies into a redefining instruction
------------------------------------

A second difference, in the same legality callback. The four colour setters (fn_80287124, fn_802871D8 and
their second-renderer twins fn_8028B6D4, fn_8028B784) scale each float parameter in its own register,
and fn_802911CC does the same for its z:

    fmuls f1, f1, f4           ; r *= 128.0f       (1.3.2: fmuls f5, f1, f4)
    fmr   f23, f1 ; fmadds f23, f23, f1, f0        ; z = z * k + c   (1.3.2: fmadds f23, f1, f2, f0)

For `x = y; x = x op z`, 1.3.2 propagates the copy into the second instruction (`x = y op z`) and the copy
dies, so x is coloured freely. Ninja keeps the copy; it then coalesces and x stays in y's register. The
callback (0x5698A0) already refuses to propagate into an instruction with an operand that both reads and
writes the copy's destination (the update forms, `(flags & 3) == 3` at 0x569909). In the compiler Ninja
was built with, any operand that writes the destination is enough (`(flags & 2) == 2`). That is one
constant in the same test, it applies to every copy-propagation run, and it keeps the two-address shape
the coalescer can use, which is the kind of choice a compiler makes on purpose.

How it was found: the copy-propagation callbacks traced under cdb (which copies each run applies, with the
mode and register class), then variants scored against every Ninja function (src/ninja plus the drafts in
docs/near). Rejected on the way, each losing existing matches:
- no coalescing with physical registers, coalescing named variables too, or not coalescing physical
  registers with named variables (31 to 194 lost, none gained);
- not propagating physical-register sources in every run, or in the loop-free run after value numbering
  (4FF8CD) only, for all classes or FPRs only (1 to 3 lost: fn_802913E8, fn_80296EEC, fn_80296BE4,
  fn_802A6398);
- extending 1.3.2's GPR-only "never rewrite into a parameter's register" rule to FPRs (no effect: float
  parameters aren't in the parameter range it uses).

With this change all 307 stock matches and all 69 earlier 1.3.2nj matches still match and the five above
match, so 74 functions match only with 1.3.2nj. It doesn't change the inline-argument copies (fn_802A1160
and the others): the copy of an unmodified local is gone before the PCode optimizer runs (knocking out
all sixteen copy-propagation calls, or the whole PCode optimizer, still gives one register), so no
backend change reaches it. Nor does it change the float scheduling of njSetAspect, njSetScreen,
fn_802992F8 or fn_8028B880, or fn_80297804's `mr. r0, r3`.

Checks
------

configure.py builds src/ninja/ninja.c (and only that unit) with GC/1.3.2nj; the patch runs as a
pre-compile step after the compilers download. `tools/verify_mwcc_ninja.py` rebuilds the patched compiler
and diffs every function in ninja.c with both compilers:

- All 277 functions in src/ninja/ninja.c that match with stock 1.3.2 still match.
- Four more match only with the patch, as plain C with the SDK's own GXVert.h inlines and the game's own
  vertex layouts: fn_8028A0F4, fn_80291064, fn_8029681C, fn_80298544 (25-36 lines off with stock 1.3.2).
- The full build agrees: objdiff counts 287 matching Ninja functions with stock 1.3.2 and 291 with
  1.3.2nj, the same 287 plus those four, and main.dol still rebuilds byte-identical.
- To diff Ninja code by hand, pass the compiler: `CCV=1.3.2nj tools/match/fdiff.py src/ninja/ninja.c FN`.
  objdiff has no decomp.me scratch preset for the unit (decomp.me has no 1.3.2nj).
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
  can test it with `docs/near/fifo_8029681C.c` (no headers) or the four functions above.
- **Two models fit equally well** so far: block-local propagation in the late run, and a pessimistic
  available-copies start in the late run only. They differ only for a copy used in a later block that isn't
  deeper in a loop; nothing in the Ninja code matched so far tells them apart. The patch uses the simpler one.
- fn_802A1160 still differs: the original also keeps preheader copies of values loaded before the loop,
  which 1.3.2's coalescing merges. That may be a second difference.
