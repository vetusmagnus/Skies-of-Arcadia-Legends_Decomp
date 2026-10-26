#include "types.h"
#include "ninja.h"
#include "game/drawstate.h"
#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

typedef struct { u8 pad0[4]; s32 f4; u8 pad8[4]; s32 fc; } Ev;
typedef struct { u8 pad0[0x2d8]; s32 f2d8; } Ctx;
typedef struct { u8 pad0[0x6c]; void* p6c; } Obj_8015271C;
typedef struct { s32 f0; u8 pad4; s8 f5; } Ent_UNIT0000;
typedef struct { s32 a, b; u32 c; void* p; } St;
typedef struct { u32 idx; u32 a, b, c, d; } Src_UNIT0000;
typedef struct { u32 a, b; void* p; } E12;
typedef struct { s32 flag; u8 pad[0x10]; f32 pos[3]; s32 ints[3]; } Obj_80158200;
typedef struct { u32 flags; u8 pad[0x38]; u16 h3c; u16 h3e; u16 h40; u8 pad2[0x2a]; s16 h6c; } Obj_8015854C;
typedef struct Inner { u8 pad[0x8]; void *x8; } Inner;
typedef struct Obj_8015C6F0 { u8 pad[0x1d8]; Inner *x1d8; } Obj_8015C6F0;
typedef struct Sub { u8 pad[0x260]; u32 f260; } Sub;
typedef struct Obj_8015C8B8 { u8 pad[0x1d8]; Sub *x1d8; } Obj_8015C8B8;
typedef struct { u8 pad0[4]; void* p4; u8 pad8[4]; u32 f0c; } Obj_80153270;
typedef struct { s32 flag; void *a; void *b; void *c; u32 d; } E14;
typedef struct { s32 f0; u8 b4; } E40;
typedef struct { u8 pad[0x1ec]; u8 f1ec; u8 pad2[2]; u8 f1ef; } In;
typedef struct { u8 pad[0x24]; In *p24; } Mid;
typedef struct { u8 pad0[0x28]; Mid *p28; u8 pad1[0x40]; void *p6c; } Obj_80152AFC;
typedef struct { u8 pad[0x17a]; u16 h17a; } Rec;
typedef struct { u8 pad[0x24]; Rec *p24; } Holder;
typedef struct { Holder *p0; u8 pad[0x10]; } Slot_UNIT0000;
typedef struct Owner { u8 pad[0x10]; u8* x10; } Owner;
typedef struct Obj_8015259C {
    u8 pad0[0x34];
    s32 x34;
    u8 pad1[4];
    s32 x3c;
    u8 pad2[0x10];
    s32 x50;
    u8 pad3[4];
    s32 x58;
    u8 pad4[0x10];
    void *x6c;
} Obj_8015259C;
typedef struct { u32 f0; s32 f4; s8 f8; u8 pad[0xb]; } Gx;
typedef struct { u32 a, b, c; } Blk;
typedef struct { u8 pad[0x1c]; u32 f1c; } Src_8015DBE4;
typedef struct { u8 pad[0x1e]; s16 h1e; u8 pad2[0x78 - 0x20]; Blk b78; } State;
typedef struct { u8 pad[0x20]; u32 *p20; } M2;
typedef struct { u8 pad[0x1c8]; M2 *p1c8; u8 pad2[0x1d8 - 0x1cc]; State *p1d8; } Self;
void fn_80153270(void *p);
void fn_80155CD8(void);
void fn_80155D74(void);
void *memcpy(void *dst, const void *src, u32 n);
void *memset(void *p, s32 c, u32 n);
extern u8 lbl_803067A8[];
extern u8 lbl_80306938[];
extern s32 lbl_80306758[];
extern u8 *lbl_80346FB8;
extern E14 *lbl_80346FE8;
extern void *lbl_80346FAC;
extern s32 lbl_8034704C;
extern Ent_UNIT0000 *lbl_802E6ACC[];
extern E40 *lbl_802E6A40[];
extern s32 *lbl_802E6AB0[];
extern char lbl_802B3B9C[];
extern char lbl_802B3B80[];
extern char lbl_802B3BB8[];
extern char lbl_802B3F38[];
extern char lbl_802B4104[];
extern const char lbl_802B3F24[];
extern s32 lbl_80347024;
extern u32 lbl_80347008;
extern u8 lbl_80306C98[];
extern E12 lbl_80306B14[];
extern E12 lbl_80308F98[];
extern Obj_8015854C* lbl_80306DB8[];
extern s32 lbl_8034729C;
extern u32 lbl_802E7090[];
extern s32 lbl_80346FA0;
extern s32 lbl_80346FA4;
extern s32 lbl_80346FA8;
extern s32 lbl_80346F9C;
extern s32 lbl_80346FB0;
extern s32 lbl_80346FB4;
extern u32 lbl_80346FBC;
extern u8* lbl_80346FC8[2];
extern St* lbl_80347000;
extern void *lbl_80347048;
extern s32 lbl_8034746C;
extern Gx lbl_80311AC0;
extern Slot_UNIT0000 lbl_80308EF8[];
extern u32 lbl_803472A8;
extern f32 lbl_803472DC;
extern f32 lbl_803472E0;
void fn_801E17E0(s32 x);
void fn_80150CB0(void *a, void *b);
void *fn_8015C4D8(void *p);
void fn_80144680(void *p);
void fn_801453D0(void);
void fn_80158374(void *p);
void fn_8015757C(s32 a, s32 b);
void fn_8020EF30(void *p);
void fn_80155A8C(void *p);
void fn_80109A94(void *p);
void *fn_801E1C7C(s32 size);
void fn_80217830(void *p);
void *fn_801E1A74(s32 a, s32 size);
void fn_80153978(void);
void fn_80152284(void *p);
void fn_80154B6C(void);
void fn_801539C4(void);
void fn_80153730(void);
void fn_8014F4E8(void *p);
void fn_801DBE1C(const char *fmt, ...);
void fn_8025CB24(void *p, ...);
void fn_80158690(s16 idx);
void fn_80167690(void *p);
void fn_80150A80(u8 *p);
void fn_8014F72C(u8 *p, s32 n);
s32 fn_80156A3C(void);
void *fn_80158394(void);
void fn_80152B58(void *a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h, s32 i, s32 j, s32 k, s32 l);
void fn_8015823C(u8 *p);
void fn_80153790(s32 a, s32 b, s32 c);
void fn_8014836C(s32 a, void *b);
void fn_80148228(s32 a, void *b);
void fn_801523A4(void *p, s32 a, s32 b, s32 c, s32 d);
s32 fn_8010CED4(void);
void fn_8012F72C(s32 a);
s32 fn_8015BB58(s32 a);
void fn_8015B358(void);
s32 fn_801CC62C(void *p);
void *fn_801CC3C4(void *p);
Blk *fn_8016748C(void *a, u32 v);

void *fn_8010A164(s32 a);
s32 fn_80129CA8(void *p);
void fn_801532B4(u8 *p);
void *memset(void *d, s32 c, u32 n);


void fn_8020EF30(void *p);
void fn_8020EFD4(void *p);
void fn_801575C4(void *a);

extern char lbl_802B3BB8[];
typedef struct Slot_80154C34 {
    s32 active;
    s16 id;
    s16 timer;
} Slot_80154C34;
extern u8 *lbl_80346FE0;
typedef struct Ent_80155AB4 {
    s32 id;
    void *p;
} Ent_80155AB4;
extern Ent_80155AB4 lbl_80346FF8[1];
extern s32 lbl_80346FF0;
extern char lbl_802B3E84[];
extern char lbl_802B3EA4[];
s32 fn_80215F8C(void *p);
void fn_80215F94(void *p);

extern char lbl_802B3EDC[];
s32 fn_80216CA4(void *p);
s32 fn_80216F1C(s32 a, s32 b);
void *memcpy(void *d, const void *s, u32 n);
void *fn_8010A164(s32 a);
void fn_8014FCF0(u8 *dst, s32 a, s32 b);
typedef struct {
    u8 pad0[0x1c];
    f32 scale;        /* 0x1C, must be > 0 to draw */
    u8 pad1[0x38 - 0x20];
    f32 pos[3];       /* 0x38 */
    u8 pad2[0xe4 - 0x44];
    void* model;      /* 0xE4 */
    u8 pad3[0x100 - 0xe8];
    void* texlist;    /* 0x100 */
    u8 pad4[0x176 - 0x104];
    u16 flags176;     /* 0x176 */
    u8 pad5[0x184 - 0x178];
    s32 hidden;       /* 0x184 */
} Obj80156DA0;
extern f32 lbl_8034A900;
extern void fn_80299040(void* texlist);
extern void fn_80286EE8(void);
extern void fn_8028B498(void);
extern void fn_802974E0(void* v);
extern void fn_801E4FD4(Obj80156DA0* self);
extern void fn_801E4CB0(u16 a, void* b);
extern void njPushMatrixEx(void);
extern void njPopMatrixEx(void);
extern void njMultiMatrix(s32 a, void* m);
typedef struct {
    u8 pad0[0x10];
    s16 index;        /* 0x10 */
    s16 type;         /* 0x12 */
} Inner80159020;
typedef struct {
    u8 pad0[0x24];
    Inner80159020* inner; /* 0x24 */
} Obj80159020;
typedef struct {
    u8 pad0[0xc];
    f32 value;        /* 0x0C */
} Entry80159020;
extern f32 lbl_8034A940;
extern f32 lbl_8034A95C;
extern s32 fn_801590F4(Inner80159020* in, s32 v);
extern u8* lbl_8034727C;
extern void* lbl_803472AC;
extern void* lbl_803472B0;
extern s32 lbl_803472B4;
extern void* fn_80129D40(void* p);

void fn_8014F970(u8 *self) {
    fn_80153270(self + 0x95c);
    fn_80155CD8();
    fn_80155D74();
}

s32 fn_8014FC9C(Ctx* c, Ev* e) {
    if (e->fc == 6 && e->f4 == -1 && c->f2d8 == 0) {
        c->f2d8 = 1;
        return 1;
    }
    return 0;
}

void fn_8014FCD8(u8 *base, s32 i, u16 v) {
    u8 *e = base + i * 0xa8;
    *(u16 *)(e + 0x48) = v;
    *(u16 *)(e + 0x4a) = 0;
}

void fn_801515EC(u8 *p) {
    *(u32 *)(p + 0x168) = 0;
}

void fn_801515F8(u8 *p, u32 a, u32 b, u32 c, u32 d, u32 e) {
    *(u32 *)(p + 0x154) = b;
    *(u32 *)(p + 0x158) = a;
    *(u32 *)(p + 0x160) = c;
    *(u32 *)(p + 0x15c) = d;
    *(u32 *)(p + 0x164) = e;
}

void fn_801517EC(u8 *p) {
    memcpy(p + 0x34, p + 4, 0x30);
}

void fn_8015181C(u8 *p) {
    memcpy(p + 4, p + 0x34, 0x30);
}

void fn_8015271C(Obj_8015271C* o) {
    if (o->p6c != 0) {
        fn_80158374(o->p6c);
        o->p6c = 0;
    }
}

void fn_80152EE8(u8 *p, u32 v) {
    *(u32 *)(p + 0x48) = v;
}

s32 fn_80152FC4(s32 idx) {
    if (idx > 0x18) {
        fn_8015757C((s32)lbl_802B3B9C, idx);
        idx = 0;
    }
    return lbl_802E6ACC[idx]->f5;
}

s32 fn_80153014(s32 idx) {
    if (idx > 0x18) {
        fn_8015757C((s32)lbl_802B3B9C, idx);
        idx = 0;
    }
    return lbl_802E6ACC[idx]->f0;
}

void fn_80153270(void *p) {
    Obj_80153270* o = p;
    if (o->f0c != 0) {
        fn_8020EF30(o->p4);
        o->f0c = 0;
    }
}

void fn_801532B4(u8* p) {
    memset(p, 0, 0x24);
    fn_80155A8C(p + 0x10);
}

void fn_80153498(void) {
    if (lbl_80306758[2] != 0) {
        fn_80109A94((u8*)lbl_80306758 + 0xc);
    }
    lbl_80306758[2] = 0;
    lbl_80306758[0] = 0;
}

void fn_801534E8(void) {
    memset(lbl_80306758, 0, 0x50);
}

void fn_80153978(void) {
    memcpy(lbl_803067A8, lbl_80306938, 0x190);
    memset(lbl_80306938, 0, 0x190);
}

void fn_80153A04(void) {
    void* p = fn_801E1C7C(0x406);
    memset(p, 0, 0x406);
    lbl_80346FB8 = p;
}

u8 fn_80153DA8(s32 i) {
    u8 *b = lbl_80346FB8;
    return (i + b)[4];
}

void fn_80153DB8(s32 i, u8 v) {
    u8 *b = lbl_80346FB8;
    (i + b)[4] = v;
}

void fn_801558B0(Src_UNIT0000* s) {
    E14* e = lbl_80346FE8 + s->idx;
    e->a = (void*)s->a;
    e->b = (void*)s->b;
    e->c = (void*)s->c;
    e->d = s->d;
    e->flag = 1;
}

void fn_801558EC(void) {
    fn_801E17E0((s32)lbl_80346FE8);
}

void fn_80155944(void *p) {
    fn_80150CB0(lbl_80346FAC, p);
}

void fn_80155A8C(void *p) {
    memset(p, 0, 0x14);
}

void fn_80155D74(void) {
    St* o = lbl_80347000;
    if (o->p != 0) {
        fn_80217830(o->p);
        o->p = 0;
    }
}

void fn_80155F80(void) {
    St* s;
    lbl_80347000 = fn_801E1A74(1, 0x90);
    memset(lbl_80347000, 0, 0x90);
    s = lbl_80347000;
    s->b = -1;
    s->a = -1;
    s->c = 0;
}

void fn_80156250(void) {
    lbl_80346FBC = lbl_80346FBC + 1;
    fn_80153978();
    fn_80152284(lbl_80346FC8[0] + 0x604);
    fn_80152284(lbl_80346FC8[1] + 0x604);
    fn_80154B6C();
    fn_801539C4();
    fn_80153730();
}

void fn_80156324(void) {
    fn_8014F4E8(*(void**)(lbl_80346FC8[0] + 0x10));
    fn_8014F4E8(*(void**)(lbl_80346FC8[1] + 0x10));
}

s32 fn_80156A3C(void) {
    if (lbl_80347024 >= 0xFDE8) {
        fn_801DBE1C(lbl_802B3F24);
    }
    return (lbl_80347024 += 0x1e) - 0x1e;
}

void fn_80157530(s32 a, s32 b, s32 c) {
    if (lbl_80347008 == 0) {
        lbl_80347008 = (u32)lbl_80306C98;
        fn_8025CB24(lbl_80306C98, a, b, c);
    }
}

void fn_8015757C(s32 a, s32 b) {
    if (lbl_80347008 == 0) {
        lbl_80347008 = (u32)lbl_80306C98;
        fn_8025CB24(lbl_80306C98, a, b);
    }
}

void fn_80157E54(s32 i, s32 j) {
    memcpy((u8*)lbl_80306B14[i].p + j * 0x58, (u8*)lbl_80308F98[i].p + j * 0x58, 0x58);
}

void fn_80158200(Obj_80158200* o, f32* v, s32* w) {
    o->flag = 1;
    o->pos[0] = v[0];
    o->pos[1] = v[1];
    o->pos[2] = v[2];
    o->ints[0] = w[0];
    o->ints[1] = w[1];
    o->ints[2] = w[2];
}

void fn_8015823C(u8 *p) {
    *(u32 *)(p + 0) = 0;
    *(u16 *)(p + 6) = 0;
    *(u16 *)(p + 4) = 0;
}

void fn_80158358(u8 *p, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f) {
    *(u32 *)(p + 0x10) = a;
    *(u32 *)(p + 0x8) = b;
    *(u32 *)(p + 0xc) = e;
    *(u32 *)(p + 0x3c) = c;
    *(u32 *)(p + 0x40) = d;
    *(u32 *)(p + 0x44) = f;
}

void* fn_80158394(void) {
    void* p = fn_801E1A74(1, 0x54);
    memset(p, 0, 0x54);
    return p;
}

void fn_8015854C(s16 idx, u16 bits) {
    Obj_8015854C* o = lbl_80306DB8[idx];
    if (o == 0) {
        return;
    }
    o->flags |= 0x20000000;
    lbl_80306DB8[idx]->h3e = bits;
    lbl_80306DB8[idx]->h3c |= bits;
}

void fn_80158650(s16 idx, s16 val) {
    u8 *p = (u8 *)lbl_80306DB8[idx];
    if (p == 0) return;
    *(s16 *)(p + 0x12) = val;
    if (val == 9) {
        *(u32 *)lbl_80306DB8[idx] |= 0x02000000;
    }
}

void fn_80158690(s16 idx) {
    u32 *p = (u32 *)lbl_80306DB8[idx];
    if (p == 0) return;
    if (p[0] & 0x40000000) return;
    p[1] = 0;
    *(s16 *)((u8 *)lbl_80306DB8[idx] + 0x3e) = 0;
    *(s16 *)((u8 *)lbl_80306DB8[idx] + 0x3c) = 0;
}

void fn_8015A844(void) {
    s32 i;
    for (i = 0; i < lbl_8034729C; i++) {
        fn_80158690((s16)i);
    }
}

void fn_8015C5F4(void *p) {
    fn_80144680(fn_8015C4D8(p));
}

void fn_8015C6C8(void) {
    lbl_8034704C = 0;
    fn_801453D0();
}

s32 fn_8015C6F0(Obj_8015C6F0 *p) {
    if (p && p->x1d8 && p->x1d8->x8) {
        fn_80167690(p->x1d8->x8);
        return 1;
    }
    return 0;
}

void fn_8015C8B8(Obj_8015C8B8 *obj, s32 idx) {
    Sub *s = obj->x1d8;
    u32 v;
    if (s == 0) return;
    if (idx >= 6) return;
    if (idx < 0) {
        v = 0;
    } else {
        v = lbl_802E7090[idx];
    }
    s->f260 = v;
}

s32 fn_8015CF8C(u8 *p, u8 *q) {
    u32 v = *(u32 *)(q + 0x1c);
    u8 *dst = *(u8 **)(p + 0x1d8);
    *(u16 *)(dst + 0x18) = v;
    return 0;
}

s32 fn_8015D688(void *unused, u8 *q) {
    s32 v = *(s32 *)(q + 0x1c) - 1;
    *(s32 *)(q + 0x1c) = v;
    return v != 0;
}

s32 fn_8015DC54(u8 *p) {
    u32 *flags = *(u32 **)(p + 0x1d8);
    *flags &= ~0x80;
    return 0;
}

void fn_8014FD9C(void)
{
    s32 r31;
    fn_801E17E0(lbl_80346FA0);
    fn_801E17E0(lbl_80346FA4);
    fn_801E17E0(lbl_80346FA8);
    r31 = (s32)lbl_80346FAC;
    fn_801E17E0(lbl_80346F9C);
    fn_801E17E0(r31);
    fn_801E17E0(lbl_80346FB0);
    fn_801E17E0(lbl_80346FB4);
}

void fn_80150258(void)
{
    memset((void*)lbl_80346FA0, 0, 0x1616);
    fn_80150A80((u8 *)lbl_80346FA8);
    fn_8014F72C(((Owner*)lbl_80346FC8[0])->x10 + 0x9c0, 0);
    fn_8014F72C(((Owner*)lbl_80346FC8[1])->x10 + 0x9c0, 1);
}

void fn_80152538(void* dst, s32 a, s32 b, s32 c)
{
    s32* d;
    memset(dst, 0, 0x28);
    d = (s32*)dst;
    d[0] = a;
    d[1] = b;
    d[2] = c;
}

void fn_8015259C(Obj_8015259C* o)
{
    memset(o, 0, 0x70);
    o->x3c = fn_80156A3C();
    o->x34 = fn_80156A3C();
    o->x50 = fn_80156A3C();
    o->x58 = fn_80156A3C();
    o->x6c = fn_80158394();
}

void fn_801526C4(void *a, s32 b, s32 c) {
    fn_80152B58(a, 0, 1, b, 0, c, 0, 0x891C, 0x76C0, 0, 0, 0);
}

void fn_80152AFC(Obj_80152AFC *o) {
    if (o->p6c != 0) {
        fn_8015823C(o->p6c);
    }
    if (o->p28 != 0) {
        o->p28->p24->f1ec = 0;
        o->p28->p24->f1ef = 0;
    }
}

void fn_80152F4C(s32 idx, s32 a, s32 b) {
    if (idx != -1) {
        if (idx > 0x18) {
            fn_8015757C((s32)lbl_802B3B80, idx);
            idx = 0;
        }
        fn_80153790(lbl_802E6ACC[idx]->f0, a, b);
    }
}

s32 fn_801533C4(s32 idx) {
    E40 *e;
    s32 r = 0;
    if (idx > 0x1a) {
        fn_8015757C((s32)lbl_802B3BB8, idx);
        return 0;
    }
    e = lbl_802E6A40[idx];
    if ((s8)e->b4 != 0) {
        r = e->f0;
    }
    return r;
}

s32 fn_80153428(s32 idx, s32 sub) {
    if (idx > 0x1a) {
        fn_8015757C((s32)lbl_802B3BB8, idx);
        return 0;
    }
    if (idx == 4) {
        return *lbl_802E6AB0[sub];
    }
    return lbl_802E6A40[idx]->f0;
}

void fn_80155848(s32 idx) {
    E14 *e = &lbl_80346FE8[idx];
    if (e->flag != 0) {
        fn_8014836C(0, e->a);
        fn_8014836C((u16)e->d, e->b);
        fn_80148228(0x7fffffff, e->c);
    }
}

void fn_801562A4(s32 unused, f32 *v) {
    fn_801523A4(lbl_80346FC8[(s32)v[0]] + 0x604, (s32)v[1], (s32)v[2], (s32)v[3], (s32)v[4]);
}

s32 fn_80156A8C(s32 x) {
    s32 i;
    for (i = 0; i < lbl_8034729C; i++) {
        if (x == lbl_80308EF8[i].p0->p24->h17a) {
            return i;
        }
    }
    fn_801DBE1C(lbl_802B3F38, x);
    return -1;
}

void fn_801584DC(s16 idx, u32 bits, s32 mode) {
    if (lbl_80306DB8[idx] == 0) {
        return;
    }
    if (mode == 1) {
        bits &= lbl_80306DB8[idx]->h3c;
        if ((u16)bits == 0) {
            return;
        }
        lbl_80306DB8[idx]->h40 |= bits;
        lbl_80306DB8[idx]->h6c = 0xff;
        lbl_80306DB8[idx]->flags |= 0x08000000;
    } else {
        lbl_80306DB8[idx]->h3c &= ~bits;
    }
}

void fn_8015AA18(void) {
    if (lbl_803472A8 == 0 || 0.0f == lbl_803472DC) {
        if (fn_8010CED4() == 1) {
            fn_8012F72C(1);
        }
    } else {
        if (fn_8015BB58((s32)lbl_803472E0) != 0) {
            fn_8015B358();
        }
    }
}

s32 fn_8015AA88(u32 x) {
    s32 r = -1;
    if (x == 0x1e4) {
        r = 0x17;
    } else if (x == 0x1e5) {
        r = 0x1a;
    } else if (x == 0x1e6) {
        r = 0x2;
    } else if (x == 0x1e7) {
        r = 0x20;
    } else if (x == 0x1e8) {
        r = 0x4;
    } else if (x == 0x1e9) {
        r = 0x14;
    }
    return r;
}

s32 fn_8015AAF0(s32 x) {
    s32 r = 1;
    if (x == 6) {
        r = 7;
    } else if (x == 7) {
        r = 8;
    } else if (x == 8) {
        r = 9;
    } else if (x == 9) {
        r = 10;
    } else if (x == 0) {
        r = 11;
    } else if (x == 1) {
        r = 12;
    } else if (x == 0xd) {
        r = 13;
    }
    return r;
}

void fn_8015C644(void) {
    u8 buf[0x20];
    fn_8025CB24(buf, lbl_802B4104, lbl_8034746C, lbl_80311AC0.f4, lbl_80311AC0.f8);
    if (fn_801CC62C(buf) == 1) {
        lbl_80347048 = fn_801CC3C4(buf);
    }
}

s32 fn_8015DBE4(Self *self, Src_8015DBE4 *src) {
    State *st = self->p1d8;
    Blk *b;
    st->h1e = src->f1c;
    if (st->b78.a == 0) {
        b = fn_8016748C(self, *self->p1c8->p20);
        if (b != 0) {
            st->b78 = *b;
        }
    }
    return 0;
}

void fn_8014FCF0(u8 *dst, s32 a, s32 b)
{
    s32 i;
    u8 *x = (u8 *)fn_8010A164(a);
    u8 *y = AT(u8 *, x, 0x24);

    memset(dst, 0, 0xa00);
    AT(u8 *, dst, 0) = x;
    AT(u8 *, dst, 4) = y;
    AT(u32, dst, 8) = AT(u32, y, 0x1e4);
    AT(s16, dst, 0xc) = fn_80129CA8(y);
    AT(s16, dst, 0xe) = b;
    for (i = 0; i < 2; i++) {
        fn_801532B4(dst + 0x95c + i * 0x24);
    }
    AT(s32, dst, 0x9a4) = 0;
}

void fn_80150A80(u8 *p)
{
    memset(p, 0, 0x6c);
    AT(s32, p, 0x38) = AT(s32, lbl_80346FC8[0], 0x10) + 0x9c0;
    AT(s32, p, 0x20) = 0;
    AT(s32, p, 0x54) = AT(s32, lbl_80346FC8[1], 0x10) + 0x9c0;
    AT(s32, p, 0x3c) = 1;
    AT(s32, p, 0x1c) = 0;
    AT(s32, p, 0) = -1;
    AT(s32, p, 0x24) = 6;
    AT(s32, p, 0x28) = 0;
    AT(s32, p, 0x2c) = 0;
    AT(s32, p, 0x40) = 6;
    AT(s32, p, 0x44) = 0;
    AT(s32, p, 0x48) = 0;
    AT(s32, p, 4) = -1;
    AT(s32, p, 8) = 0;
    AT(s32, p, 0xc) = 0;
    AT(s32, p, 0x64) = 0;
    AT(s32, p, 0x68) = 0;
}

s32 fn_801531DC(u8 *obj, void *ptr)
{
    void *r;

    if (ptr != 0) {
        if (AT(u32, obj, 0xc) != 0) {
            fn_8020EF30(AT(void *, obj, 4));
            AT(s32, obj, 0xc) = 0;
        }
        r = fn_8010A164((s32)ptr);
        if (r != 0) {
            AT(void *, obj, 0xc) = r;
            AT(void *, obj, 4) = ptr;
            fn_8020EFD4(AT(void *, obj, 4));
            AT(s32, obj, 8) = 0x78;
        } else {
            fn_801575C4(ptr);
            return 0;
        }
    }
    return 1;
}

void fn_80153324(s32 idx, s32 *pa, s32 *pb, s32 *pc)
{
    if (idx > 0x1a) {
        fn_8015757C((s32)lbl_802B3BB8, idx);
    }
    *pa = AT(s8, lbl_802E6A40[idx], 5);
    *pb = AT(s8, lbl_802E6A40[idx], 6);
    *pc = AT(s8, lbl_802E6A40[idx], 0xa);
}

void fn_80154C34(s32 val, s32 delay)
{
    u8 *g = lbl_80346FE0;
    Slot_80154C34 *s;
    s32 i;
    u32 cnt;

    if (g == 0) {
        return;
    }
    s = (Slot_80154C34 *)(g + 0x188);
    for (i = 0; i < 10; i++) {
        if (s->active == 0) {
            if (val >= 0x48) {
                val = 1;
            }
            if (val <= 0) {
                s->active = 0;
                return;
            }
            s->active = 1;
            s->id = (s16)val;
            cnt = AT(u32, lbl_80346FE0, 0x10);
            if (cnt != 0) {
                s->timer = (s16)(cnt + delay);
            } else {
                s->timer = (s16)delay;
            }
            AT(u32, lbl_80346FE0, 0x10) = AT(u32, lbl_80346FE0, 0x10) + 1;
            return;
        }
        s++;
    }
}

void *fn_80155AB4(s32 id)
{
    s32 n;
    Ent_80155AB4 *e = &lbl_80346FF8[lbl_80346FF0];

    if (e->id != id) {
        fn_8015757C((s32)lbl_802B3E84, id);
        return 0;
    }
    if (e->p != 0) {
        if (fn_80215F8C(e->p) == 0) {
            fn_80217830(e->p);
            fn_8015757C((s32)lbl_802B3EA4, id);
            return 0;
        }
        fn_80215F94(e->p);
    }
    n = lbl_80346FF0 + 1;
    lbl_80346FF0 = n;
    if (n >= 1) {
        lbl_80346FF0 = 0;
    }
    return e->p;
}

s32 fn_80155DB4(s32 id, s32 v)
{
    u8 *st = (u8 *)lbl_80347000;

    if (AT(s32, st, 0) != id) {
        fn_80157530((s32)lbl_802B3EDC, id, v);
        return 0;
    }
    if (AT(s32, st, 8) != 0) {
        if (fn_80216CA4(st + 0x10) != 0) {
            AT(s32, st, 8) = 0;
        } else {
            return 0;
        }
    }
    AT(s32, st, 0xc) = fn_80216F1C((s8)id, (s8)v);
    return AT(s32, st, 0xc);
}

void fn_801566B4(s32 a, void *p4, void *p5)
{
    if (AT(void *, lbl_80346FC8[a], 0x14) != 0) {
        memcpy((u8 *)lbl_80346FC8[a] + 0x1c, AT(void *, lbl_80346FC8[a], 0x14), 0x40);
        memcpy((u8 *)lbl_80346FC8[a] + 0x5c, AT(void *, lbl_80346FC8[a], 0x18), 0x40);
    } else {
        memcpy((u8 *)lbl_80346FC8[a] + 0x1c, p4, 0x40);
        memcpy((u8 *)lbl_80346FC8[a] + 0x5c, p5, 0x40);
    }
    AT(void *, lbl_80346FC8[a], 0x14) = p4;
    AT(void *, lbl_80346FC8[a], 0x18) = p5;
}

void fn_80156994(s32 a, u8 *obj, u8 *b, s32 c)
{
    void *r29 = fn_8010A164(AT(u16, obj, 0x17a));

    AT(void *, lbl_80346FC8[a], 0) = r29;
    AT(void *, lbl_80346FC8[a], 4) = obj;
    AT(s32, lbl_80346FC8[a], 8) = c;
    AT(s32, lbl_80346FC8[a], 0xc) = fn_80129CA8(obj);
    AT(u8 *, lbl_80346FC8[a], 0x10) = b;
    fn_8014FCF0(b, AT(u16, obj, 0x17a), a);
    fn_80152538((u8 *)lbl_80346FC8[a] + 0x604, a, fn_80129CA8(obj), (s32)r29);
}

void fn_80156DA0(Obj80156DA0* self, void* m) {
    if (self->model == 0 || self->scale <= lbl_8034A900 || self->hidden != 0) {
        return;
    }
    if (self->texlist != 0) {
        fn_80299040(self->texlist);
    }
    njPushMatrixEx();
    fn_80286EE8();
    fn_8028B498();
    fn_802974E0(self->pos);
    fn_801E4FD4(self);
    njMultiMatrix(0, m);
    fn_801E4CB0(self->flags176, self->model);
    DrawStatePop(0);
    njPopMatrixEx();
}

s32 fn_80159020(Obj80159020* self) {
    Inner80159020* in = self->inner;
    Entry80159020* e;
    s32 r;
    if (in->type != 9) {
        r = fn_801590F4(in, 1);
        if (in->type == 5 || in->type == 3 || in->type == 7 || in->type == 10) {
            return 0;
        }
        if ((u8)r != 0) {
            e = (Entry80159020 *)lbl_80306DB8[in->index];
            if (e != 0) {
                e->value = lbl_8034A95C;
            }
        } else {
            e = (Entry80159020 *)lbl_80306DB8[in->index];
            if (e != 0) {
                e->value = lbl_8034A940;
            }
        }
        return r;
    }
    fn_801590F4(in, 0);
    return 0;
}

void fn_8015A780(s32 flag) {
    u8 v;
    u16 bits = 0;
    s32 idx;
    void* p;
    idx = lbl_803472B4;
    if (flag == 0) {
        v = lbl_8034727C[idx * 0x3e + 0x50];
    } else {
        v = lbl_8034727C[idx * 0x3e + 0x68];
    }
    if (flag == 0) {
        p = fn_80129D40(lbl_803472B0);
    } else {
        p = fn_80129D40(lbl_803472AC);
    }
    if ((s8)v & 0x2) {
        bits |= 0x400;
    }
    if ((s8)v & 0x1) {
        bits |= 0x200;
    }
    if ((s8)v & 0x4) {
        bits |= 0x80;
    }
    if ((s8)v & 0x8) {
        bits |= 0x20;
    }
    *(u16*)((u8*)p + 0x4) = bits;
}
