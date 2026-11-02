#ifndef GAME_UNIT_800972AC_H
#define GAME_UNIT_800972AC_H

#include "types.h"
#include "ninja.h"
#include "game/task.h"
#include "game/evobj.h"

/* Struct layouts shared by unit_800972AC.c and the units split from it, unit_8009D274.c,
 * unit_800A3ED4.c and unit_800AE300.c (docs/progress.md). */
typedef struct Obj_800A0E1C Obj_800A0E1C;
typedef struct TNode8009D760 TNode8009D760;
typedef struct Obj_800A0BA0 Obj_800A0BA0;
typedef struct TblA {
    u32 count;
    u32 items[1];
} TblA;
typedef struct Sub2 {
    u8 pad[4];
    u32 f4;
} Sub2;
typedef struct Sub_UNIT0000 {
    u8 pad[0x20];
    Sub2 *f20;
} Sub_UNIT0000;
typedef struct Obj_UNIT0000 {
    u8 pad0[0x100];
    s32 f100;
    u8 pad1[0x1c8 - 0x104];
    Sub_UNIT0000 *f1c8;
} Obj_UNIT0000;
typedef struct {
    TNode8009D760** slots;
    s32 count;
} Pool;
typedef struct {
    u8 pad00[0x48];
    s32 count;           /* 0x48 */
    u8 pad4C[0x58 - 0x4C];
    s32 f58;             /* 0x58 */
} Params8009D760;
typedef struct {
    u8 pad00[4];
    s32 f04;
    u8 pad08[0x10 - 0x08];
    Params8009D760* params; /* 0x10 */
    u8 pad14[0x38 - 0x14];
    TNode8009D760* t38;  /* 0x38 */
} Obj8009D760;
typedef struct {
    u8 pad00[0x14];
    s32 f14;             /* 0x14 */
    s32 f18;             /* 0x18 */
    u8 pad1C[0x2C - 0x1C];
    s32 f2C;             /* 0x2C */
    s32 f30;             /* 0x30 */
    s32 f34;             /* 0x34 */
    u8 pad38[0xE4 - 0x38];
    s32 fE4;             /* 0xE4 */
    u8 padE8[0x178 - 0xE8];
    u16 s178;            /* 0x178 */
    s16 s17A;            /* 0x17A */
    u8 pad17C[0x1BC - 0x17C];
    s32 f1BC;            /* 0x1BC */
    u8 pad1C0[0x1C8 - 0x1C0];
    Obj8009D760* obj;    /* 0x1C8 */
    u8 pad1CC[0x1D8 - 0x1CC];
    s32 f1D8;            /* 0x1D8 */
    u8 pad1DC[0x204 - 0x1DC];
    s16 s204;            /* 0x204 */
    s16 s206;            /* 0x206 */
    u8 pad208[0x234 - 0x208];
    u16 h234;            /* 0x234 */
    u16 h236;            /* 0x236 */
    s16 s238;            /* 0x238 */
    u8 pad23A[0x25C - 0x23A];
    s32 f25C;            /* 0x25C */
    void* f260;          /* 0x260 */
    Pool* f264;          /* 0x264 */
    s32 f268;            /* 0x268 */
} Work8009D760;
struct TNode8009D760 {
    u8 pad00[4];
    TNode8009D760* f04;  /* 0x04 */
    u8 pad08[4];
    TNode8009D760* f0C;  /* 0x0C */
    u8 pad10[8];
    u8 flags;            /* 0x18 */
    u8 state;            /* 0x19 */
    u8 pad1A[0x24 - 0x1A];
    Work8009D760* work;  /* 0x24 */
};
typedef struct {
    u8 pad00[0x178];
    s32 state;        /* 0x178 */
    u32 key;          /* 0x17C */
    s32 i180;         /* 0x180 */
    f32 f184, f188, f18C; /* 0x184 */
    s32 i190, i194, i198; /* 0x190 */
} Work8009DCA8;
typedef struct {
    u8 pad00[0x16C];
    s16 active;       /* 0x16C */
    u8 pad16E[0x1D8 - 0x16E];
    Work8009DCA8* work; /* 0x1D8 */
    u32 base;         /* 0x1DC */
} Obj8009DCA8;
typedef struct {
    u32 key;
    s32 i04;
    f32 f08, f0C, f10;
    s32 i14, i18, i1C;
} Src8009DCA8;
typedef struct {
    s32 x, y, z;
} Ang3;
typedef struct {
    u8 pad0[4];
    void* x4;
    Obj_800A0BA0* x8;
} Aux_800A0BA0;
struct Obj_800A0BA0 {
    u8 pad0[0x38];
    NJS_POINT3 pos;      /* 0x38 */
    Ang3 ang;            /* 0x44 */
    NJS_POINT3 scl;      /* 0x50 */
    u8 pad5c[0xB4 - 0x5C];
    NJS_POINT3 pivotPos; /* 0xB4 */
    Ang3 pivotAng;       /* 0xC0 */
    u8 padcc[0x16C - 0xCC];
    s16 pivot;           /* 0x16C */
    u8 pad16e[0x1D8 - 0x16E];
    Aux_800A0BA0* aux;            /* 0x1D8 */
    u8 pad1dc[0x20C - 0x1DC];
    Ang3 outAng;         /* 0x20C */
    u8 pad218[0x24C - 0x218];
    NJS_POINT3 outPos;   /* 0x24C */
};
typedef struct {
    u8 pad0[0x24];
    Obj_800A0E1C* x24;
} Tgt_800A0E1C;
typedef struct {
    u8 pad0[4];
    Tgt_800A0E1C* x4;
    Obj_800A0E1C* x8;
} Aux_800A0E1C;
struct Obj_800A0E1C {
    u8 pad0[0x38];
    NJS_POINT3 pos;      /* 0x38 */
    Ang3 ang;            /* 0x44 */
    NJS_POINT3 scl;      /* 0x50 */
    u8 pad5c[0xB4 - 0x5C];
    NJS_POINT3 pivotPos; /* 0xB4 */
    Ang3 pivotAng;       /* 0xC0 */
    u8 padcc[0x16C - 0xCC];
    s16 pivot;           /* 0x16C */
    u8 pad16e[0x1D8 - 0x16E];
    Aux_800A0E1C* aux;            /* 0x1D8 */
    u8 pad1dc[0x20C - 0x1DC];
    Ang3 outAng;         /* 0x20C */
    u8 pad218[0x24C - 0x218];
    NJS_POINT3 outPos;   /* 0x24C */
};
typedef struct SrcRec {
    f32 v[6];
} SrcRec;
typedef struct Axis {
    s32 on;         /* 0x00 */
    f32 spd;        /* 0x04 */
    f32 val;        /* 0x08 */
    f32 lim;        /* 0x0C */
} Axis;
typedef struct Particle {
    s16 used;       /* 0x00 */
    s16 delay;      /* 0x02 */
    u8 pad4[4];
    SrcRec *src;    /* 0x08 */
    Axis axis[8];   /* 0x0C */
    f32 v[8];       /* 0x8C */
    s16 step;       /* 0xAC */
    u8 padae[2];
    f32 fb0;        /* 0xB0 */
} Particle;
/* Byte (0..255) to a 0..1 float: __OSu8tof32(&b) * (1/255).
 * Needs the Dolphin SDK fast-cast inline __OSu8tof32 (psq_l through GQR2), which our
 * extern/sdk OSFastCast.h lacks. The SDK's definition is reproduced here only until it is
 * added to <dolphin/os/OSFastCast.h>; the game code itself is the one-line function. */
/* lbl_80311AC0: the current map. */
typedef struct MapInfo { s32 x0; s32 map; char room; } MapInfo;

#endif
