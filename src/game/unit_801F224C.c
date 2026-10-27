#include "types.h"
#include "game/save_8030B7F4.h"
extern u8 lbl_8030B4D4[];
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
    SaveChar *p = lbl_8030B7F4.chr;
    p += i;
    p->slot2 = v;
    fn_801EF7E0(p);
}

void fn_801F4E38(s32 i, s16 v) {
    SaveChar *p = lbl_8030B7F4.chr;
    p += i;
    p->slot1 = v;
    fn_801EF7E0(p);
}

void fn_801F4E6C(s32 i, s16 v) {
    SaveChar *p = lbl_8030B7F4.chr;
    p += i;
    p->slot0 = v;
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

typedef struct Rec_801F3E6C {
    u8 pad0[0x12];
    s16 a;
    s16 b;
    s16 c;
    u8 pad18[0x98 - 0x18];
} Rec_801F3E6C;
extern u32 lbl_80310B3C[];
extern Rec_801F3E6C lbl_802C4860[];
extern void fn_801EFFFC(s16 id);
extern void fn_801EFFB4(s16 id);
extern void fn_801EFF6C(s16 id);
extern void fn_801EFFD8(s16 id);
extern void fn_801EFF90(s16 id);
extern void fn_801EFF48(s16 id);
extern s32 fn_801F3B90(s32 i);

s32 fn_801F3E6C(s32 i) {
    SaveChar *c;
    Rec_801F3E6C *r;
    u32 f1 = i + 0x408;
    u32 f2 = i + 0x402;
    lbl_80310B3C[f1 >> 5] |= 1 << (f1 & 31);
    lbl_80310B3C[f2 >> 5] |= 1 << (f2 & 31);
    c = &lbl_8030B7F4.chr[i];
    r = &lbl_802C4860[i];
    fn_801EFFFC(r->a);
    c->slot0 = r->a;
    fn_801EFFB4(r->b);
    c->slot1 = r->b;
    fn_801EFF6C(r->c);
    c->slot2 = r->c;
    if (fn_801F3B90(i) != 0) {
        if (i == 2) {
            lbl_8030B7F4.xb50 |= 4;
        }
        return 1;
    }
    fn_801EFFD8(r->a);
    fn_801EFF90(r->b);
    fn_801EFF48(r->c);
    return 0;
}

s32 fn_801F4D14(void)
{
    s32 i;
    s32 sb = 0;
    s32 sa = 0;
    for (i = 0; i < 5; i++) {
        s8 k = lbl_8030B7F4.party[i];
        if (k != -1) {
            SaveChar* e = &lbl_8030B7F4.chr[k];
            s32 a, b;
            b = e->hpMax;
            a = e->hp;
            if ((f32)a / (f32)b < 0.25f) {
                return 0;
            }
            sb += b;
            sa += a;
        }
    }
    return !((f32)sa / (f32)sb < 0.63);
}
