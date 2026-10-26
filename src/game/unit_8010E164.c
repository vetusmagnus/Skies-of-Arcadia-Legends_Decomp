#include "types.h"
#include "game/util.h"
#include "ninja.h"

extern void fn_80117748(void);
extern void fn_80114C84(void *a, void *b, void *c, void *d, void *e, void *f);
extern void fn_80114A44(void);
extern void fn_80114AB8(void);
extern s32 lbl_80346E80;
extern s32 fn_801161B4(void);
extern u8 lbl_802E54B0[];
typedef struct {
    u8 pad0[0x2c];
    f32 f2c; /* 0x2C */
    u8 pad30[0xa4 - 0x30];
} Entry;
typedef struct {
    s32 type;   /* 0x00 */
    void *ptr;  /* 0x04 */
    f32 a;      /* 0x08 */
    f32 b;      /* 0x0C */
    f32 c;      /* 0x10 */
    f32 d;      /* 0x14 */
    f32 e;      /* 0x18 */
    f32 f;      /* 0x1C */
} Req;
extern Req lbl_8030A380;
extern f32 lbl_80349E90;
extern void fn_80109E7C(const char *s, s32 n);
extern char lbl_802B31A8[];
extern void *lbl_80346EB0;
extern void *lbl_80346EB4;
extern s32 lbl_803473B4;
extern s32 lbl_803473B0;
extern s32 TaskDelete(void *task);
extern void *lbl_80346EC0;
extern void fn_8014FA10(void *p);
extern u8 *lbl_803472A8;
extern u8 *lbl_803472CC;
extern f32 lbl_8034A398;
extern f32 lbl_803472DC;
extern f32 lbl_8034A380;
extern f32 lbl_8034A3A4;
extern f32 lbl_803472E0;
extern f32 lbl_80346EE4;
extern u8 lbl_80311AC0[];
void fn_802238E4(void *dst, void *src, s32 n);
s32 fn_802254A0(s32 a);
void fn_80123CBC(void);
void *fn_802267AC(void *a, void *b);
void *fn_801E1C7C(s32 size);
extern void *lbl_803475A0;
extern u8 lbl_80310A1C[0x120];
void fn_801248C4(s32 a, u8 *obj, s32 flag);
void fn_8020EFD4(s32 v);
void fn_80156C6C(NJS_MATRIX m, void *a);
void fn_8014F99C(void *b, NJS_MATRIX m);
void fn_8014FA10(void *m);
void fn_80127BC0(void *self);
s32 fn_801CC5BC(void *a);
void fn_801CC65C(void *a);
void fn_80218D84(void *a, s32 b, s32 c);
extern void *lbl_80346ED8;
extern s32 lbl_80346ED4;
extern s32 lbl_80346ED0;
extern u8 lbl_80305F60[0x20];
void fn_8012C060(void);
void fn_80133144(void);
void fn_801323F0(void);
void fn_801316CC(void);
void fn_80130368(void);
void fn_8012F744(void);
void fn_8012F490(void);
void fn_8012E5D8(void);
void fn_8012C660(void);
void fn_8012AEE8(void);
void fn_8012AA8C(void);

void fn_8010E164(u8 *obj) {
    if (obj[0x19] == 0xff) {
        fn_80117748();
    }
}

void fn_801150DC(void *a, void *b, void *c, void *d) {
    fn_80114C84(a, b, c, d, fn_80114A44, fn_80114AB8);
}

void fn_80116020(s32 n) {
    lbl_80346E80 = n;
}

f32 fn_80116028(void) {
    s32 i = fn_801161B4();
    return ((Entry *)lbl_802E54B0)[i].f2c;
}

void fn_801165C4(u8 *self) {
    fn_802238E4(self + 0x38, self + 0x38, *(s32 *)(self + 0x1b8));
    MemCopy(self + 0x104, self + 0x38, 0x24);
}

s32 fn_8011698C(s32 a, u8 *obj) {
    s32 r = fn_802254A0(a);
    if (r == 1 && (*(u16 *)(obj + 0x24) & 0x4800) == 0x4800) {
        r = 0;
    }
    return r;
}

void fn_80118540(void) {
    f32 big = 3.4028235e38f;
    s32 mx = 0x80000000;
    mx -= 1;
    lbl_8030A380.type = 0;
    lbl_8030A380.ptr = (void *)mx;
    lbl_8030A380.a = big;
    lbl_8030A380.b = big;
    lbl_8030A380.c = big;
    lbl_8030A380.d = big;
    lbl_8030A380.e = big;
    lbl_8030A380.f = big;
}

void fn_80118578(void *ptr, f32 f1, f32 f2, f32 f3, f32 f4) {
    lbl_8030A380.type = 1;
    lbl_8030A380.ptr = ptr;
    lbl_8030A380.a = f1;
    lbl_8030A380.b = f2;
    lbl_8030A380.c = f3;
    lbl_8030A380.d = lbl_80349E90;
    lbl_8030A380.e = f4;
    lbl_8030A380.f = lbl_80349E90;
}

void fn_801185A8(void *ptr, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5, f32 f6) {
    lbl_8030A380.type = 2;
    lbl_8030A380.ptr = ptr;
    lbl_8030A380.a = f1;
    lbl_8030A380.b = f2;
    lbl_8030A380.c = f3;
    lbl_8030A380.d = f4;
    lbl_8030A380.e = f5;
    lbl_8030A380.f = f6;
}

void fn_8011A2A8(void) {
    fn_80109E7C(lbl_802B31A8, 0x7fff);
}

void fn_8011B238(s32 a, ...) {
}

void fn_8011BAA4(u8 *p) {
    lbl_80346EB0 = p;
    if (!(p[0x18] & 0x20)) {
        return;
    }
    lbl_80346EB4 = 0;
    lbl_80346EB0 = 0;
    p[0x18] |= 0x40;
}

void fn_80120A50(f32 *out, const f32 *a, const f32 *b, f32 t) {
    f32 az = a[2];
    f32 bz = b[2];
    f32 ax = a[0];
    f32 ay = a[1];
    f32 by = b[1];
    f32 bx = b[0];
    out[2] = az + t * (bz - az);
    out[1] = ay + t * (by - ay);
    out[0] = ax + t * (bx - ax);
}

void fn_80123E8C(void) {
    lbl_803473B4 = 1;
    lbl_803473B0 = 1;
}

void fn_80123E9C(void) {
    lbl_803473B4 = 1;
    lbl_803473B0 = 0;
}

void fn_80123EB0(void) {
    if (lbl_80346EC0 != 0) {
        TaskDelete(lbl_80346EC0);
    }
    lbl_80346EC0 = 0;
}

void fn_80123EE4(void) {
    lbl_803473B4 = 0;
    lbl_803473B0 = 0;
    lbl_80346EC0 = fn_802267AC(lbl_803475A0, fn_80123CBC);
    *(void **)((u8 *)lbl_80346EC0 + 0x24) = fn_801E1C7C(0x20);
}

void fn_80124390(u8 *p) {
    u8 *src = *(u8 **)(*(u8 **)(p + 0x1d8) + 0x8);
    MemCopy(p + 0x38, src + 0x38, 0x24);
}

void fn_801243C4(u8 *p) {
    fn_8014FA10(*(u8 **)(p + 0x23c) + 0xf0);
}

s32 fn_801243EC(s32 a) {
    if (a == 0x1c) {
        return 1;
    }
    if (a == 0x1d) {
        if ((s8)lbl_80310A1C[0xc0] == 0) {
            return 2;
        }
    }
    return 0;
}

void fn_80124870(s32 a, u8 *obj) {
    switch (obj[4]) {
    case 0x18:
        fn_801248C4(a, obj, 1);
        if (*(s16 *)(obj + 0x34) == 1) {
            fn_8020EFD4(0x74cc);
        }
        break;
    }
}

void fn_80126408(void *a, void *b) {
    NJS_MATRIX m;
    njUnitMatrix(m);
    fn_80156C6C(m, a);
    fn_8014F99C(b, m);
}

void fn_8012645C(u8 *self) {
    u8 *p = *(u8 **)(self + 0x23c);
    if (p != 0) {
        fn_8014FA10((u8 *)*(void **)(p + 4) + 0x80);
        fn_80127BC0(self);
    }
}

void fn_80126E1C(u8 *p, u8 v) {
    p[7] = v;
}

s32 fn_80128F2C(void) {
    s32 r;
    if (fn_801CC5BC(lbl_80346ED8) != 2) {
        r = 0;
    } else {
        fn_801CC65C(lbl_80346ED8);
        fn_80218D84(lbl_80305F60, lbl_80346ED4, lbl_80346ED0);
        r = 1;
    }
    return r;
}

void *fn_801298CC(void) {
    u8 *inner = *(u8 **)(lbl_803472A8 + 0x8);
    return lbl_803472CC + (*(u16 *)(inner + 0x46) << 2);
}

void fn_80129988(void) {
    lbl_803472DC = lbl_8034A398;
}

void fn_801299A0(void) {
    lbl_803472E0 = lbl_8034A380;
    lbl_80346EE4 = lbl_8034A3A4;
}

s32 fn_8012A8DC(void) {
    s32 v = *(s32 *)(lbl_80311AC0 + 0x4);
    return v >= 500;
}

void fn_8012A9FC(void) {
    fn_8012C060();
    fn_80133144();
    fn_801323F0();
    fn_801316CC();
    fn_80130368();
    fn_8012F744();
    fn_8012F490();
    fn_8012E5D8();
    fn_8012C660();
    fn_8012AEE8();
    fn_8012AA8C();
}
