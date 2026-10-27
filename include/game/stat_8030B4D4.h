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

typedef struct {
    StatRec chr[6];
    s16 x2d0;
    s16 x2d2;
    u8 x2d4;
    s8 x2d5[5];
    u8 pad2da[2];
    s32 limit;
    u8 pad2e0[0x320 - 0x2e0];
} StatBlock;

extern StatBlock lbl_8030B4D4;

#endif
