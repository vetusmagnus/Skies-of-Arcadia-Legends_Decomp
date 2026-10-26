#include "types.h"
#include "string.h"
#include <math.h>

typedef struct Obj12 {
    u8 pad_00[0x12];
    u16 v12;
} Obj12;
extern s16 lbl_80346C3C;
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
typedef struct {
    s8 mode;
    u8 flags;
    s16 field2;
    u8 pad_04[0x70 - 4];
} SeFlagBlock;
extern SeFlagBlock lbl_802E0084;
extern s16 lbl_80302F18[408];
extern void fn_800D2CA8(s32 x);
extern void fn_80097B0C(void *p);
typedef struct {
    s16 flag;
    s16 count;
} Entry8009B58C;
typedef struct {
    u8 pad_000[0x188];
    u32 flags188;
    u8 pad_18c[0x260 - 0x18C];
    Entry8009B58C *entry260;
} Obj8009B58C;
typedef struct {
    s16 flag;
    s16 count;
} Entry8009B5D4;
typedef struct {
    u8 pad_000[0x188];
    u32 flags188;
    u8 pad_18c[0x264 - 0x18C];
    Entry8009B5D4 *entry264;
} Obj8009B5D4;
typedef struct {
    u8 pad_00[0x1c];
    s32 *table;
} Sub8009D67C;
typedef struct {
    u8 pad_000[0xec];
    u32 field_ec;
    u8 pad_0f0[0x1c8 - 0xf0];
    Sub8009D67C *sub;
} Obj8009D67C;
typedef struct {
    u8 pad_00[0x44];
    u32 x44;
    u32 x48;
} Inner8009DC58;
typedef struct {
    u8 pad_00[0x10];
    Inner8009DC58 *p10;
} Sub8009DC58;
typedef struct {
    u8 pad_000[0x1c8];
    Sub8009DC58 *sub;
    u8 pad_1cc[0x23a - 0x1cc];
    u16 flags23a;
} Obj8009DC58;
typedef struct Item {
    u8 pad[0x19];
    u8 type;
} Item;
typedef struct ItemList_8009E530 {
    Item **items;
} ItemList_8009E530;
typedef struct ItemList_8009E804 {
    void **items;
    s32 count;
} ItemList_8009E804;
extern u32 lbl_80311970[];
typedef struct Sub2 {
    u8 pad[4];
    u32 f4;
} Sub2;
typedef struct Sub {
    u8 pad[0x20];
    Sub2 *f20;
} Sub;
typedef struct Obj {
    u8 pad0[0x100];
    s32 f100;
    u8 pad1[0x1c8 - 0x104];
    Sub *f1c8;
} Obj;
typedef struct State {
    s32 w00;
    s32 w04;
    s32 w08;
    s32 w0c;
    f32 f10;
    f32 f14;
    f32 f18;
    s32 w1c;
    s32 w20;
    s32 w24;
    f32 f28;
    s32 w2c;
} State;
extern State lbl_80303468;
extern s32 lbl_80346CF0;
extern Item *fn_8010A164(u16 id);
extern void fn_800A39E0(void);
extern void fn_800B0900(void);
extern u8 lbl_80303618[];
extern u8 lbl_80303634[];
extern u32 lbl_80346C40;
extern void* lbl_80347588;
void* fn_802267AC(void* a, void* b);
void fn_80096DA4(void);
typedef struct {
    void** slots;
    s32 count;
} Pool;
extern char lbl_802B0F0C[];
void* fn_801E1A2C(s32 a, u32 size);
void fn_801DBE1C(char* msg, ...);
void fn_8009DCA8(u8* o, u8* p);

void fn_800972AC(void)
{
    lbl_802E0084.mode = 0xf;
    lbl_802E0084.field2 = 0;
}

void fn_800972C4(void)
{
    lbl_802E0084.mode = -1;
    lbl_802E0084.field2 = 0;
    lbl_802E0084.flags = 0;
}

void fn_800972E0(s8 x) {
    if (x == 0) {
        lbl_802E0084.flags |= 0x2;
    } else {
        lbl_802E0084.flags &= ~0x2;
    }
}

void fn_80097318(s8 x) {
    if (x != 0) {
        lbl_802E0084.flags |= 0x1;
    } else {
        lbl_802E0084.flags &= ~0x1;
    }
}

void fn_80097350(s32 x) {
    if (x == 0) {
        lbl_80302F18[1] |= 0x8;
    } else {
        lbl_80302F18[1] &= ~0x8;
    }
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

void fn_80097CA4(void *p) {
    fn_800D2CA8(0);
    fn_80097B0C(p);
}

void fn_80097CDC(void)
{
    lbl_803473F0 = lbl_80303340;
}

s32 fn_8009B58C(s32 unused, Obj8009B58C *obj, Entry8009B58C *e, s16 arg) {
    s32 ret = 0;
    s32 v = ((e->count - 1) * 8 + 16) / 4;
    if (v == arg) {
        obj->flags188 |= e->flag & 0x10000;
        obj->entry260 = e;
        ret = 1;
    }
    return ret;
}

s32 fn_8009B5D4(s32 unused, Obj8009B5D4 *obj, Entry8009B5D4 *e, s16 arg) {
    s32 ret = 0;
    s32 v = ((e->count - 1) * 8 + 16) / 4;
    if (v == arg) {
        obj->flags188 |= e->flag & 0x10000;
        obj->entry264 = e;
        ret = 1;
    }
    return ret;
}

u32 fn_8009C50C(void *unused, Obj10 *p)
{
    return (p->v10 >> 14) & 1;
}

void fn_8009D67C(Obj8009D67C *o, s32 idx) {
    s32 *t;
    u32 v;
    t = o->sub->table;
    if (t[0] > idx) {
        v = t[idx + 1];
    } else {
        v = 0;
    }
    if (v != 0) {
        o->field_ec = v;
    } else {
        o->field_ec = 0;
    }
}

void fn_8009DC58(Obj8009DC58 *o) {
    Inner8009DC58 *p = o->sub->p10;
    u32 *q;

    o->flags23a = 0;
    if (p->x44 != 0) {
        o->flags23a |= 1;
        q = &p->x48;
    } else {
        q = &p->x48;
    }
    if (*q == 0) {
        return;
    }
    o->flags23a |= 4;
}

f32 fn_8009E4F8(u8 v) {
    return (s32)(v - 255) * 0.003921569f;
}

Item *fn_8009E530(ItemList_8009E530 *list, s32 count) {
    s32 i;
    Item **items;
    if (list == NULL) {
        return NULL;
    }
    items = list->items;
    for (i = 0; i < count; i++) {
        Item *it = items[i];
        if (it != NULL && it->type == 3) {
            return it;
        }
    }
    return NULL;
}

void fn_8009E630(u32 *p)
{
    *p = 0;
}

void fn_8009E804(ItemList_8009E804 *list, s32 idx) {
    if (idx < 0) {
        return;
    }
    if (list == NULL) {
        return;
    }
    if (list->items[idx] == NULL) {
        return;
    }
    list->items[idx] = NULL;
    list->count--;
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

void fn_800A1948(void *unused, u32 *dst, u8 flags) {
    if (flags & 1) {
        dst[0] = lbl_80311970[7];
    }
    if (flags & 2) {
        dst[1] = lbl_80311970[8];
    }
    if (flags & 4) {
        dst[2] = lbl_80311970[13];
    }
}

void *fn_800A1ABC(ObjB_800A1ABC *b, u32 i)
{
    TblA *t = b->sub_1c8->tbl_10;
    if (i >= t->count) {
        return NULL;
    }
    return &t->items[i];
}

s32 fn_800A1B50(Obj *obj) {
    s32 r0 = 0;
    if (obj != NULL) {
        s32 useSub = 0;
        Sub *s = obj->f1c8;
        if (s != NULL && s->f20 != NULL && s->f20->f4 != 0) {
            useSub = 1;
        }
        if (useSub != 0) {
            r0 = (s32)s->f20;
        } else {
            r0 = obj->f100;
        }
    }
    return r0;
}

void fn_800A363C(void) {
    lbl_80303468.w00 = 0;
    lbl_80303468.w04 = 0;
    lbl_80303468.w0c = 0;
    lbl_80303468.w08 = 0;
    lbl_80303468.f18 = 0.0f;
    lbl_80303468.f14 = 0.0f;
    lbl_80303468.f10 = 0.0f;
    lbl_80303468.w24 = 0;
    lbl_80303468.w20 = 0;
    lbl_80303468.w1c = 0;
    lbl_80303468.w2c = 0;
    lbl_80303468.f28 = 0.0f;
    lbl_80346CF0 = 0;
}

s32 fn_800A3E90(u32 id) {
    Item *it = fn_8010A164((u16)id);
    if (it == NULL) {
        return 0;
    }
    it->type = 4;
    fn_800A39E0();
    return 1;
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

void fn_800B0F0C(void) {
    fn_800B0900();
    memset(lbl_80303618, 0, 0x1c);
    memset(lbl_80303634, 0, 0x1c);
}

s32 fn_8009766C(void) {
    s32 r;
    void* obj;
    if (lbl_80346750 == 0) return 0;
    lbl_80346C40 = 0;
    r = 0;
    obj = fn_802267AC(lbl_80347588, (void*)fn_80096DA4);
    if (obj) {
        *(u8**)((u8*)obj + 0x24) = (u8*)lbl_80302F18;
        *(u32*)((u8*)lbl_80302F18 + 0x108) = 0;
        *(u32*)((u8*)lbl_80302F18 + 0x128) = 0;
        lbl_80346750 = 0;
        r = 1;
    }
    return r;
}

s32 fn_8009E840(Pool* pool, u8* item, s32 n) {
    s32 i = 0;
    s32 idx = -1;
    void** s;
    if (pool == 0) return -1;
    s = pool->slots;
    for (; i < n; i++) {
        if (*s == 0) {
            *s = item;
            idx = i;
            pool->count++;
            break;
        }
        s++;
    }
    if (idx == -1) item[0x19] = 0xff;
    return idx;
}

void* fn_8009E8B0(s32 n) {
    u8* p;
    if (n > 0) {
        p = fn_801E1A2C(1, n * 4 + 8);
        if (p == 0) fn_801DBE1C(lbl_802B0F0C);
        *(u8**)p = p + 8;
    }
    return p;
}

u32 fn_800A1AE8(u8* o, u32 idx) {
    u32 cnt = 0;
    u32* p = *(u32**)(*(u8**)(o + 0x1c8) + 0x10);
    u32 n = p[0];
    s32 found = 0;
    u32 i = idx;
    p += 1;
    if (idx >= n) return 0;
    p += idx;
    while (i < n && !found) {
        if (p[1] == 0) {
            found = 1;
        } else {
            cnt++;
            p += 2;
            i += 2;
        }
    }
    return cnt;
}

void fn_800ADF98(u8* o) {
    u8* a = *(u8**)(o + 0x1c8);
    u8* t = *(u8**)(a + 0x10);
    s32 v = *(s32*)(t + 0x44);
    if ((s32)fabsf((f32)v) == 1) {
        fn_8009DCA8(o, t + 0x24);
    }
}
