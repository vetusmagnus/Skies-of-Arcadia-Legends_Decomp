#include "types.h"
#include "game/stat_8030B4D4.h"
#include "game/work_8030CEA0.h"
#include "game/task.h"
#include "game/menu.h"
#include "ninja.h"
#include "game/camera_803119E0.h"
#include "game/uiobj.h"
#include "game/text.h"
#include "game/sprite.h"
#include <math.h>
#include <string.h>
#include <dolphin/types.h>
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
extern void* lbl_803470A0;
extern f32 lbl_8034ABDC;
typedef struct {
    u8 pad0[0x20];
    u32 w20;
    u32 w24;
    u8 pad1[0x10];
    u32 w38;
    u32 w3c;
} InnerB;
typedef struct {
    u8 pad[0x24];
    InnerB* inner;
} OwnerB;
extern OwnerB* lbl_803470B0;
typedef struct {
    u8 a;
    u8 b;
    u8 pad[2];
    f32 f;
} Rec_8016F128;
typedef struct {
    u8 a;
    u8 b;
    u8 c;
    u8 pad;
    f32 f;
    void* entry;
} Rec_80186E20;
extern u8 lbl_803072E8[];
s32 fn_801F4CA0();
typedef struct {
    u32 f0;
    u32 f4;
    u32 f8;
} Trio;
void fn_8019A15C(void* p, s32 a, s32 b, s32 c);
typedef struct {
    s32 v;
    u8 b;
} Rec_8018E81C;
extern void* lbl_80347114;
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
extern u8 lbl_80310B3C[];
void fn_8016DBAC(void *out, void *p);
extern u8 lbl_8030B7F4[0x16a0];
typedef struct Out {
    f32 f0;
    u8 pad4;
    s8 idx;
    u8 pad6[2];
    u8 *rec;
    u8 b0c;
    u8 pad_d[3];
    s32 i10;
    s32 i14;
    s32 i18;
    s32 i1c;
} Out;
extern u8 lbl_80307638[0xA50];
void fn_80195EA4(void *out, s32 a, s32 b, s32 c, s32 d);
extern s32 lbl_80308088[];
typedef struct { u8 pad[4]; u32 f4; } I1c8;
typedef struct { u8 pad[0x1c8]; I1c8 *p1c8; } Obj_8015F218;
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
typedef struct Sub_UNIT0000 {
    u8 pad0[0x18];
    f32* pos;
    u8 pad1[4];
    u32* words;
} Sub_UNIT0000;
typedef struct Obj_801671C0_UNIT0000 {
    u8 pad0[0x38];
    f32 pos[3];
    u32 vals[3];
    u8 pad1[0x1bc - 0x50];
    Sub_UNIT0000* sub;
} Obj_801671C0_UNIT0000;
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
    u8 pade;
    s8 bF;
    u8 pad10[8];
    u32 f18;
    u8 pad1c[0x30 - 0x1c];
    Task* x30;
    Task* x34;
} Sub_80168A04;
typedef struct Obj_80168A04 {
    u8 pad[0x19];
    u8 b19;
    u8 pad1a[0xA];
    Sub_80168A04* sub;
} Obj_80168A04;
typedef struct {
    Obj_80168A04 *obj;
    s32 state;
} Slot_80306F58;
extern Slot_80306F58 lbl_80306F58[3];
typedef struct Mover {
    f32 x0;
    f32 x4;
    f32 x8;
    f32 xc;
    f32 x10;
    f32 x14;
    s32 x18;
} Mover;
extern u8 lbl_80310A1C[0x120];
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
extern void fn_80195EA4(void* out, s32 a, s32 b, s32 c, s32 d);
typedef struct Target {
    u8 pad0[0x1c];
    s32 x1c;
    s32 x20;
} Target;
typedef struct Holder_80187F30 {
    Target* target;
    u8 b4;
} Holder_80187F30;
struct Dst_80189958;
extern void fn_80189958(struct Dst_80189958* dst, s32 unused, s32 a, s32 b, s32 unused2, s32 c);
typedef struct {
    u8 pad0[0x2c];
    u32 owner;        /* 0x2C */
} Node8015F2E8;
typedef struct {
    u8 pad0[0x84];
    Node8015F2E8* n84;
    Node8015F2E8* n88;
    Node8015F2E8* n8c;
    u8 pad1[0x94 - 0x90];
    s32 f94;          /* 0x94 */
    u8 pad2[0xe0 - 0x98];
    s32 fe0;          /* 0xE0 */
    u8 pad3[0x12c - 0xe4];
    s32 f12c;         /* 0x12C */
} Obj8015F2E8;
extern Obj8015F2E8* lbl_80347070;
extern void fn_80291C44(void* p);
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
extern s32 fn_8016AEBC(void* self);
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
typedef struct {
    void* p0;
    void* p4;
    void* p8;
    void* pc;
    void* p10;
} Tbl_8016CED8;
typedef struct {
    u8 pad0[0x24];
    s8* kind;
    Tbl_8016CED8* tbl;
} Obj_8016CED8;
extern s32 fn_8016C888(void);
extern u8 lbl_802E7D5C[], lbl_802E8390[], lbl_802E83E0[], lbl_802E8464[], lbl_802E84E8[];
void fn_8016CED8(Task* task);
extern void* lbl_803475A8;
typedef struct { u8 mode; u8 flag1; u8 pad02[2]; f32 f4; f32 f8; u8 pad0C[0x20]; f32 f2c; f32 f30; f32 f34; } Sub_8016D034;
typedef struct { u8 pad00[0x24]; Sub_8016D034* sub; } Owner_8016D034;
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
extern s32 fn_801944C4(void);
extern void fn_80195A68(void* p, s32 a, s32 b, s32 c, s32 d, s32 e);
typedef struct {
    u8 pad00[4];
    u32 f04;
    u8 pad08[4];
    u32 f0c;
    u8 pad10[0x34];
    u32 f44;
    u8 pad48[4];
    u32 f4c;
    u8 pad50[0x1c];
    u32 f6c;
} MS_8017439C;
typedef struct CampWorkS {
    u8 pad0[0x10];
    void *objs[0xd0];
    u8 pad350[0x10];
} CampWorkS;
extern CampWorkS camp_work;
#define CWB ((u8 *)&camp_work)
extern s32 fn_80194490(void);
extern s32 fn_8019445C(void);
extern void fn_80199BB8(UiObj* obj, f32 x, f32 y);
extern void fn_80199BAC(UiObj* obj, f32 x, f32 y);
extern void fn_80193FF8(s32 n);
extern void fn_80193FBC(s32 unused, s32 toggle);
typedef struct {
    u8 pad00[0x14];
    s32 mode; /* 0x14 */
} MS_801778AC;
extern s32 (*lbl_803467A8[2])(void);
typedef struct {
    u8 pad00[0x0c];
    u32 f0c;
    u8 pad10[0x3c];
    u32 f4c;
} MS_8017B0F8;
typedef struct {
    u8 pad00[0x18];
    s16 x18;
    s16 x1a;
    u8 pad1c[0x5c - 0x1c];
} CampRec_UNIT0000;
typedef struct {
    s8* ids;      /* 0x00 */
    void* p04;    /* 0x04 */
    u8 pad08[0x360 - 0x08];
} CampWork_UNIT0000;
extern s32 fn_801953B8(void);
extern s32 fn_80194028(void);
typedef struct {
    u8 pad00[0x14];
    s32 x14;
} CampObj;
extern s16 fn_801838C8(s32 a, s32 b);
typedef struct Ctrl_UNIT0000 {
    u8 pad00[4];
    s32 first;          /* 0x04 */
    u8 pad08[4];
    u32 mask;           /* 0x0C */
    u8 pad10[0x4C - 0x10];
    s32 x4c;            /* 0x4C */
} Ctrl_UNIT0000;
typedef struct {
    Ctrl_UNIT0000* ctrl;         /* 0x00 */
} CtrlHolder_UNIT0000;
typedef struct {
    u8 pad00[0x24];
    CtrlHolder_UNIT0000* holder; /* 0x24 */
} Outer_UNIT0000;
extern void* lbl_8034710C;
extern s32 lbl_803470C8;
extern s32 (*lbl_802E97C0[5])(void);
typedef struct {
    u8 pad00[0x20];
    void* x20;
} Sub20;
typedef struct {
    u8 pad00[4];
    Sub20* x4;
} Obj4;
extern void* lbl_803470DC;
extern void* lbl_803470D8;
extern void* lbl_803470E4;
extern void* lbl_803470E0;
void fn_801D6944(void* p);
void fn_801E17E0(void* p);
typedef struct {
    f32 f0, f4, f8, fc;
} F4;
typedef struct {
    void* p0;
    void* p4;
} P2;
typedef struct {
    f32 f00, f04;          /* 0x00 */
    s32 i08;               /* 0x08 */
    s32 i0c;               /* 0x0C */
    f32 f10, f14, f18, f1c;
    P2* p20;               /* 0x20 */
    F4* p24;               /* 0x24 */
    u8 pad28[4];
    P2* p2c;               /* 0x2C */
    F4* p30;               /* 0x30 */
    u8 pad34[4];
    P2* p38;               /* 0x38 */
    F4* p3c;               /* 0x3C */
    u8 pad40[4];
    void* p44;             /* 0x44 */
} Obj48;
extern void* lbl_803470F4;
typedef struct {
    s32 a;
    s32 b;
} Pair8;
typedef struct {
    Pair8 pairs[11];   /* 0x00 */
    u32 mask0;         /* 0x58 */
    u32 mask1;         /* 0x5C */
} PairSet;
extern void* lbl_803470F0;
extern void* lbl_803470E8;
typedef struct {
    s32 kind;
    u8 pad04[4];
    f32 rect8[4];
    u8 pad_18[0x14];
    f32 x;
    f32 y;
    u8 pad_34[0x88];
    struct Kind_8018E73C* k;
} Sub_8018DFC4;
typedef struct {
    u8 pad00[0x18];
    u8 flags18;
    u8 state19;
    u8 pad1a[0x24 - 0x1a];
    Sub_8018DFC4* p24;
} Obj_8018DFC4;
void fn_80199F38(void* r);
/* The draw argument of fn_800C2650 and its siblings (Arg_800C2650 in
   unit_800B2DA0.c). */
typedef struct Arg_800C2650 {
    f32 f0;
    s16 h4;
    s16 h6;
    f32 f8;
    f32 fc;
} Arg_800C2650;
typedef struct Kind_8018E73C {
    s32 kind;
} Kind_8018E73C;
extern f32 fn_800C2A88(Arg_800C2650 *a);
extern f32 fn_800C287C(Arg_800C2650 *a);
extern f32 fn_800C285C(Arg_800C2650 *a);
extern f32 fn_800C2650(Arg_800C2650 *a);
f32 fn_8018E73C(Sub_8018DFC4 *s);
void fn_8018E0A8(Sub_8018DFC4* s);
extern void* lbl_803470EC;
extern void* lbl_803470F8;
extern void* lbl_80347618;
void fn_801C0FE8(s32 a, s32 b);
typedef struct { u8 pad[4]; u32 f4; } Mo;
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
} Obj_8015FE60;
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
typedef struct Tgt {
    u8 pad[0x38];
    f32 x, y, z;
    s32 rx, ry, rz;
    u8 pad2[0x104 - 0x50];
    u8 tail[1];
} Tgt;
typedef struct Hold_80160954 { u8 pad[8]; Tgt *t; } Hold_80160954;
typedef struct Own_80160954 { u8 pad[0x1d8]; Hold_80160954 *h; } Own_80160954;
void fn_8008FFA4(void *, void *);
typedef struct Rec_80167244 { s16 type; s16 pad; u32 w4, w8, wc; } Rec_80167244;
typedef struct Inner_80167244 { u32 f0; void *f4; } Inner_80167244;
typedef struct Node_80167244 {
    u32 f0;
    Inner_80167244 *inner;
    u8 pad[0x2c - 8];
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
typedef struct Dst_80171B64 { u8 pad[4]; void *spr; } Dst_80171B64;
typedef struct Sub_80171B64 { u8 pad[0x94]; Dst_80171B64 *dst; } Sub_80171B64;
typedef struct Hold_80171B64 { u8 pad[0x24]; Sub_80171B64 *sub; } Hold_80171B64;
typedef struct Camp_80171B64 { u8 pad[0xac]; Hold_80171B64 *hold; } Camp_80171B64;
extern void *lbl_803470F0;
void fn_8019520C(s8 idx, void *spr);
typedef struct Hold_80172B54 { u8 pad[0x24]; } Hold_80172B54;
typedef struct Hm { u8 pad[0xbc]; void *w; } Hm;
typedef struct Mid_80172B54 { u8 pad[0x24]; Hm *hm; } Mid_80172B54;
typedef struct Camp_80172B54 { u8 pad[0x218]; Mid_80172B54 *mid; } Camp_80172B54;
void fn_80194C68(void *buf, s32 i, s32 j, s32 key);
s32 fn_801E4BF4(s8 k);
s32 fn_801E4BBC(s8 k);
typedef struct { s32 hide; s32 pad4; UiObj obj; } Win;
typedef struct { u8 pad[0x24]; Win* in; } Pnl;
typedef struct {
    u8 pad0[0x44]; s32 f44;
    u8 pad48[0x6c - 0x48]; s32 f6c;
} Ctrl_80176A44;
typedef struct { Ctrl_80176A44* ctrl; } Holder_80176A44;
typedef struct { u8 pad[0x24]; Holder_80176A44* holder; } Outer_80176A44;
extern u8 lbl_80307638[0xA50];
extern void CampMenuHideAllPanels(void);
extern s32 fn_80195CD0(s8 a, s8 b, s32 c, s8 d);
extern void fn_801D4F0C(void* spr, s32 a, s32 b, s32 c, f32 f1, f32 f2, f32 f3, f32 f4);
typedef struct {
    u8 pad0[0xc];
    s8 count;
    u8 pad1[3];
    Pnl* pnl[0x7b];
} CampWork_80177AC8;
typedef struct { u8 pad0[4]; s32 f4; s32 f8; u8 pad[0x1c - 0xc]; u32 mask; } Ctrl_80177AC8;
typedef struct { Ctrl_80177AC8* ctrl; } Holder_80177AC8;
typedef struct { u8 pad[0x24]; Holder_80177AC8* holder; } Outer_80177AC8;
typedef struct {
    u8 pad0[0xc];
    s8 count;
    u8 pad1[3];
    Pnl* pnl[0x7b];
} CampWork_801790C8;
typedef struct { u8 pad0[4]; s32 f4; s32 f8; u8 pad[0x1c - 0xc]; u32 mask; } Ctrl_801790C8;
typedef struct { Ctrl_801790C8* ctrl; } Holder_801790C8;
typedef struct { u8 pad[0x24]; Holder_801790C8* holder; } Outer_801790C8;
typedef struct {
    u8 pad0[0xc];
    s8 count;
    u8 pad1[3];
    Pnl* pnl[0x7b];
} CampWork_8017A9FC;
typedef struct { u8 pad0[4]; s32 f4; s32 f8; u8 pad[0x1c - 0xc]; u32 mask; } Ctrl_8017A9FC;
typedef struct { Ctrl_8017A9FC* ctrl; } Holder_8017A9FC;
typedef struct { u8 pad[0x24]; Holder_8017A9FC* holder; } Outer_8017A9FC;
typedef struct {
    u8 pad0[0xc];
    s8 count;
    u8 pad1[3];
    Pnl* pnl[0x7b];
} CampWork_8017B19C;
typedef struct { u8 pad0[4]; s32 f4; s32 f8; u8 pad[0x1c - 0xc]; u32 mask; } Ctrl_8017B19C;
typedef struct { Ctrl_8017B19C* ctrl; } Holder_8017B19C;
typedef struct { u8 pad[0x24]; Holder_8017B19C* holder; } Outer_8017B19C;
typedef struct {
    u8 pad0[0xc];
    s8 count;
    u8 pad1[3];
    Pnl* pnl[0x7b];
} CampWork_8017B2AC;
typedef struct { u8 pad0[4]; s32 f4; s32 f8; u8 pad[0x1c - 0xc]; u32 mask; } Ctrl_8017B2AC;
typedef struct { Ctrl_8017B2AC* ctrl; } Holder_8017B2AC;
typedef struct { u8 pad[0x24]; Holder_8017B2AC* holder; } Outer_8017B2AC;
typedef struct {
    u8 pad0[0xc];
    s8 count;
    u8 pad1[3];
    Pnl* pnl[0x7b];
} CampWork_8017B3BC;
typedef struct { u8 pad0[4]; s32 f4; s32 f8; u8 pad[0x1c - 0xc]; u32 mask; } Ctrl_8017B3BC;
typedef struct { Ctrl_8017B3BC* ctrl; } Holder_8017B3BC;
typedef struct { u8 pad[0x24]; Holder_8017B3BC* holder; } Outer_8017B3BC;
typedef struct { u8 pad[0x74]; f32 f74; } Win74;
typedef struct { u8 pad[0x24]; Win74* in; } Pnl74;
typedef struct {
    u8 pad0[4]; s32 f4; u8 pad8[4]; s32 fc;
    u8 pad10[0x24 - 0x10]; s32 f24; u8 pad28[4]; s32 f2c;
} Ctrl_8017B4E4;
typedef struct { Ctrl_8017B4E4* ctrl; } Holder_8017B4E4;
typedef struct { u8 pad[0x24]; Holder_8017B4E4* holder; } Outer_8017B4E4;
extern void fn_800FF348(void* spr, s32 id, f32 a, f32 b, f32 c);
extern void fn_801954D0(void* p);
typedef struct {
    u8 pad0[4]; s32 f4; u8 pad8[4]; s32 fc;
    u8 pad10[0x24 - 0x10]; s32 f24; u8 pad28[4]; s32 f2c;
} Ctrl_8017CC70;
typedef struct { Ctrl_8017CC70* ctrl; } Holder_8017CC70;
typedef struct { u8 pad[0x24]; Holder_8017CC70* holder; } Outer_8017CC70;
typedef struct {
    u8 pad0[4]; s32 f4; u8 pad8[4]; s32 fc;
    u8 pad10[0x24 - 0x10]; s32 f24; u8 pad28[4]; s32 f2c;
} Ctrl_8017D250;
typedef struct { Ctrl_8017D250* ctrl; } Holder_8017D250;
typedef struct { u8 pad[0x24]; Holder_8017D250* holder; } Outer_8017D250;
typedef struct {
    u8 pad0[4]; s32 f4; u8 pad8[4]; s32 fc;
    u8 pad10[0x24 - 0x10]; s32 f24; u8 pad28[4]; s32 f2c;
} Ctrl_8017E4E4;
typedef struct { Ctrl_8017E4E4* ctrl; } Holder_8017E4E4;
typedef struct { u8 pad[0x24]; Holder_8017E4E4* holder; } Outer_8017E4E4;
typedef struct {
    u8 pad0[0x44]; s32 f44;
    u8 pad48[0x6c - 0x48]; s32 f6c; s32 state;
} Ctrl_8018006C;
typedef struct { Ctrl_8018006C* ctrl; } Holder_8018006C;
typedef struct { u8 pad[0x24]; Holder_8018006C* holder; } Outer_8018006C;
extern s32 lbl_80347154;
extern void fn_80180174(s8 a, s8 mode);
extern s32 CampMenuAnyPanelBusy(void);
extern s32 fn_801C09F8(s32 a, s32 b);
extern void CampMenuFinishAllPanels(void);
typedef struct {
    u8 pad0[0x44]; s32 f44;
    u8 pad48[0x6c - 0x48]; s32 f6c; s32 state;
} Ctrl_80180174;
typedef struct { Ctrl_80180174* ctrl; } Holder_80180174;
typedef struct { u8 pad[0x24]; Holder_80180174* holder; } Outer_80180174;
extern void fn_80180174(s8 unused, s8 mode);
typedef struct {
    u8 pad0[4]; s32 f4; u8 pad8[4]; s32 fc;
    u8 pad10[0x24 - 0x10]; s32 f24; u8 pad28[4]; s32 f2c;
} Ctrl_80180A84;
typedef struct { Ctrl_80180A84* ctrl; } Holder_80180A84;
typedef struct { u8 pad[0x24]; Holder_80180A84* holder; } Outer_80180A84;
#define PNL(off) (*(Pnl**)(CWB + (off)))
extern void CampMenuHideAllPanels(void);
extern s32 fn_80194CB8(void);
typedef struct {
    u8 pad0[4]; s32 f4; u8 pad8[4]; s32 fc;
    u8 pad10[0x24 - 0x10]; s32 f24; u8 pad28[4]; s32 f2c; u8 pad30[0x44 - 0x30]; s32 f44;
} Ctrl_80183C54;
typedef struct { Ctrl_80183C54* ctrl; } Holder_80183C54;
typedef struct { u8 pad[0x24]; Holder_80183C54* holder; } Outer_80183C54;
typedef struct {
    u8 pad0[4]; s32 f4; u8 pad8[4]; s32 fc;
    u8 pad10[0x24 - 0x10]; s32 f24; u8 pad28[4]; s32 f2c;
} Ctrl_80184CE8;
typedef struct { Ctrl_80184CE8* ctrl; } Holder_80184CE8;
typedef struct { u8 pad[0x24]; Holder_80184CE8* holder; } Outer_80184CE8;
typedef struct { u8 pad[0xc]; s8 count; u8 pad1[3]; Pnl* pnl[0x80]; } CampW;
extern void fn_80199BB8(UiObj* o, f32 x, f32 y);
extern void fn_80199BAC(UiObj* o, f32 x, f32 y);
extern s32 camp_screen;
extern void fn_801959D4(s32 n);
extern const char lbl_802B44A8[];
extern void* fn_801E49D8(const char* name);
extern s32 fn_801E4974(void* h, s32 i);
extern s32 fn_801E48A8(void* h);
extern void* fn_801E4984(void* h, s32 i);
extern void MemCopy(void* dst, const void* src, s32 size);
extern void* fn_801E1584(void* h, s32 size);
extern void** fn_801DB124(void* p);
extern void fn_801D6998(void* dst, void* src);
typedef struct {
    f32 x0;            /* 0x00 */
    f32 x4;            /* 0x04 */
    s32 x8;            /* 0x08 */
    s32 xC;            /* 0x0C */
    f32 x10, x14;      /* 0x10 */
    f32 x18, x1C;      /* 0x18 */
    void** a_ptr;        /* 0x20 */
    f32* a_pos;        /* 0x24 */
    u8 pad28[4];
    void** b_ptr;        /* 0x2C */
    f32* b_pos;        /* 0x30 */
    u8 pad34[4];
    void** c_ptr;        /* 0x38 */
    f32* c_pos;        /* 0x3C */
    u32 x40;
    void* x44;           /* 0x44 */
} Obj_80186D2C;
extern void fn_8019A15C(void* p, s32 a, s32 b, s32 c);
typedef struct {
    u8 pad0[1];
    u8 kind; /* 0x01 */
} Cfg;
typedef struct {
    s32 kind; /* 0x00 */
    s32 x4;
    UiObj obj; /* 0x08 */
    u8 pad[0xBC - 0x08 - sizeof(UiObj)];
    Cfg* cfg; /* 0xBC */
} Inner_80186E4C;
typedef struct {
    u8 pad[0x18];
    u8 flags; /* 0x18 */
    u8 state; /* 0x19 */
    u8 pad1A[0x24 - 0x1A];
    Inner_80186E4C* inner; /* 0x24 */
} Self_80186E4C;
extern void fn_80199F38(void* r);
extern void fn_80199F58(void* r);
extern void fn_8018796C(void* p);
extern void fn_80186F58(void* p);
typedef struct {
    f32 x0;            /* 0x00 */
    f32 x4;            /* 0x04 */
    s32 x8;            /* 0x08 */
    s32 xC;            /* 0x0C */
    f32 x10, x14;      /* 0x10 */
    f32 x18, x1C;      /* 0x18 */
    void** a_ptr;        /* 0x20 */
    f32* a_pos;        /* 0x24 */
    u8 pad28[4];
    void** b_ptr;        /* 0x2C */
    f32* b_pos;        /* 0x30 */
    u8 pad34[4];
    void** c_ptr;        /* 0x38 */
    f32* c_pos;        /* 0x3C */
    u32 x40;
    void* x44;           /* 0x44 */
} Obj_80187D78;
typedef struct {
    f32 x0;            /* 0x00 */
    f32 x4;            /* 0x04 */
    s32 x8;            /* 0x08 */
    s32 xC;            /* 0x0C */
    f32 x10, x14;      /* 0x10 */
    f32 x18, x1C;      /* 0x18 */
    void** a_ptr;        /* 0x20 */
    f32* a_pos;        /* 0x24 */
    u8 pad28[4];
    void** b_ptr;        /* 0x2C */
    f32* b_pos;        /* 0x30 */
    u8 pad34[4];
    void** c_ptr;        /* 0x38 */
    f32* c_pos;        /* 0x3C */
    u32 x40;
    void* x44;           /* 0x44 */
} Obj_8018968C;
typedef struct {
    u8 b0;    /* 0x00 */
    u8 a;     /* 0x01 */
    u8 c;     /* 0x02 */
    u8 pad3[3];
    s16 d;    /* 0x06 */
    u8 pad8[4];
    u32 e;    /* 0x0C */
    u32 f;    /* 0x10 */
} SrcRec;
typedef struct {
    s32 x0;
    s32 count; /* 0x04 */
    u8 pad8[8];
    SrcRec rec[6]; /* 0x10 */
} Tmp;
typedef struct {
    u8 pad0;
    u8 a;  /* 0x01 */
    u8 b;  /* 0x02 */
    u8 c;  /* 0x03 */
    s32 d; /* 0x04 */
    u32 e; /* 0x08 */
    u32 f; /* 0x0C */
} DstRec;
typedef struct Dst_80189958 {
    u8 id;        /* 0x00 */
    u8 pad1[2];
    u8 ok;        /* 0x03 */
    DstRec rec[6]; /* 0x04 */
} Dst_80189958;
typedef struct {
    u8 pad0[0xF];
    s8 kind;  /* 0x0F */
    s16 id;   /* 0x10 */
    u8 pad12[0x5C - 0x12];
} CampRec_80189A70;
typedef struct {
    f32 x0;            /* 0x00 */
    f32 x4;            /* 0x04 */
    s32 x8;            /* 0x08 */
    s32 xC;            /* 0x0C */
    f32 x10, x14;      /* 0x10 */
    f32 x18, x1C;      /* 0x18 */
    void** a_ptr;        /* 0x20 */
    f32* a_pos;        /* 0x24 */
    u8 pad28[4];
    void** b_ptr;        /* 0x2C */
    f32* b_pos;        /* 0x30 */
    u8 pad34[4];
    void** c_ptr;        /* 0x38 */
    f32* c_pos;        /* 0x3C */
    u32 x40;
    void* x44;           /* 0x44 */
} Obj_8018A07C;
typedef struct {
    f32 x0;            /* 0x00 */
    f32 x4;            /* 0x04 */
    s32 x8;            /* 0x08 */
    s32 xC;            /* 0x0C */
    f32 x10, x14;      /* 0x10 */
    f32 x18, x1C;      /* 0x18 */
    void** a_ptr;        /* 0x20 */
    f32* a_pos;        /* 0x24 */
    u8 pad28[4];
    void** b_ptr;        /* 0x2C */
    f32* b_pos;        /* 0x30 */
    u8 pad34[4];
    void** c_ptr;        /* 0x38 */
    f32* c_pos;        /* 0x3C */
    u32 x40;
    void* x44;           /* 0x44 */
} Obj_80191D78;
extern void* lbl_80347100;
extern void* fn_801CC0A0(void* p);
typedef struct {
    const char *name; /* 0x00 */
    u8 pad4[0x20];
    s32 id; /* 0x24 */
} Ent_801929FC;
extern Ent_801929FC lbl_802ED258[0x58];
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
} Hold;
typedef struct {
    u8 pad0[0x1c];
    f32 x1c;
    u8 pad20[0x1d8 - 0x20];
    Hold *x1d8;
} Ent;
typedef struct { u32 a; s32 b, c; } V3;
typedef struct { u8 pad[0x14]; s32 x14, x18, x1c; } Tgt_8015EBF4;
typedef struct { u8 pad[0x2c]; Tgt_8015EBF4 *x2c; } Sub_8015EBF4;
typedef struct {
    u8 pad0[4];
    void *x4;
    void *x8;
    u8 padc[0x48 - 0xc];
    s32 x48, x4c, x50;
    s32 x54, x58, x5c;
    u8 pad60[0x74 - 0x60];
    u32 x74;
    V3 x78;
    Sub_8015EBF4 *x84;
    u8 pad88[0x94 - 0x88];
    s32 x94;
    u8 pad98[0xe0 - 0x98];
    s32 xe0;
    u8 pade4[0x12c - 0xe4];
    s32 x12c;
    u8 pad130[0x31c - 0x130];
    void (*x31c_8015EBF4)(void *, void *);
} Hold_8015EBF4;
typedef struct { u8 pad[0x20]; void *x20; } Ref;
typedef struct {
    u8 pad0[0x17a];
    u16 h17a;
    u8 pad17c[0x1c8 - 0x17c];
    Ref *x1c8;
    u8 pad1cc[0x1d4 - 0x1cc];
    s32 x1d4;
    Hold_8015EBF4 *x1d8;
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
typedef struct { void *a; void *b; } Pair;
typedef struct {
    u32 count;
    u8 pad4[4];
    s32 *x8;
    void **xc;
    Pair *x10;
} Spl;
extern f32 fn_80212A78(void *a, f32 x, f32 t);
extern void fn_80213178(void *p0, void *p1, void *p2, void *p3, void *p4, f32 x, f32 t);
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
typedef struct {
    u32 count;
    u8 pad4[4];
    void *x8;
    void **xc;
    Pair *x10;
} Spl_80165C84;
extern void fn_801E1784(void *p);
typedef struct { f32 x, y, z; } Vec;
typedef struct { s32 a, b, c; } V3i;
typedef struct {
    Vec p0;
    u8 padc[0x18 - 0xc];
    f32 x18;
    u8 pad1c[0x28 - 0x1c];
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
    u32 x1c;
    Key *x20;
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
void fn_801680B4(void);
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
void fn_80168E54(void);
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
typedef struct Ctrl_80170450 {
    u8 pad0[0x44];
    s32 f44;
    u8 pad48[0x6c - 0x48];
    s32 f6c;
    s32 state;
} Ctrl_80170450;
typedef struct { Ctrl_80170450* ctrl; } Holder_80170450;
typedef struct { u8 pad[0x24]; Holder_80170450* holder; } Outer_80170450;
extern void fn_80170704(s8 a, s32 b);
extern void fn_801705B8(void);
typedef struct {
    u8 pad0[4];
    s32 f4;
} Ctrl_801753D4;
typedef struct { Ctrl_801753D4* ctrl; } Holder_801753D4;
typedef struct { u8 pad[0x24]; Holder_801753D4* holder; } Outer_801753D4;
typedef struct { u8 pad0[4]; s32 f4; s32 f8; u8 pad[0x1c - 0xc]; u32 mask; } Ctrl_8017796C;
typedef struct { Ctrl_8017796C* ctrl; } Holder_8017796C;
typedef struct { u8 pad[0x24]; Holder_8017796C* holder; } Outer_8017796C;
typedef struct { s32 hide; u8 pad4[4]; UiObj obj; u8 pad_[0xbc - 8 - sizeof(UiObj)]; void* sub; } Win_80178F6C;
typedef struct { u8 pad[0x24]; Win_80178F6C* in; } Pnl_80178F6C;
typedef struct { u8 pad[0xc]; s8 count; u8 pad1[3]; Pnl_80178F6C* pnl[0xcf]; f32 f34c, f350, f354; } CampW_80178F6C;
extern s32 fn_801929B8(s32 idx);
extern void fn_80199BA4(UiObj* o, u8 v);
extern void fn_80199B9C(UiObj* o, f32 v);
extern s32 fn_80195D8C(s8 a, s8 b, s32 c, s8 d);
typedef struct { u8 pad0[0x1c]; u32 mask; } Ctl;
typedef struct { Ctl* ctrl; } Hold_80178F6C;
typedef struct { u8 pad[0x24]; Hold_80178F6C* holder; } Outer_80178F6C;
typedef struct { s32 hide; u8 pad4[4]; UiObj obj; u8 pad_[0xbc - 8 - sizeof(UiObj)]; void* sub; } Win_801808D4;
typedef struct { u8 pad[0x24]; Win_801808D4* in; } Pnl_801808D4;
typedef struct { u8 pad[0xc]; s8 count; u8 pad1[3]; Pnl_801808D4* pnl[0xcf]; f32 f34c, f350, f354; } CampW_801808D4;
typedef struct { s32 hide; u8 pad4[4]; UiObj obj; u8 pad_[0xbc - 8 - sizeof(UiObj)]; void* sub; } Win_80180B80;
typedef struct { u8 pad[0x24]; Win_80180B80* in; } Pnl_80180B80;
typedef struct { u8 pad[0xc]; s8 count; u8 pad1[3]; Pnl_80180B80* pnl[0xcf]; f32 f34c, f350, f354; } CampW_80180B80;
typedef struct { s32 hide; u8 pad4[4]; UiObj obj; u8 pad_[0xbc - 8 - sizeof(UiObj)]; void* sub; } Win_801854B8;
typedef struct { u8 pad[0x24]; Win_801854B8* in; } Pnl_801854B8;
typedef struct { u8 pad[0xc]; s8 count; u8 pad1[3]; Pnl_801854B8* pnl[0xcf]; f32 f34c, f350, f354; } CampW_801854B8;
typedef struct { u8 pad0[4]; s32 f4; u8 pad8[4]; u32 mask; } Ctl_801854B8;
typedef struct { Ctl_801854B8* ctrl; } Hold_801854B8;
typedef struct { u8 pad[0x24]; Hold_801854B8* holder; } Outer_801854B8;
extern s32 fn_80194CC8(void);
extern s32 lbl_80347124;
typedef struct { s32 hide; u8 pad4[4]; UiObj obj; u8 pad_[0xbc - 8 - sizeof(UiObj)]; void* sub; } Win_801861F8;
typedef struct { u8 pad[0x24]; Win_801861F8* in; } Pnl_801861F8;
typedef struct { u8 pad[0xc]; s8 count; u8 pad1[3]; Pnl_801861F8* pnl[0xcf]; f32 f34c, f350, f354; } CampW_801861F8;
typedef struct { u8 pad0[4]; s32 f4; } Ctl_801861F8;
typedef struct { Ctl_801861F8* ctrl; } Hold_801861F8;
typedef struct { u8 pad[0x24]; Hold_801861F8* holder; } Outer_801861F8;
typedef struct { s32 hide; u8 pad4[4]; UiObj obj; u8 pad_[0xbc - 8 - sizeof(UiObj)]; void* sub; } Win_801867B8;
typedef struct { u8 pad[0x24]; Win_801867B8* in; } Pnl_801867B8;
typedef struct { u8 pad[0xc]; s8 count; u8 pad1[3]; Pnl_801867B8* pnl[0xcf]; f32 f34c, f350, f354; } CampW_801867B8;
typedef struct {
    s32 kind;   /* 0x00 */
    s32 type;   /* 0x04 */
    UiObj obj;  /* 0x08 */
    u8 pad[0x8c - 8 - sizeof(UiObj)];
    f32 f8c;
} Inner;
typedef struct {
    u8 pad00[0x18];
    u8 flags;    /* 0x18 */
    u8 state;    /* 0x19 */
    u8 pad1A[0x24 - 0x1A];
    Inner* inner; /* 0x24 */
} Self;
typedef struct { u8 pad[0x74]; f32 f74; } Ctl_801867B8;
typedef struct { Ctl_801867B8* ctrl; } Hold_801867B8;
typedef struct { u8 pad[0x24]; Hold_801867B8* holder; } Outer_801867B8;
extern void fn_800FF3EC(void* p);
typedef struct { s32 hide; u8 pad4[4]; UiObj obj; u8 pad_[0xbc - 8 - sizeof(UiObj)]; void* sub; } Win_8018858C;
typedef struct { u8 pad[0x24]; Win_8018858C* in; } Pnl_8018858C;
typedef struct { u8 pad[0xc]; s8 count; u8 pad1[3]; Pnl_8018858C* pnl[0xcf]; f32 f34c, f350, f354; } CampW_8018858C;
typedef struct { u8 pad[0x74]; f32 f74; } Ctl_8018858C;
typedef struct { Ctl_8018858C* ctrl; } Hold_8018858C;
typedef struct { u8 pad[0x24]; Hold_8018858C* holder; } Outer_8018858C;
typedef struct { s32 hide; u8 pad4[4]; UiObj obj; u8 pad_[0xbc - 8 - sizeof(UiObj)]; void* sub; } Win_80189B70;
typedef struct { u8 pad[0x24]; Win_80189B70* in; } Pnl_80189B70;
typedef struct { u8 pad[0xc]; s8 count; u8 pad1[3]; Pnl_80189B70* pnl[0xcf]; f32 f34c, f350, f354; } CampW_80189B70;
typedef struct { u8 pad0[4]; const char* str; } Sub;
typedef struct {
    s32 kind;   /* 0x00 */
    s32 type;   /* 0x04 */
    UiObj obj;  /* 0x08 */
    u8 pad[0x74 - 8 - sizeof(UiObj)];
    f32 f74;
    u8 pad78[0xbc - 0x78];
    Sub* sub;  /* 0xbc */
} Inner_80189B70;
typedef struct {
    u8 pad00[0x18];
    u8 flags;    /* 0x18 */
    u8 state;    /* 0x19 */
    u8 pad1A[0x24 - 0x1A];
    Inner_80189B70* inner; /* 0x24 */
} Self_80189B70;
typedef struct { s32 hide; u8 pad4[4]; UiObj obj; u8 pad_[0xbc - 8 - sizeof(UiObj)]; void* sub; } Win_8018A16C;
typedef struct { u8 pad[0x24]; Win_8018A16C* in; } Pnl_8018A16C;
typedef struct { u8 pad[0xc]; s8 count; u8 pad1[3]; Pnl_8018A16C* pnl[0xcf]; f32 f34c, f350, f354; } CampW_8018A16C;
typedef struct { s8 mode; } Sub_8018A16C;
typedef struct {
    s32 kind;   /* 0x00 */
    s32 type;   /* 0x04 */
    UiObj obj;  /* 0x08 */
    u8 pad[0xbc - 8 - sizeof(UiObj)];
    Sub_8018A16C* sub;  /* 0xbc */
} Inner_8018A16C;
typedef struct {
    u8 pad00[0x18];
    u8 flags;    /* 0x18 */
    u8 state;    /* 0x19 */
    u8 pad1A[0x24 - 0x1A];
    Inner_8018A16C* inner; /* 0x24 */
} Self_8018A16C;
extern void fn_80296EEC(s32 a, s32 b, s32 c);
extern void fn_8018A2D8(void* p);
extern void fn_8018D250(void* p);
extern void fn_8018C8B4(void* p);
extern void fn_80194F88(void* p);
typedef struct Sub_8016C4C8 {
    s8 b0;
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
} Obj_8016C4C8;
void fn_8016C204();
void fn_8016C61C(void);
typedef struct { s32 hide; u8 pad4[4]; UiObj obj; u8 pad_[0xbc - 8 - sizeof(UiObj)]; void* sub; } Win_8017A510;
typedef struct { u8 pad[0x24]; Win_8017A510* in; } Pnl_8017A510;
typedef struct { u8 pad[0xc]; s8 count; u8 pad1[3]; Pnl_8017A510* pnl[0xcf]; f32 f34c, f350, f354; } CampW_8017A510;
typedef struct { u8 pad0[4]; s32 f4; s32 f8; void* fc; u8 pad10[0x44 - 0x10]; s32 f44; s32 f48; } Ctl_8017A510;
typedef struct { Ctl_8017A510* ctrl; } Hold_8017A510;
typedef struct { u8 pad[0x24]; Hold_8017A510* holder; } Outer_8017A510;
typedef struct { u8 pad0[4]; const char *s4, *s8, *sc; void* p; } Ent_8017A510;
extern Ent_8017A510 lbl_802E9908[];
extern s32 fn_8019A21C(void* a, s32 b, s32 c, s32 d, s32 e);
typedef struct { s32 hide; u8 pad4[4]; UiObj obj; u8 pad_[0xbc - 8 - sizeof(UiObj)]; void* sub; } Win_8017A754;
typedef struct { u8 pad[0x24]; Win_8017A754* in; } Pnl_8017A754;
typedef struct { u8 pad[0xc]; s8 count; u8 pad1[3]; Pnl_8017A754* pnl[0xcf]; f32 f34c, f350, f354; } CampW_8017A754;
extern u8 lbl_8030B7F4[0x16A0];
extern s32 (*lbl_802E9418[3])(void);
typedef struct { s32 hide; u8 pad4[4]; UiObj obj; u8 pad_[0xbc - 8 - sizeof(UiObj)]; void* sub; } Win_8017A8A8;
typedef struct { u8 pad[0x24]; Win_8017A8A8* in; } Pnl_8017A8A8;
typedef struct { u8 pad[0xc]; s8 count; u8 pad1[3]; Pnl_8017A8A8* pnl[0xcf]; f32 f34c, f350, f354; } CampW_8017A8A8;
typedef struct { s32 hide; u8 pad4[4]; UiObj obj; u8 pad_[0xbc - 8 - sizeof(UiObj)]; void* sub; } Win_801841DC;
typedef struct { u8 pad[0x24]; Win_801841DC* in; } Pnl_801841DC;
typedef struct { u8 pad[0xc]; s8 count; u8 pad1[3]; Pnl_801841DC* pnl[0xcf]; f32 f34c, f350, f354; } CampW_801841DC;
typedef struct { u8 pad0[0xc]; u32 mask; u8 pad10[0x1c - 0x10]; s32 f1c; u8 pad20[0x4c - 0x20]; s32 f4c; } Ctl_801841DC;
typedef struct { Ctl_801841DC* ctrl; } Hold_801841DC;
typedef struct { u8 pad[0x24]; Hold_801841DC* holder; } Outer_801841DC;
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
typedef struct {
    u8 pad0[0x14];
    u32 word;
} Mat_8016CAB4;
typedef struct {
    u8 pad0[4];
    Mat_8016CAB4* mat;
    u8 pad8[0x14 - 8];
    f32 x;
    f32 y;
} Item_8016CAB4;
typedef struct {
    s8 kind;
    u8 pad1[3];
    f32 f4;
    f32 f8;
    u8 padc[0x20 - 0xc];
    f32 f20;
    u8 pad24[0x2c - 0x24];
    f32 f2c;
    u8 pad30[4];
    f32 f34;
} St_8016CAB4;
typedef struct {
    u8 pad0[0x24];
    St_8016CAB4* st;
    Item_8016CAB4** items;
} Obj_8016CAB4;
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
typedef struct { s32 hide; u8 pad4[4]; UiObj obj; u8 pad_[0x74 - 8 - sizeof(UiObj)]; f32 f74; u8 pad78[0xbc - 0x78]; } Win_8017D35C;
typedef struct { u8 pad[0x24]; Win_8017D35C* in; } Pnl_8017D35C;
typedef struct { u8 pad[0xc]; s8 count; u8 pad1[3]; Pnl_8017D35C* pnl[0xcf]; } CampW_8017D35C;
typedef struct { u8 pad[0x24]; s32 f24; } Ctrl_8017D35C;
typedef struct { u8 pad[0x24]; Ctrl_8017D35C** holder; } Outer_8017D35C;
typedef struct { s32 hide; u8 pad4[4]; UiObj obj; u8 pad_[0x74 - 8 - sizeof(UiObj)]; f32 f74; u8 pad78[0xbc - 0x78]; } Win_8017EBD8;
typedef struct { u8 pad[0x24]; Win_8017EBD8* in; } Pnl_8017EBD8;
typedef struct { u8 pad[0xc]; s8 count; u8 pad1[3]; Pnl_8017EBD8* pnl[0xcf]; } CampW_8017EBD8;
typedef struct { u8 pad0[4]; s32 f4; u8 pad8[4]; u32 fc; u8 pad10[0x24 - 0x10]; s32 f24; } Ctrl_8017EBD8;
typedef struct { u8 pad[0x24]; Ctrl_8017EBD8** holder; } Outer_8017EBD8;
typedef struct { s32 hide; u8 pad4[4]; UiObj obj; u8 pad_[0x74 - 8 - sizeof(UiObj)]; f32 f74; u8 pad78[0xbc - 0x78]; } Win_8017EE48;
typedef struct { u8 pad[0x24]; Win_8017EE48* in; } Pnl_8017EE48;
typedef struct { u8 pad[0xc]; s8 count; u8 pad1[3]; Pnl_8017EE48* pnl[0xcf]; } CampW_8017EE48;
typedef struct { u8 pad0[4]; s32 f4; u8 pad8[4]; u32 fc; u8 pad10[0x24 - 0x10]; s32 f24; } Ctrl_8017EE48;
typedef struct { u8 pad[0x24]; Ctrl_8017EE48** holder; } Outer_8017EE48;
typedef struct { s16 x, y; f32 a, b; s8 idx; } Req_80188274;
typedef struct { u8 pad0[0x14]; f32 x, y; } Spr_80188274;
typedef struct { void *spr; } Sp_8018C6A8;
typedef struct {
    f32 f0, f4;
    s32 i8, ic;
    f32 f10, f14, f18, f1c;
    u8 pad20[0x2c - 0x20];
    Sp_8018C6A8 *sp;
    f32 *fp;
    u8 pad34[0x44 - 0x34];
    void *spr44;
} Pos_8018C6A8;
typedef struct { u8 pad0[0x74]; Pos_8018C6A8 pos; } Obj_8018C6A8;
typedef struct { u8 pad0[0x2c]; f32 x, y; u8 pad34[0x74 - 0x34]; f32 z; } Obj_8018FB9C;
extern s32 fn_80195184(s32 x);
extern s32 fn_80195148(s32 x);
extern s32 fn_801950D0(s32 x);
extern s32 fn_8019510C(s32 x);
extern void fn_8019A374(s32 spr, f32 x, f32 y, f32 z, u32 col, s32 n);
typedef struct { s32 row, col, dir, mode, found_idx, found; } Cur_80192EDC;
typedef struct { s32 x0; u32 id; s32 x8; } Ent_80192EDC;
extern Ent_80192EDC lbl_802EBA00[24];
typedef struct { s32 hide; } Win_80177D7C;
typedef struct { u8 pad[0x24]; Win_80177D7C* in; } Pnl_80177D7C;
typedef struct { u8 pad0[4]; s32 f4; s32 f8; u8 pad[0x1c - 0xc]; u32 mask; } Ctrl_80177D7C;
typedef struct { Ctrl_80177D7C* ctrl; } Holder_80177D7C;
typedef struct { u8 pad[0x24]; Holder_80177D7C* holder; } Outer_80177D7C;
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
typedef struct {
    u8 pad0[8];
    UiObj ui;
} Win_80173104;
typedef struct {
    u8 pad0[0x24];
    Win_80173104* win;
} Pnl_80173104;
#define PNL_80173104(off) (*(Pnl_80173104**)(CWB + (off)))
typedef struct {
    u8 pad0[8];
    UiObj ui;
} Win_80174F40;
typedef struct {
    u8 pad0[0x24];
    Win_80174F40* win;
} Pnl_80174F40;
typedef struct {
    u8 pad0[0x24];
    s32 a;
    s32 b;
} Ctrl_80174F40;
typedef struct {
    u8 pad0[0x24];
    Ctrl_80174F40** hold;
} Outer_80174F40;
#define PNL_80174F40(off) (*(Pnl_80174F40**)(CWB + (off)))
typedef struct {
    u8 pad0[8];
    UiObj ui;
} Win_801764E4;
typedef struct {
    u8 pad0[0x24];
    Win_801764E4* win;
} Pnl_801764E4;
#define PNL_801764E4(off) (*(Pnl_801764E4**)(CWB + (off)))
typedef struct {
    u8 pad0[8];
    UiObj ui;
} Win_80176868;
typedef struct {
    u8 pad0[0x24];
    Win_80176868* win;
} Pnl_80176868;
#define PNL_80176868(off) (*(Pnl_80176868**)(CWB + (off)))
typedef struct {
    u8 pad0[8];
    UiObj ui;
} Win_80178D2C;
typedef struct {
    u8 pad0[0x24];
    Win_80178D2C* win;
} Pnl_80178D2C;
typedef struct {
    u8 pad0[0x24];
    s32 a;
    s32 b;
} Ctrl_80178D2C;
typedef struct {
    u8 pad0[0x24];
    Ctrl_80178D2C** hold;
} Outer_80178D2C;
#define PNL_80178D2C(off) (*(Pnl_80178D2C**)(CWB + (off)))
typedef struct Spr_8016E3E0 {
    u8 pad[0x14];
    f32 x;
    f32 y;
} Spr_8016E3E0;
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
    void *x0;
    u8 pad4[4];
    s32 x8;
    u8 xc;
    u8 xd;
    u8 xe;
    u8 padf;
    s16 x10;
    u8 pad12[6];
    s32 x18;
    f32 x1c;
    f32 x20;
    f32 x24;
    f32 x28;
    s32 x2c;
    Fx_801677D0 *x30;
    Fx_801677D0 *x34;
    s32 x38;
    f32 x3c;
    f32 x40;
    f32 x44;
    f32 x48;
} St_801677D0;
struct Fx_801677D0 {
    u8 pad0[0x24];
    St_801677D0 *st;
};
extern void fn_801679A4(void);
extern s32 fn_80167C34(St_801677D0 *s);
extern void fn_802172C8(void *a, s32 b);
typedef struct {
    u8 pad0[0x38];
    f32 x, y, z;
} Cam_80167EF0;
typedef struct {
    u8 pad0[0x18];
    u32 x18;
    f32 x1c;
    f32 x20;
    f32 x24;
    f32 x28;
} Arg_80167EF0;
typedef struct {
    f32 x, y, z;
} Vec_80167EF0;
extern s32 fn_800C8D90(void);
extern void fn_8009FDA0(void *a, s32 b, Vec_80167EF0 *out, s32 c, Vec_80167EF0 *d, s32 e, s32 f);
extern f32 fn_80291A5C(f32 x);
typedef struct {
    u8 pad0[0x14];
    f32 x;
    f32 y;
} Eff_8016FB2C;
typedef struct {
    u8 pad0[0x24];
    UiObj* ui;
} Pnl_8016FB2C;
typedef struct {
    u8 pad0[0x44];
    s32 page;
} Sel_8016FB2C;
typedef struct {
    u8 pad0[0x24];
    Sel_8016FB2C** sel;
} Hold_8016FB2C;
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
typedef struct {
    u8 pad0[4];
    s32 sel;
    u8 pad8[4];
    s32 mask;
    u8 pad10[0x4c - 0x10];
    s32 f4c;
} Ctrl_8017379C;
typedef struct {
    Ctrl_8017379C* ctrl;
} Holder_8017379C;
typedef struct {
    u8 pad0[0x24];
    Holder_8017379C* holder;
} Outer_8017379C;
#define MID() (*(Mid_8017379C**)(CWB + 0x218))
typedef struct {
    u8 pad0[0x14];
    f32 x;
    f32 y;
} Eff_801784D8;
typedef struct {
    u8 pad0[0x2c];
    f32 rx;
    f32 ry;
} Win_801784D8;
typedef struct {
    u8 pad0[0x24];
    Win_801784D8* win;
} Pnl_801784D8;
typedef struct {
    u8 pad0[0x14];
    s32 f14;
    u8 pad18[4];
    s32 f1c;
} Ctrl_801784D8;
typedef struct {
    u8 pad0[0x24];
    Ctrl_801784D8** hold;
} Outer_801784D8;
extern s32 fn_801952D0(s32 v);
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
typedef struct { s32 hide; } Win_80179388;
typedef struct { u8 pad[0x24]; Win_80179388* in; } Pnl_80179388;
typedef struct { u8 pad[0xc]; s8 count; u8 pad1[3]; Pnl_80179388* pnl[0xcf]; } CampW_80179388;
typedef struct { u8 pad[0x1c]; u32 mask; } Ctrl_80179388;
typedef struct { u8 pad[0x24]; Ctrl_80179388** holder; } Outer_80179388;
typedef struct { s32 hide; u8 pad4[4]; UiObj obj; u8 pad_[0xbc - 8 - sizeof(UiObj)]; } Win_8017BF14;
typedef struct { u8 pad[0x24]; Win_8017BF14* in; } Pnl_8017BF14;
typedef struct { u8 pad[0xc]; s8 count; u8 pad1[3]; Pnl_8017BF14* pnl[0xcf]; } CampW_8017BF14;
typedef struct { s32 hide; u8 pad4[4]; UiObj obj; u8 pad_[0xbc - 8 - sizeof(UiObj)]; } Win_8017C0EC;
typedef struct { u8 pad[0x24]; Win_8017C0EC* in; } Pnl_8017C0EC;
typedef struct { u8 pad[0xc]; s8 count; u8 pad1[3]; Pnl_8017C0EC* pnl[0xcf]; } CampW_8017C0EC;
typedef struct { s32 hide; u8 pad4[4]; UiObj obj; u8 pad_[0xbc - 8 - sizeof(UiObj)]; } Win_8017F310;
typedef struct { u8 pad[0x24]; Win_8017F310* in; } Pnl_8017F310;
typedef struct { u8 pad[0xc]; s8 count; u8 pad1[3]; Pnl_8017F310* pnl[0xcf]; } CampW_8017F310;
typedef struct { u8 pad0[0xc]; u32 fc; } Ctrl_8017F310;
typedef struct { u8 pad[0x24]; Ctrl_8017F310** holder; } Outer_8017F310;
typedef struct { s32 hide; u8 pad4[4]; UiObj obj; u8 pad_[0xbc - 8 - sizeof(UiObj)]; } Win_80180694;
typedef struct { u8 pad[0x24]; Win_80180694* in; } Pnl_80180694;
typedef struct { u8 pad[0xc]; s8 count; u8 pad1[3]; Pnl_80180694* pnl[0xcf]; } CampW_80180694;
typedef struct { u8 pad[0x24]; s32 f24; s32 f28; } Ctrl_80180694;
typedef struct { u8 pad[0x24]; Ctrl_80180694** holder; } Outer_80180694;
typedef struct { s32 hide; } Win_80180CCC;
typedef struct { u8 pad[0x24]; Win_80180CCC* in; } Pnl_80180CCC;
typedef struct { u8 pad[0xc]; s8 count; u8 pad1[3]; Pnl_80180CCC* pnl[0xcf]; } CampW_80180CCC;
typedef struct { u8 pad[0x1c]; u32 mask; } Ctrl_80180CCC;
typedef struct { u8 pad[0x24]; Ctrl_80180CCC** holder; } Outer_80180CCC;
typedef struct { s8 kind; u8 pad1[2]; s8 b3; } In_801887EC;
typedef struct { s32 x0, x4; u8 ui[0x74 - 8]; f32 z; u8 pad78[0xbc - 0x78]; In_801887EC *in; } Node_801887EC;
typedef struct { u8 pad0[0x18]; u8 flags; u8 state; u8 pad1a[0x24 - 0x1a]; Node_801887EC *node; } Obj_801887EC;
typedef struct { u8 pad0[0x24]; Node_801887EC *node; } Ent_801887EC;
typedef struct { u8 pad[0x10]; Ent_801887EC *objs[0xd0]; } Camp_801887EC;
typedef struct { u8 pad0[0x2c]; f32 x, y; } Pos_801887EC;
extern u8 lbl_802EBB54[0x13];
extern u8 lbl_802EBB48[0xA];
extern u8 lbl_802EBB34[0x11];
extern u8 lbl_802EBB68[0x14];
extern u8 lbl_802EBB7C[0x18];
extern void fn_80188A18(Node_801887EC *n);
extern void TextPushColor(void);
extern void TextSetColor(u32 c);
extern void TextSetZ(f32 z);
extern void TextPopColor(s32 n);
typedef struct { s32 id; } In_80189EA0;
typedef struct { u8 pad0[0x2c]; f32 x, y; u8 pad34[0x74 - 0x34]; f32 z; u8 pad78[0xbc - 0x78]; In_80189EA0 *in; } Obj_80189EA0;
extern s16 fn_80194378(s8 id);
typedef void (*Callback)(void);
typedef struct CbDef {
    Callback fn;
    u32 unk4;
} CbDef;
typedef struct Hold_8015EB8C {
    u8 pad0[0x260];
    Callback cb[47];
    Callback cb13;
} Hold_8015EB8C;
typedef struct Ent_8015EB8C {
    u8 pad0[0x1d8];
    Hold_8015EB8C *hold;
} Ent_8015EB8C;
extern CbDef lbl_802B4118[47];
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
/* Linear move to (destX, destY) over 6 steps. */
typedef struct Mover6 {
    f32 x;      /* 0x00 */
    f32 y;      /* 0x04 */
    f32 destX;  /* 0x08 */
    f32 destY;  /* 0x0C */
    f32 stepX;  /* 0x10 */
    f32 stepY;  /* 0x14 */
    s32 steps;  /* 0x18 */
} Mover6;
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
typedef struct {
    u8 pad0[4];
    s32 f4;
    s32 f8;
    s32 fc;
    u8 pad10[0x34];
    s32 f44;
    s32 f48;
    s32 f4c;
    u8 pad50[0x1C];
    s32 f6c;
    s32 f70;
} Ctl_8017172C;
extern s32 fn_80193F78(void);
#define OBJ(i) (&((Elem*)camp_work.objs[i])->mid->obj)
typedef struct {
    u8 pad0[4];
    s32 f4;
    s32 f8;
    s32 fc;
    u8 pad10[0x34];
    s32 f44;
    s32 f48;
    s32 f4c;
    u8 pad50[0x1C];
    s32 f6c;
    s32 f70;
} Ctl_80172E8C;
typedef struct {
    u8 pad0[4];
    s32 f4;
    s32 f8;
    s32 fc;
    u8 pad10[0x34];
    s32 f44;
    s32 f48;
    s32 f4c;
    u8 pad50[0x1C];
    s32 f6c;
    s32 f70;
} Ctl_8017D534;
typedef struct {
    u8 pad0[4];
    s32 f4;
    u8 pad8[0x1C];
    s32 f24;
} Ctl7;
typedef struct { u8 pad[0x24]; struct { Ctl7* ctl; }* holder; } Outer7;
typedef struct { u8 pad[0x74]; f32 y; } Nd;
typedef struct { u8 pad[0x24]; Nd* n; } Elem2;
#define ND(i) (((Elem2*)camp_work.objs[i])->n)
typedef struct {
    u8 pad0[4];
    s32 f4;
    s32 f8;
    s32 fc;
    u8 pad10[0x34];
    s32 f44;
    s32 f48;
    s32 f4c;
    u8 pad50[0x1C];
    s32 f6c;
    s32 f70;
} Ctl_8017DA28;
typedef struct {
    u8 pad0[4];
    s32 f4;
    s32 f8;
    s32 fc;
    u8 pad10[0x34];
    s32 f44;
    s32 f48;
    s32 f4c;
    u8 pad50[0x1C];
    s32 f6c;
    s32 f70;
} Ctl_8017E260;
typedef struct {
    u8 pad0[4];
    s32 f4;
} Ctl8;
typedef struct { u8 pad[0x24]; struct { Ctl8* ctl; }* holder; } Outer8;
#define CW(off, T) (*(T*)((u8*)&camp_work + (off)))
extern s32 fn_8017E5FC(void);
extern void fn_8017E4E4(void);
extern void fn_8017EAEC(void);
extern void fn_8017F540(void);
extern void fn_8017F310(void);
extern void fn_8017F07C(void);
extern void fn_8017EBD8(void);
extern void fn_8017EE48(void);
typedef struct {
    u8 pad0[4];
    s32 f4;
    s32 f8;
    s32 fc;
    u8 pad10[0x34];
    s32 f44;
    s32 f48;
    s32 f4c;
    u8 pad50[0x1C];
    s32 f6c;
    s32 f70;
} Ctl_8017F07C;
typedef struct {
    u8 pad0[4];
    s32 f4;
    u8 pad8[4];
    u32 fc;
    u8 pad10[0x14];
    s32 f24;
} Ctl9;
typedef struct { u8 pad[0x24]; struct { Ctl9* ctl; }* holder; } Outer9;
typedef struct {
    u8 pad0[4];
    s32 f4;
    s32 f8;
    s32 fc;
    u8 pad10[0x34];
    s32 f44;
    s32 f48;
    s32 f4c;
    u8 pad50[0x1C];
    s32 f6c;
    s32 f70;
} Ctl_8018394C;
typedef struct {
    u8 pad0[4];
    s32 f4;
} Ctl11;
typedef struct { u8 pad[0x24]; struct { Ctl11* ctl; }* holder; } Outer11;
extern s32 fn_80183D90(void);
extern void fn_80183C54(void);
extern void fn_80184CE8(void);
extern void fn_80184A78(void);
extern void fn_801847F0(void);
extern void fn_801841DC(void);
extern void fn_80184E2C(void);
extern void fn_80184558(void);
extern void fn_80184330(void);
typedef struct {
    u8 pad0[4];
    s32 f4;
    s32 f8;
    s32 fc;
    u8 pad10[0x34];
    s32 f44;
    s32 f48;
    s32 f4c;
    u8 pad50[0x1C];
    s32 f6c;
    s32 f70;
} Ctl_80184558;
typedef struct {
    u8 pad0[4];
    s32 f4;
    u8 pad8[0xC];
    s32 f14;
    u8 pad18[0x2C];
    s32 f44;
} Ctl12;
typedef struct { u8 pad[0x24]; struct { Ctl12* ctl; }* holder; } Outer12;
typedef struct Vec3_80168BD4 { f32 x, y, z; } Vec3_80168BD4;
typedef struct Sub_80168BD4 { u8 pad[0x24]; void *x24; } Sub_80168BD4;
typedef struct W_80168BD4 {
    u8 pad0[0xe];
    s8 f0e;
    u8 pad0f[0x18 - 0xf];
    u32 f18;
    Vec3_80168BD4 p1c;
    f32 f28;
    Sub_80168BD4 *x2c;
} W_80168BD4;
extern void *fn_8015F1A0(u32 id);
extern f32 njSin(s32 a);
typedef struct {
    f32* pos;
    u8 pad4[4];
    s32* rot;
} JointSub;
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
typedef struct {
    u8 pad0[4];
    s32 f4;
} Ctrl_8016E6E8;
typedef struct {
    Ctrl_8016E6E8* ctrl;
} Holder_8016E6E8;
typedef struct {
    u8 pad0[0x24];
    Holder_8016E6E8* holder;
} Outer_8016E6E8;
extern s32 fn_8018126C(void);
extern s32 fn_801812C0(void);
typedef struct {
    u8 pad0[4];
    s32 f4;
    s32 f8;
    void* fc;
} Ctrl_80173688;
typedef struct {
    Ctrl_80173688* ctrl;
} Holder_80173688;
typedef struct {
    u8 pad0[0x24];
    Holder_80173688* holder;
} Outer_80173688;
typedef struct {
    s32 hide;
} In_80173688;
typedef struct {
    u8 pad0[0x24];
    In_80173688* in;
} Pnl_80173688;
typedef struct {
    u8 pad0[0x10];
    Pnl* pnl[0xd0]; /* 0x10 */
} CampWork;
typedef struct {
    u8 pad0[0xc];
    u32 mask;   /* 0x0c */
} Ctrl;
typedef struct { Ctrl* ctrl; } Holder;
typedef struct { u8 pad[0x24]; Holder* holder; } Outer;
typedef struct { u8 pad[4]; Sprite* spr; } Icon;
typedef struct { u8 pad[0x94]; Icon* icon; } Win_80184E2C;
typedef struct { u8 pad[0x24]; Win_80184E2C* in; } Pnl_80184E2C;
typedef struct {
    u8 pad0[0xc];
    s8 count;       /* 0x0c */
    u8 padd[3];
    Pnl_80184E2C* pnl[0xd0]; /* 0x10 */
} CampWork_80184E2C;
typedef struct {
    u8 pad00[0x328];
    s8 party[4];    /* 0x328 */
} Game;
typedef struct {
    s32 v[2];
} Slots;
extern char lbl_802E98A0[11][9];
extern char lbl_803467B0[8];
extern s32 fn_80194C7C(void* base, s32 i, s32 j);
typedef struct {
    s32 kind;   /* 0x00 */
    s32 type;   /* 0x04 */
    UiObj obj;  /* 0x08 */
    u8 pad54[0x74 - 0x08 - sizeof(UiObj)];
    f32 z;      /* 0x74 */
} Inner_801918C4;
typedef struct {
    u8 pad0[2];
    char name[0x12]; /* 0x02 */
    s32 hp;          /* 0x14 */
} Info_801918C4;
typedef struct {
    u8 pad0[4];
    Info_801918C4* info;  /* 0x04 */
    u8 pad8[0x360 - 8];
} CampWork_801918C4;
typedef struct {
    u8 pad0[0x18];
    u16 id;
} Arg_80161F04;
typedef struct {
    u8 pad0[4];
    s32 f4;
    s32 f8;
    s32 fc;
    u8 pad10[0x34];
    s32 f44;
    u8 pad48[4];
    s32 f4c;
} Ctrl_801729D0;
typedef struct {
    Ctrl_801729D0* ctrl;
} Holder_801729D0;
typedef struct {
    u8 pad0[0x24];
    Holder_801729D0* holder;
} Outer_801729D0;
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
extern s32 fn_80194A8C(s32 a);
extern s32 fn_80194A18(s32 a);
extern s32 fn_80194C38(s8 a);
#define LA(n) (((Pnl_801729D0*)camp_work.objs[n])->in->la)
typedef struct Ent_80166138 { u8 pad[0x2c]; u32 f2c; } Ent_80166138;
typedef struct Tab_80166138 {
    u8 pad[0x1c];
    u32 count;
    Ent_80166138 *ents;
} Tab_80166138;
typedef struct Mod {
    u8 pad[0x170];
    u16 f170;
    u16 f172;
    u8 pad174[0x198 - 0x174];
    s32 f198;
} Mod;
typedef struct Hd {
    u8 pad0[8];
    Mod *mod;
    u8 pad_c[0x1a - 0xc];
    s16 idx;
} Hd;
typedef struct Obj_80166138 {
    u8 pad[0x1d8];
    Hd *x1d8;
} Obj_80166138;
extern s32 fn_801664A4(Obj_80166138 *o);
extern void fn_801E735C(u32 index, f32 speed, Mod *obj);
typedef struct Obj_80191E94 { u8 pad[0x18]; u8 flags; u8 kind; } Obj_80191E94;
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
/* camp_work and its element shape as in unit_8015DC6C.c (CampWorkS_801763B8, Elem_801763B8, Mid_801763B8, OBJ_801763B8). */
typedef struct CampWorkS_801763B8 {
    u8 pad0[0x10];
    void *objs[0xd0];
    u8 pad350[0x10];
} CampWorkS_801763B8;
typedef struct { u8 pad0[8]; s32 a8; u8 padc[4]; s32 a10; u8 pad14[0x5c - 0x14]; u32 f5c; } Leaf_801763B8;
typedef struct { u8 pad[8]; UiObj obj; u8 pad2[0xBC - 8 - sizeof(UiObj)]; Leaf_801763B8* leaf; } Mid_801763B8;
typedef struct { u8 pad[0x24]; Mid_801763B8* mid; } Elem_801763B8;
#define OBJ_801763B8(i) (&((Elem_801763B8*)camp_work.objs[i])->mid->obj)
/* fn_80167578: walk the object chain, return the i-th table entry's data. */
#include "types.h"

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
typedef struct IconObj_80189214 {
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
    u8 pad28[0x1c];
    s32 f44;
} IconObj_80189214;
typedef struct { void* spr; } Sp_80191A04;
typedef struct Pos_80191A04 {
    f32 f0, f4;
    s32 i8, ic;
    f32 f10, f14, f18, f1c;
    Sp_80191A04* sp20;
    f32* fp24;
    u8 pad28[4];
    Sp_80191A04* sp;
    f32* fp;
    u8 pad34[0x44 - 0x34];
    void* spr44;
} Pos_80191A04;

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

s32 fn_8016645C(Obj_8016645C *o, Arg *a) {
    Sub_8016645C *s = o->x1d8;
    if (s && a && a->x20 && a->x1c && a->x1c > (u32)(s32)s->x1a) {
        return 1;
    }
    return 0;
}

typedef struct { f32 x, y, z; } Vec3;
void fn_8016694C(Vec *a, Vec *b, V3i *out) {
    Vec d;

    if (a != 0 && b != 0 && out != 0) {
        d.x = b->x - a->x;
        d.y = b->y - a->y;
        d.z = b->z - a->z;
        fn_802135B4(&d, out);
    }
}

void fn_8016ABEC(void)
{
    fn_8016D01C();
    fn_8016C4B0();
    fn_8016B620();
    fn_8016AD08();
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

void fn_8016C4B0(void) {
    u8* p = (u8*)lbl_803470B0;
    if (p == NULL) {
        return;
    }
    p[0x19] = 2;
}

void fn_8016C780(u32 a, u32 b)
{
    OwnerB* o = lbl_803470B0;
    if (o != 0) {
        o->inner->w3c = a;
    }
    o = lbl_803470B0;
    if (o == 0) {
        return;
    }
    o->inner->w38 = b;
}

void fn_8016C7AC(u32 a, u32 b)
{
    OwnerB* o = lbl_803470B0;
    if (o != 0) {
        o->inner->w24 = a;
    }
    o = lbl_803470B0;
    if (o == 0) {
        return;
    }
    o->inner->w20 = b;
}

void fn_8016C7D8(u32 a)
{
    OwnerB* o = lbl_803470B0;
    if (o == 0) {
        return;
    }
    o->inner->w38 = a;
}

void fn_8016C7F0(u32 a)
{
    OwnerB* o = lbl_803470B0;
    if (o == 0) {
        return;
    }
    o->inner->w20 = a;
}

void fn_8016C870(u8 v) {
    if (lbl_803470B0 == 0) return;
    (*(u8**)((u8*)lbl_803470B0 + 0x24))[1] = v;
}

void fn_8016D01C(void) {
    u8* p = (u8*)lbl_803470B8;
    if (p == NULL) {
        return;
    }
    p[0x19] = 2;
}

void fn_8016D114(u8 v) {
    u8* p = (u8*)lbl_803470B8;
    if (p == NULL) {
        return;
    }
    *(u8*)(*(u8**)((u8*)p + 0x24) + 0x2) = v;
}

s32 fn_8016E1D8(void *p) {
    u32 tmp[2];
    if (!(*(u32 *)(lbl_80310B3C + 0x88) & 4)) return 0;
    fn_8016DBAC(tmp, p);
    return 1;
}

void fn_8016F0D4(Out *o, s8 idx, f32 f) {
    u8 *r;
    o->f0 = f;
    o->idx = idx;
    r = lbl_8030B7F4 + (s32)idx * 0x5c;
    o->rec = r;
    o->b0c = r[0xb];
    o->i10 = *(s16 *)(r + 0x18);
    o->i14 = *(s16 *)(r + 0x1a);
    o->i18 = (s8)r[0xd];
    o->i1c = (s8)r[0xe];
}

void fn_8016F128(Rec_8016F128* r, u8 a, u8 b, f32 v)
{
    r->a = a;
    r->b = b;
    r->f = v;
}

void fn_80177BD4(void)
{
    u8 *p;
    UiObj *obj;
    s32 i;

    i = *(s32 *)(lbl_80307638 + 0x7c);
    p = (u8 *)camp_work.objs[i];
    obj = (UiObj *)(*(u8 **)(p + 0x24) + 8);

    UiObjSetRaised(obj);
    fn_80199BB8(obj, -348.0f, 61.0f);
    fn_80199BAC(obj, -348.0f, 61.0f);

    i = *(s32 *)(lbl_80307638 + 0x16c);
    p = (u8 *)camp_work.objs[i + 0x1f];
    obj = (UiObj *)(*(u8 **)(p + 0x24) + 8);

    UiObjSetRaised(obj);
    fn_80199BB8(obj, -348.0f, 125.0f);
    fn_80199BAC(obj, -348.0f, 125.0f);
}

void fn_801791E0(void)
{
    u8 *p;
    UiObj *obj;
    s32 i;

    i = *(s32 *)(lbl_80307638 + 0x7c);
    p = (u8 *)camp_work.objs[i];
    obj = (UiObj *)(*(u8 **)(p + 0x24) + 8);

    UiObjSetRaised(obj);
    fn_80199BB8(obj, -348.0f, 61.0f);
    fn_80199BAC(obj, -348.0f, 61.0f);

    i = *(s32 *)(lbl_80307638 + 0x16c);
    p = (u8 *)camp_work.objs[i + 0x1f];
    obj = (UiObj *)(*(u8 **)(p + 0x24) + 8);

    UiObjSetRaised(obj);
    fn_80199BB8(obj, -348.0f, 125.0f);
    fn_80199BAC(obj, -348.0f, 125.0f);
}

void fn_8017B5EC(void) {
    UiObj* o;
    f32 y;
    s32 i;
    UiObj* a;

    a = &PNL(0x78)->in->obj;
    fn_80199BB8(a, -8.0f, 61.0f);
    fn_80199BAC(a, -8.0f, 61.0f);
    for (i = 0; i < 2; i++) {
        o = &(*(Pnl**)(CWB + 0x22c + i * 4))->in->obj;
        y = (f32)((i + 1) * 64 + 61);
        UiObjSetLowered(o);
        fn_80199BB8(o, -348.0f, y);
        fn_80199BAC(o, -348.0f, y);
    }
}

s32 fn_8018126C(void) {
    s32 buf[0x20];
    s32 off = *(s32 *)(lbl_80307638 + 0x7c);
    s8 v = (s8)lbl_8030B7F4[off + 0x328];
    fn_80195EA4(buf, v, 0, 0, 2);
    return buf[3];
}

void fn_80186E20(Rec_80186E20* r, u8 c, s8 b, u8 a, f32 v)
{
    r->a = a;
    r->b = b;
    r->c = c;
    r->f = v;
    r->entry = lbl_803072E8 + b * 0x2C;
}

s8 fn_80187F90(s32 x)
{
    return fn_801F4CA0(x);
}

extern void fn_80188098(Inner_8016F138 *self);
void fn_80187FB4(Self_8016F138* self) {
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
            fn_80188098(self->inner);
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

void fn_80189DB0(s32* p, s8 v)
{
    *p = v;
}

void fn_8018DFAC(Trio* t, u32 v)
{
    t->f8 = v;
}

void fn_8018DFB4(Trio* t, u32 v)
{
    t->f0 = v;
}

void fn_8018DFBC(Trio* t, u32 v)
{
    t->f4 = v;
}

void fn_8018E7F0(void* p)
{
    fn_8019A15C(p, 0, 0, 0);
}

void fn_8018E81C(Rec_8018E81C* r, s8 v, u8 b)
{
    r->v = v;
    r->b = b;
}

void fn_80192800(void)
{
    TaskDelete(lbl_80347114);
    lbl_80347114 = 0;
}

void fn_80192920(void)
{
    s16* p = (s16*)(lbl_8030B7F4 + 0x1568);
    s32 i;

    for (i = 0; i < 5; i++) {
        if (p[12 + i] != -1) {
            fn_801C1148(p[12 + i], 1);
        }
    }
    for (i = 0; i < 3; i++) {
        if (p[17 + i] != -1) {
            fn_801C1148(p[17 + i], 1);
        }
    }
}

s32 fn_801929B8(s32 idx) {
    lbl_80308088[idx] = MenuPlaySe((s16)idx);
    return lbl_80308088[idx];
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

void fn_801671C0(Obj_801671C0_UNIT0000* obj)
{
    Sub_UNIT0000* sub;
    if (obj != NULL && (sub = obj->sub) != NULL) {
        f32* pos = sub->pos;
        f32 x = obj->pos[0];
        f32 y = obj->pos[1];
        f32 z = obj->pos[2];
        pos[2] = z;
        pos[1] = y;
        pos[0] = x;
        obj->sub->words[0] = obj->vals[0];
        obj->sub->words[1] = obj->vals[1];
        obj->sub->words[2] = obj->vals[2];
        fn_80222838(obj->sub);
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
    if (m->x18 <= 0) {
        m->x0 = m->x8;
        m->x4 = m->xc;
        return 1;
    }
    m->x0 = m->x0 + m->x10;
    m->x4 = m->x4 + m->x14;
    m->x18 = m->x18 - 1;
    return 0;
}

void fn_8016AC18(void)
{
    s32 k;
    switch ((s8)lbl_80310A1C[6]) {
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
    switch ((s8)lbl_80310A1C[6]) {
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

s32 fn_801812C0(void)
{
    s32 buf[0x20];
    s32 off = *(s32*)(lbl_80307638 + 0x7c);
    s8 v = (s8)lbl_8030B7F4[off + 0x328];
    s8 r;
    fn_80195EA4(buf, v, 0, 0, 2);
    r = ((s8*)buf)[0xb];
    return r;
}

void fn_80187F30(Holder_80187F30* h, Target* t)
{
    h->b4 = fn_801F4CA0();
    h->target = t;
    h->target->x1c = (s8)h->b4;
    h->target->x20 = (s8)h->b4;
}

void fn_80189900(u8* p, s32 a4, s32 a5, s32 a6, s8 a7)
{
    u8 local[0x80];
    s8 r;
    p[0] = a6;
    r = (s8)a5;
    p[2] = a4;
    p[1] = a5;
    if (r == -1) {
        p[3] = 0;
    } else {
        fn_80189958((struct Dst_80189958 *)p, (s32)local, a4, (s8)a5, p[0], a7);
    }
}

void fn_8015F2E8(u32 owner) {
    Obj8015F2E8* o = lbl_80347070;
    Node8015F2E8* n;
    if (o == 0) {
        return;
    }
    n = o->n8c;
    if (n != 0 && n->owner == owner && o->f12c != 0) {
        fn_80291C44((u8*)o + 0x130);
    }
    n = lbl_80347070->n88;
    if (n != 0 && n->owner == owner && o->fe0 != 0) {
        fn_80291C44((u8*)o + 0xe4);
    }
    n = lbl_80347070->n84;
    if (n != 0 && n->owner == owner && o->f94 != 0) {
        fn_80291C44((u8*)o + 0x98);
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

void fn_8017439C(void) {
    u32 a;
    u32 b;
    MS_8017439C* ms = (MS_8017439C*)((Outer_UNIT0000*)lbl_8034710C)->holder->ctrl;

    switch (fn_801944C4()) {
    case 0:
        a = 0x3f;
        b = 0xf;
        break;
    case 1:
        a = 0xff;
        b = 0x7ff;
        break;
    }
    ms->f0c = a;
    ms->f4c = b;
    fn_80195A68(ms, 1, 0, 0, 0, 1);
    ms->f6c = 6;
    ms->f04 = 0;
    ms->f44 = 0;
}

void fn_80174444(void) {
    void** arr;
    s32 i;
    s32 j;
    UiObj* obj;

    i = fn_80194490();
    arr = (void**)(CWB + 0x10);
    obj = (UiObj*)(*(u8**)(*(u8**)&arr[i] + 0x24) + 8);
    fn_80199BB8(obj, -8.0f, 61.0f);
    fn_80199BAC(obj, -8.0f, 61.0f);

    j = fn_8019445C();
    obj = (UiObj*)(*(u8**)(*(u8**)&arr[j] + 0x24) + 8);
    fn_80199BB8(obj, -648.0f, 123.0f);
    fn_80199BAC(obj, -648.0f, 123.0f);

    obj = (UiObj*)(*(u8**)(*(u8**)(CWB + 0x1ac) + 0x24) + 8);
    fn_80199BB8(obj, 48.0f, 131.0f);
    fn_80199BAC(obj, 48.0f, 131.0f);
}

void fn_801778AC(void) {
    MS_801778AC* ms = (MS_801778AC*)((Outer_UNIT0000*)lbl_8034710C)->holder->ctrl;

    switch (ms->mode) {
    case 0:
        fn_80193FF8(3);
        break;
    case 1:
        fn_80193FF8(0);
        break;
    case 2:
        fn_80193FF8(1);
        break;
    case 3:
        fn_80193FF8(2);
        break;
    case 4:
        fn_80193FBC(5, 1);
        fn_80193FBC(6, 0);
        fn_80193FBC(7, 0);
        break;
    case 5:
        fn_80193FF8(4);
        break;
    }
}

void fn_80177C98(void) {
    s32 i;
    UiObj* obj;

    for (i = 0; i < 7; i++) {
        obj = (UiObj*)(*(u8**)(*(u8**)(CWB + 0xdc + i * 4) + 0x24) + 8);
        fn_80199BB8(obj, 668.0f, 204.0f);
        fn_80199BAC(obj, 668.0f, 204.0f);
    }
    obj = (UiObj*)(*(u8**)(*(u8**)(CWB + 0x194) + 0x24) + 8);
    fn_80199BB8(obj, 328.0f, 204.0f);
    fn_80199BAC(obj, 328.0f, 204.0f);
    obj = (UiObj*)(*(u8**)(*(u8**)(CWB + 0x190) + 0x24) + 8);
    fn_80199BB8(obj, 632.0f, 480.0f);
    fn_80199BAC(obj, 632.0f, 480.0f);
}

void fn_801792A4(void) {
    s32 i;
    UiObj* obj;

    for (i = 0; i < 7; i++) {
        obj = (UiObj*)(*(u8**)(*(u8**)(CWB + 0xf8 + i * 4) + 0x24) + 8);
        fn_80199BB8(obj, 668.0f, 204.0f);
        fn_80199BAC(obj, 668.0f, 204.0f);
    }
    obj = (UiObj*)(*(u8**)(*(u8**)(CWB + 0x198) + 0x24) + 8);
    fn_80199BB8(obj, 328.0f, 204.0f);
    fn_80199BAC(obj, 328.0f, 204.0f);
    obj = (UiObj*)(*(u8**)(*(u8**)(CWB + 0x190) + 0x24) + 8);
    fn_80199BB8(obj, 632.0f, 480.0f);
    fn_80199BAC(obj, 632.0f, 480.0f);
}

void fn_8017B0F8(void) {
    s32 (**fp)(void);
    s32 i;
    s32 first;
    u32 mask;
    MS_8017B0F8* ms;

    mask = 0;
    first = -1;
    i = 0;
    fp = lbl_803467A8;
    ms = (MS_8017B0F8*)((Outer_UNIT0000*)lbl_8034710C)->holder->ctrl;
    for (; i < 2; i++) {
        if ((*fp)() != 0) {
            mask |= 1 << i;
            if (first != -1) {
                first = i;
            }
        }
        fp++;
    }
    ms->f0c = mask;
    ms->f4c = 0;
    fn_80195A68(ms, 1, 0, 0, 0, 1);
}

s32 fn_80183750(s8 a)
{
    if (a < 4) {
        CampRec_UNIT0000* r = &((CampRec_UNIT0000*)lbl_8030B7F4)[((CampWork_UNIT0000*)CWB)->ids[a]];
        return r->x1a > r->x18;
    }
    if (fn_801953B8() == 0) {
        return 0;
    }
    {
        CampObj* o = (CampObj*)((CampWork_UNIT0000*)CWB)->p04;
        s32 v = fn_80194028();
        return o->x14 < v;
    }
}

s32 fn_80183800(s32 a, s32 b)
{
    s16 v = fn_801838C8(a, *((s8*)lbl_8030B7F4 + b + 0x328));
    switch (a) {
    case 0x36: case 0x37: case 0x38: case 0x39: case 0x3a:
        return v < 0x3e7;
    case 0x3b:
        return v < 0x270f;
    case 0x3c:
        return v < 0x63;
    default:
        return 0;
    }
}

void fn_8018564C(void)
{
    s32 i;
    s32 first;
    u32 mask;
    Ctrl_UNIT0000* c;

    mask = 0;
    first = -1;
    c = ((Outer_UNIT0000*)lbl_8034710C)->holder->ctrl;
    for (i = 0; i < 5; i++) {
        if (lbl_802E97C0[i]() != 0) {
            mask |= 1 << i;
            if (first == -1) {
                first = i;
            }
        }
    }
    c->mask = mask;
    if (lbl_802E97C0[c->first]() == 0) {
        c->first = first;
    }
    c->x4c = 0;
    fn_80195A68(c, 1, 0, 0, 0, 1);
    lbl_803470C8 = 0;
}

void fn_80186348(void)
{
    if (lbl_803470DC != 0) {
        fn_801D6944(lbl_803470DC);
        fn_801E17E0(lbl_803470DC);
        lbl_803470DC = 0;
    }
    if (lbl_803470D8 != 0) {
        fn_801D6944(lbl_803470D8);
        fn_801E17E0(lbl_803470D8);
        lbl_803470D8 = 0;
    }
    if (lbl_803470E4 != 0) {
        fn_802275A4(((Obj4*)lbl_803470E4)->x4->x20, 0);
        fn_801E17E0(lbl_803470E4);
        lbl_803470E4 = 0;
    }
    if (lbl_803470E0 != 0) {
        fn_801E17E0(lbl_803470E0);
        lbl_803470E0 = 0;
    }
}

void fn_80186908(Obj48* o)
{
    void* r;

    o->f00 = -3940.0f;
    o->f04 = 0.0f;
    o->f10 = 1.0f;
    o->f14 = 1.0f;
    o->f18 = 1.0f;
    o->f1c = 0.0f;
    o->i08 = 1;
    o->i0c = 0;
    r = fn_801D68C4(lbl_803470F4, 0x4c);
    fn_8019A15C(o, 0, 1, 0);
    o->p38->p0 = r;
    o->p3c->f0 = 36.0f;
    o->p3c->f4 = 31.0f;
    o->p44 = 0;
}

void fn_801869B8(PairSet* o, Pair8* src)
{
    s32 i;

    o->mask0 = 0;
    o->mask1 = 0;
    for (i = 0; i < 11; i++) {
        u32 bit = 1 << i;

        o->pairs[i].a = src[i].a;
        if (src[i].a != -1) {
            o->mask0 |= bit;
            if (src[i].b != -1) {
                o->mask1 |= bit;
            }
        }
        o->pairs[i].b = src[i].b;
        if (src[i].a != -1) {
            o->mask0 |= bit;
            if (src[i].b != -1) {
                o->mask1 |= bit;
            }
        }
    }
}

void fn_80187E68(Obj48* o)
{
    o->f00 = -6190.0f;
    o->f04 = 0.0f;
    o->f10 = 1.0f;
    o->f14 = 0.0f;
    o->f18 = 1.0f;
    o->f1c = 0.0f;
    o->i08 = 0;
    o->i0c = 0;
    fn_8019A15C(o, 1, 0, 1);
    o->p20->p0 = fn_801D68C4(lbl_803470F0, 10);
    o->p24->f0 = 0.0f;
    o->p24->f4 = 0.0f;
    o->p2c->p0 = fn_801D68C4(lbl_803470E8, 2);
    o->p30->f0 = 0.0f;
    o->p30->f4 = 0.0f;
    o->p44 = fn_801D68C4(lbl_803470F0, 4);
}

void fn_801884C4(Obj48* o)
{
    o->f00 = -6790.0f;
    o->f04 = 0.0f;
    o->f10 = 1.0f;
    o->f14 = 0.0f;
    o->f18 = 1.0f;
    o->f1c = 0.0f;
    o->i08 = 0;
    o->i0c = 0;
    fn_8019A15C(o, 1, 0, 1);
    o->p20->p0 = fn_801D68C4(lbl_803470F0, 10);
    o->p24->f0 = 0.0f;
    o->p24->f4 = 0.0f;
    o->p2c->p0 = fn_801D68C4(lbl_803470E8, 2);
    o->p30->f0 = 0.0f;
    o->p30->f4 = 0.0f;
    o->p44 = fn_801D68C4(lbl_803470F0, 1);
}

void fn_8018873C(Obj48* o)
{
    void* r;

    o->f00 = -3700.0f;
    o->f04 = 0.0f;
    o->f10 = 1.0f;
    o->f14 = 1.0f;
    o->f18 = 1.0f;
    o->f1c = 0.0f;
    o->i08 = 1;
    o->i0c = 0;
    r = fn_801D68C4(lbl_803470F4, 0x4d);
    fn_8019A15C(o, 0, 1, 0);
    o->p38->p0 = r;
    o->p3c->f0 = 16.0f;
    o->p3c->f4 = 12.0f;
    o->p44 = 0;
}

void fn_801895C0(void* unused, Obj48* o, f32 f1)
{
    o->f00 = -4000.0f;
    o->f04 = 0.0f;
    o->f10 = 1.0f;
    o->f14 = f1;
    o->f18 = 1.0f;
    o->f1c = 0.0f;
    o->i08 = 0;
    o->i0c = 0;
    fn_8019A15C(o, 2, 0, 0);
    o->p20->p0 = fn_801D68C4(lbl_803470F0, 0x22);
    o->p24->f0 = 0.0f;
    o->p24->f4 = -26.0f;
    o->p20->p4 = fn_801D68C4(lbl_803470F0, 0x3b);
    o->p24->f8 = 68.0f;
    o->p24->fc = -26.0f;
    o->p44 = 0;
}

void fn_80189788(void* unused, Obj48* o, f32 f1)
{
    void* r;

    o->f00 = -4000.0f;
    o->f04 = 0.0f;
    o->f10 = 1.0f;
    o->f14 = f1;
    o->f18 = 1.0f;
    o->f1c = 0.0f;
    o->i08 = 0;
    o->i0c = 0;
    r = fn_801D68C4(lbl_803470F0, 0x20);
    fn_8019A15C(o, 1, 0, 0);
    o->p20->p0 = r;
    o->p24->f0 = 0.0f;
    o->p24->f4 = 2.0f;
    o->p44 = 0;
}

void fn_80189834(Obj48* o, f32 f1)
{
    o->f00 = -3850.0f;
    o->f04 = 0.0f;
    o->f10 = 1.0f;
    o->f14 = f1;
    o->f18 = 1.0f;
    o->f1c = 0.0f;
    o->i08 = 0;
    o->i0c = 0;
    fn_8019A15C(o, 1, 0, 1);
    o->p20->p0 = fn_801D68C4(lbl_803470F0, 0x1f);
    o->p24->f0 = 0.0f;
    o->p24->f4 = 160.0f;
    o->p2c->p0 = fn_801D68C4(lbl_803470E8, 3);
    o->p30->f0 = 0.0f;
    o->p30->f4 = 0.0f;
    o->p44 = fn_801D68C4(lbl_803470F0, 5);
}

void fn_80189CF0(Obj48* o)
{
    o->f00 = -3990.0f;
    o->f04 = 0.0f;
    o->f10 = 1.0f;
    o->f14 = 0.0f;
    o->f18 = 1.0f;
    o->f1c = 0.0f;
    o->i08 = 0;
    o->i0c = 0;
    fn_8019A15C(o, 1, 0, 1);
    o->p20->p0 = fn_801D68C4(lbl_803470F0, 0x27);
    o->p24->f0 = 0.0f;
    o->p24->f4 = 0.0f;
    o->p2c->p0 = fn_801D68C4(lbl_803470E8, 4);
    o->p30->f0 = 0.0f;
    o->p30->f4 = 0.0f;
    o->p44 = 0;
}

void fn_8018DEFC(Obj48* o)
{
    void* r;

    o->f00 = -3940.0f;
    o->f04 = 0.0f;
    o->f10 = 1.0f;
    o->f14 = 1.0f;
    o->f18 = 1.0f;
    o->f1c = 0.0f;
    o->i08 = 1;
    o->i0c = 0;
    r = fn_801D68C4(lbl_803470F4, 0x4a);
    fn_8019A15C(o, 0, 1, 0);
    o->p38->p0 = r;
    o->p3c->f0 = -24.0f;
    o->p3c->f4 = 0.0f;
    o->p44 = 0;
}

void fn_8018DFC4(Obj_8018DFC4* o)
{
    Sub_8018DFC4* s = o->p24;
    void* r = s->rect8;

    if (lbl_803475D8 != 0) {
        o->state19 = 0xff;
    }
    switch (o->state19) {
    case 0:
    case 0xfe:
        o->state19 = 1;
        /* fall through */
    case 1:
        fn_80199F38(r);
        UiObjCalcRect(r);
        if (o->p24->kind == 1) {
            fn_8018E73C(o->p24);
            fn_8018E0A8(o->p24);
        }
        break;
    case 0x64:
        o->state19 = 0xff;
        break;
    case 0xff:
        fn_80199F58(o->p24);
        o->flags18 |= 0x40;
        break;
    }
}

void fn_801925D8(void)
{
    if (lbl_803470E8 != 0) {
        fn_801D6944(lbl_803470E8);
        fn_801E17E0(lbl_803470E8);
        lbl_803470E8 = 0;
    }
    if (lbl_803470EC != 0) {
        fn_801D6944(lbl_803470EC);
        fn_801E17E0(lbl_803470EC);
        lbl_803470EC = 0;
    }
    if (lbl_803470F0 != 0) {
        fn_801D6944(lbl_803470F0);
        fn_801E17E0(lbl_803470F0);
        lbl_803470F0 = 0;
    }
    if (lbl_803470F4 != 0) {
        fn_801D6944(lbl_803470F4);
        fn_801E17E0(lbl_803470F4);
        lbl_803470F4 = 0;
    }
    if (lbl_80347618 != 0) {
        fn_802275A4(((Obj4*)lbl_80347618)->x4->x20, 1);
        fn_801E17E0(lbl_80347618);
        lbl_80347618 = 0;
    }
    if (lbl_803470F8 != 0) {
        fn_801E17E0(lbl_803470F8);
        lbl_803470F8 = 0;
    }
}

void fn_80192888(void)
{
    s16* p = (s16*)(lbl_8030B7F4 + 0x1568);
    s32 i;

    for (i = 0; i < 5; i++) {
        if (p[12 + i] != -1) {
            fn_801C0FE8(p[12 + i], 1);
        }
    }
    for (i = 0; i < 3; i++) {
        if (p[17 + i] != -1) {
            fn_801C0FE8(p[17 + i], 1);
        }
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

s32 fn_8015FE60(s32 idx, Obj_8015FE60 *o, f32 a)
{
    Mo *m = fn_8008F8FC(o, idx);
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
        o->f1a8 = 0.2f;
        if (prev != 0.0f && o->f1a0 != 0.0f) {
            o->f19c = 0;
        } else if (o->ff0 != 0 && m != o->ff0) {
            o->f19c = 0;
        } else {
            o->f19c = 1;
        }
    }
    if (0.0f > a) {
        o->f18c = (f32)o->fe8->f4 - 1.0f;
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

s32 fn_80160954(Own_80160954 *o, Inp *in) {
    Tgt *t = o->h->t;
    if (3.4028235e38f != in->x) t->x = in->x;
    if (3.4028235e38f != in->y) t->y = in->y;
    if (3.4028235e38f != in->z) t->z = in->z;
    if (3.4028235e38f != in->rx) t->rx = (s32)(182.04445f * in->rx);
    if (3.4028235e38f != in->ry) t->ry = (s32)(182.04445f * in->ry);
    if (3.4028235e38f != in->rz) t->rz = (s32)(182.04445f * in->rz);
    fn_801671C0((Obj_801671C0_UNIT0000 *)t);
    fn_8008FFA4(&t->x, t->tail);
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

void fn_80171B64(s8 idx) {
    void *spr;
    Hold_80171B64 *h = ((Camp_80171B64*)CWB)->hold;
    switch (idx) {
    case 0: spr = fn_801D68C4(lbl_803470F0, 0x2b); break;
    case 1: spr = fn_801D68C4(lbl_803470F0, 0x2c); break;
    case 2: spr = fn_801D68C4(lbl_803470F0, 0x2d); break;
    case 3: spr = fn_801D68C4(lbl_803470F0, 0x2e); break;
    case 4: spr = fn_801D68C4(lbl_803470F0, 0x2f); break;
    case 5: spr = fn_801D68C4(lbl_803470F0, 0x30); break;
    default: spr = fn_801D68C4(lbl_803470F0, 0x2b); break;
    }
    fn_8019520C(idx, spr);
    h->sub->dst->spr = spr;
}

void fn_80172B54(void) {
    u8 buf[0x60];
    s32 i, j;
    s32 k;
    void *w = ((Camp_80172B54*)CWB)->mid->hm->w;
    for (i = 0; i < 11; i++) {
        for (j = 0; j < 2; j++) {
            fn_80194C68(buf, i, j, -1);
        }
    }
    for (i = 0; i < 11; i++) {
        for (j = 0; j < 2; j++) {
            k = i * 2 + j;
            if (fn_801E4BF4(k) != 0) {
                if (fn_801E4BBC(k) != 0) {
                    fn_80194C68(buf, i, 0, k);
                } else {
                    fn_80194C68(buf, i, 1, k);
                }
            } else {
                fn_80194C68(buf, i, j, -1);
            }
        }
    }
    fn_801869B8(w, (void*)buf);
}

void fn_80176A44(void) {
    Ctrl_80176A44* c;
    Pnl** arr;
    s32 k;

    c = ((Outer_80176A44*)lbl_8034710C)->holder->ctrl;
    CampMenuHideAllPanels();
    arr = (Pnl**)(CWB + 0x10);
    arr[*(s32*)(lbl_80307638 + 0x7c)]->in->hide = 1;
    (*(Pnl**)(CWB + 0x8c + *(s32*)(lbl_80307638 + 0x16c) * 4))->in->hide = 1;
    PNL(0x1b0)->in->hide = 1;
    PNL(0x1b4)->in->hide = 1;
    PNL(0x18c)->in->hide = 1;
    PNL(0x184)->in->hide = 1;
    PNL(0x188)->in->hide = 1;
    PNL(0x114)->in->hide = 1;
    k = *(s32*)(lbl_80307638 + 0x3c4) + 0x43;
    arr[k]->in->hide = 1;
    PNL(0x190)->in->hide = 1;
    PNL(0x19c)->in->hide = 0;
    c->f6c = 1;
}

void fn_80177AC8(void) {
    UiObj* q;
    UiObj* p;
    s32 i;
    Ctrl_80177AC8* c;
    UiObj* o;

    c = ((Outer_80177AC8*)lbl_8034710C)->holder->ctrl;
    o = &PNL(0xdc)->in->obj;
    UiObjMoveTo(o, 6, 4, 328.0f, 204.0f);
    UiObjSetCommand(o, 15, 0);
    for (i = 0; i < 6; i++) {
        if (c->mask & (1 << i)) {
            p = &(*(Pnl**)(CWB + 0xdc + 4 + i * 4))->in->obj;
            UiObjMoveTo(p, 6, -1, 328.0f, 204.0f);
            UiObjSetCommand(p, 15, 0);
        }
    }
    q = &PNL(0x190)->in->obj;
    UiObjMoveTo(q, 6, -1, 24.0f, 384.0f);
    UiObjSetCommand(q, 15, 0);
}

void fn_801790C8(void) {
    UiObj* q;
    UiObj* p;
    s32 i;
    Ctrl_801790C8* c;
    UiObj* o;

    c = ((Outer_801790C8*)lbl_8034710C)->holder->ctrl;
    c->f4 = 0;
    c->f8 = 0;
    o = &PNL(0xf8)->in->obj;
    UiObjMoveTo(o, 6, 4, 328.0f, 204.0f);
    UiObjSetCommand(o, 15, 0);
    for (i = 0; i < 6; i++) {
        if (c->mask & (1 << i)) {
            p = &(*(Pnl**)(CWB + 0xf8 + 4 + i * 4))->in->obj;
            UiObjMoveTo(p, 6, -1, 328.0f, 204.0f);
            UiObjSetCommand(p, 15, 0);
        }
    }
    q = &PNL(0x190)->in->obj;
    UiObjMoveTo(q, 6, -1, 24.0f, 384.0f);
    UiObjSetCommand(q, 15, 0);
}

void fn_8017A9FC(void) {
    UiObj* q;
    UiObj* o;
    UiObj* a;
    f32 y;
    s32 i;

    a = &PNL(0x84)->in->obj;
    fn_80199BB8(a, -8.0f, 61.0f);
    fn_80199BAC(a, -8.0f, 61.0f);
    for (i = 0; i < 3; i++) {
        o = &(*(Pnl**)(CWB + 0x254 + i * 4))->in->obj;
        y = (f32)((i + 1) * 64 + 61);
        UiObjSetLowered(o);
        fn_80199BB8(o, -398.0f, y);
        fn_80199BAC(o, -398.0f, y);
    }
    q = &PNL(0x190)->in->obj;
    fn_80199BB8(q, 632.0f, 480.0f);
    fn_80199BAC(q, 632.0f, 480.0f);
}

void fn_8017B19C(void) {
    UiObj* o;
    s32 i;
    Ctrl_8017B19C* c;
    UiObj* q;

    c = ((Outer_8017B19C*)lbl_8034710C)->holder->ctrl;
    q = &PNL(0x78)->in->obj;
    UiObjMoveTo(q, 6, -1, -8.0f, 61.0f);
    UiObjSetCommand(q, 15, 0);
    for (i = 0; i < 2; i++) {
        o = &(*(Pnl**)(CWB + 0x22c + i * 4))->in->obj;
        UiObjMoveTo(o, 6, 4, -8.0f, (f32)((i + 1) * 64 + 61));
        if (c->f4 == i) {
            UiObjSetCommand(o, 10, i);
        } else {
            UiObjSetCommand(o, 15, i);
        }
    }
}

void fn_8017B2AC(void) {
    UiObj* o;
    s32 i;
    Ctrl_8017B2AC* c;
    UiObj* q;

    c = ((Outer_8017B2AC*)lbl_8034710C)->holder->ctrl;
    q = &PNL(0x78)->in->obj;
    UiObjMoveTo(q, 6, -1, -348.0f, 61.0f);
    UiObjSetCommand(q, 15, 0);
    for (i = 0; i < 2; i++) {
        o = &(*(Pnl**)(CWB + 0x22c + i * 4))->in->obj;
        UiObjMoveTo(o, 6, 5, -348.0f, (f32)((i + 1) * 64 + 61));
        if (c->f4 == i) {
            UiObjSetCommand(o, 15, i);
        } else {
            UiObjSetCommand(o, 15, i);
        }
    }
}

void fn_8017B3BC(void) {
    UiObj* o;
    s32 i;
    Ctrl_8017B3BC* c;
    UiObj* q;
    f32 y;

    c = ((Outer_8017B3BC*)lbl_8034710C)->holder->ctrl;
    q = &PNL(0x78)->in->obj;
    UiObjMoveTo(q, 6, -1, -348.0f, 61.0f);
    UiObjSetCommand(q, 15, 0);
    for (i = 0; i < 2; i++) {
        o = &(*(Pnl**)(CWB + 0x22c + i * 4))->in->obj;
        y = (f32)((i + 1) * 64 + 61);
        if (i == c->f4) {
            UiObjMoveTo(o, 6, 4, -8.0f, 61.0f);
            UiObjSetCommand(o, 15, i);
        } else {
            UiObjMoveTo(o, 6, 5, -348.0f, y);
            UiObjSetCommand(o, 15, i);
        }
    }
}

void fn_8017B4E4(void) {
    UiObj* o;
    f32 y;
    s32 i;
    UiObj* a;

    a = &PNL(0x78)->in->obj;
    fn_80199BB8(a, -348.0f, 61.0f);
    fn_80199BAC(a, -348.0f, 61.0f);
    for (i = 0; i < 2; i++) {
        o = &(*(Pnl**)(CWB + 0x22c + i * 4))->in->obj;
        y = (f32)((i + 1) * 64 + 61);
        UiObjSetLowered(o);
        fn_80199BB8(o, -348.0f, y);
        fn_80199BAC(o, -348.0f, y);
    }
}

void fn_8017CC70(void) {
    UiObj* o;
    f32 off;
    Sprite* s;
    u8* cw = CWB;

    switch (((Outer_8017CC70*)lbl_8034710C)->holder->ctrl->f24) {
    case 0:
        o = &(*(Pnl**)(cw + 0x1f8))->in->obj;
        off = 0.0f;
        break;
    case 1:
        o = &(*(Pnl**)(cw + 0x20c))->in->obj;
        off = 0.0f;
        break;
    }
    s = fn_801D68C4(lbl_803470F0, 0x62);
    s->x = 24.0f + o->x;
    s->y = -16.0f + o->y + off;
    fn_800FF348(s, 0, -5850.0f, 1.0f, *(f32*)(cw + 0x350));
    s = fn_801D68C4(lbl_803470F0, 0x63);
    s->x = 272.0f + o->x;
    s->y = -16.0f + o->y + off;
    fn_800FF348(s, 0, -5850.0f, 1.0f, *(f32*)(cw + 0x350));
}

void fn_8017D250(void) {
    Ctrl_8017D250* c;
    f32 v;
    u8* b = lbl_80307638;

    c = ((Outer_8017D250*)lbl_8034710C)->holder->ctrl;
    switch (*(s32*)(b + 0x204)) {
    case 0:
        c->fc = 0x1f;
        c->f4 = 0;
        break;
    case 1:
        c->fc = 7;
        c->f4 = 0;
        break;
    }
    c->f2c = 3;
    c->f24 = *(s32*)(b + 0x204);
    fn_80195A68(c, 1, 0, 0, 0, 1);
    fn_801954D0(0);
    v = -6190.0f;
    ((Pnl74*)PNL(0x1f8))->in->f74 = v;
    ((Pnl74*)PNL(0x1fc))->in->f74 = v;
    ((Pnl74*)PNL(0x200))->in->f74 = v;
    ((Pnl74*)PNL(0x204))->in->f74 = v;
    ((Pnl74*)PNL(0x208))->in->f74 = v;
    ((Pnl74*)PNL(0x20c))->in->f74 = v;
    ((Pnl74*)PNL(0x210))->in->f74 = v;
    ((Pnl74*)PNL(0x214))->in->f74 = v;
}

void fn_8017E4E4(void) {
    UiObj* o;
    f32 off;
    Sprite* s;
    u8* cw = CWB;

    switch (((Outer_8017E4E4*)lbl_8034710C)->holder->ctrl->f24) {
    case 0:
        o = &(*(Pnl**)(cw + 0x1f8))->in->obj;
        off = -64.0f;
        break;
    case 1:
        o = &(*(Pnl**)(cw + 0x20c))->in->obj;
        off = -64.0f;
        break;
    }
    s = fn_801D68C4(lbl_803470F0, 0x62);
    s->x = 24.0f + o->rect[0];
    s->y = -16.0f + o->rect[1] + off;
    fn_800FF348(s, 0, -5850.0f, 1.0f, *(f32*)(cw + 0x350));
    s = fn_801D68C4(lbl_803470F0, 0x63);
    s->x = 272.0f + o->rect[0];
    s->y = -16.0f + o->rect[1] + off;
    fn_800FF348(s, 0, -5850.0f, 1.0f, *(f32*)(cw + 0x350));
}

void fn_8018006C(s8 arg) {
    Ctrl_8018006C* c = ((Outer_8018006C*)lbl_8034710C)->holder->ctrl;

    switch (c->state) {
    case 0:
        fn_80180174(c->f44, arg);
        c->state++;
        break;
    case 1:
        if (CampMenuAnyPanelBusy() == 0) {
            c->state++;
        } else if (fn_801C09F8(lbl_80347154, 0x11) != 0 || fn_801C09F8(lbl_80347154, 0x10) != 0) {
            CampMenuFinishAllPanels();
            c->state++;
        }
        break;
    case 2:
        c->state = 0;
        switch (arg) {
        case 0:
            c->f6c = 5;
            break;
        case 1:
            c->f6c = 2;
            break;
        }
        break;
    }
}

void fn_80180174(s8 unused, s8 mode) {
    UiObj* p;
    f32 x, y;
    s16 se;
    UiObj* o;
    s32 cmd1, cmd2;

    switch (mode) {
    case 0:
        x = -8.0f;
        cmd1 = 10;
        y = 253.0f;
        cmd2 = 15;
        se = 4;
        break;
    case 1:
        x = -348.0f;
        cmd1 = 15;
        y = 253.0f;
        cmd2 = 15;
        se = 5;
        break;
    }
    o = &PNL(0x27c)->in->obj;
    UiObjFinish(o);
    UiObjMoveTo(o, 6, se, x - 60.0f, y);
    UiObjSetCommand(o, cmd1, 2);
    p = &PNL(0x280)->in->obj;
    UiObjFinish(p);
    UiObjMoveTo(p, 6, -1, x - 60.0f, 64.0f + y);
    UiObjSetCommand(p, cmd2, 2);
}

void fn_80180A84(void) {
    UiObj* q;
    UiObj* p;
    s32 i;
    UiObj* o;

    o = &PNL(0x1b8)->in->obj;
    UiObjMoveTo(o, 6, 4, -8.0f, 189.0f);
    UiObjSetCommand(o, 10, 0);
    for (i = 0; i < 7; i++) {
        p = &(*(Pnl**)(CWB + 0x130 + i * 4))->in->obj;
        UiObjMoveTo(p, 6, -1, 328.0f, 204.0f);
        UiObjSetCommand(p, 15, 0);
    }
    q = &PNL(0x190)->in->obj;
    UiObjMoveTo(q, 6, -1, 24.0f, 384.0f);
    UiObjSetCommand(q, 15, 0);
}

void fn_80183C54(void) {
    UiObj* o;
    Sprite* s;
    u8* cw = CWB;

    switch (((Outer_80183C54*)lbl_8034710C)->holder->ctrl->f44) {
    case 0:
        o = &(*(Pnl**)(cw + 0x28))->in->obj;
        break;
    case 1:
        o = &(*(Pnl**)(cw + 0x2c))->in->obj;
        break;
    case 2:
        o = &(*(Pnl**)(cw + 0x30))->in->obj;
        break;
    case 3:
        o = &(*(Pnl**)(cw + 0x34))->in->obj;
        break;
    case 4:
        o = &(*(Pnl**)(cw + 0x38))->in->obj;
        break;
    }
    s = fn_801D68C4(lbl_803470F0, 0x62);
    s->x = 24.0f + o->rect[0];
    s->y = -16.0f + o->rect[1];
    fn_800FF348(s, 0, -5850.0f, 1.0f, *(f32*)(cw + 0x350));
    s = fn_801D68C4(lbl_803470F0, 0x63);
    s->x = 272.0f + o->rect[0];
    s->y = -16.0f + o->rect[1];
    fn_800FF348(s, 0, -5850.0f, 1.0f, *(f32*)(cw + 0x350));
}

static inline void Hide(CampW* a, s32 k) {
    a->pnl[k]->in->hide = 1;
}

void fn_80184CE8(void) {
    s32 i;
    s32 k;
    CampW* a;

    CampMenuHideAllPanels();
    a = (CampW*)CWB;
    for (i = 0; i < a->count; i++) {
        (*(Pnl**)(CWB + i * 4 + 0x10))->in->hide = 1;
        for (k = 0; k < 5; k++) {
            (*(Pnl**)(CWB + (i * 5 + 6 + k) * 4 + 0x10))->in->hide = 1;
        }
    }
    if (fn_801953B8() != 0) {
        PNL(0x20)->in->hide = 1;
        PNL(0x1c0)->in->hide = 1;
        PNL(0x1c4)->in->hide = 1;
    }
    if (fn_80194CB8() == 1) {
        PNL(0x24)->in->hide = 1;
    }
}

void fn_80185AFC(void) {
    s32 i;
    f32 y;
    UiObj* o;
    for (i = 0; i < 4; i++) {
        if (lbl_802E97C0[i]() != 0) {
            o = (UiObj*)(*(u8**)(*(u8**)(CWB + 0x78 + i * 4) + 0x24) + 8);
            y = 61 + i * 64;
            UiObjSetLowered(o);
            fn_80199BB8(o, -348.0f, y);
            fn_80199BAC(o, -348.0f, y);
        }
    }
    o = (UiObj*)(*(u8**)(*(u8**)(CWB + 0x88) + 0x24) + 8);
    UiObjSetLowered(o);
    fn_80199BB8(o, -348.0f, 381.0f);
    fn_80199BAC(o, -348.0f, 381.0f);
}

void fn_801851C8(void) {
    s32 sel = *(s32*)(**(u8***)((u8*)lbl_8034710C + 0x24) + 4);
    switch (sel) {
    case 4:
    case 5:
        *(s32*)(CWB + 0x2f8) = 0;
        camp_screen = 1;
        fn_801959D4(1);
        break;
    case 0:
        *(s32*)(CWB + 0x330) = 0;
        camp_screen = 0xf;
        fn_801959D4(0xf);
        break;
    case 1:
        *(s32*)(CWB + 0x328) = 0;
        camp_screen = 0xd;
        fn_801959D4(0xd);
        break;
    case 2:
        *(s32*)(CWB + 0x340) = 0;
        camp_screen = 0x13;
        fn_801959D4(0x13);
        break;
    case 3:
        *(s32*)(CWB + 0x33c) = 0;
        camp_screen = 0x12;
        fn_801959D4(0x12);
        break;
    default:
        *(s32*)(CWB + 0x300) = 0;
        camp_screen = 3;
        fn_801959D4(3);
        break;
    }
}

void fn_80185724(void) {
    s32 i;
    s32* st = **(s32***)((u8*)lbl_8034710C + 0x24);
    UiObj* o;
    for (i = 0; i < 4; i++) {
        if (lbl_802E97C0[i]() != 0) {
            o = (UiObj*)(*(u8**)(*(u8**)(CWB + 0x78 + i * 4) + 0x24) + 8);
            UiObjMoveTo(o, 6, 5, -348.0f, 61 + i * 64);
            if (st[1] == i) {
                UiObjSetCommand(o, 10, i);
            } else {
                UiObjSetCommand(o, 15, i + 1);
            }
        }
    }
    o = (UiObj*)(*(u8**)(*(u8**)(CWB + 0x88) + 0x24) + 8);
    UiObjMoveTo(o, 6, 5, -348.0f, 381.0f);
    if (st[1] == 4) {
        UiObjSetCommand(o, 10, 5);
    } else {
        UiObjSetCommand(o, 15, 6);
    }
}

void fn_801859BC(void) {
    s32 i;
    s32* st = **(s32***)((u8*)lbl_8034710C + 0x24);
    UiObj* o;
    for (i = 0; i < 4; i++) {
        if (lbl_802E97C0[i]() != 0) {
            o = (UiObj*)(*(u8**)(*(u8**)(CWB + 0x78 + i * 4) + 0x24) + 8);
            UiObjMoveTo(o, 6, 4, -8.0f, 61 + i * 64);
            if (st[1] == i) {
                UiObjSetCommand(o, 10, i);
            } else {
                UiObjSetCommand(o, 15, i + 1);
            }
        }
    }
    o = (UiObj*)(*(u8**)(*(u8**)(CWB + 0x88) + 0x24) + 8);
    UiObjMoveTo(o, 6, 4, -8.0f, 381.0f);
    if (st[1] == 4) {
        UiObjSetCommand(o, 10, 5);
    } else {
        UiObjSetCommand(o, 15, 6);
    }
}

void fn_801866B4(void) {
    s32 b;
    void* buf;
    s32 a;
    void* src;
    void* s0;
    lbl_803470E0 = fn_801E49D8(lbl_802B44A8);
    a = fn_801E4974(lbl_803470E0, 2);
    b = fn_801E48A8(lbl_803470E0);
    buf = fn_801E1C7C(a);
    src = fn_801E4984(lbl_803470E0, 2);
    MemCopy(buf, src, a);
    lbl_803470E0 = fn_801E1584(lbl_803470E0, b - a);
    lbl_803470E4 = fn_801DB124(buf);
    fn_80227810(*(void**)((u8*)((void**)lbl_803470E4)[1] + 0x20));
    lbl_803470DC = fn_801E1C7C(0x14);
    s0 = fn_801E4984(lbl_803470E0, 0);
    fn_801D6998(lbl_803470DC, s0);
    lbl_803470D8 = fn_801E1C7C(0x14);
    fn_801D6998(lbl_803470D8, fn_801E4984(lbl_803470E0, 1));
}

void fn_80186D2C(Obj_80186D2C* o) {
    o->x0 = -4090.0f;
    o->x4 = 0.0f;
    o->x10 = 1.0f;
    o->x14 = 0.0f;
    o->x18 = 1.0f;
    o->x1C = 0.0f;
    o->x8 = 0;
    o->xC = 0;
    fn_8019A15C(o, 1, 1, 1);
    *o->c_ptr = fn_801D68C4(lbl_803470F4, 0x3f);
    o->c_pos[0] = 36.0f;
    o->c_pos[1] = 28.0f;
    *o->a_ptr = fn_801D68C4(lbl_803470F0, 0x55);
    o->a_pos[0] = 0.0f;
    o->a_pos[1] = 0.0f;
    *o->b_ptr = fn_801D68C4(lbl_803470E8, 8);
    o->b_pos[0] = 0.0f;
    o->b_pos[1] = 0.0f;
    o->x44 = fn_801D68C4(lbl_803470F0, 0x52);
}

void fn_80186E4C(Self_80186E4C* self) {
    UiObj* obj = &self->inner->obj;
    Cfg* cfg = self->inner->cfg;

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
            switch (cfg->kind) {
            case 4:
                fn_8018796C(self->inner);
                break;
            default:
                fn_80186F58(self->inner);
                break;
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

void fn_80187D78(Obj_80187D78* o, f32 sx) {
    o->x0 = -6190.0f;
    o->x4 = 0.0f;
    o->x10 = sx;
    o->x14 = 0.0f;
    o->x18 = 1.0f;
    o->x1C = 0.0f;
    o->x8 = 0;
    o->xC = 0;
    fn_8019A15C(o, 1, 1, 1);
    *o->a_ptr = fn_801D68C4(lbl_803470F0, 0x2a);
    o->a_pos[0] = 0.0f;
    o->a_pos[1] = 0.0f;
    *o->b_ptr = fn_801D68C4(lbl_803470E8, 5);
    o->b_pos[0] = 0.0f;
    o->b_pos[1] = 0.0f;
    *o->c_ptr = fn_801D68C4(lbl_803470F4, 0x37);
    o->c_pos[0] = 6.0f;
    o->c_pos[1] = 6.0f;
    o->x44 = fn_801D68C4(lbl_803470F0, 0x28);
}

void fn_8018968C(s32 a, Obj_8018968C* o, s32 b, s8 idx, f32 sy) {
    o->x0 = -4000.0f;
    o->x4 = 0.0f;
    o->x10 = 1.0f;
    o->x14 = sy;
    o->x18 = 1.0f;
    o->x1C = 0.0f;
    o->x8 = 0;
    o->xC = 0;
    fn_8019A15C(o, 2, 0, 0);
    o->a_ptr[0] = fn_801D68C4(lbl_803470F0, 0x21);
    o->a_pos[0] = 0.0f;
    o->a_pos[1] = -26.0f;
    o->a_ptr[1] = fn_801D68C4(lbl_803470F0, 0x3a);
    o->a_pos[2] = idx * 0x30 + 0x14;
    o->a_pos[3] = -26.0f;
    o->x44 = 0;
}

void fn_80189958(Dst_80189958* dst, s32 unused, s32 a, s32 b, s32 unused2, s32 c) {
    Tmp tmp;
    s32 i;
    fn_80195EA4(&tmp, a, b, c, dst->id);
    if (b != tmp.count) {
        dst->ok = 0;
    } else {
        dst->ok = 1;
        for (i = 0; i < 6; i++) {
            dst->rec[i].a = tmp.rec[i].a;
            dst->rec[i].e = tmp.rec[i].e;
            dst->rec[i].f = tmp.rec[i].f;
            dst->rec[i].b = tmp.rec[i].b0;
            dst->rec[i].c = tmp.rec[i].c;
            dst->rec[i].d = tmp.rec[i].d;
        }
    }
}

s32 fn_80189A70(s32 id, u32* out) {
    s32 i;
    *out = 0;
    for (i = 0; i < (s8)CWB[0xc]; i++) {
        CampRec_80189A70* r = &((CampRec_80189A70*)lbl_8030B7F4)[(s8)lbl_8030B7F4[0x328 + i]];
        if (id == r->id) {
            switch (r->kind) {
            case 0: *out = 0xff20ff0a; break;
            case 1: *out = 0xffff4020; break;
            case 2: *out = 0xffc800ff; break;
            case 3: *out = 0xff0096ff; break;
            case 4: *out = 0xffffc800; break;
            case 5: *out = 0xffdcdcdc; break;
            default: *out = 0xffffffff; break;
            }
            return 1;
        }
    }
    return 0;
}

void fn_8018A07C(Obj_8018A07C* o, s8 idx) {
    o->x0 = -5590.0f + 150.0f * idx;
    o->x4 = 0.0f;
    o->x10 = 1.0f;
    o->x14 = 0.0f;
    o->x18 = 1.0f;
    o->x1C = 0.0f;
    o->x8 = 0;
    o->xC = 0;
    fn_8019A15C(o, 1, 0, 1);
    *o->a_ptr = fn_801D68C4(lbl_803470F0, 0x5c);
    o->a_pos[0] = 0.0f;
    o->a_pos[1] = 0.0f;
    *o->b_ptr = fn_801D68C4(lbl_803470E8, 10);
    o->b_pos[0] = 0.0f;
    o->b_pos[1] = 0.0f;
    o->x44 = fn_801D68C4(lbl_803470F0, 0x5b);
}

void fn_80191D78(Obj_80191D78* o) {
    o->x0 = -7390.0f;
    o->x4 = 0.0f;
    o->x10 = 1.0f;
    o->x14 = 0.0f;
    o->x18 = 1.0f;
    o->x1C = 0.0f;
    o->x8 = 0;
    o->xC = 0;
    fn_8019A15C(o, 2, 1, 1);
    fn_80199FFC(o, 0, fn_801D68C4(lbl_803470F4, 2), 0x55, 0x1e, 2);
    *o->b_ptr = fn_801D68C4(lbl_803470E8, 1);
    o->b_pos[0] = 0.0f;
    o->b_pos[1] = 0.0f;
    o->a_ptr[0] = fn_801D68C4(lbl_803470F0, 8);
    o->a_pos[0] = 0.0f;
    o->a_pos[1] = 0.0f;
    o->a_ptr[1] = fn_801D68C4(lbl_803470F0, 0x1e);
    o->a_pos[2] = 24.0f;
    o->a_pos[3] = -2.0f;
    o->x44 = fn_801D68C4(lbl_803470F0, 1);
}

void fn_801926B8(void) {
    s32 b;
    void* buf;
    s32 a;
    void* src;
    void* s0;
    lbl_803470F8 = fn_801CC0A0(lbl_80347100);
    a = fn_801E4974(lbl_803470F8, 4);
    b = fn_801E48A8(lbl_803470F8);
    buf = fn_801E1C7C(a);
    src = fn_801E4984(lbl_803470F8, 4);
    MemCopy(buf, src, a);
    lbl_803470F8 = fn_801E1584(lbl_803470F8, b - a);
    lbl_80347618 = fn_801DB124(buf);
    fn_80227810(*(void**)((u8*)((void**)lbl_80347618)[1] + 0x20));
    lbl_803470E8 = fn_801E1C7C(0x14);
    s0 = fn_801E4984(lbl_803470F8, 0);
    fn_801D6998(lbl_803470E8, s0);
    lbl_803470EC = fn_801E1C7C(0x14);
    fn_801D6998(lbl_803470EC, fn_801E4984(lbl_803470F8, 1));
    lbl_803470F0 = fn_801E1C7C(0x14);
    fn_801D6998(lbl_803470F0, fn_801E4984(lbl_803470F8, 2));
    lbl_803470F4 = fn_801E1C7C(0x14);
    fn_801D6998(lbl_803470F4, fn_801E4984(lbl_803470F8, 3));
}

s32 fn_801929FC(s32 v) {
    s32 i;
    for (i = 0; i < 0x58; i++) {
        if (v == lbl_802ED258[i].id) {
            return i;
        }
    }
    if (i == 0x58) {
        v = 0;
    }
    return v;
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
    Hold_8015EBF4 *h = self->x1d8;
    void *o;
    V3 *p;
    s32 r;
    if (h != 0) {
        o = h->x8;
        fn_801601AC(self);
        if (h->x84 != 0 && h->x84->x2c != 0) {
            h->x84->x2c->x14 = h->x48;
            h->x84->x2c->x18 = h->x4c;
            h->x84->x2c->x1c = h->x50;
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
        if (h->x31c_8015EBF4 != 0 && o != 0) {
            h->x31c_8015EBF4(h->x4, o);
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
        if (x <= (f32)sp->x8[i]) {
            break;
        }
        k++;
        x -= (f32)sp->x8[i];
    }
    if (k >= n) {
        return -1;
    }
    x = fn_80212A78(c, x, (f32)sp->x8[k]);
    fn_80213178(sp->xc[k], sp->x10[k].a, sp->x10[k].b, sp->xc[k + 1], b, x, (f32)sp->x8[k]);
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

void fn_80165C84(Spl_80165C84 *sp) {
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
    Obj_80168398* obj = fn_802267AC((*(void**)&lbl_8034759C), (void*)fn_801680B4);
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
    Ctrl_80170450* c = ((Outer_80170450*)lbl_8034710C)->holder->ctrl;

    switch (c->state) {
    case 0:
        fn_80170704(c->f44, 1);
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
        fn_80170704(c->f44, 0);
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
        c->f6c = 2;
        break;
    }
}

void fn_8017519C(void) {
    s32 i;
    UiObj* o;

    o = &PNL(0x98)->in->obj;
    UiObjMoveTo(o, 6, -1, -348.0f, 125.0f);
    UiObjSetCommand(o, 15, 0);
    o = &PNL(0x1b0)->in->obj;
    UiObjMoveTo(o, 6, -1, -348.0f, 194.0f);
    UiObjSetCommand(o, 15, 1);
    for (i = 0; i < 3; i++) {
        o = &(*(Pnl**)(CWB + 0x178 + i * 4))->in->obj;
        UiObjMoveTo(o, 6, 5, 668.0f, 61 + i * 88);
        UiObjSetCommand(o, 15, i);
    }
    o = &PNL(0x190)->in->obj;
    UiObjMoveTo(o, 6, -1, 632.0f, 480.0f);
    UiObjSetCommand(o, 15, 0);
}

void fn_801753D4(void) {
    s32 i;
    Ctrl_801753D4* c;
    UiObj* o;

    c = ((Outer_801753D4*)lbl_8034710C)->holder->ctrl;
    o = &PNL(0x1b0)->in->obj;
    UiObjMoveTo(o, 6, -1, -8.0f, 194.0f);
    UiObjSetCommand(o, 10, 0);
    for (i = 0; i < 3; i++) {
        o = &(*(Pnl**)(CWB + 0x178 + i * 4))->in->obj;
        UiObjMoveTo(o, 6, 4, 328.0f, 61 + i * 88);
        if (i == c->f4) {
            UiObjSetCommand(o, 10, i);
        } else {
            UiObjSetCommand(o, 15, i + 1);
        }
    }
    o = &PNL(0x190)->in->obj;
    UiObjMoveTo(o, 6, -1, 24.0f, 384.0f);
    UiObjSetCommand(o, 15, 0);
}

void fn_80175520(void) {
    f32 y;
    s32 i;
    UiObj* p;
    s32 j;
    UiObj* o;

    for (i = 0; i < 3; i++) {
        o = &(*(Pnl**)(CWB + 0x178 + i * 4))->in->obj;
        y = 61 + i * 88;
        UiObjSetLowered(o);
        fn_80199BB8(o, 668.0f, y);
        fn_80199BAC(o, 668.0f, y);
    }
    for (j = 0; j < 2; j++) {
        p = &(*(Pnl**)(CWB + 0x1b0 + j * 4))->in->obj;
        y = 194 + j * 64;
        UiObjSetLowered(p);
        fn_80199BB8(p, -348.0f, y);
        fn_80199BAC(p, -348.0f, y);
    }
    o = &PNL(0x190)->in->obj;
    fn_80199BB8(o, 632.0f, 480.0f);
    fn_80199BAC(o, 632.0f, 480.0f);
}

void fn_801766C4(void) {
    Pnl** arr;
    s32 k;
    UiObj* o;

    o = &PNL(0x184)->in->obj;
    UiObjMoveTo(o, 6, 4, 328.0f, 61.0f);
    UiObjSetCommand(o, 15, 0);
    o = &PNL(0x188)->in->obj;
    UiObjMoveTo(o, 6, -1, 328.0f, 143.0f);
    UiObjSetCommand(o, 15, 0);
    o = &PNL(0x114)->in->obj;
    UiObjMoveTo(o, 6, 4, 328.0f, 204.0f);
    UiObjSetCommand(o, 15, 1);
    arr = (Pnl**)(CWB + 0x10);
    k = *(s32*)((*(u8(*)[0xA50])&lbl_80307638) + 0x3c4) + 0x43;
    o = &arr[k]->in->obj;
    UiObjMoveTo(o, 6, -1, 328.0f, 204.0f);
    UiObjSetCommand(o, 15, 1);
    o = &PNL(0x190)->in->obj;
    UiObjMoveTo(o, 6, -1, 24.0f, 384.0f);
    UiObjSetCommand(o, 15, 0);
    o = &PNL(0x1b4)->in->obj;
    UiObjMoveTo(o, 6, -1, -8.0f, 258.0f);
    UiObjSetCommand(o, 10, 1);
}

void fn_8017796C(void) {
    UiObj* q;
    UiObj* r;
    UiObj* p;
    Ctrl_8017796C* c;
    s32 i;
    UiObj* o;

    c = ((Outer_8017796C*)lbl_8034710C)->holder->ctrl;
    o = &((Pnl**)(CWB + 0x8c))[*(s32*)((*(u8(*)[0xA50])&lbl_80307638) + 0x16c)]->in->obj;
    UiObjMoveTo(o, 6, 5, -348.0f, 125.0f);
    UiObjSetCommand(o, 15, 0);
    p = &PNL(0xdc)->in->obj;
    UiObjMoveTo(p, 6, -1, 668.0f, 204.0f);
    UiObjSetCommand(p, 15, 0);
    for (i = 0; i < 6; i++) {
        if (c->mask & (1 << i)) {
            r = &(*(Pnl**)(CWB + 0xdc + 4 + i * 4))->in->obj;
            UiObjMoveTo(r, 6, -1, 668.0f, 204.0f);
            UiObjSetCommand(r, 15, 0);
        }
    }
    q = &PNL(0x190)->in->obj;
    UiObjMoveTo(q, 6, -1, 632.0f, 480.0f);
    UiObjSetCommand(q, 15, 0);
}

void fn_80178F6C(void) {
    s32 j;
    Ctl* c;
    UiObj* o;
    s32 idx = *(s32*)((*(u8(*)[0xA50])&lbl_80307638) + 0x16c);
    c = ((Outer_80178F6C*)lbl_8034710C)->holder->ctrl;
    o = &(((Pnl_80178F6C**)&(*(CampW_80178F6C*)CWB).pnl[0x1f])[idx])->in->obj;
    UiObjMoveTo(o, 6, 5, -348.0f, 125.0f);
    UiObjSetCommand(o, 0xf, 0);
    o = &(*(CampW_80178F6C*)CWB).pnl[0x3a]->in->obj;
    UiObjMoveTo(o, 6, -1, 668.0f, 204.0f);
    UiObjSetCommand(o, 0xf, 0);
    for (j = 0; j < 6; j++) {
        if (c->mask & (1 << j)) {
            o = &(*(CampW_80178F6C*)CWB).pnl[0x3b + j]->in->obj;
            UiObjMoveTo(o, 6, -1, 668.0f, 204.0f);
            UiObjSetCommand(o, 0xf, 0);
        }
    }
    o = &(*(CampW_80178F6C*)CWB).pnl[0x60]->in->obj;
    UiObjMoveTo(o, 6, -1, 632.0f, 480.0f);
    UiObjSetCommand(o, 0xf, 0);
}

void fn_801808D4(void) {
    s32 i;
    UiObj* o;

    o = &(*(CampW_801808D4*)CWB).pnl[0x21]->in->obj;
    UiObjMoveTo(o, 6, 5, -348.0f, 125.0f);
    UiObjSetCommand(o, 0xf, 0);
    o = &(*(CampW_801808D4*)CWB).pnl[0x6a]->in->obj;
    UiObjMoveTo(o, 6, 5, -348.0f, 189.0f);
    UiObjSetCommand(o, 0xf, 1);
    o = &(*(CampW_801808D4*)CWB).pnl[0x9b]->in->obj;
    UiObjMoveTo(o, 6, -1, -408.0f, 253.0f);
    UiObjSetCommand(o, 0xf, 1);
    o = &(*(CampW_801808D4*)CWB).pnl[0x9c]->in->obj;
    UiObjMoveTo(o, 6, -1, -408.0f, 317.0f);
    UiObjSetCommand(o, 0xf, 1);
    for (i = 0; i < 7; i++) {
        o = &(*(CampW_801808D4*)CWB).pnl[0x48 + i]->in->obj;
        UiObjMoveTo(o, 6, -1, 668.0f, 204.0f);
        UiObjSetCommand(o, 0xf, 0);
    }
    o = &(*(CampW_801808D4*)CWB).pnl[0x60]->in->obj;
    UiObjMoveTo(o, 6, -1, 632.0f, 480.0f);
    UiObjSetCommand(o, 0xf, 0);
}

void fn_80180B80(void) {
    s32 i;
    UiObj* o;

    o = &(*(CampW_80180B80*)CWB).pnl[0x6a]->in->obj;
    fn_80199BB8(o, -348.0f, 189.0f);
    fn_80199BAC(o, -348.0f, 189.0f);
    o = &(*(CampW_80180B80*)CWB).pnl[0x9b]->in->obj;
    fn_80199BB8(o, -408.0f, 253.0f);
    fn_80199BAC(o, -408.0f, 253.0f);
    o = &(*(CampW_80180B80*)CWB).pnl[0x9c]->in->obj;
    fn_80199BB8(o, -408.0f, 317.0f);
    fn_80199BAC(o, -408.0f, 317.0f);
    for (i = 0; i < 7; i++) {
        o = &(*(CampW_80180B80*)CWB).pnl[0x48 + i]->in->obj;
        fn_80199BB8(o, 668.0f, 204.0f);
        fn_80199BAC(o, 668.0f, 204.0f);
    }
    o = &(*(CampW_80180B80*)CWB).pnl[0x60]->in->obj;
    fn_80199BB8(o, 632.0f, 480.0f);
    fn_80199BAC(o, 632.0f, 480.0f);
}

void fn_801854B8(void) {
    Ctl_801854B8* c = ((Outer_801854B8*)lbl_8034710C)->holder->ctrl;
    s32 cur = fn_80194CC8();
    UiObj* o;

    if (cur != lbl_80347124) {
        lbl_803470C8 = 1;
        if (lbl_80347124 == 1) {
            (*(CampW_801854B8*)CWB).pnl[0x1c]->in->hide = 1;
            o = &(*(CampW_801854B8*)CWB).pnl[0x1c]->in->obj;
            UiObjMoveTo(o, 6, 5, -348.0f, 189.0f);
            UiObjSetCommand(o, 10, 0);
            c->mask &= ~4;
            if (c->f4 == 2) {
                c->f4 = 0;
                UiObjSetCommand(&(*(CampW_801854B8*)CWB).pnl[0x1a]->in->obj, 0x15, 0);
                fn_801929B8(4);
            }
        } else {
            (*(CampW_801854B8*)CWB).pnl[0x1c]->in->hide = 1;
            o = &(*(CampW_801854B8*)CWB).pnl[0x1c]->in->obj;
            fn_80199BB8(o, -348.0f, 189.0f);
            fn_80199BAC(o, -348.0f, 189.0f);
            UiObjSetLowered(o);
            UiObjMoveTo(o, 6, 4, -8.0f, 189.0f);
            UiObjSetCommand(o, 0xf, 0);
            c->mask |= 4;
            if (c->f4 == 2) {
                UiObjSetCommand(o, 10, 0);
            }
        }
    }
    lbl_80347124 = cur;
}

void fn_801861F8(void) {
    s32 i;
    UiObj* o;
    Ctl_801861F8* c = ((Outer_801861F8*)lbl_8034710C)->holder->ctrl;

    o = &(*(CampW_801861F8*)CWB).pnl[0x1c]->in->obj;
    UiObjMoveTo(o, 6, -1, -348.0f, 61.0f);
    UiObjSetCommand(o, 0xf, 0);
    for (i = 0; i < 2; i++) {
        o = &(*(CampW_801861F8*)CWB).pnl[0x89 + i]->in->obj;
        UiObjMoveTo(o, 6, 5, -348.0f, (f32)((i + 1) * 64 + 61));
        if (c->f4 == i) {
            UiObjSetCommand(o, 10, i);
        } else {
            UiObjSetCommand(o, 0xf, i + 1);
        }
    }
    o = &(*(CampW_801861F8*)CWB).pnl[0x60]->in->obj;
    UiObjMoveTo(o, 6, -1, 632.0f, 480.0f);
    UiObjSetCommand(o, 0xf, 0);
}

void fn_801867B8(Self* self) {
    UiObj* obj = &self->inner->obj;
    s32 idx;
    f32 y;

    switch (self->inner->type) {
    case 0x66:
        idx = *(s32*)((*(u8(*)[0xA50])&lbl_80307638) + 0x61c);
        break;
    }
    y = (f32)(idx * 0x18 + 0x7c);
    fn_80199BB8(obj, 0.0f, y);
    fn_80199BAC(obj, 0.0f, y);
    switch (self->state) {
    case 0:
    case 0xfe:
        self->state = 1;
    case 1:
        fn_80199F38(obj);
        UiObjCalcRect(obj);
        if (self->inner->kind == 1) {
            self->inner->f8c = ((Outer_801867B8*)lbl_8034710C)->holder->ctrl->f74;
            fn_800FF3EC(self->inner);
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

void fn_8018858C(Self* self) {
    UiObj* obj = &self->inner->obj;
    s32 idx;
    f32 y;

    switch (self->inner->type) {
    case 0x61:
        idx = *(s32*)((*(u8(*)[0xA50])&lbl_80307638) + 0x34c);
        break;
    case 0x62:
        idx = *(s32*)((*(u8(*)[0xA50])&lbl_80307638) + 0x25c);
        break;
    case 0x63:
        idx = *(s32*)((*(u8(*)[0xA50])&lbl_80307638) + 0x43c);
        break;
    case 0x64:
        idx = *(s32*)((*(u8(*)[0xA50])&lbl_80307638) + 0x4b4);
        break;
    case 0x65:
        idx = *(s32*)((*(u8(*)[0xA50])&lbl_80307638) + 0x5a4);
        break;
    }
    y = (f32)(idx * 0x18 + 0xcc);
    fn_80199BB8(obj, 328.0f, y);
    fn_80199BAC(obj, 328.0f, y);
    switch (self->state) {
    case 0:
    case 0xfe:
        self->state = 1;
    case 1:
        fn_80199F38(obj);
        UiObjCalcRect(obj);
        if (self->inner->kind == 1) {
            self->inner->f8c = ((Outer_8018858C*)lbl_8034710C)->holder->ctrl->f74;
            fn_800FF3EC(self->inner);
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

void fn_80189B70(Self_80189B70* self) {
    Sub* sub;
    s32 y;
    s32 x;
    Inner_80189B70* in;
    UiObj* obj = &self->inner->obj;
    f32 z;

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
            in = self->inner;
            sub = in->sub;
            if (sub->str != 0) {
                x = (s32)in->obj.rect[0];
                y = (s32)in->obj.rect[1];
                z = TextGetZ();
                TextSetZ(10.0f + in->f74);
                TextPushColor();
                TextSetColor(0xff201008);
                TextPrint(x + 0x14, y + 0xc, sub->str);
                TextPopColor(1);
                TextSetZ(z);
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

void fn_8018A16C(Self_8018A16C* self) {
    Inner_8018A16C* inner = self->inner;
    UiObj* obj = &inner->obj;
    Sub_8018A16C* sub = inner->sub;

    switch (self->state) {
    case 0:
    case 0xfe:
        self->state = 1;
    case 1:
        if (lbl_803475D8 != 0) {
            self->state = 0xff;
        }
        fn_80199F38(obj);
        UiObjCalcRect(obj);
        if (self->inner->kind == 1) {
            fn_80296EEC(0, 3, 0);
            CampPanelDrawFrame(self->inner);
            fn_80296EEC(1, 3, 1);
            switch (sub->mode) {
            case 1:
                fn_8018A2D8(self->inner);
                break;
            case 0:
                fn_8018D250(self->inner);
                break;
            case 2:
                fn_8018C8B4(self->inner);
                break;
            case 3:
                fn_8018C8B4(self->inner);
                fn_80194F88(self->inner);
                break;
            }
        }
        break;
    case 0x64:
        self->state = 0xff;
        break;
    case 0xff:
        fn_80199F58(inner);
        self->flags |= 0x40;
        break;
    }
}

void fn_8016C61C(void) {
    if ((*(Obj_8016C4C8**)&lbl_803470B0) != 0) {
        (*(Obj_8016C4C8**)&lbl_803470B0)->sub->f4 = 0.0f;
        (*(Obj_8016C4C8**)&lbl_803470B0)->sub->f8 = 0.0f;
    }
    if ((*(Obj_8016C4C8**)&lbl_803470B0) != 0) {
        (*(Obj_8016C4C8**)&lbl_803470B0)->sub->w24 = 0;
    }
    if ((*(Obj_8016C4C8**)&lbl_803470B0) != 0) {
        (*(Obj_8016C4C8**)&lbl_803470B0)->sub->w28 = 0;
    }
    if ((*(Obj_8016C4C8**)&lbl_803470B0) != 0) {
        (*(Obj_8016C4C8**)&lbl_803470B0)->sub->w2c = 0;
    }
    if ((*(Obj_8016C4C8**)&lbl_803470B0) != 0) {
        (*(Obj_8016C4C8**)&lbl_803470B0)->sub->w30 = 0;
    }
    if ((*(Obj_8016C4C8**)&lbl_803470B0) != 0) {
        (*(Obj_8016C4C8**)&lbl_803470B0)->sub->w34 = 0;
    }
    if ((*(Obj_8016C4C8**)&lbl_803470B0) != 0) {
        (*(Obj_8016C4C8**)&lbl_803470B0)->sub->w20 = 0;
    }
    if ((*(Obj_8016C4C8**)&lbl_803470B0) != 0) {
        (*(Obj_8016C4C8**)&lbl_803470B0)->sub->w3c = 0;
    }
    if ((*(Obj_8016C4C8**)&lbl_803470B0) != 0) {
        (*(Obj_8016C4C8**)&lbl_803470B0)->sub->w40 = 0;
    }
    if ((*(Obj_8016C4C8**)&lbl_803470B0) != 0) {
        (*(Obj_8016C4C8**)&lbl_803470B0)->sub->w44 = 0;
    }
    if ((*(Obj_8016C4C8**)&lbl_803470B0) != 0) {
        (*(Obj_8016C4C8**)&lbl_803470B0)->sub->w48 = 0;
    }
    if ((*(Obj_8016C4C8**)&lbl_803470B0) != 0) {
        (*(Obj_8016C4C8**)&lbl_803470B0)->sub->w4c = 0;
    }
    if ((*(Obj_8016C4C8**)&lbl_803470B0) != 0) {
        (*(Obj_8016C4C8**)&lbl_803470B0)->sub->w38 = 0;
    }
    (*(Obj_8016C4C8**)&lbl_803470B0)->sub->b3 = 10;
    (*(Obj_8016C4C8**)&lbl_803470B0)->sub->b2 = 10;
}

s32 fn_8017A510(void) {
    Ctl_8017A510* c = ((Outer_8017A510*)lbl_8034710C)->holder->ctrl;

    if (fn_801C09F8(lbl_80347154, 5)) {
        c->f8 = c->f4;
        c->f4 = fn_8019A21C(c->fc, 1, c->f4, 0, 7);
        goto upd;
    } else if (fn_801C09F8(lbl_80347154, 4)) {
        c->f8 = c->f4;
        c->f4 = fn_8019A21C(c->fc, -1, c->f4, 0, 7);
        goto upd;
    } else if (fn_801C09F8(lbl_80347154, 7)) {
        c->f48 = c->f44;
        c->f44 = 1;
        if (c->f48 != c->f44) goto snd;
    } else if (fn_801C09F8(lbl_80347154, 6)) {
        c->f48 = c->f44;
        c->f44 = 0;
        if (c->f48 != c->f44) goto snd;
    } else if (fn_801C09F8(lbl_80347154, 2)) {
        fn_801929B8(2);
        return 1;
    } else if (fn_801C09F8(lbl_80347154, 1)) {
        fn_801929B8(5);
        return -1;
    }
    goto end;
upd:
    fn_801954D0(lbl_802E9908[c->f4].p);
    fn_801929B8(0);
    goto end;
snd:
    fn_801929B8(0);
end:
    return 0;
}

void fn_8017A754(void) {
    s32 i;
    UiObj* o;

    o = &(*(CampW_8017A754*)CWB).pnl[0x1d]->in->obj;
    UiObjMoveTo(o, 6, -1, -348.0f, 61.0f);
    UiObjSetCommand(o, 0xf, 0);
    for (i = 0; i < 3; i++) {
        o = &(*(CampW_8017A754*)CWB).pnl[0x91 + i]->in->obj;
        UiObjMoveTo(o, 6, 5, -398.0f, (f32)((i + 1) * 64 + 61));
        if (lbl_802E9418[i]() == 1) {
            UiObjSetCommand(o, 10, 0);
        } else {
            UiObjSetCommand(o, 0xf, 0);
        }
    }
    o = &(*(CampW_8017A754*)CWB).pnl[0x60]->in->obj;
    UiObjMoveTo(o, 6, -1, 632.0f, 480.0f);
    UiObjSetCommand(o, 0xf, 0);
}

void fn_8017A8A8(void) {
    s32 i;
    UiObj* o;

    o = &(*(CampW_8017A8A8*)CWB).pnl[0x91]->in->obj;
    UiObjMoveTo(o, 6, 4, -8.0f, 61.0f);
    UiObjSetCommand(o, 0xf, 0);
    for (i = 0; i < 3; i++) {
        o = &(*(CampW_8017A8A8*)CWB).pnl[0x91 + i]->in->obj;
        UiObjMoveTo(o, 6, -1, -8.0f, (f32)((i + 1) * 64 + 61));
        if (lbl_802E9418[i]() == 1) {
            UiObjSetCommand(o, 10, 0);
        } else {
            UiObjSetCommand(o, 0xf, 0);
        }
    }
    o = &(*(CampW_8017A8A8*)CWB).pnl[0x60]->in->obj;
    UiObjMoveTo(o, 6, -1, 24.0f, 384.0f);
    UiObjSetCommand(o, 0xf, 0);
}

void fn_801841DC(void) {
    s32 i;
    u32 mask = 0;
    Ctl_801841DC* c = ((Outer_801841DC*)lbl_8034710C)->holder->ctrl;

    for (i = 0; i < (*(CampW_801841DC*)CWB).count; i++) {
        mask |= 1 << i;
    }
    c->mask = mask;
    if (fn_801953B8() != 0) {
        c->mask |= 0x10;
    }
    if (fn_80194CB8() == 1) {
        c->mask |= 0x20;
    }
    c->f4c = 0x1f;
    c->f1c = 0x1f;
    fn_80195A68(c, 1, 0, 0, 0, 1);
}

void fn_8016022C(Obj_8016022C *obj, Arg_8016022C *arg)
{
    extern Gx_8016022C lbl_80311AC0;
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
            a.item->x = (*(Obj_8016CAB4**)&lbl_803470B8)->st->f20 + ((*(Obj_8016CAB4**)&lbl_803470B8)->st->f4 + x);
        } else {
            a.item->x = (*(Obj_8016CAB4**)&lbl_803470B8)->st->f4 + x;
        }
        a.item->y = (*(Obj_8016CAB4**)&lbl_803470B8)->st->f8 + (*(Obj_8016CAB4**)&lbl_803470B8)->items[i]->y;
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

void fn_8017D35C(void) {
    Ctrl_8017D35C* c;
    UiObj* o;
    UiObj* q;
    s32 i;
    s32 base;
    s32 n;
    s32 off;

    c = *(*(Outer_8017D35C**)&lbl_8034710C)->holder;
    switch (c->f24) {
    case 0: base = 0x7a; n = 5; off = 0; break;
    case 1: base = 0x7f; n = 3; off = 0; break;
    }
    for (i = 0; i < n; i++) {
        q = &(*(CampW_8017D35C*)CWB).pnl[base + i]->in->obj;
        UiObjMoveTo(q, 6, -1, 668.0f, (f32)((off + i) * 64 + 61));
        UiObjSetCommand(q, 15, 0);
        (*(CampW_8017D35C*)CWB).pnl[base + i]->in->f74 -= 150.0f;
    }
    o = &(*(CampW_8017D35C*)CWB).pnl[0x6e]->in->obj;
    UiObjMoveTo(o, 6, 5, -348.0f, 189.0f);
    UiObjSetCommand(o, 15, 0);
    o = &(*(CampW_8017D35C*)CWB).pnl[0x6f]->in->obj;
    UiObjMoveTo(o, 6, 5, -348.0f, 253.0f);
    UiObjSetCommand(o, 15, 1);
    o = &(*(CampW_8017D35C*)CWB).pnl[0x60]->in->obj;
    UiObjMoveTo(o, 6, -1, 632.0f, 480.0f);
    UiObjSetCommand(o, 15, 0);
}

void fn_8017EBD8(void) {
    UiObj* o;
    s32 i;
    s32 base;
    s32 n;
    s32 off;
    Ctrl_8017EBD8* c;

    c = *(*(Outer_8017EBD8**)&lbl_8034710C)->holder;
    o = &(*(CampW_8017EBD8*)CWB).pnl[4]->in->obj;
    UiObjMoveTo(o, 6, -1, -8.0f, 61.0f);
    UiObjSetCommand(o, 15, 0);
    for (i = 0; i < 2; i++) {
        if (c->fc & (1 << i)) {
            o = &(*(CampW_8017EBD8*)CWB).pnl[0x78 + i]->in->obj;
            if (i == c->f4) {
                UiObjMoveTo(o, 6, -1, -8.0f, 125.0f);
                UiObjSetCommand(o, 15, i + 2);
            } else {
                UiObjMoveTo(o, 6, -1, -348.0f, (f32)((i + 1) * 64 + 61));
                UiObjSetCommand(o, 15, i + 2);
            }
        }
    }
    o = &(*(CampW_8017EBD8*)CWB).pnl[0x6c]->in->obj;
    UiObjMoveTo(o, 6, -1, 668.0f, 61.0f);
    UiObjSetCommand(o, 15, 0);
    switch (c->f24) {
    case 0: base = 0x7a; n = 5; off = 1; break;
    case 1: base = 0x7f; n = 3; off = 1; break;
    }
    for (i = 0; i < n; i++) {
        o = &(*(CampW_8017EBD8*)CWB).pnl[base + i]->in->obj;
        UiObjSetLowered(o);
        UiObjMoveTo(o, 6, 5, 668.0f, (f32)((off + i) * 64 + 61));
        UiObjSetCommand(o, 15, i + off);
        (*(CampW_8017EBD8*)CWB).pnl[base + i]->in->f74 -= 150.0f;
    }
}

void fn_8017EE48(void) {
    UiObj* o;
    s32 i;
    s32 base;
    s32 n;
    s32 off;
    Ctrl_8017EE48* c;

    c = *(*(Outer_8017EE48**)&lbl_8034710C)->holder;
    o = &(*(CampW_8017EE48*)CWB).pnl[4]->in->obj;
    UiObjMoveTo(o, 6, -1, -348.0f, 61.0f);
    UiObjSetCommand(o, 15, 0);
    for (i = 0; i < 2; i++) {
        if (c->fc & (1 << i)) {
            o = &(*(CampW_8017EE48*)CWB).pnl[0x78 + i]->in->obj;
            UiObjMoveTo(o, 6, -1, -348.0f, (f32)((i + 1) * 64 + 61));
            UiObjSetCommand(o, 15, i + 2);
        }
    }
    o = &(*(CampW_8017EE48*)CWB).pnl[0x6c]->in->obj;
    UiObjMoveTo(o, 6, -1, 668.0f, 61.0f);
    UiObjSetCommand(o, 15, 0);
    switch (c->f24) {
    case 0: base = 0x7a; n = 5; off = 1; break;
    case 1: base = 0x7f; n = 3; off = 1; break;
    }
    for (i = 0; i < n; i++) {
        o = &(*(CampW_8017EE48*)CWB).pnl[base + i]->in->obj;
        UiObjSetLowered(o);
        UiObjMoveTo(o, 6, 5, 668.0f, (f32)((off + i) * 64 + 61));
        UiObjSetCommand(o, 15, i + off);
        (*(CampW_8017EE48*)CWB).pnl[base + i]->in->f74 += 150.0f;
    }
}

void fn_80188274(Req_80188274 *r, Pos_80188274 *p);
void fn_80188098(Inner_8016F138 *self) {
    extern Spr_80188274 *fn_801D68C4(void *bank, u32 n);
    extern void fn_801D4F0C(Spr_80188274 *s, f32 f1, f32 f2, f32 f3, f32 f4, s32 a, s32 b, s32 c);
    Spr_80188274 *s;
    s32 x;
    s16 y;
    s16 xx;
    s16 i = 0;
    Pos_80188274 *pos = &self->pos;
    Inn_80188098 *inn = self->inn;
    s32 sy;
    y = (s16)self->obj.rect[1];
    x = (s16)self->obj.rect[0];
    xx = x;
    for (; i < 6; i++) {
        s32 on = (((s32)inn->mask) & (1 << i)) != 0;
        if (on == 1) {
            Req_80188274 r;
            f32 a;
            if (i == inn->sel->sel) a = 1.0f; else a = 0.5f;
            r.x = xx;
            r.y = y;
            r.a = a;
            r.idx = i;
            r.b = 10.0f + pos->f0;
            fn_80188274(&r, pos);
        }
        xx += 0x30;
    }
    s = fn_801D68C4(lbl_803470F0, 0x44);
    s->x = (f32)(x + inn->sel->sel * 0x30 + 0xe);
    sy = y + 0x11;
    s->y = (f32)sy;
    fn_801D4F0C(s, -4000.0f, pos->f4, 1.0f, 1.0f, pos->ic, pos->i8, 1);
    s = fn_801D68C4(lbl_803470F0, 0x43);
    s->x = (f32)(x + inn->sel->sel * 0x30 + 0x36);
    s->y = (f32)sy;
    fn_801D4F0C(s, -4000.0f, pos->f4, 1.0f, 1.0f, pos->ic, pos->i8, 1);
}

void fn_80188274(Req_80188274 *r, Pos_80188274 *p) {
    extern void *lbl_803470F4;
    extern Spr_80188274 *fn_801D68C4(void *bank, u32 n);
    extern void fn_801D4F0C(Spr_80188274 *s, f32 f1, f32 f2, f32 f3, f32 f4, s32 a, s32 b, s32 c);
    extern void fn_801D52A8(Spr_80188274 *s, f32 f1, f32 f2, f32 f3, f32 f4, s32 a, s32 b);
    s16 x = r->x;
    s16 y = r->y;
    f32 a, b;
    Spr_80188274 *s1, *s2;
    b = r->b;
    a = r->a;
    switch (r->idx) {
    case 0:
        s1 = fn_801D68C4(lbl_803470F4, 0x2b);
        s2 = fn_801D68C4(lbl_803470F0, 0x34);
        break;
    case 1:
        s1 = fn_801D68C4(lbl_803470F4, 0x2c);
        s2 = fn_801D68C4(lbl_803470F0, 0x35);
        break;
    case 2:
        s1 = fn_801D68C4(lbl_803470F4, 0x2e);
        s2 = fn_801D68C4(lbl_803470F0, 0x37);
        break;
    case 3:
        s1 = fn_801D68C4(lbl_803470F4, 0x2d);
        s2 = fn_801D68C4(lbl_803470F0, 0x36);
        break;
    case 4:
        s1 = fn_801D68C4(lbl_803470F4, 0x2f);
        s2 = fn_801D68C4(lbl_803470F0, 0x38);
        break;
    case 5:
        s1 = fn_801D68C4(lbl_803470F4, 0x30);
        s2 = fn_801D68C4(lbl_803470F0, 0x39);
        break;
    }
    s2->x = (f32)(x + 0x1c);
    s2->y = (f32)(y + 6);
    fn_801D4F0C(s2, b, p->f4, a, p->f18 + p->f1c, p->ic, p->i8, 1);
    s1->x = (f32)(x + 0x1e);
    s1->y = (f32)(y + 0x1e);
    fn_801D52A8(s1, b, p->f4, a, p->f18 + p->f1c, p->ic, p->i8);
}

void fn_8018C6A8(Obj_8018C6A8 *self, f32 f) {
    extern void *lbl_803470E8;
    extern void *lbl_803470F4;
    extern void *fn_801D68C4(void *bank, u32 n);
    extern void fn_8019A15C(void *p, s32 a, s32 b, s32 c);
    extern void fn_80199FFC(void *p, s32 a, void *b, s32 c, s32 d, s32 e);
    Pos_8018C6A8 *p = &self->pos;
    p->f0 = -6790.0f;
    p->f4 = 0.0f;
    p->f10 = 1.0f;
    p->f14 = f;
    p->f18 = 1.0f;
    p->f1c = 0.0f;
    p->i8 = 0;
    p->ic = 0;
    fn_8019A15C(p, 1, 8, 1);
    fn_80199FFC(p, 0, fn_801D68C4(lbl_803470F0, 10), 0, 0, 0);
    fn_80199FFC(p, 0, fn_801D68C4(lbl_803470F4, 0x10), 0x10, 6, 2);
    fn_80199FFC(p, 1, fn_801D68C4(lbl_803470F4, 0x11), 0x58, 6, 2);
    fn_80199FFC(p, 2, fn_801D68C4(lbl_803470F4, 0x12), 0xa0, 6, 2);
    fn_80199FFC(p, 3, fn_801D68C4(lbl_803470F4, 0x13), 0xe8, 6, 2);
    fn_80199FFC(p, 4, fn_801D68C4(lbl_803470F4, 0x14), 0x10, 0x1e, 2);
    fn_80199FFC(p, 5, fn_801D68C4(lbl_803470F4, 0x15), 0x58, 0x1e, 2);
    fn_80199FFC(p, 6, fn_801D68C4(lbl_803470F4, 0x16), 0xa0, 0x1e, 2);
    fn_80199FFC(p, 7, fn_801D68C4(lbl_803470F4, 0x35), 6, 6, 2);
    p->sp->spr = fn_801D68C4(lbl_803470E8, 2);
    p->fp[0] = 0.0f;
    p->fp[1] = 0.0f;
    p->spr44 = fn_801D68C4(lbl_803470F0, 1);
}

void fn_8018FB9C(Obj_8018FB9C *self, s32 id) {
    s16 x = (s16)self->x;
    s16 y = (s16)self->y;
    fn_8019A374(id == -1 ? 0 : fn_80195184(id), (f32)(x + 0x33), (f32)(y + 0x22), 10.0f + self->z, 0xff201008, 0);
    fn_8019A374(id == -1 ? 0 : fn_80195148(id), (f32)(x + 0x7b), (f32)(y + 0x22), 10.0f + self->z, 0xff201008, 0);
    fn_8019A374(id == -1 ? 0 : fn_801950D0(id), (f32)(x + 0xc3), (f32)(y + 0x22), 10.0f + self->z, 0xff201008, 0);
    fn_8019A374(id == -1 ? 0 : fn_8019510C(id), (f32)(x + 0x10b), (f32)(y + 0x22), 10.0f + self->z, 0xff201008, 0);
}

inline s32 Test_80192EDC(u32 b) {
    return ((*(u32(*)[])&lbl_80310B3C)[b >> 5] & (1 << (b & 31))) != 0;
}

void fn_80192EDC(Cur_80192EDC *c) {
    s32 row = c->row;
    s32 col = c->col;
    s32 w = 8;
    s32 lim;
    s32 start;
    s32 i;
    if (c->mode == 0) w = 6;
    lim = 0x58;
    if (c->mode == 0) lim = 0x18;
    c->found = 0;
    if (c->dir == -1) {
        start = row * w + col;
        for (i = start - 1; i >= 0; i--) {
            if (Test_80192EDC(lbl_802EBA00[i].id) != 0) {
                c->found = 1;
                c->found_idx = i;
                break;
            }
        }
        if (c->found != 1) {
            for (i = lim - 1; i > start; i--) {
                if (Test_80192EDC(lbl_802EBA00[i].id) != 0) {
                    c->found = 1;
                    c->found_idx = i;
                    break;
                }
            }
        }
    } else {
        start = row * w + col;
        for (i = start + 1; i < lim; i++) {
            if (Test_80192EDC(lbl_802EBA00[i].id) != 0) {
                c->found = 1;
                c->found_idx = i;
                break;
            }
        }
        if (c->found != 1) {
            for (i = 0; i < start; i++) {
                if (Test_80192EDC(lbl_802EBA00[i].id) != 0) {
                    c->found = 1;
                    c->found_idx = i;
                    break;
                }
            }
        }
    }
    if (c->found == 1) {
        c->row = c->found_idx / w;
        c->col = c->found_idx % w;
    }
}

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

void fn_80177D7C(void) {
    Ctrl_80177D7C* c;
    s32 i;

    c = ((Outer_80177D7C*)lbl_8034710C)->holder->ctrl;
    CampMenuHideAllPanels();
    ((Pnl_80177D7C**)(CWB + 0x10))[*(s32*)(lbl_80307638 + 0x7c)]->in->hide = 1;
    ((Pnl_80177D7C**)(CWB + 0x8c))[*(s32*)(lbl_80307638 + 0x16c)]->in->hide = 1;
    PNL_80177D7C(0xdc)->in->hide = 1;
    for (i = 0; i < 6; i++) {
        if (c->mask & (1 << i)) {
            (*(Pnl_80177D7C**)(CWB + 0xdc + 4 + i * 4))->in->hide = 1;
        }
    }
    PNL_80177D7C(0x190)->in->hide = 1;
    PNL_80177D7C(0x194)->in->hide = 0;
}

void fn_80172C60(void) {
    UiObj* ui;
    ui = &PNL_80172C60(0x20)->win->ui;
    UiObjMoveTo(ui, 6, 5, -348.0f, 125.0f);
    UiObjSetCommand(ui, 0xF, 0);
    ui = &PNL_80172C60(0x1E8)->win->ui;
    UiObjMoveTo(ui, 6, 5, -348.0f, 189.0f);
    UiObjSetCommand(ui, 0xF, 1);
    ui = &PNL_80172C60(0x1EC)->win->ui;
    UiObjMoveTo(ui, 6, 5, -348.0f, 253.0f);
    UiObjSetCommand(ui, 0xF, 2);
    ui = &PNL_80172C60(0x224)->win->ui;
    UiObjSetLowered(ui);
    UiObjMoveTo(ui, 6, -1, 668.0f, 61.0f);
    UiObjSetCommand(ui, 0xF, 0);
    ui = &PNL_80172C60(0x21C)->win->ui;
    UiObjSetLowered(ui);
    UiObjMoveTo(ui, 6, -1, 668.0f, 119.0f);
    UiObjSetCommand(ui, 0xF, 0);
    ui = &PNL_80172C60(0x228)->win->ui;
    UiObjSetLowered(ui);
    UiObjMoveTo(ui, 6, -1, 668.0f, 183.0f);
    UiObjSetCommand(ui, 0xF, 1);
    ui = &PNL_80172C60(0x220)->win->ui;
    UiObjSetLowered(ui);
    UiObjMoveTo(ui, 6, -1, 668.0f, 241.0f);
    UiObjSetCommand(ui, 0xF, 1);
    ui = &PNL_80172C60(0x190)->win->ui;
    UiObjSetLowered(ui);
    UiObjMoveTo(ui, 6, -1, 632.0f, 480.0f);
    UiObjSetCommand(ui, 0xF, 1);
}

void fn_80173104(void) {
    UiObj* ui;
    ui = &PNL_80173104(0x20)->win->ui;
    fn_80199BB8(ui, -348.0f, 125.0f);
    fn_80199BAC(ui, -348.0f, 125.0f);
    ui = &PNL_80173104(0x1E8)->win->ui;
    fn_80199BB8(ui, -348.0f, 189.0f);
    fn_80199BAC(ui, -348.0f, 189.0f);
    ui = &PNL_80173104(0x1EC)->win->ui;
    fn_80199BB8(ui, -348.0f, 253.0f);
    fn_80199BAC(ui, -348.0f, 253.0f);
    ui = &PNL_80173104(0x224)->win->ui;
    fn_80199BB8(ui, 668.0f, 61.0f);
    fn_80199BAC(ui, 668.0f, 61.0f);
    ui = &PNL_80173104(0x21C)->win->ui;
    fn_80199BB8(ui, 668.0f, 119.0f);
    fn_80199BAC(ui, 668.0f, 119.0f);
    ui = &PNL_80173104(0x228)->win->ui;
    fn_80199BB8(ui, 668.0f, 183.0f);
    fn_80199BAC(ui, 668.0f, 183.0f);
    ui = &PNL_80173104(0x220)->win->ui;
    fn_80199BB8(ui, 668.0f, 241.0f);
    fn_80199BAC(ui, 668.0f, 241.0f);
    ui = &PNL_80173104(0x190)->win->ui;
    fn_80199BB8(ui, 632.0f, 480.0f);
    fn_80199BAC(ui, 632.0f, 480.0f);
}

void fn_80174F40(s32 unused, s8 mode) {
    Ctrl_80174F40* c = *(*(Outer_80174F40**)&lbl_8034710C)->hold;
    UiObj* q;
    UiObj* p;
    s16 se;
    s32 i;
    UiObj* ui;
    f32 x, y, x2, y2, x3, y3;
    switch (mode) {
    case 0:
        ui = &((Pnl_80174F40**)(CWB + 0x10))[c->a]->win->ui;
        x = -8.0f;
        y = 61.0f;
        x2 = 24.0f;
        y2 = 384.0f;
        x3 = 328.0f;
        y3 = 194.0f;
        se = 4;
        break;
    case 1:
        ui = &((Pnl_80174F40**)(CWB + 0x10))[c->b]->win->ui;
        x = -348.0f;
        y = 61.0f;
        x2 = 632.0f;
        y2 = 480.0f;
        x3 = 668.0f;
        y3 = 194.0f;
        se = 5;
        break;
    }
    UiObjFinish(ui);
    UiObjMoveTo(ui, 6, -1, x, y);
    UiObjSetCommand(ui, 0xF, 0);
    ui = &PNL_80174F40(0x1B0)->win->ui;
    UiObjFinish(ui);
    UiObjMoveTo(ui, 6, -1, x, y3);
    UiObjSetCommand(ui, 0xF, 1);
    for (i = 0; i < 3; i++) {
        p = &((Pnl_80174F40**)CWB)[0x178 / 4 + i]->win->ui;
        UiObjFinish(p);
        UiObjMoveTo(p, 6, se, x3, y + (f32)(i * 0x58));
        UiObjSetCommand(p, 0xF, i);
    }
    q = &PNL_80174F40(0x190)->win->ui;
    UiObjFinish(q);
    UiObjMoveTo(q, 6, -1, x2, y2);
    UiObjSetCommand(q, 0xF, 0);
}

void fn_801764E4(void) {
    UiObj* ui;
    Pnl_801764E4** arr;
    s32 k;
    ui = &PNL_801764E4(0x1B0)->win->ui;
    UiObjMoveTo(ui, 6, 4, -348.0f, 194.0f);
    UiObjSetCommand(ui, 0xA, 1);
    ui = &PNL_801764E4(0x1B4)->win->ui;
    UiObjMoveTo(ui, 6, 4, -348.0f, 258.0f);
    UiObjSetCommand(ui, 0xA, 2);
    ui = &PNL_801764E4(0x184)->win->ui;
    UiObjMoveTo(ui, 6, 4, 668.0f, 61.0f);
    UiObjSetCommand(ui, 0xF, 0);
    ui = &PNL_801764E4(0x188)->win->ui;
    UiObjMoveTo(ui, 6, -1, 668.0f, 143.0f);
    UiObjSetCommand(ui, 0xF, 0);
    ui = &PNL_801764E4(0x114)->win->ui;
    UiObjMoveTo(ui, 6, -1, 668.0f, 204.0f);
    UiObjSetCommand(ui, 0xF, 1);
    arr = (Pnl_801764E4**)(CWB + 0x10);
    k = *(s32*)(lbl_80307638 + 0x3C4) + 0x43;
    ui = &arr[k]->win->ui;
    UiObjMoveTo(ui, 6, -1, 668.0f, 204.0f);
    UiObjSetCommand(ui, 0xF, 1);
    ui = &PNL_801764E4(0x190)->win->ui;
    UiObjMoveTo(ui, 6, -1, 632.0f, 480.0f);
    UiObjSetCommand(ui, 0xF, 0);
}

void fn_80176868(void) {
    UiObj* ui;
    Pnl_80176868** arr;
    s32 k;
    ui = &PNL_80176868(0x1B4)->win->ui;
    fn_80199BB8(ui, -348.0f, 258.0f);
    fn_80199BAC(ui, -348.0f, 258.0f);
    ui = &PNL_80176868(0x18C)->win->ui;
    fn_80199BB8(ui, -348.0f, 258.0f);
    fn_80199BAC(ui, -348.0f, 258.0f);
    ui = &PNL_80176868(0x184)->win->ui;
    fn_80199BB8(ui, 668.0f, 61.0f);
    fn_80199BAC(ui, 668.0f, 61.0f);
    ui = &PNL_80176868(0x188)->win->ui;
    fn_80199BB8(ui, 668.0f, 143.0f);
    fn_80199BAC(ui, 668.0f, 143.0f);
    ui = &PNL_80176868(0x114)->win->ui;
    fn_80199BB8(ui, 668.0f, 204.0f);
    fn_80199BAC(ui, 668.0f, 204.0f);
    arr = (Pnl_80176868**)(CWB + 0x10);
    k = *(s32*)(lbl_80307638 + 0x3C4) + 0x43;
    ui = &arr[k]->win->ui;
    fn_80199BB8(ui, 668.0f, 204.0f);
    fn_80199BAC(ui, 668.0f, 204.0f);
    ui = &PNL_80176868(0x19C)->win->ui;
    fn_80199BB8(ui, 328.0f, 204.0f);
    fn_80199BAC(ui, 328.0f, 204.0f);
    ui = &PNL_80176868(0x190)->win->ui;
    fn_80199BB8(ui, 632.0f, 480.0f);
    fn_80199BAC(ui, 632.0f, 480.0f);
}

void fn_80178D2C(s32 unused, s8 mode) {
    Ctrl_80178D2C* c = *(*(Outer_80178D2C**)&lbl_8034710C)->hold;
    UiObj* q;
    UiObj* p;
    s16 se;
    s32 i;
    UiObj* ui;
    f32 x, y, x2, y2, x3, y3;
    switch (mode) {
    case 0:
        ui = &((Pnl_80178D2C**)(CWB + 0x10))[c->a]->win->ui;
        x = 328.0f;
        y = 204.0f;
        x2 = -8.0f;
        y2 = 61.0f;
        x3 = 24.0f;
        y3 = 384.0f;
        se = 4;
        break;
    case 1:
        ui = &((Pnl_80178D2C**)(CWB + 0x10))[c->b]->win->ui;
        x = 668.0f;
        y = 204.0f;
        x2 = -348.0f;
        y2 = 61.0f;
        x3 = 632.0f;
        y3 = 480.0f;
        se = 5;
        break;
    }
    UiObjFinish(ui);
    UiObjMoveTo(ui, 6, se, x2, y2);
    UiObjSetCommand(ui, 0xF, 2);
    ui = &PNL_80178D2C(0xF8)->win->ui;
    UiObjMoveTo(ui, 6, se, x, y);
    UiObjSetCommand(ui, 0xF, 0);
    for (i = 0; i < 6; i++) {
        p = &((Pnl_80178D2C**)CWB)[0xFC / 4 + i]->win->ui;
        UiObjMoveTo(p, 6, -1, x, y);
        UiObjSetCommand(p, 0xF, 0);
    }
    q = &PNL_80178D2C(0x190)->win->ui;
    UiObjFinish(q);
    UiObjMoveTo(q, 6, se, x3, y3);
    UiObjSetCommand(q, 0xF, 3);
}

void fn_8016C4C8(s8 mode) {
    (*(Obj_8016C4C8**)&lbl_803470B0) = ((Obj_8016C4C8*)fn_802268E8((void *)(lbl_803475A8), (void *)((void*)fn_8016C204)));
    (*(Obj_8016C4C8**)&lbl_803470B0)->sub = fn_801E1C7C(0x50);
    fn_8016C61C();
    if ((*(Obj_8016C4C8**)&lbl_803470B0) != 0) {
        (*(Obj_8016C4C8**)&lbl_803470B0)->sub->b1 = 1;
    }
    if ((*(Obj_8016C4C8**)&lbl_803470B0) != 0) {
        (*(Obj_8016C4C8**)&lbl_803470B0)->sub->b0 = mode;
    }
    switch (mode) {
    case 0:
    case 1:
    case 2:
    case 3:
        if ((*(Obj_8016C4C8**)&lbl_803470B0) != 0) {
            (*(Obj_8016C4C8**)&lbl_803470B0)->sub->w24 = 0;
        }
        if ((*(Obj_8016C4C8**)&lbl_803470B0) != 0) {
            (*(Obj_8016C4C8**)&lbl_803470B0)->sub->w20 = 0;
        }
        if ((*(Obj_8016C4C8**)&lbl_803470B0) != 0) {
            (*(Obj_8016C4C8**)&lbl_803470B0)->sub->w30 = 360;
        }
        if ((*(Obj_8016C4C8**)&lbl_803470B0) != 0) {
            (*(Obj_8016C4C8**)&lbl_803470B0)->sub->w28 = 50;
        }
        if ((*(Obj_8016C4C8**)&lbl_803470B0) != 0) {
            (*(Obj_8016C4C8**)&lbl_803470B0)->sub->w3c = 0;
        }
        if ((*(Obj_8016C4C8**)&lbl_803470B0) != 0) {
            (*(Obj_8016C4C8**)&lbl_803470B0)->sub->w38 = 0;
        }
        if ((*(Obj_8016C4C8**)&lbl_803470B0) != 0) {
            (*(Obj_8016C4C8**)&lbl_803470B0)->sub->w48 = 700;
        }
        if ((*(Obj_8016C4C8**)&lbl_803470B0) != 0) {
            (*(Obj_8016C4C8**)&lbl_803470B0)->sub->w40 = 75;
        }
    }
}

void fn_8016E3E0(Obj_8016E3E0* o) {
    s16 x = o->x;
    s16 y = o->y;
    Spr_8016E3E0* s;
    f32 oz;
    f32 f;
    f = o->f3c;
    oz = TextGetZ();
    TextSetZ(10.0f + o->z);
    TextPushColor();
    TextSetColor(0xff201008);
    s = ((Spr_8016E3E0*)fn_801D68C4((void *)(lbl_803470F0), 0x1d));
    s->x = x + 16;
    s->y = y - 2;
    fn_801D4F0C((void *)(s), 0, 0, 1, 20.0f + o->z, 0.0f, f, 1.0f);
    TextPrint(x + 0x54, y + 6, fn_80193FAC());
    TextPopColor(1);
    TextSetZ(oz);
}

void fn_801677D0(void *a, s32 b, f32 x, f32 y, f32 z, f32 w, u8 c, s32 d)
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

s8 fn_80167EF0(Arg_80167EF0 *a)
{
    void *p;
    s8 k;
    f32 t;
    f32 ty;
    f32 tx;
    f32 d;
    f32 x;
    f32 tz;
    Vec_80167EF0 o;
    Vec_80167EF0 v;

    if ((*(Cam_80167EF0 **)&lbl_80347450) != 0) {
        p = fn_8015F1A0(a->x18 >> 16);
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
    k = a->x18 & 0xff;
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
    Sel_8016FB2C* sel = *(*(Hold_8016FB2C**)&lbl_8034710C)->sel;
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
    switch (sel->page) {
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

void fn_8017379C(void) {
    u8 buf[0x60];
    s32 i, j;
    s32 k;
    Ctrl_8017379C* c = (*(Outer_8017379C**)&lbl_8034710C)->holder->ctrl;
    W_8017379C* w = MID()->hm->w;
    for (i = 0; i < 11; i++) {
        for (j = 0; j < 2; j++) {
            fn_80194C68((void *)(buf), i, j, -1);
        }
    }
    for (i = 0; i < 11; i++) {
        for (j = 0; j < 2; j++) {
            k = i * 2 + j;
            if (fn_801E4BF4(k) != 0) {
                if (fn_801E4BBC(k) != 0) {
                    fn_80194C68((void *)(buf), i, 0, k);
                } else {
                    fn_80194C68((void *)(buf), i, 1, k);
                }
            } else {
                fn_80194C68((void *)(buf), i, j, -1);
            }
        }
    }
    fn_801869B8((void *)(w), (void *)(buf));
    c->mask = w->mask;
    for (i = 0; i < 32; i++) {
        if (c->mask & (1 << i)) {
            c->sel = i;
            break;
        }
    }
    c->f4c = 0;
    fn_80195A68((void *)(c), 1, 0, 0, 0, 1);
}

void fn_801784D8(void) {
    u8* cw = CWB;
    u8* tb = lbl_80307638;
    Ctrl_801784D8* c = *(*(Outer_801784D8**)&lbl_8034710C)->hold;
    Win_801784D8* w;
    Eff_801784D8* e;
    f32 x;
    if (*(s8*)(cw + 0xC) > 1) {
        w = ((Pnl_801784D8**)(cw + 0x10))[*(s32*)(tb + 0x7C)]->win;
        e = ((Eff_801784D8*)fn_801D68C4((void *)(lbl_803470F0), 0x45));
        e->x = 24.0f + w->rx;
        e->y = -16.0f + w->ry;
        fn_800FF348((void *)(e), 0, -3100.0f, 1.0f, *(f32*)(cw + 0x34C));
        e = ((Eff_801784D8*)fn_801D68C4((void *)(lbl_803470F0), 0x46));
        e->x = 272.0f + w->rx;
        e->y = -16.0f + w->ry;
        fn_800FF348((void *)(e), 0, -3100.0f, 1.0f, *(f32*)(cw + 0x34C));
    }
    if ((s8)fn_801952D0(c->f1c) > 1) {
        w = (*(Pnl_801784D8**)(CWB + 0xF8))->win;
        x = 5.0f + w->rx + (f32)(c->f14 * 0x30);
        e = ((Eff_801784D8*)fn_801D68C4((void *)(lbl_803470F0), 0x44));
        e->x = x;
        e->y = 179.0f;
        fn_800FF348((void *)(e), 0, -3100.0f, 1.0f, *(f32*)(cw + 0x354));
        x = 47.0f + w->rx + (f32)(c->f14 * 0x30);
        e = ((Eff_801784D8*)fn_801D68C4((void *)(lbl_803470F0), 0x43));
        e->x = x;
        e->y = 179.0f;
        fn_800FF348((void *)(e), 0, -3100.0f, 1.0f, *(f32*)(cw + 0x354));
    }
}

static inline void vset(Vec *d, Vec *s) {
    f32 x = s->x;
    f32 y = s->y;
    f32 z = s->z;
    d->z = z;
    d->y = y;
    d->x = x;
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

void fn_80179388(void) {
    Ctrl_80179388* c;
    s32 i;
    u8* w = lbl_80307638;

    c = *((Outer_80179388 *)lbl_8034710C)->holder;
    CampMenuHideAllPanels();
    ((Pnl_80179388 *)((Pnl_80179388 *)camp_work.objs[*(s32*)(lbl_80307638 + 0x7c)]))->in->hide = 1;
    for (i = 0; i < *(s8 *)(CWB + 0xc); i++) {
        ((Pnl_80179388 *)((Pnl_80179388 *)camp_work.objs[i]))->in->hide = 1;
    }
    ((Pnl_80179388 *)((Pnl_80179388 *)camp_work.objs[*(s32*)(w + 0x16c) + 0x1f]))->in->hide = 1;
    ((Pnl_80179388 *)((Pnl_80179388 *)camp_work.objs[0x3a]))->in->hide = 1;
    for (i = 0; i < 6; i++) {
        if (c->mask & (1 << i)) {
            ((Pnl_80179388 *)((Pnl_80179388 *)camp_work.objs[0x3b + i]))->in->hide = 1;
        }
    }
    ((Pnl_80179388 *)((Pnl_80179388 *)camp_work.objs[0x60]))->in->hide = 1;
    ((Pnl_80179388 *)((Pnl_80179388 *)camp_work.objs[0x62]))->in->hide = 0;
}

void fn_8017BF14(void) {
    s32 i;
    UiObj* o;
    s32 base;

    switch (*(s32*)(lbl_80307638 + 0x54c)) {
    case 0: base = 0x70; break;
    case 1: base = 0x72; break;
    }
    for (i = 0; i < 2; i++) {
        o = &((Pnl_8017BF14 *)((Pnl_8017BF14 *)camp_work.objs[base + i]))->in->obj;
        UiObjMoveTo(o, 6, 5, -348.0f, (f32)((i + 2) * 64 + 61));
        UiObjSetCommand(o, 10, i);
    }
    switch (*(s32*)(lbl_80307638 + 0x54c)) {
    case 0: base = 0x74; break;
    case 1: base = 0x75; break;
    }
    o = &((Pnl_8017BF14 *)((Pnl_8017BF14 *)camp_work.objs[base]))->in->obj;
    UiObjMoveTo(o, 6, -1, 668.0f, 61.0f);
    UiObjSetCommand(o, 15, 0);
    for (i = 0; i < 7; i++) {
        o = &((Pnl_8017BF14 *)((Pnl_8017BF14 *)camp_work.objs[0x4f + i]))->in->obj;
        UiObjMoveTo(o, 6, -1, 668.0f, 204.0f);
        UiObjSetCommand(o, 15, 0);
    }
    o = &((Pnl_8017BF14 *)((Pnl_8017BF14 *)camp_work.objs[0x60]))->in->obj;
    UiObjMoveTo(o, 6, -1, 632.0f, 480.0f);
    UiObjSetCommand(o, 15, 0);
}

void fn_8017C0EC(void) {
    s32 i;
    UiObj* o;
    s32 base;

    switch (*(s32*)(lbl_80307638 + 0x54c)) {
    case 0: base = 0x70; break;
    case 1: base = 0x72; break;
    }
    for (i = 0; i < 2; i++) {
        o = &((Pnl_8017C0EC *)((Pnl_8017C0EC *)camp_work.objs[base + i]))->in->obj;
        UiObjMoveTo(o, 6, 4, -8.0f, (f32)((i + 2) * 64 + 61));
        UiObjSetCommand(o, 10, i);
    }
    switch (*(s32*)(lbl_80307638 + 0x54c)) {
    case 0: base = 0x74; break;
    case 1: base = 0x75; break;
    }
    o = &((Pnl_8017C0EC *)((Pnl_8017C0EC *)camp_work.objs[base]))->in->obj;
    UiObjMoveTo(o, 6, 4, 328.0f, 61.0f);
    UiObjSetCommand(o, 15, 0);
    for (i = 0; i < 7; i++) {
        o = &((Pnl_8017C0EC *)((Pnl_8017C0EC *)camp_work.objs[0x4f + i]))->in->obj;
        UiObjMoveTo(o, 6, -1, 328.0f, 204.0f);
        UiObjSetCommand(o, 15, 0);
    }
    o = &((Pnl_8017C0EC *)((Pnl_8017C0EC *)camp_work.objs[0x60]))->in->obj;
    UiObjMoveTo(o, 6, -1, 24.0f, 384.0f);
    UiObjSetCommand(o, 15, 0);
}

void fn_8017F310(void) {
    UiObj* o;
    s32 i;
    f32 y;
    Ctrl_8017F310* c;

    c = *((Outer_8017F310 *)lbl_8034710C)->holder;
    o = &((Pnl_8017F310 *)((Pnl_8017F310 *)camp_work.objs[*(s32*)(lbl_80307638 + 0x7c)]))->in->obj;
    fn_80199BB8(o, -8.0f, 61.0f);
    fn_80199BAC(o, -8.0f, 61.0f);
    for (i = 0; i < 2; i++) {
        if (c->fc & (1 << i)) {
            o = &((Pnl_8017F310 *)((Pnl_8017F310 *)camp_work.objs[0x78 + i]))->in->obj;
            y = (f32)((i + 1) * 64 + 61);
            fn_80199BB8(o, -348.0f, y);
            fn_80199BAC(o, -348.0f, y);
        }
    }
    o = &((Pnl_8017F310 *)((Pnl_8017F310 *)camp_work.objs[0x6c]))->in->obj;
    fn_80199BB8(o, 668.0f, 61.0f);
    fn_80199BAC(o, 668.0f, 61.0f);
    for (i = 0; i < 5; i++) {
        o = &((Pnl_8017F310 *)((Pnl_8017F310 *)camp_work.objs[0x7a + i]))->in->obj;
        y = (f32)((i + 1) * 64 + 61);
        fn_80199BB8(o, 668.0f, y);
        fn_80199BAC(o, 668.0f, y);
    }
    for (i = 5; i < 8; i++) {
        o = &((Pnl_8017F310 *)((Pnl_8017F310 *)camp_work.objs[0x7a + i]))->in->obj;
        y = (f32)((i - 4) * 64 + 61);
        fn_80199BB8(o, 668.0f, y);
        fn_80199BAC(o, 668.0f, y);
    }
}

void fn_80180694(s8 unused, s8 mode) {
    Ctrl_80180694* c;
    UiObj* p;
    s16 se;
    s32 i;
    UiObj* o;
    f32 bx, by, ax, ay, cx, cy;

    c = *((Outer_80180694 *)lbl_8034710C)->holder;
    switch (mode) {
    case 0:
        o = &((Pnl_80180694 *)((Pnl_80180694 *)camp_work.objs[c->f24]))->in->obj;
        se = 4;
        bx = 328.0f; by = 204.0f;
        ax = -8.0f; ay = 61.0f;
        cx = 24.0f; cy = 384.0f;
        break;
    case 1:
        o = &((Pnl_80180694 *)((Pnl_80180694 *)camp_work.objs[c->f28]))->in->obj;
        se = 5;
        bx = 668.0f; by = 204.0f;
        ax = -348.0f; ay = 61.0f;
        cx = 632.0f; cy = 480.0f;
        break;
    }
    UiObjFinish(o);
    UiObjMoveTo(o, 6, se, ax, ay);
    UiObjSetCommand(o, 15, 2);
    o = &((Pnl_80180694 *)((Pnl_80180694 *)camp_work.objs[0x48]))->in->obj;
    UiObjMoveTo(o, 6, se, bx, by);
    UiObjSetCommand(o, 15, 0);
    for (i = 0; i < 6; i++) {
        p = &((Pnl_80180694 *)((Pnl_80180694 *)camp_work.objs[0x49 + i]))->in->obj;
        UiObjMoveTo(p, 6, -1, bx, by);
        UiObjSetCommand(p, 15, 0);
    }
    o = &((Pnl_80180694 *)((Pnl_80180694 *)camp_work.objs[0x60]))->in->obj;
    UiObjFinish(o);
    UiObjMoveTo(o, 6, se, cx, cy);
    UiObjSetCommand(o, 15, 3);
}

void fn_80180CCC(void) {
    Ctrl_80180CCC* c;
    s32 i;

    c = *((Outer_80180CCC *)lbl_8034710C)->holder;
    CampMenuHideAllPanels();
    ((Pnl_80180CCC *)((Pnl_80180CCC *)camp_work.objs[*(s32*)(lbl_80307638 + 0x7c)]))->in->hide = 1;
    for (i = 0; i < *(s8 *)(CWB + 0xc); i++) {
        ((Pnl_80180CCC *)((Pnl_80180CCC *)camp_work.objs[i]))->in->hide = 1;
    }
    ((Pnl_80180CCC *)((Pnl_80180CCC *)camp_work.objs[0x21]))->in->hide = 1;
    ((Pnl_80180CCC *)((Pnl_80180CCC *)camp_work.objs[0x6a]))->in->hide = 1;
    ((Pnl_80180CCC *)((Pnl_80180CCC *)camp_work.objs[0x9b]))->in->hide = 1;
    ((Pnl_80180CCC *)((Pnl_80180CCC *)camp_work.objs[0x9c]))->in->hide = 1;
    ((Pnl_80180CCC *)((Pnl_80180CCC *)camp_work.objs[0x48]))->in->hide = 1;
    for (i = 0; i < 6; i++) {
        if (c->mask & (1 << i)) {
            ((Pnl_80180CCC *)((Pnl_80180CCC *)camp_work.objs[0x49 + i]))->in->hide = 1;
        }
    }
    ((Pnl_80180CCC *)((Pnl_80180CCC *)camp_work.objs[0x60]))->in->hide = 1;
    ((Pnl_80180CCC *)((Pnl_80180CCC *)camp_work.objs[0x64]))->in->hide = 0;
}

void fn_801887EC(Obj_801887EC *self) {
    Node_801887EC *node = self->node;
    const char *str;
    s16 x, y;
    s32 id;
    void *ui = node->ui;
    In_801887EC *in = node->in;
    if (lbl_803475D8 != 0) {
        self->state = 0xff;
    }
    switch (self->state) {
    case 0xFE:
    case 0:
        self->state = 1;
    case 1:
        fn_80199F38(ui);
        UiObjCalcRect(ui);
        if (self->node->x0 == 1) {
            CampPanelDrawFrame();
            if (in->b3 == 1) {
                fn_80188A18(self->node);
            } else {
                switch (in->kind) {
                case 1: id = 0x3a; str = (const char *)lbl_802EBB54; break;
                case 0: id = 0x33; str = (const char *)lbl_802EBB48; break;
                case 3: id = 0x41; str = (const char *)lbl_802EBB34; break;
                case 2: id = 0x48; str = (const char *)lbl_802EBB68; break;
                case 4: id = 0x4f; str = (const char *)lbl_802EBB7C; break;
                }
                if (id != self->node->x4) {
                    Pos_801887EC *p = (Pos_801887EC *)((Ent_801887EC *)camp_work.objs[id])->node;
                    f32 z;
                    x = (s16)p->x;
                    y = (s16)p->y;
                    TextPushColor();
                    TextSetColor(0xff201008);
                    z = TextGetZ();
                    TextSetZ(self->node->z);
                    TextPrint(x + 0x34, y + 0xc, str);
                    TextSetZ(z);
                    TextPopColor(1);
                }
            }
        }
        break;
    case 0x64:
        self->state = 0xff;
        break;
    case 0xFF:
        fn_80199F58(self->node);
        self->flags |= 0x40;
        break;
    }
}

void fn_80189EA0(Obj_80189EA0 *self) {
    In_80189EA0 *in = self->in;
    s16 x = (s16)self->x;
    s16 y = (s16)self->y;
    f32 z = TextGetZ();
    TextSetZ(10.0f + self->z);
    TextPushColor();
    TextSetColor(0xff201008);
    TextPrint(x + 0x12, y + 0x11, lbl_802E9908[in->id].s4);
    switch (fn_80194378(in->id)) {
    case 0:
        TextPushColor();
        TextSetColor(0x40201008);
        TextPrint(x + 0x102, y + 0x11, lbl_802E9908[in->id].sc);
        TextPopColor(1);
        TextPrint(x + 0x92, y + 0x11, lbl_802E9908[in->id].s8);
        break;
    case 1:
        TextPushColor();
        TextSetColor(0x40201008);
        TextPrint(x + 0x92, y + 0x11, lbl_802E9908[in->id].s8);
        TextPopColor(1);
        TextPrint(x + 0x102, y + 0x11, lbl_802E9908[in->id].sc);
        break;
    }
    TextPopColor(1);
    TextSetZ(z);
}

extern void fn_80180414(void);
void fn_801802AC(void) {
    Ctrl_80170450* c = ((Outer_80170450*)lbl_8034710C)->holder->ctrl;

    switch (c->state) {
    case 0:
        fn_80180694(c->f44, 1);
        c->state++;
        break;
    case 1:
        if (CampMenuAnyPanelBusy() == 0) {
            fn_80180414();
            c->state++;
        } else if (fn_801C09F8(lbl_80347154, 0x11) != 0 || fn_801C09F8(lbl_80347154, 0x10) != 0) {
            CampMenuFinishAllPanels();
            fn_80180414();
            c->state++;
        }
        break;
    case 2:
        fn_80180694(c->f44, 0);
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
        c->f6c = 2;
        break;
    }
}

extern void fn_80174E18(void);
void fn_80174CB0(void) {
    Ctrl_80170450* c = ((Outer_80170450*)lbl_8034710C)->holder->ctrl;

    switch (c->state) {
    case 0:
        fn_80174F40((s8)c->f44, 1);
        c->state++;
        break;
    case 1:
        if (CampMenuAnyPanelBusy() == 0) {
            fn_80174E18();
            c->state++;
        } else if (fn_801C09F8(lbl_80347154, 0x11) != 0 || fn_801C09F8(lbl_80347154, 0x10) != 0) {
            CampMenuFinishAllPanels();
            fn_80174E18();
            c->state++;
        }
        break;
    case 2:
        fn_80174F40((s8)c->f44, 0);
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
        c->f6c = 2;
        break;
    }
}

extern void fn_80178BC8(void);
void fn_80178A60(void) {
    Ctrl_80170450* c = ((Outer_80170450*)lbl_8034710C)->holder->ctrl;

    switch (c->state) {
    case 0:
        fn_80178D2C((s8)c->f44, 1);
        c->state++;
        break;
    case 1:
        if (CampMenuAnyPanelBusy() == 0) {
            fn_80178BC8();
            c->state++;
        } else if (fn_801C09F8(lbl_80347154, 0x11) != 0 || fn_801C09F8(lbl_80347154, 0x10) != 0) {
            CampMenuFinishAllPanels();
            fn_80178BC8();
            c->state++;
        }
        break;
    case 2:
        fn_80178D2C((s8)c->f44, 0);
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
        c->f6c = 2;
        break;
    }
}

void fn_80189DBC(Self_8016F138* self) {
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
            fn_80189EA0((Obj_80189EA0 *)self->inner);
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
void fn_8015EB8C(Ent_8015EB8C *self, s32 idx, Callback fn)
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

void fn_8016AA64(Mover6 *m, f32 x, f32 y)
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

    obj = OBJ(*(s32*)(lbl_80307638 + 0x7c));
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

void fn_80172E8C(void)
{
    Leaf* la = ((Elem*)camp_work.objs[0x82])->mid->leaf;
    UiObj* o;

    o = OBJ(4);
    UiObjSetLowered(o);
    UiObjMoveTo(o, 6, 4, -8.0f, 125.0f);
    UiObjSetCommand(o, 10, 0);
    o = OBJ(0x76);
    UiObjSetLowered(o);
    UiObjMoveTo(o, 6, 4, -8.0f, 189.0f);
    UiObjSetCommand(o, 10, 1);
    o = OBJ(0x77);
    UiObjSetLowered(o);
    UiObjMoveTo(o, 6, 4, -8.0f, 253.0f);
    UiObjSetCommand(o, 10, 2);
    o = OBJ(0x85);
    UiObjSetLowered(o);
    UiObjMoveTo(o, 6, -1, 328.0f, 61.0f);
    UiObjSetCommand(o, 10, 0);
    o = OBJ(0x83);
    UiObjSetLowered(o);
    UiObjMoveTo(o, 6, -1, 328.0f, 119.0f);
    UiObjSetCommand(o, 10, 0);
    if (la->f5c & (1 << *(s32*)(lbl_80307638 + 0x61c))) {
        o = OBJ(0x86);
        UiObjSetLowered(o);
        UiObjMoveTo(o, 6, -1, 328.0f, 183.0f);
        UiObjSetCommand(o, 15, 1);
        o = OBJ(0x84);
        UiObjSetLowered(o);
        UiObjMoveTo(o, 6, -1, 328.0f, 241.0f);
        UiObjSetCommand(o, 15, 1);
    }
    o = OBJ(0x60);
    UiObjSetLowered(o);
    UiObjMoveTo(o, 6, 4, 24.0f, 384.0f);
    UiObjSetCommand(o, 15, 1);
}

void fn_8017D534(void)
{
    UiObj* o;
    s32 i;
    s32 a;
    s32 b;
    s32 d;
    Ctl7* c;

    c = (*(Outer7**)&lbl_8034710C)->holder->ctl;
    o = OBJ(4);
    UiObjMoveTo(o, 6, -1, -8.0f, 61.0f);
    UiObjSetCommand(o, 15, 0);
    o = OBJ(0x78 + *(s32*)(((u8*)lbl_80307638) + 0x1e4));
    UiObjMoveTo(o, 6, -1, -8.0f, 125.0f);
    UiObjSetCommand(o, 15, 1);
    o = OBJ(0x6e);
    UiObjMoveTo(o, 6, -1, -8.0f, 189.0f);
    UiObjSetCommand(o, 10, 2);
    o = OBJ(0x6f);
    UiObjMoveTo(o, 6, -1, -8.0f, 253.0f);
    UiObjSetCommand(o, 10, 3);
    switch (c->f24) {
    case 0:
        a = 0x7a;
        b = 5;
        d = 0;
        break;
    case 1:
        a = 0x7f;
        b = 3;
        d = 0;
        break;
    }
    for (i = 0; i < b; i++) {
        o = OBJ(a + i);
        UiObjMoveTo(o, 6, 4, 328.0f, (d + i) * 64 + 61);
        if (i == c->f4) {
            UiObjSetCommand(o, 10, i + d);
        } else {
            UiObjSetCommand(o, 15, i + d);
        }
        ND(a + i)->y += 150.0f;
    }
    o = OBJ(0x60);
    UiObjMoveTo(o, 6, -1, 24.0f, 384.0f);
    UiObjSetCommand(o, 15, 0);
}

void fn_8017DA28(void)
{
    UiObj* o;
    s32 i;
    s32 a;
    s32 b;
    s32 d;
    Ctl7* c;

    c = (*(Outer7**)&lbl_8034710C)->holder->ctl;
    o = OBJ(4);
    UiObjMoveTo(o, 6, -1, -8.0f, 61.0f);
    UiObjSetCommand(o, 15, 0);
    o = OBJ(0x78 + *(s32*)(((u8*)lbl_80307638) + 0x1e4));
    UiObjMoveTo(o, 6, -1, -8.0f, 125.0f);
    UiObjSetCommand(o, 10, 1);
    o = OBJ(0x6e);
    UiObjMoveTo(o, 6, -1, -8.0f, 189.0f);
    UiObjSetCommand(o, 10, 2);
    o = OBJ(0x6f);
    UiObjMoveTo(o, 6, -1, -8.0f, 253.0f);
    UiObjSetCommand(o, 10, 3);
    switch (c->f24) {
    case 0:
        a = 0x7a;
        b = 5;
        d = 0;
        break;
    case 1:
        a = 0x7f;
        b = 3;
        d = 0;
        break;
    }
    for (i = 0; i < b; i++) {
        o = OBJ(a + i);
        UiObjMoveTo(o, 6, 4, 328.0f, (d + i) * 64 + 61);
        if (i == c->f4) {
            UiObjSetCommand(o, 10, i + d);
        } else {
            UiObjSetCommand(o, 15, i + d);
        }
        ND(a + i)->y += 150.0f;
    }
    o = OBJ(0x60);
    UiObjMoveTo(o, 6, -1, 24.0f, 384.0f);
    UiObjSetCommand(o, 15, 0);
}

s32 fn_8017E260(void)
{
    Ctl8* c;
    s32 r;
    s32 n;

    c = (*(Outer8**)&lbl_8034710C)->holder->ctl;
    switch (CW(0x304, u32)) {
    case 0:
        fn_8017EAEC();
        fn_8017F540();
        fn_8017F310();
        fn_8017F07C();
        CW(0x304, s32) = 2;
        break;
    case 2:
        if (!CampMenuAnyPanelBusy()) {
            CW(0x304, s32) = 3;
        } else if (fn_801C09F8(lbl_80347154, 2) || fn_801C09F8(lbl_80347154, 1)) {
            CampMenuFinishAllPanels();
            CW(0x304, s32) = 3;
        }
        break;
    case 3:
        r = fn_8017E5FC();
        fn_8017E4E4();
        switch (r) {
        case -1:
            CW(0x304, s32) = 0x18;
            break;
        case 0:
            break;
        case 1:
            CW(0x304, s32) = 0xc;
            break;
        }
        break;
    case 12:
        fn_8017EBD8();
        CW(0x304, s32) = 0x12;
        break;
    case 18:
        switch (c->f4) {
        case 0:
            n = 0xb;
            break;
        case 1:
            n = 0xb;
            break;
        case 2:
            n = 0xb;
            break;
        default:
            n = 0xb;
            break;
        }
        if (!CampMenuAnyPanelBusy()) {
            camp_screen = n;
            ((s32*)((u8*)&camp_work + 0x2f4))[n] = 0;
            fn_801959D4(n);
        } else if (fn_801C09F8(lbl_80347154, 2) || fn_801C09F8(lbl_80347154, 1)) {
            CampMenuFinishAllPanels();
            camp_screen = n;
            ((s32*)((u8*)&camp_work + 0x2f4))[n] = 0;
            fn_801959D4(n);
        }
        break;
    case 24:
        fn_8017EE48();
        CW(0x304, s32) = 0x13;
        break;
    case 19:
        if (!CampMenuAnyPanelBusy()) {
            CW(0x2f8, s32) = 0;
            camp_screen = 1;
            fn_801959D4(1);
        } else if (fn_801C09F8(lbl_80347154, 2) || fn_801C09F8(lbl_80347154, 1)) {
            CampMenuFinishAllPanels();
            CW(0x2f8, s32) = 0;
            camp_screen = 1;
            fn_801959D4(1);
        }
        break;
    }
    return 0;
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

void fn_8017F07C(void)
{
    UiObj* o;
    s32 i;
    s32 a;
    s32 b;
    s32 d;
    Ctl9* c;

    c = (*(Outer9**)&lbl_8034710C)->holder->ctl;
    o = OBJ(4);
    UiObjMoveTo(o, 6, -1, -8.0f, 61.0f);
    UiObjSetCommand(o, 15, 0);
    for (i = 0; i < 2; i++) {
        if (c->fc & (1 << i)) {
            o = OBJ(0x78 + i);
            UiObjMoveTo(o, 6, -1, -8.0f, (i + 1) * 64 + 61);
            if (c->f4 == i) {
                UiObjSetCommand(o, 10, i + 1);
            } else {
                UiObjSetCommand(o, 15, i + 4);
            }
        }
    }
    o = OBJ(0x6c);
    UiObjMoveTo(o, 6, -1, 328.0f, 61.0f);
    UiObjSetCommand(o, 15, 0);
    switch (c->f24) {
    case 0:
        a = 0x7a;
        b = 5;
        d = 1;
        break;
    case 1:
        a = 0x7f;
        b = 3;
        d = 1;
        break;
    }
    for (i = 0; i < b; i++) {
        o = OBJ(a + i);
        UiObjSetLowered(o);
        UiObjMoveTo(o, 6, 4, 328.0f, (d + i) * 64 + 61);
        UiObjSetCommand(o, 15, i + d);
        ND(a + i)->y += 150.0f;
    }
    o = OBJ(0x60);
    UiObjMoveTo(o, 6, -1, 24.0f, 384.0f);
    UiObjSetCommand(o, 15, 0);
}

s32 fn_8018394C(void)
{
    s32 r;

    switch (CW(0x2f8, u32)) {
    case 0:
        fn_80184CE8();
        fn_80184A78();
        fn_801847F0();
        fn_801841DC();
        fn_80184E2C();
        CW(0x2f8, s32) = 2;
        break;
    case 2:
        if (!CampMenuAnyPanelBusy()) {
            CW(0x2f8, s32) = 3;
        } else if (fn_801C09F8(lbl_80347154, 2) || fn_801C09F8(lbl_80347154, 1)) {
            CampMenuFinishAllPanels();
            CW(0x2f8, s32) = 3;
        }
        break;
    case 3:
        r = fn_80183D90();
        fn_80183C54();
        switch (r) {
        case -1:
            CW(0x2f8, s32) = 0x18;
            break;
        case 0:
            break;
        case 1:
            CW(0x2f8, s32) = 0xc;
            break;
        }
        break;
    case 12:
        fn_80184558();
        CW(0x2f8, s32) = 0x12;
        break;
    case 18:
        if (!CampMenuAnyPanelBusy()) {
            switch ((*(Outer11**)&lbl_8034710C)->holder->ctl->f4) {
            case 4:
                CW(0x320, s32) = 0;
                camp_screen = 0xb;
                fn_801959D4(0xb);
                break;
            case 5:
                CW(0x2fc, s32) = 0;
                camp_screen = 2;
                fn_801959D4(2);
                break;
            default:
                CW(0x300, s32) = 0;
                camp_screen = 3;
                fn_801959D4(3);
                break;
            }
        } else if (fn_801C09F8(lbl_80347154, 2) || fn_801C09F8(lbl_80347154, 1)) {
            CampMenuFinishAllPanels();
            switch ((*(Outer11**)&lbl_8034710C)->holder->ctl->f4) {
            case 4:
                CW(0x320, s32) = 0;
                camp_screen = 0xb;
                fn_801959D4(0xb);
                break;
            case 5:
                CW(0x2fc, s32) = 0;
                camp_screen = 2;
                fn_801959D4(2);
                break;
            default:
                CW(0x300, s32) = 0;
                camp_screen = 3;
                fn_801959D4(3);
                break;
            }
        }
        break;
    case 24:
        fn_80184330();
        CW(0x2f8, s32) = 0x13;
        break;
    case 19:
        if (!CampMenuAnyPanelBusy()) {
            camp_screen = 0;
            CW(0x2f4, s32) = 0;
            fn_801959D4(0);
        } else if (fn_801C09F8(lbl_80347154, 2) || fn_801C09F8(lbl_80347154, 1)) {
            CampMenuFinishAllPanels();
            camp_screen = 0;
            CW(0x2f4, s32) = 0;
            fn_801959D4(0);
        }
        break;
    }
    return 0;
}

void fn_80184558(void)
{
    Ctl12* c;
    s32 i;
    UiObj* o;

    c = (*(Outer12**)&lbl_8034710C)->holder->ctl;
    for (i = 0; i < *(s8*)((u8*)&camp_work + 0xc); i++) {
        o = OBJ(i);
        if (i == c->f4) {
            UiObjMoveTo(o, 6, 4, -8.0f, 61.0f);
            UiObjSetCommand(o, 15, i);
        } else {
            UiObjMoveTo(o, 6, 5, -348.0f, i * 64 + 61);
            UiObjSetCommand(o, 15, i);
        }
    }
    if (fn_801953B8()) {
        o = OBJ(4);
        if (c->f4 == 4) {
            UiObjMoveTo(o, 6, 4, -8.0f, 61.0f);
            UiObjSetCommand(o, 15, 4);
        } else {
            UiObjMoveTo(o, 6, 5, -348.0f, 317.0f);
            UiObjSetCommand(o, 15, 4);
        }
        o = OBJ(0x6c + c->f14);
        UiObjMoveTo(o, 6, 5, 668.0f, 317.0f);
        UiObjSetCommand(o, 15, 4);
    }
    for (i = 0; i < *(s8*)((u8*)&camp_work + 0xc); i++) {
        o = OBJ(c->f44 + (i * 5 + 6));
        UiObjMoveTo(o, 6, -1, 668.0f, i * 64 + 61);
        UiObjSetCommand(o, 15, i);
    }
    if (fn_80194CB8() == 1) {
        o = OBJ(5);
        UiObjMoveTo(o, 6, 5, -348.0f, 381.0f);
        UiObjSetCommand(o, 15, 6);
    }
}

s8 fn_80168BD4(W_80168BD4 *w)
{
    void *h;
    Vec3_80168BD4 o;
    Vec3_80168BD4 p;
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
    p.x = w->p1c.x;
    p.y = w->p1c.y;
    p.z = w->p1c.z;
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
    if (d2 >= 0.0f && w->f28 >= 0.0f) {
        if (d2 > (f32)pow(w->f28, 2.0)) {
            r = -0x7f;
        } else {
            g = w->f28;
            r = (s32)((f32)(r + 0x7e) * ((g - fn_80291A5C(d2)) / g) + 1.0f - 127.0f);
        }
    }
    return r;
}

typedef struct Chr_801838C8 {
    u8 pad0[0xe];
    s8 xe;
    u8 padf[0x1a - 0xf];
    s16 x1a;
    u8 pad1c[0x5c - 0x1c];
} Chr_801838C8;
s16 fn_801838C8(s32 kind, s32 idx) {
    Chr_801838C8* c = &((Chr_801838C8*)lbl_8030B7F4)[idx];
    StatRec* s = &lbl_8030B4D4.chr[idx];
    s16 r = 0;
    switch (kind) {
    case 0x36: r = s->x48[0]; break;
    case 0x37: r = s->x48[1]; break;
    case 0x38: r = s->x48[2]; break;
    case 0x39: r = s->x48[3]; break;
    case 0x3a: r = s->x48[4]; break;
    case 0x3b: r = c->x1a; break;
    case 0x3c: r = c->xe; break;
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
        (*(Obj_8016CED8**)&lbl_803470B8)->tbl = fn_801E1C7C(0x14);
        switch (*(*(Obj_8016CED8**)&lbl_803470B8)->kind) {
        case 0:
            break;
        case 1:
            (*(Obj_8016CED8**)&lbl_803470B8)->tbl->p0 = lbl_802E7D5C;
            (*(Obj_8016CED8**)&lbl_803470B8)->tbl->p4 = lbl_802E8390;
            (*(Obj_8016CED8**)&lbl_803470B8)->tbl->p8 = lbl_802E83E0;
            (*(Obj_8016CED8**)&lbl_803470B8)->tbl->pc = lbl_802E8464;
            (*(Obj_8016CED8**)&lbl_803470B8)->tbl->p10 = lbl_802E84E8;
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
        if ((*(Obj_8016CED8**)&lbl_803470B8) != 0) {
            (*(Obj_8016CED8**)&lbl_803470B8) = 0;
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
    Ctrl_8016E6E8* c;
    f32 oz;

    c = ((Outer_8016E6E8*)lbl_8034710C)->holder->ctrl;
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
    if (info->b14 == 0 && c->f4 == fn_8018126C()) {
        info->level2 = fn_801812C0();
        TextPrint(lx, ty + 0x18, info->name2);
        TextPrintf(rx, ty + 0x18, "%2d", info->level2);
    }
    TextPopColor(1);
    TextSetZ(oz);
}

s32 fn_80173688(void) {
    Ctrl_80173688* c = ((Outer_80173688*)lbl_8034710C)->holder->ctrl;

    ((Pnl_80173688*)camp_work.objs[0x66])->in->hide = 1;
    if (fn_801C09F8(lbl_80347154, 5)) {
        c->f8 = c->f4;
        c->f4 = fn_8019A21C(c->fc, 1, c->f4, 0, 0x18);
    } else if (fn_801C09F8(lbl_80347154, 4)) {
        c->f8 = c->f4;
        c->f4 = fn_8019A21C(c->fc, -1, c->f4, 0, 0x18);
    } else if (fn_801C09F8(lbl_80347154, 2)) {
        fn_801929B8(2);
        return 1;
    } else if (fn_801C09F8(lbl_80347154, 1)) {
        fn_801929B8(5);
        return -1;
    } else {
        goto end;
    }
    fn_801929B8(0);
end:
    return 0;
}

void fn_801752F4(void) {
    s32 i;
    UiObj* o;

    for (i = 0; i < 3; i++) {
        o = &(*(CampWork*)&camp_work).pnl[0x5a + i]->in->obj;
        UiObjMoveTo(o, 6, 5, 668.0f, 61 + i * 88);
        UiObjSetCommand(o, 15, i);
    }
    o = &(*(CampWork*)&camp_work).pnl[0x60]->in->obj;
    UiObjMoveTo(o, 6, -1, 632.0f, 480.0f);
    UiObjSetCommand(o, 15, 0);
}

void fn_8017F540(void) {
    Ctrl* c;
    s32 i;
    UiObj* o;

    c = (*(Outer**)&lbl_8034710C)->holder->ctrl;
    CampMenuHideAllPanels();
    (*(CampWork*)&camp_work).pnl[4]->in->hide = 1;
    for (i = 0; i < 2; i++) {
        if (c->mask & (1 << i)) {
            (*(CampWork*)&camp_work).pnl[0x78 + i]->in->hide = 1;
        }
    }
    (*(CampWork*)&camp_work).pnl[0x6c]->in->hide = 1;
    for (i = 0; i < 8; i++) {
        (*(CampWork*)&camp_work).pnl[0x7a + i]->in->hide = 1;
        o = &(*(CampWork*)&camp_work).pnl[0x7a + i]->in->obj;
        fn_80199BA4(o, 0);
        fn_80199B9C(o, 1.0f);
    }
}

void fn_80184E2C(void) {
    Sprite* s;
    Pnl_80184E2C* p;
    s32 i;
    s32 who;

    for (i = 0; i < (*(CampWork_80184E2C*)&camp_work).count; i++) {
        p = (*(CampWork_80184E2C*)&camp_work).pnl[i * 5 + 8];
        who = (*(Game*)&lbl_8030B7F4).party[i];
        switch (who) {
        case 0:
            s = fn_801D68C4(lbl_803470F0, 0x2b);
            break;
        case 1:
            s = fn_801D68C4(lbl_803470F0, 0x2c);
            break;
        case 2:
            s = fn_801D68C4(lbl_803470F0, 0x2d);
            break;
        case 3:
            s = fn_801D68C4(lbl_803470F0, 0x2e);
            break;
        case 4:
            s = fn_801D68C4(lbl_803470F0, 0x2f);
            break;
        case 5:
            s = fn_801D68C4(lbl_803470F0, 0x30);
            break;
        default:
            s = fn_801D68C4(lbl_803470F0, 0x2b);
            break;
        }
        fn_8019520C(who, (void *)(s));
        p->in->icon->spr = s;
    }
}

void fn_80186BE4(s16 x, s16 y, Slots* slots) {
    s32 i;
    s32 j;
    s16 tx;
    s16 ty;

    for (i = 0; i < 11; i++) {
        if (fn_80194C7C(slots, i, 0)) {
            TextPushColor();
            TextSetColor(0xff201008);
            TextPrint(x + 0x24, y + 0x1e + i * 0x18, lbl_802E98A0[i]);
        } else {
            TextPushColor();
            TextSetColor(0x40201008);
            TextPrint(x + 0x24, y + 0x1e + i * 0x18, lbl_803467B0);
        }
        for (j = 0; j < 2; j++) {
            if (j == 0) {
                tx = x + 0x9e;
                ty = y + 0x1e + i * 0x18;
            } else {
                tx = x + 0x146;
                ty = y + 0x1e + i * 0x18;
            }
            if (fn_80194C7C(slots, i, j)) {
                TextPrint(tx, ty, fn_80194C50(slots[i].v[j]));
            } else {
                TextPrint(tx, ty, lbl_803467B0);
            }
        }
        TextPopColor(1);
    }
}

void fn_801918C4(Inner_801918C4* in) {
    s16 x;
    s16 y;
    Info_801918C4* info;
    f32 z;

    x = in->obj.rect[0];
    y = in->obj.rect[1];
    info = (*(CampWork_801918C4*)&camp_work).info;
    z = TextGetZ();
    TextSetZ(10.0f + in->z);
    TextPushColor();
    TextSetColor(0xff201008);
    TextPrint(x + 0x56, y + 6, info->name);
    TextPrintf(x + 0x56, y + 0x1e, "Hp");
    TextPrintf(x + 0x6e, y + 0x1e, "%6d", info->hp);
    TextPrintf(x + 0xb6, y + 0x1e, "/");
    TextPrintf(x + 0xc2, y + 0x1e, "%6d", fn_80194028());
    TextPopColor(1);
    TextSetZ(z);
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

void fn_801729D0(void) {
    Ctrl_801729D0* c;
    u8* tb;
    La_801729D0* la;
    Ctrl_801729D0* c2;

    c = ((Outer_801729D0*)lbl_8034710C)->holder->ctrl;
    tb = lbl_80307638;
    la = LA(0x82);
    c->fc = 0;
    if (la->f5c & (1 << *(s32*)(tb + 0x61c))) {
        c->fc = 3;
    } else {
        c->fc = 1;
    }
    c->f4 = 0;
    c->f8 = 0;
    c->f4c = la->f58;
    c->f44 = *(s32*)(tb + 0x61c);
    fn_80195A68(c, 1, 0, 0, 0, 1);
    c2 = ((Outer_801729D0*)lbl_8034710C)->holder->ctrl;
    {
        La_801729D0* t = LA(0x85);
        t->f10 = fn_80194A8C(c2->f44);
    }
    {
        La_801729D0* t = LA(0x83);
        t->f8 = fn_80194A8C(c2->f44);
    }
    {
        La_801729D0* t = LA(0x86);
        t->f10 = fn_80194A18(c2->f44);
    }
    {
        La_801729D0* t = LA(0x84);
        t->f8 = fn_80194A18(c2->f44);
    }
    fn_801954D0((void *)fn_80194C38(LA(0x85 + (s8)c->f4)->f10));
}

static inline s32 inRange(Hd *h, Tab_80166138 *t) {
    if (h != 0 && t != 0 && t->ents != 0 && t->count != 0 && t->count > h->idx) return 1;
    return 0;
}

s32 fn_80166138(Obj_80166138 *o, Tab_80166138 *t) {
    Hd *h = o->x1d8;
    Mod *m = h->mod;
    s32 r = fn_801664A4(o);
    if (inRange(o->x1d8, t)) {
        Ent_80166138 *e = &t->ents[h->idx];
        u16 i = m->f172;
        if (m->f170 != i && e->f2c != 1 && m->f198 != 0) {
            fn_801E735C(i, 1.0f, m);
        }
    }
    return r;
}

void fn_80191E94(Obj_80191E94 *o) {
    switch (o->kind) {
    case 0:
    case 1:
        break;
    case 0xfe:
        break;
    case 0xff:
        o->flags |= 0x40;
        break;
    }
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

/* Slides four camp-menu panels to their places over 6 frames and starts their command 0xf. */
void fn_801763B8(void)
{
    UiObj* obj;
    s32 i;

    obj = OBJ_801763B8(0x5d);
    UiObjMoveTo(obj, 6, 4, 328.0f, 61.0f);
    UiObjSetCommand(obj, 0xf, 0);
    obj = OBJ_801763B8(0x41);
    UiObjMoveTo(obj, 6, 4, 328.0f, 204.0f);
    UiObjSetCommand(obj, 0xf, 1);
    i = *(s32*)(lbl_80307638 + 0x3c4) + 0x43;
    obj = OBJ_801763B8(i);
    UiObjMoveTo(obj, 6, -1, 328.0f, 204.0f);
    UiObjSetCommand(obj, 0xf, 1);
    obj = OBJ_801763B8(0x60);
    UiObjMoveTo(obj, 6, -1, 24.0f, 384.0f);
    UiObjSetCommand(obj, 0xf, 0);
}

f32 fn_8018E73C(Sub_8018DFC4 *s)
{
    f32 w;
    s16 x = s->x;
    s16 y = s->y;
    Kind_8018E73C *k = s->k;
    Arg_800C2650 a;

    a.f0 = -4090.0f;
    a.h4 = x;
    a.h6 = y;
    a.f8 = 1.0f;
    a.fc = 1.0f;
    switch (k->kind) {
    case 0:
        w = fn_800C2A88(&a);
        break;
    case 1:
        w = fn_800C287C(&a);
        break;
    case 2:
        w = fn_800C285C(&a);
        break;
    case 3:
        w = fn_800C2650(&a);
        break;
    }
    return w;
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

void fn_80189214(s8* kind, IconObj_80189214* o, s8 idx, f32 scale) {
    void* a;
    void* b;

    o->x = -4000.0f;
    o->y = 0.0f;
    o->f10 = 1.0f;
    o->scale = scale;
    o->f18 = 1.0f;
    o->f1c = 0.0f;
    o->f08 = 0;
    o->f0c = 0;
    switch (*kind) {
    case 1:
        switch (idx) {
        case 0:
            a = fn_801D68C4(lbl_803470F0, 0x21);
            b = fn_801D68C4(lbl_803470F0, 0x34);
            break;
        case 1:
            a = fn_801D68C4(lbl_803470F0, 0x22);
            b = fn_801D68C4(lbl_803470F0, 0x35);
            break;
        case 2:
            a = fn_801D68C4(lbl_803470F0, 0x23);
            b = fn_801D68C4(lbl_803470F0, 0x37);
            break;
        case 3:
            a = fn_801D68C4(lbl_803470F0, 0x24);
            b = fn_801D68C4(lbl_803470F0, 0x36);
            break;
        case 4:
            a = fn_801D68C4(lbl_803470F0, 0x25);
            b = fn_801D68C4(lbl_803470F0, 0x38);
            break;
        case 5:
            a = fn_801D68C4(lbl_803470F0, 0x26);
            b = fn_801D68C4(lbl_803470F0, 0x39);
            break;
        default:
            a = fn_801D68C4(lbl_803470F0, 0x21);
            b = fn_801D68C4(lbl_803470F0, 0x34);
            break;
        }
        break;
    case 0:
        switch (idx) {
        case 0:
            a = fn_801D68C4(lbl_803470F0, 0x21);
            b = fn_801D68C4(lbl_803470F0, 0x32);
            break;
        case 1:
            a = fn_801D68C4(lbl_803470F0, 0x22);
            b = fn_801D68C4(lbl_803470F0, 0x5d);
            break;
        case 2:
            a = fn_801D68C4(lbl_803470F0, 0x23);
            b = fn_801D68C4(lbl_803470F0, 0x31);
            break;
        case 3:
            a = fn_801D68C4(lbl_803470F0, 0x24);
            b = fn_801D68C4(lbl_803470F0, 0x33);
            break;
        case 4:
            a = fn_801D68C4(lbl_803470F0, 0x25);
            b = fn_801D68C4(lbl_803470F0, 0x41);
            break;
        case 5:
            a = fn_801D68C4(lbl_803470F0, 0x26);
            b = fn_801D68C4(lbl_803470F0, 0x3c);
            break;
        default:
            a = fn_801D68C4(lbl_803470F0, 0x21);
            b = fn_801D68C4(lbl_803470F0, 0x32);
            break;
        }
        break;
    }
    fn_8019A15C(o, 2, 0, 0);
    o->spr20[0] = a;
    o->pos24->a = 0.0f;
    o->pos24->b = -26.0f;
    o->spr20[1] = b;
    o->pos24->c = (f32)(idx * 0x30 + 0x14);
    o->pos24->d = -26.0f;
    o->f44 = 0;
}

void fn_80191A04(Pos_80191A04* p, s32 kind) {
    p->f0 = -6190.0f;
    p->f4 = 0.0f;
    p->f10 = 1.0f;
    p->f14 = 0.0f;
    p->f18 = 1.0f;
    p->f1c = 0.0f;
    p->i8 = 0;
    p->ic = 0;
    fn_8019A15C(p, 1, 1, 1);
    switch (kind) {
    case 1:
        fn_80199FFC(p, 0, fn_801D68C4(lbl_803470F4, 0x58), 6, 0x1e, 2);
        p->spr44 = fn_801D68C4(lbl_803470F0, 4);
        break;
    case 2:
        fn_80199FFC(p, 0, fn_801D68C4(lbl_803470F4, 4), 8, 6, 2);
        p->spr44 = fn_801D68C4(lbl_803470F0, 4);
        break;
    case 3:
        fn_80199FFC(p, 0, fn_801D68C4(lbl_803470F4, 0x58), 6, 0x1e, 2);
        p->spr44 = fn_801D68C4(lbl_803470F0, 1);
        break;
    case 4:
        fn_80199FFC(p, 0, fn_801D68C4(lbl_803470F4, 4), 8, 6, 2);
        p->spr44 = fn_801D68C4(lbl_803470F0, 1);
        break;
    case 15:
    case 16:
        fn_80199FFC(p, 0, fn_801D68C4(lbl_803470F4, 4), 8, 6, 2);
        p->spr44 = fn_801D68C4(lbl_803470F0, 4);
        break;
    case 5:
        fn_80199FFC(p, 0, fn_801D68C4(lbl_803470F4, 0x3b), 6, 6, 2);
        p->spr44 = fn_801D68C4(lbl_803470F0, 4);
        break;
    case 6:
        fn_80199FFC(p, 0, fn_801D68C4(lbl_803470F4, 0x3b), 6, 6, 2);
        p->spr44 = fn_801D68C4(lbl_803470F0, 1);
        break;
    case 7:
        fn_80199FFC(p, 0, fn_801D68C4(lbl_803470F4, 0x3b), 0x12, 6, 2);
        p->spr44 = fn_801D68C4(lbl_803470F0, 1);
        break;
    case 8:
    case 13:
    case 14:
        fn_80199FFC(p, 0, fn_801D68C4(lbl_803470F4, 4), 6, 6, 2);
        p->spr44 = fn_801D68C4(lbl_803470F0, 1);
        break;
    case 9:
        fn_80199FFC(p, 0, fn_801D68C4(lbl_803470F4, 0x3b), 6, 6, 2);
        p->spr44 = fn_801D68C4(lbl_803470F0, 4);
        break;
    case 10:
        fn_80199FFC(p, 0, fn_801D68C4(lbl_803470F4, 0x3b), 6, 6, 2);
        p->spr44 = fn_801D68C4(lbl_803470F0, 4);
        break;
    }
    p->sp->spr = fn_801D68C4(lbl_803470E8, 2);
    p->fp[0] = 0.0f;
    p->fp[1] = 0.0f;
    p->sp20->spr = fn_801D68C4(lbl_803470F0, 10);
    p->fp24[0] = 0.0f;
    p->fp24[1] = 0.0f;
}
