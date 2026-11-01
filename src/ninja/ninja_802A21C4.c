/* Sega Ninja library, 0x802A21C4-0x802A3D08. Strip drawer file ending with fn_802A3B34, the owner
 * of the lone 65.0f at 0x8034D388. */

#include "ninja_lib.h"

/* Strip drawer files keep a single-use vertex load in source order where the rest of Ninja lets IRO
 * expression propagation forward it and drop the assignment (docs/ninja.md, "Strip drawer files").
 * `opt_propagation off` fits equally well. */
#pragma opt_dead_assignments off

asm void fn_802A21C4(register s32 n, register NJS_VECTOR* dst, register NJS_VECTOR* src) {
    nofralloc
    stwu r1, -0x130(r1)
    stfd f31, 0x120(r1)
    psq_st f31, 0x128(r1), 0, 0
    stfd f30, 0x110(r1)
    psq_st f30, 0x118(r1), 0, 0
    stfd f29, 0x100(r1)
    psq_st f29, 0x108(r1), 0, 0
    stfd f28, 0xf0(r1)
    psq_st f28, 0xf8(r1), 0, 0
    stfd f27, 0xe0(r1)
    psq_st f27, 0xe8(r1), 0, 0
    stfd f26, 0xd0(r1)
    psq_st f26, 0xd8(r1), 0, 0
    stfd f25, 0xc0(r1)
    psq_st f25, 0xc8(r1), 0, 0
    stfd f24, 0xb0(r1)
    psq_st f24, 0xb8(r1), 0, 0
    stfd f23, 0xa0(r1)
    psq_st f23, 0xa8(r1), 0, 0
    stfd f22, 0x90(r1)
    psq_st f22, 0x98(r1), 0, 0
    stfd f21, 0x80(r1)
    psq_st f21, 0x88(r1), 0, 0
    stfd f20, 0x70(r1)
    psq_st f20, 0x78(r1), 0, 0
    stfd f19, 0x60(r1)
    psq_st f19, 0x68(r1), 0, 0
    stfd f18, 0x50(r1)
    psq_st f18, 0x58(r1), 0, 0
    stfd f17, 0x40(r1)
    psq_st f17, 0x48(r1), 0, 0
    stfd f16, 0x30(r1)
    psq_st f16, 0x38(r1), 0, 0
    stfd f15, 0x20(r1)
    psq_st f15, 0x28(r1), 0, 0
    stfd f14, 0x10(r1)
    psq_st f14, 0x18(r1), 0, 0
    lwz r6, lbl_80347EB4(r13)
    li r0, 0x18
    psq_l f6, 0x0(r6), 0, 0
    psq_l f7, 0x8(r6), 0, 0
    psq_l f8, 0x10(r6), 0, 0
    psq_l f9, 0x18(r6), 0, 0
    psq_l f31, 0x20(r6), 0, 0
    psq_l f30, 0x28(r6), 0, 0
    mtctr r3
L_802A227C:
    dcbt r5, r0
    psq_l f29, 0x0(r5), 0, 0
    ps_mul f0, f6, f29
    ps_mul f1, f8, f29
    psq_l f28, 0x8(r5), 1, 0
    ps_mul f2, f31, f29
    ps_madd f3, f7, f28, f0
    psq_l f29, 0xc(r5), 0, 0
    ps_madd f4, f9, f28, f1
    ps_madd f5, f30, f28, f2
    ps_sum0 f3, f3, f3, f3
    psq_st f3, 0x0(r4), 1, 0
    ps_sum0 f4, f4, f4, f4
    ps_sum0 f5, f5, f5, f5
    psq_st f4, 0x4(r4), 1, 0
    ps_mul f10, f6, f29
    psq_st f5, 0x8(r4), 1, 0
    ps_mul f11, f8, f29
    ps_mul f12, f31, f29
    psq_l f28, 0x14(r5), 1, 0
    ps_sum0 f10, f10, f10, f10
    ps_sum0 f11, f11, f11, f11
    ps_sum0 f12, f12, f12, f12
    ps_madd f13, f7, f28, f10
    psq_st f13, 0xc(r4), 1, 0
    ps_madd f14, f9, f28, f11
    ps_madd f15, f30, f28, f12
    psq_st f14, 0x10(r4), 1, 0
    psq_st f15, 0x14(r4), 1, 0
    addi r4, r4, 0x18
    addi r5, r5, 0x18
    bdnz L_802A227C
    psq_l f31, 0x128(r1), 0, 0
    lfd f31, 0x120(r1)
    psq_l f30, 0x118(r1), 0, 0
    lfd f30, 0x110(r1)
    psq_l f29, 0x108(r1), 0, 0
    lfd f29, 0x100(r1)
    psq_l f28, 0xf8(r1), 0, 0
    lfd f28, 0xf0(r1)
    psq_l f27, 0xe8(r1), 0, 0
    lfd f27, 0xe0(r1)
    psq_l f26, 0xd8(r1), 0, 0
    lfd f26, 0xd0(r1)
    psq_l f25, 0xc8(r1), 0, 0
    lfd f25, 0xc0(r1)
    psq_l f24, 0xb8(r1), 0, 0
    lfd f24, 0xb0(r1)
    psq_l f23, 0xa8(r1), 0, 0
    lfd f23, 0xa0(r1)
    psq_l f22, 0x98(r1), 0, 0
    lfd f22, 0x90(r1)
    psq_l f21, 0x88(r1), 0, 0
    lfd f21, 0x80(r1)
    psq_l f20, 0x78(r1), 0, 0
    lfd f20, 0x70(r1)
    psq_l f19, 0x68(r1), 0, 0
    lfd f19, 0x60(r1)
    psq_l f18, 0x58(r1), 0, 0
    lfd f18, 0x50(r1)
    psq_l f17, 0x48(r1), 0, 0
    lfd f17, 0x40(r1)
    psq_l f16, 0x38(r1), 0, 0
    lfd f16, 0x30(r1)
    psq_l f15, 0x28(r1), 0, 0
    lfd f15, 0x20(r1)
    psq_l f14, 0x18(r1), 0, 0
    lfd f14, 0x10(r1)
    addi r1, r1, 0x130
    blr
}

void fn_802A2394(s16* p, NJS_POINT3* v, u32 hdr, s32 side) {
    s32 len;
    s32 total;
    u32 cull = -1;
    s32 nuv;
    u32 mode;
    NJS_POINT3* q;
    f32 x, y, z;

    fn_8029AF68(1);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
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
            p += nuv;
            x = q->x;
            y = q->y;
            z = q->z;
            GXPosition3f32(x, y, z);
        } while (--len);
    } while (--hdr);
    lbl_80347EF0 += total;
}

void fn_802A24CC(s16* p, NjColVtx* v, u32 hdr, s32 side) {
    s32 len;
    s32 total;
    u32 cull = -1;
    s32 nuv;
    u32 mode;
    NjColVtx* q;
    f32 x, y, z;

    fn_8029AF68(1);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
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
            p += nuv;
            x = q->x;
            y = q->y;
            z = q->z;
            GXPosition3f32(x, y, z);
        } while (--len);
    } while (--hdr);
    lbl_80347EF0 += total;
}

void fn_802A2604(s16* p, NjColVtx* v, u32 hdr, s32 side) {
    s32 len;
    s32 total;
    u32 cull = -1;
    s32 nuv;
    u32 mode;
    NjColVtx* q;
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
            p += nuv;
            x = q->x;
            y = q->y;
            z = q->z;
            GXPosition3f32(x, y, z);
            GXNormal3f32(x, y, z);
        } while (--len);
    } while (--hdr);
    lbl_80347EF0 += total;
}

void fn_802A2770(s16* p, NjColVtx* v, u32 hdr, s32 side) {
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
    GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
    GXSetVtxDesc(GX_VA_TEX1, GX_DIRECT);
    GXSetVtxAttrFmt(GX_VTXFMT4, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
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
            p += nuv;
            x = q->x;
            y = q->y;
            z = q->z;
            c = q->col;
            GXPosition3f32(x, y, z);
            GXTexCoord2s16((c >> 8) & 0xff, (c >> 16) & 0xff);
            GXTexCoord2s16(c >> 24, c & 0xff);
        } while (--len);
    } while (--hdr);
    lbl_80347EF0 += total;
}

void fn_802A292C(s16* p, NjColVtx* v, u32 hdr, s32 side) {
    s32 len;
    s32 total;
    u32 cull = -1;
    s32 nuv;
    u32 mode;
    NjColVtx* q;
    f32 x, y, z;
    u32 c;

    fn_8029AFA0(1, 1);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
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
            p += nuv;
            x = q->x;
            y = q->y;
            z = q->z;
            c = q->col;
            GXPosition3f32(x, y, z);
            GXColor1u32(c);
        } while (--len);
    } while (--hdr);
    lbl_80347EF0 += total;
}

void fn_802A2A8C(s16* p, NjColVtx* v, u32 hdr, s32 side) {
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
            p += nuv;
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

void fn_802A2C84(s16* p, NjColVtx* v, u32 hdr, s32 side) {
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
            p += nuv;
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

void fn_802A2E18(s16* p, NJS_POINT3* v, u32 hdr, s32 side) {
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
            p += nuv;
            x = q->x;
            y = q->y;
            z = q->z;
            GXPosition3f32(x, y, z);
            GXNormal3f32(x, y, z);
        } while (--len);
    } while (--hdr);
    lbl_80347EF0 += total;
}

void fn_802A2F84(s16* p, NjPosNrm* v, u32 hdr, s32 side) {
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
            p += nuv;
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

void fn_802A30FC(s16* p, NjPosNrmCol* v, u32 hdr, s32 side) {
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
            p += nuv;
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

void fn_802A3274(s16* p, NjPosNrmCol* v, u32 hdr, s32 side) {
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
            p += nuv;
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

void fn_802A33EC(s16* p, NjPosNrmCol* v, u32 hdr, s32 side) {
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
            p += nuv;
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

void fn_802A35F0(s16* p, NjPosNrmCol* v, u32 hdr, s32 side) {
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
            p += nuv;
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

void fn_802A3790(s16* p, NjPosNrmCol* v, u32 hdr, s32 side) {
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
            p += nuv;
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

void fn_802A3994(s16* p, NjPosNrmCol* v, u32 hdr, s32 side) {
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
            p += nuv;
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

void fn_802A3B34(s16* p, NJS_POINT3* v, s32 hdr, s32 side, f32 scale) {
    u32 mode;
    s32 nuv;
    s32 len;
    s32 total;
    GXVtxFmt fmt;
    u32 cull = -1;
    NJS_POINT3* q;
    u16 i;
    f32 x, y, z;

    fn_8029B110(GX_DIRECT, GX_INDEX16);
    nuv = (hdr >> 14) & 3;
    hdr &= 0x3fff;
    total = 0;
    if (scale == 65.0f) {
        fmt = GX_VTXFMT2;
        GXSetVtxAttrFmt(GX_VTXFMT2, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
        GXSetVtxAttrFmt(GX_VTXFMT2, GX_VA_TEX0, GX_TEX_ST, GX_S16, 8);
    } else {
        fmt = GX_VTXFMT3;
        GXSetVtxAttrFmt(GX_VTXFMT3, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
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
            x = q->x;
            y = q->y;
            z = q->z;
            GXPosition3f32(x, y, z);
            GXTexCoord1x16(i);
            i++;
        } while (--len);
    } while (--hdr);
    lbl_80347EF0 += total;
}
