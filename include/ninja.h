#ifndef NINJA_H
#define NINJA_H

#include "types.h"

/* Sega's Ninja graphics library (GameCube build). There's no symbol map for it, so these are
 * Ninja API names given by behavior; docs/ninja.md has the evidence. */

typedef struct {
    f32 a, r, g, b;
} NJS_ARGB;

typedef struct {
    f32 x, y, z;
} NJS_POINT3;
typedef NJS_POINT3 NJS_VECTOR;
typedef f32 NJS_MATRIX[16]; /* Dreamcast layout (Float[16]), 0x40 bytes */
typedef s32 Angle;          /* 0x10000 per turn */

typedef struct {
    void* filename;
    u32 attr;
    void* texaddr;
} NJS_TEXNAME;

typedef struct {
    NJS_TEXNAME* textures;
    u32 nbTexture;
} NJS_TEXLIST;

/* njColorBlendingMode targets and modes (Dreamcast Ninja numbering). */
#define NJD_SOURCE_COLOR 0
#define NJD_DESTINATION_COLOR 1
#define NJD_COLOR_BLENDING_INVSRCALPHA 6
#define NJD_COLOR_BLENDING_SRCALPHA 8

void njClipZ(f32 near, f32 far);
void njControl3D(u32 flag);
void njSetConstantAttr(u32 and_attr, u32 or_attr);
void njSetConstantMaterial(NJS_ARGB* mat);
void njColorBlendingMode(s32 target, s32 mode);
void njMemCopy(void* dst, const void* src, s32 count); /* count in 32-bit words */
void njUnitMatrix(NJS_MATRIX m);
void njRotateXYZ(NJS_MATRIX m, Angle x, Angle y, Angle z);
void njCalcPoint(NJS_MATRIX m, NJS_POINT3* p, NJS_POINT3* out);

extern u32 _nj_control_3d_flag_;
extern u32 _nj_constant_attr_and_;
extern u32 _nj_constant_attr_or_;

#endif
