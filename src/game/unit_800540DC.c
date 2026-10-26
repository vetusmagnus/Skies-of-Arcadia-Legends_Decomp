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
