/* fn_80298544: matches with GC/1.3.2nj (tools/patch_mwcc_ninja.py), not with any stock compiler.
 *
 * Texture reference table reset. The 8x-unrolled body matches with stock 1.3.2 too; the leftover
 * loop for n % 8 keeps `li r9,0` plus `mr r7,r9; mr r6,r9; mr r5,r9` only with the patch.
 *
 *   CCV=1.3.2nj python tools/match/fdiff.py docs/mwcc_ninja/fn_80298544.c fn_80298544
 */
#include "ninja_lib.h"

void fn_80298544(NjTexRef* refs, s32 n) {
    s32 i;
    lbl_80347ED4 = refs;
    lbl_80347ED0 = n;
    for (i = 0; i < n; i++) {
        refs->w00 = 0;
        refs->w04 = 0;
        refs->key = -1;
        refs->mem = NULL;
        refs->refs = 0;
        refs->w14 = 0;
        refs++;
    }
}
