#include <dolphin/types.h>
#include "types.h"

extern void* lbl_80346F38;
extern void* lbl_80346F40;
extern void* lbl_80346F48;
extern void* lbl_80346F50;
extern void* lbl_80346F58;
extern void* lbl_803475A8;
extern u8 lbl_80305FC0[];
s32 fn_80136A28(void* a, s32 b, s32 c, s32 d, s32 e, s32 f);
void fn_801365D8(s32 a, s32 b, s32 c, s32 d, s32 e);
void *fn_802268E8(void *a, void (*f)(void));
void *fn_801E1C7C(u32 n);
void fn_801303D0(void);
void fn_80131734(void);
void fn_80132458(void);
void fn_801331AC(void);

void fn_8012F6C4(s8 idx, u32 val) {
    u8* p = *(u8**)((u8*)lbl_80346F38 + 0x24);
    p = p + (s32)idx * 4;
    *(u32*)(p + 0x14) = val;
}

void fn_8012F6E0(s8 idx, u8 val) {
    u8* arr = *(u8**)((u8*)lbl_80346F38 + 0x24);
    arr[idx + 0xa] = val;
}

void fn_8012F6F8(s8 idx, u8 val) {
    u8* arr = *(u8**)((u8*)lbl_80346F38 + 0x24);
    arr[idx + 0x2] = val;
}

void fn_8012F710(s8 idx, u32 val) {
    u8* p = *(u8**)((u8*)lbl_80346F38 + 0x24);
    p = p + (s32)idx * 4;
    *(u32*)(p + 0x34) = val;
}

void fn_8012F744(void) {
    u8* p = (u8*)lbl_80346F38;
    if (p == NULL) {
        return;
    }
    p[0x19] = 2;
}

s32 fn_8012FF08(void) {
    u8 *o = *(u8 **)((u8 *)lbl_80346F40 + 0x24);
    u8 c = o[1];
    s32 t = (s8)c;
    if (t == 0xd || (u8)(c - 0xe) <= 1 || t == 0x10) {
        return 1;
    }
    return 0;
}

void fn_80130304(s8 v) {
    u8* p = *(u8**)((u8*)lbl_80346F40 + 0x24);
    *(s16*)(p + 0xa4) = v;
}

void fn_80131598(u8 v) {
    u8* p = *(u8**)((u8*)lbl_80346F48 + 0x24);
    p[0xad] = v;
}

void fn_801315A8(u8* src) {
    *(u8*)(*(u8**)((u8*)lbl_80346F48 + 0x24) + 0xa9) = src[0];
    *(u8*)(*(u8**)((u8*)lbl_80346F48 + 0x24) + 0xaa) = src[1];
    *(u8*)(*(u8**)((u8*)lbl_80346F48 + 0x24) + 0xab) = src[2];
    *(u8*)(*(u8**)((u8*)lbl_80346F48 + 0x24) + 0xac) = src[3];
}

void fn_8013160C(s8 a, s8 b, u8 v) {
    u8* p = *(u8**)((u8*)lbl_80346F48 + 0x24);
    u8* q = p + (s32)a * 4;
    q = q + (s32)b;
    q[0x89] = v;
}

void fn_80131630(s8 a, s8 b, u8 v) {
    u8* arr = *(u8**)((u8*)lbl_80346F48 + 0x24);
    arr[(s32)a * 16 + (s32)b * 4 + 0x9] = v;
}

void fn_80133030(s32* src) {
    if (lbl_80346F58 == 0) return;
    *(s32*)(*(u8**)((u8*)lbl_80346F58 + 0x24) + 0x1c) = src[0];
    *(s32*)(*(u8**)((u8*)lbl_80346F58 + 0x24) + 0x20) = src[1];
    *(s32*)(*(u8**)((u8*)lbl_80346F58 + 0x24) + 0x24) = src[2];
}

void fn_8013306C(void* v) {
    u8* p = (u8*)lbl_80346F58;
    if (p == NULL) {
        return;
    }
    *(void**)(*(u8**)((u8*)p + 0x24) + 0x18) = v;
}

void fn_80133084(void* v) {
    u8* p = (u8*)lbl_80346F58;
    if (p == NULL) {
        return;
    }
    *(void**)(*(u8**)((u8*)p + 0x24) + 0x14) = v;
}

void fn_8013309C(void* v) {
    u8* p = (u8*)lbl_80346F58;
    if (p == NULL) {
        return;
    }
    *(void**)(*(u8**)((u8*)p + 0x24) + 0x10) = v;
}

void fn_801330B4(void* v) {
    u8* p = (u8*)lbl_80346F58;
    if (p == NULL) {
        return;
    }
    *(void**)(*(u8**)((u8*)p + 0x24) + 0xc) = v;
}

void fn_801330CC(void* v) {
    u8* p = (u8*)lbl_80346F58;
    if (p == NULL) {
        return;
    }
    *(void**)(*(u8**)((u8*)p + 0x24) + 0x8) = v;
}

void fn_801330E4(u8 v) {
    u8* p = (u8*)lbl_80346F58;
    if (p == NULL) {
        return;
    }
    *(u8*)(*(u8**)((u8*)p + 0x24) + 0x4) = v;
}

void fn_801330FC(u8 v) {
    u8* p = (u8*)lbl_80346F58;
    if (p == NULL) {
        return;
    }
    *(u8*)(*(u8**)((u8*)p + 0x24) + 0x2) = v;
}

void* fn_8013558C(void) {
    return lbl_80305FC0;
}

s32 fn_801380D4(u8* p) {
    p[0x1] = 0;
    return 2;
}

s32 fn_801380E4(void* a, s32 b) {
    return fn_80136A28(a, b, 6, -1, -1, -1);
}

s32 fn_801383EC(void* a, s32 b, s32 c) {
    return fn_80136A28(a, b, 5, -1, c, -1);
}

void fn_80130378(void) {
    *(void **)&lbl_80346F40 = fn_802268E8(lbl_803475A8, fn_801303D0);
    *(void **)((u8 *)lbl_80346F40 + 0x24) = fn_801E1C7C(0xe8);
    if (lbl_80346F40 != 0) {
        **(u8 **)((u8 *)lbl_80346F40 + 0x24) = 1;
    }
}

void fn_801316DC(void) {
    *(void **)&lbl_80346F48 = fn_802268E8(lbl_803475A8, fn_80131734);
    *(void **)((u8 *)lbl_80346F48 + 0x24) = fn_801E1C7C(0xb0);
    if (lbl_80346F48 != 0) {
        **(u8 **)((u8 *)lbl_80346F48 + 0x24) = 1;
    }
}

void fn_80132400(void) {
    *(void **)&lbl_80346F50 = fn_802268E8(lbl_803475A8, fn_80132458);
    *(void **)((u8 *)lbl_80346F50 + 0x24) = fn_801E1C7C(0x7c);
    if (lbl_80346F50 != 0) {
        **(u8 **)((u8 *)lbl_80346F50 + 0x24) = 1;
    }
}

void fn_80133154(void) {
    *(void **)&lbl_80346F58 = fn_802268E8(lbl_803475A8, fn_801331AC);
    *(void **)((u8 *)lbl_80346F58 + 0x24) = fn_801E1C7C(0x28);
    if (lbl_80346F58 != 0) {
        **(u8 **)((u8 *)lbl_80346F58 + 0x24) = 1;
    }
}

void fn_80136FDC(s32 a, s32 b, s8 *tbl, s32 idx) {
    s32 v = 0x16;
    s32 ok = 0;
    if (idx >= 0 && idx < 6) {
        ok = 1;
    }
    if (ok != 0) {
        v = tbl[idx];
    }
    ok = 0;
    if (v >= 0 && v < 0x16) {
        ok = 1;
    }
    if (ok != 0) {
        fn_80136A28((void*)a, b, 7, v, -1, -1);
    }
}

void fn_80137058(s32 a, s32 b, s8 *tbl, s32 idx) {
    s32 ok = 0;
    s32 v = 0x16;
    if (idx >= 0 && idx < 6) {
        ok = 1;
    }
    if (ok != 0) {
        v = tbl[idx];
    }
    fn_801365D8(a, b, 7, v, 0xe);
}

s32 fn_80138848(s32 r3)
{
    s32 r0 = -1;
    switch (r3) {
    case 0: r0 = 4; break;
    case 1: r0 = 3; break;
    case 2: r0 = 6; break;
    case 3: r0 = 5; break;
    case 4: r0 = 7; break;
    case 5: r0 = 8; break;
    }
    return r0;
}

s32 fn_801388B4(s32 r3)
{
    s32 r0 = -1;
    switch (r3) {
    case 0: r0 = 0; break;
    case 1: r0 = 1; break;
    case 2: r0 = 2; break;
    case 3: r0 = 3; break;
    case 4: r0 = 4; break;
    case 5: r0 = 5; break;
    }
    return r0;
}
