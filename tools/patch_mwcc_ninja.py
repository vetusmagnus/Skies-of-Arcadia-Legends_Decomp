#!/usr/bin/env python3
"""Build GC/1.3.2nj: GC/1.3.2 with the late copy propagation the Ninja library was built with.

usage: tools/patch_mwcc_ninja.py [SRC_DIR] [DST_DIR]
       (defaults: build/compilers/GC/1.3.2 -> build/compilers/GC/1.3.2nj)

What it models. 1.3.2's PCode optimizer runs copy propagation (AddPropagation.c) eleven times.
The run right after VALUE NUMBERING 2 (driver call at 0x4FFA18) removes the `mr` copies value
numbering makes of loop invariants that code motion and the loop transformations re-created in
a loop's preheader. The Ninja code in main.dol keeps those copies, and the register allocator
then gives every use after the second its own register:
    lis r30,0xcc01 ; mr r31,r30 ; stfs ..(r30) ; stfs ..(r30) ; stfs ..(r31)
Everything else Ninja needs from that run is propagation within a block. So in the compiler
Ninja was built with, copy propagation after VALUE NUMBERING 2 was block-local. All other runs
are stock. Evidence and the method (pass knock-outs, PCode dumps under gdb): docs/ninja.md,
"Copy pattern".

The patch:
  * 0x4FFA15: that one call passes mode 2 instead of 1 (`push 1` -> `push 2`). The mode is
    stored in 0x5E1C00, which the rest of copy propagation only tests for zero, so 2 behaves
    exactly like 1 everywhere else.
  * 0x5699B0, the cross-block path of the legality callback (0x5698A0): jump to a stub in the
    unused tail of .text (0x57D5C0) that answers "can't propagate" when the mode is 2, otherwise
    runs the two overwritten instructions and jumps back. .text's VirtualSize is raised to its
    raw size so the stub is mapped.
"""
import hashlib
import os
import shutil
import struct
import sys

STOCK_SHA1 = "d8f9c36d62f66c2a044d5a20a132b79eeb2f36e5"  # GC/1.3.2, Version 2.4.2 build 81

TEXT_VA, TEXT_RAW = 0x401000, 0x400  # .text virtual address and file offset in this build
LATE_CALL_MODE = 0x4FFA15              # push 1 ; push ebx ; call 0x569780 (after VALUE NUMBERING 2)
SITE, CAVE, RET0, BACK = 0x5699B0, 0x57D5C0, 0x5699DA, 0x5699B7
MODE = 0x5E1C00                        # copy propagation's mode, set by 0x569780 from its argument


def off(va):
    return va - TEXT_VA + TEXT_RAW


def rel32(next_va, dst):
    return struct.pack("<i", dst - next_va)


def patch(data):
    d = bytearray(data)
    o = off(LATE_CALL_MODE)
    if d[o:o + 8] != bytes.fromhex("6a0153e8639d0600"):
        sys.exit("unexpected bytes at the late copy-propagation call: not GC/1.3.2 build 81?")
    d[o + 1] = 2
    o = off(SITE)
    if d[o:o + 7] != bytes.fromhex("8b6c241cc1fd05"):
        sys.exit("unexpected bytes at the patch site: not GC/1.3.2 build 81?")
    stub = bytearray()
    stub += b"\x83\x3d" + struct.pack("<I", MODE) + b"\x02"   # cmp dword [MODE],2
    stub += b"\x0f\x84" + rel32(CAVE + len(stub) + 6, RET0)   # je  -> "can't propagate"
    stub += bytes.fromhex("8b6c241c")                         # mov ebp,[esp+0x1c] (overwritten)
    stub += bytes.fromhex("c1fd05")                           # sar ebp,5          (overwritten)
    stub += b"\xe9" + rel32(CAVE + len(stub) + 5, BACK)       # jmp back
    co = off(CAVE)
    if any(d[co:co + len(stub)]):
        sys.exit("code cave is not empty")
    d[co:co + len(stub)] = stub
    d[o:o + 7] = b"\xe9" + rel32(SITE + 5, CAVE) + b"\x66\x90"
    pe = struct.unpack_from("<I", d, 0x3C)[0]
    nsec = struct.unpack_from("<H", d, pe + 6)[0]
    opt = struct.unpack_from("<H", d, pe + 20)[0]
    image_base = struct.unpack_from("<I", d, pe + 24 + 28)[0]
    for i in range(nsec):
        h = pe + 24 + opt + i * 40
        if d[h:h + 5] == b".text":
            # VirtualSize := SizeOfRawData so the stub is mapped
            struct.pack_into("<I", d, h + 8, struct.unpack_from("<I", d, h + 16)[0])
        if d[h:h + 6] == b".reloc":
            # The stub's absolute operand needs a base relocation: the build runs the compiler
            # inside sjiswrap.exe, which loads it away from its preferred base. Append one block
            # (page, size 12, HIGHLOW entry, padding) in the section's unused raw tail.
            vsize, raw, rawptr = (struct.unpack_from("<I", d, h + o)[0] for o in (8, 16, 20))
            target = CAVE + 2 - image_base  # RVA of the cmp's address operand
            block = struct.pack("<IIHH", target & ~0xFFF, 12, 0x3000 | (target & 0xFFF), 0)
            if vsize + len(block) > raw or any(d[rawptr + vsize:rawptr + vsize + len(block)]):
                sys.exit("no room for the relocation block")
            d[rawptr + vsize:rawptr + vsize + len(block)] = block
            struct.pack_into("<I", d, h + 8, vsize + len(block))
            ddir = pe + 24 + 96 + 5 * 8  # IMAGE_DIRECTORY_ENTRY_BASERELOC
            if struct.unpack_from("<I", d, ddir + 4)[0] != vsize:
                sys.exit("unexpected relocation directory size")
            struct.pack_into("<I", d, ddir + 4, vsize + len(block))
    return bytes(d)


def main():
    src = sys.argv[1] if len(sys.argv) > 1 else "build/compilers/GC/1.3.2"
    dst = sys.argv[2] if len(sys.argv) > 2 else "build/compilers/GC/1.3.2nj"
    data = open(os.path.join(src, "mwcceppc.exe"), "rb").read()
    if hashlib.sha1(data).hexdigest() != STOCK_SHA1:
        sys.exit("mwcceppc.exe is not the expected GC/1.3.2 build")
    os.makedirs(dst, exist_ok=True)
    for name in os.listdir(src):
        if name != "mwcceppc.exe":
            shutil.copy(os.path.join(src, name), dst)
    out = patch(data)
    open(os.path.join(dst, "mwcceppc.exe"), "wb").write(out)
    print(f"wrote {dst}/mwcceppc.exe (sha1 {hashlib.sha1(out).hexdigest()})")


if __name__ == "__main__":
    main()
