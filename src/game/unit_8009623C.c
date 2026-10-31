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
typedef struct Tpl {
    s16 x0;
    s16 x2;
    f32 x4;
    f32 x8;
    f32 xc;
    s32 x10;
    s32 x14;
    s32 x18;
    f32 x1c;
    f32 x20;
    f32 x24;
    u8 pad28[0x40 - 0x28];
} Tpl;
struct Obj12;
typedef struct Sub_80096570 {
    s32 (*fn_80096570)(void *, struct Obj12 *);   /* 0x00 */
    u8 pad4[0x10 - 4];
    s16 x10;
    s16 x12;
    s16 flags;          /* 0x14 */
    u8 pad16[2];
    void* x18;
} Sub_80096570;
typedef struct Res {
    u8 pad0[0x10];
    s16 x10;
    s16 x12;
} Res;
typedef struct Obj_80096570 {
    s16 kind;       /* 0x00 */
    s16 s2;
    s16 s4;
    s16 s6;
    u8 pad8[2];
    s16 sa;
    u8 padc[0x64 - 0xC];
    f32 v64[3];     /* 0x64 */
    u8 pad70[0xDC - 0x70];
    f32 fdc;
    u32 fe0;
    s16 fe4;
    u8 pade6[0xEC - 0xE6];
    s32 xec;
    u8 padf0[0x108 - 0xF0];
    Sub_80096570* sub;       /* 0x108 */
    u8 pad10c[0x110 - 0x10C];
    s32 w110;
    u8 pad114[0x11C - 0x114];
    s32 w11c;
    u8 pad120[0x128 - 0x120];
    Res* res;       /* 0x128 */
    Tpl tpl;        /* 0x12C */
    u8 b16c;
} Obj_80096570;
typedef struct Node {
    u8 pad0[0x19];
    u8 state;
} Node;
typedef struct Vec { f32 x; f32 y; f32 z; } Vec;
typedef struct Sphere { Vec c; f32 r; } Sphere;
typedef struct Capsule { Vec a; Vec b; f32 r; } Capsule;
extern s16 lbl_80346C3C;
extern Sphere lbl_802DFFD8;
extern Capsule lbl_802DFFE8;
extern Tpl lbl_8031191C;
extern char lbl_8030A5D4[0x100];
extern Res* fn_80222128(Sphere* p);
extern Sub_80096570* fn_80222010(Capsule* p);
extern void fn_802229F8(Sub_80096570* s);
extern void fn_80222838(Sub_80096570* s);
struct Obj12;
extern s32 fn_80097608(void *unused, struct Obj12 *p);
extern void fn_80096230();
extern void fn_80095910();
extern void fn_800C52F0();
extern void fn_800C5108();
extern void fn_800C4F1C();
extern void fn_800C4B18();
extern void fn_800C47BC();
extern void fn_800C43A0();
extern void fn_800C40EC();
extern void fn_800C3C78();
extern void fn_800C3A50();
extern void fn_800C3648();
extern void fn_800953E4();
extern void fn_800C56AC();
extern void fn_8009623C();
extern void fn_80095DFC();
extern void fn_800C540C();
extern void fn_800C51BC();
extern void fn_800C5014();
extern void fn_800C4B90();
extern void fn_800C48C4();
extern void fn_800C4584();
extern void fn_800C41D0();
extern void fn_800C3F80();
extern void fn_800C3B58();
extern void fn_800C381C();
extern void fn_8009564C();
extern void fn_800C5940();
Sphere lbl_802DFFD8 = { { 0.0f, 0.0f, 0.0f }, 4.0f };
Capsule lbl_802DFFE8 = { { 0.0f, -20.0f, 0.0f }, { 0.0f, 5.0f, 0.0f }, 5.0f };
void (*lbl_802E0004[16])() = {
    fn_80096230,
    fn_80095910,
    fn_800C52F0,
    fn_800C5108,
    fn_800C4F1C,
    fn_800C4B18,
    fn_800C47BC,
    fn_800C43A0,
    fn_800C40EC,
    fn_800C3C78,
    fn_800C3A50,
    fn_800C3648,
    fn_800953E4,
    fn_800C56AC,
    fn_80096230,
    fn_80096230,
};
void (*lbl_802E0044[16])() = {
    fn_8009623C,
    fn_80095DFC,
    fn_800C540C,
    fn_800C51BC,
    fn_800C5014,
    fn_800C4B90,
    fn_800C48C4,
    fn_800C4584,
    fn_800C41D0,
    fn_800C3F80,
    fn_800C3B58,
    fn_800C381C,
    fn_8009564C,
    fn_800C5940,
    fn_8009623C,
    0,
};
Ctrl lbl_802E0084 = {
    0xFF, 0, 0, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
    0, 0, 0, { 0 }, 0.0f, 0.0f, 0.0f, 0, 1, 0.0f, 0, 1, 0.0f, 0, 0, 0.0f,
};

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

static inline void SetFields(Obj_80096570* o, s16 a, s16 b) {
    o->s4 = a;
    o->s6 = b;
    o->fdc = 0.5f;
    o->fe0 = 0x100;
    o->fe4 = 0x78;
}

void fn_80096570(Node* node, Obj_80096570* o) {
    o->res = fn_80222128(&lbl_802DFFD8);
    o->res->x10 = 0x2800;
    o->res->x12 = 2;
    o->sub = fn_80222010(&lbl_802DFFE8);
    o->sub->x10 = 0x2800;
    o->sub->x12 = 2;
    o->sub->x18 = o->v64;
    o->sub->fn_80096570 = fn_80097608;
    fn_802229F8(o->sub);
    fn_80222838(o->sub);
    o->xec = 0;
    if (lbl_80346C3C == 1) {
        switch (o->kind) {
        case 1:
            break;
        case 0:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
            if (o->sub != NULL) {
                o->sub->flags |= 0x8000;
            }
            break;
        case 7:
            o->w11c = 0;
            o->w110 = 0;
            o->s4 = 0;
            if (o->sub != NULL) {
                o->sub->flags |= 0x8000;
            }
            break;
        }
        node->state = 2;
    } else {
        o->sub->flags = 0x8000;
        o->tpl = lbl_8031191C;
        o->tpl.x0 = 3;
        o->tpl.x2 = 2;
        o->tpl.x24 = 0.0f;
        o->tpl.x1c = 0.0f;
        o->tpl.x20 = 0.0f;
        o->tpl.xc = 0.0f;
        o->tpl.x18 = 0;
        o->tpl.x14 = 0;
        o->tpl.x10 = 0;
        o->tpl.x4 = 0.0f;
        o->tpl.x8 = 0.0f;
        SetFields(o, 0, 0);
        o->s2 = 0;
        o->kind = 0;
        o->sa = 0;
        if (lbl_8030A5D4[0] == 0) {
            lbl_802E0084.b0 = 0xE;
            lbl_802E0084.flags = 0;
            lbl_802E0084.b1 = 0;
        }
        node->state = 1;
    }
    o->b16c = 0;
    lbl_80346C3C = 2;
}
