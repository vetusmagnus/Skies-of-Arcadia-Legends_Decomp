#include "types.h"
#include "string.h"
#include <math.h>
#include "ninja.h"
#include "game/drawstate.h"
#include "game/task.h"
#include "game/evobj.h"
#include <dolphin/os/OSFastCast.h>
#include "game/unit_800972AC.h"
extern void fn_800B0900(void);
typedef struct WaveVtx {
    f32 x, y, z;    /* 0x00 */
    f32 u, v;       /* 0x0C */
    s32 w;          /* 0x14 */
} WaveVtx;
typedef struct WaveQuad {
    WaveVtx a, b;
} WaveQuad;
/* The wave effect block (a strip of WaveQuads drawn by fn_800B0278). */
typedef struct {
    void *x0;       /* 0x00 WaveQuad strip */
    s16 x4;         /* 0x04 vertex count */
    s16 mode;       /* 0x06 */
    f32 amp;        /* 0x08 */
    f32 k;          /* 0x0C */
    f32 ph1;        /* 0x10 */
    f32 ph2;        /* 0x14 */
    f32 spd;        /* 0x18 */
} Blk_80303634;
extern Blk_80303634 lbl_80303634;
void* fn_801E1A2C(s32 a, u32 size);
void fn_801E1784(void *p);
extern void fn_8015ED90(void *p);
extern void fn_8015EB8C(void *p, s32 id, void *cb);
extern void fn_800B45D4(void *p, void *q);
extern void fn_800ABEB0(void);
/* EvExt.info of a kind that only checks its word count. */
typedef struct {
    u32 count;
} EvInfoCount;
/* Four separate .bss arrays of the unit, reached through its section base. */
extern s32 lbl_803033B0[6];
extern s32 lbl_803033C8[6];
extern s32 lbl_803033E0[6];
extern s32 lbl_803033F8[6];
s32 lbl_803033B0[6];
/* count */
s32 lbl_803033C8[6];
s32 lbl_803033E0[6];
s32 lbl_803033F8[6];

static inline EvInfoCount* CountInfo(EvObj* e) {
    return e->ext->info;
}
static inline EvObj* TaskEv(Task* t) {
    return t->work;
}
extern void fn_80100B74(Task* t);
extern void* fn_80226704(void* list, void* cb, s32 size);
typedef struct {
    u32 flags;
    DrawState ds;
    s32 x2c;
    u8 pad30[4];
    void* buf;    /* 0x34 */
    void* x38;
    u8 x3c[0xc];
    u8* x48;
    s32 x4c;
    u8 x50[0x48];
} State_800B016C;
extern State_800B016C lbl_80303650;
extern void* fn_80227E74(void);
extern void fn_80297DB4(void* a, void* b, s32 c, s32 d, s32 e);
extern void fn_80297DA4(void* a, void* b, void* c, s32 d);
extern s32 fn_80007528(u8** p);
extern s32* fn_80298E6C(void);
extern void fn_80297B5C(void* p);
extern void fn_801E1784(void* p);
typedef struct {
    u8 pad[4];
    s32 mode;
} Work_800B0FD0;
typedef struct {
    u8 pad[0x18];
    u8 flags;
    u8 state;
    u8 pad1a[0x24 - 0x1a];
    Work_800B0FD0* work;
} Obj_800B0FD0;
typedef struct {
    s32 mode;
    void *x4;
    u8 pad[0x14];
} Blk_80303618;
/* Defined (not extern) so that MWCC addresses the three from one pooled base, as the original does. */
Blk_80303618 lbl_80303618;
Blk_80303634 lbl_80303634;
State_800B016C lbl_80303650;
extern void fn_80226D14(void);
extern void fn_80296ED4(s32 v);
extern void fn_800B0278(void);
extern void fn_800AF780(void);
extern void fn_800AF8F8(void);
extern void DrawStateDefault2D();
typedef struct {
    u8 pad[0x1a0];
    s32 x1a0;
    u8 pad1a4[0x260 - 0x1a4];
    void* x260;
    u8 pad264[0x31c - 0x264];
    void* x31c;
} Hook_800B2334;
typedef struct {
    u8 pad[0x48];
    u32 x48;
} Cfg_800B2334;
typedef struct {
    u8 pad[0x10];
    Cfg_800B2334* cfg;
} Link_800B2334;
typedef struct {
    u8 pad0[0x18];
    u32 x18;
    u8 pad1c[0x100 - 0x1c];
    void* x100;
    u8 pad104[0x1c8 - 0x104];
    Link_800B2334* link;
    u8 pad1cc[0x1d8 - 0x1cc];
    Hook_800B2334* hook;
    u8 pad1dc[0x25c - 0x1dc];
    void* x25c;
    u8 pad260[0x26c - 0x260];
    u8 x26c;
} Work_800B2334;
typedef struct {
    u8 pad[0x1fa];
    u8 x1fa;
    u8 x1fb;
} Sub_800B2334;
typedef struct {
    u8 pad[0x19];
    u8 state;
    u8 x1a;
    u8 x1b;
    u8 pad1c[0x24 - 0x1c];
    Sub_800B2334* work;
} Obj_800B2334;
extern void fn_80227810(void* p);
extern void fn_800ABEB0();
extern void fn_800ABE9C();
typedef struct {
    s32 mode;
    f32 *pts;
    u16 n;
    u8 pad_0a[4];
    u16 limit;
    u32 frame;
    f32 scale;
    f32 num;
} Blk;
typedef struct {
    u8 pad[4];
    DrawState ds;
} Fx;
extern void fn_80297DC8(s32 a);
extern void fn_80291064(void *p, s32 a, s32 b);
typedef struct {
    u8 pad0[8];
    u32 x8;
} Hdr;
typedef struct {
    u8 pad[0x10];
    EvInfoCount *cnt;
} Link;
typedef struct {
    Hdr *hdr;
} Hk;
typedef struct {
    u8 pad0[0x100];
    Hk *x100;
    u8 pad104[0x1c8 - 0x104];
    Link *link;
    u8 pad1cc[0x1fa - 0x1cc];
    u8 x1fa;
    s8 x1fb;
    u8 pad1fc[0x25c - 0x1fc];
    void *x25c;
} Work;
typedef struct {
    u8 pad0[0x18];
    u8 flags;
    u8 state;
    u8 pad1a[0x24 - 0x1a];
    Work *work;
} Obj_800B2428;
typedef struct Col_800B2588 {
    u8 a, r, g, b;
} Col_800B2588;
typedef struct Q_800B2588 {
    u32 flags;
    u8 pad4[0x78 - 4];
    Col_800B2588 col78;
} Q_800B2588;
typedef struct QO_800B2588 {
    u8 pad0[0x268];
    Q_800B2588 *p268;
} QO_800B2588;
typedef struct Tbl_800B2588 {
    u32 w0;
    u32 w4;
    s32 w8;
    u32 wc;
    u32 w10;
    u32 w14;
    s32 w18;
    s32 w1c;
} Tbl_800B2588;
typedef struct Sub_800B2588 {
    u8 pad0[0x10];
    Tbl_800B2588 *tbl;
} Sub_800B2588;
typedef struct Aux_800B2588 {
    u8 pad0[0x1a0];
    s32 w1a0;
} Aux_800B2588;
typedef struct Ctx_800B2588 {
    u8 pad0[0x1c8];
    Sub_800B2588 *sub;      /* 0x1c8 */
    u8 pad1cc[0x1d8 - 0x1cc];
    Aux_800B2588 *aux;      /* 0x1d8 */
    u8 pad1dc[0x1fb - 0x1dc];
    u8 b1fb;
    u8 pad1fc[0x26c - 0x1fc];
    u8 b26c;
} Ctx_800B2588;
typedef struct Obj_800B2588 {
    u8 pad0[0x18];
    u8 flags18;
    u8 state;
    u8 pad1a;
    u8 b1b;
    u8 pad1c[0x24 - 0x1c];
    Ctx_800B2588 *ctx;
} Obj_800B2588;
typedef struct Inner_800B2588 {
    void *p00;
    s32 w04;
    s32 w08;
    u8 pad0c[0xa8 - 0xc];
    s32 wa8;
    s32 wac;
} Inner_800B2588;
typedef struct Task_800B2588 {
    u8 pad0[0x24];
    Inner_800B2588 *inner;
    u8 pad28[0x40 - 0x28];
} Task_800B2588;
/* Scales a 0..1 float to a u8 (x * 255) with the SDK fast cast (psq_st through GQR2).
 * The original calls the Dolphin SDK inline __OSf32tou8 from <dolphin/os/OSFastCast.h>.
 * The game code itself is plain C. Siblings: fn_8009E4B8 = __OSu8tof32(b) * K,
 * fn_8009E4D4 = __OSf32tou8((K0 + x) * 255). */
typedef unsigned char u8;
typedef float f32;
extern s32 fn_8015E600(EvObj*);
extern void fn_8015EBF4(EvObj*);
extern MapInfo lbl_80311AC0;
typedef unsigned char u8;
typedef struct Ref_800AE300 {
    u8 pad0[0x18];
    u8 flags18;
    u8 pad19[0x24 - 0x19];
    void *p24;
} Ref_800AE300;
typedef struct Work_800AE300 {
    Ref_800AE300 *ref;  /* 0x00 */
    s32 w04;
    s32 w08;
    s32 list[0x94 / 4]; /* 0x0c */
    s32 n;              /* 0xa0 */
    s32 pada4;
    s32 wa8;
    s32 wac;
} Work_800AE300;
typedef struct Obj_800AE300 {
    u8 pad0[8];
    Ref_800AE300 *ref;
    u8 pad0c[0x18 - 0xc];
    u8 flags18;
    u8 state;
    u8 pad1a[0x24 - 0x1a];
    Work_800AE300 *work;
} Obj_800AE300;
extern void fn_800AE4E0(s32 a, s32 *out);
extern s32 fn_800B2DC0(void *c, s32 idx, s32 a, s32 b, f32 f);
extern struct { u8 pad[0x88]; u32 flags; u8 pad8c[0x13C - 0x8C]; u32 x13c; } lbl_80310B3C;

#define BSW(x) ((((x) >> 24) & 0xff) | (((x) >> 8) & 0xff00) | (((x) << 8) & 0xff0000) | ((x) << 24))

void fn_800B0F0C(void) {
    fn_800B0900();
    memset(&lbl_80303618, 0, 0x1c);
    memset(&lbl_80303634, 0, 0x1c);
}

static inline void Free_800B0900(void **pp)
{
    if (*pp != NULL) {
        fn_801E1784(*pp);
        *pp = NULL;
    }
}

void fn_800B0900(void)
{
    Blk_80303618 *b;
    State_800B016C *s;
    if (lbl_80303634.x0 != NULL) {
        Free_800B0900(&lbl_80303634.x0);
    }
    b = &lbl_80303618;
    if (b->x4 != NULL) {
        Free_800B0900(&b->x4);
    }
    s = &lbl_80303650;
    if (s->buf != NULL) {
        fn_80297B5C(s->x38);
        Free_800B0900(&s->buf);
    }
    lbl_80303650.x2c = 0;
    lbl_80303650.flags &= ~1;
    lbl_80303650.flags &= ~4;
}

extern f32 njSin(Angle a);
extern f32 njCos(Angle a);

void fn_800B0278(void)
{
    s32 i;
    WaveQuad *vp;
    f32 s;
    f32 f27;
    f32 f26;
    f32 f25;
    f32 z;
    f32 q;

    z = 0.0f;
    vp = lbl_80303634.x0;
    switch (lbl_80303634.mode) {
    case 2:
        z = -0.01f;
    case 0:
        q = 1280.0f / lbl_80303634.x4;
        f27 = (0.25f * (0.0049087387f * lbl_80303634.amp)) * q;
        f26 = 0.001953125f * lbl_80303634.k;
        f25 = 0.9375f;
        for (i = 0; i < lbl_80303634.x4; i += 2) {
            s = f26 * njSin((10430.37835 * (lbl_80303634.ph1 + f27 * i)));
            if (s > 0.0f) {
                vp->a.v = s;
                vp->a.z += z;
                vp->b.v = f25;
                vp->b.z += z;
                vp++;
            } else {
                vp->a.v = 0.0f;
                vp->a.z += z;
                vp->b.v = f25 + s;
                vp->b.z += z;
                vp++;
            }
        }
        break;
    case 3:
        z = -0.01f;
    case 1:
        q = 960.0f / lbl_80303634.x4;
        f27 = (0.25f * (0.006544984f * lbl_80303634.amp)) * q;
        f26 = 0.0009765625f * lbl_80303634.k;
        f25 = 0.625f;
        for (i = 0; i < lbl_80303634.x4; i += 2) {
            s = f26 * njSin((10430.37835 * (lbl_80303634.ph1 + f27 * i)));
            if (s > 0.0f) {
                vp->a.u = s;
                vp->a.z += z;
                vp->b.u = f25;
                vp->b.z += z;
                vp++;
            } else {
                vp->a.u = 0.0f;
                vp->a.z += z;
                vp->b.u = f25 + s;
                vp->b.z += z;
                vp++;
            }
        }
        break;
    }
    DrawStatePush(&lbl_80303650.ds);
    fn_80297DC8(0x1869E);
    fn_80291064(lbl_80303634.x0, lbl_80303634.x4, 0);
    DrawStatePop(0);
    switch (lbl_80303634.mode) {
    case 2:
        vp = lbl_80303634.x0;
        for (i = 0; i < lbl_80303634.x4; i += 2) {
            s = -(0.5f * ((f26 * njCos((10430.37835 * (lbl_80303634.ph2 + f27 * i)))) * (1.0f + njCos(lbl_80303634.ph2))));
            if (s > 0.0f) {
                vp->a.v = s;
                vp->a.z -= z;
                vp->b.v = f25;
                vp->b.z -= z;
                vp++;
            } else {
                vp->a.v = 0.0f;
                vp->a.z -= z;
                vp->b.v = f25 + s;
                vp->b.z -= z;
                vp++;
            }
        }
        lbl_80303650.ds.blend_dst = 10;
        DrawStatePush(&lbl_80303650.ds);
        fn_80297DC8(0x1869E);
        fn_80291064(lbl_80303634.x0, lbl_80303634.x4, 1);
        lbl_80303650.ds.blend_dst = 6;
        DrawStatePop(0);
        break;
    case 3:
        vp = lbl_80303634.x0;
        for (i = 0; i < lbl_80303634.x4; i += 2) {
            s = -(0.5f * ((f26 * njCos((10430.37835 * (lbl_80303634.ph2 + f27 * i)))) * (1.0f + njCos(lbl_80303634.ph2))));
            if (s > 0.0f) {
                vp->a.u = s;
                vp->a.z -= z;
                vp->b.u = f25;
                vp->b.z -= z;
                vp++;
            } else {
                vp->a.u = 0.0f;
                vp->a.z -= z;
                vp->b.u = f25 + s;
                vp->b.z -= z;
                vp++;
            }
        }
        lbl_80303650.ds.blend_dst = 10;
        DrawStatePush(&lbl_80303650.ds);
        fn_80297DC8(0x1869E);
        fn_80291064(lbl_80303634.x0, lbl_80303634.x4, 1);
        lbl_80303650.ds.blend_dst = 6;
        DrawStatePop(0);
        break;
    }
    lbl_80303634.ph1 += lbl_80303634.spd;
    lbl_80303634.ph2 = 0.6666f * lbl_80303634.spd + lbl_80303634.ph2;
    if (lbl_80303634.ph1 > 3.1415927f) {
        lbl_80303634.ph1 -= 6.2831855f;
    } else if (lbl_80303634.ph1 < -3.1415927f) {
        lbl_80303634.ph1 += 6.2831855f;
    }
    if (lbl_80303634.ph2 > 3.1415927f) {
        lbl_80303634.ph2 -= 6.2831855f;
    } else if (lbl_80303634.ph2 < -3.1415927f) {
        lbl_80303634.ph2 += 6.2831855f;
    }
}

void fn_800B0F54(void) {
    memset(&lbl_80303618, 0, sizeof(Blk_80303618));
    memset(&lbl_80303634, 0, sizeof(Blk_80303634));
    lbl_80303634.x0 = 0;
    lbl_80303618.x4 = 0;
    lbl_80303634.x4 = 0;
    lbl_80303650.flags = 0;
    lbl_80303650.x2c = 0;
    lbl_80303650.buf = 0;
    DrawStateDefault2D(&lbl_80303650.ds);
}


void fn_800B2B34(Task *self, EvObj *c)
{
    if (CountInfo(c)->count < 0x33) {
        self->state = 4;
    } else {
        self->x1b = 0xfa;
        c->x26c = 1;
        fn_8015ED90(self);
        fn_8015EB8C(c, 0, fn_800ABEB0);
        fn_8015EB8C(c, 0xd, fn_800ABE9C);
        if (c->sub != 0) {
            c->sub->x1a0 = 0;
        }
        c->x268 = fn_801E1A2C(1, 0x114);
        c->x18 |= 0x1800;
        c->x08 = 1;
        fn_800B45D4(c, c->x268);
        TaskEv(self)->x1fa = 1;
        self->state = 2;
    }
}

void fn_800B016C(void) {
    lbl_80303650.buf = fn_801E1A2C(1, 0x100000);
    if (lbl_80303650.buf != NULL) {
        lbl_80303650.x38 = fn_80227E74();
        fn_80297DB4(lbl_80303650.x50, lbl_80303650.buf, 6, 0x400, 0x200);
        fn_80297DA4(lbl_80303650.x3c, lbl_80303650.x50, lbl_80303650.x38, 0x8800000);
        lbl_80303650.x4c = 1;
        lbl_80303650.x48 = lbl_80303650.x3c;
        if (fn_80007528(&lbl_80303650.x48) < 0) {
            lbl_80303650.x2c = fn_80298E6C()[2];
            fn_80297B5C(lbl_80303650.x38);
            if (lbl_80303650.buf != NULL) {
                fn_801E1784(lbl_80303650.buf);
                lbl_80303650.buf = NULL;
            }
        } else {
            lbl_80303650.x2c = 0;
        }
    }
}

void fn_800B0FD0(Obj_800B0FD0* o) {
    Work_800B0FD0* w = o->work;
    if (o->flags & 0x20) {
        o->flags |= 0x40;
        return;
    }
    switch (o->state) {
    case 0:
    case 0xfe:
        o->state = 0xa;
    case 0xa:
        switch (w->mode) {
        case 0:
            if (!(lbl_80303650.flags & 1)) {
                o->state = 0xff;
                break;
            }
            fn_80226D14();
            if (!(lbl_80303650.flags & 8)) {
                fn_80296ED4(0);
            }
            fn_800B0278();
            fn_80296ED4(0x2000);
            break;
        case 1:
            if (!(lbl_80303650.flags & 1)) {
                o->state = 0xff;
                break;
            }
            if (!(lbl_80303650.flags & 8)) {
                fn_80296ED4(0);
            }
            if (lbl_80303618.mode == 6) {
                fn_800AF780();
            } else {
                fn_800AF8F8();
            }
            fn_80296ED4(0x2000);
            break;
        }
        break;
    case 0xff:
        o->flags |= 0x40;
        break;
    }
}

void fn_800B2334(Obj_800B2334* o, Work_800B2334* w) {
    Hook_800B2334* h;
    o->x1b = 0xfa;
    w->x26c = 1;
    fn_8015ED90(o);
    h = w->hook;
    if (h != NULL) {
        h->x1a0 = 0;
        h->x260 = fn_800ABEB0;
        h->x31c = fn_800ABE9C;
    }
    w->x100 = (void*)fn_800A1B50((Obj_UNIT0000*)w);
    if (w->x100 != NULL) {
        fn_80227810(w->x100);
    }
    fn_800ADF98((u8*)w);
    w->x25c = fn_801E1A2C(1, 0x28);
    DrawStateDefault2D();
    w->x18 |= 0x1800;
    if (w->link->cfg->x48 != 0) {
        o->work->x1fa = 1;
        o->state = 2;
    } else {
        o->work->x1fb = 1;
        o->state = 1;
    }
}

void fn_800AF780(void) {
    s32 i;
    s32 count;
    f32 *p;
    DrawStatePush(&(*(Fx*)&lbl_80303650).ds);
    if ((*(Blk*)&lbl_80303618).frame == 0) {
        fn_80226D14();
    }
    count = (*(Blk*)&lbl_80303618).n * (*(Blk*)&lbl_80303618).n * 4;
    for (i = 0; i < count; i++) {
        f32 *pt = (f32 *)((u8 *)(*(Blk*)&lbl_80303618).pts + i * 0x18);
        f32 dx = (*(Blk*)&lbl_80303618).scale * (pt[0] - 320.0f);
        f32 dy = (*(Blk*)&lbl_80303618).scale * (pt[1] - 240.0f);
        f32 d;
        dx = dx * dx;
        dy = dy * dy;
        d = dx + dy;
        if (d) {
            pt[2] = (*(Blk*)&lbl_80303618).num / d;
        } else {
            pt[2] = (*(Blk*)&lbl_80303618).num;
        }
        if (i % 4 == 3) {
            fn_80297DC8(0x1869E);
            fn_80291064((u8 *)(*(Blk*)&lbl_80303618).pts + (i - 3) * 0x18, 4, 0);
        }
    }
    (*(Blk*)&lbl_80303618).frame++;
    if ((*(Blk*)&lbl_80303618).frame >= (*(Blk*)&lbl_80303618).limit) {
        fn_800B0900();
    }
    DrawStatePop(0);
}

void fn_800B2428(Obj_800B2428 *o) {
    extern void fn_800B2334(Obj_800B2428 *o, Work *w);
    extern s32 fn_8015E600(Work *w);
    extern s32 fn_8015F218(Work *w);
    extern void fn_800B1108(Obj_800B2428 *o, Work *w);
    extern void fn_8015EBF4(Work *w);
    extern void fn_801E1784(void *p);
    extern void fn_802275A4(Hk *h, s32 a);
    extern void fn_80100B74(Obj_800B2428 *o);
    Work *w = o->work;
    if (o->flags & 0x20) {
        o->state = 0xff;
    }
    switch (o->state) {
    case 0:
        fn_800B2334(o, w);
    case 1:
        if (w->x1fb != 0) {
            w->x1fb = 0;
        }
        if (fn_8015E600(w) != 0 && fn_8015F218(w) == 1) {
            o->work->x1fa = 1;
            o->state = 2;
        } else {
            break;
        }
    case 2:
        fn_800B1108(o, w);
        break;
    case 0xff:
    case 3:
        fn_8015EBF4(w);
        if (w->x25c != NULL) {
            if (w->x25c != NULL) {
                fn_801E1784(w->x25c);
                w->x25c = NULL;
            }
        }
        if (w->x100 != NULL && w->x100->hdr->x8 != 0) {
            fn_802275A4(w->x100, 0);
        }
        fn_80100B74(o);
        break;
    case 4:
        if (w->link->cnt->count >= 0x33) {
            o->state = 0;
        }
        break;
    case 5:
        break;
    }
}

void fn_800B2588(Obj_800B2588 *o)
{
    extern void fn_8015ED90(void *o);
    extern void fn_8015EB8C(void *c, s32 id, void *cb);
    extern void fn_8015E600(void *c);
    extern void fn_8015EBF4(void *c);
    extern void fn_80100B74(void *o);
    extern void *fn_801094C8(u32 id);
    extern QO_800B2588 *fn_8015F1A0(u16 id);
    extern Task_800B2588 *fn_80226704(void *parent, void *cb, s32 size);
    extern void fn_800ABE9C(void);
    extern void fn_800AE300(void);
    Tbl_800B2588 *tbl;
    Ctx_800B2588 *c;
    c = o->ctx;
    tbl = c->sub->tbl;

    if (o->flags18 & 0x20) {
        o->state = 0xff;
    }
    switch (o->state) {
    case 0:
        if (c->sub->tbl->w0 < 8) {
            o->state = 4;
            break;
        }
        o->b1b = 0xfa;
        c->b26c = 1;
        fn_8015ED90(o);
        fn_8015EB8C(c, 0, fn_800ABEB0);
        fn_8015EB8C(c, 0xd, fn_800ABE9C);
        if (c->aux != 0) {
            c->aux->w1a0 = 0;
        }
        o->state = 1;
    case 1: {
        s32 ready = 0;
        if (lbl_80311AC0.map >= 500 && lbl_80311AC0.map < 600) {
            ready = 1;
        }
        ready = (ready != 0);
        if (ready) {
            break;
        }
        fn_8015E600(c);
        break;
    }
    case 2: {
        u32 id;
        void *ref;
        QO_800B2588 *q;
        Q_800B2588 *r;
        Col_800B2588 col;
        s32 w8;
        Task_800B2588 *n;
        fn_8015E600(c);
        id = tbl->w4;
        ref = fn_801094C8(id);
        q = fn_8015F1A0(id);
        r = q->p268;
        col.a = 0xff;
        col.r = tbl->wc;
        col.g = tbl->w10;
        col.b = tbl->w14;
        w8 = tbl->w8;
        if (r != 0) {
            r->col78 = col;
            r->flags |= 0x200;
        }
        n = fn_80226704(o, fn_800AE300, 0xb0);
        if (n != 0) {
            n->inner = (Inner_800B2588 *)((u8 *)n + 0x40);
            n->inner->p00 = ref;
            n->inner->w04 = w8;
            n->inner->w08 = 3;
            n->inner->wa8 = tbl->w18;
            n->inner->wac = tbl->w1c;
            if (n->inner->wac == 0) {
                n->inner->wac = 0xd;
            }
        }
        o->ctx->b1fb = 1;
        o->state = 1;
        break;
    }
    case 0xfe:
        break;
    case 3:
    case 0xff:
        fn_8015EBF4(c);
        fn_80100B74(o);
        break;
    case 4:
        if (c->sub->tbl->w0 >= 8) {
            o->state = 0;
        }
        break;
    }
}

static inline s32 Has(Work_800AE300 *w, s32 v)
{
    s32 k = w->n;
    for (;;) {
        k--;
        if (k < 0) {
            return 0;
        }
        if (v == w->list[k]) {
            return 1;
        }
    }
}

void fn_800AE300(Obj_800AE300 *o)
{
    Work_800AE300 *w;
    w = o->work;
    if ((o->ref->flags18 & 0x40) || (w->ref->flags18 & 0x40)) {
        o->flags18 |= 0x40;
        return;
    }
    switch (o->state) {
    case 0:
        fn_800B2DC0(w->ref->p24, w->w04, w->wa8, w->wac, 1.0f);
        w->list[w->n++] = w->w04;
        o->state++;
        break;
    case 1: {
        s32 i, j, n;
        s32 buf[6];
        n = w->n;
        for (i = 0; i < n; i++) {
            fn_800AE4E0(w->list[i], buf);
            for (j = 0; j < 6; j++) {
                if (!Has(w, buf[j])) {
                    fn_800B2DC0(w->ref->p24, buf[j], w->wa8, w->wac, 0.25f * (f32)w->w08);
                    w->list[w->n++] = buf[j];
                }
            }
        }
        o->state++;
        break;
    }
    case 2:
        w->w08--;
        if (w->w08 != 0) {
            o->state = 1;
        } else {
            o->flags18 |= 0x40;
        }
        break;
    }
}
extern s32 fn_8015F218(EvObj*);

/* One key of the timed-event record: at frame `frame`, act on item `item` (1-based). */
typedef struct {
    s32 item;   /* 0x00: 0 = none */
    s32 frame;  /* 0x04 */
    u32 pct;    /* 0x08: weight in percent */
    s32 c;      /* 0x0C */
    s32 d;      /* 0x10 */
} EvKey;
/* EvExt.info of the timed-event kind: a count-prefixed word table followed by up to 0x30 keys. */
typedef struct {
    u32 count;  /* 0x00 number of words present */
    u32 id;     /* 0x04 */
    u32 length; /* 0x08 frames */
    u32 loop;   /* 0x0C */
    u8 pad10[0x24 - 0x10];
    EvKey keys[1]; /* 0x24 */
} EvInfoKeys;
static inline EvInfoKeys* KeysInfo(EvObj* e) {
    return e->ext->info;
}

extern void *fn_8015F1A0(u16 id);
extern s32 fn_800B2E84(void *p, s32 idx, s32 v);

void fn_800B2800(Task *t, EvObj *w) {
    EvInfoKeys *info = w->ext->info;
    u32 lim = 7;
    EvKey *e;
    s32 i;
    fn_8015E600(w);
    if (w->x1fa != 0) {
        w->x268 = fn_8015F1A0(info->id);
        w->x22e = 0;
        w->x230 = info->length;
        w->x1fa = 0;
    }
    if (w->x22e >= w->x230) {
        if (info->loop != 0) {
            w->x22e = 0;
        } else {
            t->state = 1;
        }
    }
    e = KeysInfo(w)->keys;
    for (i = 0; i < 0x30; i++) {
        EvInfoKeys *c;
        f32 f;
        s32 item;
        s32 frame;
        s32 cc;
        s32 d;
        lim += 4;
        c = w->ext->info;
        if (c->count < lim) {
            break;
        }
        item = e->item;
        frame = e->frame;
        cc = e->c;
        d = e->d;
        f = 0.01f * e->pct;
        e++;
        if (f <= 0.0f || f > 1.0f) {
            f = 1.0f;
        }
        if (item != 0 && d != 0 && frame == w->x22e) {
            if (cc != 0) {
                fn_800B2DC0(w->x268, item - 1, cc, d, f);
            } else {
                fn_800B2E84(w->x268, item - 1, d);
            }
        }
    }
    w->x22e++;
}

static inline BOOL MapInRange(void) {
    s32 in = 0;
    if (lbl_80311AC0.map >= 500 && lbl_80311AC0.map < 600) {
        in = 1;
    }
    return in ? TRUE : FALSE;
}

void fn_800B29AC(Task *o) {
    EvObj *w = o->work;
    if (o->flags & 0x20) {
        o->state = 0xff;
    }
    switch (o->state) {
    case 0:
        if (KeysInfo(w)->count < 8) {
            o->state = 4;
            break;
        }
        o->x1b = 0xfa;
        w->x26c = 1;
        fn_8015ED90(o);
        fn_8015EB8C(w, 0, fn_800ABEB0);
        fn_8015EB8C(w, 0xd, fn_800ABE9C);
        if (w->sub != NULL) {
            w->sub->x1a0 = 0;
        }
        o->state = 1;
    case 1:
        if (!MapInRange()) {
            fn_8015E600(w);
        }
        break;
    case 2:
        fn_800B2800(o, w);
        break;
    case 3:
    case 0xff:
        fn_8015EBF4(w);
        fn_80100B74(o);
        break;
    case 4:
        if (KeysInfo(w)->count >= 8) {
            o->state = 0;
        }
        break;
    case 5:
        break;
    }
}

/* The record list at EvObj.x268 of the fn_800B2B34 kind (0x114 bytes, nodes linked at 0x7C). */
typedef struct ChainNode {
    u8 pad0[0x7c];
    struct ChainNode *next;
} ChainNode;
typedef struct {
    u8 pad0[0x108];
    ChainNode *head;
    ChainNode *tail;
} ChainHead;

extern void fn_800B4EEC(Task *o, EvObj *w);

static inline void ChainClear(ChainHead *p)
{
    ChainNode *q = p->head;
    if (q == NULL) {
        return;
    }
    while (q != NULL) {
        ChainNode *t = q;
        q = q->next;
        if (t != NULL) {
            fn_801E1784(t);
        }
    }
    p->tail = NULL;
    p->head = NULL;
}

static inline void Step(Task *o, EvObj *w) {
    switch (o->state) {
    case 0:
        fn_800B2B34(o, w);
        o->f20 = -10064.0f;
    case 1:
        fn_8015E600(w);
        break;
    case 2:
        {
            EvSub *h = w->sub;
            if (lbl_80310B3C.x13c & 0x200) {
                h->x1a0 = 1;
            } else {
                h->x1a0 = 0;
            }
        }
        fn_800B4EEC(o, w);
        break;
    case 3:
    case 0xff:
        fn_8015EBF4(w);
        if (w->x268 != NULL) {
            ChainClear(w->x268);
            if (w->x268 != NULL) {
                fn_801E1784(w->x268);
                w->x268 = NULL;
            }
        }
        fn_80100B74(o);
        break;
    case 4:
        if (CountInfo(w)->count >= 0x33) {
            o->state = 0;
        }
        break;
    case 5:
        break;
    }
}

void fn_800B2C1C(Task *o) {
    EvObj *w;
    w = o->work;
    if (o->flags & 0x20) {
        o->state = 0xff;
    }
    Step(o, w);
}

/* state */

/* Layout stub, NOT part of the merge: MWCC lays the pooled .bss arrays out in order of first use in
 * the file. In the unit, fn_8009C518 (earlier) sets that order; this stub stands in for it here. */
void bss_order_stub(void) { lbl_803033B0[0] = 0; lbl_803033C8[0] = 0; lbl_803033E0[0] = 0; lbl_803033F8[0] = 0; }
