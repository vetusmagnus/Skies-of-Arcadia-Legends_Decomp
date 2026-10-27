#ifndef GAME_WORK_8030CEA0_H
#define GAME_WORK_8030CEA0_H

#include "types.h"

/* lbl_8030CEA0: the 0x1920-byte work area shared by the event/script, shop and camera code. */
typedef struct {
    s32 a;
    u32 b;
} Slot8;

typedef struct {
    void* x0;
    void* x4;
    s16 x08;
    s16 x0a;
    s32 xc;
    u8* x10;
    Slot8* x14;
    s32 ent[256][2];            /* 0x18 */
    s32 x818;
    u8 pad81c[4];
    void* x820;
    u32 x824;
    s32 x828;
    s32 x82c;
    f32 x830;
    s32 x834;
    s32 x838;
    s32 x83c;
    s16 x840;
    s16 x842;
    s32 x844;
    u8 pad848[0xc4a - 0x848];
    u8 xc4a;
    u8 xc4b;
    u8 padc4c[0xc5c - 0xc4c];
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
    u8 padc8a[0x1568 - 0xc8a];
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
