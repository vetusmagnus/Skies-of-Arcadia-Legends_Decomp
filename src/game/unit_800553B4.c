#include "types.h"
s32 fn_80227068(s32 n);
typedef struct { f32 x, y, z; } V3;
typedef struct U553FC {
    s8 b0;
    u8 pad1[0xf0 - 1];
    u32 ff0;            /* 0xF0 */
    u8 padf4[0x164 - 0xf4];
    f32 f164;           /* 0x164 */
} U553FC;
typedef struct W553FC {
    u8 pad0[0x1c];
    V3 pos;
    u8 pad28[0x4c - 0x28];
    U553FC *u;
} W553FC;
typedef struct T553FC {
    u8 pad0[0x24];
    W553FC *work;
} T553FC;
typedef struct A553FC {
    u8 pad0[0x14];
    s16 s14;
    s16 s16;
    V3 v18;
} A553FC;
typedef struct S553FC {
    u16 cnt;
    u8 pad2[2];
    T553FC *target;
    V3 v8;
    A553FC *a;
} S553FC;
typedef struct O553FC {
    u8 pad0[0x18];
    u8 flags;
    u8 state;
    u8 pad1A[10];
    S553FC *s;
} O553FC;
typedef struct G553FC {
    u8 pad[0x1c4];
    s32 count;
} G553FC;
extern G553FC lbl_8030A10C;
extern void fn_80071CF0(V3 *, V3 *);
extern void fn_8001E4A0(V3 *, V3 *, T553FC *);
extern void fn_80037FD8(void *cmd, u8 *state);

s32 fn_800553B4(void) {
  if (fn_80227068(1) == 0) {
    return fn_80227068(1) != 0;
  }
  return 1;
}

void fn_800553FC(O553FC *o) {
    S553FC *s = o->s;
    V3 v;
    switch (o->state) {
    case 0:
        if (s->cnt != s->a->s14) {
            break;
        }
        fn_80071CF0(&s->target->work->pos, &s->v8);
        fn_8001E4A0(&s->a->v18, &v, s->target);
        fn_80071CF0(&v, &s->target->work->pos);
        s->target->work->u->ff0 |= 0x40000000;
        o->state = 1;
    case 1:
        if (s->cnt != s->a->s16) {
            break;
        }
        fn_80071CF0(&s->v8, &s->target->work->pos);
        s->target->work->u->ff0 &= ~0x40000000;
        o->state = 0xfa;
        break;
    case 0xf9:
    case 0xfa:
        o->flags |= 0x40;
        lbl_8030A10C.count--;
        return;
    }
    s->cnt = s->cnt + 1;
    fn_80037FD8(s->a, &o->state);
}
typedef struct {
    u8 pad0[0x10];
    u32 flags10;     /* 0x10 */
    s16 s14;
    s16 s16;
    s16 s18;
    s16 s1a;
    u16 kind;        /* 0x1C */
    s16 s1e;
    u8 pad20[4];
    f32 f24;         /* 0x24 */
} Cfg55558;

typedef struct {
    u16 frame;            /* 0x00 */
    u8 pad2[2];
    T553FC *a;         /* 0x04 */
    f32 fa;               /* 0x08 */
    f32 fb;               /* 0x0C */
    s8 list[13];          /* 0x10 */
    s8 count;             /* 0x1D */
    u8 pad1E[2];
    Cfg55558 *cfg;             /* 0x20 */
} W55558;

typedef struct {
    u8 pad0[0x18];
    u8 flags;        /* 0x18 */
    u8 state;        /* 0x19 */
    u8 pad1A[0x24 - 0x1A];
    W55558 *work;        /* 0x24 */
} T55558;

extern T553FC *lbl_80309E24[12];

s32 fn_800154BC(T553FC *t);
s32 fn_80015D78(T553FC *t, s32 id, s32 a, s32 b, s32 c, s32 d, f32 f);
s32 fn_8001D944(u8 id, T553FC *t);

void fn_80055558(T55558 *t)
{
    U553FC *self;
    W55558 *w;
    s16 m;
    s16 j;
    s16 n;
    s32 ok;
    U553FC *os;
    s16 i;
    f32 f;
    Cfg55558 *c;

    w = t->work;
    f = 0.0f;
    n = 0;
    ok = 0;
    self = w->a->work->u;
    switch (t->state) {
    case 0:
        for (j = 0; j < 12; j++) {
            if (lbl_80309E24[j] != NULL && fn_800154BC(lbl_80309E24[j]) == 0) {
                c = w->cfg;
                os = lbl_80309E24[j]->work->u;
                switch (c->kind) {
                case 0:
                    ok = fn_80015D78(w->a, os->b0, c->s1e, 0, 0, 0, 0.0f);
                    break;
                case 1:
                    ok = fn_80015D78(w->a, os->b0, 0, 0, 0, 3, c->f24);
                    break;
                }
                if (ok != 0) {
                    if (w->cfg->flags10 & 0x10000000)
                        ok = 0;
                } else {
                    if (w->cfg->flags10 & 0x10000000)
                        ok = 1;
                }
                if (ok != 0) {
                    if (!(w->cfg->flags10 & 0x80000000)) {
                        if (fn_8001D944(os->b0, w->a) == 0)
                            ok = 0;
                    }
                    if (!(w->cfg->flags10 & 0x40000000)) {
                        if (fn_8001D944(os->b0, w->a) != 0)
                            ok = 0;
                    }
                }
                if (os->b0 == self->b0)
                    ok = 0;
                if (ok != 0)
                    w->list[n++] = os->b0;
            }
        }
        w->count = n;
        t->state = 1;
    case 1:
        if (w->frame >= w->cfg->s18 && w->cfg->s1a != 0) {
            if (w->frame == w->cfg->s18)
                w->fa = 1.0f / w->cfg->s1a;
            if (w->frame < w->cfg->s18 + w->cfg->s1a)
                f = w->fa;
        } else if (w->frame >= w->cfg->s14 && w->cfg->s16 != 0) {
            if (w->frame == w->cfg->s14)
                w->fb = -1.0f / w->cfg->s16;
            if (w->frame < w->cfg->s14 + w->cfg->s16)
                f = w->fb;
        }
        if (w->frame >= w->cfg->s14 + w->cfg->s16 && w->frame >= w->cfg->s18 + w->cfg->s1a) {
            t->state = 0xfa;
            for (m = 0; m < 12; m++) {
                if (lbl_80309E24[m] != NULL && fn_800154BC(lbl_80309E24[m]) == 0) {
                    os = lbl_80309E24[m]->work->u;
                    for (i = 0; i < w->count; i++) {
                        if (w->list[i] == os->b0)
                            os->ff0 &= 0x7FFFFFFF;
                    }
                }
            }
        }
        if (f) {
            for (m = 0; m < 12; m++) {
                if (lbl_80309E24[m] != NULL && fn_800154BC(lbl_80309E24[m]) == 0) {
                    os = lbl_80309E24[m]->work->u;
                    if (os->f164 > 0.0f)
                        os->f164 = 0.0f;
                    for (i = 0; i < w->count; i++) {
                        if (w->list[i] == os->b0) {
                            os->f164 += f;
                            os->ff0 |= 0x80000000;
                        }
                    }
                    if (os->f164 <= -1.0f)
                        os->f164 = -1.0f;
                    else if (os->f164 > 0.0f)
                        os->f164 = 0.0f;
                }
            }
        }
        break;
    case 0xf9:
    case 0xfa:
        t->flags |= 0x40;
        lbl_8030A10C.count--;
        return;
    }
    w->frame++;
    fn_80037FD8(w->cfg, &t->state);
}

