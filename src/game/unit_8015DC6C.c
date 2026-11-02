#include "types.h"
#include "game/stat_8030B4D4.h"
#include "game/work_8030CEA0.h"
#include "game/save_8030B7F4.h"
#include "game/task.h"
#include "game/evobj.h"
#include "game/menu.h"
#include "ninja.h"
#include "ninja_lib.h"
#include "game/camera_803119E0.h"
#include "game/uiobj.h"
#include "game/gamedata.h"
#include "game/text.h"
#include "game/sprite.h"
#include <math.h>
#include <string.h>
#include <dolphin/types.h>
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
/* camp_work: the camp menu's panels and the state of each screen. */
typedef struct CampWork {
    s8 *ids;            /* 0x000 */
    void *p04;          /* 0x004 */
    u8 pad08[4];
    s8 count;           /* 0x00C */
    u8 pad0d[3];
    CampPnl *pnl[0xB9]; /* 0x010 */
    u32 state[22];      /* 0x2F4: one per screen, as lbl_80307638 */
    f32 f34c;           /* 0x34C */
    f32 f350;           /* 0x350 */
    f32 f354;           /* 0x354 */
    f32 f358;           /* 0x358 */
    u8 pad35c[4];
} CampWork;
extern CampWork camp_work;
extern CampCtrl lbl_80307638[22];
extern CampTask *lbl_8034710C;
extern s32 fn_80193F78(void);
extern s32 lbl_80347154;
extern void fn_80195A68(void* p, s32 a, s32 b, s32 c, s32 d, s32 e);
extern s32 CampMenuAnyPanelBusy(void);
extern s32 fn_801C09F8(s32 a, s32 b);
extern void CampMenuFinishAllPanels(void);
extern void fn_80199F38(void *ui);
extern SaveData lbl_8030B7F4;
extern void fn_80199BB8(UiObj *o, f32 x, f32 y);
extern void fn_80199BAC(UiObj *o, f32 x, f32 y);
extern s32 fn_8015F298(u32 *a, u32 *b);
typedef struct {
    u32 flags;
    u8 pad[0x19C - 4];
    f32 val;
} Sub_8015DC6C;
typedef struct {
    u8 pad[0x1D8];
    Sub_8015DC6C* sub;
} Obj_8015DC6C;
typedef struct {
    u8 pad[0x1C];
    f32 val;
} Src;
typedef struct {
    u8 pad[0x8];
    void* next;
} Sub_8015F180;
typedef struct {
    u8 pad[0x1D8];
    Sub_8015F180* sub;
} Obj_8015F180;
typedef struct {
    u8 pad[0x8];
    s32 val;
} Sub_8015F1F0;
typedef struct {
    u8 pad[0x1D8];
    Sub_8015F1F0* sub;
} Obj_8015F1F0;
void fn_8016D01C(void);
void fn_8016C4B0(void);
void fn_8016B620(void);
void fn_8016AD08(void);
typedef struct {
    s8 mode;
    u8 pad0[0x1F];
    f32 f20;
    u8 pad1[0xC];
    f32 f30;
} InnerA_UNIT0000;
typedef struct {
    u8 pad[0x24];
    InnerA_UNIT0000* inner;
} OwnerA_UNIT0000;
extern f32 lbl_8034ABDC;
typedef struct {
    u8 pad0[8];
    f32 f8;
    u8 padc[4];
    f32 f10;
    u32 word;
} Mat_8016CAB4;
typedef struct {
    u8 pad0[4];
    Mat_8016CAB4* mat;
    u8 pad8[0x14 - 8];
    f32 x;
    f32 y;
} Item_8016CAB4;
typedef struct Sub_8016C4C8 {
    s8 kind;
    s8 b1;
    s8 b2;
    s8 b3;
    f32 f4;
    f32 f8;
    u8 padc[0x14];
    s32 w20;
    s32 w24;
    s32 w28;
    s32 w2c;
    s32 w30;
    s32 w34;
    s32 w38;
    s32 w3c;
    s32 w40;
    s32 w44;
    s32 w48;
    s32 w4c;
} Sub_8016C4C8;
typedef struct Obj_8016C4C8 {
    u8 pad[0x24];
    Sub_8016C4C8* sub;
    Item_8016CAB4** items;
} Obj_8016C4C8;
extern Obj_8016C4C8* lbl_803470B0;
typedef struct {
    u8 a;
    u8 b;
    u8 pad[2];
    f32 f;
} Rec_8016F128;
void fn_8019A15C(void* p, s32 a, s32 b, s32 c);
extern void* lbl_80347450;
typedef struct Rec_UNIT0000 { u8 pad[0x24]; void *x24; } Rec_UNIT0000;
Rec_UNIT0000 *fn_8010A164(u16 idx);
typedef struct {
    u8 pad0[0xb4];
    f32 fb4;
    f32 fb8;
    f32 fbc;
    s32 fc0;
    s32 fc4;
    s32 fc8;
    u8 padcc[0x16c - 0xcc];
    s16 h16c;
} Inner_80161F04;
typedef struct Sub_8015F768 {
    u8 pad0[8];
    Inner_80161F04 *inner;
    u8 pad0c[0x178 - 0xc];
    s32 x178;
    u32 x17c;
} Sub_8015F768;
typedef struct Obj_8015F768 { u8 pad[0x1d8]; Sub_8015F768 *x1d8; } Obj_8015F768;
typedef struct Obj_8015FB98 { u8 pad[0xec]; u32 xec; u32 xf0; u32 xf4; } Obj_8015FB98;
void *fn_8008F8FC(void *a, s32 b);
typedef struct Sub_8016645C { u8 pad[0x1a]; s16 x1a; } Sub_8016645C;
typedef struct Obj_8016645C { u8 pad[0x1d8]; Sub_8016645C *x1d8; } Obj_8016645C;
typedef struct Arg { u8 pad[0x1c]; u32 x1c; u32 x20; } Arg;
/* lbl_80310B3C: the event flag bits, 32 per word. */
extern u32 lbl_80310B3C[];
void fn_8016DBAC(void *out, void *p);
typedef struct Out {
    f32 f0;
    u8 pad4;
    s8 idx;
    u8 pad6[2];
    SaveChar *rec;
    u8 b0c;
    u8 pad_d[3];
    s32 i10;
    s32 i14;
    s32 i18;
    s32 i1c;
} Out;
typedef struct { u8 pad[4]; u32 f4; } Mo;
typedef struct { u8 pad[0x1c8]; Mo *p1c8; } Obj_8015F218;
typedef struct { s32 f0; void *p4; } Sub0;
typedef struct { u8 pad[8]; u32 f8; Sub0 *pc; } Res;
Res *fn_800CCA6C(s32 kind, u32 v);
void fn_80210B44(void *p);
typedef struct { u8 pad[0x178]; s32 f178; } Inner_8015F654;
typedef struct { u8 pad[0x16c]; s16 h16c; u8 pad2[0x1d8 - 0x16e]; Inner_8015F654 *p1d8; } Obj_8015F654;
void fn_800A0028();
typedef struct { u8 pad[0x24]; void *p24; } Mid_UNIT0000;
typedef struct { u8 pad[4]; Mid_UNIT0000 *p4; u8 pad2[0x170]; s32 f178; } Inner_801601AC_UNIT0000;
typedef struct {
    u8 pad0[0xb4];
    f32 fb4, fb8, fbc;
    u32 fc0, fc4, fc8;
    u8 pad1[0x16c - 0xcc];
    s16 h16c;
    u8 pad2[0x1d8 - 0x16e];
    Inner_801601AC_UNIT0000 *p1d8;
} Obj_801601AC_UNIT0000;
extern void fn_80222838(void* p);
typedef struct C {
    u8 pad0[0x14];
    s32 x14;
    s32 x18;
} C;
typedef struct B {
    u8 pad0[0x2c];
    C* x2c;
} B;
typedef struct A {
    u8 pad0[0x54];
    s32 x54;
    s32 x58;
    s32 x5c;
    s32 x60;
    s32 x64;
    u8 pad1[0x84 - 0x68];
    B* x84;
} A;
typedef struct Obj_80167374 {
    u8 pad0[0x1d8];
    A* x1d8;
} Obj_80167374;
typedef struct Table {
    u8* entries;
    u32 count;
} Table;
typedef struct Holder_80167428 {
    u8 pad0[0x20];
    Table* table;
} Holder_80167428;
typedef struct Node_80167428 {
    u8 pad0[0x1c8];
    Holder_80167428* holder;
    u8 pad1[4];
    struct Node_80167428* next;
} Node_80167428;
extern void* lbl_8034708C;
typedef struct TaskWork_80168B7C {
    u8 pad0[4];
    u32 id;
    u8 pad1[0x34 - 8];
    Task* link;
} TaskWork_80168B7C;
extern void* memset(void*, int, unsigned long);
extern u8 lbl_80347080[8];
extern u8 lbl_80347078[8];
typedef struct TaskWork_80169294 {
    u8 pad0[0x34];
    Task* link;
} TaskWork_80169294;
extern u32 lbl_80347088;
typedef struct Sub_80168A04 {
    u32 w0;
    s32 id;
    u8 pad8[4];
    u8 fc;
    u8 fd;
    s8 f0e;
    s8 bF;
    u8 pad10[8];
    u32 f18;            /* 0x18: id << 16 | ... | low byte */
    f32 x1c;            /* 0x1c position */
    f32 x20;
    f32 x24;
    f32 x28;            /* 0x28 range */
    Rec_UNIT0000* x2c;
    struct Obj_80168A04* x30;   /* previous sound task */
    struct Obj_80168A04* x34;   /* next */
} Sub_80168A04;
typedef struct Obj_80168A04 {
    u8 pad[0x18];
    u8 b18;             /* task flags */
    u8 b19;             /* task state */
    u8 pad1a[0xA];
    Sub_80168A04* sub;
} Obj_80168A04;
typedef struct {
    Obj_80168A04 *obj;
    s32 state;
} Slot_80306F58;
extern Slot_80306F58 lbl_80306F58[3];
/* Linear move to (destX, destY) over 6 steps. */
typedef struct Mover {
    f32 x;      /* 0x00 */
    f32 y;      /* 0x04 */
    f32 destX;  /* 0x08 */
    f32 destY;  /* 0x0C */
    f32 stepX;  /* 0x10 */
    f32 stepY;  /* 0x14 */
    s32 steps;  /* 0x18 */
} Mover;
typedef struct Sys_80310A1C {
    u8 pad0[6];
    s8 f6;      /* 0x06 */
    u8 pad7[0x30 - 7];
    s8 x30;     /* 0x30 */
    u8 pad31[0x120 - 0x31];
} Sys_80310A1C;
extern Sys_80310A1C lbl_80310A1C;
extern void fn_8016B638(s8 k);
extern void fn_8016C4C8(s8 k);
extern void fn_8016D034(s8 k);
extern void fn_8016ADD4(s8 k);
struct Self_8016F594;
void fn_8016F594(struct Self_8016F594 *p);
struct PanelA;
extern void fn_8016EB4C(struct PanelA *a);
extern void fn_8016EA60(struct PanelA *a);
extern void fn_8016E96C(struct PanelA *a);
extern void fn_8016E878(struct PanelA *a);
struct Dst_80189958;
typedef struct {
    u8 pad0[0x2c];
    NjObj* owner;     /* 0x2C */
} Node8015F2E8;
/* lbl_80347070: the object whose model parts fn_8015F3B0 draws with their own matrices. */
typedef struct {
    u32 flags;        /* 0x00 */
    u8 pad4[0x84 - 0x4];
    Node8015F2E8* n84;
    Node8015F2E8* n88;
    Node8015F2E8* n8c;
    u8 pad1[0x94 - 0x90];
    s32 f94;          /* 0x94 */
    NJS_MATRIX m98;   /* 0x98 */
    NJS_TEXLIST* tex98; /* 0xD8 */
    void* mdl98;      /* 0xDC */
    s32 fe0;          /* 0xE0 */
    NJS_MATRIX me4;   /* 0xE4 */
    NJS_TEXLIST* texe4; /* 0x124 */
    void* mdle4;      /* 0x128 */
    s32 f12c;         /* 0x12C */
    NJS_MATRIX m130;  /* 0x130 */
    NJS_TEXLIST* tex130; /* 0x170 */
    void* mdl130;     /* 0x174 */
    u8 pad178[0x260 - 0x178];
    void (*draw)(EvObj*, s32); /* 0x260 */
} Obj8015F2E8;
extern Obj8015F2E8* lbl_80347070;
typedef struct {
    u8 pad0[0x16c];
    s16 flag16c;      /* 0x16C */
    u8 pad1[0x1d8 - 0x16e];
    void* link;       /* 0x1D8 */
} Obj8015F6C0;
typedef struct {
    u8 pad0[0x178];
    u32 f178;         /* 0x178 */
    u32 f17c;         /* 0x17C */
    u32 f180;         /* 0x180 */
    f32 v184[3];      /* 0x184 */
    u32 w190[3];      /* 0x190 */
} Link8015F6C0;
extern f32 lbl_8034AA80;
extern void fn_801E17E0(void* p);
typedef struct {
    u8 pad00[0x20];
    void* texlist; /* 0x20 */
} Inner_8016AD08;
typedef struct {
    u8 pad00[4];
    Inner_8016AD08* inner; /* 0x04 */
} Ent_8016AD08;
extern Ent_8016AD08* lbl_80347090;
extern Ent_8016AD08* lbl_80347094;
extern Ent_8016AD08* lbl_80347098;
extern Ent_8016AD08* lbl_8034709C;
extern int sprintf(char* buf, const char* fmt, ...);
extern void* fn_801DB244(void* p);
extern void fn_8016B4F0(void);
s32 fn_8016AEBC(void* self);
typedef struct {
    u8 pad00[0x18];
    u8 flags;  /* 0x18 */
    u8 state;  /* 0x19 */
    u8 pad1A[6];
    f32 timer; /* 0x20 */
} Self_8016B434;
extern void* fn_802268E8(void* a, void *);
typedef struct {
    void* p0;
    void* p4;
    void* p8;
    void* pc;
    void* p10;
} Tbl_8016C2C0;
typedef struct {
    u8 pad0[0x24];
    s8* kind;
    Tbl_8016C2C0* tbl;
} Obj_8016C2C0;
extern u8 lbl_802E725C[0x1C], lbl_802E72AC[0x1C], lbl_802E72FC[0x1C], lbl_802E734C[0x1C], lbl_802E739C[0x1C];
extern u8 lbl_802E7970[0x1C], lbl_802E79C0[0x1C], lbl_802E7A10[0x1C], lbl_802E7A60[0x1C], lbl_802E7AB0[0x1C];
extern u8 lbl_802E863C[0x1C], lbl_802E868C[0x1C], lbl_802E86DC[0x1C], lbl_802E872C[0x1C], lbl_802E877C[0x1C];
extern u8 lbl_802E8ACC[0x1C], lbl_802E8B1C[0x1C], lbl_802E8B6C[0x1C], lbl_802E8BBC[0x1C], lbl_802E8C0C[0x1C];
extern void* fn_801E1C7C(s32 size);
extern s32 fn_8016C888(void);
extern u8 lbl_802E7D5C[], lbl_802E8390[], lbl_802E83E0[], lbl_802E8464[], lbl_802E84E8[];
void fn_8016CED8(Task* task);
extern void* lbl_803475A8;
typedef struct {
    u8 mode;
    u8 flag1;
    u8 x2;
    u8 pad03;
    f32 f4;
    f32 f8;
    u8 pad0C[0x20 - 0xc];
    f32 f20;
    f32 f24;
    s8 stage;           /* 0x28 */
    u8 pad29[3];
    f32 f2c;
    f32 f30;
    f32 f34;
} Sub_8016D034;
typedef struct { u8 pad00[0x19]; u8 state; u8 pad1a[0xa]; Sub_8016D034* sub; } Owner_8016D034;
extern Owner_8016D034* lbl_803470B8;
extern f32 fn_80291888(f32 x);
typedef struct {
    f32 x0;   /* 0x00 */
    f32 y0;   /* 0x04 */
    f32 sx;   /* 0x08 */
    f32 sy;   /* 0x0C */
    f32 wx;   /* 0x10 */
    f32 wy;   /* 0x14 */
} Wrap;
extern void fn_80199F58(void* p);
extern void fn_8016EF10(void);
extern void CampPanelDrawFrame();
extern s32 lbl_803475D8;
typedef struct {
    s32 kind;   /* 0x00 */
    u32 pad04;
    UiObj obj;  /* 0x08 */
} Inner_8016EE2C;
typedef struct {
    u8 pad00[0x18];
    u8 flags;    /* 0x18 */
    u8 state;    /* 0x19 */
    u8 pad1A[0x24 - 0x1A];
    Inner_8016EE2C* inner; /* 0x24 */
} Self_8016EE2C;
typedef struct { f32 f0, f4; s32 i8, ic; u8 pad10[8]; f32 f18, f1c; } Pos_80188274;
typedef struct { u8 pad0[0x14]; s32 sel; } Sel_80188098;
typedef struct { Sel_80188098 *sel; s8 mask; } Inn_80188098;
typedef struct {
    s32 kind;   /* 0x00 */
    u32 pad04;
    UiObj obj;  /* 0x08 */
    u8 pad54[0x74 - 8 - sizeof(UiObj)];
    Pos_80188274 pos; /* 0x74 */
    u8 pad94[0xbc - 0x94];
    Inn_80188098 *inn; /* 0xbc */
} Inner_8016F138;
typedef struct {
    u8 pad00[0x18];
    u8 flags;    /* 0x18 */
    u8 state;    /* 0x19 */
    u8 pad1A[0x24 - 0x1A];
    Inner_8016F138* inner; /* 0x24 */
} Self_8016F138;
extern void fn_80195A68(void* p, s32 a, s32 b, s32 c, s32 d, s32 e);
#define CWB ((u8 *)&camp_work)
extern void fn_80199BB8(UiObj* obj, f32 x, f32 y);
extern void fn_80199BAC(UiObj* obj, f32 x, f32 y);
void fn_801E17E0(void* p);
extern void* lbl_803470F4;
extern void* lbl_803470F0;
extern void* lbl_803470E8;
void fn_80199F38(void* r);
typedef struct {
    u8 pad[0xe8];
    Mo *fe8;
    u8 padec[4];
    Mo *ff0;
    u8 padf4[0x18c - 0xf4];
    f32 f18c;
    f32 f190;
    u8 pad194[4];
    s32 f198;
    s32 f19c;
    f32 f1a0;
    f32 f1a4;
    f32 f1a8;
} Obj_8015FBE4;
typedef struct Mot { u32 w0, frames; } Mot;
typedef struct Obj_8015FF98 {
    u8 pad[0xe8];
    Mot *cur;
    u8 padec[4];
    Mot *prev;
    u8 pad2[0x18c - 0xf4];
    f32 f18c, f190;
    u8 pad3[4];
    s32 f198, f19c;
    f32 f1a0, f1a4, f1a8;
} Obj_8015FF98;
typedef struct Inp { u8 pad[0x1c]; f32 x, y, z, rx, ry, rz; } Inp;
void fn_8008FFA4(void *, void *);
typedef struct Rec_80167244 { s16 type; s16 pad; u32 w4, w8, wc; } Rec_80167244;
typedef struct Inner_80167244 { u32 f0; void *f4; } Inner_80167244;
typedef struct Node_80167244 {
    u32 f0;
    Inner_80167244 *inner;
    u8 pad8[0x14 - 8];
    s32 x14;
    s32 x18;
    s32 x1c;
    u8 pad20[0x2c - 0x20];
    struct Node_80167244 *next;
    struct Node_80167244 *child;
} Node_80167244;
Rec_80167244 *fn_801CB5F4(void *p, s32 lo, s32 hi);
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
extern void *lbl_8034759C;
void *fn_802267AC(void *a, void *fn);
void *fn_801E1A74(s32 n, s32 size);
void fn_801684E8(void *);
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
typedef struct Obj_80169360 Obj_80169360;
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
void fn_80168908(void);
void fn_80169360(Obj_80169360* o);
typedef struct Clk { u8 pad[0x3c]; f32 t; } Clk;
typedef struct Curve { u8 pad[0x40]; f32 f40, f44, f48, f4c; } Curve;
typedef struct { s8 mode; } InnerA_8016B4F0;
typedef struct {
    u8 pad[0x24];
    InnerA_8016B4F0* inner;
    void **tbl;
} OwnerA_8016B4F0;
extern u8 lbl_802E7160[0x2000];
typedef struct PanelA {
    f32 x, y;
    s32 z0, z1;
    f32 a, b, c, d;
    void **s0; f32 *p0; s32 n0;
    void **s1; f32 *p1; s32 n1;
    void **s2; f32 *p2; s32 n2;
    void *s3;
} PanelA;
extern void *lbl_803470F0, *lbl_803470E8, *lbl_803470F4;
void fn_80199FFC(void *p, s32 a, void *b, s32 c, s32 d, s32 e);
typedef struct Self_8016F594 {
    u8 pad[0x2c];
    f32 x, y;
    u8 pad2[0x74 - 0x34];
    f32 z;
    u8 pad3[0xbc - 0x78];
    u8 *data;
} Self_8016F594;
extern char *lbl_802E8FD0[20];
extern void *lbl_803470F0;
typedef struct { s32 hide; s32 pad4; UiObj obj; } Win;
typedef struct { u8 pad[0x24]; Win* in; } Pnl;
extern void fn_801D4F0C(void* spr, s32 a, s32 b, s32 c, f32 f1, f32 f2, f32 f3, f32 f4);
extern void fn_800FF348(void* spr, s32 id, f32 a, f32 b, f32 c);
extern s32 lbl_80347154;
extern s32 CampMenuAnyPanelBusy(void);
extern s32 fn_801C09F8(s32 a, s32 b);
extern void CampMenuFinishAllPanels(void);
#define PNL(off) (*(Pnl**)(CWB + (off)))
extern void fn_80199BB8(UiObj* o, f32 x, f32 y);
extern void fn_80199BAC(UiObj* o, f32 x, f32 y);
extern void MemCopy(void* dst, const void* src, s32 size);
extern void fn_8019A15C(void* p, s32 a, s32 b, s32 c);
extern void fn_80199F38(void* r);
extern void fn_80199F58(void* r);
typedef struct {
    u8 pad0[0x1c];
    f32 x1c;
} Obj;
typedef struct {
    u32 flags;
    u8 pad4[4];
    Obj *x8;
    u8 padc[2];
    s16 hE;
    s32 x10;
    s16 h14;
    s16 h16;
} Hold;
typedef struct {
    u8 pad0[0x1c];
    f32 x1c;
    u8 pad20[0x1d8 - 0x20];
    Hold *x1d8;
} Ent;
typedef struct { u32 a; s32 b, c; } V3;
typedef void (*Callback)(void);
typedef struct CbDef {
    Callback fn;
    u32 unk4;
} CbDef;
/* The 0x320-byte holder at the object's +0x1D8: callback slots from lbl_802B4118 and the state of the
 * object's scripted movement. */
typedef struct Hold_8015EB8C {
    u32 flags;           /* 0x00 */
    Task *task;          /* 0x04 */
    EvObj *x8;           /* 0x08 */
    s16 hC;              /* 0x0C */
    s16 hE;              /* 0x0E */
    s32 x10;             /* 0x10 */
    s16 h14;             /* 0x14 */
    s16 h16;             /* 0x16 */
    s16 h18;             /* 0x18 */
    s16 h1a;             /* 0x1A path frame */
    u16 h1c;             /* 0x1C path key */
    s16 h1e;             /* 0x1E */
    u8 pad20[0x48 - 0x20];
    s32 x48, x4c, x50;   /* 0x48 */
    s32 x54, x58, x5c;
    u8 pad60[0x6c - 0x60];
    s32 x6c;             /* 0x6C */
    s32 x70;             /* 0x70 */
    u32 x74;             /* 0x74 */
    V3 x78;              /* 0x78 */
    Node_80167244 *x84;  /* 0x84 */
    Node_80167244 *x88;  /* 0x88 */
    Node_80167244 *x8c;  /* 0x8C */
    s32 x90;             /* 0x90 */
    s32 x94;             /* 0x94 */
    u8 pad98[0xd8 - 0x98];
    s32 xd8;             /* 0xD8 */
    u8 paddc[0xe0 - 0xdc];
    s32 xe0;             /* 0xE0 */
    u8 pade4[0x124 - 0xe4];
    s32 x124;            /* 0x124 */
    u8 pad128[0x12c - 0x128];
    s32 x12c;            /* 0x12C */
    u8 pad130[0x170 - 0x130];
    s32 x170;            /* 0x170 */
    u8 pad174[0x178 - 0x174];
    s32 x178;            /* 0x178 */
    s32 x17c;            /* 0x17C */
    s32 x180;            /* 0x180 */
    u8 pad184[0x19c - 0x184];
    f32 x19c;            /* 0x19C */
    u8 pad1a0[0x1a4 - 0x1a0];
    u8 x1a4[0xbc];       /* 0x1A4, cleared by fn_801E0FD4 */
    Callback cb[47];     /* 0x260 */
    void (*cb13)(Task *, void *); /* 0x31C */
} Hold_8015EB8C;
typedef struct {
    u8 pad0[0x20];
    void *x20;
    char name[1];        /* 0x24 */
} Ref;
typedef struct {
    u8 pad0[0xe4];
    void *model;         /* 0xE4 */
    u8 pade8[0x17a - 0xe8];
    u16 h17a;
    u8 pad17c[0x1b8 - 0x17c];
    EvHit *hit;          /* 0x1B8 */
    u8 pad1bc[0x1c8 - 0x1bc];
    Ref *x1c8;
    u8 pad1cc[0x1d4 - 0x1cc];
    s32 x1d4;
    Hold_8015EB8C *x1d8;
} Ent_8015EBF4;
typedef struct { u8 pad[4]; u32 x4; } Mo_8015FCF8;
typedef struct {
    u8 pad0[0xe8];
    Mo_8015FCF8 *xe8;
    u8 padec[4];
    Mo_8015FCF8 *xf0;
    u8 padf4[0x18c - 0xf4];
    f32 x18c, x190;
    s32 x194;
    s32 x198, x19c;
    f32 x1a0, x1a4, x1a8;
} Obj_8015FCF8;
typedef struct { f32 *a; f32 *b; } Pair;
typedef struct {
    u32 count;
    u8 pad4[4];
    s32 *x8;
    f32 **xc;
    Pair *x10;
} Spl;
extern f32 fn_80212A78(void *a, f32 x, f32 t);
extern void fn_80213178(f32 t, f32 dur, f32 *p0, f32 *p1, f32 *p2, f32 *p3, f32 *out);
typedef struct {
    u8 pad0[0xe8];
    void *xe8;
    void *xec;
    void *xf0;
    void *xf4;
    u8 padf8[0x172 - 0xf8];
    u16 h172;
    u8 pad174[0x18c - 0x174];
    f32 x18c, x190;
    s32 x194;
    s32 x198, x19c;
    f32 x1a0;
} Obj_801650C4;
typedef struct {
    u8 pad0[8];
    Obj_801650C4 *x8;
    u8 padc[0x90 - 0xc];
    void *x90;
} Hold_801650C4;
typedef struct {
    u8 pad0[0x1d8];
    Hold_801650C4 *x1d8;
} Ent_801650C4;
typedef struct {
    u8 pad0[0x1c];
    u32 x1c;
    s32 x20;
    f32 x24;
} Arg_801650C4;
extern void fn_801E1784(void *p);
typedef NJS_POINT3 Vec;
typedef struct { s32 a, b, c; } V3i;
/* One path key (0x30 bytes). */
typedef struct {
    Vec p0;
    f32 rot[3];          /* 0x0C, degrees, 3.4028235e38f = keep */
    f32 x18;
    u8 pad1c[0x20 - 0x1c];
    void *x20;           /* 0x20 */
    u8 pad24[0x28 - 0x24];
    s32 x28;
    u8 pad2c[0x30 - 0x2c];
} Key;
typedef struct {
    u8 pad0[0x38];
    Vec p38;
    u8 pad44[0x5c - 0x44];
    Vec p5c;
    u8 pad68[0x104 - 0x68];
    Vec p104;
    u8 pad110[0x164 - 0x110];
    f32 x164;
    u8 pad168[0x1b8 - 0x168];
    void *x1b8;
} Obj_8016679C;
typedef struct {
    u8 pad0[8];
    Obj_8016679C *x8;
    u8 padc[0x1a - 0xc];
    s16 h1a;
} Hold_8016679C;
typedef struct {
    u8 pad0[0x1d8];
    Hold_8016679C *x1d8;
} Ent_8016679C;
typedef struct {
    u8 pad0[0x1c];
    u32 x1c;             /* key count */
    Key *x20;
    Spl *x24;
} Arg_8016679C;
extern f32 lbl_802E70C8[4];
extern s32 fn_802256A0(Vec *p, void *q, s32 a, u16 b);
extern void fn_802135B4(Vec *v, V3i *out);
extern void fn_802136A8(f32 *tab, Vec *out, s32 a, s32 b, s32 c);
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
void* fn_802267AC(void* a, void* b);
void* fn_801E1A74(s32 n, s32 size);
void fn_801680B4(Obj_80168A04 *t);
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
void fn_80168E54(Obj_80168A04 *t);
typedef struct Spr_8016E52C {
    u8 pad[0x14];
    f32 x;
    f32 y;
} Spr_8016E52C;
typedef struct Info_8016E52C {
    u8 pad[0x10];
    s32 idx;
} Info_8016E52C;
typedef struct Obj_8016E52C {
    u8 pad0[0x2c];
    f32 x;
    f32 y;
    u8 pad34[8];
    f32 f3c;
    u8 pad40[0x34];
    f32 z;
    u8 pad78[0x44];
    Info_8016E52C* info;
} Obj_8016E52C;
extern Spr_8016E52C* lbl_802E8F74[];
extern char lbl_802E8F60[][9];
void fn_801D51C4(Spr_8016E52C* s, s32 a, s32 b, f32 f1, f32 f2, f32 f3, f32 f4);
char* fn_80194C50(s8 i);
void fn_80194C18(s8 i);
char* fn_80194C00(void);
s32 fn_80194B18(s32 i);
extern void fn_80170704(s8 a, s32 b);
extern void fn_801705B8(void);
void fn_8016C204();
void fn_8016C61C(void);
extern void fn_80195A68(void* c, s32 a, s32 b, s32 d, s32 e, s32 f);
typedef struct {
    f32 x0, x4, x8;
    u8 padc[0x18 - 0xc];
    f32 x18;
    s32 x1c;
    s32 x20;
    f32 x24;
    u8 pad28[0x30 - 0x28];
} Ent_8016022C;
typedef struct {
    u8 pad0[0x20];
    Ent_8016022C *ents;
} Arg_8016022C;
typedef struct {
    u8 pad0[0x38];
    f32 x38;
    f32 x3c;
    u8 pad40[4];
    s32 x44;
    u8 pad48[4];
    s32 x4c;
    u8 pad50[0x68 - 0x50];
    s32 x68;
    u8 pad6c[4];
    s32 x70;
    u8 pad74[0xec - 0x74];
    u32 xec;
    u8 padf0[4];
    u32 xf4;
    u8 padf8[0x110 - 0xf8];
    s32 x110;
    u8 pad114[4];
    s32 x118;
} Inner_8016022C;
typedef struct {
    u8 pad0[8];
    Inner_8016022C *inner;
    u8 pad0c[0x1a - 0xc];
    s16 h1a;
    u8 pad1c[0x20 - 0x1c];
    u8 x20[1];
} St_8016022C;
typedef struct {
    u8 pad0[0x1d8];
    St_8016022C *st;
} Obj_8016022C;
typedef struct {
    f32 x, y, z;
} Vec_8016022C;
typedef struct {
    u32 f0;
    s32 f4;
    s8 f8;
    u8 pad[0xb];
} Gx_8016022C;
extern Gx_8016022C lbl_80311AC0;
typedef struct {
    u8 pad0[0x16c];
    s16 h16c;
} Inner_80161FDC;
typedef struct {
    u8 pad0[8];
    Inner_80161FDC *inner;
    u8 pad0c[0x178 - 0xc];
    s32 x178;
    u32 x17c;
    s32 x180;
    f32 x184;
    f32 x188;
    f32 x18c;
    s32 x190;
    s32 x194;
    s32 x198;
} St_80161FDC;
typedef struct {
    u8 pad0[0x1d8];
    St_80161FDC *st;
} Obj_80161FDC;
typedef struct {
    u8 pad0[0x18];
    u16 h18;
    u8 pad1a[2];
    s32 x1c;
    f32 x20;
    f32 x24;
    f32 x28;
    f32 x2c;
    f32 x30;
    f32 x34;
} Arg_80161FDC;
typedef struct {
    u8 pad0[0x38];
    f32 x38;
    f32 x3c;
    f32 x40;
    s32 x44;
    s32 x48;
    s32 x4c;
    u8 pad50[0xe8 - 0x50];
    u32 xe8;
    u32 xec;
    u32 xf0;
    u32 xf4;
    u8 padf8[0x104 - 0xf8];
    f32 x104;
    f32 x108;
    f32 x10c;
    s32 x110;
    s32 x114;
    s32 x118;
    u8 pad11c[0x168 - 0x11c];
    s16 h168;
    u8 pad16a[0x18c - 0x16a];
    f32 x18c;
    f32 x190;
    u8 pad194[4];
    s32 x198;
    s32 x19c;
    f32 x1a0;
    u8 pad1a4[0x20c - 0x1a4];
    s32 x20c;
    s32 x210;
    s32 x214;
} Inner_80164748;
typedef struct {
    u8 pad0[8];
    Inner_80164748 *inner;
    u8 pad0c[0x20 - 0xc];
    f32 x20;
    u8 pad24[0x178 - 0x24];
    s32 x178;
} St_80164748;
typedef struct {
    u8 pad0[0x1d8];
    St_80164748 *st;
} Obj_80164748;
typedef struct {
    u8 pad0[0x1c];
    f32 x1c;
    f32 x20;
    f32 x24;
    s32 x28;
    u32 x2c;
    s32 x30;
    f32 x34;
} Arg_80164748;
/* The camp menu cursor's work (lbl_803470A0): a Mover at +4, then a spring on f30. */
typedef struct {
    s8 kind;
    s8 b1;
    s8 mode;
    u8 pad3;
    Mover mv;           /* 0x04 */
    f32 f20;
    f32 f24;
    f32 f28;
    f32 f2c;
    f32 f30;            /* 0x30 position */
    f32 f34;            /* 0x34 lower limit */
    f32 f38;            /* 0x38 acceleration */
    f32 f3c;            /* 0x3C current acceleration */
    f32 f40;            /* 0x40 speed limit */
    f32 f44;            /* 0x44 speed */
} St_8016CAB4;
typedef struct {
    u8 pad0[0x24];
    St_8016CAB4* st;
    Item_8016CAB4** items;
} Obj_8016CAB4;
extern Obj_8016CAB4* lbl_803470A0;
typedef struct {
    Item_8016CAB4* item;
    f32 a;
    f32 b;
    s32 c;
    s32 d;
    f32 e;
    f32 f;
} Arg_8016CAB4;
extern void fn_8016AB44(Arg_8016CAB4* a);
typedef struct {
    u8 pad0[0x18];
    s32 page;
} Sub_8016E220;
typedef struct {
    s32 mode;
    u8 pad4[4];
    UiObj ui;
    u8 pad54[0x74 - 0x54];
    f32 f74;
    u8 pad78[0xbc - 0x78];
    Sub_8016E220* sub;
} Work_8016E220;
typedef struct {
    u8 pad0[0x18];
    u8 flags;
    u8 stage;
    u8 pad1a[0x24 - 0x1a];
    Work_8016E220* work;
} Self_8016E220;
typedef struct Obj_8016EC3C {
    f32 x;           /* 0x00 */
    f32 y;           /* 0x04 */
    s32 i8;          /* 0x08 */
    s32 ic;          /* 0x0c */
    f32 f10;         /* 0x10 */
    f32 f14;         /* 0x14 */
    f32 f18;         /* 0x18 */
    f32 f1c;         /* 0x1c */
    void** h20;      /* 0x20 */
    f32* p24;        /* 0x24 */
    u8 pad28[4];
    void** h2c;      /* 0x2c */
    f32* p30;        /* 0x30 */
    u8 pad34[4];
    void** h38;      /* 0x38 */
    f32* p3c;        /* 0x3c */
    u8 pad40[4];
    void* h44;       /* 0x44 */
} Obj_8016EC3C;
extern void fn_8019A374(s32 spr, f32 x, f32 y, f32 z, u32 col, s32 n);
typedef struct { s32 hide; } Win_80177D7C;
typedef struct { u8 pad[0x24]; Win_80177D7C* in; } Pnl_80177D7C;
#define PNL_80177D7C(off) (*(Pnl_80177D7C**)(CWB + (off)))
typedef struct {
    u8 pad0[8];
    UiObj ui;
} Win_80172C60;
typedef struct {
    u8 pad0[0x24];
    Win_80172C60* win;
} Pnl_80172C60;
#define PNL_80172C60(off) (*(Pnl_80172C60**)(CWB + (off)))
#define PNL_80173104(off) (*(Pnl_80172C60**)(CWB + (off)))
#define PNL_80174F40(off) (*(Pnl_80172C60**)(CWB + (off)))
#define PNL_801764E4(off) (*(Pnl_80172C60**)(CWB + (off)))
#define PNL_80176868(off) (*(Pnl_80172C60**)(CWB + (off)))
#define PNL_80178D2C(off) (*(Pnl_80172C60**)(CWB + (off)))
typedef struct Obj_8016E3E0 {
    u8 pad0[0x2c];
    f32 x;
    f32 y;
    u8 pad34[8];
    f32 f3c;
    u8 pad40[0x34];
    f32 z;
} Obj_8016E3E0;
extern f32 TextGetZ(void);
char* fn_80193FAC(void);
typedef struct Fx_801677D0 Fx_801677D0;
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
extern void fn_801679A4(Fx_801677D0 *t);
extern s32 fn_80167C34(St_801677D0 *s);
extern void fn_802172C8(u32 a, s32 b);
typedef struct {
    u8 pad0[0x38];
    f32 x, y, z;
} Cam_80167EF0;
extern s32 fn_800C8D90(void);
extern void fn_8009FDA0(void *a, s32 b, Vec_8016022C *out, s32 c, Vec_8016022C *d, s32 e, s32 f);
extern f32 fn_80291A5C(f32 x);
typedef struct {
    u8 pad0[0x14];
    f32 x;
    f32 y;
} Eff_8016FB2C;
#define PNL_8016FB2C(off) (*(u8**)(cw + (off)))
#define PNL2(off) (*(u8**)(CWB + (off)))
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
#define MID() (*(Mid_8017379C**)(CWB + 0x218))
typedef struct Ent_8015E174 Ent_8015E174;
typedef struct {
    u8 pad0[0x1c];
    f32 x1c;
    u8 pad20[0xec - 0x20];
    s32 xec;
    s32 xf0;
    u8 padf4[0x168 - 0xf4];
    s16 h168;
    u8 pad16a[0x172 - 0x16a];
    s16 h172;
    u8 pad174[0x1b8 - 0x174];
    void *x1b8;
    s32 x1bc;
} Obj_8015E174;
typedef struct {
    u32 flags;
    u8 pad4[4];
    Obj_8015E174 *x8;
    s16 hc;
    u8 pade[0x18 - 0xe];
    s16 h18;
    u8 pad1a[0x24 - 0x1a];
    Vec p24;
    Vec p30;
    s32 x3c, x40, x44;
    u8 pad48[0x54 - 0x48];
    u8 x54[0xc];
    u8 x60[0xc];
} Hold_8015E174;
struct Ent_8015E174 {
    u8 pad0[0x38];
    Vec p38;
    s32 x44, x48, x4c;
    u8 pad50[0x104 - 0x50];
    Vec p104;
    u8 pad110[0x1d4 - 0x110];
    s32 x1d4;
    Hold_8015E174 *x1d8;
};
s32 fn_80216F48(u32 a);
void fn_80217830(u32 a);
extern void TextPushColor(void);
extern void TextSetColor(u32 c);
extern void TextSetZ(f32 z);
extern void TextPopColor(s32 n);
typedef struct Ent_8015EB8C {
    u8 pad0[0x1d8];
    Hold_8015EB8C *hold;
} Ent_8015EB8C;
extern const CbDef lbl_802B4118[47];
typedef struct OwnerBInner {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
} OwnerBInner;
typedef struct OwnerB_8016C808 {
    u8 pad[0x24];
    OwnerBInner *inner;
} OwnerB_8016C808;
typedef struct Tbl {
    u8 pad0[0x14];
    s32 base[1];
} Tbl;
typedef struct Info {
    u8 pad0[0x2c];
    Tbl *tbl;
} Info;
typedef struct Joint {
    u8 pad0[0x68];
    s32 speed[(0x110 - 0x68) / 4];
    s32 delta[1];
} Joint;
typedef struct Work {
    u8 pad0[0x8];
    Joint *joint;
    u8 pad1[0x54 - 0xc];
    s32 x54[(0x84 - 0x54) / 4];
    Info *info;
} Work;
typedef struct Obj_80166B2C {
    u8 pad0[0x1d8];
    Work *work;
} Obj_80166B2C;
extern NJS_VECTOR lbl_802B4334;
extern NJS_VECTOR lbl_802B4340;
extern void njSetMatrix(NJS_MATRIX dst, NJS_MATRIX src);
extern void njUnitTransPortion(NJS_MATRIX m);
extern void njCalcVector(NJS_MATRIX m, NJS_VECTOR *v, NJS_VECTOR *out);
extern double atan2(double y, double x);
typedef struct Work_8016B638 {
    s8 b0;
    u8 b1;
    u8 pad2[2];
    f32 f4, f8;
    u8 padc[0x20 - 0xc];
    f32 f20, f24, f28, f2c, f30, f34, f38, f3c, f40, f44;
} Work_8016B638;
typedef struct Node_8016B638 {
    u8 pad[0x24];
    Work_8016B638 *work;
} Node_8016B638;
typedef struct { u8 pad0[8]; s32 a8; u8 padc[4]; s32 a10; u8 pad14[0x5c - 0x14]; u32 f5c; } Leaf;
typedef struct { u8 pad[8]; UiObj obj; u8 pad2[0xBC - 8 - sizeof(UiObj)]; Leaf* leaf; } Mid;
typedef struct { u8 pad[0x24]; Mid* mid; } Elem;
extern s32 fn_80193F78(void);
#define OBJ(i) (&((Elem*)camp_work.pnl[i])->mid->obj)
typedef struct { u8 pad[0x74]; f32 y; } Nd;
typedef struct { u8 pad[0x24]; Nd* n; } Elem2;
#define ND(i) (((Elem2*)camp_work.pnl[i])->n)
#define CW(off, T) (*(T*)((u8*)&camp_work + (off)))
extern void *fn_8015F1A0(u32 id);
extern f32 njSin(s32 a);
typedef struct {
    u8 pad0[0x18];
    f32* pos;
    u8 pad1c[4];
    s32* rot;
} JointObj;
typedef struct Joint_80166EC4 {
    u8 pad0[0x38];
    f32 x38[3];
    s32 pos[3];
    u8 pad50[0x68 - 0x50];
    s32 vel[3];
    u8 pad74[0x110 - 0x74];
    s32 target[3];
    u8 pad11c[0x190 - 0x11c];
    f32 x190;
    u8 pad194[0x1bc - 0x194];
    JointObj* obj;
} Joint_80166EC4;
typedef struct Joint_80167034 {
    u8 pad0[0x38];
    f32 x38;
    f32 x3c;
    f32 x40;
    s32 pos[3];
    u8 pad50[0x5c - 0x50];
    f32 x5c;
    f32 x60;
    f32 x64;
    s32 vel[3];
    u8 pad74[0x110 - 0x74];
    s32 target[3];
    u8 pad11c[0x190 - 0x11c];
    f32 x190;
} Joint_80167034;
typedef struct {
    char* name;
    s32 level;
    char* name2;
    s32 level2;
    u8 pad10[4];
    s8 b14;
} Info_8016E6E8;
typedef struct {
    s32 mode;
    u8 pad4[4];
    UiObj ui;
    u8 pad54[0x74 - 0x54];
    f32 f74;
    u8 pad78[0xbc - 0x78];
    Info_8016E6E8* info;
} Work_8016E6E8;
extern s32 fn_8018126C(void);
extern s32 fn_801812C0(void);
typedef struct {
    u8 pad0[0x18];
    u16 id;
} Arg_80161F04;
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
#define LA(n) (((Pnl_801729D0*)camp_work.pnl[n])->in->la)
typedef struct Ent_80166138 { u8 pad[0x2c]; u32 f2c; } Ent_80166138;
typedef struct Tab_80166138 {
    u8 pad[0x1c];
    u32 count;
    Ent_80166138 *ents;
} Tab_80166138;
extern s32 fn_801664A4(EvObj *o);
extern void fn_801E735C(u32 index, f32 speed, EvObj *obj);
typedef struct NameEnt { char *name; u32 b; u32 c; } NameEnt;
typedef struct NameTab { NameEnt *ents; u32 count; } NameTab;
typedef struct Node {
    u8 pad[0x100];
    NameTab *tab;
    u8 pad104[0x1d0 - 0x104];
    struct Node *parent;
} Node;
typedef struct Hit {
    NJS_POINT3 pos; /* 0x00 */
    f32 y0;         /* 0x0c */
    f32 y1;         /* 0x10 */
    s16 n0;         /* 0x14 */
    s16 n1;         /* 0x16 */
    u8 pad18[6];
    u16 id0;        /* 0x1e */
    u8 pad20[2];
    u16 id1;        /* 0x22 */
} Hit;
extern s32 fn_8022436C(u32 id, Hit* arr, s32 count);
#define OBJ_801763B8(i) (&((Elem*)camp_work.pnl[i])->mid->obj)
/* fn_80167578: walk the object chain, return the i-th table entry's data. */

typedef struct Ent_80167578 {
    u32 x0;
    u32 x4;
    u8 x8[1];
} Ent_80167578;
typedef struct Tbl_80167578 {
    s32 n;
    Ent_80167578 *e[1];
} Tbl_80167578;
typedef struct Mdl_80167578 {
    u8 pad[0x14];
    Tbl_80167578 *tbl;
} Mdl_80167578;
typedef struct Obj_80167578 {
    u8 pad[0x1c8];
    Mdl_80167578 *m;
    u8 pad1cc[4];
    struct Obj_80167578 *next;
} Obj_80167578;
typedef struct Table_80167604 { s32 n; s32* e[1]; } Table_80167604;
typedef struct Hold_80167604 { u8 pad[0x14]; Table_80167604* t; } Hold_80167604;
typedef struct Node_80167604 Node_80167604;
struct Node_80167604 { u8 pad0[0x1c8]; Hold_80167604* h; u8 pad1[4]; Node_80167604* parent; };
typedef struct Vec2f { f32 x, y; } Vec2f;
typedef struct Vec4f { f32 a, b, c, d; } Vec4f;
typedef struct IconObj {
    f32 x;       /* 0x00 */
    f32 y;       /* 0x04 */
    s32 f08;
    s32 f0c;
    f32 f10;
    f32 scale;   /* 0x14 */
    f32 f18;
    f32 f1c;
    void** spr20;
    Vec4f* pos24;
    void** spr28;
    void** spr2c;
    Vec2f* pos30;
    void* f34;
    void** spr38;
    Vec2f* pos3c;
    void* f40;
    void* spr44;
} IconObj;
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
#define IN(i) (((Elem801732C8 *)camp_work.pnl[i])->in)
#define CW_801732C8(off, T) (*(T *)((u8 *)&camp_work + (off)))
typedef struct Elem_80176D70 {
    u8 pad0[0x24];
    Inner_8016EE2C *in;
} Elem_80176D70;
#define CW_80176D70(off, T) (*(T *)((u8 *)w + (off)))
#define CG(off, T) (*(T *)((u8 *)&camp_work + (off)))
#define IN_80176D70(i) (((Elem_80176D70 *)camp_work.pnl[i])->in)
extern SaveData lbl_8030B7F4;

s32 fn_8015DC6C(Obj_8015DC6C* self, Src* src)
{
    Sub_8015DC6C* sub = self->sub;
    sub->flags |= 0x80;
    sub->val = src->val;
    return 0;
}

s32 fn_8015E30C(void) {
    return 0;
}

Node_80167244 *fn_80167244(Node_80167244 *n, u32 id);
extern void *fn_801E1A2C(s32 a, s32 b);
extern char lbl_802B42E8[];
void fn_801DBE1C(const char *fmt, ...);
extern s32 fn_800DE554(u32 x);
extern s32 fn_800DE5EC(u32 x);
extern s32 fn_800DE598(u32 id);
extern void *fn_801C8930(void *model);
extern void fn_801E0FD4(void *p, s32 n);
s32 fn_8015ED90(Task *t)
{
    Ent_8015EBF4 *o = t->work;
    Hold_8015EB8C *h;
    int i;
    u32 id;
    s16 v;

    if (o->x1d8 != NULL) {
        fn_801DBE1C(lbl_802B42E8, o->h17a, o->x1c8->name);
    }
    if (o->x1d8 == NULL) {
        o->x1d8 = fn_801E1A2C(1, 0x320);
        if (o->x1d8 == NULL) {
            return 0;
        }
    }
    h = o->x1d8;
    h->task = t;
    for (i = 0; i < 47; i++) {
        h->cb[i] = lbl_802B4118[i].fn;
    }
    h->cb13 = NULL;
    h->x8 = NULL;
    h->x90 = 0;
    h->h18 = -1;
    h->flags &= ~0x100;
    h->flags &= ~0x8;
    h->flags &= ~0x2;
    h->flags &= ~0x80;
    h->x178 = 0;
    h->x180 = 0;
    h->x17c = 0;
    if (o->x1c8 != NULL) {
        id = o->h17a;
        if ((id >= 3000 && id <= 3999) || (id >= 50100 && id <= 50999) || strcmp("man", o->x1c8->name) == 0) {
            h->flags |= 0x80;
            h->x19c = 1.0f;
        }
    }
    h->h1e = -1;
    h->x6c = 0;
    h->x70 = 1;
    h->x74 = 0;
    memset(&h->x78, 0, sizeof(V3));
    if (o->x1c8->x20 != NULL) {
        fn_80227810(o->x1c8->x20);
    }
    if (o->hit != NULL) {
        id = o->hit->key.id;
        if (id == 0xffff) {
            id = o->h17a;
        }
    } else {
        id = o->h17a;
    }
    h->x10 = fn_800DE554(id);
    h->h14 = fn_800DE5EC(id);
    h->h16 = fn_800DE598(id);
    h->hE = 0;
    if (fn_800E0C38(id) != 0) {
        h->flags |= 0x40;
    } else {
        h->flags &= ~0x40;
    }
    if (h->flags & 0x40) {
        v = 0;
        if (h->x10 == 1) {
            v = 3;
        }
        h->hE = v;
    }
    h->flags |= 0x10;
    h->x84 = fn_80167244(fn_801C8930(o->model), 0xff0000);
    h->x88 = fn_80167244(fn_801C8930(o->model), 0xff00);
    h->x8c = fn_80167244(fn_801C8930(o->model), 0xff);
    h->xe0 = 0;
    h->x12c = 0;
    h->x94 = 0;
    h->x124 = 0;
    h->x170 = 0;
    h->xd8 = 0;
    h->hC = 0;
    fn_801E0FD4(h->x1a4, sizeof(h->x1a4));
    if (h->x84 != NULL && h->x84->next != NULL) {
        h->x48 = h->x84->next->x14;
        h->x4c = h->x84->next->x18;
        h->x50 = h->x84->next->x1c;
    }
    return 1;
}

void* fn_8015F180(Obj_8015F180* self)
{
    Sub_8015F180* sub = self->sub;
    if (sub == 0) {
        return self;
    }
    if (sub->next == 0) {
        return self;
    }
    return sub->next;
}

void *fn_8015F1A0(u32 idx) {
    Rec_UNIT0000 *r;
    if ((u16)idx == 0xFFFF) return lbl_80347450;
    r = fn_8010A164((u16)idx);
    if (r && r->x24) return r->x24;
    return 0;
}

s32 fn_8015F1F0(Obj_8015F1F0* self)
{
    Sub_8015F1F0* sub = self->sub;
    if (sub != 0) {
        return sub->val != 0;
    }
    return 0;
}

s32 fn_8015F298(u32 *a, u32 *b) {
    if (a[0] == b[0] && a[0] == 7 && a[1] == b[1] &&
        (a[2] & 0xFFFF0000) == (b[2] & 0xFFFF0000)) {
        return 1;
    }
    return 0;
}

static inline s32 ObjIsMoving(Obj_8015F768 *o) {
    Sub_8015F768 *s = o->x1d8;
    s32 r;
    if (s == 0) return 0;
    r = 0;
    if (s->x178 == 1 || s->x178 == 3) r = 1;
    return r != 0;
}

void fn_8015F2E8(NjObj* owner);
extern void fn_80118AA4(EvObj *o);
extern void fn_80118948(EvObj *o);
extern void fn_801C8450(void *id);
extern void fn_801C83B4(void *id);
extern void fn_801E4FD4(EvObj *o);
extern void fn_80286EE8(void);
extern void fn_8028B498(void);
extern void fn_801E4CB0(s32 id, void *model);
extern s32 lbl_80347444;

void fn_8015F3B0(EvObj *a, Obj8015F2E8 *b)
{
    s32 saved;

    if (b->draw != 0) {
        b->draw(a, 0);
        return;
    }
    if (a == 0) {
        return;
    }
    if (b->flags & 0x80) {
        if (a->colour.a >= -1.0f) {
            fn_80118AA4(a);
        }
    }
    if (b->f94 != 0 || b->f12c != 0 || b->fe0 != 0) {
        if (a->colour.a > -1.0f) {
            saved = lbl_80347444;
            lbl_80347070 = b;
            lbl_80347444 = 0;
            if (b->f94 != 0 && b->n84 != 0) {
                b->n84->owner->evalflags |= 8;
            }
            if (b->f12c != 0 && b->n8c != 0) {
                b->n8c->owner->evalflags |= 8;
            }
            if (b->fe0 != 0 && b->n88 != 0) {
                b->n88->owner->evalflags |= 8;
            }
            fn_801C8450(fn_8015F2E8);
            fn_80118948(a);
            fn_801C83B4(fn_8015F2E8);
            if (b->f94 != 0 && b->n84 != 0) {
                b->n84->owner->evalflags ^= 8;
            }
            if (b->f12c != 0 && b->n8c != 0) {
                b->n8c->owner->evalflags ^= 8;
            }
            if (b->fe0 != 0 && b->n88 != 0) {
                b->n88->owner->evalflags ^= 8;
            }
            fn_801E4FD4(a);
            njPushMatrixEx();
            fn_80286EE8();
            fn_8028B498();
            if (b->f94 != 0) {
                fn_80299040(b->tex98);
                njSetMatrix(0, b->m98);
                fn_801E4CB0(a->id, b->mdl98);
            }
            if (b->f12c != 0) {
                fn_80299040(b->tex130);
                njSetMatrix(0, b->m130);
                fn_801E4CB0(a->id, b->mdl130);
            }
            if (b->fe0 != 0) {
                fn_80299040(b->texe4);
                njSetMatrix(0, b->me4);
                fn_801E4CB0(a->id, b->mdle4);
            }
            njPopMatrixEx();
            DrawStatePop(0);
            lbl_80347444 = saved;
            lbl_80347070 = 0;
        }
    } else {
        saved = lbl_80347444;
        lbl_80347444 = 0;
        fn_80118948(a);
        lbl_80347444 = saved;
    }
}

s32 fn_8015F768(Obj_8015F768 *o) {
    return ObjIsMoving(o);
}

void fn_8015FB98(void *a, Obj_8015FB98 *b) {
    u32 v = (u32)fn_8008F8FC(b, (s32)a);
    if (v != b->xec) {
        b->xf4 = b->xec;
        b->xec = v;
    }
}

typedef struct {
    f32 x, y, z;
    f32 h;
    s16 a;
    u16 b;
    u32 x14;             /* ADD: 0x14 */
} Probe;
void fn_801671C0(EvObj *obj);
void fn_801600E0(void *dst_, void *src_);
s32 fn_80160424(f32 x, Spl *sp, void *b, void *c);
u32 fn_8015FAD4(NJS_POINT3 *pos);
extern s32 fn_802256A0(NJS_POINT3 *p, void *q, s32 a, u16 b);
extern s32 fn_80224588(s32 a, Probe *p, s32 b);

static inline s32 Busy_80160A4C(Ent_8015EBF4 *e)
{
    Hold_8015EB8C *st = e->x1d8;
    s32 r;
    if (st == 0) {
        return 0;
    }
    r = 0;
    if (st->x178 == 1 || st->x178 == 3) {
        r = 1;
    }
    return r != 0;
}

static inline void Ground_80160A4C(EvObj *o, f32 y)
{
    u32 id = fn_8015FAD4(&o->pos);
    if (o->hit != NULL) {
        if (fn_802256A0(&o->pos, o->hit, 0xffff, id) == 0) {
            o->pos.y = y;
        }
    } else {
        Probe p;
        p.x = o->pos.x;
        p.y = o->pos.y;
        p.z = o->pos.z;
        if (fn_80224588(0xffff, &p, 1) != 0) {
            if (p.a != 0) {
                o->pos.y = p.h;
            } else {
                o->pos.y = y;
            }
        }
    }
}

static inline s32 AngStep(s32 to, s32 from, s32 n)
{
    s32 d = to - from;
    if (d > 0x8000) {
        d -= 0x10000;
    } else if (-d > 0x8000) {
        d += 0x10000;
    }
    return d / n;
}

extern void fn_80225930(u16 a, u16 b, void *c);
void fn_8016058C(s32 n, Key *ents, EvObj *obj)
{
    Key *e = ents;
    s32 j;
    s32 id;
    s32 flag = 0;
    s32 mask;
    s32 saved;
    EvHit *hit;
    Vec v;
    Probe pr;

    for (j = 0; j < n; e++, j++) {
        if (e->x28 == 0x7fffffff) {
            if (j == 0) {
                if (obj->hit != 0) {
                    e->x28 = obj->hit->x2e;
                } else {
                    e->x28 = 0;
                }
            } else {
                e->x28 = e[-1].x28;
            }
        }
        if (1.17549435e-38f == e->p0.y) {
            switch (e->x28) {
            case -1:
                e->p0.y = j == 0 ? obj->pos.y : e[-1].p0.y;
                break;
            default:
                if (obj->hit != 0) {
                    id = obj->hit->key.id;
                    flag = 1;
                    mask = obj->hit->key.x28;
                } else {
                    mask = 0xffff;
                }
                v.x = e->p0.x;
                v.y = obj->pos.y;
                v.z = e->p0.z;
                hit = obj->hit;
                if (hit != 0) {
                    saved = hit->x30;
                    fn_80225930(0xffff, e->x28, hit);
                    if (fn_802256A0(&v, obj->hit, 0xffff, e->x28) == 0) {
                        v.y = obj->pos.y;
                    }
                    obj->hit->x30 = saved;
                } else {
                    pr.x = v.x;
                    pr.y = v.y;
                    pr.z = v.z;
                    if (fn_80224588(0xffff, &pr, 1) != 0) {
                        if (pr.a != 0) {
                            v.y = pr.h;
                        } else {
                            v.y = obj->pos.y;
                        }
                    }
                }
                e->p0.y = v.y;
                v.x = obj->pos.x;
                v.z = obj->pos.z;
                if ((mask != 0xffff || flag != 0) && obj->hit != 0) {
                    fn_802256A0(&v, obj->hit, 0xffff, id);
                } else {
                    obj->pos.y = v.y;
                }
                break;
            }
        }
    }
}

extern void fn_8021331C(u32 n, f32 **pts, Pair *ctl);

Spl *fn_801607A0(s32 n, Key *keys, Vec *v) {
    Spl *s;
    s32 i;
    if (n <= 0) {
        return 0;
    }
    s = fn_801E1A2C(1, 0x1c);
    if (s == 0) {
        return 0;
    }
    s->count = n + 1;
    s->xc = fn_801E1A2C(1, s->count * 4);
    s->x10 = fn_801E1A2C(1, s->count * 8);
    s->x8 = fn_801E1A2C(1, s->count * 4);
    s->xc[0] = fn_801E1A2C(1, 0xc);
    s->xc[0][0] = v->x;
    s->xc[0][1] = v->y;
    s->xc[0][2] = v->z;
    for (i = 0; i < s->count - 1; i++) {
        s->xc[i + 1] = fn_801E1A2C(1, 0xc);
        s->x10[i].a = fn_801E1A2C(1, 0xc);
        s->x10[i].b = fn_801E1A2C(1, 0xc);
        s->x8[i] = keys[i].x18;
        s->xc[i + 1][0] = keys[i].p0.x;
        s->xc[i + 1][2] = keys[i].p0.z;
        s->xc[i + 1][1] = keys[i].p0.y;
    }
    fn_8021331C(s->count, s->xc, s->x10);
    return s;
}

s32 fn_80160A4C(Ent_8015EBF4 *self, Arg_8016679C *a)
{
    Hold_8015EB8C *h = self->x1d8;
    EvObj *o = h->x8;
    s32 k;
    f32 y;

    if (Busy_80160A4C(self) != 0) {
        return 0;
    }
    switch (o->state) {
    case 0:
        h->h1c = 0;
        h->h1a = 0;
        o->x24c.x = o->pos.x;
        o->x24c.y = o->pos.y;
        o->x24c.z = o->pos.z;
        o->x20c = o->ang[0];
        o->x210 = o->ang[1];
        o->x214 = o->ang[2];
        o->x20c &= 0xffff;
        o->x210 &= 0xffff;
        o->x214 &= 0xffff;
        fn_801671C0(o);
        o->state = 1;
    case 1:
        y = o->pos.y;
        o->home.x = o->pos.x;
        o->home.y = o->pos.y;
        o->home.z = o->pos.z;
        o->tgt[0] = o->ang[0];
        o->tgt[1] = o->ang[1];
        o->tgt[2] = o->ang[2];
        k = fn_80160424((f32)h->h1a, a->x24, &o->pos, a->x20[h->h1c].x20);
        if (k == -1) {
            o->pos.x = a->x20[a->x1c - 1].p0.x;
            if (1.1754944e-38f != a->x20[a->x1c - 1].p0.y) {
                o->pos.y = a->x20[a->x1c - 1].p0.y;
            }
            o->pos.z = a->x20[a->x1c - 1].p0.z;
            if (3.4028235e38f != a->x20[a->x1c - 1].rot[0]) {
                o->ang[0] = 182.04445f * a->x20[a->x1c - 1].rot[0];
            }
            if (3.4028235e38f != a->x20[a->x1c - 1].rot[1]) {
                o->ang[1] = 182.04445f * a->x20[a->x1c - 1].rot[1];
            }
            if (3.4028235e38f != a->x20[a->x1c - 1].rot[2]) {
                o->ang[2] = 182.04445f * a->x20[a->x1c - 1].rot[2];
            }
            if (1.1754944e-38f == a->x20[a->x1c - 1].p0.y) {
                Ground_80160A4C(o, y);
            }
            fn_801671C0(o);
            fn_801600E0(self, o);
            return 0;
        }
        if (k != h->h1c) {
            h->h1c = k;
        }
        if (1.1754944e-38f == a->x20[k].p0.y) {
            Ground_80160A4C(o, y);
        }
        {
        s32 d[3] = {0, 0, 0};
        s32 n;
        n = a->x20[k].x18;
        if (n == 0) {
            n = 1;
        }
        if (k == 0) {
            if (3.4028235e38f != a->x20[k].rot[0]) {
                d[0] = AngStep(182.04445f * a->x20[k].rot[0], o->x20c, n);
            }
            if (3.4028235e38f != a->x20[k].rot[1]) {
                d[1] = AngStep(182.04445f * a->x20[k].rot[1], o->x210, n);
            }
            if (3.4028235e38f != a->x20[k].rot[2]) {
                d[2] = AngStep(182.04445f * a->x20[k].rot[2], o->x214, n);
            }
            o->ang[0] += d[0];
            o->ang[1] += d[1];
            o->ang[2] += d[2];
        } else {
            if (3.4028235e38f != a->x20[k].rot[0]) {
                d[0] = AngStep(182.04445f * a->x20[k].rot[0], 182.04445f * a->x20[k - 1].rot[0], n);
            }
            if (3.4028235e38f != a->x20[k].rot[1]) {
                d[1] = AngStep(182.04445f * a->x20[k].rot[1], 182.04445f * a->x20[k - 1].rot[1], n);
            }
            if (3.4028235e38f != a->x20[k].rot[2]) {
                d[2] = AngStep(182.04445f * a->x20[k].rot[2], 182.04445f * a->x20[k - 1].rot[2], n);
            }
            o->ang[0] += d[0];
            o->ang[1] += d[1];
            o->ang[2] += d[2];
        }
        }
        fn_801671C0(o);
        h->h1a++;
        o->x24c.x = o->pos.x;
        o->x24c.y = o->pos.y;
        o->x24c.z = o->pos.z;
        break;
    }
    fn_801600E0(self, o);
    return 1;
}

s32 fn_80165DE8(Spl *sp, s32 frame, void *out);
s32 fn_801614E0(Ent_8015EBF4 *self, Arg_8016679C *a)
{
    Hold_8015EB8C *h = self->x1d8;
    EvObj *o = h->x8;
    s32 k;
    f32 y;

    if (Busy_80160A4C(self) != 0) {
        return 0;
    }
    switch (o->state) {
    case 0:
        h->h1c = 0;
        h->h1a = 0;
        o->x24c.x = o->pos.x;
        o->x24c.y = o->pos.y;
        o->x24c.z = o->pos.z;
        o->x20c = o->ang[0];
        o->x210 = o->ang[1];
        o->x214 = o->ang[2];
        o->x20c &= 0xffff;
        o->x210 &= 0xffff;
        o->x214 &= 0xffff;
        fn_801671C0(o);
        o->state = 1;
    case 1:
        y = o->pos.y;
        o->home.x = o->pos.x;
        o->home.y = o->pos.y;
        o->home.z = o->pos.z;
        o->tgt[0] = o->ang[0];
        o->tgt[1] = o->ang[1];
        o->tgt[2] = o->ang[2];
        k = fn_80165DE8(a->x24, h->h1a, &o->pos);
        if (k == -1) {
            o->pos.x = a->x20[a->x1c - 1].p0.x;
            if (1.1754944e-38f != a->x20[a->x1c - 1].p0.y) {
                o->pos.y = a->x20[a->x1c - 1].p0.y;
            }
            o->pos.z = a->x20[a->x1c - 1].p0.z;
            if (3.4028235e38f != a->x20[a->x1c - 1].rot[0]) {
                o->ang[0] = 182.04445f * a->x20[a->x1c - 1].rot[0];
            }
            if (3.4028235e38f != a->x20[a->x1c - 1].rot[1]) {
                o->ang[1] = 182.04445f * a->x20[a->x1c - 1].rot[1];
            }
            if (3.4028235e38f != a->x20[a->x1c - 1].rot[2]) {
                o->ang[2] = 182.04445f * a->x20[a->x1c - 1].rot[2];
            }
            if (1.1754944e-38f == a->x20[a->x1c - 1].p0.y) {
                Ground_80160A4C(o, y);
            }
            fn_801671C0(o);
            fn_801600E0(self, o);
            return 0;
        }
        if (k != h->h1c) {
            h->h1c = k;
        }
        if (1.1754944e-38f == a->x20[k].p0.y) {
            Ground_80160A4C(o, y);
        }
        {
        s32 d[3] = {0, 0, 0};
        s32 n;
        n = a->x20[k].x18;
        if (n == 0) {
            n = 1;
        }
        if (k == 0) {
            if (3.4028235e38f != a->x20[k].rot[0]) {
                d[0] = AngStep(182.04445f * a->x20[k].rot[0], o->x20c, n);
            }
            if (3.4028235e38f != a->x20[k].rot[1]) {
                d[1] = AngStep(182.04445f * a->x20[k].rot[1], o->x210, n);
            }
            if (3.4028235e38f != a->x20[k].rot[2]) {
                d[2] = AngStep(182.04445f * a->x20[k].rot[2], o->x214, n);
            }
            o->ang[0] += d[0];
            o->ang[1] += d[1];
            o->ang[2] += d[2];
        } else {
            if (3.4028235e38f != a->x20[k].rot[0]) {
                d[0] = AngStep(182.04445f * a->x20[k].rot[0], 182.04445f * a->x20[k - 1].rot[0], n);
            }
            if (3.4028235e38f != a->x20[k].rot[1]) {
                d[1] = AngStep(182.04445f * a->x20[k].rot[1], 182.04445f * a->x20[k - 1].rot[1], n);
            }
            if (3.4028235e38f != a->x20[k].rot[2]) {
                d[2] = AngStep(182.04445f * a->x20[k].rot[2], 182.04445f * a->x20[k - 1].rot[2], n);
            }
            o->ang[0] += d[0];
            o->ang[1] += d[1];
            o->ang[2] += d[2];
        }
        }
        fn_801671C0(o);
        h->h1a++;
        o->x24c.x = o->pos.x;
        o->x24c.y = o->pos.y;
        o->x24c.z = o->pos.z;
        break;
    }
    fn_801600E0(self, o);
    return 1;
}

/* Integer-time variant of fn_80160424: find the segment holding t and evaluate it into out. */
typedef struct Cmd_801649BC {
    u8 pad0[0x1c];
    u32 code;            /* 0x1C */
    s32 shape;           /* 0x20 */
    f32 scale;           /* 0x24 */
} Cmd_801649BC;
extern s32 fn_801E78C8(NJS_MOTION *m, NJS_POINT3 *pos, Angle *rot, NJS_POINT3 *d4, f32 frame);
extern void fn_800A13D8(s32 m, Angle *out);
s32 fn_8015FE60(s32 idx, EvObj *o, f32 a);

s32 fn_801649BC(EvObj *self, Cmd_801649BC *cmd) {
    Angle ax, ay, az;
    EvObj *c = self->sub->target;
    NJS_POINT3 pos;
    NJS_POINT3 d4;
    Angle rot[3];
    f32 t;
    f32 inv;
    u16 flags;
    s32 r;
    f32 px, py, pz;
    u32 code;

    switch (c->state) {
    case 0:
        code = cmd->code;
        c->motionId = code;
        c->x24c.x = c->pos.x;
        c->x24c.y = c->pos.y;
        c->x24c.z = c->pos.z;
        c->x20c = c->ang[0];
        c->x210 = c->ang[1];
        c->x214 = c->ang[2];
        t = cmd->scale;
        if (t == 3.4028235e38f) {
            t = 1.0f;
        }
        if (t == 0.0f) {
            return 0;
        }
        inv = 1.0f / t;
        if (code == 0xffffffff) {
            c->motion2 = c->motion;
            c->x1a0 = c->x18c;
            c->motion = 0;
            c->x18c = 0.0f;
            c->speed = 0.0f;
            c->x19c = 1;
            c->x198 = 1;
            return 0;
        }
        if (fn_8015FE60(c->motionId, c, inv) == 0) {
            return 0;
        }
        if (cmd->shape == 0x7fffffff) {
            c->shape2 = c->shape;
            c->shape = 0;
        } else {
            void *m = fn_8008F8FC(c, cmd->shape);
            if (m != c->shape) {
                c->shape2 = c->shape;
                c->shape = m;
            }
        }
        c->state = 1;
    case 1:
        if (cmd->code == 0x7fffffff) {
            c->x18c = 0.0f;
        } else if (cmd->code == 0x7ffffffe) {
            c->x18c = c->motion->nbFrame - 1.0f;
        }
        r = fn_801E78C8(c->motion, &pos, rot, &d4, c->x18c);
        if (c->coll != 0) {
            px = c->pos.x;
            py = c->pos.y;
            pz = c->pos.z;
            ax = c->ang[0];
            ay = c->ang[1];
            az = c->ang[2];
            {
                NJS_POINT3 zero = {0.0f, 0.0f, 0.0f};
                njPushMatrixEx();
                fn_80286EE8();
                fn_8028B498();
                njUnitMatrix(0);
                pos.x = pos.x * c->scl.x;
                pos.y = pos.y * c->scl.y;
                pos.z = pos.z * c->scl.z;
                njTranslate(0, c->x24c.x, c->x24c.y, c->x24c.z);
                njRotateXYZ(0, c->x20c, c->x210, c->x214);
                flags = r;
                if (flags & 1) {
                    njTranslate(0, pos.x, pos.y, pos.z);
                }
                if (flags & 2) {
                    njRotateXYZ(0, rot[0], rot[1], rot[2]);
                }
                njCalcPoint(0, &zero, &pos);
                fn_800A13D8(0, rot);
                c->coll->pos[0] = pos.x;
                c->coll->pos[1] = pos.y;
                c->coll->pos[2] = pos.z;
                c->coll->ang[0] = rot[0];
                c->coll->ang[1] = rot[1];
                c->coll->ang[2] = rot[2];
                njPopMatrixEx();
                fn_80222838(c->coll);
            }
            c->pos.x = px;
            c->pos.y = py;
            c->pos.z = pz;
            c->ang[0] = ax;
            c->ang[1] = ay;
            c->ang[2] = az;
        }
        if (0.0f < c->speed) {
            if (c->x18c >= c->motion->nbFrame - 1.001f) {
                c->speed = 0.0f;
                c->x18c = c->motion->nbFrame - 1.0f;
                return 0;
            }
            if (c->x18c + c->speed > c->motion->nbFrame - 1.0f) {
                cmd->code = 0x7ffffffe;
            }
        } else {
            if (c->x18c < fabsf(c->speed)) {
                if (c->x18c != 0.0f) {
                    cmd->code = 0x7fffffff;
                } else {
                    c->speed = 0.0f;
                    c->x18c = 0.0f;
                    return 0;
                }
            } else if (c->x18c + c->speed < 0.0f) {
                cmd->code = 0x7fffffff;
            }
        }
        break;
    default:
        break;
    }
    return 1;
}

s32 fn_80165DE8(Spl *sp, s32 t, void *out) {
    u32 n;
    u32 k;
    u32 i;
    if (t < 0) {
        return -1;
    }
    if (sp == 0) {
        return -1;
    }
    n = sp->count - 1;
    k = 0;
    for (i = 0; i < n; i++) {
        if (t <= sp->x8[i]) {
            break;
        }
        k++;
        t -= sp->x8[i];
    }
    if (k >= n) {
        return -1;
    }
    fn_80213178(t, sp->x8[k], sp->xc[k], sp->x10[k].a, sp->x10[k].b, sp->xc[k + 1], out);
    return k;
}

static inline s32 Step_80166220(EvObj *in, u32 i)
{
    s16 diff;
    if (in != 0 && i < 3) {
        in->ang[i] += in->rotv[i];
        diff = in->tgt[i] - in->ang[i];
        if ((in->rotv[i] > 0 && diff <= 0) || (in->rotv[i] <= 0 && diff >= 0)) {
            in->ang[i] = in->tgt[i];
            return 1;
        }
    }
    return 0;
}

static inline s32 Pred_80166220(EvObj *o, Tab_80166138 *a)
{
    EvSub *s = o->sub;
    if (s && a && a->ents && a->count && a->count > s->idx) {
        return 1;
    }
    return 0;
}

static inline s32 StepAll_80166220(EvObj *in)
{
    s32 ok = 1;
    s32 i;
    if (in != 0) {
        for (i = 0; i < 3; i++) {
            ok = Step_80166220(in, i) != 0 && ok != 0;
        }
    }
    return ok;
}

static inline void SyncHit_80166220(EvObj *in)
{
    f32 *vp;
    if (in != 0 && in->coll != 0) {
        vp = in->coll->pos;
        {
            f32 x = in->pos.x, y = in->pos.y, z = in->pos.z;
            vp[2] = z;
            vp[1] = y;
            vp[0] = x;
        }
        in->coll->ang[0] = in->ang[0];
        in->coll->ang[1] = in->ang[1];
        in->coll->ang[2] = in->ang[2];
        fn_80222838(in->coll);
    }
}

static inline s32 Move_80166220(EvObj *in, f32 f)
{
    s32 ok = 1;
    s32 sx;
    s32 sz;
    if (in != 0) {
        sx = in->ang[0];
        sz = in->ang[2];
        ok = StepAll_80166220(in);
        if (lbl_80311AC0.f4 != 0x1c || lbl_80311AC0.f8 != 0x62) {
            in->ang[0] = sx;
            in->ang[2] = sz;
        }
        SyncHit_80166220(in);
        if (ok != 0) {
            in->speed = f;
        }
    }
    return ok != 0;
}

s32 fn_80166220(EvObj *obj, Tab_80166138 *arg)
{
    s32 ok = 1;
    EvSub *st = obj->sub;
    EvObj *in = st->target;

    if (in != 0) {
        ok = Move_80166220(in, st->x20);
        if (Pred_80166220(obj, arg) != 0) {
            Ent_80166138 *e = &arg->ents[st->idx];
            if (e->f2c != 1 && in->x198 != 0) {
                fn_801E735C(in->x172, 1.0f, in);
            }
        }
    }
    return ok;
}

s32 fn_8016645C(Obj_8016645C *o, Arg *a) {
    Sub_8016645C *s = o->x1d8;
    if (s && a && a->x20 && a->x1c && a->x1c > (u32)(s32)s->x1a) {
        return 1;
    }
    return 0;
}
void fn_8016694C(Vec *a, Vec *b, V3i *out) {
    Vec d;

    if (a != 0 && b != 0 && out != 0) {
        d.x = b->x - a->x;
        d.y = b->y - a->y;
        d.z = b->z - a->z;
        fn_802135B4(&d, out);
    }
}

void fn_801679A4(Fx_801677D0 *t)
{
    St_801677D0 *w = t->st;
    f32 f31;
    f32 v;
    s32 vol;

    if ((t->flags & 0x20) || (w->x2c->flags & 0x40)) {
        t->state = 0xff;
    }
    switch (t->state) {
    case 0xfe:
    case 0:
        if (++lbl_80347088 == 0) {
            lbl_80347088 = 1;
        }
        w->id = lbl_80347088;
        t->state = 10;
    case 10:
        if (fn_80216F48(w->x0) == 0) {
            t->state = 0xff;
            break;
        }
        f31 = 1.0f;
        v = t->st->x48;
        if (v) {
            t->st->x48 = v - 1.0f;
            if (!t->st->x48) {
                t->state = 0xff;
            }
            f31 = t->st->x48 / 12.0f;
        }
        if ((t->st->x38 & 3) == 0) {
            v = fn_80167C34(w);
            if (v != w->x3c) {
                w->x3c = v;
                w->x44 = (w->x3c - w->x40) / 12.0f;
            }
            v = w->x44;
            if (v) {
                w->x40 = w->x40 + v;
                if (w->x40 <= w->x3c + 0.5 && w->x40 >= w->x3c - 0.5) {
                    w->x40 = w->x3c;
                    w->x44 = 0.0f;
                }
            }
            if (w->x44 || 1.0 != f31) {
                vol = w->x40 * f31 - 127.0;
                fn_802172C8(w->x0, vol);
            }
        }
        t->st->x38 = t->st->x38 + 1;
        break;
    case 0xff:
        if (fn_80216F48(w->x0) == 1) {
            fn_80217830(w->x0);
        }
        if (t->st->x30 == 0) {
            lbl_8034708C = t->st->x34;
        } else {
            t->st->x30->st->x34 = t->st->x34;
        }
        if (t->st->x34 != 0) {
            t->st->x34->st->x30 = t->st->x30;
        }
        t->flags |= 0x40;
        break;
    }
}

s32 fn_80168A04(Obj_80168A04* a, s32 b);
s8 fn_80167EF0(Sub_80168A04 *a);
extern f32 njScalor(Vec_8016022C *v);
/* Ninja NJM_RAD_ANG: radians to a 0x10000-per-turn angle. */
static inline s32 RadToAng(f32 r) { return 10430.381f * r; }
extern void fn_8021A094(u8 *p);
extern f32 lbl_80347510;

s32 fn_80167C34(St_801677D0 *w)
{
    void *h;
    s32 base;
    Vec_8016022C o;
    Vec_8016022C p;
    Vec_8016022C d;
    f32 dist;
    f32 a, b;
    s32 n;
    s8 id;
    f32 g, g2;
    s32 x, y, m;

    base = w->x18 + 0x7f;
    if (w->x2c != 0) {
        h = w->x2c->work;
    } else {
        h = fn_8015F1A0(w->x18 >> 16);
    }
    if (h == 0 && fn_800C8D90() != 0) {
        return -0x7f;
    }
    h = fn_8015F180(h);
    p.x = w->x1c;
    p.y = w->x20;
    p.z = w->x24;
    fn_8009FDA0(h, 3, &o, 0, &p, 0, 1);
    d.x = lbl_803119E0.pos.x - o.x;
    d.y = lbl_803119E0.pos.y - o.y;
    d.z = lbl_803119E0.pos.z - o.z;
    dist = njScalor(&d);
    if (w->xe >= 0) {
        a = atan2(o.x - lbl_803119E0.pos.x, o.z - lbl_803119E0.pos.z);
        b = atan2(lbl_803119E0.dir.x, lbl_803119E0.dir.z);
        n = RadToAng(b) - RadToAng(a);
        n = 127.0f * (0.5f * (1.0f - njSin(n)));
        id = w->xe;
        if (id < 2) {
            lbl_80347078[id] = lbl_80347080[id];
            lbl_80347080[w->xe] = (n ^ 0x7f) + 0x80;
            if (lbl_80347078[w->xe] != lbl_80347080[w->xe]) {
                fn_8021A094(lbl_80347080);
            }
        }
    }
    if (dist >= 0.0f && w->x28 >= 0.0f) {
        g = w->x28;
        g2 = 2.0f * g;
        x = base * (g2 - dist) / g2;
        y = x * (1.0f - lbl_80347510);
        m = y > 0x14 ? y : 0x14;
        return m >= 0xff ? 0xff : m;
    }
    return 0;
}

void fn_801680B4(Obj_80168A04 *t)
{
    Sub_80168A04 *w;
    s32 flag = 0;
    s8 r;
    u8 idx;
    s32 i;

    if (t->b18 & 0x20) {
        t->b19 = 0xff;
    }
    w = t->sub;
    if (w->x30 == 0) {
        lbl_80306F58[0].obj = 0;
        lbl_80306F58[0].state = 0;
        lbl_80306F58[1].obj = 0;
        lbl_80306F58[1].state = 0;
        lbl_80306F58[2].obj = 0;
        lbl_80306F58[2].state = 0;
    }
    if (w->x34 == 0) {
        flag = 1;
    }
    switch (t->b19) {
    case 0xfe:
    case 0:
        if (++lbl_80347088 == 0) {
            lbl_80347088 = 1;
        }
        w->id = lbl_80347088;
        idx = w->f18 >> 8;
        if (idx != 0) {
            lbl_8030CEA0.tbl[idx] = w->id;
        }
        t->b19 = 5;
    case 5:
        r = fn_80167EF0(w);
        if (r > -0x7f) {
            if (w->w0 == 0 || r != w->bF) {
                w->bF = r;
                fn_80168A04(t, 1);
            }
        }
        break;
    case 10:
        if (fn_80216F48(w->w0) == 0) {
            w->w0 = 0;
            t->b19 = 5;
            break;
        }
        r = fn_80167EF0(w);
        if (r == -0x7f) {
            fn_80217830(w->w0);
            w->w0 = 0;
            t->b19 = 5;
            break;
        }
        if (fabs(r - w->bF) >= 2.0) {
            w->bF = r;
            fn_80168A04(t, 2);
        } else {
            fn_80168A04(t, 3);
        }
        break;
    case 0xff:
        if (w->w0 >= 2) {
            if (fn_80216F48(w->w0) == 1) {
                fn_80217830(w->w0);
                w->w0 = 0;
            }
        }
        for (i = 0; i < 3; i++) {
            if (lbl_80306F58[i].obj == t) {
                lbl_80306F58[i].obj = 0;
                lbl_80306F58[i].state = 0;
                break;
            }
        }
        if (t->sub->x30 == 0) {
            lbl_8034708C = t->sub->x34;
        } else {
            t->sub->x30->sub->x34 = t->sub->x34;
        }
        if (t->sub->x34 != 0) {
            t->sub->x34->sub->x30 = t->sub->x30;
        }
        t->b18 |= 0x40;
        break;
    }
    if (flag) {
        fn_80168908();
    }
}

void fn_8016ABEC(void)
{
    fn_8016D01C();
    fn_8016C4B0();
    fn_8016B620();
    fn_8016AD08();
}

extern void fn_8016AB98(Arg_8016CAB4 *p);
extern void fn_8016AAF0(Arg_8016CAB4 *p);
extern void fn_8016AA9C(Arg_8016CAB4 *p);

s32 fn_8016AA0C(Mover* m);
void fn_8016AA64(Mover *m, f32 x, f32 y);
void fn_8016B1E4(void);

static inline f32 Absf(f32 x) { return fabs(x); }

s32 fn_8016AEBC(void* self)
{
    s32 ret;
    s8 sign;
    switch (lbl_803470A0->st->mode) {
    case 0:
        if (lbl_803470A0 != NULL) {
            lbl_803470A0->st->b1 = 0;
        }
        if (lbl_803470A0 != NULL) {
            lbl_803470A0->st->mv.x = -60.0f;
            lbl_803470A0->st->mv.y = 0.0f;
        }
        if (lbl_803470A0 != NULL) {
            fn_8016AA64(&lbl_803470A0->st->mv, 0.0f, 0.0f);
        }
        if (lbl_803470A0 != NULL) {
            lbl_803470A0->st->mode = 6;
        }
        break;
    case 1:
        if (lbl_803470A0 != NULL) {
            lbl_803470A0->st->b1 = 0;
        }
        if (lbl_803470A0 != NULL) {
            lbl_803470A0->st->mv.x = 0.0f;
            lbl_803470A0->st->mv.y = 0.0f;
        }
        if (lbl_803470A0 != NULL) {
            fn_8016AA64(&lbl_803470A0->st->mv, -60.0f, 0.0f);
        }
        if (lbl_803470A0 != NULL) {
            lbl_803470A0->st->mode = 6;
        }
        break;
    case 6:
        if (lbl_803470A0 != NULL) {
            ret = fn_8016AA0C(&lbl_803470A0->st->mv);
        }
        if (ret == 1) {
            if (lbl_803470A0 != NULL) {
                lbl_803470A0->st->mode = 10;
            }
        }
        break;
    case 7:
        if (lbl_803470A0 != NULL) {
            lbl_803470A0->st->b1 = 0;
        }
        if (lbl_803470A0 != NULL) {
            lbl_803470A0->st->mv.x = 0.0f;
            lbl_803470A0->st->mv.y = 0.0f;
        }
        if (lbl_803470A0 != NULL) {
            lbl_803470A0->st->mode = 10;
        }
        break;
    case 8:
        if (lbl_803470A0 != NULL) {
            lbl_803470A0->st->b1 = 1;
        }
        if (lbl_803470A0 != NULL) {
            lbl_803470A0->st->mv.x = 0.0f;
            lbl_803470A0->st->mv.y = 0.0f;
        }
        if (lbl_803470A0 != NULL) {
            lbl_803470A0->st->mode = 10;
        }
        break;
    case 2:
    case 3:
    case 4:
    case 5:
    case 9:
    case 10:
        break;
    }
    {
        St_8016CAB4 *w = lbl_803470A0->st;
        if (Absf(w->f30 - w->f20) <= w->f38 && Absf(w->f44) <= w->f38) {
            w->f30 = w->f20;
        } else {
            sign = (w->f3c + (w->f30 + w->f44) > w->f20) ? -1 : 1;
            w->f3c = w->f38 * sign;
            w->f44 = w->f44 + w->f3c;
            if (Absf(w->f44) > w->f40) {
                w->f44 = (w->f44 > 0.0f) ? w->f40 : -1.0f * w->f40;
            }
            w->f30 = w->f30 + w->f44;
            if (w->f30 < w->f34) {
                w->f30 = w->f34;
            }
        }
    }
    if (lbl_803470A0->st->b1 == 0) {
        fn_8016B1E4();
    }
    return 1;
}

void fn_8016B1E4(void)
{
    s32 i;
    Arg_8016CAB4 q;
    f32 f31;
    f32 f30;
    f32 a;

    for (i = 0; i < 3; i++) {
        q.item = lbl_803470A0->items[i];
        f31 = q.item->x;
        f30 = q.item->y;
        q.item->x = lbl_803470A0->st->mv.x + f31;
        if (i == 1) {
            q.item->y = lbl_803470A0->st->mv.y + lbl_803470A0->items[i]->y
                - lbl_803470A0->st->f24 * (lbl_803470A0->st->f30 / lbl_803470A0->st->f28)
                - lbl_803470A0->st->f24;
        } else if (i == 2) {
            Mat_8016CAB4 *s = q.item->mat;
            f32 h;
            a = 2.0f * lbl_803470A0->st->f28;
            h = (a * ((lbl_803470A0->st->f30 + lbl_803470A0->st->f28) / a)) / 2.0f;
            s->f10 = s->f8 - (1.0f + h);
        } else {
            q.item->y = lbl_803470A0->st->mv.y + lbl_803470A0->items[i]->y;
        }
        q.a = 0.001f * i + -1.3f;
        q.b = 1.0f;
        q.c = 0;
        q.d = 0;
        q.e = 1.0f;
        q.f = 1.0f;
        switch (lbl_803470A0->st->kind) {
        case 0:
            fn_8016AB98(&q);
            break;
        case 1:
            fn_8016AB44(&q);
            break;
        case 2:
            fn_8016AAF0(&q);
            break;
        case 3:
            fn_8016AA9C(&q);
            break;
        }
        q.item->x = f31;
        q.item->y = f30;
    }
}

void fn_8016B620(void) {
    u8* p = (u8*)lbl_803470A0;
    if (p == NULL) {
        return;
    }
    p[0x19] = 2;
}

void fn_8016B950(f32 a, f32 b)
{
    OwnerA_UNIT0000* o = ((OwnerA_UNIT0000*)lbl_803470A0);
    InnerA_UNIT0000* in;
    if (o == 0) {
        return;
    }
    in = o->inner;
    in->f30 = a;
    in->f20 = b;
}

void fn_8016B96C(f32 v)
{
    OwnerA_UNIT0000* o = ((OwnerA_UNIT0000*)lbl_803470A0);
    InnerA_UNIT0000* in;
    if (o == 0) {
        return;
    }
    in = o->inner;
    if (in->mode == 3) {
        v -= lbl_8034ABDC;
    }
    in->f20 = v;
}

void fn_8016B998(u8 v) {
    u8* p = (u8*)lbl_803470A0;
    if (p == NULL) {
        return;
    }
    *(u8*)(*(u8**)((u8*)p + 0x24) + 0x2) = v;
}

void fn_8016B9B0(u8 v) {
    if (lbl_803470A0 == 0) return;
    (*(u8**)((u8*)lbl_803470A0 + 0x24))[1] = v;
}

extern s32 lbl_803467A0;
extern s32 lbl_803470AC;
extern f32 njCos(s32 a);
extern void fn_8016AB98(Arg_8016CAB4 *p);
extern void fn_8016AAF0(Arg_8016CAB4 *p);
extern void fn_8016AA9C(Arg_8016CAB4 *p);
/* tex is the texture handle fn_80297DC8 binds; this caller keeps it as a signed index (-1 = none). */
extern void fn_80090404(s32 tex, u32 colour, f32 x, f32 y, f32 z, f32 w, f32 h, f32 u, f32 v, f32 du, f32 dv);

void fn_8016BF54(void)
{
    Arg_8016CAB4 item;
    DrawState ds;
    f32 ox, oy;
    s32 i;

    for (i = 0; i < 5; i++) {
        item.item = lbl_803470B0->items[i];
        ox = item.item->x;
        oy = item.item->y;
        item.item->x = lbl_803470B0->sub->f4 + ox;
        item.item->y = lbl_803470B0->sub->f8 + lbl_803470B0->items[i]->y;
        item.a = 0.001f * i + -1.3f;
        item.b = 1.0f;
        item.c = 0;
        item.d = 0;
        item.e = 1.0f;
        item.f = 1.0f;
        switch (i) {
        case 0:
            item.b = lbl_803470B0->sub->w3c;
            break;
        case 1:
            break;
        case 2:
        case 3:
            item.b = -lbl_803470B0->sub->w24;
            break;
        }
        switch (lbl_803470B0->sub->kind) {
        case 0:
            fn_8016AB98(&item);
            break;
        case 1:
            fn_8016AB44(&item);
            break;
        case 2:
            fn_8016AAF0(&item);
            break;
        case 3:
            fn_8016AA9C(&item);
            break;
        }
        item.item->x = ox;
        item.item->y = oy;
    }
    if (lbl_803467A0 >= 0) {
        DrawStateDefault2D(&ds);
        DrawStatePush(&ds);
        fn_80090404(lbl_803467A0, -1, 56.0f * njCos(lbl_803470AC) + 557.0f, 56.0f * njSin(lbl_803470AC) + 373.0f, -1.02f, 24.0f, 24.0f, 0.0f, 0.0f, 1.0f, 1.0f);
        DrawStatePop(0);
        lbl_803467A0 = -1;
    }
}

void fn_8016C4B0(void) {
    u8* p = (u8*)lbl_803470B0;
    if (p == NULL) {
        return;
    }
    p[0x19] = 2;
}

void fn_8016C780(u32 a, u32 b)
{
    Obj_8016C4C8* o = lbl_803470B0;
    if (o != 0) {
        o->sub->w3c = a;
    }
    o = lbl_803470B0;
    if (o == 0) {
        return;
    }
    o->sub->w38 = b;
}

void fn_8016C7AC(u32 a, u32 b)
{
    Obj_8016C4C8* o = lbl_803470B0;
    if (o != 0) {
        o->sub->w24 = a;
    }
    o = lbl_803470B0;
    if (o == 0) {
        return;
    }
    o->sub->w20 = b;
}

void fn_8016C7D8(u32 a)
{
    Obj_8016C4C8* o = lbl_803470B0;
    if (o == 0) {
        return;
    }
    o->sub->w38 = a;
}

void fn_8016C7F0(u32 a)
{
    Obj_8016C4C8* o = lbl_803470B0;
    if (o == 0) {
        return;
    }
    o->sub->w20 = a;
}

void fn_8016C870(u8 v) {
    if (lbl_803470B0 == 0) return;
    (*(u8**)((u8*)lbl_803470B0 + 0x24))[1] = v;
}

/* Declared int (as the original, implicitly): no value is returned and the caller ignores r3, but MWCC then keeps r3 (mode) out of the allocation. */
s32 fn_8016CCD8(s32 mode) {
    Sub_8016D034* s = lbl_803470B8->sub;
    Sub_8016D034* p;
    f32 t;
    switch (mode) {
    case 1:
        s->f34 = 1.0f;
        s->f2c = 0.5f;
        s->f20 = s->f20 - 3.0f;
        if (s->f20 < -5.0f) {
            lbl_803470B8->sub->stage = 2;
        }
        break;
    case 2:
        s->f34 = 1.0f;
        s->f2c = 0.5f;
        break;
    case 3:
        s->f34 = 1.0f;
        s->f2c = 0.5f;
        s->f20 += 1.0f;
        if (s->f20 >= 0.0f) {
            lbl_803470B8->sub->stage = 0;
        }
        break;
    case 0:
        if (165.0f < s->f20 && s->f20 < 194.0f) {
            s->f34 = 0.69f;
            lbl_803470B8->sub->stage = 4;
        } else {
            s->f34 = 0.24f;
        }
        s->f2c = 1.0f;
        p = lbl_803470B8->sub;
        p->f20 = p->f24;
        if (p->f20 > 194.0f) {
            p->f20 = 194.0f;
        }
        break;
    case 4:
        if (165.0f >= s->f20) {
            s->f34 = 0.24f;
            lbl_803470B8->sub->stage = 0;
        } else {
            t = s->f34 + 0.46f * s->f30 / 10.0f;
            if (t < 0.24f || 0.7f < t) {
                s->f30 *= -1.0f;
                t += 0.46f * s->f30 / 10.0f;
            }
            s->f34 = t;
        }
        s->f2c = 1.0f;
        p = lbl_803470B8->sub;
        p->f20 = p->f24;
        if (p->f20 > 194.0f) {
            p->f20 = 194.0f;
        }
        break;
    }
}

void fn_8016D01C(void) {
    Owner_8016D034* p = lbl_803470B8;
    if (p == NULL) {
        return;
    }
    p->state = 2;
}

void fn_8016D114(u8 v) {
    Owner_8016D034* p = lbl_803470B8;
    if (p == NULL) {
        return;
    }
    p->sub->x2 = v;
}

extern char lbl_802B4378[];
extern char lbl_802B4390[];
extern void fn_8016D12C(u32 a, s32 b, u32* bits);

static inline s32 FlagTest_8016D904(u32 b) {
    return (lbl_80310B3C[b >> 5] & (1 << (b & 31))) != 0;
}

static inline void FlagClear_8016D904(u32 b) {
    lbl_80310B3C[b >> 5] &= ~(1 << (b & 31));
}

void fn_8016D904(u32 n) {
    u32 bits[6];
    s32 i;
    s32 cur = lbl_80310A1C.x30;
    if (cur == 0 && n == 0) {
        i = 0;
        do {
            FlagClear_8016D904(0x520 + i);
            i++;
        } while (i < 168);
        return;
    }
    if ((u32)cur >= n) {
        fn_801DBE1C(lbl_802B4378, cur, n);
        return;
    }
    if (n >= 3) {
        fn_801DBE1C(lbl_802B4390, n);
        return;
    }
    i = 0;
    do {
        s32 on = FlagTest_8016D904(0x520 + i);
        if (on != 0) {
            bits[i / 32] |= 1 << (i % 32);
        } else {
            bits[i / 32] &= ~(1 << (i % 32));
        }
        i++;
    } while (i < 168);
    i = 0;
    do {
        FlagClear_8016D904(0x520 + i);
        i++;
    } while (i < 168);
    fn_8016D12C(n, cur, bits);
    lbl_80310A1C.x30 = n;
}

s32 fn_8016E1D8(void *p) {
    u32 tmp[2];
    if (!(lbl_80310B3C[0x22] & 4)) return 0;
    fn_8016DBAC(tmp, p);
    return 1;
}

void fn_8016EA60(PanelA* o)
{
    o->x = -6190.0f;
    o->y = 0.0f;
    o->a = 1.0f;
    o->b = 0.0f;
    o->c = 1.0f;
    o->d = 0.0f;
    o->z0 = 0;
    o->z1 = 0;
    fn_8019A15C(o, 1, 1, 1);
    *o->s0 = fn_801D68C4(lbl_803470F0, 7);
    o->p0[0] = 0.0f;
    o->p0[1] = 0.0f;
    *o->s1 = fn_801D68C4(lbl_803470E8, 1);
    o->p1[0] = 0.0f;
    o->p1[1] = 0.0f;
    *o->s2 = fn_801D68C4(lbl_803470F4, 0);
    o->p2[0] = 85.0f;
    o->p2[1] = 29.0f;
    o->s3 = 0;
}

void fn_8016F0D4(Out *o, s8 idx, f32 f) {
    SaveChar *r;
    o->f0 = f;
    o->idx = idx;
    r = &lbl_8030B7F4.chr[idx];
    o->rec = r;
    o->b0c = r->xb;
    o->i10 = r->hp;
    o->i14 = r->hpMax;
    o->i18 = r->mp;
    o->i1c = r->mpMax;
}

void fn_8016F128(Rec_8016F128* r, u8 a, u8 b, f32 v)
{
    r->a = a;
    r->b = b;
    r->f = v;
}

extern s32 fn_801956EC(s32 a);

extern void fn_8018DABC(void *d, s32 id, s8 b, s32 c, s32 kind);
void fn_80171B64(s32 v, s8 slot);

void fn_801705B8(void)
{
    s32 i;
    s8 v;
    s32 idx;
    UiObj *o;
    CampCtrl *ctl;

    ctl = &lbl_80307638[1];
    idx = lbl_8034710C->holder->ctrl->cur[2].sel;
    ctl->cur[0].sel = idx;
    v = lbl_8030B7F4.party[idx];
    fn_80171B64(v, idx);
    o = &camp_work.pnl[ctl->cur[0].sel]->win->obj;
    fn_80199BB8(o, -348.0f, 61.0f);
    fn_80199BAC(o, -348.0f, 61.0f);
    UiObjSetRaised(o);
    for (i = 0; i < 15; i++) {
        void *p = camp_work.pnl[i + 0x23]->win->xbc;
        if (i >= 0 && i < 4) {
            fn_8018DABC(p, v, i, 0, 1);
        } else if (i >= 4 && i < 9) {
            fn_8018DABC(p, v, i - 4, 1, 1);
        } else {
            fn_8018DABC(p, v, i - 9, 2, 1);
        }
    }
}

void fn_80170C64(void) {
    CampCtrl* c;
    u32 mask;
    s32 i;

    c = lbl_8034710C->holder->ctrl;
    c->cur[0].mask = fn_801956EC(lbl_8030B7F4.party[lbl_80307638[1].cur[0].sel]);
    c->cur[4].mask = 7;
    c->cur[2].sel = lbl_80307638[1].cur[0].sel;
    c->cur[2].x8 = lbl_80307638[1].cur[0].sel;
    c->cur[2].mask = 0;
    mask = 0;
    for (i = 0; i < camp_work.count; i++) {
        mask |= 1 << i;
    }
    c->cur[2].mask = mask;
    fn_80195A68(c, 1, 0, 0, 1, 1);
}
extern void fn_801D52A8(Sprite *s, f32 f1, f32 f2, f32 f3, f32 f4, s32 a, s32 b);

#define SLOT(K, ID, SX, SY, TY, TX)     s = fn_801D68C4(lbl_803470F4, ID);     s->x = x + (SX);     s->y = y + (SY);     fn_801D52A8(s, 10.0f + self->pos.f0, self->pos.f4, 1.0f, 1.0f, self->pos.ic, self->pos.i8);     if (d->stat[K].st == 1) {         TextPrint(x + (TX), y + (TY), "-");     } else {         switch (d->stat[K].st) {         case 2:             col = 0xff2b5000;             break;         case 3:             col = 0xff800000;             break;         case 0:             col = 0xff201008;             break;         }         fn_8019A374(d->stat[K].cur, x + (TX), y + (TY), 10.0f + self->pos.f0, col, 0);     }

extern char* lbl_803467C0[2];
extern char lbl_802B45CC[];
extern char lbl_802EBB20[];
extern char lbl_8034B3D8[5];

#define NUM(V, DX, DY) fn_8019A374(V, x + (DX), y + (DY), 100.0f + self->pos.f0, 0xff201008, 0)

#define NAME(S, DY)                                 \
    if (S != NULL) {                                \
        TextPrint(x + 0x32, y + (DY), S);           \
    } else {                                        \
        TextPrint(x + 0x32, y + (DY), lbl_802EBB20); \
    }

#define BONUS(K)                                    \
    NUM(d->x80[K], 0x104, 0xa);                     \
    if (d->x98[K] > 0) {                            \
        NUM(d->x98[K], 0x104, 0x22);                \
    } else {                                        \
        TextPrint(x + 0xe0, y + 0x22, lbl_8034B3D8); \
    }

#define LEVEL()                                     \
    TextPrint(x + 0x1c, y + 6, lbl_803467C0[0]);    \
    TextPrint(x + 0x1c, y + 0x1e, lbl_803467C0[1]); \
    NUM(d->x58, 0x110, 0xa);                        \
    if (d->lv != 99) {                              \
        NUM(d->x5c, 0x110, 0x22);                   \
    } else {                                        \
        TextPrint(x + 0xbc, y + 0x22, lbl_802B45CC); \
    }

/* Text at a float position. */
static inline void TextPrintF(f32 x, f32 y, const char *str)
{
    TextPrint(x, y, str);
}

#define SHOW(xo, av, col)                                                              \
    if (flag == 1) {                                                                   \
        if ((col) == 0xff201008) {                                                     \
            TextPrintF(x + (xo), y + 0x22, "-");                          \
        } else {                                                                       \
            fn_8019A374((av), x + (xo), y + 0x22, 10.0f + self->pos.f0, (col), 0); \
        }                                                                              \
    } else {                                                                           \
        fn_8019A374((av), x + (xo), y + 0x22, 10.0f + self->pos.f0, 0xff201008, 0); \
    }

s32 fn_8015F218(Obj_8015F218 *o) {
    Res *r;
    Sub0 *s;
    s32 n;
    if (o != 0 && o->p1c8 != 0) {
        r = fn_800CCA6C(9, (u16)o->p1c8->f4);
        if (r != 0) {
            s = r->pc;
            s->f0 = 2;
            n = r->f8 >> 16;
            if (n < 3) {
                fn_80210B44(s->p4);
            }
            return n;
        }
    }
    return 0;
}

void fn_8015F654(Obj_8015F654 *o) {
    Inner_8015F654 *r31 = o->p1d8;
    if (r31 != 0) {
        if (r31->f178 == 1 || r31->f178 == 3) {
            r31->f178 = 2;
            fn_800A0028(o);
            r31->f178 = 0;
            o->h16c = 0;
        }
    }
}

void fn_801601AC(Obj_801601AC_UNIT0000 *o) {
    if (o != 0) {
        Inner_801601AC_UNIT0000 *r31 = o->p1d8;
        s32 st = r31->f178;
        void *q = r31->p4->p24;
        if (st == 3) {
            r31->f178 = 2;
            fn_800A0028(q);
            r31->f178 = 0;
            o->h16c = 0;
            o->fb4 = 0.0f;
            o->fb8 = 0.0f;
            o->fbc = 0.0f;
            o->fc0 = 0;
            o->fc4 = 0;
            o->fc8 = 0;
        }
    }
}

void fn_801671C0(EvObj* obj)
{
    EvColl* coll;
    if (obj != NULL && (coll = obj->coll) != NULL) {
        f32* pos = coll->pos;
        f32 x = obj->pos.x;
        f32 y = obj->pos.y;
        f32 z = obj->pos.z;
        pos[2] = z;
        pos[1] = y;
        pos[0] = x;
        obj->coll->ang[0] = obj->ang[0];
        obj->coll->ang[1] = obj->ang[1];
        obj->coll->ang[2] = obj->ang[2];
        fn_80222838(obj->coll);
    }
}

void fn_80167374(Obj_80167374* obj)
{
    A* a = obj->x1d8;
    B* b;
    C* c;
    if (a == NULL) {
        return;
    }
    b = a->x84;
    if (b == NULL) {
        return;
    }
    c = b->x2c;
    if (c == NULL) {
        return;
    }
    c->x14 -= a->x60;
    b = a->x84;
    c = b->x2c;
    c->x18 -= a->x64;
    a->x58 = 0;
    a->x54 = 0;
    a->x64 = 0;
    a->x60 = 0;
}

void* fn_80167428(Node_80167428* node, u32 idx)
{
    Table* t = node->holder->table;
    Node_80167428* cur;

    if (idx < t->count) {
        return t->entries + idx * 12;
    }
    cur = node->next;
    while (cur != NULL) {
        t = cur->holder->table;
        if (idx < t->count) {
            return t->entries + idx * 12;
        }
        cur = cur->next;
    }
    return NULL;
}

void fn_80168B7C(u32 id)
{
    TaskWork_80168B7C* w;
    Task* t;
    Task* next;
    if (id == 0) {
        return;
    }
    t = ((Task*)lbl_8034708C);
    while (t != NULL) {
        w = t->work;
        next = w->link;
        if (w->id == id) {
            TaskDelete(t);
            return;
        }
        t = next;
    }
}

void fn_80169294(void)
{
    Task* t = ((Task*)lbl_8034708C);
    while (t != NULL) {
        TaskWork_80169294* w = t->work;
        Task* next = w->link;
        TaskDelete(t);
        t = next;
    }
    memset(lbl_80347080, 0x40, 8);
    memset(lbl_80347078, 0x40, 8);
}

void fn_801692F8(void)
{
    lbl_8034708C = 0;
    lbl_80347088 = 0;
    lbl_80306F58[0].state = 0;
    lbl_80306F58[0].obj = 0;
    lbl_80306F58[1].state = 0;
    lbl_80306F58[1].obj = 0;
    lbl_80306F58[2].state = 0;
    lbl_80306F58[2].obj = 0;
    memset(lbl_80347080, 0x40, 8);
    memset(lbl_80347078, 0x40, 8);
}

s32 fn_8016AA0C(Mover* m)
{
    if (m->steps <= 0) {
        m->x = m->destX;
        m->y = m->destY;
        return 1;
    }
    m->x = m->x + m->stepX;
    m->y = m->y + m->stepY;
    m->steps = m->steps - 1;
    return 0;
}

void fn_8016AC18(void)
{
    s32 k;
    switch (lbl_80310A1C.f6) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 7:
    case 12:
        k = 0;
        break;
    case 6:
    case 8:
    case 9:
        k = 2;
        break;
    case 10:
    case 11:
    case 13:
    case 14:
    case 15:
    case 16:
        k = 3;
        break;
    }
    fn_8016B638((s8)k);
    fn_8016C4C8((s8)k);
    if (k == 1) {
        fn_8016D034((s8)k);
    }
}

void fn_8016ACA0(void)
{
    s32 k;
    switch (lbl_80310A1C.f6) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 7:
    case 12:
        k = 0;
        break;
    case 6:
    case 8:
    case 9:
        k = 2;
        break;
    case 10:
    case 11:
    case 13:
    case 14:
    case 15:
    case 16:
        k = 3;
        break;
    }
    fn_8016ADD4((s8)k);
}

void fn_8016E818(struct PanelA *a, s32 mode)
{
    switch (mode) {
    case 0:
        fn_8016EB4C(a);
        break;
    case 1:
        fn_8016EA60(a);
        break;
    case 2:
        fn_8016E96C(a);
        break;
    case 3:
        fn_8016E878(a);
        break;
    }
}

void fn_8015F2E8(NjObj* owner) {
    Obj8015F2E8* o = lbl_80347070;
    Node8015F2E8* n;
    if (o == 0) {
        return;
    }
    n = o->n8c;
    if (n != 0 && n->owner == owner && o->f12c != 0) {
        fn_80291C44(o->m130);
    }
    n = lbl_80347070->n88;
    if (n != 0 && n->owner == owner && o->fe0 != 0) {
        fn_80291C44(o->me4);
    }
    n = lbl_80347070->n84;
    if (n != 0 && n->owner == owner && o->f94 != 0) {
        fn_80291C44(o->m98);
    }
}

void fn_8015F6C0(Obj8015F6C0* self, u32 a, u32 b, f32* vec, u32* words) {
    Link8015F6C0* link = self->link;
    if (link == 0) {
        return;
    }
    link->f178 = 1;
    self->flag16c = 1;
    link->f17c = a;
    link->f180 = b;
    if (vec != 0) {
        link->v184[0] = vec[0];
        link->v184[1] = vec[1];
        link->v184[2] = vec[2];
    } else {
        f32 z = lbl_8034AA80;
        link->v184[2] = z;
        link->v184[1] = z;
        link->v184[0] = z;
    }
    if (words != 0) {
        link->w190[0] = words[0];
        link->w190[1] = words[1];
        link->w190[2] = words[2];
    } else {
        link->w190[2] = 0;
        link->w190[1] = 0;
        link->w190[0] = 0;
    }
    fn_800A0028();
}

void fn_801600E0(void* dst_, void* src_) {
    u8* dst = dst_;
    u8* src = src_;
    *(f32*)((u8*)dst + 0x38) = *(f32*)((u8*)src + 0x38);
    *(f32*)((u8*)dst + 0x3C) = *(f32*)((u8*)src + 0x3C);
    *(f32*)((u8*)dst + 0x40) = *(f32*)((u8*)src + 0x40);
    *(u32*)((u8*)dst + 0x44) = *(u32*)((u8*)src + 0x44);
    *(u32*)((u8*)dst + 0x48) = *(u32*)((u8*)src + 0x48);
    *(u32*)((u8*)dst + 0x4C) = *(u32*)((u8*)src + 0x4C);
    *(f32*)((u8*)dst + 0x50) = *(f32*)((u8*)src + 0x50);
    *(f32*)((u8*)dst + 0x54) = *(f32*)((u8*)src + 0x54);
    *(f32*)((u8*)dst + 0x58) = *(f32*)((u8*)src + 0x58);
    *(f32*)((u8*)dst + 0x104) = *(f32*)((u8*)src + 0x104);
    *(f32*)((u8*)dst + 0x108) = *(f32*)((u8*)src + 0x108);
    *(f32*)((u8*)dst + 0x10C) = *(f32*)((u8*)src + 0x10C);
    *(u32*)((u8*)dst + 0x110) = *(u32*)((u8*)src + 0x110);
    *(u32*)((u8*)dst + 0x114) = *(u32*)((u8*)src + 0x114);
    *(u32*)((u8*)dst + 0x118) = *(u32*)((u8*)src + 0x118);
    *(f32*)((u8*)dst + 0x11C) = *(f32*)((u8*)src + 0x11C);
    *(f32*)((u8*)dst + 0x120) = *(f32*)((u8*)src + 0x120);
    *(f32*)((u8*)dst + 0x124) = *(f32*)((u8*)src + 0x124);
    *(f32*)((u8*)dst + 0xB4) = *(f32*)((u8*)src + 0xB4);
    *(f32*)((u8*)dst + 0xB8) = *(f32*)((u8*)src + 0xB8);
    *(f32*)((u8*)dst + 0xBC) = *(f32*)((u8*)src + 0xBC);
    *(u32*)((u8*)dst + 0xC0) = *(u32*)((u8*)src + 0xC0);
    *(u32*)((u8*)dst + 0xC4) = *(u32*)((u8*)src + 0xC4);
    *(u32*)((u8*)dst + 0xC8) = *(u32*)((u8*)src + 0xC8);
    *(s16*)((u8*)dst + 0x16C) = *(s16*)((u8*)src + 0x16C);
}

void fn_8016AD08(void) {
    if (lbl_80347090 != 0) {
        fn_802275A4(lbl_80347090->inner->texlist, 1);
        fn_801E17E0(lbl_80347090);
        lbl_80347090 = 0;
    }
    if (lbl_80347094 != 0) {
        fn_802275A4(lbl_80347094->inner->texlist, 1);
        fn_801E17E0(lbl_80347094);
        lbl_80347094 = 0;
    }
    if (lbl_80347098 != 0) {
        fn_802275A4(lbl_80347098->inner->texlist, 1);
        fn_801E17E0(lbl_80347098);
        lbl_80347098 = 0;
    }
    if (lbl_8034709C != 0) {
        fn_802275A4(lbl_8034709C->inner->texlist, 1);
        fn_801E17E0(lbl_8034709C);
        lbl_8034709C = 0;
    }
}

void fn_8016ADD4(s8 type) {
    char buf[0x20];
    s32 v = (type == 3) ? 2 : type;

    sprintf(buf, "/field/sora0%d.mld", v);
    switch (type) {
    case 0:
        lbl_80347090 = fn_801DB244(buf);
        fn_80227810(lbl_80347090->inner->texlist);
        break;
    case 1:
        lbl_80347094 = fn_801DB244(buf);
        fn_80227810(lbl_80347094->inner->texlist);
        break;
    case 2:
        lbl_80347098 = fn_801DB244(buf);
        fn_80227810(lbl_80347098->inner->texlist);
        break;
    case 3:
        lbl_8034709C = fn_801DB244(buf);
        fn_80227810(lbl_8034709C->inner->texlist);
        break;
    }
}

void fn_8016B434(Self_8016B434* self) {
    switch (self->state) {
    case 0:
    case 0xfe:
        fn_8016B4F0();
        self->state = 1;
        self->timer = -1.3f;
        break;
    case 1:
        if (fn_8016AEBC(self) == 0) {
            self->state = 2;
        }
        break;
    case 2:
        self->state = 0xff;
        break;
    case 0xff:
        self->flags |= 0x40;
        if (lbl_803470A0 != 0) {
            lbl_803470A0 = 0;
        }
        break;
    }
}

void fn_8016D034(s8 mode) {
    lbl_803470B8 = fn_802268E8(lbl_803475A8, fn_8016CED8);
    lbl_803470B8->sub = fn_801E1C7C(0x38);
    if (lbl_803470B8 != 0) {
        lbl_803470B8->sub->f4 = 0.0f;
        lbl_803470B8->sub->f8 = 0.0f;
    }
    if (lbl_803470B8 != 0) {
        lbl_803470B8->sub->flag1 = 1;
    }
    if (lbl_803470B8 != 0) {
        lbl_803470B8->sub->mode = mode;
    }
    switch (mode) {
    case 1:
        lbl_803470B8->sub->f30 = 1.0f;
        lbl_803470B8->sub->f2c = 1.0f;
        lbl_803470B8->sub->f34 = 0.24f;
        break;
    case 0:
        break;
    case 2:
        break;
    }
}

void fn_8016DAC4(s32* out, Wrap* p, f32 x, f32 y) {
    f32 dx = x - p->x0;
    f32 dy = y - p->y0;

    if (0.0f < p->wx) {
        if (0.0f > dx) {
            dx = p->wx + dx;
        } else if (p->wx <= dx) {
            dx -= p->wx;
        }
        if (0.0f > dy) {
            dy = p->wy + dy;
        } else if (p->wy <= dy) {
            dy -= p->wy;
        }
    }
    out[0] = (s32)fn_80291888(dx / p->sx);
    out[1] = (s32)fn_80291888(dy / p->sy);
}

void fn_8016EE2C(Self_8016EE2C* self) {
    UiObj* obj = &self->inner->obj;

    switch (self->state) {
    case 0:
    case 0xfe:
        self->state = 1;
    case 1:
        if (lbl_803475D8 != 0) {
            self->state = 0xff;
        } else {
            fn_80199F38(obj);
            UiObjCalcRect(obj);
            if (self->inner->kind == 1) {
                fn_8016EF10();
                CampPanelDrawFrame(self->inner);
            }
        }
        break;
    case 0x64:
        self->state = 0xff;
        break;
    case 0xff:
        fn_80199F58(self->inner);
        self->flags |= 0x40;
        break;
    }
}

void fn_8016F138(Self_8016F138* self) {
    UiObj* obj = &self->inner->obj;

    if (lbl_803475D8 != 0) {
        self->state = 0xff;
    }
    switch (self->state) {
    case 0:
    case 0xfe:
        self->state = 1;
    case 1:
        fn_80199F38(obj);
        UiObjCalcRect(obj);
        if (self->inner->kind == 1) {
            CampPanelDrawFrame(self->inner);
            fn_8016F594((struct Self_8016F594 *)self->inner);
        }
        break;
    case 0x64:
        self->state = 0xff;
        break;
    case 0xff:
        fn_80199F58(self->inner);
        self->flags |= 0x40;
        break;
    }
}

s32 fn_8015FBE4(Mo *m, Obj_8015FBE4 *o, f32 a, f32 b)
{
    if (m == 0) {
        o->ff0 = o->fe8;
        o->fe8 = 0;
        o->f190 = 0.0f;
        o->f19c = 1;
        o->f198 = 1;
        return 0;
    }
    {
        f32 prev = o->f190;
        o->f198 = 0;
        o->f190 = a;
        o->ff0 = o->fe8;
        o->fe8 = m;
        o->f1a0 = o->f18c;
        o->f18c = 0.0f;
        o->f1a4 = 0.0f;
        if (prev != 0.0f && o->f1a0 != 0.0f) {
            o->f19c = 0;
        } else if (o->ff0 != 0) {
            o->f19c = 0;
        } else {
            o->f19c = 1;
        }
    }
    if (0.0f > a) {
        o->f18c = (f32)o->fe8->f4 - 1.0f;
    }
    if (0.0f != b) {
        o->f1a8 = 1.0f / b;
    } else {
        o->f1a8 = 0.2f;
        o->f19c = 1;
    }
    return 1;
}

s32 fn_8015FE60(s32 idx, EvObj *o, f32 a)
{
    NJS_MOTION *m = fn_8008F8FC(o, idx);
    if (m == 0) {
        o->motion2 = o->motion;
        o->motion = 0;
        o->speed = 0.0f;
        o->x19c = 1;
        o->x198 = 1;
        return 0;
    }
    {
        f32 prev = o->speed;
        o->x198 = 0;
        o->speed = a;
        o->motion2 = o->motion;
        o->motion = m;
        o->x1a0 = o->x18c;
        o->x18c = 0.0f;
        o->x1a4 = 0.0f;
        o->x1a8 = 0.2f;
        if (prev != 0.0f && o->x1a0 != 0.0f) {
            o->x19c = 0;
        } else if (o->motion2 != 0 && m != o->motion2) {
            o->x19c = 0;
        } else {
            o->x19c = 1;
        }
    }
    if (0.0f > a) {
        o->x18c = (f32)o->motion->nbFrame - 1.0f;
    }
    return 1;
}

s32 fn_8015FF98(s32 idx, Obj_8015FF98 *o, f32 t) {
    Mot *m = fn_8008F8FC(o, idx);
    f32 old;
    if (m == 0) {
        o->prev = o->cur;
        o->cur = 0;
        o->f190 = 0.0f;
        o->f19c = 1;
        o->f198 = 1;
        return 0;
    }
    old = o->f190;
    o->f198 = 0;
    o->f190 = t;
    if (m == o->cur) {
        return 1;
    }
    o->prev = o->cur;
    o->cur = m;
    o->f1a0 = o->f18c;
    o->f18c = 0.0f;
    o->f1a4 = 0.0f;
    o->f1a8 = 0.2f;
    if (0.0f != old && 0.0f != o->f1a0) {
        o->f19c = 0;
    } else if (o->prev != 0 && m != o->prev) {
        o->f19c = 0;
    } else {
        o->f19c = 1;
    }
    if (0.0f > t) {
        o->f18c = (f32)o->cur->frames - 1.0f;
    }
    return 1;
}

s32 fn_80160954(Ent_8015EBF4 *o, Inp *in) {
    EvObj *t = o->x1d8->x8;
    if (3.4028235e38f != in->x) t->pos.x = in->x;
    if (3.4028235e38f != in->y) t->pos.y = in->y;
    if (3.4028235e38f != in->z) t->pos.z = in->z;
    if (3.4028235e38f != in->rx) t->ang[0] = (s32)(182.04445f * in->rx);
    if (3.4028235e38f != in->ry) t->ang[1] = (s32)(182.04445f * in->ry);
    if (3.4028235e38f != in->rz) t->ang[2] = (s32)(182.04445f * in->rz);
    fn_801671C0(t);
    fn_8008FFA4(&t->pos, &t->home);
    return 0;
}

#define BSW(x) ((((x) >> 24) & 0xff) | (((x) >> 8) & 0xff00) | (((x) << 8) & 0xff0000) | ((x) << 24))
Node_80167244 *fn_80167244(Node_80167244 *n, u32 id) {
    Node_80167244 *found = 0;
    if (n != 0) {
        if (n->inner != 0) {
            Rec_80167244 *r = fn_801CB5F4(n->inner->f4, 0x14, 0x17);
            if (r != 0) {
                u32 v = 0;
                switch ((u8)r->type) {
                case 0x14: v = BSW(r->w4) & 0xffffff; break;
                case 0x15: case 0x16: v = BSW(r->w8) & 0xffffff; break;
                case 0x17: v = BSW(r->wc) & 0xffffff; break;
                }
                if (v == id) found = n;
            }
        }
        if (found == 0 && n->child != 0) found = fn_80167244(n->child, id);
        if (found == 0 && n->next != 0) found = fn_80167244(n->next, id);
    }
    return found;
}

void fn_801687E0(s32 a, u8 b, u8 c, s8 d, s32 e, f32 x, f32 y, f32 z, f32 w) {
    Ent_801687E0 *en = (Ent_801687E0 *)fn_802267AC(lbl_8034759C, fn_801684E8);
    en->d = fn_801E1A74(1, 0x4c);
    en->d->f0 = 0;
    en->d->f8 = a;
    en->d->fc = b;
    en->d->fd = c;
    en->d->f18 = d;
    en->d->fe = -1;
    en->d->f10 = 1;
    en->d->f1c = x;
    en->d->f20 = y;
    en->d->f24 = z;
    en->d->f28 = w;
    en->d->ff = -0x7f;
    en->d->f2c = e;
    en->d->f30 = 0;
    en->d->f34 = ((Ent_801687E0 *)lbl_8034708C);
    if (lbl_8034708C != 0) {
        ((Ent_801687E0 *)lbl_8034708C)->d->f30 = en;
    }
    lbl_8034708C = en;
}

void fn_801694FC(s32 a, s8 b, s8 c, s32 d, f32 x, f32 y, f32 z) {
    Ent_801694FC *e = (Ent_801694FC *)fn_802267AC(lbl_8034759C, fn_80169360);
    e->d = fn_801E1A74(1, 0x4c);
    e->d->f0 = 0;
    e->d->f8 = a;
    e->d->fc = b;
    e->d->fd = c;
    e->d->f18 = d;
    e->d->fe = -1;
    e->d->f10 = 0;
    e->d->f1c = x;
    e->d->f20 = y;
    e->d->f24 = z;
    e->d->f2c = 0;
    e->d->f30 = 0;
    e->d->f34 = ((Ent_801694FC *)lbl_8034708C);
    if (lbl_8034708C != 0) {
        ((Ent_801694FC *)lbl_8034708C)->d->f30 = e;
    }
    lbl_8034708C = e;
}

u32 fn_8016A914(s32 base, u32 amount, Curve *c) {
    f32 t;
    if (lbl_80347450 == 0) {
        return 0;
    }
    t = 60.0f + (((Clk*)lbl_80347450)->t - (f32)base);
    if (t < c->f4c) {
        return 0;
    }
    if (t > c->f40) {
        return 0;
    }
    if (t < c->f48) {
        return (u32)((f32)amount * ((t - c->f4c) / (c->f48 - c->f4c)));
    }
    if (t > c->f44) {
        return (u32)((f32)amount * ((t - c->f40) / (c->f44 - c->f40)));
    }
    return amount;
}

void fn_8016B4F0(void) {
    u8 *base = lbl_802E7160;
    ((OwnerA_8016B4F0*)lbl_803470A0)->tbl = fn_801E1C7C(12);
    switch (((OwnerA_8016B4F0*)lbl_803470A0)->inner->mode) {
    case 0:
        ((OwnerA_8016B4F0*)lbl_803470A0)->tbl[0] = &base[0x2c0];
        ((OwnerA_8016B4F0*)lbl_803470A0)->tbl[1] = &base[0x310];
        ((OwnerA_8016B4F0*)lbl_803470A0)->tbl[2] = &base[0x360];
        break;
    case 1:
        ((OwnerA_8016B4F0*)lbl_803470A0)->tbl[0] = &base[0x9d4];
        ((OwnerA_8016B4F0*)lbl_803470A0)->tbl[1] = &base[0xa24];
        ((OwnerA_8016B4F0*)lbl_803470A0)->tbl[2] = &base[0xa74];
        break;
    case 2:
        ((OwnerA_8016B4F0*)lbl_803470A0)->tbl[0] = &base[0x173c];
        ((OwnerA_8016B4F0*)lbl_803470A0)->tbl[1] = &base[0x178c];
        ((OwnerA_8016B4F0*)lbl_803470A0)->tbl[2] = &base[0x17dc];
        break;
    case 3:
        ((OwnerA_8016B4F0*)lbl_803470A0)->tbl[0] = &base[0x1c68];
        ((OwnerA_8016B4F0*)lbl_803470A0)->tbl[1] = &base[0x1cb8];
        ((OwnerA_8016B4F0*)lbl_803470A0)->tbl[2] = &base[0x1d08];
        break;
    }
}

void fn_8016E878(PanelA *p) {
    p->x = -6340.0f;
    p->y = 0.0f;
    p->a = 1.0f;
    p->b = 0.0f;
    p->c = 1.0f;
    p->d = 0.0f;
    p->z0 = 0;
    p->z1 = 0;
    fn_8019A15C(p, 1, 1, 1);
    *p->s0 = fn_801D68C4(lbl_803470F0, 10);
    p->p0[0] = 0.0f;
    p->p0[1] = 0.0f;
    *p->s1 = fn_801D68C4(lbl_803470E8, 2);
    p->p1[0] = 0.0f;
    p->p1[1] = 0.0f;
    *p->s2 = fn_801D68C4(lbl_803470F4, 0x3a);
    p->p2[0] = 12.0f;
    p->p2[1] = 42.0f;
    p->s3 = fn_801D68C4(lbl_803470F0, 4);
}

void fn_8016E96C(PanelA *p) {
    p->x = -6190.0f;
    p->y = 0.0f;
    p->a = 1.0f;
    p->b = 0.0f;
    p->c = 1.0f;
    p->d = 0.0f;
    p->z0 = 0;
    p->z1 = 0;
    fn_8019A15C(p, 1, 1, 1);
    *p->s0 = fn_801D68C4(lbl_803470F0, 7);
    p->p0[0] = 0.0f;
    p->p0[1] = 0.0f;
    *p->s1 = fn_801D68C4(lbl_803470E8, 1);
    p->p1[0] = 0.0f;
    p->p1[1] = 0.0f;
    *p->s2 = fn_801D68C4(lbl_803470F4, 0);
    p->p2[0] = 85.0f;
    p->p2[1] = 29.0f;
    p->s3 = fn_801D68C4(lbl_803470F0, 1);
}

void fn_8016EB4C(PanelA *p) {
    p->x = -6190.0f;
    p->y = 0.0f;
    p->a = 1.0f;
    p->b = 0.0f;
    p->c = 1.0f;
    p->d = 0.0f;
    p->z0 = 0;
    p->z1 = 0;
    fn_8019A15C(p, 1, 1, 1);
    fn_80199FFC(p, 0, fn_801D68C4(lbl_803470F4, 0x36), 0x10, 0x1f, 2);
    *p->s1 = fn_801D68C4(lbl_803470E8, 2);
    p->p1[0] = 0.0f;
    p->p1[1] = 0.0f;
    *p->s0 = fn_801D68C4(lbl_803470F0, 10);
    p->p0[0] = 0.0f;
    p->p0[1] = 0.0f;
    p->s3 = fn_801D68C4(lbl_803470F0, 1);
}

void fn_8016F594(Self_8016F594 *self) {
    s32 x = (s32)self->x;
    s32 y = (s32)self->y;
    u8 *d = self->data;
    f32 savez = TextGetZ();
    s8 type;
    char *str;
    s32 dx, dy;
    TextPushColor();
    TextSetColor(0xff201008);
    TextSetZ(10.0f + self->z);
    type = d[1];
    str = lbl_802E8FD0[type];
    if (type == 14 || type == 15) {
        dx = 0x5a;
        dy = 0x11;
    } else if (type == 18) {
        dx = 0x6c;
        dy = 0x11;
    } else {
        dx = 0x74;
        dy = 0x11;
    }
    TextPrint(x + dx, y + dy, str);
    TextPopColor(1);
    TextSetZ(savez);
}

void fn_8015E314(Ent *self) {
    s16 st;
    Hold *h = self->x1d8;
    Obj *o;
    if (!(h->flags & 0x10)) {
        return;
    }
    st = h->hE;
    o = h->x8;
    if (st == 0) {
        return;
    }
    switch (st) {
    case 0:
        if (o != 0) {
            o->x1c = 0.0f;
        } else {
            self->x1c = 0.0f;
        }
        h->hE = 4;
        break;
    case 2:
        if (o != 0) {
            if (o->x1c > -1.0f) {
                o->x1c -= 0.04f;
            } else {
                h->hE = 3;
            }
        } else {
            if (self->x1c > -1.0f) {
                self->x1c -= 0.04f;
            } else {
                h->hE = 3;
            }
        }
        break;
    case 1:
        if (o != 0) {
            if (o->x1c < 0.0f) {
                o->x1c += 0.04f;
            } else {
                h->hE = 0;
            }
        } else {
            if (self->x1c < 0.0f) {
                self->x1c += 0.04f;
            } else {
                h->hE = 0;
            }
        }
        break;
    case 3:
        if (o != 0) {
            o->x1c = -1.0f;
        } else {
            self->x1c = -1.0f;
        }
        h->hE = 4;
        break;
    case 4:
        break;
    }
}

void fn_8015EBF4(Ent_8015EBF4 *self) {
    extern void fn_801601AC(Ent_8015EBF4 *e);
    extern V3 *fn_8016748C(Ent_8015EBF4 *e, s32 a);
    extern void fn_801E1784(void *p);
    extern void fn_802275A4(void *p, s32 a);
    extern void fn_80210D7C(s32 a);
    extern s32 fn_801F6EC8(s32 a);
    Hold_8015EB8C *h = self->x1d8;
    void *o;
    V3 *p;
    s32 r;
    if (h != 0) {
        o = h->x8;
        fn_801601AC(self);
        if (h->x84 != 0 && h->x84->next != 0) {
            h->x84->next->x14 = h->x48;
            h->x84->next->x18 = h->x4c;
            h->x84->next->x1c = h->x50;
        }
        h->x5c = 0;
        h->x58 = 0;
        h->x54 = 0;
        h->x12c = 0;
        h->xe0 = 0;
        h->x94 = 0;
        if (h->x78.a != 0 && h->x74 != 0) {
            p = fn_8016748C(self, h->x74);
            *p = h->x78;
        }
        if (h->cb13 != 0 && o != 0) {
            h->cb13(h->task, o);
        }
        if (h->x8 != 0) {
            fn_801E1784(h->x8);
            h->x8 = 0;
        }
        if (self->x1d8 != 0 && self->x1c8 != 0 && self->x1c8->x20 != 0) {
            fn_802275A4(self->x1c8->x20, 0);
        }
        if (self->x1d8 != 0) {
            fn_801E1784(self->x1d8);
            self->x1d8 = 0;
        }
        fn_80210D7C(self->h17a);
        r = (s16)fn_801F6EC8(self->h17a);
        if (r != -1) {
            lbl_8030CEA0.ent[r][0] = 0;
        }
        self->x1d4 = 0;
    }
}

s32 fn_8015FCF8(s32 i, Obj_8015FCF8 *o, f32 a, f32 b) {
    extern Mo_8015FCF8 *fn_8008F8FC(Obj_8015FCF8 *o, s32 i);
    Mo_8015FCF8 *t = fn_8008F8FC(o, i);
    f32 old;
    if (t == 0) {
        o->xf0 = o->xe8;
        o->xe8 = 0;
        o->x190 = 0.0f;
        o->x19c = 1;
        o->x198 = 1;
        return 0;
    }
    old = o->x190;
    o->x198 = 0;
    o->x190 = a;
    o->xf0 = o->xe8;
    o->xe8 = t;
    o->x1a0 = o->x18c;
    o->x18c = 0.0f;
    o->x1a4 = 0.0f;
    if (0.0f != old && 0.0f != o->x1a0) {
        o->x19c = 0;
    } else if (o->xf0 != 0) {
        o->x19c = 0;
    } else {
        o->x19c = 1;
    }
    if (0.0f > a) {
        o->x18c = (f32)o->xe8->x4 - 1.0f;
    }
    if (0.0f != b) {
        o->x1a8 = 1.0f / b;
    } else {
        o->x1a8 = 0.2f;
        o->x19c = 1;
    }
    return 1;
}

s32 fn_80160424(f32 x, Spl *sp, void *b, void *c) {
    u32 n;
    u32 k;
    u32 i;
    if (x < 0.0f) {
        return -1;
    }
    if (sp == 0) {
        return -1;
    }
    n = sp->count - 1;
    k = 0;
    for (i = 0; i < n; i++) {
        if (x <= sp->x8[i]) {
            break;
        }
        k++;
        x -= sp->x8[i];
    }
    if (k >= n) {
        return -1;
    }
    x = fn_80212A78(c, x, sp->x8[k]);
    fn_80213178(x, sp->x8[k], sp->xc[k], sp->x10[k].a, sp->x10[k].b, sp->xc[k + 1], b);
    return k;
}

s32 fn_801650C4(Ent_801650C4 *self, Arg_801650C4 *a) {
    extern s32 fn_8015FE60(s32 a, Obj_801650C4 *o, f32 inv);
    extern void *fn_8008F8FC(Obj_801650C4 *o, s32 i);
    Obj_801650C4 *o;
    Hold_801650C4 *h;
    f32 s = a->x24;
    void *t;
    h = self->x1d8;
    o = h->x8;
    if (3.4028235e38f == s) {
        s = 1.0f;
    }
    if (0.0f == s) {
        return 0;
    }
    s = 1.0f / s;
    o->h172 = (a->x1c == 0x7fffffff) ? 0 : a->x1c;
    if (a->x1c == -1) {
        o->xf0 = o->xe8;
        o->x1a0 = o->x18c;
        o->xe8 = 0;
        o->x18c = 0.0f;
        o->x190 = 0.0f;
        o->x19c = 1;
        o->x198 = 1;
        o->h172 = 0;
        return 0;
    }
    if (fn_8015FE60(o->h172, o, s) == 0) {
        o->x190 = 0.0f;
        return 0;
    }
    if (a->x20 == 0x7fffffff) {
        o->xf4 = o->xec;
        o->xec = 0;
    } else {
        t = fn_8008F8FC(o, a->x20);
        if (t != o->xec) {
            o->xf4 = o->xec;
            o->xec = t;
        }
    }
    h->x90 = o->xe8;
    return 0;
}

void fn_80165C84(Spl *sp) {
    s32 i;
    s32 j;
    s32 k;
    if (sp != 0) {
        if (sp->count != 0) {
            if (sp->xc[0] != 0) {
                fn_801E1784(sp->xc[0]);
                sp->xc[0] = 0;
            }
            j = 0;
            i = 0;
            k = 0;
            for (; i < sp->count - 1; i++) {
                if (sp->xc[k + 1] != 0) {
                    fn_801E1784(sp->xc[k + 1]);
                    sp->xc[k + 1] = 0;
                }
                if (sp->x10[j].a != 0) {
                    fn_801E1784(sp->x10[j].a);
                    sp->x10[j].a = 0;
                }
                if (sp->x10[j].b != 0) {
                    fn_801E1784(sp->x10[j].b);
                    sp->x10[j].b = 0;
                }
                k++;
                j++;
            }
            if (sp->xc != 0) {
                fn_801E1784(sp->xc);
                sp->xc = 0;
            }
            if (sp->x10 != 0) {
                fn_801E1784(sp->x10);
                sp->x10 = 0;
            }
            if (sp->x8 != 0) {
                fn_801E1784(sp->x8);
                sp->x8 = 0;
            }
        }
        if (sp != 0) {
            fn_801E1784(sp);
        }
    }
}

static inline s32 chk(Ent_8016679C *o, Arg_8016679C *a) {
    Hold_8016679C *s = o->x1d8;
    if (s && a && a->x20 && a->x1c && a->x1c > (u32)(s32)s->h1a) {
        return 1;
    }
    return 0;
}

void fn_8016679C(Ent_8016679C *self, Arg_8016679C *a) {
    Obj_8016679C *o = self->x1d8->x8;
    Key *e;
    V3i w;
    Vec q;
    Vec v;
    if (!chk(self, a)) {
        o->p5c.z = 0.0f;
        o->p5c.y = 0.0f;
        o->p5c.x = 0.0f;
        {
            f32 x = o->p38.x;
            f32 y = o->p38.y;
            f32 z = o->p38.z;
            o->p104.z = z;
            o->p104.y = y;
            o->p104.x = x;
        }
        return;
    }
    e = a->x20 + self->x1d8->h1a;
    if (e->x28 != 0x7fffffff && o != 0 && o->x1b8 != 0) {
        fn_802256A0(&o->p38, o->x1b8, 0xffff, e->x28);
    }
    o->p104.x = e->p0.x;
    o->p104.y = e->p0.y;
    o->p104.z = e->p0.z;
    if (1.17549435e-38f == e->p0.y) {
        o->p104.y = o->p38.y;
    }
    if (&o->p38 != 0 && &o->p104 != 0) {
        v.x = o->p104.x - o->p38.x;
        v.y = o->p104.y - o->p38.y;
        v.z = o->p104.z - o->p38.z;
        fn_802135B4(&v, &w);
    }
    o->x164 = e->x18;
    lbl_802E70C8[2] = o->x164;
    fn_802136A8(lbl_802E70C8, &q, w.a, w.b, w.c);
    o->p5c.x = q.x;
    o->p5c.y = q.y;
    o->p5c.z = q.z;
}

void fn_80168398(s32 a, u8 b, u8 c, s32 d, s32 e, s32 f, f32 f1, f32 f2, f32 f3, f32 f4) {
    Obj_80168398* obj = fn_802267AC(lbl_8034759C, fn_801680B4);
    obj->sub = fn_801E1A74(1, 0x4c);
    obj->sub->w0 = 0;
    obj->sub->w8 = a;
    obj->sub->bC = b;
    obj->sub->bD = c;
    obj->sub->bE = -1;
    obj->sub->h10 = 0;
    obj->sub->flags = d & 0xff;
    obj->sub->flags |= (f & 0xff) << 8;
    obj->sub->flags |= e << 16;
    obj->sub->f1c = f1;
    obj->sub->f20 = f2;
    obj->sub->f24 = f3;
    obj->sub->f28 = f4;
    obj->sub->bF = -0x7f;
    obj->sub->w2c = 0;
    obj->sub->w30 = 0;
    obj->sub->w34 = (*(Obj_80168398**)&lbl_8034708C);
    if ((*(Obj_80168398**)&lbl_8034708C) != 0) {
        (*(Obj_80168398**)&lbl_8034708C)->sub->w30 = obj;
    }
    (*(Obj_80168398**)&lbl_8034708C) = obj;
}

void fn_80169144(s32 a, u8 b, u8 c, s8 d, s32 e, s32 f, f32 f1, f32 f2, f32 f3, f32 f4) {
    Obj_80169144* obj = fn_802267AC((*(void**)&lbl_8034759C), (void*)fn_80168E54);
    obj->sub = fn_801E1A74(1, 0x4c);
    obj->sub->w0 = 0;
    obj->sub->w8 = a;
    obj->sub->bC = b;
    obj->sub->bD = c;
    obj->sub->flags = d;
    obj->sub->flags |= (f & 0xff) << 8;
    obj->sub->flags |= e << 16;
    obj->sub->bE = -1;
    obj->sub->h10 = 0;
    obj->sub->f1c = f1;
    obj->sub->f20 = f2;
    obj->sub->f24 = f3;
    obj->sub->f28 = f4;
    obj->sub->bF = -0x7f;
    obj->sub->w2c = 0;
    obj->sub->w30 = 0;
    obj->sub->w34 = (*(Obj_80169144**)&lbl_8034708C);
    if ((*(Obj_80169144**)&lbl_8034708C) != 0) {
        (*(Obj_80169144**)&lbl_8034708C)->sub->w30 = obj;
    }
    (*(Obj_80169144**)&lbl_8034708C) = obj;
}

void fn_8016E52C(Obj_8016E52C* o) {
    s16 x = o->x;
    s16 y = o->y;
    Info_8016E52C* info = o->info;
    f32 oz;
    f32 f;
    f = o->f3c;
    oz = TextGetZ();
    TextSetZ(10.0f + o->z);
    TextPushColor();
    TextSetColor(0xff201008);
    if (info->idx != -1) {
        Spr_8016E52C* spr = lbl_802E8F74[info->idx];
        spr->x = x + 16;
        spr->y = y - 2;
        fn_801D51C4(spr, 0, 0, 20.0f + o->z, 0.0f, f, 1.0f);
        TextPrint(x + 0x60, y + 0x1e, fn_80194C50(info->idx));
        fn_80194C18(info->idx);
        TextPrint(x + 0x54, y + 6, fn_80194C00());
        TextPrint(x + 0xc0, y + 6, lbl_802E8F60[fn_80194B18(info->idx)]);
    }
    TextPopColor(1);
    TextSetZ(oz);
}

void fn_80170450(void) {
    CampCtrl* c = lbl_8034710C->holder->ctrl;

    switch (c->state) {
    case 0:
        fn_80170704(c->cur[4].sel, 1);
        c->state++;
        break;
    case 1:
        if (CampMenuAnyPanelBusy() == 0) {
            fn_801705B8();
            c->state++;
        } else if (fn_801C09F8(lbl_80347154, 0x11) != 0 || fn_801C09F8(lbl_80347154, 0x10) != 0) {
            CampMenuFinishAllPanels();
            fn_801705B8();
            c->state++;
        }
        break;
    case 2:
        fn_80170704(c->cur[4].sel, 0);
        c->state++;
        break;
    case 3:
        if (CampMenuAnyPanelBusy() == 0) {
            c->state++;
        } else if (fn_801C09F8(lbl_80347154, 0x11) != 0 || fn_801C09F8(lbl_80347154, 0x10) != 0) {
            CampMenuFinishAllPanels();
            c->state++;
        }
        break;
    case 4:
        c->state = 0;
        c->cur[6].mask = 2;
        break;
    }
}

void fn_8016C61C(void) {
    if (lbl_803470B0 != 0) {
        lbl_803470B0->sub->f4 = 0.0f;
        lbl_803470B0->sub->f8 = 0.0f;
    }
    if (lbl_803470B0 != 0) {
        lbl_803470B0->sub->w24 = 0;
    }
    if (lbl_803470B0 != 0) {
        lbl_803470B0->sub->w28 = 0;
    }
    if (lbl_803470B0 != 0) {
        lbl_803470B0->sub->w2c = 0;
    }
    if (lbl_803470B0 != 0) {
        lbl_803470B0->sub->w30 = 0;
    }
    if (lbl_803470B0 != 0) {
        lbl_803470B0->sub->w34 = 0;
    }
    if (lbl_803470B0 != 0) {
        lbl_803470B0->sub->w20 = 0;
    }
    if (lbl_803470B0 != 0) {
        lbl_803470B0->sub->w3c = 0;
    }
    if (lbl_803470B0 != 0) {
        lbl_803470B0->sub->w40 = 0;
    }
    if (lbl_803470B0 != 0) {
        lbl_803470B0->sub->w44 = 0;
    }
    if (lbl_803470B0 != 0) {
        lbl_803470B0->sub->w48 = 0;
    }
    if (lbl_803470B0 != 0) {
        lbl_803470B0->sub->w4c = 0;
    }
    if (lbl_803470B0 != 0) {
        lbl_803470B0->sub->w38 = 0;
    }
    lbl_803470B0->sub->b3 = 10;
    lbl_803470B0->sub->b2 = 10;
}

void fn_8016022C(Obj_8016022C *obj, Arg_8016022C *arg)
{
    extern s32 fn_8015FF98(s32 idx, Inner_8016022C *o, f32 t);
    extern u32 fn_8008F8FC(Inner_8016022C *o, s32 i);
    extern s32 fn_8016645C(Inner_8016022C *o, Arg_8016022C *a);
    extern void fn_80167034(Inner_8016022C *o, s32 *p, s32 n, void *q);
    extern void fn_8016694C(f32 *a, Vec_8016022C *v, s32 *out);
    extern f32 fn_80291A5C(f32 x);
    extern s32 fn_80166D40(s32 *a, s32 *b);
    St_8016022C *st = obj->st;
    Inner_8016022C *in = st->inner;
    Ent_8016022C *e = arg->ents + st->h1a;
    f32 s;
    f32 len;
    u32 m;
    Vec_8016022C v;

    if (obj != 0) {
        if (3.4028235e38f == e->x24) {
            s = 1.0f;
        } else {
            s = e->x24;
        }
        if (s != 0.0f) {
            s = 1.0f / s;
        }
        if (e->x1c == 0x7fffffff) {
            fn_8015FF98(0xff, in, s);
        } else {
            fn_8015FF98(e->x1c, in, s);
        }
        if (e->x20 == 0x7fffffff) {
            in->xf4 = in->xec;
            in->xec = 0;
        } else {
            m = fn_8008F8FC(in, e->x20);
            if (m != in->xec) {
                in->xf4 = in->xec;
                in->xec = m;
            }
        }
        if (fn_8016645C(in, arg) == 0) {
            fn_80167034(in, &in->x44, 1, st->x20);
        } else {
            v.x = e->x0;
            v.y = e->x4;
            v.z = e->x8;
            if (1.17549435e-38f == e->x4) {
                v.y = in->x3c;
            }
            fn_8016694C(&in->x38, &v, &in->x110);
            if (lbl_80311AC0.f4 != 0x1c || lbl_80311AC0.f8 != 0x62) {
                in->x110 = in->x44;
                in->x118 = in->x4c;
                in->x70 = 0;
                in->x68 = 0;
            }
            len = fn_80291A5C(e->x18);
            fn_80167034(in, &in->x110, (s32)((f32)fn_80166D40(&in->x44, &in->x110) / len), st->x20);
        }
    }
}

s32 fn_80161FDC(Obj_80161FDC *obj, Arg_80161FDC *arg)
{
    extern void *fn_8010A164(u16 id);
    extern void fn_800A0028(void *self);
    St_80161FDC *st = obj->st;
    Inner_80161FDC *in = st->inner;
    f32 t;

    if (arg->h18 != 0xffff && fn_8010A164(arg->h18) == 0) {
        return 0;
    }
    st->x178 = 1;
    st->x17c = 0;
    st->x17c |= arg->h18;
    st->x180 = arg->x1c;
    t = arg->x20;
    if (3.4028235e38f == t) {
        t = 0.0f;
    }
    st->x184 = t;
    t = arg->x24;
    if (3.4028235e38f == t) {
        t = 0.0f;
    }
    st->x188 = t;
    t = arg->x28;
    if (3.4028235e38f == t) {
        t = 0.0f;
    }
    st->x18c = t;
    if (3.4028235e38f == arg->x2c) {
        t = 0.0f;
    } else {
        t = (s32)(182.04445f * arg->x2c);
    }
    st->x190 = t;
    if (3.4028235e38f == arg->x30) {
        t = 0.0f;
    } else {
        t = (s32)(182.04445f * arg->x30);
    }
    st->x194 = t;
    if (3.4028235e38f == arg->x34) {
        t = 0.0f;
    } else {
        t = (s32)(182.04445f * arg->x34);
    }
    st->x198 = t;
    in->h16c = 1;
    fn_800A0028(obj);
    return 0;
}

static inline s32 Busy_80164748(St_80164748 *st)
{
    s32 r;
    if (st == 0) {
        return 0;
    }
    r = 0;
    if (st->x178 == 1 || st->x178 == 3) {
        r = 1;
    }
    return r != 0;
}

s32 fn_80164748(Obj_80164748 *obj, Arg_80164748 *arg)
{
    extern s32 fn_8015FF98(s32 idx, Inner_80164748 *o, f32 t);
    extern u32 fn_8008F8FC(Inner_80164748 *o, s32 i);
    extern void fn_80167034(Inner_80164748 *o, s32 *p, s32 n, void *q);
    extern s32 fn_80166EC4(Inner_80164748 *o, f32 t);
    extern void fn_801600E0(Obj_80164748 *o, Inner_80164748 *in);
    St_80164748 *st = obj->st;
    Inner_80164748 *in = st->inner;
    s32 px, py, pz;
    f32 s;
    u32 m;

    if (Busy_80164748(st) != 0) {
        return 0;
    }
    switch (in->h168) {
    case 0:
        in->x110 = 182.04445f * arg->x1c;
        in->x114 = 182.04445f * arg->x20;
        in->x118 = 182.04445f * arg->x24;
        fn_80167034(in, &in->x110, arg->x28, &st->x20);
        in->x20c = in->x110;
        in->x210 = in->x114;
        in->x214 = in->x118;
        s = arg->x34;
        if (3.4028235e38f == s) {
            s = 1.0f;
        }
        if (0.0f != s) {
            s = 1.0f / s;
        }
        if (arg->x2c == 0xffffffff) {
            in->xf0 = in->xe8;
            in->x1a0 = in->x18c;
            in->xe8 = 0;
            in->x18c = 0.0f;
            in->x190 = 0.0f;
            in->x19c = 1;
            in->x198 = 1;
        } else if (arg->x2c == 0x7fffffff) {
            fn_8015FF98(0xff, in, s);
        } else {
            fn_8015FF98(arg->x2c, in, s);
        }
        if (arg->x30 == 0x7fffffff) {
            in->xf4 = in->xec;
            in->xec = 0;
        } else {
            m = fn_8008F8FC(in, arg->x30);
            if (m != in->xec) {
                in->xf4 = in->xec;
                in->xec = m;
            }
        }
        in->h168 = 2;
    case 1:
    case 2:
        in->x104 = in->x38;
        in->x108 = in->x3c;
        in->x10c = in->x40;
        px = in->x44;
        py = in->x48;
        pz = in->x4c;
        in->x110 = in->x20c;
        in->x114 = in->x210;
        in->x118 = in->x214;
        if (fn_80166EC4(in, st->x20) != 0) {
            in->x110 = px;
            in->x114 = py;
            in->x118 = pz;
            fn_801600E0(obj, in);
            return 0;
        }
        break;
    }
    in->x110 = px;
    in->x114 = py;
    in->x118 = pz;
    fn_801600E0(obj, in);
    return 1;
}

void fn_8016CAB4(void) {
    Arg_8016CAB4 a;
    s32 i;
    for (i = 0; i < 5; i++) {
        f32 x, y;
        Mat_8016CAB4* m;
        a.item = (*(Obj_8016CAB4**)&lbl_803470B8)->items[i];
        x = a.item->x;
        y = a.item->y;
        if (i == 3) {
            a.item->x = (*(Obj_8016CAB4**)&lbl_803470B8)->st->f20 + ((*(Obj_8016CAB4**)&lbl_803470B8)->st->mv.x + x);
        } else {
            a.item->x = (*(Obj_8016CAB4**)&lbl_803470B8)->st->mv.x + x;
        }
        a.item->y = (*(Obj_8016CAB4**)&lbl_803470B8)->st->mv.y + (*(Obj_8016CAB4**)&lbl_803470B8)->items[i]->y;
        a.a = 0.01f * (f32)i + -1.3f;
        a.b = 1.0f;
        a.c = 0;
        a.d = 0;
        if (i == 1) {
            a.e = (*(Obj_8016CAB4**)&lbl_803470B8)->st->f2c;
            a.f = 1.0f;
        } else if (i == 2) {
            a.e = 1.0f;
            a.f = (*(Obj_8016CAB4**)&lbl_803470B8)->st->f34;
            m = a.item->mat;
            m->word &= 0xFFFFFF;
            m->word |= (s32)(255.0f * (*(Obj_8016CAB4**)&lbl_803470B8)->st->f34) << 24;
        } else {
            a.e = 1.0f;
            a.f = 1.0f;
        }
        switch ((*(Obj_8016CAB4**)&lbl_803470B8)->st->kind) {
        case 1:
            fn_8016AB44(&a);
            break;
        case 0:
            break;
        case 2:
            break;
        }
        a.item->x = x;
        a.item->y = y;
    }
}

void fn_8016E220(Self_8016E220* self) {
    extern void fn_80199F38(UiObj* ui);
    extern void fn_80199F58(Work_8016E220* w);
    extern void CampPanelDrawFrame(void);
    extern void fn_8016E6E8(Work_8016E220* w);
    extern void fn_8016E52C(Work_8016E220* w);
    extern void fn_8016E3E0(Work_8016E220* w);
    extern char* fn_80193F80(void);
    f32 z;
    s32 y, x;
    Sub_8016E220* sub = self->work->sub;
    Work_8016E220* w2;
    UiObj* ui = &self->work->ui;
    if (lbl_803475D8 != 0) {
        self->stage = 0xFF;
    }
    switch (self->stage) {
    case 0:
    case 0xFE:
        self->stage = 1;
    case 1:
        fn_80199F38(ui);
        UiObjCalcRect(ui);
        if (self->work->mode == 1) {
            CampPanelDrawFrame();
            switch (sub->page) {
            case 0:
                fn_8016E6E8(self->work);
                break;
            case 1:
                fn_8016E52C(self->work);
                break;
            case 2:
                fn_8016E3E0(self->work);
                break;
            case 3: {
                w2 = self->work;
                x = (s32)w2->ui.rect[0];
                y = (s32)w2->ui.rect[1];
                z = TextGetZ();
                TextSetZ(10.0f + w2->f74);
                TextPushColor();
                TextSetColor(0xFF201008);
                TextPrint(x + 0x10, y + 0x11, fn_80193F80());
                TextPopColor(1);
                TextSetZ(z);
                break;
            }
            }
        }
        break;
    case 0x64:
        self->stage = 0xFF;
        break;
    case 0xFF:
        fn_80199F58(self->work);
        self->flags |= 0x40;
        break;
    }
}

void fn_8016EC3C(Obj_8016EC3C* o, s8 kind, s8 idx, f32 f) {
    extern void* fn_801D68C4(void* p, s32 id);
    extern void fn_8019A15C(Obj_8016EC3C* o, s8 a, s8 b, s8 c);
    void* r;
    o->x = -7990.0f + 150.0f * (f32)idx;
    o->y = 0.0f;
    o->f10 = 0.7f;
    o->f14 = f;
    o->f18 = 1.0f;
    o->f1c = 0.0f;
    o->i8 = 0;
    o->ic = 0;
    fn_8019A15C(o, 2, 1, 1);
    o->h20[0] = fn_801D68C4(lbl_803470F0, 7);
    o->p24[0] = 0.0f;
    o->p24[1] = 0.0f;
    switch (kind) {
    case 0:
        r = fn_801D68C4(lbl_803470F0, 0xB);
        break;
    case 1:
        r = fn_801D68C4(lbl_803470F0, 0xC);
        break;
    case 2:
        r = fn_801D68C4(lbl_803470F0, 0xD);
        break;
    case 3:
        r = fn_801D68C4(lbl_803470F0, 0xE);
        break;
    case 4:
        r = fn_801D68C4(lbl_803470F0, 0xF);
        break;
    case 5:
        r = fn_801D68C4(lbl_803470F0, 0x10);
        break;
    default:
        r = fn_801D68C4(lbl_803470F0, 0xB);
        break;
    }
    o->h20[1] = r;
    o->p24[2] = 24.0f;
    o->p24[3] = -2.0f;
    o->h2c[0] = fn_801D68C4(lbl_803470E8, 1);
    o->p30[0] = 0.0f;
    o->p30[1] = 0.0f;
    o->h38[0] = fn_801D68C4(lbl_803470F4, 0);
    o->p3c[0] = 85.0f;
    o->p3c[1] = 29.0f;
    o->h44 = fn_801D68C4(lbl_803470F0, 1);
}

#define FLAG(b) ((lbl_80310B3C[(b) >> 5] & (1 << ((b) & 31))) != 0)

void fn_8016C2C0(void) {
    (*(Obj_8016C2C0**)&lbl_803470B0)->tbl = fn_801E1C7C(0x14);
    switch (*(*(Obj_8016C2C0**)&lbl_803470B0)->kind) {
    case 0:
        (*(Obj_8016C2C0**)&lbl_803470B0)->tbl->p0 = lbl_802E725C;
        (*(Obj_8016C2C0**)&lbl_803470B0)->tbl->p4 = lbl_802E72AC;
        (*(Obj_8016C2C0**)&lbl_803470B0)->tbl->p8 = lbl_802E72FC;
        (*(Obj_8016C2C0**)&lbl_803470B0)->tbl->pc = lbl_802E734C;
        (*(Obj_8016C2C0**)&lbl_803470B0)->tbl->p10 = lbl_802E739C;
        break;
    case 1:
        (*(Obj_8016C2C0**)&lbl_803470B0)->tbl->p0 = lbl_802E7970;
        (*(Obj_8016C2C0**)&lbl_803470B0)->tbl->p4 = lbl_802E79C0;
        (*(Obj_8016C2C0**)&lbl_803470B0)->tbl->p8 = lbl_802E7A10;
        (*(Obj_8016C2C0**)&lbl_803470B0)->tbl->pc = lbl_802E7A60;
        (*(Obj_8016C2C0**)&lbl_803470B0)->tbl->p10 = lbl_802E7AB0;
        break;
    case 2:
        (*(Obj_8016C2C0**)&lbl_803470B0)->tbl->p0 = lbl_802E863C;
        (*(Obj_8016C2C0**)&lbl_803470B0)->tbl->p4 = lbl_802E868C;
        (*(Obj_8016C2C0**)&lbl_803470B0)->tbl->p8 = lbl_802E86DC;
        (*(Obj_8016C2C0**)&lbl_803470B0)->tbl->pc = lbl_802E872C;
        (*(Obj_8016C2C0**)&lbl_803470B0)->tbl->p10 = lbl_802E877C;
        break;
    case 3:
        (*(Obj_8016C2C0**)&lbl_803470B0)->tbl->p0 = lbl_802E8ACC;
        (*(Obj_8016C2C0**)&lbl_803470B0)->tbl->p4 = lbl_802E8B1C;
        (*(Obj_8016C2C0**)&lbl_803470B0)->tbl->p8 = lbl_802E8B6C;
        (*(Obj_8016C2C0**)&lbl_803470B0)->tbl->pc = lbl_802E8BBC;
        (*(Obj_8016C2C0**)&lbl_803470B0)->tbl->p10 = lbl_802E8C0C;
        break;
    }
}

void fn_8016C4C8(s8 mode) {
    lbl_803470B0 = fn_802268E8(lbl_803475A8, fn_8016C204);
    lbl_803470B0->sub = fn_801E1C7C(0x50);
    fn_8016C61C();
    if (lbl_803470B0 != 0) {
        lbl_803470B0->sub->b1 = 1;
    }
    if (lbl_803470B0 != 0) {
        lbl_803470B0->sub->kind = mode;
    }
    switch (mode) {
    case 0:
    case 1:
    case 2:
    case 3:
        if (lbl_803470B0 != 0) {
            lbl_803470B0->sub->w24 = 0;
        }
        if (lbl_803470B0 != 0) {
            lbl_803470B0->sub->w20 = 0;
        }
        if (lbl_803470B0 != 0) {
            lbl_803470B0->sub->w30 = 360;
        }
        if (lbl_803470B0 != 0) {
            lbl_803470B0->sub->w28 = 50;
        }
        if (lbl_803470B0 != 0) {
            lbl_803470B0->sub->w3c = 0;
        }
        if (lbl_803470B0 != 0) {
            lbl_803470B0->sub->w38 = 0;
        }
        if (lbl_803470B0 != 0) {
            lbl_803470B0->sub->w48 = 700;
        }
        if (lbl_803470B0 != 0) {
            lbl_803470B0->sub->w40 = 75;
        }
    }
}

void fn_8016E3E0(Obj_8016E3E0* o) {
    s16 x = o->x;
    s16 y = o->y;
    Spr_8016E52C* s;
    f32 oz;
    f32 f;
    f = o->f3c;
    oz = TextGetZ();
    TextSetZ(10.0f + o->z);
    TextPushColor();
    TextSetColor(0xff201008);
    s = ((Spr_8016E52C*)fn_801D68C4((void *)(lbl_803470F0), 0x1d));
    s->x = x + 16;
    s->y = y - 2;
    fn_801D4F0C((void *)(s), 0, 0, 1, 20.0f + o->z, 0.0f, f, 1.0f);
    TextPrint(x + 0x54, y + 6, fn_80193FAC());
    TextPopColor(1);
    TextSetZ(oz);
}

void fn_801677D0(u32 a, s32 b, f32 x, f32 y, f32 z, f32 w, u8 c, Task *d)
{
    Fx_801677D0 *h = ((Fx_801677D0 *)fn_802267AC((void *)(lbl_8034759C), (void *)(fn_801679A4)));

    h->st = fn_801E1C7C(0x4c);
    h->st->x0 = a;
    h->st->x8 = 0;
    h->st->xc = 0;
    h->st->xd = 0;
    h->st->x18 = b;
    h->st->xe = c;
    h->st->x10 = 0;
    h->st->x1c = x;
    h->st->x20 = y;
    h->st->x24 = z;
    h->st->x28 = w;
    h->st->x3c = 0.0f;
    h->st->x40 = 0.0f;
    h->st->x44 = 0.0f;
    h->st->x2c = d;
    h->st->x30 = 0;
    h->st->x34 = (*(Fx_801677D0 **)&lbl_8034708C);
    if ((*(Fx_801677D0 **)&lbl_8034708C) != 0) {
        (*(Fx_801677D0 **)&lbl_8034708C)->st->x30 = h;
    }
    (*(Fx_801677D0 **)&lbl_8034708C) = h;
    h->st->x48 = 0.0f;
    h->st->x38 = 0;
    h->st->x3c = fn_80167C34(h->st);
    h->st->x40 = h->st->x3c;
    h->st->x44 = 0.0f;
    fn_802172C8(h->st->x0, (s32)(h->st->x40 - 128.0));
}

s8 fn_80167EF0(Sub_80168A04 *a)
{
    void *p;
    s8 k;
    f32 t;
    f32 ty;
    f32 tx;
    f32 d;
    f32 x;
    f32 tz;
    Vec_8016022C o;
    Vec_8016022C v;

    if ((*(Cam_80167EF0 **)&lbl_80347450) != 0) {
        p = fn_8015F1A0(a->f18 >> 16);
        if (p == 0 && fn_800C8D90() != 0) {
            return -0x7f;
        }
        p = fn_8015F180((void *)(p));
        v.x = a->x1c;
        v.y = a->x20;
        v.z = a->x24;
        fn_8009FDA0(p, 3, &o, 0, &v, 0, 1);
        ty = pow((*(Cam_80167EF0 **)&lbl_80347450)->y - o.y, 2.0);
        tx = pow((*(Cam_80167EF0 **)&lbl_80347450)->x - o.x, 2.0);
        tz = pow((*(Cam_80167EF0 **)&lbl_80347450)->z - o.z, 2.0);
        d = tx + ty + tz;
    } else {
        d = -1.0f;
    }
    k = a->f18 & 0xff;
    if (d >= 0.0f && a->x28 >= 0.0f) {
        if (d > (f32)pow(a->x28, 2.0)) {
            k = -0x7f;
        } else {
            x = a->x28;
            t = fn_80291A5C(d);
            t = (x - t) / x;
            k = (s32)((f32)(k + 0x7e) * t + 1.0f - 127.0f);
        }
    }
    return k;
}

void fn_8016FB2C(void) {
    Eff_8016FB2C* e;
    u32* tb = (*(u32(*)[0x294])&lbl_80307638);
    u8* ui;
    CampCtrl* sel = lbl_8034710C->holder->ctrl;
    u8* cw = CWB;
    if (*(s8*)(cw + 0xC) > 1) {
        ui = *(u8**)(((u8**)(cw + 0x10))[tb[0x7C / 4]] + 0x24) + 8;
        e = ((Eff_8016FB2C*)fn_801D68C4((void *)(lbl_803470F0), 0x45));
        e->x = 24.0f + ((UiObj*)ui)->rect[0];
        e->y = -16.0f + ((UiObj*)ui)->rect[1];
        fn_800FF348((void *)(e), 0, -5850.0f, 1.0f, *(f32*)(cw + 0x34C));
        e = ((Eff_8016FB2C*)fn_801D68C4((void *)(lbl_803470F0), 0x46));
        e->x = 272.0f + ((UiObj*)ui)->rect[0];
        e->y = -16.0f + ((UiObj*)ui)->rect[1];
        fn_800FF348((void *)(e), 0, -5850.0f, 1.0f, *(f32*)(cw + 0x34C));
    }
    switch (sel->cur[4].sel) {
    case 0:
        ui = *(u8**)(PNL2(0x9C) + 0x24) + 8;
        break;
    case 1:
        ui = *(u8**)(PNL2(0xAC) + 0x24) + 8;
        break;
    case 2:
        ui = *(u8**)(PNL2(0xC0) + 0x24) + 8;
        break;
    }
    e = ((Eff_8016FB2C*)fn_801D68C4((void *)(lbl_803470F0), 0x62));
    e->x = 24.0f + ((UiObj*)ui)->rect[0];
    e->y = -16.0f + ((UiObj*)ui)->rect[1];
    fn_800FF348((void *)(e), 0, -5850.0f, 1.0f, *(f32*)(cw + 0x350));
    e = ((Eff_8016FB2C*)fn_801D68C4((void *)(lbl_803470F0), 0x63));
    e->x = 272.0f + ((UiObj*)ui)->rect[0];
    e->y = -16.0f + ((UiObj*)ui)->rect[1];
    fn_800FF348((void *)(e), 0, -5850.0f, 1.0f, *(f32*)(cw + 0x350));
}

extern s32 lbl_80347408;
extern void fn_8009574C(void);
extern void *fn_801E1A2C(s32 a, s32 b);
extern void *fn_802258BC(s32 a, s32 b, s32 c);

s32 fn_8015E174(Ent_8015E174 *self) {
    Obj_8015E174 *n;
    Hold_8015E174 *h = self->x1d8;
    if (h->x8 == 0) {
        if (lbl_80347450 == self) {
            h->flags &= ~0x100;
            lbl_80347408 = 1;
            fn_8009574C();
        }
        h->x8 = fn_801E1A2C(1, 0x270);
        n = h->x8;
        if (n != 0) {
            MemCopy(n, self, 0x270);
            n->xf0 = 0;
            n->h168 = 0;
            h->flags &= ~0x4;
            if (n->x1b8 == 0) {
                n->x1b8 = fn_802258BC(0xffff, 0xffff, 4);
                h->flags |= 2;
            }
            {
                f32 x = self->p38.x;
                f32 y = self->p38.y;
                f32 z = self->p38.z;
                h->p24.z = z;
                h->p24.y = y;
                h->p24.x = x;
            }
            {
                f32 x = self->p104.x;
                f32 y = self->p104.y;
                f32 z = self->p104.z;
                h->p30.z = z;
                h->p30.y = y;
                h->p30.x = x;
            }
            if (h->flags & 8) {
                n->x1bc = 0;
                n->x1c = -1.0f;
            }
            memset(h->x54, 0, 0xc);
            memset(h->x60, 0, 0xc);
            h->x3c = self->x44;
            h->x40 = self->x48;
            h->x44 = self->x4c;
            if (h->h18 != -1) {
                n->h172 = h->h18;
            } else {
                n->h172 = 0;
            }
            n->xec = 0;
            self->x1d4 = 1;
            h->hc = 0;
        }
    }
    return 0;
}

s32 fn_80168A04(Obj_80168A04* a, s32 b) {
    s32 i;
    for (i = 0; i < 3; i++) {
        if (lbl_80306F58[i].obj == 0) {
            lbl_80306F58[i].obj = a;
            lbl_80306F58[i].state = b;
            return 1;
        }
    }
    for (i = 0; i < 3; i++) {
        if (lbl_80306F58[i].obj->sub->bF < a->sub->bF) {
            if (lbl_80306F58[i].state == 2 || lbl_80306F58[i].state == 3) {
                if (fn_80216F48(lbl_80306F58[i].obj->sub->w0)) {
                    fn_80217830(lbl_80306F58[i].obj->sub->w0);
                }
                lbl_80306F58[i].obj->b19 = 5;
                lbl_80306F58[i].obj->sub->w0 = 0;
            }
            lbl_80306F58[i].obj = a;
            lbl_80306F58[i].state = b;
            return 1;
        }
    }
    if (a->sub->w0 > 2 && b != 1 && fn_80216F48(a->sub->w0)) {
        fn_80217830(a->sub->w0);
    }
    a->b19 = 5;
    return 0;
}

void fn_80169360(Obj_80169360* o) {
    extern s32 SePlay(s32 a, s32 b, s32 c);
    Sub_80169360* s;
    s32 done = 0;
    if (o->flags & 0x20) {
        o->state = 0xff;
    }
    s = o->sub;
    if (s->prev == 0) {
        lbl_80306F58[0].obj = 0;
        lbl_80306F58[0].state = 0;
        lbl_80306F58[1].obj = 0;
        lbl_80306F58[1].state = 0;
        lbl_80306F58[2].obj = 0;
        lbl_80306F58[2].state = 0;
    }
    if (s->next == 0) {
        done = 1;
    }
    switch (o->state) {
    case 0:
    case 0xfe:
        s->w0 = SePlay(-1, s->bC, s->bD);
        s->w4 = 0;
        o->state = 10;
        break;
    case 10:
        if (fn_80216F48(s->w0) == 0) {
            o->state = 0xff;
        }
        break;
    case 0xff:
        if (fn_80216F48(s->w0) == 1) {
            fn_80217830(s->w0);
        }
        if (o->sub->prev == 0) {
            lbl_8034708C = o->sub->next;
        } else {
            o->sub->prev->sub->next = o->sub->next;
        }
        if (o->sub->next != 0) {
            o->sub->next->sub->prev = o->sub->prev;
        }
        o->flags |= 0x40;
        break;
    }
    if (done) {
        fn_80168908();
        lbl_80306F58[0].obj = 0;
        lbl_80306F58[0].state = 0;
        lbl_80306F58[1].obj = 0;
        lbl_80306F58[1].state = 0;
        lbl_80306F58[2].obj = 0;
        lbl_80306F58[2].state = 0;
    }
}

extern s32 fn_8016B9C8(void* self);
void fn_8016C204(Self_8016B434* self) {
    switch (self->state) {
    case 0:
    case 0xfe:
        fn_8016C2C0();
        self->state = 1;
        self->timer = -1.3f;
        break;
    case 1:
        if (fn_8016B9C8(self) == 0) {
            self->state = 2;
        }
        break;
    case 2:
        self->state = 0xff;
        break;
    case 0xff:
        self->flags |= 0x40;
        if (lbl_803470B0 != 0) {
            lbl_803470B0 = 0;
        }
        break;
    }
}

/* Installs callback fn in slot idx of the entity's holder; fn == NULL restores the default
 * from lbl_802B4118. Slot 13 goes to a separate field. */
void fn_8015EB8C(Ent_8015EB8C *self, s32 idx, void *fn)
{
    Hold_8015EB8C *h = self->hold;

    if (fn == NULL) {
        h->cb[idx] = lbl_802B4118[idx].fn;
        return;
    }
    if (h == NULL) {
        return;
    }
    if (idx == 13) {
        h->cb13 = fn;
        return;
    }
    if (idx == 2 || idx >= 47) {
        return;
    }
    h->cb[idx] = fn;
}

void fn_8016C808(s8 c)
{
    OwnerB_8016C808 *o = (*(OwnerB_8016C808 **)&lbl_803470B0);
    if (o == 0) {
        return;
    }
    if (c == 9) {
        o->inner->b3 = c;
    } else if (c == 10) {
        switch (c) {
        case 2:
        case 3:
        case 6:
            return;
        default:
            o->inner->b2 = c;
            break;
        }
    } else {
        o->inner->b2 = c;
    }
}

void fn_80166B2C(Obj_80166B2C *obj, s32 ang, s32 idx) {
    Work *w = obj->work;
    Info *info = w->info;
    Joint *j = w->joint;
    s32 d;

    if (info->tbl == NULL) {
        return;
    }
    d = (ang - info->tbl->base[idx]) & 0xFFFF;
    if (d > 0x8000) {
        d -= 0x10000;
    }
    w->x54[idx] = 0;
    j->delta[idx] = d;
    if ((s16)d > 0) {
        j->speed[idx] = 0x2d8;
    } else if ((s16)d < 0) {
        j->speed[idx] = -0x2d8;
    }
}

void fn_8016AA64(Mover *m, f32 x, f32 y)
{
    f32 dx, dy;

    m->destX = x;
    m->destY = y;
    dx = x - m->x;
    dy = y - m->y;
    dx /= 6.0f;
    dy /= 6.0f;
    m->stepX = dx;
    m->stepY = dy;
    m->steps = 6;
}

extern void fn_801D5DD8(Item_8016CAB4 *a, f32 e, f32 f, f32 g, f32 h, s32 b, s32 c, f32 i, f32 j, void *d);

void fn_8016AA9C(Arg_8016CAB4 *p)
{
    fn_801D5DD8(p->item, 1.0f, 1.0f, p->a, p->b, p->c, p->d, p->e, p->f, lbl_8034709C->inner->texlist);
}

void fn_8016AAF0(Arg_8016CAB4 *p)
{
    fn_801D5DD8(p->item, 1.0f, 1.0f, p->a, p->b, p->c, p->d, p->e, p->f, lbl_80347098->inner->texlist);
}

void fn_8016AB44(Arg_8016CAB4 *p)
{
    fn_801D5DD8(p->item, 1.0f, 1.0f, p->a, p->b, p->c, p->d, p->e, p->f, lbl_80347094->inner->texlist);
}

void fn_8016AB98(Arg_8016CAB4 *p)
{
    fn_801D5DD8(p->item, 1.0f, 1.0f, p->a, p->b, p->c, p->d, p->e, p->f, lbl_80347090->inner->texlist);
}

void fn_8015F7A8(f32 *mtx, s32 *out)
{
    NJS_VECTOR ax = lbl_802B4334;
    NJS_VECTOR az = lbl_802B4340;
    NJS_MATRIX m;
    NJS_VECTOR t;
    NJS_VECTOR a;
    NJS_VECTOR b;
    f32 x, y, z, len;

    if (mtx != NULL) {
        njSetMatrix(m, mtx);
    } else {
        fn_80291C44((void *)(m));
    }
    njUnitTransPortion(m);
    njCalcVector(m, &ax, &a);
    njCalcVector(m, &az, &b);
    y = a.y;
    z = a.z;
    x = a.x;
    len = fn_80291A5C(x * x + y * y);
    if (0.0f == x && 0.0f == y) {
        out[2] = 0;
    } else {
        out[2] = -(s32)(10430.381f * (f32)atan2(y, x));
    }
    fn_802136A8((void *)(&a), (void *)(&t), 0, 0, out[2]);
    a.x = t.x;
    a.y = t.y;
    a.z = t.z;
    fn_802136A8((void *)(&b), (void *)(&t), 0, 0, out[2]);
    b.x = t.x;
    b.y = t.y;
    b.z = t.z;
    if (0.0f == z && 0.0f == len) {
        out[1] = 0;
    } else {
        out[1] = (s32)(10430.381f * (f32)atan2(z, len));
    }
    fn_802136A8((void *)(&a), (void *)(&t), 0, out[1], 0);
    a.x = t.x;
    a.y = t.y;
    a.z = t.z;
    fn_802136A8((void *)(&b), (void *)(&t), 0, out[1], 0);
    b.x = t.x;
    b.y = t.y;
    b.z = t.z;
    if (0.0f == b.y && 0.0f == b.z) {
        out[0] = 0;
    } else {
        out[0] = (s32)(10430.381f * (f32)atan2(b.y, b.z));
    }
    fn_802136A8((void *)(&a), (void *)(&t), out[0], 0, 0);
    a.x = t.x;
    a.y = t.y;
    a.z = t.z;
    fn_802136A8((void *)(&b), (void *)(&t), out[0], 0, 0);
    b.x = t.x;
    b.y = t.y;
    b.z = t.z;
    out[0] *= -1;
    out[1] *= -1;
    out[2] *= -1;
}

void fn_8016B638(s8 mode)
{
    f32 k;

    (*(Node_8016B638 **)&lbl_803470A0) = ((Node_8016B638 *)fn_802268E8((void *)((*(void **)&lbl_803475A8)), (void *)(fn_8016B434)));
    (*(Node_8016B638 **)&lbl_803470A0)->work = fn_801E1C7C(0x48);
    if ((*(Node_8016B638 **)&lbl_803470A0) != 0) {
        (*(Node_8016B638 **)&lbl_803470A0)->work->f4 = 0.0f;
        (*(Node_8016B638 **)&lbl_803470A0)->work->f8 = 0.0f;
    }
    if ((*(Node_8016B638 **)&lbl_803470A0) != 0) {
        (*(Node_8016B638 **)&lbl_803470A0)->work->f24 = 0.0f;
    }
    if ((*(Node_8016B638 **)&lbl_803470A0) != 0) {
        (*(Node_8016B638 **)&lbl_803470A0)->work->f28 = 0.0f;
    }
    if ((*(Node_8016B638 **)&lbl_803470A0) != 0) {
        (*(Node_8016B638 **)&lbl_803470A0)->work->f2c = 0.0f;
    }
    if ((*(Node_8016B638 **)&lbl_803470A0) != 0) {
        (*(Node_8016B638 **)&lbl_803470A0)->work->f30 = 0.0f;
    }
    if ((*(Node_8016B638 **)&lbl_803470A0) != 0) {
        (*(Node_8016B638 **)&lbl_803470A0)->work->f34 = 0.0f;
    }
    if ((*(Node_8016B638 **)&lbl_803470A0) != 0) {
        (*(Node_8016B638 **)&lbl_803470A0)->work->f38 = 0.0f;
    }
    if ((*(Node_8016B638 **)&lbl_803470A0) != 0) {
        (*(Node_8016B638 **)&lbl_803470A0)->work->f3c = 0.0f;
    }
    if ((*(Node_8016B638 **)&lbl_803470A0) != 0) {
        (*(Node_8016B638 **)&lbl_803470A0)->work->f40 = 0.0f;
    }
    if ((*(Node_8016B638 **)&lbl_803470A0) != 0) {
        (*(Node_8016B638 **)&lbl_803470A0)->work->f44 = 0.0f;
    }
    k = 0.0f;
    if ((*(Node_8016B638 **)&lbl_803470A0) != 0) {
        Work_8016B638 *w = (*(Node_8016B638 **)&lbl_803470A0)->work;
        if (w->b0 == 3) {
            k = k - 75.0f;
        }
        w->f20 = k;
    }
    if ((*(Node_8016B638 **)&lbl_803470A0) != 0) {
        (*(Node_8016B638 **)&lbl_803470A0)->work->b1 = 1;
    }
    if ((*(Node_8016B638 **)&lbl_803470A0) != 0) {
        (*(Node_8016B638 **)&lbl_803470A0)->work->b0 = mode;
    }
    switch (mode) {
    case 0:
    case 1:
    case 2:
        if ((*(Node_8016B638 **)&lbl_803470A0) != 0) {
            Work_8016B638 *w = (*(Node_8016B638 **)&lbl_803470A0)->work;
            w->f20 = w->f30 = 0.0f;
        }
        if ((*(Node_8016B638 **)&lbl_803470A0) != 0) {
            (*(Node_8016B638 **)&lbl_803470A0)->work->f38 = 0.3f;
        }
        if ((*(Node_8016B638 **)&lbl_803470A0) != 0) {
            (*(Node_8016B638 **)&lbl_803470A0)->work->f40 = 3.0f;
        }
        if ((*(Node_8016B638 **)&lbl_803470A0) != 0) {
            (*(Node_8016B638 **)&lbl_803470A0)->work->f24 = 75.0f;
        }
        if ((*(Node_8016B638 **)&lbl_803470A0) != 0) {
            (*(Node_8016B638 **)&lbl_803470A0)->work->f28 = 150.0f;
        }
        if ((*(Node_8016B638 **)&lbl_803470A0) != 0) {
            (*(Node_8016B638 **)&lbl_803470A0)->work->f2c = 150.0f;
        }
        if ((*(Node_8016B638 **)&lbl_803470A0) != 0) {
            (*(Node_8016B638 **)&lbl_803470A0)->work->f34 = -150.0f;
        }
        break;
    case 3:
        if ((*(Node_8016B638 **)&lbl_803470A0) != 0) {
            Work_8016B638 *w = (*(Node_8016B638 **)&lbl_803470A0)->work;
            w->f20 = w->f30 = 0.0f;
        }
        if ((*(Node_8016B638 **)&lbl_803470A0) != 0) {
            (*(Node_8016B638 **)&lbl_803470A0)->work->f38 = 0.3f;
        }
        if ((*(Node_8016B638 **)&lbl_803470A0) != 0) {
            (*(Node_8016B638 **)&lbl_803470A0)->work->f40 = 3.0f;
        }
        if ((*(Node_8016B638 **)&lbl_803470A0) != 0) {
            (*(Node_8016B638 **)&lbl_803470A0)->work->f24 = 162.5f;
        }
        if ((*(Node_8016B638 **)&lbl_803470A0) != 0) {
            (*(Node_8016B638 **)&lbl_803470A0)->work->f28 = 325.0f;
        }
        if ((*(Node_8016B638 **)&lbl_803470A0) != 0) {
            (*(Node_8016B638 **)&lbl_803470A0)->work->f2c = 400.0f;
        }
        if ((*(Node_8016B638 **)&lbl_803470A0) != 0) {
            (*(Node_8016B638 **)&lbl_803470A0)->work->f34 = -325.0f;
        }
        break;
    }
}

void fn_8017172C(void)
{
    UiObj* obj;
    s32 i;
    f32 x, y;

    obj = OBJ(lbl_80307638[1].cur[0].sel);
    fn_80199BB8(obj, -8.0f, 61.0f);
    fn_80199BAC(obj, -8.0f, 61.0f);
    for (i = 0; i < 4; i++) {
        obj = OBJ(i + 0x1f);
        y = (i + 1) * 64 + 61;
        fn_80199BB8(obj, -348.0f, y);
        fn_80199BAC(obj, -348.0f, y);
    }
    for (i = 0; i < 4; i++) {
        obj = OBJ(i + 0x23);
        if (i == 3) {
            x = 668.0f;
            y = 381.0f;
        } else {
            x = 668.0f;
            y = i * 64 + 61;
        }
        fn_80199BB8(obj, x, y);
        fn_80199BAC(obj, x, y);
    }
    for (i = 0; i < 5; i++) {
        obj = OBJ(i + 0x27);
        if (i == 4) {
            x = 668.0f;
            y = 381.0f;
        } else {
            x = 668.0f;
            y = i * 64 + 61;
        }
        fn_80199BB8(obj, x, y);
        fn_80199BAC(obj, x, y);
    }
    for (i = 0; i < 6; i++) {
        obj = OBJ(i + 0x2c);
        y = i * 64 + 61;
        fn_80199BB8(obj, 668.0f, y);
        fn_80199BAC(obj, 668.0f, y);
    }
    if (fn_80193F78()) {
        obj = OBJ(0x32);
        fn_80199BB8(obj, 668.0f, 317.0f);
        fn_80199BAC(obj, 668.0f, 317.0f);
    }
}


typedef struct Obj_801673D8 {
    u8 pad0[0x38];
    Vec p38;
    u8 pad44[0x1b8 - 0x44];
    void *x1b8;
} Obj_801673D8;

s32 fn_801673D8(Obj_801673D8 *o, s32 id)
{
    if (o != NULL && o->x1b8 != NULL) {
        return fn_802256A0(&o->p38, o->x1b8, 0xFFFF, id);
    }
    return 0;
}

s8 fn_80168BD4(Sub_80168A04 *w)
{
    void *h;
    Vec_8016022C o;
    Vec_8016022C p;
    f32 dy2, dx2, dz2, d2;
    f32 a, b;
    s32 n;
    s8 id;
    s8 r;
    f32 g;

    if (w->x2c != 0) {
        h = w->x2c->x24;
    } else {
        h = fn_8015F1A0(w->f18 >> 16);
    }
    if (h == 0 && fn_800C8D90() != 0) {
        return -0x7f;
    }
    h = fn_8015F180((void *)(h));
    p.x = w->x1c;
    p.y = w->x20;
    p.z = w->x24;
    fn_8009FDA0((void *)(h), 3, (void *)(&o), 0, (void *)(&p), 0, 1);
    dy2 = (f32)pow(lbl_803119E0.pos.y - o.y, 2.0);
    dx2 = (f32)pow(lbl_803119E0.pos.x - o.x, 2.0);
    dz2 = (f32)pow(lbl_803119E0.pos.z - o.z, 2.0);
    d2 = dz2 + (dx2 + dy2);
    if (w->f0e >= 0) {
        a = (f32)atan2(o.x - lbl_803119E0.pos.x, o.z - lbl_803119E0.pos.z);
        b = (f32)atan2(lbl_803119E0.dir.x, lbl_803119E0.dir.z);
        n = (s32)(10430.381f * b) - (s32)(10430.381f * a);
        n = (s32)(127.0f * (0.5f * (1.0f - njSin(n))));
        id = w->f0e;
        if (id < 2) {
            lbl_80347080[id] = n;
        }
    }
    r = (u8)w->f18;
    if (d2 >= 0.0f && w->x28 >= 0.0f) {
        if (d2 > (f32)pow(w->x28, 2.0)) {
            r = -0x7f;
        } else {
            g = w->x28;
            r = (s32)((f32)(r + 0x7e) * ((g - fn_80291A5C(d2)) / g) + 1.0f - 127.0f);
        }
    }
    return r;
}

static inline s32 JointStepAxis(Joint_80166EC4* j, u32 i) {
    if (j != 0 && i < 3) {
        s16 d;
        j->pos[i] += j->vel[i];
        d = j->target[i] - j->pos[i];
        if ((j->vel[i] > 0 && d <= 0) || (j->vel[i] <= 0 && d >= 0)) {
            j->pos[i] = j->target[i];
            return 1;
        }
    }
    return 0;
}

static inline s32 JointStep(Joint_80166EC4* j) {
    s32 done = 1;
    s32 i;
    if (j != 0) {
        for (i = 0; i < 3; i++) {
            done = JointStepAxis(j, i) && done;
        }
    }
    return done;
}

static inline void JointSync(Joint_80166EC4* j) {
    if (j != 0 && j->obj != 0) {
        f32* pos = j->obj->pos;
        f32 x = j->x38[0];
        f32 y = j->x38[1];
        f32 z = j->x38[2];
        pos[2] = z;
        pos[1] = y;
        pos[0] = x;
        j->obj->rot[0] = j->pos[0];
        j->obj->rot[1] = j->pos[1];
        j->obj->rot[2] = j->pos[2];
        fn_80222838(j->obj);
    }
}

static inline s32 JointMinSpeed(Joint_80167034* j, u32 i) {
    s32 v = 0;
    if (j != 0 && i < 3) {
        s16 d = j->target[i] - j->pos[i];
        if (d < 0) {
            v = -0xb6;
        } else if (d > 0) {
            v = 0xb6;
        }
    }
    return v;
}

void fn_80166E14(Joint_80167034 *j, s32 frames) {
    unsigned int i;
    if (j == 0) {
        return;
    }
    if (frames <= 0) {
        frames = 1;
    }
    for (i = 0; i < 3; i++) {
        s16 d = j->target[i] - j->pos[i];
        s16 n = frames;
        s16 v = d / n;
        j->vel[i] = v;
        if (j->vel[i] == 0 && d != 0) {
            j->vel[i] = JointMinSpeed(j, i);
        }
    }
}

s32 fn_80166EC4(Joint_80166EC4* j, f32 t) {
    s32 done = 1;
    if (j != 0) {
        done = JointStep(j);
        JointSync(j);
        if (done) {
            j->x190 = t;
        }
    }
    return done;
}

static inline void JointSetSpeed(Joint_80167034* j, s32 frames) {
    s32 i;
    if (j == 0) {
        return;
    }
    if (frames <= 0) {
        frames = 1;
    }
    for (i = 0; i < 3; i++) {
        s16 d = j->target[i] - j->pos[i];
        j->vel[i] = (s16)(d / (s16)frames);
        if (j->vel[i] == 0 && d != 0) {
            j->vel[i] = JointMinSpeed(j, i);
        }
    }
}

void fn_80167034(Joint_80167034* j, s32* target, s32 frames, f32* out) {
    if (j == 0) {
        return;
    }
    memset(j->vel, 0, sizeof(j->vel));
    j->x5c = j->x60 = j->x64 = 0.0f;
    j->pos[0] = (s16)j->pos[0];
    j->pos[1] = (s16)j->pos[1];
    j->pos[2] = (s16)j->pos[2];
    j->target[0] = (s16)target[0];
    j->target[1] = (s16)target[1];
    j->target[2] = (s16)target[2];
    JointSetSpeed(j, frames);
    if (out != 0) {
        *out = j->x190;
    }
    j->x190 *= 0.5f;
}

void fn_8016CED8(Task* task) {
    switch (task->state) {
    case 0:
    case 0xfe:
        (*(Obj_8016C2C0**)&lbl_803470B8)->tbl = fn_801E1C7C(0x14);
        switch (*(*(Obj_8016C2C0**)&lbl_803470B8)->kind) {
        case 0:
            break;
        case 1:
            (*(Obj_8016C2C0**)&lbl_803470B8)->tbl->p0 = lbl_802E7D5C;
            (*(Obj_8016C2C0**)&lbl_803470B8)->tbl->p4 = lbl_802E8390;
            (*(Obj_8016C2C0**)&lbl_803470B8)->tbl->p8 = lbl_802E83E0;
            (*(Obj_8016C2C0**)&lbl_803470B8)->tbl->pc = lbl_802E8464;
            (*(Obj_8016C2C0**)&lbl_803470B8)->tbl->p10 = lbl_802E84E8;
            break;
        case 2:
            break;
        case 3:
            break;
        }
        task->state = 1;
        break;
    case 1:
        if (fn_8016C888() == 0) {
            task->state = 2;
        }
        break;
    case 2:
        task->state = 0xff;
        break;
    case 0xff:
        task->flags |= 0x40;
        if ((*(Obj_8016C2C0**)&lbl_803470B8) != 0) {
            (*(Obj_8016C2C0**)&lbl_803470B8) = 0;
        }
        break;
    }
}

void fn_8016E6E8(Work_8016E6E8* w) {
    s32 lx;
    s32 rx;
    s32 ty;
    s32 x;
    s32 y;
    Info_8016E6E8* info;
    CampCtrl* c;
    f32 oz;

    c = lbl_8034710C->holder->ctrl;
    x = (s32)w->ui.rect[0];
    y = (s32)w->ui.rect[1];
    info = w->info;
    oz = TextGetZ();
    TextSetZ(10.1f + (10.0f + w->f74));
    TextPushColor();
    TextSetColor(0xff201008);
    lx = x + 0x18;
    ty = y + 6;
    rx = x + 0x110;
    TextPrint(lx, ty, info->name);
    TextPrintf(rx, ty, "%2d", info->level);
    if (info->b14 == 0 && c->cur[0].sel == fn_8018126C()) {
        info->level2 = fn_801812C0();
        TextPrint(lx, ty + 0x18, info->name2);
        TextPrintf(rx, ty + 0x18, "%2d", info->level2);
    }
    TextPopColor(1);
    TextSetZ(oz);
}

s32 fn_80161F04(Obj_8015F768 *o, Arg_80161F04 *a) {
    Sub_8015F768 *s = o->x1d8;
    Inner_80161F04 *in = s->inner;

    if (!ObjIsMoving(o)) {
        return 0;
    }
    if (s->x17c == a->id) {
        if (s->x178 != 3) {
            return 0;
        }
        s->x178 = 2;
        fn_800A0028(o);
        s->x178 = 0;
        in->h16c = 0;
        in->fb4 = 0.0f;
        in->fb8 = 0.0f;
        in->fbc = 0.0f;
        in->fc0 = 0;
        in->fc4 = 0;
        in->fc8 = 0;
    }
    return 0;
}

static inline s32 inRange(EvSub *h, Tab_80166138 *t) {
    if (h != 0 && t != 0 && t->ents != 0 && t->count != 0 && t->count > h->idx) return 1;
    return 0;
}

s32 fn_80166138(EvObj *o, Tab_80166138 *t) {
    EvSub *h = o->sub;
    EvObj *m = h->target;
    s32 r = fn_801664A4(o);
    if (inRange(o->sub, t)) {
        Ent_80166138 *e = &t->ents[h->idx];
        u16 i = m->x172;
        if (m->motionId != i && e->f2c != 1 && m->x198 != 0) {
            fn_801E735C(i, 1.0f, m);
        }
    }
    return r;
}

NameEnt *fn_8016748C(Node *n, char **key) {
    Node *p;
    NameEnt *e;
    u32 i;
    for (i = 0; i < n->tab->count; i++) {
        e = &n->tab->ents[i];
        if (strncmp(e->name, *key, strlen(e->name)) == 0) return e;
    }
    for (p = n->parent; p != 0; p = p->parent) {
        for (i = 0; i < p->tab->count; i++) {
            e = &p->tab->ents[i];
            if (strncmp(e->name, *key, strlen(e->name)) == 0) return e;
        }
    }
    return 0;
}

static inline s32 iabs(s32 v)
{
    s32 s = v >> 31;
    return (s ^ v) - s;
}
s32 fn_80166D40(s32 *a, s32 *b)
{
    s16 m;
    s16 d;
    s32 i;
    s32 r = 1;

    if (a != NULL && b != NULL) {
        m = 0;
        for (i = 0; i < 3; i++) {
            d = iabs((s16)(b[i] - a[i]));
            m = (m > d) ? m : d;
        }
        r = m / 2184;
    }
    return r;
}

u32 fn_8015FAD4(NJS_POINT3* pos) {
    Hit h;
    u32 id;
    f32 y;
    h.pos.x = pos->x;
    h.pos.y = pos->y;
    h.pos.z = pos->z;
    id = 0xFFFFFFFF;
    h.pos.y += 1.0f;
    if (fn_8022436C(0xFFFF, &h, 1) == 1) {
        if (h.n1 != 0) {
            id = h.id1;
            y = h.y1;
        } else if (h.n0 != 0) {
            id = h.id0;
            y = h.y0;
        }
    }
    if (id != 0xFFFFFFFF) {
        pos->y = y;
    }
    return id;
}

static inline Ent_80167578 *Find(Obj_80167578 *o, s32 i) {
    Tbl_80167578 *t = o->m->tbl;
    return (t->n > i) ? *(Ent_80167578 **)((u8 *)t->e + i * 4) : NULL;
}

void *fn_80167578(Obj_80167578 *o, s32 i)
{
    Ent_80167578 *e = Find(o, i);
    if (e != NULL) {
        return e->x8;
    }
    for (o = o->next; o != NULL; o = o->next) {
        e = Find(o, i);
        if (e != NULL) {
            return e->x8;
        }
    }
    return NULL;
}

static inline s32* Lookup(Node_80167604* n, int idx)
{
    Table_80167604* t = n->h->t;
    return (t->n > idx) ? *(s32 **)((u8 *)t->e + idx * 4) : NULL;
}

s32 fn_80167604(Node_80167604* self, int idx)
{
    Node_80167604* n;
    s32* e = Lookup(self, idx);
    if (e != NULL) return *e;
    for (n = self->parent; n != NULL; n = n->parent) {
        e = Lookup(n, idx);
        if (e != NULL) return *e;
    }
    return 0;
}

void fn_8016F21C(IconObj* o, s8 kind, f32 scale) {
    void* sp;
    o->x = -7090.0f + 150.0f * (f32)kind;
    o->y = 0.0f;
    o->f10 = 0.7f;
    o->scale = scale;
    o->f18 = 1.0f;
    o->f1c = 0.0f;
    o->f08 = 0;
    o->f0c = 0;
    fn_8019A15C(o, 2, 1, 1);
    if (kind == 10 || kind == 11) {
        *o->spr20 = fn_801D68C4(lbl_803470F0, 9);
    } else if (kind == 12 || kind == 13) {
        *o->spr20 = fn_801D68C4(lbl_803470F0, 0x65);
    } else if (kind == 14 || kind == 15) {
        *o->spr20 = fn_801D68C4(lbl_803470F0, 0x65);
    } else if (kind == 16 || kind == 17) {
        *o->spr20 = fn_801D68C4(lbl_803470F0, 0x65);
    } else if (kind == 18 || kind == 19) {
        *o->spr20 = fn_801D68C4(lbl_803470F0, 9);
    } else {
        *o->spr20 = fn_801D68C4(lbl_803470F0, 6);
    }
    o->pos24->a = 0.0f;
    o->pos24->b = 0.0f;
    switch (kind) {
    case 0: sp = fn_801D68C4(lbl_803470F0, 0x15); break;
    case 1: sp = fn_801D68C4(lbl_803470F0, 0x18); break;
    case 2: sp = fn_801D68C4(lbl_803470F0, 0x17); break;
    case 3: sp = fn_801D68C4(lbl_803470F0, 0x14); break;
    case 4: sp = fn_801D68C4(lbl_803470F0, 0x14); break;
    case 5: sp = fn_801D68C4(lbl_803470F0, 0x1d); break;
    case 10: sp = fn_801D68C4(lbl_803470F0, 0x11); break;
    case 11: sp = fn_801D68C4(lbl_803470F0, 0x12); break;
    case 6: sp = fn_801D68C4(lbl_803470F0, 0x16); break;
    case 7: sp = fn_801D68C4(lbl_803470F0, 0x1a); break;
    case 8: sp = fn_801D68C4(lbl_803470F0, 0x19); break;
    case 9: sp = fn_801D68C4(lbl_803470F0, 0x13); break;
    case 12: sp = fn_801D68C4(lbl_803470F0, 0x1b); break;
    case 13: sp = fn_801D68C4(lbl_803470F0, 0x1c); break;
    case 14: sp = fn_801D68C4(lbl_803470F0, 0x6e); break;
    case 15: sp = fn_801D68C4(lbl_803470F0, 0x6f); break;
    case 16: sp = fn_801D68C4(lbl_803470F0, 0x66); break;
    case 17: sp = fn_801D68C4(lbl_803470F0, 0x67); break;
    case 18:
    case 19: sp = fn_801D68C4(lbl_803470F0, 0x48); break;
    default: sp = fn_801D68C4(lbl_803470F0, 0x15); break;
    }
    o->spr20[1] = sp;
    o->pos24->c = 24.0f;
    o->pos24->d = -2.0f;
    *o->spr2c = fn_801D68C4(lbl_803470E8, 1);
    o->pos30->x = 0.0f;
    o->pos30->y = 0.0f;
    *o->spr38 = fn_801D68C4(lbl_803470F4, 1);
    o->pos3c->x = 100.0f;
    o->pos3c->y = 13.0f;
    o->spr44 = fn_801D68C4(lbl_803470F0, 1);
}

void fn_80170DCC(void)
{
    UiObj *obj;
    s32 i;
    CampCtrl *ctl;
    s32 j;

    ctl = lbl_8034710C->holder->ctrl;
    for (i = 0; i < 4; i++) {
        if (ctl->cur[0].mask & (1 << i)) {
            if (i == ctl->cur[0].sel) {
                obj = &camp_work.pnl[0x1f + i]->win->obj;
                UiObjMoveTo(obj, 6, -1, -8.0f, 125.0f);
                UiObjSetCommand(obj, 0xf, i + 2);
            } else {
                obj = &camp_work.pnl[0x1f + i]->win->obj;
                UiObjMoveTo(obj, 6, -1, -348.0f, (i + 1) * 64 + 61);
                UiObjSetCommand(obj, 0xf, i + 2);
            }
        }
    }
    switch (ctl->cur[4].sel) {
    case 0:
        for (j = 0; j < 4; j++) {
            obj = &camp_work.pnl[0x23 + j]->win->obj;
            if (j == 3) {
                UiObjMoveTo(obj, 6, 5, 668.0f, 381.0f);
                UiObjSetCommand(obj, 0xf, 6);
            } else {
                UiObjMoveTo(obj, 6, 5, 668.0f, j * 64 + 61);
                UiObjSetCommand(obj, 0xf, j + 1);
            }
        }
        if (lbl_8030B7F4.party[ctl->cur[2].sel] == 0 && fn_80193F78() != 0) {
            obj = &camp_work.pnl[0x32]->win->obj;
            UiObjMoveTo(obj, 6, 5, 668.0f, 317.0f);
            UiObjSetCommand(obj, 0xf, 5);
        }
        break;
    case 1:
        for (i = 0; i < 5; i++) {
            obj = &camp_work.pnl[0x27 + i]->win->obj;
            if (i == 4) {
                UiObjMoveTo(obj, 6, 5, 668.0f, 381.0f);
                UiObjSetCommand(obj, 0xf, 6);
            } else {
                UiObjMoveTo(obj, 6, 5, 668.0f, i * 64 + 61);
                UiObjSetCommand(obj, 0xf, i + 1);
            }
        }
        break;
    case 2:
        for (i = 0; i < 6; i++) {
            obj = &camp_work.pnl[0x2c + i]->win->obj;
            UiObjMoveTo(obj, 6, 5, 668.0f, i * 64 + 61);
            UiObjSetCommand(obj, 0xf, i + 1);
        }
        break;
    }
}

void fn_80171484(void)
{
    UiObj* obj;
    s32 i;
    UiObj* o1;
    s32 j;
    s32 a;
    s32 b;
    s32 d;
    CampCtrl* c;

    c = lbl_8034710C->holder->ctrl;
    o1 = &camp_work.pnl[lbl_80307638[1].cur[0].sel]->win->obj;
    UiObjMoveTo(o1, 6, 4, -8.0f, 61.0f);
    UiObjSetCommand(o1, 15, 0);
    for (j = 0; j < 4; j++) {
        if (c->cur[0].mask & (1 << j)) {
            obj = &camp_work.pnl[j + 0x1f]->win->obj;
            UiObjMoveTo(obj, 6, -1, -8.0f, (j + 1) * 64 + 61);
            if (c->cur[0].sel == j) {
                UiObjSetCommand(obj, 10, j + 1);
            } else {
                UiObjSetCommand(obj, 15, j + 2);
            }
        }
    }
    switch (c->cur[4].sel) {
    case 0:
        a = 0x23;
        b = 4;
        d = 3;
        break;
    case 1:
        a = 0x27;
        b = 5;
        d = 4;
        break;
    case 2:
        a = 0x2c;
        b = 6;
        d = 5;
        break;
    }
    for (i = 0; i < b; i++) {
        obj = &camp_work.pnl[a + i]->win->obj;
        if (d == i) {
            UiObjMoveTo(obj, 6, 4, 328.0f, 381.0f);
            UiObjSetCommand(obj, 15, 6);
        } else {
            UiObjMoveTo(obj, 6, 4, 328.0f, i * 64 + 61);
            UiObjSetCommand(obj, 15, i + 1);
        }
    }
    if (lbl_8030B7F4.party[c->cur[2].sel] == 0 && fn_80193F78() && c->cur[4].sel == 0) {
        obj = &camp_work.pnl[0x32]->win->obj;
        UiObjMoveTo(obj, 6, 4, 328.0f, 317.0f);
        UiObjSetCommand(obj, 15, 5);
    }
}

#ifdef NONMATCHING
typedef struct Query {
    s32 type;
    s32 val;
    s32 mask;
    s32 pad;
} Query;
typedef struct Entry {
    u8 pad0[8];
    u32 key;
    struct { u8 pad[0x1c]; s32 x1c; } *xc;
} Entry;
typedef s32 (*QueryFn)(u32 *, u32 *);
extern void *fn_800CCAE4(QueryFn cb, void *arg, u32 best);
extern s32 fn_800E0AD0(s32 mode, s32 a, s32 b);
#endif

#ifdef NONMATCHING
void fn_8015E470(Ent *self) {
    Query q2;
    Query q1;
    Query q3;
    Hold *h;
    s32 c1;
    s32 c2;
    s32 c3;
    Entry *e;
    QueryFn cb;
    s16 v;
    s32 r;
    u16 id;
    u32 best;

    best = 0xffff;
    c3 = 0;
    c2 = 0;
    c1 = 0;
    h = self->x1d8;
    cb = fn_8015F298;
    q3.type = 7;
    q2.type = 7;
    q1.type = 7;
    q3.val = h->h14;
    q2.val = h->h14;
    q1.val = h->h14;
    q1.mask = 0x40000;
    q2.mask = 0;
    q3.mask = 0x10000;
    do {
        e = fn_800CCAE4(fn_8015F298, &q1, best);
        if (e != 0) {
            r = fn_800E0AD0(h->x10, h->h16, e->xc->x1c);
            v = 1;
            if (r == 1) v = 2;
            h->hE = v;
            id = e->key;
            best = id - 1;
        } else {
            c1++;
        }
        e = fn_800CCAE4(cb, &q2, best);
        if (e != 0) {
            r = fn_800E0AD0(h->x10, h->h16, e->xc->x1c);
            v = 1;
            if (r == 1) v = 2;
            h->hE = v;
            id = e->key;
            best = id - 1;
        } else {
            c2++;
        }
        e = fn_800CCAE4(cb, &q3, best);
        if (e != 0) {
            r = fn_800E0AD0(h->x10, h->h16, e->xc->x1c);
            v = 2;
            if (r == 1) v = 1;
            h->hE = v;
            id = e->key;
            best = id - 1;
        } else {
            c3++;
        }
    } while (c1 == 0 || c2 == 0 || c3 == 0);
}
#endif
