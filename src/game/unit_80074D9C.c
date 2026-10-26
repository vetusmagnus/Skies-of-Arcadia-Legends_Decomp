#include "types.h"

extern s16 lbl_803097F0[];
extern u32 lbl_802B0830[];
typedef struct ChrState {
    s32 x0;
    u8 pad[0x1c];
} ChrState;
extern s32 lbl_80347330;
extern ChrState lbl_80309174[12];
extern s8 lbl_802AD440[];
extern s8 lbl_802C7C34[];
extern s8 lbl_802C4BF0[];
extern void fn_8006B774(void* p);
typedef struct Work {
    u8 pad[0x3c];
    s32 x3c;
} Work;
typedef struct Tk {
    u8 pad[0x24];
    Work* work;
} Tk;
extern Tk* lbl_80309700[12];
extern u8* fn_80021658(s32 i);
extern u8 lbl_80309730[];
extern s16 lbl_80302BF0[];
extern void fn_80081FEC(s32 i);
extern s8 lbl_80347334;
extern void fn_80083BAC(void* a, s32 b);
typedef struct Chr {
    u8 pad[0x10];
    u32 x10;
} Chr;
extern Chr* lbl_80309DE4[12];

u32 fn_80075FCC(u8* p) {
    u8* a = *(u8**)(p + 0x24);
    u8* b = *(u8**)(a + 0x4c);
    s16 i = *(s16*)(b + 0xe4);
    u8* e = *(u8**)(b + 0xdc);
    e = e + i * 0x18;
    return (*(u32*)(e + 8) >> 19) & 1;
}

s32 fn_80077E34(void) {
    s16 i = lbl_803097F0[0];
    if (i == -1) {
        return -1;
    }
    return lbl_802B0830[i];
}

s32 fn_8007833C(void) {
    return lbl_80309174[lbl_80347330].x0;
}

s32 fn_80078354(s32 i) {
    return lbl_802AD440[i * 0x24 + 0x526];
}

s32 fn_80078370(s32 i) {
    return lbl_802C7C34[i * 0x24 - 0x21ae];
}

s32 fn_8007838C(s32 i) {
    return lbl_802C4BF0[i * 0x30 + 0x15];
}

s32 fn_800785EC(u8* p) {
    if (p != 0) {
        if ((*(u32*)(p + 0x1c) & 0x2100) == 0) {
            return 1;
        }
    }
    return 0;
}

s32 fn_800786B0(s16* a, s16* b) {
    s16 bv = b[1];
    return a[1] - bv;
}

void fn_8007D318(u8* p) {
    if (p == 0) {
        return;
    }
    p[0x19] = 7;
}

void fn_8007E118(u8* p) {
    fn_8006B774(*(void**)(p + 0xc));
}

s32 fn_8007E264(f32* p) {
    *p = 0.0f;
    return 1;
}

void fn_8007E678(s32 a, u32* b) {
    b[0] |= 0x800;
    b[2] = 0x800;
}

s32 fn_8007EB74(s32 i) {
    s32 r = 0;
    Tk* t = lbl_80309700[i];
    if (t != 0) {
        r = t->work->x3c;
    }
    return r;
}

s16 fn_8007FCF0(s8 i) {
    u8* a = fn_80021658(i);
    u8* b = *(u8**)(*(u8**)(a + 0x24) + 0x4c);
    return *(s16*)(b + 6);
}

void fn_80081134(s16 i, u32 v) {
    s32 off = i * 16;
    *(u32*)(lbl_80309730 + off) = v;
    (lbl_80309730 + off)[9] = 0;
    lbl_80302BF0[i] = 0;
}

void fn_8008210C(void) {
    fn_80081FEC(lbl_80347334);
}

void fn_8008999C(void* a) {
    fn_80083BAC(a, 3);
}

s32 fn_8008A880(s32 i) {
    Chr* e = lbl_80309DE4[i];
    u32 f = e->x10;
    if (f & 0x20000) {
        e->x10 = f & ~0x20000;
        return 1;
    }
    return 0;
}
