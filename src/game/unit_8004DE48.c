#include "types.h"
/* Effect task handlers from 0x8004DE48 (a new .sdata2 block at 0x80348700: second 182.04445f, 1.0f
 * and 0.0f): the model effect fn_8004DE48, the area-of-effect pulse fn_8004E474 and the strip helpers. */
#include "types.h"
#include "ninja.h"
#include "game/drawstate.h"

typedef NJS_POINT3 Vec;
typedef struct { u8 pad[0x154]; void* x154; } Body;
/* Task data the effect handlers read: position, yaw and the model body. */
typedef struct {
    u8 pad0[0x1C];
    Vec pos;            /* 0x1C */
    u8 pad28[4];
    s32 x2c;            /* 0x2C */
    u8 pad30[0x4C - 0x30];
    Body* body;         /* 0x4C */
} TaskData;
typedef struct { u8 pad[0x24]; TaskData* data; } TaskRef;
typedef struct {
    u8 pad0[0x6C];
    u32 input;          /* 0x6C */
    u8 pad70[0x188 - 0x70];
    u32 col;            /* 0x188 */
    u8 pad18c[0x1C4 - 0x18C];
    s32 count;          /* 0x1C4 */
    s16 x1c8;
    s16 x1ca;
    u32 flags;          /* 0x1CC */
} ObjStats;
extern ObjStats lbl_8030A10C;
extern void* fn_801E1C7C(u32);
extern void fn_801E17E0(void*);
extern void fn_8001DF44(void*, Vec*);
extern void fn_80061518(void*, Vec*, void*);
extern void fn_80071CF0(Vec*, Vec*);
extern void fn_8006CEEC(void*, void*, int, s16);
extern void fn_80034E6C(void* o, s16 idx, void* m, void* a, f32 f);
extern void* memcpy(void*, const void*, unsigned long);

typedef struct { void** mdata; u32 nbFrame; } Motion;

typedef struct { u8 pad[8]; void* x8; } ObjSrc;
typedef struct Q16 { s32 a, b, c, d; } Q16;
typedef struct W80049130 {
    u8 pad0[0x10];
    char* x10;          /* 0x10 */
    u8 pad14[0x1c - 0x14];
    NJS_POINT3 x1c;     /* 0x1c */
    u8 pad28[0x4c - 0x28];
    struct I80049130* e; /* 0x4c */
} W80049130;
typedef struct I80049130 {
    u8 pad0[4];
    s32 x4;             /* 0x04 */
    void* x8;           /* 0x08 */
    u8 pad0C[0x1c - 0xc];
    struct { Q16 q; u8 pad10[0x56 - 0x10]; s16 x56; }* x1c; /* 0x1c */
} I80049130;
typedef struct { u8 pad[0x24]; W80049130* work; } Node_80049130;
typedef NJS_POINT3 Vec_8004A40C;
typedef struct {
    s16 id;
    s16 weight;
} AnimEnt_X;
typedef struct {
    u8 pad0[0x8];
    s32 src;            /* 0x008 */
    u8 pad0c[4];
    u32 type;           /* 0x010 */
    s16 start;          /* 0x014 */
    s16 fadeInEnd;      /* 0x016 */
    s16 end;            /* 0x018 */
    s16 fadeInLen;      /* 0x01A */
    s16 fadeOutLen;     /* 0x01C */
    AnimEnt_X anim[0x40]; /* 0x01E */
    s16 animA;          /* 0x11E */
    s16 animB;          /* 0x120 */
    s16 id;             /* 0x122 */
    u8 pad124[0x128 - 0x124];
    Vec_8004A40C mtx;            /* 0x128 */
    Vec_8004A40C vel0;           /* 0x134 */
    f32 x140;           /* 0x140 */
    s16 x144;           /* 0x144 */
    s16 count;          /* 0x146 */
    u16 x148;           /* 0x148 */
    u8 pad14a[2];
    f32 x14c;           /* 0x14C */
    u32 x150;           /* 0x150 */
    u32 x154;           /* 0x154 */
    f32 x158;           /* 0x158 */
    f32 x15c;           /* 0x15C */
    Vec_8004A40C acc;            /* 0x160 */
    s16 accStart;       /* 0x16C */
    s16 accEnd;         /* 0x16E */
    s16 x170;           /* 0x170 */
} Cfg_80049464;
typedef struct Task_80049464 {
    u8 pad[0x24];
    struct Data_80049464* data;
} Task_80049464;
typedef struct {
    s16 timer;          /* 0x00 */
    s16 count;          /* 0x02 */
    Task_80049464* task;         /* 0x04 */
    void* mtx;          /* 0x08 */
    f32 fade;           /* 0x0C */
    Vec_8004A40C pos;            /* 0x10 */
    Vec_8004A40C pos2;           /* 0x1C */
    Vec_8004A40C vel;            /* 0x28 */
    s16 frame;          /* 0x34 */
    u8 pad36[2];
    void* buf;          /* 0x38 */
    Cfg_80049464* cfg;           /* 0x3C */
} Work_80049464;
typedef struct Data_80049464 {
    u8 pad0[0x8];
    s32 src;            /* 0x08 */
    u8 pad0c[0x4C - 0xC];
    Work_80049464* work;         /* 0x4C */
    s32 x50;            /* 0x50 */
    s32 x54;            /* 0x54 */
} Data_80049464;
extern int fn_80018398(Vec_8004A40C*, int);
typedef struct { u8 a, b, c, d; } Col4_8004DE48;
typedef ObjSrc ObjSrc_8004DE48;
typedef struct {
    s8 id;
    u8 pad1[3];
    s8 x4;
    u8 pad5[0x5A - 5];
    u8 x5a;                 /* 0x05A */
    u8 pad5b[0xEC - 0x5B];
    u32 xec;                /* 0x0EC */
    u8 padf0[0x1EC - 0xF0];
    u32 x1ec;               /* 0x1EC */
} Unit_8004DE48;
typedef struct { u8 pad0[0x1C]; Vec_8004A40C pos; u8 pad28[0x4C - 0x28]; Unit_8004DE48* w; } TWk_8004DE48;
typedef struct { u8 pad[0x24]; TWk_8004DE48* work; } Tgt_8004DE48;
typedef struct {
    u8 pad0[0x10];
    u32 flags;              /* 0x10 */
    s16 start;              /* 0x14 */
    s16 id;                 /* 0x16 */
    u8 pad18[4];
    Vec_8004A40C pos;                /* 0x1C */
    f32 rot[3];             /* 0x28 */
    Vec_8004A40C vel;                /* 0x34 */
    f32 rotVel[3];          /* 0x40 */
    s16 rotStart;           /* 0x4C */
    s16 rotEnd;             /* 0x4E */
    s16 end;                /* 0x50 */
    s16 fx;                 /* 0x52 */
    s16 interval;           /* 0x54 */
} Cmd_8004DE48;
typedef struct {
    s16 timer;              /* 0x00 */
    u8 pad2[2];
    Tgt_8004DE48* tgt;               /* 0x04 */
    Motion* mtx;            /* 0x08 */
    Motion* src;            /* 0x0C */
    f32 frame;              /* 0x10 */
    s16 x14;                /* 0x14 */
    s16 x16;                /* 0x16 */
    s16 count;              /* 0x18 */
    u8 pad1a[2];
    Cmd_8004DE48* c;                 /* 0x1C */
} Sub_8004DE48;
typedef struct {
    u8 pad0[8];
    void* texlist;          /* 0x08 */
    Motion* motion;         /* 0x0C */
    ObjSrc_8004DE48* src;            /* 0x10 */
    u8 pad14[2];
    s16 x16;                /* 0x16 */
    u8 pad18[4];
    Vec_8004A40C pos;                /* 0x1C */
    s32 ang[3];             /* 0x28 */
    Vec_8004A40C scl;                /* 0x34 */
    u8 pad40[4];
    u8 kind;                /* 0x44 */
    u8 pad45[7];
    Sub_8004DE48* sub;               /* 0x4C */
} Wk_8004DE48;
typedef struct {
    u8 pad[0x18];
    u8 flags;
    u8 state;
    u8 pad1a[0x24 - 0x1A];
    Wk_8004DE48* work;
} Node_8004DE48;
extern f32 fn_80071E9C(void*, Vec_8004A40C*);
extern void fn_80032FC4(Vec_8004A40C*, Vec_8004A40C*, void*, void*);
void fn_80049130(Node_80049130* node);
void fn_8004DE48(Node_8004DE48* node);
void fn_8004F84C(NJS_VECTOR* v);
void fn_80040044(DrawState* o, f32 f, u32 flags, u8* out);
void fn_800400D8(u32 flags, TaskRef* t, u32 idx, void** out);
void fn_80040150(u32 flags, TaskRef* t, u32 idx, void** out);

void fn_8004DE48(Node_8004DE48* node) {
    Wk_8004DE48* w = node->work;
    Sub_8004DE48* s = w->sub;
    Unit_8004DE48* u = s->tgt->work->w;
    u8 kind;
    int r;
    f32 d;
    Col4_8004DE48 ca;
    Col4_8004DE48 cb;
    Vec_8004A40C b;
    Vec_8004A40C a;
    DrawState st;

    switch (node->state) {
    case 0:
        node->state = 1;
    case 1:
        fn_80040150(2, (TaskRef*)s->tgt, s->c->id, (void**)&s->src);
        node->state = 2;
        break;
    case 2:
        if (s->timer < s->c->start) {
            break;
        }
        node->state = 3;
        if (s->src != NULL) {
            s->mtx = fn_801E1C7C(0x40);
            if (s->mtx != NULL) {
                memcpy(s->mtx, s->src, 0x40);
            }
        }
        w->ang[0] = 182.04445f * s->c->rot[0];
        w->ang[1] = 182.04445f * s->c->rot[1];
        w->ang[2] = 182.04445f * s->c->rot[2];
        w->scl.x = 1.0f;
        w->scl.y = 1.0f;
        w->scl.z = 1.0f;
        fn_80071CF0(&s->c->pos, &w->pos);
        fn_8006CEEC(w->src->x8, &w->motion, 0, w->x16);
    case 3: case 4: case 5: case 6:
        if (s->timer == s->c->end) {
            u->xec |= 0x20000000;
        }
        switch (s->c->fx) {
        case 1:
            u->x1ec |= 0x80000000;
            break;
        case 2:
            u->x1ec |= 0x40000000;
            break;
        }
        if (w->motion != NULL) {
            s->frame += 1.0f;
            if (s->frame >= (f32)w->motion->nbFrame - 1.0f) {
                s->frame = 0.0f;
            }
        }
        switch (node->state) {
        case 3:
            w->pos.x += s->c->vel.x;
            w->pos.y += s->c->vel.y;
            w->pos.z += s->c->vel.z;
            break;
        case 4:
            w->pos.x -= s->c->vel.x;
            w->pos.y -= s->c->vel.y;
            w->pos.z -= s->c->vel.z;
            s->x14--;
            if (s->x14 <= 1) {
                u->xec &= ~0x20000000;
                node->state = 6;
            }
            break;
        case 5:
            if (s->c->rotStart == s->c->rotEnd || (s->c->rotEnd > s->timer && s->c->rotStart <= s->timer)) {
                w->ang[0] += (s32)(182.04445f * s->c->rotVel[0]);
                w->ang[1] += (s32)(182.04445f * s->c->rotVel[1]);
                w->ang[2] += (s32)(182.04445f * s->c->rotVel[2]);
            }
            s->x16--;
            if (s->x16 <= 0) {
                if (s->timer >= s->c->end) {
                    node->state = 4;
                } else {
                    s->x16 = 0;
                }
            }
            break;
        case 6:
            node->state = 7;
            switch (s->c->fx) {
            case 1:
                u->x1ec &= 0x7FFFFFFF;
                break;
            case 2:
                u->x1ec &= ~0x40000000;
                break;
            }
            break;
        }
        DrawStateDefault2D(&st);
        kind = w->kind;
        fn_80040044(&st, 1.0f, s->c->flags, &w->kind);
        if (DrawStatePush(&st) != 0) {
            fn_80299040(w->texlist);
            fn_80034E6C(w, -1, s->mtx, w->motion, s->frame);
            DrawStatePop(NULL);
        }
        w->kind = kind;
        if (node->state == 3) {
            fn_8001DF44(s->tgt, &a);
            fn_80061518(&w->pos, &b, s->mtx);
            r = fn_80018398(&b, 0);
            d = fn_80071E9C(&s->tgt->work->pos, &a);
            b.y = 0.0f;
            if (d < fn_80071E9C(&s->tgt->work->pos, &b) || (s8)r == u->x4) {
                s->x16 = 30;
                node->state = 5;
            }
            s->x14++;
        }
        fn_80061518(&w->pos, &b, s->mtx);
        fn_80061518(&s->c->pos, &a, s->src);
        ca.a = 0xFF;
        ca.b = 0;
        ca.c = 0;
        ca.d = 0;
        cb.a = 0;
        cb.b = 0;
        cb.c = 0;
        cb.d = 0;
        fn_80032FC4(&b, &a, &ca, &cb);
        if (s->c->interval != 0 && s->count % s->c->interval == 0) {
            fn_80049130((Node_80049130*)node);
        }
        s->count++;
        break;
    case 7:
        if (s->mtx != NULL) {
            fn_801E17E0(s->mtx);
        }
        fn_800400D8(2, (TaskRef*)s->tgt, s->c->id, (void**)&s->src);
        fn_801E17E0(s);
        node->flags |= 0x40;
        lbl_8030A10C.count--;
        return;
    }
    s->timer++;
}

typedef struct {
    u8 pad0[6];
    s16 x6;                 /* 0x06 */
    u8 pad8[0x10 - 8];
    s16 x10;                /* 0x10 */
    u8 pad12[0x14 - 0x12];
    u32 x14;                /* 0x14 */
    f32 x18;                /* 0x18 */
} Params_8004E474;
typedef struct {
    u16 cnt;                /* 0x00 */
    u8 pad2[2];
    Tgt_8004DE48* task;     /* 0x04 */
    s8 slot[14];            /* 0x08 */
    s16 x16;                /* 0x16 */
    s16 x18;                /* 0x18 */
    u8 pad1a[2];
    Vec v;                  /* 0x1C */
    f32 x28;                /* 0x28 */
    Params_8004E474* params; /* 0x2C */
} Work_8004E474;
typedef struct {
    u8 pad0[0x18];
    u8 flags;
    u8 state;
    u8 pad1a[0x24 - 0x1A];
    Work_8004E474* work;
} Node_8004E474;
extern Tgt_8004DE48* lbl_80309E24[12];
extern Vec_8004A40C lbl_802AD3A8;
extern void fn_80020B50(void*, s16*, s16*);
extern void fn_80020B8C(void*, s16, s16, int);
extern int fn_80018498(Vec*);
extern int fn_8001D944(s8, void*);
extern void fn_8001D14C(void*);

void fn_8004F84C(NJS_VECTOR* v) {
    v->x = -1.16f;
    v->y = -0.23f;
    v->z = -0.71f;
}

void fn_8004F664(f32 *base, f32 *out1, f32 *out2, f32 *src, s16 div, s8 mode) {
    f32 *p;
    s8 i;

    if (base != 0) {
        switch (mode) {
        case 0:
        default:
            p = base + 15;
            break;
        case 1:
            p = base + 12;
            break;
        case 2:
            p = base + 3;
            break;
        case 4:
            p = out2;
            break;
        }
    }
    if (base != 0) {
        for (i = 0; i < 3; i++) {
            out1[i] = (src[i] - p[i]) / (f32)div;
            if (mode < 3) {
                out2[i] = p[i];
            } else {
                out2[i] += out1[i];
            }
        }
    } else {
        for (i = 0; i < 3; i++) {
            *out1 = *src++ / (f32)div;
            if (mode < 3) {
                *out2 = *out1;
            } else {
                *out2 += *out1;
            }
            out1++;
            out2++;
        }
    }
}
