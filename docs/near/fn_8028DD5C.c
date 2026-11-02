/* DRAFT F5: fn_8028DD5C (box vs capsule), first attempt. 1.3.2nj: same 1026 instructions in the same order
 * (opcode for opcode, including the table offsets); registers differ (1062 diff lines in the real unit).
 * Unit src/ninja/ninja.c, after fn_8028DAE4 (missing), before fn_8028ED64 (missing) / fn_8028F884.
 * No header changes (adds a prototype for fn_80290008, defined later in the unit, and the dot3/dist3 static inlines;
 * dot3 is the same as in docs/near/fn_8028ED64.c; share one if both match).
 * Shape: fn_8028ED64's skeleton with the capsule axis u (normalised p1-p0) instead of the sphere centre.
 * Key forms: u as an NJS_POINT3 (scalars ax/ay/az: 1526 lines), the three fabs terms of the edge test computed into
 * x/y/z before the if, e1 = idx[j+1] kept, `/ dot3(n[i], n[i])` written twice (a nn local gives fmuls+fadds).
 * Left: allocation. The original gives the outer-loop pointers (faces/n/adj rows) and idx values saved registers
 * r19-r26 and the axis f20-f22 although no call follows; here they take volatile registers (u.z in f8), so
 * everything after shifts. v r27/c r28/base r31 in the original, v r26/c r27/base r25 here. Declaration orders
 * (ints, floats, structs): no effect. Parameter copies (opt_propagation off): worse (1398, +16 insns). */
f32 fn_80290008(f32* a, f32* b);
static inline f32 dot3(f32* a, f32* b) {
    return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}

static inline f32 dist3(f32* a, f32* b) {
    f32 x, y, z;
    x = (a[0] - b[0]) * (a[0] - b[0]);
    y = (a[1] - b[1]) * (a[1] - b[1]);
    z = (a[2] - b[2]) * (a[2] - b[2]);
    return sqrtf(x + y + z);
}

s32 fn_8028DD5C(NJS_POINT3* v, NjCapsule* c) {
    NJS_POINT3 lo, hi, clo, chi;
    NJS_POINT3* p0;
    NJS_POINT3* p1;
    NJS_POINT3* p2;
    NJS_POINT3 u, q, cp, w, q0, q1, w0, w1;
    f32 x, y, z;
    f32 t, t0, t1, d, len, l, d0, d1, e, h, m, nn;
    f32 sum0, sum1;
    s32 e0, e1, i, j, in, na, nb, nc, in0, in1, cnt0, cnt1, k0, k1;

    fn_80290428(v, &lo, &hi);
    fn_802904E8(c, &clo, &chi);
    if (fn_8028BBCC(&lo, &hi, &clo, &chi)) {
    s32 faces[6][4] = {{0, 1, 2, 3}, {4, 7, 6, 5}, {0, 3, 7, 4}, {2, 1, 5, 6}, {0, 4, 5, 1}, {3, 2, 6, 7}};
    f32 n[6][3];
    s32 adj[6][4] = {{4, 3, 5, 2}, {2, 5, 3, 4}, {0, 5, 1, 4}, {0, 4, 1, 5}, {2, 1, 3, 0}, {0, 3, 1, 2}};
    sum0 = sum1 = 0.0f;
    in0 = 1;
    in1 = 1;
    cnt0 = 0;
    cnt1 = 0;
    k0 = 0;
    k1 = 0;
    len = fn_80290008(&c->p0.x, &c->p1.x);
    u.x = c->p1.x - c->p0.x;
    u.y = c->p1.y - c->p0.y;
    u.z = c->p1.z - c->p0.z;
    l = 1.0f / sqrtf(u.x * u.x + u.y * u.y + u.z * u.z);
    u.x *= l;
    u.y *= l;
    u.z *= l;
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
        l = 1.0f / sqrtf(x + y + z);
        n[i][0] *= l;
        n[i][1] *= l;
        n[i][2] *= l;
    }
    for (i = 0; i < 6; i++) {
        in = 1;
        na = 0;
        nb = 0;
        nc = 0;
        d = u.x * n[i][0] + u.y * n[i][1] + u.z * n[i][2];
        if ((f32)fabs(d) > 0.025f) {
            p0 = &v[faces[i][0]];
            t = -(-dot3(n[i], &p0->x) + dot3(&c->p0.x, n[i])) / d;
            q.x = u.x * t + c->p0.x;
            q.y = u.y * t + c->p0.y;
            q.z = u.z * t + c->p0.z;
            d0 = dist3(&q.x, &c->p0.x);
            d1 = dist3(&q.x, &c->p1.x);
            e = (f32)fabs(d0 + d1 - len);
            for (j = 0; j < 4; j++) {
                s32 idx[5] = {0, 1, 2, 3, 0};
                e0 = idx[j];
                e1 = idx[j + 1];
                p0 = &v[faces[i][e0]];
                p1 = &v[faces[i][e1]];
                w.x = p0->x - p1->x;
                w.y = p0->y - p1->y;
                w.z = p0->z - p1->z;
                t = (w.x * (q.x - p0->x) + w.y * (q.y - p0->y) + w.z * (q.z - p0->z)) / (w.x * w.x + w.y * w.y + w.z * w.z);
                cp.x = w.x * t + p0->x;
                cp.y = w.y * t + p0->y;
                cp.z = w.z * t + p0->z;
                w.x = cp.x - q.x;
                w.y = cp.y - q.y;
                w.z = cp.z - q.z;
                l = 1.0f / sqrtf(w.x * w.x + w.y * w.y + w.z * w.z);
                w.x *= l;
                w.y *= l;
                w.z *= l;
                x = (f32)fabs(n[adj[i][e0]][0] - w.x);
                y = (f32)fabs(n[adj[i][e0]][1] - w.y);
                z = (f32)fabs(n[adj[i][e0]][2] - w.z);
                if (x <= 0.025f && y <= 0.025f && z <= 0.025f && (d0 <= c->r || d1 <= c->r || e <= 0.025f)) {
                    in &= 1;
                    nc++;
                } else {
                    in &= 0;
                    x = dist3(&v[faces[i][e0]].x, &cp.x);
                    y = dist3(&v[faces[i][e1]].x, &cp.x);
                    z = dist3(&v[faces[i][e0]].x, &v[faces[i][e1]].x);
                    m = d0 < d1 ? d0 : d1;
                    h = sqrtf(c->r * c->r - m * m);
                    if (0.025f + z >= x + y - 0.025f) {
                        if (dist3(&q.x, &cp.x) < h) {
                            na++;
                        }
                    } else {
                        x = dist3(&v[faces[i][e0]].x, &q.x);
                        y = dist3(&v[faces[i][e1]].x, &q.x);
                        if (h >= x || h >= y) {
                            nb++;
                        }
                    }
                }
            }
            if (in || na + nc == 4 || nb + nc == 4) return 1;
        }
        p0 = &v[faces[i][0]];
        t0 = -(-dot3(n[i], &p0->x) + dot3(&c->p0.x, n[i])) / dot3(n[i], n[i]);
        t1 = -(-dot3(n[i], &p0->x) + dot3(&c->p1.x, n[i])) / dot3(n[i], n[i]);
        q0.x = t0 * n[i][0] + c->p0.x;
        q0.y = t0 * n[i][1] + c->p0.y;
        q0.z = t0 * n[i][2] + c->p0.z;
        q1.x = t1 * n[i][0] + c->p1.x;
        q1.y = t1 * n[i][1] + c->p1.y;
        q1.z = t1 * n[i][2] + c->p1.z;
        w0.x = q0.x - c->p0.x;
        w0.y = q0.y - c->p0.y;
        w0.z = q0.z - c->p0.z;
        l = 1.0f / sqrtf(w0.x * w0.x + w0.y * w0.y + w0.z * w0.z);
        w0.x *= l;
        w0.y *= l;
        w0.z *= l;
        w1.x = q1.x - c->p1.x;
        w1.y = q1.y - c->p1.y;
        w1.z = q1.z - c->p1.z;
        l = 1.0f / sqrtf(w1.x * w1.x + w1.y * w1.y + w1.z * w1.z);
        w1.x *= l;
        w1.y *= l;
        w1.z *= l;
        if ((f32)fabs(n[i][0] - w0.x) <= 0.025f && (f32)fabs(n[i][1] - w0.y) <= 0.025f && (f32)fabs(n[i][2] - w0.z) <= 0.025f) {
            in0 &= 1;
            k0++;
        } else {
            in0 &= 0;
            e = dist3(&c->p0.x, &q0.x);
            if (e <= c->r) cnt0++;
            sum0 += e;
        }
        if ((f32)fabs(n[i][0] - w1.x) <= 0.025f && (f32)fabs(n[i][1] - w1.y) <= 0.025f && (f32)fabs(n[i][2] - w1.z) <= 0.025f) {
            in1 &= 1;
            k1++;
        } else {
            in1 &= 0;
            e = dist3(&c->p1.x, &q1.x);
            if (e <= c->r) cnt1++;
            sum1 += e;
        }
    }
    if (in0 || in1 || cnt0 + k0 == 6 || cnt1 + k1 == 6) {
        if (cnt0 == 2 && sum0 * sum0 < 2.0f * c->r * c->r) return 1;
        if (cnt1 == 2 && sum1 * sum1 < 2.0f * c->r * c->r) return 1;
        if (cnt0 < 2 || cnt1 < 2) return 1;
    }
    }
    return 0;
}
