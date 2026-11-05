#ifndef GAME_CHR_H
#define GAME_CHR_H

#include "types.h"
#include "ninja.h"

/* The battle characters: lbl_80309DE4 holds each one's static record, a character task's work is a ChrWork whose
 * 0x4C is the ChrInfo, and lbl_8030A10C is the battle state with the 9x9 position grid. */
struct ChrAux;
typedef struct Ent_80008800 Ent_80008800;

typedef struct ChrRec {
    s16 x0;             /* 0x00 */
    u8 pad_2[6];
    s16 x8;             /* 0x08 */
    u8 pada[0x14 - 0xa];
    s32 x14;
    s32 x18;
    s32 bits;           /* 0x1c */
    u8 pad20[0x40 - 0x20];
    s16 stat[4];        /* 0x40 */
    u8 pad48[0x86 - 0x48];
    s16 x86;            /* 0x86 */
    s16 x88;
    u8 pad8a[0x94 - 0x8a];
    s16 x94;            /* 0x94 */
    s16 x96;            /* 0x96 */
    u8 pad98[0x9a - 0x98];
    s16 x9a;            /* 0x9a */
    s16 x9c;            /* 0x9c */
    u8 pad9e[0xae - 0x9e];
    s16 xae;            /* 0xae */
    u8 padb0[0xb4 - 0xb0];
    s16 xb4;            /* 0xb4 */
    s16 xb6;            /* 0xb6: weapon id */
    u8 padb8[0x100 - 0xb8];
    u8 x100;            /* 0x100 */
    u8 pad101[0x110 - 0x101];
    struct ChrAux* x110; /* 0x110 */
} ChrRec;
extern ChrRec* lbl_80309DE4[];
/* A linked condition record (fn_800085EC walks the list). */
typedef struct CondLink {
    s16 x0;
    s16 x2;
    s16 x4;                 /* 0x4: first table index (fn_8000832C) */
    s16 x6;                 /* 0x6: end index */
    struct CondLink* next;  /* 0x8 */
    struct CondLink* prev;  /* 0xc */
} CondLink;
/* Event-target object referenced by an id record (x0 type, x4 id, x10 result). */
typedef struct Key {
    s16 x0;
    s16 x2;
    s16 x4;
    u8 pad6[2];
    u32 x8;
    u8 padc[0x10 - 0xc];
    s16 x10;
    u8 pad12[0x18 - 0x12];
} Key;
/* 0x10-byte id record; lists end at a negative x0. */
struct Ent_80008800 {
    s16 x0;
    s16 x2;
    u8 pad4[8];
    Key* xc;
};
typedef struct {
    u8 pad0[0xc];
    void* xc;           /* 0x0c */
    Ent_80008800* x10;  /* 0x10 condition id table */
    s8 x14[9][9];       /* 0x14 party grid */
    u8 pad65[0x68 - 0x65];
    void* x68;
    u32 x6c;
    u8 pad70[0xec - 0x70];
    f32 xec;            /* 0xec speed scale */
    s16 xf0;
    u8 padf2[0x180 - 0xf2];
    void* x180;         /* 0x180 */
    CondLink* x184;     /* 0x184 */
    u8 pad188[0x1c4 - 0x188];
    s32 x1c4;
} GS;
extern GS lbl_8030A10C;
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
    u8 pad158[0x15c - 0x158];
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
typedef struct ChrWork {
    void* x0;           /* 0x00 model */
    u8 pad4[4];
    NJS_TEXLIST* x8;    /* 0x08 */
    u8 padc[4];
    Obj_80017B18 *x10; /* 0x10 */
    s16 x14;            /* 0x14 */
    u8 pad16[0x1c - 0x16];
    NJS_POINT3 pos;     /* 0x1c */
    Angle rx, ry, rz;   /* 0x28 */
    NJS_POINT3 scl;     /* 0x34 */
    u8 pad40[4];
    u8 x44;             /* 0x44 */
    u8 pad45[0x48 - 0x45];
    NJS_TEXLIST* x48;   /* 0x48 */
    ChrInfo *st; /* 0x4c */
} ChrWork;

#endif
