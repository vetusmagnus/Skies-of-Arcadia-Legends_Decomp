#ifndef GAME_WORK_8030CEA0_H
#define GAME_WORK_8030CEA0_H

#include "types.h"

/* lbl_8030CEA0: the 0x1920-byte work area shared by the event/script, shop and camera code. */
typedef struct {
    s32 a;
    u32 b;
} Slot8;

typedef struct {
    u8 pad00[8];
    s16 x08;
    u8 pad0a[6];
    u8* x10;
    Slot8* x14;
    s32 ent[256][2];            /* 0x18 */
    u8 pad818[0x82c - 0x818];
    s32 x82c;
    u8 pad830[4];
    s32 x834;
    u8 pad838[0xc5c - 0x838];
    s32 xc5c;
    u32 xc60;
    f32 xc64;
    u8 padc68[4];
    s32 xc6c;
    u8 padc70[0xc86 - 0xc70];
    s16 xc86;
    u8 padc88[0x1574 - 0xc88];
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
    u8 pad1618[0x1674 - 0x1618];
    f32 x1674[0x40];
    f32 x1774, x1778, x177c, x1780;
    u8 pad1784[0x1874 - 0x1784];
    s32 x1874;
    u8 pad1878[2];
    s16 sp;                     /* 0x187A */
    void* stack[0x20];           /* 0x187C */
    f32 x18fc, x1900, x1904;
    s32 x1908, x190c, x1910;
    u8 pad1914[0x1920 - 0x1914];
} Work8030CEA0;

extern Work8030CEA0 lbl_8030CEA0;

#endif
