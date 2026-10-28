/* Sega Ninja (GameCube) library: matrix stack, motion/keyframe playback, model chunk walkers and
 * GX drawing. The file name is ours; Ninja's real file boundaries aren't known (docs/ninja.md), so
 * this holds every function matched so far from the 0x80286EE8-0x802AC7E0 region in address order. */

#include "ninja_lib.h"

void fn_80286FEC(s32 n, f32 x, f32 y) {
    NjLight* l;
    if (n == 0) return;
    l = &lbl_80344DE0[n - 1];
    l->f4c = x;
    l->f50 = y;
    l->f54 = 1.0f;
    l->f58 = 0.1f;
    l->s5c = 1;
    (l + 1)->f00 = 0.0f;
    (l + 1)->f04 = 0;
}

void fn_80287B38(NjObj* obj) {
    if (lbl_80347FD0 && !(obj->evalflags & 0x10000)) {
        fn_802AB23C();
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
        fn_802AB23C();
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

void fn_8028A054(void) {
}

void fn_8028A268(void) {
}

void fn_8028A26C(void* p) {
    fn_8029CB74(p);
    fn_8029B248(4, p);
}

void fn_8028A2A4(void) {
}

void fn_8028A3E0(void* p) {
    fn_8029CB1C(p);
    fn_8029B248(4, p);
}

void fn_8028A6B8(void) {
}

void fn_8028A6BC(void* p) {
    fn_8029CB74(p);
    fn_8029B248(0, p);
}

void fn_8028A6F4(void) {
}

void fn_8028A888(void* p) {
    fn_8029CB1C(p);
    fn_8029B248(0, p);
}

void fn_8028B59C(s32 n, f32 x, f32 y) {
    NjLight* l;
    if (n == 0) return;
    l = &lbl_80345350[n - 1];
    l->f4c = x;
    l->f50 = y;
    l->f54 = 1.0f;
    l->f58 = 0.1f;
    l->s5c = 1;
    (l + 1)->f00 = 0.0f;
    (l + 1)->f04 = 0;
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

void fn_802936E4(NJ_KEY* src, s32 arg, NJ_KEYDST* dst, f32 f) {
    u32 flags;
    f32* p0 = dst->p0;
    f32* p1 = dst->p1;
    s16* a = dst->a;
    s16* b = dst->b;
    fn_80293B34(0);
    fn_80293B4C(arg, f);
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

void fn_802938C0(void* p) {
    lbl_80347E60 = p;
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

void fn_80295140(void* a, void* b, u32 c) {
    fn_802949A4(b);
    lbl_80346A18->f0c = c;
    fn_80294A0C(a);
}

void fn_8029518C(u32* flags) {
    if (lbl_80347E78 == 0) {
        return;
    }
    if (lbl_80347E7C & 1) {
        *flags |= 8;
    } else {
        *flags &= ~8;
    }
}

s32 fn_802951C4(void) {
    return 0;
}

s32 fn_802951CC(void) {
    return 0;
}

void fn_80295EB8(u32** pp) {
    s32 i = 0;
    u32* cur = *pp;
    u32 hdr;
    f32 frac;
    s32* hi;
    s32* lo;

    while (i < lbl_80347E88->count) {
        s32 idx = *(u16*)(*lbl_80347E80 + lbl_80347E88->rec->table[1] * 8 + 4);
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

void fn_8029748C(NJS_MATRIX m) {
    memcpy(m, lbl_80347EB4, 0x30);
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

s32 fn_80297B5C(s32 key) {
    s32 r;
    fn_80298E48();
    r = fn_802982F0(key);
    if (r < 0) {
        lbl_803457F8.f4 = key;
        lbl_803457F8.f8 = 1;
        return -1;
    }
    r = fn_80297AC0(lbl_80347ED4 + r);
    if (r < 0) lbl_803457F8.f4 = key;
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

s32 fn_80298694(Obj* o, const void* src) {
    fn_802994B8(o->f1c, src, o->f14, 0);
    return 0;
}

void fn_80298E48(void) {
    lbl_803457F8.f0 = -1;
    lbl_803457F8.f4 = -1;
    lbl_803457F8.f8 = 0;
    lbl_803457F8.fc = 0;
    lbl_803457F8.f10 = 0;
}

Ctl* fn_80298E6C(void) {
    return &lbl_803457F8;
}

s32 fn_80298E78(u32 n) {
    s32 a, b;
    if (n == 2) return lbl_80347EC0;
    fn_80299744(&a, &b);
    if (n == 0) return a;
    return b;
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

s32 fn_8029954C(void* dst, Obj* o) {
    fn_802AC710(dst, o->f1c, o->f14);
    DCFlushRange(dst, o->f14);
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

void fn_8029CF7C(void* p) {
    if (p == 0) {
        fn_802976F8(lbl_80346500, 0x80, 0x80, 0xe);
        *(void**)(lbl_80346500 + 0x1c) = lbl_80300A00;
    } else {
        fn_802976F8(lbl_80346500);
        *(void**)(lbl_80346500 + 0x1c) = p;
    }
}

s32 fn_8029CFF0(void) { return lbl_80347F7C; }

void fn_8029CFF8(s32 v) { lbl_80347F7C = v; }

void fn_8029D000(s32 v) { lbl_80347F78 = v; }

void fn_8029D008(s32 v) { lbl_80347EE0 = v; }

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

void fn_802A9714(u32* in, u32* out) {
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
        fn_802A93CC(a, b, c, d, (u32*)*in, out, lbl_80347FBC->t);
    } else {
        *out = *in;
    }
}

void fn_802A9804(void) {
    fn_802AA110();
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

void fn_802A9870(NjPair* p, f32 v) {
    fn_802A8FA8(1);
    fn_802A8FC0(p->a4, p->fc);
    fn_802A8FA8(0);
    fn_802A8FC0(p->a0, p->f8);
    lbl_80347FC0 = v;
}

s32 fn_802AB2C4(void* arg) {
    u32* p;
    if (((u32**)arg)[0] != 0) {
        p = ((u32**)arg)[0];
        while ((p[0] & 0xFF) != 0xFF) {
            u32 hdr = p[0];
            u32 n = hdr >> 16;
            s32 cmd = (s32)(hdr & 0xFF);
            p += 2;
            if (cmd == 0x2C) {
                lbl_80347FC8 = 1;
            }
            p += n - 1;
        }
    }
    if (((u32**)arg)[1] != 0) {
        fn_802AB340(((u32**)arg)[1]);
    }
    return 0;
}

void fn_802AC2EC(s32 v) { lbl_80346A5C = v; }

void njMemCopy(void* dst, const void* src, s32 count) {
    memmove(dst, src, count << 2);
}

void fn_802AC730(void* dst, u8 c, s32 n) {
    if (n > 0) {
        memset(dst, c, n);
    }
}

