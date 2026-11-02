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
typedef struct {
    u16 x0;
    u8 pad2[6];
    u32 x8;
    u8 padc[0x18 - 0xc];
    s32 x18;
    f32 x1c;
    int cur;
    void* x24;
    Ent_BB28* tbl;
} Sys_80309E5C;
extern Sys_80309E5C lbl_80309E5C;
extern Task* lbl_80347394;
extern Entry16 lbl_80309730[];
extern s32 lbl_8034733C;
typedef struct Pair {
    u32 a;
    u32 b;
} Pair;
extern Task* lbl_80309E24[];
extern void fn_802A9B94(s32 a, s32 b, s32 c, void (*f)(void));
s16 fn_800086BC(Task* t, s16 a, s16 b, Ent_80008800* tbl, CondLink* e, u8 f);
/* The character record a character task's work points at (0x4c). */
typedef struct Unit_8001D288 {
    s8 id;              /* 0x000 */
    u8 pad1[0xEC - 0x1];
    u32 xec;            /* 0x0EC: 0x200000 = large */
    u8 padf0[0x15C - 0xF0];
    f32 x15c;           /* 0x15C: ground height */
} Unit_8001D288;
/* A character task's work: position at 0x1c, rotation at 0x28. */
typedef struct Wk_8001D288 {
    u8 pad0[0x1C];
    f32 x;              /* 0x1C */
    f32 y;              /* 0x20 */
    f32 z;              /* 0x24 */
    f32 rot[3];         /* 0x28 */
    u8 pad34[0x4C - 0x34];
    Unit_8001D288* w;   /* 0x4C */
} Wk_8001D288;
extern void fn_80061C80(void*, f32, f32, f32, int);
extern void fn_800615B4(void* p, void* v, void* b);
extern u32 fn_800153E0(s32, s16);
extern s16 fn_800760EC(void*, s16, s16);
extern s8 fn_80020E10(void* p);

inline ChrWork* ChrW(Task* t)
{
    return t->work;
}
extern Sys_80309EC8 lbl_80309EC8;
extern void fn_800614FC(void *p, void *v);
extern void fn_80071CF0(void *p, void *v);
extern void *fn_80021658(s8 idx);
extern s16 lbl_80347378;
extern u32 lbl_803472F4;
extern void fn_80015580(void);
typedef struct Unit { u8 pad[0xEC]; u32 xec; u32 xf0; u32 xf4; } Unit;
typedef struct Wk_8001C31C { u8 pad[0x4C]; Unit* w; } Wk_8001C31C;
typedef struct Tk_8001C31C { u8 pad[0x24]; Wk_8001C31C* work; } Tk_8001C31C;
extern void fn_8001C6CC(void* a, void* b, void* c, void* d);
extern void fn_8006C860(const char* s, void* p);
typedef struct Wk_8001D1D8 { u8 pad[0x1C]; } Wk_8001D1D8;
typedef struct Tk_8001D1D8 { u8 pad[0x24]; Wk_8001D1D8* work; } Tk_8001D1D8;
extern s32 fn_800179E4(s16);
typedef struct { s16 id; } Wk;
typedef struct { u8 pad[0x24]; Wk* work; } Tk;
extern Tbl lbl_803097F0;
extern void fn_80060950(void*);
extern int fn_80035908(void);
extern void fn_80035910(int);
extern void fn_800D2048(void);
typedef struct {
    s16 x0;
    u8 pad2[2];
    u32 x4;
} W_80016580;
typedef struct {
    u8 pad[0x1c];
    u32 x1c;
} Chr;
int fn_80016A18(s8 mode);
void fn_80015138(u8 flag);
extern void fn_80032B4C(void);
extern int fn_800168D8(int, void*, u8);
extern u8 lbl_80346ABC;
extern u8 lbl_80346ABD;
extern void fn_8007E678(void*, void*);
extern void fn_8029D008(s32);
extern void njTranslate(void*, f32, f32, f32);
extern void njRotateX(void*, s32);
extern void njRotateY(void*, s32);
extern void njRotateZ(void*, s32);
extern void njScale(void*, f32, f32, f32);
extern void fn_80035468(void*, void*, void*, f32, u8);
extern void fn_80035228(void*, void*, f32, u8);
extern void fn_800353F4(void*, void*, void*, f32, u8);
extern void fn_80035380(void*, void*, f32, u8);
extern void fn_8003529C(void*, void*, f32, u8);
extern u32 fn_800153E0(s32, s16);
extern s16 fn_800760EC(void*, s16, s16);
extern s8 fn_8002EEFC(Task*, u32*);
extern s8 fn_80030AE8(u32, ChrInfo*);
extern s16 fn_80009030(Ent_80008800* list, s16 p1, s16 p2, s16 c, s16 d);
extern void fn_800312F0(Task*, s16, s16, s8);
extern void fn_80031254(Task*);
extern void fn_80037918(Task* t);
extern u8 fn_80078478(int a);
extern s32 fn_8003136C(Task* t);
extern void fn_8002F154(Task* t, u32* out);
int fn_8001CED0(Task* t);
extern s8 lbl_80347334;
extern int fn_80078610(u8);
extern int fn_8006D1C4(void);
extern void fn_80061C80(void*, f32, f32, f32, int);
extern void fn_80071F84(void*, void*, void*);
void fn_80014AB8(u8 kind, SysObj* o);
extern int fn_8001EE24(Task*, NJS_POINT3*);
extern s8 fn_80017A14(ChrInfo*);
extern int fn_80071C74(ChrWork*, f32, f32);
extern int fn_80071C34(f32, f32, f32, f32);
extern void fn_80071BCC(void*, int, f32);
extern f32 fn_8006116C(int);
extern void fn_80061080(f32*, f32*);
extern int fn_80061F58(void*, int, int);
#define FLD(p, off, T) (*(T*)((u8*)(p) + (off)))
s8 fn_80020E10(void* p);
s16 fn_80008274(s16 v);
void fn_800615B4(void *p, void *v, void *b);
s32 fn_8003DCF4(void* a, void* b);
void fn_80061518(void* a, NJS_POINT3* b);
void fn_80012130(void* p);
typedef struct {
    u8 pad[0x1c];
    NJS_POINT3 pos;
} Ctx8001E19C;
typedef struct {
    u8 pad[0x24];
    Ctx8001E19C *obj;
} Ctx8001E19C_outer;
extern void fn_80071D0C(NJS_POINT3 *out, NJS_POINT3 *a, NJS_POINT3 *b, f32 s);
typedef struct Inner8001FA18 {
    u8 pad0[0xf0];
    u32 flags;
    u8 pad1[0x10];
    NJS_POINT3 v104;
    NJS_POINT3 v110;
    NJS_POINT3 v11c;
} Inner8001FA18;
typedef struct Obj8001FA18 {
    u8 pad0[0x24];
    struct Obj8001FA18 *sub;
    u8 pad1[0x4];
    u32 f2c;
    u8 pad2[0x1c];
    Inner8001FA18 *inner;
} Obj8001FA18;
typedef struct Obj80020B28 {
    u8 pad0[0x6];
    s16 x6;
    s16 x8;
    u8 pad1[0xa];
    s16 x14;
    s16 x16;
    u8 pad2[0xd4];
    u32 flags;
} Obj80020B28;
Task* fn_800215EC(s8 id);
void fn_80015020(s8 id);
void fn_8001DD00(ChrInfo* o, s8 v);
extern s32 lbl_80347330;
extern s32 lbl_80347328;
extern void njPushMatrixEx(void);
extern void njPopMatrixEx(void);
extern void fn_80286EE8(void);
extern void fn_8028B498(void);
extern void fn_80035140(void* model, u8 flag);
typedef struct Obj_80014784 {
    u8 pad[0x24];
    SysObj* data;
} Obj_80014784;
void fn_800136DC(Task* t);
typedef s32 Angle;
extern u32 strlen(const char* s);
typedef struct Inner_80019D7C { u8 pad0[2]; s16 x2; u8 pad4[0xe]; s16 x12; u8 pad14[0xe8-0x14]; s16 xe8; } Inner_80019D7C;
typedef struct Work_80019D7C { u8 pad[0x4c]; Inner_80019D7C* in; } Work_80019D7C;
/* The 0x18-byte work of the fn_80019B70 task: two character tasks and up to three (kind, value) pairs. */
typedef struct SeqWork {
    s8 idx;             /* 0x00 next pair */
    u8 pad1[3];
    Task* owner;        /* 0x04 */
    Task* b;            /* 0x08 */
    s16 kind[3];        /* 0x0c, 0 ends */
    s16 val[3];         /* 0x12 */
} SeqWork;
inline SeqWork* SeqW(Task* t)
{
    return t->work;
}
void fn_80019B70(Task* t);
void fn_80018CBC(Task* t, s16 idx, s16 mode, ChrWork* alt, s16 kind);
s32 fn_8001C1F0(Task* o);
typedef struct Cmd { u8 pad0[0x10]; s16 x10; s16 x12; } Cmd;
typedef struct Item { s16 lo; s16 hi; u8 pad4[8]; Cmd* obj; } Item;
extern s32 fn_8006EDA0(void);
typedef struct Tsk_80017018 { u8 pad_00[0x24]; ChrWork *work; } Tsk_80017018;
extern s16 fn_80020094(ChrWork *w, s16 a, s16 b, s8 flag);
extern s32 fn_800300C4(s16 i);
extern s32 rand(void);
typedef struct { u8 pad0[8]; u32 flags; u8 pad0c[0x18 - 0xc]; } Ent18_8001BAC0;
typedef struct {
    u8 pad0[6];
    s16 x6;
    s16 x8;
    u8 pad0a[0x20 - 0xa];
    s16 x20;
    u8 pad22[0x26 - 0x22];
    s16 x26;
    u8 pad28[0xdc - 0x28];
    Ent18_8001BAC0* xdc;
    u8 pade0[0xec - 0xe0];
    u32 xec;
} Unit_8001BAC0;
typedef struct Model { u8 pad[0x154]; Joint* joints; } Model;
typedef struct Work_8001E3D8 {
    u8 pad0[0x14];
    s16 idx;
    u8 pad16[6];
    NJS_POINT3 off;
    NJS_POINT3 pos;
    u8 pad34[0x4c - 0x34];
    Model* model;
} Work_8001E3D8;
typedef struct Task_8001E3D8 { u8 pad[0x24]; Work_8001E3D8* work; } Task_8001E3D8;
typedef struct Dat1E { u8 pad00[0x154]; u8 *tbl; } Dat1E;
typedef struct Wk1E {
    u8 pad00[0x14];
    s16 idx;
    u8 pad16[6];
    f32 x1c, x20, x24;
    NJS_POINT3 x28;
    u8 pad34[0x18];
    Dat1E *d;
} Wk1E;
typedef struct Tk1E { u8 pad00[0x24]; Wk1E *work; } Tk1E;
typedef struct Wk1E_8001E238 {
    u8 pad00[0x14];
    s16 idx;
    u8 pad16[6];
    f32 x1c, x20, x24;
    NJS_POINT3 x28;
    u8 pad34[0x18];
    Dat1E *d;
} Wk1E_8001E238;
typedef struct Tk1E_8001E238 { u8 pad00[0x24]; Wk1E_8001E238 *work; } Tk1E_8001E238;
extern void fn_8002923C(s16 id, u16 mask, s32 c);
extern s32 fn_8001604C(void* t, s8* arr, s32 a, s32 b);
extern s32 fn_80016234(void* t, s8 flag, s32 a, s32 b, s32 c);
extern s32 fn_80015EC8(void* t, s8* arr, s8 flag);
extern void fn_8001E6DC(NJS_POINT3* out, s8 v);
extern s8 fn_80018398(NJS_POINT3* v, s32 a);
int fn_8001D944(s8 id, Task* t);
extern void fn_80075F2C(void *t);
extern s32 fn_8006DB94(void);
extern void fn_80032C68(void);
extern void fn_80017CB8(Task *t, s16 v);
/* lbl_80309E24: the character task table (void* in unit_80005B50.c). */
extern Task* lbl_80309E24[];
extern void fn_8001BE2C(Task* t);
typedef struct { u8 pad[0xec]; u32 xec; } Flags;
typedef struct { u8 pad[0x1c]; NJS_POINT3 pos; u8 pad28[0x4c - 0x28]; Flags* x4c; } Work_800171F0;
typedef struct { u8 pad[0x24]; Work_800171F0* work; } Obj_800171F0;
extern f32 fn_80071E9C(void*, void*);
void fn_8001E19C(NJS_POINT3 *self, NJS_POINT3 *out, void *ctx, NJS_POINT3 *v);
extern void fn_802917C8(NJS_POINT3 *pts, NJS_POINT3 *out, NJS_POINT3 *tmp, f32 t);
typedef struct {
    s32 key;
    s32 val;
} LblEnt;
extern LblEnt lbl_802ACDF0[];
extern s32 fn_80076170(f32 a, f32 b, void *o, s32 id, s32 k, s32 j);
extern void fn_80072770(void *o);
extern void* memset(void* dst, int c, u32 n);
typedef struct Wrap8001FD7C {
    u8 pad0[0x24];
    ChrWork *ent;
} Wrap8001FD7C;
typedef struct Ent8001FDD8 {
    s16 key0;
    s16 type;
    u8 pad0[8];
    s16 key12;
    u8 pad1[10];
} Ent8001FDD8;
typedef struct Inner8001FDD8 {
    u8 pad0[0xdc];
    Ent8001FDD8 *tab;
} Inner8001FDD8;
typedef struct Obj8001FDD8 {
    u8 pad0[0x4c];
    Inner8001FDD8 *inner;
} Obj8001FDD8;
/* ADD: lbl_8030A6D4 entries (0x24 bytes) */
extern Slot24 lbl_8030A6D4[];
/* Object reached through extra->obj: a position at 0x1c and three s32 angles at 0x28. */
typedef struct RotObj {
    u8 pad0[0x1c];
    NJS_POINT3 pos;   /* 0x1c */
    s32 rot[3];       /* 0x28 */
} RotObj;
typedef struct RotRef {
    u8 pad0[0x24];
    RotObj *obj;      /* 0x24 */
} RotRef;
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
extern void fn_80032BBC(s8, s32);
extern void fn_80032B6C(s8, s32);
s16 fn_8001D41C(s16* cur, s16* other);

extern void fn_802A9338(s32 a, s32 b, s32 c, void (*f)(void));
extern s32 fn_80014C90(s8 id, s32 flags);

s32 fn_80015828(const char* s);
extern ChrStat lbl_80309174[12];


s32 fn_80016B20(s8 kind);
void fn_80014D0C(void);
void fn_80014CFC(void);
void fn_800152A0(void);
extern Task* fn_8003DB34(void* fn);
void fn_80016580(Tk_80016580* t);

extern void fn_8028BB90(void* p);

/* The view camera fn_800149AC hands to fn_80014808 and fn_8022B960. */
typedef struct ViewCam {
    NJS_POINT3 pos;     /* 0x00 */
    NJS_POINT3 up;      /* 0x0c */
    s16 roll;           /* 0x18 */
    u8 pad1a[6];
    NJS_POINT3 eye;     /* 0x20 */
    s32 ang[3];         /* 0x2c */
    NJS_POINT3 at;      /* 0x38 */
} ViewCam;
extern void fn_801DD460(NJS_POINT3* dst, s32* ang);
extern void fn_801DD334(NJS_POINT3* dir, NJS_POINT3* up, s32* rot);
extern s16 fn_8022BA58(NJS_POINT3* a, NJS_POINT3* b);
extern void fn_8022B960(ViewCam* c);
extern void fn_80291C44(void* m);

void fn_80014808(ViewCam* c, void* m) {
    NJS_POINT3 uv[2];
    NJS_POINT3 v;
    s32 ang[3];
    fn_80071CF0(&c->eye, &v);
    v.x = v.x + lbl_80309EC8.va[0];
    v.y = v.y + lbl_80309EC8.va[1];
    v.z = v.z + lbl_80309EC8.va[2];
    fn_80071CF0(&v, &lbl_80309EC8.x4c);
    fn_80071CF0(&c->at, &lbl_80309EC8.x58);
    ang[0] = c->ang[0];
    ang[1] = c->ang[1];
    ang[2] = c->ang[2];
    {
        s32 ax = 182.04445f * lbl_80309EC8.vb[0];
        s32 ay = 182.04445f * lbl_80309EC8.vb[1];
        ang[0] -= ax;
        ang[1] -= ay;
    }
    fn_800614FC(ang, lbl_80309EC8.x64);
    c->pos.x = v.x;
    c->pos.y = v.y;
    c->pos.z = v.z;
    fn_801DD460(&c->up, ang);
    fn_801DD334(&uv[0], &uv[1], ang);
    c->roll = fn_8022BA58(&uv[0], &uv[1]);
    c->up.x = -c->up.x;
    c->up.y = -c->up.y;
    c->up.z = -c->up.z;
    fn_8022B960(c);
    fn_80291C44(m);
    fn_80286EE8();
    fn_8028B498();
    memset(lbl_80309EC8.va, 0, 12);
    memset(lbl_80309EC8.vb, 0, 12);
}

void fn_80014AB8(u8 kind, SysObj* o) {
    if (o != NULL) {
        fn_8028BB90(o);
    }
    switch (kind) {
    case 0:
        if (lbl_80309EC8.x44 != NULL) {
            lbl_80309EC8.x44->flags |= 0x20000000;
        }
        lbl_80309EC8.x44 = o;
        break;
    case 1:
        if (lbl_80309EC8.x40 != NULL) {
            lbl_80309EC8.x40->flags |= 0x20000000;
        }
        lbl_80309EC8.x40 = o;
        memset(&lbl_80309EC8.mv, 0, sizeof(SysMove));
        break;
    case 2:
        if (lbl_80309EC8.x40 != NULL) {
            lbl_80309EC8.x40->flags |= 0x20000000;
        }
        break;
    }
}

s32 fn_80014CC0(void* obj) {
    u8* p = PTR(PTR(obj, 0x24), 0x4c);
    s16 id = *(s16*)(p + 6);
    switch (id) {
    case 0x1a:
    case 0x1b:
    case 0x1c:
        if (lbl_8034733C == 7) {
            return 1;
        }
        break;
    }
    return 0;
}

extern void fn_800350EC(NJS_TEXLIST* a, u16 dst, NJS_TEXLIST* b, u16 src);
static inline s16 FindSkin(NJS_TEXLIST* l) {
    s16 i;
    for (i = 0; i < l->nbTexture; i++) {
        char* n = l->textures[i].filename;
        if (n[0] == 't' || n[0] == 'T') {
            if (n[1] == 'k' || n[1] == 'K' || n[1] == 'x' || n[1] == 'X') {
                return i;
            }
        }
    }
    return -1;
}
void fn_80014D1C(Task* t, s16 id) {
    ChrWork* w;
    ChrInfo* u;
    NJS_TEXLIST* list;
    NJS_TEXLIST* p;
    s16 i;
    s32 ok;
    s16 val;
    s32 f;
    if (id >= 12) {
        return;
    }
    w = t->work;
    u = w->st;
    if (fn_80017A14(u) == 2) {
        return;
    }
    p = w->x48;
    if (p == 0) {
        ok = 0;
    } else if (p->textures == 0) {
        ok = 0;
    } else if (p->nbTexture <= 1) {
        ok = 0;
    } else {
        ok = 1;
    }
    if (ok == 0) {
        return;
    }
    list = w->x8;
    i = FindSkin(list);
    if (i < 0) {
        return;
    }
    if (id < 0) {
        val = u->anims[u->xe4].xe;
    } else {
        val = id;
    }
    if (lbl_80347394 == 0) {
        if (u->id < 12) {
            f = lbl_80309DE4[u->id]->bits & 0x800;
        } else {
            f = 0;
        }
        if (f != 0 && val == 0) {
            return;
        }
    }
    fn_800350EC(list, i, p, val);
    u->x294 = val;
}

s32 fn_80014EC4(ChrInfo* u)
{
    Task* t;
    ChrWork* w;

    if (u->x48 != u->id) {
        if (!fn_8006D1C4()) {
            return 0;
        }
        t = fn_800215EC(u->x48);
        if (t != NULL) {
            w = t->work;
            return w->st->x134 != 0;
        }
        return 1;
    }
    return 1;
}

void fn_80015138(u8 flag) {
    s8 start;
    s32 stop;
    s8 i;
    ChrInfo* u;
    u16 m;
    s8 end;
    u32 b;
    if (flag != 0) {
        start = 4;
        stop = 12;
    } else {
        start = 0;
        stop = 4;
    }
    i = start;
    end = stop;
    for (; i < end; i++) {
        Task* t = fn_800215EC(i);
        if (t == 0) {
            continue;
        }
        u = ChrW(t)->st;
        m = 0;
        b = lbl_80309DE4[(s8)u->id]->bits;
        u->x44 &= 0x44E80;
        u->x44 &= ~(b & 0x44E80);
        if (u->x44 & 0x80) {
            m |= 0x1;
        }
        if (u->x44 & 0x200) {
            m |= 0x20;
        }
        if (u->x44 & 0x400) {
            m |= 0x8;
        }
        if (u->x44 & 0x800) {
            m |= 0x10;
        }
        if (u->x44 & 0x4000) {
            m |= 0x4;
        }
        if (u->x44 & 0x40000) {
            m |= 0x100;
        }
        if (m != 0) {
            fn_80032BBC(u->id, 1);
            fn_80032B6C(u->id, 8);
            fn_8002923C(u->id, m, 1);
        }
    }
}

s32 fn_800153A0(Pair* p) {
    if (p == 0) {
        return 0;
    }
    if (p->a == 0) {
        return 0;
    }
    return p->b > 1;
}

void fn_8001545C(void) {
}

s32 fn_80015728(void);
void fn_80015640(Task* o);
void fn_80015580(void)
{
    s8 n = 0;
    s8 i;
    Task* t;
    ChrWork* w;
    ChrInfo* c;
    Task* p;
    if (fn_80015728() != 0) {
        for (i = 0; i < 12; i++) {
            t = lbl_80309E24[i];
            if (t != NULL) {
                w = t->work;
                c = w->st;
                if ((c->xec & 0x100000) || (c->xec & 0x8)) {
                    n++;
                }
            }
        }
        if (n != 0) {
            p = fn_802268E8(lbl_803475A8, fn_80015640);
            fn_80061F58(&p->work, 0x10, 0);
            lbl_80309EC8.x48 |= 0x10000000;
        }
    }
}

s32 fn_80015728(void) {
    s16 id;
    ChrInfo *a;
    Task *o;
    s8 i;
    if (fn_8006D1C4() == 0) {
        return 0;
    }
    if (lbl_80347378 != 0) {
        return 0;
    }
    if (lbl_8030A10C.x6c & 0x400) {
        return 0;
    }
    if (fn_8006EDA0() < 0) {
        return 0;
    }
    if (lbl_8034733C == 7) {
        return 0;
    }
    for (i = 0; i < 12; i++) {
        o = lbl_80309E24[i];
        if (o != 0) {
            ChrWork *w = o->work;
            a = w->st;
            id = a->x6;
            if (id == 0xe && a->x134 != 1) {
                return 0;
            }
            if ((a->x50 & 0x40000000) && id != 0xe) {
                return 0;
            }
        }
    }
    return 1;
}

s32 fn_80015828(const char* s) {
    if (s[0] == 'M' || s[0] == 'm') {
        if (s[1] == 'A' || s[1] == 'a') {
            if (s[3] == '1' || s[3] == '2') {
                return 1;
            }
        }
    }
    return 0;
}

extern NJS_POINT3 lbl_802DB110[];
void fn_8001E4A0(void *a, NJS_POINT3 *v, Task *c);
void fn_80015A58(NJS_POINT3 *base, s16 n, NJS_POINT3 *out, f32 ang);

s32 fn_80015880(s8 a, f32 f, NJS_POINT3* b, NJS_POINT3* c) {
    NJS_POINT3* tbl = lbl_802DB110;
    NJS_POINT3 v0;
    NJS_POINT3 v1;
    Task* t = fn_80021658(a);
    ChrWork* w = t->work;
    s8 kind = fn_80020E10(w->x10->xc);
    if (kind < 0) {
        return 0;
    }
    switch (kind) {
    case 0:
    default:
        fn_80015A58(&tbl[12], 4, &v0, f);
        fn_80015A58(&tbl[16], 4, &v1, f);
        break;
    case 1:
        fn_80015A58(&tbl[20], 5, &v0, f);
        fn_80015A58(&tbl[25], 5, &v1, f);
        break;
    case 2:
        fn_80015A58(&tbl[30], 4, &v0, f);
        fn_80015A58(&tbl[34], 4, &v1, f);
        break;
    case 3:
        fn_80015A58(&tbl[38], 4, &v0, f);
        fn_80015A58(&tbl[42], 4, &v1, f);
        break;
    case 4:
        fn_80015A58(&tbl[46], 4, &v0, f);
        fn_80015A58(&tbl[50], 4, &v1, f);
        break;
    case 5:
        fn_80015A58(&tbl[54], 4, &v0, f);
        fn_80015A58(&tbl[58], 4, &v1, f);
        break;
    }
    fn_8001E4A0(&v0, b, t);
    fn_8001E4A0(&v1, c, t);
    return 1;
}

s16 fn_80015C30(NJS_TEXLIST* t, const char* str);
extern char lbl_80348260[3];
extern char lbl_80348264[3];
static inline NJS_TEXLIST* TaskTex(Task* t)
{
    ChrWork* w = t->work;
    return w->x48;
}
NJS_TEXLIST* fn_80015B94(s8 id, s16* out)
{
    Task* t = fn_80021658(id);
    s16 r;
    if (!t) {
        t = fn_80021658(0);
    }
    if (!TaskTex(t)) {
        return 0;
    }
    r = fn_80015C30(TaskTex(t), lbl_80348260);
    if (r < 0) {
        r = fn_80015C30(TaskTex(t), lbl_80348264);
    }
    if (r >= 0) {
        *out = r;
        return TaskTex(t);
    }
    return 0;
}

extern void fn_80032BBC(s8, s32);
extern void fn_80032B6C(s8, s32);
extern void fn_80029168(s32, s32);
extern void fn_80032AF8(s8, u16);
extern s32 SePlay(s32 bank, s8 arg1, s8 id);
/* fn_80016E1C's work: a countdown and the flag word it clears at the end. */
typedef struct W16E1C {
    s16 timer;
    u8 pad2[2];
    struct { u8 pad[4]; u32 bits; }* p;
    u8 mode;
} W16E1C;
static inline s32 Flagged(s8 id) {
    if (id < 12) return lbl_80309DE4[id]->bits & 0x40000;
    return 0;
}
/* The work of the fn_80016C54/fn_80016E1C status tasks fn_800168D8 starts. */
typedef struct CbWork168 { u8 pad0[4]; void* x4; u8 x8; u8 pad9[3]; } CbWork168;
extern Task* fn_8003DB34(void* fn);
extern void fn_80016C54(Task*);
void fn_80016E1C(Task*);
int fn_800168D8(int flags, void* arg, u8 flag) {
    s8 i;
    s8 start;
    s8 end;
    if (flag) {
        start = 4;
        end = 0xc;
    } else {
        start = 0;
        end = 4;
    }
    for (i = start; i < end; i++) {
        Task* t = fn_800215EC(i);
        if (t) {
            ChrInfo* s = ChrW(t)->st;
            int m;
            if (s->id < 0xc) {
                m = flags & lbl_80309DE4[s->id]->bits;
            } else {
                m = 0;
            }
            if (m) {
                Task* n;
                CbWork168* w;
                switch (flags) {
                case 0x80:
                    n = fn_8003DB34(fn_80016C54);
                    fn_80061F58(&n->work, 0xc, 0);
                    w = n->work;
                    w->x8 = flag;
                    w->x4 = arg;
                    return 1;
                case 0x40000:
                    n = fn_8003DB34(fn_80016E1C);
                    fn_80061F58(&n->work, 0xc, 0);
                    w = n->work;
                    w->x8 = flag;
                    w->x4 = arg;
                    return 1;
                }
            }
        }
    }
    return 0;
}

int fn_80016A18(s8 mode) {
    s8 i;
    s8 start;
    s8 end;
    switch (mode) {
    case 0:
        start = 0;
        end = 4;
        break;
    case 1:
        start = 4;
        end = 0xc;
        break;
    case 2:
        start = 0;
        end = 0xc;
        break;
    default:
        return 0;
    }
    for (i = start; i < end; i++) {
        Task* t = fn_800215EC(i);
        if (t) {
            ChrInfo* s = ChrW(t)->st;
            s32 mine = s->x44 & 0x44e80;
            s32 theirs = lbl_80309DE4[s->id]->bits & 0x44e80;
            if (mine > theirs) {
                return 1;
            }
        }
    }
    return 0;
}

s32 fn_80016B20(s8 kind)
{
    s8 i;
    s8 lo;
    s8 hi;
    switch (kind) {
    case 0:
        lo = 0;
        hi = 4;
        break;
    case 1:
        lo = 4;
        hi = 12;
        break;
    case 2:
        lo = 0;
        hi = 12;
        break;
    default:
        return 0;
    }
    for (i = lo; i < hi; i++) {
        Task* t = fn_800215EC(i);
        if (t != 0) {
            s8 id = ChrW(t)->st->id;
            if ((id < 12 ? lbl_80309DE4[id]->bits & 0x80 : 0) != 0) return 1;
            if ((id < 12 ? lbl_80309DE4[id]->bits & 0x40000 : 0) != 0) return 1;
        }
    }
    return 0;
}
s16 fn_800085EC(Task* a, s16 b, s16 c, Ent_80008800* d, CondLink* p);

void fn_80016E1C(Task* t) {
    s8 lo;
    s8 i;
    Task* c;
    ChrInfo* u;
    W16E1C* w;
    s8 hi;
    s16 v;
    s8 n;
    s16 k;
    w = t->work;
    if (w->mode != 0) {
        lo = 4;
        hi = 12;
    } else {
        lo = 0;
        hi = 4;
    }
    switch (t->state) {
    case 0:
        t->state = 1;
        break;
    case 1:
        for (i = lo; i < hi; i++) {
            c = fn_800215EC(i);
            if (c != 0) {
                u = ChrW(c)->st;
                if (Flagged(u->id)) {
                    fn_80032BBC(u->id, 1);
                    fn_80032B6C(u->id, 8);
                    n = u->id;
                    v = 0;
                    if (fn_80078610(n)) v = lbl_80309DE4[n]->x0;
                    k = v;
                    if (k < 0) k = 0;
                    fn_80029168(u->id, k);
                    fn_80032AF8(u->id, 0x100);
                    fn_800085EC(c, 0x1f, -1, lbl_8030A10C.x10, lbl_8030A10C.x184);
                }
            }
        }
        SePlay(3, 1, 20);
        w->timer = 90;
        t->state = 2;
        break;
    case 2:
        if (w->timer != 0) {
            w->timer--;
        } else {
            t->state = 3;
        }
        break;
    case 3:
        w->p->bits &= 0x7FFFFFFF;
        fn_80032B4C();
        t->flags |= 0x40;
        lbl_8030A10C.x1c4--;
        break;
    }
}

s32 fn_8001712C(s8 id, f32* out)
{
    Task* t;
    ChrWork* w;
    ChrInfo* st;
    s16 k;
    s16 v;
    t = fn_80021658(id);
    if (t == NULL) {
        return 0;
    }
    w = t->work;
    st = w->st;
    k = fn_80020094(t->work, 0, -1, 1);
    if (k < 0) {
        return 0;
    }
    v = st->anims[k].xe;
    if (v == 0) {
        return 0;
    }
    *out = v * 15.0f * 0.25f;
    return 1;
}

void fn_80017320(void) {
}

extern int fn_800214FC(s8, s16, s8);
static inline s8 PartyChrId(s8 s)
{
    s8 i;
    for (i = 0; i < 12; i++) {
        if (lbl_80309E24[i] != NULL) {
            ChrWork* w = lbl_80309E24[i]->work;
            if (s == fn_80020E10(w->x10->xc)) {
                return w->st->id;
            }
        }
    }
    return -1;
}
static inline int ChrBits(s8 i, u32 mask)
{
    if (i < 12) {
        return lbl_80309DE4[i]->bits & mask;
    }
    return 0;
}
static inline int PartyCanAct(void)
{
    s8 s;
    s8 idx;
    for (s = 0; s < 6; s++) {
        idx = PartyChrId(s);
        if (idx >= 0 && ChrBits(idx, 0xcd80) != 0) {
            return 0;
        }
    }
    return 1;
}
static inline s8 FindBySlot(s8 slot)
{
    Task **pp = lbl_80309E24;
    s8 j;
    for (j = 0; j < 12; pp++, j++) {
        if (*pp != 0) {
            ChrWork *w = (*pp)->work;
            if (slot == fn_80020E10(w->x10->xc)) {
                return w->st->id;
            }
        }
    }
    return -1;
}
s8 fn_80017324(u16 mode_) {
    s32 mode = mode_;
    s8 slot;
    s8 result;
    s8 found;
    result = -1;
    slot = 0;
    while (result < 0) {
        found = FindBySlot(slot);
        if (found >= 0) {
            if (rand() % 4 == 0) {
                if (mode != 1) {
                    result = found;
                } else if ((ChrW(fn_80021658(found))->st->xec & 0x100) == 0) {
                    result = found;
                }
            }
        }
        slot++;
        if (slot == 6) {
            slot = 0;
        }
    }
    return result;
}

void fn_80017430(s8 sel)
{
    ChrInfo* u;
    f32 ratio;
    s8 c;
    s8 idx;
    s8 s;
    int f;
    s16 hp;
    s16 max;

    f = PartyCanAct();
    for (s = 0; s < 6; s++) {
        idx = PartyChrId(s);
        if (idx >= 0) {
            Task* t = fn_80021658(idx);
            ChrWork* w = t->work;
            u = w->st;
            u->target = u->id;
            if (idx != sel) {
                u->xf0 |= 0x8000;
            } else {
                u->xf0 |= 0x20;
            }
            if (u->xec & 0x100) {
                fn_800214FC(idx, 0xf, idx);
            } else {
                if (f != 0) {
                    hp = lbl_80309DE4[idx]->x14;
                    max = lbl_80309DE4[idx]->x18;
                    ratio = (f32)hp / max;
                    if (ratio >= 0.75f) {
                        c = 1;
                    } else {
                        c = 0;
                    }
                } else if (ChrBits(idx, 0x8000) != 0) {
                    c = 2;
                } else {
                    c = 0;
                }
                fn_800214FC(idx, c + 0x1a, idx);
            }
        }
    }
}

void fn_80017778(void) {
    s8 i;
    for (i = 0; i < 14; i++) {
        Task* t = lbl_80309E24[i];
        if (t != 0) {
            ChrWork* w = t->work;
            w->st->xf0 &= ~0x00400000;
        }
    }
}

extern Task* fn_800215EC(s8);
extern void fn_800749DC(s16 i, Joint* nodes, f32* out);
extern s32 fn_802300F0(void* out, Joint* node, s32 j);
f32 fn_800177C0(s32 idx, f32* out) {
    s8 id = idx;
    Task* t;
    Task* t2;
    f32 h = 0.0f;
    f32 tmp;
    f32 ch;
    f32 buf[2];
    ChrInfo* u;
    ChrInfo* u2;
    Joint* n;
    s16 i;
    s16 k;
    s32 j;
    s32 ok;
    t = fn_80021658(id);
    ch = ChrW(t)->x10->x40;
    if (ch) {
        h = ch;
    } else {
        t2 = fn_80021658(id);
        if (t2 == 0) {
            ok = 0;
        } else {
            u = ChrW(t2)->st;
            k = fn_80020094(ChrW(t2), 0, -1, 1);
            if (k < 0) {
                ok = 0;
            } else if (u->anims[k].xe == 0) {
                ok = 0;
            } else {
                h = 0.25f * (15.0f * u->anims[k].xe);
                ok = 1;
            }
        }
        if (!ok) {
            if (t == 0) {
                out[0] = 0.0f;
                out[1] = 0.0f;
                out[2] = 0.0f;
                return 0.0f;
            }
            u2 = ChrW(t)->st;
            for (i = 0; i < ChrW(t)->x14; i++) {
                n = &u2->x154[i];
                j = 0;
                tmp = 0.0f;
                fn_800749DC(i, u2->x154, &tmp);
                for (; fn_802300F0(buf, n, j) != 0; j++) {
                    if (tmp + buf[1] > h) h = tmp + buf[1];
                }
                if (tmp > h) h = tmp;
            }
        }
        ChrW(t)->x10->x40 = h;
    }
    fn_80071CF0(&ChrW(t)->pos, out);
    out[1] = h;
    return h;
}

int fn_800179B4(int a) {
    return fn_800215EC((s8)a) != 0;
}

s32 fn_800179E4(s16 a) {

    return fn_800215EC((s8)a) != 0;
}

extern s32 lbl_80346AB8;
int fn_80018B80(ChrDraw* a);
extern void fn_80036584(void*, int);
extern int fn_8007E264(f32* out, f32 x, f32 z);

void fn_80017CB8(Task* t, s16 idx)
{
    ChrWork* w = t->work;
    ChrInfo* u = w->st;
    f32 f = 0.0f;
    f32 ground;
    DrawState s;

    fn_80299040(w->x8);
    u->xea = idx;
    f = u->draw.a;
    njPushMatrixEx();
    fn_80286EE8();
    fn_8028B498();
    if (fn_80018B80(&u->draw)) {
        njTranslate(0, w->pos.x, w->pos.y, w->pos.z);
        njRotateXYZ(0, w->rx, w->ry, w->rz);
        njScale(0, w->scl.x, w->scl.y, w->scl.z);
        lbl_80346AB8 = fn_80035908();
        switch (w->x14) {
        case 0x4d:
            fn_80035910(0x8000);
            break;
        case 0x2f:
        case 0x76:
            fn_80035910(0x20000000);
            break;
        }
        if (u->x5c != NULL) {
            if (u->x60 != NULL) {
                if (f > -1.0f) {
                    fn_800353F4(u->x154, u->x5c, u->x60, u->x68, w->x44);
                }
            } else {
                if ((u->anims[idx].flags & 0x200000) || (u->anims[u->xe8].flags & 0x200000)) {
                    if (f > -1.0f) {
                        fn_8003529C(u->x154, u->x5c, u->x68, w->x44);
                    }
                } else {
                    if (f > -1.0f) {
                        fn_80035380(u->x154, u->x5c, u->x68, w->x44);
                    }
                }
                if (u->xec & 0x2000000) {
                    fn_80036584(t, -1);
                    DrawStateDefault2D(&s);
                    fn_8007E678(u->x154, &s);
                    s.colour.a = -0.8f;
                    if (DrawStatePush(&s)) {
                        fn_80035380(u->x154, u->x5c, u->x68, w->x44);
                        DrawStatePop(&s);
                    }
                }
            }
            if (!(u->xec & 0x20000000) || (u->xec & 0x10000000)) {
                u->x68 += u->anims[idx].x14;
            }
            if ((u->xec & 0x20000000) && (u->xec & 0x8000000)) {
                if (u->x68 >= u->anims[idx].x14) {
                    u->x68 -= u->anims[idx].x14;
                }
            }
            if (u->x68 > (f32)u->x5c->x4 - 1.0f) {
                if (u->anims[idx].flags & 0x8000000) {
                    u->x68 = (f32)u->x5c->x4 - 1.0f;
                } else {
                    u->x68 = 0.0f;
                }
                u->x70 = 1;
            }
            if (u->anims[idx].flags & 0x800000) {
                u->x70 = 1;
            }
        } else {
            fn_80035140(u->x154, w->x44);
            u->x70 = 1;
        }
        fn_8007E264(&ground, w->pos.x, w->pos.z);
        if (u->xec & 0x200) {
            if (ground > w->pos.y) {
                w->pos.y = ground;
            }
        } else {
            w->pos.y = ground;
        }
        switch (w->x14) {
        case 0x4d:
        case 0x2f:
        case 0x76:
            fn_80035910(lbl_80346AB8);
            break;
        }
        DrawStatePop(0);
        fn_800D2048();
    }
    njPopMatrixEx();
    if (u->x70 != 0 && (u->xec & 1)) {
        u->xec &= ~1;
        fn_80075F2C(t);
    }
}

extern void fn_80060950(void*);

int fn_8001FABC(Task* t);

void fn_80018084(Task* t)
{
    Work_80019D7C* w = t->work;
    Inner_80019D7C* u = w->in;
    switch (u->x12) {
    case 0: {
        Task* o;
        fn_8001FABC(t);
        o = fn_802268E8(lbl_803475A8, fn_80019B70);
        fn_80061F58(&o->work, 0x18, 0);
        SeqW(o)->owner = t;
        SeqW(o)->b = t;
        SeqW(o)->kind[0] = 30;
        SeqW(o)->val[0] = 2;
        SeqW(o)->kind[1] = 30;
        SeqW(o)->val[1] = 3;
        SeqW(o)->kind[2] = 30;
        SeqW(o)->val[2] = 4;
        u->x12 = 1;
        break;
    }
    case 1:
    default:
        break;
    }
    fn_80018CBC(t, u->xe8, 0, 0, u->x2);
}

s32 fn_80020060(ChrAnim* p);
s32 fn_80017018(s8 idx);
s32 fn_8001712C(s8 id, f32* out);

extern s32 fn_80060B98(void*, void*, void*, f32*);

s32 fn_80018178(void* a, void* b, void* c, s8* list) {
    s32 cnt;
    s8 i;
    s8 v;
    s8 j;
    s8 k;
    f32 pos[3];
    cnt = 0;
    for (i = 0; i < 14; i++) {
        list[i] = -1;
    }
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            v = lbl_8030A10C.x14[j][i];
            if (v >= 0) {
                pos[0] = 15.0f * j + 7.5f - 67.5f;
                pos[2] = 15.0f * i + 7.5f - 67.5f;
                pos[1] = 0.0f;
                if (fn_80060B98(a, b, c, pos) != 0) {
                    for (k = 0; k < 14; k++) {
                        if (list[k] < 0) {
                            list[k] = v;
                            cnt++;
                            break;
                        }
                        if (v == list[k]) break;
                    }
                }
            }
        }
    }
    return cnt;
}

void fn_80018700(s8 id) {
    s16 i;
    s16 j;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            s8 v = lbl_8030A10C.x14[i][j];
            if (v == id) {
                lbl_8030A10C.x14[i][j] = -1;
            }
        }
    }
}

void fn_80018798(Task *t)
{
    ChrWork *w = t->work;
    ChrInfo *d = w->st;
    ChrAnim *tbl = d->anims;
    s16 idx;
    s16 idx2;
    f32 f;
    idx = fn_80020060(tbl);
    d->x128 = tbl[idx].x14;
    d->x12c = lbl_8030A10C.xec * tbl[idx].x10;
    idx2 = fn_80020094(w, 1, -1, 1);
    f = tbl[idx2].x10;
    if (f) {
        d->x130 = lbl_8030A10C.xec * f;
    } else {
        d->x130 = d->x12c;
    }
    fn_8001712C(d->id, &d->x15c);
    fn_80017018(d->id);
}

void fn_80018AFC(void* t, ChrInfo* u, ChrWork* w)
{
    DrawState s;

    fn_80036584(t, -1);
    DrawStateDefault2D(&s);
    fn_8007E678(u->x154, &s);
    s.colour.a = -0.8f;
    if (DrawStatePush(&s)) {
        fn_80035380(u->x154, u->x5c, u->x68, w->x44);
        DrawStatePop(&s);
    }
}

int fn_80018B80(ChrDraw* a) {
    DrawState s;
    DrawStateGet(&s);
    s.control3d |= 0x800;
    s.colour.a = a->a;
    s.colour.r = a->r;
    s.colour.g = a->g;
    s.colour.b = a->b;
    if (lbl_80347394 != 0) {
        s.attr_and &= ~0x700;
    } else {
        s.attr_and &= ~0x700;
    }
    if (a->a < 0.0f) {
        s.attr_or |= 0x800;
    } else {
        s.attr_and &= ~0x500;
    }
    if (a->x28 != 1) {
        s.control3d &= ~0x40;
    }
    s.blend_src = a->blend_src;
    s.blend_dst = a->blend_dst;
    s.fog = a->fog;
    if (!DrawStatePush(&s)) {
        return 0;
    }
    if (a->x30 != 0) {
        fn_80060950(a);
    }
    return 1;
}

void fn_80018868(Task* t, s8 mode, f32 frame);
extern void fn_801D142C(u8 v);
extern void fn_801D1420(void);
extern void fn_80075D24(Task* t);
extern void fn_800184F0(Task* t);
void fn_80018CBC(Task* t, s16 idx, s16 mode, ChrWork* alt, s16 kind)
{
    ChrWork* w;
    ChrInfo* u;
    void* model;
    u8 rm;
    s8 dm;
    int saved;
    int flag;
    int simple;
    f32 f;
    f32 ground;
    DrawState s;
    DrawState s2;

    dm = -1;
    saved = fn_80035908();
    fn_80035910(saved & ~0x4000);
    flag = 0;
    switch (kind) {
    case 0x23:
    case 0x26:
    case 0x51:
    case 0x89:
    case 0x8a:
    case 0x8b:
        flag = 1;
        fn_801D142C(0xd0);
        break;
    }
    if (flag) {
        fn_80035910(0x10008000);
    }
    switch (kind) {
    case 0x9d:
        fn_80035910(0);
        break;
    case 0xa2:
    case 0xa7:
    case 0xac:
    case 0xb1:
        fn_80035910(0x8000);
        break;
    }
    w = t->work;
    u = w->st;
    switch (mode) {
    case 0:
        if (u->x1f4 != NULL && (u->xec & 0x400)) {
            fn_80299040(u->x1f4);
        } else {
            fn_80299040(w->x8);
        }
        model = u->x154;
        rm = w->x44;
        break;
    case 1:
        fn_80299040(alt->x8);
        model = alt->x0;
        rm = alt->x44;
        break;
    }
    u->xea = idx;
    f = u->draw.a;
    if (lbl_8034733C != 0 && f < -0.1f) {
        rm = 4;
    }
    simple = 0;
    flag = 0;
    switch (kind) {
    case 0x1d:
    case 0x1e:
    case 0x29:
    case 0x3a:
    case 0x59:
    case 0x6d:
    case 0x79:
    case 0xff:
        flag = 1;
        break;
    }
    if (flag) {
        simple = 1;
    }
    njPushMatrixEx();
    fn_80286EE8();
    fn_8028B498();
    if (fn_80018B80(&u->draw)) {
        if (u->x1fc != NULL) {
            njMultiMatrix(0, u->x1fc);
        } else {
            njTranslate(0, w->pos.x, w->pos.y, w->pos.z);
            njRotateXYZ(0, w->rx, w->ry, w->rz);
        }
        njScale(0, w->scl.x, w->scl.y, w->scl.z);
        if (u->xec & 0x80000000) {
            if (u->x60 != NULL) {
                if (f > -1.0f) {
                    if (!(u->x50 & 0x02000000)) {
                        fn_80035468(model, u->x74, u->x84, u->x68, rm);
                    }
                    dm = 0;
                }
            } else {
                if (f > -1.0f) {
                    if (!(u->x50 & 0x02000000)) {
                        fn_80035228(model, u->x74, u->x68, rm);
                    }
                    dm = 1;
                }
            }
            u->x68 = u->x68 + u->x6c;
            if (u->x68 > 1.0f) {
                u->x68 = 1.0f;
            }
        } else if (u->x5c != NULL) {
            fn_80075D24(t);
            if (u->x60 != NULL) {
                if (f > -1.0f) {
                    if (!(u->x50 & 0x02000000)) {
                        fn_800353F4(model, u->x5c, u->x60, u->x68, rm);
                    }
                    dm = 2;
                }
            } else {
                if (((u->anims[idx].flags & 0x200000) || (u->anims[u->xe8].flags & 0x200000)) && !simple) {
                    if (f > -1.0f) {
                        if (!(u->x50 & 0x02000000)) {
                            fn_8003529C(model, u->x5c, u->x68, rm);
                        }
                        dm = 4;
                    }
                } else {
                    if (f > -1.0f) {
                        if (!(u->x50 & 0x02000000)) {
                            fn_80035380(model, u->x5c, u->x68, rm);
                        }
                        dm = 3;
                    }
                }
                if (u->xec & 0x2000000) {
                    fn_80036584(t, -1);
                    DrawStateDefault2D(&s);
                    fn_8007E678(u->x154, &s);
                    s.colour.a = -0.8f;
                    if (DrawStatePush(&s)) {
                        fn_80035380(u->x154, u->x5c, u->x68, w->x44);
                        DrawStatePop(&s);
                    }
                }
            }
            if (u->xf0 & 0x1000) {
                DrawStateDefault2D(&s2);
                fn_8007E678(u->x154, &s2);
                s2.colour.a = u->x160;
                fn_80299040(u->x1f4);
                if (DrawStatePush(&s2)) {
                    njScale(0, 1.0f, 1.0f, 1.0f);
                    if (u->x60 != NULL) {
                        fn_800353F4(u->x154, u->x5c, u->x60, u->x68, w->x44);
                    } else {
                        fn_80035380(u->x154, u->x5c, u->x68, w->x44);
                    }
                    DrawStatePop(&s2);
                }
            }
            if (!((u->xec & 0x20000000) || (u->xf0 & 0x800)) || (u->xec & 0x10000000)) {
                if (!(u->xf0 & 0x2000)) {
                    u->x68 += u->anims[idx].x14;
                }
            }
            if ((u->xec & 0x20000000) && (u->xec & 0x8000000)) {
                if (u->x68 >= u->anims[idx].x14) {
                    u->x68 -= u->anims[idx].x14;
                }
            }
            if (u->x68 > u->x5c->x4 - 1.0f) {
                if (u->anims[idx].flags & 0x8000000) {
                    u->x68 = u->x5c->x4 - 1.0f;
                } else {
                    u->x68 = 0.0f;
                }
                u->x70 = 1;
            }
            if ((u->anims[idx].flags & 0x800000) || (u->xf0 & 0x800)) {
                u->x70 = 1;
            }
        } else {
            fn_80035140(model, rm);
            u->x70 = 1;
        }
        if (u->x50 & 0x04000000) {
            fn_80018868(t, dm, u->x68);
        }
        u->x296 = dm;
        fn_8007E264(&ground, w->pos.x, w->pos.z);
        if (u->xec & 0x200) {
            if (ground > w->pos.y) {
                w->pos.y = ground;
            }
        } else {
            w->pos.y = ground;
        }
        DrawStatePop(0);
        fn_800D2048();
    }
    njPopMatrixEx();
    if (u->x70 != 0 && (u->xec & 1)) {
        u->xec &= ~1;
        fn_80075F2C(t);
    }
    if (!(u->xf0 & 0x40000000)) {
        fn_800184F0(t);
        fn_80071CF0(&w->pos, &u->x13c);
        fn_800614FC(&w->rx, u->x148);
    }
    fn_80035910(saved);
    fn_801D1420();
}

extern s8 VoiceRequest(Task* t, s16 act, s16 sub, s16 act2, s16 sub2);
extern s8 VoicePoll(Task* t);
s32 fn_80014F50(Task* o);
extern void fn_80032BBC(s8, s32);
extern void fn_80031580(s32 a, s8 b, s16 c, s32 d);
extern s16 fn_8006D2C4(s32 a);
void fn_8001DCA0(ChrInfo* o);
extern void fn_800324B8(u8, int);
static inline void ClearId(s8 id)
{
    s16 i;
    s16 j;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            if (lbl_8030A10C.x14[i][j] == id) {
                lbl_8030A10C.x14[i][j] = -1;
            }
        }
    }
}

void fn_800193B8(Task* t)
{
    ChrWork* w = t->work;
    ChrInfo* u = w->st;
    Obj_80017B18* p = w->x10;
    Ent_80008800* v = p->x30;

    switch (u->state) {
    case 0:
        if (fn_80020E10(p->xc) >= 0) {
            lbl_8030A10C.x6c |= 0x400;
        }
        if (VoiceRequest(t, u->x20c, u->x20e, u->x210, u->x212) != -1) {
            u->state = 1;
        } else {
            u->state = 2;
        }
        break;
    case 1:
        if (VoicePoll(t) == 0) {
            break;
        }
        u->state = 2;
    case 2:
        u->state = 3;
        break;
    case 3:
        if (u->xf0 & 0x2000000) {
            break;
        }
        if (fn_80014F50(t)) {
            u->state = 4;
        } else {
            fn_80075F2C(t);
            u->x1f8 = 60;
            u->state = 12;
        }
        if (fn_80020E10(w->x10->xc) >= 0) {
            fn_800085EC(t, 0x14, -1, v, u->x298);
        }
        break;
    case 4:
        lbl_80347378 |= 1 << u->id;
        u->xec |= 0x100;
        fn_80075F2C(t);
        if (fn_80020E10(w->x10->xc) < 0) {
            fn_800085EC(t, 0x14, -1, lbl_8030A10C.xc, lbl_8030A10C.x180);
            fn_80032BBC(u->id, 1);
            fn_80031580(u->id, 3, 0x1e, 1);
        }
        ClearId(u->id);
        u->state = 5;
        break;
    case 5:
        if (u->xec & 0x40000) {
            break;
        }
        if (fn_8006D2C4(1) == 0) {
            u->state = 6;
        }
        break;
    case 6:
        fn_80032BBC(u->id, 0);
        if (u->x1dc != NULL) {
            lbl_80347378 &= ~(1 << u->id);
            fn_8001DCA0(u);
        }
        u->x134 = 1;
        u->state = 9;
        break;
    case 9:
        if (fn_80020E10(p->xc) < 0 && lbl_80347394 == NULL) {
            u->state = 11;
            u->x1f8 = 3;
        } else {
            u->state = 12;
        }
        break;
    case 11:
        if (u->x1f8 == 0) {
            u->xec |= 0x400000;
        } else {
            u->x1f8--;
        }
        return;
    case 12:
        if (u->x1f8 == 0x1e) {
            fn_800324B8(u->id, 0);
        }
        if (u->x1f8 == 0) {
            u->x134 = 1;
            fn_8001DCA0(u);
            if (fn_80020E10(w->x10->xc) >= 0) {
                lbl_8030A10C.x6c &= ~0x400;
            }
        } else {
            u->x1f8--;
        }
        break;
    }
    if (u->x138 != 0) {
        u->x138--;
    }
    fn_80018CBC(t, u->xe4, 0, 0, u->x2);
}

void fn_80019B70(Task* t) {
    SeqWork* w = t->work;
    ChrInfo* u = ChrW(w->owner)->st;
    if (w->kind[0] == 0) t->state = 4;
    switch (t->state) {
    case 0:
        u->xec |= 0x40010000;
        u->x134 = 1;
        u->x18 = w->kind[w->idx];
        u->x1a = w->val[w->idx];
        w->idx = 1;
        t->state = 1;
        break;
    case 1:
        u->xec |= 0x40000000;
        if (u->x6 == u->x18) t->state = 2;
        break;
    case 2: {
        s16 k;
        u->xec |= 0x40000000;
        k = w->kind[w->idx];
        if (k == 0) {
            t->state = 4;
            return;
        }
        if (u->x134 == 0) return;
        u->x18 = k;
        u->x1a = w->val[w->idx];
        w->idx++;
        if (w->idx < 3 && w->kind[w->idx] != 0) return;
        t->state = 3;
        break;
    }
    case 3:
        if (w->kind[1] == 5 || w->kind[1] == 4) {
            if (w->kind[0] == 0xB) u->xf0 |= 4;
        }
        u->xec &= ~0x40010000;
        t->state = 4;
        break;
    case 4:
        if (u->x134 == 0) return;
        if (lbl_80347394 == 0) {
            if (lbl_8034733C != 5) return;
            u->xf0 &= ~4;
            t->flags |= 0x40;
        } else {
            u->xf0 &= ~4;
            t->flags |= 0x40;
        }
        break;
    }
}

void fn_80019E44(Task* t) {
    Work_80019D7C* w = t->work;
    Inner_80019D7C* in = w->in;
    switch (in->x12) {
    case 0: {
        Task* o = fn_802268E8(lbl_803475A8, fn_80019B70);
        fn_80061F58(&o->work, 0x18, 0);
        SeqW(o)->owner = t;
        SeqW(o)->b = t;
        SeqW(o)->kind[0] = 11;
        SeqW(o)->kind[1] = 4;
        in->x12 = 1;
        break;
    }
    case 1:
        break;
    }
    fn_80018CBC(t, in->xe8, 0, 0, in->x2);
}

s32 fn_8001BBF8(void* obj) {
    u8* p = PTR(PTR(obj, 0x24), 0x4c);
    s16 id = *(s16*)(p + 0x10);
    switch (id) {
    case 0x10:
    case 0x17:
    case 0x1d:
        return 0;
    default:
        return 1;
    }
}


s32 fn_8001C1F0(Task* o)
{
    ChrWork* cw = o->work;
    ChrInfo* w = cw->st;
    switch (w->x6) {
    default:
        if ((w->xf0 & 4) && fn_80014C90(w->id, 4) != 0 && fn_80014C90(w->id, 0x800000) != 0) {
            return 1;
        }
        return 0;
    case 9:
    case 10:
        if (fn_80014C90(w->id, 4) != 0 && fn_80014C90(w->id, 0x800000) != 0) {
            return 1;
        }
        return 0;
    case 11:
    case 32:
        if (fn_80014C90(w->id, 4) != 0 && fn_80014C90(w->id, 0x800000) != 0) {
            switch (w->x4a) {
            case 4:
            case 5:
            case 8:
                return 1;
            default:
                return 0;
            }
        }
        return 0;
    }
}

extern s32 fn_80008AB4(Ent_80008800* tbl, s32 a, s32 b, s32 c, s32 d, s32 e, CondLink* list);
s16 fn_80008530(Task* a, s16 b, s16 c, Ent_80008800* d, CondLink* p);
static inline Task* FindChr(s8 key) {
    s8 i;
    for (i = 0; i < 14; i++) {
        Task* p = lbl_80309E24[i];
        if (p != 0) {
            ChrWork* w = p->work;
            if (w->st->id == key) return lbl_80309E24[i];
        }
    }
    return 0;
}
static inline s32 KeyFind(Key* p) {
    s32 i = 0;
    for (;;) {
        if (p->x2 == 3) break;
        if (p->x2 == 0) return i;
        p++;
        i++;
    }
    return -1;
}

void fn_8001C410(Task* t) {
    ChrWork* w = t->work;
    Key* base = w->x10->x30->xc;
    s16 i = KeyFind(base);
    if (!(base[i].x8 & 0x40000)) {
        return;
    }
    w->x44 = 4;
}

void fn_8001C474(Task* t) {
    ChrInfo* u = ChrW(t)->st;
    s32 flag = 0;
    Ent_80008800* h;
    GS* g;
    if (fn_80014C90(u->id, 0x10) != 0) {
        h = ChrW(t)->x10->x30;
        if (fn_80008AB4(h, 0x1e, 0x26, -1, -1, 0, u->x298) != 0) {
            fn_800086BC(t, 0x1e, 0x26, h, 0, 1);
        } else {
            fn_800086BC(t, 0x1e, 0x26, lbl_8030A10C.x10, 0, 1);
        }
        if (FindChr(u->x48) != 0) {
            switch (u->x4a) {
            case 4:
            case 5:
            case 9:
            case 10:
                flag = 1;
            }
        }
    }
    if ((u->xec & 0x2000) || flag != 0) {
        u->xec &= ~0x2000;
    } else if (!(u->xf0 & 0x4000000) && u->x204 != 0 && (u->xf4 & 0x4000000)) {
        fn_800086BC(t, 0x1e, 0x26, lbl_8030A10C.x10, 0, 1);
    } else {
        g = &lbl_8030A10C;
        u->xec |= 0x800;
        if (fn_80008530(t, u->x4a, u->x4c, g->xc, g->x180) == 0) {
            u->xec |= 0x1000;
            fn_80008530(t, 0x20, u->x4c, g->xc, g->x180);
            u->xec &= ~0x1000;
        }
        u->xec &= ~0x800;
    }
}

static inline Task* FindChr3(s8 key) {
    s8 i;
    for (i = 0; i < 14; i++) {
        Task* p = lbl_80309E24[i];
        if (p != 0) {
            ChrWork* w = p->work;
            if (w->st->id == key) return lbl_80309E24[i];
        }
    }
    return 0;
}
static inline Task* FindChrOr0(s8 key) {
    Task* r = FindChr3(key);
    if (r != 0) return r;
    return FindChr3(0);
}
s16 fn_8001D41C(s16* a, s16* b) {
    Task* t;
    s16 tb;
    ChrInfo* u;
    SysObj* s;
    if (lbl_80347394 != 0) {
        s = lbl_80347394->work;
        u = ChrW(s->owner)->st;
        *a = u->id;
        *b = u->target;
    } else {
    if (lbl_8034733C <= 0) {
        *a = 0;
        *b = 0;
        return -1;
    }
    *a = lbl_80347334;
    *b = lbl_80309730[*a].x4;
    if (*b < 0 || *b >= 12) *b = *a;
    tb = *b;
    t = FindChrOr0(tb);
    if (ChrW(t)->st->xf0 & 4) {
        *b = *a;
        *a = tb;
        return 1;
    }
    }
    return 0;
}

void fn_8001DD00(ChrInfo* o, s8 v) {
    s8 i;
    s8 j;
    s8 val;
    switch (o->x6) {
    case 0x20:
    case 0xb:
        if (v <= 3) {
            val = 0x12;
        }
        break;
    default:
        val = v;
        break;
    }
    for (i = 0; i < 10; i++) {
        if (o->x28[i] < 0) {
            o->x28[i] = val;
            break;
        }
    }
    if (i == 10) {
        for (j = 0; j < 9; j++) {
            o->x28[j] = o->x28[j + 1];
        }
        o->x28[j] = val;
    }
}

static inline Task *FindChrId(s8 id) {
    s8 i;
    for (i = 0; i < 14; i++) {
        Task *t = lbl_80309E24[i];
        if (t != 0) {
            ChrWork *w = t->work;
            if (w->st->id == id) {
                return lbl_80309E24[i];
            }
        }
    }
    return 0;
}

void fn_8001E5C8(Angle *v, s8 id) {
    Task *t = FindChrId(id);
    ChrWork *w;
    t = t != NULL ? t : FindChrId(0);
    if (t == NULL) {
        v[0] = 0;
        v[1] = 0;
        v[2] = 0;
    }
    w = t->work;
    fn_800614FC(&w->rx, v);
}

void fn_8001E6DC(NJS_POINT3 *out, s8 id) {
    Task *t = FindChrId(id);
    t = t ? t : FindChrId(0);
    if (t == 0) {
        out->x = 0.0f;
        out->y = 0.0f;
        out->z = 0.0f;
    } else {
        ChrWork *w = t->work;
        fn_80071CF0(&w->st->x13c, out);
    }
}

/* The character task with this id, or else the one with id 0. */
static inline Task* FindChrIdOr0(s8 idx)
{
    Task* t = FindChrId(idx);
    if (t != NULL) {
        return t;
    }
    return FindChrId(0);
}

void fn_8001E7F8(f32* out, s8 idx)
{
    Task* t = FindChrIdOr0(idx);
    if (t == NULL) {
        out[0] = 0.0f;
        out[1] = 0.0f;
        out[2] = 0.0f;
    } else {
        ChrWork* w = t->work;
        fn_80071CF0(&w->pos, out);
    }
}

s32 fn_8001EB6C(void* obj) {
    s16 type = *(s16*)((u8*)obj + 6);
    switch (type) {
    case 4:
    case 5:
    case 8:
    case 15:
    case 24:
        return 1;
    default:
        return 0;
    }
}

void fn_80014CFC(void)
{
    lbl_80347378 &= ~0xf;
}

void fn_80014D0C(void)
{
    lbl_80347378 |= 0xf;
}

s32 fn_8001552C(u8 *p)
{
    u32 v = *(u32 *)(p + 0xec);
    if (v & 0x20) return 1;
    else return (v & 0x40) ? 2 : 0;
}

void fn_80015554(void)
{
    if (!(lbl_803472F4 & 0x8000)) fn_80015580();
}

void fn_8001C31C(Tk_8001C31C* t) {
    Unit* u = t->work->w;
    u->xec &= ~0x60;
    u->xf0 &= ~0x04000000;
    u->xf4 = 0;
}

void fn_8001C7B8(void* a, void* b, void* c) {
    NJS_POINT3 v;
    fn_8001C6CC(a, b, c, &v);
    fn_8006C860("/BEFF/", &v);
}

void fn_8001D1D8(Tk_8001D1D8* t, void *v) {
    fn_80071CF0((u8*)t->work + 0x1C, v);
}

void fn_8001F814(s8 a, s8 b) {
    Task* t1 = FindChrOr0(a);
    Task* t2;
    Angle ang;
    if (fn_80017A14(ChrW(t1)->st) == 0) {
        t2 = FindChrOr0(b);
        ang = fn_80071C74(ChrW(t1), ChrW(t2)->pos.x, ChrW(t2)->pos.z);
        ChrW(t1)->ry = ang;
    }
}

s32 fn_80020060(ChrAnim* p) {
    s32 i = 0;
    for (;;) {
        if (p->x2 == 3) break;
        if (p->x2 == 0) return i;
        p++;
        i++;
    }
    return -1;
}

void fn_80018764(Tk* t, f32* a, f32* b) {
    s16 i;
    if (t == NULL) {
        return;
    }
    i = t->work->id;
    *a = lbl_803097F0.ent[i].x4;
    *b = lbl_803097F0.ent[i].x8;
}

s32 fn_80018498(f32 *v)
{
    if (v[0] > 67.5f) return 0;
    if (v[0] < -67.5f) return 0;
    if (v[2] > 67.5f) return 0;
    return !(v[2] < -67.5f);
}

s32 fn_80014F50(Task *o)
{
    switch (lbl_80309730[ChrW(o)->st->id].mode) {
    case 0:
        return 0;
    default:
        return 1;
    }
}

void fn_80016580(Tk_80016580* t)
{
    W_80016580* w = t->work.v;
    s8 k;

    lbl_80347378 |= 1;
    lbl_80347378 |= 2;
    lbl_80347378 |= 4;
    lbl_80347378 |= 8;
    switch (t->state) {
    case 0:
        t->state = 0x14;
        break;
    case 20:
        if (fn_80016A18(0)) {
            fn_80015138(0);
            w->x0 = 0x78;
        } else {
            w->x0 = 0;
        }
        t->state = 0x15;
        break;
    case 21:
        if (w->x0 == 0) {
            if (fn_80016A18(1)) {
                fn_80032B4C();
                fn_80015138(1);
                w->x0 = 0x78;
            }
            t->state = 0x16;
        } else {
            w->x0--;
        }
        break;
    case 22:
        if (w->x0 == 0) {
            t->state = 1;
        } else {
            w->x0--;
        }
        break;
    case 1:
        if (fn_800168D8(0x40000, w, 0)) {
            t->state = 2;
            w->x4 |= 0x80000000;
        } else {
            t->state = 3;
        }
        break;
    case 2:
        if (!(w->x4 & 0x80000000)) {
            t->state = 3;
        }
        break;
    case 3:
        if (fn_800168D8(0x80, w, 0)) {
            t->state = 4;
            w->x4 |= 0x80000000;
        } else {
            t->state = 5;
        }
        break;
    case 4:
        if (!(w->x4 & 0x80000000)) {
            t->state = 5;
        }
        break;
    case 5:
        if (fn_800168D8(0x40000, w, 1)) {
            t->state = 6;
            w->x4 |= 0x80000000;
        } else {
            t->state = 7;
        }
        break;
    case 6:
        if (!(w->x4 & 0x80000000)) {
            t->state = 7;
        }
        break;
    case 7:
        if (fn_800168D8(0x80, w, 1)) {
            t->state = 8;
            w->x4 |= 0x80000000;
        } else {
            t->state = 9;
        }
        break;
    case 8:
        if (!(w->x4 & 0x80000000)) {
            t->state = 9;
        }
        break;
    case 9:
        lbl_80347378 &= ~1;
        lbl_80347378 &= ~2;
        lbl_80347378 &= ~4;
        lbl_80347378 &= ~8;
        for (k = 0; k < 12; k++) {
            Tk_80016580* o = ((Tk_80016580*)fn_800215EC(k));
            if (o != NULL && !(o->work.uw->w->x50 & 0x1000000)) {
                o = ((Tk_80016580*)fn_800215EC(k));
                if (o != NULL) {
                    Unit_80016580* u = o->work.uw->w;
                    if (u->x1dc != NULL) {
                        u->x44 = ((Chr**)lbl_80309DE4)[u->id]->x1c;
                    }
                }
            }
        }
        t->flags |= 0x40;
        lbl_8030A10C.x1c4 -= 1;
        break;
    }
}

void fn_80018868(Task* t, s8 mode, f32 frame)
{
    ChrWork* w;
    ChrInfo* u;
    void* x0;
    DrawState s;
    u16 a;
    u16 b;

    if (mode >= 0) {
        w = t->work;
        u = w->st;
        x0 = w->x0;
        DrawStateDefault2D(&s);
        fn_8007E678(u->x154, &s);
        s.colour.a = u->x264;
        s.control3d |= 0x8000;
        switch (lbl_80346ABD) {
        case 0:
        default:
            a = 0;
            break;
        case 1: a = 0x800; break;
        case 2: a = 0x1000; break;
        case 3: a = 0x1800; break;
        case 4: a = 0x2000; break;
        case 5: a = 0x2800; break;
        case 6: a = 0x3000; break;
        case 7: a = 0x3800; break;
        }
        switch (lbl_80346ABC) {
        case 0:
        default:
            b = 0;
            break;
        case 1: b = 0x100; break;
        case 2: b = 0x200; break;
        case 3: b = 0x300; break;
        case 4: b = 0x400; break;
        case 5: b = 0x500; break;
        case 6: b = 0x600; break;
        case 7: b = 0x700; break;
        }
        fn_8029D008(b | a);
        if (DrawStatePush(&s)) {
            njTranslate(0, u->x274, u->x278, u->x27c);
            switch (u->x28c) {
            case 0:
            case 1:
                njRotateY(0, u->x284);
                njRotateZ(0, u->x288);
                break;
            case 3:
            case 4:
                njRotateX(0, u->x280);
                break;
            }
            njScale(0, u->x268, u->x26c, u->x270);
            switch (mode) {
            case 0:
                fn_80035468(x0, u->x74, u->x84, frame, 1);
                break;
            case 1:
                fn_80035228(x0, u->x74, frame, 1);
                break;
            case 2:
                fn_800353F4(x0, u->x5c, u->x60, frame, 1);
                break;
            case 4:
                fn_8003529C(x0, u->x5c, frame, 1);
                break;
            case 3:
                fn_80035380(x0, u->x5c, frame, 1);
                break;
            }
            DrawStatePop(&s);
        }
    }
}

inline int Match(Task* t, ChrInfo* u)
{
    s16 a;
    s16 b;
    s16 x;
    s16 y;

    if (u->xec & 0x8000) {
        a = u->x14;
        b = u->x16;
    } else {
        a = u->x6;
        b = u->x8;
    }
    switch (u->x20c) {
    case 0x1d:
        if (fn_800153E0(0x1d, u->x20e) != 0) {
            return 1;
        }
    }
    if (a != 0x18) {
        return 0;
    }
    x = fn_800760EC(t, 0x15, -1);
    y = fn_800760EC(t, a, b);
    if (x == y) {
        return 1;
    }
    return 0;
}

inline int Kind(ChrInfo* u)
{
    switch (u->x10) {
    case 0x10:
    case 0x17:
    case 0x1d:
        return 0;
    }
    return 1;
}


inline int Both(Task* t)
{
    ChrInfo* u2 = ChrW(t)->st;
    if (!Kind(u2)) {
        return 0;
    }
    return Match(t, u2);
}

inline int Party(Task* t)
{
    SysObj* s;

    if (lbl_80347394 != NULL) {
        s = lbl_80347394->work;
        if (s->x3c & 0x40000) {
            return 1;
        }
    } else {
        switch (fn_80078478(ChrW(t)->st->id)) {
        case 2:
        case 4:
        case 6:
            return 1;
        }
    }
    return 0;
}

inline int Linked(Task* t)
{
    if (!Match(t, ChrW(t)->st)) {
        return 0;
    }
    return Party(t);
}

void fn_8001CAA8(Task* t)
{
    u32 flags = 0;
    ChrInfo* w = ChrW(t)->st;
    s16 a;
    s16 b;
    ChrInfo* u;

    if (w->x6 == 2 && (w->x50 & 0x08000000)) {
        w->x50 &= ~0x08000000;
        return;
    }
    switch (w->x6) {
    case 2:
    case 7:
        return;
    case 0x1e:
        switch (w->x8) {
        case 0x23:
        case 0x24:
        case 0x25:
            return;
        }
        break;
    }
    if (fn_8001C1F0(t)) {
        fn_800085EC(t, 0x1e, 0x2a, lbl_8030A10C.x10, lbl_8030A10C.x184);
    } else {
        fn_800085EC(t, w->x6, w->x8, ChrW(t)->x10->x30, w->x298);
        fn_80037918(t);
    }
    if (w->xec & 0x100000) {
        return;
    }
    switch (w->x6) {
    case 6:
    case 12:
    case 13:
        return;
    }
    fn_800085EC(t, w->x6, w->x8, lbl_8030A10C.x10, lbl_8030A10C.x184);
    if (Linked(t)) {
        fn_8003136C(t);
        fn_8001CED0(t);
        w->x50 |= 0x20000;
        return;
    }
    w->x50 &= ~0x20000;
    u = ChrW(t)->st;
    if (u->xec & 0x8000) {
        a = u->x14;
        b = u->x16;
    } else {
        a = u->x6;
        b = u->x8;
    }
    flags = 0;
    if (fn_8003136C(t)) {
        fn_8002F154(t, &flags);
    }
    if (fn_80030AE8(flags, w) && Both(t)) {
        return;
    }
    if (fn_80009030(lbl_8030A10C.x10, a, b, -1, -1)) {
        fn_80031254(t);
        w->xec |= 0x80000;
    }
}

int fn_8001CED0(Task* t)
{
    u32 flags = 0;
    ChrInfo* u = ChrW(t)->st;
    s8 r;
    s16 a;
    s16 b;
    ChrInfo* u2;

    r = fn_8002EEFC(t, &flags);
    if (!Kind(ChrW(t)->st)) {
        flags &= ~0x20000000;
    }
    if (r == 2) {
        r = 1;
    }
    if (fn_80030AE8(flags, u) && Both(t)) {
        u2 = ChrW(t)->st;
        if (u2->xec & 0x8000) {
            a = u2->x14;
            b = u2->x16;
        } else {
            a = u2->x6;
            b = u2->x8;
        }
        if (fn_80009030(lbl_8030A10C.x10, a, b, -1, -1)) {
            fn_800312F0(t, a, b, r);
            u->xec &= ~0x8000;
        }
    } else {
        u2 = ChrW(t)->st;
        if (u2->xec & 0x8000) {
            a = u2->x14;
            b = u2->x16;
        } else {
            a = u2->x6;
            b = u2->x8;
        }
        if (fn_80009030(lbl_8030A10C.x10, a, b, -1, -1)) {
            fn_80031254(t);
            u->xec |= 0x80000;
        }
    }
}

extern s32 fn_80075D64(Task*);

extern s32 fn_800091E0(Task*, void*, s16, s32);
extern void fn_8006DC6C(void);
void fn_8001C348(Task* t);
extern void* lbl_80347398;
s32 fn_80020250(Task* t, s16 a, s8 b) {
    ChrWork* w = t->work;
    ChrInfo* u = w->st;
    ChrInfo* o;
    s16 k;
    if (u->xec & 0x100) {
        if (a != 0xF) return 0;
        u->xec &= ~0x100;
    }
    k = fn_80020094(w, a, 0, 0);
    if (k >= 0) {
        if (u->x6 != a || (u->anims[k].flags & 0x4000000)) {
            u->x1c = u->x6;
            u->x6 = a;
            u->x8 = -1;
            u->state = 0;
            u->xe8 = u->xe4;
            u->xe4 = k;
            u->x134 = 0;
            u->x20c = a;
            u->x20e = -1;
            u->x48 = b;
            o = ChrW(FindChrOr0(b))->st;
            u->x4a = o->x6;
            u->x4c = o->x8;
            if (lbl_8034733C == 7 && !(u->xf0 & 0x8000)) {
                if (fn_800091E0(t, lbl_80347398, a, -1) != 0) fn_8006DC6C();
            }
            fn_8001C348(t);
            return 1;
        }
    }
    return 0;
}

s32 fn_80020470(Task* t, s16 x) {
    ChrWork* cw = t->work;
    ChrInfo* w = cw->st;
    if (fn_80075D64(t) == 0) return 0;
    if (x == 14 && (lbl_8030A10C.x6c & 0x20000)) return 0;
    if ((w->x134 == 0 && !(w->xec & 1)) || (w->xf0 & 0x80000)) return 0;
    if (w->xec & 0x100) {
        if (x != 15) return 0;
        if (lbl_8030A10C.x6c & 0x100) return 0;
        w->xec &= ~0x100;
    }
    if (lbl_8030A10C.x68 != 0) {
        switch (x) {
        case 2:
        case 7:
            break;
        default:
            return 0;
        }
    }
    if (lbl_80347394 == 0) {
        switch (w->x6) {
        case 0x1a:
        case 0x1b:
        case 0x1c:
            return 0;
        }
    }
    return 1;
}

s16 fn_80015460(s16 id);
static inline s16 Who(Task* t, s16 v) {
    SysObj* s;
    if (ChrW(t)->st->x1dc != 0) return fn_80015460(v);
    if (lbl_80347394 != 0) {
        s = lbl_80347394->work;
        return s->x6c.x2;
    }
    return 0;
}
static inline s32 Hit20(Task* t, ChrInfo* u, s16 e, s16 k) {
    switch (u->x20c) {
    case 0x1D:
        if (fn_800153E0(0x1D, u->x20e) != 0) return 1;
    }
    if (e != 0x18) return 0;
    {
        s16 a = fn_800760EC(t, 0x15, -1);
        s16 b = fn_800760EC(t, e, k);
        if (a == b) return 1;
        return 0;
    }
}
int fn_80020700(s16 a, s16 b, Task* t) {
    ChrWork* w = t->work;
    ChrInfo* in = w->st;
    switch (in->x20c) {
    case 0x1d:
        if (fn_800153E0(0x1d, in->x20e) != 0) {
            return 1;
        }
        break;
    }
    if (a != 0x18) {
        return 0;
    }
    {
        s16 x = fn_800760EC(t, 0x15, -1);
        s16 y = fn_800760EC(t, a, b);
        return x == y;
    }
}

void fn_800208F4(s16* ev, s16* arg, Task* t) {
    ChrInfo* u = ChrW(t)->st;
    s16 k;
    s16 e;
    s32 hit;
    if (!(u->xec & 0x8000)) {
        e = *ev;
        switch (e) {
        case 0x18:
            k = *arg;
            hit = Hit20(t, u, e, k);
            if (hit != 0) {
                u->xec |= 0x8000;
                u->x14 = *ev;
                u->x16 = *arg;
                if (u->xec & 0x200000) {
                    *ev = 0x16;
                } else {
                    *ev = 0x15;
                }
                *arg = -1;
            }
            break;
        case 0x19:
            u->xec |= 0x8000;
            u->x14 = 0x18;
            u->x16 = Who(t, *arg);
            *ev = 0x10;
            if (lbl_80309174[u->id].xe != 0) *ev = 0x17;
            *arg = -1;
            break;
        case 0x1D:
            if (fn_800153E0(0x1D, *arg) != 0) {
                u->xec |= 0x8000;
                u->x14 = 0x18;
                u->x16 = Who(t, *arg);
            }
            break;
        }
    }
}

int fn_8001FABC(Task* t)
{
    ChrInfo* u;
    ChrWork* w;
    NJS_POINT3 pos;
    f32 d;
    int ang0;
    int ang;
    s16 kind;

    w = t->work;
    u = w->st;
    if (fn_8001EE24(t, &pos) == 0) {
        return 0;
    }
    fn_80071CF0(&pos, &u->x110);
    if ((u->anims[u->xe4].flags & 0x10000000) || (u->xec & 0x800000) || fn_80017A14(u) != 0) {
        return 0;
    }
    if (pos.x == w->pos.x && pos.z == w->pos.z) {
        return 0;
    }
    kind = u->anims[u->xe4].x0;
    ang = fn_80071C74(w, pos.x, pos.z);
    ang0 = ang;
    switch (kind) {
    case 0x13:
        ang = fn_80071C34(pos.x, pos.z, w->pos.x, w->pos.z);
        break;
    }
    if ((u->anims[u->xe4].flags & 0x1000000) || (u->xf0 & 0x20000000)) {
        switch (u->x6) {
        case 0x13:
            fn_80071BCC(u->x104, ang0, u->x130);
            break;
        default:
            fn_80071BCC(u->x104, ang0, u->x12c);
            break;
        }
    }
    if (u->anims[u->xe4].flags & 0x10000) {
        ang = fn_80071C74(w, 0.0f, 0.0f);
    }
    switch (kind) {
    case 0xb:
    case 0xc:
    case 0xd:
    case 0x20:
        if (u->xf0 & 0x40000000) {
            u->xf0 |= 0x200;
            return 0;
        }
    }
    d = fn_8006116C(ang - w->ry);
    if (d < 0.0f) {
        d = -1.0f * d;
    }
    if (d < u->x128) {
        w->ry = ang;
        u->xf0 |= 0x200;
        return 0;
    }
    switch (kind) {
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 0x20:
        u->x11c = fn_8006116C(w->ry);
        u->x120 = fn_8006116C(ang);
        u->x124 = 0.0f;
        w->ry = ang;
        u->xf0 |= 0x200;
        return 0;
    default:
        u->x11c = fn_8006116C(w->ry);
        u->x120 = fn_8006116C(ang);
        fn_80061080(&u->x11c, &u->x120);
        if (u->x120 - u->x11c < 0.0f) {
            u->x124 = -1.0f * u->x128;
        } else {
            u->x124 = u->x128;
        }
        return 1;
    }
}

s32 fn_80015CFC(void* x) {
    u32 n = FLD(x, 4, u32);
    s32 i;
    for (i = 0; (u32)(s16)i < n; i++) {
        char* s = *(char**)((u8*)FLD(x, 0, void*) + i * 12);
        if (s[0] == 't' || s[0] == 'T') {
            if (s[1] == 'k' || s[1] == 'K' || s[1] == 'x' || s[1] == 'X') {
                return i;
            }
        }
    }
    return -1;
}

s32 fn_800176DC(s8 kind) {
    s32 i;
    for (i = 0; (s8)i < 0xc; i++) {
        Task* t = lbl_80309E24[i];
        if (t) {
            void* w = t->work;
            s8 id = fn_80020E10((u8*)FLD(w, 0x10, void*) + 0xc);
            if (kind == id) {
                return FLD(FLD(w, 0x4c, void*), 0, u8);
            }
        }
    }
    return -1;
}

void fn_80018C94(void) {
    DrawStatePop(0);
    fn_800D2048();
}

s32 fn_8001BC38(Task* t) {
    s16 v = fn_80008274(FLD(FLD(t->work, 0x4c, void*), 2, s16));
    switch (v) {
    case 0x8d:
    case 0x95:
    case 0x97:
    case 0x99:
    case 0x9d:
    case 0xee:
        return 1;
    default:
        return 0;
    }
}

void fn_8001D200(Task* t, f32* v) {
    u8* w = t->work;
    u8* d = FLD(w, 0x4c, u8*);
    s16 idx = FLD(w, 0x14, s16);
    fn_800615B4(FLD(d, 0x154, u8*) + (idx - 1) * 0x34 + 8, v, w + 0x28);
    v[0] = v[0] + FLD(w, 0x1c, f32);
    v[1] = v[1] + FLD(w, 0x20, f32);
    v[2] = v[2] + FLD(w, 0x24, f32);
}

s32 fn_8001DDE0(Task* t, Ent_80008800* list) {
    Ent_80008800* p;
    ChrWork* w = t->work;
    ChrInfo* d = w->st;
    if (list) {
        for (p = list;; p++) {
            s16 lo = p->x0;
            s16 hi = p->x2;
            Key* obj;
            if (lo < 0) {
                break;
            }
            if ((((s32)hi << 16) | lo) == 0x30032) {
                obj = p->xc;
                if (fn_8003DCF4(obj, d)) {
                    return obj->x10;
                }
            }
        }
    }
    return 0;
}

void fn_8001E138(void* a, void* b, u32 c) {
    NJS_POINT3 v14;
    NJS_POINT3 v8;
    if (c) {
        fn_80061518(b, &v8);
    } else {
        fn_80071CF0(b, &v8);
    }
    fn_80012130(&v14);
    fn_80071F84(a, &v8, &v14);
}

void fn_8001E19C(NJS_POINT3 *self, NJS_POINT3 *out, void *ctx, NJS_POINT3 *v)
{
    NJS_POINT3 b;
    NJS_POINT3 d;
    NJS_POINT3 a;
    NJS_POINT3 c;
    Ctx8001E19C *o = ((Ctx8001E19C_outer *)ctx)->obj;

    fn_80071CF0(&o->pos, &a);
    a.y = a.y + self->y;
    fn_80071CF0(v, &b);
    fn_80071F84(&c, v, &a);
    fn_80071D0C(out, &a, &c, self->x);
    fn_80071CF0(out, &d);
}

int fn_8001FA18(Obj8001FA18 *a, Obj8001FA18 *b)
{
    Inner8001FA18 *in_b;
    Inner8001FA18 *in_a;
    Obj8001FA18 *o;
    o = b->sub;
    in_b = o->inner;
    in_a = a->sub->inner;

    fn_80071CF0(&in_a->v110, &in_b->v110);
    fn_80071CF0(&in_a->v104, &in_b->v104);
    fn_80071CF0(&in_a->v11c, &in_b->v11c);
    if (in_a->flags & 0x200) {
        o->f2c = a->sub->f2c;
    }
    if (!(in_a->flags & 0x400)) {
        return 0;
    }
    return 1;
}

void fn_80020B28(Obj80020B28 *o)
{
    if (o->flags & 0x8000) {
        o->flags = o->flags & ~0x8000;
        o->x6 = o->x14;
        o->x8 = o->x16;
    }
}

void fn_80014F90(u8 flag) {
    s8 i;
    s8 start;
    s8 end;
    if (flag) {
        start = 4;
        end = 0xc;
    } else {
        start = 0;
        end = 4;
    }
    for (i = start; i < end; i++) {
        Task* t = fn_800215EC(i);
        if (t) {
            void* d = FLD(t->work, 0x4c, void*);
            if (!(FLD(d, 0x50, u32) & 0x01000000)) {
                fn_80015020(i);
            }
        }
    }
}

void fn_800152A0(void) {
    s8 i;
    for (i = 0; i < 0xc; i++) {
        Task* t = fn_800215EC(i);
        void* d;
        if (t == 0) {
            continue;
        }
        if (FLD(FLD(t->work, 0x4c, void*), 0x50, u32) & 0x01000000) {
            continue;
        }
        t = fn_800215EC(i);
        if (t == 0) {
            continue;
        }
        d = FLD(t->work, 0x4c, void*);
        if (FLD(d, 0x1dc, void*) == 0) {
            continue;
        }
        FLD(d, 0x44, s32) = FLD(lbl_80309DE4[FLD(d, 0, s8)], 0x1c, s32);
    }
}

void fn_80015344(s8 id) {
    Task* t = fn_800215EC(id);
    if (t) {
        void* d = FLD(t->work, 0x4c, void*);
        if (FLD(d, 0x1dc, void*)) {
            FLD(d, 0x44, s32) = FLD(lbl_80309DE4[FLD(d, 0, s8)], 0x1c, s32);
        }
    }
}

void fn_8001DCA0(ChrInfo* o) {
    if (o->x1dc) {
        fn_8001DD00(o, o->x20);
        lbl_80309730[o->id].b9 = 1;
    }
}

void fn_8001D14C(ChrInfo* o) {
    if (o->xec & 0x10) {
        if (o->x1dc) {
            fn_8001DD00(o, o->x20);
            lbl_80309730[o->id].b9 = 1;
        }
        o->xec &= ~0x10;
        o->x134 = 1;
    }
    o->xec &= ~0x40000;
}

void fn_8001D5C0(s16* a, s16* b) {
    if (lbl_80347394) {
        SysObj* s = lbl_80347394->work;
        ChrInfo* d = ChrW(s->owner)->st;
        *a = d->id;
        *b = d->target;
        return;
    }
    *a = lbl_80347330;
    *b = lbl_80347328;
    if (*b < 0 || *b >= 0xc) {
        *b = *a;
    }
}

void fn_8001E4A0(void *a, NJS_POINT3 *v, Task *c)
{
    ChrWork *o = c->work;
    fn_800615B4(a, v, &o->rx);
    v->x = v->x + o->pos.x;
    v->y = v->y + o->pos.y;
    v->z = v->z + o->pos.z;
}

void fn_80014784(void) {
    Obj_80014784* o;

    if (lbl_80347394 == 0) {
        o = fn_802268E8(lbl_803475A8, fn_800136DC);
        if (o != 0) {
            o->data = fn_801E1C7C(0x70);
            memset(o->data, 0, 0x70);
            fn_80061F58(&o->data->x6c, 0x38, 0);
            fn_80014AB8(0, o->data);
        }
    }
}

s16 fn_80015C30(NJS_TEXLIST* t, const char* str) {
    s16 i;
    s16 j;
    s16 len;
    if (t == NULL || t->textures == NULL) {
        return -1;
    }
    len = strlen(str);
    for (i = 0; i < t->nbTexture; i++) {
        const char* n = t->textures[i].filename;
        j = 0;
        while (j < len) {
            if (n[j] != str[j]) {
                break;
            }
            j++;
        }
        if (j == len) {
            return i;
        }
    }
    return -1;
}

void fn_80019D7C(Task* t) {
    Work_80019D7C* w = t->work;
    Inner_80019D7C* in = w->in;
    switch (in->x12) {
    case 0: {
        Task* o = fn_802268E8(lbl_803475A8, fn_80019B70);
        fn_80061F58(&o->work, 0x18, 0);
        SeqW(o)->owner = t;
        SeqW(o)->b = t;
        SeqW(o)->kind[0] = 11;
        SeqW(o)->kind[1] = 5;
        in->x12 = 1;
        break;
    }
    case 1:
        break;
    }
    fn_80018CBC(t, in->xe8, 0, 0, in->x2);
}

void fn_8001C348(Task* t) {
    ChrWork* cw = t->work;
    ChrInfo* w = cw->st;
    if (fn_8001C1F0(t) != 0) {
        w->xf4 &= 0x7FFFFFFF;
    }
    if (w->xf4 & 0x80000000) {
        w->xec |= 0x40;
    } else {
        w->xec &= ~0x40;
    }
    if (w->xf4 & 0x40000000) {
        switch (w->x4a) {
        case 4:
        case 5:
        case 8:
            w->xec |= 0x20;
            break;
        default:
            w->xec &= ~0x20;
            break;
        }
    } else {
        w->xec &= ~0x20;
    }
}

void fn_8001DE78(Task* t, s8 which, Item* list) {
    Item* p;
    ChrInfo* d = ChrW(t)->st;
    Cmd* obj;
    if (list != NULL) {
        for (p = list;; p++) {
            s16 lo = p->lo;
            s16 hi = p->hi;
            if (lo < 0) {
                break;
            }
            if ((((s32)hi << 16) | lo) == 0x30007) {
                obj = p->obj;
                if (fn_8003DCF4(obj, d)) {
                    switch (which) {
                    case 0:
                        d->x138 = obj->x10;
                        break;
                    case 1:
                        d->x138 = obj->x12;
                        break;
                    }
                    break;
                }
            }
        }
    }
}

s32 fn_80017018(s8 idx) {
    Tsk_80017018 *t = fn_80021658(idx);
    ChrInfo *d;
    s16 k;
    s16 m;
    if (t == 0) {
        return 0;
    }
    d = t->work->st;
    k = fn_80020094(t->work, 1, -1, 1);
    if (k < 0) {
        return 0;
    }
    if (fn_80008274(d->x2) == 0xe9) {
        f32 s = 0.8f;
        t->work->scl.x = s;
        t->work->scl.y = s;
        t->work->scl.z = s;
        return 1;
    }
    m = d->anims[k].xe;
    if (m == 0) {
        return 0;
    }
    {
        f32 s = 0.1f * m + 1.0f;
        t->work->scl.x = s;
        t->work->scl.y = s;
        t->work->scl.z = s;
    }
    return 1;
}

s32 fn_8001BAC0(Unit_8001BAC0* u, s16 idx, s16 want, s16 other)
{
    s16 v;
    s16 t = u->x6;
    s32 bad = 0;
    u32 flags;
    if (t == 30) {
        v = u->x8;
        switch (v) {
        case 35:
            switch (u->x26) {
            case 1:
            case 3:
                switch (u->x20) {
                case 0:
                case 2:
                    bad = 1;
                    break;
                }
                break;
            }
            break;
        case 36:
        case 37:
            if (v != other) bad = 1;
            break;
        }
    }
    if (t != want) {
        if (want == 16 || want == 23) {
            if (t != 24) bad = 1;
        } else {
            bad = 1;
        }
    }
    flags = u->xdc[idx].flags;
    if (flags & 0x4000000) {
        s32 ok;
        switch (want) {
        case 4:
        case 5:
        case 8:
        case 9:
        case 10:
            ok = 1;
            break;
        default:
            ok = 0;
            break;
        }
        if (!ok) bad = 1;
    }
    if (flags & 0x1000000) {
        if (u->xec & 0x20000) bad = 1;
    }
    return bad;
}

void fn_8001E3D8(void* a, NJS_POINT3* out, Task_8001E3D8* t) {
    NJS_POINT3 v;
    Work_8001E3D8* w;
    fn_800615B4(a, out, &t->work->pos);
    w = t->work;
    fn_800615B4(w->model->joints[w->idx - 1].data, &v, &w->pos);
    v.x = v.x + w->off.x;
    v.y = v.y + w->off.y;
    v.z = v.z + w->off.z;
    out->x = out->x + v.x;
    out->y = out->y + v.y;
    out->z = out->z + v.z;
}

void fn_8001E308(void *a, NJS_POINT3 *out, Tk1E *t)
{
    NJS_POINT3 v;
    Wk1E *w2;
    Wk1E *w = t->work;

    fn_800615B4(a, out, &w->x28);
    w2 = t->work;
    fn_800615B4(w2->d->tbl + (w2->idx - 1) * 0x34 + 8, &v, &w2->x28);
    v.x = v.x + w2->x1c;
    v.y = v.y + w2->x20;
    v.z = v.z + w2->x24;
    out->x = out->x + v.x;
    out->y = out->y + w->x20;
    out->z = out->z + v.z;
}

void fn_8001E238(NJS_POINT3 *self, void *out, Tk1E_8001E238 *t)
{
    NJS_POINT3 v20;
    NJS_POINT3 v14;
    NJS_POINT3 v8;
    Wk1E_8001E238 *w = t->work;

    fn_800615B4(w->d->tbl + (w->idx - 1) * 0x34 + 8, &v20, &w->x28);
    v20.x = v20.x + w->x1c;
    v20.y = v20.y + w->x20;
    v20.z = v20.z + w->x24;
    v20.y = v20.y + self->y;
    fn_80012130(&v14);
    fn_80071F84(&v8, &v14, &v20);
    fn_80071D0C(out, &v20, &v8, self->x);
}

void fn_80014BA8(void) {
    s8 i;
    for (i = 0; i < 12; i++) {
        Task* t = fn_800215EC(i);
        if (t != 0) {
            ChrInfo* u = ChrW(t)->st;
            u32 fl = lbl_80309DE4[(s8)u->id]->bits;
            u16 m = 0;
            if (!(fl & 0x80)) m |= 0x1;
            if (!(fl & 0x200)) m |= 0x20;
            if (!(fl & 0x400)) m |= 0x8;
            if (!(fl & 0x800)) m |= 0x10;
            if (!(fl & 0x4000)) m |= 0x4;
            if (!(fl & 0x40000)) m |= 0x100;
            if (m != 0) {
                fn_8002923C(u->id, m, 0);
            }
        }
    }
}

s32 fn_80015D78(void* t, s32 id, s32 p5, s32 p6, s32 p7, s16 mode) {
    s8 arr[14];
    s8 i;
    for (i = 0; i < 14; i++) {
        arr[i] = -1;
    }
    switch (mode) {
    case 0:
        fn_8001604C(t, arr, p5, 2);
        break;
    case 1:
        return fn_80016234(t, 0, id, p6, p7);
    case 2:
        return fn_80016234(t, 1, id, p6, p7);
    case 3:
        fn_80015EC8(t, arr, 0);
        break;
    }
    for (i = 0; i < 14; i++) {
        if (arr[i] == (s16)id) {
            return 1;
        }
    }
    return 0;
}

s32 fn_800163A4(Task* t, s8 flag, s8 mode, s16 want, s16 cols, s16 rows) {
    ChrWork* w = t->work;
    ChrInfo* u = w->st;
    NJS_POINT3 v;
    f32 step;
    f32 x0;
    s8 j;
    s8 i;
    s8 id;
    s32 sel;
    if (u->id == want) {
        return 0;
    }
    if (flag != 0) {
        sel = u->target;
    } else {
        sel = u->id;
    }
    fn_8001E6DC(&v, sel);
    step = 15.0f;
    v.x = v.x - step * (cols / 2);
    x0 = v.x;
    v.z = v.z - step * (rows / 2);
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            id = fn_80018398(&v, 1);
            if (id >= 0 && id < 12 && id == want) {
                return 1;
            }
            v.x = v.x + step;
        }
        v.x = x0;
        v.z = v.z + step;
    }
    switch (mode) {
    default:
        return 0;
    case 1:
        if (fn_8001D944(want, t) == 0) {
            return 0;
        }
        break;
    case 2:
        if (fn_8001D944(want, t) != 0) {
            return 0;
        }
        break;
    }
    return 1;
}

s16 fn_80020094(ChrWork *w, s16 a, s16 b, s8 flag) {
    s16 i = 0;
    ChrInfo *u = w->st;
    ChrAnim *r;

    if (a == 0x16) a = 0x15;
    for (; u->anims[i].x2 != 3; i++) {
        r = &u->anims[i];
        if (a != r->x0) continue;
        switch (a) {
        case 24:
        case 29:
        case 30:
            if (b != r->xc) continue;
            if (flag == 0) u->xe0 = fn_800300C4(u->anims[i].x4);
            return i;
        case 14:
            if (flag == 0) {
                u->xe0 = fn_800300C4(13);
            } else {
                u->xec |= 2;
            }
            return i;
        case 9:
            if (flag == 0) u->xe0 = fn_800300C4(11);
            return i;
        case 10:
            if (flag == 0) u->xe0 = fn_800300C4(12);
            return i;
        default:
            if (flag == 0) u->xe0 = fn_800300C4(u->anims[i].x4);
            return i;
        }
    }
    if (a == 14 && flag == 0) {
        u->xe0 = fn_800300C4(13);
        return 0;
    }
    if (a == 0x25 && flag == 0) {
        u->xe0 = fn_800300C4(14);
        return 0;
    }
    return -1;
}

static inline s16 FindRec(ChrInfo* u, s16 a, s16 b) {
    s16 i;
    for (i = 0; u->anims[i].x2 != 3; i++) {
        if (a == u->anims[i].x0) {
            if (b >= 0) {
                if (b == u->anims[i].xc) return i;
            } else {
                return i;
            }
        }
    }
    return -1;
}

s32 fn_8001ECB4(Task* t, s16 a, s16* out, s16 b) {
    ChrWork* wk = t->work;
    ChrInfo* u = wk->st;
    s16 k;
    s16 v;
    if (a == 0x16) a = 0x15;
    k = FindRec(u, a, b);
    if (k < 0) return 0;
    if (fn_8001C1F0(t) != 0) return 0;
    v = fn_800760EC(t, a, b);
    if (u->x5c != 0 && u->x64 == v) return 0;
    if (a == 2 || a == 7) {
        if (u->x204 != 0) k = u->x204;
    }
    if (u->anims[k].x10 || (u->xf0 & 0x40000)) {
        *out = k;
        return 2;
    }
    return 1;
}

void fn_80017A7C(Task *t)
{
    ChrWork *w = t->work;
    ChrInfo *s = w->st;

    switch (s->state) {
    case 0:
        memset(&w->pos, 0, sizeof(NJS_POINT3));
        fn_80071CF0(&w->pos, &s->pos);
        fn_80075F2C(t);
        s->state = 1;
    case 1:
        s->x134 = 1;
        break;
    }
    fn_80017CB8(t, s->xe4);
}

extern s32 fn_800205B8(s16 id);
extern s32 fn_8001ECB4(Task *t, s16 a, s16 *out, s16 b);
extern void fn_8001CAA8(Task *t);
extern s8 fn_8001E910(Task *t);

void fn_80017B18(Task* t) {
    ChrWork *w = t->work;
    ChrInfo *u = w->st;
    s32 flag = 0;
    s16 buf[4];
    if (fn_800205B8(u->id)) flag = 1;
    switch (u->state) {
    case 0:
        u->xf0 &= ~0x10000000;
        u->state = 1;
    case 1:
        if (flag != 0 && lbl_8030A10C.x68 == 0) {
            if (fn_8006DB94() != 0) {
                u->state = 2;
            } else {
                fn_80032C68();
                break;
            }
        } else {
            u->state = 2;
        }
    case 2:
        fn_8001ECB4(t, u->x6, buf, u->x8);
        fn_80075F2C(t);
        u->state = 3;
    case 3:
        w = t->work;
        u->x138 = fn_8001DDE0(t, w->x10->x30);
        u->state = 4;
    case 4:
        if (u->x138 != 0) {
            u->x138--;
            break;
        }
        u->state = 5;
    case 5:
        u->xf0 |= 0x10000000;
        fn_8001CAA8(t);
        u->state = 6;
    case 6:
        switch (fn_8001E910(t)) {
        case 1:
        case 2:
            u->state = 7;
            u->x134 = 1;
        }
    case 7:
        break;
    }
    switch (u->state) {
    case 1:
        break;
    default:
        fn_80017CB8(t, u->xe4);
        break;
    }
}

static inline Task* Find(s8 id) {
    s8 i;
    for (i = 0; i < 14; i++) {
        Task* t = lbl_80309E24[i];
        if (t != 0) {
            ChrWork* w = t->work;
            if (w->st->id == id) return lbl_80309E24[i];
        }
    }
    return 0;
}
int fn_8001D944(s8 id, Task* t) {
    int r = 0;
    ChrWork* w = t->work;
    ChrInfo* st = w->st;
    if (st->id == id) {
        return 0;
    }
    if (st->x1dc == 0) {
        Task* o = Find(id);
        s8 a;
        s8 b;
        SysObj* sw;
        o = o ? o : Find(0);
        a = fn_80020E10(w->x10->xc);
        w = o->work;
        b = fn_80020E10(w->x10->xc);
        if ((a < 0 && b < 0) || (a >= 0 && b >= 0)) {
            r = 0;
        } else {
            r = 1;
        }
        sw = lbl_80347394->work;
        if (sw->x3c & 0x4000) {
            if (r == 1) {
                r = 0;
            } else {
                r = 1;
            }
        }
        return r;
    }
    if (st->id < 4 && id >= 4) {
        r = 1;
    }
    if (st->id >= 4 && id < 4) {
        r = 1;
    }
    if (lbl_80347394 == 0) {
        if (fn_80014C90(st->id, 0x400000)) {
            if (r == 1) {
                r = 0;
            } else {
                r = 1;
            }
        }
    }
    return r;
}

s32 fn_8001DB44(Task* t, s8 mode) {
    ChrWork* w = t->work;
    Task* o;
    ChrInfo* u;
    o = Find(w->st->target);
    o = o ? o : Find(0);
    w = o->work;
    u = w->st;
    switch (mode) {
    case 0:
        if (u->x6 == 0xb || u->x6 == 0x20) return 1;
        break;
    case 1:
        if (u->xf0 & 0x00400000) return 1;
        break;
    }
    return 0;
}

/* Three-step task: on step 1 clears flags 0x100000 and 8 of every character that has them and
 * calls fn_8001BE2C on it, then marks itself done (flag 0x40). */
void fn_80015640(Task* o) {
    s8 i;
    switch (o->state) {
    case 0:
        o->state = 1;
        break;
    case 1:
        for (i = 0; i < 12; i++) {
            Task* t = lbl_80309E24[i];
            if (t != 0) {
                ChrWork* cw = t->work;
                ChrInfo* w = cw->st;
                if ((w->xec & 0x100000) || (w->xec & 8)) {
                    w->xec &= ~0x100000;
                    w->xec &= ~8;
                    fn_8001BE2C(t);
                }
            }
        }
        o->state = 2;
    case 2:
        o->flags |= 0x40;
        break;
    }
}

void fn_800171F0(s8 ia, s8 ib, NJS_POINT3* o1, NJS_POINT3* o2)
{
    NJS_POINT3 pa;
    NJS_POINT3 pb;
    NJS_POINT3 t;
    Obj_800171F0* a = fn_80021658(ia);
    Obj_800171F0* b = fn_80021658(ib);
    f32 d;
    fn_80071CF0(&a->work->pos, &pa);
    fn_80071CF0(&b->work->pos, &pb);
    d = fn_80071E9C(&pa, &pb);
    if (a->work->x4c->xec & 0x200000) {
        d += 22.5f;
    } else {
        d += 7.5f;
    }
    t.x = d;
    t.y = 0.0f;
    fn_8001E19C(&t, o1, b, &a->work->pos);
    d = fn_80071E9C(&pa, &pb);
    if (b->work->x4c->xec & 0x200000) {
        d += 22.5f;
    } else {
        d += 7.5f;
    }
    t.x = d;
    t.y = 0.0f;
    fn_8001E19C(&t, o2, a, &b->work->pos);
}

static inline Task *FindUnit(s8 id) {
    s8 i;
    for (i = 0; i < 14; i++) {
        Task *t = lbl_80309E24[i];
        if (t != NULL) {
            ChrWork *w = t->work;
            if (w->st->id == id) {
                return lbl_80309E24[i];
            }
        }
    }
    return NULL;
}

Task *fn_8001E05C(Task *t) {
    ChrWork *w = t->work;
    Task *r = FindUnit(w->st->target);
    if (r != NULL) {
        return r;
    }
    return FindUnit(0);
}

void fn_80015A58(NJS_POINT3 *base, s16 n, NJS_POINT3 *out, f32 ang) {
    NJS_POINT3 tmp;
    NJS_POINT3 pts[4];
    s32 k;
    s16 t;
    s16 d;
    NJS_POINT3 *q;
    s16 rem;
    s16 idx;
    s16 j;
    f32 f;
    if (ang >= 360.0f) ang -= 360.0f;
    k = 360 / n;
    t = (s32)ang;
    d = t / k;
    rem = t % k;
    idx = d - 1;
    if (idx < 0) idx = n - 1;
    q = pts;
    for (j = 0; j < 4; j++) {
        fn_80071CF0(&base[idx], q);
        idx++;
        if (idx >= n) idx = 0;
        q++;
    }
    f = (f32)rem / (f32)k;
    if (f <= 0.0f) f = 0.01f;
    if (f >= 1.0f) f = 0.09f;
    fn_802917C8(pts, out, &tmp, f);
}

s16 fn_80015460(s16 id) {
    s32 k;
    s8 i;
    for (i = 0; (k = lbl_802ACDF0[i].key) >= 0; i++) {
        if (id == k - 0xf0) {
            return lbl_802ACDF0[i].val;
        }
    }
    return 0;
}

static inline Task *FindTask(s8 idx) {
    s8 i;
    for (i = 0; i < 14; i++) {
        Task *t = lbl_80309E24[i];
        if (t != 0) {
            ChrWork *w = t->work;
            if (w->st->id == idx) {
                return lbl_80309E24[i];
            }
        }
    }
    return 0;
}

static inline Task *FindTaskOrDefault(s8 idx) {
    Task *t = FindTask(idx);
    if (t != 0) {
        return t;
    }
    return FindTask(0);
}

s32 fn_8001DF44(Task *self, f32 *out) {
    ChrWork *w = self->work;
    Task *t = FindTaskOrDefault(w->st->target);
    if (t == 0) {
        return 0;
    }
    w = t->work;
    fn_80071CF0(&w->pos, out);
    return 1;
}

s32 fn_8001EBA4(Task *o, s16 idx) {
    ChrInfo *c = ChrW(o)->st;
    s32 v;
    f32 f;
    if (c->x64 == idx) {
        return 0;
    }
    if ((c->x6 == 2 || c->x6 == 7) && c->x204 != 0) {
        v = c->anims[c->x204].x6;
    } else {
        v = c->anims[idx].x6;
    }
    f = c->anims[idx].x10;
    if (f < 1.0f && (c->xf0 & 0x40000)) {
        f = 5.0f;
    }
    f = 1.0f / f;
    if (fn_80076170(0.0f, f, o->work, v, c->anims[idx].x0, c->anims[idx].xc)) {
        c->xec |= 0x80000000;
        fn_80072770(o);
    }
    c->x64 = -1;
    return 1;
}

/* Clears pending word 1 (sel 1, 0x40) or 0 (sel 0, 0x44) if it equals val; 1 if cleared. */
s32 fn_80014A54(u8 sel, SysObj* val) {
    s32 r = 0;
    switch (sel) {
    case 0:
        if (lbl_80309EC8.x44 == val) {
            lbl_80309EC8.x44 = 0;
            r = 1;
        }
        break;
    case 1:
        if (lbl_80309EC8.x40 == val) {
            lbl_80309EC8.x40 = 0;
            r = 1;
        }
        break;
    }
    return r;
}

void fn_8001FD7C(Wrap8001FD7C *w)
{
    ChrWork *e = w->ent;
    ChrInfo *in = e->st;
    if (in->anims[in->xe4].flags & 0x10000) {
        e->ry = fn_80071C74(e, 0.0f, 0.0f);
    }
}

s32 fn_8001FDD8(Obj8001FDD8 *obj, s16 a, s16 b)
{
    s32 i;
    for (i = 0; obj->inner->tab[i].type != 3; i++) {
        Ent8001FDD8 *e = &obj->inner->tab[i];
        if (a == e->key0) {
            if (b >= 0) {
                if (b == e->key12) return i;
            } else {
                return i;
            }
        }
    }
    return -1;
}

s32 fn_8001F3F0(Task* t, NJS_POINT3* out)
{
    ChrWork* w = t->work;
    ChrInfo* st = w->st;
    Task* o;
    ChrWork* ow;
    ChrWork* w2;
    NJS_POINT3 tmp;
    Angle zero[3];

    switch (st->x6) {
    default:
        return 0;
    case 6:
    case 19:
        if (st->pos.x == w->pos.x && st->pos.z == w->pos.z) {
            if (lbl_8030A6D4[2].flags & 0x40) {
                fn_80061C80(&tmp, 0.1f, 90.0f, 30.0f, 0);
            } else {
                fn_80061C80(&tmp, 0.1f, 45.0f, 40.0f, 0);
            }
            tmp.y += 10.0f;
            zero[0] = 0;
            zero[1] = 0;
            zero[2] = 0;
            fn_800615B4(&tmp, out, zero);
            out->x += w->pos.x;
            out->y += w->pos.y;
            out->z += w->pos.z;
        } else {
            out->x = st->pos.x;
            out->y = w->pos.y;
            out->z = st->pos.z;
        }
        break;
    case 2:
        if (lbl_8030A6D4[2].flags & 0x40) {
            o = Find(st->target);
            o = o ? o : Find(0);
            ow = o->work;
            fn_80071CF0(&ow->pos, out);
            break;
        }
        return 0;
    case 4:
    case 5:
    case 8:
    case 16:
    case 21:
    case 22:
    case 23:
    case 24:
    case 29:
        w2 = t->work;
        o = Find(w2->st->target);
        o = o ? o : Find(0);
        ow = o->work;
            fn_80071CF0(&ow->pos, out);
        break;
    case 9:
    case 10:
    case 11:
    case 13:
    case 32:
        w2 = t->work;
        o = Find(w2->st->x48);
        o = o ? o : Find(0);
        ow = o->work;
            fn_80071CF0(&ow->pos, out);
        break;
    }
    return 1;
}

s32 fn_8001C12C(void)
{
    ChrInfo* st;
    s8 i;
    s8 a = 0;
    s8 b = 0;
    Task* t;
    ChrWork* w;
    s32 r;

    for (i = 0; i < 12; i++) {
        t = lbl_80309E24[i];
        if (t != NULL) {
            w = t->work;
            st = w->st;
            r = fn_80020E10(w->x10->xc);
            if ((s8)r < 0) {
                if (st->x6 != 0xe) {
                    a++;
                }
            } else {
                if (st->x6 != 0xe) {
                    b++;
                }
            }
        }
    }
    if (a == 0) {
        return 1;
    }
    return (b != 0) ? 0 : 2;
}

void fn_8001E50C(NJS_POINT3 *a, NJS_POINT3 *out, RotRef *extra) {
    NJS_POINT3 d;
    RotObj *obj = extra->obj;
    fn_80071CF0(a, &d);
    d.x = d.x - obj->pos.x;
    d.y = d.y - obj->pos.y;
    d.z = d.z - obj->pos.z;
    obj = extra->obj;
    fn_800615B4(&d, out, obj->rot);
    out->x = out->x + obj->pos.x;
    out->y = out->y + obj->pos.y;
    out->z = out->z + obj->pos.z;
}

static inline Task* FindOr0(s8 id) {
    Task* o = Find(id);
    if (o != NULL) {
        return o;
    }
    return Find(0);
}

/* Collects into out (-1 terminated) the ids of the characters standing on a w x h grid of
 * 15-unit cells centred on center, the task's target or the task itself; returns the count. */
s8 fn_8001D628(Task* t, s16* out, s8 w, s8 h, NJS_POINT3* center, s8 flag)
{
    ChrWork* tw = t->work;
    ChrInfo* u = tw->st;
    s8 cnt = 1;
    f32 x0;
    NJS_POINT3 pos;
    s8 v;
    Task* o;
    s8 i;
    s8 j;
    s16 id;
    s8 k;
    int ok;

    if (center == NULL) {
        if (flag == 0) {
            id = u->target;
            out[0] = id;
            tw = t->work;
            o = FindOr0(tw->st->target);
            if (o != NULL) {
                ChrWork* ow = o->work;
                fn_80071CF0(&ow->pos, &pos);
            }
        } else {
            tw = t->work;
            fn_80071CF0(&tw->pos, &pos);
            id = u->id;
            cnt = 0;
        }
    } else {
        id = u->id;
        fn_80071CF0(center, &pos);
        cnt = 0;
    }
    pos.x -= 15.0f * (w / 2);
    pos.z -= 15.0f * (h / 2);
    x0 = pos.x;
    for (j = 0; j < h; j++) {
        for (i = 0; i < w; i++) {
            v = fn_80018398(&pos, 0);
            if (v >= 0 && v != id && v < 12 && fn_8001D944(v, t)) {
                ok = 1;
                for (k = 0; k < cnt; k++) {
                    if (v == out[k]) {
                        ok = 0;
                        break;
                    }
                }
                if (ok) {
                    out[cnt] = v;
                    cnt++;
                }
            }
            pos.x += 15.0f;
        }
        pos.x = x0;
        pos.z += 15.0f;
    }
    out[cnt] = -1;
    return cnt;
}

static inline Task* Find3(s8 key) {
    Task* r = Find(key);
    if (r != 0) return r;
    return Find(0);
}

/* Point at angle ang and distance radius (30, doubled for large characters, when 0) around
 * character id, on its ground height. */
void fn_8001D288(f32* out, s8 id, f32 ang, f32 radius) {
    Task* t;
    Unit_8001D288* w;
    f32 r;
    f32 buf[3];
    Wk_8001D288* wk;
    t = Find3(id);
    wk = t->work;
    w = wk->w;
    if (radius) {
        r = radius;
    } else {
        r = 30.0f;
        if (w->xec & 0x200000) r *= 2.0f;
    }
    fn_80061C80(buf, 0.0f, ang, r, 0);
    wk = t->work;
    fn_800615B4(buf, out, wk->rot);
    wk = t->work;
    out[0] = out[0] + wk->x;
    out[1] = w->x15c;
    wk = t->work;
    out[2] = out[2] + wk->z;
}
s32 fn_800205B8(s16 id) {
    s16 a, b;
    if (lbl_8034733C == 7) {
        ChrWork *w = Find3(id)->work;
        if (!(w->st->xf0 & 0x8000)) return 1;
    }
    fn_8001D41C(&a, &b);
    if (a == id) return 1;
    return 0;
}

int fn_8001BCC8(s16 id) {
    int ret = 0;
    int r;
    if (lbl_8034733C == 7) {
        Task* o = Find(id);
        ChrWork* w;
        o = o ? o : Find(0);
        w = o->work;
        if (!(w->st->xf0 & 0x8000)) {
            r = 1;
            goto done;
        }
    }
    {
        s16 b;
        s16 a;
        fn_8001D41C(&a, &b);
        if (a == id) {
            r = 1;
        } else {
            r = 0;
        }
    }
done:
    if (r) ret = 1;
    return ret;
}

#ifdef NONMATCHING
typedef struct Inner {
    u8 pad0[6];
    s16 x6;
    s16 x8;
    u8 padA[6];
    s16 x10;
    u8 pad12[2];
    s16 x14;
    s16 x16;
    u8 pad18[0xec - 0x18];
    u32 xec;
    u8 padf0[0x20c - 0xf0];
    s16 x20c;
    s16 x20e;
} Inner;
typedef struct Work { u8 pad[0x4c]; Inner* inner; } Work;
#endif

#ifdef NONMATCHING
int fn_800207C8(Task* t) {
    Work* w = t->work;
    Inner* in = w->inner;
    s16 a;
    s16 b;
    int ok;
    switch (in->x10) {
    case 0x10:
    case 0x17:
    case 0x1d:
        ok = 0;
        break;
    default:
        ok = 1;
        break;
    }
    if (!ok) {
        return 0;
    }
    if (in->xec & 0x8000) {
        a = in->x14;
        b = in->x16;
    } else {
        a = in->x6;
        b = in->x8;
    }
    switch (in->x20c) {
    case 0x1d:
        if (fn_800153E0(0x1d, in->x20e) != 0) {
            return 1;
        }
        break;
    }
    if (a != 0x18) {
        return 0;
    }
    {
        s16 x = fn_800760EC(t, 0x15, -1);
        s16 y = fn_800760EC(t, a, b);
        ok = 0;
        if (x == y) {
            ok = 1;
        }
    }
    return ok;
}
#endif

/* NEAR (20 lines): params land in other callee-saved registers (orig b r31, d r30, a r29, c r28). */
