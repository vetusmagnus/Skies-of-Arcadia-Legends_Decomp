#include "types.h"
#include "ninja.h"
#include "game/sprite.h"

extern s32 lbl_803473C8;
extern s32 lbl_803473CC;
extern s32 lbl_803473D0;
extern s32 lbl_803473D4;
extern s32 lbl_803473D8;
extern s32 lbl_80346D4C;
extern s32 lbl_80346D5C;
extern void* fn_801DB124(void* a);
extern u8* lbl_80346D70;
extern f32 lbl_802E1118[];
extern s32 lbl_80346D8C;
extern void fn_800CF7BC(void* a, void* b);
extern u8 lbl_80305BA8[];
extern u8 lbl_80310A1C[];
typedef struct Sub2 {
    s32 f0;
    u32 f4;
} Sub2;
typedef struct Sub_800C34C8 {
    u8 pad[0x20];
    Sub2 *f20;
} Sub_800C34C8;
typedef struct Obj_800C34C8 {
    u8 pad0[0x1c8];
    Sub_800C34C8 *f1c8;
} Obj_800C34C8;
typedef struct Sub_800C3518 {
    s32 f0;
    u32 f4;
} Sub_800C3518;
typedef struct Obj_800C3518 {
    u8 pad0[0x100];
    Sub_800C3518 *f100;
} Obj_800C3518;
typedef struct Obj_800CB610 { u8 pad0[0x260]; void *f260; } Obj_800CB610;
typedef struct Src {
    u8 pad0[0x14];
    s16 f14;
    s16 f16;
    s16 f18;
    s16 f1a;
    s16 f1c;
    u16 f1e;
} Src;
typedef struct Obj_800CB68C {
    u8 pad0[0x1e8];
    u8 pad1e8[4];
    s8 b1ec;
    s8 b1ed;
    s8 b1ee;
    s8 b1ef;
    u8 pad1f0[0x1fe - 0x1f0];
    s16 f1fe;
    s16 f200;
    u8 pad202[0x204 - 0x202];
    s16 f204;
    u8 pad206[0x22c - 0x206];
    u16 f22c;
    u8 pad22e[0x264 - 0x22e];
    Src *p264;
} Obj_800CB68C;
typedef struct Fx {
    void *p00;
    u32 w04;
    s16 h08;
    s16 h0a;
    s16 h0c;
    s16 h0e;
} Fx;
extern Fx lbl_80305B08;
extern void fn_801E1784(void *p);
typedef struct Obj_800CF8F8 {
    u8 pad0[0x38];
    f32 f38;
    f32 f3c;
    f32 f40;
    u32 f44;
    s32 f48;
} Obj_800CF8F8;
extern Obj_800CF8F8 *lbl_80347450;
typedef struct FxState {
    s16 mode;
    s16 flag;
    f32 f04;
    f32 f08;
    f32 f0c;
    s32 i10;
    s32 i14;
    s32 i18;
    f32 f1c;
    f32 f20;
    s32 pad24[2];
    s32 i2c;
    s32 i30;
} FxState;
extern FxState lbl_80305B28;
extern f32 lbl_80349408;
void fn_800D249C(s32 a, f32 b, f32 c, f32 d, f32 e);
typedef struct {
    u8 pad00[0x28];
    f32 f28;
    f32 f2c;
    u8 pad30[0x8];
    f32 f38;
    f32 f3c;
    u32 u40;
    u32 u44;
    u32 u48;
} Unk80305B5C;
extern Unk80305B5C lbl_80305B5C;
typedef struct {
    u8 pad00[0x18];
    f32 f18;
    f32 f1c;
    f32 f20;
    f32 f24;
    u8 pad28[0x4];
    u32 u2c;
    u32 u30;
    u32 u34;
    u32 u38;
} Unk80305BE8;
extern Unk80305BE8 lbl_80305BE8;
typedef struct Node {
    u8 pad0[0x48];
    f32 f48;
    u8 pad4c[0x4];
    f32 f50;
    s16 h54;
    s16 h56;
    u8 pad58[0x7c - 0x58];
    struct Node* next;
} Node;
typedef struct {
    u8 pad[0x108];
    Node* list; /* 0x108 */
} Owner;
typedef struct {
    u8 pad[0x268];
    Owner* owner; /* 0x268 */
} Ctx_800B2E84;
extern void fn_801D6944(void*);
extern void fn_801E17E0(void*);
typedef struct {
    u8 pad[0x20];
    NJS_TEXLIST* texlist; /* 0x20 */
} SpriteInner;
typedef struct {
    u8 pad[0x4];
    SpriteInner* inner; /* 0x4 */
} SpriteOuter;
extern void* lbl_80346D30;
extern void* lbl_80346D34;
extern void* lbl_80346D38;
extern SpriteOuter* lbl_80347614;
typedef struct {
    s32 x;
    u32 y;
} Sub;
typedef struct {
    s32 value;      /* 0x00 */
    u8 pad[0x4];
    Sub sub;        /* 0x08 */
} Ent;
typedef struct {
    s32 count;      /* 0x00 */
    Ent* items[1];  /* 0x04 */
} ItemList;
typedef struct {
    u8 pad[0x14];
    ItemList* list; /* 0x14 */
} Ctx_800C355C;
typedef struct {
    f32 x, y, z;
} Vec3;
typedef struct {
    u8 pad0[0xc];
    Vec3 a;         /* 0x0c */
    u8 pad1[0x24 - 0x18];
    Vec3 sum;       /* 0x24 */
} Obj_800C4B18;
extern void fn_80095360(void* p, s32 mode);
extern void fn_8022BAA0(void* a, void* b, void* c, void* d);
extern void fn_801E66E0(void);
extern u32 lbl_80346D48;
typedef struct {
    u8 pad0[0x100];
    void* f100;
} Inner;
typedef struct {
    u8 pad0[0x19];
    u8 state;       /* 0x19 */
    u8 pad1[0x24 - 0x1a];
    Inner* inner;   /* 0x24 */
} Obj_800C6724;
typedef struct {
    u8 pad0[0x19];
    u8 state;       /* 0x19 */
    u8 pad1[0x24 - 0x1a];
    Inner* inner;   /* 0x24 */
} Obj_800C67A8;
typedef struct {
    u8 pad[8];
    u32 flags;      /* 0x08 */
} Ctrl;
extern Ctrl* lbl_80311A60[6];
typedef struct {
    u8 pad0[0x19];
    u8 state;       /* 0x19 */
} Obj_800C682C;
extern void fn_801002D0(const char* name);
extern u8 lbl_802B1448[];
extern Vec3 lbl_8030A2E8;
extern u32 lbl_8030A2DC[3];
extern s32 lbl_803473B8;
extern void* fn_801E1A2C(u32 size, u32 align);

void fn_800B2DA0(u8* p, u32 v) {
    u8* q = *(u8**)(p + 0x268);
    if (q == NULL) {
        return;
    }
    *(u32*)(q + 0x78) = v;
    *(u32*)q |= 0x200;
}

void fn_800C1A34(s32 a, s32 b, s32 c, s32 d) {
    lbl_803473D0 = a;
    lbl_803473D4 = 1;
    lbl_803473CC = b;
    lbl_803473C8 = c;
    lbl_803473D8 = d;
}

s32 fn_800C34C8(Obj_800C34C8 *obj) {
    Sub_800C34C8 *s = obj->f1c8;
    if (s != NULL && s->f20 != NULL && s->f20->f4 != 0) {
        fn_80227810((NJS_TEXLIST*)s->f20);
        return 1;
    }
    return 0;
}

s32 fn_800C3518(Obj_800C3518 *obj) {
    Sub_800C3518 *s = obj->f100;
    if (s != NULL && s->f4 != 0) {
        fn_80227810((NJS_TEXLIST*)s);
        return 1;
    }
    return 0;
}

int fn_800C7DD4(void) {
    if (lbl_80346D5C == 1 || lbl_80346D4C > 0) {
        return 1;
    }
    return 0;
}

void fn_800C81BC(int unused, u8* p) {
    *(void**)(p + 4) = fn_801DB124(*(void**)(p + 4));
}

void fn_800C9060(void) {
    lbl_80346D70[0x19] = 2;
}

s32 fn_800CB610(void *unused, Obj_800CB610 *obj, s16 *data, s16 n) {
    s32 ret = 0;
    s32 v = (((s32)data[0] - 1) * 8 + 12) / 4;
    if (v == n) {
        obj->f260 = data;
        ret = 1;
    } else {
        obj->f260 = NULL;
    }
    return ret;
}

int fn_800CB650(int unused, u8* p, u32 v) {
    p[0x1ed] = 2;
    *(u32*)(p + 0x268) = v;
    return 1;
}

int fn_800CB664(int unused, u8* p, u32 v) {
    p[0x1ed] = 1;
    *(u32*)(p + 0x268) = v;
    return 1;
}

int fn_800CB678(int unused, u8* p, u32 v) {
    p[0x1ed] = 0;
    *(u32*)(p + 0x268) = v;
    return 1;
}

s32 fn_800CB68C(void *unused, Obj_800CB68C *obj, Src *src) {
    obj->p264 = src;
    obj->b1ec = 0;
    obj->f22c = src->f1e;
    obj->f1fe = src->f14;
    obj->f200 = src->f16;
    obj->b1ee = src->f18;
    obj->b1ef = src->f1a;
    obj->f204 = src->f1c;
    return 1;
}

void fn_800CD11C(void) {
    if (lbl_80305B08.p00 != NULL) {
        fn_801E1784(lbl_80305B08.p00);
    }
    lbl_80305B08.p00 = NULL;
    lbl_80305B08.h0e = 0;
    lbl_80305B08.h0c = 0;
    lbl_80305B08.h0a = 0;
    lbl_80305B08.h08 = 0;
}

void fn_800CF8C4(void* p) {
    lbl_80346D8C = 1;
    fn_800CF7BC(lbl_802E1118, p);
}

void fn_800CF8F8(f32 *pos, s32 *val) {
    if (lbl_80347450 == NULL) {
        return;
    }
    if (pos != NULL) {
        lbl_80347450->f38 = pos[0];
        lbl_80347450->f3c = pos[1];
        lbl_80347450->f40 = pos[2];
    }
    if (val != NULL) {
        lbl_80347450->f48 = *val;
    }
}

void fn_800D23A8(s32 a, f32 b, f32 c, s32 n) {
    if (lbl_80349408 > c && n > 1) {
        lbl_80305B28.mode = 2;
        lbl_80305B28.f04 = b;
        lbl_80305B28.f0c = c;
        lbl_80305B28.i10 = a;
        lbl_80305B28.i14 = 0x10000 / n;
    } else {
        lbl_80305B28.mode = 0;
    }
}

void fn_800D2554(f32 x, f32 y) {
    fn_800D249C(1, x, lbl_80305BE8.f1c, y, lbl_80305BE8.f24);
}

void fn_800D258C(s32 n, f32 a, f32 b) {
    f32 f0 = lbl_80305BE8.f18;
    f32 f3 = lbl_80305BE8.f20;
    if (n < 1) {
        return;
    }
    lbl_80305B5C.f28 = f0;
    lbl_80305B5C.f38 = f3;
    lbl_80305B5C.f2c = a;
    lbl_80305B5C.f3c = b;
    lbl_80305B5C.u48 = n;
}

s32 fn_800D2BF0(u32 id) {
    s32 found = 0;
    if (lbl_80305BE8.u38 == id) {
        lbl_80305BE8.u38 = 0;
        found = 1;
        lbl_80305BE8.u30 = 0;
    }
    if (lbl_80305BE8.u34 == id) {
        lbl_80305BE8.u34 = 0;
        found = 1;
        lbl_80305BE8.u2c = 0;
    }
    return found;
}

void fn_800D2C44(u16 v) {
    if (v == 0xffff) {
        return;
    }
    *(u16*)(lbl_80305BA8 + 0x28) = v;
}

void fn_800D2C60(f32 a, f32 b) {
    *(f32*)(lbl_80305BA8 + 0x18) = a;
    *(f32*)(lbl_80305BA8 + 0x20) = b;
}

void fn_800D2C74(u32 v) {
    *(u32*)(lbl_80305BA8 + 0x10) = v;
}

void fn_800D2C84(u8 v) {
    lbl_80305BA8[0x2] = v;
}

void fn_800D2C94(s8 v) {
    *(s16*)(lbl_80305BA8 + 0x4) = v;
}

void fn_800D2CA8(u8 v) {
    lbl_80305BA8[0x1] = v;
}

void fn_800D2CB8(u8 v) {
    lbl_80305BA8[0] = v;
}

void *fn_800D5184(s16 *tbl, s16 idx) {
    void *ret = 0;
    if (tbl != 0 && tbl[1] != 0) {
        s16 n = tbl[0];
        if (idx > n + 1) {
            ret = (u8 *)tbl + ((n + 1) << 2);
        }
    }
    return ret;
}

void *fn_800D51C0(s16 *rec, s16 key) {
    s32 want;
    s16 k;
    if (rec != 0) {
        want = key;
        while ((k = rec[1]) != 0) {
            if (want == k) {
                break;
            }
            rec += (rec[0] + 1) * 2;
        }
        if (key == k) {
            return rec;
        }
        return 0;
    }
    return 0;
}

int fn_800D7B04(void) {
    return (s8)lbl_80310A1C[0x11] != 2;
}

s32 fn_800B2E84(Ctx_800B2E84* ctx, s32 index, s16 value) {
    s32 i = 0;
    Node* node = ctx->owner->list;
    if (node == 0) {
        return 0;
    }
    while (i < index && node != 0) {
        node = node->next;
        i++;
    }
    if (node != 0) {
        node->h54 = value;
        node->h56 = 0;
        node->f48 = 1.0f;
        node->f50 = 1.0f;
        return 1;
    }
    return 0;
}

void fn_800C2EAC(void) {
    if (lbl_80346D34 != 0) {
        fn_801D6944(lbl_80346D34);
    }
    if (lbl_80346D30 != 0) {
        fn_801D6944(lbl_80346D30);
    }
    if (lbl_80347614 != 0) {
        fn_802275A4(lbl_80347614->inner->texlist, 1);
        fn_801E17E0(lbl_80347614);
        lbl_80347614 = 0;
    }
    if (lbl_80346D38 != 0) {
        fn_801E17E0(lbl_80346D38);
        lbl_80346D38 = 0;
    }
}

s32 fn_800C355C(Sub** out, Ctx_800C355C* ctx, s32 idx) {
    ItemList* list;
    s32 value = 0;
    Sub* sub = 0;
    if (idx >= 0) {
        list = ctx->list;
        if (idx <= list->count - 1) {
            Ent* e = list->items[idx];
            if (e != 0) {
                sub = &e->sub;
                value = e->value;
                if (sub != 0 && sub->y == 0) {
                    sub = 0;
                }
            }
        }
    }
    if (out != 0) {
        *out = sub;
    }
    return value;
}

void fn_800C4B18(Obj_800C4B18* self) {
    fn_80095360(&self->a, 0);
    self->sum.x = self->a.x + *(f32*)((u8*)self + 0x30);
    self->sum.y = self->a.y + *(f32*)((u8*)self + 0x34);
    self->sum.z = self->a.z + *(f32*)((u8*)self + 0x38);
    fn_8022BAA0((u8*)self + 0x40, &self->sum, (u8*)self + 0x4c, (u8*)self + 0xa0);
}

void fn_800C6724(Obj_800C6724* self) {
    Inner* inner = self->inner;
    switch (self->state) {
    case 0:
        if (inner->f100 != 0) {
            fn_80227810(inner->f100);
        }
        self->state = 1;
        break;
    case 2:
    case 0xfe:
        break;
    case 1:
        if (lbl_80346D48 == 0) {
            fn_801E66E0();
        }
        break;
    }
}

void fn_800C67A8(Obj_800C67A8* self) {
    Inner* inner = self->inner;
    switch (self->state) {
    case 0:
        if (inner->f100 != 0) {
            fn_80227810(inner->f100);
        }
        self->state = 1;
        break;
    case 2:
    case 0xfe:
        break;
    case 1:
        if (lbl_80346D48 != 0) {
            fn_801E66E0();
        }
        break;
    }
}

void fn_800C682C(Obj_800C682C* self) {
    switch (self->state) {
    case 0:
        lbl_80346D48 = 0;
        self->state = 1;
    case 1:
        if (lbl_80311A60[0]->flags & 0x100) {
            lbl_80346D48 = ~lbl_80346D48;
        }
        break;
    case 2:
    case 0xfe:
        break;
    }
}

void fn_800C8E44(f32 a, f32 b, f32 c) {
    fn_801002D0((const char*)lbl_802B1448);
    lbl_8030A2E8.x = a;
    lbl_8030A2E8.y = b;
    lbl_8030A2E8.z = c;
    lbl_8030A2DC[0] = 0;
    lbl_8030A2DC[1] = 0;
    lbl_8030A2DC[2] = 0;
    lbl_803473B8 = 1;
}

void fn_800CD1F0(s16 n) {
    void* p = fn_801E1A2C((u32)(s32)n * 2, 0x10);
    lbl_80305B08.p00 = p;
    if (p != 0) {
        lbl_80305B08.h08 = n;
        lbl_80305B08.w04 = (u32)((u8*)p + n * 16);
    } else {
        lbl_80305B08.h08 = 0;
    }
    lbl_80305B08.h0a = 0;
    lbl_80305B08.h0c = 0;
    lbl_80305B08.h0e = 0;
}
