#include "types.h"
#include "game/task.h"
#include "game/menu.h"
#include "ninja.h"
#include "game/uiobj.h"

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
void fn_800A0028();
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
typedef struct Sub_UNIT0000 {
    u8 pad0[0x18];
    f32* pos;
    u8 pad1[4];
    u32* words;
} Sub_UNIT0000;
typedef struct Obj_801671C0_UNIT0000 {
    u8 pad0[0x38];
    f32 pos[3];
    u32 vals[3];
    u8 pad1[0x1bc - 0x50];
    Sub_UNIT0000* sub;
} Obj_801671C0_UNIT0000;
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
typedef struct {
    u8 pad0[0x2c];
    u32 owner;        /* 0x2C */
} Node8015F2E8;
typedef struct {
    u8 pad0[0x84];
    Node8015F2E8* n84;
    Node8015F2E8* n88;
    Node8015F2E8* n8c;
    u8 pad1[0x94 - 0x90];
    s32 f94;          /* 0x94 */
    u8 pad2[0xe0 - 0x98];
    s32 fe0;          /* 0xE0 */
    u8 pad3[0x12c - 0xe4];
    s32 f12c;         /* 0x12C */
} Obj8015F2E8;
extern Obj8015F2E8* lbl_80347070;
extern void fn_80291C44(void* p);
typedef struct {
    u8 pad0[0x16c];
    s16 flag16c;      /* 0x16C */
    u8 pad1[0x1d8 - 0x16e];
    void* link;       /* 0x1D8 */
} Obj8015F6C0;
typedef struct {
    u8 pad0[0x178];
    u32 f178;         /* 0x178 */
    u32 f17c;         /* 0x17C */
    u32 f180;         /* 0x180 */
    f32 v184[3];      /* 0x184 */
    u32 w190[3];      /* 0x190 */
} Link8015F6C0;
extern f32 lbl_8034AA80;
extern void fn_802275A4(void* texlist, s32 a);
extern void fn_801E17E0(void* p);
typedef struct {
    u8 pad00[0x20];
    void* texlist; /* 0x20 */
} Inner_8016AD08;
typedef struct {
    u8 pad00[4];
    Inner_8016AD08* inner; /* 0x04 */
} Ent_8016AD08;
extern Ent_8016AD08* lbl_80347090;
extern Ent_8016AD08* lbl_80347094;
extern Ent_8016AD08* lbl_80347098;
extern Ent_8016AD08* lbl_8034709C;
extern int fn_8025CB24(char* buf, const char* fmt, ...);
extern void* fn_801DB244(void* p);
extern void fn_80227810(void* texlist);
extern void fn_8016B4F0(void);
extern s32 fn_8016AEBC(void* self);
typedef struct {
    u8 pad00[0x18];
    u8 flags;  /* 0x18 */
    u8 state;  /* 0x19 */
    u8 pad1A[6];
    f32 timer; /* 0x20 */
} Self_8016B434;
extern void* fn_802268E8(void* a, void (*f)(void));
extern void* fn_801E1C7C(u32 n);
extern void fn_8016CED8(void);
extern void* lbl_803475A8;
typedef struct { u8 mode; u8 flag1; u8 pad02[2]; f32 f4; f32 f8; u8 pad0C[0x20]; f32 f2c; f32 f30; f32 f34; } Sub_8016D034;
typedef struct { u8 pad00[0x24]; Sub_8016D034* sub; } Owner_8016D034;
extern Owner_8016D034* lbl_803470B8;
extern f32 fn_80291888(f32 x);
typedef struct {
    f32 x0;   /* 0x00 */
    f32 y0;   /* 0x04 */
    f32 sx;   /* 0x08 */
    f32 sy;   /* 0x0C */
    f32 wx;   /* 0x10 */
    f32 wy;   /* 0x14 */
} Wrap;
extern void fn_80199F58(void* p);
extern void fn_8016EF10(void);
extern void CampPanelDrawFrame(void* p);
extern s32 lbl_803475D8;
typedef struct {
    s32 kind;   /* 0x00 */
    u32 pad04;
    UiObj obj;  /* 0x08 */
} Inner_8016EE2C;
typedef struct {
    u8 pad00[0x18];
    u8 flags;    /* 0x18 */
    u8 state;    /* 0x19 */
    u8 pad1A[0x24 - 0x1A];
    Inner_8016EE2C* inner; /* 0x24 */
} Self_8016EE2C;
extern void fn_8016F594(void* p);
typedef struct {
    s32 kind;   /* 0x00 */
    u32 pad04;
    UiObj obj;  /* 0x08 */
} Inner_8016F138;
typedef struct {
    u8 pad00[0x18];
    u8 flags;    /* 0x18 */
    u8 state;    /* 0x19 */
    u8 pad1A[0x24 - 0x1A];
    Inner_8016F138* inner; /* 0x24 */
} Self_8016F138;
extern s32 fn_801944C4(void);
extern void fn_80195A68(void* p, s32 a, s32 b, s32 c, s32 d, s32 e);
typedef struct {
    u8 pad00[4];
    u32 f04;
    u8 pad08[4];
    u32 f0c;
    u8 pad10[0x34];
    u32 f44;
    u8 pad48[4];
    u32 f4c;
    u8 pad50[0x1c];
    u32 f6c;
} MS_8017439C;
extern u8 camp_work[];
extern s32 fn_80194490(void);
extern s32 fn_8019445C(void);
extern void fn_80199BB8(UiObj* obj, f32 x, f32 y);
extern void fn_80199BAC(UiObj* obj, f32 x, f32 y);
extern void fn_80193FF8(s32 n);
extern void fn_80193FBC(s32 unused, s32 toggle);
typedef struct {
    u8 pad00[0x14];
    s32 mode; /* 0x14 */
} MS_801778AC;
extern s32 (*lbl_803467A8[2])(void);
typedef struct {
    u8 pad00[0x0c];
    u32 f0c;
    u8 pad10[0x3c];
    u32 f4c;
} MS_8017B0F8;
typedef struct {
    u8 pad00[0x18];
    s16 x18;
    s16 x1a;
    u8 pad1c[0x5c - 0x1c];
} CampRec;
typedef struct {
    s8* ids;      /* 0x00 */
    void* p04;    /* 0x04 */
    u8 pad08[0x360 - 0x08];
} CampWork;
extern s32 fn_801953B8(void);
extern s32 fn_80194028(void);
typedef struct {
    u8 pad00[0x14];
    s32 x14;
} CampObj;
extern s16 fn_801838C8(s32 a, s32 b);
typedef struct Ctrl {
    u8 pad00[4];
    s32 first;          /* 0x04 */
    u8 pad08[4];
    u32 mask;           /* 0x0C */
    u8 pad10[0x4C - 0x10];
    s32 x4c;            /* 0x4C */
} Ctrl;
typedef struct {
    Ctrl* ctrl;         /* 0x00 */
} CtrlHolder;
typedef struct {
    u8 pad00[0x24];
    CtrlHolder* holder; /* 0x24 */
} Outer;
extern Outer* lbl_8034710C;
extern s32 lbl_803470C8;
extern s32 (*lbl_802E97C0[5])(void);
typedef struct {
    u8 pad00[0x20];
    void* x20;
} Sub20;
typedef struct {
    u8 pad00[4];
    Sub20* x4;
} Obj4;
extern void* lbl_803470DC;
extern void* lbl_803470D8;
extern Obj4* lbl_803470E4;
extern void* lbl_803470E0;
void fn_801D6944(void* p);
void fn_801E17E0(void* p);
void fn_802275A4(void* p, s32 a);
typedef struct {
    f32 f0, f4, f8, fc;
} F4;
typedef struct {
    void* p0;
    void* p4;
} P2;
typedef struct {
    f32 f00, f04;          /* 0x00 */
    s32 i08;               /* 0x08 */
    s32 i0c;               /* 0x0C */
    f32 f10, f14, f18, f1c;
    P2* p20;               /* 0x20 */
    F4* p24;               /* 0x24 */
    u8 pad28[4];
    P2* p2c;               /* 0x2C */
    F4* p30;               /* 0x30 */
    u8 pad34[4];
    P2* p38;               /* 0x38 */
    F4* p3c;               /* 0x3C */
    u8 pad40[4];
    void* p44;             /* 0x44 */
} Obj48;
extern void* lbl_803470F4;
void* fn_801D68C4(void* bank, u32 index);
typedef struct {
    s32 a;
    s32 b;
} Pair8;
typedef struct {
    Pair8 pairs[11];   /* 0x00 */
    u32 mask0;         /* 0x58 */
    u32 mask1;         /* 0x5C */
} PairSet;
extern void* lbl_803470F0;
extern void* lbl_803470E8;
typedef struct {
    s32 kind;
    u8 pad04[4];
    f32 rect8[4];
} Sub_8018DFC4;
typedef struct {
    u8 pad00[0x18];
    u8 flags18;
    u8 state19;
    u8 pad1a[0x24 - 0x1a];
    Sub_8018DFC4* p24;
} Obj_8018DFC4;
void fn_80199F38(void* r);
void fn_8018E73C(Sub_8018DFC4* s);
void fn_8018E0A8(Sub_8018DFC4* s);
extern void* lbl_803470EC;
extern void* lbl_803470F8;
extern Obj4* lbl_80347618;
void fn_801C0FE8(s32 a, s32 b);

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

void fn_801671C0(Obj_801671C0_UNIT0000* obj)
{
    Sub_UNIT0000* sub;
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

void fn_8015F2E8(u32 owner) {
    Obj8015F2E8* o = lbl_80347070;
    Node8015F2E8* n;
    if (o == 0) {
        return;
    }
    n = o->n8c;
    if (n != 0 && n->owner == owner && o->f12c != 0) {
        fn_80291C44((u8*)o + 0x130);
    }
    n = lbl_80347070->n88;
    if (n != 0 && n->owner == owner && o->fe0 != 0) {
        fn_80291C44((u8*)o + 0xe4);
    }
    n = lbl_80347070->n84;
    if (n != 0 && n->owner == owner && o->f94 != 0) {
        fn_80291C44((u8*)o + 0x98);
    }
}

void fn_8015F6C0(Obj8015F6C0* self, u32 a, u32 b, f32* vec, u32* words) {
    Link8015F6C0* link = self->link;
    if (link == 0) {
        return;
    }
    link->f178 = 1;
    self->flag16c = 1;
    link->f17c = a;
    link->f180 = b;
    if (vec != 0) {
        link->v184[0] = vec[0];
        link->v184[1] = vec[1];
        link->v184[2] = vec[2];
    } else {
        f32 z = lbl_8034AA80;
        link->v184[2] = z;
        link->v184[1] = z;
        link->v184[0] = z;
    }
    if (words != 0) {
        link->w190[0] = words[0];
        link->w190[1] = words[1];
        link->w190[2] = words[2];
    } else {
        link->w190[2] = 0;
        link->w190[1] = 0;
        link->w190[0] = 0;
    }
    fn_800A0028();
}

void fn_801600E0(void* dst_, void* src_) {
    u8* dst = dst_;
    u8* src = src_;
    *(f32*)((u8*)dst + 0x38) = *(f32*)((u8*)src + 0x38);
    *(f32*)((u8*)dst + 0x3C) = *(f32*)((u8*)src + 0x3C);
    *(f32*)((u8*)dst + 0x40) = *(f32*)((u8*)src + 0x40);
    *(u32*)((u8*)dst + 0x44) = *(u32*)((u8*)src + 0x44);
    *(u32*)((u8*)dst + 0x48) = *(u32*)((u8*)src + 0x48);
    *(u32*)((u8*)dst + 0x4C) = *(u32*)((u8*)src + 0x4C);
    *(f32*)((u8*)dst + 0x50) = *(f32*)((u8*)src + 0x50);
    *(f32*)((u8*)dst + 0x54) = *(f32*)((u8*)src + 0x54);
    *(f32*)((u8*)dst + 0x58) = *(f32*)((u8*)src + 0x58);
    *(f32*)((u8*)dst + 0x104) = *(f32*)((u8*)src + 0x104);
    *(f32*)((u8*)dst + 0x108) = *(f32*)((u8*)src + 0x108);
    *(f32*)((u8*)dst + 0x10C) = *(f32*)((u8*)src + 0x10C);
    *(u32*)((u8*)dst + 0x110) = *(u32*)((u8*)src + 0x110);
    *(u32*)((u8*)dst + 0x114) = *(u32*)((u8*)src + 0x114);
    *(u32*)((u8*)dst + 0x118) = *(u32*)((u8*)src + 0x118);
    *(f32*)((u8*)dst + 0x11C) = *(f32*)((u8*)src + 0x11C);
    *(f32*)((u8*)dst + 0x120) = *(f32*)((u8*)src + 0x120);
    *(f32*)((u8*)dst + 0x124) = *(f32*)((u8*)src + 0x124);
    *(f32*)((u8*)dst + 0xB4) = *(f32*)((u8*)src + 0xB4);
    *(f32*)((u8*)dst + 0xB8) = *(f32*)((u8*)src + 0xB8);
    *(f32*)((u8*)dst + 0xBC) = *(f32*)((u8*)src + 0xBC);
    *(u32*)((u8*)dst + 0xC0) = *(u32*)((u8*)src + 0xC0);
    *(u32*)((u8*)dst + 0xC4) = *(u32*)((u8*)src + 0xC4);
    *(u32*)((u8*)dst + 0xC8) = *(u32*)((u8*)src + 0xC8);
    *(s16*)((u8*)dst + 0x16C) = *(s16*)((u8*)src + 0x16C);
}

void fn_8016AD08(void) {
    if (lbl_80347090 != 0) {
        fn_802275A4(lbl_80347090->inner->texlist, 1);
        fn_801E17E0(lbl_80347090);
        lbl_80347090 = 0;
    }
    if (lbl_80347094 != 0) {
        fn_802275A4(lbl_80347094->inner->texlist, 1);
        fn_801E17E0(lbl_80347094);
        lbl_80347094 = 0;
    }
    if (lbl_80347098 != 0) {
        fn_802275A4(lbl_80347098->inner->texlist, 1);
        fn_801E17E0(lbl_80347098);
        lbl_80347098 = 0;
    }
    if (lbl_8034709C != 0) {
        fn_802275A4(lbl_8034709C->inner->texlist, 1);
        fn_801E17E0(lbl_8034709C);
        lbl_8034709C = 0;
    }
}

void fn_8016ADD4(s8 type) {
    char buf[0x20];
    s32 v = (type == 3) ? 2 : type;

    fn_8025CB24(buf, "/field/sora0%d.mld", v);
    switch (type) {
    case 0:
        lbl_80347090 = fn_801DB244(buf);
        fn_80227810(lbl_80347090->inner->texlist);
        break;
    case 1:
        lbl_80347094 = fn_801DB244(buf);
        fn_80227810(lbl_80347094->inner->texlist);
        break;
    case 2:
        lbl_80347098 = fn_801DB244(buf);
        fn_80227810(lbl_80347098->inner->texlist);
        break;
    case 3:
        lbl_8034709C = fn_801DB244(buf);
        fn_80227810(lbl_8034709C->inner->texlist);
        break;
    }
}

void fn_8016B434(Self_8016B434* self) {
    switch (self->state) {
    case 0:
    case 0xfe:
        fn_8016B4F0();
        self->state = 1;
        self->timer = -1.3f;
        break;
    case 1:
        if (fn_8016AEBC(self) == 0) {
            self->state = 2;
        }
        break;
    case 2:
        self->state = 0xff;
        break;
    case 0xff:
        self->flags |= 0x40;
        if (lbl_803470A0 != 0) {
            lbl_803470A0 = 0;
        }
        break;
    }
}

void fn_8016D034(s8 mode) {
    lbl_803470B8 = fn_802268E8(lbl_803475A8, fn_8016CED8);
    lbl_803470B8->sub = fn_801E1C7C(0x38);
    if (lbl_803470B8 != 0) {
        lbl_803470B8->sub->f4 = 0.0f;
        lbl_803470B8->sub->f8 = 0.0f;
    }
    if (lbl_803470B8 != 0) {
        lbl_803470B8->sub->flag1 = 1;
    }
    if (lbl_803470B8 != 0) {
        lbl_803470B8->sub->mode = mode;
    }
    switch (mode) {
    case 1:
        lbl_803470B8->sub->f30 = 1.0f;
        lbl_803470B8->sub->f2c = 1.0f;
        lbl_803470B8->sub->f34 = 0.24f;
        break;
    case 0:
        break;
    case 2:
        break;
    }
}

void fn_8016DAC4(s32* out, Wrap* p, f32 x, f32 y) {
    f32 dx = x - p->x0;
    f32 dy = y - p->y0;

    if (0.0f < p->wx) {
        if (0.0f > dx) {
            dx = p->wx + dx;
        } else if (p->wx <= dx) {
            dx -= p->wx;
        }
        if (0.0f > dy) {
            dy = p->wy + dy;
        } else if (p->wy <= dy) {
            dy -= p->wy;
        }
    }
    out[0] = (s32)fn_80291888(dx / p->sx);
    out[1] = (s32)fn_80291888(dy / p->sy);
}

void fn_8016EE2C(Self_8016EE2C* self) {
    UiObj* obj = &self->inner->obj;

    switch (self->state) {
    case 0:
    case 0xfe:
        self->state = 1;
    case 1:
        if (lbl_803475D8 != 0) {
            self->state = 0xff;
        } else {
            fn_80199F38(obj);
            UiObjCalcRect(obj);
            if (self->inner->kind == 1) {
                fn_8016EF10();
                CampPanelDrawFrame(self->inner);
            }
        }
        break;
    case 0x64:
        self->state = 0xff;
        break;
    case 0xff:
        fn_80199F58(self->inner);
        self->flags |= 0x40;
        break;
    }
}

void fn_8016F138(Self_8016F138* self) {
    UiObj* obj = &self->inner->obj;

    if (lbl_803475D8 != 0) {
        self->state = 0xff;
    }
    switch (self->state) {
    case 0:
    case 0xfe:
        self->state = 1;
    case 1:
        fn_80199F38(obj);
        UiObjCalcRect(obj);
        if (self->inner->kind == 1) {
            CampPanelDrawFrame(self->inner);
            fn_8016F594(self->inner);
        }
        break;
    case 0x64:
        self->state = 0xff;
        break;
    case 0xff:
        fn_80199F58(self->inner);
        self->flags |= 0x40;
        break;
    }
}

void fn_8017439C(void) {
    u32 a;
    u32 b;
    MS_8017439C* ms = (MS_8017439C*)lbl_8034710C->holder->ctrl;

    switch (fn_801944C4()) {
    case 0:
        a = 0x3f;
        b = 0xf;
        break;
    case 1:
        a = 0xff;
        b = 0x7ff;
        break;
    }
    ms->f0c = a;
    ms->f4c = b;
    fn_80195A68(ms, 1, 0, 0, 0, 1);
    ms->f6c = 6;
    ms->f04 = 0;
    ms->f44 = 0;
}

void fn_80174444(void) {
    void** arr;
    s32 i;
    s32 j;
    UiObj* obj;

    i = fn_80194490();
    arr = (void**)(camp_work + 0x10);
    obj = (UiObj*)(*(u8**)(*(u8**)&arr[i] + 0x24) + 8);
    fn_80199BB8(obj, -8.0f, 61.0f);
    fn_80199BAC(obj, -8.0f, 61.0f);

    j = fn_8019445C();
    obj = (UiObj*)(*(u8**)(*(u8**)&arr[j] + 0x24) + 8);
    fn_80199BB8(obj, -648.0f, 123.0f);
    fn_80199BAC(obj, -648.0f, 123.0f);

    obj = (UiObj*)(*(u8**)(*(u8**)(camp_work + 0x1ac) + 0x24) + 8);
    fn_80199BB8(obj, 48.0f, 131.0f);
    fn_80199BAC(obj, 48.0f, 131.0f);
}

void fn_801778AC(void) {
    MS_801778AC* ms = (MS_801778AC*)lbl_8034710C->holder->ctrl;

    switch (ms->mode) {
    case 0:
        fn_80193FF8(3);
        break;
    case 1:
        fn_80193FF8(0);
        break;
    case 2:
        fn_80193FF8(1);
        break;
    case 3:
        fn_80193FF8(2);
        break;
    case 4:
        fn_80193FBC(5, 1);
        fn_80193FBC(6, 0);
        fn_80193FBC(7, 0);
        break;
    case 5:
        fn_80193FF8(4);
        break;
    }
}

void fn_80177C98(void) {
    s32 i;
    UiObj* obj;

    for (i = 0; i < 7; i++) {
        obj = (UiObj*)(*(u8**)(*(u8**)(camp_work + 0xdc + i * 4) + 0x24) + 8);
        fn_80199BB8(obj, 668.0f, 204.0f);
        fn_80199BAC(obj, 668.0f, 204.0f);
    }
    obj = (UiObj*)(*(u8**)(*(u8**)(camp_work + 0x194) + 0x24) + 8);
    fn_80199BB8(obj, 328.0f, 204.0f);
    fn_80199BAC(obj, 328.0f, 204.0f);
    obj = (UiObj*)(*(u8**)(*(u8**)(camp_work + 0x190) + 0x24) + 8);
    fn_80199BB8(obj, 632.0f, 480.0f);
    fn_80199BAC(obj, 632.0f, 480.0f);
}

void fn_801792A4(void) {
    s32 i;
    UiObj* obj;

    for (i = 0; i < 7; i++) {
        obj = (UiObj*)(*(u8**)(*(u8**)(camp_work + 0xf8 + i * 4) + 0x24) + 8);
        fn_80199BB8(obj, 668.0f, 204.0f);
        fn_80199BAC(obj, 668.0f, 204.0f);
    }
    obj = (UiObj*)(*(u8**)(*(u8**)(camp_work + 0x198) + 0x24) + 8);
    fn_80199BB8(obj, 328.0f, 204.0f);
    fn_80199BAC(obj, 328.0f, 204.0f);
    obj = (UiObj*)(*(u8**)(*(u8**)(camp_work + 0x190) + 0x24) + 8);
    fn_80199BB8(obj, 632.0f, 480.0f);
    fn_80199BAC(obj, 632.0f, 480.0f);
}

void fn_8017B0F8(void) {
    s32 (**fp)(void);
    s32 i;
    s32 first;
    u32 mask;
    MS_8017B0F8* ms;

    mask = 0;
    first = -1;
    i = 0;
    fp = lbl_803467A8;
    ms = (MS_8017B0F8*)lbl_8034710C->holder->ctrl;
    for (; i < 2; i++) {
        if ((*fp)() != 0) {
            mask |= 1 << i;
            if (first != -1) {
                first = i;
            }
        }
        fp++;
    }
    ms->f0c = mask;
    ms->f4c = 0;
    fn_80195A68(ms, 1, 0, 0, 0, 1);
}

s32 fn_80183750(s8 a)
{
    if (a < 4) {
        CampRec* r = &((CampRec*)lbl_8030B7F4)[((CampWork*)camp_work)->ids[a]];
        return r->x1a > r->x18;
    }
    if (fn_801953B8() == 0) {
        return 0;
    }
    {
        CampObj* o = (CampObj*)((CampWork*)camp_work)->p04;
        s32 v = fn_80194028();
        return o->x14 < v;
    }
}

s32 fn_80183800(s32 a, s32 b)
{
    s16 v = fn_801838C8(a, *((s8*)lbl_8030B7F4 + b + 0x328));
    switch (a) {
    case 0x36: case 0x37: case 0x38: case 0x39: case 0x3a:
        return v < 0x3e7;
    case 0x3b:
        return v < 0x270f;
    case 0x3c:
        return v < 0x63;
    default:
        return 0;
    }
}

void fn_8018564C(void)
{
    s32 i;
    s32 first;
    u32 mask;
    Ctrl* c;

    mask = 0;
    first = -1;
    c = lbl_8034710C->holder->ctrl;
    for (i = 0; i < 5; i++) {
        if (lbl_802E97C0[i]() != 0) {
            mask |= 1 << i;
            if (first == -1) {
                first = i;
            }
        }
    }
    c->mask = mask;
    if (lbl_802E97C0[c->first]() == 0) {
        c->first = first;
    }
    c->x4c = 0;
    fn_80195A68(c, 1, 0, 0, 0, 1);
    lbl_803470C8 = 0;
}

void fn_80186348(void)
{
    if (lbl_803470DC != 0) {
        fn_801D6944(lbl_803470DC);
        fn_801E17E0(lbl_803470DC);
        lbl_803470DC = 0;
    }
    if (lbl_803470D8 != 0) {
        fn_801D6944(lbl_803470D8);
        fn_801E17E0(lbl_803470D8);
        lbl_803470D8 = 0;
    }
    if (lbl_803470E4 != 0) {
        fn_802275A4(lbl_803470E4->x4->x20, 0);
        fn_801E17E0(lbl_803470E4);
        lbl_803470E4 = 0;
    }
    if (lbl_803470E0 != 0) {
        fn_801E17E0(lbl_803470E0);
        lbl_803470E0 = 0;
    }
}

void fn_80186908(Obj48* o)
{
    void* r;

    o->f00 = -3940.0f;
    o->f04 = 0.0f;
    o->f10 = 1.0f;
    o->f14 = 1.0f;
    o->f18 = 1.0f;
    o->f1c = 0.0f;
    o->i08 = 1;
    o->i0c = 0;
    r = fn_801D68C4(lbl_803470F4, 0x4c);
    fn_8019A15C(o, 0, 1, 0);
    o->p38->p0 = r;
    o->p3c->f0 = 36.0f;
    o->p3c->f4 = 31.0f;
    o->p44 = 0;
}

void fn_801869B8(PairSet* o, Pair8* src)
{
    s32 i;

    o->mask0 = 0;
    o->mask1 = 0;
    for (i = 0; i < 11; i++) {
        u32 bit = 1 << i;

        o->pairs[i].a = src[i].a;
        if (src[i].a != -1) {
            o->mask0 |= bit;
            if (src[i].b != -1) {
                o->mask1 |= bit;
            }
        }
        o->pairs[i].b = src[i].b;
        if (src[i].a != -1) {
            o->mask0 |= bit;
            if (src[i].b != -1) {
                o->mask1 |= bit;
            }
        }
    }
}

void fn_80187E68(Obj48* o)
{
    o->f00 = -6190.0f;
    o->f04 = 0.0f;
    o->f10 = 1.0f;
    o->f14 = 0.0f;
    o->f18 = 1.0f;
    o->f1c = 0.0f;
    o->i08 = 0;
    o->i0c = 0;
    fn_8019A15C(o, 1, 0, 1);
    o->p20->p0 = fn_801D68C4(lbl_803470F0, 10);
    o->p24->f0 = 0.0f;
    o->p24->f4 = 0.0f;
    o->p2c->p0 = fn_801D68C4(lbl_803470E8, 2);
    o->p30->f0 = 0.0f;
    o->p30->f4 = 0.0f;
    o->p44 = fn_801D68C4(lbl_803470F0, 4);
}

void fn_801884C4(Obj48* o)
{
    o->f00 = -6790.0f;
    o->f04 = 0.0f;
    o->f10 = 1.0f;
    o->f14 = 0.0f;
    o->f18 = 1.0f;
    o->f1c = 0.0f;
    o->i08 = 0;
    o->i0c = 0;
    fn_8019A15C(o, 1, 0, 1);
    o->p20->p0 = fn_801D68C4(lbl_803470F0, 10);
    o->p24->f0 = 0.0f;
    o->p24->f4 = 0.0f;
    o->p2c->p0 = fn_801D68C4(lbl_803470E8, 2);
    o->p30->f0 = 0.0f;
    o->p30->f4 = 0.0f;
    o->p44 = fn_801D68C4(lbl_803470F0, 1);
}

void fn_8018873C(Obj48* o)
{
    void* r;

    o->f00 = -3700.0f;
    o->f04 = 0.0f;
    o->f10 = 1.0f;
    o->f14 = 1.0f;
    o->f18 = 1.0f;
    o->f1c = 0.0f;
    o->i08 = 1;
    o->i0c = 0;
    r = fn_801D68C4(lbl_803470F4, 0x4d);
    fn_8019A15C(o, 0, 1, 0);
    o->p38->p0 = r;
    o->p3c->f0 = 16.0f;
    o->p3c->f4 = 12.0f;
    o->p44 = 0;
}

void fn_801895C0(void* unused, Obj48* o, f32 f1)
{
    o->f00 = -4000.0f;
    o->f04 = 0.0f;
    o->f10 = 1.0f;
    o->f14 = f1;
    o->f18 = 1.0f;
    o->f1c = 0.0f;
    o->i08 = 0;
    o->i0c = 0;
    fn_8019A15C(o, 2, 0, 0);
    o->p20->p0 = fn_801D68C4(lbl_803470F0, 0x22);
    o->p24->f0 = 0.0f;
    o->p24->f4 = -26.0f;
    o->p20->p4 = fn_801D68C4(lbl_803470F0, 0x3b);
    o->p24->f8 = 68.0f;
    o->p24->fc = -26.0f;
    o->p44 = 0;
}

void fn_80189788(void* unused, Obj48* o, f32 f1)
{
    void* r;

    o->f00 = -4000.0f;
    o->f04 = 0.0f;
    o->f10 = 1.0f;
    o->f14 = f1;
    o->f18 = 1.0f;
    o->f1c = 0.0f;
    o->i08 = 0;
    o->i0c = 0;
    r = fn_801D68C4(lbl_803470F0, 0x20);
    fn_8019A15C(o, 1, 0, 0);
    o->p20->p0 = r;
    o->p24->f0 = 0.0f;
    o->p24->f4 = 2.0f;
    o->p44 = 0;
}

void fn_80189834(Obj48* o, f32 f1)
{
    o->f00 = -3850.0f;
    o->f04 = 0.0f;
    o->f10 = 1.0f;
    o->f14 = f1;
    o->f18 = 1.0f;
    o->f1c = 0.0f;
    o->i08 = 0;
    o->i0c = 0;
    fn_8019A15C(o, 1, 0, 1);
    o->p20->p0 = fn_801D68C4(lbl_803470F0, 0x1f);
    o->p24->f0 = 0.0f;
    o->p24->f4 = 160.0f;
    o->p2c->p0 = fn_801D68C4(lbl_803470E8, 3);
    o->p30->f0 = 0.0f;
    o->p30->f4 = 0.0f;
    o->p44 = fn_801D68C4(lbl_803470F0, 5);
}

void fn_80189CF0(Obj48* o)
{
    o->f00 = -3990.0f;
    o->f04 = 0.0f;
    o->f10 = 1.0f;
    o->f14 = 0.0f;
    o->f18 = 1.0f;
    o->f1c = 0.0f;
    o->i08 = 0;
    o->i0c = 0;
    fn_8019A15C(o, 1, 0, 1);
    o->p20->p0 = fn_801D68C4(lbl_803470F0, 0x27);
    o->p24->f0 = 0.0f;
    o->p24->f4 = 0.0f;
    o->p2c->p0 = fn_801D68C4(lbl_803470E8, 4);
    o->p30->f0 = 0.0f;
    o->p30->f4 = 0.0f;
    o->p44 = 0;
}

void fn_8018DEFC(Obj48* o)
{
    void* r;

    o->f00 = -3940.0f;
    o->f04 = 0.0f;
    o->f10 = 1.0f;
    o->f14 = 1.0f;
    o->f18 = 1.0f;
    o->f1c = 0.0f;
    o->i08 = 1;
    o->i0c = 0;
    r = fn_801D68C4(lbl_803470F4, 0x4a);
    fn_8019A15C(o, 0, 1, 0);
    o->p38->p0 = r;
    o->p3c->f0 = -24.0f;
    o->p3c->f4 = 0.0f;
    o->p44 = 0;
}

void fn_8018DFC4(Obj_8018DFC4* o)
{
    Sub_8018DFC4* s = o->p24;
    void* r = s->rect8;

    if (lbl_803475D8 != 0) {
        o->state19 = 0xff;
    }
    switch (o->state19) {
    case 0:
    case 0xfe:
        o->state19 = 1;
        /* fall through */
    case 1:
        fn_80199F38(r);
        UiObjCalcRect(r);
        if (o->p24->kind == 1) {
            fn_8018E73C(o->p24);
            fn_8018E0A8(o->p24);
        }
        break;
    case 0x64:
        o->state19 = 0xff;
        break;
    case 0xff:
        fn_80199F58(o->p24);
        o->flags18 |= 0x40;
        break;
    }
}

void fn_801925D8(void)
{
    if (lbl_803470E8 != 0) {
        fn_801D6944(lbl_803470E8);
        fn_801E17E0(lbl_803470E8);
        lbl_803470E8 = 0;
    }
    if (lbl_803470EC != 0) {
        fn_801D6944(lbl_803470EC);
        fn_801E17E0(lbl_803470EC);
        lbl_803470EC = 0;
    }
    if (lbl_803470F0 != 0) {
        fn_801D6944(lbl_803470F0);
        fn_801E17E0(lbl_803470F0);
        lbl_803470F0 = 0;
    }
    if (lbl_803470F4 != 0) {
        fn_801D6944(lbl_803470F4);
        fn_801E17E0(lbl_803470F4);
        lbl_803470F4 = 0;
    }
    if (lbl_80347618 != 0) {
        fn_802275A4(lbl_80347618->x4->x20, 1);
        fn_801E17E0(lbl_80347618);
        lbl_80347618 = 0;
    }
    if (lbl_803470F8 != 0) {
        fn_801E17E0(lbl_803470F8);
        lbl_803470F8 = 0;
    }
}

void fn_80192888(void)
{
    s16* p = (s16*)(lbl_8030B7F4 + 0x1568);
    s32 i;

    for (i = 0; i < 5; i++) {
        if (p[12 + i] != -1) {
            fn_801C0FE8(p[12 + i], 1);
        }
    }
    for (i = 0; i < 3; i++) {
        if (p[17 + i] != -1) {
            fn_801C0FE8(p[17 + i], 1);
        }
    }
}
