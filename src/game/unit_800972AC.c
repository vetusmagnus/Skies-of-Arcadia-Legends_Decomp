#include "types.h"

extern s8 lbl_802E0084[];
typedef struct Obj12 {
    u8 pad_00[0x12];
    u16 v12;
} Obj12;
extern s16 lbl_80346C3C;
extern s16 lbl_80302F18[];
extern s16 lbl_80346750;
extern u32 lbl_803473F8;
extern u32 lbl_803473F4;
extern u8 lbl_80303340[];
extern void *lbl_803473F0;
typedef struct Obj10 {
    u8 pad_00[0x10];
    u16 v10;
} Obj10;
typedef struct Pair {
    s32 a;
    s32 b;
} Pair;
typedef struct TblA {
    u32 count;
    u32 items[1];
} TblA;
typedef struct SubA {
    u8 pad_00[0x10];
    TblA *tbl_10;
} SubA;
typedef struct ObjB_800A1ABC {
    u8 pad_000[0x1c8];
    SubA *sub_1c8;
} ObjB_800A1ABC;
typedef struct LeafC {
    u8 pad_00[0x19];
    u8 state_19;
} LeafC;
typedef struct ObjB_800ABE9C {
    u8 pad_000[0x1fb];
    u8 flag_1fb;
    s16 val_1fc;
    u8 pad_1fe[0x25c - 0x1fe];
    LeafC *leaf_25c;
} ObjB_800ABE9C;
typedef struct ObjA_800ABE9C {
    u8 pad_00[0x19];
    u8 state_19;
    u8 pad_1a[0x24 - 0x1a];
    ObjB_800ABE9C *obj_24;
} ObjA_800ABE9C;
typedef struct ObjB_800AC44C {
    u8 pad_000[0x25c];
    LeafC *leaf_25c;
} ObjB_800AC44C;
typedef struct ObjA_800AC44C {
    u8 pad_00[0x19];
    u8 state_19;
    u8 pad_1a[0x24 - 0x1a];
    ObjB_800AC44C *obj_24;
} ObjA_800AC44C;
typedef struct ObjB_800AD300 {
    u8 pad_000[0x1c8];
    SubA *sub_1c8;
    u8 pad_1cc[0x1fc - 0x1cc];
    s16 val_1fc;
} ObjB_800AD300;
typedef struct ObjA_800AD300 {
    u8 pad_00[0x19];
    u8 state_19;
    u8 pad_1a[0x24 - 0x1a];
    ObjB_800AD300 *obj_24;
} ObjA_800AD300;

void fn_800972AC(void)
{
    lbl_802E0084[0] = 0xf;
    *(s16 *)&lbl_802E0084[2] = 0;
}

void fn_800972C4(void)
{
    lbl_802E0084[0] = -1;
    *(s16 *)&lbl_802E0084[2] = 0;
    lbl_802E0084[1] = 0;
}

BOOL fn_80097608(void *unused, Obj12 *p)
{
    return p->v12 == 1;
}

s32 fn_8009761C(s32 a, u16 b)
{
    s32 k = 0x10000;
    return (u16)(a + (k - 0x8000 - b)) - 0x8000;
}

s8 fn_8009763C(void)
{
    s32 r = -1;
    if (lbl_80346C3C == 2) {
        r = lbl_80302F18[0];
    }
    return (s8)r;
}

void fn_80097660(void)
{
    lbl_80346750 = 1;
}

void fn_80097AFC(void)
{
    lbl_803473F8 = 0;
    lbl_803473F4 = 0;
}

void fn_80097CDC(void)
{
    lbl_803473F0 = lbl_80303340;
}

u32 fn_8009C50C(void *unused, Obj10 *p)
{
    return (p->v10 >> 14) & 1;
}

void fn_8009E630(u32 *p)
{
    *p = 0;
}

u32 *fn_800A10A8(u32 *base, u32 i)
{
    u32 *p = base + (2 * i + 1);
    if (p == NULL) {
        return base;
    }
    return (u32 *)*p;
}

s32 fn_800A10C4(Pair *base, s32 i, s32 n)
{
    Pair *p;
    if (i >= n) {
        return 0;
    }
    p = base + i;
    if (p == NULL) {
        return (s32)base;
    }
    return p->a;
}

void *fn_800A1ABC(ObjB_800A1ABC *b, u32 i)
{
    TblA *t = b->sub_1c8->tbl_10;
    if (i >= t->count) {
        return NULL;
    }
    return &t->items[i];
}

void fn_800ABE9C(ObjA_800ABE9C *a)
{
    ObjB_800ABE9C *b = a->obj_24;
    b->flag_1fb = 1;
    a->state_19 = 1;
}

void fn_800AC44C(ObjA_800AC44C *a)
{
    LeafC *l;
    a->state_19 = 1;
    l = a->obj_24->leaf_25c;
    if (l->state_19 != 1) {
        return;
    }
    l->state_19 = 2;
}

void fn_800AD300(ObjA_800AD300 *a)
{
    ObjB_800AD300 *b = a->obj_24;
    s32 v = -1;
    u32 e = b->sub_1c8->tbl_10->items[26];
    if (e != 0) {
        v = e;
    }
    b->val_1fc = v;
    a->state_19 = 1;
}
