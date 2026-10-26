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
typedef struct Ent {
    u8 pad[0x2c];
    s16 x2c;
    u8 rest[0x10];
} Ent;
extern void fn_8014549C(s32 a, s32 b);
typedef struct Obj24 { u8 pad[0x24]; s16 x24; } Obj24;
typedef struct Obj7 { u8 pad[7]; u8 x7; } Obj7;
typedef struct Sub_80146FD4 { u8 pad[0x14]; s32 x14; s32 x18; } Sub_80146FD4;
typedef struct Req_UNIT0000 { s8 x0; s8 x1; } Req_UNIT0000;
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
extern void fn_80131500(s8 a);
extern void fn_80131658(s8 *p);
extern void fn_80140264(void);
extern void fn_8013FB48(s32 a, s32 b);
extern s32 fn_80140D04(s32 a);
extern u8 *fn_80135598(void);
extern u8 lbl_8030B4D4[];
extern Ent* lbl_8034727C;
extern s32 lbl_80347278;
extern u8 *fn_801E1A74(s32 a, s32 b);
extern u8 *fn_8013558C(void);
extern u8 lbl_80308F98[];
extern s32 lbl_803472BC;
extern u8 *lbl_803472A8;
extern s32 lbl_803472C0;
extern s32 lbl_803472D4;
extern s32 fn_801298E8(void);
extern void fn_801299A0(void);
extern void fn_80129BD4(void);
extern void fn_8015635C(void);
extern u8 lbl_80308E90[];
extern u32 fn_8013FCF0(s32 a, s32 key, s32 n);
typedef struct { u8 pad[0x2a]; s16 v; u8 pad2[4]; } E30;
typedef struct { u8 pad[0x24]; } E24;
typedef struct { s16 v; u8 pad[0x22]; } E24c;
typedef struct { u8 pad[0x1c]; s16 v; u8 pad2[6]; } E24b;
extern E30 lbl_802C4BF0[];
extern E24 lbl_802D8A2C[];
extern E24 lbl_802C7C34[];
extern E24b lbl_802D8E64[];
typedef struct {
    s8 kind;
    u8 pad1;
    s8 slot;
    u8 pad3[5];
    s16 id;
} Req_801462D0;
typedef struct Cnt { s32 x0; s32 x4; } Cnt;
typedef struct Body {
    u8 pad0[0xe8];
    Cnt *xe8;
    u8 pad1[0x18c - 0xec];
    f32 x18c;
    f32 x190;
    u8 pad2[4];
    s32 x198;
} Body;
typedef struct Owner {
    Body *p;
    s32 x4;
    s32 x8;
    s32 xc;
    s32 x10;
    f32 x14;
    s32 x18;
} Owner;
extern void fn_8014EE4C(Owner *o, s32 a, s32 b, s32 c, s32 d);

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
        ((u8*)lbl_8034727C)[0x29] |= 0x40;
    } else {
        ((u8*)lbl_8034727C)[0x2a] |= 0x40;
    }
}

void fn_80146418(IdxArg* a) {
    if (a->idx == 0) {
        ((u8*)lbl_8034727C)[0x29] |= 0x20;
    } else {
        ((u8*)lbl_8034727C)[0x2a] |= 0x20;
    }
}

void fn_8014644C(IdxArg* a) {
    if (a->idx == 0) {
        ((u8*)lbl_8034727C)[0x29] |= 0x10;
    } else {
        ((u8*)lbl_8034727C)[0x2a] |= 0x10;
    }
}

void fn_80146480(IdxArg* a) {
    if (a->idx == 0) {
        ((u8*)lbl_8034727C)[0x29] |= 0x8;
    } else {
        ((u8*)lbl_8034727C)[0x2a] |= 0x8;
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

void fn_80146FD4(Req_UNIT0000* r, s32 idx)
{
    u8* dst;
    Sub_80146FD4* s;
    s32 v = (s32)r;
    if (r->x1 == 0) {
        dst = (u8*)lbl_8034727C + idx * 0x90 + 0x124;
        s = *(Sub_80146FD4**)((u8*)lbl_8034727C + 0x20);
    } else {
        dst = (u8*)lbl_8034727C + idx * 0x90 + 0x5a4;
        s = *(Sub_80146FD4**)((u8*)lbl_8034727C + 0x24);
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

void fn_80140750(s32 cols, s32 rows)
{
    s32 j;
    s32 fill;
    s32 k;
    s32 i;
    s8 s[5];

    fn_80131500((s8)rows);
    for (i = 0; i < rows; i++) {
        fill = -1;
        for (j = 0; j < cols; j++) {
            for (k = 0; k < 4; k++) {
                s[0] = j;
                s[1] = i;
                s[2] = k;
                s[4] = fill;
                s[3] = fill;
                fn_80131658(s);
            }
        }
    }
    fn_80140264();
    for (fill = 0; fill < rows; fill++) {
        fn_8013FB48(fill, cols);
    }
}

s32 fn_80140FBC(s32 x)
{
    s32 over;
    s32 lim;
    s32 result = 0;
    s32 active;
    u8 *base;
    u8 *q;
    u8 *t;

    if (fn_80140D04(x) != 0) {
        over = 0;
        lim = 100;
        base = fn_80135598();
        active = 0;
        q = base + 0x238;
        if (q != NULL && (s8)q[0xfc] >= 0) {
            active = 1;
        }
        if (active) {
            t = base + 0x320;
            lim = 100;
            if (t != NULL) {
                lim = (s8)t[0x1f] + (s8)t[0x20];
            }
        }
        if (x >= lim) {
            over = 1;
        }
        if (over) {
            result = 1;
        }
    }
    return result;
}

void fn_801453D0(void)
{
    u8 *base;
    u8 *r;

    lbl_8034727C = (Ent*)fn_801E1A74(1, 0xab4);
    *(u8 *)((u8*)lbl_8034727C + 0x28) = lbl_8030B4D4[0x2d4];
    *(s16 *)((u8*)lbl_8034727C + 0x4) = 0;
    *(s32 *)((u8*)lbl_8034727C + 0x18) = 0;
    *(s32 *)((u8*)lbl_8034727C + 0x1c) = 0;
    *(s16 *)((u8*)lbl_8034727C + 0x6) = -1;
    *(s16 *)((u8*)lbl_8034727C + 0x8) = 0;
    *(s16 *)((u8*)lbl_8034727C + 0xa) = -1;
    *(s16 *)((u8*)lbl_8034727C + 0xc) = 0;
    *(s16 *)((u8*)lbl_8034727C + 0xe) = -1;
    *(s16 *)((u8*)lbl_8034727C + 0x10) = 0;
    *(s16 *)((u8*)lbl_8034727C + 0x12) = -1;
    *(s16 *)((u8*)lbl_8034727C + 0x14) = 0;
    base = fn_80135598();
    r = fn_8013558C();
    *(u8 **)((u8*)lbl_8034727C + 0x20) = base + 0x238;
    *(u8 **)((u8*)lbl_8034727C + 0x24) = r;
    lbl_80347278 = 0;
}

s32 fn_80145CA4(s32 p, s32 idx, s32 kind)
{
    s32 result = 0;
    u8 *base;
    s16 v;

    if (p == 0) {
        base = fn_80135598() + 0x238;
    } else {
        base = fn_8013558C() + idx * 0x10c;
    }
    switch (kind) {
    case 2:
        v = *(s16 *)(base + 0x52);
        if (v > 0) {
            result = 1;
        }
        break;
    case 3:
        v = *(s16 *)(base + 0x50);
        if (v > 0) {
            result = 1;
        }
        break;
    case 8:
        v = *(s16 *)(base + 0x54);
        if (v > 0) {
            result = 1;
        }
        break;
    case 12:
        v = *(s16 *)(base + 0x56);
        if (v > 0) {
            result = 1;
        }
        break;
    }
    return result;
}

void fn_80148640(void)
{
    s32 sum;

    if (lbl_80346F80 == -1) {
        return;
    }
    if (fn_801298E8() == 0) {
        return;
    }
    lbl_803472BC = lbl_80346F80;
    lbl_803472A8 = lbl_80308F98 + lbl_80346F80 * 12;
    fn_801299A0();
    sum = lbl_803472D4 + lbl_803472C0;
    lbl_803472C0 = 0;
    lbl_803472D4 = sum;
    lbl_80310A1C[0x101] = 0;
    lbl_80310A1C[0x100] = 0;
    fn_80129BD4();
    lbl_80346F80 = -1;
    fn_8015635C();
}

static inline s32 NameCount(void) {
    s32 n = 0;
    s8 *p = (s8 *)fn_80135598();
    if (p != NULL) {
        n = 0;
        if (p[0] >= 0) {
            n = 1;
            if (p[1] >= 0) {
                n = 2;
                if (p[2] >= 0) {
                    n = 3;
                    if (p[3] >= 0) {
                        n = 4;
                    }
                }
            }
        }
    }
    return n;
}

u32 fn_8013FE10(s32 a, s32 key) {
    u32 flags = 0;
    s32 n = NameCount();

    if (a >= 0 && a < n && (s8)lbl_80308E90[a * 5 + 0x14] != -1 &&
        key == (s8)lbl_80308E90[a * 5 + 0x15]) {
        flags = 1;
    } else {
        if (a >= 0 && a < n && (s8)lbl_80308E90[a * 5 + 0x14] != -1) {
            flags = 2;
        } else if (a >= n) {
            flags = 0x10;
        }
        flags |= fn_8013FCF0(a, key, n);
    }
    return flags;
}

void fn_801462D0(Req_801462D0 *o) {
    u8 *p = fn_80135598() + o->slot * 0x1c + 0x1c6;
    s32 d;

    switch (o->kind) {
    case 5:
        d = lbl_802C4BF0[o->id].v;
        break;
    case 1:
        d = ((E24c *)((u8 *)lbl_802D8A2C - 0x4364))[o->id].v;
        break;
    case 2:
        d = ((E24c *)((u8 *)lbl_802C7C34 - 0x21a4))[o->id].v;
        break;
    case 7:
        d = lbl_802D8E64[o->id].v;
        break;
    }
    p[0xe] += d;
    if ((s8)p[0xe] > (s8)p[0xd]) p[0xe] = p[0xd];
}

void fn_8014ED5C(Owner *o, f32 v) {
    if (o->x8 == o->x10) {
        o->p->x190 = v;
    } else {
        o->p->x190 = o->x14;
    }
    if (o->p->x198 == 1) {
        o->x4 = 0;
        if (o->x18 != 0) {
            Body *b = o->p;
            s32 m = (s32)(100.0f * b->x18c);
            m = m % ((b->xe8->x4 - 1) * 100);
            b->x18c = (f32)m / 100.0f;
        } else {
            o->p->x190 = 0.0f;
        }
        if (o->x8 >= 0) {
            fn_8014EE4C(o, o->x8, 1, 1, 10);
        }
    }
}
