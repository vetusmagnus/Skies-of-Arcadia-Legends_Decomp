#include "types.h"
#include "game/save_8030B7F4.h"
#include "game/gamedata.h"
#include "game/stat_8030B4D4.h"
void fn_801EF7E0(void);
typedef struct {
    u8 pad[0x2c];
    s8 bits[1];
} BitOwner;
s8 fn_801EF300(void);
u32 fn_801F4C24(s16 id);
s8 fn_801EFCC4(s16 id, s32 n);
extern const s8 lbl_802D4600[24];
s32 fn_801E4BBC(s8 i);
s32 fn_801F4A60(s16 id);

s32 fn_801F2508(void *a, void *b)
{
    return *(s16 *)((u8 *)a + 0xa) - *(s16 *)((u8 *)b + 0xa);
}

s32 fn_801F2894(s32 a, s32 b)
{
    StatRec *r = &lbl_8030B4D4.chr[a];
    return r->x60[b];
}

s32 fn_801F28B4(s32 a)
{
    StatRec *r = &lbl_8030B4D4.chr[a];
    return r->x18;
}

extern s8 lbl_802C9628[][4];
extern void fn_801EFFD8(s16 v);
extern void fn_801EFFFC(s16 v);

void fn_801F28CC(s32 code) {
    s32 next;
    s8 v;
    s32 cur;
    lbl_8030B7F4.xb4f = 0;
    next = -1;
    cur = lbl_8030B7F4.x32e;
    if (lbl_8030B7F4.x32f >= 3 && lbl_8030B7F4.x330 >= 30) {
        lbl_8030B7F4.xb4f = 2;
        next = 0x2f;
    } else if (code == 0x103) {
        s8* t = lbl_802C9628[cur - 0x20];
        if (t[0] <= lbl_8030B7F4.x330) {
            v = t[1];
            if (v != -1) {
                lbl_8030B7F4.xb4f = 1;
                next = v + 0x20;
            }
        }
    } else {
        s8* t = lbl_802C9628[cur - 0x20];
        v = t[3];
        if (v != -1) {
            lbl_8030B7F4.xb4f = 1;
            next = v + 0x20;
        }
    }
    if (next != -1) {
        lbl_8030B7F4.x32e = next;
        fn_801EFFD8(cur);
        fn_801EFFFC(next);
        lbl_8030B7F4.chr[2].slot0 = next;
    }
    lbl_8030B7F4.xb50 &= ~0x40;
    if (lbl_802C9628[next - 0x20][1] != lbl_802C9628[next - 0x20][3]) {
        lbl_8030B7F4.xb50 |= 0x40;
    }
}

extern u32 lbl_80310B3C[];

s32 fn_801F39EC(s32 idx) {
    SaveChar* c;
    s32 i;
    u32 b, d;
    b = idx + 0x408;
    d = idx + 0x402;
    lbl_80310B3C[b >> 5] &= ~(1 << (b & 31));
    lbl_80310B3C[d >> 5] |= 1 << (d & 31);
    c = &lbl_8030B7F4.chr[idx];
    for (i = 0; i < 4; i++) {
        if (lbl_8030B7F4.party[i] == idx) {
            for (; i < 3; i++) {
                lbl_8030B7F4.party[i] = lbl_8030B7F4.party[i + 1];
            }
            lbl_8030B7F4.party[i] = -1;
            lbl_8030B4D4.x2d4--;
            fn_801EFFD8(c->slot0);
            c->slot1 = -1;
            c->slot2 = -1;
            fn_801EF7E0();
            if (idx == 2) {
                lbl_8030B7F4.xb50 &= ~4;
            }
            return 1;
        }
    }
    return 0;
}

void fn_801F4E04(s32 i, s16 v) {
    SaveChar *p = lbl_8030B7F4.chr;
    p += i;
    p->slot2 = v;
    fn_801EF7E0();
}

void fn_801F4E38(s32 i, s16 v) {
    SaveChar *p = lbl_8030B7F4.chr;
    p += i;
    p->slot1 = v;
    fn_801EF7E0();
}

void fn_801F4E6C(s32 i, s16 v) {
    SaveChar *p = lbl_8030B7F4.chr;
    p += i;
    p->slot0 = v;
    fn_801EF7E0();
}

s32 fn_801F3F88(BitOwner *p, s8 i)
{
    return (p->bits[i / 8] & (1 << (i % 8))) != 0;
}

PirateRank *fn_801F2860(void) {
    s8 i;

    i = fn_801EF300();
    return &lbl_802C8E54[i];
}

s32 fn_801F49DC(s16 id) {
    u32 k;

    k = fn_801F4C24(id);
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

s32 fn_801F4A60(s16 id) {
    u32 k;

    k = fn_801F4C24(id);
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
    switch (fn_801F4C24(id)) {
    case 0:
        return lbl_802C5790[id].can_sell;
    case 1:
        return lbl_802C6190[id - 80].can_sell;
    case 2:
        return lbl_802C6E10[id - 160].can_sell;
    case 3:
        return lbl_802C7C34[id - 240].can_sell;
    case 4:
        return lbl_802C8774[id - 320].can_sell;
    case 5:
        return lbl_802D7E4C[id - 400].can_sell;
    case 6:
        return lbl_802D83EC[id - 440].can_sell;
    case 7:
        return lbl_802D8A2C[id - 480].can_sell;
    default:
        return 0;
    }
}

extern u32 lbl_80310B3C[];
extern void fn_801EFFFC(s16 id);
extern void fn_801EFFB4(s16 id);
extern void fn_801EFF6C(s16 id);
extern void fn_801EFFD8(s16 id);
extern void fn_801EFF90(s16 id);
extern void fn_801EFF48(s16 id);
extern s32 fn_801F3B90(s32 i);

s32 fn_801F3E6C(s32 i) {
    SaveChar *c;
    CharParam *r;
    u32 f1 = i + 0x408;
    u32 f2 = i + 0x402;
    lbl_80310B3C[f1 >> 5] |= 1 << (f1 & 31);
    lbl_80310B3C[f2 >> 5] |= 1 << (f2 & 31);
    c = &lbl_8030B7F4.chr[i];
    r = &lbl_802C4860[i];
    fn_801EFFFC(r->weapon);
    c->slot0 = r->weapon;
    fn_801EFFB4(r->armor);
    c->slot1 = r->armor;
    fn_801EFF6C(r->acc);
    c->slot2 = r->acc;
    if (fn_801F3B90(i) != 0) {
        if (i == 2) {
            lbl_8030B7F4.xb50 |= 4;
        }
        return 1;
    }
    fn_801EFFD8(r->weapon);
    fn_801EFF90(r->armor);
    fn_801EFF48(r->acc);
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

s32 fn_801F4F54(s16* pa, s16* pb) {
    u8 ka;
    s16 a = *pa;
    s16 b = *pb;
    u8 kb;
    if (a == -1 && b == -1) return 0;
    if (a == -1) return 1;
    if (b == -1) return -1;
    switch (fn_801F4C24(a)) {
    case 0:
        ka = lbl_802C5790[a].sort2;
        kb = lbl_802C5790[b].sort2;
        break;
    case 1:
        ka = lbl_802C6190[a - 0x50].sort2;
        kb = lbl_802C6190[b - 0x50].sort2;
        break;
    case 2:
        ka = lbl_802C6E10[a - 0xa0].sort2;
        kb = lbl_802C6E10[b - 0xa0].sort2;
        break;
    case 3:
        ka = lbl_802C7C34[a - 0xf0].sort2;
        kb = lbl_802C7C34[b - 0xf0].sort2;
        break;
    case 4:
        ka = lbl_802C8774[a - 0x140].sort2;
        kb = lbl_802C8774[b - 0x140].sort2;
        break;
    case 5:
        ka = lbl_802D7E4C[a - 0x190].sort2;
        kb = lbl_802D7E4C[b - 0x190].sort2;
        break;
    case 6:
        ka = lbl_802D83EC[a - 0x1b8].sort2;
        kb = lbl_802D83EC[b - 0x1b8].sort2;
        break;
    case 7:
        ka = lbl_802D8A2C[a - 0x1e0].sort2;
        kb = lbl_802D8A2C[b - 0x1e0].sort2;
        break;
    }
    return ka - kb;
}

s32 fn_801F52AC(void)
{
    s8 i;
    s32 cnt;

    cnt = 0;
    for (i = 0; i < 0x16; i++) {
        if (fn_801E4BBC(i) != 0) {
            if (lbl_802D4600[i] == 0) {
                cnt += 1;
            } else {
                cnt += 0x100;
            }
        }
    }
    return cnt;
}

const void* fn_801F4AE4(s16 id) {
    if (id == -1) return 0;
    switch (fn_801F4C24(id)) {
    case 0: return &lbl_802C5790[id];
    case 1: return &lbl_802C6190[id - 0x50];
    case 2: return &lbl_802C6E10[id - 0xa0];
    case 3: return &lbl_802C7C34[id - 0xf0];
    case 4: return &lbl_802C8774[id - 0x140];
    case 5: return &lbl_802D7E4C[id - 0x190];
    case 6: return &lbl_802D83EC[id - 0x1b8];
    case 7: return &lbl_802D8A2C[id - 0x1e0];
    }
    return 0;
}

s32 fn_801F5100(s16 *a, s16 *b)
{
    u8 p;
    s16 x = *a;
    s16 y = *b;
    u8 q;
    if (x == -1 && y == -1) return 0;
    if (x == -1) return 1;
    if (y == -1) return -1;
    switch (fn_801F4C24(x)) {
    case 0: p = lbl_802C5790[x].sort; q = lbl_802C5790[y].sort; break;
    case 1: p = lbl_802C6190[x - 0x50].sort; q = lbl_802C6190[y - 0x50].sort; break;
    case 2: p = lbl_802C6E10[x - 0xa0].sort; q = lbl_802C6E10[y - 0xa0].sort; break;
    case 3: p = lbl_802C7C34[x - 0xf0].sort; q = lbl_802C7C34[y - 0xf0].sort; break;
    case 4: p = lbl_802C8774[x - 0x140].sort; q = lbl_802C8774[y - 0x140].sort; break;
    case 5: p = lbl_802D7E4C[x - 0x190].sort; q = lbl_802D7E4C[y - 0x190].sort; break;
    case 6: p = lbl_802D83EC[x - 0x1b8].sort; q = lbl_802D83EC[y - 0x1b8].sort; break;
    case 7: p = lbl_802D8A2C[x - 0x1e0].sort; q = lbl_802D8A2C[y - 0x1e0].sort; break;
    }
    return p - q;
}

u16 fn_801F477C(s16 id)
{
    switch (fn_801F4C24(id)) {
    case 0:
        return lbl_802C5790[id].price;
    case 1:
        return lbl_802C6190[id - 80].price;
    case 2:
        return lbl_802C6E10[id - 160].price;
    case 3:
        return lbl_802C7C34[id - 240].price;
    case 4:
        return lbl_802C8774[id - 320].price;
    case 5:
        return lbl_802D7E4C[id - 400].price;
    case 6:
        return lbl_802D83EC[id - 440].price;
    case 7:
        return lbl_802D8A2C[id - 480].price;
    default:
        return 0;
    }
}

s8 fn_801F452C(s16 id) {
    s8 n = fn_801F4A60(id);
    InvEnt *tbl;
    InvEnt *e;
    s32 i;

    switch (fn_801F4C24(id)) {
    case 0:
        tbl = lbl_8030B7F4.s354;
        break;
    case 1:
        tbl = lbl_8030B7F4.s494;
        break;
    case 2:
        tbl = lbl_8030B7F4.s5d4;
        break;
    case 3:
        tbl = lbl_8030B7F4.s714;
        break;
    case 4:
        tbl = lbl_8030B7F4.s854;
        break;
    case 5:
        tbl = lbl_8030B7F4.sa0c;
        break;
    case 6:
        tbl = lbl_8030B7F4.saac;
        break;
    case 7:
        tbl = lbl_8030B7F4.s994;
        break;
    }
    e = tbl;
    i = 0;
    do {
        if (id == e->id) {
            return tbl[i].cnt;
        }
        i++;
        e++;
    } while (i < n);
    return 0;
}
