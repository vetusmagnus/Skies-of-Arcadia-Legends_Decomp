#include "types.h"
#include "ninja.h"
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
typedef struct U5C188 {
    u8 id;
    u8 pad1[5];
    s16 kind;
    u8 pad8[0x50 - 8];
    u32 f50;
    u8 pad54[0xf0 - 0x54];
    u32 ff0;
    u8 padf4[0x204 - 0xf4];
    s16 s204;
} U5C188;
typedef struct W5C188 {
    u8 pad0[0x4c];
    U5C188 *u;
} W5C188;
typedef struct T5C188 {
    u8 pad0[0x24];
    W5C188 *work;
} T5C188;
typedef struct R5C188 {
    u8 pad0[0x10];
    u32 f10;
    s16 s14;
    s16 s16;
} R5C188;
typedef struct S5C188 {
    u8 pad0[4];
    T5C188 *target;
    u8 pad8[4];
    R5C188 *rec;
} S5C188;
typedef struct O5C188 {
    u8 pad0[0x18];
    u8 flags;
    u8 state;
    u8 pad1A[10];
    S5C188 *s;
} O5C188;
typedef struct G5C188 {
    u8 pad[0x1c4];
    s32 count;
} G5C188;
extern s16 fn_8001FDD8(W5C188 *, s16, s16);
extern s32 fn_80014C90(u8, s32);
extern void fn_80075F2C(T5C188 *);
typedef struct { f32 x, y, z; } V3;
typedef struct U5C328 {
    u8 pad0[0xf0];
    u32 ff0;
    u8 padf4[0x110 - 0xf4];
    V3 v110;
} U5C328;
typedef struct W5C328 {
    u8 pad0[0x1c];
    V3 pos;
    u8 pad28[4];
    s32 i2c;
    u8 pad30[0x4c - 0x30];
    U5C328 *u;
} W5C328;
typedef struct T5C328 {
    u8 pad0[0x24];
    W5C328 *work;
} T5C328;
typedef struct R5C328 {
    u8 pad0[0x10];
    u16 kind;
    u16 count;
    V3 vecs[4];
    f32 angs[4];
} R5C328;
typedef struct S5C328 {
    u8 pad0[4];
    T5C328 *target;
    R5C328 *rec;
} S5C328;
typedef struct O5C328 {
    u8 pad0[0x18];
    u8 flags;
    u8 state;
    u8 pad1A[10];
    S5C328 *s;
} O5C328;
typedef struct G5C328 {
    u8 pad[0x1c4];
    s32 count;
} G5C328;
extern s32 fn_8025ECC4(void);
extern void fn_80071CF0(V3 *, V3 *);
typedef struct P5D47C {
    u8 pad0[0x10];
    u32 flags;
    s16 s14;
    u8 pad16[6];
    V3 v1c;
    V3 v28;
    V3 v34;
    V3 v40;
    V3 v4c;
    V3 v58;
    u8 pad64[4];
    V3 v68;
} P5D47C;
typedef struct O5D47C {
    u8 pad0[0x20];
    V3 v20;
    V3 v2c;
    V3 v38;
    u8 pad44[0x2c];
    s16 s70;
    s16 state;
    s8 b74;
    u8 pad75[3];
    void *p78;
    void *p7c;
    u8 pad80[0x34];
    P5D47C *p;
} O5D47C;
extern void fn_80014AB8(s32, O5D47C *);
extern void fn_8001E4A0(V3 *, V3 *, void *);
extern void fn_80061518(V3 *, V3 *, void *);
extern void fn_80071F84(V3 *, V3 *, V3 *);
extern void njPushMatrixEx(void);
extern void njPopMatrixEx(void);
extern void njRotateX(NJS_MATRIX m, Angle a);
extern void njRotateY(NJS_MATRIX m, Angle a);
extern void njRotateZ(NJS_MATRIX m, Angle a);
extern void fn_80286EE8(void);
extern void fn_8028B498(void);
typedef struct G800624FC {
    u8 pad0[0xc];
    f32 fc;
    u8 pad10[8];
    f32 f18;
    u8 pad1c[4];
    f32 f20;
} G800624FC;
typedef struct S800624FC {
    void *p0;
    f32 f4;
    f32 f8;
    u8 padC[2];
    s16 s0e;
    s16 s10;
} S800624FC;
typedef struct O800624FC {
    u8 pad0[0x18];
    u8 flags;
    u8 state;
    u8 pad1A[10];
    S800624FC *s;
} O800624FC;
extern G800624FC *lbl_80346BD8;
extern void fn_80075FF0(void *, s32, s32);
typedef struct G80064CA4 {
    u8 pad0[0x3c];
    f32 v[3];
    u8 pad48[0x7c - 0x48];
    u32 f7c;
} G80064CA4;
typedef struct U80064CA4 {
    u8 pad0[6];
    s16 kind;
} U80064CA4;
typedef struct W80064CA4 {
    u8 pad0[0x24];
    struct { u8 pad[0x4c]; U80064CA4 *u; } *work;
} W80064CA4;
typedef struct S80064CA4 {
    W80064CA4 *p0;
    u8 pad4[0x3c - 4];
    f32 v[3];
    u8 pad48[0x80 - 0x48];
    s16 s80;
} S80064CA4;
typedef struct O80064CA4 {
    u8 pad0[0x18];
    u8 flags;
    u8 state;
    u8 pad1A[10];
    S80064CA4 *s;
} O80064CA4;
typedef struct Chr { u8 pad[0x1C]; u32 bits; } Chr;
typedef struct Tk { u8 pad[0x19]; u8 state; } Tk;
extern u8 lbl_8030B7F4[];
extern s32 lbl_80347330;
extern s32 lbl_8034732C;
extern Tk* lbl_80347318;
extern void fn_8007D32C(void);
extern f32 njSin(s32 a);
extern f32 njCos(s32 a);
extern void njTranslate(NJS_MATRIX m, f32 x, f32 y, f32 z);
typedef struct Eff {
    u8 pad0[4];
    u32 x4;
    s16 x8;
    u8 padA[6];
    f32 x10;
    u8 pad14[0x30 - 0x14];
    f32 x30;
    f32 x34;
    f32 x38;
    u8 pad3c[0x48 - 0x3C];
    f32 x48;
    f32 x4c;
    u8 pad50[0x64 - 0x50];
} Eff;
typedef struct Task {
    u8 pad0[0x19];
    u8 state;
    u8 pad1a[0x24 - 0x1A];
    u8* work;
} Task;
typedef struct TblEnt_8006B46C { void* f0; void* f4; u32 f8; u8 fc; u8 pad[3]; } TblEnt_8006B46C;
extern void* memset(void*, int, u32);
extern void fn_8006B8A8(Eff*);

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

void fn_8005C188(O5C188 *o) {
    S5C188 *s = o->s;
    U5C188 *u = s->target->work->u;
    switch (o->state) {
    case 0: {
        s16 idx = fn_8001FDD8(s->target->work, s->rec->s14, s->rec->s16);
        if (idx >= 0) {
            if (s->rec->f10 & 0x80000000) {
                u->ff0 |= 0x40000;
            }
            if (s->rec->f10 & 0x40000000) {
                u->ff0 |= 0x20000;
            }
            u->s204 = idx;
        } else {
            o->state = 0xfa;
            break;
        }
        if (lbl_8034733C == 5) {
            o->state = 1;
        }
        break;
    }
    case 1:
        if (u->f50 & 0x40000000) {
            o->state = 0xfa;
        } else if (fn_80014C90(u->id, 2) == 0) {
            if (!(u->ff0 & 0x80000)) {
                if (u->ff0 & 0x4000000) {
                    o->state = 0xfa;
                } else {
                    u->ff0 &= ~0x40000;
                    u->ff0 &= ~0x20000;
                    u->s204 = 0;
                    switch (u->kind) {
                    case 0xb:
                    case 0x20:
                        break;
                    default:
                        fn_80075F2C(s->target);
                    }
                    o->state = 0xfa;
                }
            }
        }
        break;
    case 0xfa:
        o->flags |= 0x40;
        (*(G5C188*)&lbl_8030A10C).count--;
        break;
    }
}

void fn_8005C328(O5C328 *o) {
    S5C328 *s = o->s;
    U5C328 *u = s->target->work->u;
    switch (o->state) {
    case 0:
        switch (s->rec->kind) {
        case 0: {
            s8 idx;
            u->ff0 |= 0x40000000;
            idx = fn_8025ECC4() % s->rec->count;
            fn_80071CF0(&s->rec->vecs[idx], &s->target->work->pos);
            s->target->work->i2c = 182.04445f * s->rec->angs[idx];
            break;
        }
        case 1:
            u->ff0 &= ~0x40000000;
            fn_80071CF0(&u->v110, &s->target->work->pos);
            s->target->work->i2c = 0;
            break;
        }
        o->state = 0xfa;
        break;
    case 0xfa:
        o->flags |= 0x40;
        (*(G5C328*)&lbl_8030A10C).count--;
        break;
    }
}

void fn_8005D47C(O5D47C *o) {
    V3 *a;
    V3 *b;
    switch (o->state) {
    case 0:
        if (o->s70 < o->p->s14) {
            return;
        }
        fn_80014AB8(1, o);
        o->state = 1;
        if (o->p->flags & 0x2000) {
            o->b74 = fn_8025ECC4() % 3;
        }
    case 1:
        if (o->p->flags & 0x2000) {
            switch (o->b74) {
            case 0:
                a = &o->p->v1c;
                b = &o->p->v28;
                break;
            case 1:
                a = &o->p->v34;
                b = &o->p->v40;
                break;
            case 2:
                a = &o->p->v4c;
                b = &o->p->v58;
                break;
            }
        } else {
            a = &o->p->v1c;
            b = &o->p->v28;
        }
        if (o->p->flags & 0x10000) {
            fn_80071CF0(a, &o->v20);
            fn_80071CF0(b, &o->v38);
        } else {
            fn_8001E4A0(a, &o->v20, o->p78);
            if ((o->p->flags & 0x80000) && o->p7c != 0) {
                fn_80061518(&o->p->v68, &o->v38, o->p7c);
            } else {
                fn_8001E4A0(b, &o->v38, o->p78);
            }
        }
        fn_80071F84(&o->v2c, &o->v38, &o->v20);
        break;
    }
}

void fn_80060DFC(NJS_POINT3 *out, NJS_POINT3 *a, NJS_POINT3 *b, f32 unused, f32 angle, f32 scale) {
    extern void njPushMatrixEx(void);
    extern void njPopMatrixEx(void);
    extern void njRotateY(NJS_MATRIX m, Angle a);
    extern void fn_80286EE8(void);
    extern void fn_8028B498(void);
    extern f32 fn_80071E9C(NJS_POINT3 *, NJS_POINT3 *);
    extern void fn_80071F84(s32 *, NJS_POINT3 *, NJS_POINT3 *);
    extern void fn_80061450(NJS_POINT3 *, NJS_POINT3 *, NJS_POINT3 *);
    NJS_POINT3 p;
    NJS_POINT3 r;
    NJS_POINT3 q;
    NJS_POINT3 t;
    s32 ang[3];
    f32 dist;
    dist = fn_80071E9C(a, b);
    dist *= 0.5f;
    fn_80071F84(ang, a, b);
    p.z = dist;
    p.x = 0.0f;
    p.y = 0.0f;
    njPushMatrixEx();
    fn_80286EE8();
    fn_8028B498();
    njUnitMatrix(0);
    njRotateY(0, (s32)(182.04445f * angle));
    njCalcPoint(0, &p, &q);
    njPopMatrixEx();
    q.x = q.x * scale;
    njPushMatrixEx();
    fn_80286EE8();
    fn_8028B498();
    njUnitMatrix(0);
    njRotateY(0, ang[1]);
    njCalcPoint(0, &q, &r);
    njPopMatrixEx();
    fn_80061450(a, b, &t);
    out->x = r.x + t.x;
    out->y = r.y + t.y;
    out->z = r.z + t.z;
}

s32 fn_800611C0(V3 *a, V3 *b, V3 *c) {
    f32 zero = 0.0f;
    s32 ret = 0;
    V3 t;
    s32 i;
    f32 *pc;
    f32 *pa;
    f32 *pt;
    if (c->x == zero) {
        a->x = b->x;
    }
    if (c->y == zero) {
        a->y = b->y;
    }
    if (c->z == zero) {
        a->z = b->z;
    }
    if (a->x == b->x && a->z == b->z && a->y == b->y) {
        return 1;
    }
    fn_80071CF0(b, &t);
    pc = &c->x + 3;
    pa = &a->x + 3;
    pt = &t.x + 3;
    for (i = 0; i < 3; i++) {
        pa--;
        pc--;
        pt--;
        *pa = *pa + *pc;
        if (*pc > 0.0f) {
            if (*pa >= *pt) {
                *pa = *pt;
            }
        } else {
            if (*pa <= *pt) {
                *pa = *pt;
            }
        }
    }
    if (a->x == b->x && a->z == b->z && a->y == b->y) {
        ret = 1;
    }
    return ret;
}

void fn_80061654(NJS_POINT3 *a, NJS_POINT3 *b, NJS_POINT3 *rot, NJS_POINT3 *out, NJS_POINT3 *extra) {
    extern void njPushMatrixEx(void);
    extern void njPopMatrixEx(void);
    extern void njRotateXYZ(NJS_MATRIX m, Angle x, Angle y, Angle z);
    extern void fn_80286EE8(void);
    extern void fn_8028B498(void);
    extern void fn_80071CF0(NJS_POINT3 *, NJS_POINT3 *);
    extern void fn_8001E50C(NJS_POINT3 *, NJS_POINT3 *, NJS_POINT3 *);
    NJS_POINT3 d;
    NJS_POINT3 q;
    NJS_POINT3 p;
    Angle ax, ay, az;
    d.x = a->x - b->x;
    d.y = a->y - b->y;
    d.z = a->z - b->z;
    ax = 182.04445f * rot->x;
    ay = 182.04445f * rot->y;
    az = 182.04445f * rot->z;
    p.x = d.x;
    p.y = d.y;
    p.z = d.z;
    njPushMatrixEx();
    fn_80286EE8();
    fn_8028B498();
    njUnitMatrix(0);
    njRotateXYZ(0, ax, ay, az);
    njCalcPoint(0, &p, &q);
    njPopMatrixEx();
    out->x = q.x;
    out->y = q.y;
    out->z = q.z;
    out->x = out->x + b->x;
    out->y = out->y + b->y;
    out->z = out->z + b->z;
    if (extra != 0) {
        fn_80071CF0(out, &d);
        fn_8001E50C(&d, out, extra);
    }
}

void fn_800617A8(NJS_POINT3 *out, NJS_POINT3 *a, NJS_POINT3 *b, f32 scale, f32 angle) {
    extern void njPushMatrixEx(void);
    extern void njPopMatrixEx(void);
    extern void njRotateY(NJS_MATRIX m, Angle a);
    extern void fn_80286EE8(void);
    extern void fn_8028B498(void);
    extern f32 fn_80071E9C(NJS_POINT3 *, NJS_POINT3 *);
    extern void fn_80071F84(s32 *, NJS_POINT3 *, NJS_POINT3 *);
    NJS_POINT3 p;
    NJS_POINT3 q;
    s32 ang[3];
    f32 half;
    half = fn_80071E9C(a, b);
    half *= 0.5f;
    p.x = 0.0f;
    p.y = 0.0f;
    if (a->z > b->z) {
        p.z = half;
        fn_80071F84(ang, a, b);
    } else {
        p.z = -half;
        fn_80071F84(ang, b, a);
    }
    njPushMatrixEx();
    fn_80286EE8();
    fn_8028B498();
    njUnitMatrix(0);
    njRotateY(0, (s32)(182.04445f * angle));
    njCalcPoint(0, &p, &q);
    njPopMatrixEx();
    q.x = q.x * scale;
    q.y = q.x;
    q.x = 0.0f;
    if (q.y < 0.0f) {
        q.y *= -1.0f;
    }
    out->x = q.x;
    out->y = q.y;
    out->z = q.z;
}

void fn_800618FC(NJS_POINT3 *out, NJS_POINT3 *a, NJS_POINT3 *b, f32 angZ, f32 angY, f32 offset) {
    extern void njPushMatrixEx(void);
    extern void njPopMatrixEx(void);
    extern void njRotateY(NJS_MATRIX m, Angle a);
    extern void njRotateZ(NJS_MATRIX m, Angle a);
    extern void fn_80286EE8(void);
    extern void fn_8028B498(void);
    extern f32 fn_80071E9C(NJS_POINT3 *, NJS_POINT3 *);
    extern void fn_80071F84(s32 *, NJS_POINT3 *, NJS_POINT3 *);
    extern void fn_80061450(NJS_POINT3 *, NJS_POINT3 *, NJS_POINT3 *);
    NJS_POINT3 p;
    NJS_POINT3 q3;
    NJS_POINT3 q1;
    NJS_POINT3 q2;
    NJS_POINT3 t;
    s32 ang[3];
    f32 half;
    half = fn_80071E9C(a, b);
    half *= 0.5f;
    half += offset;
    fn_80071F84(ang, a, b);
    p.z = half;
    p.x = 0.0f;
    p.y = 0.0f;
    njPushMatrixEx();
    fn_80286EE8();
    fn_8028B498();
    njUnitMatrix(0);
    njRotateY(0, (s32)(182.04445f * angY));
    njCalcPoint(0, &p, &q1);
    njPopMatrixEx();
    njPushMatrixEx();
    fn_80286EE8();
    fn_8028B498();
    njUnitMatrix(0);
    njRotateZ(0, (s32)(182.04445f * angZ));
    njCalcPoint(0, &q1, &q2);
    njPopMatrixEx();
    njPushMatrixEx();
    fn_80286EE8();
    fn_8028B498();
    njUnitMatrix(0);
    njRotateY(0, ang[1]);
    njCalcPoint(0, &q2, &q3);
    njPopMatrixEx();
    fn_80061450(a, b, &t);
    out->x = q3.x + t.x;
    out->y = q3.y + t.y;
    out->z = q3.z + t.z;
}

void fn_80061C80(NJS_POINT3 *out, s8 mode, f32 a, f32 b, f32 z) {
    NJS_POINT3 p;
    NJS_POINT3 q;
    NJS_POINT3 tmp;
    p.z = z;
    p.x = 0.0f;
    p.y = 0.0f;
    njPushMatrixEx();
    fn_80286EE8();
    fn_8028B498();
    njUnitMatrix(0);
    switch (mode) {
    case 1:
        njRotateZ(0, (s32)(182.04445f * a));
        njRotateY(0, (s32)(182.04445f * b));
        njCalcPoint(0, &p, &q);
        break;
    case 0:
        njRotateX(0, (s32)(182.04445f * a));
        njRotateY(0, (s32)(182.04445f * b));
        njCalcPoint(0, &p, &q);
        break;
    case 2:
        njRotateY(0, (s32)(182.04445f * b));
        njCalcPoint(0, &p, &tmp);
        njRotateX(0, (s32)(182.04445f * a));
        njCalcPoint(0, &tmp, &q);
        break;
    }
    njPopMatrixEx();
    out->x = q.x;
    out->y = q.y;
    out->z = q.z;
}

void fn_800624FC(O800624FC *o) {
    S800624FC *s = o->s;
    void *p = s->p0;
    switch (o->state) {
    case 0:
        o->state = 1;
        s->f4 = (lbl_80346BD8->f18 + lbl_80346BD8->fc) / (f32)s->s0e;
        s->f8 = (lbl_80346BD8->f18 + lbl_80346BD8->fc) / (f32)(s->s10 - s->s0e);
    case 1:
        lbl_80346BD8->f20 = lbl_80346BD8->f20 - s->f4;
        if (lbl_80346BD8->f20 + lbl_80346BD8->fc <= 0.0f) {
            lbl_80346BD8->f20 = -lbl_80346BD8->fc;
            o->state = 2;
            fn_80075FF0(p, 0xf, -1);
        }
        break;
    case 2:
        lbl_80346BD8->f20 = lbl_80346BD8->f20 + s->f8;
        if (lbl_80346BD8->f20 >= lbl_80346BD8->f18) {
            lbl_80346BD8->f20 = lbl_80346BD8->f18;
            o->state = 3;
        }
        break;
    case 3:
        o->state = 4;
        break;
    case 4:
        o->flags |= 0x40;
        break;
    }
}

void fn_80064CA4(O80064CA4 *o) {
    S80064CA4 *s = o->s;
    U80064CA4 *u = s->p0->work->u;
    if (o->state != 3) {
        if (u->kind != s->s80) {
            if (s->s80 != 7) {
                o->state = 2;
            } else {
                (*(G80064CA4 **)&lbl_80346BD8)->v[0] = 0.0f;
                (*(G80064CA4 **)&lbl_80346BD8)->v[1] = 0.0f;
                (*(G80064CA4 **)&lbl_80346BD8)->v[2] = 0.0f;
                o->state = 3;
            }
        }
    }
    if ((*(G80064CA4 **)&lbl_80346BD8)->f7c & 0x40000000) {
        return;
    }
    switch (o->state) {
    case 0:
        o->state = 1;
    case 1:
        (*(G80064CA4 **)&lbl_80346BD8)->v[0] = (*(G80064CA4 **)&lbl_80346BD8)->v[0] + s->v[0];
        (*(G80064CA4 **)&lbl_80346BD8)->v[1] = (*(G80064CA4 **)&lbl_80346BD8)->v[1] + s->v[1];
        (*(G80064CA4 **)&lbl_80346BD8)->v[2] = (*(G80064CA4 **)&lbl_80346BD8)->v[2] + s->v[2];
        break;
    case 2: {
        s32 i;
        s32 n = 0;
        for (i = 0; i < 3; i++) {
            f32 x = (*(G80064CA4 **)&lbl_80346BD8)->v[i];
            if (x > 0.0f) {
                (*(G80064CA4 **)&lbl_80346BD8)->v[i] += 10.0f;
                if ((*(G80064CA4 **)&lbl_80346BD8)->v[i] >= 360.0f) {
                    (*(G80064CA4 **)&lbl_80346BD8)->v[i] = 0.0f;
                    n++;
                }
            } else {
                (*(G80064CA4 **)&lbl_80346BD8)->v[i] = x - 10.0f;
                if ((*(G80064CA4 **)&lbl_80346BD8)->v[i] <= 0.0f) {
                    (*(G80064CA4 **)&lbl_80346BD8)->v[i] = 0.0f;
                    n++;
                }
            }
        }
        if (n == 3) {
            o->state = 3;
        }
        break;
    }
    case 3:
        o->flags |= 0x40;
        break;
    }
}

void fn_8007181C(void) {
    if (lbl_80309174[0].x0 == 8) {
        lbl_80347330--;
        lbl_8034733C = 2;
        lbl_80347338 = 0;
        fn_8007D32C();
        lbl_80309174[1].x0 = 11;
        lbl_80309174[2].x0 = 11;
        lbl_80309174[3].x0 = 11;
        return;
    }
    if (lbl_80347330 < 0) {
        lbl_80347330 = 0;
        lbl_8034732C = 0;
    }
    while (1) {
        u32 bits;
        if (lbl_80347330 > 3) {
            lbl_80347330--;
            lbl_8034733C = 2;
            lbl_80347338 = 0;
            fn_8007D32C();
            return;
        }
        if ((s8)lbl_8030B7F4[lbl_80347330 + 0x328] == -1) {
            lbl_80347330--;
            lbl_8034733C = 2;
            lbl_80347338 = 0;
            fn_8007D32C();
            return;
        }
        bits = (*(Chr*(*)[12])&lbl_80309DE4)[lbl_80347330]->bits;
        if (!(bits & 0x6D00)) {
            lbl_80347338 = 2;
            lbl_80347318->state = 1;
            return;
        }
        if (bits & 0x800) {
            lbl_80309174[lbl_80347330].x0 = 3;
            lbl_80309174[lbl_80347330].x4 = -1;
        }
        lbl_80347330++;
        lbl_8034732C++;
    }
}

void fn_80071D0C(f32 dist, NJS_POINT3* out, NJS_POINT3* pos, Angle* ang) {
    NJS_POINT3 zero;
    NJS_POINT3 res;
    f32 x, y, z;

    x = -njSin(ang[1]) * njCos(ang[0]);
    y = njSin(ang[0]);
    z = -njCos(ang[1]) * njCos(ang[0]);
    x *= -dist;
    y *= -dist;
    z *= -dist;
    njPushMatrixEx();
    fn_80286EE8();
    fn_8028B498();
    zero.x = 0.0f;
    zero.y = 0.0f;
    zero.z = 0.0f;
    njUnitMatrix(0);
    njTranslate(0, pos->x, pos->y, pos->z);
    njTranslate(0, x, y, z);
    njCalcPoint(0, &zero, &res);
    out->x = res.x;
    out->y = res.y;
    out->z = res.z;
    njPopMatrixEx();
}

static inline u32 get_f8(s16 idx) {
    if (idx >= 4) {
        return 0;
    }
    return lbl_80309E88[idx].f8;
}

void fn_8006B46C(Task* t) {
    Eff* e = (Eff*)(t->work + 0x28);
    switch (t->state) {
    case 0:
        memset(e, 0, 0x64);
        e->x8 = 1;
        e->x30 = 0.1f;
        e->x34 = 0.5f;
        e->x38 = 0.3f;
        e->x10 = 60.0f;
        e->x48 = 80.0f;
        e->x4c = 300.0f;
        t->state = 1;
    case 1:
        e->x4 |= 0x40000000;
        t->state = 3;
        break;
    case 3:
        fn_8006B8A8(e);
        if (get_f8(e->x8) == 1) {
            t->state = 5;
        }
        break;
    case 5:
        if (get_f8(e->x8) == 0) {
            t->state = 3;
        }
        break;
    }
}
