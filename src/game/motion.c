#include "types.h"
#include "ninja.h"

/* Motion/keyframe playback for Ninja hierarchical objects (fn_801E3874 .. fn_801E46FC). */

typedef struct NJS_OBJECT {
    u32 evalflags;
    void* model;
    NJS_POINT3 pos;
    Angle ang[3];
    NJS_POINT3 scl;
    struct NJS_OBJECT* child;
    struct NJS_OBJECT* sibling;
} NJS_OBJECT;

/* type: which channels the motion has (1 pos, 2 ang, 4 scl).
 * inp_fn: low nibble = channel count per node, bits 6+ = interpolation kind. */
typedef struct NJS_MOTION {
    void** mdata;
    u32 nbFrame;
    u16 type;
    u16 inp_fn;
} NJS_MOTION;

/* Motion key: frame number plus three floats or three angles. */
typedef struct {
    u32 keyframe;
    f32 key[3];
} NJS_MKEY_F;

typedef struct {
    u32 keyframe;
    Angle key[3];
} NJS_MKEY_A;

/* Key interpolator: interpolates keys[i] .. keys[i+1] at the current frame into out. */
typedef void (*MotionInterpFn)(void* keys, u32 i, u32 nbKeys, void* out);

/* Current motion-playback state (lbl_80313678). */
typedef struct {
    void** mdata;  /* 0x00 current node's channel data */
    void** keys;   /* 0x04 key array pointers for the node */
    void** counts; /* 0x08 key counts for the node */
    f32 frame;     /* 0x0C */
    u32 nbFrame;   /* 0x10 */
    s32 unk14;
    f32* matrix;   /* 0x18 extra matrix applied after each node, or NULL */
    s32 unk1C;
} MotionState;

/* Game model object (only the fields used here; see model.c for the full layout). */
typedef struct {
    u8 pad0[0xE4];
    void* model;        /* 0xE4 model header; the NJS_OBJECT tree starts at +8 */
    NJS_MOTION* motion; /* 0xE8 */
    u8 padEC[0x18C - 0xEC];
    f32 frame;          /* 0x18C */
} ModelObj;

extern MotionState lbl_80313678;
extern s32 lbl_80347748;    /* node counter during evaluation */
extern s32 lbl_8034774C;    /* motion uses interpolation bits */
extern s32 lbl_80347750;    /* motion type (channel mask) */
extern s32 lbl_80347754;    /* channels per node */
extern s32 lbl_80347758;    /* interpolation kind */
extern s32 lbl_8034775C;    /* channels per node (walk) */
extern void** lbl_80347760; /* channel walk pointers, one per channels-per-node value */
extern void** lbl_80347764;
extern void** lbl_80347768;
extern void** lbl_8034776C;
extern MotionInterpFn lbl_80346838[2]; /* float-key interpolators */
extern MotionInterpFn lbl_80346840[2]; /* angle-key interpolators */

void njMultiMatrix(NJS_MATRIX dst, NJS_MATRIX src);
void njRotateY(NJS_MATRIX m, Angle ang);
void njPushMatrixEx(void);
void njPopMatrixEx(void);
void njTranslateEx(NJS_POINT3* v);
void njRotateEx(Angle* ang, s32 order);
void njScaleEx(NJS_POINT3* v);
void njGetTranslation(NJS_MATRIX m, NJS_POINT3* out);
void fn_80286EE8(void);
void fn_8028B498(void);

void fn_801E39B4(NJS_OBJECT* obj, NJS_MOTION* motion, NJS_POINT3* out, f32 frame);
s32 fn_801E3BB4(void* out, s32 which);
void fn_801E3D20(void);
s32 fn_801E3DE0(void* out, s32 which);
s32 fn_801E3F34(void* out, s32 which);
void fn_801E407C(NJS_MOTION* motion, f32 frame);
s32 fn_801E4128(NJS_MOTION* motion, s32 mask, s32 idx);

/* Evaluates the object's motion at its current frame (with a Y rotation) and returns the
 * world position of node 0x17. */
void fn_801E3874(ModelObj* a, NJS_POINT3* out, Angle ang) {
    NJS_OBJECT* model = (NJS_OBJECT*)((u8*)a->model + 8);
    NJS_POINT3 v;

    if (a->motion != 0) {
        lbl_8034775C = a->motion->inp_fn & 0xF;
        lbl_80347758 = a->motion->inp_fn >> 6;
        switch (lbl_8034775C) {
        case 1: lbl_8034776C = a->motion->mdata; break;
        case 2: lbl_80347768 = a->motion->mdata; break;
        case 3: lbl_80347764 = a->motion->mdata; break;
        case 4: lbl_80347760 = a->motion->mdata; break;
        }
        fn_801E407C(a->motion, a->frame);
    }
    lbl_80347748 = 0;
    njPushMatrixEx();
    fn_80286EE8();
    fn_8028B498();
    njUnitMatrix(0);
    njRotateY(0, ang);
    fn_801E39B4(model, a->motion, &v, a->frame);
    njPopMatrixEx();
    out->x = v.x;
    out->y = v.y;
    out->z = v.z;
}

void fn_801E39B4(NJS_OBJECT* obj, NJS_MOTION* motion, NJS_POINT3* out, f32 frame) {
    NJS_POINT3 pos;
    Angle ang[3];
    NJS_POINT3 scl;

    do {
        njPushMatrixEx();
        fn_80286EE8();
        fn_8028B498();
        if (fn_801E4128(motion, 1, 0)) {
            fn_801E3F34(&pos, lbl_80347758);
        } else {
            pos.x = obj->pos.x;
            pos.y = obj->pos.y;
            pos.z = obj->pos.z;
        }
        if (fn_801E4128(motion, 2, 1)) {
            fn_801E3DE0(ang, lbl_80347758);
        } else {
            ang[0] = obj->ang[0];
            ang[1] = obj->ang[1];
            ang[2] = obj->ang[2];
        }
        if (fn_801E4128(motion, 4, 2)) {
            fn_801E3BB4(&scl, lbl_80347758);
        } else {
            scl.x = obj->scl.x;
            scl.y = obj->scl.y;
            scl.z = obj->scl.z;
        }
        njTranslateEx(&pos);
        njRotateEx(ang, 0);
        njScaleEx(&scl);
        if (lbl_80347748 == 0x17) {
            njGetTranslation(NULL, out);
        }
        if (motion != NULL) {
            fn_801E3D20();
            switch (lbl_8034775C) {
            case 1:
                lbl_8034776C += 2;
                break;
            case 2:
                lbl_80347768 += 4;
                break;
            case 3:
                lbl_80347764 += 6;
                break;
            case 4:
                lbl_80347760 += 8;
                break;
            }
        }
        lbl_80347748++;
        if (obj->child != NULL) {
            fn_801E39B4(obj->child, motion, out, frame);
        }
        njPopMatrixEx();
        obj = obj->sibling;
    } while (obj != NULL);
}

/* Interpolates the scale channel of the current node. */
s32 fn_801E3BB4(void* out, s32 which) {
    void* keys;
    u32 count;
    u32 lo, hi, mid;
    u32 t;
    void** p;
    s32 idx = 0;

    if (lbl_80347750 & 1) idx = 1;
    if (lbl_80347750 & 2) idx++;

    switch (lbl_80347754) {
    case 1: p = lbl_80313678.mdata; lbl_80313678.keys = p; lbl_80313678.counts = p + 1; break;
    case 2: p = lbl_80313678.mdata; lbl_80313678.keys = p; lbl_80313678.counts = p + 2; break;
    case 3: p = lbl_80313678.mdata; lbl_80313678.keys = p; lbl_80313678.counts = p + 3; break;
    case 4: p = lbl_80313678.mdata; lbl_80313678.keys = p; lbl_80313678.counts = p + 4; break;
    }
    keys = lbl_80313678.keys[idx];
    count = (u32)lbl_80313678.counts[idx];
    lo = 0;
    hi = count;
    t = (u32)lbl_80313678.frame;
    while (hi - lo > 1) {
        mid = (lo + hi) >> 1;
        if (t >= ((NJS_MKEY_F*)keys)[mid].keyframe) lo = mid; else hi = mid;
    }
    if (keys != 0) {
        lbl_80346838[which](keys, lo, count, out);
        return 1;
    }
    return 0;
}

/* Advances to the next node's channel data. */
void fn_801E3D20(void) {
    switch (lbl_80347754) {
    case 1: lbl_80313678.mdata += 2; break;
    case 2: lbl_80313678.mdata += 4; break;
    case 3: lbl_80313678.mdata += 6; break;
    case 4: lbl_80313678.mdata += 8; break;
    }
    if (lbl_80313678.matrix != 0) {
        njMultiMatrix(0, lbl_80313678.matrix);
    }
}

/* Interpolates the angle channel of the current node. Near miss: the u8 idx is re-masked
 * (clrlslwi) where the original uses a plain slwi. */
s32 fn_801E3DE0(void* out, s32 which) {
    void* keys;
    u32 count;
    u32 lo, hi, mid;
    u32 t;
    void** p;
    u8 idx;

    idx = lbl_80347750 & 1;
    switch (lbl_80347754) {
    case 1: p = lbl_80313678.mdata; lbl_80313678.keys = p; lbl_80313678.counts = p + 1; break;
    case 2: p = lbl_80313678.mdata; lbl_80313678.keys = p; lbl_80313678.counts = p + 2; break;
    case 3: p = lbl_80313678.mdata; lbl_80313678.keys = p; lbl_80313678.counts = p + 3; break;
    case 4: p = lbl_80313678.mdata; lbl_80313678.keys = p; lbl_80313678.counts = p + 4; break;
    }
    keys = lbl_80313678.keys[idx];
    count = (u32)lbl_80313678.counts[idx];
    lo = 0;
    hi = count;
    t = (u32)lbl_80313678.frame;
    while (hi - lo > 1) {
        mid = (lo + hi) >> 1;
        if (t >= ((NJS_MKEY_A*)keys)[mid].keyframe) lo = mid; else hi = mid;
    }
    if (keys != 0) {
        lbl_80346840[which](keys, lo, count, out);
        return 1;
    }
    return 0;
}

/* Interpolates the position channel of the current node. */
s32 fn_801E3F34(void* out, s32 which) {
    void* keys;
    u32 count;
    u32 lo, hi, mid;
    u32 t;
    void** p;

    switch (lbl_80347754) {
    case 1: p = lbl_80313678.mdata; lbl_80313678.keys = p; lbl_80313678.counts = p + 1; break;
    case 2: p = lbl_80313678.mdata; lbl_80313678.keys = p; lbl_80313678.counts = p + 2; break;
    case 3: p = lbl_80313678.mdata; lbl_80313678.keys = p; lbl_80313678.counts = p + 3; break;
    case 4: p = lbl_80313678.mdata; lbl_80313678.keys = p; lbl_80313678.counts = p + 4; break;
    }
    keys = lbl_80313678.keys[0];
    count = (u32)lbl_80313678.counts[0];
    lo = 0;
    hi = count;
    t = (u32)lbl_80313678.frame;
    while (hi - lo > 1) {
        mid = (lo + hi) >> 1;
        if (t >= ((NJS_MKEY_F*)keys)[mid].keyframe) lo = mid; else hi = mid;
    }
    if (keys != 0) {
        lbl_80346838[which](keys, lo, count, out);
        return 1;
    }
    return 0;
}

/* Starts evaluating a motion at the given frame. */
void fn_801E407C(NJS_MOTION* motion, f32 frame) {
    if (motion != 0) {
        if (frame >= (f32)motion->nbFrame) {
            return;
        }
        lbl_80347754 = (u16)(motion->inp_fn & ~0xC0);
        lbl_8034774C = (motion->inp_fn & 0xC0) > 0;
        lbl_80347750 = motion->type;
        lbl_80313678.mdata = motion->mdata;
        lbl_80313678.nbFrame = motion->nbFrame;
    } else {
        lbl_80347754 = 0;
        lbl_8034774C = 0;
        lbl_80347750 = 0;
    }
    lbl_80313678.frame = frame;
    lbl_80313678.unk14 = 0;
    lbl_80313678.matrix = 0;
}

/* 1 if the motion has channel `mask` and the current node has keys in slot idx. */
s32 fn_801E4128(NJS_MOTION* motion, s32 mask, s32 idx) {
    if (motion != 0 && (motion->type & mask) != 0) {
        switch (lbl_8034775C) {
        case 1:
            if (lbl_8034776C[idx] != 0) return 1;
            break;
        case 2:
            if (lbl_80347768[idx] != 0) return 1;
            break;
        case 3:
            if (lbl_80347764[idx] != 0) return 1;
            break;
        case 4:
            if (lbl_80347760[idx] != 0) return 1;
            break;
        }
    }
    return 0;
}

/* Catmull-Rom interpolation of an angle key track at the current frame, between key i and
 * i+1. Near miss: register allocation/scheduling differ (frame 0xC0 vs 0xB0). */
void fn_801E41E0(NJS_MKEY_A* keys, u32 i, u32 nbKeys, Angle* out) {
    NJS_MKEY_A* k1 = &keys[i];
    f32 div[2] = {1.0f, 1.0f};
    NJS_MKEY_A* k0 = &keys[(i + nbKeys - 1) % nbKeys];
    NJS_MKEY_A* k2 = &keys[(i + 1) % nbKeys];
    NJS_MKEY_A* k3 = &keys[(i + 2) % nbKeys];
    f32 t, t2, t3;
    f32 c0, c1, c2, c3;

    div[1] = (f32)(k2->keyframe - k1->keyframe);
    t = (lbl_80313678.frame - (f32)k1->keyframe) / div[(s32)(k2->keyframe - k1->keyframe) > 0];
    t2 = t * t;
    t3 = t2 * t;
    c1 = 1.5f * t3 - 2.5f * t2 + 1.0f;
    c0 = 0.5f * (-t3 + 2.0f * t2 - t);
    c2 = -1.5f * t3 + 2.0f * t2 + 0.5f * t;
    c3 = 0.5f * (t3 - t2);
    out[0] = c0 * k0->key[0] + c1 * k1->key[0] + c2 * k2->key[0] + c3 * k3->key[0];
    out[1] = c0 * k0->key[1] + c1 * k1->key[1] + c2 * k2->key[1] + c3 * k3->key[1];
    out[2] = c0 * k0->key[2] + c1 * k1->key[2] + c2 * k2->key[2] + c3 * k3->key[2];
}

/* Linear interpolation of an angle key track at the current frame, between key i and i+1. */
void fn_801E448C(NJS_MKEY_A* keys, u32 i, u32 nbKeys, Angle* out) {
    f32 div[2] = {1.0f, 1.0f};
    NJS_MKEY_A* k1 = &keys[i];
    NJS_MKEY_A* k2 = &keys[(i + 1) % nbKeys];
    f32 t;
    f32 u;

    div[1] = (f32)(k2->keyframe - k1->keyframe);
    t = (lbl_80313678.frame - (f32)k1->keyframe) / div[(s32)(k2->keyframe - k1->keyframe) > 0];
    u = 1.0f - t;
    out[0] = k1->key[0] * u + k2->key[0] * t;
    out[1] = k1->key[1] * u + k2->key[1] * t;
    out[2] = k1->key[2] * u + k2->key[2] * t;
}

void fn_801E461C(NJS_MKEY_F* keys, u32 i, u32 nbKeys, f32* out) {
    f32 div[2] = {1.0f, 1.0f};
    NJS_MKEY_F* k1 = &keys[i];
    NJS_MKEY_F* k2 = &keys[(i + 1) % nbKeys];
    f32 t;
    f32 u;

    div[1] = (f32)(k2->keyframe - k1->keyframe);
    t = (lbl_80313678.frame - (f32)k1->keyframe) / div[(s32)(k2->keyframe - k1->keyframe) > 0];
    u = 1.0f - t;
    out[0] = k1->key[0] * u + k2->key[0] * t;
    out[1] = k1->key[1] * u + k2->key[1] * t;
    out[2] = k1->key[2] * u + k2->key[2] * t;
}

/* Catmull-Rom interpolation of a float key track at the current frame, between key i and i+1. */
void fn_801E46FC(NJS_MKEY_F* keys, u32 i, u32 nbKeys, f32* out) {
    NJS_MKEY_F* k1 = &keys[i];
    f32 div[2] = {1.0f, 1.0f};
    NJS_MKEY_F* k0 = &keys[(i + nbKeys - 1) % nbKeys];
    NJS_MKEY_F* k2 = &keys[(i + 1) % nbKeys];
    NJS_MKEY_F* k3 = &keys[(i + 2) % nbKeys];
    f32 t, t2, t3;
    f32 c0, c1, c2, c3;

    div[1] = (f32)(k2->keyframe - k1->keyframe);
    t = (lbl_80313678.frame - (f32)k1->keyframe) / div[(s32)(k2->keyframe - k1->keyframe) > 0];
    t2 = t * t;
    t3 = t2 * t;
    c0 = 0.5f * (-t3 + 2.0f * t2 - t);
    c1 = 1.5f * t3 - 2.5f * t2 + 1.0f;
    c2 = -1.5f * t3 + 2.0f * t2 + 0.5f * t;
    c3 = 0.5f * (t3 - t2);
    out[0] = c0 * k0->key[0] + c1 * k1->key[0] + c2 * k2->key[0] + c3 * k3->key[0];
    out[1] = c0 * k0->key[1] + c1 * k1->key[1] + c2 * k2->key[1] + c3 * k3->key[1];
    out[2] = c0 * k0->key[2] + c1 * k1->key[2] + c2 * k2->key[2] + c3 * k3->key[2];
}
