"""Overrides for gen_rodata.py: the .rodata of game/unit_80199B9C.c (0x802B6A18-0x802B8EDC).

    python tools/match/gen_rodata.py 802B6A18 802B8EDC tools/match/rodata_80199B9C.py

EXTRA lists the base-register offsets the file's functions use that dtk has no symbol for (each is
an object start); OVERRIDES gives typed definitions (layout parts, number positions, tables) for
the objects the C code reads by field. The output expects the unit's LayoutPart, LayoutDef, LT,
AnimDef and ShopCmpPos types."""
import struct
def ff(v):
    for n in range(1, 12):
        t = "%.*g" % (n, v)
        if struct.pack(">f", float(t)) == struct.pack(">f", v):
            break
    if "e" in t and v == int(v) and abs(v) < 1e9:
        t = "%d" % v
    if "." not in t and "e" not in t:
        t += ".0"
    return t + "f"
def _b(a, n):
    return rd(a, n)
def layout(name, a, cnt):
    out = []
    for i in range(cnt):
        b = _b(a + i * 0x14, 0x14)
        bank, spr, x, y, z, tl, fl = struct.unpack(">HHfffHH", b)
        out.append("    {0x%X, 0x%X, %s, %s, %s, 0x%X, 0x%X}," % (bank, spr, ff(x), ff(y), ff(z), tl, fl))
    return "const LayoutPart %s[%d] = {\n%s\n};" % (name, cnt, "\n".join(out))
def fpairs(name, a, cnt):
    v = struct.unpack(">%df" % (cnt * 2), _b(a, cnt * 8))
    rows = ["    {%s, %s}," % (ff(v[2 * i]), ff(v[2 * i + 1])) for i in range(cnt)]
    return "const ShopCmpPos %s[%d] = {\n%s\n};" % (name, cnt, "\n".join(rows))
def s16s(name, a, cnt):
    v = struct.unpack(">%dh" % cnt, _b(a, cnt * 2))
    return "const s16 %s[%d] = {%s};" % (name, cnt, ", ".join("0x%X" % (x & 0xFFFF) if x >= 0 else str(x) for x in v))
OVERRIDES = {
    0x802B7140: layout("lbl_802B7140", 0x802B7140, 2),
    0x802B7168: layout("lbl_802B7168", 0x802B7168, 1),
    0x802B8E4C: fpairs("lbl_802B8E4C", 0x802B8E4C, 14),
    0x802B8EBC: s16s("lbl_802B8EBC", 0x802B8EBC, 8),
    0x802B8ECC: s16s("lbl_802B8ECC", 0x802B8ECC, 8),
}

import re as _re
_asm = open(R + "/build/GEAE8P/asm/auto_04_802AD360_rodata.s").read()
def _words(a, n):
    """The 4-byte words of [a, a+n): ints, or symbol names where dtk shows a relocation."""
    out = []
    for m in _re.finditer(r"^\.obj lbl_(\w{8}), \w+\n(.*?)^\.endobj", _asm, _re.S | _re.M):
        base = int(m.group(1), 16)
        lines = [x.strip().split()[1] for x in m.group(2).split("\n") if x.strip().startswith(".4byte")]
        for i, v in enumerate(lines):
            addr = base + 4 * i
            if a <= addr < a + n:
                out.append((addr, v))
    return [v if not v.startswith("0x") else int(v, 16) for _, v in sorted(out)]
def u8s(name, a, n):
    b = rd(a, n)
    rows = [", ".join("0x%02X" % x for x in b[i:i + 12]) for i in range(0, n, 12)]
    return "const u8 %s[0x%X] = {\n    %s,\n};" % (name, n, ",\n    ".join(rows))
def defs(tname, name, a, cnt, fields):
    w = _words(a, cnt * 4 * len(fields))
    rows = []
    for i in range(cnt):
        items = []
        for j, f in enumerate(fields):
            v = w[i * len(fields) + j]
            items.append(f(v))
        rows.append("    {%s}," % ", ".join(items))
    return "const %s %s[%d] = {\n%s\n};" % (tname, name, cnt, "\n".join(rows))
_ptr = lambda cast: (lambda v: "(%s)%s" % (cast, v) if isinstance(v, str) else "0")
_hex = lambda v: "0x%X" % v
def _hi(v): return "0x%X, 0x%X" % (v >> 16, v & 0xFFFF)
EXTRA = [0x802B6A18 + o for o in (0x728, 0x750, 0x241C, 0x2434, 0x24A4, 0x24B4, 0xD94, 0xDE4, 0xE7C, 0xFDC,
                                  0x1108, 0x1138, 0xCE8, 0x4C, 0x7D4, 0x8D8, 0x8EC, 0x764, 0x784)] + [0x802B79F4]
OVERRIDES.update({
    0x802B6B0C: layout("lbl_802B6B0C", 0x802B6B0C, 4),
    0x802B6DD0: layout("lbl_802B6DD0", 0x802B6DD0, 2),
    0x802B77AC: layout("lbl_802B77AC", 0x802B77AC, 1),
    0x802B7C14: layout("lbl_802B7C14", 0x802B7C14, 4),
    0x802B7720: u8s("lbl_802B7720", 0x802B7720, 0x50),
    0x802B6DF8: u8s("lbl_802B6DF8", 0x802B6DF8, 0x50),
    0x802B7BC4: u8s("lbl_802B7BC4", 0x802B7BC4, 0x3C),
    0x802B7C00: u8s("lbl_802B7C00", 0x802B7C00, 0x14),
    0x802B6D8C: u8s("lbl_802B6D8C", 0x802B6D8C, 0x14),
    0x802B79E4: defs("LayoutDef", "lbl_802B79E4", 0x802B79E4, 2, [_ptr("LayoutPart*"), _hex]),
    0x802B7B64: defs("LT", "lbl_802B7B64", 0x802B7B64, 6, [_ptr("void*"), _hex]),
    0x802B7B94: defs("LT", "lbl_802B7B94", 0x802B7B94, 6, [_ptr("void*"), _hex]),
    0x802B6DA0: defs("LT", "lbl_802B6DA0", 0x802B6DA0, 6, [_ptr("void*"), _hex]),
    0x802B73A4: defs("AnimDef", "lbl_802B73A4", 0x802B73A4, 5, [_ptr("LayoutPart*"), _hi, _hex, _hex]),
})
OVERRIDES.update({
    0x802B717C: defs("LT", "lbl_802B717C", 0x802B717C, 4, [_ptr("void*"), _hex]),
    0x802B719C: layout("lbl_802B719C", 0x802B719C, 4),
})
