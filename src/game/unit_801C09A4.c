#include "types.h"
#include "game/gamedata.h"
extern u16 lbl_8030A2F4[18];
extern char lbl_802EE634[];
void *fn_801F4AE4(s16 idx);
extern u8 *lbl_803471B8;
extern u8 fn_801C0D34(void);
/* lbl_803471B8->x24: a block whose 0x24-byte rows (from 0x30, guessed) hold an s8 slot at row+0xc
   (absolute row offset 0x3c); slot indexes lbl_8030B7F4, 0x5c-byte records with a byte at 0xf. */
typedef struct { u8 pad[0xc]; s8 slot; u8 padd[0x24 - 0xd]; } Row;
typedef struct { u8 hdr[0x30]; Row rows[1]; } Sheet;
typedef struct { u8 pad[0x24]; Sheet* sheet; } Party;
typedef struct { u8 pad[0xf]; u8 xf; u8 pad10[0x5c - 0x10]; } Mem;
extern Mem lbl_8030B7F4[];
typedef struct { u8 pad[0xc]; s8 slot; u8 padd[0x24 - 0xd]; } Row_801C0AB4;
typedef struct { u8 hdr[0x30]; Row_801C0AB4 rows[1]; } Sheet_801C0AB4;
typedef struct { u8 pad[0x24]; Sheet_801C0AB4* sheet; } Party_801C0AB4;
extern s32 fn_801F4C24(s16 id);
extern void fn_801F4E6C(s32 i, s16 v);
extern void fn_801F4E38(s32 i, s16 v);
extern void fn_801F4E04(s32 i, s16 v);
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

char *fn_801C2CBC(s16 idx)
{
    if (idx != -1) {
        return fn_801F4AE4(idx);
    }
    return lbl_802EE634;
}

void fn_801C0FBC(void) {
    u8 v = fn_801C0D34();
    u8 *q = *(u8 **)(lbl_803471B8 + 0x24);

    q[0x9] = v;
}

void fn_801C2C4C(u8 i, u8 v) {
    Mem* m = &lbl_8030B7F4[(u16)(*(Party**)&lbl_803471B8)->sheet->rows[i].slot];
    m->xf = v;
}

u8 fn_801C2C84(u8 i) {
    Mem* m = &lbl_8030B7F4[(u16)(*(Party**)&lbl_803471B8)->sheet->rows[i].slot];
    return m->xf;
}

void fn_801C0AB4(s32 a, u8 i)
{
    s16 id = a;
    switch (fn_801F4C24(id)) {
    case 0:
        fn_801F4E6C((*(Party_801C0AB4**)&lbl_803471B8)->sheet->rows[i].slot, id);
        break;
    case 1:
        fn_801F4E38((*(Party_801C0AB4**)&lbl_803471B8)->sheet->rows[i].slot, id);
        break;
    case 2:
        fn_801F4E04((*(Party_801C0AB4**)&lbl_803471B8)->sheet->rows[i].slot, id);
        break;
    }
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

/* -1 unless the item is of kind 5, else its table byte. Takes s16 (no extsh at the call);
 * unit_80199B9C.c declares it `u16 fn_801C16D0(s16)`, the code returns the sign-extended s8. */
s32 fn_801C16D0(s16 id) {
    if (fn_801F4C24(id) != 5) {
        return -1;
    }
    return lbl_802D7E4C[id - 400].type;
}
