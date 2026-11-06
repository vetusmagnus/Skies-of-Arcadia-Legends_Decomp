#include "game/unit_80219378.h"

extern Blk2_UNIT0000 lbl_803167F0;
typedef struct P_UNIT0000 { u8 pad[0x1c]; s32 f1c; } P_UNIT0000;
extern s32 lbl_80347EB0;
extern s32 lbl_80347EA8;
extern s32 lbl_80347EB4;
extern void fn_8028BAEC(void *p);
typedef struct Pos_UNIT0000 { u8 pad0[0x1c]; s32 f1c; s32 f20; u8 pad1[0x10]; s32 f34; } Pos_UNIT0000;
extern Pos_UNIT0000 lbl_80311970;
extern double atan2(double y, double x);
extern void *memcpy(void *dst, const void *src, unsigned long n);
extern u8 lbl_803165C8[];
extern s32 fn_801DD078(void *a, void *b);
extern s32 fn_801DCFA0(void *a, void *b);
typedef struct Obj8 { s32 pad0; s32 a4; s32 a8; } Obj8;
extern const char *lbl_802F9238[];
typedef struct Obj1E4 { u8 pad[8]; s32 a8; u8 pad2[0x10]; s32 a1c; } Obj1E4;
extern f32 njScalor(Vec *v);
extern char lbl_802D98B8[];
extern s8 lbl_8034C6C4[8];
extern s32 fn_801A28F4(s32 *p);
typedef struct Obj {
    s32 x0;
    u8 pad4[4];
    s32 x8;
    s32 xc;
    s32 x10;
    s32 x14;
    s32 x18;
    s32 x1c;
} Obj;
typedef struct Spec {
    u8 pad0[0x3c];
    f32 amp1;
    s32 ang1;
    f32 amp2;
    s32 ang2;
} Spec;
extern void njCalcVector(NJS_MATRIX m, NJS_POINT3 *v, NJS_POINT3 *out);
typedef struct Menu {
    s32 mode;
    u8 pad4[4];
    s32 x8;
    s32 xc;
    s32 x10;
    s32 x14;
    u8 pad18[4];
    s32 x1c;
} Menu;
extern s32 lbl_803475D0;
extern void fn_801A289C(void);
extern void fn_801A2C40(void);
extern s32 fn_801A2670(s32 idx, s32 *out);
extern void fn_801DD5E8(Angle* out, NJS_POINT3* p);

extern u32 lbl_80347860;
extern u8 lbl_802D9F9C[];

typedef struct Frame_802F92D8 { u8 pad0[8]; void *f8; u8 pad1[0xc]; } Frame_802F92D8;
extern Frame_802F92D8 lbl_802F92D8;
extern s32 fn_80212050(void);
extern void fn_801228A0(s32 v);

extern u8 lbl_80316810[0x20];

typedef struct Screen8022BC64 {
    u8 pad00[8];
    f32 x08, x0c;
    u8 pad10[8];
    f32 z;
    u8 pad1c[0xc];
    f32 x28, x2c;
} Screen8022BC64;
extern Screen8022BC64 lbl_803118AC;
extern f32 lbl_80347570;
extern void njSetScreen(Screen8022BC64 *s);

typedef struct { f32 pad; f32 r; } Lim_8022C364;

typedef struct {
    u16 a;
    u16 pad;
    f32 b;
    f32 c;
    f32 d;
    s32 e;
    s32 f;
    f32 g;
    f32 h;
    s32 i;
    s32 j;
    s32 k;
    s32 l;
    s32 m;
    f32 n;
    f32 o;
    f32 p;
    f32 q;
    f32 r;
    f32 s;
} Obj7A28;
extern f32 lbl_80345878[];
void fn_801D7A28(Obj7A28* obj, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5, f32 f6, f32 f7);
void fn_801D7C44(void* list, Obj7A28* obj);
void TextSetColor(u32 colour);
f32 TextGetZ(void);
void TextSetZ(f32 z);

extern char* strstr(const char* str, const char* pat);
extern char* lbl_802F91F8[16];

#ifdef NONMATCHING
#include <math.h>
typedef struct AngObj_8022BDD0 {
    u8 pad0[0xc];
    Angle x;    /* 0x0c */
    Angle y;    /* 0x10 */
    Angle z;    /* 0x14 */
} AngObj_8022BDD0;
typedef struct Lim_8022BDD0 {
    u8 pad0[8];
    f32 step;   /* 0x08 */
} Lim_8022BDD0;
f32 fn_802917A0(f32 x);
#endif

/* The walking pointer is assigned in the test: testing the parameter itself gives a second
 * address computation (addic. r0 + addi r4) instead of the single addic. r4. */
static inline void StrLower(char* dst, const char* src) {
    char* p;
    if ((p = dst) != NULL && src != NULL) {
        for (;;) {
            if (*src == '\0') {
                break;
            }
            if (*src >= 'A' && *src <= 'Z') {
                *p = *src + 0x20;
            } else {
                *p = *src;
            }
            src++;
            p++;
        }
        *p = '\0';
    }
}

static inline u16 AngNeg(s32 a) {
    return -a;
}


void fn_8022A7F4(void) {
    memcpy(lbl_803165C8, (void *)0x80800000, 0x204);
}

void fn_8022A824(void) {
    memcpy((void *)0x80800000, lbl_803165C8, 0x204);
}

s32 fn_8022ABEC(char* name) {
    char buf[0x40];
    u32 i;

    StrLower(buf, name);
    for (i = 0; i < 16; i++) {
        if (strstr(lbl_802F91F8[i], buf) != NULL) {
            return i;
        }
    }
    return -1;
}
void fn_8022AE88(void) {
    lbl_80347860 = 1;
}

s32 fn_8022AE94(void) {
    Blk2_UNIT0000* b = &lbl_803167F0;
    Obj7A28 o;
    f32 z;
    if (b->f0 != 0 && b->f0 != 7) {
        fn_801D7A28(&o, -10000.0f, 0.0f, 0.0f, lbl_80345878[10], lbl_80345878[11], 0.0f, 0.0f);
        o.j = 0xff000000;
        o.k = 0xff808080;
        o.l = 0xff808080;
        o.m = 0xff000000;
        fn_801D7C44(lbl_80347854->inner->list, &o);
    }
    TextSetColor(-1);
    z = TextGetZ();
    TextSetZ(-100.0f);
    lbl_802F929C[b->f0](b);
    TextSetZ(z);
    if (b->f18 != 0) {
        lbl_802F92BC[b->f1c](b);
        if (b->f1c != 5) return 2;
        return b->f8;
    }
    return b->f8;
}

void fn_8022AFD0(void)
{
    memset(&lbl_803167F0, 0, 0x20);
    lbl_803167F0.f4 = -1;
}

void fn_8022B010(void) {
}

void fn_8022B014(u8 *p) {
    if (lbl_80347508 != 0) {
        return;
    }
    *(s32_8022B014 *)(p + 0x1c) = 5;
}

void fn_8022B02C(P_UNIT0000 *p)
{
    fn_801CBBAC(20.0f);
    p->f1c = 4;
}

void fn_8022B064(u8 *p) {
    if (lbl_80347508 != 0) {
        return;
    }
    *(s32_8022B064 *)(p + 0x1c) = 0;
}

void fn_8022B07C(P_UNIT0000 *p)
{
    fn_801CBB9C(15.0f);
    p->f1c = 2;
}

void fn_8022B0B4(void) {
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

void fn_8022B128(Obj *o) {
    TextPrint(0x18, 0xf8, lbl_802F9238[24]);
    if (o->x1c == 0 && (lbl_80311A60.p->f8 & 0x100)) {
        fn_801A2C40();
        o->xc = fn_801A28F4(&o->x10);
        switch (o->xc) {
        case 0:
            o->x0 = 1;
            break;
        case 2:
        case 3:
            o->x0 = 3;
            break;
        case 1:
        default:
            o->x0 = 2;
            break;
        }
    }
}

void fn_8022B1E4(Obj1E4 *o) {
    TextPrint(0x18, 0xf8, lbl_802F9238[23]);
    if (o->a1c == 0) {
        if (lbl_80311A60.p->f8 & 0x100) {
            o->a1c = 3;
            o->a8 = 0;
        }
    }
}

void fn_8022B258(Obj *o) {
    s32 v;

    TextPrint(0x18, 0xf8, lbl_802F9238[20 + o->x10]);
    TextPrint(0x18, 0x128, lbl_802F9238[22]);
    if (fn_801A2670(o->x10, &v)) {
        if (v == 0) {
            MenuPlaySe(0x14);
            o->x0 = 5;
        } else {
            if (v == -3) {
                o->xc = 1;
            }
            MenuPlaySe(3);
            o->x0 = 6;
        }
        lbl_803475D0 = 0;
    }
}

void fn_8022B318(Menu *m) {
    TextPrint(0x18, 0xb0, lbl_802F9238[11 + m->x10]);
    TextPrint(0x18, 0xf8, lbl_802F9238[15]);
    TextPrint(0x18, 0x140, lbl_802F9238[19]);
    TextSetColor(m->x14 == 0 ? -1 : 0xff808080);
    TextPrint(0xe0, 0x188, lbl_802F9238[0]);
    TextSetColor(m->x14 == 1 ? -1 : 0xff808080);
    TextPrint(0x158, 0x188, lbl_802F9238[1]);
    if (m->x1c == 0) {
        m->xc = fn_801A28F4(&m->x10);
        if (m->xc == 2) {
            u32 btn = lbl_80311A60.p->f8;
            if (((btn & 1) && m->x14 == 1) || ((btn & 2) && m->x14 == 0)) {
                MenuPlaySe(0);
                m->x14 = (m->x14 == 0);
            } else if (btn & 0x100) {
                MenuPlaySe(2);
                if (m->x14 == 0) {
                    lbl_803475D0 = 1;
                    fn_801A289C();
                    m->mode = 4;
                } else {
                    m->x1c = 3;
                    m->x8 = 0;
                }
            }
        } else if (m->xc == 0) {
            m->mode = 1;
        } else {
            m->mode = 2;
        }
    }
}

void fn_8022B6F4(Obj *o) {
    char *b = lbl_802D98B8;
    if (o->xc == 7) {
        TextPrintf(0x18, 0xc8, b + 0x5d4, lbl_8034C6C4[o->x10]);
        TextPrint(0x18, 0x110, b + 0x624);
        TextPrint(0x18, 0x158, b + 0x678);
        TextPrint(0x18, 0x188, b + 0x6a8);
    } else {
        TextPrint(0x18, 0x140, lbl_802F9238[18]);
    }
    o->xc = fn_801A28F4(&o->x10);
    if (o->xc != 0 && o->xc != 7) {
        o->x0 = 2;
    } else if (o->x1c == 0) {
        if (lbl_80311A60.p->f8 & 0x100) {
            o->x1c = 3;
            o->x8 = 0;
        }
    }
}

void fn_8022B808(Obj *o) {
    fn_801A2C40();
    o->xc = fn_801A28F4(&o->x10);
    if (o->xc == 0) {
        o->x8 = 0;
        o->x0 = 7;
    } else {
        o->x8 = 2;
        lbl_80347854 = fn_801DB244(lbl_802D9F9C);
        fn_80227810(lbl_80347854->inner->list);
        fn_801CBC30();
        fn_801CBBD8();
        o->x18 = 1;
        o->x1c = 1;
        if (o->xc == 2) {
            o->x0 = 3;
            o->x14 = 1;
        } else {
            o->x0 = 2;
        }
    }
}

void fn_8022B8BC(s32 mode, void *val) {
    if (lbl_80310B3C.f88 & 0x10) {
        s32 r = fn_80212050();
        switch (mode) {
        case 0:
            lbl_802F92D8.f8 = val;
            fn_801228A0(r);
            break;
        case 1:
            lbl_802F92D8.f8 = val;
            fn_801228A0(r);
            break;
        default:
            lbl_802F92D8.f8 = val;
            fn_801228A0(r);
            break;
        }
    }
}

void fn_8022B960(void *p)
{
    lbl_80347EB4 = lbl_80347EB0;
    lbl_80347EA8 = 1;
    njUnitMatrix(0);
    fn_8028BAEC(p);
}
void fn_8022B9A8(void) {
    MemCopy(&lbl_803119E0, lbl_80316810, 0x20);
}

void fn_8022B9DC(void) {
    MemCopy(lbl_80316810, &lbl_803119E0, 0x20);
}

s32 fn_8022BA10(void *a, void *b)
{
    s32 x = fn_801DCFA0(b, a);
    return (0 <= x) ? (u16)-x : 0;
}

s32 fn_8022BA58(void *a, void *b)
{
    s32 x = fn_801DD078(b, a);
    return (0 <= x) ? (u16)-x : 0;
}

s32 fn_8022BAA0(Angle* ang, NJS_POINT3* a, NJS_POINT3* b, NJS_POINT3* v) {
    NJS_POINT3 d;
    s32 r;

    d.x = a->x - b->x;
    d.y = a->y - b->y;
    d.z = a->z - b->z;
    fn_801DD5E8(ang, &d);
    if (ang[0] < 0) {
        ang[0] = 0;
    }
    if (ang[1] < 0) {
        ang[1] = 0;
    }
    r = fn_801DD078(v, &d);
    return 0 <= r ? AngNeg(r) : 0;
}

void fn_8022BB5C(void *a, s32 b, s32 c, s32 d)
{
    njRotateZXY(a, lbl_80311970.f1c + b, lbl_80311970.f20 + c, d);
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

void fn_8022BC24(void *a, s32 b, s32 c, s32 d)
{
    njRotateZXY(a, lbl_80311970.f1c + b, lbl_80311970.f20 + c, lbl_80311970.f34 + d);
}

void fn_8022BC64(void)
{
    s32 v;
    lbl_803118AC.z = 500.0f;
    lbl_803118AC.x28 = 640.0f;
    lbl_803118AC.x2c = 480.0f;
    lbl_803118AC.x08 = 320.0f;
    lbl_803118AC.x0c = 240.0f;
    v = (s32)(10430.381f * (f32)atan2(320.0, 500.0));
    lbl_80347570 = 0.005493164f * (f32)((v << 1) & 0xffff);
    njSetScreen(&lbl_803118AC);
    lbl_803119E0.x1a = (s16)(182.04445f * lbl_80347570);
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

#ifdef NONMATCHING
s32 fn_8022BDD0(AngObj_8022BDD0* dst, AngObj_8022BDD0* a, AngObj_8022BDD0* b, Lim_8022BDD0* lim) {
    f32 dx, dy, dz;
    f32 nbx, nax, nay, nby, naz, nbz;
    f32 bx, by, bz;
    f32 ax, ay, az;
    s32 ok;

    ok = 1;
    ax = 0.005493164f * (a->x & 0xffff);
    ay = 0.005493164f * (a->y & 0xffff);
    az = 0.005493164f * (a->z & 0xffff);
    bx = 0.005493164f * (b->x & 0xffff);
    by = 0.005493164f * (b->y & 0xffff);
    bz = 0.005493164f * (b->z & 0xffff);
    nax = ax;
    nbx = bx;
    if (nax >= 360.0f || nax <= -360.0f) {
        nax = (s32)nax % 360 + fn_802917A0(nax);
    }
    if (nbx >= 360.0f || nbx <= -360.0f) {
        nbx = (s32)nbx % 360 + fn_802917A0(nbx);
    }
    dx = nax - nbx;
    nby = by;
    nay = ay;
    if (nay >= 360.0f || nay <= -360.0f) {
        nay = (s32)nay % 360 + fn_802917A0(nay);
    }
    if (nby >= 360.0f || nby <= -360.0f) {
        nby = (s32)nby % 360 + fn_802917A0(nby);
    }
    dy = nay - nby;
    nbz = bz;
    naz = az;
    if (naz >= 360.0f || naz <= -360.0f) {
        naz = (s32)naz % 360 + fn_802917A0(naz);
    }
    if (nbz >= 360.0f || nbz <= -360.0f) {
        nbz = (s32)nbz % 360 + fn_802917A0(nbz);
    }
    dz = naz - nbz;
    if (fabsf(dx) > lim->step) {
        if (dx > 0.0f) {
            ax = bx + lim->step;
        } else {
            ax = bx - lim->step;
        }
        ok = 0;
    }
    if (fabsf(dy) > lim->step) {
        if (dy > 0.0f) {
            ay = by + lim->step;
        } else {
            ay = by - lim->step;
        }
        ok = 0;
    }
    if (fabsf(dz) > lim->step) {
        if (dz > 0.0f) {
            az = bz + lim->step;
        } else {
            az = bz - lim->step;
        }
        ok = 0;
    }
    dst->x = 182.04445f * ax;
    dst->y = 182.04445f * ay;
    dst->z = 182.04445f * az;
    return ok;
}
#endif

s32 fn_8022C364(NJS_POINT3 *out, NJS_POINT3 *a, NJS_POINT3 *b, Lim_8022C364 *lim) {
    NJS_VECTOR d;
    s32 ret = 0;
    d.x = a->x - b->x;
    d.y = a->y - b->y;
    d.z = a->z - b->z;
    if (njScalor(&d) > lim->r) {
        njUnitVector(&d);
        out->x = d.x * lim->r;
        out->y = d.y * lim->r;
        out->z = d.z * lim->r;
        out->x = b->x + out->x;
        out->y = b->y + out->y;
        out->z = b->z + out->z;
    } else {
        ret = 1;
        out->x = a->x;
        out->y = a->y;
        out->z = a->z;
    }
    return ret;
}

void fn_8022C46C(Vec *p, Vec *base, f32 r) {
    Vec d;
    f32 dy;
    d.x = p->x - base->x;
    dy = p->y - base->y;
    d.y = dy;
    d.z = p->z - base->z;
    d.y = 0.0f;
    if (njScalor(&d) < r) {
        njUnitVector(&d);
        p->x = d.x * r;
        p->y = d.y * r;
        p->z = d.z * r;
        p->y = dy;
        p->x += base->x;
        p->y += base->y;
        p->z += base->z;
    }
}

void fn_8022D1F8(NJS_POINT3 *out, Spec *s, Angle *rot) {
    NJS_MATRIX m;
    NJS_POINT3 v;
    NJS_POINT3 r;
    f32 k;
    if (0.0f != s->amp1 || 0.0f != s->amp2) {
        njUnitMatrix(m);
        njRotateXYZ(m, rot[0], rot[1], rot[2]);
        v.z = 0.0f;
        if (0.0f != s->amp1) {
            v.x = 0.0f;
            v.y = 1.0f;
            njCalcVector(m, &v, &r);
            k = s->amp1 * njCos(s->ang1);
            out->x += r.x * k;
            out->y += r.y * k;
            out->z += r.z * k;
        }
        if (0.0f != s->amp2) {
            v.y = 0.0f;
            v.x = 1.0f;
            njCalcVector(m, &v, &r);
            k = s->amp2 * njCos(s->ang2);
            out->x += r.x * k;
            out->y += r.y * k;
            out->z += r.z * k;
        }
    }
}
