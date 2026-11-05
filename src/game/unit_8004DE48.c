#include "types.h"
/* Effect task handlers from 0x8004DE48 (a new .sdata2 block at 0x80348700: second 182.04445f, 1.0f
 * and 0.0f): the model effect fn_8004DE48, the area-of-effect pulse fn_8004E474 and the strip helpers. */
#include "ninja.h"
#include "game/drawstate.h"
#include "game/effect.h"

typedef NJS_POINT3 Vec;
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
extern ObjStats lbl_8030A10C;
extern void* fn_801E1C7C(u32);
extern void fn_801E17E0(void*);
extern void fn_8001DF44(void*, Vec*);
extern void fn_80061518(void*, Vec*, void*);
extern void fn_80071CF0(Vec*, Vec*);
extern int fn_8006CEEC(void*, void*, s16, int);
extern void fn_80034E6C(void* o, s16 idx, void* m, void* a, f32 f);
extern void* memcpy(void*, const void*, unsigned long);


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
    u32 xf0;                /* 0x0F0 */
    u8 padf4[0x164 - 0xF4];
    f32 x164;               /* 0x164 */
    u8 pad168[0x1EC - 0x168];
    u32 x1ec;               /* 0x1EC */
    u8 pad1f0[0x208 - 0x1F0];
    f32 x208;               /* 0x208 */
} Unit_8004DE48;
typedef struct { u8 pad0[0x1C]; Vec_8004A40C pos; u8 pad28[0x3C - 0x28]; u32 x3c; u8 pad40[0x4C - 0x40]; Unit_8004DE48* w; } TWk_8004DE48;
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
extern Tgt_8004DE48* lbl_80309E24[14];
extern Vec_8004A40C lbl_802AD3A8;
extern void fn_80020B50(void*, s16*, s16*);
extern void fn_80020B8C(void*, s16, s16, int);
extern int fn_80018498(Vec*);
extern int fn_8001D944(s8, void*);
extern void fn_8001D14C(void*);

typedef struct {
    u8 pad[0x18];
    u8 flags;
    u8 state;
    u8 pad1a[0x24 - 0x1A];
    Work_8004E474* work;
} Node_8004E474;

void fn_8004E474(Node_8004E474* node)
{
    Tgt_8004DE48* t;
    Work_8004E474* w;
    Unit_8004DE48* c;
    s8 b;
    s16 i;
    s16 k;

    w = node->work;
    c = w->task->work->w;
    switch (node->state) {
    case 0:
        c->xec |= 0x80000;
        c->xec |= 0x40000;
        fn_80020B50(w->task, &w->x16, &w->x18);
        for (i = 0; i < 14; i++) {
            w->slot[i] = -1;
        }
        node->state = 1;
    case 1:
        if (w->cnt < w->params->x10) {
            break;
        }
        if (!w->params->x18) {
            w->x28 = 202.5f;
        }
        node->state = 2;
    case 2:
        w->x28 = w->x28 + w->params->x18;
        w->v.x = w->x28;
        if (fn_80018498(&w->v) == 0) {
            w->x28 *= 1.5f;
            node->state = 0xFA;
        }
        for (i = 0; i < 12; i++) {
            t = lbl_80309E24[i];
            if (t != 0) {
                Vec v = lbl_802AD3A8;
                Unit_8004DE48* c2 = t->work->w;
                if (fn_8001D944(c2->id, w->task) != 0) {
                    if (fn_80071E9C(&v, &t->work->pos) < w->x28) {
                        for (k = 0; k < 12; k++) {
                            b = w->slot[k];
                            if (b < 0) {
                                w->slot[k] = c2->id;
                                c->x5a = c2->id;
                                c->xec |= 0x80;
                                fn_80020B8C(w->task, w->x16, w->x18,
                                            (w->params->x14 >> 31) ^ 1);
                                c->xec &= ~0x80;
                                break;
                            } else if (b == c2->id) {
                                break;
                            }
                        }
                    }
                }
            }
        }
        break;
    case 3:
        if (lbl_8030A10C.flags & 0x20) {
            node->state = 1;
            w->cnt = w->params->x10;
        }
        break;
    case 0xFA:
        fn_8001D14C(c);
        node->flags |= 0x40;
        lbl_8030A10C.count--;
        return;
    }
    w->cnt++;
    if (w->params->x6 & 0x2000) {
        switch (node->state) {
        case 1:
            break;
        default:
            lbl_8030A10C.flags |= 0x10;
            break;
        }
        if (lbl_8030A10C.flags & 0x80) {
            if (!(lbl_8030A10C.flags & 0x20)) {
                switch (node->state) {
                case 1:
                    node->state = 3;
                    break;
                default:
                    break;
                }
            }
        }
    }
}

extern f32 njSin(int);
typedef struct {
    u8 pad0[0x0C];
    Vec v0c;                /* 0x0C */
    u8 pad18[0x30 - 0x18];
    Vec v30;                /* 0x30 */
    Vec v3c;                /* 0x3C */
} Q_8004EEF0;
typedef struct {
    u8 pad0[0x14];
    s16 x14;                /* 0x14 */
    s16 x16;                /* 0x16 */
    s16 x18;                /* 0x18 */
    s16 x1a;                /* 0x1A */
    s16 x1c;                /* 0x1C */
    u8 pad1e[2];
    Vec v20;                /* 0x20 */
    Vec v2c;                /* 0x2C */
    s16 x38;                /* 0x38 */
    s16 x3a;                /* 0x3A */
    f32 x3c;                /* 0x3C */
    s16 x40;                /* 0x40 */
    s16 x42;                /* 0x42 */
    s16 x44;                /* 0x44 */
} Params_8004EEF0;
typedef struct {
    u8 kind;                /* 0x00 */
    u8 pad1[3];
    u32 flags;              /* 0x04 */
    s16 id;                 /* 0x08 */
    u8 pad0a[2];
    Vec pos;                /* 0x0C */
    u8 pad18[0x30 - 0x18];
    Vec a;                  /* 0x30 */
    Vec b;                  /* 0x3C */
    f32 s0;                 /* 0x48 */
    f32 s1;                 /* 0x4C */
    u8 pad50[0x64 - 0x50];
} Sub_8004EEF0;
typedef struct {
    s16 x0;                 /* 0x00 */
    s16 x2;                 /* 0x02 */
    u8 pad4[4];
    Vec vel[3];             /* 0x08 */
    Vec pos[3];             /* 0x2C */
    Vec v50;                /* 0x50 */
    Vec v5c;                /* 0x5C */
    Vec v68;                /* 0x68 */
    Vec e;                  /* 0x74 */
    Sub_8004EEF0 sub;       /* 0x80 */
    s32 xe4;                /* 0xE4 */
    s32 xe8;                /* 0xE8 */
    Params_8004EEF0* p;     /* 0xEC */
} Work_8004EEF0;
typedef struct {
    u8 pad[0x18];
    u8 flags;
    u8 state;
    u8 pad1a[0x24 - 0x1A];
    Work_8004EEF0* work;
} Node_8004EEF0;
typedef struct { u8 pad[8]; u32 x8; } Misc_8004EEF0;
extern Misc_8004EEF0 lbl_80309E5C;
extern int fn_8006B6C8(s16);
extern Q_8004EEF0* fn_8006B6F4(s16);
extern int fn_8006B670(s16);
extern void fn_8006B6A4(s16, int);
extern void fn_8006BD84(s16, Sub_8004EEF0*, void*);
extern void fn_8006B8A8(Sub_8004EEF0*);
extern void fn_8004F664(Q_8004EEF0*, f32*, f32*, f32*, s16, s8);

void fn_8004EEF0(Node_8004EEF0* node)
{
    Work_8004EEF0* w = node->work;
    s16 idx = w->p->x1c;
    Q_8004EEF0* q;

    switch (node->state) {
    case 0:
        fn_8006D954(1);
        node->state = 1;
    case 1:
        if (w->x0 < w->p->x14) {
            break;
        }
        if (idx == 0) {
            w->xe8 = fn_8006B6C8(idx);
            switch (w->xe8) {
            case 1:
                w->xe8 = 0;
                break;
            default:
                break;
            }
            q = fn_8006B6F4(idx);
            fn_80071CF0(&q->v3c, &w->v5c);
            fn_80071CF0(&q->v30, &w->v50);
            fn_80071CF0(&q->v0c, &w->v68);
            w->e.x = -1.16f;
            w->e.y = -0.23f;
            w->e.z = -0.71f;
            lbl_80309E5C.x8 |= 0x2000000;
        }
        if (fn_8006B670(idx) == 0) {
            if (idx == 0) {
                w->xe4 = 1;
                fn_8006B6A4(idx, 1);
                q = fn_8006B6F4(idx);
                if (w->p->x18 != 0) {
                    fn_8004F664(q, &w->vel[1].x, &w->pos[1].x, &w->p->v2c.x, w->p->x18, 0);
                    fn_8004F664(q, &w->vel[0].x, &w->pos[0].x, &w->p->v20.x, w->p->x18, 1);
                    fn_8004F664(q, &w->vel[2].x, &w->pos[2].x, &w->e.x, w->p->x18, 2);
                } else {
                    w->pos[0].x = w->p->v20.x;
                    w->pos[1].x = w->p->v2c.x;
                    w->pos[2].x = w->e.x;
                    w->pos[0].y = w->p->v20.y;
                    w->pos[1].y = w->p->v2c.y;
                    w->pos[2].y = w->e.y;
                    w->pos[0].z = w->p->v20.z;
                    w->pos[1].z = w->p->v2c.z;
                    w->pos[2].z = w->e.z;
                }
            } else {
                node->state = 0xFA;
                return;
            }
        } else {
            w->xe4 = 0;
            fn_8006BD84(idx, &w->sub, node);
            if (w->p->x18 != 0) {
                fn_8004F664(0, &w->vel[1].x, &w->pos[1].x, &w->p->v2c.x, w->p->x18, 0);
                fn_8004F664(0, &w->vel[0].x, &w->pos[0].x, &w->p->v20.x, w->p->x18, 1);
                fn_8004F664(0, &w->vel[2].x, &w->pos[2].x, &w->e.x, w->p->x18, 2);
            } else {
                w->pos[0].x = w->p->v20.x;
                w->pos[1].x = w->p->v2c.x;
                w->pos[2].x = w->e.x;
                w->pos[0].y = w->p->v20.y;
                w->pos[1].y = w->p->v2c.y;
                w->pos[2].y = w->e.y;
                w->pos[0].z = w->p->v20.z;
                w->pos[1].z = w->p->v2c.z;
                w->pos[2].z = w->e.z;
            }
        }
        node->state = 3;
        break;
    case 3:
        if (w->x0 < w->p->x14 + w->p->x18) {
            w->pos[0].x += w->vel[0].x;
            w->pos[1].x += w->vel[1].x;
            w->pos[2].x += w->vel[2].x;
            w->pos[0].y += w->vel[0].y;
            w->pos[1].y += w->vel[1].y;
            w->pos[2].y += w->vel[2].y;
            w->pos[0].z += w->vel[0].z;
            w->pos[1].z += w->vel[1].z;
            w->pos[2].z += w->vel[2].z;
        }
        if (w->x0 >= w->p->x16 + w->p->x1a) {
            node->state = 0xFA;
        } else if (w->x0 == w->p->x16) {
            if (w->p->x1a != 0) {
                q = fn_8006B6F4(idx);
                if (fn_8006B670(idx) == 0) {
                    fn_8004F664(q, &w->vel[1].x, &w->pos[1].x, &w->v5c.x, w->p->x1a, 4);
                    fn_8004F664(q, &w->vel[0].x, &w->pos[0].x, &w->v50.x, w->p->x1a, 4);
                    fn_8004F664(q, &w->vel[2].x, &w->pos[2].x, &w->v68.x, w->p->x1a, 4);
                } else {
                    fn_8004F664(0, &w->vel[1].x, &w->pos[1].x, &w->p->v2c.x, w->p->x1a, 4);
                    fn_8004F664(0, &w->vel[0].x, &w->pos[0].x, &w->p->v20.x, w->p->x1a, 4);
                    fn_8004F664(0, &w->vel[2].x, &w->pos[2].x, &w->e.x, w->p->x1a, 4);
                }
            } else {
                node->state = 0xFA;
            }
        } else if (w->x0 > w->p->x16) {
            w->pos[0].x += w->vel[0].x;
            w->pos[1].x += w->vel[1].x;
            w->pos[2].x += w->vel[2].x;
            w->pos[0].y += w->vel[0].y;
            w->pos[1].y += w->vel[1].y;
            w->pos[2].y += w->vel[2].y;
            w->pos[0].z += w->vel[0].z;
            w->pos[1].z += w->vel[1].z;
            w->pos[2].z += w->vel[2].z;
        }
        w->sub.flags = 0;
        w->sub.kind = 4;
        w->sub.id = w->p->x1c;
        fn_80071CF0(&w->pos[1], &w->sub.b);
        fn_80071CF0(&w->pos[0], &w->sub.a);
        fn_80071CF0(&w->pos[2], &w->sub.pos);
        if (w->p->x44 != 0) {
            if (w->x2 % w->p->x44 == 0) {
                w->sub.flags |= 0x40000000;
            }
        } else {
            w->sub.flags |= 0x40000000;
        }
        if (w->x0 < w->p->x16 && w->x0 >= w->p->x38 && w->x0 < w->p->x3a) {
            f32 s = njSin((int)(182.04445f * (f32)(w->p->x42 + w->x2 * w->p->x40)));
            f32 d = w->p->x3c * s;
            w->sub.b.x += d;
            w->sub.b.y += d;
            w->sub.b.z += d;
            w->sub.a.x += d;
            w->sub.a.y += d;
            w->sub.a.z += d;
        }
        fn_8006B8A8(&w->sub);
        w->x2++;
        break;
    case 4:
    case 0xF9:
    case 0xFA:
        fn_8006D8DC(1);
        if (idx == 0) {
            lbl_80309E5C.x8 &= ~0x2000000;
        }
        if (w->xe4 != 0) {
            fn_8006B6A4(idx, w->xe8);
        }
        node->flags |= 0x40;
        lbl_8030A10C.count--;
        return;
    }
    fn_80037FD8(w->p, &node->state);
    w->x0++;
}

void fn_8004F84C(NJS_VECTOR* v) {
    v->x = -1.16f;
    v->y = -0.23f;
    v->z = -0.71f;
}

void fn_8004F664(Q_8004EEF0 *base, f32 *out1, f32 *out2, f32 *src, s16 div, s8 mode) {
    f32 *p;
    s8 i;

    if (base != 0) {
        switch (mode) {
        case 0:
        default:
            p = &base->v3c.x;
            break;
        case 1:
            p = &base->v30.x;
            break;
        case 2:
            p = &base->v0c.x;
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

typedef struct {
    u8 pad0[0x10];
    u32 type;           /* 0x10 */
    s16 start;          /* 0x14 */
    s16 end;            /* 0x16 */
    s16 len;            /* 0x18 */
    s16 endLen;         /* 0x1A */
    s16 x1c;            /* 0x1C */
    u8 pad1e[2];
    Vec pos;            /* 0x20 */
    s16 id;             /* 0x2C */
    u8 pad2e[2];
    Vec v30;            /* 0x30 */
    f32 x3c;            /* 0x3C */
    f32 x40;            /* 0x40 */
    s16 s44;            /* 0x44 */
    s16 s46;            /* 0x46 */
    f32 f48;            /* 0x48 */
    s16 s4c;            /* 0x4C */
    s16 s4e;            /* 0x4E */
    s16 s50;            /* 0x50 */
    s16 s52;            /* 0x52 */
    f32 f54;            /* 0x54 */
    s16 s58;            /* 0x58 */
    s16 s5a;            /* 0x5A */
    s16 s5c;            /* 0x5C */
    u8 pad5e[2];
    f32 f60;            /* 0x60 */
    s16 s64;            /* 0x64 */
    s16 s66;            /* 0x66 */
    f32 f68;            /* 0x68 */
    s16 s6c;            /* 0x6C */
    s16 s6e;            /* 0x6E */
} Cmd_8004F868;
typedef struct {
    s16 frame;          /* 0x00 */
    s16 count;          /* 0x02 */
    TaskRef* arg;       /* 0x04 */
    void* mtx;          /* 0x08 */
    u8 pad0c[4];
    Vec step;           /* 0x10 */
    Vec pos;            /* 0x1C */
    Vec ofs;            /* 0x28 */
    f32 x34;            /* 0x34 */
    f32 x38;            /* 0x38 */
    Sub_8004EEF0 sub;   /* 0x3C */
    u8 padA0[8];
    Cmd_8004F868* cmd;  /* 0xA8 */
} Work_8004F868;
typedef struct {
    u8 pad[0x18];
    u8 flags;
    u8 state;
    u8 pad1a[0x24 - 0x1A];
    Work_8004F868* work;
} Node_8004F868;
extern void fn_8001E238(Vec*, Vec*, void*);
extern void fn_8006B5B8(void*);
void fn_8004F868(Node_8004F868* node) {
    Work_8004F868* w = node->work;
    s16 id = w->cmd->id;
    s16 i;

    switch (node->state) {
    case 0:
        if (w->frame < w->cmd->start) {
            break;
        }
        if (fn_8006B670(id) == 0) {
            node->state = 3;
            break;
        }
        fn_8006BD84(id, &w->sub, node);
        fn_80040150(w->cmd->type, w->arg, w->cmd->x1c, &w->mtx);
        for (i = 0; i < 3; i++) {
            if (w->cmd->len != 0) {
                (&w->step.x)[i] = (&w->cmd->v30.x)[i] / (f32)w->cmd->len;
                (&w->ofs.x)[i] = (&w->step.x)[i];
            } else {
                (&w->ofs.x)[i] = (&w->cmd->v30.x)[i];
            }
        }
        w->x34 = w->cmd->x3c;
        w->x38 = w->cmd->x40;
        node->state = 2;
        break;
    case 1:
        break;
    case 2:
        if (w->frame < w->cmd->start + w->cmd->len) {
            w->ofs.x += w->step.x;
            w->ofs.y += w->step.y;
            w->ofs.z += w->step.z;
        }
        if (w->frame >= w->cmd->end + w->cmd->endLen) {
            node->state = 0xFA;
        } else if (w->frame == w->cmd->end) {
            if (w->cmd->endLen != 0) {
                w->step.x = w->cmd->v30.x / (f32)w->cmd->endLen;
                w->ofs.x -= w->step.x;
                w->step.y = w->cmd->v30.y / (f32)w->cmd->endLen;
                w->ofs.y -= w->step.y;
                w->step.z = w->cmd->v30.z / (f32)w->cmd->endLen;
                w->ofs.z -= w->step.z;
            } else {
                node->state = 0xFA;
            }
        } else if (w->frame > w->cmd->end) {
            w->ofs.x -= w->step.x;
            w->ofs.y -= w->step.y;
            w->ofs.z -= w->step.z;
        }
        if (w->mtx == 0) {
            switch (w->cmd->type & 0xF) {
            case 3:
                fn_8001E238(&w->cmd->pos, &w->pos, w->arg);
                break;
            case 0:
                fn_8001E4A0(&w->cmd->pos, &w->pos, w->arg);
                break;
            case 1:
                fn_80071CF0(&w->cmd->pos, &w->pos);
                break;
            case 2:
                break;
            }
        } else {
            fn_80061518(&w->cmd->pos, &w->pos, w->mtx);
        }
        memset(&w->sub, 0, 0x64);
        w->sub.kind = 4;
        w->sub.id = w->cmd->id;
        fn_80071CF0(&w->pos, &w->sub.pos);
        fn_80071CF0(&w->ofs, &w->sub.a);
        w->sub.s0 = w->cmd->x3c;
        w->sub.s1 = w->cmd->x40;
        {
            s16 t = w->cmd->s5c;
            if (t != 0) {
                if (w->count % t == 0) {
                    w->sub.flags |= 0x40000000;
                }
            } else {
                w->sub.flags |= 0x40000000;
            }
        }
        {
            Cmd_8004F868* c = w->cmd;
            if (w->frame >= c->s50 && w->frame < c->s52) {
                f32 s = njSin((int)(182.04445f * (f32)(c->s5a + w->count * c->s58)));
                s = w->cmd->f54 * s;
                w->sub.s0 += s;
                w->sub.s1 += s;
            }
        }
        if (w->frame >= w->cmd->s64 && w->frame < w->cmd->s66) {
            w->sub.s0 += w->cmd->f60 * (f32)(w->frame - w->cmd->s64);
        } else if (w->frame >= w->cmd->s66) {
            w->sub.s0 += w->cmd->f60 * (f32)(w->cmd->s66 - w->cmd->s64);
        }
        if (w->frame >= w->cmd->s6c && w->frame < w->cmd->s6e) {
            w->sub.s1 += w->cmd->f68 * (f32)(w->frame - w->cmd->s6c);
        } else if (w->frame >= w->cmd->s6e) {
            w->sub.s1 += w->cmd->f68 * (f32)(w->cmd->s6e - w->cmd->s6c);
        }
        {
            Cmd_8004F868* c = w->cmd;
            if (w->frame >= c->s44 && w->frame < c->s46) {
                f32 s = njSin((int)(182.04445f * (f32)(c->s4e + w->count * c->s4c)));
                s = w->cmd->f48 * s;
                w->sub.a.x += s;
                w->sub.a.y += s;
                w->sub.a.z += s;
            }
        }
        fn_8006B8A8(&w->sub);
        w->count++;
        break;
    case 0xF9:
    case 0xFA:
        memset(&w->sub, 0, 0x64);
        w->sub.id = w->cmd->id;
        w->sub.kind = 4;
        fn_8006B8A8(&w->sub);
        fn_8006B5B8(node);
        node->state = 3;
        break;
    case 3:
    case 0xF8:
        fn_800400D8(w->cmd->type, w->arg, w->cmd->x1c, &w->mtx);
        node->flags |= 0x40;
        lbl_8030A10C.count--;
        return;
    }
    w->frame++;
    switch (node->state) {
    case 3:
        break;
    case 0:
        if (fn_80037FD8(w->cmd, &node->state) != 0) {
            node->state = 0xF8;
        }
        break;
    default:
        fn_80037FD8(w->cmd, &node->state);
        break;
    }
}
