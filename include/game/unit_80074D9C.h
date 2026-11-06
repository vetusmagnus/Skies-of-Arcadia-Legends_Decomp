#ifndef GAME_UNIT_80074D9C_H
#define GAME_UNIT_80074D9C_H

#include "types.h"
#include "ninja.h"
#include "game/task.h"

/* Struct layouts shared by unit_80074D9C.c and the units split from it, unit_80078A20.c and
 * unit_8007DE54.c (docs/progress.md). */
typedef struct ChrState {
    s32 x0;
    s8 b4;
    u8 pad_5[0x1];
    s16 x6;
    s8 x8;
    s8 x9;
    s8 xa;
    s8 xb;
    u8 xc;
    s8 bd;
    u8 xe;
    u8 pad_f[0x1];
    s32 x10;
    u8 x14;
    u8 pad_15[0x1];
    s16 x16;
    u8 x18;
    u8 pad_19[0x1];
    s16 x1a;
    u8 x1c;
    u8 pad_1d[0x3];
} ChrState;
typedef struct PosEnt {
    u8 x0;
    s8 x1;
    s8 x2;
    u8 pad3;
    f32 x4;
    f32 x8;
    f32 xc;
} PosEnt;
typedef struct PosTbl {
    s16 x0;
    s16 x2;
    u8 pad4[0x14];
    PosEnt ent[12];
} PosTbl;
typedef struct Motion {
    void* data;
    u32 nbFrame;
} Motion;
typedef struct Tab_8006CEEC {
    u32 count;
    Motion* v[1];
} Tab_8006CEEC;
typedef struct Ent_8006CEEC {
    u8 pad0[0x1c];
    Tab_8006CEEC *x1c;
    u8 pad20[0x68 - 0x20];
} Ent_8006CEEC;
typedef struct Ctx_8006CEEC {
    u8 pad0[4];
    Ent_8006CEEC *x4;
} Ctx_8006CEEC;
typedef struct MotSrc { u8 pad0[8]; Ctx_8006CEEC* x8; } MotSrc;
typedef struct Sub { Motion* x0; Motion* x4; f32 x8; f32 xc; } Sub;
/* One motion entry of a unit's table (0x18 bytes). */
typedef struct Act {
    s16 id;
    s16 x2;
    u8 pad4[2];
    s16 x6;     /* motion id */
    u32 flags;
    s16 xc;
    u8 pade[6];
    f32 x14;
} Act;
typedef struct Unit {
    u8 pad0[2];
    s16 x2;
    u8 pad4[2];
    s16 x6;
    s16 x8;
    u8 padA[0x5C - 0xA];
    Motion* x5c;      /* current motion */
    Motion* x60;      /* the next one (flag 0x40000000) */
    s16 x64;          /* current motion id */
    u8 pad66[2];
    f32 x68;
    f32 x6c;
    s32 x70;
    Motion* x74;
    Motion* x78;
    f32 x7c;
    f32 x80;
    Sub x84;
    u8 pad94[0xdc - 0x94];
    Act* xdc;
    u8 pade0[0xe4 - 0xe0];
    s16 xe4;
    s16 xe6;
    u8 padE8[0xec - 0xe8];
    u32 xec;
    u32 xf0;
    u8 padf4[0x204 - 0xf4];
    s16 x204;
    u8 pad206[0x218 - 0x206];
    u8 x218[0x10];
    MotSrc* x228;
} Unit;
/* A model object: its motion source at 0x10, its unit block at 0x4c. */
typedef struct Mdl {
    u8 pad0[0x10];
    MotSrc* x10;
    u8 pad14[2];
    s16 x16;
    u8 pad18[0x4C - 0x18];
    Unit* u;
} Mdl;
typedef struct MdlTask {
    u8 pad0[0x24];
    Mdl* work;
} MdlTask;
typedef struct Wk {
    s16 idx;
    s16 x2;
    u32 flags;
    struct Chr_UNIT0000* chr;
    s8 xc;
    s8 xd;
    s8 xe;
    s8 xf;
    void (*x10)(struct Slot *);   /* next update handler */
    s8 len;             /* 0x14: path length */
    u8 pad15;
    s8 state;           /* 0x16 */
    s8 path[16][2];     /* 0x17: grid steps, -1 ends */
    s8 x37;
    u8 pad38[4];
    s32 x3c;
    s32 x40;
    s16 x44;
    s16 x46;
    s16 x48;
    s16 x4a;
    u8 pad4c[4];
    s8 x50;
    u8 pad51[2];
    u8 grid[11 * 11];   /* 0x53 */
    u8 padcc[0xd4 - 0xcc];
} Wk;
typedef struct Slot {
    void (*update)(struct Slot *);
    u8 pad1[0x14];
    u8 flags18;
    u8 state;
    u8 pad2[0x0a];
    Wk *work;
} Slot;
typedef struct Stat {
    u8 pad0[0x56];
    s16 s56;
    s8 x58;     /* enemy weapon effect */
} Stat;
typedef struct Chr_UNIT0000 {
    u8 pad[0xe];
    s16 xe;     /* status bits */
    u32 x10;
    s32 score;  /* 0x14 */
    s32 x18;
    u32 w1c;
    u8 pad_20[0x4];
    s16 x24;
    u8 pad_26[0x6e];
    s16 x94;
    u8 pad_96[0x16];
    s8 xac;
    s8 xad;
    s16 xae;
    u8 padb0[4];
    s16 xb4;
    s16 xb6;    /* equipped weapon */
    s8 xb8;
    u8 xb9;
    s16 xba;
    s16 xbc[6];
    s16 xc8[16];
    s16 xe8[5];
    s16 xf2[6];
    s8 xfe;
    s8 xff;
    u8 x100;
    u8 pad101;
    s16 x102;   /* first equipped item slot */
    s16 x104;   /* second equipped item slot */
    u8 x106;
    u8 pad107;
    s16 x108;
    u8 pad10a[0x110 - 0x10a];
    Stat* p110;
} Chr_UNIT0000;
typedef struct Obj_8007DE54_8007D42C {
    u8 pad[0x18];
    u8 flags18;
    u8 state;
    u8 pad1a[0x24 - 0x1a];
    s32* buf;
} Obj_8007DE54_8007D42C;
typedef struct Obj_8007DE54 {
    u8 pad[0x18];
    u8 flags18;
    u8 state;
    u8 pad2[0x0a];
    void *buf;
} Obj_8007DE54;
/* One inventory slot: item id (-1 free) and its count. */
typedef struct ItemSlot {
    s16 id;
    s8 count;
    u8 pad3;
} ItemSlot;
typedef struct Lim {
    u8 pad_0[0x6];
    s16 x6;
    s16 x8;
    s16 xa;
    u8 padc[0x38 - 0xc];
    ItemSlot e[80];     /* 0x38 */
} Lim;
typedef struct Hd74E2C {
    u32 f0;
    u32 f4;
} Hd74E2C;
typedef struct Ent74E2C {
    u8 pad0[0x20];
    Hd74E2C *f20;
} Ent74E2C;
typedef struct Sub74E2C {
    u8 pad0[4];
    Ent74E2C *f4;
} Sub74E2C;
typedef struct {
    u8 pad0[0x34];
    u32 flags;
} Obj74D9C;
/* The located chunk: its owner object, then the chunk data from +8. */
typedef struct Loc74E2C {
    Obj74D9C *obj;
    s32 x4;
    s32 data[1];
} Loc74E2C;

#endif
