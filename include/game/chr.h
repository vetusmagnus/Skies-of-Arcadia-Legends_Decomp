#ifndef GAME_CHR_H
#define GAME_CHR_H

#include "types.h"
#include "ninja.h"
#include "game/chrinfo.h"

/* The battle characters: lbl_80309DE4 holds each one's static record, a character task's work is a ChrWork whose
 * 0x4C is the ChrInfo, and lbl_8030A10C is the battle state with the 9x9 position grid. */
struct ChrAux;

typedef struct ChrRec {
    s16 x0;             /* 0x00 */
    u8 pad_2[6];
    s16 x8;             /* 0x08 */
    u8 pada[0x14 - 0xa];
    s32 x14;
    s32 x18;
    s32 bits;           /* 0x1c */
    u8 pad20[0x40 - 0x20];
    s16 stat[4];        /* 0x40 */
    u8 pad48[0x86 - 0x48];
    s16 x86;            /* 0x86 */
    s16 x88;
    u8 pad8a[0x94 - 0x8a];
    s16 x94;            /* 0x94 */
    s16 x96;            /* 0x96 */
    u8 pad98[0x9a - 0x98];
    s16 x9a;            /* 0x9a */
    s16 x9c;            /* 0x9c */
    u8 pad9e[0xae - 0x9e];
    s16 xae;            /* 0xae */
    u8 padb0[0xb4 - 0xb0];
    s16 xb4;            /* 0xb4 */
    s16 xb6;            /* 0xb6: weapon id */
    u8 padb8[0x100 - 0xb8];
    u8 x100;            /* 0x100 */
    u8 pad101[0x110 - 0x101];
    struct ChrAux* x110; /* 0x110 */
} ChrRec;
extern ChrRec* lbl_80309DE4[];
/* Event-target object referenced by an id record (x0 type, x4 id, x10 result). */
typedef struct Key {
    s16 x0;
    s16 x2;
    s16 x4;
    u8 pad6[2];
    u32 x8;
    u8 padc[0x10 - 0xc];
    s16 x10;
    u8 pad12[0x18 - 0x12];
} Key;
/* 0x10-byte id record; lists end at a negative x0. */
struct Ent_80008800 {
    s16 x0;
    s16 x2;
    u8 pad4[8];
    Key* xc;
};
typedef struct {
    u8 pad0[0xc];
    void* xc;           /* 0x0c */
    Ent_80008800* x10;  /* 0x10 condition id table */
    s8 x14[9][9];       /* 0x14 party grid */
    u8 pad65[0x68 - 0x65];
    void* x68;
    u32 x6c;
    u8 pad70[0xec - 0x70];
    f32 xec;            /* 0xec speed scale */
    s16 xf0;
    u8 padf2[0x180 - 0xf2];
    void* x180;         /* 0x180 */
    CondLink* x184;     /* 0x184 */
    u8 pad188[0x1c4 - 0x188];
    s32 x1c4;
} GS;
extern GS lbl_8030A10C;
typedef struct ChrWork {
    void* x0;           /* 0x00 model */
    u8 pad4[4];
    NJS_TEXLIST* x8;    /* 0x08 */
    u8 padc[4];
    Obj_80017B18 *x10; /* 0x10 */
    s16 x14;            /* 0x14 */
    u8 pad16[0x1c - 0x16];
    NJS_POINT3 pos;     /* 0x1c */
    Angle rx, ry, rz;   /* 0x28 */
    NJS_POINT3 scl;     /* 0x34 */
    u8 pad40[4];
    u8 x44;             /* 0x44 */
    u8 pad45[0x48 - 0x45];
    NJS_TEXLIST* x48;   /* 0x48 */
    ChrInfo *st; /* 0x4c */
} ChrWork;

#endif
