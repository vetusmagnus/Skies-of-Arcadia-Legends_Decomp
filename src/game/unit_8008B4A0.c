#include "types.h"
#include "ninja.h"

typedef struct Ent {
    u8 pad[0x1C];
    u32 x1c;
} Ent;
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
    u8 pad_00[4];
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

u32 fn_8008B55C(void* a0, Ent* e) {
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
