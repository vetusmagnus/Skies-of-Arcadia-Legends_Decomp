#ifndef GAME_EVOBJ_H
#define GAME_EVOBJ_H

#include "types.h"
#include "ninja.h"

/* The game's field-map model object (see model.c and evobj.c): the player (lbl_80347450), the work of
 * the story-event, map-object and sparkle tasks and of the field camera tasks. Only the fields the
 * decompiled code uses are named. */
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

/* One entry of a map object's script (EvObj.script). */
typedef struct {
    s16 h0;
    s16 h2;
    f32 f4;
    NJS_TEXLIST* w8;
    void* wc;
    NJS_MOTION* motion;
    void* w14;
    f32 f18;
    f32 f1c;
    s32 w20;
    s32 w24;
    u8 pad28[4];
} EvScriptEntry;

typedef struct {
    s16 h0;
    s16 h2;
    u8 pad4[0x14];
    EvScriptEntry entries[1];
} EvScript;

/* The object definition record (EvExt.info): the common part below, then the fields of each object
 * kind (trail, sparkle, map object) from 0x24 on. */
typedef struct {
    s32 count;     /* 0x00 */
    s32 w4;        /* 0x04 */
    u8 pad8[0x10 - 8];
    s32 x10;       /* 0x10 */
    u32 flags;     /* 0x14 */
    u32 x18;       /* 0x18 texture id / flags */
    u8 pad1c[0x20 - 0x1c];
    u32 x20;       /* 0x20 */
    u32 nearDist;  /* 0x24 */
    u32 actDist;   /* 0x28 */
    u32 x2c;       /* 0x2C */
    u32 speed;     /* 0x30 */
    u32 x34;       /* 0x34 */
    s32 mode;      /* 0x38 */
    u32 flag;      /* 0x3C story flag */
    s32 x40;       /* 0x40 */
    s32 x44;       /* 0x44 */
    s32 x48;       /* 0x48 */
    u32 x4c;       /* 0x4C */
    u32 x50;       /* 0x50 */
    u32 x54;       /* 0x54 trail mode */
    u32 x58;       /* 0x58 */
    u32 x5c, x60, x64; /* 0x5C */
    NJS_POINT3 offA; /* 0x68 */
    NJS_POINT3 offB; /* 0x74 */
    u32 life;      /* 0x80 */
    u32 total;     /* 0x84 */
    u32 fadeIn;    /* 0x88 */
    u32 seg;       /* 0x8C */
    u32 x90;       /* 0x90 */
    s32 scrollU;   /* 0x94 */
    s32 scrollV;   /* 0x98 */
} EvInfo;

typedef struct {
    u8 pad0[0x10];
    EvInfo* info;          /* 0x10 */
    ModelFiles* files;     /* 0x14 */
    u8 pad18[4];
    ItemList* items;       /* 0x1C */
    NJS_TEXLIST* texlist;  /* 0x20 */
    u8 pad24[0x34 - 0x24];
    s32 x34;               /* 0x34 */
    u8 pad38[0x44 - 0x38];
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
    u8 pad0[0x24];
    u16 h24;      /* 0x24 */
    u8 pad26[2];
    u16 x28;      /* 0x28 */
    u16 id;       /* 0x2A */
    s16 x2c;      /* 0x2C */
    s16 x2e;      /* 0x2E */
} EvHit;

/* The object's collision record (0x1BC), refreshed by fn_80222838. */
typedef struct EvColl {
    s32 (*cb)(struct EvColl *, struct EvColl *); /* 0x00 */
    struct EvColl *p4;       /* 0x04 */
    u8 pad8[0x10 - 8];
    u16 mask10;              /* 0x10 */
    u16 id12;                /* 0x12 */
    s16 h14;                 /* 0x14 */
    u16 h16;                 /* 0x16 */
    f32* pos;                /* 0x18 */
    u8 pad1c[4];
    u32* ang;                /* 0x20 */
} EvColl;

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
    NJS_MOTION* motion;      /* 0xE8 */
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
    s16 x16e;                /* 0x16E */
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
    u8 pad19C[0x1AC - 0x19C];
    s32 x1ac;                /* 0x1AC */
    s32 x1b0;                /* 0x1B0 */
    void* x1b4;              /* 0x1B4 */
    EvHit* hit;              /* 0x1B8 */
    EvColl* coll;            /* 0x1BC */
    u8 pad1C0[4];
    void* x1c4;              /* 0x1C4 */
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
    s32 x214;                /* 0x214, with x20c/x210 the saved angles */
    u8 pad218[0x21C - 0x218];
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
    u8 pad244[0x248 - 0x244];
    void* x248;              /* 0x248 */
    NJS_POINT3 x24c;         /* 0x24C */
    u8 pad258[4];
    void* x25c;              /* 0x25C */
    EvMode* mapMode;         /* 0x260 */
} EvObj;

#endif
