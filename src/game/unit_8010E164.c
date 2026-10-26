#include "types.h"

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
extern void MemCopy(void *dst, const void *src, u32 n);
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

void fn_8011BAA4(u8 *p) {
    lbl_80346EB0 = p;
    if (!(p[0x18] & 0x20)) {
        return;
    }
    lbl_80346EB4 = 0;
    lbl_80346EB0 = 0;
    p[0x18] |= 0x40;
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

void fn_80124390(u8 *p) {
    u8 *src = *(u8 **)(*(u8 **)(p + 0x1d8) + 0x8);
    MemCopy(p + 0x38, src + 0x38, 0x24);
}

void fn_801243C4(u8 *p) {
    fn_8014FA10(*(u8 **)(p + 0x23c) + 0xf0);
}

void fn_80126E1C(u8 *p, u8 v) {
    p[7] = v;
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
