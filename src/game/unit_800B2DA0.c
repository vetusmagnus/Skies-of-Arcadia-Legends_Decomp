#include "types.h"

extern s32 lbl_803473C8;
extern s32 lbl_803473CC;
extern s32 lbl_803473D0;
extern s32 lbl_803473D4;
extern s32 lbl_803473D8;
extern s32 lbl_80346D4C;
extern s32 lbl_80346D5C;
extern void* fn_801DB124(void* a);
extern u8* lbl_80346D70;
extern f32 lbl_802E1118[];
extern s32 lbl_80346D8C;
extern void fn_800CF7BC(void* a, void* b);
extern u8 lbl_80305BA8[];
extern u8 lbl_80310A1C[];

void fn_800B2DA0(u8* p, u32 v) {
    u8* q = *(u8**)(p + 0x268);
    if (q == NULL) {
        return;
    }
    *(u32*)(q + 0x78) = v;
    *(u32*)q |= 0x200;
}

void fn_800C1A34(s32 a, s32 b, s32 c, s32 d) {
    lbl_803473D0 = a;
    lbl_803473D4 = 1;
    lbl_803473CC = b;
    lbl_803473C8 = c;
    lbl_803473D8 = d;
}

int fn_800C7DD4(void) {
    if (lbl_80346D5C == 1 || lbl_80346D4C > 0) {
        return 1;
    }
    return 0;
}

void fn_800C81BC(int unused, u8* p) {
    *(void**)(p + 4) = fn_801DB124(*(void**)(p + 4));
}

void fn_800C9060(void) {
    lbl_80346D70[0x19] = 2;
}

int fn_800CB650(int unused, u8* p, u32 v) {
    p[0x1ed] = 2;
    *(u32*)(p + 0x268) = v;
    return 1;
}

int fn_800CB664(int unused, u8* p, u32 v) {
    p[0x1ed] = 1;
    *(u32*)(p + 0x268) = v;
    return 1;
}

int fn_800CB678(int unused, u8* p, u32 v) {
    p[0x1ed] = 0;
    *(u32*)(p + 0x268) = v;
    return 1;
}

void fn_800CF8C4(void* p) {
    lbl_80346D8C = 1;
    fn_800CF7BC(lbl_802E1118, p);
}

void fn_800D2C44(u16 v) {
    if (v == 0xffff) {
        return;
    }
    *(u16*)(lbl_80305BA8 + 0x28) = v;
}

void fn_800D2C60(f32 a, f32 b) {
    *(f32*)(lbl_80305BA8 + 0x18) = a;
    *(f32*)(lbl_80305BA8 + 0x20) = b;
}

void fn_800D2C74(u32 v) {
    *(u32*)(lbl_80305BA8 + 0x10) = v;
}

void fn_800D2C84(u8 v) {
    lbl_80305BA8[0x2] = v;
}

void fn_800D2C94(s8 v) {
    *(s16*)(lbl_80305BA8 + 0x4) = v;
}

void fn_800D2CA8(u8 v) {
    lbl_80305BA8[0x1] = v;
}

void fn_800D2CB8(u8 v) {
    lbl_80305BA8[0] = v;
}

int fn_800D7B04(void) {
    return (s8)lbl_80310A1C[0x11] != 2;
}
