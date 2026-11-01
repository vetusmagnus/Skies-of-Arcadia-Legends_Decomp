/* Sega Ninja library, 0x802A1160-0x802A20DC. Renderer 1's chunk-model file: fn_802A1160,
 * fn_802A1374 and fn_802A1B54 share the pool 0x8034D358-0x8034D37F. */

#include "ninja_lib.h"

void fn_802A1374(s16* p, s32 n, u32* data) {
    u8 dif[4] = {0xff, 0xff, 0xff, 0xff};
    u16 size;
    s16 cnt;
    s16 fl;
    s16 len;
    u8 type = n;
    s16 kind;
    s32 alpha;
    s32 mode;
    s16 c;
    u8 spc[4] = {0, 0, 0, 0};
    s32 tex;

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
                fn_802A1374(lbl_803458A8[(s16)((c >> 8) & 0xff)], n, data);
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
                c &= _nj_constant_attr_and_;
                c |= _nj_constant_attr_or_;
            }
            fl = (c >> 8) & 0x2a;
            lbl_80347EA0 = fl & 0x20;
            if (fl & 2) {
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
            fn_802A8F40(1);
            switch (kind) {
            case 0x41:
            case 0x42:
                GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX2x4, GX_TG_TEX0, 0x3c, 0, 0x7d);
                GXSetNumTexGens(1);
                switch (type) {
                case 0x29:
                    fn_8029DA24(kind, n, mode);
                    if (tex) {
                        fn_8029A4EC(alpha);
                    } else {
                        fn_8029AE38(alpha);
                    }
                    fn_802A1B54(0x1002, 0, 0, spc, dif);
                    fn_8029DCD0(p, data, cnt, 1, kind);
                    break;
                case 0x2b:
                    fn_8029DA24(kind, n, mode);
                    if (tex) {
                        fn_8029A4EC(alpha);
                    } else {
                        fn_8029AE38(alpha);
                    }
                    fn_802A1B54(0x1002, 0, 0, spc, dif);
                    fn_8029EC1C(p, data, cnt, 1, kind);
                    break;
                case 0x2a:
                    if (fn_8029CFF0()) {
                        fn_8029DA24(kind, 0x29, 0);
                        fn_8029CF04();
                        fn_8029AB44(alpha, 0);
                        fn_8029DEDC(p, data, cnt, 1, kind);
                    } else {
                        fn_8029DA24(kind, n, mode);
                        fn_8029AE38(alpha);
                        fn_8029E1B4(p, data, cnt, 1, kind);
                    }
                    break;
                case 0x22:
                    fn_8029DA24(kind, n, 0);
                    fn_802A1B54(0x3412, 0, 0, spc, dif);
                    fn_8029AE38(alpha);
                    fn_8029E40C(p, data, cnt, 1, kind);
                    break;
                case 0x24:
                    fn_8029DA24(kind, n, mode);
                    fn_8029AE38(alpha);
                    fn_802A1B54(0x3412, 0, 0, spc, dif);
                    fn_8029EA5C(p, data, cnt, 1, kind);
                    break;
                case 0x23:
                    if (fn_8029CFF0()) {
                        fn_8029DA24(kind, 0x29, 0);
                        fn_8029CF04();
                        fn_8029AB44(alpha, 0);
                        fn_8029E5CC(p, data, cnt, 1, kind);
                    } else {
                        fn_8029DA24(kind, n, mode);
                        fn_8029AE38(alpha);
                        fn_8029E850(p, data, cnt, 1, kind);
                    }
                    break;
                }
                break;
            case 0x40:
                GXSetNumTexGens(0);
                if (mode) {
                    mode = 2;
                }
                switch (type) {
                case 0x29:
                    fn_8029DA24(kind, n, mode);
                    fn_8029A41C(alpha);
                    fn_802A1B54(0x3001, 0, 0, 0, dif);
                    fn_8029EE78(p, data, cnt, 1);
                    break;
                case 0x2a:
                    if (fn_8029CFF0()) {
                        fn_8029DA24(kind, 0x29, 0);
                        fn_8029CF04();
                        fn_8029A298(alpha);
                        fn_8029F680(p, data, cnt, 1);
                    } else {
                        fn_8029DA24(kind, n, mode);
                        fn_8029A41C(alpha);
                        fn_8029F86C(p, data, cnt, 1);
                    }
                    break;
                case 0x2b:
                    fn_8029DA24(kind, n, mode);
                    fn_8029A41C(alpha);
                    fn_802A1B54(0x3001, 0, 0, 0, dif);
                    fn_8029F528(p, data, cnt, 1);
                    break;
                case 0x22:
                    fn_8029DA24(kind, n, mode);
                    fn_8029A41C(alpha);
                    fn_802A1B54(0x3003, 0, 0, 0, dif);
                    fn_8029F400(p, data, cnt, 1);
                    break;
                case 0x24:
                    fn_8029DA24(kind, n, mode);
                    fn_8029A41C(alpha);
                    fn_802A1B54(0x3003, 0, 0, 0, dif);
                    fn_8029EFD0(p, data, cnt, 1);
                    break;
                case 0x23:
                    if (fn_8029CFF0()) {
                        fn_8029DA24(kind, 0x29, 0);
                        fn_8029CF04();
                        fn_8029A298(alpha);
                        fn_8029F0F8(p, data, cnt, 1);
                    } else {
                        fn_8029DA24(kind, n, mode);
                        fn_8029A41C(alpha);
                        fn_8029F2A8(p, data, cnt, 1);
                    }
                    break;
                }
                break;
            }
            p += size - 1;
        }
    }
}
