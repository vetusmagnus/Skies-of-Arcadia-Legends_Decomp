#ifndef GAME_STAT_8030B4D4_H
#define GAME_STAT_8030B4D4_H

#include "types.h"

/* lbl_8030B4D4: six 0x78-byte per-character stat records, then the block's limit word. */
typedef struct {
    u8 pad00[6];
    s16 x6;
    u8 pad08[0x18 - 8];
    s32 x18;
    u8 pad1c[0x48 - 0x1c];
    s16 x48;
    s16 x4a;
    s16 x4c;
    s16 x4e;
    s16 x50;
    u8 pad52[0x60 - 0x52];
    s32 x60[6];
} StatRec;

typedef struct {
    StatRec chr[6];
    u8 pad2d0[0x2dc - 0x2d0];
    s32 limit;
    u8 pad2e0[0x320 - 0x2e0];
} StatBlock;

extern StatBlock lbl_8030B4D4;

#endif
