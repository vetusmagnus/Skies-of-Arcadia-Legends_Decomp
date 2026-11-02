/* DRAFT, not matching: 312 diff lines with 1.3.2nj, but the same 425 instructions in the same order:
 * box (8 corners) vs sphere (x,y,z,r) test. unit src/ninja/ninja.c, before fn_8028F884 (after fn_8028BC64's
 * missing neighbours fn_8028BE90..fn_8028DD5C, i.e. right before fn_8028F408 once that exists).
 * No header changes. What is right: local initializers inside the if (copied after fn_8028BBCC), idx[5]
 * re-initialised inside the inner loop, dot3 as a static inline (gives the separate fneg and n*p operand
 * order), n as f32[6][3] indexed n[adj[i][e0]][k] (gives the hoisted base + lfsx), e0 = idx[j] (keeps
 * idx[j]<<2 for faces and adj), `x &= 1` / `x &= 0` branches (clrlwi / li 0).
 * Left: register assignment only. GPRs: the original gives v r30, s r31 and the rodata base r29 (reused for
 * `in`); here v r29, s r30, base r31 (the parameter-copy form breaks the loops); faces/n pointers r10/r9 swap.
 * FPRs from the plane projection on (t in f4, q in f5-f7 in the original). Declaration orders of all scalars
 * don't change it. */
void fn_80290708(f32* v, f32* lo, f32* hi);
static inline f32 dot3(f32* a, f32* b) {
    return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}

s32 fn_8028ED64(NJS_POINT3* v, f32* s) {
    NJS_POINT3 lo, hi, slo, shi;
    NJS_POINT3* p0;
    NJS_POINT3* p1;
    NJS_POINT3* p2;
    NJS_POINT3 q, c, w;
    f32 x;
    f32 y;
    f32 z;
    f32 t;
    f32 d;
    f32 len;
    s32 e0;
    s32 i;
    s32 j;
    s32 out;
    s32 in;

    fn_80290428(v, &lo, &hi);
    fn_80290708(s, &slo.x, &shi.x);
    if (fn_8028BBCC(&lo, &hi, &slo, &shi)) {
    s32 faces[6][4] = {{0, 1, 2, 3}, {4, 7, 6, 5}, {0, 3, 7, 4}, {2, 1, 5, 6}, {0, 4, 5, 1}, {3, 2, 6, 7}};
    f32 n[6][3];
    s32 adj[6][4] = {{4, 3, 5, 2}, {2, 5, 3, 4}, {0, 5, 1, 4}, {0, 4, 1, 5}, {2, 1, 3, 0}, {0, 3, 1, 2}};
    out = 1;
    for (i = 0; i < 6; i++) {
        p0 = &v[faces[i][0]];
        p2 = &v[faces[i][2]];
        p1 = &v[faces[i][1]];
        n[i][0] = -((p1->y - p0->y) * (p2->z - p0->z) - (p1->z - p0->z) * (p2->y - p0->y));
        n[i][1] = -((p1->z - p0->z) * (p2->x - p0->x) - (p1->x - p0->x) * (p2->z - p0->z));
        n[i][2] = -((p1->x - p0->x) * (p2->y - p0->y) - (p1->y - p0->y) * (p2->x - p0->x));
        x = n[i][0] * n[i][0];
        y = n[i][1] * n[i][1];
        z = n[i][2] * n[i][2];
        len = 1.0f / sqrtf(x + y + z);
        n[i][0] *= len;
        n[i][1] *= len;
        n[i][2] *= len;
    }
    for (i = 0; i < 6; i++) {
        in = 1;
        p0 = &v[faces[i][0]];
        t = -(-dot3(n[i], &p0->x) + dot3(s, n[i])) / dot3(n[i], n[i]);
        q.x = t * n[i][0] + s[0];
        q.y = t * n[i][1] + s[1];
        q.z = t * n[i][2] + s[2];
        x = (q.x - s[0]) * (q.x - s[0]);
        y = (q.y - s[1]) * (q.y - s[1]);
        z = (q.z - s[2]) * (q.z - s[2]);
        d = sqrtf(x + y + z);
        for (j = 0; j < 4; j++) {
            s32 idx[5] = {0, 1, 2, 3, 0};
            e0 = idx[j];
            p0 = &v[faces[i][e0]];
            p1 = &v[faces[i][idx[j + 1]]];
            w.x = p0->x - p1->x;
            w.y = p0->y - p1->y;
            w.z = p0->z - p1->z;
            t = (w.x * (q.x - p0->x) + w.y * (q.y - p0->y) + w.z * (q.z - p0->z)) / (w.x * w.x + w.y * w.y + w.z * w.z);
            c.x = w.x * t + p0->x;
            c.y = w.y * t + p0->y;
            c.z = w.z * t + p0->z;
            w.x = c.x - q.x;
            w.y = c.y - q.y;
            w.z = c.z - q.z;
            len = 1.0f / sqrtf(w.x * w.x + w.y * w.y + w.z * w.z);
            w.x *= len;
            w.y *= len;
            w.z *= len;
            if ((f32)fabs(n[adj[i][e0]][0] - w.x) <= 0.025f && (f32)fabs(n[adj[i][e0]][1] - w.y) <= 0.025f &&
                (f32)fabs(n[adj[i][e0]][2] - w.z) <= 0.025f && s[3] >= d) {

                in &= 1;
            } else if (d <= s[3]) {
                x = (q.x - c.x) * (q.x - c.x);
                y = (q.y - c.y) * (q.y - c.y);
                z = (q.z - c.z) * (q.z - c.z);
                if (x + y + z <= s[3] * s[3] - d * d) {
                    in &= 1;
                } else {
                    in &= 0;
                }
            } else {
                in &= 0;
            }
        }
        if (in) return 1;
        w.x = q.x - s[0];
        w.y = q.y - s[1];
        w.z = q.z - s[2];
        len = 1.0f / sqrtf(w.x * w.x + w.y * w.y + w.z * w.z);
        w.x *= len;
        w.y *= len;
        w.z *= len;
        if ((f32)fabs(n[i][0] - w.x) <= 0.025f && (f32)fabs(n[i][1] - w.y) <= 0.025f && (f32)fabs(n[i][2] - w.z) <= 0.025f) {
            out &= 1;
        } else {
            out &= 0;
        }
    }
    if (out) return 1;
    }
    return 0;
}
