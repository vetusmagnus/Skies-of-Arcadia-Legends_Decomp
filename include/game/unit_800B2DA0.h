#ifndef GAME_UNIT_800B2DA0_H
#define GAME_UNIT_800B2DA0_H

#include "types.h"
#include "ninja.h"
#include "game/task.h"
#include "game/evobj.h"

/* Struct layouts shared by unit_800B2DA0.c and the units split from it, unit_800CE2B4.c and
 * unit_800D2048.c (docs/progress.md). */
typedef struct Handler Handler;
typedef struct Sub2 {
    s32 f0;
    u32 f4;
} Sub2;
typedef struct Sub_800C34C8 {
    u8 pad[0x20];
    Sub2 *f20;
} Sub_800C34C8;
typedef struct Obj_800C34C8 {
    u8 pad0[0x1c8];
    Sub_800C34C8 *f1c8;
} Obj_800C34C8;
typedef struct {
    u8 pad[8];
    u32 flags;      /* 0x08 */
} Ctrl;
typedef struct {
    s32 unk0;
    s32 map;
    char room;
} MapInfo2;
typedef struct {
    s32 count;
    s32 ids[1];
} IdList;
typedef struct {
    s16 len;          /* 0x00 */
    s16 id;           /* 0x02 */
    s32 args[1];      /* 0x04 */
} Rec_800D5210;
typedef struct {
    u32 count;        /* 0x00 */
    u8 pad4[0x24 - 4];
    Rec_800D5210 first;        /* 0x24 */
} Blob_800D5210;
typedef struct {
    u8 pad0[0x10];
    Blob_800D5210* blob;       /* 0x10 */
} Ext_800D5210;
typedef struct {
    u8 pad0[0x1C8];
    Ext_800D5210* ext;         /* 0x1C8 */
} Ent_800D5210;
struct Handler {
    s16 id;
    s16 arg;
    s32 (*func)(Task* task, Ent_800D5210* e, s32* args, s32 len);
};
typedef struct Part_800D29B4 {
    u8 pad0[0x34];
    s32 w34;
} Part_800D29B4;
typedef struct Tbl_800C4584 {
    s32 count;
    void *items[1];
} Tbl_800C4584;
typedef struct {
    s32 v0;
    u8 pad4[0x1C - 4];
    s32 v1c;
} Sub_800D6E1C;
typedef struct {
    u8 pad0[8];
    u32 kind;
    Sub_800D6E1C* sub;
} Ent_800D6E1C;
typedef struct {
    u8 pad0[0x19];
    u8 state;
    u8 pad1a[0x20 - 0x1A];
    f32 f20;
    EvObj* work;
} MapTask;
typedef struct Work_800C6474 {
    u8 pad0[0x1b8];
    void* p1b8;
    u8 pad1bc[0x23c - 0x1bc];
    u32 w23c;
} Work_800C6474;
typedef struct Node_800B63A4 {
    u8 pad0[0x58];
    struct Node_800B63A4* next;
} Node_800B63A4;
typedef struct Node_800B88F8 {
    u8 pad0[0x58];
    struct Node_800B88F8* next;
} Node_800B88F8;
typedef struct CfgAnim_800BE6EC {
    u8 pad[0x20];
} CfgAnim_800BE6EC;
typedef struct Cfg_800BE6EC {
    u32 count;          /* 0x00 */
    u8 pad4[0x10 - 0x4];
    s32 x10;            /* 0x10 */
    u8 pad14[0x24 - 0x14];
    CfgAnim_800BE6EC x24; /* 0x24 */
    s32 x44;            /* 0x44 */
    u32 x48;            /* 0x48 */
    u8 pad4c[0x64 - 0x4C];
    u32 x64;            /* 0x64 */
    f32 x68;            /* 0x68 */
    u8 pad6c[0x70 - 0x6C];
    u32 x70;            /* 0x70 */
    f32 x74;            /* 0x74 */
    f32 x78;            /* 0x78 */
    u8 pad7c[0x80 - 0x7C];
    s32 x80;            /* 0x80 */
    u8 pad84[0xA4 - 0x84];
    s32 xa4;            /* 0xA4 */
    u8 pada8[0xB4 - 0xA8];
    s32 xb4;            /* 0xB4 */
    s32 xb8;            /* 0xB8 */
    u8 padbc[0xC0 - 0xBC];
    f32 xc0;            /* 0xC0 */
    u8 padc4[4];
    u32 xc8;            /* 0xC8 */
    f32 xcc;            /* 0xCC */
} Cfg_800BE6EC;
typedef struct Link_800BE6EC {
    u8 pad[0x10];
    Cfg_800BE6EC *cfg;
} Link_800BE6EC;
typedef struct Sub_800BE6EC {
    u8 pad0[0x178];
    s32 x178;           /* 0x178 */
    u8 pad17c[0x1A0 - 0x17C];
    s32 x1a0;           /* 0x1A0 */
    u8 pad1a4[0x260 - 0x1A4];
    void (*x260)(void); /* 0x260 */
    u8 pad264[0x31C - 0x264];
    void (*x31c)(void); /* 0x31C */
} Sub_800BE6EC;
/* An emission point (the emitter's w->x25c, an array of w->x22c). */
typedef struct Spot_800BE6EC {
    NJS_POINT3 pos;     /* 0x00 */
    s32 xc;             /* 0x0C */
    s32 timer;          /* 0x10 */
    f32 x14;            /* 0x14 */
} Spot_800BE6EC;
typedef struct {
    s32 x, y, z;
} Ang3_800C47BC;

#endif
