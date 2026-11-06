#ifndef GAME_CHRINFO_H
#define GAME_CHRINFO_H

#include "types.h"
#include "ninja.h"

typedef struct Ent_80008800 Ent_80008800;

/* A battle character's state and what it points to, apart from the battle globals of chr.h. */
/* A linked condition record (fn_800085EC walks the list). */
typedef struct CondLink {
    s16 x0;
    s16 x2;
    s16 x4;                 /* 0x4: first table index (fn_8000832C) */
    s16 x6;                 /* 0x6: end index */
    struct CondLink* next;  /* 0x8 */
    struct CondLink* prev;  /* 0xc */
} CondLink;
typedef struct ChrMot {
    u8 pad0[4];
    u32 x4;
} ChrMot;
/* One motion entry of a character (0x18 bytes). */
typedef struct ChrAnim {
    s16 x0;
    s16 x2;             /* 3 ends the table */
    s16 x4;
    s16 x6;
    u32 flags;
    s16 xc;
    s16 xe;
    f32 x10;
    f32 x14;
} ChrAnim;
/* A character's draw parameters (fn_80018B80 turns them into a DrawState). */
typedef struct ChrDraw {
    f32 a;              /* 0x00 colour */
    f32 r;
    f32 g;
    f32 b;
    u8 pad10[8];
    s32 blend_src;      /* 0x18 */
    s32 blend_dst;      /* 0x1c */
    u8 pad20[8];
    s32 x28;            /* 0x28: not 1 clears control3d 0x40 */
    s32 fog;            /* 0x2c */
    s32 x30;            /* 0x30: nonzero calls fn_80060950 */
} ChrDraw;
/* One 0x34-byte joint of a character's skeleton (ChrInfo 0x154). */
typedef struct Joint { u8 pad[8]; u8 data[0x34 - 8]; } Joint;
typedef struct ChrInfo {
    s8 id;              /* 0x00 */
    u8 pad1;
    s16 x2;             /* 0x02 kind */
    s8 target;          /* 0x04 */
    u8 pad5;
    s16 x6;             /* 0x06 */
    s16 x8;             /* 0x08 */
    s16 xa;             /* 0x0a */
    u8 padC[4];
    s16 x10;            /* 0x10 */
    s16 state;          /* 0x12 */
    s16 x14;            /* 0x14 */
    s16 x16;            /* 0x16 */
    s16 x18;            /* 0x18 */
    s16 x1a;            /* 0x1a */
    s16 x1c;            /* 0x1c previous action */
    u8 pad_1e[2];
    s16 x20;            /* 0x20 */
    u8 pad22[6];
    s8 x28[10];         /* 0x28 recent ids, -1 = free */
    u8 pad32[0x44 - 0x32];
    u32 x44;            /* 0x44 status bits */
    s8 x48;             /* 0x48 */
    u8 pad_49;
    s16 x4a;            /* 0x4a */
    s16 x4c;            /* 0x4c */
    u8 pad4e[2];
    u32 x50;            /* 0x50 draw flags */
    u8 pad54[0x8];
    ChrMot* x5c;        /* 0x5c */
    void* x60;          /* 0x60 */
    s16 x64;            /* 0x64 */
    u8 pad66[2];
    f32 x68;            /* 0x68 */
    f32 x6c;            /* 0x6c frame step */
    s32 x70;            /* 0x70 */
    u8 x74[0x10];       /* 0x74 */
    u8 x84[0x10];       /* 0x84 */
    u8 pad94[0xdc - 0x94];
    ChrAnim* anims;     /* 0xdc */
    s32 xe0;            /* 0xe0 */
    s16 xe4;            /* 0xe4 */
    s16 xe6;            /* 0xe6 */
    s16 xe8;            /* 0xe8 */
    s16 xea;            /* 0xea */
    u32 xec;            /* 0xec */
    u32 xf0;            /* 0xf0 */
    u32 xf4;            /* 0xf4 */
    NJS_POINT3 pos;     /* 0xf8 */
    f32 x104[3];        /* 0x104 */
    NJS_POINT3 x110;    /* 0x110 target */
    f32 x11c;           /* 0x11c turn from */
    f32 x120;           /* 0x120 turn to */
    f32 x124;           /* 0x124 turn step */
    f32 x128;           /* 0x128 turn speed */
    f32 x12c;
    f32 x130;
    s32 x134;           /* 0x134 */
    s16 x138;           /* 0x138 */
    u8 pad13a[2];
    NJS_POINT3 x13c;    /* 0x13c saved pos */
    Angle x148[3];      /* 0x148 saved angles */
    Joint* x154;        /* 0x154 joints */
    void* x158;         /* 0x158 */
    f32 x15c;           /* 0x15c */
    f32 x160;           /* 0x160 alpha */
    ChrDraw draw;       /* 0x164 */
    u8 pad198[0x1dc - 0x198];
    void* x1dc;         /* 0x1dc */
    struct Task* x1e0;  /* 0x1e0 attached objects */
    struct Task* x1e4;
    struct Task* x1e8;
    u32 x1ec;           /* 0x1ec */
    u8 x1f0;
    u8 x1f1;
    u8 pad1f2[2];
    NJS_TEXLIST* x1f4;  /* 0x1f4 */
    s16 x1f8;           /* 0x1f8 timer */
    u8 pad1fa[2];
    void* x1fc;         /* 0x1fc matrix */
    u8 pad200[0x204 - 0x200];
    s16 x204;           /* 0x204 */
    u8 pad206[0x20c - 0x206];
    s16 x20c;           /* 0x20c */
    s16 x20e;           /* 0x20e */
    s16 x210;           /* 0x210 */
    s16 x212;           /* 0x212 */
    u32 x214;           /* 0x214 */
    u8 pad218[0x264 - 0x218];
    f32 x264;           /* 0x264 overlay alpha (fn_80018868) */
    f32 x268;           /* 0x268 overlay scale */
    f32 x26c;
    f32 x270;
    f32 x274;           /* 0x274 overlay offset */
    f32 x278;
    f32 x27c;
    s32 x280;           /* 0x280 overlay angles */
    s32 x284;
    s32 x288;
    u8 x28c;            /* 0x28c rotation order */
    u8 pad28d[0x294 - 0x28d];
    s16 x294;           /* 0x294 texture variant */
    s8 x296;            /* 0x296 draw kind */
    u8 pad297;
    CondLink* x298;     /* 0x298 condition list (fn_800193B8) */
} ChrInfo;
typedef struct Obj_80017B18 {
    u8 pad0[0xc];
    char xc[0x24];      /* 0x0c name */
    Ent_80008800 *x30;
    u8 pad34[0x40 - 0x34];
    f32 x40;            /* 0x40 cached height (fn_800177C0) */
} Obj_80017B18;

#endif
