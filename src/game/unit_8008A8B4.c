#include "types.h"

typedef struct Slot {
    s16 id;
    u8 pad2[0xE];
    u32 x10;
    s32 a; /* 0x14 */
    s32 b; /* 0x18 */
    u32 flags; /* 0x1C */
} Slot;
extern Slot* lbl_80309DE4[12];
typedef struct Rec_8008AAD8 {
    u8 pad0[0x24];
    s16 x24;
    s16 x26;
} Rec_8008AAD8;
extern u8 lbl_8030B7F4[0x16A0];
typedef struct Rec_8008AEAC {
    u8 pad0[0x80];
    s16 x80;
} Rec_8008AEAC;
typedef struct Rec_8008AEDC {
    u8 pad0[0x80];
    s16 x80;
} Rec_8008AEDC;
extern u8 lbl_80347340;
s32 fn_8025ECC4(void);
extern s32 fn_80078610(s8 idx);
s32 fn_80078610(s8 idx);

s32 fn_8008A8B4(s32 i)
{
    Slot* e = lbl_80309DE4[i];
    if (e->x10 & 0x100) {
        e->x10 &= ~0x100;
        return 1;
    }
    return 0;
}

s32 fn_8008AAC8(s32 unused, s16* p)
{
    return *p == 0;
}

s32 fn_8008AAD8(s32 unused, Rec_8008AAD8* p)
{
    if (p->x24 == 1) {
        return 1;
    }
    return p->x26 == 1;
}

s32 fn_8008ACD0(s32 i)
{
    Slot* e = lbl_80309DE4[i];
    if (e->x10 & 0x100) {
        e->x10 &= ~0x100;
        return 1;
    }
    return 0;
}

s32 fn_8008AD6C(s32 i)
{
    Slot* e = lbl_80309DE4[i];
    if (e->x10 & 0x2000) {
        e->x10 &= ~0x2000;
        return 1;
    }
    return 0;
}

s32 fn_8008ADA0(s32 i)
{
    Slot* e = lbl_80309DE4[i];
    if (e->x10 & 0x100) {
        e->x10 &= ~0x100;
        return 1;
    }
    return 0;
}

s32 fn_8008ADD4(s32 i)
{
    Slot* e = lbl_80309DE4[i];
    if (e->x10 & 0x100) {
        e->x10 &= ~0x100;
        return 1;
    }
    return 0;
}

s32 fn_8008AE08(s32 i)
{
    return (lbl_80309DE4[i]->x10 & 0x8000) != 0;
}

s32 fn_8008AE24(s32 i)
{
    return (lbl_80309DE4[i]->x10 & 0x4000) != 0;
}

s32 fn_8008AE40(s32 i)
{
    Slot* e = lbl_80309DE4[i];
    if (e->x10 & 0x2000) {
        e->x10 &= ~0x2000;
        return 1;
    }
    return 0;
}

s32 fn_8008AE74(s32 i)
{
    return (lbl_80309DE4[i]->x10 & 0x1000) != 0;
}

s32 fn_8008AE90(s32 i)
{
    return (lbl_80309DE4[i]->x10 & 0x800) != 0;
}

s32 fn_8008AEAC(s32 unused, Rec_8008AEAC* p)
{
    s32 t = (s8)lbl_8030B7F4[0xB] - p->x80;
    return !(t < 8);
}

s32 fn_8008AEDC(s32 unused, Rec_8008AEDC* p)
{
    s32 t = (s8)lbl_8030B7F4[0xB] - p->x80;
    return !(t < 4);
}

s32 fn_8008AF0C(s32 i)
{
    return (lbl_80309DE4[i]->x10 & 0x400) != 0;
}

s32 fn_8008AF28(s32 i)
{
    return (lbl_80309DE4[i]->x10 & 0x200) != 0;
}

s32 fn_8008AF44(s32 i)
{
    Slot* e = lbl_80309DE4[i];
    if (e->x10 & 0x100) {
        e->x10 &= ~0x100;
        return 1;
    }
    return 0;
}

s32 fn_8008AF78(s32 i)
{
    Slot* e = lbl_80309DE4[i];
    if (e->x10 & 0x100) {
        e->x10 &= ~0x100;
        return 1;
    }
    return 0;
}

s32 fn_8008B0AC(void)
{
    return (s8)lbl_80347340 >= 5;
}

s32 fn_8008B0CC(s32 i)
{
    return (lbl_80309DE4[i]->x10 & 0x80) != 0;
}

s32 fn_8008B0E8(s32 i)
{
    return (lbl_80309DE4[i]->x10 & 0x40) != 0;
}

s32 fn_8008B104(s32 i)
{
    return (lbl_80309DE4[i]->x10 & 0x20) != 0;
}

s32 fn_8008B120(s32 i)
{
    return (lbl_80309DE4[i]->x10 & 0x10) != 0;
}

s32 fn_8008B13C(s32 i)
{
    return (lbl_80309DE4[i]->x10 & 0x8) != 0;
}

s32 fn_8008B158(s32 i)
{
    return (lbl_80309DE4[i]->x10 & 0x4) != 0;
}

s32 fn_8008B174(void) {
    return 1;
}

s32 fn_8008B17C(void) {
  s32 r = fn_8025ECC4() % 100;
  return !(r > 0x5a);
}

s32 fn_8008B1D0(void) {
  s32 r = fn_8025ECC4() % 100;
  return !(r > 0x50);
}

s32 fn_8008B224(void) {
  s32 r = fn_8025ECC4() % 100;
  return !(r > 0x46);
}

s32 fn_8008B278(void) {
  s32 r = fn_8025ECC4() % 100;
  return !(r > 0x3c);
}

int fn_8008B2CC(void) {
    return !(fn_8025ECC4() % 100 > 50);
}

int fn_8008B320(void) {
    return !(fn_8025ECC4() % 100 > 40);
}

int fn_8008B374(void) {
    return !(fn_8025ECC4() % 100 > 30);
}

int fn_8008B3C8(void) {
    return !(fn_8025ECC4() % 100 > 20);
}

int fn_8008B41C(void) {
    return !(fn_8025ECC4() % 100 > 10);
}

s32 fn_8008A8E8(void) {
    s32 i;
    s32 count = 0;
    for (i = 4; i <= 11; i++) {
        if (fn_80078610(i)) {
            count++;
        }
    }
    return !(3 - count);
}

s32 fn_8008A948(void) {
    s32 i;
    s32 count = 0;
    for (i = 0; i <= 3; i++) {
        if (fn_80078610(i)) {
            count++;
        }
    }
    return !(4 - count);
}

s32 fn_8008A9A8(void) {
    s32 i;
    s32 count = 0;
    for (i = 0; i <= 3; i++) {
        if (fn_80078610(i)) {
            count++;
        }
    }
    return !(3 - count);
}

s32 fn_8008AA08(void) {
    s32 i;
    s32 count = 0;
    for (i = 0; i <= 3; i++) {
        if (fn_80078610(i)) {
            count++;
        }
    }
    return !(2 - count);
}

s32 fn_8008AA68(void) {
    s32 i;
    s32 count = 0;
    for (i = 0; i <= 3; i++) {
        if (fn_80078610(i)) {
            count++;
        }
    }
    return !(1 - count);
}

s32 fn_8008AB00(void) {
    s32 i;
    for (i = 0; i <= 3; i++) {
        if (fn_80078610(i) && lbl_80309DE4[i]->id > 0) {
            return 1;
        }
    }
    return 0;
}

s32 fn_8008AB74(void) {
    s32 i;
    for (i = 0; i <= 3; i++) {
        if (fn_80078610(i) && (lbl_80309DE4[i]->flags & 0x200000)) {
            return 1;
        }
    }
    return 0;
}

s32 fn_8008ABE8(void) {
    s32 i;
    for (i = 0; i <= 3; i++) {
        if (fn_80078610(i) && (lbl_80309DE4[i]->flags & 0x100000)) {
            return 1;
        }
    }
    return 0;
}

s32 fn_8008AC5C(void) {
    s32 i;
    for (i = 0; i <= 3; i++) {
        if (fn_80078610(i) && !(lbl_80309DE4[i]->flags & 0x80000)) {
            return 0;
        }
    }
    return 1;
}

s32 fn_8008AFAC(void) {
    s32 i;
    for (i = 4; i <= 11; i++) {
        if (fn_80078610((s8)i)) {
            Slot* e = lbl_80309DE4[i];
            if (e->b >= e->a * 4) return 1;
        }
    }
    return 0;
}

s32 fn_8008B02C(void) {
    s32 i;
    for (i = 4; i <= 11; i++) {
        if (fn_80078610((s8)i)) {
            Slot* e = lbl_80309DE4[i];
            if (e->b >= e->a * 2) return 1;
        }
    }
    return 0;
}
