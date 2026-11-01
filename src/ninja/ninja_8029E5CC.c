/* Sega Ninja library, 0x8029E5CC-0x8029EA5C. Drawer file: fn_8029E5CC and fn_8029E850 share the
 * lone 65.0f at 0x8034D340. fn_8029E5CC is not matched yet (register allocation only). */

#include "ninja_lib.h"

void fn_8029E850(s16* p, u32* data, s32 hdr, s32 side, f32 scale) {
    u32 mode;
    s32 nuv;
    s32 len;
    s32 total;
    GXVtxFmt fmt;
    u32 cull = -1;
    u16 i;
    s16 idx;

    fn_8029B0A8(GX_INDEX16, GX_INDEX16, GX_INDEX16);
    nuv = (hdr >> 14) & 3;
    hdr &= 0x3fff;
    total = 0;
    if (scale == 65.0f) {
        fmt = GX_VTXFMT2;
        GXSetVtxAttrFmt(GX_VTXFMT2, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
        GXSetVtxAttrFmt(GX_VTXFMT2, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);
        GXSetVtxAttrFmt(GX_VTXFMT2, GX_VA_TEX0, GX_TEX_ST, GX_S16, 8);
    } else {
        fmt = GX_VTXFMT3;
        GXSetVtxAttrFmt(GX_VTXFMT3, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
        GXSetVtxAttrFmt(GX_VTXFMT3, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);
        GXSetVtxAttrFmt(GX_VTXFMT3, GX_VA_TEX0, GX_TEX_ST, GX_S16, 10);
    }
    GXSetArray(GX_VA_POS, data, 0x10);
    GXSetArray(GX_VA_CLR0, data + 3, 0x10);
    do {
        len = *p++;
        if (len < 0) {
            len = -len;
            mode = lbl_80300898[side][lbl_80347E20];
            if (cull != mode) {
                cull = mode;
                GXSetCullMode(mode);
            }
        } else {
            mode = lbl_803008C0[side][lbl_80347E20];
            if (cull != mode) {
                cull = mode;
                GXSetCullMode(mode);
            }
        }
        total += len;
        GXSetArray(GX_VA_TEX0, p + 1, 6);
        GXBegin(GX_TRIANGLESTRIP, fmt, len);
        i = 0;
        do {
            idx = *p++;
            p += nuv + 2;
            GXPosition1x16(idx);
            GXColor1x16(idx);
            GXTexCoord1x16(i);
            i++;
        } while (--len);
    } while (--hdr);
    lbl_80347EF0 += total;
}
