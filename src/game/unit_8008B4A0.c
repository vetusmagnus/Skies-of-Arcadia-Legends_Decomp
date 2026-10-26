#include "types.h"
#include "ninja.h"

typedef struct Ent_UNIT0000 {
    u8 pad[0x1C];
    u32 x1c;
} Ent_UNIT0000;
extern s8 lbl_80347340;
typedef struct Chr {
    u8 pad[0x10];
    u32 x10;
} Chr;
extern Chr* lbl_80309DE4[12];
typedef struct Tm {
    u8 pad[0x14];
    s32 x14;
    s32 x18;
} Tm;
extern u32 lbl_80347494;
extern s32 lbl_80346C28;
extern void fn_800E3594(void);
extern s32 lbl_80346DD4;
typedef struct Rec {
    u8 pad[0x12C];
    s16 x12c;
} Rec;
typedef struct FindEntry {
    struct FindEntry *prev;
    struct FindEntry *next;
    s32 value;
    u8 pad_0c[4];
    s16 id;
} FindEntry;
extern FindEntry *lbl_80302D78[12];
extern FindEntry *fn_8008F2CC(FindEntry *head, s16 id);
extern void fn_801DD5E8(Angle *out, NJS_POINT3 *p);
extern f32 fn_80291A5C(f32 x);
typedef struct {
    u8 pad_00[0x10];
    f32 f[3];
    u32 w[3];
} Table8009539C;
extern Table8009539C lbl_80311970;
typedef struct {
    u8 mode;
    u8 flags;
    s16 field2;
    u8 pad_04[0x70 - 4];
} SeFlagBlock;
extern s16 lbl_80346C3C;
extern s16 lbl_80302F18[408];
extern SeFlagBlock lbl_802E0084;
s32 fn_80078610(s8 idx);
typedef struct {
    u8 pad[0x10];
    void* fn; /* 0x10 */
} Inner;
void fn_800804B8(void);
void fn_8008DEEC(void);
extern s16 lbl_80347374;
typedef struct {
    NJS_TEXLIST* texlist; /* 0x00 */
    void* obj;            /* 0x04 */
    f32 tx, ty, tz;       /* 0x08 */
    Angle rx, ry, rz;     /* 0x14 */
    f32 sx, sy, sz;       /* 0x20 */
} Xform;
void fn_80299040(NJS_TEXLIST* texlist);
void njPushMatrixEx(void);
void njPopMatrixEx(void);
void fn_80286EE8(void);
void fn_8028B498(void);
void fn_80288FC8(void* obj);
void njTranslate(NJS_MATRIX m, f32 x, f32 y, f32 z);
void njScale(NJS_MATRIX m, f32 x, f32 y, f32 z);
void fn_801E7E14(s32 a, s16 b, s16 c, s32 mode);
typedef struct {
    s32 x; /* 0x00 */
    s32 y; /* 0x04 */
    s32 z; /* 0x08 */
} Src;
typedef struct {
    f32 x; /* 0x00 */
    f32 y; /* 0x04 */
    f32 z; /* 0x08 */
} Vec3F;
f32 fn_802918DC(f32 x);
extern void* lbl_80347450;
s32 fn_8015F1F0(void* p);
void fn_801DD3B8(void* a, void* b, void* c);
typedef struct { f32 x, y, z; } Vec3_8008B600;
typedef struct { u8 pad[0x1c]; Vec3_8008B600 v; } Sub_8008B600;
typedef struct { u8 pad[0x24]; Sub_8008B600 *x24; } Ent_8008B600;
extern Ent_8008B600 *fn_80021658(s8 idx);
extern s32 fn_80078610(s8 idx);
extern f32 fn_80071E9C(void*a, void*b);
typedef struct { s16 x0; } SubD;
typedef struct { u8 pad[0x19]; u8 x19; u8 pad1[0x24 - 0x1a]; SubD *x24; } ObjD;
typedef struct { void (*x0)(void); u8 pad[0x19 - 4]; u8 x19; u8 pad1[0x24 - 0x1A]; Inner *inner; } Slot;
extern Slot *lbl_80309700[12];
extern void fn_800811E4(s32 idx, s32 b);
extern s32 fn_8007FFE8(s32 idx, s32 b);
extern void fn_8008C6BC(void);
extern void *lbl_80302D48[12];
extern void fn_801E17E0(void *p);
typedef struct Vec3_8009009C { f32 x; f32 y; f32 z; } Vec3_8009009C;
extern f32 lbl_80348B38;
void fn_80095220(void *obj, f32 *a, f32 *b);

u32 fn_8008B55C(void* a0, Ent_UNIT0000* e) {
    return (e->x1c >> 9) & 1;
}

s32 fn_8008B568(void) {
    return lbl_80347340 == 8;
}

s32 fn_8008B580(void) {
    return lbl_80347340 == 4;
}

s32 fn_8008B598(void) {
    return lbl_80347340 == 3;
}

s32 fn_8008B5B0(void) {
    return lbl_80347340 == 2;
}

s32 fn_8008B5C8(void) {
    return lbl_80347340 == 1;
}

u32 fn_8008B910(s32 i) {
    return (lbl_80309DE4[i]->x10 >> 1) & 1;
}

u32 fn_8008B92C(s32 i) {
    return lbl_80309DE4[i]->x10 & 1;
}

s32 fn_8008B948(void* a0, Tm* t) {
    return (t->x18 / 10) >= t->x14;
}

s32 fn_8008B97C(void* a0, Tm* t) {
    return !((t->x18 / 4) < t->x14);
}

s32 fn_8008B9A0(void* a0, Tm* t) {
    return !((t->x18 / 2) < t->x14);
}

s32 fn_8008B9C8(void* a0, Tm* t) {
    return t->x18 == t->x14;
}

void fn_8008F288(s16 slot, s16 id, s32 value) {
    FindEntry *e = fn_8008F2CC(lbl_80302D78[slot], id);
    e->value = value;
}

u32 fn_8008F980(void) {
    u32 v = lbl_80347494;
    lbl_80347494 = v + 1;
    if (v > 0xffdc) {
        lbl_80347494 = 0x10000 - 0x218;
    }
    return lbl_80347494;
}

void fn_8008F9A8(void) {
    lbl_80347494 = 0x10000 - 0x218;
}

s32 fn_8008FC48(void) {
    return lbl_80346C28;
}

s32 fn_80090D78(void) {
    fn_800E3594();
    return lbl_80346DD4;
}

void fn_80090F9C(Angle *out, NJS_POINT3 *a, NJS_POINT3 *b) {
    NJS_POINT3 d;
    d.x = a->x - b->x;
    d.y = a->y - b->y;
    d.z = a->z - b->z;
    fn_801DD5E8(out, &d);
}

f32 fn_80090FF0(NJS_POINT3 *a, NJS_POINT3 *b) {
    f32 dx = a->x - b->x;
    f32 dy = a->y - b->y;
    f32 dz = a->z - b->z;
    return fn_80291A5C(dz * dz + (dx * dx + dy * dy));
}

s32 fn_800912A8(s32 a, s32 b, s32 c, s32 d) {
    s32 e = (u16)(a + (0x8000 - (u16)b)) - 0x8000;
    s32 q;

    if (e == 0) {
        return a;
    }
    if (e < 0) {
        e = -e;
        c = -c;
    }
    if (d <= e) {
        return b + c;
    }
    q = c * e / d;
    return q ? b + q : a;
}

void fn_8009539C(f32 *out_f, u32 *out_w) {
    out_f[0] = lbl_80311970.f[0];
    out_f[1] = lbl_80311970.f[1];
    out_f[2] = lbl_80311970.f[2];
    out_w[0] = (u16)lbl_80311970.w[0];
    out_w[1] = (u16)lbl_80311970.w[1];
    out_w[2] = (u16)lbl_80311970.w[2];
}

s32 fn_8009574C(void) {
    s32 ret = 0;
    if (lbl_80346C3C == 2) {
        if (lbl_80302F18[0] == 0xc) {
            lbl_802E0084.mode = 0xf;
            lbl_802E0084.field2 = 0;
            ret = 1;
        }
    }
    return ret;
}

void fn_80096230(Rec* r) {
    r->x12c = 7;
}

s32 fn_8008B4F8(s32 x) {
    s32 i;
    for (i = 4; i <= 11; i++) {
        if (i != x && fn_80078610((s8)i)) return 0;
    }
    return 1;
}

void fn_8008E2B0(s32 n) {
    s32 i;
    for (i = 0; i < 12; i++) {
        if (i != n && fn_80078610((s8)i)) {
            lbl_80309700[i]->inner->fn = (void*)fn_800804B8;
        }
    }
}

void fn_8008E338(s32 n) {
    s32 i;
    for (i = 0; i < 12; i++) {
        if (i != n && fn_80078610((s8)i)) {
            lbl_80309700[i]->inner->fn = (void*)fn_8008DEEC;
            lbl_80347374 |= 1 << i;
        }
    }
}

void fn_80090664(Xform* o) {
    fn_80299040(o->texlist);
    njPushMatrixEx();
    fn_80286EE8();
    fn_8028B498();
    njTranslate(0, o->tx, o->ty, o->tz);
    njRotateXYZ(0, o->rx, o->ry, o->rz);
    njScale(0, o->sx, o->sy, o->sz);
    fn_80288FC8(o->obj);
    njPopMatrixEx();
}

void fn_80090A20(s32 a, s16 x, s16 y) {
    if (x && y) {
        fn_801E7E14(a, x, y, 2);
    } else if (x) {
        fn_801E7E14(a, x, y, 0);
    } else if (y) {
        fn_801E7E14(a, x, y, 1);
    }
}

void fn_80090B68(Src* s, f32* d) {
    d[0] = (2400.0f * -(f32)s->x + 8400.0f) - 1200.0f;
    d[1] = 0.0f;
    d[2] = (2400.0f * -(f32)s->z + 7200.0f) - 1200.0f;
}

void fn_80090D20(Vec3F* s, s32* out) {
    out[0] = (s32)((8400.0f - s->x) / 2400.0f);
    out[1] = 0;
    out[2] = (s32)((7200.0f - s->z) / 2400.0f);
}

s32 fn_80091228(s32 base, s32 val, f32 scale) {
    u16 d = (u16)(base + (0x8000 - (u16)val));
    s32 v = (s32)d - 0x8000;
    if (v == 0) return base;
    return val + (s32)fn_802918DC((f32)v / scale);
}

void fn_8009519C(void* a, void* b) {
    u8* p = (u8*)lbl_80347450;
    if (p) {
        if (fn_8015F1F0(p)) {
            u8* q = *(u8**)(p + 0x1d8);
            if (q) {
                u8* r = *(u8**)(q + 8);
                if (r) p = r;
            }
        }
        fn_801DD3B8(a, b, p + 0x44);
    }
}

s32 fn_8008B600(s32 a) {
    s32 i;
    Vec3_8008B600 A;
    Vec3_8008B600 B;
    Sub_8008B600 *s;
    s = fn_80021658(a)->x24;
    A.x = s->v.x;
    A.y = s->v.y;
    A.z = s->v.z;
    for (i = 0; i <= 3; i++) {
        if (fn_80078610(i)) {
            s = fn_80021658(i)->x24;
            B.x = s->v.x;
            B.y = s->v.y;
            B.z = s->v.z;
            if (fn_80071E9C(&A, &B) >= 45.0f) {
                return 1;
            }
        }
    }
    return 0;
}

s32 fn_8008B788(s32 a) {
    s32 i;
    Vec3_8008B600 A;
    Vec3_8008B600 B;
    Sub_8008B600 *s;
    s = fn_80021658(a)->x24;
    A.x = s->v.x;
    A.y = s->v.y;
    A.z = s->v.z;
    for (i = 0; i <= 3; i++) {
        if (fn_80078610(i)) {
            s = fn_80021658(i)->x24;
            B.x = s->v.x;
            B.y = s->v.y;
            B.z = s->v.z;
            if (fn_80071E9C(&A, &B) <= 45.0f) {
                return 0;
            }
        }
    }
    return 1;
}

void fn_8008D610(ObjD *o) {
    s32 idx;
    idx = o->x24->x0;
    switch (o->x19) {
    case 0:
        fn_800811E4(idx, 0);
        o->x19 = 1;
    case 1:
        if (fn_8007FFE8(idx, 0)) {
            lbl_80309700[idx]->x0 = fn_8008C6BC;
            lbl_80309700[idx]->x19 = 0;
        }
        break;
    }
}

s32 fn_8008F508(s16 idx, s16 id) {
    FindEntry *e;
    if (lbl_80302D78[idx] == 0) {
        return 0;
    }
    e = fn_8008F2CC(lbl_80302D78[idx], id);
    if (e == 0) {
        return 0;
    }
    if (e->prev == 0) {
        if (e->next == 0) {
            lbl_80302D78[idx] = 0;
            fn_801E17E0(lbl_80302D48[idx]);
            lbl_80302D48[idx] = 0;
        } else {
            lbl_80302D78[idx] = e->next;
            lbl_80302D78[idx]->prev = 0;
        }
    } else {
        e->prev->next = e->next;
    }
    fn_801E17E0(e);
    return 1;
}

void fn_8009009C(Vec3_8009009C *v, f32 s) {
    f32 k;
    if (lbl_80348B38 == v->x && lbl_80348B38 == v->y && lbl_80348B38 == v->z) {
        v->x = s;
        return;
    }
    k = s / fn_80291A5C(v->z * v->z + (v->x * v->x + v->y * v->y));
    v->x = v->x * k;
    v->y = v->y * k;
    v->z = v->z * k;
}

f32 fn_80090EEC(void *obj, f32 t) {
    f32 v3[3];
    f32 v2[3];
    f32 v1[3];
    f32 v0[3];
    f32 x;
    f32 y;
    f32 z;
    fn_80095220(obj, v3, v2);
    fn_801DD3B8(v1, v0, v2);
    x = v0[0] * t + v3[0];
    y = v0[1] * t + v3[1];
    z = v0[2] * t + v3[2];
    v1[0] = lbl_80311970.f[0] - x;
    v1[1] = lbl_80311970.f[1] - y;
    v1[2] = lbl_80311970.f[2] - z;
    return v1[0] * v1[0] + v1[1] * v1[1] + v1[2] * v1[2];
}

s32 fn_80094C34(u8 *p) {
    s32 r = 0;
    s16 a = *(s16 *)(p + 0x16);
    if (a == 0) {
        goto L68;
    }
    if (*(s16 *)(p + 0x14) != 0) {
        goto L68;
    }
    if ((*(u16 *)(p + 0x1a) & 0x1800) != 0x1800) {
        r = 1;
    }
    goto end;
L68:
    if (a == 0) {
        goto end;
    }
    if (*(s16 *)(p + 0x14) == 0) {
        goto end;
    }
    if ((*(u16 *)(p + 0x1a) & 0x400) != 0) {
        r = 1;
        goto end;
    }
    if ((*(u16 *)(p + 0x1a) & 0x1800) == 0x1800) {
        goto end;
    }
    if (5.0f < *(f32 *)(p + 0xc) - *(f32 *)(p + 0x4)) {
        r = 1;
        goto end;
    }
    if ((*(u16 *)(p + 0x18) & 0x400) != 0) {
        r = 1;
        goto end;
    }
    if (5.0f < *(f32 *)(p + 0x4) - *(f32 *)(p + 0x10)) {
        r = 1;
    }
end:
    return r;
}
