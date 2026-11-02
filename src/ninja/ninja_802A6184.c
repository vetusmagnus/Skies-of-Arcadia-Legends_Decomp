/* Sega Ninja library, 0x802A6184-0x802A7598. Renderer 2's chunk-model file (the twin of
 * ninja_802A1160.c), pool 0x8034D3C0-0x8034D3E7. */

#include "ninja_lib.h"

#pragma opt_propagation off
void fn_802A6398(s16* plist, s32 num, u32* dat) {
    u32* data;
    s32 n;
    s16* p;
    u8 type;
    u8 dif[4] = {0xff, 0xff, 0xff, 0xff};
    u8 spc[4] = {0, 0, 0, 0};
    s16 fl;
    u16 size;
    s16 cnt;
    s16 len;
    s16 kind;
    s32 alpha;
    s32 mode;
    s32 c;
    s32 tex;
    u32 spec;

    p = plist;
    n = num;
    data = dat;
    type = n;

    while ((c = *p++) != 0xff) {
        kind = c & 0xff;
        if (kind < 8) {
            switch (kind) {
            case 1:
                fn_8029D010(c);
                break;
            case 4:
                lbl_803458A8[(s16)((c >> 8) & 0xff)] = p;
                lbl_80347F24++;
                return;
            case 5:
                fn_802A6398(lbl_803458A8[(s16)((c >> 8) & 0xff)], n, data);
                lbl_80347F24--;
                break;
            }
        } else if (kind < 0x10) {
            fn_8029D0F4(c, *p++);
            if (*p & 0x18) {
                p += 8;
            }
        } else if (kind < 0x40) {
            len = *p++;
            fn_8029D698(c, p, dif, 0, spc);
            p += len;
        } else {
            cnt = p[1];
            size = *(u16*)p;  /* the chunk stream is s16; this field is unsigned */
            p += 2;
            if (_nj_control_3d_flag_ & 0x800) {
                c = (s16)(c & _nj_constant_attr_and_);
                c = (s16)(c | _nj_constant_attr_or_);
            }
            fl = c >> 8;
            lbl_80347EA0 = fl & 0x20;
            if (fl & 1) {
                mode = 0;
                tex = 0;
            } else if (fl & 2) {
                mode = 2;
                tex = 0;
            } else {
                mode = 1;
                tex = 1;
            }
            if (fl & 8) {
                alpha = 1;
                if (lbl_80347E20 == 1) {
                    p += size - 1;
                    continue;
                }
            } else {
                alpha = 0;
                switch (lbl_80347E20) {
                case 2:
                case 3:
                case 4:
                    p += size - 1;
                    continue;
                }
            }
            if (_nj_control_3d_flag_ & 0x200) {
                dif[0] = 0xff;
                dif[1] = 0xff;
                dif[2] = 0xff;
            }
            spec = 0;
            if (fl & 4) {
                spec = 0x300;
            }
            fn_802A8F40(1);
            switch (kind) {
            case 0x41:
            case 0x42:
                if (fl & 0x40) {
                    fn_8029C9B0(0);
                    GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX3x4, GX_TG_NRM, 0x1e, 0, 0x7d);
                    GXSetNumTexGens(1);
                    switch (type) {
                    case 0x29:
                        fn_802A70B0(spec | 0x1001, 0, 0, spc, dif);
                        if (tex) {
                            fn_8029A4EC(alpha);
                        } else {
                            fn_8029AE38(alpha);
                        }
                        fn_8029DA24(kind, n, mode);
                        fn_8029F9F8(p, data, cnt, 0);
                        break;
                    case 0x2a:
                        if (fn_8029CFF0()) {
                            fn_8029DA24(kind, 0x29, 0);
                            fn_8029CF04();
                            fn_8029AB44(alpha, 1);
                            fn_802A02E8(p, data, cnt, 0);
                        } else {
                            fn_8029DA24(kind, n, 0);
                            fn_8029AE38(alpha);
                            fn_802A04D8(p, data, cnt, 0);
                        }
                        break;
                    case 0x2b:
                        fn_802A70B0(spec | 0x1001, 0, 0, spc, dif);
                        if (tex) {
                            fn_8029A4EC(alpha);
                        } else {
                            fn_8029AE38(alpha);
                        }
                        fn_8029DA24(kind, n, mode);
                        fn_802A018C(p, data, cnt, 0);
                        break;
                    case 0x22:
                        fn_802A70B0(spec | 0x3003, 0, 0, 0, dif);
                        fn_8029AE38(alpha);
                        fn_8029DA24(kind, n, 0);
                        fn_8029FB54(p, data, cnt, 0);
                        break;
                    case 0x24:
                        fn_802A70B0(spec | 0x3003, 0, 0, 0, dif);
                        fn_8029AE38(alpha);
                        fn_8029DA24(kind, n, 0);
                        fn_8029FCB0(p, data, cnt, 0);
                        break;
                    case 0x23:
                        if (fn_8029CFF0()) {
                            fn_8029DA24(kind, 0x29, 0);
                            fn_8029CF04();
                            fn_8029AB44(alpha, 1);
                            fn_8029FE0C(p, data, cnt, 0);
                        } else {
                            fn_8029DA24(kind, n, 0);
                            fn_8029AE38(alpha);
                            fn_8029FFFC(p, data, cnt, 0);
                        }
                        break;
                    }
                } else {
                    GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX2x4, GX_TG_TEX0, 0x3c, 0, 0x7d);
                    GXSetNumTexGens(1);
                    switch (type) {
                    case 0x29:
                        fn_802A70B0(spec | 0x1001, 0, 0, spc, dif);
                        if (tex) {
                            fn_8029A4EC(alpha);
                        } else {
                            fn_8029AE38(alpha);
                        }
                        fn_8029DA24(kind, n, mode);
                        fn_8029DCD0(p, data, cnt, 0, kind);
                        break;
                    case 0x2a:
                        if (fn_8029CFF0()) {
                            fn_8029DA24(kind, 0x29, 0);
                            fn_8029CF04();
                            fn_8029AB44(alpha, 0);
                            fn_8029DEDC(p, data, cnt, 0, kind);
                        } else {
                            fn_8029DA24(kind, n, 0);
                            fn_8029AE38(alpha);
                            fn_8029E1B4(p, data, cnt, 0, kind);
                        }
                        break;
                    case 0x2b:
                        fn_802A70B0(spec | 0x1001, 0, 0, spc, dif);
                        if (tex) {
                            fn_8029A4EC(alpha);
                        } else {
                            fn_8029AE38(alpha);
                        }
                        fn_8029DA24(kind, n, mode);
                        fn_8029EC1C(p, data, cnt, 0, kind);
                        break;
                    case 0x22:
                        fn_802A70B0(spec | 0x3003, 0, 0, 0, dif);
                        fn_8029AE38(alpha);
                        fn_8029DA24(kind, n, 0);
                        fn_8029E40C(p, data, cnt, 0, kind);
                        break;
                    case 0x24:
                        fn_802A70B0(spec | 0x3003, 0, 0, 0, dif);
                        fn_8029AE38(alpha);
                        fn_8029DA24(kind, n, 0);
                        fn_8029EA5C(p, data, cnt, 0, kind);
                        break;
                    case 0x23:
                        if (fn_8029CFF0()) {
                            fn_8029DA24(kind, 0x29, 0);
                            fn_8029CF04();
                            fn_8029AB44(alpha, 0);
                            fn_8029E5CC(p, data, cnt, 0, kind);
                        } else {
                            fn_8029DA24(kind, n, 0);
                            fn_8029AE38(alpha);
                            fn_8029E850(p, data, cnt, 0, kind);
                        }
                        break;
                    }
                }
                break;
            case 0x40:
                if (fl & 0x40) {
                    fn_8029C9B0(0);
                    GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX3x4, GX_TG_NRM, 0x1e, 0, 0x7d);
                    GXSetNumTexGens(1);
                    switch (type) {
                    case 0x29:
                        fn_802A70B0(spec | 0x1001, 0, 0, spc, dif);
                        if (tex) {
                            fn_8029A4EC(alpha);
                        } else {
                            fn_8029AE38(alpha);
                        }
                        fn_8029DA24(kind, n, mode);
                        fn_8029EE78(p, data, cnt, 0);
                        break;
                    case 0x2a:
                        if (fn_8029CFF0()) {
                            fn_8029DA24(kind, 0x29, 0);
                            fn_8029CF04();
                            fn_8029AB44(alpha, 1);
                            fn_802A0DE8(p, data, cnt, 0);
                        } else {
                            fn_8029DA24(kind, n, 0);
                            fn_8029AE38(alpha);
                            fn_802A0FD4(p, data, cnt, 0);
                        }
                        break;
                    case 0x2b:
                        fn_802A70B0(spec | 0x1001, 0, 0, spc, dif);
                        if (tex) {
                            fn_8029A4EC(alpha);
                        } else {
                            fn_8029AE38(alpha);
                        }
                        fn_8029DA24(kind, n, mode);
                        fn_802A0C90(p, data, cnt, 0);
                        break;
                    case 0x22:
                        fn_802A70B0(spec | 0x3003, 0, 0, 0, dif);
                        fn_8029AE38(alpha);
                        fn_8029DA24(kind, n, 0);
                        fn_802A0B38(p, data, cnt, 0);
                        break;
                    case 0x24:
                        fn_802A70B0(spec | 0x3003, 0, 0, 0, dif);
                        fn_8029AE38(alpha);
                        fn_8029DA24(kind, n, 0);
                        fn_802A0668(p, data, cnt, 0);
                        break;
                    case 0x23:
                        if (fn_8029CFF0()) {
                            fn_8029DA24(kind, 0x29, 0);
                            fn_8029CF04();
                            fn_8029AB44(alpha, 1);
                            fn_802A07C0(p, data, cnt, 0);
                        } else {
                            fn_8029DA24(kind, n, 0);
                            fn_8029AE38(alpha);
                            fn_802A09AC(p, data, cnt, 0);
                        }
                        break;
                    }
                } else {
                    GXSetNumTexGens(0);
                    switch (type) {
                    case 0x29:
                        fn_802A70B0(spec | 0x3001, 0, 0, 0, dif);
                        fn_8029A41C(alpha);
                        fn_8029DA24(kind, n, mode);
                        fn_8029EE78(p, data, cnt, 0);
                        break;
                    case 0x2a:
                        if (fn_8029CFF0()) {
                            fn_8029DA24(kind, 0x29, 0);
                            fn_8029CF04();
                            fn_8029A298(alpha);
                            fn_8029F680(p, data, cnt, 0);
                        } else {
                            fn_8029DA24(kind, n, 0);
                            fn_8029A41C(alpha);
                            fn_8029F86C(p, data, cnt, 0);
                        }
                        break;
                    case 0x2b:
                        fn_802A70B0(spec | 0x3001, 0, 0, 0, dif);
                        fn_8029A41C(alpha);
                        fn_8029DA24(kind, n, mode);
                        fn_8029F528(p, data, cnt, 0);
                        break;
                    case 0x22:
                        fn_802A70B0(spec | 0x3003, 0, 0, 0, dif);
                        fn_8029A41C(alpha);
                        fn_8029DA24(kind, n, mode);
                        fn_8029F400(p, data, cnt, 0);
                        break;
                    case 0x24:
                        fn_802A70B0(spec | 0x3003, 0, 0, 0, dif);
                        fn_8029A41C(alpha);
                        fn_8029DA24(kind, n, mode);
                        fn_8029EFD0(p, data, cnt, 0);
                        break;
                    case 0x23:
                        if (fn_8029CFF0()) {
                            fn_8029DA24(kind, 0x29, 0);
                            fn_8029CF04();
                            fn_8029A298(alpha);
                            fn_8029F0F8(p, data, cnt, 0);
                        } else {
                            fn_8029DA24(kind, n, 0);
                            fn_8029A41C(alpha);
                            fn_8029F2A8(p, data, cnt, 0);
                        }
                        break;
                    }
                }
                break;
            }
            p += size - 1;
        }
    }
}
#pragma opt_propagation reset
