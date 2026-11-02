#include "ninja_lib.h"

#pragma opt_propagation off
void fn_802A02E8(s16* p_, u32* data_, s32 hdr_, s32 side) {
    u32* col;
    s32 nuv;
    u32* data;
    s32 len;
    s32 total;
    u32 c;
    s16 idx;
    u32 mode;
    u32 cull = -1;
    s32 hdr;
    s16* p;
    hdr = hdr_;
    data = data_;
    p = p_;

    GXClearVtxDesc();
    GXSetVtxDesc(GX_VA_POS, GX_INDEX16);
    GXSetVtxDesc(GX_VA_NRM, GX_INDEX16);
    GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
    GXSetVtxDesc(GX_VA_TEX1, GX_DIRECT);
    GXSetVtxAttrFmt(GX_VTXFMT4, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    GXSetVtxAttrFmt(GX_VTXFMT4, GX_VA_NRM, GX_NRM_XYZ, GX_F32, 0);
    GXSetVtxAttrFmt(GX_VTXFMT4, GX_VA_TEX0, GX_TEX_ST, GX_S16, 8);
    GXSetVtxAttrFmt(GX_VTXFMT4, GX_VA_TEX1, GX_TEX_ST, GX_S16, 8);
    nuv = (hdr & 0xc000) >> 14;
    hdr &= 0x3fff;
    total = 0;
    GXSetArray(GX_VA_POS, data, 0x1c);
    GXSetArray(GX_VA_NRM, data + 3, 0x1c);
    col = data + 6;
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
        GXBegin(GX_TRIANGLESTRIP, GX_VTXFMT4, len);
        do {
            idx = *p++;
            p += nuv + 2;
            GXPosition1x16(idx);
            GXNormal1x16(idx);
            c = col[idx * 7];
            GXTexCoord2s16((c >> 8) & 0xff, (c >> 16) & 0xff);
            GXTexCoord2s16(c >> 24, c & 0xff);
        } while (--len);
    } while (--hdr);
    lbl_80347EF0 += total;
}
#pragma opt_propagation reset
