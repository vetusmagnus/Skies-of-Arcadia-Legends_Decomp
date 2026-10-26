#include "types.h"
#include "ninja.h"

void fn_801E5DF0(void *o);
void fn_801E5148(void *o);
extern u32 lbl_8030A6D4[36];
void *memset(void *dst, int c, u32 n);
extern s32 lbl_803471CC;
extern s32 DVDGetDriveStatus(void);

void fn_801C5A60(NJS_MATRIX m, NJS_POINT3 *p, NJS_POINT3 *out)
{
    if (m && p && out) {
        NJS_POINT3 tmp;
        tmp.x = p->x;
        tmp.y = p->y;
        tmp.z = p->z;
        njCalcPoint(m, &tmp, out);
    }
}

void fn_801C5B44(u8 *o, float *out)
{
    s32 ok = 0;
    if (o != 0) {
        if (*(u8 **)(o + 0x1c8) != 0) {
            ok = 1;
        }
    }
    if (ok == 0) {
        return;
    }
    if (out == 0) {
        return;
    }
    out[0] = *(float *)(*(u8 **)(o + 0x1c8) + 0x44);
    out[1] = *(float *)(*(u8 **)(o + 0x1c8) + 0x48);
    out[2] = *(float *)(*(u8 **)(o + 0x1c8) + 0x4c);
}

void fn_801C5B98(u8 *o)
{
    if (o != 0) {
        if (*(s32 *)(o + 0x19c) != 0) {
            fn_801E5DF0(o);
        } else {
            fn_801E5148(o);
        }
    }
}

typedef struct Obj12 {
    u8 pad_00[0x12];
    u16 v12;
} Obj12;
BOOL fn_801C5E80(void *unused, Obj12 *p)
{
    return p->v12 == 1;
}

u32 fn_801C5F40(u8 *o, u32 n)
{
    u8 *p;
    u32 v;
    s32 r = 0;
    if (o != 0) {
        p = *(u8 **)(o + 0x1c8);
        if (p != 0) {
            p = *(u8 **)(p + 0x1c);
            if (p != 0) {
                v = *(u32 *)p;
                if (v != 0) {
                    if (v > n) {
                        r = 1;
                    }
                }
            }
        }
    }
    return r;
}

s32 fn_801C5F84(u8 *o)
{
    u8 *p;
    s32 r = 0;
    if (o != 0) {
        p = *(u8 **)(o + 0x1c8);
        if (p != 0) {
            p = *(u8 **)(p + 0x1c);
            if (p != 0) {
                if (*(u32 *)p != 0) {
                    r = 1;
                }
            }
        }
    }
    return r;
}

s32 fn_801C5FC0(u8 *o)
{
    u8 *p;
    s32 r = 0;
    if (o != 0) {
        p = *(u8 **)(o + 0x1c8);
        if (p != 0) {
            p = *(u8 **)(p + 0x20);
            if (p != 0) {
                if (*(u32 *)(p + 0x4) != 0) {
                    r = 1;
                }
            }
        }
    }
    return r;
}

u32 fn_801C602C(u8 *o, u32 n)
{
    u8 *p;
    s32 r = 0;
    if (o != 0) {
        p = *(u8 **)(o + 0x1c8);
        if (p != 0) {
            p = *(u8 **)(p + 0x10);
            if (p != 0) {
                if (*(u32 *)p > n) {
                    r = 1;
                }
            }
        }
    }
    return r;
}

u32 fn_801C6068(u8 *o, u32 n)
{
    u8 *p;
    s32 r = 0;
    if (o != 0) {
        p = *(u8 **)(o + 0x1c8);
        if (p != 0) {
            p = *(u8 **)(p + 0x10);
            if (p != 0) {
                if (*(u32 *)p >= n) {
                    r = 1;
                }
            }
        }
    }
    return r;
}

float fn_801C60C8(float a, float b)
{
    float s = a + b;
    if (b >= 0.0f && s > 0.0f) {
        return 0.0f;
    }
    if (!(b < 0.0f)) {
        return s;
    }
    if (!(s < -1.0f)) {
        return s;
    }
    return -1.0f;
}

extern u32 lbl_803471D0;
s32 fn_801C621C(void) {
    return lbl_803471CC;
}

void fn_801C62D8(void) {
    lbl_803471D0 = 0;
}

void fn_801C78B4(void) {
}

void fn_801C78B8(void)
{
    memset(lbl_8030A6D4, 0, 0x90);
    lbl_8030A6D4[5] = 6;
    lbl_8030A6D4[14] = 6;
    lbl_8030A6D4[23] = 6;
    lbl_8030A6D4[32] = 6;
}

void fn_801C5BD4(u8 *p) {
    if (p == 0) {
        return;
    }
    *(f32 *)(p + 0x1a4) = 0.0f;
    *(u32 *)(p + 0x198) = 0;
    *(u32 *)(p + 0x19c) = 0;
}

int fn_801C5FFC(u8 *p) {
    u8 *q;
    int r = 0;

    if (p != 0) {
        q = *(u8 **)(p + 0x100);
        if (q != 0 && *(u32 *)(q + 0x4) != 0) {
            r = 1;
        }
    }
    return r;
}

int fn_801C60A4(u8 *p) {
    int r = 0;

    if (p != 0 && *(u32 *)(p + 0x1c8) != 0) {
        r = 1;
    }
    return r;
}

void fn_801C6170(u8 *p) {
    p[0x18] |= 0x40;
}

void fn_801C6224(void) {
    lbl_803471CC = DVDGetDriveStatus();
}
