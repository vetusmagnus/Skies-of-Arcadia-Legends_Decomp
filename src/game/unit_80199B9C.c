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

void fn_801A64B4(void* obj, u8 idx) {
    u8* p = *(u8**)((u8*)obj + 0x24);
    u8* q = *(u8**)(p + 0x20C);
    if (q == 0) {
        return;
    }
    *(u32*)(*(u8**)(q + 0x28) + 0x4C) = lbl_802B6810[idx];
}

void fn_801A69BC(void) {
    UiSpritesFree();
}

void fn_801A69DC(void) {
    UiSpritesLoad(lbl_802B69D4);
}

int fn_801A6A58(int sub, int idx) {
    if (idx >= 0 && idx < 9) {
        return *(lbl_802EBEA4 + idx * 2 + sub);
    }
    return 0x29;
}

void fn_801B6400(u32 v) {
    u8* p = *(u8**)((u8*)lbl_803471B8 + 0x24);
    u8* q = *(u8**)(p + 0x214);
    if (q == 0) {
        return;
    }
    *(u32*)(*(u8**)(q + 0x28) + 0x4C) = v;
}

void fn_801BCFAC(u8* obj, s32 idx) {
    s32 j = *(s32*)(*(u8**)(obj + 4) + idx * 0x34);
    *(f32*)(*(u8**)obj + j * 0x14 + 0xC) = 0.59f;
}

void fn_801BEAE4(void* a, s32 b) {
    fn_801BEB10(a, 0, b, 0);
}
