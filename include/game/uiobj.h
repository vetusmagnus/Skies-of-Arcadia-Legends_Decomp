#ifndef GAME_UIOBJ_H
#define GAME_UIOBJ_H

#include "types.h"

/* A menu element's position and animation. Every menu panel, window and cursor embeds one: the
 * menus move them with UiObjMoveTo* (linear, over N frames) and run them with UiObjUpdate. Hidden
 * pages and windows are moved off the 4:3 screen (x = -348, 668, ...) and keep being drawn there;
 * see docs/ui.md. */
typedef struct UiObj {
    f32 z;        /* 0x00 */
    f32 x, y;     /* 0x04 position, 640x480 pixels */
    f32 tx, ty;   /* 0x0C target */
    f32 vx, vy;   /* 0x14 step per frame */
    f32 rdx, rdy; /* 0x1C "raise" offset (highlighted panels move 12 px right, 4 px up) */
    f32 rect[4];  /* 0x24 draw position from UiObjCalcRect */
    f32 alpha;    /* 0x34 0.7 lowered, 1.0 raised (when alpha_en) */
    f32 f38;      /* 0x38 */
    f32 f3c;      /* 0x3C */
    u8 alpha_en; /* 0x40 */
    u8 raised;   /* 0x41 */
    u16 frames;  /* 0x42 move frames left */
    u16 delay;   /* 0x44 frames before the command starts */
    u16 cmd;     /* 0x46 UIOBJ_CMD_*, 0 when idle */
    s16 se;      /* 0x48 menu sound played when the move starts, -1 for none */
} UiObj;

/* Commands (UiObjSetCommand). */
#define UIOBJ_CMD_NONE 0
#define UIOBJ_CMD_RAISE_MOVE_LOWER 5  /* 5 raise, 6 sound, 7 move, 8 lower */
#define UIOBJ_CMD_LOWER_MOVE_RAISE 10 /* 10 lower, 11 sound, 12 move, 13 raise */
#define UIOBJ_CMD_MOVE 15             /* 15 sound, 16 move */
#define UIOBJ_CMD_LOWER 20
#define UIOBJ_CMD_RAISE 21
#define UIOBJ_CMD_LOWER_NOALPHA 24
#define UIOBJ_CMD_RAISE_NOALPHA 25
#define UIOBJ_CMD_LOWER_NOALPHA_MOVE 26 /* then 15 */

void UiObjFinish(UiObj* obj);
void UiObjUpdate(UiObj* obj);
void UiObjSetCommand(UiObj* obj, u16 cmd, u16 delay);
s32 UiObjIsBusy(UiObj* obj);
void UiObjCalcRect(UiObj* obj);
void UiObjMoveTo(UiObj* obj, u16 frames, s16 se, f32 x, f32 y);
s32 UiObjMoveToXIfChanged(UiObj* obj, u16 frames, s16 se, f32 x);
void UiObjMoveToX(UiObj* obj, u16 frames, s16 se, f32 x);
void UiObjMoveToY(UiObj* obj, u16 frames, s16 se, f32 y);
void UiObjSetLowered(UiObj* obj);
void UiObjSetRaised(UiObj* obj);
s32 UiObjStepRaiseNoAlpha(UiObj* obj, u8 up);
s32 UiObjStepRaise(UiObj* obj, u8 up);

#endif
