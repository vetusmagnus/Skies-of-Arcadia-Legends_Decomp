/* Sega Ninja library, 0x802A5530-0x802A5A58. Strip drawers after the last 65.0f pool (no
 * constants, so the file edges inside this range are unknown). */

#include "ninja_lib.h"

/* Strip drawer files keep a single-use vertex load in source order where the rest of Ninja lets IRO
 * expression propagation forward it and drop the assignment (docs/ninja.md, "Strip drawer files").
 * `opt_propagation off` fits equally well. */
#pragma opt_dead_assignments off

void fn_802A5530(s16* p, NjPosNrmCol* v, u32 hdr, s32 side) {
    s32 len;
    s32 total;
    u32 cull = -1;
    s32 nuv;
    u32 mode;
    NjPosNrmCol* q;
    f32 x, y, z;
    f32 nx, ny, nz;
    u32 c;

    GXClearVtxDesc();
    GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
    GXSetVtxDesc(GX_VA_NRM, GX_DIRECT);
    GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
    GXSetVtxDesc(GX_VA_TEX1, GX_DIRECT);
    GXSetVtxAttrFmt(GX_VTXFMT4, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    GXSetVtxAttrFmt(GX_VTXFMT4, GX_VA_NRM, GX_NRM_XYZ, GX_F32, 0);
    GXSetVtxAttrFmt(GX_VTXFMT4, GX_VA_TEX0, GX_TEX_ST, GX_S16, 8);
    GXSetVtxAttrFmt(GX_VTXFMT4, GX_VA_TEX1, GX_TEX_ST, GX_S16, 8);
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
        GXBegin(GX_TRIANGLESTRIP, GX_VTXFMT4, len);
        do {
            q = &v[*p++];
            p += nuv + 2;
            x = q->pos.x;
            y = q->pos.y;
            z = q->pos.z;
            nx = q->nrm.x;
            ny = q->nrm.y;
            nz = q->nrm.z;
            c = q->col;
            GXPosition3f32(x, y, z);
            GXNormal3f32(nx, ny, nz);
            GXTexCoord2s16((c >> 8) & 0xff, (c >> 16) & 0xff);
            GXTexCoord2s16(c >> 24, c & 0xff);
        } while (--len);
    } while (--hdr);
    lbl_80347EF0 += total;
}

void fn_802A5738(s16* p, NjPosNrmCol* v, u32 hdr, s32 side) {
    s32 len;
    s32 total;
    u32 cull = -1;
    s32 nuv;
    u32 mode;
    NjPosNrmCol* q;
    f32 x, y, z;
    f32 nx, ny, nz;
    u32 c;

    fn_8029AFF0(1, 1, 1);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_NRM, GX_NRM_XYZ, GX_F32, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);
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
            c = q->col;
            GXPosition3f32(x, y, z);
            GXNormal3f32(nx, ny, nz);
            GXColor1u32(c);
        } while (--len);
    } while (--hdr);
    lbl_80347EF0 += total;
}

void fn_802A58DC(s16* p, NjPosNrm* v, u32 hdr, s32 side) {
    s32 len;
    s32 total;
    u32 cull = -1;
    s32 nuv;
    u32 mode;
    NjPosNrm* q;
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
