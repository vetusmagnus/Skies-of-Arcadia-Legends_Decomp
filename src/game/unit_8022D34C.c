#include "types.h"
#include <dolphin/gx.h>
#include <dolphin/os/OSFastCast.h>
#include "ninja.h"
typedef struct {
    s32 f0;
    s32 f4;
    void* f8;
    void* fc;
    u8 pad_10[0x28];
    f32 f38;
    u8 pad_3c[0x10];
    s32 a;
    f32 b;
    f32 c;
} Unk8022D34C;
extern Unk8022D34C lbl_80311970;
extern f32 lbl_80347570;
extern void fn_8022F64C(void *p, u32 flags);
typedef struct Node { u8 pad_00[0x2c]; struct Node *child; struct Node *next; } Node;
extern void fn_8022F408(Node *n, s32 a, s32 b);
void fn_8022F0CC(Node *n, s32 a, s32 b);
s32 fn_8022E068(f32 *p, u16 i, f32 *a, f32 *b, f32 *c, f32 *d);
extern s32 lbl_80347884;
extern void fn_8023182C(void);
typedef struct Res230 { void *x0; void *x4; u8 pad08[0xc]; f32 x14; } Res230;
s32 fn_80230FCC(Res230 *r);
extern void fn_80288DE4(void *p, s32 (*f)(Res230 *));
extern void fn_80296F28(void);
extern s32 fn_8022E734(u8 kind, void *p, void *a, void *b, s32 f1, s32 f2, s32 f3);
typedef struct Pt { f32 x; f32 y; f32 z; } Pt;
typedef struct Rng {
    f32 x0;
    u8 pad4[4];
    f32 x8;
    u8 padc[0xc];
    f32 lo;
    f32 hi;
    Pt *pts;
    u8 pad24[0xc];
    f32 ylo;
    f32 yhi;
    f32 dx;
    f32 dz;
} Rng;
typedef struct { u8 pad[4]; void* x4; } Src;
typedef struct { s16 x0; s16 x2; s16 x4; u8 pad6[2]; s16* x8; } Out;
extern s32 fn_80230D10(u8 id, Src* s, s16** out);
extern void fn_80230BD4(u8 id, void *node, u32 **out, u16 idx);
#define STEP(n)                  \
    p += (n);                    \
    count++;                     \
    if (dst != 0) {              \
        if (dir) {               \
            *p = *dst;           \
        } else {                 \
            *dst = *p;           \
        }                        \
        dst++;                   \
    }
#define STEP_8022E4CC(n)                              q = (p += (n));                          if (dir == 0) {                              if (*q != cmp) {                             *q = val;                            }                                    } else {                                     *q = val;                            }
typedef struct Spring8022E18C { f32 a, b, c, d, e; } Spring8022E18C;
typedef struct Ctx {
    u8 pad0[0x54];
    s32 f54;
    u8 pad58[0x14];
    f32 f6c;
    f32 f70;
    f32 f74;
} Ctx;
extern Ctx lbl_8030E830;
typedef struct Nrm {
    f32 x, y, z;
} Nrm;
typedef struct Vtx Vtx;
typedef struct Hdr {
    u16 len;
    s16 flags;
    s16 v;
} Hdr;
typedef union Cur {
    s16 *s;
    Hdr *h;
} Cur;
extern GXColor lbl_8034D480;
extern Nrm lbl_802F93E8;
extern void njPushMatrixEx(void);
extern void njPopMatrixEx(void);
extern void njInvertMatrix(NJS_MATRIX m);
extern void fn_80286EE8(void);
extern void fn_8028B498(void);
extern void fn_802928F4(Nrm *src, Nrm *dst);
extern void fn_8029D010(void);
extern void fn_8029D0F4(s16 op, s16 v);
extern void fn_8029D698(s16 op, s16 *p, GXColor *a, GXColor *b, s32 z);
extern void fn_802A8F40(s32 a);
extern void fn_8023152C(GXColor *mat, GXColor *amb);
extern void fn_80231688(s32 mode);
extern void fn_80231360(s16 *strip, Vtx *verts, u32 flags, Nrm *nrm);
/* GX light helpers, not yet named in symbols.txt (signatures are the SDK's). */
extern void fn_8024F82C(GXLightObj *l, GXColor c);
/* GXInitLightColor */
extern void fn_8024F74C(GXLightObj *l, f32 x, f32 y, f32 z);
/* GXInitLightDir */
extern void fn_8024F4EC(GXLightObj *l, f32 cutoff, s32 fn);
/* GXInitLightSpot */
extern void fn_8024F67C(GXLightObj *l, f32 d, f32 b, s32 fn);
/* GXInitLightDistAttn */
extern void fn_8024F4D0(GXLightObj *l, f32 *x, f32 *y, f32 *z);
/* GXGetLightPos */
extern void fn_8024F4C0(GXLightObj *l, f32 x, f32 y, f32 z);
/* GXInitLightPos */
extern void fn_8024F838(GXLightObj *l, s32 id);
/* GXLoadLightObjImm */

typedef struct LightParam {
    f32 dir;    /* z of the light direction */
    f32 dist;   /* GXInitLightDistAttn ref distance */
    f32 bright; /* GXInitLightDistAttn ref brightness */
    f32 div;    /* position divisor */
} LightParam;
extern GXLightObj lbl_803168B0[2];
extern LightParam lbl_802F93C8[2];
typedef struct {
    s32 f0;
    s32 f4;
    void *f8;
    void *fc;
    f32 f38_src;
} Src8031195C;
extern Src8031195C lbl_8031195C;
typedef struct { s32 w[16]; } Blk40;
extern Blk40 lbl_803118DC;
extern Blk40 lbl_8031191C;
extern f32 lbl_803119D4[3];
extern s32 lbl_803119C8[3];
extern s32 lbl_80347574;
extern s32 fn_8022D384(void);
typedef struct Out_80230634 {
    f32 x;
    f32 y;
    f32 z;
    u8 pad_c[8];
    f32 *dist;
    u8 pad_18[0xc];
    s8 sel;
} Out_80230634;
typedef union Cur_80230634 {
    s16 *s;
    f32 *f;
} Cur_80230634;
extern u8 lbl_802F9360[];
extern void *fn_801E1C7C(u32 size);
extern f32 fn_80291A5C(f32 v);
extern char lbl_8034C750;
extern int strncmp(const char *a, const char *b, u32 n);
extern char lbl_8034C760;
extern void fn_80230920(s16 *p, s16 *v);
typedef struct Ent28 { u8 pad[0x1c]; } Ent28;
typedef struct Rec3 { u32 hi; u32 *cmd; Ent28 *base; } Rec3;
extern u32 lbl_80347EF4;
extern u32 lbl_80347EF8;
extern Rec3 lbl_80316930;
extern void fn_802A5D20(u32 hi, Ent28 *dst, u32 *src);

void fn_8022D34C(s32 a, f32 b) {
    if (a > 0) {
        lbl_80311970.a = a;
        lbl_80311970.b = lbl_80347570;
        lbl_80311970.c = b;
    } else {
        lbl_80311970.a = -1;
    }
}

void fn_8022E964(Node *n, s32 mask);
extern void fn_8022EF58(Node *n, s32 mask);
extern char lbl_8034C750;
void fn_8022E8F8(void* p, s32 arg) {
    if (!(*(u32*)p & 0x80000000)) {
        if (strncmp((const char*)p, &lbl_8034C750, 4) == 0) {
            p = (u8*)p + 8;
        } else {
            return;
        }
    }
    fn_8022E964(p, arg);
}

static inline void E964_SetFlags(Node *n, s32 mask)
{
    s16 *cur = NULL;
    s16 *next;

    if (fn_8022E734(8, n, &cur, &next, 1, 0, 0)) {
        do {
            *cur &= 0xfff;
            *cur |= mask;
            cur = next;
        } while (fn_8022E734(8, n, &cur, &next, 0, 0, 0));
    }
}

static inline void E964_Leaf(Node *n, s32 mask)
{
    fn_8022EF58(n, mask);
    if (n->child != NULL) {
        fn_8022E964(n->child, mask);
    }
    if (n->next != NULL) {
        fn_8022E964(n->next, mask);
    }
}

static inline void E964_Lvl2(Node *n, s32 mask)
{
    E964_SetFlags(n, mask);
    if (n->child != NULL) {
        E964_Leaf(n->child, mask);
    }
    if (n->next != NULL) {
        E964_Leaf(n->next, mask);
    }
}

static inline void E964_Lvl1(Node *n, s32 mask)
{
    E964_SetFlags(n, mask);
    if (n->child != NULL) {
        E964_Lvl2(n->child, mask);
    }
    if (n->next != NULL) {
        E964_Lvl2(n->next, mask);
    }
}

void fn_8022E964(Node *n, s32 mask)
{
    E964_SetFlags(n, mask);
    if (n->child != NULL) {
        E964_Lvl1(n->child, mask);
    }
    if (n->next != NULL) {
        E964_Lvl1(n->next, mask);
    }
}

void fn_8022F00C(void *p) {
    fn_8022F64C(p, 0x4000);
}

extern void fn_801F01E4(void);
extern void fn_801D6850(void);
typedef struct Msg {
    s16 x0;
    s16 x2;
    s16 x4;
    s16 x6;
    s32 x8;
    s32 xc;
} Msg;
void fn_8022F050(void *p, s32 a, s32 b);
void fn_8022F030(void *p, s32 a, s32 b) {
    fn_8022F050(p, a, b);
}

s16 *fn_8023080C(void *p, s16 *v, s16 *res);
void fn_8022F6B8(Node *n, s32 mask);
extern void fn_8022FCE4(Node *n, s32 mask);
void fn_8022F64C(void* p, u32 arg) {

    if (!(*(u32*)p & 0x80000000)) {
        if (strncmp((const char*)p, &lbl_8034C750, 4) == 0) {
            p = (u8*)p + 8;
        } else {
            return;
        }
    }
    fn_8022F6B8(p, arg);
}

static inline void F6B8_SetFlags(Node *n, s32 mask)
{
    s16 *cur = NULL;
    s16 *next;

    if (fn_8022E734(8, n, &cur, &next, 1, 0, 0)) {
        do {
            cur++;
            *cur &= 0xefff;
            *cur |= mask;
            cur = next;
        } while (fn_8022E734(8, n, &cur, &next, 0, 0, 0));
    }
}

static inline void F6B8_Leaf(Node *n, s32 mask)
{
    fn_8022FCE4(n, mask);
    if (n->child != NULL) {
        fn_8022F6B8(n->child, mask);
    }
    if (n->next != NULL) {
        fn_8022F6B8(n->next, mask);
    }
}

static inline void F6B8_Lvl2(Node *n, s32 mask)
{
    F6B8_SetFlags(n, mask);
    if (n->child != NULL) {
        F6B8_Leaf(n->child, mask);
    }
    if (n->next != NULL) {
        F6B8_Leaf(n->next, mask);
    }
}

static inline void F6B8_Lvl1(Node *n, s32 mask)
{
    F6B8_SetFlags(n, mask);
    if (n->child != NULL) {
        F6B8_Lvl2(n->child, mask);
    }
    if (n->next != NULL) {
        F6B8_Lvl2(n->next, mask);
    }
}

void fn_8022F6B8(Node *n, s32 mask)
{
    F6B8_SetFlags(n, mask);
    if (n->child != NULL) {
        F6B8_Lvl1(n->child, mask);
    }
    if (n->next != NULL) {
        F6B8_Lvl1(n->next, mask);
    }
}

s16 *fn_802307EC(void *p, s16 *v, s16 *res) {
    return fn_8023080C(p, v, res);
}

extern void fn_801D6890(Msg*, s16);
void fn_80230F24(void) {
}

void fn_80230F28(Msg* a, s16 i) {
    fn_801D6890(a, i);
}

void fn_80230F48(void) {
    fn_801F01E4();
    fn_801D6850();
}

static inline void walk4(Node *n, s32 a, s32 b)
{
    fn_8022F408(n, a, b);
    if (n->child != 0) {
        fn_8022F0CC(n->child, a, b);
    }
    if (n->next != 0) {
        fn_8022F0CC(n->next, a, b);
    }
}

static inline void walk3(Node *n, s32 a, s32 b)
{
    fn_8022F408(n, a, b);
    if (n->child != 0) {
        walk4(n->child, a, b);
    }
    if (n->next != 0) {
        walk4(n->next, a, b);
    }
}

static inline void walk2(Node *n, s32 a, s32 b)
{
    fn_8022F408(n, a, b);
    if (n->child != 0) {
        walk3(n->child, a, b);
    }
    if (n->next != 0) {
        walk3(n->next, a, b);
    }
}

void fn_8022F0CC(Node *n, s32 a, s32 b)
{
    fn_8022F408(n, a, b);
    if (n->child != 0) {
        walk2(n->child, a, b);
    }
    if (n->next != 0) {
        walk2(n->next, a, b);
    }
}

s32 fn_8022DFFC(void *p) {
    f32 d;
    f32 a;
    f32 b;
    f32 c;
    s32 i = 0;
    s32 ret;
    for (;;) {
        ret = fn_8022E068(p, (u16)i, &a, &b, &c, &d);
        if (ret == 0 && (u16)i != 0) {
            break;
        }
        i++;
    }
    return i;
}

void fn_80230F6C(void *p) {
    fn_8023182C();
    lbl_80347884 = 0;
    fn_80288DE4(p, fn_80230FCC);
    lbl_80347884 = 1;
    fn_80288DE4(p, fn_80230FCC);
    fn_80296F28();
}

void fn_8022F580(void *node, s32 mask, u8 op)
{
    s16 *cur = NULL;
    s16 *next;
    s32 first = 1;

    while (fn_8022E734(0x40, node, &cur, &next, first, 0x40, 0x49)) {
        switch (op) {
        default:
            *cur |= mask;
            break;
        case 2:
            *cur &= mask;
            break;
        case 3:
            *cur ^= mask;
            break;
        }
        first = 0;
        cur = next;
    }
}

s32 fn_80230E48(Rng *r, f32 t, u16 i) {
    Pt *p;
    s32 ok = 1;
    f32 d;
    if (t < r->lo || t > r->hi) {
        ok = 0;
    }
    p = r->pts;
    if (p != 0) {
        if (r->ylo != r->yhi) {
            if (r->ylo > p[i].y || r->yhi < p[i].y) {
                ok = 0;
            }
        }
        if (r->dx != r->dz) {
            d = r->x0 - p[i].x;
            if (d < 0.0f) {
                d = -1.0f * d;
            }
            if (d > r->dx) {
                ok = 0;
            }
            d = r->x8 - p[i].z;
            if (d < 0.0f) {
                d = -1.0f * d;
            }
            if (d > r->dz) {
                ok = 0;
            }
        }
    }
    return ok;
}

s32 fn_802301A0(Src* src, Out* out) {
    s16* p;
    u16 i;
    if (src->x4 == NULL) {
        return 0;
    }
    for (i = 0x20; i < 0x38; i++) {
        if (fn_80230D10(i, src, &p) != 0) {
            i = 0x39;
        }
    }
    if (i == 0x38) {
        return 0;
    }
    out->x4 = *p++;
    out->x0 = *p++;
    out->x2 = *p++;
    p++;
    out->x8 = p;
    return 1;
}

s32 fn_8022E258(void *node, u32 *dst, u8 kind, s8 dir) {
    u16 idx;
    u16 id;
    s32 count = 0;
    u32 *p = 0;
    for (id = 0x10; id < 0x20; id++) {
        for (idx = 1;; idx++) {
            fn_80230BD4(id, node, &p, idx);
            if (p == 0) break;
            switch (kind) {
            case 0:
                switch (id) {
                case 0x11:
                case 0x13:
                case 0x15:
                case 0x17:
                    STEP(1)
                    break;
                }
                break;
            case 1:
                switch (id) {
                case 0x13:
                case 0x17:
                    STEP(2)
                    break;
                case 0x12:
                case 0x16:
                    STEP(1)
                    break;
                }
                break;
            case 2:
                switch (id) {
                case 0x17:
                    STEP(3)
                    break;
                case 0x14:
                    STEP(1)
                    break;
                case 0x15:
                case 0x16:
                    STEP(2)
                    break;
                }
                break;
            }
        }
    }
    return count;
}

void fn_8022E4CC(void *node, u32 val, u32 cmp, s8 dir, u8 kind, u8 first) {
    u16 idx;
    u8 id;
    u8 end;
    u32 *p = 0;
    u32 *q;
    if (kind >= 3) {
        end = first + 1;
    } else {
        first = 0x10;
        end = 0x20;
    }
    for (id = first; id < end; id++) {
        for (idx = 1;; idx++) {
            fn_80230BD4(id, node, &p, idx);
            if (p == 0) break;
            switch (kind) {
            case 0:
            case 3:
                switch (id) {
                case 0x11:
                case 0x13:
                case 0x15:
                case 0x17:
                    STEP_8022E4CC(1)
                    break;
                }
                break;
            case 1:
            case 4:
                switch (id) {
                case 0x13:
                case 0x17:
                    STEP_8022E4CC(2)
                    break;
                case 0x12:
                case 0x16:
                    STEP_8022E4CC(1)
                    break;
                }
                break;
            case 2:
            case 5:
                switch (id) {
                case 0x17:
                    STEP_8022E4CC(3)
                    break;
                case 0x14:
                    STEP_8022E4CC(1)
                    break;
                case 0x15:
                case 0x16:
                    STEP_8022E4CC(2)
                    break;
                }
                break;
            }
        }
    }
}

void fn_80231688(s32 mode) {
    GXSetNumTexGens(1);
    GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX2x4, GX_TG_TEX0, GX_IDENTITY, GX_FALSE, GX_PTIDENTITY);
    GXSetNumTevStages(2);
    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR1A1);
    GXSetTevKColorSel(GX_TEVSTAGE0, GX_TEV_KCSEL_1);
    GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_ZERO, GX_CC_KONST, GX_CC_TEXC, GX_CC_ZERO);
    GXSetTevColorOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_ZERO, GX_CA_TEXA, GX_CA_RASA, GX_CA_ZERO);
    GXSetTevAlphaOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    GXSetTevOrder(GX_TEVSTAGE1, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR0A0);
    GXSetTevColorIn(GX_TEVSTAGE1, GX_CC_ZERO, GX_CC_CPREV, GX_CC_RASC, GX_CC_ZERO);
    GXSetTevColorOp(GX_TEVSTAGE1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    GXSetTevAlphaIn(GX_TEVSTAGE1, GX_CA_ZERO, GX_CA_APREV, GX_CA_RASA, GX_CA_ZERO);
    GXSetTevAlphaOp(GX_TEVSTAGE1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    if (mode == 1) {
        GXSetZCompLoc(GX_FALSE);
        GXSetAlphaCompare(GX_GREATER, 0, GX_AOP_AND, GX_ALWAYS, 0);
    } else {
        GXSetZCompLoc(GX_TRUE);
        GXSetAlphaCompare(GX_ALWAYS, 0, GX_AOP_AND, GX_ALWAYS, 0);
    }
}

s32 fn_8022E18C(Spring8022E18C *p, s32 n, f32 *out)
{
    s32 ok = 1;
    f32 e;
    f32 b2;
    f32 na;
    f32 c;
    f32 v;
    f32 x;
    f32 last;
    f32 acc;
    s32 i;

    if (n > 300) {
        return 0;
    }
    b2 = p->b * p->b;
    c = p->c;
    na = -p->a;
    v = p->d;
    e = p->e;
    acc = na * v - c * b2;
    v += acc * e / 2;
    x = c + v * e;
    for (i = 0; i < n; i++) {
        acc = na * v - x * b2;
        v = v + acc * e;
        x += v * e;
        if (n > 1 && i == n - 2) {
            last = -x;
        }
    }
    *out = -x;
    if (n != 0) {
        f32 d = last - *out;
        if (d < 0.0f) {
            d *= -1.0f;
        }
        if (d < 0.0001) {
            ok = 0;
        }
    }
    return ok;
}

void fn_8023152C(GXColor *mat, GXColor *amb) {
    GXColor out;
    f32 r, g, b;
    GXSetChanMatColor(GX_COLOR0A0, *mat);
    GXSetChanMatColor(GX_COLOR1A1, *mat);
    if (lbl_8030E830.f54 == 1) {
        r = __OSu8tof32(&amb->r);
        g = __OSu8tof32(&amb->g);
        b = __OSu8tof32(&amb->b);
        r *= lbl_8030E830.f6c;
        g *= lbl_8030E830.f70;
        b *= lbl_8030E830.f74;
        if (r > 255.0f) r = 255.0f;
        if (g > 255.0f) g = 255.0f;
        if (b > 255.0f) b = 255.0f;
        out.r = __OSf32tou8(r);
        out.g = __OSf32tou8(g);
        out.b = __OSf32tou8(b);
    } else {
        out.b = 0;
        out.g = 0;
        out.r = 0;
    }
    out.a = 0;
    GXSetChanAmbColor(GX_COLOR0A0, out);
    GXSetChanAmbColor(GX_COLOR1A1, out);
}

void fn_8023114C(s16 *p, u8 kind, Vtx *verts, s32 mode) {
    Cur h;
    s32 k;
    GXColor col_mat = {255, 255, 255, 255};
    GXColor col_amb = lbl_8034D480;
    Nrm nrm;
    s16 op;
    s16 code;
    s16 cnt;
    u16 len;
    s16 flags;
    s16 v;
    njPushMatrixEx();
    fn_80286EE8();
    fn_8028B498();
    njInvertMatrix(0);
    fn_802928F4(&lbl_802F93E8, &nrm);
    njPopMatrixEx();
    k = kind;
    while ((op = *p++) != 0xff) {
        code = op & 0xff;
        if (code < 8) {
            switch (code) {
            case 1:
                fn_8029D010();
                break;
            case 4:
                return;
            case 5:
                break;
            }
        } else if (code < 0x10) {
            v = *p++;
            fn_8029D0F4(op, v);
            if (*p & 0x18) {
                p += 8;
            }
        } else if (code < 0x40) {
            cnt = *p++;
            fn_8029D698(op, p, &col_mat, &col_amb, 0);
            p += cnt;
        } else {
            h.s = p;
            flags = h.h->flags;
            len = h.h->len;
            p += 2;
            if (!(op & 0x800)) {
                if (mode != 0) {
                    p += len - 1;
                    continue;
                }
            } else {
                if (mode != 1) {
                    p += len - 1;
                    continue;
                }
            }
            fn_802A8F40(1);
            if (k == 0x2a && code == 0x41) {
                GXSetNumChans(2);
                GXSetChanCtrl(GX_COLOR0A0, GX_FALSE, GX_SRC_REG, GX_SRC_VTX, 0, GX_DF_CLAMP, GX_AF_NONE);
                GXSetChanCtrl(GX_COLOR1, GX_TRUE, GX_SRC_REG, GX_SRC_REG, 0xc0, GX_DF_CLAMP, GX_AF_NONE);
                GXSetChanCtrl(GX_ALPHA1, GX_TRUE, GX_SRC_REG, GX_SRC_REG, 0xc0, GX_DF_CLAMP, GX_AF_SPOT);
                fn_8023152C(&col_mat, &col_amb);
                fn_80231688(mode);
                fn_80231360(p, verts, flags, &nrm);
            }
            p += len - 1;
        }
    }
}

void fn_8023182C(void) {
    GXColor col = {255, 255, 255, 255};
    f32 x, y, z;
    GXLightObj *l;
    LightParam *p;
    fn_8024F82C(&lbl_803168B0[0], col);
    fn_8024F74C(&lbl_803168B0[0], 0.0f, 0.0f, lbl_802F93C8[0].dir);
    fn_8024F4EC(&lbl_803168B0[0], 0.0f, 0);
    fn_8024F67C(&lbl_803168B0[0], lbl_802F93C8[0].dist, lbl_802F93C8[0].bright, 3);
    fn_8024F4D0(&lbl_803168B0[0], &x, &y, &z);
    x /= lbl_802F93C8[0].div;
    y /= lbl_802F93C8[0].div;
    z /= lbl_802F93C8[0].div;
    fn_8024F4C0(&lbl_803168B0[0], x, y, z);
    fn_8024F838(&lbl_803168B0[0], 0x80);
    l = &lbl_803168B0[1];
    p = &lbl_802F93C8[1];
    fn_8024F82C(l, col);
    fn_8024F74C(l, 0.0f, 0.0f, p->dir);
    fn_8024F4EC(l, 0.0f, 0);
    fn_8024F67C(l, p->dist, p->bright, 3);
    fn_8024F4D0(l, &x, &y, &z);
    x /= p->div;
    y /= p->div;
    z /= p->div;
    fn_8024F4C0(l, x, y, z);
    fn_8024F838(l, 0x40);
}

void fn_8022D9C4(void)
{
    lbl_80311970.f0 = lbl_8031195C.f4;
    lbl_80311970.f4 = lbl_8031195C.f0;
    lbl_80311970.f8 = lbl_8031195C.f8;
    lbl_80311970.fc = lbl_8031195C.fc;
    lbl_80311970.f38 = lbl_8031195C.f38_src;
    lbl_80347574 = fn_8022D384();
    lbl_8031195C.f4 = 2;
    lbl_8031195C.f0 = 8;
    lbl_8031195C.f8 = lbl_803119D4;
    lbl_8031195C.fc = lbl_803119C8;
    lbl_803118DC = lbl_8031191C;
}

s32 fn_80230634(Src *src, Out_80230634 *out) {
    Cur_80230634 cur;
    s16 cnt;
    u8 *tbl;
    u16 j;
    u16 i;
    s16 id;
    f32 *q;
    u8 kind;
    f32 x, y, z;
    f32 dx, dy, dz;
    if (src->x4 == 0) {
        return 0;
    }
    if (out->dist == 0) {
        for (i = 0x20; i < 0x38; i++) {
            if (fn_80230D10(i, src, &cur.s)) {
                i = 0x39;
            }
        }
        if (i == 0x38) {
            return 0;
        }
        cur.s++;
        id = *cur.s++;
        cnt = *cur.s++;
        cur.s++;
        out->dist = fn_801E1C7C(cnt << 2);
    }
    if (out->dist == 0) {
        return 0;
    }
    kind = id;
    tbl = lbl_802F9360 + kind - 0x20;
    q = cur.f;
    for (j = 0; j < cnt; j++) {
        x = q[0];
        y = q[1];
        z = q[2];
        q += 3;
        q += *tbl - 3;
        switch (out->sel) {
        case 1:
            out->z = z;
            out->y = y;
            break;
        case 2:
            out->x = x;
            out->y = y;
            break;
        case 3:
            out->x = x;
            out->z = z;
            break;
        case 4:
            break;
        default:
            out->y = y;
            break;
        }
        dx = x - out->x;
        dy = y - out->y;
        dz = z - out->z;
        out->dist[j] = fn_80291A5C(dx * dx + dy * dy + dz * dz);
    }
    return 1;
}

void fn_8022F050(void *n, s32 a, s32 b) {
    if (!(*(u32 *)n & 0x80000000)) {
        if (strncmp(n, &lbl_8034C750, 4) == 0) {
            n = (u8 *)n + 8;
        } else {
            return;
        }
    }
    fn_8022F0CC(n, a, b);
}

s16 *fn_8023080C(void *p0, s16 *v0, s16 *res0) {
    s16 *v = v0;
    u16 i;
    void *p = p0;
    s16 *res = res0;
    s16 *tmp;
    if (strncmp((const char*)p, &lbl_8034C750, 4) == 0) {
        p = (u8*)p + 8;
    } else if (strncmp((const char*)p, &lbl_8034C760, 4) == 0) {
        return res;
    }
    tmp = res;
    if (res == 0) {
        for (i = 0x40; i < 0xff; i++) {
            switch (i) {
            case 0x40:
            case 0x43:
            case 0x46:
                break;
            default:
                if (fn_80230D10(i, p, &tmp) != 0) {
                    i = 0x100;
                }
                break;
            }
        }
        if (i == 0xff) {
            return 0;
        }
    }
    fn_80230920(tmp, v);
    if (res == 0) {
        return tmp;
    }
    return res;
}

void fn_8022EF58(Node *n, s32 mask) {
    s16 *cur = NULL;
    s16 *next;

    if (fn_8022E734(8, n, &cur, &next, 1, 0, 0)) {
        do {
            *cur &= 0xfff;
            *cur |= mask;
            cur = next;
        } while (fn_8022E734(8, n, &cur, &next, 0, 0, 0));
    }
}

void fn_8022FCE4(Node *n, s32 mask) {
    s16 *cur = NULL;
    s16 *next;

    if (fn_8022E734(8, n, &cur, &next, 1, 0, 0)) {
        do {
            cur += 1;
            *cur &= 0xefff;
            *cur |= mask;
            cur = next;
        } while (fn_8022E734(8, n, &cur, &next, 0, 0, 0));
    }
}

u32 fn_8023109C(u32 *cmd, Ent28 *base) {
    Rec3 *rec = &lbl_80316930;
    u32 cnt;
    u32 lo;
    u32 w;
    u32 w1;
    u32 hi;
    u32 idx;

    while ((u8)(w = *cmd) != 0xff) {
        w1 = cmd[1];
        cmd += 2;
        hi = w1 >> 16;
        lbl_80347EF4 += hi;
        cnt = w >> 16;
        idx = w1 & 0xffff;
        rec->hi = hi;
        lo = w & 0x7fff;
        rec->cmd = cmd;
        lbl_80347EF8 += hi;
        if ((s32)(u8)w == 0x2a) {
            rec->base = base + idx;
            fn_802A5D20(hi, base + idx, cmd);
        }
        cmd += cnt - 1;
    }
    return lo;
}
