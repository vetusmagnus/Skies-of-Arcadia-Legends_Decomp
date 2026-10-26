#include "types.h"

typedef struct SysA { u8 x0; u8 x1; u8 pad2[0xe]; u32 x10; s32 x14; s32 x18; } SysA;
typedef struct HolderA { u8 pad[0x24]; SysA* x24; } HolderA;
extern HolderA* lbl_80346F10;
typedef struct SysB { u8 pad0; s8 x1; u8 x2; u8 x3; u8 x4; u8 pad5; u8 x6; } SysB;
typedef struct HolderB { u8 pad[0x24]; SysB* x24; } HolderB;
extern HolderB* lbl_80346F20;
typedef struct SysC { u8 pad0[4]; u16 x4; u8 x6; u8 x7; u8 x8; u8 x9; u8 pad1[0x30 - 0xa]; u8 x30; u8 x31; u8 x32; } SysC;
typedef struct HolderC { u8 pad[0x24]; SysC* x24; } HolderC;
extern HolderC* lbl_80346F28;
typedef struct SysD { u8 pad0[4]; void* x4; } SysD;
typedef struct HolderD { u8 pad[0x24]; SysD* x24; } HolderD;
extern HolderD* lbl_80346F30;
extern void *lbl_803475A8;
void *fn_802268E8(void *a, void (*f)(void));
void *fn_801E1C7C(u32 n);
void fn_8012AF54(void);
void fn_8012B054(void);
extern void *lbl_80346F18;
extern f32 lbl_8034A418;
extern void *lbl_80346F04;
void *fn_801D68C4(void *a, u32 n);
void fn_8012F4F8(void);
typedef struct Fn8012C0D8Obj {
    u8 pad0[0x18];
    u8 flags;
    u8 state;
} Fn8012C0D8Obj;
void fn_8012C0D8(Fn8012C0D8Obj *p);
extern s32 fn_8012C174(Fn8012C0D8Obj *);
typedef struct Fn8012C744Obj {
    u8 pad0[0x18];
    u8 flags;
    u8 state;
} Fn8012C744Obj;
extern void fn_8012DFE0(void);
extern void fn_8012DB18(void);
extern s32 fn_8012C7E8(Fn8012C744Obj *);
typedef struct Fn8012E640Inner {
    s8 f0;
} Fn8012E640Inner;
typedef struct Fn8012E640Mgr {
    u8 pad0[0x24];
    Fn8012E640Inner *inner;
} Fn8012E640Mgr;
typedef struct Fn8012E640Obj {
    u8 pad0[0x18];
    u8 flags;
    u8 state;
} Fn8012E640Obj;
void fn_8012E640(Fn8012E640Obj *p);
extern void fn_8012F13C(void);
extern void fn_8012ECF8(void);
extern void fn_8012E970(void);
extern void fn_8012E6EC(void);

s32 fn_8012ADB4(void) { return lbl_80346F10->x24->x14; }

void fn_8012ADC4(void) {
    lbl_80346F10->x24->x14 = 1;
    lbl_80346F10->x24->x18 = 0;
}

void fn_8012ADE8(s32 v) {
    if (v > 0x63) {
        v = 0x63;
    }
    *(f32 *)(*(u8 **)((u8 *)lbl_80346F10 + 0x24) + 0x2c) = (f32)v;
}

void fn_8012AE28(s32 v) {
    if (v > 0x63) {
        v = 0x63;
    }
    *(f32 *)(*(u8 **)((u8 *)lbl_80346F10 + 0x24) + 0x28) = (f32)v;
}

void fn_8012AE68(s32 v) {
    if (v > 0x63) {
        v = 0x63;
    }
    *(f32 *)(*(u8 **)((u8 *)lbl_80346F10 + 0x24) + 0x24) = (f32)v;
}

void fn_8012AEA8(u32 v) { lbl_80346F10->x24->x10 = v; }

void fn_8012AEB8(u8 v) {
    if (lbl_80346F10 == 0) return;
    lbl_80346F10->x24->x1 = v;
}

void fn_8012AED0(u8 v) {
    if (lbl_80346F10 == 0) return;
    lbl_80346F10->x24->x0 = v;
}

void fn_8012C390(s32 v) {
    s32 m = ((u8 *)*(void **)((u8 *)lbl_80346F20 + 0x24))[0x67];
    if (m != 1) {
        *(f32 *)(*(u8 **)((u8 *)lbl_80346F20 + 0x24) + 0x54) = 1.0f;
        *(f32 *)(*(u8 **)((u8 *)lbl_80346F20 + 0x24) + 0x58) = 0.0f;
    }
    *(u8 *)(*(u8 **)((u8 *)lbl_80346F20 + 0x24) + 0x67) = (u8)v;
    *(u8 *)(*(u8 **)((u8 *)lbl_80346F20 + 0x24) + 0x68) = 0;
}

void fn_8012C454(u8 v) { lbl_80346F20->x24->x3 = v; }

void fn_8012C464(u8 v) { lbl_80346F20->x24->x2 = v; }

s32 fn_8012C5DC(void) {
    s8 v = lbl_80346F20->x24->x1;
    return v != 0;
}

void fn_8012C5FC(u8 v) {
    if (lbl_80346F20 == 0) return;
    lbl_80346F20->x24->x6 = v;
}

void fn_8012C614(s8 c) {
    if (lbl_80346F20 == 0) return;
    if (c == 9) {
        if (lbl_80346F20->x24->x1 != 8) return;
    }
    lbl_80346F20->x24->x1 = c;
}

void fn_8012E404(u8 v) { lbl_80346F28->x24->x31 = v; }

void fn_8012E414(u8 v) { lbl_80346F28->x24->x32 = v; }

void fn_8012E424(u8 v) { lbl_80346F28->x24->x30 = v; }

void fn_8012E560(u8 v) { lbl_80346F28->x24->x9 = v; }

void fn_8012E570(u8 v) { lbl_80346F28->x24->x8 = v; }

void fn_8012E580(u8 v) { lbl_80346F28->x24->x7 = v; }

void fn_8012E590(u8 v) { lbl_80346F28->x24->x6 = v; }

void fn_8012E5A0(u16 v) { lbl_80346F28->x24->x4 = v; }

void fn_8012F468(void* p) { lbl_80346F30->x24->x4 = p; }

void fn_8012AEF8(void) {
    *(void **)&lbl_80346F10 = fn_802268E8(lbl_803475A8, fn_8012B054);
    *(void **)((u8 *)lbl_80346F10 + 0x24) = fn_801E1C7C(0x48);
    fn_8012AF54();
    if (lbl_80346F10 != 0) {
        **(u8 **)((u8 *)lbl_80346F10 + 0x24) = 1;
    }
}

void fn_8012C070(void) {
    *(void **)&lbl_80346F18 = fn_802268E8(lbl_803475A8, (void (*)(void))fn_8012C0D8);
    *(void **)((u8 *)lbl_80346F18 + 0x24) = fn_801E1C7C(0xc);
    if (lbl_80346F18 != 0) {
        **(u8 **)((u8 *)lbl_80346F18 + 0x24) = 1;
    }
    *(f32 *)(*(u8 **)((u8 *)lbl_80346F18 + 0x24) + 4) = lbl_8034A418;
}

void fn_8012C3F0(s8 v) {
    void *r;
    *(s8 *)(*(u8 **)((u8 *)lbl_80346F20 + 0x24) + 4) = v;
    if (*(s8 *)(*(u8 **)((u8 *)lbl_80346F20 + 0x24) + 4) == 0) {
        r = fn_801D68C4(lbl_80346F04, 0x8c);
    } else {
        r = fn_801D68C4(lbl_80346F04, 0x8d);
    }
    *(void **)(*(u8 **)((u8 *)lbl_80346F20 + 0x28) + 0x18) = r;
}

void fn_8012E434(u8 *src) {
    *(u8 *)(*(u8 **)((u8 *)lbl_80346F28 + 0x24) + 0x2a) = src[0];
    *(u8 *)(*(u8 **)((u8 *)lbl_80346F28 + 0x24) + 0x2b) = src[1];
    *(u8 *)(*(u8 **)((u8 *)lbl_80346F28 + 0x24) + 0x2c) = src[2];
    *(u8 *)(*(u8 **)((u8 *)lbl_80346F28 + 0x24) + 0x2d) = src[3];
    *(u8 *)(*(u8 **)((u8 *)lbl_80346F28 + 0x24) + 0x2e) = src[4];
    *(u8 *)(*(u8 **)((u8 *)lbl_80346F28 + 0x24) + 0x2f) = src[5];
}

void fn_8012E498(u8 *src) {
    *(u8 *)(*(u8 **)((u8 *)lbl_80346F28 + 0x24) + 0x24) = src[0];
    *(u8 *)(*(u8 **)((u8 *)lbl_80346F28 + 0x24) + 0x25) = src[1];
    *(u8 *)(*(u8 **)((u8 *)lbl_80346F28 + 0x24) + 0x26) = src[2];
    *(u8 *)(*(u8 **)((u8 *)lbl_80346F28 + 0x24) + 0x27) = src[3];
    *(u8 *)(*(u8 **)((u8 *)lbl_80346F28 + 0x24) + 0x28) = src[4];
    *(u8 *)(*(u8 **)((u8 *)lbl_80346F28 + 0x24) + 0x29) = src[5];
}

void fn_8012E4FC(u32 *src) {
    *(u32 *)(*(u8 **)((u8 *)lbl_80346F28 + 0x24) + 0xc) = src[0];
    *(u32 *)(*(u8 **)((u8 *)lbl_80346F28 + 0x24) + 0x10) = src[1];
    *(u32 *)(*(u8 **)((u8 *)lbl_80346F28 + 0x24) + 0x14) = src[2];
    *(u32 *)(*(u8 **)((u8 *)lbl_80346F28 + 0x24) + 0x18) = src[3];
    *(u32 *)(*(u8 **)((u8 *)lbl_80346F28 + 0x24) + 0x1c) = src[4];
    *(u32 *)(*(u8 **)((u8 *)lbl_80346F28 + 0x24) + 0x20) = src[5];
}

void fn_8012E5E8(void) {
    *(void **)&lbl_80346F28 = fn_802268E8(lbl_803475A8, (void (*)(void))fn_8012E640);
    *(void **)((u8 *)lbl_80346F28 + 0x24) = fn_801E1C7C(0x38);
    if (lbl_80346F28 != 0) {
        **(u8 **)((u8 *)lbl_80346F28 + 0x24) = 1;
    }
}

void fn_8012F4A0(void) {
    *(void **)&lbl_80346F30 = fn_802268E8(lbl_803475A8, fn_8012F4F8);
    *(void **)((u8 *)lbl_80346F30 + 0x24) = fn_801E1C7C(0x8);
    if (lbl_80346F30 != 0) {
        **(u8 **)((u8 *)lbl_80346F30 + 0x24) = 1;
    }
}

void fn_8012C0D8(Fn8012C0D8Obj *p) {
    switch (p->state) {
    case 0x0:
    case 0xfe:
        p->state = 1;
        break;
    case 0x1:
        if (fn_8012C174(p) == 0) {
            p->state = 2;
        }
        break;
    case 0x2:
        p->state = 0xff;
        break;
    case 0xff:
        p->flags |= 0x40;
        break;
    }
}

void fn_8012C744(Fn8012C744Obj *p) {
    switch (p->state) {
    case 0x0:
    case 0xfe:
        fn_8012DFE0();
        fn_8012DB18();
        p->state = 1;
        break;
    case 0x1:
        if (fn_8012C7E8(p) == 0) {
            p->state = 2;
        }
        break;
    case 0x2:
        p->state = 0xff;
        break;
    case 0xff:
        p->flags |= 0x40;
        break;
    }
}

void fn_8012E640(Fn8012E640Obj *p) {
    switch (p->state) {
    case 0x0:
    case 0xfe:
        fn_8012F13C();
        p->state = 1;
        break;
    case 0x1:
        if (((Fn8012E640Mgr *)lbl_80346F28)->inner->f0 == 0) {
            fn_8012ECF8();
            fn_8012E970();
            fn_8012E6EC();
        }
        break;
    case 0x2:
        p->state = 0xff;
        break;
    case 0xff:
        p->flags |= 0x40;
        break;
    }
}
