/* Sega Ninja library, 0x802A4E4C-0x802A5530. Strip drawer file ending with fn_802A4FC8 and
 * fn_802A52C4, which share the lone 65.0f at 0x8034D3B0. */

#include "ninja_lib.h"

/* Strip drawer files keep a single-use vertex load in source order where the rest of Ninja lets IRO
 * expression propagation forward it and drop the assignment (docs/ninja.md, "Strip drawer files").
 * `opt_propagation off` fits equally well. */
#pragma opt_dead_assignments off

void fn_802A4E4C(s16* p, NjPosNrmCol* v, u32 hdr, s32 side) {
    s32 len;
    s32 total;
    u32 cull = -1;
    s32 nuv;
    u32 mode;
    NjPosNrmCol* q;
    f32 x, y, z;
    f32 nx, ny, nz;

    fn_8029B058(1, 1);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_NRM, GX_NRM_XYZ, GX_F32, 0);
    total = 0;
    nuv = (hdr >> 14) & 3;
    hdr &= 0x3fff;
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
        GXBegin(GX_TRIANGLESTRIP, GX_VTXFMT0, len);
        do {
            q = &v[*p++];
            p += nuv + 2;
            x = q->pos.x;
            y = q->pos.y;
            z = q->pos.z;
            nx = q->nrm.x;
            ny = q->nrm.y;
            nz = q->nrm.z;
            GXPosition3f32(x, y, z);
            GXNormal3f32(nx, ny, nz);
        } while (--len);
    } while (--hdr);
    lbl_80347EF0 += total;
}
