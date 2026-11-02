#include "types.h"
#include "string.h"
#include <math.h>
#include "ninja.h"
#include "game/drawstate.h"
#include "game/task.h"
#include "game/evobj.h"
#include <dolphin/os/OSFastCast.h>
typedef struct TblA {
    u32 count;
    u32 items[1];
} TblA;
typedef struct SubA {
    u8 pad_00[0x10];
    TblA *tbl_10;
} SubA;
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
typedef struct TNode8009D760 TNode8009D760;
typedef struct {
    TNode8009D760** slots;
    s32 count;
} Pool;
void* fn_801E1A2C(s32 a, u32 size);
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
extern void fn_800ABEB0(void);
/* Four separate .bss arrays of the unit, reached through its section base. */
extern s32 lbl_803033B0[6];
extern s32 lbl_803033C8[6];
extern s32 lbl_803033E0[6];
extern s32 lbl_803033F8[6];
extern s32 lbl_803033B0[6];
extern s32 lbl_803033C8[6];
extern s32 lbl_803033E0[6];
extern s32 lbl_803033F8[6];
extern void* fn_801C8930(void* h);
extern void fn_80100B74(Task* t);
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
extern void fn_800ABEB0();
extern void fn_800ABE9C();
typedef struct {
    u16* w0;
    NJS_POINT3* w4;
    Angle* w8;
    u8 pad0[0x24 - 0xc];
    f32 f24, f28, f2c, f30;
    s32 w34, w38;
    s32 w3c, w40;
    s32 w44, w48, w4c, w50;
    f32 f54;
    s32 w58;
    NJS_TEXLIST* w5c;
    s32 w60;
    u32* w64;
    s32 w68;
    u32* w6c;
    s32 w70;
    f32 f74, f78;
} P;
extern s32 rand(void);
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
/* Scales a 0..1 float to a u8 (x * 255) with the SDK fast cast (psq_st through GQR2).
 * The original calls the Dolphin SDK inline __OSf32tou8 from <dolphin/os/OSFastCast.h>.
 * The game code itself is plain C. Siblings: fn_8009E4B8 = __OSu8tof32(b) * K,
 * fn_8009E4D4 = __OSf32tou8((K0 + x) * 255). */
typedef unsigned char u8;
typedef float f32;
typedef struct {
    s32 x, y, z;
} Ang3;
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
typedef struct Item_800AE000 { s32 w0; u32 w4; } Item_800AE000;
/* EvExt.info of the timed-sound kind (fn_800AE000). */
typedef struct {
    u32 count;      /* 0x00 */
    u8 pad4[0x24 - 4];
    f32 x24;        /* 0x24 */
    u32 x28;        /* 0x28 */
} EvInfoTimer;
static inline EvInfoTimer* TimerInfo(EvObj* e) {
    return e->ext->info;
}
extern s32 fn_8015E600(EvObj*);
extern void fn_800972AC(void);
extern EvObj* fn_8015F180(EvObj*);
extern void fn_80097294(s32);
extern void fn_800970D8(u16, s32, f32);
extern void fn_800970B4(u16, s32, f32);
extern void fn_8015EBF4(EvObj*);
/* Byte (0..255) to a 0..1 float: __OSu8tof32(&b) * (1/255).
 * Needs the Dolphin SDK fast-cast inline __OSu8tof32 (psq_l through GQR2), which our
 * extern/sdk OSFastCast.h lacks. The SDK's definition is reproduced here only until it is
 * added to <dolphin/os/OSFastCast.h>; the game code itself is the one-line function. */
typedef unsigned char u8;

#define BSW(x) ((((x) >> 24) & 0xff) | (((x) >> 8) & 0xff00) | (((x) << 8) & 0xff0000) | ((x) << 24))

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

void fn_800ADF98(u8* o) {
    u8* a = *(u8**)(o + 0x1c8);
    u8* t = *(u8**)(a + 0x10);
    s32 v = *(s32*)(t + 0x44);
    if ((s32)fabsf((f32)v) == 1) {
        fn_8009DCA8((Obj8009DCA8*)o, (Src8009DCA8*)(t + 0x24));
    }
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
void* fn_8009E8B0(s32 n);

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
    dst->f24 += dst->f28 * (3.0517578125e-05f * (f32)rand());
    dst->f2c += dst->f30 * (3.0517578125e-05f * (f32)rand());
}

/* EvExt.info of the ring-emitter kind (fn_800AC728). */
typedef struct {
    u32 count;              /* 0x00 */
    u8 pad04[0x24 - 0x04];
    Src8009DCA8 blend;      /* 0x24 */
    u32 x44;                /* 0x44 */
    f32 x48;                /* 0x48 radius */
    s32 x4c;                /* 0x4C count */
    u32 x50;                /* 0x50 mode */
    f32 x54;                /* 0x54 */
    f32 x58, x5c, x60, x64; /* 0x58 */
    f32 x68, x6c;           /* 0x68 */
    s32 x70, x74, x78, x7c; /* 0x70 */
    s32 x80, x84;           /* 0x80 */
    f32 x88;                /* 0x88 */
    s32 x8c;                /* 0x8C */
    u32 x90;                /* 0x90 */
} EvInfoRing;
static inline EvInfoRing* RingInfo(EvObj* e) {
    return e->ext->info;
}
/* One ring point of fn_800AC728 (EvObj.x25c). */
typedef struct {
    NJS_POINT3 pos;  /* 0x00 */
    u8 pad0c[4];
    s32 x10;         /* 0x10 */
    u8 pad14[4];
} RingPart;
u32 *fn_800A10A8(u32 *base, u32 i, s32 n);
void *fn_800A1ABC(EvObj *b, u32 i);
u32 fn_800A1AE8(EvObj* o, u32 idx);
void fn_800A1210(NJS_VECTOR *out, NJS_VECTOR *in, Angle deg, f32 radius);

void fn_800AC728(EvObj *w, P *p)
{
    RingPart *pt;
    s32 mode;
    s32 i;
    s32 acc;
    f32 radius;
    s32 k;
    f32 t;

    radius = RingInfo(w)->x48;
    w->x22c = RingInfo(w)->x4c;
    if (w->x22c != 0) {
        w->x25c = fn_801E1A2C(1, w->x22c * 0x18);
    }
    pt = w->x25c;
    mode = RingInfo(w)->x50;
    w->x258 = RingInfo(w)->x54;
    w->x22e = RingInfo(w)->x80;
    w->x230 = RingInfo(w)->x84;
    if (w->x22e == 0) {
        w->x22e = 1;
    }
    w->x1fc = RingInfo(w)->x90 != 0 ? RingInfo(w)->x90 : -1;
    p->f24 = RingInfo(w)->x58;
    p->f28 = RingInfo(w)->x5c;
    p->f2c = RingInfo(w)->x60;
    p->f30 = RingInfo(w)->x64;
    p->w3c = 182.04445f * RingInfo(w)->x68;
    p->w40 = 182.04445f * RingInfo(w)->x6c;
    p->w44 = RingInfo(w)->x70;
    p->w48 = RingInfo(w)->x74;
    p->w4c = RingInfo(w)->x78;
    p->w50 = RingInfo(w)->x7c;
    p->f54 = RingInfo(w)->x88;
    if (p->f54 == 0.0f) {
        p->f54 = 1.0f;
    }
    p->w58 = RingInfo(w)->x8c;
    p->w64 = fn_800A1ABC(w, 0x24);
    p->w60 = fn_800A1AE8(w, 0x24);
    p->w5c = w->texlist;
    p->w70 = 0;
    p->w68 = 0;
    p->w6c = fn_800A10A8(p->w64, p->w70, p->w60);
    p->f74 = 16.0f;
    p->f78 = 16.0f;
    p->w4 = &w->x24c;
    p->w8 = &w->x20c;
    w->point = 0;
    p->w0 = &w->point;
    w->x1fb = 0;
    w->x1fa = 0;
    for (i = 0, acc = 0; i < w->x22c; pt++, i++) {
        NJS_VECTOR v = {0.0f, 0.0f, 0.0f};
        if (i == 0) {
            pt->x10 = 0;
        } else {
            pt->x10 = w->x230 * (3.0517578125e-05f * rand());
        }
        if (mode == 1) {
            fn_800A1210(&pt->pos, &v, 360.0f * (3.0517578125e-05f * rand()), radius);
        } else {
            fn_800A1210(&pt->pos, &v, acc, radius);
            acc += 360 / w->x22c;
        }
    }
    if (RingInfo(w)->x44 == 1) {
        w->pivotPos.x = RingInfo(w)->blend.f08;
        w->pivotPos.y = RingInfo(w)->blend.f0C;
        w->pivotPos.z = RingInfo(w)->blend.f10;
        w->pivotAng[0] = RingInfo(w)->blend.i14;
        w->pivotAng[1] = RingInfo(w)->blend.i18;
        w->pivotAng[2] = RingInfo(w)->blend.i1C;
        w->pivot = 1;
    } else {
        w->pivotPos.x = w->pivotPos.y = w->pivotPos.z = 0.0f;
        w->pivotAng[0] = w->pivotAng[1] = w->pivotAng[2] = 0;
        w->pivot = 0;
    }
    t = ceil((f32)p->w4c / (s32)w->x22e); /* signed divide: x22e is a u16 count */
    k = (f32)ceil((1.0f + t) * w->x22c);
    w->x264 = fn_8009E8B0(k);
    w->x236 = k;
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

void fn_800AE000(Task* o) {
    EvObj* w = o->work;
    switch (o->state) {
    case 0:
    case 0xfe:
        w->x26c = 1;
        w->motionId = 0;
        w->x1fb = 0;
        fn_8015ED90(o);
        if (TimerInfo(w)->count < 10) {
            o->state = 4;
            break;
        }
        o->state = 1;
    case 1:
        fn_8015E600(w);
        if (w->x1fb != 0) {
            if (w->x24c.x > 0.0f) {
                fn_800972AC();
                w->motionId = 0;
                w->x24c.x = 0.0f;
            }
            w->x1fb = 0;
        }
        break;
    case 2: {
        ItemList* t;
        s32 n;
        fn_8015E600(w);
        t = w->ext->items;
        n = t->count;
        if ((n > 0 ? t->items[0] : 0) == 0 || (n > 1 ? t->items[1] : 0) == 0) {
            o->state = 1;
            break;
        }
        switch (w->motionId) {
        case 0: {
            EvObj* p = fn_8015F180(w);
            f32 f = TimerInfo(p)->x24;
            Item_800AE000* a;
            Item_800AE000* b;
            u32 x, y, z;
            s32 cnt;
            fn_80097294(7);
            fn_800970D8(w->x17a, 0, f);
            fn_800970B4(w->x17a, 1, f);
            t = w->ext->items;
            a = t->count > 0 ? t->items[0] : 0;
            x = a->w4;
            b = t->count > 1 ? t->items[1] : 0;
            y = b->w4;
            cnt = TimerInfo(p)->count;
            z = cnt > 9 ? TimerInfo(p)->x28 : 0;
            w->x24c.x = z;
            {
                f32 m = x > y ? (f32)x * f : (f32)y * f;
                w->x24c.x += m;
            }
            w->motionId = 1;
            break;
        }
        case 1:
            w->x24c.x -= 1.0f;
            if (w->x24c.x <= 0.0f) {
                fn_800972AC();
                w->motionId = 0;
                o->state = 1;
                w->x1fb = 0;
            }
            break;
        }
        break;
    }
    case 3:
    case 0xff:
        fn_8015EBF4(w);
        fn_80100B74(o);
        break;
    case 4:
        if (TimerInfo(w)->count >= 10) o->state = 1;
        break;
    }
}

extern void fn_800A619C(TNode8009D760* t);
TNode8009D760 *fn_8009E530(Pool *list, s32 count);
s32 fn_8009E840(Pool* pool, TNode8009D760* item, s32 n);
TNode8009D760* fn_8009D760(TNode8009D760* parent, void* cb, u16 a, Obj8009D760* obj);

void fn_800AB834(TNode8009D760* t) {
    TNode8009D760* n;
    Work8009D760* w = t->work;
    s32 count;

    n = fn_8009E530(w->f264, w->h236);
    if (n != NULL) {
        n->state = 6;
    } else {
        count = w->obj->params->count;
        if (count <= 0) {
            count = 1;
        }
        n = fn_8009D760(t, fn_800A619C, w->s178, w->obj);
        n->work->f260 = fn_801E1A2C(1, count << 7);
        n->work->s238 = fn_8009E840(w->f264, n, w->h236);
        n->work->s206 = count;
    }
    n->work->h234 = w->h234;
    n->work->s204 = w->obj->params->f58;
    if (n->work->s204 < 0) {
        n->work->s204 = 0;
    }
}
void bss_order_stub(void);

/* state */

/* Layout stub, NOT part of the merge: MWCC lays the pooled .bss arrays out in order of first use in
 * the file. In the unit, fn_8009C518 (earlier) sets that order; this stub stands in for it here. */
void bss_order_stub(void) { lbl_803033B0[0] = 0; lbl_803033C8[0] = 0; lbl_803033E0[0] = 0; lbl_803033F8[0] = 0; }
