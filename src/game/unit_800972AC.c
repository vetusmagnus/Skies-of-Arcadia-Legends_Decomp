#include "types.h"
#include "string.h"
#include <math.h>
#include "ninja.h"
#include "game/drawstate.h"

typedef struct Obj12 {
    u8 pad_00[0x12];
    u16 v12;
} Obj12;
extern s16 lbl_80346C3C;
extern s16 lbl_80346750;
extern u32 lbl_803473F8;
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
extern void fn_80097B0C(void *p);
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
void njScale(void *m, f32 x, f32 y, f32 z);
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
extern void* fn_8009D5BC(void);
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
