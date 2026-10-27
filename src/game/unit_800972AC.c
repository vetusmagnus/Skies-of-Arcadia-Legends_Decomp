#include "types.h"
#include "string.h"
#include <math.h>
#include "ninja.h"
#include "game/drawstate.h"
#include <dolphin/os/OSFastCast.h>
typedef struct Obj12 {
    u8 pad_00[0x12];
    u16 v12;
} Obj12;
extern s16 lbl_80346C3C;
extern s16 lbl_80346750;
extern s32 lbl_803473F8;
extern u32 lbl_803473F4;
extern u8 lbl_80303340[];
extern void *lbl_803473F0;
typedef struct Obj10 {
    u8 pad_00[0x10];
    u16 v10;
} Obj10;
typedef struct Pair {
    s32 a;
    s32 b;
} Pair;
typedef struct TblA {
    u32 count;
    u32 items[1];
} TblA;
typedef struct SubA {
    u8 pad_00[0x10];
    TblA *tbl_10;
} SubA;
typedef struct ObjB_800A1ABC {
    u8 pad_000[0x1c8];
    SubA *sub_1c8;
} ObjB_800A1ABC;
typedef struct LeafC {
    u8 pad_00[0x19];
    u8 state_19;
} LeafC;
typedef struct ObjB_800ABE9C {
    u8 pad_000[0x1fb];
    u8 flag_1fb;
    s16 val_1fc;
    u8 pad_1fe[0x25c - 0x1fe];
    LeafC *leaf_25c;
} ObjB_800ABE9C;
typedef struct ObjA_800ABE9C {
    u8 pad_00[0x19];
    u8 state_19;
    u8 pad_1a[0x24 - 0x1a];
    ObjB_800ABE9C *obj_24;
} ObjA_800ABE9C;
typedef struct ObjB_800AC44C {
    u8 pad_000[0x25c];
    LeafC *leaf_25c;
} ObjB_800AC44C;
typedef struct ObjA_800AC44C {
    u8 pad_00[0x19];
    u8 state_19;
    u8 pad_1a[0x24 - 0x1a];
    ObjB_800AC44C *obj_24;
} ObjA_800AC44C;
typedef struct ObjB_800AD300 {
    u8 pad_000[0x1c8];
    SubA *sub_1c8;
    u8 pad_1cc[0x1fc - 0x1cc];
    s16 val_1fc;
} ObjB_800AD300;
typedef struct ObjA_800AD300 {
    u8 pad_00[0x19];
    u8 state_19;
    u8 pad_1a[0x24 - 0x1a];
    ObjB_800AD300 *obj_24;
} ObjA_800AD300;
typedef struct {
    s8 mode;
    u8 flags;
    s16 field2;
    u8 pad_04[0x70 - 4];
} SeFlagBlock;
extern SeFlagBlock lbl_802E0084;
extern s16 lbl_80302F18[408];
extern void fn_800D2CA8(s32 x);
s32 fn_80097B0C(void* p);
typedef struct {
    s16 flag;
    s16 count;
} Entry8009B58C;
typedef struct {
    u8 pad_000[0x188];
    u32 flags188;
    u8 pad_18c[0x260 - 0x18C];
    Entry8009B58C *entry260;
} Obj8009B58C;
typedef struct {
    s16 flag;
    s16 count;
} Entry8009B5D4;
typedef struct {
    u8 pad_000[0x188];
    u32 flags188;
    u8 pad_18c[0x264 - 0x18C];
    Entry8009B5D4 *entry264;
} Obj8009B5D4;
typedef struct {
    u8 pad_00[0x1c];
    s32 *table;
} Sub8009D67C;
typedef struct {
    u8 pad_000[0xec];
    u32 field_ec;
    u8 pad_0f0[0x1c8 - 0xf0];
    Sub8009D67C *sub;
} Obj8009D67C;
typedef struct {
    u8 pad_00[0x44];
    u32 x44;
    u32 x48;
} Inner8009DC58;
typedef struct {
    u8 pad_00[0x10];
    Inner8009DC58 *p10;
} Sub8009DC58;
typedef struct {
    u8 pad_000[0x1c8];
    Sub8009DC58 *sub;
    u8 pad_1cc[0x23a - 0x1cc];
    u16 flags23a;
} Obj8009DC58;
typedef struct Item {
    u8 pad[0x19];
    u8 type;
} Item;
typedef struct ItemList_8009E530 {
    Item **items;
} ItemList_8009E530;
typedef struct ItemList_8009E804 {
    void **items;
    s32 count;
} ItemList_8009E804;
extern u32 lbl_80311970[];
typedef struct Sub2 {
    u8 pad[4];
    u32 f4;
} Sub2;
typedef struct Sub_UNIT0000 {
    u8 pad[0x20];
    Sub2 *f20;
} Sub_UNIT0000;
typedef struct Obj_UNIT0000 {
    u8 pad0[0x100];
    s32 f100;
    u8 pad1[0x1c8 - 0x104];
    Sub_UNIT0000 *f1c8;
} Obj_UNIT0000;
typedef struct State_UNIT0000 {
    s32 w00;
    s32 w04;
    s32 w08;
    s32 w0c;
    f32 f10;
    f32 f14;
    f32 f18;
    s32 w1c;
    s32 w20;
    s32 w24;
    f32 f28;
    s32 w2c;
} State_UNIT0000;
extern State_UNIT0000 lbl_80303468;
extern s32 lbl_80346CF0;
extern Item *fn_8010A164(u16 id);
extern void fn_800A39E0(void);
extern void fn_800B0900(void);
extern u8 lbl_80303634[];
extern u32 lbl_80346C40;
extern void* lbl_80347588;
void* fn_802267AC(void* a, void* b);
void fn_80096DA4(void);
typedef struct {
    void** slots;
    s32 count;
} Pool;
extern char lbl_802B0F0C[];
void* fn_801E1A2C(s32 a, u32 size);
extern u8 *lbl_80346C94;
extern s32 lbl_80346C90;
void fn_801E7DF0(void *);
void fn_801DD76C(void *m);
extern void njScale(NJS_MATRIX m, f32 x, f32 y, f32 z);
f32 fn_8009DEF0(u8 *obj, void *m, void *p, f32 *s, f32 z);
void fn_801DD71C(s32 a);
void fn_801E1784(void *p);
typedef struct Node {
    void (*fn)(struct Node *);
    struct Node *next;
    s32 unk8;
    struct Node *owner;
    u8 pad10[0x9];
    u8 b19;
    u8 pad1a;
    u8 b1b;
    u8 pad1c[4];
    f32 f20;
} Node;
void fn_80226AE8(Node *);
void fn_801E17E0(Node *);
typedef struct NodeList {
    Node **items;
    s32 count;
} NodeList;
double pow(double, double);
extern f32 njCos(Angle a);
extern f32 njSin(Angle a);
extern void fn_800A0028(void *self);
typedef struct Ctx10_800ADED0 {
    u8 pad0[0x24];
    u8 inner24[0x44 - 0x24];
    s32 w44;
} Ctx10_800ADED0;
typedef struct Inner_800ADED0 {
    u8 pad0[0x10];
    Ctx10_800ADED0 *p10; /* 0x10 */
} Inner_800ADED0;
typedef struct Unit_800ADED0 {
    u8 pad0[0x16c];
    s16 h16c;
    u8 pad16e[0x1c8 - 0x16e];
    Inner_800ADED0 *p1c8; /* 0x1c8 */
    u8 pad1cc[0x1fa - 0x1cc];
    s8 b1fa;
} Unit_800ADED0;
typedef struct State_800ADED0 {
    u8 pad0[0x178];
    s32 w178;
} State_800ADED0;
extern void fn_8015ED90(void *p);
extern void fn_8015EB8C(void *p, s32 id, void *cb);
extern void fn_800B45D4(void *p, void *q);
extern void fn_800ABEB0(void);
typedef struct Ctx10_800B2B34 {
    u8 pad0[0x4c];
} Ctx10_800B2B34;
typedef struct Inner_800B2B34 {
    u8 pad0[0x10];
    u32 *p10; /* 0x10 */
} Inner_800B2B34;
typedef struct Sub_800B2B34 {
    u8 pad0[0x1fa];
    u8 b1fa;
} Sub_800B2B34;
typedef struct Rec {
    u8 pad0[0x8];
    u32 w8;
    u8 pad_c[0x18 - 0xc];
    u32 w18;
} Rec;
typedef struct Ctx_800B2B34 {
    u8 pad0[0x8];
    u32 w8;
    u8 pad_c[0x18 - 0xc];
    u32 w18;
    u8 pad1c[0x1c8 - 0x1c];
    Inner_800B2B34 *p1c8;
    u8 pad1cc[0x1d8 - 0x1cc];
    u32 *p1d8;
    u8 pad1dc[0x268 - 0x1dc];
    void *p268;
    u8 b26c;
} Ctx_800B2B34;
typedef struct Self_800B2B34 {
    u8 pad0[0x19];
    u8 b19;
    u8 pad1a[0x1b - 0x1a];
    u8 b1b;
    u8 pad1c[0x24 - 0x1c];
    Sub_800B2B34 *sub;
} Self_800B2B34;
extern void fn_801DD14C(f32* a, f32* b, f32* c);
typedef struct {
    s16 state;          /* 0x00 */
    s16 flags;          /* 0x02 */
    u8 pad04[8];
    f32 f0C, f10, f14;  /* 0x0C */
    u8 pad18[0x30 - 0x18];
    f32 f30, f34, f38;  /* 0x30 */
    s32 i3C;            /* 0x3C */
    u8 pad40[0x58 - 0x40];
    f32 f58, f5C, f60, f64, f68, f6C; /* 0x58 */
    s32 i70, i74, i78;  /* 0x70 */
    u8 pad7C[0x94 - 0x7C];
    f32 v94[3];         /* 0x94 */
    f32 vA0[3];         /* 0xA0 */
    f32 fAC, fB0, fB4; /* 0xAC */
    u8 padB8[0xD0 - 0xB8];
    f32 fD0, fD4;       /* 0xD0 */
    s32 iD8;            /* 0xD8 */
    u8 padDC[0xE6 - 0xDC];
    s16 sE6;            /* 0xE6 */
    u8 padE8[0x100 - 0xE8];
    s32 i100, i104;     /* 0x100 */
    u8 pad108[0x16C - 0x108];
    s8 n16C;            /* 0x16C */
    u8 b16D;            /* 0x16D */
    s16 s16E;           /* 0x16E */
    f32 f170, f174, f178, f17C, f180, f184; /* 0x170 */
    s32 i188;           /* 0x188 */
    f32 f18C, f190, f194, f198, f19C, f1A0; /* 0x18C */
    s32 i1A4, i1A8, i1AC; /* 0x1A4 */
    f32 v1B0[3];        /* 0x1B0 */
    f32 f1BC;           /* 0x1BC */
    u16 u1C0, u1C2;     /* 0x1C0 */
    f32 f1C4;           /* 0x1C4 */
} Obj80097388;
typedef struct { f32 x, y; } V2;
typedef struct {
    s16 kind;       /* 0x00 */
    u8 pad02[2];
    V2 v04;         /* 0x04 */
    V2 v0C;         /* 0x0C */
    V2 v14;         /* 0x14 */
    f32 f1C;        /* 0x1C */
    f32 f20;        /* 0x20 */
    V2 v24;         /* 0x24 */
    V2 v2C;         /* 0x2C */
    V2 v34;         /* 0x34 */
    V2 v3C;         /* 0x3C */
    s32 i44;        /* 0x44 */
} Part8009B6B8;
typedef struct {
    V2 v00, v08, v10, v18, v20, v28, v30;
    s32 i38;
    f32 f3C;
} Src8009B6B8;
typedef struct {
    u8 pad00[0xE4];
    void* h_e4;               /* 0xE4 */
    u8 padE8[0x188 - 0xE8];
    u32 flags;                /* 0x188 */
    u8 pad18C[0x254 - 0x18C];
    f32 f254, f258;           /* 0x254 */
    Part8009B6B8* part;       /* 0x25C */
} Obj8009B6B8;
extern void* fn_801C8930(void* h);
extern void* fn_801DF988(void* h);
extern void fn_801E0CB8();
extern void fn_801E06E0();
typedef struct {
    u32 (*fn)(void*, Obj10*);  /* 0x00 */
    u8 pad04[0x10];
    s16 flags;         /* 0x14 */
} Sub8009C3D0;
typedef struct {
    u32 count;         /* 0x00 */
    u8 pad04[0x24];
    s32 v28;           /* 0x28 */
    s32 v2C;           /* 0x2C */
} Info8009C3D0;
typedef struct {
    u8 pad00[0x10];
    Info8009C3D0* info; /* 0x10 */
} Inner8009C3D0;
typedef struct {
    u8 pad00[0x1BC];
    Sub8009C3D0* sub;   /* 0x1BC */
    u8 pad1C0[8];
    Inner8009C3D0* inner; /* 0x1C8 */
} Owner8009C3D0;
typedef struct {
    u8 pad00[0x19];
    u8 state;           /* 0x19 */
    u8 pad1A[0x24 - 0x1A];
    Owner8009C3D0* owner; /* 0x24 */
} Task8009C3D0;
extern void fn_800CD0B8(s32 a, s32 b, s32 c, s32 d);
extern void fn_800CCE0C(s32 a, s32 b);
extern void fn_80100B74(Task8009C3D0* t);
typedef struct TNode8009D760 TNode8009D760;
typedef struct {
    u8 pad00[4];
    s32 f04;
    u8 pad08[0x38 - 0x08];
    TNode8009D760* t38;  /* 0x38 */
} Obj8009D760;
typedef struct {
    u8 pad00[0x14];
    s32 f14;             /* 0x14 */
    s32 f18;             /* 0x18 */
    u8 pad1C[0x2C - 0x1C];
    s32 f2C;             /* 0x2C */
    s32 f30;             /* 0x30 */
    s32 f34;             /* 0x34 */
    u8 pad38[0xE4 - 0x38];
    s32 fE4;             /* 0xE4 */
    u8 padE8[0x178 - 0xE8];
    s16 s178;            /* 0x178 */
    s16 s17A;            /* 0x17A */
    u8 pad17C[0x1BC - 0x17C];
    s32 f1BC;            /* 0x1BC */
    u8 pad1C0[0x1C8 - 0x1C0];
    Obj8009D760* obj;    /* 0x1C8 */
    u8 pad1CC[0x1D8 - 0x1CC];
    s32 f1D8;            /* 0x1D8 */
    u8 pad1DC[0x25C - 0x1DC];
    s32 f25C, f260, f264, f268; /* 0x25C */
} Work8009D760;
struct TNode8009D760 {
    u8 pad00[4];
    TNode8009D760* f04;  /* 0x04 */
    u8 pad08[4];
    TNode8009D760* f0C;  /* 0x0C */
    u8 pad10[8];
    u8 flags;            /* 0x18 */
    u8 pad19[0x24 - 0x19];
    Work8009D760* work;  /* 0x24 */
};
extern void* fn_80226704(void* list, void* cb, s32 size);
extern void fn_801DBE1C(const char* fmt, ...);
extern s32 lbl_80347530;
typedef struct {
    u8 pad00[0x14];
    u32 attr_and;      /* 0x14 */
    u32 attr_or;       /* 0x18 */
    NJS_ARGB colour;   /* 0x1C */
    s32 fog;           /* 0x2C */
    s32 blend_src;     /* 0x30 */
    s32 blend_dst;     /* 0x34 */
} Obj8009D88C;
typedef struct {
    u8 pad00[0x178];
    s32 state;        /* 0x178 */
    u32 key;          /* 0x17C */
    s32 i180;         /* 0x180 */
    f32 f184, f188, f18C; /* 0x184 */
    s32 i190, i194, i198; /* 0x190 */
} Work8009DCA8;
typedef struct {
    u8 pad00[0x16C];
    s16 active;       /* 0x16C */
    u8 pad16E[0x1D8 - 0x16E];
    Work8009DCA8* work; /* 0x1D8 */
    u32 base;         /* 0x1DC */
} Obj8009DCA8;
typedef struct {
    u32 key;
    s32 i04;
    f32 f08, f0C, f10;
    s32 i14, i18, i1C;
} Src8009DCA8;
void fn_8009DCA8(Obj8009DCA8* o, Src8009DCA8* src);
extern f32 fn_80291A5C(f32 x);
typedef struct {
    u8 pad[0x2c];
    f32 x2c, x30, x34;
    s32 x38, x3c, x40;
    u32 x44;
} Cfg_800ABEB4;
typedef struct {
    u8 pad[0x10];
    Cfg_800ABEB4* cfg;
} Link_800ABEB4;
typedef struct {
    u8 pad0[0xb4];
    f32 xb4, xb8, xbc;
    s32 xc0, xc4, xc8;
    u8 padcc[0xe4 - 0xcc];
    void* xe4;
    u8 pade8[0x16c - 0xe8];
    s16 x16c;
    u8 pad16e[0x1c8 - 0x16e];
    Link_800ABEB4* link;
    u8 pad1cc[0x1fa - 0x1cc];
    u8 x1fa, x1fb;
    s16 x1fc;
    u8 pad1fe[0x21c - 0x1fe];
    u8 x21c;
    u8 pad21d[0x232 - 0x21d];
    s16 x232;
    u8 pad234[2];
    u16 x236;
    u8 pad238[0x25c - 0x238];
    void* x25c;
    u8 pad260[4];
    void* x264;
} Work_800ABEB4;
extern void* fn_8009D5BC();
typedef struct {
    u32 flags;
    u8 pad04[0x2c - 4];
    s32 x2c;
    u8 pad30[4];
    void* buf;    /* 0x34 */
    void* x38;
    u8 x3c[0xc];
    u8* x48;
    s32 x4c;
    u8 x50[0x48];
} State_800B016C;
extern State_800B016C lbl_80303650;
extern void* fn_80227E74(void);
extern void fn_80297DB4(void* a, void* b, s32 c, s32 d, s32 e);
extern void fn_80297DA4(void* a, void* b, void* c, s32 d);
extern s32 fn_80007528(u8** p);
extern s32* fn_80298E6C(void);
extern void fn_80297B5C(void* p);
extern void fn_801E1784(void* p);
typedef struct {
    u8 pad[4];
    s32 mode;
} Work_800B0FD0;
typedef struct {
    u8 pad[0x18];
    u8 flags;
    u8 state;
    u8 pad1a[0x24 - 0x1a];
    Work_800B0FD0* work;
} Obj_800B0FD0;
typedef struct {
    s32 mode;
    u8 pad[0x18];
} Blk_80303618;
extern Blk_80303618 lbl_80303618;
extern void fn_80226D14(void);
extern void fn_80296ED4(s32 v);
extern void fn_800B0278(void);
extern void fn_800AF780(void);
extern void fn_800AF8F8(void);
extern void DrawStateDefault2D();
typedef struct {
    u8 pad[0x1a0];
    s32 x1a0;
    u8 pad1a4[0x260 - 0x1a4];
    void* x260;
    u8 pad264[0x31c - 0x264];
    void* x31c;
} Hook_800B2334;
typedef struct {
    u8 pad[0x48];
    u32 x48;
} Cfg_800B2334;
typedef struct {
    u8 pad[0x10];
    Cfg_800B2334* cfg;
} Link_800B2334;
typedef struct {
    u8 pad0[0x18];
    u32 x18;
    u8 pad1c[0x100 - 0x1c];
    void* x100;
    u8 pad104[0x1c8 - 0x104];
    Link_800B2334* link;
    u8 pad1cc[0x1d8 - 0x1cc];
    Hook_800B2334* hook;
    u8 pad1dc[0x25c - 0x1dc];
    void* x25c;
    u8 pad260[0x26c - 0x260];
    u8 x26c;
} Work_800B2334;
typedef struct {
    u8 pad[0x1fa];
    u8 x1fa;
    u8 x1fb;
} Sub_800B2334;
typedef struct {
    u8 pad[0x19];
    u8 state;
    u8 x1a;
    u8 x1b;
    u8 pad1c[0x24 - 0x1c];
    Sub_800B2334* work;
} Obj_800B2334;
extern void fn_80227810(void* p);
extern void fn_800ABEB0();
extern void fn_800ABE9C();
typedef struct { f32 x, y; f32 pad[4]; } Pt;
typedef struct {
    u8 pad[0x15c];
    Pt *pts;
    u8 pad2[0x178 - 0x160];
    f32 cx, cy;
} Obj;
extern s16 lbl_80346CA0;
typedef struct Node_8009D294 Node_8009D294;
typedef struct {
    u32 pad0;
    s16 *stream;
} Mesh;
struct Node_8009D294 {
    u32 flags;
    Mesh *mesh;
    u8 pad[0x2c - 8];
    Node_8009D294 *child;
    Node_8009D294 *sibling;
};
extern s32 fn_801CB460(s32 op);
typedef struct {
    s32 w0, w4, w8;
    u8 pad0[0x24 - 0xc];
    f32 f24, f28, f2c, f30;
    s32 w34, w38;
    u8 pad1[0x44 - 0x3c];
    s32 w44, w48, w4c, w50;
    f32 f54;
    s32 w58, w5c, w60, w64, w68, w6c, w70;
    f32 f74, f78;
} P;
extern s32 fn_8025ECC4(void);
typedef struct {
    s32 mode;
    f32 *pts;
    u16 n;
    u8 pad_0a[4];
    u16 limit;
    u32 frame;
    f32 scale;
    f32 num;
} Blk;
typedef struct {
    u8 pad[4];
    DrawState ds;
} Fx;
extern void fn_80297DC8(s32 a);
extern void fn_80291064(void *p, s32 a, s32 b);
typedef struct {
    u8 pad0[8];
    u32 x8;
} Hdr;
typedef struct {
    u32 count;
} Cnt;
typedef struct {
    u8 pad[0x10];
    Cnt *cnt;
} Link;
typedef struct {
    Hdr *hdr;
} Hk;
typedef struct {
    u8 pad0[0x100];
    Hk *x100;
    u8 pad104[0x1c8 - 0x104];
    Link *link;
    u8 pad1cc[0x1fa - 0x1cc];
    u8 x1fa;
    s8 x1fb;
    u8 pad1fc[0x25c - 0x1fc];
    void *x25c;
} Work;
typedef struct {
    u8 pad0[0x18];
    u8 flags;
    u8 state;
    u8 pad1a[0x24 - 0x1a];
    Work *work;
} Obj_800B2428;
extern f32 lbl_80346C70;
extern s32 lbl_80346C6C;
extern s32 lbl_80346C50;
extern f32 lbl_80345878[];
extern s32 lbl_80311AD4[11];
extern NJS_TEXLIST lbl_80347568;
extern u8 lbl_8030A318[];
extern u8 lbl_802F60B0[];
extern void njTranslate(NJS_MATRIX m, f32 x, f32 y, f32 z);
extern void njPushMatrixEx(void);
extern void njPopMatrixEx(void);
extern void fn_8028BB90(void* p);
extern void fn_8022B960(void* p);
extern void fn_80286EE8(void);
extern void fn_8028B498(void);
extern void fn_80299040(NJS_TEXLIST* t);
extern void fn_80287B38(void* p);
extern s32 fn_80097720(void);
extern s32 fn_80097CEC(void* p);
typedef struct V3_800A3ED4 {
    f32 x, y, z;
} V3_800A3ED4;
typedef struct Tbl_800A3ED4 {
    s32 n;
    u32 w[8];
} Tbl_800A3ED4;
typedef struct Tbl2_800A3ED4 {
    u32 n;
    u32 w[2];
} Tbl2_800A3ED4;
typedef struct Src_800A3ED4 {
    u8 pad0[4];
    s32 w4;
    u8 pad8[8];
    Tbl_800A3ED4* p10;
    u8 pad14[0x1c - 0x14];
    Tbl2_800A3ED4* p1c;
    u8 pad20[0x38 - 0x20];
    void* p38;
    u8 pad3c[0x44 - 0x3c];
    V3_800A3ED4 v44;
    f32 f50, f54, f58;
    V3_800A3ED4 v5c;
} Src_800A3ED4;
typedef struct Sub_800A3ED4 {
    s16 h0;
    u8 pad2[0x2c - 2];
    s32 w2c;
    s32 w30;
    s32 w34;
    V3_800A3ED4 v38;
    s32 w44, w48, w4c;
    V3_800A3ED4 v50;
    u8 pad5c[0xe4 - 0x5c];
    s32 we4;
    s32 we8;
    s32 wec;
    u8 padf0[0x100 - 0xf0];
    void* w100;
    u8 pad104[0x16e - 0x104];
    s16 h16e;
    u8 pad170[0x178 - 0x170];
    s16 h178;
    s16 h17a;
    u8 pad17c[0x190 - 0x17c];
    f32 f190;
    u8 pad194[0x1a8 - 0x194];
    f32 f1a8;
    u8 pad1ac[0x1c8 - 0x1ac];
    Src_800A3ED4* p1c8;
} Sub_800A3ED4;
typedef struct Obj_800A3ED4 {
    u8 pad0[0x18];
    u8 flags;
    u8 pad19[0x24 - 0x19];
    Sub_800A3ED4* sub;
    u8 pad28[0x40 - 0x28];
    u8 area[0x270 - 0x40];
} Obj_800A3ED4;
extern s32 fn_800C355C(void** out, Src_800A3ED4* ctx, s32 idx);
typedef struct Col_800B2588 {
    u8 a, r, g, b;
} Col_800B2588;
typedef struct Q_800B2588 {
    u32 flags;
    u8 pad4[0x78 - 4];
    Col_800B2588 col78;
} Q_800B2588;
typedef struct QO_800B2588 {
    u8 pad0[0x268];
    Q_800B2588 *p268;
} QO_800B2588;
typedef struct Tbl_800B2588 {
    u32 w0;
    u32 w4;
    s32 w8;
    u32 wc;
    u32 w10;
    u32 w14;
    s32 w18;
    s32 w1c;
} Tbl_800B2588;
typedef struct Sub_800B2588 {
    u8 pad0[0x10];
    Tbl_800B2588 *tbl;
} Sub_800B2588;
typedef struct Aux_800B2588 {
    u8 pad0[0x1a0];
    s32 w1a0;
} Aux_800B2588;
typedef struct Ctx_800B2588 {
    u8 pad0[0x1c8];
    Sub_800B2588 *sub;      /* 0x1c8 */
    u8 pad1cc[0x1d8 - 0x1cc];
    Aux_800B2588 *aux;      /* 0x1d8 */
    u8 pad1dc[0x1fb - 0x1dc];
    u8 b1fb;
    u8 pad1fc[0x26c - 0x1fc];
    u8 b26c;
} Ctx_800B2588;
typedef struct Obj_800B2588 {
    u8 pad0[0x18];
    u8 flags18;
    u8 state;
    u8 pad1a;
    u8 b1b;
    u8 pad1c[0x24 - 0x1c];
    Ctx_800B2588 *ctx;
} Obj_800B2588;
typedef struct Inner_800B2588 {
    void *p00;
    s32 w04;
    s32 w08;
    u8 pad0c[0xa8 - 0xc];
    s32 wa8;
    s32 wac;
} Inner_800B2588;
typedef struct Task_800B2588 {
    u8 pad0[0x24];
    Inner_800B2588 *inner;
    u8 pad28[0x40 - 0x28];
} Task_800B2588;
/* Scales a 0..1 float to a u8 (x * 255) with the SDK fast cast (psq_st through GQR2).
 * The original calls the Dolphin SDK inline __OSf32tou8 from <dolphin/os/OSFastCast.h>.
 * The game code itself is plain C. Siblings: fn_8009E4B8 = __OSu8tof32(b) * K,
 * fn_8009E4D4 = __OSf32tou8((K0 + x) * 255). */
#include <dolphin/os/OSFastCast.h>
typedef unsigned char u8;
typedef float f32;
typedef struct { u8 pad[0x19]; u8 state; } Obj_800A35E0_C;
typedef struct { u8 pad[0x4]; Obj_800A35E0_C *c; } Obj_800A35E0_B;
typedef struct { u8 pad[0x1d8]; Obj_800A35E0_B *b; } Obj_800A35E0_A;
typedef struct {
    f32 f0;      /* 0x00 */
    f32 f4;      /* 0x04 */
    f32 f8;      /* 0x08 */
    f32 fc;      /* 0x0C */
    f32 f10;     /* 0x10 */
    u8 pad14[0x1C - 0x14];
    s16 lim;     /* 0x1C */
} Cfg;
typedef struct {
    s16 active;  /* 0x00 */
    s16 wait;    /* 0x02 */
    u8 pad4[0x8C - 4];
    f32 x;       /* 0x8C */
    f32 y;       /* 0x90 */
    f32 z;       /* 0x94 */
    u8 pad98[0xAC - 0x98];
    s16 step;    /* 0xAC */
    u8 padae[2];
    f32 fb0;     /* 0xB0 */
} Ent;
extern Cfg* lbl_80346C7C;
typedef struct NJS_MOTION {
    u8 pad0[4];
    u32 nbFrame;
} NJS_MOTION;
typedef struct {
    s32 size;
    u8 pad4[0x14];
    s32 flags; /* 0x18, valid when size > 5 */
} ExtInfo;
typedef struct {
    u8 pad0[0x10];
    ExtInfo* info; /* 0x10 */
} Ext;
typedef struct {
    u8 pad0[0x1A0];
    s32 x1a0;
} Aux;
typedef struct {
    u8 pad0[0x1C];
    f32 alpha;               /* 0x1C */
    u8 pad20[0x38 - 0x20];
    NJS_POINT3 pos;          /* 0x38 */
    Angle ang[3];            /* 0x44 */
    NJS_POINT3 scl;          /* 0x50 */
    u8 pad5C[0xE4 - 0x5C];
    void* model;             /* 0xE4 */
    NJS_MOTION* motion;      /* 0xE8 */
    void* shape;             /* 0xEC */
    u8 padF0[0x100 - 0xF0];
    NJS_TEXLIST* texlist;    /* 0x100 */
    u8 pad104[0x176 - 0x104];
    u16 id;                  /* 0x176 */
    u8 pad178[0x184 - 0x178];
    s32 hidden;              /* 0x184 */
    u8 pad188[4];
    f32 frame;               /* 0x18C */
    f32 speed;               /* 0x190 */
    u8 pad194[4];
    s32 looped;              /* 0x198 */
    u8 pad19c[0x1C8 - 0x19C];
    Ext* ext;                /* 0x1C8 */
    u8 pad1cc[0x1D8 - 0x1CC];
    Aux* aux;                /* 0x1D8 */
} Obj_8009D994;
extern void njTranslateEx(NJS_POINT3* p);
extern void njRotateEx(Angle* a, s32 flag);
extern void fn_801E7194(s32 id, void* model, void* motion, void* shape, f32 frame);
extern void fn_801E4CB0(s32 id, void* model);
typedef struct Node_8009E9D8 {
    u32 flags;          /* 0x00 */
    u8 pad4[4];
    NJS_POINT3 pos;     /* 0x08 */
    Angle ang[3];       /* 0x14 */
    NJS_POINT3 scl;     /* 0x20 */
    struct Node_8009E9D8* child; /* 0x2C */
    struct Node_8009E9D8* sibling; /* 0x30 */
} Node_8009E9D8;
typedef struct {
    NJS_POINT3* point;
    void* rot;
} Out;
extern NJS_MATRIX lbl_803034D8;
extern NJS_MATRIX lbl_80303498;
extern s32 lbl_80346CFC;
extern u32 lbl_80346CF4;
extern u32 lbl_80346CF8;
extern Node_8009E9D8* lbl_80346D00;
extern NJS_POINT3 lbl_802B0EDC;
extern void njSetMatrix(NJS_MATRIX dst, NJS_MATRIX src);
extern s32 fn_80007080(void* dst, s32 flag);
extern s32 fn_80006F1C(void* dst, s32 flag);
extern s32 fn_80006DA0(void* dst, s32 flag);
extern void fn_80006CE0(void);
extern void fn_80291C44(NJS_MATRIX m);
typedef struct {
    s32 x, y, z;
} Ang3;
extern void fn_800A1690(f32* m, Ang3* out);
typedef struct Obj_800A0BA0 Obj_800A0BA0;
typedef struct {
    u8 pad0[4];
    void* x4;
    Obj_800A0BA0* x8;
} Aux_800A0BA0;
struct Obj_800A0BA0 {
    u8 pad0[0x38];
    NJS_POINT3 pos;      /* 0x38 */
    Ang3 ang;            /* 0x44 */
    NJS_POINT3 scl;      /* 0x50 */
    u8 pad5c[0xB4 - 0x5C];
    NJS_POINT3 pivotPos; /* 0xB4 */
    Ang3 pivotAng;       /* 0xC0 */
    u8 padcc[0x16C - 0xCC];
    s16 pivot;           /* 0x16C */
    u8 pad16e[0x1D8 - 0x16E];
    Aux_800A0BA0* aux;            /* 0x1D8 */
    u8 pad1dc[0x20C - 0x1DC];
    Ang3 outAng;         /* 0x20C */
    u8 pad218[0x24C - 0x218];
    NJS_POINT3 outPos;   /* 0x24C */
};
extern NJS_POINT3 lbl_802B0EAC;
extern s32 fn_8015F1F0(void);
extern void njUnitTransPortion(NJS_MATRIX m);
typedef struct Obj_800A0E1C Obj_800A0E1C;
typedef struct {
    u8 pad0[0x24];
    Obj_800A0E1C* x24;
} Tgt_800A0E1C;
typedef struct {
    u8 pad0[4];
    Tgt_800A0E1C* x4;
    Obj_800A0E1C* x8;
} Aux_800A0E1C;
struct Obj_800A0E1C {
    u8 pad0[0x38];
    NJS_POINT3 pos;      /* 0x38 */
    Ang3 ang;            /* 0x44 */
    NJS_POINT3 scl;      /* 0x50 */
    u8 pad5c[0xB4 - 0x5C];
    NJS_POINT3 pivotPos; /* 0xB4 */
    Ang3 pivotAng;       /* 0xC0 */
    u8 padcc[0x16C - 0xCC];
    s16 pivot;           /* 0x16C */
    u8 pad16e[0x1D8 - 0x16E];
    Aux_800A0E1C* aux;            /* 0x1D8 */
    u8 pad1dc[0x20C - 0x1DC];
    Ang3 outAng;         /* 0x20C */
    u8 pad218[0x24C - 0x218];
    NJS_POINT3 outPos;   /* 0x24C */
};
extern NJS_POINT3 lbl_802B0EA0;
typedef struct {
    NJS_POINT3 v[2];
} Pair_800A13D8;
extern NJS_POINT3 lbl_802B0E88[2];
extern Pair_800A13D8 lbl_80303438;
extern u8 lbl_802B0E30[0x40];
extern f32* lbl_80346784;
extern f32* lbl_80346780;
extern void* fn_802AC710(void* dst, void* src, int n);
extern void njCalcVectors(NJS_MATRIX m, NJS_POINT3* src, NJS_POINT3* dst, s32 n);
extern void njCalcPoints(NJS_MATRIX m, NJS_POINT3* src, NJS_POINT3* dst, s32 n);
extern void njRotateX(NJS_MATRIX m, Angle a);
extern void njRotateY(NJS_MATRIX m, Angle a);
typedef struct {
    f32 x, y;
    u32 col;
} Vtx;
typedef struct {
    u8 pad0[8];
    s16 id;         /* 0x08 */
    u8 alpha;       /* 0x0A */
    u8 pad0b;
    Vtx v[4];       /* 0x0C */
    s16 u;          /* 0x3C */
    s16 w;          /* 0x3E */
    NJS_TEXLIST* tex; /* 0x40 */
} Obj_800A1BA4;
typedef struct {
    f32* p;
    u32* col;
    s16* uv;
    s32 count;
} Buf;
extern f32 fn_801DBD9C(f32 z);
extern void fn_80298FE4(s32 i);
extern void fn_801CCD90(Buf* b, s32 n, s32 textured, NJS_TEXLIST* tex, s32 idx, f32 z, s32 flags);
typedef struct Tbl { u32 n; u32 w[0x40]; } Tbl;
typedef struct Tbl2_800AE000 { s32 n; struct Item_800AE000* w[2]; } Tbl2_800AE000;
typedef struct Item_800AE000 { s32 w0; u32 w4; } Item_800AE000;
typedef struct Cfg_800AE000 {
    u8 pad0[0x10];
    Tbl* p10;
    u8 pad14[0x1c - 0x14];
    Tbl2_800AE000* p1c;
} Cfg_800AE000;
typedef struct Work_800AE000 {
    u8 pad0[0x170];
    u16 h170;
    u8 pad172[0x17a - 0x172];
    u16 h17a;
    u8 pad17c[0x1c8 - 0x17c];
    Cfg_800AE000* cfg;
    u8 pad1cc[0x1fb - 0x1cc];
    s8 b1fb;
    u8 pad1fc[0x24c - 0x1fc];
    f32 f24c;
    u8 pad250[0x26c - 0x250];
    u8 b26c;
} Work_800AE000;
typedef struct Obj_800AE000 {
    u8 pad0[0x19];
    u8 state;
    u8 pad1a[0x24 - 0x1a];
    Work_800AE000* work;
} Obj_800AE000;
extern void fn_8015E600(Work_800AE000*);
extern void fn_800972AC(void);
extern Work_800AE000* fn_8015F180(Work_800AE000*);
extern void fn_80097294(s32);
extern void fn_800970D8(u16, s32, f32);
extern void fn_800970B4(u16, s32, f32);
extern void fn_8015EBF4(Work_800AE000*);
typedef struct Camera {
    s16 mode;            /* 0x000 */
    s16 flags;           /* 0x002 */
    u8 pad_004[0x0c - 0x04];
    f32 pos[3];          /* 0x00C */
    u8 pad_018[0x30 - 0x18];
    f32 tgt[3];          /* 0x030 */
    s32 roll;            /* 0x03C */
    u8 pad_040[0x58 - 0x40];
    f32 v58[6];          /* 0x058 */
    s32 ang[3];          /* 0x070 */
    u8 pad_07c[0x94 - 0x7c];
    NJS_VECTOR dir;      /* 0x094 */
    NJS_VECTOR up;       /* 0x0A0 */
    u8 pad_0ac[0xd0 - 0xac];
    f32 fd0;             /* 0x0D0 */
    f32 fd4;             /* 0x0D4 */
    s32 xd8;             /* 0x0D8 */
    u8 pad_0dc[0xe6 - 0xdc];
    s16 xe6;             /* 0x0E6 */
    u8 pad_0e8[0x100 - 0xe8];
    s32 x100;            /* 0x100 */
    s32 x104;            /* 0x104 */
    u8 pad_108[0x16c - 0x108];
    s8 ret_mode;         /* 0x16C */
    u8 ret_flags;        /* 0x16D */
    s16 ret_e6;          /* 0x16E */
    f32 ret_pos[3];      /* 0x170 */
    f32 ret_tgt[3];      /* 0x17C */
    s32 ret_roll;        /* 0x188 */
    f32 ret_v58[6];      /* 0x18C */
    s32 ret_ang[3];      /* 0x1A4 */
    s32 ret_rot[3];      /* 0x1B0 */
    f32 ret_d4;          /* 0x1BC */
    u16 ret_d8;          /* 0x1C0 */
    u16 ret_100;         /* 0x1C2 */
    f32 ret_d0;          /* 0x1C4 */
} Camera;
extern void fn_801DD334(NJS_VECTOR *dir, NJS_VECTOR *up, s32 *rot);
typedef struct SrcRec {
    f32 v[6];
} SrcRec;
typedef struct SrcHdr {
    u8 pad0[4];
    s16 count;      /* 0x04 */
    u8 pad6[2];
    SrcRec recs[1]; /* 0x08 */
} SrcHdr;
typedef struct Node_8009877C {
    s16 used;       /* 0x00 */
    u8 pad2[6];
    SrcRec *src;    /* 0x08 */
    u8 padc[0x8C - 0xC];
    f32 v[6];       /* 0x8C */
    u8 pada4[0xB4 - 0xA4];
} Node_8009877C;
typedef struct Owner_8009877C {
    u8 pad0[8];
    SrcHdr **data;  /* 0x08 */
    u8 padc[0xBB10 - 0xC];
    s32 id;         /* 0xBB10 */
    s32 count;      /* 0xBB14 */
    Node_8009877C *nodes;    /* 0xBB18 */
} Owner_8009877C;
extern Node_8009877C *lbl_80346CB0;
extern void DCStoreRange(void *p, u32 n);
typedef struct Axis {
    s32 on;         /* 0x00 */
    f32 spd;        /* 0x04 */
    f32 val;        /* 0x08 */
    f32 lim;        /* 0x0C */
} Axis;
typedef struct Node_80099078 {
    s16 used;       /* 0x00 */
    s16 delay;      /* 0x02 */
    u8 pad4[8];
    Axis axis[8];   /* 0x0C */
    f32 ofs[8];     /* 0x8C */
    u8 padac[0xB4 - 0xAC];
} Node_80099078;
typedef struct Key {
    s32 time;       /* 0x00 */
    f32 val;        /* 0x04 */
} Key;
typedef struct Track {
    s16 flags;      /* 0x00 */
    s16 count;      /* 0x02 */
    u8 pad4[4];
    Key keys[1];    /* 0x08 */
} Track;
typedef struct Leaf {
    u8 pad0[0x24];
    f32 val[2];     /* 0x24 */
} Leaf;
typedef struct Obj_8009B3F4 {
    u8 pad0[0x202];
    s16 idx[2];     /* 0x202 */
    u8 pad206[0x20C - 0x206];
    s32 timer[2];   /* 0x20C */
    u8 pad214[0x24C - 0x214];
    f32 target[2];  /* 0x24C */
    u8 pad254[0x25C - 0x254];
    Leaf *leaf;     /* 0x25C */
    Track *track[2]; /* 0x260 */
} Obj_8009B3F4;
typedef struct Obj_8009B4C0 {
    u8 pad0[0x202];
    s16 idx[2];     /* 0x202 */
    u8 pad206[0x20C - 0x206];
    s32 timer[2];   /* 0x20C */
    u8 pad214[0x24C - 0x214];
    f32 target[2];  /* 0x24C */
    u8 pad254[0x25C - 0x254];
    Leaf *leaf;     /* 0x25C */
    Track *track[2]; /* 0x260 */
} Obj_8009B4C0;
typedef struct Ang3_800A1998 {
    s32 x, y, z;
} Ang3_800A1998;
extern void njUnitMatrix(NJS_MATRIX m);
extern void fn_802135B4(NJS_POINT3 *v, Ang3_800A1998 *out);
typedef struct {
    NJS_POINT3 v[2];
} Pair_800A1690;
extern NJS_POINT3 lbl_802B0E70[2];
extern Pair_800A1690 lbl_80303450;
extern f32* lbl_80346778;
extern f32* lbl_8034677C;
extern void njRotateZ(NJS_MATRIX m, Angle a);
/* Byte (0..255) to a 0..1 float: __OSu8tof32(&b) * (1/255).
 * Needs the Dolphin SDK fast-cast inline __OSu8tof32 (psq_l through GQR2), which our
 * extern/sdk OSFastCast.h lacks. The SDK's definition is reproduced here only until it is
 * added to <dolphin/os/OSFastCast.h>; the game code itself is the one-line function. */
#include <dolphin/os/OSFastCast.h>
typedef unsigned char u8;
typedef struct Ent_8009884C {
    s16 h0;
    u8 pad2[0xc - 2];
    s32 w0c;
    f32 f10;
    f32 f14;
    s32 w18;
    s32 w1c;
    u8 pad20[4];
    f32 f24;
    s32 w28;
    s32 w2c;
    u8 pad30[4];
    f32 f34;
    s32 w38;
    s32 w3c;
    f32 f40;
    f32 f44;
    u8 pad48[4];
    s32 w4c;
    f32 f50;
    f32 f54;
    u8 pad58[0x8c - 0x58];
    f32 f8c;
    f32 f90;
    u8 pad94[0xb4 - 0x94];
} Ent_8009884C;
typedef struct Ref_800AE300 {
    u8 pad0[0x18];
    u8 flags18;
    u8 pad19[0x24 - 0x19];
    void *p24;
} Ref_800AE300;
typedef struct Work_800AE300 {
    Ref_800AE300 *ref;  /* 0x00 */
    s32 w04;
    s32 w08;
    s32 list[0x94 / 4]; /* 0x0c */
    s32 n;              /* 0xa0 */
    s32 pada4;
    s32 wa8;
    s32 wac;
} Work_800AE300;
typedef struct Obj_800AE300 {
    u8 pad0[8];
    Ref_800AE300 *ref;
    u8 pad0c[0x18 - 0xc];
    u8 flags18;
    u8 state;
    u8 pad1a[0x24 - 0x1a];
    Work_800AE300 *work;
} Obj_800AE300;
extern void fn_800AE4E0(s32 a, s32 *out);
extern s32 fn_800B2DC0(void *c, s32 idx, s32 a, s32 b, f32 f);
typedef struct Tab_8009CBBC {
    f32 a3[3];
    f32 b3[3];
    f32 c3[3];
    f32 d3[3];
    f32 e3[3];
    f32 f3[3];
    f32 a[6];
    f32 b[6];
    f32 c[6];
    f32 d[6];
    f32 e[6];
    f32 f[6];
} Tab_8009CBBC;
typedef struct Pos_8009CBBC {
    u8 pad0[0x38];
    f32 x;
    u8 pad3c[4];
    f32 z;
} Pos_8009CBBC;
extern Tab_8009CBBC lbl_802E0E18;
extern struct { u8 pad[0x88]; u32 flags; } lbl_80310B3C;
extern Pos_8009CBBC* lbl_80347450;
extern u32 fn_80218DC4(void);
extern void sndSeqSetMidiCtrl(u32 id, u8 ch, s32 ctrl, s32 val);

void fn_800972AC(void)
{
    lbl_802E0084.mode = 0xf;
    lbl_802E0084.field2 = 0;
}

void fn_800972C4(void)
{
    lbl_802E0084.mode = -1;
    lbl_802E0084.field2 = 0;
    lbl_802E0084.flags = 0;
}

void fn_800972E0(s8 x) {
    if (x == 0) {
        lbl_802E0084.flags |= 0x2;
    } else {
        lbl_802E0084.flags &= ~0x2;
    }
}

void fn_80097318(s8 x) {
    if (x != 0) {
        lbl_802E0084.flags |= 0x1;
    } else {
        lbl_802E0084.flags &= ~0x1;
    }
}

void fn_80097350(s32 x) {
    if (x == 0) {
        lbl_80302F18[1] |= 0x8;
    } else {
        lbl_80302F18[1] &= ~0x8;
    }
}

BOOL fn_80097608(void *unused, Obj12 *p)
{
    return p->v12 == 1;
}

s32 fn_8009761C(s32 a, u16 b)
{
    s32 k = 0x10000;
    return (u16)(a + (k - 0x8000 - b)) - 0x8000;
}

s8 fn_8009763C(void)
{
    s32 r = -1;
    if (lbl_80346C3C == 2) {
        r = lbl_80302F18[0];
    }
    return (s8)r;
}

void fn_80097660(void)
{
    lbl_80346750 = 1;
}

void fn_800976EC(void)
{
    lbl_80346C3C = 1;
}

void fn_80097AFC(void)
{
    lbl_803473F8 = 0;
    lbl_803473F4 = 0;
}

void fn_80097CA4(void *p) {
    fn_800D2CA8(0);
    fn_80097B0C(p);
}

void fn_80097CDC(void)
{
    lbl_803473F0 = lbl_80303340;
}

s32 fn_8009B58C(s32 unused, Obj8009B58C *obj, Entry8009B58C *e, s16 arg) {
    s32 ret = 0;
    s32 v = ((e->count - 1) * 8 + 16) / 4;
    if (v == arg) {
        obj->flags188 |= e->flag & 0x10000;
        obj->entry260 = e;
        ret = 1;
    }
    return ret;
}

s32 fn_8009B5D4(s32 unused, Obj8009B5D4 *obj, Entry8009B5D4 *e, s16 arg) {
    s32 ret = 0;
    s32 v = ((e->count - 1) * 8 + 16) / 4;
    if (v == arg) {
        obj->flags188 |= e->flag & 0x10000;
        obj->entry264 = e;
        ret = 1;
    }
    return ret;
}

u32 fn_8009C50C(void *unused, Obj10 *p)
{
    return (p->v10 >> 14) & 1;
}

typedef struct Msg {
    s16 x0;
    s16 x2;
    s16 x4;
    s16 x6;
    s32 x8;
    s32 xc;
} Msg;
extern void fn_801E7E14(Msg*, s16);
void fn_8009CBB8(void) {
}

void fn_8009D274(Msg* a, s16 i) {
    fn_801E7E14(a, i);
}

void fn_8009D67C(Obj8009D67C *o, s32 idx) {
    s32 *t;
    u32 v;
    t = o->sub->table;
    if (t[0] > idx) {
        v = t[idx + 1];
    } else {
        v = 0;
    }
    if (v != 0) {
        o->field_ec = v;
    } else {
        o->field_ec = 0;
    }
}

void fn_8009DC58(Obj8009DC58 *o) {
    Inner8009DC58 *p = o->sub->p10;
    u32 *q;

    o->flags23a = 0;
    if (p->x44 != 0) {
        o->flags23a |= 1;
        q = &p->x48;
    } else {
        q = &p->x48;
    }
    if (*q == 0) {
        return;
    }
    o->flags23a |= 4;
}

f32 fn_8009E4F8(u8 v) {
    return (s32)(v - 255) * 0.003921569f;
}

Item *fn_8009E530(ItemList_8009E530 *list, s32 count) {
    s32 i;
    Item **items;
    if (list == NULL) {
        return NULL;
    }
    items = list->items;
    for (i = 0; i < count; i++) {
        Item *it = items[i];
        if (it != NULL && it->type == 3) {
            return it;
        }
    }
    return NULL;
}

void fn_8009E630(u32 *p)
{
    *p = 0;
}

void fn_8009E804(ItemList_8009E804 *list, s32 idx) {
    if (idx < 0) {
        return;
    }
    if (list == NULL) {
        return;
    }
    if (list->items[idx] == NULL) {
        return;
    }
    list->items[idx] = NULL;
    list->count--;
}

u32 *fn_800A10A8(u32 *base, u32 i)
{
    u32 *p = base + (2 * i + 1);
    if (p == NULL) {
        return base;
    }
    return (u32 *)*p;
}

s32 fn_800A10C4(Pair *base, s32 i, s32 n)
{
    Pair *p;
    if (i >= n) {
        return 0;
    }
    p = base + i;
    if (p == NULL) {
        return (s32)base;
    }
    return p->a;
}

void fn_800A1948(void *unused, u32 *dst, u8 flags) {
    if (flags & 1) {
        dst[0] = lbl_80311970[7];
    }
    if (flags & 2) {
        dst[1] = lbl_80311970[8];
    }
    if (flags & 4) {
        dst[2] = lbl_80311970[13];
    }
}

void *fn_800A1ABC(ObjB_800A1ABC *b, u32 i)
{
    TblA *t = b->sub_1c8->tbl_10;
    if (i >= t->count) {
        return NULL;
    }
    return &t->items[i];
}

s32 fn_800A1B50(Obj_UNIT0000 *obj) {
    s32 r0 = 0;
    if (obj != NULL) {
        s32 useSub = 0;
        Sub_UNIT0000 *s = obj->f1c8;
        if (s != NULL && s->f20 != NULL && s->f20->f4 != 0) {
            useSub = 1;
        }
        if (useSub != 0) {
            r0 = (s32)s->f20;
        } else {
            r0 = obj->f100;
        }
    }
    return r0;
}

void fn_800A363C(void) {
    lbl_80303468.w00 = 0;
    lbl_80303468.w04 = 0;
    lbl_80303468.w0c = 0;
    lbl_80303468.w08 = 0;
    lbl_80303468.f18 = 0.0f;
    lbl_80303468.f14 = 0.0f;
    lbl_80303468.f10 = 0.0f;
    lbl_80303468.w24 = 0;
    lbl_80303468.w20 = 0;
    lbl_80303468.w1c = 0;
    lbl_80303468.w2c = 0;
    lbl_80303468.f28 = 0.0f;
    lbl_80346CF0 = 0;
}

s32 fn_800A3E90(u32 id) {
    Item *it = fn_8010A164((u16)id);
    if (it == NULL) {
        return 0;
    }
    it->type = 4;
    fn_800A39E0();
    return 1;
}

void fn_800ABE9C(ObjA_800ABE9C *a)
{
    ObjB_800ABE9C *b = a->obj_24;
    b->flag_1fb = 1;
    a->state_19 = 1;
}

void fn_800ABEB0(void) {
}

void fn_800AC44C(ObjA_800AC44C *a)
{
    LeafC *l;
    a->state_19 = 1;
    l = a->obj_24->leaf_25c;
    if (l->state_19 != 1) {
        return;
    }
    l->state_19 = 2;
}

void fn_800AD300(ObjA_800AD300 *a)
{
    ObjB_800AD300 *b = a->obj_24;
    s32 v = -1;
    u32 e = b->sub_1c8->tbl_10->items[26];
    if (e != 0) {
        v = e;
    }
    b->val_1fc = v;
    a->state_19 = 1;
}

void fn_800B0F0C(void) {
    fn_800B0900();
    memset(&lbl_80303618, 0, 0x1c);
    memset(lbl_80303634, 0, 0x1c);
}

s32 fn_8009766C(void) {
    s32 r;
    void* obj;
    if (lbl_80346750 == 0) return 0;
    lbl_80346C40 = 0;
    r = 0;
    obj = fn_802267AC(lbl_80347588, (void*)fn_80096DA4);
    if (obj) {
        *(u8**)((u8*)obj + 0x24) = (u8*)lbl_80302F18;
        *(u32*)((u8*)lbl_80302F18 + 0x108) = 0;
        *(u32*)((u8*)lbl_80302F18 + 0x128) = 0;
        lbl_80346750 = 0;
        r = 1;
    }
    return r;
}

s32 fn_8009E840(Pool* pool, u8* item, s32 n) {
    s32 i = 0;
    s32 idx = -1;
    void** s;
    if (pool == 0) return -1;
    s = pool->slots;
    for (; i < n; i++) {
        if (*s == 0) {
            *s = item;
            idx = i;
            pool->count++;
            break;
        }
        s++;
    }
    if (idx == -1) item[0x19] = 0xff;
    return idx;
}

void* fn_8009E8B0(s32 n) {
    u8* p;
    if (n > 0) {
        p = fn_801E1A2C(1, n * 4 + 8);
        if (p == 0) fn_801DBE1C(lbl_802B0F0C);
        *(u8**)p = p + 8;
    }
    return p;
}

u32 fn_800A1AE8(u8* o, u32 idx) {
    u32 cnt = 0;
    u32* p = *(u32**)(*(u8**)(o + 0x1c8) + 0x10);
    u32 n = p[0];
    s32 found = 0;
    u32 i = idx;
    p += 1;
    if (idx >= n) return 0;
    p += idx;
    while (i < n && !found) {
        if (p[1] == 0) {
            found = 1;
        } else {
            cnt++;
            p += 2;
            i += 2;
        }
    }
    return cnt;
}

void fn_800ADF98(u8* o) {
    u8* a = *(u8**)(o + 0x1c8);
    u8* t = *(u8**)(a + 0x10);
    s32 v = *(s32*)(t + 0x44);
    if ((s32)fabsf((f32)v) == 1) {
        fn_8009DCA8((Obj8009DCA8*)o, (Src8009DCA8*)(t + 0x24));
    }
}

void fn_800986C8(u8 *obj, u8 *src, s32 count) {
    u8 *dst;
    s32 i;
    dst = lbl_80346C94;
    *(s32 *)obj = 1;
    *(s32 *)(obj + 0xbb08) = count;
    *(u8 **)(obj + 0xbb0c) = dst;
    lbl_80346C94 = lbl_80346C94 + count * 0xb4;
    lbl_80346C90 = lbl_80346C90 + count;
    for (i = 0; i < count;) {
        if (*(s32 *)src != 0) {
            memset(dst, 0, 0xb4);
            *(u8 **)(dst + 4) = src + 4;
            *(s16 *)dst = 1;
            *(f32 *)(dst + 0x8c) = *(f32 *)(src + 0x178);
            *(f32 *)(dst + 0x90) = *(f32 *)(src + 0x17c);
        }
        i++;
        dst += 0xb4;
        src += 0x180;
    }
}

s32 fn_8009B61C(void *unused, u8 *obj, s16 *d) {
    (void)unused;
    fn_801E7DF0(*(void **)(obj + 0xe4));
    *(s16 *)(obj + 0x1fe) = d[1];
    *(s16 *)(obj + 0x200) = d[0];
    *(s32 *)(obj + 0x188) |= 1;
    if (d[1] != 0 && d[0] != 0) {
        *(s16 *)(obj + 0x1fc) = 2;
    } else if (d[1] != 0) {
        *(s16 *)(obj + 0x1fc) = 0;
    } else {
        *(s16 *)(obj + 0x1fc) = 1;
    }
    return 0;
}

void fn_8009B8F0(u8 *obj) {
    void *s;
    f32 *f;
    s = fn_801DF988(fn_801C8930(*(void **)(obj + 0xe4)));
    if (s != 0) {
        f = (f32 *)s;
        *(void **)(obj + 0x25c) = s;
        *(s16 *)s = 0;
        f[1] = *(f32 *)(obj + 0x38);
        f[2] = *(f32 *)(obj + 0x3c);
        f[3] = *(f32 *)(obj + 0x40);
        f[6] = 0.0f;
        f[4] = 0.0f;
        f[7] = 0.0f;
        f[5] = 1.0f;
        f[9] = 36.0f;
        f[10] = 5.0f;
        f[13] = -65536.0f;
        f[12] = -65536.0f;
        f[11] = -65536.0f;
        f[16] = 65536.0f;
        f[15] = 65536.0f;
        f[14] = 65536.0f;
        f[8] = 0.5f;
        fn_801E06E0(s);
        *(s32 *)(obj + 0x188) |= 2;
    }
}

void fn_8009D6C0(u8 *obj, s32 idx, f32 f) {
    u32 *tbl = *(u32 **)(*(u8 **)(obj + 0x1c8) + 0x1c);
    u32 *item = (s32)tbl[0] > idx ? (u32 *)tbl[idx + 1] : 0;
    if (item != 0) {
        *(s32 *)(obj + 0x198) = 0;
        *(f32 *)(obj + 0x190) = f;
        *(u32 **)(obj + 0xe8) = item;
        if (0.0f > f) {
            *(f32 *)(obj + 0x18c) = (f32)(*(u32 **)(obj + 0xe8))[1] - 1.0f;
        } else {
            *(f32 *)(obj + 0x18c) = 0.0f;
        }
    } else {
        *(u32 **)(obj + 0xe8) = 0;
        *(f32 *)(obj + 0x190) = 0.0f;
    }
}

f32 fn_8009E3D0(u8 *obj, void *p, f32 *s) {
    void *m;
    f32 r;
    if (p == 0) {
        return 0.0f;
    }
    m = fn_801E1A2C(1, 0x40);
    njUnitMatrix(m);
    fn_801DD76C(m);
    njScale(m, s[0], s[1], s[2]);
    r = fn_8009DEF0(obj, m, p, s, 0.0f);
    fn_801DD71C(0);
    if (m != 0) {
        fn_801E1784(m);
    }
    return r;
}

void fn_8009E578(Node *n) {
    Node *cur = n;
    Node *e;
    while (cur != 0) {
        e = cur;
        if (e->fn != 0) {
            if (e->f20 < 0.0f) {
                fn_80226AE8(e);
            } else {
                e->fn(e);
            }
        }
        cur = cur->next;
        if (e->fn == 0) {
            Node *p = e->owner;
            if (p->b1b == 0xfb) {
                p->next = cur;
            } else {
                p->owner = cur;
            }
            if (cur != 0) {
                cur->owner = e->owner;
            }
            fn_801E17E0(e);
        }
    }
}

void fn_8009E63C(NodeList *s, s32 n) {
    s32 i = 0;
    Node **slot;
    Node *p;
    if (s != 0) {
        slot = s->items;
        while (i < n) {
            if (*slot != 0) {
                (*slot)->b19 = 0xff;
                (*slot)->fn(*slot);
                p = (*slot)->owner;
                if (p->b1b == 0xfb) {
                    p->next = (*slot)->next;
                } else {
                    p->owner = (*slot)->next;
                }
                if ((*slot)->next != 0) {
                    (*slot)->next->owner = (*slot)->owner;
                }
                fn_801E17E0(*slot);
                *slot = 0;
            }
            slot++;
            i++;
        }
        s->count = 0;
    }
}

void fn_8009E71C(NodeList *s, s32 n) {
    s32 i = 0;
    Node **slot;
    Node *p;
    if (s == 0) {
        return;
    }
    slot = s->items;
    while (i < n) {
        if (*slot != 0) {
            (*slot)->b19 = 0xff;
            (*slot)->fn(*slot);
            p = (*slot)->owner;
            if (p->b1b == 0xfb) {
                p->next = (*slot)->next;
            } else {
                p->owner = (*slot)->next;
            }
            if ((*slot)->next != 0) {
                (*slot)->next->owner = (*slot)->owner;
            }
            fn_801E17E0(*slot);
            *slot = 0;
        }
        slot++;
        i++;
    }
    if (s != 0) {
        fn_801E1784(s);
    }
}

void fn_8009E910(s32 *o, s32 mode, u8 *out) {
    if (o == 0) {
        return;
    }
    if (out == 0) {
        return;
    }
    switch (mode) {
    case 0:
    default:
        o[7] = 8;
        o[8] = 6;
        *out = 0xff;
        return;
    case 1:
        o[7] = 8;
        o[8] = 6;
        if (*out == 0) {
            *out = 0x80;
        } else if (*out > 0xff) {
            *out = 0xff;
        }
        return;
    case 2:
        o[7] = 8;
        o[8] = 10;
        *out = 0xff;
        return;
    case 3:
        o[7] = 11;
        o[8] = 7;
        *out = 0xff;
        return;
    }
}

f32 fn_800A0ADC(s32 a, s32 b, u32 flags, f32 t) {
    s32 m0 = flags & 0xff;
    s32 m1 = (flags >> 8) & 0xff;
    s32 m2 = (flags >> 16) & 0xff;
    f32 ratio;
    f32 p;
    f32 r = t;
    if (b > 0) {
        ratio = (f32)a / (f32)b;
        if (m1 != 0) {
            ratio = 1.0f - ratio;
        }
        p = (f32)pow((f64)ratio, (f64)(f32)m2);
        r = p;
        if (m0 == 0) {
            r = p * t;
        }
    }
    return r;
}

void fn_800A1210(NJS_VECTOR *out, NJS_VECTOR *in, Angle deg, f32 radius)
{
    Angle a = (Angle)(182.04445f * (f32)deg);
    out->x = radius * njCos(a);
    out->z = radius * njSin(a);
    out->x = out->x + in->x;
    out->y = in->y;
    out->z = out->z + in->z;
}

void fn_800ADED0(Unit_800ADED0 *self, State_800ADED0 *st)
{
    Ctx10_800ADED0 *c = self->p1c8->p10;
    s32 k = (s32)fabsf((f32)c->w44);
    if (k == 1) {
        fn_8009DCA8((Obj8009DCA8*)self, (Src8009DCA8*)c->inner24);
    } else if (k == 0) {
        if (st->w178 == 1 || st->w178 == 3) {
            if (self->b1fa == 0) {
                st->w178 = 2;
                fn_800A0028(self);
            }
            st->w178 = 0;
            self->h16c = 0;
        }
    }
}

void fn_800B2B34(Self_800B2B34 *self, Ctx_800B2B34 *c)
{
    Inner_800B2B34 *in = c->p1c8;
    if (*in->p10 < 0x33) {
        self->b19 = 4;
    } else {
        self->b1b = 0xfa;
        c->b26c = 1;
        fn_8015ED90(self);
        fn_8015EB8C(c, 0, fn_800ABEB0);
        fn_8015EB8C(c, 0xd, fn_800ABE9C);
        if (c->p1d8 != 0) {
            c->p1d8[0x1a0 / 4] = 0;
        }
        c->p268 = fn_801E1A2C(1, 0x114);
        c->w18 |= 0x1800;
        c->w8 = 1;
        fn_800B45D4(c, c->p268);
        self->sub->b1fa = 1;
        self->b19 = 2;
    }
}

void fn_800974CC(Obj80097388* o) {
    if (o->state != 0) {
        o->n16C = o->state;
        o->b16D = o->flags & 0xA;
        o->s16E = o->sE6;
        if (o->state == 6) {
            o->f170 = o->fAC;
            o->f174 = o->fB0;
            o->f178 = o->fB4;
        } else {
            o->f170 = o->f0C;
            o->f174 = o->f10;
            o->f178 = o->f14;
        }
        o->f17C = o->f30;
        o->f180 = o->f34;
        o->f184 = o->f38;
        o->i188 = o->i3C;
        o->f18C = o->f58;
        o->f190 = o->f5C;
        o->f194 = o->f60;
        o->f198 = o->f64;
        o->f19C = o->f68;
        o->f1A0 = o->f6C;
        o->i1A4 = o->i70;
        o->i1A8 = o->i74;
        o->i1AC = o->i78;
        fn_801DD14C(o->v1B0, o->v94, o->vA0);
        o->f1BC = o->fD4;
        o->u1C0 = o->iD8;
        o->u1C2 = o->i100;
        o->f1C4 = o->fD0;
    } else {
        o->n16C = 0;
    }
    o->flags &= ~4;
}

s32 fn_8009B6B8(s32 unused, Obj8009B6B8* o, Src8009B6B8* src) {
    s32 ok = 0;
    Part8009B6B8* p = o->part;

    if (p == 0) {
        p = fn_801DF988(fn_801C8930(o->h_e4));
    }
    if (p != 0) {
        o->part = p;
        p->kind = 1;
        p->v04 = src->v00;
        p->v0C = src->v08;
        p->v14 = src->v10;
        p->v24 = src->v18;
        o->f254 = p->v24.x;
        o->f258 = p->v24.y;
        p->v2C = src->v20;
        p->v34 = src->v28;
        p->v3C = src->v30;
        p->i44 = src->i38;
        p->f20 = src->f3C;
        p->f1C = 0.0f;
        fn_801E0CB8();
        ok = 1;
        o->flags |= 2;
    }
    return ok;
}

s32 fn_8009B7D4(s32 unused, Obj8009B6B8* o, Src8009B6B8* src) {
    s32 ok = 0;
    Part8009B6B8* p = o->part;

    if (p == 0) {
        p = fn_801DF988(fn_801C8930(o->h_e4));
    }
    if (p != 0) {
        o->part = p;
        p->kind = 0;
        p->v04 = src->v00;
        p->v0C = src->v08;
        p->v14 = src->v10;
        p->v24 = src->v18;
        o->f254 = p->v24.x;
        o->f258 = p->v24.y;
        p->v2C = src->v20;
        p->v34 = src->v28;
        p->v3C = src->v30;
        p->i44 = src->i38;
        p->f20 = src->f3C;
        p->f1C = 0.0f;
        fn_801E06E0();
        ok = 1;
        o->flags |= 2;
    }
    return ok;
}

void fn_8009C3D0(Task8009C3D0* t) {
    Owner8009C3D0* o = t->owner;
    Sub8009C3D0* s;

    switch (t->state) {
    case 0:
        if (o->inner->info->count >= 0xB && o->sub != 0) {
            o->sub->fn = fn_8009C50C;
            t->state = 1;
        } else {
            t->state = 4;
        }
        break;
    case 1:
        s = o->sub;
        if (s->flags & 0x4000) {
            fn_800CD0B8(2, o->inner->info->v2C, 0, o->inner->info->v28);
            s->flags = 0;
            t->state = 2;
        }
        break;
    case 2:
        fn_800CCE0C(2, o->inner->info->v2C);
        t->state = 3;
    case 3:
        s = o->sub;
        if (!(s->flags & 0x4000)) {
            t->state = 1;
        }
        s->flags = 0;
        break;
    case 0xFE:
        break;
    default:
        fn_80100B74(t);
        break;
    }
}

static inline void TaskLink(TNode8009D760* parent, TNode8009D760* t) {
    parent->f04 = t->f04;
    t->f04 = parent->f0C;
    parent->f0C = t;
    t->f0C = parent;
    if (t->f04 != 0) {
        t->f04->f0C = t;
    }
}

TNode8009D760* fn_8009D760(TNode8009D760* parent, void* cb, s16 a, Obj8009D760* obj) {
    TNode8009D760* t = fn_80226704(parent, cb, 0x270);
    Work8009D760* w;

    if (t == 0) {
        fn_801DBE1C("Effect: Particle task make failed.");
    }
    t->flags |= 1;
    t->work = (Work8009D760*)((u8*)t + 0x40);
    if (t != 0) {
        TaskLink(parent, t);
        w = t->work;
        w->obj = obj;
        if (obj->t38 == 0) {
            obj->t38 = t;
        }
        w->f1D8 = 0;
        w->f268 = 0;
        w->f264 = 0;
        w->f260 = 0;
        w->f25C = 0;
        w->f14 = -1;
        w->f18 = 0;
        w->f30 = 8;
        w->f34 = 6;
        w->s178 = a;
        w->s17A = obj->f04;
        w->f1BC = 0;
        t->work->fE4 = parent->work->fE4;
        t->work->f2C = parent->work->f2C;
    }
    return t;
}

void fn_8009D88C(Obj8009D88C* o) {
    DrawState s;
    f32 zero = 0.0f;
    DrawStateGet(&s);
    if (lbl_80347530 == 1) {
        s.control3d &= ~0x100;
    }
    s.control3d &= ~0x204;
    s.control3d = 0x820;
    if (o->colour.a == zero) {
        s.attr_or &= ~0x800;
    } else {
        s.attr_or |= 0x800;
    }
    s.control3d &= ~0x400;
    s.colour = o->colour;
    s.attr_and &= o->attr_and;
    s.attr_or &= ~0x6000;
    s.attr_or |= o->attr_or;
    s.control3d &= ~0x40;
    s.blend_src = o->blend_src;
    s.blend_dst = o->blend_dst;
    s.fog = o->fog;
    DrawStatePush(&s);
}

void fn_8009DCA8(Obj8009DCA8* o, Src8009DCA8* src) {
    Work8009DCA8* w = o->work;
    u32 old;
    f32 zero = 0.0f;

    if (w == 0) {
        return;
    }
    old = (u16)w->key;
    o->active = 1;
    w->key = src->key + o->base;
    w->i180 = src->i04;
    w->f184 = src->f08;
    w->f188 = src->f0C;
    w->f18C = src->f10;
    w->i190 = src->i14;
    w->i194 = src->i18;
    w->i198 = src->i1C;
    if (w->f184 == zero && w->f188 == zero && w->f18C == zero && w->i190 == 0 && w->i194 == 0 && w->i198 == 0) {
        o->active = 0;
    } else {
        o->active = 1;
    }
    if (old != w->key) {
        w->state = 1;
        return;
    }
    if (w->state == 3) {
        w->key |= 0xFFFF0000;
    } else {
        w->state = 1;
    }
}

void fn_800A10E8(NJS_POINT3* p, NJS_POINT3* origin, f32 extra) {
    NJS_POINT3 o;
    f32 dx, dy, dz;
    f32 len, k;
    f32 zero = 0.0f;

    if (origin != 0) {
        o = *origin;
        dx = p->x - o.x;
        dy = p->y - o.y;
        dz = p->z - o.z;
    } else {
        o.z = 0.0f;
        o.y = 0.0f;
        o.x = 0.0f;
        dx = p->x;
        dy = p->y;
        dz = p->z;
    }
    if (dx != zero || dy != zero || dz != zero) {
        len = fn_80291A5C(dx * dx + dy * dy + dz * dz);
        k = (len + extra) / len;
        p->x = o.x + dx * k;
        p->y = o.y + dy * k;
        p->z = o.z + dz * k;
    }
}

void fn_800ABEB4(Work_800ABEB4* w) {
    w->x1fb = 0;
    w->x1fa = 1;
    w->x232 = 0;
    w->x21c = 0;
    if (w->link->cfg->x44 == 1) {
        w->xb4 = w->link->cfg->x2c;
        w->xb8 = w->link->cfg->x30;
        w->xbc = w->link->cfg->x34;
        w->xc0 = w->link->cfg->x38;
        w->xc4 = w->link->cfg->x3c;
        w->xc8 = w->link->cfg->x40;
        w->x16c = 1;
    } else {
        w->xb4 = w->xb8 = w->xbc = 0.0f;
        w->xc0 = w->xc4 = w->xc8 = 0;
        w->x16c = 0;
    }
    w->x1fc = 0;
    w->x236 = 8;
    if (w->x264 == NULL) {
        w->x264 = fn_8009E8B0(w->x236);
    }
    if (w->xe4 != NULL && w->x25c == NULL) {
        fn_801C8930(w->xe4);
        w->x25c = fn_8009D5BC();
    }
}

void fn_800B016C(void) {
    lbl_80303650.buf = fn_801E1A2C(1, 0x100000);
    if (lbl_80303650.buf != NULL) {
        lbl_80303650.x38 = fn_80227E74();
        fn_80297DB4(lbl_80303650.x50, lbl_80303650.buf, 6, 0x400, 0x200);
        fn_80297DA4(lbl_80303650.x3c, lbl_80303650.x50, lbl_80303650.x38, 0x8800000);
        lbl_80303650.x4c = 1;
        lbl_80303650.x48 = lbl_80303650.x3c;
        if (fn_80007528(&lbl_80303650.x48) < 0) {
            lbl_80303650.x2c = fn_80298E6C()[2];
            fn_80297B5C(lbl_80303650.x38);
            if (lbl_80303650.buf != NULL) {
                fn_801E1784(lbl_80303650.buf);
                lbl_80303650.buf = NULL;
            }
        } else {
            lbl_80303650.x2c = 0;
        }
    }
}

void fn_800B0FD0(Obj_800B0FD0* o) {
    Work_800B0FD0* w = o->work;
    if (o->flags & 0x20) {
        o->flags |= 0x40;
        return;
    }
    switch (o->state) {
    case 0:
    case 0xfe:
        o->state = 0xa;
    case 0xa:
        switch (w->mode) {
        case 0:
            if (!(lbl_80303650.flags & 1)) {
                o->state = 0xff;
                break;
            }
            fn_80226D14();
            if (!(lbl_80303650.flags & 8)) {
                fn_80296ED4(0);
            }
            fn_800B0278();
            fn_80296ED4(0x2000);
            break;
        case 1:
            if (!(lbl_80303650.flags & 1)) {
                o->state = 0xff;
                break;
            }
            if (!(lbl_80303650.flags & 8)) {
                fn_80296ED4(0);
            }
            if (lbl_80303618.mode == 6) {
                fn_800AF780();
            } else {
                fn_800AF8F8();
            }
            fn_80296ED4(0x2000);
            break;
        }
        break;
    case 0xff:
        o->flags |= 0x40;
        break;
    }
}

void fn_800B2334(Obj_800B2334* o, Work_800B2334* w) {
    Hook_800B2334* h;
    o->x1b = 0xfa;
    w->x26c = 1;
    fn_8015ED90(o);
    h = w->hook;
    if (h != NULL) {
        h->x1a0 = 0;
        h->x260 = fn_800ABEB0;
        h->x31c = fn_800ABE9C;
    }
    w->x100 = (void*)fn_800A1B50((Obj_UNIT0000*)w);
    if (w->x100 != NULL) {
        fn_80227810(w->x100);
    }
    fn_800ADF98((u8*)w);
    w->x25c = fn_801E1A2C(1, 0x28);
    DrawStateDefault2D();
    w->x18 |= 0x1800;
    if (w->link->cfg->x48 != 0) {
        o->work->x1fa = 1;
        o->state = 2;
    } else {
        o->work->x1fb = 1;
        o->state = 1;
    }
}

void fn_800996D8(Obj *o) {
    f32 sx = 0.0f, sy = 0.0f;
    int n = lbl_80346CA0;
    Pt *p = o->pts;
    Pt *q = p;
    Pt *r;
    f32 cx, cy;
    int i, j;
    for (i = n; i > 0; i--) {
        sx += q->x;
        sy += q->y;
        q++;
    }
    cx = sx / n;
    cy = sy / n;
    r = p;
    for (j = 0; j < lbl_80346CA0; j++) {
        r->x -= cx;
        r->y -= cy;
        r++;
    }
    o->cx = cx;
    o->cy = cy;
}

void fn_8009D294(Node_8009D294 *node, s32 *a, s32 *b) {
    if (node->mesh != NULL && !(node->flags & 8) && node->mesh->stream != NULL) {
        s32 op;
        s32 total;
        s16 *p;
        p = node->mesh->stream;
        total = 0;
        do {
            s32 n;
            s32 len;
            op = *p++ & 0xff;
            n = fn_801CB460(op);
            if (n >= 0) {
                len = *p++;
            } else {
                len = n & 0xffff;
            }
            if (n > 0) {
                switch (op) {
                case 0x41:
                case 0x42:
                case 0x44:
                case 0x45:
                case 0x47:
                case 0x48: {
                    s32 m = *p & 0xffff3fff;
                    s16 *q = p + 1;
                    total++;
                    do {
                        s32 v = *q;
                        if (0 > v) v = -v;
                        total += v * 2;
                        q += n * v + 1;
                    } while (--m > 0);
                    break;
                }
                }
            }
            p += len;
        } while (op != 0xff);
        if (total != 0) {
            *b += total + 1;
            (*a)++;
        }
    }
    if (node->child != NULL && !(node->flags & 0x10)) {
        fn_8009D294(node->child, a, b);
    }
    if (node->sibling != NULL) {
        fn_8009D294(node->sibling, a, b);
    }
}

void fn_800AD588(P *src, P *dst) {
    dst->f24 = src->f24;
    dst->f28 = src->f28;
    dst->f2c = src->f2c;
    dst->f30 = src->f30;
    dst->w34 = src->w34;
    dst->w38 = src->w38;
    dst->w44 = src->w44;
    dst->w48 = src->w48;
    dst->w4c = src->w4c;
    dst->w50 = src->w50;
    dst->f54 = src->f54;
    dst->w58 = src->w58;
    dst->w64 = src->w64;
    dst->w60 = src->w60;
    dst->w5c = src->w5c;
    dst->w70 = src->w70;
    dst->f74 = src->f74;
    dst->f78 = src->f78;
    dst->w4 = src->w4;
    dst->w8 = src->w8;
    dst->w0 = src->w0;
    dst->w68 = 0;
    dst->w6c = src->w6c;
    dst->f24 += dst->f28 * (3.0517578125e-05f * (f32)fn_8025ECC4());
    dst->f2c += dst->f30 * (3.0517578125e-05f * (f32)fn_8025ECC4());
}

void fn_800AF780(void) {
    s32 i;
    s32 count;
    f32 *p;
    DrawStatePush(&(*(Fx*)&lbl_80303650).ds);
    if ((*(Blk*)&lbl_80303618).frame == 0) {
        fn_80226D14();
    }
    count = (*(Blk*)&lbl_80303618).n * (*(Blk*)&lbl_80303618).n * 4;
    for (i = 0; i < count; i++) {
        f32 *pt = (f32 *)((u8 *)(*(Blk*)&lbl_80303618).pts + i * 0x18);
        f32 dx = (*(Blk*)&lbl_80303618).scale * (pt[0] - 320.0f);
        f32 dy = (*(Blk*)&lbl_80303618).scale * (pt[1] - 240.0f);
        f32 d;
        dx = dx * dx;
        dy = dy * dy;
        d = dx + dy;
        if (d) {
            pt[2] = (*(Blk*)&lbl_80303618).num / d;
        } else {
            pt[2] = (*(Blk*)&lbl_80303618).num;
        }
        if (i % 4 == 3) {
            fn_80297DC8(0x1869E);
            fn_80291064((u8 *)(*(Blk*)&lbl_80303618).pts + (i - 3) * 0x18, 4, 0);
        }
    }
    (*(Blk*)&lbl_80303618).frame++;
    if ((*(Blk*)&lbl_80303618).frame >= (*(Blk*)&lbl_80303618).limit) {
        fn_800B0900();
    }
    DrawStatePop(0);
}

void fn_800B2428(Obj_800B2428 *o) {
    extern void fn_800B2334(Obj_800B2428 *o, Work *w);
    extern s32 fn_8015E600(Work *w);
    extern s32 fn_8015F218(Work *w);
    extern void fn_800B1108(Obj_800B2428 *o, Work *w);
    extern void fn_8015EBF4(Work *w);
    extern void fn_801E1784(void *p);
    extern void fn_802275A4(Hk *h, s32 a);
    extern void fn_80100B74(Obj_800B2428 *o);
    Work *w = o->work;
    if (o->flags & 0x20) {
        o->state = 0xff;
    }
    switch (o->state) {
    case 0:
        fn_800B2334(o, w);
    case 1:
        if (w->x1fb != 0) {
            w->x1fb = 0;
        }
        if (fn_8015E600(w) != 0 && fn_8015F218(w) == 1) {
            o->work->x1fa = 1;
            o->state = 2;
        } else {
            break;
        }
    case 2:
        fn_800B1108(o, w);
        break;
    case 0xff:
    case 3:
        fn_8015EBF4(w);
        if (w->x25c != NULL) {
            if (w->x25c != NULL) {
                fn_801E1784(w->x25c);
                w->x25c = NULL;
            }
        }
        if (w->x100 != NULL && w->x100->hdr->x8 != 0) {
            fn_802275A4(w->x100, 0);
        }
        fn_80100B74(o);
        break;
    case 4:
        if (w->link->cnt->count >= 0x33) {
            o->state = 0;
        }
        break;
    case 5:
        break;
    }
}

s32 fn_80097B0C(void* p)
{
    s32 a;
    s32 b;
    s32 flag;
    s32 mode;
    s32 ret;
    switch (lbl_803473F8) {
    case 0:
        fn_8028BB90(lbl_8030A318);
        DrawStateDefault(1, (*(DrawState**)&lbl_803473F0));
        (*(DrawState**)&lbl_803473F0)->attr_or |= 0x100;
        lbl_80346C70 = 1.0f;
        lbl_80346C6C = 0;
        lbl_803473F8 = 1;
        lbl_80346C50 = 0;
        /* fallthrough */
    case 1:
        DrawStatePush((*(DrawState**)&lbl_803473F0));
        fn_8022B960(lbl_8030A318);
        njPushMatrixEx();
        fn_80286EE8();
        fn_8028B498();
        njUnitMatrix(0);
        njTranslate(0, 0.0f, 0.0f, -1.0f * lbl_80345878[6]);
        njScale(0, 0.9090909f, 1.0f, 1.0f);
        fn_80299040(&lbl_80347568);
        fn_80287B38(lbl_802F60B0);
        njPopMatrixEx();
        DrawStatePop(0);
        lbl_803473F8 = 2;
        break;
    case 2:
        ret = 0;
        mode = lbl_80311AD4[6];
        flag = 0;
        if (mode == 12 || mode == 13) flag = 1;
        if (flag) a = 1;
        else a = fn_80097720();
        b = fn_80097CEC(p);
        if (a && b) ret = 1;
        return ret;
    }
    return 0;
}

Obj_800A3ED4* fn_800A3ED4(void* list, void* cb, s16 v, Src_800A3ED4* src) {
    Obj_800A3ED4* o = fn_80226704(list, cb, 0x270);
    Sub_800A3ED4* s;
    Tbl_800A3ED4* t;
    if (o == 0) {
        while (1) {
        }
    }
    o->flags |= 1;
    o->sub = (Sub_800A3ED4*)o->area;
    s = o->sub;
    s->w30 = 8;
    s->w34 = 6;
    s->w2c = 1;
    s->f190 = 1.0f;
    s->f1a8 = 0.2f;
    s->p1c8 = src;
    src->p38 = o;
    s->h178 = v;
    s->h17a = src->w4;
    s->h0 = src->w4;
    {
        f32 x = src->v44.x;
        f32 y = src->v44.y;
        f32 z = src->v44.z;
        s->v38.z = z;
        s->v38.y = y;
        s->v38.x = x;
    }
    s->w44 = (s32)(182.04445f * src->f50);
    s->w48 = (s32)(182.04445f * src->f54);
    s->w4c = (s32)(182.04445f * src->f58);
    {
        f32 x = src->v5c.x;
        f32 y = src->v5c.y;
        f32 z = src->v5c.z;
        s->v50.z = z;
        s->v50.y = y;
        s->v50.x = x;
    }
    t = src->p10;
    if (t != 0) {
        if ((t->n > 6 ? t->w[6] : 0) != 0) {
            s->w2c = 0;
        }
        s->h16e = (t->n > 7 ? t->w[7] : 0);
    }
    s->we4 = 0;
    s->w100 = 0;
    if (src != 0) {
        s->we4 = fn_800C355C(&s->w100, src, 0);
        if (src->p1c->n != 0) {
            s->we8 = src->p1c->w[0];
            if (src->p1c->n > 1) {
                s->wec = src->p1c->w[1];
            }
        }
    }
    return o;
}

void fn_800B2588(Obj_800B2588 *o)
{
    extern s32 lbl_80311AC0[5];
    extern void fn_8015ED90(void *o);
    extern void fn_8015EB8C(void *c, s32 id, void *cb);
    extern void fn_8015E600(void *c);
    extern void fn_8015EBF4(void *c);
    extern void fn_80100B74(void *o);
    extern void *fn_801094C8(u32 id);
    extern QO_800B2588 *fn_8015F1A0(u16 id);
    extern Task_800B2588 *fn_80226704(void *parent, void *cb, s32 size);
    extern void fn_800ABE9C(void);
    extern void fn_800AE300(void);
    Tbl_800B2588 *tbl;
    Ctx_800B2588 *c;
    c = o->ctx;
    tbl = c->sub->tbl;

    if (o->flags18 & 0x20) {
        o->state = 0xff;
    }
    switch (o->state) {
    case 0:
        if (c->sub->tbl->w0 < 8) {
            o->state = 4;
            break;
        }
        o->b1b = 0xfa;
        c->b26c = 1;
        fn_8015ED90(o);
        fn_8015EB8C(c, 0, fn_800ABEB0);
        fn_8015EB8C(c, 0xd, fn_800ABE9C);
        if (c->aux != 0) {
            c->aux->w1a0 = 0;
        }
        o->state = 1;
    case 1: {
        s32 ready = 0;
        if (lbl_80311AC0[1] >= 500 && lbl_80311AC0[1] < 600) {
            ready = 1;
        }
        ready = (ready != 0);
        if (ready) {
            break;
        }
        fn_8015E600(c);
        break;
    }
    case 2: {
        u32 id;
        void *ref;
        QO_800B2588 *q;
        Q_800B2588 *r;
        Col_800B2588 col;
        s32 w8;
        Task_800B2588 *n;
        fn_8015E600(c);
        id = tbl->w4;
        ref = fn_801094C8(id);
        q = fn_8015F1A0(id);
        r = q->p268;
        col.a = 0xff;
        col.r = tbl->wc;
        col.g = tbl->w10;
        col.b = tbl->w14;
        w8 = tbl->w8;
        if (r != 0) {
            r->col78 = col;
            r->flags |= 0x200;
        }
        n = fn_80226704(o, fn_800AE300, 0xb0);
        if (n != 0) {
            n->inner = (Inner_800B2588 *)((u8 *)n + 0x40);
            n->inner->p00 = ref;
            n->inner->w04 = w8;
            n->inner->w08 = 3;
            n->inner->wa8 = tbl->w18;
            n->inner->wac = tbl->w1c;
            if (n->inner->wac == 0) {
                n->inner->wac = 0xd;
            }
        }
        o->ctx->b1fb = 1;
        o->state = 1;
        break;
    }
    case 0xfe:
        break;
    case 3:
    case 0xff:
        fn_8015EBF4(c);
        fn_80100B74(o);
        break;
    case 4:
        if (c->sub->tbl->w0 >= 8) {
            o->state = 0;
        }
        break;
    }
}

typedef struct {
    s32 len;      /* 0x00 */
    s16* plist;   /* 0x04 chunk data */
    s16* offsets; /* 0x08 stream of chunk offsets and per-vertex deltas */
} ChunkSet;
typedef struct {
    u32 flags;  /* 0x00 */
    s16* plist; /* 0x04 chunk data */
} CnkModel;
typedef struct CnkObject {
    u32 flags;                /* 0x00 bit 3: no model, bit 4: no children */
    CnkModel* model;          /* 0x04 */
    u8 pad8[0x2C - 8];
    struct CnkObject* child;   /* 0x2C */
    struct CnkObject* sibling; /* 0x30 */
} CnkObject;
typedef struct {
    s32 num;          /* 0x00 */
    ChunkSet* sets;   /* 0x04 */
    CnkObject* owner; /* 0x08 */
} ChunkSetList;
extern void* fn_801E1C7C(s32 size);
extern void fn_8009D400(CnkObject* o, ChunkSet** strips, s16** out);
void* fn_8009D5BC(CnkObject* o) {
    s32 nodes;
    s32 shorts;
    ChunkSetList* h;
    ChunkSet* p;
    s16* q;
    shorts = 0;
    nodes = 0;
    fn_8009D294((Node_8009D294*)o, &nodes, &shorts);
    if (nodes == 0 || shorts == 0) return 0;
    h = fn_801E1C7C((nodes * 12 + 12) + shorts * 2);
    if (h != 0) {
        p = (ChunkSet*)(h + 1);
        q = (s16*)(p + nodes);
        h->num = nodes;
        h->sets = p;
        h->owner = o;
        fn_8009D400(o, &p, &q);
    }
    return h;
}

u8 fn_8009E49C(f32 x) {
    return __OSf32tou8(x * 255.0f);
}

void fn_800976F8(void)
{
    lbl_80346C3C = 0;
    lbl_80346750 = 1;
    lbl_802E0084.mode = -1;
    lbl_802E0084.field2 = 0;
    lbl_802E0084.flags = 0;
}

s32 fn_800A35E0(Obj_800A35E0_A *a)
{
    if (a != NULL && a->b != NULL && a->b->c != NULL) {
        switch (a->b->c->state) {
        case 1:
            return 0;
        case 2:
            return 1;
        default:
            return 2;
        }
    }
    return 2;
}

void fn_800991AC(Ent* e, s32 n) {
    Cfg* c = lbl_80346C7C;
    f32 c0 = c->f0;
    f32 c1 = c->f4;
    f32 c2 = c->f8;
    f32 c3 = c->fc;
    f32 c4 = c->f10;
    s32 i;
    s32 lim = c->lim;
    f32 ang;
    s32 ia;
    f32 r;
    f32 d;
    f32 t;
    f32 t2;
    f32 t8;
    f32 nr;
    f32 sg;
    f32 zero = 0.0f;

    for (i = 0; i < n; i++, e++) {
        if (e->wait > 0) {
            e->wait--;
        } else if (e->active != 0) {
            ia = (s32)(10430.381f * (f32)atan2(e->y, e->x));
            ang = ia;
            r = e->x / njCos((s32)ang);
            r *= 1.0f + e->fb0;
            d = r - c0;
            t = (c4 - (f32)fabs(d)) / c4;
            t2 = t * t;
            t8 = t2 * t2;
            t8 = t8 * t8;
            if (e->step < lim) {
                t2 = t2 * e->step / lim;
                t8 = t8 * e->step / lim;
                e->step++;
            }
            if (d >= 0.0f) {
                nr = r - c2 * t2;
                if (nr < c0) {
                    nr = c0;
                }
            } else {
                nr = r;
            }
            ang += c1 * t2;
            e->x = nr * njCos((s32)ang);
            e->y = nr * njSin((s32)ang);
            sg = (f32)fabs(zero);
            if (c3 < zero) {
                sg = -sg;
            }
            if (zero == c3) {
                sg = zero;
            }
            e->z += c3 * t8 + sg;
        }
    }
}

void fn_8009D994(Obj_8009D994* o, s32 idx, u32 count) {
    NJS_TEXLIST tl;
    s32 flag;
    s32 f;

    flag = o->aux != NULL ? o->aux->x1a0 : 1;
    if ((flag != 0 && o->hidden != 0) || -1.0f >= o->alpha) {
        if (o->motion != NULL) {
            o->frame += o->speed;
            if (0.0f > o->speed) {
                if (0.0f > o->frame) {
                    o->looped = 1;
                    o->frame = (f32)o->motion->nbFrame - 1.0f;
                }
            } else if (o->frame > (f32)o->motion->nbFrame - 1.0f) {
                o->looped = 1;
                o->frame = 0.0f;
            }
        } else {
            o->looped = 1;
        }
        return;
    }
    if (o->texlist != NULL) {
        tl.nbTexture = count;
        tl.textures = &o->texlist->textures[idx];
        fn_80299040(&tl);
    }
    njPushMatrixEx();
    fn_80286EE8();
    fn_8028B498();
    fn_8009D88C((void *)(o));
    njTranslateEx(&o->pos);
    njRotateEx(o->ang, 1);
    njScale(0, o->scl.x, o->scl.y, o->scl.z);
    f = o->ext->info->size > 5 ? o->ext->info->flags : 0;
    if ((f & ~0xFF) == 0) {
        o->id |= 0x5000;
    } else {
        o->id = o->ext->info->size > 5 ? o->ext->info->flags : 0;
    }
    if (o->motion != NULL) {
        fn_801E7194(o->id, o->model, o->motion, o->shape, o->frame);
        o->frame += o->speed;
        if (0.0f > o->speed) {
            if (0.0f > o->frame) {
                o->looped = 1;
                o->frame = (f32)o->motion->nbFrame - 1.0f;
            }
        } else if (o->frame > (f32)o->motion->nbFrame - 1.0f) {
            o->looped = 1;
            o->frame = 0.0f;
        }
    } else {
        fn_801E4CB0(o->id, o->model);
        o->looped = 1;
    }
    DrawStatePop(NULL);
    njPopMatrixEx();
}

Node_8009E9D8* fn_8009E9D8(Node_8009E9D8* node, s32 anim, u32 target, Out* out) {
    NJS_POINT3 pos;
    NJS_POINT3 scl;
    Angle rot[3];

    if (node != NULL) {
        njSetMatrix(0, lbl_803034D8);
        njPushMatrixEx();
        fn_80286EE8();
        fn_8028B498();
        njSetMatrix(0, lbl_80303498);
        njPushMatrixEx();
        fn_80286EE8();
        fn_8028B498();
        if (lbl_80346CFC == 0) {
            if (lbl_80346CF4 & 1) {
                if (fn_80007080(&pos, anim) == 0) {
                    pos.x = node->pos.x;
                    pos.y = node->pos.y;
                    pos.z = node->pos.z;
                }
                njTranslate(lbl_803034D8, pos.x, pos.y, pos.z);
            }
            if (lbl_80346CF4 & 2) {
                if (fn_80006F1C(rot, anim) == 0) {
                    rot[0] = node->ang[0];
                    rot[1] = node->ang[1];
                    rot[2] = node->ang[2];
                }
                njRotateXYZ(lbl_803034D8, rot[0], rot[1], rot[2]);
            }
            if (lbl_80346CF4 & 4) {
                if (fn_80006DA0(&scl, anim) == 0) {
                    scl.x = node->scl.x;
                    scl.y = node->scl.y;
                    scl.z = node->scl.z;
                }
                njScale(lbl_803034D8, scl.x, scl.y, scl.z);
            }
            if (lbl_80346CF4 & 2) {
                if (fn_80006F1C(rot, anim) == 0) {
                    rot[0] = node->ang[0];
                    rot[1] = node->ang[1];
                    rot[2] = node->ang[2];
                }
                njRotateXYZ(lbl_80303498, rot[0], rot[1], rot[2]);
            }
            fn_80006CE0();
        } else {
            if (!(node->flags & 1)) {
                njTranslate(lbl_803034D8, node->pos.x, node->pos.y, node->pos.z);
            }
            if (!(node->flags & 2)) {
                njRotateXYZ(lbl_803034D8, node->ang[0], node->ang[1], node->ang[2]);
            }
            if (!(node->flags & 4)) {
                njScale(lbl_803034D8, node->scl.x, node->scl.y, node->scl.z);
            }
            if (!(node->flags & 2)) {
                njRotateXYZ(lbl_80303498, node->ang[0], node->ang[1], node->ang[2]);
            }
        }
        if (lbl_80346CF8 == target) {
            lbl_80346D00 = node;
            njCalcPoint(lbl_803034D8, &lbl_802B0EDC, out->point);
            fn_800A1690(lbl_80303498, out->rot);
        }
        lbl_80346CF8++;
        if (lbl_80346D00 == NULL && node->child != NULL) {
            lbl_80346D00 = fn_8009E9D8(node->child, anim, target, out);
        }
        njPopMatrixEx();
        fn_80291C44(lbl_80303498);
        njPopMatrixEx();
        fn_80291C44(lbl_803034D8);
        if (lbl_80346D00 == NULL && node->sibling != NULL) {
            lbl_80346D00 = fn_8009E9D8(node->sibling, anim, target, out);
        }
    }
    return lbl_80346D00;
}

void fn_800A0BA0(Obj_800A0BA0* o, f32* m) {
    Aux_800A0BA0* aux = o->aux;
    Obj_800A0BA0* src;
    Ang3* a;
    NJS_POINT3* p;

    if (aux != NULL && aux->x4 != NULL) {
        if (fn_8015F1F0() != 0) {
            src = aux->x8;
        } else {
            src = o;
        }
        njPushMatrixEx();
        fn_80286EE8();
        fn_8028B498();
        njUnitMatrix(0);
        p = &o->outPos;
        a = &o->outAng;
        if (src->pivot != 0) {
            njTranslateEx(&src->pos);
            njRotateEx((void *)(&src->ang), 1);
            njTranslateEx(&src->pivotPos);
            njRotateEx((void *)(&src->pivotAng), 0);
            njCalcPoint(0, &lbl_802B0EAC, p);
            fn_800A1690(0, (void *)(a));
        } else {
            njTranslateEx(&src->pos);
            njRotateEx((void *)(&src->ang), 1);
            if (src->ang.z == 0 || (src->ang.x == 0 && src->ang.y == 0)) {
                *p = src->pos;
                *a = src->ang;
                if (a->x >= 0x8000) {
                    do {
                        a->x -= 0x10000;
                    } while (a->x >= 0x8000);
                } else if (a->x < -0x8000) {
                    do {
                        a->x += 0x10000;
                    } while (a->x < -0x8000);
                }
                if (a->y >= 0x8000) {
                    do {
                        a->y -= 0x10000;
                    } while (a->y >= 0x8000);
                } else if (a->y < -0x8000) {
                    do {
                        a->y += 0x10000;
                    } while (a->y < -0x8000);
                }
                if (a->z >= 0x8000) {
                    do {
                        a->z -= 0x10000;
                    } while (a->z >= 0x8000);
                } else if (a->z < -0x8000) {
                    do {
                        a->z += 0x10000;
                    } while (a->z < -0x8000);
                }
            } else {
                *p = src->pos;
                fn_800A1690(0, (void *)(a));
            }
        }
        fn_80291C44(m);
        njUnitTransPortion(m);
        njPopMatrixEx();
        o->scl = src->scl;
    }
}

void fn_800A0E1C(Obj_800A0E1C* o) {
    Ang3* a;
    Aux_800A0E1C* aux;
    Obj_800A0E1C* src;
    Tgt_800A0E1C* tgt;

    aux = o->aux;
    if (aux != NULL && (tgt = aux->x4) != NULL) {
        if (fn_8015F1F0() != 0) {
            src = aux->x8;
        } else {
            src = o;
        }
        if (src->pivot != 0) {
            njPushMatrixEx();
            fn_80286EE8();
            fn_8028B498();
            njUnitMatrix(0);
            njTranslateEx(&src->pos);
            njRotateEx((void *)(&src->ang), 1);
            njTranslateEx(&src->pivotPos);
            njRotateEx((void *)(&src->pivotAng), 0);
            njCalcPoint(0, &lbl_802B0EA0, &o->outPos);
            fn_800A1690(0, (void *)(&o->outAng));
            njPopMatrixEx();
        } else if (src->ang.z == 0 || (src->ang.x == 0 && src->ang.y == 0)) {
            o->outPos = src->pos;
            o->outAng = src->ang;
            a = &o->outAng;
            if (a->x >= 0x8000) {
                do {
                    a->x -= 0x10000;
                } while (a->x >= 0x8000);
            } else if (a->x < -0x8000) {
                do {
                    a->x += 0x10000;
                } while (a->x < -0x8000);
            }
            if (a->y >= 0x8000) {
                do {
                    a->y -= 0x10000;
                } while (a->y >= 0x8000);
            } else if (a->y < -0x8000) {
                do {
                    a->y += 0x10000;
                } while (a->y < -0x8000);
            }
            if (a->z >= 0x8000) {
                do {
                    a->z -= 0x10000;
                } while (a->z >= 0x8000);
            } else if (a->z < -0x8000) {
                do {
                    a->z += 0x10000;
                } while (a->z < -0x8000);
            }
        } else {
            njPushMatrixEx();
            fn_80286EE8();
            fn_8028B498();
            njUnitMatrix(0);
            njTranslateEx(&src->pos);
            njRotateEx((void *)(&src->ang), 1);
            o->outPos = src->pos;
            fn_800A1690(0, (void *)(&o->outAng));
            njPopMatrixEx();
        }
        tgt->x24->scl = src->scl;
    }
}

void fn_800A13D8(f32* m, Ang3* out) {
    NJS_MATRIX mat;
    NJS_MATRIX mat2;
    Pair_800A13D8 tmp;
    f32 x, y, z;
    f32 len;

    if (m != NULL) {
        fn_802AC710(mat, m, 0x40);
    } else {
        fn_80291C44(mat);
    }
    njUnitTransPortion(mat);
    njCalcVectors(mat, lbl_802B0E88, lbl_80303438.v, 2);
    x = lbl_80346784[0];
    if (fabs(x) < 1.0e-6f) {
        x = 0.0f;
    }
    y = lbl_80346784[1];
    if (fabs(y) < 1.0e-6f) {
        y = 0.0f;
    }
    z = lbl_80346784[2];
    if (fabs(z) < 1.0e-6f) {
        z = 0.0f;
    }
    len = fn_80291A5C(x * x + z * z);
    if (!x && !z) {
        out->y = 0;
    } else {
        out->y = -(s32)(10430.381f * (f32)atan2(x, z));
    }
    fn_802AC710(mat2, lbl_802B0E30, 0x40);
    njRotateY(mat2, out->y);
    njCalcPoints(mat2, lbl_80303438.v, tmp.v, 2);
    lbl_80303438 = tmp;
    out->x = (s32)(10430.381f * (f32)atan2(y, len));
    fn_802AC710(mat2, lbl_802B0E30, 0x40);
    njRotateX(mat2, out->x);
    njCalcPoints(mat2, lbl_80303438.v, tmp.v, 2);
    lbl_80303438 = tmp;
    out->z = (s32)(10430.381f * (f32)atan2(lbl_80346780[0], lbl_80346780[1]));
    out->x *= -1;
    out->y *= -1;
    out->z *= -1;
}

void fn_800A1BA4(Obj_800A1BA4* o, s32 flag, f32 z, s32 a, s32 b) {
    f32 pts[8];
    Buf buf;
    u32 cols[4];
    s16 uvs[8];
    Buf* pb = &buf;
    s16 idx;
    s32 n;
    s32 textured;
    s32 i;

    buf.p = pts;
    buf.col = cols;
    buf.uv = uvs;
    buf.count = 4;
    n = 4;
    buf.p[0] = o->v[0].x;
    buf.p[1] = o->v[0].y;
    buf.p[2] = o->v[1].x;
    buf.p[3] = o->v[1].y;
    buf.p[4] = o->v[2].x;
    buf.p[5] = o->v[2].y;
    buf.p[6] = o->v[3].x;
    buf.p[7] = o->v[3].y;
    if (flag != 0) {
        buf.count = n = 3;
    }
    for (i = 0; i < 4; i++) {
        buf.p[i * 2] = o->v[i].x;
        buf.p[i * 2 + 1] = o->v[i].y;
        buf.col[i] = o->v[i].col;
        ((u8*)buf.col)[i * 4] = (u8)(0.003921569f * (f32)(o->alpha * ((u8*)buf.col)[i * 4]));
    }
    if (o->tex != NULL) {
        idx = o->id;
        if (o->tex->nbTexture <= (u32)idx) {
            idx = o->tex->nbTexture - 1;
        }
        fn_80299040(o->tex);
        fn_80298FE4(idx);
        textured = 1;
        if (o->u < -0x100) {
            o->u = 0xFF;
        }
        if (o->u > 0xFF) {
            o->u = -0x100;
        }
        if (o->w < -0x100) {
            o->w = 0xFF;
        }
        if (o->w > 0xFF) {
            o->w = -0x100;
        }
        buf.uv[0] = o->u + 1;
        buf.uv[1] = 1 - o->w;
        buf.uv[2] = o->u + 0xFE;
        buf.uv[3] = 1 - o->w;
        buf.uv[4] = o->u + 0xFE;
        buf.uv[5] = 0xFE - o->w;
        buf.uv[6] = o->u + 1;
        buf.uv[7] = 0xFE - o->w;
    } else {
        textured = 0;
    }
    z = fn_801DBD9C(z);
    fn_801CCD90(pb, n, textured, o->tex, idx, z, b == 1 ? a : 0);
}

void fn_800AE000(Obj_800AE000* o) {
    Work_800AE000* w = o->work;
    switch (o->state) {
    case 0:
    case 0xfe:
        w->b26c = 1;
        w->h170 = 0;
        w->b1fb = 0;
        fn_8015ED90((void *)(o));
        if (w->cfg->p10->n < 10) {
            o->state = 4;
            break;
        }
        o->state = 1;
    case 1:
        fn_8015E600(w);
        if (w->b1fb != 0) {
            if (w->f24c > 0.0f) {
                fn_800972AC();
                w->h170 = 0;
                w->f24c = 0.0f;
            }
            w->b1fb = 0;
        }
        break;
    case 2: {
        Tbl2_800AE000* t;
        s32 n;
        fn_8015E600(w);
        t = w->cfg->p1c;
        n = t->n;
        if ((n > 0 ? t->w[0] : 0) == 0 || (n > 1 ? t->w[1] : 0) == 0) {
            o->state = 1;
            break;
        }
        switch (w->h170) {
        case 0: {
            Work_800AE000* p = fn_8015F180(w);
            f32 f = *(f32*)((u8*)p->cfg->p10 + 0x24);
            Item_800AE000* a;
            Item_800AE000* b;
            u32 x, y, z;
            fn_80097294(7);
            fn_800970D8(w->h17a, 0, f);
            fn_800970B4(w->h17a, 1, f);
            t = w->cfg->p1c;
            a = t->n > 0 ? t->w[0] : 0;
            x = a->w4;
            b = t->n > 1 ? t->w[1] : 0;
            y = b->w4;
            z = (s32)p->cfg->p10->n > 9 ? p->cfg->p10->w[9] : 0;
            w->f24c = (f32)z;
            {
                f32 m = x > y ? (f32)x * f : (f32)y * f;
                w->f24c += m;
            }
            w->h170 = 1;
            break;
        }
        case 1:
            w->f24c -= 1.0f;
            if (w->f24c <= 0.0f) {
                fn_800972AC();
                w->h170 = 0;
                o->state = 1;
                w->b1fb = 0;
            }
            break;
        }
        break;
    }
    case 3:
    case 0xff:
        fn_8015EBF4(w);
        fn_80100B74((void *)(o));
        break;
    case 4:
        if (w->cfg->p10->n >= 10) o->state = 1;
        break;
    }
}

void fn_80097388(Camera *cam) {
    if (cam->ret_mode >= 15) {
        fn_801DBE1C("ERROR(retC): NO RETURN CAMERA MODE");
    }
    cam->mode = cam->ret_mode;
    if (cam->mode != 0 && cam->mode != 7) {
        cam->flags = cam->ret_flags;
        cam->xe6 = cam->ret_e6;
        cam->pos[0] = cam->ret_pos[0];
        cam->pos[1] = cam->ret_pos[1];
        cam->pos[2] = cam->ret_pos[2];
        cam->tgt[0] = cam->ret_tgt[0];
        cam->tgt[1] = cam->ret_tgt[1];
        cam->tgt[2] = cam->ret_tgt[2];
        cam->roll = cam->ret_roll;
        cam->v58[0] = cam->ret_v58[0];
        cam->v58[1] = cam->ret_v58[1];
        cam->v58[2] = cam->ret_v58[2];
        cam->v58[3] = cam->ret_v58[3];
        cam->v58[4] = cam->ret_v58[4];
        cam->v58[5] = cam->ret_v58[5];
        cam->ang[0] = cam->ret_ang[0];
        cam->ang[1] = cam->ret_ang[1];
        cam->ang[2] = cam->ret_ang[2];
        fn_801DD334(&cam->dir, &cam->up, cam->ret_rot);
        cam->fd4 = cam->ret_d4;
        cam->xd8 = cam->ret_d8;
        cam->x104 = cam->x100 = cam->ret_100;
        cam->fd0 = cam->ret_d0;
    } else {
        cam->mode = 0;
    }
    cam->flags |= 4;
}

s32 fn_8009877C(Owner_8009877C *o, s32 id)
{
    Node_8009877C *n = lbl_80346CB0;
    s32 count;
    SrcRec *src;
    s32 i;
    SrcHdr *h;

    o->id = id;
    h = *o->data;
    count = h->count;
    src = h->recs;
    for (i = 0; i < count; i++, n++, src++) {
        memset(n, 0, sizeof(Node_8009877C));
        n->used = 1;
        n->src = src;
        n->v[0] = src->v[0];
        n->v[1] = src->v[1];
        n->v[2] = src->v[2];
        n->v[3] = src->v[3];
        n->v[4] = src->v[4];
        n->v[5] = src->v[5];
        DCStoreRange(n, sizeof(Node_8009877C));
    }
    o->count = count;
    o->nodes = lbl_80346CB0;
    lbl_80346CB0 = n;
    return count;
}

void fn_80099078(Node_80099078 *n, s32 count)
{
    s32 i;
    s32 k;
    Axis *a;
    f32 *o;

    for (i = 0; i < count; i++, n++) {
        if (n->delay > 0) {
            n->delay--;
        } else if (n->used != 0) {
            o = n->ofs;
            a = n->axis;
            for (k = 0; k < 8; k++, a++, o++) {
                if (a->on != 0) {
                    a->val += a->spd;
                    *o += a->val;
                    if (a->lim && (f32)fabs(a->val) >= a->lim) {
                        a->spd *= 0.5;
                    }
                }
            }
        }
    }
}

s32 fn_8009B3F4(Obj_8009B3F4 *o)
{
    Track *t;
    Key *k;
    s32 ret = 1;

    o->leaf->val[0] += (o->target[0] - o->leaf->val[0]) / (f32)o->timer[0];
    o->timer[0]--;
    if (o->timer[0] <= 0) {
        t = o->track[0];
        k = t->keys;
        o->idx[0]++;
        if (t->count <= o->idx[0]) {
            if (!(t->flags & 1)) {
                o->idx[0] = t->count - 1;
                ret = 0;
            } else {
                o->idx[0] = 0;
            }
        }
        k += o->idx[0];
        o->timer[0] = k->time;
        o->target[0] = k->val;
    }
    return ret;
}

s32 fn_8009B4C0(Obj_8009B4C0 *o)
{
    Track *t;
    Key *k;
    s32 ret = 1;

    o->leaf->val[1] += (o->target[1] - o->leaf->val[1]) / (f32)o->timer[1];
    o->timer[1]--;
    if (o->timer[1] <= 0) {
        t = o->track[1];
        k = t->keys;
        o->idx[1]++;
        if (t->count <= o->idx[1]) {
            if (!(t->flags & 1)) {
                o->idx[1] = t->count - 1;
                ret = 0;
            } else {
                o->idx[1] = 0;
            }
        }
        k += o->idx[1];
        o->timer[1] = k->time;
        o->target[1] = k->val;
    }
    return ret;
}

void fn_800A1998(NJS_POINT3 *from, NJS_POINT3 *to, Ang3_800A1998 *out, s8 mode, u8 flags) {
    NJS_POINT3 d;
    Ang3_800A1998 ang;

    d.x = to->x - from->x;
    d.y = to->y - from->y;
    d.z = to->z - from->z;
    switch (mode) {
    case 1:
        njPushMatrixEx();
        fn_80286EE8();
        fn_8028B498();
        njUnitMatrix(0);
        njTranslateEx((void *)(&d));
        fn_800A1690(0, (void *)(&ang));
        njPopMatrixEx();
        break;
    case 2:
        njPushMatrixEx();
        fn_80286EE8();
        fn_8028B498();
        njUnitMatrix(0);
        njTranslateEx((void *)(&d));
        fn_800A13D8(0, (void *)(&ang));
        njPopMatrixEx();
        break;
    case 0:
    default:
        fn_802135B4(&d, &ang);
        break;
    }
    if (flags & 1) {
        out->x = ang.x;
    }
    if (flags & 2) {
        out->y = ang.y;
    }
    if (flags & 4) {
        out->z = ang.z;
    }
}

void fn_800A1690(f32* m, Ang3* out) {
    NJS_MATRIX mat;
    NJS_MATRIX mat2;
    Pair_800A1690 tmp;
    f32 x, y, z;
    f32 len;

    if (m != NULL) {
        fn_802AC710(mat, m, 0x40);
    } else {
        fn_80291C44(mat);
    }
    njUnitTransPortion(mat);
    njCalcVectors(mat, lbl_802B0E70, lbl_80303450.v, 2);
    x = lbl_80346778[0];
    if (fabs(x) < 1.0e-6f) {
        x = 0.0f;
    }
    y = lbl_80346778[1];
    if (fabs(y) < 1.0e-6f) {
        y = 0.0f;
    }
    z = lbl_80346778[2];
    if (fabs(z) < 1.0e-6f) {
        z = 0.0f;
    }
    len = fn_80291A5C(x * x + y * y);
    if (!x && !y) {
        out->z = 0;
    } else {
        out->z = -(s32)(10430.381f * (f32)atan2(y, x));
    }
    fn_802AC710(mat2, lbl_802B0E30, 0x40);
    njRotateZ(mat2, out->z);
    njCalcPoints(mat2, lbl_80303450.v, tmp.v, 2);
    lbl_80303450 = tmp;
    out->y = (s32)(10430.381f * (f32)atan2(z, len));
    fn_802AC710(mat2, lbl_802B0E30, 0x40);
    njRotateY(mat2, out->y);
    njCalcPoints(mat2, lbl_80303450.v, tmp.v, 2);
    lbl_80303450 = tmp;
    out->x = (s32)(10430.381f * (f32)atan2(lbl_8034677C[1], lbl_8034677C[2]));
    out->x *= -1;
    out->y *= -1;
    out->z *= -1;
}

f32 fn_8009E4B8(u8 b) {
    f32 f = __OSu8tof32(&b);
    f *= 0.003921569f;
    return f;
}

/* (1 + x) * 255 to a u8 through the SDK fast cast. The constants must be literals: as
 * extern sdata2 labels the stwu is scheduled first. */
u8 fn_8009E4D4(f32 x) {
    return __OSf32tou8((1.0f + x) * 255.0f);
}

void fn_8009884C(Ent_8009884C* e, s32 n, f32* v) {
    NJS_POINT3 vec;
    NJS_POINT3 out;
    f32 y;
    f32 zero;
    f32 xy;
    f32 x;
    f32 sgn;
    s32 i;
    x = v[0];
    y = v[1];
    sgn = 1.0f;
    zero = 0.0f;
    if (y < zero) {
        sgn = -1.0f;
        y = -y;
    }
    if (x != zero) {
        vec.x = 0.0f;
        vec.y = 0.0f;
        vec.z = y;
    }
    xy = y * x;
    for (i = 0; i < n; i++, e++) {
        Angle a2;
        Angle a1;
        f32 d;
        e->h0 = 1;
        a1 = (s32)(10430.381f * (f32)atan2(e->f90, e->f8c));
        a2 = (s32)(10430.381f * (f32)atan2(e->f8c / njCos(a1), x));
        d = x / njCos(a2);
        njPushMatrixEx();
        fn_80286EE8();
        fn_8028B498();
        njUnitMatrix(0);
        vec.z = xy / d;
        njRotateXYZ(0, 0, a2, a1);
        njCalcPoint(0, &vec, &out);
        njPopMatrixEx();
        e->f14 = e->f14 + out.x;
        e->f24 = e->f24 + out.y;
        e->f34 = out.z * sgn + e->f34;
        e->w0c = 1;
        e->w1c = 1;
        e->w2c = 1;
        e->f54 = 100.0f * out.x * sgn + e->f54;
        e->f50 = out.x * sgn + e->f50;
        e->w4c = 1;
        e->f44 = e->f44 - 100.0f * out.y * sgn;
        e->f40 = e->f40 - out.y * sgn;
        e->w3c = 1;
    }
}

static inline s32 Has(Work_800AE300 *w, s32 v)
{
    s32 k = w->n;
    for (;;) {
        k--;
        if (k < 0) {
            return 0;
        }
        if (v == w->list[k]) {
            return 1;
        }
    }
}

void fn_800AE300(Obj_800AE300 *o)
{
    Work_800AE300 *w;
    w = o->work;
    if ((o->ref->flags18 & 0x40) || (w->ref->flags18 & 0x40)) {
        o->flags18 |= 0x40;
        return;
    }
    switch (o->state) {
    case 0:
        fn_800B2DC0(w->ref->p24, w->w04, w->wa8, w->wac, 1.0f);
        w->list[w->n++] = w->w04;
        o->state++;
        break;
    case 1: {
        s32 i, j, n;
        s32 buf[6];
        n = w->n;
        for (i = 0; i < n; i++) {
            fn_800AE4E0(w->list[i], buf);
            for (j = 0; j < 6; j++) {
                if (!Has(w, buf[j])) {
                    fn_800B2DC0(w->ref->p24, buf[j], w->wa8, w->wac, 0.25f * (f32)w->w08);
                    w->list[w->n++] = buf[j];
                }
            }
        }
        o->state++;
        break;
    }
    case 2:
        w->w08--;
        if (w->w08 != 0) {
            o->state = 1;
        } else {
            o->flags18 |= 0x40;
        }
        break;
    }
}

/* |d| */
static inline f32 Abs(f32 d) {
    if (d < 0.0f) {
        d = -d;
    }
    return d;
}

/* distance on a wrapping axis of length lim */
static inline f32 Fold(f32 d, f32 lim) {
    if (d < lim - d) {
        return d;
    }
    return lim - d;
}

void fn_8009CBBC(void) {
    Tab_8009CBBC* t = &lbl_802E0E18;
    u32 id = fn_80218DC4();
    s32 i;
    f32* ta;
    f32* tb;
    f32* tc;
    f32* td;
    f32* te;
    f32* tf;
    f32 dx;
    f32 dz;
    f32 v;
    if (id != 0xFFFFFFFF && !(lbl_80310B3C.flags & 0x40000)) {
        ta = t->a;
        tb = t->b;
        tc = t->c;
        td = t->d;
        te = t->e;
        tf = t->f;
        for (i = 0; i < 6; i++) {
            dx = Abs(lbl_80347450->x - ta[i]);
            dz = Abs(lbl_80347450->z - tb[i]);
            dx = Fold(dx, 16800.0f);
            dz = Fold(dz, 14400.0f);
            if (dx > tc[i] || dz > td[i]) {
                v = 0.0f;
            } else if (dx < te[i]) {
                if (dz < tf[i]) {
                    v = 1.0f;
                } else {
                    v = 1.0f - (dz - tf[i]) / tf[i];
                }
            } else if (dz < tf[i]) {
                v = 1.0f - (dx - te[i]) / te[i];
            } else {
                f32 p = (dx - te[i]) / te[i];
                f32 q = (dz - tf[i]) / tf[i];
                v = 1.0f - ((p > q) ? p : q);
            }
            sndSeqSetMidiCtrl(id, i + 10, 7, (s32)(127.0f * v));
        }
    }
}
