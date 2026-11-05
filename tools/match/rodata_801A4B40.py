"""Overrides for gen_rodata.py: the .rodata of game/unit_801A4B40.c (0x802B4A00-0x802B6A18).

    python tools/match/gen_rodata.py 802B4A00 802B6A18 tools/match/rodata_801A4B40.py

Reuses the helpers of rodata_80199B9C.py. The output expects the shop header's LayoutPart, LayoutDef,
PanelStart and ShopSlotPos types."""
exec(open(R + "/tools/match/rodata_80199B9C.py").read())


def slotpos(name, a, cnt):
    rows = []
    for i in range(cnt):
        idx, _, x, x2 = struct.unpack(">HHff", rd(a + i * 12, 12))
        rows.append("    {0x%X, %s, %s}," % (idx, ff(x), ff(x2)))
    return "const ShopSlotPos %s[%d] = {\n%s\n};" % (name, cnt, "\n".join(rows))


def panelstart(name, a, cnt):
    rows = []
    for i in range(cnt):
        v = struct.unpack(">6f", rd(a + i * 24, 24))
        rows.append("    {%s}," % ", ".join(ff(x) for x in v))
    return "const PanelStart %s[%d] = {\n%s\n};" % (name, cnt, "\n".join(rows))


def strptrs(name, a, cnt):
    rows = ["    %s," % (v if isinstance(v, str) else "0") for v in _words(a, cnt * 4)]
    return "const char* const %s[%d] = {\n%s\n};" % (name, cnt, "\n".join(rows))


def u16s(name, a, cnt):
    v = struct.unpack(">%dH" % cnt, rd(a, cnt * 2))
    return "const u16 %s[%d] = {%s};" % (name, cnt, ", ".join("0x%X" % x for x in v))


EXTRA = [0x802B4A64, 0x802B4AA0, 0x802B4B2C, 0x802B4DC8]
OVERRIDES = {}
for _a, _n in ((0x802B4A00, 2), (0x802B4A28, 3), (0x802B4A64, 3), (0x802B4AA0, 1), (0x802B4AB4, 1), (0x802B4AC8, 2),
               (0x802B4AF0, 1), (0x802B4B04, 2), (0x802B4B4C, 3), (0x802B4B88, 1), (0x802B4B9C, 6), (0x802B4C14, 11),
               (0x802B4CF0, 5), (0x802B4D54, 5)):
    OVERRIDES[_a] = layout("lbl_%08X" % _a, _a, _n)
OVERRIDES[0x802B4B2C] = defs("LayoutDef", "lbl_802B4B2C", 0x802B4B2C, 4, [_ptr("LayoutPart*"), _hex])
OVERRIDES[0x802B4DB8] = defs("LayoutDef", "lbl_802B4DB8", 0x802B4DB8, 2, [_ptr("LayoutPart*"), _hex])
OVERRIDES[0x802B6810] = strptrs("lbl_802B6810", 0x802B6810, 51)
OVERRIDES[0x802B690C] = panelstart("lbl_802B690C", 0x802B690C, 7)
OVERRIDES[0x802B69B4] = u16s("lbl_802B69B4", 0x802B69B4, 6)
OVERRIDES[0x802B69E8] = slotpos("lbl_802B69E8", 0x802B69E8, 4)
