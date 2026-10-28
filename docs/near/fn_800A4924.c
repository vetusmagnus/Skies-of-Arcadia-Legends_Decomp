/* fn_800A4924 (6.2 KB, a ribbon effect task): a near miss.
 *
 *   python tools/match/fdiff.py docs/near/fn_800A4924.c fn_800A4924
 * Instruction count (1566) and structure are exact apart from one scheduling line: before the
 * fn_800A0ADC call the original loads the 0.0f argument ahead of `st->age`. The registers are
 * the open part (fdiff prints 1066 lines): the original colours the work pointer, the parent's
 * work, the finished-strand count, the colour-table count and item first (r31-r27) and the task
 * pointer sixth (r26); this build colours the task pointer, the map-table base, the draw and
 * point buffers and the strand index first, then the rest in declaration order. The task's
 * `o->state = 2` inside the strand loop is what moves it to the front here: without that store
 * it comes last, as the parameter does in small tests. Declaration order alone (a 250-step
 * random search) got down to 976 lines without changing that grouping.
 *
 * The effect: each of the work's `nstrand` strands (RibStrand) throws a run of `npt` points
 * (RibPt) out from the parent's position, lets them fall and bounce off the floor height found
 * with fn_8015FAD4, and every frame copies them, offset by the emitter and faded towards the
 * tail, into the draw buffer that fn_800A432C draws from. States: 0 sets up the strands, 1
 * moves and draws them, 2 releases the parent's slot, 0xff frees the buffers.
 *
 * What the original shows:
 * - The fill loop is unrolled by 8, which MWCC only does when the body is small enough:
 *   advancing `dst++`/`src++` inside the body keeps it under the limit, indexing `dst[j]` or
 *   advancing the pointers in the `for` header does not (2x unroll).
 * - The point-count loop sets `k = len` on a zero point instead of breaking (no increment).
 * - `st->life + w->npt - 1`, unparenthesised: with `(w->npt - 1)` MWCC reassociates it.
 * - The bounce reuses the loaded `p->pos.y` and `w->pos.y` (locals `py`/`by`), and `h` is
 *   computed before the map-range check.
 * - fn_800A10A8 takes the count as a third, `s32`, parameter (unit_800B2DA0 declares it that
 *   way too); with `u32` the conversion gets hoisted into its own register.
 */
#include "../src/game/unit_800972AC.c" /* found through -i include */

typedef struct RibPt {
    NJS_POINT3 pos; /* 0x00 */
    Ang3 rot;       /* 0x0C */
    NJS_POINT3 scl; /* 0x18 */
    s32 x24;        /* 0x24 */
    s32 x28;        /* 0x28 */
    u8 alpha;       /* 0x2C */
    u8 pad2d[3];
    f32 x30;        /* 0x30 */
} RibPt;

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

typedef struct RibLink {
    u8 pad0[0x10];
    RibCfg* cfg; /* 0x10 */
} RibLink;

typedef struct RibSub {
    u8 pad0[0x1A0];
    s32 x1a0;
} RibSub;

typedef struct RibWork {
    u8 pad0[0x18];
    u32 flags;          /* 0x018 */
    f32 x1c;            /* 0x01C */
    f32 x20;            /* 0x020 */
    f32 x24;            /* 0x024 */
    f32 x28;            /* 0x028 */
    s32 x2c;            /* 0x02C */
    u8 pad30[0x20];
    NJS_POINT3 x50;     /* 0x050 */
    u8 pad5c[0xE4 - 0x5C];
    void* xe4;          /* 0x0E4 */
    u8 pade8[0x100 - 0xE8];
    s32 x100;           /* 0x100 */
    u8 pad104[0x176 - 0x104];
    s16 x176;           /* 0x176 */
    u8 pad178[0x18C - 0x178];
    f32 x18c;           /* 0x18C */
    u8 pad190[0x1C8 - 0x190];
    RibLink* link;      /* 0x1C8 */
    u8 pad1cc[0x1D8 - 0x1CC];
    RibSub* x1d8;       /* 0x1D8 */
    u8 pad1dc[0x1EC - 0x1DC];
    s8 x1ec;            /* 0x1EC */
    u8 pad1ed[0x206 - 0x1ED];
    s16 nstrand;        /* 0x206 */
    u8 pad208[4];
    Ang3 rot;           /* 0x20C */
    u32 x218;           /* 0x218 */
    u8 x21c;            /* 0x21C */
    u8 pad21d;
    u8 x21e;            /* 0x21E */
    u8 x21f;            /* 0x21F */
    u8 x220;            /* 0x220 */
    u8 x221;            /* 0x221 */
    u8 x222;            /* 0x222 */
    u8 pad223[0x232 - 0x223];
    u16 x232;           /* 0x232 */
    u16 npt;            /* 0x234 */
    u8 pad236[2];
    u16 x238;           /* 0x238 */
    u8 pad23a[0x24C - 0x23A];
    NJS_POINT3 pos;     /* 0x24C */
    f32 x258;           /* 0x258 */
    DrawState* x25c;    /* 0x25C */
    RibStrand* strand;  /* 0x260 */
    RibPt* pt;          /* 0x264 */
    RibPt* draw;        /* 0x268 */
} RibWork;

typedef struct RibTask {
    u8 pad0[8];
    struct RibTask* parent; /* 0x08 */
    u8 padc[0xC];
    u8 flags;               /* 0x18 */
    u8 state;               /* 0x19 */
    u8 pad1a;
    u8 x1b;                 /* 0x1B */
    u8 pad1c[4];
    f32 x20;                /* 0x20 */
    RibWork* work;          /* 0x24 */
} RibTask;

extern NJS_POINT3 lbl_802B10D8;
extern NJS_POINT3 lbl_802B10E4;
extern s8 fn_8015FAD4(NJS_POINT3* p);
extern void* fn_8008F8FC(RibWork* w, s32 i);
extern void fn_8015FE60(s32 i, RibWork* w, f32 f);
extern void fn_8015FB98(s32 i, RibWork* w);
extern void fn_800A432C(RibWork* w, RibWork* pw, RibPt* p);

#define RIB_RND (3.0517578125e-05f * rand())

static inline s32 RibNoModel(RibWork* w)
{
    s32 r = 0;
    u32 p = w->link->cfg->x48;
    if (p == 0 || (p != 0 && w->xe4 == NULL)) {
        r = 1;
    }
    return r;
}

static inline BOOL RibMapInRange(void)
{
    extern s32 lbl_80311AC0[5];
    s32 in = 0;
    if (lbl_80311AC0[1] >= 500 && lbl_80311AC0[1] < 600) {
        in = 1;
    }
    return in ? TRUE : FALSE;
}

/* Copies a strand's n points into the draw buffer, offset by the emitter, fading to the tail. */
static inline void RibFill(RibWork* w, RibPt* dst, RibPt* src, s32 n)
{
    f32 step = (s32)(w->x21c / n);
    s32 j;
    for (j = 0; j < n; j++) {
        dst->pos.x = src->pos.x + w->pos.x;
        dst->pos.y = src->pos.y + w->pos.y;
        dst->pos.z = src->pos.z + w->pos.z;
        dst->alpha = step * (n - j);
        dst++;
        src++;
    }
}

void fn_800A4924(RibTask* o)
{
    NJS_POINT3 up = lbl_802B10D8;
    NJS_POINT3 off = lbl_802B10E4;
    NJS_MATRIX m;
    DrawState ds;
    u8 b;
    RibWork* w = o->work;
    RibCfg* cfg = w->link->cfg;
    RibStrand* s = w->strand;
    RibStrand* st;
    RibWork* pw;
    s32 done = 0;
    s32 cnt;
    void* item;
    RibPt* pt;
    RibPt* draw;
    RibPt* p;
    s32 i;
    s32 j;
    s32 k;
    s32 n;
    s32 base;
    s32 a1;
    s32 a2;
    f32 g;
    f32 h;
    f32 spread;
    f32 py;
    f32 by;
    f32 floor;

    if (o->parent->flags & 0x40) {
        o->state = 0xff;
    } else {
        pw = o->parent->work;
        cnt = fn_800A1AE8((u8*)pw, 0x31);
        w->x218 = cnt;
        item = fn_800A1ABC((ObjB_800A1ABC*)pw, 0x31);
        w->x222 = RibNoModel(pw);
    }
    if (o->flags & 0x20) {
        o->state = 0xff;
    }
    switch (o->state) {
    case 0:
        o->x1b = 0xfb;
        if (cfg->x68 == 0.0f) {
            o->state = 2;
            break;
        }
        if (cfg->x70 != 0 && pw->link->cfg->count >= 0xb1) {
            w->x221 = 1;
        } else {
            w->x221 = 0;
        }
        w->x100 = pw->x100;
        g = cfg->x58;
        if (fn_8008F8FC(w, 0) != NULL) {
            fn_8015FE60(0, w, g);
        }
        if (fn_8008F8FC(w, 1) != NULL) {
            fn_8015FB98(1, w);
        }
        w->flags |= 0x1000;
        if (cfg->x50 == 1) {
            w->x176 = 0;
        } else {
            w->x176 = 3;
        }
        w->pos = pw->pos;
        w->rot = pw->rot;
        draw = fn_801E1A2C(1, w->npt * sizeof(RibPt));
        pt = fn_801E1A2C(1, w->nstrand * w->npt * sizeof(RibPt));
        w->draw = draw;
        w->pt = pt;
        w->x21c = 0xff;
        if (!RibMapInRange()) {
            off = w->pos;
            w->x1ec = fn_8015FAD4(&off);
            floor = off.y;
        }
        n = cfg->x84 > 100 ? 100 : cfg->x84;
        spread = 1.8f * (u32)(100 - n);
        for (i = 0; i < w->nstrand; s++, i++) {
            s->done = 0;
            s->len = w->npt;
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
            njRotateXYZ(m, w->rot.x, w->rot.y, w->rot.z);
            njRotateXYZ(m, a1, 0, a2);
            njCalcPoint(m, &up, &s->vel);
            if (cfg->x90 != 0) {
                s->vel.x *= cfg->x94.x;
                s->vel.y *= cfg->x94.y;
                s->vel.z *= cfg->x94.z;
            }
            s->fall = 0.0f;
            for (j = 0; j < w->npt; pt++, j++) {
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
                    pt->x30 = w->x18c;
                    pt->scl.x = pw->x50.x * (1.0f + g);
                    pt->scl.y = pw->x50.y * (1.0f + g);
                    pt->scl.z = pw->x50.z * (1.0f + g);
                    if (pt->scl.x < 0.0f) {
                        pt->scl.x = 0.0f;
                    }
                    if (pt->scl.y < 0.0f) {
                        pt->scl.y = 0.0f;
                    }
                    if (pt->scl.z < 0.0f) {
                        pt->scl.z = 0.0f;
                    }
                    pt->x24 = (s32)fn_800A10A8(item, 0, cnt) + 1;
                    pt->x28 = 0;
                }
                if (RibNoModel(w)) {
                    g = pow(pt->scl.y, 2.0);
                    s->x1c = fn_80291A5C((f32)pow(pt->scl.x, 2.0) + g);
                    s->floor = 0.5f * s->x1c + floor;
                } else {
                    s->x1c = fn_8009E3D0((u8*)7, fn_801C8930(w->xe4), &pt->scl.x);
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
        pw->x232++;
        o->state = 1;
        o->x20 = ((s32)w->link->cfg->count > 3 ? w->link->cfg->x10 : 0) == 0 ? -100.0f : -300.0f;
        break;
    case 1:
        draw = w->draw;
        pt = w->pt;
        st = w->strand;
        if (cfg->x44 <= -1) {
            w->pos = pw->pos;
            w->rot = pw->rot;
        }
        if (RibNoModel(w)) {
            DrawStateDefault2D(&ds);
            ((s32*)&ds)[9] = w->x2c;
            fn_8009E910((s32*)&ds, cfg->x4c, &b);
            w->x25c = &ds;
            DrawStatePush(&ds);
        }
        for (i = 0; i < w->nstrand; st++, i++) {
            base = i * w->npt;
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
                            if (0.0f == q->pos.x && 0.0f == q->pos.y && 0.0f == q->pos.z) {
                                k = st->len;
                            } else {
                                k++;
                            }
                        }
                        RibFill(w, draw, p, n);
                    }
                } else {
                    f32 t;
                    st->age++;
                    for (k = st->len - 1; k >= 1; k--) {
                        pt[base + k] = pt[base + k - 1];
                    }
                    t = fn_800A0ADC(st->age, st->life + w->npt - 1, 0x20101, 0.0f);
                    off.x = st->vel.x * t;
                    off.y = st->vel.y * t;
                    off.z = st->vel.z * t;
                    off.y = st->fall * t + off.y;
                    py = p->pos.y;
                    by = w->pos.y;
                    h = by + (off.y + py);
                    if (!RibMapInRange() && w->x1ec != -1 && h < st->floor && cfg->x8c == 0) {
                        f32 r = (by + py - st->floor) / fabs(off.y);
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
                        if (0.0f == pt[base + k].pos.x && 0.0f == pt[base + k].pos.y && 0.0f == pt[base + k].pos.z) {
                            k = st->len;
                        } else {
                            k++;
                        }
                    }
                    RibFill(w, draw, p, n);
                }
                if (st->done == 0) {
                    RibPt* q;
                    if (cnt != 0) {
                        if (p->x24 == 0 && p->x28 < cnt) {
                            p->x28++;
                            if (p->x28 == cnt && cfg->x60 != 0) {
                                p->x28 = 0;
                            }
                            if (p->x28 < cnt) {
                                p->x24 = (s32)fn_800A10A8(item, p->x28, cnt) - 1;
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
                        q->x30 = p->x30;
                        q->rot = p->rot;
                        q->scl = p->scl;
                        if ((pw->x1d8 != NULL ? pw->x1d8->x1a0 : 1) == 0) {
                            w->x258 = st->x1c;
                            w->x1c = fn_8009E4F8(st->alpha);
                            fn_800A432C(w, pw, q);
                        }
                    }
                }
                {
                    s32 last = st->life + w->npt - 1;
                    if (st->age + st->fade >= last) {
                        st->alpha = 255.0f / (st->fade + 1) * (last - st->age);
                    }
                }
            } else {
                done++;
            }
            if (done >= w->nstrand) {
                o->state = 2;
            }
        }
        if (RibNoModel(w)) {
            DrawStatePop(NULL);
        }
        break;
    case 2:
        pw->x232--;
        if (pw->x232 == 0xffff) {
            pw->x232 = 0;
        }
        fn_8009E804(*(ItemList_8009E804**)&pw->pt, w->x238);
    case 0xff:
        draw = w->draw;
        pt = w->pt;
        st = w->strand;
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
        w->draw = NULL;
        w->pt = NULL;
        w->strand = NULL;
        w->x25c = NULL;
        fn_8009E630((u32*)o);
        break;
    case 0xfe:
        /* nothing: an empty case here gives the original's switch tree (its extra bge) */
        break;
    }
}
