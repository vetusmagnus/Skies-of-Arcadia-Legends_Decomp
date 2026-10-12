#ifndef GAME_FOG_H
#define GAME_FOG_H

#include "types.h"

/* Field fog: FogOn loads the current field's fog into GX, FogOff disables it. */
void FogOn(void);
void FogOff(void);

extern s32 fog_enabled;

#endif
