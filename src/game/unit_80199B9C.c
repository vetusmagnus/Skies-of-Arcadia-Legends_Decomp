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
extern void fn_801A66AC(void *p);
extern void *fn_801A4DCC(void *a, u16 flag);
extern void fn_801CBBAC(f32 f);
extern void Ui2DBegin(void);
extern void *lbl_8034718C[2];
extern u32 lbl_80347184;
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
extern void fn_801A6650(void *o, s32 k);
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
extern void* fn_802267AC(void* a, void (*b)(void));
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
extern void fn_801A5274(void);
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
extern void fn_801ABD40(void);
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
extern void fn_801B0F1C(void);
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
extern void fn_801A5D08(void);
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
extern void fn_801A6344(void);
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
extern void fn_801B2430(void);
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
    lbl_80347184 = 0;
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
            fn_801A6650(o, 5);
            fn_801A6650(o, 6);
        }
        if (o->ctx->p228 != 0) {
            for (i = 0; i < 7; i++) {
                fn_801A6650(o, (u16)(i + 7));
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
    Ctl_801A4DCC* o = fn_802267AC(a, (void (*)(void))fn_801A4E58);
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
    Task2_801B6838* t = fn_802267AC(arg, (void (*)(void))fn_801B66F8);
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
