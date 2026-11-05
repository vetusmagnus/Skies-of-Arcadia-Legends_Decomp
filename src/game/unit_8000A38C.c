#include "types.h"
#include "game/chr.h"
#include "ninja.h"
#include "game/drawstate.h"
#include <dolphin/os.h>
#include <dolphin/dvd.h>
#include "game/task.h"
#include "game/save_8030B7F4.h"
#include "game/stat_8030B4D4.h"
#include "game/gamedata.h"
#include <string.h>
#include "game/unit_80005B50.h"
#define PTR(p, off) (*(void**)((u8*)(p) + (off)))
extern void* lbl_803475A8;
extern void* fn_802268E8(void* a, void* cb);
extern void* fn_801E1C7C(u32 size);
extern void fn_8000A3FC(void* p);
extern u32 lbl_803474E4[2];
extern void* lbl_80346AA0;
extern void fn_801DDCA8(void* p);
extern void fn_802275A4(void* a, s32 b);
extern void fn_801E17E0(void* p);
extern void* fn_801DB1A4(u32 size);
extern s32 fn_80227810(void* p);
extern void fn_801DDD74(void* p, s32 n);
extern f32 fn_80291A5C(f32 v);
typedef struct Node_BB28 {
    u8 pad[0x24];
    Work_BB28* work;
} Node_BB28;
typedef struct {
    u16 x0;
    u8 pad2[6];
    u32 x8;
    u8 padc[4];
    f32 x10;
    f32 x14;
    s32 x18;
    f32 x1c;
    int cur;
    void* x24;
    Ent_BB28* tbl;
} Sys_80309E5C;
extern Sys_80309E5C lbl_80309E5C;
extern Task* lbl_80347394;
u32 fn_8000F718(s8 idx, s8 alt, u8* out);
typedef struct HNode {
    u8 pad0[0x2c];
    struct HNode* child;   /* 0x2c */
    struct HNode* sibling; /* 0x30 */
} HNode;
extern void fn_8000F6F8(HNode* n, u8 kind, s32 a, s32 b, s32 c);
extern Entry16 lbl_80309730[];
extern Task* lbl_80309E24[];
extern void fn_802A9B94(s32 a, s32 b, s32 c, void (*f)(void));
typedef struct WorkRec {
    s16 x0;
    s16 x2;
} WorkRec;
typedef struct TkRec {
    u8 pad_0[0x24];
    WorkRec *work;
} TkRec;
extern TkRec *lbl_80309700[12];
extern s8 fn_80020E10(void* p);
extern s8 fn_8000FA30(s8 v);
extern int sprintf(char* buf, const char* fmt, ...);
extern s32 fn_8025ECC4(void);
extern u8 *lbl_80346AA4;
typedef void (*TaskFn)(void*);
extern TaskFn lbl_802DAFA8[];
extern void fn_80071CF0(void *p, void *v);
typedef struct E0D8Anim {
    u16 cur;
    u16 end;
    s16 sub;
    u8 pad6[2];
    u32 val;
    u8 mat[0x14];
    void *p20;
    u8 pad24[8];
    void *p2c;
} E0D8Anim;
typedef struct E0D8Obj {
    u8 pad0[0x18];
    u8 flags;
    u8 state;
    u8 pad1A[10];
    struct { void *p0; u8 pad4[0x48]; E0D8Anim *anim; } *inner;
} E0D8Obj;
extern void fn_80230634(void *, void *);
extern void fn_80230280(void *, void *);
extern s32 fn_800179E4(s16);
extern void fn_8000B320(f32, void *, void *);
extern void fn_801E17E0(void *);
extern Tbl lbl_803097F0;
/* lbl_80309730: 12 rows of 16 bytes, one per character slot; +0x8 is the slot mode
 * (0 = unused, see fn_80010538). */
typedef struct {
    f32 x0;
    u8 pad4[8];
    f32 xc;
    f32 x10;
    f32 x14;
    f32 x18;
    f32 x1c;
    u8 pad20[0x40 - 0x20];
    s32 x40;
    s32 x44;
    f32 x48;
    void* x4c;
    u32 x50;
} U;
typedef struct {
    void* x0;
    u8 pad4[4];
    void* x8;
    struct { u8 pad[4]; u32 x4; }* xc;
    struct { u8 pad[8]; void* x8; }* x10;
    u8 pad14[2];
    s16 x16;
    s16 x18;
    u8 pad1a[0x1c - 0x1a];
    f32 tx;
    f32 ty;
    f32 tz;
    s32 rx;
    s32 ry;
    s32 rz;
    f32 sx;
    f32 sy;
    f32 sz;
    u8 pad40[4];
    u8 x44;
    u8 pad45[0x4c - 0x45];
    U* u;
} W;
typedef struct {
    u8 pad0[0x19];
    u8 state;
    u8 pad1a[0x24 - 0x1a];
    W* work;
} Tk_8000E664;
extern int fn_8000CCBC(Tk_8000E664*, s16);
extern void fn_8000B77C(void*, void*);
extern void fn_80060950(void*);
extern int fn_80035908(void);
extern void fn_80035910(int);
extern void fn_8000F0BC(void);
extern void fn_8000B6F0(W*);
extern void fn_8000B5F4(W*, f32);
extern void fn_800D2048(void);
extern void njTranslate(void*, f32, f32, f32);
extern void njScale(void*, f32, f32, f32);
extern void fn_800353F4(void*, void*, void*, f32, u8);
extern void fn_80035380(void*, void*, f32, u8);
/* The camera object fn_8006B6F4 returns; its position is at 0x3c. */
typedef struct CamObj {
    u8 pad0[0x3C];
    f32 pos[3];         /* 0x3c */
} CamObj;
typedef struct {
    u8 pad0[4];
    CamObj* cam;        /* 0x04 */
    s32 mode;
    f32 b1[3];
    s16 steps;          /* 0x18 */
    u8 pad1a[2];
    f32 vel[3];
    f32 b2[3];
    s16 state;
} Bounce;
typedef struct {
    struct {
        u8 pad0[8];
        f32 v[3];
        u8 pad14[4];
    } e[4];
} Q4;
typedef struct Nd {
    Q4* x0;
    struct Nd* x4;
    f32 v[3];
    u8 pad14[0x2c - 0x14];
    struct Nd* x2c;
} Nd;
typedef struct {
    Nd* x0;
    u8 pad4[0x1c - 4];
    f32 x1c[3];
    u8 pad28[4];
    s32 x2c;
} N0;
typedef struct {
    N0* x0;
    s16 x4;
} U_8000D8FC;
typedef struct {
    u8 pad[0x4C];
    U_8000D8FC* w;
} Wk_8000D8FC;
typedef struct {
    u8 pad0[0x18];
    u8 flags;
    u8 state;
    u8 pad1a[0x24 - 0x1a];
    Wk_8000D8FC* work;
} Tk_8000D8FC;
extern void fn_800120D0(s32*);
typedef struct Cx_BB28 {
    u8 pad[0x2c];
    struct { u8 pad[0x2c]; void* x2c; }* x2c;
} Cx_BB28;
extern TaskFn fn_8000F0A4(s16 i);
extern int fn_80061F58(void*, int, int);
extern void fn_8006CF28(void*, void*, s16);
extern void fn_8006CEEC(void*, void*, int, s16);
extern void fn_8022F00C(void*);
extern void fn_8000B8E4(void*, void*);
#define FLD(p, off, T) (*(T*)((u8*)(p) + (off)))
s8 fn_80020E10(void* p);
s16 fn_80008274(s16 v);
void fn_80012130(void* p);
typedef struct Ref3 {
    u8 pad[0x28];
    u32 flags;
} Ref3;
typedef struct Ref {
    u8 pad[0x4c];
    Ref3* m;
} Ref;
typedef struct Actor {
    u8 pad[0x24];
    Ref* r;
} Actor;
typedef struct Owner_8000FBA8 {
    u8 pad[0x1e0];
    Actor* a;
    Actor* b;
    Actor* c;
} Owner_8000FBA8;
extern void njPushMatrixEx(void);
extern void njPopMatrixEx(void);
extern void fn_80286EE8(void);
extern void fn_8028B498(void);
extern void fn_80035140(void* model, u8 flag);
typedef s32 Angle;
typedef struct Dst { u32 x0; u8 pad4[0x20 - 4]; f32 x20; } Dst;
typedef struct Par { f32 x0; f32 x4; f32 x8; Dst* xc; } Par;
typedef struct Work_8000DDFC { u8 pad0[0x4c]; Par* x4c; } Work_8000DDFC;
typedef struct Task_8000DDFC { u8 pad0[0x18]; u8 flags; u8 mode; u8 pad1a[0x24 - 0x1a]; Work_8000DDFC* work; } Task_8000DDFC;
extern f32 njSin(Angle a);
typedef struct D { u8 pad[0x4c]; A* x4c; } D;
typedef struct Obj_8000DF50 { u8 pad[0x18]; u8 flags; u8 state; u8 pad1a[0xa]; D* x24; } Obj_8000DF50;
extern s32 rand(void);
typedef struct SlotTable {
    s16 count;
    char sml[0x20];      /* 0x002 model file name */
    char sst[0x20];      /* 0x022 */
    char icon[0x3c2];    /* 0x042 */
    void *buf[32];
    void *res[32];
} SlotTable;
extern SlotTable lbl_803098C8;
void fn_801E1718(void *p);
extern void fn_8000AA08(void);
extern void fn_8000AA98(void);
extern void *memcpy(void *d, const void *s, u32 n);
typedef struct Fn108EC {
    u8 pad0[0x1c];
    u32 flags;
    u8 pad1[0x28 - 0x20];
    s16 stat[6];
} Fn108EC;
typedef struct Node_800102C8 {
    u8 pad[0x24];
    void* val;
} Node_800102C8;
typedef struct Mid_800102C8 {
    u8 pad0[0x1e0];
    Node_800102C8* e0;
    Node_800102C8* e4;
} Mid_800102C8;
typedef struct Holder_800102C8 {
    u8 pad[0x4c];
    Mid_800102C8* mid;
} Holder_800102C8;
typedef struct Ent_800102C8 {
    u8 pad[0x24];
    Holder_800102C8* h;
} Ent_800102C8;
/* lbl_80309E24: the character task table (void* in unit_80005B50.c). */
extern Task* lbl_80309E24[];
typedef struct Sub {
    void* link;
    u8 pad[0x1c];
    f32 pos;
} Sub;
typedef struct Mid_8000DEC8 {
    f32 speed;
    s16 mode;
    u8 pad[2];
    Sub* sub;
} Mid_8000DEC8;
typedef struct Holder_8000DEC8 {
    u8 pad[0x4c];
    Mid_8000DEC8* mid;
} Holder_8000DEC8;
typedef struct Actor_8000DEC8 {
    u8 pad0[0x18];
    u8 flags;
    u8 state;
    u8 pad1[0xa];
    Holder_8000DEC8* holder;
} Actor_8000DEC8;
extern f32 fn_80071E9C(void*, void*);
typedef struct ModelCache {
    u8 pad0[4];
    s16 x4;
    u8 pad6[2];
    void* x8;
    char name[0x28];
    struct ModelCache* x34;
    struct ModelCache* x38;
    u8 pad3c[8];
} ModelCache;
typedef struct ModelSrc {
    s32 id;
    void* data;
    s32 size;
} ModelSrc;
extern char lbl_802ACCE8[];
extern ModelCache* lbl_803473A0;
extern int sprintf(char* s, const char* fmt, ...);
extern void* memset(void* dst, int c, u32 n);
extern int fn_8025EF88(const char* a, const char* b);
extern char* strcpy(char* d, const char* s);
extern void* fn_801DB124(void* data);
extern void fn_8006CF54(ModelCache* c);
typedef struct CE8Pos {
    u8 pad0[0x1C];
    f32 p1c[3];
} CE8Pos;
typedef struct CE8Ext {
    u8 pad0[0x10];
    f32 x10;
    u8 pad14[0x50 - 0x14];
    u32 x50;
} CE8Ext;
/* The move parameters (at the state's 0x08). */
typedef struct CE8Prm {
    s16 x0;
    s16 xa;
    f32 to[3];   /* 0x04 */
    f32 from[3]; /* 0x10 */
    s16 x1c;     /* 0x1C speed */
    s16 x1e;     /* 0x1E fade frames */
    s16 x20;     /* 0x20 wait frames */
} CE8Prm;
typedef struct CE8State {
    CE8Pos* x0;
    CE8Ext* x4;
    CE8Prm prm;     /* 0x08 */
    f32 v[3];       /* 0x2C */
    f32 s[3];       /* 0x38 */
    f32 x44;
    s16 x48;
    s16 x4a;
    s16 x4c;
    s16 x4e;
} CE8State;
typedef struct CE8Work {
    u8 pad0[0x4C];
    CE8State* st;
} CE8Work;
extern void fn_802307EC(void* p, void* v, s32 n);
typedef struct E02Ctr {
    u16 cur;
    u16 max;
    void* x4;
} E02Ctr;
typedef struct E02Work {
    void* x0;
    u8 pad4[0x4C - 0x4];
    E02Ctr* ctr;
} E02Work;
extern void fn_80012100(void* a);
extern s32 fn_8000AD30(u8 dir);
#define LIMIT() \
    switch (lbl_80309E5C.x0) { \
    case 0x46: case 0x47: case 0x49: case 0x4b: \
    case 0x80: case 0x81: case 0x82: \
    case 0x92: case 0x93: case 0x94: case 0x95: \
        *out = -0.9f; \
        break; \
    default: \
        *out = -1.0f; \
        break; \
    } \
    return 1;

extern void fn_802A9338(s32 a, s32 b, s32 c, void (*f)(void));

void fn_8000AA58(void);
s32 fn_8000ACE8(void);



typedef struct Hd_8000CF94 { s16 x0; } Hd_8000CF94;
typedef struct Bd_8000CF94 { Hd_8000CF94* x0; } Bd_8000CF94;
typedef struct Ob_8000CF94 { u8 pad0[4]; Bd_8000CF94* x4; } Ob_8000CF94;
extern s32 fn_80047F9C(void* p);
int fn_8000CF94(Ob_8000CF94* o);

void fn_8000A3A4(void* obj) {
    lbl_80346AA4 = fn_802268E8(lbl_803475A8, fn_8000A3FC);
    PTR(lbl_80346AA4, 0x24) = fn_801E1C7C(12);
    *(void**)PTR(lbl_80346AA4, 0x24) = obj;
}

void fn_8000AA08(void) {
    fn_801DDCA8(lbl_803474E4);
    if (lbl_80346AA0 != 0) {
        fn_802275A4(PTR(PTR(lbl_80346AA0, 4), 0x20), 1);
        fn_801E17E0(lbl_80346AA0);
        lbl_80346AA0 = 0;
    }
}

void fn_8000AA58(void) {
    lbl_80346AA0 = fn_801DB1A4(4);
    fn_80227810(PTR(PTR(lbl_80346AA0, 4), 0x20));
    fn_801DDD74(lbl_803474E4, 1);
}
/* The file's .rodata from its start, defined at the original offsets: fn_8000ABCC addresses it
 * from one pooled base (lbl_802ACCB8 + 0xc/0x18/0x24). */
const s32 lbl_802ACCB8[3] = { 0, 0, 0 };
const char lbl_802ACCC4[] = "s%03d.sml";
const char lbl_802ACCD0[] = "s%03d.sst";
const char lbl_802ACCDC[] = "stsicon.mld";
extern int fn_8025CB24(char* dst, const char* fmt, ...);
extern void fn_8002F670(void);

void fn_8000ABCC(s16 id) {
    s32 i;
    lbl_803098C8.count = 3;
    fn_8025CB24(lbl_803098C8.sml, lbl_802ACCC4, id);
    fn_8025CB24(lbl_803098C8.sst, lbl_802ACCD0, id);
    fn_8025CB24(lbl_803098C8.icon, lbl_802ACCDC);
    fn_8002F670();
    for (i = 0; i < 32; i += 4) {
        lbl_803098C8.buf[i] = 0;
        lbl_803098C8.buf[i + 1] = 0;
        lbl_803098C8.buf[i + 2] = 0;
        lbl_803098C8.buf[i + 3] = 0;
    }
}

s32 fn_8000ACE8(void) {
    return 1;
}

f32 fn_8000ACF0(NJS_POINT3* v) {
    return fn_80291A5C(v->z * v->z + (v->x * v->x + v->y * v->y));
}

/* A loaded resource file handle (fn_801CC69C). */
typedef struct ResHandle {
    u8 pad0[0x54];
    u32 size;
} ResHandle;
extern int sprintf(char* s, const char* fmt, ...);
extern ResHandle* fn_801CC69C(char* name);
extern void fn_801CC608(ResHandle* h, void* buf, u32 size);
extern void fn_801CC65C(ResHandle* h);
extern void fn_801E1DF8(s32 a, void* b);

/* The work of the effect task fn_8000BF48 starts (fn_8000F0A4(11)), and its 0x38-byte parameters. */
typedef struct Par_8000BF48 { u8 pad0[8]; u32 x8; f32 xc; f32 x10; f32 x14; s16 x18; u8 pad1a[0x38 - 0x1a]; } Par_8000BF48;
typedef struct Work_8000BF48 { u8 pad0[0x4c]; Par_8000BF48* x4c; u8 pad50[8]; } Work_8000BF48;
typedef struct Src_8000BF48 { s16 x0; u8 pad2[2]; u32 x4; f32 x8; f32 xc; f32 x10; s16 x14; } Src_8000BF48;
typedef struct Owner_8000BF48 { u8 pad[0xc]; Src_8000BF48* src; } Owner_8000BF48;

void fn_8000B5F4(W *o, f32 frame) {
    void *aux = NULL;
    njPushMatrixEx();
    fn_80286EE8();
    fn_8028B498();
    njTranslate(0, o->tx, o->ty, o->tz);
    njRotateXYZ(0, o->rx, o->ry, o->rz);
    njScale(0, o->sx, o->sy, o->sz);
    fn_8006CEEC(o->x10->x8, &aux, 1, o->x16);
    if (o->x0 != NULL) {
        if (o->xc != NULL && aux != NULL) {
            fn_800353F4(o->x0, o->xc, aux, frame, o->x44);
        } else if (o->xc != NULL) {
            fn_80035380(o->x0, o->xc, frame, o->x44);
        } else {
            fn_80035140(o->x0, o->x44);
        }
    }
    njPopMatrixEx();
}

/* The work parameters of the effect task fn_8000BE28 starts (fn_8000F0A4(12)), 0x50 bytes. */
typedef struct Par_8000BE28 {
    Work_BB28* x0;       /* the first of the current table's works */
    void* x4;
    s16 x8;
    s16 xa;
    f32 xc;
    f32 x10;
    f32 x14;
    u8 pad18[0x24 - 0x18];
    s16 x24;
    s16 x26;
    s16 x28;
    u8 pad2a[0x50 - 0x2a];
} Par_8000BE28;
typedef struct Work_8000BE28 { u8 pad0[0x4c]; Par_8000BE28* x4c; u8 pad50[8]; } Work_8000BE28;
typedef struct Src_8000BE28 {
    s16 x0;
    u8 pad2[2];
    s16 x4;
    s16 x6;
    f32 x8;
    f32 xc;
    f32 x10;
    u8 pad14[0x20 - 0x14];
    s16 x20;
    s16 x22;
    s16 x24;
} Src_8000BE28;
typedef struct Owner_8000BE28 { u8 pad[0xc]; Src_8000BE28* src; } Owner_8000BE28;

void fn_8000BE28(Owner_8000BE28 *a) {
    Src_8000BE28 *s = a->src;
    Task *n;
    Work_8000BE28 *w;
    Par_8000BE28 *d;
    if (s->x0 < lbl_80309E5C.tbl[lbl_80309E5C.cur].xc && s->x20 != 0) {
        n = fn_802268E8(lbl_803475A8, fn_8000F0A4(0xc));
        fn_80061F58(&n->work, 0x58, 0);
        w = n->work;
        fn_80061F58(&w->x4c, 0x50, 0);
        d = w->x4c;
        d->x26 = s->x22;
        d->x8 = s->x4;
        d->x24 = s->x20;
        d->xa = s->x6;
        d->x28 = s->x24;
        d->xc = s->x8;
        d->x10 = s->xc;
        d->x14 = s->x10;
        d->x0 = *lbl_80309E5C.tbl[lbl_80309E5C.cur].ptrs;
        d->x4 = lbl_80309E5C.tbl[lbl_80309E5C.cur].x10;
    }
}

void fn_8000BF48(Owner_8000BF48* ow) {
    Src_8000BF48* s = ow->src;
    if (s->x0 < lbl_80309E5C.tbl[lbl_80309E5C.cur].xc && s->x14 != 0) {
        Task* o = fn_802268E8(lbl_803475A8, fn_8000F0A4(11));
        Work_8000BF48* w;
        Par_8000BF48* sub;
        fn_80061F58(&o->work, 0x58, 0);
        w = o->work;
        fn_80061F58(&w->x4c, 0x38, 0);
        sub = w->x4c;
        sub->xc = s->x8;
        sub->x10 = s->xc;
        sub->x14 = s->x10;
        sub->x8 = s->x4;
        sub->x18 = s->x14;
    }
}

typedef struct LoadRec {
    s16 kind;
    u8 pad2[0xa];
    u8 *data;
} LoadRec;
typedef struct LoadHdr {
    u32 count;
    LoadRec recs[1];
} LoadHdr;
extern void fn_8000C19C(LoadRec *r);

void fn_8000C7C0(s32 mode, LoadHdr *h) {
    u32 n;
    u8 i;
    LoadRec *recs;
    u8 *p;
    {
        /* the records' data follows the (count + 1) record headers */
        void *v = h->recs;
        p = v;
    }
    recs = h->recs;
    n = h->count;
    p += (n + 1) * 16;
    for (i = 0; i < n; i++) {
        recs[i].data = p;
        switch (recs[i].kind) {
        case 0: p += 0x4c; break;
        case 1: p += 0xd0; break;
        case 2: p += 0x44; break;
        case 3: p += 0x8; break;
        case 4: p += 0x18; break;
        case 6: p += 0x10; break;
        case 7: p += 0x14; break;
        case 8: p += 0x14; break;
        case 9: p += 0xc; break;
        case 10: p += 0x18; break;
        case 11: p += 0x18; break;
        }
    }
    if (mode == 1) lbl_80309E5C.x24 = p;
    fn_8000C19C(recs);
}

void fn_8000C9F8(void** out1, void** out2) {
    char name[0x20];

    if (lbl_803098C8.buf[0] == 0) {
        ResHandle* h;
        u32 size;
        sprintf(name, lbl_802ACCC4, lbl_80309E5C.x0);
        h = fn_801CC69C(name);
        size = h->size;
        *out1 = fn_801E1C7C(size);
        fn_801CC608(h, *out1, size);
        fn_801CC65C(h);
    } else {
        fn_801E1DF8(0, lbl_803098C8.buf[0]);
        *out1 = lbl_803098C8.buf[0];
        lbl_803098C8.buf[0] = 0;
    }
    if (lbl_803098C8.buf[1] == 0) {
        ResHandle* h2;
        u32 size2;
        sprintf(name, lbl_802ACCD0, lbl_80309E5C.x0);
        h2 = fn_801CC69C(name);
        size2 = h2->size;
        *out2 = fn_801E1C7C(size2);
        fn_801CC608(h2, *out2, size2);
        fn_801CC65C(h2);
    } else {
        fn_801E1DF8(0, lbl_803098C8.buf[1]);
        *out2 = lbl_803098C8.buf[1];
        lbl_803098C8.buf[1] = 0;
    }
}

void fn_8000CC84(s32 flag) {
    if (flag == 1) {
        lbl_80309E5C.x8 |= 0x01000000;
    } else {
        lbl_80309E5C.x8 &= ~0x01000000;
    }
}

s32 fn_80015828(const char* s);
static inline int FindNamedChr(Task** out) {
    Task* e;
    u8 i;
    for (i = 0; i < 0xe; i++) {
        e = lbl_80309E24[i];
        if (e != 0) {
            ChrWork* w = e->work;
            if (fn_80015828(w->x10->xc) != 0) {
                *out = e;
                return 1;
            }
        }
    }
    return 0;
}

/* The work of the camera task fn_8000D734 runs (its Bounce at 0x4c). */
typedef struct CamTaskWork {
    u8 pad0[0x4C];
    Bounce* move;
} CamTaskWork;
/* What lbl_80309E88[0].f4's work points at. */
typedef struct CamInfo {
    u8 pad0[0x30];
    s16 x30;
    u8 pad32[0x64 - 0x32];
    f32 x64[3];
} CamInfo;
/* lbl_80309E88: four 0x10-byte slots (TblEnt in unit_80055E94.c). */
typedef struct TblEnt_80309E88 {
    void* f0;
    Task* f4;
    u32 f8;
    u8 fc;
    u8 pad[3];
} TblEnt_80309E88;
extern TblEnt_80309E88 lbl_80309E88[4];
extern CamObj* fn_8006B6F4(s32 a);
extern void* fn_8006B6C8(s16 a);
void fn_8000D488(Bounce* o, f32* pos);

void fn_8000D734(Task* t) {
    CamInfo* info;
    Bounce* m;
    CamObj* o;
    CamTaskWork* w;
    Task* h;
    f32 dx, dy, dz;
    if (lbl_80309E5C.x8 & 0x02000000) return;
    w = t->work;
    m = w->move;
    h = lbl_80309E88[0].f4;
    info = h->work;
    switch (t->state) {
    case 0:
        m->cam = fn_8006B6F4(0);
        fn_80071CF0(m->cam->pos, m->b2);
        o = m->cam;
        dx = m->b1[0] - o->pos[0];
        dy = m->b1[1] - o->pos[1];
        dz = m->b1[2] - o->pos[2];
        m->vel[0] = dx / m->steps;
        m->vel[1] = dy / m->steps;
        m->vel[2] = dz / m->steps;
        if (m->mode == 1) {
            fn_80071CF0(m->b1, m->cam->pos);
            m->vel[0] = -1.0f * m->vel[0];
            m->vel[1] = -1.0f * m->vel[1];
            m->vel[2] = -1.0f * m->vel[2];
            m->state = 1;
        } else {
            m->state = 0;
        }
        t->state = 1;
    case 1:
        if (fn_8006B6C8(info->x30) == 0) fn_8000D488(m, info->x64);
        break;
    case 2:
        break;
    case 3:
        t->flags |= 0x40;
        break;
    }
}

void fn_8000F168(NJS_TEXLIST* d) {
    Task* hit;
    if (FindNamedChr(&hit)) {
        ChrWork* w = hit->work;
        d->textures->texaddr = w->x8->textures->texaddr;
    }
}

static inline u32 Pack(u8 r, u8 g, u8 b, u8 a) {
    return (b << 24) | (g << 16) | (r << 8) | a;
}

u32 fn_8000F718(s8 idx, s8 alt, u8* out) {
    f32 tabA[6][3] = {
        {0.231f, 1.0f, 0.655f}, {1.0f, 0.146f, 0.468f}, {0.711f, 0.446f, 1.0f},
        {0.0f, 1.0f, 1.0f}, {1.0f, 1.0f, 0.446f}, {1.0f, 1.0f, 1.0f}
    };
    f32 tabB[6][3] = {
        {0.0f, 0.5f, 0.0f}, {0.5f, 0.0f, 0.0f}, {0.25f, 0.0f, 0.5f},
        {0.0f, 0.5f, 1.0f}, {0.5f, 0.5f, 0.0f}, {0.5f, 0.5f, 0.5f}
    };
    u8 r, g, b, a;
    if (idx > 5) idx = 5;
    if (alt == 0) {
        r = tabA[idx][0] * 255.0f;
        g = tabA[idx][1] * 255.0f;
        b = tabA[idx][2] * 255.0f;
        a = 0x7f;
    } else {
        r = tabB[idx][0] * 255.0f;
        g = tabB[idx][1] * 255.0f;
        b = tabB[idx][2] * 255.0f;
        a = 0x7f;
    }
    if (out != 0) {
        out[1] = r;
        out[2] = g;
        out[3] = b;
    }
    return Pack(r, g, b, a);
}

s32 fn_8000F86C(s32 idx) {
    Task* p = lbl_80347394;
    if (p != 0) {
        SysObj* s = p->work;
        return (s8)s->x5c;
    }
    return lbl_80309DE4[(s8)idx]->x100;
}

void fn_8000F8A4(void* obj, s8 x) {
    s32 v = fn_8000F718(x, 0, 0);
    fn_8000F6F8(obj, 0x40, v, -1, 0);
}

s8 fn_8000FA30(s8 idx) {
    s8 v;
    SysObj* s;
    if (lbl_80347394 == 0) {
        v = lbl_80309DE4[idx]->xb6;
        if (v >= 0 && v < 0x10) {
        } else if (v >= 0x10 && v < 0x20) {
            v = v - 0x10;
        } else if (v >= 0x20 && v < 0x30) {
            v = v - 0x20;
        } else if (v >= 0x30 && v < 0x3a) {
            v = v - 0x30;
        } else if (v >= 0x3a && v < 0x40) {
            v = v - 0x3a;
        } else if (v >= 0x40 && v < 0x47) {
            v = v - 0x40;
        } else if (v == 0x47 || v == 0x48) {
            v = 0x10;
        } else if (v == 0x49) {
            v = 0x11;
        } else {
            v = -1;
        }
        if (v < 0) {
            v = 0;
        }
        if (v > 0x11) {
            v = 0x11;
        }
        return v;
    }
    s = lbl_80347394->work;
    return s->x5a;
}

void fn_80010538(s16 idx) {
    s32 mode = lbl_80309730[idx].mode;
    ChrRec* q;
    if (mode == 0) {
        return;
    }
    if (mode == 4) {
        return;
    }
    q = lbl_80309DE4[idx];
    q->xb4 += q->x8;
}
extern ChrStat lbl_80309174[12];
static inline int Gt(s16 x, int y) { return x > y ? 1 : 0; }

static inline int Roll(ChrRec* p, ChrRec* q, int lim, s16 v)
{
    s16 den;
    s16 num;
    s16 res;
    s16 rnd;
    den = q->x96;
    num = p->x94;
    rnd = rand() % 100;
    if (rnd >= 90) rnd = 100;
    if (rnd < 10) rnd = 0;
    if (den == 0) den = 1;
    res = v / 10.0f * (num * rnd) / den;
    return Gt(res, lim);
}

s8 fn_80010584(s16 a, s16 b)
{
    ChrRec* p = lbl_80309DE4[a];
    ChrRec* q = lbl_80309DE4[b];
    int r = -1;
    int lim;
    s16 num;
    s16 den;
    s16 res;
    s16 rnd;
    s16 v;
    int c;
    s8 k;
    WeaponFx* e;
    ChrAux* t;

    if (b >= 4 && a < 4) {
        k = lbl_802C5790[p->xb6].effect;
        if (k != -1) {
            e = &lbl_802C7A90[k];
            r = e->effect;
            c = Roll(p, q, e->status_rate, q->stat[e->status]);
            if (c == 1) lbl_80309174[b].x9 = r;
            else r = -1;
        }
    } else if (b < 4 && a >= 4) {
        t = p->x110;
        r = t->x58;
        if (r != -1) {
            lim = t->x5a;
            den = q->x96;
            num = p->x94;
            v = q->stat[t->x59];
            rnd = rand() % 100;
            if (rnd >= 90) rnd = 100;
            if (rnd < 10) rnd = 0;
            if (den == 0) den = 1;
            res = v / 10.0f * (num * rnd) / den;
            c = Gt(res, lim);
            if (c == 1) lbl_80309174[b].x9 = r;
            else r = -1;
        }
    }
    if (lbl_80309DE4[b]->bits & 0x40) {
        switch (r) {
        case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10: case 11: case 12: case 13: case 14:
        case 0x1a: case 0x3e: case 0x44: case 0x45: case 0x46: case 0x47: case 0x48: case 0x49:
            r = -1;
        }
    }
    lbl_80309174[b].x9 = r;
    return r;
}

s32 fn_80010B5C(void) {
    return 1;
}

/* What lbl_80347390 points at: its first byte is the level fn_80010CF4 compares with. */
typedef struct Lim_80347390 { u8 v; u8 x1; s8 x2; s8 x3; } Lim_80347390;
extern Lim_80347390* lbl_80347390;
extern s32 lbl_80347344;
extern s32 fn_8025ECC4(void);

extern s8 fn_801EF300(void);

s32 fn_80010B64(s16 a, s16 b) {
    s16 u = lbl_80309DE4[a]->x9a;
    s16 w = lbl_80309DE4[b]->x9c;
    s32 res;
    s16 hit;
    if (b <= 3 && lbl_8030B7F4.party[b] == 0) {
        w += lbl_802C8E54[fn_801EF300()].dodge;
    }
    hit = (100 - u + w) / 2;
    if (fn_8025ECC4() % 101 >= hit) {
        res = 1;
        if (lbl_80309174[a].x6 == 0) {
            if (fn_8025ECC4() % 101 <= lbl_80309DE4[a]->x86) {
                res = 2;
            }
        }
    } else {
        res = 0;
        if (!(lbl_80309DE4[b]->xae & 0x800) || (lbl_80309DE4[b]->bits & 0x4c00)) {
            res = 1;
        }
    }
    return res;
}

void fn_80010CF4(void) {
    s32 a;
    s32 r;
    if (lbl_803097F0.x0 != -1) {
        lbl_80347344 = 1;
        return;
    }
    a = lbl_8030B4D4.x2d5[0];
    r = fn_8025ECC4() % 101;
    if (a == -1) {
        a = lbl_8030B7F4.chr[lbl_8030B7F4.party[0]].xb * 4 + 30 - lbl_80347390->v;
        if (a < 0) {
            a = 0;
        }
        if (a > 30) {
            a = 30;
        }
    }
    if (a > r) {
        lbl_80347344 = 2;
        return;
    }
    a = lbl_8030B4D4.x2d5[1];
    r = fn_8025ECC4() % 101;
    if (a == -1) {
        a = lbl_80347390->v - lbl_8030B7F4.chr[lbl_8030B7F4.party[0]].xb * 4;
        if (a < 0) {
            a = 0;
        }
        if (a > 70) {
            a = 70;
        }
    }
    if (a > r) {
        lbl_80347344 = 0;
        return;
    }
    lbl_80347344 = 1;
}

extern s32 fn_8025ECC4(void);

extern void fn_80060950(void*);

void fn_8000A38C(void)
{
    if (lbl_80346AA4 != NULL) lbl_80346AA4[0x19] = 3;
}

TaskFn fn_8000F0A4(s16 i)
{
    return lbl_802DAFA8[i];
}

s16 fn_80010CBC(s16 i)
{
    s8 k = lbl_8030B7F4.party[i];
    return lbl_8030B7F4.chr[k].x1c;
}

s32 fn_80010CE4(u8 *a, u8 *b)
{
    return *(s32 *)(a + 4) - *(s32 *)(b + 4);
}

void fn_8000E0D8(E0D8Obj *obj) {
    E0D8Anim *a;
    void *p;
    p = obj->inner->p0;
    a = obj->inner->anim;
    if (p == 0) {
        obj->state = 3;
    }
    switch (obj->state) {
    case 0:
        if (a->cur >= a->end) {
            obj->state = 1;
            a->val = *(u32 *)((u8 *)p + 4);
        } else {
            a->cur = a->cur + 1;
        }
        break;
    case 1:
        fn_80230634(p, a->mat);
        fn_80230280(p, a->mat);
        obj->state = 2;
        break;
    case 2:
        if (a->sub >= 0 && fn_800179E4(a->sub) == 0) {
            obj->state = 3;
        }
        fn_8000B320((f32)a->cur, p, a->mat);
        a->cur += 1.0f;
        break;
    case 3:
        if (a->p20 != 0) {
            fn_801E17E0(a->p20);
        }
        if (a->p2c != 0) {
            fn_801E17E0(a->p2c);
        }
        obj->flags |= 0x40;
        break;
    }
}

extern s32 fn_8022E734(u8 kind, void* p, void* a, void* b, s32 f1, s32 f2, s32 f3);
extern void fn_8022E4CC(HNode* o, s32 a, s32 b, s32 c, s32 d, s32 e);
void fn_8000F2A0(HNode* n, u8 kind, s32 a, s32 b, s32 c);

int fn_8000F208(Task** out) {
    Task* e;
    u8 i;
    for (i = 0; i < 0xe; i++) {
        e = lbl_80309E24[i];
        if (e != 0) {
            ChrWork* w = e->work;
            if (fn_80015828(w->x10->xc) != 0) {
                *out = e;
                return 1;
            }
        }
    }
    return 0;
}

static inline void visit(HNode* n, u8 kind, s32 a, s32 b, s32 c) {
    s32 s0 = 0, s1;
    if (fn_8022E734(kind, n, &s0, &s1, 1, 0, 0)) {
        fn_8022E4CC(n, a, b, c, 0, 0);
        fn_8022E4CC(n, a, b, c, 1, 0);
    }
}

static inline void walk0(HNode* n, u8 kind, s32 a, s32 b, s32 c) {
    visit(n, kind, a, b, c);
    if (n->child != 0) {
        fn_8000F2A0(n->child, kind, a, b, c);
    }
    if (n->sibling != 0) {
        fn_8000F2A0(n->sibling, kind, a, b, c);
    }
}

static inline void walk1(HNode* n, u8 kind, s32 a, s32 b, s32 c) {
    visit(n, kind, a, b, c);
    if (n->child != 0) {
        walk0(n->child, kind, a, b, c);
    }
    if (n->sibling != 0) {
        walk0(n->sibling, kind, a, b, c);
    }
}

void fn_8000F2A0(HNode* n, u8 kind, s32 a, s32 b, s32 c) {
    s32 s0 = 0, s1;
    if (fn_8022E734(kind, n, &s0, &s1, 1, 0, 0)) {
        fn_8022E4CC(n, a, b, c, 0, 0);
        fn_8022E4CC(n, a, b, c, 1, 0);
    }
    if (n->child != 0) {
        walk1(n->child, kind, a, b, c);
    }
    if (n->sibling != 0) {
        walk1(n->sibling, kind, a, b, c);
    }
}

void fn_8000F6F8(HNode* n, u8 kind, s32 a, s32 b, s32 c) {
    fn_8000F2A0(n, kind, a, b, c);
}

void fn_8000E664(Tk_8000E664* t)
{
    W* w = t->work;
    U* u = w->u;
    DrawState s;
    int ok;
    int saved;

    switch (t->state) {
    case 0:
        t->state = 1;
        u->xc = 0.0f;
        break;
    case 1:
        t->state = 2;
        break;
    default:
        DrawStateDefault2D(&s);
        w->x44 = 2;
        s.control3d |= 0x800;
        s.attr_or |= 0x300;
        if (u->x10 != 0.0f) {
            s.attr_or |= 0x800;
        }
        ok = fn_8000CCBC(t, 0);
        s.colour.a = u->x10;
        s.colour.r = u->x14;
        s.colour.g = u->x18;
        s.colour.b = u->x1c;
        if (!(lbl_80309E5C.x8 & 0x1000000)) {
            if (lbl_80309E5C.x8 & 0x8000000) {
                u->x40 = 1;
                u->x44 = lbl_80309E5C.x18;
                u->x48 = lbl_80309E5C.x1c;
            } else {
                u->x40 = 0;
                u->x48 = 0.0f;
            }
            if (u->x50 & 0x40000000) {
                if (0.0f == u->x10) {
                    if (u->x50 & 0x20000000) {
                        fn_8000B77C(u->x4c, w->x0);
                        u->x50 &= ~0x20000000;
                    }
                } else if (u->x10 < 0.0f && u->x10 > -1.0f) {
                    fn_8000B77C(u->x4c, w->x0);
                    u->x50 |= 0x20000000;
                }
            }
        }
        if (u->x10 <= -1.0f) {
            ok = 0;
        }
        if (u->x40 != 0 && ok == 1) {
            fn_80060950(&u->x10);
        }
        if (ok == 1) {
            if (DrawStatePush(&s)) {
                saved = fn_80035908();
                fn_8000F0BC();
                fn_80299040(w->x8);
                if (w->x18 == 6) {
                    fn_8000B6F0(w);
                } else if (w->x18 == 8) {
                    if (lbl_80309E5C.x0 == 6) {
                        fn_80035910(0x5000);
                    }
                    fn_8000B5F4(w, u->x0);
                    u->x0 += 1.0f;
                    if (u->x0 >= (f32)w->xc->x4) {
                        u->x0 = u->x0 - (f32)w->xc->x4;
                    }
                } else if (w->x18 == 0x10) {
                    fn_8000B5F4(w, u->x0);
                    if (u->x0 < (f32)w->xc->x4 - 1.0f) {
                        u->x0 += 1.0f;
                    }
                }
                fn_80035910(saved);
                DrawStatePop(&s);
            }
        }
        break;
    }
    fn_800D2048();
}

void fn_8000EDE4(Tk_8000E664* t)
{
    W* w = t->work;
    U* u = w->u;
    DrawState s;
    int ok;
    int saved;
    u8 flag = 0;

    switch (t->state) {
    case 0:
        t->state = 1;
        u->xc = 0.0f;
        break;
    case 1:
        t->state = 2;
        break;
    default:
        DrawStateDefault2D(&s);
        s.control3d |= 0x800;
        if (w->x44 == 2) {
            flag = 1;
            s.attr_or |= 0x200;
            if (u->x10 != 0.0f) {
                s.attr_or |= 0x800;
            }
            w->x44 = 0;
        } else {
            s.attr_and &= ~0x700;
            if (u->x10 != 0.0f) {
                s.attr_or |= 0x800;
            }
        }
        ok = fn_8000CCBC((void *)(t), 0);
        if (!(lbl_80309E5C.x8 & 0x1000000)) {
            if (lbl_80309E5C.x8 & 0x8000000) {
                u->x40 = 1;
                u->x44 = lbl_80309E5C.x18;
                u->x48 = lbl_80309E5C.x1c;
            } else {
                u->x40 = 0;
                u->x48 = 0.0f;
            }
        }
        s.colour.a = u->x10;
        s.colour.r = u->x14;
        s.colour.g = u->x18;
        s.colour.b = u->x1c;
        if (u->x10 <= -1.0f) {
            ok = 0;
        }
        if (u->x40 != 0 && ok == 1) {
            fn_80060950(&u->x10);
        }
        saved = fn_80035908();
        fn_8000F0BC();
        if (ok == 1) {
            if (DrawStatePush(&s)) {
                fn_80299040(w->x8);
                if (w->x18 == 1) {
                    fn_8000B6F0(w);
                } else if (w->x18 == 7) {
                    fn_8000B5F4(w, u->x0);
                    u->x0 += 1.0f;
                    if (u->x0 >= (f32)w->xc->x4) {
                        u->x0 = u->x0 - (f32)w->xc->x4;
                    }
                } else if (w->x18 == 0xf) {
                    fn_8000B5F4(w, u->x0);
                    if (u->x0 < (f32)w->xc->x4 - 1.0f) {
                        u->x0 += 1.0f;
                    }
                }
                DrawStatePop(&s);
            }
        }
        fn_80035910(saved);
        fn_800D2048();
        if (flag == 1) {
            w->x44 = 2;
        }
        break;
    }
}

void fn_8000D488(Bounce* o, f32* pos)
{
    s16 axis = 0;
    int hit;

    pos[0] += o->vel[0];
    pos[1] += o->vel[1];
    pos[2] += o->vel[2];
    if (o->vel[0] != 0.0f) {
        axis = 0;
    } else if (o->vel[1] != 0.0f) {
        axis = 1;
    } else if (o->vel[2] != 0.0f) {
        axis = 2;
    }
    switch (o->mode) {
    case 0:
        if (o->vel[axis] >= 0.0f) {
            if (pos[axis] >= o->b1[axis]) {
                fn_80071CF0(o->b2, pos);
            }
        } else if (pos[axis] <= o->b1[axis]) {
            fn_80071CF0(o->b2, pos);
        }
        break;
    case 1:
        if (o->vel[axis] >= 0.0f) {
            if (pos[axis] >= o->b2[axis]) {
                fn_80071CF0(o->b1, pos);
            }
        } else if (pos[axis] <= o->b2[axis]) {
            fn_80071CF0(o->b1, pos);
        }
        break;
    case 2:
        hit = 0;
        if (o->state == 0) {
            if (o->vel[axis] >= 0.0f) {
                if (pos[axis] >= o->b1[axis]) {
                    fn_80071CF0(o->b1, pos);
                    hit = 1;
                    o->state = 1;
                }
            } else if (pos[axis] <= o->b1[axis]) {
                fn_80071CF0(o->b1, pos);
                hit = 1;
                o->state = 1;
            }
        } else {
            if (o->vel[axis] >= 0.0f) {
                if (pos[axis] >= o->b2[axis]) {
                    fn_80071CF0(o->b2, pos);
                    hit = 1;
                    o->state = 0;
                }
            } else if (pos[axis] <= o->b2[axis]) {
                fn_80071CF0(o->b2, pos);
                hit = 1;
                o->state = 0;
            }
        }
        if (hit == 1) {
            o->vel[0] = -1.0f * o->vel[0];
            o->vel[1] = -1.0f * o->vel[1];
            o->vel[2] = -1.0f * o->vel[2];
        }
        break;
    }
}

void fn_8000D8FC(Tk_8000D8FC* t)
{
    U_8000D8FC* u = t->work->w;
    N0* n = u->x0;
    Nd* a = (Nd*)n->x0;
    Nd* c = a->x2c->x2c;
    Q4* e = c->x4->x0;
    s32 ang[3];
    f32 tmp[3];
    int k;

    if (a == NULL) {
        t->state = 3;
    }
    switch (t->state) {
    case 0:
        for (k = 0; k < 3; k++) {
            tmp[k] = ((Nd*)n->x0)->x2c->x2c->v[k] + (((Nd*)n->x0)->x2c->v[k] + (n->x1c[k] + ((Nd*)n->x0)->v[k]));
            if (k == 0) {
                e->e[0].v[0] -= c->x4->v[0];
                e->e[1].v[0] -= c->x4->v[0];
                e->e[2].v[0] -= c->x4->v[0];
                e->e[3].v[0] -= c->x4->v[0];
                tmp[k] += c->x4->v[0];
                c->x4->v[0] = 0.0f;
            } else if (k == 2) {
                e->e[0].v[2] -= c->x4->v[2];
                e->e[1].v[2] -= c->x4->v[2];
                e->e[2].v[2] -= c->x4->v[2];
                e->e[3].v[2] -= c->x4->v[2];
                tmp[k] += c->x4->v[2];
                c->x4->v[2] = 0.0f;
            }
            ((Nd*)n->x0)->v[k] = 0.0f;
            ((Nd*)n->x0)->x2c->v[k] = 0.0f;
            ((Nd*)n->x0)->x2c->x2c->v[k] = 0.0f;
            n->x1c[k] = tmp[k];
        }
        t->state = 1;
    case 1:
        fn_800120D0(ang);
        switch (u->x4) {
        case 0:
            n->x2c = ang[1] + 0x8000;
            break;
        case 1:
            n->x2c = ang[1] + 0x4000;
            break;
        case 2:
            n->x2c = ang[1];
            break;
        case 3:
            n->x2c = ang[1] - 0x4000;
            break;
        }
        break;
    case 3:
        t->flags |= 0x40;
        break;
    }
}

void fn_8000BB28(u8 idx)
{
    int k = idx;
    Node_BB28* o = NULL;
    s16 a;
    s16 kind;
    Work_BB28* w;
    Sub2_BB28* u;
    u32* p0;
    u32 p8;

    a = lbl_80309E5C.tbl[lbl_80309E5C.cur].recs[k].x16;
    kind = lbl_80309E5C.tbl[lbl_80309E5C.cur].recs[k].x18;
    fn_8006CF28(lbl_80309E5C.tbl[lbl_80309E5C.cur].x4->x8, &p0, a);
    switch (kind) {
    case 7:
    case 8:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
        fn_8006CEEC(lbl_80309E5C.tbl[lbl_80309E5C.cur].x4->x8, &p8, 0, a);
        break;
    }
    switch (kind) {
    case 1:
    case 7:
    case 15:
        o = fn_802268E8(lbl_803475A8, fn_8000F0A4(0));
        break;
    case 2:
    case 3:
    case 4:
    case 5:
    case 13:
    case 17:
    case 18:
    case 19:
    case 20:
        o = fn_802268E8(lbl_803475A8, fn_8000F0A4(1));
        break;
    case 6:
    case 8:
    case 16:
        o = fn_802268E8(lbl_803475A8, fn_8000F0A4(2));
        break;
    case 9:
    case 10:
    case 11:
    case 12:
    case 14:
        o = fn_802268E8(lbl_803475A8, fn_8000F0A4(3));
        break;
    }
    fn_80061F58(&o->work, 0x58, 0);
    w = o->work;
    w->r = lbl_80309E5C.tbl[lbl_80309E5C.cur].recs[k];
    w->r.x8 = (u32*)((u32)p0 + 8);
    lbl_80309E5C.tbl[lbl_80309E5C.cur].ptrs[k] = w;
    if (*w->r.x8 != 0) {
        w->r.x40 = fn_80227810(w->r.x8);
    } else {
        w->r.x8 = 0;
    }
    w->r.x0 = (void*)*p0;
    switch (kind) {
    case 7:
    case 8:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
        w->r.xc = p8;
        break;
    }
    lbl_80309E5C.tbl[lbl_80309E5C.cur].recs[k] = w->r;
    if (kind != 0xff) {
        fn_80061F58(&w->x4c, 0x54, 0);
        lbl_80309E5C.tbl[lbl_80309E5C.cur].x10 = w->x4c;
        fn_8022F00C(w->r.x0);
    }
    switch (kind) {
    case 6:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 14:
    case 16:
        if (fn_8000CF94(((Cx_BB28*)w->r.x0)->x2c->x2c) == 1) {
            u = w->x4c;
            fn_80061F58(&u->x4c, 0xc, 0);
            fn_8000B8E4(u->x4c, w->r.x0);
            w->x4c->x50 |= 0x40000000;
        }
        break;
    }
}

void fn_8000FBA8(Actor* o) {
    Owner_8000FBA8* ow = (Owner_8000FBA8*)o->r->m;

    if (ow->a != 0) {
        ow->a->r->m->flags |= 0x400000;
    }
    if (ow->b != 0) {
        ow->b->r->m->flags |= 0x400000;
    }
    if (ow->c != 0) {
        ow->c->r->m->flags |= 0x400000;
    }
}

void fn_8000B6F0(W* o) {
    if (o->x0 != 0) {
        njPushMatrixEx();
        fn_80286EE8();
        fn_8028B498();
        njTranslate(0, o->tx, o->ty, o->tz);
        njRotateXYZ(0, o->rx, o->ry, o->rz);
        njScale(0, o->sx, o->sy, o->sz);
        fn_80035140(o->x0, o->x44);
        njPopMatrixEx();
    }
}

void fn_8000DDFC(Task_8000DDFC* t) {
    Par* p = t->work->x4c;
    Dst* d = p->xc;
    if (d->x0 == 0) {
        t->mode = 3;
    }
    switch (t->mode) {
    case 0:
        p->x8 = p->x8 + p->x4;
        if (p->x8 >= 360.0f) {
            p->x8 = p->x8 - 360.0f;
        }
        d->x20 = p->x0 * njSin((Angle)(182.04445f * p->x8));
        break;
    case 3:
        t->flags |= 0x40;
        break;
    }
}

s32 fn_8000AD30(u8 dir)
{
    NJS_POINT3 a;
    NJS_POINT3 b;
    fn_80012130(&a);
    fn_80012100(&b);
    switch (dir) {
    case 0:
        if (b.x >= a.x) return 1;
        break;
    case 1:
        if (b.x <= a.x) return 1;
        break;
    case 2:
        if (b.z >= a.z) return 1;
        break;
    case 3:
        if (b.z <= a.z) return 1;
        break;
    }
    return 0;
}

void fn_8000DF50(Obj_8000DF50* o) {
    B* b;
    A* a = o->x24->x4c;
    b = a->x1c;
    if (b->x0 == 0) o->state = 3;
    switch (o->state) {
    case 0:
        if (a->xc == 0) b->x28 += a->x0; else b->x28 -= a->x0;
        if (a->xc == 0) b->x2c += a->x4; else b->x2c -= a->x4;
        if (a->xc == 0) b->x30 += a->x8; else b->x30 -= a->x8;
        break;
    case 3:
        o->flags |= 0x40;
        break;
    }
}

s32 fn_80010F9C(s16 a, s16 b, s16 c, s16 d)
{
    s16 r = rand() % 100;
    if (r >= 90) {
        r = 100;
    }
    if (r < 10) {
        r = 0;
    }
    if (b == 0) {
        b = 1;
    }
    if ((s16)((f32)c / 10.0f * (f32)(a * r) / (f32)b) > d) {
        return 1;
    }
    return 0;
}

void fn_8000AA98(void)
{
    s32 i;
    for (i = 0; i < lbl_803098C8.count; i++) {
        if (lbl_803098C8.buf[i] != 0) {
            fn_801E1718(lbl_803098C8.buf[i]);
            lbl_803098C8.buf[i] = 0;
        }
    }
    for (i = 0; i < 32; i++) {
        if (lbl_803098C8.res[i] != 0) {
            lbl_803098C8.res[i] = 0;
        }
    }
}

s16 fn_800108EC(s32 a, s32 b, s32 unused, Fn108EC* c) {
    f32 x = a;
    f32 y;
    s32 v;
    if (x < 0.0f) {
        x = 0.0f;
    }
    y = x;
    x *= 0.975f;
    y *= 0.05f;
    x += y * (0.000030517578f * rand());
    if ((rand() & 7) == 0) {
        x += 1.0f;
    }
    if (b <= 5) {
        x *= c->stat[b];
        x /= 10.0f;
    }
    v = (s16)x;
    if (c->flags & 1) {
        v = (s16)(x / 2);
    }
    if (v >= 10000) {
        v = 9999;
    }
    return v;
}

static inline s32 GetNode(Mid_800102C8* m, s16 sel, Node_800102C8** out) {
    switch (sel) {
    case 1:
        if (m->e0 != NULL) {
            *out = m->e0;
            return 1;
        }
        break;
    case 2:
        if (m->e4 != NULL) {
            *out = m->e4;
            return 1;
        }
        break;
    }
    return 0;
}

s32 fn_800102C8(Ent_800102C8* obj, s16 sel, void** out) {
    Node_800102C8* n;

    if (GetNode(obj->h->mid, sel, &n)) {
        *out = n->val;
        return 1;
    }
    return 0;
}

void fn_8000DEC8(Actor_8000DEC8* a) {
    Mid_8000DEC8* m = a->holder->mid;
    Sub* s = m->sub;

    if (s->link == 0) {
        a->state = 3;
    }
    if ((s32)a->state != 3) {
        if ((s32)a->state >= 3) {
            return;
        }
        if ((s32)a->state != 0) {
            return;
        }
        if (m->mode != 1) {
            return;
        }
        if (s->pos <= 0.0f) {
            s->pos = s->pos + m->speed;
        } else {
            s->pos = s->pos - m->speed;
        }
    } else {
        a->flags |= 0x40;
    }
}

void fn_8000C8AC(ModelSrc* src) {
    char name[0x20];
    ModelCache* c;
    ModelCache* n;

    sprintf(name, lbl_802ACCE8, lbl_80309E5C.x0, (s16)src->id);
    c = lbl_803473A0;
    if (c->x8 == 0) {
        {
            void* buf = fn_801E1C7C(src->size);
            memcpy(buf, src->data, src->size);
            c->x8 = fn_801DB124(buf);
            fn_8006CF54(c);
            strcpy(c->name, name);
            c->x4 = 0;
        }
        return;
    }
    for (;;) {
        if (c->x8 != 0) {
            if (fn_8025EF88(name, c->name) == 0) return;
        }
        if (c->x38 == 0) break;
        c = c->x38;
    }
    n = fn_801E1C7C(0x44);
    c->x38 = n;
    n = c->x38;
    memset(n, 0, 0x44);
    n->x34 = c;
    {
        void* buf = fn_801E1C7C(src->size);
        memcpy(buf, src->data, src->size);
        n->x8 = fn_801DB124(buf);
        fn_8006CF54(n);
        strcpy(n->name, name);
        n->x4 = 0;
    }
}

int fn_8000CF94(Ob_8000CF94* o) {
    if (o->x4 != 0 && (s16)fn_80047F9C(o) != 0) {
        switch (o->x4->x0->x0 & 0xff) {
        case 0x2a:
            return 1;
        }
    }
    return 0;
}

void fn_8000CEE8(Task* task)
{
    CE8State* st = ((CE8Work*)task->work)->st;
    CE8Pos* pos = st->x0;
    CE8Ext* ext = st->x4;

    st->x4c++;
    if (st->prm.xa != -1 && st->x4c > st->prm.xa) {
        task->state = 3;
    } else {
        st->x4e = 0;
        if (st->x44 != 0.0f) {
            ext->x10 = -1.0f;
            st->x48 = 0;
        } else {
            st->x48 = 1;
        }
        fn_80071CF0(&st->prm.from, &pos->p1c);
        task->state = 2;
    }
}


extern void njUnitVector(NJS_VECTOR *v);
static inline s32 Passed(f32 c, f32 a, f32 b) {
    if (a > b) {
        if (c >= a) {
            return 1;
        }
    } else if (c <= a) {
        return 1;
    }
    return 0;
}

void fn_8000CFFC(Task* t) {
    NJS_VECTOR d;
    s32 i;
    CE8Work* w;
    CE8Pos* pos;
    CE8State* st;
    CE8Prm* prm;
    CE8Ext* ext;
    w = t->work;
    st = w->st;
    ext = st->x4;
    prm = &st->prm;
    pos = st->x0;
    ext->x50 |= 0x80000000;
    switch (t->state) {
    case 0:
        if (prm->x1c == 0) {
            t->state = 3;
        }
        d.x = prm->to[0] - prm->from[0];
        d.y = prm->to[1] - prm->from[1];
        d.z = prm->to[2] - prm->from[2];
        njUnitVector(&d);
        st->v[0] = d.x * prm->x1c;
        st->v[1] = d.y * prm->x1c;
        st->v[2] = d.z * prm->x1c;
        for (i = 0; i < 3; i++) {
            st->s[i] = prm->to[i] - st->v[i] * prm->x1e;
            if (prm->to[i] != prm->from[i]) {
                st->x4a = i;
            }
        }
        if (prm->x0 == 0 && prm->x1e != 0) {
            st->x44 = 1.0f / prm->x1e;
        }
        if (0.0f != st->x44) {
            ext->x10 = -1.0f;
            st->x48 = 0;
        } else {
            st->x48 = 1;
        }
        t->state = 2;
        break;
    case 2:
        switch (st->x48) {
        case 0:
            ext->x10 = ext->x10 + st->x44;
            if (ext->x10 >= 0.0f) {
                ext->x10 = 0.0f;
                st->x48 = 1;
            }
            break;
        case 1:
            ext->x50 &= 0x7fffffff;
            if (0.0f != st->x44) {
                if (Passed(pos->p1c[st->x4a], prm->to[st->x4a], prm->from[st->x4a]) == 1) {
                    st->x48 = 2;
                }
            } else if (Passed(pos->p1c[st->x4a], prm->to[st->x4a], prm->from[st->x4a]) == 1) {
                if (prm->x20 != 0) {
                    st->x4e = 0;
                    t->state = 1;
                } else {
                    fn_8000CEE8(t);
                }
            }
            break;
        case 2:
            ext->x10 = ext->x10 - st->x44;
            if (ext->x10 <= -1.0f) {
                ext->x10 = -1.0f;
                if (prm->x20 != 0) {
                    st->x4e = 0;
                    t->state = 1;
                } else {
                    fn_8000CEE8(t);
                }
            }
            break;
        }
        pos->p1c[0] = pos->p1c[0] + st->v[0];
        pos->p1c[1] = pos->p1c[1] + st->v[1];
        pos->p1c[2] = pos->p1c[2] + st->v[2];
        break;
    case 1:
        st->x4e = st->x4e + 1;
        if (st->x4e >= prm->x20) {
            fn_8000CEE8(t);
        }
        break;
    case 3:
        ext->x10 = -1.0f;
        break;
    case 4:
        t->flags |= 0x40;
        break;
    }
}

void fn_8000E02C(Task* task)
{
    E02Work* w = task->work;
    E02Ctr* c;

    c = w->ctr;
    if (w->x0 == 0) {
        task->state = 3;
    }
    switch (task->state) {
    case 0:
        if (c->cur >= c->max) {
            task->state = 1;
        } else {
            c->cur = c->cur + 1;
        }
        break;
    case 1:
        fn_802307EC(w->x0, &c->x4, 0);
        break;
    case 3:
        task->flags |= 0x40;
        break;
    }
}

void fn_8000F0BC(void)
{
    u16 id = lbl_80309E5C.x0;

    if (id == 0xf || id == 0x10 || id == 0x1f) {
        fn_80035910(0x10004000);
    } else if (id == 0x6e || id == 0x71 || id == 0x74 || id == 0x78 || id == 0x80 || id == 0x82) {
        fn_80035910(0x10104000);
    } else if (id == 0x1e) {
        fn_80035910(0x10008000);
    } else {
        fn_80035910(0x08000000);
    }
}

s32 fn_8000AE08(void* obj, f32* out, u8 dir) {
    NJS_POINT3 a;
    NJS_POINT3 c;
    NJS_POINT3 p;
    s32 b[3];
    f32 f;
    f32 s;
    u16 id;
    fn_80012130(&a);
    fn_800120D0(b);
    fn_80012100(&c);
    fn_80071CF0(obj, &p);
    switch (dir) {
    case 0:
        p.z = a.z;
        p.y = a.y;
        p.x += 2.5f;
        if (a.x >= p.x) {
            LIMIT()
        }
        break;
    case 1:
        p.z = a.z;
        p.y = a.y;
        p.x -= 2.5f;
        if (a.x <= p.x) {
            LIMIT()
        }
        break;
    case 2:
        p.x = a.x;
        p.y = a.y;
        p.z += 2.5f;
        if (a.z >= p.z) {
            LIMIT()
        }
        break;
    case 3:
        p.x = a.x;
        p.y = a.y;
        p.z -= 2.5f;
        if (a.z <= p.z) {
            LIMIT()
        }
        break;
    case 4:
        p.z = a.z;
        p.x = a.x;
        p.y += 2.5f;
        if (a.y >= p.y) {
            LIMIT()
        }
        break;
    }
    if (lbl_80309E5C.x0 != 0x3e && lbl_80309E5C.x0 != 6) {
        if (fn_8000AD30(dir) == 1) {
            return 0;
        }
    }
    f = fn_80071E9C(&a, &p);
    switch (id = lbl_80309E5C.x0) {
    case 0x46: case 0x47: case 0x4b: case 0x81:
        s = 15.0f;
        break;
    default:
        s = 45.0f;
        break;
    }
    if (f < 0.0f) {
        f = 0.0f;
    }
    f = -(1.0f - f / s);
    if (f < 0.0f) {
        if (f <= -1.0) {
            f = -1.0f;
        }
        switch (id) {
        case 0x46: case 0x47: case 0x49: case 0x4b:
        case 0x80: case 0x81: case 0x82:
        case 0x92: case 0x93: case 0x94: case 0x95:
            if (f <= -0.9f) {
                f = -0.9f;
            }
            *out = f;
            break;
        default:
            *out = f;
            break;
        }
        return 1;
    }
    return 0;
}

void fn_80010474(s16 i) {
    s16 v = lbl_80309DE4[i]->x18;

    if (fn_80008274(lbl_80309700[i]->work->x2) == 0xc6) {
        v /= 2;
    } else {
        v /= 4;
    }
    if (v >= lbl_80309DE4[i]->x14) {
        lbl_80309DE4[i]->bits |= 0x8000;
    } else {
        lbl_80309DE4[i]->bits &= ~0x8000;
    }
}

#ifdef NONMATCHING
extern void fn_80046BB0(char* name, s32* out);
extern void fn_80009500(void* a, s32 b, void* c);
#endif

#ifdef NONMATCHING
s8 fn_8000F8F8(void* a, void* b, s32 unused, s32 c, void* d)
{
    s8 tbl[6] = { 2, 2, 0, 1, 1, 1 };
    char buf[32];
    s32 tmp;
    s32 kind;
    s8 i;
    s8 id;
    s8 x;
    id = fn_80020E10(b);
    if (id >= 0) {
        kind = id;
        if (kind != 2) {
            x = fn_8000FA30(c);
            id = tbl[kind];
            for (i = 0; i < id; i++) {
                switch (i) {
                case 0:
                    sprintf(buf, "E99%02d%02d%d", kind, x, i);
                    break;
                default:
                    switch (x) {
                    case 16:
                    case 17:
                        sprintf(buf, "E99%02d%02d%d", kind, x, i);
                        break;
                    default:
                        sprintf(buf, "E99%02d00%d", kind, i);
                        break;
                    }
                    break;
                }
                fn_80046BB0(buf, &tmp);
                fn_80009500(a, tmp, d);
            }
            return i;
        }
    }
    return 0;
}
#endif

/* NEAR (20 lines): params land in other callee-saved registers (orig b r31, d r30, a r29, c r28). */
#ifdef NONMATCHING
s32 fn_80010E68(s16 a, s16 b, s8 c, s8 d)
{
    s16 r = fn_8025ECC4() % 100;
    s32 res;
    if (r >= 90) {
        res = 100;
    } else if (r < 10) {
        res = 0;
    } else {
        if (b == 0) b = 1;
        res = (s16)((1.0f - (f32)c / 255.0f) * (f32)(a * r) / (f32)b);
    }
    if ((s16)res >= d) return 1;
    return 0;
}
#endif
Task* fn_800215EC(s32 id);
extern s32 fn_800154BC(void);

void fn_800110C8(u8* list, s8 mode, s8 count) {
    s8 i;
    s8 n;

    if (count >= 0) {
        n = count;
    }
    for (i = 0; i < n; i++) {
        Task* e = fn_800215EC(list[i]);
        if (mode == 1) {
            if (fn_800154BC() != 0) {
                e = 0;
            }
        }
        if (e != 0) {
            ChrWork* w = e->work;
            ChrInfo* m = w->st;
            m->xf0 &= 0x7fffffff;
        }
    }
}
