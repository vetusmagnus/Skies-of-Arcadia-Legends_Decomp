"""Overrides for gen_rodata.py: the .rodata of game/unit_801C5A60.c (0x802C3C20-0x802C4180).

    python tools/match/gen_rodata.py 802C3C20 802C4180 tools/match/rodata_801C5A60.py

fn_801C8DF0 and fn_801C9198 (the ending's picture show) reach these through the section base
(`addi rN, rBase, 0x2e0` and so on), so the objects must sit at their original offsets. EXTRA
lists the starts dtk has no symbol for; OVERRIDES types the sprite records, the picture tile
table, the tile sizes and the file names. The output expects the unit's Rect8 type."""
import struct


def ff(v):
    for n in range(1, 12):
        t = "%.*g" % (n, v)
        if struct.pack(">f", float(t)) == struct.pack(">f", v):
            break
    if "." not in t and "e" not in t:
        t += ".0"
    return t + "f"


def sprites(name, a, cnt):
    out = []
    for i in range(cnt):
        tex, x, y, w, h, u0, v0, u1, v1 = struct.unpack(">i8f", rd(a + i * 0x24, 0x24))
        out.append("    {%d, %s, %s, %s, %s, %s, %s, %s, %s}," % (tex, ff(x), ff(y), ff(w), ff(h), ff(u0), ff(v0), ff(u1), ff(v1)))
    return "const Rect8 %s[%d] = {\n%s\n};" % (name, cnt, "\n".join(out))


def tiles(name, a, cnt):
    out = []
    for i in range(cnt):
        v = struct.unpack(">8H", rd(a + i * 16, 16))
        out.append("    {" + ", ".join(str(x) for x in v) + "},")
    return "const u16 %s[%d][8] = {\n%s\n};" % (name, cnt, "\n".join(out))


def sizes(name, a, cnt):
    v = struct.unpack(">%df" % (cnt * 2), rd(a, cnt * 8))
    out = ["    {%s, %s}," % (ff(v[2 * i]), ff(v[2 * i + 1])) for i in range(cnt)]
    return "const f32 %s[%d][2] = {\n%s\n};" % (name, cnt, "\n".join(out))


def string(name, a, size):
    b = rd(a, size)
    s = b.split(b"\0")[0].decode()
    return 'const char %s[%d] = "%s";' % (name, size, s)


EXTRA = [0x802C3F00, 0x802C4120, 0x802C4138, 0x802C4148, 0x802C415C, 0x802C4170]
OVERRIDES = {
    0x802C3C20: sprites("lbl_802C3C20", 0x802C3C20, 18),
    0x802C3EA8: "const s32 lbl_802C3EA8[22] = {\n    "
    + ", ".join("0x%X" % x for x in struct.unpack(">22i", rd(0x802C3EA8, 0x58))) + ",\n};",
    0x802C3F00: tiles("lbl_802C3F00", 0x802C3F00, 34),
    0x802C4120: sizes("lbl_802C4120", 0x802C4120, 3),
    0x802C4138: string("lbl_802C4138", 0x802C4138, 0x10),
    0x802C4148: string("lbl_802C4148", 0x802C4148, 0x14),
    0x802C415C: string("lbl_802C415C", 0x802C415C, 0x14),
    0x802C4170: string("lbl_802C4170", 0x802C4170, 0x10),
}
