#ifndef GAME_CAMERA_803119E0_H
#define GAME_CAMERA_803119E0_H

#include "types.h"
#include "ninja.h"

/* lbl_803119E0: the 0x20-byte camera block; the event, camp and title code read the eye position
 * and the look-at direction, the screen code sets the angle at 0x1a. */
typedef struct {
    NJS_POINT3 pos;
    NJS_POINT3 dir;
    u8 pad18[2];
    s16 x1a;
    u8 pad1c[4];
} Camera803119E0;

extern Camera803119E0 lbl_803119E0;

#endif
