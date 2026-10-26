#include "types.h"
#include "game/task.h"

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

s32 fn_8015F1F0(Obj_8015F1F0* self)
{
    Sub_8015F1F0* sub = self->sub;
    if (sub != 0) {
        return sub->val != 0;
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

void fn_8016F128(Rec_8016F128* r, u8 a, u8 b, f32 v)
{
    r->a = a;
    r->b = b;
    r->f = v;
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
