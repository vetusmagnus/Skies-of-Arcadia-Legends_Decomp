#include "types.h"

void fn_80153270(void *p);
void fn_80155CD8(void);
void fn_80155D74(void);
void *memcpy(void *dst, const void *src, u32 n);
extern u8 lbl_80306758[];
void *memset(void *p, s32 c, u32 n);
extern u8 *lbl_80346FB8;
extern s32 lbl_80346FE8;
void fn_801E17E0(s32 x);
extern void *lbl_80346FAC;
void fn_80150CB0(void *a, void *b);
void *fn_8015C4D8(void *p);
void fn_80144680(void *p);
extern s32 lbl_8034704C;
void fn_801453D0(void);

void fn_8014F970(u8 *self) {
    fn_80153270(self + 0x95c);
    fn_80155CD8();
    fn_80155D74();
}

void fn_8014FCD8(u8 *base, s32 i, u16 v) {
    u8 *e = base + i * 0xa8;
    *(u16 *)(e + 0x48) = v;
    *(u16 *)(e + 0x4a) = 0;
}

void fn_801515EC(u8 *p) {
    *(u32 *)(p + 0x168) = 0;
}

void fn_801515F8(u8 *p, u32 a, u32 b, u32 c, u32 d, u32 e) {
    *(u32 *)(p + 0x154) = b;
    *(u32 *)(p + 0x158) = a;
    *(u32 *)(p + 0x160) = c;
    *(u32 *)(p + 0x15c) = d;
    *(u32 *)(p + 0x164) = e;
}

void fn_801517EC(u8 *p) {
    memcpy(p + 0x34, p + 4, 0x30);
}

void fn_8015181C(u8 *p) {
    memcpy(p + 4, p + 0x34, 0x30);
}

void fn_80152EE8(u8 *p, u32 v) {
    *(u32 *)(p + 0x48) = v;
}

void fn_801534E8(void) {
    memset(lbl_80306758, 0, 0x50);
}

u8 fn_80153DA8(s32 i) {
    u8 *b = lbl_80346FB8;
    return (i + b)[4];
}

void fn_80153DB8(s32 i, u8 v) {
    u8 *b = lbl_80346FB8;
    (i + b)[4] = v;
}

void fn_801558EC(void) {
    fn_801E17E0(lbl_80346FE8);
}

void fn_80155944(void *p) {
    fn_80150CB0(lbl_80346FAC, p);
}

void fn_80155A8C(void *p) {
    memset(p, 0, 0x14);
}

void fn_8015823C(u8 *p) {
    *(u32 *)(p + 0) = 0;
    *(u16 *)(p + 6) = 0;
    *(u16 *)(p + 4) = 0;
}

void fn_80158358(u8 *p, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f) {
    *(u32 *)(p + 0x10) = a;
    *(u32 *)(p + 0x8) = b;
    *(u32 *)(p + 0xc) = e;
    *(u32 *)(p + 0x3c) = c;
    *(u32 *)(p + 0x40) = d;
    *(u32 *)(p + 0x44) = f;
}

void fn_8015C5F4(void *p) {
    fn_80144680(fn_8015C4D8(p));
}

void fn_8015C6C8(void) {
    lbl_8034704C = 0;
    fn_801453D0();
}

s32 fn_8015CF8C(u8 *p, u8 *q) {
    u32 v = *(u32 *)(q + 0x1c);
    u8 *dst = *(u8 **)(p + 0x1d8);
    *(u16 *)(dst + 0x18) = v;
    return 0;
}

s32 fn_8015D688(void *unused, u8 *q) {
    s32 v = *(s32 *)(q + 0x1c) - 1;
    *(s32 *)(q + 0x1c) = v;
    return v != 0;
}

s32 fn_8015DC54(u8 *p) {
    u32 *flags = *(u32 **)(p + 0x1d8);
    *flags &= ~0x80;
    return 0;
}
