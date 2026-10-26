#include "types.h"
#include <string.h>
#include "game/util.h"

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
} Tbl;
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
extern u8 *lbl_80346DCC;
extern u32 lbl_80346DD0;
extern u32 lbl_80346DD4;
extern u8 *lbl_80346E3C;
extern s32 lbl_80346E38;
extern s32 lbl_8034757C;
extern void fn_801CC434(void* p, s32 zero, void* out);
extern void fn_80109A94(void* p);
extern void fn_800D2CA8(s32 x);
extern void fn_80100E68(void* p, s32 zero, s32 a, s32 b);
extern void fn_801E17E0(void* p);
extern void *fn_801E1C7C(u32 size);
extern s32 fn_800F7D6C(void *p);
extern s32 fn_801D6E38(s32 a);
extern void fn_801E1AC8(u16 a, u8 b, s32 c, s32 d);
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
extern void* fn_801E1C7C(u32 n);
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
extern u32 lbl_80347450;
extern s32 fog_enabled;
extern void fn_80100B74(void* o);
extern void fn_800D2B1C(void* p);
extern u32 fn_801096FC(s32 a, s32 b, void* c, s32 d);
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
typedef struct Sub {
    u8 pad0[0x100];
    void* p100;
    u8 pad104[0x170 - 0x104];
    s16 s170;
    s16 s172;
} Sub;
typedef struct Obj_8010DE84 {
    u8 pad0[0x19];
    u8 st;
    u8 pad1a[0x24 - 0x1a];
    Sub* p24;
} Obj_8010DE84;
extern void fn_80227810(void* p);
extern void fn_8010DDBC(void* o);
extern s32 lbl_803473DC;
extern u8 lbl_80310B3C[];
extern s32 lbl_803473E4;
extern s32 lbl_80347444;
extern s32 lbl_803473E8;
extern void *lbl_80346D98;
extern void *lbl_803475A0;
typedef struct {
    u8 pad0[0x24];
    void *p24;
} Task;
void *fn_80227E84(s32 size);
s32 fn_800FF48C(void *cb, s32 arg);
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
s32 fn_801C6068(void *p, s32 x);
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
void *fn_801094C8(u32 idx);
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
typedef struct K06B {
    u8 pad0[0xc];
    s32 f0c;
    s32 f10;
} K06B;
extern K06A *lbl_80311A60[];
extern K06B *lbl_80346E14;
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
    s32 f28;
} K06Rec;
extern s32 lbl_803475D8;
extern s32 lbl_80346E30;
extern K06Rec *lbl_80346E34;
void *memcpy(void *dst, const void *src, u32 n);
typedef struct K06W {
    u8 pad0[4];
    s32 w4;
    u8 b8;
} K06W;
extern char lbl_802B2348[];
extern u8 lbl_80305CF0[];
extern K06W lbl_80311AC0;
extern s32 lbl_80311AD4[];
extern s32 lbl_80347464;
void fn_8025F120(void *a, char *b);
void fn_800FF908(void);
void fn_801F7B04(s32 a);
extern s32 lbl_8034746C;
extern char lbl_802B23B8[];
void GXInvalidateTexAll(void);
void fn_801CC434(void *p, s32 zero, void *out);
void fn_8025F0B0(void *a, void *b);
s32 fn_8025EF88(void *a, char *b);
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
extern s32 fn_801C6068(void *obj, s32 kind);
extern void SePlay(s32 a, s8 id, s8 vol);
extern void fn_801C6170(void *obj);
extern u8 *lbl_80347460;
extern u8 *lbl_80346E58;
extern void fn_801E17E0(void *p);
extern void fn_8014912C(void);
extern s32 lbl_8034745C;
extern u8 *fn_801E1A74(s32 a, u32 b);
extern u16 TextReadChar(const u8 **pp);
extern s8 lbl_802E4C70[];
extern void fn_8010C0E4(u8 *obj, u8 *n);
typedef struct {
    f32 x;
    f32 y;
    f32 z;
    u32 w;
} Quad;
extern f32 fn_801DBD9C(f32 v);
extern void fn_80290ED4(Quad *q, s32 n, s32 m);

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
    *(u32 *)(lbl_80346DCC + 0x160c) = 0;
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
    if (*(u32 *)(lbl_80310B3C + 0x88) & 0x10) {
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
    fn_80109A94(buf);
}

void* fn_801005F8(Tbl* t, u16 key) {
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
    fn_801E1AC8((u16)lbl_80311AC0.w4, lbl_80311AC0.b8, a, b);
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
    fn_801096FC(1, a, (void*)b, c);
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
    if (fn_801096FC(0, a, b, 0) == 0) {
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

void fn_8010DE84(Obj_8010DE84* o) {
    if (o->st == 0) {
        Sub* p = o->p24;
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
    Task *t;

    if (lbl_803473DC == 0) {
        if ((*(u32 *)(lbl_80310B3C + 0x84) & 0x80000000) == 0) {
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
            d->f28 = id;
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
        idx = (s8)(lbl_80311AC0.b8 - 0x61);
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

    link = &lbl_80347460;
    n = lbl_80347460;
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

    node = lbl_80347460;
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

    link = &lbl_80347460;
    n = lbl_80347460;
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

    node = lbl_80347460;
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

    link = &lbl_80347460;
    n = lbl_80347460;
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

    node = lbl_80347460;
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

    node = lbl_80347460;
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

void fn_8010C7A0(u32 id, f32 a, f32 b, f32 c, f32 d, f32 e) {
    Quad q[4];
    f32 f;
    u32 id24;

    f = fn_801DBD9C(e);
    id24 = id & 0xffffff;
    q[0].x = a;
    q[0].y = b;
    q[0].z = f;
    q[0].w = id24;
    q[1].x = a;
    q[1].y = b + d;
    q[1].z = f;
    q[1].w = id;
    q[2].x = a + c;
    q[2].y = b;
    q[2].z = f;
    q[2].w = id24;
    q[3].x = a + c;
    q[3].y = b + d;
    q[3].z = f;
    q[3].w = id;
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
