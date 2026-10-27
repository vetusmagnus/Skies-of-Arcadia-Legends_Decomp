#include "types.h"
extern u32 lbl_80347228;
extern u32 lbl_80347230;
extern u32 lbl_8034723C;
extern u32 lbl_80347240;
extern u32 lbl_80347248;
extern u32 lbl_80347234;
extern u32 lbl_80347238;
extern f32 lbl_80347244;
extern void fn_801CF248(void);
extern s32 lbl_80347208;
extern s32 lbl_80347210;
extern s32 lbl_80347258;
extern s32 lbl_8034725C;
extern s32 lbl_80347264;
extern u32 lbl_803476A4;
extern u32 lbl_80347260;
extern void fn_80005AD8(u32 a, u32 b);
extern s32 lbl_80347218;
extern s32 lbl_8034720C;
extern s32 lbl_80347214;
extern s32 lbl_80347220;
extern void fn_801D129C(void);
extern u8 lbl_80346820;
/* lbl_8034720C = (lbl_80347208 != 0), and the value is returned (r3 holds the result;
 * as a void function the compiler keeps it in r0). The one caller, fn_801DC62C, ignores it. */
extern long lbl_80347208;
typedef struct Node { u8 pad0[4]; struct Node* next; void* tex; } Node;
extern Node* lbl_80308CB8[10];
extern s32 lbl_803475D8;
extern s32 lbl_803475CC;
extern void FogOn(void);
extern void FogOff(void);
extern void fn_80286EE8(void);
extern void fn_8028B498(void);
extern void fn_801D1714(void);
extern void fn_801DBCD4(void);
extern void GXFlush(void);
extern void fn_802A8AE4(void* tex);
extern s32 lbl_8034722C;
extern s32 lbl_8034724C;
extern void njClipZ(f32 near, f32 far);
extern f32 lbl_80345850[10];
typedef struct { s32 id; u8 pad4[4]; s8 x8; } Cur;
extern Cur lbl_80311AC0;
extern u32 lbl_80310B3C[];

void fn_801CED24(u32 a, u32 b, u32 c, f32 d, u32 e)
{
    lbl_80347230 = a;
    lbl_80347228 = 0x08000000;
    lbl_8034723C = b;
    lbl_80347240 = c;
    lbl_80347244 = d;
    lbl_80347248 = e;
    fn_801CF248();
}

void fn_801CED60(u32 a, u32 b, u32 c, f32 d, u32 e)
{
    lbl_80347230 = a;
    lbl_80347228 = 0x04000000;
    lbl_8034723C = b;
    lbl_80347240 = c;
    lbl_80347244 = d;
    lbl_80347248 = e;
    fn_801CF248();
}

void fn_801CED9C(u32 a, u32 b, u32 c, f32 d, u32 e)
{
    lbl_80347230 = a;
    lbl_80347228 = 0x02000000;
    lbl_8034723C = b;
    lbl_80347240 = c;
    lbl_80347244 = d;
    lbl_80347248 = e;
    fn_801CF248();
}

void fn_801CEDD8(u32 a, u32 b, u32 c, f32 d, u32 e)
{
    lbl_80347230 = a;
    lbl_80347228 = 0x01000000;
    lbl_8034723C = b;
    lbl_80347240 = c;
    lbl_80347244 = d;
    lbl_80347248 = e;
    fn_801CF248();
}

void fn_801CEE14(u32 a, u32 b, f32 d, u32 c)
{
    lbl_80347230 = a;
    lbl_80347228 = 0x00800000;
    lbl_8034723C = b;
    lbl_80347244 = d;
    lbl_80347248 = c;
    fn_801CF248();
}

void fn_801CEE4C(u32 a, u32 b, f32 d, u32 c)
{
    lbl_80347230 = a;
    lbl_80347228 = 0x00400000;
    lbl_8034723C = b;
    lbl_80347244 = d;
    lbl_80347248 = c;
    fn_801CF248();
}

void fn_801CEE84(u32 a, u32 b, f32 d, u32 c)
{
    lbl_80347230 = a;
    lbl_80347228 = 0x00200000;
    lbl_8034723C = b;
    lbl_80347244 = d;
    lbl_80347248 = c;
    fn_801CF248();
}

void fn_801CEEBC(u32 a, u32 b, f32 d, u32 c)
{
    lbl_80347230 = a;
    lbl_80347228 = 0x00100000;
    lbl_8034723C = b;
    lbl_80347244 = d;
    lbl_80347248 = c;
    fn_801CF248();
}

void fn_801CEEF4(u32 a, u32 b, u32 c, f32 d, u32 e)
{
    lbl_80347230 = a;
    lbl_80347228 = 0x00080000;
    lbl_80347234 = b;
    lbl_80347238 = c;
    lbl_80347244 = d;
    lbl_80347248 = e;
    fn_801CF248();
}

void fn_801CEF30(u32 a, u32 b, u32 c, f32 d, u32 e)
{
    lbl_80347230 = a;
    lbl_80347228 = 0x00040000;
    lbl_80347234 = b;
    lbl_80347238 = c;
    lbl_80347244 = d;
    lbl_80347248 = e;
    fn_801CF248();
}

void fn_801CEF6C(u32 a, u32 b, u32 c, f32 d, u32 e)
{
    lbl_80347230 = a;
    lbl_80347228 = 0x00020000;
    lbl_80347234 = b;
    lbl_80347238 = c;
    lbl_80347244 = d;
    lbl_80347248 = e;
    fn_801CF248();
}

void fn_801CEFA8(u32 a, u32 b, u32 c, f32 d, u32 e)
{
    lbl_80347230 = a;
    lbl_80347228 = 0x00010000;
    lbl_80347234 = b;
    lbl_80347238 = c;
    lbl_80347244 = d;
    lbl_80347248 = e;
    fn_801CF248();
}

void fn_801CEFE4(u32 a, u32 b, f32 d, u32 c)
{
    lbl_80347230 = a;
    lbl_80347228 = 0x8000;
    lbl_80347234 = b;
    lbl_80347244 = d;
    lbl_80347248 = c;
    fn_801CF248();
}

void fn_801CF020(u32 a, u32 b, f32 d, u32 c)
{
    lbl_80347230 = a;
    lbl_80347228 = 0x4000;
    lbl_80347234 = b;
    lbl_80347244 = d;
    lbl_80347248 = c;
    fn_801CF248();
}

void fn_801CF058(u32 a, u32 b, f32 d, u32 c)
{
    lbl_80347230 = a;
    lbl_80347228 = 0x2000;
    lbl_80347234 = b;
    lbl_80347244 = d;
    lbl_80347248 = c;
    fn_801CF248();
}

void fn_801CF090(u32 a, u32 b, f32 d, u32 c)
{
    lbl_80347230 = a;
    lbl_80347228 = 0x1000;
    lbl_80347234 = b;
    lbl_80347244 = d;
    lbl_80347248 = c;
    fn_801CF248();
}

extern u32 lbl_80347224;
void fn_801D0B2C(void) {
    lbl_80347224 = 0;
}

void fn_801D0B38(s32 v) {
    lbl_80347224 = v;
}

s32 fn_801D0B40(void) {
    return lbl_80347220;
}

void fn_801D0B48(s32 v) {
    lbl_80347220 = v;
}

void fn_801D0B50(s32 delta)
{
    s32 cur;
    s32 sum;
    s32 hi;

    if (lbl_80347208 == 0) {
        return;
    }
    cur = lbl_80347258 + delta;
    sum = lbl_80347264 + cur;
    hi = lbl_80347210;
    lbl_80347258 = cur;
    lbl_8034725C = sum;
    if (hi >= cur) {
        return;
    }
    lbl_80347210 = cur;
}

void fn_801D13D8(void)
{
    if (lbl_80347208 != 0) {
        lbl_80347208 = 0;
        fn_80005AD8(lbl_803476A4, lbl_80347264);
        fn_80005AD8(lbl_803476A4, lbl_80347260);
    }
}

s32 fn_801D0B88(void) {
    s32 r = 0;

    if (lbl_80347208 != 0) {
        r = lbl_80347218 - lbl_80347258;
    }
    return r;
}

s32 fn_801D0BA8(void) {
    s32 r = 0;

    if (lbl_80347208 != 0) {
        r = lbl_8034725C;
    }
    return r;
}

void fn_801D0EA4(void) {
    if (lbl_8034720C != 0) {
        lbl_80347214 = 0;
    }
}

void fn_801D0EBC(void) {
    if (lbl_8034720C != 0) {
        lbl_80347214 = 2;
    }
}

void fn_801D1268(void) {
    if (lbl_80347208 != 0) {
        lbl_80347220 = 0x80000;
        fn_801D129C();
    }
}

void fn_801D1420(void) {
    lbl_80346820 = 0x80;
}

void fn_801D142C(u8 v)
{
    lbl_80346820 = v;
}

extern u32 lbl_80347268;
void fn_801D14F8(void) {
    lbl_80347268 = 0;
}

s32 fn_801D1504(void) {
    return lbl_80347268;
}

int fn_801D13C0(void) {
    return lbl_8034720C = lbl_80347208 != 0;
}

static inline void FreeList(Node* n)
{
    for (; n != 0; n = n->next) {
        if (n->tex != 0) {
            GXFlush();
            fn_802A8AE4(n->tex);
            n->tex = 0;
        }
    }
}

void fn_801D0F80(void)
{
    Node* n;
    if (lbl_80347208 != 0 && lbl_803475D8 == 0) {
        if (lbl_803475CC == 6) {
            FogOn();
        }
        fn_80286EE8();
        fn_8028B498();
        FreeList(lbl_80308CB8[1]);
        if (lbl_803475CC == 6) {
            FogOff();
        }
        fn_801D1714();
        if (lbl_803475CC == 6) {
            FogOn();
        }
        FreeList(lbl_80308CB8[0]);
        FreeList(lbl_80308CB8[3]);
        FreeList(lbl_80308CB8[4]);
        FreeList(lbl_80308CB8[5]);
        FreeList(lbl_80308CB8[2]);
        FreeList(lbl_80308CB8[6]);
        FreeList(lbl_80308CB8[7]);
        FreeList(lbl_80308CB8[8]);
        for (n = lbl_80308CB8[9]; n != 0; n = n->next) {
            if (n->tex != 0) {
                fn_801DBCD4();
                GXFlush();
                fn_802A8AE4(n->tex);
                n->tex = 0;
            }
        }
        if (lbl_803475CC == 6) {
            FogOff();
        }
    }
}

void fn_801CF0C8(s32 a, s32 b) {
    lbl_80347230 = a;
    lbl_80347228 = 0x80;
    lbl_80347248 = b;
    fn_801CF248();
}

void fn_801CF0F8(s32 a, s32 b) {
    lbl_80347230 = a;
    lbl_80347228 = 0x40;
    lbl_80347248 = b;
    fn_801CF248();
}

void fn_801CF128(s32 a, s32 b) {
    lbl_80347230 = a;
    lbl_80347228 = 0x20;
    lbl_80347248 = b;
    fn_801CF248();
}

void fn_801CF158(s32 a, s32 b) {
    lbl_80347230 = a;
    lbl_80347228 = 0x10;
    lbl_80347248 = b;
    fn_801CF248();
}

void fn_801CF188(s32 a, s32 b) {
    lbl_8034722C = a;
    lbl_80347228 = 0x8;
    lbl_80347248 = b;
    fn_801CF248();
}

void fn_801CF1B8(s32 a, s32 b) {
    lbl_8034722C = a;
    lbl_80347228 = 0x4;
    lbl_80347248 = b;
    fn_801CF248();
}

void fn_801CF1E8(s32 a, s32 b) {
    lbl_8034722C = a;
    lbl_80347228 = 0x2;
    lbl_80347248 = b;
    fn_801CF248();
}

void fn_801CF218(s32 a, s32 b) {
    lbl_8034722C = a;
    lbl_80347228 = 0x1;
    lbl_80347248 = b;
    fn_801CF248();
}

void fn_801D0680(void) {
    lbl_8034724C = 0;
    if (lbl_80311AC0.id == 0x74 && lbl_803475CC != 7) {
        s8 c = lbl_80311AC0.x8;
        if (c == 0x66) {
            lbl_8034724C = 1;
            njClipZ(-1.0f, -1000000.0f);
        } else if (c == 0x61) {
            lbl_8034724C = 2;
            lbl_80345850[0] = 1900.0f;
        } else if (c == 0x63) {
            if (lbl_80310B3C[89] & 0x200) {
                lbl_8034724C = 3;
                njClipZ(-1.0f, -400.0f);
            }
        }
    }
    if (lbl_80311AC0.id == 0x11 && lbl_80311AC0.x8 == 0x61) {
        lbl_80346820 = 0xc0;
    }
}
