#include "types.h"
#include "game/work_8030CEA0.h"
#include "ninja.h"
#include "game/sprite.h"
#include "game/util.h"
#include "game/task.h"
#include "game/pad.h"
#include "game/drawstate.h"
#include <math.h>
#include "game/evobj.h"
#include "game/unit_800B2DA0.h"
extern s32 lbl_80346D8C;
extern s8 lbl_80310A1C[0x120];
extern void fn_801E1784(void *p);
extern EvObj* lbl_80347450;
extern void fn_801E17E0(void*);
extern s32 fn_8009761C(s32 a, s32 b);
extern void fn_801E66E0();
extern f32 njCos(Angle a);
extern f32 njSin(Angle a);
extern void fn_801DD9AC(void *a, void *b);
extern void fn_801DD95C(void *p);
extern void fn_80100B74(void *self);
extern s32 lbl_803474EC;
extern void fn_801DCEB0(void *a, void *b, f32 c);
extern MapInfo2 lbl_80311AC0;
typedef struct {
    u8 pad0[0x8];
    void *a8;
    u8 padc[0x14];
    void *f20;
    void *f24;
    u8 pad28[4];
} Elem;
typedef struct {
    u8 pad0[0x18];
    Elem elems[1];
} List_UNIT0000;
typedef struct {
    u8 pad0[0x1ac];
    s32 f1ac;
    s32 f1b0;
    u8 pad1b4[0x218 - 0x1b4];
    s32 count;
    u8 pad21c[0x25c - 0x21c];
    List_UNIT0000 *list;
} Self_800D1268_UNIT0000;
void fn_801DD9AC(void *a, void *b);
f32 fn_80291A5C(f32 x);
extern void fn_801E1784(void* p);
extern s32 fn_802275A4(NJS_TEXLIST* texlist, s32 a);
extern int rand(void);
extern NJS_POINT3 lbl_802E1118;
extern void fn_800CF7BC(NJS_POINT3* a, NJS_POINT3* b, f32 c);
extern s32 fn_80091228(s32 a, s32 b, f32 c);
typedef struct {
    s16 h0;
    s16 h2;
    f32 f4;
    s32 w8;
    void *wc;
    s32 w10;
    s32 w14;
    f32 f18;
    f32 f1c;
    s32 w20;
    s32 w24;
    u8 pad28[4];
} AuxEntry;
typedef struct {
    s16 x0;           /* 0x00 */
    s16 x2;           /* 0x02 entry count */
    u8 pad4[4];
    f32 x8;           /* 0x08 */
    f32 xc, x10, x14; /* 0x0C */
    AuxEntry entries[1]; /* 0x18 */
} Aux;
extern void fn_800D0E78(EvObj* a);
extern s32 lbl_8034753C;
extern void fn_801E6438(EvObj* a);
extern void fn_801E6744(EvObj* a);
void fn_800D0CC8(EvObj* a);
typedef struct {
    u8 pad0[0x54];
    f32 x54, x58, x5c; /* 0x54 */
    u32 x60, x64, x68; /* 0x60 */
    u8 pad6C[0xCC0 - 0x6C];
} Snap;
extern Snap lbl_8030A794;
extern s32 lbl_803473EC;
extern s32 lbl_80347408;
extern void fn_8016B96C(f32 x);
extern void fn_8016C7F0(s32 x);
extern void fn_8016C7D8(s32 x);
extern void fn_8016C780(s32 a, s32 b);
extern s32 fn_8015E600(void* e);
extern void fn_80118368(void* e);
extern void fn_800D1174(EvObj* e);
extern f32 lbl_80346D88;
typedef struct Row {
    f32 f0;
    u32 w4;
    u8 pad8[8];
    u32 w10;
    u8 pad14[0xc];
} Row;
extern Row lbl_802E1154[];
/* a wall segment: two end points */
typedef struct Seg {
    NJS_POINT3 a;
    NJS_POINT3 b;
} Seg;
/* a line: point and direction (fn_8028FEA4) */
typedef struct Line {
    NJS_POINT3 p;
    NJS_POINT3 d;
} Line;
typedef struct Flags {
    Seg seg;        /* 0x00 hit wall segment (written by fn_801150DC/fn_8011510C) */
    u8 pad18[0x24 - 0x18];
    u16 h24;
    u8 pad26[0x28 - 0x26];
    s32 w28;
    s16 h2c;
    s16 h2e;
    u16 h30;
} Flags;
extern f32 lbl_80346D90;
extern s32 fn_800CEDDC(NJS_POINT3* q, EvObj* m, Flags* f);
extern s32 fn_800CE67C(NJS_POINT3* q, EvObj* m, Flags* f);
typedef struct {
    u8 pad0[0x10];
    void* tbl[4];
    u8 pad20[0x20 - 0x20];
} Ent_800CE2B4;
typedef struct {
    u8 pad0[4];
    s32 id;
    s8 ch;
    u8 pad9[0x14 - 9];
} Key_800CE2B4;
extern u8 lbl_8030B7F4[0x16A0];
extern s32 fn_8021A1C4(void* buf);
extern s32 fn_8021ADA0(void* a, void* b);
extern void fn_80100178(void* p);
extern void fn_801F7B04(s32 v);
extern void fn_800EB58C(s32 v);
extern MapTask* lbl_80347454;
extern s32 lbl_803473A8;
extern u32 lbl_80310B3C[0x356];
extern void fn_800D1B5C(void* o);
extern void fn_8016B9B0(s32 a);
extern void fn_8016B998(s32 a);
extern void fn_8016C870(s32 a);
extern void fn_8016C808(s32 a);
extern void fn_8016B950(f32 a, f32 b);
extern void fn_8016C7AC(s32 a, s32 b);
extern void fn_800D1630(MapTask* task);
extern void fn_80217830(void* p);
extern void fn_8015EBF4(void* w);
extern void fn_8016ABEC(void);
extern void fn_80097660(void);
/* Motion callback (registered with fn_8015EB8C id 0xd): copies src+0xC0 into ctx->dst+0xC0.
 * Declared s32 like its sibling callbacks (fn_8010A530) but the original has no return
 * statement: r3 stays live as the result, so the dst pointer lands in r4. */
typedef struct CbObj {
    char pad0[0x24];
    struct CbObj* dst; /* 0x24 */
    char pad28[0xc0 - 0x28];
    int valC0;         /* 0xC0 */
} CbObj;
extern s32 fn_80222B30(EvColl *a, EvColl *b);
extern s32 fn_802254A0(NJS_POINT3* p, void* q);
#define RND (3.0517578125e-05f * rand())
extern u32 lbl_8030A3C8[3];
extern u16 lbl_8034740E;
extern f32 lbl_80347410;
extern s32 fn_802256A0(NJS_POINT3* v, EvHit* s, u32 a, u32 b);
#define FREE_CHAIN(w) do { \
    Node_800B63A4* p = (w)->x25c; \
    if (p != NULL) { \
        while (p != NULL) { \
            Node_800B63A4* q = p; \
            p = p->next; \
            if (q) fn_801E1784(q); \
        } \
        (w)->x25c = NULL; \
    } \
} while (0)
#define FREE_CHAIN_800B88F8(w) do { \
    Node_800B88F8* p = (w)->x25c; \
    if (p != NULL) { \
        while (p != NULL) { \
            Node_800B88F8* q = p; \
            p = p->next; \
            if (q) fn_801E1784(q); \
        } \
        (w)->x25c = NULL; \
    } \
} while (0)
#define ATAN_ANG(y, x) (((x) == 0.0f && (y) == 0.0f) ? 0 : (Angle)(10430.378f * (f32)atan2((y), (x))))
extern struct Task_800BE6EC;
/* The emitter's slots for its particle tasks. */
typedef struct Slots_800BE6EC {
    struct Task_800BE6EC **items; /* 0x00 */
    u32 count;          /* 0x04 */
} Slots_800BE6EC;
/* The effect task work (0x270 bytes, see fn_8009D760), for both the emitter and its
 * particles. */
typedef struct Work_800BE6EC {
    u8 pad0[0x18];
    u32 flags;          /* 0x018 */
    NJS_ARGB col;       /* 0x01C */
    u8 pad2c[0x38 - 0x2C];
    NJS_POINT3 x38;     /* 0x038 */
    Ang3_800C47BC rot;  /* 0x044 */
    NJS_POINT3 scl;     /* 0x050 */
    NJS_POINT3 dscl;    /* 0x05C */
    u8 pad68[0xE8 - 0x68];
    void *xe8;          /* 0x0E8 */
    void *xec;          /* 0x0EC */
    u8 padf0[0x100 - 0xF0];
    NJS_TEXLIST *x100;  /* 0x100 */
    u8 pad104[0x176 - 0x104];
    u16 x176;           /* 0x176 */
    u16 x178;           /* 0x178 */
    u8 pad17a[0x184 - 0x17A];
    s32 x184;           /* 0x184 */
    u8 pad188[0x18C - 0x188];
    f32 x18c;           /* 0x18C */
    f32 x190;           /* 0x190 */
    u8 pad194[0x19C - 0x194];
    s32 x19c;           /* 0x19C */
    u8 pad1a0[0x1C8 - 0x1A0];
    Link_800BE6EC *link; /* 0x1C8 */
    u8 pad1cc[0x1D8 - 0x1CC];
    Sub_800BE6EC *x1d8; /* 0x1D8 */
    u8 pad1dc[0x1EC - 0x1DC];
    u8 x1ec;            /* 0x1EC */
    u8 pad1ed[0x1FA - 0x1ED];
    s8 x1fa;            /* 0x1FA */
    s8 x1fb;            /* 0x1FB */
    s16 x1fc;           /* 0x1FC */
    s16 x1fe;           /* 0x1FE */
    u8 pad200[0x20C - 0x200];
    Ang3_800C47BC x20c; /* 0x20C */
    u8 pad218[0x22C - 0x218];
    u16 x22c;           /* 0x22C */
    u8 pad22e[0x236 - 0x22E];
    u16 x236;           /* 0x236 */
    u16 x238;           /* 0x238 */
    u8 pad23a[0x24C - 0x23A];
    NJS_POINT3 x24c;    /* 0x24C */
    f32 x258;           /* 0x258 */
    Spot_800BE6EC *x25c; /* 0x25C */
    void *x260;         /* 0x260 */
    Slots_800BE6EC *x264; /* 0x264 */
    u8 pad268[0x26C - 0x268];
    u8 x26c;            /* 0x26C */
} Work_800BE6EC;
typedef struct Task_800BE6EC {
    u8 pad0[8];
    struct Task_800BE6EC *parent; /* 0x08 */
    struct Task_800BE6EC *xc;     /* 0x0C */
    u8 pad10[8];
    u8 flags;           /* 0x18 */
    u8 state;           /* 0x19 */
    u8 pad1a;
    u8 x1b;             /* 0x1B */
    f32 x1c;            /* 0x1C */
    f32 x20;            /* 0x20 */
    Work_800BE6EC *work; /* 0x24 */
} Task_800BE6EC;











#define FREE(p) if ((p) != NULL) { fn_801E1784(p); (p) = NULL; }

extern void fn_801E5DF0(EvObj *w);

extern f32 fn_800CE4E8(NJS_POINT3* a, Flags* b);

extern NJS_POINT3 lbl_80305B18;
extern void njUnitVector(NJS_POINT3* v);
extern s32 fn_801150DC(NJS_POINT3* out, NJS_POINT3* a, NJS_POINT3* b, Flags* info);
extern f32 fn_8028FEA4(NJS_POINT3* p, Line* l, NJS_POINT3* out);
extern void fn_801DCE18(NJS_POINT3* out, NJS_POINT3* in, s32 ang);
extern s32 fn_80114A44(s32 id, NJS_POINT3* p, f32 y, Flags* info);

s32 fn_800CE67C(NJS_POINT3* q, EvObj* m, Flags* f) {
    Flags info;
    NJS_POINT3 pos[3];
    Seg segs[2];
    NJS_POINT3 hits[2];
    Seg seg0;
    Line line;
    Line bestLine;
    NJS_POINT3 b;
    NJS_POINT3 a;
    NJS_POINT3 out;
    s32 res[2];
    s32 cur;
    s32 next;
    s32 prev;
    NJS_POINT3* np;
    s32 found;
    s32 ang;
    s32 n;
    f32 best;
    f32 nx;
    f32 nz;
    f32 ox;
    f32 oz;
    f32 d;
    f32 lim;
    f32 len;

    info.seg.a = f->seg.a;
    info.seg.b = f->seg.b;
    info.w28 = f->w28;
    info.h2c = f->h2c;
    info.h2e = f->h2e;
    info.h30 = f->h30;
    found = 0;
    a.x = b.x = q->x;
    a.y = b.y = q->y;
    a.z = q->z - 1.0f;
    b.z = 30.0f + q->z;
    if ((res[0] = fn_801150DC(&hits[0], &a, &b, &info)) != 0) {
        seg0 = info.seg;
        pos[1].x = hits[0].x;
        pos[1].z = hits[0].z;
    }
    cur = res[0];
    b.x = njSin(0x2000);
    a.x = q->x - b.x;
    b.x = q->x + 30.0f * b.x;
    b.z = njCos(0x2000);
    a.z = q->z - b.z;
    b.z = q->z + 30.0f * b.z;
    if ((res[1] = fn_801150DC(&hits[1], &a, &b, &info)) != 0) {
        segs[1] = info.seg;
        pos[2].x = hits[1].x;
        pos[2].z = hits[1].z;
    }
    ang = 0x2000;
    next = res[1];
    np = &pos[2];
    for (n = 8; n > 0; n--) {
        prev = cur;
        if (cur != 0) {
            pos[0].x = pos[1].x;
            pos[0].z = pos[1].z;
        }
        cur = next;
        if (next != 0) {
            pos[1].x = np->x;
            pos[1].z = np->z;
            segs[0] = segs[1];
        }
        if (n >= 2) {
            ang += 0x2000;
            b.x = njSin(ang);
            a.x = q->x - b.x;
            b.x = q->x + 30.0f * b.x;
            b.z = njCos(ang);
            a.z = q->z - b.z;
            b.z = q->z + 30.0f * b.z;
            if ((next = fn_801150DC(np, &a, &b, &info)) != 0) {
                segs[1] = info.seg;
            }
        } else {
            next = res[2 - n];
            if (next != 0) {
                np->x = hits[2 - n].x;
                np->z = hits[2 - n].z;
                segs[1].a = seg0.a;
                segs[1].b = seg0.b;
            }
        }
        if (cur != 0) {
            if (next != 0) {
                line.p.x = pos[1].x;
                line.p.z = pos[1].z;
                line.p.y = q->y;
                line.d.x = np->x - pos[1].x;
                line.d.y = 0.0f;
                line.d.z = np->z - pos[1].z;
                d = line.d.x * line.d.x + line.d.z * line.d.z;
                if (0.010000001f > d) {
                    line.p.x = segs[0].a.x;
                    line.p.z = segs[0].a.z;
                    line.p.y = q->y;
                    line.d.x = segs[0].b.x - segs[0].a.x;
                    line.d.y = 0.0f;
                    line.d.z = segs[0].b.z - segs[0].a.z;
                }
                d = fn_8028FEA4(q, &line, &out);
                if (found == 0) {
                    best = d;
                    found = 1;
                    bestLine = line;
                    nx = out.x;
                    nz = out.z;
                } else if (best > d) {
                    best = d;
                    bestLine = line;
                    nx = out.x;
                    nz = out.z;
                }
            } else if (prev == 0) {
                line.p.x = segs[0].a.x;
                line.p.z = segs[0].a.z;
                line.p.y = q->y;
                line.d.x = segs[0].b.x - segs[0].a.x;
                line.d.y = 0.0f;
                line.d.z = segs[0].b.z - segs[0].a.z;
                d = fn_8028FEA4(q, &line, &out);
                if (found == 0) {
                    best = d;
                    found = 1;
                    bestLine = line;
                    nx = out.x;
                    nz = out.z;
                } else if (best > d) {
                    best = d;
                    bestLine = line;
                    nx = out.x;
                    nz = out.z;
                }
            }
        }
    }
    if (found != 0) {
        if (0.0f < best) {
            nx = (nx - q->x) / best;
            nz = (nz - q->z) / best;
        } else {
            njUnitVector(&bestLine.d);
            fn_801DCE18(&a, &bestLine.d, 0x4000);
            nx = a.x;
            nz = a.z;
        }
        a.x = q->x + (ox = 20.0f * nx);
        oz = 20.0f * nz;
        a.z = q->z + oz;
        res[0] = fn_802254A0(&a, &info);
        if (fn_80114A44(res[0], &a, q->y, &info) == 0) {
            a.x = q->x - ox;
            a.y = q->y;
            a.z = q->z - oz;
            res[0] = fn_802254A0(&a, &info);
            if (fn_80114A44(res[0], &a, q->y, &info) != 0) {
                nx = -nx;
                nz = -nz;
            } else {
                nx = 0.0f;
                nz = nx;
            }
        }
        m->vel.x += 0.2f * nx;
        m->vel.z += 0.2f * nz;
        lim = fn_800CE4E8(q, f);
        if (0.0f < lim) {
            len = fn_80291A5C(m->vel.x * m->vel.x + m->vel.z * m->vel.z);
            if (lim < len) {
                m->vel.x = m->vel.x * lim / len;
                m->vel.z = m->vel.z * lim / len;
            }
        }
        lbl_80305B18.x = nx;
        lbl_80346D90 = best;
        lbl_80305B18.z = nz;
    }
    return found;
}
extern s32 fn_8011510C(NJS_POINT3* out, NJS_POINT3* a, NJS_POINT3* b, Flags* info);

s32 fn_800CEDDC(NJS_POINT3* q, EvObj* m, Flags* f) {
    Flags info;
    NJS_POINT3 pos[3];
    Seg segs[2];
    NJS_POINT3 hits[2];
    Seg seg0;
    Line line;
    Line bestLine;
    NJS_POINT3 b;
    NJS_POINT3 a;
    NJS_POINT3 out;
    s32 res[2];
    s32 cur;
    s32 next;
    s32 prev;
    NJS_POINT3* np;
    s32 found;
    s32 ang;
    s32 n;
    f32 best;
    f32 nx;
    f32 nz;
    f32 ox;
    f32 oz;
    f32 d;
    f32 lim;
    f32 len;

    info.seg.a = f->seg.a;
    info.seg.b = f->seg.b;
    info.w28 = f->w28;
    info.h2c = f->h2c;
    info.h2e = f->h2e;
    info.h30 = f->h30;
    found = 0;
    a.x = b.x = q->x;
    a.y = b.y = q->y;
    a.z = q->z - 1.0f;
    b.z = 30.0f + q->z;
    if ((res[0] = fn_8011510C(&hits[0], &a, &b, &info)) != 0) {
        seg0 = info.seg;
        pos[1].x = hits[0].x;
        pos[1].z = hits[0].z;
    }
    cur = res[0];
    b.x = njSin(0x2000);
    a.x = q->x - b.x;
    b.x = q->x + 30.0f * b.x;
    b.z = njCos(0x2000);
    a.z = q->z - b.z;
    b.z = q->z + 30.0f * b.z;
    if ((res[1] = fn_8011510C(&hits[1], &a, &b, &info)) != 0) {
        segs[1] = info.seg;
        pos[2].x = hits[1].x;
        pos[2].z = hits[1].z;
    }
    ang = 0x2000;
    next = res[1];
    np = &pos[2];
    for (n = 8; n > 0; n--) {
        prev = cur;
        if (cur != 0) {
            pos[0].x = pos[1].x;
            pos[0].z = pos[1].z;
        }
        cur = next;
        if (next != 0) {
            pos[1].x = np->x;
            pos[1].z = np->z;
            segs[0] = segs[1];
        }
        if (n >= 2) {
            ang += 0x2000;
            b.x = njSin(ang);
            a.x = q->x - b.x;
            b.x = q->x + 30.0f * b.x;
            b.z = njCos(ang);
            a.z = q->z - b.z;
            b.z = q->z + 30.0f * b.z;
            if ((next = fn_8011510C(np, &a, &b, &info)) != 0) {
                segs[1] = info.seg;
            }
        } else {
            next = res[2 - n];
            if (next != 0) {
                np->x = hits[2 - n].x;
                np->z = hits[2 - n].z;
                segs[1].a = seg0.a;
                segs[1].b = seg0.b;
            }
        }
        if (cur != 0) {
            if (next != 0) {
                line.p.x = pos[1].x;
                line.p.z = pos[1].z;
                line.p.y = q->y;
                line.d.x = np->x - pos[1].x;
                line.d.y = 0.0f;
                line.d.z = np->z - pos[1].z;
                d = line.d.x * line.d.x + line.d.z * line.d.z;
                if (0.010000001f > d) {
                    line.p.x = segs[0].a.x;
                    line.p.z = segs[0].a.z;
                    line.p.y = q->y;
                    line.d.x = segs[0].b.x - segs[0].a.x;
                    line.d.y = 0.0f;
                    line.d.z = segs[0].b.z - segs[0].a.z;
                }
                d = fn_8028FEA4(q, &line, &out);
                if (20.0f > d) {
                    if (found == 0) {
                        best = d;
                        found = 1;
                        bestLine = line;
                        nx = out.x;
                        nz = out.z;
                    } else if (best > d) {
                        best = d;
                        bestLine = line;
                        nx = out.x;
                        nz = out.z;
                    }
                }
            } else if (prev == 0) {
                line.p.x = segs[0].a.x;
                line.p.z = segs[0].a.z;
                line.p.y = q->y;
                line.d.x = segs[0].b.x - segs[0].a.x;
                line.d.y = 0.0f;
                line.d.z = segs[0].b.z - segs[0].a.z;
                d = fn_8028FEA4(q, &line, &out);
                if (20.0f > d) {
                    if (found == 0) {
                        best = d;
                        found = 1;
                        bestLine = line;
                        nx = out.x;
                        nz = out.z;
                    } else if (best > d) {
                        best = d;
                        bestLine = line;
                        nx = out.x;
                        nz = out.z;
                    }
                }
            }
        }
    }
    if (found != 0) {
        if (0.0f < best) {
            nx = (q->x - nx) / best;
            nz = (q->z - nz) / best;
        } else {
            njUnitVector(&bestLine.d);
            fn_801DCE18(&a, &bestLine.d, 0x4000);
            nx = a.x;
            nz = a.z;
        }
        a.x = q->x + (ox = 20.0f * nx);
        oz = 20.0f * nz;
        a.z = q->z + oz;
        res[0] = fn_802254A0(&a, &info);
        if (fn_80114A44(res[0], &a, q->y, &info) == 0) {
            a.x = q->x - ox;
            a.y = q->y;
            a.z = q->z - oz;
            res[0] = fn_802254A0(&a, &info);
            if (fn_80114A44(res[0], &a, q->y, &info) != 0) {
                nx = -nx;
                nz = -nz;
            } else {
                nx = 0.0f;
                nz = nx;
            }
        }
        m->vel.x += 0.2f * nx;
        m->vel.z += 0.2f * nz;
        lim = fn_800CE4E8(q, f);
        if (0.0f < lim) {
            len = fn_80291A5C(m->vel.x * m->vel.x + m->vel.z * m->vel.z);
            if (lim < len) {
                m->vel.x = m->vel.x * lim / len;
                m->vel.z = m->vel.z * lim / len;
            }
        }
        lbl_80305B18.x = nx;
        lbl_80346D90 = best;
        lbl_80305B18.z = nz;
    }
    return found;
}

void fn_800CF8C4(void* p, f32 max) {
    lbl_80346D8C = 1;
    fn_800CF7BC(&lbl_802E1118, p, max);
}

void fn_800CF8F8(f32 *pos, s32 *val) {
    if (lbl_80347450 == NULL) {
        return;
    }
    if (pos != NULL) {
        lbl_80347450->pos.x = pos[0];
        lbl_80347450->pos.y = pos[1];
        lbl_80347450->pos.z = pos[2];
    }
    if (val != NULL) {
        lbl_80347450->ang[1] = *val;
    }
}

void fn_800D1268(Self_800D1268_UNIT0000 *self) {
    s32 n;
    List_UNIT0000 *list;
    Elem *el;

    n = self->count;
    if (n > 0) {
        list = self->list;
        if (list != 0) {
            el = list->elems;
            do {
                if (el->f20 != 0) {
                    fn_801DD9AC(&lbl_803474EC, el->f20);
                }
                if (el->f24 != 0) {
                    fn_801DD95C(el->f24);
                }
                if (el->a8 != 0) {
                    fn_802275A4(el->a8, 0);
                }
                n--;
                el++;
            } while (n > 0);
            fn_801E17E0(list);
            self->list = 0;
        }
    }
    self->f1ac = 0;
    self->f1b0 = 0;
}

void fn_800CF7BC(NJS_POINT3* v, NJS_POINT3* d, f32 max) {
    f32 nx, ny, nz;
    f32 cur2, new2, max2;

    ny = v->y + d->y;
    nx = v->x + d->x;
    nz = v->z + d->z;
    cur2 = v->x * v->x + v->y * v->y + v->z * v->z;
    new2 = nx * nx + ny * ny + nz * nz;
    if (cur2 > new2) {
        v->x = nx;
        v->y = ny;
        v->z = nz;
    } else {
        max2 = max * max;
        if (9.999999e-09f < max2) {
            if (new2 < max2) {
                v->x = nx;
                v->y = ny;
                v->z = nz;
            } else {
                f32 k = max / fn_80291A5C(new2);
                v->x = nx * k;
                v->y = ny * k;
                v->z = nz * k;
            }
        }
    }
}

f32 fn_800CFAB8(NJS_POINT3* out, EvObj* a, Aux* b, f32 p) {
    f32 v;
    f32 t;

    a->ang[0] = fn_80091228(0, a->ang[0], 4.0f);
    a->rotv[1] = fn_80091228(0, a->rotv[1], 4.0f);
    b->xc = 0.0f;
    if (0.0f > p) {
        t = p / 128.0f;
        v = 0.1f * t + a->x164;
        if (v < 0.5f * -b->x8) {
            v = 0.5f * -b->x8;
        }
        fn_801DCEB0(out, a->ang, -v);
    } else {
        if (0.0f < p) {
            t = p / 128.0f;
        } else {
            t = 0.15625f + (f32)fabs(b->x10);
        }
        v = 0.5f * t + a->x164;
        if (0.0f <= v) {
            out->z = 0.0f;
            out->y = 0.0f;
            out->x = 0.0f;
            v = 0.0f;
        } else {
            fn_801DCEB0(out, a->ang, -v);
        }
    }
    a->x164 = v;
    return v;
}

s32 fn_800D1028(EvObj* e) {
    s32 save;
    u32 ang;
    Aux* a = e->x25c;
    f32 k;

    a->x0 = 0;
    a->xc = a->x10 = a->x14 = 0.0f;
    e->rotv[1] = fn_80091228(0, e->rotv[1], 4.0f);
    e->home.x = e->pos.x;
    e->home.y = e->pos.y;
    e->home.z = e->pos.z;
    e->vel.y = e->x164 = 0.0f;
    save = e->ang[1];
    e->ang[1] = save + e->rotv[1];
    e->pivot = 1;
    fn_800D0E78(e);
    ang = e->pivotAng[0];
    e->pivotAng[0] = 0;
    k = (f32)fabs(e->x164);
    k /= a->x8;
    k = 1.0f - k;
    k *= 0.3f;
    e->pivotPos.y = k * njSin(ang);
    if (0.0f < e->x164) {
        if ((ang & 0x7FFFF) != 0) {
            ang = (ang + 0x100) & 0xFFFF;
        }
    } else {
        ang = (ang + 0x100) & 0xFFFF;
    }
    fn_800D0CC8(e);
    e->pivot = 0;
    e->pivotAng[0] = ang;
    e->ang[1] = save;
    return 1;
}

void fn_800D1174(EvObj* e) {
    s32 save = e->ang[1];
    u32 ang;
    Aux* a = e->x25c;
    f32 k;

    e->ang[1] = save + e->rotv[1];
    e->pivot = 1;
    fn_800D0E78(e);
    ang = e->pivotAng[0];
    e->pivotAng[0] = 0;
    k = (f32)fabs(e->x164);
    k /= a->x8;
    k = 1.0f - k;
    k *= 0.3f;
    e->pivotPos.y = k * njSin(ang);
    if (0.0f < e->x164) {
        if ((ang & 0x7FFFF) != 0) {
            ang = (ang + 0x100) & 0xFFFF;
        }
    } else {
        ang = (ang + 0x100) & 0xFFFF;
    }
    fn_800D0CC8(e);
    e->pivot = 0;
    e->pivotAng[0] = ang;
    e->ang[1] = save;
}

extern void fn_801DBE1C(const char* fmt, ...);
extern void* fn_801E1C7C(s32 n);
/* EvExt.info of a script object: the common head, then one kind word per script entry from 0x24. */
typedef struct EvInfoScript {
    s32 count;      /* 0x00 number of words present */
    u8 pad4[0x20];
    s32 kind[1];    /* 0x24 */
} EvInfoScript;
extern void* fn_800C355C(NJS_TEXLIST** out, EvExt* ctx, s32 idx);
extern void fn_801E7600(void* model, s32 a, s32 b, s32 c);
extern void* fn_801DDAB0(void* a, void* b, void* c, void* d, s16* e);
extern EvSlot* fn_801DD984(void);
extern char lbl_802B1538[];

void fn_800D1324(EvObj* self) {
    EvScript* h;
    s32 count;
    s32 i;
    s32 nk;
    s32 nv;
    s32 j;
    EvExt* ext;
    EvScriptEntry* e;
    s32* kp;
    void** vp;
    s32 kind;
    EvInfoScript* kinds;
    ItemList* vals;
    s16 sz[2];

    self->x25c = 0;
    ext = self->ext;
    count = ext->files->count;
    if (count > 0) {
        h = fn_801E1C7C((count - 1) * 0x2c + 0x44);
        if (h != 0) {
            h->h0 = 0;
            h->h2 = count;
            h->w4 = lbl_80310A1C[6];
            h->f8 = lbl_802E1154[h->w4].f0;
            h->fc = h->f10 = h->f14 = 0.0f;
            e = h->entries;
            j = 0;
            i = 0;
            kinds = ext->info;
            vals = ext->items;
            nk = kinds->count;
            kp = kinds->kind;
            nv = vals->count;
            vp = vals->items;
            self->x25c = h;
            for (; i < count; e++, i++) {
                e->wc = fn_800C355C(&e->w8, ext, i);
                if (e->w8 != 0) {
                    fn_80227810(e->w8);
                }
                if (e->wc != 0) {
                    kind = (nk > i + 8) ? *kp : 6;
                    switch (kind) {
                    case 0:
                        if (nv > j) {
                            e->motion = *vp;
                            vp++;
                            j++;
                        } else {
                            e->motion = 0;
                        }
                        if (nv > j) {
                            e->w14 = *vp;
                            vp++;
                            j++;
                        } else {
                            e->w14 = 0;
                        }
                        e->h0 = 1;
                        e->h2 = 0;
                        e->f18 = 0.0f;
                        e->f1c = 0.0f;
                        e->w20 = 0;
                        e->w24 = 0;
                        break;
                    case 1:
                        e->h0 = 1;
                        e->h2 = 1;
                        fn_801E7600(e->wc, 1, -3, 0);
                        e->f18 = 0.0f;
                        e->w20 = 0;
                        e->w24 = 0;
                        break;
                    case 2:
                        e->h0 = 1;
                        e->h2 = 2;
                        fn_801E7600(e->wc, 1, -3, 0);
                        e->f18 = 0.0f;
                        e->w20 = 0;
                        e->w24 = 0;
                        break;
                    case 3:
                        e->h0 = 0;
                        e->f4 = -1.0f;
                        e->h2 = 3;
                        sz[0] = 0x20;
                        sz[1] = 0x20;
                        e->w20 = fn_801DDAB0(&lbl_803474EC, e->wc, e->w8, e->w8, sz);
                        e->w24 = fn_801DD984();
                        break;
                    case 4:
                        e->h0 = 1;
                        e->h2 = 4;
                        break;
                    case 5:
                        e->h0 = (lbl_80310B3C[0x38] >> 22) & 1;
                        e->h2 = 5;
                        e->w20 = 0;
                        e->w24 = 0;
                        break;
                    default:
                        e->h0 = 0;
                        e->h2 = kind;
                        break;
                    }
                    kp++;
                } else {
                    fn_801DBE1C(lbl_802B1538, i);
                    break;
                }
            }
        } else {
            count = 0;
        }
        self->x218 = count;
    } else {
        self->x218 = 0;
    }
}

extern PadState* lbl_80311A60[6];
extern s32 lbl_8034757C;
extern s32 lbl_80347444;
extern s32 fn_800D7B04(void);
extern s32 fn_800D84AC(s32 a);
extern s32 fn_8016E1D8(NJS_POINT3* p);
extern void fn_800CFDF0(EvObj* e);
extern void fn_8011513C(NJS_POINT3* p, EvObj* e);
extern s32 fn_80115EAC(EvObj* e, NJS_POINT3* from, NJS_POINT3* to);
extern void fn_80117290(EvObj* e);
extern s32 fn_80114950(EvObj* e);
extern void fn_80118204(EvObj* e);
s32 fn_800D07F8(EvObj* o);
extern NJS_POINT3 lbl_802E1124;

/* Wraps one axis of the map-99 world (a torus): *p back into [lo, hi), carrying the previous position *s. */
static inline void Wrap(f32* p, f32* s, f32 lo, f32 hi) {
    f32 t = *p - lo;
    if (t < 0.0f) {
        *p = hi + t;
        *s = (hi + *s) - lo;
    } else {
        t = *p - hi;
        if (t > 0.0f) {
            *p = lo + t;
            *s = (lo + *s) - hi;
        }
    }
}

/* Moves the ship out of whatever it hit; a blocked ship goes back to *v, a pushed one keeps the push
 * in the drift lbl_802E1124. */
static inline void ShipCollide(EvObj* e, NJS_POINT3* v) {
    f32 py;
    f32 px;
    f32 pz;

    px = e->pos.x;
    py = e->pos.y;
    pz = e->pos.z;
    fn_8011513C(&e->pos, e);
    fn_80115EAC(e, &e->pos, v);
    fn_80117290(e);
    if (fn_80114950(e) != 0) {
        lbl_802E1124.x *= 0.5f;
        lbl_802E1124.y *= 0.5f;
        lbl_802E1124.z *= 0.5f;
        if (px != e->pos.x || py != e->pos.y || pz != e->pos.z) {
            lbl_802E1124.x += e->pos.x - px;
            lbl_802E1124.y += e->pos.y - py;
            lbl_802E1124.z += e->pos.z - pz;
        }
    } else {
        e->pos.x = v->x;
        e->pos.y = v->y;
        e->pos.z = v->z;
    }
}

void fn_800D1630(MapTask* task) {
    EvObj* e = task->work;
    s32 x;
    s32 old;
    NJS_POINT3 v;
    u32 flags;

    fn_8016B96C(e->pos.y);
    fn_8016C7F0(e->rotv[1]);
    fn_8016C7D8(e->ang[1]);
    lbl_80347408 = 1;
    lbl_803473EC = 1;
    if (fn_8015E600(e) == 0) {
        old = e->ang[1];
        fn_80118368(e);
        if (old != e->ang[1]) {
            fn_8016C780(e->ang[1], e->ang[1]);
        }
        fn_800D1174(e);
        v.x = e->pos.x;
        v.y = e->pos.y;
        v.z = e->pos.z;
        if (lbl_80347444 != 1) {
            flags = lbl_80311A60[lbl_8034757C]->held;
            if (flags & 0x800) {
                if (fn_800D7B04() != 0) {
                    x = fn_800D84AC(1);
                }
            } else if (flags & 0x1000) {
                x = fn_800D84AC(0);
            } else {
                x = 0;
            }
            if (x == 0) {
                lbl_80347408 = 0;
                lbl_803473EC = 0;
            }
            fn_8016E1D8(&e->pos);
            fn_800CFDF0(e);
            ShipCollide(e, &v);
            fn_800D07F8(e);
            if (x == 0) {
                fn_80118204(e);
            }
        } else {
            e->vel.y = 0.0f;
            e->x164 = 0.0f;
        }
        if (lbl_80311AC0.map == 0x63) {
            Wrap(&e->pos.x, &v.x, -8400.0f, 8400.0f);
            Wrap(&e->pos.z, &v.z, -7200.0f, 7200.0f);
        }
        lbl_8030A794.x54 = e->pos.x;
        lbl_8030A794.x58 = e->pos.y;
        lbl_8030A794.x5c = e->pos.z;
        lbl_8030A794.x60 = e->ang[0];
        lbl_8030A794.x64 = e->ang[1];
        lbl_8030A794.x68 = e->ang[2];
        e->home.x = v.x;
        e->home.y = v.y;
        e->home.z = v.z;
    } else {
        e->home.x = e->pos.x;
        e->home.y = e->pos.y;
        e->home.z = e->pos.z;
        e->vel.y = 0.0f;
        e->x164 = 0.0f;
    }
    if (lbl_80346D8C == 0) {
        lbl_802E1118.x *= 0.9f;
        lbl_802E1118.y *= 0.9f;
        lbl_802E1118.z *= 0.9f;
    }
    lbl_80346D8C = 0;
}


void fn_800D1A34(Task* task) {
    s32 old;
    EvObj* e = task->work;

    fn_8016B96C(e->pos.y);
    fn_8016C7F0(e->rotv[1]);
    fn_8016C7D8(e->ang[1]);
    lbl_80347408 = 1;
    lbl_803473EC = 1;
    if (fn_8015E600(e) == 0) {
        old = e->ang[1];
        fn_80118368(e);
        if (old != e->ang[1]) {
            fn_8016C780(e->ang[1], e->ang[1]);
        }
        fn_800D1174(e);
        lbl_8030A794.x54 = e->pos.x;
        lbl_8030A794.x58 = e->pos.y;
        lbl_8030A794.x5c = e->pos.z;
        lbl_8030A794.x60 = e->ang[0];
        lbl_8030A794.x64 = e->ang[1];
        lbl_8030A794.x68 = e->ang[2];
    }
    e->home.x = e->pos.x;
    e->home.y = e->pos.y;
    e->home.z = e->pos.z;
    e->vel.y = 0.0f;
    e->x164 = 0.0f;
    if (lbl_80346D8C == 0) {
        lbl_802E1118.x *= 0.9f;
        lbl_802E1118.y *= 0.9f;
        lbl_802E1118.z *= 0.9f;
    }
    lbl_80346D8C = 0;
}

f32 fn_800CE4E8(NJS_POINT3* a, Flags* b) {
    u16 h = b->h24;
    Row* row = &lbl_802E1154[lbl_80310A1C[6]];
    f32 r = 0.0f;
    if (h & 0x8000) {
        switch ((h >> 8) & 0x7F) {
        case 0:
        case 1:
        case 30:
            if (!(row->w4 & 1)) {
                r = 2.0f * row->f0;
            } else if (150.0f >= a->y) {
                r = 0.5f * row->f0;
            }
            break;
        case 2:
        case 3:
            if (!(row->w4 & 2)) {
                r = 2.0f * row->f0;
            } else if (150.0f >= a->y) {
                r = 2.0f * row->f0;
            }
            break;
        case 4:
        case 5:
            if (!(row->w4 & 4)) {
                r = 2.0f * row->f0;
            } else if (150.0f >= a->y && -150.0f <= a->y) {
                r = 0.5f * row->f0;
            }
            break;
        case 6:
        case 7:
            if (!(row->w4 & 8)) {
                r = 2.0f * row->f0;
            } else if (150.0f >= a->y && -150.0f <= a->y) {
                r = 0.5f * row->f0;
            }
            break;
        }
    }
    return r;
}

void fn_800CF554(NJS_POINT3* p, NJS_POINT3* q, EvObj* m, Flags* f) {
    s32 hit = 0;
    if (150.0f >= q->y && (f->h24 & 0x8000)) {
        s32 sel;
        switch ((f->h24 >> 8) & 0x7F) {
        case 0:
        case 2:
            sel = 1;
            break;
        case 1:
        case 3:
        case 30:
            sel = 2;
            break;
        case 4:
        case 6:
            if (-150.0f <= q->y) {
                sel = 1;
            } else {
                sel = 0;
            }
            break;
        case 5:
        case 7:
            if (-150.0f <= q->y) {
                sel = 2;
            } else {
                sel = 0;
            }
            break;
        default:
            sel = 0;
            break;
        }
        if (sel == 1) {
            hit = fn_800CEDDC(q, m, f);
        } else if (sel == 2) {
            hit = fn_800CE67C(q, m, f);
        }
    }
    if (hit == 0) {
        m->vel.x *= 0.9f;
        m->vel.z *= 0.9f;
    } else {
        lbl_80346D90 = -1.0f;
    }
    p->x += m->vel.x;
    p->z += m->vel.z;
}

f32 fn_800CFBF4(NJS_POINT3* out, EvObj* o, Aux* q, f32 a) {
    f32 r;
    if (0.0f < a) {
        r = 0.1f * (a / 128.0f) + o->x164;
        if (q->x8 < r) {
            r = q->x8;
        }
        o->ang[1] = o->ang[1] - (s32)q->xc;
        o->rotv[1] = fn_80091228((s32)(4.0f * -q->xc), o->rotv[1], 4.0f);
        o->ang[0] = fn_80091228((s32)(-3712.0f * q->x10), o->ang[0], 4.0f);
        if (0.0f != q->xc) {
            f32 t = -o->x164 / q->x8;
            q->x14 = t * (f32)fn_8009761C(0, o->rotv[1]);
        }
        fn_801DCEB0(out, o->ang, -r);
    } else {
        f32 d;
        if (0.0f > a) {
            d = a / 128.0f;
        } else {
            d = -fabsf(q->x10) - 0.15625f;
        }
        r = 0.5f * d + o->x164;
        o->ang[0] = fn_80091228(0, o->ang[0], 4.0f);
        o->rotv[1] = fn_80091228(0, o->rotv[1], 4.0f);
        q->xc = 0.0f;
        if (0.0f >= r) {
            out->z = 0.0f;
            r = 0.0f;
            out->y = 0.0f;
            out->x = 0.0f;
        } else {
            fn_801DCEB0(out, o->ang, -r);
        }
    }
    o->x164 = r;
    return r;
}

void fn_800CE2B4(void) {
    Ent_800CE2B4* ent = &(*(Ent_800CE2B4(*)[20])&lbl_802E1154)[lbl_80310A1C[6]];
    s32 kind = 0;
    if (ent->tbl[1] != 0) {
        if (((*(Key_800CE2B4*)&lbl_80311AC0).id == 0x7A && (*(Key_800CE2B4*)&lbl_80311AC0).ch == 0x61) || ((*(Key_800CE2B4*)&lbl_80311AC0).id == 0x7D && ((*(Key_800CE2B4*)&lbl_80311AC0).ch == 0x61 || (*(Key_800CE2B4*)&lbl_80311AC0).ch == 0x62 || (*(Key_800CE2B4*)&lbl_80311AC0).ch == 0x64)) || ((*(Key_800CE2B4*)&lbl_80311AC0).id == 0x7F && ((*(Key_800CE2B4*)&lbl_80311AC0).ch == 0x61 || (*(Key_800CE2B4*)&lbl_80311AC0).ch == 0x62))) {
            kind = 3;
        } else {
            u8 buf[24];
            s32 n = fn_8021A1C4(buf);
            s32 m = fn_8021ADA0(&lbl_8030B7F4[0x1568], buf);
            f32 ratio;
            f32 thr = 0.3f;
            s32 v = *(s32*)&lbl_8030B7F4[0x157C];
            if (m > 0) {
                ratio = (f32)v / (f32)m;
            } else {
                ratio = 1.0f;
            }
            if (thr >= ratio) {
                kind = 2;
            } else if (n >= 10) {
                if (rand() & 1) {
                    kind = 0;
                } else {
                    kind = 1;
                }
            } else {
                kind = 0;
            }
        }
    }
    {
        EvObj* c = lbl_80347450;
        lbl_8030CEA0.x1774 = c->pos.x;
        lbl_8030CEA0.x1778 = c->pos.y;
        lbl_8030CEA0.x177c = c->pos.z;
        lbl_8030CEA0.x1780 = 0.005493164f * (f32)(c->ang[1] & 0xFFFF);
    }
    fn_80100178(ent->tbl[kind]);
    fn_801F7B04(0x7530);
    fn_800EB58C(3);
}

void fn_800D1E58(MapTask* o) {
    EvObj* w = o->work;
    lbl_80347454 = o;
    lbl_80347450 = w;
    switch (o->state) {
    case 0:
    case 0xFE:
        fn_800D1B5C(o);
        lbl_80347408 = 1;
        lbl_803473EC = 1;
        o->state = 1;
        o->f20 = -15000.0f;
        break;
    case 1:
        lbl_80347408 = 1;
        lbl_803473EC = 1;
        if (fn_8015E600((void *)(w)) == 0) {
            fn_80118368((void *)(w));
        }
        if (3.4028235e38f != w->pos.x && 3.4028235e38f != w->pos.y && 3.4028235e38f != w->pos.z) {
            lbl_803473A8 = 1;
            w->home.x = w->pos.x;
            w->home.y = w->pos.y;
            w->home.z = w->pos.z;
            if (!(lbl_80310B3C[0x22] & 0x20000)) {
                fn_8016B9B0(0);
                fn_8016B998(0);
                fn_8016C870(0);
                fn_8016C808(2);
            }
            fn_8016B950(w->pos.y, w->pos.y);
            fn_8016C7AC(0, 0);
            fn_8016C780(w->ang[1], w->ang[1]);
            o->state = 2;
        }
        break;
    case 2:
        if (lbl_80310B3C[0x22] & 0x10000) {
            o->state = 3;
        }
        fn_800D1A34((void *)(o));
        w->id |= 0x1000;
        break;
    case 3:
        fn_800D1630(o);
        break;
    case 0xFF:
        w = o->work;
        if (w->x248 != 0) {
            fn_80217830(w->x248);
            w->x248 = 0;
        }
        fn_8015EBF4(o->work);
        fn_8016ABEC();
        fn_80097660();
        fn_801E17E0(w->slots);
        fn_800D1268((void *)(w));
        fn_80100B74((void *)(o));
        break;
    }
}

void fn_800D0CC8(EvObj* a) {
    EvScript* s = a->x25c;
    EvScriptEntry* e = s->entries;
    s32 n = s->h2;
    do {
        if (e->h0 != 0) {
            switch (e->h2) {
            case 0: {
                f32 f;
                a->texlist = e->w8;
                a->model = e->wc;
                a->motion = e->motion;
                a->shape = e->w14;
                a->x18c = e->f18;
                a->speed = e->f1c;
                fn_801E5DF0(a);
                e->f18 = a->x18c;
                if (e->motion != NULL) {
                    f = (f32)(e->motion->nbFrame - 1);
                    if (e->f18 > f) {
                        e->f18 -= f;
                    }
                }
                break;
            }
            case 1:
            case 2:
            case 5:
                a->texlist = e->w8;
                a->model = e->wc;
                fn_801E66E0(a);
                break;
            case 3: {
                f32 save = a->colour.a;
                a->colour.a = e->f4;
                a->x1ac = e->w20;
                a->x1b0 = e->w24;
                a->id |= 0x4000;
                fn_801E6438(a);
                a->id &= ~0x4000;
                a->colour.a = save;
                break;
            }
            case 4: {
                s32 t4c;
                s32 t44;
                s32 saved;
                t44 = a->ang[0];
                t4c = a->ang[2];
                a->ang[2] = 0;
                a->ang[0] = 0;
                saved = lbl_8034753C;
                lbl_8034753C = 1;
                a->texlist = 0;
                a->model = e->wc;
                fn_801E6744(a);
                lbl_8034753C = saved;
                a->ang[0] = t44;
                a->ang[2] = t4c;
                break;
            }
            }
        }
        e++;
    } while (--n > 0);
}

int fn_800D1018(CbObj* ctx, CbObj* src) {
    ctx->dst->valC0 = src->valC0;
}

s32 fn_800CF944(EvColl *arg)
{
    s32 ret = 0;

    if (lbl_80347450 != NULL && lbl_80347450->coll != NULL) {
        ret = fn_80222B30(arg, lbl_80347450->coll);
    }
    return ret;
}

u32 fn_800CE4B4(void) {
    u32 v = lbl_802E1154[lbl_80310A1C[6]].w10;
    return (v | -v) >> 31;
}

f32 fn_800CF988(NJS_POINT3 *out, EvObj *a, Aux *b, f32 p)
{
    f32 v;
    f32 lim;
    f32 d;

    a->ang[0] = fn_80091228(0, a->ang[0], 4.0f);
    if (b->x10 != 0.0f) {
        v = 0.1f * b->x10 + a->vel.y;
        lim = b->x8 / 2.0f;
        if (v > lim) {
            v = lim;
        } else if (v < -lim) {
            v = -lim;
        }
    } else if (a->vel.y != 0.0f) {
        v = a->vel.y;
        if (0.0f >= p) {
            d = 0.078125f;
        } else {
            d = 0.5f * (p / 128.0f);
        }
        if (0.0f < v) {
            v = v - d;
            if (0.0f > v) {
                v = 0.0f;
            }
        } else {
            v = v + d;
            if (0.0f < v) {
                v = 0.0f;
            }
        }
    } else {
        v = 0.0f;
    }
    a->vel.y = v;
    out->y = v;
    out->z = 0.0f;
    out->x = 0.0f;
    return v;
}

s32 fn_800D07F8(EvObj* o) {
    NJS_POINT3 v;
    s32 res = 0;
    if (o->hit != NULL) {
        o->hit->x30 = 1;
        v.x = o->pos.x;
        v.y = 1.0f + o->pos.y;
        v.z = o->pos.z;
        res = fn_802256A0(&v, o->hit, 0xFFFF, lbl_8030A3C8[0] & 0xFFFF);
        o->hit->x30 = 4;
        if (res != 0) {
            lbl_8034740E = o->hit->h24 & 0xF;
            lbl_80346D88 = v.y;
        }
        if ((o->hit->h24 & 0xFF00) == 0x8300) {
            if (150.0f < o->pos.y && 170.0f >= o->pos.y) {
                v.x = 0.0f;
                v.y = 0.5f;
                v.z = 0.0f;
                lbl_80346D8C = 1;
                fn_800CF7BC(&lbl_802E1118, &v, 4.0f);
            }
        }
    }
    if (lbl_8034740E < 1 || lbl_8034740E > 9) {
        lbl_80347410 = 0.0f;
    } else {
        f32 a = (f32)fabs(o->x164);
        if (0.0f < a) {
            Aux* st = o->x25c;
            a = a / st->x8;
            lbl_80347410 += 1.7f * a;
        }
    }
    return res;
}


void fn_800CF6A8(NJS_POINT3 *a, NJS_POINT3 *b)
{
    f32 d;
    if (0.0f < a->y) {
        if (380.0f < b->y) {
            d = b->y - 380.0f;
            d = 20.0f - d;
            a->y = a->y * (d / 20.0f);
        } else if (!(lbl_802E1154[lbl_80310A1C[6]].w4 & 0x10) && 130.0f < b->y) {
            d = b->y - 130.0f;
            d = 20.0f - d;
            a->y = a->y * (d / 20.0f);
        }
    } else if (0.0f > a->y) {
        if (-230.0f > b->y) {
            d = -230.0f - b->y;
            d = 20.0f - d;
            a->y = a->y * (d / 20.0f);
        } else if (!(lbl_802E1154[lbl_80310A1C[6]].w4 & 0x20) && -130.0f > b->y) {
            d = -130.0f - b->y;
            d = 20.0f - d;
            a->y = a->y * (d / 20.0f);
        }
    }
}

extern void fn_801E7580(void *model, s16 n, s32 val);
extern void fn_801E75C0(void *model, s16 n, s32 val);
extern void fn_800D0970(EvObj* a, AuxEntry* e);

void fn_800D0E78(EvObj* a) {
    Aux* s = a->x25c;
    AuxEntry* e;
    s32 n;
    f32 t;
    Aux* sc;
    a->ang[2] = fn_80091228(s->x14, a->ang[2], 4.0f);
    e = s->entries;
    n = s->x2;
    do {
        switch (e->h2) {
        case 0:
            sc = a->x25c;
            if (0.0f < a->x164) {
                e->f1c = 0.2f + a->x164 / sc->x8;
            } else {
                e->f1c = 0.2f;
            }
            break;
        case 1:
            sc = a->x25c;
            if (sc->x0 == 1) {
                t = sc->xc / 819.0f;
            } else {
                t = 0.0f;
            }
            e->f18 = (t - e->f18) / 4.0f + e->f18;
            fn_801E7580(e->wc, 1, 8192.0f * e->f18);
            break;
        case 2:
            sc = a->x25c;
            if (sc->x0 == 1) {
                t = sc->x10;
            } else {
                t = 0.0f;
            }
            e->f18 = (t - e->f18) / 4.0f + e->f18;
            fn_801E75C0(e->wc, 1, 5461.0f * e->f18);
            break;
        case 3:
            fn_800D0970(a, e);
            break;
        case 5:
            break;
        }
        e++;
    } while (--n > 0);
}
