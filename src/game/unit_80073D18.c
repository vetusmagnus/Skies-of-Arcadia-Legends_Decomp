#include "types.h"
typedef struct TNode { u8 pad[0x2c]; struct TNode* child; struct TNode* next; } TNode;
void fn_800740D0(TNode* n, s16* count);
void* fn_801E1A74(s32 n, s32 size);
void fn_80074394(void* a, s16* b);
void fn_800743BC(void* obj, void* p, s16* out);
typedef struct Node {
    u8 pad0[0xC];
    f32 len;
    u8 pad10[0x2C - 0x10];
    struct Node *parent;
    u8 pad30[4];
} Node;
extern void fn_80061F58(void *p, u32 n, s32 c);
extern void fn_80073DD0(void *a, void *b, s32 c, s32 e, s16 *m);
extern s16 fn_80060F6C(s32 i, void *c, s32 k);

void fn_80073D18(u8* a, u8* b, s16 idx) {
    s32 off = idx * 0x34;
    *(u32*)(a + off) |= 8;
    *(u32*)(b + off) |= 8;
}

void fn_80074394(void* a, s16* b) {
    *b = 0;
    fn_800740D0(a, b);
}

void fn_80074968(void* p, void** out) {
    s16 done = 0;
    s16 cnt;
    fn_80074394(p, &cnt);
    *out = fn_801E1A74(cnt, 0x34);
    fn_800743BC(*out, p, &done);
    while (cnt != done) {
    }
}

/* Sums len from node i back along the chain of preceding nodes whose parent is the next node. */
void fn_800749DC(s16 i, Node *nodes, f32 *out)
{
    Node *cur = &nodes[i];
    Node *prev;

    *out = cur->len;
    while (i != 0) {
        prev = &nodes[i - 1];
        if (prev->parent != cur) {
            return;
        }
        *out += prev->len;
        i--;
        cur = &nodes[i];
    }
}

static inline void walk3(TNode* n, s16* count) {
    (*count)++;
    if (n->child) {
        fn_800740D0(n->child, count);
    }
    if (n->next) {
        fn_800740D0(n->next, count);
    }
}
static inline void walk2(TNode* n, s16* count) {
    (*count)++;
    if (n->child) {
        walk3(n->child, count);
    }
    if (n->next) {
        walk3(n->next, count);
    }
}
static inline void walk1(TNode* n, s16* count) {
    (*count)++;
    if (n->child) {
        walk2(n->child, count);
    }
    if (n->next) {
        walk2(n->next, count);
    }
}
void fn_800740D0(TNode* n, s16* count) {
    (*count)++;
    if (n->child) {
        walk1(n->child, count);
    }
    if (n->next) {
        walk1(n->next, count);
    }
}

void fn_80073D3C(void *a, void *b, s32 c, s32 *d) {
    s16 m = 0;
    s16 n;
    if ((s8)c < 2) {
        fn_80074394(a, &n);
        fn_80061F58(d, n * 4, 0);
    }
    fn_80073DD0(a, b, c, *d, &m);
}

void fn_80073F14(u8 *a, u8 *b, s16 max, void *c, s16 n) {
    void *pc = c;
    u8 *pa;
    u8 *pb;
    s16 cnt;
    s32 i;
    if (n > 0 && n < max) {
        cnt = n;
    } else {
        cnt = max;
    }
    pa = a;
    pb = b;
    for (i = 0; (s16)i < cnt; i++) {
        if (fn_80060F6C(i, pc, 2)) {
            *(u32 *)pb = *(u32 *)pa;
        } else {
            *(u32 *)pb |= 8;
        }
        pa += 0x34;
        pb += 0x34;
    }
}
