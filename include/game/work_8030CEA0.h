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

/* The 5-byte pattern record passed to fn_801D6CBC (rumble/pattern player). */
typedef struct {
    u8 a;
    u8 b;
    u8 c;
    u8 d;
    u8 e;
} Pat;

/* One node of a camera path: position, look-at, frames to the next node, two more values. */
typedef struct {
    f32 a[3];
    f32 b[3];
    u32 w;
    f32 c[2];
} PathNode;

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
    struct Scpt* x10;           /* the 0x180 running script commands (unit_801F5334.c) */
    Slot8* x14;
    s32 ent[256][2];            /* 0x18 */
    union {
        s32 w;
        u8 b[4];
    } x818;                     /* a one-word script (the end code, 12) for x4 to fall back on */
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
    u8 padc4d[0xc50 - 0xc4d];
    s32 xc50;                   /* screen fade: length in frames */
    s32 xc54;                   /* frames done */
    f32 xc58;                   /* alpha, 0..255 */
    s32 xc5c;                   /* drawn while set */
    union {
        u32 w;
        u8 b[4];                /* b[0] is the alpha */
    } xc60;                     /* colour */
    f32 xc64;
    s32 xc68;
    s32 xc6c;
    s32 xc70;
    s32 xc74[4];                /* camera path n: running */
    s16 xc84;
    s16 xc86;
    s16 xc88;
    s16 xc8a[4];                /* camera path n: node count */
    u8 padc92[0xca0 - 0xc92];
    s32 xca0[4];
    u8 padcb0[0xcbc - 0xcb0];
    s32 xcbc[4];                /* camera path n: total frames */
    u8 padccc[0x102c - 0xccc];
    PathNode path[4][8];        /* 0x102c: camera paths (fn_802001F8) */
    u8 pad14ac[0x14b8 - 0x14ac];
    s32 x14b8[4];
    u8 pad14c8[3];
    u8 x14cb[0x1544 - 0x14cb];
    s32 x1544[9];
    s32 x1568;
    s32 x156c;
    s32 x1570;
    s32 x1574;
    s32 x1578;
    u32 x157c;                  /* the sound handle SePlay returned */
    s32 x1580;
    s32 x1584[17];
    s32 x15c8;
    s32 x15cc;
    s32 x15d0;
    u8 pad15d4[4];
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
    u8 pad1784[0x17a0 - 0x1784];
    u32 x17a0;
    u32 x17a4;
    u8 pad17a8[0x1874 - 0x17a8];
    s32 x1874;
    s16 x1878;
    s16 sp;                     /* 0x187A */
    void* stack[0x20];           /* 0x187C */
    f32 x18fc, x1900, x1904;
    s32 x1908, x190c, x1910;
    void* x1914;
    s32 x1918;
    s32 x191c;
} Work8030CEA0;

extern Work8030CEA0 lbl_8030CEA0;

#endif
