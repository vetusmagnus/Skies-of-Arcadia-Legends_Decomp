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
    u8 pad0[0x8];
    f32 f8;
    f32 fc;
    f32 f10;
    u8 pad14[0x4];
    f32 f18;
    f32 f1c;
    f32 f20;
    s32 n24;
    f32 f28;
    f32 f2c;
    f32 f30;
    f32 f34;
    f32 f38;
    f32 f3c;
    f32 f40;
    f32 f44;
    s32 n48;
} Unk80305B5C;
extern Unk80305B5C lbl_80305B5C;
typedef struct Node_UNIT0000 {
    u8 pad0[0x48];
    f32 f48;
    u8 pad4c[0x4];
    f32 f50;
    s16 h54;
    s16 h56;
    u8 pad58[0x7c - 0x58];
    struct Node_UNIT0000* next;
} Node_UNIT0000;
typedef struct {
    u8 pad[0x108];
    Node_UNIT0000* list; /* 0x108 */
} Owner_UNIT0000;
typedef struct {
    u8 pad[0x268];
    Owner_UNIT0000* owner; /* 0x268 */
} Ctx_800B2E84_UNIT0000;
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
} Sub_UNIT0000;
typedef struct {
    s32 value;      /* 0x00 */
    u8 pad[0x4];
    Sub_UNIT0000 sub;        /* 0x08 */
} Ent_UNIT0000;
typedef struct {
    s32 count;      /* 0x00 */
    Ent_UNIT0000* items[1];  /* 0x04 */
} ItemList_UNIT0000;
typedef struct {
    u8 pad[0x14];
    ItemList_UNIT0000* list; /* 0x14 */
} Ctx_800C355C_UNIT0000;
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
} Inner_UNIT0000;
typedef struct {
    u8 pad0[0x19];
    u8 state;       /* 0x19 */
    u8 pad1[0x24 - 0x1a];
    Inner_UNIT0000* inner;   /* 0x24 */
} Obj_800C6724_UNIT0000;
typedef struct {
    u8 pad0[0x19];
    u8 state;       /* 0x19 */
    u8 pad1[0x24 - 0x1a];
    Inner_UNIT0000* inner;   /* 0x24 */
} Obj_800C67A8_UNIT0000;
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
typedef struct Node_800B2DC0 {
    u8 pad0[0x48];
    f32 f48;
    f32 f4c;
    f32 f50;
    s16 h54;
    s16 h56;
    u8 pad58[0x7c - 0x58];
    struct Node_800B2DC0 *next; /* 0x7c */
} Node_800B2DC0;
typedef struct Owner_800B2DC0 {
    u8 pad0[0x108];
    Node_800B2DC0 *list; /* 0x108 */
} Owner_800B2DC0;
typedef struct Ctx_800B2DC0 {
    u8 pad0[0x268];
    Owner_800B2DC0 *owner; /* 0x268 */
} Ctx_800B2DC0;
typedef struct X_800BC02C {
    u8 pad0[0x50];
    u32 w50;
    u32 w54;
    u32 w58;
    u32 w5c;
    u8 pad60[0xe8 - 0x60];
    u32 we8;
} X_800BC02C;
typedef struct Inner_800BC02C {
    u8 pad0[0x10];
    X_800BC02C *p10; /* 0x10 */
} Inner_800BC02C;
typedef struct Self_800BC02C {
    u8 pad0[0x100];
    u32 w100;
    u8 pad104[0x1c8 - 0x104];
    Inner_800BC02C *p1c8; /* 0x1c8 */
} Self_800BC02C;
typedef struct Out {
    u8 pad0[0x7a];
    s16 h7a;
    u32 w7c;
    u32 w80;
    u8 pad84;
    u8 b85;
    u8 b86;
    u8 b87;
    u8 pad88[0x8c - 0x88];
    u32 w8c;
} Out;
extern u32 fn_800A1AE8(void *s, s32 a);
extern u32 fn_800A1ABC(void *s, s32 a);
extern s32 fn_800A10A8(u32 a, u32 b, u32 c);
typedef struct X_800BD904 {
    u8 pad0[0x6c];
    u32 w6c;
} X_800BD904;
typedef struct Inner_800BD904 {
    u8 pad0[0x10];
    X_800BD904 *p10; /* 0x10 */
} Inner_800BD904;
typedef struct Sub_800BD904 {
    u8 pad0[0x50];
    f32 f50;
    f32 f54;
    u8 pad58[0x1c8 - 0x58];
    Inner_800BD904 *p1c8; /* 0x1c8 */
} Sub_800BD904;
typedef struct Actor_800BD904 {
    u8 pad0[0x24];
    Sub_800BD904 *sub; /* 0x24 */
} Actor_800BD904;
typedef struct Rec {
    u32 w0;
    u32 w4;
    u32 w8;
    u32 wc;
    u32 w10;
    u32 w14;
    f32 f18;
    f32 f1c;
    f32 f20;
} Rec;
extern f32 njCos(Angle a);
extern f32 njSin(Angle a);
extern void *fn_801E49D8(const char *s);
extern void *fn_801E4974(void *p, s32 n);
extern u32 fn_801E48A8(void *p);
extern void *fn_801E1C7C(u32 n);
extern void *fn_801E4984(void *p, s32 n);
extern void *fn_801E1584(void *p, u32 n);
extern void *fn_801DB124(void *p);
extern void fn_801D6998(void *p, void *q);
extern char lbl_802B13BC[];
extern void *lbl_80346D40;
extern void *lbl_80346D44;
extern void *lbl_80346D3C;
extern void fn_801DD9AC(void *a, void *b);
extern void fn_801DD95C(void *p);
extern void fn_80100B74(void *self);
extern s32 lbl_803474EC;
typedef struct Node_800C3428 {
    u8 pad0[0x4];
    u32 w4;
} Node_800C3428;
typedef struct Sub_800C3428 {
    u8 pad0[0x100];
    Node_800C3428 *p100; /* 0x100 */
    u8 pad104[0x1ac - 0x104];
    void *p1ac; /* 0x1ac */
    void *p1b0; /* 0x1b0 */
} Sub_800C3428;
typedef struct Self_800C3428 {
    u8 pad0[0x24];
    Sub_800C3428 *sub; /* 0x24 */
} Self_800C3428;
extern void fn_80095360(void *p, s32 a);
extern void fn_80091040(void *a, void *b);
extern s32 fn_80095110(void);
extern void *fn_800912A8(s32 a, void *b, s32 c, s32 d);
extern void fn_801DCEB0(void *a, void *b, f32 c);
typedef struct Obj_800C40EC {
    u8 pad_0[0xc];
    u8 box[0x24 - 0xc];
    f32 f24;
    f32 f28;
    f32 f2c;
    f32 f30;
    f32 f34;
    f32 f38;
    u8 pad3c[0x8];
    void *p44;
    u8 pad48[0x4];
    f32 f4c;
    f32 f50;
    f32 f54;
    u8 pad58[0x1c];
    s32 w74;
    u8 pad78[0x34];
    f32 fac;
    f32 fb0;
    f32 fb4;
    u8 padb8[0x14];
    f32 fcc;
    u8 padd0[0x8];
    s32 wd8;
} Obj_800C40EC;
extern void fn_800967F0(void *self, s32 a, s32 b);
typedef struct Part {
    u8 pad0[0x14];
    s16 h14;
} Part;
typedef struct Other {
    u8 pad0[0x2];
    s16 h2;
} Other;
typedef struct Obj_800C4B90 {
    s16 h0;
    s16 h2;
    u8 pad4[0x8];
    f32 fc;
    f32 f10;
    f32 f14;
    u8 pad18[0x24 - 0x18];
    f32 f24;
    f32 f28;
    f32 f2c;
    f32 f30;
    f32 f34;
    f32 f38;
    u8 pad3c[0x4c - 0x3c];
    f32 f4c;
    f32 f50;
    f32 f54;
    u8 pad58[0x64 - 0x58];
    f32 f64;
    f32 f68;
    f32 f6c;
    u8 pad70[0x108 - 0x70];
    Part *p108;
} Obj_800C4B90;
extern void fn_8022BAA0(void *a, void *b, void *c, void *d);
typedef struct Obj_800C5108 {
    u8 pad_0[0xc];
    u8 box[0x24 - 0xc];
    f32 f24;
    f32 f28;
    f32 f2c;
    f32 f30;
    f32 f34;
    f32 f38;
    u8 pad3c[0x4c - 0x3c];
    f32 f4c;
    f32 f50;
    f32 f54;
    f32 f58;
    f32 f5c;
    f32 f60;
    u8 pad64[0xa0 - 0x64];
    f32 fa0;
    f32 fa4;
    f32 fa8;
    f32 fac;
    f32 fb0;
    f32 fb4;
} Obj_800C5108;
extern void fn_801E7DF0(void *p);
typedef struct Ctl_800C5B58 {
    s16 h0;
    s16 h2;
} Ctl_800C5B58;
typedef struct Obj_800C5B58 {
    u8 pad0[0x188];
    u32 w188;
    u8 pad18c[0x1b0 - 0x18c];
    u32 w1b0;
    u8 pad1b4[0x1e4 - 0x1b4];
} Obj_800C5B58;
extern void fn_800C5D78(void *p);
extern void fn_800C5EE8(void *p);
typedef struct Obj_800C6310 {
    u8 pad0[0x19];
    u8 b19;
    u8 pad1a[0x24 - 0x1a];
    void *p24;
} Obj_800C6310;
void fn_80226AE8();
typedef struct Ent_800C86EC {
    void (*fn)(struct Ent_800C86EC *);
    u8 pad4[0x14];
    u8 flags;
    u8 pad19[7];
    f32 val;
    u8 pad24[0x2C0 - 0x24];
} Ent_800C86EC;
typedef struct Host_800C86EC {
    u8 pad0[0x10];
    struct {
        u32 count;
    } *hdr;
    u8 pad14[4];
    Ent_800C86EC *ents;
} Host_800C86EC;
extern u32 lbl_80305A5C[];
typedef struct {
    s32 unk0;
    s32 map;
    char room;
} MapInfo2;
extern MapInfo2 lbl_80311AC0;
typedef struct {
    u8 pad0[0x24];
    void *tab;
} Mgr_800C8F3C;
extern Mgr_800C8F3C *lbl_80346D70;
void *fn_8015F1A0(s32 id);
void fn_801003F4(void *p);
void fn_801E17E0(void *p);
extern void *lbl_803475A8;
void *fn_802268E8(void *list, void *fn);
void fn_800C9144(void);
typedef struct {
    u8 pad0[0x8];
    u32 key;
    u8 pad1[4];
} Entry;
extern s32 lbl_80346D80;
typedef struct {
    u8 pad0[0x8];
    void *a8;
    u8 padc[0x14];
    void *f20;
    void *f24;
    u8 pad28[4];
} Elem;
typedef struct {
    u8 pad0[0x18];
    Elem elems[1];
} List;
typedef struct {
    u8 pad0[0x1ac];
    s32 f1ac;
    s32 f1b0;
    u8 pad1b4[0x218 - 0x1b4];
    s32 count;
    u8 pad21c[0x25c - 0x21c];
    List *list;
} Self_800D1268;
void fn_801DD9AC(void *a, void *b);
void fn_801DD95C(void *a);
typedef struct {
    u8 pad0[0x34];
    s32 v34;
} Sub_800D2924;
typedef struct {
    u8 pad0[0x184];
    s32 f184;
    u8 pad188[0x1c8 - 0x188];
    Sub_800D2924 *p1c8;
} Self_800D2924;
s32 fn_800D2924(Self_800D2924 *self);
typedef struct {
    u8 pad0[0x34];
    s32 v34;
    u8 rest[0x68 - 0x38];
} Item68;
typedef struct {
    s32 count;
    s32 ids[1];
} IdList;
typedef struct {
    u8 pad0[0xc];
    IdList *list;
} Group;
typedef struct {
    u8 pad0[0x6];
    s16 a6;
    u8 pad8[0x18 - 0x8];
    f32 f18;
    f32 f1c;
    f32 f20;
    f32 f24;
    u8 pad28[0x2a - 0x28];
    u16 u2a;
    u32 u2c;
    Group *grp;
    u32 u34;
    u32 u38;
    s32 w3c;
} Ctl_80305BE8;
extern Ctl_80305BE8 lbl_80305BE8;
typedef struct {
    s32 n0;
    Item68 *items;
} Self_800D2B1C;
void *fn_801005F8(Self_800D2B1C *self, u16 id);
typedef struct {
    u8 pad0[0x1c];
    f32 f1c;
    u8 pad20[0xb4 - 0x20];
    f32 fb4;
    f32 fb8;
    f32 fbc;
    u8 pad_c0[0x184 - 0xc0];
    s32 f184;
} Self_800D3598;
f32 fn_80291A5C(f32 x);

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
    ((u8*)lbl_80346D70)[0x19] = 2;
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
    lbl_80305B5C.n48 = n;
}

s32 fn_800D2BF0(u32 id) {
    s32 found = 0;
    if (lbl_80305BE8.u38 == id) {
        lbl_80305BE8.u38 = 0;
        found = 1;
        lbl_80305BE8.grp = 0;
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

s32 fn_800B2E84(Ctx_800B2E84_UNIT0000* ctx, s32 index, s16 value) {
    s32 i = 0;
    Node_UNIT0000* node = ctx->owner->list;
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

s32 fn_800C355C(Sub_UNIT0000** out, Ctx_800C355C_UNIT0000* ctx, s32 idx) {
    ItemList_UNIT0000* list;
    s32 value = 0;
    Sub_UNIT0000* sub = 0;
    if (idx >= 0) {
        list = ctx->list;
        if (idx <= list->count - 1) {
            Ent_UNIT0000* e = list->items[idx];
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

void fn_800C6724(Obj_800C6724_UNIT0000* self) {
    Inner_UNIT0000* inner = self->inner;
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

void fn_800C67A8(Obj_800C67A8_UNIT0000* self) {
    Inner_UNIT0000* inner = self->inner;
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

s32 fn_800B2DC0(Ctx_800B2DC0 *c, s32 idx, s32 a, s16 b, f32 f)
{
    Node_800B2DC0 *p = c->owner->list;
    s32 i = 0;
    if (p == 0) {
        return 0;
    }
    while (i < idx && p != 0) {
        p = p->next;
        i++;
    }
    if (p != 0) {
        if (a != 0) {
            p->h54 = -a;
            p->h56 = b;
            if (p->f48 > 0.0f) {
                p->f50 = 1.0f - p->f48;
                if (p->f50 < 0.001f) {
                    p->f50 = 0.001f;
                }
            } else {
                p->f50 = 1.0f;
                p->f48 = 0.0f;
            }
        } else {
            p->h54 = b;
            p->h56 = 0;
            p->f48 = 1.0f;
            p->f50 = 1.0f;
        }
        p->f4c = f;
        return 1;
    }
    return 0;
}

void fn_800BC02C(Self_800BC02C *self, Out *out)
{
    X_800BC02C *x = self->p1c8->p10;
    out->w8c = self->w100;
    out->b85 = x->w54;
    out->b86 = x->w58;
    out->b87 = x->w5c;
    if (out->b85 != 0 || out->b86 != 0 || out->b87 != 0) {
        out->w80 = 1;
    } else {
        out->w80 = 0;
    }
    out->h7a = x->we8;
    if (x->w50 == 3) {
        out->w7c = 1;
    } else {
        out->w7c = 0;
    }
}

void fn_800BD904(Actor_800BD904 *a, Rec *r)
{
    Sub_800BD904 *s = a->sub;
    X_800BD904 *x = s->p1c8->p10;
    if (s != 0 && r != 0) {
        if (x->w6c != 0) {
            r->w0 |= 2;
        } else {
            r->w0 &= ~2;
        }
        r->w4 = fn_800A1AE8(s, 0x3b);
        r->w8 = fn_800A1ABC(s, 0x3b);
        r->w14 = 0;
        r->wc = 0;
        r->w10 = fn_800A10A8(r->w8, r->w14, r->w4) + 1;
        r->f1c = s->f50;
        r->f20 = s->f54;
        r->w0 &= ~0x80;
        fn_800BC02C((Self_800BC02C *)s, (Out *)r);
    }
}

void fn_800BE464(NJS_VECTOR *a, NJS_VECTOR *b, Angle ang)
{
    f32 dx = a->x - b->x;
    f32 dz = a->z - b->z;
    f32 s, c, nx, nz;
    f32 zero = 0.0f;
    if (dx != zero || dz != zero) {
        s = njSin(ang);
        c = njCos(ang);
        nx = dx * c - dz * s;
        nz = dx * s + dz * c;
        a->x = nx;
        a->z = nz;
        a->x = a->x + b->x;
        a->z = a->z + b->z;
    }
}

void fn_800C3348(void)
{
    void *a;
    u32 sz;
    void *dst;
    void *b;
    void *src;
    void *obj;

    lbl_80346D40 = fn_801E49D8(lbl_802B13BC);
    b = fn_801E4974(lbl_80346D40, 1);
    sz = fn_801E48A8(lbl_80346D40);
    dst = fn_801E1C7C((u32)b);
    src = fn_801E4984(lbl_80346D40, 1);
    MemCopy(dst, src, (u32)b);
    lbl_80346D40 = fn_801E1584(lbl_80346D40, sz - (u32)b);
    lbl_80346D44 = fn_801DB124(dst);
    obj = lbl_80346D44;
    fn_80227810(*(void **)((u8 *)*(void **)((u8 *)obj + 0x4) + 0x20));
    lbl_80346D3C = fn_801E1C7C(0x14);
    a = fn_801E4984(lbl_80346D40, 0);
    fn_801D6998(lbl_80346D3C, a);
}

void fn_800C3428(Self_800C3428 *self)
{
    Sub_800C3428 *s = self->sub;
    if (s != 0 && s->p100 != 0) {
        if (s->p100->w4 != 0) {
            fn_802275A4((NJS_TEXLIST *)s->p100, 0);
        }
        s->p100 = 0;
    }
    if (s->p1ac != 0) {
        fn_801DD9AC((void *)&lbl_803474EC, s->p1ac);
        s->p1ac = 0;
    }
    if (s->p1b0 != 0) {
        fn_801DD95C(s->p1b0);
        s->p1b0 = 0;
    }
    fn_80100B74(self);
}

void fn_800C40EC(Obj_800C40EC *self)
{
    s32 r;
    fn_80095360(self->box, 0);
    fn_80091040(self->box, &self->fac);
    self->f24 = self->fac + self->f30;
    self->f28 = self->fb0 + self->f34;
    self->f2c = self->fb4 + self->f38;
    r = fn_80095110();
    if (r >= 0) {
        self->w74 = r + self->wd8;
    }
    self->p44 = fn_800912A8(self->w74, self->p44, 0x80, 0x400);
    fn_801DCEB0((u8 *)self + 0x4c, (u8 *)self + 0x40, -self->fcc);
    self->f4c = self->f4c + self->f24;
    self->f50 = self->f50 + self->f28;
    self->f54 = self->f54 + self->f2c;
}

void fn_800C4B90(Obj_800C4B90 *self, Other *other)
{
    if (self->p108 != 0) {
        self->p108->h14 |= 0x8000;
    }
    if ((self->h2 & 4) == 0 && (other->h2 & 4) == 0) {
        f32 c0 = 0.0f;
        f32 c1 = 14.0f;
        self->f38 = c0;
        self->f30 = c0;
        self->f34 = c1;
    }
    self->f24 = self->fc + self->f30;
    self->f28 = self->f10 + self->f34;
    self->f2c = self->f14 + self->f38;
    self->f4c = self->f64;
    self->f50 = self->f68;
    self->f54 = self->f6c;
    fn_800967F0(self, (self->h2 & 1) ? 6 : 4, 6);
}

void fn_800C5108(Obj_800C5108 *self)
{
    fn_80095360(self->box, 0);
    fn_80091040(self->box, &self->fac);
    self->f4c = self->fac + self->f58;
    self->f50 = self->fb0 + self->f5c;
    self->f54 = self->fb4 + self->f60;
    self->f24 = self->fac + self->f30;
    self->f28 = self->fb0 + self->f34;
    self->f2c = self->fb4 + self->f38;
    fn_8022BAA0((u8 *)self + 0x40, &self->f24, &self->f4c, (u8 *)self + 0xa0);
}

void fn_800C5B58(Obj_800C5B58 *self, Ctl_800C5B58 *c)
{
    if (self->w1b0 == 0) {
        if (c->h0 != 0 || c->h2 != 0) {
            s16 a;
            fn_801E7DF0(*(void **)((u8 *)self + 0xe4));
            a = c->h0;
            if (a != 0 && c->h2 != 0) {
                *(s16 *)((u8 *)self + 0x204) = 2;
            } else if (a != 0) {
                *(s16 *)((u8 *)self + 0x204) = 0;
            } else {
                *(s16 *)((u8 *)self + 0x204) = 1;
            }
            *(s16 *)((u8 *)self + 0x206) = c->h0;
            *(s16 *)((u8 *)self + 0x208) = c->h2;
            self->w188 |= 8;
        }
    }
}

void fn_800C6310(Obj_800C6310 *self)
{
    s32 t = self->b19;
    void *sub = self->p24;
    switch (t) {
    case 0:
    case 0xfe:
        fn_800C5EE8(sub);
        self->b19 = 1;
        break;
    case 1:
        if (fn_800D2924(sub) != 0) {
            fn_800C5D78(sub);
        }
        break;
    default:
        fn_800C3428((Self_800C3428 *)self);
        break;
    }
}

s32 fn_800C86EC(Host_800C86EC *h, s32 arg) {
    Ent_800C86EC *e;
    u32 i;
    s32 result = 0;

    e = h->ents;
    for (i = 0; i < h->hdr->count; i++) {
        if (e->fn != 0 && !(e->flags & 0x40)) {
            if (arg != 0 && e->val < 0.0f) {
                fn_80226AE8(e);
            } else {
                e->fn(e);
            }
            if (!(e->flags & 0x40)) {
                result = 1;
            }
        }
        e = (Ent_800C86EC *)((u8 *)e + 0x2C0);
    }
    return result;
}

void fn_800C88E4(void) {
    lbl_80305A5C[0] = 0;
    lbl_80305A5C[1] = 0;
    lbl_80305A5C[2] = 0;
    lbl_80305A5C[3] = 0;
    lbl_80305A5C[4] = 0;
    lbl_80305A5C[5] = 0;
    lbl_80305A5C[6] = 0;
    lbl_80305A5C[7] = 0;
    lbl_80305A5C[8] = 0;
    lbl_80305A5C[9] = 0;
    lbl_80305A5C[10] = 0;
    lbl_80305A5C[11] = 0;
    lbl_80305A5C[12] = 0;
    lbl_80305A5C[13] = 0;
    lbl_80305A5C[14] = 0;
    lbl_80305A5C[15] = 0;
    lbl_80305A5C[16] = 0;
    lbl_80305A5C[17] = 0;
    lbl_80305A5C[18] = 0;
    lbl_80305A5C[19] = 0;
    lbl_80305A5C[20] = 0;
    lbl_80305A5C[21] = 0;
    lbl_80305A5C[22] = 0;
    lbl_80305A5C[23] = 0;
    lbl_80305A5C[24] = 0;
    lbl_80305A5C[25] = 0;
    lbl_80305A5C[26] = 0;
    lbl_80305A5C[27] = 0;
    lbl_80305A5C[28] = 0;
    lbl_80305A5C[29] = 0;
    lbl_80305A5C[30] = 0;
    lbl_80305A5C[31] = 0;
    lbl_80305A5C[32] = 0;
    lbl_80305A5C[33] = 0;
    lbl_80305A5C[34] = 0;
    lbl_80305A5C[35] = 0;
    lbl_80305A5C[36] = 0;
    lbl_80305A5C[37] = 0;
    lbl_80305A5C[38] = 0;
    lbl_80305A5C[39] = 0;
    lbl_80305A5C[40] = 0;
    lbl_80305A5C[41] = 0;
}

s32 fn_800C8D90(void) {
    if (lbl_80311AC0.map == 0x63 ||
        (lbl_80311AC0.map == 0x7a && lbl_80311AC0.room == 'a') ||
        (lbl_80311AC0.map == 0x7d && lbl_80311AC0.room == 'a') ||
        (lbl_80311AC0.map == 0x7d && lbl_80311AC0.room == 'b') ||
        (lbl_80311AC0.map == 0x7d && lbl_80311AC0.room == 'd') ||
        (lbl_80311AC0.map == 0x7f && (lbl_80311AC0.room == 'a' || lbl_80311AC0.room == 'b'))) {
        return 1;
    }
    return 0;
}

void fn_800C8F3C(s32 idx) {
    void *p;
    void *a;

    if (((void**)lbl_80346D70->tab)[idx] != 0) {
        p = fn_8015F1A0(0x752f);
        if (p != 0) {
            a = *(void **)((u8 *)p + 0x1cc);
            a = *(void **)((u8 *)a + 4);
            fn_802275A4(*(void **)((u8 *)a + 0x20), 0);
        }
        fn_801003F4(((void**)lbl_80346D70->tab)[idx]);
        fn_801E17E0(((void**)lbl_80346D70->tab)[idx]);
        ((void**)lbl_80346D70->tab)[idx] = 0;
    }
}

void fn_800C9070(void) {
    s32 i;

    lbl_80346D70 = fn_802268E8(lbl_803475A8, fn_800C9144);
    lbl_80346D70->tab = fn_801E1C7C(0x80);
    for (i = 0; i < 0x80; i += 0x20) {
        *(s32 *)((u8*)lbl_80346D70->tab + i + 0) = 0;
        *(s32 *)((u8*)lbl_80346D70->tab + i + 4) = 0;
        *(s32 *)((u8*)lbl_80346D70->tab + i + 8) = 0;
        *(s32 *)((u8*)lbl_80346D70->tab + i + 0xc) = 0;
        *(s32 *)((u8*)lbl_80346D70->tab + i + 0x10) = 0;
        *(s32 *)((u8*)lbl_80346D70->tab + i + 0x14) = 0;
        *(s32 *)((u8*)lbl_80346D70->tab + i + 0x18) = 0;
        *(s32 *)((u8*)lbl_80346D70->tab + i + 0x1c) = 0;
    }
}

void *fn_800CCAE4(s32 (*cb)(void *, void *), void *arg, u32 best) {
    Entry *e;
    void *result = 0;

    if (cb != 0 && arg != 0) {
        lbl_80346D80 = 0;
        e = (Entry*)lbl_80305B08.p00;
        while (lbl_80346D80 < lbl_80305B08.h0a) {
            if (cb(e, arg) != 0) {
                u32 k = (u16)e->key;
                if (k <= best) {
                    result = e;
                    best = k;
                }
            }
            lbl_80346D80++;
            e++;
        }
    }
    return result;
}

void *fn_800CCB94(s32 (*cb)(void *, void *), void *arg) {
    Entry *e;
    void *result = 0;
    u32 best = 0xFFFF;

    if (cb != 0 && arg != 0) {
        lbl_80346D80 = 0;
        e = (Entry*)lbl_80305B08.p00;
        while (lbl_80346D80 < lbl_80305B08.h0a) {
            if (cb(e, arg) != 0) {
                u32 k = (u16)e->key;
                if (k <= best) {
                    result = e;
                    best = k;
                }
            }
            lbl_80346D80++;
            e++;
        }
    }
    return result;
}

void fn_800D1268(Self_800D1268 *self) {
    s32 n;
    List *list;
    Elem *el;

    n = self->count;
    if (n > 0) {
        list = self->list;
        if (list != 0) {
            el = list->elems;
            do {
                if (el->f20 != 0) {
                    fn_801DD9AC(&lbl_803474EC, el->f20);
                }
                if (el->f24 != 0) {
                    fn_801DD95C(el->f24);
                }
                if (el->a8 != 0) {
                    fn_802275A4(el->a8, 0);
                }
                n--;
                el++;
            } while (n > 0);
            fn_801E17E0(list);
            self->list = 0;
        }
    }
    self->f1ac = 0;
    self->f1b0 = 0;
}

void fn_800D249C(s32 n, f32 a, f32 b, f32 c, f32 d) {
    if (n < 1) {
        return;
    }
    if (1.0f < a) {
        a = 1.0f;
    } else if (0.0f > a) {
        a = 0.0f;
    }
    if (1.0f < b) {
        b = 1.0f;
    } else if (0.0f > b) {
        b = 0.0f;
    }
    if (1.0f < c) {
        c = 1.0f;
    } else if (0.0f > c) {
        c = 0.0f;
    }
    if (1.0f < d) {
        d = 1.0f;
    } else if (0.0f > d) {
        d = 0.0f;
    }
    lbl_80305B5C.f30 = b;
    lbl_80305B5C.f40 = d;
    lbl_80305B5C.f34 = a;
    lbl_80305B5C.f44 = c;
    lbl_80305B5C.n48 = n;
}

void fn_800D25C4(u32 rgb, s32 n) {
    u32 w = *(u32 *)((u8*)&lbl_80305BE8 + 0x10);

    if (n >= 1) {
        u32 w0 = w & 0xFF;
        u32 w1 = (w >> 8) & 0xFF;
        u32 w2 = (w >> 16) & 0xFF;
        u32 c0 = rgb & 0xFF;
        u32 c1 = (rgb >> 8) & 0xFF;
        u32 c2 = (rgb >> 16) & 0xFF;

        lbl_80305B5C.f10 = (f32)w0;
        lbl_80305B5C.fc = (f32)w1;
        lbl_80305B5C.f8 = (f32)w2;
        lbl_80305B5C.f20 = (f32)c0;
        lbl_80305B5C.f1c = (f32)c1;
        lbl_80305B5C.f18 = (f32)c2;
        lbl_80305B5C.n24 = n;
    }
}

s32 fn_800D2924(Self_800D2924 *self) {
    s32 ret;

    if (lbl_80305BE8.a6 == 0) {
        self->f184 = 0;
        ret = 1;
    } else if (lbl_80305BE8.u2a == 0xFFFF) {
        self->f184 = 1;
        ret = 0;
    } else if (self->p1c8 != 0) {
        if (lbl_80305BE8.w3c == self->p1c8->v34) {
            self->f184 = 0;
            ret = 1;
        } else {
            self->f184 = 1;
            ret = 0;
        }
    } else {
        self->f184 = 0;
        ret = 1;
    }
    return ret;
}

void fn_800D2B1C(Self_800D2B1C *self) {
    s32 n = self->n0;
    Ctl_80305BE8 *ctl = &lbl_80305BE8;
    s32 val = ctl->w3c - 1;
    Item68 *p;
    IdList *list;
    s32 *ids;
    s32 cnt;
    Item68 *hit;
    s32 w;
    s32 w29;

    if (n > 0) {
        p = self->items;
        do {
            p->v34 = val;
            p++;
            n--;
        } while (n > 0);
    }

    if (lbl_80305BE8.grp != 0) {
        list = lbl_80305BE8.grp->list;
        w29 = lbl_80305BE8.w3c;
        if (list != 0) {
            cnt = list->count;
            if (cnt > 0) {
                ids = list->ids;
                do {
                    w = *ids;
                    if (w < 0) {
                        hit = fn_801005F8(self, (u16)w);
                        if (hit != 0) {
                            hit->v34 = w29;
                        }
                    }
                    cnt--;
                    ids++;
                } while (cnt > 0);
            }
        }
    }
}

s32 fn_800D3598(Self_800D3598 *self) {
    s32 r = self->f184;

    if (r == 0) {
        Obj_800CF8F8 *t = lbl_80347450;

        if (t != 0) {
            f32 dy = self->fb4 - t->f38;
            f32 dx = self->fb8 - t->f3c;
            f32 dz = self->fbc - t->f40;
            f32 d = dy * dy + dx * dx + dz * dz;

            if (12250000.0f < d) {
                self->f1c = -1.0f;
                r = 1;
            } else if (9000000.0f >= d) {
                self->f1c = 0.0f;
            } else {
                self->f1c = -(fn_80291A5C(d) - 3000.0f) / 500.0f;
            }
        }
    }
    return r;
}
