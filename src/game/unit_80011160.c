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
#define PTR(p, off) (*(void**)((u8*)(p) + (off)))
typedef struct Vec3 {
    f32 x;
    f32 y;
    f32 z;
} Vec3;
typedef struct Sub2_BB28 {
    u8 pad[0x4C];
    void* x4c;
    u32 x50;
} Sub2_BB28;
typedef struct Rec_BB28 {
    void* x0;
    u8 pad4[4];
    u32* x8;
    u32 xc;
    u8 pad10[6];
    s16 x16;
    s16 x18;
    u8 pad1a[0x40 - 0x1A];
    u32 x40;
    u8 pad44[0x4C - 0x44];
} Rec_BB28;
typedef struct Work_BB28 {
    Rec_BB28 r;
    Sub2_BB28* x4c;
    u8 pad50[8];
} Work_BB28;
typedef struct Ent_BB28 {
    Rec_BB28* recs;
    struct { u8 pad[8]; void* x8; }* x4;
    Work_BB28** ptrs;
    u8 xc;              /* 0x0c record count */
    u8 padd[3];
    void* x10;
} Ent_BB28;
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
extern s32 lbl_8034733C;
extern Task* lbl_80309E24[];
typedef struct Key16 {
    u32 frame;
    f32 v[3];
} Key16;
typedef struct Track {
    Key16* keys;
    u32 pad4;
    u32 count;
} Track;
typedef struct AnimHdr {
    Track* track;
    u32 length;
} AnimHdr;
typedef struct AnimPlay {
    AnimHdr* anim;
    u8 pad4[4];
    u32 end;
    u32 idx;
    u8 pad10[4];
    f32 speed;
    f32 time;
    f32 out[3];
} AnimPlay;
extern void fn_80061C80(void*, f32, f32, f32, int);
extern u32 fn_800153E0(s32, s16);
extern s8 fn_80020E10(void* p);
extern s32 fn_8025ECC4(void);

inline ChrWork* ChrW(Task* t)
{
    return t->work;
}
/* The 0x70-byte objects lbl_80309EC8 keeps at 0x40/0x44 (fn_80014AB8); 0x20000000 in flags
 * releases one. */
/* The 0x38-byte block at SysObj 0x6c. */
typedef struct SysSub {
    u8 pad0[2];
    s16 x2;             /* 0x02 */
    u8 pad4[0x38 - 4];
} SysSub;
typedef struct SysObj {
    u8 pad0[0x3c];
    u32 x3c;            /* 0x3c */
    u8 pad40[0x50 - 0x40];
    Task* owner;        /* 0x50: the character it belongs to */
    u8 pad54[0x5a - 0x54];
    s16 x5a;            /* 0x5a */
    s16 x5c;            /* 0x5c */
    u8 pad5e[0x68 - 0x5e];
    u32 flags;          /* 0x68 */
    SysSub x6c;         /* 0x6c: cleared as a whole by fn_80061F58 */
} SysObj;
/* lbl_80309EC8 0x88..0x204, cleared as one block by fn_80014AB8. */
typedef struct SysMove {
    u8 pad0[0xC0 - 0x88];
    f32 xc0[3];
    u8 padcc[0x110 - 0xCC];
    f32 x110;
    u8 pad114[0x160 - 0x114];
    f32 x160;
    u8 pad164[0x19A - 0x164];
    s16 x19a;
    u8 pad19c[0x204 - 0x19C];
} SysMove;
/* lbl_80309EC8: the 0x244-byte battle/system block (memset in battle.c). */
typedef struct Sys_80309EC8 {
    u8 pad_0[0x40];
    SysObj* x40;
    SysObj* x44;
    u32 x48;
    NJS_POINT3 x4c;     /* 0x4c eye */
    NJS_POINT3 x58;     /* 0x58 target */
    s32 x64[3];         /* 0x64 angles */
    f32 va[3];
    f32 vb[3];
    SysMove mv;         /* 0x88 */
    s8 a[10];
    u8 pad20e[2];
    u32 w[10];
    s8 b[10];
    u8 pad242[2];
} Sys_80309EC8;
extern Sys_80309EC8 lbl_80309EC8;
extern void fn_800614FC(void *p, void *v);
extern void fn_80071CF0(void *p, void *v);
extern void *fn_80021658(s8 idx);
extern s32 fn_800179E4(s16);
typedef struct {
    s8 id;
    u8 pad1[0x44 - 1];
    u32 x44;
    u8 pad48[0x50 - 0x48];
    u32 x50;
    u8 pad54[0x1dc - 0x54];
    void* x1dc;
} Unit_80016580;
typedef struct {
    u8 pad[0x4c];
    Unit_80016580* w;
} UW_80016580;
typedef struct Tk_80016580 {
    u8 pad0[0x18];
    u8 flags;
    u8 state;
    u8 pad1a[0x24 - 0x1a];
    union {
        void* v;
        UW_80016580* uw;
    } work;
} Tk_80016580;
int fn_80016A18(s8 mode);
extern void fn_80032B4C(void);
extern u32 fn_800153E0(s32, s16);
extern s16 fn_80009030(Ent_80008800* list, s16 p1, s16 p2, s16 c, s16 d);
extern void fn_800120D0(s32*);
extern s8 lbl_80347334;
extern int fn_80078610(u8);
extern void fn_80290EA8(int);
extern void fn_80290E98(u32);
/* The camera task's state block (its work's x6c). */
typedef struct CamState {
    s8 mode;            /* 0x00 camera mode */
    s8 prev;            /* 0x01 previous mode */
    s16 x2;             /* 0x02 current character */
    s16 x4;             /* 0x04 second character */
    u8 pad6[2];
    f32 x8;
    f32 xc;
    u8 pad10[0x2c - 0x10];
    s16 x2c;
    u8 x2e;
    s8 x2f;             /* 0x2f camera kind */
    s16 state;          /* 0x30 */
    u8 pad32[2];
    u32 x34;
} CamState;
/* The camera task's work: eye at 0x20, angles at 0x2c, target at 0x38. */
typedef struct CamWork {
    u8 pad0[0x20];
    f32 x20[3];
    f32 x2c[3];
    f32 x38[3];
    u8 pad44[0x68 - 0x44];
    u32 x68;            /* 0x68 flags */
    CamState* u;        /* 0x6c */
} CamWork;
extern int fn_8006D1C4(void);
f32 fn_800114AC(f32* out, f32* w, f32* h, s8 flag);
extern void fn_800608C8(void*);
extern void fn_80061C80(void*, f32, f32, f32, int);
extern void fn_80071F84(void*, void*, void*);
void fn_80014AB8(u8 kind, SysObj* o);
extern f32 fn_8006116C(int);
extern int fn_80061F58(void*, int, int);
#define FLD(p, off, T) (*(T*)((u8*)(p) + (off)))
s8 fn_80020E10(void* p);
void fn_80012130(void* p);
Task* fn_800215EC(s8 id);
typedef s32 Angle;
extern s32 fn_8006EDA0(void);
s32 fn_80011400(s16 id, s8 val);
extern void fn_8005535C(void *a, void *v, void *t, f32 x);
extern void fn_80011208(s8 a, s8 b, s32 c);
extern s32 rand(void);
/* lbl_80309E24: the character task table (void* in unit_80005B50.c). */
extern Task* lbl_80309E24[];
extern f32 fn_80071E9C(void*, void*);
typedef struct V5BF30 { f32 x, y, z; } V5BF30;
extern void* memset(void* dst, int c, u32 n);
typedef struct {
    u8 pad0[0x48];
    u32 x48;
    u8 x4c[12];
    u8 x58[12];
    u8 x64[12];
} G;
typedef struct {
    u16 x0;
    u8 pad2[0x2a];
} Sys;
typedef struct {
    u8 pad0[0x190];
    u32 x190;
} Gs;
extern void fn_80012100(void* a);
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
extern void fn_80053F38(s8, s32);

extern void fn_80011208(s8 a, s8 b, s32 c);
extern s32 fn_8025ECC4(void);

void fn_80011208(s8 a, s8 b, s32 c) {
    s8 m;
    f32 d;
    f32 r;
    f32 t;
    f32 v;
    f32 n;
    NJS_POINT3 tmp;
    s8 i;
    fn_80071CF0(&lbl_80309EC8.x4c, &tmp);
    m = c;
    for (i = 0; i < 13; i++) {
        Task* u = lbl_80309E24[i];
        ChrWork* q;
        ChrInfo* chr;
        if (u == 0) {
            continue;
        }
        q = u->work;
        chr = q->st;
        if (chr->xf0 & 0x80000000) {
            continue;
        }
        if (chr->id == a) {
            continue;
        }
        if (chr->id == b) {
            continue;
        }
        tmp.y = q->pos.y;
        d = fn_80071E9C(&tmp, &q->pos);
        r = 7.5f;
        if (chr->xec & 0x200000) {
            r *= 3.0f;
        } else {
            r *= 1.5f;
        }
        d -= r;
        if (d < 0.0f) {
            d = 0.0f;
        }
        d = d / 7.5f;
        t = 1.0f - d;
        n = -t;
        if (n < 0.0f) {
            v = chr->draw.a;
            if (v > 3.0f * n) {
                v = 3.0f * n;
            }
            if (v < -1.0f) {
                v = -1.0f;
            }
        } else {
            v = 0.0f;
        }
        if (m != 1) {
            chr->draw.a = v;
        } else if (chr->draw.a > v) {
            chr->draw.a = v;
        }
    }
}

void fn_80011370(s8 a, s8 b)
{
    fn_80011208(a, b, 0);
}


s32 fn_80016B20(s8 kind);
void fn_80014D0C(void);
void fn_80014CFC(void);
void fn_800152A0(void);
extern void SoundLoadStageSamp(void);
extern Task* fn_8003DB34(void* fn);
void fn_80016580(Tk_80016580* t);

inline int HitCached(CamWork* w, CamState* u, f32 xc)
{
    switch (lbl_80309EC8.mv.x19a) {
    case 10:
    case 11:
        if (lbl_80309EC8.mv.x110 == xc && lbl_80309EC8.mv.xc0[0] == w->x38[0] && lbl_80309EC8.mv.xc0[1] == w->x38[1]
            && lbl_80309EC8.mv.xc0[2] == w->x38[2]) {
            u->x8 = lbl_80309EC8.mv.x160;
            return 1;
        }
    }
    return 0;
}

inline void ResetChrs(int idle)
{
    Task** p;
    s8 i;
    for (i = 0, p = lbl_80309E24; i < 14; p++, i++) {
        if (*p != NULL) {
            ChrWork* w = (*p)->work;
            ChrInfo* o = w->st;
            if (!idle || !(o->xf0 & 0x80000000)) {
                o->draw.a = 0.0f;
                o->x1ec |= 0x20000000;
            }
        }
    }
}

extern s32 fn_8025ECC4(void);
s32 fn_800117EC(NJS_POINT3* a, NJS_POINT3* b, f32* out, NJS_POINT3* c);

s32 fn_80011400(s16 id, s8 val)
{
    Task* t;
    ChrWork* w;
    ChrInfo* c;
    t = fn_800215EC(id);
    if (t == NULL) {
        return 0;
    }
    w = t->work;
    c = w->st;
    if (c->x50 & 0x40000) {
        return 0;
    }
    if (c->xf0 & 0x80000000) {
        if (val != 0) {
            c->draw.a = 0.0f;
            c->x1ec |= 0x20000000;
            return 0;
        }
        return 0;
    }
    c->draw.a = 0.0f;
    c->x1ec |= 0x20000000;
    return 1;
}

f32 fn_800114AC(f32* out, f32* w, f32* h, s8 flag) {
    f32 v[3];
    f32 maxx = -500.0f;
    f32 minx = 500.0f;
    f32 maxz = maxx;
    f32 top = 0.0f;
    f32 minz = minx;
    f32 r;
    f32 dx, dz;
    Task* t;
    ChrInfo* c;
    ChrWork* o;
    s16 i;
    for (i = 0; i < 12; i++) {
        t = lbl_80309E24[i];
        if (t == 0) {
            continue;
        }
        o = t->work;
        c = o->st;
        if ((c->xec & 0x100) && fn_80020E10(o->x10->xc) < 0) {
            continue;
        }
        o = t->work;
        if (flag == 0) {
            fn_80071CF0(&o->pos, v);
        } else {
            fn_80071CF0(&c->x13c, v);
        }
        if (c->xec & 0x200000) {
            r = 22.5f;
        } else {
            r = 7.5f;
        }
        if (v[0] + r > maxx) {
            maxx = v[0] + r;
        }
        if (v[0] - r < minx) {
            minx = v[0] - r;
        }
        if (v[2] + r > maxz) {
            maxz = v[2] + r;
        }
        if (v[2] - r < minz) {
            minz = v[2] - r;
        }
        if (top < c->x15c) {
            top = c->x15c;
        }
    }
    dx = maxx - minx;
    if (dx < 0.0f) {
        dx = -1.0f * dx;
    }
    dz = maxz - minz;
    if (dz < 0.0f) {
        dz = -1.0f * dz;
    }
    dx *= 0.5f;
    dz *= 0.5f;
    *w = dx;
    *h = dz;
    out[0] = minx + dx;
    out[2] = minz + dz;
    out[1] = 0.0f;
    return top;
}

f32 fn_80011694(NJS_POINT3* mtx, s16 id, NJS_POINT3* v, s8* out) {
    f32 sum = 0.0f;
    f32 best = 0.0f;
    s8 i;
    ChrWork* q;
    ChrInfo* chr;
    f32 d;
    f32 r;
    *out = -1;
    for (i = 0; i < 12; i++) {
        if (lbl_80309E24[i] != 0) {
            q = lbl_80309E24[i]->work;
            chr = q->st;
            if (!(chr->xf0 & 0x80000000) && chr->id != id && fn_800117EC(mtx, &q->pos, &d, v) != 0) {
                r = 7.5f;
                if (chr->xec & 0x200000) {
                    r *= 3.0f;
                }
                d -= r;
                sum += d;
                if (best <= chr->x15c) {
                    *out = chr->id;
                    best = chr->x15c;
                }
            }
        }
    }
    if (sum == 0.0f) {
        return 5000.0f + 0.000030517578f * fn_8025ECC4();
    }
    return sum;
}

/* A line through o with direction d (fn_8028FEA4). */
typedef struct Line3 {
    NJS_POINT3 o;
    NJS_POINT3 d;
} Line3;
extern void fn_80071B98(NJS_POINT3* a, NJS_POINT3* b, NJS_POINT3* out);
extern f32 fn_8028FEA4(NJS_POINT3* p, Line3* l, NJS_POINT3* out);

s32 fn_800117EC(NJS_POINT3* a, NJS_POINT3* b, f32* out, NJS_POINT3* c) {
    Line3 l;
    NJS_POINT3 pt;
    NJS_POINT3 cl;
    NJS_POINT3 p;
    NJS_POINT3 t;
    s32 rb[3];
    s32 ra[3];
    f32 dist;
    f32 d1;
    f32 d2;
    f32 diff;
    if (c != 0) {
        fn_80071CF0(c, &p);
    } else {
        fn_80071CF0(&lbl_80309EC8.x4c, &p);
    }
    p.y = a->y;
    l.o.x = p.x;
    l.o.y = p.y;
    l.o.z = p.z;
    fn_80071B98(&p, a, &t);
    l.d.x = t.x;
    l.d.y = t.y;
    l.d.z = t.z;
    pt.x = b->x;
    pt.y = b->y;
    pt.z = b->z;
    dist = fn_8028FEA4(&pt, &l, &cl);
    d1 = fn_80071E9C(&p, b);
    d2 = fn_80071E9C(&p, a);
    if (d1 <= d2) {
        fn_80071F84(rb, b, &p);
        fn_80071F84(ra, a, &p);
        d1 = fn_8006116C(rb[1]);
        diff = d1 - fn_8006116C(ra[1]);
        if (diff < 0.0f) {
            diff = -1.0f * diff;
        }
        if (diff < 45.0f) {
            *out = dist;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
    return 1;
}

s32 fn_80011E50(f32* v, f32* out, u8 mode) {
    f32 pos[3];
    f32 c58[3];
    f32 tmp[3];
    f32 ang[3];
    f32 d;
    fn_80071CF0(&lbl_80309EC8.x4c, pos);
    fn_800614FC(lbl_80309EC8.x64, ang);
    fn_80071CF0(&lbl_80309EC8.x58, c58);
    fn_80071CF0(v, tmp);
    switch (mode) {
    case 0:
        tmp[2] = pos[2];
        if (v[0] < 0.0f && pos[0] <= v[0]) {
            *out = -1.0f;
            return 1;
        }
        if (v[0] > 0.0f && pos[0] >= v[0]) {
            *out = -1.0f;
            return 1;
        }
        break;
    case 1:
        tmp[0] = pos[0];
        if (v[2] < 0.0f && pos[2] <= v[2]) {
            *out = -1.0f;
            return 1;
        }
        if (v[2] > 0.0f && pos[2] >= v[2]) {
            *out = -1.0f;
            return 1;
        }
        break;
    }
    tmp[1] = pos[1];
    d = fn_80071E9C(pos, tmp) - 7.5f;
    if (d < 0.0f) {
        d = 0.0001f;
    }
    d = d / 7.5f;
    d = -(1.0f - d);
    if (d < 0.0001f) {
        *out = 3.0f * d;
        return 1;
    }
    return 0;
}

void fn_800121D8(Task* t)
{
    CamWork* w = t->work;
    CamState* u = w->u;
    f32 b, a;
    f32 v[3];
    Task** p;
    s8 i;
    f32 c, d;

    switch (u->state) {
    case 0:
        if (lbl_8030A10C.x6c & 0x20000) {
            return;
        }
        fn_80014AB8(2, 0);
        fn_800114AC(v, &a, &b, 0);
        if (a > b) {
            u->xc = a;
        } else {
            u->xc = b;
        }
        u->xc = 2.0f * u->xc;
        v[1] = 0.0f;
        fn_80071CF0(v, w->x38);
        if (!HitCached(w, u, u->xc)) {
            fn_800608C8(&u->x8);
        }
        u->state = 1;
        break;
    case 1:
        fn_80014D0C();
        fn_80032B4C();
        if (fn_80016B20(2) || fn_80016A18(2)) {
            u->state = 4;
        } else {
            fn_800152A0();
            u->state = 6;
        }
        break;
    case 2:
        ResetChrs(1);
        break;
    case 3:
        fn_80011208(-1, -1, 0);
        break;
    case 4:
        if (!(lbl_8030A10C.x6c & 0x80000000)) {
            if (lbl_8030A10C.x6c & 0x200) {
                return;
            }
            SoundLoadStageSamp();
            u->state = 5;
        }
        break;
    case 5:
        if (!(lbl_8030A10C.x6c & 0x80000000)) {
            fn_80061F58(&fn_8003DB34(fn_80016580)->work, 8, 0);
            u->state = 2;
        }
        break;
    case 6:
        if (!(lbl_8030A10C.x6c & 0x80000000)) {
            SoundLoadStageSamp();
            u->state = 7;
        }
        break;
    case 7:
        if (!(lbl_8030A10C.x6c & 0x80000000)) {
            fn_80014CFC();
            u->state = 3;
        }
        break;
    }
    ResetChrs(0);
    switch (u->state) {
    case 3:
    case 6:
    case 7:
        return;
    }
    d = u->xc;
    c = u->x8;
    lbl_80309EC8.mv.x19a = 11;
    lbl_80309EC8.mv.x110 = d;
    fn_80071CF0(w->x38, lbl_80309EC8.mv.xc0);
    lbl_80309EC8.mv.x160 = c;
    c = u->xc;
    fn_80061C80(w->x20, 0.0f, u->x8, c, 0);
    w->x20[0] = w->x20[0] + w->x38[0];
    w->x20[2] = w->x20[2] + w->x38[2];
    w->x20[1] = c;
    fn_80071F84(w->x2c, w->x38, w->x20);
    u->x8 += 1.0f;
}

void fn_80013504(Vec3* obj, Vec3* src, void* p5, f32 a, f32 b) {
    fn_80061C80(obj, 0.0f, b, a, 0);
    obj->x = obj->x + src->x;
    obj->z = obj->z + src->z;
    obj->y = a;
    fn_80071F84(p5, src, obj);
}

extern void fn_80032BBC(s8, s32);
extern void fn_80032B6C(s8, s32);
extern Task* fn_8003DB34(void* fn);

extern Task* fn_800215EC(s8);
extern void fn_80032BBC(s8, s32);

void fn_800120D0(s32 *a)
{
    fn_800614FC(lbl_80309EC8.x64, a);
}

void fn_80012100(void *a)
{
    fn_80071CF0(&lbl_80309EC8.x58, a);
}

s32 fn_80012F24(s32 idx)
{
    u8 *p = (u8 *)fn_80021658((s8)idx);
    u8 *q = *(u8 **)(p + 0x24);
    u8 *r = *(u8 **)(q + 0x4c);
    u32 v = *(u32 *)(r + 0xec);
    return (v >> 21) & 1;
}

void fn_80012020(f32 *v)
{
    f32 x;
    x = v[0];
    if (x) lbl_80309EC8.vb[0] = x;
    x = v[1];
    if (x) lbl_80309EC8.vb[1] = x;
    x = v[2];
    if (x) lbl_80309EC8.vb[2] = x;
}

void fn_80013D58(s8 id, s8 flag)
{
    s8 i;
    s8 j;
    s8 k;

    if (flag != 0) {
        for (i = 0; i < 10; i++) {
            if (lbl_80309EC8.a[i] == 0) {
                k = i;
                break;
            }
        }
        if (i == 10) {
            for (j = 0; j < 9; j++) {
                lbl_80309EC8.a[j] = lbl_80309EC8.a[j + 1];
                lbl_80309EC8.w[j] = lbl_80309EC8.w[j + 1];
                lbl_80309EC8.b[j] = lbl_80309EC8.b[j + 1];
            }
            k = j;
        }
        lbl_80309EC8.a[k] = id;
        lbl_80309EC8.w[k] = lbl_80309EC8.x48;
        lbl_80309EC8.b[k] = lbl_80347334;
        if (k != 0 && id == 7) {
            if (fn_80078610(lbl_80309EC8.b[k]) == 0 || fn_800179E4(lbl_80309EC8.b[k]) == 0) {
                if (lbl_80309EC8.a[k - 1] == 8 && (lbl_80309EC8.w[k - 1] & 0x8000000)) {
                    lbl_80309EC8.x48 |= 0x8000000;
                    lbl_80309EC8.w[k] |= 0x4000000;
                }
            }
        }
    } else {
        fn_80290EA8(8);
        for (i = 0; i < 10; i++) {
            if (lbl_80309EC8.a[i] > 11 || lbl_80309EC8.a[i] < 0) {
                lbl_80309EC8.a[i] = 12;
            }
            switch (lbl_80309EC8.a[i]) {
            case 11:
                fn_80290E98(0x8080FFFF);
                break;
            default:
                if (lbl_80309EC8.w[i] & 0x4000000) {
                    fn_80290E98(0xFF80FFFF);
                } else {
                    fn_80290E98(-1);
                }
                break;
            }
        }
    }
}

inline int Hit(CamWork* w, CamState* u, f32 xc)
{
    switch (lbl_80309EC8.mv.x19a) {
    case 10:
    case 11:
        if (lbl_80309EC8.mv.x110 == xc && lbl_80309EC8.mv.xc0[0] == w->x38[0] && lbl_80309EC8.mv.xc0[1] == w->x38[1]
            && lbl_80309EC8.mv.xc0[2] == w->x38[2]) {
            u->x8 = lbl_80309EC8.mv.x160;
            return 1;
        }
    }
    return 0;
}

inline void Reset(void)
{
    Task** p;
    s8 i;
    for (i = 0, p = lbl_80309E24; i < 14; p++, i++) {
        if (*p != NULL) {
            ChrWork* cw = (*p)->work;
            ChrInfo* o = cw->st;
            o->draw.a = 0.0f;
            o->x1ec |= 0x20000000;
        }
    }
    fn_80011208(-1, -1, 0);
}

void fn_80014474(Task* t)
{
    CamWork* w = t->work;
    CamState* u = w->u;
    f32 b, a;
    f32 v[3];
    f32 c;
    f32 d;

    switch (u->state) {
    case 0:
        if (lbl_80309EC8.x48 & 0x8000000) {
            lbl_80309EC8.x48 &= ~0x8000000;
            u->state = 2;
            break;
        }
        if (fn_8006D1C4()) {
            fn_800114AC(v, &a, &b, 0);
            if (a > b) {
                u->xc = a;
            } else {
                u->xc = b;
            }
            u->xc = 2.0f * u->xc;
            v[1] = 0.0f;
            fn_80071CF0(v, w->x38);
            if (!Hit(w, u, u->xc)) {
                fn_800608C8(&u->x8);
            }
            c = u->xc;
            fn_80061C80(w->x20, 0.0f, u->x8, c, 0);
            w->x20[0] = w->x20[0] + w->x38[0];
            w->x20[2] = w->x20[2] + w->x38[2];
            w->x20[1] = c;
            fn_80071F84(w->x2c, w->x38, w->x20);
            fn_80014AB8(2, 0);
            u->state = 1;
        } else {
            fn_80071CF0(&lbl_80309EC8.x4c, w->x20);
            fn_80071CF0(&lbl_80309EC8.x58, w->x38);
            fn_800614FC(lbl_80309EC8.x64, w->x2c);
            break;
        }
    case 1:
        Reset();
        d = u->xc;
        c = u->x8;
        lbl_80309EC8.mv.x19a = 11;
        lbl_80309EC8.mv.x110 = d;
        fn_80071CF0(w->x38, lbl_80309EC8.mv.xc0);
        lbl_80309EC8.mv.x160 = c;
        break;
    case 2:
        Reset();
        break;
    }
}

s32 fn_80012160(void) {
    if (lbl_80347394 != 0) {
        return -1;
    }
    switch (lbl_8034733C) {
    case 0:
        return 1;
    case 1:
        return 2;
    case 2:
        return 5;
    case 3:
        return 4;
    case 4:
        return 7;
    case 5:
        return 8;
    case 6:
        return 9;
    case 7:
    case 8:
    default:
        return -1;
    }
}

void fn_80012130(void* p) {
    fn_80071CF0(&lbl_80309EC8.x4c, p);
}

f32 fn_8001359C(Vec3* obj, f32* out) {
    f32 b;
    f32 a;
    f32 v[3];
    f32 r;

    r = fn_800114AC(v, &a, &b, 1);
    if (a > b) {
        *out = a;
    } else {
        *out = b;
    }
    *out = 2.0f * *out;
    v[1] = 0.0f;
    fn_80071CF0(v, obj);
    return r;
}

f32 fn_8001363C(Vec3* obj, f32* out) {
    f32 b;
    f32 a;
    f32 v[3];
    f32 r;

    r = fn_800114AC(v, &a, &b, 0);
    if (a > b) {
        *out = a;
    } else {
        *out = b;
    }
    *out = 2.0f * *out;
    v[1] = 0.0f;
    fn_80071CF0(v, obj);
    return r;
}

void fn_800143A0(Task *t)
{
    CamWork *w = t->work;
    CamState *sub = w->u;
    void *e;
    s32 idx;

    switch (sub->state) {
    case 0:
        idx = fn_8006EDA0();
        if (idx < 0) {
            idx = 0;
        }
        fn_80014AB8(2, NULL);
        e = fn_80021658(idx);
        fn_80032B4C();
        fn_80011400(idx, 1);
        fn_8005535C(w->x20, w->x38, e, 0.0f);
        fn_80071F84(w->x2c, w->x38, w->x20);
        sub->state = 1;
    case 1:
        fn_80011208(-1, -1, 0);
        break;
    }
}

void fn_80011394(s8 sel) {
    s8 i;

    for (i = 0; i < 0xe; i++) {
        Task* n = lbl_80309E24[i];
        if (n != 0) {
            ChrWork* w = n->work;
            ChrInfo* m = w->st;
            if ((!(m->xf0 & 0x80000000) && sel == 0) || sel != 0) {
                m->draw.a = 0.0f;
                m->x1ec |= 0x20000000;
            }
        }
    }
}

/* Copies each non-zero component of v into lbl_80309EC8.va (the float test is `if (x)`,
 * which compares x against 0.0f in the order the original has; `x != 0.0f` swaps fcmpu). */
void fn_80012078(V5BF30* v) {
    if (v->x) {
        lbl_80309EC8.va[0] = v->x;
    }
    if (v->y) {
        lbl_80309EC8.va[1] = v->y;
    }
    if (v->z) {
        lbl_80309EC8.va[2] = v->z;
    }
}

void fn_80013FD0(Task* t)
{
    CamWork* w = t->work;
    CamState* u = w->u;

    if (u->state != 0) {
        if ((*(G*)&lbl_80309EC8).x48 & 0x80000000) {
            (*(G*)&lbl_80309EC8).x48 &= ~0x80000000;
            u->state = 6;
        }
        if ((*(G*)&lbl_80309EC8).x48 & 0x40000000) {
            u->state = 7;
        }
    }
    switch (u->state) {
    case 0:
        switch ((*(Sys*)&lbl_80309E5C).x0) {
        default:
            if (rand() % 2 != 0) {
                u->state = 1;
            } else {
                u->state = 3;
            }
            break;
        case 1:
        case 3:
            u->state = 1;
            break;
        case 2:
            u->state = 3;
            break;
        }
        if ((*(Gs*)&lbl_8030A10C).x190 != 0) {
            u->xc = 1.25f;
        } else {
            u->xc = 1.0f;
        }
        break;
    case 1:
        fn_80061C80(w->x20, 0.1f, u->x8, 110.0f, 0);
        w->x20[1] = 80.0f;
        w->x38[0] = 0.0f;
        w->x38[1] = 60.0f + w->x20[1];
        w->x38[2] = 0.0f;
        u->state = 2;
        u->x34 = 0;
        if (rand() % 2 != 0) {
            u->x34 |= 1;
        }
        break;
    case 2:
        if (u->x34 & 1) {
            u->x8 += 1.5f * u->xc;
        } else {
            u->x8 -= 1.5f * u->xc;
        }
        fn_80061C80(w->x20, 0.1f, u->x8, 110.0f, 0);
        w->x20[1] = 80.0f;
        w->x38[1] -= u->xc;
        if (w->x38[1] < 0.0f) {
            w->x38[1] = 0.0f;
        }
        break;
    case 3:
        u->x2c = 0;
        fn_80061C80(w->x20, 0.1f, u->x8, u->x2c, 0);
        w->x20[1] = 80.0f;
        memset(w->x38, 0, 12);
        u->state = 4;
        u->x34 = 0;
        if (rand() % 2 != 0) {
            u->x34 |= 1;
        }
        break;
    case 4:
        if (u->x34 & 1) {
            u->x8 += 1.5f * u->xc;
        } else {
            u->x8 -= 1.5f * u->xc;
        }
        fn_80061C80(w->x20, 0.1f, u->x8, u->x2c * u->xc, 0);
        w->x20[1] = 80.0f;
        u->x2c++;
        if (u->x2c * u->xc > 110.0f) {
            u->x2c--;
        }
        break;
    case 7:
        fn_80071CF0((void *)((*(G*)&lbl_80309EC8).x4c), (void *)(w->x20));
        fn_80071CF0((void *)((*(G*)&lbl_80309EC8).x58), (void *)(w->x38));
        fn_800614FC((void *)((*(G*)&lbl_80309EC8).x64), (void *)(w->x2c));
        break;
    }
    fn_80071F84(w->x2c, w->x38, w->x20);
    fn_80032B4C();
}

void fn_80011160(s8* ids)
{
    s8 i;
    s8 j;
    ChrInfo* u;
    Task* t;

    for (i = 0; i < 12; i++) {
        t = fn_800215EC(i);
        if (t != NULL) {
            u = ((ChrWork*)t->work)->st;
            for (j = 0; j < 12; j++) {
                if (u->id == ids[j]) {
                    break;
                }
            }
            if (j == 12) {
                u->draw.a = 0.0f;
            }
        }
    }
}

/* The work of a character task. */



void fn_80012F58(Task* t)
{
    CamWork* w = t->work;
    CamState* u = w->u;
    Task* c;
    ChrInfo* st;
    s8 kind;
    s16 cur;
    s16 other;
    s16 r;

    r = fn_8001D41C(&cur, &other);
    if (cur != u->x2) {
        if (r) {
            u->state = 2;
        } else {
            u->state = 0;
        }
    }
    c = fn_80021658(cur);
    st = ChrW(c)->st;
    switch (st->x6) {
    case 6:
        kind = 0;
        break;
    case 4:
    case 8:
    case 9:
        kind = 2;
        break;
    case 5:
    case 10:
        kind = 3;
        break;
    case 2:
    case 7:
    case 12:
        kind = 4;
        break;
    case 29:
        if (fn_800153E0(0x1d, st->x8)) {
            kind = 1;
        } else {
            kind = 5;
        }
        break;
    default:
        kind = 1;
        break;
    }
    if (kind != u->x2f) {
        switch (st->x6) {
        case 30:
            switch (st->x8) {
            case 0x24:
            case 0x25:
                if (u->x2 != cur) {
                    u->state = 0;
                }
                break;
            }
            break;
        case 2:
        case 7:
        case 11:
            if (u->x2 != cur) {
                u->state = 0;
            }
            break;
        default:
            u->state = 0;
            break;
        }
    }
    switch (u->state) {
    case 0:
        u->x2f = kind;
        fn_80032B4C();
        ResetChrs(1);
        fn_80032B6C(cur, 1);
        fn_80032B6C(other, 1);
        if (u->x2 != cur) {
            fn_80053F38(cur, 1);
        }
        u->state = 1;
    case 1:
        if (!(st->xf0 & 0x02000000)) {
            u->state = 2;
        }
        break;
    }
    kind = u->x2f;
    u->x2 = cur;
    u->x4 = other;
    switch (kind) {
    case 0:
    case 4:
        switch (u->state) {
        case 2:
            fn_80053F38(cur, 0);
            u->state = 3;
            break;
        case 3:
            fn_80071CF0(&lbl_80309EC8.x4c, w->x20);
            fn_80071CF0(&lbl_80309EC8.x58, w->x38);
            fn_800614FC(lbl_80309EC8.x64, w->x2c);
            break;
        }
        break;
    case 1:
        switch (u->state) {
        case 2:
            u->state = 3;
            fn_80032BBC(cur, 0);
            break;
        case 3:
            fn_80071CF0(&lbl_80309EC8.x4c, w->x20);
            fn_80071CF0(&lbl_80309EC8.x58, w->x38);
            fn_800614FC(lbl_80309EC8.x64, w->x2c);
            break;
        }
        break;
    case 2:
        switch (u->state) {
        case 2:
            if (!fn_80009030(ChrW(c)->x10->x30, 4, -1, 0x2a, 3)) {
                fn_80053F38(cur, 0);
            }
            u->state = 3;
            break;
        case 3:
            fn_80071CF0(&lbl_80309EC8.x4c, w->x20);
            fn_80071CF0(&lbl_80309EC8.x58, w->x38);
            fn_800614FC(lbl_80309EC8.x64, w->x2c);
            break;
        }
        fn_80032BBC(cur, 1);
        break;
    case 3:
        switch (u->state) {
        case 2:
            if (!fn_80009030(ChrW(c)->x10->x30, 5, -1, 0x2a, 3)) {
                fn_80053F38(cur, 0);
            }
            u->state = 3;
            break;
        case 3:
            fn_80071CF0(&lbl_80309EC8.x4c, w->x20);
            fn_80071CF0(&lbl_80309EC8.x58, w->x38);
            fn_800614FC(lbl_80309EC8.x64, w->x2c);
            break;
        }
        break;
    case 5:
        switch (u->state) {
        case 2:
            if (fn_80009030(ChrW(c)->x10->x30, st->x6, st->x8, 0x2e, 3)) {
                u->state = 4;
                break;
            }
            u->state = 3;
        case 3:
            fn_80032BBC(cur, 0);
        case 4:
            fn_80071CF0(&lbl_80309EC8.x4c, w->x20);
            fn_80071CF0(&lbl_80309EC8.x58, w->x38);
            fn_800614FC(lbl_80309EC8.x64, w->x2c);
            break;
        }
        break;
    }
}

s32 fn_80011984(AnimPlay* a) {
    s32 ret;
    Key16* k;
    u32 fr;
    f32 t;
    Track* trk;
    Key16* keys;
    ret = 0;
    a->end = a->anim->length;
    a->time = a->time + a->speed;
    if (a->time >= (f32)a->end) {
        return 1;
    }
    trk = a->anim->track;
    keys = trk->keys;
    while (trk->count > a->idx) {
        k = &keys[a->idx];
        fr = k->frame;
        t = a->time;
        if (t == (f32)fr) {
            fn_80071CF0(k->v, a->out);
            break;
        }
        if ((f32)fr > t) {
            f32 dx = k->v[0] - k[-1].v[0];
            f32 dy = k->v[1] - k[-1].v[1];
            f32 dz = k->v[2] - k[-1].v[2];
            a->out[0] = k[-1].v[0] + dx * t / (f32)fr;
            a->out[1] = (&keys[a->idx])[-1].v[1] + dy * a->time / (f32)keys[a->idx].frame;
            a->out[2] = (&keys[a->idx])[-1].v[2] + dz * a->time / (f32)keys[a->idx].frame;
            break;
        }
        ret = 2;
        a->idx++;
    }
    return ret;
}

/* NEAR (20 lines): params land in other callee-saved registers (orig b r31, d r30, a r29, c r28). */
