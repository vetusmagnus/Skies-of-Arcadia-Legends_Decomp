#include "types.h"

extern u8 lbl_802F6748[];
extern s32 lbl_803476E4;
void *fn_801E184C(void *base, s32 idx, s32 a, s32 n);

void fn_801E1A74(s32 a, u32 n) {
    void *p;
    if (n == 0) n = 0x20;
    lbl_803476E4 = 1;
    p = fn_801E184C(lbl_802F6748, -1, a, n);
    *(s32 *)((u8 *)p - 0x10) = 0;
    lbl_803476E4 = 0;
}

void fn_801E1C34(u32 n) {
    void *p;
    if (n == 0) n = 0x20;
    p = fn_801E184C(lbl_802F6748, -1, 0, n);
    *(s32 *)((u8 *)p - 0x10) = 0;
}

void fn_801E1C7C(s32 n) {
    void *p;
    if (n == 0) n = 0x20;
    lbl_803476E4 = 1;
    p = fn_801E184C(lbl_802F6748, -1, 0, n);
    *(s32 *)((u8 *)p - 0x10) = 0;
    lbl_803476E4 = 0;
}
