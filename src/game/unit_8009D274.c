#include "types.h"
#include "string.h"
#include <math.h>
#include "ninja.h"
#include "game/drawstate.h"
#include "game/task.h"
#include "game/evobj.h"
#include <dolphin/os/OSFastCast.h>
#include "ninja_lib.h"
/* The file's .rodata, in the original order: fn_800A0028 reaches it from one pooled base. */
const f32 lbl_802B0E30[16] = {
    1.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 1.0f,
};
const NJS_POINT3 lbl_802B0E70[2] = { { 1.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 1.0f } };
const NJS_POINT3 lbl_802B0E88[2] = { { 0.0f, 1.0f, 0.0f }, { 0.0f, 0.0f, 1.0f } };
const NJS_POINT3 lbl_802B0EA0 = { 0.0f, 0.0f, 0.0f };
const NJS_POINT3 lbl_802B0EAC = { 0.0f, 0.0f, 0.0f };
const NJS_POINT3 lbl_802B0EB8 = { 0.0f, 0.0f, 0.0f };
const NJS_POINT3 lbl_802B0EC4 = { 0.0f, 0.0f, 0.0f };
const NJS_POINT3 lbl_802B0ED0 = { 0.0f, 0.0f, 0.0f };
const NJS_POINT3 lbl_802B0EDC = { 0.0f, 0.0f, 0.0f };
const char lbl_802B0EE8[] = "Effect: Particle task make failed.";
const char lbl_802B0F0C[0x24] = "Effect: Particle table get failed.";
const char lbl_802B0F30[0x10] = "eff_putmodel3";
const char lbl_802B0F40[0x10] = "eff_putmodelEx";
const char lbl_802B0F50[0x10] = "eff_putmodel2";
const char lbl_802B0F60[0xC] = "trainPic";
const char lbl_802B0F6C[0xC] = "modlight";
const char lbl_802B0F78[0x10] = "eff_man2";
typedef struct Pair {
    s32 a;
    s32 b;
} Pair;
typedef struct TblA {
    u32 count;
    u32 items[1];
} TblA;
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
typedef struct ItemList_8009E804 {
    void **items;
    s32 count;
} ItemList_8009E804;
typedef struct CamState {
    u8 pad0[0x10];
    f32 pos[3];     /* 0x10 */
    Angle ang[3];   /* 0x1C */
    u8 pad28[0x34 - 0x28];
    s32 w34;        /* 0x34 */
} CamState;
extern CamState lbl_80311970;
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
/* Finds a task by object id (below 0x10000) or by name. */
extern Task *fn_8010A164();
void fn_800A39E0(Task* o);
typedef struct TNode8009D760 TNode8009D760;
typedef struct {
    TNode8009D760** slots;
    s32 count;
} Pool;
void* fn_801E1A2C(s32 a, u32 size);
void fn_801DD76C(void *m);
extern void njScale(NJS_MATRIX m, f32 x, f32 y, f32 z);
/* A model hierarchy node (NJS_OBJECT layout). */
typedef struct ModelNode {
    u32 pad0;
    void* model;              /* 0x04 */
    NJS_POINT3 pos;           /* 0x08 */
    Angle ang[3];             /* 0x14 */
    NJS_POINT3 scl;           /* 0x20 */
    struct ModelNode* child;  /* 0x2C */
    struct ModelNode* next;   /* 0x30 */
} ModelNode;
f32 fn_8009DEF0(u32 flags, NJS_MATRIX m, ModelNode* n, f32* s, f32 best);
void fn_801DD71C(void* m);
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
void fn_801E17E0(void *);
typedef struct NodeList {
    Node **items;
    s32 count;
} NodeList;
double pow(double, double);
extern f32 njCos(Angle a);
extern f32 njSin(Angle a);
extern void fn_8015ED90(void *p);
typedef struct RecSub {
    s32 x0;
    void* p4;
} RecSub;
typedef struct Rec {
    u8 pad0[0x8];
    u32 id;         /* 0x08 */
    RecSub* pc;     /* 0x0C */
} Rec;
typedef struct Vec3_800A12D8 { f32 x, y, z; } Vec3_800A12D8;
extern f32 fn_80291A5C(f32 x);
/* Four separate .bss arrays of the unit, reached through its section base. */
extern s32 lbl_803033B0[6];
extern s32 lbl_803033C8[6];
extern s32 lbl_803033E0[6];
extern s32 lbl_803033F8[6];
extern s32 lbl_803033B0[6];
extern s32 lbl_803033C8[6];
extern s32 lbl_803033E0[6];
extern s32 lbl_803033F8[6];
typedef struct {
    u8 pad00[0x48];
    s32 count;           /* 0x48 */
    u8 pad4C[0x58 - 0x4C];
    s32 f58;             /* 0x58 */
} Params8009D760;
typedef struct {
    u8 pad00[4];
    s32 f04;
    u8 pad08[0x10 - 0x08];
    Params8009D760* params; /* 0x10 */
    u8 pad14[0x38 - 0x14];
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
    u16 s178;            /* 0x178 */
    s16 s17A;            /* 0x17A */
    u8 pad17C[0x1BC - 0x17C];
    s32 f1BC;            /* 0x1BC */
    u8 pad1C0[0x1C8 - 0x1C0];
    Obj8009D760* obj;    /* 0x1C8 */
    u8 pad1CC[0x1D8 - 0x1CC];
    s32 f1D8;            /* 0x1D8 */
    u8 pad1DC[0x204 - 0x1DC];
    s16 s204;            /* 0x204 */
    s16 s206;            /* 0x206 */
    u8 pad208[0x234 - 0x208];
    u16 h234;            /* 0x234 */
    u16 h236;            /* 0x236 */
    s16 s238;            /* 0x238 */
    u8 pad23A[0x25C - 0x23A];
    s32 f25C;            /* 0x25C */
    void* f260;          /* 0x260 */
    Pool* f264;          /* 0x264 */
    s32 f268;            /* 0x268 */
} Work8009D760;
struct TNode8009D760 {
    u8 pad00[4];
    TNode8009D760* f04;  /* 0x04 */
    u8 pad08[4];
    TNode8009D760* f0C;  /* 0x0C */
    u8 pad10[8];
    u8 flags;            /* 0x18 */
    u8 state;            /* 0x19 */
    u8 pad1A[0x24 - 0x1A];
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
extern void* fn_8009D5BC();
extern void fn_801E1784(void* p);
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
extern void njTranslate(NJS_MATRIX m, f32 x, f32 y, f32 z);
extern void fn_80286EE8(void);
extern void fn_8028B498(void);
/* Scales a 0..1 float to a u8 (x * 255) with the SDK fast cast (psq_st through GQR2).
 * The original calls the Dolphin SDK inline __OSf32tou8 from <dolphin/os/OSFastCast.h>.
 * The game code itself is plain C. Siblings: fn_8009E4B8 = __OSu8tof32(b) * K,
 * fn_8009E4D4 = __OSf32tou8((K0 + x) * 255). */
typedef unsigned char u8;
typedef float f32;
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
typedef struct { u32 f0; void* f4; } NodeModel;
typedef struct Node_8009E9D8 {
    u32 flags;          /* 0x00 */
    NodeModel* model;   /* 0x04 */
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
typedef struct {
    NJS_POINT3 v[2];
} Pair_800A13D8;
extern Pair_800A13D8 lbl_80303438;
extern f32* lbl_80346784;
extern f32* lbl_80346780;
extern void* fn_802AC710(void* dst, const void* src, u32 n);
extern void njCalcVectors(NJS_MATRIX m, const NJS_POINT3* src, NJS_POINT3* dst, s32 n);
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
extern void fn_801CCD90(Buf* b, s32 n, s32 textured, NJS_TEXLIST* tex, s32 idx, f32 z, s32 flags);
extern s32 fn_8015E600(EvObj*);
extern void fn_8015EBF4(EvObj*);
typedef struct SrcRec {
    f32 v[6];
} SrcRec;
typedef struct Axis {
    s32 on;         /* 0x00 */
    f32 spd;        /* 0x04 */
    f32 val;        /* 0x08 */
    f32 lim;        /* 0x0C */
} Axis;
typedef struct Particle {
    s16 used;       /* 0x00 */
    s16 delay;      /* 0x02 */
    u8 pad4[4];
    SrcRec *src;    /* 0x08 */
    Axis axis[8];   /* 0x0C */
    f32 v[8];       /* 0x8C */
    s16 step;       /* 0xAC */
    u8 padae[2];
    f32 fb0;        /* 0xB0 */
} Particle;
extern void njUnitMatrix(NJS_MATRIX m);
extern void fn_802135B4(NJS_POINT3 *v, Ang3 *out);
extern Pair_800A13D8 lbl_80303450;
extern f32* lbl_80346778;
extern f32* lbl_8034677C;
extern void njRotateZ(NJS_MATRIX m, Angle a);
/* Byte (0..255) to a 0..1 float: __OSu8tof32(&b) * (1/255).
 * Needs the Dolphin SDK fast-cast inline __OSu8tof32 (psq_l through GQR2), which our
 * extern/sdk OSFastCast.h lacks. The SDK's definition is reproduced here only until it is
 * added to <dolphin/os/OSFastCast.h>; the game code itself is the one-line function. */
/* lbl_80311AC0: the current map. */
typedef struct MapInfo { s32 x0; s32 map; char room; } MapInfo;
extern MapInfo lbl_80311AC0;
typedef unsigned char u8;
typedef struct Sprite {
    u8 pad0[8];
    s16 idx;       /* 0x08 texture index */
    s16 x0;        /* 0x0a */
    s16 x1;        /* 0x0c */
    s16 y0;        /* 0x0e */
    s16 y1;        /* 0x10 */
    u16 mode;      /* 0x12 */
    s32 shade;     /* 0x14 scale the colour by the alpha byte */
    s32 hasCol;    /* 0x18 */
    u8 colA[4];    /* 0x1c colour of vertices 0 and 3 */
    u8 colB[4];    /* 0x20 colour of vertices 1 and 2 */
    s16 ox;        /* 0x24 texture scroll */
    s16 oy;        /* 0x26 */
    NJS_TEXLIST* tex; /* 0x28 */
} Sprite;
typedef struct Quad {
    NJS_POINT3* pos;
    u8* col;
    s16* uv;
    s32 n;
} Quad;
extern void fn_80035518(void* tex, s32 id, Quad* src, s32 textured, s32 flags);
typedef struct Msg {
    s16 x0;
    s16 x2;
    s16 x4;
    s16 x6;
    s32 x8;
    s32 xc;
} Msg;
extern void fn_801E7E14(Msg*, s16);
typedef struct Colour4 { u8 c[4]; } Colour4;
typedef struct VertexTex {
    f32 x, y, z, u, v;
    Colour4 colour;
} VertexTex;
typedef struct VertexCol {
    f32 x, y, z;
    Colour4 colour;
} VertexCol;
/* A billboard particle's draw parameters (fn_800BA444 fills one per particle). */
typedef struct Emit_800BA444 {
    f32 x;              /* 0x00 width */
    f32 y;              /* 0x04 height */
    s16 x8;             /* 0x08 texture index */
    u16 xa;             /* 0x0A UV flip/rotate mode */
    s32 xc;             /* 0x0C premultiply the colour by alpha */
    s32 x10;            /* 0x10 use the colour below (else white) */
    u8 x14;             /* 0x14 alpha */
    u8 x15, x16, x17;   /* 0x15 colour */
    s16 x18;            /* 0x18 u scroll (1/255) */
    s16 x1a;            /* 0x1A v scroll */
    NJS_TEXLIST* x1c;   /* 0x1C */
} Emit_800BA444;
extern void fn_80296EEC(s32 a, s32 b, s32 c);
extern void fn_8028A8C0(VertexTex* v, s32 count, s32 flag);
extern void fn_8028A418(VertexCol* v, s32 count, s32 flag);
#define SWAP(a, b, t) { t = a; a = b; b = t; }
#define ROT4(a, b, c, d, t) { t = a; a = b; b = c; c = d; d = t; }

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

extern void njTranslate(NJS_MATRIX m, f32 x, f32 y, f32 z);
f32 fn_8009DDA8(u32 flags, NJS_MATRIX m, void* model, f32* s);
static inline f32 walk2(u32 flags, NJS_MATRIX m, ModelNode* n, f32* s, f32 best) {
    f32 r;
    njUnitMatrix(m);
    njTranslate(m, n->pos.x, n->pos.y, n->pos.z);
    njRotateXYZ(m, n->ang[0], n->ang[1], n->ang[2]);
    njScale(m, n->scl.x, n->scl.y, n->scl.z);
    if (n->model != 0) {
        r = fn_8009DDA8(flags, m, n->model, s);
        if (r > best) {
            best = r;
        }
    }
    if (n->child != 0) {
        best = fn_8009DEF0(flags, m, n->child, s, best);
    }
    fn_801DD71C(m);
    if (n->next != 0) {
        best = fn_8009DEF0(flags, m, n->next, s, best);
    }
    return best;
}

static inline f32 walk1(u32 flags, NJS_MATRIX m, ModelNode* n, f32* s, f32 best) {
    f32 r;
    njUnitMatrix(m);
    njTranslate(m, n->pos.x, n->pos.y, n->pos.z);
    njRotateXYZ(m, n->ang[0], n->ang[1], n->ang[2]);
    njScale(m, n->scl.x, n->scl.y, n->scl.z);
    if (n->model != 0) {
        r = fn_8009DDA8(flags, m, n->model, s);
        if (r > best) {
            best = r;
        }
    }
    if (n->child != 0) {
        best = walk2(flags, m, n->child, s, best);
    }
    fn_801DD71C(m);
    if (n->next != 0) {
        best = walk2(flags, m, n->next, s, best);
    }
    return best;
}

f32 fn_8009DEF0(u32 flags, NJS_MATRIX m, ModelNode* n, f32* s, f32 best) {
    f32 r;
    njUnitMatrix(m);
    njTranslate(m, n->pos.x, n->pos.y, n->pos.z);
    njRotateXYZ(m, n->ang[0], n->ang[1], n->ang[2]);
    njScale(m, n->scl.x, n->scl.y, n->scl.z);
    if (n->model != 0) {
        r = fn_8009DDA8(flags, m, n->model, s);
        if (r > best) {
            best = r;
        }
    }
    if (n->child != 0) {
        best = walk1(flags, m, n->child, s, best);
    }
    fn_801DD71C(m);
    if (n->next != 0) {
        best = walk1(flags, m, n->next, s, best);
    }
    return best;
}

f32 fn_8009E4F8(u8 v) {
    return (s32)(v - 255) * 0.003921569f;
}

TNode8009D760 *fn_8009E530(Pool *list, s32 count) {
    s32 i;
    TNode8009D760 **items;
    if (list == NULL) {
        return NULL;
    }
    items = list->slots;
    for (i = 0; i < count; i++) {
        TNode8009D760 *it = items[i];
        if (it != NULL && it->state == 3) {
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

typedef struct { s16 type; s16 pad; u32 w4, w8, wc; } ModelRec;

extern ModelRec* fn_801CB5F4(void* p, s32 lo, s32 hi);

#define BSW(x) ((((x) >> 24) & 0xff) | (((x) >> 8) & 0xff00) | (((x) << 8) & 0xff0000) | ((x) << 24))

Node_8009E9D8* fn_8009ED04(Node_8009E9D8* node, s32 anim, u32 target, Out* out) {
    NJS_POINT3 pos;
    Angle rot[3];
    NJS_POINT3 scl;
    ModelRec* r;
    Node_8009E9D8* c;
    u32 v;

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
                njRotateXYZ(lbl_80303498, rot[0], rot[1], rot[2]);
            }
            if (lbl_80346CF4 & 4) {
                if (fn_80006DA0(&scl, anim) == 0) {
                    scl.x = node->scl.x;
                    scl.y = node->scl.y;
                    scl.z = node->scl.z;
                }
                njScale(lbl_803034D8, scl.x, scl.y, scl.z);
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
        if (node->model != NULL) {
            r = fn_801CB5F4(node->model->f4, 0x14, 0x17);
            if (r != NULL) {
                v = 0;
                switch (r->type & 0xff) {
                case 0x14: v = BSW(r->w4) & 0xffffff; break;
                case 0x15: case 0x16: v = BSW(r->w8) & 0xffffff; break;
                case 0x17: v = BSW(r->wc) & 0xffffff; break;
                }
                if (v == target) {
                    lbl_80346D00 = node;
                    c = node->child;
                    if (c != NULL) {
                        if (lbl_80346CFC == 0) {
                            if (lbl_80346CF4 & 1) {
                                if (fn_80007080(&pos, anim) == 0) {
                                    pos.x = c->pos.x;
                                    pos.y = c->pos.y;
                                    pos.z = c->pos.z;
                                }
                                njTranslate(lbl_803034D8, pos.x, pos.y, pos.z);
                            }
                            if (lbl_80346CF4 & 2) {
                                if (fn_80006F1C(rot, anim) == 0) {
                                    rot[0] = c->ang[0];
                                    rot[1] = c->ang[1];
                                    rot[2] = c->ang[2];
                                }
                                njRotateXYZ(lbl_803034D8, rot[0], rot[1], rot[2]);
                                njRotateXYZ(lbl_80303498, rot[0], rot[1], rot[2]);
                            }
                            if (lbl_80346CF4 & 4) {
                                if (fn_80006DA0(&scl, anim) == 0) {
                                    scl.x = c->scl.x;
                                    scl.y = c->scl.y;
                                    scl.z = c->scl.z;
                                }
                                njScale(lbl_803034D8, scl.x, scl.y, scl.z);
                            }
                        } else {
                            if (!(c->flags & 1)) {
                                njTranslate(lbl_803034D8, c->pos.x, c->pos.y, c->pos.z);
                            }
                            if (!(node->child->flags & 2)) {
                                njRotateXYZ(lbl_803034D8, c->ang[0], c->ang[1], c->ang[2]);
                            }
                            if (!(node->child->flags & 4)) {
                                njScale(lbl_803034D8, c->scl.x, c->scl.y, c->scl.z);
                            }
                            if (!(node->child->flags & 2)) {
                                njRotateXYZ(lbl_80303498, c->ang[0], c->ang[1], c->ang[2]);
                            }
                        }
                    }
                    njCalcPoint(lbl_803034D8, &lbl_802B0ED0, out->point);
                    fn_800A1690(lbl_80303498, out->rot);
                }
            }
        }
        if (lbl_80346D00 == NULL && node->child != NULL) {
            lbl_80346D00 = fn_8009ED04(node->child, anim, target, out);
        }
        njPopMatrixEx();
        fn_80291C44(lbl_80303498);
        njPopMatrixEx();
        fn_80291C44(lbl_803034D8);
        if (lbl_80346D00 == NULL && node->sibling != NULL) {
            lbl_80346D00 = fn_8009ED04(node->sibling, anim, target, out);
        }
    }
    return lbl_80346D00;
}

u32 *fn_800A10A8(u32 *base, u32 i, s32 n)
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
        dst[0] = lbl_80311970.ang[0];
    }
    if (flags & 2) {
        dst[1] = lbl_80311970.ang[1];
    }
    if (flags & 4) {
        dst[2] = lbl_80311970.w34;
    }
}

void *fn_800A1ABC(EvObj *b, u32 i)
{
    TblA *t = b->ext->info;
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

s32 fn_800A3E90(u16 id) {
    Task *it = fn_8010A164(id);
    if (it == NULL) {
        return 0;
    }
    it->state = 4;
    fn_800A39E0(it);
    return 1;
}

s32 fn_8009E840(Pool* pool, TNode8009D760* item, s32 n) {
    s32 i = 0;
    s32 idx = -1;
    TNode8009D760** s;
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
    if (idx == -1) item->state = 0xff;
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

u32 fn_800A1AE8(EvObj* o, u32 idx) {
    u32 cnt = 0;
    u32* p = o->ext->info;
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

f32 fn_8009E3D0(u32 flags, ModelNode *p, f32 *s) {
    void *m;
    f32 r;
    if (p == 0) {
        return 0.0f;
    }
    m = fn_801E1A2C(1, 0x40);
    njUnitMatrix(m);
    fn_801DD76C(m);
    njScale(m, s[0], s[1], s[2]);
    r = fn_8009DEF0(flags, m, p, s, 0.0f);
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

static inline void TaskLink(TNode8009D760* parent, TNode8009D760* t) {
    parent->f04 = t->f04;
    t->f04 = parent->f0C;
    parent->f0C = t;
    t->f0C = parent;
    if (t->f04 != 0) {
        t->f04->f0C = t;
    }
}

TNode8009D760* fn_8009D760(TNode8009D760* parent, void* cb, u16 a, Obj8009D760* obj) {
    TNode8009D760* t = fn_80226704(parent, cb, 0x270);
    Work8009D760* w;

    if (t == 0) {
        fn_801DBE1C(lbl_802B0EE8);
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
void fn_8009D400(CnkObject* node, ChunkSet** ent, s16** outp);
void fn_8009D400(CnkObject* node, ChunkSet** ent, s16** outp) {
    s16 *stream;
    s32 op;
    s16 *start;
    s32 total;
    s16 *p;
    s16 *out;
    if (node->model != NULL && !(node->flags & 8) && node->model->plist != NULL) {
        stream = node->model->plist;
        total = 0;
        p = stream;
        out = *outp;
        do {
            s32 n;
            s32 len;
            start = p;
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
                    s16 *q;
                    s32 m;
                    total++;
                    *out++ = ((u32)start - (u32)stream) >> 1; /* byte offset into the stream */
                    q = p;
                    m = *q++ & 0xffff3fff;
                    do {
                        s16 v0 = *q++;
                        s32 v = v0;
                        if (0 > v) v = -v;
                        total += v * 2;
                        do {
                            out[0] = q[1];
                            out[1] = q[2];
                            out += 2;
                            q += n;
                        } while (--v > 0);
                    } while (--m > 0);
                    break;
                }
                }
            }
            p += len;
        } while (op != 0xff);
        if (total != 0) {
            *out = -1;
            (*ent)->len = total + 1;
            (*ent)->plist = stream;
            (*ent)->offsets = *outp;
            *outp = out + 1;
            (*ent)++;
        }
    }
    if (node->child != NULL && !(node->flags & 0x10)) {
        fn_8009D400(node->child, ent, outp);
    }
    if (node->sibling != NULL) {
        fn_8009D400(node->sibling, ent, outp);
    }
}

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

s32 fn_800A35E0(EvObj *a)
{
    if (a != NULL && a->sub != NULL && a->sub->task != NULL) {
        switch (a->sub->task->state) {
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

void fn_800A1998(NJS_POINT3 *from, NJS_POINT3 *to, Ang3 *out, s8 mode, u8 flags) {
    NJS_POINT3 d;
    Ang3 ang;

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
    Pair_800A13D8 tmp;
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

void fn_800A2264(Sprite* o, NJS_POINT3* pos, s32 flags, s32 mode) {
    Quad q;
    u8 col[16];
    s16 uv[8];
    s32 i;
    Quad* qp = &q;
    s16 idx;

    q.pos = pos;
    q.col = col;
    q.uv = uv;
    q.n = 4;
    for (i = 0; i < 4; i++) {
        u8 a;
        if (i == 0 || i == 3) {
            a = o->colA[0];
        } else {
            a = o->colB[0];
        }
        if (o->mode == 1 && (i == 0 || i == 1)) {
            a = 0;
        }
        q.col[i * 4] = a;
        if (o->hasCol == 1) {
            if (i == 0 || i == 3) {
                q.col[i * 4 + 1] = o->colA[1];
                q.col[i * 4 + 2] = o->colA[2];
                q.col[i * 4 + 3] = o->colA[3];
            } else {
                q.col[i * 4 + 1] = o->colB[1];
                q.col[i * 4 + 2] = o->colB[2];
                q.col[i * 4 + 3] = o->colB[3];
            }
        } else {
            q.col[i * 4 + 3] = 255;
            q.col[i * 4 + 2] = 255;
            q.col[i * 4 + 1] = 255;
        }
        if (o->shade == 1) {
            f32 k = 0.003921569f * a;
            q.col[i * 4 + 1] = k * q.col[i * 4 + 1];
            q.col[i * 4 + 2] = k * q.col[i * 4 + 2];
            q.col[i * 4 + 3] = k * q.col[i * 4 + 3];
        }
    }
    if (o->tex != 0) {
        idx = o->idx;
        if (o->tex->nbTexture <= idx) {
            idx = o->tex->nbTexture - 1;
        }
        fn_80299040(o->tex);
        fn_80298FE4(idx);
        if (o->ox < -0x100) o->ox = 255;
        if (o->ox > 255) o->ox = -0x100;
        if (o->oy < -0x100) o->oy = 255;
        if (o->oy > 255) o->oy = -0x100;
        q.uv[0] = o->x0 + o->ox;
        q.uv[1] = o->y0 - o->oy;
        q.uv[2] = o->x1 + o->ox;
        q.uv[3] = o->y0 - o->oy;
        q.uv[4] = o->x1 + o->ox;
        q.uv[5] = o->y1 - o->oy;
        q.uv[6] = o->x0 + o->ox;
        q.uv[7] = o->y1 - o->oy;
    }
    {
        s32 f = 0x84000;
        if (mode == 1) {
            f = flags | 0x80000;
        }
        if (o->tex != 0) {
            fn_80035518(o->tex, idx, qp, 1, f);
        } else {
            fn_80035518(o->tex, idx, qp, 0, f);
        }
    }
}

typedef struct Sprite3D {
    f32 w;          /* 0x00 */
    f32 h;          /* 0x04 */
    s16 idx;        /* 0x08 texture index */
    u8 pad0a[2];
    s32 shade;      /* 0x0c scale the colour by the alpha byte */
    s32 hasCol;     /* 0x10 */
    u8 col[4];      /* 0x14 */
    s16 ox;         /* 0x18 texture scroll */
    s16 oy;         /* 0x1a */
    NJS_TEXLIST* tex; /* 0x1c */
} Sprite3D;
extern void njRotateZXY(NJS_MATRIX m, Angle x, Angle y, Angle z);

void fn_800A322C(Sprite3D* o, NJS_POINT3* pos, Angle ang, s32 unused, s32 flags, s32 mode) {
    Angle rx;
    Angle ry;
    Quad* qp;
    s16 idx;
    NJS_POINT3 pbuf[4];
    Quad q;
    u8 col[16];
    s16 uv[8];
    s32 i;
    f32 w;
    f32 h;

    rx = lbl_80311970.ang[0];
    ry = lbl_80311970.ang[1];
    qp = &q;
    q.pos = pbuf;
    q.col = col;
    q.uv = uv;
    q.n = 4;
    if (o->ox < -0x100) o->ox = 255;
    if (o->ox > 255) o->ox = -0x100;
    if (o->oy < -0x100) o->oy = 255;
    if (o->oy > 255) o->oy = -0x100;
    w = 0.5f * o->w;
    h = 0.5f * o->h;
    q.pos[0].x = -w;
    q.pos[0].y = h;
    q.pos[0].z = 0.0f;
    q.uv[0] = o->ox;
    q.uv[1] = -o->oy;
    q.pos[1].x = w;
    q.pos[1].y = h;
    q.pos[1].z = 0.0f;
    q.uv[2] = o->ox + 255;
    q.uv[3] = -o->oy;
    q.pos[2].x = w;
    q.pos[2].y = -h;
    q.pos[2].z = 0.0f;
    q.uv[4] = o->ox + 255;
    q.uv[5] = 255 - o->oy;
    q.pos[3].x = -w;
    q.pos[3].y = -h;
    q.pos[3].z = 0.0f;
    q.uv[6] = o->ox;
    q.uv[7] = 255 - o->oy;
    for (i = 0; i < 4; i++) {
        q.col[i * 4] = o->col[0];
        if (o->hasCol == 1) {
            q.col[i * 4 + 1] = o->col[1];
            q.col[i * 4 + 2] = o->col[2];
            q.col[i * 4 + 3] = o->col[3];
        } else {
            q.col[i * 4 + 3] = 255;
            q.col[i * 4 + 2] = 255;
            q.col[i * 4 + 1] = 255;
        }
        if (o->shade == 1) {
            q.col[i * 4 + 1] = 0.003921569f * (o->col[0] * q.col[i * 4 + 1]);
            q.col[i * 4 + 2] = 0.003921569f * (o->col[0] * q.col[i * 4 + 2]);
            q.col[i * 4 + 3] = 0.003921569f * (o->col[0] * q.col[i * 4 + 3]);
        }
    }
    if (o->tex != 0) {
        idx = o->idx;
        if (o->tex->nbTexture <= idx) {
            idx = o->tex->nbTexture - 1;
        }
        fn_80299040(o->tex);
        fn_80298FE4(idx);
    }
    njPushMatrixEx();
    fn_80286EE8();
    fn_8028B498();
    njTranslate(0, pos->x, pos->y, pos->z);
    njRotateZXY(0, rx, ry, ang);
    {
        s32 f = 0x84000;
        if (mode == 1) {
            f = flags | 0x80000;
        }
        if (o->tex != 0) {
            fn_80035518(o->tex, idx, qp, 1, f);
        } else {
            fn_80035518(o->tex, idx, qp, 0, f);
        }
    }
    njPopMatrixEx();
}

/* EvExt.info of the linked-objects kind (fn_800A39E0): a count-prefixed word table of
 * (name offset into EvObj.x1dc, order) pairs from word 2 on. */
typedef struct {
    u32 off;    /* name offset */
    u32 order;
} EvNameRef;
typedef struct {
    s32 count;  /* 0x00 number of words present */
    u32 x4;     /* 0x04 */
    EvNameRef refs[1]; /* 0x08 */
} EvInfoNames;
static inline EvInfoNames* NamesInfo(EvObj* e) {
    return e->ext->info;
}

void fn_800A3680(EvObj *obj)
{
    Task *r;
    EvNameRef *e;
    s32 i;
    EvInfoNames *t;
    s32 n;
    u8 *base;
    EvObj *sub;

    t = NamesInfo(obj);
    if (t != NULL) {
        n = t->count;
        base = obj->x1dc;
        e = t->refs;
        obj->x1fc = 0;
        for (i = 1; i < n - 1; e++, i += 2) {
            r = fn_8010A164(base + e->off);
            if (r != NULL) {
                sub = r->work;
                if (sub->x26c == 1) {
                    EvSub *m = sub->sub;
                    r->state = 0xff;
                    m->task->func(r);
                    if (fn_800A35E0(sub) == 1) {
                        EvObj *s2 = r->work;
                        s2->x1fb = 1;
                        r->state = 1;
                    }
                }
            }
        }
    }
}

extern Rec* fn_800CCA6C(s32, u32);
extern void fn_80210B44(void*);
extern void fn_800A3744(EvObj*);
extern s32 fn_800A37E8(EvObj*, s32);
extern s32 fn_8015F218(EvObj*);
extern void fn_8010953C(void*);

static inline s32 EventActive(void) {
    s32 f = 0;
    s32 t = lbl_80311AC0.map;
    if (t >= 500 && t < 600) f = 1;
    f = f != 0;
    return f;
}

static inline void InitMax(EvObj* v)
{
    EvInfoNames* tb;
    EvNameRef* q;
    s32 i;
    u32 max = 0;
    v->x1fc = max;
    tb = NamesInfo(v);
    q = tb->refs;
    for (i = 1; i < tb->count - 1; i += 2) {
        if (q->order > max) max = q->order;
        q++;
    }
    v->x1fe = max + 1;
}

void fn_800A39E0(Task* o) {
    EvObj* w = o->work;
    Rec* r;
    switch (o->state) {
    case 0: {
        InitMax(o->work);
        fn_8015ED90(o);
        w->x26c = 1;
        o->state = 1;
    }
    case 1:
        r = fn_800CCA6C(9, w->ext->x04 & 0xffff);
        if (r != 0) {
            s32 k;
            RecSub* sb = r->pc;
            sb->x0 = 2;
            k = r->id >> 16;
            if (k < 3) fn_80210B44(sb->p4);
            switch (k) {
            case 1: o->state = 2; break;
            case 2: fn_800A3744(w); break;
            }
        }
        if (!EventActive()) fn_8015E600(w);
        break;
    case 2: {
        if (!EventActive()) fn_8015E600(w);
        if (fn_800A37E8(w, 0) == 0) o->state = 1;
        switch (fn_8015F218(w)) {
        case 2:
            fn_800A3744(w);
            o->state = 1;
            break;
        case 3:
            o->flags |= 0x20;
            o->state = 4;
            break;
        }
        break;
    }
    case 3:
    case 5:
        break;
    case 4:
        fn_8015EBF4(o->work);
        fn_800A3680(w);
        o->flags |= 0x40;
        fn_8010953C(w->x1cc);
        if (w->x1cc != 0) fn_801E1784(w->x1cc);
        break;
    case 0xff:
        fn_8015EBF4(o->work);
        fn_800A3744(w);
        o->flags |= 0x40;
        break;
    }
}

/* Matches only with the self-assignment after the length call: without a
   store to d there, MWCC keeps d.z in f30 across the calls where the original
   reloads it. Rotates p about the Y axis through c by angle a (XZ plane). */
void fn_800A12D8(Vec3_800A12D8 *p, Vec3_800A12D8 *c, Angle a)
{
    Vec3_800A12D8 d;
    f32 s;
    f32 co;

    d = *p;
    d.x -= c->x;
    d.z -= c->z;
    if (d.x || d.z) {
        fn_80291A5C(d.x * d.x + d.z * d.z);
        d.x = d.x;
        s = njSin(a);
        co = njCos(a);
        p->x = d.x * co - d.z * s;
        p->z = d.x * s + d.z * co;
        p->x += c->x;
        p->z += c->z;
    }
}
void fn_800A3744(EvObj *obj)
{
    Task *r;
    EvNameRef *e;
    s32 i;
    EvInfoNames *t;
    s32 n;
    u8 *base;
    EvObj *sub;

    t = NamesInfo(obj);
    if (t != NULL) {
        n = t->count;
        base = obj->x1dc;
        e = t->refs;
        obj->x1fc = 0;
        for (i = 1; i < n - 1; e++, i += 2) {
            r = fn_8010A164(base + e->off);
            if (r != NULL) {
                sub = r->work;
                if (sub->x26c == 1 && fn_800A35E0(sub) == 1) {
                    EvObj *s2 = r->work;
                    s2->x1fb = 1;
                    r->state = 1;
                }
            }
        }
    }
}
void bss_order_stub(void);

/* state */

/* Layout stub, NOT part of the merge: MWCC lays the pooled .bss arrays out in order of first use in
 * the file. In the unit, fn_8009C518 (earlier) sets that order; this stub stands in for it here. */
void bss_order_stub(void) { lbl_803033B0[0] = 0; lbl_803033C8[0] = 0; lbl_803033E0[0] = 0; lbl_803033F8[0] = 0; }

void fn_800A2830(Emit_800BA444* e, NJS_POINT3* pos, Angle* ang) {
    VertexCol vc[4];
    VertexTex vt[4];
    Colour4 col;
    f32 w;
    f32 h;
    f32 k;
    f32 du;
    f32 dv;
    s16 idx;
    u8 a;

    w = 0.5f * e->x;
    h = 0.5f * e->y;
    a = e->x14;
    col.c[0] = a;
    if (e->x10 == 1) {
        col.c[1] = e->x15;
        col.c[2] = e->x16;
        col.c[3] = e->x17;
    } else {
        col.c[1] = col.c[2] = col.c[3] = 0xff;
    }
    if (e->xc != 0) {
        k = 0.003921569f * a;
        col.c[1] = col.c[1] * k;
        col.c[2] = col.c[2] * k;
        col.c[3] = col.c[3] * k;
    }
    njPushMatrixEx();
    fn_80286EE8();
    fn_8028B498();
    njTranslateEx(pos);
    njRotateEx(ang, 1);
    if (e->x1c != 0) {
        idx = e->x8;
        if (e->x1c->nbTexture <= idx) {
            idx = e->x1c->nbTexture - 1;
        }
        fn_80299040(e->x1c);
        fn_80298FE4(idx);
        if (e->x18 == 0 && e->x1a == 0) {
            vt[0].u = vt[1].u = vt[0].v = vt[2].v = 0.0f;
            vt[2].u = vt[3].u = vt[1].v = vt[3].v = 1.0f;
        } else {
            if (e->x18 < -0x100) {
                e->x18 = 0xff;
            } else if (e->x18 > 0xff) {
                e->x18 = -0x100;
            }
            if (e->x1a < -0x100) {
                e->x1a = 0xff;
            } else if (e->x1a > 0xff) {
                e->x1a = -0x100;
            }
            du = 0.003921569f * e->x18;
            dv = 0.003921569f * -e->x1a;
            vt[0].u = vt[1].u = du;
            vt[2].u = vt[3].u = 1.0f + du;
            vt[0].v = vt[2].v = dv;
            vt[1].v = vt[3].v = 1.0f + dv;
        }
        if (e->xa != 0) switch (e->xa) {
        case 0:
            break;
        case 1:
            {
                f32 t1, t0;
                SWAP(vt[0].u, vt[2].u, t0);
                SWAP(vt[3].u, vt[1].u, t1);
            }
            break;
        case 2:
            {
                f32 t1, t0;
                SWAP(vt[0].v, vt[1].v, t0);
                SWAP(vt[3].v, vt[2].v, t1);
            }
            break;
        case 3:
            {
                f32 t1, t0;
                ROT4(vt[0].u, vt[1].u, vt[3].u, vt[2].u, t0);
                ROT4(vt[0].v, vt[1].v, vt[3].v, vt[2].v, t1);
            }
            break;
        case 4:
            {
                f32 t3, t2, t1, t0;
                SWAP(vt[0].u, vt[3].u, t0);
                SWAP(vt[1].u, vt[2].u, t1);
                SWAP(vt[0].v, vt[3].v, t2);
                SWAP(vt[1].v, vt[2].v, t3);
            }
            break;
        case 5:
            {
                f32 t1, t0;
                ROT4(vt[0].u, vt[2].u, vt[3].u, vt[1].u, t0);
                ROT4(vt[0].v, vt[2].v, vt[3].v, vt[1].v, t1);
            }
            break;
        }
        vt[0].z = vt[2].z = vt[3].z = vt[1].z = 0.0f;
        vt[0].x = vt[1].x = -w;
        vt[0].y = vt[2].y = h;
        vt[2].x = vt[3].x = w;
        vt[3].y = vt[1].y = -h;
        vt[0].colour = vt[1].colour = vt[2].colour = vt[3].colour = col;
        fn_80296EEC(0, 3, 0);
        fn_8028A8C0(vt, 4, 1);
        fn_80296EEC(1, 3, 1);
    } else {
        vc[0].z = vc[2].z = vc[3].z = vc[1].z = 0.0f;
        vc[0].x = vc[1].x = -w;
        vc[0].y = vc[2].y = h;
        vc[2].x = vc[3].x = w;
        vc[3].y = vc[1].y = -h;
        vc[0].colour = vc[1].colour = vc[2].colour = vc[3].colour = col;
        fn_80296EEC(0, 3, 0);
        fn_8028A418(vc, 4, 1);
        fn_80296EEC(1, 3, 1);
    }
    njPopMatrixEx();
}
