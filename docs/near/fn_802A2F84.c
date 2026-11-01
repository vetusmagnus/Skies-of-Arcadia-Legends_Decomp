/* fn_802A2F84 and its family: near misses with GC/1.3.2nj, one load out of place.
 *
 *   CCV=1.3.2nj python tools/match/fdiff.py docs/near/fn_802A2F84.c fn_802A2F84
 *
 * The indexed strip drawers that send each vertex value once (position only, position + colour,
 * position + separate normal) match except for one line: the original loads the vertex fields in
 * order (`lfs f0,0x0(r3); lfs f1,0x4(r3); ...`); here the field at offset 0 (`q->pos.x`, i.e. `*q`)
 * is loaded last. It is already last in the PCode before the first PCode pass runs, so it comes
 * from the front end / IRO, not from the passes tools/patch_mwcc_ninja.py touches. When the values
 * are used twice (the drawers that send the position as the normal too: fn_802A2604, fn_802A2C84,
 * fn_802A2E18, fn_802A3EDC, fn_802A46EC, fn_802A4884) the same source keeps the order and matches.
 * Statement order shows the rule: every load keeps its place except the offset-0 one, whatever
 * position it is written in. Tried: locals, block-scope initialisers, `register`, a local array or
 * struct, direct GXWGFifo writes, an `f32*` view, indexing v[idx] without q, `const`, the skip
 * before/after the loads, an inline taking the pointer or the values; every GC compiler.
 * Probably a second difference in the original compiler, at the IRO level (forwarding a single-use
 * `*q` load to its use). encounter's 1.3.2 IRO-logging patch (decomp Discord, #metroid-prime) is the
 * tool to look at it.
 *
 * Same one line: fn_802A2394, fn_802A24CC (position only), fn_802A292C (position + colour),
 * fn_802A2F84, fn_802A30FC, fn_802A3274, fn_802A4E4C, fn_802A58DC (position + normal),
 * fn_802A35F0, fn_802A3994, fn_802A5738 (position + normal + colour), and fn_802A3B34 (textured,
 * after its register differences).
 */
#include "../src/ninja/ninja.c" /* found through -i include */

void fn_802A2F84(s16* p, NjPosNrm* v, u32 hdr, s32 side) {
    s32 len;
    s32 total;
    u32 cull = -1;
    s32 nuv;
    u32 mode;
    NjPosNrm* q;
    f32 x, y, z;
    f32 nx, ny, nz;

    fn_8029B058(1, 1);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_NRM, GX_NRM_XYZ, GX_F32, 0);
    total = 0;
    nuv = (hdr >> 14) & 3;
    hdr &= 0x3fff;
    do {
        len = *p++;
        if (len < 0) {
            len = -len;
            mode = lbl_80300898[side][lbl_80347E20];
            if (cull != mode) {
                cull = mode;
                GXSetCullMode(mode);
            }
        } else {
            mode = lbl_803008C0[side][lbl_80347E20];
            if (cull != mode) {
                cull = mode;
                GXSetCullMode(mode);
            }
        }
        total += len;
        GXBegin(GX_TRIANGLESTRIP, GX_VTXFMT0, len);
        do {
            q = &v[*p++];
            p += nuv;
            x = q->pos.x;
            y = q->pos.y;
            z = q->pos.z;
            nx = q->nrm.x;
            ny = q->nrm.y;
            nz = q->nrm.z;
            GXPosition3f32(x, y, z);
            GXNormal3f32(nx, ny, nz);
        } while (--len);
    } while (--hdr);
    lbl_80347EF0 += total;
}
