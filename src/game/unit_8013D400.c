#include "types.h"

extern void fn_80136A28(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
extern void fn_8013DA50(s32 a, s32 b);
typedef struct { u8 pad0[1]; s8 kind; } KindObj;
extern s32 lbl_80346F70;
extern s32 lbl_80346F6C;
extern s32 lbl_80346F68;
extern s32 lbl_80346F64;
extern s32 fn_801E4BBC(s32 n);
extern s32 fn_8025ECC4(void);
typedef struct {
    u8 pad0[0x29];
    u8 flag29;
    u8 flag2a;
} FlagObj;
typedef struct {
    u8 pad0;
    s8 idx; /* 0x01 */
} IdxArg;
extern FlagObj* lbl_8034727C;
extern void fn_80100270();
extern void fn_801F7B04(s32 n);
extern char lbl_802E5E68[];
typedef struct {
    u8 pad0[8];
    s32 f8;
} Inner;
typedef struct {
    u8 pad0[0x24];
    Inner* inner; /* 0x24 */
} Outer_8013D400;
extern Outer_8013D400* lbl_803472A0;
extern u8 lbl_8030CEA0[];
extern f32 lbl_803472E0;
extern void* lbl_803472CC;
extern void fn_801E17E0(void* p);
typedef struct {
    u8 pad0[0x7C];
    s32 f7c;
} Sub;
typedef struct {
    u8 pad0[0x23C];
    Sub* sub; /* 0x23C */
} Obj;
extern void fn_8014FA10(void* p);
typedef struct {
    u8 pad0[0x18];
    s32 f18;
    s32 f1c;
    s16 f20;
    u8 pad22[2];
    s16 f24;
    u8 pad26[6];
    s16 f2c;
    s16 f2e;
} Timer;
typedef struct {
    u8 pad0[0x28];
    s8 f28;
    u8 f29;
} Flags;
extern s32 fn_8013E42C(s32 a);
typedef struct { u8 pad0[2]; s8 count; } CountObj;
extern void fn_8013F6E0(void);
extern void SePlay(s32 id, s32 a, s32 b);
extern void fn_80097294(s32 a);
extern s32 lbl_80346F80;
extern s32 lbl_80347290;
extern s32 lbl_803472A8;
extern void* fn_801E1A74(s32 size, s32 align);
extern void* lbl_80346F88;
extern void* memset(void* dst, s32 c, u32 n);

void fn_8013D400(s32 a, s32 b) {
    fn_80136A28(a, b, 3, -1, -1, -1);
}

void fn_8013DB64(void) {
    fn_8013DA50(0, 1);
}

s32 fn_8013DB8C(s32 a, s32 b) {
    s32 n = fn_8013E42C(a);
    s32 idx = b;
    if (b < 0) idx = n - 1;
    if (idx > n - 1) idx = 0;
    return idx;
}

void fn_8013F634(s32 a, s32 b) {
    fn_80136A28(a, b, 0, -1, -1, -1);
}

s32 fn_8013F664(KindObj* o) {
    s32 r = 0;
    s32 k = o->kind;
    if (k == 1) { goto end; }
    if (k >= 1) { goto out; }
    if (k < 0) { goto out; }
    r = 1;
    goto out;
end:
    r = 2;
out:
    return r;
}

void fn_801415C4(CountObj* o) {
    if (o != 0) {
        if (o->count > 0) {
            o->count--;
            fn_8013F6E0();
            SePlay(0xf, 1, 7);
        }
    }
}

void fn_80142F04(s32 a, s32 b) {
    lbl_80346F70 = a;
    lbl_80346F6C = b;
    lbl_80346F68 = a;
    lbl_80346F64 = b;
}

s32 fn_801431A0(void) {
    return fn_801E4BBC(8) != 0;
}

s32 fn_801431D0(void) {
    return fn_801E4BBC(9) != 0;
}

s32 fn_80143274(void) {
    return (fn_8025ECC4() & 1) ^ 1;
}

s32 fn_8014332C(void) {
    return fn_8025ECC4() % 100 == 0;
}

void fn_801463E4(IdxArg* a) {
    if (a->idx == 0) {
        lbl_8034727C->flag29 |= 0x40;
    } else {
        lbl_8034727C->flag2a |= 0x40;
    }
}

void fn_80146418(IdxArg* a) {
    if (a->idx == 0) {
        lbl_8034727C->flag29 |= 0x20;
    } else {
        lbl_8034727C->flag2a |= 0x20;
    }
}

void fn_8014644C(IdxArg* a) {
    if (a->idx == 0) {
        lbl_8034727C->flag29 |= 0x10;
    } else {
        lbl_8034727C->flag2a |= 0x10;
    }
}

void fn_80146480(IdxArg* a) {
    if (a->idx == 0) {
        lbl_8034727C->flag29 |= 0x8;
    } else {
        lbl_8034727C->flag2a |= 0x8;
    }
}

void fn_80147DCC(void) {
    fn_80100270();
    fn_801F7B04(0x10000 - 0x63C0);
}

void fn_80147DF8(void) {
    fn_80100270(lbl_802E5E68);
    fn_801F7B04(0x10000 - 0x63C0);
}

void fn_80148108(void) {
    if (lbl_803472A0 == 0) {
        return;
    }
    lbl_803472A0->inner->f8 = 0;
}

void fn_80148124(void) {
    if (lbl_803472A0 != 0) {
        lbl_803472A0->inner->f8 = 1;
    }
    fn_80097294(0);
}

void fn_80148160(void) {
    *(s32*)(lbl_8030CEA0 + 0x1614) = (s32)lbl_803472E0;
}

void fn_80148DDC(void) {
    if (lbl_803472CC != 0) {
        fn_801E17E0(lbl_803472CC);
    }
}

void fn_80148E08(void) {
    lbl_80346F80 = -1;
    lbl_80347290 = 0;
    lbl_803472CC = fn_801E1A74(0xf00, 4);
    lbl_803472A8 = 0;
}

void fn_801490F4(void) {
    void* p = fn_801E1A74(0x1f4, 4);
    lbl_80346F88 = p;
    memset(p, 0, 0x7d0);
}

void fn_8014ED2C(Obj* o) {
    Sub* s = o->sub;
    s->f7c = 0;
    fn_8014FA10((u8*)s + 0x214);
}

void fn_8014F4E8(Timer* t) {
    s32 n;
    t->f20 = 0;
    t->f18 = 0;
    t->f1c = 0;
    t->f24 = 0;
    t->f2c = 0;
    n = t->f2e;
    if (n != 0) {
        t->f2e = n - 1;
    }
}

void fn_8014F714(Flags* p) {
    if (p->f28 == 0) {
        p->f29 = 1;
    }
}

void fn_8014F72C(void* p, s32 v) {
    memset(p, 0, 0x30);
    *(s16*)((u8*)p + 0x10) = v;
}
