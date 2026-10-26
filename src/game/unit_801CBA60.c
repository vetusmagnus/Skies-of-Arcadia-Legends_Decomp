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
extern u32 lbl_80347518;
extern f32 lbl_80347510;
extern u32 lbl_80347508;
extern u32 lbl_80347504;
extern s32 fn_8023A4B0(void);

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

typedef struct Msg {
    s16 x0;
    s16 x2;
    s16 x4;
    s16 x6;
    s32 x8;
    s32 xc;
} Msg;
extern void fn_801CBC90(Msg*, s16);
extern u32 lbl_803471F8;
void fn_801CBBF8(void) {
    lbl_803471F8 = 1;
}

void fn_801CBC04(void) {
    lbl_803474F8 = 0;
}

void fn_801CBC10(Msg* a, s16 i) {
    fn_801CBC90(a, i);
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

extern void fn_801CBE38(Msg*, s16);
void fn_801CC3A4(Msg* a, s16 i) {
    fn_801CBE38(a, i);
}

extern void fn_8023AB28(Msg*, s16);
void fn_801CC578(Msg* a, s16 i) {
    fn_8023AB28(a, i);
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

void fn_801CBBBC(void) {
    lbl_80347518 = 0;
    lbl_80347510 = 0.0f;
    lbl_80347508 = 0;
    lbl_80347504 = 0;
}

void fn_801CBBD8(void) {
    lbl_80347518 = 1;
    lbl_80347510 = 1.0f;
    lbl_80347508 = 0;
    lbl_80347504 = 1;
}

void fn_801CC600(u8 *p, u32 v) {
    *(u32 *)(p + 0x4c) = v;
}

u32 fn_801CC62C(void) {
    return fn_8023A4B0() != -1;
}

extern void fn_801C6384(Msg*, s16);
void fn_801CC65C(Msg* a, s16 i) {
    fn_801C6384(a, i);
}

extern void fn_801C63EC(Msg*, s16);
void fn_801CC67C(Msg* a, s16 i) {
    fn_801C63EC(a, i);
}

extern void fn_801C64DC(Msg*, s16);
void fn_801CC69C(Msg* a, s16 i) {
    fn_801C64DC(a, i);
}
