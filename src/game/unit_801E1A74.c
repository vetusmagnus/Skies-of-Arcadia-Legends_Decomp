#include "types.h"
void *fn_801E184C(void *base, s32 idx, s32 a, s32 n);
extern s32 lbl_803476E4;
extern u32 lbl_803476F8;
extern u32 lbl_803476F4;
extern u32 lbl_803476FC;
extern u32 lbl_80347700;
extern u32 lbl_803476E8;
extern u32 lbl_803476EC;
/* A heap block header (unit_801D24D0.c's MemBlk); lbl_802F6748 heads one list of them per heap. */
typedef struct Node {
    void *data;
    u32 pad04[3];
    u32 list;           /* 0x10 */
    struct Node *prev;  /* 0x14 */
    struct Node *next;  /* 0x18 */
} Node;
extern Node *lbl_802F6748[4];
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
    Node* node = lbl_802F6748[0];
    while (node != 0) {
        Node* next = node->next;
        fn_801E15FC(lbl_802F6748, node->data);
        node = next;
    }
    lbl_802F6748[0] = 0;
}

void fn_801E1D94(void) {
    Node* node = lbl_802F6748[0];
    while (node != 0) {
        Node* next = node->next;
        fn_801E15FC(lbl_802F6748, node->data);
        node = next;
    }
    lbl_802F6748[0] = 0;
}

static inline void Link(u32 i, Node *n)
{
    n->list = i;
    if (lbl_802F6748[i] != NULL) {
        lbl_802F6748[i]->prev = n;
    }
    n->prev = NULL;
    n->next = lbl_802F6748[i];
    lbl_802F6748[i] = n;
}

/* Moves the node holding data from whichever list it is on to list `to`. */
void fn_801E1DF8(s32 to, void *data)
{
    Node *prev;
    u32 i;
    Node *n;
    for (i = 0; i < 3; i++) {
        if (to == i) {
            continue;
        }
        for (n = lbl_802F6748[i]; n != NULL; n = n->next) {
            if (n->data == data) {
                if (i == 2) {
                    lbl_80347700++;
                }
                {
                    Node **head = &lbl_802F6748[i];
                    prev = n->prev;
                    if (prev == NULL) {
                        *head = n->next;
                        if (n->next != NULL) {
                            n->next->prev = NULL;
                        }
                    } else {
                        prev->next = n->next;
                    }
                    if (n->next != NULL) {
                        n->next->prev = n->prev;
                    }
                }
                Link(to, n);
                return;
            }
        }
    }
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
    Node **slot;
    Node *n;

    slot = lbl_802F6748 + 1;
    n = *slot;
    while (n != NULL) {
        next = n->next;
        fn_801E15FC(slot, n->data);
        n = next;
    }
    *slot = NULL;
}

void *fn_801E1BDC(u32 n) {
    void *p;
    if (n == 0) n = 0x20;
    p = fn_801E184C(&lbl_802F6748[2], -1, 0, n);
    *(s32 *)((u8 *)p - 0x10) = 2;
    lbl_80347700++;
    return p;
}
