#include "types.h"
typedef struct Sub {
    u8 pad0[0x14];
    s16 flags;
} Sub;
typedef struct Obj_8009623C {
    u8 pad0[0x108];
    Sub *sub;
    u8 pad1[0x12C - 0x10C];
    s16 state;
} Obj_8009623C;
typedef struct Obj_800967F0 {
    u8 pad0[4];
    s16 a4;
    s16 a6;
    u8 pad8[0xDC - 0x8];
    f32 fdc;
    u32 fe0;
    s16 fe4;
} Obj_800967F0;
typedef struct Ctrl {
    u8 b0;
    u8 b1;
    s16 flags;
    f32 f04;
    f32 f08;
    f32 f0C;
    f32 f10;
    f32 f14;
    f32 f18;
    f32 f1C;
    f32 f20;
    f32 f24;
    f32 f28;
    f32 f2C;
    f32 f30;
    u32 p34;
    u32 p38;
    u32 p3C;
    u8 pad40[0x0C];
    f32 f4C;
    f32 f50;
    f32 f54;
    s16 s58;
    s16 s5A;
    f32 f5C;
    s16 s60;
    s16 s62;
    f32 f64;
    s16 s68;
    s16 s6A;
    f32 f6C;
} Ctrl;
extern Ctrl lbl_802E0084;
typedef struct {
    u8 pad_00[0x10];
    f32 f[3];
    u32 w[3];
} Table;
extern Table lbl_80311970;
typedef struct {
    u8 b0;
    u8 b1;
    s16 flags;
    f32 v0c[3];  /* 0x04 */
    f32 v10[3];  /* 0x10 */
    f32 v1c[3];  /* 0x1C */
    f32 v28[3];  /* 0x28 */
    u32 w34[3];  /* 0x34 */
    u32 w40[3];  /* 0x40 */
} Ctrl_80096260;
typedef struct {
    s16 kind;        /* 0x00 */
    s16 flags;       /* 0x02 */
    u8 pad4[4];
    s16 s8;          /* 0x08 */
    u8 pad0a[2];
    f32 v0c[3];      /* 0x0C */
    u8 pad18[0x30 - 0x18];
    f32 v30[3];      /* 0x30 */
    u32 w3c;         /* 0x3C */
    s32 w40[3];      /* 0x40 */
    f32 v4c[3];      /* 0x4C */
    f32 v58[3];      /* 0x58 */
    f32 v64[3];      /* 0x64 */
    s32 w70[3];      /* 0x70 */
    f32 v7c[3];      /* 0x7C */
    s32 w88[3];      /* 0x88 */
    f32 v94[3];      /* 0x94 */
    f32 va0[3];      /* 0xA0 */
    u8 padac[0x12C - 0xAC];
    s16 s12c;
} Obj;
extern void* lbl_80347450;
extern s32 lbl_80311AC0[3];
extern void (*lbl_802E0044[])(Obj*, Ctrl_80096260*);
extern void fn_80097388(Obj*);
extern void fn_800974CC(Obj*);
extern void fn_80095220(void* cam, f32* a, u32* b);
extern void fn_801DD334(f32* a, f32* b, u32* c);

void fn_8009623C(Obj_8009623C *o)
{
    Sub *s = o->sub;
    if (s != 0) {
        s->flags |= 0x8000;
    }
    o->state = 7;
}

void fn_800967F0(Obj_800967F0 *o, s16 a, s16 b)
{
    o->a4 = a;
    o->a6 = b;
    o->fdc = 0.5f;
    o->fe0 = 0x100;
    o->fe4 = 0x78;
}

void fn_80097094(s16 a, f32 b)
{
    lbl_802E0084.s60 = a;
    lbl_802E0084.flags |= 0x1000;
    lbl_802E0084.f64 = b;
}

void fn_800970B4(s16 a, s16 b, f32 c)
{
    lbl_802E0084.s68 = a;
    lbl_802E0084.flags |= 0x2000;
    lbl_802E0084.s6A = b;
    lbl_802E0084.f6C = c;
}

void fn_800970D8(s16 a, s16 b, f32 c)
{
    lbl_802E0084.s60 = a;
    lbl_802E0084.flags |= 0x1000;
    lbl_802E0084.s62 = b;
    lbl_802E0084.f64 = c;
}

void fn_800970FC(f32 a)
{
    lbl_802E0084.f50 = a;
    lbl_802E0084.flags |= 0x80;
}

void fn_80097118(f32 a)
{
    lbl_802E0084.f4C = a;
    lbl_802E0084.flags |= 0x40;
}

void fn_80097134(s16 a)
{
    lbl_802E0084.s5A = a;
    lbl_802E0084.flags |= 0x400;
}

void fn_80097150(s16 a)
{
    lbl_802E0084.s58 = a;
    lbl_802E0084.flags |= 0x200;
}

void fn_8009716C(s16 a)
{
    lbl_802E0084.s62 = a;
    lbl_802E0084.flags |= 0x1000;
}

void fn_80097188(f32 a, f32 b)
{
    lbl_802E0084.f54 = a;
    lbl_802E0084.flags |= 0x800;
    lbl_802E0084.f5C = b;
}

void fn_800971A8(f32 a)
{
    lbl_802E0084.f5C = a;
    lbl_802E0084.flags |= 0x800;
}

void fn_800971C4(f32 a)
{
    lbl_802E0084.f54 = a;
    lbl_802E0084.flags |= 0x100;
}

void fn_800971E0(u32 a, u32 b, u32 c)
{
    lbl_802E0084.p34 = a;
    lbl_802E0084.flags |= 0x20;
    lbl_802E0084.p38 = b;
    lbl_802E0084.p3C = c;
}

void fn_80097204(f32 a, f32 b, f32 c)
{
    lbl_802E0084.f28 = a;
    lbl_802E0084.flags |= 0x10;
    lbl_802E0084.f2C = b;
    lbl_802E0084.f30 = c;
}

void fn_80097228(f32 a, f32 b, f32 c)
{
    lbl_802E0084.f1C = a;
    lbl_802E0084.flags |= 0x8;
    lbl_802E0084.f20 = b;
    lbl_802E0084.f24 = c;
}

void fn_8009724C(f32 a, f32 b, f32 c)
{
    lbl_802E0084.f10 = a;
    lbl_802E0084.flags |= 0x4;
    lbl_802E0084.f14 = b;
    lbl_802E0084.f18 = c;
}

void fn_80097270(f32 a, f32 b, f32 c)
{
    lbl_802E0084.f04 = a;
    lbl_802E0084.flags |= 0x2;
    lbl_802E0084.f08 = b;
    lbl_802E0084.f0C = c;
}

void fn_80097294(u8 a)
{
    lbl_802E0084.b0 = a;
    lbl_802E0084.flags = 0;
    lbl_802E0084.b1 = 0;
}

void fn_8009703C(s16 v, f32 a, f32 b) {
    lbl_802E0084.s60 = v;
    lbl_802E0084.flags |= 0x1000;
    if (0.0f >= a) a = 1.0f;
    lbl_802E0084.f54 = a;
    if (1.0f > b) b = 1.0f;
    lbl_802E0084.f5C = b;
}

void fn_8009701C(s8 a)
{
    lbl_802E0084.flags |= 0x1000;
    lbl_802E0084.s60 = a;
}

static inline void LoadDefault(f32* outf, s32* outw) {
    outf[0] = lbl_80311970.f[0];
    outf[1] = lbl_80311970.f[1];
    outf[2] = lbl_80311970.f[2];
    outw[0] = (u16)lbl_80311970.w[0];
    outw[1] = (u16)lbl_80311970.w[1];
    outw[2] = (u16)lbl_80311970.w[2];
}

void fn_80096260(Obj* o, Ctrl_80096260* c) {
    u32 tmp[6];

    o->s8 = 0;
    LoadDefault(o->v4c, o->w40);
    LoadDefault(o->v7c, o->w88);
    if ((s8)c->b0 >= 15) {
        o->kind = 0;
        fn_80097388(o);
        o->flags |= c->b1 & 1;
    } else {
        fn_800974CC(o);
        o->kind = (s8)c->b0;
        LoadDefault(o->v64, o->w70);
        if (lbl_80347450 != NULL) {
            fn_80095220(lbl_80347450, o->v0c, tmp);
        }
        o->w3c = tmp[1];
        o->v30[2] = 0.0f;
        o->v30[1] = 0.0f;
        o->v30[0] = 0.0f;
        o->flags &= ~3;
        o->flags |= c->b1 & 3;
        if (c->flags & 2) {
            o->v0c[0] = c->v0c[0];
            o->v0c[1] = c->v0c[1];
            o->v0c[2] = c->v0c[2];
        }
        if (c->flags & 4) {
            o->v30[0] = c->v10[0];
            o->v30[1] = c->v10[1];
            o->v30[2] = c->v10[2];
        }
        if (c->flags & 8) {
            o->v64[0] = c->v1c[0];
            o->v64[1] = c->v1c[1];
            o->v64[2] = c->v1c[2];
        }
        if (c->flags & 0x10) {
            o->v58[0] = c->v28[0];
            o->v58[1] = c->v28[1];
            o->v58[2] = c->v28[2];
        } else {
            o->v58[0] = o->v4c[0] - o->v0c[0];
            o->v58[1] = o->v4c[1] - o->v0c[1];
            o->v58[2] = o->v4c[2] - o->v0c[2];
        }
        if (c->flags & 0x20) {
            o->w70[0] = c->w34[0];
            o->w70[1] = c->w34[1];
            o->w70[2] = c->w34[2];
        }
        if (c->flags & 0x4000) {
            fn_801DD334(o->v94, o->va0, c->w40);
        } else {
            if (lbl_80311AC0[0] == 0x1c && (s32)*(u8*)&lbl_80311AC0[2] == 0x61) {
                o->va0[1] = -1.0f;
            } else {
                o->va0[1] = 1.0f;
            }
            o->v94[0] = o->v94[1] = o->va0[0] = o->va0[2] = 0.0f;
            o->v94[2] = 1.0f;
        }
    }
    o->s12c = 0;
    lbl_802E0044[o->kind](o, c);
}
