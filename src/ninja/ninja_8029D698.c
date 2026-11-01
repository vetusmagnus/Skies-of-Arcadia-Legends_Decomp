/* Sega Ninja library, 0x8029D698-0x8029DEDC. Drawer file ending with fn_8029DCD0, the owner of the
 * lone 65.0f at 0x8034D328. */

#include "ninja_lib.h"
#include "ninja_blend.h"

void fn_8029D698(u32 attr, s16* p, u8* c0, u8* c1, u8* c2) {
    u8 kind = attr;
    s32 flags = kind - 0x10;
    NJS_ARGB tmp;
    s16 a, b;

    if (flags & 1) {
        a = p[0];
        b = p[1];
        p += 2;
        if (_nj_control_3d_flag_ & 0x10) {
            fn_8029EE28(&_nj_constant_material_, c0);
        } else if (c0 != 0) {
            c0[3] = b;
            c0[0] = (b >> 8) & 0xFF;
            c0[1] = a;
            c0[2] = (a >> 8) & 0xFF;
            if (_nj_control_3d_flag_ & 0x20) {
                fn_8029EE50(c0, &tmp);
                tmp.a += _nj_constant_material_.a;
                tmp.r += _nj_constant_material_.r;
                tmp.g += _nj_constant_material_.g;
                tmp.b += _nj_constant_material_.b;
                fn_8029EE28(&tmp, c0);
            }
        }
    }
    if (flags & 2) {
        a = p[0];
        b = p[1];
        p += 2;
        if (c1 != 0) {
            c1[3] = b;
            c1[0] = (b >> 8) & 0xFF;
            c1[1] = a;
            c1[2] = (a >> 8) & 0xFF;
        }
    }
    if (flags & 4) {
        a = p[0];
        b = p[1];
        p += 2;
        if (c2 != 0) {
            c2[3] = b;
            c2[0] = (b >> 8) & 0xFF;
            c2[1] = a;
            c2[2] = (a >> 8) & 0xFF;
        }
    }
    set_blend(attr);
}

void fn_8029D8B0(NjLightTbl* lt, s16 kind, s32 n, s32 enable) {
    u8 type = n;
    GXSetNumChans(1);
    switch (type) {
    case 0x22:
    case 0x24:
    case 0x29:
    case 0x2B:
        GXSetChanCtrl(0, enable, 0, 0, lt->chan[0].mask, lt->chan[0].diff_fn, lt->chan[0].attn_fn);
        GXSetChanCtrl(2, 0, 0, 0, lt->chan[1].mask, lt->chan[1].diff_fn, lt->chan[1].attn_fn);
        GXSetChanCtrl(1, 0, 0, 0, 0, 0, 2);
        GXSetChanCtrl(3, 0, 0, 0, 0, 0, 2);
        break;
    case 0x23:
    case 0x2A:
        GXSetChanCtrl(0, enable, 0, 1, lt->chan[0].mask, lt->chan[0].diff_fn, lt->chan[0].attn_fn);
        GXSetChanCtrl(2, 0, 0, 1, lt->chan[1].mask, lt->chan[1].diff_fn, lt->chan[1].attn_fn);
        GXSetChanCtrl(1, 0, 0, 0, 0, 0, 2);
        GXSetChanCtrl(3, 0, 0, 0, 0, 0, 2);
        break;
    }
}

void fn_8029DA24(s16 kind, s32 type, s32 mode) {
    s32 enable;
    s32 twoSided;
    s32 mask;

    switch (mode) {
    case 0:
        enable = 0;
        twoSided = 0;
        mask = 0;
        GXSetNumChans(1);
        break;
    case 1:
        enable = 1;
        twoSided = 1;
        mask = 1;
        GXSetNumChans(2);
        break;
    case 2:
        enable = 1;
        twoSided = 0;
        mask = 1;
        GXSetNumChans(1);
        break;
    }
    switch ((u8)type) {
    case 0x29:
    case 0x2B:
        GXSetChanCtrl(0, enable, 0, 0, mask, 2, 2);
        GXSetChanCtrl(2, 0, 0, 0, mask, 2, 0);
        if (twoSided != 0) {
            GXSetChanCtrl(1, enable, 0, 0, mask, 2, 0);
            GXSetChanCtrl(3, 0, 0, 0, mask, 2, 0);
        }
        break;
    case 0x22:
    case 0x24:
        GXSetChanCtrl(0, enable, 0, 0, mask, 0, 2);
        GXSetChanCtrl(2, 0, 0, 0, mask, 0, 0);
        if (twoSided != 0) {
            GXSetChanCtrl(1, enable, 0, 0, mask, 0, 2);
            GXSetChanCtrl(3, 0, 0, 0, mask, 0, 2);
        } else {
            GXSetChanCtrl(1, 0, 0, 0, 0, 0, 2);
            GXSetChanCtrl(3, 0, 0, 0, 0, 0, 2);
        }
        break;
    case 0x23:
    case 0x2A:
        GXSetChanCtrl(0, 0, 0, 1, mask, 2, 2);
        GXSetChanCtrl(2, 0, 0, 1, mask, 2, 2);
        GXSetChanCtrl(1, 0, 0, 0, 0, 0, 2);
        GXSetChanCtrl(3, 0, 0, 0, mask, 0, 2);
        break;
    }
}
