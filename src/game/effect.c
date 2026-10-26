/* Effect and particle task handlers (0x80040010 - 0x80041238): blend-mode and object-flag
 * helpers, matrix create/free helpers for effect tasks, the animation-table picker
 * (fn_800403AC), and the per-effect task handlers (ring spawner fn_800405EC, emitter fn_80040AA0
 * and its particle fn_80040DC4). Each handler switches on node->state (0 init, 1 wait, 0xF9/0xFA
 * free) and uses a work area whose layout is named <Type>_<handler address> when it is private. */
#include "types.h"
#include "ninja.h"
#include "game/drawstate.h"

typedef struct { f32 x, y, z; } Vec;

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
    u8 pad[0x18];
    u8 flags;
    u8 state;
    u8 pad1a[0x24 - 0x1A];
    void* work;
} Node;

typedef struct {
    u8 pad[0x1C4];
    s32 count;
} ObjStats;

/* Animation table entry (fn_800403AC). */
typedef struct {
    s16 id;
    s16 weight;
} AnimEnt;

typedef struct {
    u32 x0;
    u32 x4;
    u32 x8;
    f32 xc;
} Obj_80040044;

typedef struct {
    s16 x0;
    s16 x2;
    s16 x4;
    u8 pad6[0xE];
    f32 x14, x18, x1c;
    u8 pad20[0xC];
    f32 x2c, x30;
    u8 pad34[0xC];
    u32 x40;
    u8 pad44[5];
    u8 x49;
    u8 pad4a[0x1F0 - 0x4A];
} Data_80040508;
typedef struct {
    u8 pad[0x4C];
    Data_80040508* data;
    u8 pad50[8];
} Work_80040508;

/* Ring spawner (fn_800405EC). */
typedef struct {
    u8 pad0[0x6];
    s16 flags;          /* 0x06 */
    s32 src;            /* 0x08 */
    u8 pad0c[0x4];
    u32 type;           /* 0x10 */
    u8 pad14[0x4];
    s16 fade;           /* 0x18 */
    u8 pad1a[0x2];
    Vec ofs;            /* 0x1C */
    s16 id;             /* 0x28 */
    u8 pad2a[0x4];
    s16 num;            /* 0x2E */
    f32 height;         /* 0x30 */
    f32 angStep;        /* 0x34 */
    f32 heightAcc;      /* 0x38 */
    f32 scale;          /* 0x3C */
    f32 scaleStep;      /* 0x40 */
    f32 radius;         /* 0x44 */
    f32 radiusStep;     /* 0x48 */
    Vec rotDeg;         /* 0x4C */
    AnimEnt anim[0x40]; /* 0x58 */
    s16 animA;          /* 0x158 */
    s16 animB;          /* 0x15A */
} Cmd;

typedef struct {
    s16 start;          /* 0x00 */
    s16 end;            /* 0x02 */
    s16 timer;          /* 0x04 */
    s16 count;          /* 0x06 */
    TaskRef* arg;       /* 0x08 */
    void* mtx;          /* 0x0C */
    f32 ang;            /* 0x10 */
    u8 alpha;           /* 0x14 */
    u8 alphaStep;       /* 0x15 */
    s16 frame;          /* 0x16 */
    f32 height;         /* 0x18 */
    s32 rot[3];         /* 0x1C */
    Cmd c;              /* 0x28 */
} Sub_800405EC;

typedef struct {
    u8 pad0[0x8];
    s32 x8;             /* 0x08 */
    u8 pad0c[0x4C - 0xC];
    Sub_800405EC* sub;  /* 0x4C */
    s32 x50;
    s32 x54;
} Work_800405EC;

typedef struct {
    s32 unk0;
    Vec pos;            /* 0x04 */
    Vec vec;            /* 0x10 */
    u8 pad1C[0xC];
    f32 sx;             /* 0x28 */
    f32 sy;             /* 0x2C */
    s32 unk30;
    s16 frame;          /* 0x34 */
    u8 pad36[2];
    s32 unk38;          /* 0x38 */
    u8 col[4][4];       /* 0x3C */
    s32 unk4C;
} Quad; /* 0x50 */

/* Emitter (fn_80040AA0) and its particles (fn_80040DC4). */
typedef struct {
    u8 pad0[0x6];
    s16 flags;      /* 0x06 */
    s32 src;        /* 0x08 */
    u8 pad0c[0x4];
    u32 type;       /* 0x10 */
    s16 start;      /* 0x14 */
    s16 end;        /* 0x16 */
    s16 len;        /* 0x18 */
    s16 fadeIn;     /* 0x1A */
    s16 fadeOut;    /* 0x1C */
    s16 id;         /* 0x1E */
    u8 x20[0xC];    /* 0x20 */
    f32 scale;      /* 0x2C */
    f32 sizeStep;   /* 0x30 */
    s16 sizeStart;  /* 0x34 */
    u8 pad36[2];
    f32 sizeMax;    /* 0x38 */
    f32 size;       /* 0x3C */
    s16 moveStart;  /* 0x40 */
    s16 moveEnd;    /* 0x42 */
    s16 interval;   /* 0x44 */
    AnimEnt anim[0x40]; /* 0x46 */
    s16 animA;      /* 0x146 */
    s16 animB;      /* 0x148 */
} Obj;

typedef struct {
    s16 timer;      /* 0x00 */
    s16 count;      /* 0x02 */
    void* mtx;      /* 0x04 */
    TaskRef* arg;   /* 0x08 */
    f32 alpha;      /* 0x0C */
    s16 frame;      /* 0x10 */
    u8 pad12[2];
    f32 size;       /* 0x14 */
    Vec pos;        /* 0x18 */
    Vec vel;        /* 0x24 */
    s16 life;       /* 0x30 */
    u8 pad32[2];
    Obj* owner;     /* 0x34 */
} Sub;

typedef struct { u8 d[0x4C]; } Buf;

typedef struct {
    u8 pad0[0x1C];
    Vec pos;        /* 0x1C */
    u8 pad28[0x34 - 0x28];
    f32 size;       /* 0x34 */
    u8 pad38[0x4C - 0x38];
    Sub* sub;       /* 0x4C */
    s32 x50;
    s32 x54;
} Work;

extern ObjStats lbl_8030A10C;
extern void* memset(void*, int, unsigned long);
extern void fn_8006D954(s32);
extern void fn_8006D8DC(s32);
extern void fn_8007638C(void*, void*, u16);
extern void fn_80076478(void*, void*, u16, int);
extern void* fn_801E1C7C(u32);
extern void fn_801E17E0(void*);
extern void njTranslateV(void*, Vec*);
extern void njRotateY(void*, s32);
extern void fn_8001D200(TaskRef*, Vec*);
extern void fn_8001DF44(TaskRef*, Vec*);
extern void fn_80012130(Vec*);
extern void fn_80032E78(int flag, Work* w, s16 frame, f32 alpha, int a, int b, int mode);
extern void fn_80033A18(Quad*, s32, s32, s32);
extern int fn_80037FD8(void* e, u8* out);
extern Node* fn_8003DB34(void* fn);
extern void fn_80043730(void);
extern void fn_80061014(Vec*, Vec*, Vec*);
extern void fn_80061518(void*, Vec*, void*);
extern void fn_80061E34(Vec* out, s32* rot, f32 ang, f32 radius, f32 height);
extern void fn_80061F58(void*, int, int);
extern void fn_80071CF0(Vec*, Vec*);
extern void fn_80072130(Vec*);
extern int fn_8007E264(f32* out, f32 x, f32 z);
extern int fn_8025ECC4(void);
void fn_80040DC4(Node* node);

s32 fn_80040010(u32 flags) {
    if (flags & 0x80) {
        return 1;
    }
    if (flags & 0x40) {
        return 2;
    }
    return (flags & 0x10) ? 3 : 0;
}

void fn_80040044(Obj_80040044* o, u32 flags, u8* out, f32 f) {
    o->x0 |= 0x800;
    o->xc = f;
    if (f != 0.0f) {
        o->x8 = 0x800;
    }
    o->x4 &= ~0x200;
    o->x0 &= ~0x100;
    if (flags & 0x800000) {
        *out = 2;
        o->x8 |= 0x300;
    }
    if (flags & 0x1000000) {
        o->x4 &= ~0x700;
        o->x8 = 0x4000;
        *out = 2;
    }
    if (flags & 0x20000000) {
        o->x8 |= 0x800;
    }
}

/* Frees a task's effect matrix; inlined into the effect handlers. */
static inline void FreeMtx(u32 flags, TaskRef* t, u32 idx, void** out)
{
    void* m = *out;
    if (m != NULL) {
        switch (flags & 0xF) {
        case 0:
        case 4:
        case 5:
            break;
        default:
            fn_8007638C(m, t->data->body->x154, idx);
            break;
        }
        fn_801E17E0(*out);
    }
}

void fn_800400D8(u32 flags, TaskRef* t, u32 idx, void** out) {
    FreeMtx(flags, t, idx, out);
}

void fn_80040150(u32 flags, TaskRef* t, u32 idx, void** out) {
    switch (flags & 0xF) {
    case 0: {
        Vec p;
        if (flags & 0x4000000) {
            break;
        }
        p.x = t->data->pos.x;
        p.y = t->data->pos.y;
        p.z = t->data->pos.z;
        *out = fn_801E1C7C(0x40);
        njUnitMatrix(*out);
        njTranslateV(*out, &p);
        njRotateY(*out, t->data->x2c);
        break;
    }
    case 2:
        *out = fn_801E1C7C(0x40);
        fn_80076478(*out, t->data->body->x154, idx, 0);
        break;
    case 4: {
        Vec v;
        Vec p;
        fn_8001D200(t, &v);
        p.x = v.x;
        p.y = v.y;
        p.z = v.z;
        *out = fn_801E1C7C(0x40);
        njUnitMatrix(*out);
        njTranslateV(*out, &p);
        njRotateY(*out, t->data->x2c);
        break;
    }
    case 5: {
        Vec v;
        Vec p;
        fn_8001D200(t, &v);
        p.x = v.x;
        p.y = t->data->pos.y;
        p.z = v.z;
        *out = fn_801E1C7C(0x40);
        njUnitMatrix(*out);
        njTranslateV(*out, &p);
        njRotateY(*out, t->data->x2c);
        break;
    }
    }
}

void fn_800402FC(void* a, u32 b, void** out) {
    if (*out != NULL) {
        fn_8007638C(*out, a, b);
        fn_801E17E0(*out);
    }
}

void fn_8004034C(void* a, u32 b, void** out) {
    *out = fn_801E1C7C(0x40);
    fn_80076478(*out, a, b, 0);
}

s16 fn_800403AC(s16 roll, AnimEnt* tbl, s16 lo, s16 hi) {
    s16 i;
    s16 j;
    s16 r;
    s16 sum;
    s16 cnt;
    if (tbl[0].weight == 0 ||
        (tbl[1].weight == 0 && tbl[0].weight == 1 && tbl[0].id == 0)) {
        return -1;
    }
    i = 0;
    sum = 0;
    cnt = 0;
    while (tbl[i].weight != 0 && i < 0x40) {
        sum += tbl[i].weight;
        if (sum > roll) {
            return tbl[i].id;
        }
        if (i >= lo && i <= hi) {
            cnt += tbl[i].weight;
        }
        i++;
    }
    if (lo >= hi) {
        return tbl[i - 1].id;
    }
    r = (s16)((s16)(roll - sum) % cnt);
    j = 0;
    while (tbl[lo].weight != 0 && lo <= hi) {
        j += tbl[lo].weight;
        if (j > r) {
            return tbl[lo].id;
        }
        lo++;
    }
    return -1;
}

void fn_80040508(Data_80040508* src, s16 div) {
    Node* t = fn_8003DB34(fn_80043730);
    Data_80040508* d;
    fn_80061F58(&t->work, 0x58, 0);
    fn_80061F58(&((Work_80040508*)t->work)->data, 0x1F0, 0);
    d = ((Work_80040508*)t->work)->data;
    *d = *src;
    d->x0 = 0;
    d->x2 = 0;
    d->x40 &= ~0x08000000;
    d->x4 = 0;
    d->x49 = 255 / div;
    d->x14 = 0.0f;
    d->x18 = 0.0f;
    d->x1c = 0.0f;
    d->x30 = 1.0f;
    d->x2c = 0.0f;
}

void fn_800405EC(Node* node)
{
    Work_800405EC* w = node->work;
    Sub_800405EC* s = w->sub;
    Vec p;
    DrawState st;
    Quad q;
    int mode;
    Vec* dst;
    s16 i;

    switch (node->state) {
    case 0:
        fn_8006D954(s->c.src);
        node->state = 1;
        ((Work_800405EC*)node->work)->x50 = s->c.src;
        ((Work_800405EC*)node->work)->x54 = -1;
    case 1:
        if (s->timer >= s->start) {
            node->state = 2;
            s->alpha = 255;
            s->alphaStep = 255 / s->c.fade;
            fn_80040150(s->c.type, s->arg, s->c.id, &s->mtx);
            s->rot[0] = 182.04445f * s->c.rotDeg.x;
            s->rot[1] = 182.04445f * s->c.rotDeg.y;
            s->rot[2] = 182.04445f * s->c.rotDeg.z;
        }
        break;
    case 2:
        if (s->end >= 0 && s->timer >= s->end) {
            node->state = 0xFA;
        } else {
            if (s->timer >= s->end - s->c.fade) {
                if (s->alpha >= s->alphaStep) {
                    s->alpha -= s->alphaStep;
                } else {
                    s->alpha = 0;
                    node->state = 0xFA;
                }
            }
            DrawStateDefault2D(&st);
            if (s->c.type & 0x20000000) {
                st.blend_src = 8;
                st.blend_dst = 10;
            }
            if (s->c.type & 0x80) {
                mode = 1;
            } else if (s->c.type & 0x40) {
                mode = 2;
            } else if (s->c.type & 0x10) {
                mode = 3;
            } else {
                mode = 0;
            }
            if (DrawStatePush(&st) != 0) {
                memset(&q, 0, sizeof(q));
                s->frame = fn_800403AC(s->count, s->c.anim, s->c.animA, s->c.animB);
                q.unk38 = 0;
                q.sx = s->c.scale;
                q.sy = s->c.scale;
                q.unk4C = w->x8;
                q.frame = s->frame;
                fn_80012130(&q.vec);
                q.col[0][0] = 255;
                q.col[0][1] = 255;
                q.col[0][2] = 255;
                q.col[0][3] = 255;
                q.col[0][0] = s->alpha;
                q.col[1][0] = 255;
                q.col[1][1] = 255;
                q.col[1][2] = 255;
                q.col[1][3] = 255;
                q.col[1][0] = s->alpha;
                q.col[2][0] = 255;
                q.col[2][1] = 255;
                q.col[2][2] = 255;
                q.col[2][3] = 255;
                q.col[2][0] = s->alpha;
                q.col[3][0] = 255;
                q.col[3][1] = 255;
                q.col[3][2] = 255;
                q.col[3][3] = 255;
                q.col[3][0] = s->alpha;
                dst = &q.pos;
                for (i = 0; i < s->c.num; i++) {
                    fn_80061E34(&p, s->rot, i * (360.0f / s->c.num) + s->ang, s->c.radius, s->height);
                    p.x += s->c.ofs.x;
                    p.y += s->c.ofs.y;
                    p.z += s->c.ofs.z;
                    switch (s->c.type & 0xF) {
                    case 1:
                        fn_80071CF0(&p, dst);
                        break;
                    default:
                        fn_80061518(&p, dst, s->mtx);
                        break;
                    }
                    fn_80033A18(&q, 0, 0, mode);
                }
                s->height += s->c.height;
                s->c.height += s->c.heightAcc;
                s->c.radius += s->c.radiusStep;
                s->c.scale += s->c.scaleStep;
                DrawStatePop(NULL);
            }
            s->ang += s->c.angStep;
        }
        s->count++;
        break;
    case 0xF9:
    case 0xFA:
        fn_8006D8DC(s->c.src);
        FreeMtx(s->c.type, s->arg, s->c.id, &s->mtx);
        fn_801E17E0(s);
        node->flags |= 0x40;
        lbl_8030A10C.count--;
        return;
    }
    s->timer++;
    fn_80037FD8(&s->c, &node->state);
}

void fn_80040AA0(Node* node)
{
    Work* w = node->work;
    Sub* s = w->sub;
    Vec a;
    Vec b;
    Vec c;
    Node* n;
    Work* w2;
    Sub* s2;

    switch (node->state) {
    case 0:
        fn_8006D954(s->owner->src);
        node->state = 1;
        ((Work*)node->work)->x50 = s->owner->src;
        ((Work*)node->work)->x54 = -1;
    case 1:
        if (s->timer >= s->owner->start) {
            node->state = 3;
            fn_80040150(s->owner->type, s->arg, s->owner->id, &s->mtx);
            s->life = s->owner->len;
        }
        break;
    case 3:
        if (s->timer >= s->owner->end + s->owner->len) {
            node->state = 0xFA;
        } else if (s->count % s->owner->interval == 0) {
            fn_80061518(s->owner->x20, &a, s->mtx);
            fn_8001DF44(s->arg, &b);
            fn_80061014(&a, &b, &c);
            fn_80072130(&c);
            n = fn_8003DB34(fn_80040DC4);
            fn_80061F58(&n->work, 0x58, 0);
            w2 = n->work;
            *(Buf*)w2 = *(Buf*)w;
            fn_80061F58(&w2->sub, 0x38, 0);
            s2 = w2->sub;
            s2->arg = s->arg;
            s2->owner = s->owner;
            fn_80071CF0(&a, &s2->pos);
            s2->vel.x = c.x * s->owner->scale;
            s2->vel.y = c.y * s->owner->scale;
            s2->vel.z = c.z * s->owner->scale;
            s2->life = s->life;
            if (s->timer >= s->owner->end) {
                s->life -= s->owner->interval;
                if (s->life < 0) {
                    node->state = 0xFA;
                }
            }
        }
        s->count++;
        break;
    case 0xF9:
    case 0xFA:
        fn_8006D8DC(s->owner->src);
        FreeMtx(s->owner->type, s->arg, s->owner->id, &s->mtx);
        fn_801E17E0(s);
        node->flags |= 0x40;
        lbl_8030A10C.count--;
        return;
    }
    s->timer++;
    fn_80037FD8(s->owner, &node->state);
}

void fn_80040DC4(Node* node)
{
    Work* w = node->work;
    Sub* s = w->sub;
    int flag;
    int mode;
    f32 h;

    switch (node->state) {
    case 0:
        fn_8006D954(s->owner->src);
        node->state = 1;
        ((Work*)node->work)->x50 = s->owner->src;
        ((Work*)node->work)->x54 = -1;
    case 1:
        if (s->owner->fadeIn != 0) {
            s->alpha = -1.0f;
        } else {
            s->alpha = 0.0f;
        }
        s->size = s->owner->size;
        if (s->owner->moveStart >= s->owner->moveEnd) {
            s->owner->moveEnd = s->owner->end;
        }
        node->state = 3;
    case 3:
    case 4:
        if (s->alpha < 0.0f && s->timer < s->life) {
            s->alpha += 1.0f / s->owner->fadeIn;
            if (s->alpha > 0.0f) {
                s->alpha = 0.0f;
            }
        }
        if (s->timer >= s->life) {
            if (s->owner->fadeOut != 0) {
                s->alpha -= 1.0f / s->owner->fadeOut;
                if (s->alpha <= -1.0f) {
                    s->alpha = -1.0f;
                    node->state = 0xFA;
                }
            } else {
                node->state = 0xFA;
            }
        }
        fn_80071CF0(&s->pos, &w->pos);
        if (s->size < s->owner->sizeMax && s->timer >= s->owner->sizeStart) {
            s->size += s->owner->sizeStep;
        }
        s->frame = fn_800403AC(s->count, s->owner->anim, s->owner->animA, s->owner->animB);
        flag = 0;
        if (s->owner->type & 0x20000000) {
            flag = 1;
        }
        if (s->frame < 0) {
            s->frame = 0;
        }
        w->size = s->size;
        if (s->owner->type & 0x80) {
            mode = 1;
        } else if (s->owner->type & 0x40) {
            mode = 2;
        } else if (s->owner->type & 0x10) {
            mode = 3;
        } else {
            mode = 0;
        }
        fn_80032E78(flag, w, s->frame, s->alpha, 0, 0, mode);
        if (s->timer >= s->owner->moveStart && s->timer < s->owner->moveEnd) {
            s->pos.x += s->vel.x;
            s->pos.y += s->vel.y;
            s->pos.z += s->vel.z;
        }
        switch (node->state) {
        case 3:
            fn_8007E264(&h, w->pos.x, w->pos.z);
            if (w->pos.y < h) {
                w->pos.y = s->size;
                s->vel.x = 0.5f * (3.0517578125e-05f * fn_8025ECC4());
                if (fn_8025ECC4() % 2) {
                    s->vel.x *= -1.0f;
                }
                s->vel.z = 0.5f * (3.0517578125e-05f * fn_8025ECC4());
                if (fn_8025ECC4() % 2) {
                    s->vel.z *= -1.0f;
                }
                s->vel.y = 0.0f;
                node->state = 4;
            }
            break;
        }
        s->count++;
        break;
    case 0xF9:
    case 0xFA:
        fn_8006D8DC(s->owner->src);
        fn_801E17E0(s);
        node->flags |= 0x40;
        lbl_8030A10C.count--;
        return;
    }
    s->timer++;
    fn_80037FD8(s->owner, &node->state);
}
