#ifndef NINJA_H
#define NINJA_H

#include "types.h"
#include <dolphin/gx/GXStruct.h>

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
    struct NjTexRef* texaddr; /* defined below */
} NJS_TEXNAME;

typedef struct {
    NJS_TEXNAME* textures;
    u32 nbTexture;
} NJS_TEXLIST;

/* Motion data (Ninja's NJS_MOTION). type: which channels the motion has (1 pos, 2 ang, 4 scl).
 * inp_fn: low nibble = channel count per node, bits 6+ = interpolation kind. */
typedef struct NJS_MOTION {
    void** mdata;
    u32 nbFrame;
    u16 type;
    u16 inp_fn;
} NJS_MOTION;

/* The part of a texture slot handed to the loaders (0x20 bytes). */
typedef struct {
    u32 w00;
    u32 w04;
    u32 w08;
    u32 w0c;
    u32 w10;
    u32 size;  /* 0x14 */
    u32 flags; /* 0x18 */
    void* data; /* 0x1c */
} NjTexBody;

/* Texture memory slot (lbl_80347ECC, 0x48 bytes). */
typedef struct {
    u32 id; /* 0x00, -1 = free */
    NjTexBody body;  /* 0x04 */
    GXTexObj texobj; /* 0x24 */
    s32 refs;        /* 0x44 */
} NjTexMem;

/* Texture reference (lbl_80347ED4, 0x18 bytes); NJS_TEXNAME.texaddr points at one. */
struct NjTexRef {
    u32 w00;
    u32 w04;
    u32 key;      /* 0x08 */
    NjTexMem* mem; /* 0x0c */
    s32 refs;     /* 0x10 */
    u32 w14;
};
typedef struct NjTexRef NjTexRef;

/* njColorBlendingMode targets and modes (Dreamcast Ninja numbering). */
#define NJD_SOURCE_COLOR 0
#define NJD_DESTINATION_COLOR 1
#define NJD_COLOR_BLENDING_INVSRCALPHA 6
#define NJD_COLOR_BLENDING_SRCALPHA 8

void njClipZ(f32 near, f32 far);
void njControl3D(u32 flag);
void njSetConstantAttr(u32 and_attr, u32 or_attr);
void njSetConstantMaterial(NJS_ARGB* mat);

/* njSetTexture: makes texlist the current texture list; returns 1. */
s32 fn_80299040(NJS_TEXLIST* texlist);
void njColorBlendingMode(s32 target, s32 mode);
void njMemCopy(void* dst, const void* src, s32 count); /* count in 32-bit words */
void njUnitMatrix(NJS_MATRIX m);
void njRotateXYZ(NJS_MATRIX m, Angle x, Angle y, Angle z);
void njCalcPoint(NJS_MATRIX m, NJS_POINT3* p, NJS_POINT3* out);

extern u32 _nj_control_3d_flag_;
extern u32 _nj_constant_attr_and_;
extern u32 _nj_constant_attr_or_;

#endif
