#include "types.h"
#include <dolphin/gx.h>
typedef struct {
    u8 pad[0x4c];
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
extern s32 fn_8022E068(void *p, u16 i, s32 *a, s32 *b, s32 *c, s32 *d);
extern s32 lbl_80347884;
extern void fn_8023182C(void);
extern void fn_80230FCC(void);
extern void fn_80288DE4(void *p, void (*f)(void));
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

void fn_8022D34C(s32 a, f32 b) {
    if (a > 0) {
        lbl_80311970.a = a;
        lbl_80311970.b = lbl_80347570;
        lbl_80311970.c = b;
    } else {
        lbl_80311970.a = -1;
    }
}

extern void fn_8022E964(void*, void*);
extern char lbl_8034C750;
void fn_8022E8F8(void* p, void* arg) {
    if (!(*(u32*)p & 0x80000000)) {
        if (strncmp((const char*)p, &lbl_8034C750, 4) == 0) {
            p = (u8*)p + 8;
        } else {
            return;
        }
    }
    fn_8022E964(p, arg);
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
extern void fn_8022F050(Msg*, s16);
void fn_8022F030(Msg* a, s16 i) {
    fn_8022F050(a, i);
}

extern void fn_8023080C(Msg*, s16);
extern void fn_8022F6B8(void*, u32);
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

void fn_802307EC(Msg* a, s16 i) {
    fn_8023080C(a, i);
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
    s32 d;
    s32 a;
    s32 b;
    s32 c;
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
