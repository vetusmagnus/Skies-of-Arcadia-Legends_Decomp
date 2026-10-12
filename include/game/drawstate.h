#ifndef GAME_DRAWSTATE_H
#define GAME_DRAWSTATE_H

#include "ninja.h"

/* A Ninja draw state: 3D control flags, constant attributes, constant material colour, colour
 * blending and whether field fog applies. Game code keeps a stack of them; most 2D drawing
 * pushes a modified default, draws, then pops (see docs/ui.md). */
typedef struct {
    u32 control3d;   /* 0x00 njControl3D */
    u32 attr_and;    /* 0x04 njSetConstantAttr */
    u32 attr_or;     /* 0x08 */
    NJS_ARGB colour; /* 0x0C njSetConstantMaterial */
    s32 blend_src;   /* 0x1C njColorBlendingMode(NJD_SOURCE_COLOR, ...) */
    s32 blend_dst;   /* 0x20 njColorBlendingMode(NJD_DESTINATION_COLOR, ...) */
    s32 fog;         /* 0x24 field fog on while this state is applied */
} DrawState;

#define DRAWSTATE_DEPTH 32
#define CLIPZ_DEPTH 32

typedef struct {
    f32 near, far;
} ClipZ;

extern ClipZ clipz_stack[CLIPZ_DEPTH];
extern DrawState drawstate_current; /* what DrawStateApply last loaded */
extern DrawState drawstate_stack[DRAWSTATE_DEPTH];
extern s32 clipz_depth;
extern s32 drawstate_depth;

void ClipZPop(void);
void ClipZPush(void);
void ClipZSet(f32 near, f32 far);

void DrawStateApplyFog(void);
void DrawStateReapply(void);
void DrawStateRestore(void);
void DrawStateApply(DrawState* state);
void DrawStateGet(DrawState* out);
s32 DrawStatePop(DrawState* out);
s32 DrawStatePush(DrawState* state);
void DrawStateDefault3D(DrawState* out);
void DrawStateDefault2D(DrawState* out);
void DrawStateDefault(s32 mode, DrawState* out);
void DrawStateInit(void);

#endif
