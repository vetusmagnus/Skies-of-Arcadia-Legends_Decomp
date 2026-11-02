#ifndef GAME_EFFECT_H
#define GAME_EFFECT_H

#include "types.h"
#include "ninja.h"

/* Struct layouts shared by effect.c and unit_8004DE48.c, which was split from it
 * (docs/progress.md). */
typedef struct { u8 pad[0x154]; void* x154; } Body;
typedef struct {
    u8 pad0[0x6C];
    u32 input;          /* 0x6C */
    u8 pad70[0x188 - 0x70];
    u32 col;            /* 0x188 */
    u8 pad18c[0x1C4 - 0x18C];
    s32 count;          /* 0x1C4 */
    s16 x1c8;
    s16 x1ca;
    u32 flags;          /* 0x1CC */
} ObjStats;
typedef struct { void** mdata; u32 nbFrame; } Motion;
typedef struct { u8 pad[8]; void* x8; } ObjSrc;
typedef struct Q16 { s32 a, b, c, d; } Q16;
typedef struct W80049130 {
    u8 pad0[0x10];
    char* x10;          /* 0x10 */
    u8 pad14[0x1c - 0x14];
    NJS_POINT3 x1c;     /* 0x1c */
    u8 pad28[0x4c - 0x28];
    struct I80049130* e; /* 0x4c */
} W80049130;
typedef struct I80049130 {
    u8 pad0[4];
    s32 x4;             /* 0x04 */
    void* x8;           /* 0x08 */
    u8 pad0C[0x1c - 0xc];
    struct { Q16 q; u8 pad10[0x56 - 0x10]; s16 x56; }* x1c; /* 0x1c */
} I80049130;
typedef struct { u8 pad[0x24]; W80049130* work; } Node_80049130;

#endif
