#include "types.h"

typedef struct { u8 pad0[4]; s32 f4; u8 pad8[4]; s32 fc; } Ev;
typedef struct { u8 pad0[0x2d8]; s32 f2d8; } Ctx;
typedef struct { u8 pad0[0x6c]; void* p6c; } Obj_8015271C;
typedef struct { s32 f0; u8 pad4; s8 f5; } Ent_802E6ACC;
typedef struct { s32 a, b; u32 c; void* p; } St;
typedef struct { u32 flag; u32 a, b, c, d; } Ent_801558B0;
typedef struct { u32 idx; u32 a, b, c, d; } Src;
typedef struct { u32 a, b; void* p; } E12;
typedef struct { s32 flag; u8 pad[0x10]; f32 pos[3]; s32 ints[3]; } Obj_80158200;
typedef struct { u32 flags; u8 pad[0x38]; u16 h3c; u16 h3e; } Obj_8015854C;
typedef struct Inner { u8 pad[0x8]; void *x8; } Inner;
typedef struct Obj_8015C6F0 { u8 pad[0x1d8]; Inner *x1d8; } Obj_8015C6F0;
typedef struct Sub { u8 pad[0x260]; u32 f260; } Sub;
typedef struct Obj_8015C8B8 { u8 pad[0x1d8]; Sub *x1d8; } Obj_8015C8B8;
typedef struct { u8 pad0[4]; void* p4; u8 pad8[4]; u32 f0c; } Obj_80153270;

void fn_80153270(void *p);
void fn_80155CD8(void);
void fn_80155D74(void);
void *memcpy(void *dst, const void *src, u32 n);
void *memset(void *p, s32 c, u32 n);
extern u8 lbl_803067A8[];
extern u8 lbl_80306938[];
extern s32 lbl_80306758[];
extern u8 *lbl_80346FB8;
extern Ent_801558B0 *lbl_80346FE8;
void fn_801E17E0(s32 x);
extern void *lbl_80346FAC;
void fn_80150CB0(void *a, void *b);
void *fn_8015C4D8(void *p);
void fn_80144680(void *p);
extern s32 lbl_8034704C;
void fn_801453D0(void);
void fn_80158374(void* p);
extern Ent_802E6ACC* lbl_802E6ACC[];
extern char lbl_802B3B9C[];
void fn_8015757C(s32 a, s32 b);
extern void fn_8020EF30(void* p);
extern void fn_80155A8C(void* p);
extern void fn_80109A94(void* p);
extern void* fn_801E1C7C(s32 size);
extern void fn_80217830(void* p);
extern St* lbl_80347000;
extern void* fn_801E1A74(s32 a, s32 size);
extern u32 lbl_80346FBC;
extern u8* lbl_80346FC8[2];
extern void fn_80153978(void);
extern void fn_80152284(void* p);
extern void fn_80154B6C(void);
extern void fn_801539C4(void);
extern void fn_80153730(void);
extern void fn_8014F4E8(void* p);
extern s32 lbl_80347024;
extern void fn_801DBE1C(const char* fmt, ...);
extern const char lbl_802B3F24[];
extern u32 lbl_80347008;
extern u8 lbl_80306C98[];
extern void fn_8025CB24(void* p, ...);
extern E12 lbl_80306B14[];
extern E12 lbl_80308F98[];
extern Obj_8015854C* lbl_80306DB8[];
extern s32 lbl_8034729C;
void fn_80158690(s16 idx);
void fn_80167690(void *p);
extern u32 lbl_802E7090[];

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

void fn_801558B0(Src* s) {
    Ent_801558B0* e = lbl_80346FE8 + s->idx;
    e->a = s->a;
    e->b = s->b;
    e->c = s->c;
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
