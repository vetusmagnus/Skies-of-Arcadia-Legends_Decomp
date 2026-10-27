#include "types.h"
extern u8 lbl_8030B4D4[];
extern u8 lbl_8030B7F4[];
void fn_801EF7E0(void *p);
typedef struct {
    u8 pad[0x2c];
    s8 bits[1];
} BitOwner;
extern u8 lbl_802C8E54[];
s8 fn_801EF300(void);
u32 fn_801F4C24(void);
s8 fn_801EFCC4(s16 id, s32 n);
typedef struct { u8 pad[0x12]; u8 f; u8 pad2[0xd]; } T0;
extern T0 lbl_802C5790[];
typedef struct { u8 pad[0x12]; u8 f; u8 pad2[0x15]; } T1;
extern T1 lbl_802C6190[];
typedef struct { u8 pad[0x12]; u8 f; u8 pad2[0x15]; } T2;
extern T2 lbl_802C6E10[];
typedef struct { u8 pad[0x15]; u8 f; u8 pad2[0xe]; } T3;
extern T3 lbl_802C7C34[];
typedef struct { u8 pad[0x11]; u8 f; u8 pad2[0x4]; } T4;
extern T4 lbl_802C8774[];
typedef struct { u8 pad[0x20]; u8 f; u8 pad2[0x3]; } T5;
extern T5 lbl_802D7E4C[];
typedef struct { u8 pad[0x24]; u8 f; u8 pad2[0x3]; } T6;
extern T6 lbl_802D83EC[];
typedef struct { u8 pad[0x18]; u8 f; u8 pad2[0xb]; } T7;
extern T7 lbl_802D8A2C[];

s32 fn_801F2508(void *a, void *b)
{
    return *(s16 *)((u8 *)a + 0xa) - *(s16 *)((u8 *)b + 0xa);
}

s32 fn_801F2894(s32 a, s32 b)
{
    return *(s32 *)(lbl_8030B4D4 + a * 0x78 + (b << 2) + 0x60);
}

s32 fn_801F28B4(s32 a)
{
    return *(s32 *)(lbl_8030B4D4 + a * 0x78 + 0x18);
}

void fn_801F4E04(s32 i, s16 v) {
    u8 *p = lbl_8030B7F4;
    p += i * 0x5c;
    *(s16 *)(p + 0x14) = v;
    fn_801EF7E0(p);
}

void fn_801F4E38(s32 i, s16 v) {
    u8 *p = lbl_8030B7F4;
    p += i * 0x5c;
    *(s16 *)(p + 0x12) = v;
    fn_801EF7E0(p);
}

void fn_801F4E6C(s32 i, s16 v) {
    u8 *p = lbl_8030B7F4;
    p += i * 0x5c;
    *(s16 *)(p + 0x10) = v;
    fn_801EF7E0(p);
}

s32 fn_801F3F88(BitOwner *p, s8 i)
{
    return (p->bits[i / 8] & (1 << (i % 8))) != 0;
}

void *fn_801F2860(void) {
    s8 i;

    i = fn_801EF300();
    return &lbl_802C8E54[i * 0x22];
}

s32 fn_801F49DC(void) {
    u32 k;

    k = fn_801F4C24();
    switch (k) {
    case 0:
        return 0x0;
    case 1:
        return 0x50;
    case 2:
        return 0xa0;
    case 3:
        return 0xf0;
    case 4:
        return 0x140;
    case 5:
        return 0x190;
    case 6:
        return 0x1b8;
    case 7:
        return 0x1e0;
    default:
        return 0x0;
    }
}

s32 fn_801F4A60(void) {
    u32 k;

    k = fn_801F4C24();
    switch (k) {
    case 0:
        return 0x50;
    case 1:
        return 0x50;
    case 2:
        return 0x50;
    case 3:
        return 0x50;
    case 4:
        return 0x50;
    case 5:
        return 0x28;
    case 6:
        return 0x28;
    case 7:
        return 0x1e;
    default:
        return 0x0;
    }
}

s8 fn_801F4CA0(void) {
    s32 i;
    s8 mask;

    mask = 0;
    for (i = 0; i < 6; i++) {
        if (fn_801EFCC4(0x146 + i, 4)) {
            mask = (s8)(mask | (1 << i));
        }
    }
    return mask;
}

s32 fn_801F464C(s16 id)
{
    switch (fn_801F4C24()) {
    case 0:
        return lbl_802C5790[id].f;
    case 1:
        return lbl_802C6190[id - 80].f;
    case 2:
        return lbl_802C6E10[id - 160].f;
    case 3:
        return lbl_802C7C34[id - 240].f;
    case 4:
        return lbl_802C8774[id - 320].f;
    case 5:
        return lbl_802D7E4C[id - 400].f;
    case 6:
        return lbl_802D83EC[id - 440].f;
    case 7:
        return lbl_802D8A2C[id - 480].f;
    default:
        return 0;
    }
}
