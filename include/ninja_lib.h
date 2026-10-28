#ifndef NINJA_LIB_H
#define NINJA_LIB_H

/* Types and declarations shared by the Sega Ninja library code in src/ninja/ninja.c. Layouts are
 * inferred from the asm (docs/ninja.md); Ninja matrices are Float[16] while the SDK takes Mtx, so
 * the PSMTX/PSVEC routines are declared here with flat pointers. */

#include "types.h"
#include "ninja.h"
#include <string.h>
#include <math.h>
#include <dolphin/gx.h>
#include <dolphin/os.h>
extern f64 modf(f64 x, f64* ip);

#define CURM(m) ((m) ? (m) : (lbl_80347F70 = 5, lbl_80347EB4))
#define ANG_RAD 9.58737801e-05f /* 2*pi / 65536 */

/* ---- Models and nodes ---- */

/* Chunk model (Ninja's NJS_CNK_MODEL): vertex and polygon chunk lists, bounding sphere. */
typedef struct {
    u32* vlist;
    u32* plist;
    NJS_POINT3 center;
    f32 r;
} NjModel;

/* Node of a model tree (Ninja's NJS_CNK_OBJECT plus the quaternion w). */
typedef struct NjObj {
    u32 evalflags;
    NjModel* model;
    NJS_POINT3 pos;
    union {
        Angle ang[3];
        NJS_POINT3 quat;
    } rot;
    NJS_POINT3 scl;
    struct NjObj* child;
    struct NjObj* sibling;
    f32 radius; /* quaternion w when evalflags & 0x400 */
} NjObj;

typedef s32 (*NjModelCb)(NjModel*);

/* A two-motion blend (Ninja's NJS_MOTION_LINK; NJS_MOTION is in ninja.h). */

typedef struct {
    NJS_MOTION* motion[2];
    f32 frame[2];
} NJS_MOTION_LINK;

/* Draw context (lbl_80346A18): the model callback the motion walkers call for each node. */
typedef struct {
    u8 pad_00[0xc];
    NjModelCb drawModel; /* 0x0c */
} NjDrawCtx;
extern NjDrawCtx* lbl_80346A18;

extern s32 lbl_80347FD0;
extern s32 lbl_80346A50;
void fn_802AB23C(NjObj* obj);
void fn_80288DE4(NjObj* obj, NjModelCb cb);
s32 fn_802A6184(NjModel* m);
s32 fn_80287C14(NjModel* m);
s32 fn_802A1160(NjModel* m);
s32 fn_802890A4(NjModel* m);
s32 fn_802A7680(NjModel* m);
s32 fn_802873BC(NjModel* m);
s32 fn_802A7FA0(NjModel* m);
s32 fn_8028AB48(NjModel* m);
s32 fn_80288C68(NjModel* m);
s32 fn_80287D98(u32* vlist, void* base);
void fn_80287F00(u32* plist, s32 n, void* base);
s32 fn_80289228(u32* vlist, void* base);
void fn_80289390(u32* plist, s32 n, void* base);
extern void* lbl_80347EFC;
extern s32 lbl_80347E18;
extern s32 lbl_80347E20;
extern s32 lbl_80347E24;
void fn_80295E6C(NjObj* obj, NJS_MOTION* mot, NjModelCb cb, f32 frame);
void fn_80295140(NjObj* obj, NJS_MOTION_LINK* link, NjModelCb cb, f32 rate);
void fn_8029638C(NjObj* obj, NJS_MOTION* mot, NJS_MOTION* shape, NjModelCb cb, f32 frame, f32 sframe);

/* ---- Lights ---- */

/* One light of a light table (0x60 bytes). */
typedef struct {
    s32 w00;
    u32 mask;        /* 0x04 GX light mask bit */
    s32 type;        /* 0x08 1 = on */
    s32 kind;        /* 0x0c */
    NJS_POINT3 pos;  /* 0x10 */
    NJS_POINT3 vec;  /* 0x1c */
    NJS_POINT3 vpos; /* 0x28 pos in view space */
    NJS_POINT3 vvec; /* 0x34 */
    u8 col[4];       /* 0x40 */
    f32 f44, f48, f4c, f50;
    s32 s54;
    f32 f58;
    s32 s5c;
} NjLight;

/* GXSetChanCtrl light mask, diffuse and attenuation functions. */
typedef struct {
    u32 mask;
    s32 diff_fn;
    s32 attn_fn;
} NjChanCtrl;

/* Light table: the two model renderers each have one (lbl_80344DE0, lbl_80345350). */
typedef struct {
    s32 dirty;
    s32 f04;
    NjLight light[8]; /* 0x008 */
    s32 f308;
    NjChanCtrl chan[2]; /* 0x30c: GX_COLOR0, GX_ALPHA0 */
} NjLightTbl;
extern NjLightTbl lbl_80344DE0;
extern NjLightTbl lbl_80345350;

/* ---- Matrix stack ---- */

extern f32* lbl_80347EB4;
extern s32 lbl_80347F70;
extern s32 lbl_80347EA8;
extern s32 lbl_80347EAC;
extern f32* lbl_80347EB0;
extern s32 lbl_80347EA4;
extern f32 lbl_80345828[10];
extern f32 lbl_80345120[12];
extern f32 lbl_80347ED8;
void fn_80291C44(NJS_MATRIX m);
void fn_802974B4(NJS_MATRIX m);
void fn_8029748C(NJS_MATRIX m);
void fn_80292A00(NJS_POINT3* axis, f32 w);
s32 njPushMatrixEx(void);
s32 njPopMatrixEx(void);
void njTranslateEx(NJS_POINT3*);
void njRotateEx(Angle*, s32);
void njScaleEx(NJS_POINT3*);
void njSetMatrix(NJS_MATRIX md, NJS_MATRIX ms);
void fn_80297504(Angle a, f32* s, f32* c);
void fn_802394C4(void);

void PSMTXConcat(const f32* a, const f32* b, f32* ab);
void PSMTXMultVec(const f32* m, const NJS_POINT3* src, NJS_POINT3* dst);
void PSMTXMultVecArray(const f32* m, const NJS_POINT3* src, NJS_POINT3* dst, u32 count);
void PSMTXMultVecSR(const f32* m, const NJS_POINT3* src, NJS_POINT3* dst);
void PSMTXMultVecArraySR(const f32* m, const NJS_POINT3* src, NJS_POINT3* dst, u32 count);
void PSMTXCopy(const f32* src, f32* dst);
void PSMTXIdentity(f32* m);
u32 PSMTXInverse(const f32* src, f32* inv);
void PSMTXRotRad(f32* m, char axis, f32 rad);
void PSMTXRotAxisRad(f32* m, const NJS_POINT3* axis, f32 rad);
void PSMTXScale(f32* m, f32 x, f32 y, f32 z);
void PSMTXTrans(f32* m, f32 x, f32 y, f32 z);
void PSMTXQuat(f32* m, const f32* q);
f32 PSVECMag(const NJS_POINT3* v);
f32 PSVECSquareMag(const NJS_POINT3* v);
f32 PSVECDotProduct(const NJS_POINT3* a, const NJS_POINT3* b);
void PSVECCrossProduct(const NJS_POINT3* a, const NJS_POINT3* b, NJS_POINT3* ab);
void PSVECNormalize(const NJS_POINT3* src, NJS_POINT3* dst);
void PSVECSubtract(const NJS_POINT3* a, const NJS_POINT3* b, NJS_POINT3* ab);

static inline void calc_vector(NJS_MATRIX m, NJS_POINT3* src, NJS_POINT3* dst) {
    PSMTXMultVecSR(m ? m : lbl_80347EB4, src, dst);
}

/* ---- Motion playback ---- */

typedef s32 (*NjGetVec)(f32* v);
typedef s32 (*NjGetAng)(Angle* a);
typedef s32 (*NjGetAng16)(s16* a);

/* Key interpolator: (keys, key count, out value, frame). */
typedef void (*NjInterp)(void* keys, s32 n, void* out, f32 frame);

/* Motion playback state (lbl_80347E64). */
typedef struct {
    u8 pad_00[0xc];
    void** keys;        /* 0x0c per-channel key tables */
    s32* nkeys;         /* 0x10 per-channel key counts */
    f32 frame;          /* 0x14 */
    u8 pad_18[4];
    s32 count;          /* 0x1c current channel */
    u32 flags;          /* 0x20 */
    NjInterp interpPos;   /* 0x24 */
    NjInterp interpRot;   /* 0x28 */
    NjInterp interpScl;   /* 0x2c */
    NjInterp interpRot16; /* 0x30 */
    NjGetVec getPos;    /* 0x34 */
    NjGetAng getRot;    /* 0x38 */
    NjGetVec getScale;  /* 0x3c */
    NjGetVec getQuat;   /* 0x40 */
    NjGetAng16 getRot16; /* 0x44 */
} NjMotState;
extern NjMotState* lbl_80347E64;
extern NjMotState lbl_803456D0[2];

/* Camera key: position, target (or direction from pos), roll, fov, target mode. */
typedef struct {
    f32 p0[3];
    f32 p1[3];
    s16 a;    /* 0x18 roll */
    s16 b;    /* 0x1a */
    u32 mode; /* 0x1c 2 = p1 is the target itself */
} NJ_KEY;
typedef struct {
    f32* p0;
    f32* p1;
    s16* a;
    s16* b;
} NJ_KEYDST;

void fn_80293B34(s32 x);
void fn_802936E4(NJ_KEY* src, NJS_MOTION* mot, NJ_KEYDST* dst, f32 f);
void fn_8028B880(NJ_KEY* c, NJS_POINT3* target, NJS_POINT3* up);
void fn_802992F8(s32 fov);
void fn_8028BA48(Angle a);
extern NJS_POINT3 lbl_802DAB18;
extern f32 lbl_80347E70;
void fn_802956F0(NJS_MOTION* mot, f32 frame);
s32 fn_802951D4(NjObj* obj, f32* pos, Angle* rot, f32* scale, f32* quat);
void fn_802929C0(f32* q);
extern GXColor lbl_80347E98;
s32 fn_80298FE4(s32 n);
void fn_80293B4C(NJS_MOTION* mot, f32 frame);
s32 fn_80293EA8(f32* p);
s32 fn_80293E38(s16* p);
s32 fn_80293DC0(Angle* p);
s32 fn_80293D48(s16* p);
s32 fn_80293CD8(f32* p);
s32 fn_80293C68(u16* p);
void fn_80294100(void* table, s32 count, u16* out, f32 t);
void fn_80294170(void* table, s32 count, s16* out, f32 t);
void fn_80294770(void* table, s32 count, f32* out, f32 t);
void fn_80293C2C(void);
s32 fn_802951C4(Angle* p);
s32 fn_802951CC(f32* p);
void fn_8029557C(NJS_MOTION* mot, f32 frame);
extern void (*lbl_80347E60)(NjObj*);
void fn_802938C8(void* table, s32 stride, s32 count, f32 t, s16** lo, s16** hi, f32* frac);
void fn_802939C4(void* table, s32 stride, s32 count, f32 t, s32** lo, s32** hi, f32* frac);
extern s32 lbl_80347E68;
void fn_802949A4(NJS_MOTION_LINK* link, f32 rate);
void fn_80294A0C(NjObj* obj);
void fn_80295738(NjObj* obj);
void fn_802947D4(NjObj* obj);
void fn_802954EC(NjObj* obj);
void fn_8029518C(NjObj* obj);
extern int lbl_80347E78;
extern u16 lbl_80347E7C;
extern u32 lbl_80347E90;

/* Per-node cached keys for the vertex-motion streams (lbl_80347E84 / lbl_80347E88). */
typedef struct {
    u32 key;
    s32 a;
    s32 b;
    f32 frac;
} NjCacheEnt;
typedef struct {
    u32* table; /* table[1] is an index into the lbl_80347E80 table */
    u16 count;
} NjCacheRec;
typedef struct {
    NjCacheRec* rec;
    s32 count;
} NjCacheSeg;
typedef struct {
    NjCacheSeg* cur;
    f32 t;
    u32 w8;
    s32 count;       /* 0x0c */
    NjCacheRec* rec; /* 0x10 */
    u32 key;
    s32 idx;
} NjCacheCtx;
typedef struct {
    u32 w0;
    u16 idx; /* 0x04 index into lbl_80347E84 */
    u16 h6;
} NjCacheIdx;
extern NjCacheIdx** lbl_80347E80;
extern NjCacheEnt* lbl_80347E84;
extern NjCacheCtx* lbl_80347E88;
extern NjCacheCtx lbl_80345770[2];
void fn_80296680(u32* p, u32 n);
void fn_80295EB8(NjModel* m);
void fn_802960FC(void);

/* ---- Textures (NjTexBody, NjTexMem and NjTexRef are in ninja.h) ---- */

/* Texture error status (lbl_803457F8), returned by fn_80298E6C. */
typedef struct {
    s32 n;           /* texlist index */
    s32 globalIndex;
    s32 texerr;
    s32 w0c;
    s32 w10;
} NjTexErr;

/* Texture cache regions (lbl_80345AA0). */
typedef struct {
    GXTexRegion region;
    u8 pad_10[0x10];
    GXTexObj* obj; /* 0x20 */
} NjTexCache;

typedef struct {
    u32 fmt;
    u16 w;
    u16 h;
} NjTexSize;

extern NjTexMem* lbl_80347ECC;
extern s32 lbl_80347EC8;
extern NjTexRef* lbl_80347ED4;
extern s32 lbl_80347ED0;
extern s32 lbl_80347EC4;
extern NjTexErr lbl_803457F8;
extern NjTexCache lbl_80345AA0[8];
extern s32 lbl_80347F44;
void fn_80298E48(void);
s32 fn_802982F0(s32 key);
s32 fn_80297AC0(NjTexRef* e);
s32 fn_802995CC(NjTexBody* b, void* a, void* c);
s32 fn_80298694(NjTexBody* b, const void* src);
s32 fn_802986C8(NjTexBody* b, void* a, void* c, void* d);
s32 fn_80297804(NjTexBody* b, u32 w, u32 h, u32 fmt);
s32 fn_8029959C(NjTexBody* b);
s32 fn_8029954C(void* dst, NjTexBody* b);
void fn_80298144(NjTexRef* r);

/* ---- GX render state ---- */

/* Render state (lbl_803457A8, 0x50 bytes; the texture error status follows it). */
typedef struct {
    u16 h00, h02, h04;
    s16 f06; /* 0x06 */
    s16 f08;
    s16 f0A;
    f32 f0c, f10, f14; /* 0x0c */
    s16 f18; /* 0x18 */
    u16 h1a, h1c;
    u16 h1e; /* 0x1e */
    u16 h20;
    u16 blendType; /* 0x22 */
    u16 blendSrc;
    u16 blendDst;
    u16 blendOp;
    u16 mode; /* 0x2a */
    u8 pad_2c[0x18];
    NJS_TEXLIST* texlist; /* 0x44 */
    s32 w48;
    s32 w4c;
} NjGxState;
extern NjGxState lbl_803457A8;

typedef struct {
    f32 v0, v4, v8, vc, v10;
    f32 f14;
    s16 s18;
    s16 s1a;
    s32 s1c;
} NjState;

extern NJS_ARGB _nj_constant_material_;
/* Screen parameters (0x80345878): [0] x scale, [1] y scale, [2] x offset, [3] y offset. */
extern f32 lbl_80345878[];
extern f32 lbl_80345850[];
extern u32 lbl_80347E48;
extern s32 lbl_80347E5C;
extern s32 lbl_80347F74;
extern s32 lbl_80347F68;
extern s32 lbl_80347F6C;
extern u32 lbl_80347F08;
extern u32 lbl_80347F04;
extern u32 lbl_80347EF8;
extern u32 lbl_80347EF4;
extern u32 lbl_80347EF0;
extern f32 lbl_80347F30;
extern f32 lbl_80347F34;
void fn_80291978(void);
void fn_8029CB74(void);
void fn_8029B248(s32 kind, s32 flag);
void fn_8029CB1C(void);
void fn_8029C8A0(void);
void fn_8029976C(NjTexBody* b, s32 n);
void fn_8029EE28(NJS_ARGB* src, u8* dst);
void fn_8029EE50(u8* src, NJS_ARGB* dst);
extern u32 lbl_80300898[2][5];
extern u32 lbl_803008C0[2][5];

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
} Rec3;
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fc;
    s32 f10;
    s32 f14;
} Rec6;
s32 fn_802994B8(void* dst, const void* src, u32 n, s32 unused);
extern s32 lbl_80347EC0;
s32 fn_80299744(s32* a, s32* b);
void fn_802979B8(void);
void fn_80298544(void);
void fn_8029833C(s32 a, s32 b);
void* fn_802AC710(void* dst, const void* src, u32 n);
extern u8 lbl_80345BC0[0x800];
extern f32 lbl_80346400[4][4];
extern f32 lbl_803463C0[4][4];
extern f32 lbl_803464A0[3][4];
extern f32 lbl_803464D0[3][4];
extern f32 lbl_803007C8[3][4];
extern s32 lbl_80346A38;
extern u8 lbl_80347F54;
extern s32 lbl_80347F58;
extern s32 lbl_80346A3C;
extern u8 lbl_80347F5C;
extern s32 lbl_80346A44;
extern u8 lbl_80347F5D;
extern s32 lbl_80347F60;
extern s32 lbl_80346A48;
extern u8 lbl_80347F64;
extern s32 lbl_80347F50;
extern s32 lbl_80346A40;
extern NjTexBody lbl_80346500;
extern u8 lbl_80300A00[];
s32 fn_802976F8();
extern s32 lbl_80347F7C;
extern s32 lbl_80347F78;
extern s32 lbl_80347EE0;
extern f32 lbl_80300760[];
extern f32 lbl_80300794[];

/* ---- NGDL display-list models ---- */

extern s32 lbl_80347FB4;
extern s32 lbl_80347FB8;
typedef struct {
    u8 pad0[0xC];
    void** arrA;
    void** arrB;
    f32 t;
    u32 unk18;
    u32 idx;
    u32 flags;
} NgCtx;
extern NgCtx* lbl_80347FBC;
void fn_802A93CC(void* a, void* b, void* c, void* d, u32* src, u32** dst, f32 t);
void fn_802A9C20(void* a, void* b, f32 t1, f32 t2, f32 t3, void* c, void* d, void* e, void* f, void* g, void* h,
                 u32* src, u32** dst);
void fn_802AA110(u32** in, u32** out);
void fn_802A8FA8(s32 i);
void fn_802A9040(void);
void fn_802A8F48(u32** in, u32** out);
extern f32 lbl_80347FC0;
void fn_802A8FC0(const NJS_MOTION* s, f32 v);
extern s32 lbl_80347FC8;
extern s32 lbl_80347FCC;
s32 fn_802AB2C4(NjModel* m);
s32 fn_802AC31C(NjModel* m);
s32 fn_802AB340(u32* list);
extern s32 lbl_80346A5C;

#endif
