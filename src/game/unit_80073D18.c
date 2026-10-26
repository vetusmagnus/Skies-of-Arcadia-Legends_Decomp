#include "types.h"

extern void fn_800740D0(void* a);

void fn_80073D18(u8* a, u8* b, s16 idx) {
    s32 off = idx * 0x34;
    *(u32*)(a + off) |= 8;
    *(u32*)(b + off) |= 8;
}

void fn_80074394(void* a, s16* b) {
    *b = 0;
    fn_800740D0(a);
}
