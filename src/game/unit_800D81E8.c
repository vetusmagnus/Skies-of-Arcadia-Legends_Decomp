#include "game/save_8030B7F4.h"
#include "types.h"
#include "game/work_8030CEA0.h"
#include <string.h>
#include "game/util.h"
#include "ninja.h"
#include "game/drawstate.h"
#include <math.h>
#include "game/menu.h"
#include <dolphin/os/OSFastCast.h>
#include "game/task.h"
#include "game/evobj.h"
#include "game/sprite.h"
#include "game/uiobj.h"
#include "game/text.h"
extern void fn_80226D14(void);
extern void fn_80226BD0(f32 a, f32 b);
typedef struct {
    u8 pad[0x198];
    s32 looped;
} LoopObj;
typedef struct {
    u8 pad[0x18C];
    f32 frame;
    f32 speed;
    u8 pad194[4];
    s32 looped;
} AnimObj;
extern void fn_800DF74C(void* p, void* data);
extern char lbl_802B1718[];
typedef struct {
    u8 pad[0x110];
    s32 tgt[3];
} TgtObj;
typedef struct {
    u8 pad0[4];
    u32 id;
    u8 rest[0x60];
} TblEntry;
typedef struct {
    s32 count;
    TblEntry* entries;
} Tbl_UNIT0000;
typedef struct {
    u8 pad[4];
    s32 idx;
} IdxObj;
typedef struct {
    u8 pad0[0xE8];
    void* motion;
    u8 pad1[0x18C - 0xEC];
    f32 frame;
    f32 speed;
} MotObj;
typedef struct {
    u8 pad[0x24];
    MotObj* dst;
} MotCtx;
extern s32 lbl_80346DB0;
extern u32 lbl_803473A4;
extern u32 lbl_80346DB8;
extern u32 lbl_80346DB4;
extern s32 lbl_80311AD4[11];
extern s32 lbl_80346E48;
extern f32 lbl_80305C68[4];
extern s16 lbl_80346E64;
extern void (*lbl_80347490)(s32 a);
extern u32 lbl_8034748C;
extern u16 lbl_80347458;
extern u32 lbl_80346DD0;
extern u32 lbl_80346DD4;
extern u8 *lbl_80346E3C;
extern s32 lbl_80346E38;
extern s32 lbl_8034757C;
extern void fn_801CC434(const void* p, s32 zero, void* out);
extern void fn_80109A94(const char *name);
extern void fn_800D2CA8(s32 x);
extern void fn_80100E68(void* p, s32 zero, s32 a, s32 b);
extern void fn_801E17E0(void* p);
extern void *fn_801E1C7C(u32 size);
extern s32 fn_800F7D6C(EvObj *e);
extern s32 fn_801D6E38(s32 a);
extern void fn_801E1AC8(u16 a, char b, s32 c, s32 d);
typedef struct {
    u32 a;
    u32 b;
    u32 c;      /* only the high half is compared */
} Key;
typedef struct Ent_800E0470 {
    u8 pad0[0x190];
    f32 f190;
    u32 u194;
    u32 u198;
} Ent_800E0470;
extern f32 lbl_803496AC;
extern s32 fn_801C6068(void* p, s32 n);
extern f32 fn_801C5D04(void* p, s32 n);
typedef struct Src_800E04E0 {
    u8 pad0[4];
    u32 u4;
} Src_800E04E0;
typedef struct Ent_800E04E0 {
    u8 pad0[0xe8];
    Src_800E04E0* pe8;
    u8 padec[0x18c - 0xec];
    f32 f18c;
    f32 f190;
    u8 pad194[4];
    u32 u198;
} Ent_800E04E0;
extern f32 lbl_80349698;
typedef struct Ent_800E0540 {
    u8 pad0[0x190];
    f32 f190;
    u32 u194;
    u32 u198;
} Ent_800E0540;
typedef struct Mid {
    u8 pad0[8];
    u32 u8;
} Mid;
typedef struct Aux {
    u8 pad0[0x1c];
    Mid* m1c;
} Aux;
typedef struct Ent_800E05AC {
    u8 pad0[0xec];
    u32 uec;
    u8 padf0[0x18c - 0xf0];
    f32 f18c;
    f32 f190;
    u8 pad194[4];
    u32 u198;
    u8 pad19c[0x1c8 - 0x19c];
    Aux* p1c8;
} Ent_800E05AC;
extern s32 fn_801C5F40(void* p, s32 n);
typedef struct Ctx_800EDF38 {
    u8 pad0[0x19];
    u8 f19;
    u8 pad1a[0x24 - 0x1a];
    void* p24;
} Ctx_800EDF38;
extern void* lbl_803475A0;
extern Ctx_800EDF38* lbl_80346E18;
typedef struct {
    u8 pad00[0x04];
    struct {
        u8 pad[0x20];
        void* texlist;
    }* inner;
} MapRes;
extern MapRes* lbl_80346E10;
extern void* fn_802267AC(void* a, void *);
extern void fn_800EDB70(void);
extern u32 lbl_8030A3C8[3];
extern void fn_800D2C44(u16 n);
typedef struct Rec {
    u32 u0;
    u32 u4;
    void* p8;
} Rec;
extern Rec* fn_80109404();
extern void* fn_80109D74(void* p);
extern void* fn_801C6180(void* a);
typedef struct {
    u32 count;
    u32 d4;
} Sub_80100BF8;
typedef struct {
    u8 pad0[4];
    s32 f4;
    u8 pad8[0x2c - 8];
    s32 f2c;
    u8 pad30[0xe4 - 0x30];
    s32 fe4;
    s32 fe8;
    u8 pad_ec[0x100 - 0xec];
    s32 f100;
    u8 pad104[0x16e - 0x104];
    s16 f16e;
    u8 pad170[0x176 - 0x170];
    u16 f176;
    s16 f178;
    s16 f17a;
    s32 f17c;
    u8 pad180[0x1c8 - 0x180];
    void* f1c8;
} Data_80100BF8;
typedef struct {
    s32 kind;
    u8 pad4[0x14];
    s32 f18;
    u32 f1c;
    s32 f20;
} Opt_80100BF8;
typedef struct {
    u8 pad0[4];
    s32 f4;
    u8 pad8[8];
    Opt_80100BF8* f10;
    u8 pad14[8];
    Sub_80100BF8* f1c;
    u8 pad20[0x38 - 0x20];
    void* f38;
    s8 f3c;
    u8 pad3d[3];
    f32 f40;
    f32 f44;
    f32 f48;
    f32 f4c;
    f32 f50;
    f32 f54;
    f32 f58;
    f32 f5c;
    f32 f60;
    f32 f64;
} Inf_80100BF8;
typedef struct {
    void* fn;
    u8 pad4[0x20];
    Data_80100BF8* d;
} Task_80100BF8;
extern void fn_8008F760(void* o);
extern u32 fn_8008F980(void);
extern s32 fn_800C355C(void* p, Inf_80100BF8* inf, s32 a);
extern void fn_80222C80(Inf_80100BF8* inf, Data_80100BF8* d);
extern void fn_80129814(Task_80100BF8* t);
Task_80100BF8* fn_80100BF8(Task_80100BF8* o, u32 id, u32 infw);
typedef struct Obj_801090A8 {
    u8 pad0[0x19];
    u8 state;
} Obj_801090A8;
extern s32 fog_enabled;
typedef struct Cnt_8010B038 {
    s32 count;
    s32 pad4[3];
    s32 w10;
    s32 w14;
} Cnt_8010B038;
typedef struct Cfg_8010B038 {
    u8 pad0[0x10];
    Cnt_8010B038 *cnt;
} Cfg_8010B038;
typedef struct Sub_8010B038 {
    u8 pad0[0x100];
    NJS_TEXLIST *p100;
    u8 pad_104[0x170 - 0x104];
    s16 h170;
    s16 h172;
    u8 pad_174[0x176 - 0x174];
    u16 h176;
    u8 pad_178[0x17A - 0x178];
    u16 h17a;
    u8 pad_17c[0x18C - 0x17C];
    f32 pos;
    f32 speed;
    u8 pad_194[0x1C8 - 0x194];
    Cfg_8010B038 *p1c8;
} Sub_8010B038;
typedef struct Obj_8010B038 {
    u8 pad0[0x19];
    u8 state;
    u8 pad_1a[0x20 - 0x1A];
    f32 f20;
    Sub_8010B038 *sub;
} Obj_8010B038;
extern f32 lbl_80346788;
extern f32 lbl_8034678C;
extern f32 lbl_80347560;
extern void ClipZPush(void);
extern void ClipZPop(void);
extern void njClipZ(f32 near, f32 far);
extern s32 fn_8010ABD4();
extern void fn_80100B74(void *p);
extern void fn_800D2B1C(void* p);
extern s32 fn_801E1098(void* a, void* b);
typedef struct Ent_80109468 {
    u8 pad0[4];
    u32 key;
    u8 pad8[0x38 - 8];
    u32 v38;
    u8 pad3c[0x68 - 0x3c];
} Ent_80109468;
typedef struct Set_80109468 {
    s32 count;
    Ent_80109468* ent;
} Set_80109468;
typedef struct Out_80109468 {
    Set_80109468* s;
    Ent_80109468* e;
    u32 v;
} Out_80109468;
typedef struct Node_801094C8 {
    u8 pad0[4];
    Set_80109468* data;
    u8 pad8[0x30 - 8];
    struct Node_801094C8* next;
} Node_801094C8;
extern s32 fn_80109468(u32 key, Set_80109468* s, Out_80109468* out);
typedef struct Src_8010AB60 {
    u8 pad0[0x38];
    f32 f38;
    f32 f3c;
    f32 f40;
    u32 u44;
    u32 u48;
    u32 u4c;
    u8 pad50[0xe8 - 0x50];
    u32 ue8;
    u8 padec[0x18c - 0xec];
    f32 f18c;
    f32 f190;
} Src_8010AB60;
typedef struct Ent_8010AB60 {
    u8 pad0[0xe8];
    u32 ue8;
    u8 padec[0x18c - 0xec];
    f32 f18c;
    f32 f190;
    u8 pad194[0x20c - 0x194];
    u32 u20c;
    u32 u210;
    u32 u214;
    u8 pad218[0x24c - 0x218];
    f32 f24c;
    f32 f250;
    f32 f254;
} Ent_8010AB60;
typedef struct Ctx_8010AB60 {
    u8 pad0[0x24];
    Ent_8010AB60* dst;
} Ctx_8010AB60;
typedef struct Tp {
    u8 pad0[0x24];
    void* p24;
} Tp;
extern s32 lbl_80346E60;
extern void* lbl_80347590;
extern void fn_8010D4F4(void);
extern void fn_802260E8(void* p);
typedef struct Sub_UNIT0000 {
    u8 pad0[0x100];
    void* p100;
    u8 pad104[0x170 - 0x104];
    s16 s170;
    s16 s172;
} Sub_UNIT0000;
typedef struct Obj_8010DE84_UNIT0000 {
    u8 pad0[0x19];
    u8 st;
    u8 pad1a[0x24 - 0x1a];
    Sub_UNIT0000* p24;
} Obj_8010DE84_UNIT0000;
extern void fn_8010DDBC(void* o);
extern s32 lbl_803473DC;
extern s32 lbl_803473E4;
extern s32 lbl_80347444;
extern s32 lbl_803473E8;
extern void *lbl_80346D98;
extern void *lbl_803475A0;
typedef struct {
    u8 pad0[0x24];
    void *p24;
} Task_UNIT0000;
void *fn_80227E84(s32 size);
s32 fn_800FF48C(void *a, s32 b);
void *fn_80226704(void *list, void *cb, s32 size);
void fn_800D81E8(void);
struct T;
void fn_800D8214(struct T *t);
typedef struct {
    u8 pad0[0x8];
    u32 w8;
    void *sub;
} K06Obj_800DE2E4;
typedef struct {
    u8 pad0[0x1c];
    s32 f1c;
    s32 f20;
} K06Sub_800DE2E4;
typedef struct K06Mid_800E082C {
    u8 pad0[0x10];
    struct K06Leaf_800E082C *leaf;
} K06Mid_800E082C;
typedef struct K06Leaf_800E082C {
    u8 pad0[0x28];
    u32 v28;
} K06Leaf_800E082C;
typedef struct K06Obj_800E082C {
    u8 pad0[0x114];
    s32 f114;
    u8 pad1[0x164 - 0x118];
    f32 f164;
    u8 pad2[0x1c8 - 0x168];
    K06Mid_800E082C *p1c8;
    u8 pad3[0x254 - 0x1cc];
    f32 f254;
} K06Obj_800E082C;
s32 fn_801C6068(void* p, s32 n);
typedef struct K06Leaf_800E08C8 {
    u8 pad0[0x2c];
    s32 v2c;
} K06Leaf_800E08C8;
typedef struct K06Mid_800E08C8 {
    u8 pad0[0x10];
    K06Leaf_800E08C8 *leaf;
    u8 pad1[0x54 - 0x14];
    f32 f54;
} K06Mid_800E08C8;
typedef struct K06Obj_800E08C8 {
    u8 pad0[0x48];
    s32 f48;
    u8 pad1[0x114 - 0x4c];
    s32 f114;
    u8 pad2[0x1c8 - 0x118];
    K06Mid_800E08C8 *p1c8;
} K06Obj_800E08C8;
s32 fn_801C60A4(void *p);
typedef struct K06Leaf_800E09A0 {
    u8 pad0[0x28];
    u32 v28;
    s32 v2c;
} K06Leaf_800E09A0;
typedef struct K06Mid_800E09A0 {
    u8 pad0[0x10];
    K06Leaf_800E09A0 *leaf;
} K06Mid_800E09A0;
typedef struct K06Obj_800E09A0 {
    u8 pad0[0x114];
    s32 f114;
    u8 pad1[0x164 - 0x118];
    f32 f164;
    u8 pad2[0x1c8 - 0x168];
    K06Mid_800E09A0 *p1c8;
    u8 pad3[0x254 - 0x1cc];
    f32 f254;
} K06Obj_800E09A0;
typedef struct K06Ctx_800E2924 {
    u8 pad0[0x20];
    NJS_TEXLIST *p20;
} K06Ctx_800E2924;
typedef struct K06Obj_800E2924 {
    u8 pad0[0x24];
    struct K06Obj_800E2924 *next;
    u8 pad1[0x1c8 - 0x28];
    K06Ctx_800E2924 *p1c8;
    u8 pad2[0x20c - 0x1cc];
    s32 f20c;
    s32 f210;
    u8 pad3[0x260 - 0x214];
    u32 f260;
} K06Obj_800E2924;
extern char lbl_802B19D4[];
extern u16 lbl_80346DC0;
void * fn_801094C8(u32 key);
void fn_801DBE1C(const char *fmt, ...);
void fn_800E1A58(K06Obj_800E2924 *p);
void fn_80297CC0(s32 a, s32 b, s32 c, s32 d);
typedef struct K06Obj_800EC3EC {
    u8 pad0[0x38];
    f32 f38;
    u8 pad1[0x40 - 0x3c];
    f32 f40;
} K06Obj_800EC3EC;
extern f32 lbl_802E3CB0[];
extern f32 lbl_802E3CD0[];
typedef struct K06A {
    u8 pad0[0x8];
    u32 flags;
    u8 pad1[0x14 - 0xc];
    s16 s14;
    s16 s16v;
} K06A;
extern K06A *lbl_80311A60[6];
typedef struct K06Blk {
    s32 count;
} K06Blk;
typedef struct K06Sub_800F1598 {
    u8 pad0[0x10];
    K06Blk *blk;
} K06Sub_800F1598;
typedef struct K06Obj_800F1598 {
    u8 pad0[0x1c8];
    K06Sub_800F1598 *sub;
} K06Obj_800F1598;
typedef struct K06Ent {
    s16 id;
    s16 ty;
} K06Ent;
s32 fn_800F13F0(K06Obj_800F1598 *p, s16 ty, s16 id, void *data);
void *fn_800D5184(void *e, s16 n);
typedef struct K06Rec {
    Sprite spr;
    f32 f1c;
    f32 f20;
    f32 f24;
    s32 kind;
} K06Rec;
extern s32 lbl_803475D8;
extern s32 lbl_80346E30;
extern K06Rec *lbl_80346E34;
void *memcpy(void *dst, const void *src, u32 n);
extern char lbl_802B2348[];
extern char lbl_80305CF0[];
extern s32 lbl_80311AD4[];
extern s32 lbl_80347464;
void fn_800FF908(void);
void fn_801F7B04(s32 a);
extern char lbl_802B23B8[];
void GXInvalidateTexAll(void);
void fn_801CC434(const void* p, s32 zero, void* out);
s32 fn_80109E7C(void *a, u16 b);
typedef struct K06Obj_8010085C K06Obj_8010085C;
typedef struct K06Sub_8010085C {
    u8 pad0[0x38];
    K06Obj_8010085C *p38;
    u8 b3c;
} K06Sub_8010085C;
typedef struct K06Ctx_8010085C {
    u8 pad0[0x1bc];
    void *p1bc;
    u8 pad1[0x1c8 - 0x1c0];
    K06Sub_8010085C *p1c8;
} K06Ctx_8010085C;
struct K06Obj_8010085C {
    u8 pad0[0x19];
    u8 st;
    u8 pad1[0x24 - 0x1a];
    K06Ctx_8010085C *ctx;
};
void fn_80222964(void *p);
void fn_801E1784(void *p);
void fn_801E6744(void *p);
void fn_801C6170(void *p);
typedef struct K06Obj_80100AA4 K06Obj_80100AA4;
typedef struct K06Sub_80100AA4 {
    u8 pad0[0x38];
    K06Obj_80100AA4 *p38;
    u8 b3c;
} K06Sub_80100AA4;
typedef struct K06Ctx_80100AA4 {
    u8 pad0[0x1bc];
    void *p1bc;
    u8 pad1[0x1c8 - 0x1c0];
    K06Sub_80100AA4 *p1c8;
} K06Ctx_80100AA4;
struct K06Obj_80100AA4 {
    u8 pad0[0x19];
    u8 st;
    u8 pad1[0x24 - 0x1a];
    K06Ctx_80100AA4 *ctx;
};
extern s32 lbl_80346E44;
extern u32 lbl_803473CC;
extern u8 lbl_802E46E0[];
f32 njScalor(f32 *v);
void njUnitVector(f32 *v);
f32 njInnerProduct(f32 *a, f32 *b);
extern s32 fn_801C6068(void* p, s32 n);
extern void fn_801C6170(void *p);
extern u8 *lbl_80346E58;
extern void fn_801E17E0(void* p);
extern void fn_8014912C(void);
extern s32 lbl_8034745C;
extern void *fn_801E1A74(s32 a, u32 b);
extern u16 TextReadChar(const u8 **pp);
extern s8 lbl_802E4C70[];
extern void fn_8010C0E4(struct Obj_8010C0E4 *obj, struct Src_8010C0E4 *n);
typedef struct {
    f32 x, y, z;
    u32 colour;
} VertexCol;
typedef VertexCol Quad;
extern f32 fn_801DBD9C(f32 v);
extern void fn_80290ED4(Quad *q, s32 n, s32 m);
typedef struct {
    u32 pad0;
    u32 code; /* 0x04 */
} Code1c8;
typedef struct {
    u8 pad0[0x1c8];
    Code1c8* info; /* 0x1c8 */
} Obj_800DE440;
extern s32 fn_801C60A4(void *p);
extern void* fn_800CCA6C(s32 a, s32 b);
typedef struct {
    u8 pad0[0x1c8];
    Code1c8* info; /* 0x1c8 */
} Obj_800E0B08;
extern void njPushMatrixEx(void);
extern void njPopMatrixEx(void);
extern void fn_80286EE8(void);
extern void fn_8028B498(void);
extern void njProjectScreen(void* m, NJS_VECTOR* p, f32* out);
typedef struct {
    u8 pad0[8];
    s8 step;  /* 0x08 */
    u8 pad9[3];
    f32 x;    /* 0x0C */
    f32 y;    /* 0x10 */
} Ui178C;
typedef struct {
    u8 pad0[0x38];
    NJS_VECTOR pos; /* 0x38 */
    u8 pad44[0x258 - 0x44];
    f32 fade;       /* 0x258 */
} Tgt178C;
typedef struct {
    s32 count;      /* 0x00 */
    u8 pad4[0x28];
    u32 w;          /* 0x2C */
    u32 h;          /* 0x30 */
} Size340C;
typedef struct {
    u8 pad0[0x10];
    Size340C* size; /* 0x10 */
    u8 pad14[0xc];
    void* tex;      /* 0x20 */
} Info340C;
typedef struct {
    u8 pad0[0x1c8];
    Info340C* info; /* 0x1C8 */
} Obj340C;
extern void fn_801E4FD4(Obj340C* o);
extern void fn_80291428(s32 a);
extern void fn_802913E8(s32 a, s32 b);
extern f32 fn_801DBD9C(f32 v);
extern void fn_802911CC(f32* v);
extern void fn_80291424(void);
/* The battle result screen's work (lbl_80346DCC; fn_800E4644 is its state machine). */
typedef struct {           /* 0x18 */
    s16 flags;   /* 0x00 */
    u8 pad2[2];
    u32 c4;      /* 0x04 */
    u32 c8;      /* 0x08 */
    u32 cc;      /* 0x0C */
    s16 h10;     /* 0x10 */
    s16 h12;     /* 0x12 */
    s16 h14;     /* 0x14 */
    s16 h16;     /* 0x16 */
} ResSpr;
typedef struct {           /* 0x6C */
    UiObj o;
    u8 pad4c[0x20];
} ResPanel;
typedef struct {           /* 0x0C */
    u8 pad0[4];
    s16 id;      /* 0x04 */
    s16 arg;     /* 0x06 */
    s16 flags;   /* 0x08 */
    s16 ha;      /* 0x0A */
} ResEv;
typedef struct {           /* 0x14 */
    s16 sel;     /* 0x00 */
    s8 on[6];    /* 0x02 */
    s16 slot[6]; /* 0x08 */
} ResMem;
typedef struct {           /* 0x42 */
    u8 b0;       /* 0x00 */
    u8 pad1;
    u8 b2;       /* 0x02 */
    u8 pad3[0x14];
    u8 b17;      /* 0x17 */
    u8 pad18[0x2a];
} ResRow;
typedef struct {           /* 0x6E */
    s16 h[2];    /* 0x00 indexed by ResSwap.sel */
    u8 pad4[4];
    s8 b8;       /* 0x08 */
    u8 b9[99];   /* 0x09 */
    u8 b6c[2];   /* 0x6C indexed by ResSwap.sel */
} ResStat;
typedef struct {           /* 0x04 */
    s16 h;       /* 0x00 item id, < 0 for none */
    s8 n;        /* 0x02 count */
    u8 pad3;
} ResItem;
typedef struct {           /* 0x0C, one per party member */
    s8 chr;      /* 0x00 character (lbl_8030B7F4.chr index) */
    u8 level;    /* 0x01 */
    u8 pad2[10];
} ResMember;
typedef struct {           /* 0x14, one per party member */
    s16 sel;     /* 0x00 which of the two slots is shown */
    s8 moving;   /* 0x02 */
    u8 pad3;
    s16 obj[2];  /* 0x04 */
    s16 spr[2];  /* 0x08 */
    f32 x[2];    /* 0x0C */
} ResSwap;
typedef struct {
    u32 w0;              /* 0x00 */
    u32 state;           /* 0x04 */
    u32 w8;              /* 0x08 */
    s32 count;           /* 0x0C */
    s32 w10;             /* 0x10 */
    s32 w14;             /* 0x14 */
    s32 total;           /* 0x18 */
    s32 w1c;             /* 0x1C */
    s32 w20;             /* 0x20 */
    s32 cur;             /* 0x24 */
    ResItem h28[3];      /* 0x28 */
    s8 b34[4];           /* 0x34 */
    s8 b38[4];           /* 0x38 */
    u8 pad3c[4];
    s32 timer;           /* 0x40 */
    s32 w44;             /* 0x44 */
    s32 w48;             /* 0x48 */
    f32 fade;            /* 0x4C */
    ResMember member[4]; /* 0x50 */
    u8 pad80[0x140];
    ResRow row[4];       /* 0x1C0 */
    ResMem mem[4];       /* 0x2C8 */
    f32 z318[4];         /* 0x318 per-member draw z */
    u8 pad328[0x20];
    f32 x348[4];         /* 0x348 */
    f32 x358[4];         /* 0x358 */
    u8 pad368[4];
    f32 z36c;            /* 0x36C draw z */
    ResSpr spr[22];      /* 0x370 */
    ResPanel obj[22];    /* 0x580 */
    ResStat stat[4];     /* 0xEC8 */
    ResSwap swap[4];     /* 0x1080 */
    u8 pad10d0[0x420];
    s16 evIdx;           /* 0x14F0 */
    s16 h14f2;           /* 0x14F2 */
    u8 pad14f4[0x44];
    ResEv ev[16];        /* 0x1538 */
    u8 sub[0x14];        /* 0x15F8 */
    s32 active;          /* 0x160C */
} Ctx3594;
extern Ctx3594* lbl_80346DCC;
extern s32 lbl_80346DC8;
extern u8 lbl_802B1B20[0x14];
extern void fn_800E36F8(void);
extern void fn_801D6B58(void* a, void* b);
extern void fn_80217800(s32 a);
extern s32 fn_80218570(s32 a, s32 b, s32 c);
extern void fn_800E4644(void);
extern void fn_801D68DC(void* a);
extern void fn_80217830(s32 a);
extern void fn_801E17E0(void* p);
typedef struct {
    u8 pad0[0x19];
    u8 state;  /* 0x19 */
    u8 pad1a[10];
    void* sub; /* 0x24 */
} Task460;
typedef struct {
    u8 pad0[8];
    u32 flags; /* 0x08 */
} Pad460;
extern s32 lbl_80346DD8;
extern s32 lbl_80346EB4;
extern void fn_8015ED90(void *p);
extern s32 fn_8015E600(void *p);
extern void fn_801D77B8(void);
extern s32 fn_801D1504(void);
extern void fn_801CBBAC(f32 f);
extern void fn_80216D14(s32 a);
extern void fn_80217CB0(void);
extern void fn_800FF9FC(void);
extern void fn_8015EBF4(void *p);
extern f32 lbl_802E725C[7];
extern f32 lbl_802E72AC[7];
extern f32 lbl_802E72FC[7];
extern f32 lbl_802E734C[7];
extern f32 lbl_802E739C[7];
typedef struct {
    s32 area;            /* 0x00 */
    u8 pad4[8];
    s32 f0c;
    s32 f10;
    u8 pad14[0x38 - 0x14];
    s16 level;           /* 0x38 */
    u8 pad3a[0x4c - 0x3a];
    f32 v4c, v50, v54, v58, v5c;
    f32 v60, v64, v68, v6c, v70;
    u8 tile[12][14][4];  /* 0x74 */
    u8 active[29];       /* 0x314 */
    u8 pad331[0xDF8 - 0x331];
    void* bank;          /* 0xDF8 */
} Game6E14;
typedef Game6E14 K06B;
typedef Game6E14 Cfg;
extern f32 lbl_802E3EF0[3][29][2];
extern u32 lbl_80310B3C[0x356];
extern Game6E14* lbl_80346E14;
typedef struct {
    s32 count;
    f32 pts[1][2];
} PtList;
typedef struct {
    u8 pad0[0x20c];
    s32 frames;     /* 0x20C */
    u8 pad210[0x25c - 0x210];
    void* h;        /* 0x25C */
    PtList* cur;    /* 0x260 */
    PtList* target; /* 0x264 */
} Obj0C68;
extern void fn_801DEDC0(void* h, f32* pts, s32 n);
typedef struct {
    s32 a;
    s32 b;
} Pair0EF4;
typedef struct {
    u8 pad0[0x100];
    Pair0EF4* p100;   /* 0x100 */
    u8 pad104[0x188 - 0x104];
    u32 flags;        /* 0x188 */
    u8 pad18c[0x24c - 0x18c];
    f32 pos;          /* 0x24C */
    f32 vel;          /* 0x250 */
    u8 pad254[0x25c - 0x254];
    void* h;          /* 0x25C */
    u8 pad260[0x268 - 0x260];
    s32* src;         /* 0x268 */
} Obj0EF4;
extern void fn_801DE9BC(void* h, f32 f);
extern s32 fn_800F0C68(Obj0C68* o);
extern void fn_801DE8C0(Obj0EF4* o, void* h);
typedef struct {
    u8 b0, b1, b2, b3;
    s16 s4;
    s16 s6;
    f32 f8;
    f32 fc;
    u16 s10;
    u16 s12;
    f32 f14;
    f32 f18;
} Src1010;
typedef struct {
    s32 a, b, c;
} Vec3i;
typedef struct {
    s32 pad0;
    s32 v4;
} Pos1010;
typedef struct {
    u8 pad0[0x5c];
    f32 f5c;
    u8 pad60[0x100 - 0x60];
    Pos1010* p100;   /* 0x100 */
    u8 pad104[0x158 - 0x104];
    u8 sub158[0xc];  /* 0x158 */
    f32 f164;        /* 0x164 */
    u8 pad168[0x180 - 0x168];
    s32 v180;        /* 0x180 */
    u8 pad184[4];
    u32 flags;       /* 0x188 */
    u8 pad18c[0x1fc - 0x18c];
    s16 s1fc, s1fe, s200, s202;
    u8 pad204[2];
    s16 s206, s208;
    u8 pad20a[0x254 - 0x20a];
    f32 f254, f258;
    u8 pad25c[0x268 - 0x25c];
    Pos1010* p268;   /* 0x268 */
} Obj1010;
extern void fn_801DD460(void* dst, Vec3i* v);
typedef struct {
    f32 x, y, z;
    f32 a, b;
} Pt1644;
typedef struct {
    s16 count;
    s16 type;
    Pt1644 pts[3];
} Path1644;
typedef struct {
    u8 pad0[0x44];
    f32 dir[3];      /* 0x44 */
    u8 pad50[0x25c - 0x50];
    void* h;         /* 0x25C */
} Obj1644;
extern void fn_801DCEB0(f32* out, f32* in, f32 scale);
extern void* fn_801DF450(Path1644* p, s32 a);
typedef struct {
    u32 w[1];
} Tbl_800FE254;
typedef struct {
    u8 pad0[0x10];
    u32* tbl;
} Info;
typedef struct {
    u8 pad0[0x1c8];
    Info* info;  /* 0x1C8 */
    u8 pad1cc[0x210 - 0x1cc];
    s32 cur;     /* 0x210 */
    s32 flip;    /* 0x214 */
    s32 idx;     /* 0x218 */
} Obj_800FE254;
typedef K06Rec Item;
extern u8* lbl_80346E3C;
extern void fn_8011D548(void);
extern void CampPanelDrawFrame(void* p);
extern void fn_801D4F0C(Sprite* it, s32 a, s32 b, s32 c, f32 f1, f32 f2, f32 f3, f32 f4);
extern void fn_801D4C54(Sprite* it, s32 a, s32 b, s32 c, f32 f1, f32 f2, f32 f3, f32 f4);
extern void fn_801D52A8(Sprite* it, s32 a, s32 b, f32 f1, f32 f2, f32 f3, f32 f4);
extern EvObj* lbl_80347450;
extern s32 lbl_803474B0[2];
extern s16 lbl_803474AC[2];
extern f32 lbl_8030A77C[6];
extern s32 lbl_8030A764[6];
extern s32 lbl_80347470;
extern s32 lbl_803475D4;
extern f32 lbl_80347488;
extern char lbl_80305CF0[0x20];
extern void fn_801DBE1C(const char* fmt, ...);
extern void fn_800FF908(void);
extern void fn_801F7B04(s32 a);
extern void fn_801004C4(void* a, void* b);
typedef struct {
    s32 map;
    s32 w4;
    char room;
    u8 pad9[3];
    void *p0c;
    void *p10;
} MapInfo_80100178;
extern MapInfo_80100178 lbl_80311AC0;
extern void fn_801DBE1C(const char *fmt, ...);
extern void fn_801004C4(void *a, void *b);
typedef struct {
    u8 pad0[0x100];
    void *p100;
    u8 pad104[0x1bc - 0x104];
    void *p1bc;
    u8 pad1c0[0x1c8 - 0x1c0];
    u8 *p1c8;
} Inner;
typedef struct {
    u8 pad0[0x19];
    u8 state;
    u8 pad1a[0x24 - 0x1a];
    Inner *inner;
} Obj_80100768;
extern void fn_801E671C(Inner *p);
extern void fn_80222964(void *p);
extern void fn_801E1784(void *p);
extern void fn_801C6170(void *p);
extern u8 lbl_8030A5D4[0x100];
extern void *lbl_8034749C;
extern void *lbl_80346E4C;
extern u8 lbl_803474EC[8];
extern void fn_80169294(void);
extern void fn_800E3544(void);
extern void fn_80192800(void);
extern void fn_80230F24(void);
extern void fn_80123EB0(void);
extern void fn_801CBBF8(void);
extern void fn_801DDCA8(void *p);
extern void fn_80109B8C(struct Set_80109B8C *p);
extern void fn_800C23CC(void);
extern void fn_801F72F8(void);
extern void fn_80216CD8(void);
extern void fn_80109868(void);
extern void fn_801CAE8C(void);
extern void fn_800CD11C(void);
extern void fn_80225EDC(void);
extern void fn_801DB9B4(void);
extern void fn_802280D4(void);
extern s32 lbl_803473EC;
extern s32 lbl_80347440;
extern s8 lbl_80310A1C[0x120];
extern char *lbl_8034746C;
extern u8 lbl_8030A4D4[0x100];
extern u8 lbl_8030A3D4[0x100];
extern char lbl_802B2364[];
extern void fn_80225FDC(void);
extern void fn_801DDD74(void *p, s32 n);
extern void fn_800CD1F0(s32 n);
extern void *fn_8010CEF8(void);
extern void fn_80123EE4(void);
extern void CampMenuCreate(void);
extern void fn_800E3554(void);
extern void OSGetTick(void);
extern void fn_8025ECBC(void);
extern void fn_801DA1C0(void);
extern void fn_80118540(void);
extern void fn_801CBC30(void);
extern void fn_801195E4(void);
extern void sprintf(char *dst, const char *fmt, ...);
extern void fn_800972C4(void);
extern void fn_801F7958(void);
extern void fn_801F7158(void *p);
extern void fn_800C24CC(void);
extern DrawState lbl_8030A3A0;
extern s32 lbl_803475B0;
extern s32 lbl_80347280;
extern u8 lbl_8030A794[0xCC0];
extern s32 lbl_803473A8;
extern s32 lbl_803472E4;
extern u8 *lbl_80347468;
extern s32 fn_800C8D90(void);
extern void fn_801E1D30(void);
extern void fn_80226120(void);
extern void fn_801DBA0C(void);
extern void fn_8022DCC4(void);
extern void fn_800D3464(void);
extern void fn_80227068(s32 n);
extern void fn_80226EFC(void);
extern void fn_80097CDC(void);
extern void TextReset(void);
extern void fn_801E74D0(void);
extern void fn_80109A4C(void);
extern void fn_8008F9A8(void);
extern void fn_801692F8(void);
extern void fn_801C86D8(void);
extern s32 lbl_80347474;
extern void fn_8022697C(s32 n);
extern void fn_80101158(void);
extern void fn_8012A26C(void);
extern void fn_8022642C(void);
extern void fn_801E1CCC(void);
extern void fn_801DBE6C(s32 n);
extern f32 fn_80291978(f32 x);
extern s32 fn_801C6068(void* p, s32 n);
extern f32 fn_801C5C80(void *obj, s32 n);
typedef struct Unit_80104B70 Unit_80104B70;
typedef struct {
    u8 pad0[0x1c];
    f32 f1c;
} Sub_80104B70;
struct Unit_80104B70 {
    u8 pad0[0x1c];
    f32 f1c;
    u8 pad20[0x38 - 0x20];
    f32 x, y, z;
    u8 pad44[0x50 - 0x44];
    f32 rx, ry, rz;
    f32 vx, vy, vz;
    u8 pad64[0x11c - 0x68];
    f32 vrx, vry, vrz;
    u8 pad128[0x21d - 0x128];
    u8 b21d;
    u8 b21e;
    u8 pad21f[0x250 - 0x21f];
    f32 f250;
};
typedef struct {
    u8 pad0[0x24];
    Sub_80104B70 *sub;
} Other_80104B70;
extern f32 fn_801C60C8(f32 a, f32 b);
extern s32 fn_800D2924(void *p);
extern void fn_801E5608(void *o, s32 a, s32 b);
typedef struct Unit_80105058 {
    u8 pad0[0x1c];
    f32 f1c;
    u8 pad20[0x38 - 0x20];
    NJS_POINT3 pos;
    u8 pad44[0x100 - 0x44];
    void *p100;
    u8 pad104[0x20c - 0x104];
    s32 s20c;
} Unit_80105058;
typedef struct Parent {
    u8 pad0[0x24];
    struct Parent2 *p24;
} Parent;
typedef struct Parent2 {
    u8 pad0[0x25c];
    s32 *p25c;
} Parent2;
typedef struct Task_80105058 {
    u8 pad0[8];
    Parent *parent;
    u8 pad0c[0x19 - 0xc];
    u8 state;
    u8 pad1a[6];
    f32 f20;
    Unit_80105058 *unit;
} Task_80105058;
extern void fn_80104D64(void*u);
extern void fn_80104B70(Unit_80104B70 *u, Other_80104B70 *o);
extern s32 fn_801C5FFC(void*u);
typedef struct {
    u8 pad0[0x1c];
    f32 f1c;
    u8 pad20[0x168 - 0x20];
    s16 state;
    u8 pad16a[0x1ef - 0x16a];
    s8 b1ef;
    s8 b1f0;
    s8 b1f1;
} Unit_801051A0;
extern void* fn_800DE440(Obj_800DE440* o);
extern void fn_800DE2E4(K06Obj_800DE2E4 *p, u8 *a, u8 *b, s8 *c);
extern s32 fn_800E0B08(Obj_800E0B08* o, s32 limit);
extern s32 fn_800DE228(void *p, f32 f);
typedef struct Unit_80107B18 {
    u8 pad0[0x74];
    s16 s74;
    u8 pad76[0x100 - 0x76];
    void *p100;
    u8 pad104[0x16e - 0x104];
    s16 s16e;
} Unit_80107B18;
typedef struct Task_80107B18 {
    u8 pad0[0x19];
    u8 state;
    u8 pad1a[0x24 - 0x1a];
    Unit_80107B18 *unit;
} Task_80107B18;
extern void fn_801173DC(s32 a, void*u);
extern void fn_8015C8B8(void*u, s32 n);
extern s32 fn_8015E600(void* p);
extern void fn_801E5DF0(void*u);
extern void fn_8015EBF4(void* p);
typedef struct {
    u8 pad0[0x17a];
    u16 id;
} Target;
typedef struct {
    u8 pad0[0x17a];
    u16 id;
} Self24;
typedef struct Node_80108CC4 {
    u8 pad0[8];
    u32 id;
} Node_80108CC4;
typedef struct {
    u8 pad0[0x17a];
    u16 id;
    u8 pad17c[0x1bc - 0x17c];
    void *list;
} Work;
typedef struct {
    u8 pad0[0x19];
    u8 state;
    u8 pad1a[0x24 - 0x1a];
    Work *work;
} Task_80108CC4;
extern void*fn_8022300C(void *list);
extern void*fn_80222F14(void *list, void*n);
extern void fn_80210550(s32 id);
typedef struct Entry {
    s32 id;            /* 0x00 */
    u32 ptr;           /* 0x04 */
    void *p8;          /* 0x08 */
    char name[0x20];   /* 0x0C */
    void *owner;       /* 0x2C */
    struct Entry *next; /* 0x30 */
} Entry;
extern Entry *lbl_80347460;
extern Entry * fn_801096FC(void *owner, s32 id, u32 ptr, const char *name);
extern void fn_801CC434(const void* p, s32 zero, void* out);
extern s32 fn_8025EF88(const char *a, const char *b);
extern s32 fn_801E1098(void* a, void* b);
extern void fn_80109B8C(struct Set_80109B8C *p);
extern void fn_801CC0E4(void *p);
typedef struct Unit_8010A740 {
    u8 pad0[0x18c];
    f32 f18c;
    f32 f190;
} Unit_8010A740;
typedef struct Unit2 {
    u8 pad0[0x170];
    s16 s170;
    s16 s172;
    u8 pad174[0x18c - 0x174];
    f32 f18c;
    f32 f190;
} Unit2;
typedef struct Task_8010A740 {
    u8 pad0[0x19];
    u8 state;
    u8 pad1a[0x24 - 0x1a];
    Unit2 *unit;
} Task_8010A740;
extern void fn_8015EB8C(void *p, s32 id, void *cb);
extern s32 fn_8010A530(MotCtx* ctx, MotObj* src);
extern void fn_8015C8B8(void*u, s32 n);
extern s32 fn_8015E600(void* p);
extern s32 fn_800D2924(void*u);
extern void fn_80167690(Unit2 *u);
extern void fn_8015EBF4(void* p);
typedef struct Node_8010B68C {
    struct Node_8010B68C *next; /* 0x00 */
    u32 *flag;         /* 0x04 */
    u8 pad8[0x14 - 0x8];
    u16 kind;          /* 0x14 */
    u8 pad16[2];
    s16 cost;          /* 0x18 */
} Node_8010B68C;
typedef struct Queue_8010B68C {
    u8 pad0[0x36];
    s16 total;  /* 0x36 */
    u8 pad38[0x3e - 0x38];
    s16 count;  /* 0x3e */
    Node_8010B68C *head; /* 0x40 */
} Queue_8010B68C;
typedef struct Node_8010B78C {
    struct Node_8010B78C *next; /* 0x00 */
    u32 *flag;         /* 0x04 */
} Node_8010B78C;
typedef struct Queue_8010B78C {
    s16 s0;       /* 0x00 */
    s16 s2;
    f32 f4;
    u8 pad8[0x10 - 0x8];
    s16 s10;
    s16 s12;
    s16 s14;
    s16 s16;
    u8 pad18[0x30 - 0x18];
    s16 s30;
    s16 s32;
    u8 pad34[2];
    s16 total;    /* 0x36 */
    s16 s38;
    s16 s3a;
    s16 s3c;
    s16 count;    /* 0x3e */
    Node_8010B78C *head;   /* 0x40 */
    Node_8010B78C *tail;   /* 0x44 */
    u32 color;    /* 0x48 */
    f32 f4c;
    f32 f50;
    s16 s54;
    u8 b56;
} Queue_8010B78C;
typedef struct Seg {
    struct Seg* next;  /* 0x00 */
    u32 pad04;
    u32 w08;
    f32 f0c;
    f32 f10;
    u16 u14;
    s16 s16_;
    s16 chars;
    char text[1];
} Seg;
typedef struct {
    u8 pad[0x36];
    s16 nseg;
} Ctx;
extern u16 TextReadChar(const u8** pp);
extern Seg* fn_8010B88C(Ctx* ctx, s32 n);
extern void* memcpy(void* dst, const void* src, u32 n);
typedef struct {
    u16 flags;  /* 0x00 */
    u8 pad02[0x0A];
    u32 colour; /* 0x0C */
    u8 pad10[2];
    s16 y;      /* 0x12 */
} FadeObj;
extern void fn_8010C87C(f32 x, f32 y, f32 w, f32 h, f32 z, u32 colour);
extern void fn_8010C7A0(f32 a, f32 b, f32 c, f32 d, f32 e, u32 id);
typedef struct {
    NJS_POINT3 a;
    NJS_POINT3 b;
    u8 pad[0x38 - 0x18];
} Obj;
typedef struct {
    u8 pad[0x38];
    NJS_POINT3 pos;
} Target_800E1894;
extern void njSubVector(NJS_POINT3* a, NJS_POINT3* b);
extern s32 fn_801DD4C4(f32 x, f32 z);
extern s32 fn_801DD544(NJS_POINT3* v);
typedef struct {
    u8 pad0[0x24];
    void* dst;
} Slot;
typedef struct {
    u8 pad0[0x180];
    s32 timer;
    u8 pad184[4];
    u32 flags;
    u8 pad18c[0x1fc - 0x18c];
    s16 s1fc, s1fe, s200, s202, s204, s206;
} Obj_800F0D5C;
typedef struct { u8 pad0[4]; u32 count; } Model;
typedef struct { u8 pad0[0x24]; void* a; void* b; } Sub1bc;
typedef struct { u8 pad0[0x24]; } Info_8010092C;
typedef struct {
    u8 pad0[0xb4];
    f32 b4, b8, bc;
    f32 c0, c4, c8;
    u8 padcc[0xe8 - 0xcc];
    Model* model;
    u8 pade8[0x16c - 0xec];
    s16 s16c;
    u8 pad16e[0x18c - 0x16e];
    f32 f18c;
    u8 pad190[0x1bc - 0x190];
    Sub1bc* sub;
    u8 pad1c0[0x1c8 - 0x1c0];
    u8* p1c8;
} Ent;
typedef struct {
    u8 pad0[0x19];
    u8 mode;
    u8 pad1a[0x24 - 0x1a];
    Ent* ent;
} Obj_8010092C;
typedef struct { u8 pad0[0x24]; u32 count; } T10;
typedef struct { u8 pad0[0x10]; T10* t; u8 pad14[0x44 - 0x14]; NJS_POINT3 p44; } P1c8;
typedef struct {
    u8 pad0[0x38];
    NJS_POINT3 pos;
    u8 pad44[0x1c8 - 0x44];
    P1c8* p1c8;
} Ent_80103140;
typedef struct {
    u8 pad0[0x25c];
    u32* arr;
} Q;
typedef struct {
    u8 pad0[0x24];
    Q* q;
} P;
typedef struct {
    u8 pad0[0x38];
    f32 x, y, z;
    u8 pad44[0x5c - 0x44];
    f32 vx, vy, vz;
    u8 pad68[0x100 - 0x68];
    void* h100;
    u8 pad104[0x22c - 0x104];
    u16 idx;
    u8 pad22e[0x24c - 0x22e];
    f32 lim;
} Ent_801034BC;
typedef struct {
    u8 pad0[8];
    P* p8;
    u8 pad_c[0x19 - 0xc];
    u8 mode;
    u8 pad1a[0x24 - 0x1a];
    Ent_801034BC* ent;
} Obj_801034BC;
typedef struct { u8 pad0[0x50]; s32 w50; } T10_80105660;
typedef struct { u8 pad0[0x10]; T10_80105660* t; } P1c8_80105660;
typedef struct { u8 pad0[8]; s32 w8; } P1b0;
typedef struct {
    u8 pad0[0xe8];
    void* e8;
    u8 pade8[0x180 - 0xec];
    s32 w180;
    u8 pad184[0x190 - 0x184];
    f32 f190;
    u8 pad194[4];
    s32 w198;
    u8 pad19c[0x1b0 - 0x19c];
    P1b0* p1b0;
    u8 pad1b4[0x1c8 - 0x1b4];
    P1c8_80105660* p1c8;
} Obj_80105660;
typedef struct {
    s32 a;   /* 0 */
    s32 b;   /* 4 */
    s32 c;   /* 8 */
    s32 d;   /* 0xC */
} SeqEnt;
typedef struct {
    s32 pad0;
    s32 pad4;
    s32 count;      /* 8 */
    SeqEnt ent[1];  /* 0xC */
} SeqTbl;
typedef struct {
    u8 pad0[0xe8];
    struct { s32 p0; u32 len; } *anim; /* 0xE8 */
    u8 pad_ec[0x180 - 0xec];
    s32 timer;      /* 0x180 */
    u8 pad184[0x18c - 0x184];
    f32 f18c;
    f32 f190;
    u8 pad194[4];
    s32 state;      /* 0x198 */
    u8 pad19c[0x20c - 0x19c];
    s32 idx;        /* 0x20C */
    s32 cnt;        /* 0x210 */
    u8 pad214[0x23c - 0x214];
    s32 state3;     /* 0x23C */
    u8 pad240[0x24c - 0x240];
    f32 f24c;
    u8 pad250[0x25c - 0x250];
    SeqTbl *tbl;    /* 0x25C */
} Obj_80107C24;
extern void fn_801E735C(s32 a, Obj_80107C24 *o, f32 f);
typedef struct {
    s32 count;      /* 0 */
    u8 pad4[0x24 - 4];
    s32 f24;
    s32 f28;
} Info_80108388;
typedef struct {
    u8 pad0[0x10];
    Info_80108388 *info;
} Sub_80108388;
typedef struct {
    u8 pad0[0x17a];
    u16 f17a;
    u8 pad17c[0x18c - 0x17c];
    f32 f18c;
    f32 f190;
    u8 pad194[4];
    s32 state;      /* 0x198 */
    u8 pad19c[0x1c8 - 0x19c];
    Sub_80108388 *sub;       /* 0x1C8 */
    u8 pad1cc[0x20c - 0x1cc];
    s32 idx;        /* 0x20C */
    u8 pad210[0x24c - 0x210];
    f32 f24c;
} Obj_80108388;
typedef struct {
    s32 count;      /* 0 */
    u8 pad4[0x24 - 4];
    s32 f24;
} Info_80108698;
typedef struct {
    u8 pad0[0x10];
    Info_80108698 *info;
} Sub_80108698;
typedef struct {
    s32 pad0;
    u32 len;
} Anim;
typedef struct {
    u8 pad0[4];
    s32 f4;
    u8 pad8[0xb4 - 8];
    f32 f_b4;
    f32 f_b8;
    f32 f_bc;
    f32 f_c0[3];
    u8 padcc[0xe8 - 0xcc];
    Anim *anim;     /* 0xE8 */
    u8 padec[0x16c - 0xec];
    s16 f16c;
    u8 pad16e[0x18c - 0x16e];
    f32 f18c;
    f32 f190;
    u8 pad194[0x1c8 - 0x194];
    Sub_80108698 *sub;       /* 0x1C8 */
} Obj_80108698;
typedef struct {
    u8 pad0[0x19];
    u8 f19;
    u8 pad1a[0x24 - 0x1a];
    Obj_80108698 *obj;   /* 0x24 */
} Parent_80108698;
typedef struct {
    s32 count;      /* 0 */
    s32 f4;
    s32 f8;
} InfoA;
typedef struct {
    s32 count;      /* 0 */
    u8 pad4[0x10 - 4];
    s32 f10;
    u8 pad14[0x24 - 0x14];
    u32 f24;
} InfoB;
typedef struct {
    u8 pad0[0x10];
    InfoB *infob;
    u8 pad14[0x1c - 0x14];
    InfoA *infoa;   /* 0x1C */
} Sub;
typedef struct {
    u8 pad0[0xe8];
    s32 fe8;
    s32 fec;
    u8 padf0[0x100 - 0xf0];
    void *f100;
    u8 pad104[0x190 - 0x104];
    f32 f190;
    u8 pad194[0x1c8 - 0x194];
    Sub *sub;       /* 0x1C8 */
} Obj_80108828;
typedef struct {
    u8 pad0[0x19];
    u8 f19;
    u8 pad1a[6];
    f32 f20;
    Obj_80108828 *obj;   /* 0x24 */
} Parent_80108828;
typedef struct {
    s32 pad0;
    s32 pad4;
    s32 pad8;
} Z;
typedef struct {
    u8 pad0[0x24];
    f32 *pos;   /* 0x24 */
    f32 *rot;   /* 0x28 */
} Attach;
typedef struct {
    s32 pad0;
    s32 f4;
} Res4;
typedef struct {
    struct { u8 pad0[8]; void *f8; } *f0;
    s32 f4;
} Res;
typedef struct { f32 x, y, z; } Vec3;
typedef struct Obj_8010AE90 {
    u8 pad0[0x38];
    Vec3 f38;
    Vec3 f44;
    u8 pad50[0xb4 - 0x50];
    f32 fb4[3];
    f32 fc0[3];
    u8 padcc[0x100 - 0xcc];
    Res *res;       /* 0x100 */
    u8 pad104[0x170 - 0x104];
    s16 f170;
    s16 f172;
    u8 pad174[0x18c - 0x174];
    f32 f18c;
    f32 f190;
    u8 pad194[0x1bc - 0x194];
    Attach *attach; /* 0x1BC */
    u8 pad1c0[0x20c - 0x1c0];
    Vec3 f20c;
    u8 pad218[0x24c - 0x218];
    Vec3 f24c;
} Obj_8010AE90;
typedef struct {
    u8 pad0[0x19];
    u8 f19;
    u8 pad1a[0x24 - 0x1a];
    Obj_8010AE90 *obj;   /* 0x24 */
} Parent_8010AE90;
typedef struct {
    u8 pad0[0x1c];
    f32 f1c;
    u8 pad20[0x18c - 0x20];
    f32 f18c;
    f32 f190;
    u8 pad194[4];
    s32 state;      /* 0x198 */
    u8 pad19c[0x24c - 0x19c];
    f32 f24c;
    f32 f250;
    f32 f254;
    f32 f258;
} Obj_8010DEE8;
typedef struct {
    u8 pad0[0x19];
    u8 f19;
    u8 pad1a[6];
    f32 f20;
    Obj_8010DEE8 *obj;   /* 0x24 */
} Parent_8010DEE8;
typedef struct {
    u8 pad0[6];
    u16 flags;
    u8 pad8[0x1C - 8];
    void* p1c;
    u8 pad20[4];
    void* p24;
    u8 pad28[0x30 - 0x28];
    f32 v[3];
    u8 pad3c[0x48 - 0x3C];
} Hnd_800D99B4;
typedef struct {
    s32 count;
    s32 id;
} Lst_800D99B4;
typedef struct {
    u8 pad0[4];
    u32 id;
    u8 pad8[8];
    Lst_800D99B4* c10;
} Src_800D99B4;
typedef struct {
    u8 pad0[0x38];
    f32 pos[3];
    f32 rot[3];
    u8 pad50[0xE4 - 0x50];
    void* e4;
    u8 pade8[0x1B4 - 0xE8];
    Hnd_800D99B4* h1b4;
    u8 pad1b8[0x1C8 - 0x1B8];
    Src_800D99B4* p1c8;
    u8 pad1cc[0x25C - 0x1CC];
    void* p25c;
} Work_800D99B4;
typedef struct {
    u8 pad0[0x19];
    u8 state;
    u8 pad1a[0x24 - 0x1A];
    Work_800D99B4* work;
} Obj_800D99B4;
extern s32 fn_800C3518(void* w);
extern Hnd_800D99B4* fn_80225B74(s32 mask, u16 id);
extern void fn_802233EC(void* h);
extern void fn_802234D4(void* h);
extern void fn_80223628(void* a, void* b, void* c);
extern s32 fn_800D2924(void* w);
extern void fn_801E5DF0(void* w);
extern void fn_800C3428(void* o);
typedef struct {
    s32 x, y, z;
} IVec_800D9BA0;
typedef struct {
    f32 x, y, z;
} Vec_800D9BA0;
extern void fn_80090B68(IVec_800D9BA0* k, Vec_800D9BA0* v);
extern void fn_80090BE4(f32* p, IVec_800D9BA0* k);
extern void fn_80090A7C(f32* p, Vec_800D9BA0* v);
extern s32 fn_800E126C(void* w);
typedef struct {
    u8 pad0[0x20];
    s32 v20;
} Lim_800DE00C;
typedef struct {
    u8 pad0[0x1C];
    f32 f1c;
    u8 pad20[0x38 - 0x20];
    f32 x;
    f32 y;
    f32 z;
    u8 pad44[0x100 - 0x44];
    s32 s100;
    u8 pad104[0x1C8 - 0x104];
    Lim_800DE00C* p1c8;
} Work_800DE00C;
typedef struct {
    u8 pad0[0x19];
    u8 state;
    u8 pad1a[0x24 - 0x1A];
    Work_800DE00C* work;
} Obj_800DE00C;
typedef struct {
    u32 flags;
    u8 pad04[0x34 - 4];
    f32 x, y;      /* 0x34 */
    u8 pad3c[0x50 - 0x3c];
} Obj50;
/* A 2D sprite descriptor (fn_801D7A90; as in unit_801D24D0.c). */
typedef struct {
    u16 enable;    /* 0x00 */
    u8 pad02[6];
    f32 z;         /* 0x08 */
    f32 colour;    /* 0x0C */
    u32 attr;      /* 0x10 */
    u32 blend;     /* 0x14 */
    f32 ca, cb;    /* 0x18 */
    u8 pad20[4];
    u32 col;       /* 0x24 */
    u8 pad28[0x34 - 0x28];
    f32 x, y;      /* 0x34 */
    f32 w, h;      /* 0x3C */
    f32 ox, oy;    /* 0x44 */
} Desc;
/* lbl_80346DF0 (the board's sprites, inside the board work at 0x10). */
typedef struct {
    Desc bg;           /* 0x000 */
    Desc cursor;       /* 0x04C */
    Desc cursor2;      /* 0x098 */
    Desc piece[10];    /* 0x0E4 */
    Desc frame;        /* 0x3DC */
    Desc slot[10];     /* 0x428 */
    Desc cell[8][9];   /* 0x720 */
} Board;
typedef struct {
    u8 on;
    u8 pad1[3];
} Mark;
/* The board screen's work (lbl_80346DF4). */
typedef struct {
    s32 first;         /* 0x00 */
    u8 pad4[6];
    s16 active;        /* 0x0A */
    s16 mode;          /* 0x0C */
    u8 padE[2];
    Board board;       /* 0x10 */
    u8 pad1c90[8];
    Obj50 base;        /* 0x1C98: the board's offset */
    Obj50 cursor;      /* 0x1CE8 */
    Obj50 slot[10];    /* 0x1D38 */
    Obj50 cell[8][9];  /* 0x2058 */
    Desc mark[8][9];   /* 0x36D8 */
    Mark marked[8][9]; /* 0x4C38 */
} Work_800ED360;
/* lbl_80305C78 */
typedef struct {
    s16 flag;
    u8 pad2[2];
    s16 x;
    s16 y;
    u8 pad8[0xc];
    u16 x14;
    u16 count;
    u16 piece[10];
    u8 cell[8][9];
    s16 v;
} Cur_800ED360;
typedef struct {
    u8 pad0[0x19];
    u8 state;
    u8 pad1a[0x24 - 0x1A];
    Work_800ED360* work;
} Node_800ED360;
typedef struct {
    u8 pad0[0x20];
    NJS_TEXLIST* texlist; /* 0x20 */
} Res_800EC488;
typedef struct {
    u8 pad0[4];
    Res_800EC488* res;  /* 0x04 */
} Obj_800EC488;
extern Cur_800ED360 lbl_80305C78;
extern Board* lbl_80346DF0;
extern Obj_800EC488* lbl_80346DEC;
extern u8 lbl_802E3D68[8][9];
extern s16 lbl_802E3CF4[10][4];
extern void fn_801D7A08(Desc* p, f32 a, f32 b);
extern void fn_801D7A14(Desc* p, f32 a, f32 b, f32 c, f32 d);
extern void fn_801D7A90(NJS_TEXLIST* tex, Desc* d);
extern Work_800ED360* lbl_80346DF4;
extern Node_800ED360* lbl_80346DF8;
extern void fn_80210450(const char* s);
typedef struct {
    u8 pad0[0x28];
    s32 kind;
    u32 size;
} Info_800F2270;
typedef struct {
    u8 pad0[0x38];
    f32 x;
    f32 y;
    f32 z;
    u8 pad44[0x1c8 - 0x44];
    struct {
        u8 pad[0x10];
        Info_800F2270* info;
        u8 pad14[0x44 - 0x14];
        f32 ox;
        f32 oy;
        f32 oz;
    }* ext;
} Obj_800F2270;
typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec_800F2270;
typedef struct {
    u8 pad0[0x24];
    s32 f24;
    s32 f28;
    s32 f2c;
    u8 pad30[0x3c - 0x30];
    s32 f3c;
} Tbl_801022FC;
typedef struct {
    u8 pad0[0x10];
    Tbl_801022FC* t;
    u8 pad14[0x44 - 0x14];
    f32 x;
    f32 y;
    f32 z;
} P1c8_801022FC;
typedef struct {
    u8 pad0[0x38];
    f32 px;
    f32 py;
    f32 pz;
    u8 pad44[0x68 - 0x44];
    s32 f68;
    s32 f6c;
    s32 f70;
    s16 f74;
    u8 pad76[0x104 - 0x76];
    f32 v104;
    f32 v108;
    f32 v10c;
    u8 pad110[0x180 - 0x110];
    s32 f180;
    u8 pad184[0x1bc - 0x184];
    void* f1bc;
    u8 pad1c0[0x1c8 - 0x1c0];
    P1c8_801022FC* p1c8;
    u8 pad1cc[0x1ec - 0x1cc];
    u8 f1ec;
    u8 pad1ed[0x250 - 0x1ed];
    f32 f250;
    f32 f254;
    f32 f258;
} Ent_801022FC;
typedef struct {
    s32 count;
    u8 pad4[0xc];
    s32 f10;
    s32 f14;
} Tbl_8010427C;
typedef struct {
    u8 pad0[0x10];
    Tbl_8010427C* t;
} P1c8_8010427C;
typedef struct {
    u8 pad0[0x74];
    s16 f74;
    u8 pad76[0x100 - 0x76];
    void* h100;
    u8 pad104[0x1c8 - 0x104];
    P1c8_8010427C* p1c8;
} Ent_8010427C;
typedef struct {
    u8 pad0[0x19];
    u8 mode;
    u8 pad1a[6];
    f32 f20;
    Ent_8010427C* d;
} Obj_8010427C;
typedef struct Sub_80107904 {
    u8 pad0[0x2];
    s16 s2;
    void *w4;
    u8 pad8[0x8];
    s16 s10;
} Sub_80107904;
typedef struct Obj_80107904 {
    u8 pad0[0xE4];
    void *pe4;
    u8 pad_e8[0x100 - 0xE8];
    void *p100;
    u8 pad_104[0x1AC - 0x104];
    void *p1ac;
    Sub_80107904 *p1b0;
} Obj_80107904;
extern void *fn_801DDAB0(void *a, void *b, void *c, void *d, s16 *e);
extern Sub_80107904 *fn_801DD984(void);
extern void fn_801DD95C(void *p);
extern void fn_801DD9AC(void *a, void *b);
extern void fn_801E5F1C(void *p, s32 n);
typedef struct Sub_801081BC {
    u8 pad0[0xE4];
    void *pe4;
    u8 pad_e8[0x17A - 0xE8];
    u16 h17a;
    u8 pad_17c[0x1C8 - 0x17C];
    u8 *p1c8;
    u8 pad_1cc[0x1FC - 0x1CC];
    s16 s1fc;
    s16 s1fe;
    s16 s200;
    u8 pad_202[0x23C - 0x202];
    u32 w23c;
} Sub_801081BC;
typedef struct Obj_801081BC {
    u8 pad0[0x19];
    u8 state;
    u8 pad_1a[0x24 - 0x1A];
    Sub_801081BC *sub;
} Obj_801081BC;
typedef struct Len_8010A55C {
    u32 w0;
    u32 len;
} Len_8010A55C;
typedef struct Sub_8010A55C {
    u8 pad0[0xE8];
    Len_8010A55C *pe8;
    u8 pad_ec[0x170 - 0xEC];
    s16 h170;
    s16 h172;
    u8 pad_174[0x18C - 0x174];
    f32 pos;
    f32 speed;
    u8 pad_194[0x198 - 0x194];
    s32 wrapped;
} Sub_8010A55C;
typedef struct Obj_8010A55C {
    u8 pad0[0x19];
    u8 state;
    u8 pad_1a[0x24 - 0x1A];
    Sub_8010A55C *sub;
} Obj_8010A55C;
typedef struct { u8 pad[0x8]; u32 flags; } PadState;
typedef struct {
    u8 pad0[2];
    s8 b2;
    s8 b3;
    u8 pad4[8];
} Stick;
typedef struct {
    u8 pad0[8];
    s32 x8;
} Slot_8010CF78;
typedef struct {
    u8 pad0[0x1a];
    s16 f1a;
    s16 f1c;
    u8 pad1e[2];
    s16 f20;
    s16 f22;
    Slot_8010CF78 *slot;     /* 0x24 */
    u8 pad28[0x38 - 0x28];
    s16 f38;
    u8 pad3a[0x40 - 0x3a];
    void *p40;
} Menu_8010CF78;
extern Stick lbl_80311A14[];
typedef struct Row {
    struct Row *next;
    u8 pad4[4];
    u32 color;
    u8 padc[8];
    u16 x14;
    u8 pad16[2];
    s16 x18;
} Row;
void fn_8010C384(Row *p, s32 a, s16 b);
typedef struct {
    s16 s0;
    s16 pad2;
    s16 n;
    s16 s6;
} Rec_800F1264;
typedef struct {
    s32 count;
    u8 pad[0x20];
} Tbl;
typedef struct {
    u8 pad0[0x10];
    Tbl* t;
} P1c8_800F1264;
typedef struct {
    u8 pad0[0x19];
    u8 mode;
} Ctl;
typedef struct {
    u8 pad0[0x188];
    u32 flags;
    u8 pad18c[0x1c8 - 0x18c];
    P1c8_800F1264* p1c8;
    u8 pad1cc[0x20a - 0x1cc];
    s16 s20a;
    s32 w20c;
    u8 pad210[0x260 - 0x210];
    s32* src;
    u8* dst;
} Obj_800F1264;
extern Rec_800F1264* fn_800D51C0(void* p, s32 id);
typedef struct {
    u8 pad0[0x18c];
    f32 f18c;
    f32 f190;
    u8 pad194[4];
    s32 state;      /* 0x198 */
    u8 pad19c[0x20c - 0x19c];
    s32 idx;        /* 0x20C */
    u8 pad210[0x24c - 0x210];
    f32 f24c;
} Obj_8010850C;
typedef struct {
    u8 pad0[0x19];
    u8 f19;
    u8 pad1a[0x24 - 0x1a];
    Obj_8010850C *obj;   /* 0x24 */
} Parent_8010850C;
extern s32 fn_8015F218(Obj_8010850C *o);
typedef struct {
    u16 flags;
    u8 pad2[0x1a - 2];
    s16 f1a;
    u8 pad1c[0x38 - 0x1c];
    s16 f38;
} Menu;
typedef struct {
    s32 x, y, z;
} IVec_800D9E00;
typedef struct {
    f32 x, y, z;
} Vec_800D9E00;
extern s32 lbl_80346DA0[2];
extern u16 lbl_8034740C;
extern void fn_800DA010(void* o);
extern void fn_800B2C1C(void* o);
extern void fn_800B2DA0(void* p, u32 v);
typedef struct {
    u8 pad0[0x4c];
    f32 f4c;
    u8 pad50[0x15f8 - 0x50];
    u8 sub[0x14];
} Work_800EA244;
extern void* fn_802268E8(void*, void*);
extern void* memset(void*, int, unsigned long);
extern void fn_801D89D4(void* p, s32 a, s32 b, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5, f32 f6, f32 f7, f32 f8);
extern void fn_800EB754(void);
extern void* lbl_803475A8;
extern s16 lbl_80346DE8;
typedef struct Node_80109868 {
    u8 pad0[0x4];
    u8 *sub;
    void *p8;
    s8 flag;
    u8 pad_d[0x2C - 0xD];
    s32 v2c;
    struct Node_80109868 *next;
} Node_80109868;
extern void *fn_801CC0A0(void *p);
typedef struct Obj_8010D280 {
    u16 flags;
    s16 state;
    u8 pad4[0x32];
    s16 s36;
    s16 s38;
    s16 s3a;
} Obj_8010D280;
typedef struct Pad_8010D280 {
    u8 pad0[8];
    u32 x8;
} Pad_8010D280;
extern s8 fn_8010B258(Obj_8010D280 *o, void *p);
typedef struct {
    u8 pad0[0x28];
    u32 f28;
    u32 f2c;
} Tbl_801032C8;
typedef struct {
    u8 pad0[0x10];
    Tbl_801032C8* t;
    u8 pad14[0x48 - 0x14];
    f32 f48;
} P1c8_801032C8;
typedef struct {
    u8 pad0[0x38];
    f32 p38;
    f32 p3c;
    u8 pad40[0x5c - 0x40];
    f32 v5c;
    f32 v60;
    f32 v64;
    u8 pad68[0x74 - 0x68];
    s16 f74;
    u8 pad76[0x16e - 0x76];
    s16 f16e;
    u8 pad170[0x178 - 0x170];
    u16 f178;
    u8 pad17a[0x1c8 - 0x17a];
    P1c8_801032C8* p1c8;
    u8 pad1cc[0x22c - 0x1cc];
    s16 f22c;
    u8 pad22e[0x24c - 0x22e];
    f32 f24c;
} Ent_801032C8;
typedef struct Task_801032C8 {
    u8 pad0[0x24];
    Ent_801032C8* d;
} Task_801032C8;
typedef struct Obj_8010C0E4 {
    u16 flags;
    u8 pad2[0xE];
    s16 h10;
    s16 h12;
    u8 pad14[6];
    s16 h1a;
    u8 pad1c[0x32 - 0x1C];
    s16 h32;
    u8 pad34[0x54 - 0x34];
    s16 len;
    char text[1];
} Obj_8010C0E4;
typedef struct Src_8010C0E4 {
    u8 pad0[4];
    s32 *p4;
    u8 pad8[0xC];
    u16 flags;
    s16 h16;
    s16 h18;
    u8 text[1];
} Src_8010C0E4;
extern u8 *TextCopyN(u8 *dst, const u8 *src, s16 n);
extern s32 TextStrlen(const char *s);
typedef struct Obj19 {
    u8 pad00[0x19];
    u8 state; /* 0x19 */
} Obj19;
typedef struct {
    s32 a[9];
    s32 b;
} Unk80305C40;
extern Unk80305C40 lbl_80305C40;
typedef struct {
    u32 id;
    u8 rest[0x64];
} Entry68;
typedef struct {
    s32 count;
    Entry68* entries;
} Tbl68;
typedef struct Mid_800E07AC {
    u8 pad0[0x54];
    f32 f54;
} Mid_800E07AC;
typedef struct Obj_800E07AC {
    u8 pad0[0x48];
    s32 f48;
    u8 pad1[0x114 - 0x4c];
    s32 f114;
    u8 pad2[0x164 - 0x118];
    f32 f164;
    u8 pad3[0x1c8 - 0x168];
    Mid_800E07AC *p1c8;
    u8 pad4[0x254 - 0x1cc];
    f32 f254;
} Obj_800E07AC;
typedef struct Cfg_800E2D0C { s32 n; u8 pad4[0x20]; s32 i24, i28, i2c, i30; u32 u34; u32 u38; } Cfg_800E2D0C;
typedef struct Scr_800E2D0C { u8 pad[0x10]; Cfg_800E2D0C *cfg; } Scr_800E2D0C;
typedef struct Obj_800E2D0C { u8 pad[0x1c8]; Scr_800E2D0C *scr; } Obj_800E2D0C;
typedef struct {
    s32 n;
    f32 x, z, w;
    f32 r0, r1, a, f1c_pad;
} Hdr;
typedef struct {
    s32 n;      /* 0x00 */
    f32 f04;
    f32 f08;
    f32 f0c;
    f32 f10;
    f32 f14;
    f32 f18;
    u32 u1c;
} Hdr2;
typedef struct { u8 pad[0x20]; void *tex; u8 pad24[0x44 - 0x24]; } Ent_8010A834;
typedef struct {
    u8 pad0[0x38];
    f32 x, y, z;
} Cam;
typedef struct { u8 pad[0x10]; Hdr2 *hdr; u8 pad14[0x20 - 0x14]; void *tex; } Ent2;
typedef struct Ctx_8010A834 {
    u8 pad0[0x1c8];
    Ent2 *p1c8;
} Ctx_8010A834;
typedef struct Obj_8010A834 {
    u8 pad0[0x19];
    u8 state;
    u8 pad1a[6];
    f32 f20;
    Ctx_8010A834 *ctx;
} Obj_8010A834;
typedef struct {
    u32 w0;
    u8 pad4[0x58 - 4];
    u32 *colors;
    u8 pad5c[0x64 - 0x5c];
    f32 x, y, z;
    u8 pad70[0x7c - 0x70];
    f32 f7c, f80;
    u8 pad84[4];
} DrawObj;
extern DrawObj lbl_80305D10;
extern char lbl_802B3058[];
extern f32 lbl_80349C40;
extern void fn_8009090C(DrawObj *o);
extern void fn_8009076C(s32 a, DrawObj *o);
extern void fn_80296EEC(s32 a, s32 b, s32 c);
extern f32 fn_80291A5C(f32 x);
extern f32 njSin(s32 a);
extern f32 njCos(s32 a);
extern void fn_80298FE4(s32 i);
typedef struct {
    u8 pad0[0x19];
    u8 mode;
    u8 pad1a[0x24 - 0x1a];
    void* ent;
} Obj_800DF5C0;
typedef struct { u8 pad0[0x24]; s32 w24; } X10;
typedef struct { u8 pad0[0x10]; X10* x; } Y1c8;
typedef struct {
    u8 pad0[0x168];
    s16 s168;
    u8 pad16a[0x1c8 - 0x16a];
    Y1c8* p1c8;
    u8 pad1cc[0x1ec - 0x1cc];
    u8 b1ec, b1ed;
    s8 b1ee;
    u8 pad1ef[0x23c - 0x1ef];
    s32 w23c;
    u8 pad240[0x25c - 0x240];
    s32 w25c;
    void* p260;
    void** p264;
    s32 w268;
} Ent_800DF5C0;
extern void PartKill(void* p);
extern void fn_800DE9BC(Obj_800DF5C0* o);
extern void fn_80225F58(u16 n);
extern void fn_80109118(s32 a, u32 b);
extern void fn_802273E0(void* p, s32 n);
typedef struct {
    u8 cell[24][28];
} Grid;
typedef struct {
    u8 pad0[0x38];
    s16 s38;
    u8 pad3a[0x47c - 0x3a];
    Grid grid[1];
} Game6E14_800EEDD4;
extern u8 lbl_802E4460[12][14];
extern char lbl_802B2308[];
extern char lbl_802B2328[];
extern s32 fn_801F39EC(s32 n);
extern s32 fn_801F3844(s32 n);
extern void fn_801F3E6C(s32 n);
extern void fn_801F3CB0(s32 n);
typedef struct {
    u8 pad0[0xe8];
    struct { s32 p0; u32 len; } *anim; /* 0xE8 */
    u8 pad_ec[0x180 - 0xec];
    s32 timer;      /* 0x180 */
    u8 pad184[0x18c - 0x184];
    f32 f18c;
    f32 f190;
    u8 pad194[4];
    s32 state;      /* 0x198 */
    u8 pad19c[0x20c - 0x19c];
    s32 idx;        /* 0x20C */
    s32 cnt;        /* 0x210 */
    u8 pad214[0x23c - 0x214];
    s32 state3;     /* 0x23C */
    u8 pad240[0x24c - 0x240];
    f32 f24c;
    u8 pad250[0x25c - 0x250];
    SeqTbl *tbl;    /* 0x25C */
} Obj_80107D90;
typedef struct {
    u8 pad0[0x19];
    u8 f19;
    u8 pad1a[0x24 - 0x1a];
    Obj_80107D90 *obj;   /* 0x24 */
} Parent_80107D90;
typedef struct {
    u8 pad0[0x38];
    f32 x38;
    f32 x3c;
    f32 x40;
    u8 pad44[0x100 - 0x44];
    void* texlist;
    u8 pad104[0x1bc - 0x104];
    void* x1bc;
} Work_8010E074;
typedef struct {
    u8 pad0[0x19];
    u8 state;
    u8 pad1a[0x24 - 0x1a];
    Work_8010E074* work;
} Obj_8010E074;
extern void fn_80222838(void* p);
extern void fn_8011622C(s32 v);
extern u32 lbl_803473FC;
extern s32 lbl_80347400;
typedef struct {
    u8 pad0[0x100];
    void* texlist;
    u8 pad104[0x170 - 0x104];
    s16 h170;
    s16 h172;
} Work_8010DDBC;
typedef struct {
    u8 pad0[0x19];
    u8 state;
    u8 pad1a[0x24 - 0x1a];
    Work_8010DDBC* work;
} Obj_8010DDBC;
extern void fn_80119AF4(Obj_8010DDBC* o);
typedef struct E { u8 pad0[4]; s32 mode; f32 f8; } E;
typedef struct T { u8 pad0[0x14]; s32 p14; u8 flags; u8 state; u8 pad1a[8]; E *e; } T;
extern void fn_800D8014(E *e);
extern void fn_802171F0(s32 a);
extern void fn_800D7D60(E *e);
extern s32 fn_800D7E7C(E *e);
extern void fn_801CBB9C(f32 f);
extern void fn_800EDF38(void);
extern void fn_800CE2B4(void);
extern void fn_80123E8C(void);
extern void fn_80217134(void);
extern void fn_800D7B28(E *e);
extern void fn_8022DBC8(void);
extern s32 lbl_80347508;
extern s32 lbl_80346E04;
extern s32 lbl_803473B4;
typedef struct {
    u8 pad0[0x18];
    u8 flags;
    u8 pad19[0x24 - 0x19];
    void* ctx;
} Src_800DA564;
typedef struct {
    Src_800DA564* src;
    s32 s4;
    s32 s8;
    s32 list[(0xA0 - 0xC) / 4];
    s32 count;
} Work_800DA564;
typedef struct {
    u8 pad0[8];
    Src_800DA564* par;
    u8 pad0c[0x18 - 0xC];
    u8 flags;
    u8 state;
    u8 pad1a[0x24 - 0x1A];
    Work_800DA564* work;
} Obj_800DA564;
extern s32 fn_800B2DC0(void* c, s32 idx, s32 a, s16 b, f32 f);
extern void fn_800DA744(s32 id, s32* out);
extern s32 fn_801CC62C(char *name);
extern void *fn_801DB244(char *path);
extern void fn_80224040(u16 id, void *p);
extern void fn_8010A278(void *p);
typedef struct { u8 pad0[0x28]; s32 w28; s32 w2c; } Info_80101E64;
typedef struct { u8 pad0[0x10]; Info_80101E64* info; } Sub_80101E64;
typedef struct {
    u8 pad0[0x38];
    f32 x38, y3c, z40;   /* 0x38 */
    s32 a44, a48, a4c;   /* 0x44 */
    u8 pad50[0x100 - 0x50];
    void* tex;           /* 0x100 */
    u8 pad104[0xEC - 0x104 + 0x18 + 0x0];
} Dummy_80101E64;
typedef struct {
    u8 pad0[0x38];
    f32 x38, y3c, z40;   /* 0x38 */
    s32 a44, a48, a4c;   /* 0x44 */
    u8 pad50[0xEC - 0x50];
    s32 wec;             /* 0xEC */
    u8 pad_f0[0x100 - 0xF0];
    void* tex;           /* 0x100 */
    u8 pad104[0x180 - 0x104];
    s32 count;           /* 0x180 */
    u8 pad184[0x18C - 0x184];
    f32 f18c;            /* 0x18C */
    f32 f190;            /* 0x190 */
    u8 pad194[4];
    s32 flag;            /* 0x198 */
    u8 pad19c[0x1C8 - 0x19C];
    Sub_80101E64* sub;   /* 0x1C8 */
    u8 pad1cc[0x20C - 0x1CC];
    s32 w20c;            /* 0x20C */
    s32 w210;            /* 0x210 */
} Work_80101E64;
extern s32 fn_801C5D88(void* w, s32 a);
extern void fn_801C5B44(void* w, void* p);
extern void fn_801C5AB4(void* w, void* p);
extern void fn_801E66E0(void* w);
typedef struct {
    u8 pad00[0x48];
    void* p48;
    u8 pad4c[0xC5C - 0x4C];
    Obj50 o0;
    Obj50 o1;
    Obj50 o2;
    Obj50 o3;
    Obj50 o4;
    void* bank;
    void* b0;
    void* b1;
    void* b2;
} Work_800EDB70;
extern u32 lbl_80346E0C;
extern u8 lbl_802B2188[];
extern void fn_800EE51C(void);
extern void fn_801D8AB4(Obj50* o, s32 a, s32 b, f32 x, f32 y);
extern void* fn_801E49D8(void* p);
extern void* fn_801E4984(void* bank, s32 i);
extern void fn_801D6998(void* buf, void* src);
extern void fn_801D66D4(void);
extern void fn_801CBBD8(void);
extern s32 fn_800EE450(void);
extern void fn_801D668C(void);
extern void fn_800EDFA8(void);
typedef struct Hit {
    u32 w[9];
    u16 h24;
    u8 pad26[2];
    u32 w28, w2c, w30;
} Hit;
typedef struct Ent_800F1E5C {
    u8 pad0[0x18];
    NJS_POINT3 *pos;  /* 0x18 */
    u8 pad1c[4];
    Angle *ang;       /* 0x20 */
} Ent_800F1E5C;
typedef struct Obj_800F1E5C {
    u8 pad0[0x38];
    NJS_POINT3 p;     /* 0x38 */
    u8 pad44[0x1b8 - 0x44];
    Hit *hit;         /* 0x1b8 */
    Ent_800F1E5C *ent;         /* 0x1bc */
} Obj_800F1E5C;
extern void njRotateY(NJS_MATRIX m, Angle a);
extern void fn_801C5A60(NJS_MATRIX m, NJS_POINT3 *p, NJS_POINT3 *out);
extern u32 fn_80222E00(u32 flags, Ent_800F1E5C *e);
extern s32 fn_802254A0(NJS_POINT3 *p, Hit *h);
extern NJS_POINT3 lbl_802B2228;
extern SaveData lbl_8030B7F4;
/* fn_80005D98's sprite (as in evobj.c). */
typedef struct Obj14 {
    u32 w[4];
    s16 flag; /* 0x10 */
    u16 pad;
} Obj14;
typedef struct Obj20 {
    f32 x, y;      /* 0x00 */
    f32 pad08;     /* 0x08 */
    f32 sx, sy;    /* 0x0C */
    u32 colour;    /* 0x14 */
    NJS_TEXLIST* texlist; /* 0x18 */
    Obj14* data;   /* 0x1C */
} Obj20;
extern u32 lbl_80347648;
extern s32 lbl_80347408;
extern f32 fn_80290008(NJS_POINT3* a, NJS_POINT3* b);
extern void fn_80005D98(Obj20* obj, s32 a, s32 b, f32 z);
extern int rand(void);
/* unit has s8; read here with lbz and no extsb */
extern u32 lbl_80310B3C[0x356];
extern s32 lbl_80346E40;
extern s32 lbl_803473D8;
extern void* lbl_80346E54;
extern void* lbl_80346E50;
extern s32 lbl_80346DAC;
extern f32 lbl_80347484;
extern f32 lbl_80347480;
extern s32 lbl_8034747C;
extern u16 lbl_80347478;
extern void* lbl_80347370;
extern char lbl_802B244C[];
extern void fn_80101378(void);
extern s32 fn_800FFB24(void);
extern s32 fn_801015AC(s32 state);
extern s32 fn_80090D78(void);
extern void fn_80217554(void);
extern s32 fn_800C7DD4(void);
extern s32 fn_800C7DFC(void);
extern void fn_802126C8(void);
extern void fn_80212130(void);
extern void fn_8012A39C(void);
extern void fn_80129DD0(void);
extern void fn_800E1A24(void);
extern void fn_8022D9C4(void);
extern void fn_80129AA4(void);
extern void fn_800CD16C(void);
extern void fn_801DA0AC(void);
extern void fn_801299B4(void);
extern void fn_800FF218(void);
extern void fn_800D2E60(void);
extern s32 fn_800C1C24(void);
extern void fn_80217C24(void);
extern void fn_80217608(void);
extern void fn_80219324(s32 n);
extern void fn_80097AFC(void);
extern s32 fn_80097CA4(s32 id);
extern s32 fn_801D6CBC(s32 h, u8* p);
extern s32 fn_801D6C3C(s32 h);
extern void fn_80128F80(void);
extern void fn_80219378(char* s);
extern s32 fn_80128F2C(void);
extern void fn_80101494(void);
/* item table (evobj.c's TblC, 0x24 per entry from id 0x190) */
typedef struct ItemTbl {
    u8 pad0[0x12];
    s8 kind;     /* ADD: 0x12 */
    u8 pad13[0x24 - 0x13];
} ItemTbl;
extern ItemTbl lbl_802D7E4C[];
extern void fn_800EA4A8(ResSpr* spr);
extern s32 fn_801F4C24(s16 id);
/* item category: 0 weapon ... 5 accessory (evobj.c declares it (void)) */
extern char* fn_801F4AE4(s16 id);
typedef struct ResStat_800E9B04 {           /* 0x6E */
    s16 h0;      /* 0x00 */
    s16 h2;      /* 0x02 */
    u8 pad4[4];
    u8 b8;       /* 0x08 */
    u8 b9[99];   /* 0x09 */
    u8 b6c;      /* 0x6C */
    u8 b6d;      /* 0x6D */
} ResStat_800E9B04;
typedef struct Ctx3594_800E9B04 {
    u32 w0;              /* 0x00 */
    s32 state;           /* 0x04 */
    u32 w8;              /* 0x08 */
    s32 count;           /* 0x0C */
    s32 w10;             /* 0x10 */
    s32 w14;             /* 0x14 */
    s32 total;           /* 0x18 */
    s32 w1c;             /* 0x1C */
    s32 w20;             /* 0x20 */
    s32 cur;             /* 0x24 */
    struct { s16 h; u8 pad[2]; } h28[3]; /* 0x28 */
    s8 b34[4];           /* 0x34 */
    s8 b38[4];           /* 0x38 */
    u8 pad3c[4];
    s32 timer;           /* 0x40 */
    s32 w44;             /* 0x44 */
    s32 w48;             /* 0x48 */
    f32 fade;            /* 0x4C */
    ResMember member[4]; /* 0x50 ADD */
    u8 pad80[0x140];
    ResRow row[4];       /* 0x1C0 */
    ResMem mem[4];       /* 0x2C8 */
    f32 z318[4];         /* 0x318 ADD: per-member draw z */
    u8 pad328[0x48];
    ResSpr spr[22];      /* 0x370 */
    ResPanel obj[22];    /* 0x580 */
    ResStat_800E9B04 stat[4];     /* 0xEC8 */
    u8 pad1080[0x470];
    s16 evIdx;           /* 0x14F0 */
    s16 h14f2;           /* 0x14F2 */
    u8 pad14f4[0x44];
    ResEv ev[16];        /* 0x1538 */
    u8 sub[0x14];        /* 0x15F8 */
    s32 active;          /* 0x160C */
} Ctx3594_800E9B04;

void fn_800D81E8(void) {
    fn_80226D14();
    fn_80226BD0(-2.92f, 1.0f);
}

s32 fn_800DDE60(u8 *self) {
    u8 *p = *(u8 **)(self + 0x24);
    memcpy(p + 0x104, *(u8 **)(p + 0x1d8) + 0x30, 0xc);
    return 1;
}

s32 fn_800E043C(LoopObj* obj) {
    return obj->looped != 0;
}

void fn_800E0450(AnimObj* obj) {
    if (obj == NULL) {
        return;
    }
    obj->frame = 0.0f;
    obj->speed = 0.0f;
    obj->looped = 1;
}

void fn_800E060C(void* p) {
    fn_800DF74C(p, lbl_802B1718);
}

void fn_800E0A8C(TgtObj* obj) {
    if (obj == NULL) {
        return;
    }
    obj->tgt[0] = 0;
    obj->tgt[1] = 0;
    obj->tgt[2] = 0;
}

extern char lbl_802B1700[];
void fn_800E0AA8(void* p) {
    fn_800DF74C(p, lbl_802B1700);
}

s32 fn_800E0AD0(s32 mode, s32 a, s32 b) {
    s32 ret = 0;
    if (a > 0) {
        if ((mode == 0 && a >= b) || (mode == 1 && a > b)) {
            ret = 1;
        }
    }
    return ret;
}

s32 fn_800E0C38(u32 id) {
    s32 r = 0;
    if (id >= 0x4E20 && id < 0x6FB7) {
        r = 1;
    }
    return r;
}

void fn_800E1A24(void) {
    if (lbl_80346DB0 == 0) {
        return;
    }
    if (!(lbl_80311A60[0]->flags & 0x1000)) {
        return;
    }
    lbl_803473A4 = ~lbl_803473A4;
}

void fn_800E28D4(f32 *src, u32 *cfg) {
    u32 a;
    u32 b;
    u32 c;
    lbl_80305C68[0] = src[0];
    lbl_80305C68[1] = src[1];
    lbl_80305C68[2] = src[2];
    a = cfg[0];
    b = cfg[1];
    c = cfg[2];
    lbl_80346DB4 = 0xFF000000 | ((a & 0xFF) << 16) | ((b & 0xFF) << 8) | (c & 0x00FF0000);
    lbl_80346DB8 = 1;
}

void fn_800E3540(void) {
}

void fn_800E3544(void) {
    lbl_80346DC0 = 0;
    lbl_80346DB8 = 0;
}

void fn_800E36B0(void) {
    lbl_80346DCC = fn_801E1C7C(0x1610);
    memset(lbl_80346DCC, 0, 0x1610);
    lbl_80346DD4 = 0;
    lbl_80346DD0 = 0;
    *(u32 *)((u8 *)lbl_80346DCC + 0x160c) = 0;
}

static inline void BoardDrawAt(Desc* d, f32 x, f32 y) {
    fn_801D7A08(d, x + lbl_80346DF4->base.x, y + lbl_80346DF4->base.y);
    fn_801D7A90(lbl_80346DEC->res->texlist, d);
}

static inline s32 CellSetFrame(Desc* d, s8 f) {
    if (f != 0) {
        if (f & 2) {
            fn_801D7A14(d, lbl_802E3CF4[5][0], lbl_802E3CF4[5][1], lbl_802E3CF4[5][2], lbl_802E3CF4[5][3]);
        } else if (f & 1) {
            fn_801D7A14(d, lbl_802E3CF4[6][0], lbl_802E3CF4[6][1], lbl_802E3CF4[6][2], lbl_802E3CF4[6][3]);
        } else if (f & 4) {
            fn_801D7A14(d, lbl_802E3CF4[3][0], lbl_802E3CF4[3][1], lbl_802E3CF4[3][2], lbl_802E3CF4[3][3]);
        } else {
            fn_801D7A14(d, lbl_802E3CF4[2][0], lbl_802E3CF4[2][1], lbl_802E3CF4[2][2], lbl_802E3CF4[2][3]);
        }
        if (f & 0x40) {
            d->col = 0xFFFF0000;
        }
        return 1;
    }
    return 0;
}

void fn_800EC488(void) {
    Desc* d;
    s16 i;
    s16 c;

    BoardDrawAt(&lbl_80346DF0->bg, 448.0f, 256.0f);
    if (lbl_80305C78.x14 == 0) {
        lbl_80346DF0->frame.col = 0xFFFF0000;
    }
    d = &lbl_80346DF0->frame;
    BoardDrawAt(d, 485.0f, 434.0f);
    for (i = 0; i < 10; i++) {
        lbl_80346DF0->slot[i].cb = lbl_80346DF4->slot[i].x;
        BoardDrawAt(&lbl_80346DF0->slot[i], 0x20b + i * 8, 437.0f);
    }
    for (i = 0; i < 10; i++) {
        if (i < lbl_80305C78.count) {
            lbl_80346DF0->piece[i].enable = 1;
            lbl_80346DF0->piece[i].ox = (lbl_80305C78.piece[i] % 8) * 18 + 0x1c8;
            lbl_80346DF0->piece[i].oy = (lbl_80305C78.piece[i] / 8) * 18 + 0xfa;
        }
        d = &lbl_80346DF0->piece[i];
        d->ox += lbl_80346DF4->base.x;
        d->oy += lbl_80346DF4->base.y;
        fn_801D7A90(lbl_80346DEC->res->texlist, d);
    }
    for (i = 0; i < 8; i++) {
        for (c = 0; c < 9; c++) {
            if (lbl_802E3D68[i][c] == 0x80) {
                continue;
            }
            if (CellSetFrame(&lbl_80346DF0->cell[i][c], lbl_80305C78.cell[i][c]) == 1) {
                lbl_80346DF0->cell[i][c].cb = lbl_80346DF4->cell[i][c].x;
                d = &lbl_80346DF0->cell[i][c];
                BoardDrawAt(d, 0x1dc + i * 18, 0x10e + c * 18);
            }
            if (lbl_80346DF4->marked[i][c].on != 0) {
                d = &lbl_80346DF4->mark[i][c];
                BoardDrawAt(d, 0x1dc + i * 18, 0x10e + c * 18);
            }
        }
    }
    lbl_80346DF0->cursor.colour = 0xffff - lbl_80347450->ang[1] % 0xffff;
    d = &lbl_80346DF0->cursor;
    BoardDrawAt(d, lbl_80305C78.x * 18 + 0x1dc, lbl_80305C78.y * 18 + 0x10e);
    lbl_80346DF0->cursor2.cb = lbl_80346DF4->cursor.x;
    d = &lbl_80346DF0->cursor2;
    BoardDrawAt(d, lbl_80305C78.x * 18 + 0x1c8, lbl_80305C78.y * 18 + 0xfa);
}

extern void fn_801D7A28(Desc* d, f32 z, f32 x, f32 y, f32 w, f32 h, f32 ox, f32 oy);
extern u32 lbl_802E3E40[10];

void fn_800ECC5C(void) {
    f32 z;
    s16 i;
    s16 c;

    z = -8.0f;
    fn_801D7A28(&lbl_80346DF0->bg, z, lbl_802E3CF4[8][0], lbl_802E3CF4[8][1], lbl_802E3CF4[8][2], lbl_802E3CF4[8][3],
                448.0f, 256.0f);
    lbl_80346DF0->bg.cb = 0.8f;
    for (i = 0; i < 8; i++) {
        for (c = 0; c < 9; c++) {
            z += 0.02f;
            fn_801D7A28(&lbl_80346DF4->mark[i][c], z, lbl_802E3CF4[3][0], lbl_802E3CF4[3][1], lbl_802E3CF4[3][2],
                        lbl_802E3CF4[3][3], 476.0f, 270.0f);
            lbl_80346DF4->mark[i][c].cb = 0.0f;
        }
    }
    for (i = 0; i < 8; i++) {
        for (c = 0; c < 9; c++) {
            z += 0.02f;
            fn_801D7A28(&lbl_80346DF0->cell[i][c], z, lbl_802E3CF4[3][0], lbl_802E3CF4[3][1], lbl_802E3CF4[3][2],
                        lbl_802E3CF4[3][3], 476.0f, 270.0f);
            fn_801D8AB4(&lbl_80346DF4->cell[i][c], 1, 0, 0.8f, 0.8f);
        }
    }
    for (i = 0; i < 10; i++) {
        z += 0.02f;
        fn_801D7A28(&lbl_80346DF0->piece[i], z, lbl_802E3CF4[1][0], lbl_802E3CF4[1][1], lbl_802E3CF4[1][2],
                    lbl_802E3CF4[1][3], 474.0f, 268.0f);
        lbl_80346DF0->piece[i].enable = 0;
        lbl_80346DF0->piece[i].cb = 0.8f;
    }
    z += 0.02f;
    fn_801D7A28(&lbl_80346DF0->cursor2, z, lbl_802E3CF4[0][0], lbl_802E3CF4[0][1], lbl_802E3CF4[0][2],
                lbl_802E3CF4[0][3], 474.0f, 268.0f);
    lbl_80346DF0->cursor2.cb = 0.8f;
    z += 0.02f;
    fn_801D7A28(&lbl_80346DF0->frame, z, lbl_802E3CF4[9][0], lbl_802E3CF4[9][1], lbl_802E3CF4[9][2],
                lbl_802E3CF4[9][3], 485.0f, 434.0f);
    for (c = 0, i = 9; i >= 0; i--, c++) {
        z += 0.02f;
        fn_801D7A28(&lbl_80346DF0->slot[c], z, lbl_802E3CF4[7][0], lbl_802E3CF4[7][1], lbl_802E3CF4[7][2],
                    lbl_802E3CF4[7][3], 0x20b + i * 8, 437.0f);
        lbl_80346DF0->piece[i].enable = 0;
        lbl_80346DF0->piece[i].cb = 0.8f;
        lbl_80346DF0->slot[c].col = lbl_802E3E40[c];
        if (c < lbl_80305C78.x14) {
            fn_801D8AB4(&lbl_80346DF4->slot[c], 1, 0, 1.0f, 1.0f);
        } else {
            fn_801D8AB4(&lbl_80346DF4->slot[c], 1, 0, 0.0f, 0.0f);
        }
    }
    fn_801D7A28(&lbl_80346DF0->cursor, -3.0f, lbl_802E3CF4[4][0], lbl_802E3CF4[4][1], lbl_802E3CF4[4][2],
                lbl_802E3CF4[4][3], 476.0f, 270.0f);
    lbl_80346DF0->cursor.cb = 0.8f;
}

s32 fn_800F816C(u8 *obj) {
    s32 v = 0xa;
    if (obj != 0) {
        if (*(void **)(obj + 0x24) != 0) {
            v = fn_800F7D6C(*(void **)(obj + 0x24));
        }
        obj[0x19] = v;
    }
    return 1;
}

void fn_800FF3EC(void *src) {
    if (lbl_80346E3C != 0) {
        memcpy(lbl_80346E3C + lbl_80346E38 * 0xc0, src, 0xc0);
        lbl_80346E38 = lbl_80346E38 + 1;
    }
}

s32 fn_800FF438(void) {
    s32 ret = -1;
    if (lbl_80310B3C[0x22] & 0x10) {
        if (fn_801D6E38(lbl_8034757C) == 1) {
            ret = lbl_8034757C;
        }
    }
    return ret;
}

s32 fn_800FF48C(void *a, s32 b) {
    s32 r = 0;
    if (lbl_80347490 == 0) {
        lbl_80347490 = (void (*)(s32))a;
        r = 1;
        lbl_8034748C = b;
    }
    return r;
}

void fn_800FF4B0(void) {
    if (lbl_80347490 != 0) {
        lbl_80347490(lbl_8034748C);
        lbl_80347490 = 0;
    }
}

typedef struct Msg {
    s16 x0;
    s16 x2;
    s16 x4;
    s16 x6;
    s32 x8;
    s32 xc;
} Msg;
extern void fn_80123E9C(Msg*, s16);
void fn_800FF780(Msg* a, s16 i) {
    fn_80123E9C(a, i);
}

void fn_800FF9FC(void) {
    lbl_80311AD4[6] = 15;
    lbl_80346E48 = 1;
}

void fn_80100150(void* p) {
    fn_801004C4(p, lbl_80305CF0);
}

void fn_801003F4(void* p) {
    u8 buf[0x20];
    fn_801CC434(p, 0, buf);
    fn_80109A94((char *)buf);
}

void* fn_801005F8(Tbl_UNIT0000* t, u16 key) {
    s32 i;
    TblEntry* e = t->entries;
    for (i = 0; i < t->count; i++) {
        if (key == e->id) {
            return e;
        }
        e++;
    }
    return NULL;
}

void fn_80100684(s32 a, s32 b) {
    fn_801E1AC8((u16)lbl_80311AC0.w4, lbl_80311AC0.room, a, b);
}

void fn_801006C0(void* p) {
    fn_800D2924(p);
}

extern void fn_800D2C60(Msg*, s16);
void fn_801006E0(Msg* a, s16 i) {
    fn_800D2C60(a, i);
}

extern void fn_800D2C74(Msg*, s16);
void fn_80100700(Msg* a, s16 i) {
    fn_800D2C74(a, i);
}

void fn_80100720(s8 x) {
    fn_800D2CA8(x);
}

extern void fn_800D2CB8(s32 x);
void fn_80100744(s8 x) {
    fn_800D2CB8(x);
}

void fn_80101060(void* p, s32 a, s32 b) {
    fn_80100E68(p, 0, a, b);
}

void fn_8010108C(s32 a, s32 b, s32 c) {
    fn_80100E68((void*)0, a, b, c);
}

extern void fn_801073B4(Msg*, s16);
s32 fn_801010C4(void) {
    return lbl_80346E44;
}

void fn_80108C9C(void) {
}

void fn_80108CA0(void) {
}

void fn_80108CA4(Msg* a, s16 i) {
    fn_801073B4(a, i);
}

typedef struct Node { u8 pad0[4]; void *x4; u8 pad8[0x28]; struct Node *next; } Node;
static inline s32 find(s32 id, Out_80109468 *r) {
    u16 x = id;
    Entry *n;
    for (n = lbl_80347460; n != 0; n = n->next) {
        if (fn_80109468(x, (Set_80109468 *)n->ptr, r) == 1) {
            return 1;
        }
    }
    return 0;
}
s32 fn_801091F8(s32 id, void **out) {
    Out_80109468 r;
    if (out != 0 && *out != 0 && fn_80109468((u16)id, (Set_80109468 *)*out, &r) == 1) {
        return (s32)r.e;
    }
    if (find(id, &r) == 1) {
        if (out != 0) {
            *out = (void *)r.s;
        }
        return (s32)r.e;

    }
    return 0;
}

s32 fn_801092C0(s32 id, void **out) {
    Out_80109468 r;
    if (out != 0 && *out != 0 && fn_80109468((u16)id, (Set_80109468 *)*out, &r) == 1) {
        return (s32)r.e;
    }
    if (find(id, &r) == 1) {
        if (out != 0) {
            *out = (void *)r.s;
        }
        return (s32)r.e;

    }
    return 0;
}

void fn_801097F8(s32 a, s32 b, s32 c) {
    fn_801096FC((void *)1, a, (u32)b, (const char *)c);
}

void fn_80109A4C(void) {
    void *p = lbl_80346E58;
    lbl_80347460 = 0;
    lbl_8034745C = 0;
    lbl_80347458 = 1000;
    if (p != 0) {
        memset(p, 0, 0x40000);
    }
}

void fn_8010A094(void) {
    fn_801E17E0(lbl_80346E58);
    lbl_80346E58 = NULL;
}

void* fn_8010A214(u32 idx) {
    void** tbl = (void**)lbl_80346E58;
    if (tbl != NULL) {
        if (idx < 0x10000) {
            return tbl[idx];
        }
    }
    return NULL;
}

void fn_8010A240(IdxObj* o) {
    void** tbl = (void**)lbl_80346E58;
    s32 idx;
    if (tbl == NULL) {
        return;
    }
    idx = o->idx;
    if (idx < 0) {
        return;
    }
    if (idx >= 0x10000) {
        return;
    }
    tbl[idx] = o;
}

s32 fn_8010A270(void) {
    return 0x9E;
}

s32 fn_8010A530(MotCtx* ctx, MotObj* src) {
    ctx->dst->frame = src->frame;
    ctx->dst->speed = src->speed;
    ctx->dst->motion = src->motion;
    return 0;
}

s32 fn_8010CED4(void) {
    if (lbl_80346E64 >= 2 && lbl_80346E64 < 8) {
        return 1;
    }
    return 0;
}

s32 fn_800DE390(Key* p, Key* q) {
    s32 r = 0;
    if (p != 0 && q != 0) {
        if (p->a == q->a && p->b != q->b && (p->c >> 16) == (q->c >> 16)) {
            r = 1;
        }
    }
    return r;
}

s32 fn_800DE3E8(Key* p, Key* q) {
    s32 r = 0;
    if (p != 0 && q != 0) {
        if (p->a == q->a && p->b == q->b && (p->c >> 16) == (q->c >> 16)) {
            r = 1;
        }
    }
    return r;
}

s32 fn_800DE5EC(u32 x) {
    s32 inr;
    s32 ret;
    u32 r5;
    ret = -1;
    inr = 0;
    if (x >= 0x4e20 && x < 0x6fb7) {
        inr = 1;
    }
    if (inr != 0) {
        if (x < 0x59d8) {
            r5 = x - 0x4e20;
        } else if (x < 0x6590) {
            r5 = x - 0x59d8;
        } else {
            r5 = x - 0x6590;
        }
        ret = ((r5 % 10000) / 100);
    }
    return ret;
}

void fn_800E0470(Ent_800E0470* p) {
    f32 f31;

    if (p != 0) {
        f31 = lbl_803496AC;
        if (fn_801C6068(p, 10) != 0) {
            f31 = fn_801C5D04(p, 9);
        }
        p->f190 = -f31;
        p->u198 = 0;
    }
}

void fn_800E04E0(Ent_800E04E0* p) {
    if (p != 0) {
        f32 v;
        if (p->pe8 != 0) {
            v = (f32)p->pe8->u4 - lbl_803496AC;
        } else {
            v = lbl_80349698;
        }
        p->f18c = v;
        p->f190 = lbl_80349698;
        p->u198 = 1;
    }
}

void fn_800E0540(Ent_800E0540* p) {
    f32 f31;

    if (p != 0) {
        f31 = lbl_803496AC;
        if (fn_801C6068(p, 10) != 0) {
            f31 = fn_801C5D04(p, 9);
        }
        p->f190 = f31;
        p->u198 = 0;
    }
}

void fn_800E05AC(Ent_800E05AC* p) {
    if (p != 0) {
        f32 z = lbl_80349698;
        p->f18c = z;
        p->f190 = z;
        p->u198 = 0;
        if (fn_801C5F40(p, 1) != 0) {
            p->uec = p->p1c8->m1c->u8;
        }
    }
}

void fn_800EDF38(void) {
    lbl_80346E18 = fn_802267AC(lbl_803475A0, fn_800EDB70);
    lbl_80346E18->p24 = fn_801E1C7C(0xdfc);
    memset(lbl_80346E18->p24, 0, 0xdfc);
    lbl_80346E18->f19 = 0;
    lbl_80346E14 = lbl_80346E18->p24;
    lbl_80346E10 = 0;
}

void fn_801000F0(u32 a, u32 b) {
    if (a != 0x7fffffff) {
        lbl_8030A3C8[0] = a;
        fn_800D2C44((u16)a);
    }
    if (b != 0x7fffffff) {
        lbl_8030A3C8[1] = b;
    }
}

s32 fn_8010038C(void) {
    Rec* r = fn_80109404();
    if (r == 0) {
        return 0;
    }
    if (r->u4 == 0) {
        return 0;
    }
    if (r->p8 != 0) {
        fn_80109D74(r->p8);
        r->p8 = 0;
    }
    return 1;
}

void* fn_80100E10(void* a, u32 unused, u32 b, u32 c) {
    void* r;
    r = fn_801C6180(a);
    if (r != 0) {
        fn_80100BF8(r, b, c);
    }
    return r;
}

void fn_801090A8(Obj_801090A8* o) {
    s32 s = o->state;
    switch (s) {
    case 0:
    case 0xfe:
        if (lbl_80347450 != 0) {
            fog_enabled = 1;
            o->state = 1;
        }
        break;
    case 1:
        break;
    case 0xff:
        fn_80100B74(o);
        break;
    }
}

s32 fn_80109388(s32 a, void* b) {
    s32 r;
    if (a == -1 || b == 0) {
        return 0;
    }
    fn_800D2B1C(b);
    r = 1;
    if (fn_801096FC(0, a, (u32)b, 0) == 0) {
        r = 0;
    }
    return r;
}

Rec* fn_80109404(void *a) {
    u8 buf[0x20];
    Node_801094C8* n;

    fn_801CC434(a, 0, buf);
    n = (Node_801094C8 *)lbl_80347460;
    while (n != 0) {
        if (fn_801E1098(buf, (u8*)n + 0xc) == 0) {
            return (Rec*)n;
        }
        n = n->next;
    }
    return 0;
}

s32 fn_80109468(u32 key, Set_80109468* s, Out_80109468* out) {
    Ent_80109468* e;
    s32 n;

    if (s == 0) {
        return 0;
    }
    e = s->ent;
    n = s->count;
    do {
        if (e->key == key) {
            out->s = s;
            out->e = e;
            out->v = e->v38;
            return 1;
        }
        e = (Ent_80109468*)((u8*)e + 0x68);
    } while (--n != 0);
    out->s = 0;
    out->e = 0;
    out->v = 0;
    return 0;
}

void *fn_801094C8(u32 key) {
    Node_801094C8* n;
    void *r = 0;
    Out_80109468 out;

    n = (Node_801094C8 *)lbl_80347460;
    while (n != 0) {
        if (fn_80109468(key, n->data, &out) == 1) {
            r = (void *)out.v;
            break;
        }
        n = n->next;
    }
    return r;
}

s32 fn_8010AB60(Ctx_8010AB60* c, Src_8010AB60* src) {
    c->dst->f18c = src->f18c;
    c->dst->f190 = src->f190;
    c->dst->ue8 = src->ue8;
    c->dst->f24c = src->f38;
    c->dst->f250 = src->f3c;
    c->dst->f254 = src->f40;
    c->dst->u20c = src->u44;
    c->dst->u210 = src->u48;
    c->dst->u214 = src->u4c;
    return 0;
}

void* fn_8010CEF8(void) {
    Tp* r31;
    void* r30;

    lbl_80346E60 = 0;
    r30 = fn_801E1C7C(0xb8);
    if (r30 != 0) {
        r31 = fn_802267AC(lbl_80347590, fn_8010D4F4);
        if (r31 != 0) {
            r31->p24 = r30;
            lbl_80346E64 = 0;
        } else {
            fn_801E17E0(r30);
        }
    }
    fn_802260E8(r31);
    return r31;
}

void fn_8010DE84(Obj_8010DE84_UNIT0000* o) {
    if (o->st == 0) {
        Sub_UNIT0000* p = o->p24;
        p->s170 = 0;
        p->s172 = 0;
        if (p->p100 != 0) {
            fn_80227810(p->p100);
        }
        o->st = 2;
    } else {
        fn_8010DDBC(o);
    }
}

s32 fn_800D84AC(void *self) {
    s32 ret = 0;
    Task_UNIT0000 *t;

    if (lbl_803473DC == 0) {
        if ((lbl_80310B3C[0x21] & 0x80000000) == 0) {
            if (lbl_803473E4 == 0) {
                if (lbl_80347444 == 0) {
                    if (fn_80227E84(0x20000 - 0x7962) != 0) {
                        if (fn_800FF48C(fn_800D81E8, 0) != 0) {
                            t = fn_80226704(lbl_803475A0, fn_800D8214, 0x44);
                            if (t != 0) {
                                t->p24 = (u8 *)t + 0x28;
                                lbl_803473E8 = 0;
                                lbl_80347444 = 1;
                                lbl_80346D98 = self;
                                ret = 1;
                            }
                        }
                    }
                }
            }
        }
    }
    return ret;
}

void fn_800DE2E4(K06Obj_800DE2E4 *p, u8 *a, u8 *b, s8 *c) {
    K06Sub_800DE2E4 *s;
    u32 w;
    if (p == 0) {
        return;
    }
    if (a == 0) {
        return;
    }
    if (b == 0) {
        return;
    }
    if (c == 0) {
        return;
    }
    s = p->sub;
    w = p->w8 >> 16;
    if (s == 0) {
        return;
    }
    switch (w) {
    case 0:
        *a = 1;
        *b = s->f1c;
        *c = s->f20;
        break;
    case 1:
        *a = 0;
        *b = s->f1c;
        *c = s->f20;
        break;
    case 4:
        *a = 1;
        *b = s->f1c;
        *c = -1;
        break;
    }
}

void fn_800E082C(K06Obj_800E082C *p) {
    if (p == 0) {
        return;
    }
    if (fn_801C6068(p, 0xb) == 0) {
        return;
    }
    if (&p->f164 == 0) {
        return;
    }
    if (&p->f254 == 0) {
        return;
    }
    p->f254 = 0.0f;
    p->f164 = (f32)p->p1c8->leaf->v28 / 30.0f;
    if ((s16)p->f114 > 0) {
        p->f164 = -p->f164;
    }
}

void fn_800E08C8(K06Obj_800E08C8 *p) {
    f32 f;
    s32 t;
    if (p == 0) {
        return;
    }
    f = 0.0f;
    if (fn_801C6068(p, 0xb)) {
        f = (f32)p->p1c8->leaf->v2c;
    }
    if (p == 0) {
        return;
    }
    p->f114 = (s32)(182.04445f * f);
    p->f48 = p->f114;
    if (fn_801C60A4(p)) {
        t = p->f48;
        p->f48 = t + (s32)(182.04445f * p->p1c8->f54);
    }
}

void fn_800E09A0(K06Obj_800E09A0 *p) {
    f32 f;
    if (p == 0) {
        return;
    }
    if (fn_801C6068(p, 0xb) == 0) {
        return;
    }
    if (&p->f164 == 0) {
        return;
    }
    if (&p->f254 == 0) {
        return;
    }
    p->f164 = (f32)p->p1c8->leaf->v28 / 30.0f;
    f = 0.0f;
    if (fn_801C6068(p, 0xb)) {
        f = (f32)p->p1c8->leaf->v2c;
    }
    p->f254 = f;
    if (p->f254 < 0.0f) {
        p->f164 = -p->f164;
    }
}

void fn_800E2924(s32 idx) {
    K06Obj_800E2924 *o;
    o = fn_801094C8(idx);
    if (o == 0) {
        fn_801DBE1C(lbl_802B19D4, idx);
    }
    o = o->next;
    if (o->p1c8->p20->nbTexture > 2 && o->f260 != 0) {
        fn_800E1A58(o);
        fn_80299040(o->p1c8->p20);
        fn_80297CC0(1, o->f260, o->f20c, o->f210);
    }
    lbl_80346DC0 = (u16)idx;
    lbl_80346DB8 = 0;
}

s16 fn_800EC3EC(K06Obj_800EC3EC *p) {
    s16 i;
    s16 n6;
    s16 n7;

    n7 = 0;
    n6 = 0;
    for (i = 0; i < 7; i++) {
        if (p->f38 > lbl_802E3CB0[i]) {
            break;
        }
        n6++;
    }
    for (i = 0; i < 8; i++) {
        if (p->f40 > lbl_802E3CD0[i]) {
            break;
        }
        n7++;
    }
    lbl_80305C78.x = n6;
    lbl_80305C78.y = n7;
    return n6 + n7 * 8;
}

s32 fn_800EE450(void) {
    K06A *a;
    K06B *b;

    a = lbl_80311A60[0];
    if ((a->flags & 0x1000) || (a->flags & 0x200) || (a->flags & 0x800)) {
        return 0;
    }
    b = lbl_80346E14;
    b->f0c += a->s14 / 16;
    b = lbl_80346E14;
    b->f10 += lbl_80311A60[0]->s16v / 16;
    b = lbl_80346E14;
    if (b->f10 < 0x34) {
        b->f10 = 0x34;
    } else if (b->f10 > 0x1b4) {
        b->f10 = 0x1b4;
    }
    b = lbl_80346E14;
    if (b->f0c < 0x24) {
        b->f0c = 0x24;
    } else if (b->f0c > 0x1e4) {
        b->f0c = 0x1e4;
    }
    return -1;
}

s32 fn_800F1598(K06Obj_800F1598 *p) {
    K06Sub_800F1598 *s;
    K06Blk *blk;
    s32 rem;
    void *e;
    s32 ret;
    s16 id;
    s16 ty;

    ret = 0;
    s = p->sub;
    if (s != 0) {
        blk = s->blk;
        if (blk->count > 8) {
            rem = blk->count - 8;
            e = (u8 *)blk + 0x24;
            for (;;) {
                ty = ((K06Ent *)e)->ty;
                if (ty == 0) {
                    break;
                }
                id = ((K06Ent *)e)->id;
                if (ty != 2 && ty != 3) {
                    ret = fn_800F13F0(p, ty, id, (u8 *)e + 4);
                }
                e = fn_800D5184(e, (s16)rem);
                rem -= id + 1;
                if (rem <= 0) {
                    break;
                }
                if (ret == 0) {
                    break;
                }
            }
        }
    }
    return ret;
}

void fn_800FF348(void *src, s32 id, f32 a, f32 b, f32 c) {
    K06Rec *base;
    K06Rec *d;

    if (lbl_803475D8 == 0) {
        base = lbl_80346E34;
        if (base != 0) {
            d = (K06Rec *)((u8 *)base + lbl_80346E30 * 0x2c);
            memcpy(d, src, 0x1c);
            d->f1c = a;
            d->f20 = b;
            d->f24 = c;
            d->kind = id;
            lbl_80346E30 = lbl_80346E30 + 1;
        }
    }
}

void fn_801002D0(char *name) {
    s32 idx;

    if (name == 0) {
        fn_801DBE1C(lbl_802B2348, name);
    }
    strcpy(lbl_80305CF0, name);
    fn_800FF908();
    if (lbl_80347464 == 1 && lbl_80311AC0.w4 == 0x63) {
        idx = 0;
    } else {
        idx = (s8)(lbl_80311AC0.room - 0x61);
    }
    fn_801F7B04((s8)idx + lbl_80311AC0.w4 * 10);
    lbl_80311AD4[6] = 15;
}

s32 fn_80100424(void *p) {
    char buf1[0x20];
    char buf2[0x40];

    GXInvalidateTexAll();
    strcpy(buf2, (char *)lbl_8034746C);
    fn_801CC434(p, 0, buf1);
    strcat(buf2, buf1);
    if (fn_8025EF88(buf1, lbl_802B23B8) == 0) {
        return 0;
    }
    if (fn_80109404(buf1) != 0) {
        return 0;
    }
    return fn_80109E7C(buf2, lbl_80347458++);
}

void fn_8010085C(K06Obj_8010085C *p) {
    K06Ctx_8010085C *o;
    K06Sub_8010085C *s;

    o = p->ctx;
    switch (p->st) {
    case 0xfe:
    case 0:
        p->st = 1;
        break;
    case 1:
        fn_801E6744(o);
        break;
    case 0xff:
        if (o->p1bc != 0) {
            fn_80222964(o->p1bc);
            fn_801E1784(o->p1bc);
            o->p1bc = 0;
        }
        fn_801C6170(p);
        s = o->p1c8;
        if (s != 0) {
            if (s->p38 == p) {
                s->p38 = 0;
                o->p1c8->b3c = 0;
            }
        }
        break;
    }
}

void fn_80100AA4(K06Obj_80100AA4 *p) {
    K06Ctx_80100AA4 *o;
    K06Sub_80100AA4 *s;

    switch (p->st) {
    case 0xfe:
    case 0:
        if (lbl_80347450 != 0) {
            p->st = 1;
        }
        break;
    case 1:
        break;
    case 0xff:
        o = p->ctx;
        if (o->p1bc != 0) {
            fn_80222964(o->p1bc);
            fn_801E1784(o->p1bc);
            o->p1bc = 0;
        }
        fn_801C6170(p);
        s = o->p1c8;
        if (s != 0) {
            if (s->p38 == p) {
                s->p38 = 0;
                o->p1c8->b3c = 0;
            }
        }
        break;
    }
}

s32 fn_801010CC(void) {
    if (lbl_80346E44 == 2) {
        if (lbl_803473CC >= 0xa7 && lbl_803473CC <= 0xb5) {
            return 0x3d;
        }
    }
    if (lbl_80346E44 == 2) {
        if (lbl_803473CC >= 0x48 && lbl_803473CC <= 0x100) {
            return 0x3c;
        }
    }
    if (lbl_803473CC < 0x3b && lbl_80346E44 == 2) {
        return lbl_802E46E0[lbl_803473CC];
    }
    if (lbl_80347464 == 1) {
        return 0x3b;
    }
    return 0x3a;
}

f32 fn_80103B38(f32 *a, f32 *b) {
    f32 vb[3];
    f32 va[3];
    f32 len;
    f32 res;

    res = 0.0f;
    if (a != 0 && b != 0) {
        va[0] = a[0];
        va[1] = a[1];
        va[2] = a[2];
        vb[0] = b[0];
        vb[1] = b[1];
        vb[2] = b[2];
        len = njScalor(vb);
        if (len != 0.0f) {
            njUnitVector(vb);
            va[0] = va[0] / len;
            va[1] = va[1] / len;
            va[2] = va[2] / len;
            res = njInnerProduct(va, vb);
        }
    }
    return res;
}

void fn_80104C7C(u8 *obj, f32 *out) {
    u8 *p;
    u8 *q;
    u32 v;
    u32 idx;
    f32 f;

    if (fn_801C6068(obj, 0xe) == 0) {
        return;
    }
    if (out == 0) {
        return;
    }
    out[0] = 0.0f;
    out[1] = 0.0f;
    out[2] = 0.0f;
    p = *(u8 **)(obj + 0x1c8);
    q = *(u8 **)(p + 0x10);
    v = *(u32 *)(q + 0x28);
    f = (f32)v / 100.0f;
    idx = *(u32 *)(q + 0x2c) + 1;
    switch (idx) {
    case 0:
        out[0] = f;
        break;
    case 1:
        out[0] = -f;
        break;
    case 2:
        out[1] = f;
        break;
    case 3:
        out[1] = -f;
        break;
    case 4:
        out[2] = f;
        break;
    case 5:
        out[2] = -f;
        break;
    case 6:
        break;
    }
}

void fn_8010690C(u8 *obj) {
    u8 *sub;
    s32 st;
    s32 cnt;
    if (obj == 0) return;
    sub = *(u8 **)(obj + 0x24);
    if (sub == 0) return;
    st = obj[0x19];
    switch (st) {
    case 0xfe:
        break;
    case 0:
        cnt = *(s32 *)(sub + 0x180);
        if (cnt > 0) {
            if (cnt > 0) cnt--;
            *(s32 *)(sub + 0x180) = cnt;
        } else {
            SePlay(*(s32 *)(sub + 0x20c), *(s32 *)(sub + 0x210), *(s32 *)(sub + 0x214));
            fn_801C6170(obj);
        }
        break;
    }
}

void fn_80109118(s32 a, u32 b) {
    u8 **link;
    u8 *n;
    u8 *node;
    u8 *sub;
    s32 count;
    u8 *base;
    u32 idx;

    link = (u8 **)&lbl_80347460;
    n = (u8 *)lbl_80347460;
    while (n != 0) {
        if (*(u32 *)(n + 4) == b || *(s32 *)n == a) {
            *link = *(u8 **)(n + 0x30);
            fn_801E17E0(n);
            break;
        }
        link = (u8 **)(n + 0x30);
        n = *link;
    }

    if (lbl_80346E58 == 0) return;
    if (lbl_80346E58 != 0) memset(lbl_80346E58, 0, 0x40000);

    node = (u8 *)lbl_80347460;
    while (node != 0) {
        sub = *(u8 **)(node + 4);
        if (lbl_80346E58 != 0 && sub != 0) {
            base = *(u8 **)(sub + 4);
            count = *(s32 *)sub;
            do {
                idx = *(u32 *)(base + 4);
                if (idx < 0x10000) {
                    ((u8 **)lbl_80346E58)[idx] = base;
                }
                base += 0x68;
            } while (--count != 0);
        }
        node = *(u8 **)(node + 0x30);
    }
    fn_8014912C();
}

void fn_8010953C(u32 b) {
    u8 *n;
    u8 **link;
    u8 *node;
    u8 *sub;
    s32 count;
    u8 *base;
    u32 idx;

    link = (u8 **)&lbl_80347460;
    n = (u8 *)lbl_80347460;
    while (n != 0) {
        if (*(u32 *)(n + 4) == b) {
            *link = *(u8 **)(n + 0x30);
            fn_801E17E0(n);
            lbl_8034745C -= 1;
            break;
        }
        link = (u8 **)(n + 0x30);
        n = *link;
    }

    if (lbl_80346E58 == 0) return;
    if (lbl_80346E58 != 0) memset(lbl_80346E58, 0, 0x40000);

    node = (u8 *)lbl_80347460;
    while (node != 0) {
        sub = *(u8 **)(node + 4);
        if (lbl_80346E58 != 0 && sub != 0) {
            base = *(u8 **)(sub + 4);
            count = *(s32 *)sub;
            do {
                idx = *(u32 *)(base + 4);
                if (idx < 0x10000) {
                    ((u8 **)lbl_80346E58)[idx] = base;
                }
                base += 0x68;
            } while (--count != 0);
        }
        node = *(u8 **)(node + 0x30);
    }
    fn_8014912C();
}

void fn_8010961C(u32 b) {
    u8 **link;
    u8 *n;
    u8 *node;
    u8 *sub;
    s32 count;
    u8 *base;
    u32 idx;

    link = (u8 **)&lbl_80347460;
    n = (u8 *)lbl_80347460;
    while (n != 0) {
        if (*(u32 *)(n + 4) == b) {
            *link = *(u8 **)(n + 0x30);
            fn_801E17E0(n);
            lbl_8034745C -= 1;
            break;
        }
        link = (u8 **)(n + 0x30);
        n = *link;
    }

    if (lbl_80346E58 == 0) return;
    if (lbl_80346E58 != 0) memset(lbl_80346E58, 0, 0x40000);

    node = (u8 *)lbl_80347460;
    while (node != 0) {
        sub = *(u8 **)(node + 4);
        if (lbl_80346E58 != 0 && sub != 0) {
            base = *(u8 **)(sub + 4);
            count = *(s32 *)sub;
            do {
                idx = *(u32 *)(base + 4);
                if (idx < 0x10000) {
                    ((u8 **)lbl_80346E58)[idx] = base;
                }
                base += 0x68;
            } while (--count != 0);
        }
        node = *(u8 **)(node + 0x30);
    }
    fn_8014912C();
}

void fn_8010A0C0(void) {
    u8 *node;
    u8 *sub;
    s32 count;
    u8 *base;
    u32 idx;

    lbl_80346E58 = fn_801E1A74(1, 0x40000);
    if (lbl_80346E58 == 0) return;
    if (lbl_80346E58 != 0) memset(lbl_80346E58, 0, 0x40000);

    node = (u8 *)lbl_80347460;
    while (node != 0) {
        sub = *(u8 **)(node + 4);
        if (lbl_80346E58 != 0 && sub != 0) {
            base = *(u8 **)(sub + 4);
            count = *(s32 *)sub;
            do {
                idx = *(u32 *)(base + 4);
                if (idx < 0x10000) {
                    ((u8 **)lbl_80346E58)[idx] = base;
                }
                base += 0x68;
            } while (--count != 0);
        }
        node = *(u8 **)(node + 0x30);
    }
    fn_8014912C();
}

u32 fn_8010B5AC(const u8 **pp) {
    u16 c;
    u16 c2;
    const u8 *saved;
    s32 i;

    c = TextReadChar(pp);
    if (c == 0x5c) {
        saved = *pp;
        c2 = TextReadChar(pp);
        if (c2 == 0x6e) {
            return 0xa;
        }
        for (i = 0; i < 0xb; i++) {
            if (lbl_802E4C70[i] == (s32)c2) {
                return 0x80000000 | i;
            }
        }
        if (c2 == 0x77) {
            c = TextReadChar(pp);
            if (c == 0x63) {
                return 0x8000000b;
            }
            if (c == 0x6f) {
                return 0x8000000c;
            }
        }
        *pp = saved;
        return 0x5c;
    }
    return c;
}

s32 fn_8010BA34(const u8 **pp) {
    const u8 *saved;
    s32 v;
    u16 c;

    saved = *pp;
    c = TextReadChar(pp);
    if (c == 0x28) {
        v = 0;
        do {
            c = TextReadChar(pp);
            if (c == 0x29) {
                if (saved + 2 == *pp) {
                    v = -1;
                }
                return v;
            }
            if (c < 0x30) {
                break;
            }
            if (c > 0x39) {
                break;
            }
            v = (s32)c - 0x30 + v * 10;
        } while (c != 0);
    }
    *pp = saved;
    return -2;
}

u16 fn_8010C2AC(u8 *obj, s16 v) {
    u8 *n;
    s16 r30;

    if (*(s16 *)(obj + 0x36) < v) {
        return 0;
    }
    n = *(u8 **)(obj + 0x40);
    r30 = 1;
    while (n != 0 && v > 0) {
        r30 = *(s16 *)(n + 0x16);
        if (v == 1) {
            if (*(u16 *)(n + 0x14) != 0) {
                fn_8010C0E4((void *)obj, (void *)n);
                *(s16 *)(obj + 0x3a) = r30;
                return *(u16 *)(n + 0x14);
            }
            break;
        }
        if (*(u16 *)(n + 0x14) == 0) {
            v = v - *(s16 *)(n + 0x18);
        } else {
            v--;
        }
        n = *(u8 **)n;
    }
    if (*(s16 *)(obj + 0x3a) <= 0) {
        *(s16 *)(obj + 0x3a) = r30;
    }
    return 0;
}

void fn_8010C7A0(f32 a, f32 b, f32 c, f32 d, f32 e, u32 id) {
    Quad q[4];
    f32 f;
    u32 id24;

    f = fn_801DBD9C(e);
    id24 = id & 0xffffff;
    q[0].x = a;
    q[0].y = b;
    q[0].z = f;
    q[0].colour = id24;
    q[1].x = a;
    q[1].y = b + d;
    q[1].z = f;
    q[1].colour = id;
    q[2].x = a + c;
    q[2].y = b;
    q[2].z = f;
    q[2].colour = id24;
    q[3].x = a + c;
    q[3].y = b + d;
    q[3].z = f;
    q[3].colour = id;
    fn_80290ED4(q, 4, 1);
}

s32 fn_8010D458(u8 *o) {
    *(s16 *)(o + 0x3e) = 0;
    *(s16 *)(o + 0x36) = 0;
    *(s16 *)(o + 0x38) = 0;
    *(u32 *)(o + 0x44) = 0;
    *(u32 *)(o + 0x40) = 0;
    *(u32 *)(o + 0x48) = 0xffc0c0c0;
    *(s16 *)(o + 0x3c) = 1;
    *(f32 *)(o + 0x4c) = 1.0f;
    *(f32 *)(o + 0x50) = 1.0f;
    *(s16 *)(o + 0x0) = 0;
    *(s16 *)(o + 0x10) = 0x20;
    *(s16 *)(o + 0x12) = 0x178;
    *(s16 *)(o + 0x2) = 0;
    *(s16 *)(o + 0x14) = 10;
    *(s16 *)(o + 0x16) = 10;
    *(s16 *)(o + 0x30) = 0;
    *(s16 *)(o + 0x32) = -0x18;
    *(f32 *)(o + 0x4) = 0.0f;
    *(f32 *)(o + 0x8) = 1.0f;
    *(s16 *)(o + 0x36) = 0;
    *(s16 *)(o + 0x38) = 0;
    *(u8 *)(o + 0x56) = 0;
    *(s16 *)(o + 0x54) = 0;
    *(s16 *)(o + 0x3a) = 0;
    *(u32 *)(o + 0xc) = 0xa00a0a0a;
    return 1;
}

void* fn_800DE440(Obj_800DE440* o)
{
    s32 v = 0;
    void* res = 0;
    u32 t;
    s32 ok2;

    if (fn_801C60A4(o)) {
        v = 0;
        if (o->info->code >= 20000 && o->info->code < 28599) {
            v = 1;
        }
    }
    if (v) {
        v = -1;
        if (fn_801C60A4(o)) {
            v = -1;
            ok2 = 0;
            t = o->info->code;
            if (t >= 20000 && t < 28599) {
                ok2 = 1;
            }
            if (ok2) {
                if (t < 23000) {
                    t -= 20000;
                } else if (t < 26000) {
                    t -= 23000;
                } else {
                    t -= 26000;
                }
                v = (t % 10000) / 100;
            }
        }
        res = fn_800CCA6C(7, v);
    }
    return res;
}

s32 fn_800E0B08(Obj_800E0B08* o, s32 limit)
{
    s32 a = -1;
    s32 b;
    s32 ok;
    u32 t;
    s32 res;

    if (fn_801C60A4(o)) {
        a = -1;
        ok = 0;
        t = o->info->code;
        if (t >= 20000 && t < 28599) {
            ok = 1;
        }
        if (ok) {
            a = (t % 100) / 10;
        }
    }
    b = -1;
    if (fn_801C60A4(o)) {
        b = -1;
        ok = 0;
        t = o->info->code;
        if (t >= 20000 && t < 28599) {
            ok = 1;
        }
        if (ok) {
            b = t >= 23000;
        }
    }
    res = 0;
    if (a > 0) {
        if ((b == 0 && a >= limit) || (b == 1 && a > limit)) {
            res = 1;
        }
    }
    return res;
}

void fn_800E178C(Ui178C* ui, Tgt178C* t)
{
    NJS_VECTOR p;
    f32 scr[2];

    p.x = t->pos.x;
    p.y = t->pos.y;
    p.z = t->pos.z;
    njPushMatrixEx();
    fn_80286EE8();
    fn_8028B498();
    njProjectScreen(0, &p, scr);
    njPopMatrixEx();
    ui->x = scr[0] - 104.0f;
    if (ui->x > 430.0f) {
        ui->x = 430.0f;
    } else if (ui->x < 0.0f) {
        ui->x = 0.0f;
    }
    ui->y = 0.0f;
    t->fade = t->fade + (f32)ui->step / 15.0f;
    if (t->fade > 1.0f) {
        t->fade = 1.0f;
    } else if (t->fade < 0.0f) {
        t->fade = 0.0f;
    }
}

void fn_800E340C(Obj340C* o, s32 id, f32 z)
{
    f32 v[8];

    fn_801E4FD4(o);
    fn_80299040(o->info->tex);
    fn_80291428(1);
    fn_802913E8(id, -1);
    v[0] = (f32)(o->info->size->count > 10 ? o->info->size->w : 0);
    v[1] = (f32)(o->info->size->count > 11 ? o->info->size->h : 0);
    v[2] = 128.0f + v[0];
    v[3] = 128.0f + v[1];
    v[4] = 0.0f;
    v[5] = 0.0f;
    v[6] = 1.0f;
    v[7] = 1.0f;
    fn_801DBD9C(-1.0799999f + z);
    fn_802911CC(v);
    fn_80291424();
    DrawStatePop(0);
}

void fn_800E3594(void)
{
    if (lbl_803475D8 == 1) {
        lbl_80346DD0 = 255;
    }
    switch (lbl_80346DD0) {
    case 0:
    case 254:
        fn_800E36F8();
        fn_801D6B58(lbl_80346DCC->sub, lbl_802B1B20);
        lbl_80346DCC->active = 1;
        lbl_80346DD0 = 1;
        fn_80217800(4);
        lbl_80346DC8 = fn_80218570(0, 1, 18);
        break;
    case 1:
        fn_800E4644();
        break;
    case 2:
        lbl_80346DD0 = 255;
        break;
    case 255:
        if (lbl_80346DCC->active == 1) {
            fn_801D68DC(lbl_80346DCC->sub);
            lbl_80346DCC->active = 0;
        }
        fn_80217830(1);
        if (lbl_80346DCC != 0) {
            fn_801E17E0(lbl_80346DCC);
            lbl_80346DCC = 0;
        }
        lbl_80346DD4 = 1;
        break;
    default:
        lbl_80346DD0 = 255;
        break;
    }
}

void fn_800EB460(Task460* t)
{
    void* sub = t->sub;
    u32 flags;

    switch (t->state) {
    case 0:
    case 254:
        fn_8015ED90(t);
        lbl_80346DD8 = 0;
        t->state = 1;
        /* fall through */
    case 1:
        if (fn_8015E600(sub) == 0) {
            fn_801D77B8();
            flags = lbl_80311A60[0]->flags;
            if ((flags & 0x100) || (flags & 0x1000) || fn_801D1504() != 0) {
                fn_801CBBAC(10.0f);
                fn_80216D14(10);
                t->state = 2;
                lbl_80346EB4 = 0;
            }
        }
        break;
    case 2:
        if (lbl_80346DD8 > 12) {
            fn_80217CB0();
            lbl_80347450 = 0;
            fn_800FF9FC();
        } else {
            lbl_80346DD8++;
        }
        break;
    case 3:
    case 255:
        fn_8015EBF4(sub);
        fn_80100B74(t);
        break;
    }
}

void fn_800EECA8(s16 save)
{
    if (save == 0) {
        lbl_80346E14->v4c = lbl_802E725C[5];
        lbl_80346E14->v60 = lbl_802E725C[6];
        lbl_80346E14->v50 = lbl_802E72AC[5];
        lbl_80346E14->v64 = lbl_802E72AC[6];
        lbl_80346E14->v54 = lbl_802E72FC[5];
        lbl_80346E14->v68 = lbl_802E72FC[6];
        lbl_80346E14->v58 = lbl_802E734C[5];
        lbl_80346E14->v6c = lbl_802E734C[6];
        lbl_80346E14->v5c = lbl_802E739C[5];
        lbl_80346E14->v70 = lbl_802E739C[6];
    } else {
        Cfg* c = lbl_80346E14;
        lbl_802E725C[5] = c->v4c;
        lbl_802E725C[6] = c->v60;
        lbl_802E72AC[5] = c->v50;
        lbl_802E72AC[6] = c->v64;
        lbl_802E72FC[5] = c->v54;
        lbl_802E72FC[6] = c->v68;
        lbl_802E734C[5] = c->v58;
        lbl_802E734C[6] = c->v6c;
        lbl_802E739C[5] = c->v5c;
        lbl_802E739C[6] = c->v70;
    }
}

static inline s32 FlagTest(s32 n)
{
    u32 b = n + 0x500;
    return (lbl_80310B3C[b >> 5] & (1 << (b & 31))) != 0;
}

void fn_800EEFB0(void)
{
    s32 i;
    f32* p;
    s16 a;
    s32 ar;

    ar = lbl_80346E14->area;
    a = ar <= 0 ? 0 : (s16)(ar - 1);
    p = lbl_802E3EF0[a][0];
    for (i = 0; i < 29; p += 2, i++) {
        lbl_80346E14->active[i] = 0;
        if (FlagTest(i) != 0) {
            if (p[0] >= 0.0f && p[1] >= 0.0f) {
                lbl_80346E14->active[i] = 1;
                if (lbl_80346E14->level >= 15) {
                    if (i == 4) {
                        lbl_80346E14->active[i] = 0;
                    }
                    if (i == 3) {
                        lbl_80346E14->active[i] = 0;
                    }
                } else if (i == 26) {
                    lbl_80346E14->active[i] = 0;
                }
                if (i == 5 && (lbl_80310B3C[12] & 0x8000000)) {
                    lbl_80346E14->active[i] = 0;
                }
            }
        }
    }
}

s32 fn_800F0C68(Obj0C68* o)
{
    s32 ret = 0;
    PtList* cur;
    f32 f;
    f32* a;
    f32* b;
    s32 i;
    s32 n;

    n = o->frames;
    if (n > 0) {
        f = (f32)n;
        cur = o->cur;
        a = cur->pts[0];
        b = o->target->pts[0];
        o->frames = n - 1;
        if (n - 1 > 0) {
            i = cur->count;
            ret = 1;
            do {
                a[0] = a[0] + (b[0] - a[0]) / f;
                a[1] = a[1] + (b[1] - a[1]) / f;
                b += 2;
                a += 2;
                i--;
            } while (i > 0);
        } else {
            i = cur->count;
            do {
                a[0] = b[0];
                a[1] = b[1];
                b += 2;
                a += 2;
                i--;
            } while (i > 0);
        }
        fn_801DEDC0(o->h, cur->pts[0], cur->count);
    }
    return ret;
}

void fn_800F0EF4(Obj0EF4* o)
{
    void* h;
    Pair0EF4 tmp;
    u32 flags = o->flags;
    Pair0EF4* saved;

    if (!(flags & 1)) {
        h = o->h;
        if (flags & 4) {
            fn_801DE9BC(h, o->pos);
            o->pos = o->pos + o->vel;
            if (0.0f > o->vel) {
                if (-1.0f >= o->pos) {
                    o->pos = 1.0f + o->vel;
                }
            } else if (1.0f <= o->pos) {
                o->pos = -1.0f + o->vel;
            }
        }
        if (flags & 8) {
            if (fn_800F0C68((Obj0C68 *)o) == 0) {
                o->flags ^= 8;
            }
        }
        if (flags & 2) {
            saved = o->p100;
            o->p100 = &tmp;
            tmp.b = saved->b;
            tmp.a = *o->src;
            fn_801DE8C0(o, h);
            o->p100 = saved;
        }
    }
}

s32 fn_800F1010(Obj1010* o, Src1010* s, s16 mode)
{
    Vec3i v;
    s16 t;

    o->flags &= ~0x11;
    if ((u32)mode == 7) {
        o->flags |= 0x10;
        if ((s8)s->b3 < 0) {
            o->flags |= 1;
        }
        o->s208 = s->b3 & 0x7f;
        if (o->s208 != 0) {
            if (o->p268->v4 < o->s208 + o->p100->v4) {
                o->s208 = 0;
            }
        }
        o->s200 = s->b2;
        o->s202 = s->b1;
        o->s206 = s->b0;
        t = s->s6;
        o->s1fc = t;
        o->v180 = t;
        o->s1fe = s->s4;
        o->f5c = s->f8;
        o->f254 = s->fc;
        v.a = s->s12;
        v.b = s->s10;
        v.c = 0;
        fn_801DD460(o->sub158, &v);
        o->f164 = s->f14;
        o->f258 = s->f18;
        return 1;
    }
    return 0;
}

void fn_800F1644(Obj1644* o)
{
    f32 d[3];
    Path1644* p;
    Pt1644* q;
    s32 i;

    p = fn_801E1A74(1, 0x40);
    if (p != 0) {
        fn_801DCEB0(d, o->dir, 10.0f);
        p->type = 5;
        p->count = 3;
        i = 0;
        q = p->pts;
        do {
            q->x = d[0] * (f32)i;
            q->y = d[1] * (f32)i;
            q->z = d[2] * (f32)i;
            q->a = 1.0f;
            q->b = 0.0f;
            i++;
            q++;
        } while (i < 3);
        if (((p->count - 1) * 0x14 + 0x18) / 4 == 0x10) {
            if (o->h != 0) {
                fn_801E17E0(o->h);
                o->h = 0;
            }
            o->h = fn_801DF450(p, 1);
        }
        fn_801E17E0(p);
    }
}

s32 fn_800FE254(Obj_800FE254* o)
{
    s32 i;
    s32 base = o->idx + 1;
    s32 next;
    u32* t = o->info->tbl;
    s32 n = t[base];

    if (t[9] == 1) {
        if (o->flip != 0) {
            if (o->cur == 0) {
                o->flip = 0;
                o->cur = 1;
            } else {
                o->cur = o->cur - 1;
            }
        } else {
            next = o->cur + 1;
            if (next == t[14]) {
                o->flip = 1;
                o->cur = o->cur - 1;
            } else {
                o->cur = next;
            }
        }
    } else {
        next = o->cur + 1;
        if (next < t[14]) {
            o->cur = next;
        } else {
            o->cur = 0;
        }
    }
    for (i = 0; i < n; i++) {
        if (o->cur == o->info->tbl[base + i + 1]) {
            return 1;
        }
    }
    return 0;
}

void fn_800FF218(void)
{
    s32 i;
    Item* it;
    u8* panel;

    if (lbl_803475D8 == 0) {
        fn_8011D548();
        if (lbl_80346E3C == 0 || lbl_80346E34 == 0) {
            return;
        }
        {
            panel = lbl_80346E3C;
            for (i = 0; i < lbl_80346E38; i++) {
                CampPanelDrawFrame(panel);
                panel += 0xc0;
            }
            it = lbl_80346E34;
            for (i = 0; i < lbl_80346E30; i++) {
                if (it->kind == 0) {
                    fn_801D4F0C(&it->spr, 0, 0, 1, it->f1c, 0.0f, 1.0f, it->f24);
                } else if (it->kind == 1) {
                    fn_801D4C54(&it->spr, 0, 0, 1, it->f1c, 0.0f, it->f20, it->f24);
                } else {
                    fn_801D52A8(&it->spr, 0, 1, it->f1c, 0.0f, 1.0f, it->f24);
                }
                it++;
            }
            lbl_80346E38 = 0;
            lbl_80346E30 = 0;
        }
    }
}

void fn_800FF908(void)
{
    EvObj* c = lbl_80347450;
    if (c == 0) {
        return;
    }
    if (lbl_80347464 != 1) {
        lbl_803474B0[0] = 1;
        lbl_8030A77C[0] = c->pos.x;
        lbl_8030A77C[1] = c->pos.y;
        lbl_8030A77C[2] = c->pos.z;
        lbl_8030A764[0] = c->ang[0];
        lbl_8030A764[1] = c->ang[1];
        lbl_8030A764[2] = c->ang[2];
        if (c->hit != 0) {
            lbl_803474AC[0] = c->hit->id;
        } else {
            lbl_803474AC[0] = -1;
        }
    } else {
        lbl_803474B0[1] = 1;
        lbl_8030A77C[3] = c->pos.x;
        lbl_8030A77C[4] = c->pos.y;
        lbl_8030A77C[5] = c->pos.z;
        lbl_8030A764[3] = c->ang[0];
        lbl_8030A764[4] = c->ang[1];
        lbl_8030A764[5] = c->ang[2];
        if (c->hit != 0) {
            lbl_803474AC[1] = c->hit->id;
        } else {
            lbl_803474AC[1] = -1;
        }
    }
}

void fn_800FFA18(void)
{
    s8 v;

    lbl_80347470 = 1;
    if ("me002z.sct" == 0) {
        fn_801DBE1C("Warp Name Is Illegal!! %s", "me002z.sct");
    }
    strcpy(lbl_80305CF0, "me002z.sct");
    fn_800FF908();
    if (lbl_80347464 == 1 && lbl_80311AC0.w4 == 99) {
        v = 0;
    } else {
        v = lbl_80311AC0.room - 0x61;
    }
    fn_801F7B04(v + lbl_80311AC0.w4 * 10);
    lbl_80347488 = 3.4028235e38f;
    lbl_80311AD4[6] = 15;
    lbl_803475D4 = 1;
    if (lbl_803475D8 != 1 && lbl_80346E48 != 1) {
        fn_801004C4(&lbl_80311AC0, lbl_80305CF0);
    }
    lbl_80311AD4[6] = 15;
}

void fn_80100178(u8 *p) {
    s8 idx;
    if (p == 0) {
        fn_801DBE1C(lbl_802B2348, p);
    }
    strcpy(lbl_80305CF0, (char *)p);
    fn_800FF908();
    if (lbl_80347464 == 1 && lbl_80311AC0.w4 == 0x63) {
        idx = 0;
    } else {
        idx = lbl_80311AC0.room - 0x61;
    }
    fn_801F7B04(idx + lbl_80311AC0.w4 * 10);
    lbl_80347488 = 3.4028235e38f;
    lbl_80311AD4[6] = 15;
    lbl_803475D4 = 1;
    if (lbl_803475D8 != 1 && lbl_80346E48 != 1) {
        fn_801004C4(&lbl_80311AC0, lbl_80305CF0);
    }
}

void fn_80100768(Obj_80100768 *o) {
    Inner *in = o->inner;
    switch (o->state) {
    case 0:
    case 0xfe:
        if (in->p100 != 0) {
            fn_80227810(in->p100);
        }
        o->state = 1;
        break;
    case 1:
        fn_801E671C(in);
        break;
    case 0xff: {
        Inner *q;
        if (in->p100 != 0) {
            fn_802275A4(in->p100, 0);
        }
        q = o->inner;
        if (q->p1bc != 0) {
            fn_80222964(q->p1bc);
            fn_801E1784(q->p1bc);
            q->p1bc = 0;
        }
        fn_801C6170(o);
        if (q->p1c8 != 0) {
            if (*(Obj_80100768 **)(q->p1c8 + 0x38) == o) {
                *(Obj_80100768 **)(q->p1c8 + 0x38) = 0;
                q->p1c8[0x3c] = 0;
            }
        }
        break;
    }
    }
}

void fn_80101158(void) {
    fn_80169294();
    fn_800E3544();
    fn_80192800();
    fn_80230F24();
    fn_80123EB0();
    fn_801CBBF8();
    fn_801DDCA8(lbl_803474EC);
    TaskDelete(lbl_8034749C);
    lbl_8034749C = 0;
    if (lbl_80311AC0.p10 != 0) {
        fn_80109B8C(lbl_80311AC0.p10);
        lbl_80311AC0.p10 = 0;
    }
    fn_80109B8C(lbl_80311AC0.p0c);
    lbl_80311AC0.p0c = 0;
    fn_800C23CC();
    if ((s8)lbl_8030A5D4[1] != 0) {
        fn_801F72F8();
    }
    DrawStatePop(0);
    TaskDelete(lbl_80346E4C);
    lbl_80346E4C = 0;
    fn_80216CD8();
    fn_80109868();
    fn_801CAE8C();
    fn_800CD11C();
    fn_80225EDC();
    fn_801DB9B4();
    fn_802280D4();
    if (lbl_80346E3C != 0) {
        fn_801E17E0(lbl_80346E3C);
        lbl_80346E3C = 0;
    }
    if (lbl_80346E34 != 0) {
        fn_801E17E0(lbl_80346E34);
        lbl_80346E34 = 0;
    }
}

void fn_80101264(void) {
    fn_80225FDC();
    fn_801DDD74(lbl_803474EC, 0x80);
    fn_800CD1F0(0x100);
    lbl_80346E4C = fn_8010CEF8();
    fn_80123EE4();
    CampMenuCreate();
    lbl_803473EC = 1;
    lbl_803473E8 = 0;
    fn_800E3554();
    OSGetTick();
    fn_8025ECBC();
    lbl_80305CF0[0] = 0;
    fn_801DA1C0();
    lbl_80347450 = 0;
    lbl_80347440 = 0;
    fn_80118540();
    lbl_80346E48 = 0;
    fn_801CBC30();
    fn_801195E4();
    if (lbl_80311AC0.w4 == 0x63) {
        lbl_80311AC0.room = lbl_80310A1C[6] + 0x61;
    }
    sprintf((char *)lbl_8030A5D4, lbl_802B2364, lbl_8034746C, lbl_80311AC0.w4, lbl_80311AC0.room);
    lbl_8030A4D4[0] = 0;
    lbl_8030A3D4[0] = 0;
    fn_800972C4();
    fn_801F7958();
    fn_801F7158(lbl_8030A5D4);
    fn_800C24CC();
}

void fn_80101378(void) {
    lbl_80346E38 = 0;
    lbl_80346E30 = 0;
    lbl_80346E3C = fn_801E1C7C(0xf00);
    lbl_80346E34 = fn_801E1C7C(0x1b8);
    lbl_80347464 = fn_800C8D90();
    lbl_8034746C = "/field/";
    fn_801E1D30();
    fn_80226120();
    fn_801DBA0C();
    fn_802280D4();
    fn_8022DCC4();
    DrawStateDefault3D(&lbl_8030A3A0);
    DrawStatePush(&lbl_8030A3A0);
    fn_800D3464();
    ClipZSet(-1.1f, -60000.0f);
    if (lbl_803475B0 != 1 && lbl_80347280 != 1) {
        fn_80227068(0);
    } else {
        fn_80226EFC();
    }
    lbl_80347490 = 0;
    fn_80097CDC();
    TextReset();
    fn_801E74D0();
    fn_80109A4C();
    fn_8008F9A8();
    fn_801692F8();
    fn_801C86D8();
    lbl_8034749C = 0;
    lbl_80311AC0.p10 = 0;
    lbl_80311AC0.p0c = 0;
    lbl_80310B3C[0x22] &= ~0x10000;
    lbl_803473A8 = 0;
    lbl_803472E4 = 0;
    lbl_80347468 = lbl_8030A794 + 0xa0;
}

void fn_80101494(void) {
    if (lbl_80346E3C != 0) {
        fn_801E17E0(lbl_80346E3C);
        lbl_80346E3C = 0;
    }
    if (lbl_80346E34 != 0) {
        fn_801E17E0(lbl_80346E34);
        lbl_80346E34 = 0;
    }
    fn_8022697C(0x7fffffff);
    lbl_80347474 = 1;
    fn_80101158();
    fn_8012A26C();
    fn_8022642C();
    fn_8022642C();
    fn_8022642C();
    lbl_80347450 = 0;
    fn_801E1CCC();
    if (lbl_80310A1C[0x4c] != 'L') {
        lbl_803475D4 = 1;
        lbl_80347488 = 3.4028235e38f;
        if (lbl_803475D8 != 1 && lbl_80346E48 != 1) {
            fn_801004C4(&lbl_80311AC0, lbl_80305CF0);
        }
    }
    if (lbl_80310A1C[0x4c] == 'L') {
        lbl_80310A1C[0x4c] = 0;
        fn_801DBE6C(9);
    } else if (lbl_80346E48 == 0) {
        fn_801DBE6C(6);
    } else {
        fn_801DBE6C(3);
    }
}

void fn_801021EC(f32 *obj, f32 *target, f32 *out) {
    f32 dx, dz, d2, k;
    if (out != 0) {
        out[0] = 0.0f;
        out[1] = 0.0f;
        out[2] = 0.0f;
        if (fn_801C6068(obj, 15) != 0 && target != 0) {
            dz = target[2] - obj[0x40 / 4];
            dx = target[0] - obj[0x38 / 4];
            d2 = dx * dx + dz * dz;
            if (0.0f != d2) {
                f64 s = fabs(fn_801C5C80(obj, 11));
                k = (f32)s * fn_80291978(d2);
                out[0] = dx * k;
                out[1] = 0.0f;
                out[2] = dz * k;
            }
        }
    }
}

void fn_80104B70(Unit_80104B70 *u, Other_80104B70 *o) {
    f32 save;
    if (u == 0) {
        return;
    }
    u->x = u->x + u->vx;
    u->y = u->y + u->vy;
    u->z = u->z + u->vz;
    u->rx = u->rx + u->vrx;
    u->ry = u->ry + u->vry;
    u->rz = u->rz + u->vrz;
    u->f1c = fn_801C60C8(u->f1c, u->f250);
    fn_800D2924(u);
    if (o != 0 && o->sub != 0) {
        save = u->f1c;
        u->f1c = save + o->sub->f1c;
        fn_801E5608(u, u->b21e, u->b21d);
        u->f1c = save;
    } else {
        fn_801E5608(u, u->b21e, u->b21d);
    }
}

void fn_80105058(Task_80105058 *t) {
    Unit_80105058 *u;
    if (t == 0) {
        return;
    }
    u = t->unit;
    if (u == 0) {
        return;
    }
    switch (t->state) {
    case 0:
        fn_80104D64(u);
        t->state = 2;
        break;
    case 1:
    case 3:
    case 5:
        break;
    case 2: {
        NJS_POINT3 p;
        fn_80104B70((Unit_80104B70 *)u, (Other_80104B70 *)t->parent);
        njCalcPoint(0, &u->pos, &p);
        t->f20 = -1000.0f + p.z;
        if (u->f1c <= -1.0f) {
            u->f1c = -1.0f;
            t->state = 4;
        }
        break;
    }
    case 4:
    case 0xff:
        if (fn_801C5FFC(u) != 0) {
            fn_802275A4(u->p100, 0);
        }
        if (t->parent != 0 && t->parent->p24 != 0 && t->parent->p24->p25c != 0 && u->s20c >= 0) {
            t->parent->p24->p25c[u->s20c] = 0;
        }
        fn_80100B74(t);
        break;
    }
}

void fn_801051A0(Unit_801051A0 *u) {
    if (u == 0) {
        return;
    }
    fn_800DE2E4(fn_800DE440((Obj_800DE440 *)u), (u8 *)&u->b1ef, (u8 *)&u->b1f0, &u->b1f1);
    switch (u->state) {
    case 0:
        if (u->b1ef != 0) {
            if (fn_800E0B08((Obj_800E0B08 *)u, u->b1f0) != 0) {
                u->state = 1;
            }
        }
        break;
    case 1:
        if (fn_800DE228(&u->f1c, -0.04f) != 0) {
            u->state = 2;
        }
        break;
    case 2:
        if (u->b1ef == 0 || fn_800E0B08((Obj_800E0B08 *)u, u->b1f0) == 0) {
            u->state = 3;
        }
        break;
    case 3:
        if (fn_800DE228(&u->f1c, 0.04f) != 0) {
            u->state = 0;
        }
        break;
    }
}

void fn_80107B18(Task_80107B18 *t) {
    Unit_80107B18 *u = t->unit;
    switch (t->state) {
    case 0:
        if (fn_801C5FFC(u) != 0) {
            fn_80227810(u->p100);
        }
        u->s16e = 3;
        fn_801173DC(0, u);
        u->s74 = 5;
        fn_8015ED90(t);
        fn_8015C8B8(u, 2);
        t->state = 1;
    case 1:
        if (fn_8015E600(u) == 0) {
            fn_800D2924(u);
            fn_801E5DF0(u);
        }
        break;
    case 2:
    case 4:
        break;
    case 3:
    case 0xff:
        fn_8015EBF4(u);
        if (fn_801C5FFC(u) != 0) {
            fn_802275A4(u->p100, 0);
        }
        fn_80100B74(t);
        break;
    }
}

void fn_80108CC4(Task_80108CC4 *t) {
    Node_80108CC4 *n;
    s32 found;
    switch (t->state) {
    case 0:
    case 0xfe:
        if (lbl_80347450 != 0) {
            n = fn_8022300C(t->work->list);
            if (n != 0) {
                do {
                    if (lbl_80347450->x17a == n->id) {
                        t->state = 10;
                    }
                    n = fn_80222F14(t->work->list, n);
                } while (n != 0);
            }
        }
        break;
    case 10:
        if (lbl_80347450 != 0) {
            found = 0;
            n = fn_8022300C(t->work->list);
            if (n != 0) {
                do {
                    if (lbl_80347450->x17a == n->id) {
                        found = 1;
                    }
                    n = fn_80222F14(t->work->list, n);
                } while (n != 0);
            }
            if (found == 0) {
                fn_80210550(t->work->id);
                t->state = 0;
            }
        }
        break;
    case 0xff:
        fn_80100B74(t);
        break;
    }
}

Entry *fn_801096FC(void *owner, s32 id, u32 ptr, const char *name) {
    Entry *e;
    for (e = lbl_80347460; e != 0; e = e->next) {
        if ((e->id == id && id != 0x7fff) || (e->ptr == ptr && e->ptr != 0)) {
            return 0;
        }
        if (name != 0 && fn_8025EF88(e->name, name) == 0) {
            return 0;
        }
    }
    e = fn_801E1C7C(0x34);
    if (name != 0) {
        fn_801CC434(name, 0, e->name);
    } else {
        e->name[0] = 0;
    }
    e->id = id;
    e->ptr = ptr;
    e->p8 = 0;
    e->owner = owner;
    e->next = lbl_80347460;
    lbl_80347460 = e;
    lbl_8034745C = lbl_8034745C + 1;
    return e;
}

static inline Entry *FindEntry(const char *name) {
    char buf[0x20];
    Entry *e;
    fn_801CC434(name, 0, buf);
    for (e = lbl_80347460; e != 0; e = e->next) {
        if (fn_801E1098(buf, e->name) == 0) {
            return e;
        }
    }
    return 0;
}

void fn_80109A94(const char *name) {
    Entry *e;
    Entry **prev;
    Entry *cur;
    e = FindEntry(name);
    if (e != 0) {
        if (e->ptr != 0) {
            fn_80109B8C((void *)e->ptr);
            return;
        }
        if (e->p8 != 0) {
            fn_801CC0E4(e->p8);
            e->p8 = 0;
        }
        prev = &lbl_80347460;
        for (cur = lbl_80347460; cur != 0; cur = cur->next) {
            if (fn_8025EF88(cur->name, name) == 0) {
                *prev = cur->next;
                fn_801E17E0(cur);
                lbl_8034745C = lbl_8034745C - 1;
                return;
            }
            prev = &cur->next;
        }
    }
}

void fn_8010A740(Task_8010A740 *t) {
    u8 st = t->state;
    Unit2 *u = t->unit;
    Unit2 *w;
    switch (st) {
    case 0:
    case 0xfe:
        fn_8015ED90(t);
        fn_8015EB8C(u, 0xd, fn_8010A530);
        fn_8015C8B8(u, 5);
        w = t->unit;
        w->s172 = 0;
        w->s170 = 0;
        w->f190 = 0.0f;
        w->f18c = 0.0f;
        t->state = 1;
    case 1:
        if (fn_8015E600(u) == 0) {
            if (fn_800D2924(u) == 1) {
                fn_80167690(u);
            }
        }
        break;
    case 2:
    case 0xff:
        fn_8015EBF4(u);
        fn_80100B74(t);
        break;
    }
}

void fn_8010B68C(Queue_8010B68C *q, s16 n) {
    Node_8010B68C *node;
    Node_8010B68C *cur;
    s16 c;
    s16 left = n;
    if (q->count != 0) {
        node = q->head;
        while (node != 0 && left > 0) {
            cur = node;
            node = cur->next;
            if (cur->kind != 0) {
                if (cur->flag != 0 && *cur->flag == 1) {
                    *cur->flag = 2;
                }
                q->count--;
                left--;
                fn_801E17E0(cur);
            } else if (c = cur->cost, left >= c) {
                q->count--;
                left -= c;
                fn_801E17E0(cur);
            } else {
                node = cur;
                break;
            }
        }
        q->head = node;
    }
    q->total = q->total - (s16)(n - left);
}

void fn_8010B78C(Queue_8010B78C *q) {
    Node_8010B78C *node;
    Node_8010B78C *cur;
    if (q->count != 0) {
        node = q->head;
        while (node != 0) {
            cur = node;
            node = cur->next;
            if (cur->flag != 0 && *cur->flag == 1) {
                *cur->flag = 2;
            }
            fn_801E17E0(cur);
        }
        q->count = 0;
        q->tail = 0;
        q->head = 0;
    }
    q->color = 0xffc0c0c0;
    q->s3c = 1;
    q->f4c = 1.0f;
    q->f50 = 1.0f;
    q->s0 = 0;
    q->s10 = 0x20;
    q->s12 = 0x178;
    q->s2 = 0;
    q->s14 = 10;
    q->s16 = 10;
    q->s30 = 0;
    q->s32 = -0x18;
    q->f4 = 0.0f;
    q->total = 0;
    q->s38 = 0;
    q->b56 = 0;
    q->s54 = 0;
    q->s3a = 0;
}

void fn_8010BAE0(Ctx* ctx, const u8** pp) {
    const u8* start = *pp;
    Seg* seg;
    s32 bytes;
    s32 chars;
    u16 c;
    if (TextReadChar(pp) == '(') {
        chars = 0;
        bytes = 0;
        for (;;) {
            c = TextReadChar(pp);
            if (c == ')') {
                seg = fn_8010B88C(ctx, bytes);
                if (seg == NULL) {
                    return;
                }
                if (bytes != 0) {
                    memcpy(seg->text, start + 1, bytes);
                    seg->text[bytes] = 0;
                }
                seg->chars = chars;
                seg->f0c = 1.0f;
                seg->f10 = 1.0f;
                seg->u14 = 0x400;
                ctx->nseg++;
                return;
            }
            if (c >= 0x100) {
                bytes += 2;
                chars++;
            } else if (c >= 0x20) {
                bytes += 1;
                chars++;
            } else {
                bytes += 1;
            }
            if (c == 0) break;
        }
    }
    *pp = start;
    
}

void fn_8010C87C(f32 x, f32 y, f32 w, f32 h, f32 z, u32 colour) {
    VertexCol v[4];
    s32 flag;
    f32 zz;
    f32 x1, y1;
    u32 a = colour & 0xFF000000;
    flag = 1;
    if (a != 0) {
        if (a == 0xFF000000) {
            flag = 0;
        }
        zz = fn_801DBD9C(z);
        y1 = y + h;
        x1 = x + w;
        v[0].x = x;
        v[0].y = y;
        v[0].z = zz;
        v[0].colour = colour;
        v[1].x = x;
        v[1].y = y1;
        v[1].z = zz;
        v[1].colour = colour;
        v[2].x = x1;
        v[2].y = y;
        v[2].z = zz;
        v[2].colour = colour;
        v[3].x = x1;
        v[3].y = y1;
        v[3].z = zz;
        v[3].colour = colour;
        fn_80290ED4(v, 4, flag);
    }
}

void fn_8010CB3C(FadeObj* o, f32 scale) {
    union { u32 w; u8 a; } c;
    f32 y;
    c.w = o->colour;
    if (1.0f > scale) {
        if (0.0f < scale) {
            c.a = (u8)(c.a * scale);
        } else {
            return;
        }
    }
    njColorBlendingMode(0, 8);
    njColorBlendingMode(1, 6);
    if (o->flags & 0x800) {
        fn_8010C87C(0.0f, 0.0f, 640.0f, 480.0f, -1.023f, c.w);
    } else {
        y = o->y - 24.0f;
        fn_8010C87C(0.0f, y, 640.0f, 128.0f, -1.023f, c.w);
        y -= 8.0f;
        fn_8010C7A0(0.0f, y, 640.0f, 8.0f, -1.023f, c.w);
    }
}

s32 fn_800E1894(Obj* o, Target_800E1894* t) {
    NJS_POINT3 d, c, e, f;
    s32 a1, a2, d1;
    d.x = t->pos.x;
    d.y = t->pos.y;
    d.z = t->pos.z;
    c.x = o->a.x;
    c.y = o->a.y;
    c.z = o->a.z;
    njSubVector(&d, &c);
    e.x = d.x;
    e.y = d.y;
    e.z = d.z;
    f.x = o->b.x;
    f.y = o->b.y;
    f.z = o->b.z;
    a1 = fn_801DD4C4(e.x, e.z);
    a2 = fn_801DD4C4(f.x, f.z);
    d1 = (s32)fabsf((f32)(a2 - a1));
    if (!((d1 >= 0 && d1 <= 0x18E4) || (0x10000 - 0x18E5 <= d1 && d1 <= 0xFFFF))) return 0;
    a1 = fn_801DD544(&e);
    a2 = fn_801DD544(&f);
    d1 = (s32)fabsf((f32)(a2 - a1));
    if ((d1 >= 0 && d1 <= 0x18E4) || (0x10000 - 0x18E5 <= d1 && d1 <= 0xFFFF)) return 1;
    return 0;
}

void fn_800F0D5C(void* a, Obj_800F0D5C* o) {
    extern s32 rand(void);
    extern Slot* fn_801C6180(void* a, void* fn);
    extern void fn_800F1780(void);
    s32 m;
    s32 n;
    s32 lo;
    if (o->flags & 0x10) {
        o->timer--;
        if (o->timer <= 0) {
            lo = o->s200;
            n = (s32)((f32)o->s202 * (0.000030517578125f * (f32)rand()) + (f32)lo);
            m = o->s206 - o->s204;
            while (n-- > 0 && m-- > 0) {
                Slot* s = fn_801C6180(a, fn_800F1780);
                if (s != 0) {
                    MemCopy(s->dst, o, 0x270);
                    o->s204++;
                }
            }
            o->timer = o->s1fc;
            if (o->s1fe != 0) {
                o->timer = (s32)((f32)o->s1fe * (0.000030517578125f * (f32)rand()) + (f32)o->timer);
            }
        }
    }
}

void fn_8010092C(Obj_8010092C* o) {
    extern u8 lbl_802B2434[];
    extern void fn_800C3518(Ent* e);
    extern s32 fn_8025EF88(void* a, void* b);
    extern void fn_80222838(void* p);
    extern s32 fn_801E7B2C(void* m, void* a, void* b, f32 frame);
    extern void fn_801E66E0(Ent* e);
    extern void fn_800C3428(void);
    u8 mode = o->mode;
    Ent* e = o->ent;
    switch (mode) {
    case 0:
        fn_800C3518(e);
        if (fn_8025EF88(e->p1c8 + 0x24, lbl_802B2434) == 0) {
            if (e->model != 0 && e->sub != 0) {
                e->f18c = 0.0f;
                e->sub->a = &e->b4;
                e->sub->b = &e->c0;
                e->bc = 0.0f;
                e->b8 = 0.0f;
                e->b4 = 0.0f;
                e->s16c = 1;
                o->mode = 3;
            } else {
                o->mode = 2;
            }
        } else {
            o->mode = 1;
        }
        break;
    case 3:
        fn_80222838(e->sub);
        e->f18c += 1.0f;
        if (e->f18c > (f32)(e->model->count - 1)) {
            e->f18c = 0.0f;
        }
        fn_801E7B2C(e->model, &e->b4, &e->c0, e->f18c);
        break;
    case 1:
        fn_801E66E0(e);
        break;
    case 0xFF:
        fn_800C3428();
        break;
    case 0xFE:
        break;
    }
}

void fn_80103140(Ent_80103140* e, NJS_POINT3* out) {
    extern s32 fn_801C60A4(Ent_80103140* e);
    extern s32 fn_801C6068(Ent_80103140* e, s32 n);
    extern s32 rand(void);
    extern f32 njCos(s32 a);
    extern f32 njSin(s32 a);
    f32 bx, by, bz;
    f32 r;
    s32 ang;
    if (out == 0) return;
    out->x = 0.0f;
    out->y = 0.0f;
    out->z = 0.0f;
    if (e == 0) return;
    if (fn_801C60A4(e) == 0) {
        bx = e->pos.x;
        by = e->pos.y;
        bz = e->pos.z;
    } else {
        bx = e->p1c8->p44.x;
        by = e->p1c8->p44.y;
        bz = e->p1c8->p44.z;
    }
    if (fn_801C6068(e, 12) != 0) {
        r = (f32)e->p1c8->t->count;
        r = r * (0.000030517578125f * (f32)rand());
        ang = (s32)(182.04445f * (360.0f * (0.000030517578125f * (f32)rand())));
        out->x = r * njCos(ang) + bx;
        out->y = by;
        out->z = r * njSin(ang) + bz;
    }
}

static inline void move(Ent_801034BC* e) {
    if (e != 0) {
        e->x += e->vx;
        e->y += e->vy;
        e->z += e->vz;
        fn_801E66E0(e);
    }
}

void fn_801034BC(Obj_801034BC* o) {
    extern s32 fn_801C5FFC(Ent_801034BC* e);
    extern void fn_80227810(void* h);
    extern void fn_802275A4(void* h, s32 n);
    extern void fn_801E66E0(Ent_801034BC* e);
    extern void fn_80100B74(Obj_801034BC* o);
    Ent_801034BC* e;
    if (o == 0) return;
    e = o->ent;
    if (e == 0) return;
    switch (o->mode) {
    case 0:
        if (fn_801C5FFC(e) != 0) fn_80227810(e->h100);
        o->mode = 2;
        break;
    case 2:
        move(e);
        if (e->y <= e->lim) o->mode = 4;
        break;
    case 4:
    case 0xFF:
        if (fn_801C5FFC(e) != 0) fn_802275A4(e->h100, 0);
        if (o->p8 != 0) {
            P* p = o->p8;
            if (p->q != 0) {
                u32* a = p->q->arr;
                if (a != 0) a[e->idx] = 0;
            }
        }
        fn_80100B74(o);
        break;
    case 0xFE:
        break;
    }
}

static inline s32 check(Obj_80105660* o) {
    s32 r = 1;
    if (o != 0) {
        s32 v = 0;
        if (fn_801C6068(o, 0x15) != 0) {
            v = 0;
            if (fn_801C602C(o, 0x13) != 0) v = o->p1c8->t->w50;
        }
        r = (v == 0);
        if (r == 0) r = (o->p1b0->w8 != 0);
    }
    return r;
}

s32 fn_80105660(Obj_80105660* o) {
    extern s32 fn_8015E600(Obj_80105660* o);
    extern s32 fn_801C6068(Obj_80105660* o, s32 n);
    extern s32 fn_801C602C(Obj_80105660* o, s32 n);
    extern void fn_801E5E54(Obj_80105660* o);
    extern void fn_801E5E2C(Obj_80105660* o);
    s32 ret = 1;
    if (o != 0 && o->p1b0 != 0) {
        ret = 0;
        if (fn_8015E600(o) == 0) {
            if (check(o) != 0) fn_801E5E54(o);
            else fn_801E5E2C(o);
            if (o->w198 != 0) o->f190 = 0.0f;
            {
                s32 n = o->w180;
                if (n > 0) n--;
                o->w180 = n;
                if (n <= 0 || ((o->w198 != 0 || o->e8 == 0) && check(o) != 0)) ret = 1;
            }
        }
    }
    return ret;
}

s32 fn_80107C24(Obj_80107C24 *o) {
    s32 ret = 1;
    SeqEnt *e;

    if (o->timer <= 0) {
        o->f190 = o->f24c;
        if (o->state == 1) {
            if (o->cnt > 0) {
                o->f18c = 0.0f;
                o->cnt--;
                if (o->cnt == 0) {
                    SeqTbl *t = o->tbl;
                    o->idx++;
                    e = t->ent;
                    if (t->count > o->idx) {
                        e += o->idx;
                        fn_801E735C(e->b, o, (f32)e->c / 100.0f);
                        o->f24c = o->f190;
                        if (e->a > 0) {
                            o->f190 = 0.0f;
                        }
                        o->timer = e->a;
                        o->cnt = e->d;
                    } else {
                        ret = 0;
                        o->f18c = (f32)o->anim->len - 1.0f;
                        o->f190 = 0.0f;
                        o->f24c = 0.0f;
                    }
                }
            } else {
                o->state = 0;
            }
        }
    } else {
        o->timer--;
    }
    return ret;
}

s8 fn_80108388(Obj_80108388 *o) {
    extern char lbl_802B2478[];
    extern char lbl_802B2490[];
    extern void fn_800C3518(Obj_80108388 *o);
    extern s32 fn_8015F218(Obj_80108388 *o);
    extern void fn_801E735C(s32 a, Obj_80108388 *o, f32 f);
    Info_80108388 *info;
    s32 cnt;
    s32 idx;
    s32 den;
    Sub_80108388 *sub;
    s8 ret = 4;
    s32 r;

    fn_800C3518(o);
    if ((sub = o->sub) != 0 && (info = sub->info) != 0 && (cnt = info->count) > 8) {
        idx = info->f24;
        if (idx == -1 || (idx >= 0x600 && idx <= 0x77f)) {
            o->idx = idx;
            ret = 1;
        } else {
            fn_801DBE1C(lbl_802B2478, idx);
        }
        if (cnt > 9) {
            den = info->f28;
        } else {
            den = 100;
        }
        o->f24c = (f32)den / 100.0f;
    }
    if (ret != 4) {
        switch (fn_8015F218(o)) {
        case 1:
            fn_801E735C(0, o, o->f24c);
            r = 2;
            break;
        case 2:
            fn_801E735C(0, o, -o->f24c);
            o->f190 = 0.0f;
            r = 3;
            break;
        default:
            r = -1;
            break;
        }
        r = (s8)r;
        if (r > 0) {
            ret = r;
        } else {
            o->f18c = 0.0f;
            o->f190 = 0.0f;
        }
    } else {
        fn_801DBE1C(lbl_802B2490, o->f17a);
    }
    return ret;
}

void fn_80108698(Parent_80108698 *p) {
    extern void fn_800D2924(Obj_80108698 *o);
    extern void fn_801E6744(Obj_80108698 *o);
    extern void fn_801E7B2C(Anim *a, f32 *p, f32 *q, f32 t);
    extern void fn_800C3428(Parent_80108698 *p);
    Obj_80108698 *o = p->obj;
    Info_80108698 *info;
    s32 v;

    fn_800D2924(o);
    switch (p->f19) {
    case 0:
    case 0xfe:
        if (o->anim != 0) {
            o->f16c = 1;
            o->f_bc = 0.0f;
            o->f_b8 = 0.0f;
            o->f_b4 = 0.0f;
            o->f18c = 0.0f;
            fn_801E7B2C(o->anim, &o->f_b4, o->f_c0, 0.0f);
            info = o->sub->info;
            if (info->count > 8) {
                v = info->f24;
            } else {
                v = 0;
            }
            if (v <= 0) {
                v = 100;
            }
            o->f190 = 0.01f * (f32)v;
            p->f19 = 2;
        } else {
            p->f19 = 1;
        }
        o->f4 = 0;
        break;
    case 1:
        fn_801E6744(o);
        break;
    case 2:
        fn_801E6744(o);
        o->f18c = o->f18c + o->f190;
        if (o->f18c > (f32)(o->anim->len - 1)) {
            o->f18c = 0.0f;
        }
        fn_801E7B2C(o->anim, &o->f_b4, o->f_c0, o->f18c);
        break;
    default:
        fn_800C3428(p);
        break;
    }
}

void fn_80108828(Parent_80108828 *p) {
    extern void fn_801006C0(Obj_80108828 *o);
    extern void fn_802275A4(void *p, s32 a);
    extern void fn_801E5DF0(Obj_80108828 *o);
    extern void fn_80100B74(Parent_80108828 *p);
    Obj_80108828 *o = p->obj;
    InfoA *a;
    InfoB *b;
    s32 v;

    fn_801006C0(o);
    switch (p->f19) {
    case 0:
    case 0xfe:
        if (o->f100 != 0) {
            fn_80227810(o->f100);
        }
        a = o->sub->infoa;
        o->fe8 = (a->count > 0) ? a->f4 : 0;
        a = o->sub->infoa;
        o->fec = (a->count > 1) ? a->f8 : 0;
        b = o->sub->infob;
        o->f190 = (f32)((b->count > 8) ? b->f24 : 0) / 100.0f;
        b = o->sub->infob;
        v = (b->count > 3) ? b->f10 : 0;
        if (v > 0) {
            p->f20 = -10000.0f + (f32)v;
        }
        p->f19 = 10;
        break;
    case 10:
        fn_801E5DF0(o);
        break;
    case 0xff:
        if (o->f100 != 0) {
            fn_802275A4(o->f100, 0);
        }
        fn_80100B74(p);
        break;
    }
}

void fn_8010AE90(Parent_8010AE90 *p) {
    extern void fn_8010AB60(void);
    extern void fn_8010AC00(Obj_8010AE90 *o);
    extern void fn_8015ED90(Parent_8010AE90 *p);
    extern void fn_8015EB8C(Obj_8010AE90 *o, s32 a, void (*f)(void));
    extern s32 fn_8015E600(Obj_8010AE90 *o);
    extern s32 fn_800D2924(Obj_8010AE90 *o);
    extern void fn_8015EBF4(Obj_8010AE90 *o);
    extern void fn_80227810(Res *r);
    extern void fn_802275A4(Res *r, s32 a);
    extern void fn_801E5608(Obj_8010AE90 *o, s32 a, s32 b);
    extern void fn_80100B74(Parent_8010AE90 *p);
    Obj_8010AE90 *q;
    Obj_8010AE90 *o = p->obj;

    switch (p->f19) {
    case 0:
    case 0xfe:
        fn_8015ED90(p);
        fn_8015EB8C(o, 0xd, fn_8010AB60);
        q = p->obj;
        q->f172 = 0;
        q->f170 = 0;
        fn_80227810(q->res);
        q->f190 = 0.0f;
        q->f18c = 0.0f;
        if (o->attach != 0) {
            o->attach->pos = o->fb4;
            o->attach->rot = o->fc0;
        }
        { f32 x = o->f38.x, y = o->f38.y, z = o->f38.z; o->f24c.z = z; o->f24c.y = y; o->f24c.x = x; }
        { f32 x = o->f44.x, y = o->f44.y, z = o->f44.z; o->f20c.z = z; o->f20c.y = y; o->f20c.x = x; }
        p->f19 = 1;
        /* fallthrough */
    case 1:
        if (fn_8015E600(o) == 0) {
            if (fn_800D2924(o) == 1) {
                if (o->res != 0) {
                    fn_801E5608(o, 0, o->res->f4);
                } else {
                    fn_801E5608(o, 0, 0);
                }
            }
            if (o->attach != 0) {
                fn_8010AC00(o);
            }
        }
        break;
    case 2:
    case 0xff:
        fn_8015EBF4(o);
        if (o->res != 0 && o->res->f0->f8 != 0) {
            fn_802275A4(o->res, 0);
        }
        fn_80100B74(p);
        break;
    }
}

void fn_8010DEE8(Parent_8010DEE8 *p) {
    extern void fn_801E5DF0(Obj_8010DEE8 *o);
    extern void fn_80117748(void);
    u8 st = p->f19;
    Obj_8010DEE8 *o = p->obj;

    switch (st) {
    case 0:
    case 0xfe:
        o->f1c = -1.0f;
        p->f19 = 1;
        p->f20 = -200.0f;
        /* fallthrough */
    case 1:
        if (-1.0f != o->f24c) {
            fn_801E5DF0(o);
            o->f1c = o->f1c + 1.0f / o->f250;
            if (o->f1c >= 0.0f) {
                o->f1c = 0.0f;
                p->f19 = 2;
            }
            break;
        }
        o->f1c = 0.0f;
        p->f19 = 2;
        /* fallthrough */
    case 2:
        fn_801E5DF0(o);
        if (o->state == 1) {
            p->f19 = 0xff;
        }
        if (o->f254 <= o->f18c && o->f254 + o->f190 > o->f18c) {
            p->f19 = 3;
        }
        break;
    case 3:
        fn_801E5DF0(o);
        o->f1c = o->f1c - 1.0f / o->f258;
        if (o->f1c <= -1.0f || o->state == 1) {
            p->f19 = 0xff;
        }
        break;
    case 0xff:
        fn_80117748();
        break;
    }
}

void fn_800D99B4(Obj_800D99B4* o) {
    Work_800D99B4* w = o->work;
    switch (o->state) {
    case 0:
    case 0xFE: {
        Src_800D99B4* src;
        u8 ns;
        fn_800C3518(w);
        src = w->p1c8;
        if (src == 0) {
            ns = 1;
        } else {
            Lst_800D99B4* t;
            Hnd_800D99B4* h = fn_80225B74(0xFFFF, (u16)src->id);
            w->h1b4 = h;
            if (h != 0) {
                h->p1c = w->pos;
                h->p24 = w->rot;
                fn_802233EC(h);
            }
            t = src->c10;
            if (t->count > 0) {
                if (t->id >= 0) {
                    w->p25c = fn_80225B74(0xFFFF, (u16)t->id);
                } else {
                    w->p25c = 0;
                }
            }
            ns = 1;
        }
        o->state = ns;
        break;
    }
    case 1: {
        Hnd_800D99B4* h = w->h1b4;
        if (h != 0) {
            fn_802234D4(h);
            if (w->p25c != 0) {
                fn_80223628(w->pos, w->pos, w->p25c);
                if (w->pos[0] != h->v[0] || w->pos[1] != h->v[1] || w->pos[2] != h->v[2]) {
                    h->flags |= 1;
                }
            }
        }
        if (w->e4 != 0) {
            if (fn_800D2924(w) != 0) {
                fn_801E5DF0(w);
            }
        }
        break;
    }
    default: {
        Src_800D99B4* src = w->p1c8;
        if (src != 0) {
            Hnd_800D99B4* h = fn_80225B74(0xFFFF, (u16)src->id);
            if (h != 0) {
                if (h->p1c == w->pos) {
                    h->p1c = h->v;
                }
                if (h->p24 == w->rot) {
                    h->p24 = (u8*)h + 0x48;
                }
            }
        }
        fn_800C3428(o);
        break;
    }
    }
}

void fn_800D9BA0(Task* o) {
    EvObj* w = o->work;
    IVec_800D9BA0 k;
    Vec_800D9BA0 v;
    k.x = w->b16a;
    k.y = 0;
    k.z = w->b16b;
    fn_80090B68(&k, &v);
    if (lbl_80347450 != 0) {
        fn_80090BE4(&lbl_80347450->pos.x, &k);
    } else {
        return;
    }
    if (w->mapMode->mode != 0) {
        o->state = 0xFF;
    } else if (lbl_80347450 == 0) {
        return;
    }
    switch (o->state) {
    case 0:
        w->home.x = w->pos.x - v.x;
        w->home.y = w->pos.y;
        w->home.z = w->pos.z - v.z;
        o->f20 = -1.3f;
        o->state++;
        break;
    case 1:
        fn_80090A7C(&lbl_80347450->pos.x, &v);
        w->pos.x = (w->home.x + v.x) - 2400.0f * (f32)k.x;
        w->pos.y = w->home.y;
        w->pos.z = (w->home.z + v.z) - 2400.0f * (f32)k.z;
        if (fn_800E126C(w) != 0) {
            o->state++;
        }
        break;
    case 2:
        fn_80090A7C(&lbl_80347450->pos.x, &v);
        w->pos.x = (w->home.x + v.x) - 2400.0f * (f32)k.x;
        w->pos.y = w->home.y;
        w->pos.z = (w->home.z + v.z) - 2400.0f * (f32)k.z;
        fn_800E126C(w);
        if (lbl_8030CEA0.x1874 != 1) {
            lbl_80347444 = 0;
            o->state--;
        }
        break;
    case 0xFF:
        fn_80100B74(o);
        break;
    }
}

void fn_800DE00C(Obj_800DE00C* o) {
    extern void fn_8015ED90(void* w);
    extern s32 fn_8015F218(void* w);
    extern void fn_8015E600(void* w);
    extern void fn_8015EBF4(void* w);
    extern void fn_802275A4(s32 a, s32 b);
    extern void fn_800DDE98(s32 a, s32 b, s32 c, s32 d, s32 e, f32 f1, f32 f2, s32 g);
    Work_800DE00C* w = o->work;
    switch (o->state) {
    case 0:
        w->x = 640.0f;
        w->y = 72.0f;
        w->z = -1.09f;
        w->s100 = w->p1c8->v20;
        fn_8015ED90(o);
        o->state = 3;
    case 3:
        switch (fn_8015F218(w)) {
        case 1:
            o->state = 1;
            break;
        }
        fn_8015E600(w);
        break;
    case 1: {
        f32 d;
        fn_8015E600(w);
        d = 0.2f * (320.0f - w->x);
        fn_800DDE98((s32)w->x, (s32)w->y, (s32)(256.0f + w->x), (s32)(256.0f + w->y), w->s100, w->f1c, w->z, 0);
        w->x = w->x + d;
        switch (fn_8015F218(w)) {
        case 2:
            o->state = 4;
            break;
        }
        break;
    }
    case 4:
        fn_800DDE98((s32)w->x, (s32)w->y, (s32)(256.0f + w->x), (s32)(256.0f + w->y), w->s100, w->f1c, w->z, 0);
        w->f1c = w->f1c - 0.06666667f;
        if (w->f1c < -1.0f) {
            o->state = 3;
        }
        break;
    case 2:
    case 0xFF:
        fn_8015EBF4(w);
        fn_802275A4(w->s100, 0);
        fn_80100B74(o);
        break;
    case 0xFE:
        break;
    }
}

void fn_800ED360(void) {
    if (lbl_80346DF4->active != 0 && ((*(u32(*)[0xd58 / 4])&lbl_80310B3C)[0xcc / 4] & 0x80000000) == 0) {
        switch (lbl_80346DF4->mode) {
        case 0:
            fn_80210450("Fship");
            if (lbl_80346DF4 != 0 && lbl_80305C78.flag != 0) {
                lbl_80305C78.v = lbl_80346DF4->active;
                lbl_80346DF8->state = 3;
                lbl_80305C78.flag = 0;
            }
            lbl_80346DF4->mode = -1;
            lbl_80305C78.cell[lbl_80305C78.x][lbl_80305C78.y] |= 0x40;
            break;
        case 1:
            fn_80210450("Item1");
            lbl_80346DF4->mode = -1;
            lbl_80305C78.cell[lbl_80305C78.x][lbl_80305C78.y] |= 0x40;
            break;
        case 2:
            fn_80210450("Item2");
            lbl_80346DF4->mode = -1;
            lbl_80305C78.cell[lbl_80305C78.x][lbl_80305C78.y] |= 0x40;
            break;
        case 3:
            fn_80210450("Hazure");
            if (lbl_80346DF4 != 0 && lbl_80305C78.flag != 0) {
                lbl_80305C78.v = lbl_80346DF4->active;
                lbl_80346DF8->state = 3;
                lbl_80305C78.flag = 0;
            }
            lbl_80346DF4->mode = -1;
            break;
        default:
            lbl_80346DF4->active = 0;
            lbl_80346DF8->state = 1;
            break;
        }
    }
}

void fn_800F2270(Obj_800F2270* o, u8 dir, Vec_800F2270* out) {
    extern Vec_800F2270 lbl_802B21B0[8];
    extern Vec_800F2270 lbl_802B2210;
    extern s32 fn_801C6068(Obj_800F2270* o, s32 n);
    extern void fn_801C5AB4(Obj_800F2270* o, Angle* out);
    extern void njScale(NJS_MATRIX m, f32 x, f32 y, f32 z);
    extern void njCalcVector(NJS_MATRIX m, Vec_800F2270* in, Vec_800F2270* out);
    NJS_MATRIX m;
    Vec_800F2270 v;
    Angle rot[3];
    f32 scale;
    if (o != 0) {
        scale = 4.0f * (f32)o->ext->info->size;
        if (fn_801C6068(o, 14) == 0) {
            out->x = o->x;
            out->y = o->y;
            out->z = o->z;
        } else {
            dir = dir % 4;
            switch (o->ext->info->kind) {
            case 5:
            case 6:
                v = lbl_802B21B0[dir + 4];
                break;
            case 7:
            case 8:
                v = lbl_802B21B0[dir];
                break;
            default:
                v = lbl_802B2210;
                break;
            }
            njUnitMatrix(m);
            fn_801C5AB4(o, rot);
            njRotateXYZ(m, rot[0], rot[1], rot[2]);
            njScale(m, scale, scale, scale);
            njCalcVector(m, &v, &v);
            out->x = o->ext->ox + v.x;
            out->y = o->ext->oy + v.y;
            out->z = o->ext->oz + v.z;
        }
    }
}

static inline void InitVec_801022FC(f32* v, Ent_801022FC* e) {
    if (v != 0) {
        v[0] = 0.0f;
        v[1] = 0.0f;
        v[2] = 0.0f;
        if (fn_801C6068(e, 15) != 0) {
            v[0] = (f32)e->p1c8->t->f24;
            v[1] = (f32)e->p1c8->t->f28;
            v[2] = (f32)e->p1c8->t->f2c;
        }
    }
}

void fn_801022FC(Ent_801022FC* e) {
    extern void fn_801173DC(s32 a, Ent_801022FC* e);
    extern s32 fn_801C60A4(Ent_801022FC* e);
    extern s32 fn_801C6068(Ent_801022FC* e, s32 n);
    extern f32 fn_801C5C80(Ent_801022FC* e, s32 n);
    extern void fn_80222838(void* p);
    f32 a;
    f32 b;
    f32 c;
    s32 ang;
    if (e != 0) {
        fn_801173DC(0, e);
        e->f74 = 5;
        if (fn_801C60A4(e) != 0) {
            e->px = e->p1c8->x;
            e->py = e->p1c8->y;
            e->pz = e->p1c8->z;
        }
        a = 0.0f;
        if (e != 0) {
            a = 12.5f;
        }
        e->f250 = a;
        e->f70 = e->f6c = e->f68 = ang = 0;
        if (fn_801C6068(e, 15) != 0) {
            ang = (s32)(182.04445f * (f32)e->p1c8->t->f3c);
        }
        e->f68 = ang;
        b = 0.0f;
        if (fn_801C6068(e, 15) != 0) {
            b = fn_801C5C80(e, 12);
        }
        e->f254 = b;
        c = 0.0f;
        if (fn_801C6068(e, 15) != 0) {
            c = fn_801C5C80(e, 13);
        }
        e->f258 = c;
        e->f1ec = 0;
        e->f180 = 0;
        InitVec_801022FC(&e->v104, e);
        fn_80222838(e->f1bc);
    }
}

void fn_8010427C(Obj_8010427C* o) {
    extern s32 fn_800D2924(Ent_8010427C* e);
    extern s32 fn_801C5FFC(Ent_8010427C* e);
    extern void fn_80227810(void* h);
    extern void fn_802275A4(void* h, s32 n);
    extern void fn_801173DC(s32 a, Ent_8010427C* e);
    extern void fn_801E5DF0(Ent_8010427C* e);
    extern void fn_8029CE6C(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
    extern void fn_80100B74(Obj_8010427C* o);
    Ent_8010427C* e;
    if (o == 0 || (e = o->d) == 0) return;
    if (o->mode != 0xfe && o->mode != 0xff && o->mode != 0 && o->mode != 3) {
        if (fn_800D2924(e) == 0) {
            return;
        }
    }
    switch (o->mode) {
    case 0: {
        s32 v;
        if (fn_801C5FFC(e) != 0) {
            fn_80227810(e->h100);
        }
        fn_801173DC(0, e);
        e->f74 = 5;
        v = (e->p1c8->t->count > 3) ? e->p1c8->t->f10 : 0;
        if (v > 0) {
            o->f20 = -10000.0f + (f32)v;
        }
        o->mode = 1;
        break;
    }
    case 1: {
        s32 v = (e->p1c8->t->count > 4) ? e->p1c8->t->f14 : 0;
        if ((v & 4) != 0) {
            fn_8029CE6C(6, 0x80, 0, 6, 0x80, 1);
            fn_801E5DF0(e);
            fn_8029CE6C(4, 0, 0, 7, 0, 1);
        } else {
            fn_801E5DF0(e);
        }
        break;
    }
    case 0xfe:
        break;
    case 3:
    case 0xff:
        if (fn_801C5FFC(e) != 0) {
            fn_802275A4(e->h100, 0);
        }
        fn_80100B74(o);
        break;
    }
}

static inline void Cleanup_80107904(Obj_80107904 *self)
{
    if (self != 0) {
        if (self->p1b0 != 0) {
            self->p1b0->w4 = 0;
            fn_801DD95C(self->p1b0);
            self->p1b0 = 0;
        }
        if (self->p1ac != 0) {
            fn_801DD9AC(&(*(s32*)&lbl_803474EC), self->p1ac);
            self->p1ac = 0;
        }
    }
}

s32 fn_80107904(Obj_80107904 *self, s16 *v, u32 a, s16 b, void *c, void *d)
{
    if (self != 0 && c != 0 && d != 0 && a != 0) {
        if (self->p1ac == 0) {
            if (v != 0 && v[0] == 0 && v[1] == 0) {
                v = 0;
            }
            self->p1ac = fn_801DDAB0(&(*(s32*)&lbl_803474EC), self->pe4, d, self->p100, v);
            if (self->p1ac == 0) {
                Cleanup_80107904(self);
                return 0;
            }
        }
        if (self->p1b0 == 0) {
            self->p1b0 = fn_801DD984();
            if (self->p1b0 == 0) {
                Cleanup_80107904(self);
                return 0;
            }
        }
        if (self->p1b0->w4 == 0) {
            self->p1b0->w4 = c;
            if (self->p1b0->w4 == 0) {
                Cleanup_80107904(self);
                return 0;
            }
            self->p1b0->s2 = a;
            self->p1b0->s10 = b;
            fn_801E5F1C(self, 1);
            return 1;
        }
    }
    return 0;
}

void fn_801081BC(Obj_801081BC *self)
{
    extern char lbl_802B2460[0x18];
    extern void fn_800D2924(void *p);
    extern s32 fn_80107D90(void *p);
    extern s32 fn_80107C24(void *p);
    extern void fn_80107EF0(void *p);
    extern void fn_801E7E14(void *o, s16 a, s16 b, s32 mode);
    extern void fn_801E5DF0(void *p);
    extern u32 *fn_80100684(u16 id, s32 n);
    extern void fn_800C3428(void *p);
    Sub_801081BC *s = self->sub;
    s16 m;
    u32 *r;

    switch (self->state) {
    case 0:
    case 0xFE:
        fn_80107EF0(self);
        break;
    case 1:
        fn_800D2924(s);
        if (fn_80107D90(self) != 0) {
            if (self->state == 4) {
                break;
            }
        } else {
            m = s->s1fc;
            if (m >= 0) {
                fn_801E7E14(s->pe4, s->s1fe, s->s200, m);
            }
            fn_801E5DF0(s);
            break;
        }
    case 2:
        m = s->s1fc;
        if (m >= 0) {
            fn_801E7E14(s->pe4, s->s1fe, s->s200, m);
        }
        fn_801E5DF0(s);
        if (fn_80107C24(s) == 0) {
            self->state = 1;
        }
        break;
    case 3:
        fn_800D2924(s);
        if (fn_80107D90(self) != 0) {
            if (self->state == 4) {
                break;
            }
        }
        m = s->s1fc;
        if (m >= 0) {
            fn_801E7E14(s->pe4, s->s1fe, s->s200, m);
        }
        fn_801E5DF0(s);
        if (fn_80107C24(s) == 0) {
            self->state = 1;
        }
        break;
    case 4:
        fn_80107D90(self);
        break;
    case 5:
        fn_801DBE1C(lbl_802B2460, s->h17a);
        break;
    default:
        r = fn_80100684(*(u32 *)(s->p1c8 + 4), 4);
        if (r != 0) {
            *r = s->w23c;
        }
        fn_800C3428(self);
        break;
    }
}

void fn_8010A55C(Obj_8010A55C *self)
{
    extern void fn_8015ED90(void *p);
    extern void fn_8015EB8C(void *p, s32 id, void *cb);
    extern void fn_8015C8B8(void *p, s32 n);
    extern s32 fn_8015E600(void *p);
    extern s32 fn_800D2924(void *p);
    extern void fn_80167690(void *p);
    extern void fn_8015EBF4(void *p);
    extern void fn_80100B74(void *p);
    extern s32 fn_8010A530(void *a, void *b);
    Sub_8010A55C *s = self->sub;
    Sub_8010A55C *t;
    f32 zero;

    switch (self->state) {
    case 0:
    case 0xFE:
        fn_8015ED90(self);
        fn_8015EB8C(s, 0xD, (void *)fn_8010A530);
        fn_8015C8B8(s, 5);
        t = self->sub;
        t->h172 = 0;
        t->h170 = 0;
        t->speed = 0.0f;
        t->pos = 0.0f;
        self->state = 1;
    case 1:
        if (fn_8015E600(s) != 0) {
            break;
        }
        if (fn_800D2924(s) == 1) {
            fn_80167690(s);
        }
        if (s->pe8 != 0) {
            s->pos = s->pos + s->speed;
            zero = 0.0f;
            if (zero > s->speed) {
                if (zero > s->pos) {
                    s->wrapped = 1;
                    do {
                        s->pos = (f32)s->pe8->len + s->pos;
                    } while (s->pos < zero);
                }
            } else {
                if (s->pos > (f32)s->pe8->len - 1.0f) {
                    s->wrapped = 1;
                    if (s->pos >= (f32)s->pe8->len) {
                        s->pos = zero;
                    }
                }
            }
        } else {
            s->wrapped = 1;
        }
        break;
    case 2:
    case 0xFF:
        fn_8015EBF4(s);
        fn_80100B74(self);
        break;
    }
}

void fn_8010B038(Obj_8010B038 *self)
{
    Sub_8010B038 *s = self->sub;
    Sub_8010B038 *t;
    s32 c;

    ClipZPush();
    c = s->p1c8->cnt->count > 4 ? s->p1c8->cnt->w14 : 0;
    if ((c & 4) != 0) {
        lbl_80346788 = lbl_80347560;
        lbl_8034678C = -25000.0f;
        njClipZ(lbl_80346788, lbl_8034678C);
    }
    switch (self->state) {
    case 0:
    case 0xFE:
        fn_8015ED90(self);
        fn_8015EB8C(s, 0xD, (void *)fn_8010ABD4);
        t = self->sub;
        t->h172 = 0;
        t->h170 = 0;
        fn_80227810(t->p100);
        t->speed = 0.0f;
        t->pos = 0.0f;
        self->state = 1;
        c = s->p1c8->cnt->count > 3 ? s->p1c8->cnt->w10 : 0;
        if (c > 0) {
            self->f20 = (f32)-c;
        }
    case 1:
        if (fn_8015E600(s) != 0) {
            break;
        }
        if ((*(s32(*)[5])&lbl_80311AC0)[0] == 0x223) {
            if (s->h17a != 0xAFC8) {
                if (s->h17a == 0xAFC8) {
                    s->h176 = 0x8000;
                }
            }
        }
        if (fn_800D2924(s) == 1) {
            if (s->p100 != 0) {
                fn_801E5608(s, 0, s->p100->nbTexture);
            } else {
                fn_801E5608(s, 0, 0);
            }
        }
        break;
    case 2:
    case 0xFF:
        fn_8015EBF4(s);
        if (s->p100 != 0 && s->p100->textures->texaddr != 0) {
            fn_802275A4(s->p100, 0);
        }
        fn_80100B74(self);
        break;
    }
    ClipZPop();
}

s32 fn_8010CF78(Menu_8010CF78 *m) {
    s32 ret = 6;

    if (((*(PadState *(*)[6])&lbl_80311A60)[lbl_8034757C]->flags & 0xc) && m->f22 != 0) {
        m->f22 = 1;
    }
    if (m->f22 <= 0) {
        s32 i = lbl_8034757C;
        u32 fl = (*(PadState *(*)[6])&lbl_80311A60)[i]->flags;

        if ((fl & 0xc) || lbl_80311A14[i].b3 > 15 || lbl_80311A14[i].b2 > 15) {
            if ((fl & 8) || lbl_80311A14[i].b3 > 15) {
                m->f1c--;
                if (m->f1c < 0) {
                    m->f1c = m->f20 - 1;
                }
            } else {
                m->f1c++;
                if (m->f20 <= m->f1c) {
                    m->f1c = 0;
                }
            }
            fn_8010C384(m->p40, m->f1c, m->f38);
            m->slot->x8 = m->f1c;
            SePlay(1, 1, 0);
        }
        if ((*(PadState *(*)[6])&lbl_80311A60)[lbl_8034757C]->flags & 0x100) {
            m->f1a = 2;
            ret = 4;
            SePlay(1, 1, 2);
        }
    } else {
        m->f22--;
    }
    (*(Menu_8010CF78 **)&lbl_80346E60) = m;
    return ret;
}

static inline Rec_800F1264* lookup(Obj_800F1264* o, s32 id) {
    Rec_800F1264* r = 0;
    if (o->p1c8 != 0) {
        Tbl* t = o->p1c8->t;
        if (t->count > 8) r = fn_800D51C0((u8*)t + 0x24, id);
    }
    return r;
}

void fn_800F1264(Ctl* c, Obj_800F1264* o) {
    s32 ok = 0;
    Rec_800F1264* a = lookup(o, 2);
    Rec_800F1264* b;
    if (a != 0) {
        s32 f;
        u32 k = (u32)(a->n * 8 + 4) >> 2;
        u32 v = a->s0;
        o->dst = (u8*)(o->w20c = f = 0);
        if (v == k && o->src != 0 && *o->src == a->n) {
            o->w20c = a->s6;
            o->dst = (u8*)a + 4;
            f = 1;
        }
        ok = f;
    }
    b = lookup(o, 5);
    if (ok != 0 && b != 0) {
        MemCopy((u8*)o->src + 4, o->dst + 4, *o->src * 8);
        o->dst = (u8*)b + 4;
        if (c->mode == 0) {
            o->w20c = 1;
            fn_800F0C68((void *)(o));
            c->mode = 1;
        } else {
            o->flags |= 8;
            o->s20a = 1;
            c->mode = 3;
        }
    } else {
        c->mode = 1;
    }
}

void fn_8010850C(Parent_8010850C *p) {
    Obj_8010850C *o = p->obj;
    s8 r;

    fn_800D2924((void *)(o));
    if (p->f19 >= 1 && p->f19 <= 3) {
        switch (fn_8015F218(o)) {
        case 1:
            fn_801E735C(0, (void *)(o), o->f24c);
            r = 2;
            break;
        case 2:
            fn_801E735C(0, (void *)(o), -o->f24c);
            o->f190 = 0.0f;
            r = 3;
            break;
        default:
            r = -1;
            break;
        }
        if (r > 0) {
            p->f19 = r;
        }
    }
    switch (p->f19) {
    case 0:
    case 0xfe:
        p->f19 = fn_80108388((void *)(o));
        break;
    case 1:
        fn_801E5DF0((void *)(o));
        break;
    case 2:
        fn_801E5DF0((void *)(o));
        if (o->state == 1) {
            if (o->idx >= 0x600) {
                (*(u32(*)[])&lbl_80310B3C)[(u32)o->idx >> 5] |= 1 << (o->idx & 0x1f);
            }
            fn_801E735C(0, (void *)(o), -o->f24c);
            o->f190 = 0.0f;
            p->f19 = 3;
        }
        break;
    case 3:
        fn_801E5DF0((void *)(o));
        break;
    default:
        fn_800C3428((void *)(p));
        break;
    }
}

s32 fn_8010D12C(Menu *m) {
    s32 ret = 4;
    u16 f = m->flags;

    if (f & 0x10) {
        m->f1a--;
        if (m->f1a <= 0) {
            m->f38++;
            fn_8010C2AC((void *)(m), m->f38);
            m->flags &= 0xffef;
            if (m->flags & 0x80) {
                ret = 7;
            } else if (m->flags & 0x200) {
                ret = 5;
            } else {
                ret = 8;
            }
        }
    } else if (!(f & 0x40)) {
        if (((*(PadState *(*)[6])&lbl_80311A60)[lbl_8034757C]->flags & 0x100) || ((*(u32(*)[])&lbl_80310B3C)[33] & 0x40000000)) {
            if (f & 0x80) {
                ret = 7;
            } else if (f & 0x200) {
                ret = 5;
            } else {
                ret = 8;
            }
            m->flags &= 0xeff7;
            SePlay(1, 1, 1);
        }
    } else {
        m->f1a--;
        if (m->f1a <= 0) {
            ret = 5;
            m->flags &= 0xffbf;
        }
    }
    (*(Menu **)&lbl_80346E60) = m;
    return ret;
}

void fn_800D9E00(Task* o) {
    EvObj* w = o->work;
    IVec_800D9E00 k;
    Vec_800D9E00 v;
    k.x = w->b16a;
    k.y = 0;
    k.z = w->b16b;
    fn_80090B68((void *)(&k), (void *)(&v));
    if (lbl_80347450 != 0) {
        fn_80090BE4((void *)(&lbl_80347450->pos.x), (void *)(&k));
    } else {
        return;
    }
    if (w->mapMode->mode != 0) {
        o->state = 0xFF;
    } else if (lbl_80347450 == 0) {
        return;
    }
    ClipZPush();
    {
        f32 near = lbl_80347560;
        f32 far = -1200.0f;
        lbl_80346788 = near;
        lbl_8034678C = far;
        njClipZ(near, far);
    }
    if (lbl_80346DA0[0] != 0) {
        lbl_80346DA0[0]--;
    } else if ((lbl_8034740C & 0x7F00) == 0xD00 && o->state != 0xFF) {
        fn_800DA010(o);
        lbl_80346DA0[0] = 15;
    }
    switch (o->state) {
    case 0:
        w->pos.x = w->pos.x - v.x;
        w->pos.z = w->pos.z - v.z;
        w->home.x = w->pos.x;
        w->home.y = w->pos.y;
        w->home.z = w->pos.z;
        w->clipNear = -800.0f;
        w->clipFar = -1200.0f;
        fn_800B2C1C(o);
        fn_800B2DA0(w, 0xFF40D060);
        break;
    default:
        fn_80090A7C((void *)(&lbl_80347450->pos.x), (void *)(&v));
        w->pos.x = (w->home.x + v.x) - 2400.0f * (f32)k.x;
        w->pos.y = w->home.y;
        w->pos.z = (w->home.z + v.z) - 2400.0f * (f32)k.z;
        fn_800B2C1C(o);
        break;
    case 0xFF:
        fn_800B2C1C(o);
        break;
    }
    ClipZPop();
}

void fn_800EA244(s16 flag) {
    f32 y = -10000.0f;
    f32 s = (*(Work_800EA244**)&lbl_80346DCC)->f4c;
    Sprite* it;
    it = fn_801D68C4((*(Work_800EA244**)&lbl_80346DCC)->sub, 0);
    fn_801D4F0C(it, 0, 0, 0, -10000.0f, 0.0f, s, 1.0f);
    y += 0.05f * (f32)it->count;
    if (flag != 0) {
        it = fn_801D68C4((*(Work_800EA244**)&lbl_80346DCC)->sub, 2);
    } else {
        it = fn_801D68C4((*(Work_800EA244**)&lbl_80346DCC)->sub, 1);
    }
    fn_801D4F0C(it, 0, 0, 0, y, 0.0f, s, 1.0f);
    y += 0.05f * (f32)it->count;
    it = fn_801D68C4((*(Work_800EA244**)&lbl_80346DCC)->sub, 3);
    fn_801D4F0C(it, 0, 1, 1, y, 0.0f, s, 1.0f);
    y += 0.05f * (f32)it->count;
    it = fn_801D68C4((*(Work_800EA244**)&lbl_80346DCC)->sub, 4);
    fn_801D4F0C(it, 0, 0, 0, y, 0.0f, s, 1.0f);
    y += 0.05f * (f32)it->count;
    it = fn_801D68C4((*(Work_800EA244**)&lbl_80346DCC)->sub, 5);
    fn_801D4F0C(it, 0, 0, 1, y, 0.0f, s, 1.0f);
    y += 0.05f * (f32)it->count;
    it = fn_801D68C4((*(Work_800EA244**)&lbl_80346DCC)->sub, 0xb);
    fn_801D4F0C(it, 0, 0, 1, y, 0.0f, 1.0f, 1.0f);
}

s32 fn_800EB58C(s32 mode) {
    switch (mode) {
    case 1:
        lbl_80346DF8 = fn_802268E8(lbl_803475A8, fn_800EB754);
        lbl_80346DF8->work = fn_801E1C7C(0x4d58);
        memset(lbl_80346DF8->work, 0, 0x4d58);
        lbl_80346DF8->state = 0;
        lbl_80346DF4 = lbl_80346DF8->work;
        lbl_80346DF0 = &lbl_80346DF4->board;
        lbl_80346DF4->first = 0;
        lbl_80346DE8 = 1;
        break;
    case 2:
        lbl_80346DF8 = fn_802268E8(lbl_803475A8, fn_800EB754);
        lbl_80346DF8->work = fn_801E1C7C(0x4d58);
        memset(lbl_80346DF8->work, 0, 0x4d58);
        lbl_80346DF8->state = 0;
        lbl_80346DF4 = lbl_80346DF8->work;
        lbl_80346DF0 = &lbl_80346DF4->board;
        lbl_80346DF4->first = 1;
        lbl_80346DE8 = 1;
        break;
    case 3:
        if (lbl_80346DF4 != 0) {
            if (lbl_80305C78.flag != 0) {
                lbl_80305C78.v = lbl_80346DF4->active;
                lbl_80346DF8->state = 3;
                lbl_80305C78.flag = 0;
            }
        }
        break;
    case 4:
        fn_801D89D4(&lbl_80346DF4->base, 10, 0, lbl_80346DF4->base.x, lbl_80346DF4->base.y, 0.0f, 0.0f, 0.0f, -224.0f, 0.0f, 0.0f);
        break;
    case 5:
        fn_801D89D4(&lbl_80346DF4->base, 10, 0, lbl_80346DF4->base.x, lbl_80346DF4->base.y, 0.0f, 0.0f, 200.0f, -224.0f, 0.0f, 0.0f);
        break;
    }
    return 0;
}

static inline Node_80109868 *Find_80109868(void *key)
{
    Node_80109868 *p;
    for (p = (*(Node_80109868 **)&lbl_80347460); p != 0; p = p->next) {
        if ((void *)p->sub == key) {
            return p;
        }
    }
    return 0;
}

static inline void Unlink_80109868(u32 b)
{
    u8 **link;
    u8 *n;
    u8 *base;
    s32 count;
    u32 idx;
    u8 *sub;
    u8 *node;

    link = (u8 **)&(*(Node_80109868 **)&lbl_80347460);
    n = (u8 *)(*(Node_80109868 **)&lbl_80347460);
    while (n != 0) {
        if (*(u32 *)(n + 4) == b) {
            *link = *(u8 **)(n + 0x30);
            fn_801E17E0((void *)(n));
            lbl_8034745C -= 1;
            break;
        }
        link = (u8 **)(n + 0x30);
        n = *link;
    }

    if (lbl_80346E58 == 0) return;
    if (lbl_80346E58 != 0) memset((void *)(lbl_80346E58), 0, 0x40000);

    node = (u8 *)(*(Node_80109868 **)&lbl_80347460);
    while (node != 0) {
        sub = *(u8 **)(node + 4);
        if (lbl_80346E58 != 0 && sub != 0) {
            base = *(u8 **)(sub + 4);
            count = *(s32 *)sub;
            do {
                idx = *(u32 *)(base + 4);
                if (idx < 0x10000) {
                    ((u8 **)lbl_80346E58)[idx] = base;
                }
                base += 0x68;
            } while (--count != 0);
        }
        node = *(u8 **)(node + 0x30);
    }
    fn_8014912C();
}

void fn_80109868(void)
{
    Node_80109868 *n;
    Node_80109868 *p;
    void *h;

    while ((*(Node_80109868 **)&lbl_80347460) != 0) {
        if ((*(Node_80109868 **)&lbl_80347460)->flag == 0 || (*(Node_80109868 **)&lbl_80347460)->v2c == 1) {
            if ((*(Node_80109868 **)&lbl_80347460)->sub != 0) {
                Unlink_80109868((u32)(*(Node_80109868 **)&lbl_80347460)->sub);
            }
        }
        if ((*(Node_80109868 **)&lbl_80347460)->flag == 0 && (*(Node_80109868 **)&lbl_80347460)->v2c != 0) {
            continue;
        }
        if ((*(Node_80109868 **)&lbl_80347460)->sub != 0) {
            if ((*(Node_80109868 **)&lbl_80347460)->p8 != 0) {
                h = fn_801CC0A0((*(Node_80109868 **)&lbl_80347460)->p8);
                if (h != 0) {
                    p = Find_80109868(h);
                    p->p8 = 0;
                }
                (*(Node_80109868 **)&lbl_80347460)->p8 = 0;
            }
            fn_80109B8C((void *)((*(Node_80109868 **)&lbl_80347460)->sub));
        } else {
            if ((*(Node_80109868 **)&lbl_80347460)->p8 != 0) {
                fn_801CC0E4((*(Node_80109868 **)&lbl_80347460)->p8);
                (*(Node_80109868 **)&lbl_80347460)->p8 = 0;
            }
            n = (*(Node_80109868 **)&lbl_80347460);
            (*(Node_80109868 **)&lbl_80347460) = n->next;
            fn_801E17E0((void *)(n));
        }
    }
    lbl_8034745C = 0;
    if (lbl_80346E58 != 0) memset((void *)(lbl_80346E58), 0, 0x40000);
}

s8 fn_8010D280(Obj_8010D280 *o)
{
    s8 ret = 3;
    void *p;
    u16 r;

    switch (o->state) {
    case 0:
        p = fn_800CCA6C(5, 0);
        if (p != 0) {
            ret = fn_8010B258(o, p);
            if (ret < 0) {
                ret = 3;
            }
        } else {
            ret = 3;
        }
        break;
    case 1:
        if ((o->flags & 0x1000) == 0) {
            if (((*(Pad_8010D280 *(*)[6])&lbl_80311A60)[lbl_8034757C]->x8 & 0x300) != 0) {
                o->flags |= 0x20;
            }
        }
        if (o->s38 < o->s36) {
            if ((o->flags & 0x20) != 0) {
                do {
                    o->s38 = o->s38 + 1;
                    if ((fn_8010C2AC((void *)(o), o->s38) & 0x12C0) != 0) {
                        break;
                    }
                } while (o->s36 > o->s38);
            } else {
                o->s3a = o->s3a - 1;
                if (o->s3a <= 0) {
                    o->s38 = o->s38 + 1;
                    do {
                        r = fn_8010C2AC((void *)(o), o->s38) & ~0x2C0;
                        if (r != 0) {
                            o->s38 = o->s38 + 1;
                        }
                    } while (r != 0);
                    if (o->s36 < o->s38) {
                        o->s38 = o->s36;
                    }
                }
            }
        } else {
            switch (o->state) {
            case 0:
                o->state = 0;
                break;
            case 1:
                o->state = 0;
                break;
            }
        }
        break;
    }
    if (ret == 3 && (o->flags & 0x48) != 0) {
        ret = 4;
    }
    (*(void **)&lbl_80346E60) = o;
    return ret;
}

Task_80100BF8* fn_80100BF8(Task_80100BF8* o, u32 id, u32 infw) {
    Data_80100BF8* d = o->d;
    Inf_80100BF8* inf = (Inf_80100BF8*)infw;
    Opt_80100BF8* p;
    if (inf->f3c == 0) {
        d->f1c8 = inf;
        if (inf->f38 == 0) {
            inf->f38 = o;
        }
        inf->f3c = 1;
    } else {
        d->f1c8 = inf;
    }
    if (o->fn == fn_8008F760) {
        d->f17c = inf->f4;
        inf->f4 = fn_8008F980();
    }
    d->f178 = id;
    d->f17a = inf->f4;
    *(f32*)((u8*)d + 0x38) = inf->f44;
    *(f32*)((u8*)d + 0x3c) = inf->f48;
    *(f32*)((u8*)d + 0x40) = inf->f4c;
    *(s32*)((u8*)d + 0x44) = (s32)(182.04445f * inf->f50);
    *(s32*)((u8*)d + 0x48) = (s32)(182.04445f * inf->f54);
    *(s32*)((u8*)d + 0x4c) = (s32)(182.04445f * inf->f58);
    *(f32*)((u8*)d + 0x50) = inf->f5c;
    *(f32*)((u8*)d + 0x54) = inf->f60;
    *(f32*)((u8*)d + 0x58) = inf->f64;
    p = inf->f10;
    if (p != 0) {
        d->f176 = (p->kind > 5) ? p->f18 : 0;
        if ((d->f176 & 0xff) >= 9) {
            d->f4 = 0;
            d->f176 = d->f176 - 9;
        }
        if (((p->kind > 6) ? p->f1c : 0) != 0) {
            d->f2c = 0;
        }
        d->f16e = (p->kind > 7) ? p->f20 : 0;
    }
    d->fe4 = 0;
    d->f100 = 0;
    if (inf != 0) {
        Sub_80100BF8* w;
        d->fe4 = fn_800C355C((u8*)d + 0x100, inf, 0);
        w = inf->f1c;
        if (w->count != 0 && w->d4 != 0) {
            d->fe8 = w->d4;
        }
        fn_80222C80(inf, d);
    }
    fn_80129814(o);
    return o;
}

static inline void Setup_801032C8(Ent_801032C8* e) {
    f32 lo;
    f32 hi;
    f32 v;
    f32 z;
    if (e != 0) {
        e->f16e = 1;
        fn_801173DC(0, e);
        e->f74 = 5;
        z = 0.0f;
        e->v5c = z;
        e->v60 = z;
        e->v64 = z;
        if (fn_801C6068(e, 12) != 0) {
            z = -(f32)e->p1c8->t->f2c / 100.0f;
        }
        e->v60 = z;
        fn_80103140((void *)e, (void *)&e->p38);
        v = 0.0f;
        if (e != 0) {
            if (fn_801C60A4(e) == 0) {
                v = e->p3c;
            } else {
                lo = 0.0f;
                hi = e->p1c8->f48;
                if (e != 0 && fn_801C6068(e, 12) != 0) {
                    lo = (f32)e->p1c8->t->f28;
                }
                v = hi - lo;
            }
        }
        e->f24c = v;
    }
}

Task_801032C8* fn_801032C8(Task_801032C8* o, s32 a, s32 b) {
    Ent_801032C8* e;
    Task_801032C8* t = 0;
    if (o != 0 && o->d != 0 && fn_801C60A4(o->d) != 0 && a >= 0 && b > 0) {
        t = fn_80100E10(o, (u32)fn_801034BC, o->d->f178, (u32)o->d->p1c8);
        if (t != 0) {
            if (t->d == 0) {
                fn_80100B74(t);
            } else {
                if (a >= b) {
                    a = a % b;
                }
                t->d->f22c = a;
                e = t->d;
                if (e != 0) {
                    Setup_801032C8(e);
                }
            }
        }
    }
    return t;
}

static inline Entry *Find_80109B8C(void *key)
{
    Entry *p;
    for (p = lbl_80347460; p != 0; p = p->next) {
        if ((void *)p->ptr == key) {
            return p;
        }
    }
    return 0;
}

static inline void Unlink_80109B8C(u32 b)
{
    u8 **link;
    u8 *n;
    u8 *base;
    s32 count;
    u32 idx;
    u8 *sub;
    u8 *node;

    link = (u8 **)&lbl_80347460;
    n = (u8 *)lbl_80347460;
    while (n != 0) {
        if (*(u32 *)(n + 4) == b) {
            *link = *(u8 **)(n + 0x30);
            fn_801E17E0(n);
            lbl_8034745C -= 1;
            break;
        }
        link = (u8 **)(n + 0x30);
        n = *link;
    }

    if (lbl_80346E58 == 0) return;
    if (lbl_80346E58 != 0) memset(lbl_80346E58, 0, 0x40000);

    node = (u8 *)lbl_80347460;
    while (node != 0) {
        sub = *(u8 **)(node + 4);
        if (lbl_80346E58 != 0 && sub != 0) {
            base = *(u8 **)(sub + 4);
            count = *(s32 *)sub;
            do {
                idx = *(u32 *)(base + 4);
                if (idx < 0x10000) {
                    ((u8 **)lbl_80346E58)[idx] = base;
                }
                base += 0x68;
            } while (--count != 0);
        }
        node = *(u8 **)(node + 0x30);
    }
    fn_8014912C();
}

typedef struct Task_80109B8C {
    u8 pad0[0x18];
    u8 flags;
    u8 pad_19[0x24 - 0x19];
    u8 *w24;
} Task_80109B8C;

typedef struct Ent_80109B8C {
    u8 pad0[0x38];
    Task_80109B8C *task;
    u8 pad_3c[0x68 - 0x3C];
} Ent_80109B8C;

typedef struct Set_80109B8C {
    u32 count;
    Ent_80109B8C *ent;
} Set_80109B8C;

extern s32 fn_800D2BF0(u32 id);
extern void fn_80225F58(u16 id);
extern void *fn_80226354(void *t);
extern void fn_802273E0(void *p, s32 n);

void fn_80109B8C(Set_80109B8C *b)
{
    Entry *node;
    s32 id;
    u32 n;
    Ent_80109B8C *e;
    u8 *w;

    if (b != 0) {
        fn_800D2BF0((u32)b);
        node = Find_80109B8C(b);
        if (node != 0) {
            id = node->id;
        } else {
            id = -1;
        }
        if (id != -1 && id != 0x7FFF) {
            fn_80225F58(id);
        }
        n = b->count;
        e = b->ent;
        while (n-- != 0) {
            if (e->task != 0 && fn_80226354(e->task) != 0) {
                if ((e->task->flags & 1) != 0 && TaskDelete((void *)e->task) == 0) {
                    w = e->task->w24;
                    if (*(void **)(w + 0x1bc) != 0) {
                        fn_80222964(*(void **)(w + 0x1bc));
                        fn_801E1784(*(void **)(w + 0x1bc));
                        *(void **)(w + 0x1bc) = 0;
                    }
                }
            }
            e = (Ent_80109B8C *)((u8 *)e + 0x68);
        }
        fn_802273E0(b, 0);
        fn_801E17E0(b);
        Unlink_80109B8C((u32)b);
    }
}

void fn_8010C0E4(Obj_8010C0E4 *o, Src_8010C0E4 *n)
{
    u16 f = n->flags;
    s32 *p;
    u8 *e;

    if ((f & 0x6000) != 0) {
        p = n->p4;
        if (p != 0) {
            if ((f & 0x2000) != 0) {
                *p = 1;
            } else {
                *p = 2;
            }
            n->p4 = 0;
        }
        return;
    }
    if ((f & 0x2C0) != 0) {
        if ((f & 0x80) != 0) {
            o->flags |= 0x88;
            o->flags &= 0xFDBF;
        } else if ((f & 0x200) != 0) {
            o->flags |= 0x208;
            o->flags &= 0xFFBF;
        } else {
            o->flags |= 0x40;
            o->h1a = n->h16;
        }
    }
    if ((f & 0x900) != 0) {
        if ((f & 0x100) != 0) {
            o->flags |= 0x100;
            o->flags &= 0x77FF;
            o->h10 = 0x20;
            o->h12 = 0x178;
        } else {
            o->flags |= 0x8800;
            o->flags &= 0xFEFF;
            o->h10 = 0x14;
            o->h12 = 0x24;
        }
    }
    if ((f & 0x400) != 0) {
        if (n->h18 != 0) {
            o->flags |= 4;
            e = TextCopyN((u8 *)o->text, n->text, 0x30);
            *e = 0;
            o->len = TextStrlen(o->text);
            o->h32 = 0;
        } else {
            o->flags &= 0xFFFB;
            o->text[0] = 0;
            o->len = 0;
            o->h32 = -0x18;
        }
    }
    if ((f & 0x1000) != 0) {
        o->flags |= 0x1000;
        o->flags &= 0xFFDF;
    }
}

void fn_8010B238(void* p) {
    fn_8010B038(p);
}

s32 fn_8010ABD4(MotCtx* ctx, MotObj* src) {
    ctx->dst->frame = src->frame;
    ctx->dst->speed = src->speed;
    ctx->dst->motion = src->motion;
    return 0;
}

void fn_80109830(s32 a, s32 b, s32 c) {
    fn_801096FC((void *)0, a, (u32)b, (const char *)c);
}

void fn_80108DF8(Obj19 *o)
{
    switch (o->state) {
    case 0xFE:
    case 0xFF:
        fn_80100B74(o);
        break;
    }
}

/* -1 when x is outside the 20000..28598 id range, else 0 below 23000 and 1 from 23000 up. */
s32 fn_800DE554(u32 x)
{
    s32 inr;
    s32 ret;

    ret = -1;
    inr = 0;
    if (x >= 0x4e20 && x < 0x6fb7) {
        inr = 1;
    }
    if (inr != 0) {
        ret = x >= 0x59d8;
    }
    return ret;
}

void fn_800E3554(void)
{
    Unk80305C40 *p = &lbl_80305C40;
    int i;

    for (i = 0; i < 9; i++) {
        p->a[i] = 0;
    }
    lbl_80346DC0 = 0;
    lbl_80346DB8 = 0;
    lbl_80346DB0 = 0;
    p->b = 0;
}

s32 fn_800DE598(u32 id)
{
    s32 r = -1;
    BOOL in = FALSE;

    if (id >= 20000 && id < 28599) {
        in = TRUE;
    }
    if (in) {
        r = id % 100 / 10;
    }
    return r;
}

static inline Entry *FindByPtr(void *key)
{
    Entry *p;
    for (p = lbl_80347460; p != 0; p = p->next) {
        if ((void *)p->ptr == key) {
            return p;
        }
    }
    return 0;
}

void *fn_80109D74(void *p)
{
    void *key = fn_801CC0A0(p);

    if (key != 0) {
        FindByPtr(key)->p8 = 0;
    }
    return key;
}

void* fn_8010062C(Tbl68* t, u16 key) {
    s32 i;
    Entry68* e;
    if ((u32)t->count > key) {
        e = t->entries;
        if (key != e[key].id) {
            for (i = 0; i < t->count; i++) {
                if (key == e->id) {
                    return e;
                }
                e++;
            }
        } else {
            e += key;
            return e;
        }
    }
    return NULL;
}

static inline void SetAngle(Obj_800E07AC *p, f32 deg) {
    if (p == 0) {
        return;
    }
    p->f114 = (s32)(182.04445f * deg);
    p->f48 = p->f114;
    if (fn_801C60A4(p)) {
        p->f48 = p->f48 + (s32)(182.04445f * p->p1c8->f54);
    }
}
void fn_800E07AC(Obj_800E07AC *p) {
    if (p == 0) {
        return;
    }
    SetAngle(p, 0.0f);
    p->f164 = 0.0f;
    p->f254 = 0.0f;
}

void fn_800E2D0C(s32 mode, Obj_800E2D0C *e, f32 *ox, f32 *oy, f32 a, f32 b, f32 c)
{
    Cfg_800E2D0C *cfg = e->scr->cfg;
    s32 n = cfg->n;
    s32 p = n > 8 ? cfg->i24 : 0;
    s32 q = n > 10 ? cfg->i2c : 0;
    f32 fx = (f32)(q + p);
    s32 r = n > 9 ? cfg->i28 : 0;
    s32 t = n > 11 ? cfg->i30 : 0;
    f32 fy = (f32)(t + r);

    if (mode == 0) {
        *ox = fx + a / (f32)(n > 12 ? cfg->u34 : 0);
        *oy = fy + c / (f32)(e->scr->cfg->n > 12 ? e->scr->cfg->u34 : 0);
    } else if (mode == 1) {
        *ox = fx + a / (f32)(n > 12 ? cfg->u34 : 0);
        *oy = fy - b / (f32)(e->scr->cfg->n > 12 ? e->scr->cfg->u34 : 0);
    } else if (mode == 2) {
        *ox = fx + c / (f32)(n > 12 ? cfg->u34 : 0);
        *oy = fy - b / (f32)(e->scr->cfg->n > 12 ? e->scr->cfg->u34 : 0);
    } else if (mode == 3) {
        *ox = fx - c / (f32)(n > 12 ? cfg->u34 : 0);
        *oy = fy - b / (f32)(e->scr->cfg->n > 12 ? e->scr->cfg->u34 : 0);
    } else if (mode == 4) {
        *ox = fx - c / (f32)(n > 12 ? cfg->u34 : 0);
        *oy = fy - b / (f32)(e->scr->cfg->n > 12 ? e->scr->cfg->u34 : 0);
    }
}

void fn_8010A834(Obj_8010A834 *self) {
    Ctx_8010A834 *c = self->ctx;
    DrawObj *d = &lbl_80305D10;
    Hdr2 *h = c->p1c8->hdr;
    if ((*(Cam **)&lbl_80347450) == 0) return;
    if (self->state != 0xff && lbl_803473A8 == 0) return;
    switch (self->state) {
    case 0:
        if ((u32)h->n < 7) fn_801DBE1C(lbl_802B3058);
        fn_80227810((void *)(c->p1c8->tex));
        fn_8009090C(d);
        self->f20 = lbl_80349C40;
        self->state = self->state + 1;
        break;
    case 1: {
        f32 lim, dx, dz, dist;
        s32 ang;
        u32 a;
        u32 col;
        DrawState ds;
        d->f80 = h->f0c;
        d->f7c = h->f0c;
        d->w0 = (u32)c->p1c8->tex;
        dx = h->f04 - (*(Cam **)&lbl_80347450)->x;
        dz = h->f08 - (*(Cam **)&lbl_80347450)->z;
        if (dx > 8400.0f) dx -= 16800.0f;
        else if (dx < -8400.0f) dx += 16800.0f;
        if (dz > 7200.0f) dz -= 14400.0f;
        else if (dz < -7200.0f) dz += 14400.0f;
        dist = fn_80291A5C(dx * dx + dz * dz);
        lim = 1.04f * dist;
        if (lim > h->f10) return;
        ang = (s32)(16384.0f * (h->f10 - dist) / h->f10);
        d->y = 2000.0f * njSin(ang);
        d->x = (h->f14 / h->f10) * (dx * njCos(ang)) + (*(Cam **)&lbl_80347450)->x;
        d->z = (h->f14 / h->f10) * (dz * njCos(ang)) + (*(Cam **)&lbl_80347450)->z;
        a = (u32)(255.0f * h->f18 * (h->f10 - lim) / h->f10);
        if (a > 0xff) a = 0xff;
        col = (a << 24) | 0xffffff;
        d->colors[0] = col;
        d->colors[1] = col;
        d->colors[2] = col;
        d->colors[3] = col;
        ClipZPush();
        njClipZ(-1.1f, -2200.0f);
        DrawStateDefault2D(&ds);
        if (h->u1c != 0) {
            ds.blend_src = 8;
            ds.blend_dst = 10;
        }
        DrawStatePush(&ds);
        fn_80296EEC(1, 3, 0);
        fn_8009076C(0, d);
        fn_80296EEC(1, 3, 1);
        DrawStatePop(0);
        ClipZPop();
        break;
    }
    case 0xff:
        if (c->p1c8->tex != 0) fn_802275A4((void *)(c->p1c8->tex), 0);
        fn_80100B74((void *)(self));
        break;
    }
}

/* Draws texture idx of tex as a screen rectangle (x0,y0)-(x1,y1) at depth z with the given alpha.
 * Needs __OSs16tof32 / OSs16tof32 in <dolphin/os/OSFastCast.h>. */
void fn_800DDE98(s16 x0, s16 y0, s16 x1, s16 y1, f32 alpha, f32 z, NJS_TEXLIST* tex, s16 idx) {
    DrawState st;
    Vertex2D v[4];
    f32 zz;
    u32 col;
    s32 i;
    if (tex != 0) {
        DrawStateDefault2D(&st);
        fn_80299040(tex);
        if (idx >= tex->nbTexture) idx = tex->nbTexture - 1;
        fn_80298FE4(idx);
        zz = fn_801DBD9C(z);
        alpha *= 255.0f;
        col = (__OSf32tou8(alpha) << 24) | 0xFFFFFF;
        OSs16tof32(&x0, &v[0].x);
        OSs16tof32(&y0, &v[0].y);
        v[0].u = 0.0f;
        v[0].v = 0.0f;
        v[1].x = v[0].x;
        OSs16tof32(&y1, &v[1].y);
        v[1].u = 0.0f;
        v[1].v = 1.0f;
        OSs16tof32(&x1, &v[2].x);
        v[2].y = v[0].y;
        v[2].u = 1.0f;
        v[2].v = 0.0f;
        v[3].x = v[2].x;
        v[3].y = v[1].y;
        v[3].u = 1.0f;
        v[3].v = 1.0f;
        for (i = 0; i < 4; i++) {
            v[i].z = zz;
            v[i].colour = col;
        }
        if (DrawStatePush(&st) != 0) {
            fn_80291064(v, 4, 1);
            DrawStatePop(0);
        }
    }
}

static inline void ent_reset(Ent_800DF5C0* e) {
    if (e != 0) {
        e->w25c = 0;
        e->p260 = 0;
        e->p264 = 0;
        e->w268 = 0;
        e->w23c = 0;
        e->b1ec = 0;
        e->b1ed = 0;
        e->b1ee = -1;
    }
}

static inline void partlist_free(void** p) {
    if (p != 0) {
        void** q = p;
        while (*q != 0) {
            PartKill(*q);
            q++;
        }
        fn_801E1784(p);
    }
}

static inline void ent_free_parts(Ent_800DF5C0* e) {
    void** p;
    if (e != 0) {
        p = e->p264;
        if (p != 0) {
            partlist_free(p);
            e->p264 = 0;
        }
    }
}

static inline void ent_res(Ent_800DF5C0* e) {
    s32 n = 0;
    void* t;
    if (fn_801C6068(e, 9) != 0) {
        n = e->p1c8->x->w24 + 1;
    }
    if (n > 0) fn_80225F58(n);
    t = e->p260;
    if (t != 0) {
        fn_80109118(-1, (u32)t);
        fn_802273E0(e->p260, 0);
        fn_801E17E0(e->p260);
        e->p260 = 0;
    }
}

void fn_800DF5C0(Obj_800DF5C0* o) {
    Ent_800DF5C0* e;
    void** p;
    if (o == 0) return;
    e = o->ent;
    if (e == 0) return;
    switch (o->mode) {
    case 0:
        ent_reset(e);
        if (e != 0) e->s168 = 0;
        o->mode = 1;
        break;
    case 1:
        fn_800DE9BC(o);
        break;
    case 2:
    case 0xFF:
        if (e != 0) {
            if (e != 0) {
                p = e->p264;
                if (p != 0) {
                    partlist_free(p);
                    e->p264 = 0;
                }
            }
            ent_res(e);
        }
        fn_80100B74(o);
        break;
    case 0xFE:
        break;
    }
}

s32 fn_800EEDD4(s32 n, f32 fx, f32 fy) {
    s32 i = n <= 0 ? 0 : n - 1;
    s32 x;
    s32 y;
    s32 v;
    if (fx > 0.0f) {
        x = (fx - 36.0f) / 16.0f;
    } else {
        x = 0;
    }
    if (fy > 0.0f) {
        y = (fy - 53.0f) / 16.0f;
    } else {
        y = 0;
    }
    if (x >= 28) x = 27;
    if (y >= 24) y = 23;
    if (lbl_802E4460[y / 2][x / 2] != 0) {
        v = (*(Game6E14_800EEDD4**)&lbl_80346E14)->grid[i].cell[y][x];
        if ((*(Game6E14_800EEDD4**)&lbl_80346E14)->s38 < 14) {
            if (v == 7) v = 0;
        } else {
            if (v == 11) v = 7;
        }
    } else {
        v = 12;
    }
    return v;
}

void fn_800FF4EC(s32 n) {
    u32 b;
    s32 set;
    if (n < 0 || n >= 6) {
        fn_801DBE1C(lbl_802B2308);
    }
    b = n + 0x408;
    set = (lbl_80310B3C[b >> 5] & (1 << (b & 31))) != 0;
    if (set != 0) {
        if (fn_801F3844(n) == 0) {
            fn_801DBE1C(lbl_802B2328);
        }
        lbl_80310B3C[b >> 5] &= ~(1 << (b & 31));
        b = n + 0x402;
        lbl_80310B3C[b >> 5] |= 1 << (b & 31);
    }
}

void fn_800FF5D0(s32 n) {
    u32 b;
    s32 set;
    if (n < 0 || n >= 6) {
        fn_801DBE1C(lbl_802B2308);
    }
    b = n + 0x408;
    set = (lbl_80310B3C[b >> 5] & (1 << (b & 31))) != 0;
    if (set != 0) {
        if (fn_801F39EC(n) == 0) {
            fn_801DBE1C(lbl_802B2328);
        }
        lbl_80310B3C[b >> 5] &= ~(1 << (b & 31));
        b = n + 0x402;
        lbl_80310B3C[b >> 5] |= 1 << (b & 31);
    }
}

void fn_800FF6B4(s32 n) {
    s32 set;
    u32 a;
    u32 b;
    u32 ma;
    u32 mb;
    if (n < 0 || n >= 6) {
        fn_801DBE1C(lbl_802B2308);
    }
    a = n + 0x408;
    ma = 1 << (a & 31);
    set = (lbl_80310B3C[a >> 5] & ma) != 0;
    if (set == 0) {
        b = n + 0x402;
        mb = 1 << (b & 31);
        set = (lbl_80310B3C[b >> 5] & mb) != 0;
        if (set == 0) {
            fn_801F3E6C(n);
        } else {
            fn_801F3CB0(n);
        }
        lbl_80310B3C[a >> 5] |= ma;
        lbl_80310B3C[b >> 5] |= mb;
    }
}

static inline void SeqStart(Obj_80107D90 *o) {
    SeqTbl *t = o->tbl;
    o->idx = 0;
    o->timer = t->ent[0].a;
    fn_801E735C(t->ent[0].b, (void *)(o), (f32)t->ent[0].c / 100.0f);
    o->f24c = o->f190;
    o->f190 = 0.0f;
    o->cnt = t->ent[0].d;
}

s32 fn_80107D90(Parent_80107D90 *p) {
    Obj_80107D90 *o;

    switch (fn_8015F218((void *)(p->obj))) {
    case 1:
        o = p->obj;
        if (p->f19 != 1) {
            SeqStart(o);
        }
        o->f190 = o->f24c;
        o->state3 = 3;
        p->f19 = 3;
        return 1;
    case 2:
        o = p->obj;
        SeqStart(o);
        o->state3 = 4;
        p->f19 = 4;
        return 1;
    default:
        return 0;
    }
}

/* Parses a "(r,g,b)" colour after the cursor; "()" gives the default grey.
 * On a syntax error the cursor is put back and 0 is returned. */
u32 fn_8010B940(const u8** pp) {
    const u8* start = *pp;
    u32 col;
    u8 v;
    u16 c;
    if (TextReadChar(pp) == '(') {
        col = 0;
        v = 0;
        do {
            c = TextReadChar(pp);
            if (c == ')') {
                if (start + 2 == *pp) {
                    col = 0xFFC0C0C0;
                } else {
                    col <<= 8;
                    col |= 0xFF000000 | v;
                }
                return col;
            }
            if (c == ',') {
                col <<= 8;
                col |= v;
                v = 0;
            } else if (c >= '0' && c <= '9') {
                v = v * 10 + (u8)(c - '0');
            } else {
                break;
            }
        } while (c != 0);
    }
    *pp = start;
    return 0;
}

void fn_8010E074(Obj_8010E074* o) {
    Work_8010E074* w = o->work;

    switch (o->state) {
    case 0:
    case 0xfe:
        if (w->texlist != NULL) {
            fn_80227810(w->texlist);
        }
        o->state = 1;
        w->x38 = 100000.0f;
        w->x3c = 100000.0f;
        w->x40 = 100000.0f;
        fn_80222838(w->x1bc);
        fn_8015ED90(o);
        break;
    case 1:
        fn_8015E600(w);
        break;
    case 0xff:
        if (lbl_803473FC != 0) {
            lbl_80347400 = 0x7FFFFFFF;
            fn_8011622C(0x7FFFFFFF);
        }
        fn_8015EBF4(o->work);
        if (w->texlist != NULL) {
            fn_802275A4(w->texlist, 0);
        }
        fn_80100B74(o);
        break;
    }
}

void fn_800F113C(Ctl* c, Obj_800F1264* o) {
    s32 ok = 0;
    Rec_800F1264* a = lookup(o, 3);
    if (a != 0) {
        s32 f;
        u32 k = (u32)(a->n * 8 + 4) >> 2;
        u32 v = a->s0;
        o->dst = (u8*)(o->w20c = f = 0);
        if (v == k && o->src != 0 && *o->src == a->n) {
            o->w20c = a->s6;
            o->dst = (u8*)a + 4;
            f = 1;
        }
        ok = f;
    }
    if (ok != 0) {
        if (c->mode == 0) {
            o->w20c = 1;
            fn_800F0C68((void *)(o));
            c->mode = 2;
        } else {
            o->flags |= 8;
            o->s20a = 2;
            c->mode = 3;
        }
    } else {
        c->mode = 2;
    }
}

void fn_8010DDBC(void *o_) {
    Obj_8010DDBC* o = o_;
    Work_8010DDBC* w = o->work;

    switch (o->state) {
    case 0:
        w->h170 = 0;
        w->h172 = 0;
        if (w->texlist != NULL) {
            fn_80227810(w->texlist);
        }
        o->state = 1;
        break;
    case 1:
        fn_801E5DF0(w);
        break;
    case 2:
        fn_801E5DF0(w);
        break;
    case 3:
        fn_80119AF4(o);
        break;
    case 0xfe:
        break;
    case 0xff:
        if (w->texlist != NULL) {
            fn_802275A4(w->texlist, 0);
        }
        fn_801C6170(o);
        break;
    }
}

void fn_800D8214(T *self)
{
    E *e;
    s32 a = 1;
    s32 b = 1;
    s32 r;

    e = self->e;
    if (lbl_803475D8 != 0) {
        self->state = 9;
    }
    switch (self->state) {
    case 0:
    case 0xfe:
        fn_8022697C(self->p14);
        fn_800D8014(self->e);
        fn_802171F0(-0x1f);
        if ((*(s32*)&lbl_80346D98) != 0) {
            e->mode = 0;
            self->state = 2;
            break;
        }
        self->state = 1;
    case 1:
        fn_800D7D60(e);
        r = fn_800D7E7C(e);
        if (r != 0) {
            s32 st = 2;
            if (r < 0) st = 6;
            self->state = st;
        }
        break;
    case 2:
        fn_801CBBAC(15.0f);
        self->state = 3;
        break;
    case 3:
        if (lbl_80347508 == 0) {
            s32 n = e->mode;
            a = 0;
            b = 0;
            if (n == 0) {
                fn_800EDF38();
                self->state = 4;
            } else if (n == 1) {
                fn_800CE2B4();
                self->state = 9;
            } else {
                self->state = 8;
                fn_80123E8C();
            }
        }
        break;
    case 4:
        a = 0;
        b = 0;
        if (lbl_80346E04 == 0) {
            fn_801CBB9C(15.0f);
            e->f8 = 0.0f;
            self->state = 5;
        }
        break;
    case 5:
        b = 0;
        if (lbl_80347508 == 0) {
            self->state = 9;
        }
        break;
    case 6:
        self->state = 7;
    case 7:
        e->f8 = e->f8 - 0.33333334f;
        if (0.0f >= e->f8) {
            self->state = 9;
        }
        break;
    case 8:
        if (lbl_803473B4 != 0) {
            b = 0;
            a = 0;
            break;
        }
    default:
        fn_8022697C(0x7fffffff);
        lbl_803473E8 = 1;
        lbl_80347444 = 0;
        fn_80217134();
        self->flags |= 0x40;
        return;
    }
    if (a != 0) {
        fn_80226BD0(-2.92f, 0.5f * (1.0f - e->f8) + 0.5f);
    }
    if (b != 0) {
        fn_800D7B28(e);
    }
    fn_8022DBC8();
}

void fn_80100270(void *arg) {
    if (arg == 0) {
        fn_801DBE1C(lbl_802B2348, arg);
    }
    strcpy(lbl_80305CF0, arg);
    lbl_80311AD4[6] = 15;
}

s32 fn_800EDAA4(f32 x, f32 y, u8 (*tbl)[24][28], s32 idx) {
    s32 cx;
    s32 cy;
    s32 t;
    if (x > 0.0f) {
        cx = (x - 36.0f) / 16.0f;
    } else {
        cx = 0;
    }
    if (y > 0.0f) {
        cy = (y - 53.0f) / 16.0f;
    } else {
        cy = 0;
    }
    if (cx >= 0x1c) {
        cx = 0x1b;
    }
    if (cy >= 0x18) {
        cy = 0x17;
    }
    t = tbl[idx][cy][cx];
    if ((s8)lbl_80310A1C[6] < 14) {
        if (t == 7) {
            t = 0;
        }
    } else if (t == 11) {
        t = 7;
    }
    return t;
}

void fn_8010C384(Row *p, s32 a, s16 b)
{
    s32 n = b;

    while (p != NULL) {
        if (p->x14 == 0) break;
        p = p->next;
        n--;
    }
    while (p != NULL && n > 0) {
        if (p->x14 == 0) {
            if (a == 0) {
                p->color = 0xFFC0C021;
            } else {
                p->color = 0xFFC0C0C0;
            }
            a--;
            n -= p->x18;
        } else {
            n--;
        }
        p = p->next;
    }
}

static inline s32 Has_800DA564(Work_800DA564* w, s32 v) {
    s32 n = w->count;
    for (;;) {
        n--;
        if (n < 0) {
            return 0;
        }
        if (v == w->list[n]) {
            return 1;
        }
    }
}

void fn_800DA564(Obj_800DA564* o) {
    Work_800DA564* w;
    s32 j;
    s32 k;
    s32 n;
    s32 buf[6];
    w = o->work;
    if ((o->par->flags & 0x40) || (w->src->flags & 0x40)) {
        o->flags |= 0x40;
        return;
    }
    switch (o->state) {
    case 0:
        fn_800B2DC0(w->src->ctx, w->s4, 2, 13, 1.0f);
        w->list[w->count++] = w->s4;
        o->state++;
        break;
    case 1: {
        n = w->count;
        for (j = 0; j < n; j++) {
            fn_800DA744(w->list[j], buf);
            for (k = 0; k < 6; k++) {
                s32 found = Has_800DA564(w, buf[k]);
                if (found == 0) {
                    fn_800B2DC0(w->src->ctx, buf[k], 2, 13, 0.25f * (f32)w->s8);
                    w->list[w->count++] = buf[k];
                }
            }
        }
        o->state++;
        break;
    }
    case 2:
        w->s8--;
        if (w->s8 != 0) {
            o->state = 1;
        } else {
            o->flags |= 0x40;
        }
        break;
    }
}

void fn_800FF7A0(void) {
    if (lbl_80347450 == 0) return;
    if (lbl_80347464 != 1 && lbl_803474B0[0] == 1) {
        lbl_80347450->pos.x = lbl_8030A77C[0];
        lbl_80347450->pos.y = lbl_8030A77C[1];
        lbl_80347450->pos.z = lbl_8030A77C[2];
        lbl_80347450->ang[0] = lbl_8030A764[0];
        lbl_80347450->ang[1] = lbl_8030A764[1];
        lbl_80347450->ang[2] = lbl_8030A764[2];
        lbl_80347450->hit->id = lbl_803474AC[0];
        lbl_80347450->hit->x28 = 0xFFFF;
        lbl_80347450->hit->x2e = -1;
        lbl_80347450->hit->x2c = -1;
    } else if (lbl_803474B0[1] == 1) {
        lbl_80347450->pos.x = lbl_8030A77C[3];
        lbl_80347450->pos.y = lbl_8030A77C[4];
        lbl_80347450->pos.z = lbl_8030A77C[5];
        lbl_80347450->ang[0] = lbl_8030A764[3];
        lbl_80347450->ang[1] = lbl_8030A764[4];
        lbl_80347450->ang[2] = lbl_8030A764[5];
        lbl_80347450->hit->id = lbl_803474AC[1];
        lbl_80347450->hit->x28 = 0xFFFF;
        lbl_80347450->hit->x2e = -1;
        lbl_80347450->hit->x2c = -1;
    }
}

inline Entry *fn_80109F90_find(char *name) {
    char buf[0x20];
    Entry *e;
    fn_801CC434(name, 0, buf);
    for (e = lbl_80347460; e != 0; e = e->next) {
        if (fn_801E1098(buf, e->name) == 0) {
            return e;
        }
    }
    return 0;
}

inline void *fn_80109F90_load(char *path, u16 id) {
    void *p = fn_801DB244(path);
    if (id != 0x7fff) {
        fn_80224040(id, p);
    }
    fn_8010A278(p);
    fn_800D2B1C(p);
    return p;
}
void *fn_80109F90(char *name, u16 id) {
    char path[0x40];
    void *p;
    fn_801096FC(0, id, 0, name);
    if (fn_801CC62C(name) == 0) {
        sprintf(path, "%stest.mld", lbl_8034746C);
    } else {
        strcpy(path, name);
    }
    p = fn_80109F90_load(path, id);
    fn_80109F90_find(name)->ptr = (u32)p;
    return p;
}

void fn_80101E64(Task* t) {
    Work_80101E64* w;
    f32 f;
    s32 n;

    if (t == NULL) return;
    w = t->work;
    if (w == NULL) return;
    switch (t->state) {
    case 0:
        if (fn_801C5FFC(w)) {
            fn_80227810(w->tex);
        }
        fn_8015ED90(t);
        fn_8015C8B8(w, 2);
        w->wec = fn_801C5D88(w, 1);
        n = 0;
        if (fn_801C6068(w, 0x11)) {
            n = w->sub->info->w2c;
        }
        w->w210 = n;
        n = 0;
        if (fn_801C6068(w, 0x11)) {
            n = w->sub->info->w28;
        }
        w->w20c = n;
        n = 1;
        if (w->w20c <= 0) n = 6;
        t->state = n;
        if (t->state == 6) return;
    case 1:
        fn_801C5B44(w, &w->x38);
        fn_801C5AB4(w, &w->a44);
        f = 0.0f;
        w->f18c = f;
        if (fn_801C6068(w, 0x11)) {
            f = fn_801C5D04(w, 8);
        }
        w->f190 = f;
        w->count = w->w20c;
        t->state = 2;
    case 2:
        if (fn_8015E600(w) != 0) return;
        fn_801E5DF0(w);
        if (w->flag != 1) return;
        w->flag = 0;
        if (w != NULL) {
            w->x38 += fn_801C5C80(w, 0xB);
            w->y3c += fn_801C5C80(w, 0xC);
            w->z40 += fn_801C5C80(w, 0xD);
        }
        if (w != NULL) {
            w->a44 += (s32)(182.04445f * fn_801C5C80(w, 0xE));
            w->a48 += (s32)(182.04445f * fn_801C5C80(w, 0xF));
            w->a4c += (s32)(182.04445f * fn_801C5C80(w, 0x10));
        }
        n = w->count;
        if (n > 0) n--;
        w->count = n;
        if (w->count > 0) break;
        if (w->w210 <= 0) {
            t->state = 1;
        } else {
            t->state = 3;
        }
        break;
    case 3:
        w->f190 = 0.0f;
        w->count = w->w210;
        t->state = 4;
    case 4:
        fn_801E5DF0(w);
        n = w->count;
        if (n > 0) n--;
        w->count = n;
        if (n <= 0) {
            t->state = 1;
        }
        break;
    case 5:
    case 0xFF:
        fn_8015EBF4(w);
        if (fn_801C5FFC(w)) {
            fn_802275A4(w->tex, 0);
        }
        fn_80100B74(t);
        break;
    case 6:
        fn_801E66E0(w);
        break;
    case 0xFE:
        break;
    }
}

void fn_800EDB70(void) {
    s16 busy = 0;

    switch ((*(Task**)&lbl_80346E18)->state) {
    case 0:
    case 0xFE:
        fn_800EE51C();
        fn_801D8AB4(&(*(Work_800EDB70**)&lbl_80346E14)->o0, 0x2D, 0, 1.0f, 0.5f);
        (*(Work_800EDB70**)&lbl_80346E14)->o0.flags |= 2;
        (*(Work_800EDB70**)&lbl_80346E14)->o0.flags |= 4;
        fn_801D89D4((void *)(&(*(Work_800EDB70**)&lbl_80346E14)->o1), 0x1E, 0, 1.0f, -2.0f, -2.0f, -2.0f, 0.75f, 2.0f, 2.0f, 2.0f);
        (*(Work_800EDB70**)&lbl_80346E14)->o1.flags |= 2;
        (*(Work_800EDB70**)&lbl_80346E14)->o1.flags |= 4;
        fn_801D8AB4(&(*(Work_800EDB70**)&lbl_80346E14)->o2, 1, 0, 0.0f, 0.0f);
        fn_801D8AB4(&(*(Work_800EDB70**)&lbl_80346E14)->o3, 1, 0, 0.0f, 0.0f);
        fn_801D8AB4(&(*(Work_800EDB70**)&lbl_80346E14)->o4, 1, 0, 0.0f, 0.0f);
        lbl_80346E10 = ((MapRes*)fn_801DB244((void *)((*(Work_800EDB70**)&lbl_80346E14)->p48)));
        fn_80227810((void *)(lbl_80346E10->inner->texlist));
        (*(Work_800EDB70**)&lbl_80346E14)->bank = fn_801E49D8(lbl_802B2188);
        (*(Work_800EDB70**)&lbl_80346E14)->b0 = fn_801E1C7C(0x14);
        fn_801D6998((*(Work_800EDB70**)&lbl_80346E14)->b0, fn_801E4984((*(Work_800EDB70**)&lbl_80346E14)->bank, 0));
        (*(Work_800EDB70**)&lbl_80346E14)->b1 = fn_801E1C7C(0x14);
        fn_801D6998((*(Work_800EDB70**)&lbl_80346E14)->b1, fn_801E4984((*(Work_800EDB70**)&lbl_80346E14)->bank, 1));
        (*(Work_800EDB70**)&lbl_80346E14)->b2 = fn_801E1C7C(0x14);
        fn_801D6998((*(Work_800EDB70**)&lbl_80346E14)->b2, fn_801E4984((*(Work_800EDB70**)&lbl_80346E14)->bank, 2));
        fn_801D66D4();
        fn_801CBBD8();
        fn_801CBB9C(20.0f);
        lbl_80346E04 = 1;
        (*(Task**)&lbl_80346E18)->state = 1;
        break;
    case 1:
        busy = 1;
        if (lbl_80347508 != 1) {
            (*(Task**)&lbl_80346E18)->state = 2;
        }
        break;
    case 2:
        busy = 1;
        if (fn_800EE450() != -1) {
            (*(Task**)&lbl_80346E18)->state = 3;
        }
        break;
    case 3:
        busy = 1;
        fn_801CBBAC(20.0f);
        (*(Task**)&lbl_80346E18)->state = 4;
        break;
    case 4:
        busy = 1;
        if (lbl_80347508 != 1) {
            (*(Task**)&lbl_80346E18)->state = 5;
        }
        break;
    case 5:
    case 0xFF:
        if ((*(Work_800EDB70**)&lbl_80346E14)->b0 != 0) {
            fn_801E17E0((*(Work_800EDB70**)&lbl_80346E14)->b0);
            (*(Work_800EDB70**)&lbl_80346E14)->b0 = 0;
        }
        if ((*(Work_800EDB70**)&lbl_80346E14)->b1 != 0) {
            fn_801E17E0((*(Work_800EDB70**)&lbl_80346E14)->b1);
            (*(Work_800EDB70**)&lbl_80346E14)->b1 = 0;
        }
        if ((*(Work_800EDB70**)&lbl_80346E14)->b2 != 0) {
            fn_801E17E0((*(Work_800EDB70**)&lbl_80346E14)->b2);
            (*(Work_800EDB70**)&lbl_80346E14)->b2 = 0;
        }
        if ((*(Work_800EDB70**)&lbl_80346E14)->bank != 0) {
            fn_801E17E0((*(Work_800EDB70**)&lbl_80346E14)->bank);
            (*(Work_800EDB70**)&lbl_80346E14)->bank = 0;
        }
        if (lbl_80346E10 != 0) {
            fn_802275A4((void *)(lbl_80346E10->inner->texlist), 1);
            fn_801E17E0(lbl_80346E10);
            lbl_80346E10 = 0;
        }
        if (lbl_80346E0C != 0) {
            lbl_80346E0C = 0;
        }
        fn_800EECA8(1);
        fn_801D668C();
        lbl_80346E04 = 0;
        (*(Task**)&lbl_80346E18)->flags |= 0x40;
        (*(Task**)&lbl_80346E18) = 0;
        break;
    }
    if (lbl_803475D8 != 1 && busy == 1) {
        fn_800EDFA8();
    }
}

static inline s32 Ok(NJS_POINT3 *p, Hit *h) {
    s32 r = 0;
    if (p != NULL && h != NULL && fn_802254A0(p, h) == 1 && (h->h24 & 0x2800) != 0x2800) {
        r = 1;
    }
    return r;
}

s32 fn_800F1E5C(Obj_800F1E5C *o, Angle *rot, NJS_POINT3 *dir) {
    NJS_MATRIX m;
    Hit saved;
    NJS_POINT3 c;
    NJS_POINT3 c2;
    NJS_POINT3 t;
    NJS_POINT3 v = lbl_802B2228;
    Angle ax, ay, az;
    f32 px, py, pz;
    s32 result = 0;
    if (o != NULL && o->ent != NULL && o->hit != NULL && rot != NULL && dir != NULL) {
        Ent_800F1E5C *e = o->ent;
        NJS_POINT3 *pos = e->pos;
        Angle *ang = e->ang;
        px = pos->x; py = pos->y; pz = pos->z;
        ax = ang[0]; ay = ang[1]; az = ang[2];
        saved = *o->hit;
        njUnitMatrix(m);
        njRotateXYZ(m, rot[0], rot[1], rot[2]);
        fn_801C5A60(m, dir, &t);
        c.x = o->p.x + t.x;
        c.y = o->p.y + t.y;
        c.z = o->p.z + t.z;
        o->ent->pos->x = c.x;
        o->ent->pos->y = c.y;
        o->ent->pos->z = c.z;
        o->ent->ang[0] = rot[0];
        o->ent->ang[1] = rot[1];
        o->ent->ang[2] = rot[2];
        fn_80222838((void *)(o->ent));
        if (fn_80222E00(0x2800, o->ent) == 0) {
            if (Ok(&c, o->hit)) {
                f32 len = njScalor((void *)(dir));
                s32 n;
                if (len != 0.0f) {
                    v.x = 3.0f * dir->x / len;
                    v.y = 3.0f * dir->y / len;
                    v.z = 3.0f * dir->z / len;
                }
                njRotateY(m, -0x2000);
                n = 0;
                do {
                    fn_801C5A60(m, &v, &t);
                    c2.x = c.x + t.x;
                    c2.y = c.y + t.y;
                    c2.z = c.z + t.z;
                    if (!Ok(&c2, o->hit)) {
                        break;
                    }
                    n++;
                    njRotateY(m, 0xccc);
                } while (n < 5);
                if (n == 5) {
                    result = 1;
                }
            }
        }
        *o->hit = saved;
        o->ent->pos->x = px;
        o->ent->pos->y = py;
        o->ent->pos->z = pz;
        o->ent->ang[0] = ax;
        o->ent->ang[1] = ay;
        o->ent->ang[2] = az;
        fn_80222838((void *)(o->ent));
    }
    return result;
}

extern u16 lbl_80346CE8;
extern void fn_801E7E14(void* model, s16 a, s16 b, s32 mode);
extern void fn_801D9BFC(void);
extern void fn_801D9CF0(f32 a, f32 b, f32 c);
extern void fn_801D9B34(void);
extern u32 fn_801D0B40(void);
extern void fn_801D0B48(u32 v);
extern void fn_80090B68(IVec_800D9BA0* k, Vec_800D9BA0* v);

void fn_800DCB78(Task* t)
{
    EvObj* w = t->work;
    IVec_800D9BA0 k;
    Vec_800D9BA0 v;
    u32 s;

    k.x = w->b16a;
    k.y = 0;
    k.z = w->b16b;
    fn_80090B68(&k, &v);
    if (lbl_80347450 != NULL) {
        fn_80090BE4(&lbl_80347450->pos.x, &k);
    } else {
        return;
    }
    if (w->mapMode->mode != 0) {
        t->state = 0xff;
    } else if (lbl_80347450 == NULL) {
        return;
    }
    ClipZPush();
    lbl_80346788 = lbl_80347560;
    lbl_8034678C = -1200.0f;
    njClipZ(lbl_80347560, -1200.0f);
    switch (t->state) {
    case 0:
        w->x1ec = 1;
        if (w->texlist != NULL) {
            w->x1ec = 1;
            fn_80227810(w->texlist);
        }
        w->clipNear = -1100.0f;
        w->clipFar = -1200.0f;
        w->x08 = 1;
        w->x2c = 1;
        w->id = 0;
        w->pos.x = w->pos.x - v.x;
        w->pos.z = w->pos.z - v.z;
        w->home.x = w->pos.x;
        w->home.y = w->pos.y;
        w->home.z = w->pos.z;
        fn_801E7E14(w->model, lbl_80346CE8 * 3, 0, 0);
        w->id = 0x2001;
        w->ext->info->flags |= 1;
        w->x2c = 0;
        t->f20 = -300.0f;
        t->state = 1;
        break;
    case 1:
        if (-300.0f == t->f20) {
            fn_80090A7C(&lbl_80347450->pos.x, &v);
            w->pos.x = (w->home.x + v.x) - 2400.0f * (f32)k.x;
            w->pos.y = w->home.y;
            w->pos.z = (w->home.z + v.z) - 2400.0f * (f32)k.z;
            t->f20 = -255.0f;
        }
        fn_801D9BFC();
        fn_801D9CF0(1.0f, 1.0f, 1.0f);
        fn_801E7E14(w->model, 3, 0, 0);
        w->shape = (w->ext->items->count > 0) ? w->ext->items->items[0] : 0;
        if (w->motion == NULL) {
            s = fn_801D0B40();
            fn_801D0B48(s | 0x405000);
            fn_801E66E0(w);
            fn_801D0B48(s);
        } else {
            w->shape = (w->ext->items->count > 1) ? w->ext->items->items[1] : 0;
            fn_801E5DF0(w);
        }
        fn_80090A7C(&lbl_80347450->pos.x, &v);
        w->pos.x = (w->home.x + v.x) - 2400.0f * (f32)k.x;
        w->pos.y = w->home.y;
        w->pos.z = (w->home.z + v.z) - 2400.0f * (f32)k.z;
        fn_801D9B34();
        break;
    case 0xff:
        if (w->x1ec != 0 && w->texlist != NULL) {
            fn_802275A4(w->texlist, 0);
        }
        fn_80100B74(t);
        break;
    }
    ClipZPop();
}

extern s32 fn_801C5F84(EvObj* e);
extern void fn_800F7438(EvObj* e);

static inline void StartAnim_800F7D6C(EvObj* e) {
    if (e != NULL) {
        if (e->state != 6) {
            e->state = 1;
        } else {
            e->state = 5;
        }
    }
}

static inline void Pre_800F7D6C(EvObj* e) {
    if (e != NULL) {
        if (e->state == 9) {
            e->speed = e->x24c.z;
        }
        e->state = 7;
    }
}

static inline void Timer_800F7D6C(EvObj* e, s16 t) {
    if (e != NULL) {
        f32 f = 0.0f;
        if (fn_801C6068(e, 14) != 0) {
            f = 0.01f * (f32)e->ext->info->speed;
        }
        e->x164 = f;
        e->x172 = t;
    }
}

s32 fn_800F7D6C(EvObj* e) {
    s32 ok;
    s32 v = 10;
    ok = 0;
    if (e != NULL && fn_801C5F84(e) != 0 && fn_801C6068(e, 14) != 0) {
        ok = 1;
    }
    if (ok != 0) {
        EvSub* t = e->sub;
        s32 idx;
        if (t != NULL) {
            idx = t->h18;
        } else {
            idx = -1;
        }
        if (idx >= 0 && e != NULL) {
            e->x21c = idx;
        }
        switch (e->ext->info->actDist) {
        case 0:
            StartAnim_800F7D6C(e);
            v = 2;
            break;
        case 1:
            fn_800F7438(e);
            Timer_800F7D6C(e, 20);
            v = 3;
            break;
        case 2:
            fn_800F7438(e);
            Timer_800F7D6C(e, 30);
            v = 4;
            break;
        case 3:
            Pre_800F7D6C(e);
            Timer_800F7D6C(e, 20);
            v = 5;
            break;
        case 4:
            Pre_800F7D6C(e);
            Timer_800F7D6C(e, 30);
            v = 6;
            break;
        case 5:
        case 7:
            Pre_800F7D6C(e);
            Timer_800F7D6C(e, 20);
            v = 7;
            break;
        case 6:
        case 8:
            Pre_800F7D6C(e);
            Timer_800F7D6C(e, 30);
            v = 8;
            break;
        default:
            if (e != NULL) {
                e->state = 0;
            }
            v = 2;
            break;
        }
    }
    return v;
}

extern void fn_801D7ED4(Sprite* s, f32 z, f32 a, f32 b);
extern s32 fn_801D80A0(void* t, s32 a);
extern void fn_801D8080(void);
extern s16 lbl_802B1E2C[];

#define TILE_800F04C8(k, ox, oy)                                                      if (lbl_80346E14->tile[row][col][k] != 0) {                                            s = fn_801D68C4(lbl_80346E14->bank, tbl[lbl_80346E14->tile[row][col][k]]);         s->x = col * 32 + (ox);                                                            s->y = row * 32 + (oy);                                                            fn_801D7ED4(s, z, 1.0f, 1.0f);                                                     z += 0.05f * s->count;                                                         }

s32 fn_800F04C8(void) {
    DrawState ds;
    s16 tbl[21] = { 3, 3, 8, 0x6c, 0x70, 0xc, 4, 9, 0x6d, 0x71, 0xd, 5, 0xa, 0x6e, 0x72, 0xe, 6, 0xb, 0x6f, 0x73, 0xf };
    f32 z = -6000.0f;
    s32 ret;
    s32 row, col;
    Sprite* s;

    DrawStateDefault2D(&ds);
    DrawStatePush(&ds);
    ret = fn_801D80A0(lbl_80346E10->inner->texlist, 1);
    if (ret != 0) {
        for (row = 0; row < 12; row++) {
            for (col = 0; col < 14; col++) {
                TILE_800F04C8(0, 0x24, 0x35)
                TILE_800F04C8(1, 0x34, 0x35)
                TILE_800F04C8(2, 0x24, 0x45)
                TILE_800F04C8(3, 0x34, 0x45)
            }
        }
        fn_801D8080();
    }
    DrawStatePop(0);
    DrawStateRestore();
    return ret;
}

s32 fn_800EAE2C(EvObj* pl, EvObj* obj) {
    Obj20 o;
    s16 thr[15] = { 6, 6, 6, 6, 1, 1, 1, 1, 1, 3, 3, 3, 3, 3, 3 };
    Obj14 parts[15] = {
        { { 0x00540054, 0x00000000, 0x00000000, 0x00530053 }, 0 },
        { { 0x00540054, 0x00000000, 0x00540000, 0x00A70053 }, 0 },
        { { 0x00540054, 0x00000000, 0x00000000, 0x00530053 }, 0 },
        { { 0x00540054, 0x00000000, 0x00540000, 0x00A70053 }, 0 },
        { { 0x00540054, 0x00000000, 0x00A80000, 0x00FB0053 }, 0 },
        { { 0x00540054, 0x00000000, 0x00000054, 0x005300A7 }, 0 },
        { { 0x00540054, 0x00000000, 0x00540054, 0x00A700A7 }, 0 },
        { { 0x00540054, 0x00000000, 0x00A80054, 0x00FB00A7 }, 0 },
        { { 0x00540054, 0x00000000, 0x000000A8, 0x005300FB }, 0 },
        { { 0x00540054, 0x00000000, 0x005400A8, 0x00A700FB }, 0 },
        { { 0x00540054, 0x00000000, 0x00A800A8, 0x00FB00FB }, 0 },
        { { 0x00540054, 0x00000000, 0x005400A8, 0x00A700FB }, 0 },
        { { 0x00540054, 0x00000000, 0x00A800A8, 0x00FB00FB }, 0 },
        { { 0x00540054, 0x00000000, 0x005400A8, 0x00A700FB }, 0 },
        { { 0x00540054, 0x00000000, 0x00A800A8, 0x00FB00FB }, 0 },
    };
    NJS_POINT3 a;
    NJS_POINT3 b;
    EvInfo* info;
    f32 range;
    f32 dist;

    if (lbl_80347648 == 0) {
        lbl_8030B7F4.xb4d = 0;
        lbl_80310B3C[0x22] &= ~0x80;
        lbl_80347648 = 1;
    }
    info = obj->ext->info;
    if (FlagTest(info->nearDist + 0x500) != 0) {
        return 0;
    }
    range = info->actDist / 10;
    a.x = pl->pos.x;
    a.y = pl->pos.y;
    a.z = pl->pos.z;
    b.x = obj->pos.x;
    b.y = obj->pos.y;
    b.z = obj->pos.z;
    dist = fn_80290008(&a, &b);
    obj->x24c.x = dist;
    obj->x24c.y = range;
    if (dist < 2.0f * range) {
        lbl_8030B7F4.xb4d = 1;
        lbl_80310B3C[0x22] |= 0x80;
        o.colour = 0;
        o.texlist = obj->ext->texlist;
        o.sx = 0.5f;
        o.sy = 0.5f;
        o.x = 48.0f;
        o.y = 48.0f;
        o.data = &parts[obj->x1fc];
        if (obj->x200++ >= thr[obj->x1fc]) {
            obj->x200 = 0;
            if (obj->x1fc++ >= 14) {
                obj->x1fc = 0;
            }
        }
        if (lbl_80347408 == 0) {
            fn_80005D98(&o, 0, 0x21, fn_801DBD9C(-1.5f));
        }
        if (obj->x202 > 30 - obj->x206 && lbl_8030CEA0.x15c8 == 0 && lbl_80347408 == 0) {
            obj->x23c = SePlay(0, 1, 0x26);
            obj->x202 = 0;
            obj->x206 = (s16)rand() % 20;
        }
    } else if (dist < 4.0f * range) {
        lbl_8030B7F4.xb4d = 2;
        if (obj->x202 > 50 - obj->x206 && lbl_8030CEA0.x15c8 == 0 && lbl_80347408 == 0) {
            obj->x23c = SePlay(0, 1, 0x26);
            obj->x202 = 0;
            obj->x206 = (s16)rand() % 25;
            if (rand() % 5 == 0) {
                obj->x206 = (s16)rand() % 20 + 20;
            }
        }
    } else if (dist < 7.0f * range) {
        lbl_8030B7F4.xb4d = 3;
        if (obj->x202 > 70 - obj->x206 && lbl_8030CEA0.x15c8 == 0 && lbl_80347408 == 0) {
            obj->x23c = SePlay(0, 1, 0x26);
            obj->x202 = 0;
            obj->x206 = (s16)rand() % 35;
            if (rand() % 5 == 0) {
                obj->x206 = (s16)rand() % 20 + 40;
            }
        }
    } else if (dist < 10.0f * range) {
        lbl_8030B7F4.xb4d = 4;
        if (obj->x202 > 90 - obj->x206 && lbl_8030CEA0.x15c8 == 0 && lbl_80347408 == 0) {
            obj->x23c = SePlay(0, 1, 0x26);
            obj->x202 = 0;
            obj->x206 = (s16)rand() % 45;
            if (rand() % 5 == 0) {
                obj->x206 = (s16)rand() % 20 + 60;
            }
        }
    } else {
        return 0;
    }
    if (lbl_8030CEA0.x15c8 == 0) {
        obj->x202++;
    } else {
        obj->x202 = 0;
    }
    return 1;
}

/* Inline copy of fn_800FF438: the memory card slot to use, or -1. */
inline s32 SaveSlot_80101828(void) {
    s32 ret = -1;
    if (lbl_80310B3C[0x22] & 0x10) {
        if (fn_801D6E38(lbl_8034757C) == 1) {
            ret = lbl_8034757C;
        }
    }
    return ret;
}

inline void CardOpen_80101828(void) {
    s32 n;
    s32 r;
    lbl_80346E40 = SaveSlot_80101828();
    if (lbl_80346E40 >= 0) {
        u8 buf[5];
        buf[0] = 1;
        buf[1] = 1;
        buf[2] = 1;
        buf[3] = 0x2e;
        buf[4] = 0;
        n = 9;
        do {
            r = fn_801D6CBC(lbl_80346E40, buf);
            if (r == 0 || r == -2) {
                break;
            }
        } while (n-- != 0);
    }
}

inline void CardClose_80101828(void) {
    s32 n;
    s32 r;
    if (lbl_80346E40 >= 0) {
        n = 9;
        do {
            r = fn_801D6C3C(lbl_80346E40);
            if (r == 0 || r == -2) {
                break;
            }
        } while (n-- != 0);
        lbl_80346E40 = -1;
    }
}

inline void FreeBufs_80101828(void) {
    if (lbl_80346E3C != NULL) {
        fn_801E17E0(lbl_80346E3C);
        lbl_80346E3C = NULL;
    }
    if (lbl_80346E34 != NULL) {
        fn_801E17E0(lbl_80346E34);
        lbl_80346E34 = NULL;
    }
}

inline s32 SavePlayer_80101828(void) {
    s32 ok;
    lbl_80346E44 = fn_800C1C24();
    if (lbl_80346E44 > 0) {
        fn_80226D14();
        lbl_80347488 = lbl_80347450->pos.x;
        lbl_80347484 = lbl_80347450->pos.y;
        lbl_80347480 = lbl_80347450->pos.z;
        lbl_8034747C = lbl_80347450->ang[1];
        lbl_80347478 = lbl_80347450->hit->id;
        ok = 1;
    } else {
        ok = 0;
    }
    return ok;
}

void fn_80101828(void) {
    s32 ok = 0;

    if (lbl_803475D8 == 1) {
        lbl_80311AD4[6] = 15;
    }
    switch (lbl_80311AD4[6]) {
    case 0:
        fn_80101378();
        lbl_80311AD4[6] = 1;
        break;
    case 2:
        if (fn_800FFB24() != 0) {
            lbl_80311AD4[6] = 3;
        }
        break;
    case 1:
        if (lbl_803475D4 == 0) {
            lbl_8030A5D4[0] = 0;
            lbl_8030A5D4[1] = 0;
            lbl_80311AD4[6] = 2;
            break;
        }
        lbl_803475D4 = 0;
        lbl_80311AD4[6] = 3;
    case 3:
        lbl_80311AD4[6] = fn_801015AC(lbl_80311AD4[6]);
        break;
    case 4:
        if (fn_80090D78() == 1) {
            fn_80217554();
            lbl_80311AD4[6] = 5;
        }
        break;
    case 5:
        ok = 0;
        lbl_80311AC0.p0c = fn_80109D74(lbl_80346E54);
        if (lbl_80311AC0.p0c != NULL) {
            if (lbl_80346E50 != NULL) {
                lbl_80311AC0.p10 = fn_80109D74(lbl_80346E50);
                if (lbl_80311AC0.p10 == NULL) {
                    ok = 0;
                } else {
                    ok = 1;
                }
            } else {
                ok = 1;
            }
        }
        if (ok == 1) {
            if (fn_800C7DD4() == 1) {
                lbl_80311AD4[6] = 6;
            } else {
                lbl_80311AD4[6] = 7;
            }
        }
        break;
    case 6:
        if (fn_800C7DFC() != 1) {
            break;
        }
        lbl_80311AD4[6] = 7;
    case 7:
        fn_8022642C();
        if (lbl_80311AC0.map == 0x83 && lbl_80311AC0.room == 'e') {
            fn_802126C8();
            for (ok = 0; ok < 200; ok++) {
                fn_80212130();
            }
            ok = 1;
        }
        fn_8012A39C();
        fn_8022642C();
        lbl_80311AD4[6] = 8;
        if (ok == 0) {
            fn_802126C8();
        }
        lbl_803473EC = 0;
        lbl_803473E8 = 1;
        lbl_803475B0 = 0;
        lbl_80347280 = 0;
        break;
    case 8:
        lbl_80346DAC = 0;
        fn_80129DD0();
        fn_800E1A24();
        fn_8022D9C4();
        fn_80212130();
        fn_80129AA4();
        fn_800CD16C();
        DrawStateRestore();
        fn_801DA0AC();
        fn_8022642C();
        fn_801299B4();
        fn_800FF218();
        fn_800D2E60();
        if (SavePlayer_80101828() == 1 && lbl_80311AD4[6] == 8) {
            FreeBufs_80101828();
            fn_80217C24();
            fn_80217608();
            fn_80219324(5);
            fn_80219324(6);
            fn_80097AFC();
            fn_80097CA4(lbl_803473D8);
            CardOpen_80101828();
            lbl_80311AD4[6] = 9;
        } else if (lbl_803472E4 == 1) {
            s32 next;
            lbl_803472E4 = 0;
            fn_80128F80();
            fn_80217CB0();
            if (lbl_80311AC0.w4 < 500) {
                fn_80226D14();
                fn_80097AFC();
                lbl_80311AD4[6] = 12;
                fn_80097CA4(lbl_803473D8);
                CardOpen_80101828();
                next = 12;
            } else {
                next = 14;
            }
            lbl_80311AD4[6] = next;
        } else if ((s32)lbl_80310A1C[0x4c] == 0x4c) {
            lbl_80311AD4[6] = 15;
        }
        break;
    case 12:
        SePlay(-2, 1, 0xe);
        lbl_80311AD4[6] = 13;
    case 13:
        if (fn_80097CA4(lbl_803473D8) == 1) {
            lbl_803473D8 = -1;
            lbl_80311AD4[6] = 14;
        }
        break;
    case 9:
        fn_80219378(lbl_802B244C);
        SePlay(-2, 1, 0xe);
        lbl_80347474 = 0;
        lbl_80311AD4[6] = 10;
    case 10:
        if (fn_80097CA4(lbl_803473D8) == 1) {
            CardClose_80101828();
            lbl_803473D8 = -1;
            lbl_80311AD4[6] = 11;
        }
        break;
    case 14:
        if (fn_80128F2C() != 1) {
            break;
        }
        fn_80218570(0, 4, 0);
        CardClose_80101828();
        lbl_80311AD4[6] = 15;
    case 15:
        fn_80101494();
        break;
    case 11:
        FreeBufs_80101828();
        fn_8022697C(0x7FFFFFFF);
        fn_800FF908();
        fn_80101158();
        fn_8012A26C();
        fn_8022642C();
        fn_8022642C();
        fn_8022642C();
        fn_80219378(lbl_802B244C);
        lbl_80347450 = NULL;
        lbl_80347370 = NULL;
        lbl_803475D4 = 1;
        fn_801DBE6C(7);
        break;
    }
}

void fn_800E96C0(void) {
    s32 tbl[18] = { 30, 45, 31, 30, 48, 49, 54, 53, 39, 40, 41, 42, 43, 44, 49, 50, 51, 52 };
    f32 z0;
    f32 z;
    UiObj* o;
    s16 x;
    s16 y;
    s32 yy;
    s16 i;
    s16 k;
    Sprite* s;
    ResItem* e;

    z0 = TextGetZ();
    fn_800EA4A8(&lbl_80346DCC->spr[21]);
    o = &lbl_80346DCC->obj[21].o;
    UiObjUpdate(o);
    x = o->x;
    y = o->y;
    TextPushColor();
    TextSetColor(0xFF160800);
    z = lbl_80346DCC->z36c;
    s = fn_801D68C4(lbl_80346DCC->sub, 8);
    s->x = x + 0x9e;
    s->y = y + 0x168;
    fn_801D4F0C(s, 0, 0, 1, z, 0.0f, 1.0f, 1.0f);
    z += 0.05f * s->count;
    s = fn_801D68C4(lbl_80346DCC->sub, 10);
    s->x = x + 0x9e;
    s->y = y + 0x168;
    fn_801D4F0C(s, 0, 0, 1, z, 0.0f, 1.0f, 1.0f);
    z += 0.05f * s->count;
    for (i = 0; i < 3; i++) {
        e = &lbl_80346DCC->h28[i];
        if (e->h < 0) {
            continue;
        }
        k = fn_801F4C24(e->h);
        if (k == 0) {
            if (e->h == 0x47 || e->h == 0x49) {
                k = 8;
            } else if (e->h == 0x48) {
                k = 9;
            } else if (e->h < 0x10) {
                k = 8;
            } else if (e->h < 0x20) {
                k = 9;
            } else if (e->h < 0x30) {
                k = 10;
            } else if (e->h < 0x3a) {
                k = 11;
            } else if (e->h < 0x40) {
                k = 12;
            } else {
                k = 13;
            }
        } else if (k == 5) {
            switch (lbl_802D7E4C[e->h - 0x190].kind) {
            case 1:
                k = 15;
                break;
            case 2:
                k = 16;
                break;
            case 3:
                k = 17;
                break;
            case 0:
            default:
                k = 14;
                break;
            }
        }
        s = fn_801D68C4(lbl_80346DCC->sub, tbl[k]);
        yy = y + (i * 0x19 + 0x173);
        s->x = x + 0xd8;
        s->y = yy;
        fn_801D4F0C(s, 0, 0, 1, z, 0.0f, 1.0f, 1.0f);
        z += 0.05f * s->count;
        TextSetZ(z);
        TextPrint(x + 0xf0, yy, fn_801F4AE4(e->h));
        TextPrint(x + 0x1b0, yy, "\x82\x77");
        TextPrintNumber(x + 0x1c6, yy, e->n, 0xc002);
        z += 0.8f;
    }
    TextPopColor(1);
    TextSetZ(z0);
}

static inline f32 ResDrawPart(s32 n, s32 x, s32 y, f32 z) {
    Sprite* s = fn_801D68C4(lbl_80346DCC->sub, n);
    s->x = x;
    s->y = y;
    fn_801D4F0C(s, 0, 0, 1, z, 0.0f, 1.0f, 1.0f);
    return z + 0.05f * s->count;
}

void fn_800E9B04(void) {
    u8 chr;
    f32 z0;
    s16 i;
    ResSpr* spr;
    ResPanel* pan;
    s16 x;
    s16 y;
    f32 z;

    z0 = TextGetZ();
    for (i = 0; i < lbl_80346DCC->count; i++) {
        chr = lbl_80346DCC->member[i].chr;
        TextPushColor();
        TextSetColor(0xFF160800);
        spr = &lbl_80346DCC->spr[i];
        fn_800EA4A8(spr);
        pan = &lbl_80346DCC->obj[i];
        UiObjUpdate(&pan->o);
        x = pan->o.x;
        y = pan->o.y;
        z = lbl_80346DCC->z318[i];
        z = ResDrawPart(0xf, x - 8, y + (i * 64 + 0x58), z);
        z = ResDrawPart(0x10, x - 8, y + (i * 64 + 0x58), z);
        z = ResDrawPart(0x11, x - 8, y + (i * 64 + 0x58), z);
        z = ResDrawPart(chr + 0x18, x + 0x10, y + (i * 64 + 0x56), z);
        TextSetZ(z);
        TextPrint(x + 0x4e, y + (i * 64 + 0x5e), lbl_8030B7F4.chr[chr].name);
        TextPrint(x + 0xd8, y + (i * 64 + 0x5e), "Lv");
        TextPrintNumber(x + 0xf0, y + (i * 64 + 0x5e), lbl_80346DCC->member[i].level, 0xC002);
        z += 1.25f;
        TextSetZ(z);
        TextSetColor(spr->c8);
        TextPrintNumber(x + 0xef, y + (i * 64 + 0x5d), lbl_80346DCC->member[i].level, 0xC002);
        TextPopColor(1);
    }
    TextSetZ(z0);
}
