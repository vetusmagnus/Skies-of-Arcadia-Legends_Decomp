#include "types.h"
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
