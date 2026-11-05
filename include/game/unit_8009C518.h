#ifndef GAME_UNIT_8009C518_H
#define GAME_UNIT_8009C518_H

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
/* count */
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
extern u32 lbl_80346C50;
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
void fn_800972AC(void);
void fn_800972C4(void);
void fn_800972E0(s8 x);
void fn_80097318(s8 x);
void fn_80097350(s32 x);
BOOL fn_80097608(void *unused, Obj12 *p);
s32 fn_8009761C(s32 a, u16 b);
s8 fn_8009763C(void);
void fn_80097660(void);
void fn_800976EC(void);
void fn_80097AFC(void);
void fn_80097CA4(s32 p);
void fn_80097CDC(void);
s32 fn_8009B58C(s32 unused, Obj8009B58C *obj, Entry8009B58C *e, s16 arg);
s32 fn_8009B5D4(s32 unused, Obj8009B5D4 *obj, Entry8009B58C *e, s16 arg);
u32 fn_8009C50C(void *unused, Obj10 *p);
void fn_8009CBB8(void);

extern void njTranslate(NJS_MATRIX m, f32 x, f32 y, f32 z);

#define BSW(x) ((((x) >> 24) & 0xff) | (((x) >> 8) & 0xff00) | (((x) << 8) & 0xff0000) | ((x) << 24))
s32 fn_8009766C(void);
void fn_800986C8(u8 *obj, u8 *src, s32 count);
s32 fn_8009B61C(void *unused, u8 *obj, s16 *d);
void fn_8009B8F0(u8 *obj);
void fn_800974CC(Obj80097388* o);
s32 fn_8009B6B8(s32 unused, Obj8009B6B8* o, Src8009B6B8* src);
s32 fn_8009B7D4(s32 unused, Obj8009B6B8* o, Src8009B6B8* src);
void fn_8009C3D0(Task* t);
void fn_800996D8(Obj *o);
s32 fn_80097B0C(s32 p);
void fn_800976F8(void);
void fn_800991AC(Particle* e, s32 n);
void fn_80097388(Camera *cam);
s32 fn_8009877C(Owner_8009877C *o, s32 id);
void fn_80099078(Particle *n, s32 count);
s32 fn_8009B3F4(Obj_8009B3F4 *o);
s32 fn_8009B4C0(Obj_8009B3F4 *o);
void fn_8009884C(Ent_8009884C* e, s32 n, f32* v);

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
void fn_8009CBBC(void);

typedef struct DvdFile {
    u8 pad0[0x34];
    u32 length;         /* 0x34 */
    u8 pad38[0x3C - 0x38];
} DvdFile;
extern DvdFile lbl_80303248;
extern DvdFile lbl_80303284;
extern char lbl_803032C0[0x40];
extern char lbl_80303300[0x40];
extern u32 lbl_80346C68;
extern s32 lbl_803474A8;
extern s32 lbl_80346C54;
extern u32 lbl_80346C5C;
extern void *lbl_80346C60;
extern s32 lbl_80346C58;
extern s32 lbl_803472E8;
extern void *lbl_80346C64;
extern s8 fn_801010CC(void);
extern int sprintf(char *buf, const char *fmt, ...);
extern s32 DVDGetCommandBlockStatus(DvdFile *file);
extern s32 DVDClose(DvdFile *file);
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
extern s32 fn_801010C4(void);
extern s32 fn_801F4D14(void);
extern void fn_802182F4(s32 n, ...);
extern void fn_80217830(s32 a);
extern s32 fn_80218570(s32 a, s32 b, s32 c);
extern void fn_80218D84(void *path, void *data, s32 size);

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
s32 fn_80097CEC(s32 p);
void fn_8009CFD8(void);

extern const char lbl_802B0E14[];
extern s32 fn_8009014C(void *arr, const void *key, s32 n, s32 size);
void fn_8009D190(s32 key);
void fn_8009BED8(Task* t);

#endif
