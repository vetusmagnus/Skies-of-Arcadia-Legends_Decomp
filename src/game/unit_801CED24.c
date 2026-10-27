#include "types.h"
#include <string.h>
#include "game/drawstate.h"
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
extern f32 lbl_80308CE0[4];
extern u8 lbl_80308CF0[0x100];
extern s32 lbl_80347270;
extern s32 lbl_80347274;
extern void fn_8029CFF8(s32 a);

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

void fn_801D0680(void);
u32 fn_801D0AB4(u32 x);
extern s16 lbl_80347256;
extern s32 lbl_8034721C;
extern s32 lbl_80346A50;
extern void fn_801D075C(void);
extern void fn_801D0BC0(s32 a, f32 b);
extern void fn_802A8E50(void* p, u32 len, s32 mode);
extern void fn_802A8D64(void* p, u32 len, s32 mode);
extern void fn_8024DE74(void);
extern void fn_8029CEA4(s32 a, s32 b);
extern void fn_8029CE6C(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
extern void fn_80296EEC(s32 a, s32 b, s32 c);
extern void fn_802A8BA4(void);
extern void njPushMatrixEx(void);
extern void njPopMatrixEx(void);
extern void njScale(NJS_MATRIX m, f32 x, f32 y, f32 z);

/* The draw buffer: lbl_80347218 is its fill mark, lbl_80347258 the part already flushed and
 * lbl_8034725C the flush pointer (see fn_801D0B50). Flushing applies only while it is enabled
 * and holds something new. */
#define DRAWBUF_PENDING()                                                                   \
    ((s16)lbl_80347256 < 0x400 && (u32)lbl_80347218 > (u32)lbl_80347258 && lbl_80347208 != 0 \
     && lbl_8034720C != 0)

static inline void DrawBufFlush(void* p, u32 len, s32 mode)
{
    if (lbl_803475D8 != 0) {
        p = 0;
    }
    if (p != 0) {
        GXFlush();
        if (lbl_8034721C == 0) {
            fn_802A8E50(p, lbl_80347218, mode);
            lbl_8034721C = 1;
        } else {
            fn_802A8D64(p, len, mode);
        }
        fn_8024DE74();
    } else {
        fn_802A8E50(p, len, mode);
    }
}

/* Same body as DrawBufFlush; calling it from here gives other registers. */
static inline void DrawBufFlushPending(s32 mode)
{
    u32 len = lbl_80347218 - lbl_80347258;
    void* p = (void*)lbl_8034725C;
    if (lbl_803475D8 != 0) {
        p = 0;
    }
    if (p != 0) {
        GXFlush();
        if (lbl_8034721C == 0) {
            fn_802A8E50(p, lbl_80347218, mode);
            lbl_8034721C = 1;
        } else {
            fn_802A8D64(p, len, mode);
        }
        fn_8024DE74();
    } else {
        fn_802A8E50(p, len, mode);
    }
}
static inline s32 RoomIs74a(void)
{
    s32 ok = 0;
    if (lbl_803475CC == 6 && lbl_80311AC0.id == 0x74 && lbl_80311AC0.x8 == 0x61) {
        ok = 1;
    }
    return ok;
}

static inline void DrawBufFlushRoom(void)
{
    if (DRAWBUF_PENDING()) {
        if (RoomIs74a()) {
            DrawBufFlushPending(6);
        } else {
            DrawBufFlushPending(4);
        }
        DrawStateApplyFog();
    }
}

/* Clip distance for layer k: far (1410055424) or near (100) in modes 1 and 2, otherwise the
 * squared view-space distance of the object's position (+8), capped at the far value. */
static inline void SetLayerClip(s32 k, s32 obj)
{
    NJS_POINT3 v;
    f32 d;
    if (DRAWBUF_PENDING()) {
        if (lbl_80347214 == 1) {
            d = 1410055424.0f;
        } else if (lbl_80347214 == 2) {
            d = 100.0f;
        } else {
            njCalcPoint(0, (NJS_POINT3*)(obj + 8), &v);
            d = v.x * v.x + v.y * v.y + v.z * v.z;
            if (d > 1410055424.0f) {
                d = 1410055424.0f;
            }
        }
        fn_801D0BC0(k, 10000.0f + d);
    }
}

static inline void SetLayerClipObj(s32 k)
{
    if (lbl_80347228 & 0xF) {
        SetLayerClip(k, lbl_8034722C);
    } else {
        SetLayerClip(k, lbl_80347230);
    }
}

static inline void DrawLayerMasked(void)
{
    fn_8029CEA4(0, 1);
    fn_8029CE6C(6, lbl_80346820, 0, 6, lbl_80346820, 1);
    fn_801D075C();
    fn_8029CEA4(0, 1);
    fn_8029CE6C(4, 0, 0, 7, 0, 1);
}

static inline void DrawLayerScaled(void)
{
    DrawBufFlush(0, 0, 2);
    if (lbl_80347248 & 0x00100000) {
        njPushMatrixEx();
        fn_80286EE8();
        fn_8028B498();
        njScale(0, 1.01f, 1.01f, 1.01f);
    }
    fn_801D075C();
    if (lbl_80347248 & 0x00100000) {
        njPopMatrixEx();
    }
    fn_802A8BA4();
    lbl_80346A50 = 1;
}

/* The same flush written out with the caller's own tex/len variables. fn_801CF248 needs it in
 * this form where the inline version's fresh locals take different registers. */
#define DRAWBUF_FLUSH(mode)                                     \
    if (lbl_803475D8 != 0) {                                    \
        tex = 0;                                                \
    }                                                           \
    if (tex != 0) {                                             \
        GXFlush();                                              \
        if (lbl_8034721C == 0) {                                \
            fn_802A8E50(tex, lbl_80347218, mode);               \
            lbl_8034721C = 1;                                   \
        } else {                                                \
            fn_802A8D64(tex, len, mode);                        \
        }                                                       \
        fn_8024DE74();                                          \
    } else {                                                    \
        fn_802A8E50(tex, len, mode);                            \
    }

/* Bit 0x4000: draw the layer with fn_80296EEC(1, 3, 0) set (restored after). Uses the caller's alt. */
#define DRAW_LAYER(f)                                           \
    alt = (f) & 0x4000;                                         \
    if (alt) {                                                  \
        fn_80296EEC(1, 3, 0);                                   \
    }                                                           \
    fn_801D075C();                                              \
    if (alt) {                                                  \
        fn_80296EEC(1, 3, 1);                                   \
    }

/* Draws the queued layer selected by lbl_80347228/lbl_80347248 (set by the fn_801CED24..
 * fn_801CF218 wrappers above), flushing the draw buffer and setting clip distances around it,
 * then clears the request. */
void fn_801CF248(void)
{
    u32 f;
    s32 k;
    f32 d;
    s32 alt;
    void* tex;
    u32 len;

    f = fn_801D0AB4(lbl_80347248);
    fn_801D0680();
    if (f & 0xFF000000) {
        if (!(f & 0x02000000)) {
            if (f & 0x08000000) {
                if (!(f & 0x00200000)) {
                    DrawBufFlushRoom();
                    DRAW_LAYER(f);
                    SetLayerClipObj(5);
                }
                DrawLayerScaled();
            } else if (f & 0x8000) {
                DrawLayerMasked();
            } else if ((k = f & 0xFE000000) != 0) {
                if (!(f & 0x00200000)) {
                    DrawBufFlushRoom();
                    DRAW_LAYER(f);
                    switch (k) {
                    case 0x10000000:
                    default:
                        k = 3;
                        break;
                    case 0x20000000:
                        k = 4;
                        break;
                    case 0x40000000:
                        k = 6;
                        break;
                    case (s32)0x80000000:
                        k = 7;
                        break;
                    case 0x04000000:
                        k = 8;
                        break;
                    }
                    SetLayerClipObj(k);
                }
                DrawLayerScaled();
            } else if (f & 0x01000000) {
                DRAW_LAYER(f);
            } else {
                fn_801D075C();
            }
        }
    } else if (lbl_80347214 != 0) {
        if (DRAWBUF_PENDING()) {
            tex = (void*)lbl_8034725C;
            len = lbl_80347218 - lbl_80347258;
            DRAWBUF_FLUSH(1);
            DrawStateApplyFog();
        }
        fn_801D075C();
        if (DRAWBUF_PENDING()) {
            d = 0.0f;
            switch (lbl_80347214) {
            case 1:
                d = 1410055424.0f;
                break;
            case 2:
                d = 10000.0f;
                break;
            }
            fn_801D0BC0(2, 10000.0f + d);
        }
    } else if (f & 0x8000) {
        DrawLayerMasked();
    } else if (lbl_8034720C != 0 && (f & 0x1000)) {
        if (!(f & 0x00200000)) {
            DrawBufFlushRoom();
            DRAW_LAYER(f);
            if (f & 0x800) {
                SetLayerClipObj(9);
            } else if (f & 0x80) {
                SetLayerClipObj(3);
            } else {
                SetLayerClipObj(2);
            }
        }
        if (!(f & 0x200)) {
            if (f & 0x100) {
                if (DRAWBUF_PENDING()) {
                    len = lbl_80347218 - lbl_80347258;
                    tex = (void*)lbl_8034725C;
                    DRAWBUF_FLUSH(2);
                    DrawStateApplyFog();
                }
                fn_801D075C();
                SetLayerClipObj(0);
            } else {
                len = 0;
                tex = 0;
                DRAWBUF_FLUSH(2);
                fn_801D075C();
                fn_802A8BA4();
                lbl_80346A50 = 1;
            }
        }
    } else {
        if (lbl_80311AC0.id == 0x217 && (f & 0x4000)) {
            fn_80296EEC(1, 3, 0);
        }
        fn_801D075C();
        if (lbl_80311AC0.id == 0x217 && (f & 0x4000)) {
            fn_80296EEC(1, 3, 1);
        }
    }
    if (f & 0x2000) {
        fn_8029CFF8(0);
    }
    lbl_80347228 = 0;
    lbl_8034722C = 0;
    lbl_80347230 = 0;
    lbl_80347234 = 0;
    lbl_80347238 = 0;
    lbl_8034723C = 0;
    lbl_80347240 = 0;
    lbl_80347244 = 0.0f;
    lbl_80347248 = 0;
    switch (lbl_8034724C) {
    case 2:
        lbl_80345850[0] = 60000.0f;
        break;
    case 3:
        njClipZ(-1.0f, -60000.0f);
        break;
    case 1:
        njClipZ(-1.0f, -60000.0f);
        break;
    }
    lbl_8034724C = 0;
    if (lbl_80311AC0.id == 0x11 && lbl_80311AC0.x8 == 0x61) {
        lbl_80346820 = 0x80;
    }
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

void fn_801D1A94(void) {
    f32* p;
    s32 i;
    lbl_80347270 = 0;
    lbl_80347274 = 0;
    memset(lbl_80308CF0, 0, 0x100);
    p = lbl_80308CE0;
    for (i = 4; i != 0; i--) {
        *p++ = 0.0f;
    }
}

/* Adds the modifier bits to a key/button code: lbl_80347220 (unless it is the 0x80000
 * raw mode) and lbl_80347224 for plain codes below 0x100. Bit 0x2000 calls fn_8029CFF8(1).
 * lbl_80347224 is compared signed (cmpwi): it is s32 here, u32 in unit_801CED24.c. */
u32 fn_801D0AB4(u32 x) {
    s32 m;
    u32 v;
    u32 r;
    m = lbl_80347220;
    v = (m == 0x80000) ? x : (m | (x & 0x7f));
    r = v;
    m = lbl_80347224;
    if (m != 0 && (x & ~0xff) == 0) {
        r = v | (m | (x & 0x7f));
    }
    if (r & 0x2000) {
        fn_8029CFF8(1);
    }
    return r;
}
