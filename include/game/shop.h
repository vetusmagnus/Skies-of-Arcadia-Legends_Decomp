#ifndef GAME_SHOP_H
#define GAME_SHOP_H

#include "types.h"
#include "game/save_8030B7F4.h"
#include "game/task.h"
#include "game/uiobj.h"
#include "ninja.h"
#include "game/sprite.h"
#include "game/util.h"
#define TextPrint TextPrint_hdr
#include "game/text.h"
#undef TextPrint
extern void TextPrint(s32 x, s32 y, const char *str);
#include "game/menu.h"
#include "game/drawstate.h"
#include "game/evobj.h"
#include "game/gamedata.h"
#include <math.h>
#include <stdlib.h>
#include "game/camp.h"
#include "game/draw2d.h"
/* A menu panel (0x6C bytes, the object at a menu part task's 0x28/0x2C): its UiObj, the text it
 * prints and four parameters (layout, item or member ids). */
typedef struct MenuPanel {
    UiObj o;
    const char* text; /* 0x4C */
    u16 h50;          /* 0x50 */
    u16 h52;          /* 0x52 */
    u16 h54;          /* 0x54 */
    u16 h56;          /* 0x56 */
    u8 pad58[0x14];
} MenuPanel;
/* A menu part's work (0x58 bytes, at the part task's 0x24). b0 == 1 hides the part. */
typedef struct MenuPartWork {
    u8 b0;            /* 0x00 */
    u8 pad1[3];
    s16 h4;           /* 0x04 */
    u16 h6;           /* 0x06: the layout index (fn_801B02F4) */
    u32 w8;           /* 0x08 */
    s32 wc;           /* 0x0C */
    s32 w10;          /* 0x10 */
    u8 pad14[0x1e - 0x14];
    u8 b1e;           /* 0x1E */
    u8 pad1f[0x44 - 0x1f];
    u32 w44;          /* 0x44 */
    void (*cb)(void* t); /* 0x48 */
    u8 pad4c[0x58 - 0x4c];
} MenuPartWork;
typedef struct CampStats_8030741C {
    u8 pad00[8];
    u8 b8[0x25 - 8];  /* 0x08 */
    u8 b25;           /* 0x25 */
    u8 pad26[2];
    s32 w28;          /* 0x28 */
    u8 pad2c[0x20c - 0x2c];
} CampStats_8030741C;
extern CampStats_8030741C lbl_8030741C;
extern u32 lbl_80347180;
extern u8 lbl_8034717C[2];

extern u32 lbl_802B6810[];
void UiSpritesFree(void);
void UiSpritesLoad(void* p);
extern char lbl_802B69D4[];
extern u8 lbl_802EBEA4[];
void fn_801BEB10(void* a, s32 b, s32 c, s32 d);
extern void fn_801DC214(void);
extern s32 fn_80248708(s32 slot, s32 a, s32 b);
extern s32 fn_801A6A04(s32 r);
extern void fn_801A4B40(void* a);
extern u8 *fn_80226670(u8 *obj, void *cb);
extern void *fn_801E1A74(s32 a, s32 b);
typedef struct Sub_UNIT0000 {
    u8 pad0[0x8];
    float f8;
    float fc;
    u8 pad1[0xa];
    u16 h1a;
} Sub_UNIT0000;
typedef struct Obj_UNIT0000 {
    u8 pad[0x30];
    Sub_UNIT0000 *sub;
} Obj_UNIT0000;
extern s32 lbl_80347508;
extern void fn_801A65D4(Task *t);
extern PadState *lbl_80311A60[];
extern s32 fn_801A6554(void *o);
extern void fn_801A64E0(void *o);
extern f32 fn_801DBD9C(f32 z);
extern void fn_80290ED4(VertexCol *v, s32 count, s32 flag);
extern void *fn_801A4DCC(void *a, u16 flag);
extern void fn_801CBBAC(f32 f);
extern void Ui2DBegin(void);
extern void *lbl_8034718C[2];
extern s32 lbl_80347184[2];
extern s32 CARDUnmount(s32 slot);
extern void strcpy(void *, const char *);
extern void strcat(void *, const char *);
extern char lbl_802B69C0[];
extern void *fn_801CC3C4(const char *path);
extern s16 fn_800ED8C4(void *p);
extern u8 lbl_8030B4D4[];
extern void fn_801ABA30(void* a);
extern f32 lbl_8034B96C;
extern f32 lbl_8034B8B0;
extern void TextSetColor(u32 colour);
typedef struct Obj_80199F58 {
    u8 pad0[0x94];
    void *p94;
    void *p98;
    s8 f9c;
    u8 pad9d[3];
    void *pa0;
    void *pa4;
    s8 fa8;
    u8 pada9[3];
    void *pac;
    void *pb0;
    s8 fb4;
    u8 padb5[3];
    u8 padb8[4];
    void *pbc;
} Obj_80199F58;
extern void *fn_801E1C7C(u32 size);
extern void fn_8019A15C(u8 *o, s8 a, s8 b, s8 c);
extern void *lbl_803470E8;
extern void *lbl_803470F0;
extern void fn_801A69BC();
extern void fn_801A6824(void *o);
extern void fn_80226DC4(void);
extern void Ui2DEnd(void);
extern s32 lbl_803473C4;
extern u32 lbl_80310B3C[];
typedef struct Ctx_8019E294 {
    u8 b0;
    u8 b1;
    u8 pad2[8];
    u8 ba;
} Ctx_8019E294;
typedef struct Self_8019E294 {
    u8 pad0[0x18];
    u8 flags18;
    u8 pad1[0xb];
    Ctx_8019E294 *ctx;
} Self_8019E294;
extern s32 fn_801A2670(s32 idx, s32 *out);
extern void fn_801A64B4(void *o, s32 k);
typedef struct Ctx_8019E650 {
    u8 pad0[4];
    u8 b4;
} Ctx_8019E650;
typedef struct Self_8019E650 {
    u8 pad0[0x19];
    u8 state19;
    u8 pad1[0xa];
    Ctx_8019E650 *ctx;
} Self_8019E650;
typedef struct Holder_8019FDB0 {
    u8 pad0[0x28];
    MenuPanel* ui;
} Holder_8019FDB0;
typedef struct Ctx_8019FDB0 {
    u8 pad0[8];
    u8 b8;
    u8 pad1[0x218 - 9];
    Holder_8019FDB0 *p218;
    Holder_8019FDB0 *p21c;
    Holder_8019FDB0 *p220;
    Holder_8019FDB0 *p224;
    Holder_8019FDB0 *p228;
} Ctx_8019FDB0;
typedef struct Self_8019FDB0 {
    u8 pad0[0x19];
    u8 state19;
    u8 pad1[0xa];
    Ctx_8019FDB0 *ctx;
} Self_8019FDB0;
/* A menu part task: the task and its panel. */
typedef struct Pnl {
    Task task;
    MenuPanel* obj; /* 0x28 */
} Pnl;
/* Save time stamp. */
typedef struct SaveStamp {
    u16 year;
    u8 month, day, hour, min, sec, wday;
} SaveStamp;
typedef struct CardStampBuf {
    SaveStamp stamp;
    u8 pad8[4];
} CardStampBuf;
/* A party member's position record (lbl_8030A794 + 0x38, and the save's copy of it). */
typedef struct PartyPos {
    f32 f[3];
    u32 w[3];
    s16 h;
    u8 pad1a[2];
} PartyPos;
typedef struct CardSaveData {
    char magic[0x10];  /* 0x00 lbl_802EBDD0 */
    SaveData data;     /* 0x10 */
    u32 x16b0;
    u8 x16b4;
    u8 pad16b5[0x16e8 - 0x16b5];
    PartyPos pos[2];   /* 0x16E8 */
    u8 pad1720[0x2370 - 0x1720];
    u8 blk2370[0xd58];
    u8 blk30c8[0x120];
    u16 x31e8;
    u16 x31ea;
    u32 x31ec;
    u8 pad31f0[2];
    u8 stamp[10];
    u32 sum;           /* 0x31FC: fn_801A4684 of the words before it */
} CardSaveData;
/* The 0x6000-byte card file image. */
typedef struct CardImage {
    u8 hdr[0x1440];
    CardSaveData save;
} CardImage;
/* The open card file (lbl_803081A4): its image, name and slot. */
typedef struct CardRec {
    CardImage *buf;
    char name[0x10];
    s32 w14;
    s32 chan;
    s32 w1c;
    SaveStamp stamp;
} CardRec;
/* A card slot's transfer progress (lbl_803081CC, one per slot). */
typedef struct CardXfer {
    u8 pad0[0xc];
    u32 done;        /* 0x0C */
    u32 total;       /* 0x10 */
    u32 busy;        /* 0x14 */
    u8 pad18[0x50 - 0x18];
} CardXfer;
extern CardXfer lbl_803081CC[2];
/* A save slot's summary, one per file (0x2C bytes). */
typedef struct {
    s32 f0;
    u16 h4;          /* 0x04 */
    u16 h6;          /* 0x06 */
    u32 w8;          /* 0x08 */
    s16 hc;          /* 0x0C */
    s8 fe[4];        /* 0x0E-0x11 */
    SaveStamp stamp; /* 0x12 */
    u8 pad[0x2c - 0x1a];
} E2c;
/* The save menu's work. */
typedef struct SaveWork {
    u8 x0;
    u8 f1;           /* 0x01 */
    u8 cnt;          /* 0x02 */
    u8 f3;           /* 0x03 */
    u8 sel;          /* 0x04 */
    u8 pad5[2];
    u8 f7;           /* 0x07 */
    u8 pad8;
    u8 f9;           /* 0x09 */
    u8 fa;           /* 0x0A */
    u8 padB;
    s32 fc;          /* 0x0C */
    u16 h10;         /* 0x10 */
    s16 h12;         /* 0x12 */
    s32 w14;         /* 0x14 files found */
    f32 f18;         /* 0x18 */
    f32 f1c;         /* 0x1C scan progress */
    E2c ent[10];     /* 0x20 */
    u8 pad_[0x20c - 0x20 - 10 * 0x2c];
    Pnl* p[17];      /* 0x20C */
    s32 w250;        /* 0x250 scan done */
    u8 pad254[4];
    CardRec* f258;   /* 0x258 */
    s32 st[2];       /* 0x25C: per slot */
    s32 w264;        /* 0x264 card bytes transferred (fn_801A4070) */
    s32 w268;        /* 0x268 */
    u8 pad26c[0x10];
} SaveWork;
typedef struct SaveTask {
    u8 pad[0x19];
    u8 state;        /* 0x19 */
    u8 pad1a[0x24 - 0x1a];
    SaveWork* w;     /* 0x24 */
} SaveTask;
extern void fn_801A6650(SaveTask *t, u16 i);
typedef struct Ctx_8019FE64 {
    u8 pad0[0x220];
    void *p220;
    void *p224;
    void *p228;
} Ctx_8019FE64;
typedef struct Self_8019FE64 {
    u8 pad0[0x19];
    u8 state19;
    u8 pad1[0xa];
    Ctx_8019FE64 *ctx;
} Self_8019FE64;
typedef struct Ctx_8019FF38 {
    u8 pad0[4];
    u8 b4;
    u8 pad1[0x218 - 5];
    Holder_8019FDB0 *p218;
    Holder_8019FDB0 *p21c;
} Ctx_8019FF38;
typedef struct Self_8019FF38 {
    u8 pad0[0x19];
    u8 state19;
    u8 pad1[0xa];
    Ctx_8019FF38 *ctx;
} Self_8019FF38;
extern void fn_801A47D8(void);
extern void fn_80227068(s32 a);
extern void fn_801A69DC(void);
extern void fn_801A686C(void *o);
extern void fn_801A68C4(void *o);
extern void *fn_801A4AF4(void *o);
extern void fn_801C09A4(void);
extern void fn_801CBC30(void);
extern void fn_801CBBD8(void);
extern void fn_801CBB9C(f32 f);
typedef struct Ctx_801A1834 {
    u8 b0;
    u8 b1;
    u8 pad2[0xe];
    u16 h10;
    u8 pad12[0x208 - 0x12];
    void *p208;
} Ctx_801A1834;
typedef struct Self_801A1834 {
    u8 pad0[0x19];
    u8 state19;
    u8 pad1[0xa];
    Ctx_801A1834 *ctx;
} Self_801A1834;
extern void* fn_802267AC(void* a, void *);
/* The card scan task's record (0x24 bytes). */
typedef struct Rec24 {
    u8 pad00[4];
    s32 w04;         /* 0x04 blocks per file */
    s32 w08;         /* 0x08 free file slots */
    s32 w0c;
    s32 w10;
    u8 b14;          /* 0x14 file index */
    u8 b15;
    u16 h16;
    u16 h18;
    u8 b1a;
    u8 b1b;
} Rec24;
/* The card scan task (fn_801A2D60, started by fn_801A343C). */
typedef struct Task_801A343C {
    u8 pad00[0x8];
    SaveTask* parent; /* 0x08 */
    u8 pad0c[0x18 - 0xc];
    u8 flags;         /* 0x18 */
    u8 state;         /* 0x19 */
    u8 pad1a[0x24 - 0x1a];
    Rec24* p24;
    struct CardImage* buf; /* 0x28 */
} Task_801A343C;
void fn_801A2D60(Task_801A343C* t);
typedef struct Actor24 {
    u8 pad00;
    u8 b01;
    u8 pad02[2];
    u8 b04;
    u8 pad05[0xD];
    s16 h12;
    s32 w14;
    u8 pad18[0x238];
    s32 w250;
} Actor24;
#define A24(p) ((Actor24 *)((Task_801A343C *)(p))->p24)
extern s32 fn_801A388C(s32 chan, const char *name, s32* out);
extern const char lbl_802B4978[];
extern const char lbl_8034B6A0[6];
extern void TPLReleasePalette(void* p);
extern void* lbl_8034716C;
extern void* lbl_80347168;
extern void* fn_801E1A74(s32 size, s32 n);
void fn_801A4E58(void *o);
typedef struct Ctl_801A4DCC {
    u8 pad00[0x8];
    void* p08;
    u8 pad0C[0xC];
    u8 b18;
    u8 b19;
    u8 pad1A[0xA];
    void* p24;
} Ctl_801A4DCC;
typedef struct Wk_801A4DCC {
    f32 f00;
} Wk_801A4DCC;
typedef struct Ctl_801A4E58 {
    u8 pad00[0x8];
    struct Ctl_801A4E58* p08;
    u8 pad0C[0xC];
    u8 b18;
    u8 b19;
    u8 pad1A[0xA];
    struct Wk_801A4E58* p24;
} Ctl_801A4E58;
typedef struct Wk_801A4E58 {
    f32 f00;
    u8 pad04[0x14];
    f32 f18;
} Wk_801A4E58;
typedef struct Task_801A5274 {
    u8 pad0[0x18];
    u8 flags;
    u8 state;
    u8 pad1a[0xa];
    u8 *flag;
    MenuPanel *pan;
} Task_801A5274;
extern LayoutPart lbl_802B4A00[2];
void fn_801A5274(Task_801A5274 *t);
typedef struct PanelTask_801ABD40 {
    u8 pad0[0x18];
    u8 flags;   /* 0x18 */
    u8 state;   /* 0x19 */
    u8 pad1A[0x24 - 0x1A];
    u8* flag;   /* 0x24 */
    MenuPanel* pan; /* 0x28 */
} PanelTask_801ABD40;
extern const char* lbl_80346810[2];
void fn_801ABD40(PanelTask_801ABD40* t);
extern void fn_801ABF70();
extern void fn_801B6BB4(void *ui, f32 *pos, s16 id, s32 b, s16 x, s16 y, f32 alpha);
extern const LayoutPart lbl_802B7720[4];
typedef struct Task_801B0F1C {
    u8 pad00[0x18];
    u8 flags;     /* 0x18 */
    u8 state;     /* 0x19 */
    u8 pad1a[0x24 - 0x1a];
    u8 *flag;     /* 0x24 */
    MenuPanel *pan;  /* 0x28 */
} Task_801B0F1C;
void fn_801B0F1C(Task_801B0F1C *t);
extern const char* fn_801F4AE4(s16 v);
/* A part's cursor (at the part task's 0x30): where it is drawn and the list position it points at. */
typedef struct ShopList {
    f32 x, y;    /* 0x00 draw position */
    f32 ox, oy;  /* 0x08 offset from the panel */
    f32 scale;   /* 0x10 pulse */
    u16 angle;   /* 0x14 */
    u8 pad16[2];
    u16 page;    /* 0x18 */
    u16 row;     /* 0x1A */
    u16 tab;     /* 0x1C selected tab */
    u8 part;     /* 0x1E layout part, 0xFF none */
    u8 flags;    /* 0x1F 1 shown, 2 pulsing */
} ShopList;
/* A part's arrow (at the part task's 0x38). */
typedef struct ShopSub38 {
    f32 x, y;    /* 0x00 */
    u16 idx;     /* 0x08 */
    u16 state;   /* 0x0A */
    u16 angle;   /* 0x0C */
    u16 padE;
    s32 f10;
    f32 scale;   /* 0x14 */
} ShopSub38;
/* A menu part task. */
typedef struct ShopPart {
    u8 pad0[0x18];
    u8 flags;        /* 0x18 */
    u8 state;        /* 0x19 */
    u8 pad1a[0xa];
    MenuPartWork* flag; /* 0x24 */
    MenuPanel* obj;      /* 0x28 */
    MenuPanel* obj2;     /* 0x2C */
    ShopList* list;  /* 0x30 */
    u8 pad34[4];
    ShopSub38* x38;  /* 0x38 */
} ShopPart;
/* A party member's record in the shop work (0x24 bytes). */
typedef struct ShopMember {
    const char* name; /* 0x00 */
    s8 id;            /* 0x04 */
    s8 b5, b6, b7;    /* 0x05 level and the two values shown after it */
    u8 pad8[2];
    s16 ha, hc, he;   /* 0x0A */
    s16 h10, h12;     /* 0x10 */
    u8 pad14[0x24 - 0x14];
} ShopMember;
typedef struct ShopChar {
    u8 pad0[0x6c];
    s16 h6c;
    u8 pad6e[0x2e];
} ShopChar;
/* One party member's stat row in the shop's character block (0xA8 bytes). */
typedef struct ShopRow {
    u8 pad0[6];
    s16 h6, h8, ha, hc, he, h10, h12, h14;
    u8 pad16[0xa8 - 0x16];
} ShopRow;
typedef struct ShopSave {
    ShopChar c[4];
    u8 pad270[0x2e8 - 0x270];
    ShopRow rows[4];
} ShopSave;
/* A sell tab's list: a count and the items' entries. */
typedef struct SellList {
    u32 n;
    s16* e[80];
} SellList;
typedef struct ShopWork {
    u8 pad0[3];
    u8 state;        /* 0x03 */
    s16 qty;         /* 0x04 */
    u16 item;        /* 0x06 */
    u8 pad8[1];
    u8 x9;           /* 0x09 */
    u8 xa;           /* 0x0A */
    u8 xb;           /* 0x0B */
    u8 xc[4];        /* 0x0C */
    s8 who[4];       /* 0x10 */
    s16 stat[4][4];  /* 0x14 */
    u8 b34;          /* 0x34 */
    u8 count;        /* 0x35 party size */
    u8 b36;          /* 0x36 */
    u8 b37;          /* 0x37 */
    ShopMember m[4];     /* 0x38: the party, in order */
    u8 padc8[0xd8 - 0xc8];
    struct { s16 v; u8 pad[8]; } d8[4]; /* 0xD8 */
    u8 pad100[0x10a - 0x100];
    s16 h10a[3];         /* 0x10A */
    u8 pad110[0x11c - 0x110];
    u32 cost;        /* 0x11C */
    u32 left;        /* 0x120 */
    u32 step;        /* 0x124 */
    u8 pad128[0xd0];
    ShopPart* parts[19]; /* 0x1F8 */
} ShopWork;
typedef struct ShopEntry {
    s8 flag;
    s8 type;
    s16 id;
    s16 key;
} ShopEntry;
typedef struct ShopBuf {
    u32 shop;
    u16 pages;
    u16 count;
    ShopEntry out[0x5a];
} ShopBuf;
typedef struct ShopTask {
    u8 pad0[0x19];
    u8 state;        /* 0x19 */
    u8 pad1a[0xa];
    ShopWork* w;     /* 0x24 */
    ShopSave* chr;   /* 0x28 */
    ShopBuf* buf;    /* 0x2C */
    SellList* sell;  /* 0x30: the five sell tabs' lists */
} ShopTask;
extern ShopTask* lbl_803471B8;
extern s32 fn_801B93E8(ShopTask* t);
struct Task_801B11EC;
extern void fn_801B11EC(struct Task_801B11EC* t);
extern void fn_801B5EA8();
void fn_801B6950(ShopPart* t);
typedef struct NamePair {
    const char* a;
    const char* b;
} NamePair;
extern const NamePair lbl_802EBFDC[8];
extern const char lbl_802B8F80[];
extern s8 lbl_80310A1C[0x120];
typedef struct Sub2 {
    u8 pad00[0x11C];
    u32 w11c;
    u8 pad120[4];
    u32 w124;
} Sub2;
typedef struct Task_801B8E68 {
    u8 pad00[0x24];
    Sub2* p24;
} Task_801B8E68;
extern void* lbl_803470EC;
extern void* lbl_803470F4;
typedef struct TexMdl_8019CB80 {
    NJS_TEXLIST* texlist;
    void* model;
} TexMdl_8019CB80;
typedef struct St {
    u8 pad00[4];
    TexMdl_8019CB80 x4;
    f32 xc, x10, x14;
    s32 x18, x1c, x20;
    f32 x24, x28, x2c; /* scale */
    f32 x30, x34, x38;
    s32 x3c, x40, x44;
    f32 x48, x4c;
    s32 x50;
} St;
typedef struct Sub { u8 pad[0x18]; u8 flags; } Sub;
typedef struct Obj_8019CB80 {
    u8 pad00[8];
    Sub* x8;
    u8 pad0c[0x18 - 0x0c];
    u8 flags;
    u8 state;
    u8 pad1a[0x24 - 0x1a];
    St* st;
} Obj_8019CB80;
extern void fn_800906E8(void*);
typedef struct MP { u8 pad[0x28]; MenuPanel* obj; } MP;
typedef struct Ctx_801A0B18 {
    u8 pad00[4];
    u8 idx;           /* 0x04 */
    u8 pad05[4];
    u8 x9;            /* 0x09 */
    u8 pad0a[0x18 - 0x0a];
    f32 x18;
    u8 pad1c[0x210 - 0x1c];
    MP* x210;
    u8 pad214[0x25c - 0x214];
    s32 slot[1];      /* 0x25c */
} Ctx_801A0B18;
typedef struct Self_801A0B18 {
    u8 pad00[0x19];
    u8 state;
    u8 pad1a[0x24 - 0x1a];
    Ctx_801A0B18* ctx;
} Self_801A0B18;
extern s32 fn_801A28AC(s32 i);
extern int fn_801A6A58(int sub, int idx);
extern s32 fn_801A6554(void* o);
typedef struct Ctx_801A1494 {
    u8 pad00;
    u8 x1;
    u8 x2;
    u8 x3;
    u8 pad04[0x25c - 4];
    s32 slot[2];      /* 0x25c */
} Ctx_801A1494;
typedef struct Self_801A1494 {
    u8 pad00[0x19];
    u8 state;
    u8 pad1a[0x24 - 0x1a];
    Ctx_801A1494* ctx;
} Self_801A1494;

extern void fn_801A64E0(void* o);
extern s32 SpriteObjDrawScaled(SpriteObjScaled* obj);
typedef struct CardStat {
    char fileName[0x20];
    u32 length;
    u32 time;
    u32 gameName;     /* 0x28 */
    u16 company;      /* 0x2c */
    u8 bannerFormat;
    u8 pad2f;
    u32 iconAddr;     /* 0x30 */
    u16 iconFormat;
    u16 iconSpeed;
    u32 commentAddr;  /* 0x38 */
    u8 rest[0x30];
} CardStat;           /* 0x6C */
extern CardStat lbl_803080F8;
extern s32 CARDGetStatus(s32 chan, s32 fileNo, CardStat* stat);
extern char *strstr(const char *str, const char *pat);
typedef struct Misc {
    u32 x0;
    u32 x4;
    u8 x8;
} Misc;
typedef struct Flt {
    u8 pad00[0x38];
    PartyPos pos[2];
} Flt;
extern char lbl_802EBDD0[0x10];
extern Misc lbl_80311AC0;
extern Flt lbl_8030A794;
extern void* fn_801E1A74(s32 a, s32 size);
typedef struct Ent {
    u8 pad00[2];
    u8 flag2;
    u8 pad03[5];
    u32 x8;
    u8 pad0c[0x23 - 0xc];
    u8 flag23;
} Ent;
typedef struct Pair_801A49E0 {
    Ent* a;
    Ent* b;
} Pair_801A49E0;
typedef struct Hdr_801A49E0 {
    u32 magic;
    u32 count;
    Pair_801A49E0* table;
} Hdr_801A49E0;
extern char lbl_802B49C4[];
extern char lbl_802B49D0[];
extern void OSPanic(const char* file, int line, const char* msg, ...);
typedef struct Node {
    u8 pad00[0x24];
    MenuPartWork* w;       /* 0x24 */
    MenuPanel* obj;    /* 0x28 */
    u32 x2c;           /* 0x2C */
} Node;
void fn_801A66AC(Node *t);
extern const char lbl_80346808[4];
extern const char lbl_8034680C[3];
typedef struct Ctx_801A5D08 {
    u8 pad0[0x18];
    f32 f18;
} Ctx_801A5D08;
typedef struct Parent_801A5D08 {
    u8 pad0[0x24];
    Ctx_801A5D08 *ctx;
} Parent_801A5D08;
typedef struct Task_801A5D08 {
    u8 pad0[8];
    Parent_801A5D08 *parent;
    u8 pad0c[0xc];
    u8 flags;
    u8 state;
    u8 pad1a[0xa];
    u8 *flag;
    MenuPanel *pan;
} Task_801A5D08;
extern LayoutPart lbl_802B4B88[1];
extern LayoutPart lbl_802B4B4C[3];
void fn_801A5D08(Task_801A5D08 *t);
typedef Node SlotTask;
extern void* fn_801E1A74(s32 n, s32 size);
extern void fn_801A5FD8(void);
extern LayoutPart lbl_802B4A28[3];
void fn_801A6344(Task_801A5D08 *t);
typedef struct {
    u8 pad0[0x10];
    u16 id;       /* 0x10 */
    u8 pad12[0x1D8 - 0x12];
    s32 f1D8;
    u16 f1DC;
    u16 f1DE;
    s32 f1E0;
    s16 f1E4;
    u8 b1E6, b1E7, b1E8, b1E9;
} ElemA;
typedef struct {
    u8 pad0[0x1B];
    s8 f1B;
    u8 pad1C[0x338 - 0x1C];
    u8 b338, b339, b33A, b33B;
    u8 pad33C[0x31E8 - 0x33C];
    u16 f31E8;
    u16 f31EA;
    s32 f31EC;
} ElemB;
typedef struct {
    u8 pad[0x24];
    ElemA* a;
    ElemB* b;
} ElemTask;
extern void* fn_801A456C(void);
extern s8 fn_801F4CA0(void);
typedef struct {
    u8 pad0[0x18];
    u8 flags;   /* 0x18 */
    u8 state;   /* 0x19 */
    u8 pad1A[0x24 - 0x1A];
    u8* flag;   /* 0x24 */
    MenuPanel* ui;  /* 0x28 */
} PanelTask_801ABF70;
extern const LayoutPart lbl_802B7C14[4];
void fn_801C3F5C(f32 x, f32 y, f32 z);
void fn_801AC48C(ShopPart* t);
typedef struct PanelTask_801AFAA4 PanelTask_801AFAA4;
typedef struct {
    const LayoutPart* parts;
    u32 count;
} LayoutDef;
typedef struct {
    u8 flag;       /* 0x00 */
    u8 pad1[0x48 - 1];
    void (*cb)(PanelTask_801AFAA4*); /* 0x48 */
} PanelData_801AFAA4;
struct PanelTask_801AFAA4 {
    u8 pad0[0x18];
    u8 flags;
    u8 state;
    u8 pad1A[0x24 - 0x1A];
    PanelData_801AFAA4* data;
    MenuPanel* pan;
};
extern const LayoutDef lbl_802B79E4[2];
extern const LayoutPart lbl_802B77AC[1];
typedef struct {
    u8 b0;           /* 0x00 */
    u8 pad1[5];
    u16 s6;          /* 0x06 */
    u8 pad8[0x48 - 8];
    void* cb;        /* 0x48 */
} PanelData_801B0470;
typedef struct {
    u8 pad[0x24];
    PanelData_801B0470* data; /* 0x24 */
    MenuPanel* pan;      /* 0x28 */
    s32 f2C;
} Task2_801B0470;
void fn_801B02F4(ShopPart* t);
extern const char* lbl_802EBF60[7];
void fn_801B0B9C(ShopPart* t);
typedef struct {
    u8 pad0[8];
    s16 s8;
    s16 sA;
} BufD;
typedef struct {
    u8 pad0[0x18];
    s16 s18;
    s16 s1A;
    s16 s1C;
    u8 b1E;
    u8 b1F;
} BufC_801B2310;
typedef struct {
    u8 pad[0x24];
    u8* a;       /* 0x24 */
    MenuPanel* pan;  /* 0x28 */
    s32 f2C;
    BufC_801B2310* c;     /* 0x30 */
    u8 pad34[4];
    BufD* d;     /* 0x38 */
} Task3_801B2310;
ShopPart;
extern void fn_801B1B3C(ShopPart* t);
typedef struct {
    u8 pad[0x24];
    u8* a;       /* 0x24 */
    MenuPanel* pan;  /* 0x28 */
    s32 f2C;
} Task2_801B2678;
extern void UiDrawNumber(NJS_POINT3 *pos, u32 flags, u16 ndigits, u32 value, f32 c1);
extern const LayoutPart lbl_802B6DF8[4];
void fn_801B2430(Task_801B0F1C *t);
extern const char* lbl_802EC04C[13];
typedef struct {
    u8 pad0[0x1E];
    u8 b1E;
    u8 b1F;
} BufC_801B5C4C;
typedef struct {
    u8 pad[0x24];
    u8* a;       /* 0x24 */
    MenuPanel* pan;  /* 0x28 */
    s32 f2C;
    BufC_801B5C4C* c;     /* 0x30 */
    u8 pad34[4];
    BufD* d;     /* 0x38 */
} Task3_801B5C4C;
extern void fn_801B58E0(void);
typedef struct {
    LayoutPart* parts; /* 0x00 */
    u32 count;
    u16 p8;
    u16 p6;
    u32 pc;
} Dummy;
typedef struct {
    const LayoutPart* parts; /* 0x00 */
    u16 pad4;
    u16 flag6;         /* 0x06 */
    u32 pad8, padC;
} AnimDef;
extern const AnimDef lbl_802B73A4[5];
f32 njSin(u16 a);
extern const LayoutPart lbl_802B6DD0[2];
void fn_801B6E5C(PanelTask_801ABF70* t);
extern const LayoutPart lbl_802B6B0C[4];
extern s32 lbl_803475D8;
void MenuDummy();
typedef struct {
    u8 pad[0x24];
    u8* a;       /* 0x24 */
    MenuPanel* pan;  /* 0x28 */
} Task2_801B6838;
typedef struct {
    const char* label;
    u32 pad[3];
} Entry10;
extern void fn_801B66F8();
extern Entry10 lbl_802ED218[4];
extern u8 lbl_803473BF;
extern u16 lbl_803473BC;
extern const char* lbl_802EBF7C[16];
extern u32 lbl_802EBFBC[8];
extern char lbl_802B8F94[];
extern char lbl_802B8F70[];
typedef struct {
    u8 pad0[0x20];
    s32 *a0;
    f32 *f0;
    u8 pad28[4];
    s32 *a1;
    f32 *f1;
    u8 pad34[4];
    s32 *a2;
    f32 *f2;
} PosTabs;
typedef struct Sub_8019B44C {
    s32 mode;
    u8 pad4[4];
    void *w8;
} Sub_8019B44C;
typedef struct Ctx_8019B44C {
    s32 w0;
    u8 pad4[4];
    u8 ui[0xb4];
    Sub_8019B44C *pbc;
} Ctx_8019B44C;
typedef struct Self_8019B44C {
    u8 pad0[0x18];
    u8 flags18;
    u8 state19;
    u8 pad1a[0xa];
    Ctx_8019B44C *ctx;
} Self_8019B44C;
typedef struct P2 {
    void *p0;
    void *p4;
} P2;
typedef struct Obj48 {
    f32 f00, f04;
    s32 i08;
    s32 i0c;
    f32 f10, f14, f18, f1c;
    P2 *p20;
    F4 *p24;
    u8 pad28[4];
    P2 *p2c;
    F4 *p30;
    u8 pad34[0x10];
    void *p44;
} Obj48;
typedef struct Ctx_8019E96C {
    u8 pad0[4];
    u8 b4;
    u8 pad5[3];
    u8 b8;
    u8 pad9[0x217];
    Holder_8019FDB0 *p220;
    Holder_8019FDB0 *p224;
    u8 pad228[0x34];
    s32 w25c[1];
} Ctx_8019E96C;
typedef struct Self_8019E96C {
    u8 pad0[0x19];
    u8 state19;
    u8 pad1a[0xa];
    Ctx_8019E96C *ctx;
} Self_8019E96C;
extern s32 fn_801A28AC(s32 obj);
typedef struct Ctx_8019EE4C {
    u8 pad0[4];
    u8 b4;
    u8 pad5[4];
    u8 b9;
    u8 pad9[2];
    s32 wc;
    u8 pad10[8];
    f32 f18;
    u8 pad1c[0x1f4];
    Holder_8019FDB0 *p210;
    u8 pad214[0x44];
    s32 w258;
    s32 w25c[8];
} Ctx_8019EE4C;
typedef struct Self_8019EE4C {
    u8 pad0[0x19];
    u8 state19;
    u8 pad1a[0xa];
    Ctx_8019EE4C *ctx;
} Self_8019EE4C;
extern s32 lbl_803475D0;
extern s32 lbl_803475E0;
s32 fn_801A4070(SaveTask *t);
void fn_801A4060(SaveTask *t);
void fn_801A41C0(CardRec *rec);
extern s32 fn_801A3A10(u8 slot, SaveTask *t);
void fn_801A2D20(SaveTask *t, u32 a, u32 b);
u32 fn_801A4684(void *buf, u32 size);
extern void fn_801A4354(CardSaveData *p);
typedef struct Ctx_801A0214 {
    u8 pad0[4];
    u8 b4;
    u8 pad5[4];
    u8 b9;
    u8 pad9[0xe];
    f32 f18;
    u8 pad1c[0x1f0];
    Holder_8019FDB0 *h[20];
    s32 w25c[8];
} Ctx_801A0214;
typedef struct Self_801A0214 {
    u8 pad0[0x19];
    u8 state19;
    u8 pad1a[0xa];
    Ctx_801A0214 *ctx;
} Self_801A0214;
/* A save menu file panel task: its parent is the save menu task. */
typedef struct Task_801A54AC {
    u8 pad0[8];
    SaveTask *parent;
    u8 pad0c[0xc];
    u8 flags;
    u8 state;
    u8 pad1a[0xa];
    u8 *flag;
    MenuPanel *pan;
} Task_801A54AC;
extern LayoutPart lbl_802B4B9C[6];
void fn_801A5600(Task_801A54AC *t);
extern void fn_801A58A0(Task_801A54AC *t, E2c *e);
extern char lbl_802EBE08[];
extern LayoutPart lbl_802B4C14[];
#define TextPrintNumber TextPrintNumber_hdr
#undef TextPrintNumber
typedef struct Ctx_801A6A88 {
    u8 pad0[4];
    s16 h4;
    u8 pad6[0x1f2];
    Holder_8019FDB0 *h[8];
} Ctx_801A6A88;
typedef struct Task_801A6A88 {
    u8 pad0[0x24];
    Ctx_801A6A88 *ctx;
} Task_801A6A88;
typedef struct Buf_801AB580 {
    u8 pad0[4];
    s16 pages;
    s16 count;
    ShopEntry out[0x30];
} Buf_801AB580;
typedef struct Self_801AB580 {
    u8 pad0[0x2c];
    Buf_801AB580 *buf;
} Self_801AB580;
extern s32 fn_801F4C24(s16 id);
extern u16 fn_801F477C(s16 id);
extern s8 fn_801F452C(s16 id);
#define MenuDummy MenuDummy_hdr
#undef MenuDummy
typedef struct { u8 pad[0x28]; MenuPanel* obj; MenuPanel* obj2; } MP2;
typedef struct ShopCmpPos {
    f32 x, y;
} ShopCmpPos;
/* .rodata 0x802B6A18-0x802B8EDC of the original (generated by tools/match/gen_rodata.py from the DOL).
 * Objects are sized to the next one, padding included. */
extern const LayoutPart lbl_802B6BAC[4];
extern const LayoutPart lbl_802B6BFC[4];
extern const LayoutPart lbl_802B6C4C[4];
extern const LayoutPart lbl_802B6C9C[4];
extern const LayoutPart lbl_802B6CEC[4];
extern const LayoutPart lbl_802B6D3C[4];
extern const LayoutPart lbl_802B6F38[10];
extern const LayoutPart lbl_802B7000[6];
extern const LayoutPart lbl_802B7078[7];
extern const LayoutPart lbl_802B7104[3];
extern const LayoutPart lbl_802B7228[2];
extern const LayoutPart lbl_802B7250[2];
extern const LayoutPart lbl_802B7278[2];
extern const LayoutPart lbl_802B72A0[2];
extern const LayoutPart lbl_802B72C8[2];
extern const LayoutPart lbl_802B732C[2];
extern const LayoutPart lbl_802B7354[2];
extern const LayoutPart lbl_802B737C[2];
extern const LayoutPart lbl_802B73F4[4];
extern const LayoutPart lbl_802B7444[11];
extern const LayoutPart lbl_802B7520[8];
extern const LayoutPart lbl_802B75C0[16];
extern const LayoutPart lbl_802B7770[3];
extern const LayoutPart lbl_802B77C0[3];
extern const LayoutPart lbl_802B78CC[7];
extern const LayoutPart lbl_802B7958[7];
extern const LayoutPart lbl_802B7A30[2];
extern const LayoutPart lbl_802B7A58[2];
extern const LayoutPart lbl_802B7A80[2];
extern const LayoutPart lbl_802B7AA8[2];
extern const LayoutPart lbl_802B7AD0[2];
extern const LayoutPart lbl_802B7AF8[2];
extern const u32 lbl_802B6A18[19];
extern const LayoutPart lbl_802B6A64[7];
extern const u32 lbl_802B6AF0[4];
extern const u32 lbl_802B6B00[3];
extern const LayoutPart lbl_802B6B0C[4];
extern const LayoutPart lbl_802B6B5C[4];
extern const LayoutPart lbl_802B6BAC[4];
extern const LayoutPart lbl_802B6BFC[4];
extern const LayoutPart lbl_802B6C4C[4];
extern const LayoutPart lbl_802B6C9C[4];
extern const LayoutPart lbl_802B6CEC[4];
extern const LayoutPart lbl_802B6D3C[4];
extern const LayoutPart lbl_802B6D8C[1];
extern const LayoutDef lbl_802B6DA0[6];
extern const LayoutPart lbl_802B6DD0[2];
extern const LayoutPart lbl_802B6DF8[4];
extern const LayoutPart lbl_802B6E48[8];
extern const LayoutPart lbl_802B6EE8[4];
extern const LayoutPart lbl_802B6F38[10];
extern const LayoutPart lbl_802B7000[6];
extern const LayoutPart lbl_802B7078[7];
extern const LayoutPart lbl_802B7104[3];
extern const LayoutPart lbl_802B7140[2];
extern const LayoutPart lbl_802B7168[1];
extern const LayoutDef lbl_802B717C[4];
extern const LayoutPart lbl_802B719C[4];
extern const LayoutPart lbl_802B71EC[3];
extern const LayoutPart lbl_802B7228[2];
extern const LayoutPart lbl_802B7250[2];
extern const LayoutPart lbl_802B7278[2];
extern const LayoutPart lbl_802B72A0[2];
extern const LayoutPart lbl_802B72C8[2];
extern const LayoutPart lbl_802B72F0[1];
extern const LayoutDef lbl_802B7304[5];
extern const LayoutPart lbl_802B732C[2];
extern const LayoutPart lbl_802B7354[2];
extern const LayoutPart lbl_802B737C[2];
extern const AnimDef lbl_802B73A4[5];
extern const LayoutPart lbl_802B73F4[4];
extern const LayoutPart lbl_802B7444[11];
extern const LayoutPart lbl_802B7520[8];
extern const LayoutPart lbl_802B75C0[16];
extern const LayoutDef lbl_802B7700[4];
extern const LayoutPart lbl_802B7720[4];
extern const LayoutPart lbl_802B7770[3];
extern const LayoutPart lbl_802B77AC[1];
extern const LayoutPart lbl_802B77C0[3];
extern const LayoutPart lbl_802B77FC[7];
extern const u32 lbl_802B7888[3];
extern const LayoutDef lbl_802B7894[7];
extern const LayoutPart lbl_802B78CC[7];
extern const LayoutPart lbl_802B7958[7];
extern const LayoutDef lbl_802B79E4[2];
extern const LayoutPart lbl_802B79F4[3];
extern const LayoutPart lbl_802B7A30[2];
extern const LayoutPart lbl_802B7A58[2];
extern const LayoutPart lbl_802B7A80[2];
extern const LayoutPart lbl_802B7AA8[2];
extern const LayoutPart lbl_802B7AD0[2];
extern const LayoutPart lbl_802B7AF8[2];
extern const LayoutDef lbl_802B7B20[6];
extern const LayoutPart lbl_802B7B50[1];
extern const LayoutDef lbl_802B7B64[6];
extern const LayoutDef lbl_802B7B94[6];
extern const LayoutPart lbl_802B7BC4[3];
extern const LayoutPart lbl_802B7C00[1];
extern const LayoutPart lbl_802B7C14[4];
extern const char lbl_802B7C64[0x1C];
extern const char lbl_802B7C80[0x18];
extern const char lbl_802B7C98[0x10];
extern const char lbl_802B7CA8[0x14];
extern const char lbl_802B7CBC[0x14];
extern const char lbl_802B7CD0[0x18];
extern const char lbl_802B7CE8[0x18];
extern const char lbl_802B7D00[0x14];
extern const char lbl_802B7D14[0x30];
extern const char lbl_802B7D44[0x2C];
extern const char lbl_802B7D70[0x30];
extern const char lbl_802B7DA0[0x30];
extern const char lbl_802B7DD0[0x30];
extern const char lbl_802B7E00[0x34];
extern const char lbl_802B7E34[0x30];
extern const char lbl_802B7E64[0x2C];
extern const char lbl_802B7E90[0xF8];
extern const char lbl_802B7F88[0xEC];
extern const char lbl_802B8074[0xF8];
extern const char lbl_802B816C[0xF8];
extern const char lbl_802B8264[0xF8];
extern const char lbl_802B835C[0xD8];
extern const char lbl_802B8434[0xF4];
extern const char lbl_802B8528[0xF0];
extern const char lbl_802B8618[0xF4];
extern const char lbl_802B870C[0xFC];
extern const char lbl_802B8808[0xDC];
extern const char lbl_802B88E4[0xDC];
extern const char lbl_802B89C0[0xFC];
extern const char lbl_802B8ABC[0xF4];
extern const char lbl_802B8BB0[0xF4];
extern const char lbl_802B8CA4[0xB8];
extern const char lbl_802B8D5C[0xC];
extern const char lbl_802B8D68[0xC];
extern const char lbl_802B8D74[0xC];
extern const char lbl_802B8D80[0x14];
extern const char lbl_802B8D94[0x14];
extern const char lbl_802B8DA8[0x14];
extern const char lbl_802B8DBC[0x10];
extern const char lbl_802B8DCC[0x14];
extern const char lbl_802B8DE0[0x10];
extern const char lbl_802B8DF0[0x10];
extern const char lbl_802B8E00[0x10];
extern const char lbl_802B8E10[0x10];
extern const u32 lbl_802B8E20[5];
extern const u32 lbl_802B8E34[6];
extern const ShopCmpPos lbl_802B8E4C[14];
extern const s16 lbl_802B8EBC[8];
extern const s16 lbl_802B8ECC[8];
typedef struct { u8 pad[0x10]; u32 v; } W;
void fn_801B277C(Task* t);
typedef struct { u8 pad[0x24]; MenuPartWork* w; MenuPanel* obj; MenuPanel* obj2; u8 pad30[0xC]; void* p3c; } T_801B54D4;
typedef struct { f32 a, b; } FP;
typedef struct { s16 id; s8 count; s8 pad; } Ent_801B9810;
extern u8 fn_801F464C(s32 id);
extern u16 fn_801B995C(s32 id);
typedef struct { u8 pad0[0x2c]; f32 x, y; u8 pad34[0x74 - 0x34]; f32 z; } Obj_8019B980;
typedef struct { u8 pad0[0x18]; u8 flags; } Par_8019D168;
typedef struct { s32 ready; } Sig_8019D168;
typedef struct {
    u8 pad0[8];
    f32 f8;
    u8 pad0c[4];
    f32 f10;
    u8 pad14[4];
    s32 w18;
    u8 pad1c[4];
    f32 f20, f24, f28, f2c;
    u8 pad30[4];
    f32 f34, f38, f3c;
    s32 w40, w44, w48;
    Sig_8019D168 *sig;
    s32 w50;
} Dat_8019D168;
typedef struct {
    u8 pad0[8];
    Par_8019D168 *par;
    u8 pad0c[0x18 - 0xc];
    u8 flags;
    u8 state;
    u8 pad1a[0x24 - 0x1a];
    Dat_8019D168 *dat;
} Obj_8019D168;
typedef struct Key_801A1DB4 { u16 a; u8 b[6]; u8 c; u8 pad; } Key_801A1DB4;
extern s32 fn_8000743C(Key_801A1DB4 *a, Key_801A1DB4 *b);
typedef struct Item_801A1DB4 {
    u8 pad00[0xc];
    s32 kind;
    u8 pad10[0x1e - 0x10];
    u16 h32;
    u8 b34[6];
    u8 pad26[0x2c - 0x26];
} Item_801A1DB4;
typedef struct Ctx_801A1DB4 {
    u8 pad00[5];
    u8 x5;
    u8 x6;
    u8 x7;
} Ctx_801A1DB4;
typedef struct Self_801A1DB4 {
    u8 pad00[0x24];
    Ctx_801A1DB4 *ctx;
} Self_801A1DB4;
typedef struct Sub_801AB328 {
    u8 pad00[0x24];
    MenuPartWork *flag;   /* 0x24 */
    MenuPanel* obj;            /* 0x28 */
    u8 pad2c[4];
    MenuPartWork *flag30; /* 0x30 */
} Sub_801AB328;
typedef struct Ctx_801AB328 {
    u8 pad00[0x1f8];
    Sub_801AB328 *x1f8;
    Sub_801AB328 *x1fc;
    u8 pad200[4];
    Sub_801AB328 *x204;
    u8 pad208[0x214 - 0x208];
    Sub_801AB328 *x214;
    Sub_801AB328 *x218;
    Sub_801AB328 *x21c;
} Ctx_801AB328;
typedef struct Self_801AB328 {
    u8 pad00[0x24];
    Ctx_801AB328 *ctx;
} Self_801AB328;
typedef struct Sub_801A0FD8 { u8 pad[0x19]; u8 x19; u8 pad1a[0x28 - 0x1a]; MenuPanel* obj; } Sub_801A0FD8;
typedef struct Ctx_801A0FD8 {
    u8 pad00[1];
    u8 x1;
    u8 pad02[2];
    u8 idx;           /* 0x04 */
    u8 x5;
    u8 x6;
    u8 x7;
    u8 pad08;
    u8 x9;
    u8 pad0a[0x14 - 0x0a];
    u32 x14;
    f32 x18;
    f32 x1c;
    u8 pad20[0x20c - 0x20];
    Sub_801A0FD8 *objs[8];   /* 0x20c */
    u8 pad22c[0x250 - 0x22c];
    s32 x250;
    u8 pad254[0x25c - 0x254];
    s32 slot[1];      /* 0x25c */
    u8 pad260[0x26c - 0x260];
    u8 x26c;
} Ctx_801A0FD8;
typedef struct Self_801A0FD8 {
    u8 pad00[0x19];
    u8 state;
    u8 pad1a[0x24 - 0x1a];
    Ctx_801A0FD8 *ctx;
} Self_801A0FD8;
extern void UiObjMoveToY(UiObj *o, u16 frames, s16 se, f32 y);
typedef struct { void* a; void* b; void* c; u16 xc;
 u8 lo;
 u8 hi;
 s32 f10;
 s32 f14;
 s32 f18;
 s32 f1c;
 s32 f20;
 s32 f24; } Ent_801AC2E4;
extern Ent_801AC2E4 lbl_802ED258[];
extern s8 fn_801BE608(s16 x);
void fn_801AC16C(Task* task);
typedef struct { u8 pad[0x24]; u8* w; MenuPanel* obj; u32 x2c; } T;
typedef Node Sub_801A0C3C;
typedef struct SaveItem_801A0C3C { s32 kind; u8 rest[0x2c - 4]; } SaveItem_801A0C3C;
typedef struct Ctx_801A0C3C {
    u8 pad00[1];
    u8 x1;
    u8 x2;
    u8 x3;
    u8 idx;           /* 0x04 */
    u8 x5;
    u8 x6;
    u8 x7;
    u8 x8;
    u8 x9;
    u8 pad0a[2];
    s32 xc;           /* 0x0c */
    u8 pad10[4];
    u32 x14;
    f32 x18;
    f32 x1c;
    SaveItem_801A0C3C items[10]; /* 0x20 */
    u8 pad1d8[0x1e0 - 0x1d8];
    s32 x1e0;
    u8 pad1e4[0x1ea - 0x1e4];
    SaveStamp stamp;  /* 0x1ea */
    u8 pad1f2[0x20c - 0x1f2];
    Sub_801A0C3C *objs[14];   /* 0x20c */
    u8 pad244[0x250 - 0x244];
    s32 x250;
    u8 pad254[0x25c - 0x254];
    s32 slot[2];      /* 0x25c */
    u8 pad264[0x26c - 0x264];
    u8 x26c;
} Ctx_801A0C3C;
typedef struct Self_801A0C3C {
    u8 pad00[0x19];
    u8 state;
    u8 pad1a[0x24 - 0x1a];
    Ctx_801A0C3C *ctx;
    CardSaveData *data;  /* 0x28 */
} Self_801A0C3C;
extern Sub_801A0C3C *fn_801A53D4(void *o, u16 idx);
extern const f32 lbl_802B4920[11];
typedef struct Ent_801A1B98 { u8 idx; u8 b1; u8 b2; u8 b3; u8 b4; u8 b5; } Ent_801A1B98;
extern const Ent_801A1B98 lbl_802B494C[7];
void fn_801A1B98(Self_801A0C3C *o, u8 mode);
/* Memory-card state reset. lbl_80347170 is a 2-entry per-slot table (fn_801A28F4 fills
 * both entries), lbl_80347178 a slot bit mask. The original stores entry 0 twice; the
 * store to lbl_80347178 has to come first in the source for the scheduler to keep 1 in r0
 * and 0 in r3. (Equivalent match: `for (i = 0; i < 2; i++) lbl_80347170[0] = 1;` after the
 * mask store, i.e. a slot loop that forgot its index.) */
extern int lbl_80347170[2];
extern int lbl_80347178;
extern const u32 lbl_8034BAC0[];
extern u8 lbl_803473BE;
extern s32 fn_801A3B30(SaveTask* t, s32* out);
extern s32 MenuPlaySe(s16 se);

extern s32 fn_801C09F8(s32 a, s32 b);
extern void fn_801A20AC(SaveTask* t);
typedef struct St_801B737C { u8 pad[0x64]; s8 seen[8]; } St_801B737C;
typedef struct Fl { u8 pad[4]; u32 f4; u8 pad8[0x18 - 8]; u32 f18; u32 f1c; u8 pad20[0x30 - 0x20]; u32 f30; u8 pad34[0x168 - 0x34]; u32 f168; u8 pad16c[4]; u32 f170; } Fl;
typedef struct UiObj UiObj;
extern void UiObjSetCommand(UiObj* obj, u16 cmd, u16 delay);
typedef struct Menu { u8 pad[0xA]; u8 cur; u8 pad2[0x230-0xB]; MP* slot[5]; } Menu;
typedef struct Task_801AB094 { u8 pad[0x24]; Menu* m; } Task_801AB094;
typedef struct Ctx_801A0E7C {
    u8 pad0[4];
    u8 b4;
    u8 b5;
    u8 b6;
    u8 b7;
    u8 pad8;
    u8 b9;
    u8 pad9[0xe];
    f32 f18;
    u8 pad1c[0x1f0];
    Holder_8019FDB0 *h[20];
    s32 w25c[8];
} Ctx_801A0E7C;
typedef struct Self_801A0E7C {
    u8 pad0[0x19];
    u8 state19;
    u8 pad1a[0xa];
    Ctx_801A0E7C *ctx;
} Self_801A0E7C;
extern void *fn_801A343C(Task_801A343C *a);
extern void fn_801E17E0(void *p);
extern void fn_801A2C58(void);
extern void fn_801A2CC4(void);
extern s32 fn_80248DCC(s32 chan, void *work, void (*cb)(void), s32 f);
extern s32 CARDGetResultCode(s32 chan);
extern s32 CARDCheckExAsync(s32 chan, s32 *xfer, void *cb);
extern CardStampBuf lbl_80308198;
extern CardRec lbl_803081A4;
extern void *memcpy(void *, const void *, u32);
extern void *memset(void *, s32, u32);
extern s32 fn_801C0B88(s16 id, u8 slot);
typedef struct PanelTask_801AFBE8 {
    u8 pad[0x24];
    MenuPartWork* w;   /* 0x24 */
    MenuPanel* obj; /* 0x28 */
    u32 x2c;
} PanelTask_801AFBE8;
typedef struct PanelPos {
    f32 y;
    f32 z;
} PanelPos;
extern const PanelPos lbl_802B8F20[];
extern void fn_801AFD34(void *t);
extern void fn_801B0014(void *t);
typedef struct { u8 pad[0x18]; f32 f18; } Inner_801A4B40;
typedef struct { u8 pad0[0x18]; u8 flags; u8 pad19[0x24 - 0x19]; Inner_801A4B40* in; } Par_801A4B40;
typedef struct { u8 pad0[8]; Par_801A4B40* par; u8 pad_[0x18 - 0xc]; u8 flags; u8 state; } Tsk_801A4B40;
extern void SpriteObjDraw(SpriteObj* obj);
extern void SpriteObjDrawAt(SpriteObj* obj, f32* pos);
void SpriteObjDrawAtEx(SpriteObj* obj, f32* pos);
typedef struct Ent_801ABA30 { u8 pad[8]; Sub* sub; u8 pad2[0x18-0xc]; u8 flags; u8 mode; } Ent_801ABA30;
typedef struct {
    NJS_TEXLIST* texlist;   /* 0x00 */
    u8 pad4[0x64 - 4];
    NJS_POINT3 pos;        /* 0x64 */
    u8 pad70[4];
    s32 w74;               /* 0x74 */
    u8 pad78[4];
    f32 x7c, x80, x84;
    s32 x88;
} Data;
typedef struct {
    u8 pad[8];
    Sub* parent;
    u8 pad0c[0xc];
    u8 flags;
    u8 state;
    u8 pad1a[0xa];
    Data* data;
    u8 pad28[0x40 - 0x28];
    Data buf;           /* 0x40 */
} Self;
extern void fn_8009076C(s32 a, Data* d);
extern s32 strlen(const char* s);
extern char* const lbl_802B9428[];
typedef struct {
    s32 type;
    u8 pad4[0x24 - 4];
    s32 f24, f28, f2c, f30, f34, f38, f3c, f40;
} Rec;
extern void* fn_802258BC(s32 a, u32 b, s32 c);
extern void fn_801DCE18(f32* a, f32* b, s32 c);
typedef struct Tri { VertexCol v[3]; } Tri;
extern Tri lbl_802B8EF0;
typedef struct ShopEntry_801BD748 {
    s8 flag;
    s8 type;
    s16 id;
    s16 val;
} ShopEntry_801BD748;
typedef struct ShopBuf_801BD748 {
    u8 pad0[4];
    u16 pages;
    u16 count;
    ShopEntry_801BD748 out[0x30];
} ShopBuf_801BD748;
typedef struct ShopTask_801BD748 {
    u8 pad0[0x2c];
    ShopBuf_801BD748* buf;
} ShopTask_801BD748;
typedef struct Ent_801BE608 {
    void *a, *b, *c;
    u16 xc;
    u8 lo;
    u8 hi;
    s32 f10, f14, f18, f1c, f20;
    s32 f24;
} Ent_801BE608;
extern TaskFunc lbl_802EBD30[33];
extern EvObj *lbl_80347450;
typedef struct Obj_8019CB80_8019C424 {
    u8 pad00[8];
    Sub* x8;
    u8 pad0c[0x18 - 0x0c];
    u8 flags;
    u8 state;
    u8 pad1a[0x24 - 0x1a];
    St* st;
    u8 pad28[0x40 - 0x28];
    St buf;                /* 0x40 ADD: the work itself */
} Obj_8019CB80_8019C424;
extern void *fn_80226704(void *parent, void *cb, s32 size);
extern void *fn_801C8930(void *p);
extern f32 fn_80291A5C(f32 x);
extern s32 fn_802254A0(NJS_POINT3 *p, EvHit *h);
extern s32 fn_80227810(NJS_TEXLIST *t);
extern s32 fn_802275A4(NJS_TEXLIST *t, s32 a);
extern void fn_80217830(s32 h);
extern void fn_80100B74(Task *t);
#define RND() (3.0517578e-05f * rand())
#define SIGN(x) (((x) > 0.0f) - ((x) < 0.0f))
void fn_80199B9C(void* p, f32 v);
void fn_80199BA4(void* p, u8 v);
void fn_80199BAC(void* p, f32 a, f32 b);
void fn_80199BB8(void* p, f32 a, f32 b);
void fn_80199F38(void* obj);
void fn_8019AD94(void* p, u32 a, u32 b);
void fn_8019B42C(void* p, u32 a);

void fn_801A28A8(void);
extern s32 CARDMountAsync(s32 chan, void *work, void (*detach)(void), void (*attach)(void));
extern s32 CARDFormatAsync(s32 chan, void (*cb)(void));

void fn_8019BED8(struct Task* t, EvObj* o);
static inline s32 Flag_8019C190(u32 n) {
    return (lbl_80310B3C[n >> 5] & (1 << (n & 31))) != 0;
}

extern s32 lbl_803473A8;

extern void fn_800CF8C4(f32* v, f32 f);

extern void fn_801DBE1C(const char* fmt, ...);

static inline s32 InArea_8019C190(EvObj* o) {
    NJS_POINT3 v;
    EvObj* p;
    if (o->x20c >= 0 && Flag_8019C190(o->x20c) != 0) return 0;
    p = lbl_80347450;
    if (o->x24c.z < p->pos.y || o->x258 > p->pos.y) return 0;
    v.x = p->pos.x;
    v.y = p->pos.y;
    v.z = p->pos.z;
    return fn_802254A0(&v, o->hit);
}
void fn_8019C190(struct Task* t);
s32 fn_801A2670(s32 idx, s32 *out);

extern u32 lbl_80347568;
void SaveLoadTask(Task *task);
SaveTask* SaveLoadOpenSave(void* parent, u16 id);
void fn_801A289C(void);
void fn_801A28A8(void);
s32 fn_801A28AC(s32 obj);
void fn_801A2D20(SaveTask *t, u32 a, u32 b);

extern s32 CARDProbeEx(s32 chan, s32 *mem, s32 *sector);
s32 fn_801A37D8(s32 chan);
s32 fn_801A3510(void);
void fn_801A37C4(void);

extern const char lbl_802B4978[];   /* "SA_LEGENDS" */
extern const char lbl_8034B6A0[6];  /* ".%03d" */


static inline void SlotName(char* buf, u16 n)
{
    sprintf(buf, lbl_8034B6A0, n);
}
s32 fn_801A37D8(s32 chan);
void fn_801A4060(SaveTask* t);
void fn_801A41C0(CardRec* rec);
void fn_801A471C(s32 idx);

extern void *lbl_80346720;
extern void fn_80005AD8(void *p, void *q);
void fn_801A49B8(void *p);
void *fn_801A4AF4(void *obj);
void fn_801A64B4(void* obj, s32 idx);
void fn_801A6824(void *o0);
void fn_801A69BC();
void fn_801A69DC(void);
s32 fn_801A6A04(s32 x);
int fn_801A6A58(int sub, int idx);
s32 fn_801AACB0(ShopTask* t);
void fn_801AB98C(Obj_UNIT0000 *o);

void fn_801AC678(ShopPart* t);
void* fn_801BE17C(u16 id);
s32 fn_801BDEF4(u16 id, u16 mode);
void fn_801AC87C(ShopPart* t);
ShopPart* fn_801ACD38(void* arg, u16 slot);
void fn_801B6400(const char* v);

void fn_801BD5A4(void);
/* ADD: the poster model object: p4 -> a block whose 0x20 word is the model handle. */
typedef struct PosterSub { u8 pad[0x20]; void* x20; } PosterSub;
typedef struct PosterObj { u8 pad[4]; PosterSub* p4; } PosterObj;

extern s16 lbl_803471A6;
extern s16 lbl_803471A4;
extern PosterObj* lbl_803471A0;
extern void fn_801BCAF4(s16 a, s16 b, f32 alpha, s16 sel, s32 n);
extern PosterObj* fn_801DB244(char* path);
void fn_801BC490(ShopTask* t);
void fn_801BCFAC(u8* obj, s32 idx);

extern const char lbl_802C39A0[];
extern void* fn_801E49D8(const char* name);
extern void* lbl_803471B0;
extern s32 fn_801E4974(void* h, s32 i);
extern s32 fn_801E48A8(void* h);
extern void* fn_801E4984(void* h, s32 i);
extern void* fn_801E1584(void* h, s32 size);
extern void** fn_801DB124(void* p);
extern void* lbl_803471B4;
extern void* lbl_803471AC;
extern void fn_801D6998(void* dst, void* src);
extern void* lbl_803471A8;
void fn_801BD5A4(void);
void fn_801BD644(void);
void fn_801BEAE4(void* a, s32 b);
void fn_8019E33C(Task *t);
void fn_8019E3E0(Task *t);
void fn_8019E5F0(Task *t);
void fn_8019EDEC(Task *t);
void fn_801A18FC(Task *t);
void fn_801A2CC4(void);
void fn_801A39B4(u16 id, void *obj);
void fn_801A64E0(void *o);
s32 fn_801A6554(void *o);
void fn_801A65D4(Task *t);
void fn_801A686C(void *o);
void *fn_801AB9D0(s32 a);
void fn_801B0B2C(u8 *obj);
void fn_80199F58(Obj_80199F58 *o);
void fn_8019A15C(u8 *o, s8 a, s8 b, s8 c);
void fn_8019B36C(u8 *o);
void fn_8019E294(Self_8019E294 *o);
void fn_8019E650(Self_8019E650 *o);
void fn_8019FDB0(Self_8019FDB0 *o);
void fn_8019FE64(Self_8019FE64 *o);
void fn_8019FF38(Self_8019FF38 *o);
void fn_801A1834(Self_801A1834 *o);
void* fn_801A343C(Task_801A343C* a);
void fn_801A473C(void);
void* fn_801A4DCC(void* a, u16 flag);
void fn_801A4E58(void *a);
Node* fn_801A51A8(void* a);
Node* fn_801ABE90(void* a);
Node* fn_801AC094(void* a);
Node* fn_801B1104(void* a);

/* The two stat buffers the item and equip windows fill from an item id. */
typedef struct CmpEq { s16 id; s16 x2; s16 col; s16 v[9]; } CmpEq;
extern void fn_801C2E48(CmpEq* out, s16 id);
extern s32 fn_801C2CF4(CmpEq* out, s16 id);
/* The item window of the shop: the item's name, "x" and how many are held, then its stats. */
typedef struct Task_801B11EC {
    u8 pad00[0x18];
    u8 flags; /* 0x18 */
    u8 state; /* 0x19 */
    u8 pad1a[0x24 - 0x1a];
    u8* flag;  /* 0x24 */
    MenuPanel* obj; /* 0x28 */
} Task_801B11EC;

/* Draws a signed number: a minus sign at (x, y), then the digits like TextPrintNumber. Its
 * arguments are in TextPrintNumber's order, position first; the float arguments are evaluated
 * before the value, which is what fixes the registers here. */
extern void UiDrawNumberText(f32 x, f32 y, s32 value, u16 flags);
#define IT_NUM(val, x, y, k) UiDrawNumberText((x) + lbl_802B8E4C[k].x, (y) + lbl_802B8E4C[k].y, (val), 0xC004)
#define IT_SNUM(val, ix, iy, tbl, k, fl) TextPrintNumber((ix) + (tbl)[k], (iy), (val), (fl))
#define IT_HEAD(t, id)                                                                           \
    fn_801B6BB4((t)->obj, &(t)->obj->o.x, (id), -1, 8, 6, 1.0f);                                \
    if ((id) != -1) {                                                                             \
        TextPrint(42.0f + (t)->obj->o.x, 6.0f + (t)->obj->o.y, fn_801F4AE4(id));       \
    }                                                                                             \
    TextPrint(248.0f + (t)->obj->o.x, 6.0f + (t)->obj->o.y, "\x81\x7e");              \
    TextPrintNumber(20.0f + (248.0f + (t)->obj->o.x), 6.0f + (t)->obj->o.y, fn_801F452C(id), 0xC002);
void fn_801B11EC(Task_801B11EC* t);
ShopPart* fn_801B1A78(void* a);

/* The shop's top menu panel (the task fn_801B2310 creates). */

extern f32 njCos(s32 a);
extern void fn_801B1EA0(ShopPart* t);
s32 fn_801B94F0(void);
u16 fn_801B952C(u16 i);
void fn_801B5D68(ShopPart* t);
void fn_801B1B3C(ShopPart* t);
ShopPart* fn_801B6240(void* a, f32 x);
ShopPart* fn_801B6AE8(void* a);
void fn_801B8E68(Task_801B8E68* t);
Sprite* fn_8019AB94(s16 a);
Sprite* fn_8019AC94(s16 a);
void fn_8019CB80(Obj_8019CB80* o);
void fn_801A0B18(Self_801A0B18* o);
void fn_801A1494(Self_801A1494* o);
void fn_801A1FBC(Self_801A0C3C* o);
s32 fn_801A388C(s32 chan, const char *name, s32* out);
void* fn_801A456C(void);
void fn_801A49E0(Hdr_801A49E0* h);

extern s32 UiSpriteDraw(Sprite* sprite, f32 x, f32 y, f32 z, NJS_TEXLIST* texlist, u16 flags, f32 a, f32 b);
extern void UiDrawNumberAt(u32 flags, u16 ndigits, u32 value, f32 x, f32 y, f32 z, f32 c1);
extern u16 lbl_802B69B4[];
void fn_801A58A0(Task_801A54AC* t, E2c* e);
Node* fn_801A5BE8(void* parent, u16 mode);

void SaveLoadCursorDraw(Task_801A54AC* t);
SlotTask* SaveLoadCursorCreate(void* parent);

extern const LayoutDef lbl_802B4DB8[];
void SaveLoadCursorDraw(Task_801A54AC* t);
SlotTask* fn_801A5EB4(void* a, u16 slot);
SlotTask* fn_801A6244(void* a, u16 slot);
void fn_801A68C4(void* tt);
u8 fn_801AB6E8(s8 step, u8 start);
void fn_801ABF70(PanelTask_801ABF70* t);
ShopPart* fn_801ACC00(void* arg, u16 slot);
void fn_801AFAA4(PanelTask_801AFAA4* t);
void fn_801B02F4(ShopPart* t);
Task2_801B0470* fn_801B0470(void* arg);
ShopPart* fn_801B0DF8(void* arg);
Task3_801B2310* fn_801B2310(void* arg);
Task2_801B2678* fn_801B2678(void* arg, u16 sel);
Task3_801B5C4C* fn_801B5C4C(void* arg);
void fn_801B5D68(ShopPart* t);
void fn_801B5EA8(PanelTask_801ABF70* t);
void fn_801B5FA8(PanelTask_801ABD40* t);
void fn_801B66F8(PanelTask_801ABD40* t);
Task2_801B6838* fn_801B6838(void* arg);
s32 fn_801B93E8(ShopTask* t);
s32 fn_80199FFC(PosTabs *t, s8 idx, s32 val, s16 x, s16 y, s8 kind);
void fn_8019B44C(Self_8019B44C *self);
void fn_8019BD2C(Obj48 *o, s32 mode);
void fn_8019E96C(Self_8019E96C *self);
void fn_8019EE4C(Self_8019EE4C *self);
void fn_8019F44C(SaveTask* t);
void fn_8019F730(SaveTask *self);
void fn_801A0214(Self_801A0214 *self);
void fn_801A54AC(Task_801A54AC *t);
void fn_801A5600(Task_801A54AC *t);
void fn_801A6A88(Task_801A6A88 *t, u16 idx, f32 off);
void fn_801AB580(Self_801AB580 *self);
u8 fn_801AB82C(s32 mode, u8 cur, s32 idxp);
void fn_801AC16C(Task* task);
void fn_801ACE70(Task* task);
void fn_801B277C(Task* task);
void* fn_801B54D4(void* a);
void fn_801B6420(Task* task);
s32 fn_801B8F48(s32 mode, s16* sel, s16 id);

static inline u32 ItemTotal(s16 id) {
    u32 cnt = fn_801F464C(id);
    if (cnt == 0) {
        return 0;
    }
    return cnt * fn_801F477C(id) / 100;
}
u32 fn_801B9810(Ent_801B9810* list, Ent_801B9810** out, u32 n);
void fn_801A66AC(Node *t);
void fn_8019B980(Obj_8019B980 *self);
void fn_8019D168(Obj_8019D168 *self);
void fn_801A1DB4(Self_801A1DB4 *o);
void fn_801AB328(Self_801AB328 *o);
void fn_801A0FD8(Self_801A0FD8 *o);
void fn_801A5274(Task_801A5274 *t);
void fn_801A5D08(Task_801A5D08 *t);
void fn_801A6344(Task_801A5D08 *t);
void* fn_801AC2E4(void* a);
void fn_801B0F1C(Task_801B0F1C *t);
void fn_801B2430(Task_801B0F1C *t);
void fn_801A0C3C(Self_801A0C3C *o);
ShopPart* fn_801B6320(void* a, f32 x);

typedef struct {
    s32 kind;   /* 0x00 */
    u32 pad04;
    UiObj obj;  /* 0x08 */
} Inner_8016F138;
typedef struct {
    u8 pad00[0x18];
    u8 flags;    /* 0x18 */
    u8 state;    /* 0x19 */
    u8 pad1A[0x24 - 0x1A];
    Inner_8016F138* inner; /* 0x24 */
} Self_8016F138;
extern void fn_8019AE84(Self_8016F594 *self);
void fn_8019ADA0(Self_8016F138* self);
void fn_801A2C40(void);
u32 fn_801B90E4(s32 idx);
void fn_801BEA70(void *a, u32 idx, s32 mode);
void fn_8019EFF8(SaveTask* t);
void fn_801A11B0(SaveTask* t);
void fn_801B737C(ShopPart* t);
s32 fn_801AB094(Task_801AB094* t);

/* fn_801A6BDC: the shop's buy screen (item list, quantity, gold) and the equip-now prompt that
 * follows a purchase (weapon, armor and accessory comparison windows). The work keeps the menu
 * parts in a table like MenuWork; the state byte at work+0x03 drives the switch. */
extern u8 fn_801C0CA0(s16 id);
extern s8 fn_801C0C14(s16 id);
extern s32 fn_801C2C84(u8 i);
extern s32 fn_801F3FD0(s32 who, s16 id);
extern s32 fn_801C0B88(s16 id, u8 who);
typedef struct ShopSlotPos {
    u16 idx;
    f32 x;   /* shown */
    f32 x2;  /* hidden */
} ShopSlotPos;
extern const ShopSlotPos lbl_802B69E8[];
extern ShopPart* fn_801AD00C(ShopTask* t, u8 kind, u16 who);
extern ShopPart* fn_801B057C(ShopTask* t, u16 kind, u16 who);
extern ShopPart* fn_801B06CC(ShopTask* t, u16 i, u16 who, f32 alpha);
extern void* fn_801AFBE8(void* t, u16 i, u16 kind, f32 alpha);
extern void fn_801C1FC0(s16 id, s32 who);
extern s32 fn_801C16D0(s16 id);
extern void fn_801C1728(s16 id, u16 slot);
extern s32 fn_801AAFAC(ShopTask* t);
extern void fn_801C0AB4(u16 id, u8 who);
extern void fn_801C2C4C(u8 who, s8 v);
extern void fn_8021B1CC(void* a, void* b);
extern void fn_801C1E48(void);
extern s32 fn_801AACB0(ShopTask* t);
extern void fn_801F4E38(s32 who, s16 v);
extern void fn_801F4E04(s32 who, s16 v);
extern void fn_801C12C8(void);
extern void* fn_801F48AC(s16 id);
extern void fn_801B5644(ShopPart* p, u16 id);
extern void fn_801B571C(ShopPart* p, u16 id);
extern void fn_801C0FBC(s16 id);
extern void fn_801C08B4(s32 msg);
extern void fn_801C0814(ShopTask* t);
extern void fn_801C1148(s16 id, u8 n);

#define PAD_A (lbl_80311A60[0]->held & 0x100)
#define PAD_B (lbl_80311A60[0]->held & 0x200)
/* The entry under the cursor. The original keeps the entry address in a register (addi 8; add;
 * lha 2) even for one use; only the extra copy through cur_ reproduces that. */
#define SHOP_CUR_ENTRY(e, t, p)                                                          \
    {                                                                                    \
        ShopEntry* cur_ = &(t)->buf->out[(u8)(p)->list->page * 6 + (u8)(p)->list->row]; \
        (e) = cur_;                                                                      \
    }

#define SHOP_LIST_SET_Y(part)                   \
    {                                           \
        ShopPart* lp_ = (part);                 \
        ShopList* ll_ = lp_->list;              \
        ll_->oy = ll_->row * 24;                \
        lp_->list->ox = 0.0f;                   \
    }

#define ShopShowEquip(t) \
    { \
        UiObjMoveToX(&t->w->parts[0]->obj->o, 6, 5, -260.0f); \
        UiObjSetCommand(&t->w->parts[0]->obj->o, 15, 0); \
        UiObjMoveToX(&t->w->parts[3]->obj->o, 6, 5, -260.0f); \
        UiObjSetCommand(&t->w->parts[3]->obj->o, 15, 2); \
        UiObjMoveToX(&t->w->parts[1]->obj->o, 6, 5, -260.0f); \
        UiObjSetCommand(&t->w->parts[1]->obj->o, 15, 4); \
        UiObjMoveToX(&t->w->parts[2]->obj->o, 6, 5, -240.0f); \
        UiObjSetCommand(&t->w->parts[2]->obj->o, 15, 6); \
        UiObjMoveToX(&t->w->parts[8]->obj->o, 6, -1, 648.0f); \
        UiObjSetCommand(&t->w->parts[8]->obj->o, 15, 0); \
        UiObjMoveTo(&t->w->parts[7]->obj->o, 6, -1, 640.0f, 480.0f); \
        UiObjSetCommand(&t->w->parts[7]->obj->o, 15, 2); \
        t->w->parts[9]->flag->b0 = 1; \
        t->w->state = 8; \
    }

#define ShopBackToList(t) \
    { \
        t->w->parts[8]->list->part = 0; \
        t->w->parts[9]->flag->b0 = 0; \
        UiObjMoveToX(&t->w->parts[9]->obj->o, 6, -1, -8.0f); \
        UiObjSetCommand(&t->w->parts[9]->obj->o, 15, 2); \
        UiObjMoveToX(&t->w->parts[2]->obj->o, 6, -1, -240.0f); \
        UiObjSetCommand(&t->w->parts[2]->obj->o, 15, 0); \
    }

#define ShopHideList(t) \
    { \
        t->w->parts[0]->flag->b0 = 1; \
        t->w->parts[3]->flag->b0 = 1; \
        t->w->parts[1]->flag->b0 = 1; \
        t->w->parts[2]->flag->b0 = 1; \
        t->w->parts[8]->flag->b0 = 1; \
        t->w->parts[7]->flag->b0 = 1; \
    }

#define ShopShowCompare(t) \
    { \
        UiObjMoveToX(&t->w->parts[10]->obj->o, 6, -1, 328.0f); \
        UiObjSetCommand(&t->w->parts[10]->obj->o, 15, 0); \
        UiObjMoveToX(&t->w->parts[10]->obj2->o, 6, -1, 328.0f); \
        UiObjSetCommand(&t->w->parts[10]->obj2->o, 15, 2); \
        UiObjMoveToX(&t->w->parts[11]->obj->o, 6, -1, 328.0f); \
        UiObjSetCommand(&t->w->parts[11]->obj->o, 15, 4); \
        UiObjMoveToX(&t->w->parts[11]->obj2->o, 6, -1, 328.0f); \
        UiObjSetCommand(&t->w->parts[11]->obj2->o, 15, 6); \
    }

#define ShopCompareDone(t) \
    { \
        t->w->state = 12; \
        if (fn_801AAFAC(t)) { \
            t->w->xa = 4; \
        } \
    }

#define ShopFreeCompare(t) \
    { \
        MenuPartFree((MenuTask*)t, 12); \
        MenuPartFree((MenuTask*)t, 18); \
        MenuPartFree((MenuTask*)t, 10); \
        MenuPartFree((MenuTask*)t, 11); \
        MenuPartFree((MenuTask*)t, 13); \
        MenuPartFree((MenuTask*)t, 14); \
        fn_801AB328((Self_801AB328*)t); \
    }

#define SHOP_SLOT_CMDS(t, cmd, o) \
    { \
        cmd = 20; \
        if (t->w->xa == 0) { \
            cmd = 21; \
        } \
        UiObjSetCommand(&t->w->parts[14]->obj->o, cmd, 0); \
        { \
            ShopPart* q_ = t->w->parts[15]; \
            if (q_) { \
                o = &q_->obj->o; \
                cmd = 20; \
                if (t->w->xa == 1) { \
                    cmd = 21; \
                } \
                UiObjSetCommand(o, cmd, 0); \
            } \
        } \
        { \
            ShopPart* q_ = t->w->parts[16]; \
            if (q_) { \
                o = &q_->obj->o; \
                cmd = 20; \
                if (t->w->xa == 2) { \
                    cmd = 21; \
                } \
                UiObjSetCommand(o, cmd, 0); \
            } \
        } \
        { \
            ShopPart* q_ = t->w->parts[17]; \
            if (q_) { \
                o = &q_->obj->o; \
                cmd = 20; \
                if (t->w->xa == 3) { \
                    cmd = 21; \
                } \
                UiObjSetCommand(o, cmd, 0); \
            } \
        } \
        cmd = 20; \
        if (t->w->xa == 4) { \
            cmd = 21; \
        } \
        UiObjSetCommand(&t->w->parts[18]->obj->o, cmd, 0); \
    }
void fn_801A6BDC(ShopTask* t);
void fn_801A2C58(void);
s32 fn_801B5868(s16 id);
void fn_801A6650(SaveTask *t, u16 i);
void fn_8019E3A8(Task *t);

static inline s32 bit_set(u32 mask, s32 k)
{
    s32 f = (mask & (1 << k)) != 0;
    f = f != 0;
    return f;
}
s32 fn_8019A21C(u32 mask, s32 d, s32 n, s32 unused, s32 max);

/* Returns 0 once the selected slot's entry is valid and the menu has moved on. */
static inline s32 SelectSlot(Self_801A0E7C *self) {
    extern void fn_801A64B4(void *o, u8 k);
    extern u32 fn_801A6A58(int sub, int idx);
    s32 k;
    self->ctx->w25c[self->ctx->b4] = fn_801A28AC(self->ctx->b4);
    if (self->ctx->w25c[self->ctx->b4] != 0) {
        self->ctx->b9 = 0;
        if (1.0f != self->ctx->f18) {
            fn_801A4DCC(self, 1);
        }
        UiObjMoveToXIfChanged(&self->ctx->h[1]->ui->o, 6, 4, -330.0f);
        UiObjSetCommand(&self->ctx->h[1]->ui->o, 0xf, 0);
        k = fn_801A6A58(self->ctx->b4, self->ctx->w25c[self->ctx->b4]);
        fn_801A64B4(self, k);
        MenuPlaySe(3);
        self->state19 = 0xb;
        return 0;
    }
    return 1;
}
void fn_801A0E7C(Self_801A0E7C *self);

static inline s32 CardWait(s32 chan) {
    s32 t;
    do {
        fn_801DC214();
        t = CARDGetResultCode(chan);
    } while (t == -1);
    return t;
}

static inline void CardRelease(s32 chan) {
    s32 r;
    if (lbl_8034718C[chan] != 0) {
        fn_801DC214();
        r = CARDUnmount(chan);
        if (r == 0 || r == -3) {
            fn_801E17E0(lbl_8034718C[chan]);
            lbl_8034718C[chan] = 0;
        }
    }
}
s32 fn_801A2500(s32 chan, s32 *out);
CardRec *fn_801A41EC(CardSaveData *p, s32 chan, const char *name);
s32 fn_801AAFAC(ShopTask *self);
void fn_801ABD40(PanelTask_801ABD40* t);
void* fn_801AFBE8(void* parent, u16 idx, u16 mode, f32 alpha);
void fn_801B71E8(s32 x, s32 y, s16 id);
void fn_801B7274(s32 x, s32 y, s32 nx, s32 ny, s16 id);
void fn_801A4B40(void* a);
void fn_801ABA30(void* a);
void fn_8019D598(Self* o);

typedef struct { u8 pad[0x24]; MenuPartWork* w; MenuPanel* obj; u32 w2c; } T_801B65CC;
typedef struct { const char* text; f32 x; } NameEnt;
extern const f32 lbl_802B8EDC[];
extern NameEnt lbl_802EC01C[];
T_801B65CC* fn_801B65CC(void* a, u16 idx, f32 y);

static inline void Unmount(s32 slot) {
    if (lbl_8034718C[slot] != 0) {
        s32 r;
        fn_801DC214();
        r = CARDUnmount(slot);
        if (r == 0 || r == -3) {
            fn_801E17E0(lbl_8034718C[slot]);
            lbl_8034718C[slot] = 0;
        }
    }
}
void fn_801A372C(void);
u32 fn_801A4684(void *buf, u32 size);
void fn_801A2424(s32 n, s32 idx, char* buf, s32 len);

static inline void ScrollUp(Self_801A0C3C *o, s32 st) {
    s32 i;
    o->ctx->x6--;
    for (i = 0; i < 7; i++) {
        UiObjMoveToY(&o->ctx->objs[i + 7]->obj->o, 6, -1, 110.0f + o->ctx->objs[i + 7]->obj->o.y);
        UiObjSetCommand(&o->ctx->objs[i + 7]->obj->o, 0xf, 0);
    }
    MenuPlaySe(4);
    o->state = st;
}

static inline void ScrollDown(Self_801A0C3C *o, s32 st) {
    s32 i;
    o->ctx->x6++;
    for (i = 0; i < 7; i++) {
        UiObjMoveToY(&o->ctx->objs[i + 7]->obj->o, 6, -1, o->ctx->objs[i + 7]->obj->o.y - 110.0f);
        UiObjSetCommand(&o->ctx->objs[i + 7]->obj->o, 0xf, 0);
    }
    MenuPlaySe(4);
    o->state = st;
}
void fn_801A1958(Self_801A0C3C *o, s32 st);
void fn_8019BED8(struct Task* t, EvObj* o);
void fn_801A1B98(Self_801A0C3C *o, u8 mode);
void fn_801B60E8(MP* p);

inline s32 FlagTest(u32 b)
{
    return (lbl_80310B3C[b >> 5] & (1 << (b & 31))) != 0;
}

inline s32 Rank(s16 id)
{
    u8 c = lbl_803473BE;
    s8 r;
    s32 x;
    if (id == -1) {
        x = -1;
    } else if (c >= 0x18) {
        x = -1;
    } else {
        r = 0;
        if (c >= lbl_802ED258[id].lo) {
            r = 2;
        } else if (c >= lbl_802ED258[id].hi) {
            r = 1;
        }
        x = r;
    }
    return x;
}
s32 fn_801BDEF4(u16 id, u16 mode);

inline s32 Cat(s16 id) {
    u8 v = lbl_803473BE;
    s8 r;
    if (id == -1) {
        return -1;
    }
    if (v >= 0x18) {
        return -1;
    }
    r = 0;
    if (v >= lbl_802ED258[id].lo) {
        r = 2;
    } else if (v >= lbl_802ED258[id].hi) {
        r = 1;
    }
    return r;
}
inline void FlagClear(u32 b) {
    lbl_80310B3C[b >> 5] &= ~(1 << (b & 31));
}
inline void FlagSet(u32 b) {
    lbl_80310B3C[b >> 5] |= 1 << (b & 31);
}
static inline void Pass1(void) {
    s32 i;
    s8 c;
    for (i = 0; i < 0x58; i++) {
        c = Cat(i);
        if (c == 2) {
            if (FlagTest(i + 0x8A2) != 0) {
                FlagClear(i + 0xC08);
                FlagClear(i + 0x8A2);
            }
        }
    }
}
void fn_801BE468(void);
extern const f32 lbl_802B8F40[6];
extern const f32 lbl_802B8F58[6];
ShopPart* fn_801AD00C(ShopTask* t, u8 kind, u16 who);

/* fn_801F4C24's item type folded into the item panel's five layouts (its h52). */
static inline u8 ShopItemKind(s16 id) {
    u8 r;
    s16 kind = fn_801F4C24(id);
    switch (kind) {
    case 0: case 1: case 2: r = 0; break;
    case 5: r = 2; break;
    case 6: r = 1; break;
    case 3: case 4: case 7: r = 3; break;
    default: r = 4; break;
    }
    return r;
}
void fn_801B5644(ShopPart* p, u16 id);
void fn_801B571C(ShopPart* p, u16 id);
void* fn_801BE17C(u16 id);
void fn_801BE2F0(ShopEntry* e, u8 mode);

extern char* fn_801C2CBC(s16 id);
void fn_801AFD34(void* arg);
void fn_801B0014(void* arg);
void fn_801A20AC(SaveTask* t);
void fn_801B0838(void* arg);
ShopPart* fn_801B057C(ShopTask* t, u16 kind, u16 who);
ShopPart* fn_801B06CC(ShopTask* t, u16 kind, u16 who, f32 alpha);

extern void fn_801B4F78(s32 x, s32 y, u16 cur, u16 id);
extern s16 fn_801C153C(s16 i, s16 cur);

static inline void ShopNums3(MenuPanel* o, s32 n) {
    s16 ix = o->o.rect[0];
    s16 iy = 60.0f + o->o.rect[1] + 24 * n;
    ShopRow* r = &lbl_803471B8->chr->rows[n];
    TextPrintNumber(ix + lbl_802B8ECC[0], iy, r->h8, 0xC004);
    TextPrintNumber(ix + lbl_802B8ECC[1], iy, r->ha, 0xC004);
    TextPrintNumber(ix + lbl_802B8ECC[2], iy, r->he, 0xC004);
    TextPrintNumber(ix + lbl_802B8ECC[3], iy, r->h14, 0xC004);
}
void fn_801B42F8(ShopPart* t);
void fn_801B46EC(void* arg);

static inline void ShopNums4(MenuPanel* o, s32 n) {
    s16 ix = o->o.rect[0];
    s16 iy = 60.0f + o->o.rect[1] + 24 * n;
    ShopRow* r = &lbl_803471B8->chr->rows[n];
    TextPrintNumber(ix + lbl_802B8EBC[0], iy, r->h6, 0xC004);
    TextPrintNumber(ix + lbl_802B8EBC[1], iy, r->hc, 0xC004);
    TextPrintNumber(ix + lbl_802B8EBC[2], iy, r->h10, 0xC004);
    TextPrintNumber(ix + lbl_802B8EBC[3], iy, r->h12, 0xC001);
}
void fn_801B49B0(ShopPart* t);
void fn_801B4CF0(void* arg);
void fn_801B914C(ShopTask* t, u8 dir);

extern u32 lbl_80347198;
void fn_801AC87C(ShopPart* t);
void fn_801AC48C(ShopPart* t);
void fn_801AC678(ShopPart* t);
void fn_801B6950(ShopPart* t);
void fn_801B0B9C(ShopPart* t);

/* A panel's start position, z and alpha (0x18 bytes). */
typedef struct PanelStart {
    f32 x, y;
    f32 f8, fc;
    f32 z;
    f32 alpha;
} PanelStart;
extern const PanelStart lbl_802B690C[];
Sub_801A0C3C *fn_801A53D4(void *o, u16 idx);
void fn_8019F898(SaveTask *t);

inline s32 Test_801BD748(u32 b) {
    return ((*(u32(*)[])&lbl_80310B3C)[b >> 5] & (1 << (b & 31))) != 0;
}
s32 fn_801BD748(ShopTask_801BD748* t, ShopEntry_801BD748* tmp, s32 start);
void SaveLoadTask(Task *task);
void fn_8019C424(Task *t);
typedef struct CARDFileInfo {
    s32 chan;
    s32 fileNo;
    s32 offset;
    s32 length;
    u16 iBlock;
    u16 pad;
} CARDFileInfo;

extern char lbl_80308178[0x20];
extern s32 fn_801A2500(s32 chan, s32 *out);
extern s32 CARDFreeBlocks(s32 chan, s32 *bytes, s32 *files);
extern s32 CARDOpen(s32 chan, const char *name, CARDFileInfo *info);
extern s32 CARDRead(CARDFileInfo *info, void *buf, s32 len, s32 ofs);
extern s32 CARDClose(CARDFileInfo *info);
extern int strcmp(const char *, const char *);

static inline u32 CardSum(const void *p) {
    const u32 *q;
    u32 sum;
    s32 i;
    if (p == NULL) {
        sum = 0;
    } else {
        q = p;
        sum = 0;
        for (i = 3199; i != 0; i--) {
            sum ^= *q++;
        }
    }
    return sum;
}
void fn_801A2D60(Task_801A343C* t);

/* The strip handed to fn_8019DBA8: 48 points, 48 indices, 48 extra words. */
typedef struct StripUV { s16 u, v; } StripUV;
typedef struct Strip_8019DBA8 {
    NJS_POINT3* v;   /* 0x00 */
    u32* idx;        /* 0x04 */
    StripUV* uv;     /* 0x08 */
    s32 n;           /* 0x0C */
} Strip_8019DBA8;

/* The trail record at EvObj.x25c (0x62C bytes). */
typedef struct Trail_8019D678 {
    NJS_POINT3 v[48];        /* 0x000 */
    u32 idx[48];             /* 0x240 */
    StripUV uv[48];          /* 0x300 */
    Strip_8019DBA8 strip;    /* 0x3C0 */
    f32 x[25];               /* 0x3D0 */
    f32 x2[25];              /* 0x434 */
    f32 z[25];               /* 0x498 */
    f32 z2[25];              /* 0x4FC */
    f32 w[25];               /* 0x560 */
    f32 w2[25];              /* 0x5C4 */
    s32 cur;                 /* 0x628 */
} Trail_8019D678;

extern f32 lbl_803467E0;
extern f32 lbl_803467E4;
extern f32 lbl_80347160;
extern void* fn_801E1C34(s32 size);
extern void fn_801E1784(void* p);
extern void fn_80296E4C(s32 a);
extern void fn_80296DC8(u32 v);
extern s32 fn_80299040(NJS_TEXLIST* texlist);
extern void fn_80298FE4(s32 i);
extern void fn_8019DBA8(Strip_8019DBA8* s, f32* x, f32* z, f32* w);

#define TRAIL_STEP(b) \
    if ((b)->cur > 0) { \
        (b)->cur--; \
    } else { \
        (b)->cur = 24; \
    }

#define TRAIL_POS(b) \
    { \
        f32 x_ = lbl_80347450->pos.x + s; \
        (b)->x[(b)->cur] = x_; \
        (b)->x2[(b)->cur] = x_; \
    } \
    { \
        f32 z_ = lbl_80347450->pos.z + c; \
        (b)->z[(b)->cur] = z_; \
        (b)->z2[(b)->cur] = z_; \
    }
void fn_8019D678(Task* t);

extern void fn_800073C0(CardStampBuf *p);
extern s32 fn_80228928(void);
extern Sub_801A0C3C *fn_801A5BE8(void *parent, u16 mode);
static inline void FinishPart_801A038C(Self_801A0C3C *o, s32 idx)
{
    if (o->ctx->objs[idx] != 0 && o->ctx->objs[idx]->obj != 0) {
        UiObjFinish(&o->ctx->objs[idx]->obj->o);
    }
}

static inline void FinishList_801A038C(Self_801A0C3C *o)
{
    s32 i;
    for (i = 0; i < 7; i++) {
        FinishPart_801A038C(o, i + 7);
    }
}

static inline void SlideAll_801A038C(Self_801A0C3C *o)
{
    s32 i;
    for (i = 0; i < 7; i++) {
        if (o->ctx->objs[lbl_802B494C[i].idx] != 0
            && UiObjMoveToXIfChanged(&o->ctx->objs[lbl_802B494C[i].idx]->obj->o, 6, 5, 676.0f) != 0) {
            UiObjSetCommand(&o->ctx->objs[lbl_802B494C[i].idx]->obj->o, 0xf, lbl_802B494C[i].b3);
        }
    }
}

static inline void SlideBut_801A038C(Self_801A0C3C *o)
{
    s32 i;
    for (i = 0; i < 7; i++) {
        if (i != o->ctx->x7 && o->ctx->objs[lbl_802B494C[i].idx] != 0
            && UiObjMoveToXIfChanged(&o->ctx->objs[lbl_802B494C[i].idx]->obj->o, 6, 5, 676.0f) != 0) {
            UiObjSetCommand(&o->ctx->objs[lbl_802B494C[i].idx]->obj->o, 0xf, lbl_802B494C[i].b3);
        }
    }
}
void fn_801A0018(Self_801A0C3C *o);
void fn_801A038C(Self_801A0C3C *o);
void fn_8019F28C(Self_801A0C3C *o);
void fn_8019EAD4(Self_801A0C3C *o);
void SaveLoadSlideAllOut(Self_801A0C3C *o);
void SaveLoadCreateParts(Self_801A0C3C *o);

#endif
