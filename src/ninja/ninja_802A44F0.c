/* Sega Ninja library, 0x802A44F0-0x802A4C20. Strip drawer file ending with fn_802A49F4, the owner
 * of the lone 65.0f at 0x8034D3A0. */

#include "ninja_lib.h"

/* Strip drawer files keep a single-use vertex load in source order where the rest of Ninja lets IRO
 * expression propagation forward it and drop the assignment (docs/ninja.md, "Strip drawer files").
 * `opt_propagation off` fits equally well. */
#pragma opt_dead_assignments off

void fn_802A44F0(s16* p, NjColVtx* v, u32 hdr, s32 side) {
    s32 len;
    s32 total;
    u32 cull = -1;
    s32 nuv;
    u32 mode;
    NjColVtx* q;
    f32 x, y, z;
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
            x = q->x;
            y = q->y;
            z = q->z;
            c = q->col;
            GXPosition3f32(x, y, z);
            GXNormal3f32(x, y, z);
            GXTexCoord2s16((c >> 8) & 0xff, (c >> 16) & 0xff);
            GXTexCoord2s16(c >> 24, c & 0xff);
        } while (--len);
    } while (--hdr);
    lbl_80347EF0 += total;
}

void fn_802A46EC(s16* p, NjColVtx* v, u32 hdr, s32 side) {
    s32 len;
    s32 total;
    u32 cull = -1;
    s32 nuv;
    u32 mode;
    NjColVtx* q;
    f32 x, y, z;
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
            x = q->x;
            y = q->y;
            z = q->z;
            c = q->col;
            GXPosition3f32(x, y, z);
            GXNormal3f32(x, y, z);
            GXColor1u32(c);
        } while (--len);
    } while (--hdr);
    lbl_80347EF0 += total;
}

void fn_802A4884(s16* p, NJS_POINT3* v, u32 hdr, s32 side) {
    s32 len;
    s32 total;
    u32 cull = -1;
    s32 nuv;
    u32 mode;
    NJS_POINT3* q;
    f32 x, y, z;
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
            x = q->x;
            y = q->y;
            z = q->z;
            GXPosition3f32(x, y, z);
            GXNormal3f32(x, y, z);
        } while (--len);
    } while (--hdr);
    lbl_80347EF0 += total;
}

void fn_802A49F4(s16* p, NjPosNrm* v, s32 hdr, s32 side, f32 scale) {
    u32 mode;
    s32 nuv;
    s32 len;
    s32 total;
    GXVtxFmt fmt;
    u32 cull = -1;
    NjPosNrm* q;
    u16 i;
    f32 x, y, z;
    f32 nx, ny, nz;

    fn_8029B1E0(GX_DIRECT, GX_DIRECT, GX_INDEX16);
    nuv = (hdr >> 14) & 3;
    hdr &= 0x3fff;
    total = 0;
    if (scale == 65.0f) {
        fmt = GX_VTXFMT2;
        GXSetVtxAttrFmt(GX_VTXFMT2, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
        GXSetVtxAttrFmt(GX_VTXFMT2, GX_VA_NRM, GX_NRM_XYZ, GX_F32, 0);
        GXSetVtxAttrFmt(GX_VTXFMT2, GX_VA_TEX0, GX_TEX_ST, GX_S16, 8);
    } else {
        fmt = GX_VTXFMT3;
        GXSetVtxAttrFmt(GX_VTXFMT3, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
        GXSetVtxAttrFmt(GX_VTXFMT3, GX_VA_NRM, GX_NRM_XYZ, GX_F32, 0);
        GXSetVtxAttrFmt(GX_VTXFMT3, GX_VA_TEX0, GX_TEX_ST, GX_S16, 10);
    }
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
            GXTexCoord1x16(i);
            i++;
        } while (--len);
    } while (--hdr);
    lbl_80347EF0 += total;
}
