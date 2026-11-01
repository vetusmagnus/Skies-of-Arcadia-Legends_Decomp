/* fn_80286EE8 (duplicate group 40 with fn_8028B498, the second light table): a near miss.
 *
 *   python tools/match/fdiff.py docs/near/fn_80286EE8.c fn_80286EE8
 *
 * Per-frame light update: clear both channel masks, transform each active light's position into
 * view space, OR the masks of kind 0/3 lights into GX_COLOR0/GX_ALPHA0, then set the channel
 * functions and the dirty flags. 62 of 65 instructions, 23 diff lines. Both builds keep the table
 * address twice, a light walker and a base for chan[1], but in opposite directions: the original
 * makes the walker first (`addi r30`) and copies it for the base (`mr r31, r30`); this file does the
 * reverse. The original also hoists `r29 = base + 0x30c` for chan[0].mask, which this build folds into
 * a 0x30c displacement on the base. Tried: a NjLight* walker, a NjLightTbl* local, a
 * NjChanCtrl* or s32* local for chan[0] (in every declaration order), global vs local access
 * for the clears and the final test; MWCC folds each pointer back into the base.
 */
#include "ninja_lib.h"

void fn_80286EE8(void) {
    NjLightTbl* t = &lbl_80344DE0;
    s32 i;
    t->chan[0].mask = 0;
    t->chan[1].mask = 0;
    for (i = 0; i < 8; i++) {
        if (t->light[i].type == 1) {
            PSMTXMultVec(lbl_80347EB4, &t->light[i].pos, &t->light[i].vpos);
            switch (t->light[i].kind) {
            case 0:
            case 3:
                t->chan[0].mask |= t->light[i].mask;
                t->chan[1].mask |= t->light[i].mask;
                break;
            }
        }
    }
    if (t->chan[0].mask != 0) {
        lbl_80344DE0.chan[0].diff_fn = 2;
        lbl_80344DE0.chan[0].attn_fn = 1;
        lbl_80344DE0.chan[1].diff_fn = 2;
        lbl_80344DE0.chan[1].attn_fn = 1;
    }
    lbl_80344DE0.light[0].w00 = 1;
    lbl_80344DE0.dirty = 1;
}
