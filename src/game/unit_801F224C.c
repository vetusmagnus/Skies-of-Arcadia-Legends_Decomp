#include "types.h"

extern u8 lbl_8030B4D4[];
extern u8 lbl_8030B7F4[];
void fn_801EF7E0(void *p);

s32 fn_801F2508(void *a, void *b)
{
    return *(s16 *)((u8 *)a + 0xa) - *(s16 *)((u8 *)b + 0xa);
}

s32 fn_801F2894(s32 a, s32 b)
{
    return *(s32 *)(lbl_8030B4D4 + a * 0x78 + (b << 2) + 0x60);
}

s32 fn_801F28B4(s32 a)
{
    return *(s32 *)(lbl_8030B4D4 + a * 0x78 + 0x18);
}

void fn_801F4E04(s32 i, s16 v) {
    u8 *p = lbl_8030B7F4;
    p += i * 0x5c;
    *(s16 *)(p + 0x14) = v;
    fn_801EF7E0(p);
}

void fn_801F4E38(s32 i, s16 v) {
    u8 *p = lbl_8030B7F4;
    p += i * 0x5c;
    *(s16 *)(p + 0x12) = v;
    fn_801EF7E0(p);
}

void fn_801F4E6C(s32 i, s16 v) {
    u8 *p = lbl_8030B7F4;
    p += i * 0x5c;
    *(s16 *)(p + 0x10) = v;
    fn_801EF7E0(p);
}
