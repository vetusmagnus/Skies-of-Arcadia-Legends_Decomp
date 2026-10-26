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
    u8 pad0;
    s8 idx; /* 0x01 */
} IdxArg;
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
} Sub_UNIT0000;
typedef struct {
    u8 pad0[0x23C];
    Sub_UNIT0000* sub; /* 0x23C */
} Obj_UNIT0000;
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
typedef struct Slot {
    u32 flags;
    u32 x4;
    u32 x8;
    u32 xc;
    u8 pad[0x24 - 0x10];
} Slot;
extern Slot lbl_8030A6D4[];
extern s32 lbl_8034757C;
extern s32 fn_8013E730(s32 i);
extern u8 lbl_80306738[];
extern u8 lbl_80346F61;
extern u8 lbl_80346F60;
/* Shared view of lbl_8034727C (stride 0x3E per element). x20/x24 hold Sub* values (fn_80146FD4). */
typedef struct Ent {
    u8 pad[0x20];
    u8 x20[4];
    u8 x24[4];
    u8 pad28;
    u8 flag29;
    u8 flag2a;
    u8 pad2b;
    s16 x2c;
    u8 rest[0x10];
} Ent;
extern Ent* lbl_8034727C;
extern void fn_8014549C(s32 a, s32 b);
typedef struct Obj24 { u8 pad[0x24]; s16 x24; } Obj24;
typedef struct Obj7 { u8 pad[7]; u8 x7; } Obj7;
typedef struct Sub_80146FD4 { u8 pad[0x14]; s32 x14; s32 x18; } Sub_80146FD4;
typedef struct Req { s8 x0; s8 x1; } Req;
typedef struct MapInfo { s32 map; s32 unk4; char room; } MapInfo;
extern void fn_800FF908(void);
extern void fn_801002D0(s32 a);
extern int fn_8025CB24(char* buf, const char* fmt, ...);
extern MapInfo lbl_80311AC0;
extern s32 lbl_80311AD4[11];
extern s32 lbl_803472E4;
extern char lbl_802B3578[];
extern u32 lbl_80346F74;
extern s32 lbl_8034728C;
extern s32 lbl_80347294;
extern void fn_80143060(s32* p);
extern u8 lbl_80310A1C[];
typedef struct Node {
    u8 pad0[4];
    struct Node* x4;
    struct Node* x8;
    struct Node* xc;
    struct Node* x10;
    struct Node* x14;
} Node;

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

void fn_8014ED2C(Obj_UNIT0000* o) {
    Sub_UNIT0000* s = o->sub;
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

void fn_8013DB0C(s32 a)
{
    s32 d = 0;
    u32 f = lbl_8030A6D4[lbl_8034757C].xc;
    if (f & 1) d = -1;
    if (f & 2) d++;
    fn_8013DA50(a + d, d);
}

s32 fn_80141078(void)
{
    s32 r31 = 0;
    s32 i = 0;
    do {
        if (fn_8013E730(i) > 0) {
            r31 = 1;
            break;
        }
        i++;
    } while (i < 2);
    return r31;
}

void fn_80142F18(void)
{
    u8* p = lbl_80306738;
    p[0] = 0;
    lbl_80346F61 = 0;
    p[0x1] = 0;
    p[0x2] = 0;
    p[0x3] = 0;
    p[0x4] = 0;
    p[0x5] = 0;
    p[0x6] = 0;
    p[0x7] = 0;
    p[0x8] = 0;
    p[0x9] = 0;
    p[0xa] = 0;
    p[0xb] = 0;
    p[0x10] = 0;
    p[0x11] = 0;
    p[0x12] = 0;
    p[0x13] = 0;
    p[0x14] = 0;
    p[0x15] = 0;
    *(u16*)(p + 0x16) = 0;
    *(u16*)(p + 0x18) = 0;
    *(u16*)(p + 0x1a) = 0;
    *(u16*)(p + 0x1c) = 0;
    *(u16*)(p + 0x1e) = 0;
    lbl_80346F60 = 0;
}

void fn_801457C4(s32 a, s32 b)
{
    if (b == 0) {
        if (lbl_8034727C[a].x2c == 1) {
            fn_8014549C(a, 0);
        } else {
            fn_8014549C(a, 1);
        }
    } else {
        if (lbl_8034727C[a].x2c == 1) {
            fn_8014549C(a, 1);
        } else {
            fn_8014549C(a, 0);
        }
    }
}

s32 fn_80145D84(Obj7* dst, Obj24* a, Obj24* b)
{
    s32 v = 0x50 - b->x24 + a->x24;
    s32 r = fn_8025ECC4() % 100;
    if (v >= r) {
        dst->x7 = 1;
        return 1;
    } else {
        dst->x7 = 0;
        return 0;
    }
}

void fn_80146FD4(Req* r, s32 idx)
{
    u8* dst;
    Sub_80146FD4* s;
    s32 v = (s32)r;
    if (r->x1 == 0) {
        dst = (u8*)lbl_8034727C + idx * 0x90 + 0x124;
        s = *(Sub_80146FD4**)lbl_8034727C->x20;
    } else {
        dst = (u8*)lbl_8034727C + idx * 0x90 + 0x5a4;
        s = *(Sub_80146FD4**)lbl_8034727C->x24;
    }
    switch (r->x0) {
    case 1:
    case 2:
    case 5:
    case 7:
        v = s->x14 - s->x18;
        break;
    }
    *(s32*)(dst + 8) = v;
}

void fn_80147E2C(s32 a)
{
    fn_800FF908();
    fn_8025CB24(lbl_802E5E68, lbl_802B3578, lbl_80311AC0.unk4, lbl_80311AC0.room);
    fn_801002D0(a);
    lbl_803472E4 = 1;
    lbl_80311AD4[6] = 0xc;
}

void fn_801481D0(void)
{
    if (lbl_80346F74 == 0 && lbl_80347290 == 0) {
        fn_80143060(&lbl_80347294);
        lbl_80310A1C[0x102] = 0;
        lbl_80347290 = 1;
        lbl_8034728C = 1;
    }
}

void fn_80148E80(Node* n)
{
    Node* b = n->x10;
    Node* a = n->x8;
    Node* c = n->x14;
    if (c != 0) {
        c->x10 = b;
    } else if (a != 0) {
        a->x4 = b;
    }
    if (b != 0) {
        b->x14 = c;
    }
    if (a != 0 && b == 0) {
        a->xc = c;
    }
    n->x8 = 0;
    n->x10 = 0;
    n->x14 = 0;
}
