/* DRAFT F5: fn_8028CF20, 4 diff lines (1.3.2nj; stock: worse, constant copies), 753 instructions, same order.
 * Unit src/ninja/ninja.c, right after fn_8028BC64 (fn_8028BE90 still missing), before fn_8028F884. No header changes.
 * Key change: the edge length's sum in its own local (l = x + y; sqrtf(l)) fixes the 2nd triangle's FPR.
 * Left: in the last-evaluated triangle (small[i], big[0], big[1]) dy is f23 where the original has f22. */

static inline f32 TriArea2D(const NJS_POINT2* p0, const NJS_POINT2* p1, const NJS_POINT2* q) {
    f32 a, b, c, h, dx, dy, x, y, l;
    if ((f32)fabs(p0->x - p1->x) < 0.025f) {
        a = 1.0f;
        b = 0.0f;
        c = -p0->x;
    } else {
        a = p1->y - p0->y;
        b = -(p1->x - p0->x);
        c = -p0->x * a - p0->y * b;
    }
    h = fabsf(c + (a * q->x + b * q->y)) / sqrtf(a * a + b * b);
    dx = p0->x - p1->x;
    dy = p0->y - p1->y;
    x = dx * dx;
    y = dy * dy;
    l = x + y;
    return 0.5f * (h * sqrtf(l));
}

s32 fn_8028CF20(NJS_POINT2* a, NJS_POINT2* b) {
    NJS_POINT2* big;
    NJS_POINT2* small;
    f32 sa, sb, area;
    s32 i;
    sa = TriArea2D(&a[0], &a[1], &a[2]) + TriArea2D(&a[0], &a[2], &a[3]);
    sb = TriArea2D(&b[0], &b[1], &b[2]) + TriArea2D(&b[0], &b[2], &b[3]);
    if (sa < sb) {
        area = sb;
        small = a;
        big = b;
    } else {
        area = sa;
        small = b;
        big = a;
    }
    for (i = 0; i < 4; i++) {
        if (TriArea2D(&small[i], &big[0], &big[1]) + TriArea2D(&small[i], &big[1], &big[2]) + TriArea2D(&small[i], &big[2], &big[3]) + TriArea2D(&small[i], &big[3], &big[0]) < 1.025f * area) {
            return 1;
        }
    }
    return 0;
}
