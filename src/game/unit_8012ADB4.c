#include "types.h"
#include "game/text.h"
#include "ninja.h"
typedef struct {
    s8 x0;
    s8 x1;
    u8 pad2[2];
    f32 f4;
    f32 f8;
    s32 xc;
    s32 x10;
    s32 x14;
    s32 x18;
    f32 f1c;
    s32 x20;
    f32 f24;
    f32 f28;
    f32 f2c;
    s32 x30;
    f32 f34;
    s32 x38;
    f32 f3c;
    f32 f40;
    s8 x44;
} SysA;
typedef struct {
    u8 pad0[0x14];
    f32 f14;
    f32 f18;
} Pos;
typedef struct {
    Pos *pos;
} PosHolder;
typedef struct {
    u8 pad[0x24];
    SysA *x24;
    union {
        PosHolder *x28;
        void **x28v;
    };
} HolderA;
extern HolderA *lbl_80346F10;
typedef struct {
    u8 pad0;
    s8 x1;
    u8 x2;
    u8 x3;
    u8 x4;
    u8 pad5;
    s8 x6;
    u8 pad7[0x54 - 7];
    f32 f54;
    f32 f58;
    u8 x5c;
    u8 x5d;
} SysB;
typedef struct {
    u8 pad[0x24];
    SysB *x24;
    void **x28;
} HolderB;
extern HolderB *lbl_80346F20;
typedef struct SysC { u8 pad0[4]; u16 x4; u8 x6; u8 x7; u8 x8; u8 x9; u8 pad1[0x30 - 0xa]; u8 x30; u8 x31; u8 x32; } SysC;
typedef struct HolderC { u8 pad[0x24]; SysC* x24; } HolderC;
extern HolderC* lbl_80346F28;
typedef struct {
    s8 x0;
    u8 pad1;
    s8 x2;
    u8 pad3;
    void *x4;
} SysD;
typedef struct {
    u8 pad[0x24];
    SysD *x24;
    void **x28;
} HolderD;
extern HolderD *lbl_80346F30;
typedef struct {
    u8 pad0[0x18];
    u8 flags;
    u8 state;
} Obj;
extern void *lbl_803475A8;
void *fn_802268E8(void *a, void *f);
void *fn_801E1C7C(s32 n);
void *fn_801D68C4(void *a, u32 n);
void fn_8012AF54(void);
void fn_8012B054(Obj* o);
extern void *lbl_80346F18;
extern f32 lbl_8034A418;
extern void *lbl_80346F04;
void fn_8012F4F8(Obj *o);
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
void fn_8012B308(s8 n);
extern void fn_8012BD34(void);
extern void fn_8012B47C(void);
extern void fn_8012F61C(void);
typedef struct {
    u8 pad0[4];
    u32 x4;
    u8 pad8[0x14 - 8];
    f32 f14;
    f32 f18;
} Spr;
typedef struct {
    Spr* obj; /* 0x00 */
    f32 x;    /* 0x04 */
    f32 y;    /* 0x08 */
    s32 z0;   /* 0x0C */
    s32 z1;   /* 0x10 */
    f32 one;  /* 0x14 */
    f32 w;    /* 0x18 */
} Req;
typedef struct {
    s16 x0;
    s16 x2;
    s8 cnt;    /* 0x04 */
    u8 pad5[3];
    f32 f8;
    f32 fc;
    u32 x10;
} Num;
extern Spr* fn_8012BC48(s8 digit);
extern void fn_8012A9A8(Req* r);
typedef struct {
    u8 pad0[4];
    s8 x4;
    u8 x5;
    u8 pad6[0x5F - 6];
    s8 st[8]; /* 0x5F */
} SysB_8012CE60;
typedef struct {
    u8 pad[0x24];
    SysB_8012CE60* x24;
    void** x28;
} HolderB_8012CE60;
extern void* fn_801D68C4(void* a, u32 n);
extern void fn_801D4954(void* p);
typedef struct {
    u8 pad[0x28];
    void** x28;
} Holder;
extern void* fn_801E1C7C(s32 n);
extern void fn_8012F2EC(void);
typedef struct {
    u8 pad0[2];
    u8 x2;
    u8 pad3;
    u16 x4;
    u8 x6;
    u8 x7;
    u8 x8;
    u8 x9;
    u8 padA[2];
    s32 xc;
    s32 x10;
    s32 x14;
    s32 x18;
    s32 x1c;
    s32 x20;
    s8 a[6];      /* 0x24 */
    u8 b[6];      /* 0x2A */
    u8 pad30;
    u8 x31;
    u8 x32;
    s8 x33;
    f32 f34;
} SysC_8012F2EC;
typedef struct {
    u8 pad[0x24];
    SysC_8012F2EC* x24;
} HolderC_8012F2EC;
typedef struct {
    u8 pad0[4];
    f32 f4;
    f32 f8;
} SysA_8012B308;
typedef struct {
    Pos* pos;
} PosHolder_8012B308;
typedef struct {
    u8 pad[0x24];
    SysA_8012B308* x24;
    PosHolder_8012B308* x28;
} HolderA_8012B308;
extern void njRotate(NJS_MATRIX m, NJS_VECTOR* axis, Angle a);
/* Returns the signed byte at +4 of the object held at lbl_80346F20->+0x24.
 * Returning int (not s8) from an s8 field gives `lbz r3` / `extsb r3,r3`. */
typedef signed char s8;
typedef struct Sub_8012C3DC { char pad0[4]; s8 b4; } Sub_8012C3DC;
typedef struct Holder_8012C3DC { char pad0[0x24]; Sub_8012C3DC* sub; } Holder_8012C3DC;
typedef struct SysB_8012C474 {
    u8 pad0[0x30];
    f32 alpha[8];
    u8 pad50[0x5e - 0x50];
    s8 mask;
} SysB_8012C474;
typedef struct HolderB_8012C474 {
    u8 pad[0x24];
    SysB_8012C474 *x24;
} HolderB_8012C474;
typedef struct {
    u8 x0;
    u8 x1;
    u8 pad2[4];
    s8 x6;
    u8 pad7[0x49];
    s32 x50;
    f32 x54;
    f32 x58;
    u8 x5c;
    u8 x5d;
    u8 pad5e[0xe];
} Work_8012C670;
typedef struct {
    u8 pad0[0x24];
    Work_8012C670* work;
} Task_8012C670;
typedef struct {
    u8 pad0[4];
    s8 x4;
    u8 x5;
    u8 pad6[0x50 - 6];
    s32 mode; /* 0x50 */
    u8 pad54[0x5F - 0x54];
    s8 st[8]; /* 0x5F */
} SysB_8012CFC8;
typedef struct {
    u8 pad[0x24];
    SysB_8012CFC8* x24;
    void** x28;
} HolderB_8012CFC8;
extern void* fn_801D497C(void* p);
typedef struct {
    u8 pad0[4];
    s8 b4;
    u8 b5;
    u8 pad6[0x50 - 6];
    s32 mode;      /* 0x50 */
} Sys;
typedef struct {
    u8 pad0[0x24];
    Sys *x24;
    void **x28;
} Holder_8012D0F4;

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

void fn_8012AEE8(void) {
    ((u8*)lbl_80346F10)[0x19] = 2;
}

void fn_8012C048(u8 v) {
    if (lbl_80346F18 == 0) return;
    (*(u8**)((u8*)lbl_80346F18 + 0x24))[1] = v;
}

void fn_8012C060(void) {
    ((u8*)lbl_80346F18)[0x19] = 2;
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

void fn_8012C648(u8 v) {
    if (lbl_80346F20 == 0) return;
    (*(u8**)((u8*)lbl_80346F20 + 0x24))[0] = v;
}

void fn_8012C660(void) {
    ((u8*)lbl_80346F20)[0x19] = 2;
}

void fn_8012E404(u8 v) { lbl_80346F28->x24->x31 = v; }

void fn_8012E414(u8 v) { lbl_80346F28->x24->x32 = v; }

void fn_8012E424(u8 v) { lbl_80346F28->x24->x30 = v; }

void fn_8012E560(u8 v) { lbl_80346F28->x24->x9 = v; }

void fn_8012E570(u8 v) { lbl_80346F28->x24->x8 = v; }

void fn_8012E580(u8 v) { lbl_80346F28->x24->x7 = v; }

void fn_8012E590(u8 v) { lbl_80346F28->x24->x6 = v; }

void fn_8012E5A0(u16 v) { lbl_80346F28->x24->x4 = v; }

void fn_8012E5B0(u8 v) { (*(u8**)((u8*)lbl_80346F28 + 0x24))[2] = v; }

void fn_8012E5C0(u8 v) {
    if (lbl_80346F28 == 0) return;
    (*(u8**)((u8*)lbl_80346F28 + 0x24))[0] = v;
}

void fn_8012E5D8(void) {
    ((u8*)lbl_80346F28)[0x19] = 2;
}

void fn_8012F458(u8 v) { lbl_80346F30->x24->x2 = v; }

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

void fn_8012F478(u8 v) {
    if (lbl_80346F30 == 0) return;
    lbl_80346F30->x24->x0 = v;
}

void fn_8012F490(void) {
    ((u8*)lbl_80346F30)[0x19] = 2;
}

void fn_8012F4A0(void) {
    *(void **)&lbl_80346F30 = fn_802268E8(lbl_803475A8, (void (*)(void))fn_8012F4F8);
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

void fn_8012AF54(void)
{
    lbl_80346F10->x24->x0 = 0;
    lbl_80346F10->x24->x1 = 1;
    lbl_80346F10->x24->f4 = 0.0f;
    lbl_80346F10->x24->f8 = 0.0f;
    lbl_80346F10->x24->xc = 0;
    lbl_80346F10->x24->x10 = 3;
    lbl_80346F10->x24->x14 = 0;
    lbl_80346F10->x24->x18 = 0;
    lbl_80346F10->x24->f1c = 0.0f;
    lbl_80346F10->x24->x20 = 0;
    lbl_80346F10->x24->f24 = 0.0f;
    lbl_80346F10->x24->f28 = 0.0f;
    lbl_80346F10->x24->f2c = 0.0f;
    lbl_80346F10->x24->x30 = 0;
    lbl_80346F10->x24->f34 = 0.0f;
    lbl_80346F10->x24->x38 = 0;
    lbl_80346F10->x24->f3c = 0.0f;
    lbl_80346F10->x24->f40 = 1.0f;
    lbl_80346F10->x24->x44 = -1;
}

s32 fn_8012B1D8(void)
{
    switch (lbl_80346F10->x24->x1) {
    case 0:
        lbl_80346F10->x24->xc = 0;
        break;
    case 1:
        lbl_80346F10->x28->pos->f14 = 84.0f;
        lbl_80346F10->x28->pos->f18 = 37.0f;
        lbl_80346F10->x24->f4 = 0.0f;
        lbl_80346F10->x24->f8 = 0.0f;
        if (lbl_80346F10 != NULL) {
            lbl_80346F10->x24->x1 = 0;
        }
        lbl_80346F10->x24->xc = 0;
        break;
    case 2:
        lbl_80346F10->x24->xc++;
        fn_8012B308(-1);
        if (lbl_80346F10->x24->xc >= 3) {
            if (lbl_80346F10 != NULL) {
                lbl_80346F10->x24->x1 = 0;
            }
            lbl_80346F10->x24->xc = 0;
        }
        break;
    }
    fn_8012BD34();
    if (lbl_80346F10->x24->x0 == 0) {
        fn_8012B47C();
    }
    return 1;
}

void fn_8012C4E8(void)
{
    fn_8012DB18();
    if (lbl_80346F20 != NULL) {
        lbl_80346F20->x24->x6 = -1;
    }
    lbl_80346F20->x24->f54 = 1.0f;
    lbl_80346F20->x24->f58 = 0.0f;
    lbl_80346F20->x24->x5c = 3;
    lbl_80346F20->x24->x5d = 3;
    *(s32 *)((u8 *)lbl_80346F20->x24 + 0x50) = 0;
    lbl_80346F20->x28[0xc] = fn_801D68C4(lbl_80346F04, 0x14);
    lbl_80346F20->x28[0xd] = fn_801D68C4(lbl_80346F04, 0x14);
    lbl_80346F20->x28[0xe] = fn_801D68C4(lbl_80346F04, 0x2d);
    lbl_80346F20->x28[0xf] = fn_801D68C4(lbl_80346F04, 0x2d);
    *(f32 *)((u8 *)lbl_80346F20->x24 + 0xc) = 0.0f;
}

void fn_8012F4F8(Obj *o)
{
    switch (o->state) {
    case 0:
    case 0xfe:
        lbl_80346F30->x28 = fn_801E1C7C(4);
        lbl_80346F30->x28[0] = fn_801D68C4(lbl_80346F04, 0x35);
        lbl_80346F30->x24->x4 = NULL;
        lbl_80346F30->x24->x2 = 0;
        o->state = 1;
        break;
    case 1:
        if (lbl_80346F30->x24->x0 == 0) {
            fn_8012F61C();
            if (lbl_80346F30->x24->x4 != NULL) {
                TextPrint(0x20, (s8)(lbl_80346F30->x24->x2 == 1) * -100 + 0x18d, lbl_80346F30->x24->x4);
            }
        }
        break;
    case 2:
        o->state = 0xff;
        break;
    case 0xff:
        o->flags |= 0x40;
        break;
    }
}

void fn_8012BAA8(Num* n)
{
    Req r;
    s8 tens = n->cnt / 10;
    if (tens > 0) {
        r.obj = fn_8012BC48(tens);
        r.obj->f14 = (f32)n->x0;
        r.obj->f18 = (f32)n->x2;
        *(u32*)((u8*)r.obj->x4 + 0x14) = n->x10;
        r.x = n->f8;
        r.y = 0.0f;
        r.z0 = 0;
        r.z1 = 0;
        r.one = 1.0f;
        r.w = n->fc;
        fn_8012A9A8(&r);
    }
    r.obj = fn_8012BC48((s8)(n->cnt % 10));
    r.obj->f14 = (f32)(n->x0 + 0x10);
    r.obj->f18 = (f32)n->x2;
    *(u32*)((u8*)r.obj->x4 + 0x14) = n->x10;
    r.x = n->f8;
    r.y = 0.0f;
    r.z0 = 0;
    r.z1 = 0;
    r.one = 1.0f;
    r.w = n->fc;
    fn_8012A9A8(&r);
}

void fn_8012CE60(void)
{
    s32 i;
    for (i = 0; i < 8; i++) {
        if ((*(HolderB_8012CE60**)&lbl_80346F20)->x24->st[i] == 1) {
            void* r;
            fn_801D4954((*(HolderB_8012CE60**)&lbl_80346F20)->x28[i]);
            switch (i) {
            case 0:
                r = fn_801D68C4((*(void**)&lbl_80346F04), 0x10);
                break;
            case 1:
                r = fn_801D68C4((*(void**)&lbl_80346F04), 0xE);
                break;
            case 2:
                r = fn_801D68C4((*(void**)&lbl_80346F04), 0xC);
                break;
            case 3:
                r = fn_801D68C4((*(void**)&lbl_80346F04), 0xB);
                break;
            case 4:
                r = fn_801D68C4((*(void**)&lbl_80346F04), 0xF);
                break;
            case 5:
                r = fn_801D68C4((*(void**)&lbl_80346F04), 0xD);
                break;
            case 6:
                if ((*(HolderB_8012CE60**)&lbl_80346F20)->x24->x4 == 0)
                    r = fn_801D68C4((*(void**)&lbl_80346F04), 0x8C);
                else
                    r = fn_801D68C4((*(void**)&lbl_80346F04), 0x8D);
                break;
            case 7:
                r = fn_801D68C4((*(void**)&lbl_80346F04), 0x11);
                break;
            default:
                r = fn_801D68C4((*(void**)&lbl_80346F04), 0x11);
                break;
            }
            (*(HolderB_8012CE60**)&lbl_80346F20)->x28[i] = r;
            fn_8012DB18();
        }
    }
    (*(HolderB_8012CE60**)&lbl_80346F20)->x24->x5 = 1;
}

void fn_8012F13C(void)
{
    (*(Holder**)&lbl_80346F28)->x28 = fn_801E1C7C(0x40);
    (*(Holder**)&lbl_80346F28)->x28[0] = fn_801D68C4((*(void**)&lbl_80346F04), 0x38);
    (*(Holder**)&lbl_80346F28)->x28[1] = fn_801D68C4((*(void**)&lbl_80346F04), 0x39);
    (*(Holder**)&lbl_80346F28)->x28[2] = fn_801D68C4((*(void**)&lbl_80346F04), 0x3A);
    (*(Holder**)&lbl_80346F28)->x28[3] = fn_801D68C4((*(void**)&lbl_80346F04), 0x3B);
    (*(Holder**)&lbl_80346F28)->x28[4] = fn_801D68C4((*(void**)&lbl_80346F04), 0x3C);
    (*(Holder**)&lbl_80346F28)->x28[5] = fn_801D68C4((*(void**)&lbl_80346F04), 0x3D);
    (*(Holder**)&lbl_80346F28)->x28[6] = fn_801D68C4((*(void**)&lbl_80346F04), 0x3E);
    (*(Holder**)&lbl_80346F28)->x28[7] = fn_801D68C4((*(void**)&lbl_80346F04), 0x3F);
    (*(Holder**)&lbl_80346F28)->x28[8] = fn_801D68C4((*(void**)&lbl_80346F04), 0x20);
    (*(Holder**)&lbl_80346F28)->x28[9] = fn_801D68C4((*(void**)&lbl_80346F04), 0x1F);
    (*(Holder**)&lbl_80346F28)->x28[10] = fn_801D68C4((*(void**)&lbl_80346F04), 0x20);
    (*(Holder**)&lbl_80346F28)->x28[11] = fn_801D68C4((*(void**)&lbl_80346F04), 0x40);
    (*(Holder**)&lbl_80346F28)->x28[12] = fn_801D68C4((*(void**)&lbl_80346F04), 0x34);
    (*(Holder**)&lbl_80346F28)->x28[13] = fn_801D68C4((*(void**)&lbl_80346F04), 0x36);
    (*(Holder**)&lbl_80346F28)->x28[14] = fn_801D68C4((*(void**)&lbl_80346F04), 0x37);
    (*(Holder**)&lbl_80346F28)->x28[15] = fn_801D68C4((*(void**)&lbl_80346F04), 0x48);
    fn_8012F2EC();
}

void fn_8012F2EC(void)
{
    (*(HolderC_8012F2EC**)&lbl_80346F28)->x24->x2 = 0;
    (*(HolderC_8012F2EC**)&lbl_80346F28)->x24->x4 = 0x3F;
    (*(HolderC_8012F2EC**)&lbl_80346F28)->x24->x6 = 0;
    (*(HolderC_8012F2EC**)&lbl_80346F28)->x24->x7 = 1;
    (*(HolderC_8012F2EC**)&lbl_80346F28)->x24->x8 = 0;
    (*(HolderC_8012F2EC**)&lbl_80346F28)->x24->x9 = 0;
    (*(HolderC_8012F2EC**)&lbl_80346F28)->x24->xc = 0;
    (*(HolderC_8012F2EC**)&lbl_80346F28)->x24->a[0] = -1;
    (*(HolderC_8012F2EC**)&lbl_80346F28)->x24->b[0] = 7;
    (*(HolderC_8012F2EC**)&lbl_80346F28)->x24->x10 = 0;
    (*(HolderC_8012F2EC**)&lbl_80346F28)->x24->a[1] = -1;
    (*(HolderC_8012F2EC**)&lbl_80346F28)->x24->b[1] = 7;
    (*(HolderC_8012F2EC**)&lbl_80346F28)->x24->x14 = 0;
    (*(HolderC_8012F2EC**)&lbl_80346F28)->x24->a[2] = -1;
    (*(HolderC_8012F2EC**)&lbl_80346F28)->x24->b[2] = 7;
    (*(HolderC_8012F2EC**)&lbl_80346F28)->x24->x18 = 0;
    (*(HolderC_8012F2EC**)&lbl_80346F28)->x24->a[3] = -1;
    (*(HolderC_8012F2EC**)&lbl_80346F28)->x24->b[3] = 7;
    (*(HolderC_8012F2EC**)&lbl_80346F28)->x24->x1c = 0;
    (*(HolderC_8012F2EC**)&lbl_80346F28)->x24->a[4] = -1;
    (*(HolderC_8012F2EC**)&lbl_80346F28)->x24->b[4] = 7;
    (*(HolderC_8012F2EC**)&lbl_80346F28)->x24->x20 = 0;
    (*(HolderC_8012F2EC**)&lbl_80346F28)->x24->a[5] = -1;
    (*(HolderC_8012F2EC**)&lbl_80346F28)->x24->b[5] = 7;
    (*(HolderC_8012F2EC**)&lbl_80346F28)->x24->x31 = 0;
    (*(HolderC_8012F2EC**)&lbl_80346F28)->x24->x32 = 0;
    (*(HolderC_8012F2EC**)&lbl_80346F28)->x24->x33 = -1;
    (*(HolderC_8012F2EC**)&lbl_80346F28)->x24->f34 = 1.0f;
}

void fn_8012B308(s8 n)
{
    NJS_MATRIX m;
    NJS_VECTOR in;
    NJS_VECTOR out;
    NJS_VECTOR axis;
    Pos* pos;
    f32 d;

    d = (-43.5f * (f32)n) / 3.0f;
    lbl_80346F10->x24->f4 += d;
    axis.x = 0.0f;
    axis.y = 0.0f;
    axis.z = 1.0f;
    pos = lbl_80346F10->x28->pos;
    in.x = (19.0f + pos->f14) - 51.0f;
    in.y = (19.0f + pos->f18) - 57.0f;
    in.z = 0.0f;
    njUnitMatrix(m);
    njRotate(m, &axis, (Angle)(182.04445f * d));
    njCalcPoint(m, &in, &out);
    pos->f14 = 51.0f + (out.x - 19.0f);
    pos->f18 = 57.0f + (out.y - 19.0f);
    lbl_80346F10->x24->f8 = (f32)(s32)(182.04445f * (-40.466667f + lbl_80346F10->x24->f4));
}

void fn_8012B054(Obj* o)
{
    switch (o->state) {
    case 0xFE:
    case 0:
        lbl_80346F10->x28v = fn_801E1C7C(0x24);
        lbl_80346F10->x28v[0] = fn_801D68C4(lbl_80346F04, 8);
        lbl_80346F10->x28v[1] = fn_801D68C4(lbl_80346F04, 0);
        lbl_80346F10->x28v[2] = fn_801D68C4(lbl_80346F04, 1);
        lbl_80346F10->x28v[3] = fn_801D68C4(lbl_80346F04, 2);
        lbl_80346F10->x28v[4] = fn_801D68C4(lbl_80346F04, 3);
        lbl_80346F10->x28v[5] = fn_801D68C4(lbl_80346F04, 4);
        lbl_80346F10->x28v[6] = fn_801D68C4(lbl_80346F04, 5);
        lbl_80346F10->x28v[7] = fn_801D68C4(lbl_80346F04, 6);
        lbl_80346F10->x28v[8] = fn_801D68C4(lbl_80346F04, 7);
        o->state = 1;
        break;
    case 1:
        if (fn_8012B1D8() == 0)
            o->state = 2;
        break;
    case 2:
        o->state = 0xFF;
        break;
    case 0xFF:
        o->flags |= 0x40;
        break;
    }
}

int fn_8012C3DC(void) {
    return (*(Holder_8012C3DC**)&lbl_80346F20)->sub->b4;
}

void fn_8012C474(s8 mask) {
    s8 i;

    (*(HolderB_8012C474 **)&lbl_80346F20)->x24->mask = mask;
    for (i = 0; i < 8; i++) {
        if (mask & (1 << i)) {
            (*(HolderB_8012C474 **)&lbl_80346F20)->x24->alpha[i] = 1.0f;
        } else {
            (*(HolderB_8012C474 **)&lbl_80346F20)->x24->alpha[i] = 0.5f;
        }
    }
}

void fn_8012C670(void)
{
    (*(Task_8012C670**)&lbl_80346F20) = ((Task_8012C670*)fn_802268E8((void *)((*(void**)&lbl_803475A8)), (void *)(fn_8012C744)));
    (*(Task_8012C670**)&lbl_80346F20)->work = fn_801E1C7C(0x6c);
    if ((*(Task_8012C670**)&lbl_80346F20) != NULL) {
        (*(Task_8012C670**)&lbl_80346F20)->work->x0 = 1;
    }
    if ((*(Task_8012C670**)&lbl_80346F20) != NULL) {
        (*(Task_8012C670**)&lbl_80346F20)->work->x1 = 0;
    }
    if ((*(Task_8012C670**)&lbl_80346F20) != NULL) {
        (*(Task_8012C670**)&lbl_80346F20)->work->x6 = -1;
    }
    (*(Task_8012C670**)&lbl_80346F20)->work->x54 = 1.0f;
    (*(Task_8012C670**)&lbl_80346F20)->work->x58 = 0.0f;
    (*(Task_8012C670**)&lbl_80346F20)->work->x5c = 3;
    (*(Task_8012C670**)&lbl_80346F20)->work->x5d = 3;
    (*(Task_8012C670**)&lbl_80346F20)->work->x50 = 0;
}

void fn_8012CFC8(void)
{
    s32 i;

    for (i = 0; i < 8; i++) {
        if ((*(HolderB_8012CFC8**)&lbl_80346F20)->x24->st[i] == 1) {
            switch ((*(HolderB_8012CFC8**)&lbl_80346F20)->x24->mode) {
            case 0:
                (*(HolderB_8012CFC8**)&lbl_80346F20)->x24->x5 = 0;
                (*(HolderB_8012CFC8**)&lbl_80346F20)->x28[i] = fn_801D497C(fn_801D68C4((*(void**)&lbl_80346F04), 0x12));
                fn_8012DB18();
                break;
            case 1:
                fn_801D4954((*(HolderB_8012CFC8**)&lbl_80346F20)->x28[i]);
                (*(HolderB_8012CFC8**)&lbl_80346F20)->x28[i] = fn_801D497C(fn_801D68C4((*(void**)&lbl_80346F04), 0x13));
                fn_8012DB18();
                break;
            case 2:
                fn_801D4954((*(HolderB_8012CFC8**)&lbl_80346F20)->x28[i]);
                (*(HolderB_8012CFC8**)&lbl_80346F20)->x28[i] = fn_801D497C(fn_801D68C4((*(void**)&lbl_80346F04), 8));
                fn_8012DB18();
                break;
            }
        }
    }
    if ((*(HolderB_8012CFC8**)&lbl_80346F20)->x24->mode == 2) {
        (*(HolderB_8012CFC8**)&lbl_80346F20)->x24->mode = -1;
    }
}

Spr* fn_8012BC48(s8 n) {
    switch (n) {
    case 0:
        fn_801D68C4(lbl_80346F04, 0x21);
        break;
    case 1:
        fn_801D68C4(lbl_80346F04, 0x22);
        break;
    case 2:
        fn_801D68C4(lbl_80346F04, 0x23);
        break;
    case 3:
        fn_801D68C4(lbl_80346F04, 0x24);
        break;
    case 4:
        fn_801D68C4(lbl_80346F04, 0x25);
        break;
    case 5:
        fn_801D68C4(lbl_80346F04, 0x26);
        break;
    case 6:
        fn_801D68C4(lbl_80346F04, 0x27);
        break;
    case 7:
        fn_801D68C4(lbl_80346F04, 0x28);
        break;
    case 8:
        fn_801D68C4(lbl_80346F04, 0x29);
        break;
    case 9:
        fn_801D68C4(lbl_80346F04, 0x2a);
        break;
    default:
        fn_801D68C4(lbl_80346F04, 0x21);
        break;
    }
}

void fn_8012D0F4(void) {
    void *p;
    switch ((*(Holder_8012D0F4 **)&lbl_80346F20)->x24->mode) {
    case 0:
        (*(Holder_8012D0F4 **)&lbl_80346F20)->x24->b5 = 0;
        (*(Holder_8012D0F4 **)&lbl_80346F20)->x28[0] = fn_801D497C((void *)(fn_801D68C4((void *)(lbl_80346F04), 8)));
        (*(Holder_8012D0F4 **)&lbl_80346F20)->x28[1] = fn_801D497C((void *)(fn_801D68C4((void *)(lbl_80346F04), 8)));
        (*(Holder_8012D0F4 **)&lbl_80346F20)->x28[2] = fn_801D497C((void *)(fn_801D68C4((void *)(lbl_80346F04), 8)));
        (*(Holder_8012D0F4 **)&lbl_80346F20)->x28[3] = fn_801D497C((void *)(fn_801D68C4((void *)(lbl_80346F04), 8)));
        (*(Holder_8012D0F4 **)&lbl_80346F20)->x28[4] = fn_801D497C((void *)(fn_801D68C4((void *)(lbl_80346F04), 8)));
        (*(Holder_8012D0F4 **)&lbl_80346F20)->x28[5] = fn_801D497C((void *)(fn_801D68C4((void *)(lbl_80346F04), 8)));
        (*(Holder_8012D0F4 **)&lbl_80346F20)->x28[6] = fn_801D497C((void *)(fn_801D68C4((void *)(lbl_80346F04), 8)));
        (*(Holder_8012D0F4 **)&lbl_80346F20)->x28[7] = fn_801D497C((void *)(fn_801D68C4((void *)(lbl_80346F04), 8)));
        fn_8012DB18();
        break;
    case 1:
        fn_801D4954((void *)((*(Holder_8012D0F4 **)&lbl_80346F20)->x28[0]));
        fn_801D4954((void *)((*(Holder_8012D0F4 **)&lbl_80346F20)->x28[1]));
        fn_801D4954((void *)((*(Holder_8012D0F4 **)&lbl_80346F20)->x28[2]));
        fn_801D4954((void *)((*(Holder_8012D0F4 **)&lbl_80346F20)->x28[3]));
        fn_801D4954((void *)((*(Holder_8012D0F4 **)&lbl_80346F20)->x28[4]));
        fn_801D4954((void *)((*(Holder_8012D0F4 **)&lbl_80346F20)->x28[5]));
        fn_801D4954((void *)((*(Holder_8012D0F4 **)&lbl_80346F20)->x28[6]));
        fn_801D4954((void *)((*(Holder_8012D0F4 **)&lbl_80346F20)->x28[7]));
        (*(Holder_8012D0F4 **)&lbl_80346F20)->x28[0] = fn_801D497C((void *)(fn_801D68C4((void *)(lbl_80346F04), 0x12)));
        (*(Holder_8012D0F4 **)&lbl_80346F20)->x28[1] = fn_801D497C((void *)(fn_801D68C4((void *)(lbl_80346F04), 0x12)));
        (*(Holder_8012D0F4 **)&lbl_80346F20)->x28[2] = fn_801D497C((void *)(fn_801D68C4((void *)(lbl_80346F04), 0x12)));
        (*(Holder_8012D0F4 **)&lbl_80346F20)->x28[3] = fn_801D497C((void *)(fn_801D68C4((void *)(lbl_80346F04), 0x12)));
        (*(Holder_8012D0F4 **)&lbl_80346F20)->x28[4] = fn_801D497C((void *)(fn_801D68C4((void *)(lbl_80346F04), 0x12)));
        (*(Holder_8012D0F4 **)&lbl_80346F20)->x28[5] = fn_801D497C((void *)(fn_801D68C4((void *)(lbl_80346F04), 0x12)));
        (*(Holder_8012D0F4 **)&lbl_80346F20)->x28[6] = fn_801D497C((void *)(fn_801D68C4((void *)(lbl_80346F04), 0x12)));
        (*(Holder_8012D0F4 **)&lbl_80346F20)->x28[7] = fn_801D497C((void *)(fn_801D68C4((void *)(lbl_80346F04), 0x12)));
        fn_8012DB18();
        break;
    case 2:
        fn_801D4954((void *)((*(Holder_8012D0F4 **)&lbl_80346F20)->x28[0]));
        fn_801D4954((void *)((*(Holder_8012D0F4 **)&lbl_80346F20)->x28[1]));
        fn_801D4954((void *)((*(Holder_8012D0F4 **)&lbl_80346F20)->x28[2]));
        fn_801D4954((void *)((*(Holder_8012D0F4 **)&lbl_80346F20)->x28[3]));
        fn_801D4954((void *)((*(Holder_8012D0F4 **)&lbl_80346F20)->x28[4]));
        fn_801D4954((void *)((*(Holder_8012D0F4 **)&lbl_80346F20)->x28[5]));
        fn_801D4954((void *)((*(Holder_8012D0F4 **)&lbl_80346F20)->x28[6]));
        fn_801D4954((void *)((*(Holder_8012D0F4 **)&lbl_80346F20)->x28[7]));
        (*(Holder_8012D0F4 **)&lbl_80346F20)->x28[0] = fn_801D68C4((void *)(lbl_80346F04), 0x10);
        (*(Holder_8012D0F4 **)&lbl_80346F20)->x28[1] = fn_801D68C4((void *)(lbl_80346F04), 0xe);
        (*(Holder_8012D0F4 **)&lbl_80346F20)->x28[2] = fn_801D68C4((void *)(lbl_80346F04), 0xc);
        (*(Holder_8012D0F4 **)&lbl_80346F20)->x28[3] = fn_801D68C4((void *)(lbl_80346F04), 0xb);
        (*(Holder_8012D0F4 **)&lbl_80346F20)->x28[4] = fn_801D68C4((void *)(lbl_80346F04), 0xf);
        (*(Holder_8012D0F4 **)&lbl_80346F20)->x28[5] = fn_801D68C4((void *)(lbl_80346F04), 0xd);
        if ((*(Holder_8012D0F4 **)&lbl_80346F20)->x24->b4 == 0) {
            p = fn_801D68C4((void *)(lbl_80346F04), 0x8c);
        } else {
            p = fn_801D68C4((void *)(lbl_80346F04), 0x8d);
        }
        (*(Holder_8012D0F4 **)&lbl_80346F20)->x28[6] = p;
        (*(Holder_8012D0F4 **)&lbl_80346F20)->x28[7] = fn_801D68C4((void *)(lbl_80346F04), 0x11);
        fn_8012DB18();
        (*(Holder_8012D0F4 **)&lbl_80346F20)->x24->b5 = 1;
        break;
    }
}
