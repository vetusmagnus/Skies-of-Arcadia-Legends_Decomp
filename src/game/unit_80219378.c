

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern void fn_802193BC(s32 a, s32 b);
extern s32 fn_801D168C(void);
extern void fn_801D150C(s32 v);
extern s32 fn_80219B7C(void);
typedef struct Obj { u8 pad[4]; u32 count; } Obj;
extern void fn_80298FE4(s32 v);
typedef void (*VoidFn)(void);
typedef struct Node { u32 val; struct Node *next; } Node;
typedef struct Blk {
    Node *head;
    u32 f4;
    Node sentinel;
} Blk;
extern Blk lbl_80311A78;
typedef struct Rec {
    u32 active;
    s32 a;
    f32 b;
    s32 c;
    s32 h;
    f32 d;
    f32 e;
    f32 f;
    f32 g;
    u8 pad[0x5c - 0x24];
} Rec;
typedef struct Owner { u8 pad[0x18]; Rec *recs; } Owner;
extern s32 lbl_803474A4;
extern s32 lbl_803475CC;
extern s32 lbl_80347808;
extern s32 lbl_803474A0;
extern s32 lbl_80347858;
extern s32 lbl_80347818;
extern s32 lbl_8034781C;
extern s32 lbl_8034782C;
extern void fn_801D0B2C(void);
extern u8 lbl_802D9724[];
extern void fn_80100178(u8 *p);
extern void fn_801DBE6C(s32 a);
extern void fn_801E1D94(void);
extern void fn_801D14F8(void);
extern u8 lbl_802D9730[];
extern void fn_801D0B38(s32 a);
typedef struct Blk2 { s32 f0; s32 f4; u8 pad[0x18]; } Blk2;
extern Blk2 lbl_803167F0;
extern void *memset(void *s, s32 c, u32 n);
typedef struct P { u8 pad[0x1c]; s32 f1c; } P;
extern void fn_801CBBAC(P *p, f32 f);
extern void fn_801CBB9C(P *p, f32 f);
extern s32 lbl_80347EB0;
extern s32 lbl_80347EA8;
extern s32 lbl_80347EB4;
extern void njUnitMatrix(void *m);
extern void fn_8028BAEC(void *p);
typedef struct Pos { u8 pad0[0x1c]; s32 f1c; s32 f20; u8 pad1[0x10]; s32 f34; } Pos;
extern Pos lbl_80311970;
extern void njRotateZXY(void *m, s32 x, s32 y, s32 z);
typedef struct Vec { f32 x; f32 y; f32 z; } Vec;
extern double atan2(double y, double x);

void fn_80219378(s32 a)
{
    fn_802193BC(a, 0);
    while (fn_80219B7C() != 0) {
        s32 v = fn_801D168C();
        if (v != -1) {
            fn_801D150C(v);
        }
    }
}

void fn_8021EDE0(Obj *p, s32 n)
{
    if (p->count <= (u16)n) {
        n = (s16)(p->count - 1);
    }
    fn_80298FE4((s16)n);
}

void fn_802260E8(void *p)
{
    if (p) {
        VoidFn f = *(VoidFn *)p;
        if (f) {
            f();
        }
    }
}

void *fn_80226354(void *target)
{
    Node *n = &lbl_80311A78.sentinel;
    lbl_80311A78.head = n;
    while ((n = n->next) != 0) {
        if (n == target) {
            return n;
        }
    }
    return 0;
}

void fn_802287BC(Owner *o, s32 idx, s32 a, f32 b, s32 c, f32 d, f32 e, f32 f, f32 g, s32 h)
{
    Rec *r = &o->recs[idx];
    r->active = 1;
    r->a = a;
    r->b = b;
    r->c = c;
    r->d = d;
    r->e = e;
    r->f = f;
    r->g = g;
    r->h = h;
}

void fn_80228948(void)
{
    lbl_803474A4 = lbl_803474A4 + 1;
    if (lbl_803475CC == 6 || lbl_803475CC == 7) {
        if (lbl_80347808 != 1) {
            lbl_803474A0 = lbl_803474A0 + 1;
        }
    }
}

void fn_80228A98(void)
{
    lbl_80347858 = -1;
    lbl_80347818 = 0;
    lbl_8034781C = 0;
    lbl_8034782C = 0;
    fn_801D0B2C();
}

void fn_8022A25C(void)
{
    lbl_8034782C = 1;
    fn_80100178(lbl_802D9724);
    fn_801DBE6C(6);
    fn_801E1D94();
    fn_801D14F8();
}

void fn_8022A29C(void)
{
    lbl_8034782C = 1;
    fn_80100178(lbl_802D9730);
    fn_801DBE6C(6);
    fn_801D0B38(0x5000);
    fn_801E1D94();
    fn_801D14F8();
}

void fn_8022AFD0(void)
{
    memset(&lbl_803167F0, 0, 0x20);
    lbl_803167F0.f4 = -1;
}

void fn_8022B02C(P *p)
{
    fn_801CBBAC(p, 20.0f);
    p->f1c = 4;
}

void fn_8022B07C(P *p)
{
    fn_801CBB9C(p, 15.0f);
    p->f1c = 2;
}

void fn_8022B960(void *p)
{
    lbl_80347EB4 = lbl_80347EB0;
    lbl_80347EA8 = 1;
    njUnitMatrix(0);
    fn_8028BAEC(p);
}

void fn_8022BB5C(void *a, s32 b, s32 c, s32 d)
{
    njRotateZXY(a, lbl_80311970.f1c + b, lbl_80311970.f20 + c, d);
}

void fn_8022BC24(void *a, s32 b, s32 c, s32 d)
{
    njRotateZXY(a, lbl_80311970.f1c + b, lbl_80311970.f20 + c, lbl_80311970.f34 + d);
}

s32 fn_8022BD30(Vec *a, Vec *b)
{
    f32 ang = (f32)atan2(a->z - b->z, a->x - b->x);
    return (s32)(10430.381f * ang);
}

s32 fn_8022BD80(Vec *a, Vec *b)
{
    f32 ang = (f32)atan2(a->y - b->y, a->z - b->z);
    return (s32)(10430.381f * ang);
}
