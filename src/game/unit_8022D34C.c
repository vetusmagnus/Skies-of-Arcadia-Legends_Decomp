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
