#ifndef GAME_STAT_8030B4D4_H
#define GAME_STAT_8030B4D4_H

#include "types.h"

/* lbl_8030B4D4: six 0x78-byte per-character stat records, then the block's limit word. */
typedef struct {
    s16 x0;
    u8 x2;
    u8 pad03[3];
    s16 x6;
    s16 x8;
    s16 xa;
    s16 xc;
    s16 xe;
    u8 pad10[4];
    s32 x14;                /* flags; bit 16 is tested by fn_801EF7E0 */
    s32 x18;
    s16 x1c[6];
    s16 x28[16];
    s16 x48[5];
    s16 x52[6];
    u8 pad5e[2];
    s32 x60[6];
} StatRec;

/* The ship's stats at 0x2dc (fn_8021AF94 fills them): a limit word, the stat values, five
 * 6-byte cannon records at 0x24. */
typedef struct {
    s32 limit;
    s16 x4;
    s16 x6;
    s16 x8;
    u8 pada[0x1a - 0xa];
    s16 x1a;
    s16 x1c;
    u8 pad1e[0x24 - 0x1e];
    struct { s16 a; s16 b; u8 c; u8 d; } e[5];    /* 0x24 */
} ShipStat;

typedef struct {
    StatRec chr[6];
    s16 x2d0;
    s16 x2d2;
    s8 x2d4;                /* party size (signed: fn_801C0D34 extsb's it) */
    s8 x2d5[5];
    u8 pad2da[2];
    ShipStat ship;          /* 0x2DC */
    u8 pad31e[0x320 - 0x31e];
} StatBlock;

extern StatBlock lbl_8030B4D4;

#endif
