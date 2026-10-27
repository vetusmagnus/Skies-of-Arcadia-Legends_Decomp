/* Effect and particle task handlers (0x80040010 - 0x80047210): blend-mode and object-flag
 * helpers, matrix create/free helpers for effect tasks, the animation-table picker
 * (fn_800403AC), and the per-effect task handlers: ring spawner fn_800405EC, emitters and their
 * particles (fn_80040AA0/fn_80040DC4, fn_80041238/fn_80041664, fn_80041E64/fn_800422D0,
 * fn_80042B10 and the Part particles fn_8004335C/fn_80043730), the ring/column effects
 * fn_80043C24 - fn_800445D4, the model effects fn_80044B24 - fn_80045CD8 and the 2D effects
 * fn_80046704 - fn_800470F0. Each handler switches on node->state (0 init, 1 wait, 0xF9/0xFA
 * free) and uses a work area whose layout is named <Type>_<handler address> when it is private. */
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
    u8 pad[0x18];
    u8 flags;
    u8 state;
    u8 pad1a[0x24 - 0x1A];
    void* work;
} Node;

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

typedef struct { u8 pad[4]; u32 n; } TexList;

/* Animation table entry (fn_800403AC). */
typedef struct {
    s16 id;
    s16 weight;
} AnimEnt;

/* Command header shared by every effect command (fn_80037FD8). */
typedef struct {
    u8 pad0[0x6];
    s16 flags;          /* 0x06 */
    s32 src;            /* 0x08 */
    u8 pad0c[0x4];
} CmdHead;
typedef struct { u8 pad[0x18]; Vec pos; } Model;
/* Particle (fn_80043730), spawned by fn_80042B10 and fn_80040508. */
typedef struct {
    s16 timer;          /* 0x000 */
    s16 start;          /* 0x002 */
    s16 life;           /* 0x004 */
    u8 pad6[2];
    Vec pos;            /* 0x008 */
    Vec vel0;           /* 0x014 */
    Vec vel;            /* 0x020 */
    f32 gravity;        /* 0x02C */
    f32 drag;           /* 0x030 */
    f32 scale;          /* 0x034 */
    NJS_TEXLIST* texlist; /* 0x038 */
    s16 frame;          /* 0x03C */
    u8 pad3e[2];
    u32 flags;          /* 0x040 */
    u32 type;           /* 0x044 */
    u8 alpha;           /* 0x048 */
    u8 alphaStep;       /* 0x049 */
    s16 bounces;        /* 0x04A */
    s16 maxBounces;     /* 0x04C */
    u8 pad4e[2];
    f32 x50;            /* 0x050 */
    u8 x54[4];          /* 0x054 */
    Model* model;       /* 0x058 */
    u8 pad5c[0x98 - 0x5C];
    f32 x98;            /* 0x098 */
    f32 x9c;            /* 0x09C */
    f32 xa0;            /* 0x0A0 */
    u8 pada4[0xD4 - 0xA4];
    AnimEnt anim[0x40]; /* 0x0D4 */
    s16 animA;          /* 0x1D4 */
    s16 animB;          /* 0x1D6 */
    s16 count;          /* 0x1D8 */
    u8 pad1da[2];
    s32 src;            /* 0x1DC */
    CmdHead hdr;        /* 0x1E0 */
} Part;
typedef struct {
    u8 pad[0x4C];
    Part* data;
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
    NJS_TEXLIST* tex;   /* 0x08 */
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
    NJS_TEXLIST* tex;   /* 0x4C */
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
extern void fn_8001D200(void*, Vec*);
extern void fn_8001DF44(void*, Vec*);
extern void fn_80012130(Vec*);
extern void fn_80032E78(int flag, void* w, s16 frame, f32 alpha, void* a, s16 b, int mode);
extern void fn_80033A18(void*, s32, s32, s8);
extern int fn_80037FD8(void* e, u8* out);
extern void* fn_8003DB34(void* fn);
extern void fn_80061014(Vec*, Vec*, Vec*);
extern void fn_80061518(void*, Vec*, void*);
extern void fn_80061E34(Vec* out, s32* rot, f32 ang, f32 radius, f32 height);
extern void fn_80061F58(void*, int, int);
extern void fn_80071CF0(Vec*, Vec*);
extern void fn_80072130(void*);
extern int fn_8007E264(f32* out, f32 x, f32 z);
extern int fn_8025ECC4(void);
extern void fn_80071F84(s32* out, Vec* a, Vec* b);
extern s32 lbl_80346BC8;
extern void fn_8006CEEC(void*, void*, int, s16);
extern void sndAuxCallbackShutdownReverbSTD(void*, void*);
extern void fn_8022E8F8(void*, int);
extern void fn_8001E238(Vec*, Vec*, void*);
extern void fn_8001E4A0(Vec*, Vec*, void*);
extern void fn_8023080C(void*, s16*, int);
extern s32 fn_80035908(void);
extern void fn_80035910(s32);
extern void fn_80299040(void*);
extern void fn_8003440C(void* o, s16 idx, void* m, void* a, void* b, f32 f);
extern void fn_80034E6C(void* o, s16 idx, void* m, void* a, f32 f);
extern void fn_80048E58(struct NodeSrc*);
extern void fn_8001E3D8(Vec*, Vec*, void*);
extern void fn_8001E308(Vec*, Vec*, void*);
extern void fn_80061ABC(Vec*, Vec*, Vec*, f32, f32);
extern void* fn_8001E05C(void*);
extern void fn_80020B50(void*, s16*, s16*);
extern void fn_80020B8C(void*, s16, s16, int);
extern void fn_8001D14C(void*);
extern void* memcpy(void*, const void*, unsigned long);
extern void fn_8005A7B8(void*);
extern void fn_80018C94(void);
extern void fn_80047A68(void*, f32);
extern void fn_800331B0(u32*);
extern void fn_80061C80(Vec* out, void* rot, f32 a, f32 ang, f32 radius);
extern void fn_80048C40(struct W80048C40* src, f32* mat, s16 a, f32 f1, NJS_POINT3* pt, s16 b, s16 c, s32 d, struct Q16* q, f32 f2);
extern s32 fn_8001DB44(void*, int);
extern int fn_80018498(Vec*);
extern void fn_800492C0(struct Node_800492C0*);
extern void fn_80032C6C(int, void*);
extern void fn_80071CBC(Vec*, Vec*);
extern u8 fn_80011984(TexList**);
extern void fn_80032E44(void*);
extern void fn_80034AF0(void* o, s16 idx, void* m, void* a, void* b, s32 flag, f32 f);
extern void fn_80047214(u32 flags);
extern s32 fn_800358F8(void);
extern void fn_80035900(s32);
extern void fn_800334B8(void*);
extern void fn_80073F14(void*, void*, s16, void*, s32);
extern void njPushMatrixEx(void);
extern void njPopMatrixEx(void);
extern void fn_80286EE8(void);
extern void fn_8028B498(void);
extern void njTranslate(void*, f32, f32, f32);
extern void njScale(void*, f32, f32, f32);
extern void fn_8007E678(void*, void*);
extern void fn_80060950(void*);
extern void fn_8003529C(void*, void*, u8, f32);
extern void fn_80035380(void*, void*, f32, u8);
extern void fn_80033050(void*);
void fn_80040DC4(Node* node);
void fn_80043730(Node* node);

s32 fn_80040010(u32 flags) {
    if (flags & 0x80) {
        return 1;
    }
    if (flags & 0x40) {
        return 2;
    }
    return (flags & 0x10) ? 3 : 0;
}

void fn_80040044(DrawState* o, f32 f, u32 flags, u8* out) {
    o->control3d |= 0x800;
    o->colour.a = f;
    if (f != 0.0f) {
        o->attr_or = 0x800;
    }
    o->attr_and &= ~0x200;
    o->control3d &= ~0x100;
    if (flags & 0x800000) {
        *out = 2;
        o->attr_or |= 0x300;
    }
    if (flags & 0x1000000) {
        o->attr_and &= ~0x700;
        o->attr_or = 0x4000;
        *out = 2;
    }
    if (flags & 0x20000000) {
        o->attr_or |= 0x800;
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
    roll -= sum;
    roll %= cnt;
    i = lo;
    j = 0;
    while (tbl[i].weight != 0 && i <= hi) {
        j += tbl[i].weight;
        if (j > roll) {
            return tbl[i].id;
        }
        i++;
    }
    return -1;
}

void fn_80040508(Part* src, s16 div) {
    Node* t = fn_8003DB34(fn_80043730);
    Part* d;
    fn_80061F58(&t->work, 0x58, 0);
    fn_80061F58(&((Work_80040508*)t->work)->data, 0x1F0, 0);
    d = ((Work_80040508*)t->work)->data;
    *d = *src;
    d->timer = 0;
    d->start = 0;
    d->flags &= ~0x08000000;
    d->life = 0;
    d->alphaStep = 255 / div;
    d->vel0.x = 0.0f;
    d->vel0.y = 0.0f;
    d->vel0.z = 0.0f;
    d->drag = 1.0f;
    d->gravity = 0.0f;
}

void fn_800405EC(Node* node)
{
    Work_800405EC* w = node->work;
    Sub_800405EC* s = w->sub;
    Vec p;
    DrawState st;
    Quad q;
    s8 mode;
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
                q.tex = w->tex;
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

/* Common effect command header (0x14 bytes). */
typedef struct {
    u32 x0;
    u32 x4;
    s32 src;            /* 0x08 */
    u32 xc;
    u32 type;           /* 0x10 */
} CmdHdr;

/* Particle spawned by the emitter fn_80041238, run by fn_80041664 (0xAC bytes). */
typedef struct {
    CmdHdr h;           /* 0x00 (0x1C) */
    s16 start;          /* 0x14 (0x30) */
    s16 end;            /* 0x16 (0x32) */
    s16 fadeStart;      /* 0x18 (0x34) */
    s16 fadeIn;         /* 0x1A (0x36) */
    s16 fadeOut;        /* 0x1C (0x38) */
    s16 id;             /* 0x1E (0x3A) */
    Vec pos;            /* 0x20 (0x3C) */
    Vec rotDeg;         /* 0x2C (0x48) */
    Vec vel;            /* 0x38 (0x54) */
    Vec rotVel;         /* 0x44 (0x60) */
    Vec scaleVel;       /* 0x50 (0x6C) */
    s16 scaleStart;     /* 0x5C (0x78) */
    s16 scaleCount;     /* 0x5E (0x7A) */
    Vec scale;          /* 0x60 (0x7C) */
    Vec scaleVel2;      /* 0x6C (0x88) */
    s16 scaleStart2;    /* 0x78 (0x94) */
    s16 scaleCount2;    /* 0x7A (0x96) */
    s16 x7c;            /* 0x7C (0x98) */
    s16 x7e;            /* 0x7E (0x9A) */
    f32 frameStep;      /* 0x80 (0x9C) */
    s16 rotStart;       /* 0x84 (0xA0) */
    s16 rotEnd;         /* 0x86 (0xA2) */
    s16 moveStart;      /* 0x88 (0xA4) */
    s16 moveEnd;        /* 0x8A (0xA6) */
    s16 x8c;            /* 0x8C (0xA8) */
    s16 x8e;            /* 0x8E (0xAA) */
} PCmd;

typedef struct {
    s16 timer;          /* 0x00 */
    s16 count;          /* 0x02 */
    TaskRef* arg;       /* 0x04 */
    void* mtx;          /* 0x08 */
    void* mtx2;         /* 0x0C */
    f32 alpha;          /* 0x10 */
    f32 frame;          /* 0x14 */
    void* snd;          /* 0x18 */
    PCmd c;             /* 0x1C */
} PSub;

/* Emitter command (fn_80041238). */
typedef struct {
    CmdHdr h;           /* 0x00 (0x10) */
    s16 start;          /* 0x14 (0x24) */
    s16 end;            /* 0x16 (0x26) */
    s16 x18;            /* 0x18 (0x28) */
    s16 x1a;            /* 0x1A (0x2A) */
    s16 x1c;            /* 0x1C (0x2C) */
    s16 id;             /* 0x1E (0x2E) */
    Vec origin;         /* 0x20 (0x30) */
    u8 pad2c[0xC];
    f32 speed;          /* 0x38 (0x48) */
    Vec rotVel;         /* 0x3C (0x4C) */
    Vec scaleVel;       /* 0x48 (0x58) */
    s16 scaleStart;     /* 0x54 (0x64) */
    s16 scaleCount;     /* 0x56 (0x66) */
    Vec scale;          /* 0x58 (0x68) */
    s16 x64;            /* 0x64 (0x74) */
    s16 x66;            /* 0x66 (0x76) */
    f32 frameStep;      /* 0x68 (0x78) */
    s16 rotStart;       /* 0x6C (0x7C) */
    s16 rotEnd;         /* 0x6E (0x7E) */
    s16 moveStart;      /* 0x70 (0x80) */
    s16 moveEnd;        /* 0x72 (0x82) */
    s16 interval;       /* 0x74 (0x84) */
    s16 x76;            /* 0x76 (0x86) */
    s16 x78;            /* 0x78 (0x88) */
} ECmd;

typedef struct {
    s16 timer;          /* 0x00 */
    s16 count;          /* 0x02 */
    u8 pad4[4];
    TaskRef* arg;       /* 0x08 */
    void* mtx;          /* 0x0C */
    ECmd c;             /* 0x10 */
} ESub;

typedef struct {
    u8 pad0[0x4C];
    void* sub;          /* 0x4C */
    s32 x50;
    s32 x54;
} EWork;

void fn_80041664(Node* node);

void fn_80041238(Node* node)
{
    EWork* w = node->work;
    ESub* s = w->sub;
    Vec a;
    Vec b;
    Vec c;
    s32 ang[3];
    Node* n;
    EWork* w2;
    PSub* s2;

    switch (node->state) {
    case 0:
        fn_8006D954(s->c.h.src);
        node->state = 1;
        ((EWork*)node->work)->x50 = s->c.h.src;
        ((EWork*)node->work)->x54 = -1;
    case 1:
        if (s->timer >= s->c.start) {
            node->state = 3;
            fn_80040150(s->c.h.type, s->arg, s->c.id, &s->mtx);
        }
        break;
    case 3:
        if (s->timer >= s->c.end) {
            node->state = 0xFA;
        } else if (s->count % s->c.interval == 0) {
            fn_80061518(&s->c.origin, &a, s->mtx);
            fn_8001DF44(s->arg, &b);
            fn_80071F84(ang, &b, &a);
            fn_80061014(&a, &b, &c);
            fn_80072130(&c);
            n = fn_8003DB34(fn_80041664);
            fn_80061F58(&n->work, 0x58, 0);
            w2 = n->work;
            *(Buf*)w2 = *(Buf*)w;
            fn_80061F58(&w2->sub, 0xAC, 0);
            s2 = w2->sub;
            s2->arg = s->arg;
            s2->c.h = s->c.h;
            s2->c.h.type &= ~0xF;
            s2->c.h.type |= 1;
            s2->c.end = s->c.x18;
            s2->c.fadeIn = s->c.x1a;
            s2->c.fadeOut = s->c.x1c;
            s2->c.id = s->c.id;
            fn_80071CF0(&a, &s2->c.pos);
            s2->c.rotDeg.x = 360.0 * (ang[0] & 0xFFFF) / 65536.0;
            s2->c.rotDeg.y = 360.0 * (ang[1] & 0xFFFF) / 65536.0;
            s2->c.rotDeg.z = 360.0 * (ang[2] & 0xFFFF) / 65536.0;
            s2->c.vel.x = c.x * s->c.speed;
            s2->c.vel.y = c.y * s->c.speed;
            s2->c.vel.z = c.z * s->c.speed;
            fn_80071CF0(&s->c.rotVel, &s2->c.rotVel);
            fn_80071CF0(&s->c.scaleVel, &s2->c.scaleVel);
            s2->c.scaleStart = s->c.scaleStart;
            s2->c.scaleCount = s->c.scaleCount;
            fn_80071CF0(&s->c.scale, &s2->c.scale);
            if (s->count == 0) {
                s2->c.x7c = s->c.x64;
                s2->c.x7e = s->c.x66;
            }
            s2->c.frameStep = s->c.frameStep;
            s2->c.rotStart = s->c.rotStart;
            s2->c.rotEnd = s->c.rotEnd;
            s2->c.moveStart = s->c.moveStart;
            s2->c.moveEnd = s->c.moveEnd;
            s2->c.x8c = s->c.x76;
            s2->c.x8e = s->c.x78;
        }
        s->count++;
        break;
    case 0xF9:
    case 0xFA:
        fn_8006D8DC(s->c.h.src);
        FreeMtx(s->c.h.type, s->arg, s->c.id, &s->mtx);
        fn_801E17E0(s);
        node->flags |= 0x40;
        lbl_8030A10C.count--;
        return;
    }
    s->timer++;
    fn_80037FD8(&s->c, &node->state);
}

typedef struct { void** mdata; u32 nbFrame; } Motion;

typedef struct { u8 pad[8]; void* x8; } ObjSrc;

/* Model object work (0x58 bytes; the head is draw2d.c's DrawObj). */
typedef struct {
    void* model;        /* 0x00 */
    u8 pad4[4];
    void* texlist;      /* 0x08 */
    Motion* motion;     /* 0x0C */
    ObjSrc* src;        /* 0x10 */
    u8 pad14[2];
    s16 x16;            /* 0x16 */
    u8 pad18[4];
    Vec pos;            /* 0x1C */
    s32 ang[3];         /* 0x28 */
    Vec scl;            /* 0x34 */
    u8 pad40[4];
    u8 kind;            /* 0x44 */
    u8 pad45[7];
    PSub* sub;          /* 0x4C */
    s32 x50;
    s32 x54;
} PWork_80041664;

static inline void AllocMtx(void* a, u32 b, void** out)
{
    *out = fn_801E1C7C(0x40);
    fn_80076478(*out, a, b, 0);
}

static inline void FreeMtx2(void* a, u32 b, void** out)
{
    if (*out != NULL) {
        fn_8007638C(*out, a, b);
        fn_801E17E0(*out);
    }
}

void fn_80041664(Node* node)
{
    PWork_80041664* w = node->work;
    PSub* s = w->sub;
    u8 kind;
    s16 v[2];
    void* drawn;
    DrawState st;

    switch (node->state) {
    case 0:
        fn_8006D954(s->c.h.src);
        node->state = 1;
        ((PWork_80041664*)node->work)->x50 = s->c.h.src;
        ((PWork_80041664*)node->work)->x54 = -1;
    case 1:
        if (s->timer >= s->c.start) {
            node->state = 3;
            fn_80040150(s->c.h.type, s->arg, s->c.id, &s->mtx);
            if (s->c.h.type & 0x8000) {
                AllocMtx(w->model, 0, &s->mtx2);
            }
            w->ang[0] = 182.04445f * s->c.rotDeg.x;
            w->ang[1] = 182.04445f * s->c.rotDeg.y;
            w->ang[2] = 182.04445f * s->c.rotDeg.z;
            if (s->timer >= s->c.fadeStart) {
                if (s->c.fadeIn != 0) {
                    s->alpha = -1.0f + 1.0f / s->c.fadeIn;
                } else {
                    s->alpha = -1.0f;
                }
            } else {
                s->alpha = -1.0f;
            }
            fn_80071CF0(&s->c.scale, &w->scl);
            fn_8006CEEC(w->src->x8, &w->motion, 0, w->x16);
            if (s->c.x7c != 0 || s->c.x7e != 0) {
                sndAuxCallbackShutdownReverbSTD(w->model, &s->snd);
                fn_8022E8F8(w->model, 0);
            }
            if (s->c.moveStart >= s->c.moveEnd) {
                s->c.moveEnd = s->c.end;
            }
        }
        break;
    case 3:
        if (s->timer >= s->c.fadeStart && s->alpha < 0.0f && s->timer < s->c.end) {
            s->alpha += 1.0f / s->c.fadeIn;
            if (s->alpha > 0.0f) {
                s->alpha = 0.0f;
            }
        }
        if (s->timer >= s->c.end && s->c.start < s->c.end) {
            if (s->c.fadeOut != 0) {
                s->alpha -= 1.0f / s->c.fadeOut;
                if (s->alpha <= -1.0f) {
                    s->alpha = -1.0f;
                    node->state = 0xFA;
                }
            } else {
                node->state = 0xFA;
            }
        }
        if (s->mtx == NULL) {
            switch (s->c.h.type & 0xF) {
            case 3:
                fn_8001E238(&s->c.pos, &w->pos, s->arg);
                break;
            case 0:
                fn_8001E4A0(&s->c.pos, &w->pos, s->arg);
                break;
            case 1:
                fn_80071CF0(&s->c.pos, &w->pos);
                break;
            }
        } else {
            fn_80071CF0(&s->c.pos, &w->pos);
        }
        if ((s->c.h.type & 0xF) != 3 && s->timer >= s->c.moveStart && s->timer < s->c.moveEnd) {
            s->c.pos.x += s->c.vel.x;
            s->c.pos.y += s->c.vel.y;
            s->c.pos.z += s->c.vel.z;
        }
        if (s->c.rotStart == s->c.rotEnd || (s->c.rotEnd > s->timer && s->c.rotStart <= s->timer)) {
            w->ang[0] += (s32)(182.04445f * s->c.rotVel.x);
            w->ang[1] += (s32)(182.04445f * s->c.rotVel.y);
            w->ang[2] += (s32)(182.04445f * s->c.rotVel.z);
        }
        if (s->c.scaleCount > 0 && s->timer >= s->c.scaleStart) {
            w->scl.x += s->c.scaleVel.x;
            w->scl.y += s->c.scaleVel.y;
            w->scl.z += s->c.scaleVel.z;
            s->c.scaleCount--;
        }
        if (s->c.scaleCount2 > 0 && s->timer >= s->c.scaleStart2) {
            w->scl.x += s->c.scaleVel2.x;
            w->scl.y += s->c.scaleVel2.y;
            w->scl.z += s->c.scaleVel2.z;
            s->c.scaleCount2--;
        }
        if (w->scl.x < 0.0f) {
            w->scl.x = 0.0f;
        }
        if (w->scl.y < 0.0f) {
            w->scl.y = 0.0f;
        }
        if (w->scl.z < 0.0f) {
            w->scl.z = 0.0f;
        }
        if (w->motion != NULL) {
            s->frame += s->c.frameStep;
            if (s->frame >= (f32)w->motion->nbFrame - 1.0f) {
                if (s->c.h.type & 0x08000000) {
                    s->frame = (f32)w->motion->nbFrame - 1.0f;
                } else {
                    s->frame = 0.0f;
                }
            }
        }
        if (s->c.x7c != 0 || s->c.x7e != 0) {
            v[0] = s->c.x7c;
            v[1] = s->c.x7e;
            fn_8023080C(s->snd, v, 0);
        }
        if (w->x50 > 0x195DC && w->x50 < 0x195FA) {
            lbl_80346BC8 = fn_80035908();
            fn_80035910(0x1000000);
        }
        DrawStateDefault2D(&st);
        kind = w->kind;
        fn_80040044(&st, s->alpha, s->c.h.type, &w->kind);
        if (DrawStatePush(&st) != 0) {
            fn_80299040(w->texlist);
            drawn = NULL;
            fn_8006CEEC(w->src->x8, &drawn, 1, w->x16);
            if (drawn != NULL) {
                fn_8003440C(w, -1, s->mtx, w->motion, drawn, s->frame);
            } else {
                fn_80034E6C(w, -1, s->mtx, w->motion, s->frame);
            }
            DrawStatePop(NULL);
        }
        w->kind = kind;
        if (s->c.x8c != 0 && s->count % s->c.x8c == 0) {
            fn_80048E58((struct NodeSrc*)node);
        }
        if (w->x50 > 0x195DC && w->x50 < 0x195FA) {
            fn_80035910(lbl_80346BC8);
        }
        s->count++;
        break;
    case 0xF9:
    case 0xFA:
        fn_8006D8DC(s->c.h.src);
        FreeMtx(s->c.h.type, s->arg, s->c.id, &s->mtx);
        if (s->mtx2 != NULL) {
            fn_8007638C(s->mtx2, w->model, 0);
            fn_801E17E0(s->mtx2);
        }
        fn_801E17E0(s);
        node->flags |= 0x40;
        lbl_8030A10C.count--;
        return;
    }
    s->timer++;
    fn_80037FD8(&s->c, &node->state);
}

/* Particle burst command (fn_80041E64 spawns, fn_800422D0 runs each particle). */
typedef struct {
    u8 pad0[0x6];
    s16 flags;          /* 0x06 */
    s32 src;            /* 0x08 */
    u8 pad0c[0x4];
    u32 type;           /* 0x10 */
    s16 start;          /* 0x14 */
    s16 spread;         /* 0x16 random start offset range */
    s16 len;            /* 0x18 */
    s16 fade;           /* 0x1A */
    s16 count;          /* 0x1C particles per group */
    s16 step;           /* 0x1E start delay between particles */
    f32 accel;          /* 0x20 */
    f32 jitterX;        /* 0x24 */
    f32 speed;          /* 0x28 */
    f32 jitterZ;        /* 0x2C */
    Vec size;           /* 0x30 size, max, step */
    s16 x3c;            /* 0x3C */
    AnimEnt anim[0x40]; /* 0x3E */
    s16 animA;          /* 0x13E */
    s16 animB;          /* 0x140 */
    s16 num;            /* 0x142 groups */
    f32 x144;           /* 0x144 */
    f32 x148;           /* 0x148 */
    f32 x14c;           /* 0x14C */
    f32 x150;           /* 0x150 */
    f32 x154;           /* 0x154 */
    f32 x158;           /* 0x158 */
    s16 x15c;           /* 0x15C */
    u8 pad15e[2];
    Vec pos;            /* 0x160 */
} LCmd;

typedef struct {
    s16 timer;          /* 0x00 */
    s16 count;          /* 0x02 */
    TaskRef* arg;       /* 0x04 */
    u8 pad8[0x8C - 0x8];
    LCmd* c;            /* 0x8C */
} LSub;

/* One particle (0x48 bytes). */
typedef struct {
    s16 timer;          /* 0x00 */
    s16 count;          /* 0x02 */
    TaskRef* arg;       /* 0x04 */
    u8 pad8[4];
    u8 alpha;           /* 0x0C */
    u8 alphaStep;       /* 0x0D */
    u8 pad0e[2];
    f32 x10;            /* 0x10 */
    f32 x14;            /* 0x14 */
    s16 frame;          /* 0x18 */
    u8 pad1a[6];
    LCmd* c;            /* 0x20 */
    s16 x24;            /* 0x24 */
    s16 start;          /* 0x26 */
    s16 end;            /* 0x28 */
    u8 pad2a[2];
    f32 x2c;            /* 0x2C */
    f32 x30;            /* 0x30 */
    f32 size;           /* 0x34 */
    f32 sizeMax;        /* 0x38 */
    f32 sizeStep;       /* 0x3C */
    s16 x40;            /* 0x40 */
    u8 pad42[2];
    f32 fall;           /* 0x44 */
} LPart;

typedef struct {
    u8 pad0[0x1C];
    Vec pos;            /* 0x1C */
    u8 pad28[0x34 - 0x28];
    f32 size;           /* 0x34 */
    u8 pad38[0x4C - 0x38];
    void* sub;          /* 0x4C */
    s32 x50;
    s32 x54;
} LWork;

void fn_800422D0(Node* node);

void fn_80041E64(Node* node)
{
    LWork* w = node->work;
    LSub* s = w->sub;
    s16 i;
    s16 j;
    s16 ofs;
    u8 kind;
    f32 dx;
    f32 dy;
    f32 t;
    f32 sc;
    f32 ang;
    Node* n;
    LWork* w2;
    LPart* p;

    switch (node->state) {
    case 0:
        if (s->timer >= s->c->start) {
            for (i = 0; i < s->c->num; i++) {
                if (s->c->spread != 0) {
                    ofs = fn_8025ECC4() % s->c->spread;
                } else {
                    ofs = 0;
                }
                dx = s->c->x14c * (3.0517578125e-05f * fn_8025ECC4());
                dy = s->c->x150 * (3.0517578125e-05f * fn_8025ECC4());
                t = 3.0517578125e-05f * fn_8025ECC4();
                sc = 3.0517578125e-05f * fn_8025ECC4();
                ang = 3.0517578125e-05f * fn_8025ECC4();
                if (sc < 0.8f) {
                    sc = 0.8f;
                }
                if (s->c->x3c == 8) {
                    kind = fn_8025ECC4() % 4;
                } else {
                    kind = s->c->x3c;
                }
                ang = 360.0f * ang;
                for (j = 0; j < s->c->count; j++) {
                    n = fn_8003DB34(fn_800422D0);
                    fn_80061F58(&n->work, 0x58, 0);
                    w2 = n->work;
                    *(Buf*)w2 = *(Buf*)w;
                    fn_80061F58(&w2->sub, 0x48, 0);
                    p = w2->sub;
                    p->c = s->c;
                    p->arg = s->arg;
                    p->start = ofs + s->c->step * j;
                    p->end = ofs + s->c->step * j + (s->c->len - s->c->start);
                    p->x2c = s->c->x144 + dx;
                    p->x30 = s->c->x148 + dy;
                    p->x10 = s->c->x154 - s->c->x158;
                    if (p->x10 < 0.0f) {
                        p->x10 *= -1.0f;
                    }
                    p->x10 *= t;
                    if (s->c->x154 < s->c->x158) {
                        p->x10 += s->c->x154;
                    } else {
                        p->x10 += s->c->x158;
                    }
                    p->x14 = ang;
                    p->x24 = kind;
                    p->size = s->c->size.x * sc;
                    p->sizeMax = s->c->size.y * sc;
                    p->sizeStep = s->c->size.z * sc;
                }
            }
            node->state = 0xFA;
            return;
        }
        switch (s->c->src) {
        case 0x19729:
            s->c->flags |= 0x2000;
            break;
        }
        break;
    case 0xF9:
    case 0xFA:
        fn_801E17E0(s);
        node->flags |= 0x40;
        lbl_8030A10C.count--;
        return;
    }
    s->timer++;
    fn_80037FD8(s->c, &node->state);
}

void fn_800422D0(Node* node)
{
    LWork* w = node->work;
    LPart* s = w->sub;
    Vec a;
    Vec b;
    int flag;
    int mode;
    f32 sign;

    switch (node->state) {
    case 0:
        fn_8006D954(s->c->src);
        node->state = 1;
        ((LWork*)node->work)->x50 = s->c->src;
        ((LWork*)node->work)->x54 = -1;
    case 1:
        if (s->timer >= s->start) {
            s->x40 = s->c->x15c;
            s->x40 = 0xFF;
            s->alpha = s->x40;
            s->fall = s->c->speed;
            s->alphaStep = s->alpha / s->c->fade;
            switch (s->c->type & 0xF) {
            case 1:
                fn_80071CF0(&s->c->pos, &a);
                fn_80071CF0(&s->c->pos, &b);
                break;
            case 0:
                fn_8001E4A0(&s->c->pos, &a, s->arg);
                fn_8001E4A0(&s->c->pos, &b, s->arg);
                break;
            case 4:
                fn_8001E3D8(&s->c->pos, &a, s->arg);
                fn_8001E3D8(&s->c->pos, &b, s->arg);
                break;
            case 5:
                fn_8001E308(&s->c->pos, &a, s->arg);
                fn_8001E308(&s->c->pos, &b, s->arg);
                break;
            }
            a.z -= s->x2c;
            b.z += s->x2c;
            a.y += s->x30;
            b.y += s->x30;
            fn_80061ABC(&w->pos, &a, &b, s->x10, s->x14);
            node->state = 3;
        }
        switch (s->c->src) {
        case 0x19729:
            s->c->flags |= 0x2000;
            break;
        }
        break;
    case 3:
        if (s->end >= 0 && s->timer >= s->end) {
            node->state = 0xFA;
        } else {
            if (s->timer >= s->end - s->c->fade) {
                if (s->alpha >= s->alphaStep) {
                    s->alpha -= s->alphaStep;
                } else {
                    s->alpha = 0;
                    node->state = 0xFA;
                }
            }
            s->size += s->sizeStep;
            if (s->size >= s->sizeMax) {
                s->size = s->sizeMax;
            }
            sign = 1.0f;
            if (3.0517578125e-05f * fn_8025ECC4() >= 0.5f) {
                sign *= -1.0f;
            }
            w->pos.x += sign * (s->c->jitterX * (3.0517578125e-05f * fn_8025ECC4()));
            w->pos.y += s->fall;
            if (3.0517578125e-05f * fn_8025ECC4() >= 0.5f) {
                sign *= -1.0f;
            }
            w->pos.z += sign * (s->c->jitterZ * (3.0517578125e-05f * fn_8025ECC4()));
            flag = 0;
            s->fall += s->c->accel;
            s->frame = fn_800403AC(s->count, s->c->anim, s->c->animA, s->c->animB);
            if (s->c->type & 0x20000000) {
                flag = 1;
            }
            if (s->frame < 0) {
                s->frame = 0;
            }
            w->size = s->size;
            if (s->c->type & 0x80) {
                mode = 1;
            } else if (s->c->type & 0x40) {
                mode = 2;
            } else if (s->c->type & 0x10) {
                mode = 3;
            } else {
                mode = 0;
            }
            fn_80032E78(flag, w, s->frame, -1.0f + (f32)s->alpha / 255.0f, 0, s->x24, mode);
        }
        s->count++;
        break;
    case 0xF9:
    case 0xFA:
        fn_8006D8DC(s->c->src);
        fn_801E17E0(s);
        node->flags |= 0x40;
        lbl_8030A10C.count--;
        return;
    }
    s->timer++;
    fn_80037FD8(s->c, &node->state);
}


typedef struct {
    u8 pad0[0x4];
    s8 x4;                  /* 0x04 */
    u8 pad5[0x18 - 0x5];
    s16 x18;                /* 0x18 */
    u8 pad1a[0x50 - 0x1A];
    u32 x50;                /* 0x50 */
    u8 pad54[0x5A - 0x54];
    u8 x5a;                 /* 0x5A */
    u8 pad5b[0xEC - 0x5B];
    u32 xec;                /* 0xEC */
} Chr_8004281C;

typedef struct { u8 pad[0x4C]; Chr_8004281C* chr; } ChrInfo_8004281C;

typedef struct { u8 pad[0x24]; ChrInfo_8004281C* info; } ChrTask_8004281C;

typedef struct {
    u8 pad0[0x2];
    s16 x2;                 /* 0x02 */
    s16 x4;                 /* 0x04 */
    s16 x6;                 /* 0x06 */
    ChrTask_8004281C* task;          /* 0x08 */
    ChrTask_8004281C* xc;            /* 0x0C */
    u8 pad10[0x16 - 0x10];
    s16 x16;                /* 0x16 */
    u8 pad18[0x20 - 0x18];
    u32 x20;                /* 0x20 */
    s16 wait;               /* 0x24 */
    s16 x26;                /* 0x26 */
} Work_8004281C;

void fn_8004281C(Node* node)
{
    int f = 0;
    Work_8004281C* w = node->work;
    Chr_8004281C* c = w->task->info->chr;
    Chr_8004281C* c2;

    if (c->x50 & 0x200000) {
        switch (node->state) {
        case 0:
            node->state = 0xFA;
            break;
        case 3:
            break;
        default:
            node->state = 4;
            break;
        }
    }
    switch (node->state) {
    case 0:
        w->xc = fn_8001E05C(w->task);
        node->state = 1;
        if (w->x20 & 0x20000000) {
            c->xec |= 0x80000;
        }
        if (w->x20 & 0x10000000) {
            c->xec |= 0x40000;
        }
        fn_80020B50(w->task, &w->x2, &w->x4);
        w->x6 = c->x4;
        break;
    case 1:
        if (w->wait != 0) {
            w->wait--;
            break;
        }
        node->state = 2;
    case 2:
        if (w->x20 & 0x20000000) {
            if (w->x20 & 0x400) {
                f = 1;
            }
            c->xec |= 0x80;
            c->x5a = w->x6;
            fn_80020B8C(w->task, w->x2, w->x4, f);
            c->xec &= ~0x80;
            node->state = 3;
        } else {
            c2 = w->xc->info->chr;
            c2->x18 = w->x26;
            c2->xec |= 0x40000000;
            node->state = 3;
        }
        break;
    case 3:
        if (w->x20 & 0x10000000) {
            fn_8001D14C(w->task->info->chr);
        }
        node->flags |= 0x40;
        lbl_8030A10C.count--;
        return;
    case 5:
        if (lbl_8030A10C.flags & 0x20) {
            node->state = 1;
            w->wait = 0;
        }
        break;
    case 4:
        if (w->x20 & 0x20000000) {
            c->xec &= ~0x80000;
        }
        if (w->x20 & 0x10000000) {
            c->xec &= ~0x40000;
        }
    case 0xFA:
        node->flags |= 0x40;
        lbl_8030A10C.count--;
        return;
    }
    if (w->x16 & 0x2000) {
        switch (node->state) {
        case 1:
            break;
        default:
            lbl_8030A10C.flags |= 0x10;
            break;
        }
        if ((lbl_8030A10C.flags & 0x80) && !(lbl_8030A10C.flags & 0x20)) {
            switch (node->state) {
            case 1:
                node->state = 5;
                break;
            }
        }
    }
}






/* Particle burst command (fn_80042B10), at sub+0x28. */
typedef struct {
    CmdHead hdr;        /* 0x00 */
    u32 type;           /* 0x10 */
    s16 start;          /* 0x14 */
    s16 life;           /* 0x16 */
    s16 id;             /* 0x18 */
    u8 pad1a[2];
    Vec ofs;            /* 0x1C */
    Vec dir;            /* 0x28 */
    s16 num;            /* 0x34 */
    s16 delay;          /* 0x36 */
    s16 mode;           /* 0x38 */
    u8 pad3a[2];
    f32 fade;           /* 0x3C */
    f32 x40;            /* 0x40 */
    f32 x44;            /* 0x44 */
    Vec speed;          /* 0x48 */
    f32 gravity;        /* 0x54 */
    f32 drag;           /* 0x58 */
    f32 scale;          /* 0x5C */
    AnimEnt anim[0x40]; /* 0x60 */
    s16 animA;          /* 0x160 */
    s16 animB;          /* 0x162 */
} BurstCmd_80042B10;

typedef struct {
    s16 timer;          /* 0x00 */
    u8 pad2[2];
    TaskRef* arg;       /* 0x04 */
    void* mtx;          /* 0x08 */
    Vec a;              /* 0x0C */
    Vec b;              /* 0x18 */
    u8 alpha;           /* 0x24 */
    u8 pad25[3];
    BurstCmd_80042B10 c;         /* 0x28 */
} Burst_80042B10;

typedef struct {
    u8 pad0[0x8];
    void* texlist;      /* 0x08 */
    u8 pad0c[0x1C - 0xC];
    Vec pos;            /* 0x1C */
    u8 pad28[0x4C - 0x28];
    void* sub;          /* 0x4C */
    s32 x50;
    s32 x54;
} Work_80042B10;

void fn_80042B10(Node* node)
{
    Work_80042B10* w = node->work;
    Burst_80042B10* s = w->sub;
    Vec v44;
    Vec v38;
    Vec v2c;
    Vec v20;
    Vec v14;
    Vec v08;
    f32 t;
    s16 i;
    Node* n;
    Part* d;

    switch (node->state) {
    case 0:
        fn_8006D954(s->c.hdr.src);
        node->state = 1;
        ((Work_80042B10*)node->work)->x50 = s->c.hdr.src;
        ((Work_80042B10*)node->work)->x54 = -1;
    case 1:
        node->state = 2;
        switch (s->c.type & 0xF) {
        case 3:
            s->c.type &= ~0xF;
            break;
        }
        fn_80040150(s->c.type, s->arg, s->c.id, &s->mtx);
        s->alpha = 0xFF;
        break;
    case 2:
        if (s->timer < s->c.start) {
            break;
        }
        switch (s->c.type & 0xF) {
        case 1:
            fn_80071CF0(&s->c.ofs, &w->pos);
            fn_80071CF0(&s->c.dir, &s->a);
            fn_80071CF0(&s->c.dir, &v38);
            v38.x *= -1.0f;
            fn_80071CF0(&v38, &v44);
            if (s->c.type & 0x80000) {
                t = v38.x;
                v38.x = v38.z;
                v38.z = t;
                fn_80071CF0(&v38, &v2c);
                v38.z *= -1.0f;
                fn_80071CF0(&v38, &v14);
            }
            s->a.x += s->c.ofs.x;
            v14.x += s->c.ofs.x;
            v44.x += s->c.ofs.x;
            v2c.x += s->c.ofs.x;
            s->a.y += s->c.ofs.y;
            v14.y += s->c.ofs.y;
            v44.y += s->c.ofs.y;
            v2c.y += s->c.ofs.y;
            s->a.z += s->c.ofs.z;
            v14.z += s->c.ofs.z;
            v44.z += s->c.ofs.z;
            v2c.z += s->c.ofs.z;
            break;
        default:
            fn_80061518(&s->c.ofs, &w->pos, s->mtx);
            fn_80061518(&s->c.dir, &s->a, s->mtx);
            fn_80071CF0(&s->c.dir, &v38);
            v38.x *= -1.0f;
            fn_80061518(&v38, &v44, s->mtx);
            if (s->c.type & 0x80000) {
                t = v38.x;
                v38.x = v38.z;
                v38.z = t;
                fn_80061518(&v38, &v2c, s->mtx);
                v38.z *= -1.0f;
                fn_80061518(&v38, &v14, s->mtx);
            }
            break;
        }
        node->state = 3;
    case 3:
        node->state = 0xFA;
        if (s->mtx == NULL && (s->c.type & 0xF) != 1) {
            break;
        }
        fn_80061014(&w->pos, &s->a, &s->b);
        fn_80061014(&w->pos, &v44, &v38);
        if (s->c.type & 0x80000) {
            fn_80061014(&w->pos, &v2c, &v20);
            fn_80061014(&w->pos, &v14, &v08);
        }
        for (i = 0; i < s->c.num; i++) {
            if (s->c.type & 0x200) {
                n = fn_8003DB34(fn_8005A7B8);
            } else {
                n = fn_8003DB34(fn_80043730);
            }
            fn_80061F58(&n->work, 0x58, 0);
            fn_80061F58(&((Work_80042B10*)n->work)->sub, 0x1F0, 0);
            *(Buf*)n->work = *(Buf*)w;
            d = ((Work_80042B10*)n->work)->sub;
            d->texlist = w->texlist;
            fn_80071CF0(&w->pos, &d->pos);
            d->hdr = s->c.hdr;
            d->type = s->c.type;
            if (s->c.type & 0x80000) {
                switch (fn_8025ECC4() % 4) {
                case 0:
                    fn_80071CF0(&s->b, &d->vel0);
                    break;
                case 1:
                    fn_80071CF0(&v38, &d->vel0);
                    break;
                case 2:
                    fn_80071CF0(&v20, &d->vel0);
                    break;
                case 3:
                    fn_80071CF0(&v08, &d->vel0);
                    break;
                }
            } else if (fn_8025ECC4() % 2) {
                fn_80071CF0(&s->b, &d->vel0);
            } else {
                fn_80071CF0(&v38, &d->vel0);
            }
            d->vel0.x *= s->c.speed.x;
            d->vel0.y *= s->c.speed.y;
            d->vel0.z *= s->c.speed.z;
            d->vel0.x *= 3.0517578125e-05f * fn_8025ECC4();
            d->vel0.y *= 3.0517578125e-05f * fn_8025ECC4();
            d->vel0.z *= 3.0517578125e-05f * fn_8025ECC4();
            d->gravity = s->c.gravity;
            d->drag = s->c.drag;
            d->scale = s->c.scale;
            if (!(s->c.type & 0x8000)) {
                d->flags = 0xA0000000;
                d->maxBounces = 3;
            }
            if (s->c.type & 0x20000000) {
                d->flags |= 0x10000000;
            }
            if (s->c.delay == 0) {
                d->start = 0;
            } else {
                d->start = fn_8025ECC4() % s->c.delay;
            }
            d->life = s->c.life;
            d->alpha = 0xFF;
            if (s->c.fade != 0.0f) {
                d->alphaStep = 255.0f / s->c.fade;
            } else {
                d->alphaStep = 5;
            }
            d->animA = s->c.animA;
            d->animB = s->c.animB;
            memcpy(d->anim, s->c.anim, sizeof(d->anim));
            if (s->c.type & 0x200) {
                switch (s->c.mode) {
                case 0:
                    d->flags |= 0x2000000;
                    d->x98 = s->c.x40;
                    break;
                case 1:
                    d->flags |= 0x1000000;
                    d->x9c = s->c.x40;
                    break;
                case 2:
                    d->flags |= 0x800000;
                    d->xa0 = s->c.x40;
                    break;
                case 3:
                    d->flags |= 0x400000;
                    switch (fn_8025ECC4() % 3) {
                    case 0:
                        d->x98 = s->c.x40;
                        break;
                    case 1:
                        d->x9c = s->c.x40;
                        break;
                    case 2:
                        d->xa0 = s->c.x40;
                        break;
                    }
                    break;
                }
            }
            d->x50 = s->c.x44;
            d->src = s->c.hdr.src;
        }
        break;
    case 0xF9:
    case 0xFA:
        FreeMtx(s->c.type, s->arg, s->c.id, &s->mtx);
        fn_8006D8DC(s->c.hdr.src);
        fn_801E17E0(s);
        node->flags |= 0x40;
        lbl_8030A10C.count--;
        return;
    }
    s->timer++;
    fn_80037FD8(&s->c, &node->state);
}

typedef struct {
    u8 pad[0x18];
    Vec pos;            /* 0x18 */
    u8 pad24[0x30 - 0x24];
    Vec ang;            /* 0x30 */
} Model_8004335C;

/* Model_8004335C particle (fn_8004335C). */
typedef struct {
    s16 timer;          /* 0x00 */
    s16 start;          /* 0x02 */
    s16 life;           /* 0x04 */
    u8 pad6[2];
    Vec pos;            /* 0x08 */
    Vec vel0;           /* 0x14 */
    Vec vel;            /* 0x20 */
    f32 gravity;        /* 0x2C */
    f32 drag;           /* 0x30 */
    u8 pad34[4];
    void* texlist;      /* 0x38 */
    u8 pad3c[4];
    u32 flags;          /* 0x40 */
    u8 alpha;           /* 0x44 */
    u8 alphaStep;       /* 0x45 */
    s16 bounces;        /* 0x46 */
    s16 maxBounces;     /* 0x48 */
    u8 pad4a[2];
    u8 x4c[4];          /* 0x4C */
    Model_8004335C* model;       /* 0x50 */
    u8 pad54[0xCC - 0x54];
    s16 count;          /* 0xCC */
    u8 padce[2];
    s32 src;            /* 0xD0 */
    s32 spin;           /* 0xD4 */
    CmdHead hdr;        /* 0xD8 */
} MPart_8004335C;

typedef struct {
    u8 pad0[0x1C];
    Vec pos;            /* 0x1C */
    u8 pad28[0x4C - 0x28];
    MPart_8004335C* part;        /* 0x4C */
    s32 x50;
    s32 x54;
} Work_8004335C;

void fn_8004335C(Node* node)
{
    Work_8004335C* w = node->work;
    MPart_8004335C* d = w->part;
    DrawState st;

    switch (node->state) {
    case 0:
        fn_8006D954(d->src);
        node->state = 1;
        ((Work_8004335C*)node->work)->x50 = d->src;
        ((Work_8004335C*)node->work)->x54 = -1;
    case 1:
        if (d->timer < d->start) {
            break;
        }
        node->state = 2;
        fn_80071CF0(&d->vel0, &d->vel);
    case 2:
        d->pos.x += d->vel.x;
        d->pos.y += d->vel.y;
        d->pos.z += d->vel.z;
        if (d->flags & 0x4000000) {
            d->vel.y += d->gravity;
        } else {
            d->vel.x *= d->drag;
            d->vel.y += d->gravity;
            d->vel.z *= d->drag;
        }
        if (d->timer >= d->life) {
            if (d->alpha <= d->alphaStep) {
                d->alpha = 0;
                node->state = 0xFA;
            } else {
                d->alpha -= d->alphaStep;
            }
        }
        if (d->flags & 0x4000000) {
            if (d->flags & 0x80000000) {
                fn_8007E264(&w->pos.y, d->pos.x, d->pos.z);
                if (w->pos.y >= d->pos.y) {
                    d->vel.x *= d->drag;
                    d->vel.z *= d->drag;
                    d->pos.y = w->pos.y;
                    d->vel0.y *= d->drag;
                    d->vel.y = d->vel0.y;
                    if (d->vel.y < 0.0f) {
                        d->vel.y *= -1.0f;
                    }
                    d->bounces++;
                }
            }
            fn_80071CF0(&d->pos, &d->model->pos);
            if (d->spin != 0) {
                d->model->ang.x += (s32)(182.04445f * (10.0f * d->vel.x));
                d->model->ang.y += (s32)(182.04445f * (10.0f * d->vel.y));
                d->model->ang.z += (s32)(182.04445f * (10.0f * d->vel.z));
            }
            fn_80299040(d->texlist);
            DrawStateDefault2D(&st);
            if (DrawStatePush(&st) != 0) {
                fn_80047A68(d->x4c, (-255.0f + d->alpha) / 255.0f);
                fn_80018C94();
            }
        }
        d->count++;
        break;
    case 0xF9:
    case 0xFA:
        fn_8006D8DC(d->src);
        fn_801E17E0(d);
        node->flags |= 0x40;
        lbl_8030A10C.count--;
        return;
    }
    d->timer++;
    if ((d->flags & 0x20000000) && d->bounces >= d->maxBounces) {
        d->timer = d->life;
    }
    fn_80037FD8(&d->hdr, &node->state);
}



typedef struct {
    u8 pad0[0x8];
    void* texlist;      /* 0x08 */
    u8 pad0c[0x1C - 0xC];
    Vec pos;            /* 0x1C */
    u8 pad28[0x4C - 0x28];
    Part* part;         /* 0x4C */
    s32 x50;
    s32 x54;
} Work_80043730;

void fn_80043730(Node* node)
{
    Work_80043730* w = node->work;
    Part* d = w->part;
    DrawState st;
    Quad q;
    s8 mode;

    switch (node->state) {
    case 0:
        fn_8006D954(d->src);
        node->state = 1;
        ((Work_80043730*)node->work)->x50 = d->src;
        ((Work_80043730*)node->work)->x54 = -1;
    case 1:
        if (d->timer < d->start) {
            break;
        }
        node->state = 2;
        fn_80071CF0(&d->vel0, &d->vel);
    case 2:
        d->pos.x += d->vel.x;
        d->pos.y += d->vel.y;
        d->pos.z += d->vel.z;
        if (d->flags & 0x4000000) {
            d->vel.y += d->gravity;
        } else {
            d->vel.x *= d->drag;
            d->vel.y += d->gravity;
            d->vel.z *= d->drag;
        }
        if (d->timer >= d->life || d->pos.y < 0.0f) {
            if (d->alpha <= d->alphaStep) {
                d->alpha = 0;
                node->state = 0xFA;
            } else {
                d->alpha -= d->alphaStep;
            }
        }
        if (d->flags & 0x4000000) {
            if (d->flags & 0x80000000) {
                fn_8007E264(&w->pos.y, d->pos.x, d->pos.z);
                if (w->pos.y >= d->pos.y) {
                    d->vel.x *= d->drag;
                    d->vel.z *= d->drag;
                    d->pos.y = w->pos.y;
                    d->vel0.y *= d->drag;
                    d->vel.y = d->vel0.y;
                    if (d->vel.y < 0.0f) {
                        d->vel.y *= -1.0f;
                    }
                    d->bounces++;
                }
            }
            fn_80071CF0(&d->pos, &d->model->pos);
            fn_80299040(w->texlist);
            DrawStateDefault2D(&st);
            if (DrawStatePush(&st) != 0) {
                fn_80047A68(d->x54, (-255.0f + d->alpha) / 255.0f);
                fn_80018C94();
            }
        } else {
            d->frame = fn_800403AC(d->count, d->anim, d->animA, d->animB);
            if (d->flags & 0x80000000) {
                fn_8007E264(&w->pos.y, d->pos.x, d->pos.z);
                if (w->pos.y >= d->pos.y) {
                    d->pos.y = w->pos.y;
                    d->vel.y = d->vel0.y * d->drag;
                    if (d->vel.y < 0.0f) {
                        d->vel.y *= -1.0f;
                    }
                    d->bounces++;
                }
            }
            DrawStateDefault2D(&st);
            fn_800331B0(&st.attr_and);
            if (d->flags & 0x10000000) {
                st.blend_src = 8;
                st.blend_dst = 10;
            }
            if (d->type & 0x80) {
                mode = 1;
            } else if (d->type & 0x40) {
                mode = 2;
            } else if (d->type & 0x10) {
                mode = 3;
            } else {
                mode = 0;
            }
            if (DrawStatePush(&st) != 0) {
                memset(&q, 0, sizeof(q));
                q.unk38 = 0;
                q.sx = d->scale;
                q.sy = d->scale;
                q.tex = d->texlist;
                if (d->frame < 0) {
                    d->frame = 0;
                }
                q.frame = d->frame;
                fn_80012130(&q.vec);
                q.col[0][0] = 255;
                q.col[0][1] = 255;
                q.col[0][2] = 255;
                q.col[0][3] = 255;
                q.col[0][0] = d->alpha;
                q.col[1][0] = 255;
                q.col[1][1] = 255;
                q.col[1][2] = 255;
                q.col[1][3] = 255;
                q.col[1][0] = d->alpha;
                q.col[2][0] = 255;
                q.col[2][1] = 255;
                q.col[2][2] = 255;
                q.col[2][3] = 255;
                q.col[2][0] = d->alpha;
                q.col[3][0] = 255;
                q.col[3][1] = 255;
                q.col[3][2] = 255;
                q.col[3][3] = 255;
                q.col[3][0] = d->alpha;
                fn_80071CF0(&d->pos, &q.pos);
                fn_80033A18(&q, 0, 0, mode);
                DrawStatePop(NULL);
            }
            if (d->flags & 0x8000000) {
                fn_80040508(d, 10);
            }
        }
        d->count++;
        break;
    case 0xF9:
    case 0xFA:
        fn_8006D8DC(d->src);
        fn_801E17E0(d);
        node->flags |= 0x40;
        lbl_8030A10C.count--;
        return;
    }
    d->timer++;
    if ((d->flags & 0x20000000) && d->bounces >= d->maxBounces) {
        d->timer = d->life;
    }
    fn_80037FD8(&d->hdr, &node->state);
}


typedef struct {
    u8 pad0[0x8];
    s32 src;            /* 0x08 */
    u8 pad0c[0x4];
    u32 type;           /* 0x10 */
    s16 start;          /* 0x14 */
    s16 end;            /* 0x16 */
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
} Cmd_80043C24;

typedef struct {
    s16 timer;          /* 0x00 */
    TaskRef* arg;       /* 0x04 */
    void* mtx;          /* 0x08 */
    f32 ang;            /* 0x0C */
    u8 alpha;           /* 0x10 */
    u8 alphaStep;       /* 0x11 */
    s16 frame;          /* 0x12 */
    f32 height;         /* 0x14 */
    s32 rot[3];         /* 0x18 */
    Cmd_80043C24 c;              /* 0x24 */
} Sub_80043C24;

typedef struct {
    u8 pad0[0x8];
    NJS_TEXLIST* tex;   /* 0x08 */
    u8 pad0c[0x4C - 0xC];
    Sub_80043C24* sub;           /* 0x4C */
    s32 x50;
    s32 x54;
} Work_80043C24;

static inline s8 BlendMode(u32 type)
{
    if (type & 0x80) {
        return 1;
    } else if (type & 0x40) {
        return 2;
    } else if (type & 0x10) {
        return 3;
    } else {
        return 0;
    }
}

void fn_80043C24(Node* node)
{
    Work_80043C24* w;
    Sub_80043C24* s;
    s8 mode;
    Vec* dst;
    s16 i;
    Vec p;
    DrawState st;
    Quad q;

    w = node->work;
    s = w->sub;

    switch (node->state) {
    case 0:
        fn_8006D954(s->c.src);
        node->state = 1;
        ((Work_80043C24*)node->work)->x50 = s->c.src;
        ((Work_80043C24*)node->work)->x54 = -1;
    case 1:
        if (s->timer >= s->c.start) {
            node->state = 2;
            s->alpha = 255;
            s->alphaStep = 255 / s->c.fade;
            s->frame = (w->tex->nbTexture - 1) * (3.0517578125e-05f * fn_8025ECC4());
            fn_80040150(s->c.type, s->arg, s->c.id, &s->mtx);
            s->rot[0] = 182.04445f * s->c.rotDeg.x;
            s->rot[1] = 182.04445f * s->c.rotDeg.y;
            s->rot[2] = 182.04445f * s->c.rotDeg.z;
        }
        break;
    case 2:
        if (s->c.end >= 0 && s->timer >= s->c.end) {
            node->state = 0xFA;
        } else {
            if (s->timer >= s->c.end - s->c.fade) {
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
            mode = BlendMode(s->c.type);
            if (mode == 0) {
                st.colour.a = s->alpha / 255.0f;
                st.colour.r = 1.0f;
                st.colour.g = 1.0f;
                st.colour.b = 1.0f;
            }
            if (DrawStatePush(&st) != 0) {
                memset(&q, 0, sizeof(q));
                q.unk38 = 0;
                q.sx = s->c.scale;
                q.sy = s->c.scale;
                q.tex = w->tex;
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
                s->frame++;
                if (s->frame >= w->tex->nbTexture) {
                    s->frame = 0;
                }
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

typedef struct {
    u8 pad0[0x8];
    s32 src;            /* 0x08 */
    u8 pad0c[0x4];
    u32 type;           /* 0x10 */
    s16 start;          /* 0x14 */
    s16 end;            /* 0x16 */
    s16 fade;           /* 0x18 */
    u8 pad1a[0x2];
    Vec ofs;            /* 0x1C */
    s16 id;             /* 0x28 */
    u8 pad2a[0x2];
    s16 num;            /* 0x2C */
    f32 height;         /* 0x30 */
    f32 angStep;        /* 0x34 */
    f32 heightAcc;      /* 0x38 */
    f32 scale;          /* 0x3C */
    f32 radius;         /* 0x40 */
} Cmd_80044178;

typedef struct {
    s16 timer;          /* 0x00 */
    u8 pad2[2];
    TaskRef* arg;       /* 0x04 */
    f32 ang;            /* 0x08 */
    u8 alpha;           /* 0x0C */
    u8 alphaStep;       /* 0x0D */
    s16 frame;          /* 0x0E */
    Cmd_80044178 c;              /* 0x10 */
} Sub_80044178;

typedef struct {
    u8 pad0[0x8];
    NJS_TEXLIST* tex;   /* 0x08 */
    u8 pad0c[0x1C - 0xC];
    Vec pos;            /* 0x1C */
    u8 pad28[0x4C - 0x28];
    Sub_80044178* sub;           /* 0x4C */
    s32 x50;
    s32 x54;
} Work_80044178;

void fn_80044178(Node* node)
{
    Work_80044178* w;
    Sub_80044178* s;
    s8 mode;
    Vec* dst;
    s16 i;
    Vec p;
    Vec o;
    DrawState st;
    Quad q;

    w = node->work;
    s = w->sub;

    switch (node->state) {
    case 0:
        fn_8006D954(s->c.src);
        node->state = 1;
        ((Work_80044178*)node->work)->x50 = s->c.src;
        ((Work_80044178*)node->work)->x54 = -1;
    case 1:
        if (s->timer >= s->c.start) {
            node->state = 2;
            s->alpha = 255;
            s->alphaStep = 255 / s->c.fade;
        }
        break;
    case 2:
        node->state = 3;
        s->frame = (w->tex->nbTexture - 1) * (3.0517578125e-05f * fn_8025ECC4());
        break;
    case 3:
        if (s->c.end >= 0 && s->timer >= s->c.end) {
            node->state = 0xFA;
        } else {
            if (s->timer >= s->c.end - s->c.fade) {
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
            mode = BlendMode(s->c.type);
            if (DrawStatePush(&st) != 0) {
                memset(&q, 0, sizeof(q));
                q.unk38 = 0;
                q.sx = s->c.scale;
                q.sy = s->c.scale;
                q.tex = w->tex;
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
                s->frame++;
                if (s->frame >= w->tex->nbTexture) {
                    s->frame = 0;
                }
                switch (s->c.type & 0xF) {
                case 1:
                    fn_80071CF0(&s->c.ofs, &o);
                    break;
                default:
                    fn_8001E4A0(&s->c.ofs, &o, s->arg);
                    break;
                }
                dst = &q.pos;
                for (i = 0; i < s->c.num; i++) {
                    fn_80061C80(&p, NULL, 0.01f, i * (360.0f / s->c.num) + s->ang, s->c.radius);
                    w->pos.x = p.x + o.x;
                    w->pos.y = p.y + o.y;
                    w->pos.z = p.z + o.z;
                    fn_80071CF0(&w->pos, dst);
                    fn_80033A18(&q, 0, 0, mode);
                }
                s->c.ofs.y += s->c.height;
                s->c.height += s->c.heightAcc;
                DrawStatePop(NULL);
            }
            s->ang += s->c.angStep;
        }
        break;
    case 0xF9:
    case 0xFA:
        fn_8006D8DC(s->c.src);
        fn_801E17E0(s);
        node->flags |= 0x40;
        lbl_8030A10C.count--;
        return;
    }
    s->timer++;
    fn_80037FD8(&s->c, &node->state);
}

typedef struct {
    u8 pad0[0x8];
    s32 src;            /* 0x08 */
    u8 pad0c[0x4];
    u32 type;           /* 0x10 */
    s16 start;          /* 0x14 */
    s16 end;            /* 0x16 */
    s16 fade;           /* 0x18 */
    s16 id;             /* 0x1A */
    Vec ofs;            /* 0x1C */
    u8 pad28[4];
    f32 velYAcc;        /* 0x2C */
    f32 rangeX;         /* 0x30 */
    f32 velY;           /* 0x34 */
    f32 rangeZ;         /* 0x38 */
    f32 size;           /* 0x3C */
    f32 sizeMax;        /* 0x40 */
    f32 sizeStep;       /* 0x44 */
    s16 x48;            /* 0x48 */
    s16 alphaMax;       /* 0x4A */
} Cmd_800445D4;

typedef struct {
    s16 timer;          /* 0x00 */
    u8 pad2[2];
    TaskRef* arg;       /* 0x04 */
    void* mtx;          /* 0x08 */
    u8 alpha;           /* 0x0C */
    u8 alphaStep;       /* 0x0D */
    u8 pad0e[0xE];
    s16 frame;          /* 0x1C */
    u8 pad1e[2];
    Cmd_800445D4 c;              /* 0x20 */
} Sub_800445D4;

typedef struct {
    u8 pad0[0x8];
    NJS_TEXLIST* tex;   /* 0x08 */
    u8 pad0c[0x1C - 0xC];
    Vec pos;            /* 0x1C */
    u8 pad28[0x34 - 0x28];
    f32 size;           /* 0x34 */
    u8 pad38[0x4C - 0x38];
    Sub_800445D4* sub;           /* 0x4C */
    s32 x50;
    s32 x54;
} Work_800445D4;

void fn_800445D4(Node* node)
{
    Work_800445D4* w = node->work;
    Sub_800445D4* s = w->sub;
    f32 sign;
    int flag;
    int mode;

    switch (node->state) {
    case 0:
        fn_8006D954(s->c.src);
        node->state = 1;
        ((Work_800445D4*)node->work)->x50 = s->c.src;
        ((Work_800445D4*)node->work)->x54 = -1;
    case 1:
        if (s->timer >= s->c.start) {
            node->state = 2;
            if ((s->c.type & 0xF) == 2) {
                s->mtx = fn_801E1C7C(0x40);
                fn_80076478(s->mtx, s->arg->data->body->x154, s->c.id, 0);
            }
            if (s->c.alphaMax == 0 || s->c.alphaMax > 255) {
                s->c.alphaMax = 255;
            }
            s->alpha = s->c.alphaMax;
            s->alphaStep = s->alpha / s->c.fade;
        }
        break;
    case 2:
        node->state = 3;
        if (s->mtx != NULL) {
            fn_8007638C(s->mtx, s->arg->data->body->x154, s->c.id);
            fn_80061518(&s->c.ofs, &w->pos, s->mtx);
            fn_801E17E0(s->mtx);
        } else {
            switch (s->c.type & 0xF) {
            case 3:
                fn_8001E238(&s->c.ofs, &w->pos, s->arg);
                break;
            case 0:
                fn_8001E4A0(&s->c.ofs, &w->pos, s->arg);
                break;
            case 4:
                fn_8001E3D8(&s->c.ofs, &w->pos, s->arg);
                break;
            case 5:
                fn_8001E308(&s->c.ofs, &w->pos, s->arg);
                break;
            case 1:
                fn_80071CF0(&s->c.ofs, &w->pos);
                break;
            }
        }
        s->frame = (w->tex->nbTexture - 1) * (3.0517578125e-05f * fn_8025ECC4());
        break;
    case 3:
        if (s->c.end >= 0 && s->timer >= s->c.end) {
            node->state = 0xFA;
        } else {
            if (s->timer >= s->c.end - s->c.fade) {
                if (s->alpha >= s->alphaStep) {
                    s->alpha -= s->alphaStep;
                } else {
                    s->alpha = 0;
                    node->state = 0xFA;
                }
            }
            s->c.size += s->c.sizeStep;
            if (s->c.size >= s->c.sizeMax) {
                s->c.size = s->c.sizeMax;
            }
            sign = 1.0f;
            if (3.0517578125e-05f * fn_8025ECC4() >= 0.5f) {
                sign *= -1.0f;
            }
            w->pos.x += sign * (s->c.rangeX * (3.0517578125e-05f * fn_8025ECC4()));
            w->pos.y += s->c.velY;
            if (3.0517578125e-05f * fn_8025ECC4() >= 0.5f) {
                sign *= -1.0f;
            }
            w->pos.z += sign * (s->c.rangeZ * (3.0517578125e-05f * fn_8025ECC4()));
            s->c.velY += s->c.velYAcc;
            flag = 0;
            if (s->c.type & 0x20000000) {
                flag = 1;
            }
            if (s->frame < 0) {
                s->frame = 0;
            }
            w->size = s->c.size;
            s->frame++;
            if (s->frame >= w->tex->nbTexture) {
                s->frame = 0;
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
            fn_80032E78(flag, w, s->frame, -1.0f + s->alpha / 255.0f, 0, s->c.x48, mode);
        }
        break;
    case 0xF9:
    case 0xFA:
        fn_8006D8DC(s->c.src);
        fn_801E17E0(s);
        node->flags |= 0x40;
        lbl_8030A10C.count--;
        return;
    }
    s->timer++;
    fn_80037FD8(&s->c, &node->state);
}


/* Effect command (embedded in the sub at 0x1C). */
typedef struct {
    u8 pad0[0x8];
    s32 src;            /* 0x08 */
    u8 pad0c[0x4];
    u32 type;           /* 0x10 */
    u16 flags;          /* 0x14 */
    s16 start;          /* 0x16 */
    s16 end;            /* 0x18 */
    s16 len;            /* 0x1A */
    s16 fadeIn;         /* 0x1C */
    s16 fadeOut;        /* 0x1E */
    s16 id;             /* 0x20 */
    u8 pad22[2];
    Vec pos;            /* 0x24 */
    Vec rotDeg;         /* 0x30 */
    AnimEnt anim[0x40]; /* 0x3C */
    s16 animA;          /* 0x13C */
    s16 animB;          /* 0x13E */
    Vec move;           /* 0x140 */
    Vec rotStep;        /* 0x14C */
    Vec sclStep;        /* 0x158 */
    s16 sclStart;       /* 0x164 */
    s16 sclCount;       /* 0x166 */
    Vec scl;            /* 0x168 */
    s16 snd[2];         /* 0x174 */
    f32 texStep;        /* 0x178 */
    s16 rotStart;       /* 0x17C */
    s16 rotEnd;         /* 0x17E */
    s16 x180;           /* 0x180 */
    u8 pad182[2];
    u8 x184[0xC];       /* 0x184 */
    f32 x190;           /* 0x190 */
    s16 x194;           /* 0x194 */
    s16 x196;           /* 0x196 */
    s16 moveStart;      /* 0x198 */
    s16 moveEnd;        /* 0x19A */
    s16 period;         /* 0x19C */
    u8 pad19e[2];
    s32 tex;            /* 0x1A0 */
} Cmd_80044B24;

typedef struct {
    s16 timer;          /* 0x00 */
    s16 count;          /* 0x02 */
    TaskRef* arg;       /* 0x04 */
    void* mtx;          /* 0x08 */
    f32 alpha;          /* 0x0C */
    s16 frame;          /* 0x10 */
    u8 pad12[2];
    f32 tex;            /* 0x14 */
    void* snd;          /* 0x18 */
    Cmd_80044B24 c;              /* 0x1C */
} Sub_80044B24;

typedef struct {
    void* model;        /* 0x00 */
    u8 pad4[4];
    void* x8;           /* 0x08 */
    TexList* texlist;   /* 0x0C */
    ObjSrc* x10;         /* 0x10 */
    u8 pad14[2];
    s16 x16;            /* 0x16 */
    u8 pad18[4];
    Vec pos;            /* 0x1C */
    s32 rot[3];         /* 0x28 */
    Vec scl;            /* 0x34 */
    u8 pad40[4];
    u8 kind;            /* 0x44 */
    u8 pad45[0x4C - 0x45];
    Sub_80044B24* sub;           /* 0x4C */
    s32 x50;
    s32 x54;
} Work_80044B24;

void fn_80044B24(Node* node)
{
    Work_80044B24* w;
    Sub_80044B24* s;
    int active;
    int flag;
    u8 kind;
    s16 snd[2];
    void* tex;
    Vec tmp;
    DrawState st;
    int flag2;
    int mode;

    active = 0;
    flag = 0;
    w = node->work;
    s = w->sub;
    if (s->c.type & 0x200) {
        flag = 1;
    }
    if (s->c.tex == 0) {
        if (s->c.flags & 0x1000) {
            s->c.tex = fn_8001DB44(s->arg, 1);
        } else {
            s->c.tex = fn_8001DB44(s->arg, 0);
        }
    }
    switch (node->state) {
    case 0:
        fn_8006D954(s->c.src);
        node->state = 1;
        ((Work_80044B24*)node->work)->x50 = s->c.src;
        ((Work_80044B24*)node->work)->x54 = -1;
    case 1:
        if (s->c.flags & 0x8000) {
            if (s->c.tex == 0) {
                break;
            }
            node->state = 2;
        } else {
            node->state = 2;
        }
    case 2:
        if (s->timer == 0) {
            fn_80040150(s->c.type, s->arg, s->c.id, &s->mtx);
        }
        if (s->timer >= s->c.start) {
            node->state = 3;
            w->rot[0] = 182.04445f * s->c.rotDeg.x;
            w->rot[1] = 182.04445f * s->c.rotDeg.y;
            w->rot[2] = 182.04445f * s->c.rotDeg.z;
            if (s->timer >= s->c.len) {
                if (s->c.fadeIn != 0) {
                    s->alpha = -1.0f + 1.0f / s->c.fadeIn;
                } else {
                    s->alpha = -1.0f;
                }
            } else {
                s->alpha = -1.0f;
            }
            fn_80071CF0(&s->c.scl, &w->scl);
            fn_8006CEEC(w->x10->x8, &w->texlist, 0, w->x16);
            if (s->c.snd[0] != 0 || s->c.snd[1] != 0) {
                sndAuxCallbackShutdownReverbSTD(w->model, &s->snd);
                fn_8022E8F8(w->model, 0);
            }
            if (s->c.moveStart >= s->c.moveEnd) {
                s->c.moveEnd = s->c.end;
                if (s->c.moveEnd == 0) {
                    s->c.moveEnd = 999;
                }
            }
        }
        break;
    case 3:
        if (s->timer >= s->c.len && s->alpha < 0.0f &&
            ((s->timer < s->c.end && (s->c.flags & 0x8000)) ||
             (s->c.tex == 0 && !(s->c.flags & 0x8000)))) {
            s->alpha += 1.0f / s->c.fadeIn;
            if (s->alpha > 0.0f) {
                s->alpha = 0.0f;
            }
        }
        if (s->timer >= s->c.end || (s->c.tex != 0 && !(s->c.flags & 0x8000))) {
            if (s->c.fadeOut != 0) {
                s->alpha -= 1.0f / s->c.fadeOut;
                if (s->alpha <= -1.0f) {
                    s->alpha = -1.0f;
                    node->state = 0xFA;
                }
            } else {
                node->state = 0xFA;
            }
        }
        if (s->mtx == NULL) {
            switch (s->c.type & 0xF) {
            case 3:
                fn_8001E238(&s->c.pos, &w->pos, s->arg);
                break;
            case 0:
                fn_8001E4A0(&s->c.pos, &w->pos, s->arg);
                break;
            case 1:
                fn_80071CF0(&s->c.pos, &w->pos);
                break;
            }
            if (fn_80018498(&w->pos) == 0) {
                node->state = 0xFA;
            }
        } else {
            fn_80071CF0(&s->c.pos, &w->pos);
            fn_80061518(&w->pos, &tmp, s->mtx);
            if (fn_80018498(&tmp) == 0) {
                node->state = 0xFA;
            }
        }
        if ((s->c.type & 0x8000) && s->c.tex != 0) {
            active = 1;
        }
        if (!(s->c.type & 0x8000) && s->c.tex == 0) {
            active = 1;
        }
        if (active && s->timer >= s->c.moveStart && s->timer < s->c.moveEnd) {
            s->c.pos.x += s->c.move.x;
            s->c.pos.y += s->c.move.y;
            s->c.pos.z += s->c.move.z;
        }
        if (s->c.rotStart == s->c.rotEnd ||
            (s->c.rotEnd > s->timer && s->c.rotStart <= s->timer && active)) {
            w->rot[0] += (s32)(182.04445f * s->c.rotStep.x);
            w->rot[1] += (s32)(182.04445f * s->c.rotStep.y);
            w->rot[2] += (s32)(182.04445f * s->c.rotStep.z);
        }
        if (s->c.sclCount > 0 && s->timer >= s->c.sclStart && active) {
            w->scl.x += s->c.sclStep.x;
            w->scl.y += s->c.sclStep.y;
            w->scl.z += s->c.sclStep.z;
            s->c.sclCount--;
        }
        if (w->scl.x < 0.0f) {
            w->scl.x = 0.0f;
        }
        if (w->scl.y < 0.0f) {
            w->scl.y = 0.0f;
        }
        if (w->scl.z < 0.0f) {
            w->scl.z = 0.0f;
        }
        if (active) {
            s->frame = fn_800403AC(s->count, s->c.anim, s->c.animA, s->c.animB);
        }
        if (w->texlist != NULL && active) {
            s->tex += s->c.texStep;
            if (s->tex >= (f32)w->texlist->n - 1.0f) {
                if (s->c.type & 0x08000000) {
                    s->tex = (f32)w->texlist->n - 1.0f;
                } else {
                    s->tex = 0.0f;
                }
            }
        }
        if (s->c.snd[0] != 0 || s->c.snd[1] != 0) {
            snd[0] = s->c.snd[0];
            snd[1] = s->c.snd[1];
            if (active) {
                fn_8023080C(s->snd, snd, 0);
            }
        }
        if ((s->c.type & 0x04000000) || w->model == NULL) {
            flag2 = 0;
            if (s->c.type & 0x20000000) {
                flag2 = 1;
            }
            if (s->frame < 0) {
                s->frame = 0;
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
            fn_80032E78(flag2, w, s->frame, s->alpha, s->mtx, s->c.x180, mode);
        } else {
            DrawStateDefault2D(&st);
            kind = w->kind;
            fn_80040044(&st, s->alpha, s->c.type, &w->kind);
            if (DrawStatePush(&st) != 0) {
                fn_80299040(w->x8);
                tex = NULL;
                if ((s->c.flags & 0x2000) && s->c.tex != 0) {
                    fn_80048C40((struct W80048C40*)w, s->mtx, 0, s->c.x190, (NJS_POINT3*)s->c.x184, s->c.x194, s->c.x196, flag,
                                (struct Q16*)&s->c, s->alpha);
                    node->state = 0xFA;
                } else {
                    fn_8006CEEC(w->x10->x8, &tex, 1, w->x16);
                    if (tex != NULL) {
                        fn_8003440C(w, s->frame, s->mtx, w->texlist, tex, s->tex);
                    } else {
                        fn_80034E6C(w, s->frame, s->mtx, w->texlist, s->tex);
                    }
                }
                DrawStatePop(NULL);
            }
            w->kind = kind;
        }
        if (s->c.period != 0 && s->timer >= s->c.moveStart && s->timer < s->c.moveEnd &&
            s->count % s->c.period == 0 && active) {
            fn_800492C0((struct Node_800492C0*)node);
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
    if (node->state > 1) {
        s->timer++;
    }
    fn_80037FD8(&s->c, &node->state);
}

/* Effect command (embedded in the sub at 0x1C). */
typedef struct {
    u8 pad0[0x8];
    s32 src;            /* 0x08 */
    u8 pad0c[0x4];
    u32 type;           /* 0x10 */
    s16 start;          /* 0x14 */
    s16 end;            /* 0x16 */
    s16 len;            /* 0x18 */
    s16 fadeIn;         /* 0x1A */
    s16 fadeOut;        /* 0x1C */
    s16 id;             /* 0x1E */
    Vec pos;            /* 0x20 */
    Vec rotDeg;         /* 0x2C */
    AnimEnt anim[0x40]; /* 0x38 */
    s16 animA;          /* 0x138 */
    s16 animB;          /* 0x13A */
    Vec move;           /* 0x13C */
    Vec rotStep;        /* 0x148 */
    Vec sclStep;        /* 0x154 */
    s16 sclStart;       /* 0x160 */
    s16 sclCount;       /* 0x162 */
    Vec scl;            /* 0x164 */
    Vec sclStep2;       /* 0x170 */
    s16 sclStart2;      /* 0x17C */
    s16 sclCount2;      /* 0x17E */
    s16 snd[2];         /* 0x180 */
    f32 texStep;        /* 0x184 */
    s16 rotStart;       /* 0x188 */
    s16 rotEnd;         /* 0x18A */
    s16 x18c;           /* 0x18C */
    s16 x18e;           /* 0x18E */
    u8 x190[0xC];       /* 0x190 */
    f32 x19c;           /* 0x19C */
    s16 x1a0;           /* 0x1A0 */
    s16 x1a2;           /* 0x1A2 */
    s16 moveStart;      /* 0x1A4 */
    s16 moveEnd;        /* 0x1A6 */
} Cmd_800454A0;

typedef struct {
    s16 timer;          /* 0x00 */
    s16 count;          /* 0x02 */
    TaskRef* arg;       /* 0x04 */
    void* mtx;          /* 0x08 */
    f32 alpha;          /* 0x0C */
    s16 frame;          /* 0x10 */
    u8 pad12[2];
    f32 tex;            /* 0x14 */
    void* snd;          /* 0x18 */
    Cmd_800454A0 c;              /* 0x1C */
} Sub_800454A0;

typedef struct {
    void* model;        /* 0x00 */
    u8 pad4[4];
    void* x8;           /* 0x08 */
    TexList* texlist;   /* 0x0C */
    ObjSrc* x10;         /* 0x10 */
    u8 pad14[2];
    s16 x16;            /* 0x16 */
    u8 pad18[4];
    Vec pos;            /* 0x1C */
    s32 rot[3];         /* 0x28 */
    Vec scl;            /* 0x34 */
    u8 pad40[4];
    u8 kind;            /* 0x44 */
    u8 pad45[0x4C - 0x45];
    Sub_800454A0* sub;           /* 0x4C */
    s32 x50;
    s32 x54;
} Work_800454A0;

void fn_800454A0(Node* node)
{
    Work_800454A0* w = node->work;
    Sub_800454A0* s = w->sub;
    int flag;
    u8 kind;
    s16 snd[2];
    void* tex;
    DrawState st;
    int flag2;
    int mode;

    flag = 0;
    if (s->c.type & 0x200) {
        flag = 1;
    }
    switch (node->state) {
    case 0:
        fn_8006D954(s->c.src);
        node->state = 1;
        ((Work_800454A0*)node->work)->x50 = s->c.src;
        ((Work_800454A0*)node->work)->x54 = -1;
    case 1:
        if (s->timer >= s->c.start) {
            node->state = 3;
            fn_80040150(s->c.type, s->arg, s->c.id, &s->mtx);
            w->rot[0] = 182.04445f * s->c.rotDeg.x;
            w->rot[1] = 182.04445f * s->c.rotDeg.y;
            w->rot[2] = 182.04445f * s->c.rotDeg.z;
            if (s->timer >= s->c.len) {
                if (s->c.fadeIn != 0) {
                    s->alpha = -1.0f + 1.0f / s->c.fadeIn;
                } else {
                    s->alpha = -1.0f;
                }
            } else {
                s->alpha = -1.0f;
            }
            fn_80071CF0(&s->c.scl, &w->scl);
            fn_8006CEEC(w->x10->x8, &w->texlist, 0, w->x16);
            if (s->c.snd[0] != 0 || s->c.snd[1] != 0) {
                sndAuxCallbackShutdownReverbSTD(w->model, &s->snd);
                fn_8022E8F8(w->model, 0);
            }
            if (s->c.moveStart >= s->c.moveEnd) {
                s->c.moveEnd = s->c.end;
            }
        }
        break;
    case 3:
        if (s->timer >= s->c.len && s->alpha < 0.0f && s->timer < s->c.end) {
            s->alpha += 1.0f / s->c.fadeIn;
            if (s->alpha > 0.0f) {
                s->alpha = 0.0f;
            }
        }
        if (s->timer >= s->c.end && s->c.start < s->c.end) {
            if (s->c.fadeOut != 0) {
                s->alpha -= 1.0f / s->c.fadeOut;
                if (s->alpha <= -1.0f) {
                    s->alpha = -1.0f;
                    node->state = 0xFA;
                }
            } else {
                node->state = 0xFA;
            }
        }
        if (s->mtx == NULL) {
            switch (s->c.type & 0xF) {
            case 3:
                fn_8001E238(&s->c.pos, &w->pos, s->arg);
                break;
            case 0:
                fn_8001E4A0(&s->c.pos, &w->pos, s->arg);
                break;
            case 1:
                fn_80071CF0(&s->c.pos, &w->pos);
                break;
            }
        } else {
            fn_80071CF0(&s->c.pos, &w->pos);
        }
        if ((s->c.type & 0xF) != 3 && s->timer >= s->c.moveStart && s->timer < s->c.moveEnd) {
            s->c.pos.x += s->c.move.x;
            s->c.pos.y += s->c.move.y;
            s->c.pos.z += s->c.move.z;
        }
        if (s->c.rotStart == s->c.rotEnd ||
            (s->c.rotEnd > s->timer && s->c.rotStart <= s->timer)) {
            w->rot[0] += (s32)(182.04445f * s->c.rotStep.x);
            w->rot[1] += (s32)(182.04445f * s->c.rotStep.y);
            w->rot[2] += (s32)(182.04445f * s->c.rotStep.z);
        }
        if (s->c.sclCount > 0 && s->timer >= s->c.sclStart) {
            w->scl.x += s->c.sclStep.x;
            w->scl.y += s->c.sclStep.y;
            w->scl.z += s->c.sclStep.z;
            s->c.sclCount--;
        }
        if (s->c.sclCount2 > 0 && s->timer >= s->c.sclStart2) {
            w->scl.x += s->c.sclStep2.x;
            w->scl.y += s->c.sclStep2.y;
            w->scl.z += s->c.sclStep2.z;
            s->c.sclCount2--;
        }
        if (w->scl.x < 0.0f) {
            w->scl.x = 0.0f;
        }
        if (w->scl.y < 0.0f) {
            w->scl.y = 0.0f;
        }
        if (w->scl.z < 0.0f) {
            w->scl.z = 0.0f;
        }
        s->frame = fn_800403AC(s->count, s->c.anim, s->c.animA, s->c.animB);
        if (w->texlist != NULL) {
            s->tex += s->c.texStep;
            if (s->tex >= (f32)w->texlist->n - 1.0f) {
                if (s->c.type & 0x08000000) {
                    s->tex = (f32)w->texlist->n - 1.0f;
                } else {
                    s->tex = 0.0f;
                }
            }
        }
        if (s->c.snd[0] != 0 || s->c.snd[1] != 0) {
            snd[0] = s->c.snd[0];
            snd[1] = s->c.snd[1];
            fn_8023080C(s->snd, snd, 0);
        }
        fn_80032C6C(1, node);
        if ((s->c.type & 0x04000000) || w->model == NULL) {
            flag2 = 0;
            if (s->c.type & 0x20000000) {
                flag2 = 1;
            }
            if (s->frame < 0) {
                s->frame = 0;
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
            fn_80032E78(flag2, w, s->frame, s->alpha, s->mtx, s->c.x18c, mode);
        } else {
            DrawStateDefault2D(&st);
            kind = w->kind;
            fn_80040044(&st, s->alpha, s->c.type, &w->kind);
            if (DrawStatePush(&st) != 0) {
                fn_80299040(w->x8);
                tex = NULL;
                if (s->c.x18e != 0 && s->timer >= s->c.x18e) {
                    fn_80048C40((struct W80048C40*)w, s->mtx, s->c.x18e, s->c.x19c, (NJS_POINT3*)s->c.x190, s->c.x1a0, s->c.x1a2, flag,
                                (struct Q16*)&s->c, s->alpha);
                    node->state = 0xFA;
                } else {
                    fn_8006CEEC(w->x10->x8, &tex, 1, w->x16);
                    if (tex != NULL) {
                        fn_8003440C(w, s->frame, s->mtx, w->texlist, tex, s->tex);
                    } else {
                        fn_80034E6C(w, s->frame, s->mtx, w->texlist, s->tex);
                    }
                }
                DrawStatePop(NULL);
            }
            w->kind = kind;
        }
        fn_80032C6C(0, node);
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

/* Model effect command (pointed to by the sub at 0x68). */
typedef struct {
    u8 pad0[0x8];
    s32 src;            /* 0x08 */
    u8 pad0c[0x4];
    u32 type;           /* 0x10 */
    s16 start;          /* 0x14 */
    s16 end;            /* 0x16 */
    s16 len;            /* 0x18 */
    s16 fadeIn;         /* 0x1A */
    s16 fadeOut;        /* 0x1C */
    s16 id;             /* 0x1E */
    Vec pos;            /* 0x20 */
    Vec rotDeg;         /* 0x2C */
    AnimEnt anim[0x40]; /* 0x38 */
    s16 animA;          /* 0x138 */
    s16 animB;          /* 0x13A */
    Vec move;           /* 0x13C */
    Vec rotStep;        /* 0x148 */
    Vec sclStep;        /* 0x154 */
    s16 sclStart;       /* 0x160 */
    s16 sclCount;       /* 0x162 */
    Vec scl;            /* 0x164 */
    Vec sclStep2;       /* 0x170 */
    s16 sclStart2;      /* 0x17C */
    s16 sclCount2;      /* 0x17E */
    s16 snd[2];         /* 0x180 */
    f32 texStep;        /* 0x184 */
    s16 rotStart;       /* 0x188 */
    s16 rotEnd;         /* 0x18A */
    s16 x18c;           /* 0x18C */
    s16 moveStart;      /* 0x18E */
    s16 moveEnd;        /* 0x190 */
} Cmd_80045CD8;

typedef struct {
    s16 timer;          /* 0x00 */
    s16 count;          /* 0x02 */
    TaskRef* arg;       /* 0x04 */
    void* mtx;          /* 0x08 */
    f32 alpha;          /* 0x0C */
    s16 frame;          /* 0x10 */
    u8 pad12[2];
    f32 tex;            /* 0x14 */
    s16 sclCount;       /* 0x18 */
    s16 sclCount2;      /* 0x1A */
    Vec pos;            /* 0x1C */
    void* snd;          /* 0x28 */
    TexList* texlist;   /* 0x2C */
    u8 pad30[8];
    s32 x38;            /* 0x38 */
    u8 pad3c[4];
    f32 x40;            /* 0x40 */
    f32 x44;            /* 0x44 */
    Vec x48;            /* 0x48 */
    Vec x54;            /* 0x54 */
    u8 pad60[4];
    s32 sndLock;        /* 0x64 */
    Cmd_80045CD8* owner;         /* 0x68 */
} Sub_80045CD8;

typedef struct { u8 pad[8]; void* x8; u8 padc[0x3C - 0xC]; u32 flags; } Model_80045CD8;

typedef struct {
    void* model;        /* 0x00 */
    u8 pad4[4];
    void* x8;           /* 0x08 */
    TexList* texlist;   /* 0x0C */
    Model_80045CD8* x10;         /* 0x10 */
    u8 pad14[2];
    s16 x16;            /* 0x16 */
    u8 pad18[4];
    Vec pos;            /* 0x1C */
    s32 rot[3];         /* 0x28 */
    Vec scl;            /* 0x34 */
    u8 pad40[4];
    u8 kind;            /* 0x44 */
    u8 pad45[0x4C - 0x45];
    Sub_80045CD8* sub;           /* 0x4C */
    s32 x50;
    s32 x54;
} Work_80045CD8;

void fn_80045CD8(Node* node)
{
    Work_80045CD8* w = node->work;
    Sub_80045CD8* s = w->sub;
    u8 kind;
    s16 snd[2];
    void* tex;
    DrawState st;
    int flag2;
    int mode;

    switch (node->state) {
    case 0:
        fn_8006D954(s->owner->src);
        node->state = 1;
        ((Work_80045CD8*)node->work)->x50 = s->owner->src;
        ((Work_80045CD8*)node->work)->x54 = -1;
    case 1:
        if (s->timer >= s->owner->start) {
            fn_80040150(s->owner->type, s->arg, s->owner->id, &s->mtx);
            w->rot[0] = 182.04445f * s->owner->rotDeg.x;
            w->rot[1] = 182.04445f * s->owner->rotDeg.y;
            w->rot[2] = 182.04445f * s->owner->rotDeg.z;
            if (s->timer >= s->owner->len) {
                if (s->owner->fadeIn != 0) {
                    s->alpha = -1.0f + 1.0f / s->owner->fadeIn;
                } else {
                    s->alpha = -1.0f;
                }
            } else {
                s->alpha = -1.0f;
            }
            fn_80071CF0(&s->owner->scl, &w->scl);
            s->sclCount = s->owner->sclCount;
            s->sclCount2 = s->owner->sclCount2;
            fn_8006CEEC(w->x10->x8, &w->texlist, 0, w->x16);
            s->texlist = w->texlist;
            s->x40 = s->owner->texStep;
            if (s->owner->snd[0] != 0 || s->owner->snd[1] != 0) {
                sndAuxCallbackShutdownReverbSTD(w->model, &s->snd);
                fn_8022E8F8(w->model, 0);
            }
            fn_80071CF0(&s->owner->pos, &s->pos);
            if (s->owner->moveStart >= s->owner->moveEnd) {
                s->owner->moveEnd = s->owner->end;
            }
            node->state = 3;
        }
        break;
    case 3:
        fn_80071CF0(&s->pos, &s->x54);
        if ((s->owner->type & 0x04000000) || w->model == NULL) {
            if (w->texlist != NULL) {
                if (fn_80011984(&s->texlist) == 1 && !(s->owner->type & 0x08000000)) {
                    s->x44 = 0.0f;
                    s->x38 = 0;
                }
                fn_80071CF0(&s->x48, &s->pos);
                fn_80071CBC(&s->x54, &s->pos);
            }
        }
        if (s->timer >= s->owner->len && s->alpha < 0.0f && s->timer < s->owner->end) {
            s->alpha += 1.0f / s->owner->fadeIn;
            if (s->alpha > 0.0f) {
                s->alpha = 0.0f;
            }
        }
        if (s->timer >= s->owner->end && s->owner->start < s->owner->end) {
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
        if (s->mtx == NULL) {
            switch (s->owner->type & 0xF) {
            case 3:
                fn_8001E238(&s->pos, &w->pos, s->arg);
                break;
            case 0:
                fn_8001E4A0(&s->pos, &w->pos, s->arg);
                break;
            case 1:
                fn_80071CF0(&s->pos, &w->pos);
                break;
            }
        } else {
            fn_80071CF0(&s->pos, &w->pos);
        }
        fn_80071CF0(&s->x54, &s->pos);
        if ((s->owner->type & 0xF) != 3 && s->timer >= s->owner->moveStart &&
            s->timer < s->owner->moveEnd) {
            s->pos.x += s->owner->move.x;
            s->pos.y += s->owner->move.y;
            s->pos.z += s->owner->move.z;
        }
        if (s->owner->rotStart == s->owner->rotEnd ||
            (s->owner->rotEnd > s->timer && s->owner->rotStart <= s->timer)) {
            w->rot[0] += (s32)(182.04445f * s->owner->rotStep.x);
            w->rot[1] += (s32)(182.04445f * s->owner->rotStep.y);
            w->rot[2] += (s32)(182.04445f * s->owner->rotStep.z);
        }
        if (s->sclCount > 0 && s->timer >= s->owner->sclStart) {
            w->scl.x += s->owner->sclStep.x;
            w->scl.y += s->owner->sclStep.y;
            w->scl.z += s->owner->sclStep.z;
            s->sclCount--;
        }
        if (s->sclCount2 > 0 && s->timer >= s->owner->sclStart2) {
            w->scl.x += s->owner->sclStep2.x;
            w->scl.y += s->owner->sclStep2.y;
            w->scl.z += s->owner->sclStep2.z;
            s->sclCount2--;
        }
        if (w->scl.x < 0.0f) {
            w->scl.x = 0.0f;
        }
        if (w->scl.y < 0.0f) {
            w->scl.y = 0.0f;
        }
        if (w->scl.z < 0.0f) {
            w->scl.z = 0.0f;
        }
        s->frame = fn_800403AC(s->count, s->owner->anim, s->owner->animA, s->owner->animB);
        if (w->texlist != NULL && !(w->x10->flags & 0x40000000)) {
            s->tex += s->owner->texStep;
            if (s->tex >= (f32)w->texlist->n - 1.0f) {
                if (s->owner->type & 0x08000000) {
                    s->tex = (f32)w->texlist->n - 1.0f;
                } else {
                    s->tex = 0.0f;
                }
            }
        }
        if (s->owner->snd[0] != 0 || s->owner->snd[1] != 0) {
            if (s->sndLock != 0 || !(w->x10->flags & 0x80000000)) {
                if (s->sndLock == 0 && (s->owner->type & 0x20)) {
                    s->sndLock = 1;
                    w->x10->flags |= 0x80000000;
                }
                snd[0] = s->owner->snd[0];
                snd[1] = s->owner->snd[1];
                fn_8023080C(s->snd, snd, 0);
            }
        }
        fn_80032C6C(1, node);
        if ((s->owner->type & 0x04000000) || w->model == NULL) {
            flag2 = 0;
            if (s->owner->type & 0x20000000) {
                flag2 = 1;
            }
            if (s->frame < 0) {
                s->frame = 0;
            }
            if (s->owner->type & 0x80) {
                mode = 1;
            } else if (s->owner->type & 0x40) {
                mode = 2;
            } else if (s->owner->type & 0x10) {
                mode = 3;
            } else {
                mode = 0;
            }
            fn_80032E78(flag2, w, s->frame, s->alpha, s->mtx, s->owner->x18c, mode);
        } else {
            DrawStateDefault2D(&st);
            kind = w->kind;
            fn_80040044(&st, s->alpha, s->owner->type, &w->kind);
            switch (((Work_80045CD8*)node->work)->x50) {
            case 0x175130:
            case 0x17520A:
            case 0x1755DE:
            case 0x1D01C9:
            case 0x1D01CA:
            case 0x1D01CB:
            case 0x1D2CC1:
            case 0x1D2CC2:
                w->kind = 0;
                break;
            }
            if (DrawStatePush(&st) != 0) {
                fn_80032E44(w->x8);
                tex = NULL;
                fn_8006CEEC(w->x10->x8, &tex, 1, w->x16);
                flag2 = 0;
                if (s->owner->type & 0x2000) {
                    flag2 = 1;
                }
                fn_80034AF0(w, s->frame, s->mtx, w->texlist, tex, flag2, s->tex);
                DrawStatePop(NULL);
            }
            w->kind = kind;
        }
        fn_80032C6C(0, node);
        s->count++;
        break;
    case 0xF9:
    case 0xFA:
        if (s->sndLock != 0) {
            w->x10->flags &= ~0x80000000;
        }
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

typedef struct { u8 c[4]; } Col4;

typedef struct { s16 u, v; } UV;

typedef struct {
    s16 x0, y0, x1, y1; /* 0x00 */
    s16 id;             /* 0x08 */
    u8 pad0a[6];
    Col4 col[4];        /* 0x10 */
    UV uv[4];           /* 0x20 */
    void* data;         /* 0x30 */
} Rect2D_80046704;

typedef struct {
    u8 pad0[8];
    s32 src;            /* 0x08 */
    u8 pad0c[4];
    u32 type;           /* 0x10 */
    s16 start;          /* 0x14 */
    s16 end;            /* 0x16 */
    s16 len;            /* 0x18 */
    s16 fadeIn;         /* 0x1A */
    s16 fadeOut;        /* 0x1C */
    AnimEnt anim[0x40]; /* 0x1E */
    s16 animA;          /* 0x11E */
    s16 animB;          /* 0x120 */
    s16 dx;             /* 0x122 */
    s16 dy;             /* 0x124 */
    u8 b;               /* 0x126 */
    u8 g;               /* 0x127 */
    u8 r;               /* 0x128 */
} Obj_80046704;

typedef struct {
    s16 timer;          /* 0x00 */
    s16 count;          /* 0x02 */
    u8 pad4[4];
    f32 alpha;          /* 0x08 */
    s16 frame;          /* 0x0C */
    s16 ofsx;           /* 0x0E */
    s16 ofsy;           /* 0x10 */
    u8 pad12[2];
    Obj_80046704* owner;/* 0x14 */
} Sub_80046704;

typedef struct {
    u8 pad0[8];
    void* x8;
    u8 pad0c[0x4C - 0xC];
    Sub_80046704* sub;  /* 0x4C */
    s32 x50;
    s32 x54;
} Work_80046704;

void fn_80046704(Node* node)
{
    Work_80046704* w = node->work;
    Sub_80046704* s = w->sub;
    DrawState st;
    Rect2D_80046704 r;
    s32 save;

    switch (node->state) {
    case 0:
        fn_8006D954(s->owner->src);
        node->state = 1;
        ((Work_80046704*)node->work)->x50 = s->owner->src;
        ((Work_80046704*)node->work)->x54 = -1;
    case 1:
        if (s->timer >= s->owner->start) {
            if (s->timer >= s->owner->len) {
                if (s->owner->fadeIn != 0) {
                    s->alpha = -1.0f + 1.0f / s->owner->fadeIn;
                } else {
                    s->alpha = -1.0f;
                }
            } else {
                s->alpha = -1.0f;
            }
            node->state = 2;
        } else {
            break;
        }
    case 2:
        if (s->timer >= s->owner->len && s->alpha < 0.0f && s->timer < s->owner->end) {
            s->alpha += 1.0f / s->owner->fadeIn;
            if (s->alpha > 0.0f) {
                s->alpha = 0.0f;
            }
        }
        if (s->timer >= s->owner->end && s->owner->start < s->owner->end) {
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
        s->frame = fn_800403AC(s->count, s->owner->anim, s->owner->animA, s->owner->animB);
        DrawStateDefault2D(&st);
        if (s->owner->type & 0x20000000) {
            st.blend_src = 8;
            st.blend_dst = 10;
        }
        if (DrawStatePush(&st) != 0) {
            r.x0 = 0;
            r.y0 = 0;
            r.x1 = 640;
            r.y1 = 480;
            if (s->owner->type & 0x200000) {
                r.data = NULL;
                s->frame = 0;
            } else {
                r.data = w->x8;
                if (s->frame < 0) {
                    s->frame = 0;
                }
            }
            r.id = s->frame;
            r.col[0].c[0] = (s32)(255.0f * s->alpha) + 255;
            r.col[0].c[1] = s->owner->r;
            r.col[0].c[2] = s->owner->g;
            r.col[0].c[3] = s->owner->b;
            r.col[1].c[0] = (s32)(255.0f * s->alpha) + 255;
            r.col[1].c[1] = s->owner->r;
            r.col[1].c[2] = s->owner->g;
            r.col[1].c[3] = s->owner->b;
            r.col[2].c[0] = (s32)(255.0f * s->alpha) + 255;
            r.col[2].c[1] = s->owner->r;
            r.col[2].c[2] = s->owner->g;
            r.col[2].c[3] = s->owner->b;
            r.col[3].c[0] = (s32)(255.0f * s->alpha) + 255;
            r.col[3].c[1] = s->owner->r;
            r.col[3].c[2] = s->owner->g;
            r.col[3].c[3] = s->owner->b;
            s->ofsx += s->owner->dx;
            s->ofsy += s->owner->dy;
            if (s->ofsx < -255) {
                s->ofsx = 255;
            }
            if (s->ofsx > 255) {
                s->ofsx = -255;
            }
            if (s->ofsy < -255) {
                s->ofsy = 255;
            }
            if (s->ofsy > 255) {
                s->ofsy = -255;
            }
            r.uv[0].u = s->ofsx;
            r.uv[0].v = s->ofsy;
            r.uv[1].u = s->ofsx + 255;
            r.uv[1].v = s->ofsy;
            r.uv[2].u = s->ofsx + 255;
            r.uv[2].v = s->ofsy + 255;
            r.uv[3].u = s->ofsx;
            r.uv[3].v = s->ofsy + 255;
            fn_80047214(0);
            save = fn_800358F8();
            switch (w->x50) {
            case 0x19E15:
                fn_80035900(0x1000);
                break;
            default:
                fn_80035900(0x5000);
                break;
            }
            fn_800334B8(&r);
            fn_80035900(save);
            DrawStatePop(NULL);
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

u8 fn_80046BB0(char* s, s32* out)
{
    char digits[11] = "0123456789";
    char comp[7] = "abgABG";
    s16 j;
    s16 i;
    s16 k;
    s16 m;
    s16 n;
    s32 mul = 1000000;
    s32 val = 0;
    int ret = -1;

    switch (s[0]) {
    case 'P':
    case 'p':
        ret = 3;
        break;
    case 'C':
    case 'c':
        return 0;
    case 'M':
    case 'm':
        for (k = 0; k < 3; k++) {
            if (s[1] == comp[k] || s[1] == comp[k + 3]) {
                val += k * 1000;
                break;
            }
        }
        mul = 100;
        for (i = 2; i < 5; i++) {
            for (j = 0; j < 10; j++) {
                if (digits[j] == s[i]) {
                    val += mul * j;
                    break;
                }
            }
            mul /= 10;
        }
        val += 10000000;
        ret = 0;
        break;
    case 'E':
    case 'e':
        for (n = 1; n < 8; n++) {
            for (m = 0; m < 10; m++) {
                if (digits[m] == s[n]) {
                    val += mul * m;
                    break;
                }
            }
            mul /= 10;
        }
        ret = 1;
        break;
    case 'F':
    case 'f':
        ret = 2;
        break;
    case 'D':
    case 'd':
        if (s[1] == '0') {
            ret = 2;
        }
        break;
    }
    *out = val;
    return ret;
}

typedef struct { u8 pad[0x2C]; void* x2c; } Ptr2C_80046DE4;

typedef struct {
    u8 pad30[0x30];
    s32 x30;
    u32 x34;
    f32 x38;
} Blk3C_80046DE4;

typedef struct {
    u8 pad0[0x5C];
    void* x5c;          /* 0x5C */
    u8 pad60[0xDC - 0x60];
    u8* tbl;            /* 0xDC */
    u8 pade0[8];
    s16 xe8;            /* 0xE8 */
    s16 xea;            /* 0xEA */
    u8 padec[0x154 - 0xEC];
    void* x154;         /* 0x154 */
    void* x158;         /* 0x158 */
    u8 pad15c[0x164 - 0x15C];
    Blk3C_80046DE4 src;          /* 0x164 */
    u8 pad1a0[0];
} Sub_80046DE4;

typedef struct {
    u8 pad0[8];
    s32 x8;
    u8 pad0c[4];
    Ptr2C_80046DE4* x10;
    s16 x14;
    u8 pad16[0x28 - 0x16];
    s32 rx, ry, rz;     /* 0x28 */
    f32 sx, sy, sz;     /* 0x34 */
    u8 pad40[4];
    u8 x44;
    u8 pad45[0x4C - 0x45];
    Sub_80046DE4* sub;  /* 0x4C */
} Work_80046DE4;

void fn_80046DE4(Node* node, void* tex, void* p5, Vec* scl, u8* col, Vec* pos, s32 flag, f32 f29, f32 f30, f32 f31)
{
    Work_80046DE4* w = node->work;
    Sub_80046DE4* s = w->sub;
    u8 save = w->x44;
    DrawState st;

    if (p5 != NULL) {
        fn_80073F14(w->x10->x2c, s->x158, w->x14, p5, 0x100);
    }
    fn_80299040(tex);
    njPushMatrixEx();
    fn_80286EE8();
    fn_8028B498();
    njTranslate(NULL, pos->x, pos->y, pos->z);
    njRotateXYZ(NULL, w->rx, w->ry, w->rz);
    njScale(NULL, w->sx * scl->x, w->sy * scl->y, w->sz * scl->z);
    if (s->x5c != NULL) {
        DrawStateDefault2D(&st);
        fn_8007E678(s->x154, &st);
        if (st.colour.a > f30) {
            st.colour.a = f30;
        }
        if (col != NULL) {
            st.colour.r = -1.0f + col[1] / 255.0f;
            st.colour.g = -1.0f + col[2] / 255.0f;
            st.colour.b = -1.0f + col[3] / 255.0f;
        }
        if (flag != 0) {
            Blk3C_80046DE4* d = (Blk3C_80046DE4*)((u8*)s + 0x1A0);
            *d = s->src;
            d->x34 = (col[3] << 24) | (col[2] << 16) | (col[1] << 8) | 0xFF;
            d->x38 = f31;
            d->x30 = 1;
            fn_80060950(d);
        }
        if (f30 < 0.0f) {
            st.attr_or |= 0x300;
            w->x44 = 2;
        }
        if (DrawStatePush(&st) != 0) {
            u8* t = s->tbl + 8;
            if ((*(u32*)(t + s->xea * 0x18) & 0x200000) || (*(u32*)(t + s->xe8 * 0x18) & 0x200000)) {
                fn_8003529C(s->x158, s->x5c, w->x44, f29);
            } else {
                fn_80035380(s->x158, s->x5c, f29, w->x44);
            }
            fn_80018C94();
        }
        if (f30 < 0.0f) {
            w->x44 = save;
        }
    }
    njPopMatrixEx();
}

typedef struct {
    u8 pad0[4];
    NJS_POINT3 pos[4];  /* 0x04 */
    s16 id;             /* 0x34 */
    u8 pad36[2];
    s32 x38;            /* 0x38 */
    Col4 col[4];        /* 0x3C */
    UV uv[4];           /* 0x4C */
    void* data;         /* 0x5C */
} Quad3D_800470F0;

typedef struct {
    u8 pad0[0x6C];
    Col4 col[4];        /* 0x6C */
    u8 pad7c[4];
    void* x80;          /* 0x80 */
} QuadSrc_800470F0;

void fn_800470F0(QuadSrc_800470F0* src, NJS_POINT3* scl, void* data, UV* uv, NJS_POINT3* pos, f32 alpha)
{
    Quad3D_800470F0 q;
    s16 i;
    s16 a;
    s16 c;

    q.data = data;
    q.x38 = 0;
    q.id = 0;
    a = 255.0f * alpha;
    for (i = 0; i < 4; i++) {
        q.pos[i].x = scl->x * pos->x;
        q.pos[i].y = scl->y * pos->y;
        q.pos[i].z = scl->z * pos->z;
        c = src->col[i].c[0] + a;
        if (c < 0) {
            c = 0;
        }
        if (c > 255) {
            c = 255;
        }
        if (c > src->col[i].c[0]) {
            c = src->col[i].c[0];
        }
        q.col[i].c[0] = c;
        q.col[i].c[1] = src->col[i].c[1];
        q.col[i].c[2] = src->col[i].c[2];
        q.col[i].c[3] = src->col[i].c[3];
        q.uv[i].u = uv->u;
        q.uv[i].v = uv->v;
        uv++;
        pos++;
    }
    fn_80047214((u32)src->x80);
    fn_80033050(&q);
}


extern void fn_80296E4C(u32 v);
extern void fn_80296DC8(u32 v);
typedef struct {
    NJS_POINT3 a;     /* 0x00 start */
    NJS_POINT3 b;     /* 0x0C end */
    s16 s18;          /* 0x18 */
    u8 pad1a[2];
    u32 w1c;          /* 0x1C */
    u32 flags20;      /* 0x20 */
    f32 f24;          /* 0x24 */
    s16 n;            /* 0x28 point count */
    u16 u2a;          /* 0x2A */
    f32 f2c;          /* 0x2C */
    u32 flags30;      /* 0x30 */
    u8 pad34[4];
    f32 f38;          /* 0x38 */
    f32 f3c;          /* 0x3C */
    u8 c40;           /* 0x40 */
    u8 pad41;
    s16 s42;          /* 0x42 */
    NJS_POINT3* pts;  /* 0x44 */
} Line;
typedef struct {
    u8 kind;          /* 0x00 */
    u8 pad1[3];
    NJS_POINT3 p0;    /* 0x04 */
    NJS_POINT3 p1;    /* 0x10 */
    u8 pad1c[0x28 - 0x1C];
    f32 f28;          /* 0x28 */
    f32 f2c;          /* 0x2C */
    u8 pad30[4];
    s16 s34;          /* 0x34 */
    u8 pad36[2];
    s32 w38;          /* 0x38 */
    u8 col[4][4];     /* 0x3C */
    u32 w4c;          /* 0x4C */
} Seg;
void fn_800617A8(NJS_POINT3* out, Line* l, NJS_POINT3* p, f32 a, f32 b);
void fn_80033CF8(Seg* seg);
f32 njSin(Angle a);
typedef struct {
    u8 pad0[0xC];
    f32 a[3];   /* 0x0C */
    f32 b[3];   /* 0x18 */
    f32 out[3]; /* 0x24 */
    u8 pad30[0x3C - 0x30];
} Part_80047CF0;
typedef struct {
    u32 count;
    Part_80047CF0* parts;
} Parts;
typedef struct {
    void* a;
    void* b;
    void* c;
    u8 pad[0x3C - 0xC];
} Item;
typedef struct {
    u32 count;
    Item* items;
} Pool;
extern s32 fn_8022E734(u8 kind, void* p, void* a, void* b, s32 f1, s32 f2, s32 f3);
typedef struct {
    u32 count;
    u8* parts;
} ModelParts_80048040;
typedef struct ModelNode_80048040 ModelNode_80048040;
void fn_80230BD4(s32 a, ModelNode_80048040* node, s16** out, u16 idx);
void fn_80048654(u32 v, u8* part, u32* index, s32 flags, ModelNode_80048040* node);
typedef struct ModelNode_800481F4 {
    u8 pad0[4];
    void* mesh;            /* 0x04 */
    NJS_POINT3 pos;        /* 0x08 */
    Angle rot[3];          /* 0x14 */
    NJS_POINT3 scl;        /* 0x20 */
    struct ModelNode_800481F4* child;   /* 0x2C */
    struct ModelNode_800481F4* sibling; /* 0x30 */
} ModelNode_800481F4;
typedef struct {
    s32 count;
    void* parts;
} ModelParts_800481F4;
typedef struct {
    u32 count;
    void* parts;
} ModelParts_800482E0;
typedef struct ModelNode_800482E0 ModelNode_800482E0;
void njMultiMatrix(NJS_MATRIX m, NJS_MATRIX n);
void* fn_801E1A74(s32 count, s32 size);
typedef struct T800483EC {
    u8 pad0[4];
    void* x4;
    u8 pad8[0x2c - 8];
    struct T800483EC* x2c;
    struct T800483EC* x30;
} T800483EC;
extern s32 fn_80048570(s32*);
typedef struct {
    u8 pad0[4];
    void* x4;
} N80048B08;
extern u8 lbl_802DF030[];
extern int fn_80230D10(u8, N80048B08*, s16**);
typedef struct Q16 { s32 a, b, c, d; } Q16;
typedef struct { u8 b[0x4c]; } Blk4C;
typedef struct E80048C40 {
    u8 pad0[2];
    s16 x2;             /* 0x02 */
    NJS_POINT3 x4;      /* 0x04 */
    f32 x10;            /* 0x10 */
    s16 x14;            /* 0x14 */
    s16 x16;            /* 0x16 */
    f32 x18;            /* 0x18 */
    u8 pad1C[0x28 - 0x1c];
    f32* x28;           /* 0x28 */
    s32 x2c;            /* 0x2c */
    s32 x30;            /* 0x30 */
    Q16 x34;            /* 0x34 */
} E80048C40;
typedef struct W80048C40 {
    u8 pad0[0x1c];
    f32 px, py, pz;     /* 0x1c */
    s32 x28;            /* 0x28 */
    s32 x2c;            /* 0x2c */
    s32 x30;            /* 0x30 */
    u8 pad34[0x4c - 0x34];
    E80048C40* e;       /* 0x4c */
} W80048C40;
typedef struct { u8 pad[0x24]; W80048C40* work; } Node_80048C40;
typedef struct { s32 pad; Angle y; } RotParam;
typedef struct { s32 w[5]; } Q20;
typedef struct {
    Q20 q;              /* 0x00 */
    NJS_POINT3 v;       /* 0x14 */
    f32 f20;            /* 0x20 */
    u8 pad24[0x30 - 0x24];
} Buf_80048E58;
typedef struct E80048E58_80048E58 {
    u8 pad0[2];
    s16 x2;             /* 0x02 */
    s16 x4;             /* 0x04 */
    u8 pad6[0xc - 6];
    s32 xC;             /* 0x0c */
    void* x10;          /* 0x10 */
    s32 x14;            /* 0x14 */
    Buf_80048E58 buf;            /* 0x18 */
} E80048E58_80048E58;
typedef struct W80048E58_80048E58 {
    u8 pad0[0x10];
    char* x10;          /* 0x10 */
    u8 pad14[0x4c - 0x14];
    E80048E58_80048E58* e;       /* 0x4c */
} W80048E58_80048E58;
typedef struct I80048E58 {
    u8 pad0[4];
    s32 x4;             /* 0x04 */
    void* x8;           /* 0x08 */
    void* xC;           /* 0x0c */
    f32 x10;            /* 0x10 */
    u8 pad14[0x1c - 0x14];
    Q20 x1c;            /* 0x1c */
    u8 pad30[0x3c - 0x30];
    NJS_POINT3 x3c;     /* 0x3c */
    u8 pad48[0xaa - 0x48];
    s16 xaa;            /* 0xaa */
} I80048E58;
typedef struct { u8 pad[0x24]; void* work; } Node_80048E58;
typedef struct { u8 pad[0x24]; W80048E58_80048E58* work; } Node2_80048E58;
typedef struct NodeSrc { u8 pad[0x24]; struct { u8 pad[0x4c]; I80048E58* e; }* work; } NodeSrc;
typedef struct {
    Q16 q;              /* 0x00 */
    s32 w10;            /* 0x10 */
    NJS_POINT3 v;       /* 0x14 */
    u8 pad20[0x30 - 0x20];
} Buf_80049130;
typedef struct E80049130_80049130 {
    u8 pad0[2];
    s16 x2;             /* 0x02 */
    s16 x4;             /* 0x04 */
    u8 pad6[0xc - 6];
    s32 xC;             /* 0x0c */
    void* x10;          /* 0x10 */
    s32 x14;            /* 0x14 */
    Buf_80049130 buf;            /* 0x18 */
} E80049130_80049130;
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
typedef struct { u8 pad[0x10]; char* x10; u8 pad14[0x4c - 0x14]; E80049130_80049130* e; } W2_80049130;
typedef struct { u8 pad[0x24]; W2_80049130* work; } Node2_80049130;
typedef struct {
    Q20 q;              /* 0x00 */
    NJS_POINT3 v;       /* 0x14 */
    f32 f20;            /* 0x20 */
    s16 s24;            /* 0x24 */
    f32 f28;            /* 0x28 */
    s16 s2c;            /* 0x2c */
} Buf_800492C0;
typedef struct E800492C0_800492C0 {
    u8 pad0[2];
    s16 x2;             /* 0x02 */
    s16 x4;             /* 0x04 */
    u8 pad6[0xc - 6];
    s32 xC;             /* 0x0c */
    void* x10;          /* 0x10 */
    s32 x14;            /* 0x14 */
    Buf_800492C0 buf;            /* 0x18 */
} E800492C0_800492C0;
typedef struct { u8 pad[0x10]; char* x10; u8 pad14[0x4c - 0x14]; E800492C0_800492C0* e; } W2_800492C0;
typedef struct { u8 pad[0x24]; W2_800492C0* work; } Node2_800492C0;
typedef struct I800492C0 {
    u8 pad0[4];
    s32 x4;             /* 0x04 */
    void* x8;           /* 0x08 */
    f32 xC;             /* 0x0c */
    s16 x10;            /* 0x10 */
    u8 pad12[2];
    f32 x14;            /* 0x14 */
    u8 pad18[4];
    Q20 x1c;            /* 0x1c */
    u8 pad30[0x40 - 0x30];
    NJS_POINT3 x40;     /* 0x40 */
    u8 pad4C[0x19c - 0x4c];
    s16 x19c;           /* 0x19c */
    u8 pad19E[0x1ba - 0x19e];
    s16 x1ba;           /* 0x1ba */
} I800492C0;
typedef struct Node_800492C0 { u8 pad[0x24]; struct { u8 pad[0x4c]; I800492C0* e; }* work; } Node_800492C0;
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
typedef struct {
    u8 pad[0x18];
    u8 flags;
    u8 state;
    u8 pad1a[0x24 - 0x1A];
    Data_80049464* data;
} Node_80049464;
typedef struct {
    Vec_8004A40C pos;            /* 0x00 */
    Vec_8004A40C pos2;           /* 0x0C */
    s16 frame;          /* 0x18 */
    u8 pad1a[2];
    s32 src;            /* 0x1C */
    u32 type;           /* 0x20 */
    f32 x24;            /* 0x24 */
    s16 count;          /* 0x28 */
    u16 x2a;            /* 0x2A */
    f32 x2c;            /* 0x2C */
    u32 x30;            /* 0x30 */
    u32 x34;            /* 0x34 */
    f32 x38;            /* 0x38 */
    f32 x3c;            /* 0x3C */
    u8 alpha;           /* 0x40 */
    u8 pad41;
    s16 step;           /* 0x42 */
    void* buf;          /* 0x44 */
} Draw;
typedef struct {
    u8 pad[0x1C4];
    s32 nodes;          /* 0x1C4 */
} GameState_80049464;
typedef Col4 Col4_800498F0;

typedef struct {
    s16 x0, y0, x1, y1; /* 0x00 */
    s16 id;             /* 0x08 */
    u8 pad0a[6];
    Col4_800498F0 col[4];        /* 0x10 */
    UV uv[4];           /* 0x20 */
    void* data;         /* 0x30 */
} Rect2D_800498F0;
typedef struct {
    u8 pad0[8];
    s32 src;            /* 0x08 */
    u8 pad0c[4];
    u32 type;           /* 0x10 */
    s16 start;          /* 0x14 */
    s16 end;            /* 0x16 */
    s16 len;            /* 0x18 */
    s16 fadeIn;         /* 0x1A */
    s16 fadeOut;        /* 0x1C */
    AnimEnt_X anim[0x40]; /* 0x1E */
    s16 animA;          /* 0x11E */
    s16 animB;          /* 0x120 */
    u8 b;               /* 0x122 */
    u8 g;               /* 0x123 */
    u8 r;               /* 0x124 */
    u8 pad125[0x128 - 0x125];
} Cfg_800498F0;
typedef struct {
    s16 timer;          /* 0x00 */
    s16 count;          /* 0x02 */
    u8 pad4[4];
    f32 alpha;          /* 0x08 */
    s16 frame;          /* 0x0C */
    u8 pad0e[2];
    s32 held;           /* 0x10 */
    Cfg_800498F0* base;          /* 0x14 */
    Cfg_800498F0* copy;          /* 0x18 */
} Work_800498F0;
typedef struct {
    u8 pad0[8];
    void* tex;          /* 0x08 */
    u8 pad0c[0x4C - 0xC];
    Work_800498F0* work;         /* 0x4C */
    s32 x50;            /* 0x50 */
    s32 x54;            /* 0x54 */
} Data_800498F0;
typedef struct {
    u8 pad[0x18];
    u8 flags;
    u8 state;
    u8 pad1a[0x24 - 0x1A];
    Data_800498F0* data;
} Node_800498F0;
typedef struct {
    u8 pad0[0x6C];
    u32 input;          /* 0x6C */
    u8 pad70[0x1C4 - 0x70];
    s32 count;          /* 0x1C4 */
} GameState_800498F0;
typedef struct {
    u8 pad[0x68];
    f32 x68;            /* 0x68 */
    u8 pad6c[0x158 - 0x6C];
    void* x158;         /* 0x158 */
    u8 pad15c[0x1F4 - 0x15C];
    void* x1f4;         /* 0x1F4 */
} Body_80049DC0;
typedef struct {
    u8 pad0[0x8];
    void* tex;          /* 0x08 */
    u8 pad0c[0x10 - 0xC];
    struct { u8 pad[0x2C]; void* x2c; }* x10;
    s16 x14;            /* 0x14 */
    u8 pad16[0x1C - 0x16];
    u8 pos[0xC];        /* 0x1C */
    u8 pad28[0x4C - 0x28];
    Body_80049DC0* body;         /* 0x4C */
} Q_80049DC0;
typedef struct {
    u8 pad[0x24];
    Q_80049DC0* work;
} Node2_80049DC0;
typedef struct {
    u8 pad0[0x10];
    u32 flags;          /* 0x10 */
    u8 pad14[0x18 - 0x14];
    s16 x18;            /* 0x18 */
    u8 pad1a[2];
    u8 col[4];          /* 0x1C */
    u8 scl[0x2C - 0x20]; /* 0x20 */
    u8 x2c[0x50 - 0x2C];
    f32 x50;            /* 0x50 */
    s16 x54;            /* 0x54 */
} Ent;
typedef struct Data_80049DC0 {
    s16 timer;          /* 0x00 */
    u8 pad2[2];
    Node2_80049DC0* x4;          /* 0x04 */
    f32 x8;             /* 0x08 */
    f32 xc;             /* 0x0C */
    s16 x10;            /* 0x10 */
    s16 x12;            /* 0x12 */
    u8 pad14[0x60 - 0x14];
    Ent* ent;           /* 0x60 */
} Data_80049DC0;
typedef struct {
    u8 pad[0x18];
    u8 flags;
    u8 state;
    u8 pad1a[0x24 - 0x1A];
    struct Data_80049DC0* work;
} Node_80049DC0;
typedef struct {
    u8 pad[0x1C4];
    s32 count;
} GameState_80049DC0;
extern int fn_80056FC4(void*, s16);
typedef struct {
    u16 timer;          /* 0x00 */
    u16 pad2;
    u8 x4[0x14 - 0x4];  /* 0x04 */
    u16 t14;            /* 0x14 */
    u16 id14;           /* 0x16 */
    u16 t18;            /* 0x18 */
    u16 id18;           /* 0x1A */
    u16 t1c;            /* 0x1C */
    u16 id1c;           /* 0x1E */
    u16 t20;            /* 0x20 */
    u16 id20;           /* 0x22 */
    u16 flags;          /* 0x24 */
} Data_8004A028;
typedef struct {
    u8 pad[0x18];
    u8 flags;
    u8 state;
    u8 pad1a[0x24 - 0x1A];
    Data_8004A028* data;
} Node_8004A028;
typedef struct {
    u8 pad[0x6C];
    u32 input;          /* 0x6C */
    u8 pad70[0x1C4 - 0x70];
    s32 count;          /* 0x1C4 */
} GameState_8004A028;
extern void fn_8007E3A8(u16);
extern void fn_8007E2D8(u16);
extern void fn_8007E344(u16);
extern void fn_8007E274(u16);
extern void fn_8007E414(int);
extern void fn_8000CC84(int);
extern void fn_8003801C(void);
typedef struct {
    u8 pad0[0x70];
    s32 x70;            /* 0x70 */
    u8 pad74[0xF0 - 0x74];
    u32 flags;          /* 0xF0 */
} Ctl;
typedef struct {
    u8 pad0[0x8];
    void* tex;          /* 0x08 */
    u8 pad0c[0x48 - 0xC];
    void* x48;          /* 0x48 */
    Ctl* ctl;           /* 0x4C */
} Inner;
typedef struct {
    u8 pad[0x24];
    Inner* data;        /* 0x24 */
} Sub_8004A260;
typedef struct {
    u16 timer;          /* 0x00 */
    u8 pad2[2];
    Sub_8004A260* sub;           /* 0x04 */
    u8 x8[0x18];        /* 0x08 */
    u8 x20[0x120 - 0x20];
    s16 x120;           /* 0x120 */
    s16 x122;           /* 0x122 */
} Work_8004A260;
typedef struct {
    u8 pad0[0x8];
    void* x8;           /* 0x08 */
    u8 pad0c[0x4C - 0xC];
    Work_8004A260* work;         /* 0x4C */
} Data_8004A260;
typedef struct {
    u8 pad[0x18];
    u8 flags;
    u8 state;
    u8 pad1a[0x24 - 0x1A];
    Data_8004A260* data;
} Node_8004A260;
extern int fn_80015CFC(void*);
extern void fn_800350EC(void* a, u16 dst, void* b, u16 src);
typedef Buf Buf_8004A40C;
typedef struct { u32 w[4]; u32 flags; } Hdr;
typedef struct { Hdr hdr; Vec_8004A40C org; f32 f0; s16 s0; s16 pad0; f32 f1; s16 s1; s16 pad1; } Blk_8004A40C;
typedef struct {
    u8 pad0[0xF0];
    u32 flagsF0;
    u8 padF4[0x1EC - 0xF4];
    u32 flags1EC;
} TBody;
typedef struct { u8 pad[0x4C]; TBody* body; } TaskData_8004A40C;
typedef struct { u8 pad[0x24]; TaskData_8004A40C* data; } TaskRef_8004A40C;
typedef struct {
    s16 timer;          /* 0x00 */
    s16 count;          /* 0x02 */
    f32 x4;             /* 0x04 */
    TaskRef_8004A40C* task;      /* 0x08 */
    void* mtx;          /* 0x0C */
    f32 alpha;          /* 0x10 */
    s16 frame;          /* 0x14 */
    u8 pad16[2];
    f32 frameF;         /* 0x18 */
    Vec_8004A40C pos;            /* 0x1C */
    s32 snd;            /* 0x28 */
    Hdr hdr;            /* 0x2C */
    s16 start;          /* 0x40 */
    s16 x42;            /* 0x42 */
    s16 end;            /* 0x44 */
    s16 fadeStart;      /* 0x46 */
    s16 fadeIn;         /* 0x48 */
    s16 fadeOut;        /* 0x4A */
    s16 id;             /* 0x4C */
    u8 pad4e[2];
    Vec_8004A40C src;            /* 0x50 */
    Vec_8004A40C rotDeg;         /* 0x5C */
    Vec_8004A40C scale;          /* 0x68 */
    u8 pad74[0x174 - 0x74];
    s16 x174;           /* 0x174 */
    s16 x176;           /* 0x176 */
    f32 x178;           /* 0x178 */
    Vec_8004A40C rotVel;         /* 0x17C */
    f32 x188;           /* 0x188 */
    s16 x18c;           /* 0x18C */
    s16 x18e;           /* 0x18E */
    f32 frameStep;      /* 0x190 */
    s16 rotStart;       /* 0x194 */
    s16 rotEnd;         /* 0x196 */
    s16 interval;       /* 0x198 */
    s16 x19a;           /* 0x19A */
    s16 x19c;           /* 0x19C */
    s16 x19e;           /* 0x19E */
} Sub_8004A40C;

typedef ObjSrc ObjSrc_8004A40C;
typedef struct {
    void* model;        /* 0x00 */
    u8 pad4[4];
    void* texlist;      /* 0x08 */
    Motion* motion;     /* 0x0C */
    ObjSrc_8004A40C* src;        /* 0x10 */
    u8 pad14[2];
    s16 x16;            /* 0x16 */
    u8 pad18[4];
    Vec_8004A40C pos;            /* 0x1C */
    s32 ang[3];         /* 0x28 */
    Vec_8004A40C scl;            /* 0x34 */
    u8 pad40[4];
    u8 kind;            /* 0x44 */
    u8 pad45[7];
    Sub_8004A40C* sub;           /* 0x4C */
} Work_8004A40C;
typedef struct {
    u8 pad[0x18];
    u8 flags;
    u8 state;
    u8 pad1a[0x24 - 0x1A];
    Work_8004A40C* work;
} Node_8004A40C;
typedef struct {
    s16 timer;          /* 0x00 */
    s16 count;          /* 0x02 */
    s16 x4;             /* 0x04 */
    u8 pad6[6];
    void* parent;       /* 0x0C */
    void* copy;         /* 0x10 */
    s32 id;             /* 0x14 */
    Blk_8004A40C blk;            /* 0x18 */
} Child_8004A40C;
typedef struct { u8 pad[0x10]; void* x10; u8 pad14[0x4C - 0x14]; Child_8004A40C* sub; } ChildNode_8004A40C;
typedef struct { u8 pad[0x24]; ChildNode_8004A40C* work; } CNode_8004A40C;
typedef struct { u8 pad[0x1C4]; s32 count; } ObjStats_8004A40C;
extern Vec_8004A40C lbl_802AD360;
extern void fn_80060DFC(Vec_8004A40C*, Vec_8004A40C*, Vec_8004A40C*, f32, f32, f32);
typedef struct { u8 pad[0xF0]; u32 flags; u8 padF4[0x164 - 0xF4]; f32 gauge; } Body_8004AD38;
typedef struct { u8 pad[0x24]; struct { u8 pad[0x4C]; Body_8004AD38* body; }* data; } TaskRef_8004AD38;
typedef struct {
    u16 timer;          /* 0x00 */
    u8 pad2[6];
    TaskRef_8004AD38* target;    /* 0x08 */
    f32 inRate;         /* 0x0C */
    f32 outRate;        /* 0x10 */
    u8 sub[0x1C];       /* 0x14 */
    s16 outStart;       /* 0x30 */
    s16 outLen;         /* 0x32 */
    s16 inStart;        /* 0x34 */
    s16 inLen;          /* 0x36 */
} Work_8004AD38;
typedef struct {
    u8 pad[0x18];
    u8 flags;
    u8 state;
    u8 pad1a[0x24 - 0x1A];
    Work_8004AD38* work;
} Node_8004AD38;
typedef struct { u8 pad[0x1C4]; s32 count; } ObjStats_8004AD38;
extern int fn_8000F208(void*);
typedef Buf Buf_8004AFD8;
typedef struct { Hdr hdr; Vec_8004A40C org; f32 alpha; u8 pad[0xC]; } Blk_8004AFD8;
typedef struct {
    u8 pad0[4];
    u32 flags;          /* 0x04 */
    void* mtxSrc;       /* 0x08 */
    void* mtx;          /* 0x0C */
    f32 alpha;          /* 0x10 */
    u8 pad14[4];
    Hdr hdr;            /* 0x18 */
    u8 pad2c[4];
    Vec_8004A40C org;            /* 0x30 */
} Body_8004AFD8;
typedef struct { u8 pad[0x4C]; Body_8004AFD8* body; } TaskData_8004AFD8;
typedef struct { u8 pad[0x24]; TaskData_8004AFD8* data; } TaskRef_8004AFD8;
typedef struct {
    u16 timer;          /* 0x00 */
    u8 pad2[2];
    void* src;          /* 0x04 */
    TaskRef_8004AFD8* target;    /* 0x08 */
    f32 inRate;         /* 0x0C */
    f32 outRate;        /* 0x10 */
    u8 sub[0x10];       /* 0x14 */
    s16 spawnStart;     /* 0x24 */
    s16 spawnEnd;       /* 0x26 */
    s16 interval;       /* 0x28 */
    s16 x2a;            /* 0x2A */
    s16 x2c;            /* 0x2C */
    s16 x2e;            /* 0x2E */
    s16 outStart;       /* 0x30 */
    s16 outLen;         /* 0x32 */
    s16 inStart;        /* 0x34 */
    s16 inLen;          /* 0x36 */
    s16 mode;           /* 0x38 */
} Work_8004AFD8;
typedef struct {
    u8 pad[0x18];
    u8 flags;
    u8 state;
    u8 pad1a[0x24 - 0x1A];
    Work_8004AFD8* work;
} Node_8004AFD8;
typedef struct {
    u8 pad[0xC];
    void* parent;       /* 0x0C */
    void* copy;         /* 0x10 */
    s32 id;             /* 0x14 */
} _unused;
typedef struct {
    u8 pad0[2];
    s16 count;          /* 0x02 */
    s16 x4;             /* 0x04 */
    u8 pad6[6];
    void* parent;       /* 0x0C */
    void* copy;         /* 0x10 */
    s32 id;             /* 0x14 */
    Blk_8004AFD8 blk;            /* 0x18 */
} Child_8004AFD8;
typedef struct { u8 pad[0x10]; void* x10; u8 pad14[0x4C - 0x14]; Child_8004AFD8* sub; } ChildNode_8004AFD8;
typedef struct { u8 pad[0x24]; ChildNode_8004AFD8* work; } CNode_8004AFD8;
typedef struct { u8 pad[0x1C4]; s32 count; } ObjStats_8004AFD8;
extern int fn_8000FB4C(void*, void*, s16);
extern void fn_80076344(void*);
typedef struct {
    u8 pad[0x1C4];
    s32 count;
    s16 x1c8;
    s16 x1ca;
    u32 flags;
} ObjStats_8004B458;
typedef struct {
    u8 pad[0x18];
    u8 flags;
    u8 state;
    u8 pad1a[0x24 - 0x1A];
    void* work;
} Node_8004B458;
typedef struct {
    u8 pad0[6];
    s16 flags;
    s32 src;
    u8 pad0c[4];
} CmdHead_X;
typedef struct { u8 pad[0x8]; void* x8; } ObjSrc_8004B458;
typedef struct {
    s16 timer;      /* 0x00 */
    s16 start;      /* 0x02 */
    s16 life;       /* 0x04 */
    u8 pad6[2];
    f32 rate;       /* 0x08 */
    void* arg;      /* 0x0C */
    void* mtx;      /* 0x10 */
    s32 src;        /* 0x14 */
    CmdHead_X c;      /* 0x18 */
    u32 type;       /* 0x28 */
    Vec_8004A40C pos;        /* 0x2C */
    f32 alpha;      /* 0x38 */
    s16 frame;      /* 0x3C */
    u8 pad3e[2];
    f32 x40;        /* 0x40 */
    s16 x44;        /* 0x44 */
} Sub_8004B458;
typedef struct {
    void* x0;
    u8 pad4[4];
    void* texlist;  /* 0x08 */
    void* motion;   /* 0x0C */
    ObjSrc_8004B458* src;    /* 0x10 */
    u8 pad14[2];
    s16 x16;        /* 0x16 */
    u8 pad18[4];
    Vec_8004A40C ofs;        /* 0x1C */
    u8 pad28[0x44 - 0x28];
    u8 kind;        /* 0x44 */
    u8 pad45[0x4C - 0x45];
    Sub_8004B458* sub;       /* 0x4C */
    s32 x50;
    s32 x54;
} Work_8004B458;
typedef struct {
    u8 pad[0x1C4];
    s32 count;
    s16 x1c8;
    s16 x1ca;
    u32 flags;          /* 0x1CC */
} ObjStats_8004B7C4;
typedef struct {
    u8 pad[0x18];
    u8 flags;
    u8 state;
    u8 pad1a[0x24 - 0x1A];
    void* work;
} Node_8004B7C4;
typedef struct {
    s8 id;              /* 0x00 */
    u8 pad1[3];
    u8 id4;             /* 0x04 */
    u8 pad5[0x5A - 5];
    u8 cur;             /* 0x5A */
    u8 pad5b[0xEC - 0x5B];
    u32 fa;             /* 0xEC */
    u32 fb;             /* 0xF0 */
    u8 padf4[0x154 - 0xF4];
    void* body;         /* 0x154 */
} Chr;
typedef struct Tk_8004B7C4 Tk_8004B7C4;
typedef struct { u8 pad[0x4C]; Chr* chr; } TkData;
struct Tk_8004B7C4 { u8 pad[0x24]; TkData* data; };
typedef struct {
    u16 timer;          /* 0x00 */
    u8 pad2[2];
    Tk_8004B7C4* task;           /* 0x04 */
    void* mem;          /* 0x08 */
    s8 hit[0xE];        /* 0x0C */
    s16 x1a;
    s16 x1c;
    s32 x20;
    u8 pad24[0x2A - 0x24];
    s16 x2a;
    u8 pad2c[0x34 - 0x2C];
    u32 type;           /* 0x34 */
    s16 x38;
    s16 x3a;
    s16 x3c;
    u8 pad3e[2];
    Vec_8004A40C pos;            /* 0x40 */
    Vec_8004A40C vel;            /* 0x4C */
    u32 flags;          /* 0x58 */
} Work_8004B7C4;
typedef struct { u8 pad[0x24]; struct { u8 pad[0x3C]; u32 f; }* work; } Other;
extern Other* lbl_80347394;
extern u32 lbl_803472F4;
extern void fn_80017778(void);
extern int fn_80018398(Vec_8004A40C*, int);
extern void fn_800341B0(Vec_8004A40C*, u8, u8);
extern s32 fn_8001DC7C(int, void*);
extern void* fn_80021658(int);
extern int fn_80075FF0(void*, int, int);
extern int fn_8001D944(int, void*);
typedef struct Unit_8004BFD8 {
    u8 pad0[0x5A];
    u8 id;                  /* 0x5A */
    u8 pad5B[0xEC - 0x5B];
    u32 flagsEC;            /* 0xEC */
    u32 flagsF0;            /* 0xF0 */
} Unit_8004BFD8;
typedef struct Wrk_8004BFD8 {
    u8 pad0[0x4C];
    Unit_8004BFD8* unit;             /* 0x4C */
} Wrk_8004BFD8;
typedef struct Tk_8004BFD8 {
    u8 pad0[0x24];
    Wrk_8004BFD8* work;              /* 0x24 */
} Tk_8004BFD8;
typedef struct { u8 pad[0x50]; u32 x50; u8 pad54[0xEC - 0x54]; u32 xec; } Body_8004C070;
typedef struct { u8 pad[0x4C]; Body_8004C070* body; } TaskData_8004C070;
typedef struct { u8 pad[0x24]; TaskData_8004C070* data; } TaskRef_8004C070;
typedef struct {
    s16 timer;          /* 0x00 */
    u8 pad2[2];
    TaskRef_8004C070* arg;       /* 0x04 */
    u8 pad8[0x54 - 0x8];
    u8 cmd[0x10];       /* 0x54 */
    u32 flags;          /* 0x64 */
    s16 x68;
    s16 x6a;
} Work_8004C070;
typedef struct {
    u8 pad[0x18];
    u8 flags;
    u8 state;
    u8 pad1a[0x24 - 0x1A];
    Work_8004C070* work;
} Node_8004C070;
typedef struct {
    u8 pad[0x1C4];
    s32 count;
} ObjStats_8004C070;
typedef struct {
    u8 pad0[0x18];
    f32 x18, x1c, x20;      /* 0x18 */
    f32 vx, vy, vz;         /* 0x24 */
    f32 c0, c1, c2;         /* 0x30 */
} P;
typedef struct {
    s16 timer;              /* 0x00 */
    s16 count;              /* 0x02 */
    u8 pad4[0x10 - 4];
    f32 grav;               /* 0x10 */
    s16 fade;               /* 0x14 */
    s16 end;                /* 0x16 */
    f32 alpha;              /* 0x18 */
    f32 step;               /* 0x1C */
    u32 n;                  /* 0x20 */
    P* p;                   /* 0x24 */
    void* buf;              /* 0x28 */
    s32 src;                /* 0x2C */
    s32 colmode;            /* 0x30 */
    u8 cmd[1];              /* 0x34 */
} Sub_8004CF14;
typedef struct {
    s32 x0;
    u8 pad4[4];
    void* x8;
    u8 padc[0x10];
    Vec_8004A40C v;                  /* 0x1C */
    s32 a, b, c;            /* 0x28 */
    u8 q[1];                /* 0x34 */
    u8 pad35[0x4C - 0x35];
    Sub_8004CF14* sub;               /* 0x4C */
    s32 x50;
    s32 x54;
} Work_8004CF14;
typedef struct {
    u8 pad[0x18];
    u8 flags;
    u8 state;
    u8 pad1a[0x24 - 0x1A];
    Work_8004CF14* work;
} Node_8004CF14;
typedef struct {
    u8 pad[0x1C4];
    s32 count;
} ObjStats_8004CF14;
extern void fn_800472DC(void*, s16, s32, void*);
typedef struct { u8 pad[0x24]; void* data; } TaskRef_8004D378;
typedef struct {
    u8 pad0[8];
    s32 src;                /* 0x08 */
    u8 pad0c[4];
    u32 type;               /* 0x10 */
    s16 start;              /* 0x14 */
    s16 end;                /* 0x16 */
    s16 len;                /* 0x18 */
    s16 fadeIn;             /* 0x1A */
    s16 fadeOut;            /* 0x1C */
    u8 pad1e[2];
    Vec_8004A40C from;               /* 0x20 */
    Vec_8004A40C delta;              /* 0x2C */
    s16 x38;                /* 0x38 */
    s16 count;              /* 0x3A */
    Vec_8004A40C pts[4];             /* 0x3C */
    u8 pad6c[0x7C - 0x6C];
    s16 dx;                 /* 0x7C */
    s16 dy;                 /* 0x7E */
} Obj_X;
typedef struct {
    s16 timer;              /* 0x00 */
    s16 count;              /* 0x02 */
    s16 ctr;                /* 0x04 */
    u8 pad6[2];
    TaskRef_8004D378* arg;           /* 0x08 */
    f32 alpha;              /* 0x0C */
    s16 uv[8];              /* 0x10 */
    Vec_8004A40C pos[4];             /* 0x20 */
    Obj_X* owner;             /* 0x50 */
} Sub_8004D378;
typedef struct {
    u8 pad0[8];
    s32 x8;                 /* 0x08 */
    u8 pad0c[0x34 - 0xC];
    Vec_8004A40C v;                  /* 0x34 */
    u8 pad40[0x4C - 0x40];
    Sub_8004D378* sub;               /* 0x4C */
    s32 x50;
    s32 x54;
} Work_8004D378;
typedef struct {
    u8 pad[0x18];
    u8 flags;
    u8 state;
    u8 pad1a[0x24 - 0x1A];
    Work_8004D378* work;
} Node_8004D378;
typedef struct {
    u8 pad[0x1C4];
    s32 count;
} ObjStats_8004D378;
extern void fn_800339B0(void* out, s16 idx);
typedef struct {
    u8 pad0[0x6C];
    u32 flags;                  /* 0x06C */
    u8 pad70[0x188 - 0x70];
    u32 col;                    /* 0x188 */
    u8 pad18c[0x1C4 - 0x18C];
    s32 count;                  /* 0x1C4 */
} GState;
typedef struct {
    u8 pad0[6];
    s16 flags;                  /* 0x06 */
    s32 src;                    /* 0x08 */
    u8 padc[4];
    u8 alpha;                   /* 0x10 */
    u8 c1;                      /* 0x11 */
    u8 c2;                      /* 0x12 */
    u8 c3;                      /* 0x13 */
    f32 init;                   /* 0x14 */
    f32 max;                    /* 0x18 */
    f32 rise;                   /* 0x1C */
    f32 fall;                   /* 0x20 */
    s16 riseStart;              /* 0x24 */
    s16 riseEnd;                /* 0x26 */
    s16 fallStart;              /* 0x28 */
    s16 fallEnd;                /* 0x2A */
} Cmd_8004D828;
typedef struct {
    u8 pad0[0x164];
    f32 scale;                  /* 0x164 */
    u8 pad168[0x194 - 0x168];
    s32 on;                     /* 0x194 */
    u32 col;                    /* 0x198 */
    f32 val;                    /* 0x19C */
} Unit_8004D828;
typedef struct { u8 pad0[0x24]; struct { u8 pad[0x4C]; Unit_8004D828* w; }* work; } Owner_8004D828;
typedef struct {
    u16 timer;                  /* 0x00 */
    s16 sub;                    /* 0x02 */
    s32 flags;                  /* 0x04 */
    Owner_8004D828* owner;               /* 0x08 */
    Cmd_8004D828* cmd;                   /* 0x0C */
} Wk_8004D828;
typedef struct {
    u8 pad0[0x18];
    u8 flags;                   /* 0x18 */
    u8 state;                   /* 0x19 */
    u8 pad1a[0xA];
    Wk_8004D828* work;                   /* 0x24 */
} Node_8004D828;
typedef NJS_POINT3 V3;
typedef struct { V3* data; u32 count; } VArr;
typedef struct { u8 pad0[0x1F4]; VArr* x1f4; } Unit_8004DB90;
typedef struct { u8 pad0[8]; VArr* arr; u8 pad0c[0x4C - 0xC]; Unit_8004DB90* w; } TW_8004DB90;
typedef struct { u8 pad0[0x18]; u8 flags; u8 state; u8 pad1a[0xA]; TW_8004DB90* work; } TkN_8004DB90;
typedef struct { u8 pad0[8]; s32 src; } Cmd_8004DB90;
typedef struct { TkN_8004DB90* t; Cmd_8004DB90* cmd; } Own_8004DB90;
typedef struct { u8 pad0[8]; V3** v; u8 padc[0x4C - 0xC]; Own_8004DB90* own; s32 x50; s32 x54; } Wk_8004DB90;
typedef struct { u8 pad0[0x18]; u8 flags; u8 state; u8 pad1a[0xA]; Wk_8004DB90* work; } Node_8004DB90;
s32 x1c4;
typedef struct { u8 a, b, c, d; } Col4_8004DE48;
typedef ObjSrc ObjSrc_8004DE48;
typedef struct {
    s8 id;
    u8 pad1[3];
    s8 x4;
    u8 pad5[0xEC - 5];
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

void fn_80047214(u32 flags);
void fn_8004754C(Line* l, f32 a1, f32 a2);
void fn_80047CF0(Parts* parts, NJS_POINT3* pos, f32* dir, NJS_MATRIX m);
void fn_80047EDC(Pool* pool);
s32 fn_80047F9C(void* p);
s16 fn_80048040(ModelParts_80048040* parts, ModelNode_80048040* node, u32* index);
void fn_800481F4(ModelParts_800481F4* parts, ModelNode_800481F4* node, s32* index);
s32 fn_800482E0(ModelParts_800482E0* parts, ModelNode_800482E0* node, NJS_POINT3* pos, Angle* rot, NJS_POINT3* scl, NJS_MATRIX mtx);
void fn_800483EC(T800483EC* a, s32* out);
int fn_80048B08(N80048B08* node, f32* out, s16 idx);
void fn_80048C40(W80048C40* src, f32* mat, s16 a, f32 f1, NJS_POINT3* pt, s16 b, s16 c, s32 d, Q16* q, f32 f2);
void fn_80048DF0(NJS_MATRIX m, NJS_VECTOR* v, RotParam* r, s32 a);
void fn_80048E58(NodeSrc* node);
void fn_80049130(Node_80049130* node);
void fn_800492C0(Node_800492C0* node);
void fn_80049464(Node_80049464* node);
void fn_800498F0(Node_800498F0* node);
void fn_80049DC0(Node_80049DC0* node);
void fn_8004A028(Node_8004A028* node);
void fn_8004A260(Node_8004A260* node);
void fn_8004A40C(Node_8004A40C* node);
void fn_8004AD38(Node_8004AD38* n);
void fn_8004AFD8(Node_8004AFD8* node);
void fn_8004B458(Node_8004B458* node);
void fn_8004B7C4(Node_8004B7C4* node);
void fn_8004BFD8(Tk_8004BFD8* t);
void fn_8004C070(Node_8004C070* node);
void fn_8004CF14(Node_8004CF14* node);
void fn_8004D378(Node_8004D378* node);
void fn_8004D828(Node_8004D828* node);
void fn_8004DB90(Node_8004DB90* node);
void fn_8004DE48(Node_8004DE48* node);
void fn_8004F84C(NJS_VECTOR* v);
void fn_80047214(u32 flags) {
    u32 hi = flags & 0x80000000;
    u32 mid;
    if (hi && (flags & 0x40000000)) {
        fn_80296E4C(0x18000);
    } else if (hi) {
        fn_80296E4C(0x10000);
    } else if (flags & 0x40000000) {
        fn_80296E4C(0x8000);
    } else {
        fn_80296E4C(0);
    }
    mid = flags & 0x20000000;
    if (mid && (flags & 0x10000000)) {
        fn_80296DC8(0x60000);
    } else if (mid) {
        fn_80296DC8(0x40000);
    } else if (flags & 0x10000000) {
        fn_80296DC8(0x20000);
    } else {
        fn_80296DC8(0);
    }
}

void fn_8004754C(Line* l, f32 a1, f32 a2) {
    Seg seg;
    DrawState ds;
    NJS_POINT3 p;
    NJS_POINT3 q;
    f32 dy;
    f32 dx;
    f32 dang;
    f32 ang;
    f32 dz;
    s32 j;
    u16 i;
    u16 k;
    u16 m;
    u8 step;

    dang = 180.0f / (f32)l->n;
    l->pts[0].x = l->a.x;
    l->pts[0].y = l->a.y;
    l->pts[0].z = l->a.z;
    dx = (l->b.x - l->a.x) / (f32)(l->n - 1);
    dy = (l->b.y - l->a.y) / (f32)(l->n - 1);
    dz = (l->b.z - l->a.z) / (f32)(l->n - 1);
    ang = 0.0f;
    fn_80071CF0(&l->a, &p);
    for (m = 1; (j = m) < l->n - 1; m++) {
        p.x += dx;
        p.y += dy;
        p.z += dz;
        ang += dang;
        ((f32*)l->pts)[m * 3 + 0] = p.x;
        ((f32*)l->pts)[m * 3 + 1] = p.y;
        ((f32*)l->pts)[m * 3 + 2] = p.z;
        fn_800617A8(&q, l, &l->b, l->f24, ang);
        ((f32*)l->pts)[m * 3 + 1] += q.y;
    }
    l->pts[j].x = l->b.x;
    l->pts[j].y = l->b.y;
    l->pts[j].z = l->b.z;
    DrawStateDefault2D(&ds);
    if (l->flags20 & 0x20000000) {
        ds.blend_src = 8;
        ds.blend_dst = 10;
    }
    if (DrawStatePush(&ds)) {
        memset(&seg, 0, sizeof(Seg));
        seg.s34 = l->s18;
        seg.kind = 2;
        seg.w38 = 0;
        seg.f28 = l->f38;
        seg.f2c = l->f3c;
        seg.w4c = l->w1c;
        seg.col[0][0] = l->c40;
        seg.col[0][1] = 255;
        seg.col[0][2] = 255;
        seg.col[0][3] = 255;
        seg.col[1][0] = l->c40;
        seg.col[1][1] = 255;
        seg.col[1][2] = 255;
        seg.col[1][3] = 255;
        seg.col[2][0] = l->c40;
        seg.col[2][1] = 255;
        seg.col[2][2] = 255;
        seg.col[2][3] = 255;
        seg.col[3][0] = l->c40;
        seg.col[3][1] = 255;
        seg.col[3][2] = 255;
        seg.col[3][3] = 255;
        for (i = 0; (j = i) < l->n - 1; i++) {
            njSin((Angle)(182.04445f * (f32)(l->s42 * 7 + j * 27)));
            if (l->flags30 & 0x20000000) {
                step = l->c40 / l->n;
                for (k = 0; k < 4; k++) {
                    switch (k) {
                    case 0:
                    case 1:
                        seg.col[k][0] = seg.col[2][0];
                        break;
                    case 2:
                        if (seg.col[k][0] >= step) {
                            seg.col[k][0] -= step;
                        }
                        break;
                    case 3:
                        seg.col[k][0] = seg.col[2][0];
                        break;
                    }
                }
            }
            seg.p0.x = ((f32*)l->pts)[i * 3];
            seg.p0.y = ((f32*)l->pts)[i * 3 + 1];
            seg.p0.z = ((f32*)l->pts)[i * 3 + 2];
            if (i != 0) {
                seg.p0.y = l->f2c * njSin((Angle)(182.04445f * (f32)(l->s42 + j * l->u2a))) + seg.p0.y;
            }
            seg.p1.x = ((f32*)l->pts)[j * 3 + 3];
            seg.p1.y = ((f32*)l->pts)[j * 3 + 4];
            seg.p1.z = ((f32*)l->pts)[j * 3 + 5];
            if (j < l->n - 2) {
                seg.p1.y = l->f2c * njSin((Angle)(182.04445f * (f32)(l->s42 + (j + 1) * l->u2a))) + seg.p1.y;
            }
            fn_80033CF8(&seg);
        }
        fn_80018C94();
    }
}

void fn_80047CF0(Parts* parts, NJS_POINT3* pos, f32* dir, NJS_MATRIX m) {
    NJS_POINT3 w;
    NJS_POINT3 p;
    NJS_POINT3 q;
    Part_80047CF0* e;
    u32 n;
    u32 i;
    f32 scale;

    if (m != 0) {
        p.x = pos->x;
        p.y = pos->y;
        p.z = pos->z;
        njCalcPoint(m, &p, &q);
        w.x = q.x;
        w.y = q.y;
        w.z = q.z;
    } else {
        fn_80071CF0(pos, &w);
    }
    e = parts->parts;
    for (n = 0; n < parts->count; e++, n++) {
        f32* wp = &w.x;
        i = 3;
        while (i-- != 0) {
            if (dir[0] < 0.0f || dir[1] < 0.0f || dir[2] < 0.0f) {
                e->out[i] = wp[i] - e->b[i];
            } else {
                e->out[i] = e->b[i] - wp[i];
            }
        }
        fn_80072130(e->out);
        scale = 2.0f * (0.000030517578f * (f32)fn_8025ECC4());
        i = 3;
        while (i-- != 0) {
            e->out[i] = e->out[i] * scale;
            if (dir[i] < 0.0f) {
                e->out[i] = e->out[i] * -dir[i];
            } else {
                e->out[i] = e->out[i] * dir[i];
            }
        }
    }
}

void fn_80047EDC(Pool* pool) {
    if (pool && pool->items) {
        Item* it = pool->items;
        u32 i = 0;
        while (i < pool->count) {
            if (it->a) fn_801E17E0(it->a);
            if (it->b) fn_801E17E0(it->b);
            if (it->c) fn_801E17E0(it->c);
            memset(it, 0, 0x3C);
            it++;
            i++;
        }
        fn_801E17E0(pool->items);
        memset(pool, 0, 8);
    }
}

s32 fn_80047F9C(void* p) {
    s32 b;
    s32 a;
    s32 count = 0;
    if (fn_8022E734(8, p, &a, &b, 1, 0, 0)) {
        a = b;
        count = 1;
        while (fn_8022E734(8, p, &a, &b, 0, 0, 0)) {
            a = b;
            count++;
        }
    }
    return count;
}

s16 fn_80048040(ModelParts_80048040* parts, ModelNode_80048040* node, u32* index) {
    u32 next2;
    u32 cur2;
    u32 cur;
    u32 next;
    s16* p;
    s32 flags;
    u8* part;
    s16 n;
    s16 j;
    u16 i;
    u8 key;

    key = 0x40;
    n = 0;
    if (fn_8022E734(8, node, &cur, &next, 1, 0, 0)) {
        n = 1;
        cur = next;
        while (fn_8022E734(8, node, &cur, &next, 0, 0, 0)) {
            n++;
            cur = next;
        }
    }
    if (n == 0) {
        return 0;
    }
    for (i = 0x40; i < 0xff; i++) {
        if (fn_8022E734(i, node, &cur2, &next2, 1, 0, 0)) {
            key = i;
            break;
        }
    }
    for (j = 0; j < n; j++) {
        p = 0;
        fn_80230BD4(8, node, &p, j + 1);
        if (p == 0) {
            flags = 0;
        } else {
            p++;
            flags = *p & 0x1fff;
        }
        part = parts->parts + *index * 0x3c;
        if (fn_8022E734(key, node, &cur2, &next2, 0, 0, 0)) {
            fn_80048654(cur2, part, index, flags, node);
            cur2 = next2;
        }
    }
    return n;
}

void fn_800481F4(ModelParts_800481F4* parts, ModelNode_800481F4* node, s32* index) {
    njPushMatrixEx();
    fn_80286EE8();
    fn_8028B498();
    njTranslate(0, node->pos.x, node->pos.y, node->pos.z);
    njRotateXYZ(0, node->rot[0], node->rot[1], node->rot[2]);
    njScale(0, node->scl.x, node->scl.y, node->scl.z);
    if (node->mesh != 0) {
        fn_80048040((ModelParts_80048040*)parts, (ModelNode_80048040*)node, (u32*)index);
    }
    if (node->child != 0) {
        fn_800481F4(parts, node->child, index);
    }
    if (node->sibling != 0) {
        njPopMatrixEx();
        fn_800481F4(parts, node->sibling, index);
        njPushMatrixEx();
        fn_80286EE8();
        fn_8028B498();
    }
    njPopMatrixEx();
}

s32 fn_800482E0(ModelParts_800482E0* parts, ModelNode_800482E0* node, NJS_POINT3* pos, Angle* rot, NJS_POINT3* scl,
                NJS_MATRIX mtx) {
    u32 index;
    void* mem;
    parts->count = 0;
    fn_800483EC((T800483EC*)node, (s32*)parts);
    parts->parts = 0;
    mem = fn_801E1A74(parts->count, 0x3c);
    parts->parts = mem;
    if (mem == 0) {
        while (1) {
        }
    }
    njPushMatrixEx();
    fn_80286EE8();
    fn_8028B498();
    njUnitMatrix(0);
    if (mtx != 0) {
        njMultiMatrix(0, mtx);
    }
    njTranslate(0, pos->x, pos->y, pos->z);
    njRotateXYZ(0, rot[0], rot[1], rot[2]);
    njScale(0, scl->x, scl->y, scl->z);
    index = 0;
    fn_800481F4((ModelParts_800481F4*)parts, (ModelNode_800481F4*)node, (s32*)&index);
    if (index != parts->count) {
        while (1) {
        }
    }
    njPopMatrixEx();
    return 1;
}

void fn_800483EC(T800483EC* a, s32* out) {
    s32 v14;
    s32 v10;
    s32 vc;
    s32 v8;
    s16 cnt;
    s16 j;
    u16 i;
    u8 found = 0x40;

    if (a->x4 != 0) {
        cnt = 0;
        if (fn_8022E734(8, a, &vc, &v8, 1, 0, 0)) {
            cnt = 1;
            vc = v8;
            while (fn_8022E734(8, a, &vc, &v8, 0, 0, 0)) {
                cnt++;
                vc = v8;
            }
        }
        if (cnt != 0) {
            for (i = 0x40; i < 0xff; i++) {
                if (fn_8022E734(i, a, &v10, &v14, 1, 0, 0)) {
                    found = i;
                    break;
                }
            }
        }
        for (j = 0; j < cnt; j++) {
            if (fn_8022E734(found, a, &v10, &v14, 0, 0, 0)) {
                *out += fn_80048570((s32*)v10);
                v10 = v14;
            }
        }
    }
    if (a->x2c != 0) {
        fn_800483EC(a->x2c, out);
    }
    if (a->x30 != 0) {
        fn_800483EC(a->x30, out);
    }
}

int fn_80048B08(N80048B08* node, f32* out, s16 idx) {
    s16* p;
    f32* data;
    u16 i;
    s16 type;
    u16 k;
    u8* tp;
    s16 count;
    u8 len;

    if (node->x4 == 0) {
        return 0;
    }
    for (i = 0x20; i < 0x38; i++) {
        if (fn_80230D10(i, node, &p)) {
            i = 0x39;
        }
    }
    if (i == 0x38) {
        return 0;
    }
    p++;
    type = *p++;
    count = *p++;
    p++;
    data = (f32*)p;
    tp = lbl_802DF030 + (u8)type - 0x20;
    for (k = 0; k < count; k++) {
        len = *tp;
        out[0] = data[0];
        out[1] = data[1];
        out[2] = data[2];
        data += 3;
        if (k == idx) {
            return 1;
        }
        data += len - 3;
    }
    return 0;
}

void fn_80048C40(W80048C40* src, f32* mat, s16 a, f32 f1, NJS_POINT3* pt, s16 b, s16 c, s32 d, Q16* q, f32 f2) {
    NJS_POINT3 t;
    Node_80048C40* node;
    W80048C40* w;
    E80048C40* e;

    node = fn_8003DB34(fn_8004CF14);
    fn_80061F58(&node->work, 0x58, 0);
    w = node->work;
    *(Blk4C*)w = *(Blk4C*)src;
    fn_80061F58(&w->e, 0x44, 0);
    e = w->e;
    e->x2 = a;
    fn_80071CF0(pt, &e->x4);
    e->x10 = f1;
    e->x14 = b;
    e->x18 = f2;
    e->x16 = c;
    e->x2c = q->c;
    e->x34 = *q;
    if (mat != 0) {
        e->x28 = fn_801E1C7C(0x40);
        memcpy(e->x28, mat, 0x40);
    } else {
        e->x28 = fn_801E1C7C(0x40);
        mat = e->x28;
        t.x = src->px;
        t.y = src->py;
        t.z = src->pz;
        njUnitMatrix(mat);
        njTranslateV(mat, &t);
        njRotateY(mat, src->x2c);
        w->px = 0.0f;
        w->py = 0.0f;
        w->pz = 0.0f;
        w->x28 = 0;
        w->x2c = 0;
        w->x30 = 0;
    }
    e->x30 = d;
}

void fn_80048DF0(NJS_MATRIX m, NJS_VECTOR* v, RotParam* r, s32 a) {
    NJS_VECTOR t;
    t.x = v->x;
    t.y = v->y;
    t.z = v->z;
    njUnitMatrix(m);
    njTranslateV(m, &t);
    njRotateY(m, r->y);
}

static inline void Spawn_80048E58(NodeSrc* src, Buf_80048E58* buf, s32 v4, void* mat, s16 rot) {
    Node2_80048E58* n;
    W80048E58_80048E58* w;
    E80048E58_80048E58* e;
    s32 hash;

    n = fn_8003DB34(fn_8004B458);
    fn_80061F58(&n->work, 0x58, 0);
    w = n->work;
    *(Blk4C*)w = *(Blk4C*)src->work;
    fn_80061F58(&w->e, 0x48, 0);
    e = w->e;
    e->buf = *buf;
    e->xC = v4;
    if (mat != 0) {
        e->x10 = fn_801E1C7C(0x40);
        memcpy(e->x10, mat, 0x40);
    }
    e->x2 = 0;
    e->x4 = rot;
    fn_80046BB0(w->x10 + 0xc, &hash);
    e->x14 = hash;
}

void fn_80048E58(NodeSrc* node) {
    Buf_80048E58 buf;
    I80048E58* inner;

    memset(&buf, 0, 0x30);
    inner = node->work->e;
    buf.q = inner->x1c;
    fn_80071CF0(&inner->x3c, &buf.v);
    buf.f20 = inner->x10;
    if (inner->xC != 0) {
        buf.v.x = 0.0f;
        buf.v.y = 0.0f;
        buf.v.z = 0.0f;
        Spawn_80048E58(node, &buf, inner->x4, inner->xC, inner->xaa);
    } else {
        Spawn_80048E58(node, &buf, inner->x4, inner->x8, inner->xaa);
    }
}

static inline void Spawn_80049130(Node_80049130* src, Buf_80049130* buf, s32 v4, void* mat, s16 rot) {
    Node2_80049130* n;
    W2_80049130* w;
    E80049130_80049130* e;
    s32 hash;

    n = fn_8003DB34(fn_8004B458);
    fn_80061F58(&n->work, 0x58, 0);
    w = n->work;
    *(Blk4C*)w = *(Blk4C*)src->work;
    fn_80061F58(&w->e, 0x48, 0);
    e = w->e;
    e->buf = *buf;
    e->xC = v4;
    if (mat != 0) {
        e->x10 = fn_801E1C7C(0x40);
        memcpy(e->x10, mat, 0x40);
    }
    e->x2 = 0;
    e->x4 = rot;
    fn_80046BB0(w->x10 + 0xc, &hash);
    e->x14 = hash;
}

void fn_80049130(Node_80049130* node) {
    Buf_80049130 buf;
    W80049130* work;
    I80049130* inner;

    work = node->work;
    inner = work->e;
    memset(&buf, 0, 0x30);
    fn_80071CF0(&work->x1c, &buf.v);
    buf.q = inner->x1c->q;
    Spawn_80049130(node, &buf, inner->x4, inner->x8, inner->x1c->x56);
}

static inline void Spawn_800492C0(Node_800492C0* src, Buf_800492C0* buf, s32 v4, void* mat, s16 rot) {
    Node2_800492C0* n;
    W2_800492C0* w;
    E800492C0_800492C0* e;
    s32 hash;

    n = fn_8003DB34(fn_8004B458);
    fn_80061F58(&n->work, 0x58, 0);
    w = n->work;
    *(Blk4C*)w = *(Blk4C*)src->work;
    fn_80061F58(&w->e, 0x48, 0);
    e = w->e;
    e->buf = *buf;
    e->xC = v4;
    if (mat != 0) {
        e->x10 = fn_801E1C7C(0x40);
        memcpy(e->x10, mat, 0x40);
    }
    e->x2 = 0;
    e->x4 = rot;
    fn_80046BB0(w->x10 + 0xc, &hash);
    e->x14 = hash;
}

void fn_800492C0(Node_800492C0* node) {
    Buf_800492C0 buf;
    I800492C0* inner;

    inner = node->work->e;
    buf.q = inner->x1c;
    fn_80071CF0(&inner->x40, &buf.v);
    buf.f20 = inner->xC;
    buf.s24 = inner->x10;
    buf.f28 = inner->x14;
    buf.s2c = inner->x19c;
    Spawn_800492C0(node, &buf, inner->x4, inner->x8, inner->x1ba);
}

void fn_80049464(Node_80049464* node)
{
    Data_80049464* d = node->data;
    Work_80049464* w = d->work;
    Draw dr;

    switch (node->state) {
    case 0:
        fn_8006D954(w->cfg->src);
        node->state = 1;
        node->data->x50 = w->cfg->src;
        node->data->x54 = -1;
    case 1:
        if (w->timer < w->cfg->start) {
            break;
        }
        fn_80040150(w->cfg->type, (TaskRef*)w->task, w->cfg->id, &w->mtx);
        if (w->timer >= w->cfg->end) {
            if (w->cfg->fadeInLen != 0) {
                w->fade = -1.0f + 1.0f / w->cfg->fadeInLen;
            } else {
                w->fade = -1.0f;
            }
        } else {
            w->fade = -1.0f;
        }
        if (w->cfg->accStart >= w->cfg->accEnd) {
            w->cfg->accEnd = w->cfg->fadeInEnd;
        }
        node->state = 3;
        fn_80071CF0(&w->cfg->vel0, &w->vel);
        w->buf = fn_801E1C7C(w->cfg->count * 12);
        if (w->buf == NULL) {
            node->state = 0xFA;
        }
        break;
    case 3:
        if (w->timer >= w->cfg->end && w->fade < 0.0f && w->timer < w->cfg->fadeInEnd) {
            w->fade += 1.0f / w->cfg->fadeInLen;
            if (w->fade > 0.0f) {
                w->fade = 0.0f;
            }
        }
        if (w->timer >= w->cfg->fadeInEnd && w->cfg->start < w->cfg->fadeInEnd) {
            if (w->cfg->fadeOutLen != 0) {
                w->fade -= 1.0f / w->cfg->fadeOutLen;
                if (w->fade <= -1.0f) {
                    w->fade = -1.0f;
                    node->state = 0xFA;
                }
            } else {
                node->state = 0xFA;
            }
        }
        if (w->mtx == NULL) {
            fn_8001E4A0(&w->cfg->mtx, &w->pos, w->task);
        } else {
            fn_80061518(&w->cfg->mtx, &w->pos, w->mtx);
        }
        fn_8001E4A0(&w->vel, &w->pos2, w->task);
        if (w->timer >= w->cfg->accStart && w->timer < w->cfg->accEnd) {
            w->vel.x += w->cfg->acc.x;
            w->vel.y += w->cfg->acc.y;
            w->vel.z += w->cfg->acc.z;
        }
        w->frame = fn_800403AC(w->count, (AnimEnt*)w->cfg->anim, w->cfg->animA, w->cfg->animB);
        fn_80071CF0(&w->pos, &dr.pos);
        fn_80071CF0(&w->pos2, &dr.pos2);
        dr.frame = w->frame;
        dr.src = d->src;
        dr.x24 = w->cfg->x140;
        dr.count = w->cfg->count;
        dr.x2a = w->cfg->x148;
        dr.x2c = w->cfg->x14c;
        dr.x30 = w->cfg->x150;
        dr.x34 = w->cfg->x154;
        dr.x38 = w->cfg->x158;
        dr.x3c = w->cfg->x15c;
        dr.type = w->cfg->type;
        dr.alpha = 255.0f * (1.0f + w->fade);
        dr.buf = w->buf;
        dr.step = w->count * w->cfg->x170;
        fn_8004754C((Line*)&dr, 1.0f, 255.0f);
        w->count++;
        break;
    case 0xF9:
    case 0xFA:
        fn_8006D8DC(w->cfg->src);
        if (w->buf != NULL) {
            fn_801E17E0(w->buf);
        }
        fn_800400D8(w->cfg->type, (TaskRef*)w->task, w->cfg->id, &w->mtx);
        fn_801E17E0(w);
        node->flags |= 0x40;
        lbl_8030A10C.count--;
        return;
    }
    w->timer++;
    fn_80037FD8(w->cfg, &node->state);
}

void fn_800498F0(Node_800498F0* node)
{
    Data_800498F0* d = node->data;
    Work_800498F0* w = d->work;
    Cfg_800498F0* cfg;
    DrawState st;
    Rect2D_800498F0 r;
    s32 save;
    Cfg_800498F0* copy;

    copy = w->copy;
    if (copy != NULL) {
        cfg = copy;
    } else {
        cfg = w->base;
    }
    switch (node->state) {
    case 0:
        fn_8006D954(w->base->src);
        node->data->x50 = w->base->src;
        node->data->x54 = -1;
        if (w->base->type & 0x8000) {
            fn_80061F58(&w->copy, sizeof(Cfg_800498F0), 0);
            *w->copy = *w->base;
        }
        node->state = 1;
    case 1:
        if (w->timer < cfg->start) {
            break;
        }
        if (w->timer >= cfg->len) {
            if (cfg->fadeIn != 0) {
                w->alpha = -1.0f + 1.0f / cfg->fadeIn;
            } else {
                w->alpha = -1.0f;
            }
        } else {
            w->alpha = -1.0f;
        }
        node->state = 2;
        if ((cfg->type & 0x8000) && !(cfg->type & 0x80000)) {
            SePlay(4, 1, 30);
        }
    case 2:
        if (w->timer >= cfg->len && w->alpha < 0.0f && w->timer < cfg->end) {
            w->alpha += 1.0f / cfg->fadeIn;
            if (w->alpha > 0.0f) {
                w->alpha = 0.0f;
            }
        }
        if (cfg->type & 0x8000) {
            if (w->held == 0 && (lbl_8030A10C.input & 0x1000000)) {
                w->held = 1;
            }
        } else {
            w->held = 1;
        }
        if (w->held != 0 && w->timer >= cfg->end && cfg->start < cfg->end) {
            if (cfg->fadeOut != 0) {
                w->alpha -= 1.0f / cfg->fadeOut;
                if (w->alpha <= -1.0f) {
                    w->alpha = -1.0f;
                    node->state = 0xFA;
                }
            } else {
                node->state = 0xFA;
            }
        }
        w->frame = fn_800403AC(w->count, (AnimEnt*)cfg->anim, cfg->animA, cfg->animB);
        DrawStateDefault2D(&st);
        if (cfg->type & 0x20000000) {
            st.blend_src = 8;
            st.blend_dst = 10;
        }
        if (DrawStatePush(&st) != 0) {
            r.x0 = 0;
            r.y0 = 0;
            r.x1 = 640;
            r.y1 = 480;
            if (cfg->type & 0x200000) {
                r.data = NULL;
                w->frame = 0;
            } else {
                r.data = d->tex;
                if (w->frame < 0) {
                    w->frame = 0;
                }
            }
            r.id = w->frame;
            r.col[0].c[0] = (s32)(255.0f * w->alpha) + 255;
            r.col[0].c[1] = cfg->r;
            r.col[0].c[2] = cfg->g;
            r.col[0].c[3] = cfg->b;
            r.col[1].c[0] = (s32)(255.0f * w->alpha) + 255;
            r.col[1].c[1] = cfg->r;
            r.col[1].c[2] = cfg->g;
            r.col[1].c[3] = cfg->b;
            r.col[2].c[0] = (s32)(255.0f * w->alpha) + 255;
            r.col[2].c[1] = cfg->r;
            r.col[2].c[2] = cfg->g;
            r.col[2].c[3] = cfg->b;
            r.col[3].c[0] = (s32)(255.0f * w->alpha) + 255;
            r.col[3].c[1] = cfg->r;
            r.col[3].c[2] = cfg->g;
            r.col[3].c[3] = cfg->b;
            r.uv[0].u = 0;
            r.uv[0].v = 0;
            r.uv[1].u = 255;
            r.uv[1].v = 0;
            r.uv[2].u = 255;
            r.uv[2].v = 255;
            r.uv[3].u = 0;
            r.uv[3].v = 255;
            save = fn_800358F8();
            fn_80035900(0x5000);
            fn_800334B8(&r);
            fn_80035900(save);
            DrawStatePop(NULL);
        }
        w->count++;
        break;
    case 0xF9:
    case 0xFA:
        if (copy != NULL) {
            fn_801E17E0(copy);
        }
        fn_8006D8DC(cfg->src);
        fn_801E17E0(w);
        node->flags |= 0x40;
        lbl_8030A10C.count--;
        return;
    }
    w->timer++;
    fn_80037FD8(cfg, &node->state);
}

void fn_80049DC0(Node_80049DC0* node)
{
    Q_80049DC0* q;
    Data_80049DC0* d;
    Body_80049DC0* b;
    s32 flag;
    Ent* e;
    s16 lim;
    void* tex;

    flag = 0;
    d = node->work;
    q = d->x4->work;
    b = q->body;

    switch (node->state) {
    case 0:
        if (d->timer < d->x10) {
            break;
        }
        d->x8 = -1.0f + d->ent->col[0] / 255.0f;
        if ((d->ent->flags & 0x10000000) && d->ent->x54 != 0) {
            node->state = 1;
        } else {
            node->state = 2;
        }
        if (d->ent->flags & 0x80000000) {
            d->xc = b->x68;
        }
        fn_80073F14(q->x10->x2c, b->x158, q->x14, d->ent->x2c, 0x100);
    case 1:
        if (d->timer < d->x10 + d->ent->x54) {
            break;
        }
        node->state = 2;
    case 2:
        e = d->ent;
        lim = d->x12;
        if (e->flags & 0x10000000) {
            lim = lim + e->x54;
        }
        if (d->timer > lim + e->x18) {
            node->state = 0xFA;
        }
        if (d->timer >= lim) {
            if (fn_80056FC4(&d->x8, d->ent->x18) == 0) {
                node->state = 0xFA;
            }
        }
        if (!(d->ent->flags & 0x80000000)) {
            d->xc = b->x68;
        }
        if (b->x1f4 != NULL && (d->ent->flags & 0x40000000)) {
            tex = b->x1f4;
        } else {
            tex = q->tex;
        }
        e = d->ent;
        if (e->flags & 0x20000000) {
            flag = 1;
        }
        fn_80046DE4((Node*)d->x4, tex, 0, (Vec*)&e->scl, e->col, (Vec*)&q->pos, flag, d->xc, d->x8, e->x50);
        break;
    case 0xF9:
    case 0xFA:
        node->flags |= 0x40;
        lbl_8030A10C.count--;
        return;
    }
    d->timer++;
    fn_80037FD8(d->ent, &node->state);
}

void fn_8004A028(Node_8004A028* node)
{
    u32 in;
    s8 skip = 0;

    if (node->data->flags & 0x8000) {
        in = lbl_8030A10C.input;
        if ((in & 0x08000000) && node->data->timer > node->data->t14 && node->data->timer > node->data->t18) {
            node->flags |= 0x40;
            return;
        }
        if (in & 0x04000000) {
            node->flags |= 0x40;
            return;
        } else if (in & 0x02000000) {
            skip = 1;
        }
    }
    switch (node->state) {
    case 0:
        if (skip == 0) {
            if (node->data->t14 == node->data->timer && node->data->id14 != 0) {
                fn_8007E3A8(node->data->id14);
            }
            if (node->data->t18 == node->data->timer && node->data->id18 != 0) {
                fn_8007E2D8(node->data->id18);
                fn_8007E414(1);
            }
        }
        if (node->data->t1c == node->data->timer && node->data->id1c != 0) {
            fn_8007E344(node->data->id1c);
        }
        if (node->data->t20 == node->data->timer && node->data->id20 != 0) {
            fn_8007E274(node->data->id20);
            fn_8007E414(0);
        }
        if (node->data->flags & 0x4000) {
            fn_8000CC84(1);
        }
        if (node->data->timer > node->data->t14 && node->data->timer > node->data->t18
            && node->data->timer > node->data->t1c + node->data->id1c
            && node->data->timer > node->data->t20 + node->data->id20) {
            node->state = 0xFA;
        }
        break;
    case 0xF9:
        fn_8003801C();
    case 0xFA:
        if (node->data->flags & 0x4000) {
            fn_8000CC84(0);
        }
        node->flags |= 0x40;
        lbl_8030A10C.count--;
        return;
    }
    node->data->timer++;
    fn_80037FD8(node->data->x4, &node->state);
}

void fn_8004A260(Node_8004A260* node)
{
    Data_8004A260* d = node->data;
    Work_8004A260* w = d->work;
    Ctl* c = w->sub->data->ctl;
    s16 idx;
    int r;

    switch (node->state) {
    case 1:
        c->flags &= ~8;
        node->state = 2;
        break;
    case 0:
        if (c->flags & 8) {
            node->state = 1;
            return;
        }
        node->state = 2;
    case 2:
        if (c->flags & 8) {
            node->state = 0xFA;
            return;
        }
        idx = fn_800403AC(w->timer, (AnimEnt*)w->x20, w->x120, w->x122);
        if (idx >= 0) {
            r = fn_80015CFC(w->sub->data->tex);
            if (d->x8 != NULL) {
                fn_800350EC(w->sub->data->tex, r, d->x8, idx);
            } else if (w->sub->data->x48 != NULL) {
                fn_800350EC(w->sub->data->tex, r, w->sub->data->x48, idx);
            } else {
                node->state = 0xFA;
            }
        }
        if (c->x70 != 0) {
            node->state = 0xFA;
        }
        break;
    case 0xF9:
    case 0xFA:
        fn_801E17E0(w);
        node->flags |= 0x40;
        lbl_8030A10C.count--;
        return;
    }
    w->timer++;
    fn_80037FD8(&w->x8, &node->state);
}

static inline void CalcPos(Sub_8004A40C* s)
{
    if (s->mtx == NULL) {
        switch (s->hdr.flags & 0xF) {
        case 3:
            fn_8001E238(&s->src, &s->pos, s->task);
            break;
        case 0:
            fn_8001E4A0(&s->src, &s->pos, s->task);
            break;
        case 1:
            fn_80071CF0(&s->src, &s->pos);
            break;
        }
    } else {
        fn_80061518(&s->src, &s->pos, s->mtx);
    }
}

void fn_8004A40C(Node_8004A40C* node)
{
    Child_8004A40C* c;
    ChildNode_8004A40C* cw;
    CNode_8004A40C* n;
    Sub_8004A40C* s2;
    void* task;
    s16 x;
    Work_8004A40C* w;
    Sub_8004A40C* s;
    TBody* body;

    w = node->work;
    s = w->sub;
    body = s->task->data->body;

    switch (node->state) {
    case 0:
        node->state = 1;
    case 1:
        fn_80040150(s->hdr.flags, (TaskRef*)s->task, s->id, &s->mtx);
        node->state = 2;
        break;
    case 2: {
        if (s->timer < s->start) break;
        node->state = 3;
        CalcPos(s);
        if (s->timer >= s->fadeStart) {
            if (s->fadeIn != 0) {
                s->alpha = -1.0f + 1.0f / s->fadeIn;
            } else {
                s->alpha = -1.0f;
            }
        } else {
            s->alpha = -1.0f;
        }
        w->ang[0] = 182.04445f * s->rotDeg.x;
        w->ang[1] = 182.04445f * s->rotDeg.y;
        w->ang[2] = 182.04445f * s->rotDeg.z;
        fn_80071CF0(&s->scale, &w->scl);
        fn_8006CEEC(w->src->x8, &w->motion, 0, w->x16);
        if (s->x18c != 0 || s->x18e != 0) {
            sndAuxCallbackShutdownReverbSTD(w->model, &s->snd);
            fn_8022E8F8(w->model, 0);
        }
    }
    case 3: {
        DrawState st;
        Blk_8004A40C blk;
        Vec_8004A40C dir;
        s16 v[2];
        void* drawn;
        s32 tmp;
        u8 kind;
        int blend;

        switch (s->x19e) {
        case 1:
            body->flags1EC |= 0x80000000;
            break;
        case 2:
            body->flags1EC |= 0x40000000;
            break;
        }
        if (s->timer >= s->fadeStart && s->alpha < 0.0f && s->x4 < (f32)s->end) {
            s->alpha += 1.0f / s->fadeIn;
            if (s->alpha > 0.0f) {
                s->alpha = 0.0f;
            }
        }
        if (s->count >= s->end) {
            if (s->fadeOut != 0) {
                s->alpha -= 1.0f / s->fadeOut;
                if (s->alpha <= -1.0f) {
                    s->alpha = -1.0f;
                    node->state = 0xFA;
                }
            } else {
                node->state = 0xFA;
            }
        }
        if (s->rotStart == s->rotEnd || (s->rotEnd > s->timer && s->rotStart <= s->timer)) {
            w->ang[0] += (s32)(182.04445f * s->rotVel.x);
            w->ang[1] += (s32)(182.04445f * s->rotVel.y);
            w->ang[2] += (s32)(182.04445f * s->rotVel.z);
        }
        s->frame = fn_800403AC(s->count, (AnimEnt*)(s16*)((u8*)s + 0x74), s->x174, s->x176);
        if (w->motion != NULL) {
            s->frameF += s->frameStep;
            if (s->frameF >= (f32)w->motion->nbFrame - 1.0f) {
                if (s->hdr.flags & 0x08000000) {
                    s->frameF = (f32)w->motion->nbFrame - 1.0f;
                } else {
                    s->frameF = 0.0f;
                }
            }
        }
        if (s->x18c != 0 || s->x18e != 0) {
            v[0] = s->x18c;
            v[1] = s->x18e;
            fn_8023080C((void*)s->snd, v, 0);
        }
        dir = lbl_802AD360;
        if (s->x4 >= 180.0f || s->x4 <= -180.0f) {
            CalcPos(s);
        }
        fn_8001DF44(s->task, &dir);
        fn_80060DFC(&w->pos, &s->pos, &dir, 0.0f, s->x4, s->x188);
        if (s->timer >= s->x42 && s->timer < s->end + s->start) {
            s->x4 += s->x178;
        }
        if ((s->hdr.flags & 0x04000000) || w->model == NULL) {
            blend = 0;
            if (s->hdr.flags & 0x20000000) blend = 1;
            if (s->frame < 0) s->frame = 0;
            fn_80032E78(blend, w, s->frame, s->alpha, 0, s->x19c, fn_80040010(s->hdr.flags));
        } else {
            DrawStateDefault2D(&st);
            kind = w->kind;
            fn_80040044(&st, s->alpha, s->hdr.flags, &w->kind);
            if (DrawStatePush(&st) != 0) {
                fn_80299040(w->texlist);
                drawn = NULL;
                fn_8006CEEC(w->src->x8, &drawn, 1, w->x16);
                if (drawn != NULL) {
                    fn_8003440C(w, s->frame, NULL, w->motion, drawn, s->frameF);
                } else {
                    fn_80034E6C(w, s->frame, NULL, w->motion, s->frameF);
                }
                DrawStatePop(NULL);
            }
            w->kind = kind;
        }
        if (s->interval != 0 && s->timer >= s->x42 && s->timer < s->end + s->start
            && s->count % s->interval == 0) {
            s2 = ((Work_8004A40C*)node->work)->sub;
            blk.hdr = *(Hdr*)((u8*)s2 + 0x2C);
            blk.hdr.flags &= ~0xF;
            blk.hdr.flags |= 1;
            fn_80071CF0(&s2->src, &blk.org);
            blk.f0 = s2->alpha;
            blk.s0 = s2->frame;
            blk.f1 = s2->frameF;
            blk.s1 = s2->x19c;
            x = s2->x19a;
            task = s2->task;
            n = fn_8003DB34(fn_8004B458);
            fn_80061F58(&n->work, 0x58, 0);
            cw = n->work;
            *(Buf_8004A40C*)cw = *(Buf_8004A40C*)node->work;
            fn_80061F58(&cw->sub, 0x48, 0);
            c = cw->sub;
            c->blk = blk;
            c->parent = task;
            c->count = 0;
            c->x4 = x;
            fn_80046BB0((char*)cw->x10 + 0xC, &tmp);
            c->id = tmp;
        }
        s->count++;
        break;
    }
    case 0xF9:
    case 0xFA:
        body->flagsF0 |= 0x200000;
        switch (s->x19e) {
        case 1:
            body->flags1EC &= 0x7FFFFFFF;
            break;
        case 2:
            body->flags1EC &= ~0x40000000;
            break;
        }
        fn_800400D8(s->hdr.flags, (TaskRef*)s->task, s->id, &s->mtx);
        fn_801E17E0(s);
        node->flags |= 0x40;
        lbl_8030A10C.count -= 1;
        return;
    }
    s->timer++;
    fn_80037FD8(&s->hdr, &node->state);
}

void fn_8004AD38(Node_8004AD38* n)
{
    Work_8004AD38* w = n->work;
    switch (n->state) {
    case 0:
        if (fn_8000F208(&w->target)) {
            n->state = 1;
            w->target->data->body->flags |= 0x80000000;
        } else {
            n->state = 0xFA;
            break;
        }
    case 1: {
        Body_8004AD38* b = w->target->data->body;
        b->flags |= 0x80000000;
        if (w->timer >= w->inStart && w->inLen != 0) {
            if (w->timer == w->inStart && b->gauge < 0.0f) {
                w->inRate = -1.0f * (b->gauge / (f32)w->inLen);
            }
            if (w->timer < w->inStart + w->inLen) {
                b->gauge = b->gauge + w->inRate;
                if (b->gauge > 0.0f) b->gauge = 0.0f;
            }
        }
        if (w->timer >= w->outStart && w->outLen != 0) {
            f32 one = -1.0f;
            if (w->timer == w->outStart && b->gauge > one) {
                w->outRate = one * ((1.0f + b->gauge) / (f32)w->outLen);
            }
            if (w->timer < w->outStart + w->outLen) {
                b->gauge = b->gauge + w->outRate;
                if (b->gauge <= one) b->gauge = one;
            }
        }
        if (w->timer >= w->inStart + w->inLen && w->timer >= w->outStart + w->outLen) {
            n->state = 0xFA;
        }
        break;
    }
    case 0xF9:
        w->target->data->body->gauge = 0.0f;
    case 0xFA:
        w->target->data->body->flags &= 0x7FFFFFFF;
        n->flags |= 0x40;
        lbl_8030A10C.count -= 1;
        return;
    }
    w->timer++;
    fn_80037FD8(w->sub, &n->state);
}

void fn_8004AFD8(Node_8004AFD8* node)
{
    s16 x;
    TaskRef_8004AFD8* t;
    Child_8004AFD8* c;
    ChildNode_8004AFD8* cw;
    CNode_8004AFD8* n;
    void* mtxSrc;
    void* copy;
    Work_8004AFD8* w = node->work;
    Body_8004AFD8* body;
    switch (node->state) {
    case 0:
        if (fn_8000FB4C(w->src, &w->target, w->mode)) {
            node->state = 1;
            w->target->data->body->flags |= 0x8000000;
        } else {
            node->state = 0xFA;
            break;
        }
    case 1: {
        u16 timer;
        t = w->target;
        body = t->data->body;
        timer = w->timer;
        if (timer >= w->spawnStart && timer < w->spawnEnd && w->spawnStart != w->spawnEnd
            && timer % w->interval == 0) {
            Blk_8004AFD8 blk;
            s32 tmp;
            x = w->x2a;
            blk.hdr = body->hdr;
            blk.hdr.flags &= ~0xF;
            blk.hdr.flags |= 2;
            fn_80071CF0(&body->org, &blk.org);
            blk.alpha = body->alpha;
            copy = body->mtx;
            mtxSrc = body->mtxSrc;
            n = fn_8003DB34(fn_8004B458);
            fn_80061F58(&n->work, 0x58, 0);
            cw = n->work;
            *(Buf_8004AFD8*)cw = *(Buf_8004AFD8*)t->data;
            fn_80061F58(&cw->sub, 0x48, 0);
            c = cw->sub;
            c->blk = blk;
            c->parent = mtxSrc;
            if (copy != NULL) {
                c->copy = fn_801E1C7C(0x40);
                memcpy(c->copy, copy, 0x40);
            }
            c->count = 0;
            c->x4 = x;
            fn_80046BB0((char*)cw->x10 + 0xC, &tmp);
            c->id = tmp;
        }
        timer = w->timer;
        if (timer >= w->inStart && w->inLen != 0) {
            if (timer == w->inStart && body->alpha < 0.0f) {
                w->inRate = -1.0f * (body->alpha / (f32)w->inLen);
            }
            if (w->timer < w->inStart + w->inLen) {
                body->alpha = body->alpha + w->inRate;
                if (body->alpha > 0.0f) body->alpha = 0.0f;
            }
        }
        timer = w->timer;
        if (timer >= w->outStart && w->outLen != 0) {
            f32 neg = -1.0f;
            if (timer == w->outStart && body->alpha > neg) {
                w->outRate = neg * ((1.0f + body->alpha) / (f32)w->outLen);
            }
            if (w->timer < w->outStart + w->outLen) {
                body->alpha = body->alpha + w->outRate;
                if (body->alpha <= neg) body->alpha = neg;
            }
        }
        if (w->timer == w->x2c || w->timer == w->x2e) {
            if (w->x2c != w->x2e) fn_80076344(body->mtx);
        }
        timer = w->timer;
        if (timer >= w->spawnEnd && timer >= w->x2e
            && timer >= w->inStart + w->inLen && timer >= w->outStart + w->outLen) {
            node->state = 0xFA;
        }
        break;
    }
    case 0xF9:
        w->target->data->body->alpha = 0.0f;
    case 0xFA:
        w->target->data->body->flags &= ~0x8000000;
        node->flags |= 0x40;
        lbl_8030A10C.count -= 1;
        return;
    }
    w->timer++;
    fn_80037FD8(w->sub, &node->state);
}

void fn_8004B458(Node_8004B458* node) {
    Work_8004B458* w = node->work;
    Sub_8004B458* s = w->sub;
    DrawState st;
    void* drawn;
    u8 kind;
    int blend;

    switch (node->state) {
    case 0:
        fn_8006D954(s->src);
        node->state = 1;
        ((Work_8004B458*)node->work)->x50 = s->src;
        ((Work_8004B458*)node->work)->x54 = -1;
    case 1:
        if (s->life != 0) {
            s->rate = (1.0f + s->alpha) / (f32)s->life;
        }
        node->state = 2;
    case 2:
        if (s->timer >= s->start) {
            if (s->rate) {
                s->alpha -= s->rate;
                if (s->timer > s->start + s->life || s->alpha <= -1.0f) {
                    s->alpha = -1.0f;
                    node->state = 0xFA;
                }
            } else {
                node->state = 0xFA;
            }
        }
        if (s->mtx == NULL) {
            switch (s->type & 0xF) {
            case 3:
                fn_8001E238(&s->pos, &w->ofs, s->arg);
                break;
            case 0:
                fn_8001E4A0(&s->pos, &w->ofs, s->arg);
                break;
            case 2:
                break;
            }
        } else {
            fn_80071CF0(&s->pos, &w->ofs);
        }
        if ((s->type & 0x4000000) || w->x0 == NULL) {
            blend = 0;
            if (s->type & 0x20000000) {
                blend = 1;
            }
            if (s->frame < 0) {
                s->frame = 0;
            }
            fn_80032E78(blend, w, s->frame, s->alpha, s->mtx, s->x44, fn_80040010(s->type));
        } else {
            DrawStateDefault2D(&st);
            kind = w->kind;
            fn_80040044(&st, s->alpha, s->type, &w->kind);
            if (DrawStatePush(&st) != 0) {
                fn_80299040(w->texlist);
                drawn = NULL;
                fn_8006CEEC(w->src->x8, &drawn, 1, w->x16);
                if (drawn != NULL) {
                    fn_8003440C(w, s->frame, s->mtx, w->motion, drawn, s->x40);
                } else if ((s->type & 0x8000) && s->mtx != NULL && w->motion != NULL) {
                    fn_80034E6C(w, s->frame, s->mtx, NULL, s->x40);
                } else {
                    fn_80034E6C(w, s->frame, s->mtx, w->motion, s->x40);
                }
                DrawStatePop(NULL);
            }
            w->kind = kind;
        }
        break;
    case 0xF9:
    case 0xFA:
        fn_8006D8DC(s->src);
        if (s->mtx != NULL) {
            fn_801E17E0(s->mtx);
        }
        fn_801E17E0(s);
        node->flags |= 0x40;
        lbl_8030A10C.count--;
        return;
    default:
        break;
    }
    s->timer++;
    fn_80037FD8(&s->c, &node->state);
}

void fn_8004B7C4(Node_8004B7C4* node) {
    Work_8004B7C4* w = node->work;
    Chr* c;
    Vec_8004A40C v20;
    Vec_8004A40C v14;
    Vec_8004A40C v8;
    s16 i;
    int cnt;
    int id;
    int fl;
    int id2;
    int k;
    Chr* d2;
    Chr* d3;
    Tk_8004B7C4* t2;
    Tk_8004B7C4* t3;
    Tk_8004B7C4* t;
    Chr* d;

    k = 1;
    fl = 0;
    c = w->task->data->chr;
    if (w->type & 0x400) {
        fl = 1;
    }
    switch (node->state) {
    case 0:
        c->fa |= 0x80000;
        c->fa |= 0x40000;
        fn_80017778();
        fn_80020B50(w->task, &w->x1a, &w->x1c);
        node->state = 1;
    case 1:
        if (w->timer < w->x38) {
            break;
        }
        node->state = 2;
        switch (w->type & 0xF) {
        case 2:
            w->mem = fn_801E1C7C(0x40);
            fn_80076478(w->mem, c->body, w->x3c, 0);
            break;
        default:
            break;
        }
        break;
    case 2:
        if (w->flags & 0x1000) {
            k = 3;
        } else if (w->flags & 0x800) {
            k = 5;
        }
        cnt = k;
        for (i = 0; i < (s16)k; i++) {
            fn_80071CF0(&w->pos, &v14);
            switch (i) {
            case 1:
                v14.x += 15.0f;
                break;
            case 2:
                v14.x -= 15.0f;
                break;
            case 3:
                fn_80071CF0(&w->pos, &v14);
                v14.x -= 30.0f;
                break;
            case 4:
                fn_80071CF0(&w->pos, &v14);
                v14.x += 30.0f;
                break;
            }
            if (w->mem != NULL) {
                fn_80061518(&v14, &v20, w->mem);
            } else {
                fn_8001E4A0(&v14, &v20, w->task);
            }
            id = fn_80018398(&v20, 0);
            if ((lbl_80347394 != NULL && (lbl_80347394->work->f & 0x40)) || (lbl_803472F4 & 0x20000000)) {
                fn_800341B0(&v20, 0, 2);
            }
            if ((s8)id < 0) {
                fn_80071CF0(&v14, &v8);
                {
                    f32 h = 0.5f;
                    v8.x -= w->vel.x * h;
                    v8.y -= w->vel.y * h;
                    v8.z -= w->vel.z * h;
                }
                if (w->mem != NULL) {
                    fn_80061518(&v8, &v20, w->mem);
                } else {
                    fn_8001E4A0(&v8, &v20, w->task);
                }
                id = fn_80018398(&v20, 0);
            }
            if (fn_80018498(&v20) == 0) {
                cnt--;
            }
            if ((s8)id >= 0 && (s8)id != c->id && w->hit[(s8)id] == 0) {
                w->hit[(s8)id] = 1;
                c->cur = id;
                if (fn_8001DC7C(id, w->task) != 0) {
                    if (!(w->flags & 0x4000)) {
                        node->state = 0xFA;
                    }
                    if (w->flags & 0x400) {
                        t = fn_80021658(w->task->data->chr->cur);
                        d = t->data->chr;
                        d->fb |= 0x400000;
                        d->fa |= 1;
                        if (fn_80075FF0(t, 0x20, -1) == 0 && fn_80075FF0(t, 0xb, -1) == 0) {
                            d->fa &= ~1;
                        }
                    } else {
                        c->fa |= 0x80;
                        fn_80020B8C(w->task, w->x1a, w->x1c, fl);
                        c->fa &= ~0x80;
                    }
                    w->x20 = 1;
                } else if (w->flags & 0x2000) {
                    if (fn_8001D944(id, w->task) != 0) {
                        if (w->flags & 0x400) {
                            t = fn_80021658(w->task->data->chr->cur);
                            d = t->data->chr;
                            d->fb |= 0x400000;
                            d->fa |= 1;
                            if (fn_80075FF0(t, 0x20, -1) == 0 && fn_80075FF0(t, 0xb, -1) == 0) {
                                d->fa &= ~1;
                            }
                        } else {
                            c->fa |= 0x80;
                            fn_80020B8C(w->task, w->x1a, w->x1c, fl);
                            c->fa &= ~0x80;
                        }
                    }
                }
                if (w->flags & 0x8000) {
                    node->state = 0xFA;
                }
            }
        }
        if (w->timer < w->x3a || w->x3a == 0) {
            w->pos.x += w->vel.x;
            w->pos.y += w->vel.y;
            w->pos.z += w->vel.z;
        }
        if ((s16)cnt > 0) {
            break;
        }
        if (w->x20 == 0) {
            id2 = c->id4;
            if (w->hit[(s8)id2] == 0) {
                w->hit[(s8)id2] = 1;
                c->cur = id2;
                if (fn_8001DC7C(id2, w->task) != 0) {
                    if (!(w->flags & 0x4000)) {
                        node->state = 0xFA;
                    }
                    if (w->flags & 0x400) {
                        t2 = fn_80021658(w->task->data->chr->cur);
                        d2 = t2->data->chr;
                        d2->fb |= 0x400000;
                        d2->fa |= 1;
                        if (fn_80075FF0(t2, 0x20, -1) == 0 && fn_80075FF0(t2, 0xb, -1) == 0) {
                            d2->fa &= ~1;
                        }
                    } else {
                        c->fa |= 0x80;
                        fn_80020B8C(w->task, w->x1a, w->x1c, fl);
                        c->fa &= ~0x80;
                    }
                    w->x20 = 1;
                } else if (w->flags & 0x2000) {
                    if (fn_8001D944(id2, w->task) != 0) {
                        if (w->flags & 0x400) {
                            t3 = fn_80021658(w->task->data->chr->cur);
                            d3 = t3->data->chr;
                            d3->fb |= 0x400000;
                            d3->fa |= 1;
                            if (fn_80075FF0(t3, 0x20, -1) == 0 && fn_80075FF0(t3, 0xb, -1) == 0) {
                                d3->fa &= ~1;
                            }
                        } else {
                            c->fa |= 0x80;
                            fn_80020B8C(w->task, w->x1a, w->x1c, fl);
                            c->fa &= ~0x80;
                        }
                    }
                }
            }
        }
        node->state = 0xFA;
        break;
    case 4:
        if (lbl_8030A10C.flags & 0x20) {
            node->state = 1;
            w->timer = w->x38;
        }
        break;
    case 0xFA:
        fn_8001D14C(c);
        if (w->mem != NULL) {
            fn_8007638C(w->mem, c->body, w->x3c);
            fn_801E17E0(w->mem);
        }
        node->flags |= 0x40;
        lbl_8030A10C.count--;
        return;
    case 3:
    default:
        break;
    }
    w->timer++;
    if (w->x2a & 0x2000) {
        switch (node->state) {
        case 1:
            break;
        default:
            lbl_8030A10C.flags |= 0x10;
            break;
        }
        if ((lbl_8030A10C.flags & 0x80) && !(lbl_8030A10C.flags & 0x20)) {
            switch (node->state) {
            case 1:
                node->state = 4;
                break;
            default:
                break;
            }
        }
    }
}

void fn_8004BFD8(Tk_8004BFD8* t) {
    Tk_8004BFD8* p = fn_80021658(t->work->unit->id);
    Unit_8004BFD8* u = p->work->unit;
    u->flagsF0 |= 0x400000;
    u->flagsEC |= 1;
    if (fn_80075FF0(p, 0x20, -1) != 0) {
        return;
    }
    if (fn_80075FF0(p, 0xB, -1) != 0) {
        return;
    }
    u->flagsEC &= ~1;
}

void fn_8004C070(Node_8004C070* node) {
    Work_8004C070* w;
    switch (node->state) {
    case 0:
        w = node->work;
        if (w->timer < w->x68) break;
        w->arg->data->body->xec |= 0x20000000;
        if (node->work->flags & 0x8000) {
            node->state = 2;
            return;
        }
        node->state = 1;
        /* fallthrough */
    case 1:
        w = node->work;
        if (w->timer < w->x6a) break;
        w->arg->data->body->xec &= ~0x20000000;
        node->state = 0xFA;
        break;
    case 2:
        w = node->work;
        if (w->timer < w->x6a) break;
        w->arg->data->body->x50 |= 0x10000;
        node->state = 0xFA;
        break;
    case 0xF9:
        node->work->arg->data->body->xec &= ~0x20000000;
        /* fallthrough */
    case 0xFA:
        node->flags |= 0x40;
        lbl_8030A10C.count--;
        return;
    }
    node->work->timer++;
    fn_80037FD8(node->work->cmd, &node->state);
}

void fn_8004CF14(Node_8004CF14* node)
{
    Work_8004CF14* w = node->work;
    Sub_8004CF14* s = w->sub;
    DrawState st;
    Angle rot[3];
    u32 i;
    P* p;
    s16 k;
    f32 g;

    switch (node->state) {
    case 0:
        fn_8006D954(s->src);
        node->state = 1;
        node->work->x50 = s->src;
        node->work->x54 = -1;
    case 1:
        node->state = 3;
        if (s->fade != 0) {
            s->step = (1.0f + s->alpha) / s->fade;
        }
        rot[0] = (s32)(182.04445f * w->a);
        rot[1] = (s32)(182.04445f * w->b);
        rot[2] = (s32)(182.04445f * w->c);
        fn_800482E0((ModelParts_800482E0*)&s->n, (ModelNode_800482E0*)w->x0, (NJS_POINT3*)&w->v, rot, (NJS_POINT3*)&w->q, (f32*)s->buf);
        fn_80047CF0((Parts*)&s->n, (NJS_POINT3*)&w->v, (f32*)(&s->count + 1), (f32*)s->buf);
        if (s->buf != NULL) {
            fn_801E17E0(s->buf);
        }
        for (k = 0; k < s->n; k++) {
            if (fn_8025ECC4() % 4 == 0) {
                fn_800472DC(node, k, s->colmode, s->cmd);
            }
        }
        break;
    case 3:
        if (s->timer >= s->end) {
            if (s->fade != 0) {
                s->alpha = s->alpha - s->step;
                if (s->alpha <= -1.0f) {
                    s->alpha = -1.0f;
                    node->state = 0xFA;
                }
            } else {
                node->state = 0xFA;
            }
        }
        fn_80299040(w->x8);
        g = s->grav;
        p = s->p;
        i = 0;
        if (s->colmode != 0) {
            for (; i < s->n; i++, p++) {
                p->vy += g;
                p->x18 += p->vx;
                p->x1c += p->vy;
                p->x20 += p->vz;
                p->c0 += (s32)(182.04445f * (10.0f * p->vx));
                p->c1 += (s32)(182.04445f * (10.0f * p->vy));
                p->c2 += (s32)(182.04445f * (10.0f * p->vz));
            }
        } else {
            for (; i < s->n; i++, p++) {
                p->vy += g;
                p->x18 += p->vx;
                p->x1c += p->vy;
                p->x20 += p->vz;
            }
        }
        DrawStateDefault2D(&st);
        if (DrawStatePush(&st) != 0) {
            fn_80047A68(&s->n, s->alpha);
            fn_80018C94();
        }
        break;
    case 0xF9:
    case 0xFA:
        fn_8006D8DC(s->src);
        fn_80047EDC((Pool*)&s->n);
        fn_801E17E0(s);
        node->flags |= 0x40;
        lbl_8030A10C.count--;
        return;
    }
    s->timer++;
    fn_80037FD8(s->cmd, &node->state);
}

void fn_8004D378(Node_8004D378* node)
{
    Work_8004D378* w = node->work;
    Sub_8004D378* s = w->sub;
    DrawState st;
    s16 k;

    switch (node->state) {
    case 0:
        fn_8006D954(s->owner->src);
        node->state = 1;
        node->work->x50 = s->owner->src;
        node->work->x54 = -1;
    case 1:
        if (s->timer >= s->owner->start) {
            if (s->timer >= s->owner->len) {
                if (s->owner->fadeIn != 0) {
                    s->alpha = -1.0f + 1.0f / s->owner->fadeIn;
                } else {
                    s->alpha = -1.0f;
                }
            } else {
                s->alpha = -1.0f;
            }
            fn_800339B0(s->uv, 0);
            fn_80071CF0(&s->owner->from, &w->v);
            s->ctr = s->owner->count;
            switch (s->owner->type & 0xF) {
            case 1:
                for (k = 0; k < 4; k++) {
                    fn_80071CF0(&s->owner->pts[k], &s->pos[k]);
                }
                break;
            default:
                for (k = 0; k < 4; k++) {
                    fn_8001E4A0(&s->owner->pts[k], &s->pos[k], s->arg);
                }
                break;
            }
            node->state = 3;
        } else {
            break;
        }
    case 3:
        if (s->timer >= s->owner->len && s->alpha < 0.0f && s->timer < s->owner->end) {
            s->alpha += 1.0f / s->owner->fadeIn;
            if (s->alpha > 0.0f) {
                s->alpha = 0.0f;
            }
        }
        if (s->timer >= s->owner->end && s->owner->start < s->owner->end && !(s->owner->type & 0x10000)) {
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
        if (s->ctr > 0 && s->timer >= s->owner->x38) {
            w->v.x += s->owner->delta.x;
            w->v.y += s->owner->delta.y;
            w->v.z += s->owner->delta.z;
            s->ctr--;
        }
        if (s->owner->dx != 0 || s->owner->dy != 0) {
            s->uv[0] += s->owner->dx;
            s->uv[1] += s->owner->dy;
            s->uv[2] += s->owner->dx;
            s->uv[3] += s->owner->dy;
            s->uv[4] += s->owner->dx;
            s->uv[5] += s->owner->dy;
            s->uv[6] += s->owner->dx;
            s->uv[7] += s->owner->dy;
        }
        DrawStateDefault2D(&st);
        if (s->owner->type & 0x20000000) {
            st.blend_src = 8;
            st.blend_dst = 10;
        }
        if (DrawStatePush(&st) != 0) {
            fn_800470F0((QuadSrc_800470F0*)s->owner, &w->v, (void*)w->x8, (UV*)s->uv, (NJS_POINT3*)s->pos, s->alpha);
            DrawStatePop(NULL);
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

void fn_8004D828(Node_8004D828* node) {
    Wk_8004D828* w = node->work;
    Unit_8004D828* u = w->owner->work->w;
    u32 col;
    u8 alpha;
    u8 lim;
    int t;

    switch (node->state) {
    case 0:
        fn_8006D954(1);
        node->state = 1;
        w->cmd->flags |= 0x2000;
    case 1:
        if (w->cmd->riseStart > w->cmd->fallStart) {
            if (w->timer < w->cmd->fallStart) {
                break;
            }
            node->state = 2;
        } else {
            if (w->timer < w->cmd->riseStart) {
                break;
            }
            node->state = 2;
        }
    case 2:
        w->flags = w->cmd->flags;
        col = (w->cmd->c3 << 24) | (w->cmd->c2 << 16) | (w->cmd->c1 << 8);
        if (!(w->flags & 0x4000)) {
            if (!(lbl_8030A10C.input & 0x80000)) {
                lbl_8030A10C.col = col;
                lbl_8030A10C.input |= 0x80000;
                w->sub = 1;
            } else if (lbl_8030A10C.col != col) {
                w->sub = 3;
            } else {
                w->sub = 2;
            }
        } else {
            w->sub = 4;
        }
        lim = (int)(255.0f * u->scale);
        alpha = w->cmd->alpha;
        t = lim + 0xff;
        if (alpha > t) {
            alpha = t;
        }
        if (w->sub == 3 || w->sub == 4) {
            u->col = (w->cmd->c3 << 24) | (w->cmd->c2 << 16) | (w->cmd->c1 << 8);
        } else {
            u->col = (w->cmd->c3 << 24) | (w->cmd->c2 << 16) | (w->cmd->c1 << 8) | alpha;
            u->on = 1;
        }
        u->val = w->cmd->init;
        node->state = 3;
    case 3:
        if (w->timer >= w->cmd->riseStart && w->timer < w->cmd->riseEnd) {
            u->val += w->cmd->rise;
        }
        if (w->timer >= w->cmd->fallStart && w->timer < w->cmd->fallEnd) {
            u->val += w->cmd->fall;
            if (u->val < 0.0f) {
                node->state = 0xFA;
            }
        }
        if (u->val > w->cmd->max) {
            u->val = w->cmd->max;
        }
        if (u->val < 0.0f) {
            u->val = 0.0f;
        }
        if (w->timer > w->cmd->riseEnd && w->timer > w->cmd->fallEnd) {
            node->state = 0xFA;
        }
        break;
    case 0xF9:
    case 0xFA:
        fn_8006D8DC(1);
        if (w->sub == 1) {
            lbl_8030A10C.input &= ~0x80000;
        }
        if (u->on != 0) {
            u->on = 0;
        }
        u->val = 0.0f;
        node->flags |= 0x40;
        lbl_8030A10C.count--;
        return;
    }
    w->timer++;
    fn_80037FD8(w->cmd, &node->state);
}

void fn_8004DB90(Node_8004DB90* node) {
    TW_8004DB90* tw;
    Wk_8004DB90* w;
    Own_8004DB90* own;
    Unit_8004DB90* u;
    s16 i;

    w = node->work;
    own = w->own;
    tw = own->t->work;
    u = tw->w;

    switch (node->state) {
    case 0:
        fn_8006D954(own->cmd->src);
        node->state = 1;
        node->work->x50 = own->cmd->src;
        node->work->x54 = -1;
    case 1:
        if (u->x1f4 != NULL) {
            node->state = 0xFA;
            break;
        }
        fn_80061F58(&u->x1f4, 8, 0);
        *u->x1f4 = *tw->arr;
        fn_80061F58(&u->x1f4->data, tw->arr->count * 12, 0);
        memcpy(u->x1f4->data, tw->arr->data, tw->arr->count * 12);
        for (i = 0; i < tw->arr->count; i++) {
            u->x1f4->data[i] = **w->v;
        }
        node->state = 2;
        break;
    case 2:
        node->state = 0xFA;
        break;
    case 0xF9:
    case 0xFA:
        fn_8006D8DC(own->cmd->src);
        fn_801E17E0(own);
        node->flags |= 0x40;
        lbl_8030A10C.count--;
        return;
    }
    fn_80037FD8(own->cmd, &node->state);
}

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

void fn_8004F84C(NJS_VECTOR* v) {
    v->x = -1.16f;
    v->y = -0.23f;
    v->z = -0.71f;
}
