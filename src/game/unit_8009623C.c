#include "types.h"

typedef struct Sub {
    u8 pad0[0x14];
    s16 flags;
} Sub;
typedef struct Obj_8009623C {
    u8 pad0[0x108];
    Sub *sub;
    u8 pad1[0x12C - 0x10C];
    s16 state;
} Obj_8009623C;
typedef struct Obj_800967F0 {
    u8 pad0[4];
    s16 a4;
    s16 a6;
    u8 pad8[0xDC - 0x8];
    f32 fdc;
    u32 fe0;
    s16 fe4;
} Obj_800967F0;
typedef struct Ctrl {
    u8 b0;
    u8 b1;
    s16 flags;
    f32 f04;
    f32 f08;
    f32 f0C;
    f32 f10;
    f32 f14;
    f32 f18;
    f32 f1C;
    f32 f20;
    f32 f24;
    f32 f28;
    f32 f2C;
    f32 f30;
    u32 p34;
    u32 p38;
    u32 p3C;
    u8 pad40[0x0C];
    f32 f4C;
    f32 f50;
    f32 f54;
    s16 s58;
    s16 s5A;
    f32 f5C;
    s16 s60;
    s16 s62;
    f32 f64;
    s16 s68;
    s16 s6A;
    f32 f6C;
} Ctrl;
extern Ctrl lbl_802E0084;

void fn_8009623C(Obj_8009623C *o)
{
    Sub *s = o->sub;
    if (s != 0) {
        s->flags |= 0x8000;
    }
    o->state = 7;
}

void fn_800967F0(Obj_800967F0 *o, s16 a, s16 b)
{
    o->a4 = a;
    o->a6 = b;
    o->fdc = 0.5f;
    o->fe0 = 0x100;
    o->fe4 = 0x78;
}

void fn_80097094(s16 a, f32 b)
{
    lbl_802E0084.s60 = a;
    lbl_802E0084.flags |= 0x1000;
    lbl_802E0084.f64 = b;
}

void fn_800970B4(s16 a, s16 b, f32 c)
{
    lbl_802E0084.s68 = a;
    lbl_802E0084.flags |= 0x2000;
    lbl_802E0084.s6A = b;
    lbl_802E0084.f6C = c;
}

void fn_800970D8(s16 a, s16 b, f32 c)
{
    lbl_802E0084.s60 = a;
    lbl_802E0084.flags |= 0x1000;
    lbl_802E0084.s62 = b;
    lbl_802E0084.f64 = c;
}

void fn_800970FC(f32 a)
{
    lbl_802E0084.f50 = a;
    lbl_802E0084.flags |= 0x80;
}

void fn_80097118(f32 a)
{
    lbl_802E0084.f4C = a;
    lbl_802E0084.flags |= 0x40;
}

void fn_80097134(s16 a)
{
    lbl_802E0084.s5A = a;
    lbl_802E0084.flags |= 0x400;
}

void fn_80097150(s16 a)
{
    lbl_802E0084.s58 = a;
    lbl_802E0084.flags |= 0x200;
}

void fn_8009716C(s16 a)
{
    lbl_802E0084.s62 = a;
    lbl_802E0084.flags |= 0x1000;
}

void fn_80097188(f32 a, f32 b)
{
    lbl_802E0084.f54 = a;
    lbl_802E0084.flags |= 0x800;
    lbl_802E0084.f5C = b;
}

void fn_800971A8(f32 a)
{
    lbl_802E0084.f5C = a;
    lbl_802E0084.flags |= 0x800;
}

void fn_800971C4(f32 a)
{
    lbl_802E0084.f54 = a;
    lbl_802E0084.flags |= 0x100;
}

void fn_800971E0(u32 a, u32 b, u32 c)
{
    lbl_802E0084.p34 = a;
    lbl_802E0084.flags |= 0x20;
    lbl_802E0084.p38 = b;
    lbl_802E0084.p3C = c;
}

void fn_80097204(f32 a, f32 b, f32 c)
{
    lbl_802E0084.f28 = a;
    lbl_802E0084.flags |= 0x10;
    lbl_802E0084.f2C = b;
    lbl_802E0084.f30 = c;
}

void fn_80097228(f32 a, f32 b, f32 c)
{
    lbl_802E0084.f1C = a;
    lbl_802E0084.flags |= 0x8;
    lbl_802E0084.f20 = b;
    lbl_802E0084.f24 = c;
}

void fn_8009724C(f32 a, f32 b, f32 c)
{
    lbl_802E0084.f10 = a;
    lbl_802E0084.flags |= 0x4;
    lbl_802E0084.f14 = b;
    lbl_802E0084.f18 = c;
}

void fn_80097270(f32 a, f32 b, f32 c)
{
    lbl_802E0084.f04 = a;
    lbl_802E0084.flags |= 0x2;
    lbl_802E0084.f08 = b;
    lbl_802E0084.f0C = c;
}

void fn_80097294(u8 a)
{
    lbl_802E0084.b0 = a;
    lbl_802E0084.flags = 0;
    lbl_802E0084.b1 = 0;
}
