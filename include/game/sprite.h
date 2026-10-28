#ifndef GAME_SPRITE_H
#define GAME_SPRITE_H

#include "game/drawstate.h"
#include "game/task.h"
#include "game/util.h"

/* Menu sprites and layouts: a sprite is a list of pieces (textured quads), a layout a list of
 * sprites with offsets; see docs/ui.md. */

/* 2D vertex for fn_80291064 (0x18 bytes). */
typedef struct {
    f32 x, y, z;
    f32 u, v;
    u32 colour;
} Vertex2D;

/* A sprite frame (0x14): texture index and UV rect. */
typedef struct {
    u32 tex;
    f32 u0, v0, u1, v1;
} SpriteFrame;

/* A sprite piece (0x34): frame index, screen rect relative to the sprite origin, colour. */
typedef struct {
    u32 frame;            /* 0x00 */
    f32 x0, y0, x1, y1;   /* 0x04 */
    u32 colour;           /* 0x14 */
    u8 pad18[0x34 - 0x18];
} SpritePiece;

typedef struct {
    SpriteFrame* frames; /* 0x00 */
    SpritePiece* pieces; /* 0x04 */
    u32 count;           /* 0x08 */
    u8 pad0C[0x14 - 0x0C];
    f32 x, y;            /* 0x14 origin */
} Sprite;

/* A sprite drawn as an object (fn_801C4074, fn_801C4B88, fn_801C4D00). */
typedef struct {
    Sprite* sprite;       /* 0x00 */
    f32 z;                /* 0x04 */
    f32 a, b;             /* 0x08 colour modulation for fn_801D65B4 */
    NJS_TEXLIST* texlist; /* 0x10 */
    u32 colour;           /* 0x14 used instead of the piece colour when flags & 8 */
    u16 flags;            /* 0x18 */
} SpriteObj;



/* A layout part (0x14). */
typedef struct {
    u16 bank;    /* 0x00 */
    u16 sprite;  /* 0x02 */
    f32 x, y, z; /* 0x04 */
    u16 texlist; /* 0x10 */
    u16 flags;   /* 0x12 */
} LayoutPart;

/* Draw count layout parts at pos; texlists is indexed by each part's texlist. */
s32 UiLayoutDraw(NJS_TEXLIST** texlists, const LayoutPart* parts, u32 count, f32* pos, f32 z, f32 a, f32 b);
s32 UiLayoutDrawPart(NJS_TEXLIST** texlists, const LayoutPart* parts, s32 count, f32* pos, f32 z, f32 a, f32 b,
                     u16 index);

/* Colour from fn_801D65B4: four bytes, packed by callers as a<<24 | r<<16 | g<<8 | b
 * (byte 0 is shifted by 24). */
typedef struct { u8 c[4]; } Colour4;

/* lbl_803082D0 (0x28): the menu sprite system. */
typedef struct {
    void* file;          /* 0x00 loaded menu file (->0x4 ->0x20 is a texlist-like thing) */
    u32 pad04;
    NJS_TEXLIST* texlist8;  /* 0x08 the menu file's texlist */
    NJS_TEXLIST* textlistC; /* 0x0C = &lbl_80347568 */
    void* tex10;         /* 0x10 */
    void* banks[4];      /* 0x14 sprite banks (fn_801D68C4 takes one) */
    void* data24;        /* 0x24 */
} SpriteSystem;

extern SpriteSystem menu_sprites;
extern Vertex2D sprite_verts[4];

Sprite* fn_801D68C4(void* bank, u16 index);
s32 fn_80227810(NJS_TEXLIST* texlist);
void fn_802275A4(NJS_TEXLIST* texlist, s32 a);
f32 fn_801DBD9C(f32 z);
void fn_801D65B4(u32 colour, Colour4* out, f32 a, f32 b);
void fn_80299040(NJS_TEXLIST* texlist);
void fn_80297DC8(void* tex);
void fn_80291064(Vertex2D* v, s32 count, s32 mode);

/* --- types local to this part --- */


/* One quad being built (SpriteQuadBuildScaled). */
typedef struct {
    Vertex2D* verts;    /* 0x00 */
    SpriteFrame* frame; /* 0x04 */
    SpritePiece* piece; /* 0x08 */
    f32 x, y, z;        /* 0x0C */
    u32 colour;         /* 0x18 */
} SpriteQuad;

typedef struct {
    Sprite* sprite;       /* 0x00 */
    NJS_TEXLIST* texlist; /* 0x04 */
    u32 colour;           /* 0x08 */
    f32 x, y, z;          /* 0x0C */
    f32 a, b;             /* 0x18 */
    f32 sx, sy;           /* 0x20 */
    u16 flags;            /* 0x28 */
    u16 flip;             /* 0x2A */
} SpriteObjScaled;

#endif
