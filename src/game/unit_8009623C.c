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
    s8 b0;
    u8 b1;
    s16 flags;
    f32 v0c[3];  /* 0x04 */
    f32 v10[3];  /* 0x10 */
    f32 v1c[3];  /* 0x1C */
    f32 v28[3];  /* 0x28 */
    u32 w34[3];  /* 0x34 */
    u32 w40[3];  /* 0x40 */
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
extern void* lbl_80347450;
extern s32 lbl_80311AC0[3];
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
    s32 x28;
    u8 pad2c[0x40 - 0x2c];
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
    s16 flags;
    s16 s4;
    s16 s6;
    s16 s8;
    s16 sa;
    f32 v0c[3];     /* 0x0C */
    u8 pad18[0x24 - 0x18];
    f32 v24[3];     /* 0x24 */
    f32 v30[3];     /* 0x30 */
    u32 w3c;
    s32 w40[3];     /* 0x40 */
    f32 v4c[3];     /* 0x4C */
    f32 v58[3];     /* 0x58 */
    f32 v64[3];     /* 0x64 */
    s32 w70[3];     /* 0x70 */
    f32 v7c[3];     /* 0x7C */
    s32 w88[3];     /* 0x88 */
    f32 v94[3];     /* 0x94 */
    f32 va0[3];     /* 0xA0 */
    u8 padac[0xDC - 0xAC];
    f32 fdc;
    s32 fe0;
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
extern void (*lbl_802E0044[])(Obj_80096570*, Ctrl*);
extern void fn_80097388(Obj_80096570*);
extern void fn_800974CC(Obj_80096570*);
typedef struct Node {
    u8 pad0[0x18];
    u8 flags;
    u8 state;
    u8 pad1a[0x24 - 0x1A];
    Obj_80096570* sub;
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
    0xFF, 0, 0, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f },
    { 0, 0, 0 }, { 0, 0, 0 }, 0.0f, 0.0f, 0.0f, 0, 1, 0.0f, 0, 1, 0.0f, 0, 0, 0.0f,
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
    lbl_802E0084.w34[0] = a;
    lbl_802E0084.flags |= 0x20;
    lbl_802E0084.w34[1] = b;
    lbl_802E0084.w34[2] = c;
}

void fn_80097204(f32 a, f32 b, f32 c)
{
    lbl_802E0084.v28[0] = a;
    lbl_802E0084.flags |= 0x10;
    lbl_802E0084.v28[1] = b;
    lbl_802E0084.v28[2] = c;
}

void fn_80097228(f32 a, f32 b, f32 c)
{
    lbl_802E0084.v1c[0] = a;
    lbl_802E0084.flags |= 0x8;
    lbl_802E0084.v1c[1] = b;
    lbl_802E0084.v1c[2] = c;
}

void fn_8009724C(f32 a, f32 b, f32 c)
{
    lbl_802E0084.v10[0] = a;
    lbl_802E0084.flags |= 0x4;
    lbl_802E0084.v10[1] = b;
    lbl_802E0084.v10[2] = c;
}

void fn_80097270(f32 a, f32 b, f32 c)
{
    lbl_802E0084.v0c[0] = a;
    lbl_802E0084.flags |= 0x2;
    lbl_802E0084.v0c[1] = b;
    lbl_802E0084.v0c[2] = c;
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

void fn_80096260(Obj_80096570* o, Ctrl* c) {
    u32 tmp[6];

    o->s8 = 0;
    LoadDefault(o->v4c, o->w40);
    LoadDefault(o->v7c, o->w88);
    if (c->b0 >= 15) {
        o->kind = 0;
        fn_80097388(o);
        o->flags |= c->b1 & 1;
    } else {
        fn_800974CC(o);
        o->kind = c->b0;
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
    o->tpl.x0 = 0;
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
        o->flags = 0;
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

#ifdef NONMATCHING
extern s32 fn_8022BA10(s32* ang, f32* p);
extern s32 fn_8022BAA0(s32* ang, f32* a, f32* b, f32* p);
extern s32 fn_800914D8(f32* cur, f32* tgt, f32 speed, f32 range);

static inline s32 AngApproach(s32 cur, s32 spd, s32 tgt) {
    u16 c = cur;
    u16 w = tgt + (0x8000 - c);
    s32 d = w - 0x8000;
    if (d == 0) {
        return tgt;
    }
    if (d < 0) {
        d = -d;
        spd = -spd;
    }
    if (d >= 0x1000) {
        return cur + spd;
    }
    d = spd * d / 4096;
    if (d != 0) {
        return cur + d;
    }
    return tgt;
}

static inline void CamSpeed(Obj_80096570* c) {
    if ((4.0f > c->fdc || c->fe4 == 0) && 12.0f > c->fdc) {
        c->fdc += 0.5f;
    }
    if (c->fe0 < 0x600) {
        c->fe0 += 0x100;
    }
    if (c->fe4 > 0) {
        c->fe4--;
    }
}

void fn_80096814(Obj_80096570* c) {
    switch (c->s4) {
    case 0:
        break;
    case 1:
        c->tpl.x28 = fn_8022BA10(c->w40, c->va0);
        fn_8022DAE8(c->v4c, c->w40, &c->tpl.x0);
        c->v7c[0] = c->v4c[0];
        c->v7c[1] = c->v4c[1];
        c->v7c[2] = c->v4c[2];
        break;
    case 2:
        c->w88[0] = AngApproach(c->w88[0], c->fe0, c->w40[0]);
        c->w88[1] = AngApproach(c->w88[1], c->fe0, c->w40[1]);
        if (fn_800914D8(c->v7c, c->v4c, c->fdc, 8.0f) != 0 && c->w88[0] == c->w40[0] &&
            c->w88[1] == c->w40[1]) {
            c->s4 = c->s6;
        }
        c->tpl.x28 = fn_8022BA10(c->w88, c->va0);
        fn_8022DAE8(c->v7c, c->w88, &c->tpl.x0);
        CamSpeed(c);
        break;
    case 3:
        if (fn_800914D8(c->v7c, c->v4c, c->fdc, 8.0f) != 0) {
            c->s4 = c->s6;
        }
        c->tpl.x28 = fn_8022BAA0(c->w88, c->v24, c->v7c, c->va0);
        fn_8022DAE8(c->v7c, c->w88, &c->tpl.x0);
        CamSpeed(c);
        break;
    case 4: {
        s32 done;
        s32 a[3];
        done = fn_800914D8(c->v7c, c->v4c, c->fdc, 8.0f);
        c->tpl.x28 = fn_8022BAA0(a, c->v24, c->v7c, c->va0);
        c->w88[0] = AngApproach(c->w88[0], c->fe0, a[0]);
        c->w88[1] = AngApproach(c->w88[1], c->fe0, a[1]);
        if (done != 0 && a[0] == c->w88[0] && a[1] == c->w88[1]) {
            c->s4 = c->s6;
        }
        fn_8022DAE8(c->v7c, c->w88, &c->tpl.x0);
        CamSpeed(c);
        break;
    }
    case 5:
        c->tpl.x28 = fn_8022BA10(c->w88, c->va0);
        fn_8022DAE8(c->v7c, c->w88, &c->tpl.x0);
        break;
    case 6:
        c->v7c[0] = c->v4c[0];
        c->v7c[1] = c->v4c[1];
        c->v7c[2] = c->v4c[2];
        c->tpl.x28 = fn_8022BAA0(c->w88, c->v24, c->v7c, c->va0);
        fn_8022DAE8(c->v7c, c->w88, &c->tpl.x0);
        break;
    case 7:
        if (fn_800914D8(c->v7c, c->v4c, c->fdc, 8.0f) != 0) {
            c->s4 = c->s6;
        }
        c->tpl.x28 = fn_8022BAA0(c->w88, c->v24, c->v7c, c->va0);
        fn_8022DAE8(c->v7c, c->w88, &c->tpl.x0);
        CamSpeed(c);
        break;
    }
}

#endif
extern void fn_80096814(Obj_80096570* c);
extern void fn_8022DAE8(f32* v, s32* w, s16* h);
extern void fn_80222930(void* p);
extern void fn_801E17E0(void* p);
extern s16 lbl_80346750;

void fn_80096DA4(Node* self) {
    Obj_80096570* o = self->sub;
    if (lbl_80346750 != 0) {
        self->state = 0xff;
    } else {
        if (self->state == 0xfe || self->state == 0) {
            if ((lbl_802E0084.b0 < 0 && lbl_80346C3C != 1) || lbl_80347450 == 0) {
                return;
            }
            fn_80096570(self, o);
            o->tpl.x0 = 0;
        }
        if (lbl_802E0084.b0 >= 0) {
            fn_80096260(o, &lbl_802E0084);
            lbl_802E0084.b0 = -1;
            lbl_802E0084.flags = 0;
            lbl_802E0084.b1 = 0;
        }
    }
    switch (self->state) {
    case 1:
        if (o->kind != 0) {
            o->s8 = 0;
            self->state = 2;
        } else {
            o->v7c[0] = lbl_80311970.f[0];
            o->v7c[1] = lbl_80311970.f[1];
            o->v7c[2] = lbl_80311970.f[2];
            o->w88[0] = (u16)lbl_80311970.w[0];
            o->w88[1] = (u16)lbl_80311970.w[1];
            o->w88[2] = (u16)lbl_80311970.w[2];
            o->tpl.x0 = 7;
            fn_8022DAE8(o->v7c, o->w88, &o->tpl.x0);
            break;
        }
    case 2:
        if (o->kind != 0 && o->kind < 0xf) {
            lbl_802E0004[o->kind](o);
            fn_80096814(o);
            o->tpl.x0 = 3;
        } else {
            o->v7c[0] = lbl_80311970.f[0];
            o->v7c[1] = lbl_80311970.f[1];
            o->v7c[2] = lbl_80311970.f[2];
            o->w88[0] = (u16)lbl_80311970.w[0];
            o->w88[1] = (u16)lbl_80311970.w[1];
            o->w88[2] = (u16)lbl_80311970.w[2];
            fn_8022DAE8(o->v7c, o->w88, &o->tpl.x0);
            self->state = 1;
        }
        break;
    default:
        if (o->sub != 0) {
            fn_80222930(o->sub);
            o->sub = 0;
        }
        if (o->res != 0) {
            fn_801E17E0(o->res);
            o->res = 0;
        }
        lbl_80346C3C = 0;
        lbl_802E0084.b0 = -1;
        lbl_802E0084.flags = 0;
        lbl_802E0084.b1 = 0;
        lbl_80346750 = 1;
        self->sub = 0;
        self->flags |= 0x40;
        break;
    }
}
