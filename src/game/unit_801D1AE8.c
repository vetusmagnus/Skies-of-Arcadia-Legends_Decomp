#include "types.h"

void VISetNextFrameBuffer(void *fb);
void VIFlush(void);
void VIWaitForRetrace(void);
extern void *lbl_803476AC;
extern u32 *lbl_803476C0;
void fn_801D4A2C(s32 a, s32 b, s32 c, void *d, s32 e, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5, f32 f6);
extern s32 lbl_80347568[2];
typedef struct Sub { u8 pad[0x20]; s32 val; } Sub;
typedef struct Outer { u8 pad[4]; Sub *sub; } Outer;
void fn_801D5A50(s32 a, s32 b, s32 c, s32 d, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5, f32 f6);
extern Outer *lbl_80347618;
void fn_802275A4(s32 v, s32 flag);
void fn_801E17E0(void *p);
extern Outer *lbl_80347614;
void *fn_801E1BDC(s32 size);
extern s32 lbl_8034761C;
typedef struct Thing { u8 pad[8]; void *f8; void *fc; } Thing;
typedef struct Quad {
    s32 type;  /* 0x00 */
    f32 f04;   /* 0x04 */
    s32 f08;   /* 0x08 */
    void *f0c; /* 0x0C */
    f32 f10;   /* 0x10 */
    f32 f14;   /* 0x14 */
    f32 f18;   /* 0x18 */
    f32 f1c;   /* 0x1C */
    f32 f20;   /* 0x20 */
    f32 f24;   /* 0x24 */
    f32 f28;   /* 0x28 */
    f32 f2c;   /* 0x2C */
} Quad;
typedef struct Ctx {
    u8 pad0[0x50];
    s32 f50;
    u8 pad1[0x18];
    f32 f6c;
    f32 f70;
    f32 f74;
} Ctx;
void fn_802871D8(void *p);
extern Ctx lbl_8030E830;
typedef struct Ent { u32 key; u32 next; s16 val; s16 pad; } Ent;
typedef struct Req { u32 key; void *next; } Req;
extern Ent lbl_802F65C0[8];
typedef struct RelocEnt { u32 ptr; u32 b; u32 c; } RelocEnt;
typedef struct RelocTbl { RelocEnt *ents; s32 count; } RelocTbl;
extern u32 lbl_80312D00[16];
void *memcpy(void *dst, const void *src, u32 n);
extern s32 lbl_8034754C;
extern u8 lbl_8030EA1C[];
typedef struct Ob { u8 pad0[2]; s16 s2; u8 pad1[0x48]; void *p4c; } Ob;
void fn_801DFA9C(void *p, s32 v);
typedef struct Mo { u8 pad0[4]; u8 m4[0x28]; u8 m2c[0x1C]; s32 x48; void *x4c; } Mo;
void njPushMatrixEx(void);
void njPopMatrixEx(void);
void njUnitMatrix(void *m);
void fn_80286EE8(void);
void fn_8028B498(void);
void fn_801E04E8(void *m, s32 a, void *b, void *c);
void *fn_801E184C(void *obj, s32 idx, void *src, s32 n);
extern u8 lbl_802F6748[];
void fn_8024DF5C(u32 a);
void GXClearGPMetric(void);
void GXInvalidateVtxCache(void);
void GXInvalidateTexAll(void);
extern u8 lbl_80311B00[];
void fn_801E1718(void *p);
extern u8 *lbl_80347608;
void fn_801D843C(void *a, s32 b, s32 c, s32 d, s32 e, s32 f);
extern u8 *lbl_80347654;
extern u8 *lbl_80347660;
extern u32 lbl_80312D40[4];
void fn_801E1A74(s32 a, s32 b);
extern s32 lbl_80347550;

void fn_801D1AE8(void) {
    VISetNextFrameBuffer(lbl_803476AC);
    VIFlush();
    VIWaitForRetrace();
    if (*lbl_803476C0 & 1) {
        VIWaitForRetrace();
    }
}

void fn_801D49E4(s32 a, s32 b, s32 c, s32 d, f32 p1, f32 p2, f32 p3, f32 p4) {
    fn_801D4A2C(a, b, c, lbl_80347568, d, 1.0f, 1.0f, p1, p2, p3, p4);
}

void fn_801D4C9C(s32 a, s32 b, s32 c, void *d, s32 e, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5, f32 f6);
void fn_801D4C54(s32 a, s32 b, s32 c, s32 d, f32 p1, f32 p2, f32 p3, f32 p4) {
    fn_801D4C9C(a, b, c, lbl_80347568, d, 1.0f, 1.0f, p1, p2, p3, p4);
}

void fn_801D4F54(s32 a, s32 b, s32 c, void *d, s32 e, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5, f32 f6);
void fn_801D4F0C(s32 a, s32 b, s32 c, s32 d, f32 p1, f32 p2, f32 p3, f32 p4) {
    fn_801D4F54(a, b, c, lbl_80347568, d, 1.0f, 1.0f, p1, p2, p3, p4);
}

void fn_801D51C4(s32 a, s32 b, s32 c, f32 p1, f32 p2, f32 p3, f32 p4) {
    fn_801D5A50(a, b, c, lbl_80347618->sub->val, 1.0f, 1.0f, p1, p2, p3, p4);
}

void fn_801D538C(s32 a, s32 b, s32 c, s32 d, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5, f32 f6);
void fn_801D5210(s32 a, s32 b, s32 c, f32 p1, f32 p2, f32 p3, f32 p4) {
    fn_801D538C(a, b, c, lbl_80347614->sub->val, 1.0f, 1.0f, p1, p2, p3, p4);
}

void fn_801D56C8(s32 a, s32 b, s32 c, s32 d, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5, f32 f6);
void fn_801D525C(s32 a, s32 b, s32 c, f32 p1, f32 p2, f32 p3, f32 p4) {
    fn_801D56C8(a, b, c, lbl_80347614->sub->val, 1.0f, 1.0f, p1, p2, p3, p4);
}

void fn_801D52A8(s32 a, s32 b, s32 c, f32 p1, f32 p2, f32 p3, f32 p4) {
    fn_801D5A50(a, b, c, lbl_80347614->sub->val, 1.0f, 1.0f, p1, p2, p3, p4);
}

extern Outer *lbl_80347610;
void fn_801D5DD8(s32 a, s32 b, s32 c, s32 d, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5, f32 f6);
void fn_801D52F4(s32 a, s32 b, s32 c, f32 p1, f32 p2, f32 p3, f32 p4) {
    fn_801D5DD8(a, b, c, lbl_80347610->sub->val, 1.0f, 1.0f, p1, p2, p3, p4);
}

extern Outer *lbl_8034760C;
void fn_801D5340(s32 a, s32 b, s32 c, f32 p1, f32 p2, f32 p3, f32 p4) {
    fn_801D5DD8(a, b, c, lbl_8034760C->sub->val, 1.0f, 1.0f, p1, p2, p3, p4);
}

void fn_801D668C(void) {
    if (lbl_80347614 != 0) {
        fn_802275A4(lbl_80347614->sub->val, 1);
        fn_801E17E0(lbl_80347614);
        lbl_80347614 = 0;
    }
}

void fn_801D6850(void) {
    if (lbl_80347608 == 0) {
        lbl_80347608 = fn_801E1BDC(0x10000 - 0x600);
    }
    lbl_8034761C = -1;
}

void fn_801D6944(Thing *t) {
    if (t->f8 != 0) {
        t->f8 = 0;
    }
    if (t->fc != 0) {
        fn_801E17E0(t->fc);
        t->fc = 0;
    }
}

extern s32 lbl_80347634;
void fn_801D71BC(s32 v) {
    lbl_80347634 = v;
}

void fn_801D7868(Quad *q, void *p, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5, f32 f6, f32 f7) {
    q->type = 3;
    q->f04 = f1;
    q->f08 = 1;
    q->f0c = p;
    q->f10 = f2;
    q->f20 = f3;
    q->f14 = f4;
    q->f24 = f5;
    q->f18 = f6;
    q->f28 = f7;
    q->f1c = 0.0f;
    q->f2c = 0.0f;
}

void fn_801D78A8(Quad *q, void *p, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5) {
    f32 a = f2 + f4;
    f32 b = f3 + f5;
    q->type = 4;
    q->f04 = f1;
    q->f08 = 1;
    q->f0c = p;
    q->f10 = f2;
    q->f20 = f3;
    q->f14 = a;
    q->f24 = f3;
    q->f18 = a;
    q->f28 = b;
    q->f1c = f2;
    q->f2c = b;
}

typedef struct Msg {
    s16 x0;
    s16 x2;
    s16 x4;
    s16 x6;
    s32 x8;
    s32 xc;
} Msg;
extern void fn_80291424(Msg*, s16);
void fn_801D8080(Msg* a, s16 i) {
    fn_80291424(a, i);
}

void fn_801D9CF0(f32 f1, f32 f2, f32 f3) {
    lbl_8030E830.f50 = 1;
    lbl_8030E830.f6c = f1;
    lbl_8030E830.f70 = f2;
    lbl_8030E830.f74 = f3;
    fn_802871D8(&lbl_8030E830);
}

s32 fn_801DA66C(Req *p) {
    s32 i = 8;
    Ent *e = lbl_802F65C0;
    do {
        if (p->key == e->key) {
            return e->val;
        }
        e++;
    } while (--i > 0);
    return -1;
}

void fn_801DAE18(RelocTbl *t, u32 off) {
    RelocEnt *e;
    s32 i;
    if (t->ents == 0) {
        return;
    }
    e = (RelocEnt *)((u32)t->ents + off);
    t->ents = e;
    for (i = 0; i < t->count; i++, e++) {
        e->ptr += off;
    }
}

void fn_801DBA0C(void) {
    lbl_80312D00[0] = 0;
    lbl_80312D00[1] = 0;
    lbl_80312D00[2] = 0;
    lbl_80312D00[3] = 0;
    lbl_80312D00[4] = 0;
    lbl_80312D00[5] = 0;
    lbl_80312D00[6] = 0;
    lbl_80312D00[7] = 0;
    lbl_80312D00[8] = 0;
    lbl_80312D00[9] = 0;
    lbl_80312D00[10] = 0;
    lbl_80312D00[11] = 0;
    lbl_80312D00[12] = 0;
    lbl_80312D00[13] = 0;
    lbl_80312D00[14] = 0;
    lbl_80312D00[15] = 0;
}

extern s32 lbl_803476D8;
s32 fn_801DBCCC(void) {
    return lbl_803476D8;
}

void fn_801DBE1C(s32 a, ...) {
}

void fn_801DBF90(void) {
}

void fn_801DD71C(void *dst) {
    s32 idx;
    if (lbl_8034754C > 0) {
        idx = lbl_8034754C - 1;
        lbl_8034754C = idx;
        if (dst != 0) {
            memcpy(dst, lbl_8030EA1C + idx * 0x40, 0x40);
        }
    }
}

void fn_801DD7CC(void) {
    lbl_8034754C = 0;
}

void fn_801DD95C(void *p)
{
    if (p != 0) {
        fn_801E17E0(p);
    }
}

void fn_801DF94C(Ob *o) {
    fn_801DFA9C(o->p4c, o->s2);
    fn_801E17E0(o);
}

void fn_801E06E0(Mo *o) {
    njPushMatrixEx();
    fn_80286EE8();
    fn_8028B498();
    njUnitMatrix(0);
    fn_801E04E8(&o->m4, o->x48, o->x4c, &o->m2c);
    njPopMatrixEx();
}

void fn_801E0CB8(Mo *o) {
    njPushMatrixEx();
    fn_80286EE8();
    fn_8028B498();
    njUnitMatrix(0);
    fn_801E0AC0(&o->m4, o->x48, o->x4c, &o->m2c);
    njPopMatrixEx();
}

void fn_801E1A2C(void *src, u32 n) {
    void *q;
    if (n == 0) {
        n = 0x20;
    }
    q = fn_801E184C(lbl_802F6748, -1, src, n);
    *(u32 *)((u8 *)q - 0x10) = 0;
}

void fn_801D23E0(void)
{
    fn_8024DF5C(0x10000 - 0x115);
    GXClearGPMetric();
    GXInvalidateVtxCache();
    GXInvalidateTexAll();
}

void fn_801D4954(void *p)
{
    if (p != 0) {
        fn_801E17E0(p);
    }
}

void fn_801D61C4(void *p)
{
    if (p != lbl_80311B00) {
        fn_801E1718(p);
    }
}

void *fn_801D665C(void)
{
    lbl_8034761C = lbl_8034761C + 1;
    if ((u32)lbl_8034761C > 0x7cf) {
        lbl_8034761C = 0;
    }
    return lbl_80347608 + (lbl_8034761C << 5);
}

void fn_801D7A08(u8 *p, f32 a, f32 b)
{
    *(f32 *)(p + 0x44) = a;
    *(f32 *)(p + 0x48) = b;
}

void fn_801D7A14(u8 *p, f32 a, f32 b, f32 c, f32 d)
{
    *(f32 *)(p + 0x34) = a;
    *(f32 *)(p + 0x38) = b;
    *(f32 *)(p + 0x3c) = c;
    *(f32 *)(p + 0x40) = d;
}

void fn_801D8818(void *a, s32 b, s32 c, s32 d, s32 e)
{
    fn_801D843C(a, b, c, d, 0, e);
}

void *fn_801D8D18(void)
{
    u8 *p = lbl_80347654;
    if (p[0x19] == 7) {
        return *(void **)(*(u8 **)(p + 0x24) + 4);
    }
    return (void *)-1;
}

void fn_801D8D3C(void)
{
    u8 *p = lbl_80347660;
    if (p != 0) {
        p[0x19] = 10;
    }
}

s32 fn_801D8EE8(void)
{
    u8 *p = lbl_80347660;
    if (p[0x19] == 10) {
        return *(s8 *)(*(u8 **)(p + 0x24) + 1);
    }
    return *(s8 *)(*(u8 **)(p + 0x24) + 5);
}

void fn_801DBA58(u32 a, u32 b, u32 c)
{
    lbl_80312D40[0] = a;
    lbl_80312D40[1] = b;
    lbl_80312D40[2] = c;
    lbl_80312D40[3] = c;
}

void fn_801DD984(void)
{
    fn_801E1A74(0x14, 1);
}

void fn_801E0D50(u32 *dst, u32 *src, s32 size)
{
    u32 t;
    s32 n = size / 4;
    do {
        t = *dst;
        *dst++ = *src;
        *src++ = t;
        n--;
    } while (n != 0);
}

s32 fn_801E183C(void)
{
    return lbl_80347550 == 0;
}
