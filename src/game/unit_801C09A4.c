#include "types.h"
#include "game/gamedata.h"
#include "game/save_8030B7F4.h"
#include "game/stat_8030B4D4.h"
extern u16 lbl_8030A2F4[18];
extern char lbl_802EE634[];
void *fn_801F4AE4(s16 idx);
/* A party member's record in the shop work (0x24 bytes; as in unit_80199B9C.c). */
typedef struct ShopMember {
    const char* name; /* 0x00 */
    s8 id;            /* 0x04: the member's lbl_8030B7F4 character index */
    s8 b5, b6, b7;    /* 0x05 level and the two values shown after it */
    u8 pad8[2];
    s16 ha, hc, he;   /* 0x0A */
    s16 h10, h12;     /* 0x10 */
    u8 pad14[0x24 - 0x14];
} ShopMember;
/* The shop work (as in unit_80199B9C.c). */
typedef struct ShopWork {
    u8 pad0[3];
    u8 state;        /* 0x03 */
    s16 qty;         /* 0x04 */
    u16 item;        /* 0x06 */
    u8 pad8[1];
    u8 x9;           /* 0x09 */
    u8 xa;           /* 0x0A */
    u8 xb;           /* 0x0B */
    u8 xc[4];        /* 0x0C */
    s8 who[4];       /* 0x10 */
    s16 stat[4][4];  /* 0x14 */
    u8 b34;          /* 0x34 */
    u8 count;        /* 0x35: party size */
    u8 b36;          /* 0x36 */
    u8 b37;          /* 0x37 */
    ShopMember m[4];     /* 0x38: the party, in order */
    u8 padc8[0xd8 - 0xc8];
    struct { s16 v; u8 pad[8]; } d8[4]; /* 0xD8 */
    u8 pad100[0x10a - 0x100];
    s16 h10a[3];         /* 0x10A */
} ShopWork;
typedef struct ShopTask {
    u8 pad0[0x24];
    ShopWork* w;     /* 0x24 */
} ShopTask;
extern ShopTask* lbl_803471B8;
extern s32 fn_801F4C24(s16 id);
extern s8 fn_801F452C(s16 id);
extern void fn_801F4E6C(s32 i, s16 v);
extern void fn_801F4E38(s32 i, s16 v);
extern void fn_801F4E04(s32 i, s16 v);
void fn_801C1364(u8 i);
void fn_801C1E48(void);
typedef struct Info {
    s16 id;
    s16 cat;
    s16 x4;
    s16 x6;
    s16 x8;
    s16 xa;
    s16 xc;
    s16 xe;
    s16 x10;
    s16 x12;
} Info;
extern s16 fn_801EE344(s16 id, s32 stat);
extern s8 fn_801F4A60(void);

void fn_801C09A4(void)
{
    lbl_8030A2F4[0] = 0;
    lbl_8030A2F4[1] = 0;
    lbl_8030A2F4[2] = 0;
    lbl_8030A2F4[3] = 0;
    lbl_8030A2F4[4] = 0;
    lbl_8030A2F4[5] = 0;
    lbl_8030A2F4[6] = 0;
    lbl_8030A2F4[7] = 0;
    lbl_8030A2F4[8] = 0;
    lbl_8030A2F4[9] = 0;
    lbl_8030A2F4[10] = 0;
    lbl_8030A2F4[11] = 0;
    lbl_8030A2F4[12] = 0;
    lbl_8030A2F4[13] = 0;
    lbl_8030A2F4[14] = 0;
    lbl_8030A2F4[15] = 0;
    lbl_8030A2F4[16] = 0;
    lbl_8030A2F4[17] = 0;
}

void fn_801C0AB4(s32 a, u8 i)
{
    s16 id = a;
    switch (fn_801F4C24(id)) {
    case 0:
        fn_801F4E6C(lbl_803471B8->w->m[i].id, id);
        break;
    case 1:
        fn_801F4E38(lbl_803471B8->w->m[i].id, id);
        break;
    case 2:
        fn_801F4E04(lbl_803471B8->w->m[i].id, id);
        break;
    }
}

/* 1 when member `who` already has item id in one of its five slots. */
s32 fn_801C0B88(s16 id, u8 who)
{
    if (id == lbl_803471B8->w->m[who].ha) {
        return 1;
    }
    if (id == lbl_803471B8->w->m[who].hc) {
        return 1;
    }
    if (id == lbl_803471B8->w->m[who].he) {
        return 1;
    }
    if (id == lbl_803471B8->w->d8[who].v) {
        return 1;
    }
    return id == lbl_803471B8->w->h10a[who];
}

u8 fn_801C0D34(s16 id)
{
    u32 cnt;
    u32 i;
    u32 c;
    if (id == -1) {
        return 0;
    }
    cnt = fn_801F452C(id);
    switch (fn_801F4C24(id)) {
    case 0:
        c = 0;
        for (i = 0; i < lbl_8030B4D4.x2d4; i++) {
            if (id == lbl_8030B7F4.chr[lbl_8030B7F4.party[i]].slot0) {
                c++;
            }
        }
        cnt -= c;
        break;
    case 1:
        c = 0;
        for (i = 0; i < lbl_8030B4D4.x2d4; i++) {
            if (id == lbl_8030B7F4.chr[lbl_8030B7F4.party[i]].slot1) {
                c++;
            }
        }
        cnt -= c;
        break;
    case 2:
        c = 0;
        for (i = 0; i < lbl_8030B4D4.x2d4; i++) {
            if (id == lbl_8030B7F4.chr[lbl_8030B7F4.party[i]].slot2) {
                c++;
            }
        }
        cnt -= c;
        break;
    case 5:
        if (cnt != 0) {
            for (i = 0; i < 4; i++) {
                if (cnt == 0) break;
                if (lbl_803471B8->w->d8[i].v == id) cnt--;
            }
        }
        break;
    case 6:
        for (i = 0; i < 3; i++) {
            if (cnt == 0) break;
            if (lbl_803471B8->w->h10a[i] == id) cnt--;
        }
        break;
    }
    return cnt;
}

void fn_801C0FBC(s16 id) {
    lbl_803471B8->w->x9 = fn_801C0D34(id);
}

void fn_801C0FE8(s16 id, s8 amount) {
    InvEnt* p;
    InvEnt* tbl;
    s32 i;
    s32 n;

    switch (fn_801F4C24(id)) {
    case 0: tbl = lbl_8030B7F4.s354; n = 0x50; break;
    case 1: tbl = lbl_8030B7F4.s494; n = 0x50; break;
    case 2: tbl = lbl_8030B7F4.s5d4; n = 0x50; break;
    case 3: tbl = lbl_8030B7F4.s714; n = 0x50; break;
    case 4: tbl = lbl_8030B7F4.s854; n = 0x50; break;
    case 5: tbl = lbl_8030B7F4.sa0c; n = 0x28; break;
    case 6: tbl = lbl_8030B7F4.saac; n = 0x28; break;
    case 7: tbl = lbl_8030B7F4.s994; n = 0x1e; break;
    }
    p = tbl;
    i = 0;
    do {
        if (id == p->id) {
            tbl[i].cnt -= amount;
            if (tbl[i].cnt <= 0) {
                tbl[i].id = -1;
                tbl[i].cnt = 0;
            }
            return;
        }
        i++;
        p++;
    } while (i < n);
}

void fn_801C12C8(void) {
    u32 i = 0;
    lbl_803471B8->w->count = lbl_8030B4D4.x2d4;
    lbl_803471B8->w->m[3].id = -1;
    lbl_803471B8->w->m[2].id = -1;
    lbl_803471B8->w->m[1].id = -1;
    lbl_803471B8->w->m[0].id = -1;
    while (i < lbl_803471B8->w->count) {
        fn_801C1364(i);
        i++;
    }
    fn_801C1E48();
}

/* -1 unless the item is of kind 5, else its table byte. Takes s16 (no extsh at the call);
 * unit_80199B9C.c declares it `u16 fn_801C16D0(s16)`, the code returns the sign-extended s8. */
s32 fn_801C16D0(s16 id) {
    if (fn_801F4C24(id) != 5) {
        return -1;
    }
    return lbl_802D7E4C[id - 400].type;
}

void fn_801C2C4C(u8 i, u8 v) {
    u16 c = lbl_803471B8->w->m[i].id;
    SaveChar* m = &lbl_8030B7F4.chr[c];
    m->xf = v;
}

u8 fn_801C2C84(u8 i) {
    u16 c = lbl_803471B8->w->m[i].id;
    SaveChar* m = &lbl_8030B7F4.chr[c];
    return m->xf;
}

char *fn_801C2CBC(s16 idx)
{
    if (idx != -1) {
        return fn_801F4AE4(idx);
    }
    return lbl_802EE634;
}

s32 fn_801C2E48(Info* o, s16 id) {
    s32 cat;
    if (id == -1) {
        goto clear;
    }
    cat = fn_801F4C24(id);
    switch (cat) {
    case 4:
    default:
    clear:
        o->cat = -1;
        o->id = id;
        o->x4 = -1;
        o->x12 = 0;
        o->x10 = 0;
        o->xe = 0;
        o->xc = 0;
        o->xa = 0;
        o->x8 = 0;
        o->x6 = 0;
        return 0;
    case 0:
    case 1:
    case 2:
        o->cat = cat;
        o->id = id;
        o->x4 = -1;
        o->x6 = fn_801EE344(id, 0x10);
        o->x8 = fn_801EE344(id, 0x11);
        o->xa = fn_801EE344(id, 1);
        o->xc = fn_801EE344(id, 0x12);
        o->xe = fn_801EE344(id, 0x13);
        o->x10 = fn_801EE344(id, 0x14);
        o->x12 = fn_801EE344(id, 4);
        break;
    case 3:
        o->cat = cat;
        o->id = id;
        break;
    case 5:
    case 6:
        o->cat = cat;
        o->id = id;
        break;
    case 7:
        o->cat = cat;
        o->id = id;
        break;
    }
    return 1;
}

void fn_801C1148(s16 id, s8 amount) {
    InvEnt* tbl;
    InvEnt* p;
    s32 i;
    s32 n = fn_801F4A60();

    switch (fn_801F4C24(id)) {
    case 0: tbl = lbl_8030B7F4.s354; break;
    case 1: tbl = lbl_8030B7F4.s494; break;
    case 2: tbl = lbl_8030B7F4.s5d4; break;
    case 3: tbl = lbl_8030B7F4.s714; break;
    case 4: tbl = lbl_8030B7F4.s854; break;
    case 5: tbl = lbl_8030B7F4.sa0c; break;
    case 6: tbl = lbl_8030B7F4.saac; break;
    case 7: tbl = lbl_8030B7F4.s994; break;
    }
    p = tbl;
    i = 0;
    do {
        if (id == p->id) {
            tbl[i].cnt += amount;
            if (tbl[i].cnt >= 99) {
                tbl[i].cnt = 99;
            }
            return;
        }
        i++;
        p++;
    } while (i < n);
    i = 0;
    p = tbl;
    do {
        if (p->id == -1) {
            tbl[i].id = id;
            tbl[i].cnt = amount;
            return;
        }
        i++;
        p++;
    } while (i < n);
}
