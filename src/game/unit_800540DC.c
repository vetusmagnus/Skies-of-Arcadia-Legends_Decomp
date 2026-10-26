#include "types.h"
typedef struct { f32 x, y, z; } V3;
typedef struct U800540DC { s8 id; u8 pad1[3]; s8 x4; u8 pad5[0x15c - 5]; f32 x15c; } U800540DC;
typedef struct W800540DC { u8 pad[0x1c]; V3 pos; u8 pad28[0x4c - 0x28]; U800540DC* u; } W800540DC;
typedef struct Tk800540DC { u8 pad[0x24]; W800540DC* work; } Tk800540DC;
typedef struct Par800540DC { u8 pad[0x74]; Tk800540DC* child; } Par800540DC;
extern Tk800540DC* fn_80021658(u8);
extern void fn_80071CF0(V3* src, V3* dst);
extern void fn_80071F84(s32* out, V3* a, V3* b);
extern f32 fn_80071E9C(V3*, V3*);
extern f32 njSin(s32);
typedef struct U54B74 {
    u8 pad0[6];
    s16 s6;
    u8 pad8[0xec - 8];
    u32 fec;
    u32 ff0;
} U54B74;
typedef struct D54B74 {
    u8 pad0[0x10];
    u8 pad10[0x20];
    u32 f30;
} D54B74;
typedef struct W54B74 {
    u8 pad0[0x10];
    D54B74 *d10;
    u8 pad14[0x4c - 0x14];
    U54B74 *u;
} W54B74;
typedef struct P54B74 {
    u8 pad0[0x24];
    W54B74 *work;
} P54B74;
typedef struct T54B74 {
    u8 pad0[0x10];
    u32 f10;
} T54B74;
typedef struct E54B74 {
    u8 pad0[0x14];
    s16 a14[10];
    s16 a28[10];
    s16 a3c[10];
} E54B74;
typedef struct S54B74 {
    s16 cnt;
    s16 s2;
    P54B74 *p4;
    P54B74 *p8;
    U54B74 *pc;
    E54B74 *tab;
} S54B74;
typedef struct O54B74 {
    u8 pad0[0x18];
    u8 flags;
    u8 state;
    u8 pad1A[10];
    S54B74 *s;
} O54B74;
typedef struct H54B74 {
    u8 pad[0x1c4];
    s32 count;
} H54B74;
extern H54B74 lbl_8030A10C;
extern void fn_80037FD8(E54B74 *, u8 *);
extern P54B74 *fn_8001E05C(P54B74 *);
extern s32 fn_80075FF0(P54B74 *, s32, s32);
extern void fn_80008C00(P54B74 *, s32, s32, s32, s32, u32);
typedef struct { s8 id; } Obj4C;
typedef struct { u8 pad[0x4c]; Obj4C *p4c; } Obj24;
typedef struct { u8 pad[0x24]; Obj24 *p24; } Task;
extern void fn_8001D288(void *a, s32 id, f32 x, f32 y);
extern void fn_8001D200(Task *t, void *v);
typedef struct E54B74_80054DD8 {
    u8 pad0[0x14];
    s16 a14[10];
    s16 a28[10];
} E54B74_80054DD8;
typedef struct S54B74_80054DD8 {
    s16 cnt;
    s16 s2;
    P54B74 *p4;
    P54B74 *p8;
    U54B74 *pc;
    E54B74_80054DD8 *tab;
} S54B74_80054DD8;
typedef struct O54B74_80054DD8 {
    u8 pad0[0x18];
    u8 flags;
    u8 state;
    u8 pad1A[10];
    S54B74_80054DD8 *s;
} O54B74_80054DD8;
typedef struct Un {
    u8 id;
    u8 pad1[0x4f];
    u32 f50;
    u8 pad54[0xec - 0x54];
    u32 fec;
    u32 ff0;
    u8 padf4[0x164 - 0xf4];
    f32 f164;
} Un;
typedef struct Wk {
    u8 pad0[0x4c];
    Un *unit;
} Wk;
typedef struct Nd {
    u8 pad0[0x24];
    Wk *wk;
} Nd;
typedef struct Ad {
    u8 pad0[0x10];
    u32 f10;
    s16 s14;
    s16 s16;
    u8 pad18[0x2a - 0x18];
    s16 s2a;
} Ad;
typedef struct S {
    s16 cnt;
    u8 pad2[2];
    Nd *p;
    f32 f8;
    f32 fc;
    u8 id;
    u8 pad11[3];
    Ad *a;
} S;
typedef struct Ow {
    u8 pad0[0x4c];
    S *s;
} Ow;
typedef struct O {
    u8 pad0[0x18];
    u8 flags;
    u8 state;
    u8 pad1a[10];
    Ow *w;
} O;
typedef struct H {
    u8 pad[0x1c4];
    s32 count;
} H;
extern void *lbl_80347394;
extern s32 fn_80021728(s8);
extern s32 fn_8006D1C4(void);
extern void fn_8001DCA0(Un *);
extern void fn_80018700(s32);
extern void fn_801E17E0(S *);

f32 fn_800540DC(Par800540DC* t) {
    W800540DC* w;
    U800540DC* v;
    U800540DC* u;
    s32 ang[3];
    V3 a;
    V3 b;
    u = t->child->work->u;
    w = fn_80021658(u->id)->work;
    v = w->u;
    fn_80071CF0(&w->pos, &a);
    a.y = v->x15c;
    if (u->x4 == u->id) {
        b.x = b.y = b.z = 0.0f;
    } else {
        w = fn_80021658(u->x4)->work;
        v = w->u;
        fn_80071CF0(&w->pos, &b);
        b.y = v->x15c;
    }
    if (a.y > b.y) {
        b.y = 0.0f;
        fn_80071F84(ang, &b, &a);
        return njSin(ang[0]) * fn_80071E9C(&a, &b);
    }
    return 0.0f;
}

void fn_80054B74(O54B74 *o) {
    S54B74 *s = o->s;
    s16 i;
    switch (o->state) {
    case 0:
        for (i = 0; i < 10; i++) {
            if (s->tab->a3c[i] == 0) {
                if (i == 0) {
                    o->state = 0xfa;
                    return;
                }
                s->s2 = s->tab->a3c[i - 1];
                break;
            }
        }
        s->p8 = fn_8001E05C(s->p4);
        s->pc = s->p8->work->u;
        o->state = 1;
    case 1:
        if (s->cnt > s->s2 || s->pc->s6 == 0xe) {
            o->state = 0xfa;
            break;
        }
        for (i = 0; i < 10; i++) {
            s16 e = s->tab->a3c[i];
            if (e != 0 && s->cnt == e) {
                s->pc->fec |= 1;
                if (fn_80075FF0(s->p8, s->tab->a14[i], s->tab->a28[i]) == 0) {
                    s->pc->fec &= ~1;
                } else {
                    U54B74 *u;
                    P54B74 *t;
                    s32 x;
                    s32 y;
                    t = s->p8;
                    u = t->work->u;
                    y = s->tab->a28[i];
                    x = s->tab->a14[i];
                    u->ff0 |= 8;
                    fn_80008C00(t, x, y, 0xe, 3, t->work->d10->f30);
                    if (!(u->ff0 & 0x800)) {
                        if (x == 0xe && !(u->fec & 0x100)) {
                            x = 0x20;
                        }
                        fn_80008C00(t, x, y, 0x36, 3, t->work->d10->f30);
                    }
                }
            }
        }
        break;
    case 0xf9:
    case 0xfa:
        o->flags |= 0x40;
        lbl_8030A10C.count--;
        return;
    }
    s->cnt = s->cnt + 1;
    fn_80037FD8(s->tab, &o->state);
}

void fn_8005535C(void *a, void *v, Task *t, f32 x)
{
    fn_8001D288(a, t->p24->p4c->id, x, 0.0f);
    fn_8001D200(t, v);
}

void fn_80054DD8(O54B74_80054DD8 *o) {
    S54B74_80054DD8 *s = o->s;
    s16 i;
    switch (o->state) {
    case 0:
        for (i = 0; i < 10; i++) {
            if (s->tab->a28[i] == 0) {
                if (i == 0) {
                    o->state = 0xfa;
                    return;
                }
                s->s2 = s->tab->a28[i - 1];
                break;
            }
        }
        if (i == 10) {
            s->s2 = s->tab->a28[i - 1];
        }
        s->p8 = fn_8001E05C(s->p4);
        s->pc = s->p8->work->u;
        o->state = 1;
    case 1:
        if (s->cnt > s->s2 || s->pc->s6 == 0xe) {
            o->state = 0xfa;
            break;
        }
        for (i = 0; i < 10; i++) {
            s16 e = s->tab->a28[i];
            if (e != 0 && s->cnt == e) {
                s->pc->fec |= 1;
                if (fn_80075FF0(s->p8, s->tab->a14[i], -1) == 0) {
                    s->pc->fec &= ~1;
                } else {
                    U54B74 *u;
                    P54B74 *t;
                    s32 x;
                    t = s->p8;
                    x = s->tab->a14[i];
                    u = t->work->u;
                    u->ff0 |= 8;
                    fn_80008C00(t, x, 0, 0xe, 3, t->work->d10->f30);
                    if (!(u->ff0 & 0x800)) {
                        if (x == 0xe && !(u->fec & 0x100)) {
                            x = 0x20;
                        }
                        fn_80008C00(t, x, 0, 0x36, 3, t->work->d10->f30);
                    }
                }
            }
        }
        break;
    case 0xf9:
    case 0xfa:
        o->flags |= 0x40;
        lbl_8030A10C.count--;
        return;
    }
    s->cnt = s->cnt + 1;
    fn_80037FD8((void *)(s->tab), (void *)(&o->state));
}

void fn_80055058(O *o) {
    S *s = o->w->s;
    Un *u;
    Un *u2;
    switch (o->state) {
    case 0:
        u = s->p->wk->unit;
        u->fec |= 0x40000;
        s->id = u->id;
        o->state = 1;
    case 1:
        if (fn_80021728(s->id) == 0) {
            o->state = 0xfa;
            return;
        }
        u = s->p->wk->unit;
        if (s->cnt == s->a->s14) {
            s->fc = -1.0f / (f32)(s->a->s16 - s->a->s14);
            u->fec |= 0x20000000;
            u->ff0 |= 0x80000000;
            u->f50 |= 0x40000;
            o->state = 3;
        } else {
            u->f164 = 0.0f;
            break;
        }
    case 3:
        if (fn_80021728(s->id) == 0) {
            o->state = 0xfa;
            return;
        }
        u = s->p->wk->unit;
        if (s->cnt >= s->a->s16) {
            o->state = 4;
            u->f164 = -1.0f;
        } else {
            if (s->f8 > -1.0f) {
                s->f8 += s->fc;
            }
            u->f164 = s->f8;
            break;
        }
    case 4:
        if (s->cnt < s->a->s2a) {
            break;
        }
        o->state = 0xfa;
    case 0xfa:
        if (fn_80021728(s->id) != 0) {
            u = s->p->wk->unit;
            if (lbl_80347394 != 0) {
                u->f164 = 0.0f;
                u->fec &= ~0x20000000;
            }
            u->fec &= ~0x40000;
            if (s->a->f10 & 0x40000000) {
                o->state = 5;
                u->fec |= 0x100;
                return;
            }
        }
        fn_801E17E0(s);
        o->flags |= 0x40;
        lbl_8030A10C.count--;
        return;
    case 5:
        if (fn_8006D1C4() != 0) {
            u2 = s->p->wk->unit;
            fn_8001DCA0(u2);
            fn_80018700(u2->id);
            u2->fec |= 0x400000;
            fn_801E17E0(s);
            o->flags |= 0x40;
            lbl_8030A10C.count--;
        }
        return;
    }
    s->cnt = s->cnt + 1;
}
