#ifndef GAME_DRAW2D_H
#define GAME_DRAW2D_H

#include "types.h"

/* Vertex layouts of the 2D/3D quad helpers in draw2d.c, also built by bevent.c, unit_8008B4A0.c,
 * unit_800D81E8.c, unit_8010E164.c, unit_80199B9C.c, unit_801CBA60.c, unit_801D24D0.c and
 * unit_80219378.c. unit_8009D274.c has its own copies with a Colour4 colour. */
/* A textured vertex: position, uv and colour. */
typedef struct {
    f32 x, y, z, u, v;
    u32 colour;
} VertexTex;
/* A coloured vertex: position and colour. */
typedef struct {
    f32 x, y, z;
    u32 colour;
} VertexCol;

#endif
