#include "types.h"

extern void fn_801DBE1C(const char *fmt, ...);
extern u8 camp_work[];
extern u8 lbl_8030B7F4[];
extern void fn_801F2860(s16 v);
extern u8 lbl_80307638[];
extern u32 lbl_80347144;
extern u8 lbl_802E98A0[];
extern u32 lbl_802F7298[];
extern u8 lbl_802D8E64[];
extern u8 *lbl_8034710C;
extern u32 lbl_803473EC;
extern s32 lbl_803467D0;
void fn_801F4EA0(s32 a, s32 v);
void fn_8021A1C4(void *out);
void fn_8021ADA0(void *p, void *buf);
extern const char lbl_802B4864[];
extern u8 lbl_80310B3C[];
extern void sndOutputMode(s32 mode);
extern void OSSetSoundMode(s32 mode);
extern u8 lbl_80347148;
extern u32 OSGetSoundMode(void);
extern s32 fn_801EE344(s16 a, s32 b);
extern s8 lbl_802D7E4C[];
extern u8 lbl_80310A1C[];
extern u8 lbl_8030B4D4[];
extern int fn_8025CB24(char*, const char*, ...);
extern char lbl_802B4870[];
extern char lbl_802B4880[];
extern s32 fn_801E4BF4(s8 a);
extern s32 fn_801E4BBC(s8 a);
extern s32 fn_801F3F88(void *p, s8 i);

int fn_80193F28(void) {
    fn_801DBE1C("Nothing VM Tanken.");
    return 0;
}

u16 fn_80193F58(void) {
    u8 *p = *(u8 **)(camp_work + 0x278);
    p = *(u8 **)(p + 0x24);
    p = *(u8 **)(p + 0xbc);
    p = *(u8 **)(p + 0x4);
    return *(u16 *)(p + 0x18);
}

void fn_80193F80(void) {
    fn_801F2860(*(s16 *)(lbl_8030B7F4 + 0x348));
}

u8 *fn_80193FAC(void) {
    return lbl_8030B7F4 + 0x331;
}

void fn_80193FBC(s32 unused, s32 toggle) {
    if (toggle != 0) {
        lbl_803467D0 = (lbl_803467D0 == 0);
    }
    fn_801F4EA0(unused, lbl_803467D0);
}

void fn_80194028(void) {
    u8 buf[0x20];
    void *p = *(void **)(camp_work + 4);
    fn_8021A1C4(buf);
    fn_8021ADA0(p, buf);
}

int fn_8019406C(void) {
    fn_801DBE1C(lbl_802B4864);
    fn_801DBE1C(lbl_802B4864);
    return 0;
}

void fn_8019410C(void) {
    if (*(s32 *)(lbl_80307638 + 0x8b4) == 0) {
        *(u32 *)(lbl_80310B3C + 0x88) |= 0x20;
    } else {
        *(u32 *)(lbl_80310B3C + 0x88) &= ~0x20;
    }
}

void fn_80194210(void) {
    if (*(s32 *)(lbl_80307638 + 0x8b4) == 0) {
        *(u32 *)(lbl_80310B3C + 0x88) &= ~0x8;
    } else {
        *(u32 *)(lbl_80310B3C + 0x88) |= 0x8;
    }
}

void fn_80194254(void) {
    lbl_80347144 = *(u32 *)(lbl_80307638 + 0x8b4);
}

void fn_80194268(void) {
    sndOutputMode(lbl_80347144 == 0);
    OSSetSoundMode(lbl_80347144 == 0);
}

void fn_80194334(void) {
    if (OSGetSoundMode() == 1) {
        lbl_80347148 = 0;
        lbl_80347144 = 0;
    } else {
        lbl_80347148 = 1;
        lbl_80347144 = 1;
    }
}

u32 fn_801944C4(void) {
    return *(u32 *)(lbl_80307638 + 0x70c);
}

u8 *fn_80194C00(s8 idx) {
    return lbl_802E98A0 + idx * 9;
}

u32 fn_80194C38(s8 idx) {
    return lbl_802F7298[idx];
}

u8 *fn_80194C50(s8 idx) {
    return lbl_802D8E64 + idx * 0x24;
}

void fn_80194C68(u8 *base, u32 i, u32 j, u32 v) {
    *(u32 *)(base + i * 8 + j * 4) = v;
}

u32 fn_80194C7C(u8 *base, u32 i, u32 j) {
    u32 v = *(u32 *)(base + i * 8 + j * 4);
    return ((-1 - v) | (v + 1)) >> 31;
}

u32 fn_80194F5C(s32 a, s32 b) {
    u32 r;
    if (a > b) {
        r = 0xff2b5000;
    } else if (a < b) {
        r = 0xff800000;
    } else {
        r = 0xff201008;
    }
    return r;
}

s32 fn_801950D0(s32 x) {
    s16 v = x;
    if (v == -1) {
        return 0;
    }
    return (s16)fn_801EE344(v, 6);
}

s32 fn_8019510C(s32 x) {
    s16 v = x;
    if (v == -1) {
        return 0;
    }
    return (s16)fn_801EE344(v, 4);
}

s32 fn_80195148(s32 x) {
    s16 v = x;
    if (v == -1) {
        return 0;
    }
    return (s16)fn_801EE344(v, 3);
}

s32 fn_80195184(s32 x) {
    s16 v = x;
    if (v == -1) {
        return 0;
    }
    return (s16)fn_801EE344(v, 2);
}

s32 fn_801951C0(s32 x) {
    if (x >= 0x190 && x <= 0x1b7) {
        return lbl_802D7E4C[x * 0x24 - 0x382e];
    }
    if (x >= 0x1b8 && x <= 0x1df) {
        return -1;
    }
    return -2;
}

s32 fn_801953B8(void) {
    s32 v = (s8)lbl_80310A1C[6];
    switch (v) {
    case 0: case 1: case 2: case 3: case 4: case 12:
        return 0;
    }
    return (s8)lbl_8030B7F4[0x328] == 0;
}

void fn_801954D0(u32 v) {
    u8 *p = *(u8 **)(camp_work + 0x190);
    p = *(u8 **)(p + 0x24);
    p = *(u8 **)(p + 0xbc);
    *(u32 *)(p + 0x4) = v;
}

void fn_801959D4(s32 idx) {
    *(u8 **)(*(u8 **)(lbl_8034710C + 0x24)) = lbl_80307638 + idx * 0x78;
}

void fn_80195F90(void) {
    lbl_803473EC = 1;
}

void fn_80199B60(void) {
    u8 v = lbl_8030B4D4[0x2d4];
    camp_work[0xc] = v;
    *(u8 **)(camp_work + 0x0) = lbl_8030B7F4 + 0x328;
    *(u8 **)(camp_work + 0x4) = lbl_8030B7F4 + 0x1568;
    *(u8 **)(camp_work + 0x8) = lbl_8030B4D4 + 0x2dc;
}

s32 fn_801944D4(char* buf, s32 id)
{
    s32 mode = *(s32 *)(lbl_80307638 + 0x70c);
    switch (mode) {
    case 0:
        return (s8)fn_8025CB24(buf, lbl_802B4870, id);
    case 1:
        return (s8)fn_8025CB24(buf, lbl_802B4880, id);
    }
    return (s32)buf;
}

s32 fn_80194A18(s32 a)
{
    s32 x = a * 2;
    if (fn_801E4BF4((s8)x) == 0) {
        return -1;
    }
    if (fn_801E4BF4((s8)(x + 1)) == 0) {
        return -1;
    }
    if (fn_801E4BBC((s8)x) == 0) {
        return x;
    }
    return x + 1;
}

void fn_80194B84(s8* out)
{
    s32 i;
    for (i = 0; i < 0x16; i++) {
        s8 v;
        if (fn_801E4BF4((s8)i) == 1) {
            if (fn_801E4BBC((s8)i) == 1) {
                v = 1;
            } else {
                v = 0;
            }
        } else {
            v = -1;
        }
        out[i] = v;
    }
}

s32 fn_8019576C(s32 idx) {
    s32 i = 0;
    u8 *p = lbl_8030B7F4 + idx * 0x5C;

    for (; i < 0x24; i++) {
        if (fn_801F3F88(p, (s8)i) != 0) {
            return 1;
        }
    }
    return 0;
}

void fn_801959F4(void) {
    u8 *p = lbl_80307638;
    s32 i;

    for (i = 0; i < 0x16; i++) {
        *(u32 *)(p + 0x00) = 0;
        *(u32 *)(p + 0x04) = 0;
        *(u32 *)(p + 0x08) = 0;
        *(u32 *)(p + 0x0C) = 0;
        *(u32 *)(p + 0x10) = 0;
        *(u32 *)(p + 0x14) = 0;
        *(u32 *)(p + 0x18) = 0;
        *(u32 *)(p + 0x1C) = 0;
        *(u32 *)(p + 0x20) = 0;
        *(u32 *)(p + 0x34) = 0;
        *(u32 *)(p + 0x38) = 0;
        *(u32 *)(p + 0x3C) = 0;
        *(u32 *)(p + 0x40) = 0;
        *(u32 *)(p + 0x24) = 0;
        *(u32 *)(p + 0x28) = 0;
        *(u32 *)(p + 0x2C) = 0;
        *(u32 *)(p + 0x30) = 0;
        *(u32 *)(p + 0x44) = 0;
        *(u32 *)(p + 0x48) = 0;
        *(u32 *)(p + 0x4C) = 0;
        *(u32 *)(p + 0x50) = 0;
        p += 0x78;
    }
}
