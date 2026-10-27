#include "types.h"
typedef struct P52058 {
    u8 pad0[0x10];
    u32 flags;
    f32 f14;
    s16 s18;
} P52058;
typedef struct O52058 {
    u8 pad0[0x20];
    u8 v20[0xc];
    u8 v2c[0xc];
    u8 m38[0x38];
    s16 s70;
    u8 pad72[2];
    void *child;
    u8 pad78[0x10];
    f32 f88;
    u8 pad8c[0x4c];
    f32 fd8;
    u8 padDC[0x32];
    s16 state;
    u8 pad110[0x68];
    P52058 *p;
} O52058;
typedef struct B52058 {
    u8 pad[0x88];
    O52058 o;
} B52058;
extern B52058 lbl_80309EC8;
extern void *fn_8001E05C(void *);
extern void fn_80014AB8(s32, void *);
extern void fn_8001359C(void *, void *);
extern void fn_8001363C(void *, void *);
extern void fn_800608C8(f32 *);
extern void fn_80013504(void *, void *, void *, f32, f32);
typedef struct { f32 x, y, z; } V3;
typedef struct U53F38 {
    u8 pad0[6];
    s16 type;
    u8 pad8[0xec - 8];
    u32 fec;
    u32 ff0;
    u8 padf4[0x110 - 0xf4];
    V3 v110;
    u8 pad11c[0x12c - 0x11c];
    f32 f12c;
} U53F38;
typedef struct W53F38 {
    u8 pad0[0x1c];
    V3 pos;
    u8 pad28[0x4c - 0x28];
    U53F38 *u;
} W53F38;
typedef struct Tk53F38 {
    u8 pad[0x24];
    W53F38 *work;
} Tk53F38;
typedef struct Ev53F38 {
    u8 pad[0x1e];
    s16 s1e;
    s16 s20;
    s16 s22;
} Ev53F38;
typedef struct Cw53F38 {
    u8 pad[0x6c];
    u32 f6c;
    u8 pad70[4];
    Tk53F38 *parent;
    u8 pad78[0x178 - 0x78];
    Ev53F38 *ev;
} Cw53F38;
typedef struct Ct53F38 {
    u8 pad[0x24];
    Cw53F38 *work;
} Ct53F38;
extern Tk53F38 *fn_80021658(u8);
extern f32 fn_80071E9C(void *, void *);
extern void fn_80061F58(void *, s32, s32);
extern Ct53F38 *fn_8003DB34(void *);
extern void fn_80051264(void);
extern u8 lbl_80302B38[12];
extern f32 njSin(s32);
typedef struct Wk {
    u8 pad0[0x1c];
    u8 mtx[0x30];
    s8 *id;
} Wk;
typedef struct Ch {
    u8 pad0[0x24];
    Wk *wk;
} Ch;
typedef struct Ob {
    u8 pad0[0x2c];
    f32 v2c[3];
    f32 v38[3];
    u8 pad44[0x74 - 0x44];
    Ch *child;
    u8 pad78[0x88 - 0x78];
    f32 f88;
    f32 v8c[3];
    f32 v98[3];
    u8 pada4[0xd4 - 0xa4];
    f32 fd4;
    f32 fd8;
    f32 fdc;
    u8 pade0[0xf4 - 0xe0];
    f32 vf4[3];
} Ob;
extern void fn_800618FC(f32 *, f32 *, f32 *, f32, f32, f32);
extern void fn_80071F84(f32 *, f32 *, f32 *);
extern f32 fn_80011694(void *, s32, f32 *, f32 *);
typedef struct Pm {
    u8 pad0[0x10];
    u32 flags;
    f32 f14;
    s16 s18;
    u8 pad1a[8];
    s16 s22;
} Pm;
typedef struct Un {
    s8 id;
    u8 pad1[0x4f];
    u32 f50;
} Un;
typedef struct Wk_80053964 {
    u8 pad0[0x1c];
    f32 mtx[3];
    u8 pad28[0x4c - 0x28];
    Un *unit;
} Wk_80053964;
typedef struct Ch_80053964 {
    u8 pad0[0x24];
    Wk_80053964 *wk;
} Ch_80053964;
typedef struct O_80053964 {
    u8 pad0[0x20];
    f32 v20[3];
    f32 v2c[3];
    f32 v38[3];
    u8 pad44[0x68 - 0x44];
    u32 f68;
    u8 pad6c[4];
    s16 s70;
    u8 pad72[2];
    Ch_80053964 *child;
    u8 pad78[0xd8 - 0x78];
    f32 fd8;
    u8 pade0[0x10e - 0xdc];
    s16 state;
    u8 pad110[0x178 - 0x110];
    Pm *p;
} O_80053964;
extern void fn_8001D288(f32 *, s32, f32, f32);
extern void fn_8001D200(Ch_80053964 *, f32 *);
extern void fn_80071CF0(f32 *, f32 *);
extern void fn_80011370(u8, s32);
extern void fn_80011400(s32, s32);
extern void fn_80032B4C(void);
extern void fn_80032BBC(u8, s32);
typedef struct Chr_80051FA0 { u8 id; } Chr_80051FA0;
typedef struct Wk_80051FA0 { u8 pad0[0x4c]; Chr_80051FA0 *chr; } Wk_80051FA0;
typedef struct Task_80051FA0 { u8 pad0[0x24]; Wk_80051FA0 *work; } Task_80051FA0;
extern void fn_800171F0(u8 id, u8 part, f32 *a, f32 *b);
typedef struct A50B88 {
    u8 pad0[0x10];
    s16 s10;
    s16 s12;
    s16 s14;
    s16 s16;
    f32 f18;
} A50B88;
typedef struct S50B88 {
    u16 cnt;
    u8 pad2[6];
    f32 f8;
    A50B88 *a;
} S50B88;
typedef struct O50B88 {
    u8 pad0[0x18];
    u8 flags;
    u8 state;
    u8 pad1A[10];
    S50B88 *s;
} O50B88;
typedef struct G50B88 {
    u8 pad0[8];
    u32 flags8;
    u8 pad_c[0xc];
    s32 i18;
    f32 f1c;
    u8 pad20[0xc];
} G50B88;
typedef struct H50B88 {
    u8 pad[0x1c4];
    s32 count;
} H50B88;
extern G50B88 lbl_80309E5C;
extern H50B88 lbl_8030A10C;
extern void fn_80037FD8(A50B88 *, u8 *);

void fn_80052058(O52058 *o) {
    fn_8001E05C(o->child);
    switch (o->state) {
    case 0:
        o->state = 1;
    case 1:
        if (o->s70 < o->p->s18) {
            return;
        }
        fn_80014AB8(1, o);
        if (o->p->flags & 0x800) {
            fn_8001359C(o->m38, (u8 *)o + 0x88);
        } else {
            fn_8001363C(o->m38, (u8 *)o + 0x88);
        }
        o->state = 2;
        if (o->p->flags & 0x20000000) {
            if (o->p->flags & 0x04000000) {
                fn_800608C8(&o->fd8);
            } else {
                o->fd8 = 0.0f;
            }
        } else {
            if (o->p->flags & 0x04000000) {
                fn_800608C8(&o->fd8);
            } else {
                o->fd8 = o->p->f14;
            }
        }
    case 2:
        fn_80013504(o->v20, o->m38, o->v2c, o->f88, o->fd8);
        if (o->p->flags & 0x20000000) {
            o->fd8 += 1.0f;
        }
        lbl_80309EC8.o = *o;
        break;
    }
}

void fn_80053F38(u8 id, s8 b) {
    Ct53F38 *c;
    Cw53F38 *w;
    Ev53F38 *ev;
    Tk53F38 *t;
    U53F38 *u;
    s16 half = 1;
    s16 kind = b;
    t = fn_80021658(id);
    if (t != 0) {
        u = t->work->u;
        if (!(u->fec & 0x100000)) {
            if (b == 0) {
                switch (u->type) {
                default: {
                    s16 q;
                    kind = 2;
                    q = (s16)(s32)(fn_80071E9C(&t->work->pos, &u->v110) / u->f12c);
                    half = q - q % 2;
                    break;
                }
                case 4:
                case 8:
                    kind = 0xe;
                    break;
                case 5:
                    kind = 1;
                    break;
                case 29:
                    kind = 1;
                    break;
                case 12:
                    kind = 0xf;
                    break;
                case 17:
                    kind = 0x10;
                    break;
                }
            } else {
                u->ff0 |= 0x2000000;
                kind = 0x11;
                if (u->ff0 & 4) {
                    kind = 0x11;
                }
            }
            fn_80061F58(&ev, 0x24, 0);
            ev->s22 = kind;
            switch (kind) {
            case 6:
                ev->s1e = half / 2;
                ev->s20 = half / 2;
                break;
            }
            c = fn_8003DB34(fn_80051264);
            fn_80061F58(&c->work, 0x17c, 0);
            w = c->work;
            w->ev = ev;
            w->parent = t;
            w->f6c |= 0x80000000;
        }
    }
}

void fn_8005121C(void)
{
    s32 i;

    for (i = 0; i < 12; i++) {
        lbl_80302B38[i] = 0;
    }
}

void fn_8005174C(Ob *o) {
    f32 ang;
    f32 bestAng;
    f32 best;
    Ch *c0;
    Ch *c1;
    s16 i;
    s32 id0;
    s32 id1;
    f32 tmp[2];
    f32 a, sum;
    best = 0.0f;
    ang = o->fd8;
    bestAng = ang;
    c0 = o->child;
    c1 = fn_8001E05C(c0);
    id0 = *c0->wk->id;
    id1 = *c1->wk->id;
    for (i = 0; i < 12; i++) {
        o->fd8 = ang;
        a = fn_80071E9C(o->v8c, o->v98);
        fn_800618FC(o->vf4, o->v8c, o->v98, 0.0f, o->fd8, 0.5f * (o->f88 - a));
        o->fd8 = o->fd8 + o->fdc;
        o->vf4[1] = o->vf4[1] + (o->f88 * njSin((s32)(182.04445f * o->fd4)) + 30.0f);
        if (o->vf4[1] < 3.75f) {
            o->vf4[1] = 3.75f;
        }
        fn_80071F84(o->v2c, o->v38, o->vf4);
        a = fn_80011694(c0->wk->mtx, id0, o->vf4, tmp);
        sum = a + fn_80011694(c1->wk->mtx, id1, o->vf4, tmp);
        if (sum >= best) {
            bestAng = ang;
            best = sum;
        }
        ang += 10.0f;
    }
    o->fd8 = bestAng;
    a = fn_80071E9C(o->v8c, o->v98);
    fn_800618FC(o->vf4, o->v8c, o->v98, 0.0f, o->fd8, 0.5f * (o->f88 - a));
    o->fd8 = o->fd8 + o->fdc;
    o->vf4[1] = o->vf4[1] + (o->f88 * njSin((s32)(182.04445f * o->fd4)) + 30.0f);
    if (o->vf4[1] < 3.75f) {
        o->vf4[1] = 3.75f;
    }
    fn_80071F84(o->v2c, o->v38, o->vf4);
}

void fn_80053964(O_80053964 *o) {
    Ch_80053964 *c;
    Un *un;
    f32 f;
    switch (o->p->s22) {
    case 7:
    case 8:
        if (o->p->flags & 0x40000000) {
            c = o->child;
        } else {
            c = fn_8001E05C(o->child);
        }
        break;
    default:
        if (o->p->flags & 0x40000000) {
            c = fn_8001E05C(o->child);
        } else {
            c = o->child;
        }
        break;
    }
    un = c->wk->unit;
    switch (o->p->s22) {
    case 7:
    case 9:
    default:
        f = 45.0f;
        break;
    case 8:
    case 0x12:
        f = 75.0f;
        break;
    }
    f *= 1.5f;
    switch (o->state) {
    case 0:
        if (o->s70 < o->p->s18) {
            break;
        }
        fn_80014AB8(1, o);
        o->fd8 = 0.0f;
        fn_8001D288(o->v20, un->id, o->fd8, f);
        o->v20[1] += o->p->f14;
        if (o->p->flags & 0x08000000) {
            o->v20[1] = o->p->f14;
            fn_80071CF0(o->child->wk->mtx, o->v38);
            o->v38[1] += o->p->f14;
        } else {
            fn_8001D200(c, o->v38);
        }
        fn_80071F84(o->v2c, o->v38, o->v20);
        fn_80011370(un->id, -1);
        if (!(o->p->flags & 0x10000000)) {
            fn_80032B4C();
        }
        o->state = 1;
    case 1:
        fn_80011370(un->id, -1);
        if (o->p->flags & 0x20000000) {
            fn_8001D288(o->v20, un->id, o->fd8, f);
            o->v20[1] += o->p->f14;
            if (o->p->flags & 0x08000000) {
                o->v20[1] = o->p->f14;
                fn_80071CF0(o->child->wk->mtx, o->v38);
                o->v38[1] += o->p->f14;
            } else {
                fn_8001D200(c, o->v38);
            }
            o->fd8 += 1.0f;
        }
        fn_80071F84(o->v2c, o->v38, o->v20);
        if (!(o->p->flags & 0x10000000)) {
            if (!(o->f68 & 0x20000000)) {
                fn_80032BBC(un->id, 1);
            } else {
                fn_80032BBC(un->id, 0);
            }
        }
        break;
    }
    fn_80011400(un->id, 0);
}

/* Over up to 8 parts (list ends at a negative entry), finds the pair of points fn_800171F0
 * gives with the largest distance; copies that pair to outA/outB and returns the distance. */
f32 fn_80051FA0(Task_80051FA0 *t, s8 *list, f32 *outA, f32 *outB) {
    s16 i;
    Chr_80051FA0 *c = t->work->chr;
    f32 best = 0.0f;
    f32 a[3];
    f32 b[3];
    f32 d;

    for (i = 0; i < 8; i++) {
        if (list[i] < 0) {
            break;
        }
        fn_800171F0(c->id, list[i], a, b);
        d = fn_80071E9C(a, b);
        if (d > best) {
            best = d;
            fn_80071CF0(a, outA);
            fn_80071CF0(b, outB);
        }
    }
    return best;
}

void fn_80050B88(O50B88 *o) {
    S50B88 *s = o->s;
    switch (o->state) {
    case 0:
        {
            A50B88 *a = s->a;
            G50B88 *g;
            if (s->cnt < a->s10) {
                break;
            }
            g = &lbl_80309E5C;
            s->f8 = (1.0f - a->f18) / a->s12;
            g->flags8 |= 0x8000000;
            g->i18 = 255;
            g->f1c = 0.0f;
        }
        o->state = 1;
    case 1:
        if (s->cnt >= s->a->s10 && s->a->s12 != 0 && s->cnt < s->a->s10 + s->a->s12) {
            lbl_80309E5C.f1c = lbl_80309E5C.f1c + s->f8;
        }
        if (s->cnt >= s->a->s14 && s->a->s16 != 0) {
            if (s->cnt == s->a->s14) {
                s->f8 = lbl_80309E5C.f1c / s->a->s16;
            }
            if (s->cnt < s->a->s14 + s->a->s16) {
                lbl_80309E5C.f1c = lbl_80309E5C.f1c - s->f8;
            }
        }
        if (s->cnt >= s->a->s10 + s->a->s12 && s->cnt >= s->a->s14 + s->a->s16) {
            o->state = 0xfa;
        }
        break;
    case 0xf9:
    case 0xfa:
        lbl_80309E5C.f1c = 0.0f;
        lbl_80309E5C.flags8 &= ~0x8000000;
        o->flags |= 0x40;
        lbl_8030A10C.count--;
        return;
    }
    s->cnt = s->cnt + 1;
    fn_80037FD8(s->a, &o->state);
}
