#include "types.h"
#include <string.h>
#include "game/util.h"
#include "ninja.h"
#include "game/drawstate.h"
#include <math.h>

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
extern s32 fn_800F7D6C(void *p);
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
extern void* lbl_80346E10;
extern void* fn_802267AC(void* a, void (*b)(void));
extern void fn_800EDB70(void);
extern u32 lbl_8030A3C8[3];
extern void fn_800D2C44(u16 n);
typedef struct Rec {
    u32 u0;
    u32 u4;
    void* p8;
} Rec;
extern Rec* fn_80109404();
extern void fn_80109D74(void* p);
extern void* fn_801C6180(void* a);
extern void fn_80100BF8(void* a, u32 b, u32 c);
typedef struct Obj_801090A8 {
    u8 pad0[0x19];
    u8 state;
} Obj_801090A8;
extern s32 fog_enabled;
extern void fn_80100B74(void* o);
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
extern void fn_80227810(void* p);
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
void fn_800D8214(void);
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
typedef struct K06Pair {
    u8 pad0[0x4];
    u32 w4;
} K06Pair;
typedef struct K06Ctx_800E2924 {
    u8 pad0[0x20];
    K06Pair *p20;
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
void fn_80299040(void *p);
void fn_80297CC0(s32 a, s32 b, s32 c, s32 d);
typedef struct K06Obj_800EC3EC {
    u8 pad0[0x38];
    f32 f38;
    u8 pad1[0x40 - 0x3c];
    f32 f40;
} K06Obj_800EC3EC;
extern f32 lbl_802E3CB0[];
extern f32 lbl_802E3CD0[];
extern u8 lbl_80305C78[];
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
    u8 data[0x1c];
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
extern u8 lbl_80305CF0[];
extern s32 lbl_80311AD4[];
extern s32 lbl_80347464;
void fn_800FF908(void);
void fn_801F7B04(s32 a);
extern char lbl_802B23B8[];
void GXInvalidateTexAll(void);
void fn_801CC434(const void* p, s32 zero, void* out);
void fn_8025F0B0(void *a, void *b);
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
extern void SePlay(s32 a, s8 id, s8 vol);
extern void fn_801C6170(void *p);
extern u8 *lbl_80346E58;
extern void fn_801E17E0(void* p);
extern void fn_8014912C(void);
extern s32 lbl_8034745C;
extern void *fn_801E1A74(s32 a, u32 b);
extern u16 TextReadChar(const u8 **pp);
extern s8 lbl_802E4C70[];
extern void fn_8010C0E4(u8 *obj, u8 *n);
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
extern void fn_80299040(void *p);
extern void fn_80291428(s32 a);
extern void fn_802913E8(s32 a, s32 b);
extern f32 fn_801DBD9C(f32 v);
extern void fn_802911CC(f32* v);
extern void fn_80291424(void);
typedef struct {
    u8 pad0[0x15f8];
    u8 sub[0x14]; /* 0x15F8 */
    s32 active;   /* 0x160C */
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
extern void fn_8015ED90(void *t);
extern s32 fn_8015E600(void* p);
extern void fn_801D77B8(void);
extern s32 fn_801D1504(void);
extern void fn_801CBBAC(f32 f);
extern void fn_80216D14(s32 a);
extern void fn_80217CB0(void);
extern void fn_800FF9FC(void);
extern void fn_8015EBF4(void* p);
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
    u8 pad74[0x314 - 0x74];
    u8 active[29];       /* 0x314 */
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
extern void fn_801D4F0C(Item* it, s32 a, s32 b, s32 c, f32 f1, f32 f2, f32 f3, f32 f4);
extern void fn_801D4C54(Item* it, s32 a, s32 b, s32 c, f32 f1, f32 f2, f32 f3, f32 f4);
extern void fn_801D52A8(Item* it, s32 a, s32 b, f32 f1, f32 f2, f32 f3, f32 f4);
typedef struct {
    u8 pad0[0x2a];
    u16 id;       /* 0x2A */
} Sub_800FF908;
typedef struct {
    u8 pad0[0x38];
    f32 pos[3];   /* 0x38 */
    s32 rot[3];   /* 0x44 */
    u8 pad50[0x17a - 0x50];
    u16 id;       /* 0x17A */
    u8 pad17c[0x1b8 - 0x17c];
    Sub_800FF908* sub;     /* 0x1B8 */
} Cam_800FF908;
extern Cam_800FF908* lbl_80347450;
extern s32 lbl_803474B0[2];
extern s16 lbl_803474AC[2];
extern f32 lbl_8030A77C[6];
extern s32 lbl_8030A764[6];
extern s32 lbl_80347470;
extern s32 lbl_803475D4;
extern f32 lbl_80347488;
extern u8 lbl_80305CF0[0x20];
extern void fn_801DBE1C(const char* fmt, ...);
extern void fn_8025F120(void* dst, const char* src);
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
extern void fn_80227810(void *p);
extern void fn_801E671C(Inner *p);
extern void fn_802275A4(void *p, s32 n);
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
extern s32 TaskDelete(void *t);
extern void fn_80109B8C(void *p);
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
extern void fn_8025CB24(char *dst, const char *fmt, ...);
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
extern s32 fn_800D2924(void*u);
extern void fn_801E5608(void*u, s32 a, s32 b);
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
extern void fn_80109B8C(void *p);
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
extern void fn_8015EB8C(Unit2 *u, s32 id, void *cb);
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

void fn_800FF9FC(void) {
    lbl_80311AD4[6] = 15;
    lbl_80346E48 = 1;
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

void fn_80100720(s8 x) {
    fn_800D2CA8(x);
}

void fn_80101060(void* p, s32 a, s32 b) {
    fn_80100E68(p, 0, a, b);
}

void fn_8010108C(s32 a, s32 b, s32 c) {
    fn_80100E68((void*)0, a, b, c);
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
    if (o->p1c8->p20->w4 > 2 && o->f260 != 0) {
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
    *(s16 *)(lbl_80305C78 + 4) = n6;
    *(s16 *)(lbl_80305C78 + 6) = n7;
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
    fn_8025F120(lbl_80305CF0, name);
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
    u8 buf1[0x20];
    u8 buf2[0x40];

    GXInvalidateTexAll();
    fn_8025F120(buf2, (char *)lbl_8034746C);
    fn_801CC434(p, 0, buf1);
    fn_8025F0B0(buf2, buf1);
    if (fn_8025EF88((char *)buf1, lbl_802B23B8) == 0) {
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
                fn_8010C0E4(obj, n);
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
                    fn_801D4F0C(it, 0, 0, 1, it->f1c, 0.0f, 1.0f, it->f24);
                } else if (it->kind == 1) {
                    fn_801D4C54(it, 0, 0, 1, it->f1c, 0.0f, it->f20, it->f24);
                } else {
                    fn_801D52A8(it, 0, 1, it->f1c, 0.0f, 1.0f, it->f24);
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
    Cam_800FF908* c = lbl_80347450;
    if (c == 0) {
        return;
    }
    if (lbl_80347464 != 1) {
        lbl_803474B0[0] = 1;
        lbl_8030A77C[0] = c->pos[0];
        lbl_8030A77C[1] = c->pos[1];
        lbl_8030A77C[2] = c->pos[2];
        lbl_8030A764[0] = c->rot[0];
        lbl_8030A764[1] = c->rot[1];
        lbl_8030A764[2] = c->rot[2];
        if (c->sub != 0) {
            lbl_803474AC[0] = c->sub->id;
        } else {
            lbl_803474AC[0] = -1;
        }
    } else {
        lbl_803474B0[1] = 1;
        lbl_8030A77C[3] = c->pos[0];
        lbl_8030A77C[4] = c->pos[1];
        lbl_8030A77C[5] = c->pos[2];
        lbl_8030A764[3] = c->rot[0];
        lbl_8030A764[4] = c->rot[1];
        lbl_8030A764[5] = c->rot[2];
        if (c->sub != 0) {
            lbl_803474AC[1] = c->sub->id;
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
    fn_8025F120(lbl_80305CF0, "me002z.sct");
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
    fn_8025F120(lbl_80305CF0, (char *)p);
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
    fn_8025CB24((char *)lbl_8030A5D4, lbl_802B2364, lbl_8034746C, lbl_80311AC0.w4, lbl_80311AC0.room);
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
                    if (lbl_80347450->id == n->id) {
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
                    if (lbl_80347450->id == n->id) {
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
