#include "types.h"
void *fn_801E184C(void *base, s32 idx, s32 a, s32 n);
extern u32 lbl_802F6748[4];
extern s32 lbl_803476E4;
extern u32 lbl_803476F8;
extern u32 lbl_803476F4;
extern u32 lbl_803476FC;
extern u32 lbl_80347700;
extern u32 lbl_803476E8;
extern u32 lbl_803476EC;
typedef struct Node {
    void *data;
    u32 pad04[5];
    struct Node *next;
} Node;
void fn_801E15FC(void *slot, void *data);

void fn_801E1A74(s32 a, u32 n) {
    void *p;
    if (n == 0) n = 0x20;
    lbl_803476E4 = 1;
    p = fn_801E184C(lbl_802F6748, -1, a, n);
    *(s32 *)((u8 *)p - 0x10) = 0;
    lbl_803476E4 = 0;
}

void fn_801E1C34(u32 n) {
    void *p;
    if (n == 0) n = 0x20;
    p = fn_801E184C(lbl_802F6748, -1, 0, n);
    *(s32 *)((u8 *)p - 0x10) = 0;
}

void fn_801E1C7C(s32 n) {
    void *p;
    if (n == 0) n = 0x20;
    lbl_803476E4 = 1;
    p = fn_801E184C(lbl_802F6748, -1, 0, n);
    *(s32 *)((u8 *)p - 0x10) = 0;
    lbl_803476E4 = 0;
}

extern void fn_801E15FC(void*, void*);
void fn_801E1D30(void) {
    void* node = *(void**)lbl_802F6748;
    while (node != 0) {
        void* next = *(void**)((u8*)node + 0x18);
        fn_801E15FC(lbl_802F6748, *(void**)node);
        node = next;
    }
    *(void**)lbl_802F6748 = 0;
}

void fn_801E1D94(void) {
    void* node = *(void**)lbl_802F6748;
    while (node != 0) {
        void* next = *(void**)((u8*)node + 0x18);
        fn_801E15FC(lbl_802F6748, *(void**)node);
        node = next;
    }
    *(void**)lbl_802F6748 = 0;
}

void fn_801E1EE4(void)
{
    lbl_802F6748[0] = 0;
    lbl_803476F8 = 0;
    lbl_802F6748[1] = 0;
    lbl_802F6748[2] = 0;
    lbl_803476F4 = 0;
    lbl_803476FC = 0;
}

void fn_801E1F08(void)
{
    lbl_802F6748[0] = 0;
    lbl_803476F8 = 0;
    lbl_802F6748[1] = 0;
    lbl_802F6748[2] = 0;
    lbl_803476F4 = 0;
    lbl_803476FC = 0;
    lbl_80347700 = 0;
    lbl_803476E8 = 0;
    lbl_803476EC = 0;
    lbl_803476E4 = 0;
}

void fn_801E1CCC(void) {
    Node *next;
    u32 *slot;
    Node *n;

    slot = lbl_802F6748 + 1;
    n = *(Node **)slot;
    while (n != NULL) {
        next = n->next;
        fn_801E15FC(slot, n->data);
        n = next;
    }
    *(Node **)slot = NULL;
}

void *fn_801E1BDC(u32 n) {
    void *p;
    if (n == 0) n = 0x20;
    p = fn_801E184C(&lbl_802F6748[2], -1, 0, n);
    *(s32 *)((u8 *)p - 0x10) = 2;
    lbl_80347700++;
    return p;
}
