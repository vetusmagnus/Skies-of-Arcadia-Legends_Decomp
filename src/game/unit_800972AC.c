#include "types.h"
#include "string.h"
#include <math.h>
#include "ninja.h"
#include "game/drawstate.h"
#include "game/task.h"
#include "game/evobj.h"
#include <dolphin/os/OSFastCast.h>
#include "game/unit_800972AC.h"
typedef struct Obj12 {
    u8 pad_00[0x12];
    u16 v12;
} Obj12;
extern s16 lbl_80346C3C;
extern s16 lbl_80346750;
extern s32 lbl_803473F8;
extern s32 lbl_803473F4;
extern u8 lbl_80303340[];
extern void *lbl_803473F0;
typedef struct Obj10 {
    u8 pad_00[0x10];
    u16 v10;
} Obj10;
typedef struct {
    s8 mode;
    u8 flags;
    s16 field2;
    u8 pad_04[0x70 - 4];
} SeFlagBlock;
extern SeFlagBlock lbl_802E0084;
extern s16 lbl_80302F18[408];
extern void fn_800D2CA8(s32 x);
s32 fn_80097B0C(s32 p);
typedef struct {
    s16 flag;
    s16 count;
} Entry8009B58C;
typedef struct {
    u8 pad_000[0x188];
    u32 flags188;
    u8 pad_18c[0x260 - 0x18C];
    Entry8009B58C *entry260;
} Obj8009B58C;
typedef struct {
    u8 pad_000[0x188];
    u32 flags188;
    u8 pad_18c[0x264 - 0x18C];
    Entry8009B58C *entry264;
} Obj8009B5D4;
extern u32 lbl_80346C40;
extern void* lbl_80347588;
void* fn_802267AC(void* a, void* b);
void fn_80096DA4(void);
extern u8 *lbl_80346C94;
extern s32 lbl_80346C90;
void fn_801E7DF0(void *);
extern void njScale(NJS_MATRIX m, f32 x, f32 y, f32 z);
void fn_801E17E0(void *);
extern f32 njCos(Angle a);
extern f32 njSin(Angle a);
/* Four separate .bss arrays of the unit, reached through its section base. */
extern s32 lbl_803033B0[6];
extern s32 lbl_803033C8[6];
extern s32 lbl_803033E0[6];
extern s32 lbl_803033F8[6];
extern void fn_800CAC04(s32 a, s32 b, s32 c, s32 d, f32 y, f32 sx, f32 sy);
s32 lbl_803033B0[6];
/* count */
s32 lbl_803033C8[6];
s32 lbl_803033E0[6];
s32 lbl_803033F8[6];
extern void fn_801DD14C(f32* a, f32* b, f32* c);
typedef struct {
    s16 state;          /* 0x00 */
    s16 flags;          /* 0x02 */
    u8 pad04[8];
    f32 f0C, f10, f14;  /* 0x0C */
    u8 pad18[0x30 - 0x18];
    f32 f30, f34, f38;  /* 0x30 */
    s32 i3C;            /* 0x3C */
    u8 pad40[0x58 - 0x40];
    f32 f58, f5C, f60, f64, f68, f6C; /* 0x58 */
    s32 i70, i74, i78;  /* 0x70 */
    u8 pad7C[0x94 - 0x7C];
    f32 v94[3];         /* 0x94 */
    f32 vA0[3];         /* 0xA0 */
    f32 fAC, fB0, fB4; /* 0xAC */
    u8 padB8[0xD0 - 0xB8];
    f32 fD0, fD4;       /* 0xD0 */
    s32 iD8;            /* 0xD8 */
    u8 padDC[0xE6 - 0xDC];
    s16 sE6;            /* 0xE6 */
    u8 padE8[0x100 - 0xE8];
    s32 i100, i104;     /* 0x100 */
    u8 pad108[0x16C - 0x108];
    s8 n16C;            /* 0x16C */
    u8 b16D;            /* 0x16D */
    s16 s16E;           /* 0x16E */
    f32 f170, f174, f178, f17C, f180, f184; /* 0x170 */
    s32 i188;           /* 0x188 */
    f32 f18C, f190, f194, f198, f19C, f1A0; /* 0x18C */
    s32 i1A4, i1A8, i1AC; /* 0x1A4 */
    f32 v1B0[3];        /* 0x1B0 */
    f32 f1BC;           /* 0x1BC */
    u16 u1C0, u1C2;     /* 0x1C0 */
    f32 f1C4;           /* 0x1C4 */
} Obj80097388;
typedef struct { f32 x, y; } V2;
typedef struct {
    s16 kind;       /* 0x00 */
    u8 pad02[2];
    V2 v04;         /* 0x04 */
    V2 v0C;         /* 0x0C */
    V2 v14;         /* 0x14 */
    f32 f1C;        /* 0x1C */
    f32 f20;        /* 0x20 */
    V2 v24;         /* 0x24 */
    V2 v2C;         /* 0x2C */
    V2 v34;         /* 0x34 */
    V2 v3C;         /* 0x3C */
    s32 i44;        /* 0x44 */
} Part8009B6B8;
typedef struct {
    V2 v00, v08, v10, v18, v20, v28, v30;
    s32 i38;
    f32 f3C;
} Src8009B6B8;
typedef struct {
    u8 pad00[0xE4];
    void* h_e4;               /* 0xE4 */
    u8 padE8[0x188 - 0xE8];
    u32 flags;                /* 0x188 */
    u8 pad18C[0x254 - 0x18C];
    f32 f254, f258;           /* 0x254 */
    Part8009B6B8* part;       /* 0x25C */
} Obj8009B6B8;
extern void* fn_801C8930(void* h);
extern void* fn_801DF988(void* h);
extern void fn_801E0CB8();
extern void fn_801E06E0();
typedef struct {
    u32 (*fn)(void*, Obj10*);  /* 0x00 */
    u8 pad04[0x10];
    s16 flags;         /* 0x14 */
} Sub8009C3D0;
typedef struct {
    u32 count;         /* 0x00 */
    u8 pad04[0x24];
    s32 v28;           /* 0x28 */
    s32 v2C;           /* 0x2C */
} Info8009C3D0;
typedef struct {
    u8 pad00[0x10];
    Info8009C3D0* info; /* 0x10 */
} Inner8009C3D0;
typedef struct {
    u8 pad00[0x1BC];
    Sub8009C3D0* sub;   /* 0x1BC */
    u8 pad1C0[8];
    Inner8009C3D0* inner; /* 0x1C8 */
} Owner8009C3D0;
extern void fn_800CD0B8(s32 a, s32 b, s32 c, s32 d);
extern void fn_800CCE0C(s32 a, s32 b);
extern void fn_80100B74(Task* t);
extern void fn_801DBE1C(const char* fmt, ...);
typedef struct { f32 x, y; f32 pad[4]; } Pt;
typedef struct {
    u8 pad[0x15c];
    Pt *pts;
    u8 pad2[0x178 - 0x160];
    f32 cx, cy;
} Obj;
extern s16 lbl_80346CA0;
extern f32 lbl_80346C70;
extern s32 lbl_80346C6C;
extern s32 lbl_80346C50;
extern f32 lbl_80345878[];
extern s32 lbl_80311AD4[11];
extern NJS_TEXLIST lbl_80347568;
extern u8 lbl_8030A318[];
extern u8 lbl_802F60B0[];
extern void njTranslate(NJS_MATRIX m, f32 x, f32 y, f32 z);
extern void njPushMatrixEx(void);
extern void njPopMatrixEx(void);
extern void fn_8028BB90(void* p);
extern void fn_8022B960(void* p);
extern void fn_80286EE8(void);
extern void fn_8028B498(void);
extern void fn_80287B38(void* p);
extern s32 fn_80097720(void);
extern s32 fn_80097CEC(s32 p);
/* Scales a 0..1 float to a u8 (x * 255) with the SDK fast cast (psq_st through GQR2).
 * The original calls the Dolphin SDK inline __OSf32tou8 from <dolphin/os/OSFastCast.h>.
 * The game code itself is plain C. Siblings: fn_8009E4B8 = __OSu8tof32(b) * K,
 * fn_8009E4D4 = __OSf32tou8((K0 + x) * 255). */
typedef unsigned char u8;
typedef float f32;
typedef struct {
    f32 f0;      /* 0x00 */
    f32 f4;      /* 0x04 */
    f32 f8;      /* 0x08 */
    f32 fc;      /* 0x0C */
    f32 f10;     /* 0x10 */
    u8 pad14[0x1C - 0x14];
    s16 lim;     /* 0x1C */
} Cfg;
extern Cfg* lbl_80346C7C;
extern void fn_800972AC(void);
typedef struct Camera {
    s16 mode;            /* 0x000 */
    s16 flags;           /* 0x002 */
    u8 pad_004[0x0c - 0x04];
    f32 pos[3];          /* 0x00C */
    u8 pad_018[0x30 - 0x18];
    f32 tgt[3];          /* 0x030 */
    s32 roll;            /* 0x03C */
    u8 pad_040[0x58 - 0x40];
    f32 v58[6];          /* 0x058 */
    s32 ang[3];          /* 0x070 */
    u8 pad_07c[0x94 - 0x7c];
    NJS_VECTOR dir;      /* 0x094 */
    NJS_VECTOR up;       /* 0x0A0 */
    u8 pad_0ac[0xd0 - 0xac];
    f32 fd0;             /* 0x0D0 */
    f32 fd4;             /* 0x0D4 */
    s32 xd8;             /* 0x0D8 */
    u8 pad_0dc[0xe6 - 0xdc];
    s16 xe6;             /* 0x0E6 */
    u8 pad_0e8[0x100 - 0xe8];
    s32 x100;            /* 0x100 */
    s32 x104;            /* 0x104 */
    u8 pad_108[0x16c - 0x108];
    s8 ret_mode;         /* 0x16C */
    u8 ret_flags;        /* 0x16D */
    s16 ret_e6;          /* 0x16E */
    f32 ret_pos[3];      /* 0x170 */
    f32 ret_tgt[3];      /* 0x17C */
    s32 ret_roll;        /* 0x188 */
    f32 ret_v58[6];      /* 0x18C */
    s32 ret_ang[3];      /* 0x1A4 */
    s32 ret_rot[3];      /* 0x1B0 */
    f32 ret_d4;          /* 0x1BC */
    u16 ret_d8;          /* 0x1C0 */
    u16 ret_100;         /* 0x1C2 */
    f32 ret_d0;          /* 0x1C4 */
} Camera;
extern void fn_801DD334(NJS_VECTOR *dir, NJS_VECTOR *up, s32 *rot);
typedef struct SrcHdr {
    u8 pad0[4];
    s16 count;      /* 0x04 */
    u8 pad6[2];
    SrcRec recs[1]; /* 0x08 */
} SrcHdr;
typedef struct Owner_8009877C {
    u8 pad0[8];
    SrcHdr **data;  /* 0x08 */
    u8 padc[0xBB08 - 0xC];
    s32 sub_count;  /* 0xBB08 */
    Particle *sub_nodes; /* 0xBB0C */
    s32 id;         /* 0xBB10 */
    s32 count;      /* 0xBB14 */
    Particle *nodes;    /* 0xBB18 */
} Owner_8009877C;
extern Particle *lbl_80346CB0;
extern void DCStoreRange(void *p, u32 n);
typedef struct Key {
    s32 time;       /* 0x00 */
    f32 val;        /* 0x04 */
} Key;
typedef struct Track {
    s16 flags;      /* 0x00 */
    s16 count;      /* 0x02 */
    u8 pad4[4];
    Key keys[1];    /* 0x08 */
} Track;
typedef struct Leaf {
    u8 pad0[0x24];
    f32 val[2];     /* 0x24 */
} Leaf;
typedef struct Obj_8009B3F4 {
    u8 pad0[0x202];
    s16 idx[2];     /* 0x202 */
    u8 pad206[0x20C - 0x206];
    s32 timer[2];   /* 0x20C */
    u8 pad214[0x24C - 0x214];
    f32 target[2];  /* 0x24C */
    u8 pad254[0x25C - 0x254];
    Leaf *leaf;     /* 0x25C */
    Track *track[2]; /* 0x260 */
} Obj_8009B3F4;
extern void njUnitMatrix(NJS_MATRIX m);
/* Byte (0..255) to a 0..1 float: __OSu8tof32(&b) * (1/255).
 * Needs the Dolphin SDK fast-cast inline __OSu8tof32 (psq_l through GQR2), which our
 * extern/sdk OSFastCast.h lacks. The SDK's definition is reproduced here only until it is
 * added to <dolphin/os/OSFastCast.h>; the game code itself is the one-line function. */
typedef unsigned char u8;
typedef struct Ent_8009884C {
    s16 h0;
    u8 pad2[0xc - 2];
    s32 w0c;
    f32 f10;
    f32 f14;
    s32 w18;
    s32 w1c;
    u8 pad20[4];
    f32 f24;
    s32 w28;
    s32 w2c;
    u8 pad30[4];
    f32 f34;
    s32 w38;
    s32 w3c;
    f32 f40;
    f32 f44;
    u8 pad48[4];
    s32 w4c;
    f32 f50;
    f32 f54;
    u8 pad58[0x8c - 0x58];
    f32 f8c;
    f32 f90;
    u8 pad94[0xb4 - 0x94];
} Ent_8009884C;
typedef struct Tab_8009CBBC {
    f32 a3[3];
    f32 b3[3];
    f32 c3[3];
    f32 d3[3];
    f32 e3[3];
    f32 f3[3];
    f32 a[6];
    f32 b[6];
    f32 c[6];
    f32 d[6];
    f32 e[6];
    f32 f[6];
} Tab_8009CBBC;
typedef struct Pos_8009CBBC {
    u8 pad0[0x38];
    f32 x;
    u8 pad3c[4];
    f32 z;
} Pos_8009CBBC;
extern Tab_8009CBBC lbl_802E0E18;
extern struct { u8 pad[0x88]; u32 flags; u8 pad8c[0x13C - 0x8C]; u32 x13c; } lbl_80310B3C;
extern Pos_8009CBBC* lbl_80347450;
extern u32 fn_80218DC4(void);
extern void sndSeqSetMidiCtrl(u32 id, u8 ch, s32 ctrl, s32 val);
/* Sliding object (fn_8009BED8): moves by an offset from EvExt.target when a switch entry flips. */
typedef struct EvInfoSlide {
    u32 count;     /* 0x00 */
    u8 pad4[0x24 - 0x4];
    u32 key;       /* 0x24 fn_800CCC48 switch */
    s32 ofs[3];    /* 0x28 offset in the object's frame */
    u32 frames;    /* 0x34 */
} EvInfoSlide;
typedef struct Entry_800CCC48 {
    u32 a;
    u32 b;
    u32 c;
    u32 d;
} Entry_800CCC48;
extern s32 fn_801006C0(EvObj* o);
extern Entry_800CCC48* fn_800CCC48(u32 a, u32 b);
extern s32 fn_800C3518(EvObj* o);
extern void fn_801E66E0(EvObj* o);
extern void fn_800C3428(Task* t);
extern void fn_80222838(EvColl* c);
extern s32 fn_8025ECC4(void);

void fn_800972AC(void)
{
    lbl_802E0084.mode = 0xf;
    lbl_802E0084.field2 = 0;
}

void fn_800972C4(void)
{
    lbl_802E0084.mode = -1;
    lbl_802E0084.field2 = 0;
    lbl_802E0084.flags = 0;
}

void fn_800972E0(s8 x) {
    if (x == 0) {
        lbl_802E0084.flags |= 0x2;
    } else {
        lbl_802E0084.flags &= ~0x2;
    }
}

void fn_80097318(s8 x) {
    if (x != 0) {
        lbl_802E0084.flags |= 0x1;
    } else {
        lbl_802E0084.flags &= ~0x1;
    }
}

void fn_80097350(s32 x) {
    if (x == 0) {
        lbl_80302F18[1] |= 0x8;
    } else {
        lbl_80302F18[1] &= ~0x8;
    }
}

BOOL fn_80097608(void *unused, Obj12 *p)
{
    return p->v12 == 1;
}

s32 fn_8009761C(s32 a, u16 b)
{
    s32 k = 0x10000;
    return (u16)(a + (k - 0x8000 - b)) - 0x8000;
}

s8 fn_8009763C(void)
{
    s32 r = -1;
    if (lbl_80346C3C == 2) {
        r = lbl_80302F18[0];
    }
    return (s8)r;
}

void fn_80097660(void)
{
    lbl_80346750 = 1;
}

void fn_800976EC(void)
{
    lbl_80346C3C = 1;
}

void fn_80097AFC(void)
{
    lbl_803473F8 = 0;
    lbl_803473F4 = 0;
}

void fn_80097CA4(s32 p) {
    fn_800D2CA8(0);
    fn_80097B0C(p);
}

void fn_80097CDC(void)
{
    lbl_803473F0 = lbl_80303340;
}

s32 fn_8009B58C(s32 unused, Obj8009B58C *obj, Entry8009B58C *e, s16 arg) {
    s32 ret = 0;
    s32 v = ((e->count - 1) * 8 + 16) / 4;
    if (v == arg) {
        obj->flags188 |= e->flag & 0x10000;
        obj->entry260 = e;
        ret = 1;
    }
    return ret;
}

s32 fn_8009B5D4(s32 unused, Obj8009B5D4 *obj, Entry8009B58C *e, s16 arg) {
    s32 ret = 0;
    s32 v = ((e->count - 1) * 8 + 16) / 4;
    if (v == arg) {
        obj->flags188 |= e->flag & 0x10000;
        obj->entry264 = e;
        ret = 1;
    }
    return ret;
}

u32 fn_8009C50C(void *unused, Obj10 *p)
{
    return (p->v10 >> 14) & 1;
}
void fn_8009CBB8(void) {
}

extern void njTranslate(NJS_MATRIX m, f32 x, f32 y, f32 z);

#define BSW(x) ((((x) >> 24) & 0xff) | (((x) >> 8) & 0xff00) | (((x) << 8) & 0xff0000) | ((x) << 24))

s32 fn_8009766C(void) {
    s32 r;
    void* obj;
    if (lbl_80346750 == 0) return 0;
    lbl_80346C40 = 0;
    r = 0;
    obj = fn_802267AC(lbl_80347588, (void*)fn_80096DA4);
    if (obj) {
        *(u8**)((u8*)obj + 0x24) = (u8*)lbl_80302F18;
        *(u32*)((u8*)lbl_80302F18 + 0x108) = 0;
        *(u32*)((u8*)lbl_80302F18 + 0x128) = 0;
        lbl_80346750 = 0;
        r = 1;
    }
    return r;
}

void fn_800986C8(u8 *obj, u8 *src, s32 count) {
    u8 *dst;
    s32 i;
    dst = lbl_80346C94;
    *(s32 *)obj = 1;
    *(s32 *)(obj + 0xbb08) = count;
    *(u8 **)(obj + 0xbb0c) = dst;
    lbl_80346C94 = lbl_80346C94 + count * 0xb4;
    lbl_80346C90 = lbl_80346C90 + count;
    for (i = 0; i < count;) {
        if (*(s32 *)src != 0) {
            memset(dst, 0, 0xb4);
            *(u8 **)(dst + 4) = src + 4;
            *(s16 *)dst = 1;
            *(f32 *)(dst + 0x8c) = *(f32 *)(src + 0x178);
            *(f32 *)(dst + 0x90) = *(f32 *)(src + 0x17c);
        }
        i++;
        dst += 0xb4;
        src += 0x180;
    }
}

s32 fn_8009B61C(void *unused, u8 *obj, s16 *d) {
    (void)unused;
    fn_801E7DF0(*(void **)(obj + 0xe4));
    *(s16 *)(obj + 0x1fe) = d[1];
    *(s16 *)(obj + 0x200) = d[0];
    *(s32 *)(obj + 0x188) |= 1;
    if (d[1] != 0 && d[0] != 0) {
        *(s16 *)(obj + 0x1fc) = 2;
    } else if (d[1] != 0) {
        *(s16 *)(obj + 0x1fc) = 0;
    } else {
        *(s16 *)(obj + 0x1fc) = 1;
    }
    return 0;
}

void fn_8009B8F0(u8 *obj) {
    void *s;
    f32 *f;
    s = fn_801DF988(fn_801C8930(*(void **)(obj + 0xe4)));
    if (s != 0) {
        f = (f32 *)s;
        *(void **)(obj + 0x25c) = s;
        *(s16 *)s = 0;
        f[1] = *(f32 *)(obj + 0x38);
        f[2] = *(f32 *)(obj + 0x3c);
        f[3] = *(f32 *)(obj + 0x40);
        f[6] = 0.0f;
        f[4] = 0.0f;
        f[7] = 0.0f;
        f[5] = 1.0f;
        f[9] = 36.0f;
        f[10] = 5.0f;
        f[13] = -65536.0f;
        f[12] = -65536.0f;
        f[11] = -65536.0f;
        f[16] = 65536.0f;
        f[15] = 65536.0f;
        f[14] = 65536.0f;
        f[8] = 0.5f;
        fn_801E06E0(s);
        *(s32 *)(obj + 0x188) |= 2;
    }
}

void fn_800974CC(Obj80097388* o) {
    if (o->state != 0) {
        o->n16C = o->state;
        o->b16D = o->flags & 0xA;
        o->s16E = o->sE6;
        if (o->state == 6) {
            o->f170 = o->fAC;
            o->f174 = o->fB0;
            o->f178 = o->fB4;
        } else {
            o->f170 = o->f0C;
            o->f174 = o->f10;
            o->f178 = o->f14;
        }
        o->f17C = o->f30;
        o->f180 = o->f34;
        o->f184 = o->f38;
        o->i188 = o->i3C;
        o->f18C = o->f58;
        o->f190 = o->f5C;
        o->f194 = o->f60;
        o->f198 = o->f64;
        o->f19C = o->f68;
        o->f1A0 = o->f6C;
        o->i1A4 = o->i70;
        o->i1A8 = o->i74;
        o->i1AC = o->i78;
        fn_801DD14C(o->v1B0, o->v94, o->vA0);
        o->f1BC = o->fD4;
        o->u1C0 = o->iD8;
        o->u1C2 = o->i100;
        o->f1C4 = o->fD0;
    } else {
        o->n16C = 0;
    }
    o->flags &= ~4;
}

s32 fn_8009B6B8(s32 unused, Obj8009B6B8* o, Src8009B6B8* src) {
    s32 ok = 0;
    Part8009B6B8* p = o->part;

    if (p == 0) {
        p = fn_801DF988(fn_801C8930(o->h_e4));
    }
    if (p != 0) {
        o->part = p;
        p->kind = 1;
        p->v04 = src->v00;
        p->v0C = src->v08;
        p->v14 = src->v10;
        p->v24 = src->v18;
        o->f254 = p->v24.x;
        o->f258 = p->v24.y;
        p->v2C = src->v20;
        p->v34 = src->v28;
        p->v3C = src->v30;
        p->i44 = src->i38;
        p->f20 = src->f3C;
        p->f1C = 0.0f;
        fn_801E0CB8();
        ok = 1;
        o->flags |= 2;
    }
    return ok;
}

s32 fn_8009B7D4(s32 unused, Obj8009B6B8* o, Src8009B6B8* src) {
    s32 ok = 0;
    Part8009B6B8* p = o->part;

    if (p == 0) {
        p = fn_801DF988(fn_801C8930(o->h_e4));
    }
    if (p != 0) {
        o->part = p;
        p->kind = 0;
        p->v04 = src->v00;
        p->v0C = src->v08;
        p->v14 = src->v10;
        p->v24 = src->v18;
        o->f254 = p->v24.x;
        o->f258 = p->v24.y;
        p->v2C = src->v20;
        p->v34 = src->v28;
        p->v3C = src->v30;
        p->i44 = src->i38;
        p->f20 = src->f3C;
        p->f1C = 0.0f;
        fn_801E06E0();
        ok = 1;
        o->flags |= 2;
    }
    return ok;
}

void fn_8009C3D0(Task* t) {
    Owner8009C3D0* o = t->work;
    Sub8009C3D0* s;

    switch (t->state) {
    case 0:
        if (o->inner->info->count >= 0xB && o->sub != 0) {
            o->sub->fn = fn_8009C50C;
            t->state = 1;
        } else {
            t->state = 4;
        }
        break;
    case 1:
        s = o->sub;
        if (s->flags & 0x4000) {
            fn_800CD0B8(2, o->inner->info->v2C, 0, o->inner->info->v28);
            s->flags = 0;
            t->state = 2;
        }
        break;
    case 2:
        fn_800CCE0C(2, o->inner->info->v2C);
        t->state = 3;
    case 3:
        s = o->sub;
        if (!(s->flags & 0x4000)) {
            t->state = 1;
        }
        s->flags = 0;
        break;
    case 0xFE:
        break;
    default:
        fn_80100B74(t);
        break;
    }
}

void fn_800996D8(Obj *o) {
    f32 sx = 0.0f, sy = 0.0f;
    int n = lbl_80346CA0;
    Pt *p = o->pts;
    Pt *q = p;
    Pt *r;
    f32 cx, cy;
    int i, j;
    for (i = n; i > 0; i--) {
        sx += q->x;
        sy += q->y;
        q++;
    }
    cx = sx / n;
    cy = sy / n;
    r = p;
    for (j = 0; j < lbl_80346CA0; j++) {
        r->x -= cx;
        r->y -= cy;
        r++;
    }
    o->cx = cx;
    o->cy = cy;
}

s32 fn_80097B0C(s32 p)
{
    s32 a;
    s32 b;
    s32 flag;
    s32 mode;
    s32 ret;
    switch (lbl_803473F8) {
    case 0:
        fn_8028BB90(lbl_8030A318);
        DrawStateDefault(1, (*(DrawState**)&lbl_803473F0));
        (*(DrawState**)&lbl_803473F0)->attr_or |= 0x100;
        lbl_80346C70 = 1.0f;
        lbl_80346C6C = 0;
        lbl_803473F8 = 1;
        lbl_80346C50 = 0;
        /* fallthrough */
    case 1:
        DrawStatePush((*(DrawState**)&lbl_803473F0));
        fn_8022B960(lbl_8030A318);
        njPushMatrixEx();
        fn_80286EE8();
        fn_8028B498();
        njUnitMatrix(0);
        njTranslate(0, 0.0f, 0.0f, -1.0f * lbl_80345878[6]);
        njScale(0, 0.9090909f, 1.0f, 1.0f);
        fn_80299040(&lbl_80347568);
        fn_80287B38(lbl_802F60B0);
        njPopMatrixEx();
        DrawStatePop(0);
        lbl_803473F8 = 2;
        break;
    case 2:
        ret = 0;
        mode = lbl_80311AD4[6];
        flag = 0;
        if (mode == 12 || mode == 13) flag = 1;
        if (flag) a = 1;
        else a = fn_80097720();
        b = fn_80097CEC(p);
        if (a && b) ret = 1;
        return ret;
    }
    return 0;
}

void fn_800976F8(void)
{
    lbl_80346C3C = 0;
    lbl_80346750 = 1;
    lbl_802E0084.mode = -1;
    lbl_802E0084.field2 = 0;
    lbl_802E0084.flags = 0;
}

void fn_800991AC(Particle* e, s32 n) {
    Cfg* c = lbl_80346C7C;
    f32 c0 = c->f0;
    f32 c1 = c->f4;
    f32 c2 = c->f8;
    f32 c3 = c->fc;
    f32 c4 = c->f10;
    s32 i;
    s32 lim = c->lim;
    f32 ang;
    s32 ia;
    f32 r;
    f32 d;
    f32 t;
    f32 t2;
    f32 t8;
    f32 nr;
    f32 sg;
    f32 at;
    f32 zero = 0.0f;

    for (i = 0; i < n; i++, e++) {
        if (e->delay > 0) {
            e->delay--;
        } else if (e->used != 0) {
            at = atan2(e->v[1], e->v[0]);
            ia = 10430.381f * at;
            ang = ia;
            r = e->v[0] / njCos(ang);
            r *= 1.0f + e->fb0;
            d = r - c0;
            t = (c4 - (f32)fabs(d)) / c4;
            t2 = t * t;
            t8 = t2 * t2;
            t8 = t8 * t8;
            if (e->step < lim) {
                t2 = t2 * e->step / lim;
                t8 = t8 * e->step / lim;
                e->step++;
            }
            if (d >= 0.0f) {
                nr = r - c2 * t2;
                if (nr < c0) {
                    nr = c0;
                }
            } else {
                nr = r;
            }
            ang += c1 * t2;
            e->v[0] = nr * njCos(ang);
            e->v[1] = nr * njSin(ang);
            sg = (f32)fabs(zero);
            if (c3 < zero) {
                sg = -sg;
            }
            if (zero == c3) {
                sg = zero;
            }
            e->v[2] += c3 * t8 + sg;
        }
    }
}

void fn_80097388(Camera *cam) {
    if (cam->ret_mode >= 15) {
        fn_801DBE1C("ERROR(retC): NO RETURN CAMERA MODE");
    }
    cam->mode = cam->ret_mode;
    if (cam->mode != 0 && cam->mode != 7) {
        cam->flags = cam->ret_flags;
        cam->xe6 = cam->ret_e6;
        cam->pos[0] = cam->ret_pos[0];
        cam->pos[1] = cam->ret_pos[1];
        cam->pos[2] = cam->ret_pos[2];
        cam->tgt[0] = cam->ret_tgt[0];
        cam->tgt[1] = cam->ret_tgt[1];
        cam->tgt[2] = cam->ret_tgt[2];
        cam->roll = cam->ret_roll;
        cam->v58[0] = cam->ret_v58[0];
        cam->v58[1] = cam->ret_v58[1];
        cam->v58[2] = cam->ret_v58[2];
        cam->v58[3] = cam->ret_v58[3];
        cam->v58[4] = cam->ret_v58[4];
        cam->v58[5] = cam->ret_v58[5];
        cam->ang[0] = cam->ret_ang[0];
        cam->ang[1] = cam->ret_ang[1];
        cam->ang[2] = cam->ret_ang[2];
        fn_801DD334(&cam->dir, &cam->up, cam->ret_rot);
        cam->fd4 = cam->ret_d4;
        cam->xd8 = cam->ret_d8;
        cam->x104 = cam->x100 = cam->ret_100;
        cam->fd0 = cam->ret_d0;
    } else {
        cam->mode = 0;
    }
    cam->flags |= 4;
}

s32 fn_8009877C(Owner_8009877C *o, s32 id)
{
    Particle *n = lbl_80346CB0;
    s32 count;
    SrcRec *src;
    s32 i;
    SrcHdr *h;

    o->id = id;
    h = *o->data;
    count = h->count;
    src = h->recs;
    for (i = 0; i < count; i++, n++, src++) {
        memset(n, 0, sizeof(Particle));
        n->used = 1;
        n->src = src;
        n->v[0] = src->v[0];
        n->v[1] = src->v[1];
        n->v[2] = src->v[2];
        n->v[3] = src->v[3];
        n->v[4] = src->v[4];
        n->v[5] = src->v[5];
        DCStoreRange(n, sizeof(Particle));
    }
    o->count = count;
    o->nodes = lbl_80346CB0;
    lbl_80346CB0 = n;
    return count;
}

void fn_80099078(Particle *n, s32 count)
{
    s32 i;
    s32 k;
    Axis *a;
    f32 *o;

    for (i = 0; i < count; i++, n++) {
        if (n->delay > 0) {
            n->delay--;
        } else if (n->used != 0) {
            o = n->v;
            a = n->axis;
            for (k = 0; k < 8; k++, a++, o++) {
                if (a->on != 0) {
                    a->val += a->spd;
                    *o += a->val;
                    if (a->lim && (f32)fabs(a->val) >= a->lim) {
                        a->spd *= 0.5;
                    }
                }
            }
        }
    }
}

s32 fn_8009B3F4(Obj_8009B3F4 *o)
{
    Track *t;
    Key *k;
    s32 ret = 1;

    o->leaf->val[0] += (o->target[0] - o->leaf->val[0]) / (f32)o->timer[0];
    o->timer[0]--;
    if (o->timer[0] <= 0) {
        t = o->track[0];
        k = t->keys;
        o->idx[0]++;
        if (t->count <= o->idx[0]) {
            if (!(t->flags & 1)) {
                o->idx[0] = t->count - 1;
                ret = 0;
            } else {
                o->idx[0] = 0;
            }
        }
        k += o->idx[0];
        o->timer[0] = k->time;
        o->target[0] = k->val;
    }
    return ret;
}

s32 fn_8009B4C0(Obj_8009B3F4 *o)
{
    Track *t;
    Key *k;
    s32 ret = 1;

    o->leaf->val[1] += (o->target[1] - o->leaf->val[1]) / (f32)o->timer[1];
    o->timer[1]--;
    if (o->timer[1] <= 0) {
        t = o->track[1];
        k = t->keys;
        o->idx[1]++;
        if (t->count <= o->idx[1]) {
            if (!(t->flags & 1)) {
                o->idx[1] = t->count - 1;
                ret = 0;
            } else {
                o->idx[1] = 0;
            }
        }
        k += o->idx[1];
        o->timer[1] = k->time;
        o->target[1] = k->val;
    }
    return ret;
}

void fn_8009884C(Ent_8009884C* e, s32 n, f32* v) {
    NJS_POINT3 vec;
    NJS_POINT3 out;
    f32 y;
    f32 zero;
    f32 xy;
    f32 x;
    f32 sgn;
    s32 i;
    x = v[0];
    y = v[1];
    sgn = 1.0f;
    zero = 0.0f;
    if (y < zero) {
        sgn = -1.0f;
        y = -y;
    }
    if (x != zero) {
        vec.x = 0.0f;
        vec.y = 0.0f;
        vec.z = y;
    }
    xy = y * x;
    for (i = 0; i < n; i++, e++) {
        Angle a2;
        Angle a1;
        f32 d;
        e->h0 = 1;
        a1 = (s32)(10430.381f * (f32)atan2(e->f90, e->f8c));
        a2 = (s32)(10430.381f * (f32)atan2(e->f8c / njCos(a1), x));
        d = x / njCos(a2);
        njPushMatrixEx();
        fn_80286EE8();
        fn_8028B498();
        njUnitMatrix(0);
        vec.z = xy / d;
        njRotateXYZ(0, 0, a2, a1);
        njCalcPoint(0, &vec, &out);
        njPopMatrixEx();
        e->f14 = e->f14 + out.x;
        e->f24 = e->f24 + out.y;
        e->f34 = out.z * sgn + e->f34;
        e->w0c = 1;
        e->w1c = 1;
        e->w2c = 1;
        e->f54 = 100.0f * out.x * sgn + e->f54;
        e->f50 = out.x * sgn + e->f50;
        e->w4c = 1;
        e->f44 = e->f44 - 100.0f * out.y * sgn;
        e->f40 = e->f40 - out.y * sgn;
        e->w3c = 1;
    }
}

/* |d| */
static inline f32 Abs(f32 d) {
    if (d < 0.0f) {
        d = -d;
    }
    return d;
}

/* distance on a wrapping axis of length lim */
static inline f32 Fold(f32 d, f32 lim) {
    if (d < lim - d) {
        return d;
    }
    return lim - d;
}

void fn_8009CBBC(void) {
    Tab_8009CBBC* t = &lbl_802E0E18;
    u32 id = fn_80218DC4();
    s32 i;
    f32* ta;
    f32* tb;
    f32* tc;
    f32* td;
    f32* te;
    f32* tf;
    f32 dx;
    f32 dz;
    f32 v;
    if (id != 0xFFFFFFFF && !(lbl_80310B3C.flags & 0x40000)) {
        ta = t->a;
        tb = t->b;
        tc = t->c;
        td = t->d;
        te = t->e;
        tf = t->f;
        for (i = 0; i < 6; i++) {
            dx = Abs(lbl_80347450->x - ta[i]);
            dz = Abs(lbl_80347450->z - tb[i]);
            dx = Fold(dx, 16800.0f);
            dz = Fold(dz, 14400.0f);
            if (dx > tc[i] || dz > td[i]) {
                v = 0.0f;
            } else if (dx < te[i]) {
                if (dz < tf[i]) {
                    v = 1.0f;
                } else {
                    v = 1.0f - (dz - tf[i]) / tf[i];
                }
            } else if (dz < tf[i]) {
                v = 1.0f - (dx - te[i]) / te[i];
            } else {
                f32 p = (dx - te[i]) / te[i];
                f32 q = (dz - tf[i]) / tf[i];
                v = 1.0f - ((p > q) ? p : q);
            }
            sndSeqSetMidiCtrl(id, i + 10, 7, (s32)(127.0f * v));
        }
    }
}

typedef struct Preset { s32 w0; s32 w4; } Preset;
extern Owner_8009877C* lbl_80346CB8;
extern void* lbl_80346CB4;
extern void* lbl_80346CAC;
extern void* lbl_80346C9C;
extern Particle* lbl_80346C8C;
extern s32 lbl_80346C88;
extern s32 lbl_80346C84;
extern s32 lbl_80346C80;
extern f32 lbl_80346CA4;
extern DrawState lbl_80303368;
extern u8 lbl_80303390[];
extern Preset lbl_802E0CB4[];
extern Preset lbl_802E0D04[];
extern s32 fn_8025ECC4(void);
extern void fn_80099830(void);
extern void fn_80098084(void);
extern void fn_80098DA4(void*);

static inline void UpdateParts(Owner_8009877C* pool) {
    s32 n = pool->count;
    s32 i;
    Particle* e;

    if (n == 0) {
        return;
    }
    e = pool->nodes;
    switch (pool->id) {
    case 0:
        for (i = 0; i < n; i++, e++) {
            SrcRec* src = e->src;
            f32 dx = e->v[0] / 30.0f;
            f32 dy = e->v[1] / 30.0f;
            e->v[2] = lbl_80346CA4 * (dx * dx) + lbl_80346CA4 * (dy * dy);
            src->v[2] = e->v[2];
        }
        break;
    }
}

s32 fn_80097CEC(s32 p) {
    Owner_8009877C* pool;
    Preset* tab;
    switch (lbl_803473F4) {
    case 0:
        njControl3D(0x810);
        njSetConstantAttr(-1, 0x800);
        fn_8028BB90(lbl_80303390);
        DrawStateDefault(1, &lbl_80303368);
        lbl_80303368.attr_or |= 0x100;
        if (p < 0) {
            s32 r = 10.0f * (0.000030517578f * fn_8025ECC4());
            lbl_80346C80 = r;
            if (p == -1) {
                tab = &lbl_802E0D04[r];
            } else {
                tab = &lbl_802E0CB4[r];
            }
        } else {
            lbl_80346C80 = p;
            tab = &lbl_802E0CB4[p];
        }
        lbl_80346CA0 = tab->w4;
        lbl_80346CA4 = 0.0f;
        lbl_80346C88 = tab->w0;
        lbl_80346C84 = 1;
        lbl_803473F4 = 1;
        fn_80099830();
    case 1:
        DrawStatePush(&lbl_80303368);
        fn_80098084();
        fn_80099078(lbl_80346C8C, 1);
        pool = lbl_80346CB8;
        if (pool->sub_count != 0) {
            UpdateParts(pool);
            if (lbl_80346C7C != 0) {
                fn_800991AC(pool->sub_nodes, pool->sub_count);
            }
            fn_80099078(pool->sub_nodes, pool->sub_count);
        }
        fn_80098DA4(lbl_80346C8C);
        DrawStatePop(0);
        lbl_80346CA4 = lbl_80346CA4 + 2.0f;
        if (lbl_80346CA4 >= 90.0f) {
            lbl_803473F4 = 2;
        }
        break;
    case 2:
        fn_801E17E0(lbl_80346CB8);
        lbl_80346CB8 = 0;
        fn_801E17E0(lbl_80346CB4);
        lbl_80346CB4 = 0;
        fn_801E17E0(lbl_80346CAC);
        lbl_80346CAC = 0;
        fn_801E17E0(lbl_80346C9C);
        lbl_80346C9C = 0;
        lbl_803473F4 = 3;
        return 1;
    case 3:
        return 1;
    }
    return 0;
}
void bss_order_stub(void);

/* state */

/* Layout stub, NOT part of the merge: MWCC lays the pooled .bss arrays out in order of first use in
 * the file. In the unit, fn_8009C518 (earlier) sets that order; this stub stands in for it here. */
void bss_order_stub(void) { lbl_803033B0[0] = 0; lbl_803033C8[0] = 0; lbl_803033E0[0] = 0; lbl_803033F8[0] = 0; }

void fn_8009CFD8(void) {
    s32 i;
    s32 y = 0x104;
    for (i = 0; i < 6; y -= 0x23, i++) {
        s32 n = lbl_803033B0[i];
        if (n > 0) {
            s32 s = lbl_803033F8[i];
            switch (s) {
            case 0:
            case 1:
            case 2: {
                f32 f = 0.5f * (s + 1);
                fn_800CAC04(lbl_803033E0[i], (s + 1) * 50, lbl_803033C8[i], 0xff, y, f, f);
                lbl_803033F8[i]++;
                break;
            }
            case 3: {
                s32 a, b;
                f32 sx, sy;
                if (n > 45) {
                    a = (n - 45) * 50;
                } else {
                    a = 0;
                }
                if (n >= 5) {
                    b = 0xff;
                    sx = 1.5f;
                    sy = 0.022222223f * (n - 5) + 1.5f;
                } else {
                    b = n * 50;
                    sy = 0.3f * n;
                    sx = sy;
                }
                fn_800CAC04(lbl_803033E0[i], b, lbl_803033C8[i], a, y, sx, sy);
                lbl_803033B0[i]--;
                if (lbl_803033B0[i] == 0) {
                    lbl_803033F8[i] = 0;
                }
                break;
            }
            }
        }
    }
}

void fn_8009BED8(Task* t) {
    EvObj* o;
    EvInfoSlide* info;
    Entry_800CCC48* e;
    NJS_POINT3 out;
    NJS_POINT3 v;
    f32 f;
    f32 n;

    o = t->work;
    if (t->state != 0 && t->state != 5 && fn_801006C0(o) == 0) {
        return;
    }
    info = o->ext->info;
    if (info->count >= 0xd) {
        e = fn_800CCC48(2, info->key);
        if (e == 0) {
            e = fn_800CCC48(2, -1);
        }
    } else {
        e = 0;
        info = 0;
    }
    switch (t->state) {
    case 0:
    case 0xfe:
        fn_800C3518(o);
        t->state = 1;
        break;
    case 1:
        if (e != 0 && e->c == 0) {
            t->state = 3;
            o->x180 = info->frames;
        }
        fn_801E66E0(o);
        break;
    case 2:
        if (e != 0 && e->c == 1) {
            t->state = 4;
            o->x180 = info->frames;
        }
        fn_801E66E0(o);
        break;
    case 3:
        o->x180--;
        if (o->x180 > 0) {
            n = info->frames;
            f = (n - o->x180) / n;
            v.x = info->ofs[0] * f;
            v.y = info->ofs[1] * f;
            v.z = info->ofs[2] * f;
        } else {
            v.x = info->ofs[0];
            v.y = info->ofs[1];
            v.z = info->ofs[2];
            t->state = 2;
        }
        njPushMatrixEx();
        fn_80286EE8();
        fn_8028B498();
        njUnitMatrix(0);
        njRotateXYZ(0, o->ang[0], o->ang[1], o->ang[2]);
        njCalcPoint(0, &v, &out);
        njPopMatrixEx();
        o->pos.x = o->ext->target.x + out.x;
        o->pos.y = o->ext->target.y + out.y;
        o->pos.z = o->ext->target.z + out.z;
        if (o->coll != 0) {
            o->coll->pos[0] = o->pos.x;
            o->coll->pos[1] = o->pos.y;
            o->coll->pos[2] = o->pos.z;
            fn_80222838(o->coll);
            o->coll->h14 = 0;
        }
        fn_801E66E0(o);
        break;
    case 4:
        o->x180--;
        if (o->x180 > 0) {
            f = info->frames;
            f = o->x180 / f;
            v.x = info->ofs[0] * f;
            v.y = info->ofs[1] * f;
            v.z = info->ofs[2] * f;
            njPushMatrixEx();
            fn_80286EE8();
            fn_8028B498();
            njUnitMatrix(0);
            njRotateXYZ(0, o->ang[0], o->ang[1], o->ang[2]);
            njCalcPoint(0, &v, &out);
            njPopMatrixEx();
            o->pos.x = o->ext->target.x + out.x;
            o->pos.y = o->ext->target.y + out.y;
            o->pos.z = o->ext->target.z + out.z;
        } else {
            o->pos.x = o->ext->target.x;
            o->pos.y = o->ext->target.y;
            o->pos.z = o->ext->target.z;
            t->state = 1;
        }
        if (o->coll != 0) {
            o->coll->pos[0] = o->pos.x;
            o->coll->pos[1] = o->pos.y;
            o->coll->pos[2] = o->pos.z;
            fn_80222838(o->coll);
            o->coll->h14 = 0;
        }
        fn_801E66E0(o);
        break;
    default:
        fn_800C3428(t);
        break;
    }
}

#ifdef NONMATCHING
typedef struct Spark {
    s32 on;
    f32 x;
    f32 y;
    f32 z;
} Spark;
typedef struct SparkSet {
    s16 active;
    u8 pad2[0xa];
    Spark s[8];
    u8 pad8C[0xb4 - 0x8c];
} SparkSet;
typedef struct SparkDef {
    s32 on;
    f32 xr;
    f32 xb;
    f32 wrap;
    f32 z;
    f32 yr;
    f32 yb;
    u8 pad1C[4];
} SparkDef;
typedef struct DvdFile {
    u8 pad0[0x34];
    u32 length;         /* 0x34 */
    u8 pad38[0x3C - 0x38];
} DvdFile;
typedef struct SampLoad {
    DvdFile file[2];    /* 0x00 */
    char path[2][0x40]; /* 0x78 */
} SampLoad;
extern SampLoad lbl_80303248;
extern u32 lbl_80346C68;
extern s32 lbl_803474A8;
extern s32 lbl_80346C54;
extern u32 lbl_80346C5C;
extern s32 lbl_80346C60;
extern void *lbl_80346C64;
extern s8 fn_801010CC(void);
extern int sprintf(char *buf, const char *fmt, ...);
extern s32 DVDOpen(const char *path, DvdFile *file);
extern void StvSampPath(char *path);
extern void *fn_801E1C7C(u32 size);
extern s32 DVDReadAsyncPrio(DvdFile *file, void *buf, u32 len, s32 ofs, void *cb, s32 prio);
typedef struct Ent_80098A68 {
    u8 pad0[2];
    s16 h2;
    u8 pad4[0x8c - 4];
    f32 f8c;
    f32 f90;
    u8 pad94[0xb4 - 0x94];
} Ent_80098A68;
#endif

#ifdef NONMATCHING
void fn_80098C58(SparkSet* set, s32 n, SparkDef* def) {
    s32 i;
    s32 j;
    Spark* s;
    SparkDef* d;

    d = def;
    for (i = 0; i < n; i++, set++) {
        set->active = 1;
        def = d;
        s = set->s;
        for (j = 0; j < 8; j++, s++, def++) {
            if (def->on != 0) {
                s->on = 1;
                s->x += def->xr * (3.0517578125e-05f * fn_8025ECC4()) + def->xb;
                if (def->wrap) {
                    if (s->x > 0.0f) {
                        s->x += def->wrap;
                    }
                    if (s->x < 0.0f) {
                        s->x -= def->wrap;
                    }
                }
                s->y += def->yr * (3.0517578125e-05f * fn_8025ECC4()) + def->yb;
                s->z = def->z;
            }
        }
    }
}
#endif

#ifdef NONMATCHING
void fn_80097A1C(void)
{
    SampLoad *s = &lbl_80303248;

    lbl_80346C68 = fn_801010CC();
    if (lbl_80346C68 == 0x3C || lbl_80346C68 == 0x3E) {
        lbl_803474A8 = 1;
        if (lbl_80346C68 == 0x3E) {
            lbl_80346C54 = 1;
        } else {
            lbl_80346C54 = 0;
        }
    } else {
        lbl_803474A8 = 0;
    }
    sprintf(s->path[1], "/sound/m04%02d.samp", lbl_80346C68);
    DVDOpen(s->path[1], &s->file[1]);
    StvSampPath(s->path[0]);
    lbl_80346C60 = 0;
    lbl_80346C64 = NULL;
    lbl_80346C5C = (s->file[1].length + 0x1F) & ~0x1F;
    lbl_80346C64 = fn_801E1C7C(lbl_80346C5C);
    DVDReadAsyncPrio(&s->file[1], lbl_80346C64, lbl_80346C5C, 0, NULL, 2);
}
#endif

#ifdef NONMATCHING
void fn_80098A68(Ent_80098A68* e, s32 n, f32* v) {
    f32 c = v[2];
    f32 a = v[0];
    f32 d = v[3];
    f32 b = v[1];
    f32 sgn = 1.0f;
    f32 zero = 0.0f;
    f32 one = 1.0f;
    s32 i;
    if (a < 0.0f) {
        sgn = -1.0f;
        a = -a;
    }
    if (c < 0.0f) {
        sgn = -1.0f;
        c = -c;
    }
    for (i = 0; i < n; i++, e++) {
        if (c != zero) {
            e->h2 += (s32)((one * e->f90 + 256.0f) / c);
        }
        if (d != zero) {
            e->h2 += (s32)(d * (0.000030517578f * (f32)fn_8025ECC4()));
        }
        if (a != zero) {
            e->h2 += (s32)((sgn * e->f8c + 256.0f) / a);
        }
        if (b != zero) {
            e->h2 += (s32)(b * (0.000030517578f * (f32)fn_8025ECC4()));
        }
    }
}
#endif
