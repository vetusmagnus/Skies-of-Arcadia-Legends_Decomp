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
    u32 x30;                 /* colour */
    f32 f34;
    u32 x38;                 /* colour */
    f32 f3c;
    f32 f40;
    s8 x44;
} SysA;
typedef struct {
    u8 pad[0x24];
    SysA *x24;
    struct Spr **x28;
} HolderA;
extern HolderA *lbl_80346F10;
typedef struct {
    s8 x0;
    s8 x1;
    s8 x2;
    s8 x3;
    s8 x4;
    s8 x5;
    s8 x6;
    u8 pad7;
    f32 f8;        /* 0x08 */
    f32 fc;        /* 0x0C */
    f32 y[8];      /* 0x10 */
    f32 s[8];      /* 0x30 */
    s32 x50;
    f32 f54[2];    /* 0x54 */
    s8 x5c[2];     /* 0x5C */
    s8 x5e;        /* 0x5E */
    s8 x5f[8];     /* 0x5F */
    s8 x67;        /* 0x67 */
    s8 x68;        /* 0x68 */
} SysB;
typedef struct {
    u8 pad[0x24];
    SysB *x24;
    struct Spr **x28;
} HolderB;
extern HolderB *lbl_80346F20;
typedef struct SysC { u8 pad0[2]; s8 x2; u8 pad3; s16 x4; s8 x6; char x7; u8 x8; s8 x9; u8 padA[2]; char *name[6]; s8 value[6]; s8 kind[6]; s8 x30; char x31; s8 x32; s8 x33; f32 x34; } SysC;
typedef struct HolderC { u8 pad[0x24]; SysC* x24; struct Spr** x28; } HolderC;
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
typedef struct SysE {
    s8 x0;
    s8 x1;
    u8 pad2[2];
    f32 f4;
    s8 x8;
} SysE;
/* The task at lbl_80346F18 (fn_8012C0D8) and its 0xc-byte work. */
typedef struct HolderE {
    u8 pad[0x18];
    u8 flags;
    u8 state;
    u8 pad1a[0x24 - 0x1a];
    SysE *x24;
} HolderE;
extern HolderE *lbl_80346F18;
extern f32 lbl_8034A418;
extern void *lbl_80346F04;
void fn_8012F4F8(Obj *o);
void fn_8012C0D8(Obj *p);
extern s32 fn_8012C174(Obj *);
extern void fn_8012DFE0(void);
extern void fn_8012DB18(void);
extern s32 fn_8012C7E8(Obj *);
typedef struct Fn8012E640Inner {
    s8 f0;
} Fn8012E640Inner;
typedef struct Fn8012E640Mgr {
    u8 pad0[0x24];
    Fn8012E640Inner *inner;
} Fn8012E640Mgr;
void fn_8012E640(Obj *p);
extern void fn_8012F13C(void);
extern void fn_8012ECF8(void);
extern void fn_8012E970(void);
extern void fn_8012E6EC(void);
void fn_8012B308(s8 n);
extern void fn_8012BD34(void);
extern void fn_8012B47C(void);
extern void fn_8012F61C(void);
typedef struct SprColor {
    u8 pad0[4];
    f32 f4;
    u8 pad8[4];
    f32 fc;
    u8 pad10[4];
    u32 color;
} SprColor;
typedef struct Spr {
    u8 pad0[4];
    SprColor *x4;
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
    lbl_80346F18->x24->x1 = v;
}

void fn_8012C060(void) {
    lbl_80346F18->state = 2;
}

extern void fn_801CBA60(f32 a, f32 b);

s32 fn_8012C174(Obj *unused) {
    SysE *s = lbl_80346F18->x24;
    switch (s->x1) {
    case 0:
        break;
    case 0x12:
        s->f4 = 0.0f;
        lbl_80346F18->x24->x8 = 1;
        if (lbl_80346F18 != 0) {
            lbl_80346F18->x24->x1 = 0x14;
        }
        if (lbl_80346F18 != 0) {
            lbl_80346F18->x24->x0 = 0;
        }
        break;
    case 0x13:
        s->f4 = 0.4f;
        if (lbl_80346F18 != 0) {
            lbl_80346F18->x24->x1 = 0;
        }
        break;
    case 0x14:
        s->f4 = 0.04f * s->x8 + s->f4;
        switch (lbl_80346F18->x24->x8) {
        case 1:
            if (lbl_80346F18->x24->f4 >= 0.4f) {
                if (lbl_80346F18 != 0) {
                    lbl_80346F18->x24->x1 = 0x13;
                }
                lbl_80346F18->x24->f4 = 0.4f;
            }
            break;
        case -1:
            if (lbl_80346F18->x24->f4 <= 0.0f) {
                if (lbl_80346F18 != 0) {
                    lbl_80346F18->x24->x1 = 0x15;
                }
                lbl_80346F18->x24->f4 = 0.0f;
            }
            break;
        }
        break;
    case 0x15:
        s->f4 = 0.0f;
        if (lbl_80346F18 != 0) {
            lbl_80346F18->x24->x1 = 0;
        }
        if (lbl_80346F18 != 0) {
            lbl_80346F18->x24->x0 = 1;
        }
        break;
    case 0x16:
        s->f4 = 0.4f;
        lbl_80346F18->x24->x8 = -1;
        if (lbl_80346F18 != 0) {
            lbl_80346F18->x24->x1 = 0x14;
        }
        break;
    }
    if (lbl_80346F18->x24->x0 == 0) {
        fn_801CBA60(lbl_80346F18->x24->f4, -1.31f);
    }
    return 1;
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
    lbl_80346F20->x24->x0 = v;
}

void fn_8012C660(void) {
    ((u8*)lbl_80346F20)[0x19] = 2;
}

extern void fn_8012D508(u8 a);
extern void fn_8012D760(s8 a);
extern void fn_8012D0F4(void);
extern void fn_8012CFC8(void);
extern void fn_8012CE60(void);
extern void fn_8012CA4C(void);

s32 fn_8012C7E8(Obj *unused) {
    switch (lbl_80346F20->x24->x1) {
    case 0:
        lbl_80346F20->x24->x50 = 0;
        break;
    case 3:
        fn_8012D508(lbl_80346F20->x24->x6);
        if (lbl_80346F20 != 0) {
            lbl_80346F20->x24->x1 = 4;
        }
    case 4:
        lbl_80346F20->x24->x50++;
        fn_8012D760(lbl_80346F20->x24->x6);
        lbl_80346F20->x24->f54[0] -= 0.33333334f;
        lbl_80346F20->x24->f54[1] += 0.33333334f;
        if (lbl_80346F20->x24->x50 >= 3) {
            lbl_80346F20->x28[12] = lbl_80346F20->x28[13];
            lbl_80346F20->x28[14] = lbl_80346F20->x28[15];
            lbl_80346F20->x24->f54[0] = 1.0f;
            lbl_80346F20->x24->f54[1] = 0.0f;
            lbl_80346F20->x24->x5c[0] = lbl_80346F20->x24->x5c[1];
            if (lbl_80346F20 != 0) {
                lbl_80346F20->x24->x1 = 0;
            }
            lbl_80346F20->x24->x50 = 0;
        }
        break;
    case 5:
        if (lbl_80346F20 != 0) {
            lbl_80346F20->x24->x1 = 6;
        }
        break;
    case 6:
        fn_8012D0F4();
        lbl_80346F20->x24->x50++;
        if (lbl_80346F20->x24->x50 >= 3) {
            if (lbl_80346F20 != 0) {
                lbl_80346F20->x24->x1 = 0;
            }
            lbl_80346F20->x24->x50 = 0;
        }
        break;
    case 7:
        if (lbl_80346F20 != 0) {
            lbl_80346F20->x24->x1 = 8;
        }
        break;
    case 8:
        fn_8012CFC8();
        lbl_80346F20->x24->x50++;
        if (lbl_80346F20->x24->x50 >= 3) {
            if (lbl_80346F20 != 0) {
                lbl_80346F20->x24->x1 = 0;
            }
            lbl_80346F20->x24->x50 = 0;
        }
        break;
    case 9:
        fn_8012CE60();
        if (lbl_80346F20 != 0) {
            lbl_80346F20->x24->x1 = 0;
        }
        lbl_80346F20->x24->x50 = 0;
        break;
    }
    if (lbl_80346F20->x24->x0 == 0) {
        fn_8012CA4C();
    }
    return 1;
}

static inline s32 Test(s32 flags, s32 bit) {
    return (flags & (1 << bit)) != 0;
}

static inline u32 Argb(u8 a, u8 r, u8 g, u8 b) {
    return (a << 24) + (r << 16) + (g << 8) + b;
}
void fn_8012CA4C(void) {
    s32 i;
    Req r;
    for (i = 0; i < 18; i++) {
        if (i >= 0 && i < 8) {
            r.obj = lbl_80346F20->x28[i];
            r.x = 0.0001f * i + -1.3f;
            r.y = lbl_80346F20->x24->y[i];
            r.z0 = 0;
            r.z1 = 0;
            r.one = lbl_80346F20->x24->s[i];
            r.w = 1.0f;
            if (i == 6 && lbl_80346F20->x24->x3 != 1) {
                r.w = 0.0f;
            }
            if (i == 7 && lbl_80346F20->x24->x2 != 1) {
                r.w = 0.0f;
            }
        } else if (i >= 8 && i < 12) {
            r.obj = lbl_80346F20->x28[i];
            r.x = 0.0001f * i + -1.3f;
            if (i == 8) {
                r.y = lbl_80346F20->x24->f8;
            } else {
                r.y = 0.0f;
            }
            r.z0 = 0;
            r.z1 = 0;
            r.one = 1.0f;
            r.w = 1.0f;
        } else if (i >= 12 && i < 14) {
            if (lbl_80346F20->x24->x5 == 1) {
                s32 k;
                r.obj = lbl_80346F20->x28[i];
                r.x = 0.0001f * i + -1.2989999f;
                k = (i != 12);
                r.y = 1.0f;
                r.z0 = 0;
                r.z1 = 0;
                r.w = lbl_80346F20->x24->f54[k];
                if (Test(lbl_80346F20->x24->x5e, lbl_80346F20->x24->x5c[k]) != 0) {
                    r.one = 1.0f;
                } else {
                    r.one = 0.5f;
                }
                fn_8012A9A8(&r);
            }
        } else if (i >= 14 && i < 16) {
            s32 k = (i != 14);
            r.obj = lbl_80346F20->x28[i];
            r.x = 0.0001f * i + -1.2989999f;
            r.y = 0.0f;
            r.z0 = 0;
            r.z1 = 0;
            r.w = lbl_80346F20->x24->f54[k];
            r.one = 1.0f;
            if (lbl_80346F20->x24->x67 == 1) {
                s8 v = lbl_80346F20->x24->x68;
                if (v >= 0 && v < 3) {
                    u8 c = (3 - v) * 21 + 0xc0;
                    r.obj->x4->color = Argb(0xff, c, c, 0xc0);
                } else {
                    r.obj->x4->color = 0xFFC8C8C8;
                    lbl_80346F20->x24->x68 = 4;
                    lbl_80346F20->x24->x67 = 0;
                }
                lbl_80346F20->x24->x68++;
            } else {
                r.obj->x4->color = 0xFFC8C8C8;
            }
        } else {
            r.obj = lbl_80346F20->x28[i];
            r.x = 0.0001f * i + -1.2989999f;
            r.y = 0.0f;
            r.z0 = 0;
            r.z1 = 0;
            r.one = 1.0f;
            r.w = 1.0f;
        }
        if (i < 12 || i >= 14) {
            fn_8012A9A8(&r);
        }
    }
}

void fn_8012D508(u8 n) {
    SysB* b = lbl_80346F20->x24;
    s8 v = b->x5c[0] - n;
    b->x5c[1] = v;
    switch (v) {
    case 0:
        lbl_80346F20->x28[13] = fn_801D68C4(lbl_80346F04, 0x19);
        lbl_80346F20->x28[15] = fn_801D68C4(lbl_80346F04, 0x32);
        break;
    case 1:
        lbl_80346F20->x28[13] = fn_801D68C4(lbl_80346F04, 0x17);
        lbl_80346F20->x28[15] = fn_801D68C4(lbl_80346F04, 0x30);
        break;
    case 2:
        lbl_80346F20->x28[13] = fn_801D68C4(lbl_80346F04, 0x15);
        lbl_80346F20->x28[15] = fn_801D68C4(lbl_80346F04, 0x2E);
        break;
    case 3:
        lbl_80346F20->x28[13] = fn_801D68C4(lbl_80346F04, 0x14);
        lbl_80346F20->x28[15] = fn_801D68C4(lbl_80346F04, 0x2D);
        break;
    case 4:
        lbl_80346F20->x28[13] = fn_801D68C4(lbl_80346F04, 0x18);
        lbl_80346F20->x28[15] = fn_801D68C4(lbl_80346F04, 0x31);
        break;
    case 5:
        lbl_80346F20->x28[13] = fn_801D68C4(lbl_80346F04, 0x16);
        lbl_80346F20->x28[15] = fn_801D68C4(lbl_80346F04, 0x2F);
        break;
    case 6:
        if (lbl_80346F20->x24->x4 == 0) {
            lbl_80346F20->x28[13] = fn_801D68C4(lbl_80346F04, 0x8E);
            lbl_80346F20->x28[15] = fn_801D68C4(lbl_80346F04, 0x90);
        } else {
            lbl_80346F20->x28[13] = fn_801D68C4(lbl_80346F04, 0x8F);
            lbl_80346F20->x28[15] = fn_801D68C4(lbl_80346F04, 0x90);
        }
        break;
    case 7:
        lbl_80346F20->x28[13] = fn_801D68C4(lbl_80346F04, 0x1A);
        lbl_80346F20->x28[15] = fn_801D68C4(lbl_80346F04, 0x33);
        break;
    }
    lbl_80346F20->x24->f54[0] = 1.0f;
    lbl_80346F20->x24->f54[1] = 0.0f;
}

static inline Spr* PadIcon(void) {
    if (lbl_80346F20->x24->x4 == 0) {
        return fn_801D68C4(lbl_80346F04, 0x8c);
    }
    return fn_801D68C4(lbl_80346F04, 0x8d);
}

static inline void SetAlpha(u8 mask) {
    s8 i;
    for (i = 0; i < 8; i++) {
        if ((1 << i) & mask) {
            lbl_80346F20->x24->s[i] = 1.0f;
        } else {
            lbl_80346F20->x24->s[i] = 0.5f;
        }
    }
}

void fn_8012DFE0(void) {
    s8 i;

    lbl_80346F20->x28 = fn_801E1C7C(0x48);
    lbl_80346F20->x28[0] = fn_801D68C4(lbl_80346F04, 0x10);
    lbl_80346F20->x28[1] = fn_801D68C4(lbl_80346F04, 0xe);
    lbl_80346F20->x28[2] = fn_801D68C4(lbl_80346F04, 0xc);
    lbl_80346F20->x28[3] = fn_801D68C4(lbl_80346F04, 0xb);
    lbl_80346F20->x28[4] = fn_801D68C4(lbl_80346F04, 0xf);
    lbl_80346F20->x28[5] = fn_801D68C4(lbl_80346F04, 0xd);
    lbl_80346F20->x28[6] = PadIcon();
    lbl_80346F20->x28[7] = fn_801D68C4(lbl_80346F04, 0x11);
    lbl_80346F20->x28[8] = fn_801D68C4(lbl_80346F04, 9);
    lbl_80346F20->x28[9] = fn_801D68C4(lbl_80346F04, 0xa);
    lbl_80346F20->x28[10] = fn_801D68C4(lbl_80346F04, 0x1b);
    lbl_80346F20->x28[11] = fn_801D68C4(lbl_80346F04, 0x1c);
    lbl_80346F20->x28[12] = fn_801D68C4(lbl_80346F04, 0x14);
    lbl_80346F20->x28[13] = fn_801D68C4(lbl_80346F04, 0x14);
    lbl_80346F20->x28[14] = fn_801D68C4(lbl_80346F04, 0x2d);
    lbl_80346F20->x28[15] = fn_801D68C4(lbl_80346F04, 0x2d);
    lbl_80346F20->x28[16] = fn_801D68C4(lbl_80346F04, 0x1d);
    lbl_80346F20->x28[17] = fn_801D68C4(lbl_80346F04, 0x1e);
    for (i = 0; i < 8; i++) {
        lbl_80346F20->x24->y[i] = 0.0f;
        lbl_80346F20->x24->s[i] = 1.0f;
    }
    lbl_80346F20->x24->fc = 0.0f;
    lbl_80346F20->x24->x5e = 0xf;
    SetAlpha(0xf);
    lbl_80346F20->x24->x3 = 0;
    lbl_80346F20->x24->x4 = 0;
    lbl_80346F20->x28[6] = PadIcon();
    lbl_80346F20->x24->x2 = 0;
    for (i = 0; i < 8; i++) {
        lbl_80346F20->x24->x5f[i] = 0;
    }
    lbl_80346F20->x24->x5f[0] = 1;
    lbl_80346F20->x24->x5 = 1;
}

void fn_8012E404(u8 v) { lbl_80346F28->x24->x31 = v; }

void fn_8012E414(s8 v) { lbl_80346F28->x24->x32 = v; }

void fn_8012E424(u8 v) { lbl_80346F28->x24->x30 = v; }

void fn_8012E560(s8 v) { lbl_80346F28->x24->x9 = v; }

void fn_8012E570(s8 v) { lbl_80346F28->x24->x8 = v; }

void fn_8012E580(s8 v) { lbl_80346F28->x24->x7 = v; }

void fn_8012E590(s8 v) { lbl_80346F28->x24->x6 = v; }

void fn_8012E5A0(u16 v) { lbl_80346F28->x24->x4 = v; }

void fn_8012E5B0(s8 v) { (*(u8**)((u8*)lbl_80346F28 + 0x24))[2] = v; }

void fn_8012E5C0(s8 v) {
    if (lbl_80346F28 == 0) return;
    (*(u8**)((u8*)lbl_80346F28 + 0x24))[0] = v;
}

void fn_8012E5D8(void) {
    ((u8*)lbl_80346F28)[0x19] = 2;
}

void fn_8012E6EC(void) {
    s32 i;
    s32 base;
    lbl_80346F28->x24->x34 += lbl_80346F28->x24->x33 / 15.0f;
    if (lbl_80346F28->x24->x34 < 0.0f || 1.0f < lbl_80346F28->x24->x34) {
        lbl_80346F28->x24->x33 *= -1;
        lbl_80346F28->x24->x34 += lbl_80346F28->x24->x33 / 15.0f;
    }
    if (lbl_80346F28->x24->x32 == 1) {
        switch (lbl_80346F28->x24->x2) {
        case 0:
            base = 0;
            break;
        case 1:
            base = 6;
            break;
        }
        for (i = 0; i < 2; i++) {
            Req s;
            Spr *h;
            f32 sc;
            s32 c;
            s32 d;
            if (i == 0) {
                h = fn_801D68C4(lbl_80346F04, 0x6d);
                s.obj = h;
                c = 0;
                d = 0;
                sc = 1.0f;
                h->f14 = (lbl_80346F28->x24->x6 - base) * 0x30 + 0x113;
            } else {
                h = fn_801D68C4(lbl_80346F04, 0x6e);
                s.obj = h;
                c = 1;
                d = 2;
                sc = lbl_80346F28->x24->x34;
                h->f14 = (lbl_80346F28->x24->x6 - base) * 0x30 + 0x10e;
            }
            s.x = 0.001f * (d + 2) + -1.2f;
            s.y = 1.0f;
            s.z0 = 0;
            s.z1 = c;
            s.one = 1.0f;
            s.w = sc;
            fn_8012A9A8(&s);
        }
    }
}

static inline s32 BitSet(s32 mask, s32 bit) {
    return (mask & (1 << bit)) != 0;
}

void fn_8012ECF8(void) {
    Req r;
    s32 i;
    s32 off;
    s32 aux;
    f32 sy;

    off = 0;
    for (i = 0; i < 16; i++, off += 4) {
        if (i >= 0 && i < 9) {
        } else if (i >= 9 && i < 11) {
            r.obj = lbl_80346F28->x28[i];
            if (i == 9) {
                if (lbl_80346F28->x24->x2 == 2) {
                    continue;
                }
                switch (lbl_80346F28->x24->x6) {
                case 0:
                    if (lbl_80346F28->x24->x2 == 3) {
                        r.obj->x4->color = 0xc8101010;
                    } else {
                        r.obj->x4->color = 0xc8004000;
                    }
                    break;
                case 1:
                    r.obj->x4->color = 0xc8400000;
                    break;
                case 2:
                    r.obj->x4->color = 0xc820002a;
                    break;
                case 3:
                    r.obj->x4->color = 0xc8000040;
                    break;
                case 4:
                    r.obj->x4->color = 0xc82a2000;
                    break;
                case 5:
                    r.obj->x4->color = 0xdc101820;
                    break;
                case 6:
                case 7:
                    r.obj->x4->color = 0xc8101010;
                    break;
                case 8:
                case 9:
                default:
                    r.obj->x4->color = 0xc8101010;
                    break;
                }
                r.x = 0.001f * i + -1.3f;
                r.y = 1.0f;
                r.z0 = 0;
                r.z1 = 0;
                r.one = 1.0f;
                r.w = 1.0f;
                fn_8012A9A8(&r);
            } else {
                switch (lbl_80346F28->x24->x2) {
                case 2:
                    r.obj = fn_801D68C4(lbl_80346F04, 0x2b);
                    break;
                default:
                    r.obj = fn_801D68C4(lbl_80346F04, 0x20);
                    break;
                }
                r.x = 0.001f * i + -1.3f;
                r.y = 1.0f;
                r.z0 = 0;
                r.z1 = 0;
                r.one = 1.0f;
                r.w = 1.0f;
                fn_8012A9A8(&r);
            }
        } else if (i >= 11 && i < 12) {
        } else if (i >= 12 && i < 15) {
            if (lbl_80346F28->x24->x31 == 1 && lbl_80346F28->x24->x7 != 1) {
                r.obj = lbl_80346F28->x28[i];
                r.x = 2.0f * (0.0001f * i) + -1.288f;
                if (i != 14) {
                    aux = 0;
                    sy = 1.0f;
                } else {
                    aux = 1;
                    sy = lbl_80346F28->x24->x34;
                }
                r.y = 1.0f;
                r.z0 = 0;
                r.z1 = aux;
                r.one = 1.0f;
                r.w = sy;
                fn_8012A9A8(&r);
            }
        } else if (i >= 15) {
            s8 idx = lbl_80346F28->x24->x9;
            if (idx != -1) {
                r.obj = lbl_80346F28->x28[i];
                r.obj->f18 = (idx * 0x18 + 0x12a);
                r.x = -1.1989f;
                r.y = 1.0f;
                r.z0 = 0;
                r.z1 = 1;
                r.one = 1.0f;
                r.w = 1.0f;
                fn_8012A9A8(&r);
            }
        }
    }
    off = 0;
    for (i = 0; i < 16; i++, off += 4) {
        if (i >= 0 && i < 9) {
            if (BitSet(lbl_80346F28->x24->x4, i) == 1) {
                r.obj = lbl_80346F28->x28[i];
                if (i == lbl_80346F28->x24->x6) {
                    r.x = -1.2f;
                } else {
                    r.x = -1.3f;
                }
                r.y = 1.0f;
                r.z0 = 0;
                r.z1 = 0;
                r.one = 1.0f;
                r.w = 1.0f;
                fn_8012A9A8(&r);
            }
        }
    }
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
    lbl_80346F18 = fn_802268E8(lbl_803475A8, (void (*)(void))fn_8012C0D8);
    lbl_80346F18->x24 = fn_801E1C7C(0xc);
    if (lbl_80346F18 != 0) {
        lbl_80346F18->x24->x0 = 1;
    }
    lbl_80346F18->x24->f4 = lbl_8034A418;
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

void fn_8012E4FC(void **src) {
    *(void **)(*(u8 **)((u8 *)lbl_80346F28 + 0x24) + 0xc) = src[0];
    *(void **)(*(u8 **)((u8 *)lbl_80346F28 + 0x24) + 0x10) = src[1];
    *(void **)(*(u8 **)((u8 *)lbl_80346F28 + 0x24) + 0x14) = src[2];
    *(void **)(*(u8 **)((u8 *)lbl_80346F28 + 0x24) + 0x18) = src[3];
    *(void **)(*(u8 **)((u8 *)lbl_80346F28 + 0x24) + 0x1c) = src[4];
    *(void **)(*(u8 **)((u8 *)lbl_80346F28 + 0x24) + 0x20) = src[5];
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

void fn_8012C0D8(Obj *p) {
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

void fn_8012C744(Obj *p) {
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

void fn_8012E640(Obj *p) {
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
        lbl_80346F10->x28[0]->f14 = 84.0f;
        lbl_80346F10->x28[0]->f18 = 37.0f;
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
    lbl_80346F20->x24->f54[0] = 1.0f;
    lbl_80346F20->x24->f54[1] = 0.0f;
    lbl_80346F20->x24->x5c[0] = 3;
    lbl_80346F20->x24->x5c[1] = 3;
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
        r.obj->x4->color = n->x10;
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
    r.obj->x4->color = n->x10;
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
    Spr* pos;
    f32 d;

    d = (-43.5f * (f32)n) / 3.0f;
    lbl_80346F10->x24->f4 += d;
    axis.x = 0.0f;
    axis.y = 0.0f;
    axis.z = 1.0f;
    pos = lbl_80346F10->x28[0];
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
        lbl_80346F10->x28 = fn_801E1C7C(0x24);
        lbl_80346F10->x28[0] = fn_801D68C4(lbl_80346F04, 8);
        lbl_80346F10->x28[1] = fn_801D68C4(lbl_80346F04, 0);
        lbl_80346F10->x28[2] = fn_801D68C4(lbl_80346F04, 1);
        lbl_80346F10->x28[3] = fn_801D68C4(lbl_80346F04, 2);
        lbl_80346F10->x28[4] = fn_801D68C4(lbl_80346F04, 3);
        lbl_80346F10->x28[5] = fn_801D68C4(lbl_80346F04, 4);
        lbl_80346F10->x28[6] = fn_801D68C4(lbl_80346F04, 5);
        lbl_80346F10->x28[7] = fn_801D68C4(lbl_80346F04, 6);
        lbl_80346F10->x28[8] = fn_801D68C4(lbl_80346F04, 7);
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

static inline s16 ToS16(f32 x) {
    return x;
}
void fn_8012BD34(void) {
    SysA *q = lbl_80346F10->x24;
    f32 f4 = q->f24;
    f32 f5 = q->f2c;
    f32 f6 = q->f28;
    f32 f3 = q->f1c;
    s32 r5 = q->x20;
    f32 f7, f8;
    if (f6 > f4) f6 = f4;
    if (f6 < 0.0f) f6 = 0.0f;
    if (f5 > f4) f5 = f4;
    if (f5 < 0.0f) f5 = 0.0f;
    f7 = q->f34;
    f8 = q->f3c;
    if (q->x14 == 1) {
        switch (q->x18) {
        case 0:
            f3 = (f5 - f6) / 30.0f;
            q->f1c = f3;
            f7 = 500.0f * (f6 / f4);
            f8 = 0.0f;
            lbl_80346F10->x24->x18 = 1;
            break;
        case 1:
            r5++;
            if (r5 > 30.0f) {
                q->x18 = 2;
                f6 = f5;
                r5 = 0;
                f3 = 0.0f;
            }
            f6 += f3;
            f7 = 500.0f * (f6 / f4);
            f8 = 0.0f;
            break;
        case 2:
            q->x14 = 0;
            break;
        }
        if (f3 >= 0.0f) {
            if (f5 < f6) f6 = f5;
        } else {
            if (f5 > f6) f6 = f5;
        }
    } else {
        f7 = 500.0f * (f5 / f4);
        f8 = 500.0f * ((f6 - f5) / f4);
    }
    lbl_80346F10->x24->f24 = f4;
    lbl_80346F10->x24->f2c = f5;
    lbl_80346F10->x24->f28 = f6;
    lbl_80346F10->x24->x20 = r5;
    if (f7 - ToS16(f7) >= 0.5f) {
        lbl_80346F10->x24->f34 = 1.0f + ToS16(f7);
    } else {
        lbl_80346F10->x24->f34 = ToS16(f7);
    }
    if (f8 - ToS16(f8) > 0.5f) {
        lbl_80346F10->x24->f3c = 1.0f + ToS16(f8);
    } else {
        lbl_80346F10->x24->f3c = ToS16(f8);
    }
    lbl_80346F10->x24->x30 = 0xff20e820;
    lbl_80346F10->x24->x38 = 0xffe82020;
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

/* Draws sprite 0 of lbl_80346F30 at (16, 386), 100 higher when its mode x2 is 1. */
void fn_8012F61C(void)
{
    Req r;
    s8 up;
    r.obj = lbl_80346F30->x28[0];
    up = lbl_80346F30->x24->x2 == 1;
    r.obj->f14 = 16.0f;
    r.obj->f18 = up * -100 + 386;
    r.x = -1.1f;
    r.y = 1.0f;
    r.z0 = 0;
    r.z1 = 0;
    r.one = 1.0f;
    r.w = 1.0f;
    fn_8012A9A8(&r);
}
static inline s32 Bit(s32 v, s32 m)
{
    return (v & m) != 0;
}

void fn_8012E970(void)
{
    f32 savedz;
    SysC *rows;
    char *name;
    s16 off;
    s32 y;
    s8 val;
    s8 i;
    Req r;

    savedz = TextGetZ();
    TextSetZ(-1.199f);
    for (i = 0; i < 6; i++) {
        TextPushColor();
        rows = lbl_80346F28->x24;
        name = rows->name[i];
        if (name != 0) {
            off = i * 0x18;
            val = rows->value[i];
            switch (rows->kind[i]) {
            case 0:
                lbl_80346F28->x28[11] = fn_801D68C4(lbl_80346F04, 0x40);
                break;
            case 1:
                lbl_80346F28->x28[11] = fn_801D68C4(lbl_80346F04, 0x41);
                break;
            case 2:
                lbl_80346F28->x28[11] = fn_801D68C4(lbl_80346F04, 0x42);
                break;
            case 3:
                lbl_80346F28->x28[11] = fn_801D68C4(lbl_80346F04, 0x43);
                break;
            case 4:
                lbl_80346F28->x28[11] = fn_801D68C4(lbl_80346F04, 0x44);
                break;
            case 5:
                lbl_80346F28->x28[11] = fn_801D68C4(lbl_80346F04, 0x45);
                break;
            case 6:
                lbl_80346F28->x28[11] = fn_801D68C4(lbl_80346F04, 0x46);
                break;
            case 7:
                lbl_80346F28->x28[11] = fn_801D68C4(lbl_80346F04, 0x47);
                break;
            case 8:
                lbl_80346F28->x28[11] = fn_801D68C4(lbl_80346F04, 0x54);
                break;
            case 9:
                lbl_80346F28->x28[11] = fn_801D68C4(lbl_80346F04, 0x55);
                break;
            case 10:
                lbl_80346F28->x28[11] = fn_801D68C4(lbl_80346F04, 0x61);
                break;
            case 11:
                lbl_80346F28->x28[11] = fn_801D68C4(lbl_80346F04, 0x71);
                break;
            case 12:
                lbl_80346F28->x28[11] = fn_801D68C4(lbl_80346F04, 0x62);
                break;
            case 13:
                lbl_80346F28->x28[11] = fn_801D68C4(lbl_80346F04, 0x88);
                break;
            default:
                lbl_80346F28->x28[11] = fn_801D68C4(lbl_80346F04, 0x47);
                break;
            }
            y = off + 0x12d;
            r.obj = lbl_80346F28->x28[11];
            r.obj->f14 = 284.0f;
            r.obj->f18 = (f32)y;
            r.x = -1.199f;
            r.y = 1.0f;
            r.z0 = 0;
            r.z1 = 0;
            if (Bit(lbl_80346F28->x24->x30, 1 << i) == 1) {
                r.one = 1.0f;
                TextSetColor(0xFFC8C8C8);
            } else {
                r.one = 0.5f;
                TextSetColor(0xFF606060);
            }
            r.w = 1.0f;
            fn_8012A9A8(&r);
            TextPrint(0x144, y, name);
            if (val != -1) {
                if (val == -2) {
                    TextPrint(0x21c, y, "\x82\x64");
                } else {
                    TextPrintf(0x21c, y, "%2d", val);
                }
            }
        }
        TextPopColor(1);
    }
    TextSetZ(savedz);
}
static inline f32 Deg(f32 deg)
{
    f32 t;
    t = 182.04445f * deg;
    return (s32)t;
}

static inline s32 Ang(f32 deg)
{
    f32 t;
    t = 182.04445f * deg;
    return t;
}

void fn_8012D760(s8 step)
{
    NJS_MATRIX m;
    NJS_POINT3 pos;
    NJS_POINT3 out;
    NJS_VECTOR axis;
    f32 d;
    s32 ang;
    s32 i;
    Spr *it;

    d = 30.0f * (f32)step / 3.0f;
    lbl_80346F20->x24->fc += d;
    axis.x = 0.0f;
    axis.y = 0.0f;
    axis.z = 1.0f;
    ang = (s32)(182.04445f * d);
    for (i = 0; i < 8; i++) {
        it = lbl_80346F20->x28[i];
        pos.x = 19.0f + it->f14 - 102.0f;
        pos.y = 19.0f + it->f18 - 381.0f;
        pos.z = 0.0f;
        njUnitMatrix(m);
        njRotate(m, &axis, ang);
        njCalcPoint(m, &pos, &out);
        it->f14 = 102.0f + (out.x - 19.0f);
        it->f18 = 381.0f + (out.y - 19.0f);
    }
    lbl_80346F20->x24->y[0] = Deg(-6.0f * lbl_80346F20->x24->fc + 180.0f);
    lbl_80346F20->x24->y[1] = Deg(-6.0f * lbl_80346F20->x24->fc + 360.0f);
    lbl_80346F20->x24->y[2] = Deg(-6.0f * lbl_80346F20->x24->fc + 540.0f);
    lbl_80346F20->x24->y[3] = Deg(-6.0f * lbl_80346F20->x24->fc + 720.0f);
    lbl_80346F20->x24->y[4] = Deg(-6.0f * lbl_80346F20->x24->fc + 900.0f);
    lbl_80346F20->x24->y[5] = Deg(-6.0f * lbl_80346F20->x24->fc + 1080.0f);
    lbl_80346F20->x24->y[6] = Deg(-6.0f * lbl_80346F20->x24->fc + 1260.0f);
    lbl_80346F20->x24->y[7] = Deg(-6.0f * lbl_80346F20->x24->fc + 1440.0f);
    lbl_80346F20->x24->f8 = Deg(-1.0f * (lbl_80346F20->x24->fc / 3.0f));
}
void fn_8012DB18(void)
{
    NJS_MATRIX m;
    NJS_POINT3 pos;
    NJS_POINT3 out;
    NJS_VECTOR axis;
    s32 i;
    Spr *it;
    s32 ang;
    s32 j;

    axis.x = 0.0f;
    axis.y = 0.0f;
    axis.z = 1.0f;
    for (i = 0; i < 8; i++) {
        it = lbl_80346F20->x28[i];
        pos.x = 69.0f;
        pos.y = -45.0f;
        pos.z = 0.0f;
        njUnitMatrix(m);
        njRotate(m, &axis, Ang(30.0f * (f32)i));
        njCalcPoint(m, &pos, &out);
        it->f14 = 151.0f + (out.x - pos.x);
        it->f18 = 316.0f + (out.y - pos.y);
    }
    for (i = 0; i < 8; i++) {
        lbl_80346F20->x24->y[i] = Deg(i * -180);
    }
    for (j = 0; j < 3; j++) {
        ang = -Ang(30.0f);
        axis.x = 0.0f;
        axis.y = 0.0f;
        axis.z = 1.0f;
        for (i = 0; i < 8; i++) {
            it = lbl_80346F20->x28[i];
            pos.x = 19.0f + it->f14 - 102.0f;
            pos.y = 19.0f + it->f18 - 381.0f;
            pos.z = 0.0f;
            njUnitMatrix(m);
            njRotate(m, &axis, ang);
            njCalcPoint(m, &pos, &out);
            it->f14 = 102.0f + (out.x - 19.0f);
            it->f18 = 381.0f + (out.y - 19.0f);
        }
        for (i = 0; i < 8; i++) {
            lbl_80346F20->x24->y[i] = Deg((i + 1) * -180);
        }
    }
}
static inline u32 Color(u8 a, u8 r, u8 g, u8 b)
{
    return (a << 24) + (r << 16) + (g << 8) + b;
}

void fn_8012B47C(void)
{
    Req r;
    Num n;
    f32 sx;
    f32 sy;
    f32 v;
    f32 t;
    f32 z;
    f32 savedz;
    s32 i;
    u8 ca;
    u8 cr;
    u8 cg;
    u8 cb;

    for (i = 0; i < 9; i++) {
        if (i == 0) {
            switch (lbl_80346F10->x24->x10) {
            case 0:
                r.obj = fn_801D68C4(lbl_80346F04, 0x10);
                break;
            case 1:
                r.obj = fn_801D68C4(lbl_80346F04, 0xe);
                break;
            case 2:
                r.obj = fn_801D68C4(lbl_80346F04, 0xc);
                break;
            case 3:
                r.obj = fn_801D68C4(lbl_80346F04, 0xb);
                break;
            case 4:
                r.obj = fn_801D68C4(lbl_80346F04, 0xf);
                break;
            case 5:
                r.obj = fn_801D68C4(lbl_80346F04, 0xd);
                break;
            case 6:
                if (fn_8012C3DC() == 0) {
                    r.obj = fn_801D68C4(lbl_80346F04, 0x8c);
                } else {
                    r.obj = fn_801D68C4(lbl_80346F04, 0x8d);
                }
                break;
            case 7:
                r.obj = fn_801D68C4(lbl_80346F04, 0x11);
                break;
            default:
                r.obj = fn_801D68C4(lbl_80346F04, 0x8d);
                break;
            }
            sx = r.obj->f14;
            sy = r.obj->f18;
            r.obj->f14 = lbl_80346F10->x28[i]->f14;
            r.obj->f18 = lbl_80346F10->x28[i]->f18;
            r.x = 0.0001f * (f32)i + -1.3f;
            r.y = lbl_80346F10->x24->f8;
            r.z0 = 0;
            r.z1 = 0;
            r.one = 1.0f;
            r.w = 1.0f;
        } else if (i == 4) {
            r.obj = lbl_80346F10->x28[i];
            sx = r.obj->f14;
            sy = r.obj->f18;
            r.x = 0.0001f * (f32)i + -1.3f;
            r.y = 0.0f;
            r.z0 = 0;
            r.z1 = 1;
            r.one = 1.0f;
            r.w = 1.0f;
            r.obj->x4->fc = r.obj->x4->f4 + lbl_80346F10->x24->f34;
            r.obj->x4->color = lbl_80346F10->x24->x30;
        } else if (i == 5) {
            r.obj = lbl_80346F10->x28[i];
            sx = r.obj->f14;
            sy = r.obj->f18;
            r.obj->f14 = lbl_80346F10->x28[4]->f14 + lbl_80346F10->x28[4]->x4->fc;
            r.x = 0.0001f * (f32)i + -1.3f;
            r.y = 0.0f;
            r.z0 = 0;
            r.z1 = 1;
            r.one = 1.0f;
            r.w = 1.0f;
            r.obj->x4->fc = r.obj->x4->f4 + lbl_80346F10->x24->f3c;
            r.obj->x4->color = lbl_80346F10->x24->x38;
        } else {
            r.obj = lbl_80346F10->x28[i];
            sx = r.obj->f14;
            sy = r.obj->f18;
            r.x = 0.0001f * (f32)i + -1.3f;
            r.y = 1.0f;
            r.z0 = 0;
            r.z1 = 0;
            r.one = 1.0f;
            r.w = 1.0f;
        }
        fn_8012A9A8(&r);
        r.obj->f14 = sx;
        r.obj->f18 = sy;
    }
    if (lbl_80346F10->x24->x14 == 1) {
        v = lbl_80346F10->x24->f28;
        lbl_80346F10->x24->f40 = 1.0f;
    } else {
        v = lbl_80346F10->x24->f2c;
        if (lbl_80346F10->x24->f28 != v) {
            lbl_80346F10->x24->f40 += lbl_80346F10->x24->x44 / 15.0f;
            if (lbl_80346F10->x24->f40 <= 0.0f || 1.0f < lbl_80346F10->x24->f40) {
                lbl_80346F10->x24->x44 *= -1;
            }
        } else {
            lbl_80346F10->x24->f40 = 1.0f;
            lbl_80346F10->x24->x44 = -1;
        }
    }
    t = v / lbl_80346F10->x24->f24;
    if (t > 0.5f) {
        ca = 0xfa;
        cb = 0x20;
        cr = (s32)(376.0f * (1.0f - t)) + 0x20;
        cg = 0xfa - (s32)(100.0f * (1.0f - t));
    } else {
        ca = 0xfa;
        cb = 0x20;
        cr = (s32)(30.0f * (1.0f - 2.0f * t)) + 0xdc;
        cg = 0xc8 - (s32)(168.0f * (1.0f - 2.0f * t));
    }
    n.x0 = 0x23;
    n.x2 = 0x28;
    n.cnt = (s32)v;
    z = 0.0001f * (f32)i + -1.3f;
    n.f8 = z;
    n.fc = lbl_80346F10->x24->f40;
    n.x10 = Color(ca, cr, cg, cb);
    fn_8012BAA8(&n);
    savedz = TextGetZ();
    TextSetZ(z);
    TextSetScale(1.0f, 1.0f);
    TextPrint(0x45, 0x28, "/");
    TextPrintf(0x51, 0x28, "%2d", (s32)lbl_80346F10->x24->f24);
    TextSetZ(savedz);
}
