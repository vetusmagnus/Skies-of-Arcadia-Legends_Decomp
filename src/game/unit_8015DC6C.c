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
s32 fn_801F4CA0();
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
typedef struct { u8 pad[4]; u32 f4; } I1c8;
typedef struct { u8 pad[0x1c8]; I1c8 *p1c8; } Obj_8015F218;
typedef struct { s32 f0; void *p4; } Sub0;
typedef struct { u8 pad[8]; u32 f8; Sub0 *pc; } Res;
Res *fn_800CCA6C(s32 kind, u32 v);
void fn_80210B44(void *p);
typedef struct { u8 pad[0x178]; s32 f178; } Inner_8015F654;
typedef struct { u8 pad[0x16c]; s16 h16c; u8 pad2[0x1d8 - 0x16e]; Inner_8015F654 *p1d8; } Obj_8015F654;
void fn_800A0028(void *p);
typedef struct { u8 pad[0x24]; void *p24; } Mid;
typedef struct { u8 pad[4]; Mid *p4; u8 pad2[0x170]; s32 f178; } Inner_801601AC;
typedef struct {
    u8 pad0[0xb4];
    f32 fb4, fb8, fbc;
    u32 fc0, fc4, fc8;
    u8 pad1[0x16c - 0xcc];
    s16 h16c;
    u8 pad2[0x1d8 - 0x16e];
    Inner_801601AC *p1d8;
} Obj_801601AC;
extern void fn_80222838(void* p);
typedef struct Sub {
    u8 pad0[0x18];
    f32* pos;
    u8 pad1[4];
    u32* words;
} Sub;
typedef struct Obj_801671C0 {
    u8 pad0[0x38];
    f32 pos[3];
    u32 vals[3];
    u8 pad1[0x1bc - 0x50];
    Sub* sub;
} Obj_801671C0;
typedef struct C {
    u8 pad0[0x14];
    s32 x14;
    s32 x18;
} C;
typedef struct B {
    u8 pad0[0x2c];
    C* x2c;
} B;
typedef struct A {
    u8 pad0[0x54];
    s32 x54;
    s32 x58;
    s32 x5c;
    s32 x60;
    s32 x64;
    u8 pad1[0x84 - 0x68];
    B* x84;
} A;
typedef struct Obj_80167374 {
    u8 pad0[0x1d8];
    A* x1d8;
} Obj_80167374;
typedef struct Table {
    u8* entries;
    u32 count;
} Table;
typedef struct Holder_80167428 {
    u8 pad0[0x20];
    Table* table;
} Holder_80167428;
typedef struct Node_80167428 {
    u8 pad0[0x1c8];
    Holder_80167428* holder;
    u8 pad1[4];
    struct Node_80167428* next;
} Node_80167428;
extern Task* lbl_8034708C;
typedef struct TaskWork_80168B7C {
    u8 pad0[4];
    u32 id;
    u8 pad1[0x34 - 8];
    Task* link;
} TaskWork_80168B7C;
extern void* memset(void*, int, unsigned long);
extern u8 lbl_80347080[8];
extern u8 lbl_80347078[8];
typedef struct TaskWork_80169294 {
    u8 pad0[0x34];
    Task* link;
} TaskWork_80169294;
extern u32 lbl_80347088;
extern u32 lbl_80306F58[6];
typedef struct Mover {
    f32 x0;
    f32 x4;
    f32 x8;
    f32 xc;
    f32 x10;
    f32 x14;
    s32 x18;
} Mover;
extern u8 lbl_80310A1C[0x120];
extern void fn_8016B638(s8 k);
extern void fn_8016C4C8(s8 k);
extern void fn_8016D034(s8 k);
extern void fn_8016ADD4(s8 k);
extern void fn_8016EB4C(s32 a);
extern void fn_8016EA60(s32 a);
extern void fn_8016E96C(s32 a);
extern void fn_8016E878(s32 a);
extern void fn_80195EA4(void* out, s32 a, s32 b, s32 c, s32 d);
typedef struct Target {
    u8 pad0[0x1c];
    s32 x1c;
    s32 x20;
} Target;
typedef struct Holder_80187F30 {
    Target* target;
    u8 b4;
} Holder_80187F30;
extern void fn_80189958(void* p, void* local, s32 a4, s8 a5, u8 b0, s8 a7);

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

s32 fn_8015F218(Obj_8015F218 *o) {
    Res *r;
    Sub0 *s;
    s32 n;
    if (o != 0 && o->p1c8 != 0) {
        r = fn_800CCA6C(9, (u16)o->p1c8->f4);
        if (r != 0) {
            s = r->pc;
            s->f0 = 2;
            n = r->f8 >> 16;
            if (n < 3) {
                fn_80210B44(s->p4);
            }
            return n;
        }
    }
    return 0;
}

void fn_8015F654(Obj_8015F654 *o) {
    Inner_8015F654 *r31 = o->p1d8;
    if (r31 != 0) {
        if (r31->f178 == 1 || r31->f178 == 3) {
            r31->f178 = 2;
            fn_800A0028(o);
            r31->f178 = 0;
            o->h16c = 0;
        }
    }
}

void fn_801601AC(Obj_801601AC *o) {
    if (o != 0) {
        Inner_801601AC *r31 = o->p1d8;
        s32 st = r31->f178;
        void *q = r31->p4->p24;
        if (st == 3) {
            r31->f178 = 2;
            fn_800A0028(q);
            r31->f178 = 0;
            o->h16c = 0;
            o->fb4 = 0.0f;
            o->fb8 = 0.0f;
            o->fbc = 0.0f;
            o->fc0 = 0;
            o->fc4 = 0;
            o->fc8 = 0;
        }
    }
}

void fn_801671C0(Obj_801671C0* obj)
{
    Sub* sub;
    if (obj != NULL && (sub = obj->sub) != NULL) {
        f32* pos = sub->pos;
        f32 x = obj->pos[0];
        f32 y = obj->pos[1];
        f32 z = obj->pos[2];
        pos[2] = z;
        pos[1] = y;
        pos[0] = x;
        obj->sub->words[0] = obj->vals[0];
        obj->sub->words[1] = obj->vals[1];
        obj->sub->words[2] = obj->vals[2];
        fn_80222838(obj->sub);
    }
}

void fn_80167374(Obj_80167374* obj)
{
    A* a = obj->x1d8;
    B* b;
    C* c;
    if (a == NULL) {
        return;
    }
    b = a->x84;
    if (b == NULL) {
        return;
    }
    c = b->x2c;
    if (c == NULL) {
        return;
    }
    c->x14 -= a->x60;
    b = a->x84;
    c = b->x2c;
    c->x18 -= a->x64;
    a->x58 = 0;
    a->x54 = 0;
    a->x64 = 0;
    a->x60 = 0;
}

void* fn_80167428(Node_80167428* node, u32 idx)
{
    Table* t = node->holder->table;
    Node_80167428* cur;

    if (idx < t->count) {
        return t->entries + idx * 12;
    }
    cur = node->next;
    while (cur != NULL) {
        t = cur->holder->table;
        if (idx < t->count) {
            return t->entries + idx * 12;
        }
        cur = cur->next;
    }
    return NULL;
}

void fn_80168B7C(u32 id)
{
    TaskWork_80168B7C* w;
    Task* t;
    Task* next;
    if (id == 0) {
        return;
    }
    t = lbl_8034708C;
    while (t != NULL) {
        w = t->work;
        next = w->link;
        if (w->id == id) {
            TaskDelete(t);
            return;
        }
        t = next;
    }
}

void fn_80169294(void)
{
    Task* t = lbl_8034708C;
    while (t != NULL) {
        TaskWork_80169294* w = t->work;
        Task* next = w->link;
        TaskDelete(t);
        t = next;
    }
    memset(lbl_80347080, 0x40, 8);
    memset(lbl_80347078, 0x40, 8);
}

void fn_801692F8(void)
{
    lbl_8034708C = 0;
    lbl_80347088 = 0;
    lbl_80306F58[1] = 0;
    lbl_80306F58[0] = 0;
    lbl_80306F58[3] = 0;
    lbl_80306F58[2] = 0;
    lbl_80306F58[5] = 0;
    lbl_80306F58[4] = 0;
    memset(lbl_80347080, 0x40, 8);
    memset(lbl_80347078, 0x40, 8);
}

s32 fn_8016AA0C(Mover* m)
{
    if (m->x18 <= 0) {
        m->x0 = m->x8;
        m->x4 = m->xc;
        return 1;
    }
    m->x0 = m->x0 + m->x10;
    m->x4 = m->x4 + m->x14;
    m->x18 = m->x18 - 1;
    return 0;
}

void fn_8016AC18(void)
{
    s32 k;
    switch ((s8)lbl_80310A1C[6]) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 7:
    case 12:
        k = 0;
        break;
    case 6:
    case 8:
    case 9:
        k = 2;
        break;
    case 10:
    case 11:
    case 13:
    case 14:
    case 15:
    case 16:
        k = 3;
        break;
    }
    fn_8016B638((s8)k);
    fn_8016C4C8((s8)k);
    if (k == 1) {
        fn_8016D034((s8)k);
    }
}

void fn_8016ACA0(void)
{
    s32 k;
    switch ((s8)lbl_80310A1C[6]) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 7:
    case 12:
        k = 0;
        break;
    case 6:
    case 8:
    case 9:
        k = 2;
        break;
    case 10:
    case 11:
    case 13:
    case 14:
    case 15:
    case 16:
        k = 3;
        break;
    }
    fn_8016ADD4((s8)k);
}

void fn_8016E818(s32 a, s32 mode)
{
    switch (mode) {
    case 0:
        fn_8016EB4C(a);
        break;
    case 1:
        fn_8016EA60(a);
        break;
    case 2:
        fn_8016E96C(a);
        break;
    case 3:
        fn_8016E878(a);
        break;
    }
}

s32 fn_801812C0(void)
{
    s32 buf[0x20];
    s32 off = *(s32*)(lbl_80307638 + 0x7c);
    s8 v = (s8)lbl_8030B7F4[off + 0x328];
    s8 r;
    fn_80195EA4(buf, v, 0, 0, 2);
    r = ((s8*)buf)[0xb];
    return r;
}

void fn_80187F30(Holder_80187F30* h, Target* t)
{
    h->b4 = fn_801F4CA0();
    h->target = t;
    h->target->x1c = (s8)h->b4;
    h->target->x20 = (s8)h->b4;
}

void fn_80189900(u8* p, s32 a4, s32 a5, s32 a6, s32 a7)
{
    u8 local[0x80];
    s8 r;
    p[0] = a6;
    r = (s8)a5;
    p[2] = a4;
    p[1] = a5;
    if (r == -1) {
        p[3] = 0;
    } else {
        fn_80189958(p, local, a4, (s8)a5, p[0], (s8)a7);
    }
}
