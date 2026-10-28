/* Sega Ninja (GameCube) library: matrix stack, motion/keyframe playback, model chunk walkers and
 * GX drawing. The file name is ours; Ninja's real file boundaries aren't known (docs/ninja.md), so
 * this holds every function matched so far from the 0x80286EE8-0x802AC7E0 region in address order. */

#include "ninja_lib.h"

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
    u32* p;
    void* base;
    if ((_nj_control_3d_flag_ & 0x100) && m->r > 0.0f) {
        if (fn_80288C68(m)) {
            return -1;
        }
    }
    base = lbl_80347EFC;
    p = m->vlist;
    if (p) {
        lbl_80347E18 = fn_80287D98(p, base);
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
    u32* p;
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

void fn_80290708(f32* v, f32* lo, f32* hi) {
    lo[0] = v[0] - v[3];
    lo[1] = v[1] - v[3];
    lo[2] = v[2] - v[3];
    hi[0] = v[0] + v[3];
    hi[1] = v[1] + v[3];
    hi[2] = v[2] + v[3];
}

void fn_80290E98(u32 x) {
    lbl_80347E48 = (x << 8) | (x >> 24);
}

void fn_80291424(void) {
}

void fn_80291428(s32 p) {
    fn_8029CB74();
    lbl_80347E5C = p;
}

f32 njCos(Angle a) {
    return cos(a * ANG_RAD);
}

f32 fn_802917A0(f32 x) {
    f64 ip;
    return modf(x, &ip);
}

f32 njSin(Angle a) {
    return sin(a * ANG_RAD);
}

f32 njTan(Angle a) {
    return tan(a * ANG_RAD);
}

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

void njInitMatrix(NJS_MATRIX* base, s32 limit) {
    f32* aligned = (f32*)(((u32)base + 31) & ~31);
    lbl_80347EB4 = aligned;
    lbl_80347EB0 = aligned;
    lbl_80347EAC = limit;
    lbl_80347EA8 = 1;
    PSMTXCopy(&lbl_803007C8[0][0], lbl_80347EB4);
}

f32 njInnerProduct(NJS_POINT3* a, NJS_POINT3* b) {
    return PSVECDotProduct(a, b);
}

void fn_80291CF8(void) {
    fn_802394C4();
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
    calc_vector(NULL, src, dst);
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

void fn_80292A00(NJS_POINT3* axis, f32 w) {
    f32 q[4];
    f32 t[12];
    q[0] = axis->x;
    q[1] = axis->y;
    q[2] = axis->z;
    q[3] = w;
    PSMTXQuat(t, q);
    PSMTXConcat(lbl_80347EB4, t, lbl_80347EB4);
    lbl_80347F70 = 5;
}

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

void fn_802968B8(void) {
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

void fn_802974E4(void) {
    fn_80291978();
}

void fn_80297504(Angle a, f32* s, f32* c) {
    *s = njSin(a);
    *c = njCos(a);
}

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

static inline s32 load_tex(NjTexMem* m, void* a, void* b) {
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

s32 fn_80297BD8(s32 idx, void* a, void* b) {
    s32 r;
    fn_80298E48();
    r = load_tex(lbl_803457A8.texlist->textures[idx].texaddr->mem, a, b);
    if (r < 0) {
        lbl_803457F8.n = idx;
    }
    return r;
}

static inline s32 reload_tex(NjTexMem* m, void* a, void* b, void* c) {
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

s32 fn_80297CC0(s32 idx, void* a, void* b, void* c) {
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

s32 fn_80298694(NjTexBody* b, const void* src) {
    fn_802994B8(b->data, src, b->size, 0);
    return 0;
}

s32 fn_8029873C(NjTexRef* r, NjTexSize* sz) {
    if (fn_80297804(&r->mem->body, sz->w, sz->h, sz->fmt) != 0) {
        lbl_803457F8.texerr = 6;
        return -1;
    }
    return 1;
}

void fn_80298C78(NJS_TEXLIST* tl, s32 i, s32 j) {
    tl->textures[i].texaddr = &lbl_80347ED4[j];
    tl->textures[i].attr |= 0x200000;
}

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

void fn_80299058(void) {
    fn_802979B8();
}

void fn_80299078(s32 a, s32 b, s32 c, s32 d) {
    fn_80298544();
    fn_8029833C(c, d);
}

s32 fn_802994B0(void) {
    return 0;
}

s32 fn_802994B8(void* dst, const void* src, u32 n, s32 unused) {
    fn_802AC710(dst, src, n);
    DCFlushRange(dst, n);
    return 0;
}

s32 fn_8029954C(void* dst, NjTexBody* b) {
    fn_802AC710(dst, b->data, b->size);
    DCFlushRange(dst, b->size);
    return 0;
}

s32 fn_8029959C(NjTexBody* b) {
    OSFreeToHeap(lbl_80347F44, b->data);
    return 0;
}

s32 fn_80299744(s32* a, s32* b) {
    *a = 0;
    *b = 0;
    return 0;
}

void* fn_80299758(s32 i) {
    return &lbl_80345BC0[i << 4];
}

void fn_80299FC8(void) {
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

void fn_8029A298(void) {
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

void fn_8029D8B0(NjLightTbl* lt, s32 unused, u8 type, s32 enable) {
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

void fn_8029DA24(void* unused, u8 type, s32 mode) {
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
    switch (type) {
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

void fn_802A20DC(f32 a, f32 b, f32 c) {
    lbl_80300760[6] = a;
    lbl_80300760[7] = b;
    lbl_80300760[8] = c;
}

void fn_802A20F4(f32 a, f32 b) {
    lbl_80300760[3] = -a;
    lbl_80300760[4] = b;
}

void fn_802A5EF8(s32 count, NJS_POINT3* dst, NJS_POINT3* src) {
    PSMTXMultVecArray(lbl_80347EB4, src, dst, count);
}

void fn_802A7598(f32 a, f32 b, f32 c) {
    lbl_80300794[6] = a;
    lbl_80300794[7] = b;
    lbl_80300794[8] = c;
}

void fn_802A75B0(f32 a, f32 b) {
    lbl_80300794[3] = -a;
    lbl_80300794[4] = b;
}

s32 fn_802A8ADC(void) { return lbl_80346A50; }

void fn_802A8F40(s32 v) { lbl_80347FB4 = v; }

void fn_802A8FA0(s32 v) { lbl_80347FB8 = v; }

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

void fn_802AC2EC(s32 v) { lbl_80346A5C = v; }

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
