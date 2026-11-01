#ifndef GAME_BTLSIDE_H
#define GAME_BTLSIDE_H

#include "types.h"
#include "ninja.h"
#include "game/evobj.h"

struct Task;

/* One slot of a battle side (0x18): the slot kind, its index, two parameters and the unit in it.
 * Setting a unit marks it linked (its EvObj.x1ec byte). */
typedef struct BtlSlot {
    s32 type;       /* 0x00 */
    s32 idx;        /* 0x04 */
    f32 a;          /* 0x08 */
    f32 b;          /* 0x0C */
    EvObj* target;  /* 0x10 */
    s32 active;     /* 0x14 */
} BtlSlot;

/* A side's sound cue (fn_80152538 sets it up, fn_801523A4 queues, fn_80152284 plays). */
typedef struct BtlCue {
    s32 x0;
    s32 x4;
    s32 x8;
    s32 xc;
    s32 x10;
    s32 x14;
    s32 x18;
    s32 x1c;
    s32 x20;
    s32 x24;
} BtlCue;

/* lbl_80346FC8[2]: the two battle sides (fn_80156994 sets the head, fn_801540D0 the slots). */
typedef struct BtlSide {
    struct Task* task;      /* 0x00 fn_8010A164(obj->x17a) */
    EvObj* obj;             /* 0x04 */
    void (*cb)(EvObj*);     /* 0x08 called every frame with obj */
    s32 xc;                 /* 0x0C */
    u8* ship;               /* 0x10 */
    f32* m14;               /* 0x14 */
    f32* m18;               /* 0x18 */
    NJS_MATRIX m1c;         /* 0x1C */
    NJS_MATRIX m5c;         /* 0x5C */
    BtlSlot lead;           /* 0x9C kind 0 */
    BtlSlot c[8];           /* 0xB4 kind 1 */
    BtlSlot a[8];           /* 0x174 the first 8 of b, copied by fn_801540D0 */
    BtlSlot b[32];          /* 0x234 kind 2 */
    BtlSlot d[8];           /* 0x534 kind 3 */
    NJS_POINT3 centre;      /* 0x5F4 */
    s32 valid;              /* 0x600 */
    BtlCue cue;             /* 0x604 */
} BtlSide;

extern BtlSide* lbl_80346FC8[2];

#endif
