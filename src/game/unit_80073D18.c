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
