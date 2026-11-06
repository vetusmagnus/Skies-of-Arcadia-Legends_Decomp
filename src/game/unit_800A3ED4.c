#include "types.h"
#include "string.h"
#include <math.h>
#include "ninja.h"
#include "game/drawstate.h"
#include "game/task.h"
#include "game/evobj.h"
#include <dolphin/os/OSFastCast.h>
#include "game/unit_800972AC.h"
#include "game/camera_803119E0.h"
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
void* fn_801E1A2C(s32 a, u32 size);
extern void fn_800A0028(void *self);
typedef struct Obj_800A3ED4 Obj_800A3ED4;
typedef struct State_800ADED0 {
    u8 pad0[4];
    Obj_800A3ED4* task; /* 0x004 */
    u8 pad8[0x178 - 8];
    s32 w178;
    u8 pad17c[0x1a0 - 0x17c];
    s32 w1a0;
    u8 pad1a4[0x260 - 0x1a4];
    void* x260;
    u8 pad264[0x31c - 0x264];
    void* x31c;
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
extern void fn_80100B74(void* t);
extern void* fn_80226704(void* list, void* cb, s32 size);
extern void* fn_8009D5BC();
extern void fn_800ABEB0();
extern void fn_800ABE9C();
typedef struct {
    u16* w0;
    NJS_POINT3* w4;
    Angle* w8;
    NJS_POINT3 off;
    u8 pad18[0x24 - 0x18];
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
    s32 w6c;
    s32 w70;
    f32 f74, f78;
} P;
extern s32 rand(void);
typedef struct Tbl_800A3ED4 {
    s32 n;
    u32 w[8];
} Tbl_800A3ED4;
typedef struct Tbl2_800A3ED4 {
    u32 n;
    void* w[2];
} Tbl2_800A3ED4;
typedef struct Src_800A3ED4 {
    u8 pad0[4];
    s32 w4;
    u8 pad8[8];
    void* p10; /* per-kind info record; Tbl_800A3ED4 for the effect list */
    u8 pad14[0x1c - 0x14];
    Tbl2_800A3ED4* p1c;
    u8 pad20[4];
    char name[0x38 - 0x24];
    void* p38;
    u8 pad3c[0x44 - 0x3c];
    NJS_POINT3 v44;
    f32 f50, f54, f58;
    NJS_POINT3 v5c;
} Src_800A3ED4;
typedef struct Sub_800A3ED4 Sub_800A3ED4;
/* The list of effect records fn_800A40B0 builds: a header, then the records. */
typedef struct Grp_800A40B0 {
    s32 n;
    Src_800A3ED4* recs;
    s32 w8, wc, w10;
    Src_800A3ED4 rec[1];
} Grp_800A40B0;
struct Sub_800A3ED4 {
    s16 h0;
    u8 pad2[2];
    Obj_800A3ED4* task;
    u8 pad8[0x18 - 8];
    u32 x18;
    f32 alpha;
    f32 x20;
    f32 x24;
    f32 x28;
    s32 w2c;
    s32 w30;
    s32 w34;
    NJS_POINT3 v38;
    Ang3 ang;
    NJS_POINT3 v50;
    NJS_POINT3 vel;
    u8 pad68[0xb4 - 0x68];
    NJS_POINT3 pivotPos;
    Angle pivotAng[3];
    u8 padcc[0xe4 - 0xcc];
    void* we4;
    NJS_MOTION* motion;
    void* wec;
    u8 padf0[0x100 - 0xf0];
    NJS_TEXLIST* w100;
    u8 pad104[0x16c - 0x104];
    s16 pivot;
    s16 h16e;
    u16 motionId;
    u16 x172;
    u8 pad174[2];
    u16 id;
    u16 h178;
    u16 h17a;
    u8 pad17c[0x184 - 0x17c];
    s32 hidden;
    u8 pad188[4];
    f32 x18c;
    f32 f190;
    u8 pad194[4];
    s32 x198;
    s32 x19c;
    s32 w1a0;
    u8 pad1a4[0x1a8 - 0x1a4];
    f32 f1a8;
    u8 pad1ac[0x1c8 - 0x1ac];
    Src_800A3ED4* p1c8;
    Grp_800A40B0* x1cc;
    u8 pad1d0[0x1d8 - 0x1d0];
    State_800ADED0* p1d8;
    s32 x1dc;
    u8 pad1e0[0x1ec - 0x1e0];
    s8 x1ec;
    u8 pad1ed[0x1fa - 0x1ed];
    s8 x1fa;
    s8 x1fb;
    s16 x1fc;
    u8 pad1fe[0x204 - 0x1fe];
    s16 x204;
    s16 x206;
    s16 x208, x20a;
    Ang3 x20c;
    s32 x218;
    u8 x21c;
    u8 x21d;
    u8 x21e, x21f, x220, x221, x222;
    u8 pad223[0x22c - 0x223];
    u16 x22c;
    u16 x22e;
    u16 x230;
    u16 point;
    u16 x234;
    u16 x236;
    u16 x238;
    u8 pad23a[0x24c - 0x23a];
    NJS_POINT3 x24c;
    f32 x258;
    void* x25c;
    void* x260; /* per-kind record: P (fn_800A9708/fn_800A8FE0), Emit (fn_800A6F30...) */
    void* x264; /* ItemList on the parent objects, the point buffer of fn_800A4924 */
    void* x268;
    u8 x26c;
};
struct Obj_800A3ED4 {
    void* func;
    u8 pad4[4];
    Obj_800A3ED4* parent;
    Obj_800A3ED4* x0c;
    u8 pad10[0x18 - 0x10];
    u8 flags;
    u8 state;
    u8 pad1a;
    u8 prio;
    u8 pad1c[4];
    f32 f20;
    Sub_800A3ED4* sub;
    u8 pad28[0x40 - 0x28];
    u8 area[0x270 - 0x40];
};
extern void* fn_800C355C(NJS_TEXLIST** out, Src_800A3ED4* ctx, s32 idx);
void fn_8009DCA8(Sub_800A3ED4* o, Src8009DCA8* src);
extern s32 lbl_80311AD4[];
extern MapInfo lbl_80311AC0;
extern void fn_800A0E1C(Sub_800A3ED4* o);
extern void fn_8009E578(Obj_800A3ED4* n);
extern void fn_8015EB8C(Sub_800A3ED4* p, s32 id, void* cb);
void fn_8009E71C(ItemList* s, s32 n);
extern void fn_800A4924(Obj_800A3ED4* t);
/* Scales a 0..1 float to a u8 (x * 255) with the SDK fast cast (psq_st through GQR2).
 * The original calls the Dolphin SDK inline __OSf32tou8 from <dolphin/os/OSFastCast.h>.
 * The game code itself is plain C. Siblings: fn_8009E4B8 = __OSu8tof32(b) * K,
 * fn_8009E4D4 = __OSf32tou8((K0 + x) * 255). */
typedef unsigned char u8;
typedef float f32;
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
extern s32 fn_8015E600(void*);
extern void fn_800972AC(void);
extern void* fn_8015F180(void*);
extern void fn_80097294(s32);
extern void fn_800970D8(u16, s32, f32);
extern void fn_800970B4(u16, s32, f32);
extern void fn_8015EBF4(void*);
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

/* EvExt.info head of the objects that carry a blend source (fn_8009DCA8). */
typedef struct {
    u8 pad00[0x24];
    Src8009DCA8 blend; /* 0x24 */
    s32 mode;          /* 0x44 */
} EvInfoBlend;
static inline EvInfoBlend* BlendInfo(Sub_800A3ED4* e) {
    return e->p1c8->p10;
}

void fn_800ADF98(Sub_800A3ED4* o) {
    EvInfoBlend* t = BlendInfo(o);
    if ((s32)fabsf((f32)t->mode) == 1) {
        fn_8009DCA8(o, &t->blend);
    }
}

void fn_800ADED0(Sub_800A3ED4 *self, State_800ADED0 *st)
{
    EvInfoBlend* c = BlendInfo(self);
    s32 k = (s32)fabsf((f32)c->mode);
    if (k == 1) {
        fn_8009DCA8(self, &c->blend);
    } else if (k == 0) {
        if (st->w178 == 1 || st->w178 == 3) {
            if (self->x1fa == 0) {
                st->w178 = 2;
                fn_800A0028(self);
            }
            st->w178 = 0;
            self->pivot = 0;
        }
    }
}
void* fn_8009E8B0(s32 n);

/* EvExt.info of the object fn_800ABEB4 resets. */
typedef struct {
    u32 count;         /* 0x00 */
    u8 pad04[0x24 - 4];
    Src8009DCA8 blend; /* 0x24 */
    u32 mode;          /* 0x44 */
} EvInfoCfg;
static inline EvInfoCfg* CfgInfo(Sub_800A3ED4* e) {
    return e->p1c8->p10;
}

void fn_800ABEB4(Sub_800A3ED4* w) {
    w->x1fb = 0;
    w->x1fa = 1;
    w->point = 0;
    w->x21c = 0;
    if (CfgInfo(w)->mode == 1) {
        w->pivotPos.x = CfgInfo(w)->blend.f08;
        w->pivotPos.y = CfgInfo(w)->blend.f0C;
        w->pivotPos.z = CfgInfo(w)->blend.f10;
        w->pivotAng[0] = CfgInfo(w)->blend.i14;
        w->pivotAng[1] = CfgInfo(w)->blend.i18;
        w->pivotAng[2] = CfgInfo(w)->blend.i1C;
        w->pivot = 1;
    } else {
        w->pivotPos.x = w->pivotPos.y = w->pivotPos.z = 0.0f;
        w->pivotAng[0] = w->pivotAng[1] = w->pivotAng[2] = 0;
        w->pivot = 0;
    }
    w->x1fc = 0;
    w->x236 = 8;
    if (w->x264 == NULL) {
        w->x264 = fn_8009E8B0(w->x236);
    }
    if (w->we4 != NULL && w->x25c == NULL) {
        fn_801C8930(w->we4);
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
static inline EvInfoRing* RingInfo(Sub_800A3ED4* e) {
    return e->p1c8->p10;
}
/* One ring point of fn_800AC728 (EvObj.x25c). */
typedef struct {
    NJS_POINT3 pos;  /* 0x00 */
    u8 pad0c[4];
    s32 x10;         /* 0x10 */
    u8 pad14[4];
} RingPart;
u32 fn_800A10A8(u32 *base, u32 i, s32 n);
void *fn_800A1ABC(void *b, u32 i);
u32 fn_800A1AE8(void* o, u32 idx);
void fn_800A1210(NJS_VECTOR *out, NJS_VECTOR *in, Angle deg, f32 radius);

void fn_800AC728(Sub_800A3ED4 *w, P *p)
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
    p->w5c = w->w100;
    p->w70 = 0;
    p->w68 = 0;
    p->w6c = fn_800A10A8(p->w64, p->w70, p->w60);
    p->f74 = 16.0f;
    p->f78 = 16.0f;
    p->w4 = &w->x24c;
    p->w8 = &w->x20c.x;
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
    s->ang.x = (s32)(182.04445f * src->f50);
    s->ang.y = (s32)(182.04445f * src->f54);
    s->ang.z = (s32)(182.04445f * src->f58);
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
            s->motion = src->p1c->w[0];
            if (src->p1c->n > 1) {
                s->wec = src->p1c->w[1];
            }
        }
    }
    return o;
}

extern void fn_80227810(NJS_TEXLIST *p);
extern void fn_8009E630(Obj_800A3ED4 *t);
extern void fn_801E1784(void *p);
extern void fn_802275A4(NJS_TEXLIST *h, s32 a);
extern void fn_801E5608(Sub_800A3ED4 *w, s32 a, u32 b);
extern f32 njCos(Angle a);
extern f32 njSin(Angle a);
s32 fn_800A10C4(u32 *base, s32 i, s32 n);
void fn_800A1948(NJS_POINT3 *unused, Angle *dst, u8 flags);
NJS_TEXLIST *fn_800A1B50(Sub_800A3ED4 *obj);
void fn_800A10E8(NJS_POINT3 *p, NJS_POINT3 *origin, f32 extra);
extern void fn_800D2924(Sub_800A3ED4* o);
extern void fn_801DBE1C(const char* fmt, ...);
extern f32 fn_8009E3D0(s32 kind, void* model, NJS_POINT3* scl);
extern void njProjectScreen(void* m, NJS_POINT3* p, f32* out);
extern void fn_80296EEC(s32 a, s32 b, s32 c);
extern void fn_800A12D8(NJS_POINT3* p, NJS_POINT3* origin, s32 ang);
extern void fn_8009E804(ItemList* list, s32 idx);
typedef struct {
    Obj_800A3ED4* parent;  /* 0x00 */
    s32 loop;              /* 0x04 */
    NJS_TEXLIST* texlist;  /* 0x08 */
    s32 n;                 /* 0x0C */
    u32* item;            /* 0x10 */
    u32 frame;             /* 0x14 */
    s32 wait;              /* 0x18 */
    s32 index;             /* 0x1C */
    f32 f20;               /* 0x20 */
    f32 f24;               /* 0x24 */
} Emit_800A7860;
inline Sub_800A3ED4* PWORKS(Emit_800A7860* em) {
    return em->parent->sub;
}
typedef struct {
    f32 x, y;        /* 0x00 */
    s16 tex;         /* 0x08 */
    u8 pad0A[2];
    s32 add;         /* 0x0C */
    s32 tint;        /* 0x10 */
    u8 a, r, g, b;   /* 0x14 */
    s16 x18;         /* 0x18 */
    s16 x1a;         /* 0x1A */
    NJS_TEXLIST* texlist; /* 0x1C */
} Sprite_800A432C;
extern void fn_80227810(NJS_TEXLIST *p);
extern void fn_8009E630(Obj_800A3ED4 *t);
extern void fn_801E1784(void *p);
extern void fn_802275A4(NJS_TEXLIST *h, s32 a);
extern void fn_801E5608(Sub_800A3ED4 *w, s32 a, u32 b);
extern f32 njCos(Angle a);
extern f32 njSin(Angle a);
s32 fn_800A10C4(u32 *base, s32 i, s32 n);
void fn_800A1948(NJS_POINT3 *unused, Angle *dst, u8 flags);
NJS_TEXLIST *fn_800A1B50(Sub_800A3ED4 *obj);
void fn_800A10E8(NJS_POINT3 *p, NJS_POINT3 *origin, f32 extra);
extern s32 fn_801E78C8(NJS_MOTION* a, NJS_POINT3* pos, Ang3* ang, NJS_POINT3* scl, f32 frame);
extern void fn_801E7DF0(void* p);
extern void fn_8009D274(void* model, s16 u, s16 v, s32 mode);
extern void fn_802135B4(NJS_POINT3* v, Ang3* out);
extern void fn_800A13D8(f32* m, Angle* out);
extern void fn_800A1690(f32* m, Angle* out);
extern s32 lbl_80347530;
extern void fn_8009D6C0(Sub_800A3ED4* obj, s32 idx, f32 f);
extern void fn_8009D67C(Sub_800A3ED4* o, s32 idx);
extern void fn_800A322C(Sprite_800A432C* s, NJS_POINT3* pos, s32 a, NJS_POINT3* scl, u16 id, s32 c);
extern void fn_80296E4C(s32 a);
extern void njRotateZXY(NJS_MATRIX m, Angle x, Angle y, Angle z);
extern void fn_8009D994(Sub_800A3ED4* o, s32 idx, u32 count);
extern void fn_800D2924(Sub_800A3ED4* o);
extern void fn_801DBE1C(const char* fmt, ...);
extern f32 fn_8009E3D0(s32 kind, void* model, NJS_POINT3* scl);
extern void njProjectScreen(void* m, NJS_POINT3* p, f32* out);
extern void fn_80296EEC(s32 a, s32 b, s32 c);
extern void fn_800A12D8(NJS_POINT3* p, NJS_POINT3* origin, s32 ang);
extern void fn_8009E804(ItemList* list, s32 idx);
/* One point of the ribbon (fn_800A4924's RibPt) as fn_800A432C draws it. */
typedef struct RibPt {
    NJS_POINT3 pos; /* 0x00 */
    Ang3 rot;       /* 0x0C */
    NJS_POINT3 scl; /* 0x18 */
    s32 x24;        /* 0x24 */
    s32 x28;        /* 0x28 */
    u8 alpha;       /* 0x2C */
    u8 pad2d[3];
    f32 frame;      /* 0x30 */
} RibPt;

typedef struct EvInfoRib {
    u8 pad0[0x4C];
    u32 alphaMode;   /* 0x4C */
    u8 pad50[4];
    u32 animated;    /* 0x54 */
    u8 pad58[4];
    u32 noLoopCtl;   /* 0x5C */
} EvInfoRib;

extern void fn_8009E910(DrawState* o, s32 mode, u8* out);
extern void fn_80286EE8(void);
extern void fn_8028B498(void);

static inline void RibDraw(Sub_800A3ED4* obj, u32* item, RibPt* part, s32 n, f32* scr) {
    u32 count;
    s32 saved;
    f32 margin;

    saved = lbl_80347530;
    lbl_80347530 = 1;
    margin = obj->x258;
    njProjectScreen(NULL, &obj->v38, scr);
    if (scr[0] < 640.0f + margin && scr[0] > -margin && scr[1] < 480.0f + margin && scr[1] > -margin) {
        count = obj->w100 != NULL ? obj->w100->nbTexture : 0;
        if (item != NULL) {
            fn_8009D994(obj, fn_800A10C4(item, part->x28, n), count);
        } else {
            fn_8009D994(obj, 0, count);
        }
    }
    lbl_80347530 = saved;
}

void fn_800A432C(Sub_800A3ED4* obj, Sub_800A3ED4* src, RibPt* part) {
    EvInfoRib* info = obj->p1c8->p10;
    s32 n = obj->x218;
    u32* item = fn_800A1ABC(src, 0x31);
    f32 margin;
    f32 scr[2];

    obj->x18c = part->frame;
    if (obj->x222 != 0) {
        if (obj->w100 != NULL) {
            DrawState* fx = obj->x25c;
            u8 alpha = 0;
            Sprite_800A432C spr;
            Sprite_800A432C* sp = &spr;
            sp->x = part->scl.x;
            sp->y = part->scl.y;
            sp->x1a = 0;
            sp->x18 = 0;
            if (item != NULL) {
                sp->tex = fn_800A10C4(item, part->x28, n);
            } else {
                sp->tex = 0;
            }
            sp->a = part->alpha * (1.0f + obj->alpha);
            sp->texlist = obj->w100;
            if (obj->x221 != 0) {
                sp->tint = 1;
                sp->r = obj->x21e;
                sp->g = obj->x21f;
                sp->b = obj->x220;
            } else {
                sp->tint = 0;
            }
            fn_8009E910(fx, info->alphaMode, &alpha);
            sp->a = spr.a * alpha / 255.0f;
            if (info->alphaMode == 3) {
                sp->add = 1;
            } else {
                sp->add = 0;
            }
            margin = obj->x258;
            njProjectScreen(NULL, &part->pos, scr);
            if (scr[0] < 640.0f + margin && scr[0] > -margin && scr[1] < 480.0f + margin && scr[1] > -margin) {
                fn_800A322C(sp, &part->pos, part->rot.z, &obj->v50, 0, 0);
            }
            if (obj->motion != NULL) {
                obj->x18c += obj->f190;
                if (0.0f > obj->f190) {
                    if (0.0f > obj->x18c) {
                        obj->x198 = 1;
                        obj->x18c = obj->motion->nbFrame - 1.0f;
                    }
                } else if (obj->x18c > obj->motion->nbFrame - 1.0f) {
                    obj->x198 = 1;
                    obj->x18c = 0.0f;
                }
            }
        }
    } else {
        NJS_POINT3 pos = obj->v38;
        Ang3 ang = obj->ang;
        njPushMatrixEx();
        fn_80286EE8();
        fn_8028B498();
        njUnitMatrix(NULL);
        if (info->animated != 0) {
            fn_800A1948(&part->pos, &obj->ang.x, 3);
            obj->ang.z = part->rot.z;
            njRotateEx(&obj->ang.x, 1);
        } else {
            njRotateEx(&obj->x20c.x, 0);
            njRotateEx(&part->rot.x, 0);
        }
        fn_800A1690(NULL, &obj->ang.x);
        njPopMatrixEx();
        obj->v38 = part->pos;
        obj->v50 = part->scl;
        obj->alpha = (1.0f / 255.0f) * ((1.0f + obj->alpha) * part->alpha) - 1.0f;
        RibDraw(obj, item, part, n, scr);
        if (info->noLoopCtl == 0 && obj->motion != NULL && obj->x21d != 3) {
            if (obj->x21d == 1) {
                obj->x18c = 0.0f;
            } else if (obj->x21d == 2) {
                obj->x18c = obj->motion->nbFrame - 1.0f;
            }
            if (0.0f < obj->f190) {
                if (obj->x18c >= obj->motion->nbFrame - 1.001f) {
                    obj->f190 = 0.0f;
                    obj->x21d = 3;
                } else if (obj->x18c + obj->f190 > obj->motion->nbFrame - 1.0f) {
                    obj->x21d = 2;
                }
            } else if (obj->x18c < fabs(obj->f190)) {
                if (0.0f != obj->x18c) {
                    obj->x21d = 1;
                } else {
                    obj->f190 = 0.0f;
                    obj->x21d = 3;
                }
            } else if (obj->x18c + obj->f190 < 0.0f) {
                obj->x21d = 1;
            }
        }
        obj->v38 = pos;
        obj->ang = ang;
    }
    part->frame = obj->x18c;
}

static inline s32 SubFlag(Sub_800A3ED4* o) {
    return o->p1d8 != NULL ? o->p1d8->w1a0 : 1;
}

void fn_800A6F30(Sub_800A3ED4* obj, Emit_800A7860* em);
void fn_800A7860(Sub_800A3ED4* obj, Emit_800A7860* em);

typedef struct {
    s32 count;       /* 0x00 */
    u8 pad04[0x0C];
    s32 depth;       /* 0x10 */
    u8 pad14[4];
    u32 flags;       /* 0x18 */
    u8 pad1C[0x24 - 0x1C];
    Src8009DCA8 blend; /* 0x24 */
    s32 mode;        /* 0x44 */
    u32 drawMode;    /* 0x48 */
    u32 alphaMode;   /* 0x4C */
    u32 x50;         /* 0x50 */
    u32 animated;    /* 0x54 */
    u32 noLoopCtl;   /* 0x58 */
    s32 x5c;         /* 0x5C */
    u8 pad60[0x6C - 0x60];
    u32 life;        /* 0x6C */
    u8 pad70[0xC4 - 0x70];
    s32 spinX;       /* 0xC4 */
    s32 spinY;       /* 0xC8 */
    u8 padCC[4];
    f32 xd0;         /* 0xD0 */
} EvInfoSpriteC_800A816C;


static inline EvInfoSpriteC_800A816C* SpriteCInfo(Sub_800A3ED4* e) {
    return e->p1c8->p10;
}

inline s32 EvDepth(Sub_800A3ED4* obj) {
    EvInfoSpriteC_800A816C* ci;
    if ((ci = obj->p1c8->p10)->count > 3) {
        return (ci = obj->p1c8->p10)->depth;
    }
    return 0;
}

inline s32 IsBillboardC(EvInfoSpriteC_800A816C* info, Sub_800A3ED4* obj) {
    s32 r = 0;
    if (info->drawMode == 0 || (info->drawMode == 1 && obj->we4 == NULL)) {
        r = 1;
    }
    return r;
}

typedef struct {
    u8 pad0[0x24];
    u32 drawMode;    /* 0x24 */
    u32 alphaMode;   /* 0x28 */
    u32 x2c;         /* 0x2C */
    u32 animated;    /* 0x30 */
    u8 pad34[0x3C - 0x34];
    u32 fadeInStart; /* 0x3C */
    u32 fadeInLen;   /* 0x40 */
    u32 fadeOutLen;  /* 0x44 */
    u32 life;        /* 0x48 also where the fade out starts */
    u32 moveStart;   /* 0x4C */
    u32 moveEnd;     /* 0x50 */
    u32 grow0Start;  /* 0x54 */
    u32 grow0Len;    /* 0x58 */
    u32 grow1Start;  /* 0x5C */
    u32 grow1Len;    /* 0x60 */
    u32 spinStart;   /* 0x64 */
    u32 spinEnd;     /* 0x68 */
    f32 radius;      /* 0x6C */
    NJS_POINT3 move; /* 0x70 */
    s32 spin[3];     /* 0x7C degrees per frame */
    NJS_POINT3 size; /* 0x88 */
    NJS_POINT3 grow0;/* 0x94 */
    NJS_POINT3 grow1;/* 0xA0 */
    s32 uvX;         /* 0xAC */
    s32 uvY;         /* 0xB0 */
} EvInfoSprite_800A7860;

inline s32 IsBillboard(EvInfoSprite_800A7860* info, Sub_800A3ED4* obj) {
    s32 r = 0;
    if (info->drawMode == 0 || (info->drawMode == 1 && obj->we4 == NULL)) {
        r = 1;
    }
    return r;
}

void fn_800A816C(Obj_800A3ED4* task) {
    Sub_800A3ED4* obj = task->sub;
    Emit_800A7860* em = obj->x260;
    NJS_POINT3 v;
    DrawState ds;
    EvInfoSpriteC_800A816C* ci;
    NJS_MATRIX m;

    if (task->parent->flags & 0x40) {
        task->state = 0xFF;
    }
    if (task->flags & 0x20) {
        task->state = 0xFF;
    }
    switch (task->state) {
    case 0:
        task->prio = 0xFB;
        if (em->texlist != NULL) {
            obj->w100 = em->texlist;
        } else {
            obj->w100 = fn_800A1B50(obj);
            em->texlist = obj->w100;
        }
        if (obj->w100 != NULL) {
            fn_80227810(obj->w100);
        }
        obj->v50.x = PWORKS(em)->v50.x;
        obj->v50.y = PWORKS(em)->v50.y;
        obj->v50.z = PWORKS(em)->v50.z;
        obj->ang.z = 0;
        obj->ang.y = 0;
        obj->ang.x = 0;
        obj->x20a = 0;
        obj->x208 = 0;
        obj->x18 |= 0x1000;
        fn_8009D6C0(obj, 0, (ci = PWORKS(em)->p1c8->p10)->xd0);
        fn_8009D67C(obj, 1);
        obj->id &= 0xFF00;
        if ((ci = PWORKS(em)->p1c8->p10)->x50 == 0) {
            obj->id |= 3;
        }
        if ((ci = PWORKS(em)->p1c8->p10)->alphaMode != 0) {
            obj->w30 = 8;
            obj->w34 = 10;
        }
        {
            s32 d = EvDepth(obj);
            if (d >= 0) {
                task->f20 = -10000.0f + d;
            }
        }
        task->state = 1;
    case 1:
        if (em->parent->state == 1) {
            task->state = 2;
        }
        fn_800A6F30(obj, em);
        if (EvDepth(obj) == 0) {
            njCalcPoint(NULL, &obj->v38, &v);
            task->f20 = -200.0f + v.z;
        }
        {
            Sub_800A3ED4* pw;
            if (SubFlag(PWORKS(em)) == 0) {
                EvInfoSpriteC_800A816C* info = PWORKS(em)->p1c8->p10;
                if (IsBillboardC(info, obj)) {
                    if (obj->w100 != NULL) {
                        Sprite_800A432C* bb;
                        obj->x208 += (s16)info->spinX;
                        obj->x20a += (s16)(ci = PWORKS(em)->p1c8->p10)->spinY;
                        if (obj->x208 < -0xFF) {
                            obj->x208 += 0x1FE;
                        }
                        if (obj->x208 > 0xFF) {
                            obj->x208 -= 0x1FE;
                        }
                        if (obj->x20a < -0xFF) {
                            obj->x20a += 0x1FE;
                        }
                        if (obj->x20a > 0xFF) {
                            obj->x20a -= 0x1FE;
                        }
                        bb = fn_801E1A2C(1, 0x20);
                        bb->x = obj->v50.x;
                        bb->y = obj->v50.y;
                        if (0.0f != obj->vel.x) {
                            bb->x *= obj->vel.x;
                        }
                        if (0.0f != obj->vel.y) {
                            bb->y *= obj->vel.y;
                        }
                        bb->x18 = obj->x208;
                        bb->x1a = obj->x20a;
                        if (em->item != NULL) {
                            bb->tex = fn_800A10C4(em->item, em->index, em->n);
                        } else {
                            bb->tex = 0;
                        }
                        bb->a = 255.0f * (1.0f + obj->alpha);
                        bb->add = 0;
                        bb->tint = 0;
                        bb->texlist = obj->w100;
                        DrawStateDefault2D(&ds);
                        if ((ci = PWORKS(em)->p1c8->p10)->alphaMode != 0) {
                            ds.blend_src = 8;
                            ds.blend_dst = 10;
                        }
                        ds.fog = obj->w2c;
                        DrawStatePush(&ds);
                        fn_80296E4C(0);
                        if ((ci = obj->p1c8->p10)->flags & 0x80000) {
                            fn_800A322C(bb, &obj->v38, obj->ang.z, &obj->v50, obj->id, 1);
                        } else {
                            fn_800A322C(bb, &obj->v38, obj->ang.z, &obj->v50, obj->id, 0);
                        }
                        if (obj->motion != NULL) {
                            obj->x18c += obj->f190;
                            if (0.0f > obj->f190) {
                                if (0.0f > obj->x18c) {
                                    obj->x198 = 1;
                                    obj->x18c = (f32)obj->motion->nbFrame - 1.0f;
                                }
                            } else if (obj->x18c > (f32)obj->motion->nbFrame - 1.0f) {
                                obj->x198 = 1;
                                obj->x18c = 0.0f;
                            }
                        }
                        DrawStatePop(NULL);
                        if (bb != NULL) {
                            fn_801E1784(bb);
                        }
                    }
                } else {
                    Angle ax, ay, az;
                    s32 saved;
                    u32 count;
                    if (info->animated == 1) {
                        njUnitMatrix(m);
                        fn_800A1948(&obj->v38, &obj->ang.x, 3);
                    }
                    if (obj->w100 != NULL) {
                        fn_80299040(obj->w100);
                        if (em->item != NULL) {
                            fn_80298FE4(fn_800A10C4(em->item, em->index, em->n));
                        } else {
                            fn_80298FE4(0);
                        }
                    }
                    ax = obj->ang.x;
                    ay = obj->ang.y;
                    az = obj->ang.z;
                    njUnitMatrix(m);
                    pw = PWORKS(em);
                    if ((ci = pw->p1c8->p10)->animated == 0) {
                        njRotateXYZ(m, pw->x20c.x, pw->x20c.y, pw->x20c.z);
                    }
                    njRotateZXY(m, obj->ang.x, obj->ang.y, obj->ang.z);
                    fn_800A13D8(m, &obj->ang.x);
                    saved = lbl_80347530;
                    lbl_80347530 = 1;
                    if (obj->w100 != NULL) {
                        count = obj->w100->nbTexture;
                    } else {
                        count = 0;
                    }
                    if (em->item != NULL) {
                        fn_8009D994(obj, fn_800A10C4(em->item, em->index, em->n), count);
                    } else {
                        fn_8009D994(obj, 0, count);
                    }
                    lbl_80347530 = saved;
                    obj->ang.x = ax;
                    obj->ang.y = ay;
                    obj->ang.z = az;
                }
            }
        }
        if (em->frame > (ci = PWORKS(em)->p1c8->p10)->life && -1.0f == obj->alpha) {
            task->state = 2;
        } else {
            em->frame++;
        }
        if ((ci = PWORKS(em)->p1c8->p10)->noLoopCtl == 0 && obj->motion != NULL && obj->x21d != 3) {
            if (obj->x21d == 1) {
                obj->x18c = 0.0f;
            } else if (obj->x21d == 2) {
                obj->x18c = (f32)obj->motion->nbFrame - 1.0f;
            }
            if (0.0f < obj->f190) {
                if (obj->x18c >= (f32)obj->motion->nbFrame - 1.001f) {
                    obj->f190 = 0.0f;
                    obj->x21d = 3;
                } else if (obj->x18c + obj->f190 > (f32)obj->motion->nbFrame - 1.0f) {
                    obj->x21d = 2;
                }
            } else if (obj->x18c < fabs(obj->f190)) {
                if (0.0f != obj->x18c) {
                    obj->x21d = 1;
                } else {
                    obj->f190 = 0.0f;
                    obj->x21d = 3;
                }
            } else if (obj->x18c + obj->f190 < 0.0f) {
                obj->x21d = 1;
            }
        }
        {
            Sub_800A3ED4* w = fn_8015F180(PWORKS(em));
            w->x18c = obj->x18c;
            w->f190 = obj->f190;
            w->x19c = obj->x19c;
            w->x198 = obj->x198;
        }
        break;
    case 2:
        PWORKS(em)->point--;
        if (PWORKS(em)->point == 0xFFFF) {
            PWORKS(em)->point = 0;
        }
        fn_8009E804(PWORKS(em)->x264, obj->x238);
    case 0xFF:
        if (obj->w100 != NULL && obj->w100->textures->texaddr != 0) {
            fn_802275A4(obj->w100, 0);
        }
        if (em != NULL) {
            fn_801E1784(em);
        }
        obj->x264 = NULL;
        obj->x260 = NULL;
        obj->x25c = NULL;
        fn_8009E630(task);
        break;
    case 0xfe:
        break;
    }
}

typedef struct {
    u8 pad0[0x44];
    s32 follow; /* <= -1 follows the parent every frame */
} EvInfoSmoke_800A8FE0;

inline void DrawSpriteModel(Sub_800A3ED4* obj, Emit_800A7860* em, NJS_MATRIX m) {
    Angle az, ay, ax;
    EvInfoSprite_800A7860* ci;
    Sub_800A3ED4* pw;
    ax = obj->ang.x;
    ay = obj->ang.y;
    az = obj->ang.z;
    njUnitMatrix(m);
    pw = PWORKS(em);
    if ((ci = pw->p1c8->p10)->animated == 0) {
        njRotateXYZ(m, pw->x20c.x, pw->x20c.y, pw->x20c.z);
    }
    njRotateXYZ(m, obj->ang.x, obj->ang.y, obj->ang.z);
    fn_800A1690(m, &obj->ang.x);
    if (SubFlag(PWORKS(em)) == 0) {
        if (em->item != NULL) {
            fn_801E5608(obj, fn_800A10C4(em->item, em->index, em->n), obj->w100->nbTexture);
        } else {
            fn_801E5608(obj, 0, obj->w100->nbTexture);
        }
    }
    obj->ang.x = ax;
    obj->ang.y = ay;
    obj->ang.z = az;
}

void fn_800A8A80(Obj_800A3ED4* task) {
    Sub_800A3ED4* obj = task->sub;
    Emit_800A7860* em = obj->x260;
    DrawState ds;
    EvInfoSprite_800A7860* ci;
    NJS_MATRIX m;

    if (task->parent->flags & 0x40) {
        task->state = 0xFF;
    }
    if (task->flags & 0x20) {
        task->state = 0xFF;
    }
    switch (task->state) {
    case 0:
        task->prio = 0xFB;
        if (em->texlist != NULL) {
            if (em->texlist != NULL) {
                obj->w100 = em->texlist;
            } else {
                obj->w100 = fn_800A1B50(obj);
                em->texlist = obj->w100;
            }
            if (obj->w100 != NULL) {
                fn_80227810(obj->w100);
            }
        }
        obj->v50.x = (ci = PWORKS(em)->p1c8->p10)->size.x;
        obj->v50.y = (ci = PWORKS(em)->p1c8->p10)->size.y;
        obj->v50.z = (ci = PWORKS(em)->p1c8->p10)->size.z;
        obj->ang.z = 0;
        obj->ang.y = 0;
        obj->ang.x = 0;
        if ((ci = PWORKS(em)->p1c8->p10)->x2c == 1) {
            obj->id = 0;
        } else {
            obj->id = 1;
        }
        if ((ci = PWORKS(em)->p1c8->p10)->alphaMode == 1) {
            obj->w30 = 8;
            obj->w34 = 10;
        }
        task->state = 1;
    case 1:
        fn_800A7860(obj, em);
        {
            Sub_800A3ED4* pw;
            EvInfoSprite_800A7860* info = PWORKS(em)->p1c8->p10;
            if (IsBillboard(info, obj)) {
                if (obj->w100 != NULL) {
                    if (SubFlag(PWORKS(em)) == 0) {
                        Sprite_800A432C* bb;
                        u16 sx = (ci = PWORKS(em)->p1c8->p10)->uvX;
                        u16 sy = (ci = PWORKS(em)->p1c8->p10)->uvY;
                        u16 ux = sx * em->frame;
                        u16 uy = sy * em->frame;
                        bb = fn_801E1A2C(1, 0x20);
                        bb->x = em->f20 * obj->v50.x;
                        bb->y = em->f24 * obj->v50.y;
                        bb->x18 = ux;
                        bb->x1a = uy;
                        if (em->item != NULL) {
                            bb->tex = fn_800A10C4(em->item, em->index, em->n);
                        } else {
                            bb->tex = 0;
                        }
                        bb->a = 255.0f * (1.0f + obj->alpha);
                        bb->add = 0;
                        bb->tint = 0;
                        bb->texlist = obj->w100;
                        DrawStateDefault2D(&ds);
                        if ((ci = PWORKS(em)->p1c8->p10)->alphaMode == 1) {
                            ds.blend_src = 8;
                            ds.blend_dst = 10;
                        }
                        ds.fog = obj->w2c;
                        DrawStatePush(&ds);
                        fn_800A322C(bb, &obj->v38, obj->ang.z, &obj->v50, 0, 0);
                        DrawStatePop(NULL);
                        if (bb != NULL) {
                            fn_801E1784(bb);
                        }
                    }
                }
            } else {
                Angle saved;
                if (info->animated == 1) {
                    njUnitMatrix(m);
                    saved = obj->ang.z;
                    fn_800A1948(&obj->v38, &obj->ang.x, 3);
                    obj->ang.z = saved;
                    njRotateZXY(m, obj->ang.x, obj->ang.y, obj->ang.z);
                    fn_800A1690(m, &obj->ang.x);
                }
                if (obj->w100 != NULL) {
                    fn_80299040(obj->w100);
                    if (em->item != NULL) {
                        fn_80298FE4(fn_800A10C4(em->item, em->index, em->n));
                    } else {
                        fn_80298FE4(0);
                    }
                }
                DrawSpriteModel(obj, em, m);
            }
        }
        if (em->frame > (ci = PWORKS(em)->p1c8->p10)->life && -1.0f == obj->alpha) {
            task->state = 2;
        } else {
            em->frame++;
        }
        break;
    case 2:
        PWORKS(em)->point--;
        if (PWORKS(em)->point == 0xFFFF) {
            PWORKS(em)->point = 0;
        }
    case 0xFF:
        if (obj->w100 != NULL && obj->w100->textures->texaddr != 0) {
            fn_802275A4(obj->w100, 0);
        }
        if (em != NULL) {
            fn_801E1784(em);
        }
        obj->x264 = NULL;
        obj->x260 = NULL;
        obj->x25c = NULL;
        fn_8009E630(task);
        break;
    case 0xFE:
        break;
    }
}

void fn_800A8FE0(Obj_800A3ED4* task) {
    Sub_800A3ED4* obj = task->sub;
    Sub_800A3ED4* pw;
    P* em = obj->x260;
    f32 scr[2];
    NJS_POINT3 v;
    NJS_MATRIX m;
    f32 margin;
    EvInfoSmoke_800A8FE0* si;

    if (task->parent->flags & 0x40) {
        task->state = 0xFF;
    } else {
        pw = task->parent->sub;
        fn_800D2924(pw);
    }
    if (task->flags & 0x20) {
        task->state = 0xFF;
    }
    switch (task->state) {
    case 0:
        task->prio = 0xFB;
        obj->x24c.x = pw->x24c.x;
        obj->x24c.y = pw->x24c.y;
        obj->x24c.z = pw->x24c.z;
        obj->x20c.x = pw->x20c.x;
        obj->x20c.y = pw->x20c.y;
        obj->x20c.z = pw->x20c.z;
        em->off.x = obj->v38.x - obj->x24c.x;
        em->off.y = obj->v38.y - obj->x24c.y;
        em->off.z = obj->v38.z - obj->x24c.z;
        (*em->w0)++;
        if (em->w5c != NULL) {
            obj->w100 = em->w5c;
        }
        if (em->w48 > 0) {
            obj->alpha = -1.0f;
        } else {
            obj->alpha = 0.0f;
        }
        obj->v50.x = pw->v50.x;
        obj->v50.y = pw->v50.y;
        obj->v50.z = pw->v50.z;
        obj->x18 |= 0x1000;
        obj->id = 3;
        obj->h16e = 1;
        task->state = 1;
    case 1:
        if ((si = pw->p1c8->p10)->follow <= -1) {
            obj->x24c.x = pw->x24c.x;
            obj->x24c.y = pw->x24c.y;
            obj->x24c.z = pw->x24c.z;
            obj->x20c.x = pw->x20c.x;
            obj->x20c.y = pw->x20c.y;
            obj->x20c.z = pw->x20c.z;
        }
        if (obj->w100 != NULL) {
            fn_80299040(obj->w100);
            if (em->w64 != NULL) {
                u32 idx = fn_800A10C4(em->w64, em->w70, em->w60);
                if (idx < obj->w100->nbTexture) {
                    fn_80298FE4(idx);
                } else {
                    fn_801DBE1C("eff_smoke2: Texture No.%d not found.", idx);
                }
            } else {
                fn_80298FE4(0);
            }
        }
        if (em->w68 < em->w48) {
            obj->alpha = 1.0f / (f32)em->w48 * (f32)em->w68 + -1.0f;
        } else if (em->w68 == em->w48) {
            obj->alpha = 0.0f;
        } else if (em->w68 > em->w4c - em->w50) {
            obj->alpha = 1.0f / (f32)em->w50 * (f32)(em->w4c - em->w68) + -1.0f;
        } else if (em->w68 == em->w4c) {
            obj->alpha = -1.0f;
        }
        if (SubFlag(pw) == 0) {
            if (obj->hidden == 0) {
                njUnitMatrix(m);
                njRotateXYZ(m, obj->x20c.x, obj->x20c.y, obj->x20c.z);
                njCalcPoint(m, &em->off, &obj->v38);
                obj->v38.x += obj->x24c.x;
                obj->v38.y += obj->x24c.y;
                obj->v38.z += obj->x24c.z;
            }
            margin = fn_8009E3D0(7, fn_801C8930(obj->we4), &obj->v50);
            njProjectScreen(NULL, &obj->v38, scr);
            njCalcPoint(NULL, &obj->v38, &v);
            task->f20 = -200.0f + v.z;
            if (scr[0] < 640.0f + margin && scr[0] > -margin && scr[1] < 480.0f + margin && scr[1] > -margin) {
                fn_80296EEC(1, 3, 0);
                if (em->w64 != NULL) {
                    fn_801E5608(obj, fn_800A10C4(em->w64, em->w70, em->w60), obj->w100->nbTexture);
                } else {
                    fn_801E5608(obj, 0, obj->w100->nbTexture);
                }
                fn_80296EEC(1, 3, 1);
            }
        }
        {
            NJS_POINT3 org = { 0.0f, 0.0f, 0.0f };
            em->off.y = em->f24 * njCos(182.04445f * em->w44) + em->off.y;
            fn_800A10E8(&em->off, &org, em->f24 * njSin(182.04445f * em->w44));
            em->f24 += em->f2c;
            fn_800A12D8(&em->off, &org, em->w3c);
            em->w3c += em->w40;
        }
        obj->v50.x += pw->v50.x * em->f54 - pw->v50.x;
        obj->v50.y += pw->v50.y * em->f54 - pw->v50.y;
        obj->v50.z += pw->v50.z * em->f54 - pw->v50.z;
        if (obj->v50.x < 0.0f) {
            obj->v50.x = 0.0f;
        }
        if (obj->v50.y < 0.0f) {
            obj->v50.y = 0.0f;
        }
        if (obj->v50.z < 0.0f) {
            obj->v50.z = 0.0f;
        }
        if (em->w6c == 0 && em->w70 < em->w60) {
            em->w70++;
            if (em->w70 == em->w60 && em->w58 == 1) {
                em->w70 = 0;
            }
            if (em->w70 < em->w60) {
                em->w6c = fn_800A10A8(em->w64, em->w70, em->w60) - 1;
            }
        } else if (em->w70 != em->w60) {
            em->w6c--;
        }
        if (em->w70 == em->w60 && em->w70 > 0) {
            em->w70 = em->w60 - 1;
        }
        if (em->w68 == em->w4c) {
            task->state = 2;
        } else {
            em->w68++;
        }
        break;
    case 2:
        (*em->w0)--;
        if (*em->w0 == 0xFFFF) {
            *em->w0 = 0;
        }
        fn_8009E804(pw->x264, obj->x238);
    case 0xFF:
        if (em != NULL) {
            fn_801E1784(em);
        }
        obj->x264 = NULL;
        obj->x260 = NULL;
        obj->x25c = NULL;
        fn_8009E630(task);
        break;
    case 0xfe:
        break;
    }
}


void fn_800A9708(Obj_800A3ED4 *t)
{
    Sub_800A3ED4 *w = t->sub;
    Sub_800A3ED4 *pw;
    P *fx = w->x260;
    NJS_MATRIX m;
    NJS_POINT3 c;

    if (t->parent->flags & 0x40) {
        t->state = 0xff;
    } else {
        pw = t->parent->sub;
    }
    if (t->flags & 0x20) {
        t->state = 0xff;
    }
    switch (t->state) {
    case 0:
        t->prio = 0xfb;
        fx->off.x = w->v38.x - fx->w4->x;
        fx->off.y = w->v38.y - fx->w4->y;
        fx->off.z = w->v38.z - fx->w4->z;
        (*fx->w0)++;
        if (fx->w5c != NULL) {
            w->w100 = fx->w5c;
        } else {
            w->w100 = fn_800A1B50(w);
            fx->w5c = w->w100;
        }
        if (w->w100 != NULL) {
            fn_80227810(w->w100);
        }
        if (fx->w48 > 0) {
            w->alpha = -1.0f;
        } else {
            w->alpha = 0.0f;
        }
        w->v50.x = pw->v50.x;
        w->v50.y = pw->v50.y;
        w->v50.z = pw->v50.z;
        w->id &= 0xff00;
        w->id |= 1;
        t->state = 1;
    case 1:
        if (w->w100 != NULL) {
            fn_80299040(w->w100);
            if (fx->w64 != NULL) {
                fn_80298FE4(fn_800A10C4(fx->w64, fx->w70, fx->w60));
            } else {
                fn_80298FE4(0);
            }
        }
        if (fx->w68 < fx->w48) {
            w->alpha = 1.0f / fx->w48 * fx->w68 + -1.0f;
        } else if (fx->w68 == fx->w48) {
            w->alpha = 0.0f;
        } else if (fx->w68 > fx->w4c - fx->w50) {
            w->alpha = 1.0f / fx->w50 * (fx->w4c - fx->w68) + -1.0f;
        } else if (fx->w68 == fx->w4c) {
            w->alpha = -1.0f;
        }
        if ((pw->p1d8 != NULL ? pw->p1d8->w1a0 : 1) == 0) {
            njUnitMatrix(m);
            njRotateXYZ(m, fx->w8[0], fx->w8[1], fx->w8[2]);
            njCalcPoint(m, &fx->off, &w->v38);
            w->v38.x += fx->w4->x;
            w->v38.y += fx->w4->y;
            w->v38.z += fx->w4->z;
            fn_800A1948(&w->v38, &w->ang.x, 3);
            if (fx->w64 != NULL) {
                fn_801E5608(w, fn_800A10C4(fx->w64, fx->w70, fx->w60), w->w100->nbTexture);
            } else {
                fn_801E5608(w, 0, w->w100->nbTexture);
            }
        }
        {
            NJS_POINT3 c2 = { 0.0f, 0.0f, 0.0f };
            c = c2;
        }
        fx->off.y = fx->f24 * njCos((Angle)(182.04445f * fx->w44)) + fx->off.y;
        fn_800A10E8(&fx->off, &c, fx->f24 * njSin((Angle)(182.04445f * fx->w44)));
        fx->f24 = fx->f24 + fx->f2c;
        fx->w34 = fx->w34 + fx->w38;
        w->v50.x = w->v50.x + (pw->v50.x * fx->f54 - pw->v50.x);
        w->v50.y = w->v50.y + (pw->v50.y * fx->f54 - pw->v50.y);
        w->v50.z = w->v50.z + (pw->v50.z * fx->f54 - pw->v50.z);
        if (w->v50.x < 0.0f) {
            w->v50.x = 0.0f;
        }
        if (w->v50.y < 0.0f) {
            w->v50.y = 0.0f;
        }
        if (w->v50.z < 0.0f) {
            w->v50.z = 0.0f;
        }
        if (fx->w6c == 0 && fx->w70 < fx->w60) {
            fx->w70++;
            if (fx->w70 == fx->w60 && fx->w58 == 1) {
                fx->w70 = 0;
            }
            if (fx->w70 < fx->w60) {
                fx->w6c = fn_800A10A8(fx->w64, fx->w70, fx->w60) - 1;
            }
        } else if (fx->w70 != fx->w60) {
            fx->w6c--;
        }
        if (fx->w70 == fx->w60 && fx->w70 > 0) {
            fx->w70 = fx->w60 - 1;
        }
        if (fx->w68 == fx->w4c) {
            t->state = 2;
        } else {
            fx->w68++;
        }
        break;
    case 2:
        (*fx->w0)--;
        if (*fx->w0 == 0xffff) {
            *fx->w0 = 0;
        }
    case 0xff:
        if (w->w100 != NULL && w->w100->textures->texaddr != NULL) {
            fn_802275A4(w->w100, 0);
        }
        if (fx != NULL) {
            fn_801E1784(fx);
        }
        w->x264 = NULL;
        w->x260 = NULL;
        w->x25c = NULL;

        fn_8009E630(t);
        break;
    case 0xfe:
        break;
    }
}

/*@@NEW@@*/

/* EvExt.info of the ring-spawner kind (fn_800AD6D8, fn_800ADA60). */
typedef struct {
    u32 count;              /* 0x00 */
    u8 pad04[0x18 - 0x04];
    u32 flags;              /* 0x18 */
    u8 pad1c[0x24 - 0x1c];
    f32 x24;                /* 0x24 radius */
    s32 x28;                /* 0x28 count */
    s32 x2c;                /* 0x2C mode */
    f32 x30;                /* 0x30 */
    f32 x34, x38, x3c, x40; /* 0x34 */
    s32 x44, x48, x4c, x50; /* 0x44 */
    s32 x54, x58, x5c, x60; /* 0x54 */
    f32 x64;                /* 0x64 */
    s32 x68;                /* 0x68 */
    u32 x6c;                /* 0x6C */
} EvInfoSpawn;
static inline EvInfoSpawn* SpawnInfo(Sub_800A3ED4* e) {
    return e->p1c8->p10;
}
extern void fn_800AD330(Sub_800A3ED4* o);
Obj_800A3ED4* fn_8009D760(Obj_800A3ED4* parent, void* cb, u16 a, Src_800A3ED4* obj);

void fn_800AD6D8(Sub_800A3ED4* w, P* p);

void fn_800ADA60(Obj_800A3ED4* self) {
    Angle ax;
    RingPart* sp;
    Angle ay;
    P* rec;
    s32 i;
    Angle az;
    Obj_800A3ED4* child;
    f32 x;
    f32 y;
    f32 z;
    RingPart* s;
    Sub_800A3ED4* e;
    P* p;
    s32 j;

    e = self->sub;
    e->x172 = 0;
    e->motionId = 0;
    if (self->flags & 0x20) {
        self->state = 0xff;
    }
    if (lbl_80311AD4[6] == 0xf) {
        self->state = 0xff;
    }
    switch (self->state) {
    case 0:
        self->prio = 0xfa;
        e->x26c = 1;
        if (SpawnInfo(e)->count < 0x1c) {
            self->state = 4;
            break;
        }
        rec = fn_801E1A2C(1, 0x7c);
        fn_800AD6D8(e, rec);
        e->x260 = rec;
        fn_8015ED90(self);
        fn_8015EB8C(e, 0, fn_800AD330);
        fn_8015EB8C(e, 0xd, fn_800AD300);
        if (e->p1d8 != 0) {
            e->p1d8->w1a0 = 0;
        }
        self->state = 1;
    case 1:
        if (fn_8015E600(e) == 0) {
            e->x1fb = 0;
        }
        break;
    case 2:
        sp = e->x25c;
        p = e->x260;
        if (e->x1fc > 0) {
            e->x1fc--;
        } else if (e->x1fc == 0) {
            if (e->point != 0) {
                break;
            }
            for (i = 0; i < e->x22c; sp++, i++) {
                if (i == 0) {
                    sp->x10 = 0;
                } else {
                    sp->x10 = (f32)e->x230 * (3.0517578125e-05f * (f32)rand());
                }
            }
            e->x1fc = SpawnInfo(e)->x6c != 0 ? SpawnInfo(e)->x6c : -1;
            e->x1fb = 1;
            e->x1fa = 1;
            self->state = 1;
            break;
        }
        if (fn_8015E600(e) != 0) {
            break;
        }
        for (s = sp, j = 0; j < e->x22c; s++, j++) {
            if (s->x10 == 0) {
                x = e->v38.x;
                y = e->v38.y;
                z = e->v38.z;
                ax = e->ang.x;
                ay = e->ang.y;
                az = e->ang.z;
                child = fn_8009D760(self, fn_800A9708, e->h178, e->p1c8);
                child->sub->x260 = fn_801E1A2C(1, 0x7c);
                fn_800AD588(p, child->sub->x260);
                child->sub->v38.x = e->v38.x + s->pos.x;
                child->sub->v38.y = e->v38.y + s->pos.y;
                child->sub->v38.z = e->v38.z + s->pos.z;
                p->w4 = &e->x24c;
                p->w8 = &e->x20c.x;
                fn_800A10E8(&child->sub->v38, p->w4, e->x258 * (3.0517578125e-05f * (f32)rand()));
                child->sub->x25c = self;
                if (SpawnInfo(e)->flags & 0x80000) {
                    child->sub->id = SpawnInfo(child->sub)->flags;
                }
                s->x10 = e->x22e;
                e->v38.x = x;
                e->v38.y = y;
                e->v38.z = z;
                e->ang.x = ax;
                e->ang.y = ay;
                e->ang.z = az;
            } else {
                s->x10--;
            }
        }
        break;
    case 3:
    case 0xff: {
        void* a;
        void* b;
        fn_8015EBF4(e);
        a = e->x25c;
        b = e->x260;
        if (a != 0) {
            fn_801E1784(a);
        }
        if (b != 0) {
            fn_801E1784(b);
        }
        e->x264 = 0;
        e->x260 = 0;
        e->x25c = 0;
        fn_80100B74(self);
        break;
    }
    case 4:
        if (SpawnInfo(e)->count >= 0x1c) {
            self->state = 0;
        }
        break;
    case 0xfe:
        break;
    }
    fn_8009E578(self->x0c);
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

extern void fn_800A619C(Obj_800A3ED4* t);
Obj_800A3ED4 *fn_8009E530(ItemList *list, s32 count);
s32 fn_8009E840(ItemList* pool, Obj_800A3ED4* item, s32 n);

/* EvExt.info of the particle effect (fn_800AB834). */
typedef struct {
    u8 pad00[0x48];
    s32 count;           /* 0x48 */
    u8 pad4C[0x58 - 0x4C];
    s32 f58;             /* 0x58 */
} EvInfoPart;
static inline EvInfoPart* PartInfo(Sub_800A3ED4* e) {
    return e->p1c8->p10;
}

void fn_800AB834(Obj_800A3ED4* t) {
    Obj_800A3ED4* n;
    Sub_800A3ED4* w = t->sub;
    s32 count;

    n = fn_8009E530(w->x264, w->x236);
    if (n != NULL) {
        n->state = 6;
    } else {
        count = PartInfo(w)->count;
        if (count <= 0) {
            count = 1;
        }
        n = fn_8009D760(t, fn_800A619C, w->h178, w->p1c8);
        n->sub->x260 = fn_801E1A2C(1, count << 7);
        n->sub->x238 = fn_8009E840(w->x264, n, w->x236);
        n->sub->x206 = count;
    }
    n->sub->x234 = w->x234;
    n->sub->x204 = PartInfo(w)->f58;
    if (n->sub->x204 < 0) {
        n->sub->x204 = 0;
    }
}

extern void fn_800A8A80(Obj_800A3ED4* t);
extern const NJS_POINT3 lbl_802B0FDC;
extern void fn_8015F7A8(NJS_MATRIX m, void* out);

/* EvExt.info of the ring-spawner effect (fn_800AB280). */
typedef struct {
    u32 count;          /* 0x00 */
    u8 pad04[0x24 - 0x04];
    Src8009DCA8 blend;  /* 0x24 */
    s32 mode;           /* 0x44 */
    u8 pad48[0x64 - 0x48];
    s32 x64;            /* 0x64 */
    u8 pad68[0x74 - 0x68];
    s32 x74;            /* 0x74 */
    s32 x78;            /* 0x78 */
    u32 x7c;            /* 0x7C */
    u32 x80;            /* 0x80 */
    u8 pad84[0xc0 - 0x84];
    s32 xc0;            /* 0xC0 */
    u32 xc4;            /* 0xC4 */
} Info_800AB280;

static inline Info_800AB280* Info280(Sub_800A3ED4* e) {
    return e->p1c8->p10;
}

static inline s32 EventActive(void) {
    s32 f = 0;
    s32 t = lbl_80311AC0.map;
    if (t >= 500 && t < 600) f = 1;
    f = f != 0;
    return f;
}

static inline s32 CalcCount(Sub_800A3ED4* w)
{
    Info_800AB280* info = Info280(w);
    s32 d = info->xc0;
    if (d <= 0) {
        d = 1;
    }
    return (s32)(f32)ceil((f32)(info->x7c + info->x80 + w->x234) / (f32)d) * 2;
}

#define RESET(w, cnt)                                                          \
    w->x1fb = 0;                                                               \
    w->x1fa = 1;                                                               \
    w->point = 0;                                                              \
    w->x22e = 0;                                                               \
    w->x234 = Info280(w)->x74 + 1;                                             \
    w->x1fc = 0;                                                               \
    cnt = CalcCount(w);                                                        \
    w->x264 = fn_8009E8B0(cnt);                                                \
    w->x236 = cnt;

static inline s32 Reached(s16 n, s16 max)
{
    return n >= max;
}

static inline void Spawn(Obj_800A3ED4* t)
{
    Obj_800A3ED4* nt;
    Sub_800A3ED4* w2 = t->sub;
    s32 n = Info280(w2)->x64;
    if (n <= 0) {
        n = 1;
    }
    nt = fn_8009D760(t, fn_800A4924, w2->h178, w2->p1c8);
    nt->sub->x260 = fn_801E1A2C(1, n * 0x4c);
    nt->sub->x238 = fn_8009E840(w2->x264, nt, w2->x236);
    nt->sub->x206 = n;
    nt->sub->x234 = w2->x234;
    nt->sub->x204 = Info280(w2)->x7c;
    if (nt->sub->x204 < 0) {
        nt->sub->x204 = 0;
    }
}

void fn_800AB280(Obj_800A3ED4* t)
{
    Sub_800A3ED4* w = t->sub;
    Info_800AB280* info;
    State_800ADED0* sub;
    s32 k;
    s32 n;

    w->motionId = w->x172 = 0;
    if (t->flags & 0x20) {
        t->state = 0xff;
    }
    switch (t->state) {
    case 0:
        t->prio = 0xfa;
        w->x26c = 1;
        if (Info280(w)->count < 50) {
            t->state = 4;
            break;
        }
        RESET(w, n);
        fn_8015ED90(t);
        sub = w->p1d8;
        if (sub != NULL) {
            sub->w1a0 = 0;
            sub->x260 = fn_800ABEB0;
            sub->x31c = fn_800ABE9C;
        }
        info = Info280(w);
        if ((s32)fabsf((f32)info->mode) == 1) {
            fn_8009DCA8(w, &info->blend);
        }
        w->w100 = fn_800A1B50(w);
        if (w->w100 != NULL) {
            fn_80227810(w->w100);
        }
        t->state = 1;
    case 1:
        if (!EventActive()) {
            fn_8015E600(w);
        }
        break;
    case 2: {
        State_800ADED0* s2 = w->p1d8;
        if (w->x1fa) {
            info = Info280(w);
            k = (s32)fabsf((f32)info->mode);
            if (k == 1) {
                fn_8009DCA8(w, &info->blend);
            } else if (k == 0) {
                if (s2->w178 == 1 || s2->w178 == 3) {
                    if (!w->x1fa) {
                        s2->w178 = 2;
                        fn_800A0028(w);
                    }
                    s2->w178 = 0;
                    w->pivot = 0;
                }
            }
            fn_8009E71C(w->x264, w->x236);
            w->x264 = NULL;
            RESET(w, n);
            w->x1fa = 0;
            w->x230 = Info280(w)->xc0;
        }
        fn_8015E600(w);
        fn_800A0E1C(w);
        if (w->x1fb) {
            if (w->point == 0) {
                w->x1fc = 0;
                w->x22e = w->x230;
                w->x1fa = 1;
                t->state = 1;
            }
            break;
        }
        if (w->x22e != 0) {
            w->x22e--;
            break;
        }
        Spawn(t);
        w->x1fc++;
        if ((Reached(w->x1fc, Info280(w)->xc4) && Info280(w)->xc4 != 0) ||
            (w->x230 == 0 && w->x1fc == 1)) {
            w->x1fb = 1;
        } else {
            w->x22e = w->x230;
        }
        break;
    }
    case 3:
    case 0xff:
        fn_8015EBF4(w);
        fn_8009E71C(w->x264, w->x236);
        if (w->w100 != NULL && w->w100->textures->texaddr != NULL) {
            fn_802275A4(w->w100, 0);
        }
        w->x264 = NULL;
        w->x260 = NULL;
        w->x25c = NULL;
        fn_80100B74(t);
        break;
    case 4:
        if (Info280(w)->count >= 50) {
            t->state = 0;
        }
        break;
    case 5:
        break;
    }
    fn_8009E578(t->x0c);
}

/* EvExt.info of the ring effect (fn_800AB934). */
typedef struct {
    u32 count;      /* 0x00 */
    u8 pad04[0x20];
    Src8009DCA8 blend; /* 0x24 */
    s32 mode;       /* 0x44 */
    u8 pad48[0x54 - 0x48];
    s32 x54;
    u32 x58;
    u32 x5c;
    u8 pad60[0x74 - 0x60];
    s32 x74;
    u32 x78;
} Info_800AB934;

static inline Info_800AB934* Info934(Sub_800A3ED4* e) {
    return e->p1c8->p10;
}

/* ceil(a / b) in single precision. */
static inline f32 CeilDiv(f32 a, f32 b)
{
    return ceil(a / b);
}

static inline void InitBuf(Sub_800A3ED4* w)
{
    Info_800AB934* c;
    s32 n, k;

    w->x1fb = 0;
    w->x1fa = 1;
    w->point = 0;
    w->x22e = 0;
    w->x234 = Info934(w)->x54 + 2;
    w->x1fc = 0;
    c = Info934(w);
    n = c->x74;
    if (n <= 0) {
        n = 1;
    }
    k = CeilDiv(c->x58 + c->x5c + w->x234, n);
    k *= 2;
    w->x264 = fn_8009E8B0(k);
    w->x236 = k;
}

void fn_800AB934(Obj_800A3ED4* self)
{
    Sub_800A3ED4* w = self->sub;
    Info_800AB934* c;
    s32 in;
    u32 lim;
    State_800ADED0* h;

    w->x172 = 0;
    w->motionId = 0;
    if (self->flags & 0x20) {
        self->state = 0xff;
    }
    if (lbl_80311AD4[6] == 0xf) {
        self->state = 0xff;
    }
    switch (self->state) {
    case 0:
        self->prio = 0xfa;
        w->x26c = 1;
        if (Info934(w)->count < 0x20) {
            self->state = 4;
            break;
        }
        InitBuf(w);
        fn_8015ED90(self);
        h = w->p1d8;
        if (h != 0) {
            h->w1a0 = 0;
            h->x260 = fn_800ABEB0;
            h->x31c = fn_800ABE9C;
        }
        c = Info934(w);
        in = fabsf(c->mode);
        if (in == 1) {
            fn_8009DCA8(w, &c->blend);
        }
        self->state = 1;
    case 1:
        in = (lbl_80311AC0.map >= 0x1f4 && lbl_80311AC0.map < 0x258) ? 1 : 0;
        if (!in) {
            fn_8015E600(w);
        }
        if (w->x1fb != 0) {
            w->x1fb = 0;
        }
        break;
    case 2:
        h = w->p1d8;
        if (w->x1fa != 0) {
            c = Info934(w);
            in = fabsf(c->mode);
            if (in == 1) {
                fn_8009DCA8(w, &c->blend);
            }
            fn_8009E71C(w->x264, w->x236);
            c = Info934(w);
            in = fabsf(c->mode);
            if (in == 1) {
                fn_8009DCA8(w, &c->blend);
            } else if (in == 0) {
                if (h->w178 == 1 || h->w178 == 3) {
                    if (w->x1fa == 0) {
                        h->w178 = 2;
                        fn_800A0028(w);
                    }
                    h->w178 = 0;
                    w->pivot = 0;
                }
            }
            InitBuf(w);
            w->x230 = Info934(w)->x74;
            w->x1fa = 0;
        }
        fn_8015E600(w);
        fn_800A0E1C(w);
        if (w->x1fb != 0) {
            if (w->point == 0) {
                w->x1fc = 0;
                w->x22e = w->x230;
                w->x1fa = 1;
                self->state = 1;
            }
        } else if (w->x22e != 0) {
            w->x22e--;
        } else {
            fn_800AB834(self);
            w->x1fc++;
            c = Info934(w);
            lim = c->x78;
            if ((Reached(w->x1fc, lim) && lim != 0) || (w->x230 == 0 && w->x1fc == 1)) {
                w->x1fb = 1;
            } else {
                w->x22e = w->x230;
            }
        }
        break;
    case 0xff:
    case 3:
        fn_8015EBF4(w);
        fn_8009E71C(w->x264, w->x236);
        w->x264 = 0;
        w->x260 = 0;
        w->x25c = 0;
        fn_80100B74(self);
        break;
    case 4:
        if (Info934(w)->count >= 0x20) {
            self->state = 0;
        }
        break;
    case 5:
        break;
    }
    fn_8009E578(self->x0c);
}

extern NJS_MOTION* fn_8008F8FC(Sub_800A3ED4* obj, s32 n);
extern void fn_8015FE60(s32 a, Sub_800A3ED4* obj, f32 f);
extern void fn_8015FB98(s32 a, Sub_800A3ED4* obj);
extern void fn_801E8580(void* p);

void fn_800ABFD4(Obj_800A3ED4* task)
{
    Sub_800A3ED4* obj = task->sub;
    Sub_800A3ED4* owner;
    State_800ADED0* sub;
    Emit_800A7860* tr;
    Obj_800A3ED4* child;
    s32 k;
    f32 f;

    obj->x172 = 0;
    obj->motionId = 0;
    if (task->flags & 0x20) {
        task->state = 0xFF;
    }
    if (lbl_80311AD4[6] == 15) {
        task->state = 0xFF;
    }
    switch (task->state) {
    case 0:
        task->prio = 0xFA;
        obj->x26c = 1;
        fn_800ABEB4(obj);
        fn_8015ED90(task);
        fn_8015EB8C(obj, 0, fn_800ABEB0);
        fn_8015EB8C(obj, 0xD, fn_800ABE9C);
        if (obj->p1d8 != NULL) {
            obj->p1d8->w1a0 = 0;
        }
        if ((s32)fabsf((f32)SpriteCInfo(obj)->mode) == 1) {
            fn_8009DCA8(obj, &SpriteCInfo(obj)->blend);
        }
        task->state = 1;
    case 1:
        if (obj->x264 != NULL) {
            fn_8009E71C(obj->x264, obj->x236);
            obj->x264 = NULL;
            f = SpriteCInfo(obj)->xd0;
            if (fn_8008F8FC(obj, 0) != 0) {
                fn_8015FE60(0, obj, f);
            }
            if (fn_8008F8FC(obj, 1) != 0) {
                fn_8015FB98(1, obj);
            }
        }
        if (obj->x25c != NULL) {
            fn_801E8580(obj->x25c);
            obj->x25c = NULL;
        }
        fn_8015E600(obj);
        break;
    case 2:
        k = (s32)fabsf((f32)SpriteCInfo(obj)->mode);
        sub = obj->p1d8;
        if (k == 1) {
            fn_8009DCA8(obj, &SpriteCInfo(obj)->blend);
        } else if (k == 0) {
            if (sub->w178 == 1 || sub->w178 == 3) {
                if (obj->x1fa == 0) {
                    sub->w178 = 2;
                    fn_800A0028(obj);
                }
                sub->w178 = 0;
                obj->pivot = 0;
            }
        }
        fn_8015E600(obj);
        fn_800A0E1C(obj);
        if (obj->x1fa == 1) {
            fn_800ABEB4(obj);
            child = fn_8009D760(task, fn_800A816C, obj->h178, obj->p1c8);
            child->sub->x260 = fn_801E1A2C(1, 0x2C);
            child->sub->x25c = task;
            tr = child->sub->x260;
            child->sub->x238 = fn_8009E840(obj->x264, child, obj->x236);
            owner = task->sub;
            if (owner != NULL && tr != NULL) {
                tr->parent = task;
                tr->loop = SpriteCInfo(owner)->x5c;
                tr->texlist = fn_800A1B50(owner);
                tr->n = fn_800A1AE8(owner, 0x35);
                tr->item = fn_800A1ABC(owner, 0x35);
                tr->index = 0;
                tr->frame = 0;
                tr->wait = fn_800A10A8(tr->item, tr->index, tr->n) + 1;
                tr->f20 = owner->v50.x;
                tr->f24 = owner->v50.y;
            }
            obj->x1fa = 0;
            obj->point++;
            child->sub->id = SpriteCInfo(child->sub)->flags;
            k = EvDepth(obj);
            if (k >= 0) {
                child->f20 = -1000.0f;
            }
        }
        if (obj->point == 0) {
            obj->x1fb = 1;
            obj->x1fa = 1;
            task->state = 1;
        }
        break;
    case 3:
    case 0xFF:
        fn_8015EBF4(obj);
        fn_8009E71C(obj->x264, obj->x236);
        if (obj->x25c != NULL) {
            fn_801E8580(obj->x25c);
        }
        obj->x264 = NULL;
        obj->x260 = NULL;
        obj->x25c = NULL;
        fn_80100B74(task);
        break;
    case 4:
        if (CfgInfo(obj)->count >= 0x36) {
            task->state = 0;
        }
        break;
    case 5:
        break;
    }
    fn_8009E578(task->x0c);
}

/* EvExt.info of the looping effect (fn_800AC474). */
typedef struct {
    u32 count;     /* 0x00 */
    u8 pad4[0x38 - 4];
    s32 x38;       /* 0x38 */
} EvInfoLoop_800AC474;
static inline EvInfoLoop_800AC474* LoopInfo(Sub_800A3ED4* e) {
    return e->p1c8->p10;
}

void fn_800AC474(Obj_800A3ED4* o)
{
    Sub_800A3ED4* w = o->sub;
    w->x172 = 0;
    w->motionId = 0;
    if (o->flags & 0x20) {
        o->state = 0xff;
    }
    if (lbl_80311AD4[6] == 0xf) {
        o->state = 0xff;
    }
    switch (o->state) {
    case 0:
        o->prio = 0xfa;
        w->x26c = 1;
        w->x1fb = 0;
        w->x1fa = 1;
        w->point = 0;
        w->x21c = 0;
        w->x1fc = 0;
        fn_8015ED90(o);
        fn_8015EB8C(w, 0, fn_800ABEB0);
        fn_8015EB8C(w, 0xd, fn_800AC44C);
        if (w->p1d8 != NULL) {
            w->p1d8->w1a0 = 0;
        }
        o->state = 1;
    case 1:
        fn_800A0E1C(w);
        if (fn_8015E600(w) == 0) {
            w->x1fb = 0;
        }
        break;
    case 2:
        fn_800A0E1C(w);
        if (w->x1fa == 1) {
            Obj_800A3ED4* n = fn_8009D760(o, fn_800A8A80, w->h178, w->p1c8);
            Sub_800A3ED4* ow;
            Emit_800A7860* f;
            n->sub->x260 = fn_801E1A2C(1, 0x2c);
            n->sub->x25c = o;
            ow = o->sub;
            f = n->sub->x260;
            if (ow != NULL && f != NULL) {
                f->parent = o;
                f->loop = LoopInfo(ow)->x38;
                f->texlist = fn_800A1B50(ow);
                f->n = fn_800A1AE8(ow, 0x2f);
                f->item = fn_800A1ABC(ow, 0x2f);
                f->index = 0;
                f->frame = 0;
                f->wait = fn_800A10A8(f->item, f->index, f->n) + 1;
                f->f20 = ow->v50.x;
                f->f24 = ow->v50.y;
            }
            w->x25c = n;
            w->x1fa = 0;
            w->point++;
        }
        if (w->point == 0) {
            w->x1fb = 1;
            w->x1fa = 1;
            o->state = 1;
        } else {
            fn_8015E600(w);
            fn_800A0E1C(w);
        }
        break;
    case 3:
    case 0xff:
        fn_8015EBF4(w);
        w->x264 = NULL;
        w->x260 = NULL;
        w->x25c = NULL;
        fn_80100B74(o);
        break;
    case 4:
        if (LoopInfo(w)->count >= 0x30) {
            o->state = 0;
        }
        break;
    case 5:
        break;
    }
    fn_8009E578(o->x0c);
}

static inline void FreeSlot(Sub_800A3ED4* e) {
    if (e->x25c != NULL) {
        fn_801E1784(e->x25c);
        e->x25c = NULL;
    }
}
static inline void FreeBlock(void* p) {
    if (p != NULL) {
        fn_801E1784(p);
    }
}

extern const NJS_VECTOR lbl_802B0FE8;

void fn_800ACBC8(Obj_800A3ED4* self) {
    P* q;
    s32 k;
    RingPart* s;
    EvInfoRing* info;
    Angle ax;
    Angle ay;
    s32 w;
    s32 i;
    f32 x;
    Angle az;
    RingPart* t;
    u32 d;
    Sub_800A3ED4* e;
    State_800ADED0* sub;
    Obj_800A3ED4* child;
    RingPart* sp;
    f32 y;
    f32 z;
    P* p;
    EvInfoBlend* blend;
    P* rec;
    NJS_VECTOR v;
    s32 j;

    e = self->sub;
    e->motionId = e->x172 = 0;
    if (self->flags & 0x20) {
        self->state = 0xff;
    }
    if (lbl_80311AD4[6] == 0xf) {
        self->state = 0xff;
    }
    switch (self->state) {
    case 0:
        self->prio = 0xfa;
        e->x26c = 1;
        info = RingInfo(e);
        if (info->count < 0x25) {
            self->state = 4;
            break;
        }
        fn_8015ED90(self);
        fn_8015EB8C(e, 0, fn_800ABEB0);
        fn_8015EB8C(e, 0xd, fn_800ABE9C);
        if (e->p1d8 != 0) {
            e->p1d8->w1a0 = 0;
        }
        blend = BlendInfo(e);
        if ((s32)fabsf((f32)blend->mode) == 1) {
            fn_8009DCA8(e, &blend->blend);
        }
        e->w100 = fn_800A1B50(e);
        if (e->w100 != NULL) {
            fn_80227810(e->w100);
        }
        rec = fn_801E1A2C(1, 0x7c);
        fn_800AC728(e, rec);
        e->x25c = NULL;
        e->x264 = NULL;
        e->x260 = rec;
        self->state = 1;
    case 1:
        if (e->x25c != NULL) {
            FreeSlot(e);
            e->x25c = NULL;
        }
        fn_8015E600(e);
        break;
    case 2:
        blend = BlendInfo(e);
        sp = e->x25c;
        p = e->x260;
        sub = e->p1d8;
        k = (s32)fabsf((f32)blend->mode);
        if (k == 1) {
            fn_8009DCA8(e, &blend->blend);
        } else if (k == 0) {
            if (sub->w178 == 1 || sub->w178 == 3) {
                if (!e->x1fa) {
                    sub->w178 = 2;
                    fn_800A0028(e);
                }
                sub->w178 = 0;
                e->pivot = 0;
            }
        }
        fn_8015E600(e);
        if (e->x1fa == 1) {
            fn_8009E71C(e->x264, e->x236);
            fn_800AC728(e, p);
            e->x1fa = 0;
            sp = e->x25c;
        }
        fn_800A0E1C(e);
        if (e->x1fc > 0) {
            e->x1fc--;
        } else if (e->x1fc == 0) {
            if (e->point != 0) {
                break;
            }
            for (s = sp, i = 0; i < e->x22c; s++, i++) {
                if (i == 0) {
                    s->x10 = 0;
                } else {
                    s->x10 = (f32)e->x230 * (3.0517578125e-05f * (f32)rand());
                }
            }
            w = -1;
            info = RingInfo(e);
            d = info->x90;
            if (d != 0) {
                w = d;
            }
            e->x1fc = w;
            e->x1fb = 1;
            e->x1fa = 1;
            self->state = 1;
            break;
        }
        for (t = sp, j = 0; j < e->x22c; t++, j++) {
            if (t->x10 == 0) {
                x = e->v38.x;
                y = e->v38.y;
                z = e->v38.z;
                ax = e->ang.x;
                ay = e->ang.y;
                az = e->ang.z;
                child = fn_8009D760(self, fn_800A8FE0, e->h178, e->p1c8);
                child->sub->x260 = fn_801E1A2C(1, 0x7c);
                child->sub->x238 = fn_8009E840(e->x264, child, e->x236);
                q = child->sub->x260;
                *q = *p;
                q->w68 = 0;
                q->w6c = p->w6c;
                q->f24 += q->f28 * (3.0517578125e-05f * (f32)rand());
                q->f2c += q->f30 * (3.0517578125e-05f * (f32)rand());
                child->f20 = -200.0f;
                info = RingInfo(e);
                if (info->x50 == 1) {
                    f32 r = info->x48;
                    v = lbl_802B0FE8;
                    fn_800A1210(&t->pos, &v, 360.0f * (3.0517578125e-05f * (f32)rand()), r);
                }
                child->sub->v38.x = e->x24c.x + t->pos.x;
                child->sub->v38.y = e->x24c.y + t->pos.y;
                child->sub->v38.z = e->x24c.z + t->pos.z;
                p->w4 = &e->x24c;
                p->w8 = &e->x20c.x;
                fn_800A10E8(&child->sub->v38, p->w4, e->x258 * (3.0517578125e-05f * (f32)rand()));
                child->sub->x25c = self;
                t->x10 = e->x22e;
                e->v38.x = x;
                e->v38.y = y;
                e->v38.z = z;
                e->ang.x = ax;
                e->ang.y = ay;
                e->ang.z = az;
            } else {
                t->x10--;
            }
        }
        break;
    case 3:
    case 0xff: {
        void* a;
        void* b;
        fn_8015EBF4(e);
        fn_8009E71C(e->x264, e->x236);
        if (e->w100 != NULL && e->w100->textures->texaddr != NULL) {
            fn_802275A4(e->w100, 0);
        }
        a = e->x25c;
        b = e->x260;
        if (a != NULL) {
            FreeBlock(a);
        }
        if (b != NULL) {
            FreeBlock(b);
        }
        e->x264 = NULL;
        e->x260 = NULL;
        e->x25c = NULL;
        fn_80100B74(self);
        break;
    }
    case 4:
        info = RingInfo(e);
        if (info->count >= 0x25) {
            self->state = 0;
        }
        break;
    case 5:
        break;
    }
    fn_8009E578(self->x0c);
}

/* EvExt.info of the emitter effect (fn_800AD330). */
typedef struct {
    u8 pad0[0x18];
    u32 flags;     /* 0x18 */
} EvInfoEmitter_800AD330;
static inline EvInfoEmitter_800AD330* EmitterInfo(Sub_800A3ED4* e) {
    return e->p1c8->p10;
}

void fn_800AD330(Sub_800A3ED4* o)
{
    NJS_POINT3 v;
    NJS_MATRIX m;
    RingPart* e;
    RingPart* ents;
    Obj_800A3ED4* n;
    Obj_800A3ED4* t;
    P* lnk;
    s32 i = 0;

    if (o->p1d8 != 0) {
        t = o->p1d8->task;
    } else {
        return;
    }
    if (t == 0) return;
    ents = t->sub->x25c;
    lnk = t->sub->x260;
    if (t->state == 1) return;
    for (e = ents; i < t->sub->x22c; e++, i++) {
        if (e->x10 == 0) {
            n = fn_8009D760(t, fn_800A9708, o->h178, o->p1c8);
            n->sub->x260 = fn_801E1A2C(1, 0x7c);
            fn_800AD588(lnk, n->sub->x260);
            v = lbl_802B0FDC;
            njUnitMatrix(m);
            njTranslate(m, o->v38.x, o->v38.y, o->v38.z);
            njRotateXYZ(m, o->ang.x, o->ang.y, o->ang.z);
            njTranslate(m, o->pivotPos.x, o->pivotPos.y, o->pivotPos.z);
            njRotateXYZ(m, o->pivotAng[0], o->pivotAng[1], o->pivotAng[2]);
            njCalcPoint(m, &v, &t->sub->x24c);
            fn_8015F7A8(m, &t->sub->x20c);
            n->sub->v38.x = t->sub->x24c.x + e->pos.x;
            n->sub->v38.y = t->sub->x24c.y + e->pos.y;
            n->sub->v38.z = t->sub->x24c.z + e->pos.z;
            lnk->w4 = &t->sub->x24c;
            lnk->w8 = &t->sub->x20c.x;
            fn_800A10E8(&n->sub->v38, lnk->w4,
                        t->sub->x258 * (3.0517578125e-05f * (f32)rand()));
            n->sub->x25c = t;
            if (EmitterInfo(o)->flags & 0x80000) {
                n->sub->id = EmitterInfo(n->sub)->flags;
            }
            e->x10 = t->sub->x22e;
        } else {
            e->x10--;
        }
    }
}

/* state */

typedef struct RibStrand {
    u8 pad0[4];
    s32 done;       /* 0x04 */
    s32 len;        /* 0x08 */
    s32 life;       /* 0x0C */
    s32 fade;       /* 0x10 */
    s32 age;        /* 0x14 */
    f32 floor;      /* 0x18 */
    f32 x1c;        /* 0x1C */
    NJS_POINT3 vel; /* 0x20 */
    u8 pad2c[0xC];
    f32 fall;       /* 0x38 */
    u8 pad3c[0xC];
    u8 alpha;       /* 0x48 */
    u8 pad49[3];
} RibStrand;

typedef struct RibCfg {
    u32 count;      /* 0x00 */
    u8 pad4[0xC];
    u32 x10;        /* 0x10 */
    u8 pad14[0x30];
    s32 x44;        /* 0x44 */
    u32 x48;        /* 0x48 */
    s32 x4c;        /* 0x4C */
    u32 x50;        /* 0x50 */
    u8 pad54[4];
    f32 x58;        /* 0x58 */
    u8 pad5c[4];
    u32 x60;        /* 0x60 */
    u8 pad64[4];
    f32 x68;        /* 0x68 */
    f32 x6c;        /* 0x6C */
    u32 x70;        /* 0x70 */
    u8 pad74[4];
    s32 x78;        /* 0x78 */
    s32 x7c;        /* 0x7C */
    s32 x80;        /* 0x80 */
    u32 x84;        /* 0x84 */
    f32 x88;        /* 0x88 */
    u32 x8c;        /* 0x8C */
    u32 x90;        /* 0x90 */
    NJS_POINT3 x94; /* 0x94 */
    f32 xa0;        /* 0xA0 */
    u32 xa4;        /* 0xA4 */
    Ang3 xa8;       /* 0xA8 */
    Ang3 xb4;       /* 0xB4 */
    u8 padc0[0x2C8 - 0xC0];
    u32 x2c8;       /* 0x2C8 */
    u32 x2cc;       /* 0x2CC */
    u32 x2d0;       /* 0x2D0 */
} RibCfg;

extern NJS_POINT3 lbl_802B10D8;
extern NJS_POINT3 lbl_802B10E4;
extern s8 fn_8015FAD4(NJS_POINT3* p);
extern MapInfo lbl_80311AC0;
extern f32 fn_80291A5C(f32 x);
extern f32 fn_8009E4F8(u8 v);
extern f32 fn_800A0ADC(f32 t, s32 a, s32 b, u32 flags);

extern void fn_8015FE60(s32 i, Sub_800A3ED4* w, f32 f);
extern void fn_8015FB98(s32 i, Sub_800A3ED4* w);

#define RIB_RND (3.0517578125e-05f * rand())

static inline RibCfg* RibInfo(Sub_800A3ED4* o) {
    return o->p1c8->p10;
}

static inline u32 RibDepth(Sub_800A3ED4* o) {
    EvInfo* e = o->p1c8->p10;
    return e->count > 3 ? e->w10 : 0;
}

static inline s32 RibNoModel(Sub_800A3ED4* w)
{
    s32 r = 0;
    u32 p = RibInfo(w)->x48;
    if (p == 0 || (p != 0 && w->we4 == NULL)) {
        r = 1;
    }
    return r;
}

static inline BOOL RibMapInRange(void)
{
    s32 in = 0;
    if (lbl_80311AC0.map >= 500 && lbl_80311AC0.map < 600) {
        in = 1;
    }
    return in ? TRUE : FALSE;
}

/* Copies a strand's n points into the draw buffer, offset by the emitter, fading to the tail. */
static inline void RibFill(Sub_800A3ED4* w, RibPt* src, RibPt* dst, s32 n)
{
    f32 step = w->x21c / n;
    s32 j;
    for (j = 0; j < n; j++) {
        dst->pos.x = src->pos.x + w->x24c.x;
        dst->pos.y = src->pos.y + w->x24c.y;
        dst->pos.z = src->pos.z + w->x24c.z;
        dst->alpha = step * (n - j);
        dst++;
        src++;
    }
}

void fn_800A4924(Obj_800A3ED4* o)
{
    NJS_POINT3 up = lbl_802B10D8;
    NJS_POINT3 off = lbl_802B10E4;
    NJS_MATRIX m;
    DrawState ds;
    u8 b;
    RibStrand* s;
    RibCfg* cfg;
    RibPt* draw;
    RibPt* pt;
    RibStrand* st;
    s32 i;
    RibPt* p;
    s32 n;
    s32 base;
    Sub_800A3ED4* w;
    Sub_800A3ED4* pw;
    s32 done = 0;
    s32 cnt;
    u32* item;
    s32 j;
    s32 k;
    s32 a1;
    s32 a2;
    RibPt* q;
    f32 h;
    f32 py;
    f32 by;

    w = o->sub;
    cfg = w->p1c8->p10;
    s = w->x260;
    if (o->parent->flags & 0x40) {
        o->state = 0xff;
    } else {
        pw = o->parent->sub;
        cnt = fn_800A1AE8(pw, 0x31);
        w->x218 = cnt;
        item = fn_800A1ABC(pw, 0x31);
        w->x222 = RibNoModel(pw);
    }
    if (o->flags & 0x20) {
        o->state = 0xff;
    }
    switch (o->state) {
    case 0: {
        RibPt* draw;
        RibPt* pt;
        s32 i;
        s32 j;
        u32 n;
        f32 floor;
        f32 g0;
        f32 spread;

        o->prio = 0xfb;
        if (!cfg->x68) {
            o->state = 2;
            break;
        }
        if (cfg->x70 != 0 && RibInfo(pw)->count >= 0xb1) {
            w->x221 = 1;
        } else {
            w->x221 = 0;
        }
        w->w100 = pw->w100;
        g0 = cfg->x58;
        if (fn_8008F8FC(w, 0) != NULL) {
            fn_8015FE60(0, w, g0);
        }
        if (fn_8008F8FC(w, 1) != NULL) {
            fn_8015FB98(1, w);
        }
        w->x18 |= 0x1000;
        if (cfg->x50 == 1) {
            w->id = 0;
        } else {
            w->id = 3;
        }
        w->x24c = pw->x24c;
        w->x20c = pw->x20c;
        draw = fn_801E1A2C(1, w->x234 * sizeof(RibPt));
        pt = fn_801E1A2C(1, w->x206 * w->x234 * sizeof(RibPt));
        w->x268 = draw;
        w->x264 = pt;
        w->x21c = 0xff;
        if (!RibMapInRange()) {
            off = w->x24c;
            w->x1ec = fn_8015FAD4(&off);
            floor = off.y;
        }
        n = cfg->x84 > 100 ? 100 : cfg->x84;
        spread = 1.8f * (100 - n);
        for (i = 0; i < w->x206; s++, i++) {
            s->done = 0;
            s->len = w->x234;
            s->life = (s16)cfg->x7c + (s16)((s16)cfg->x80 * RIB_RND);
            s->fade = (s16)cfg->x78;
            if (s->life < 0) {
                s->life = 0;
            }
            if (s->fade > s->life) {
                s->fade = s->life - 1;
            }
            if (s->fade < 0) {
                s->fade = 0;
            }
            s->age = 0;
            s->alpha = 0xff;
            a1 = 182.04445f * (spread * RIB_RND);
            a2 = 182.04445f * (360.0f * RIB_RND);
            up.x = up.y = 0.0f;
            up.z = cfg->x68 + cfg->x6c * RIB_RND;
            njUnitMatrix(m);
            njRotateXYZ(m, w->x20c.x, w->x20c.y, w->x20c.z);
            njRotateXYZ(m, a1, 0, a2);
            njCalcPoint(m, &up, &s->vel);
            if (cfg->x90 != 0) {
                s->vel.x *= cfg->x94.x;
                s->vel.y *= cfg->x94.y;
                s->vel.z *= cfg->x94.z;
            }
            s->fall = 0.0f;
            for (j = 0; j < w->x234; pt++, j++) {
                f32 g;

                if (cfg->xa0 <= 0.0f) {
                    g = 0.0f;
                } else {
                    g = cfg->xa0 - 1.0f;
                }
                g *= RIB_RND;
                if (j == 0) {
                    pt->rot.x = cfg->xa8.x;
                    pt->rot.y = cfg->xa8.y;
                    pt->rot.z = cfg->xa8.z;
                    if (cfg->xa4 != 0) {
                        pt->rot.x = 182.04445f * (360.0f * RIB_RND);
                        pt->rot.y = 182.04445f * (360.0f * RIB_RND);
                        pt->rot.z = 182.04445f * (360.0f * RIB_RND);
                    }
                    pt->frame = w->x18c;
                    pt->scl.x = pw->v50.x * (1.0f + g);
                    pt->scl.y = pw->v50.y * (1.0f + g);
                    pt->scl.z = pw->v50.z * (1.0f + g);
                    if (pt->scl.x < 0.0f) {
                        pt->scl.x = 0.0f;
                    }
                    if (pt->scl.y < 0.0f) {
                        pt->scl.y = 0.0f;
                    }
                    if (pt->scl.z < 0.0f) {
                        pt->scl.z = 0.0f;
                    }
                    pt->x24 = fn_800A10A8(item, 0, cnt) + 1;
                    pt->x28 = 0;
                }
                if (RibNoModel(w)) {
                    s->x1c = fn_80291A5C((f32)pow(pt->scl.x, 2.0) + (f32)pow(pt->scl.y, 2.0));
                    s->floor = 0.5f * s->x1c + floor;
                } else {
                    s->x1c = fn_8009E3D0(7, fn_801C8930(w->we4), &pt->scl);
                    s->floor = floor + s->x1c;
                }
            }
        }
        if (w->x221 != 0) {
            w->x21e = cfg->x2c8;
            w->x21f = cfg->x2cc;
            w->x220 = cfg->x2d0;
            if (w->x21e == 0 && w->x21f == 0 && w->x220 == 0) {
                w->x21e = w->x21f = w->x220 = 0xff;
            }
            w->x20 = fn_8009E4F8(w->x21e);
            w->x24 = fn_8009E4F8(w->x21f);
            w->x28 = fn_8009E4F8(w->x220);
        }
        pw->point++;
        o->state = 1;
        o->f20 = RibDepth(w) == 0 ? -100.0f : -300.0f;
        break;
    }
    case 1:
        draw = w->x268;
        pt = w->x264;
        st = w->x260;
        if (cfg->x44 <= -1) {
            w->x24c = pw->x24c;
            w->x20c = pw->x20c;
        }
        if (RibNoModel(w)) {
            DrawStateDefault2D(&ds);
            ds.fog = w->w2c;
            fn_8009E910(&ds, cfg->x4c, &b);
            w->x25c = &ds;
            DrawStatePush(&ds);
        }
        for (i = 0; i < w->x206; st++, i++) {
            base = i * w->x234;
            n = 0;
            p = &pt[base];
            if (st->done == 0) {
                if (st->age >= st->life) {
                    st->len--;
                    if (st->len <= 0) {
                        st->done = 1;
                    } else {
                        RibPt* q;
                        st->age++;
                        for (k = 0, q = p; k < st->len; q++) {
                            n++;
                            if (!q->pos.x && !q->pos.y && !q->pos.z) {
                                k = st->len;
                            } else {
                                k++;
                            }
                        }
                        RibFill(w, p, draw, n);
                    }
                } else {
                    f32 t;
                    st->age++;
                    for (k = st->len - 1; k >= 1; k--) {
                        pt[base + k] = pt[base + k - 1];
                    }
                    t = fn_800A0ADC(0.0f, st->age, st->life + w->x234 - 1, 0x20101);
                    off.x = st->vel.x * t;
                    off.y = st->vel.y * t;
                    off.z = st->vel.z * t;
                    off.y = st->fall * t + off.y;
                    py = p->pos.y;
                    by = w->x24c.y;
                    h = by + (off.y + py);
                    if (!RibMapInRange() && w->x1ec != -1 && h < st->floor && cfg->x8c == 0) {
                        f32 r = by + py - st->floor;
                        r /= fabs(off.y);
                        off.x *= r;
                        off.y *= r;
                        off.z *= r;
                        st->vel.y *= -1.0f;
                        st->fall *= -1.0f;
                    }
                    st->fall -= cfg->x88;
                    p->pos.x += off.x;
                    p->pos.y += off.y;
                    p->pos.z += off.z;
                    p->rot.x += cfg->xb4.x;
                    p->rot.y += cfg->xb4.y;
                    p->rot.z += cfg->xb4.z;
                    for (k = 0; k < st->len;) {
                        n++;
                        if (!pt[base + k].pos.x && !pt[base + k].pos.y && !pt[base + k].pos.z) {
                            k = st->len;
                        } else {
                            k++;
                        }
                    }
                    RibFill(w, p, draw, n);
                }
                if (st->done == 0) {
                    if (cnt != 0) {
                        if (p->x24 == 0 && p->x28 < cnt) {
                            p->x28++;
                            if (p->x28 == cnt && cfg->x60 != 0) {
                                p->x28 = 0;
                            }
                            if (p->x28 < cnt) {
                                p->x24 = fn_800A10A8(item, p->x28, cnt) - 1;
                            }
                        } else if (p->x28 != cnt) {
                            p->x24--;
                        }
                        if (p->x28 == cnt && p->x28 > 0) {
                            p->x28 = cnt - 1;
                        }
                    } else {
                        p->x28 = 0;
                    }
                    for (j = 0, q = draw; j < n; p++, q++, j++) {
                        q->x28 = p->x28;
                        q->frame = p->frame;
                        q->rot = p->rot;
                        q->scl = p->scl;
                        if (SubFlag(pw) == 0) {
                            w->x258 = st->x1c;
                            w->alpha = fn_8009E4F8(st->alpha);
                            fn_800A432C(w, pw, q);
                        }
                    }
                }
                {
                    s32 last = st->life + w->x234 - 1;
                    if (st->age + st->fade >= last) {
                        st->alpha = 255.0f / (st->fade + 1) * (last - st->age);
                    }
                }
            } else {
                done++;
            }
            if (done >= w->x206) {
                o->state = 2;
            }
        }
        if (RibNoModel(w)) {
            DrawStatePop(NULL);
        }
        break;
    case 2:
        pw->point--;
        if (pw->point == 0xffff) {
            pw->point = 0;
        }
        fn_8009E804(pw->x264, w->x238);
    case 0xff: {
        RibPt* draw;
        RibStrand* st;
        RibPt* pt;
        draw = w->x268;
        pt = w->x264;
        st = w->x260;
        if (draw != NULL) {
            if (draw != NULL) {
                fn_801E1784(draw);
            }
        }
        if (st != NULL) {
            if (st != NULL) {
                fn_801E1784(st);
            }
            if (pt != NULL) {
                fn_801E1784(pt);
            }
        }
        w->x268 = NULL;
        w->x264 = NULL;
        w->x260 = NULL;
        w->x25c = NULL;
        fn_8009E630(o);
        break;
    }
    case 0xfe:
        /* nothing: an empty case here gives the original's switch tree (its extra bge) */
        break;
    }
}

