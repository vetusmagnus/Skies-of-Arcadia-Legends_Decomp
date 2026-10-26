#include "types.h"

extern u32 lbl_80347228;
extern u32 lbl_80347230;
extern u32 lbl_8034723C;
extern u32 lbl_80347240;
extern u32 lbl_80347248;
extern u32 lbl_80347234;
extern u32 lbl_80347238;
extern f32 lbl_80347244;
extern void fn_801CF248(void);
extern s32 lbl_80347208;
extern s32 lbl_80347210;
extern s32 lbl_80347258;
extern s32 lbl_8034725C;
extern s32 lbl_80347264;
extern u32 lbl_803476A4;
extern u32 lbl_80347260;
extern void fn_80005AD8(u32 a, u32 b);

void fn_801CED24(u32 a, u32 b, u32 c, f32 d, u32 e)
{
    lbl_80347230 = a;
    lbl_80347228 = 0x08000000;
    lbl_8034723C = b;
    lbl_80347240 = c;
    lbl_80347244 = d;
    lbl_80347248 = e;
    fn_801CF248();
}

void fn_801CED60(u32 a, u32 b, u32 c, f32 d, u32 e)
{
    lbl_80347230 = a;
    lbl_80347228 = 0x04000000;
    lbl_8034723C = b;
    lbl_80347240 = c;
    lbl_80347244 = d;
    lbl_80347248 = e;
    fn_801CF248();
}

void fn_801CED9C(u32 a, u32 b, u32 c, f32 d, u32 e)
{
    lbl_80347230 = a;
    lbl_80347228 = 0x02000000;
    lbl_8034723C = b;
    lbl_80347240 = c;
    lbl_80347244 = d;
    lbl_80347248 = e;
    fn_801CF248();
}

void fn_801CEDD8(u32 a, u32 b, u32 c, f32 d, u32 e)
{
    lbl_80347230 = a;
    lbl_80347228 = 0x01000000;
    lbl_8034723C = b;
    lbl_80347240 = c;
    lbl_80347244 = d;
    lbl_80347248 = e;
    fn_801CF248();
}

void fn_801CEE14(u32 a, u32 b, f32 d, u32 c)
{
    lbl_80347230 = a;
    lbl_80347228 = 0x00800000;
    lbl_8034723C = b;
    lbl_80347244 = d;
    lbl_80347248 = c;
    fn_801CF248();
}

void fn_801CEE4C(u32 a, u32 b, f32 d, u32 c)
{
    lbl_80347230 = a;
    lbl_80347228 = 0x00400000;
    lbl_8034723C = b;
    lbl_80347244 = d;
    lbl_80347248 = c;
    fn_801CF248();
}

void fn_801CEE84(u32 a, u32 b, f32 d, u32 c)
{
    lbl_80347230 = a;
    lbl_80347228 = 0x00200000;
    lbl_8034723C = b;
    lbl_80347244 = d;
    lbl_80347248 = c;
    fn_801CF248();
}

void fn_801CEEBC(u32 a, u32 b, f32 d, u32 c)
{
    lbl_80347230 = a;
    lbl_80347228 = 0x00100000;
    lbl_8034723C = b;
    lbl_80347244 = d;
    lbl_80347248 = c;
    fn_801CF248();
}

void fn_801CEEF4(u32 a, u32 b, u32 c, f32 d, u32 e)
{
    lbl_80347230 = a;
    lbl_80347228 = 0x00080000;
    lbl_80347234 = b;
    lbl_80347238 = c;
    lbl_80347244 = d;
    lbl_80347248 = e;
    fn_801CF248();
}

void fn_801CEF30(u32 a, u32 b, u32 c, f32 d, u32 e)
{
    lbl_80347230 = a;
    lbl_80347228 = 0x00040000;
    lbl_80347234 = b;
    lbl_80347238 = c;
    lbl_80347244 = d;
    lbl_80347248 = e;
    fn_801CF248();
}

void fn_801CEF6C(u32 a, u32 b, u32 c, f32 d, u32 e)
{
    lbl_80347230 = a;
    lbl_80347228 = 0x00020000;
    lbl_80347234 = b;
    lbl_80347238 = c;
    lbl_80347244 = d;
    lbl_80347248 = e;
    fn_801CF248();
}

void fn_801CEFA8(u32 a, u32 b, u32 c, f32 d, u32 e)
{
    lbl_80347230 = a;
    lbl_80347228 = 0x00010000;
    lbl_80347234 = b;
    lbl_80347238 = c;
    lbl_80347244 = d;
    lbl_80347248 = e;
    fn_801CF248();
}

void fn_801CEFE4(u32 a, u32 b, f32 d, u32 c)
{
    lbl_80347230 = a;
    lbl_80347228 = 0x8000;
    lbl_80347234 = b;
    lbl_80347244 = d;
    lbl_80347248 = c;
    fn_801CF248();
}

void fn_801CF020(u32 a, u32 b, f32 d, u32 c)
{
    lbl_80347230 = a;
    lbl_80347228 = 0x4000;
    lbl_80347234 = b;
    lbl_80347244 = d;
    lbl_80347248 = c;
    fn_801CF248();
}

void fn_801CF058(u32 a, u32 b, f32 d, u32 c)
{
    lbl_80347230 = a;
    lbl_80347228 = 0x2000;
    lbl_80347234 = b;
    lbl_80347244 = d;
    lbl_80347248 = c;
    fn_801CF248();
}

void fn_801CF090(u32 a, u32 b, f32 d, u32 c)
{
    lbl_80347230 = a;
    lbl_80347228 = 0x1000;
    lbl_80347234 = b;
    lbl_80347244 = d;
    lbl_80347248 = c;
    fn_801CF248();
}

void fn_801D0B50(s32 delta)
{
    s32 cur;
    s32 sum;
    s32 hi;

    if (lbl_80347208 == 0) {
        return;
    }
    cur = lbl_80347258 + delta;
    sum = lbl_80347264 + cur;
    hi = lbl_80347210;
    lbl_80347258 = cur;
    lbl_8034725C = sum;
    if (hi >= cur) {
        return;
    }
    lbl_80347210 = cur;
}

void fn_801D13D8(void)
{
    if (lbl_80347208 != 0) {
        lbl_80347208 = 0;
        fn_80005AD8(lbl_803476A4, lbl_80347264);
        fn_80005AD8(lbl_803476A4, lbl_80347260);
    }
}
