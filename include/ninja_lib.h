#ifndef NINJA_LIB_H
#define NINJA_LIB_H

/* Types and declarations shared by the Sega Ninja library code in src/ninja/ninja.c. Layouts are
 * inferred from the asm (docs/ninja.md); Ninja matrices are Float[16] while the SDK takes Mtx, so
 * the PSMTX/PSVEC routines are declared here with flat pointers. */

#include "types.h"
#include "ninja.h"
#define CURM(m) ((m) ? (m) : (lbl_80347F70 = 5, lbl_80347EB4))
#include <string.h>
#include <dolphin/gx.h>
#include <dolphin/os.h>
extern f64 modf(f64 x, f64* ip);
#define ANG_RAD 9.58737801e-05f /* 2*pi / 65536 */

typedef struct {
    f32 f00;
    s32 f04;
    u32 f08;
    u32 tbl;      /* 0x0c */
    s32 type;     /* 0x10 */
    s32 kind;     /* 0x14 */
    f32 pos[3];   /* 0x18 */
    u8 pad24[0x24];
    u8 col[4];    /* 0x48 */
    f32 f4c, f50, f54, f58;
    s32 s5c;
} NjLight; /* 0x60 stride; the 0x60/0x64 words belong to the next entry's header */
extern NjLight lbl_80344DE0[8];
typedef struct NjObj {
    u32 evalflags;
    void* model;
    NJS_POINT3 pos;
    union {
        Angle ang[3];
        NJS_POINT3 quat;
    } rot;
    NJS_POINT3 scl;
    struct NjObj* child;
    struct NjObj* sibling;
    f32 radius;
} NjObj;
typedef s32 (*NjModelCb)(void*);
extern s32 lbl_80347FD0;
extern s32 lbl_80346A50;
void fn_802AB23C(void);
void fn_80288DE4(NjObj* obj, NjModelCb cb);
s32 fn_802A6184(void*);
s32 fn_80287C14(void*);
extern s32 lbl_80347EA4;
extern f32 lbl_80345828[10];
extern f32 lbl_80345120[12];
void fn_80291C44(NJS_MATRIX m);
void fn_802974B4(void*);
void fn_80292A00(NJS_POINT3* axis, f32 w);
s32 njPushMatrixEx(void);
s32 njPopMatrixEx(void);
void njTranslateEx(NJS_POINT3*);
void njRotateEx(Angle*, s32);
void njScaleEx(NJS_POINT3*);
extern f32 lbl_80347ED8;
s32 fn_802A1160(void*);
s32 fn_802890A4(void*);
void fn_8029CB74(void* p);
void fn_8029B248(s32 kind, void* p);
void fn_8029CB1C(void* p);
extern NjLight lbl_80345350[8];
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
extern f32* lbl_80347EB4;
extern s32 lbl_80347F70;
extern u32 lbl_80347E48;
extern void fn_802394C4(void);
void fn_80297504(Angle a, f32* s, f32* c);
typedef struct {
    u8 pad[0x1c];
    s32 count;
    u32 flags;
} NJ_STATE;
typedef struct {
    f32 p0[3];
    f32 p1[3];
    s16 a;
    s16 b;
} NJ_KEY;
typedef struct {
    f32* p0;
    f32* p1;
    s16* a;
    s16* b;
} NJ_KEYDST;
extern NJ_STATE* lbl_80347E64;
void fn_80293B34(s32 x);
void fn_80293B4C(s32 x, f32 f);
s32 fn_80293EA8(f32* p);
s32 fn_80293E38(s16* p);
extern void* lbl_80347E60;
void fn_802938C8(void* table, s32 stride, s32 count, f32 t, s16** lo, s16** hi, f32* frac);
void fn_802939C4(void* table, s32 stride, s32 count, f32 t, s32** lo, s32** hi, f32* frac);
extern s32 lbl_80347E68;
typedef struct {
    unsigned char pad_00[0xc];
    u32 f0c;
} NjCtx;
extern NjCtx* lbl_80346A18;
void fn_802949A4(void* p);
void fn_80294A0C(void* p);
extern int lbl_80347E78;
extern u16 lbl_80347E7C;
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
    u32 w0;
    f32 t;
    u32 w8;
    s32 count;
    NjCacheRec* rec;
    u32 key;
    s32 idx;
} NjCacheCtx;
extern u8** lbl_80347E80;
extern NjCacheEnt* lbl_80347E84;
extern NjCacheCtx* lbl_80347E88;
void fn_80296680(u32* p, u32 n);
typedef struct {
    u8 pad_00[6];
    s16 f06;
    s16 f08;
    s16 f0A;
    u8 pad_0C[8];
    f32 f14;
    s16 f18;
    u8 pad_1A[0x2E];
    int f48;
} NjGxState;
extern NjGxState lbl_803457A8;
extern s32 lbl_80347F74;
extern s32 lbl_80347F68;
extern s32 lbl_80347F6C;
extern u32 lbl_80347F08;
extern u32 lbl_80347F04;
extern u32 lbl_80347EF8;
extern u32 lbl_80347EF4;
extern u32 lbl_80347EF0;
void fn_80291978(void);
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fc;
    s32 f10;
} Ctl;
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fc;
    s32 f10;
    s32 f14;
} Ent;
extern Ent* lbl_80347ED4;
extern Ctl lbl_803457F8;
void fn_80298E48(void);
s32 fn_802982F0(s32 key);
s32 fn_80297AC0(Ent* e);
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
typedef struct {
    u8 pad[0x14];
    s32 f14;
    s32 f18;
    void* f1c;
} Obj;
s32 fn_802994B8(void* dst, const void* src, u32 n, s32 unused);
extern s32 lbl_80347EC0;
void fn_80299744(s32* a, s32* b);
void fn_802979B8(void);
void fn_80298544(void);
void fn_8029833C(s32 a, s32 b);
void fn_802AC710(void* dst, const void* src, u32 n);
extern u8 lbl_80345BC0[0x800];
extern f32 lbl_80346400[4][4];
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
void PSMTXConcat(const f32* a, const f32* b, f32* ab);
extern u8 lbl_80346500[];
extern u8 lbl_80300A00[];
void fn_802976F8();
extern s32 lbl_80347F7C;
extern s32 lbl_80347F78;
extern s32 lbl_80347EE0;
extern f32 lbl_80300760[];
void PSMTXMultVecArray(const f32* m, const NJS_POINT3* src, NJS_POINT3* dst, u32 count);
extern f32 lbl_80300794[];
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
void fn_802A93CC(void* a, void* b, void* c, void* d, u32* src, u32* dst, f32 t);
void fn_802AA110(void);
void fn_802A8FA8(s32 i);
void fn_802A9040(void);
typedef struct {
    s32 w0;
    s32 w4;
    u16 h8;
    u16 ha;
} NjSpec;
typedef struct {
    const NjSpec* a0;
    const NjSpec* a4;
    f32 f8;
    f32 fc;
} NjPair;
extern f32 lbl_80347FC0;
void fn_802A8FC0(const NjSpec* s, f32 v);
extern s32 lbl_80347FC8;
s32 fn_802AB340(u32* list);
extern s32 lbl_80346A5C;
/* Sega Ninja (GameCube) matrix stack and math wrappers. Names are Ninja's public API; the file
 * name is ours. See docs/ninja.md.
 *
 * Ninja declares matrices as Float[16] while the SDK takes Mtx, so the SDK routines are declared
 * here with flat pointers instead of pulling in dolphin/mtx.h. */

#include "ninja.h"
#include <math.h>

void PSMTXMultVec(const f32* m, const NJS_POINT3* src, NJS_POINT3* dst);
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
extern s32 lbl_80347EA8;
extern s32 lbl_80347EAC;
extern f32* lbl_80347EB0;
void fn_8029748C(NJS_MATRIX m);
static inline void calc_vector(NJS_MATRIX m, NJS_POINT3* src, NJS_POINT3* dst) {
    PSMTXMultVecSR(m ? m : lbl_80347EB4, src, dst);
}

#endif
