/* fn_8028A0F4: matches with GC/1.3.2nj (tools/patch_mwcc_ninja.py), not with any stock compiler.
 *
 * Coloured triangle-strip drawer, loop unrolled 4x by the compiler; address copies r6 (x, y), r5 (z), r4 (colour). Vertex layout as the game's VertexCol (draw2d.c).
 *
 *   CCV=1.3.2nj python tools/match/fdiff.py docs/mwcc_ninja/fn_8028A0F4.c fn_8028A0F4
 */
#include "ninja_lib.h"

typedef struct { f32 x, y, z; u32 col; } NjColVtx;

void fn_8028A0F4(NjColVtx* v, s32 n) {
    s32 i;
    GXBegin(GX_TRIANGLESTRIP, GX_VTXFMT0, n);
    for (i = 0; i < n; i++, v++) {
        GXPosition3f32(v->x, v->y, v->z * lbl_80347F30 + lbl_80347F34);
        GXColor1u32(__rlwinm(v->col, 8, 0, 31));
    }
}
