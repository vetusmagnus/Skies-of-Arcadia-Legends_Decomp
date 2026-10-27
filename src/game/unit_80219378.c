#include "types.h"
extern void fn_802193BC(s32 a, s32 b);
extern s32 fn_801D168C(void);
extern void fn_801D150C(s32 v);
extern s32 fn_80219B7C(void);
typedef struct Obj_UNIT0000 { u8 pad[4]; u32 count; } Obj_UNIT0000;
extern void fn_80298FE4(s32 v);
typedef void (*VoidFn)(void);
typedef struct Node_UNIT0000 { u32 val; struct Node_UNIT0000 *next; } Node_UNIT0000;
typedef struct Blk_UNIT0000 {
    Node_UNIT0000 *head;
    u32 f4;
    Node_UNIT0000 sentinel;
} Blk_UNIT0000;
extern Blk_UNIT0000 lbl_80311A78;
typedef struct Rec_UNIT0000 {
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
} Rec_UNIT0000;
typedef struct Owner_UNIT0000 { u8 pad[0x18]; Rec_UNIT0000 *recs; } Owner_UNIT0000;
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
typedef struct Blk2_UNIT0000 { s32 f0; s32 f4; u8 pad[0x18]; } Blk2_UNIT0000;
extern Blk2_UNIT0000 lbl_803167F0;
typedef struct P_UNIT0000 { u8 pad[0x1c]; s32 f1c; } P_UNIT0000;
extern void fn_801CBBAC(void*p, f32 f);
extern void fn_801CBB9C(void*p, f32 f);
extern s32 lbl_80347EB0;
extern s32 lbl_80347EA8;
extern s32 lbl_80347EB4;
extern void njUnitMatrix(void *m);
extern void fn_8028BAEC(void *p);
typedef struct Pos_UNIT0000 { u8 pad0[0x1c]; s32 f1c; s32 f20; u8 pad1[0x10]; s32 f34; } Pos_UNIT0000;
extern Pos_UNIT0000 lbl_80311970;
extern void njRotateZXY(void *m, s32 x, s32 y, s32 z);
typedef struct Vec { f32 x; f32 y; f32 z; } Vec;
extern double atan2(double y, double x);
extern s32 lbl_80347520;
typedef struct Node {
    u8 pad0[0x10];
    u16 mask10;
    u16 id12;
    s16 flag14;
    u8 pad16[0x2c - 0x16];
    struct Node *prev;
    struct Node *next;
} Node;
extern Node *lbl_80347524;
extern u16 lbl_8034751C;
void fn_80222964(void *p);
void fn_801E17E0(void *p);
typedef struct Rec_80225930 {
    u8 pad0[0x24];
    s16 f24;
    s16 f26;
    s16 f28;
    s16 f2a;
    s16 f2c;
    s16 f2e;
    s16 f30;
} Rec_80225930;
typedef unsigned int u32_80226240;
extern u32_80226240 lbl_80347580;
typedef unsigned int u32_80226268;
extern u32_80226268 lbl_80347588;
extern void fn_80226984(void *p);
typedef unsigned int u32_80226298;
extern u32_80226298 lbl_8034758C;
extern u32_80226298 lbl_803475A4;
typedef unsigned int u32_80226318;
extern u32_80226318 lbl_803475A4;
extern u32_80226318 lbl_80347580;
extern u32_80226318 lbl_8034758C;
typedef unsigned int u32_80226334;
extern u32_80226334 lbl_803475A8;
extern u32_80226334 lbl_80347590;
extern u32_80226334 lbl_80347594;
extern u32_80226334 lbl_80347598;
typedef int s32_80227E74;
extern s32_80227E74 lbl_803477FC;
typedef unsigned long u32_8022823C;
extern void *memset(void *dst, int c, u32_8022823C n);
typedef struct Unk_8022828C {
    int unk0;
    f32 f4;
    f32 f8;
    f32 fc;
    f32 f10;
    f32 f14;
    f32 f18;
} Unk_8022828C;
typedef struct Unk_802282A8 {
    int unk0;
    int unk4;
    int unk8;
    int unkc;
    f32 f10;
} Unk_802282A8;
typedef unsigned int u32_802282B0;
typedef unsigned int u32_80228374;
extern void fn_801E17E0(void *p);
typedef struct Unk_80228418 {
    u8 pad[0x18];
    u8 *table;
} Unk_80228418;
extern u8 lbl_80316578[];
extern void OSCancelAlarm(void *alarm);
extern void fn_801D8B2C(void);
extern void fn_8022642C(void);
typedef struct SoalState { u8 pad[0xc]; s32 state; } SoalState;
extern SoalState lbl_80311AD4;
typedef unsigned int u32_8022A36C;
extern u32_8022A36C lbl_80347820;
extern u32_8022A36C lbl_80347824;
extern void *memcpy(void *dst, const void *src, unsigned long n);
extern u8 lbl_803165C8[];
typedef int s32_8022B014;
extern s32_8022B014 lbl_80347508;
typedef int s32_8022B064;
extern s32_8022B064 lbl_80347508;
extern s32 fn_801DCFA0(void *a, void *b);
typedef struct Fx {
    u8 pad0[0xc];
    f32 f0c;
    f32 f10;
    f32 f14;
    f32 f18;
} Fx;
s32 fn_80225958(s32 c);
s32 fn_8022377C(void *a, void *b, s32 r, s32 c);
typedef struct Ent68 {
    u8 pad0[0x18];
    u32 *list;
    u8 pad1c[0x68 - 0x1c];
} Ent68;
typedef struct Thing {
    u8 pad0[0x24];
    s16 a24;
    s16 a26;
    s16 a28;
    s16 a2a;
    s16 a2c;
    s16 a2e;
    s16 a30;
} Thing;
void *fn_801E1C7C(u32 size);
typedef struct Slot {
    void *p0;
    void *ptr4;
    u16 key8;
    u8 pad[6];
} Slot;
extern Slot *lbl_8034752C;
extern s16 lbl_8034752A;
extern s16 lbl_80347528;
s16 fn_80225E58(Slot *tbl, s16 n, u32 key);
typedef struct Sub802281DC { s32 a; s32 b[8]; u8 pad[0x44 - 0x24]; s32 z44; } Sub802281DC;
typedef struct Ctx802281DC { s32 a0; s32 a4; s32 a8; Sub802281DC *sub; s32 a10; s32 a14; } Ctx802281DC;
typedef struct C2 { u8 pad[0x20]; void *p20; } C2;
typedef struct C1 { u8 pad[4]; C2 *p4; } C1;
typedef struct C0 { u8 pad[0x35c]; C1 *p35c; } C0;
extern C0 *lbl_8034784C;
extern f32 lbl_8034C640;
extern f32 lbl_8034C65C;
extern void fn_801D5DD8(s32 a, s32 b, s32 c, void *p, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5, f32 f6);
typedef struct TexInner { u8 pad[0x20]; void *list; } TexInner;
typedef struct TexRoot { u8 pad[4]; TexInner *inner; } TexRoot;
typedef struct Obj8 { s32 pad0; s32 a4; s32 a8; } Obj8;
extern TexRoot *lbl_80347854;
extern void fn_802275A4(void *list, s32 a);
extern void fn_801CBBF8(void);
typedef struct Flags8 { u8 pad[8]; u32 f8; } Flags8;
typedef struct Ref { Flags8 *p; u8 pad[0x18 - 4]; } Ref;
extern Ref lbl_80311A60;
extern u8 lbl_802F9238[];
extern void *TextPrint(s16 x, s16 y, const char *str);
typedef struct Obj1E4 { u8 pad[8]; s32 a8; u8 pad2[0x10]; s32 a1c; } Obj1E4;
s32 fn_80222B30(Node *a, Node *b);
extern s32 lbl_80347848;
extern s32 fn_801D8D18(void);
typedef struct Flags88 { u8 pad[0x88]; u32 f88; } Flags88;
extern Flags88 lbl_80310B3C;
extern s32 lbl_803475D4;
extern u8 lbl_8030A794[];
extern void fn_801CAF30(void);
extern void fn_801F01E4(void);
extern void fn_801E0FD4(void *p, s32 n);
extern void fn_801F7B04(s32 a);
extern void fn_8022AFD0(void);
extern TexRoot *lbl_80347850;
extern void fn_801A372C(void);
extern u8 lbl_802D973C[];
extern u8 lbl_802D9750[];
extern TexRoot *fn_801DB244(void *p);
extern void fn_80227810(void *list);
extern void fn_801DBA58(u32 a, u32 b, u32 c);
extern void fn_801CBC30(void);
extern void fn_801CBBBC(void);
extern void njRotateXYZ(void *m, s32 x, s32 y, s32 z);

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

extern void *lbl_80346720;
extern void fn_80005AD8(void *p, void *q);
void fn_8021A044(void *p) {
    fn_80005AD8(lbl_80346720, p);
}

extern void fn_80005B50(void *p, void *q);
void fn_8021A06C(void *p) {
    fn_80005B50(lbl_80346720, p);
}

s32 fn_8021A094(void) {
    return 0;
}

void fn_8021EDE0(Obj_UNIT0000 *p, s32 n)
{
    if (p->count <= (u16)n) {
        n = (s16)(p->count - 1);
    }
    fn_80298FE4((s16)n);
}

extern u32 lbl_802F89A8[];
u32 fn_802205C8(s16 i)
{
    return lbl_802F89A8[i];
}

typedef struct { float x, y, z; } Vec3;
void fn_80221048(Vec3 *v)
{
    int i, j;
    Vec3 t1, t7, t6, t5, t4, t3, t2;

    for (i = 0; i < 7; i++) {
        for (j = i + 1; j < 8; j++) {
            if (v[i].y < v[j].y) {
                t1 = v[j];
                v[j] = v[i];
                v[i] = t1;
            }
        }
    }
    for (i = 0; i < 3; i++) {
        for (j = i + 1; j < 4; j++) {
            if (v[i].x > v[j].x) {
                t2 = v[j];
                v[j] = v[i];
                v[i] = t2;
            }
        }
    }
    for (i = 4; i < 7; i++) {
        for (j = i + 1; j < 8; j++) {
            if (v[i].x > v[j].x) {
                t3 = v[j];
                v[j] = v[i];
                v[i] = t3;
            }
        }
    }
    if (v[0].z < v[1].z) { t4 = v[1]; v[1] = v[0]; v[0] = t4; }
    if (v[2].z > v[3].z) { t5 = v[3]; v[3] = v[2]; v[2] = t5; }
    if (v[4].z < v[5].z) { t6 = v[5]; v[5] = v[4]; v[4] = t6; }
    if (v[6].z > v[7].z) { t7 = v[7]; v[7] = v[6]; v[6] = t7; }
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

extern u32_80226240 lbl_80347584;
void fn_80226254(void *p) {
    if (p == 0) {
        for (;;) {}
    }
    lbl_80347584 = (u32_80226240)p;
}

void fn_802262B0(void *p) {
    if (p == 0) {
        for (;;) {}
    }
    lbl_80347590 = (u32_80226298)p;
    lbl_803475A8 = (u32_80226298)p;
}

void fn_802262C8(void *p) {
    if (p == 0) {
        for (;;) {}
    }
    lbl_80347594 = (u32_80226240)p;
}

void fn_802262DC(void *p) {
    if (p == 0) {
        for (;;) {}
    }
    lbl_80347598 = (u32_80226240)p;
}

extern u32_80226240 lbl_8034759C;
void fn_802262F0(void *p) {
    if (p == 0) {
        for (;;) {}
    }
    lbl_8034759C = (u32_80226240)p;
}

extern u32_80226240 lbl_803475A0;
void fn_80226304(void *p) {
    if (p == 0) {
        for (;;) {}
    }
    lbl_803475A0 = (u32_80226240)p;
}

void *fn_80226354(void *target)
{
    Node_UNIT0000 *n = &lbl_80311A78.sentinel;
    lbl_80311A78.head = n;
    while ((n = n->next) != 0) {
        if (n == target) {
            return n;
        }
    }
    return 0;
}

typedef struct Msg {
    s16 x0;
    s16 x2;
    s16 x4;
    s16 x6;
    s32 x8;
    s32 xc;
} Msg;
extern void fn_802979B8(Msg*, s16);
extern s32 lbl_803477F4;
void fn_8022697C(s32 v) {
    lbl_803477F4 = v;
}

void fn_802281BC(Msg* a, s16 i) {
    fn_802979B8(a, i);
}

void fn_80228264(void *p) {
    memset(p, 0, 0x1c);
}

void fn_802287BC(Owner_UNIT0000 *o, s32 idx, s32 a, f32 b, s32 c, f32 d, f32 e, f32 f, f32 g, s32 h)
{
    Rec_UNIT0000 *r = &o->recs[idx];
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

void fn_80228914(void) {
    lbl_803474A0 = 0;
}

void fn_80228920(s32 v) {
    lbl_803474A0 = v;
}

s32 fn_80228928(void) {
    return lbl_803474A0;
}

void fn_80228930(void) {
    lbl_80347808 = 0;
}

void fn_8022893C(void) {
    lbl_80347808 = 1;
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

void fn_80228AD0(void) {
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

extern u32 lbl_80347860;
void fn_8022AE88(void) {
    lbl_80347860 = 1;
}

void fn_8022AFD0(void)
{
    memset(&lbl_803167F0, 0, 0x20);
    lbl_803167F0.f4 = -1;
}

void fn_8022B010(void) {
}

void fn_8022B02C(P_UNIT0000 *p)
{
    fn_801CBBAC(p, 20.0f);
    p->f1c = 4;
}

void fn_8022B07C(P_UNIT0000 *p)
{
    fn_801CBB9C(p, 15.0f);
    p->f1c = 2;
}

void fn_8022B0B4(void) {
}

void fn_8022B960(void *p)
{
    lbl_80347EB4 = lbl_80347EB0;
    lbl_80347EA8 = 1;
    njUnitMatrix(0);
    fn_8028BAEC(p);
}

extern f32 lbl_803119E0[8];
extern u8 lbl_80316810[0x20];
void fn_8022B9A8(void) {
    MemCopy(lbl_803119E0, lbl_80316810, 0x20);
}

void fn_8022B9DC(void) {
    MemCopy(lbl_80316810, lbl_803119E0, 0x20);
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

s32 fn_8021A09C(s32 v) {
    s32 r = 0;
    if (v >= 0 && v < 0x2d) {
        r = 1;
    }
    return r;
}

s32 fn_8021A0DC(s32 v) {
    s32 r = 0;
    if (v >= 0x190 && v <= 0x1b7) {
        r = 1;
    }
    return r;
}

s32 fn_8021A0FC(s32 v) {
    s32 r = 0;
    if (v >= 0 && v < 5) {
        r = 1;
    }
    return r;
}

s32 fn_8021A5F0(s32 a, s32 b, u8 *p) {
    s32 r = 0;
    if (p != 0) {
        r = *(s8 *)(p + 0x19);
    }
    return r;
}

s32 fn_8021A608(s32 a, s32 b, u8 *p) {
    s32 r = 0;
    if (p != 0) {
        r = *(s8 *)(p + 0x18);
    }
    return r;
}

void fn_8022291C(void) {
    lbl_80347520 = 0;
    lbl_80347524 = 0;
    lbl_8034751C = 0;
}

void fn_80222930(void *p) {
    fn_80222964(p);
    fn_801E17E0(p);
}

void fn_80225930(s16 a, s16 b, Rec_80225930 *r) {
    r->f26 = 0;
    r->f24 = 0;
    r->f2a = b;
    r->f28 = a;
    r->f2e = -1;
    r->f2c = -1;
    r->f30 = 0;
}

void fn_80226240(void *p) {
    if (p == 0) {
        for (;;) {}
    }
    lbl_80347580 = (u32_80226240)p;
}

void fn_80226268(void *p) {
    if (p == 0) {
        for (;;) {}
    }
    lbl_80347588 = (u32_80226268)p;
    fn_80226984(p);
}

void fn_80226298(void *p) {
    if (p == 0) {
        for (;;) {}
    }
    lbl_8034758C = (u32_80226298)p;
    lbl_803475A4 = (u32_80226298)p;
}

void fn_80226318(void *p) {
    if (p == 0) {
        for (;;) {}
    }
    lbl_803475A4 = (u32_80226318)p;
    lbl_80347580 = (u32_80226318)p;
    lbl_8034758C = (u32_80226318)p;
}

void fn_80226334(void *p) {
    if (p == 0) {
        for (;;) {}
    }
    lbl_803475A8 = (u32_80226334)p;
    lbl_80347590 = (u32_80226334)p;
    lbl_80347594 = (u32_80226334)p;
    lbl_80347598 = (u32_80226334)p;
}

void fn_80227E74(void) {
    lbl_803477FC++;
}

void fn_8022823C(void *p) {
    memset(p, 0, 0x1c);
}

void fn_8022828C(Unk_8022828C *p, f32 a, f32 b, f32 c, f32 d, f32 e, f32 g) {
    p->f4 = a;
    p->f8 = b;
    p->fc = c;
    p->f10 = d;
    p->f14 = e;
    p->f18 = g;
}

void fn_802282A8(Unk_802282A8 *p, f32 a) {
    p->f10 = a;
}

void fn_802282B0(u32_802282B0 *p) {
    *p = 1;
}

void fn_80228374(u32_80228374 *p) {
    *p = 0;
    fn_801E17E0(p);
}

f32 fn_80228418(Unk_80228418 *p, int i) {
    return *(f32 *)(p->table + i * 0x5c + 8);
}

void fn_80228984(void) {
    OSCancelAlarm(lbl_80316578);
}

void fn_80228B40(void) {
    fn_801D8B2C();
    fn_8022642C();
    lbl_80311AD4.state = 0x11;
}

void fn_8022A36C(void) {
    lbl_80311AD4.state = 6;
    lbl_80347820 = 0;
    lbl_80347824 = 0;
}

void fn_8022A7F4(void) {
    memcpy(lbl_803165C8, (void *)0x80800000, 0x204);
}

void fn_8022A824(void) {
    memcpy((void *)0x80800000, lbl_803165C8, 0x204);
}

void fn_8022B014(u8 *p) {
    if (lbl_80347508 != 0) {
        return;
    }
    *(s32_8022B014 *)(p + 0x1c) = 5;
}

void fn_8022B064(u8 *p) {
    if (lbl_80347508 != 0) {
        return;
    }
    *(s32_8022B064 *)(p + 0x1c) = 0;
}

static inline s32 InRange(s32 v)
{
    s32 r = 0;
    if (v >= 0 && v < 5) {
        r = 1;
    }
    return r;
}

s32 fn_8021A83C(s8 *a, void *b)
{
    s32 ret = 0;

    if (a != NULL && b != NULL) {
        if (InRange(*a)) {
            ret = 0;
        }
    }
    return ret;
}

s32 fn_8022BA10(void *a, void *b)
{
    s32 x = fn_801DCFA0(b, a);
    return (0 <= x) ? (u16)-x : 0;
}

void fn_8021EEF4(Fx *t, s16 kind, f32 v)
{
    t->f0c = v;
    switch (kind) {
    case 1:
        t->f10 = 0.9019608f;
        t->f14 = 0.1254902f;
        t->f18 = 0.1254902f;
        break;
    case 2:
        t->f10 = 0.1254902f;
        t->f14 = 0.98039216f;
        t->f18 = 0.1254902f;
        break;
    case 3:
        t->f10 = 0.078431375f;
        t->f14 = 0.8627451f;
        t->f18 = 0.98039216f;
        break;
    default:
        t->f10 = 1.0f;
        t->f14 = 1.0f;
        t->f18 = 1.0f;
        break;
    }
}

s32 fn_802238E4(void *a, void *b, s32 c)
{
    s32 r = fn_80225958(c);
    if (r != 0) {
        return fn_8022377C(a, b, r, c);
    }
    return 0;
}

s32 fn_80223FB4(Ent68 *t, u32 key, s32 n, s32 m)
{
    Ent68 *p = t;
    s32 i;
    for (i = 0; i < n - 1; i++) {
        u32 *list = p->list;
        s32 c = list[0];
        if (c != 0) {
            u32 *it = list + 1;
            do {
                if (key == *it) {
                    return 1;
                }
                c--;
                it++;
            } while (c > 0);
        }
        p++;
    }
    {
        u32 *list = p->list;
        u32 *it;
        if (list[0] != 0) {
            it = list + 1;
            for (i = 0; i < m; i++) {
                if (key == *it) {
                    return 1;
                }
                it++;
            }
        }
    }
    return 0;
}

Thing *fn_802258BC(s16 x28, s16 x2a, s16 x30)
{
    Thing *p = (Thing *)fn_801E1C7C(0x34);
    if (p != NULL) {
        p->a26 = 0;
        p->a24 = 0;
        p->a2a = x2a;
        p->a28 = x28;
        p->a2e = -1;
        p->a2c = -1;
        p->a30 = x30;
    }
    return p;
}

void fn_80225EDC(void)
{
    Slot *s;
    s32 i;
    for (i = 0; i < lbl_8034752A; i++) {
        s = lbl_8034752C + i;
        if (s->p0 != NULL) {
            fn_801E17E0(s->ptr4);
            s->p0 = NULL;
            s->key8 = 0xFFFF;
        }
    }
    lbl_80347528 = 0;
}

s16 fn_80225F58(u32 key)
{
    Slot *s;
    s16 idx = fn_80225E58(lbl_8034752C, lbl_8034752A, key);
    if (idx >= 0) {
        s = lbl_8034752C + idx;
        fn_801E17E0(s->ptr4);
        s->p0 = NULL;
        s->key8 = 0xFFFF;
        lbl_80347528 = lbl_80347528 - 1;
    }
    return idx;
}

void fn_802281DC(Ctx802281DC *c) {
    Sub802281DC *s = c->sub;
    if (s != 0) {
        s->a = -1;
        s->b[0] = 0; s->b[1] = 0; s->b[2] = 0; s->b[3] = 0;
        s->b[4] = 0; s->b[5] = 0; s->b[6] = 0; s->b[7] = 0;
        s->z44 = 0;
    }
    c->a8 = -1;
    c->a0 = 0;
    c->a4 = 0;
    c->sub = 0;
    c->a14 = 0;
    c->a10 = 0;
}

void *fn_8022839C(s32 n) {
    u8 *p = fn_801E1C7C(n * 0x5c + 0x1c);
    memset(p, 0, 0x1c);
    memset(p, 0, n * 0x5c);
    *(s32 *)p = 1;
    *(u8 **)(p + 0x18) = p + 0x1c;
    *(s16 *)(p + 0x14) = n;
    return p;
}

f32 fn_8022975C(s32 a, s32 b, s32 c, f32 x, f32 y, f32 z, f32 w) {
    fn_801D5DD8(a, b, c, lbl_8034784C->p35c->p4->p20, lbl_8034C640, lbl_8034C640, x, y, z, w);
    return lbl_8034C65C + x;
}

void fn_8022B0B8(Obj8 *o) {
    if (lbl_80347854 != 0) {
        fn_802275A4(lbl_80347854->inner->list, 1);
        fn_801E17E0(lbl_80347854);
        lbl_80347854 = 0;
    }
    fn_801CBBF8();
    fn_8022642C();
    fn_8022642C();
    if (o->a4 != -1) {
        o->a8 = o->a4;
    }
}

void fn_8022B1E4(Obj1E4 *o) {
    TextPrint(0x18, 0xf8, *(const char **)(lbl_802F9238 + 0x5c));
    if (o->a1c == 0) {
        if (lbl_80311A60.p->f8 & 0x100) {
            o->a1c = 3;
            o->a8 = 0;
        }
    }
}

Node *fn_80223104(u16 id, Node *stop)
{
    Node *n;
    for (n = lbl_80347524; n != NULL; n = n->next) {
        if (n == stop) {
            continue;
        }
        if (n->flag14 >= 0 && id == n->id12) {
            if (fn_80222B30(stop, n) == 1) {
                return n;
            }
        }
    }
    return NULL;
}

Node *fn_80223194(u16 id, Node *stop)
{
    Node *n;
    for (n = lbl_80347524; n != NULL; n = n->next) {
        if (n == stop) {
            continue;
        }
        if (n->flag14 >= 0 && (id & n->mask10) == id) {
            if (fn_80222B30(stop, n) == 1) {
                return n;
            }
        }
    }
    return NULL;
}

void fn_80228AD4(void) {
    s32 r = fn_801D8D18();
    lbl_80347848 = r;
    if (r != -1) {
        if (r == 1) {
            lbl_80311AD4.state = 9;
        } else {
            lbl_80311AD4.state = 0x12;
            fn_801DBE6C(6);
        }
        fn_8022642C();
        fn_8022642C();
    }
    fn_8022642C();
}

void fn_80228BE4(void) {
    fn_801CAF30();
    fn_801F01E4();
    fn_801E0FD4(lbl_8030A794, 0xcc0);
    fn_801F7B04(0);
    lbl_803475D4 = 1;
    lbl_80310B3C.f88 |= 0x20;
    fn_8022AFD0();
    lbl_80311AD4.state = 0xf;
}

void fn_8022A2E4(void) {
    s32 st;
    s32 v;
    fn_802275A4(lbl_80347854->inner->list, 1);
    fn_801E17E0(lbl_80347854);
    lbl_80347854 = 0;
    fn_802275A4(lbl_80347850->inner->list, 1);
    fn_801E17E0(lbl_80347850);
    lbl_80347850 = 0;
    fn_801A372C();
    v = lbl_8034781C;
    st = (v & 1) + 7;
    lbl_8034781C = v + 1;
    lbl_80311AD4.state = st;
}

void fn_8022A548(void) {
    lbl_80347854 = fn_801DB244(lbl_802D973C);
    fn_80227810(lbl_80347854->inner->list);
    lbl_80347850 = fn_801DB244(lbl_802D9750);
    fn_80227810(lbl_80347850->inner->list);
    fn_801DBA58(0xff000000, 0xff000000, 0xff000000);
    fn_801CBC30();
    fn_801CBBBC();
    lbl_80311AD4.state = 3;
    lbl_80347820 = 0;
    lbl_80347824 = 0;
}

void fn_8022BB94(void *m, s32 x, s32 y, s32 z) {
    njRotateXYZ(m, x, y, lbl_80311970.f34 + z);
}

void fn_8022BBC4(void *m, s32 x, s32 y, s32 z) {
    njRotateXYZ(m, x, lbl_80311970.f20 + y, z);
}

void fn_8022BBF4(void *m, s32 x, s32 y, s32 z) {
    njRotateXYZ(m, lbl_80311970.f1c + x, y, z);
}

typedef struct Obj_8022394C {
    u8 pad0[0x1c];
    Vec3 *p1c;
    Vec3 *p20;
    u32 *p24;
    Vec3 *p28;
    u32 *p2c;
    Vec3 v30;
    Vec3 v3c;
    u32 w48[3];
    Vec3 v54;
    u32 w60[3];
} Obj_8022394C;

void fn_8022394C(Obj_8022394C *o)
{
    Vec3 *s = o->p1c;
    u32 *w;
    o->v30.x = s->x;
    o->v30.y = s->y;
    o->v30.z = s->z;
    s = o->p20;
    o->v3c.x = s->x;
    o->v3c.y = s->y;
    o->v3c.z = s->z;
    w = o->p24;
    o->w48[0] = w[0];
    o->w48[1] = w[1];
    o->w48[2] = w[2];
}

typedef struct Obj_802239A4 {
    u8 pad0[0x1c];
    Vec3 *p1c;
    Vec3 *p20;
    u32 *p24;
    Vec3 *p28;
    u32 *p2c;
    Vec3 v30;
    Vec3 v3c;
    u32 w48[3];
    Vec3 v54;
    u32 w60[3];
} Obj_802239A4;

void fn_802239A4(Obj_802239A4 *o)
{
    Vec3 *s = o->p1c;
    u32 *w;
    o->v30.x = s->x;
    o->v30.y = s->y;
    o->v30.z = s->z;
    s = o->p20;
    o->v3c.x = s->x;
    o->v3c.y = s->y;
    o->v3c.z = s->z;
    s = o->p28;
    o->v54.x = s->x;
    o->v54.y = s->y;
    o->v54.z = s->z;
    w = o->p24;
    o->w48[0] = w[0];
    o->w48[1] = w[1];
    o->w48[2] = w[2];
    w = o->p2c;
    o->w60[0] = w[0];
    o->w60[1] = w[1];
    o->w60[2] = w[2];
}

extern void (*lbl_802F91AC[])(void);
extern void fn_801A3510(void);

void fn_80228A20(void) {
    s32 st = lbl_80311AD4.state;
    if (st >= 9 && st <= 13) {
        fn_801A3510();
    }
    if (lbl_80347858 != (st = lbl_80311AD4.state)) {
        lbl_80347818 = 0;
    }
    lbl_80347858 = st;
    lbl_802F91AC[st]();
}
