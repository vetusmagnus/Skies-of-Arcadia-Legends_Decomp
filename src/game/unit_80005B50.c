#include "types.h"
#include "ninja.h"
#include "game/drawstate.h"
#define PTR(p, off) (*(void**)((u8*)(p) + (off)))
extern void* fn_80005B9C(void* heap);
extern void* memset(void* dst, s32 c, u32 n);
extern void fn_800090F8(s32 packed, s16* p);
extern void* lbl_803475A8;
extern void* fn_802268E8(void* a, void (*cb)(void*));
extern void* fn_801E1C7C(u32 size);
extern void fn_8000A3FC(void* p);
extern u32 lbl_803474E4[2];
extern void* lbl_80346AA0;
extern void fn_801DDCA8(void* p);
extern void fn_802275A4(void* a, s32 b);
extern void fn_801E17E0(void* p);
extern void* fn_801DB1A4(u32 size);
extern void fn_80227810(void* p);
extern void fn_801DDD74(void* p, s32 n);
typedef struct Vec3 {
    f32 x;
    f32 y;
    f32 z;
} Vec3;
extern f32 fn_80291A5C(f32 v);
extern u32 lbl_80309E5C[];
extern void* lbl_80347394;
extern void* lbl_80309DE4[];
extern s32 fn_8000F718(void* p, s32 a, s32 b);
extern void fn_8000F6F8(void* obj, s32 a, s32 b, s32 c, s32 d);
typedef struct Entry16 {
    u8 pad[8];
    s8 mode;
    u8 pad2[7];
} Entry16;
extern Entry16 lbl_80309730[];
extern s32 lbl_8034733C;
typedef struct Pair {
    u32 a;
    u32 b;
} Pair;
extern void* lbl_80309E24[];
extern void fn_8028AB48(void);
extern void fn_802A9B94(s32 a, s32 b, s32 c, void (*f)(void));
extern u32 lbl_803478A0;
extern u32 lbl_803478A4;
extern u8 *lbl_803478DC;
extern void fn_8000832C(s32 a, s32 b, s32 c);
extern void fn_800086BC(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
extern u8 lbl_8030A10C[];
typedef struct {
    s16 id;
    s16 pad;
    void *ptr;
} Ent_80009860;
extern u8 *lbl_80346AA4;
extern u32 lbl_802DAFA8[];
extern u8 lbl_8030B7F4[];
extern u8 lbl_80309EC8[];
extern void fn_800614FC(void *p, s32 v);
extern void fn_80071CF0(void *p, s32 v);
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
typedef struct Ent_80020060 { s16 x0; s16 x2; u8 pad[0x14]; } Ent_80020060;
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
typedef struct { s16 id; } Wk;
typedef struct { u8 pad[0x24]; Wk* work; } Tk;
/* lbl_803097F0 (.bss, 0xD8 bytes): s16 header (x0 read as a state id in battle.c),
   then 12 per-character 16-byte entries from 0x18. */
typedef struct { f32 x0; f32 x4; f32 x8; f32 xc; } Ent;
typedef struct { s16 x0; u8 pad[0x16]; Ent ent[12]; } Tbl;
extern Tbl lbl_803097F0;
typedef struct {
    u8 pad[0x70];
    f32 a[3];
    f32 b[3];
} State_80309EC8;
/* lbl_80309730: 12 rows of 16 bytes, one per character slot; +0x8 is the slot mode
 * (0 = unused, see fn_80010538). */
typedef struct Entry16B {
    u8 pad[8];
    s8 mode;
    u8 pad2[7];
} Entry16B;
typedef struct Work {
    s8 idx; /* 0x00: slot index */
} Work;
typedef struct Inner {
    u8 pad[0x4c];
    Work *work; /* 0x4C */
} Inner;
typedef struct Obj {
    u8 pad[0x24];
    Inner *inner; /* 0x24 */
} Obj;
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
    u8 pad10[8];
    s16 x18;
    u8 pad1a[0x44 - 0x1a];
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
typedef struct {
    u16 x0;
    u8 pad2[6];
    u32 x8;
    u8 padc[0x18 - 0xc];
    s32 x18;
    f32 x1c;
} G;
extern int fn_8000CCBC(Tk_8000E664*, int);
extern void fn_8000B77C(void*, void*);
extern void fn_80060950(void*);
extern int fn_80035908(void);
extern void fn_80035910(int);
extern void fn_8000F0BC(void);
extern void fn_80299040(void*);
extern void fn_8000B6F0(W*);
extern void fn_8000B5F4(W*, f32);
extern void fn_800D2048(void);
typedef struct {
    u8 pad0[0x19];
    u8 state;
    u8 pad1a[0x24 - 0x1a];
    W* work;
} Tk_8000EDE4;
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
typedef struct {
    s16 x0;
    u8 pad2[2];
    u32 x4;
} W_80016580;
typedef struct {
    u8 pad[0x1c];
    u32 x1c;
} Chr;
typedef struct {
    u8 pad0[0x1c4];
    s32 x1c4;
} GS;
typedef struct {
    u8 pad[0x44];
    u32 x44;
} U44;
extern int fn_80016A18(s8);
extern void fn_80015138(int);
extern void fn_80032B4C(void);
extern int fn_800168D8(int, void*, u8);
typedef struct {
    u8 pad0[0x5c];
    void* x5c;
    void* x60;
    u8 pad64[0x74 - 0x64];
    u8 x74[0x10];
    u8 x84[4];
    u8 pad88[0x154 - 0x88];
    void* x154;
    u8 pad158[0x264 - 0x158];
    f32 x264;
    f32 x268;
    f32 x26c;
    f32 x270;
    f32 x274;
    f32 x278;
    f32 x27c;
    s32 x280;
    s32 x284;
    s32 x288;
    u8 x28c;
} U_80018868;
typedef struct {
    void* x0;
    u8 pad4[0x4c - 4];
    U_80018868* u;
} W_80018868;
typedef struct {
    u8 pad[0x24];
    W_80018868* work;
} Tk_80018868;
extern u8 lbl_80346ABC;
extern u8 lbl_80346ABD;
extern void fn_8007E678(void*, void*);
extern void fn_8029D008(s32);
extern void njTranslate(void*, f32, f32, f32);
extern void njRotateX(void*, s32);
extern void njRotateY(void*, s32);
extern void njRotateZ(void*, s32);
extern void njScale(void*, f32, f32, f32);
extern void fn_80035468(void*, void*, void*, int, f32);
extern void fn_80035228(void*, void*, int, f32);
extern void fn_800353F4(void*, void*, void*, int, f32);
extern void fn_80035380(void*, void*, int, f32);
extern void fn_8003529C(void*, void*, int, f32);
typedef struct {
    s8 id;
    u8 pad1[5];
    s16 x6;
    s16 x8;
    u8 padA[0x10 - 0xA];
    s16 x10;
    u8 pad12[2];
    s16 x14;
    s16 x16;
    u8 pad18[0xec - 0x18];
    u32 xec;
    u8 padf0[0x20c - 0xf0];
    s16 x20c;
    s16 x20e;
} Unit_8001CED0;
typedef struct {
    u8 pad[0x3c];
    u32 x3c;
    u8 pad40[0x4c - 0x40];
    Unit_8001CED0* w;
} Wk_8001CED0;
typedef struct Tk_8001CED0 {
    u8 pad[0x24];
    Wk_8001CED0* work;
} Tk_8001CED0;
extern u32 fn_800153E0(s32, s16);
extern s16 fn_800760EC(Tk_8001CED0*, s16, s16);
extern s8 fn_8002EEFC(Tk_8001CED0*, u32*);
extern s8 fn_80030AE8(u32, Unit_8001CED0*);
extern s16 fn_80009030(void*, s16, s16, int, int);
extern void fn_800312F0(Tk_8001CED0*, s16, s16, s8);
extern void fn_80031254(Tk_8001CED0*);
typedef struct { u8 pad[0x10]; void* x10; } GS_8001CED0;

void* fn_80005B50(void* heap, u32 size) {
    void* p = fn_80005B9C(heap);
    if (p != 0) {
        memset(p, 0, size);
    }
    return p;
}

typedef struct {
    u32 keyframe;
    f32 key[3];
} NJS_MKEY_F;
typedef void (*MotionInterpFn)(void* keys, u32 i, u32 nbKeys, void* out);
typedef struct {
    void** mdata;  /* 0x00 current node's channel data */
    void** keys;   /* 0x04 key array pointers for the node */
    void** counts; /* 0x08 key counts for the node */
    f32 frame;     /* 0x0C */
    u32 nbFrame;   /* 0x10 */
    s32 unk14;
    f32* matrix;   /* 0x18 extra matrix applied after each node, or NULL */
    s32 unk1C;
} MotionState;
extern MotionState lbl_80316940;
void fn_800068C4(NJS_MKEY_F* keys, u32 i, u32 nbKeys, f32* out) {
    NJS_MKEY_F* k1 = &keys[i];
    f32 div[2] = {1.0f, 1.0f};
    NJS_MKEY_F* k0 = &keys[(i + nbKeys - 1) % nbKeys];
    NJS_MKEY_F* k2 = &keys[(i + 1) % nbKeys];
    NJS_MKEY_F* k3 = &keys[(i + 2) % nbKeys];
    f32 t, t2, t3;
    f32 c0, c1, c2, c3;

    div[1] = (f32)(k2->keyframe - k1->keyframe);
    t = (lbl_80316940.frame - (f32)k1->keyframe) / div[(s32)(k2->keyframe - k1->keyframe) > 0];
    t2 = t * t;
    t3 = t2 * t;
    c0 = 0.5f * (-t3 + 2.0f * t2 - t);
    c1 = 1.5f * t3 - 2.5f * t2 + 1.0f;
    c2 = -1.5f * t3 + 2.0f * t2 + 0.5f * t;
    c3 = 0.5f * (t3 - t2);
    out[0] = c0 * k0->key[0] + c1 * k1->key[0] + c2 * k2->key[0] + c3 * k3->key[0];
    out[1] = c0 * k0->key[1] + c1 * k1->key[1] + c2 * k2->key[1] + c3 * k3->key[1];
    out[2] = c0 * k0->key[2] + c1 * k1->key[2] + c2 * k2->key[2] + c3 * k3->key[2];
}

extern void fn_802A9338(s32 a, s32 b, s32 c, void (*f)(void));
typedef struct {
    u32 keyframe;
    Angle key[3];
} NJS_MKEY_A;
void fn_80006A70(NJS_MKEY_A* keys, u32 i, u32 nbKeys, Angle* out) {
    f32 div[2] = {1.0f, 1.0f};
    NJS_MKEY_A* k1 = &keys[i];
    NJS_MKEY_A* k2 = &keys[(i + 1) % nbKeys];
    f32 t;
    f32 u;

    div[1] = (f32)(k2->keyframe - k1->keyframe);
    t = (lbl_80316940.frame - (f32)k1->keyframe) / div[(s32)(k2->keyframe - k1->keyframe) > 0];
    u = 1.0f - t;
    out[0] = k1->key[0] * u + k2->key[0] * t;
    out[1] = k1->key[1] * u + k2->key[1] * t;
    out[2] = k1->key[2] * u + k2->key[2] * t;
}

void fn_800072A8(s32 a, s32 b, s32 c)
{
    fn_802A9338(a, b, c, fn_8028AB48);
}

extern void fn_80287C14(void);
void fn_800072D0(s32 a, s32 b, s32 c)
{
    fn_802A9B94(a, b, c, fn_80287C14);
}

void fn_800072F8(s32 a, s32 b, s32 c)
{
    fn_802A9338(a, b, c, fn_80287C14);
}

extern void fn_802873BC(void);
void fn_80007320(s32 a, s32 b, s32 c)
{
    fn_802A9B94(a, b, c, fn_802873BC);
}

void fn_80007348(s32 a, s32 b, s32 c)
{
    fn_802A9338(a, b, c, fn_802873BC);
}

extern void fn_802890A4(void);
void fn_80007370(s32 a, s32 b, s32 c)
{
    fn_802A9B94(a, b, c, fn_802890A4);
}

void fn_80007398(s32 a, s32 b, s32 c)
{
    fn_802A9338(a, b, c, fn_802890A4);
}

void fn_80008170(void) {
    fn_8023A8E0((s32)lbl_803478DC);
}

void fn_800091A4(s16* p) {
    s16 x = p[0];
    s16 y = p[1];
    if (x >= 0) {
        fn_800090F8((y << 16) | x, p);
    }
}

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

s32 fn_8000ACE8(void) {
    return 1;
}

f32 fn_8000ACF0(Vec3* v) {
    return fn_80291A5C(v->z * v->z + (v->x * v->x + v->y * v->y));
}

void fn_8000CC84(s32 flag) {
    if (flag == 1) {
        lbl_80309E5C[2] |= 0x01000000;
    } else {
        lbl_80309E5C[2] &= ~0x01000000;
    }
}

s32 fn_8000F86C(s32 idx) {
    void* p = lbl_80347394;
    if (p != 0) {
        return (s8)*(s16*)((u8*)PTR(p, 0x24) + 0x5c);
    }
    return *(u8*)((u8*)lbl_80309DE4[(s8)idx] + 0x100);
}

void fn_8000F8A4(void* obj, void* x) {
    s32 v = fn_8000F718(x, 0, 0);
    fn_8000F6F8(obj, 0x40, v, -1, 0);
}

void fn_80010538(s16 idx) {
    s32 mode = lbl_80309730[idx].mode;
    void* q;
    if (mode == 0) {
        return;
    }
    if (mode == 4) {
        return;
    }
    q = lbl_80309DE4[idx];
    *(s16*)((u8*)q + 0xb4) += *(s16*)((u8*)q + 8);
}

extern void fn_80011208(s32 a, s32 b, s32 c);
s32 fn_80010B5C(void) {
    return 1;
}

void fn_80011370(s32 a, s32 b)
{
    fn_80011208(a, b, 0);
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

void fn_80017320(void) {
}

void fn_80017778(void) {
    s8 i;
    for (i = 0; i < 14; i++) {
        void* obj = lbl_80309E24[i];
        if (obj != 0) {
            u8* p = PTR(PTR(obj, 0x24), 0x4c);
            *(u32*)(p + 0xf0) &= ~0x00400000;
        }
    }
}

extern u32 fn_800215EC(s8);
int fn_800179B4(int a) {
    return fn_800215EC((s8)a) != 0;
}

s32 fn_800179E4(s16 a) {

    return fn_800215EC((s8)a) != 0;
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

void fn_80007280(s32 a, s32 b, s32 c)
{
    fn_802A9B94(a, b, c, fn_8028AB48);
}

void fn_80007514(u32 *a, u32 *b)
{
    *b = lbl_803478A0;
    *a = lbl_803478A4;
}

s32 fn_80008258(u32 *out)
{
    u32 n = *(u32 *)(lbl_803478DC + 0x34);
    *out = (n + 0x1f) & ~0x1fu;
    return 1;
}

void fn_80008308(s32 a, s32 b)
{
    fn_8000832C(a, b, 0);
}

void fn_80008694(s32 a, s32 b, s32 c, s32 d)
{
    fn_800086BC(a, b, c, d, 0, 0);
}

void fn_80008DE4(s16 v)
{
    *(s16 *)(lbl_8030A10C + 0xf0) = v;
}

void fn_80009860(void *v, Ent_80009860 *e)
{
    if (e->id < 0) return;
    e->ptr = v;
}

void fn_80009FBC(u8 *p)
{
    if (p[0x19] == 0xff) p[0x18] |= 0x40;
}

void fn_8000A38C(void)
{
    if (lbl_80346AA4 != NULL) lbl_80346AA4[0x19] = 3;
}

u32 fn_8000F0A4(s16 i)
{
    return lbl_802DAFA8[i];
}

s16 fn_80010CBC(s16 i)
{
    s8 k = (s8)lbl_8030B7F4[i + 0x328];
    return *(s16 *)(lbl_8030B7F4 + k * 0x5c + 0x1c);
}

s32 fn_80010CE4(u8 *a, u8 *b)
{
    return *(s32 *)(a + 4) - *(s32 *)(b + 4);
}

void fn_800120D0(s32 a)
{
    fn_800614FC(lbl_80309EC8 + 0x64, a);
}

void fn_80012100(s32 a)
{
    fn_80071CF0(lbl_80309EC8 + 0x58, a);
}

u32 fn_80012F24(s32 idx)
{
    u8 *p = (u8 *)fn_80021658((s8)idx);
    u8 *q = *(u8 **)(p + 0x24);
    u8 *r = *(u8 **)(q + 0x4c);
    u32 v = *(u32 *)(r + 0xec);
    return (v >> 21) & 1;
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
    Vec3 v;
    fn_8001C6CC(a, b, c, &v);
    fn_8006C860("/BEFF/", &v);
}

void fn_8001D1D8(Tk_8001D1D8* t, s32 v) {
    fn_80071CF0((u8*)t->work + 0x1C, v);
}

s32 fn_80020060(Ent_80020060* p) {
    s32 i = 0;
    for (;;) {
        if (p->x2 == 3) break;
        if (p->x2 == 0) return i;
        p++;
        i++;
    }
    return -1;
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

extern void fn_8000F2A0(void);
void fn_8000F6F8(void* obj, s32 a, s32 b, s32 c, s32 d) {
    fn_8000F2A0();
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

void fn_80012020(f32 *v)
{
    f32 x;
    x = v[0];
    if (x) (*(State_80309EC8*)&lbl_80309EC8).b[0] = x;
    x = v[1];
    if (x) (*(State_80309EC8*)&lbl_80309EC8).b[1] = x;
    x = v[2];
    if (x) (*(State_80309EC8*)&lbl_80309EC8).b[2] = x;
}

s32 fn_80018498(f32 *v)
{
    if (v[0] > 67.5f) return 0;
    if (v[0] < -67.5f) return 0;
    if (v[2] > 67.5f) return 0;
    return !(v[2] < -67.5f);
}

s32 fn_80014F50(Obj *o)
{
    switch (lbl_80309730[o->inner->work->idx].mode) {
    case 0:
        return 0;
    default:
        return 1;
    }
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
        if (!((*(G*)&lbl_80309E5C).x8 & 0x1000000)) {
            if ((*(G*)&lbl_80309E5C).x8 & 0x8000000) {
                u->x40 = 1;
                u->x44 = (*(G*)&lbl_80309E5C).x18;
                u->x48 = (*(G*)&lbl_80309E5C).x1c;
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
                    if ((*(G*)&lbl_80309E5C).x0 == 6) {
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

void fn_8000EDE4(Tk_8000EDE4* t)
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
        if (!((*(G*)&lbl_80309E5C).x8 & 0x1000000)) {
            if ((*(G*)&lbl_80309E5C).x8 & 0x8000000) {
                u->x40 = 1;
                u->x44 = (*(G*)&lbl_80309E5C).x18;
                u->x48 = (*(G*)&lbl_80309E5C).x1c;
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
        (*(GS*)&lbl_8030A10C).x1c4 -= 1;
        break;
    }
}

void fn_80018868(Tk_80018868* t, s8 mode, f32 frame)
{
    W_80018868* w;
    U_80018868* u;
    void* x0;
    DrawState s;
    u16 a;
    u16 b;

    if (mode >= 0) {
        w = t->work;
        u = w->u;
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
                fn_80035468(x0, u->x74, u->x84, 1, frame);
                break;
            case 1:
                fn_80035228(x0, u->x74, 1, frame);
                break;
            case 2:
                fn_800353F4(x0, u->x5c, u->x60, 1, frame);
                break;
            case 4:
                fn_8003529C(x0, u->x5c, 1, frame);
                break;
            case 3:
                fn_80035380(x0, u->x5c, 1, frame);
                break;
            }
            DrawStatePop(&s);
        }
    }
}

inline int Match(Tk_8001CED0* t, Unit_8001CED0* u)
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

inline int Kind(Unit_8001CED0* u)
{
    switch (u->x10) {
    case 0x10:
    case 0x17:
    case 0x1d:
        return 0;
    }
    return 1;
}


inline int Both(Tk_8001CED0* t)
{
    Unit_8001CED0* u2 = t->work->w;
    if (!Kind(u2)) {
        return 0;
    }
    return Match(t, u2);
}

int fn_8001CED0(Tk_8001CED0* t)
{
    u32 flags = 0;
    Unit_8001CED0* u = t->work->w;
    s8 r;
    s16 a;
    s16 b;
    Unit_8001CED0* u2;

    r = fn_8002EEFC(t, &flags);
    if (!Kind(t->work->w)) {
        flags &= ~0x20000000;
    }
    if (r == 2) {
        r = 1;
    }
    if (fn_80030AE8(flags, u) && Both(t)) {
        u2 = t->work->w;
        if (u2->xec & 0x8000) {
            a = u2->x14;
            b = u2->x16;
        } else {
            a = u2->x6;
            b = u2->x8;
        }
        if (fn_80009030((*(GS_8001CED0*)&lbl_8030A10C).x10, a, b, -1, -1)) {
            fn_800312F0(t, a, b, r);
            u->xec &= ~0x8000;
        }
    } else {
        u2 = t->work->w;
        if (u2->xec & 0x8000) {
            a = u2->x14;
            b = u2->x16;
        } else {
            a = u2->x6;
            b = u2->x8;
        }
        if (fn_80009030((*(GS_8001CED0*)&lbl_8030A10C).x10, a, b, -1, -1)) {
            fn_80031254(t);
            u->xec |= 0x80000;
        }
    }
}
