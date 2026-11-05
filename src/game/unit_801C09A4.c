#include "types.h"
#include "game/gamedata.h"
#include "game/save_8030B7F4.h"
#include "game/stat_8030B4D4.h"
extern u16 lbl_8030A2F4[18];
extern char lbl_802EE634[];
void *fn_801F4AE4(s16 idx);
/* A party member's record in the shop work (0x24 bytes; as in unit_80199B9C.c). */
typedef struct ShopMember {
    SaveChar* ch;     /* 0x00: the member's save record (its name is first) */
    s8 id;            /* 0x04: the member's lbl_8030B7F4 character index */
    s8 b5, b6, b7;    /* 0x05 level and the two values shown after it */
    u8 b8, b9;        /* 0x08 */
    s16 ha, hc, he;   /* 0x0A */
    s16 h10, h12;     /* 0x10 */
    s16 stat[7];      /* 0x14: values copied from the stat record */
    u8 pad22[2];
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
    char* xc8;           /* 0xC8: the ship's name */
    u8 xcc;
    u8 padcd;
    s16 xce;
    s16 xd0;
    u8 padd2[2];
    s32 xd4;
    struct { s16 v; s16 z; s16 a; s16 b; s8 c; s8 d; } d8[5]; /* 0xD8 */
    s16 h10a[3];         /* 0x10A */
    u8 pad110[2];
    s16 x112;
    s16 x114;
    s16 x116;
} ShopWork;
typedef struct ShopTask {
    u8 pad0[0x24];
    ShopWork* w;     /* 0x24 */
    void* x28;       /* 0x28: the window's comparison records (ShopCmp or ShopEquipCmp) */
} ShopTask;
extern ShopTask* lbl_803471B8;
extern s32 fn_801F4C24(s16 id);
extern s8 fn_801F452C(s16 id);
extern void fn_801F4E6C(s32 i, s16 v);
extern void fn_801F4E38(s32 i, s16 v);
extern void fn_801F4E04(s32 i, s16 v);
void fn_801C1364(u8 i);
extern void fn_801DBE1C(const char* fmt, ...);
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
    s16 x14;
    s16 x16;
} Info;
/* One side of the shop's stat comparison: the stats and the colour each is drawn in. */
typedef struct ShopCmpRec {
    s16 id, x2, x4;
    s16 v[9];      /* 0x06 */
    u32 col[9];    /* 0x18 */
} ShopCmpRec;
/* A party member's comparison (0xA8 bytes): with the current and with the new equipment. */
typedef struct ShopCmpRow {
    ShopCmpRec cur;   /* 0x00 */
    ShopCmpRec nw;    /* 0x3C */
    Info eq;          /* 0x78 */
    Info eq2;         /* 0x90 */
} ShopCmpRow;
typedef struct ShopCmp {
    u8 pad0[0x270];
    ShopCmpRow row[4]; /* 0x270 */
} ShopCmp;
extern char lbl_802C3B14[];
extern void fn_8021B2B4(void);
s32 fn_801C2CF4(Info* o, s16 id);

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

extern s32 fn_801F3FD0(s32 slot, s16 id);

u8 fn_801C0C14(s16 id)
{
    u32 i = 0;
    do {
        if (fn_801F3FD0(lbl_803471B8->w->m[i].id, id)) {
            return i;
        }
        i++;
    } while (i < lbl_803471B8->w->count);
    return 0;
}

u8 fn_801C0CA0(s16 id)
{
    u32 i;
    u32 n;
    i = n = 0;
    do {
        if (fn_801F3FD0(lbl_803471B8->w->m[i].id, id)) {
            n++;
        }
        i++;
    } while (i < lbl_803471B8->w->count);
    return n;
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

#define COL(a, b) ((a) == (b) ? 0xFF201008 : (a) < (b) ? 0xFF00A000 : 0xFFA00000)

static inline void Check(u16 i) { if (i >= 4) fn_801DBE1C(lbl_802C3B14); }
static inline u32 CmpCol(s16 a, s16 b)
{
    if (a == b) return 0xFF201008;
    if (a < b) return 0xFF00A000;
    return 0xFFA00000;
}

void fn_801C1E48(void) {
    Save1568* o = &lbl_8030B7F4.x1568;
    ShipStat* l = &lbl_8030B4D4.ship;
    s32 i;
    lbl_803471B8->w->xcc = o->b1568;
    lbl_803471B8->w->xc8 = o->name;
    lbl_803471B8->w->xd4 = o->x157c;
    for (i = 0; i < 5; i++) {
        lbl_803471B8->w->d8[i].v = o->s1580[i];
        lbl_803471B8->w->d8[i].z = 0;
        lbl_803471B8->w->d8[i].a = l->e[i].a;
        lbl_803471B8->w->d8[i].b = l->e[i].b;
        lbl_803471B8->w->d8[i].c = l->e[i].c;
        lbl_803471B8->w->d8[i].d = l->e[i].d;
    }
    lbl_803471B8->w->h10a[0] = o->s158a[0];
    lbl_803471B8->w->h10a[1] = o->s158a[1];
    lbl_803471B8->w->h10a[2] = o->s158a[2];
    lbl_803471B8->w->xce = l->x4;
    lbl_803471B8->w->xd0 = l->x6;
    lbl_803471B8->w->x112 = l->x1a;
    lbl_803471B8->w->x114 = l->x8;
    lbl_803471B8->w->x116 = l->x1c;
}

/* the equip comparison of one member (0x9C) */
typedef struct ShopEquipCmp {
    u8 who;           /* 0x00 */
    u8 pad1[3];
    Info cur;         /* 0x04 the piece worn now */
    Info sel;         /* 0x1C the item tried */
    s16 curId;        /* 0x34 */
    s16 x36;
    s16 xf;           /* 0x38 */
    s16 old[7];       /* 0x3A stats now */
    u8 pad48[4];
    u32 col[7];       /* 0x4C */
    s16 selId;        /* 0x68 */
    s16 x6a;
    s16 x6c;
    s16 now[7];       /* 0x6E stats with the item */
    u8 pad7c[4];
    u32 col2[7];      /* 0x80 */
} ShopEquipCmp;
s32 fn_801C2E48(Info* o, s16 id);
static inline s32 EqKind(s16 id) {
    if (id == -1) {
        return -1;
    }
    return fn_801F4C24(id);
}

static inline s8 EqXf(u8 i) {
    u16 c = lbl_803471B8->w->m[i].id;
    SaveChar* m = &lbl_8030B7F4.chr[c];
    return m->xf;
}

#define W lbl_803471B8->w

#define STATS(dst) \
    dst[0] = W->m[who].stat[0]; \
    dst[1] = W->m[who].stat[1]; \
    dst[2] = W->m[who].stat[2]; \
    dst[3] = W->m[who].stat[3]; \
    dst[4] = W->m[who].stat[4]; \
    dst[5] = W->m[who].stat[5]; \
    dst[6] = W->m[who].stat[6];

/* the equip comparison for one gear slot: EQUIP is fn_801F4E6C/38/04, piece the worn one */
#define TRY(piece, EQUIP, XF) \
    fn_801C2E48(&c->sel, -1); \
    cur = W->m[who].piece; \
    fn_801C2E48(&c->cur, cur); \
    c->curId = cur; \
    STATS(c->old); \
    c->xf = XF; \
    if (fn_801F3FD0(W->m[who].id, id) == 0 && id != -1) { \
        break; \
    } \
    EQUIP(W->m[who].id, id); \
    fn_801C1364(who); \
    c->selId = id; \
    STATS(c->now); \
    c->x6c = -1; \
    EQUIP(W->m[who].id, cur); \
    fn_801C1364(who); \
    if (fn_801F3FD0(W->m[who].id, id)) { \
        fn_801C2E48(&c->sel, id); \
    } \
    break;

static inline u32 EqCol(s16 b, s16 a, s16 id, u16 who) {
    if (fn_801F3FD0(W->m[who].id, id) == 0) {
        return 0x40201008;
    }
    if (b == a) {
        return 0xFF201008;
    }
    if (b < a) {
        return 0xFF00A000;
    }
    return 0xFFA00000;
}

void fn_801C1FC0(s16 id, u16 who) {
    ShopEquipCmp* c;
    ShopEquipCmp* cm;
    s16 cur;

    if (who >= 4) {
        fn_801DBE1C("WshopEquipMakeParameta WorkNumber Error: %s", who);
    }
    cm = lbl_803471B8->x28;
    c = &cm[who];
    c->who = who;
    switch (EqKind(id)) {
    case 0:
        TRY(ha, fn_801F4E6C, EqXf(who));
    case 1:
        TRY(hc, fn_801F4E38, -1);
    case 2:
        TRY(he, fn_801F4E04, -1);
    case 5:
    case 6:
        break;
    default:
        fn_801C2E48(&c->sel, -1);
        fn_801C2E48(&c->cur, -1);
        break;
    }
    c->col[0] = EqCol(c->old[0], c->now[0], id, who);
    c->col[1] = EqCol(c->old[1], c->now[1], id, who);
    c->col[2] = EqCol(c->old[2], c->now[2], id, who);
    c->col[3] = EqCol(c->old[3], c->now[3], id, who);
    c->col[4] = EqCol(c->old[4], c->now[4], id, who);
    c->col[5] = EqCol(c->old[5], c->now[5], id, who);
    c->col[6] = EqCol(c->old[6], c->now[6], id, who);
    c->col2[0] = EqCol(c->now[0], c->old[0], id, who);
    c->col2[1] = EqCol(c->now[1], c->old[1], id, who);
    c->col2[2] = EqCol(c->now[2], c->old[2], id, who);
    c->col2[3] = EqCol(c->now[3], c->old[3], id, who);
    c->col2[4] = EqCol(c->now[4], c->old[4], id, who);
    c->col2[5] = EqCol(c->now[5], c->old[5], id, who);
    c->col2[6] = EqCol(c->now[6], c->old[6], id, who);
}

#undef W
#undef STATS
#undef TRY

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

#ifdef NONMATCHING
typedef struct Pad {
    u32 held;     /* 0x00 */
    u32 x4;       /* 0x04 */
    u32 pressed;  /* 0x08 */
} Pad;
extern Pad* lbl_80311A60[];
extern const u32 lbl_802C3A68[18];
#endif

#ifdef NONMATCHING
s32 fn_801C09F8(s32 port, s32 btn) {
    Pad* p;
    u32 m;

    if (btn < 18 && btn >= 0) {
        p = lbl_80311A60[port];
        m = lbl_802C3A68[btn];
        if (p->held & m) {
            if (p->pressed & m) {
                lbl_8030A2F4[btn] = 10;
                return 1;
            }
            if (lbl_8030A2F4[btn] != 0) {
                lbl_8030A2F4[btn]--;
                return 0;
            }
            lbl_8030A2F4[btn] = 2;
            return 1;
        }
        lbl_8030A2F4[btn] = 0;
    }
    return 0;
}
#endif

s32 fn_801C2CF4(Info* o, s16 id) {
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
        o->x14 = 0;
        o->x12 = 0;
        o->x10 = 0;
        o->xe = 0;
        o->xc = 0;
        o->xa = 0;
        o->x8 = 0;
        o->x6 = 0;
        return 0;
    case 5:
    case 6:
        o->cat = cat;
        o->id = id;
        o->x6 = fn_801EE344(id, 0x10);
        o->xc = fn_801EE344(id, 0x13);
        o->x8 = fn_801EE344(id, 2);
        o->xa = fn_801EE344(id, 3);
        o->xe = fn_801EE344(id, 6);
        o->x10 = lbl_802D7E4C[id - 0x190].cost;
        o->x12 = lbl_802D7E4C[id - 0x190].limit;
        o->x14 = fn_801EE344(id, 4);
        o->x16 = 0;
        break;
    case 0: case 1: case 2: case 3: case 7:
        o->cat = cat;
        o->id = id;
        break;
    }
    return 1;
}
