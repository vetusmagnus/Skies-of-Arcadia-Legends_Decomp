#!/usr/bin/env python3
"""Build GC/1.3.2nj: GC/1.3.2 with the copy propagation Sega's Ninja library was built with.

usage: tools/patch_mwcc_ninja.py [SRC_DIR] [DST_DIR]
       (defaults: build/compilers/GC/1.3.2 -> build/compilers/GC/1.3.2nj)

Stock 1.3.2 propagates a copy into any later block where it's still available. The Ninja code in
main.dol shows the original compiler did not propagate a copy into a block with a higher loop
weight than the copy's own block, so hoisted loop invariants keep their `mr` copies:
    lis r30,0xcc01 ; mr r31,r30 ; stfs ..(r30) ; stfs ..(r30) ; stfs ..(r31)
See docs/ninja.md, "Copy pattern solved".

The patch, in the copy-propagation legality callback (0x5698A0, AddPropagation.c): the
different-block path at 0x5699B0 jumps to a stub in the unused tail of .text (0x57D5C0) that
returns "can't propagate" when use_block->loop_weight (+0x24) > copy_block->loop_weight, then
runs the two overwritten instructions and jumps back. .text's VirtualSize is raised to its raw
size so the stub is mapped. 43 bytes change in all (39 of code, 4 in the section header).
"""
import hashlib
import os
import shutil
import struct
import sys

STOCK_SHA1 = "d8f9c36d62f66c2a044d5a20a132b79eeb2f36e5"

TEXT_VA, TEXT_RAW = 0x401000, 0x400  # .text virtual address and file offset in this build
SITE, CAVE, RET0, BACK = 0x5699B0, 0x57D5C0, 0x5699DA, 0x5699B7


def off(va):
    return va - TEXT_VA + TEXT_RAW


def rel32(next_va, dst):
    return struct.pack("<i", dst - next_va)


def patch(data):
    d = bytearray(data)
    o = off(SITE)
    if d[o:o + 7] != bytes.fromhex("8b6c241cc1fd05"):
        sys.exit("unexpected bytes at the patch site: not GC/1.3.2 (2.4.2 build 81)?")
    stub = bytearray()
    stub += bytes.fromhex("8b0424")    # mov eax,[esp]        ; the copy instruction
    stub += bytes.fromhex("8b4008")    # mov eax,[eax+8]      ; its block
    stub += bytes.fromhex("8b4c2404")  # mov ecx,[esp+4]      ; the use's block
    stub += bytes.fromhex("8b4024")    # mov eax,[eax+0x24]   ; copy block loop weight
    stub += bytes.fromhex("394124")    # cmp [ecx+0x24],eax
    stub += b"\x0f\x8f" + rel32(CAVE + len(stub) + 6, RET0)  # jg: use is deeper -> don't propagate
    stub += bytes.fromhex("8b6c241c")  # mov ebp,[esp+0x1c]   ; overwritten instructions
    stub += bytes.fromhex("c1fd05")    # sar ebp,5
    stub += b"\xe9" + rel32(CAVE + len(stub) + 5, BACK)
    co = off(CAVE)
    if any(d[co:co + len(stub)]):
        sys.exit("code cave is not empty")
    d[co:co + len(stub)] = stub
    d[o:o + 7] = b"\xe9" + rel32(SITE + 5, CAVE) + b"\x66\x90"
    # .text section header: VirtualSize := SizeOfRawData so the stub is mapped
    pe = struct.unpack_from("<I", d, 0x3C)[0]
    nsec = struct.unpack_from("<H", d, pe + 6)[0]
    opt = struct.unpack_from("<H", d, pe + 20)[0]
    for i in range(nsec):
        h = pe + 24 + opt + i * 40
        if d[h:h + 5] == b".text":
            struct.pack_into("<I", d, h + 8, struct.unpack_from("<I", d, h + 16)[0])
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
    open(os.path.join(dst, "mwcceppc.exe"), "wb").write(patch(data))
    print(f"wrote {dst}/mwcceppc.exe")


if __name__ == "__main__":
    main()
