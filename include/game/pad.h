#ifndef GAME_PAD_H
#define GAME_PAD_H

#include "types.h"

/* The controller state lbl_80311A60 points to per port. */
typedef struct PadState {
    u32 buttons;    /* 0x00 */
    u8 pad4[4];
    u32 held;       /* 0x08 */
    u8 padc[4];
    u16 trigL;      /* 0x10 */
    u16 trigR;      /* 0x12 */
    u8 pad14[4];
    s16 stickX;     /* 0x18 */
    s16 stickY;     /* 0x1A */
} PadState;

#endif
