#include "types.h"

extern u16 lbl_8030A2F4[18];
extern char lbl_802EE634[];
void *fn_801F4AE4(s16 idx);
extern u8 *lbl_803471B8;
extern u8 fn_801C0D34(void);

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
