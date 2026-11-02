/* DRAFT F5: fn_8028BE90 (3D quad-quad overlap: 2D edge-edge intersection tests on the xy, xz and yz projections, then
 * fn_8028CF20 on each projection), first attempt. 1.3.2nj: 1060 instructions in the original; 458 diff lines here (stock 1.3.2: 466), same 1060 instructions; the same spilled set (first projection's a0/a1, each projection's xa, the third's cb) but different FPRs and spill slots. Each projection is a { } block with its own declarations in the same order (as a macro would give); that order is a hill-climb result (natural order: 608). Earlier variant with per-projection suffixed variables only for the maybe-unset ones: 318 lines with a searched order, 1058 insns.
 * Unit src/ninja/ninja.c, right after fn_8028BC64, before fn_8028CF20.
 * Header change: ninja_lib.h's prototype becomes s32 fn_8028BE90(const NJS_POINT3* qa, const NJS_POINT3* qb)
 * (const lets the 16 coordinate loads of each fn_8028CF20 copy move above the stores, as in fn_8028BC64).
 * Key finding: the original's stack slots in the first projection are register-allocator spills, not locals. MWCC
 * treats a variable that may be read before it is written (slope/intercept/x of a vertical edge/intersection point:
 * set only on some paths) as live from function entry, so each projection having its OWN copies of those variables
 * (ma/ca/xa/mb/cb/xb/px/py, plus va/vb/par/o1/o2 for the instruction order) makes all three sets live through the first
 * projection: that is what exhausts f0-f12 there and spills a0/a1 and xa. One shared set gives 998 instructions.
 * Float declaration order changes the colouring a lot (1010 -> ~350 by search); the order below is a search result. */
s32 fn_8028BE90(const NJS_POINT3* qa, const NJS_POINT3* qb) {
    NJS_POINT2 a[4];
    NJS_POINT2 b[4];
    s32 k;
    s32 hxy, hxz, hyz, cxy, cxz, cyz;
    s32 ret;

    hxy = 0;
    hxz = 0;
    hyz = 0;
    {
        f32 a0x, b0x, a0y, sx, a1x, a1y, sy, b0y, b1x, b1y, la, ma, d2, xa, ca, px, d1, py, mb, cb, xb;
        s32 vb, i, o1, va, j, o2, par;

        a0x = qa[3].x;
        a0y = qa[3].y;
        for (i = 0; i < 4; i++) {
            a1x = qa[i].x;
            a1y = qa[i].y;
            if (a0x < a1x - 0.025f || a0x > 0.025f + a1x) {
                va = 0;
                ma = (a1y - a0y) / (a1x - a0x);
                ca = a0y - ma * a0x;
            } else {
                xa = a0x;
                va = 1;
            }
            sx = (a0x - a1x) * (a0x - a1x);
            sy = (a0y - a1y) * (a0y - a1y);
            la = sx + sy;
            b0x = qb[3].x;
            b0y = qb[3].y;
            for (j = 0; j < 4; j++) {
                b1x = qb[j].x;
                b1y = qb[j].y;
                par = 0;
                if (b0x < b1x - 0.025f || b0x > 0.025f + b1x) {
                    vb = 0;
                    mb = (b1y - b0y) / (b1x - b0x);
                    cb = b0y - mb * b0x;
                } else {
                    xb = b0x;
                    vb = 1;
                }
                if (va == 0 && vb == 0) {
                    if (ma < mb - 0.025f || ma > 0.025f + mb) {
                        px = (cb - ca) / (ma - mb);
                        py = ma * px + ca;
                    } else {
                        par = 1;
                    }
                } else if (vb == 0) {
                    px = xa;
                    py = mb * px + cb;
                } else if (va == 0) {
                    px = xb;
                    py = ma * xb + ca;
                } else {
                    par = 1;
                }
                if (par == 0) {
                    o1 = 0;
                    o2 = 0;
                    sx = (a0x - px) * (a0x - px);
                    sy = (a0y - py) * (a0y - py);
                    d1 = sqrtf(sx + sy);
                    sx = (a1x - px) * (a1x - px);
                    sy = (a1y - py) * (a1y - py);
                    d2 = sqrtf(sx + sy);
                    if (0.025f + sqrtf(la) >= d1 + d2 - 0.025f) {
                        o1 = 1;
                    }
                    sx = (b0x - px) * (b0x - px);
                    sy = (b0y - py) * (b0y - py);
                    d1 = sqrtf(sx + sy);
                    sx = (b1x - px) * (b1x - px);
                    sy = (b1y - py) * (b1y - py);
                    d2 = sqrtf(sx + sy);
                    sx = (b0x - b1x) * (b0x - b1x);
                    sy = (b0y - b1y) * (b0y - b1y);
                    if (0.025f + sqrtf(sx + sy) >= d1 + d2 - 0.025f) {
                        o2 = 1;
                    }
                    if (o1 && o2) {
                        hxy = 1;
                        break;
                    }
                }
                b0x = b1x;
                b0y = b1y;
            }
            if (hxy) break;
            a0x = a1x;
            a0y = a1y;
        }
    }
    {
        f32 a0x, b0x, a0y, sx, a1x, a1y, sy, b0y, b1x, b1y, la, ma, d2, xa, ca, px, d1, py, mb, cb, xb;
        s32 vb, i, o1, va, j, o2, par;

        a0x = qa[3].x;
        a0y = qa[3].z;
        for (i = 0; i < 4; i++) {
            a1x = qa[i].x;
            a1y = qa[i].z;
            if (a0x < a1x - 0.025f || a0x > 0.025f + a1x) {
                va = 0;
                ma = (a1y - a0y) / (a1x - a0x);
                ca = a0y - ma * a0x;
            } else {
                xa = a0x;
                va = 1;
            }
            sx = (a0x - a1x) * (a0x - a1x);
            sy = (a0y - a1y) * (a0y - a1y);
            la = sx + sy;
            b0x = qb[3].x;
            b0y = qb[3].z;
            for (j = 0; j < 4; j++) {
                b1x = qb[j].x;
                b1y = qb[j].z;
                par = 0;
                if (b0x < b1x - 0.025f || b0x > 0.025f + b1x) {
                    vb = 0;
                    mb = (b1y - b0y) / (b1x - b0x);
                    cb = b0y - mb * b0x;
                } else {
                    xb = b0x;
                    vb = 1;
                }
                if (va == 0 && vb == 0) {
                    if (ma < mb - 0.025f || ma > 0.025f + mb) {
                        px = (cb - ca) / (ma - mb);
                        py = ma * px + ca;
                    } else {
                        par = 1;
                    }
                } else if (vb == 0) {
                    px = xa;
                    py = mb * px + cb;
                } else if (va == 0) {
                    px = xb;
                    py = ma * xb + ca;
                } else {
                    par = 1;
                }
                if (par == 0) {
                    o1 = 0;
                    o2 = 0;
                    sx = (a0x - px) * (a0x - px);
                    sy = (a0y - py) * (a0y - py);
                    d1 = sqrtf(sx + sy);
                    sx = (a1x - px) * (a1x - px);
                    sy = (a1y - py) * (a1y - py);
                    d2 = sqrtf(sx + sy);
                    if (0.025f + sqrtf(la) >= d1 + d2 - 0.025f) {
                        o1 = 1;
                    }
                    sx = (b0x - px) * (b0x - px);
                    sy = (b0y - py) * (b0y - py);
                    d1 = sqrtf(sx + sy);
                    sx = (b1x - px) * (b1x - px);
                    sy = (b1y - py) * (b1y - py);
                    d2 = sqrtf(sx + sy);
                    sx = (b0x - b1x) * (b0x - b1x);
                    sy = (b0y - b1y) * (b0y - b1y);
                    if (0.025f + sqrtf(sx + sy) >= d1 + d2 - 0.025f) {
                        o2 = 1;
                    }
                    if (o1 && o2) {
                        hxz = 1;
                        break;
                    }
                }
                b0x = b1x;
                b0y = b1y;
            }
            if (hxz) break;
            a0x = a1x;
            a0y = a1y;
        }
    }
    {
        f32 a0x, b0x, a0y, sx, a1x, a1y, sy, b0y, b1x, b1y, la, ma, d2, xa, ca, px, d1, py, mb, cb, xb;
        s32 vb, i, o1, va, j, o2, par;

        a0x = qa[3].y;
        a0y = qa[3].z;
        for (i = 0; i < 4; i++) {
            a1x = qa[i].y;
            a1y = qa[i].z;
            if (a0x < a1x - 0.025f || a0x > 0.025f + a1x) {
                va = 0;
                ma = (a1y - a0y) / (a1x - a0x);
                ca = a0y - ma * a0x;
            } else {
                xa = a0x;
                va = 1;
            }
            sx = (a0x - a1x) * (a0x - a1x);
            sy = (a0y - a1y) * (a0y - a1y);
            la = sx + sy;
            b0x = qb[3].y;
            b0y = qb[3].z;
            for (j = 0; j < 4; j++) {
                b1x = qb[j].y;
                b1y = qb[j].z;
                par = 0;
                if (b0x < b1x - 0.025f || b0x > 0.025f + b1x) {
                    vb = 0;
                    mb = (b1y - b0y) / (b1x - b0x);
                    cb = b0y - mb * b0x;
                } else {
                    xb = b0x;
                    vb = 1;
                }
                if (va == 0 && vb == 0) {
                    if (ma < mb - 0.025f || ma > 0.025f + mb) {
                        px = (cb - ca) / (ma - mb);
                        py = ma * px + ca;
                    } else {
                        par = 1;
                    }
                } else if (vb == 0) {
                    px = xa;
                    py = mb * px + cb;
                } else if (va == 0) {
                    px = xb;
                    py = ma * xb + ca;
                } else {
                    par = 1;
                }
                if (par == 0) {
                    o1 = 0;
                    o2 = 0;
                    sx = (a0x - px) * (a0x - px);
                    sy = (a0y - py) * (a0y - py);
                    d1 = sqrtf(sx + sy);
                    sx = (a1x - px) * (a1x - px);
                    sy = (a1y - py) * (a1y - py);
                    d2 = sqrtf(sx + sy);
                    if (0.025f + sqrtf(la) >= d1 + d2 - 0.025f) {
                        o1 = 1;
                    }
                    sx = (b0x - px) * (b0x - px);
                    sy = (b0y - py) * (b0y - py);
                    d1 = sqrtf(sx + sy);
                    sx = (b1x - px) * (b1x - px);
                    sy = (b1y - py) * (b1y - py);
                    d2 = sqrtf(sx + sy);
                    sx = (b0x - b1x) * (b0x - b1x);
                    sy = (b0y - b1y) * (b0y - b1y);
                    if (0.025f + sqrtf(sx + sy) >= d1 + d2 - 0.025f) {
                        o2 = 1;
                    }
                    if (o1 && o2) {
                        hyz = 1;
                        break;
                    }
                }
                b0x = b1x;
                b0y = b1y;
            }
            if (hyz) break;
            a0x = a1x;
            a0y = a1y;
        }
    }
    for (k = 0; k < 4; k++) {
        a[k].x = qa[k].x;
        a[k].y = qa[k].y;
        b[k].x = qb[k].x;
        b[k].y = qb[k].y;
    }
    cxy = fn_8028CF20(a, b);
    for (k = 0; k < 4; k++) {
        a[k].x = qa[k].x;
        a[k].y = qa[k].z;
        b[k].x = qb[k].x;
        b[k].y = qb[k].z;
    }
    cxz = fn_8028CF20(a, b);
    for (k = 0; k < 4; k++) {
        a[k].x = qa[k].y;
        a[k].y = qa[k].z;
        b[k].x = qb[k].y;
        b[k].y = qb[k].z;
    }
    cyz = fn_8028CF20(a, b);
    ret = 0;
    if ((hxy || cxy) && (hxz || cxz) && (hyz || cyz)) {
        ret = 1;
    }
    return ret;
}
