#include "types.h"

/* One declaration per global / prototype. Tk and Chr tables are read through raw offsets
   (same offsets and widths as the per-function struct views they replace). */
typedef struct Lim { u8 pad[6]; s16 x6; s16 x8; s16 xa; } Lim;
typedef struct Node { u8 pad0[8]; u32 x8; u8 name[0x2c]; struct Node* x38; } Node;

extern u8 lbl_8030A10C[];
extern u8 *lbl_80309700[12];
extern u8 *lbl_80309DE4[12];
extern s32 *lbl_80347398;
extern Lim *lbl_80347390;
extern Node *lbl_803473A0;
extern s8 lbl_80347334;
extern s32 lbl_8034733C;
extern s32 lbl_80347338;

typedef struct {
    void *f0;
    void *f4;
    u32 f8;
    u8 fc;
    u8 pad[3];
} TblEnt;
extern TblEnt lbl_80309E88[4];

typedef struct {
    u8 pad0[0x14];
    u32 *p14;
    u8 rest[0x68 - 0x18];
} Elem;

typedef struct ChrState { s32 x0; s8 x4; u8 pad5; s16 x6; s8 x8; u8 pad9[0x17]; } ChrState;
extern ChrState lbl_80309174[12];

typedef struct Row16 { u8 pad[8]; s8 x8; u8 pad9[7]; } Row16;
extern Row16 lbl_80309730[12];

typedef struct Vec3 { f32 x; f32 y; f32 z; } Vec3;

typedef struct Ent { s32 x0; u32 x4; s32 x8; s32 xc; } Ent;
typedef struct Hdr { u8 pad0[4]; s16 count; u8 pad6[2]; Ent e[1]; } Hdr;

#define WORK_OF(i) (*(u8 **)(lbl_80309700[i] + 0x24))
#define WK_S32(i, off) (*(s32 *)(WORK_OF(i) + (off)))
#define WK_S16(i, off) (*(s16 *)(WORK_OF(i) + (off)))
#define CHR_S32(i, off) (*(s32 *)(lbl_80309DE4[i] + (off)))
#define CHR_U32(i, off) (*(u32 *)(lbl_80309DE4[i] + (off)))
#define CHR_S8(i, off) (*(s8 *)(lbl_80309DE4[i] + (off)))

void fn_800D208C(void *obj, f32 f);
void fn_8006AFD0(s16 i, void *a, void *b, s32 c);
extern void fn_8006AC68(s16 i);
extern void fn_800696A8(s32 a, s16 i, s32 b, s8 v);
void fn_8006E924(void);
s32 fn_8025ECC4(void);
s32 fn_801D6E38(s32 a);
f32 njSin(s32 a);
f32 njCos(s32 a);
char* fn_8025F0B0(char* d, const char* s);
void* fn_802AC730(void* d, s32 c, u32 n);
void fn_801CC62C(char* s);
void fn_8006E244(Ent* e, s32 n);
int fn_8003DBAC(s32 n, char* buf);
int fn_8025EF88(char* a, const char* b);
void fn_80015554(void);

void fn_80055E94(u8 *p) {
    p[0x18] |= 0x40;
    *(s32 *)(lbl_8030A10C + 0x1c4) -= 1;
}

void fn_80056FA4(f32 *out, s16 flag) {
    if (flag) {
        *out = -1.0f;
    } else {
        *out = 0.0f;
    }
}

void fn_80060950(u8 *p) {
    fn_800D208C(*(void **)(p + 0x34), *(f32 *)(p + 0x38));
}

void fn_80061014(f32 *a, f32 *b, f32 *out) {
    out[0] = b[0] - a[0];
    out[1] = b[1] - a[1];
    out[2] = b[2] - a[2];
}

void fn_800614FC(u32 *src, u32 *dst) {
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}

void fn_80061F3C(f32 *src, f32 *dst) {
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}

void fn_800688C4(void *a, s16 idx, void *b, s8 v) {
    u8 *p = lbl_80309700[idx];
    *(s16 *)(*(u8 **)(p + 0x24) + 0x44) = v;
}

void fn_80069684(s16 a, void *b, s32 c) {
    fn_8006AFD0(a, b, (void *)c, 0);
}

void fn_8006B3C4(void *a, s16 idx) {
    u8 *p = lbl_80309DE4[idx];
    *(u32 *)(p + 0x1c) |= 1;
}

void fn_8006B3E8(void) {
}

s32 fn_8006B670(s16 idx) {
    if (idx >= 4) {
        return 0;
    }
    return lbl_80309E88[idx].fc == 0;
}

void fn_8006B6A4(s16 idx, u32 v) {
    if (idx < 4) {
        lbl_80309E88[idx].f8 = v;
    }
}

u32 fn_8006B6C8(s16 idx) {
    if (idx >= 4) {
        return 0;
    }
    return lbl_80309E88[idx].f8;
}

void *fn_8006B6F4(s16 idx) {
    if (idx >= 4) {
        return 0;
    }
    return lbl_80309E88[idx].f0;
}

void fn_8006C5A4(void) {
    *lbl_80347398 = -1;
}

s32 fn_8006C8C4(void) {
    return *(u32 *)(lbl_8030A10C + 0x68) == 0;
}

void fn_8006CF28(u8 *a, u32 *out, s32 idx) {
    Elem *arr = *(Elem **)(a + 4);
    u32 *p3 = *(u32 **)((u8 *)arr + 0x14);
    u32 *p;

    if (*p3 == 0) {
        return;
    }
    p = arr[idx].p14;
    *out = p[1];
}

void fn_8006EA70(void) {
    fn_8006E924();
}

void fn_80071CBC(f32 *a, f32 *b) {
    b[0] = b[0] + a[0];
    b[1] = b[1] + a[1];
    b[2] = b[2] + a[2];
}

void fn_800608C8(f32* p) {
    *p = (f32)(fn_8025ECC4() % 6) * 70.0f;
    if (*p == 0.0f) {
        *p = 45.0f;
    }
}

void fn_80060A54(void) {
    if (fn_801D6E38(0)) {
        *(u32 *)(lbl_8030A10C + 0x6C) |= 0x100000;
        *(s32 *)(lbl_8030A10C + 0x168) = 0;
    } else {
        *(u32 *)(lbl_8030A10C + 0x6C) &= ~0x100000;
    }
}

void fn_80060B20(Vec3* v, f32 x) {
    s32 a;
    if (x > 180.0f) {
        x = 180.0f;
    }
    a = (s32)(182.04445f * (90.0f - 0.5f * x));
    v->x = njCos(a);
    v->z = njSin(a);
}

void fn_800688E8(void* a, s16 i, void* b, s8 v) {
    WK_S32(i, 0x3c) = -1;
    if (CHR_U32(i, 0x1c) & 0x6100) {
        WK_S16(i, 0x44) = -1;
    } else {
        WK_S16(i, 0x44) = v;
    }
}

void fn_80069008(s16 i) {
    fn_8006AC68(i);
    WK_S16(i, 0x44) = 0;
    WK_S32(i, 0x3c) = CHR_S32(i, 0x14);
}

void fn_80069070(s16 i, void* a, void* b) {
    fn_8006AFD0(i, a, b, 0);
    WK_S16(i, 0x44) = 0;
    WK_S32(i, 0x3c) = CHR_S32(i, 0x14);
}

void fn_800690DC(void* a, s16 i, void* b, s8 v) {
    WK_S32(i, 0x3c) = (s16)(CHR_S32(i, 0x18) - CHR_S32(i, 0x14));
    WK_S32(i, 0x40) = (s16)(CHR_S8(i, 0xff) - CHR_S8(i, 0xfe));
    WK_S16(i, 0x44) = v;
}

void fn_80069AE4(void* a, s16 idx, void* b, s8 v) {
    WK_S32(idx, 0x3c) = CHR_S32(idx, 0x18) - CHR_S32(idx, 0x14);
    WK_S16(idx, 0x44) = v;
    lbl_80309174[idx].x8 = 1;
    lbl_80309730[idx].x8 = 1;
}

void fn_80069D34(void* a, s16 idx, void* b, s8 v) {
    WK_S32(idx, 0x3c) = lbl_80347390->x6 - lbl_80347390->x8;
    WK_S16(idx, 0x44) = v;
    lbl_80309174[idx].x8 = 1;
    lbl_80309730[idx].x8 = 1;
}

void fn_80069FF4(s32 a, s16 i, s32 b, s8 v) {
    WK_S32(i, 0x3c) = -1;
    if (CHR_U32(i, 0x1c) & 0x2100) {
        WK_S16(i, 0x44) = -1;
    } else if (v == 0x1e) {
        WK_S16(i, 0x44) = v;
    } else {
        fn_800696A8(a, i, b, v);
    }
}

void fn_8006A388(s32 a, s16 i, s32 b, s8 v) {
    WK_S32(i, 0x3c) = -1;
    if (CHR_U32(i, 0x1c) & 0x2100) {
        WK_S16(i, 0x44) = -1;
    } else {
        WK_S16(i, 0x44) = v;
    }
}

void fn_8006A70C(s32 a, s16 i, s32 b, s8 v) {
    if (CHR_U32(i, 0x1c) & 0x7150) {
        WK_S16(i, 0x44) = -1;
        WK_S32(i, 0x3c) = -1;
    } else {
        fn_800696A8(a, i, b, v);
    }
}

void fn_8006A774(s32 a, s16 i, s32 b, s8 v) {
    if (CHR_U32(i, 0x1c) & 0x6350) {
        WK_S16(i, 0x44) = -1;
        WK_S32(i, 0x3c) = -1;
    } else {
        fn_800696A8(a, i, b, v);
    }
}

void fn_8006AB04(s32 a, s16 i, s32 b, s8 v) {
    if (CHR_U32(i, 0x1c) & 0x2150) {
        WK_S16(i, 0x44) = -1;
        WK_S32(i, 0x3c) = -1;
    } else {
        fn_800696A8(a, i, b, v);
    }
}

void fn_8006AC00(s32 a, s16 i, s32 b, s8 v) {
    fn_800696A8(a, i, b, v);
    if (WK_S16(i, 0x44) != -1) {
        lbl_80309730[i].x8 = 5;
    }
}

void fn_8006AD44(s32 a, s16 i, s32 b, s8 v) {
    if (CHR_U32(i, 0x1c) & 0x61d0) {
        WK_S16(i, 0x44) = -1;
        WK_S32(i, 0x3c) = -1;
    } else {
        fn_800696A8(a, i, b, v);
    }
}

void fn_8006C860(char* a, char* b) {
    char buf[0x100];
    fn_802AC730(buf, 0, 0xff);
    fn_8025F0B0(buf, a);
    fn_8025F0B0(buf, b);
    fn_801CC62C(buf);
}

s32 fn_8006E6E4(Hdr* h) {
    Ent* e = h->e;
    s16 i;
    for (i = 0; i < h->count; e++, i++) {
        e->x4 += (u32)h;
        fn_8006E244(e, 0);
    }
    return 0;
}

Node* fn_8006E810(s32 n) {
    char buf[0x20];
    Node* p;
    Node* nx;
    fn_8003DBAC(n, buf);
    p = lbl_803473A0;
    if (p->x8 == 0) {
        return 0;
    }
    for (;;) {
        if (p->x8 != 0 && fn_8025EF88(buf, (char*)p->name) == 0) {
            return p;
        }
        nx = p->x38;
        if (nx == 0) {
            break;
        }
        p = nx;
    }
    return 0;
}

s32 fn_8006E898(char* s) {
    Node* p = lbl_803473A0;
    Node* nx;
    if (p->x8 == 0) {
        return 0;
    }
    for (;;) {
        if (p->x8 != 0 && fn_8025EF88(s, (char*)p->name) == 0) {
            return 1;
        }
        nx = p->x38;
        if (nx == 0) {
            break;
        }
        p = nx;
    }
    return 0;
}

void fn_80070848(void) {
    u8 *t = lbl_80309700[lbl_80347334];
    if (t == 0) {
        lbl_8034733C = 5;
        lbl_80347338 = 0;
        fn_80015554();
    } else if (*(u32 *)(*(u8 **)(t + 0x24) + 4) & 0x13) {
        lbl_8034733C = 5;
        lbl_80347338 = 0;
        fn_80015554();
    }
}

void fn_80071BCC(f32* out, s32 ang, f32 s) {
    out[0] = s * njSin(ang);
    out[2] = s * njCos(ang);
}
