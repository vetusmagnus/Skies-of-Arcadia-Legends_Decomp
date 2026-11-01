/* Sega Ninja (GameCube) library: matrix stack, motion/keyframe playback, model chunk walkers and
 * GX drawing. The file name is ours; Ninja's real file boundaries aren't known (docs/ninja.md), so
 * this holds every function matched so far from the 0x80286EE8-0x802AC75C region in address order. */

#include "ninja_lib.h"
#include <ctype.h>

void fn_80286FEC(s32 n, f32 x, f32 y) {
    if (n == 0) return;
    n--;
    lbl_80344DE0.light[n].f44 = x;
    lbl_80344DE0.light[n].f48 = y;
    lbl_80344DE0.light[n].f4c = 1.0f;
    lbl_80344DE0.light[n].f50 = 0.1f;
    lbl_80344DE0.light[n].s54 = 1;
    lbl_80344DE0.light[n].f58 = 0.0f;
    lbl_80344DE0.light[n].s5c = 0;
}


void fn_8028703C(s32 n, f32 x, f32 y, f32 z) {
    if (n == 0) return;
    n--;
    lbl_80344DE0.light[n].mask = lbl_803005A0[n];
    lbl_80344DE0.light[n].type = 1;
    lbl_80344DE0.light[n].kind = 3;
    lbl_80344DE0.light[n].pos.x = x;
    lbl_80344DE0.light[n].pos.y = y;
    lbl_80344DE0.light[n].pos.z = z;
}

void fn_8028708C(s32 n, f32 x, f32 y, f32 z) {
    if (n == 0) return;
    n--;
    lbl_80344DE0.light[n].mask = lbl_803005A0[n];
    lbl_80344DE0.light[n].type = 1;
    lbl_80344DE0.light[n].kind = 0;
    lbl_80344DE0.light[n].pos.x = -x * 1048576.0f;
    lbl_80344DE0.light[n].pos.y = -y * 1048576.0f;
    lbl_80344DE0.light[n].pos.z = -z * 1048576.0f;
    lbl_80344DE0.light[n].f44 = 0.0f;
    lbl_80344DE0.light[n].f48 = 1048576.0f;
    lbl_80344DE0.light[n].f4c = 1.0f;
    lbl_80344DE0.light[n].f50 = 0.999999f;
    lbl_80344DE0.light[n].s54 = 3;
    lbl_80344DE0.light[n].f58 = 0.0f;
    lbl_80344DE0.light[n].s5c = 0;
}

void fn_80287274(s32 n, s32 t) {
    if (n != 0) {
        n--;
        lbl_80344DE0.light[n].type = t;
    } else {
        lbl_80344DE0.light[0].type = t;
        lbl_80344DE0.light[1].type = t;
        lbl_80344DE0.light[2].type = t;
        lbl_80344DE0.light[3].type = t;
        lbl_80344DE0.light[4].type = t;
        lbl_80344DE0.light[5].type = t;
        lbl_80344DE0.light[6].type = t;
        lbl_80344DE0.light[7].type = t;
    }
}

void fn_802872C4(s32 x) {
    lbl_80344DE0.f04 = x;
}

void fn_802872D4(NjObj* obj) {
    lbl_80344DE0.dirty = 1;
    if (lbl_80347FD0 && !(obj->evalflags & 0x10000)) {
        fn_802AB23C(obj);
    }
    if (obj->evalflags & 0x4000) {
        if (obj->evalflags & 0x8000) {
            switch (lbl_80346A50) {
            case 1:
            case 2:
                fn_80288DE4(obj, fn_802A7680);
                break;
            }
        } else {
            fn_80288DE4(obj, fn_802A7680);
        }
    } else {
        if (obj->evalflags & 0x8000) {
            switch (lbl_80346A50) {
            case 1:
            case 2:
                fn_80288DE4(obj, fn_802873BC);
                break;
            }
        } else {
            fn_80288DE4(obj, fn_802873BC);
        }
    }
}

void fn_80287B38(NjObj* obj) {
    if (lbl_80347FD0 && !(obj->evalflags & 0x10000)) {
        fn_802AB23C(obj);
    }
    if (obj->evalflags & 0x4000) {
        if (obj->evalflags & 0x8000) {
            switch (lbl_80346A50) {
            case 1:
            case 2:
                fn_80288DE4(obj, fn_802A6184);
                break;
            }
        } else {
            fn_80288DE4(obj, fn_802A6184);
        }
    } else {
        if (obj->evalflags & 0x8000) {
            switch (lbl_80346A50) {
            case 1:
            case 2:
                fn_80288DE4(obj, fn_80287C14);
                break;
            }
        } else {
            fn_80288DE4(obj, fn_80287C14);
        }
    }
}

s32 fn_80287C14(NjModel* m) {
    u32* v;
    s16* p;
    void* base;
    if ((_nj_control_3d_flag_ & 0x100) && m->r > 0.0f) {
        if (fn_80288C68(m)) {
            return -1;
        }
    }
    base = lbl_80347EFC;
    v = m->vlist;
    if (v) {
        lbl_80347E18 = fn_80287D98(v, base);
    }
    p = m->plist;
    if (p) {
        fn_8029C8A0();
        switch (lbl_80346A50) {
    case 1:
        lbl_80347E20 = 0;
        fn_80287F00(p, lbl_80347E18, base);
        break;
    case 2:
        lbl_80347E20 = 1;
        fn_80287F00(p, lbl_80347E18, base);
        break;
    case 3:
        lbl_80347E20 = 2;
        fn_80287F00(p, lbl_80347E18, base);
        break;
    case 4:
        lbl_80347E20 = 3;
        fn_80287F00(p, lbl_80347E18, base);
        lbl_80347E20 = 4;
        fn_80287F00(p, lbl_80347E18, base);
        break;
    case 5:
        lbl_80347E20 = 3;
        fn_80287F00(p, lbl_80347E18, base);
        break;
    case 6:
        lbl_80347E20 = 4;
        fn_80287F00(p, lbl_80347E18, base);
        break;
        }
    }
}

void fn_80288C28(s32 n, f32 a, f32 b) {
    lbl_80347EA4 = n;
    if (a > -1.0f) a = -1.0f;
    if (b > -1.0f) b = -1.0f;
    lbl_80345828[1] = -a;
    lbl_80345828[0] = -b;
}

s32 fn_80288C68(NjModel* m) {
    NJS_POINT3 p;
    f32 zr;
    f32 r;
    njCalcPoint(0, &m->center, &p);
    p.z = -p.z;
    r = m->r;
    if (lbl_80347EA4) {
        if (p.z + r <= lbl_80345828[1]) return 1;
        if (p.z - r > lbl_80345828[0]) return 1;
    } else {
        if (p.z + r <= lbl_80345850[1]) return 1;
        if (p.z - r > lbl_80345850[0]) return 1;
    }
    zr = p.z + r;
    if (lbl_80345878[0] * (p.x - r) > lbl_80345850[2] * zr) return 1;
    if (lbl_80345878[0] * (p.x + r) < lbl_80345850[3] * zr) return 1;
    if (-lbl_80345878[1] * (-p.y - r) > lbl_80345850[4] * zr) return 1;
    return -lbl_80345878[1] * (-p.y + r) < lbl_80345850[5] * zr;
}

void fn_80288DE4(NjObj* obj, NjModelCb cb) {
    do {
        u32 flags = obj->evalflags;
        s32 r = 0;
        if (flags & 0x800) {
            fn_80291C44(lbl_80345120);
        }
        if ((flags & 7) == 7) {
            if (!(flags & 8)) {
                r = cb(obj->model);
            }
            if (!(flags & 0x10)) {
                if (!(flags & 0x100) || r == 0) {
                    fn_80288DE4(obj->child, cb);
                }
            }
        } else {
            njPushMatrixEx();
            if (!(flags & 1)) {
                njTranslateEx(&obj->pos);
            }
            if (!(flags & 2)) {
                if (flags & 0x1000) {
                    fn_802974B4(lbl_80345120);
                } else if (flags & 0x400) {
                    fn_80292A00(&obj->rot.quat, obj->radius);
                } else {
                    njRotateEx(obj->rot.ang, flags & 0x20);
                }
            }
            if (!(flags & 4)) {
                njScaleEx(&obj->scl);
            }
            if (!(flags & 8)) {
                r = cb(obj->model);
            }
            if (!(flags & 0x10)) {
                if (!(flags & 0x100) || r == 0) {
                    fn_80288DE4(obj->child, cb);
                }
            }
            njPopMatrixEx();
        }
        obj = obj->sibling;
    } while (obj != 0);
}

void fn_80288F4C(f32 x) {
    lbl_80347ED8 = x;
}

void njSetConstantMaterial(NJS_ARGB* mat) {
    _nj_constant_material_.a = mat->a;
    _nj_constant_material_.r = mat->r;
    _nj_constant_material_.g = mat->g;
    _nj_constant_material_.b = mat->b;
}

void njSetConstantAttr(u32 and_attr, u32 or_attr) {
    _nj_constant_attr_and_ = and_attr;
    _nj_constant_attr_or_ = or_attr;
}

void njControl3D(u32 flag) {
    _nj_control_3d_flag_ = flag;
}

void fn_80288F90(void* p) {
    lbl_80347EFC = p;
    _nj_control_3d_flag_ = 0;
    _nj_constant_attr_and_ = -1;
    _nj_constant_attr_or_ = 0;
    _nj_constant_material_.a = 255.0f;
    _nj_constant_material_.r = 0.0f;
    _nj_constant_material_.g = 0.0f;
    _nj_constant_material_.b = 0.0f;
}

void fn_80288FC8(NjObj* obj) {
    if (lbl_80347FD0 && !(obj->evalflags & 0x10000)) {
        fn_802AB23C(obj);
    }
    if (obj->evalflags & 0x4000) {
        if (obj->evalflags & 0x8000) {
            switch (lbl_80346A50) {
            case 1:
            case 2:
                fn_80288DE4(obj, fn_802A1160);
                break;
            }
        } else {
            fn_80288DE4(obj, fn_802A1160);
        }
    } else {
        if (obj->evalflags & 0x8000) {
            switch (lbl_80346A50) {
            case 1:
            case 2:
                fn_80288DE4(obj, fn_802890A4);
                break;
            }
        } else {
            fn_80288DE4(obj, fn_802890A4);
        }
    }
}

s32 fn_802890A4(NjModel* m) {
    s16* p;
    void* base;
    if ((_nj_control_3d_flag_ & 0x100) && m->r > 0.0f) {
        if (fn_80288C68(m)) {
            return -1;
        }
    }
    base = lbl_80347EFC;
    if (m->vlist) {
        lbl_80347E24 = fn_80289228(m->vlist, base);
    }
    p = m->plist;
    if (p) {
        fn_8029C8A0();
        switch (lbl_80346A50) {
    case 1:
        lbl_80347E20 = 0;
        fn_80289390(p, lbl_80347E24, base);
        break;
    case 2:
        lbl_80347E20 = 1;
        fn_80289390(p, lbl_80347E24, base);
        break;
    case 3:
        lbl_80347E20 = 2;
        fn_80289390(p, lbl_80347E24, base);
        break;
    case 4:
        lbl_80347E20 = 3;
        fn_80289390(p, lbl_80347E24, base);
        lbl_80347E20 = 4;
        fn_80289390(p, lbl_80347E24, base);
        break;
    case 5:
        lbl_80347E20 = 3;
        fn_80289390(p, lbl_80347E24, base);
        break;
    case 6:
        lbl_80347E20 = 4;
        fn_80289390(p, lbl_80347E24, base);
        break;
        }
    }
    return 0;
}

void fn_8028A054(void) {
}

#pragma optimization_level 2
void fn_8028A058(u32 argb, s32 p, f32 w) {
    fn_8029B248(5, p);
    lbl_80347E28.a = argb >> 24;
    lbl_80347E28.r = argb >> 16;
    lbl_80347E28.g = argb >> 8;
    lbl_80347E28.b = argb;
    GXSetChanMatColor(GX_COLOR0A0, lbl_80347E28);
    GXSetLineWidth((w + 0.16f) * 12.0f, GX_TO_ZERO);
}
#pragma optimization_level reset

void fn_8028A268(void) {
}

void fn_8028A26C(s32 p) {
    fn_8029CB74();
    fn_8029B248(4, p);
}

void fn_8028A2A4(void) {
}

void fn_8028A3E0(s32 p) {
    fn_8029CB1C();
    fn_8029B248(4, p);
}

void fn_8028A6B8(void) {
}

void fn_8028A6BC(s32 p) {
    fn_8029CB74();
    fn_8029B248(0, p);
}

void fn_8028A6F4(void) {
}

void fn_8028A888(s32 p) {
    fn_8029CB1C();
    fn_8029B248(0, p);
}

void fn_8028AA60(NjObj* obj) {
    lbl_80345350.dirty = 1;
    if (lbl_80347FD0 && !(obj->evalflags & 0x10000)) {
        fn_802AB23C(obj);
    }
    if (obj->evalflags & 0x4000) {
        if (obj->evalflags & 0x8000) {
            switch (lbl_80346A50) {
            case 1:
            case 2:
                fn_80288DE4(obj, fn_802A7FA0);
                break;
            }
        } else {
            fn_80288DE4(obj, fn_802A7FA0);
        }
    } else {
        if (obj->evalflags & 0x8000) {
            switch (lbl_80346A50) {
            case 1:
            case 2:
                fn_80288DE4(obj, fn_8028AB48);
                break;
            }
        } else {
            fn_80288DE4(obj, fn_8028AB48);
        }
    }
}

void fn_8028B59C(s32 n, f32 x, f32 y) {
    if (n == 0) return;
    n--;
    lbl_80345350.light[n].f44 = x;
    lbl_80345350.light[n].f48 = y;
    lbl_80345350.light[n].f4c = 1.0f;
    lbl_80345350.light[n].f50 = 0.1f;
    lbl_80345350.light[n].s54 = 1;
    lbl_80345350.light[n].f58 = 0.0f;
    lbl_80345350.light[n].s5c = 0;
}

void fn_8028B5EC(s32 n, f32 x, f32 y, f32 z) {
    if (n == 0) return;
    n--;
    lbl_80345350.light[n].mask = lbl_80300710[n];
    lbl_80345350.light[n].type = 1;
    lbl_80345350.light[n].kind = 3;
    lbl_80345350.light[n].pos.x = x;
    lbl_80345350.light[n].pos.y = y;
    lbl_80345350.light[n].pos.z = z;
}

void fn_8028B63C(s32 n, f32 x, f32 y, f32 z) {
    if (n == 0) return;
    n--;
    lbl_80345350.light[n].mask = lbl_80300710[n];
    lbl_80345350.light[n].type = 1;
    lbl_80345350.light[n].kind = 0;
    lbl_80345350.light[n].pos.x = 1048576.0f * -x;
    lbl_80345350.light[n].pos.y = 1048576.0f * -y;
    lbl_80345350.light[n].pos.z = 1048576.0f * -z;
    lbl_80345350.light[n].f44 = 0.0f;
    lbl_80345350.light[n].f48 = 1048576.0f;
    lbl_80345350.light[n].f4c = 1.0f;
    lbl_80345350.light[n].f50 = 0.99999f;
    lbl_80345350.light[n].s54 = 3;
    lbl_80345350.light[n].f58 = 0.0f;
    lbl_80345350.light[n].s5c = 0;
}

void fn_8028B820(s32 n, s32 v) {
    if (n) {
        n--;
        lbl_80345350.light[n].type = v;
    } else {
        lbl_80345350.light[0].type = v;
        lbl_80345350.light[1].type = v;
        lbl_80345350.light[2].type = v;
        lbl_80345350.light[3].type = v;
        lbl_80345350.light[4].type = v;
        lbl_80345350.light[5].type = v;
        lbl_80345350.light[6].type = v;
        lbl_80345350.light[7].type = v;
    }
}

void fn_8028B870(s32 x) {
    lbl_80345350.f04 = x;
}

void fn_8028BA48(Angle a) {
    f32 m[12];
    f32 t[12];
    fn_80291C44(m);
    PSMTXRotRad(t, 'Z', -a * ANG_RAD);
    PSMTXConcat(t, m, m);
    njSetMatrix(0, m);
}

void fn_8028BAC8(void) {
    njUnitMatrix(0);
}

void fn_8028BB90(NjState* s) {
    s->v0 = 0.0f;
    s->v4 = 0.0f;
    s->v8 = 0.0f;
    s->vc = 0.0f;
    s->v10 = 0.0f;
    s->f14 = -1.0f;
    s->s18 = 0;
    s->s1a = 0x2aaa;
    s->s1c = 1;
}

s32 fn_8028BBCC(NJS_POINT3* amin, NJS_POINT3* amax, NJS_POINT3* bmin, NJS_POINT3* bmax) {
    if (amax->x < bmin->x) return 0;
    if (amin->x > bmax->x) return 0;
    if (amax->y < bmin->y) return 0;
    if (amin->y > bmax->y) return 0;
    if (amax->z < bmin->z) return 0;
    if (amin->z > bmax->z) return 0;
    return 1;
}

s32 fn_8028F884(f32* a, f32* s) {
    f32 dx, dy, dz, ex, ey, ez, t, d, r;
    f32 x, y, z;
    dx = a[0] - s[0];
    dy = a[1] - s[1];
    dz = a[2] - s[2];
    ex = s[3] - s[0];
    ey = s[4] - s[1];
    ez = s[5] - s[2];
    t = (dx * ex + dy * ey + dz * ez) / (ex * ex + ey * ey + ez * ez);
    if (t < 0.0f) {
        d = dx * dx + dy * dy + dz * dz;
    } else if (t > 1.0f) {
        f32 u, v, w;
        u = ex - dx;
        v = ey - dy;
        w = ez - dz;
        d = u * u + v * v + w * w;
    } else {
        x = t * ex - dx;
        y = t * ey - dy;
        z = t * ez - dz;
        d = x * x + y * y + z * z;
    }
    r = a[3] + s[6];
    if (d <= r * r) return 1;
    return 0;
}

s32 fn_8028F95C(f32* a, f32* b) {
    f32 dx, dy, dz, r;
    dx = b[0] - a[0];
    dy = b[1] - a[1];
    dz = b[2] - a[2];
    r = a[3] + b[3];
    if (dx * dx + dy * dy + dz * dz <= r * r) return 1;
    return 0;
}

#pragma optimization_level 1
#pragma opt_common_subs on
f32 fn_8028FD98(f32* l, f32* pl, f32* out) {
    f32 p[3];
    f32 t;
    if (fn_802907D0(l, pl)) {
        f32 z, y, x;
        x = l[0]; y = l[1]; z = l[2];
        p[0] = x; p[1] = y; p[2] = z;
        return fn_802900C0(p, pl, out);
    }
    if (out) {
        t = -(-(pl[3] * pl[0] + pl[4] * pl[1] + pl[5] * pl[2]) + (pl[3] * l[0] + pl[4] * l[1] + pl[5] * l[2])) / (pl[3] * l[3] + pl[4] * l[4] + pl[5] * l[5]);
        out[0] = l[3] * t + l[0];
        out[1] = l[4] * t + l[1];
        out[2] = l[5] * t + l[2];
    }
    return 0.0f;
}
#pragma opt_common_subs reset
#pragma optimization_level reset

f32 fn_80290008(f32* a, f32* b) {
    f32 x, y, z, d;
    f32 dx = a[0] - b[0];
    f32 dy = a[1] - b[1];
    f32 dz = a[2] - b[2];
    x = dx * dx;
    y = dy * dy;
    z = dz * dz;
    d = x + y + z;
    if (d < 0.025f) return 0.0f;
    return sqrtf(d);
}

#pragma optimization_level 1
#pragma opt_common_subs on
f32 fn_802900C0(f32* p, f32* pl, f32* out) {
    f32 n2, d, t;
    d = -(pl[3] * pl[0] + pl[4] * pl[1] + pl[5] * pl[2]) + (pl[3] * p[0] + pl[4] * p[1] + pl[5] * p[2]);
    n2 = pl[3] * pl[3] + pl[4] * pl[4] + pl[5] * pl[5];
    if (out) {
        t = -d / n2;
        out[0] = pl[3] * t + p[0];
        out[1] = pl[4] * t + p[1];
        out[2] = pl[5] * t + p[2];
    }
    return (f32)fabs(d) * fn_80291978(n2);
}

#pragma opt_common_subs reset
#pragma optimization_level reset

void fn_80290428(NJS_POINT3* p, NJS_POINT3* lo, NJS_POINT3* hi) {
    s32 i;
    lo->x = p[0].x;
    lo->y = p[0].y;
    lo->z = p[0].z;
    hi->x = p[0].x;
    hi->y = p[0].y;
    hi->z = p[0].z;
    for (i = 1; i < 8; i++) {
        if (p[i].x < lo->x) lo->x = p[i].x;
        if (p[i].y < lo->y) lo->y = p[i].y;
        if (p[i].z < lo->z) lo->z = p[i].z;
        if (p[i].x > hi->x) hi->x = p[i].x;
        if (p[i].y > hi->y) hi->y = p[i].y;
        if (p[i].z > hi->z) hi->z = p[i].z;
    }
}

#pragma optimization_level 1
#pragma opt_common_subs on
void fn_802904E8(NjCapsule* c, NJS_POINT3* lo, NJS_POINT3* hi) {
    f32 a0, a1, a2, b0, b1, b2, c0, c1, c2, d0, d1, d2;
    a0 = c->p0.x - c->r;
    a1 = c->p0.y - c->r;
    a2 = c->p0.z - c->r;
    b0 = c->p1.x - c->r;
    b1 = c->p1.y - c->r;
    b2 = c->p1.z - c->r;
    c0 = c->p0.x + c->r;
    c1 = c->p0.y + c->r;
    c2 = c->p0.z + c->r;
    d0 = c->p1.x + c->r;
    d1 = c->p1.y + c->r;
    d2 = c->p1.z + c->r;
    lo->x = a0 < b0 ? a0 : b0;
    lo->y = a1 < b1 ? a1 : b1;
    lo->z = a2 < b2 ? a2 : b2;
    hi->x = c0 > d0 ? c0 : d0;
    hi->y = c1 > d1 ? c1 : d1;
    hi->z = c2 > d2 ? c2 : d2;
}

#pragma opt_common_subs reset
#pragma optimization_level reset

#pragma optimization_level 1
#pragma opt_common_subs on
void fn_802905C8(NJS_POINT3* p, NJS_POINT3* n) {
    n->x = (p[1].y - p[0].y) * (p[2].z - p[0].z) - (p[1].z - p[0].z) * (p[2].y - p[0].y);
    n->y = (p[1].z - p[0].z) * (p[2].x - p[0].x) - (p[1].x - p[0].x) * (p[2].z - p[0].z);
    n->z = (p[1].x - p[0].x) * (p[2].y - p[0].y) - (p[1].y - p[0].y) * (p[2].x - p[0].x);
}

#pragma opt_common_subs reset
#pragma optimization_level reset

#pragma optimization_level 1
#pragma opt_common_subs on
void fn_80290668(NJS_POINT3* p0, NJS_POINT3* p1, NJS_POINT3* p2, NJS_POINT3* n) {
    n->x = (p1->y - p0->y) * (p2->z - p0->z) - (p1->z - p0->z) * (p2->y - p0->y);
    n->y = (p1->z - p0->z) * (p2->x - p0->x) - (p1->x - p0->x) * (p2->z - p0->z);
    n->z = (p1->x - p0->x) * (p2->y - p0->y) - (p1->y - p0->y) * (p2->x - p0->x);
}

#pragma opt_common_subs reset
#pragma optimization_level reset

void fn_80290708(f32* v, f32* lo, f32* hi) {
    lo[0] = v[0] - v[3];
    lo[1] = v[1] - v[3];
    lo[2] = v[2] - v[3];
    hi[0] = v[0] + v[3];
    hi[1] = v[1] + v[3];
    hi[2] = v[2] + v[3];
}

s32 fn_8029076C(f32* a, f32* b) {
    f32 la = a[3] * a[3] + a[4] * a[4] + a[5] * a[5];
    f32 d = a[3] * b[3] + a[4] * b[4] + a[5] * b[5];
    f32 lb = b[3] * b[3] + b[4] * b[4] + b[5] * b[5];
    return (f32)fabs(d * d / (la * lb)) > 0.975f;
}

static inline f32 vlen(f32* v) {
    f32 z, x, y;
    x = v[0];
    y = v[1];
    z = v[2];
    x = x * x;
    y = y * y;
    z = z * z;
    return sqrtf(x + y + z);
}
static inline f32 vlen2(f32* v) {
    f32 x, y, z;
    x = v[0] * v[0];
    y = v[1] * v[1];
    z = v[2] * v[2];
    return sqrtf(x + y + z);
}
s32 fn_802907D0(f32* a, f32* b) {
    f32 la, lb;
    la = vlen(&a[3]);
    lb = vlen2(&b[3]);
    if ((f32)fabs((a[3] * b[3] + a[4] * b[4] + a[5] * b[5]) / (la * lb)) < 0.025f) return 1;
    return 0;
}

void fn_80290E98(u32 x) {
    lbl_80347E48 = (x << 8) | (x >> 24);
}

#pragma optimization_level 1
void fn_80290EA8(u16 x) {
    lbl_80347E44 = x;
}
#pragma optimization_level reset

#pragma optimization_level 1
void fn_802913D4(u32 x) {
    x = __rlwinm(x, 8, 0, 31);
    lbl_80347E50 = 1;
    lbl_80347E58 = x;
}
#pragma optimization_level reset

void fn_802913E8(s32 n, u32 x) {
    fn_80298FE4(n);
    lbl_80347E58 = __rlwinm(x, 8, 0, 31);
    lbl_80347E50 = 1;
}

void fn_80291424(void) {
}

void fn_80291428(s32 p) {
    fn_8029CB74();
    lbl_80347E5C = p;
}

#pragma optimization_level 1
f32 njCos(Angle a) {
    return cos(a * ANG_RAD);
}
#pragma optimization_level reset

#pragma optimization_level 1
#pragma opt_common_subs on
void fn_80291700(NJS_POINT3* p, NJS_POINT3* out, f32 t) {
    f32 u = 1.0f - t;
    f32 b0 = u * u * u;
    f32 b1 = u * 3.0f * u * t;
    f32 b2 = u * 3.0f * t * t;
    f32 b3 = t * t * t;
    out->x = b0 * p[0].x + b1 * p[1].x + b2 * p[2].x + b3 * p[3].x;
    out->y = b0 * p[0].y + b1 * p[1].y + b2 * p[2].y + b3 * p[3].y;
    out->z = b0 * p[0].z + b1 * p[1].z + b2 * p[2].z + b3 * p[3].z;
}
#pragma opt_common_subs reset
#pragma optimization_level reset

f32 fn_802917A0(f32 x) {
    f64 ip;
    return modf(x, &ip);
}

f32 fn_80291888(f32 x) {
    f32 a;
    f32 t;
    f32 r;
    if (x < 0.0f) {
        a = fabs(x);
        t = floor(a);
        r = -t;
    } else {
        a = fabs(x);
        t = floor(a);
        r = t;
    }
    return r;
}

f32 fn_802918DC(f32 x) {
    f32 a;
    f32 t;
    f32 r;
    if (x < 0.0f) {
        a = fabs(x);
        t = ceil(a);
        r = -t;
    } else {
        a = fabs(x);
        t = ceil(a);
        r = t;
    }
    return r;
}

#pragma optimization_level 1
f32 njSin(Angle a) {
    return sin(a * ANG_RAD);
}
#pragma optimization_level reset

f32 fn_80291978(f64 x) {
    f32 r = (x < 0.0) ? -sqrtf(-x) : sqrtf(x);
    return 1.0f / r;
}

f32 fn_80291A5C(f64 x) {
    f32 r;
    if (x < 0.0) {
        r = -sqrtf(-x);
    } else {
        r = sqrtf(x);
    }
    return r;
}

#pragma optimization_level 1
f32 njTan(Angle a) {
    return tan(a * ANG_RAD);
}
#pragma optimization_level reset

void njCalcPoint(NJS_MATRIX m, NJS_POINT3* p, NJS_POINT3* out) {
    PSMTXMultVec(m ? m : lbl_80347EB4, p, out);
}

void njCalcPoints(NJS_MATRIX m, NJS_POINT3* src, NJS_POINT3* dst, s32 n) {
    PSMTXMultVecArray(m ? m : lbl_80347EB4, src, dst, n);
}

void njCalcVector(NJS_MATRIX m, NJS_POINT3* src, NJS_POINT3* dst) {
    calc_vector(m, src, dst);
}

void njCalcVectors(NJS_MATRIX m, NJS_POINT3* src, NJS_POINT3* dst, s32 n) {
    PSMTXMultVecArraySR(m ? m : lbl_80347EB4, src, dst, n);
}

void fn_80291C44(NJS_MATRIX m) {
    fn_8029748C(m);
}

void njGetTranslation(NJS_MATRIX m, NJS_POINT3* out) {
    f32* p = m ? m : lbl_80347EB4;
    out->x = p[3];
    out->y = p[7];
    out->z = p[11];
}

#pragma optimization_level 1
void njInitMatrix(NJS_MATRIX* base, s32 limit) {
    f32* aligned = (f32*)(((u32)base + 31) & ~31);
    lbl_80347EB4 = aligned;
    lbl_80347EB0 = aligned;
    lbl_80347EAC = limit;
    lbl_80347EA8 = 1;
    PSMTXCopy(&lbl_803007C8[0][0], aligned);
}
#pragma optimization_level reset

f32 njInnerProduct(NJS_POINT3* a, NJS_POINT3* b) {
    return PSVECDotProduct(a, b);
}

void fn_80291CF8(f32* a, f32* b, f32* out, f32 t) {
    C_QUATSlerp(a, b, out, t);
}

s32 njInvertMatrix(NJS_MATRIX m) {
    f32* p = CURM(m);
    if (!PSMTXInverse(p, p)) {
        p[0] = 3.4e38f;
        p[4] = 3.4e38f;
        p[8] = 3.4e38f;
        p[1] = 3.4e38f;
        p[5] = 3.4e38f;
        p[9] = 3.4e38f;
        p[2] = 3.4e38f;
        p[6] = 3.4e38f;
        p[10] = 3.4e38f;
        p[3] = 3.4e38f;
        p[7] = 3.4e38f;
        p[11] = 3.4e38f;
        return 0;
    }
    return 1;
}

void njMultiMatrix(NJS_MATRIX m, NJS_MATRIX n) {
    if (!m) {
        m = lbl_80347EB4;
        lbl_80347F70 = 5;
    }
    PSMTXConcat(m, n, m);
}

f32 njOuterProduct(NJS_POINT3* a, NJS_POINT3* b, NJS_POINT3* out) {
    PSVECCrossProduct(a, b, out);
    return PSVECMag(out);
}

s32 fn_80291E18(s32 n) {
    u32 d = lbl_80347EA8 - n;
    if (d < 1) return 0;
    lbl_80347EA8 = d;
    lbl_80347EB4 -= n * 12;
    lbl_80347F70 = 5;
    return 1;
}

void njProjectScreen(NJS_MATRIX m, NJS_POINT3* p, NJS_POINT3* out) {
    f32* a = CURM(m);
    f32 x = p->x;
    f32 y = p->y;
    f32 z = p->z;
    f32 w = a[8] * x + a[9] * y + a[10] * z + a[11];
    f32 xx = a[0] * x + a[1] * y + a[2] * z + a[3];
    f32 yy = a[4] * x + a[5] * y + a[6] * z + a[7];
    f32 k = -1.0f / w;
    out->x = lbl_80345878[2] + k * (lbl_80345878[0] * xx);
    out->y = lbl_80345878[3] + k * (lbl_80345878[1] * yy);
}

s32 njPushMatrix(NJS_MATRIX m) {
    if (lbl_80347EA8 >= lbl_80347EAC) return 0;
    PSMTXCopy(m ? m : lbl_80347EB4, lbl_80347EB4 + 12);
    lbl_80347EB4 += 12;
    lbl_80347F70 = 5;
    lbl_80347EA8++;
    return 1;
}

void njRotate(NJS_MATRIX m, NJS_POINT3* axis, Angle a) {
    f32 t[12];
    f32* p = CURM(m);
    PSMTXRotAxisRad(t, axis, a * ANG_RAD);
    PSMTXConcat(p, t, p);
}

void njRotateX(NJS_MATRIX m, Angle a) {
    f32 t[12];
    f32* p = CURM(m);
    PSMTXRotRad(t, 'X', a * ANG_RAD);
    PSMTXConcat(p, t, p);
}

void njRotateXYZ(NJS_MATRIX m, Angle x, Angle y, Angle z) {
    f32 t[12];
    f32* p = CURM(m);
    if (z) {
        PSMTXRotRad(t, 'Z', z * ANG_RAD);
        PSMTXConcat(p, t, p);
    }
    if (y) {
        PSMTXRotRad(t, 'Y', y * ANG_RAD);
        PSMTXConcat(p, t, p);
    }
    if (x) {
        PSMTXRotRad(t, 'X', x * ANG_RAD);
        PSMTXConcat(p, t, p);
    }
}

void njRotateY(NJS_MATRIX m, Angle a) {
    f32 t[12];
    f32* p = CURM(m);
    PSMTXRotRad(t, 'Y', a * ANG_RAD);
    PSMTXConcat(p, t, p);
}

void njRotateZ(NJS_MATRIX m, Angle a) {
    f32 t[12];
    f32* p = CURM(m);
    PSMTXRotRad(t, 'Z', a * ANG_RAD);
    PSMTXConcat(p, t, p);
}

void njRotateZXY(NJS_MATRIX m, Angle x, Angle y, Angle z) {
    f32 t[12];
    f32* p = CURM(m);
    if (y) {
        PSMTXRotRad(t, 'Y', y * ANG_RAD);
        PSMTXConcat(p, t, p);
    }
    if (x) {
        PSMTXRotRad(t, 'X', x * ANG_RAD);
        PSMTXConcat(p, t, p);
    }
    if (z) {
        PSMTXRotRad(t, 'Z', z * ANG_RAD);
        PSMTXConcat(p, t, p);
    }
}

void njScale(NJS_MATRIX m, f32 x, f32 y, f32 z) {
    f32 t[12];
    f32* p = CURM(m);
    PSMTXScale(t, x, y, z);
    PSMTXConcat(p, t, p);
}

f32 njScalor(NJS_POINT3* v) {
    return PSVECMag(v);
}

f32 njScalor2(NJS_POINT3* v) {
    return PSVECSquareMag(v);
}

void njSetMatrix(NJS_MATRIX md, NJS_MATRIX ms) {
    f32* p = CURM(md);
    PSMTXCopy(ms, p);
}

void njSubVector(NJS_POINT3* a, NJS_POINT3* b) {
    PSVECSubtract(a, b, a);
}

void njTranslate(NJS_MATRIX m, f32 x, f32 y, f32 z) {
    f32 t[12];
    f32* p = CURM(m);
    PSMTXTrans(t, x, y, z);
    PSMTXConcat(p, t, p);
}

void njTranslateV(NJS_MATRIX m, NJS_POINT3* v) {
    f32 t[12];
    f32* p = CURM(m);
    PSMTXTrans(t, v->x, v->y, v->z);
    PSMTXConcat(p, t, p);
}

void njUnitMatrix(NJS_MATRIX m) {
    f32* p = CURM(m);
    PSMTXIdentity(p);
}

void njUnitRotPortion(NJS_MATRIX m) {
    f32* p = CURM(m);
    p[10] = 1.0f;
    p[6] = 0.0f;
    p[2] = 0.0f;
    p[9] = 0.0f;
    p[5] = 1.0f;
    p[1] = 0.0f;
    p[8] = 0.0f;
    p[4] = 0.0f;
    p[0] = 1.0f;
}

void njUnitTransPortion(NJS_MATRIX m) {
    f32* p = CURM(m);
    p[11] = 0.0f;
    p[7] = 0.0f;
    p[3] = 0.0f;
}

f32 njUnitVector(NJS_POINT3* v) {
    f32 len = PSVECMag(v);
    if (len != 0.0f) PSVECNormalize(v, v);
    return len;
}

void fn_802926A4(Angle* ang, f32* q) {
    f32 cx, cy, cz, sx, sy, sz;
    fn_80297504(ang[0] >> 1, &sx, &cx);
    fn_80297504(ang[1] >> 1, &sy, &cy);
    fn_80297504(ang[2] >> 1, &sz, &cz);
    q[3] = cz * (cx * cy) + sz * (sx * sy);
    q[0] = sz * (-cx * sy) + cz * (sx * cy);
    q[1] = sx * (cy * sz) + cx * (sy * cz);
    q[2] = sy * (-cz * sx) + cy * (sz * cx);
}

void fn_802927CC(Angle* ang, f32* q) {
    f32 cx, cy, cz, sx, sy, sz;
    fn_80297504(ang[0] >> 1, &sx, &cx);
    fn_80297504(ang[1] >> 1, &sy, &cy);
    fn_80297504(ang[2] >> 1, &sz, &cz);
    q[3] = cz * (cx * cy) + sz * (sx * sy);
    q[0] = sz * (cx * sy) + cz * (sx * cy);
    q[1] = sx * (-cy * sz) + cx * (sy * cz);
    q[2] = sy * (-cz * sx) + cy * (sz * cx);
}

void fn_802928F4(NJS_POINT3* src, NJS_POINT3* dst) {
    PSMTXMultVecSR(lbl_80347EB4, src, dst);
}

s32 njPopMatrixEx(void) {
    s32 d = lbl_80347EA8 - 1;
    if (d < 1) return 0;
    lbl_80347EA8 = d;
    lbl_80347EB4 -= 12;
    lbl_80347F70 = 5;
    return 1;
}

s32 njPushMatrixEx(void) {
    if (lbl_80347EA8 >= lbl_80347EAC) return 0;
    PSMTXCopy(lbl_80347EB4, lbl_80347EB4 + 12);
    lbl_80347F70 = 5;
    lbl_80347EB4 += 12;
    lbl_80347EA8++;
    return 1;
}

void fn_802929C0(f32* q) {
    f32 t[12];
    PSMTXQuat(t, q);
    PSMTXConcat(lbl_80347EB4, t, lbl_80347EB4);
    lbl_80347F70 = 5;
}

#pragma optimization_level 1
void fn_80292A00(NJS_POINT3* axis, f32 w) {
    f32 q[4];
    f32 t[12];
    f32* m;
    q[0] = axis->x;
    q[1] = axis->y;
    q[2] = axis->z;
    q[3] = w;
    PSMTXQuat(t, q);
    m = lbl_80347EB4;
    PSMTXConcat(m, t, m);
    lbl_80347F70 = 5;
}
#pragma optimization_level reset

void njRotateEx(Angle* ang, s32 lv) {
    f32 t[12];
    f32 x, y, z;
    lbl_80347F70 = 5;
    x = ang[0];
    y = ang[1];
    z = ang[2];
    if (lv == 0 && z != 0.0f) {
        PSMTXRotRad(t, 'Z', ANG_RAD * z);
        PSMTXConcat(lbl_80347EB4, t, lbl_80347EB4);
    }
    if (y != 0.0f) {
        PSMTXRotRad(t, 'Y', ANG_RAD * y);
        PSMTXConcat(lbl_80347EB4, t, lbl_80347EB4);
    }
    if (x != 0.0f) {
        PSMTXRotRad(t, 'X', ANG_RAD * x);
        PSMTXConcat(lbl_80347EB4, t, lbl_80347EB4);
    }
    if (lv != 0 && z != 0.0f) {
        PSMTXRotRad(t, 'Z', ANG_RAD * z);
        PSMTXConcat(lbl_80347EB4, t, lbl_80347EB4);
    }
}

void njScaleEx(NJS_POINT3* v) {
    f32 t[12];
    PSMTXScale(t, v->x, v->y, v->z);
    PSMTXConcat(lbl_80347EB4, t, lbl_80347EB4);
    lbl_80347F70 = 5;
}

void njTranslateEx(NJS_POINT3* v) {
    f32 t[12];
    PSMTXTrans(t, v->x, v->y, v->z);
    PSMTXConcat(lbl_80347EB4, t, lbl_80347EB4);
    lbl_80347F70 = 5;
}

void fn_80292C74(NjObj* obj, NJS_MOTION* mot, f32 frame) {
    if (lbl_80347FD0 && !(obj->evalflags & 0x10000)) {
        fn_802AB23C(obj);
    }
    if (obj->evalflags & 0x4000) {
        if (obj->evalflags & 0x8000) {
            switch (lbl_80346A50) {
            case 1:
            case 2:
                fn_80295E6C(obj, mot, fn_802A1160, frame);
                break;
            }
        } else {
            fn_80295E6C(obj, mot, fn_802A1160, frame);
        }
    } else {
        if (obj->evalflags & 0x8000) {
            switch (lbl_80346A50) {
            case 1:
            case 2:
                fn_80295E6C(obj, mot, fn_802890A4, frame);
                break;
            }
        } else {
            fn_80295E6C(obj, mot, fn_802890A4, frame);
        }
    }
}

void fn_80292D88(NjObj* obj, NJS_MOTION* mot, f32 frame) {
    lbl_80344DE0.dirty = 1;
    if (lbl_80347FD0 && !(obj->evalflags & 0x10000)) {
        fn_802AB23C(obj);
    }
    if (obj->evalflags & 0x4000) {
        if (obj->evalflags & 0x8000) {
            switch (lbl_80346A50) {
            case 1:
            case 2:
                fn_80295E6C(obj, mot, fn_802A7680, frame);
                break;
            }
        } else {
            fn_80295E6C(obj, mot, fn_802A7680, frame);
        }
    } else {
        if (obj->evalflags & 0x8000) {
            switch (lbl_80346A50) {
            case 1:
            case 2:
                fn_80295E6C(obj, mot, fn_802873BC, frame);
                break;
            }
        } else {
            fn_80295E6C(obj, mot, fn_802873BC, frame);
        }
    }
}

void fn_80292EA8(NjObj* obj, NJS_MOTION_LINK* link, f32 rate) {
    if (lbl_80347FD0 && !(obj->evalflags & 0x10000)) {
        fn_802AB23C(obj);
    }
    if (obj->evalflags & 0x4000) {
        if (obj->evalflags & 0x8000) {
            switch (lbl_80346A50) {
            case 1:
            case 2:
                fn_80295140(obj, link, fn_802A1160, rate);
                break;
            }
        } else {
            fn_80295140(obj, link, fn_802A1160, rate);
        }
    } else {
        if (obj->evalflags & 0x8000) {
            switch (lbl_80346A50) {
            case 1:
            case 2:
                fn_80295140(obj, link, fn_802890A4, rate);
                break;
            }
        } else {
            fn_80295140(obj, link, fn_802890A4, rate);
        }
    }
}

void fn_80292FBC(NjObj* obj, NJS_MOTION_LINK* link, f32 rate) {
    lbl_80344DE0.dirty = 1;
    if (lbl_80347FD0 && !(obj->evalflags & 0x10000)) {
        fn_802AB23C(obj);
    }
    if (obj->evalflags & 0x4000) {
        if (obj->evalflags & 0x8000) {
            switch (lbl_80346A50) {
            case 1:
            case 2:
                fn_80295140(obj, link, fn_802A7680, rate);
                break;
            }
        } else {
            fn_80295140(obj, link, fn_802A7680, rate);
        }
    } else {
        if (obj->evalflags & 0x8000) {
            switch (lbl_80346A50) {
            case 1:
            case 2:
                fn_80295140(obj, link, fn_802873BC, rate);
                break;
            }
        } else {
            fn_80295140(obj, link, fn_802873BC, rate);
        }
    }
}

void fn_802930DC(NjObj* obj, NJS_MOTION_LINK* link, f32 rate) {
    if (lbl_80347FD0 && !(obj->evalflags & 0x10000)) {
        fn_802AB23C(obj);
    }
    if (obj->evalflags & 0x4000) {
        if (obj->evalflags & 0x8000) {
            switch (lbl_80346A50) {
            case 1:
            case 2:
                fn_80295140(obj, link, fn_802A6184, rate);
                break;
            }
        } else {
            fn_80295140(obj, link, fn_802A6184, rate);
        }
    } else {
        if (obj->evalflags & 0x8000) {
            switch (lbl_80346A50) {
            case 1:
            case 2:
                fn_80295140(obj, link, fn_80287C14, rate);
                break;
            }
        } else {
            fn_80295140(obj, link, fn_80287C14, rate);
        }
    }
}

void fn_802931F0(NjObj* obj, NJS_MOTION_LINK* link, f32 rate) {
    lbl_80345350.dirty = 1;
    if (lbl_80347FD0 && !(obj->evalflags & 0x10000)) {
        fn_802AB23C(obj);
    }
    if (obj->evalflags & 0x4000) {
        if (obj->evalflags & 0x8000) {
            switch (lbl_80346A50) {
            case 1:
            case 2:
                fn_80295140(obj, link, fn_802A7FA0, rate);
                break;
            }
        } else {
            fn_80295140(obj, link, fn_802A7FA0, rate);
        }
    } else {
        if (obj->evalflags & 0x8000) {
            switch (lbl_80346A50) {
            case 1:
            case 2:
                fn_80295140(obj, link, fn_8028AB48, rate);
                break;
            }
        } else {
            fn_80295140(obj, link, fn_8028AB48, rate);
        }
    }
}

void fn_80293310(NjObj* obj, NJS_MOTION* mot, f32 frame) {
    if (lbl_80347FD0 && !(obj->evalflags & 0x10000)) {
        fn_802AB23C(obj);
    }
    if (obj->evalflags & 0x4000) {
        if (obj->evalflags & 0x8000) {
            switch (lbl_80346A50) {
            case 1:
            case 2:
                fn_80295E6C(obj, mot, fn_802A6184, frame);
                break;
            }
        } else {
            fn_80295E6C(obj, mot, fn_802A6184, frame);
        }
    } else {
        if (obj->evalflags & 0x8000) {
            switch (lbl_80346A50) {
            case 1:
            case 2:
                fn_80295E6C(obj, mot, fn_80287C14, frame);
                break;
            }
        } else {
            fn_80295E6C(obj, mot, fn_80287C14, frame);
        }
    }
}

void fn_80293424(NjObj* obj, NJS_MOTION* mot, f32 frame) {
    lbl_80345350.dirty = 1;
    if (lbl_80347FD0 && !(obj->evalflags & 0x10000)) {
        fn_802AB23C(obj);
    }
    if (obj->evalflags & 0x4000) {
        if (obj->evalflags & 0x8000) {
            switch (lbl_80346A50) {
            case 1:
            case 2:
                fn_80295E6C(obj, mot, fn_802A7FA0, frame);
                break;
            }
        } else {
            fn_80295E6C(obj, mot, fn_802A7FA0, frame);
        }
    } else {
        if (obj->evalflags & 0x8000) {
            switch (lbl_80346A50) {
            case 1:
            case 2:
                fn_80295E6C(obj, mot, fn_8028AB48, frame);
                break;
            }
        } else {
            fn_80295E6C(obj, mot, fn_8028AB48, frame);
        }
    }
}

void fn_80293544(NjObj* obj, NJS_MOTION* mot, NJS_MOTION* shape, f32 frame) {
    lbl_80344DE0.dirty = 1;
    if (lbl_80347FD0 && !(obj->evalflags & 0x10000)) {
        fn_802AB23C(obj);
    }
    if (obj->evalflags & 0x4000) {
        if (obj->evalflags & 0x8000) {
            switch (lbl_80346A50) {
            case 1:
            case 2:
                fn_8029638C(obj, mot, shape, fn_802A7680, frame, frame);
                break;
            }
        } else {
            fn_8029638C(obj, mot, shape, fn_802A7680, frame, frame);
        }
    } else {
        if (obj->evalflags & 0x8000) {
            switch (lbl_80346A50) {
            case 1:
            case 2:
                fn_8029638C(obj, mot, shape, fn_802873BC, frame, frame);
                break;
            }
        } else {
            fn_8029638C(obj, mot, shape, fn_802873BC, frame, frame);
        }
    }
}

void fn_802936E4(NJ_KEY* src, NJS_MOTION* mot, NJ_KEYDST* dst, f32 f) {
    u32 flags;
    f32* p0 = dst->p0;
    f32* p1 = dst->p1;
    s16* a = dst->a;
    s16* b = dst->b;
    fn_80293B34(0);
    fn_80293B4C(mot, f);
    flags = lbl_80347E64->flags;
    if (flags & 0x1) {
        if (fn_80293EA8(p0) == 0) {
            p0[0] = src->p0[0];
            p0[1] = src->p0[1];
            p0[2] = src->p0[2];
        }
    } else {
        p0[0] = src->p0[0];
        p0[1] = src->p0[1];
        p0[2] = src->p0[2];
    }
    if ((flags & 0x2) || (flags & 0x20) || (flags & 0x2000)) {
        lbl_80347E64->count++;
    }
    if (flags & 0x4) {
        lbl_80347E64->count++;
    }
    if (flags & 0x40) {
        if (fn_80293EA8(p1) == 0) {
            p1[0] = src->p1[0];
            p1[1] = src->p1[1];
            p1[2] = src->p1[2];
        }
    } else if (flags & 0x8) {
        if (fn_80293EA8(p1) == 0) {
            p1[0] = src->p1[0];
            p1[1] = src->p1[1];
            p1[2] = src->p1[2];
        }
    } else {
        p1[0] = src->p1[0];
        p1[1] = src->p1[1];
        p1[2] = src->p1[2];
    }
    if (flags & 0x8000) {
        lbl_80347E64->count++;
    }
    if (flags & 0x80) {
        if (fn_80293E38(a) == 0) {
            *a = src->a;
        }
    }
    if (flags & 0x100) {
        if (fn_80293E38(b) == 0) {
            *b = src->b;
        }
    } else {
        *b = src->b;
    }
}

void fn_802938C0(void (*cb)(NjObj*)) {
    lbl_80347E60 = cb;
}

#pragma optimization_level 1
void fn_80293B34(s32 i) {
    lbl_80347E64 = &lbl_803456D0[i];
}
#pragma optimization_level reset

s32 fn_80293C68(u16* out) {
    void* k = lbl_80347E64->keys[lbl_80347E64->count];
    if (k != 0) {
        fn_80294100(k, lbl_80347E64->nkeys[lbl_80347E64->count], out, lbl_80347E64->frame);
        lbl_80347E64->count++;
        return 1;
    }
    lbl_80347E64->count++;
    return 0;
}

s32 fn_80293CD8(f32* out) {
    void* k = lbl_80347E64->keys[lbl_80347E64->count];
    if (k != 0) {
        fn_80294770(k, lbl_80347E64->nkeys[lbl_80347E64->count], out, lbl_80347E64->frame);
        lbl_80347E64->count++;
        return 1;
    }
    lbl_80347E64->count++;
    return 0;
}

s32 fn_80293D48(s16* out) {
    void* k = lbl_80347E64->keys[lbl_80347E64->count];
    if (k != 0) {
        lbl_80347E64->interpRot16(k, lbl_80347E64->nkeys[lbl_80347E64->count], out, lbl_80347E64->frame);
        lbl_80347E64->count++;
        return 1;
    }
    lbl_80347E64->count++;
    return 0;
}

s32 fn_80293DC0(Angle* out) {
    void* k = lbl_80347E64->keys[lbl_80347E64->count];
    if (k != 0) {
        lbl_80347E64->interpRot(k, lbl_80347E64->nkeys[lbl_80347E64->count], out, lbl_80347E64->frame);
        lbl_80347E64->count++;
        return 1;
    }
    lbl_80347E64->count++;
    return 0;
}

s32 fn_80293E38(s16* out) {
    void* k = lbl_80347E64->keys[lbl_80347E64->count];
    if (k != 0) {
        fn_80294170(k, lbl_80347E64->nkeys[lbl_80347E64->count], out, lbl_80347E64->frame);
        lbl_80347E64->count++;
        return 1;
    }
    lbl_80347E64->count++;
    return 0;
}

s32 fn_80293EA8(f32* out) {
    void* k = lbl_80347E64->keys[lbl_80347E64->count];
    if (k != 0) {
        lbl_80347E64->interpPos(k, lbl_80347E64->nkeys[lbl_80347E64->count], out, lbl_80347E64->frame);
        lbl_80347E64->count++;
        return 1;
    }
    lbl_80347E64->count++;
    return 0;
}

void fn_80294170(void* table, s32 count, s16* out, f32 t) {
    f32 frac;
    s16* lo;
    s16* hi;
    s16 d;
    fn_802938C8(table, 4, count, t, &lo, &hi, &frac);
    d = hi[1] - lo[1];
    *out = frac * d + lo[1];
}

void fn_80294210(void* table, s32 count, s16* out, f32 t) {
    f32 frac;
    s16* lo;
    s16* hi;
    fn_802938C8(table, 8, count, t, &lo, &hi, &frac);
    out[0] = (s16)(frac * (s16)(hi[1] - lo[1]) + lo[1]);
    out[1] = (s16)(frac * (s16)(hi[2] - lo[2]) + lo[2]);
    out[2] = (s16)(frac * (s16)(hi[3] - lo[3]) + lo[3]);
}

void fn_80294360(void* table, s32 count, s32* out, f32 t) {
    f32 frac;
    s32* lo;
    s32* hi;
    fn_802939C4(table, 16, count, t, &lo, &hi, &frac);
    if (lbl_80347E68 != 0) {
        out[0] = (s32)(frac * (hi[1] - lo[1]) + lo[1]);
        out[1] = (s32)(frac * (hi[2] - lo[2]) + lo[2]);
        out[2] = (s32)(frac * (hi[3] - lo[3]) + lo[3]);
    } else {
        out[0] = (s32)(frac * (s16)(hi[1] - lo[1]) + lo[1]);
        out[1] = (s32)(frac * (s16)(hi[2] - lo[2]) + lo[2]);
        out[2] = (s32)(frac * (s16)(hi[3] - lo[3]) + lo[3]);
    }
}

void fn_802945C4(void* table, s32 count, s32* out, f32 t) {
    f32 frac;
    s32* lo;
    s32* hi;
    fn_802939C4(table, 8, count, t, &lo, &hi, &frac);
    if (lbl_80347E68 != 0) {
        *out = (s32)(frac * (hi[1] - lo[1]) + lo[1]);
    } else {
        *out = (s32)(frac * (s16)(hi[1] - lo[1]) + lo[1]);
    }
}

void fn_802947CC(s32 x) {
    lbl_80347E68 = x;
}

/* One level of the motion tree walk: transform, run the motion callback and draw the node, then
 * recurse with NEXT into the children. Four levels are expanded inline before the walker calls
 * itself again. */
#define MOTION_WALK(XFORM, NEXT)                                                                      \
    NjObj saved;                                                                                      \
    do {                                                                                              \
        njPushMatrixEx();                                                                             \
        XFORM(obj);                                                                                   \
        if (lbl_80347E78 != 0) {                                                                      \
            saved = *obj;                                                                             \
            fn_8029518C(obj);                                                                         \
        }                                                                                             \
        if (lbl_80347E60 != 0) {                                                                      \
            lbl_80347E60(obj);                                                                        \
        }                                                                                             \
        if (obj->model != 0 && !(obj->evalflags & 8)) {                                               \
            lbl_80346A18->drawModel(obj->model);                                                      \
        }                                                                                             \
        if (lbl_80347E78 != 0) {                                                                      \
            *obj = saved;                                                                             \
        }                                                                                             \
        if (obj->child != 0) {                                                                        \
            NEXT(obj->child);                                                                         \
        }                                                                                             \
        njPopMatrixEx();                                                                              \
        obj = obj->sibling;                                                                           \
    } while (obj != 0);

static inline void walk_a4(NjObj* obj) {
    MOTION_WALK(fn_802947D4, fn_80294A0C)
}

static inline void walk_a3(NjObj* obj) {
    MOTION_WALK(fn_802947D4, walk_a4)
}

static inline void walk_a2(NjObj* obj) {
    MOTION_WALK(fn_802947D4, walk_a3)
}

static inline void walk_a1(NjObj* obj) {
    MOTION_WALK(fn_802947D4, walk_a2)
}

#pragma opt_propagation off
void fn_802947D4(NjObj* obj) {
    NJS_POINT3 po;
    NJS_POINT3 so;
    f32 qo[4];
    f32 q1[4];
    Angle rot1[3];
    f32 scl1[3];
    f32 pos1[3];
    f32 q0[4];
    Angle rot0[3];
    f32 scl0[3];
    f32 pos0[3];
    f32 s, t;
    s32 r0, r1;
    u16 flags;
    t = lbl_80347E70;
    s = 1.0f - t;
    fn_80293B34(1);
    r1 = fn_802951D4(obj, pos1, rot1, scl1, q1);
    flags = lbl_80347E78 ? lbl_80347E7C : flags;
    fn_80293B34(0);
    r0 = fn_802951D4(obj, pos0, rot0, scl0, q0);
    if (lbl_80347E78 != 0 && t < 1.0f) {
        lbl_80347E7C = flags;
    }
    if (r0 != 2) {
        if (r0 == 0) {
            fn_802926A4(rot0, q0);
        } else {
            fn_802927CC(rot0, q0);
        }
    }
    if (r1 != 2) {
        if (r1 == 0) {
            fn_802926A4(rot1, q1);
        } else {
            fn_802927CC(rot1, q1);
        }
    }
    po.x = pos0[0] * s + pos1[0] * t;
    po.y = pos0[1] * s + pos1[1] * t;
    po.z = pos0[2] * s + pos1[2] * t;
    so.x = scl0[0] * s + scl1[0] * t;
    so.y = scl0[1] * s + scl1[1] * t;
    so.z = scl0[2] * s + scl1[2] * t;
    fn_80291CF8(q0, q1, qo, t);
    njTranslateEx(&po);
    fn_802929C0(qo);
    njScaleEx(&so);
}

#pragma opt_propagation reset

void fn_802949A4(NJS_MOTION_LINK* link, f32 rate) {
    fn_80293B34(1);
    fn_8029557C(link->motion[1], link->frame[1]);
    fn_80293B34(0);
    fn_8029557C(link->motion[0], link->frame[0]);
    lbl_80347E70 = rate;
}

void fn_80294A0C(NjObj* obj) {
    MOTION_WALK(fn_802947D4, walk_a1)
}

void fn_80295140(NjObj* obj, NJS_MOTION_LINK* link, NjModelCb cb, f32 rate) {
    fn_802949A4(link, rate);
    lbl_80346A18->drawModel = cb;
    fn_80294A0C(obj);
}

void fn_8029518C(NjObj* obj) {
    if (lbl_80347E78 == 0) {
        return;
    }
    if (lbl_80347E7C & 1) {
        obj->evalflags |= 8;
    } else {
        obj->evalflags &= ~8;
    }
}

s32 fn_802951C4(Angle* p) {
    return 0;
}

s32 fn_802951CC(f32* p) {
    return 0;
}

#define KEY_ROT(ret)                                                                                  \
    if (obj->evalflags & 0x400) {                                                                     \
        quat[3] = obj->radius;                                                                        \
        ret = 2;                                                                                      \
        quat[0] = obj->rot.quat.x;                                                                    \
        quat[1] = obj->rot.quat.y;                                                                    \
        quat[2] = obj->rot.quat.z;                                                                    \
    } else {                                                                                          \
        rot[0] = obj->rot.ang[0];                                                                     \
        rot[1] = obj->rot.ang[1];                                                                     \
        rot[2] = obj->rot.ang[2];                                                                     \
        ret = (obj->evalflags >> 5) & 1;                                                              \
    }

s32 fn_802951D4(NjObj* obj, f32* pos, Angle* rot, f32* scale, f32* quat) {
    s32 ret;
    s16 tmp[3];
    if (!(obj->evalflags & 0x40)) {
        if (!lbl_80347E64->getPos(pos)) {
            pos[0] = obj->pos.x;
            pos[1] = obj->pos.y;
            pos[2] = obj->pos.z;
        }
        if (lbl_80347E64->getRot) {
            if (lbl_80347E64->getRot(rot)) {
                ret = (obj->evalflags >> 5) & 1;
            } else {
                KEY_ROT(ret)
            }
        } else if (lbl_80347E64->getRot16) {
            if (lbl_80347E64->getRot16(tmp)) {
                rot[0] = tmp[0];
                rot[1] = tmp[1];
                rot[2] = tmp[2];
                ret = (obj->evalflags >> 5) & 1;
            } else {
                KEY_ROT(ret)
            }
        } else {
            if (lbl_80347E64->getQuat(quat)) {
                ret = 2;
            } else {
                KEY_ROT(ret)
            }
        }
        if (!lbl_80347E64->getScale(scale)) {
            scale[0] = obj->scl.x;
            scale[1] = obj->scl.y;
            scale[2] = obj->scl.z;
        }
        if (lbl_80347E78 != 0) {
            if (fn_80293C68(&lbl_80347E7C) == 0) {
                if (obj->evalflags & 8) {
                    lbl_80347E7C |= 1;
                } else {
                    lbl_80347E7C &= ~1;
                }
            }
        }
        fn_80293C2C();
    } else {
        pos[0] = obj->pos.x;
        pos[1] = obj->pos.y;
        pos[2] = obj->pos.z;
        scale[0] = obj->scl.x;
        scale[1] = obj->scl.y;
        scale[2] = obj->scl.z;
        KEY_ROT(ret)
    }
    return ret;
}

#pragma optimization_level 1
void fn_802954EC(NjObj* obj) {
    NJS_POINT3 pos;
    NJS_POINT3 scale;
    Angle rot[3];
    f32 quat[4];
    s32 r = fn_802951D4(obj, &pos.x, rot, &scale.x, quat);
    njTranslateEx(&pos);
    switch (r) {
    case 0:
        njRotateEx(rot, 0);
        break;
    case 1:
        njRotateEx(rot, 1);
        break;
    default:
        fn_802929C0(quat);
        break;
    }
    njScaleEx(&scale);
}
#pragma optimization_level reset

void fn_8029557C(NJS_MOTION* mot, f32 frame) {
    u32 fl;
    fn_80293B4C(mot, frame);
    fl = lbl_80347E64->flags;
    if (fl & 1) {
        lbl_80347E64->getPos = fn_80293EA8;
    } else {
        lbl_80347E64->getPos = fn_802951CC;
    }
    if (fl & 2) {
        lbl_80347E64->getRot = fn_80293DC0;
        lbl_80347E64->getQuat = 0;
        lbl_80347E64->getRot16 = 0;
    } else if (fl & 0x20) {
        lbl_80347E64->getRot = 0;
        lbl_80347E64->getQuat = 0;
        lbl_80347E64->getRot16 = fn_80293D48;
    } else if (fl & 0x2000) {
        lbl_80347E64->getRot = 0;
        lbl_80347E64->getQuat = fn_80293CD8;
        lbl_80347E64->getRot16 = 0;
    } else {
        lbl_80347E64->getRot = fn_802951C4;
        lbl_80347E64->getQuat = 0;
        lbl_80347E64->getRot16 = 0;
    }
    if (fl & 4) {
        lbl_80347E64->getScale = fn_80293EA8;
    } else {
        lbl_80347E64->getScale = fn_802951CC;
    }
    if ((fl & 8) || (fl & 0x40)) {
        lbl_80347E64->count++;
    }
    if (fl & 0x8000) {
        lbl_80347E78 = 1;
        lbl_80347E7C = 0;
    } else {
        lbl_80347E78 = 0;
        lbl_80347E7C = 0;
    }
}

void fn_802956F0(NJS_MOTION* mot, f32 frame) {
    fn_80293B34(0);
    fn_8029557C(mot, frame);
}

static inline void walk_b4(NjObj* obj) {
    MOTION_WALK(fn_802954EC, fn_80295738)
}

static inline void walk_b3(NjObj* obj) {
    MOTION_WALK(fn_802954EC, walk_b4)
}

static inline void walk_b2(NjObj* obj) {
    MOTION_WALK(fn_802954EC, walk_b3)
}

static inline void walk_b1(NjObj* obj) {
    MOTION_WALK(fn_802954EC, walk_b2)
}

void fn_80295738(NjObj* obj) {
    MOTION_WALK(fn_802954EC, walk_b1)
}

void fn_80295E6C(NjObj* obj, NJS_MOTION* mot, NjModelCb cb, f32 frame) {
    fn_802956F0(mot, frame);
    lbl_80346A18->drawModel = cb;
    fn_80295738(obj);
}

void fn_80295EB8(NjModel* m) {
    s32 i = 0;
    u32* cur = m->vlist;
    u32 hdr;
    f32 frac;
    s32* hi;
    s32* lo;

    while (i < lbl_80347E88->count) {
        s32 idx = (*lbl_80347E80)[lbl_80347E88->rec->table[1]].idx;

        lbl_80347E88->idx = idx;
        if (lbl_80347E88->key != lbl_80347E84[idx].key) {
            fn_802939C4(lbl_80347E88->rec->table, 8, lbl_80347E88->rec->count, lbl_80347E88->t, &lo, &hi, &frac);
            lbl_80347E84[idx].key = lbl_80347E88->key;
            lbl_80347E84[idx].a = lo[1];
            lbl_80347E84[idx].b = hi[1];
            lbl_80347E84[idx].frac = frac;
        }
        hdr = *cur;
        cur += 2;
        fn_80296680(cur, hdr & 0xFF);
        cur += (hdr >> 16) - 1;
        i++;
        lbl_80347E88->rec++;
    }
}

#pragma optimization_level 1
void fn_80296090(s32 i) { lbl_80347E88 = &lbl_80345770[i]; }
#pragma optimization_level reset

#pragma opt_propagation off
void fn_802960A8(NJS_MOTION* m, f32 t) {
    NjCacheCtx* c = lbl_80347E88;
    void* p = m->mdata;
    c->cur = p;
    lbl_80347E88->w8 = m->nbFrame;
    lbl_80347E88->t = t;
    lbl_80347E88->key++;
    lbl_80347E88->count = lbl_80347E88->cur->count;
    lbl_80347E88->rec = lbl_80347E88->cur->rec;
}
#pragma opt_propagation reset

void fn_802960FC(void) {
    lbl_80347E88->cur++;
    lbl_80347E88->count = lbl_80347E88->cur->count;
    lbl_80347E88->rec = lbl_80347E88->cur->rec;
}

void fn_80296130(NjObj* obj) {
    NjObj saved;
    NjModel* model;
    do {
        njPushMatrixEx();
        if (lbl_80347E90 != 0) {
            fn_802954EC(obj);
            if (lbl_80347E78 != 0) {
                saved = *obj;
                fn_8029518C(obj);
            }
        } else {
            if (!(obj->evalflags & 1)) {
                njTranslateEx(&obj->pos);
            }
            if (!(obj->evalflags & 2)) {
                if (obj->evalflags & 0x400) {
                    fn_80292A00(&obj->rot.quat, obj->radius);
                } else {
                    njRotateEx(obj->rot.ang, obj->evalflags & 0x20);
                }
            }
            if (!(obj->evalflags & 4)) {
                njScaleEx(&obj->scl);
            }
        }
        if (lbl_80347E60 != 0) {
            lbl_80347E60(obj);
        }
        if (!(obj->evalflags & 0x80)) {
            model = obj->model;
            if (model != 0 && !(obj->evalflags & 8)) {
                if (lbl_80347E88->cur->rec != 0) {
                    fn_80295EB8(model);
                }
                lbl_80346A18->drawModel(model);
            }
            fn_802960FC();
        } else {
            if (obj->model != 0 && !(obj->evalflags & 8)) {
                lbl_80346A18->drawModel(obj->model);
            }
        }
        if (lbl_80347E90 != 0 && lbl_80347E78 != 0) {
            *obj = saved;
        }
        if (obj->child != 0) {
            fn_80296130(obj->child);
        }
        njPopMatrixEx();
        obj = obj->sibling;
    } while (obj != 0);
}

void fn_8029638C(NjObj* obj, NJS_MOTION* mot, NJS_MOTION* shape, NjModelCb cb, f32 frame, f32 sframe) {
    lbl_80347E90 = mot;
    if (mot) {
        fn_802956F0(mot, frame);
    }
    lbl_80346A18->drawModel = cb;
    if (!shape) {
        fn_80295738(obj);
    } else {
        fn_80296090(0);
        fn_802960A8(shape, sframe);
        fn_80296130(obj);
    }
}

void fn_802968B8(void) {
}

void fn_802968BC(u32 argb) {
    GXColor c;
    c.b = argb;
    c.a = argb >> 24;
    c.r = argb >> 16;
    c.g = argb >> 8;

    fn_8029CB1C();
    fn_8029B248(5, 1);
    GXSetChanMatColor(GX_COLOR0A0, c);
}

void fn_80296B34(void) {
    GXEnableTexOffsets(0, 0, 0);
}

void fn_80296BE4(s16 a, s16 b, s16 c, f32 f) {
    lbl_803457A8.f14 = f;
    lbl_803457A8.f06 = a;
    lbl_803457A8.f08 = b;
    lbl_803457A8.f0A = c;
}

void fn_80296C58(u16 type, u16 src, u16 dst, u16 op) {
    lbl_803457A8.blendType = type;
    lbl_803457A8.blendSrc = src;
    lbl_803457A8.blendDst = dst;
    lbl_803457A8.blendOp = op;
    GXSetBlendMode(type, src, dst, op);
}

void fn_80296ED4(s32 a) {
    lbl_803457A8.f18 = a;
    lbl_803457A8.w48 = -1;
}

void fn_80296EEC(u16 enable, s32 func, u16 update) {
    lbl_803457A8.h00 = enable;
    lbl_803457A8.h02 = func;
    lbl_803457A8.h04 = update;
    GXSetZMode(enable, func, update);
}

void fn_80296F28(void) {
    lbl_80347F74 = -1;
    lbl_80347F68 = -1;
    lbl_80347F6C = 2;
    lbl_80347F70 = 5;
}

void fn_80296F48(void) {
    lbl_80347F08 = OSGetTick();
}

void fn_80296F6C(void) {
    lbl_80347F04 = OSGetTick();
    lbl_80347EF8 = 0;
    lbl_80347EF4 = 0;
    lbl_80347EF0 = 0;
}

void fn_80296FA0(void) {
    lbl_80345878[7] = 1.0f;
    lbl_80345878[8] = 1.0f;
    lbl_80345878[9] = 1.0f;
    lbl_80345878[6] = 500.0f;
    lbl_80345878[0] = lbl_80345878[7] * lbl_80345878[6];
    lbl_80345878[1] = -lbl_80345878[0];
    lbl_80345878[4] = lbl_80345878[7] / lbl_80345878[0];
    lbl_80345878[5] = lbl_80345878[7] / lbl_80345878[1];
    lbl_80345850[0] = 60000.0f;
    lbl_80345850[1] = 1.0f;
    _nj_control_3d_flag_ = 0;
    lbl_80347E60 = 0;
    lbl_80347ED8 = 1.5259022e-5f;
    lbl_80347F30 = 1.0f;
    lbl_80347F34 = 0.0f;
    lbl_803457A8.texlist = 0;
    lbl_803457A8.w48 = -1;
    lbl_803457A8.w4c = -1;
    lbl_803457A8.f18 = 0;
    lbl_803457A8.h1a = 0;
    lbl_803457A8.h1c = 1;
    lbl_803457A8.h1e = 1;
    lbl_803457A8.h20 = 1;
    lbl_803457A8.h00 = 1;
    lbl_803457A8.h02 = 3;
    lbl_803457A8.h04 = 1;
    lbl_803457A8.f0c = 1.0f;
    lbl_803457A8.f10 = 100.0f;
    lbl_803457A8.f14 = 0.0f;
    lbl_803457A8.f06 = 0;
    lbl_803457A8.f08 = 0;
    lbl_803457A8.f0A = 0;
    lbl_803457A8.blendType = 1;
    lbl_803457A8.blendSrc = 4;
    lbl_803457A8.blendDst = 5;
    lbl_803457A8.blendOp = 5;
    lbl_803457A8.mode = 0;
    lbl_80347F6C = 2;
    lbl_80347F70 = 5;
}

void fn_8029748C(NJS_MATRIX m) {
    memcpy(m, lbl_80347EB4, 0x30);
}

void fn_802974B4(NJS_MATRIX m) {
    memcpy(lbl_80347EB4, m, 0x30);
}

void fn_802974E0(void) {
}

static inline s32 read_tex(NjTexRef* r, void* dst) {
    if (fn_8029954C(dst, &r->mem->body)) {
        return -1;
    }
    return 1;
}

f32 fn_802974E4(f32 x) {
    return fn_80291978(x);
}

void fn_80297504(int a, f32* s, f32* c) {
    *s = njSin(a);
    *c = njCos(a);
}

#pragma optimization_level 1
/* K&R definition: fn_8029CF7C also calls it with only the texture body. */
s32 fn_802976F8(b, w, h, fmt)
NjTexBody* b;
u32 w;
u32 h;
u32 fmt;
{
    u32 f;
    s32 extra;
    u8 mip;
    u32 g;
    u32 size;
    b->w00 = fmt & 0xff;
    b->w0c = w;
    b->w10 = h;
    b->w08 = b->flags = 0;
    f = 0;
    if (fmt & 0x100) f |= 0x80000000;
    if (fmt & 0x200) f |= 0x8000;
    if (fmt & 0x400) f |= 0x1000000;
    if (fmt & 0x800) {
        f |= 0x40000000;
        if (fmt & 0x1000) b->w08 = 1;
        if (fmt & 0x2000) b->w08 = 2;
    }
    b->flags = f;
    extra = 0;
    g = b->flags;
    mip = g >> 31;
    if (g & 0x40000000) {
        switch (b->w00) {
        case 8:
            extra = 0x20;
            break;
        case 9:
            extra = 0x200;
            break;
        }
    }
    size = GXGetTexBufferSize(b->w0c, b->w10, b->w00, mip, 100);
    b->size = size + extra;
    return 0;
}

#pragma optimization_level reset

void fn_802979B8(void) {
    s32 i;
    NjTexMem* a = lbl_80347ECC;
    NjTexRef* b;
    for (i = 0; i < lbl_80347EC8; i++, a++) {
        if (a->id != 0xFFFFFFFF) {
            fn_8029959C(&a->body);
        }
        a->id = -1;
        a->body.w00 = 0;
        a->body.w04 = 0;
        a->body.w08 = 0;
        a->body.w0c = 0;
        a->body.w10 = 0;
        a->body.size = 0;
        a->body.flags = 0;
        a->body.data = 0;
    }
    b = lbl_80347ED4;
    for (i = 0; i < lbl_80347ED0; i++, b++) {
        b->key = -1;
        b->w00 = 0;
        b->w04 = 0;
        b->mem = 0;
        b->refs = 0;
        b->w14 = 0;
    }
    lbl_80347EC4 = 0;
    lbl_803457A8.w48 = -1;
}

s32 fn_80297AC0(NjTexRef* r) {
    if (r->mem == 0) {
        return -1;
    }
    if (r->refs > 0) {
        r->refs--;
    }
    if (r->mem->refs > 0) {
        r->mem->refs--;
        if (r->mem->refs == 0) {
            fn_8029959C(&r->mem->body);
            lbl_803457A8.w48 = -1;
        }
    }
    fn_80298144(r);
    return 1;
}

s32 fn_80297B5C(s32 key) {
    s32 r;
    fn_80298E48();
    r = fn_802982F0(key);
    if (r < 0) {
        lbl_803457F8.globalIndex = key;
        lbl_803457F8.texerr = 1;
        return -1;
    }
    r = fn_80297AC0(lbl_80347ED4 + r);
    if (r < 0) lbl_803457F8.globalIndex = key;
    return r;
}

static inline s32 load_tex(NjTexMem* m, void* a, u32 b) {
    if ((m->body.flags & 0x80000000) && b) {
        if (fn_802995CC(&m->body, a, b)) {
            lbl_803457F8.texerr = 8;
            return -1;
        }
    } else {
        if (fn_80298694(&m->body, a)) {
            lbl_803457F8.texerr = 8;
            return -1;
        }
    }
    return 1;
}

s32 fn_80297BD8(s32 idx, void* a, u32 b) {
    s32 r;
    fn_80298E48();
    r = load_tex(lbl_803457A8.texlist->textures[idx].texaddr->mem, a, b);
    if (r < 0) {
        lbl_803457F8.n = idx;
    }
    return r;
}

static inline s32 reload_tex(NjTexMem* m, void* a, u32 b, u32 c) {
    s32 e = fn_802986C8(&m->body, a, b, c);
    if (e) {
        switch (e) {
        case 7:
            lbl_803457F8.texerr = 8;
            break;
        case 4:
            lbl_803457F8.texerr = 4;
            break;
        }
        return -1;
    }
    return 1;
}

s32 fn_80297CC0(s32 idx, void* a, u32 b, u32 c) {
    s32 r;
    fn_80298E48();
    r = reload_tex(lbl_803457A8.texlist->textures[idx].texaddr->mem, a, b, c);
    if (r < 0) {
        lbl_803457F8.n = idx;
    }
    return r;
}

void fn_80297DA4(Rec3* p, s32 a, s32 b, s32 c) {
    p->f0 = a;
    p->f4 = c;
    p->f8 = b;
}

void fn_80297DB4(Rec6* p, s32 a, s32 b, s32 c, s32 d) {
    p->f0 = a;
    p->f10 = c;
    p->f14 = d;
    p->f4 = b;
}

s32 fn_80297DC8(s32 key) {
    NjTexRef* r;
    s32 i = fn_802982F0(key);
    if (i < 0) {
        return -1;
    }
    r = &lbl_80347ED4[i];
    if (lbl_803457A8.w48 != r->mem->id) {
        lbl_803457A8.w48 = r->mem->id;
        lbl_803457A8.w4c = r->key;
        fn_8029976C(&r->mem->body, 0);
    }
    return 1;
}

s32 fn_8029800C(u32 fmt) {
    switch ((u8)fmt) {
    case 8:
    case 9:
    case 10:
        return 1;
    }
    return 0;
}

static inline void str_upper(char* s) {
    while (*s) {
        *s = toupper(*s);
        s++;
    }
}

void fn_80298034(char* dst, char* name, char* ext) {
    char buf[8];
    s32 len = strlen(name);
    if (len > 4) {
        strcpy(buf, &name[len - 4]);
        str_upper(buf);
    } else {
        buf[0] = 0;
    }
    if (buf[0] == '.') {
        if (strcmp(buf, ext) != 0) {
            strcpy(dst, name);
            strcat(dst, ext);
        } else {
            strcpy(dst, name);
        }
    } else {
        strcpy(dst, name);
        strcat(dst, ext);
    }
}

void fn_80298144(NjTexRef* r) {
    NjTexMem* m = r->mem;
    if (m->refs <= 0) {
        m->id = -1;
        m->body.w00 = 0;
        m->body.w04 = 0;
        m->body.w08 = 0;
        m->body.w0c = 0;
        m->body.w10 = 0;
        m->body.size = 0;
        m->body.flags = 0;
        m->body.data = 0;

        lbl_80347EC4--;
    }
    if (r->refs <= 0) {
        r->key = -1;
        r->w00 = 0;
        r->w04 = 0;
        r->mem = 0;
        r->w14 = 0;
    }
}

s32 fn_802981B8(u32 id, u32 key) {
    s32 i;
    NjTexRef* b = lbl_80347ED4;
    for (i = 0; i < lbl_80347ED0; b++, i++) {
        if (b->key == key && b->mem != NULL && b->mem->id == id) {
            return i;
        }
    }
    return -1;
}

s32 fn_80298210(NjTexRef** outB, NjTexMem** outA) {
    s32 i;
    NjTexRef* b;
    s32 idx;
    NjTexMem* a;
    *outB = NULL;
    b = lbl_80347ED4;
    for (i = 0; i < lbl_80347ED0; b++, i++) {
        if (b->mem == NULL) {
            *outB = b;
            idx = i;
            break;
        }
    }
    if (*outB == NULL) {
        lbl_803457F8.texerr = 7;
        return -1;
    }
    if (outA != NULL) {
        *outA = NULL;
        a = lbl_80347ECC;
        for (i = 0; i < lbl_80347EC8; a++, i++) {
            if (a->id == 0xFFFFFFFF) {
                *outA = a;
                break;
            }
        }
        if (*outA == NULL) {
            lbl_803457F8.texerr = 7;
            return -1;
        }
        return idx;
    }
    return idx;
}

s32 fn_802982F0(s32 key) {
    s32 i;
    for (i = 0; i < lbl_80347ED0; i++) {
        if (lbl_80347ED4[i].mem != 0 && key == lbl_80347ED4[i].mem->id) return i;
    }
    return -1;
}

s32 fn_80298694(NjTexBody* b, const void* src) {
    fn_802994B8(b->data, src, b->size, 0);
    return 0;
}

#pragma optimization_level 1
s32 fn_80298700(NjTexRef* r) {
    if (fn_8029959C(&r->mem->body) != 0) {
        return -1;
    }
    return 1;
}
#pragma optimization_level reset

s32 fn_8029873C(NjTexRef* r, NjTexSize* sz) {
    if (fn_80297804(&r->mem->body, sz->w, sz->h, sz->fmt) != 0) {
        lbl_803457F8.texerr = 6;
        return -1;
    }
    return 1;
}

#pragma optimization_level 1
#pragma optimization_level 1
void fn_80298BCC(s32 n) { fn_80297AC0(&lbl_80347ED4[n]); }

#pragma optimization_level reset

s32 fn_80298BF8(s32 idx, void* src) {
    NjTexMem* m = lbl_80347ED4[idx].mem;
    if (m == NULL) {
        lbl_803457F8.texerr = 1;
        return -1;
    }
    if (fn_802986C8(&m->body, src, 0, m->body.size) != 0) {
        lbl_803457F8.texerr = 8;
        return -1;
    }
    return 1;
}
#pragma optimization_level reset

void fn_80298C78(NJS_TEXLIST* tl, s32 i, s32 j) {
    tl->textures[i].texaddr = &lbl_80347ED4[j];
    tl->textures[i].attr |= 0x200000;
}

#pragma optimization_level 1
#pragma opt_common_subs on
static inline s32 find_tex(u32 id) {
    return fn_802982F0(id);
}
s32 fn_80298CAC(u32 id, u32 key, u32 fmt, s32* out) {
    s32 idx = find_tex(id);
    s32 r;
    s32 n;
    NjTexRef* nr;
    if (fn_8029800C(fmt)) {
        if (idx < 0) {
            *out = -1;
            return 0;
        }
        r = fn_802981B8(id, key);
        if (r < 0) {
            n = fn_80298210(&nr, NULL);
            if (n < 0) {
                return -1;
            }
            nr->key = key;
            nr->mem = lbl_80347ED4[idx].mem;
            nr->mem->refs++;
            nr->refs = 1;
            nr->w14 = lbl_80347ED4[idx].w14;
            fn_80297E3C(nr);
            *out = n;
            return 1;
        }
        *out = r;
        lbl_80347ED4[r].refs++;
        lbl_80347ED4[r].mem->refs++;
        return 1;
    }
    *out = idx;
    if (idx < 0) {
        return 0;
    }
    lbl_80347ED4[idx].refs++;
    lbl_80347ED4[idx].mem->refs++;
    return 1;
}

#pragma opt_common_subs reset
#pragma optimization_level reset

void fn_80298E48(void) {
    lbl_803457F8.n = -1;
    lbl_803457F8.globalIndex = -1;
    lbl_803457F8.texerr = 0;
    lbl_803457F8.w0c = 0;
    lbl_803457F8.w10 = 0;
}

NjTexErr* fn_80298E6C(void) {
    return &lbl_803457F8;
}

s32 fn_80298E78(u32 n) {
    s32 a, b;
    if (n == 2) return lbl_80347EC0;
    fn_80299744(&a, &b);
    if (n == 0) return a;
    return b;
}

s32 fn_80298ED0(u32 idx) {
    NJS_TEXLIST* tl = lbl_803457A8.texlist;
    GXTexObj* obj;
    s32 i;
    if (tl->nbTexture <= idx) {
        return -1;
    }
    obj = &tl->textures[idx].texaddr->mem->texobj;
    for (i = 0; i < 8; i++) {
        if (lbl_80345AA0[i].obj == obj) {
            break;
        }
    }
    for (i = 0; i < 8; i++) {
        GXInvalidateTexRegion(&lbl_80345AA0[i].region);
    }
    lbl_803457A8.w48 = -1;
    lbl_803457A8.w4c = -1;
    return 0;
}

#pragma optimization_level 1
s32 fn_80299040(NJS_TEXLIST* t) {
    lbl_803457A8.texlist = t;
    return 1;
}
#pragma optimization_level reset

void fn_80299058(void) {
    fn_802979B8();
}

void fn_80299078(NjTexRef* a, s32 b, NjTexMem* c, s32 d) {
    fn_80298544(a, b);
    fn_8029833C(c, d);
}

void njClipZ(f32 near, f32 far) {
    if (near > -1.0f) near = -1.0f;
    if (far > -1.0f) far = -1.0f;
    lbl_80345850[1] = -near;
    lbl_80345850[0] = -far;
    C_MTXFrustum(lbl_80346400, lbl_80345850[1] * (lbl_80345850[5] * lbl_80345878[5]),
                 lbl_80345850[1] * (lbl_80345850[4] * lbl_80345878[5]),
                 lbl_80345850[1] * (lbl_80345850[3] * lbl_80345878[4]),
                 lbl_80345850[1] * (lbl_80345850[2] * lbl_80345878[4]), lbl_80345850[1], lbl_80345850[0]);
    lbl_80347F6C = 2;
}

s32 fn_802994B0(void) {
    return 0;
}

s32 fn_802994B8(void* dst, const void* src, u32 n, s32 unused) {
    fn_802AC710(dst, src, n);
    DCFlushRange(dst, n);
    return 0;
}

#pragma optimization_level 1
s32 fn_80299500(void* a, u32 size, void** out) {
    s32 r;
    *out = OSAllocFromHeapClear(lbl_80347F44, size);
    r = 3;
    if (*out) r = 0;
    return r;
}

#pragma optimization_level reset

s32 fn_8029954C(void* dst, NjTexBody* b) {
    fn_802AC710(dst, b->data, b->size);
    DCFlushRange(dst, b->size);
    return 0;
}

s32 fn_8029959C(NjTexBody* b) {
    OSFreeToHeap(lbl_80347F44, b->data);
    return 0;
}

#pragma optimization_level 1
s32 fn_802995CC(NjTexBody* b, void* src, u32 dv) {
    s32 div = dv;
    u32 sz;
    void* d;
    s32 w = b->w0c;
    s32 h = b->w10;
    u32 fmt = b->w00;
    s32 lod;
    u32 off;
    lod = w / div;
    switch (lod) {
    case 1: lod = 0; break;
    case 2: lod = 1; break;
    case 4: lod = 2; break;
    case 8: lod = 3; break;
    case 0x10: lod = 4; break;
    case 0x20: lod = 5; break;
    case 0x40: lod = 6; break;
    case 0x80: lod = 7; break;
    case 0x100: lod = 8; break;
    case 0x200: lod = 9; break;
    case 0x400: lod = 10; break;
    }
    off = GXGetTexBufferSize(w, h, fmt, 1, lod);
    sz = GXGetTexBufferSize(w, h, fmt, 1, lod + 1) - off;
    d = b->data + off;
    fn_802AC710(d, src, sz);
    DCFlushRange(b->data + off, sz);
    return 0;
}
#pragma optimization_level reset

s32 fn_80299744(s32* a, s32* b) {
    *a = 0;
    *b = 0;
    return 0;
}

void* fn_80299758(s32 i) {
    return &lbl_80345BC0[i << 4];
}

void fn_80299BD8(s32 flag) {
    if (lbl_803457A8.mode == 1) {
        flag = 0;
    }
    GXSetNumTevStages(5);
    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
    GXSetTevOrder(GX_TEVSTAGE1, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR0A0);
    GXSetTevOrder(GX_TEVSTAGE2, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR0A0);
    GXSetTevOrder(GX_TEVSTAGE3, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR_NULL);
    GXSetTevOrder(GX_TEVSTAGE4, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR_NULL);
    GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_ZERO, GX_CC_TEXC, GX_CC_RASC, GX_CC_ZERO);
    GXSetTevColorOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_2, GX_TRUE, GX_TEVPREV);
    GXSetTevColorIn(GX_TEVSTAGE1, GX_CC_RASC, GX_CC_ZERO, GX_CC_ZERO, GX_CC_ZERO);
    GXSetTevColorOp(GX_TEVSTAGE1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_2, GX_FALSE, GX_TEVREG0);
    GXSetTevColorIn(GX_TEVSTAGE2, GX_CC_RASC, GX_CC_ZERO, GX_CC_ZERO, GX_CC_ZERO);
    GXSetTevColorOp(GX_TEVSTAGE2, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_2, GX_TRUE, GX_TEVREG1);
    GXSetTevColorIn(GX_TEVSTAGE3, GX_CC_C1, GX_CC_ZERO, GX_CC_ZERO, GX_CC_C0);
    GXSetTevColorOp(GX_TEVSTAGE3, GX_TEV_SUB, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVREG0);
    GXSetTevColorIn(GX_TEVSTAGE4, GX_CC_C0, GX_CC_ZERO, GX_CC_ZERO, GX_CC_CPREV);
    GXSetTevColorOp(GX_TEVSTAGE4, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    if (flag) {
        GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_ZERO, GX_CA_TEXA, GX_CA_RASA, GX_CA_ZERO);
        GXSetTevAlphaIn(GX_TEVSTAGE1, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_APREV);
        GXSetTevAlphaOp(GX_TEVSTAGE1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
        GXSetTevAlphaIn(GX_TEVSTAGE2, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_APREV);
        GXSetTevAlphaOp(GX_TEVSTAGE2, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
        GXSetTevAlphaIn(GX_TEVSTAGE3, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_APREV);
        GXSetTevAlphaOp(GX_TEVSTAGE3, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
        GXSetTevAlphaIn(GX_TEVSTAGE4, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_APREV);
        GXSetTevAlphaOp(GX_TEVSTAGE4, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
        GXSetZCompLoc(lbl_80347F50);
        GXSetAlphaCompare(lbl_80346A38, lbl_80347F54, lbl_80347F58, lbl_80346A3C, lbl_80347F5C);
    } else {
        GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_KONST, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO);
        GXSetZCompLoc(lbl_80346A40);
        GXSetAlphaCompare(lbl_80346A44, lbl_80347F5D, lbl_80347F60, lbl_80346A48, lbl_80347F64);
    }
    GXSetTevAlphaOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    GXSetTevAlphaIn(GX_TEVSTAGE1, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_APREV);
    GXSetTevAlphaOp(GX_TEVSTAGE1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    GXSetTevAlphaIn(GX_TEVSTAGE2, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_APREV);
    GXSetTevAlphaOp(GX_TEVSTAGE2, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    GXSetTevAlphaIn(GX_TEVSTAGE3, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_APREV);
    GXSetTevAlphaOp(GX_TEVSTAGE3, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    GXSetTevAlphaIn(GX_TEVSTAGE4, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_APREV);
    GXSetTevAlphaOp(GX_TEVSTAGE4, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
}

void fn_80299FC8(s32 hasAlpha) {
    GXSetTexCoordGen2(0, 1, 4, 0x3C, 0, 0x7D);
    GXSetTexCoordGen2(1, 1, 5, 0x3C, 0, 0x7D);
    GXSetNumTexGens(2);
    GXSetNumTevStages(3);
    GXSetTevOrder(0, 0, 1, 0xFF);
    GXSetTevOrder(1, 1, 1, 0xFF);
    GXSetTevOrder(2, 0xFF, 0xFF, 4);
    GXSetTevSwapModeTable(1, 2, 0, 0, 1);
    GXSetTevSwapMode(1, 0, 1);
    GXSetTevColorIn(0, 15, 15, 15, 8);
    GXSetTevColorOp(0, 0, 0, 0, 1, 0);
    GXSetTevColorIn(1, 8, 15, 15, 0);
    GXSetTevColorOp(1, 0, 0, 0, 1, 0);
    GXSetTevColorIn(2, 15, 10, 0, 15);
    GXSetTevColorOp(2, 0, 0, 1, 1, 0);
    GXSetTevAlphaIn(0, 7, 7, 7, 7);
    GXSetTevAlphaOp(0, 0, 0, 0, 1, 0);
    GXSetTevAlphaIn(1, 4, 7, 7, 0);
    GXSetTevAlphaOp(1, 0, 0, 0, 1, 0);
    GXSetTevAlphaIn(2, 7, 7, 7, 0);
    GXSetTevAlphaOp(2, 0, 0, 0, 1, 0);
}

void fn_8029A1C8(s32 hasAlpha) {
    GXSetTevOrder(0, 0xFF, 0xFF, 4);
    GXSetNumTevStages(1);
    GXSetTevColorIn(0, 10, 15, 15, 15);
    GXSetTevColorOp(0, 0, 0, 1, 1, 0);
    if (hasAlpha != 0) {
        GXSetTevAlphaIn(0, 5, 7, 7, 7);
    } else {
        GXSetTevAlphaIn(0, 6, 7, 7, 7);
    }
    GXSetTevAlphaOp(0, 0, 0, 0, 1, 0);
}

void fn_8029A298(s32 hasAlpha) {
    GXSetTexCoordGen2(0, 1, 4, 0x3C, 0, 0x7D);
    GXSetTexCoordGen2(1, 1, 5, 0x3C, 0, 0x7D);
    GXSetNumTexGens(2);
    GXSetNumTevStages(2);
    GXSetTevOrder(0, 0, 1, 0xFF);
    GXSetTevOrder(1, 1, 1, 0xFF);
    GXSetTevSwapModeTable(1, 2, 0, 0, 1);
    GXSetTevSwapMode(1, 0, 1);
    GXSetTevColorIn(0, 15, 15, 15, 8);
    GXSetTevColorOp(0, 0, 0, 0, 1, 0);
    GXSetTevColorIn(1, 8, 15, 15, 0);
    GXSetTevColorOp(1, 0, 0, 0, 1, 0);
    GXSetTevAlphaIn(0, 7, 7, 7, 7);
    GXSetTevAlphaOp(0, 0, 0, 0, 1, 0);
    GXSetTevAlphaIn(1, 4, 7, 7, 0);
    GXSetTevAlphaOp(1, 0, 0, 0, 1, 0);
}

void fn_8029A41C(s32 hasAlpha) {
    GXSetTevOrder(0, 0xFF, 0xFF, 4);
    GXSetNumTevStages(1);
    GXSetTevColorIn(0, 10, 15, 15, 15);
    GXSetTevColorOp(0, 0, 0, 0, 1, 0);
    if (hasAlpha != 0) {
        GXSetTevAlphaIn(0, 5, 7, 7, 7);
    } else {
        GXSetTevAlphaIn(0, 6, 7, 7, 7);
    }
    GXSetTevAlphaOp(0, 0, 0, 0, 1, 0);
}

void fn_8029A4EC(s32 hasAlpha) {
    if (lbl_803457A8.mode == 1) {
        hasAlpha = 0;
    }
    GXSetNumTevStages(2);
    GXSetTevOrder(0, 0, 0, 4);
    GXSetTevOrder(1, 0xFF, 0xFF, 5);
    GXSetTevColorIn(0, 15, 8, 10, 15);
    GXSetTevColorOp(0, 0, 0, 0, 1, 0);
    GXSetTevColorIn(1, 10, 15, 15, 0);
    GXSetTevColorOp(1, 0, 0, 0, 1, 0);
    if (hasAlpha != 0) {
        GXSetTevAlphaIn(0, 7, 4, 5, 7);
        GXSetZCompLoc(lbl_80347F50);
        GXSetAlphaCompare(lbl_80346A38, lbl_80347F54, lbl_80347F58, lbl_80346A3C, lbl_80347F5C);
    } else {
        GXSetTevAlphaIn(0, 6, 7, 7, 7);
        GXSetZCompLoc(lbl_80346A40);
        GXSetAlphaCompare(lbl_80346A44, lbl_80347F5D, lbl_80347F60, lbl_80346A48, lbl_80347F64);
    }
    GXSetTevAlphaOp(0, 0, 0, 0, 1, 0);
    GXSetTevAlphaIn(1, 7, 7, 7, 0);
    GXSetTevAlphaOp(1, 0, 0, 0, 1, 0);
}

void fn_8029A698(s32 hasAlpha, s32 mode) {
    if (lbl_803457A8.mode == 1) {
        hasAlpha = 0;
    }
    GXSetNumTexGens(3);
    if (mode == 0) {
        GXSetTexCoordGen2(0, 1, 5, 0x3C, 0, 0x7D);
        GXSetTexCoordGen2(1, 1, 6, 0x3C, 0, 0x7D);
        GXSetTexCoordGen2(2, 1, 4, 0x3C, 0, 0x7D);
    } else {
        GXSetTexCoordGen2(0, 1, 4, 0x3C, 0, 0x7D);
        GXSetTexCoordGen2(1, 1, 5, 0x3C, 0, 0x7D);
        GXSetTexCoordGen2(2, 0, 1, 0x1E, 0, 0x7D);
    }
    GXSetNumTevStages(4);
    GXSetTevOrder(0, 0, 1, 0xFF);
    GXSetTevOrder(1, 1, 1, 0xFF);
    GXSetTevOrder(2, 0xFF, 0xFF, 4);
    GXSetTevOrder(3, 2, 0, 0xFF);
    GXSetTevSwapModeTable(1, 2, 0, 0, 1);
    GXSetTevSwapMode(1, 0, 1);
    GXSetTevColorIn(0, 15, 15, 15, 8);
    GXSetTevColorOp(0, 0, 0, 0, 1, 0);
    GXSetTevColorIn(1, 8, 15, 15, 0);
    GXSetTevColorOp(1, 0, 0, 0, 1, 0);
    GXSetTevColorIn(2, 15, 10, 0, 15);
    GXSetTevColorOp(2, 0, 0, 1, 1, 0);
    GXSetTevColorIn(3, 15, 8, 0, 15);
    GXSetTevColorOp(3, 0, 0, 0, 1, 0);
    if (hasAlpha != 0) {
        GXSetZCompLoc(lbl_80347F50);
        GXSetAlphaCompare(lbl_80346A38, lbl_80347F54, lbl_80347F58, lbl_80346A3C, lbl_80347F5C);
    } else {
        GXSetZCompLoc(lbl_80346A40);
        GXSetAlphaCompare(lbl_80346A44, lbl_80347F5D, lbl_80347F60, lbl_80346A48, lbl_80347F64);
    }
    GXSetTevAlphaIn(0, 7, 7, 7, 7);
    GXSetTevAlphaOp(0, 0, 0, 0, 1, 0);
    GXSetTevAlphaIn(1, 4, 7, 7, 0);
    GXSetTevAlphaOp(1, 0, 0, 0, 1, 0);
    GXSetTevAlphaIn(2, 7, 7, 7, 0);
    GXSetTevAlphaOp(2, 0, 0, 0, 1, 0);
    GXSetTevAlphaIn(3, 7, 4, 0, 7);
    GXSetTevAlphaOp(3, 0, 0, 0, 1, 0);
}

void fn_8029AA14(s32 hasAlpha) {
    if (lbl_803457A8.mode == 1) {
        hasAlpha = 0;
    }
    GXSetNumTevStages(1);
    GXSetTevOrder(0, 0, 0, 4);
    GXSetTevColorIn(0, 15, 8, 10, 15);
    GXSetTevColorOp(0, 0, 0, 1, 1, 0);
    if (hasAlpha != 0) {
        GXSetTevAlphaIn(0, 7, 4, 5, 7);
        GXSetZCompLoc(lbl_80347F50);
        GXSetAlphaCompare(lbl_80346A38, lbl_80347F54, lbl_80347F58, lbl_80346A3C, lbl_80347F5C);
    } else {
        GXSetTevAlphaIn(0, 6, 7, 7, 7);
        GXSetZCompLoc(lbl_80346A40);
        GXSetAlphaCompare(lbl_80346A44, lbl_80347F5D, lbl_80347F60, lbl_80346A48, lbl_80347F64);
    }
    GXSetTevAlphaOp(0, 0, 0, 0, 1, 0);
}

void fn_8029AB44(s32 hasAlpha, s32 mode) {
    if (lbl_803457A8.mode == 1) {
        hasAlpha = 0;
    }
    if (mode == 0) {
        GXSetTexCoordGen2(0, 1, 5, 0x3C, 0, 0x7D);
        GXSetTexCoordGen2(1, 1, 6, 0x3C, 0, 0x7D);
        GXSetTexCoordGen2(2, 1, 4, 0x3C, 0, 0x7D);
    } else {
        GXSetTexCoordGen2(0, 1, 4, 0x3C, 0, 0x7D);
        GXSetTexCoordGen2(1, 1, 5, 0x3C, 0, 0x7D);
        GXSetTexCoordGen2(2, 0, 1, 0x1E, 0, 0x7D);
    }
    GXSetNumTexGens(3);
    GXSetNumTevStages(3);
    GXSetTevOrder(0, 0, 1, 0xFF);
    GXSetTevOrder(1, 1, 1, 0xFF);
    GXSetTevOrder(2, 2, 0, 0xFF);
    GXSetTevSwapModeTable(1, 2, 0, 0, 1);
    GXSetTevSwapMode(1, 0, 1);
    GXSetTevColorIn(0, 15, 15, 15, 8);
    GXSetTevColorOp(0, 0, 0, 0, 1, 0);
    GXSetTevColorIn(1, 8, 15, 15, 0);
    GXSetTevColorOp(1, 0, 0, 0, 1, 0);
    GXSetTevColorIn(2, 15, 8, 0, 15);
    GXSetTevColorOp(2, 0, 0, 0, 1, 0);
    if (hasAlpha != 0) {
        GXSetZCompLoc(lbl_80347F50);
        GXSetAlphaCompare(lbl_80346A38, lbl_80347F54, lbl_80347F58, lbl_80346A3C, lbl_80347F5C);
    } else {
        GXSetZCompLoc(lbl_80346A40);
        GXSetAlphaCompare(lbl_80346A44, lbl_80347F5D, lbl_80347F60, lbl_80346A48, lbl_80347F64);
    }
    GXSetTevAlphaIn(0, 7, 7, 7, 7);
    GXSetTevAlphaOp(0, 0, 0, 0, 1, 0);
    GXSetTevAlphaIn(1, 4, 7, 7, 0);
    GXSetTevAlphaOp(1, 0, 0, 0, 1, 0);
    GXSetTevAlphaIn(2, 7, 4, 0, 7);
    GXSetTevAlphaOp(2, 0, 0, 0, 1, 0);
}

void fn_8029AE38(s32 hasAlpha) {
    if (lbl_803457A8.mode == 1) {
        hasAlpha = 0;
    }
    GXSetNumTevStages(1);
    GXSetTevOrder(0, 0, 0, 4);
    GXSetTevColorIn(0, 15, 8, 10, 15);
    GXSetTevColorOp(0, 0, 0, 0, 1, 0);
    if (hasAlpha != 0) {
        GXSetTevAlphaIn(0, 7, 4, 5, 7);
        GXSetZCompLoc(lbl_80347F50);
        GXSetAlphaCompare(lbl_80346A38, lbl_80347F54, lbl_80347F58, lbl_80346A3C, lbl_80347F5C);
    } else {
        GXSetTevAlphaIn(0, 6, 7, 7, 7);
        GXSetZCompLoc(lbl_80346A40);
        GXSetAlphaCompare(lbl_80346A44, lbl_80347F5D, lbl_80347F60, lbl_80346A48, lbl_80347F64);
    }
    GXSetTevAlphaOp(0, 0, 0, 0, 1, 0);
}

void fn_8029AF68(GXAttrType t) {
    GXClearVtxDesc();
    GXSetVtxDesc(GX_VA_POS, t);
}

void fn_8029AFA0(GXAttrType p, GXAttrType c) {
    GXClearVtxDesc();
    GXSetVtxDesc(GX_VA_POS, p);
    GXSetVtxDesc(GX_VA_CLR0, c);
}

void fn_8029AFF0(GXAttrType p, GXAttrType n, GXAttrType c) {
    GXClearVtxDesc();
    GXSetVtxDesc(GX_VA_POS, p);
    GXSetVtxDesc(GX_VA_NRM, n);
    GXSetVtxDesc(GX_VA_CLR0, c);
}

void fn_8029B058(GXAttrType p, GXAttrType n) {
    GXClearVtxDesc();
    GXSetVtxDesc(GX_VA_POS, p);
    GXSetVtxDesc(GX_VA_NRM, n);
}

void fn_8029B0A8(GXAttrType p, GXAttrType c, GXAttrType t) {
    GXClearVtxDesc();
    GXSetVtxDesc(GX_VA_POS, p);
    GXSetVtxDesc(GX_VA_CLR0, c);
    GXSetVtxDesc(GX_VA_TEX0, t);
}

void fn_8029B110(GXAttrType p, GXAttrType t) {
    GXClearVtxDesc();
    GXSetVtxDesc(GX_VA_POS, p);
    GXSetVtxDesc(GX_VA_TEX0, t);
}

void fn_8029B160(GXAttrType p, GXAttrType n, GXAttrType c, GXAttrType t) {
    GXClearVtxDesc();
    GXSetVtxDesc(GX_VA_POS, p);
    GXSetVtxDesc(GX_VA_NRM, n);
    GXSetVtxDesc(GX_VA_CLR0, c);
    GXSetVtxDesc(GX_VA_TEX0, t);
}

void fn_8029B1E0(GXAttrType p, GXAttrType n, GXAttrType t) {
    GXClearVtxDesc();
    GXSetVtxDesc(GX_VA_POS, p);
    GXSetVtxDesc(GX_VA_NRM, n);
    GXSetVtxDesc(GX_VA_TEX0, t);
}

static inline void alpha_test(s32 hasAlpha) {
    if (hasAlpha != 0) {
        GXSetTevAlphaIn(0, 7, 4, 5, 7);
        GXSetZCompLoc(lbl_80347F50);
        GXSetAlphaCompare(lbl_80346A38, lbl_80347F54, lbl_80347F58, lbl_80346A3C, lbl_80347F5C);
    } else {
        GXSetTevAlphaIn(0, 6, 7, 7, 7);
        GXSetZCompLoc(lbl_80346A40);
        GXSetAlphaCompare(lbl_80346A44, lbl_80347F5D, lbl_80347F60, lbl_80346A48, lbl_80347F64);
    }
}

static inline void tev_tex(s32 hasAlpha) {
    if (lbl_803457A8.mode == 1) {
        hasAlpha = 0;
    }
    GXSetNumTevStages(1);
    GXSetTevOrder(0, 0, 0, 4);
    GXSetTevColorIn(0, 15, 8, 10, 15);
    GXSetTevColorOp(0, 0, 0, 0, 1, 0);
    alpha_test(hasAlpha);
    GXSetTevAlphaOp(0, 0, 0, 0, 1, 0);
}

static inline void tev_tex_spec(s32 hasAlpha) {
    if (lbl_803457A8.mode == 1) {
        hasAlpha = 0;
    }
    GXSetNumTevStages(2);
    GXSetTevOrder(0, 0, 0, 4);
    GXSetTevOrder(1, 0xFF, 0xFF, 5);
    GXSetTevColorIn(0, 15, 8, 10, 15);
    GXSetTevColorOp(0, 0, 0, 0, 1, 0);
    GXSetTevColorIn(1, 10, 15, 15, 0);
    GXSetTevColorOp(1, 0, 0, 0, 1, 0);
    alpha_test(hasAlpha);
    GXSetTevAlphaOp(0, 0, 0, 0, 1, 0);
    GXSetTevAlphaIn(1, 7, 7, 7, 0);
    GXSetTevAlphaOp(1, 0, 0, 0, 1, 0);
}

static inline void tev_color(s32 hasAlpha) {
    GXSetTevOrder(0, 0xFF, 0xFF, 4);
    GXSetNumTevStages(1);
    GXSetTevColorIn(0, 10, 15, 15, 15);
    GXSetTevColorOp(0, 0, 0, 0, 1, 0);
    if (hasAlpha != 0) {
        GXSetTevAlphaIn(0, 5, 7, 7, 7);
    } else {
        GXSetTevAlphaIn(0, 6, 7, 7, 7);
    }
    GXSetTevAlphaOp(0, 0, 0, 0, 1, 0);
}

/* The material setup is done the same way whether or not the kind changed; the compiler won't
 * inline a helper this size, so it is a macro. */
#define MATERIAL_SETUP(kind, flag)                                                                  \
    switch (kind) {                                                                                 \
    case 0:                                                                                         \
        GXSetTexCoordGen2(0, 1, 4, 0x3C, 0, 0x7D);                                                  \
        GXClearVtxDesc();                                                                           \
        GXSetVtxDesc(GX_VA_POS, 1);                                                                 \
        GXSetVtxDesc(GX_VA_CLR0, 1);                                                                \
        GXSetVtxDesc(GX_VA_TEX0, 1);                                                                \
        GXSetVtxAttrFmt(0, 9, 1, 4, 0);                                                             \
        GXSetVtxAttrFmt(0, 11, 1, 5, 0);                                                            \
        GXSetVtxAttrFmt(0, 13, 1, 4, 0);                                                            \
        GXSetNumChans(1);                                                                           \
        GXSetChanCtrl(4, 0, 1, 1, 0, 0, 2);                                                         \
        GXSetNumTexGens(1);                                                                         \
        tev_tex(flag);                                                                              \
        break;                                                                                      \
    case 1:                                                                                         \
        GXSetTexCoordGen2(0, 1, 4, 0x3C, 0, 0x7D);                                                  \
        GXClearVtxDesc();                                                                           \
        GXSetVtxDesc(GX_VA_POS, 1);                                                                 \
        GXSetVtxDesc(GX_VA_CLR0, 1);                                                                \
        GXSetVtxDesc(GX_VA_CLR1, 1);                                                                \
        GXSetVtxDesc(GX_VA_TEX0, 1);                                                                \
        GXSetVtxAttrFmt(0, 9, 1, 4, 0);                                                             \
        GXSetVtxAttrFmt(0, 11, 1, 5, 0);                                                            \
        GXSetVtxAttrFmt(0, 12, 1, 5, 0);                                                            \
        GXSetVtxAttrFmt(0, 13, 1, 4, 0);                                                            \
        GXSetNumChans(2);                                                                           \
        GXSetChanCtrl(4, 0, 1, 1, 0, 0, 2);                                                         \
        GXSetChanCtrl(5, 0, 1, 1, 0, 0, 2);                                                         \
        GXSetNumTexGens(1);                                                                         \
        tev_tex_spec(flag);                                                                         \
        break;                                                                                      \
    case 2:                                                                                         \
        GXSetTexCoordGen2(0, 1, 4, 0x3C, 0, 0x7D);                                                  \
        GXClearVtxDesc();                                                                           \
        GXSetVtxDesc(GX_VA_POS, 1);                                                                 \
        GXSetVtxDesc(GX_VA_TEX0, 1);                                                                \
        GXSetVtxAttrFmt(0, 9, 1, 4, 0);                                                             \
        GXSetVtxAttrFmt(0, 11, 1, 5, 0);                                                            \
        GXSetVtxAttrFmt(0, 13, 1, 4, 0);                                                            \
        GXSetNumChans(1);                                                                           \
        GXSetChanCtrl(4, 0, 1, 0, 0, 0, 2);                                                         \
        GXSetNumTexGens(1);                                                                         \
        tev_tex(flag);                                                                              \
        break;                                                                                      \
    case 3:                                                                                         \
        GXSetTexCoordGen2(0, 1, 4, 0x3C, 0, 0x7D);                                                  \
        GXClearVtxDesc();                                                                           \
        GXSetVtxDesc(GX_VA_POS, 1);                                                                 \
        GXSetVtxDesc(GX_VA_TEX0, 1);                                                                \
        GXSetVtxAttrFmt(0, 9, 1, 4, 0);                                                             \
        GXSetVtxAttrFmt(0, 11, 1, 5, 0);                                                            \
        GXSetVtxAttrFmt(0, 12, 1, 5, 0);                                                            \
        GXSetVtxAttrFmt(0, 13, 1, 4, 0);                                                            \
        GXSetNumChans(2);                                                                           \
        GXSetChanCtrl(4, 0, 1, 0, 0, 0, 2);                                                         \
        GXSetChanCtrl(5, 0, 0, 1, 0, 0, 2);                                                         \
        GXSetNumTexGens(1);                                                                         \
        tev_tex_spec(flag);                                                                         \
        break;                                                                                      \
    case 4:                                                                                         \
        GXClearVtxDesc();                                                                           \
        GXSetVtxDesc(GX_VA_POS, 1);                                                                 \
        GXSetVtxDesc(GX_VA_CLR0, 1);                                                                \
        GXSetVtxAttrFmt(0, 9, 1, 4, 0);                                                             \
        GXSetVtxAttrFmt(0, 11, 1, 5, 0);                                                            \
        GXSetNumChans(1);                                                                           \
        GXSetChanCtrl(4, 0, 1, 1, 0, 0, 2);                                                         \
        GXSetNumTexGens(0);                                                                         \
        tev_color(flag);                                                                            \
        break;                                                                                      \
    case 5:                                                                                         \
        GXClearVtxDesc();                                                                           \
        GXSetVtxDesc(GX_VA_POS, 1);                                                                 \
        GXSetVtxAttrFmt(0, 9, 1, 4, 0);                                                             \
        GXSetVtxAttrFmt(0, 11, 1, 5, 0);                                                            \
        GXSetNumChans(1);                                                                           \
        GXSetChanCtrl(4, 0, 1, 0, 0, 0, 2);                                                         \
        GXSetNumTexGens(0);                                                                         \
        tev_color(flag);                                                                            \
        break;                                                                                      \
    }

void fn_8029B248(s32 kind, s32 flag) {
    if (lbl_80347F74 != kind) {
        MATERIAL_SETUP(kind, flag);
        lbl_80347F74 = kind;
        lbl_80347F68 = flag;
    } else {
        MATERIAL_SETUP(kind, flag);
        lbl_80347F68 = flag;
    }
}

void fn_8029C8A0(void) {
    fn_8029B248(7, 1);
    if (lbl_80347F6C != 1) {
        GXSetProjection(lbl_80346400, 0);
        lbl_80347F6C = 1;
    }
    if (lbl_80347F70 != 4) {
        GXLoadPosMtxImm(lbl_803007C8, 3);
        GXLoadNrmMtxImm(lbl_803007C8, 3);
        GXLoadTexMtxImm(lbl_803464A0, 30, 0);
        GXSetCurrentMtx(3);
        lbl_80347F70 = 4;
    }
}

void fn_8029C93C(void) {
    if (lbl_80347F6C != 1) {
        GXSetProjection(lbl_80346400, 0);
        lbl_80347F6C = 1;
    }
    if (lbl_80347F70 != 3) {
        GXLoadPosMtxImm(lbl_803007C8, 6);
        GXSetCurrentMtx(6);
        GXSetCullMode(0);
        lbl_80347F70 = 3;
    }
}

void fn_8029C9B0(s32 kind) {
    f32 m[3][4];
    f32 o[4][4];
    f32 w, h;
    switch (kind) {
    case 0:
        break;
    case 1:
        PSMTXCopy(lbl_80347EB4, m[0]);
        w = 0.5f * lbl_80345878[10];
        h = 0.5f * lbl_80345878[11];
        C_MTXOrtho(o, h, -h, -w, w, lbl_80345850[1], lbl_80345850[0]);
        PSMTXConcat(o[0], m[0], m[0]);
        PSMTXConcat(lbl_80346440[0], m[0], m[0]);
        GXLoadTexMtxImm(m, 30, 1);
        break;
    }
}

void fn_8029CB74(void) {
    GXSetProjection(lbl_803463C0, 1);
    lbl_80347F6C = 0;
    GXLoadPosMtxImm(lbl_803464D0, 0);
    GXSetCurrentMtx(0);
    GXSetCullMode(0);
    lbl_80347F70 = 0;
}

void fn_8029CBD0(void) {
    lbl_80347F74 = -1;
    lbl_80347F70 = -1;
    lbl_80347F68 = -1;
    GXSetVtxAttrFmt(0, 9, 1, 4, 0);
    GXSetVtxAttrFmt(0, 10, 0, 4, 0);
    GXSetVtxAttrFmt(0, 11, 1, 5, 0);
    GXSetVtxAttrFmt(0, 12, 1, 5, 0);
    GXSetVtxAttrFmt(0, 13, 1, 4, 0);
    GXSetVtxAttrFmt(0, 14, 1, 4, 0);
    GXSetVtxAttrFmt(2, 9, 1, 4, 0);
    GXSetVtxAttrFmt(2, 10, 0, 4, 0);
    GXSetVtxAttrFmt(2, 11, 1, 5, 0);
    GXSetVtxAttrFmt(2, 12, 1, 5, 0);
    GXSetVtxAttrFmt(2, 13, 1, 3, 8);
    GXSetVtxAttrFmt(3, 9, 1, 4, 0);
    GXSetVtxAttrFmt(3, 10, 0, 4, 0);
    GXSetVtxAttrFmt(3, 11, 1, 5, 0);
    GXSetVtxAttrFmt(3, 12, 1, 5, 0);
    GXSetVtxAttrFmt(3, 13, 1, 3, 10);
    GXSetVtxAttrFmt(4, 9, 1, 4, 0);
    GXSetVtxAttrFmt(4, 10, 0, 4, 0);
    GXSetVtxAttrFmt(4, 13, 1, 3, 8);
    GXSetVtxAttrFmt(4, 14, 1, 3, 8);
    GXSetVtxAttrFmt(4, 15, 1, 3, 8);
    GXSetVtxAttrFmt(5, 9, 1, 4, 0);
    GXSetVtxAttrFmt(5, 10, 0, 4, 0);
    GXSetVtxAttrFmt(5, 13, 1, 3, 10);
    GXSetVtxAttrFmt(5, 14, 1, 3, 8);
    GXSetVtxAttrFmt(5, 15, 1, 3, 8);
}

void fn_8029CE6C(s32 a, u8 b, s32 c, s32 d, u8 e, s32 flag) {
    if (flag != 0) {
        lbl_80346A38 = a;
        lbl_80347F54 = b;
        lbl_80347F58 = c;
        lbl_80346A3C = d;
        lbl_80347F5C = e;
    } else {
        lbl_80346A44 = a;
        lbl_80347F5D = b;
        lbl_80347F60 = c;
        lbl_80346A48 = d;
        lbl_80347F64 = e;
    }
}

void fn_8029CEA4(s32 v, s32 flag) {
    if (flag != 0) {
        lbl_80347F50 = v;
    }
    if (flag == 0) {
        lbl_80346A40 = v;
    }
}

void fn_8029CEC0(f32* m, const f32* n) {
    f32* p;
    if (m == 0) { lbl_80347F70 = 5; p = lbl_80347EB4; } else { p = m; }
    PSMTXConcat(n, p, p);
}

void fn_8029CF04(void) {
    u16 saveA = lbl_803457A8.h1e;
    u16 saveB = lbl_803457A8.h20;
    lbl_803457A8.h1e = 2;
    lbl_803457A8.h20 = 2;
    fn_8029976C(&lbl_80346500, 1);
    lbl_803457A8.h1e = saveA;
    lbl_803457A8.h20 = saveB;
    lbl_803457A8.w48 = -1;
}

void fn_8029CF7C(void* p) {
    if (p == 0) {
        fn_802976F8(&lbl_80346500, 0x80, 0x80, 0xe);
        lbl_80346500.data = lbl_80300A00;
    } else {
        fn_802976F8(&lbl_80346500);
        lbl_80346500.data = p;
    }
}

s32 fn_8029CFF0(void) { return lbl_80347F7C; }

void fn_8029CFF8(s32 v) { lbl_80347F7C = v; }

void fn_8029D000(s32 v) { lbl_80347F78 = v; }

void fn_8029D008(s32 v) { lbl_80347EE0 = v; }

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

void fn_8029D010(u32 mode) {
    set_blend(mode);
}

void fn_8029D698(u32 attr, s16* p, u8* c0, u8* c1, u8* c2) {
    u8 kind = attr;
    s32 flags = kind - 0x10;
    NJS_ARGB tmp;
    s16 a, b;

    if (flags & 1) {
        a = p[0];
        b = p[1];
        p += 2;
        if (_nj_control_3d_flag_ & 0x10) {
            fn_8029EE28(&_nj_constant_material_, c0);
        } else if (c0 != 0) {
            c0[3] = b;
            c0[0] = (b >> 8) & 0xFF;
            c0[1] = a;
            c0[2] = (a >> 8) & 0xFF;
            if (_nj_control_3d_flag_ & 0x20) {
                fn_8029EE50(c0, &tmp);
                tmp.a += _nj_constant_material_.a;
                tmp.r += _nj_constant_material_.r;
                tmp.g += _nj_constant_material_.g;
                tmp.b += _nj_constant_material_.b;
                fn_8029EE28(&tmp, c0);
            }
        }
    }
    if (flags & 2) {
        a = p[0];
        b = p[1];
        p += 2;
        if (c1 != 0) {
            c1[3] = b;
            c1[0] = (b >> 8) & 0xFF;
            c1[1] = a;
            c1[2] = (a >> 8) & 0xFF;
        }
    }
    if (flags & 4) {
        a = p[0];
        b = p[1];
        p += 2;
        if (c2 != 0) {
            c2[3] = b;
            c2[0] = (b >> 8) & 0xFF;
            c2[1] = a;
            c2[2] = (a >> 8) & 0xFF;
        }
    }
    set_blend(attr);
}

void fn_8029D8B0(NjLightTbl* lt, s16 kind, s32 n, s32 enable) {
    u8 type = n;
    GXSetNumChans(1);
    switch (type) {
    case 0x22:
    case 0x24:
    case 0x29:
    case 0x2B:
        GXSetChanCtrl(0, enable, 0, 0, lt->chan[0].mask, lt->chan[0].diff_fn, lt->chan[0].attn_fn);
        GXSetChanCtrl(2, 0, 0, 0, lt->chan[1].mask, lt->chan[1].diff_fn, lt->chan[1].attn_fn);
        GXSetChanCtrl(1, 0, 0, 0, 0, 0, 2);
        GXSetChanCtrl(3, 0, 0, 0, 0, 0, 2);
        break;
    case 0x23:
    case 0x2A:
        GXSetChanCtrl(0, enable, 0, 1, lt->chan[0].mask, lt->chan[0].diff_fn, lt->chan[0].attn_fn);
        GXSetChanCtrl(2, 0, 0, 1, lt->chan[1].mask, lt->chan[1].diff_fn, lt->chan[1].attn_fn);
        GXSetChanCtrl(1, 0, 0, 0, 0, 0, 2);
        GXSetChanCtrl(3, 0, 0, 0, 0, 0, 2);
        break;
    }
}

void fn_8029DA24(s16 kind, s32 type, s32 mode) {
    s32 enable;
    s32 twoSided;
    s32 mask;

    switch (mode) {
    case 0:
        enable = 0;
        twoSided = 0;
        mask = 0;
        GXSetNumChans(1);
        break;
    case 1:
        enable = 1;
        twoSided = 1;
        mask = 1;
        GXSetNumChans(2);
        break;
    case 2:
        enable = 1;
        twoSided = 0;
        mask = 1;
        GXSetNumChans(1);
        break;
    }
    switch ((u8)type) {
    case 0x29:
    case 0x2B:
        GXSetChanCtrl(0, enable, 0, 0, mask, 2, 2);
        GXSetChanCtrl(2, 0, 0, 0, mask, 2, 0);
        if (twoSided != 0) {
            GXSetChanCtrl(1, enable, 0, 0, mask, 2, 0);
            GXSetChanCtrl(3, 0, 0, 0, mask, 2, 0);
        }
        break;
    case 0x22:
    case 0x24:
        GXSetChanCtrl(0, enable, 0, 0, mask, 0, 2);
        GXSetChanCtrl(2, 0, 0, 0, mask, 0, 0);
        if (twoSided != 0) {
            GXSetChanCtrl(1, enable, 0, 0, mask, 0, 2);
            GXSetChanCtrl(3, 0, 0, 0, mask, 0, 2);
        } else {
            GXSetChanCtrl(1, 0, 0, 0, 0, 0, 2);
            GXSetChanCtrl(3, 0, 0, 0, 0, 0, 2);
        }
        break;
    case 0x23:
    case 0x2A:
        GXSetChanCtrl(0, 0, 0, 1, mask, 2, 2);
        GXSetChanCtrl(2, 0, 0, 1, mask, 2, 2);
        GXSetChanCtrl(1, 0, 0, 0, 0, 0, 2);
        GXSetChanCtrl(3, 0, 0, 0, mask, 0, 2);
        break;
    }
}

void fn_802A1374(s16* p, s32 n, u32* data) {
    u8 dif[4] = {0xff, 0xff, 0xff, 0xff};
    u16 size;
    s16 cnt;
    s16 fl;
    s16 len;
    u8 type = n;
    s16 kind;
    s32 alpha;
    s32 mode;
    s16 c;
    u8 spc[4] = {0, 0, 0, 0};
    s32 tex;

    while ((c = *p++) != 0xff) {
        kind = c & 0xff;
        if (kind < 8) {
            switch (kind) {
            case 1:
                fn_8029D010(c);
                break;
            case 4:
                lbl_803458A8[(s16)((c >> 8) & 0xff)] = p;
                lbl_80347F24++;
                return;
            case 5:
                fn_802A1374(lbl_803458A8[(s16)((c >> 8) & 0xff)], n, data);
                lbl_80347F24--;
                break;
            }
        } else if (kind < 0x10) {
            fn_8029D0F4(c, *p++);
            if (*p & 0x18) {
                p += 8;
            }
        } else if (kind < 0x40) {
            len = *p++;
            fn_8029D698(c, p, dif, 0, spc);
            p += len;
        } else {
            cnt = p[1];
            size = *(u16*)p;  /* the chunk stream is s16; this field is unsigned */
            p += 2;
            if (_nj_control_3d_flag_ & 0x800) {
                c &= _nj_constant_attr_and_;
                c |= _nj_constant_attr_or_;
            }
            fl = (c >> 8) & 0x2a;
            lbl_80347EA0 = fl & 0x20;
            if (fl & 2) {
                mode = 2;
                tex = 0;
            } else {
                mode = 1;
                tex = 1;
            }
            if (fl & 8) {
                alpha = 1;
                if (lbl_80347E20 == 1) {
                    p += size - 1;
                    continue;
                }
            } else {
                alpha = 0;
                switch (lbl_80347E20) {
                case 2:
                case 3:
                case 4:
                    p += size - 1;
                    continue;
                }
            }
            fn_802A8F40(1);
            switch (kind) {
            case 0x41:
            case 0x42:
                GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX2x4, GX_TG_TEX0, 0x3c, 0, 0x7d);
                GXSetNumTexGens(1);
                switch (type) {
                case 0x29:
                    fn_8029DA24(kind, n, mode);
                    if (tex) {
                        fn_8029A4EC(alpha);
                    } else {
                        fn_8029AE38(alpha);
                    }
                    fn_802A1B54(0x1002, 0, 0, spc, dif);
                    fn_8029DCD0(p, data, cnt, 1, kind);
                    break;
                case 0x2b:
                    fn_8029DA24(kind, n, mode);
                    if (tex) {
                        fn_8029A4EC(alpha);
                    } else {
                        fn_8029AE38(alpha);
                    }
                    fn_802A1B54(0x1002, 0, 0, spc, dif);
                    fn_8029EC1C(p, data, cnt, 1, kind);
                    break;
                case 0x2a:
                    if (fn_8029CFF0()) {
                        fn_8029DA24(kind, 0x29, 0);
                        fn_8029CF04();
                        fn_8029AB44(alpha, 0);
                        fn_8029DEDC(p, data, cnt, 1, kind);
                    } else {
                        fn_8029DA24(kind, n, mode);
                        fn_8029AE38(alpha);
                        fn_8029E1B4(p, data, cnt, 1, kind);
                    }
                    break;
                case 0x22:
                    fn_8029DA24(kind, n, 0);
                    fn_802A1B54(0x3412, 0, 0, spc, dif);
                    fn_8029AE38(alpha);
                    fn_8029E40C(p, data, cnt, 1, kind);
                    break;
                case 0x24:
                    fn_8029DA24(kind, n, mode);
                    fn_8029AE38(alpha);
                    fn_802A1B54(0x3412, 0, 0, spc, dif);
                    fn_8029EA5C(p, data, cnt, 1, kind);
                    break;
                case 0x23:
                    if (fn_8029CFF0()) {
                        fn_8029DA24(kind, 0x29, 0);
                        fn_8029CF04();
                        fn_8029AB44(alpha, 0);
                        fn_8029E5CC(p, data, cnt, 1, kind);
                    } else {
                        fn_8029DA24(kind, n, mode);
                        fn_8029AE38(alpha);
                        fn_8029E850(p, data, cnt, 1, kind);
                    }
                    break;
                }
                break;
            case 0x40:
                GXSetNumTexGens(0);
                if (mode) {
                    mode = 2;
                }
                switch (type) {
                case 0x29:
                    fn_8029DA24(kind, n, mode);
                    fn_8029A41C(alpha);
                    fn_802A1B54(0x3001, 0, 0, 0, dif);
                    fn_8029EE78(p, data, cnt, 1);
                    break;
                case 0x2a:
                    if (fn_8029CFF0()) {
                        fn_8029DA24(kind, 0x29, 0);
                        fn_8029CF04();
                        fn_8029A298(alpha);
                        fn_8029F680(p, data, cnt, 1);
                    } else {
                        fn_8029DA24(kind, n, mode);
                        fn_8029A41C(alpha);
                        fn_8029F86C(p, data, cnt, 1);
                    }
                    break;
                case 0x2b:
                    fn_8029DA24(kind, n, mode);
                    fn_8029A41C(alpha);
                    fn_802A1B54(0x3001, 0, 0, 0, dif);
                    fn_8029F528(p, data, cnt, 1);
                    break;
                case 0x22:
                    fn_8029DA24(kind, n, mode);
                    fn_8029A41C(alpha);
                    fn_802A1B54(0x3003, 0, 0, 0, dif);
                    fn_8029F400(p, data, cnt, 1);
                    break;
                case 0x24:
                    fn_8029DA24(kind, n, mode);
                    fn_8029A41C(alpha);
                    fn_802A1B54(0x3003, 0, 0, 0, dif);
                    fn_8029EFD0(p, data, cnt, 1);
                    break;
                case 0x23:
                    if (fn_8029CFF0()) {
                        fn_8029DA24(kind, 0x29, 0);
                        fn_8029CF04();
                        fn_8029A298(alpha);
                        fn_8029F0F8(p, data, cnt, 1);
                    } else {
                        fn_8029DA24(kind, n, mode);
                        fn_8029A41C(alpha);
                        fn_8029F2A8(p, data, cnt, 1);
                    }
                    break;
                }
                break;
            }
            p += size - 1;
        }
    }
}

void fn_802A20DC(f32 a, f32 b, f32 c) {
    lbl_80300760.f18[0] = a;
    lbl_80300760.f18[1] = b;
    lbl_80300760.f18[2] = c;
}

void fn_802A20F4(f32 a, f32 b) {
    lbl_80300760.f0c = -a;
    lbl_80300760.f10 = b;
}

void fn_802A210C(f32 x, f32 y, f32 z) {
    f64 dx = x, dy = y, dz = z;
    lbl_80300760.dir[0] = x;
    lbl_80300760.dir[1] = y;
    lbl_80300760.dir[2] = z;
    GXInitLightPos(&lbl_80346560, 1048576.0f * -(f32)dx, 1048576.0f * -(f32)dy, 1048576.0f * -(f32)dz);
    GXInitSpecularDir(&lbl_80346520, x, y, z);
}

void fn_802A5EF8(s32 count, NJS_POINT3* dst, NJS_POINT3* src) {
    PSMTXMultVecArray(lbl_80347EB4, src, dst, count);
}

void fn_802A7598(f32 a, f32 b, f32 c) {
    lbl_80300794.f18[0] = a;
    lbl_80300794.f18[1] = b;
    lbl_80300794.f18[2] = c;
}

void fn_802A75B0(f32 a, f32 b) {
    lbl_80300794.f0c = -a;
    lbl_80300794.f10 = b;
}

void fn_802A75C8(f32 x, f32 y, f32 z) {
    f64 a = x, b = y, c = z;
    lbl_80300794.dir[0] = x;
    lbl_80300794.dir[1] = y;
    lbl_80300794.dir[2] = z;
    GXInitLightPos(&lbl_803465E0, 1048576.0f * -(f32)a, 1048576.0f * -(f32)b, 1048576.0f * -(f32)c);
    GXInitSpecularDir(&lbl_803465A0, x, y, z);
}

void fn_802A7894(s16* p, s32 n, u32* data) {
    u8 type = n;
    u8 dif[4] = {0xff, 0xff, 0xff, 0xff};
    u8 spc[4] = {0, 0, 0, 0};
    u8 amb[4] = {0, 0, 0, 0};
    s32 tex;
    u16 size;
    s16 cnt;
    s16 kind;
    s16 c;
    s16 len;
    s16 fl;
    s32 alpha;
    s32 enable;
    u32 ambf;

    while ((c = *p++) != 0xff) {
        kind = c & 0xff;
        if (kind < 8) {
            switch (kind) {
            case 1:
                fn_8029D010(c);
                break;
            case 4:
                lbl_803458A8[(s16)((c >> 8) & 0xff)] = p;
                lbl_80347F24++;
                return;
            case 5:
                fn_802A7894(lbl_803458A8[(s16)((c >> 8) & 0xff)], n, data);
                lbl_80347F24--;
                break;
            }
        } else if (kind < 0x10) {
            fn_8029D0F4(c, *p++);
            if (*p & 0x18) {
                p += 8;
            }
        } else if (kind < 0x40) {
            len = *p++;
            fn_8029D698(c, p, dif, amb, spc);
            p += len;
        } else {
            cnt = p[1];
            size = *(u16*)p;  /* the chunk stream is s16; this field is unsigned */
            p += 2;
            if (_nj_control_3d_flag_ & 0x800) {
                c &= _nj_constant_attr_and_;
                c |= _nj_constant_attr_or_;
            }
            fl = (c >> 8) & 0x2a;
            lbl_80347EA0 = fl & 0x20;
            tex = fl & 2;
            if (tex) {
                enable = 1;
            } else {
                enable = 1;
            }
            if (fl & 8) {
                alpha = 1;
                if (lbl_80347E20 == 1) {
                    p += size - 1;
                    continue;
                }
            } else {
                alpha = 0;
                switch (lbl_80347E20) {
                case 2:
                case 3:
                case 4:
                    p += size - 1;
                    continue;
                }
            }
            ambf = 0;
            if (fl & 4) {
                ambf = 0x300;
            }
            fn_802A8F40(1);
            fn_8029D8B0(&lbl_80344DE0, kind, n, enable);
            switch (kind) {
            case 0x41:
            case 0x42:
                GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX2x4, GX_TG_TEX0, 0x3c, 0, 0x7d);
                GXSetNumTexGens(1);
                switch (type) {
                case 0x29:
                    if (tex) {
                        fn_8029AA14(alpha);
                    } else {
                        fn_80299BD8(alpha);
                    }
                    fn_802A7D74(ambf | 2, 0, amb, 0, dif);
                    fn_8029DCD0(p, data, cnt, 1, kind);
                    break;
                case 0x2a:
                    if (fn_8029CFF0()) {
                        fn_802A7D74(ambf | 2, 0, amb, 0, dif);
                        fn_8029D8B0(&lbl_80344DE0, kind, 0x29, enable);
                        fn_8029CF04();
                        fn_8029A698(alpha, 0);
                        fn_8029DEDC(p, data, cnt, 1, kind);
                    } else {
                        fn_802A7D74(ambf | 4, 0, amb, 0, 0);
                        if (tex) {
                            fn_8029AA14(alpha);
                        } else {
                            fn_80299BD8(alpha);
                        }
                        fn_8029E1B4(p, data, cnt, 1, kind);
                    }
                    break;
                }
                break;
            case 0x40:
                switch (type) {
                case 0x29:
                    GXSetNumTexGens(0);
                    fn_8029A1C8(alpha);
                    fn_802A7D74(ambf | 1, 0, amb, 0, dif);
                    fn_8029EE78(p, data, cnt, 1);
                    break;
                case 0x2a:
                    if (fn_8029CFF0()) {
                        fn_802A7D74(ambf | 2, 0, amb, 0, dif);
                        fn_8029D8B0(&lbl_80344DE0, kind, 0x29, enable);
                        fn_8029CF04();
                        fn_80299FC8(alpha);
                        fn_8029F680(p, data, cnt, 1);
                    } else {
                        GXSetNumTexGens(0);
                        fn_8029A1C8(alpha);
                        fn_802A7D74(ambf | 4, 0, amb, 0, dif);
                        fn_8029F86C(p, data, cnt, 1);
                    }
                    break;
                }
                break;
            }
            p += size - 1;
        }
    }
}

void fn_802A7D74(u32 flags, s32 unused1, u8* amb, s32 unused2, u8* mat) {
    GXColor a;
    GXColor c;
    s32 i;
    u32 r, g, bl;
    NjLightTbl* t;

    switch (flags & 0xf) {
    case 1:
        c.a = mat[3];
        c.r = mat[0];
        c.g = mat[1];
        c.b = mat[2];
        GXSetChanMatColor(GX_COLOR0A0, c);
        break;
    case 2:
        c.a = mat[3];
        c.r = 0xff;
        c.g = 0xff;
        c.b = 0xff;
        GXSetChanMatColor(GX_COLOR0A0, c);
        break;
    case 4:
        break;
    }
    switch (flags & 0xf00) {
    case 0x100:
        a.r = amb[0];
        a.g = amb[1];
        a.b = amb[2];
        a.a = amb[3];
        break;
    case 0x300:
        a.r = 0;
        a.g = 0;
        a.b = 0;
        a.a = 0xff;
        break;
    case 0x200:
    default:
        r = amb[0] * lbl_80344DE0.amb.r;
        g = amb[1] * lbl_80344DE0.amb.g;
        bl = amb[2] * lbl_80344DE0.amb.b;
        a.r = r >> 8;
        a.g = g >> 8;
        a.b = bl >> 8;
        a.a = 0xff;
        break;
    }
    GXSetChanAmbColor(GX_COLOR0A0, a);
    t = &lbl_80344DE0;
    if (t->dirty) {
        t->dirty = 0;
        for (i = 0; i < 8; i++) {
            if (t->light[i].mask) {
                GXInitLightColor(&lbl_80344BE0[i], t->light[i].col);
                GXInitLightPos(&lbl_80344BE0[i], t->light[i].vpos.x, t->light[i].vpos.y, t->light[i].vpos.z);
                GXInitLightDistAttn(&lbl_80344BE0[i], t->light[i].f48, t->light[i].f50, t->light[i].s54);
                GXInitLightSpot(&lbl_80344BE0[i], t->light[i].f58, t->light[i].s5c);
                GXLoadLightObjImm(&lbl_80344BE0[i], t->light[i].mask);
            }
        }
    }
}

s32 fn_802A8ADC(void) { return lbl_80346A50; }

void fn_802A8F40(s32 v) { lbl_80347FB4 = v; }

void fn_802A8FA0(s32 v) { lbl_80347FB8 = v; }

#pragma optimization_level 1
void fn_802A8FA8(s32 i) { lbl_80347FBC = &lbl_80346690[i]; }
#pragma optimization_level reset

inline void fn_802A907C(NjObj* obj) {
    NjDrawCtx* ctx;
    u32* tmp;
    NjModel* m;
    u32* saved;

    ctx = lbl_80346A18;
    do {
        njPushMatrixEx();
        fn_802954EC(obj);
        if (!(obj->evalflags & 0x80)) {
            m = obj->model;
            if (m != 0 && !(obj->evalflags & 8)) {
                fn_802A8F48(&m->vlist, &tmp);
                saved = m->vlist;
                m->vlist = tmp;
                ctx->drawModel(m);
                m->vlist = saved;
            } else {
                fn_802A9040();
            }
        } else if (obj->model != 0 && !(obj->evalflags & 8)) {
            ctx->drawModel(obj->model);
        }
        if (obj->child != 0) {
            fn_802A907C(obj->child);
        }
        njPopMatrixEx();
        obj = obj->sibling;
    } while (obj != 0);
}

void fn_802A9338(NjObj* obj, NJS_MOTION* mot, NJS_MOTION* shape, NjModelCb cb, f32 frame) {
    NjDrawCtx* ctx = lbl_80346A18;
    fn_802956F0(mot, frame);
    ctx->drawModel = cb;
    if (shape == 0) {
        fn_80295738(obj);
    } else {
        fn_802A8FA8(0);
        fn_802A8FC0(shape, frame);
        fn_802A907C(obj);
    }
}

void fn_802A9714(u32** in, u32** out) {
    void* a;
    void* b;
    void* c;
    void* d;

    if (*in == 0) {
        *out = 0;
        return;
    }
    if (lbl_80347FBC->flags & 0x10) {
        a = lbl_80347FBC->arrA[lbl_80347FBC->idx];
        if (a != 0) {
            b = lbl_80347FBC->arrB[lbl_80347FBC->idx];
        }
        lbl_80347FBC->idx++;
    } else {
        a = 0;
    }
    if (lbl_80347FBC->flags & 0x20) {
        c = lbl_80347FBC->arrA[lbl_80347FBC->idx];
        if (c != 0) {
            d = lbl_80347FBC->arrB[lbl_80347FBC->idx];
        }
        lbl_80347FBC->idx++;
    } else {
        c = 0;
    }
    if (a != 0 || c != 0) {
        fn_802A93CC(a, b, c, d, *in, out, lbl_80347FBC->t);
    } else {
        *out = *in;
    }
}

void fn_802A9804(u32** in, u32** out) {
    fn_802AA110(in, out);
    fn_802A8FA8(1);
    fn_802A9040();
    fn_802A8FA8(0);
    fn_802A9040();
}

void fn_802A983C(void) {
    fn_802A8FA8(1);
    fn_802A9040();
    fn_802A8FA8(0);
    fn_802A9040();
}

void fn_802A9870(NJS_MOTION_LINK* p, f32 v) {
    fn_802A8FA8(1);
    fn_802A8FC0(p->motion[1], p->frame[1]);
    fn_802A8FA8(0);
    fn_802A8FC0(p->motion[0], p->frame[0]);

    lbl_80347FC0 = v;
}

inline void fn_802A98D8(NjObj* obj) {
    NjDrawCtx* ctx;
    u32* tmp;
    NjModel* m;
    u32* saved;

    ctx = lbl_80346A18;
    do {
        njPushMatrixEx();
        fn_802947D4(obj);
        if (!(obj->evalflags & 0x80)) {
            m = obj->model;
            if (m != 0 && !(obj->evalflags & 8)) {
                fn_802A9804(&m->vlist, &tmp);
                saved = m->vlist;
                m->vlist = tmp;
                ctx->drawModel(m);
                m->vlist = saved;
            } else {
                fn_802A983C();
            }
        } else if (obj->model != 0 && !(obj->evalflags & 8)) {
            ctx->drawModel(obj->model);
        }
        if (obj->child != 0) {
            fn_802A98D8(obj->child);
        }
        njPopMatrixEx();
        obj = obj->sibling;
    } while (obj != 0);
}

void fn_802A9B94(NjObj* obj, NJS_MOTION_LINK* link, NJS_MOTION_LINK* shape, NjModelCb cb, f32 rate) {
    NjDrawCtx* ctx = lbl_80346A18;
    fn_802949A4(link, rate);
    ctx->drawModel = cb;
    if (shape == 0) {
        fn_80294A0C(obj);
    } else {
        fn_802A9870(shape, rate);
        fn_802A98D8(obj);
    }
}

void fn_802AA110(u32** in, u32** out) {
    void* p3b;
    void* p4b;
    void* p1a;
    void* p2a;
    void* p1b;
    void* p2b;
    void* p3a;
    void* p4a;
    f32 t0;
    f32 t1;

    if (*in == 0) {
        *out = 0;
        return;
    }
    fn_802A8FA8(1);
    if (lbl_80347FBC->flags & 0x10) {
        p1a = lbl_80347FBC->arrA[lbl_80347FBC->idx];
        if (p1a != 0) {
            p1b = lbl_80347FBC->arrB[lbl_80347FBC->idx];
        }
        lbl_80347FBC->idx++;
    } else {
        p1a = 0;
    }
    if (lbl_80347FBC->flags & 0x20) {
        p2a = lbl_80347FBC->arrA[lbl_80347FBC->idx];
        if (p2a != 0) {
            p2b = lbl_80347FBC->arrB[lbl_80347FBC->idx];
        }
        lbl_80347FBC->idx++;
    } else {
        p2a = 0;
    }
    t0 = lbl_80347FBC->t;
    fn_802A8FA8(0);
    if (lbl_80347FBC->flags & 0x10) {
        p3a = lbl_80347FBC->arrA[lbl_80347FBC->idx];
        if (p3a != 0) {
            p3b = lbl_80347FBC->arrB[lbl_80347FBC->idx];
        }
        lbl_80347FBC->idx++;
    } else {
        p3a = 0;
    }
    if (lbl_80347FBC->flags & 0x20) {
        p4a = lbl_80347FBC->arrA[lbl_80347FBC->idx];
        if (p4a != 0) {
            p4b = lbl_80347FBC->arrB[lbl_80347FBC->idx];
        }
        lbl_80347FBC->idx++;
    } else {
        p4a = 0;
    }
    t1 = lbl_80347FBC->t;
    if (p3a != 0 || p4a != 0 || p1a != 0 || p2a != 0) {
        fn_802A9C20(p3a, p3b, t1, t0, lbl_80347FC0, p4a, p4b, p1a, p1b, p2a, p2b, *in, out);
    } else {
        *out = *in;
    }
}

void fn_802AB23C(NjObj* obj) {
    if (!(obj->evalflags & 0x10000)) {
        lbl_80347FC8 = 0;
        lbl_80347FCC = 0;
        fn_80288DE4(obj, fn_802AB2C4);
        if (lbl_80347FC8 != 1) {
            obj->evalflags |= 0x4000;
        }
        if (lbl_80347FCC != 1) {
            obj->evalflags |= 0x8000;
        }
        obj->evalflags |= 0x10000;
    }
}

s32 fn_802AB2C4(NjModel* m) {
    u32* p;
    if (m->vlist != 0) {
        p = m->vlist;
        while ((p[0] & 0xFF) != 0xFF) {
            u32 hdr = p[0];
            u32 n = hdr >> 16;
            s32 cmd = hdr & 0xFF;
            p += 2;
            if (cmd == 0x2C) {
                lbl_80347FC8 = 1;
            }
            p += n - 1;
        }
    }
    if (m->plist != 0) {
        fn_802AB340(m->plist);
    }
    return 0;
}

void fn_802AB340(s16* list) {
    s16* p = list;
    s16 h;
    s16 t;
    while ((h = *p++) != 0xFF) {
        t = h & 0xFF;
        if (t < 8) {
            switch (t) {
            case 0:
            case 1:
            case 2:
            case 3:
                break;
            case 4:
                lbl_803458A8[(s16)((h >> 8) & 0xFF)] = p;
                lbl_80347F24++;
                return;
            case 5:
                fn_802AB340(lbl_803458A8[(s16)((h >> 8) & 0xFF)]);
                lbl_80347F24--;
                break;
            }
        } else if (t < 16) {
            if (*++p & 0x18) {
                p += 8;
            }
        } else if (t < 64) {
            h = *p++;
            p += h;
        } else {
            s32 n;
            s16 fl = (h >> 8) & 8;
            n = *(u16*)p;  /* the chunk stream is s16; this field is unsigned */
            p += 2;
            if (fl & 8) {
                lbl_80347FCC = 1;
            }
            p += n - 1;
        }
    }
}

void fn_802AC2EC(s32 v) { lbl_80346A5C = v; }

void fn_802AC2F4(NjObj* obj) {
    fn_80288DE4(obj, fn_802AC31C);
}

void njMemCopy(void* dst, const void* src, s32 count) {
    memmove(dst, src, count << 2);
}

void* fn_802AC710(void* dst, const void* src, u32 n) {
    return memmove(dst, src, n);
}

void fn_802AC730(void* dst, u8 c, s32 n) {
    if (n > 0) {
        memset(dst, c, n);
    }
}

#include "src/ninja/ninja_asm.c"
