#include "types.h"
#include "ninja.h"
#include "game/task.h"

/* Battle character record (character task work +0x4C). */
typedef struct BtlUnit {
    s8 id;              /* 0x000 */
    u8 pad1[3];
    s8 target;          /* 0x004 */
    u8 pad5;
    s16 type;           /* 0x006 */
    u8 pad8[0x50 - 0x8];
    u32 x50;            /* 0x050 */
    u8 pad54[0xEC - 0x54];
    u32 shape;          /* 0x0EC */
    u32 flags;          /* 0x0F0 */
    u8 padF4[0x110 - 0xF4];
    NJS_POINT3 home;    /* 0x110 */
    u8 pad11C[0x12C - 0x11C];
    f32 step;           /* 0x12C */
    u8 pad130[0x15C - 0x130];
    f32 height;         /* 0x15C */
    u8 pad160[0x298 - 0x160];
    s32 x298;           /* 0x298 */
} BtlUnit;

typedef struct ActRes {
    u8 pad0[0x30];
    void *p30;          /* 0x30 */
} ActRes;

/* Work of a battle character task. */
typedef struct Actor {
    u8 pad0[0x10];
    ActRes *res;        /* 0x10 */
    u8 pad14[0x1C - 0x14];
    NJS_POINT3 pos;     /* 0x1C */
    Angle ang28;        /* 0x28 */
    Angle ang;          /* 0x2C */
    u8 pad30[0x4C - 0x30];
    BtlUnit *unit;      /* 0x4C */
} Actor;

/* A task (game/task.h) whose work is an Actor. */
typedef struct ActTask {
    u8 pad0[0x24];
    Actor *work;        /* 0x24 */
} ActTask;

/* Command header shared by every effect command (fn_80037FD8). */
typedef struct CmdHead {
    u8 pad0[0x6];
    s16 flags;          /* 0x06 */
    s32 src;            /* 0x08 */
    u8 pad0c[0x4];
} CmdHead;

/* Camera move command (Pawn.mv). */
typedef struct Move {
    CmdHead c;
    u32 flags;          /* 0x10 */
    f32 f14;            /* 0x14 */
    s16 start;          /* 0x18 */
    u8 pad1A[2];
    s16 end;            /* 0x1C */
    s16 s1e;            /* 0x1E */
    s16 s20;            /* 0x20 */
    s16 kind;           /* 0x22 */
} Move;

/* Battle camera (0x17C bytes, work of fn_80051264). */
typedef struct Pawn {
    u8 pad0[0x20];
    NJS_POINT3 pos;     /* 0x020 */
    Angle rot[3];       /* 0x02C */
    NJS_POINT3 at;      /* 0x038 */
    u8 pad44[0x68 - 0x44];
    u32 f68;            /* 0x068 */
    u32 f6c;            /* 0x06C */
    s16 frame;          /* 0x070 */
    u8 pad72[2];
    ActTask *child;     /* 0x074 */
    u8 pad78[4];
    s8 ids[8];          /* 0x07C */
    u8 pad84[4];
    f32 f88;            /* 0x088 */
    NJS_POINT3 v8c;     /* 0x08C */
    NJS_POINT3 v98;     /* 0x098 */
    NJS_POINT3 vA4;     /* 0x0A4 */
    NJS_POINT3 vB0;     /* 0x0B0 */
    u8 padBC[0xD4 - 0xBC];
    f32 fd4;            /* 0x0D4 */
    f32 fd8;            /* 0x0D8 */
    f32 fdc;            /* 0x0DC */
    u8 padE0[4];
    f32 fe4;            /* 0x0E4 */
    NJS_POINT3 vE8;     /* 0x0E8 */
    NJS_POINT3 vF4;     /* 0x0F4 */
    NJS_POINT3 v100;    /* 0x100 */
    s16 count;          /* 0x10C */
    s16 step;           /* 0x10E */
    s16 kind;           /* 0x110 */
    s16 kind2;          /* 0x112 */
    u8 pad114[0x178 - 0x114];
    Move *mv;           /* 0x178 */
} Pawn;

typedef struct CamHold {
    u8 pad[0x88];
    Pawn o;             /* 0x88 */
} CamHold;
extern CamHold lbl_80309EC8;

typedef struct Game {
    u8 pad0[0xC];
    void *p0c;          /* 0x00C */
    void *p10;          /* 0x010 */
    u8 pad14[0x180 - 0x14];
    void *x180;         /* 0x180 */
    void *x184;         /* 0x184 */
    u8 pad188[0x1C4 - 0x188];
    s32 count;          /* 0x1C4 */
    u8 pad1C8[4];
    u32 flags;          /* 0x1CC */
} Game;
extern Game lbl_8030A10C;

/* Character swap command (fn_800506B0). */
typedef struct SwapCmd {
    CmdHead c;
    s16 start;          /* 0x10 */
    s16 end;            /* 0x12 */
    NJS_POINT3 p14;     /* 0x14 */
    f32 scaleA;         /* 0x20 */
    NJS_POINT3 p24;     /* 0x24 */
    f32 scaleB;         /* 0x30 */
} SwapCmd;
typedef struct SwapWork {
    u16 frame;          /* 0x00 */
    u8 pad2[2];
    ActTask *a;         /* 0x04 */
    ActTask *b;         /* 0x08 */
    NJS_POINT3 saveA;   /* 0x0C */
    NJS_POINT3 saveB;   /* 0x18 */
    s32 x24;            /* 0x24 */
    s32 x28;            /* 0x28 */
    SwapCmd *cfg;       /* 0x2C */
    s8 mode;            /* 0x30 */
} SwapWork;
typedef struct SwapTask {
    u8 pad0[0x18];
    u8 flags;           /* 0x18 */
    u8 state;           /* 0x19 */
    u8 pad1A[0x24 - 0x1A];
    SwapWork *work;     /* 0x24 */
} SwapTask;

/* Hit command (fn_80050DB0). */
typedef struct HitCmd {
    CmdHead c;
    s16 start;          /* 0x10 */
    s16 x12;            /* 0x12 */
    s16 x14;            /* 0x14 */
    u8 kind;            /* 0x16 */
    u8 key;             /* 0x17 */
    u8 delay;           /* 0x18 */
    u8 pad19[3];
    u32 flags;          /* 0x1C */
} HitCmd;
typedef struct HitWork {
    s16 frame;          /* 0x00 */
    u8 pad2[2];
    ActTask *a;         /* 0x04 */
    HitCmd *cfg;        /* 0x08 */
} HitWork;
typedef struct HitTask {
    u8 pad0[0x18];
    u8 flags;           /* 0x18 */
    u8 state;           /* 0x19 */
    u8 pad1A[0x24 - 0x1A];
    HitWork *work;      /* 0x24 */
} HitTask;

/* Screen fade command (fn_80050B88). */
typedef struct FadeCmd {
    CmdHead c;
    s16 inStart;        /* 0x10 */
    s16 inLen;          /* 0x12 */
    s16 outStart;       /* 0x14 */
    s16 outLen;         /* 0x16 */
    f32 level;          /* 0x18 */
} FadeCmd;
typedef struct FadeWork {
    u16 cnt;            /* 0x0 */
    u8 pad2[6];
    f32 step;           /* 0x8 */
    FadeCmd *a;         /* 0xC */
} FadeWork;
typedef struct Fade {
    u8 pad0[8];
    u32 flags;          /* 0x08 */
    u8 pad_c[0xc];
    s32 i18;            /* 0x18 */
    f32 level;          /* 0x1C */
    u8 pad20[0xc];
} Fade;
extern Fade lbl_80309E5C;

typedef struct Stage {
    u8 pad0[0x3C];
    u32 flags;          /* 0x3C */
} Stage;
typedef struct StageTask {
    u8 pad0[0x24];
    Stage *work;        /* 0x24 */
} StageTask;
extern StageTask *lbl_80347394;
extern u32 lbl_803472F4;
extern ActTask *lbl_80309E24[12];
extern u8 lbl_80302B38[12];

extern ActTask *fn_8001E05C(ActTask *t);
extern ActTask *fn_80021658(u8 id);
extern Task *fn_8003DB34(void *fn);
extern void fn_80061F58(void *p, s32 size, s32 b);
extern s32 fn_80037FD8(CmdHead *c, u8 *state);
extern void fn_80014AB8(s32 n, Pawn *p);
extern void fn_80014A54(s32 n, Pawn *p);
extern void fn_80071CF0(NJS_POINT3 *src, NJS_POINT3 *dst);
extern void fn_80071CBC(NJS_POINT3 *src, NJS_POINT3 *dst);
extern void fn_80071F84(Angle *rot, NJS_POINT3 *a, NJS_POINT3 *b);
extern void fn_80071BCC(NJS_POINT3 *out, f32 len, Angle ang);
extern f32 fn_80071E9C(NJS_POINT3 *a, NJS_POINT3 *b);
extern void fn_800618FC(NJS_POINT3 *out, NJS_POINT3 *a, NJS_POINT3 *b, f32 angZ, f32 angY, f32 offset);
extern void fn_80061014(NJS_POINT3 *a, NJS_POINT3 *b, NJS_POINT3 *out);
extern void fn_80061450(NJS_POINT3 *a, NJS_POINT3 *b, NJS_POINT3 *out);
extern void fn_800614FC(Angle *src, Angle *dst);
extern s32 fn_800611C0(NJS_POINT3 *a, NJS_POINT3 *b, NJS_POINT3 *c);
extern f32 fn_8006116C(Angle ang);
extern void fn_8001D288(NJS_POINT3 *p, s32 id, f32 a, f32 b);
extern void fn_8001D200(ActTask *t, NJS_POINT3 *p);
extern f32 fn_80011694(NJS_POINT3 *pos, s32 id, NJS_POINT3 *p, f32 *out);
extern f32 fn_8001359C(NJS_POINT3 *at, f32 *out);
extern f32 fn_8001363C(NJS_POINT3 *at, f32 *out);
extern void fn_80013504(NJS_POINT3 *pos, NJS_POINT3 *at, Angle *rot, f32 a, f32 b);
extern void fn_800608C8(f32 *p);
extern void fn_800171F0(u8 id, u8 part, NJS_POINT3 *a, NJS_POINT3 *b);
extern void fn_80051EC8(ActTask *t, s8 *list, NJS_POINT3 *p);
extern void fn_8001604C(ActTask *t, s8 *list, s32 a, s32 b);
extern void fn_80011370(u8 a, s8 b);
extern void fn_80011394(s8 sel);
extern void fn_80011400(s32 a, s32 b);
extern void fn_80032B4C(void);
extern void fn_80032BBC(u8 id, s32 b);
extern void fn_80032B6C(u8 id, s32 b);
extern s32 fn_80008AB4(void *p, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
extern s16 fn_8001D41C(s16 *a, s16 *b);
extern f32 fn_800540DC(Pawn *p);
extern void fn_801E17E0(Move *m);
extern void fn_8006D954(s32 n);
extern void fn_8006D8DC(s32 n);
extern s32 fn_8001D944(u8 key, ActTask *t);
extern void fn_8001D14C(BtlUnit *s);
extern void fn_8002ECA4(BtlUnit *s, u8 key);
extern void fn_8002E48C(ActTask *t);
extern void fn_80008694(ActTask *t, s16 a, s16 b, void *p);
extern void fn_800085EC(ActTask *t, s16 a, s16 b, void *p, void *q);
extern f32 njSin(s32 a);
extern s32 rand(void);

void fn_80051264(Task *t);
void fn_8005174C(Pawn *p);
void fn_800519F4(Pawn *p);
f32 fn_80051FA0(ActTask *t, s8 *list, NJS_POINT3 *outA, NJS_POINT3 *outB);
void fn_80052058(Pawn *o);
void fn_800521C4(Pawn *p);
void fn_8005259C(Pawn *p);
void fn_80052B24(Pawn *p);
void fn_80052ECC(Pawn *p);
void fn_800534B0(Pawn *p);
void fn_80053964(Pawn *o);
void fn_80053C48(Pawn *p);

void fn_800506B0(SwapTask *t)
{
    SwapWork *w = t->work;
    BtlUnit *sa;
    BtlUnit *sb;
    Angle rot[3];
    NJS_POINT3 v;

    switch (t->state) {
    case 0:
        if (w->frame < w->cfg->start)
            break;
        sa = w->a->work->unit;
        if ((0.0f == w->cfg->p24.x && 0.0f == w->cfg->p24.y && 0.0f == w->cfg->p24.z && 0.0f == w->cfg->scaleB)
            || sa->id == sa->target)
            w->mode = 1;
        if (w->cfg->c.flags & 0x4000)
            w->mode = 2;
        switch (w->mode) {
        case 0:
        case 1:
            fn_80071CF0(&w->a->work->pos, &w->saveA);
            fn_80071CF0(&w->cfg->p14, &w->a->work->pos);
            w->x24 = w->a->work->ang;
            w->a->work->pos.y = w->saveA.y;
            w->a->work->ang = (s32)(182.04445f * w->cfg->scaleA);
        }
        switch (w->mode) {
        case 0:
        case 2:
            w->b = fn_8001E05C(w->a);
            sb = w->b->work->unit;
            fn_80071CF0(&w->b->work->pos, &w->saveB);
            fn_80071CF0(&w->cfg->p24, &w->b->work->pos);
            w->x28 = w->b->work->ang;
            w->b->work->pos.y = w->saveB.y;
            w->b->work->ang = (s32)(182.04445f * w->cfg->scaleB);
            sb->flags |= 0x40000000;
            sb->flags |= 0x80;
        }
        switch (w->mode) {
        case 0:
        case 1:
            sa = w->a->work->unit;
            sa->flags |= 0x40000000;
            sa->flags |= 0x80;
        }
        switch (w->mode) {
        case 0:
            if (sa->shape & 0x200000) {
                fn_80071F84(rot, &w->a->work->pos, &w->b->work->pos);
                fn_80071BCC(&v, 15.0f, rot[1]);
                w->a->work->pos.x += v.x;
                w->a->work->pos.z += v.z;
            }
            sb = w->b->work->unit;
            sb->flags |= 0x40000000;
            sb->flags |= 0x80;
            if (sb->shape & 0x200000) {
                fn_80071F84(rot, &w->b->work->pos, &w->a->work->pos);
                fn_80071BCC(&v, 15.0f, rot[1]);
                w->b->work->pos.x += v.x;
                w->b->work->pos.z += v.z;
            }
        }
        t->state = 1;
        /* fall through */
    case 1:
        if (w->frame != w->cfg->end)
            break;
        switch (w->mode) {
        case 0:
        case 1:
            fn_80071CF0(&w->saveA, &w->a->work->pos);
            w->a->work->ang = w->x24;
            sa = w->a->work->unit;
            sa->flags &= ~0x40000000;
            sa->flags &= ~0x80;
        }
        switch (w->mode) {
        case 0:
        case 2:
            fn_80071CF0(&w->saveB, &w->b->work->pos);
            w->b->work->ang = w->x28;
            sb = w->b->work->unit;
            sb->flags &= ~0x40000000;
            sb->flags &= ~0x80;
        }
        t->state = 0xfa;
        break;
    case 0xf9:
    case 0xfa:
        t->flags |= 0x40;
        lbl_8030A10C.count--;
        return;
    }
    w->frame++;
    fn_80037FD8(&w->cfg->c, &t->state);
}

void fn_80050B88(Task *o) {
    FadeWork *s = o->work;
    switch (o->state) {
    case 0:
        {
            FadeCmd *a = s->a;
            Fade *g;
            if (s->cnt < a->inStart) {
                break;
            }
            g = &lbl_80309E5C;
            s->step = (1.0f - a->level) / a->inLen;
            g->flags |= 0x8000000;
            g->i18 = 255;
            g->level = 0.0f;
        }
        o->state = 1;
    case 1:
        if (s->cnt >= s->a->inStart && s->a->inLen != 0 && s->cnt < s->a->inStart + s->a->inLen) {
            lbl_80309E5C.level = lbl_80309E5C.level + s->step;
        }
        if (s->cnt >= s->a->outStart && s->a->outLen != 0) {
            if (s->cnt == s->a->outStart) {
                s->step = lbl_80309E5C.level / s->a->outLen;
            }
            if (s->cnt < s->a->outStart + s->a->outLen) {
                lbl_80309E5C.level = lbl_80309E5C.level - s->step;
            }
        }
        if (s->cnt >= s->a->inStart + s->a->inLen && s->cnt >= s->a->outStart + s->a->outLen) {
            o->state = 0xfa;
        }
        break;
    case 0xf9:
    case 0xfa:
        lbl_80309E5C.level = 0.0f;
        lbl_80309E5C.flags &= ~0x8000000;
        o->flags |= 0x40;
        lbl_8030A10C.count--;
        return;
    }
    s->cnt = s->cnt + 1;
    fn_80037FD8(&s->a->c, &o->state);
}

void fn_80050DB0(HitTask *t)
{
    ActTask *o;
    HitWork *w;
    s8 i;
    BtlUnit *os;
    BtlUnit *sub;
    s32 hit;

    w = t->work;
    sub = w->a->work->unit;

    switch (t->state) {
    case 0:
        fn_8006D954(1);
        if (w->cfg->flags & 0x1000)
            sub->shape |= 0x80000;
        t->state = 1;
    case 1:
        if (w->frame < w->cfg->start)
            break;
        t->state = 3;
    case 3:
    case 4:
        for (i = 0; i < 12; i++) {
            o = lbl_80309E24[i];
            if (o != NULL) {
                hit = 0;
                os = o->work->unit;
                switch (w->cfg->kind) {
                case 0:
                    if (fn_8001D944(os->id, t->work->a) == 0)
                        hit = 1;
                    break;
                case 1:
                    if (fn_8001D944(os->id, t->work->a) != 0)
                        hit = 1;
                    break;
                case 2:
                    if (os->id == sub->id)
                        hit = 1;
                    break;
                case 3:
                    if (os->id == sub->target)
                        hit = 1;
                    break;
                case 4:
                    if (os->id == w->cfg->key && sub->id != w->cfg->key)
                        hit = 1;
                    break;
                }
                if (hit != 0) {
                    if (t->state == 3 || t->state == 5) {
                        HitCmd *c = w->cfg;
                        if (c->flags & 0x20000000) {
                            fn_80008694(o, c->x12, c->x14 + 300, w->a->work->res->p30);
                        } else if (c->flags & 0x8000) {
                            if (c->flags & 0x10)
                                fn_800085EC(o, c->x12, c->x14 + 100, lbl_8030A10C.p10, lbl_8030A10C.x184);
                            else
                                fn_800085EC(o, c->x12, c->x14, lbl_8030A10C.p10, lbl_8030A10C.x184);
                        } else {
                            fn_800085EC(o, c->x12, c->x14, lbl_8030A10C.p0c, lbl_8030A10C.x180);
                        }
                    }
                    if (w->cfg->flags & 0x800) {
                        if (w->cfg->delay != 0 && (t->state == 3 || t->state == 5)) {
                            t->state = 5;
                        } else {
                            fn_8002ECA4(sub, os->id);
                            if (w->cfg->flags & 0x100)
                                fn_8002E48C(o);
                        }
                    }
                }
            }
        }
        if (t->state != 5)
            t->state = 0xfa;
        else
            w->frame = 0;
        break;
    case 5:
        if (w->frame < w->cfg->delay)
            break;
        t->state = 4;
        break;
    case 6:
        if (lbl_8030A10C.flags & 0x20) {
            t->state = 1;
            w->frame = w->cfg->start;
        }
        break;
    case 0xf9:
        fn_8006D8DC(1);
        t->flags |= 0x40;
        lbl_8030A10C.count--;
        return;
    case 0xfa:
        fn_8006D8DC(1);
        fn_8001D14C(sub);
        t->flags |= 0x40;
        lbl_8030A10C.count--;
        return;
    }
    w->frame++;
    if (w->cfg->c.flags & 0x1000) {
        fn_80037FD8(&w->cfg->c, &t->state);
    } else if (w->cfg->c.flags & 0x2000) {
        switch (t->state) {
        case 1:
            break;
        default:
            lbl_8030A10C.flags |= 0x10;
        }
        if ((lbl_8030A10C.flags & 0x80) && !(lbl_8030A10C.flags & 0x20)) {
            switch (t->state) {
            case 1:
                t->state = 6;
            }
        }
    }
}

void fn_8005121C(void)
{
    s32 i;

    for (i = 0; i < 12; i++) {
        lbl_80302B38[i] = 0;
    }
}

void fn_80051264(Task *t)
{
    Pawn *p = t->work;
    BtlUnit *sub = p->child->work->unit;
    f32 d;

    if (sub->shape & 0x400000)
        t->state = 0xfa;
    else
        fn_8001E05C(p->child);

    switch (t->state) {
    case 0:
        if ((lbl_80347394 != NULL && (lbl_80347394->work->flags & 0x80)) || (lbl_803472F4 & 0x40000000)) {
            t->state = 3;
            return;
        }
        fn_800519F4(p);
        if ((p->mv->flags & 0x80000000) && lbl_80347394 == NULL)
            fn_8006D954(1);
        t->state = 1;
    case 1:
        fn_80011394(0);
        switch (p->mv->kind) {
        case 0x10:
            if (!(p->mv->flags & 0x10000000))
                fn_80032BBC(sub->id, 0);
        }
        if (p->mv->kind == 0x11) {
            t->state = 2;
            p->kind = p->mv->kind;
        } else if (sub->flags & 0x10000000) {
            t->state = 2;
            switch (p->mv->kind) {
            case 0:
                if (rand() % 2 == 0 && lbl_80347394 == NULL)
                    p->mv->kind = 0xe;
                p->kind = 0;
                break;
            default:
                p->kind = p->mv->kind;
            }
        } else {
            break;
        }
        p->kind2 = p->mv->kind;
    case 2:
        if (p->mv->start < p->mv->end && p->frame >= p->mv->end) {
            t->state = 0xfa;
            return;
        }
        if (p->f68 & 0x20000000) {
            t->state = 0xfa;
            return;
        }
        switch (p->mv->kind) {
        case 7:
        case 8:
        case 9:
        case 18:
            fn_80053964(p);
            break;
        case 15:
        case 16:
            fn_80053C48(p);
            break;
        case 2:
            fn_800534B0(p);
            break;
        case 1:
            fn_8005259C(p);
            break;
        case 0:
            fn_80052ECC(p);
            break;
        case 14:
            fn_80052B24(p);
            break;
        case 10:
        case 11:
            fn_80052058(p);
            break;
        case 17:
            fn_800521C4(p);
            break;
        default:
            sub = p->child->work->unit;
            fn_8001E05C(p->child);
            switch (p->step) {
            case 0:
                if (p->frame < p->mv->start)
                    break;
                fn_80014AB8(1, p);
                p->step = 1;
            case 1:
                d = fn_80071E9C(&p->v8c, &p->v98);
                fn_800618FC(&p->pos, &p->v8c, &p->v98, 0.0f, p->fd8, 0.5f * (p->f88 - d));
                p->fd8 += p->fdc;
                p->pos.y = p->pos.y + (p->f88 * njSin((s32)(182.04445f * p->fd4)) + 30.0f);
                if (p->pos.y < 3.75f)
                    p->pos.y = 3.75f;
                fn_80071F84(p->rot, &p->at, &p->pos);
                fn_80011370(sub->id, -1);
            }
        }
        if (p->pos.y < 1.0f)
            p->pos.y = 1.0f;
        break;
    case 0xf9:
    case 0xfa:
        p->mv->kind = p->kind;
        fn_80014A54(1, p);
        if ((p->mv->flags & 0x80000000) && lbl_80347394 == NULL)
            fn_8006D8DC(1);
        switch (p->mv->kind) {
        case 0x11:
            if (sub->flags & 0x02000000)
                sub->flags &= ~0x02000000;
        }
        if (p->f6c & 0x80000000)
            fn_801E17E0(p->mv);
        t->flags |= 0x40;
        lbl_8030A10C.count--;
        return;
    case 3:
        t->flags |= 0x40;
        lbl_8030A10C.count--;
        return;
    }
    if (p->mv->start < p->mv->end && p->frame >= p->mv->end) {
        t->state = 0xfa;
        return;
    }
    if (p->f68 & 0x20000000) {
        t->state = 0xfa;
        return;
    }
    switch (t->state) {
    case 0:
    case 1:
        break;
    default:
        p->frame++;
    }
    fn_80037FD8(&p->mv->c, &t->state);
}

void fn_8005174C(Pawn *o) {
    f32 ang;
    f32 bestAng;
    f32 best;
    ActTask *c0;
    ActTask *c1;
    s16 i;
    s32 id0;
    s32 id1;
    f32 tmp[2];
    f32 a, sum;
    best = 0.0f;
    ang = o->fd8;
    bestAng = ang;
    c0 = o->child;
    c1 = fn_8001E05C(c0);
    id0 = c0->work->unit->id;
    id1 = c1->work->unit->id;
    for (i = 0; i < 12; i++) {
        o->fd8 = ang;
        a = fn_80071E9C(&o->v8c, &o->v98);
        fn_800618FC(&o->vF4, &o->v8c, &o->v98, 0.0f, o->fd8, 0.5f * (o->f88 - a));
        o->fd8 = o->fd8 + o->fdc;
        o->vF4.y = o->vF4.y + (o->f88 * njSin((s32)(182.04445f * o->fd4)) + 30.0f);
        if (o->vF4.y < 3.75f) {
            o->vF4.y = 3.75f;
        }
        fn_80071F84(o->rot, &o->at, &o->vF4);
        a = fn_80011694(&c0->work->pos, id0, &o->vF4, tmp);
        sum = a + fn_80011694(&c1->work->pos, id1, &o->vF4, tmp);
        if (sum >= best) {
            bestAng = ang;
            best = sum;
        }
        ang += 10.0f;
    }
    o->fd8 = bestAng;
    a = fn_80071E9C(&o->v8c, &o->v98);
    fn_800618FC(&o->vF4, &o->v8c, &o->v98, 0.0f, o->fd8, 0.5f * (o->f88 - a));
    o->fd8 = o->fd8 + o->fdc;
    o->vF4.y = o->vF4.y + (o->f88 * njSin((s32)(182.04445f * o->fd4)) + 30.0f);
    if (o->vF4.y < 3.75f) {
        o->vF4.y = 3.75f;
    }
    fn_80071F84(o->rot, &o->at, &o->vF4);
}

void fn_800519F4(Pawn *p)
{
    BtlUnit *u = p->child->work->unit;
    s16 k = 0;
    BtlUnit *ou;
    f32 e, d, f;
    s32 i;

    switch (p->mv->kind) {
    case 0:
    case 1:
        for (i = 0; i < 8; i++)
            p->ids[i] = -1;
        p->ids[0] = u->target;
        p->f88 = fn_80051FA0(p->child, p->ids, &p->v8c, &p->v98);
        break;
    case 4:
        fn_8001604C(p->child, p->ids, 1, 0);
        p->f88 = fn_80051FA0(p->child, p->ids, &p->v8c, &p->v98);
        break;
    case 5:
        fn_8001604C(p->child, p->ids, 3, 0);
        p->f88 = fn_80051FA0(p->child, p->ids, &p->v8c, &p->v98);
        break;
    }

    switch (p->mv->kind) {
    case 0:
    case 1:
    case 4:
    case 5:
        p->f88 = p->f88 + (0.6f * p->f88 + 22.5f);
        fn_80051EC8(p->child, p->ids, &p->vE8);
    }

    switch (p->mv->kind) {
    case 1:
    case 4:
    case 5: {
        Angle rot[3];
        NJS_POINT3 a;
        fn_80061450(&p->v8c, &p->v98, &p->at);
        fn_80071CF0(&p->v98, &a);
        a.y = p->vE8.y;
        fn_80071F84(rot, &p->at, &a);
        p->fd4 = 360.0 * (rot[0] & 0xFFFF) / 65536.0;
        p->fd4 *= 0.5f;
        p->fd8 = 45.0f * (f32)(rand() % 7) + 45.0f;
        break;
    }
    case 0:
        ou = fn_80021658(u->target)->work->unit;
        e = u->height;
        f = ou->height;
        d = e - f;
        i = 0;
        if (d < 0.0f)
            d = -1.0f * d;
        if (d < 3.75f) {
            f *= 0.5f;
            k = 8 + rand() % 4;
        } else if (e > ou->height) {
            k = 4 + rand() % 2;
        } else {
            k = 2 + rand() % 2;
        }
        switch (k) {
        case 0:
        case 4:
        case 8:
            p->fd8 = 200.0f;
            break;
        case 1:
        case 5:
        case 9:
            p->fd8 = 160.0f;
            break;
        case 2:
        case 6:
        case 10:
            p->fd8 = 20.0f;
            break;
        case 3:
        case 7:
        case 11:
            p->fd8 = 340.0f;
            break;
        }
        break;
    }

    switch (p->mv->kind) {
    case 1:
    case 4:
    case 5: {
        NJS_POINT3 a, b;
        fn_80071CF0(&p->v8c, &a);
        a.y = u->height;
        fn_80071CF0(&p->v98, &b);
        b.y = p->vE8.y;
        fn_80061450(&a, &b, &p->at);
        p->at.y *= 0.5f;
        break;
    }
    case 0: {
        NJS_POINT3 a, b;
        fn_80071CF0(&p->v8c, &a);
        a.y = u->height;
        fn_80071CF0(&p->v98, &b);
        b.y = f;
        fn_80061450(&a, &b, &p->at);
        break;
    }
    }

    switch (p->mv->kind) {
    case 0: {
        Angle rot[3];
        switch (k) {
        case 0:
        case 1:
        case 6:
        case 7:
            fn_80071F84(rot, &p->at, &p->vE8);
            break;
        default:
            fn_80071F84(rot, &p->vE8, &p->at);
        }
        p->fd4 = 360.0 * (rot[0] & 0xFFFF) / 65536.0;
    }
    }
}

/* Over up to 8 parts (list ends at a negative entry), finds the pair of points fn_800171F0
 * gives with the largest distance; copies that pair to outA/outB and returns the distance. */
f32 fn_80051FA0(ActTask *t, s8 *list, NJS_POINT3 *outA, NJS_POINT3 *outB) {
    s16 i;
    BtlUnit *c = t->work->unit;
    f32 best = 0.0f;
    NJS_POINT3 a;
    NJS_POINT3 b;
    f32 d;

    for (i = 0; i < 8; i++) {
        if (list[i] < 0) {
            break;
        }
        fn_800171F0(c->id, list[i], &a, &b);
        d = fn_80071E9C(&a, &b);
        if (d > best) {
            best = d;
            fn_80071CF0(&a, outA);
            fn_80071CF0(&b, outB);
        }
    }
    return best;
}

void fn_80052058(Pawn *o) {
    fn_8001E05C(o->child);
    switch (o->step) {
    case 0:
        o->step = 1;
    case 1:
        if (o->frame < o->mv->start) {
            return;
        }
        fn_80014AB8(1, o);
        if (o->mv->flags & 0x800) {
            fn_8001359C(&o->at, &o->f88);
        } else {
            fn_8001363C(&o->at, &o->f88);
        }
        o->step = 2;
        if (o->mv->flags & 0x20000000) {
            if (o->mv->flags & 0x04000000) {
                fn_800608C8(&o->fd8);
            } else {
                o->fd8 = 0.0f;
            }
        } else {
            if (o->mv->flags & 0x04000000) {
                fn_800608C8(&o->fd8);
            } else {
                o->fd8 = o->mv->f14;
            }
        }
    case 2:
        fn_80013504(&o->pos, &o->at, o->rot, o->f88, o->fd8);
        if (o->mv->flags & 0x20000000) {
            o->fd8 += 1.0f;
        }
        lbl_80309EC8.o = *o;
        break;
    }
}

static inline s32 InBand(s16 v)
{
    switch (v) {
    case 4:
    case 5:
    case 9:
    case 10:
        return 1;
    default:
        return 0;
    }
}

void fn_8005259C(Pawn *p)
{
    s16 x, y;
    ActTask *t = p->child;
    BtlUnit *u = t->work->unit;
    s32 k = 0;

    fn_8001E05C(t);
    if (u->type == 4) {
        if (fn_80008AB4(t->work->res->p30, 4, 0, 0x2a, 3, 2, u->x298))
            k = 1;
    }
    switch (p->step) {
    case 0:
        if (p->frame < p->mv->start)
            break;
        if (fn_8001D41C(&x, &y) != 0 && k == 0) {
            Pawn tmp = lbl_80309EC8.o;
            fn_80014AB8(1, p);
            lbl_80309EC8.o = tmp;
        } else {
            fn_80014AB8(1, p);
        }
        fn_8005174C(p);
        fn_80071CF0(&p->at, &p->v100);
        t = p->child;
        fn_8001D288(&p->pos, t->work->unit->id, 0.0f, 0.0f);
        fn_8001D200(t, &p->at);
        if (p->mv->s20 != 0) {
            fn_80061014(&p->pos, &p->vF4, &p->vA4);
            p->vA4.x /= p->mv->s20;
            p->vA4.y /= p->mv->s20;
            p->vA4.z /= p->mv->s20;
            fn_80061014(&p->at, &p->v100, &p->vB0);
            p->vB0.x /= p->mv->s20;
            p->vB0.y /= p->mv->s20;
            p->vB0.z /= p->mv->s20;
        } else {
            fn_80071CF0(&p->vF4, &p->pos);
            fn_80071CF0(&p->v100, &p->at);
        }
        fn_80071F84(p->rot, &p->at, &p->pos);
        p->count = p->mv->s1e;
        fn_80011370(u->id, -1);
        p->step = 1;
    case 1:
        if (p->count != 0) {
            p->count--;
            fn_80011370(u->id, -1);
            fn_80011400(u->id, 0);
            fn_80032BBC(u->id, 0);
        } else {
            p->count = p->mv->s20;
            fn_80011370(u->id, u->target);
            fn_80011400(u->id, 0);
            fn_80011400(u->target, 0);
            p->step = 2;
            if (InBand(u->type))
                fn_80032BBC(u->id, 1);
            fn_80032B6C(u->id, 1);
        }
        break;
    case 2:
        if (p->count != 0) {
            fn_80011370(u->id, u->target);
            fn_80011400(u->id, 0);
            fn_80011400(u->target, 1);
            fn_80071CBC(&p->vA4, &p->pos);
            fn_80071CBC(&p->vB0, &p->at);
            fn_80071F84(p->rot, &p->at, &p->pos);
            p->count--;
        } else {
            fn_80011370(u->id, u->target);
            fn_80011400(u->id, 0);
            fn_80011400(u->target, 1);
            if (!(p->mv->flags & 0x10000000)) {
                if (InBand(u->type))
                    fn_80032BBC(u->target, 1);
            }
        }
        break;
    }
    if (fn_8001D41C(&x, &y) != 0 && k == 0) {
        fn_80071CF0(&lbl_80309EC8.o.pos, &p->pos);
        fn_80071CF0(&lbl_80309EC8.o.at, &p->at);
        fn_800614FC(lbl_80309EC8.o.rot, p->rot);
    } else {
        lbl_80309EC8.o = *p;
    }
}

void fn_800534B0(Pawn *p)
{
    ActTask *t;
    ActTask *t2;
    BtlUnit *u;
    Angle rot[3];
    f32 f;

    t = p->child;
    u = t->work->unit;
    t2 = fn_8001E05C(p->child);

    if (t == t2 && p->step == 0) {
        if (rand() % 2 != 0)
            p->step = 10;
        else
            p->step = 15;
    }
    switch (p->step) {
    case 0:
        if (p->frame < p->mv->start)
            break;
        fn_80014AB8(1, p);
        fn_80071CF0(&t->work->pos, &p->at);
        fn_8001D200(t2, &p->v100);
        fn_80061014(&p->at, &p->v100, &p->vB0);
        if (p->mv->s20 != 0) {
            p->vB0.x /= p->mv->s20;
            p->vB0.y /= p->mv->s20;
            p->vB0.z /= p->mv->s20;
        }
        fn_80071F84(rot, &p->v100, &u->home);
        f = fn_8006116C(rot[1]);
        f += 180.0f;
        p->fe4 = fn_8006116C(p->child->work->ang);
        p->fd8 = f - p->fe4;
        fn_8001D288(&p->pos, u->id, p->fd8, 0.0f);
        p->pos.y += fn_800540DC(p);
        p->step = 1;
        p->count = p->mv->s1e;
    case 1:
        fn_8006116C(t->work->ang);
        if (p->count != 0) {
            fn_80071CF0(&t->work->pos, &p->at);
            fn_80061014(&p->at, &p->v100, &p->vB0);
            p->vB0.x /= p->mv->s20;
            p->vB0.y /= p->mv->s20;
            p->vB0.z /= p->mv->s20;
            p->count--;
        } else {
            if (fn_800611C0(&p->at, &p->v100, &p->vB0) != 0)
                p->step = 2;
        }
        fn_8001D288(&p->pos, u->id, p->fd8, 0.0f);
        p->pos.y += fn_800540DC(p);
        fn_80071F84(p->rot, &p->at, &p->pos);
        fn_80011370(u->id, u->target);
        fn_80011400(u->id, 0);
        fn_80011400(u->target, 0);
        break;
    case 15:
        fn_80014AB8(1, p);
        p->v100.x = p->v100.y = p->v100.z = 0.0f;
        p->step = 2;
    case 2:
        fn_8006116C(t->work->ang);
        fn_80071F84(rot, &p->v100, &p->child->work->pos);
        f = fn_8006116C(rot[1]);
        f += 180.0f;
        p->fe4 = fn_8006116C(p->child->work->ang);
        p->fd8 = f - p->fe4;
        fn_8001D288(&p->pos, u->id, p->fd8, 0.0f);
        p->pos.y += fn_800540DC(p);
        fn_80071F84(p->rot, &p->at, &p->pos);
        fn_80011370(u->id, u->target);
        fn_80011400(u->id, 0);
        fn_80011400(u->target, 0);
        break;
    case 10:
        fn_80014AB8(1, p);
        p->step = 11;
    case 11:
        fn_8001D288(&p->pos, t->work->unit->id, 0.0f, 0.0f);
        fn_8001D200(t, &p->at);
        fn_80071F84(p->rot, &p->at, &p->pos);
        fn_80011370(u->id, -1);
        break;
    }
}

void fn_80053964(Pawn *o) {
    ActTask *c;
    BtlUnit *un;
    f32 f;
    switch (o->mv->kind) {
    case 7:
    case 8:
        if (o->mv->flags & 0x40000000) {
            c = o->child;
        } else {
            c = fn_8001E05C(o->child);
        }
        break;
    default:
        if (o->mv->flags & 0x40000000) {
            c = fn_8001E05C(o->child);
        } else {
            c = o->child;
        }
        break;
    }
    un = c->work->unit;
    switch (o->mv->kind) {
    case 7:
    case 9:
    default:
        f = 45.0f;
        break;
    case 8:
    case 0x12:
        f = 75.0f;
        break;
    }
    f *= 1.5f;
    switch (o->step) {
    case 0:
        if (o->frame < o->mv->start) {
            break;
        }
        fn_80014AB8(1, o);
        o->fd8 = 0.0f;
        fn_8001D288(&o->pos, un->id, o->fd8, f);
        o->pos.y += o->mv->f14;
        if (o->mv->flags & 0x08000000) {
            o->pos.y = o->mv->f14;
            fn_80071CF0(&o->child->work->pos, &o->at);
            o->at.y += o->mv->f14;
        } else {
            fn_8001D200(c, &o->at);
        }
        fn_80071F84(o->rot, &o->at, &o->pos);
        fn_80011370(un->id, -1);
        if (!(o->mv->flags & 0x10000000)) {
            fn_80032B4C();
        }
        o->step = 1;
    case 1:
        fn_80011370(un->id, -1);
        if (o->mv->flags & 0x20000000) {
            fn_8001D288(&o->pos, un->id, o->fd8, f);
            o->pos.y += o->mv->f14;
            if (o->mv->flags & 0x08000000) {
                o->pos.y = o->mv->f14;
                fn_80071CF0(&o->child->work->pos, &o->at);
                o->at.y += o->mv->f14;
            } else {
                fn_8001D200(c, &o->at);
            }
            o->fd8 += 1.0f;
        }
        fn_80071F84(o->rot, &o->at, &o->pos);
        if (!(o->mv->flags & 0x10000000)) {
            if (!(o->f68 & 0x20000000)) {
                fn_80032BBC(un->id, 1);
            } else {
                fn_80032BBC(un->id, 0);
            }
        }
        break;
    }
    fn_80011400(un->id, 0);
}

void fn_80053F38(u8 id, s8 b) {
    Task *c;
    Pawn *w;
    Move *ev;
    ActTask *t;
    BtlUnit *u;
    s16 half = 1;
    s16 kind = b;
    t = fn_80021658(id);
    if (t != 0) {
        u = t->work->unit;
        if (!(u->shape & 0x100000)) {
            if (b == 0) {
                switch (u->type) {
                default: {
                    s16 q;
                    kind = 2;
                    q = (s16)(s32)(fn_80071E9C(&t->work->pos, &u->home) / u->step);
                    half = q - q % 2;
                    break;
                }
                case 4:
                case 8:
                    kind = 0xe;
                    break;
                case 5:
                    kind = 1;
                    break;
                case 29:
                    kind = 1;
                    break;
                case 12:
                    kind = 0xf;
                    break;
                case 17:
                    kind = 0x10;
                    break;
                }
            } else {
                u->flags |= 0x2000000;
                kind = 0x11;
                if (u->flags & 4) {
                    kind = 0x11;
                }
            }
            fn_80061F58(&ev, 0x24, 0);
            ev->kind = kind;
            switch (kind) {
            case 6:
                ev->s1e = half / 2;
                ev->s20 = half / 2;
                break;
            }
            c = fn_8003DB34(fn_80051264);
            fn_80061F58(&c->work, 0x17c, 0);
            w = c->work;
            w->mv = ev;
            w->child = t;
            w->f6c |= 0x80000000;
        }
    }
}
