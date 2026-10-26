#include "types.h"
#include "game/task.h"
#include "game/menu.h"

typedef struct {
    u32 flags;
    u8 pad[0x19C - 4];
    f32 val;
} Sub_8015DC6C;
typedef struct {
    u8 pad[0x1D8];
    Sub_8015DC6C* sub;
} Obj_8015DC6C;
typedef struct {
    u8 pad[0x1C];
    f32 val;
} Src;
typedef struct {
    u8 pad[0x8];
    void* next;
} Sub_8015F180;
typedef struct {
    u8 pad[0x1D8];
    Sub_8015F180* sub;
} Obj_8015F180;
typedef struct {
    u8 pad[0x8];
    s32 val;
} Sub_8015F1F0;
typedef struct {
    u8 pad[0x1D8];
    Sub_8015F1F0* sub;
} Obj_8015F1F0;
void fn_8016D01C(void);
void fn_8016C4B0(void);
void fn_8016B620(void);
void fn_8016AD08(void);
typedef struct {
    s8 mode;
    u8 pad0[0x1F];
    f32 f20;
    u8 pad1[0xC];
    f32 f30;
} InnerA;
typedef struct {
    u8 pad[0x24];
    InnerA* inner;
} OwnerA;
extern OwnerA* lbl_803470A0;
extern f32 lbl_8034ABDC;
typedef struct {
    u8 pad0[0x20];
    u32 w20;
    u32 w24;
    u8 pad1[0x10];
    u32 w38;
    u32 w3c;
} InnerB;
typedef struct {
    u8 pad[0x24];
    InnerB* inner;
} OwnerB;
extern OwnerB* lbl_803470B0;
typedef struct {
    u8 a;
    u8 b;
    u8 pad[2];
    f32 f;
} Rec_8016F128;
typedef struct {
    u8 a;
    u8 b;
    u8 c;
    u8 pad;
    f32 f;
    void* entry;
} Rec_80186E20;
extern u8 lbl_803072E8[];
s32 fn_801F4CA0(s32 x);
typedef struct {
    u32 f0;
    u32 f4;
    u32 f8;
} Trio;
void fn_8019A15C(void* p, s32 a, s32 b, s32 c);
typedef struct {
    s32 v;
    u8 b;
} Rec_8018E81C;
extern void* lbl_80347114;
extern void *lbl_80347450;
typedef struct Rec { u8 pad[0x24]; void *x24; } Rec;
Rec *fn_8010A164(u16 idx);
typedef struct Sub_8015F768 { u8 pad[0x178]; s32 x178; } Sub_8015F768;
typedef struct Obj_8015F768 { u8 pad[0x1d8]; Sub_8015F768 *x1d8; } Obj_8015F768;
typedef struct Obj_8015FB98 { u8 pad[0xec]; u32 xec; u32 xf0; u32 xf4; } Obj_8015FB98;
u32 fn_8008F8FC(void *a, void *b);
typedef struct Sub_8016645C { u8 pad[0x1a]; s16 x1a; } Sub_8016645C;
typedef struct Obj_8016645C { u8 pad[0x1d8]; Sub_8016645C *x1d8; } Obj_8016645C;
typedef struct Arg { u8 pad[0x1c]; u32 x1c; u32 x20; } Arg;
extern u8 lbl_80310B3C[];
void fn_8016DBAC(void *out, void *p);
extern u8 lbl_8030B7F4[];
typedef struct Out {
    f32 f0;
    u8 pad4;
    s8 idx;
    u8 pad6[2];
    u8 *rec;
    u8 b0c;
    u8 pad_d[3];
    s32 i10;
    s32 i14;
    s32 i18;
    s32 i1c;
} Out;
extern u8 lbl_80307638[];
void fn_80195EA4(void *out, s32 a, s32 b, s32 c, s32 d);
extern s32 lbl_80308088[];

s32 fn_8015DC6C(Obj_8015DC6C* self, Src* src)
{
    Sub_8015DC6C* sub = self->sub;
    sub->flags |= 0x80;
    sub->val = src->val;
    return 0;
}

void* fn_8015F180(Obj_8015F180* self)
{
    Sub_8015F180* sub = self->sub;
    if (sub == 0) {
        return self;
    }
    if (sub->next == 0) {
        return self;
    }
    return sub->next;
}

void *fn_8015F1A0(u32 idx) {
    Rec *r;
    if ((u16)idx == 0xFFFF) return lbl_80347450;
    r = fn_8010A164((u16)idx);
    if (r && r->x24) return r->x24;
    return 0;
}

s32 fn_8015F1F0(Obj_8015F1F0* self)
{
    Sub_8015F1F0* sub = self->sub;
    if (sub != 0) {
        return sub->val != 0;
    }
    return 0;
}

s32 fn_8015F298(u32 *a, u32 *b) {
    if (a[0] == b[0] && a[0] == 7 && a[1] == b[1] &&
        (a[2] & 0xFFFF0000) == (b[2] & 0xFFFF0000)) {
        return 1;
    }
    return 0;
}

s32 fn_8015F768(Obj_8015F768 *o) {
    Sub_8015F768 *s = o->x1d8;
    s32 r;
    if (s == 0) return 0;
    r = 0;
    if (s->x178 == 1 || s->x178 == 3) r = 1;
    return r != 0;
}

void fn_8015FB98(void *a, Obj_8015FB98 *b) {
    u32 v = fn_8008F8FC(b, a);
    if (v != b->xec) {
        b->xf4 = b->xec;
        b->xec = v;
    }
}

s32 fn_8016645C(Obj_8016645C *o, Arg *a) {
    Sub_8016645C *s = o->x1d8;
    if (s && a && a->x20 && a->x1c && a->x1c > (u32)(s32)s->x1a) {
        return 1;
    }
    return 0;
}

void fn_8016ABEC(void)
{
    fn_8016D01C();
    fn_8016C4B0();
    fn_8016B620();
    fn_8016AD08();
}

void fn_8016B950(f32 a, f32 b)
{
    OwnerA* o = lbl_803470A0;
    InnerA* in;
    if (o == 0) {
        return;
    }
    in = o->inner;
    in->f30 = a;
    in->f20 = b;
}

void fn_8016B96C(f32 v)
{
    OwnerA* o = lbl_803470A0;
    InnerA* in;
    if (o == 0) {
        return;
    }
    in = o->inner;
    if (in->mode == 3) {
        v -= lbl_8034ABDC;
    }
    in->f20 = v;
}

void fn_8016C780(u32 a, u32 b)
{
    OwnerB* o = lbl_803470B0;
    if (o != 0) {
        o->inner->w3c = a;
    }
    o = lbl_803470B0;
    if (o == 0) {
        return;
    }
    o->inner->w38 = b;
}

void fn_8016C7AC(u32 a, u32 b)
{
    OwnerB* o = lbl_803470B0;
    if (o != 0) {
        o->inner->w24 = a;
    }
    o = lbl_803470B0;
    if (o == 0) {
        return;
    }
    o->inner->w20 = b;
}

void fn_8016C7D8(u32 a)
{
    OwnerB* o = lbl_803470B0;
    if (o == 0) {
        return;
    }
    o->inner->w38 = a;
}

void fn_8016C7F0(u32 a)
{
    OwnerB* o = lbl_803470B0;
    if (o == 0) {
        return;
    }
    o->inner->w20 = a;
}

s32 fn_8016E1D8(void *p) {
    u32 tmp[2];
    if (!(*(u32 *)(lbl_80310B3C + 0x88) & 4)) return 0;
    fn_8016DBAC(tmp, p);
    return 1;
}

void fn_8016F0D4(Out *o, s8 idx, f32 f) {
    u8 *r;
    o->f0 = f;
    o->idx = idx;
    r = lbl_8030B7F4 + (s32)idx * 0x5c;
    o->rec = r;
    o->b0c = r[0xb];
    o->i10 = *(s16 *)(r + 0x18);
    o->i14 = *(s16 *)(r + 0x1a);
    o->i18 = (s8)r[0xd];
    o->i1c = (s8)r[0xe];
}

void fn_8016F128(Rec_8016F128* r, u8 a, u8 b, f32 v)
{
    r->a = a;
    r->b = b;
    r->f = v;
}

s32 fn_8018126C(void) {
    s32 buf[0x20];
    s32 off = *(s32 *)(lbl_80307638 + 0x7c);
    s8 v = (s8)lbl_8030B7F4[off + 0x328];
    fn_80195EA4(buf, v, 0, 0, 2);
    return buf[3];
}

void fn_80186E20(Rec_80186E20* r, u8 c, s8 b, u8 a, f32 v)
{
    r->a = a;
    r->b = b;
    r->c = c;
    r->f = v;
    r->entry = lbl_803072E8 + b * 0x2C;
}

s8 fn_80187F90(s32 x)
{
    return fn_801F4CA0(x);
}

void fn_80189DB0(s32* p, s8 v)
{
    *p = v;
}

void fn_8018DFAC(Trio* t, u32 v)
{
    t->f8 = v;
}

void fn_8018DFB4(Trio* t, u32 v)
{
    t->f0 = v;
}

void fn_8018DFBC(Trio* t, u32 v)
{
    t->f4 = v;
}

void fn_8018E7F0(void* p)
{
    fn_8019A15C(p, 0, 0, 0);
}

void fn_8018E81C(Rec_8018E81C* r, s8 v, u8 b)
{
    r->v = v;
    r->b = b;
}

void fn_80192800(void)
{
    TaskDelete(lbl_80347114);
    lbl_80347114 = 0;
}

s32 fn_801929B8(s32 idx) {
    lbl_80308088[idx] = MenuPlaySe((s16)idx);
    return lbl_80308088[idx];
}
