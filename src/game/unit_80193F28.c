#include "types.h"

extern void fn_801DBE1C(const char *fmt, ...);
extern u8 camp_work[];
extern u8 lbl_8030B7F4[];
extern void fn_801F2860(s16 v);
extern u8 lbl_80307638[];
extern u32 lbl_80347144;
extern u8 lbl_802E98A0[];
extern u32 lbl_802F7298[];
extern u8 lbl_802D8E64[];
extern u8 *lbl_8034710C;
extern u32 lbl_803473EC;

int fn_80193F28(void) {
    fn_801DBE1C("Nothing VM Tanken.");
    return 0;
}

u16 fn_80193F58(void) {
    u8 *p = *(u8 **)(camp_work + 0x278);
    p = *(u8 **)(p + 0x24);
    p = *(u8 **)(p + 0xbc);
    p = *(u8 **)(p + 0x4);
    return *(u16 *)(p + 0x18);
}

void fn_80193F80(void) {
    fn_801F2860(*(s16 *)(lbl_8030B7F4 + 0x348));
}

u8 *fn_80193FAC(void) {
    return lbl_8030B7F4 + 0x331;
}

void fn_80194254(void) {
    lbl_80347144 = *(u32 *)(lbl_80307638 + 0x8b4);
}

u32 fn_801944C4(void) {
    return *(u32 *)(lbl_80307638 + 0x70c);
}

u8 *fn_80194C00(s8 idx) {
    return lbl_802E98A0 + idx * 9;
}

u32 fn_80194C38(s8 idx) {
    return lbl_802F7298[idx];
}

u8 *fn_80194C50(s8 idx) {
    return lbl_802D8E64 + idx * 0x24;
}

void fn_80194C68(u8 *base, u32 i, u32 j, u32 v) {
    *(u32 *)(base + i * 8 + j * 4) = v;
}

u32 fn_80194C7C(u8 *base, u32 i, u32 j) {
    u32 v = *(u32 *)(base + i * 8 + j * 4);
    return ((-1 - v) | (v + 1)) >> 31;
}

u32 fn_80194F5C(s32 a, s32 b) {
    u32 r;
    if (a > b) {
        r = 0xff2b5000;
    } else if (a < b) {
        r = 0xff800000;
    } else {
        r = 0xff201008;
    }
    return r;
}

void fn_801954D0(u32 v) {
    u8 *p = *(u8 **)(camp_work + 0x190);
    p = *(u8 **)(p + 0x24);
    p = *(u8 **)(p + 0xbc);
    *(u32 *)(p + 0x4) = v;
}

void fn_801959D4(s32 idx) {
    *(u8 **)(*(u8 **)(lbl_8034710C + 0x24)) = lbl_80307638 + idx * 0x78;
}

void fn_80195F90(void) {
    lbl_803473EC = 1;
}
