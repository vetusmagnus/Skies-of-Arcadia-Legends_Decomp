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
extern void fn_8001E05C(void *);
extern void fn_80014AB8(s32, O52058 *);
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
extern f32 fn_80071E9C(V3 *, V3 *);
extern void fn_80061F58(void *, s32, s32);
extern Ct53F38 *fn_8003DB34(void *);
extern void fn_80051264(void);
extern u8 lbl_80302B38[12];

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
