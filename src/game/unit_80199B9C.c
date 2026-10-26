#include "types.h"
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
#include <math.h>
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
extern void fn_801A4B40(void);
extern u8 *fn_80226670(u8 *obj, void (*cb)(void));
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
extern u8 *lbl_80311A60[];
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
    UiObj *ui;
} Task_801A66AC;
extern f32 fn_801DBD9C(f32 z);
extern void fn_80290ED4(VertexCol *v, s32 count, s32 flag);
void fn_801A66AC(Task_801A66AC *t);
extern void *fn_801A4DCC(void *a, u16 flag);
extern void fn_801CBBAC(f32 f);
extern void Ui2DBegin(void);
extern void *lbl_8034718C[2];
extern u32 lbl_80347184[2];
extern s32 CARDUnmount(s32 slot);
extern s32 fn_8025CB24(char *, const char *, ...);
extern void fn_8025F120(void *, const char *);
extern void fn_8025F0B0(void *, const char *);
extern char lbl_802B69C0[];
extern void *fn_801CC3C4(const char *path);
extern s16 fn_800ED8C4(void *p);
extern u8 lbl_8030B4D4[];
extern void fn_801ABA30(void);
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
    UiObj *ui;
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
typedef struct Work_801A6650 {
    u8 pad[0x20c];
    Task *slots[16];
} Work_801A6650;
typedef struct Task_801A6650 {
    u8 pad[0x24];
    Work_801A6650 *work;
} Task_801A6650;
extern void fn_801A6650(Task_801A6650 *t, u16 i);
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
    UiObj *ui;
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
extern void fn_801A2D60(void);
typedef struct Task_801A343C {
    u8 pad00[0x24];
    void* p24;
} Task_801A343C;
typedef struct Rec24 {
    u8 pad00[0xC];
    s32 w0c;
    s32 w10;
    u8 pad14;
    u8 b15;
    s16 h16;
    s16 h18;
} Rec24;
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
extern s32 fn_801A388C(s32 chan, s32 a, s32* out);
#define R24(p) ((Rec24 *)((Task_801A343C *)(p))->p24)
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
typedef struct PanelUi_801A5274 {
    UiObj ui;
    const char *label;
} PanelUi_801A5274;
typedef struct Task_801A5274 {
    u8 pad0[0x18];
    u8 flags;
    u8 state;
    u8 pad1a[0xa];
    u8 *flag;
    PanelUi_801A5274 *pan;
} Task_801A5274;
extern LayoutPart lbl_802B4A00[2];
void fn_801A5274(Task_801A5274 *t);
typedef struct MenuUi {
    f32 z;
    f32 x, y;
    f32 tx, ty;
    f32 vx, vy;
    f32 rdx, rdy;
    f32 rect[4];
    f32 alpha;
    f32 f38, f3c;
    u8 alpha_en;
    u8 raised;
    u16 frames;
    u16 delay;
    u16 cmd;
    s16 se;
    u16 pad4A;
    u32 w4c;
    s16 h50;
    s16 h52;
    s16 h54;
    s16 h56;
    u8 pad58[0x14];
} MenuUi;
typedef struct Task_801A51A8 {
    u8 pad00[0x24];
    u8* p24;
    MenuUi* p28;
    u32 w2c;
} Task_801A51A8;
/* A title panel: a UiObj and the index of the label to print on it. */
typedef struct Panel_801ABD40 {
    UiObj ui;
    u8 pad4C[0x56 - 0x4C];
    u16 label; /* 0x56 */
} Panel_801ABD40;
typedef struct PanelTask_801ABD40 {
    u8 pad0[0x18];
    u8 flags;   /* 0x18 */
    u8 state;   /* 0x19 */
    u8 pad1A[0x24 - 0x1A];
    u8* flag;   /* 0x24 */
    Panel_801ABD40* pan; /* 0x28 */
} PanelTask_801ABD40;
extern const char* lbl_80346810[2];
void fn_801ABD40(PanelTask_801ABD40* t);
typedef struct Task_801ABE90 {
    u8 pad00[0x24];
    u8* p24;
    MenuUi* p28;
    u32 w2c;
} Task_801ABE90;
extern void fn_801ABF70();
typedef struct Task_801AC094 {
    u8 pad00[0x24];
    u8* p24;
    MenuUi* p28;
    u32 w2c;
} Task_801AC094;
extern void fn_801B6BB4(void *ui, f32 *pos, s16 a, s32 b, s32 c, s32 d, f32 e);
extern u8 lbl_802B7720[0x50];
typedef struct Cfg_801B0F1C { u8 pad[6]; u16 h6; u8 pad8; u8 b9; } Cfg_801B0F1C;
typedef struct Gl_801B0F1C { u8 pad[0x24]; Cfg_801B0F1C *cfg; } Gl_801B0F1C;
typedef struct Pan_801B0F1C { UiObj ui; const char *label; } Pan_801B0F1C;
typedef struct Task_801B0F1C {
    u8 pad00[0x18];
    u8 flags;     /* 0x18 */
    u8 state;     /* 0x19 */
    u8 pad1a[0x24 - 0x1a];
    u8 *flag;     /* 0x24 */
    Pan_801B0F1C *pan;  /* 0x28 */
} Task_801B0F1C;
void fn_801B0F1C(Task_801B0F1C *t);
extern s32 fn_801F4AE4(s16 v);
typedef struct Task_801B1104 {
    u8 pad00[0x24];
    u8* p24;
    MenuUi* p28;
    u32 w2c;
} Task_801B1104;
typedef struct Sub_801B1104 {
    u8 pad00[6];
    u16 h06;
} Sub_801B1104;
typedef struct Pl {
    u32 w00;
    u8 pad04[0x140];
    u32 w144;
    u8 pad148[0x140];
    u32 w288;
    u8 pad28C[0x140];
    u32 w3cc;
    u8 pad3D0[0x140];
    u32 w510;
} Pl;
typedef struct {
    u8 pad0[4];
    s16* g[5][81]; /* 0x04 */
} Tables;
typedef struct Game_UNIT {
    u8 pad00[0x24];
    Sub_801B1104* p24;
    u8 pad28[0x8];
    union { Pl* p30; Tables* t; };
} Game_UNIT;
extern Game_UNIT* lbl_803471B8;
extern void fn_801B11EC(void);
typedef struct Task_801B1A78 {
    u8 pad00[0x24];
    u8* p24;
    MenuUi* p28;
    u32 w2c;
} Task_801B1A78;
extern void fn_801B5EA8();
typedef struct Task_801B6240 {
    u8 pad00[0x24];
    u8* p24;
    MenuUi* p28;
    u32 w2c;
} Task_801B6240;
extern void fn_801B6950(void);
typedef struct Task_801B6AE8 {
    u8 pad00[0x24];
    u8* p24;
    MenuUi* p28;
    u32 w2c;
} Task_801B6AE8;
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
typedef struct Flags_UNIT0000 {
    u8 pad00[8];
    u32 w08;
} Flags_UNIT0000;
typedef struct Stat {
    u8 pad00[0x34C];
    s32 w34c;
    u8 pad350[0x16A0 - 0x350];
} Stat;
extern Stat lbl_8030B7F4;
extern void* lbl_803470EC;
extern void* lbl_803470F4;
typedef struct St {
    u8 pad00[4];
    u8 x4[8];
    f32 xc, x10, x14;
    s32 x18, x1c, x20;
    u8 pad24[0x30 - 0x24];
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
typedef struct Sub28 { u8 pad[0x28]; UiObj* obj; } Sub28;
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
typedef struct Flg { u8 pad[8]; u32 flags; } Flg;
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
    u8 fileName[0x20];
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
extern u32 fn_8025ED74(CardStat* stat, s32 a);
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
extern u8 lbl_802EBDD0[0x10];
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
extern void fn_801DBA70(const char* file, s32 line, const char* msg, ...);
typedef struct Named {
    UiObj o;
    const char* name; /* 0x4c */
} Named;
typedef struct Node {
    u8 pad00[0x24];
    u8* a;       /* 0x24 */
    Named* b;    /* 0x28 */
} Node;
extern const char lbl_80346808[4];
extern const char lbl_8034680C[3];
typedef struct Panel_801A5D08 {
    UiObj ui;
    const char *label;
} Panel_801A5D08;
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
    Panel_801A5D08 *pan;
} Task_801A5D08;
extern LayoutPart lbl_802B4B88[1];
extern LayoutPart lbl_802B4B4C[3];
void fn_801A5D08(Task_801A5D08 *t);
typedef struct {
    UiObj ui;
    const char* label; /* 0x4C */
    u8 pad50[4];
    s16 slot;          /* 0x54 */
} SlotPanel;
typedef struct {
    u8 pad[0x24];
    u8* buf;        /* 0x24 */
    SlotPanel* pan; /* 0x28 */
} SlotTask;
extern void* fn_801E1A74(s32 n, s32 size);
extern void fn_801A5FD8(void);
typedef struct Panel_801A6344 {
    UiObj ui;
    const char *label;
} Panel_801A6344;
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
    Panel_801A6344 *pan;
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
    UiObj* ui;  /* 0x28 */
} PanelTask_801ABF70;
extern LayoutPart lbl_802B7C14[4];
s32 UiLayoutDraw(NJS_TEXLIST** texlists, LayoutPart* parts, u32 count, f32* pos, f32 z, f32 a, f32 b);
void fn_801C3F5C(f32 x, f32 y, f32 z);
typedef struct {
    UiObj ui;
    const char* label; /* 0x4C */
    u8 pad50[4];
    s16 slot;          /* 0x54 */
} Panel_801ACC00;
typedef struct {
    u8 pad0[8];
    u32 slot; /* 0x08 */
} BufA_801ACC00;
typedef struct {
    u8 pad0[0x18];
    s16 s18;
    s16 s1A;
    u8 pad1C[2];
    u8 b1E;
    u8 b1F;
} BufC_801ACC00;
typedef struct {
    u8 pad[0x24];
    BufA_801ACC00* a;     /* 0x24 */
    Panel_801ACC00* pan;  /* 0x28 */
    s32 f2C;
    BufC_801ACC00* c;     /* 0x30 */
    u8 pad34[4];
    void* d;     /* 0x38 */
} Task3_801ACC00;
extern void fn_801AC48C(void);
typedef struct PanelTask_801AFAA4 PanelTask_801AFAA4;
typedef struct {
    LayoutPart* parts;
    u32 count;
} LayoutDef;
typedef struct {
    u8 flag;       /* 0x00 */
    u8 pad1[0x48 - 1];
    void (*cb)(PanelTask_801AFAA4*); /* 0x48 */
} PanelData_801AFAA4;
typedef struct {
    UiObj ui;
    u8 pad4C[8];
    u16 layout; /* 0x54 */
} Panel_801AFAA4;
struct PanelTask_801AFAA4 {
    u8 pad0[0x18];
    u8 flags;
    u8 state;
    u8 pad1A[0x24 - 0x1A];
    PanelData_801AFAA4* data;
    Panel_801AFAA4* pan;
};
extern LayoutDef lbl_802B79E4[];
extern LayoutPart lbl_802B77AC[1];
typedef struct {
    UiObj ui;
    u32 f4C;       /* 0x4C */
    u16 pad50;
    u16 f52;       /* 0x52 */
    u16 layout;    /* 0x54 */
} Panel_801B0470;
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
    Panel_801B0470* pan;      /* 0x28 */
    s32 f2C;
} Task2_801B0470;
extern void fn_801B02F4(void);
extern u32 lbl_802EBF60[7];
typedef struct {
    UiObj ui;
    u32 f4C;
    u16 f50;
    u16 f52;
    u16 f54;
    u16 f56;
} Panel_801B0DF8;
typedef struct {
    u8 b0;
    u8 pad1[7];
    s16 s8;
    s16 sA;
} BufA_801B0DF8;
typedef struct {
    u8 pad0[0x18];
    s16 s18;
    s16 s1A;
    u8 pad1C[2];
    u8 b1E;
    u8 b1F;
} BufC_801B0DF8;
typedef struct {
    u8 pad[0x24];
    void* a;     /* 0x24 */
    Panel_801B0DF8* pan;  /* 0x28 */
    s32 f2C;
    BufC_801B0DF8* c;     /* 0x30 */
    u8 pad34[4];
    BufA_801B0DF8* d;     /* 0x38 */
} Task3_801B0DF8;
extern void fn_801B0B9C(void);
typedef struct {
    UiObj ui;
    u32 f4C;
    u16 f50;
    u16 f52;
    u16 f54;
    u16 f56;
} Panel_801B2310;
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
    Panel_801B2310* pan;  /* 0x28 */
    s32 f2C;
    BufC_801B2310* c;     /* 0x30 */
    u8 pad34[4];
    BufD* d;     /* 0x38 */
} Task3_801B2310;
extern void fn_801B1B3C(void);
typedef struct {
    UiObj ui;
    u32 f4C;
    u16 f50;
    u16 f52;
    u16 f54;
    u16 f56;
} Panel_801B2678;
typedef struct {
    u8 pad[0x24];
    u8* a;       /* 0x24 */
    Panel_801B2678* pan;  /* 0x28 */
    s32 f2C;
} Task2_801B2678;
extern void UiDrawNumber(NJS_POINT3 *pos, u32 flags, u16 ndigits, u32 value, f32 c1);
extern u8 lbl_802B6DF8[0x50];
typedef struct Cfg_801B2430 { u8 pad[0x11c]; u32 w11c; u32 w120; } Cfg_801B2430;
typedef struct Gl_801B2430 { u8 pad[0x24]; Cfg_801B2430 *cfg; } Gl_801B2430;
typedef struct Pan_801B2430 { UiObj ui; const char *label; } Pan_801B2430;
typedef struct Task_801B2430 {
    u8 pad00[0x18];
    u8 flags;     /* 0x18 */
    u8 state;     /* 0x19 */
    u8 pad1a[0x24 - 0x1a];
    u8 *flag;     /* 0x24 */
    Pan_801B2430 *pan;  /* 0x28 */
} Task_801B2430;
void fn_801B2430(Task_801B2430 *t);
extern u32 lbl_802EC04C[13];
typedef struct {
    UiObj ui;
} Panel_801B5C4C;
typedef struct {
    u8 pad0[0x1E];
    u8 b1E;
    u8 b1F;
} BufC_801B5C4C;
typedef struct {
    u8 pad[0x24];
    u8* a;       /* 0x24 */
    Panel_801B5C4C* pan;  /* 0x28 */
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
    LayoutPart* parts; /* 0x00 */
    u16 pad4;
    u16 flag6;         /* 0x06 */
    u32 pad8, padC;
} AnimDef;
typedef struct {
    u8 pad0[8];
    u16 idx;    /* 0x08 */
    u16 state;  /* 0x0A */
    u16 angle;  /* 0x0C */
    u16 padE;
    s32 f10;
    f32 scale;  /* 0x14 */
} AnimData;
typedef struct {
    u8 pad[0x28];
    UiObj* ui;       /* 0x28 */
    u8 pad2C[0xC];
    AnimData* d;     /* 0x38 */
} Task3_801B5D68;
extern AnimDef lbl_802B73A4[];
f32 njSin(u16 a);
typedef struct PanelTask_801B5EA8 {
    u8 pad0[0x18];
    u8 flags;   /* 0x18 */
    u8 state;   /* 0x19 */
    u8 pad1A[0x24 - 0x1A];
    u8* flag;   /* 0x24 */
    UiObj* ui;  /* 0x28 */
} PanelTask_801B5EA8;
extern LayoutPart lbl_802B6DD0[2];
void fn_801B6E5C(PanelTask_801B5EA8* t);
typedef struct {
    UiObj ui;
    const char* label; /* 0x4C */
} Panel_801B5FA8;
typedef struct PanelTask_801B5FA8 {
    u8 pad0[0x18];
    u8 flags;   /* 0x18 */
    u8 state;   /* 0x19 */
    u8 pad1A[0x24 - 0x1A];
    u8* flag;   /* 0x24 */
    Panel_801B5FA8* pan; /* 0x28 */
} PanelTask_801B5FA8;
typedef struct {
    UiObj ui;
    const char* label; /* 0x4C */
} Panel_801B66F8;
typedef struct PanelTask_801B66F8 {
    u8 pad0[0x18];
    u8 flags;   /* 0x18 */
    u8 state;   /* 0x19 */
    u8 pad1A[0x24 - 0x1A];
    u8* flag;   /* 0x24 */
    Panel_801B66F8* pan; /* 0x28 */
} PanelTask_801B66F8;
extern LayoutPart lbl_802B6B0C[4];
extern s32 lbl_803475D8;
void MenuDummy();
typedef struct {
    UiObj ui;
    const char* label; /* 0x4C */
} Panel_801B6838;
typedef struct {
    u8 pad[0x24];
    u8* a;       /* 0x24 */
    Panel_801B6838* pan;  /* 0x28 */
} Task2_801B6838;
typedef struct {
    u32 x0;
    const char* label; /* 0x04 */
    u8 pad[0x68 - 8];
} Entry68;
typedef struct {
    const char* label;
    u32 pad[3];
} Entry10;
extern void fn_801B66F8();
extern Entry68 lbl_802EC0A0[];
extern Entry10 lbl_802ED218[4];
extern u8 lbl_803473BF;
extern u16 lbl_803473BC;
extern const char* lbl_802EBF7C[16];
extern u32 lbl_802EBFBC[8];
extern char lbl_802B8F94[];
extern char lbl_802B8F70[];
typedef struct {
    u8 pad0[0x18];
    u16 a;      /* 0x18 */
    u16 c;      /* 0x1A */
    u16 kind;   /* 0x1C */
} Sel;
typedef struct {
    u8 pad0[0x30];
    Sel* sel;   /* 0x30 */
} Inner;
typedef struct {
    u8 pad[0x24];
    struct {
        u8 pad[0x218];
        struct {
            u8 pad[0x30];
            Sel* s;
        }* in;
    }* o;
} TaskSel;
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
    UiObj *ui;
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
    UiObj *ui;
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
    UiObj *ui;
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
    UiObj *ui;
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
typedef struct Panel_801A54AC {
    UiObj ui;
    const char *label;
    u8 pad50[4];
    u16 slot;
} Panel_801A54AC;
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
    Panel_801A54AC *pan;
} Task_801A54AC;
extern LayoutPart lbl_802B4B9C[6];
s32 UiLayoutDraw(NJS_TEXLIST **texlists, LayoutPart *parts, u32 count, f32 *pos, f32 z, f32 a, f32 b);
extern void fn_801A5600(void *t);
#define TextPrintNumber TextPrintNumber_hdr
#undef TextPrintNumber
typedef struct Holder_801A6A88 {
    u8 pad0[0x28];
    UiObj *ui;
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
typedef struct Row_801AB580 {
    u8 pad0[8];
    s16 e[0x30];
} Row_801AB580;
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
typedef struct Game_801AB580 {
    u8 pad0[0x34c];
    s32 w34c;
} Game_801AB580;
extern s16 fn_801F4C24(s16 id);
extern u16 fn_801F477C(s16 id);
extern s8 fn_801F452C(s16 id);
typedef struct Game_801AB82C {
    u8 pad0[0x34c];
    u32 w34c;
} Game_801AB82C;
#define MenuDummy MenuDummy_hdr
#undef MenuDummy
typedef struct { UiObj o; const char* text; u16 h50, h52, h54, h56; } MObj;
typedef struct { u8 pad[0x28]; MObj* obj; } MP;
typedef struct { u8 pad[0x28]; MObj* obj; MObj* obj2; } MP2;
typedef struct { void* parts; u32 count; } LT;
typedef struct { u8 pad[0x10]; u32 v; } W;
void fn_801B277C(Task* t);
typedef struct { u8 b0; u8 pad1[3]; s16 h4; u8 pad6[2]; s32 w8; s32 wc; s32 w10; } W_801B54D4;
typedef struct { u8 pad[0x24]; W_801B54D4* w; MObj* obj; MObj* obj2; u8 pad30[0xC]; void* p3c; } T_801B54D4;
typedef struct { f32 a, b; } FP;
extern s32 UiLayoutDrawPart(NJS_TEXLIST** texlists, void* parts, s32 count, f32* pos, u16 index, f32 z, f32 a, f32 b);
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
typedef struct Flag_801AB328 { u8 b0; u8 pad1[7]; s32 w8; u8 pad0c[0x1e - 0xc]; u8 b1e; } Flag_801AB328;
typedef struct Sub_801AB328 {
    u8 pad00[0x24];
    Flag_801AB328 *flag;   /* 0x24 */
    UiObj *obj;            /* 0x28 */
    u8 pad2c[4];
    Flag_801AB328 *flag30; /* 0x30 */
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
typedef struct Sub_801A0FD8 { u8 pad[0x19]; u8 x19; u8 pad1a[0x28 - 0x1a]; UiObj *obj; } Sub_801A0FD8;
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
typedef struct { u8 pad[0x24]; struct { u8 pad[6]; u16 idx; } *p; } G;
typedef struct { void* a; void* b; void* c; u8 pad[0x1C]; } Ent_801AC2E4;
extern Ent_801AC2E4 lbl_802ED258[];
extern s8 fn_801BE608(s16 x);
void fn_801AC16C(Task* task);
typedef struct { u8 pad[0x24]; u8* w; MObj* obj; u32 x2c; } T;
typedef struct Flg_801A0C3C { u8 pad[8]; u32 flags; } Flg_801A0C3C;
typedef struct Sub_801A0C3C { u8 pad[0x28]; UiObj *obj; } Sub_801A0C3C;
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
extern void fn_801A1B98(void *o, s32 k);
/* Memory-card state reset. lbl_80347170 is a 2-entry per-slot table (fn_801A28F4 fills
 * both entries), lbl_80347178 a slot bit mask. The original stores entry 0 twice; the
 * store to lbl_80347178 has to come first in the source for the scheduler to keep 1 in r0
 * and 0 in r3. (Equivalent match: `for (i = 0; i < 2; i++) lbl_80347170[0] = 1;` after the
 * mask store, i.e. a slot loop that forgot its index.) */
extern int lbl_80347170[2];
extern int lbl_80347178;
extern const u32 lbl_8034BAC0[];
extern u8 lbl_803473BE;
typedef struct { u8 pad[0x28]; UiObj* obj; } Pnl;
typedef struct { s32 f0; u8 pad[0x28]; } E2c;
typedef struct {
    u8 pad0[7];
    u8 f7;
    u8 pad8;
    u8 f9;
    u8 padA[2];
    s32 fc;
    u8 pad10[0x20 - 0x10];
    E2c ent[10];
    u8 pad_[0x20c - 0x20 - 10 * 0x2c];
    Pnl* p[19];
    void* f258;
} W_8019EFF8;
typedef struct { u8 pad[0x19]; u8 state; u8 pad1a[0x24 - 0x1a]; W_8019EFF8* w; } Task_8019EFF8;
extern s32 fn_801A3B30(Task_8019EFF8* t, s32* out);
extern s32 MenuPlaySe(s16 se);
typedef struct {
    u8 pad0[1];
    u8 f1;
    u8 cnt;
    u8 f3;
    u8 sel;
    u8 pad5[0x18 - 5];
    f32 f18;
    u8 pad1c[0x20c - 0x1c];
    Pnl* p[19];
    s32 pad258;
    s32 st[8];
} W_801A11B0;
typedef struct { u8 pad[0x19]; u8 state; u8 pad1a[0x24 - 0x1a]; W_801A11B0* w; } Task_801A11B0;
typedef struct { u8 pad[0x14]; u32 f14; u8 pad18[0x50 - 0x18]; } Tab;
typedef struct { u8 pad[8]; u32 bits; } Pad;
typedef struct { Pad* pad; } PadInfo;
extern s32 fn_801C09F8(s32 a, s32 b);
extern void fn_801A20AC(Task_801A11B0* t);
typedef struct V { u8 pad[4]; f32 a; f32 b; } V;
typedef struct Ent_801B737C { u8 pad[0x28]; V* v; } Ent_801B737C;
typedef struct St_801B737C { u8 pad[0x64]; s8 seen[8]; } St_801B737C;
typedef struct Fl { u8 pad[4]; u32 f4; u8 pad8[0x18 - 8]; u32 f18; u32 f1c; u8 pad20[0x30 - 0x20]; u32 f30; u8 pad34[0x168 - 0x34]; u32 f168; u8 pad16c[4]; u32 f170; } Fl;
typedef struct UiObj UiObj;
typedef struct Slot { u8 pad[0x28]; UiObj* obj; } Slot;
extern void UiObjSetCommand(UiObj* obj, u16 cmd, u16 delay);
typedef struct Menu { u8 pad[0xA]; u8 cur; u8 pad2[0x230-0xB]; Slot* slot[5]; } Menu;
typedef struct Task_801AB094 { u8 pad[0x24]; Menu* m; } Task_801AB094;
typedef struct Holder_801A0E7C {
    u8 pad0[0x28];
    UiObj *ui;
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
/* Save time stamp. */
typedef struct SaveStamp {
    u16 year;
    u8 month, day, hour, min, sec, wday;
} SaveStamp;
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
typedef struct SaveData {
    u8 pad0[0x31f2];
    u8 stamp[10];
    u32 sum;
} SaveData;
extern CardStampBuf lbl_80308198;
extern CardRec lbl_803081A4;
extern void *memcpy(void *, const void *, u32);
extern void *memset(void *, s32, u32);
typedef struct Item_801AAFAC {
    u8 pad0[0x34];
    f32 alpha;
} Item_801AAFAC;
typedef struct Holder_801AAFAC {
    u8 pad0[0x28];
    Item_801AAFAC *ui;
} Holder_801AAFAC;
typedef struct Ctx_801AAFAC {
    u8 pad0[6];
    u16 id;
    u8 pad8;
    u8 b9;
    u8 padA;
    u8 count;
    u8 padC[4];
    s8 slot[0x220];
    Holder_801AAFAC *items[16];
} Ctx_801AAFAC;
typedef struct Self_801AAFAC {
    u8 pad0[0x24];
    Ctx_801AAFAC *ctx;
} Self_801AAFAC;
extern s32 fn_801C0B88(s16 id, u8 slot);
typedef struct MenuPanel {
    UiObj o;
    const char* text; /* 0x4C */
    u16 h50, h52, h54, h56;
} MenuPanel;
typedef struct PanelWork_801AFBE8 {
    u8 state;
    u8 pad1[0x47];
    void (*cb_801AFBE8)(void *t); /* 0x48 */
} PanelWork_801AFBE8;
typedef struct PanelTask_801AFBE8 {
    u8 pad[0x24];
    PanelWork_801AFBE8* w;   /* 0x24 */
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

extern void fn_801AC678(void);
Task3_801ACC00* fn_801ACD38(void* arg, u16 slot) {
    Task3_801ACC00* t = fn_802267AC(arg, fn_801AC678);
    t->a = fn_801E1A74(1, 0x58);
    t->pan = fn_801E1A74(1, 0x6c);
    t->c = fn_801E1A74(1, 0x20);
    t->d = fn_801E1A74(1, 0x18);
    t->f2C = 0;
    t->a->slot = slot;
    t->c->b1E = 4;
    t->c->b1F = 3;
    t->c->s18 = 0;
    t->c->s1A = 0;
    t->pan->ui.alpha_en = 0;
    ((u8*)t->a)[0] = 0;
    t->pan->ui.x = 648.0f;
    t->pan->ui.tx = 648.0f;
    t->pan->ui.y = 38.0f;
    t->pan->ui.ty = 38.0f;
    t->pan->ui.rdx = 0.0f;
    t->pan->ui.rdy = 0.0f;
    *(f32*)((u8*)t->pan + 0x38) = 1.0f;
    t->pan->ui.alpha = 1.0f;
    t->pan->ui.z = -4500.0f;
    UiObjSetLowered(&t->pan->ui);
    return t;
}

void fn_801B6400(u32 v) {
    u8* p = *(u8**)((u8*)lbl_803471B8 + 0x24);
    u8* q = *(u8**)(p + 0x214);
    if (q == 0) {
        return;
    }
    *(u32*)(*(u8**)(q + 0x28) + 0x4C) = v;
}

u32 fn_801B94F0(void)
{
    u8 *p = *(u8 **)((u8 *)lbl_803471B8 + 0x30);
    u32 sum = *(u32 *)(p + 0x3cc);
    sum += *(u32 *)(p + 0x0);
    sum += *(u32 *)(p + 0x144);
    sum += *(u32 *)(p + 0x288);
    sum += *(u32 *)(p + 0x510);
    return sum != 0;
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
    } else if (*(u32 *)(lbl_80311A60[0] + 0x8) & 0x200) {
        fn_801A64E0(t);
        t->state = 0x1E;
    }
}

void fn_8019E5F0(Task *t) {
    fn_801A66AC(*(void **)((u8 *)t->work + 0x20C));
    if (*(u32 *)(lbl_80311A60[0] + 0x8) & 0x300) {
        fn_801A4DCC(t, 1);
        t->state = 0xC;
    }
}

void fn_8019EDEC(Task *t) {
    if (fn_801A6554(t) == 0 || (*(u32 *)(lbl_80311A60[0] + 0x8) & 0x200)) {
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

    fn_8025CB24(buf, ".%03d", id);
    fn_8025F120(obj, "SA_LEGENDS");
    fn_8025F0B0(obj, buf);
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
    if (fn_801A6554(o) == 0 || (*(u32 *)(lbl_80311A60[0] + 8) & 0x100)) {
        s32 cmd;
        fn_801A64E0(o);
        cmd = 0x14;
        if (o->ctx->b8 == 0) {
            cmd = 0x15;
        }
        UiObjSetCommand(o->ctx->p220->ui, (u16)cmd, 0);
        cmd = 0x14;
        if (o->ctx->b8 == 1) {
            cmd = 0x15;
        }
        UiObjSetCommand(o->ctx->p224->ui, (u16)cmd, 0);
        o->state19 = 0xf;
    }
}

void fn_8019FE64(Self_8019FE64 *o) {
    s32 doit = 0;
    s32 i;

    if (fn_801A6554(o) == 0) {
        doit = 1;
    } else if (*(u32 *)(lbl_80311A60[0] + 8) & 0x100) {
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
        UiObjMoveToX(o->ctx->p21c->ui, 6, 5, -8.0f);
        UiObjSetCommand(o->ctx->p21c->ui, 0xf, 0);
    } else {
        UiObjMoveToX(o->ctx->p218->ui, 6, 5, -8.0f);
        UiObjSetCommand(o->ctx->p218->ui, 0xf, 3);
        UiObjMoveToY(o->ctx->p21c->ui, 3, -1, 164.0f);
        UiObjSetCommand(o->ctx->p21c->ui, 0xf, 0);
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
    *(s32*)((u8*)o + 0x28) = 0;
    R24(o)->w10 = A24(a)->b04;
    R24(o)->b15 = 7;
    A24(a)->h12 = 7;
    R24(o)->w0c = 0;
    A24(a)->w14 = 0;
    A24(a)->w250 = 0;
    R24(o)->h16 = 0;
    if (A24(a)->b01 == 0) {
        R24(o)->h18 = R24(o)->b15 + 1;
    } else {
        R24(o)->h18 = R24(o)->b15 + 3;
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
    o->p28->alpha_en = 0;
    o->p28->z = -4000.0f;
    o->p28->x = 640.0f;
    o->p28->tx = 640.0f;
    o->p28->y = 480.0f;
    o->p28->ty = 480.0f;
    o->p28->rdx = 0.0f;
    o->p28->rdy = 0.0f;
    o->p28->alpha = 1.0f;
    o->p28->w4c = 0;
    return o;
}

Task_801ABE90* fn_801ABE90(void* a)
{
    Task_801ABE90* o = fn_802267AC(a, fn_801ABD40);
    o->p24 = fn_801E1A74(1, 0x58);
    o->p28 = fn_801E1A74(1, 0x6c);
    o->p28->alpha_en = 0;
    o->p24[0] = 0;
    o->p28->x = -260.0f;
    o->p28->tx = -260.0f;
    o->p28->y = 324.0f;
    o->p28->ty = 324.0f;
    o->p28->rdx = 0.0f;
    o->p28->rdy = 0.0f;
    o->p28->f38 = 1.0f;
    o->p28->alpha = 1.0f;
    o->p28->z = -4250.0f;
    o->w2c = 0;
    UiObjSetLowered((UiObj*)o->p28);
    UiObjCalcRect((UiObj*)o->p28);
    return o;
}

Task_801AC094* fn_801AC094(void* a)
{
    Task_801AC094* o = fn_802267AC(a, fn_801ABF70);
    o->p24 = fn_801E1A74(1, 0x58);
    o->p28 = fn_801E1A74(1, 0x6c);
    o->p28->alpha_en = 0;
    o->p24[0] = 0;
    o->p28->x = 640.0f;
    o->p28->tx = 640.0f;
    o->p28->y = 84.0f;
    o->p28->ty = 84.0f;
    o->p28->rdx = 0.0f;
    o->p28->rdy = 0.0f;
    o->p28->f38 = 1.0f;
    o->p28->alpha = 1.0f;
    o->p28->z = -4350.0f;
    o->w2c = 0;
    UiObjSetLowered((UiObj*)o->p28);
    return o;
}

Task_801B1104* fn_801B1104(void* a)
{
    Task_801B1104* o = fn_802267AC(a, fn_801B0F1C);
    o->p24 = fn_801E1A74(1, 0x58);
    o->p28 = fn_801E1A74(1, 0x6c);
    o->p28->f38 = 1.0f;
    o->p28->alpha = 1.0f;
    o->w2c = 0;
    o->p28->h54 = 0;
    o->p24[0] = 0;
    o->p28->x = -348.0f;
    o->p28->tx = -348.0f;
    o->p28->y = 36.0f;
    o->p28->ty = 36.0f;
    o->p28->z = -4050.0f;
    o->p28->h52 = 0;
    o->p28->w4c = fn_801F4AE4((s16)lbl_803471B8->p24->h06);
    UiObjSetLowered((UiObj*)o->p28);
    return o;
}

Task_801B1A78* fn_801B1A78(void* a)
{
    Task_801B1A78* o = fn_802267AC(a, fn_801B11EC);
    o->p24 = fn_801E1A74(1, 0x58);
    o->p28 = fn_801E1A74(1, 0x6c);
    o->w2c = 0;
    o->p24[0] = 0;
    o->p28->x = 648.0f;
    o->p28->tx = 648.0f;
    o->p28->y = 282.0f;
    o->p28->ty = 282.0f;
    o->p28->h54 = 0;
    o->p28->h52 = 0;
    o->p28->f38 = 1.0f;
    o->p28->alpha = 1.0f;
    o->p28->z = -4400.0f;
    return o;
}

Task_801B6240* fn_801B6240(void* a, f32 x)
{
    Task_801B6240* o = fn_802267AC(a, fn_801B5EA8);
    o->p24 = fn_801E1A74(1, 0x58);
    o->p28 = fn_801E1A74(1, 0x6c);
    o->w2c = 0;
    o->p24[0] = 0;
    o->p28->alpha_en = 0;
    o->p28->x = 640.0f;
    o->p28->tx = 640.0f;
    o->p28->y = 480.0f;
    o->p28->ty = 480.0f;
    o->p28->rdx = 0.0f;
    o->p28->rdy = 0.0f;
    o->p28->alpha = 1.0f;
    o->p28->z = x;
    UiObjSetLowered((UiObj*)o->p28);
    return o;
}

Task_801B6AE8* fn_801B6AE8(void* a)
{
    Task_801B6AE8* o = fn_802267AC(a, fn_801B6950);
    o->p24 = fn_801E1A74(1, 0x58);
    o->p28 = fn_801E1A74(1, 0x6c);
    o->p24[0] = 0;
    o->p28->alpha_en = 0;
    o->p28->z = -4400.0f;
    o->p28->x = -260.0f;
    o->p28->tx = -260.0f;
    o->p28->y = 100.0f;
    o->p28->ty = 100.0f;
    o->p28->rdx = 0.0f;
    o->p28->rdy = 0.0f;
    o->p28->alpha = 1.0f;
    UiObjSetRaised((UiObj*)o->p28);
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
    if (((Flags_UNIT0000 *)lbl_80311A60[0])->w08 & 0x100) {
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

u16 fn_801B952C(u16 k)
{
    switch (k) {
    case 0:
        return (u16)lbl_803471B8->p30->w3cc;
    case 1:
        return (u16)lbl_803471B8->p30->w00;
    case 2:
        return (u16)lbl_803471B8->p30->w144;
    case 3:
        return (u16)lbl_803471B8->p30->w288;
    case 4:
        return (u16)lbl_803471B8->p30->w510;
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
        fn_800906E8(s->x4);
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
        UiObjMoveToXIfChanged(o->ctx->x210->obj, 6, 4, -330.0f);
        UiObjSetCommand(o->ctx->x210->obj, 0xf, 0);
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
    if (fn_801A6554(o) == 0 || ((f = ((Flg *)lbl_80311A60[0])->flags) & 0x100)) {
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

s32 fn_801A388C(s32 chan, s32 a, s32* out) {
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
            if (fn_8025ED74(&lbl_803080F8, a) == 0) break;
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
        fn_801DBA70(lbl_802B49C4, 0x161, lbl_802B49D0);
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
        n->b->name = lbl_80346808;
    } else {
        n->b->o.z = -4300.0f;
        n->b->o.x = -240.0f;
        n->b->o.tx = -240.0f;
        n->b->o.y = 292.0f;
        n->b->o.ty = 292.0f;
        n->b->name = lbl_8034680C;
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
    t->pan->ui.alpha_en = 0;
    t->pan->slot = slot;
    if (slot == 0) {
        t->pan->ui.z = -4200.0f;
        t->pan->ui.x = -340.0f;
        t->pan->ui.tx = -340.0f;
        t->pan->ui.y = 100.0f;
        t->pan->ui.ty = 100.0f;
        t->pan->label = "Slot A";
    } else {
        t->pan->ui.z = -4150.0f;
        t->pan->ui.x = -340.0f;
        t->pan->ui.tx = -340.0f;
        t->pan->ui.y = 164.0f;
        t->pan->ui.ty = 164.0f;
        t->pan->label = "Slot B";
    }
    t->pan->ui.alpha = 1.0f;
    UiObjSetLowered(&t->pan->ui);
    return t;
}

SlotTask* fn_801A6244(void* a, u16 slot) {
    SlotTask* t = fn_802267AC(a, fn_801A6344);
    t->buf = fn_801E1A74(1, 0x58);
    t->pan = fn_801E1A74(1, 0x6c);
    t->buf[0] = 0;
    t->pan->ui.alpha_en = 0;
    t->pan->ui.z = -4100.0f;
    t->pan->ui.x = -340.0f;
    t->pan->ui.tx = -340.0f;
    t->pan->ui.y = 36.0f;
    t->pan->ui.ty = 36.0f;
    t->pan->ui.rdx = 105.0f;
    t->pan->ui.rdy = 18.0f;
    t->pan->ui.alpha = 1.0f;
    t->pan->slot = slot;
    if (slot == 0) {
        t->pan->label = "Save";
    } else {
        t->pan->label = "Load";
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
        UiObjUpdate(t->ui);
        UiLayoutDraw((NJS_TEXLIST**)&menu_sprites.texlist8, lbl_802B7C14, 4, &t->ui->x, t->ui->z, 1.0f, 1.0f);
        fn_801C3F5C(19.0f + t->ui->x, 17.0f + t->ui->y, -27.5f + t->ui->z);
        z = TextGetZ();
        TextPushColor();
        TextSetColor(0xFF201008);
        TextSetZ(-27.5f + t->ui->z);
        TextPopColor(1);
        TextSetZ(z);
        break;
    case 0xFF:
        MenuDummy();
        t->flags |= 0x40;
        break;
    }
}

Task3_801ACC00* fn_801ACC00(void* arg, u16 slot) {
    Task3_801ACC00* t = fn_802267AC(arg, fn_801AC48C);
    t->a = fn_801E1A74(1, 0x58);
    t->pan = fn_801E1A74(1, 0x6c);
    t->c = fn_801E1A74(1, 0x20);
    t->d = fn_801E1A74(1, 0x18);
    t->f2C = 0;
    t->a->slot = slot;
    t->c->b1E = 4;
    t->c->b1F = 3;
    t->c->s18 = 0;
    t->c->s1A = 0;
    t->pan->ui.alpha_en = 0;
    ((u8*)t->a)[0] = 0;
    t->pan->ui.x = 648.0f;
    t->pan->ui.tx = 648.0f;
    t->pan->ui.y = 38.0f;
    t->pan->ui.ty = 38.0f;
    t->pan->ui.rdx = 0.0f;
    t->pan->ui.rdy = 0.0f;
    *(f32*)((u8*)t->pan + 0x38) = 1.0f;
    t->pan->ui.alpha = 1.0f;
    t->pan->ui.z = -4500.0f;
    UiObjSetLowered(&t->pan->ui);
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
        UiObjUpdate(&t->pan->ui);
        UiObjCalcRect(&t->pan->ui);
        UiLayoutDraw((NJS_TEXLIST**)&menu_sprites.texlist8, lbl_802B79E4[t->pan->layout].parts,
                     lbl_802B79E4[t->pan->layout].count, t->pan->ui.rect, t->pan->ui.z, t->pan->ui.alpha, 1.0f);
        UiLayoutDraw((NJS_TEXLIST**)&menu_sprites.texlist8, lbl_802B77AC, 1, &t->pan->ui.rect[2], t->pan->ui.z, 1.0f, 1.0f);
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
    t->pan->ui.alpha = 1.0f;
    t->pan->layout = 4;
    t->data->s6 = 6;
    t->f2C = 0;
    t->data->cb = fn_801B0B2C;
    t->pan->ui.alpha_en = 0;
    t->data->b0 = 0;
    t->pan->ui.x = -348.0f;
    t->pan->ui.tx = -348.0f;
    t->pan->ui.y = 356.0f;
    t->pan->ui.ty = 356.0f;
    t->pan->ui.z = -4150.0f;
    t->pan->f52 = 1;
    t->pan->f4C = lbl_802EBF60[6];
    UiObjSetLowered(&t->pan->ui);
    return t;
}

Task3_801B0DF8* fn_801B0DF8(void* arg) {
    Task3_801B0DF8* t = fn_802267AC(arg, fn_801B0B9C);
    t->a = fn_801E1A74(1, 0x58);
    t->pan = fn_801E1A74(1, 0x6c);
    t->c = fn_801E1A74(1, 0x20);
    t->d = fn_801E1A74(1, 0x18);
    t->f2C = 0;
    t->d->s8 = 3;
    t->d->sA = 0;
    *(f32*)((u8*)t->pan + 0x38) = 1.0f;
    t->pan->ui.alpha = 1.0f;
    *(f32*)((u8*)t->pan + 0x38) = 1.0f;
    t->pan->ui.alpha = 1.0f;
    t->pan->ui.z = -4300.0f;
    t->pan->ui.alpha_en = 0;
    t->pan->f54 = 0;
    t->pan->f52 = 0;
    ((u8*)t->a)[0] = 0;
    t->pan->ui.x = -348.0f;
    t->pan->ui.tx = -348.0f;
    t->pan->ui.y = 164.0f;
    t->pan->ui.ty = 164.0f;
    UiObjSetLowered(&t->pan->ui);
    t->d->sA = 1;
    return t;
}

Task3_801B2310* fn_801B2310(void* arg) {
    Task3_801B2310* t = fn_802267AC(arg, fn_801B1B3C);
    t->a = fn_801E1A74(1, 0x58);
    t->pan = fn_801E1A74(1, 0x6c);
    t->c = fn_801E1A74(1, 0x20);
    t->d = fn_801E1A74(1, 0x18);
    *(f32*)((u8*)t->pan + 0x38) = 1.0f;
    t->pan->ui.alpha = 1.0f;
    t->d->sA = 0;
    t->f2C = 0;
    t->c->b1E = 0;
    t->c->s1C = 0;
    t->c->s18 = 0;
    t->c->s1A = 0;
    t->c->b1F = 3;
    t->pan->f54 = 0;
    t->pan->f56 = 0;
    t->a[0] = 0;
    t->pan->ui.x = 648.0f;
    t->pan->ui.tx = 648.0f;
    t->pan->ui.y = 100.0f;
    t->pan->ui.ty = 100.0f;
    t->pan->ui.z = -4500.0f;
    UiObjSetLowered(&t->pan->ui);
    return t;
}

Task2_801B2678* fn_801B2678(void* arg, u16 sel) {
    Task2_801B2678* t = fn_802267AC(arg, fn_801B2430);
    t->a = fn_801E1A74(1, 0x58);
    t->pan = fn_801E1A74(1, 0x6c);
    t->pan->ui.z = -4400.0f;
    *(f32*)((u8*)t->pan + 0x38) = 1.0f;
    t->pan->ui.alpha = 1.0f;
    t->f2C = 0;
    t->pan->f54 = 0;
    t->a[0] = 0;
    t->pan->ui.x = -240.0f;
    t->pan->ui.tx = -240.0f;
    t->pan->ui.y = 206.0f;
    t->pan->ui.ty = 206.0f;
    if (sel == 0) {
        t->pan->f4C = lbl_802EC04C[3];
    } else {
        t->pan->f4C = lbl_802EC04C[4];
    }
    UiObjSetLowered(&t->pan->ui);
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
    t->pan->ui.alpha_en = 0;
    t->a[0] = 0;
    t->pan->ui.x = 648.0f;
    t->pan->ui.tx = 648.0f;
    t->pan->ui.y = 38.0f;
    t->pan->ui.ty = 38.0f;
    t->pan->ui.rdx = 0.0f;
    t->pan->ui.rdy = 0.0f;
    *(f32*)((u8*)t->pan + 0x38) = 1.0f;
    t->pan->ui.alpha = 1.0f;
    t->pan->ui.z = -4500.0f;
    UiObjSetLowered(&t->pan->ui);
    return t;
}

void fn_801B5D68(Task3_801B5D68* t) {
    if (t->d != 0) {
        switch (t->d->state) {
        case 0:
            t->d->f10 = 0;
            t->d->angle = 0;
            t->d->scale = 1.0f;
            break;
        case 1:
            t->d->scale = 1.0f;
            t->d->state = 2;
            t->d->angle = 0;
        case 2:
            if (lbl_802B73A4[t->d->idx].flag6 != 0) {
                t->d->scale = 1.0f - 0.7f * njSin(t->d->angle);
                t->d->angle += 0x400;
                t->d->angle &= 0x7F00;
            }
            UiLayoutDraw((NJS_TEXLIST**)&menu_sprites.texlist8, lbl_802B73A4[t->d->idx].parts, 2,
                         (f32*)t->d, -32.5f + t->ui->z, 1.0f, t->d->scale);
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
        UiObjUpdate(t->ui);
        UiLayoutDraw((NJS_TEXLIST**)&menu_sprites.texlist8, lbl_802B6DD0, 2, &t->ui->x, t->ui->z, 1.0f, 1.0f);
        z = TextGetZ();
        TextPushColor();
        TextSetColor(0xFF201008);
        fn_801B6E5C(t);
        TextSetZ(-27.5f + t->ui->z);
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
        UiObjUpdate(&t->pan->ui);
        z = TextGetZ();
        TextPushColor();
        TextSetColor(0xFF201008);
        UiLayoutDraw((NJS_TEXLIST**)&menu_sprites.texlist8, lbl_802B6DD0, 2, &t->pan->ui.x, t->pan->ui.z, 1.0f, 1.0f);
        if (t->pan->label != 0) {
            TextSetZ(-27.5f + t->pan->ui.z);
            TextPrint(18.0f + t->pan->ui.x, 12.0f + t->pan->ui.y, t->pan->label);
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
        UiObjUpdate(&t->pan->ui);
        UiLayoutDraw((NJS_TEXLIST**)&menu_sprites.texlist8, lbl_802B6B0C, 4, &t->pan->ui.x, t->pan->ui.z, 1.0f, 1.0f);
        z = TextGetZ();
        TextSetZ(-4027.5f);
        TextPushColor();
        TextSetColor(0xFF201008);
        TextPrint(20.0f + t->pan->ui.x, 20.0f + t->pan->ui.y, t->pan->label);
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
    t->pan->ui.alpha_en = 0;
    t->pan->ui.z = -4000.0f;
    t->pan->ui.x = -260.0f;
    t->pan->ui.tx = -260.0f;
    t->pan->ui.y = 36.0f;
    t->pan->ui.ty = 36.0f;
    t->pan->ui.rdx = 0.0f;
    t->pan->ui.rdy = 0.0f;
    t->pan->ui.alpha = 1.0f;
    if (lbl_803473BF == 0) {
        t->pan->label = lbl_802EC0A0[lbl_803473BC].label;
    } else {
        t->pan->label = lbl_802ED218[lbl_803473BC].label;
    }
    UiObjSetRaised(&t->pan->ui);
    return t;
}


s32 fn_801B93E8(TaskSel* t) {
    s32 r = -1;
    Sel* s = t->o->in->s;
    u16 idx = s->c + s->a * 6;
    s16* p;
    switch (s->kind) {
    case 0:
        p = lbl_803471B8->t->g[3][idx];
        if (p != 0) r = *p;
        break;
    case 1:
        p = lbl_803471B8->t->g[0][idx];
        if (p != 0) r = *p;
        break;
    case 2:
        p = lbl_803471B8->t->g[1][idx];
        if (p != 0) r = *p;
        break;
    case 3:
        p = lbl_803471B8->t->g[2][idx];
        if (p != 0) r = *p;
        break;
    case 4:
        p = lbl_803471B8->t->g[4][idx];
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
        UiObjMoveToX(self->ctx->p220->ui, 6, 5, -240.0f);
        UiObjSetCommand(self->ctx->p220->ui, 0x1a, 2);
        UiObjMoveToX(self->ctx->p224->ui, 6, 5, -240.0f);
        UiObjSetCommand(self->ctx->p224->ui, 0x1a, 0);
        MenuPlaySe(3);
        fn_801A64B4(self, 4);
        self->state19 = 0x17;
    } else if (fn_801A6554(self) == 0 || (*(u32 *)(lbl_80311A60[0] + 8) & 0x100) != 0) {
        u32 cmd;
        fn_801A64E0(self);
        cmd = 0x14;
        if (self->ctx->b8 == 0) {
            cmd = 0x15;
        }
        UiObjSetCommand(self->ctx->p220->ui, cmd, 0);
        cmd = 0x14;
        if (self->ctx->b8 == 1) {
            cmd = 0x15;
        }
        UiObjSetCommand(self->ctx->p224->ui, cmd, 0);
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
    if (self->ctx->wc == 0 || (*(u32 *)(lbl_80311A60[0] + 8) & 0x300) != 0) {
        fn_801A1B98(self, 1);
        fn_801A4DCC(self, 1);
        UiObjMoveToXIfChanged(self->ctx->p210->ui, 6, 4, -330.0f);
        UiObjSetCommand(self->ctx->p210->ui, 0xf, 0);
        self->state19 = 0x16;
    } else if ((*(u32 *)(lbl_80311A60[0] + 8) & 0x400) != 0) {
        self->state19 = 0x1e;
    }
    self->ctx->w25c[self->ctx->b4] = fn_801A28AC(self->ctx->b4);
    if (self->ctx->w25c[self->ctx->b4] != 0) {
        self->ctx->b9 = 0;
        if (1.0f != self->ctx->f18) {
            fn_801A4DCC(self, 1);
        }
        UiObjMoveToXIfChanged(self->ctx->p210->ui, 6, 4, -330.0f);
        UiObjSetCommand(self->ctx->p210->ui, 0xf, 0);
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
            UiObjMoveToXIfChanged(self->ctx->p210->ui, 6, 4, -330.0f);
            UiObjSetCommand(self->ctx->p210->ui, 0xf, 0);
            UiObjMoveToX(self->ctx->p220->ui, 6, 5, -240.0f);
            UiObjSetCommand(self->ctx->p220->ui, 0x1a, 2);
            UiObjMoveToX(self->ctx->p224->ui, 6, 5, -240.0f);
            UiObjSetCommand(self->ctx->p224->ui, 0x1a, 0);
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
                UiObjFinish(h->ui);
            }
        }
        self->state19 = 9;
        self->ctx->w25c[self->ctx->b4] = fn_801A28AC(self->ctx->b4);
        if (self->ctx->w25c[self->ctx->b4] != 0) {
            self->ctx->b9 = 0;
            if (1.0f != self->ctx->f18) {
                fn_801A4DCC(self, 1);
            }
            UiObjMoveToXIfChanged(self->ctx->h[1]->ui, 6, 4, -330.0f);
            UiObjSetCommand(self->ctx->h[1]->ui, 0xf, 0);
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
        UiObjUpdate(&t->pan->ui);
        if (-132.0f < t->pan->ui.y && t->pan->ui.y < 370.0f) {
            if (UiObjIsBusy(&t->pan->ui) == 0 && t->pan->slot == parent->ctx->b7) {
                t->pan->ui.alpha = 1.0f;
            } else {
                t->pan->ui.alpha = 0.5f;
            }
            UiLayoutDraw((NJS_TEXLIST **)&menu_sprites.texlist8, lbl_802B4B9C, 6, &t->pan->ui.x, t->pan->ui.z, t->pan->ui.alpha * t->parent->ctx->f18, 1.0f);
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
    TextSetZ(-27.5f + t->ctx->h[idx]->ui->z);
    TextPrint((s32)(336.0f + (t->ctx->h[idx]->ui->x + t->ctx->h[idx]->ui->rdx)),
              (s32)(off + (t->ctx->h[idx]->ui->y - t->ctx->h[idx]->ui->rdy)), "\x81\x7e");
    TextPrintNumber((s32)(360.0f + (t->ctx->h[idx]->ui->x + t->ctx->h[idx]->ui->rdx)),
                    (s32)(off + (t->ctx->h[idx]->ui->y - t->ctx->h[idx]->ui->rdy)), t->ctx->h4, 0xC002);
    TextPopColor(1);
    TextSetZ(z);
}

void fn_801AB580(Self_801AB580 *self) {
    Row_801AB580 *row = &(*(Row_801AB580(*)[])&lbl_802EC0A0)[lbl_803473BC];
    u32 i = 0;
    u32 n = 0;
    for (; i < 0x30; i++) {
        if (row->e[i] != -1) {
            s16 id;
            u8 flag;
            self->buf->out[i].id = row->e[i];
            self->buf->out[i].type = fn_801F4C24(row->e[i]);
            id = (u16)row->e[i];
            if (fn_801F477C(id) == 0) {
                flag = 1;
            } else if ((*(Game_801AB580*)&lbl_8030B7F4).w34c / fn_801F477C(id) == 0) {
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

    max = (*(Game_801AB82C*)&lbl_8030B7F4).w34c / fn_801F477C(idx);
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
    extern s32 UiLayoutDraw(NJS_TEXLIST** texlists, void* parts, u32 count, f32* pos, f32 z, f32 a, f32 b);
    extern s32 UiLayoutDrawPart(NJS_TEXLIST** texlists, void* parts, s32 count, f32* pos, u16 index, f32 z, f32 a, f32 b);
    extern void* fn_802267AC(void* a, void (*b)(Task*));
    extern void* fn_801E1A74(s32 a, s32 b);
    extern u8 lbl_802B7BC4[];
    extern u8 lbl_802B7C00[];
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
        tl = (NJS_TEXLIST**)&menu_sprites.texlist8;
        UiLayoutDraw(tl, lbl_802B7BC4, 3, p->obj->o.rect, p->obj->o.z, 1.0f, 1.0f);
        UiLayoutDraw(tl, lbl_802B7C00, 1, &p->obj->o.rect[2], p->obj->o.z, 1.0f, 1.0f);
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
    extern s32 UiLayoutDraw(NJS_TEXLIST** texlists, void* parts, u32 count, f32* pos, f32 z, f32 a, f32 b);
    extern s32 UiLayoutDrawPart(NJS_TEXLIST** texlists, void* parts, s32 count, f32* pos, u16 index, f32 z, f32 a, f32 b);
    extern void* fn_802267AC(void* a, void (*b)(Task*));
    extern void* fn_801E1A74(s32 a, s32 b);
    extern LT lbl_802B7B64[];
    extern LT lbl_802B7B94[];
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
        tl = (NJS_TEXLIST**)&menu_sprites.texlist8;
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
    extern s32 UiLayoutDraw(NJS_TEXLIST** texlists, void* parts, u32 count, f32* pos, f32 z, f32 a, f32 b);
    extern s32 UiLayoutDrawPart(NJS_TEXLIST** texlists, void* parts, s32 count, f32* pos, u16 index, f32 z, f32 a, f32 b);
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
    extern s32 UiLayoutDraw(NJS_TEXLIST** texlists, void* parts, u32 count, f32* pos, f32 z, f32 a, f32 b);
    extern s32 UiLayoutDrawPart(NJS_TEXLIST** texlists, void* parts, s32 count, f32* pos, u16 index, f32 z, f32 a, f32 b);
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
    extern s32 UiLayoutDraw(NJS_TEXLIST** texlists, void* parts, u32 count, f32* pos, f32 z, f32 a, f32 b);
    extern s32 UiLayoutDrawPart(NJS_TEXLIST** texlists, void* parts, s32 count, f32* pos, u16 index, f32 z, f32 a, f32 b);
    extern void* fn_802267AC(void* a, void (*b)(Task*));
    extern void* fn_801E1A74(s32 a, s32 b);
    extern LT lbl_802B6DA0[];
    extern u8 lbl_802B6D8C[];
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
        tl = (NJS_TEXLIST**)&menu_sprites.texlist8;
        UiLayoutDraw(tl, lbl_802B6DA0[p->obj->h54].parts, lbl_802B6DA0[p->obj->h54].count, p->obj->o.rect, p->obj->o.z, p->obj->o.alpha, 1.0f);
        UiLayoutDraw(tl, lbl_802B6D8C, 1, &p->obj->o.rect[2], p->obj->o.z, 1.0f, 1.0f);
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
    extern s32 UiLayoutDraw(NJS_TEXLIST** texlists, void* parts, u32 count, f32* pos, f32 z, f32 a, f32 b);
    extern s32 UiLayoutDrawPart(NJS_TEXLIST** texlists, void* parts, s32 count, f32* pos, u16 index, f32 z, f32 a, f32 b);
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
                p->x = 18.0f + p->x + 264.0f + t->ui->x;
                p->y = 16.0f + p->y + 48.0f + t->ui->y;
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
    UiObjMoveToX(o->ctx->x1f8->obj, 6, 4, -8.0f);
    UiObjSetCommand(o->ctx->x1f8->obj, 0xf, 0);
    o->ctx->x204->flag->b0 = 0;
    UiObjMoveToX(o->ctx->x204->obj, 6, 4, -8.0f);
    UiObjSetCommand(o->ctx->x204->obj, 0xf, 1);
    o->ctx->x1fc->flag->b0 = 0;
    UiObjMoveToX(o->ctx->x1fc->obj, 6, 4, -8.0f);
    UiObjSetCommand(o->ctx->x1fc->obj, 0xf, 2);
    o->ctx->x218->flag->b0 = 0;
    UiObjMoveToX(o->ctx->x218->obj, 6, -1, 240.0f);
    UiObjSetCommand(o->ctx->x218->obj, 0xf, 0);
    o->ctx->x214->flag->b0 = 0;
    UiObjMoveTo(o->ctx->x214->obj, 6, -1, 24.0f, 384.0f);
    UiObjSetCommand(o->ctx->x214->obj, 0xf, 1);
    o->ctx->x21c->flag->b0 = 0;
    UiObjMoveToX(o->ctx->x21c->obj, 6, -1, -8.0f);
    UiObjSetCommand(o->ctx->x21c->obj, 0xf, 1);
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
        UiObjMoveToXIfChanged(o->ctx->objs[1]->obj, 6, 4, -330.0f);
        UiObjSetCommand(o->ctx->objs[1]->obj, 0xf, 0);
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
            UiObjMoveToY(o->ctx->objs[4]->obj, 3, 4, 100.0f);
            UiObjSetCommand(o->ctx->objs[4]->obj, 0xf, 0);
        }
        o->ctx->objs[1]->x19 = 1;
        ((u16 *)o->ctx->objs[1]->obj)[0x54 / 2] = 1;
        o->ctx->x1c = 0.0f;
        UiObjMoveToX(o->ctx->objs[1]->obj, 6, 4, 160.0f);
        UiObjSetCommand(o->ctx->objs[1]->obj, 0xf, 0);
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
        UiObjUpdate(&t->pan->ui);
        UiLayoutDraw((NJS_TEXLIST **)&menu_sprites.texlist8, lbl_802B4A00, 2, &t->pan->ui.x, t->pan->ui.z, t->pan->ui.alpha, 1.0f);
        z = TextGetZ();
        y = 12.0f + t->pan->ui.y;
        x = 18.0f + t->pan->ui.x;
        if (t->pan->label != 0) {
            TextPushColor();
            TextSetColor(0xFF201008);
            TextSetZ(-27.5f + t->pan->ui.z);
            TextPrint((s32)x, (s32)y, t->pan->label);
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
        UiObjUpdate(&t->pan->ui);
        UiObjCalcRect(&t->pan->ui);
        UiLayoutDraw((NJS_TEXLIST **)&menu_sprites.texlist8, lbl_802B4B88, 1, &t->pan->ui.rect[2], t->pan->ui.z, 1.0f, 1.0f);
        UiLayoutDraw((NJS_TEXLIST **)&menu_sprites.texlist8, lbl_802B4B4C, 3, &t->pan->ui.rect[0], t->pan->ui.z, t->pan->ui.alpha * t->parent->ctx->f18, 1.0f);
        z = TextGetZ();
        y = 19.0f + t->pan->ui.rect[1];
        x = 74.0f + t->pan->ui.rect[0];
        if (t->pan->label != 0) {
            TextPushColor();
            TextSetColor(0xFF201008);
            TextSetZ(-27.5f + t->pan->ui.z);
            TextPrint((s32)x, (s32)y, t->pan->label);
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
        UiObjUpdate(&t->pan->ui);
        UiLayoutDraw((NJS_TEXLIST **)&menu_sprites.texlist8, lbl_802B4A28, 3, &t->pan->ui.x, t->pan->ui.z, t->pan->ui.alpha * t->parent->ctx->f18, 1.0f);
        z = TextGetZ();
        y = 18.0f + t->pan->ui.y;
        x = 105.0f + t->pan->ui.x;
        if (t->pan->label != 0) {
            TextPushColor();
            TextSetColor(0xFF201008);
            TextSetZ(-27.5f + t->pan->ui.z);
            TextPrint((s32)x, (s32)y, t->pan->label);
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
    switch (fn_801BE608((*(G**)&lbl_803471B8)->p->idx)) {
    case 0:
        t->obj->text = lbl_802ED258[(*(G**)&lbl_803471B8)->p->idx].a;
        break;
    case 1:
        t->obj->text = lbl_802ED258[(*(G**)&lbl_803471B8)->p->idx].c;
        break;
    case 2:
        t->obj->text = lbl_802ED258[(*(G**)&lbl_803471B8)->p->idx].b;
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
        UiObjUpdate(&t->pan->ui);
        z = TextGetZ();
        TextPushColor();
        TextSetColor(0xFF201008);
        UiLayoutDraw((void *)((NJS_TEXLIST **)&menu_sprites.texlist8), (void *)(lbl_802B7720), 4, (void *)(&t->pan->ui.x), t->pan->ui.z, 1.0f, 1.0f);
        fn_801B6BB4(t->pan, &t->pan->ui.x, (*(Gl_801B0F1C *(*)[2])&lbl_803471B8)[0]->cfg->h6, -1, 0x18, 0x14, 1.0f);
        TextSetZ(-27.5f + t->pan->ui.z);
        TextPrint(55.0f + t->pan->ui.x, 20.0f + t->pan->ui.y, t->pan->label);
        TextPrint(264.0f + t->pan->ui.x, 20.0f + t->pan->ui.y, "\x81\x7e");
        TextPrintNumber(288.0f + t->pan->ui.x, 20.0f + t->pan->ui.y, (*(Gl_801B0F1C *(*)[2])&lbl_803471B8)[0]->cfg->b9, 0xC002);
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
        UiObjUpdate(&t->pan->ui);
        UiLayoutDraw((void *)((NJS_TEXLIST **)&menu_sprites.texlist8), (void *)(lbl_802B6DF8), 4, (void *)(&t->pan->ui.x), t->pan->ui.z, 1.0f, 1.0f);
        z = TextGetZ();
        TextPushColor();
        TextSetColor(0xFF201008);
        TextSetZ(-27.5f + t->pan->ui.z);
        TextPrint(20.0f + t->pan->ui.x, 5.0f + t->pan->ui.y, t->pan->label);
        TextPrint(20.0f + t->pan->ui.x, 32.0f + t->pan->ui.y, (*(const char *(*)[13])&lbl_802EC04C)[5]);
        TextPopColor(1);
        pos.x = 84.0f + (97.0f + (t->pan->ui.x + t->pan->ui.rdx));
        pos.y = 7.0f + (t->pan->ui.y - t->pan->ui.rdy);
        pos.z = -32.0f + t->pan->ui.z;
        UiDrawNumber(&pos, 0, 8, (*(Gl_801B2430 *(*)[2])&lbl_803471B8)[0]->cfg->w11c, t->pan->ui.alpha);
        pos.y = 34.0f + (t->pan->ui.y - t->pan->ui.rdy);
        pos.z = -31.5f + t->pan->ui.z;
        UiDrawNumber(&pos, 0, 8, (*(Gl_801B2430 *(*)[2])&lbl_803471B8)[0]->cfg->w120, t->pan->ui.alpha);
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
        UiObjMoveToXIfChanged(o->ctx->objs[1]->obj, 6, 4, -330.0f);
        UiObjSetCommand(o->ctx->objs[1]->obj, 0xf, 0);
        fn_801A4DCC(o, 1);
        k = fn_801A6A58(o->ctx->idx, o->ctx->slot[o->ctx->idx]);
        fn_801A64B4(o, k);
        o->state = 0x17;
    } else if (o->ctx->x1 == 1) {
        fn_801A1DB4();
        fn_801A1B98(o, 0);
        fn_801A4DCC(o, 1);
        UiObjMoveToXIfChanged(o->ctx->objs[1]->obj, 6, 4, -330.0f);
        UiObjSetCommand(o->ctx->objs[1]->obj, 0xf, 0);
        o->ctx->x9 = 0;
        o->state = 8;
    } else if (o->ctx->x14 != 0) {
        fn_801A64B4(o, 5);
        fn_801A1B98(o, 0);
        o->ctx->x9 = 0;
        fn_801A4DCC(o, 1);
        UiObjMoveToXIfChanged(o->ctx->objs[1]->obj, 6, 4, -330.0f);
        UiObjSetCommand(o->ctx->objs[1]->obj, 0xf, 0);
        o->state = 8;
    } else {
        o->ctx->slot[o->ctx->idx] = 6;
        fn_801A64B4(o, fn_801A6A58(o->ctx->idx, o->ctx->slot[o->ctx->idx]));
        o->ctx->x26c = 3;
        MenuPlaySe(3);
        fn_801A4DCC(o, 1);
        UiObjMoveToXIfChanged(o->ctx->objs[1]->obj, 6, 4, -330.0f);
        UiObjSetCommand(o->ctx->objs[1]->obj, 0xf, 0);
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
    o->p28->alpha_en = 0;
    o->p28->x = 640.0f;
    o->p28->tx = 640.0f;
    o->p28->y = 480.0f;
    o->p28->ty = 480.0f;
    o->p28->rdx = 0.0f;
    o->p28->rdy = 0.0f;
    o->p28->alpha = 1.0f;
    o->p28->z = x;
    UiObjSetLowered((UiObj*)o->p28);
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

void fn_8019EFF8(Task_8019EFF8* t) {
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
        UiObjMoveToXIfChanged(t->w->p[1]->obj, 6, 4, -330.0f);
        UiObjSetCommand(t->w->p[1]->obj, 0xf, 0);
        fn_801A4DCC(t, 1);
        UiObjMoveToX(t->w->p[5]->obj, 6, 5, -240.0f);
        UiObjSetCommand(t->w->p[5]->obj, 0x1a, 2);
        UiObjMoveToX(t->w->p[6]->obj, 6, 5, -240.0f);
        UiObjSetCommand(t->w->p[6]->obj, 0x1a, 0);
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
        UiObjMoveToXIfChanged(t->w->p[1]->obj, 6, 4, -330.0f);
        UiObjSetCommand(t->w->p[1]->obj, 0xf, 0);
        UiObjMoveToX(t->w->p[5]->obj, 6, 5, -240.0f);
        UiObjSetCommand(t->w->p[5]->obj, 0x1a, 2);
        UiObjMoveToX(t->w->p[6]->obj, 6, 5, -240.0f);
        UiObjSetCommand(t->w->p[6]->obj, 0x1a, 0);
        fn_801A4DCC(t, 1);
        lbl_803475D0 = 0;
        lbl_803475E0 = 0;
        t->state = 0x17;
    }
}

void fn_801A11B0(Task_801A11B0* t) {
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
        bits = ((PadInfo*)lbl_80311A60)[0].pad->bits;
        if (bits & 0x100) {
            if (t->w->cnt == 0) {
                MenuPlaySe(3);
            } else if (t->w->sel != 2) {
                MenuPlaySe(2);
                if (t->w->sel == 0) {
                    UiObjSetCommand(t->w->p[3]->obj, 0x14, 0);
                    UiObjMoveToX(t->w->p[4]->obj, 6, 5, -340.0f);
                    UiObjSetCommand(t->w->p[4]->obj, 0xf, 0);
                } else {
                    UiObjMoveToX(t->w->p[3]->obj, 6, 5, -340.0f);
                    UiObjSetCommand(t->w->p[3]->obj, 0xf, 0);
                    UiObjSetCommand(t->w->p[4]->obj, 0x14, 0);
                }
                fn_801A64B4((void *)(t), 0x11);
                t->state = 5;
            } else {
                goto cancel;
            }
        } else if (bits & 0x200) {
        cancel:
            UiObjSetCommand(t->w->p[3]->obj, 0x14, 0);
            UiObjSetCommand(t->w->p[4]->obj, 0x14, 0);
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

void fn_801B737C(Ent_801B737C* t)
{
    char buf[32];
    s32 i;
    s32 ok;
    for (i = 0; i < 8; i++) {
        ok = 0;
        switch (i) {
        case 0:
            fn_8025F120((void *)(buf), (void *)(((char**)lbl_802EBF7C)[i]));
            ok = 1;
            break;
        case 1:
            if ((*(Fl*)&lbl_80310B3C).f4 & 0x10000000) {
                fn_8025F120((void *)(buf), (void *)(((char**)lbl_802EBF7C)[i]));
                ok = 1;
            }
            break;
        case 2:
            if ((*(Fl*)&lbl_80310B3C).f18 & 0x100) {
                fn_8025F120((void *)(buf), (void *)(((char**)lbl_802EBF7C)[i]));
                ok = 1;
            }
            break;
        case 3:
            if ((*(Fl*)&lbl_80310B3C).f1c & 0x04000000) {
                fn_8025F120((void *)(buf), (void *)(((char**)lbl_802EBF7C)[i]));
                ok = 1;
            }
            break;
        case 4:
            if ((*(Fl*)&lbl_80310B3C).f168 & 0x40000000) {
                fn_8025F120((void *)(buf), (void *)(((char**)lbl_802EBF7C)[i]));
                ok = 1;
            }
            break;
        case 5:
            if (((*(Fl*)&lbl_80310B3C).f30 & 0x10000) || (*(St_801B737C*)&lbl_80310A1C).seen[5] > 0) {
                ok = 1;
                if ((*(St_801B737C*)&lbl_80310A1C).seen[5] > 1) {
                    fn_8025F120((void *)(buf), (void *)(lbl_802B8F70));
                } else {
                    fn_8025F120((void *)(buf), (void *)(((char**)lbl_802EBF7C)[i]));
                }
            }
            break;
        case 6:
            if ((*(Fl*)&lbl_80310B3C).f170 & 0x80) {
                fn_8025F120((void *)(buf), (void *)(((char**)lbl_802EBF7C)[i]));
                ok = 1;
            }
            break;
        case 7:
            if ((*(Fl*)&lbl_80310B3C).f30 & 0x1000000) {
                fn_8025F120((void *)(buf), (void *)(((char**)lbl_802EBF7C)[i]));
                ok = 1;
            }
            break;
        }
        if (ok == 0) {
            TextSetColor(0x40201008);
            TextPrint((s32)(16.0f + t->v->a), (s32)(12.0f + t->v->b + (f32)(i * 24)), (void *)(lbl_802B8F94));
            TextSetColor(0xFF201008);
        } else {
            TextPrint((s32)(16.0f + t->v->a), (s32)(12.0f + t->v->b + (f32)(i * 24)), (void *)(buf));
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
    UiObjSetCommand(t->m->slot[0]->obj, cmd, 0);
    if ((s = t->m->slot[1]) != 0) {
        o = s->obj;
        cmd = 0x14;
        if (t->m->cur == 1) cmd = 0x15;
        UiObjSetCommand(o, cmd, 0);
    }
    if ((s = t->m->slot[2]) != 0) {
        o = s->obj;
        cmd = 0x14;
        if (t->m->cur == 2) cmd = 0x15;
        UiObjSetCommand(o, cmd, 0);
    }
    if ((s = t->m->slot[3]) != 0) {
        o = s->obj;
        cmd = 0x14;
        if (t->m->cur == 3) cmd = 0x15;
        UiObjSetCommand(o, cmd, 0);
    }
    cmd = 0x14;
    if (t->m->cur == 4) cmd = 0x15;
    UiObjSetCommand(t->m->slot[4]->obj, cmd, 0);
    return ret;
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
    switch (fn_801F4C24(id)) {
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

void fn_801A6650(Task_801A6650 *t, u16 i)
{
    if (t->work->slots[i] != NULL) {
        TaskDelete(t->work->slots[i]);
        t->work->slots[i] = NULL;
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
        UiObjMoveToXIfChanged(self->ctx->h[1]->ui, 6, 4, -330.0f);
        UiObjSetCommand(self->ctx->h[1]->ui, 0xf, 0);
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

CardRec *fn_801A41EC(SaveData *p, s32 chan, const char *name) {
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
    fn_8025F120(rec->name, name);
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

s32 fn_801AAFAC(Self_801AAFAC *self) {
    u32 i;
    u32 n;
    s32 done = 0;

    for (i = n = 0; i < self->ctx->count; i++) {
        if (fn_801C0B88(self->ctx->id, self->ctx->slot[i])) {
            n++;
            self->ctx->items[i]->ui->alpha = 0.7f;
            if (n == self->ctx->count) {
                done = 1;
            }
        } else if (self->ctx->b9 != 0) {
            self->ctx->items[i]->ui->alpha = 1.0f;
        } else {
            self->ctx->items[i]->ui->alpha = 0.7f;
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
        UiObjUpdate(&t->pan->ui);
        UiLayoutDraw((NJS_TEXLIST**)&menu_sprites.texlist8, lbl_802B6B0C, 4, &t->pan->ui.x, t->pan->ui.z, 1.0f, 1.0f);
        z = TextGetZ();
        TextSetZ(-4027.5f);
        TextPushColor();
        TextSetColor(0xFF201008);
        TextPrint(24.0f + t->pan->ui.x, 20.0f + t->pan->ui.y, lbl_80346810[t->pan->label]);
        TextPopColor(1);
        TextSetZ(z);
        break;
    case 0xFF:
        MenuDummy(t);
        t->flags |= 0x40;
        break;
    }
}

PanelTask_801AFBE8* fn_801AFBE8(void* parent, u16 idx, u16 mode, f32 alpha) {
    PanelTask_801AFBE8* t = fn_802267AC(parent, fn_801AFAA4);

    t->w = fn_801E1A74(1, 0x58);
    t->obj = fn_801E1A74(1, 0x6c);
    *(f32 *)&t->obj->o.pad38[0] = 1.0f;
    t->x2c = 0;
    t->obj->h56 = idx;
    t->obj->h54 = mode;
    t->obj->o.alpha_en = 0;
    t->obj->o.alpha = alpha;
    t->w->state = 0;
    t->obj->o.x = -348.0f;
    t->obj->o.tx = -348.0f;
    t->obj->o.y = lbl_802B8F20[idx].y;
    t->obj->o.ty = lbl_802B8F20[idx].y;
    t->obj->o.z = lbl_802B8F20[idx].z;
    t->obj->h52 = 1;
    if (mode != 0) {
        t->w->cb_801AFBE8 = fn_801AFD34;
    } else {
        t->w->cb_801AFBE8 = fn_801B0014;
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
        fn_8025F120(buf, lbl_802B8F94);
        break;
    case 1:
    case 2:
        fn_8025F120(buf, lbl_802EBF7C[id]);
        break;
    case 3:
        if (id != 5) {
            fn_8025F120(buf, lbl_802EBF7C[id]);
        } else {
            fn_8025F120(buf, lbl_802B8F70);
        }
        break;
    }
    TextPrint(x, y, buf);
    TextPrintNumber(nx, ny, lbl_802EBFBC[id], 0xC005);
}
