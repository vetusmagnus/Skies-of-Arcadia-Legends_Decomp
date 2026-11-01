/* fn_802A1160 (0x214, duplicate group 12 with fn_802A7680): a near miss.
 *
 *   python tools/match/fdiff.py docs/near/fn_802A1160.c fn_802A1160
 *
 * The chunk-model draw callback of the second renderer: the clip test and the draw-mode switch are
 * written like fn_80287C14 (its first-renderer counterpart) and match. The vertex chunk loop is the
 * open part (38 diff lines, 131 of 133 instructions): the original keeps `v`, `base` and the
 * NjEnvState address in copies (`mr r9,r0`, `mr r10,r4`, `mr r5,r6`) and uses one copy of
 * &lbl_80300760 for n/data and the other for dst. That is the per-use copy shape docs/ninja.md
 * records for &lbl_80346620 in fn_802873BC. Tried: the loop inline in the function, as one inline
 * taking (v, base) or (v, base, env), with an env local, and with nested inlines for the dst store,
 * the n/data/count stores or the whole chunk (this file, the best at 38 lines). `flags` is only set
 * inside the loop; the original stores the last chunk's flags after it, uninitialised when the list
 * is empty.
 */
#include "ninja_lib.h"
#include "ninja.h"

extern u32 lbl_80347F80;

inline void VtxChunk(NjEnvState* e, u32* v, void* base, u32 w) {
    e->n = w >> 16;
    e->data = v;
    lbl_80347EF4 += w >> 16;
    /* base is the untyped vertex buffer (lbl_80347EFC); the chunk's low half is a word offset into it */
    e->dst = (u32*)base + (w & 0xFFFF);
}
inline void VtxChunks(u32* v, void* base) {
    u32 hdr, w, flags;
    while (((hdr = *v) & 0xFF) != 0xFF) {
        w = v[1];
        v += 2;
        VtxChunk(&lbl_80300760, v, base, w);
        v += (hdr >> 16) - 1;
        flags = hdr & 0x7FFF;
    }
    lbl_80347F80 = flags;
}

s32 fn_802A1160(NjModel* m) {
    u32* v;
    s16* p;
    void* base;
    if ((_nj_control_3d_flag_ & 0x100) && m->r > 0.0f) {
        if (fn_80288C68(m)) {
            return -1;
        }
    }
    v = m->vlist;
    base = lbl_80347EFC;
    if (v) {
        VtxChunks(v, base);
    }
    p = m->plist;
    if (p) {
        fn_8029CA58();
        switch (lbl_80346A50) {
        case 1:
            lbl_80347E20 = 0;
            fn_802A1374(p, lbl_80347F80, lbl_80300760.data);
            break;
        case 2:
            lbl_80347E20 = 1;
            fn_802A1374(p, lbl_80347F80, lbl_80300760.data);
            break;
        case 3:
            lbl_80347E20 = 2;
            fn_802A1374(p, lbl_80347F80, lbl_80300760.data);
            break;
        case 4:
            lbl_80347E20 = 3;
            fn_802A1374(p, lbl_80347F80, lbl_80300760.data);
            lbl_80347E20 = 4;
            fn_802A1374(p, lbl_80347F80, lbl_80300760.data);
            break;
        case 5:
            lbl_80347E20 = 3;
            fn_802A1374(p, lbl_80347F80, lbl_80300760.data);
            break;
        case 6:
            lbl_80347E20 = 4;
            fn_802A1374(p, lbl_80347F80, lbl_80300760.data);
            break;
        }
    }
    return 0;
}
