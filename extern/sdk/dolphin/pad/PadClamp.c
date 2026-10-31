#include <dolphin/pad.h>

#include <math.h>

typedef struct PADClampRegion {
  u8 minTrigger;
  u8 maxTrigger;
  s8 minStick;
  s8 maxStick;
  s8 xyStick;
  s8 minSubstick;
  s8 maxSubstick;
  s8 xySubstick;
  s8 radStick;
  s8 radSubstick;
} PADClampRegion;

static const PADClampRegion ClampRegion = {
    // Triggers
    30,
    180,

    // Left stick
    15,
    72,
    40,

    // Right stick
    15,
    59,
    31,

    // Stick radii
    56,
    44,
};

static void ClampCircle(s8* px, s8* py, s8 radius, s8 min) {
  int x = *px;
  int y = *py;
  s32 squared;
  s32 length;

  if (-min < x && x < min) {
    x = 0;
  } else if (0 < x) {
    x -= min;
  } else {
    x += min;
  }

  if (-min < y && y < min) {
    y = 0;
  } else if (0 < y) {
    y -= min;
  } else {
    y += min;
  }

  squared = x * x + y * y;
  if (radius * radius < squared) {
    length = sqrtf(squared);
    x = (x * radius) / length;
    y = (y * radius) / length;
  }

  *px = x;
  *py = y;
}

static void ClampTrigger(u8* trigger, u8 min, u8 max) {
  if (*trigger <= min) {
    *trigger = 0;
  } else {
    if (max < *trigger) {
      *trigger = max;
    }
    *trigger -= min;
  }
}

void PADClampCircle(PADStatus* status) {
  int i;
  for (i = 0; i < 4; ++i, status++) {
    if (status->err != PAD_ERR_NONE) {
      continue;
    }

    ClampCircle(&status->stickX, &status->stickY, ClampRegion.radStick, ClampRegion.minStick);
    ClampCircle(&status->substickX, &status->substickY, ClampRegion.radSubstick,
                ClampRegion.minSubstick);
    ClampTrigger(&status->triggerL, ClampRegion.minTrigger, ClampRegion.maxTrigger);
    ClampTrigger(&status->triggerR, ClampRegion.minTrigger, ClampRegion.maxTrigger);
  }
}
