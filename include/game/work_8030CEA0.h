#ifndef GAME_WORK_8030CEA0_H
#define GAME_WORK_8030CEA0_H

#include "types.h"

/* lbl_8030CEA0: the 0x1920-byte work area shared by the event/script, shop and camera code. */
typedef struct {
    s32 a;
    u32 b;
} Slot8;

/* One entry of the loaded archive's directory: data offset (low two bits are flags) and name. */
typedef struct {
    u32 off;
    char name[16];
} ArcDir;

/* An event slot (0x180 of them at x10). */
typedef struct {
    s32 kind;
    s32 x4;
    s32 x8;
    struct { s32 x0; s32 x4; }* xc;
    s32 x10;
    s32 x14;
    s32 x18;                    /* index into lbl_802F7940 */
    u8 pad1c[4];
    u32 x20;                    /* type */
    u32 x24;                    /* id */
    u32 x28;
    u8 pad2c[4];
    void* x30;
} EvSlot;

/* The 5-byte pattern record passed to fn_801D6CBC (rumble/pattern player). */
typedef struct {
    u8 a;
    u8 b;
    u8 c;
    u8 d;
    u8 e;
} Pat;

/* One step of the pattern table at x848 (replayed by fn_80211D90). */
typedef struct {
    u8 a;
    s8 b;
    u16 c;
} PatStep;

typedef struct {
    u8* x0;
    u8* x4;
    s16 x08;
    s16 x0a;
    s32 xc;
    EvSlot* x10;
    Slot8* x14;
    s32 ent[256][2];            /* 0x18 */
    s32 x818;
    u8 pad81c[4];
    ArcDir* x820;
    u32 x824;
    s32 x828;
    s32 x82c;
    f32 x830;
    s32 x834;
    u32 x838;
    u32 x83c;
    s16 x840;
    u16 x842;
    u32 x844;
    PatStep steps[0x100];       /* 0x848 */
    Pat pat;                    /* 0xc48 */
    u8 padc4d[0xc5c - 0xc4d];
    s32 xc5c;
    u32 xc60;
    f32 xc64;
    s32 xc68;
    s32 xc6c;
    s32 xc70;
    u8 padc74[0xc84 - 0xc74];
    s16 xc84;
    s16 xc86;
    s16 xc88;
    u8 padc8a[0x14b8 - 0xc8a];
    s32 x14b8[4];
    u8 pad14c8[3];
    u8 x14cb[0x1544 - 0x14cb];
    s32 x1544[9];
    s32 x1568;
    u8 pad156c[0x1574 - 0x156c];
    s32 x1574;
    u8 pad1578[4];
    void* x157c;
    s32 x1580;
    s32 x1584[17];
    s32 x15c8;
    s32 x15cc;
    u8 pad15d0[8];
    s32 x15d8, x15dc, x15e0, x15e4, x15e8, x15ec, x15f0, x15f4, x15f8, x15fc, x1600, x1604, x1608;
    s32 x160c;
    s32 x1610;
    s32 x1614;
    union {
        s32 tbl[64];            /* 0x1618 */
        struct {
            u8 pad1618[0x1674 - 0x1618];
            f32 x1674[0x40];
        };
    };
    f32 x1774, x1778, x177c, x1780;
    u8 pad1784[0x1874 - 0x1784];
    s32 x1874;
    s16 x1878;
    s16 sp;                     /* 0x187A */
    void* stack[0x20];           /* 0x187C */
    f32 x18fc, x1900, x1904;
    s32 x1908, x190c, x1910;
    void* x1914;
    s32 x1918;
    u8 pad191c[4];
} Work8030CEA0;

extern Work8030CEA0 lbl_8030CEA0;

#endif
