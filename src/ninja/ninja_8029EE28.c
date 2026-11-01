/* Sega Ninja library, 0x8029EE28-0x802A1160. Indexed drawers (no constants, so the file edges
 * inside this range are unknown). */

#include "ninja_lib.h"

asm void fn_8029EE28(register NJS_ARGB* src, register u8* dst) {
    nofralloc
    li r0, 0x804
    oris r0, r0, 0x804
    mtspr 913, r0
    lfs f0, 0x0(src)
    psq_st f0, 0x3(dst), 1, 1
    psq_l f0, 0x4(src), 0, 0
    psq_st f0, 0x0(dst), 0, 1
    lfs f0, 0xc(src)
    psq_st f0, 0x2(dst), 1, 1
    blr
}

asm void fn_8029EE50(register u8* src, register NJS_ARGB* dst) {
    nofralloc
    li r0, 0x804
    oris r0, r0, 0x804
    mtspr 913, r0
    psq_l f0, 0x3(src), 1, 1
    stfs f0, 0x0(dst)
    psq_l f0, 0x0(src), 0, 1
    psq_st f0, 0x4(dst), 0, 0
    psq_l f0, 0x2(src), 1, 1
    stfs f0, 0xc(dst)
    blr
}

void fn_8029EE78(s16* p, u32* data, s32 hdr, s32 side) {
    s32 total;
    u32 cull = -1;
    s32 nuv;
    s32 len;
    u32 mode;
    s16 idx;

    fn_8029B058(3, 3);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_NRM, GX_NRM_XYZ, GX_F32, 0);
    nuv = (hdr >> 14) & 3;
    hdr &= 0x3fff;
    total = 0;
    GXSetArray(GX_VA_POS, data, 0x18);
    GXSetArray(GX_VA_NRM, data + 3, 0x18);
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
            idx = *p++;
            p += nuv;
            GXPosition1x16(idx);
            GXNormal1x16(idx);
        } while (--len);
    } while (--hdr);
    lbl_80347EF0 += total;
}

void fn_8029EFD0(s16* p, u32* data, s32 hdr, s32 side) {
    s32 total;
    u32 cull = -1;
    s32 nuv;
    s32 len;
    u32 mode;
    s16 idx;

    fn_8029AF68(GX_INDEX16);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    nuv = (hdr >> 14) & 3;
    hdr &= 0x3fff;
    total = 0;
    GXSetArray(GX_VA_POS, data, 0x10);
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
            idx = *p++;
            p += nuv;
            GXPosition1x16(idx);
        } while (--len);
    } while (--hdr);
    lbl_80347EF0 += total;
}

void fn_8029F2A8(s16* p, u32* data, s32 hdr, s32 side) {
    s32 total;
    u32 cull = -1;
    s32 nuv;
    s32 len;
    u32 mode;
    s16 idx;

    fn_8029AFA0(3, 3);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);
    nuv = (hdr >> 14) & 3;
    hdr &= 0x3fff;
    total = 0;
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
        GXBegin(GX_TRIANGLESTRIP, GX_VTXFMT0, len);
        do {
            idx = *p++;
            p += nuv;
            GXPosition1x16(idx);
            GXColor1x16(idx);
        } while (--len);
    } while (--hdr);
    lbl_80347EF0 += total;
}

void fn_8029F400(s16* p, u32* data, s32 hdr, s32 side) {
    s32 total;
    u32 cull = -1;
    s32 nuv;
    s32 len;
    u32 mode;
    s16 idx;

    fn_8029AF68(GX_INDEX16);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    nuv = (hdr >> 14) & 3;
    hdr &= 0x3fff;
    total = 0;
    GXSetArray(GX_VA_POS, data, 0xc);
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
            idx = *p++;
            p += nuv;
            GXPosition1x16(idx);
        } while (--len);
    } while (--hdr);
    lbl_80347EF0 += total;
}

void fn_8029F528(s16* p, u32* data, s32 hdr, s32 side) {
    s32 total;
    u32 cull = -1;
    s32 nuv;
    s32 len;
    u32 mode;
    s16 idx;

    fn_8029B058(3, 3);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_NRM, GX_NRM_XYZ, GX_F32, 0);
    nuv = (hdr >> 14) & 3;
    hdr &= 0x3fff;
    total = 0;
    GXSetArray(GX_VA_POS, data, 0x1c);
    GXSetArray(GX_VA_NRM, data + 3, 0x1c);
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
            idx = *p++;
            p += nuv;
            GXPosition1x16(idx);
            GXNormal1x16(idx);
        } while (--len);
    } while (--hdr);
    lbl_80347EF0 += total;
}

void fn_8029F9F8(s16* p, u32* data, s32 hdr, s32 side) {
    s32 total;
    u32 cull = -1;
    s32 nuv;
    s32 len;
    u32 mode;
    s16 idx;

    fn_8029B058(3, 3);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_NRM, GX_NRM_XYZ, GX_F32, 0);
    nuv = (hdr >> 14) & 3;
    hdr &= 0x3fff;
    total = 0;
    GXSetArray(GX_VA_POS, data, 0x18);
    GXSetArray(GX_VA_NRM, data + 3, 0x18);
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
            idx = *p++;
            p += nuv + 2;
            GXPosition1x16(idx);
            GXNormal1x16(idx);
        } while (--len);
    } while (--hdr);
    lbl_80347EF0 += total;
}

void fn_8029FB54(s16* p, u32* data, s32 hdr, s32 side) {
    s32 total;
    u32 cull = -1;
    s32 nuv;
    s32 len;
    u32 mode;
    s16 idx;

    fn_8029B058(3, 3);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_NRM, GX_NRM_XYZ, GX_F32, 0);
    nuv = (hdr >> 14) & 3;
    hdr &= 0x3fff;
    total = 0;
    GXSetArray(GX_VA_POS, data, 0xc);
    GXSetArray(GX_VA_NRM, data, 0xc);
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
            idx = *p++;
            p += nuv + 2;
            GXPosition1x16(idx);
            GXNormal1x16(idx);
        } while (--len);
    } while (--hdr);
    lbl_80347EF0 += total;
}

void fn_8029FCB0(s16* p, u32* data, s32 hdr, s32 side) {
    s32 total;
    u32 cull = -1;
    s32 nuv;
    s32 len;
    u32 mode;
    s16 idx;

    fn_8029B058(3, 3);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_NRM, GX_NRM_XYZ, GX_F32, 0);
    nuv = (hdr >> 14) & 3;
    hdr &= 0x3fff;
    total = 0;
    GXSetArray(GX_VA_POS, data, 0x10);
    GXSetArray(GX_VA_NRM, data, 0x10);
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
            idx = *p++;
            p += nuv + 2;
            GXPosition1x16(idx);
            GXNormal1x16(idx);
        } while (--len);
    } while (--hdr);
    lbl_80347EF0 += total;
}

void fn_8029FFFC(s16* p, u32* data, s32 hdr, s32 side) {
    s32 total;
    u32 cull = -1;
    s32 nuv;
    s32 len;
    u32 mode;
    s16 idx;

    fn_8029AFF0(3, 3, 3);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_NRM, GX_NRM_XYZ, GX_F32, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);
    nuv = (hdr >> 14) & 3;
    hdr &= 0x3fff;
    total = 0;
    GXSetArray(GX_VA_POS, data, 0x10);
    GXSetArray(GX_VA_NRM, data, 0x10);
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
        GXBegin(GX_TRIANGLESTRIP, GX_VTXFMT0, len);
        do {
            idx = *p++;
            p += nuv + 2;
            GXPosition1x16(idx);
            GXNormal1x16(idx);
            GXColor1x16(idx);
        } while (--len);
    } while (--hdr);
    lbl_80347EF0 += total;
}

void fn_802A018C(s16* p, u32* data, s32 hdr, s32 side) {
    s32 total;
    u32 cull = -1;
    s32 nuv;
    s32 len;
    u32 mode;
    s16 idx;

    fn_8029B058(3, 3);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_NRM, GX_NRM_XYZ, GX_F32, 0);
    nuv = (hdr >> 14) & 3;
    hdr &= 0x3fff;
    total = 0;
    GXSetArray(GX_VA_POS, data, 0x1c);
    GXSetArray(GX_VA_NRM, data + 3, 0x1c);
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
            idx = *p++;
            p += nuv + 2;
            GXPosition1x16(idx);
            GXNormal1x16(idx);
        } while (--len);
    } while (--hdr);
    lbl_80347EF0 += total;
}

void fn_802A04D8(s16* p, u32* data, s32 hdr, s32 side) {
    s32 total;
    u32 cull = -1;
    s32 nuv;
    s32 len;
    u32 mode;
    s16 idx;

    fn_8029AFF0(3, 3, 3);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_NRM, GX_NRM_XYZ, GX_F32, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);
    nuv = (hdr >> 14) & 3;
    hdr &= 0x3fff;
    total = 0;
    GXSetArray(GX_VA_POS, data, 0x1c);
    GXSetArray(GX_VA_NRM, data + 3, 0x1c);
    GXSetArray(GX_VA_CLR0, data + 6, 0x1c);
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
            idx = *p++;
            p += nuv + 2;
            GXPosition1x16(idx);
            GXNormal1x16(idx);
            GXColor1x16(idx);
        } while (--len);
    } while (--hdr);
    lbl_80347EF0 += total;
}

void fn_802A0668(s16* p, u32* data, s32 hdr, s32 side) {
    s32 total;
    u32 cull = -1;
    s32 nuv;
    s32 len;
    u32 mode;
    s16 idx;

    fn_8029B058(3, 3);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_NRM, GX_NRM_XYZ, GX_F32, 0);
    nuv = (hdr >> 14) & 3;
    hdr &= 0x3fff;
    total = 0;
    GXSetArray(GX_VA_POS, data, 0x10);
    GXSetArray(GX_VA_NRM, data, 0x10);
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
            idx = *p++;
            p += nuv;
            GXPosition1x16(idx);
            GXNormal1x16(idx);
        } while (--len);
    } while (--hdr);
    lbl_80347EF0 += total;
}

void fn_802A0B38(s16* p, u32* data, s32 hdr, s32 side) {
    s32 total;
    u32 cull = -1;
    s32 nuv;
    s32 len;
    u32 mode;
    s16 idx;

    fn_8029B058(3, 3);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_NRM, GX_NRM_XYZ, GX_F32, 0);
    nuv = (hdr >> 14) & 3;
    hdr &= 0x3fff;
    total = 0;
    GXSetArray(GX_VA_POS, data, 0xc);
    GXSetArray(GX_VA_NRM, data, 0xc);
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
            idx = *p++;
            p += nuv;
            GXPosition1x16(idx);
            GXNormal1x16(idx);
        } while (--len);
    } while (--hdr);
    lbl_80347EF0 += total;
}

void fn_802A0C90(s16* p, u32* data, s32 hdr, s32 side) {
    s32 total;
    u32 cull = -1;
    s32 nuv;
    s32 len;
    u32 mode;
    s16 idx;

    fn_8029B058(3, 3);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_NRM, GX_NRM_XYZ, GX_F32, 0);
    nuv = (hdr >> 14) & 3;
    hdr &= 0x3fff;
    total = 0;
    GXSetArray(GX_VA_POS, data, 0x1c);
    GXSetArray(GX_VA_NRM, data + 3, 0x1c);
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
            idx = *p++;
            p += nuv;
            GXPosition1x16(idx);
            GXNormal1x16(idx);
        } while (--len);
    } while (--hdr);
    lbl_80347EF0 += total;
}
