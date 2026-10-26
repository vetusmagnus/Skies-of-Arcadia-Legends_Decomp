#include "types.h"
s32 fn_80227068(s32 n);
typedef struct { f32 x, y, z; } V3;
typedef struct U553FC {
    u8 pad0[0xf0];
    u32 ff0;
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
extern void fn_80037FD8(A553FC *, u8 *);

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
