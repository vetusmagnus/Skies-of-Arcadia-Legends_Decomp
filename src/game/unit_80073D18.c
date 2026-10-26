#include "types.h"
extern void fn_800740D0(void* a);
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
    fn_800740D0(a);
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
