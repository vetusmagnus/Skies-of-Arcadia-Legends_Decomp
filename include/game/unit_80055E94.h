#ifndef GAME_UNIT_80055E94_H
#define GAME_UNIT_80055E94_H

#include "types.h"
#include "game/task.h"
#include <math.h>
#include "game/stat_8030B4D4.h"
#include "ninja.h"
#include "game/drawstate.h"
#include "game/gamedata.h"
#include "game/sprite.h"
#include "game/save_8030B7F4.h"

/* A loaded model file's materials (fn_8006D080 frees them). */
typedef struct MdlMat { char *cur; u32 x4; NJS_TEXLIST tex; } MdlMat;
typedef struct MdlRec {
    u8 pad0[0x14];
    struct { u32 x0; MdlMat* x4; }* x14;
    u8 pad18[8];
    NJS_TEXLIST* x20;
    u8 pad24[0x68 - 0x24];
} MdlRec;
typedef struct MdlBlk { u32 n; MdlRec* r; } MdlBlk;
typedef struct Node {
    u32 x0;
    s16 count;           /* 0x04 reference count */
    u8 pad6[2];
    MdlBlk *blk;         /* 0x08 */
    char name[0x20];     /* 0x0C */
    void *x2c;           /* 0x2C */
    struct Arg80067CA4 *x30; /* 0x30 */
    struct Node* prev;   /* 0x34 */
    struct Node* x38;    /* 0x38 next */
    u32 flags;           /* 0x3C */
    u8 pad40[4];
} Node;
typedef struct { u32 handle; s8 id; u8 kind; s16 s; u8 pad8[8]; } Slot_8030A10C;
typedef struct {
    u32 f0;
    u8 pad4[4];
    struct TkRec *x8;           /* 0x08 */
    u8 padc[4];
    struct Ent_80008800 *x10;   /* 0x10 condition id table */
    u8 pad14[0x68 - 0x14];
    u32 f68;
    u32 f6c;
    u8 pad70[4];
    u32 x74;
    u32 x78;
    u32 x7c;
    u32 x80;
    u8 x84[0x20];
    u8 xa4[0xCC - 0xA4];
    Slot_8030A10C e[2];
    u8 pad_ec[0xF8 - 0xEC];
    void *pf8;
    void *pfc;
    void *p100;
    void *a104[12];
    u32 a134[12];
    u8 pad164[4];
    void *f168;
    u8 b16c;
    u8 b16d;
    s8 b16e;
    u8 b16f;
    u8 b170;
    u8 pad171[0x184 - 0x171];
    struct CondLink *x184;      /* 0x184 condition list */
    u8 pad188[0x1C4 - 0x188];
    s32 count;
    u8 pad1c8[4];
    u32 f1cc;
} Sys_8030A10C;
extern Sys_8030A10C lbl_8030A10C;
typedef struct WorkRec {
    s16 x0;
    s16 x2;
    u32 x04;
    u8 pad8[8];
    void (*x10)(void);
    u8 pad14[0x38 - 0x14];
    s32 x38;
    s32 x3c;
    s32 x40;
    s16 x44;
    s16 x46;
    s16 x48;
    s16 x4a;
    u8 pad4c[4];
    u8 x50;
} WorkRec;
typedef struct TkRec {
    void (*proc)(struct TkRec *); /* 0x00 */
    u8 pad_4[0x14];
    u8 flags;
    u8 state;           /* 0x19 */
    u8 pad_1a[0xa];
    WorkRec *work;
} TkRec;
typedef struct Ent6EB88 {
    s32 f0;
    void *f4;
    char f8[0x10];
    s32 f18;
} Ent6EB88;
extern s32 sprintf(char *, const char *, ...);
/* Model table entry of a battle character record. */
typedef struct Rec18 {
    s16 type;           /* 0x00 */
    s16 s2;             /* 0x02 */
    s16 s4;             /* 0x04 */
    u8 pad6[2];
    u32 flags8;         /* 0x08 */
    s16 sc;             /* 0x0C */
    u8 pade[2];
    f32 f10;            /* 0x10 */
    f32 f14;            /* 0x14 */
} Rec18;
/* The battle character task as fn_800631B0 and fn_800565B0 see it (position as an array). */
typedef struct {
    s8 b0;               /* 0x00 */
    u8 pad1[3];
    u8 b4;               /* 0x04 */
    u8 pad5;
    s16 h6;              /* 0x06 */
    s16 h8;              /* 0x08 */
    u8 padA[0x5a - 0xa];
    u8 b5a;              /* 0x5A */
    u8 pad5b;
    struct { u8 pad[4]; u32 w4; }* p5c; /* 0x5C */
    u8 pad60[0x8c];
    u32 fec;             /* 0xEC */
    u32 ff0;             /* 0xF0 */
    u8 padF4[0x154 - 0xf4];
    void* p154;          /* 0x154 */
    u8 pad158[0x164 - 0x158];
    f32 f164;            /* 0x164 */
    u8 pad168[0x94];
    void* p1fc;          /* 0x1FC */
    u8 pad200[8];
    f32 f208;            /* 0x208 */
} CamChr;
typedef struct {
    u8 pad0[0x1c];
    f32 pos[3];          /* 0x1C */
    s32 rot[3];          /* 0x28 */
    f32 scale[3];        /* 0x34 */
    u8 pad40[0xc];
    CamChr* chr;         /* 0x4C */
} CamBody;
typedef struct {
    u8 pad0[0x24];
    CamBody* body;       /* 0x24 */
} CamObj;
extern void fn_80217830(s32);
extern s32 SePlay(s32 bank, s8 arg1, s8 id);
typedef struct Motion {
    void* data;
    u32 nbFrame;
} Motion;
typedef struct Node_8006D888 {
    s32 x0;              /* id */
    s32 x4;              /* busy */
    u8 pad8[4];
    struct Node_8006D888 *xc;  /* prev */
    struct Node_8006D888 *x10; /* next */
} Node_8006D888;
extern void fn_8006E75C(Ent6EB88 *, char *, s32);
extern void fn_8006C8DC(char *, char *);
s32 fn_8001D944(u8 id, void *t);
extern Task *lbl_80309E24[14];
extern Task *lbl_80309E24[14];
extern Task *lbl_80309E24[14];
typedef struct Base80067CA4 {
    u8 d[0x4c];
} Base80067CA4;
typedef struct Src80067CA4 {
    u8 pad0[4];
    Base80067CA4 *base;
} Src80067CA4;
typedef struct Arg80067CA4 {
    s16 x0;
    s16 x2;
    Src80067CA4 *src;
    s32 count;
    Rec18 *list;
    s16 s10;
    s16 s12;
    s32 w14;
    s32 w18;
    s32 w1c;
} Arg80067CA4;
s32 fn_8006DC6C(void);
#define CLAMP3(a, b, c)    \
    if ((a) < 0.0f) {      \
        (a) = 0.0f;        \
    }                      \
    if ((b) < 0.0f) {      \
        (b) = 0.0f;        \
    }                      \
    if ((c) < 0.0f) {      \
        (c) = 0.0f;        \
    }                      \
    if ((a) > 1.0f) {      \
        (a) = 1.0f;        \
    }                      \
    if ((b) > 1.0f) {      \
        (b) = 1.0f;        \
    }                      \
    if ((c) > 1.0f) {      \
        (c) = 1.0f;        \
    }

#endif
