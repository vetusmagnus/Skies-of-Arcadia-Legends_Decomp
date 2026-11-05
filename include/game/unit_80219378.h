#ifndef GAME_UNIT_80219378_H
#define GAME_UNIT_80219378_H

#include "types.h"
#include "game/camera_803119E0.h"
#include "game/save_8030B7F4.h"
#include "game/drawstate.h"
#include "game/stat_8030B4D4.h"
#include "ninja.h"
#include <dolphin/os.h>
#include <dolphin/gx.h>
#include "game/text.h"
#include "game/menu.h"
#include "game/gamedata.h"
#include "game/sprite.h"
#include <stdio.h>
#include <string.h>
#include <dolphin/dvd.h>
#include "game/draw2d.h"

typedef struct Node_UNIT0000 {
    void (*w0)(void *);                   /* the update function */
    struct Node_UNIT0000 *next;
    struct Node_UNIT0000 *w8;             /* the parent */
    u32 wc;
    u32 w10;
    s32 w14;
    u8 b18;
    u8 pad19[2];
    u8 b1b;
    u8 pad1c[4];
    f32 f20;                              /* the draw-order key */
    void *kids[6];                        /* 0x24: work blocks, freed with the task */
    u8 pad3c[4];
} Node_UNIT0000;
typedef struct Blk2_UNIT0000 { s32 f0; s32 f4; s32 f8; u8 padc[0x18 - 0xc]; s32 f18; s32 f1c; } Blk2_UNIT0000;
extern void fn_801CBBAC(f32 f);
extern void fn_801CBB9C(f32 f);
extern void njRotateZXY(void *m, s32 x, s32 y, s32 z);
typedef NJS_POINT3 Vec;
typedef struct Node {
    s32 (*cb)(struct Node *, struct Node *);
    u8 pad4[0xc];
    u16 mask10;
    u16 id12;
    s16 flag14;
    u8 pad16[0x2c - 0x16];
    struct Node *prev;
    struct Node *next;
} Node;
void fn_801E17E0(void *p);
typedef unsigned long u32_8022823C;
extern void *memset(void *dst, int c, u32_8022823C n);
extern void fn_801E17E0(void *p);
extern void fn_8022642C(void);
extern s32 lbl_80311AD4[11];
typedef int s32_8022B014;
extern s32_8022B014 lbl_80347508;
typedef int s32_8022B064;
extern s32_8022B064 lbl_80347508;
void *fn_801E1C7C(u32 size);
typedef struct Z { u8 pad[8]; NJS_TEXLIST texlist; } Z;
typedef struct TexInner { u8 pad[0x20]; NJS_TEXLIST *list; } TexInner;
typedef struct TexRoot { u8 pad[4]; TexInner *inner; } TexRoot;
extern TexRoot *lbl_80347854;
s32 fn_802275A4(NJS_TEXLIST *texlist, s32 mode);
extern void fn_801CBBF8(void);
typedef struct Flags8 { u8 pad[8]; u32 f8; } Flags8;
typedef struct Ref { Flags8 *p; u8 pad[0x18 - 4]; } Ref;
extern Ref lbl_80311A60;
typedef struct Flags88 { u8 pad[0x88]; u32 f88; } Flags88;
extern Flags88 lbl_80310B3C;
extern void fn_8022AFD0(void);
extern TexRoot *fn_801DB244(void *p);
extern void fn_801CBC30(void);
extern void njUnitVector(Vec *v);
extern f32 njCos(Angle a);
typedef struct Blk {
    u8 pad0[0x30];
    struct Blk *next;
} Blk;
extern s32 fn_8022AE94(void);
extern void fn_80228914(void);
extern void fn_80226170(void);
extern void fn_802281BC(s32 a);
extern void fn_801E17E0(void *p);
extern void *fn_801E1C7C(u32 size);
extern void fn_801CBBD8(void);
extern void (*lbl_802F91AC[])(void);
extern void fn_801CBBD8(void);
extern void (*lbl_802F929C[])(Blk2_UNIT0000*);
extern void (*lbl_802F92BC[])(Blk2_UNIT0000*);
void fn_80219378(const char *a);
void fn_8022BC64(void);

#endif
