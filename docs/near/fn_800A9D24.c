/* fn_800A9D24 (5.4 KB, a screen-quad effect task): a near miss, 24 fdiff lines.
 *
 *   python tools/match/fdiff.py docs/near/fn_800A9D24.c fn_800A9D24
 * Everything matches except the volatile registers in the texture-scroll block at the end of
 * state 2 (12 instructions): the original keeps the config pointer in r4 (the link pointer's
 * register) and the scroll-end loads in r5/r6, where this build puts the config in r8. Tried
 * without effect: the config in a block or function-scope variable, an accessor inline, the
 * block as an inline function (with and without the config as a parameter, all declaration
 * orders), `du +=` forms, the shared ease condition as an inline, a 120-step declaration-order
 * search and 5,000 permuter iterations.
 *
 * The effect draws one quad (Obj_800A1BA4's layout, with byte access to the vertex colours)
 * through fn_800A1BA4. Over the effect's time line (`timer`, fade-in `fadein`, length `length`,
 * fade-out `fadeout`) it fades in and out; after `delay` frames its corners and colours move
 * from the config's `from` keys to its `to` keys over `time` frames, and its texture scrolls.
 *
 * What the original shows:
 * - `(s32)w->x1fa == 1` (a signed compare of the byte, as unit_8010E164 spells it too).
 * - fn_800A1AE8's count compared signed, and `(s32)count > 4`.
 * - The vertex tint loop indexes `q->v[i]` (the original strength-reduces it to a pointer at
 *   the quad, offsets folded into the displacements).
 * - `du`/`dv` are `s16`: as `s32` the value before and after the scroll step lands in two
 *   registers and needs copies.
 */
#include "../src/game/unit_800972AC.c" /* found through -i include */

typedef struct QuadVtx {
    f32 x, y;
    u8 a, r, g, b;
} QuadVtx;

typedef struct Quad {
    u8 pad0[8];
    s16 id;         /* 0x08 */
    u8 alpha;       /* 0x0A */
    u8 pad0b;
    QuadVtx v[4];   /* 0x0C */
    s16 u;          /* 0x3C */
    s16 w;          /* 0x3E */
    void* tex;      /* 0x40 */
} Quad;

typedef struct QuadKey {
    f32 x, y;
    u32 r, g, b;
} QuadKey;

typedef struct QuadCfg {
    u32 count;      /* 0x00 */
    u8 pad4[0x10];
    u32 flags;      /* 0x14 */
    u32 x18;        /* 0x18 */
    u8 pad1c[8];
    u32 x24;        /* 0x24 */
    u32 full;       /* 0x28 */
    u32 x2c;        /* 0x2C */
    u32 x30;        /* 0x30 */
    u32 loop;       /* 0x34 */
    u32 alpha;      /* 0x38 */
    u32 tint;       /* 0x3C */
    u32 fadein;     /* 0x40 */
    u32 length;     /* 0x44 */
    u32 fadeout;    /* 0x48 */
    s32 du;         /* 0x4C */
    s32 dv;         /* 0x50 */
    u32 z;          /* 0x54 */
    QuadKey from[4]; /* 0x58 */
    u32 delay;      /* 0xA8 */
    u32 time;       /* 0xAC */
    s32 du2;        /* 0xB0 */
    s32 dv2;        /* 0xB4 */
    QuadKey to[4];  /* 0xB8 */
} QuadCfg;

typedef struct QuadLink {
    u8 pad0[0x10];
    QuadCfg* cfg;
} QuadLink;

typedef struct QuadHkHdr {
    u8 pad0[8];
    u32 x8;
} QuadHkHdr;

typedef struct QuadHk {
    QuadHkHdr* hdr;
} QuadHk;

typedef struct QuadSub {
    u8 pad0[0x1A0];
    s32 x1a0;
} QuadSub;

typedef struct QuadWork {
    u8 pad0[0x1C];
    f32 fade;           /* 0x01C */
    u8 pad20[0xC];
    s32 x2c;            /* 0x02C */
    u8 pad30[0x100 - 0x30];
    QuadHk* x100;       /* 0x100 */
    u8 pad104[0x170 - 0x104];
    s16 x170;           /* 0x170 */
    s16 x172;           /* 0x172 */
    u8 pad174[2];
    u16 x176;           /* 0x176 */
    u8 pad178[0x1C8 - 0x178];
    QuadLink* link;     /* 0x1C8 */
    u8 pad1cc[0x1D8 - 0x1CC];
    QuadSub* x1d8;      /* 0x1D8 */
    u8 pad1dc[0x1FA - 0x1DC];
    u8 x1fa;            /* 0x1FA */
    u8 x1fb;            /* 0x1FB */
    s16 timer;          /* 0x1FC */
    u8 pad1fe[2];
    s16 wait;           /* 0x200 */
    s16 step;           /* 0x202 */
    s16 x204;           /* 0x204 */
    s16 x206;           /* 0x206 */
    s16 u;              /* 0x208 */
    s16 v;              /* 0x20A */
    u8 pad20c[0x218 - 0x20C];
    s32 x218;           /* 0x218 */
    u8 pad21c[0x22E - 0x21C];
    s16 x22e;           /* 0x22E */
    u8 pad230[2];
    s16 x232;           /* 0x232 */
    u16 x234;           /* 0x234 */
    u8 pad236[0x25C - 0x236];
    Quad* quad;         /* 0x25C */
    void* x260;         /* 0x260 */
    void* x264;         /* 0x264 */
    u8 pad268[4];
    u8 x26c;            /* 0x26C */
} QuadWork;

typedef struct QuadTask {
    u8 pad0[0x18];
    u8 flags;           /* 0x18 */
    u8 state;           /* 0x19 */
    u8 pad1a;
    u8 x1b;             /* 0x1B */
    u8 pad1c[4];
    f32 z;              /* 0x20 */
    QuadWork* work;     /* 0x24 */
} QuadTask;

extern void fn_80296E4C(s32 a);

static inline void QuadReset(QuadWork* w)
{
    w->x1fb = 0;
    w->x1fa = 1;
    w->x232 = 0;
    w->x22e = 0;
    w->x206 = 0;
    w->x204 = 0;
    w->step = 0;
    w->wait = 0;
    w->v = 0;
    w->u = 0;
    w->x218 = 0;
    w->timer = 0;
}

static inline BOOL QuadMapInRange(void)
{
    extern s32 lbl_80311AC0[5];
    s32 in = 0;
    if (lbl_80311AC0[1] >= 500 && lbl_80311AC0[1] < 600) {
        in = 1;
    }
    return in ? TRUE : FALSE;
}

#define QUAD_CFG (w->link->cfg)
#define QUAD_COUNT() (s32)fn_800A1AE8((u8*)w, 0x41)

void fn_800A9D24(QuadTask* o)
{
    DrawState ds;
    u8 b;
    QuadWork* w = o->work;
    Quad* q;
    f32 z;
    s32 tri;
    s16 du;
    s16 dv;
    s32 i;
    u8 a;

    w->x170 = w->x172 = 0;
    if (o->flags & 0x20) {
        o->state = 0xff;
    }
    switch (o->state) {
    case 0:
        o->x1b = 0xfa;
        w->x26c = 1;
        if (QUAD_CFG->count < 0x42) {
            o->state = 4;
            break;
        }
        QuadReset(w);
        w->quad = fn_801E1A2C(1, sizeof(Quad));
        w->x100 = (QuadHk*)fn_800A1B50((Obj_UNIT0000*)w);
        if (w->x100 != NULL) {
            fn_80227810(w->x100);
        }
        fn_8015ED90(o);
        fn_8015EB8C(w, 0, fn_800ABEB0);
        fn_8015EB8C(w, 0xd, fn_800ABE9C);
        if (w->x1d8 != NULL) {
            w->x1d8->x1a0 = 0;
        }
        o->z = -1.5f + -0.03125f * QUAD_CFG->z;
        o->state = 1;
    case 1:
        fn_8015E600((Work_800AE000*)w);
        break;
    case 2:
        q = w->quad;
        if ((s32)w->x1fa == 1) {
            QuadReset(w);
            w->x1fa = 0;
        }
        if (w->timer < QUAD_CFG->fadein) {
            w->fade = -1.0f + (1.0f / QUAD_CFG->fadein) * w->timer;
        } else if (w->timer == QUAD_CFG->fadein) {
            w->fade = 0.0f;
        } else if (w->timer > QUAD_CFG->length - QUAD_CFG->fadeout && QUAD_CFG->length != 0) {
            w->fade = -1.0f + (1.0f / QUAD_CFG->fadeout) * (QUAD_CFG->length - w->timer);
        } else if (w->timer == QUAD_CFG->length) {
            w->fade = -1.0f;
        }
        if (w->x100 != NULL) {
            if (w->x234 == 0 && w->x218 < QUAD_COUNT()) {
                w->x218++;
                if (w->x218 == QUAD_COUNT() && QUAD_CFG->loop == 1) {
                    w->x218 = 0;
                }
                if (w->x218 < QUAD_COUNT()) {
                    w->x234 = (s32)fn_800A10A8(fn_800A1ABC((ObjB_800A1ABC*)w, 0x41), w->x218, QUAD_COUNT()) - 1;
                }
            } else if (w->x218 != QUAD_COUNT()) {
                w->x234--;
            }
            if (w->x218 == QUAD_COUNT() && w->x218 > 0) {
                w->x218 = QUAD_COUNT() - 1;
            }
        }
        if (QUAD_CFG->full == 1) {
            q->v[0].x = 0.0f;
            q->v[0].y = 0.0f;
            q->v[1].x = 640.0f;
            q->v[1].y = 0.0f;
            q->v[2].x = 640.0f;
            q->v[2].y = 480.0f;
            q->v[3].x = 0.0f;
            q->v[3].y = 480.0f;
        } else {
            q->v[0].x = QUAD_CFG->from[0].x;
            q->v[0].y = QUAD_CFG->from[0].y;
            q->v[1].x = QUAD_CFG->from[1].x;
            q->v[1].y = QUAD_CFG->from[1].y;
            q->v[2].x = QUAD_CFG->from[2].x;
            q->v[2].y = QUAD_CFG->from[2].y;
            q->v[3].x = QUAD_CFG->from[3].x;
            q->v[3].y = QUAD_CFG->from[3].y;
            if (w->wait >= (s16)QUAD_CFG->delay && w->step != 0) {
                q->v[0].x += w->step * ((QUAD_CFG->to[0].x - QUAD_CFG->from[0].x) / QUAD_CFG->time);
                q->v[0].y += w->step * ((QUAD_CFG->to[0].y - QUAD_CFG->from[0].y) / QUAD_CFG->time);
                q->v[1].x += w->step * ((QUAD_CFG->to[1].x - QUAD_CFG->from[1].x) / QUAD_CFG->time);
                q->v[1].y += w->step * ((QUAD_CFG->to[1].y - QUAD_CFG->from[1].y) / QUAD_CFG->time);
                q->v[2].x += w->step * ((QUAD_CFG->to[2].x - QUAD_CFG->from[2].x) / QUAD_CFG->time);
                q->v[2].y += w->step * ((QUAD_CFG->to[2].y - QUAD_CFG->from[2].y) / QUAD_CFG->time);
                q->v[3].x += w->step * ((QUAD_CFG->to[3].x - QUAD_CFG->from[3].x) / QUAD_CFG->time);
                q->v[3].y += w->step * ((QUAD_CFG->to[3].y - QUAD_CFG->from[3].y) / QUAD_CFG->time);
            }
        }
        if (QUAD_CFG->x2c == 2) {
            q->v[1].x = q->v[2].x;
            q->v[1].y = q->v[0].y;
            q->v[3].x = q->v[0].x;
            q->v[3].y = q->v[2].y;
        }
        q->v[0].x = 1.1f * (q->v[0].x - 320.0f) + 320.0f;
        q->v[1].x = 1.1f * (q->v[1].x - 320.0f) + 320.0f;
        q->v[2].x = 1.1f * (q->v[2].x - 320.0f) + 320.0f;
        q->v[3].x = 1.1f * (q->v[3].x - 320.0f) + 320.0f;
        if (QUAD_CFG->tint == 1) {
            q->v[0].r = QUAD_CFG->from[0].r;
            q->v[0].g = QUAD_CFG->from[0].g;
            q->v[0].b = QUAD_CFG->from[0].b;
            q->v[1].r = QUAD_CFG->from[1].r;
            q->v[1].g = QUAD_CFG->from[1].g;
            q->v[1].b = QUAD_CFG->from[1].b;
            q->v[2].r = QUAD_CFG->from[2].r;
            q->v[2].g = QUAD_CFG->from[2].g;
            q->v[2].b = QUAD_CFG->from[2].b;
            q->v[3].r = QUAD_CFG->from[3].r;
            q->v[3].g = QUAD_CFG->from[3].g;
            q->v[3].b = QUAD_CFG->from[3].b;
            if (w->wait >= (s16)QUAD_CFG->delay && w->step != 0) {
                q->v[0].r += w->step * ((f32)((u8)QUAD_CFG->to[0].r - (u8)QUAD_CFG->from[0].r) / QUAD_CFG->time);
                q->v[0].g += w->step * ((f32)((u8)QUAD_CFG->to[0].g - (u8)QUAD_CFG->from[0].g) / QUAD_CFG->time);
                q->v[0].b += w->step * ((f32)((u8)QUAD_CFG->to[0].b - (u8)QUAD_CFG->from[0].b) / QUAD_CFG->time);
                q->v[1].r += w->step * ((f32)((u8)QUAD_CFG->to[1].r - (u8)QUAD_CFG->from[1].r) / QUAD_CFG->time);
                q->v[1].g += w->step * ((f32)((u8)QUAD_CFG->to[1].g - (u8)QUAD_CFG->from[1].g) / QUAD_CFG->time);
                q->v[1].b += w->step * ((f32)((u8)QUAD_CFG->to[1].b - (u8)QUAD_CFG->from[1].b) / QUAD_CFG->time);
                q->v[2].r += w->step * ((f32)((u8)QUAD_CFG->to[2].r - (u8)QUAD_CFG->from[2].r) / QUAD_CFG->time);
                q->v[2].g += w->step * ((f32)((u8)QUAD_CFG->to[2].g - (u8)QUAD_CFG->from[2].g) / QUAD_CFG->time);
                q->v[2].b += w->step * ((f32)((u8)QUAD_CFG->to[2].b - (u8)QUAD_CFG->from[2].b) / QUAD_CFG->time);
                q->v[3].r += w->step * ((f32)((u8)QUAD_CFG->to[3].r - (u8)QUAD_CFG->from[3].r) / QUAD_CFG->time);
                q->v[3].g += w->step * ((f32)((u8)QUAD_CFG->to[3].g - (u8)QUAD_CFG->from[3].g) / QUAD_CFG->time);
                q->v[3].b += w->step * ((f32)((u8)QUAD_CFG->to[3].b - (u8)QUAD_CFG->from[3].b) / QUAD_CFG->time);
            }
        } else {
            q->v[0].r = q->v[0].g = q->v[0].b = 0xff;
            q->v[1].r = q->v[1].g = q->v[1].b = 0xff;
            q->v[2].r = q->v[2].g = q->v[2].b = 0xff;
            q->v[3].r = q->v[3].g = q->v[3].b = 0xff;
        }
        a = 255.0f * (1.0f + w->fade);
        q->v[0].a = q->v[1].a = q->v[2].a = q->v[3].a = a;
        for (i = 0; i < 4; i++) {
            if (QUAD_CFG->x30 == 3) {
                q->v[i].r = q->v[i].r * (1.0f + w->fade);
                q->v[i].g = q->v[i].g * (1.0f + w->fade);
                q->v[i].b = q->v[i].b * (1.0f + w->fade);
            }
        }
        if (QUAD_CFG->x24 == 1) {
            q->tex = w->x100;
        } else {
            q->tex = NULL;
        }
        q->id = fn_800A10C4((Pair*)fn_800A1ABC((ObjB_800A1ABC*)w, 0x41), w->x218, QUAD_COUNT());
        q->u = w->u;
        q->w = (((s32)QUAD_CFG->count > 4 ? QUAD_CFG->flags : 0) & 4) ? -2 : w->v;
        q->alpha = QUAD_CFG->alpha;
        if (q->alpha > 100) {
            q->alpha = 100;
        }
        q->alpha = 255.0f * (q->alpha / 100.0f);
        b = q->alpha;
        DrawStateDefault2D(&ds);
        fn_8009E910((s32*)&ds, QUAD_CFG->x30, &b);
        q->alpha = b;
        ((s32*)&ds)[9] = w->x2c;
        z = -1.5f + -0.03125f * QUAD_CFG->z;
        if (z < -2.0f) {
            z = -2.0f;
        }
        tri = QUAD_CFG->x2c == 1;
        if ((w->x1d8 != NULL ? w->x1d8->x1a0 : 1) == 0) {
            DrawStatePush(&ds);
            fn_80296E4C(0);
            if (QUAD_CFG->x18 & 0x80000) {
                w->x176 = QUAD_CFG->x18;
                fn_800A1BA4((Obj_800A1BA4*)q, tri, z, w->x176, 1);
            } else if (QuadMapInRange()) {
                u16 save = w->x176;
                w->x176 = save | 0x5000;
                fn_800A1BA4((Obj_800A1BA4*)q, tri, z, w->x176, 1);
                w->x176 = save;
            } else {
                fn_800A1BA4((Obj_800A1BA4*)q, tri, z, w->x176, 0);
            }
            DrawStatePop(NULL);
        }
        fn_8015E600((Work_800AE000*)w);
        du = QUAD_CFG->du;
        dv = QUAD_CFG->dv;
        if (w->wait >= (s16)QUAD_CFG->delay && w->step != 0) {
            du = (f32)w->step * ((f32)((s16)QUAD_CFG->du2 - du) / QUAD_CFG->time) + du;
            dv = (f32)w->step * ((f32)((s16)QUAD_CFG->dv2 - dv) / QUAD_CFG->time) + dv;
        }
        w->u += du;
        w->v += dv;
        if (w->u < -0x100) {
            w->u += 0x200;
        }
        if (w->u > 0xff) {
            w->u -= 0x200;
        }
        if (w->v < -0x100) {
            w->v += 0x200;
        }
        if (w->v > 0xff) {
            w->v -= 0x200;
        }
        if (w->timer >= QUAD_CFG->length && QUAD_CFG->length != 0) {
            w->timer = 0;
            w->x1fa = 1;
            o->state = 1;
        } else if ((w->timer < QUAD_CFG->fadein && QUAD_CFG->length == 0) || QUAD_CFG->length != 0) {
            w->timer++;
        }
        if (w->wait < QUAD_CFG->delay) {
            w->wait++;
        } else if (w->step < QUAD_CFG->time) {
            w->step++;
        }
        break;
    case 3:
    case 0xff:
        q = w->quad;
        fn_8015EBF4((Work_800AE000*)w);
        if (w->x100 != NULL && w->x100->hdr->x8 != 0) {
            fn_802275A4(w->x100, 0);
        }
        if (q != NULL) {
            fn_801E1784(q);
        }
        w->x264 = NULL;
        w->x260 = NULL;
        w->quad = NULL;
        fn_80100B74((Task8009C3D0*)o);
        break;
    case 4:
        if (QUAD_CFG->count >= 0x42) {
            o->state = 0;
        }
        break;
    case 0xfe:
        /* nothing: an empty case here gives the original's switch tree (pivot 4, the extra bge) */
        break;
    }
}
