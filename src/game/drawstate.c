/* Draw state and clip distance stacks.
 *
 * The file name is ours (the original isn't known). Game code brackets most drawing with
 * DrawStatePush / DrawStatePop: it fills a DrawState from DrawStateDefault2D or
 * DrawStateDefault3D, changes what it needs (blend modes, colour), pushes it, draws, and pops.
 * See docs/ui.md. */

#include "game/drawstate.h"
#include "game/fog.h"
#include "game/util.h"

/* The field's clip distances (near, far), shared with the field code. */
extern f32 lbl_80346788;
extern f32 lbl_8034678C;
extern f32 lbl_8034755C;
extern f32 lbl_80347560;


void ClipZPop(void) {
    f32 near, far;
    clipz_depth--;
    near = clipz_stack[clipz_depth].near;
    far = clipz_stack[clipz_depth].far;
    lbl_80347560 = near;
    lbl_8034755C = far;
    lbl_80346788 = near;
    lbl_8034678C = far;
    njClipZ(near, far);
}

void ClipZPush(void) {
    clipz_stack[clipz_depth].near = lbl_80347560;
    clipz_stack[clipz_depth].far = lbl_8034755C;
    clipz_depth++;
}

void ClipZSet(f32 near, f32 far) {
    lbl_8034678C = far;
    lbl_80346788 = near;
    njClipZ(near, far);
    lbl_80347560 = near;
    lbl_8034755C = far;
}

void DrawStateApplyFog(void) {
    if (drawstate_stack[drawstate_depth].fog == 1 && fog_enabled == 1) {
        FogOn();
    } else {
        FogOff();
    }
}

void DrawStateReapply(void) {
    DrawStateApply(&drawstate_stack[drawstate_depth]);
}

/* Loads the last applied state into Ninja again, unconditionally. */
void DrawStateRestore(void) {
    njControl3D(drawstate_current.control3d);
    njSetConstantAttr(drawstate_current.attr_and, drawstate_current.attr_or);
    njColorBlendingMode(NJD_SOURCE_COLOR, drawstate_current.blend_src);
    njColorBlendingMode(NJD_DESTINATION_COLOR, drawstate_current.blend_dst);
    njSetConstantMaterial(&drawstate_current.colour);
    if (drawstate_current.fog == 1 && fog_enabled == 1) {
        FogOn();
    } else {
        FogOff();
    }
}

void DrawStateApply(DrawState* state) {
    NJS_ARGB* cur;
    if (state->control3d != _nj_control_3d_flag_) {
        njControl3D(state->control3d);
    }
    if (state->attr_and != _nj_constant_attr_and_ || state->attr_or != _nj_constant_attr_or_) {
        njSetConstantAttr(state->attr_and, state->attr_or);
    }
    njColorBlendingMode(NJD_SOURCE_COLOR, state->blend_src);
    njColorBlendingMode(NJD_DESTINATION_COLOR, state->blend_dst);
    cur = &drawstate_current.colour;
    if (MemEqual(&state->colour, cur, sizeof(NJS_ARGB)) != 1) {
        *cur = state->colour;
        njSetConstantMaterial(&state->colour);
    }
    if (state->fog != 0 && fog_enabled != 0) {
        FogOn();
        drawstate_current.fog = 1;
    } else {
        FogOff();
        drawstate_current.fog = 0;
    }
}

void DrawStateGet(DrawState* out) {
    njMemCopy(out, &drawstate_stack[drawstate_depth], sizeof(DrawState) / 4);
}

s32 DrawStatePop(DrawState* out) {
    if (drawstate_depth > 0) {
        if (out != NULL) {
            njMemCopy(out, &drawstate_stack[drawstate_depth], sizeof(DrawState) / 4);
        }
        drawstate_depth--;
        return 1;
    }
    return 0;
}

s32 DrawStatePush(DrawState* state) {
    if (drawstate_depth < DRAWSTATE_DEPTH - 1) {
        njMemCopy(&drawstate_stack[++drawstate_depth], state, sizeof(DrawState) / 4);
        DrawStateApply(&drawstate_stack[drawstate_depth]);
        return 1;
    }
    return 0;
}

void DrawStateDefault3D(DrawState* out) {
    DrawStateDefault(1, out);
}

void DrawStateDefault2D(DrawState* out) {
    DrawStateDefault(0, out);
}

/* Alpha blended, constant material colour zero, no fog; mode 0 (2D) and 1 (3D) each add one
 * control flag. */
void DrawStateDefault(s32 mode, DrawState* out) {
    out->control3d = 0x328;
    if (mode == 0) {
        out->control3d |= 0x4;
    } else if (mode == 1) {
        out->control3d |= 0x800;
    }
    out->attr_and = -1;
    out->attr_or = 0;
    out->colour.a = 0.0f;
    out->colour.r = 0.0f;
    out->colour.g = 0.0f;
    out->colour.b = 0.0f;
    out->blend_src = NJD_COLOR_BLENDING_SRCALPHA;
    out->blend_dst = NJD_COLOR_BLENDING_INVSRCALPHA;
    out->fog = 0;
}

void DrawStateInit(void) {
    clipz_depth = 0;
    drawstate_depth = 0;
    DrawStateDefault(0, &drawstate_stack[0]);
    njControl3D(drawstate_stack[0].control3d);
    njSetConstantAttr(drawstate_stack[0].attr_and, drawstate_stack[0].attr_or);
    njColorBlendingMode(NJD_SOURCE_COLOR, drawstate_stack[0].blend_src);
    njColorBlendingMode(NJD_DESTINATION_COLOR, drawstate_stack[0].blend_dst);
    njSetConstantMaterial(&drawstate_stack[0].colour);
    if (drawstate_stack[0].fog == 1 && fog_enabled == 1) {
        FogOn();
    } else {
        FogOff();
    }
    MemCopy(&drawstate_current, &drawstate_stack[0], sizeof(DrawState));
}

/* Defined last, in reverse: that reproduces the original .bss/.sbss layout (docs/compiler.md). */
DrawState drawstate_stack[DRAWSTATE_DEPTH];
DrawState drawstate_current;
ClipZ clipz_stack[CLIPZ_DEPTH];
s32 drawstate_depth;
s32 clipz_depth;
