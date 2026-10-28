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
#include "game/gamedata.h"
#include <math.h>
#include <stdlib.h>
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
    s16 h6;           /* 0x06 */
    s32 w8;           /* 0x08 */
    s32 wc;           /* 0x0C */
    s32 w10;          /* 0x10 */
    u8 pad14[0x1e - 0x14];
    u8 b1e;           /* 0x1E */
    u8 pad1f[0x48 - 0x1f];
    void (*cb)(void* t); /* 0x48 */
    u8 pad4c[0x58 - 0x4c];
} MenuPartWork;
extern u8 lbl_8030741C[];
extern u32 lbl_80347180;
extern u8 lbl_8034717C[2];
extern u8 lbl_803081CC[];
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
/* A controller's state; lbl_80311A60 has one per port. */
typedef struct PadState {
    u8 pad0[8];
    u32 held; /* 0x08: buttons held this frame (0x100 A, 0x200 B) */
} PadState;
extern PadState *lbl_80311A60[];
extern s32 fn_801A6554(void *o);
extern void fn_801A64E0(void *o);
typedef struct VertexCol {
    f32 x, y, z;
    u32 colour;
} VertexCol;
typedef struct Ctx_801A66AC {
    u8 pad0[0x44];
    u32 w44;
} Ctx_801A66AC;
typedef struct Task_801A66AC {
    u8 pad0[0x24];
    Ctx_801A66AC *ctx;
    MenuPanel* ui;
} Task_801A66AC;
extern f32 fn_801DBD9C(f32 z);
extern void fn_80290ED4(VertexCol *v, s32 count, s32 flag);
void fn_801A66AC(Task_801A66AC *t);
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
extern void fn_801A473C();
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
extern s32 fn_801A2670(u8 idx, s32 *out);
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
/* A save slot's summary, one per file (0x2C bytes). */
typedef struct {
    s32 f0;
    u16 h4;          /* 0x04 */
    u16 h6;          /* 0x06 */
    u32 w8;          /* 0x08 */
    s16 hc;          /* 0x0C */
    u8 be, bf, b10, b11; /* 0x0E-0x11 */
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
    u8 padA[2];
    s32 fc;          /* 0x0C */
    u8 pad10[2];
    s16 h12;         /* 0x12 */
    s32 w14;         /* 0x14 files found */
    f32 f18;         /* 0x18 */
    f32 f1c;         /* 0x1C scan progress */
    E2c ent[10];     /* 0x20 */
    u8 pad_[0x20c - 0x20 - 10 * 0x2c];
    Pnl* p[17];      /* 0x20C */
    s32 w250;        /* 0x250 scan done */
    u8 pad254[4];
    void* f258;      /* 0x258 */
    s32 st[8];       /* 0x25C */
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
typedef struct Holder_8019FF38 {
    u8 pad0[0x28];
    MenuPanel* ui;
} Holder_8019FF38;
typedef struct Ctx_8019FF38 {
    u8 pad0[4];
    u8 b4;
    u8 pad1[0x218 - 5];
    Holder_8019FF38 *p218;
    Holder_8019FF38 *p21c;
} Ctx_8019FF38;
typedef struct Self_8019FF38 {
    u8 pad0[0x19];
    u8 state19;
    u8 pad1[0xa];
    Ctx_8019FF38 *ctx;
} Self_8019FF38;
extern void fn_801A47D8(void *o);
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
extern void fn_80252E5C(void* p);
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
typedef struct Task_801A51A8 {
    u8 pad00[0x24];
    u8* p24;
    MenuPanel* p28;
    u32 w2c;
} Task_801A51A8;
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
typedef struct Task_801ABE90 {
    u8 pad00[0x24];
    u8* p24;
    MenuPanel* p28;
    u32 w2c;
} Task_801ABE90;
extern void fn_801ABF70();
typedef struct Task_801AC094 {
    u8 pad00[0x24];
    u8* p24;
    MenuPanel* p28;
    u32 w2c;
} Task_801AC094;
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
typedef struct Task_801B1104 {
    u8 pad00[0x24];
    u8* p24;
    MenuPanel* p28;
    u32 w2c;
} Task_801B1104;
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
    u8 pad35;
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
    u8 pad4[2];
} ShopEntry;
typedef struct ShopBuf {
    u8 pad0[4];
    u16 pages;
    u16 count;
    ShopEntry out[0x30];
} ShopBuf;
typedef struct ShopTask {
    u8 pad0[0x19];
    u8 state;        /* 0x19 */
    u8 pad1a[0xa];
    ShopWork* w;     /* 0x24 */
    ShopChar* chr;   /* 0x28 */
    ShopBuf* buf;    /* 0x2C */
    SellList* sell;  /* 0x30: the five sell tabs' lists */
} ShopTask;
extern ShopTask* lbl_803471B8;
extern s32 fn_801B93E8(ShopTask* t);
struct Task_801B11EC;
extern void fn_801B11EC(struct Task_801B11EC* t);
typedef struct Task_801B1A78 {
    u8 pad00[0x24];
    u8* p24;
    MenuPanel* p28;
    u32 w2c;
} Task_801B1A78;
extern void fn_801B5EA8();
typedef struct Task_801B6240 {
    u8 pad00[0x24];
    u8* p24;
    MenuPanel* p28;
    u32 w2c;
} Task_801B6240;
void fn_801B6950(ShopPart* t);
typedef struct Pair_UNIT0000 {
    const char* a;
    const char* b;
} Pair_UNIT0000;
extern const Pair_UNIT0000 lbl_802EBFDC[8];
extern const char lbl_802B8F80[];
extern u8 lbl_80310A1C[0x120];
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
typedef struct Flags_8019CB80 { u8 pad[0x18]; u8 flags; } Flags_8019CB80;
typedef struct Obj_8019CB80 {
    u8 pad00[8];
    Flags_8019CB80* x8;
    u8 pad0c[0x18 - 0x0c];
    u8 flags;
    u8 state;
    u8 pad1a[0x24 - 0x1a];
    St* st;
} Obj_8019CB80;
extern void fn_800906E8(void*);
typedef struct Sub28 { u8 pad[0x28]; MenuPanel* obj; } Sub28;
typedef struct Ctx_801A0B18 {
    u8 pad00[4];
    u8 idx;           /* 0x04 */
    u8 pad05[4];
    u8 x9;            /* 0x09 */
    u8 pad0a[0x18 - 0x0a];
    f32 x18;
    u8 pad1c[0x210 - 0x1c];
    Sub28* x210;
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
typedef struct Sv {
    u8 pad00[0x14];
    u32 x14;
    u8 pad18[0x64 - 0x18];
    u32 x64;
} Sv;
extern void fn_801A64E0(void* o);
typedef struct Ctx_801A1FBC {
    u8 pad00[6];
    u8 x6;
    u8 pad07[0x18 - 7];
    f32 x18;
} Ctx_801A1FBC;
typedef struct Self_801A1FBC {
    u8 pad00[0x24];
    Ctx_801A1FBC* ctx;
} Self_801A1FBC;
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
    u8 rest[0x1c];
} CardStat;
extern CardStat lbl_803080F8;
extern s32 CARDGetStatus(s32 chan, s32 fileNo, CardStat* stat);
extern char *strstr(const char *str, const char *pat);
typedef struct Misc {
    u8 pad00[4];
    u32 x4;
    u8 x8;
} Misc;
typedef struct Flt {
    u8 pad00[0x38];
    f32 f38, f3c, f40;
    u32 w44, w48, w4c;
    u8 pad50[4];
    f32 f54, f58, f5c;
    u32 w60, w64, w68;
} Flt;
typedef struct Save {
    u8 pad00[0x16b0];
    u32 x16b0;
    u8 x16b4;
    u8 pad16b5[0x16e8 - 0x16b5];
    f32 x16e8, x16ec, x16f0;
    u32 x16f4, x16f8, x16fc;
    u8 pad1700[4];
    f32 x1704, x1708, x170c;
    u32 x1710, x1714, x1718;
    u8 pad171c[0x31ea - 0x171c];
    s16 x31ea;
} Save;
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
    u8* a;       /* 0x24 */
    MenuPanel* b;    /* 0x28 */
} Node;
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
typedef struct {
    u8 pad[0x24];
    u8* buf;        /* 0x24 */
    MenuPanel* pan; /* 0x28 */
} SlotTask;
extern void* fn_801E1A74(s32 n, s32 size);
extern void fn_801A5FD8(void);
typedef struct Ctx_801A6344 {
    u8 pad0[0x18];
    f32 f18;
} Ctx_801A6344;
typedef struct Parent_801A6344 {
    u8 pad0[0x24];
    Ctx_801A6344 *ctx;
} Parent_801A6344;
typedef struct Task_801A6344 {
    u8 pad0[8];
    Parent_801A6344 *parent;
    u8 pad0c[0xc];
    u8 flags;
    u8 state;
    u8 pad1a[0xa];
    u8 *flag;
    MenuPanel *pan;
} Task_801A6344;
extern LayoutPart lbl_802B4A28[3];
void fn_801A6344(Task_801A6344 *t);
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
extern void fn_801B02F4(void);
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
typedef struct Task_801B2430 {
    u8 pad00[0x18];
    u8 flags;     /* 0x18 */
    u8 state;     /* 0x19 */
    u8 pad1a[0x24 - 0x1a];
    u8 *flag;     /* 0x24 */
    MenuPanel *pan;  /* 0x28 */
} Task_801B2430;
void fn_801B2430(Task_801B2430 *t);
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
typedef struct PanelTask_801B5EA8 {
    u8 pad0[0x18];
    u8 flags;   /* 0x18 */
    u8 state;   /* 0x19 */
    u8 pad1A[0x24 - 0x1A];
    u8* flag;   /* 0x24 */
    MenuPanel* ui;  /* 0x28 */
} PanelTask_801B5EA8;
extern const LayoutPart lbl_802B6DD0[2];
void fn_801B6E5C(PanelTask_801B5EA8* t);
typedef struct PanelTask_801B5FA8 {
    u8 pad0[0x18];
    u8 flags;   /* 0x18 */
    u8 state;   /* 0x19 */
    u8 pad1A[0x24 - 0x1A];
    u8* flag;   /* 0x24 */
    MenuPanel* pan; /* 0x28 */
} PanelTask_801B5FA8;
typedef struct PanelTask_801B66F8 {
    u8 pad0[0x18];
    u8 flags;   /* 0x18 */
    u8 state;   /* 0x19 */
    u8 pad1A[0x24 - 0x1A];
    u8* flag;   /* 0x24 */
    MenuPanel* pan; /* 0x28 */
} PanelTask_801B66F8;
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
typedef struct F4 {
    f32 f0, f4, f8, fc;
} F4;
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
typedef struct Holder_8019E96C {
    u8 pad0[0x28];
    MenuPanel* ui;
} Holder_8019E96C;
typedef struct Ctx_8019E96C {
    u8 pad0[4];
    u8 b4;
    u8 pad5[3];
    u8 b8;
    u8 pad9[0x217];
    Holder_8019E96C *p220;
    Holder_8019E96C *p224;
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
typedef struct Holder_8019EE4C {
    u8 pad0[0x28];
    MenuPanel* ui;
} Holder_8019EE4C;
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
    Holder_8019EE4C *p210;
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
typedef struct Holder_8019F730 {
    u8 pad0[0x28];
    MenuPanel* ui;
} Holder_8019F730;
typedef struct Ctx_8019F730 {
    u8 pad0[1];
    u8 b1;
    u8 pad2[7];
    u8 b9;
    u8 pad9[0x206];
    Holder_8019F730 *p210;
    u8 pad214[0xc];
    Holder_8019F730 *p220;
    Holder_8019F730 *p224;
    u8 pad228[0x30];
    void *p258;
} Ctx_8019F730;
typedef struct Self_8019F730 {
    u8 pad0[0x19];
    u8 state19;
    u8 pad1a[0xa];
    Ctx_8019F730 *ctx;
} Self_8019F730;
extern s32 lbl_803475D0;
extern s32 lbl_803475E0;
extern s32 fn_801A4070(void *o);
extern void fn_801A4060(void *o);
extern void fn_801A41C0(void *o);
typedef struct Holder_801A0214 {
    u8 pad0[0x28];
    MenuPanel* ui;
} Holder_801A0214;
typedef struct Ctx_801A0214 {
    u8 pad0[4];
    u8 b4;
    u8 pad5[4];
    u8 b9;
    u8 pad9[0xe];
    f32 f18;
    u8 pad1c[0x1f0];
    Holder_801A0214 *h[20];
    s32 w25c[8];
} Ctx_801A0214;
typedef struct Self_801A0214 {
    u8 pad0[0x19];
    u8 state19;
    u8 pad1a[0xa];
    Ctx_801A0214 *ctx;
} Self_801A0214;
typedef struct Ctx_801A54AC {
    u8 pad0[7];
    u8 b7;
    u8 pad8[0x10];
    f32 f18;
} Ctx_801A54AC;
typedef struct Parent_801A54AC {
    u8 pad0[0x24];
    Ctx_801A54AC *ctx;
} Parent_801A54AC;
typedef struct Task_801A54AC {
    u8 pad0[8];
    Parent_801A54AC *parent;
    u8 pad0c[0xc];
    u8 flags;
    u8 state;
    u8 pad1a[0xa];
    u8 *flag;
    MenuPanel *pan;
} Task_801A54AC;
extern LayoutPart lbl_802B4B9C[6];
extern void fn_801A5600(void *t);
#define TextPrintNumber TextPrintNumber_hdr
#undef TextPrintNumber
typedef struct Holder_801A6A88 {
    u8 pad0[0x28];
    MenuPanel* ui;
} Holder_801A6A88;
typedef struct Ctx_801A6A88 {
    u8 pad0[4];
    s16 h4;
    u8 pad6[0x1f2];
    Holder_801A6A88 *h[8];
} Ctx_801A6A88;
typedef struct Task_801A6A88 {
    u8 pad0[0x24];
    Ctx_801A6A88 *ctx;
} Task_801A6A88;
typedef struct Out_801AB580 {
    s8 flag;
    s8 type;
    s16 id;
    u8 pad4[2];
} Out_801AB580;
typedef struct Buf_801AB580 {
    u8 pad0[4];
    s16 pages;
    s16 count;
    Out_801AB580 out[0x30];
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
typedef struct { u8 pad[0x28]; MenuPanel* obj; } MP;
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
const u32 lbl_802B6A18[19] = {
    0x001E001F, 0x00200021, 0x00220023, 0x00240026, 0x00250027, 0x00280029,
    0x002A002B, 0x002C002D, 0x002E002F, 0x00300031, 0x00320033, 0x00340035,
    0x000F0010, 0x00110012, 0x00130014, 0x000E000F, 0x00100011, 0x00120013,
    0x00140035,
};
const LayoutPart lbl_802B6A64[7] = {
    {0x3, 0x27, 16.0f, 12.0f, -37.5f, 0x0, 0x1},
    {0x3, 0x34, 336.0f, 12.0f, -37.5f, 0x0, 0x1},
    {0x3, 0x27, 16.0f, 12.0f, -37.5f, 0x0, 0x1},
    {0x3, 0x34, 336.0f, 12.0f, -37.5f, 0x0, 0x1},
    {0x3, 0x33, 16.0f, 12.0f, -37.5f, 0x0, 0x1},
    {0x3, 0x34, 16.0f, 12.0f, -37.5f, 0x0, 0x1},
    {0x3, 0x24, 16.0f, 12.0f, -37.5f, 0x0, 0x1},
};
const u32 lbl_802B6AF0[4] = {
    0x001E0024, 0x00260025, 0x002F0033, 0x00350034,
};
const u32 lbl_802B6B00[3] = {
    0x001E001F, 0x00200021, 0x00220023,
};
const LayoutPart lbl_802B6B0C[4] = {
    {0x0, 0x38, 0.0f, 0.0f, -42.5f, 0x1, 0x1},
    {0x3, 0x2, 0.0f, 41.0f, -40.0f, 0x0, 0x1},
    {0x1, 0x6, 0.0f, 0.0f, -50.0f, 0x1, 0x0},
    {0x0, 0x5, 0.0f, 0.0f, -4000.0f, 0x1, 0x1},
};
const LayoutPart lbl_802B6B5C[4] = {
    {0x0, 0x39, 0.0f, 0.0f, -42.5f, 0x1, 0x1},
    {0x3, 0x25, 0.0f, 1e+01f, -4e+01f, 0x0, 0x1},
    {0x1, 0x9, 0.0f, 0.0f, -5e+01f, 0x1, 0x0},
    {0x0, 0x4, 0.0f, 0.0f, -4e+03f, 0x1, 0x1},
};
const LayoutPart lbl_802B6BAC[4] = {
    {0x0, 0x3A, 16.0f, -2.0f, -32.5f, 0x1, 0x1},
    {0x0, 0xB, 0.0f, 0.0f, -42.5f, 0x1, 0x1},
    {0x3, 0x28, 88.0f, 13.0f, -4e+01f, 0x0, 0x1},
    {0x1, 0x6, 0.0f, 0.0f, -5e+01f, 0x1, 0x0},
};
const LayoutPart lbl_802B6BFC[4] = {
    {0x0, 0x3B, 16.0f, -2.0f, -32.5f, 0x1, 0x1},
    {0x0, 0xB, 0.0f, 0.0f, -42.5f, 0x1, 0x1},
    {0x3, 0x28, 88.0f, 13.0f, -4e+01f, 0x0, 0x1},
    {0x1, 0x6, 0.0f, 0.0f, -5e+01f, 0x1, 0x0},
};
const LayoutPart lbl_802B6C4C[4] = {
    {0x0, 0x3F, 16.0f, -2.0f, -32.5f, 0x1, 0x1},
    {0x0, 0xB, 0.0f, 0.0f, -42.5f, 0x1, 0x1},
    {0x3, 0x28, 88.0f, 13.0f, -4e+01f, 0x0, 0x1},
    {0x1, 0x6, 0.0f, 0.0f, -5e+01f, 0x1, 0x0},
};
const LayoutPart lbl_802B6C9C[4] = {
    {0x0, 0x3C, 16.0f, -2.0f, -32.5f, 0x1, 0x1},
    {0x0, 0xB, 0.0f, 0.0f, -42.5f, 0x1, 0x1},
    {0x3, 0x23, 88.0f, 13.0f, -4e+01f, 0x0, 0x1},
    {0x1, 0x6, 0.0f, 0.0f, -5e+01f, 0x1, 0x0},
};
const LayoutPart lbl_802B6CEC[4] = {
    {0x0, 0x52, 16.0f, -2.0f, -32.5f, 0x1, 0x1},
    {0x0, 0xB, 0.0f, 0.0f, -42.5f, 0x1, 0x1},
    {0x3, 0x23, 88.0f, 13.0f, -4e+01f, 0x0, 0x1},
    {0x1, 0x6, 0.0f, 0.0f, -5e+01f, 0x1, 0x0},
};
const LayoutPart lbl_802B6D3C[4] = {
    {0x0, 0x3D, 16.0f, -2.0f, -32.5f, 0x1, 0x1},
    {0x0, 0xB, 0.0f, 0.0f, -42.5f, 0x1, 0x1},
    {0x3, 0x23, 88.0f, 13.0f, -4e+01f, 0x0, 0x1},
    {0x1, 0x6, 0.0f, 0.0f, -5e+01f, 0x1, 0x0},
};
const LayoutPart lbl_802B6D8C[1] = {
    {0x0, 0x5, 0.0f, 0.0f, -4e+03f, 0x1, 0x1},
};
const LayoutDef lbl_802B6DA0[6] = {
    {lbl_802B6BAC, 0x4},
    {lbl_802B6BFC, 0x4},
    {lbl_802B6C4C, 0x4},
    {lbl_802B6C9C, 0x4},
    {lbl_802B6D3C, 0x4},
    {lbl_802B6CEC, 0x4},
};
const LayoutPart lbl_802B6DD0[2] = {
    {0x0, 0x1C, 0.0f, 0.0f, -42.5f, 0x1, 0x1},
    {0x1, 0x4, 0.0f, 0.0f, -50.0f, 0x1, 0x0},
};
const LayoutPart lbl_802B6DF8[4] = {
    {0x0, 0x42, 0.0f, 0.0f, -42.5f, 0x1, 0x1},
    {0x3, 0x2A, 0.0f, 4.0f, -4e+01f, 0x0, 0x1},
    {0x1, 0x6, 0.0f, 0.0f, -5e+01f, 0x1, 0x0},
    {0x0, 0x5, 0.0f, 0.0f, -4e+03f, 0x1, 0x1},
};
const LayoutPart lbl_802B6E48[8] = {
    {0x0, 0x16, 0.0f, 2.0f, -43.0f, 0x1, 0x1},
    {0x0, 0x15, 0.0f, 166.0f, -42.5f, 0x1, 0x1},
    {0x1, 0x3, 0.0f, 0.0f, -5e+01f, 0x1, 0x0},
    {0x0, 0x1, 0.0f, 0.0f, -4e+03f, 0x1, 0x1},
    {0x0, 0x16, 0.0f, 2.0f, -43.0f, 0x1, 0x1},
    {0x0, 0x15, 0.0f, 166.0f, -42.5f, 0x1, 0x1},
    {0x1, 0x3, 0.0f, 0.0f, -5e+01f, 0x1, 0x0},
    {0x0, 0x1, 0.0f, 0.0f, -4e+03f, 0x1, 0x1},
};
const LayoutPart lbl_802B6EE8[4] = {
    {0x0, 0x50, 0.0f, 2.0f, -2e+03f, 0x1, 0x1},
    {0x0, 0x51, 0.0f, 214.0f, -2e+03f, 0x1, 0x1},
    {0x1, 0xB, 0.0f, 0.0f, -3e+03f, 0x1, 0x0},
    {0x0, 0x4F, 0.0f, 0.0f, -4e+03f, 0x1, 0x1},
};
const LayoutPart lbl_802B6F38[10] = {
    {0x0, 0x40, 0.0f, 0.0f, -42.5f, 0x1, 0x1},
    {0x3, 0x2F, 0.0f, 4.0f, -4e+01f, 0x0, 0x1},
    {0x1, 0x7, 0.0f, 0.0f, -5e+01f, 0x1, 0x0},
    {0x3, 0xE, 2.5e+02f, 6.0f, -37.15f, 0x0, 0x1},
    {0x3, 0xF, 304.0f, 6.0f, -37.2f, 0x0, 0x1},
    {0x3, 0x10, 358.0f, 6.0f, -37.25f, 0x0, 0x1},
    {0x3, 0x11, 412.0f, 6.0f, -37.3f, 0x0, 0x1},
    {0x3, 0x12, 466.0f, 6.0f, -37.35f, 0x0, 0x1},
    {0x3, 0x13, 5.2e+02f, 6.0f, -37.4f, 0x0, 0x1},
    {0x3, 0x14, 574.0f, 6.0f, -37.45f, 0x0, 0x1},
};
const LayoutPart lbl_802B7000[6] = {
    {0x0, 0x41, 0.0f, 0.0f, -42.5f, 0x1, 0x1},
    {0x3, 0x30, 0.0f, 4.0f, -4e+01f, 0x0, 0x1},
    {0x1, 0x8, 0.0f, 0.0f, -5e+01f, 0x1, 0x0},
    {0x3, 0xE, 2.5e+02f, 6.0f, -37.35f, 0x0, 0x1},
    {0x3, 0x12, 304.0f, 6.0f, -37.4f, 0x0, 0x1},
    {0x3, 0x17, 358.0f, 6.0f, -37.45f, 0x0, 0x1},
};
const LayoutPart lbl_802B7078[7] = {
    {0x0, 0x41, 0.0f, 0.0f, -42.5f, 0x1, 0x1},
    {0x3, 0x31, 0.0f, 4.0f, -4e+01f, 0x0, 0x1},
    {0x1, 0x8, 0.0f, 0.0f, -5e+01f, 0x1, 0x0},
    {0x3, 0xF, 2.5e+02f, 6.0f, -37.3f, 0x0, 0x1},
    {0x3, 0x11, 304.0f, 6.0f, -37.35f, 0x0, 0x1},
    {0x3, 0x13, 358.0f, 6.0f, -37.4f, 0x0, 0x1},
    {0x3, 0x14, 412.0f, 6.0f, -37.45f, 0x0, 0x1},
};
const LayoutPart lbl_802B7104[3] = {
    {0x0, 0x41, 0.0f, 0.0f, -42.5f, 0x1, 0x1},
    {0x3, 0x32, 0.0f, 4.0f, -4e+01f, 0x0, 0x1},
    {0x1, 0x8, 0.0f, 0.0f, -5e+01f, 0x1, 0x0},
};
const LayoutPart lbl_802B7140[2] = {
    {0x0, 0x48, 83.0f, -11.0f, -32.5f, 0x1, 0x1},
    {0x0, 0x4A, 83.0f, -11.0f, -32.4f, 0x1, 0x1},
};
const LayoutPart lbl_802B7168[1] = {
    {0x0, 0x49, 83.0f, -11.0f, -32.45f, 0x1, 0x1},
};
const LayoutDef lbl_802B717C[4] = {
    {lbl_802B6F38, 0xA},
    {lbl_802B7078, 0x7},
    {lbl_802B7000, 0x6},
    {lbl_802B7104, 0x3},
};
const LayoutPart lbl_802B719C[4] = {
    {0x0, 0x8, 0.0f, 0.0f, -4000.0f, 0x1, 0x1},
    {0x0, 0x9, 0.0f, 0.0f, -4000.0f, 0x1, 0x1},
    {0x0, 0x9, 0.0f, 0.0f, -4000.0f, 0x1, 0x1},
    {0x0, 0x9, 0.0f, 0.0f, -4000.0f, 0x1, 0x1},
};
const LayoutPart lbl_802B71EC[3] = {
    {0x0, 0x15, 0.0f, 164.0f, -42.5f, 0x1, 0x1},
    {0x1, 0x3, 0.0f, 0.0f, -5e+01f, 0x1, 0x0},
    {0x0, 0x1, 0.0f, 0.0f, -4e+03f, 0x1, 0x1},
};
const LayoutPart lbl_802B7228[2] = {
    {0x0, 0x25, 68.0f, -26.0f, 0.0f, 0x1, 0x1},
    {0x0, 0x17, 0.0f, -26.0f, -0.2f, 0x1, 0x1},
};
const LayoutPart lbl_802B7250[2] = {
    {0x0, 0x47, 116.0f, -26.0f, 0.0f, 0x1, 0x1},
    {0x0, 0x18, 0.0f, -26.0f, -0.2f, 0x1, 0x1},
};
const LayoutPart lbl_802B7278[2] = {
    {0x0, 0x24, 164.0f, -26.0f, 0.0f, 0x1, 0x1},
    {0x0, 0x19, 0.0f, -26.0f, -0.2f, 0x1, 0x1},
};
const LayoutPart lbl_802B72A0[2] = {
    {0x0, 0x26, 212.0f, -26.0f, 0.0f, 0x1, 0x1},
    {0x0, 0x1A, 0.0f, -26.0f, -0.2f, 0x1, 0x1},
};
const LayoutPart lbl_802B72C8[2] = {
    {0x0, 0x35, 2.6e+02f, -26.0f, 0.0f, 0x1, 0x1},
    {0x0, 0x1B, 0.0f, -26.0f, -0.2f, 0x1, 0x1},
};
const LayoutPart lbl_802B72F0[1] = {
    {0x0, 0x16, 0.0f, 2.0f, 0.0f, 0x1, 0x1},
};
const LayoutDef lbl_802B7304[5] = {
    {lbl_802B7228, 0x2},
    {lbl_802B7250, 0x2},
    {lbl_802B7278, 0x2},
    {lbl_802B72A0, 0x2},
    {lbl_802B72C8, 0x2},
};
const LayoutPart lbl_802B732C[2] = {
    {0x0, 0x37, 53.0f, -25.0f, -5.0f, 0x1, 0x1},
    {0x0, 0x36, 95.0f, -25.0f, -5.0f, 0x1, 0x1},
};
const LayoutPart lbl_802B7354[2] = {
    {0x0, 0x4C, 24.0f, 156.0f, -5.0f, 0x1, 0x1},
    {0x0, 0x4D, 338.0f, 156.0f, -5.0f, 0x1, 0x1},
};
const LayoutPart lbl_802B737C[2] = {
    {0x0, 0x37, 14.0f, 17.0f, -5.0f, 0x1, 0x1},
    {0x0, 0x36, 54.0f, 17.0f, -5.0f, 0x1, 0x1},
};
const AnimDef lbl_802B73A4[5] = {
    {lbl_802B7354, 0x2, 0x0, 0x1, 0x2},
    {lbl_802B732C, 0x2, 0x1, 0x1, 0x2},
    {lbl_802B7354, 0x2, 0x0, 0x1, 0x2},
    {lbl_802B737C, 0x2, 0x1, 0x1, 0x2},
    {lbl_802B737C, 0x2, 0x1, 0x1, 0x2},
};
const LayoutPart lbl_802B73F4[4] = {
    {0x0, 0xE, 0.0f, 0.0f, -42.5f, 0x1, 0x1},
    {0x3, 0x2B, 0.0f, 6.0f, -4e+01f, 0x0, 0x1},
    {0x1, 0x2, 0.0f, 0.0f, -5e+01f, 0x1, 0x1},
    {0x0, 0x3, 0.0f, 0.0f, -4e+03f, 0x1, 0x1},
};
const LayoutPart lbl_802B7444[11] = {
    {0x0, 0x1D, 0.0f, 0.0f, -42.5f, 0x1, 0x1},
    {0x3, 0x2C, 14.0f, 6.0f, -4e+01f, 0x0, 0x1},
    {0x1, 0x5, 0.0f, 0.0f, -5e+01f, 0x1, 0x0},
    {0x0, 0x7, 0.0f, 0.0f, -4e+03f, 0x1, 0x1},
    {0x3, 0xE, 4.0f, 3e+01f, -32.5f, 0x0, 0x1},
    {0x3, 0xF, 76.0f, 3e+01f, -32.5f, 0x0, 0x1},
    {0x3, 0x10, 148.0f, 3e+01f, -32.5f, 0x0, 0x1},
    {0x3, 0x11, 2.2e+02f, 3e+01f, -32.5f, 0x0, 0x1},
    {0x3, 0x12, 4.0f, 54.0f, -32.5f, 0x0, 0x1},
    {0x3, 0x13, 76.0f, 54.0f, -32.5f, 0x0, 0x1},
    {0x3, 0x14, 148.0f, 54.0f, -32.5f, 0x0, 0x1},
};
const LayoutPart lbl_802B7520[8] = {
    {0x0, 0xE, 0.0f, 0.0f, -42.5f, 0x1, 0x1},
    {0x3, 0x2D, 0.0f, 6.0f, -4e+01f, 0x0, 0x1},
    {0x1, 0x2, 0.0f, 0.0f, -5e+01f, 0x1, 0x0},
    {0x0, 0x3, 0.0f, 0.0f, -4e+03f, 0x1, 0x1},
    {0x3, 0xE, 9.0f, 3e+01f, -32.5f, 0x0, 0x1},
    {0x3, 0x12, 81.0f, 3e+01f, -32.5f, 0x0, 0x1},
    {0x3, 0x17, 153.0f, 3e+01f, -32.5f, 0x0, 0x1},
    {0x3, 0x35, 225.0f, 34.0f, -32.5f, 0x0, 0x1},
};
const LayoutPart lbl_802B75C0[16] = {
    {0x0, 0xE, 0.0f, 0.0f, -42.5f, 0x1, 0x1},
    {0x3, 0x2D, 0.0f, 6.0f, -4e+01f, 0x0, 0x1},
    {0x1, 0x2, 0.0f, 0.0f, -5e+01f, 0x1, 0x0},
    {0x0, 0x3, 0.0f, 0.0f, -4e+03f, 0x1, 0x1},
    {0x3, 0xF, 9.0f, 3e+01f, -32.5f, 0x0, 0x1},
    {0x3, 0x11, 81.0f, 3e+01f, -32.5f, 0x0, 0x1},
    {0x3, 0x13, 153.0f, 3e+01f, -32.5f, 0x0, 0x1},
    {0x3, 0x14, 225.0f, 3e+01f, -32.5f, 0x0, 0x1},
    {0x0, 0xE, 0.0f, 0.0f, -42.5f, 0x1, 0x1},
    {0x3, 0x2E, -6.0f, 28.0f, -4e+01f, 0x0, 0x1},
    {0x1, 0x2, 0.0f, 0.0f, -5e+01f, 0x1, 0x0},
    {0x0, 0x3, 0.0f, 0.0f, -4e+03f, 0x1, 0x1},
    {0x3, 0xF, 4.0f, 3e+01f, -32.5f, 0x0, 0x1},
    {0x3, 0x11, 76.0f, 3e+01f, -32.5f, 0x0, 0x1},
    {0x3, 0x13, 148.0f, 3e+01f, -32.5f, 0x0, 0x1},
    {0x3, 0x14, 2.2e+02f, 3e+01f, -32.5f, 0x0, 0x1},
};
const LayoutDef lbl_802B7700[4] = {
    {lbl_802B7444, 0xB},
    {lbl_802B75C0, 0x8},
    {lbl_802B7520, 0x8},
    {lbl_802B73F4, 0x4},
};
const LayoutPart lbl_802B7720[4] = {
    {0x0, 0x43, 0.0f, 0.0f, -42.5f, 0x1, 0x1},
    {0x3, 0x2B, 6.0f, 2e+01f, -4e+01f, 0x0, 0x1},
    {0x1, 0x1, 0.0f, 0.0f, -5e+01f, 0x1, 0x0},
    {0x0, 0x2, 0.0f, 0.0f, -4e+03f, 0x1, 0x1},
};
const LayoutPart lbl_802B7770[3] = {
    {0x0, 0xD, 0.0f, 0.0f, -42.5f, 0x1, 0x1},
    {0x3, 0x0, 85.0f, 3e+01f, -4e+01f, 0x0, 0x1},
    {0x1, 0x1, 0.0f, 0.0f, -5e+01f, 0x1, 0x0},
};
const LayoutPart lbl_802B77AC[1] = {
    {0x0, 0x2, 0.0f, 0.0f, -4000.0f, 0x1, 0x1},
};
const LayoutPart lbl_802B77C0[3] = {
    {0x0, 0xC, 0.0f, 0.0f, -42.5f, 0x1, 0x1},
    {0x3, 0x1, 1e+02f, 13.0f, -4e+01f, 0x0, 0x1},
    {0x1, 0x1, 0.0f, 0.0f, -5e+01f, 0x1, 0x0},
};
const LayoutPart lbl_802B77FC[7] = {
    {0x0, 0xF, 24.0f, -2.0f, -32.5f, 0x1, 0x1},
    {0x0, 0x10, 24.0f, -2.0f, -32.5f, 0x1, 0x1},
    {0x0, 0x11, 24.0f, -2.0f, -32.5f, 0x1, 0x1},
    {0x0, 0x12, 24.0f, -2.0f, -32.5f, 0x1, 0x1},
    {0x0, 0x13, 24.0f, -2.0f, -32.5f, 0x1, 0x1},
    {0x0, 0x14, 24.0f, -2.0f, -32.5f, 0x1, 0x1},
    {0x0, 0x3E, 24.0f, -2.0f, -32.5f, 0x1, 0x1},
};
const u32 lbl_802B7888[3] = {
    0x45717569, 0x70706564, 0x00000000,
};
const LayoutDef lbl_802B7894[7] = {
    {lbl_802B7770, 0x3},
    {lbl_802B7770, 0x3},
    {lbl_802B7770, 0x3},
    {lbl_802B7770, 0x3},
    {lbl_802B7770, 0x3},
    {lbl_802B7770, 0x3},
    {lbl_802B77C0, 0x3},
};
const LayoutPart lbl_802B78CC[7] = {
    {0x0, 0xD, 0.0f, 0.0f, -42.5f, 0x1, 0x1},
    {0x3, 0x2D, 6.0f, 6.0f, -4e+01f, 0x0, 0x1},
    {0x1, 0x1, 0.0f, 0.0f, -5e+01f, 0x1, 0x0},
    {0x3, 0xE, 16.0f, 3e+01f, -32.5f, 0x0, 0x1},
    {0x3, 0x12, 88.0f, 3e+01f, -32.5f, 0x0, 0x1},
    {0x3, 0x17, 1.6e+02f, 3e+01f, -32.5f, 0x0, 0x1},
    {0x3, 0x35, 232.0f, 34.0f, -32.5f, 0x0, 0x1},
};
const LayoutPart lbl_802B7958[7] = {
    {0x0, 0xD, 0.0f, 0.0f, -42.5f, 0x1, 0x1},
    {0x3, 0x2D, 6.0f, 6.0f, -4e+01f, 0x0, 0x1},
    {0x1, 0x1, 0.0f, 0.0f, -5e+01f, 0x1, 0x0},
    {0x3, 0xF, 16.0f, 3e+01f, -32.5f, 0x0, 0x1},
    {0x3, 0x11, 88.0f, 3e+01f, -32.5f, 0x0, 0x1},
    {0x3, 0x13, 1.6e+02f, 3e+01f, -32.5f, 0x0, 0x1},
    {0x3, 0x14, 232.0f, 3e+01f, -32.5f, 0x0, 0x1},
};
const LayoutDef lbl_802B79E4[2] = {
    {lbl_802B78CC, 0x7},
    {lbl_802B7958, 0x7},
};
const LayoutPart lbl_802B79F4[3] = {
    {0x0, 0xE, 0.0f, 0.0f, -42.5f, 0x1, 0x1},
    {0x1, 0x1, 0.0f, 0.0f, -5e+01f, 0x1, 0x0},
    {0x3, 0x24, 28.0f, 6.0f, -42.5f, 0x0, 0x1},
};
const LayoutPart lbl_802B7A30[2] = {
    {0x0, 0x27, 28.0f, 6.0f, -4e+01f, 0x1, 0x1},
    {0x3, 0x1B, 3e+01f, 3e+01f, -27.5f, 0x0, 0x1},
};
const LayoutPart lbl_802B7A58[2] = {
    {0x0, 0x28, 76.0f, 6.0f, -4e+01f, 0x1, 0x1},
    {0x3, 0x1C, 78.0f, 3e+01f, -27.5f, 0x0, 0x1},
};
const LayoutPart lbl_802B7A80[2] = {
    {0x0, 0x29, 172.0f, 6.0f, -4e+01f, 0x1, 0x1},
    {0x3, 0x1D, 174.0f, 3e+01f, -27.5f, 0x0, 0x1},
};
const LayoutPart lbl_802B7AA8[2] = {
    {0x0, 0x2A, 124.0f, 6.0f, -4e+01f, 0x1, 0x1},
    {0x3, 0x1E, 126.0f, 3e+01f, -27.5f, 0x0, 0x1},
};
const LayoutPart lbl_802B7AD0[2] = {
    {0x0, 0x2B, 2.2e+02f, 6.0f, -4e+01f, 0x1, 0x1},
    {0x3, 0x1F, 222.0f, 3e+01f, -27.5f, 0x0, 0x1},
};
const LayoutPart lbl_802B7AF8[2] = {
    {0x0, 0x2C, 268.0f, 6.0f, -4e+01f, 0x1, 0x1},
    {0x3, 0x20, 2.7e+02f, 3e+01f, -27.5f, 0x0, 0x1},
};
const LayoutDef lbl_802B7B20[6] = {
    {lbl_802B7A30, 0x2},
    {lbl_802B7A58, 0x2},
    {lbl_802B7AA8, 0x2},
    {lbl_802B7A80, 0x2},
    {lbl_802B7AD0, 0x2},
    {lbl_802B7AF8, 0x2},
};
const LayoutPart lbl_802B7B50[1] = {
    {0x0, 0x2, 0.0f, 0.0f, -4e+03f, 0x1, 0x1},
};
const LayoutDef lbl_802B7B64[6] = {
    {lbl_802B7444, 0xB},
    {lbl_802B7444, 0xB},
    {lbl_802B75C0, 0x8},
    {lbl_802B75C0, 0x8},
    {lbl_802B75C0, 0x8},
    {lbl_802B75C0, 0x8},
};
const LayoutDef lbl_802B7B94[6] = {
    {lbl_802B7444, 0xB},
    {lbl_802B7444, 0xB},
    {lbl_802B7520, 0x8},
    {lbl_802B7520, 0x8},
    {lbl_802B75C0, 0x8},
    {lbl_802B75C0, 0x8},
};
const LayoutPart lbl_802B7BC4[3] = {
    {0x0, 0x43, 0.0f, 0.0f, -42.5f, 0x1, 0x1},
    {0x3, 0x22, 0.0f, 41.0f, -4e+01f, 0x0, 0x1},
    {0x1, 0x1, 0.0f, 0.0f, -5e+01f, 0x1, 0x0},
};
const LayoutPart lbl_802B7C00[1] = {
    {0x0, 0x2, 0.0f, 0.0f, -4e+03f, 0x1, 0x1},
};
const LayoutPart lbl_802B7C14[4] = {
    {0x0, 0x44, 0.0f, 0.0f, -42.5f, 0x1, 0x1},
    {0x3, 0x29, 12.0f, 9.0f, -40.0f, 0x0, 0x1},
    {0x1, 0xA, 0.0f, 0.0f, -50.0f, 0x1, 0x0},
    {0x0, 0xA, 0.0f, 0.0f, -4000.0f, 0x1, 0x1},
};
const char lbl_802B7C64[0x1C] = "Baltor the Black Bearded";
const char lbl_802B7C80[0x18] = "Rupee of the Larso Clan";
const char lbl_802B7C98[0x10] = "Gordo the Round";
const char lbl_802B7CA8[0x14] = "Loose Cannon Lapen";
const char lbl_802B7CBC[0x14] = "The Ixa'ness Demons";
const char lbl_802B7CD0[0x18] = "Vyse the Fallen Pirate";
const char lbl_802B7CE8[0x18] = "Daikokuya the Wealthy";
const char lbl_802B7D00[0x14] = "Lord Zivilyn Bane";
const char lbl_802B7D14[0x30] = "A despicable Pirate who will attack anything.";
const char lbl_802B7D44[0x2C] = "A Nasr Pirate who attack non-Nasr airships.";
const char lbl_802B7D70[0x30] = "A Pirate who will do anything for good food.";
const char lbl_802B7DA0[0x30] = "A loner who attacks using machines he built.";
const char lbl_802B7DD0[0x30] = "Female triplets who attack ships carrying men.";
const char lbl_802B7E00[0x34] = "A Pirate who thinks he can hide behind his name.";
const char lbl_802B7E34[0x30] = "A Pirate with enough money to buy the world.";
const char lbl_802B7E64[0x2C] = "The mysterious leader of a bandit tribe.";
const char lbl_802B7E90[0xF8] = "He is known for attacking\012towns and ships throughout\012the Mid Ocean area. He is\012known for a lack of mercy.\012His favorite tactic is to\012weaken his enemy using\012The Blackbeard, his ship,\012before boarding to loot.\012Beware the power of\012his ship's cannons.";
const char lbl_802B7F88[0xEC] = "Baltor, along with his\012ship, The Blackbeard, was\012defeated by Vyse the Blue\012Rogue, but managed to\012escape. Thanks to Vyse,\012trade routes through Nasr\012and Mid Ocean are much\012safer. Rumor has it that\012Baltor has sworn vengeance\012against Vyse.";
const char lbl_802B8074[0xF8] = "He is the leader of the\012legendary Larso Clan. The\012former leader recently\012passed away, so it was\012thought that they had\012disbanded, but they have\012recently attacked Maramba.\012They are known for fierce\012strength, so prepare to\012defend and heal yourself.";
const char lbl_802B816C[0xF8] = "The new leader of the\012Larso Clan was nothing but\012a young boy. In a strange\012turn of events, that same\012boy has given up life as a\012Pirate, and has joined his\012mother in her carpet\012making business. His giant\012of a bodyguard has also\012decided to join him.";
const char lbl_802B8264[0xF8] = "An Air Pirate that only\012attacks ships carrying\012food cargo in the North\012Ocean area. He has taken\012a liking to the spice\012trade between valua and\012Ixa'taka. Learning from\012his chefs, he uses fire to\012not only cook his meals,\012but his opponents as well.";
const char lbl_802B835C[0xD8] = "There have been reports\012that after being defeated\012by the Blue Rogue, Vyse,\012Gordo has given up his\012pirate life. Apparently,\012he has opened up his own\012restaurant, a perfect fit\012for the self-proclaimed\012\"Gourmet Pirate.\"";
const char lbl_802B8434[0xF4] = "Using Gunarm, a machine of\012his own creation, this\012Pirate seems to enjoy\012wanton destruction of\012property. But, even his\012machine is capable of\012producing a multitude of\012smaller drones, as well\012as having a large arsenal\012of weaponry stored inside.";
const char lbl_802B8528[0xF0] = "It is now known that Lapen\012is the adopted son of the\012Blue Rogue, Centime. After\012being defeated by Vyse,\012Lapen realized the error\012of his ways, and started a\012new life as an engineer.\012His goal is to one day\012surpass his own father in\012skill.";
const char lbl_802B8618[0xF4] = "They target only ships that\012have handsome men as crew\012members. Knowing that,\012some men who have been\012left behind in raids have\012been psychologically\012traumatized. They are\012fierce in battle, as each\012covers the weaknesses of\012the others. Be careful.";
const char lbl_802B870C[0xFC] = "According to reports from\012Vyse the Blue Rogue, the\012men who were thought to\012have been kidnapped did in\012fact go of their own\012volition. The triplets\012have, however, agreed to\012not cause any more trouble\012but will not give up their\012search for handsome men.";
const char lbl_802B8808[0xDC] = "Once thought to be a hero,\012the once-Blue-Rogue Vyse\012has been reported to be\012robbing the people of\012Nasrad, along with his two\012female accomplices.\012Perhaps Vyse is nothing\012but a lowly scumbag of a\012Black Pirate after all.";
const char lbl_802B88E4[0xDC] = "It has been revealed that\012it was not Vyse who\012committed all those\012dastardly deeds, but a\012fake who used his name to\012further his own greed. The\012fake has decided to give\012up Piracy, and has started\012a Vyse look-alike show.";
const char lbl_802B89C0[0xFC] = "Riding aboard a gawdy ship\012plated in gold, this\012Pirate has been known to\012attack all who cross his\012path. A wealthy Yafutoman,\012he has been seen traveling\012near the Lands of Ice. It\012is said that he throws\012money at his opponents,\012confusing them in a fight.";
const char lbl_802B8ABC[0xF4] = "Lost in the Lands of Ice\012region, he was rescued by\012the Blue Rogue, Vyse. He\012promised not to cause any\012more trouble, but refused\012to give up on his dream to\012travel the world. He has\012been spotted in various\012cities buying gifts by\012the boatload.";
const char lbl_802B8BB0[0xF4] = "The supposed leader of an\012infamous clan of bandits,\012nothing is known about his\012true identity. Nobody\012knows where he is from.\012Little is known about his\012fighting tactics, other\012than his use of \"Explosive\012Powder.\" Avoid this attack\012at all costs.";
const char lbl_802B8CA4[0xB8] = "Rumor has it that Vyse\012defeated him on the new\012continent, Soltis, but it\012has yet to be confirmed.\012Perhaps now nobody will\012ever know his true\012identity, now that he is\012gone for good.";
const char lbl_802B8D5C[0xC] = "Buy Info.";
const char lbl_802B8D68[0xC] = "Sell Info.";
const char lbl_802B8D74[0xC] = "Wanted List";
const char lbl_802B8D80[0x14] = "Nothing Equipped";
const char lbl_802B8D94[0x14] = "Cannot Be Equipped";
const char lbl_802B8DA8[0x14] = "Already Equipped";
const char lbl_802B8DBC[0x10] = "Cannot Be Sold";
const char lbl_802B8DCC[0x14] = "Cannot Change Color";
const char lbl_802B8DE0[0x10] = "No Ship Owned";
const char lbl_802B8DF0[0x10] = "No Info to Buy";
const char lbl_802B8E00[0x10] = "No Info to Sell";
const char lbl_802B8E10[0x10] = "Found By Vyse";
const u32 lbl_802B8E20[5] = {
    0x466F756E, 0x64204279, 0x20446F6D, 0x696E676F, 0x00000000,
};
const u32 lbl_802B8E34[6] = {
    0xFF20FF0A, 0xFFFF4020, 0xFFC800FF, 0xFF0096FF, 0xFFFFC800, 0xFFDCDCDC,
};
const ShopCmpPos lbl_802B8E4C[14] = {
    {240.0f, 0.0f},
    {294.0f, 0.0f},
    {348.0f, 0.0f},
    {402.0f, 0.0f},
    {456.0f, 0.0f},
    {510.0f, 0.0f},
    {564.0f, 0.0f},
    {41.0f, 0.0f},
    {113.0f, 0.0f},
    {185.0f, 0.0f},
    {257.0f, 0.0f},
    {41.0f, 24.0f},
    {113.0f, 24.0f},
    {185.0f, 24.0f},
};
const s16 lbl_802B8EBC[8] = {0xF0, 0x126, 0x15C, 0x1AE, 0x29, 0x71, 0xB9, 0x118};
const s16 lbl_802B8ECC[8] = {0xF0, 0x126, 0x15C, 0x192, 0x29, 0x71, 0xB9, 0x101};
typedef struct { u8 pad[0x10]; u32 v; } W;
void fn_801B277C(Task* t);
typedef struct { u8 pad[0x24]; MenuPartWork* w; MenuPanel* obj; MenuPanel* obj2; u8 pad30[0xC]; void* p3c; } T_801B54D4;
typedef struct { f32 a, b; } FP;
extern u8 fn_801F464C(s32 id);
extern u16 fn_801B995C(s32 id);
typedef struct { s16 id; s8 count; s8 pad; } Ent_801B9810;
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
typedef struct Flg_801A0FD8 { u8 pad[8]; u32 flags; } Flg_801A0FD8;
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
 u8 pad_24[0x4]; } Ent_801AC2E4;
extern Ent_801AC2E4 lbl_802ED258[];
extern s8 fn_801BE608(s16 x);
void fn_801AC16C(Task* task);
typedef struct { u8 pad[0x24]; u8* w; MenuPanel* obj; u32 x2c; } T;
typedef struct Flg_801A0C3C { u8 pad[8]; u32 flags; } Flg_801A0C3C;
typedef struct Sub_801A0C3C { u8 pad[0x24]; MenuPartWork* w; MenuPanel* obj; } Sub_801A0C3C;
typedef struct Ctx_801A0C3C {
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
    Sub_801A0C3C *objs[8];   /* 0x20c */
    u8 pad22c[0x250 - 0x22c];
    s32 x250;
    u8 pad254[0x25c - 0x254];
    s32 slot[1];      /* 0x25c */
    u8 pad260[0x26c - 0x260];
    u8 x26c;
} Ctx_801A0C3C;
typedef struct Self_801A0C3C {
    u8 pad00[0x19];
    u8 state;
    u8 pad1a[0x24 - 0x1a];
    Ctx_801A0C3C *ctx;
} Self_801A0C3C;
typedef struct Flg_801A1B98 { u8 pad[8]; u32 flags; } Flg_801A1B98;
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
typedef struct { u8 pad[0x14]; u32 f14; u8 pad18[0x50 - 0x18]; } Tab;
extern s32 fn_801C09F8(s32 a, s32 b);
extern void fn_801A20AC(SaveTask* t);
typedef struct St_801B737C { u8 pad[0x64]; s8 seen[8]; } St_801B737C;
typedef struct Fl { u8 pad[4]; u32 f4; u8 pad8[0x18 - 8]; u32 f18; u32 f1c; u8 pad20[0x30 - 0x20]; u32 f30; u8 pad34[0x168 - 0x34]; u32 f168; u8 pad16c[4]; u32 f170; } Fl;
typedef struct UiObj UiObj;
typedef struct Slot { u8 pad[0x28]; MenuPanel* obj; } Slot;
extern void UiObjSetCommand(UiObj* obj, u16 cmd, u16 delay);
typedef struct Menu { u8 pad[0xA]; u8 cur; u8 pad2[0x230-0xB]; Slot* slot[5]; } Menu;
typedef struct Task_801AB094 { u8 pad[0x24]; Menu* m; } Task_801AB094;
typedef struct Holder_801A0E7C {
    u8 pad0[0x28];
    MenuPanel* ui;
} Holder_801A0E7C;
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
    Holder_801A0E7C *h[20];
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
typedef struct CardStampBuf {
    SaveStamp stamp;
    u8 pad8[4];
} CardStampBuf;
typedef struct CardRec {
    void *buf;
    char name[0x10];
    s32 w14;
    s32 chan;
    s32 w1c;
    SaveStamp stamp;
} CardRec;
typedef struct CardSaveData {
    char magic[0x10];  /* 0x00 lbl_802EBDD0 */
    u8 pad10[0x1b - 0x10];
    s8 b1b;            /* 0x1B */
    u8 pad1c[0x338 - 0x1c];
    u8 b338, b339, b33a, b33b; /* 0x338 */
    u8 pad33c[0x31e8 - 0x33c];
    u16 x31e8;
    u16 x31ea;
    u32 x31ec;
    u8 pad31f0[2];
    u8 stamp[10];
    u32 sum;
} CardSaveData;
/* The 0x6000-byte card file image. */
typedef struct CardImage {
    u8 hdr[0x1440];
    CardSaveData save;
} CardImage;
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
typedef struct { const char* a; const char* b; } NamePair;
typedef struct { u8 pad[0x18]; f32 f18; } Inner_801A4B40;
typedef struct { u8 pad0[0x18]; u8 flags; u8 pad19[0x24 - 0x19]; Inner_801A4B40* in; } Par_801A4B40;
typedef struct { u8 pad0[8]; Par_801A4B40* par; u8 pad_[0x18 - 0xc]; u8 flags; u8 state; } Tsk_801A4B40;
extern void SpriteObjDraw(SpriteObj* obj);
extern void SpriteObjDrawAt(SpriteObj* obj, f32* pos);
void SpriteObjDrawAtEx(SpriteObj* obj, f32* pos);
typedef struct Sub { u8 pad[0x18]; u8 flags; } Sub;
typedef struct Ent_801ABA30 { u8 pad[8]; Sub* sub; u8 pad2[0x18-0xc]; u8 flags; u8 mode; } Ent_801ABA30;
typedef struct { u8 pad[0x18]; u8 flags; } Parent;
typedef struct {
    u8 pad[0x7c];
    f32 x7c, x80, x84;
    s32 x88;
} Data;
typedef struct {
    u8 pad[8];
    Parent* parent;
    u8 pad0c[0xc];
    u8 flags;
    u8 state;
    u8 pad1a[0xa];
    Data* data;
} Self;
extern void fn_8009076C(s32 a, Data* d);
extern s32 strlen(const char* s);
extern char* const lbl_802B9428[];
typedef struct Flg_801A1958 { u8 pad[8]; u32 flags; } Flg_801A1958;
typedef struct Sub_801A1958 { u8 pad[0x28]; MenuPanel* obj; } Sub_801A1958;
typedef struct Item_801A1958 { u8 pad[0x18]; s32 kind; u8 rest[0x2c - 0x1c]; } Item_801A1958;
typedef struct Ctx_801A1958 {
    u8 pad00[1];
    u8 x1;
    u8 pad02[3];
    u8 x5;
    u8 x6;
    u8 x7;
    Item_801A1958 items[12]; /* 0x08, kind at 0x20 from the record's start - 8 */
    u8 pad[0x228 - 8 - 12 * 0x2c];
    Sub_801A1958 *objs[7];   /* 0x228 */
} Ctx_801A1958;
typedef struct Self_801A1958 {
    u8 pad00[0x19];
    u8 state;
    u8 pad1a[0x24 - 0x1a];
    Ctx_801A1958 *ctx;
} Self_801A1958;
typedef struct {
    s32 type;
    u8 pad4[0x24 - 4];
    s32 f24, f28, f2c, f30, f34, f38, f3c, f40;
} Rec;
typedef struct { u8 pad0[4]; u32 id; u8 pad8[8]; Rec* rec; } Ent_8019BED8;
typedef struct {
    u8 pad0[0x38];
    f32 f38;
    u8 pad3c[4];
    f32 f40;
    u8 pad44[4];
    s32 f48;
    u8 pad4c[0x158 - 0x4c];
    f32 v[3];
    u8 pad164[0x1b8 - 0x164];
    void* h;
    u8 pad1bc[0x1c8 - 0x1bc];
    Ent_8019BED8* ent;
    u8 pad1cc[0x20c - 0x1cc];
    s32 f20c, f210;
    u8 pad214[0x24c - 0x214];
    f32 f24c, f250, f254, f258;
} Obj_8019BED8;
extern void* fn_802258BC(s32 a, u32 b, s32 c);
extern void fn_801DCE18(f32* a, f32* b, s32 c);
typedef struct MP_801B60E8 { u8 pad[0x28]; MenuPanel* obj; } MP_801B60E8;
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
typedef struct EvHit {
    u8 pad0[0x24];
    u16 h24;      /* 0x24 ADD: collision attribute (bits 8-14 the area id) */
} EvHit;
/* The emitter parameters (EvExt.info of a sparkle map object); game/evobj.h types this pointer
 * as EvInfo, whose 0x24..0x40 fields are retyped here. */
typedef struct EvInfo {
    u8 pad0[4];
    f32 rate;      /* 0x04 ADD: spawn threshold (0..1) */
    f32 drag;      /* 0x08 ADD */
    f32 spin;      /* 0x0C ADD */
    f32 rise;      /* 0x10 ADD */
    f32 riseVar;   /* 0x14 ADD */
    f32 spread;    /* 0x18 ADD */
    f32 gravity;   /* 0x1C ADD */
    f32 side;      /* 0x20 ADD */
    s32 angVel;    /* 0x24 (EvInfo.nearDist) */
    s32 life;      /* 0x28 (EvInfo.actDist) */
    f32 minDist;   /* 0x2C (EvInfo.x2c) */
    f32 scale;     /* 0x30 (EvInfo.speed) */
    u8 pad34[4];
    f32 yOfs;      /* 0x38 (EvInfo.mode) */
    f32 height;    /* 0x3C (EvInfo.flag) */
    s32 area;      /* 0x40 ADD */
} EvInfo;
typedef struct EvExt {
    u8 pad0[0x10];
    EvInfo* info;          /* 0x10 */
} EvExt;
/* Copy of game/evobj.h's EvObj with the fields this function needs. */
typedef struct EvObj {
    u8 pad0[0x38];
    NJS_POINT3 pos;          /* 0x38 */
    u8 pad44[0xE4 - 0x44];
    void* model;             /* 0xE4 */
    u8 padE8[0x100 - 0xE8];
    NJS_TEXLIST* texlist;    /* 0x100 */
    NJS_POINT3 home;         /* 0x104 */
    u8 pad110[0x1B8 - 0x110];
    EvHit* hit;              /* 0x1B8 */
    u8 pad1BC[0x1C8 - 0x1BC];
    EvExt* ext;              /* 0x1C8 */
    u8 pad1CC[0x20C - 0x1CC];
    s32 x20c;                /* 0x20C ADD: the loop sound is playing */
    s32 x210;                /* 0x210 */
    u8 pad214[0x23C - 0x214];
    s32 x23c;                /* 0x23C ADD: the loop sound's handle */
} EvObj;
extern EvObj *lbl_80347450;
typedef struct Obj_8019CB80_8019C424 {
    u8 pad00[8];
    Flags_8019CB80* x8;
    u8 pad0c[0x18 - 0x0c];
    u8 flags;
    u8 state;
    u8 pad1a[0x24 - 0x1a];
    St* st;
    u8 pad28[0x40 - 0x28];
    St buf;                /* 0x40 ADD: the work itself */
} Obj_8019CB80_8019C424;
extern Obj_8019CB80_8019C424 *fn_80226704(void *parent, void *cb, s32 size);
extern void *fn_801C8930(void *p);
extern f32 fn_80291A5C(f32 x);
extern s32 fn_802254A0(NJS_POINT3 *p, EvHit *h);
extern s32 fn_80227810(NJS_TEXLIST *t);
extern void fn_802275A4(NJS_TEXLIST *t, s32 a);
extern void fn_80217830(s32 h);
extern void fn_80100B74(Task *t);
#define RND() (3.0517578e-05f * rand())
#define SIGN(x) (((x) > 0.0f) - ((x) < 0.0f))

void fn_80199B9C(void* p, f32 v) {
    *(f32*)((u8*)p + 0x34) = v;
}

void fn_80199BA4(void* p, u8 v) {
    *(u8*)((u8*)p + 0x40) = v;
}

void fn_80199BAC(void* p, f32 a, f32 b) {
    *(f32*)((u8*)p + 0x4) = a;
    *(f32*)((u8*)p + 0x8) = b;
}

void fn_80199BB8(void* p, f32 a, f32 b) {
    *(f32*)((u8*)p + 0xC) = a;
    *(f32*)((u8*)p + 0x10) = b;
}

void fn_80199F38(void* obj) {
    UiObjUpdate(obj);
}

void fn_8019AD94(void* p, u32 a, u32 b) {
    ((u32*)p)[0] = a;
    ((u32*)p)[1] = b;
}

void fn_8019B42C(void* p, u32 a) {
    ((u32*)p)[0] = a;
    ((u8**)p)[1] = lbl_8030741C + 8;
    ((u32*)p)[2] = 0;
}

void fn_801A289C(void) {
    lbl_80347180 = 0;
}

void fn_801A28A8(void) {
}

s32 fn_801A28AC(s32 obj) {
    s32 r;
    fn_801DC214();
    do {
        r = fn_80248708(obj, 0, 0);
    } while (r == -1);
    return fn_801A6A04(r);
}

void fn_801A2D20(u8 *obj, u32 a, u32 b) {
    *(f32 *)(*(u8 **)(obj + 0x24) + 0x1c) = (f32)a / (f32)b;
}

void fn_801A37C4(void) {
    u8* p = lbl_8034717C;
    p[1] = 0;
    lbl_8034717C[0] = 0;
}

void fn_801A4060(void* obj) {
    *(u32*)(*(u8**)((u8*)obj + 0x24) + 0x268) = 0;
}

void fn_801A41C0(void* obj) {
    void* p = *(void**)obj;
    if (p != 0) {
        fn_801E17E0(p);
    }
}

void fn_801A471C(s32 idx) {
    u8* p = lbl_803081CC + idx * 0x50;
    *(u32*)(p + 0xC) = 0;
    *(u32*)(p + 0x10) = 0;
}

extern void *lbl_80346720;
extern void fn_80005AD8(void *p, void *q);
void fn_801A49B8(void *p) {
    fn_80005AD8(lbl_80346720, p);
}

void *fn_801A4AF4(void *obj) {
    u8 *r31 = fn_80226670(obj, fn_801A4B40);
    *(void **)(r31 + 0x24) = fn_801E1A74(1, 6);
    return r31;
}

void fn_801A64B4(void* obj, s32 idx) {
    u8* p = *(u8**)((u8*)obj + 0x24);
    u8* q = *(u8**)(p + 0x20C);
    if (q == 0) {
        return;
    }
    *(u32*)(*(u8**)(q + 0x28) + 0x4C) = lbl_802B6810[(u8)idx];
}

void fn_801A6824(void *o0) {
    u8 *obj = o0;
    if (*(void **)(*(u8 **)(obj + 0x24) + 0x204) != 0) {
        fn_801E17E0(*(void **)(*(u8 **)(obj + 0x24) + 0x204));
        *(u32 *)(*(u8 **)(obj + 0x24) + 0x204) = 0;
    }
}

void fn_801A69BC() {
    UiSpritesFree();
}

void fn_801A69DC(void) {
    UiSpritesLoad(lbl_802B69D4);
}

s32 fn_801A6A04(s32 x)
{
    s32 r;
    switch (x + 13) {
    case 12:
    case 13:
        r = 0;
        break;
    case 11:
        r = 5;
        break;
    case 10:
        r = 1;
        break;
    case 8:
        r = 4;
        break;
    case 0:
    case 7:
        r = 2;
        break;
    default:
        r = 8;
        break;
    }
    return r;
}

int fn_801A6A58(int sub, int idx) {
    if (idx >= 0 && idx < 9) {
        return *(lbl_802EBEA4 + idx * 2 + sub);
    }
    return 0x29;
}

void fn_801AB98C(Obj_UNIT0000 *o)
{
    Sub_UNIT0000 *s = o->sub;
    s->fc = (float)(s32)(s->h1a * 0x18);
    o->sub->f8 = 0.0f;
}

void fn_801AC678(ShopPart* t);
ShopPart* fn_801ACD38(void* arg, u16 slot) {
    ShopPart* t = fn_802267AC(arg, fn_801AC678);
    t->flag = fn_801E1A74(1, 0x58);
    t->obj = fn_801E1A74(1, 0x6c);
    t->list = fn_801E1A74(1, 0x20);
    t->x38 = fn_801E1A74(1, 0x18);
    t->obj2 = 0;
    t->flag->w8 = slot;
    t->list->part = 4;
    t->list->flags = 3;
    t->list->page = 0;
    t->list->row = 0;
    t->obj->o.alpha_en = 0;
    ((u8*)t->flag)[0] = 0;
    t->obj->o.x = 648.0f;
    t->obj->o.tx = 648.0f;
    t->obj->o.y = 38.0f;
    t->obj->o.ty = 38.0f;
    t->obj->o.rdx = 0.0f;
    t->obj->o.rdy = 0.0f;
    *(f32*)((u8*)t->obj + 0x38) = 1.0f;
    t->obj->o.alpha = 1.0f;
    t->obj->o.z = -4500.0f;
    UiObjSetLowered(&t->obj->o);
    return t;
}

void fn_801B6400(const char* v) {
    ShopWork* w = lbl_803471B8->w;
    ShopPart* q = w->parts[7];
    if (q == 0) {
        return;
    }
    q->obj->text = v;
}

void fn_801BCFAC(u8* obj, s32 idx) {
    s32 j = *(s32*)(*(u8**)(obj + 4) + idx * 0x34);
    *(f32*)(*(u8**)obj + j * 0x14 + 0xC) = 0.59f;
}

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
typedef struct {
    u8 pad00[0x20];
    void* x20;
} Sub20;
typedef struct {
    u8 pad00[4];
    Sub20* x4;
} Obj4;
void fn_801BD5A4(void)
{
    if (lbl_803471A8 != 0) {
        fn_801D6944(lbl_803471A8);
        fn_801E17E0(lbl_803471A8);
        lbl_803471A8 = 0;
    }
    if (lbl_803471AC != 0) {
        fn_801D6944(lbl_803471AC);
        fn_801E17E0(lbl_803471AC);
        lbl_803471AC = 0;
    }
    if (lbl_803471B4 != 0) {
        fn_802275A4(((Obj4*)lbl_803471B4)->x4->x20, 0);
        fn_801E17E0(lbl_803471B4);
        lbl_803471B4 = 0;
    }
    if (lbl_803471B0 != 0) {
        fn_801E17E0(lbl_803471B0);
        lbl_803471B0 = 0;
    }
}

void fn_801BD644(void) {
    s32 b;
    void* buf;
    s32 a;
    void* src;
    void* s0;
    lbl_803471B0 = fn_801E49D8(lbl_802C39A0);
    a = fn_801E4974(lbl_803471B0, 2);
    b = fn_801E48A8(lbl_803471B0);
    buf = fn_801E1C7C(a);
    src = fn_801E4984(lbl_803471B0, 2);
    MemCopy(buf, src, a);
    lbl_803471B0 = fn_801E1584(lbl_803471B0, b - a);
    lbl_803471B4 = fn_801DB124(buf);
    fn_80227810(*(void**)((u8*)((void**)lbl_803471B4)[1] + 0x20));
    lbl_803471AC = fn_801E1C7C(0x14);
    s0 = fn_801E4984(lbl_803471B0, 0);
    fn_801D6998(lbl_803471AC, s0);
    lbl_803471A8 = fn_801E1C7C(0x14);
    fn_801D6998(lbl_803471A8, fn_801E4984(lbl_803471B0, 1));
}

void fn_801BEAE4(void* a, s32 b) {
    fn_801BEB10(a, 0, b, 0);
}

void fn_8019E33C(Task *t) {
    if (lbl_80347508 == 0) {
        u8 *p = *(u8 **)((u8 *)t->work + 0x208);
        if (p != 0) {
            p[0x18] |= 0x40;
            *(void **)((u8 *)t->work + 0x208) = 0;
        }
        fn_801A65D4(t);
        t->state = 0x20;
    }
}

void fn_8019E3E0(Task *t) {
    if (fn_801A6554(t) == 0) {
        t->state = 0x1E;
    } else if (lbl_80311A60[0]->held & 0x200) {
        fn_801A64E0(t);
        t->state = 0x1E;
    }
}

void fn_8019E5F0(Task *t) {
    fn_801A66AC(*(void **)((u8 *)t->work + 0x20C));
    if (lbl_80311A60[0]->held & 0x300) {
        fn_801A4DCC(t, 1);
        t->state = 0xC;
    }
}

void fn_8019EDEC(Task *t) {
    if (fn_801A6554(t) == 0 || (lbl_80311A60[0]->held & 0x200)) {
        fn_801A64B4(t, 5);
        t->state = 0x8;
    }
}

void fn_801A18FC(Task *t) {
    if (((u8 *)t->work)[0x1] == 1) {
        fn_801CBBAC(8.0f);
    } else {
        Ui2DBegin();
        ((u8 *)t->work)[0x2] = 0xFF;
    }
    t->state = 0x1;
}

void fn_801A2CC4(void) {
    if (lbl_8034718C[0] != 0) {
        s32 r;
        fn_801DC214();
        r = CARDUnmount(0);
        if (r == 0 || r == -3) {
            fn_801E17E0(lbl_8034718C[0]);
            lbl_8034718C[0] = 0;
        }
    }
    lbl_80347184[0] = 0;
}

void fn_801A39B4(u16 id, void *obj) {
    char buf[0x8];

    sprintf(buf, ".%03d", id);
    strcpy(obj, "SA_LEGENDS");
    strcat(obj, buf);
}

void fn_801A64E0(void *o) {
    Task *t = o;
    s32 i;

    for (i = 0; i < 0x10; i++) {
        u8 *slot = *(u8 **)((u8 *)t->work + 0x20C + i * 4);
        if (slot != 0 && *(UiObj **)(slot + 0x28) != 0) {
            UiObjFinish(*(UiObj **)(slot + 0x28));
        }
    }
}

s32 fn_801A6554(void *o) {
    Task *t = o;
    s32 i;

    for (i = 0; i < 0x10; i++) {
        u8 *slot = *(u8 **)((u8 *)t->work + 0x20C + i * 4);
        if (slot != 0 && UiObjIsBusy(*(UiObj **)(slot + 0x28)) != 0) {
            return 1;
        }
    }
    return 0;
}

void fn_801A65D4(Task *t) {
    u32 off;
    s32 i;

    for (i = 0; i < 0x10; i++) {
        off = (u16)i << 2;
        if (*(Task **)((u8 *)t->work + off + 0x20C) != 0) {
            TaskDelete(*(Task **)((u8 *)t->work + off + 0x20C));
            *(void **)((u8 *)t->work + off + 0x20C) = 0;
        }
    }
}

void fn_801A686C(void *o) {
    Task *t = o;
    *(void **)((u8 *)t->work + 0x204) = fn_801CC3C4(lbl_802B69C0);
    if (*(void **)((u8 *)t->work + 0x204) != 0) {
        *(s16 *)((u8 *)t->work + 0x10) = fn_800ED8C4(*(void **)((u8 *)t->work + 0x204));
    }
}

void *fn_801AB9D0(s32 a) {
    u8 *obj = fn_80226670((u8 *)a, fn_801ABA30);
    *(void **)(obj + 0x24) = fn_801E1A74(1, 6);
    *(u8 *)(*(u8 **)(obj + 0x24) + 0x4) = *(s16 *)(lbl_8030B4D4 + 0x2D0);
    return obj;
}

void fn_801B0B2C(u8 *obj) {
    u8 *e;
    s32 x;
    s32 y;

    TextSetColor(0xFF201008);
    e = *(u8 **)(obj + 0x28);
    x = (s32)(lbl_8034B96C + *(f32 *)(e + 0x24));
    y = (s32)(lbl_8034B8B0 + *(f32 *)(e + 0x28));
    TextPrint(x, y, *(const char **)(e + 0x4C));
}

void fn_80199F58(Obj_80199F58 *o) {
    if (o->pbc != 0) {
        fn_801E17E0(o->pbc);
    }
    if (o->f9c > 0) {
        o->f9c = 0;
        fn_801E17E0(o->p94);
        fn_801E17E0(o->p98);
    }
    if (o->fa8 > 0) {
        o->fa8 = 0;
        fn_801E17E0(o->pa0);
        fn_801E17E0(o->pa4);
    }
    if (o->fb4 > 0) {
        o->fb4 = 0;
        fn_801E17E0(o->pac);
        fn_801E17E0(o->pb0);
    }
}

void fn_8019A15C(u8 *o, s8 a, s8 b, s8 c) {
    *(s8 *)(o + 0x28) = a;
    if (a > 0) {
        *(void **)(o + 0x20) = fn_801E1C7C(a * 4);
        *(void **)(o + 0x24) = fn_801E1C7C(a * 8);
    }
    *(s8 *)(o + 0x34) = c;
    if (c > 0) {
        *(void **)(o + 0x2c) = fn_801E1C7C(c * 4);
        *(void **)(o + 0x30) = fn_801E1C7C(c * 8);
    }
    *(s8 *)(o + 0x40) = b;
    if (b > 0) {
        *(void **)(o + 0x38) = fn_801E1C7C(b * 4);
        *(void **)(o + 0x3c) = fn_801E1C7C(b * 8);
    }
}

void fn_8019B36C(u8 *o) {
    *(f32 *)(o + 0x0) = -5440.0f;
    *(f32 *)(o + 0x4) = 0.0f;
    *(f32 *)(o + 0x10) = 1.0f;
    *(f32 *)(o + 0x14) = 0.0f;
    *(f32 *)(o + 0x18) = 1.0f;
    *(f32 *)(o + 0x1c) = 0.0f;
    *(u32 *)(o + 0x8) = 0;
    *(u32 *)(o + 0xc) = 0;
    fn_8019A15C(o, 1, 0, 1);
    *(void **)(*(u8 **)(o + 0x2c)) = fn_801D68C4(lbl_803470E8, 2);
    *(f32 *)(*(u8 **)(o + 0x30) + 0x0) = 0.0f;
    *(f32 *)(*(u8 **)(o + 0x30) + 0x4) = 0.0f;
    *(void **)(*(u8 **)(o + 0x20)) = fn_801D68C4(lbl_803470F0, 10);
    *(f32 *)(*(u8 **)(o + 0x24) + 0x0) = 0.0f;
    *(f32 *)(*(u8 **)(o + 0x24) + 0x4) = 0.0f;
    *(u32 *)(o + 0x44) = 0;
}

void fn_8019E294(Self_8019E294 *o) {
    fn_801A473C(o);
    fn_801A69BC();
    if (o->ctx->b1 == 1) {
        if (o->ctx->b0 == 0) {
            fn_80226DC4();
        }
        {
            u8 ba = o->ctx->ba;
            if (ba == 1) {
                lbl_803473C4 = ba;
                lbl_80310B3C[0x21] &= 0x7fffffff;
            } else {
                lbl_803473C4 = 2;
            }
        }
    } else {
        fn_801A6824(o);
        lbl_803473C4 = 1;
        Ui2DEnd();
    }
    o->flags18 |= 0x40;
}

void fn_8019E650(Self_8019E650 *o) {
    s32 x;

    if (fn_801A2670(o->ctx->b4, &x) != 0) {
        if (x == 0) {
            fn_801A4DCC(o, 1);
            fn_801A64B4(o, 0x17);
            MenuPlaySe(0x15);
        } else {
            s32 k;
            if (x == -3) {
                k = 0x18;
            } else {
                k = (u8)(o->ctx->b4 + 0x19);
            }
            fn_801A64B4(o, k);
            MenuPlaySe(3);
        }
        o->state19 = 0x1b;
    }
}

void fn_8019FDB0(Self_8019FDB0 *o) {
    if (fn_801A6554(o) == 0 || (lbl_80311A60[0]->held & 0x100)) {
        s32 cmd;
        fn_801A64E0(o);
        cmd = 0x14;
        if (o->ctx->b8 == 0) {
            cmd = 0x15;
        }
        UiObjSetCommand(&o->ctx->p220->ui->o, (u16)cmd, 0);
        cmd = 0x14;
        if (o->ctx->b8 == 1) {
            cmd = 0x15;
        }
        UiObjSetCommand(&o->ctx->p224->ui->o, (u16)cmd, 0);
        o->state19 = 0xf;
    }
}

void fn_8019FE64(Self_8019FE64 *o) {
    s32 doit = 0;
    s32 i;

    if (fn_801A6554(o) == 0) {
        doit = 1;
    } else if (lbl_80311A60[0]->held & 0x100) {
        fn_801A64E0(o);
        doit = 1;
    }
    if (doit) {
        if (o->ctx->p220 != 0) {
            fn_801A6650((void *)o, 5);
            fn_801A6650((void *)o, 6);
        }
        if (o->ctx->p228 != 0) {
            for (i = 0; i < 7; i++) {
                fn_801A6650((void *)o, (u16)(i + 7));
            }
        }
        o->state19 = 4;
    }
}

void fn_8019FF38(Self_8019FF38 *o) {
    if (o->ctx->b4 >= 2) {
        return;
    }
    if (o->ctx->b4 == 0) {
        UiObjMoveToX(&o->ctx->p21c->ui->o, 6, 5, -8.0f);
        UiObjSetCommand(&o->ctx->p21c->ui->o, 0xf, 0);
    } else {
        UiObjMoveToX(&o->ctx->p218->ui->o, 6, 5, -8.0f);
        UiObjSetCommand(&o->ctx->p218->ui->o, 0xf, 3);
        UiObjMoveToY(&o->ctx->p21c->ui->o, 3, -1, 164.0f);
        UiObjSetCommand(&o->ctx->p21c->ui->o, 0xf, 0);
    }
    o->state19 = 0xd;
}

void fn_801A1834(Self_801A1834 *o) {
    if (o->ctx->b1 == 1 && lbl_80347508 != 0) {
        return;
    }
    fn_801A47D8(o->ctx);
    if (o->ctx->b1 == 1 && o->ctx->b0 == 0) {
        fn_80227068(0);
    }
    fn_801A69DC();
    if (o->ctx->b1 == 0) {
        if (o->ctx->h10 >= 0x3c) {
            fn_801A686C(o);
        }
        fn_801A68C4(o);
    }
    o->ctx->p208 = fn_801A4AF4(o);
    fn_801C09A4();
    fn_801CBC30();
    fn_801CBBD8();
    fn_801CBB9C(8.0f);
    o->state19 = 2;
}

void* fn_801A343C(Task_801A343C* a)
{
    Task_801A343C* o = fn_802267AC(a, fn_801A2D60);
    o->p24 = fn_801E1C7C(0x24);
    o->buf = NULL;
    o->p24->w10 = A24(a)->b04;
    o->p24->b15 = 7;
    A24(a)->h12 = 7;
    o->p24->w0c = 0;
    A24(a)->w14 = 0;
    A24(a)->w250 = 0;
    o->p24->h16 = 0;
    if (A24(a)->b01 == 0) {
        o->p24->h18 = o->p24->b15 + 1;
    } else {
        o->p24->h18 = o->p24->b15 + 3;
    }
    return o;
}

void fn_801A473C(void)
{
    s32 i;

    for (i = 0; i < 2; i++) {
        if (lbl_8034718C[i]) {
            fn_801E17E0(lbl_8034718C[i]);
            lbl_8034718C[i] = 0;
        }
    }
    if (lbl_8034716C) {
        fn_80252E5C(&lbl_8034716C);
        lbl_8034716C = 0;
    }
    if (lbl_80347168) {
        fn_80252E5C(&lbl_80347168);
        lbl_80347168 = 0;
    }
}

void* fn_801A4DCC(void* a, u16 flag)
{
    Ctl_801A4DCC* o = fn_802267AC(a, (void *)fn_801A4E58);
    o->p24 = fn_801E1A74(1, 4);
    if (flag == 0) {
        ((Wk_801A4DCC*)o->p24)->f00 = 0.1f;
        o->b19 = 0;
    } else {
        ((Wk_801A4DCC*)o->p24)->f00 = 0.1f;
        o->b19 = 1;
    }
    return o;
}

void fn_801A4E58(void *a)
{
    Ctl_801A4E58* o = a;
    Ctl_801A4E58* t = o->p08;

    if (t == 0) {
        o->b19 = 0xff;
    }
    switch (o->b19) {
    case 0:
    case 0xfe: {
        f32 f2;
        f32 f1;
        f2 = t->p24->f18;
        f1 = o->p24->f00;
        t->p24->f18 = f2 - f1;
        if (!(t->p24->f18 <= 0.4f)) {
            return;
        }
        t->p24->f18 = 0.4f;
        o->b19 = 0xff;
        break;
    }
    case 1: {
        f32 f2;
        f32 f1;
        f2 = t->p24->f18;
        f1 = o->p24->f00;
        t->p24->f18 = f2 + f1;
        if (!(t->p24->f18 >= 1.0f)) {
            return;
        }
        t->p24->f18 = 1.0f;
        o->b19 = 0xff;
        break;
    }
    case 0xff:
        o->b18 |= 0x40;
        break;
    default:
        break;
    }
}

Task_801A51A8* fn_801A51A8(void* a)
{
    Task_801A51A8* o = fn_802267AC(a, fn_801A5274);
    o->p24 = fn_801E1A74(1, 0x58);
    o->p28 = fn_801E1A74(1, 0x6c);
    o->p24[0] = 0;
    o->p28->o.alpha_en = 0;
    o->p28->o.z = -4000.0f;
    o->p28->o.x = 640.0f;
    o->p28->o.tx = 640.0f;
    o->p28->o.y = 480.0f;
    o->p28->o.ty = 480.0f;
    o->p28->o.rdx = 0.0f;
    o->p28->o.rdy = 0.0f;
    o->p28->o.alpha = 1.0f;
    o->p28->text = 0;
    return o;
}

Task_801ABE90* fn_801ABE90(void* a)
{
    Task_801ABE90* o = fn_802267AC(a, fn_801ABD40);
    o->p24 = fn_801E1A74(1, 0x58);
    o->p28 = fn_801E1A74(1, 0x6c);
    o->p28->o.alpha_en = 0;
    o->p24[0] = 0;
    o->p28->o.x = -260.0f;
    o->p28->o.tx = -260.0f;
    o->p28->o.y = 324.0f;
    o->p28->o.ty = 324.0f;
    o->p28->o.rdx = 0.0f;
    o->p28->o.rdy = 0.0f;
    o->p28->o.f38 = 1.0f;
    o->p28->o.alpha = 1.0f;
    o->p28->o.z = -4250.0f;
    o->w2c = 0;
    UiObjSetLowered(&o->p28->o);
    UiObjCalcRect(&o->p28->o);
    return o;
}

Task_801AC094* fn_801AC094(void* a)
{
    Task_801AC094* o = fn_802267AC(a, fn_801ABF70);
    o->p24 = fn_801E1A74(1, 0x58);
    o->p28 = fn_801E1A74(1, 0x6c);
    o->p28->o.alpha_en = 0;
    o->p24[0] = 0;
    o->p28->o.x = 640.0f;
    o->p28->o.tx = 640.0f;
    o->p28->o.y = 84.0f;
    o->p28->o.ty = 84.0f;
    o->p28->o.rdx = 0.0f;
    o->p28->o.rdy = 0.0f;
    o->p28->o.f38 = 1.0f;
    o->p28->o.alpha = 1.0f;
    o->p28->o.z = -4350.0f;
    o->w2c = 0;
    UiObjSetLowered(&o->p28->o);
    return o;
}

Task_801B1104* fn_801B1104(void* a)
{
    Task_801B1104* o = fn_802267AC(a, fn_801B0F1C);
    o->p24 = fn_801E1A74(1, 0x58);
    o->p28 = fn_801E1A74(1, 0x6c);
    o->p28->o.f38 = 1.0f;
    o->p28->o.alpha = 1.0f;
    o->w2c = 0;
    o->p28->h54 = 0;
    o->p24[0] = 0;
    o->p28->o.x = -348.0f;
    o->p28->o.tx = -348.0f;
    o->p28->o.y = 36.0f;
    o->p28->o.ty = 36.0f;
    o->p28->o.z = -4050.0f;
    o->p28->h52 = 0;
    o->p28->text = fn_801F4AE4((s16)lbl_803471B8->w->item);
    UiObjSetLowered(&o->p28->o);
    return o;
}

/* The two stat buffers the item and equip windows fill from an item id. */
typedef struct CmpEq { s16 id; s16 x2; s16 col; s16 v[9]; } CmpEq;
extern void fn_801C2E48(CmpEq* out, s16 id);
extern void fn_801C2CF4(CmpEq* out, s16 id);
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

void fn_801B11EC(Task_801B11EC* t) {
    f32 x;
    f32 y;
    f32 z;
    s16 id;
    CmpEq eq;
    CmpEq eq2;
    s16 ix;
    s16 iy;

    if (lbl_803475D8 != 0) {
        t->state = 0xff;
    }
    switch (t->state) {
    case 0:
    case 1:
    case 0xFE:
        if (t->flag[0] == 1) {
            return;
        }
        UiObjUpdate(&t->obj->o);
        z = TextGetZ();
        TextPushColor();
        TextSetColor(0xFF201008);
        UiLayoutDraw(&menu_sprites.texlist8, lbl_802B7700[t->obj->h52].parts,
                     lbl_802B7700[t->obj->h52].count, &t->obj->o.x, t->obj->o.z, 1.0f, 1.0f);
        TextSetZ(-27.5f + t->obj->o.z);
        id = fn_801B93E8(lbl_803471B8);
        switch (fn_801F4C24(id)) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 7:
            fn_801C2E48(&eq, id);
            break;
        case 5:
        case 6:
            fn_801C2CF4(&eq2, id);
            break;
        }
        TextSetColor(0xFF201008);
        switch (t->obj->h52) {
        case 0:
            IT_HEAD(t, id);
            y = 30.0f + t->obj->o.y;
            x = t->obj->o.x - 14.0f;
            IT_NUM(eq.v[0], x, y, 7);
            IT_NUM(eq.v[1], x, y, 8);
            IT_NUM(eq.v[2], x, y, 9);
            IT_NUM(eq.v[3], x, y, 10);
            IT_NUM(eq.v[4], x, y, 11);
            IT_NUM(eq.v[5], x, y, 12);
            IT_NUM(eq.v[6], x, y, 13);
            break;
        case 2:
            IT_HEAD(t, id);
            iy = 30.0f + t->obj->o.y;
            ix = t->obj->o.x - 14.0f;
            IT_SNUM(eq2.v[0], ix, iy, lbl_802B8EBC, 4, 0xC004);
            IT_SNUM(eq2.v[3], ix, iy, lbl_802B8EBC, 5, 0xC004);
            IT_SNUM(eq2.v[5], ix, iy, lbl_802B8EBC, 6, 0xC004);
            IT_SNUM(eq2.v[6], ix, iy, lbl_802B8EBC, 7, 0xC001);
            break;
        case 1:
            IT_HEAD(t, id);
            iy = 30.0f + t->obj->o.y;
            ix = t->obj->o.x - 14.0f;
            IT_SNUM(eq2.v[1], ix, iy, lbl_802B8ECC, 4, 0xC004);
            IT_SNUM(eq2.v[2], ix, iy, lbl_802B8ECC, 5, 0xC004);
            IT_SNUM(eq2.v[4], ix, iy, lbl_802B8ECC, 6, 0xC004);
            IT_SNUM(eq2.v[7], ix, iy, lbl_802B8ECC, 7, 0xC004);
            break;
        case 3:
            IT_HEAD(t, id);
            break;
        }
        TextPopColor(1);
        TextSetZ(z);
        break;
    case 0xFF:
        MenuDummy(t);
        t->flags |= 0x40;
        break;
    }
}

Task_801B1A78* fn_801B1A78(void* a)
{
    Task_801B1A78* o = fn_802267AC(a, fn_801B11EC);
    o->p24 = fn_801E1A74(1, 0x58);
    o->p28 = fn_801E1A74(1, 0x6c);
    o->w2c = 0;
    o->p24[0] = 0;
    o->p28->o.x = 648.0f;
    o->p28->o.tx = 648.0f;
    o->p28->o.y = 282.0f;
    o->p28->o.ty = 282.0f;
    o->p28->h54 = 0;
    o->p28->h52 = 0;
    o->p28->o.f38 = 1.0f;
    o->p28->o.alpha = 1.0f;
    o->p28->o.z = -4400.0f;
    return o;
}

/* The shop's top menu panel (the task fn_801B2310 creates). */

extern f32 njCos(s32 a);
extern void fn_801B1EA0(ShopPart* t);
s32 fn_801B94F0(void);
u16 fn_801B952C(u16 i);
void fn_801B5D68(ShopPart* t);

void fn_801B1B3C(ShopPart* t) {
    NJS_TEXLIST** tl;
    f32 z;
    f32 s;

    if (lbl_803475D8 != 0) {
        t->state = 0xFF;
    }
    switch (t->state) {
    case 0:
    case 1:
    case 0xFE:
        if (t->flag->b0 == 1) {
            return;
        }
        UiObjUpdate(&t->obj->o);
        tl = &menu_sprites.texlist8;
        UiLayoutDraw(tl, lbl_802B71EC, 3, &t->obj->o.x, t->obj->o.z, 1.0f, 1.0f);
        z = -42.75f + t->obj->o.z;
        if (fn_801B94F0()) {
            s32 i;
            const LayoutDef* p;
            UiLayoutDraw(tl, lbl_802B7304[t->list->tab].parts, lbl_802B7304[t->list->tab].count, &t->obj->o.x, z, 1.0f, 1.0f);
            z -= 0.25f;
            for (i = 0, p = lbl_802B7304; i < 5; i++, p++) {
                if (t->list->tab != i && fn_801B952C(i)) {
                    UiLayoutDraw(tl, p->parts, 2, &t->obj->o.x, z, 0.7f, 1.0f);
                    z -= 0.25f;
                }
            }
        } else {
            UiLayoutDraw(tl, lbl_802B72F0, 1, &t->obj->o.x, z, 1.0f, 1.0f);
        }
        switch (t->state) {
        case 0:
            if (fn_801B94F0()) {
                if (t->x38->state == 0) {
                    t->x38->state = 1;
                }
                t->x38->idx = 1;
                t->x38->x = t->obj->o.x + t->obj->o.rdx + (f32)(t->list->tab * 48);
                t->x38->y = t->obj->o.y + t->obj->o.rdy;
            } else {
                t->x38->state = 0;
            }
            break;
        case 1: {
            UiObj* ui;
            ShopList* c;
            t->x38->idx = 2;
            t->x38->x = t->obj->o.x;
            t->x38->y = t->obj->o.y;
            c = t->list;
            ui = &t->obj->o;
            if ((c->flags & 1) && c->part != 0xFF) {
                s = 0.0f;
                if (c->flags & 2) {
                    c->x = ui->x + c->ox;
                    c->y = ui->y + c->oy;
                    c->scale = 0.3f * njCos(c->angle) + 1.0f;
                    c->angle += 0x800;
                    s = c->scale;
                }
                UiLayoutDrawPart(tl, (void*)lbl_802B6A64, 1, &c->x, ui->z, s, 1.0f, c->part);
            }
            break;
        }
        }
        fn_801B5D68(t);
        fn_801B1EA0(t);
        break;
    case 0xFF:
        MenuDummy(t);
        t->flags |= 0x40;
        break;
    }
}

Task_801B6240* fn_801B6240(void* a, f32 x)
{
    Task_801B6240* o = fn_802267AC(a, fn_801B5EA8);
    o->p24 = fn_801E1A74(1, 0x58);
    o->p28 = fn_801E1A74(1, 0x6c);
    o->w2c = 0;
    o->p24[0] = 0;
    o->p28->o.alpha_en = 0;
    o->p28->o.x = 640.0f;
    o->p28->o.tx = 640.0f;
    o->p28->o.y = 480.0f;
    o->p28->o.ty = 480.0f;
    o->p28->o.rdx = 0.0f;
    o->p28->o.rdy = 0.0f;
    o->p28->o.alpha = 1.0f;
    o->p28->o.z = x;
    UiObjSetLowered(&o->p28->o);
    return o;
}

ShopPart* fn_801B6AE8(void* a)
{
    ShopPart* o = fn_802267AC(a, fn_801B6950);
    o->flag = fn_801E1A74(1, 0x58);
    o->obj = fn_801E1A74(1, 0x6c);
    o->flag->b0 = 0;
    o->obj->o.alpha_en = 0;
    o->obj->o.z = -4400.0f;
    o->obj->o.x = -260.0f;
    o->obj->o.tx = -260.0f;
    o->obj->o.y = 100.0f;
    o->obj->o.ty = 100.0f;
    o->obj->o.rdx = 0.0f;
    o->obj->o.rdy = 0.0f;
    o->obj->o.alpha = 1.0f;
    UiObjSetRaised(&o->obj->o);
    return o;
}


void fn_801B8E68(Task_801B8E68* t)
{
    u32 n;
    Sub2* s = t->p24;

    n = s->w11c;
    if (n == 0) {
        return;
    }
    if (lbl_80311A60[0]->held & 0x100) {
        lbl_8030B7F4.w34c += n;
        s->w11c = 0;
        if (lbl_8030B7F4.w34c >= 99999999) {
            lbl_8030B7F4.w34c = 99999999;
        }
        return;
    }
    if (n <= s->w124) {
        lbl_8030B7F4.w34c += n;
        s->w11c = 0;
        if (lbl_8030B7F4.w34c >= 99999999) {
            lbl_8030B7F4.w34c = 99999999;
        }
        return;
    }
    s->w11c = n - s->w124;
    lbl_8030B7F4.w34c += t->p24->w124;
    if (lbl_8030B7F4.w34c >= 99999999) {
        lbl_8030B7F4.w34c = 99999999;
    }
}

/* Whether there is anything to sell. inline, like fn_801B952C: fn_801B1B3C (before them) calls
 * them, fn_801B7624 (after) has them inlined. */
inline s32 fn_801B94F0(void)
{
    u32 sum = lbl_803471B8->sell[3].n;
    sum += lbl_803471B8->sell[0].n;
    sum += lbl_803471B8->sell[1].n;
    sum += lbl_803471B8->sell[2].n;
    sum += lbl_803471B8->sell[4].n;
    return sum != 0;
}

/* How many items a sell tab lists. */
inline u16 fn_801B952C(u16 k)
{
    switch (k) {
    case 0:
        return (u16)lbl_803471B8->sell[3].n;
    case 1:
        return (u16)lbl_803471B8->sell[0].n;
    case 2:
        return (u16)lbl_803471B8->sell[1].n;
    case 3:
        return (u16)lbl_803471B8->sell[2].n;
    case 4:
        return (u16)lbl_803471B8->sell[4].n;
    default:
        return 0;
    }
}

void fn_8019AB94(s16 a) {
    switch (a) {
    case 0:
        fn_801D68C4(lbl_803470EC, 4);
        break;
    case 1:
        fn_801D68C4(lbl_803470EC, 5);
        break;
    case 2:
        fn_801D68C4(lbl_803470EC, 6);
        break;
    case 3:
        fn_801D68C4(lbl_803470EC, 7);
        break;
    case 4:
        fn_801D68C4(lbl_803470EC, 8);
        break;
    case 5:
        fn_801D68C4(lbl_803470EC, 9);
        break;
    case 6:
        fn_801D68C4(lbl_803470EC, 10);
        break;
    case 7:
        fn_801D68C4(lbl_803470EC, 11);
        break;
    case 8:
        fn_801D68C4(lbl_803470EC, 12);
        break;
    case 9:
        fn_801D68C4(lbl_803470EC, 13);
        break;
    case -1:
        fn_801D68C4(lbl_803470EC, 4);
        break;
    default:
        fn_801D68C4(lbl_803470EC, 4);
        break;
    }
}

void fn_8019AC94(s16 a) {
    switch (a) {
    case 0:
        fn_801D68C4(lbl_803470F4, 5);
        break;
    case 1:
        fn_801D68C4(lbl_803470F4, 6);
        break;
    case 2:
        fn_801D68C4(lbl_803470F4, 7);
        break;
    case 3:
        fn_801D68C4(lbl_803470F4, 8);
        break;
    case 4:
        fn_801D68C4(lbl_803470F4, 9);
        break;
    case 5:
        fn_801D68C4(lbl_803470F4, 10);
        break;
    case 6:
        fn_801D68C4(lbl_803470F4, 11);
        break;
    case 7:
        fn_801D68C4(lbl_803470F4, 12);
        break;
    case 8:
        fn_801D68C4(lbl_803470F4, 13);
        break;
    case 9:
        fn_801D68C4(lbl_803470F4, 14);
        break;
    case -1:
        fn_801D68C4(lbl_803470F4, 5);
        break;
    default:
        fn_801D68C4(lbl_803470F4, 5);
        break;
    }
}

void fn_8019CB80(Obj_8019CB80* o) {
    St* s = o->st;
    if (o->x8->flags & 0x40) {
        o->flags |= 0x40;
        return;
    }
    switch (o->state) {
    case 0:
        s->xc += s->x30;
        s->x10 += s->x34;
        s->x14 += s->x38;
        s->x18 += s->x3c;
        s->x1c += s->x40;
        s->x20 += s->x44;
        s->x34 -= s->x4c;
        s->x30 *= s->x48;
        s->x38 *= s->x48;
        fn_800906E8(&s->x4);
        s->x50--;
        if (s->x50 <= 0) o->state = 0xff;
        break;
    case 0xff:
        o->flags |= 0x40;
        break;
    }
}

void fn_801A0B18(Self_801A0B18* o) {
    s32 r;
    s32 k;
    o->ctx->slot[o->ctx->idx] = fn_801A28AC(o->ctx->idx);
    if (o->ctx->slot[o->ctx->idx] != 0) {
        o->ctx->x9 = 0;
        if (1.0f != o->ctx->x18) {
            fn_801A4DCC(o, 1);
        }
        UiObjMoveToXIfChanged(&o->ctx->x210->obj->o, 6, 4, -330.0f);
        UiObjSetCommand(&o->ctx->x210->obj->o, 0xf, 0);
        k = fn_801A6A58(o->ctx->idx, o->ctx->slot[o->ctx->idx]);
        fn_801A64B4(o, (u8)k);
        MenuPlaySe(3);
        o->state = 0xb;
        r = 0;
    } else {
        r = 1;
    }
    if (r != 0 && fn_801A6554(o) == 0) {
        o->state = 9;
    }
}

void fn_801A1494(Self_801A1494* o) {
    u32 f;
    s32 k;
    if (fn_801A6554(o) == 0 || ((f = lbl_80311A60[0]->held) & 0x100)) {
        fn_801A64E0(o);
        o->state = 4;
    } else if (f & 0x400) {
        o->state = 0x1e;
    }
    if (((Sv *)lbl_803081CC)->x14 == 0 && ((Sv *)lbl_803081CC)->x64 == 0) {
        o->ctx->slot[0] = fn_801A28AC(0);
        o->ctx->slot[1] = fn_801A28AC(1);
        o->ctx->x3 = o->ctx->x2;
        o->ctx->x2 = 0;
        if (o->ctx->slot[0] != 1) o->ctx->x2++;
        if (o->ctx->slot[1] != 1) o->ctx->x2++;
    }
    if (o->ctx->x2 != 0) {
        k = (o->ctx->x1 == 0) ? 1 : 0xb;
    } else {
        k = 4;
    }
    fn_801A64B4(o, k);
}

void fn_801A1FBC(Self_801A1FBC* o) {
    SpriteObjScaled so;
    so.texlist = (NJS_TEXLIST*)menu_sprites.textlistC;
    so.a = 1.0f;
    so.b = o->ctx->x18;
    so.sx = 1.0f;
    so.sy = 1.0f;
    so.flags = 1;
    if (o->ctx->x6 != 0) {
        so.sprite = fn_801D68C4(menu_sprites.banks[0], 0xf);
        so.x = 480.0f;
        so.y = 40.0f;
        so.z = -4400.0f;
        so.flip = 1;
        SpriteObjDrawScaled(&so);
    }
    if (o->ctx->x6 != 4) {
        so.sprite = fn_801D68C4(menu_sprites.banks[0], 0x10);
        so.x = 480.0f;
        so.y = 360.0f;
        so.z = -4399.9f;
        so.flip = 1;
        SpriteObjDrawScaled(&so);
    }
}

s32 fn_801A388C(s32 chan, const char *name, s32* out) {
    s32 i;
    s32 ret;
    s32 cont;
    i = 0;
    cont = 1;
    ret = -4;
    for (; i < 0x7f && cont; i++) {
        s32 r;
        do {
            fn_801DC214();
            r = CARDGetStatus(chan, i, &lbl_803080F8);
        } while (r == -1);
        switch (r) {
        case -4:
        case -10:
            break;
        case 0:
            if (lbl_803080F8.gameName != 0x47454145) break;
            if (lbl_803080F8.company != 0x3850) break;
            if (strstr(lbl_803080F8.fileName, name) == NULL) break;
            if (out != NULL) {
                *out = (lbl_803080F8.iconAddr == -1 || lbl_803080F8.commentAddr == -1) != 0;
            }
            ret = 0;
            cont = 0;
            break;
        default:
            ret = r;
            cont = 0;
            break;
        }
    }
    return ret;
}

void* fn_801A456C(void) {
    u8* p = fn_801E1A74(1, 0x3200);
    Save* s = (Save*)p;
    MemCopy(p, lbl_802EBDD0, 0x10);
    s->x31ea = (s8)lbl_80310A1C[0x32];
    MemCopy(p + 0x10, &lbl_8030B7F4, 0x16a0);
    s->x16b0 = lbl_80311AC0.x4;
    s->x16b4 = lbl_80311AC0.x8;
    s->x16e8 = lbl_8030A794.f38;
    s->x16ec = lbl_8030A794.f3c;
    s->x16f0 = lbl_8030A794.f40;
    s->x16f4 = lbl_8030A794.w44;
    s->x16f8 = lbl_8030A794.w48;
    s->x16fc = lbl_8030A794.w4c;
    s->x1704 = lbl_8030A794.f54;
    s->x1708 = lbl_8030A794.f58;
    s->x170c = lbl_8030A794.f5c;
    s->x1710 = lbl_8030A794.w60;
    s->x1714 = lbl_8030A794.w64;
    s->x1718 = lbl_8030A794.w68;
    MemCopy(p + 0x2370, lbl_80310B3C, 0xd58);
    MemCopy(p + 0x30c8, lbl_80310A1C, 0x120);
    return p;
}

void fn_801A49E0(Hdr_801A49E0* h) {
    u16 i;
    if (h->magic != 0x20AF30) {
        OSPanic(lbl_802B49C4, 0x161, lbl_802B49D0);
    }
    h->table = (Pair_801A49E0*)((u32)h->table + (u32)h);
    for (i = 0; i < h->count; i++) {
        if (h->table[i].a != 0) {
            h->table[i].a = (Ent*)((u32)h + (u32)h->table[i].a);
            if (h->table[i].a->flag23 == 0) {
                h->table[i].a->x8 = (u32)h + h->table[i].a->x8;
                h->table[i].a->flag23 = 1;
            }
        }
        if (h->table[i].b != 0) {
            h->table[i].b = (Ent*)((u32)h + (u32)h->table[i].b);
            if (h->table[i].b->flag2 == 0) {
                h->table[i].b->x8 = (u32)h + h->table[i].b->x8;
                h->table[i].b->flag2 = 1;
            }
        }
    }
}

Node* fn_801A5BE8(void* parent, u16 mode) {
    Node* n = fn_802267AC(parent, fn_801A5D08);
    n->a = fn_801E1A74(1, 0x58);
    n->b = fn_801E1A74(1, 0x6c);
    n->a[0] = 0;
    n->b->o.alpha_en = 1;
    if (mode == 0) {
        n->b->o.z = -4250.0f;
        n->b->o.x = -240.0f;
        n->b->o.tx = -240.0f;
        n->b->o.y = 228.0f;
        n->b->o.ty = 228.0f;
        n->b->text = lbl_80346808;
    } else {
        n->b->o.z = -4300.0f;
        n->b->o.x = -240.0f;
        n->b->o.tx = -240.0f;
        n->b->o.y = 292.0f;
        n->b->o.ty = 292.0f;
        n->b->text = lbl_8034680C;
    }
    n->b->o.alpha = 1.0f;
    UiObjSetLowered(&n->b->o);
    return n;
}

SlotTask* fn_801A5EB4(void* a, u16 slot) {
    SlotTask* t = fn_802267AC(a, fn_801A5FD8);
    t->buf = fn_801E1A74(1, 0x58);
    t->pan = fn_801E1A74(1, 0x6c);
    t->buf[0] = 0;
    t->pan->o.alpha_en = 0;
    t->pan->h54 = slot;
    if (slot == 0) {
        t->pan->o.z = -4200.0f;
        t->pan->o.x = -340.0f;
        t->pan->o.tx = -340.0f;
        t->pan->o.y = 100.0f;
        t->pan->o.ty = 100.0f;
        t->pan->text = "Slot A";
    } else {
        t->pan->o.z = -4150.0f;
        t->pan->o.x = -340.0f;
        t->pan->o.tx = -340.0f;
        t->pan->o.y = 164.0f;
        t->pan->o.ty = 164.0f;
        t->pan->text = "Slot B";
    }
    t->pan->o.alpha = 1.0f;
    UiObjSetLowered(&t->pan->o);
    return t;
}

SlotTask* fn_801A6244(void* a, u16 slot) {
    SlotTask* t = fn_802267AC(a, fn_801A6344);
    t->buf = fn_801E1A74(1, 0x58);
    t->pan = fn_801E1A74(1, 0x6c);
    t->buf[0] = 0;
    t->pan->o.alpha_en = 0;
    t->pan->o.z = -4100.0f;
    t->pan->o.x = -340.0f;
    t->pan->o.tx = -340.0f;
    t->pan->o.y = 36.0f;
    t->pan->o.ty = 36.0f;
    t->pan->o.rdx = 105.0f;
    t->pan->o.rdy = 18.0f;
    t->pan->o.alpha = 1.0f;
    t->pan->h54 = slot;
    if (slot == 0) {
        t->pan->text = "Save";
    } else {
        t->pan->text = "Load";
    }
    return t;
}

void fn_801A68C4(void* tt) {
    ElemTask* t = tt;
    t->b = fn_801A456C();
    t->b->f31E8 = t->a->id;
    t->b->f31EA = (s8)lbl_80310A1C[0x32];
    t->a->f1E0 = 0;
    t->b->f31EC = 0;
    t->a->f1D8 = 1;
    t->a->f1DC = t->b->f31EA;
    t->a->f1DE = t->a->id;
    t->a->f1E0 = t->b->f31EC;
    t->a->f1E4 = t->b->f1B;
    t->a->b1E6 = t->b->b338;
    t->a->b1E7 = t->b->b339;
    t->a->b1E8 = t->b->b33A;
    t->a->b1E9 = t->b->b33B;
}

u8 fn_801AB6E8(s8 step, u8 start) {
    s32 d;
    s32 mask;
    s32 i;
    s32 n;
    mask = fn_801F4CA0();
    if (mask == 0) {
        return 0;
    }
    i = (s8)start + (d = step);
    if (i < 0) {
        i = 5;
    }
    if (i >= 6) {
        i = 0;
    }
    for (n = 0; n < 6; n++) {
        if (i == 7) {
            i = 0;
        }
        if (mask & (1 << i)) {
            return (u8)i;
        }
        i += d;
    }
    return start;
}

void fn_801ABF70(PanelTask_801ABF70* t) {
    f32 z;
    switch (t->state) {
    case 0:
    case 0xFE:
        if (t->flag[0] == 1) {
            return;
        }
        UiObjUpdate(&t->ui->o);
        UiLayoutDraw(&menu_sprites.texlist8, lbl_802B7C14, 4, &t->ui->o.x, t->ui->o.z, 1.0f, 1.0f);
        fn_801C3F5C(19.0f + t->ui->o.x, 17.0f + t->ui->o.y, -27.5f + t->ui->o.z);
        z = TextGetZ();
        TextPushColor();
        TextSetColor(0xFF201008);
        TextSetZ(-27.5f + t->ui->o.z);
        TextPopColor(1);
        TextSetZ(z);
        break;
    case 0xFF:
        MenuDummy();
        t->flags |= 0x40;
        break;
    }
}

ShopPart* fn_801ACC00(void* arg, u16 slot) {
    ShopPart* t = fn_802267AC(arg, fn_801AC48C);
    t->flag = fn_801E1A74(1, 0x58);
    t->obj = fn_801E1A74(1, 0x6c);
    t->list = fn_801E1A74(1, 0x20);
    t->x38 = fn_801E1A74(1, 0x18);
    t->obj2 = 0;
    t->flag->w8 = slot;
    t->list->part = 4;
    t->list->flags = 3;
    t->list->page = 0;
    t->list->row = 0;
    t->obj->o.alpha_en = 0;
    ((u8*)t->flag)[0] = 0;
    t->obj->o.x = 648.0f;
    t->obj->o.tx = 648.0f;
    t->obj->o.y = 38.0f;
    t->obj->o.ty = 38.0f;
    t->obj->o.rdx = 0.0f;
    t->obj->o.rdy = 0.0f;
    *(f32*)((u8*)t->obj + 0x38) = 1.0f;
    t->obj->o.alpha = 1.0f;
    t->obj->o.z = -4500.0f;
    UiObjSetLowered(&t->obj->o);
    return t;
}

void fn_801AFAA4(PanelTask_801AFAA4* t) {
    void (*cb)(PanelTask_801AFAA4*);
    f32 z;
    switch (t->state) {
    case 0:
    case 0xFE:
        if (t->data->flag == 1) {
            return;
        }
        UiObjUpdate(&t->pan->o);
        UiObjCalcRect(&t->pan->o);
        UiLayoutDraw(&menu_sprites.texlist8, lbl_802B79E4[t->pan->h54].parts,
                     lbl_802B79E4[t->pan->h54].count, t->pan->o.rect, t->pan->o.z, t->pan->o.alpha, 1.0f);
        UiLayoutDraw(&menu_sprites.texlist8, lbl_802B77AC, 1, &t->pan->o.rect[2], t->pan->o.z, 1.0f, 1.0f);
        cb = t->data->cb;
        if (cb != 0) {
            z = TextGetZ();
            TextPushColor();
            cb(t);
            TextPopColor(1);
            TextSetZ(z);
        }
        break;
    case 0xFF:
        MenuDummy();
        t->flags |= 0x40;
        break;
    }
}

Task2_801B0470* fn_801B0470(void* arg) {
    Task2_801B0470* t = fn_802267AC(arg, fn_801B02F4);
    t->data = fn_801E1A74(1, 0x58);
    t->pan = fn_801E1A74(1, 0x6c);
    *(f32*)((u8*)t->pan + 0x38) = 1.0f;
    t->pan->o.alpha = 1.0f;
    t->pan->h54 = 4;
    t->data->s6 = 6;
    t->f2C = 0;
    t->data->cb = fn_801B0B2C;
    t->pan->o.alpha_en = 0;
    t->data->b0 = 0;
    t->pan->o.x = -348.0f;
    t->pan->o.tx = -348.0f;
    t->pan->o.y = 356.0f;
    t->pan->o.ty = 356.0f;
    t->pan->o.z = -4150.0f;
    t->pan->h52 = 1;
    t->pan->text = lbl_802EBF60[6];
    UiObjSetLowered(&t->pan->o);
    return t;
}

ShopPart* fn_801B0DF8(void* arg) {
    ShopPart* t = fn_802267AC(arg, fn_801B0B9C);
    t->flag = fn_801E1A74(1, 0x58);
    t->obj = fn_801E1A74(1, 0x6c);
    t->list = fn_801E1A74(1, 0x20);
    t->x38 = fn_801E1A74(1, 0x18);
    t->obj2 = 0;
    t->x38->idx = 3;
    t->x38->state = 0;
    *(f32*)((u8*)t->obj + 0x38) = 1.0f;
    t->obj->o.alpha = 1.0f;
    *(f32*)((u8*)t->obj + 0x38) = 1.0f;
    t->obj->o.alpha = 1.0f;
    t->obj->o.z = -4300.0f;
    t->obj->o.alpha_en = 0;
    t->obj->h54 = 0;
    t->obj->h52 = 0;
    ((u8*)t->flag)[0] = 0;
    t->obj->o.x = -348.0f;
    t->obj->o.tx = -348.0f;
    t->obj->o.y = 164.0f;
    t->obj->o.ty = 164.0f;
    UiObjSetLowered(&t->obj->o);
    t->x38->state = 1;
    return t;
}

Task3_801B2310* fn_801B2310(void* arg) {
    Task3_801B2310* t = fn_802267AC(arg, fn_801B1B3C);
    t->a = fn_801E1A74(1, 0x58);
    t->pan = fn_801E1A74(1, 0x6c);
    t->c = fn_801E1A74(1, 0x20);
    t->d = fn_801E1A74(1, 0x18);
    *(f32*)((u8*)t->pan + 0x38) = 1.0f;
    t->pan->o.alpha = 1.0f;
    t->d->sA = 0;
    t->f2C = 0;
    t->c->b1E = 0;
    t->c->s1C = 0;
    t->c->s18 = 0;
    t->c->s1A = 0;
    t->c->b1F = 3;
    t->pan->h54 = 0;
    t->pan->h56 = 0;
    t->a[0] = 0;
    t->pan->o.x = 648.0f;
    t->pan->o.tx = 648.0f;
    t->pan->o.y = 100.0f;
    t->pan->o.ty = 100.0f;
    t->pan->o.z = -4500.0f;
    UiObjSetLowered(&t->pan->o);
    return t;
}

Task2_801B2678* fn_801B2678(void* arg, u16 sel) {
    Task2_801B2678* t = fn_802267AC(arg, fn_801B2430);
    t->a = fn_801E1A74(1, 0x58);
    t->pan = fn_801E1A74(1, 0x6c);
    t->pan->o.z = -4400.0f;
    *(f32*)((u8*)t->pan + 0x38) = 1.0f;
    t->pan->o.alpha = 1.0f;
    t->f2C = 0;
    t->pan->h54 = 0;
    t->a[0] = 0;
    t->pan->o.x = -240.0f;
    t->pan->o.tx = -240.0f;
    t->pan->o.y = 206.0f;
    t->pan->o.ty = 206.0f;
    if (sel == 0) {
        t->pan->text = lbl_802EC04C[3];
    } else {
        t->pan->text = lbl_802EC04C[4];
    }
    UiObjSetLowered(&t->pan->o);
    return t;
}

Task3_801B5C4C* fn_801B5C4C(void* arg) {
    Task3_801B5C4C* t = fn_802267AC(arg, fn_801B58E0);
    t->a = fn_801E1A74(1, 0x58);
    t->pan = fn_801E1A74(1, 0x6c);
    t->c = fn_801E1A74(1, 0x20);
    t->d = fn_801E1A74(1, 0x18);
    t->f2C = 0;
    t->d->s8 = 0;
    t->d->sA = 0;
    t->c->b1E = 0;
    t->c->b1F = 3;
    t->pan->o.alpha_en = 0;
    t->a[0] = 0;
    t->pan->o.x = 648.0f;
    t->pan->o.tx = 648.0f;
    t->pan->o.y = 38.0f;
    t->pan->o.ty = 38.0f;
    t->pan->o.rdx = 0.0f;
    t->pan->o.rdy = 0.0f;
    *(f32*)((u8*)t->pan + 0x38) = 1.0f;
    t->pan->o.alpha = 1.0f;
    t->pan->o.z = -4500.0f;
    UiObjSetLowered(&t->pan->o);
    return t;
}

void fn_801B5D68(ShopPart* t) {
    if (t->x38 != 0) {
        switch (t->x38->state) {
        case 0:
            t->x38->f10 = 0;
            t->x38->angle = 0;
            t->x38->scale = 1.0f;
            break;
        case 1:
            t->x38->scale = 1.0f;
            t->x38->state = 2;
            t->x38->angle = 0;
        case 2:
            if (lbl_802B73A4[t->x38->idx].flag6 != 0) {
                t->x38->scale = 1.0f - 0.7f * njSin(t->x38->angle);
                t->x38->angle += 0x400;
                t->x38->angle &= 0x7F00;
            }
            UiLayoutDraw(&menu_sprites.texlist8, lbl_802B73A4[t->x38->idx].parts, 2,
                         (f32*)t->x38, -32.5f + t->obj->o.z, 1.0f, t->x38->scale);
            break;
        }
    }
}

void fn_801B5EA8(PanelTask_801B5EA8* t) {
    f32 z;
    switch (t->state) {
    case 0:
    case 0xFE:
        if (t->flag[0] == 1) {
            return;
        }
        UiObjUpdate(&t->ui->o);
        UiLayoutDraw(&menu_sprites.texlist8, lbl_802B6DD0, 2, &t->ui->o.x, t->ui->o.z, 1.0f, 1.0f);
        z = TextGetZ();
        TextPushColor();
        TextSetColor(0xFF201008);
        fn_801B6E5C(t);
        TextSetZ(-27.5f + t->ui->o.z);
        TextPopColor(1);
        TextSetZ(z);
        break;
    case 0xFF:
        MenuDummy();
        t->flags |= 0x40;
        break;
    }
}

void fn_801B5FA8(PanelTask_801B5FA8* t) {
    f32 z;
    switch (t->state) {
    case 0:
    case 0xFE:
        if (t->flag[0] == 1) {
            return;
        }
        UiObjUpdate(&t->pan->o);
        z = TextGetZ();
        TextPushColor();
        TextSetColor(0xFF201008);
        UiLayoutDraw(&menu_sprites.texlist8, lbl_802B6DD0, 2, &t->pan->o.x, t->pan->o.z, 1.0f, 1.0f);
        if (t->pan->text != 0) {
            TextSetZ(-27.5f + t->pan->o.z);
            TextPrint(18.0f + t->pan->o.x, 12.0f + t->pan->o.y, t->pan->text);
            TextSetZ(z);
        }
        TextPopColor(1);
        break;
    case 0xFF:
        MenuDummy();
        t->flags |= 0x40;
        break;
    }
}

void fn_801B66F8(PanelTask_801B66F8* t) {
    f32 z;
    if (lbl_803475D8 != 0) {
        t->state = 0xFF;
    }
    switch (t->state) {
    case 0:
    case 0xFE:
        if (t->flag[0] == 1) {
            return;
        }
        UiObjUpdate(&t->pan->o);
        UiLayoutDraw(&menu_sprites.texlist8, lbl_802B6B0C, 4, &t->pan->o.x, t->pan->o.z, 1.0f, 1.0f);
        z = TextGetZ();
        TextSetZ(-4027.5f);
        TextPushColor();
        TextSetColor(0xFF201008);
        TextPrint(20.0f + t->pan->o.x, 20.0f + t->pan->o.y, t->pan->text);
        TextPopColor(1);
        TextSetZ(z);
        break;
    case 0xFF:
        MenuDummy(t);
        t->flags |= 0x40;
        break;
    }
}

Task2_801B6838* fn_801B6838(void* arg) {
    Task2_801B6838* t = fn_802267AC(arg, (void *)fn_801B66F8);
    t->a = fn_801E1A74(1, 0x58);
    t->pan = fn_801E1A74(1, 0x6c);
    t->a[0] = 0;
    t->pan->o.alpha_en = 0;
    t->pan->o.z = -4000.0f;
    t->pan->o.x = -260.0f;
    t->pan->o.tx = -260.0f;
    t->pan->o.y = 36.0f;
    t->pan->o.ty = 36.0f;
    t->pan->o.rdx = 0.0f;
    t->pan->o.rdy = 0.0f;
    t->pan->o.alpha = 1.0f;
    if (lbl_803473BF == 0) {
        t->pan->text = lbl_802EC0A0[lbl_803473BC].label;
    } else {
        t->pan->text = lbl_802ED218[lbl_803473BC].label;
    }
    UiObjSetRaised(&t->pan->o);
    return t;
}


s32 fn_801B93E8(ShopTask* t) {
    s32 r = -1;
    ShopList* s = t->w->parts[8]->list;
    u16 idx = s->row + s->page * 6;
    s16* p;
    switch (s->tab) {
    case 0:
        p = lbl_803471B8->sell[3].e[idx];
        if (p != 0) r = *p;
        break;
    case 1:
        p = lbl_803471B8->sell[0].e[idx];
        if (p != 0) r = *p;
        break;
    case 2:
        p = lbl_803471B8->sell[1].e[idx];
        if (p != 0) r = *p;
        break;
    case 3:
        p = lbl_803471B8->sell[2].e[idx];
        if (p != 0) r = *p;
        break;
    case 4:
        p = lbl_803471B8->sell[4].e[idx];
        if (p != 0) r = *p;
        break;
    }
    return r;
}

s32 fn_80199FFC(PosTabs *t, s8 idx, s32 val, s16 x, s16 y, s8 kind)
{
    switch (kind) {
    case 0:
        t->a0[idx] = val;
        t->f0[idx * 2] = x;
        t->f0[idx * 2 + 1] = y;
        break;
    case 1:
        t->a1[idx] = val;
        t->f1[idx * 2] = x;
        t->f1[idx * 2 + 1] = y;
        break;
    case 2:
        t->a2[idx] = val;
        t->f2[idx * 2] = x;
        t->f2[idx * 2 + 1] = y;
        break;
    }
    return val;
}

void fn_8019B44C(Self_8019B44C *self) {
    extern void fn_80199F38(void *ui);
    extern void UiObjCalcRect(void *ui);
    extern void CampPanelDrawFrame(void);
    extern void fn_8019BB54(Ctx_8019B44C *c);
    extern void fn_8019B980(Ctx_8019B44C *c);
    extern void fn_8019B59C(Ctx_8019B44C *c);
    extern void fn_801E17E0(void *p);
    extern void fn_80199F58(Ctx_8019B44C *c);
    Ctx_8019B44C *ctx = self->ctx;
    void *ui = ctx->ui;
    Sub_8019B44C *sub = ctx->pbc;

    if (lbl_803475D8 != 0) {
        self->state19 = 0xff;
    }
    switch (self->state19) {
    case 0xfe:
    case 0:
        self->state19 = 1;
        sub->w8 = 0;
    case 1:
        fn_80199F38(ui);
        UiObjCalcRect(ui);
        if (self->ctx->w0 == 1) {
            CampPanelDrawFrame();
            switch (sub->mode) {
            case 0:
                fn_8019BB54(self->ctx);
                break;
            case 1:
                fn_8019B980(self->ctx);
                break;
            case 2:
                fn_8019B59C(self->ctx);
                break;
            }
        }
        break;
    case 100:
        self->state19 = 0xff;
        break;
    case 0xff:
        if (sub->w8 != 0) {
            fn_801E17E0(sub->w8);
            sub->w8 = 0;
        }
        fn_80199F58(self->ctx);
        self->flags18 |= 0x40;
        break;
    }
}

void fn_8019BD2C(Obj48 *o, s32 mode) {
    extern void *lbl_803470F0, *lbl_803470E8, *lbl_803470F4;
    extern void *fn_801D68C4(void *a, u32 n);
    extern void fn_8019A15C(void *p, s32 a, s32 b, s32 c);
    extern void fn_80199FFC(void *p, s32 a, void *b, s32 c, s32 d, s32 e);
    o->f00 = -4000.0f;
    o->f04 = 0.0f;
    o->f10 = 1.0f;
    o->f14 = 0.0f;
    o->f18 = 1.0f;
    o->f1c = 0.0f;
    o->i08 = 0;
    o->i0c = 0;
    switch (mode) {
    case 0:
    case 1:
        fn_8019A15C(o, 1, 1, 1);
        fn_80199FFC(o, 0, fn_801D68C4(lbl_803470F4, 0x4e), 0, 0, 2);
        o->p20->p0 = fn_801D68C4(lbl_803470F0, 0x68);
        o->p24->f0 = 0.0f;
        o->p24->f4 = 0.0f;
        o->p2c->p0 = fn_801D68C4(lbl_803470E8, 0xb);
        o->p30->f0 = 0.0f;
        o->p30->f4 = 0.0f;
        o->p44 = fn_801D68C4(lbl_803470F0, 0x6a);
        break;
    case 2:
        fn_8019A15C(o, 2, 0, 1);
        o->p20->p0 = fn_801D68C4(lbl_803470F0, 0x20);
        o->p24->f0 = 0.0f;
        o->p24->f4 = 2.0f;
        o->p20->p4 = fn_801D68C4(lbl_803470F0, 0x1f);
        o->p24->f8 = 0.0f;
        o->p24->fc = 330.0f;
        o->p2c->p0 = fn_801D68C4(lbl_803470E8, 0xc);
        o->p30->f0 = 0.0f;
        o->p30->f4 = 0.0f;
        o->p44 = fn_801D68C4(lbl_803470F0, 0x6b);
        break;
    }
}

void fn_8019E96C(Self_8019E96C *self) {
    s32 r = fn_801A28AC(self->ctx->b4);
    if (r == 1) {
        self->ctx->w25c[self->ctx->b4] = r;
        UiObjMoveToX(&self->ctx->p220->ui->o, 6, 5, -240.0f);
        UiObjSetCommand(&self->ctx->p220->ui->o, 0x1a, 2);
        UiObjMoveToX(&self->ctx->p224->ui->o, 6, 5, -240.0f);
        UiObjSetCommand(&self->ctx->p224->ui->o, 0x1a, 0);
        MenuPlaySe(3);
        fn_801A64B4(self, 4);
        self->state19 = 0x17;
    } else if (fn_801A6554(self) == 0 || (lbl_80311A60[0]->held & 0x100) != 0) {
        u32 cmd;
        fn_801A64E0(self);
        cmd = 0x14;
        if (self->ctx->b8 == 0) {
            cmd = 0x15;
        }
        UiObjSetCommand(&self->ctx->p220->ui->o, cmd, 0);
        cmd = 0x14;
        if (self->ctx->b8 == 1) {
            cmd = 0x15;
        }
        UiObjSetCommand(&self->ctx->p224->ui->o, cmd, 0);
        self->state19 = 0x19;
    }
}

void fn_8019EE4C(Self_8019EE4C *self) {
    extern void fn_801A64B4(void *o, u8 k);
    extern void fn_801A1B98(void *o, s32 k);
    extern u32 fn_801A6A58(int sub, int idx);
    s32 k;
    if (fn_801A6554(self) != 0) {
        return;
    }
    if (self->ctx->wc != 0) {
        self->ctx->wc--;
    }
    if (self->ctx->wc == 0 || (lbl_80311A60[0]->held & 0x300) != 0) {
        fn_801A1B98(self, 1);
        fn_801A4DCC(self, 1);
        UiObjMoveToXIfChanged(&self->ctx->p210->ui->o, 6, 4, -330.0f);
        UiObjSetCommand(&self->ctx->p210->ui->o, 0xf, 0);
        self->state19 = 0x16;
    } else if ((lbl_80311A60[0]->held & 0x400) != 0) {
        self->state19 = 0x1e;
    }
    self->ctx->w25c[self->ctx->b4] = fn_801A28AC(self->ctx->b4);
    if (self->ctx->w25c[self->ctx->b4] != 0) {
        self->ctx->b9 = 0;
        if (1.0f != self->ctx->f18) {
            fn_801A4DCC(self, 1);
        }
        UiObjMoveToXIfChanged(&self->ctx->p210->ui->o, 6, 4, -330.0f);
        UiObjSetCommand(&self->ctx->p210->ui->o, 0xf, 0);
        k = fn_801A6A58(self->ctx->b4, self->ctx->w25c[self->ctx->b4]);
        fn_801A64B4(self, k);
        MenuPlaySe(3);
        self->state19 = 0xb;
    }
}

void fn_8019F730(Self_8019F730 *self) {
    if (fn_801A6554(self) != 0) {
        return;
    }
    if (self->ctx->b1 == 1) {
        if (fn_801A4070(self) == 0) {
            self->ctx->b9 = 0;
            fn_801A41C0(self->ctx->p258);
            self->ctx->p258 = 0;
            fn_801A64B4(self, 0x28);
            MenuPlaySe(3);
            UiObjMoveToXIfChanged(&self->ctx->p210->ui->o, 6, 4, -330.0f);
            UiObjSetCommand(&self->ctx->p210->ui->o, 0xf, 0);
            UiObjMoveToX(&self->ctx->p220->ui->o, 6, 5, -240.0f);
            UiObjSetCommand(&self->ctx->p220->ui->o, 0x1a, 2);
            UiObjMoveToX(&self->ctx->p224->ui->o, 6, 5, -240.0f);
            UiObjSetCommand(&self->ctx->p224->ui->o, 0x1a, 0);
            fn_801A4DCC(self, 1);
            lbl_803475D0 = 0;
            lbl_803475E0 = 0;
            self->state19 = 0x17;
        } else {
            self->state19 = 0x12;
        }
    } else {
        fn_801A4060(self);
        self->state19 = 0x14;
    }
}

void fn_801A0214(Self_801A0214 *self) {
    extern void fn_801A64B4(void *o, u8 k);
    extern u32 fn_801A6A58(int sub, int idx);
    extern s32 fn_801C09F8(s32 a, s32 b);
    s32 i;
    s32 k;
    if (fn_801A6554(self) == 0 || fn_801C09F8(0, 4) != 0 || fn_801C09F8(0, 5) != 0) {
        for (i = 0; i < 7; i++) {
            s32 j = i + 7;
            Holder_801A0214 *h = self->ctx->h[j];
            if (h != 0 && h->ui != 0) {
                UiObjFinish(&h->ui->o);
            }
        }
        self->state19 = 9;
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
        }
    }
}

void fn_801A54AC(Task_801A54AC *t) {
    Parent_801A54AC *parent = t->parent;
    f32 z;
    switch (t->state) {
    case 0:
    case 0xFE:
        if (t->flag[0] == 1) {
            return;
        }
        UiObjUpdate(&t->pan->o);
        if (-132.0f < t->pan->o.y && t->pan->o.y < 370.0f) {
            if (UiObjIsBusy(&t->pan->o) == 0 && t->pan->h54 == parent->ctx->b7) {
                t->pan->o.alpha = 1.0f;
            } else {
                t->pan->o.alpha = 0.5f;
            }
            UiLayoutDraw(&menu_sprites.texlist8, lbl_802B4B9C, 6, &t->pan->o.x, t->pan->o.z, t->pan->o.alpha * t->parent->ctx->f18, 1.0f);
            TextPushColor();
            z = TextGetZ();
            fn_801A5600(t);
            TextSetZ(z);
            TextPopColor(1);
        }
        break;
    case 0xFF:
        t->flags |= 0x40;
        break;
    }
}

void fn_801A6A88(Task_801A6A88 *t, u16 idx, f32 off) {
    extern void TextPrintNumber(s32 x, s32 y, s32 value, u32 flags);
    f32 z = TextGetZ();
    TextPushColor();
    TextSetColor(0xFF2222F0);
    TextSetZ(-27.5f + t->ctx->h[idx]->ui->o.z);
    TextPrint((s32)(336.0f + (t->ctx->h[idx]->ui->o.x + t->ctx->h[idx]->ui->o.rdx)),
              (s32)(off + (t->ctx->h[idx]->ui->o.y - t->ctx->h[idx]->ui->o.rdy)), "\x81\x7e");
    TextPrintNumber((s32)(360.0f + (t->ctx->h[idx]->ui->o.x + t->ctx->h[idx]->ui->o.rdx)),
                    (s32)(off + (t->ctx->h[idx]->ui->o.y - t->ctx->h[idx]->ui->o.rdy)), t->ctx->h4, 0xC002);
    TextPopColor(1);
    TextSetZ(z);
}

void fn_801AB580(Self_801AB580 *self) {
    ShopData *row = &lbl_802EC0A0[lbl_803473BC];
    u32 i = 0;
    u32 n = 0;
    for (; i < 0x30; i++) {
        if (row->item[i] != -1) {
            s16 id;
            u8 flag;
            self->buf->out[i].id = row->item[i];
            self->buf->out[i].type = fn_801F4C24(row->item[i]);
            id = (u16)row->item[i];
            if (fn_801F477C(id) == 0) {
                flag = 1;
            } else if (lbl_8030B7F4.w34c / fn_801F477C(id) == 0) {
                flag = 1;
            } else if (fn_801F452C(id) == 99) {
                flag = 1;
            } else {
                flag = 0;
            }
            self->buf->out[i].flag = flag;
            n++;
        } else {
            self->buf->out[i].type = -1;
            self->buf->out[i].id = -1;
            self->buf->out[i].flag = -1;
        }
    }
    self->buf->count = n;
    self->buf->pages = n / 6 + (n % 6 != 0);
}

u8 fn_801AB82C(s32 mode, u8 cur, s32 idxp) {
    s16 idx = idxp;
    u32 max;
    u32 v;
    s32 lim;

    max = (u32)lbl_8030B7F4.w34c / fn_801F477C(idx);
    if (max == 0) {
        return 0;
    }
    if (max > 99) {
        max = 99;
    }
    lim = 99 - fn_801F452C(idx);
    if (max > lim) {
        max = lim;
    }
    v = cur;
    switch (mode) {
    case 4:
        if (v > 1) {
            v--;
        }
        break;
    case 8:
        if (v < max) {
            v++;
        }
        break;
    case 1:
        if (max + 1 < 10) {
            v = 1;
        } else {
            if (v < 10) {
                v = 1;
            } else {
                v -= 10;
            }
            if (v == 0) {
                v = 1;
            }
        }
        break;
    case 2:
        if (max + 1 < 10) {
            v = max;
        } else {
            v += 10;
            if (v >= max + 1) {
                v = max;
            }
        }
        break;
    }
    if (v != cur) {
        MenuPlaySe(0);
    }
    return v;
}

void fn_801AC16C(Task* task) {
    extern void MenuDummy(Task* t);
    extern TextNode* TextPrint(s32 x, s32 y, const char *str);
    extern void* fn_802267AC(void* a, void (*b)(Task*));
    extern void* fn_801E1A74(s32 a, s32 b);
    MP* p = (MP*)task;
    f32 z;
    NJS_TEXLIST** tl;
    switch (task->state) {
    case 0:
    case 0xFE:
        if (*(u8*)task->work == 1) {
            return;
        }
        UiObjUpdate(&p->obj->o);
        UiObjCalcRect(&p->obj->o);
        tl = &menu_sprites.texlist8;
        UiLayoutDraw(tl, (void*)lbl_802B7BC4, 3, p->obj->o.rect, p->obj->o.z, 1.0f, 1.0f);
        UiLayoutDraw(tl, (void*)lbl_802B7C00, 1, &p->obj->o.rect[2], p->obj->o.z, 1.0f, 1.0f);
        z = TextGetZ();
        TextPushColor();
        TextSetColor(0xFF201008);
        TextSetZ(-27.5f + p->obj->o.z);
        if (p->obj->text != NULL) {
            TextPrint((s32)(24.0f + p->obj->o.rect[0]), (s32)(20.0f + p->obj->o.rect[1]), p->obj->text);
        }
        TextPopColor(1);
        TextSetZ(z);
        break;
    case 0xFF:
        MenuDummy(task);
        task->flags |= 0x40;
        break;
    }
}

void fn_801ACE70(Task* task) {
    extern void MenuDummy(Task* t);
    extern TextNode* TextPrint(s32 x, s32 y, const char *str);
    extern void* fn_802267AC(void* a, void (*b)(Task*));
    extern void* fn_801E1A74(s32 a, s32 b);
    extern void fn_801AD1D4(Task* t);
    extern s32 fn_801C09F8(s32 a, s32 b);
    extern s32 UiLayoutDraw2(NJS_TEXLIST** t, void* parts, u32 count, f32* pos, f32 z, f32 a, f32 b);
    MP2* p = (MP2*)task;
    f32 z;
    NJS_TEXLIST** tl;
    switch (task->state) {
    case 0:
    case 0xFE:
        if (*(u8*)task->work == 1) {
            return;
        }
        UiObjUpdate(&p->obj->o);
        UiObjUpdate(&p->obj2->o);
        UiObjCalcRect(&p->obj->o);
        UiObjCalcRect(&p->obj2->o);
        tl = &menu_sprites.texlist8;
        UiLayoutDraw(tl, lbl_802B7B64[p->obj->h54].parts, lbl_802B7B64[p->obj->h54].count, p->obj->o.rect, p->obj->o.z, p->obj->o.alpha, 1.0f);
        UiLayoutDraw(tl, lbl_802B7B94[p->obj2->h54].parts, lbl_802B7B94[p->obj2->h54].count, p->obj2->o.rect, p->obj2->o.z, p->obj2->o.alpha, 1.0f);
        z = TextGetZ();
        TextPushColor();
        fn_801AD1D4(task);
        TextPopColor(1);
        TextSetZ(z);
        switch (p->obj->h54) {
        case 1:
            if (fn_801C09F8(0, 10) != 0) {
                ((W*)task->work)->v++;
                ((W*)task->work)->v &= 1;
                MenuPlaySe(4);
            }
            break;
        }
        break;
    case 0xFF:
        MenuDummy(task);
        task->flags |= 0x40;
        break;
    }
}

void fn_801B277C(Task* task) {
    extern void MenuDummy(Task* t);
    extern TextNode* TextPrint(s32 x, s32 y, const char *str);
    extern void* fn_802267AC(void* a, void (*b)(Task*));
    extern void* fn_801E1A74(s32 a, s32 b);
    extern void fn_801B28D4(Task* t);
    extern s32 fn_801C09F8(s32 a, s32 b);
    MP* p = (MP*)task;
    if (lbl_803475D8 != 0) {
        task->state = 0xFF;
    }
    switch (task->state) {
    case 0:
    case 0xFE:
        if (*(u8*)task->work == 1) {
            return;
        }
        UiObjCalcRect(&p->obj->o);
        UiObjUpdate(&p->obj->o);
        if (p->obj->h52 != 4) {
            fn_801B28D4(task);
        }
        if (p->obj->h52 == 0) {
            if (fn_801C09F8(0, 10) != 0) {
                ((W*)task->work)->v++;
                if (((W*)task->work)->v == 3) {
                    ((W*)task->work)->v = 0;
                }
                MenuPlaySe(4);
            }
        } else if (p->obj->h52 == 1 || p->obj->h52 == 2) {
            if (fn_801C09F8(0, 10) != 0) {
                ((W*)task->work)->v++;
                ((W*)task->work)->v &= 1;
                MenuPlaySe(4);
            }
        }
        break;
    case 0xFF:
        MenuDummy(task);
        task->flags |= 0x40;
        break;
    }
}

void* fn_801B54D4(void* a) {
    extern void MenuDummy(Task* t);
    extern TextNode* TextPrint(s32 x, s32 y, const char *str);
    extern void* fn_802267AC(void* a, void (*b)(Task*));
    extern void* fn_801E1A74(s32 a, s32 b);
    T_801B54D4* t = fn_802267AC(a, fn_801B277C);
    t->w = fn_801E1A74(1, 0x58);
    t->obj = fn_801E1A74(1, 0x6c);
    t->obj2 = fn_801E1A74(1, 0x6c);
    t->p3c = fn_801E1A74(1, 0x9c);
    t->w->b0 = 0;
    t->w->h4 = 0;
    t->obj2->h54 = 0;
    t->obj->h54 = 0;
    t->obj2->h52 = 4;
    t->obj->h52 = 4;
    t->obj->o.z = -4700.0f;
    t->obj2->o.z = -4750.0f;
    t->obj2->o.alpha_en = 0;
    t->obj->o.alpha_en = 0;
    t->obj2->o.alpha = 1.0f;
    *(f32*)((u8*)t->obj2 + 0x38) = 1.0f;
    t->obj->o.alpha = 1.0f;
    *(f32*)((u8*)t->obj + 0x38) = 1.0f;
    t->obj2->o.x = -624.0f;
    t->obj2->o.tx = -624.0f;
    t->obj->o.x = -624.0f;
    t->obj->o.tx = -624.0f;
    t->obj2->o.y = 212.0f;
    t->obj2->o.ty = 212.0f;
    t->obj->o.y = 212.0f;
    t->obj->o.ty = 212.0f;
    UiObjSetLowered(&t->obj->o);
    t->w->w8 = -1;
    t->w->wc = 0;
    t->w->w10 = 0;
    return t;
}

void fn_801B6420(Task* task) {
    extern void MenuDummy(Task* t);
    extern TextNode* TextPrint(s32 x, s32 y, const char *str);
    extern void* fn_802267AC(void* a, void (*b)(Task*));
    extern void* fn_801E1A74(s32 a, s32 b);
    extern FP lbl_802EC01C[];
    MP* p = (MP*)task;
    NJS_TEXLIST** tl;
    f32 z;
    if (lbl_803475D8 != 0) {
        task->state = 0xFF;
    }
    switch (task->state) {
    case 0:
    case 0xFE:
        if (*(u8*)task->work == 1) {
            return;
        }
        UiObjUpdate(&p->obj->o);
        UiObjCalcRect(&p->obj->o);
        tl = &menu_sprites.texlist8;
        UiLayoutDraw(tl, lbl_802B6DA0[p->obj->h54].parts, lbl_802B6DA0[p->obj->h54].count, p->obj->o.rect, p->obj->o.z, p->obj->o.alpha, 1.0f);
        UiLayoutDraw(tl, (void*)lbl_802B6D8C, 1, &p->obj->o.rect[2], p->obj->o.z, 1.0f, 1.0f);
        z = TextGetZ();
        TextPushColor();
        TextSetColor(0xFF201008);
        TextSetZ(-27.5f + p->obj->o.z);
        TextPrint((s32)(p->obj->o.rect[0] + lbl_802EC01C[p->obj->h56].b), (s32)(17.0f + p->obj->o.rect[1]), p->obj->text);
        TextPopColor(1);
        TextSetZ(z);
        break;
    case 0xFF:
        MenuDummy(task);
        task->flags |= 0x40;
        break;
    }
}

s32 fn_801B8F48(s32 mode, s16* sel, s16 id) {
    extern void MenuDummy(Task* t);
    extern TextNode* TextPrint(s32 x, s32 y, const char *str);
    extern void* fn_802267AC(void* a, void (*b)(Task*));
    extern void* fn_801E1A74(s32 a, s32 b);
    extern u8 fn_801F464C(s32 id);
    extern u16 fn_801F477C(s32 id);
    extern s8 fn_801F452C(s32 id);
    extern u16 fn_801B995C(s32 id);
    u32 total;
    u32 cnt = fn_801F464C(id);
    s32 cur;
    s32 n;
    if (cnt == 0) {
        total = 0;
    } else {
        total = cnt * fn_801F477C(id) / 100;
    }
    if (total == 0) {
        return -1;
    }
    n = fn_801F452C(id) - fn_801B995C(id);
    cur = *sel;
    switch (mode) {
    case 4:
        if (cur > 1) {
            *sel = cur - 1;
        }
        break;
    case 8:
        if ((u32)cur < (u32)n) {
            *sel = cur + 1;
        }
        break;
    case 1:
        if ((u32)(n + 1) < 10) {
            *sel = 1;
        } else {
            if (cur < 10) {
                *sel = 1;
            } else {
                *sel = cur - 10;
            }
            if (*sel == 0) {
                *sel = 1;
            }
        }
        break;
    case 2:
        if ((u32)(n + 1) < 10) {
            *sel = n;
        } else {
            *sel = cur + 10;
            if ((u32)*sel >= (u32)(n + 1)) {
                *sel = n;
            }
            if (*sel == 0) {
                *sel = 1;
            }
        }
        break;
    }
    if ((u32)cur != (u32)*sel) {
        MenuPlaySe(0);
    }
    return total * (u16)*sel;
}

static inline u32 ItemTotal(s16 id) {
    u32 cnt = fn_801F464C(id);
    if (cnt == 0) {
        return 0;
    }
    return cnt * fn_801F477C(id) / 100;
}
u32 fn_801B9810(Ent_801B9810* list, Ent_801B9810** out, u32 n) {
    u32 i;
    u32 k;
    Ent_801B9810** p = out;
    for (i = 0; i < n; i++) {
        *p++ = NULL;
    }
    i = 0;
    k = 0;
    for (; i < n; list++, i++) {
        if (list->id != -1 && list->count - fn_801B995C(list->id) > 0) {
            if (ItemTotal((u16)list->id) != 0) {
                *out++ = list;
                k++;
            }
        }
    }
    return k;
}

void fn_801A66AC(Task_801A66AC *t) {
    VertexCol v[3] = {
        { 0.0f, 0.0f, 0.0f, 0xFF201008 },
        { 24.0f, 0.0f, 0.0f, 0xFF201008 },
        { 12.0f, 20.0f, 0.0f, 0xFF201008 },
    };
    u32 i;
    u32 n;
    VertexCol *p;
    if (t != 0) {
        n = t->ctx->w44 + 1;
        t->ctx->w44 = n;
        if ((n & 8) == 0) {
            p = v;
            for (i = 0; i < 3; i++, p++) {
                p->x = 18.0f + p->x + 264.0f + t->ui->o.x;
                p->y = 16.0f + p->y + 48.0f + t->ui->o.y;
                p->z = fn_801DBD9C(-0.1f);
            }
            fn_80290ED4(v, 3, 0);
        }
    }
}

void fn_8019B980(Obj_8019B980 *self) {
    extern const char *lbl_802EBCB0[4];
    extern s16 lbl_802EBCC0[8];
    extern s32 lbl_803073F0[11];
    extern f32 TextGetZ(void);
    extern void TextSetZ(f32 z);
    extern void TextPushColor(void);
    extern void TextSetColor(u32 c);
    extern void TextPrint(s16 x, s16 y, const char *s);
    extern void TextPrintf(s16 x, s16 y, const char *fmt, ...);
    extern void TextPopColor(s32 n);
    s16 x = (s16)self->x;
    s16 y = (s16)self->y;
    f32 z = TextGetZ();
    TextSetZ(10.0f + self->z);
    TextPushColor();
    TextSetColor(0xff201008);
    TextPrint(x + lbl_802EBCC0[0], y + lbl_802EBCC0[1], lbl_802EBCB0[0]);
    TextPrintf(x + lbl_802EBCC0[0] + 0xa8, y + lbl_802EBCC0[1], "%6d", lbl_803073F0[0]);
    TextPrint(x + lbl_802EBCC0[2], y + lbl_802EBCC0[3], lbl_802EBCB0[1]);
    TextPrintf(x + lbl_802EBCC0[2] + 0x90, y + lbl_802EBCC0[3], "%8d", lbl_803073F0[1]);
    TextPrint(x + lbl_802EBCC0[6], y + lbl_802EBCC0[7], lbl_802EBCB0[3]);
    TextPrintf(x + lbl_802EBCC0[6] + 0xa8, y + lbl_802EBCC0[7], "%8d", lbl_803073F0[2]);
    TextPopColor(1);
    TextSetZ(z);
}

void fn_8019D168(Obj_8019D168 *self) {
    extern u8 lbl_802DFEF0[0x2c];
    extern f32 njSin(s32 a);
    extern void fn_80090664(Dat_8019D168 *d);
    Dat_8019D168 *d = self->dat;
    DrawState st;
    if (self->par->flags & 0x40) {
        self->flags |= 0x40;
        return;
    }
    switch (self->state) {
    case 0:
        d->w44 = d->w48;
        self->state = self->state + 1;
    case 1:
        d->f20 = d->f28 = d->f38 * d->f3c;
        if (d->w50 == 0) {
            d->f20 = -d->f20;
        }
        d->f24 = d->f38 * njSin((d->w48 << 14) / d->w44);
        d->f8 = d->f8 + d->f2c;
        d->f10 = d->f10 + d->f34;
        d->w18 = d->w18 + d->w40;
        njMemCopy(&st, lbl_802DFEF0, 10);
        st.colour.a = -(f32)(d->w44 - d->w48) / (f32)d->w44;
        st.attr_or |= 0x100;
        DrawStatePush(&st);
        fn_80090664(d);
        DrawStatePop(0);
        d->sig->ready = 1;
        d->w48 = d->w48 - 1;
        if (d->w48 <= 0) {
            self->state = 0xff;
        }
        break;
    case 0xff:
        self->flags |= 0x40;
        break;
    }
}

void fn_801A1DB4(Self_801A1DB4 *o) {
    s32 i;
    u32 best = 0;
    Key_801A1DB4 cur;
    Key_801A1DB4 tmp;
    o->ctx->x6 = 0;
    o->ctx->x5 = 0;
    o->ctx->x7 = 0;
    cur.a = 0;
    cur.c = 0;
    cur.b[5] = 0;
    cur.b[4] = 0;
    cur.b[3] = 0;
    cur.b[2] = 0;
    cur.b[1] = 0;
    cur.b[0] = 0;
    for (i = 0; i < 7; i++) {
        Item_801A1DB4 *it = &((Item_801A1DB4 *)((u8 *)o->ctx + 0x14))[i];
        if (it->kind == 1) {
            tmp.a = it->h32;
            tmp.b[0] = it->b34[0];
            tmp.b[1] = it->b34[1];
            tmp.b[2] = it->b34[2];
            tmp.b[3] = it->b34[3];
            tmp.b[4] = it->b34[4];
            tmp.b[5] = it->b34[5];
            tmp.c = 0;
            if (fn_8000743C(&tmp, &cur) >= 0) {
                best = i;
                cur = tmp;
            }
        }
    }
    switch (best) {
    case 0:
    default: o->ctx->x6 = 0; o->ctx->x5 = 0; break;
    case 1: o->ctx->x6 = 1; o->ctx->x5 = 0; break;
    case 2: o->ctx->x6 = 2; o->ctx->x5 = 0; break;
    case 3: o->ctx->x6 = 3; o->ctx->x5 = 0; break;
    case 4: o->ctx->x6 = 4; o->ctx->x5 = 0; break;
    case 5: o->ctx->x6 = 4; o->ctx->x5 = 1; break;
    case 6: o->ctx->x6 = 4; o->ctx->x5 = 2; break;
    }
    o->ctx->x7 = o->ctx->x6 + o->ctx->x5;
}

void fn_801AB328(Self_801AB328 *o) {
    o->ctx->x1f8->flag->b0 = 0;
    o->ctx->x204->flag->b0 = 0;
    o->ctx->x1fc->flag->b0 = 0;
    o->ctx->x218->flag->b0 = 0;
    o->ctx->x214->flag->b0 = 0;
    o->ctx->x1f8->flag->b0 = 0;
    UiObjMoveToX(&o->ctx->x1f8->obj->o, 6, 4, -8.0f);
    UiObjSetCommand(&o->ctx->x1f8->obj->o, 0xf, 0);
    o->ctx->x204->flag->b0 = 0;
    UiObjMoveToX(&o->ctx->x204->obj->o, 6, 4, -8.0f);
    UiObjSetCommand(&o->ctx->x204->obj->o, 0xf, 1);
    o->ctx->x1fc->flag->b0 = 0;
    UiObjMoveToX(&o->ctx->x1fc->obj->o, 6, 4, -8.0f);
    UiObjSetCommand(&o->ctx->x1fc->obj->o, 0xf, 2);
    o->ctx->x218->flag->b0 = 0;
    UiObjMoveToX(&o->ctx->x218->obj->o, 6, -1, 240.0f);
    UiObjSetCommand(&o->ctx->x218->obj->o, 0xf, 0);
    o->ctx->x214->flag->b0 = 0;
    UiObjMoveTo(&o->ctx->x214->obj->o, 6, -1, 24.0f, 384.0f);
    UiObjSetCommand(&o->ctx->x214->obj->o, 0xf, 1);
    o->ctx->x21c->flag->b0 = 0;
    UiObjMoveToX(&o->ctx->x21c->obj->o, 6, -1, -8.0f);
    UiObjSetCommand(&o->ctx->x21c->obj->o, 0xf, 1);
    o->ctx->x21c->flag->w8 = 0xffff;
    o->ctx->x218->flag30->b1e = 0;
}

void fn_801A0FD8(Self_801A0FD8 *o) {
    s32 r;
    s32 k;
    o->ctx->slot[o->ctx->idx] = fn_801A28AC(o->ctx->idx);
    if (o->ctx->slot[o->ctx->idx] != 0) {
        o->ctx->x9 = 0;
        if (1.0f != o->ctx->x18) fn_801A4DCC(o, 1);
        UiObjMoveToXIfChanged(&o->ctx->objs[1]->obj->o, 6, 4, -330.0f);
        UiObjSetCommand(&o->ctx->objs[1]->obj->o, 0xf, 0);
        k = fn_801A6A58(o->ctx->idx, o->ctx->slot[o->ctx->idx]);
        fn_801A64B4(o, (u8)k);
        MenuPlaySe(3);
        o->state = 0xb;
        r = 0;
    } else {
        r = 1;
    }
    if (r != 0 && fn_801A6554(o) == 0 && o->ctx->idx < 2) {
        if (o->ctx->idx == 1) {
            UiObjMoveToY(&o->ctx->objs[4]->obj->o, 3, 4, 100.0f);
            UiObjSetCommand(&o->ctx->objs[4]->obj->o, 0xf, 0);
        }
        o->ctx->objs[1]->x19 = 1;
        ((u16 *)o->ctx->objs[1]->obj)[0x54 / 2] = 1;
        o->ctx->x1c = 0.0f;
        UiObjMoveToX(&o->ctx->objs[1]->obj->o, 6, 4, 160.0f);
        UiObjSetCommand(&o->ctx->objs[1]->obj->o, 0xf, 0);
        fn_801A4DCC(o, 0);
        o->state = 6;
    }
}

void fn_801A5274(Task_801A5274 *t) {
    f32 x;
    f32 y;
    f32 z;
    switch (t->state) {
    case 0:
    case 0xFE:
        if (t->flag[0] == 1) {
            return;
        }
        UiObjUpdate(&t->pan->o);
        UiLayoutDraw(&menu_sprites.texlist8, lbl_802B4A00, 2, &t->pan->o.x, t->pan->o.z, t->pan->o.alpha, 1.0f);
        z = TextGetZ();
        y = 12.0f + t->pan->o.y;
        x = 18.0f + t->pan->o.x;
        if (t->pan->text != 0) {
            TextPushColor();
            TextSetColor(0xFF201008);
            TextSetZ(-27.5f + t->pan->o.z);
            TextPrint((s32)x, (s32)y, t->pan->text);
            TextPopColor(1);
        }
        TextSetZ(z);
        break;
    case 0xFF:
        t->flags |= 0x40;
        break;
    }
}

void fn_801A5D08(Task_801A5D08 *t) {
    f32 x;
    f32 y;
    f32 z;
    switch (t->state) {
    case 0:
    case 0xFE:
        if (t->flag[0] == 1) {
            return;
        }
        UiObjUpdate(&t->pan->o);
        UiObjCalcRect(&t->pan->o);
        UiLayoutDraw(&menu_sprites.texlist8, lbl_802B4B88, 1, &t->pan->o.rect[2], t->pan->o.z, 1.0f, 1.0f);
        UiLayoutDraw(&menu_sprites.texlist8, lbl_802B4B4C, 3, &t->pan->o.rect[0], t->pan->o.z, t->pan->o.alpha * t->parent->ctx->f18, 1.0f);
        z = TextGetZ();
        y = 19.0f + t->pan->o.rect[1];
        x = 74.0f + t->pan->o.rect[0];
        if (t->pan->text != 0) {
            TextPushColor();
            TextSetColor(0xFF201008);
            TextSetZ(-27.5f + t->pan->o.z);
            TextPrint((s32)x, (s32)y, t->pan->text);
            TextPopColor(1);
        }
        TextSetZ(z);
        break;
    case 0xFF:
        t->flags |= 0x40;
        break;
    }
}

void fn_801A6344(Task_801A6344 *t) {
    f32 x;
    f32 y;
    f32 z;
    switch (t->state) {
    case 0:
    case 0xFE:
        if (t->flag[0] == 1) {
            return;
        }
        UiObjUpdate(&t->pan->o);
        UiLayoutDraw(&menu_sprites.texlist8, lbl_802B4A28, 3, &t->pan->o.x, t->pan->o.z, t->pan->o.alpha * t->parent->ctx->f18, 1.0f);
        z = TextGetZ();
        y = 18.0f + t->pan->o.y;
        x = 105.0f + t->pan->o.x;
        if (t->pan->text != 0) {
            TextPushColor();
            TextSetColor(0xFF201008);
            TextSetZ(-27.5f + t->pan->o.z);
            TextPrint((s32)x, (s32)y, t->pan->text);
            TextPopColor(1);
        }
        TextSetZ(z);
        break;
    case 0xFF:
        t->flags |= 0x40;
        break;
    }
}

void* fn_801AC2E4(void* a) {
    T* t = fn_802267AC((void *)(a), (void *)(fn_801AC16C));
    t->w = fn_801E1A74(1, 0x58);
    t->obj = fn_801E1A74(1, 0x6c);
    switch (fn_801BE608(lbl_803471B8->w->item)) {
    case 0:
        t->obj->text = lbl_802ED258[lbl_803471B8->w->item].a;
        break;
    case 1:
        t->obj->text = lbl_802ED258[lbl_803471B8->w->item].c;
        break;
    case 2:
        t->obj->text = lbl_802ED258[lbl_803471B8->w->item].b;
        break;
    default:
        t->obj->text = NULL;
        break;
    }
    t->obj->o.alpha_en = 0;
    t->w[0] = 0;
    t->obj->o.x = -348.0f;
    t->obj->o.tx = -348.0f;
    t->obj->o.y = 36.0f;
    t->obj->o.ty = 36.0f;
    t->obj->o.rdx = 0.0f;
    t->obj->o.rdy = 0.0f;
    *(f32*)((u8*)t->obj + 0x38) = 1.0f;
    t->obj->o.alpha = 1.0f;
    t->obj->o.z = -4300.0f;
    t->x2c = 0;
    UiObjSetLowered(&t->obj->o);
    UiObjCalcRect(&t->obj->o);
    return t;
}

void fn_801B0F1C(Task_801B0F1C *t) {
    f32 z;
    switch (t->state) {
    case 0:
    case 0xFE:
        if (t->flag[0] == 1) {
            return;
        }
        UiObjUpdate(&t->pan->o);
        z = TextGetZ();
        TextPushColor();
        TextSetColor(0xFF201008);
        UiLayoutDraw(&menu_sprites.texlist8, lbl_802B7720, 4, &t->pan->o.x, t->pan->o.z, 1.0f, 1.0f);
        fn_801B6BB4(t->pan, &t->pan->o.x, lbl_803471B8->w->item, -1, 0x18, 0x14, 1.0f);
        TextSetZ(-27.5f + t->pan->o.z);
        TextPrint(55.0f + t->pan->o.x, 20.0f + t->pan->o.y, t->pan->text);
        TextPrint(264.0f + t->pan->o.x, 20.0f + t->pan->o.y, "\x81\x7e");
        TextPrintNumber(288.0f + t->pan->o.x, 20.0f + t->pan->o.y, lbl_803471B8->w->x9, 0xC002);
        TextPopColor(1);
        TextSetZ(z);
        break;
    case 0xFF:
        MenuDummy();
        t->flags |= 0x40;
        break;
    }
}

void fn_801B2430(Task_801B2430 *t) {
    f32 z;
    NJS_POINT3 pos;
    if (lbl_803475D8 != 0) {
        t->state = 0xff;
    }
    switch (t->state) {
    case 0:
    case 0xFE:
        if (t->flag[0] == 1) {
            return;
        }
        UiObjUpdate(&t->pan->o);
        UiLayoutDraw(&menu_sprites.texlist8, lbl_802B6DF8, 4, &t->pan->o.x, t->pan->o.z, 1.0f, 1.0f);
        z = TextGetZ();
        TextPushColor();
        TextSetColor(0xFF201008);
        TextSetZ(-27.5f + t->pan->o.z);
        TextPrint(20.0f + t->pan->o.x, 5.0f + t->pan->o.y, t->pan->text);
        TextPrint(20.0f + t->pan->o.x, 32.0f + t->pan->o.y, lbl_802EC04C[5]);
        TextPopColor(1);
        pos.x = 84.0f + (97.0f + (t->pan->o.x + t->pan->o.rdx));
        pos.y = 7.0f + (t->pan->o.y - t->pan->o.rdy);
        pos.z = -32.0f + t->pan->o.z;
        UiDrawNumber(&pos, 0, 8, lbl_803471B8->w->cost, t->pan->o.alpha);
        pos.y = 34.0f + (t->pan->o.y - t->pan->o.rdy);
        pos.z = -31.5f + t->pan->o.z;
        UiDrawNumber(&pos, 0, 8, lbl_803471B8->w->left, t->pan->o.alpha);
        TextSetZ(z);
        break;
    case 0xFF:
        MenuDummy(t);
        t->flags |= 0x40;
        break;
    }
}

void fn_801A0C3C(Self_801A0C3C *o) {
    extern void fn_801A1DB4(void);
    s32 k;
    if (o->ctx->x250 == 0) return;
    if (o->ctx->slot[o->ctx->idx] != 0) {
        MenuPlaySe(3);
        UiObjMoveToXIfChanged(&o->ctx->objs[1]->obj->o, 6, 4, -330.0f);
        UiObjSetCommand(&o->ctx->objs[1]->obj->o, 0xf, 0);
        fn_801A4DCC(o, 1);
        k = fn_801A6A58(o->ctx->idx, o->ctx->slot[o->ctx->idx]);
        fn_801A64B4(o, k);
        o->state = 0x17;
    } else if (o->ctx->x1 == 1) {
        fn_801A1DB4();
        fn_801A1B98(o, 0);
        fn_801A4DCC(o, 1);
        UiObjMoveToXIfChanged(&o->ctx->objs[1]->obj->o, 6, 4, -330.0f);
        UiObjSetCommand(&o->ctx->objs[1]->obj->o, 0xf, 0);
        o->ctx->x9 = 0;
        o->state = 8;
    } else if (o->ctx->x14 != 0) {
        fn_801A64B4(o, 5);
        fn_801A1B98(o, 0);
        o->ctx->x9 = 0;
        fn_801A4DCC(o, 1);
        UiObjMoveToXIfChanged(&o->ctx->objs[1]->obj->o, 6, 4, -330.0f);
        UiObjSetCommand(&o->ctx->objs[1]->obj->o, 0xf, 0);
        o->state = 8;
    } else {
        o->ctx->slot[o->ctx->idx] = 6;
        fn_801A64B4(o, fn_801A6A58(o->ctx->idx, o->ctx->slot[o->ctx->idx]));
        o->ctx->x26c = 3;
        MenuPlaySe(3);
        fn_801A4DCC(o, 1);
        UiObjMoveToXIfChanged(&o->ctx->objs[1]->obj->o, 6, 4, -330.0f);
        UiObjSetCommand(&o->ctx->objs[1]->obj->o, 0xf, 0);
        o->state = 0xb;
    }
}

Task_801B6240* fn_801B6320(void* a, f32 x)
{
    Task_801B6240* o = fn_802267AC(a, fn_801B5FA8);
    o->p24 = fn_801E1A74(1, 0x58);
    o->p28 = fn_801E1A74(1, 0x6c);
    o->w2c = 0;
    o->p24[0] = 0;
    o->p28->o.alpha_en = 0;
    o->p28->o.x = 640.0f;
    o->p28->o.tx = 640.0f;
    o->p28->o.y = 480.0f;
    o->p28->o.ty = 480.0f;
    o->p28->o.rdx = 0.0f;
    o->p28->o.rdy = 0.0f;
    o->p28->o.alpha = 1.0f;
    o->p28->o.z = x;
    UiObjSetLowered(&o->p28->o);
    return o;
}

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
typedef struct Self_8016F594 {
    u8 pad[0x2c];
    f32 x, y;
    u8 pad2[0x74 - 0x34];
    f32 z;
    u8 pad3[0xbc - 0x78];
    u8 *data;
} Self_8016F594;
extern void fn_8019AE84(Self_8016F594 *self);
void fn_8019ADA0(Self_8016F138* self) {
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
            fn_8019AE84((struct Self_8016F594 *)self->inner);
        }
        break;
    case 0x64:
        self->state = 0xff;
        break;
    case 0xff:
        fn_80199F58((Obj_80199F58 *)self->inner);
        self->flags |= 0x40;
        break;
    }
}

void fn_801A2C40(void) {
    lbl_80347178 = 0;
    lbl_80347170[0] = 1;
    lbl_80347170[0] = 1;
}

/* Item count (fn_801F464C) times per-unit value (fn_801F477C), divided by 100. */
u32 fn_801B90E4(s32 idx) {
    s16 id = idx;
    u32 cnt = fn_801F464C(id);

    if (cnt == 0) {
        return 0;
    }
    return cnt * fn_801F477C(id) / 100;
}

void fn_801BEA70(void *a, u32 idx, s32 mode) {
    lbl_803473BE = ((u8)mode <= 23) ? mode : 0;
    if (idx > lbl_8034BAC0[0] - 1) {
        fn_801BEB10(a, 1, 0, 0);
    } else {
        fn_801BEB10(a, 1, idx, 0);
    }
}

void fn_8019EFF8(SaveTask* t) {
    s32 r;
    if (fn_801A3B30(t, &r) == 0) return;
    if (r == 0) {
        MemCopy(&t->w->ent[t->w->f7], (u8*)t->w + 0x1d8, 0x2c);
        t->w->ent[t->w->f7].f0 = 1;
        t->w->f9 = 0;
        fn_801A41C0(t->w->f258);
        t->w->f258 = NULL;
        fn_801A64B4(t, 10);
        MenuPlaySe(0xd);
        UiObjMoveToXIfChanged(&t->w->p[1]->obj->o, 6, 4, -330.0f);
        UiObjSetCommand(&t->w->p[1]->obj->o, 0xf, 0);
        fn_801A4DCC(t, 1);
        UiObjMoveToX(&t->w->p[5]->obj->o, 6, 5, -240.0f);
        UiObjSetCommand(&t->w->p[5]->obj->o, 0x1a, 2);
        UiObjMoveToX(&t->w->p[6]->obj->o, 6, 5, -240.0f);
        UiObjSetCommand(&t->w->p[6]->obj->o, 0x1a, 0);
        lbl_803475D0 = 0;
        lbl_803475E0 = 0;
        t->w->fc = 10;
        t->state = 0x15;
    } else if (r != -1) {
        t->w->ent[t->w->f7].f0 = 2;
        t->w->f9 = 0;
        fn_801A41C0(t->w->f258);
        t->w->f258 = NULL;
        fn_801A64B4(t, 9);
        MenuPlaySe(3);
        UiObjMoveToXIfChanged(&t->w->p[1]->obj->o, 6, 4, -330.0f);
        UiObjSetCommand(&t->w->p[1]->obj->o, 0xf, 0);
        UiObjMoveToX(&t->w->p[5]->obj->o, 6, 5, -240.0f);
        UiObjSetCommand(&t->w->p[5]->obj->o, 0x1a, 2);
        UiObjMoveToX(&t->w->p[6]->obj->o, 6, 5, -240.0f);
        UiObjSetCommand(&t->w->p[6]->obj->o, 0x1a, 0);
        fn_801A4DCC(t, 1);
        lbl_803475D0 = 0;
        lbl_803475E0 = 0;
        t->state = 0x17;
    }
}

void fn_801A11B0(SaveTask* t) {
    u32 bits;
    u8 v;
    s32 arg;
    if (t->w->f18 != 1.0f) fn_801A4DCC((void *)(t), 1);
    if (fn_801A6554((void *)(t)) != 0) return;
    if (((Tab*)lbl_803081CC)[0].f14 == 0 && ((Tab*)lbl_803081CC)[1].f14 == 0) {
        t->w->st[0] = fn_801A28AC(0);
        t->w->st[1] = fn_801A28AC(1);
        t->w->f3 = t->w->cnt;
        t->w->cnt = 0;
        if (t->w->st[0] != 1) t->w->cnt++;
        if (t->w->st[1] != 1) t->w->cnt++;
    }
    if (fn_801C09F8(0, 4) != 0 || fn_801C09F8(0, 5) != 0) {
        if (t->w->cnt == 2) {
            MenuPlaySe(4);
            t->w->sel++;
            t->w->sel &= 1;
        }
    } else {
        bits = lbl_80311A60[0]->held;
        if (bits & 0x100) {
            if (t->w->cnt == 0) {
                MenuPlaySe(3);
            } else if (t->w->sel != 2) {
                MenuPlaySe(2);
                if (t->w->sel == 0) {
                    UiObjSetCommand(&t->w->p[3]->obj->o, 0x14, 0);
                    UiObjMoveToX(&t->w->p[4]->obj->o, 6, 5, -340.0f);
                    UiObjSetCommand(&t->w->p[4]->obj->o, 0xf, 0);
                } else {
                    UiObjMoveToX(&t->w->p[3]->obj->o, 6, 5, -340.0f);
                    UiObjSetCommand(&t->w->p[3]->obj->o, 0xf, 0);
                    UiObjSetCommand(&t->w->p[4]->obj->o, 0x14, 0);
                }
                fn_801A64B4((void *)(t), 0x11);
                t->state = 5;
            } else {
                goto cancel;
            }
        } else if (bits & 0x200) {
        cancel:
            UiObjSetCommand(&t->w->p[3]->obj->o, 0x14, 0);
            UiObjSetCommand(&t->w->p[4]->obj->o, 0x14, 0);
            t->state = 0x1c;
        } else if (bits & 0x400) {
            t->state = 0x1e;
        } else {
            fn_801A20AC(t);
            if (t->w->cnt != 0) {
                v = 0xb;
                if (t->w->f1 == 0) v = 1;
                arg = v;
            } else {
                arg = 4;
            }
            fn_801A64B4((void *)(t), arg);
        }
    }
}

void fn_801B737C(ShopPart* t)
{
    char buf[32];
    s32 i;
    s32 ok;
    for (i = 0; i < 8; i++) {
        ok = 0;
        switch (i) {
        case 0:
            strcpy((void *)(buf), (void *)(((char**)lbl_802EBF7C)[i]));
            ok = 1;
            break;
        case 1:
            if ((*(Fl*)&lbl_80310B3C).f4 & 0x10000000) {
                strcpy((void *)(buf), (void *)(((char**)lbl_802EBF7C)[i]));
                ok = 1;
            }
            break;
        case 2:
            if ((*(Fl*)&lbl_80310B3C).f18 & 0x100) {
                strcpy((void *)(buf), (void *)(((char**)lbl_802EBF7C)[i]));
                ok = 1;
            }
            break;
        case 3:
            if ((*(Fl*)&lbl_80310B3C).f1c & 0x04000000) {
                strcpy((void *)(buf), (void *)(((char**)lbl_802EBF7C)[i]));
                ok = 1;
            }
            break;
        case 4:
            if ((*(Fl*)&lbl_80310B3C).f168 & 0x40000000) {
                strcpy((void *)(buf), (void *)(((char**)lbl_802EBF7C)[i]));
                ok = 1;
            }
            break;
        case 5:
            if (((*(Fl*)&lbl_80310B3C).f30 & 0x10000) || (*(St_801B737C*)&lbl_80310A1C).seen[5] > 0) {
                ok = 1;
                if ((*(St_801B737C*)&lbl_80310A1C).seen[5] > 1) {
                    strcpy((void *)(buf), lbl_802B8F70);
                } else {
                    strcpy((void *)(buf), (void *)(((char**)lbl_802EBF7C)[i]));
                }
            }
            break;
        case 6:
            if ((*(Fl*)&lbl_80310B3C).f170 & 0x80) {
                strcpy((void *)(buf), (void *)(((char**)lbl_802EBF7C)[i]));
                ok = 1;
            }
            break;
        case 7:
            if ((*(Fl*)&lbl_80310B3C).f30 & 0x1000000) {
                strcpy((void *)(buf), (void *)(((char**)lbl_802EBF7C)[i]));
                ok = 1;
            }
            break;
        }
        if (ok == 0) {
            TextSetColor(0x40201008);
            TextPrint((s32)(16.0f + t->obj->o.x), (s32)(12.0f + t->obj->o.y + (f32)(i * 24)), lbl_802B8F94);
            TextSetColor(0xFF201008);
        } else {
            TextPrint((s32)(16.0f + t->obj->o.x), (s32)(12.0f + t->obj->o.y + (f32)(i * 24)), (void *)(buf));
        }
        if ((*(St_801B737C*)&lbl_80310A1C).seen[i] == 0 && ok == 1) {
            (*(St_801B737C*)&lbl_80310A1C).seen[i] = 1;
        }
    }
}

s32 fn_801AB094(Task_801AB094* t)
{
    s32 ret = 0;
    u8 old = t->m->cur;
    s32 i, cmd;
    Slot* s;
    UiObj* o;
    if (fn_801C09F8(0, 4)) {
        ret = 1;
        if (t->m->cur == 0) t->m->cur = 4; else t->m->cur--;
        if (t->m->slot[t->m->cur] == 0) {
            for (i = 0; i < 5; i++) {
                if (t->m->slot[t->m->cur] != 0) break;
                if (t->m->cur == 0) t->m->cur = 5; else t->m->cur--;
            }
        }
    } else if (fn_801C09F8(0, 5)) {
        ret = 1;
        t->m->cur++;
        if (t->m->cur == 5) t->m->cur = 0;
        if (t->m->slot[t->m->cur] == 0) {
            for (i = 0; i < 5; i++) {
                if (t->m->slot[t->m->cur] != 0) break;
                t->m->cur++;
                if (t->m->cur == 5) t->m->cur = 0;
            }
        }
    }
    if (old != t->m->cur) MenuPlaySe(0);
    cmd = 0x14;
    if (t->m->cur == 0) cmd = 0x15;
    UiObjSetCommand(&t->m->slot[0]->obj->o, cmd, 0);
    if ((s = t->m->slot[1]) != 0) {
        o = &s->obj->o;
        cmd = 0x14;
        if (t->m->cur == 1) cmd = 0x15;
        UiObjSetCommand(o, cmd, 0);
    }
    if ((s = t->m->slot[2]) != 0) {
        o = &s->obj->o;
        cmd = 0x14;
        if (t->m->cur == 2) cmd = 0x15;
        UiObjSetCommand(o, cmd, 0);
    }
    if ((s = t->m->slot[3]) != 0) {
        o = &s->obj->o;
        cmd = 0x14;
        if (t->m->cur == 3) cmd = 0x15;
        UiObjSetCommand(o, cmd, 0);
    }
    cmd = 0x14;
    if (t->m->cur == 4) cmd = 0x15;
    UiObjSetCommand(&t->m->slot[4]->obj->o, cmd, 0);
    return ret;
}

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
extern void fn_801C1728(s16 id, s32 slot);
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

void fn_801A6BDC(ShopTask* t) {
    extern void TextPrintNumber(s32 x, s32 y, s32 value, u32 flags);
    f32 z;
    f32 y;
    f32 a;
    ShopPart* p;
    ShopEntry* e;
    u16 price;
    s32 page;
    s32 row;
    s32 i;
    u32 n;
    s32 d;
    u8 d8;
    s32 cmd;
    s32 old;
    s32 cnt;
    UiObj* o;

    switch (t->w->state) {
    case 0:
        fn_801C12C8();
        fn_801AB580((Self_801AB580*)t);
        t->w->parts[4]->flag->b0 = 1;
        t->w->parts[5]->flag->b0 = 1;
        t->w->parts[7] = (ShopPart*)fn_801B6320(t, -4450.0f);
        t->w->parts[8] = (ShopPart*)fn_801B5C4C(t);
        t->w->parts[9] = (ShopPart*)fn_801B54D4(t);
        t->w->parts[2] = (ShopPart*)fn_801B2678(t, 0);
        t->w->parts[2]->flag->b0 = 1;
        t->w->parts[8]->list->page = 0;
        t->w->parts[8]->list->row = 0;
        t->w->qty = 1;
        t->w->state = 1;
        SHOP_LIST_SET_Y(t->w->parts[8]);
    case 1:
        UiObjMoveTo(&t->w->parts[7]->obj->o, 6, -1, 24.0f, 384.0f);
        UiObjSetCommand(&t->w->parts[7]->obj->o, 15, 0);
        SHOP_CUR_ENTRY(e, t, t->w->parts[8]);
        fn_801B6400(fn_801F48AC(e->id));
        UiObjMoveToX(&t->w->parts[8]->obj->o, 6, -1, 240.0f);
        UiObjSetCommand(&t->w->parts[8]->obj->o, 15, 0);
        SHOP_CUR_ENTRY(e, t, t->w->parts[8]);
        fn_801B5644(t->w->parts[9], e->id);
        t->w->state = 2;
        break;
    case 2:
        if (UiObjIsBusy(&t->w->parts[7]->obj->o) == 0 || PAD_A) {
            MenuPartsFinish((MenuTask*)t);
            t->w->parts[8]->x38->state = 1 < t->buf->pages;
            t->w->state = 3;
        }
        break;
    case 3:
        p = t->w->parts[8];
        page = p->list->page;
        row = p->list->row;
        if (fn_801C09F8(0, 1)) {
            t->w->state = 0x18;
            t->w->parts[8]->x38->state = 0;
            MenuPlaySe(5);
        } else {
            if (fn_801C09F8(0, 4)) {
                if (p->list->row == 0) {
                    p->list->row = 5;
                    for (i = 0; i < 6 - p->list->row; i++) {
                        if (t->buf->out[(u8)p->list->page * 6 + (u8)p->list->row].id != -1) {
                            break;
                        }
                        p->list->row--;
                    }
                } else {
                    p->list->row--;
                }
            } else if (fn_801C09F8(0, 5)) {
                p->list->row++;
                if (p->list->row == 6) {
                    p->list->row = 0;
                }
                SHOP_CUR_ENTRY(e, t, p);
                if (e->id == -1) {
                    p->list->row = 0;
                }
            } else {
                if (fn_801C09F8(0, 6)) {
                    if (p->list->page == 0) {
                        p->list->page = t->buf->pages;
                    }
                    p->list->page--;
                    if (page != p->list->page) {
                        t->w->parts[8]->x38->angle = 0;
                    }
                } else if (fn_801C09F8(0, 7)) {
                    p->list->page++;
                    if (p->list->page == t->buf->pages) {
                        p->list->page = 0;
                    }
                    if (page != p->list->page) {
                        t->w->parts[8]->x38->angle = 0;
                    }
                } else {
                    goto no_move;
                }
                SHOP_CUR_ENTRY(e, t, p);
                if (e->id == -1) {
                    for (i = 0; i < 6 - p->list->row; i++) {
                        if (t->buf->out[(u8)p->list->page * 6 + (u8)p->list->row].id != -1) {
                            break;
                        }
                        p->list->row--;
                    }
                }
            }
            if (page != p->list->page || row != p->list->row) {
                MenuPlaySe(4);
            }
            p = t->w->parts[8];
            SHOP_CUR_ENTRY(e, t, p);
            fn_801B571C(t->w->parts[9], e->id);
            p->list->angle = 0;
            goto tail3;
        no_move: /* no direction pressed */
            if (PAD_A) {
            SHOP_CUR_ENTRY(e, t, t->w->parts[8]);
            if (e->flag == 0) {
                t->w->item = e->id;
                fn_801C0FBC(t->w->item);
                t->w->qty = 1;
                price = fn_801F477C(t->w->item);
                t->w->cost = price * t->w->qty;
                t->w->left = (s32)(lbl_8030B7F4.w34c - t->w->cost) <= 0 ? 0 : lbl_8030B7F4.w34c - t->w->cost;
                UiObjMoveToX(&t->w->parts[9]->obj->o, 6, -1, -624.0f);
                UiObjSetCommand(&t->w->parts[9]->obj->o, 15, 0);
                t->w->parts[2]->flag->b0 = 0;
                UiObjMoveToX(&t->w->parts[2]->obj->o, 6, -1, -8.0f);
                UiObjSetCommand(&t->w->parts[2]->obj->o, 15, 1);
                t->w->parts[8]->x38->state = 0;
                fn_801C08B4(2);
                t->w->state = 4;
            } else {
                fn_801C08B4(3);
            }
            }
        }
    tail3:
        SHOP_LIST_SET_Y(t->w->parts[8]);
        SHOP_CUR_ENTRY(e, t, t->w->parts[8]);
        fn_801B6400(fn_801F48AC(e->id));
        break;
    case 4:
        if (UiObjIsBusy(&t->w->parts[2]->obj->o) == 0 && UiObjIsBusy(&t->w->parts[9]->obj->o) == 0) {
            t->w->state = 5;
            t->w->parts[9]->flag->b0 = 1;
            t->w->parts[8]->list->part = 1;
        } else if (PAD_A) {
            MenuPartsFinish((MenuTask*)t);
        }
        break;
    case 5:
        if (fn_801C09F8(0, 1)) {
            t->w->state = 9;
            MenuPlaySe(5);
        back_to_list:
            ShopBackToList(t);
            break;
        }
        if (fn_801C09F8(0, 4)) {
            t->w->qty = fn_801AB82C(8, t->w->qty, t->w->item);
        } else if (fn_801C09F8(0, 5)) {
            t->w->qty = fn_801AB82C(4, t->w->qty, t->w->item);
        } else if (fn_801C09F8(0, 6)) {
            t->w->qty = fn_801AB82C(1, t->w->qty, t->w->item);
        } else if (fn_801C09F8(0, 7)) {
            t->w->qty = fn_801AB82C(2, t->w->qty, t->w->item);
        } else if (PAD_A) {
            t->w->state = 6;
            t->w->parts[8]->list->part = 0xFF;
            MenuPlaySe(2);
            fn_801C08B4(0x19);
        }
        y = t->w->parts[8]->list->row * 24 + 12;
        z = TextGetZ();
        TextPushColor();
        TextSetColor(0xFF2222F0);
        TextSetZ(-27.5f + t->w->parts[8]->obj->o.z);
        TextPrint((s32)(336.0f + (t->w->parts[8]->obj->o.x + t->w->parts[8]->obj->o.rdx)),
                  (s32)(y + (t->w->parts[8]->obj->o.y - t->w->parts[8]->obj->o.rdy)), "\x81\x7e");
        TextPrintNumber((s32)(360.0f + (t->w->parts[8]->obj->o.x + t->w->parts[8]->obj->o.rdx)),
                        (s32)(y + (t->w->parts[8]->obj->o.y - t->w->parts[8]->obj->o.rdy)), t->w->qty, 0xC002);
        TextPopColor(1);
        TextSetZ(z);
        price = fn_801F477C(t->w->item);
        t->w->cost = price * t->w->qty;
        t->w->left = (s32)(lbl_8030B7F4.w34c - t->w->cost) <= 0 ? 0 : lbl_8030B7F4.w34c - t->w->cost;
        fn_801C0814(t);
        break;
    case 6:
        if (PAD_A) {
            lbl_8030B7F4.w34c -= t->w->cost;
            t->w->cost = 0;
        } else if (t->w->cost <= t->w->step) {
            lbl_8030B7F4.w34c -= t->w->cost;
            t->w->cost = 0;
        } else {
            t->w->cost -= t->w->step;
            lbl_8030B7F4.w34c -= t->w->step;
        }
        if (t->w->cost == 0) {
            fn_801C1148(t->w->item, t->w->qty);
            fn_801AB580((Self_801AB580*)t);
            t->w->state = 7;
            fn_801C08B4(0x18);
            t->w->step = 0;
        }
        break;
    case 7:
        t->w->who[3] = -1;
        t->w->who[2] = -1;
        t->w->who[1] = -1;
        t->w->who[0] = -1;
        t->w->xb = 0;
        t->w->parts[17] = 0;
        t->w->parts[16] = 0;
        t->w->parts[15] = 0;
        t->w->parts[14] = 0;
        fn_801C0FBC(t->w->item);
        for (i = 0; i < 4; i++) {
            t->w->stat[i][3] = 0;
            t->w->stat[i][2] = 0;
            t->w->stat[i][1] = 0;
            t->w->stat[i][0] = 0;
        }
        switch (fn_801F4C24(t->w->item)) {
        case 0:
            if (fn_801C0CA0(t->w->item)) {
                t->w->who[0] = fn_801C0C14(t->w->item);
                t->w->b34 = fn_801C2C84(t->w->who[0]);
                t->w->xb = 1;
                ShopShowEquip(t);
            } else {
                t->w->state = 10;
            }
            break;
        case 1:
        case 2:
            t->w->xa = 0;
            for (i = 0; i < 4; i++) {
                if (fn_801F3FD0(lbl_803471B8->w->m[i].id, t->w->item)) {
                    t->w->who[t->w->xb] = i;
                    t->w->stat[i][0] = lbl_803471B8->w->m[i].ha;
                    t->w->stat[i][1] = lbl_803471B8->w->m[i].hc;
                    t->w->stat[i][2] = lbl_803471B8->w->m[i].he;
                    t->w->xb++;
                    if (fn_801C0B88(t->w->item, i)) {
                        t->w->xa++;
                    }
                }
            }
            if (t->w->xa == t->w->xb) {
                t->w->xa = 4;
            }
            if (t->w->xb == 0) {
                t->w->state = 10;
            } else {
                ShopShowEquip(t);
            }
            break;
        case 5:
        case 6:
            switch ((s8)lbl_80310A1C[6]) {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 12:
                t->w->state = 10;
                break;
            default:
                if (fn_801F3FD0(0, t->w->item) == 2 && lbl_8030B7F4.x1568.b1568 != -1) {
                    ShopShowEquip(t);
                } else {
                    t->w->state = 10;
                }
                break;
            }
            break;
        case 3:
        case 4:
        case 7:
            t->w->state = 10;
            break;
        }
        break;
    case 8:
        if (UiObjIsBusy(&t->w->parts[2]->obj->o)) {
            if (!PAD_A) {
                break;
            }
            MenuPartsFinish((MenuTask*)t);
        }
        switch (fn_801F4C24(t->w->item)) {
        case 0:
            ShopHideList(t);
            t->w->xa = 0;
            t->w->parts[12] = (ShopPart*)fn_801B1104(t);
            t->w->parts[18] = (ShopPart*)fn_801B0470(t);
            t->w->parts[10] = fn_801AD00C(t, 0, t->w->who[0]);
            t->w->parts[11] = fn_801AD00C(t, 1, t->w->who[0]);
            t->w->parts[13] = fn_801B057C(t, 0, t->w->who[0]);
            UiObjMoveToX(&t->w->parts[13]->obj->o, 6, 4, -8.0f);
            UiObjSetCommand(&t->w->parts[13]->obj->o, 15, 2);
            t->w->stat[0][0] = lbl_803471B8->w->m[t->w->who[0]].ha;
            fn_801C1FC0(t->w->item, t->w->who[0]);
            t->w->parts[14] = fn_801B0DF8(t);
            t->w->parts[14]->list->page = fn_801AB6E8(0, fn_801C2C84(t->w->who[0]));
            t->w->xc[t->w->who[0]] = 0;
            UiObjMoveToX(&t->w->parts[14]->obj->o, 6, 4, -8.0f);
            UiObjSetCommand(&t->w->parts[14]->obj->o, 15, 4);
            UiObjMoveToX(&t->w->parts[12]->obj->o, 6, 5, -8.0f);
            UiObjSetCommand(&t->w->parts[12]->obj->o, 15, 0);
            UiObjMoveToX(&t->w->parts[18]->obj->o, 6, 5, -8.0f);
            UiObjSetCommand(&t->w->parts[18]->obj->o, 15, 6);
            ShopShowCompare(t);
            t->w->state = 11;
            break;
        case 1:
        case 2:
            ShopHideList(t);
            t->w->parts[12] = (ShopPart*)fn_801B1104(t);
            t->w->parts[18] = (ShopPart*)fn_801B0470(t);
            t->w->xc[3] = 0;
            t->w->xc[2] = 0;
            t->w->xc[1] = 0;
            t->w->xc[0] = 0;
            n = 0;
            for (i = 0; i < t->w->xb; i++) {
                if (fn_801C0B88(t->w->item, t->w->who[i])) {
                    a = 0.7f;
                    n++;
                } else {
                    a = 1.0f;
                }
                fn_801C1FC0(t->w->item, t->w->who[i]);
                t->w->parts[lbl_802B69E8[i].idx] = fn_801B06CC(t, i, t->w->who[i], a);
                UiObjMoveToX(&t->w->parts[lbl_802B69E8[i].idx]->obj->o, 6, 4, lbl_802B69E8[i].x);
                UiObjSetCommand(&t->w->parts[lbl_802B69E8[i].idx]->obj->o, 15, i * 2 + 2);
            }
            if (n == t->w->xb) {
                t->w->xa = 4;
                i = 0;
            } else {
                for (i = 0; i < t->w->xb; i++) {
                    if (fn_801C0B88(t->w->item, t->w->who[i]) == 0) {
                        break;
                    }
                }
                t->w->xa = i;
            }
            t->w->parts[10] = fn_801AD00C(t, 0, t->w->who[i]);
            t->w->parts[11] = fn_801AD00C(t, 1, t->w->who[i]);
            d8 = t->w->xb * 2 + 2;
            UiObjMoveToX(&t->w->parts[12]->obj->o, 6, 5, -8.0f);
            UiObjSetCommand(&t->w->parts[12]->obj->o, 15, 0);
            UiObjMoveToX(&t->w->parts[18]->obj->o, 6, 5, -8.0f);
            UiObjSetCommand(&t->w->parts[18]->obj->o, 15, d8);
            ShopShowCompare(t);
            t->w->state = 15;
            break;
        case 5:
            t->w->b37 = 0;
            t->w->xa = 0;
            t->w->xc[3] = 0;
            t->w->xc[2] = 0;
            t->w->xc[1] = 0;
            t->w->xc[0] = 0;
            t->w->parts[10] = fn_801AD00C(t, 2, fn_801C16D0(t->w->item));
            t->w->parts[11] = fn_801AD00C(t, 3, fn_801C16D0(t->w->item));
            t->w->stat[0][0] = lbl_803471B8->w->d8[0].v;
            t->w->stat[0][1] = lbl_803471B8->w->d8[1].v;
            t->w->stat[0][2] = lbl_803471B8->w->d8[2].v;
            t->w->stat[0][3] = lbl_803471B8->w->d8[3].v;
            fn_801C1728(t->w->item, 0);
            fn_801C1728(t->w->item, 1);
            fn_801C1728(t->w->item, 2);
            fn_801C1728(t->w->item, 3);
            for (i = 0; i < 4; i++) {
                t->w->parts[lbl_802B69E8[i].idx] = fn_801AFBE8(t, i, 0, lbl_8030B7F4.x1568.s158a[i] == t->w->item ? 0.7f : 1.0f);
                UiObjMoveToX(&t->w->parts[lbl_802B69E8[i].idx]->obj->o, 6, 4, lbl_802B69E8[i].x);
                UiObjSetCommand(&t->w->parts[lbl_802B69E8[i].idx]->obj->o, 15, i * 2 + 2);
            }
            goto accessory; /* types 5 and 6 share their tail */
        case 6:
            t->w->xa = 0;
            t->w->b37 = 1;
            t->w->xc[3] = 0;
            t->w->xc[2] = 0;
            t->w->xc[1] = 0;
            t->w->xc[0] = 0;
            t->w->parts[10] = fn_801AD00C(t, 4, 0);
            t->w->parts[11] = fn_801AD00C(t, 5, 0);
            t->w->stat[0][0] = lbl_803471B8->w->h10a[0];
            t->w->stat[0][1] = lbl_803471B8->w->h10a[1];
            t->w->stat[0][2] = lbl_803471B8->w->h10a[2];
            fn_801C1728(t->w->item, 0);
            fn_801C1728(t->w->item, 1);
            fn_801C1728(t->w->item, 2);
            for (i = 0; i < 3; i++) {
                t->w->parts[lbl_802B69E8[i].idx] = fn_801AFBE8(t, i, 1, lbl_8030B7F4.x1568.s1580[i] == t->w->item ? 0.7f : 1.0f);
                UiObjMoveToX(&t->w->parts[lbl_802B69E8[i].idx]->obj->o, 6, 4, lbl_802B69E8[i].x);
                UiObjSetCommand(&t->w->parts[lbl_802B69E8[i].idx]->obj->o, 15, i * 2 + 2);
            }
        accessory:
            ShopHideList(t);
            t->w->parts[12] = (ShopPart*)fn_801B1104(t);
            t->w->parts[18] = (ShopPart*)fn_801B0470(t);
            UiObjMoveToX(&t->w->parts[12]->obj->o, 6, 5, -8.0f);
            UiObjSetCommand(&t->w->parts[12]->obj->o, 15, 0);
            UiObjMoveToX(&t->w->parts[18]->obj->o, 6, 5, -8.0f);
            UiObjSetCommand(&t->w->parts[18]->obj->o, 15, (u8)(i * 2 + 2));
            ShopShowCompare(t);
            t->w->state = 19;
            break;
        case 3:
        case 4:
        case 7:
            t->w->xa = 0;
            t->w->state = 10;
            break;
        }
        if (PAD_A) {
            MenuPartsFinish((MenuTask*)t);
        }
        break;
    case 10:
        t->w->state = 9;
        goto back_to_list; /* the original jumps into state 5's code */
    case 9:
        if (fn_801C09F8(0, 1) || PAD_B) {
            MenuPartsFinish((MenuTask*)t);
        list_ready:
            t->w->parts[2]->flag->b0 = 1;
            t->w->state = 3;
            t->w->parts[8]->x38->state = 1 < t->buf->pages;
        } else if (UiObjIsBusy(&t->w->parts[2]->obj->o) == 0 && UiObjIsBusy(&t->w->parts[9]->obj->o) == 0) {
            goto list_ready; /* shared with the cancel path above */
        }
        break;
    case 11:
        if (UiObjIsBusy(&t->w->parts[18]->obj->o) == 0 && UiObjIsBusy(&t->w->parts[11]->obj2->o) == 0) {
            ShopCompareDone(t);
        } else if (PAD_A) {
            MenuPartsFinish((MenuTask*)t);
            ShopCompareDone(t);
        }
        break;
    case 12:
        if (PAD_B) {
            if (t->w->xa == 4) {
                break;
            }
            t->w->parts[14]->x38->state = 1;
            t->w->xc[t->w->who[0]] = 0;
            lbl_803471B8->chr[t->w->who[0]].h6c = -1;
            fn_801C0AB4(t->w->stat[0][0], t->w->who[0]);
            fn_801C2C4C(t->w->who[0], t->w->b34);
            fn_801C12C8();
            fn_801C0FBC(t->w->item);
            fn_801AAFAC(t);
        } else if (PAD_A) {
            switch (t->w->xa) {
            case 0:
            case 1:
            case 2:
            case 3:
                if (t->w->x9 != 0 && t->w->parts[14]->x38->state != 0) {
                    fn_801C0AB4(t->w->item, t->w->who[0]);
                    if (fn_801F4CA0()) {
                        fn_801C2C4C(t->w->who[0], t->w->parts[14]->list->page);
                        lbl_803471B8->chr[t->w->who[0]].h6c = t->w->parts[14]->list->page;
                        t->w->xc[t->w->who[0]] = 1;
                    } else {
                        fn_801C2C4C(t->w->who[0], t->w->b34);
                        lbl_803471B8->chr[t->w->who[0]].h6c = t->w->b34;
                        t->w->xc[t->w->who[0]] = 1;
                    }
                    fn_801C12C8();
                    fn_801C0FBC(t->w->item);
                    if (fn_801AAFAC(t)) {
                        t->w->xa = 4;
                    }
                    fn_801C08B4(0x16);
                    SHOP_SLOT_CMDS(t, cmd, o);
                    t->w->parts[14]->x38->state = 0;
                } else {
                    fn_801C08B4(3);
                }
                break;
            case 4:
                fn_801C08B4(2);
                UiObjMoveToX(&t->w->parts[13]->obj->o, 6, 5, -348.0f);
                UiObjSetCommand(&t->w->parts[13]->obj->o, 15, 4);
                UiObjMoveToX(&t->w->parts[14]->obj->o, 6, 5, -348.0f);
                UiObjSetCommand(&t->w->parts[14]->obj->o, 15, 2);
                UiObjMoveToX(&t->w->parts[12]->obj->o, 6, 5, -348.0f);
                UiObjSetCommand(&t->w->parts[12]->obj->o, 15, 6);
                UiObjMoveToX(&t->w->parts[18]->obj->o, 6, 5, -348.0f);
                UiObjSetCommand(&t->w->parts[18]->obj->o, 15, 0);
                UiObjMoveToX(&t->w->parts[10]->obj->o, 6, -1, 648.0f);
                UiObjSetCommand(&t->w->parts[10]->obj->o, 15, 6);
                UiObjMoveToX(&t->w->parts[10]->obj2->o, 6, -1, 648.0f);
                UiObjSetCommand(&t->w->parts[10]->obj2->o, 15, 4);
                UiObjMoveToX(&t->w->parts[11]->obj->o, 6, -1, 648.0f);
                UiObjSetCommand(&t->w->parts[11]->obj->o, 15, 2);
                UiObjMoveToX(&t->w->parts[11]->obj2->o, 6, -1, 648.0f);
                UiObjSetCommand(&t->w->parts[11]->obj2->o, 15, 0);
                t->w->state = 14;
                break;
            }
        } else if (fn_801AB094((Task_801AB094*)t) == 0) {
            if (fn_801C09F8(0, 6)) {
                if (t->w->xa == 0 && t->w->parts[14]->x38->state != 0 &&
                    t->w->stat[0][0] == lbl_803471B8->w->m[t->w->who[0]].ha) {
                    page = t->w->parts[14]->list->page;
                    t->w->parts[14]->list->page = fn_801AB6E8(-1, page);
                    if (page != t->w->parts[14]->list->page) {
                        MenuPlaySe(0);
                    }
                }
            } else if (fn_801C09F8(0, 7)) {
                if (t->w->xa == 0 && t->w->parts[14]->x38->state != 0 &&
                    t->w->stat[0][0] == lbl_803471B8->w->m[t->w->who[0]].ha) {
                    page = t->w->parts[14]->list->page;
                    t->w->parts[14]->list->page = fn_801AB6E8(1, page);
                    if (page != t->w->parts[14]->list->page) {
                        MenuPlaySe(0);
                    }
                }
            }
        }
        break;
    case 14:
        if (fn_801C09F8(0, 1) || PAD_A) {
            MenuPartsFinish((MenuTask*)t);
            ShopFreeCompare(t);
            MenuPartsFinish((MenuTask*)t);
            t->w->state = 3;
            t->w->parts[8]->x38->state = 1 < t->buf->pages;
        } else if (UiObjIsBusy(&t->w->parts[10]->obj->o) == 0) {
            ShopFreeCompare(t);
            t->w->state = 0x17;
        }
        break;
    case 15:
        if (UiObjIsBusy(&t->w->parts[18]->obj->o) == 0 && UiObjIsBusy(&t->w->parts[11]->obj2->o) == 0) {
            t->w->state = 16;
        } else if (PAD_A) {
            MenuPartsFinish((MenuTask*)t);
            t->w->state = 16;
        }
        break;
    case 16:
        if (PAD_B) {
            if (t->w->xa == 4) {
                break;
            }
            switch (fn_801F4C24(t->w->item)) {
            default:
                return;
            case 1:
                if (t->w->item == t->w->stat[t->w->who[t->w->xa]][1]) {
                    return;
                }
                t->w->xc[t->w->who[t->w->xa]] = 0;
                fn_801F4E38(lbl_803471B8->w->m[t->w->who[t->w->xa]].id, t->w->stat[t->w->who[t->w->xa]][1]);
                break;
            case 2:
                if (t->w->item == t->w->stat[t->w->who[t->w->xa]][2]) {
                    return;
                }
                t->w->xc[t->w->who[t->w->xa]] = 0;
                fn_801F4E04(lbl_803471B8->w->m[t->w->who[t->w->xa]].id, t->w->stat[t->w->who[t->w->xa]][2]);
                break;
            }
        armor_changed:
            fn_801C12C8();
            fn_801C0FBC(t->w->item);
            if (fn_801AAFAC(t)) {
                t->w->xa = 4;
            }
            fn_801AAFAC(t);
        } else if (PAD_A) {
            switch (t->w->xa) {
            case 0:
            case 1:
            case 2:
            case 3:
                if (t->w->x9 != 0 && fn_801C0B88(t->w->item, t->w->who[t->w->xa]) == 0) {
                    t->w->xc[t->w->who[t->w->xa]] = 1;
                    fn_801C0AB4(t->w->item, t->w->who[t->w->xa]);
                    fn_801C08B4(0x16);
                    goto armor_changed; /* shared with the cancel path above */
                }
                fn_801C08B4(3);
                break;
            case 4:
                fn_801C08B4(2);
                fn_801AAFAC(t);
                d = t->w->xb * 2;
                for (cnt = 0; cnt < (i = t->w->xb); cnt++, d -= 2) {
                    UiObjMoveToX(&t->w->parts[lbl_802B69E8[cnt].idx]->obj->o, 6, 5, lbl_802B69E8[cnt].x2);
                    UiObjSetCommand(&t->w->parts[lbl_802B69E8[cnt].idx]->obj->o, 15, d);
                }
                UiObjMoveToX(&t->w->parts[12]->obj->o, 6, 5, -348.0f);
                UiObjSetCommand(&t->w->parts[12]->obj->o, 15, (u8)(i * 2 + 2));
                UiObjMoveToX(&t->w->parts[18]->obj->o, 6, 5, -348.0f);
                UiObjSetCommand(&t->w->parts[18]->obj->o, 15, 0);
                UiObjMoveToX(&t->w->parts[10]->obj->o, 6, -1, 648.0f);
                UiObjSetCommand(&t->w->parts[10]->obj->o, 15, 6);
                UiObjMoveToX(&t->w->parts[10]->obj2->o, 6, -1, 648.0f);
                UiObjSetCommand(&t->w->parts[10]->obj2->o, 15, 4);
                UiObjMoveToX(&t->w->parts[11]->obj->o, 6, -1, 648.0f);
                UiObjSetCommand(&t->w->parts[11]->obj->o, 15, 2);
                UiObjMoveToX(&t->w->parts[11]->obj2->o, 6, -1, 648.0f);
                UiObjSetCommand(&t->w->parts[11]->obj2->o, 15, 0);
                t->w->state = 17;
                break;
            }
        } else if (fn_801AB094((Task_801AB094*)t)) {
            if (t->w->xa != 4 && (old = t->w->who[t->w->xa]) != -1) {
                t->w->parts[11]->obj->h56 = old;
                t->w->parts[10]->obj->h56 = old;
            }
        }
        break;
    case 17:
        if (fn_801C09F8(0, 1) || PAD_A) {
            MenuPartsFinish((MenuTask*)t);
            MenuPartFree((MenuTask*)t, 12);
            MenuPartFree((MenuTask*)t, 18);
            MenuPartFree((MenuTask*)t, 10);
            MenuPartFree((MenuTask*)t, 11);
            for (i = 0; i < 4; i++) {
                MenuPartFree((MenuTask*)t, i + 14);
            }
            fn_801AB328((Self_801AB328*)t);
            MenuPartsFinish((MenuTask*)t);
            t->w->state = 3;
            t->w->parts[8]->x38->state = 1 < t->buf->pages;
        } else if (UiObjIsBusy(&t->w->parts[12]->obj->o) == 0) {
            MenuPartFree((MenuTask*)t, 12);
            MenuPartFree((MenuTask*)t, 18);
            MenuPartFree((MenuTask*)t, 10);
            MenuPartFree((MenuTask*)t, 11);
            for (i = 0; i < 4; i++) {
                MenuPartFree((MenuTask*)t, i + 14);
            }
            fn_801AB328((Self_801AB328*)t);
            t->w->state = 3;
            t->w->parts[8]->x38->state = 1 < t->buf->pages;
        }
        break;
    case 18:
        t->w->state = 18;
        break;
    case 19:
        fn_801C0FBC(t->w->item);
        if (UiObjIsBusy(&t->w->parts[18]->obj->o) == 0 && UiObjIsBusy(&t->w->parts[11]->obj2->o) == 0) {
            t->w->state = 20;
            if (fn_801AACB0(t)) {
                t->w->xa = 4;
            }
            fn_801AACB0(t);
            SHOP_SLOT_CMDS(t, cmd, o);
        } else if (PAD_A) {
            MenuPartsFinish((MenuTask*)t);
            t->w->state = 20;
            if (fn_801AACB0(t)) {
                t->w->xa = 4;
            }
            fn_801AACB0(t);
            SHOP_SLOT_CMDS(t, cmd, o);
        }
        break;
    case 20:
        if (fn_801C09F8(0, 1)) {
            if (t->w->xa >= 4 || t->w->xc[t->w->xa] == 0) {
                break;
            }
            if (t->w->b37 == 0) {
                lbl_8030B7F4.x1568.s1580[t->w->xa] = t->w->stat[0][t->w->xa];
            } else {
                lbl_8030B7F4.x1568.s158a[t->w->xa] = t->w->stat[0][t->w->xa];
            }
            t->w->xc[t->w->xa] = 0;
            fn_8021B1CC(lbl_8030B4D4 + 0x2dc, &lbl_8030B7F4.x1568.b1568);
            fn_801C1E48();
            fn_801C0FBC(t->w->item);
            fn_801AACB0(t);
            SHOP_SLOT_CMDS(t, cmd, o);
        } else if (PAD_A) {
            switch (t->w->xa) {
            case 0:
            case 1:
            case 2:
            case 3:
                if (t->w->b37 == 0) {
                    if (lbl_8030B7F4.x1568.s1580[(u8)t->w->xa] != t->w->item && t->w->x9 != 0) {
                        lbl_8030B7F4.x1568.s1580[(u8)t->w->xa] = t->w->item;
                        t->w->xc[t->w->xa] = 1;
                        fn_801C08B4(0x16);
                    } else {
                        fn_801C08B4(3);
                        break;
                    }
                } else {
                    old = lbl_8030B7F4.x1568.s158a[(u8)t->w->xa] == (s16)t->w->item;
                    if (!old && t->w->x9 != 0) {
                        lbl_8030B7F4.x1568.s158a[t->w->xa] = t->w->item;
                        t->w->xc[t->w->xa] = 1;
                        fn_801C08B4(0x16);
                    } else {
                        fn_801C08B4(3);
                        break;
                    }
                }
                fn_801C08B4(2);
                fn_8021B1CC(lbl_8030B4D4 + 0x2dc, &lbl_8030B7F4.x1568.b1568);
                fn_801C1E48();
                fn_801C0FBC(t->w->item);
                if (fn_801AACB0(t)) {
                    t->w->xa = 4;
                }
                fn_801AACB0(t);
                SHOP_SLOT_CMDS(t, cmd, o);
                break;
            case 4:
                if (t->w->b37 == 0) {
                    for (cnt = 0, d = 8; cnt < 4; cnt++, d -= 2) {
                        UiObjMoveToX(&t->w->parts[lbl_802B69E8[cnt].idx]->obj->o, 6, 4, lbl_802B69E8[cnt].x2);
                        UiObjSetCommand(&t->w->parts[lbl_802B69E8[cnt].idx]->obj->o, 15, d + 2);
                    }
                    UiObjMoveToX(&t->w->parts[12]->obj->o, 6, 5, -348.0f);
                    UiObjSetCommand(&t->w->parts[12]->obj->o, 15, 12);
                    UiObjMoveToX(&t->w->parts[18]->obj->o, 6, 5, -348.0f);
                    UiObjSetCommand(&t->w->parts[18]->obj->o, 15, 0);
                    UiObjMoveToX(&t->w->parts[10]->obj->o, 6, -1, 648.0f);
                    UiObjSetCommand(&t->w->parts[10]->obj->o, 15, 6);
                    UiObjMoveToX(&t->w->parts[10]->obj2->o, 6, -1, 648.0f);
                    UiObjSetCommand(&t->w->parts[10]->obj2->o, 15, 4);
                    UiObjMoveToX(&t->w->parts[11]->obj->o, 6, -1, 648.0f);
                    UiObjSetCommand(&t->w->parts[11]->obj->o, 15, 2);
                    UiObjMoveToX(&t->w->parts[11]->obj2->o, 6, -1, 648.0f);
                    UiObjSetCommand(&t->w->parts[11]->obj2->o, 15, 0);
                } else {
                    for (cnt = 0, d = 6; cnt < 3; cnt++, d -= 2) {
                        UiObjMoveToX(&t->w->parts[lbl_802B69E8[cnt].idx]->obj->o, 6, 4, lbl_802B69E8[cnt].x2);
                        UiObjSetCommand(&t->w->parts[lbl_802B69E8[cnt].idx]->obj->o, 15, d + 2);
                    }
                    UiObjMoveToX(&t->w->parts[12]->obj->o, 6, 5, -348.0f);
                    UiObjSetCommand(&t->w->parts[12]->obj->o, 15, 10);
                    UiObjMoveToX(&t->w->parts[18]->obj->o, 6, 5, -348.0f);
                    UiObjSetCommand(&t->w->parts[18]->obj->o, 15, 0);
                    UiObjMoveToX(&t->w->parts[10]->obj->o, 6, -1, 648.0f);
                    UiObjSetCommand(&t->w->parts[10]->obj->o, 15, 6);
                    UiObjMoveToX(&t->w->parts[10]->obj2->o, 6, -1, 648.0f);
                    UiObjSetCommand(&t->w->parts[10]->obj2->o, 15, 4);
                    UiObjMoveToX(&t->w->parts[11]->obj->o, 6, -1, 648.0f);
                    UiObjSetCommand(&t->w->parts[11]->obj->o, 15, 2);
                    UiObjMoveToX(&t->w->parts[11]->obj2->o, 6, -1, 648.0f);
                    UiObjSetCommand(&t->w->parts[11]->obj2->o, 15, 0);
                }
                t->w->state = 21;
                fn_801C08B4(2);
                break;
            }
        } else if (fn_801C09F8(0, 4)) {
            row = t->w->xa;
            if (t->w->b37 == 0) {
                if (t->w->xa == 0) {
                    t->w->xa = 4;
                } else {
                    t->w->xa--;
                }
            } else if (t->w->xa == 0) {
                t->w->xa = 4;
            } else if (t->w->xa == 4) {
                t->w->xa = 2;
            } else {
                t->w->xa--;
            }
            if ((n = t->w->xa) != 4) {
                t->w->parts[11]->obj->h56 = n;
                t->w->parts[10]->obj->h56 = n;
            }
            if (row != t->w->xa) {
                MenuPlaySe(4);
            }
            SHOP_SLOT_CMDS(t, cmd, o);
        } else if (fn_801C09F8(0, 5)) {
            row = t->w->xa;
            if (t->w->b37 == 0) {
                t->w->xa++;
                if (t->w->xa == 5) {
                    t->w->xa = 0;
                }
            } else {
                t->w->xa++;
                if (t->w->xa == 3) {
                    t->w->xa = 4;
                } else if (t->w->xa == 5) {
                    t->w->xa = 0;
                }
            }
            if ((n = t->w->xa) != 4) {
                t->w->parts[11]->obj->h56 = n;
                t->w->parts[10]->obj->h56 = n;
            }
            SHOP_SLOT_CMDS(t, cmd, o);
            if (row != t->w->xa) {
                MenuPlaySe(4);
            }
        }
        break;
    case 21:
        if (fn_801C09F8(0, 1) || PAD_A) {
            MenuPartsFinish((MenuTask*)t);
        } else if (UiObjIsBusy(&t->w->parts[12]->obj->o)) {
            break;
        }
        MenuPartFree((MenuTask*)t, 12);
        MenuPartFree((MenuTask*)t, 18);
        MenuPartFree((MenuTask*)t, 10);
        MenuPartFree((MenuTask*)t, 11);
        MenuPartFree((MenuTask*)t, 14);
        MenuPartFree((MenuTask*)t, 14);
        MenuPartFree((MenuTask*)t, 15);
        MenuPartFree((MenuTask*)t, 16);
        MenuPartFree((MenuTask*)t, 17);
        fn_801AB328((Self_801AB328*)t);
        t->w->state = 0x17;
        break;
    case 23:
        if (UiObjIsBusy(&t->w->parts[1]->obj->o) == 0) {
            t->w->state = 3;
            t->w->parts[8]->x38->state = 1 < t->buf->pages;
        } else if (PAD_A || fn_801C09F8(0, 1)) {
            MenuPartsFinish((MenuTask*)t);
            t->w->state = 3;
            t->w->parts[8]->x38->state = 1 < t->buf->pages;
        }
        break;
    case 24:
        UiObjMoveTo(&t->w->parts[7]->obj->o, 6, -1, 640.0f, 480.0f);
        UiObjSetCommand(&t->w->parts[7]->obj->o, 15, 0);
        UiObjMoveToX(&t->w->parts[8]->obj->o, 6, -1, 648.0f);
        UiObjSetCommand(&t->w->parts[8]->obj->o, 15, 0);
        UiObjMoveToX(&t->w->parts[9]->obj->o, 6, -1, -624.0f);
        UiObjSetCommand(&t->w->parts[9]->obj->o, 15, 0);
        UiObjMoveToX(&t->w->parts[9]->obj2->o, 6, -1, -624.0f);
        UiObjSetCommand(&t->w->parts[9]->obj2->o, 15, 0);
        t->w->state = 25;
    case 25:
        if (fn_801C09F8(0, 1)) {
            MenuPartFree((MenuTask*)t, 7);
            MenuPartFree((MenuTask*)t, 8);
            MenuPartFree((MenuTask*)t, 9);
            MenuPartFree((MenuTask*)t, 2);
            t->w->parts[4]->flag->b0 = 0;
            t->w->parts[5]->flag->b0 = 0;
            t->w->state = 26;
        } else if (UiObjIsBusy(&t->w->parts[7]->obj->o) == 0) {
            MenuPartFree((MenuTask*)t, 7);
            MenuPartFree((MenuTask*)t, 8);
            MenuPartFree((MenuTask*)t, 9);
            MenuPartFree((MenuTask*)t, 2);
            t->w->parts[4]->flag->b0 = 0;
            t->w->parts[5]->flag->b0 = 0;
            t->w->state = 26;
        }
        break;
    case 26:
        t->state = 5;
        break;
    }
}

void fn_801A2C58(void) {
    if (lbl_8034718C[1] != 0) {
        s32 r;
        fn_801DC214();
        r = CARDUnmount(1);
        if (r == 0 || r == -3) {
            fn_801E17E0(lbl_8034718C[1]);
            lbl_8034718C[1] = 0;
        }
    }
    lbl_80347184[1] = 0;
}

s32 fn_801B5868(s16 id) {
    s16 kind = fn_801F4C24(id);
    switch (kind) {
    case 0:
    case 1:
    case 2:
        return 0;
    case 5:
        return 2;
    case 6:
        return 1;
    case 3:
    case 4:
    case 7:
        return 3;
    default:
        return 4;
    }
}

void fn_801A6650(SaveTask *t, u16 i)
{
    if (t->w->p[i] != NULL) {
        TaskDelete(&t->w->p[i]->task);
        t->w->p[i] = NULL;
    }
}

void fn_8019E3A8(Task *t)
{
    fn_801CBBAC(8.0f);
    t->state = 0x1F;
}

static inline s32 bit_set(u32 mask, s32 k)
{
    s32 f = (mask & (1 << k)) != 0;
    f = f != 0;
    return f;
}

s32 fn_8019A21C(u32 mask, s32 d, s32 n, s32 unused, s32 max)
{
    s32 i;
    s32 k;

    k = n + d;
    if (bit_set(mask, k)) {
        return k;
    }
    if (d > 0) {
        for (i = n; i < max; i++) {
            k = n + d * (i - n + 1);
            if (bit_set(mask, k)) {
                return k;
            }
        }
        if (i >= max) {
            for (i = 0; i < n; i++) {
                if (mask & (1 << (i * d))) {
                    return i;
                }
            }
            if (i >= n) {
                return n;
            }
        }
    } else {
        for (i = n; i > 0; i--) {
            k = n + d * (n - i + 1);
            if (bit_set(mask, k)) {
                return k;
            }
        }
        if (i <= 0) {
            for (k = max; k > n; k--) {
                if (mask & (1 << k)) {
                    return k;
                }
            }
            if (k <= n) {
                return n;
            }
        }
    }
}

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

void fn_801A0E7C(Self_801A0E7C *self) {
    if (SelectSlot(self) != 0 && fn_801A6554(self) == 0) {
        fn_801A64B4(self, 0x11);
        self->ctx->b7 = 0;
        self->ctx->b5 = 0;
        self->ctx->b6 = 0;
        *(void **)((u8 *)self->ctx + 0x24c) = fn_801A343C((Task_801A343C *)self);
        self->state19 = 7;
    }
}

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

s32 fn_801A2500(s32 chan, s32 *out) {
    s32 code;
    s32 xfer;
    s32 r;

    if (lbl_8034718C[chan] == 0) {
        lbl_8034718C[chan] = fn_801E1C7C(0xa000);
    }
    fn_80248DCC(chan, lbl_8034718C[chan], chan == 0 ? fn_801A2CC4 : fn_801A2C58, 0);
    code = CardWait(chan);
    switch (code) {
    case 0:
    case -6:
        CARDCheckExAsync(chan, &xfer, 0);
        code = CardWait(chan);
        if (code != 0) {
            CardRelease(chan);
            r = 0;
        } else {
            lbl_80347184[chan] = 1;
            r = 1;
        }
        break;
    default:
        CardRelease(chan);
        r = 0;
        break;
    }
    if (out != 0) {
        *out = code;
    }
    return r;
}

CardRec *fn_801A41EC(CardSaveData *p, s32 chan, const char *name) {
    CardRec *rec = &lbl_803081A4;
    u32 sum;
    s32 i;

    rec->stamp.year = lbl_80308198.stamp.year;
    rec->stamp.month = lbl_80308198.stamp.month;
    rec->stamp.day = lbl_80308198.stamp.day;
    rec->stamp.hour = lbl_80308198.stamp.hour;
    rec->stamp.min = lbl_80308198.stamp.min;
    rec->stamp.sec = lbl_80308198.stamp.sec;
    rec->stamp.wday = lbl_80308198.stamp.wday;
    strcpy(rec->name, name);
    lbl_803081A4.chan = chan;
    lbl_803081A4.w1c = 0;
    memcpy(p->stamp, &lbl_80308198, 10);
    if (p == NULL) {
        sum = 0;
    } else {
        u32 *q = (u32 *)p;
        sum = 0;
        for (i = 3199; i != 0; i--) {
            sum ^= *q++;
        }
    }
    p->sum = sum;
    rec->w14 = 3;
    rec->buf = fn_801E1C7C(0x6000);
    if (rec->buf == NULL) {
        return NULL;
    }
    memset(rec->buf, 0, 0x6000);
    memcpy((u8 *)rec->buf + 0x1440, p, 0x3200);
    return rec;
}

s32 fn_801AAFAC(ShopTask *self) {
    u32 i;
    u32 n;
    s32 done = 0;

    for (i = n = 0; i < self->w->xb; i++) {
        if (fn_801C0B88(self->w->item, self->w->who[i])) {
            n++;
            self->w->parts[14 + i]->obj->o.alpha = 0.7f;
            if (n == self->w->xb) {
                done = 1;
            }
        } else if (self->w->x9 != 0) {
            self->w->parts[14 + i]->obj->o.alpha = 1.0f;
        } else {
            self->w->parts[14 + i]->obj->o.alpha = 0.7f;
            done = 1;
        }
    }
    return done;
}

void fn_801ABD40(PanelTask_801ABD40* t) {
    f32 z;
    if (lbl_803475D8 != 0) {
        t->state = 0xFF;
    }
    switch (t->state) {
    case 0:
    case 0xFE:
        if (t->flag[0] == 1) {
            return;
        }
        UiObjUpdate(&t->pan->o);
        UiLayoutDraw(&menu_sprites.texlist8, lbl_802B6B0C, 4, &t->pan->o.x, t->pan->o.z, 1.0f, 1.0f);
        z = TextGetZ();
        TextSetZ(-4027.5f);
        TextPushColor();
        TextSetColor(0xFF201008);
        TextPrint(24.0f + t->pan->o.x, 20.0f + t->pan->o.y, lbl_80346810[t->pan->h56]);
        TextPopColor(1);
        TextSetZ(z);
        break;
    case 0xFF:
        MenuDummy(t);
        t->flags |= 0x40;
        break;
    }
}

void* fn_801AFBE8(void* parent, u16 idx, u16 mode, f32 alpha) {
    PanelTask_801AFBE8* t = fn_802267AC(parent, fn_801AFAA4);

    t->w = fn_801E1A74(1, 0x58);
    t->obj = fn_801E1A74(1, 0x6c);
    t->obj->o.f38 = 1.0f;
    t->x2c = 0;
    t->obj->h56 = idx;
    t->obj->h54 = mode;
    t->obj->o.alpha_en = 0;
    t->obj->o.alpha = alpha;
    t->w->b0 = 0;
    t->obj->o.x = -348.0f;
    t->obj->o.tx = -348.0f;
    t->obj->o.y = lbl_802B8F20[idx].y;
    t->obj->o.ty = lbl_802B8F20[idx].y;
    t->obj->o.z = lbl_802B8F20[idx].z;
    t->obj->h52 = 1;
    if (mode != 0) {
        t->w->cb = fn_801AFD34;
    } else {
        t->w->cb = fn_801B0014;
    }
    UiObjSetLowered(&t->obj->o);
    return t;
}

void fn_801B71E8(s32 x, s32 y, s16 id) {
    extern TextNode* TextPrint(s32 x, s32 y, const char *str);
    switch ((s8)lbl_80310A1C[0x64 + id]) {
    case 1:
    case 2:
        TextPrint(x, y, lbl_802EBFDC[id].a);
        break;
    case 3:
        TextPrint(x, y, lbl_802EBFDC[id].b);
        break;
    default:
        TextPrint(x, y, lbl_802B8F80);
        break;
    }
}

void fn_801B7274(s32 x, s32 y, s32 nx, s32 ny, s16 id) {
    extern TextNode* TextPrint(s32 x, s32 y, const char *str);
    extern void TextPrintNumber(s32 x, s32 y, s32 value, u32 flags);
    char buf[32];
    switch ((s8)lbl_80310A1C[0x64 + id]) {
    case 0:
        strcpy(buf, lbl_802B8F94);
        break;
    case 1:
    case 2:
        strcpy(buf, lbl_802EBF7C[id]);
        break;
    case 3:
        if (id != 5) {
            strcpy(buf, lbl_802EBF7C[id]);
        } else {
            strcpy(buf, lbl_802B8F70);
        }
        break;
    }
    TextPrint(x, y, buf);
    TextPrintNumber(nx, ny, lbl_802EBFBC[id], 0xC005);
}

void fn_801A4B40(void* a) {
    Tsk_801A4B40* t = a;
    SpriteObj obj;
    f32 pos[2];
    f32 z;
    s32 j, i;
    if (lbl_803475D8 != 0) t->state = 0xff;
    switch (t->state) {
    case 0:
    case 0xfe:
        z = -9990.0f;
        obj.sprite = fn_801D68C4(menu_sprites.banks[1], 0);
        obj.z = -9990.0f;
        obj.b = 1.0f;
        obj.a = t->par->in->f18;
        obj.texlist = (NJS_TEXLIST*)menu_sprites.textlistC;
        obj.flags = 0;
        obj.colour = 0;
        for (j = 0; j < 8; j++) {
            for (i = 0; i < 10; i++) {
                obj.z = z;
                pos[0] = i * 64;
                pos[1] = j * 64;
                SpriteObjDrawAt(&obj, pos);
                z += 0.05f;
            }
        }
        obj.sprite = fn_801D68C4(menu_sprites.banks[0], 0);
        obj.z = -9980.0f;
        obj.flags = 3;
        obj.texlist = (NJS_TEXLIST*)menu_sprites.textlistC;
        SpriteObjDraw(&obj);
        obj.flags = 1;
        obj.texlist = (NJS_TEXLIST*)menu_sprites.texlist8;
        obj.sprite = fn_801D68C4(menu_sprites.banks[2], 0);
        obj.z = -9970.0f;
        SpriteObjDraw(&obj);
        obj.sprite = fn_801D68C4(menu_sprites.banks[2], 3);
        obj.z = -9960.0f;
        SpriteObjDraw(&obj);
        obj.sprite = fn_801D68C4(menu_sprites.banks[2], 1);
        obj.z = -9950.0f;
        SpriteObjDraw(&obj);
        obj.sprite = fn_801D68C4(menu_sprites.banks[2], 2);
        obj.z = -9940.0f;
        SpriteObjDraw(&obj);
        obj.texlist = (NJS_TEXLIST*)menu_sprites.texlist8;
        obj.sprite = fn_801D68C4(menu_sprites.banks[3], 0);
        SpriteObjDraw(&obj);
        if (t->par->flags & 0x40) t->flags |= 0x40;
        break;
    case 0xff:
        t->flags |= 0x40;
        break;
    }
}

void fn_801ABA30(void* a)
{
    Ent_801ABA30* t = a;
    SpriteObj obj;
    f32 pos[2];
    s32 i, j;
    f32 z;

    if (lbl_803475D8 != 0) {
        t->mode = 0xFF;
    }
    switch (t->mode) {
    case 0:
    case 0xFE:
        z = -10100.0f;
        obj.sprite = fn_801D68C4(menu_sprites.banks[1], 0);
        obj.z = -10100.0f;
        obj.b = 1.0f;
        obj.a = 1.0f;
        obj.texlist = menu_sprites.textlistC;
        obj.flags = 1;
        obj.colour = 0;
        for (i = 0; i < 8; i++) {
            for (j = 0; j < 10; j++) {
                obj.z = z;
                pos[0] = (f32)(j * 64);
                pos[1] = (f32)(i * 64);
                SpriteObjDrawAtEx(&obj, pos);
                z += 0.05f;
            }
        }
        obj.sprite = fn_801D68C4(menu_sprites.banks[0], 0);
        z += 0.05f;
        obj.flags = 3;
        obj.z = z;
        obj.texlist = menu_sprites.textlistC;
        SpriteObjDraw(&obj);
        obj.flags = 1;
        obj.texlist = menu_sprites.texlist8;
        obj.sprite = fn_801D68C4(menu_sprites.banks[2], 0);
        z += 0.05f;
        obj.z = z;
        SpriteObjDraw(&obj);
        z += 0.05f * (f32)fn_801D68C4(menu_sprites.banks[2], 0)->count;
        obj.z = z;
        obj.sprite = fn_801D68C4(menu_sprites.banks[2], 3);
        SpriteObjDraw(&obj);
        z += 0.05f * (f32)fn_801D68C4(menu_sprites.banks[2], 3)->count;
        obj.z = z;
        obj.sprite = fn_801D68C4(menu_sprites.banks[2], 1);
        SpriteObjDraw(&obj);
        obj.z = z + 0.05f * (f32)fn_801D68C4(menu_sprites.banks[2], 1)->count;
        obj.sprite = fn_801D68C4(menu_sprites.banks[2], 2);
        SpriteObjDraw(&obj);
        obj.texlist = menu_sprites.texlist8;
        obj.sprite = fn_801D68C4(menu_sprites.banks[3], 0xD);
        SpriteObjDraw(&obj);
        if (t->sub->flags & 0x40) {
            t->flags |= 0x40;
        }
        break;
    case 0xFF:
        t->flags |= 0x40;
        break;
    }
}

void fn_8019D598(Self* o) {
    Parent* p = o->parent;
    Data* d = o->data;
    if (p->flags & 0x40) {
        o->flags |= 0x40;
    } else {
        switch (o->state) {
        case 0:
            d->x7c += 0.05;
            d->x80 += 0.05;
            d->x84 += 0.05;
            fn_8009076C(1, d);
            d->x88--;
            if (d->x88 <= 0) {
                o->state = 0xff;
            }
            break;
        case 0xff:
            o->flags |= 0x40;
            break;
        }
    }
}

typedef struct { u8 pad[0x24]; MenuPartWork* w; MenuPanel* obj; u32 w2c; } T_801B65CC;
typedef struct { const char* text; f32 x; } NameEnt;
extern const f32 lbl_802B8EDC[];
extern NameEnt lbl_802EC01C[];

T_801B65CC* fn_801B65CC(void* a, u16 idx, f32 y) {
    T_801B65CC* t = fn_802267AC(a, fn_801B6420);
    t->w = fn_801E1A74(1, 0x58);
    t->obj = fn_801E1A74(1, 0x6c);
    t->w2c = 0;
    t->w2c = 0;
    t->obj->h54 = idx;
    t->w->b0 = 0;
    t->obj->o.alpha_en = 1;
    t->obj->o.x = -260.0f;
    t->obj->o.tx = -260.0f;
    t->obj->o.y = y;
    t->obj->o.ty = y;
    t->obj->o.z = lbl_802B8EDC[idx];
    t->obj->o.rdx = 0.0f;
    t->obj->o.rdy = 0.0f;
    t->obj->o.alpha = 1.0f;
    t->obj->text = lbl_802EC01C[idx].text;
    t->obj->h56 = idx;
    UiObjSetLowered(&t->obj->o);
    return t;
}

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

void fn_801A372C(void) {
    Unmount(0);
    Unmount(1);
}

u32 fn_801A4684(u32 *p, u32 size)
{
    u32 sum;
    u32 i;

    if (p == NULL) {
        return 0;
    }
    size >>= 2;
    sum = 0;
    for (i = 0; i < size; i++) {
        sum ^= *p++;
    }
    return sum;
}

void fn_801A2424(s32 n, s32 idx, char* buf, s32 len) {
    char* s = lbl_802B9428[idx];
    char* p;
    s32 lim;
    s32 i;
    if (strlen(s) < (lim = len - 4)) {
        sprintf(buf, "#%d %s", n, s);
    } else {
        buf[0] = '#';
        buf[1] = n + '0';
        buf[2] = ' ';
        p = buf + 3;
        lim--;
        for (i = 3; i < lim; i++) {
            if (*s == 0) break;
            *p = *s;
            s++;
            p++;
        }
        *p = 0;
    }
}

static inline void ScrollUp(Self_801A1958 *o, s32 st) {
    s32 i;
    o->ctx->x6--;
    for (i = 0; i < 7; i++) {
        UiObjMoveToY(&o->ctx->objs[i]->obj->o, 6, -1, 110.0f + o->ctx->objs[i]->obj->o.y);
        UiObjSetCommand(&o->ctx->objs[i]->obj->o, 0xf, 0);
    }
    MenuPlaySe(4);
    o->state = st;
}

static inline void ScrollDown(Self_801A1958 *o, s32 st) {
    s32 i;
    o->ctx->x6++;
    for (i = 0; i < 7; i++) {
        UiObjMoveToY(&o->ctx->objs[i]->obj->o, 6, -1, o->ctx->objs[i]->obj->o.y - 110.0f);
        UiObjSetCommand(&o->ctx->objs[i]->obj->o, 0xf, 0);
    }
    MenuPlaySe(4);
    o->state = st;
}

void fn_801A1958(Self_801A1958 *o, s32 st) {
    s32 v;
    if (fn_801C09F8(0, 4) != 0) {
        if (o->ctx->x5 == 0) {
            if (o->ctx->x6 != 0) {
                ScrollUp(o, st);
            }
        } else {
            MenuPlaySe(4);
            o->ctx->x5--;
        }
    } else if (fn_801C09F8(0, 5) != 0) {
        if (o->ctx->x5 == 2) {
            if (o->ctx->x6 != 4) {
                ScrollDown(o, st);
            }
        } else {
            MenuPlaySe(4);
            o->ctx->x5++;
        }
    }
    o->ctx->x7 = o->ctx->x5 + o->ctx->x6;
    if (o->ctx->x1 == 1) {
        switch (o->ctx->items[o->ctx->x7].kind) {
        case 2:
        case 4: v = 0xd; break;
        case 3:
        default: v = 0xc; break;
        }
    } else {
        v = 5;
    }
    fn_801A64B4(o, v);
}

void fn_8019BED8(struct Task* t, Obj_8019BED8* o) {
    Ent_8019BED8* e;
    Rec* r;
    s32 ty;
    s32 k;
    t->state = 5;
    e = o->ent;
    if (e == NULL) return;
    o->h = fn_802258BC(0xffff, (u16)e->id, 2);
    if (o->h == NULL) return;
    r = e->rec;
    if (r == NULL) return;
    ty = r->type;
    if (ty <= 10) return;
    o->f20c = r->f24;
    k = r->f28;
    o->f210 = k;
    if (k == 0) {
        if ((u32)ty == 0xf && r->f34 > r->f38) {
            o->f24c = 0.0001f * r->f2c;
            o->f250 = 0.0001f * r->f30;
            o->f254 = 0.01f * r->f34;
            o->f258 = 0.01f * r->f38;
            o->f48 = 182.04445f * (0.01f * r->f3c);
            o->v[1] = 0.0f;
            o->v[0] = 0.0f;
            o->v[2] = -o->f24c;
            fn_801DCE18(o->v, o->v, o->f48);
            t->state = 3;
        }
    } else if (k == 1) {
        if ((u32)ty == 0x10 && r->f34 > r->f38) {
            o->f24c = 0.0001f * r->f2c;
            o->f250 = 0.0001f * r->f30;
            o->f254 = 0.01f * r->f34;
            o->f258 = 0.01f * r->f38;
            o->f38 = 0.01f * r->f3c;
            o->f40 = 0.01f * r->f40;
            o->v[1] = 0.0f;
            t->state = 4;
        }
    }
}

void fn_801A1B98(Self_801A0C3C *o, u8 mode) {
    s32 i;
    s32 k = 4 - o->ctx->x6;
    const f32 *tb;
    if (mode == 0) {
        tb = &lbl_802B4920[k];
        for (i = 0; i < 7; i++) {
            if (o->ctx->objs[lbl_802B494C[i].idx] == 0) {
                f32 f;
                o->ctx->objs[lbl_802B494C[i].idx] = fn_801A53D4(o, lbl_802B494C[i].b1);
                f = tb[i];
                o->ctx->objs[lbl_802B494C[i].idx]->obj->o.ty = f;
                o->ctx->objs[lbl_802B494C[i].idx]->obj->o.y = f;
            }
            UiObjMoveToX(&o->ctx->objs[lbl_802B494C[i].idx]->obj->o, 6, 4, 336.0f);
            UiObjSetCommand(&o->ctx->objs[lbl_802B494C[i].idx]->obj->o, 0xf, lbl_802B494C[i].b2);
        }
    } else {
        tb = &lbl_802B4920[k];
        for (i = 0; i < 7; i++) {
            if (i != o->ctx->x7) {
                if (o->ctx->objs[lbl_802B494C[i].idx] == 0) {
                    f32 f;
                    o->ctx->objs[lbl_802B494C[i].idx] = fn_801A53D4(o, lbl_802B494C[i].b1);
                    f = tb[i];
                    o->ctx->objs[lbl_802B494C[i].idx]->obj->o.ty = f;
                    o->ctx->objs[lbl_802B494C[i].idx]->obj->o.y = f;
                }
                UiObjMoveToX(&o->ctx->objs[lbl_802B494C[i].idx]->obj->o, 6, 4, 336.0f);
                UiObjSetCommand(&o->ctx->objs[lbl_802B494C[i].idx]->obj->o, 0xf, lbl_802B494C[i].b4);
            }
        }
    }
}

void fn_801B60E8(MP_801B60E8* p) {
    Tri t = lbl_802B8EF0;
    int i;
    VertexCol* v;
    f32 z = fn_801DBD9C(-0.1f);
    for (i = 0; i < 3; i++) {
        v = &t.v[i];
        v->x = 264.0f + (18.0f + v->x) + p->obj->o.x;
        v->y = 48.0f + (16.0f + v->y) + p->obj->o.y;
        v->z = z;
    }
    fn_80290ED4(t.v, 3, 0);
}

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

s32 fn_801BDEF4(u16 id, u16 mode)
{
    s32 f;
    s32 rk;
    if (mode == 0) {
        f = FlagTest(id + 0xBAE);
        if (f != 0) {
            return lbl_802ED258[id].f10;
        }
        f = FlagTest(id + 0xC62);
        if (f != 0) {
            return lbl_802ED258[id].f10;
        }
        rk = Rank(id);
        switch ((s8)rk) {
        case 0:
        case 1:
            return lbl_802ED258[id].f14;
        case 2:
            return lbl_802ED258[id].f10;
        }
    } else {
        f = FlagTest(id + 0xBAE);
        if (f != 0) {
            return lbl_802ED258[id].f18;
        }
        rk = Rank(id);
        switch ((s8)rk) {
        case 0:
            return lbl_802ED258[id].f20;
        case 1:
            return lbl_802ED258[id].f1c;
        case 2:
            return lbl_802ED258[id].f1c;
        }
    }
    return 0;
}

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
void fn_801BE468(void) {
    s32 i;
    s32 t;
    u16 lim;
    Pass1();
    if (lbl_80310B3C[0x80 / 4] & 0x400000) {
        return;
    }
    for (i = 0; i < 0x58; i++) {
        lim = lbl_802ED258[i].xc;
        t = FlagTest(i + 0xC62);
        if (!t) {
            if (lbl_803473BE >= lim) {
                FlagSet(i + 0xBAE);
            } else {
                FlagClear(i + 0xBAE);
            }
        }
    }
}
extern const f32 lbl_802B8F40[6];
extern const f32 lbl_802B8F58[6];
ShopPart* fn_801AD00C(ShopTask* t, u8 kind, u16 who) {
    ShopPart* p = fn_802267AC(t, fn_801ACE70);
    p->flag = fn_801E1A74(1, 0x58);
    p->obj = fn_801E1A74(1, 0x6c);
    p->obj->o.alpha_en = 0;
    p->obj->o.tx = p->obj->o.x = 648.0f;
    p->obj->o.ty = p->obj->o.y = lbl_802B8F40[kind];
    UiObjSetLowered(&p->obj->o);
    p->obj->o.z = kind == 0 ? -4600.0f : -4700.0f;
    p->obj->o.alpha = (kind & 1) == 0 ? 0.7f : 1.0f;
    p->obj->o.f38 = 1.0f;
    p->obj->h52 = 1;
    p->obj->h54 = kind;
    p->obj->h56 = who;
    p->obj2 = fn_801E1A74(1, 0x6c);
    p->obj2->o.alpha_en = 0;
    p->obj2->o.tx = p->obj2->o.x = 648.0f;
    p->obj2->o.ty = p->obj2->o.y = lbl_802B8F58[kind];
    UiObjSetLowered(&p->obj2->o);
    p->obj2->o.z = kind == 0 ? -4650.0f : -4750.0f;
    p->obj2->o.alpha = (kind & 1) == 0 ? 0.7f : 1.0f;
    p->obj2->o.f38 = 1.0f;
    p->obj2->h52 = 1;
    p->obj2->h54 = kind;
    p->flag->b0 = 0;
    return p;
}

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

void fn_801B5644(ShopPart* p, u16 id) {
    UiObjMoveToX(&p->obj->o, 6, -1, -8.0f);
    UiObjSetCommand(&p->obj->o, 15, 0);
    p->obj->o.z = -4700.0f;
    p->obj->h52 = ShopItemKind(id);
    p->obj->h56 = id;
}

void fn_801B571C(ShopPart* p, u16 id) {
    if (UiObjIsBusy(&p->obj->o)) {
        UiObjFinish(&p->obj->o);
    }
    if (p->obj->h52 != ShopItemKind(id)) {
        p->flag->w10 = 0;
    }
    p->obj->h52 = ShopItemKind(id);
    p->obj->h56 = id;
}

void* fn_801BE17C(u16 id) {
    s32 f1 = FlagTest(id + 0xBAE);
    s32 f2;
    if (f1) {
        return lbl_802ED258[id].b;
    }
    f2 = FlagTest(id + 0xC62);
    if (f2) {
        return lbl_802ED258[id].b;
    }
    switch ((s8)Rank(id)) {
    case 0:
        return lbl_802ED258[id].a;
    case 1:
        return lbl_802ED258[id].c;
    case 2:
        return lbl_802ED258[id].c;
    }
    return NULL;
}

void fn_801BE2F0(ShopEntry* e, u8 mode) {
    u32 thr;
    s8 c;
    c = e->flag = Rank(e->id);
    if (mode == 0) {
        switch (c) {
        case 0:
            e->type = 1;
        default:
            return;
        case 1:
            thr = lbl_802ED258[e->id].f14;
            break;
        case 2:
            thr = lbl_802ED258[e->id].f10;
            break;
        }
        if (FlagTest(e->id + 0xC08) != 0 || FlagTest(e->id + 0xC62) != 0) {
            e->type = 1;
            return;
        }
        if (lbl_8030B7F4.w34c >= thr) {
            e->type = 0;
        } else {
            e->type = 1;
        }
    } else {
        e->type = 0;
    }
}

extern char* fn_801C2CBC(s16 id);
void fn_801AFD34(void* arg) {
    PanelTask_801AFBE8* t = arg;
    MenuPanel* p;
    CmpEq eq;
    s16 id = lbl_8030B7F4.x1568.s158a[t->obj->h56];
    s32 x;
    s16 y;

    TextSetColor(0xFF201008);
    TextSetZ(-27.5f + t->obj->o.z);
    fn_801C2CF4(&eq, id);
    fn_801B6BB4(t->obj, t->obj->o.rect, id, -1, 0x14, 6, t->obj->o.alpha);
    if (id != -1) {
        p = t->obj;
        TextPrint(50.0f + p->o.rect[0], 5.0f + p->o.rect[1], fn_801C2CBC(id));
        y = 31.0f + t->obj->o.rect[1];
        x = (s16)(t->obj->o.rect[0] - 2.0f);
        TextPrintNumber(x + lbl_802B8ECC[4], y, eq.v[1], 0xC004);
        TextPrintNumber(x + lbl_802B8ECC[5], y, eq.v[2], 0xC004);
        TextPrintNumber(x + lbl_802B8ECC[6], y, eq.v[4], 0xC004);
        TextPrintNumber(x + lbl_802B8ECC[7], y, eq.v[7], 0xC004);
    } else {
        TextPrint(50.0f + t->obj->o.rect[0], 5.0f + t->obj->o.rect[1], lbl_802EC04C[0]);
        y = 31.0f + t->obj->o.rect[1];
        x = (s16)(t->obj->o.rect[0] - 2.0f);
        TextPrintNumber(x + lbl_802B8ECC[4], y, eq.v[1], 0xC004);
        TextPrintNumber(x + lbl_802B8ECC[5], y, eq.v[2], 0xC004);
        TextPrintNumber(x + lbl_802B8ECC[6], y, eq.v[4], 0xC004);
        TextPrintNumber(x + lbl_802B8ECC[7], y, eq.v[7], 0xC004);
    }
}

void fn_801B0014(void* arg) {
    PanelTask_801AFBE8* t = arg;
    MenuPanel* p;
    CmpEq eq;
    s16 id = lbl_8030B7F4.x1568.s1580[t->obj->h56];
    s32 x;
    s16 y;

    TextSetColor(0xFF201008);
    TextSetZ(-27.5f + t->obj->o.z);
    fn_801C2CF4(&eq, id);
    fn_801B6BB4(t->obj, t->obj->o.rect, id, -1, 0x14, 6, t->obj->o.alpha);
    if (id != -1) {
        p = t->obj;
        TextPrint(50.0f + p->o.rect[0], 5.0f + p->o.rect[1], fn_801C2CBC(id));
        y = 31.0f + t->obj->o.rect[1];
        x = (s16)(t->obj->o.rect[0] - 2.0f);
        TextPrintNumber(x + lbl_802B8EBC[4], y, eq.v[0], 0xC004);
        TextPrintNumber(x + lbl_802B8EBC[5], y, eq.v[3], 0xC004);
        TextPrintNumber(x + lbl_802B8EBC[6], y, eq.v[5], 0xC004);
        TextPrintNumber(x + lbl_802B8EBC[7], y, eq.v[6], 0xC001);
    } else {
        TextPrint(50.0f + t->obj->o.rect[0], 5.0f + t->obj->o.rect[1], lbl_802EC04C[0]);
        y = 31.0f + t->obj->o.rect[1];
        x = (s16)(t->obj->o.rect[0] - 2.0f);
        TextPrintNumber(x + lbl_802B8EBC[4], y, eq.v[0], 0xC004);
        TextPrintNumber(x + lbl_802B8EBC[5], y, eq.v[3], 0xC004);
        TextPrintNumber(x + lbl_802B8EBC[6], y, eq.v[5], 0xC004);
        TextPrintNumber(x + lbl_802B8EBC[7], y, eq.v[6], 0xC001);
    }
}

void fn_801A20AC(SaveTask* t) {
    s32 b = 0;
    s32 a = 0;
    u16 cmd;
    UiObj *ui;
    if (t->w->sel == 2) {
        if (t->w->st[1] != 1) {
            t->w->sel = 1;
            b = 1;
        }
        if (t->w->st[0] != 1) {
            t->w->sel = 0;
            a = 1;
        }
    } else {
        if (t->w->st[0] != 1) {
            a = 1;
        } else if (t->w->st[1] != 1) {
            t->w->sel = 1;
        }
        if (t->w->st[1] != 1) {
            b = 1;
        } else if (t->w->st[0] != 1) {
            t->w->sel = 0;
        }
    }
    ui = &t->w->p[3]->obj->o;
    if (a != 0) {
        s32 c = 0x14;
        if (t->w->sel == 0) {
            c = 0x15;
        }
        cmd = c;
    } else {
        cmd = 0x14;
    }
    UiObjSetCommand(ui, cmd, 0);
    ui = &t->w->p[4]->obj->o;
    if (b != 0) {
        s32 c = 0x14;
        if (t->w->sel == 1) {
            c = 0x15;
        }
        cmd = c;
    } else {
        cmd = 0x14;
    }
    UiObjSetCommand(ui, cmd, 0);
}

void fn_801B0838(void* arg) {
    ShopPart* t = arg;
    TextSetColor(0xFF201008);
    TextPrint(86.0f + t->obj->o.rect[0], 6.0f + t->obj->o.rect[1], t->obj->text);
    TextPrint(224.0f + t->obj->o.rect[0], 6.0f + t->obj->o.rect[1], "Lv");
    TextPrint(86.0f + t->obj->o.rect[0], 30.0f + t->obj->o.rect[1], "Hp    /");
    TextPrint(224.0f + t->obj->o.rect[0], 30.0f + t->obj->o.rect[1], "Mp  /");
    if (t->obj->h54 != 4) {
        TextPrintNumber(248.0f + t->obj->o.rect[0], 6.0f + t->obj->o.rect[1], lbl_803471B8->w->m[t->obj->h56].b5, 0xC002);
        TextPrintNumber(248.0f + t->obj->o.rect[0], 30.0f + t->obj->o.rect[1], lbl_803471B8->w->m[t->obj->h56].b6, 0xC002);
        TextPrintNumber(284.0f + t->obj->o.rect[0], 30.0f + t->obj->o.rect[1], lbl_803471B8->w->m[t->obj->h56].b7, 0xC002);
        TextPrintNumber(110.0f + t->obj->o.rect[0], 30.0f + t->obj->o.rect[1], lbl_803471B8->w->m[t->obj->h56].h10, 0xC004);
        TextPrintNumber(170.0f + t->obj->o.rect[0], 30.0f + t->obj->o.rect[1], lbl_803471B8->w->m[t->obj->h56].h12, 0xC004);
    }
}

ShopPart* fn_801B057C(ShopTask* t, u16 kind, u16 who) {
    ShopPart* p = fn_802267AC(t, fn_801B02F4);
    p->flag = fn_801E1A74(1, 0x58);
    p->obj = fn_801E1A74(1, 0x6c);
    p->obj->o.f38 = 1.0f;
    p->obj->o.alpha = 1.0f;
    p->obj->h56 = who;
    p->obj->h54 = kind;
    p->flag->h6 = lbl_803471B8->w->m[who].id;
    p->flag->cb = fn_801B0838;
    p->obj->o.alpha_en = 0;
    p->flag->b0 = 0;
    p->obj->o.tx = p->obj->o.x = -348.0f;
    p->obj->o.ty = p->obj->o.y = lbl_802B8F20[kind].y;
    p->obj->o.z = lbl_802B8F20[kind].z;
    p->obj->h52 = 1;
    p->obj->text = lbl_803471B8->w->m[who].name;
    UiObjSetLowered(&p->obj->o);
    return p;
}

ShopPart* fn_801B06CC(ShopTask* t, u16 kind, u16 who, f32 alpha) {
    ShopPart* p = fn_802267AC(t, fn_801B02F4);
    p->flag = fn_801E1A74(1, 0x58);
    p->obj = fn_801E1A74(1, 0x6c);
    p->obj->o.f38 = 1.0f;
    p->obj2 = NULL;
    p->obj->h56 = who;
    p->obj->h54 = kind;
    p->flag->h6 = lbl_803471B8->w->m[who].id;
    p->flag->cb = fn_801B0838;
    p->obj->o.alpha_en = 0;
    p->obj->o.alpha = alpha;
    p->flag->b0 = 0;
    p->obj->o.tx = p->obj->o.x = -348.0f;
    p->obj->o.ty = p->obj->o.y = lbl_802B8F20[kind].y;
    p->obj->o.z = lbl_802B8F20[kind].z;
    p->obj->h52 = 1;
    p->obj->text = lbl_803471B8->w->m[who].name;
    UiObjSetLowered(&p->obj->o);
    return p;
}

extern void fn_801B4F78(s32 x, s32 y, u16 cur, u16 id);
extern s16 fn_801C153C(s16 i, s16 cur);

void fn_801B46EC(void* arg) {
    ShopPart* t = arg;
    MenuPanel* v = t->obj;
    s16 id;
    s32 i;
    for (i = 0; i < 3; i++) {
        id = lbl_803471B8->w->h10a[i];
        if (id != -1) {
            if (id == v->h56) {
                TextSetColor(0x40201008);
                TextPrint(260.0f + v->o.rect[0], 60.0f + v->o.rect[1] + (f32)(i * 25), lbl_802EC04C[2]);
            } else {
                TextSetColor(0xFF201008);
                fn_801B4F78(v->o.rect[0], 60.0f + v->o.rect[1] + (f32)(i * 24), v->h56, lbl_803471B8->w->h10a[i]);
            }
            TextPrint(44.0f + v->o.rect[0], 60.0f + v->o.rect[1] + (f32)(i * 25), fn_801F4AE4(lbl_803471B8->w->h10a[i]));
            fn_801B6BB4(v, &v->o.rect[0], lbl_803471B8->w->h10a[i], -1, 0x10, 0x3C + i * 25, v->o.alpha);
        } else {
            TextSetColor(0xFF201008);
            TextPrint(44.0f + v->o.rect[0], 60.0f + v->o.rect[1] + (f32)(i * 25), lbl_802EC04C[0]);
            fn_801B4F78(v->o.rect[0], 60.0f + v->o.rect[1] + (f32)(i * 24), v->h56, lbl_803471B8->w->h10a[i]);
        }
    }
}

void fn_801B4CF0(void* arg) {
    ShopPart* t = arg;
    MenuPanel* v = t->obj;
    s32 i;
    s32 sel;
    u32 color;
    f32 f;

    for (i = 0; i < 4; i++) {
        switch (fn_801C153C(i, v->h56)) {
        case 0:
            f = v->o.alpha;
            color = 0xFF201008;
            sel = -1;
            fn_801B4F78(v->o.rect[0], 60.0f + v->o.rect[1] + (f32)(i * 24), v->h56, lbl_803471B8->w->d8[i].v);
            break;
        case 1:
            f = 0.7f * v->o.alpha;
            color = 0x40201008;
            sel = 2;
            break;
        case 2:
            f = 0.7f * v->o.alpha;
            color = 0x40201008;
            sel = 1;
            break;
        }
        TextSetColor(color);
        fn_801B6BB4(v, &v->o.rect[0], lbl_803471B8->w->d8[i].v, -1, 0x10, 0x3C + i * 25, f);
        TextPrint(44.0f + v->o.rect[0], 60.0f + v->o.rect[1] + (f32)(i * 25), fn_801F4AE4(lbl_803471B8->w->d8[i].v));
        if (sel != -1) {
            TextPrint(236.0f + v->o.rect[0], 60.0f + v->o.rect[1] + (f32)(i * 25), lbl_802EC04C[sel]);
        }
    }
}

void fn_801B914C(ShopTask* t, u8 dir)
{
    u16 old;
    ShopPart* s;
    s32 i;
    u16 ok;
    s = t->w->parts[8];
    old = s->list->tab;
    switch (dir) {
    case 0:
        s->list->tab = 0;
        goto fwd;
    case 2:
        if (old == 4) s->list->tab = 0;
        else s->list->tab = old + 1;
    case 1:
    fwd:
        for (i = 0; i < 5; i++) {
            ok = fn_801B952C(t->w->parts[8]->list->tab);
            if (ok != 0) break;
            s->list->tab++;
            if (s->list->tab == 5) s->list->tab = 0;
        }
        if ((s32)old != s->list->tab) {
            s->list->page = 0;
            s->list->row = 0;
            s->x38->angle = 0;
        }
        return;
    case 3:
        if (old == 0) s->list->tab = 5;
        s->list->tab--;
        for (i = 0; i < 5; i++) {
            ok = fn_801B952C(t->w->parts[8]->list->tab);
            if (ok != 0) break;
            if (s->list->tab == 0) s->list->tab = 5;
            s->list->tab--;
        }
        if ((s32)old != s->list->tab) {
            s->list->page = 0;
            s->list->row = 0;
            s->x38->angle = 0;
        }
        break;
    }
}

extern u32 lbl_80347198;
void fn_801AC87C(ShopPart* t);

void fn_801AC48C(ShopPart* t) {
    f32 z;
    ShopList* p;
    UiObj* ui;
    NJS_TEXLIST** tl;
    switch (t->state) {
    case 0:
    case 0xFE:
        if (t->flag->b0 == 1) {
            return;
        }
        UiObjUpdate(&t->obj->o);
        tl = &menu_sprites.texlist8;
        UiLayoutDraw(tl, lbl_802B6EE8, 4, &t->obj->o.x, t->obj->o.z, 1.0f, 1.0f);
        lbl_80347198 = t->list->row;
        t->list->oy = (f32)(t->list->row * 0x18);
        p = t->list;
        ui = &t->obj->o;
        if ((p->flags & 1) && p->part != 0xff) {
            f32 a = 0.0f;
            if (p->flags & 2) {
                p->x = ui->x + p->ox;
                p->y = ui->y + p->oy;
                p->scale = 0.3f * njCos(p->angle) + 1.0f;
                p->angle += 0x800;
                a = p->scale;
            }
            UiLayoutDrawPart(tl, lbl_802B6A64, 1, &p->x, ui->z, a, 1.0f, p->part);
        }
        z = TextGetZ();
        TextPushColor();
        TextSetColor(0xFF201008);
        fn_801B737C(t);
        TextSetZ(-27.5f + t->obj->o.z);
        TextPopColor(1);
        TextSetZ(z);
        break;
    case 0xFF:
        MenuDummy();
        t->flags |= 0x40;
        break;
    }
}

void fn_801AC678(ShopPart* t) {
    f32 z;
    ShopList* p;
    UiObj* ui;
    NJS_TEXLIST** tl;
    switch (t->state) {
    case 0:
    case 0xFE:
        if (t->flag->b0 == 1) {
            return;
        }
        UiObjUpdate(&t->obj->o);
        tl = &menu_sprites.texlist8;
        UiLayoutDraw(tl, lbl_802B6E48, 4, &t->obj->o.x, t->obj->o.z, 1.0f, 1.0f);
        if (lbl_803471B8->buf->count != 0) {
            p = t->list;
            ui = &t->obj->o;
            if ((p->flags & 1) && p->part != 0xff) {
                f32 a = 0.0f;
                if (p->flags & 2) {
                    p->x = ui->x + p->ox;
                    p->y = ui->y + p->oy;
                    p->scale = 0.3f * njCos(p->angle) + 1.0f;
                    p->angle += 0x800;
                    a = p->scale;
                }
                UiLayoutDrawPart(tl, lbl_802B6A64, 1, &p->x, ui->z, a, 1.0f, p->part);
            }
        }
        if (lbl_803471B8->buf->pages != 0) {
            t->x38->idx = 2;
            t->x38->x = t->obj->o.x;
            t->x38->y = t->obj->o.y;
            fn_801B5D68(t);
        }
        z = TextGetZ();
        TextPushColor();
        fn_801AC87C(t);
        TextSetZ(-27.5f + t->obj->o.z);
        TextPopColor(1);
        TextSetZ(z);
        break;
    case 0xFF:
        MenuDummy();
        t->flags |= 0x40;
        break;
    }
}

void fn_801B6950(ShopPart* t) {
    f32 z;
    NJS_POINT3 pos;
    if (lbl_803475D8 != 0) {
        t->state = 0xFF;
    }
    switch (t->state) {
    case 0:
    case 0xFE:
        if (t->flag->b0 == 1) {
            return;
        }
        UiObjUpdate(&t->obj->o);
        UiLayoutDraw(&menu_sprites.texlist8, lbl_802B6B5C, 4, &t->obj->o.x, t->obj->o.z, 1.0f, 1.0f);
        z = TextGetZ();
        TextSetZ(-4427.5f);
        TextPushColor();
        TextSetColor(0xFF201008);
        TextPrint(20.0f + t->obj->o.x, 10.0f + t->obj->o.y, lbl_802EC04C[9]);
        TextPopColor(1);
        TextSetZ(z);
        pos.x = 182.0f + t->obj->o.x;
        pos.y = 14.0f + t->obj->o.y;
        pos.z = -4432.5f;
        UiDrawNumber(&pos, 0, 8, lbl_8030B7F4.w34c, t->obj->o.alpha);
        break;
    case 0xFF:
        MenuDummy(t);
        t->flags |= 0x40;
        break;
    }
}

void fn_801B0B9C(ShopPart* t) {
    const LayoutDef* e;
    u32 i;
    u32 n;
    s32 mask;
    f32 z;
    switch (t->state) {
    case 0:
    case 0xFE:
        if (t->flag->b0 == 1) {
            return;
        }
        UiObjUpdate(&t->obj->o);
        UiObjCalcRect(&t->obj->o);
        z = TextGetZ();
        TextPushColor();
        TextSetColor(0xFF201008);
        UiLayoutDraw(&menu_sprites.texlist8, lbl_802B79F4, 2, t->obj->o.rect, t->obj->o.z, t->obj->o.alpha, 1.0f);
        mask = fn_801F4CA0();
        i = n = 0;
        e = &lbl_802B7B20[i];
        do {
            if (mask & (1 << i)) {
                MenuPanel* pan = t->obj;
                UiLayoutDraw(&menu_sprites.texlist8, e->parts, e->count, pan->o.rect, pan->o.z,
                             i == t->list->page ? pan->o.alpha : pan->o.alpha - 0.5f, pan->o.f38);
                n++;
            }
            i++;
            e++;
        } while (i < 6);
        if (n == 0) {
            TextPrint(24.0f + (8.0f + t->obj->o.rect[0]), 17.0f + t->obj->o.rect[1], lbl_802EC04C[8]);
        } else if (n >= 2) {
            t->x38->idx = 3;
            t->x38->x = t->obj->o.rect[0] + (f32)(t->list->page * 0x30);
            t->x38->y = t->obj->o.rect[1];
            fn_801B5D68(t);
        }
        UiLayoutDraw(&menu_sprites.texlist8, lbl_802B7B50, 1, &t->obj->o.rect[2], t->obj->o.z, 1.0f, 1.0f);
        TextPopColor(1);
        TextSetZ(z);
        break;
    case 0xFF:
        MenuDummy(t);
        t->flags |= 0x40;
        break;
    }
}

/* A panel's start position, z and alpha (0x18 bytes). */
typedef struct PanelStart {
    f32 x, y;
    f32 f8, fc;
    f32 z;
    f32 alpha;
} PanelStart;
extern const PanelStart lbl_802B690C[];

Sub_801A0C3C *fn_801A53D4(void *o, u16 idx) {
    Sub_801A0C3C *t = fn_802267AC(o, fn_801A54AC);
    t->w = fn_801E1A74(1, 0x58);
    t->obj = fn_801E1A74(1, 0x6c);
    t->w->b0 = 0;
    t->obj->o.alpha_en = 0;
    t->obj->h54 = idx;
    t->obj->o.z = lbl_802B690C[idx].z;
    t->obj->o.tx = t->obj->o.x = lbl_802B690C[idx].x;
    t->obj->o.ty = t->obj->o.y = lbl_802B690C[idx].y;
    t->obj->o.alpha = lbl_802B690C[idx].alpha;
    return t;
}

void fn_8019F898(SaveTask *t) {
    u8 k;
    if (fn_801A6554(t) == 0 || (lbl_80311A60[0]->held & 0x200)) {
        fn_801A64E0(t);
        fn_801A6650(t, 5);
        fn_801A6650(t, 6);
        k = t->w->f1 == 1 ? 0xc : 5;
        fn_801A64B4(t, k);
        t->state = 8;
    }
}

inline s8 fn_801BE608(s16 x) {
    u8 lvl = lbl_803473BE;
    int r;
    if (x == -1) {
        return -1;
    }
    if (lvl >= 0x18) {
        return -1;
    }
    r = 0;
    if (lvl >= ((Ent_801BE608*)lbl_802ED258)[x].lo) {
        r = 2;
    } else if (lvl >= ((Ent_801BE608*)lbl_802ED258)[x].hi) {
        r = 1;
    }
    return r;
}

inline s32 Test_801BD748(u32 b) {
    return ((*(u32(*)[])&lbl_80310B3C)[b >> 5] & (1 << (b & 31))) != 0;
}

s32 fn_801BD748(ShopTask_801BD748* t, ShopEntry_801BD748* tmp, s32 start) {
    int i;
    int j;
    int n;
    for (i = 0; i < 0x58; i++) {
        tmp[i].id = -1;
        tmp[i].flag = -1;
        tmp[i].type = 0;
        tmp[i].val = 0;
    }
    n = i = 0;
    for (; i < 0x58; i++) {
        if ((Test_801BD748(i + 0xc62) & 1) == 0 && Test_801BD748(i + 0xb54) == 1) {
            tmp[n].id = i;
            tmp[n].flag = fn_801BE608(i);
            tmp[n].val = ((Ent_801BE608*)lbl_802ED258)[i].f24;
            n++;
        }
    }
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (tmp[j].val < tmp[i].val) {
                s16 id = tmp[j].id;
                int f = tmp[j].flag;
                s16 v = tmp[j].val;
                tmp[j].val = tmp[i].val;
                tmp[j].flag = tmp[i].flag;
                tmp[j].id = tmp[i].id;
                tmp[i].val = v;
                tmp[i].flag = f;
                tmp[i].id = id;
            }
        }
    }
    for (i = 0; i < n; i++, start++) {
        t->buf->out[start].id = tmp[i].id;
        t->buf->out[start].flag = tmp[i].flag;
        t->buf->out[start].val = tmp[i].val;
    }
    return start;
}

void SaveLoadTask(Task *task) {
    if (lbl_803475D8 != 0) {
        task->state = 0x1F;
    }
    lbl_802EBD30[task->state](task);
}

void fn_8019C424(Task *t)
{
    EvInfo *info;
    EvObj *o;
    Obj_8019CB80_8019C424 *sp;
    f32 dx;
    f32 dz;
    f32 dist;
    f32 r1;
    f32 r2;
    NJS_POINT3 p;
    s32 area;

    o = t->work;
    info = o->ext->info;
    if (lbl_80347450 == 0) {
        return;
    }
    switch (t->state) {
    case 0:
        fn_80227810(o->texlist);
        t->state++;
    case 1:
        dx = lbl_80347450->pos.x - lbl_80347450->home.x;
        dz = lbl_80347450->pos.z - lbl_80347450->home.z;
        dist = fn_80291A5C(dx * dx + dz * dz);
        area = (lbl_80347450->hit->h24 >> 8) & 0x7f;
        if ((((u32)lbl_80347450->hit->h24 >> 8) & 0xff) == 0 || area != info->area) {
            break;
        }
        memcpy(&p, &lbl_80347450->pos, sizeof(NJS_POINT3));
        fn_802254A0(&p, lbl_80347450->hit);
        if (lbl_80347450->pos.y < p.y || lbl_80347450->pos.y > p.y + info->height || !(dist > info->minDist)) {
            break;
        }
        o->x210 = 1;
        if (!(RND() > info->rate)) {
            break;
        }
        sp = fn_80226704(t, fn_8019CB80, 0x5c);
        if (sp == 0) {
            break;
        }
        r1 = info->spread * RND();
        r2 = RND();
        sp->st = &sp->buf;
        sp->st->x4.texlist = o->texlist;
        sp->st->x4.model = fn_801C8930(o->model);
        sp->st->x10 = lbl_80347450->pos.y + info->yOfs;
        sp->st->x18 = 65536.0f * RND();
        sp->st->x1c = 65536.0f * RND();
        sp->st->x20 = 65536.0f * RND();
        sp->st->x24 = info->scale;
        sp->st->x28 = info->scale;
        sp->st->x2c = info->scale;
        sp->st->x50 = info->life;
        sp->st->x48 = info->drag;
        sp->st->x4c = info->gravity;
        sp->st->x3c = info->angVel * RND();
        sp->st->x40 = info->angVel * RND();
        sp->st->x44 = info->angVel * RND();
        if (RND() > 0.5f) {
            sp->st->xc = lbl_80347450->pos.x + dx * r1 + info->side * SIGN(dz);
            sp->st->x14 = lbl_80347450->pos.z + dz * r1 - info->side * SIGN(dx);
            sp->st->x30 = dx + r2 * (dz * info->spin);
            sp->st->x34 = info->rise + dist * info->riseVar * RND();
            sp->st->x38 = dz - r2 * (dx * info->spin);
        } else {
            sp->st->xc = lbl_80347450->pos.x + dx * r1 - info->side * SIGN(dz);
            sp->st->x14 = lbl_80347450->pos.z + dz * r1 + info->side * SIGN(dx);
            sp->st->x30 = dx - r2 * (dz * info->spin);
            sp->st->x34 = info->rise + dist * info->riseVar * RND();
            sp->st->x38 = dz + r2 * (dx * info->spin);
        }
        break;
    case 0xff:
        if (o->texlist != 0) {
            fn_802275A4(o->texlist, 0);
        }
        if (o->x20c != 0) {
            o->x20c = 0;
            fn_80217830(o->x23c);
        }
        fn_80100B74(t);
        return;
    }
    if (info->area == 8) {
        if (o->x210 != 0) {
            o->x210 = 0;
            if (o->x20c == 0) {
                o->x20c = 1;
                o->x23c = SePlay(8, 5, 8);
            }
        } else if (o->x20c != 0) {
            o->x20c = 0;
            fn_80217830(o->x23c);
        }
    }
}
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

/* Scans a memory card's save files (the task fn_801A343C starts), filling the save menu's
 * slot summaries. */
void fn_801A2D60(Task_801A343C* t) {
    s32 code;
    s32 flag;
    s32 files;
    s32 bytes;
    char num[8];
    CARDFileInfo info;
    CardSaveData* save;
    SaveTask* par;
    s32* st;
    s32 chan;
    s32 n;

    chan = t->p24->w10;
    par = t->parent;
    st = &par->w->st[chan];
    if (t->state > 0xfe && lbl_80347184[chan] == 0) {
        *st = 1;
        t->state = 4;
    }
    switch (t->state) {
    case 0:
    case 0xfe:
        lbl_803475D0 = 1;
        t->p24->b14 = 0;
        if (fn_801A2500(t->p24->w10, &code) == 0) {
            *st = fn_801A6A04(code);
            t->p24->w08 = 0;
            t->state = 4;
            break;
        }
        t->p24->w0c = 0;
        par->w->w14 = 0;
        {
            s32 c = t->p24->w10;
            s32 r;
            do {
                r = CARDFreeBlocks(c, &bytes, &files);
            } while (r == -1);
            if (r == 0) {
                if (files <= 0) {
                    n = 0;
                } else {
                    n = bytes / 0x6000;
                    if (n > 7) {
                        n = 7;
                    }
                }
            } else {
                n = 0;
            }
        }
        t->p24->w08 = n;
        *st = 0;
        t->state = 1;
        break;
    case 1:
        sprintf(num, lbl_8034B6A0, t->p24->b14);
        strcpy(lbl_80308178, lbl_802B4978);
        strcat(lbl_80308178, num);
        code = fn_801A388C(t->p24->w10, lbl_80308178, &flag);
        if (code == 0) {
            if (flag != 0) {
                par->w->ent[t->p24->b14].f0 = 2;
                t->p24->w0c++;
                goto next;
            }
            t->p24->w0c++;
            t->state = 2;
            break;
        }
        if (code == -4) {
            if (t->p24->w08 > 0) {
                par->w->ent[t->p24->b14].f0 = 0;
                t->p24->w0c++;
                t->p24->w08--;
            } else {
                par->w->ent[t->p24->b14].f0 = 3;
            }
        next:
            t->p24->b14++;
            t->p24->h16++;
            if (t->p24->b14 >= t->p24->b15) {
                t->p24->b1a = 0;
                t->p24->b1b = 0;
                t->state = 4;
            }
            break;
        }
        *st = fn_801A6A04(code);
        t->state = 4;
        break;
    case 2:
        t->p24->w04 = 3;
        par->w->ent[t->p24->b14].f0 = 1;
        t->buf = fn_801E1C7C(0x6000);
        do {
            code = CARDOpen(t->p24->w10, lbl_80308178, &info);
        } while (code == -1);
        if (code == 0) {
            do {
                code = CARDRead(&info, t->buf, t->p24->w04 << 13, 0);
            } while (code == -1);
            CARDClose(&info);
        }
        if (code != 0) {
            t->p24->w0c = 0;
            par->w->w14 = 0;
            t->state = 4;
            *st = 1;
            break;
        }
        t->state = 3;
        break;
    case 3:
        save = &t->buf->save;
        if (save->sum != CardSum(save)) {
            par->w->ent[t->p24->b14].f0 = 2;
        } else if (strcmp(save->magic, lbl_802EBDD0) != 0) {
            par->w->ent[t->p24->b14].f0 = 4;
        } else {
            par->w->ent[t->p24->b14].f0 = 1;
            par->w->ent[t->p24->b14].h4 = save->x31ea;
            par->w->ent[t->p24->b14].h6 = save->x31e8;
            par->w->ent[t->p24->b14].w8 = save->x31ec;
            par->w->ent[t->p24->b14].hc = save->b1b;
            par->w->ent[t->p24->b14].be = save->b338;
            par->w->ent[t->p24->b14].bf = save->b339;
            par->w->ent[t->p24->b14].b10 = save->b33a;
            par->w->ent[t->p24->b14].b11 = save->b33b;
            memcpy(&par->w->ent[t->p24->b14].stamp, save->stamp, 8);
        }
        fn_801E17E0(t->buf);
        t->buf = NULL;
        t->state = 1;
        goto next;
    case 4:
        CardRelease(t->p24->w10);
        par->w->w14 = t->p24->w0c;
        par->w->w250 = 1;
        lbl_803475D0 = 0;
    case 0xff:
        if (t->buf != NULL) {
            fn_801E17E0(t->buf);
            t->buf = NULL;
        }
        t->flags |= 0x40;
        return;
    }
    par->w->f1c = (f32)t->p24->h16 / (f32)t->p24->h18;
}

