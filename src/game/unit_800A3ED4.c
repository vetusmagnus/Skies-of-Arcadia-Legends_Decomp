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
extern void* fn_80226704(void* list, void* cb, s32 size);
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
    u8 pad20[0x38 - 0x20];
    void* p38;
    u8 pad3c[0x44 - 0x3c];
    NJS_POINT3 v44;
    f32 f50, f54, f58;
    NJS_POINT3 v5c;
} Src_800A3ED4;
typedef struct Sub_800A3ED4 Sub_800A3ED4;
struct Sub_800A3ED4 {
    s16 h0;
    u8 pad2[0x18 - 2];
    u32 x18;
    f32 alpha;
    u8 pad20[0x2c - 0x20];
    s32 w2c;
    s32 w30;
    s32 w34;
    NJS_POINT3 v38;
    Angle ang[3];
    NJS_POINT3 v50;
    NJS_POINT3 vel;
    u8 pad68[0xe4 - 0x68];
    void* we4;
    NJS_MOTION* motion;
    void* wec;
    u8 padf0[0x100 - 0xf0];
    NJS_TEXLIST* w100;
    u8 pad104[0x16e - 0x104];
    s16 h16e;
    u8 pad170[0x176 - 0x170];
    u16 id;
    s16 h178;
    s16 h17a;
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
    u8 pad1cc[0x1d8 - 0x1cc];
    Sub_800A3ED4* p1d8;
    u8 pad1dc[0x208 - 0x1dc];
    s16 x208, x20a;
    Ang3 x20c;
    u8 pad218[0x21d - 0x218];
    u8 x21d;
    u8 pad21e[0x232 - 0x21e];
    u16 point;
    u8 pad234[0x238 - 0x234];
    u16 x238;
    u8 pad23a[0x24c - 0x23a];
    NJS_POINT3 x24c;
    u8 pad258[0x25c - 0x258];
    void* x25c;
    void* x260; /* per-kind record: P (fn_800A9708/fn_800A8FE0), Emit (fn_800A6F30...) */
    ItemList* x264;
};
typedef struct Obj_800A3ED4 Obj_800A3ED4;
struct Obj_800A3ED4 {
    u8 pad0[8];
    Obj_800A3ED4* parent;
    u8 pad0c[0x18 - 0xc];
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
extern s32 fn_8015E600(EvObj*);
extern void fn_800972AC(void);
extern void* fn_8015F180(void*);
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
u32 fn_800A10A8(u32 *base, u32 i, s32 n);
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
    s->ang[0] = (s32)(182.04445f * src->f50);
    s->ang[1] = (s32)(182.04445f * src->f54);
    s->ang[2] = (s32)(182.04445f * src->f58);
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
    Task* parent;          /* 0x00 */
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
    return em->parent->work;
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
    u8 pad1C[0x48 - 0x1C];
    u32 drawMode;    /* 0x48 */
    u32 alphaMode;   /* 0x4C */
    u32 x50;         /* 0x50 */
    u32 animated;    /* 0x54 */
    u32 noLoopCtl;   /* 0x58 */
    u8 pad5C[0x6C - 0x5C];
    u32 life;        /* 0x6C */
    u8 pad70[0xC4 - 0x70];
    s32 spinX;       /* 0xC4 */
    s32 spinY;       /* 0xC8 */
    u8 padCC[4];
    f32 xd0;         /* 0xD0 */
} EvInfoSpriteC_800A816C;


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
        obj->ang[2] = 0;
        obj->ang[1] = 0;
        obj->ang[0] = 0;
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
                            fn_800A322C(bb, &obj->v38, obj->ang[2], &obj->v50, obj->id, 1);
                        } else {
                            fn_800A322C(bb, &obj->v38, obj->ang[2], &obj->v50, obj->id, 0);
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
                        fn_800A1948(&obj->v38, obj->ang, 3);
                    }
                    if (obj->w100 != NULL) {
                        fn_80299040(obj->w100);
                        if (em->item != NULL) {
                            fn_80298FE4(fn_800A10C4(em->item, em->index, em->n));
                        } else {
                            fn_80298FE4(0);
                        }
                    }
                    ax = obj->ang[0];
                    ay = obj->ang[1];
                    az = obj->ang[2];
                    njUnitMatrix(m);
                    pw = PWORKS(em);
                    if ((ci = pw->p1c8->p10)->animated == 0) {
                        njRotateXYZ(m, pw->x20c.x, pw->x20c.y, pw->x20c.z);
                    }
                    njRotateZXY(m, obj->ang[0], obj->ang[1], obj->ang[2]);
                    fn_800A13D8(m, obj->ang);
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
                    obj->ang[0] = ax;
                    obj->ang[1] = ay;
                    obj->ang[2] = az;
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
            fn_800A1948(&w->v38, w->ang, 3);
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
