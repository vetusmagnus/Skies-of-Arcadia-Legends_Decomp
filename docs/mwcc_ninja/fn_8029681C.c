/* fn_8029681C: matches with GC/1.3.2nj (tools/patch_mwcc_ninja.py), not with any stock compiler.
 *
 * Point drawer (GX_POINTS). The FIFO address gets one register for x and y, a copy for z.
 *
 *   CCV=1.3.2nj python tools/match/fdiff.py docs/mwcc_ninja/fn_8029681C.c fn_8029681C
 */
#include "ninja_lib.h"

static inline void Pos3(f32 x, f32 y, f32 z) {
    GXWGFifo.f32 = x;
    GXWGFifo.f32 = y;
    GXWGFifo.f32 = z;
}

void fn_8029681C(NJS_POINT3* p, s32 n, f32 size) {
    GXSetPointSize(size * 12.0f, 0);
    do {
        GXBegin(GX_POINTS, GX_VTXFMT0, 1);
        Pos3(p->x, p->y, p->z);
        p++;
    } while (--n);
}
