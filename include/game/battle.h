#ifndef GAME_BATTLE_H
#define GAME_BATTLE_H

#include "types.h"

/* The event message battle.c's command handlers take (Msg*, slot index); nine other units post or
 * read the same layout. */
typedef struct Msg {
    s16 x0;
    s16 x2;
    s16 x4;
    s16 x6;
    s32 x8;
    s32 xc;
} Msg;

#endif
