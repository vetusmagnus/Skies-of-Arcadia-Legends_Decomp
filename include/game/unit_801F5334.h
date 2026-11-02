#ifndef GAME_UNIT_801F5334_H
#define GAME_UNIT_801F5334_H

#include "types.h"
#include "ninja.h"
#include "game/task.h"

/* Struct layouts shared by unit_801F5334.c and the units split from it, unit_8020EEE8.c and
 * unit_802159E0.c (docs/progress.md). */
/* The head of a message a script command posts through fn_800CD0B8; the receiver sets kind (2 = done). */
typedef struct EvHead {
    u32 kind;       /* 0x00 */
    s32 x04;        /* 0x04 */
} EvHead;
/* The event message fn_80211058 posts: the head plus the fields it clears. */
typedef struct Ev {
    EvHead hd;      /* 0x00 */
    s16 h8;         /* 0x08 */
    u8 pad0a[2];
    s32 x0c;        /* 0x0c */
    s32 x10;        /* 0x10 */
} Ev;
typedef struct Work801F8 {
    Ev ev;
    u8 pad14[0x4];
    u16 n;
    u8 pad1a[0x2];
    s32 x1c;
    s32 x20;
    f32 x24;
    f32 x28;
    u32 x2c;
    u8 pad30[0x14];
} Work801F8;
typedef struct Work801FC {
    Ev ev;
    s32 x14;
    u16 n;
    u8 pad1a[0x2];
    f32 x1c;
    f32 x20;
    f32 x24;
    s32 x28;
    s32 x2c;
    s32 x30;
    f32 x34;
    u8 pad38[0xc];
} Work801FC;
typedef struct Work8020 {
    Ev ev;
    u8 pad14[0x4];
    u16 n;
    u8 pad1a[0x2];
    s32 x1c;
    f32 x20;
    f32 x24;
    f32 x28;
    u8 pad2c[0xc];
    s32 x38;
    s32 x3c;
    u8 pad40[0x4];
} Work8020;
/* lbl_80311970: the free camera. */
typedef struct {
    u8 pad00[8];
    f32* f8;            /* 0x08: eye point */
    u8 pad0c[4];
    f32 f[3];           /* 0x10 */
    s32 w[3];           /* 0x1c */
    u8 pad28[0x50 - 0x28];
    f32 x50;            /* 0x50: field of view */
} Cam8020C;
typedef struct Info { u8 pad_00[0x10]; s32 *x10; u8 pad_14[0x30]; f32 x44, x48, x4c, x50, x54, x58; } Info;
typedef struct Work_80202004 {
    EvHead hd;
    u8 pad08[0x10];
    s32 x18;
    s32 x1c;
    s32 x20;
} Work_80202004;
typedef struct Lerp {
    s32 total;      /* 0x00 */
    s32 step[3];    /* 0x04 */
    s32 dest[3];    /* 0x10 */
} Lerp;
typedef struct Eff {
    f32 f[8];       /* 0x00 */
    s32 x20;
} Eff;
typedef struct Fx {
    Ev ev;
    u8 pad14[0x4];
    u16 x18;
    u8 pad1a[0x2];
    f32 x1c;
    f32 x20;
    f32 x24;
    f32 x28;
    f32 x2c;
    f32 x30;
    s32 x34;
    u8 pad38[0xc];
} Fx;
typedef struct Fx_801F8D0C {
    Ev ev;
    u8 pad14[0x4];
    u16 x18;
    u8 pad1a[0x2];
    s32 x1c;
    s32 x20;
    f32 x24;
    f32 x28;
    s32 x2c;
    u8 pad30[0x14];
} Fx_801F8D0C;
typedef struct Fx_801F8F7C {
    Ev ev;
    u8 pad14[0x4];
    u16 x18;
    u16 x1a;
    u8 pad1c[0x28];
} Fx_801F8F7C;
typedef struct Fx_801F9120 {
    Ev ev;
    u8 pad14[0x4];
    u16 x18;
    u16 x1a;
    s32 x1c;
    f32 x20;
    f32 x24;
    f32 x28;
    f32 x2c;
    f32 x30;
    f32 x34;
    u8 pad38[0xc];
} Fx_801F9120;
typedef struct Fx_801FBBA8 {
    Ev ev;
    u8 pad14[0x4];
    u16 x18;
    u8 pad1a[0x2];
    s32 x1c;
    s32 x20;
    f32 x24;
    u8 pad28[0x1c];
} Fx_801FBBA8;
typedef struct ScrState {
    u8 pad0[0x1c];
    s32 mode;
    s32 count;
    u8 pad24[0x20];
} ScrState;
typedef struct Work_8020184C {
    Ev ev;
    u8 pad14[0x4];
    u16 n;
    u8 pad1a[0x2];
    u32 x1c;
    u8 pad20[0x24];
} Work_8020184C;
typedef struct Work_802019F8 {
    EvHead hd;
    u8 pad08[0x10];
    s32 x18;
    s32 x1c;
    s32 x20;
    u8 pad24[0x20];
} Work_802019F8;
typedef struct Work_80207CD0 {
    Ev ev;
    u8 pad14[0x4];
    u16 id;
    u16 v;
    f32 f0;
    f32 f1;
    f32 f2;
} Work_80207CD0;
typedef struct Rec {
    Ev ev;
    u8 pad14[0x4];
    u16 n;
    u8 pad1a[0x2];
    f32 f1c;
    f32 f20;
    f32 f24;
    f32 f28;
    f32 f2c;
    f32 f30;
    s32 i34;
    u8 pad38[0xc];
} Rec;
typedef struct Rec_80208424 {
    Ev ev;
    u8 pad14[0x4];
    u16 n;
    u8 pad1a[0x2];
    s32 i1c;
    f32 f20;
    f32 f24;
    f32 f28;
    f32 f2c;
    f32 f30;
    s32 i34;
    u8 pad38[0xc];
} Rec_80208424;
typedef struct Rec_80208A20 {
    Ev ev;
    u8 pad14[0x4];
    u16 n;
    u8 pad1a[0x2];
    s32 i1c;
    s32 i20;
    f32 f24;
    f32 f28;
    f32 f2c;
    f32 f30;
    s32 i34;
    u8 pad38[0xc];
} Rec_80208A20;
typedef struct Rec_80209974 {
    Ev ev;
    u8 pad14[0x4];
    u16 n;
    u16 n2;
    f32 f1c;
    f32 f20;
    f32 f24;
    s32 i28;
    u8 pad2c[0x18];
} Rec_80209974;
typedef struct Work_8020A938 {
    EvHead hd;
    void *x08;
} Work_8020A938;
/* The work of a type-5 message with a value: the head, the value and the text. */
typedef struct Work_8020A584 {
    EvHead hd;
    s32 x08;
    char* x0c;
} Work_8020A584;
/* The work of a type-8 message: the head, an id and a value. */
typedef struct Work_8020D2A8 {
    EvHead hd;
    u8 pad08[0x10];
    u16 n;
    u8 pad1a[2];
    s32 x1c;
    u8 pad20[0x24];
} Work_8020D2A8;
/* The 0x88-byte block fn_8020DBC4 hands over: two tables of lbl_8034A034 entries. */
typedef struct EvBufs {
    u8 pad00[0x1c];
    void* x1c;
    void* x20;
    u8 pad24[0x64];
} EvBufs;
typedef struct Work_8020DBC4 {
    Ev ev;
    u8 pad14[8];
    EvBufs* x1c;
    u8 pad20[0x24];
} Work_8020DBC4;

#endif
