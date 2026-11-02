#ifndef GAME_CAMP_H
#define GAME_CAMP_H

#include "types.h"
#include "game/task.h"
#include "game/uiobj.h"

/* Types shared by the camp (pause) menu units: unit_8015DC6C.c, unit_801719D0.c, unit_80193F28.c
 * and unit_80199B9C.c (docs/ui.md, "Camp (pause) menu"). */
typedef struct Fx_801677D0 Fx_801677D0;
typedef struct Obj_80169360 Obj_80169360;
/* A cursor of a camp menu screen: the selected row and the mask of the rows that can be
   selected (fn_8019A21C). */
typedef struct CampCur {
    s32 x0;     /* 0x00 */
    s32 sel;    /* 0x04 */
    s32 x8;     /* 0x08 */
    u32 mask;   /* 0x0C */
} CampCur;
/* The control block of one camp menu screen (lbl_80307638 has one per screen); the camp menu
   task's work points at the current one. */
typedef struct CampCtrl {
    CampCur cur[7]; /* 0x00 */
    s32 state;      /* 0x70 */
    f32 f74;        /* 0x74 */
} CampCtrl;
typedef struct CampHold {
    CampCtrl *ctrl; /* 0x00 */
} CampHold;
/* The camp menu task (lbl_8034710C). */
typedef struct CampTask {
    u8 pad0[0x24];
    CampHold *holder; /* 0x24 */
} CampTask;
/* A camp menu panel's window: the panel task's work. */
typedef struct CampWin {
    s32 x0;          /* 0x00 */
    s32 x4;          /* 0x04 */
    UiObj obj;       /* 0x08 */
    u8 pad54[0x74 - 0x54];
    f32 f74;         /* 0x74 */
    u8 pad78[0xBC - 0x78];
    void *xbc;       /* 0xBC */
} CampWin;
/* A camp menu panel task. */
typedef struct CampPnl {
    u8 pad0[0x24];
    CampWin *win;    /* 0x24 */
} CampPnl;
/* lbl_803072E8: 0x2c-byte item entries (fn_80195B38 fills them; x4 is the item id). */
typedef struct Ent2c {
    u8 x0;
    u8 x1;
    u8 pad2[2];
    s32 x4;
    s32 x8;
    u32 xc;
    s32 x10, x14, x18, x1c, x20, x24, x28;
} Ent2c;
typedef struct Sys_80310A1C {
    u8 pad0[6];
    s8 f6;      /* 0x06 */
    u8 pad7[0x30 - 7];
    s8 x30;     /* 0x30 */
    u8 pad31[0x120 - 0x31];
} Sys_80310A1C;
typedef struct { f32 f0, f4; s32 i8, ic; u8 pad10[8]; f32 f18, f1c; } Pos_80188274;
typedef struct { u8 pad0[0x14]; s32 sel; } Sel_80188098;
typedef struct { Sel_80188098 *sel; s8 mask; } Inn_80188098;
typedef struct {
    u8 pad00[0x20];
    void* x20;
} Sub20;
typedef struct {
    u8 pad00[4];
    Sub20* x4;
} Obj4;
typedef struct {
    f32 f0, f4, f8, fc;
} F4;
typedef struct EntD_801687E0 {
    s32 f0, f4;
    s32 f8;
    u8 fc, fd; s8 fe; s8 ff;
    s16 f10;
    s16 f12;
    s32 f14;
    s32 f18;
    f32 f1c, f20, f24, f28;
    s32 f2c;
    struct Ent_801687E0 *f30;
    struct Ent_801687E0 *f34;
    u8 pad[0x4c - 0x38];
} EntD_801687E0;
typedef struct Ent_801687E0 {
    u8 pad[0x24];
    EntD_801687E0 *d;
} Ent_801687E0;
typedef struct EntD_801694FC {
    s32 f0, f4;
    s32 f8;
    u8 fc, fd; s8 fe; u8 ff;
    s16 f10;
    s16 f12;
    s32 f14;
    s32 f18;
    f32 f1c, f20, f24;
    s32 f28;
    s32 f2c;
    struct Ent_801694FC *f30;
    struct Ent_801694FC *f34;
    u8 pad[0x4c - 0x38];
} EntD_801694FC;
typedef struct Ent_801694FC {
    u8 pad[0x24];
    EntD_801694FC *d;
} Ent_801694FC;
typedef struct Sub_80169360 {
    s32 w0;
    s32 w4;
    u8 pad8[4];
    u8 bC;
    u8 bD;
    u8 pad_e[0x22];
    Obj_80169360* prev;
    Obj_80169360* next;
} Sub_80169360;
struct Obj_80169360 {
    u8 pad0[0x18];
    u8 flags;
    u8 state;
    u8 pad1a[0xA];
    Sub_80169360* sub;
};
typedef struct { s32 hide; s32 pad4; UiObj obj; } Win;
typedef struct Sub_80168398 {
    s32 w0;
    s32 w4;
    s32 w8;
    u8 bC;
    u8 bD;
    s8 bE;
    s8 bF;
    s16 h10;
    s16 h12;
    s32 w14;
    u32 flags;
    f32 f1c;
    f32 f20;
    f32 f24;
    f32 f28;
    s32 w2c;
    struct Obj_80168398* w30;
    struct Obj_80168398* w34;
    u8 pad[0x14];
} Sub_80168398;
typedef struct Obj_80168398 {
    u8 pad[0x24];
    Sub_80168398* sub;
} Obj_80168398;
typedef struct Sub_80169144 {
    s32 w0;
    s32 w4;
    s32 w8;
    u8 bC;
    u8 bD;
    s8 bE;
    s8 bF;
    s16 h10;
    s16 h12;
    s32 w14;
    u32 flags;
    f32 f1c;
    f32 f20;
    f32 f24;
    f32 f28;
    s32 w2c;
    struct Obj_80169144* w30;
    struct Obj_80169144* w34;
    u8 pad[0x14];
} Sub_80169144;
typedef struct Obj_80169144 {
    u8 pad[0x24];
    Sub_80169144* sub;
} Obj_80169144;
typedef struct { s32 hide; } Win_80177D7C;
typedef struct { u8 pad[0x24]; Win_80177D7C* in; } Pnl_80177D7C;
typedef struct {
    u8 pad0[8];
    UiObj ui;
} Win_80172C60;
typedef struct {
    u8 pad0[0x24];
    Win_80172C60* win;
} Pnl_80172C60;
typedef struct {
    u32 x0;
    s32 id;
    s32 x8;
    u8 xc;
    u8 xd;
    s8 xe;
    u8 padf;
    s16 x10;
    u8 pad12[6];
    u32 x18;
    f32 x1c;
    f32 x20;
    f32 x24;
    f32 x28;
    Task *x2c;
    Fx_801677D0 *x30;
    Fx_801677D0 *x34;
    s32 x38;
    f32 x3c;
    f32 x40;
    f32 x44;
    f32 x48;
} St_801677D0;
struct Fx_801677D0 {
    u8 pad0[0x18];
    u8 flags;
    u8 state;
    u8 pad1a[0x24 - 0x1a];
    St_801677D0 *st;
};
typedef struct {
    u8 pad0[0x58];
    s32 mask;
} W_8017379C;
typedef struct {
    u8 pad0[0xbc];
    W_8017379C* w;
} Hm_8017379C;
typedef struct {
    u8 pad0[0x24];
    Hm_8017379C* hm;
} Mid_8017379C;
typedef struct { u8 pad0[8]; s32 a8; u8 padc[4]; s32 a10; u8 pad14[0x5c - 0x14]; u32 f5c; } Leaf;
typedef struct { u8 pad[8]; UiObj obj; u8 pad2[0xBC - 8 - sizeof(UiObj)]; Leaf* leaf; } Mid;
typedef struct { u8 pad[0x24]; Mid* mid; } Elem;
typedef struct { u8 pad[0x74]; f32 y; } Nd;
typedef struct { u8 pad[0x24]; Nd* n; } Elem2;
typedef struct {
    u8 pad0[8];
    s32 f8;
    u8 padc[4];
    s32 f10;
    u8 pad14[0x44];
    s32 f58;
    u32 f5c;
} La_801729D0;
typedef struct {
    u8 pad0[0xbc];
    La_801729D0* la;
} In_801729D0;
typedef struct {
    u8 pad0[0x24];
    In_801729D0* in;
} Pnl_801729D0;
/* fn_80167578: walk the object chain, return the i-th table entry's data. */
typedef struct Vec4f { f32 a, b, c, d; } Vec4f;
typedef struct Inner801732C8 {
    s32 kind;
    u32 pad04;
    UiObj obj;
    u8 pad_[0x74 - 8 - sizeof(UiObj)];
    f32 y74;
} Inner801732C8;
typedef struct Elem801732C8 {
    u8 pad0[0x24];
    Inner801732C8 *in;
} Elem801732C8;
/* The camp menu's controlling task: state 0/0xFE init, 1 wait for the open button, 3 wait for the
 * menu data and start the menu task, 4/5 open, 6 close, 7 tear down, 0xFF delete. */
/* The controller state lbl_80311A60 points to per port. */
typedef struct PadState {
    u8 pad0[8];
    u32 held; /* 0x08 */
} PadState;
typedef struct Self_8016F594 {
    u8 pad[0x2c];
    f32 x, y;
    u8 pad2[0x74 - 0x34];
    f32 z;
    u8 pad3[0xbc - 0x78];
    u8 *data;
} Self_8016F594;
#endif
