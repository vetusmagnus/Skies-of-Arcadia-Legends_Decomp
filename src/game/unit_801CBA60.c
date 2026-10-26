#include "types.h"

typedef struct Ent {
    float a;
    s32 b;
    float c;
} Ent;
extern Ent lbl_8030E7C0[4];
extern s32 lbl_803474F8;
extern s32 lbl_8034750C;
void fn_801E1718(void *o);
s32 fn_801C6BC8(void);

void fn_801CBA60(float a, float c)
{
    s32 i = lbl_803474F8;
    if (i >= 4) {
        return;
    }
    lbl_8030E7C0[i].a = a;
    lbl_8030E7C0[i].b = lbl_8034750C;
    lbl_803474F8 = i + 1;
    lbl_8030E7C0[i].c = c;
}

u32 fn_801CC0A0(u32 *o)
{
    u32 v;
    if (o[0] != 0) {
        return 0;
    }
    v = o[1];
    fn_801E1718(o);
    return v;
}

s32 fn_801CC5BC(void)
{
    s32 r = fn_801C6BC8();
    s32 v;
    if (r == 3) {
        v = 1;
    } else if (r == 4) {
        v = 2;
    } else {
        v = 0;
    }
    return v;
}
