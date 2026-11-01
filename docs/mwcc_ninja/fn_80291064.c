/* fn_80291064: matches with GC/1.3.2nj (tools/patch_mwcc_ninja.py), not with any stock compiler.
 *
 * Textured sprite drawer called by SpriteObjDraw/UiSpriteDraw; loop unrolled 2x; five address copies (r8 x/y, r7 z, r6 colour, r5 u, r4 v). Vertex layout as the game's VertexTex (draw2d.c).
 *
 *   CCV=1.3.2nj python tools/match/fdiff.py docs/mwcc_ninja/fn_80291064.c fn_80291064
 */
#include "ninja_lib.h"

typedef struct { f32 x, y, z; f32 u, v; u32 col; } NjTexVtx;

void fn_80291064(NjTexVtx* v, s32 n, s32 flag) {
    s32 i;
    fn_8029CB74();
    fn_8029B248(0, flag);
    GXBegin(GX_TRIANGLESTRIP, GX_VTXFMT0, n);
    for (i = 0; i < n; i++, v++) {
        GXPosition3f32(v->x, v->y, v->z * lbl_80347F30 + lbl_80347F34);
        GXColor1u32(__rlwinm(v->col, 8, 0, 31));
        GXTexCoord2f32(v->u, v->v);
    }
}
