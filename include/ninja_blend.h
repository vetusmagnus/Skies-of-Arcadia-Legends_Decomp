#ifndef NINJA_BLEND_H
#define NINJA_BLEND_H

/* set_blend, inlined into fn_8029D010 (ninja.c) and fn_8029D698 (ninja_8029D698.c). It has its own
 * header because MWCC emits the table's initializer (48 bytes of .rodata) in every file that sees
 * the definition, used or not. */

#include "ninja_lib.h"

/* Blend factors from a material's attribute word (bits 11-13 source, 8-10 destination); with
 * _nj_control_3d_flag_ & 0x8000 the override mode lbl_80347EE0 is used instead. */
static inline void set_blend(u32 mode) {
    u32 tbl[12] = {0, 1, 2, 3, 4, 5, 6, 7, 0, 0, 0, 0};
    u16 src, dst;
    if (_nj_control_3d_flag_ & 0x8000) {
        mode = lbl_80347EE0;
    }
    src = tbl[(mode >> 11) & 7];
    dst = tbl[(mode >> 8) & 7];
    lbl_803457A8.blendSrc = src;
    lbl_803457A8.blendDst = dst;
    GXSetBlendMode(lbl_803457A8.blendType, src, dst, lbl_803457A8.blendOp);
}

#endif
