#include "types.h"
#include "ninja.h"
void fn_801E5DF0(void *o);
void fn_801E5148(void *o);
extern u32 lbl_8030A6D4[36];
void *memset(void *dst, int c, u32 n);
extern s32 lbl_803471CC;
extern s32 DVDGetDriveStatus(void);
typedef struct Table { u32 count; s32 vals[1]; } Table;
typedef struct Sub { u8 pad[0x10]; Table *tab; } Sub;
typedef struct Obj { u8 pad[0x1c8]; Sub *sub; } Obj;

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

extern void fn_8023AB28(const char*);
extern char lbl_8034BC10;
void fn_801C62E4(void) {
    fn_8023AB28(&lbl_8034BC10);
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

typedef struct { float x, y, z; } Vec3;
void fn_801C7A2C(Vec3 *v)
{
    int i, j;
    Vec3 t1, t7, t6, t5, t4, t3, t2;

    for (i = 0; i < 7; i++) {
        for (j = i + 1; j < 8; j++) {
            if (v[i].y < v[j].y) {
                t1 = v[j];
                v[j] = v[i];
                v[i] = t1;
            }
        }
    }
    for (i = 0; i < 3; i++) {
        for (j = i + 1; j < 4; j++) {
            if (v[i].x > v[j].x) {
                t2 = v[j];
                v[j] = v[i];
                v[i] = t2;
            }
        }
    }
    for (i = 4; i < 7; i++) {
        for (j = i + 1; j < 8; j++) {
            if (v[i].x > v[j].x) {
                t3 = v[j];
                v[j] = v[i];
                v[i] = t3;
            }
        }
    }
    if (v[0].z < v[1].z) { t4 = v[1]; v[1] = v[0]; v[0] = t4; }
    if (v[2].z > v[3].z) { t5 = v[3]; v[3] = v[2]; v[2] = t5; }
    if (v[4].z < v[5].z) { t6 = v[5]; v[5] = v[4]; v[4] = t6; }
    if (v[6].z > v[7].z) { t7 = v[7]; v[7] = v[6]; v[6] = t7; }
}

extern void fn_801D9634(Vec3 *v, void *out);
void fn_801C588C(Vec3 *a, Vec3 *b, void *out) {
    Vec3 d;
    if (a != 0 && b != 0 && out != 0) {
        d.x = b->x - a->x;
        d.y = b->y - a->y;
        d.z = b->z - a->z;
        fn_801D9634(&d, out);
    }
}

static inline BOOL HasVal(Obj *obj, u32 idx) {
    return obj != NULL && obj->sub != NULL && obj->sub->tab != NULL && obj->sub->tab->count > idx;
}

f32 fn_801C5C80(Obj *obj, u32 idx) {
    f32 result = 0.0f;
    if (HasVal(obj, idx)) {
        result = (f32)obj->sub->tab->vals[idx] / 100.0f;
    }
    return result;
}

f32 fn_801C5D04(Obj *obj, u32 idx) {
    f32 result = 0.0f;
    if (HasVal(obj, idx)) {
        result = (f32)obj->sub->tab->vals[idx] / 100.0f;
    }
    return result;
}
