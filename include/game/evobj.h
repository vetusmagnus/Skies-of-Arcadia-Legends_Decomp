#ifndef GAME_EVOBJ_H
#define GAME_EVOBJ_H

#include "types.h"
#include "ninja.h"

/* The game's field-map model object (see model.c and evobj.c): the player (lbl_80347450), the work of
 * the story-event, map-object and sparkle tasks and of the field camera tasks. Only the fields the
 * decompiled code uses are named. */
struct NJS_MOTION;

typedef struct {
    void* model;          /* 0x00 */
    u32 pad4;
    NJS_TEXLIST texlist;  /* 0x08 */
} ModelFile;

typedef struct {
    u8 pad0[8];
    ModelFile* body;    /* 0x08 */
    ModelFile* extra;   /* 0x0C */
    ModelFile* spark;   /* 0x10 */
} ModelFiles;

typedef struct {
    s32 count;
    void* items[1]; /* count entries */
} ItemList;

typedef struct {
    u8 pad0[0x14];
    u32 flags;     /* 0x14 */
    u8 pad18[0x24 - 0x18];
    u32 nearDist;  /* 0x24 */
    u32 actDist;   /* 0x28 */
    u32 x2c;       /* 0x2C */
    u32 speed;     /* 0x30 */
    u8 pad34[4];
    s32 mode;      /* 0x38 */
    u32 flag;      /* 0x3C story flag */
} EvInfo;

typedef struct {
    u8 pad0[0x10];
    EvInfo* info;          /* 0x10 */
    ModelFiles* files;     /* 0x14 */
    u8 pad18[4];
    ItemList* items;       /* 0x1C */
    NJS_TEXLIST* texlist;  /* 0x20 */
    u8 pad24[0x44 - 0x24];
    NJS_POINT3 target;     /* 0x44 */
    NJS_POINT3 rot;        /* 0x50 */
} EvExt;

typedef struct {
    u8 pad0[0x18];
    s16 h18;      /* 0x18 */
} EvSub;

typedef struct {
    s32 mode;     /* 0x00 */
} EvMode;

typedef struct {
    u8 pad0[0x28];
    u16 x28;      /* 0x28 */
    u16 id;       /* 0x2A */
    s16 x2c;      /* 0x2C */
    s16 x2e;      /* 0x2E */
} EvHit;

typedef struct {
    u8 pad0[4];
    s32 kind;                /* 0x04 */
    s32 x08;                 /* 0x08 */
    f32 clipNear;            /* 0x0C */
    f32 clipFar;             /* 0x10 */
    u8 pad14[0x1C - 0x14];
    NJS_ARGB colour;         /* 0x1C */
    s32 x2c;                 /* 0x2C */
    u8 pad30[0x38 - 0x30];
    NJS_POINT3 pos;          /* 0x38 */
    Angle ang[3];            /* 0x44 */
    NJS_POINT3 scl;          /* 0x50 */
    NJS_POINT3 vel;          /* 0x5C */
    Angle rotv[3];           /* 0x68 */
    s16 x74;                 /* 0x74 */
    u8 pad76[0xB4 - 0x76];
    NJS_POINT3 pivotPos;     /* 0xB4 */
    u8 padC0[0xE4 - 0xC0];
    void* model;             /* 0xE4 */
    struct NJS_MOTION* motion; /* 0xE8 */
    void* shape;             /* 0xEC */
    u8 padF0[0x100 - 0xF0];
    NJS_TEXLIST* texlist;    /* 0x100 */
    NJS_POINT3 home;         /* 0x104 */
    Angle tgt[3];            /* 0x110 */
    u8 pad11C[0x164 - 0x11C];
    f32 x164;                /* 0x164 */
    s16 state;               /* 0x168 */
    u8 b16a;                 /* 0x16A */
    u8 b16b;                 /* 0x16B */
    s16 pivot;               /* 0x16C */
    u8 pad16E[2];
    u16 motionId;            /* 0x170 */
    u16 x172;                /* 0x172 */
    u8 pad174[2];
    u16 id;                  /* 0x176 */
    u8 pad178[2];
    u16 x17a;                /* 0x17A */
    u8 pad17C[4];
    s32 x180;                /* 0x180 */
    s32 hidden;              /* 0x184 */
    u8 pad188[4];
    f32 x18c;                /* 0x18C */
    f32 speed;               /* 0x190 */
    u8 pad194[4];
    s32 x198;                /* 0x198 */
    u8 pad19C[0x1B8 - 0x19C];
    EvHit* hit;              /* 0x1B8 */
    void* x1bc;              /* 0x1BC */
    u8 pad1C0[0x1C8 - 0x1C0];
    EvExt* ext;              /* 0x1C8 */
    u8 pad1CC[0x1D8 - 0x1CC];
    EvSub* sub;              /* 0x1D8 */
    u8 pad1DC[0x1EC - 0x1DC];
    s8 x1ec;                 /* 0x1EC */
    s8 x1ed;                 /* 0x1ED */
    s8 x1ee;                 /* 0x1EE */
    u8 pad1EF[0x1FC - 0x1EF];
    s16 x1fc;                /* 0x1FC */
    s16 x1fe;                /* 0x1FE */
    s16 x200;                /* 0x200 */
    s16 x202;                /* 0x202 */
    s16 x204;                /* 0x204 */
    s16 x206;                /* 0x206 */
    s16 x208;                /* 0x208 */
    s16 x20a;                /* 0x20A */
    Angle x20c;              /* 0x20C */
    u32 x210;                /* 0x210 */
    u8 pad214[0x21C - 0x214];
    u8 x21c;                 /* 0x21C */
    u8 x21d;                 /* 0x21D */
    u8 x21e;                 /* 0x21E */
    u8 x21f;                 /* 0x21F */
    u8 pad220[0x22C - 0x220];
    u16 x22c;                /* 0x22C frame counter */
    u16 x22e;                /* 0x22E colour key index */
    u16 x230;                /* 0x230 */
    u16 point;               /* 0x232 */
    u8 pad234[0x23C - 0x234];
    s32 x23c;                /* 0x23C sound handle */
    s32 x240;                /* 0x240 sound handle */
    u8 pad244[0x24C - 0x244];
    NJS_POINT3 x24c;         /* 0x24C */
    u8 pad258[0x260 - 0x258];
    EvMode* mapMode;         /* 0x260 */
} EvObj;

#endif
