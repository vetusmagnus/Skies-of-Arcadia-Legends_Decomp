#include "types.h"
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
