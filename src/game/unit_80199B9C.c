#include "types.h"

void UiObjUpdate(void* obj);
extern u8 lbl_8030741C[];
extern u32 lbl_80347180;
extern u8 lbl_8034717C[2];
extern void fn_801E17E0(void* p);
extern u8 lbl_803081CC[];
extern u32 lbl_802B6810[];
void UiSpritesFree(void);
void UiSpritesLoad(void* p);
extern char lbl_802B69D4[];
extern u8 lbl_802EBEA4[];
extern void* lbl_803471B8;
void fn_801BEB10(void* a, s32 b, s32 c, s32 d);
extern void fn_801DC214(u8 *obj);
extern s32 fn_80248708(u8 *obj, s32 a, s32 b);
extern s32 fn_801A6A04(s32 r);
extern void fn_801A4B40(void);
extern u8 *fn_80226670(u8 *obj, void (*cb)(void));
extern void *fn_801E1A74(s32 a, s32 b);
extern void fn_801E17E0(void *p);
typedef struct Sub {
    u8 pad0[0x8];
    float f8;
    float fc;
    u8 pad1[0xa];
    u16 h1a;
} Sub;
typedef struct Obj {
    u8 pad[0x30];
    Sub *sub;
} Obj;
extern void *lbl_803471B8;

void fn_80199B9C(void* p, f32 v) {
    *(f32*)((u8*)p + 0x34) = v;
}

void fn_80199BA4(void* p, u8 v) {
    *(u8*)((u8*)p + 0x40) = v;
}

void fn_80199BAC(void* p, f32 a, f32 b) {
    *(f32*)((u8*)p + 0x4) = a;
    *(f32*)((u8*)p + 0x8) = b;
}

void fn_80199BB8(void* p, f32 a, f32 b) {
    *(f32*)((u8*)p + 0xC) = a;
    *(f32*)((u8*)p + 0x10) = b;
}

void fn_80199F38(void* obj) {
    UiObjUpdate(obj);
}

void fn_8019AD94(void* p, u32 a, u32 b) {
    ((u32*)p)[0] = a;
    ((u32*)p)[1] = b;
}

void fn_8019B42C(void* p, u32 a) {
    ((u32*)p)[0] = a;
    ((u8**)p)[1] = lbl_8030741C + 8;
    ((u32*)p)[2] = 0;
}

void fn_801A289C(void) {
    lbl_80347180 = 0;
}

void fn_801A28AC(u8 *obj) {
    s32 r;
    fn_801DC214(obj);
    do {
        r = fn_80248708(obj, 0, 0);
    } while (r == -1);
    fn_801A6A04(r);
}

void fn_801A2D20(u8 *obj, u32 a, u32 b) {
    *(f32 *)(*(u8 **)(obj + 0x24) + 0x1c) = (f32)a / (f32)b;
}

void fn_801A37C4(void) {
    u8* p = lbl_8034717C;
    p[1] = 0;
    lbl_8034717C[0] = 0;
}

void fn_801A4060(void* obj) {
    *(u32*)(*(u8**)((u8*)obj + 0x24) + 0x268) = 0;
}

void fn_801A41C0(void* obj) {
    void* p = *(void**)obj;
    if (p != 0) {
        fn_801E17E0(p);
    }
}

void fn_801A471C(s32 idx) {
    u8* p = lbl_803081CC + idx * 0x50;
    *(u32*)(p + 0xC) = 0;
    *(u32*)(p + 0x10) = 0;
}

u8 *fn_801A4AF4(u8 *obj) {
    u8 *r31 = fn_80226670(obj, fn_801A4B40);
    *(void **)(r31 + 0x24) = fn_801E1A74(1, 6);
    return r31;
}

void fn_801A64B4(void* obj, u8 idx) {
    u8* p = *(u8**)((u8*)obj + 0x24);
    u8* q = *(u8**)(p + 0x20C);
    if (q == 0) {
        return;
    }
    *(u32*)(*(u8**)(q + 0x28) + 0x4C) = lbl_802B6810[idx];
}

void fn_801A6824(u8 *obj) {
    if (*(void **)(*(u8 **)(obj + 0x24) + 0x204) != 0) {
        fn_801E17E0(*(void **)(*(u8 **)(obj + 0x24) + 0x204));
        *(u32 *)(*(u8 **)(obj + 0x24) + 0x204) = 0;
    }
}

void fn_801A69BC(void) {
    UiSpritesFree();
}

void fn_801A69DC(void) {
    UiSpritesLoad(lbl_802B69D4);
}

s32 fn_801A6A04(s32 x)
{
    s32 r;
    switch (x + 13) {
    case 12:
    case 13:
        r = 0;
        break;
    case 11:
        r = 5;
        break;
    case 10:
        r = 1;
        break;
    case 8:
        r = 4;
        break;
    case 0:
    case 7:
        r = 2;
        break;
    default:
        r = 8;
        break;
    }
    return r;
}

int fn_801A6A58(int sub, int idx) {
    if (idx >= 0 && idx < 9) {
        return *(lbl_802EBEA4 + idx * 2 + sub);
    }
    return 0x29;
}

void fn_801AB98C(Obj *o)
{
    Sub *s = o->sub;
    s->fc = (float)(s32)(s->h1a * 0x18);
    o->sub->f8 = 0.0f;
}

void fn_801B6400(u32 v) {
    u8* p = *(u8**)((u8*)lbl_803471B8 + 0x24);
    u8* q = *(u8**)(p + 0x214);
    if (q == 0) {
        return;
    }
    *(u32*)(*(u8**)(q + 0x28) + 0x4C) = v;
}

u32 fn_801B94F0(void)
{
    u8 *p = *(u8 **)((u8 *)lbl_803471B8 + 0x30);
    u32 sum = *(u32 *)(p + 0x3cc);
    sum += *(u32 *)(p + 0x0);
    sum += *(u32 *)(p + 0x144);
    sum += *(u32 *)(p + 0x288);
    sum += *(u32 *)(p + 0x510);
    return sum != 0;
}

void fn_801BCFAC(u8* obj, s32 idx) {
    s32 j = *(s32*)(*(u8**)(obj + 4) + idx * 0x34);
    *(f32*)(*(u8**)obj + j * 0x14 + 0xC) = 0.59f;
}

void fn_801BEAE4(void* a, s32 b) {
    fn_801BEB10(a, 0, b, 0);
}
