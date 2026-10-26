#include "types.h"
#include "ninja.h"
#include "game/drawstate.h"
/* One declaration per global / prototype. Tk and Chr tables are read through raw offsets
   (same offsets and widths as the per-function struct views they replace). */
typedef struct Lim { u8 pad[6]; s16 x6; s16 x8; s16 xa; } Lim;
typedef struct Node { u8 pad0[8]; u32 x8; u8 name[0x2c]; struct Node* x38; } Node;
extern u8 lbl_8030A10C[];
extern u8 *lbl_80309700[12];
extern u8 *lbl_80309DE4[12];
extern s32 *lbl_80347398;
extern Lim *lbl_80347390;
extern Node *lbl_803473A0;
extern s8 lbl_80347334;
extern s32 lbl_8034733C;
extern s32 lbl_80347338;
typedef struct {
    void *f0;
    void *f4;
    u32 f8;
    u8 fc;
    u8 pad[3];
} TblEnt;
extern TblEnt lbl_80309E88[4];
typedef struct {
    u8 pad0[0x14];
    u32 *p14;
    u8 rest[0x68 - 0x18];
} Elem;
typedef struct ChrState { s32 x0; s8 x4; u8 pad5; s16 x6; s8 x8; u8 pad9[0x17]; } ChrState;
extern ChrState lbl_80309174[12];
typedef struct Row16 { u8 pad[8]; s8 x8; u8 pad9[7]; } Row16;
extern Row16 lbl_80309730[12];
typedef struct Vec3 { f32 x; f32 y; f32 z; } Vec3;
typedef struct Ent { s32 x0; u32 x4; s32 x8; s32 xc; } Ent;
typedef struct Hdr { u8 pad0[4]; s16 count; u8 pad6[2]; Ent e[1]; } Hdr;
#define WORK_OF(i) (*(u8 **)(lbl_80309700[i] + 0x24))
#define WK_S32(i, off) (*(s32 *)(WORK_OF(i) + (off)))
#define WK_S16(i, off) (*(s16 *)(WORK_OF(i) + (off)))
#define CHR_S32(i, off) (*(s32 *)(lbl_80309DE4[i] + (off)))
#define CHR_U32(i, off) (*(u32 *)(lbl_80309DE4[i] + (off)))
#define CHR_S8(i, off) (*(s8 *)(lbl_80309DE4[i] + (off)))
void fn_800D208C(void *obj, f32 f);
void fn_8006AFD0(s16 i, void *a, void *b, s32 c);
extern void fn_8006AC68(s16 i);
extern void fn_800696A8(s32 a, s16 i, s32 b, s8 v);
void fn_8006E924();
s32 fn_8025ECC4(void);
s32 fn_801D6E38(s32 a);
typedef struct U64FE0 {
    u8 pad0[6];
    s16 s6;
} U64FE0;
typedef struct W64FE0 {
    u8 pad0[0x24];
    struct {
        u8 pad[0x4c];
        U64FE0 *u;
    } *work;
} W64FE0;
typedef struct G64FE0 {
    u8 pad0[0xc];
    f32 fc;
    u8 pad10[0x60 - 0x10];
    s32 w60;
    u8 pad64[0x7c - 0x64];
    u32 f7c;
} G64FE0;
typedef struct S64FE0 {
    W64FE0 *p0;
    u8 pad4[0x64 - 4];
    f32 f64;
    f32 f68;
    u8 pad6c[0x80 - 0x6c];
    s16 s80;
} S64FE0;
typedef struct O64FE0 {
    u8 pad0[0x18];
    u8 flags;
    u8 state;
    u8 pad1A[10];
    S64FE0 *s;
} O64FE0;
extern f32 njSin(s32);
f32 njCos(s32 a);
char* fn_8025F0B0(char* d, const char* s);
void* fn_802AC730(void* d, s32 c, u32 n);
typedef struct S6BEFC {
    u8 pad0[8];
    void *p8;
    u8 pad_c[0x8c - 0xc];
    s16 s8c;
    u8 pad8e[0x94 - 0x8e];
    void *p94;
    s16 s98;
    s16 s9a;
    void *p9c;
    s16 sa0;
    u8 pada2[2];
    u8 fa4[4];
} S6BEFC;
typedef struct O6BEFC {
    u8 pad0[0x18];
    u8 flags;
    u8 state;
    u8 pad1A[10];
    S6BEFC *s;
} O6BEFC;
typedef struct H6BEFC {
    u8 pad[0x6c];
    u32 f6c;
} H6BEFC;
extern char lbl_802B0678[];
extern char lbl_802B068C[];
extern void fn_8001C6CC(void *, s16, s16, char *);
extern void fn_80061048(char *);
extern s32 fn_8025CB24(char *, char *, ...);
extern void *fn_801CC1B4(char *);
extern s32 fn_801CC1A4(void *);
extern void *fn_801CC0A0(void *);
extern s32 fn_8006E5BC(void *);
extern s32 fn_8006E4CC(void *, s16 *, s32, void **);
extern s32 fn_8006E640(void *, u8 *, s16 *, s32);
extern void fn_801E17E0(void *);
extern s32 fn_801CC62C(char *);
void fn_8006E244(Ent* e, s32 n);
typedef struct E6DDBC {
    s32 f0;
    void *f4;
    char f8[0x10];
    s32 f18;
} E6DDBC;
typedef struct S6DDBC {
    u8 pad0[4];
    E6DDBC *p4;
    void *p8;
    char name[0x8c - 0xc];
    s16 s8c;
} S6DDBC;
typedef struct O6DDBC {
    u8 pad0[0x18];
    u8 flags;
    u8 state;
    u8 pad1A[10];
    S6DDBC *s;
} O6DDBC;
typedef struct H6DDBC {
    u8 pad0[0x6c];
    u32 f6c;
    u8 pad70[0x104 - 0x70];
    u32 a104[12];
    u32 a134[12];
} H6DDBC;
extern char lbl_802B069C[];
extern void fn_8025F120(char *, char *);
extern u8 fn_80046BB0(char *, s32 *);
extern u32 fn_80035C38(void *);
extern s32 fn_8003DBAC(s32, char *);
int fn_8025EF88(char* a, const char* b);
void fn_80015554(void);
typedef struct U5C188 {
    u8 id;
    u8 pad1[5];
    s16 kind;
    u8 pad8[0x50 - 8];
    u32 f50;
    u8 pad54[0xf0 - 0x54];
    u32 ff0;
    u8 padf4[0x204 - 0xf4];
    s16 s204;
} U5C188;
typedef struct W5C188 {
    u8 pad0[0x4c];
    U5C188 *u;
} W5C188;
typedef struct T5C188 {
    u8 pad0[0x24];
    W5C188 *work;
} T5C188;
typedef struct R5C188 {
    u8 pad0[0x10];
    u32 f10;
    s16 s14;
    s16 s16;
} R5C188;
typedef struct S5C188 {
    u8 pad0[4];
    T5C188 *target;
    u8 pad8[4];
    R5C188 *rec;
} S5C188;
typedef struct O5C188 {
    u8 pad0[0x18];
    u8 flags;
    u8 state;
    u8 pad1A[10];
    S5C188 *s;
} O5C188;
typedef struct G5C188 {
    u8 pad[0x1c4];
    s32 count;
} G5C188;
extern s16 fn_8001FDD8(W5C188 *, s16, s16);
extern s32 fn_80014C90(u8, s32);
extern void fn_80075F2C(T5C188 *);
typedef struct { f32 x, y, z; } V3;
typedef struct U5C328 {
    u8 pad0[0xf0];
    u32 ff0;
    u8 padf4[0x110 - 0xf4];
    V3 v110;
} U5C328;
typedef struct W5C328 {
    u8 pad0[0x1c];
    V3 pos;
    u8 pad28[4];
    s32 i2c;
    u8 pad30[0x4c - 0x30];
    U5C328 *u;
} W5C328;
typedef struct T5C328 {
    u8 pad0[0x24];
    W5C328 *work;
} T5C328;
typedef struct R5C328 {
    u8 pad0[0x10];
    u16 kind;
    u16 count;
    V3 vecs[4];
    f32 angs[4];
} R5C328;
typedef struct S5C328 {
    u8 pad0[4];
    T5C328 *target;
    R5C328 *rec;
} S5C328;
typedef struct O5C328 {
    u8 pad0[0x18];
    u8 flags;
    u8 state;
    u8 pad1A[10];
    S5C328 *s;
} O5C328;
typedef struct G5C328 {
    u8 pad[0x1c4];
    s32 count;
} G5C328;
extern s32 fn_8025ECC4(void);
extern void fn_80071CF0(V3 *, V3 *);
typedef struct P5D47C {
    u8 pad0[0x10];
    u32 flags;
    s16 s14;
    u8 pad16[6];
    V3 v1c;
    V3 v28;
    V3 v34;
    V3 v40;
    V3 v4c;
    V3 v58;
    u8 pad64[4];
    V3 v68;
} P5D47C;
typedef struct O5D47C {
    u8 pad0[0x20];
    V3 v20;
    V3 v2c;
    V3 v38;
    u8 pad44[0x2c];
    s16 s70;
    s16 state;
    s8 b74;
    u8 pad75[3];
    void *p78;
    void *p7c;
    u8 pad80[0x34];
    P5D47C *p;
} O5D47C;
extern void fn_80014AB8(s32, O5D47C *);
extern void fn_8001E4A0(V3 *, V3 *, void *);
extern void fn_80061518(V3 *, V3 *, void *);
extern void fn_80071F84(V3 *, V3 *, V3 *);
extern void njPushMatrixEx(void);
extern void njPopMatrixEx(void);
extern void njRotateX(NJS_MATRIX m, Angle a);
extern void njRotateY(NJS_MATRIX m, Angle a);
extern void njRotateZ(NJS_MATRIX m, Angle a);
extern void fn_80286EE8(void);
extern void fn_8028B498(void);
typedef struct G800624FC {
    u8 pad0[0xc];
    f32 fc;
    u8 pad10[8];
    f32 f18;
    u8 pad1c[4];
    f32 f20;
} G800624FC;
typedef struct S800624FC {
    void *p0;
    f32 f4;
    f32 f8;
    u8 padC[2];
    s16 s0e;
    s16 s10;
} S800624FC;
typedef struct O800624FC {
    u8 pad0[0x18];
    u8 flags;
    u8 state;
    u8 pad1A[10];
    S800624FC *s;
} O800624FC;
extern G800624FC *lbl_80346BD8;
extern void fn_80075FF0(void *, s32, s32);
typedef struct G80064CA4 {
    u8 pad0[0x3c];
    f32 v[3];
    u8 pad48[0x7c - 0x48];
    u32 f7c;
} G80064CA4;
typedef struct U80064CA4 {
    u8 pad0[6];
    s16 kind;
} U80064CA4;
typedef struct W80064CA4 {
    u8 pad0[0x24];
    struct { u8 pad[0x4c]; U80064CA4 *u; } *work;
} W80064CA4;
typedef struct S80064CA4 {
    W80064CA4 *p0;
    u8 pad4[0x3c - 4];
    f32 v[3];
    u8 pad48[0x80 - 0x48];
    s16 s80;
} S80064CA4;
typedef struct O80064CA4 {
    u8 pad0[0x18];
    u8 flags;
    u8 state;
    u8 pad1A[10];
    S80064CA4 *s;
} O80064CA4;
typedef struct Chr { u8 pad[0x1C]; u32 bits; } Chr;
typedef struct Tk { u8 pad[0x19]; u8 state; } Tk;
extern u8 lbl_8030B7F4[];
extern s32 lbl_80347330;
extern s32 lbl_8034732C;
extern Tk* lbl_80347318;
extern void fn_8007D32C(void);
extern f32 njSin(s32 a);
extern f32 njCos(s32 a);
extern void njTranslate(NJS_MATRIX m, f32 x, f32 y, f32 z);
typedef struct Eff {
    u8 pad0[4];
    u32 x4;
    s16 x8;
    u8 padA[6];
    f32 x10;
    u8 pad14[0x30 - 0x14];
    f32 x30;
    f32 x34;
    f32 x38;
    u8 pad3c[0x48 - 0x3C];
    f32 x48;
    f32 x4c;
    u8 pad50[0x64 - 0x50];
} Eff;
typedef struct Task {
    u8 pad0[0x19];
    u8 state;
    u8 pad1a[0x24 - 0x1A];
    u8* work;
} Task;
typedef struct TblEnt_8006B46C { void* f0; void* f4; u32 f8; u8 fc; u8 pad[3]; } TblEnt_8006B46C;
extern void* memset(void*, int, u32);
extern void fn_8006B8A8(Eff*);
typedef struct V5BF30 { f32 x, y, z; } V5BF30;
typedef struct D5BF30 {
    u8 pad0[0x14];
    u32 flags;
    s16 s18;
    s16 s1a;
    V5BF30 v1c;
} D5BF30;
typedef struct S5BF30 {
    s16 cnt;
    u8 pad2[6];
    s16 s8;
    u8 padA[2];
    V5BF30 vc;
    f32 f18;
    f32 f1c;
    u16 u20;
    u8 pad22[2];
    D5BF30 *d;
} S5BF30;
typedef struct O5BF30 {
    u8 pad0[0x18];
    u8 flags;
    u8 state;
    u8 pad1A[10];
    S5BF30 *s;
} O5BF30;
typedef struct H5BF30 {
    u8 pad[0x1c4];
    s32 count;
} H5BF30;
extern V5BF30 lbl_802AD3C8;
extern V5BF30 lbl_802AD3D4[7];
extern void fn_80037FD8(D5BF30 *, u8 *);
extern s16 fn_8022DFFC(V5BF30 *);
extern void fn_8022E18C(V5BF30 *, s32, f32 *);
extern void fn_80012078(V5BF30 *);
extern void fn_80012020(V5BF30 *);
typedef struct U5D8F8 {
    u8 pad0[0x5c];
    void *p5c;
    void *p60;
    u8 pad64[4];
    f32 f68;
    u8 pad6c[0x74 - 0x6c];
    u8 a74[0x10];
    u8 a84[0x154 - 0x84];
    void *p154;
} U5D8F8;
typedef struct W5D8F8 {
    u8 pad0[8];
    NJS_TEXLIST *tex;
    u8 padc[0x1c - 0xc];
    f32 px, py, pz;
    s32 rx, ry, rz;
    f32 sx, sy, sz;
    u8 pad40[0x4c - 0x40];
    U5D8F8 *u;
} W5D8F8;
typedef struct M5D8F8 {
    void *model;
} M5D8F8;
typedef struct T5D8F8 {
    u8 pad0[0x24];
    W5D8F8 *work;
} T5D8F8;
typedef struct O5D8F8 {
    T5D8F8 *t;
    s8 kind;
    u8 mode;
    u8 pad6[2];
    u32 flags;
    u8 padc[4];
    f32 alpha;
    NJS_TEXLIST *tex;
} O5D8F8;
extern void fn_80299040(NJS_TEXLIST *);
extern void fn_8029D008(NJS_TEXLIST *);
extern void fn_8007E678(void *, DrawState *);
extern void fn_80032AD8(void *, s32, s32, s32);
extern void njScale(NJS_MATRIX m, f32 x, f32 y, f32 z);
extern s32 fn_8002F52C(void);
extern void fn_8002F4BC(void *, f32, void *);
extern void fn_80035468(void *, void *, void *, s32, f32);
extern void fn_80035228(void *, void *, s32, f32);
extern void fn_800353F4(void *, void *, void *, s32, f32);
extern void fn_8003529C(void *, void *, s32, f32);
extern void fn_80035380(void *, void *, s32, f32);
typedef struct Q62F70 {
    u8 pad0[4];
    s32 f4;
} Q62F70;
typedef struct U62F70 {
    u8 pad0[6];
    s16 s6;
    u8 pad8[0x5c - 8];
    Q62F70 *p5c;
} U62F70;
typedef struct W62F70 {
    u8 pad0[0x24];
    struct {
        u8 pad[0x4c];
        U62F70 *u;
    } *work;
} W62F70;
typedef struct G62F70 {
    u8 pad0[0xc];
    f32 fc;
    u8 pad10[8];
    f32 f18;
    u8 pad1c[4];
    f32 f20;
    u8 pad24[4];
    f32 f28;
    u8 pad2c[0x88 - 0x2c];
    s16 s88;
    s16 s8a;
    s16 s8c;
} G62F70;
typedef struct S62F70 {
    W62F70 *p0;
    f32 f4;
    f32 f8;
    s16 s0c;
    s16 s0e;
    s16 s10;
    s16 s12;
    s16 s14;
} S62F70;
typedef struct O62F70 {
    u8 pad0[0x18];
    u8 flags;
    u8 state;
    u8 pad1A[10];
    S62F70 *s;
} O62F70;
typedef struct C715F0 {
    s32 w0;
    s8 b4;
    u8 pad5;
    s16 s6;
    u8 pad8[5];
    u8 bd;
    u8 be;
    u8 padf[0x20 - 0xf];
} C715F0;
typedef struct D715F0 {
    u8 pad0[4];
    s8 b4;
    u8 pad5[3];
    s8 b8;
    u8 pad9[7];
} D715F0;
typedef struct U715F0 {
    u8 pad0[0x1c];
    u32 f1c;
} U715F0;
typedef struct G715F0 {
    u8 pad[0x328];
    s8 a[0x16A0 - 0x328];
} G715F0;
extern void fn_8007D3D0(void);
extern void fn_8007181C(void);
typedef struct E6E00C {
    s32 f0;
    void *f4;
    char f8[0x10];
    s32 f18;
} E6E00C;
typedef struct S6E00C {
    u8 pad0[4];
    E6E00C *p4;
    void *p8;
    char name[0x8c - 0xc];
    s16 s8c;
} S6E00C;
typedef struct O6E00C {
    u8 pad0[0x18];
    u8 flags;
    u8 state;
    u8 pad1A[10];
    S6E00C *s;
} O6E00C;
typedef struct H6E00C {
    u8 pad0[0x6c];
    u32 f6c;
} H6E00C;
extern u32 fn_8022ABEC(char *);
extern void *fn_8022ACA8(u32);
typedef struct V57BD0 { f32 x, y, z; } V57BD0;
typedef struct U57BD0 {
    u8 pad0[0xf0];
    u32 ff0;
    u8 pad_f4[0x1fc - 0xf4];
    void *f1fc;
} U57BD0;
typedef struct W57BD0 {
    u8 pad0[0x1c];
    V57BD0 v1c;
    V57BD0 v28;
    u8 pad34[0x4c - 0x34];
    U57BD0 *u;
} W57BD0;
typedef struct P57BD0 {
    u8 pad0[0x24];
    W57BD0 *work;
} P57BD0;
typedef struct D57BD0 {
    u8 pad0[0x10];
    void *d10;
    s16 s14;
    s16 s16;
    s16 s18;
    s16 s1a;
    s16 s1c;
} D57BD0;
typedef struct S57BD0 {
    s16 cnt;
    u8 pad2[2];
    P57BD0 *p4;
    void *f8;
    V57BD0 vc;
    V57BD0 v18;
    D57BD0 *d;
    s32 f28;
} S57BD0;
typedef struct O57BD0 {
    u8 pad0[0x18];
    u8 flags;
    u8 state;
    u8 pad1A[10];
    S57BD0 *s;
} O57BD0;
typedef struct H57BD0 {
    u8 pad[0x1c4];
    s32 count;
} H57BD0;
typedef struct G57BD0 {
    u8 pad0[0x24];
    struct { u8 pad[0x3c]; u32 f3c; } *work;
} G57BD0;
extern G57BD0 *lbl_80347394;
extern V57BD0 lbl_802AD3B8;
extern P57BD0 *fn_8001E05C(P57BD0 *);
extern void fn_80040150(void *, P57BD0 *, s32, void **);
extern void fn_800400D8(void *, P57BD0 *, s32, void **);
typedef struct U6065C {
    u8 pad0[0x154];
    u8 *p154;
} U6065C;
typedef struct W6065C {
    u8 pad0[0x4c];
    U6065C *u;
} W6065C;
typedef struct K6065C {
    u8 pad0[0x24];
    W6065C *work;
} K6065C;
typedef struct D6065C {
    u8 pad0[0x14];
    s16 s14;
    s16 s16;
    s16 s18;
} D6065C;
typedef struct S6065C {
    s16 cnt;
    u8 pad2[2];
    K6065C *p4;
    s32 *p8;
    s16 c;
    s16 e;
    D6065C *d;
} S6065C;
typedef struct O6065C {
    u8 pad0[0x18];
    u8 flags;
    u8 state;
    u8 pad1A[10];
    S6065C *s;
} O6065C;
typedef struct H6065C {
    u8 pad[0x1c4];
    s32 count;
} H6065C;
extern s32 fn_8022E258(void *, void *, u8, s32);
extern void fn_80061F58(void *, s32, s32);
extern void fn_8022F580(void *, s32, s32);
extern void fn_8022E4CC(void *, s32, s32, s32, s32, s32);
typedef struct Ent6EB88 {
    s32 f0;
    void *f4;
    char f8[0x14];
} Ent6EB88;
typedef struct Out6EB88 {
    u8 pad0[8];
    void *f8;
} Out6EB88;
typedef struct H6EB88 {
    u8 pad[0xf8];
    void *pf8;
} H6EB88;
extern char lbl_802B06DC[];
extern void *fn_801DB124(void *);
extern void *fn_801DB244(char *);
extern void fn_801DBE1C(char *, ...);
extern void fn_8006CF54(Out6EB88 *);

void fn_80055E94(u8 *p) {
    p[0x18] |= 0x40;
    *(s32 *)(lbl_8030A10C + 0x1c4) -= 1;
}

void fn_80056FA4(f32 *out, s16 flag) {
    if (flag) {
        *out = -1.0f;
    } else {
        *out = 0.0f;
    }
}

void fn_80060950(u8 *p) {
    fn_800D208C(*(void **)(p + 0x34), *(f32 *)(p + 0x38));
}

void fn_80061014(f32 *a, f32 *b, f32 *out) {
    out[0] = b[0] - a[0];
    out[1] = b[1] - a[1];
    out[2] = b[2] - a[2];
}

void fn_800614FC(u32 *src, u32 *dst) {
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}

void fn_80061F3C(f32 *src, f32 *dst) {
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}

s32 fn_80065490(void) {
    return 1;
}

void fn_800688C4(void *a, s16 idx, void *b, s8 v) {
    u8 *p = lbl_80309700[idx];
    *(s16 *)(*(u8 **)(p + 0x24) + 0x44) = v;
}

void fn_80069684(s16 a, void *b, s32 c) {
    fn_8006AFD0(a, b, (void *)c, 0);
}

void fn_80069CD8(void* a, s16 i, void* b, s8 v) {
    WK_S32(i, 0x3c) = -1;
    if (CHR_U32(i, 0x1c) & 0x6100) {
        WK_S16(i, 0x44) = -1;
    } else {
        WK_S16(i, 0x44) = v;
    }
}

void fn_8006A7DC(s32 a, s16 i, s32 b, s8 v) {
    u8 *c = lbl_80309DE4[i];
    if (*(u32 *)(c + 0x1c) & 0x6950) {
        WK_S16(i, 0x44) = -1;
        WK_S32(i, 0x3c) = -1;
    } else {
        fn_800696A8(a, i, b, v);
    }
    if (v == WK_S16(i, 0x44)) {
        *(s16 *)(c + 0xc) = *(s16 *)(lbl_80309DE4[(s16)a] + 0x82);
    }
}

void fn_8006A8A8(s32 a, s16 i, s32 b, s8 v) {
    u8 *c = lbl_80309DE4[i];
    if (*(u32 *)(c + 0x1c) & 0x6950) {
        WK_S16(i, 0x44) = -1;
        WK_S32(i, 0x3c) = -1;
    } else {
        fn_800696A8(a, i, b, v);
    }
    if (v == WK_S16(i, 0x44)) {
        *(s16 *)(c + 0xc) = *(s16 *)(lbl_80309DE4[(s16)a] + 0x82);
    }
}

void fn_8006A974(s32 a, s16 i, s32 b, s8 v) {
    u8 *c = lbl_80309DE4[i];
    if (*(u32 *)(c + 0x1c) & 0x6950) {
        WK_S16(i, 0x44) = -1;
        WK_S32(i, 0x3c) = -1;
    } else {
        fn_800696A8(a, i, b, v);
    }
    if (v == WK_S16(i, 0x44)) {
        *(s16 *)(c + 0xc) = *(s16 *)(lbl_80309DE4[(s16)a] + 0x82);
    }
}

void fn_8006B3C4(void *a, s16 idx) {
    u8 *p = lbl_80309DE4[idx];
    *(u32 *)(p + 0x1c) |= 1;
}

void fn_8006B3E8(void) {
}

void fn_8006B460(void) {
}

void fn_8006B464(void) {
}

void fn_8006B468(void) {
}

s32 fn_8006B670(s16 idx) {
    if (idx >= 4) {
        return 0;
    }
    return lbl_80309E88[idx].fc == 0;
}

void fn_8006B6A4(s16 idx, u32 v) {
    if (idx < 4) {
        lbl_80309E88[idx].f8 = v;
    }
}

u32 fn_8006B6C8(s16 idx) {
    if (idx >= 4) {
        return 0;
    }
    return lbl_80309E88[idx].f8;
}

void *fn_8006B6F4(s16 idx) {
    if (idx >= 4) {
        return 0;
    }
    return lbl_80309E88[idx].f0;
}

void fn_8006C5A4(void) {
    *lbl_80347398 = -1;
}

s32 fn_8006C8C4(void) {
    return *(u32 *)(lbl_8030A10C + 0x68) == 0;
}

void fn_8006CF28(u8 *a, u32 *out, s32 idx) {
    Elem *arr = *(Elem **)(a + 4);
    u32 *p3 = *(u32 **)((u8 *)arr + 0x14);
    u32 *p;

    if (*p3 == 0) {
        return;
    }
    p = arr[idx].p14;
    *out = p[1];
}

typedef struct SubRec {
    u8 pad0[4];
    u32 v4;
} SubRec;
typedef struct ObjA {
    u8 pad0[0x24];
    SubRec *sub;
} ObjA;
extern void *lbl_803475A8;
extern ObjA *fn_802268E8(void *a, void *fp);
void fn_8006DDBC(O6DDBC *o);
s32 fn_8006DBDC(void)

{
    s32 r;
    ObjA *obj;

    if (*(u32 *)(lbl_8030A10C + 0x6C) & 0x80000000) {
        r = 0;
    } else {
        *(u32 *)(lbl_8030A10C + 0x6C) |= 0x80000000;
        r = 1;
    }
    if (r == 0) {
        return 0;
    }
    obj = fn_802268E8(lbl_803475A8, fn_8006DDBC);
    fn_80061F58(&obj->sub, 0xac, 0);
    obj->sub->v4 = (u32)lbl_80347398;
    return 1;
}

void fn_8006EA70(void) {
    fn_8006E924();
}

void fn_80071B98(f32 *a, f32 *b, f32 *out) {
    out[0] = b[0] - a[0];
    out[1] = b[1] - a[1];
    out[2] = b[2] - a[2];
}

void fn_80071CBC(f32 *a, f32 *b) {
    b[0] = b[0] + a[0];
    b[1] = b[1] + a[1];
    b[2] = b[2] + a[2];
}

void fn_800608C8(f32* p) {
    *p = (f32)(fn_8025ECC4() % 6) * 70.0f;
    if (*p == 0.0f) {
        *p = 45.0f;
    }
}

void fn_80060A54(void) {
    if (fn_801D6E38(0)) {
        *(u32 *)(lbl_8030A10C + 0x6C) |= 0x100000;
        *(s32 *)(lbl_8030A10C + 0x168) = 0;
    } else {
        *(u32 *)(lbl_8030A10C + 0x6C) &= ~0x100000;
    }
}

void fn_80060B20(Vec3* v, f32 x) {
    s32 a;
    if (x > 180.0f) {
        x = 180.0f;
    }
    a = (s32)(182.04445f * (90.0f - 0.5f * x));
    v->x = njCos(a);
    v->z = njSin(a);
}

void fn_800688E8(void* a, s16 i, void* b, s8 v) {
    WK_S32(i, 0x3c) = -1;
    if (CHR_U32(i, 0x1c) & 0x6100) {
        WK_S16(i, 0x44) = -1;
    } else {
        WK_S16(i, 0x44) = v;
    }
}

void fn_80069008(s16 i) {
    fn_8006AC68(i);
    WK_S16(i, 0x44) = 0;
    WK_S32(i, 0x3c) = CHR_S32(i, 0x14);
}

void fn_80069070(s16 i, void* a, void* b) {
    fn_8006AFD0(i, a, b, 0);
    WK_S16(i, 0x44) = 0;
    WK_S32(i, 0x3c) = CHR_S32(i, 0x14);
}

void fn_800690DC(void* a, s16 i, void* b, s8 v) {
    WK_S32(i, 0x3c) = (s16)(CHR_S32(i, 0x18) - CHR_S32(i, 0x14));
    WK_S32(i, 0x40) = (s16)(CHR_S8(i, 0xff) - CHR_S8(i, 0xfe));
    WK_S16(i, 0x44) = v;
}

void fn_80069AE4(void* a, s16 idx, void* b, s8 v) {
    WK_S32(idx, 0x3c) = CHR_S32(idx, 0x18) - CHR_S32(idx, 0x14);
    WK_S16(idx, 0x44) = v;
    lbl_80309174[idx].x8 = 1;
    lbl_80309730[idx].x8 = 1;
}

void fn_80069D34(void* a, s16 idx, void* b, s8 v) {
    WK_S32(idx, 0x3c) = lbl_80347390->x6 - lbl_80347390->x8;
    WK_S16(idx, 0x44) = v;
    lbl_80309174[idx].x8 = 1;
    lbl_80309730[idx].x8 = 1;
}

void fn_80069FF4(s32 a, s16 i, s32 b, s8 v) {
    WK_S32(i, 0x3c) = -1;
    if (CHR_U32(i, 0x1c) & 0x2100) {
        WK_S16(i, 0x44) = -1;
    } else if (v == 0x1e) {
        WK_S16(i, 0x44) = v;
    } else {
        fn_800696A8(a, i, b, v);
    }
}

void fn_8006A388(s32 a, s16 i, s32 b, s8 v) {
    WK_S32(i, 0x3c) = -1;
    if (CHR_U32(i, 0x1c) & 0x2100) {
        WK_S16(i, 0x44) = -1;
    } else {
        WK_S16(i, 0x44) = v;
    }
}

void fn_8006A70C(s32 a, s16 i, s32 b, s8 v) {
    if (CHR_U32(i, 0x1c) & 0x7150) {
        WK_S16(i, 0x44) = -1;
        WK_S32(i, 0x3c) = -1;
    } else {
        fn_800696A8(a, i, b, v);
    }
}

void fn_8006A774(s32 a, s16 i, s32 b, s8 v) {
    if (CHR_U32(i, 0x1c) & 0x6350) {
        WK_S16(i, 0x44) = -1;
        WK_S32(i, 0x3c) = -1;
    } else {
        fn_800696A8(a, i, b, v);
    }
}

void fn_8006AB04(s32 a, s16 i, s32 b, s8 v) {
    if (CHR_U32(i, 0x1c) & 0x2150) {
        WK_S16(i, 0x44) = -1;
        WK_S32(i, 0x3c) = -1;
    } else {
        fn_800696A8(a, i, b, v);
    }
}

void fn_8006AC00(s32 a, s16 i, s32 b, s8 v) {
    fn_800696A8(a, i, b, v);
    if (WK_S16(i, 0x44) != -1) {
        lbl_80309730[i].x8 = 5;
    }
}

void fn_8006AD44(s32 a, s16 i, s32 b, s8 v) {
    if (CHR_U32(i, 0x1c) & 0x61d0) {
        WK_S16(i, 0x44) = -1;
        WK_S32(i, 0x3c) = -1;
    } else {
        fn_800696A8(a, i, b, v);
    }
}

void fn_8006C860(char* a, char* b) {
    char buf[0x100];
    fn_802AC730(buf, 0, 0xff);
    fn_8025F0B0(buf, a);
    fn_8025F0B0(buf, b);
    fn_801CC62C(buf);
}

s32 fn_8006E6E4(Hdr* h) {
    Ent* e = h->e;
    s16 i;
    for (i = 0; i < h->count; e++, i++) {
        e->x4 += (u32)h;
        fn_8006E244(e, 0);
    }
    return 0;
}

Node* fn_8006E810(s32 n) {
    char buf[0x20];
    Node* p;
    Node* nx;
    fn_8003DBAC(n, buf);
    p = lbl_803473A0;
    if (p->x8 == 0) {
        return 0;
    }
    for (;;) {
        if (p->x8 != 0 && fn_8025EF88(buf, (char*)p->name) == 0) {
            return p;
        }
        nx = p->x38;
        if (nx == 0) {
            break;
        }
        p = nx;
    }
    return 0;
}

s32 fn_8006E898(char* s) {
    Node* p = lbl_803473A0;
    Node* nx;
    if (p->x8 == 0) {
        return 0;
    }
    for (;;) {
        if (p->x8 != 0 && fn_8025EF88(s, (char*)p->name) == 0) {
            return 1;
        }
        nx = p->x38;
        if (nx == 0) {
            break;
        }
        p = nx;
    }
    return 0;
}

void fn_80070848(void) {
    u8 *t = lbl_80309700[lbl_80347334];
    if (t == 0) {
        lbl_8034733C = 5;
        lbl_80347338 = 0;
        fn_80015554();
    } else if (*(u32 *)(*(u8 **)(t + 0x24) + 4) & 0x13) {
        lbl_8034733C = 5;
        lbl_80347338 = 0;
        fn_80015554();
    }
}

void fn_80071BCC(f32* out, s32 ang, f32 s) {
    out[0] = s * njSin(ang);
    out[2] = s * njCos(ang);
}

void fn_8005C188(O5C188 *o) {
    S5C188 *s = o->s;
    U5C188 *u = s->target->work->u;
    switch (o->state) {
    case 0: {
        s16 idx = fn_8001FDD8(s->target->work, s->rec->s14, s->rec->s16);
        if (idx >= 0) {
            if (s->rec->f10 & 0x80000000) {
                u->ff0 |= 0x40000;
            }
            if (s->rec->f10 & 0x40000000) {
                u->ff0 |= 0x20000;
            }
            u->s204 = idx;
        } else {
            o->state = 0xfa;
            break;
        }
        if (lbl_8034733C == 5) {
            o->state = 1;
        }
        break;
    }
    case 1:
        if (u->f50 & 0x40000000) {
            o->state = 0xfa;
        } else if (fn_80014C90(u->id, 2) == 0) {
            if (!(u->ff0 & 0x80000)) {
                if (u->ff0 & 0x4000000) {
                    o->state = 0xfa;
                } else {
                    u->ff0 &= ~0x40000;
                    u->ff0 &= ~0x20000;
                    u->s204 = 0;
                    switch (u->kind) {
                    case 0xb:
                    case 0x20:
                        break;
                    default:
                        fn_80075F2C(s->target);
                    }
                    o->state = 0xfa;
                }
            }
        }
        break;
    case 0xfa:
        o->flags |= 0x40;
        (*(G5C188*)&lbl_8030A10C).count--;
        break;
    }
}

void fn_8005C328(O5C328 *o) {
    S5C328 *s = o->s;
    U5C328 *u = s->target->work->u;
    switch (o->state) {
    case 0:
        switch (s->rec->kind) {
        case 0: {
            s8 idx;
            u->ff0 |= 0x40000000;
            idx = fn_8025ECC4() % s->rec->count;
            fn_80071CF0(&s->rec->vecs[idx], &s->target->work->pos);
            s->target->work->i2c = 182.04445f * s->rec->angs[idx];
            break;
        }
        case 1:
            u->ff0 &= ~0x40000000;
            fn_80071CF0(&u->v110, &s->target->work->pos);
            s->target->work->i2c = 0;
            break;
        }
        o->state = 0xfa;
        break;
    case 0xfa:
        o->flags |= 0x40;
        (*(G5C328*)&lbl_8030A10C).count--;
        break;
    }
}

void fn_8005D47C(O5D47C *o) {
    V3 *a;
    V3 *b;
    switch (o->state) {
    case 0:
        if (o->s70 < o->p->s14) {
            return;
        }
        fn_80014AB8(1, o);
        o->state = 1;
        if (o->p->flags & 0x2000) {
            o->b74 = fn_8025ECC4() % 3;
        }
    case 1:
        if (o->p->flags & 0x2000) {
            switch (o->b74) {
            case 0:
                a = &o->p->v1c;
                b = &o->p->v28;
                break;
            case 1:
                a = &o->p->v34;
                b = &o->p->v40;
                break;
            case 2:
                a = &o->p->v4c;
                b = &o->p->v58;
                break;
            }
        } else {
            a = &o->p->v1c;
            b = &o->p->v28;
        }
        if (o->p->flags & 0x10000) {
            fn_80071CF0(a, &o->v20);
            fn_80071CF0(b, &o->v38);
        } else {
            fn_8001E4A0(a, &o->v20, o->p78);
            if ((o->p->flags & 0x80000) && o->p7c != 0) {
                fn_80061518(&o->p->v68, &o->v38, o->p7c);
            } else {
                fn_8001E4A0(b, &o->v38, o->p78);
            }
        }
        fn_80071F84(&o->v2c, &o->v38, &o->v20);
        break;
    }
}

void fn_80060DFC(NJS_POINT3 *out, NJS_POINT3 *a, NJS_POINT3 *b, f32 unused, f32 angle, f32 scale) {
    extern void njPushMatrixEx(void);
    extern void njPopMatrixEx(void);
    extern void njRotateY(NJS_MATRIX m, Angle a);
    extern void fn_80286EE8(void);
    extern void fn_8028B498(void);
    extern f32 fn_80071E9C(NJS_POINT3 *, NJS_POINT3 *);
    extern void fn_80071F84(s32 *, NJS_POINT3 *, NJS_POINT3 *);
    extern void fn_80061450(NJS_POINT3 *, NJS_POINT3 *, NJS_POINT3 *);
    NJS_POINT3 p;
    NJS_POINT3 r;
    NJS_POINT3 q;
    NJS_POINT3 t;
    s32 ang[3];
    f32 dist;
    dist = fn_80071E9C(a, b);
    dist *= 0.5f;
    fn_80071F84(ang, a, b);
    p.z = dist;
    p.x = 0.0f;
    p.y = 0.0f;
    njPushMatrixEx();
    fn_80286EE8();
    fn_8028B498();
    njUnitMatrix(0);
    njRotateY(0, (s32)(182.04445f * angle));
    njCalcPoint(0, &p, &q);
    njPopMatrixEx();
    q.x = q.x * scale;
    njPushMatrixEx();
    fn_80286EE8();
    fn_8028B498();
    njUnitMatrix(0);
    njRotateY(0, ang[1]);
    njCalcPoint(0, &q, &r);
    njPopMatrixEx();
    fn_80061450(a, b, &t);
    out->x = r.x + t.x;
    out->y = r.y + t.y;
    out->z = r.z + t.z;
}

s32 fn_800611C0(V3 *a, V3 *b, V3 *c) {
    f32 zero = 0.0f;
    s32 ret = 0;
    V3 t;
    s32 i;
    f32 *pc;
    f32 *pa;
    f32 *pt;
    if (c->x == zero) {
        a->x = b->x;
    }
    if (c->y == zero) {
        a->y = b->y;
    }
    if (c->z == zero) {
        a->z = b->z;
    }
    if (a->x == b->x && a->z == b->z && a->y == b->y) {
        return 1;
    }
    fn_80071CF0(b, &t);
    pc = &c->x + 3;
    pa = &a->x + 3;
    pt = &t.x + 3;
    for (i = 0; i < 3; i++) {
        pa--;
        pc--;
        pt--;
        *pa = *pa + *pc;
        if (*pc > 0.0f) {
            if (*pa >= *pt) {
                *pa = *pt;
            }
        } else {
            if (*pa <= *pt) {
                *pa = *pt;
            }
        }
    }
    if (a->x == b->x && a->z == b->z && a->y == b->y) {
        ret = 1;
    }
    return ret;
}

void fn_80061654(NJS_POINT3 *a, NJS_POINT3 *b, NJS_POINT3 *rot, NJS_POINT3 *out, NJS_POINT3 *extra) {
    extern void njPushMatrixEx(void);
    extern void njPopMatrixEx(void);
    extern void njRotateXYZ(NJS_MATRIX m, Angle x, Angle y, Angle z);
    extern void fn_80286EE8(void);
    extern void fn_8028B498(void);
    extern void fn_80071CF0(NJS_POINT3 *, NJS_POINT3 *);
    extern void fn_8001E50C(NJS_POINT3 *, NJS_POINT3 *, NJS_POINT3 *);
    NJS_POINT3 d;
    NJS_POINT3 q;
    NJS_POINT3 p;
    Angle ax, ay, az;
    d.x = a->x - b->x;
    d.y = a->y - b->y;
    d.z = a->z - b->z;
    ax = 182.04445f * rot->x;
    ay = 182.04445f * rot->y;
    az = 182.04445f * rot->z;
    p.x = d.x;
    p.y = d.y;
    p.z = d.z;
    njPushMatrixEx();
    fn_80286EE8();
    fn_8028B498();
    njUnitMatrix(0);
    njRotateXYZ(0, ax, ay, az);
    njCalcPoint(0, &p, &q);
    njPopMatrixEx();
    out->x = q.x;
    out->y = q.y;
    out->z = q.z;
    out->x = out->x + b->x;
    out->y = out->y + b->y;
    out->z = out->z + b->z;
    if (extra != 0) {
        fn_80071CF0(out, &d);
        fn_8001E50C(&d, out, extra);
    }
}

void fn_800617A8(NJS_POINT3 *out, NJS_POINT3 *a, NJS_POINT3 *b, f32 scale, f32 angle) {
    extern void njPushMatrixEx(void);
    extern void njPopMatrixEx(void);
    extern void njRotateY(NJS_MATRIX m, Angle a);
    extern void fn_80286EE8(void);
    extern void fn_8028B498(void);
    extern f32 fn_80071E9C(NJS_POINT3 *, NJS_POINT3 *);
    extern void fn_80071F84(s32 *, NJS_POINT3 *, NJS_POINT3 *);
    NJS_POINT3 p;
    NJS_POINT3 q;
    s32 ang[3];
    f32 half;
    half = fn_80071E9C(a, b);
    half *= 0.5f;
    p.x = 0.0f;
    p.y = 0.0f;
    if (a->z > b->z) {
        p.z = half;
        fn_80071F84(ang, a, b);
    } else {
        p.z = -half;
        fn_80071F84(ang, b, a);
    }
    njPushMatrixEx();
    fn_80286EE8();
    fn_8028B498();
    njUnitMatrix(0);
    njRotateY(0, (s32)(182.04445f * angle));
    njCalcPoint(0, &p, &q);
    njPopMatrixEx();
    q.x = q.x * scale;
    q.y = q.x;
    q.x = 0.0f;
    if (q.y < 0.0f) {
        q.y *= -1.0f;
    }
    out->x = q.x;
    out->y = q.y;
    out->z = q.z;
}

void fn_800618FC(NJS_POINT3 *out, NJS_POINT3 *a, NJS_POINT3 *b, f32 angZ, f32 angY, f32 offset) {
    extern void njPushMatrixEx(void);
    extern void njPopMatrixEx(void);
    extern void njRotateY(NJS_MATRIX m, Angle a);
    extern void njRotateZ(NJS_MATRIX m, Angle a);
    extern void fn_80286EE8(void);
    extern void fn_8028B498(void);
    extern f32 fn_80071E9C(NJS_POINT3 *, NJS_POINT3 *);
    extern void fn_80071F84(s32 *, NJS_POINT3 *, NJS_POINT3 *);
    extern void fn_80061450(NJS_POINT3 *, NJS_POINT3 *, NJS_POINT3 *);
    NJS_POINT3 p;
    NJS_POINT3 q3;
    NJS_POINT3 q1;
    NJS_POINT3 q2;
    NJS_POINT3 t;
    s32 ang[3];
    f32 half;
    half = fn_80071E9C(a, b);
    half *= 0.5f;
    half += offset;
    fn_80071F84(ang, a, b);
    p.z = half;
    p.x = 0.0f;
    p.y = 0.0f;
    njPushMatrixEx();
    fn_80286EE8();
    fn_8028B498();
    njUnitMatrix(0);
    njRotateY(0, (s32)(182.04445f * angY));
    njCalcPoint(0, &p, &q1);
    njPopMatrixEx();
    njPushMatrixEx();
    fn_80286EE8();
    fn_8028B498();
    njUnitMatrix(0);
    njRotateZ(0, (s32)(182.04445f * angZ));
    njCalcPoint(0, &q1, &q2);
    njPopMatrixEx();
    njPushMatrixEx();
    fn_80286EE8();
    fn_8028B498();
    njUnitMatrix(0);
    njRotateY(0, ang[1]);
    njCalcPoint(0, &q2, &q3);
    njPopMatrixEx();
    fn_80061450(a, b, &t);
    out->x = q3.x + t.x;
    out->y = q3.y + t.y;
    out->z = q3.z + t.z;
}

void fn_80061C80(NJS_POINT3 *out, s8 mode, f32 a, f32 b, f32 z) {
    NJS_POINT3 p;
    NJS_POINT3 q;
    NJS_POINT3 tmp;
    p.z = z;
    p.x = 0.0f;
    p.y = 0.0f;
    njPushMatrixEx();
    fn_80286EE8();
    fn_8028B498();
    njUnitMatrix(0);
    switch (mode) {
    case 1:
        njRotateZ(0, (s32)(182.04445f * a));
        njRotateY(0, (s32)(182.04445f * b));
        njCalcPoint(0, &p, &q);
        break;
    case 0:
        njRotateX(0, (s32)(182.04445f * a));
        njRotateY(0, (s32)(182.04445f * b));
        njCalcPoint(0, &p, &q);
        break;
    case 2:
        njRotateY(0, (s32)(182.04445f * b));
        njCalcPoint(0, &p, &tmp);
        njRotateX(0, (s32)(182.04445f * a));
        njCalcPoint(0, &tmp, &q);
        break;
    }
    njPopMatrixEx();
    out->x = q.x;
    out->y = q.y;
    out->z = q.z;
}

void fn_800624FC(O800624FC *o) {
    S800624FC *s = o->s;
    void *p = s->p0;
    switch (o->state) {
    case 0:
        o->state = 1;
        s->f4 = (lbl_80346BD8->f18 + lbl_80346BD8->fc) / (f32)s->s0e;
        s->f8 = (lbl_80346BD8->f18 + lbl_80346BD8->fc) / (f32)(s->s10 - s->s0e);
    case 1:
        lbl_80346BD8->f20 = lbl_80346BD8->f20 - s->f4;
        if (lbl_80346BD8->f20 + lbl_80346BD8->fc <= 0.0f) {
            lbl_80346BD8->f20 = -lbl_80346BD8->fc;
            o->state = 2;
            fn_80075FF0(p, 0xf, -1);
        }
        break;
    case 2:
        lbl_80346BD8->f20 = lbl_80346BD8->f20 + s->f8;
        if (lbl_80346BD8->f20 >= lbl_80346BD8->f18) {
            lbl_80346BD8->f20 = lbl_80346BD8->f18;
            o->state = 3;
        }
        break;
    case 3:
        o->state = 4;
        break;
    case 4:
        o->flags |= 0x40;
        break;
    }
}

void fn_80064CA4(O80064CA4 *o) {
    S80064CA4 *s = o->s;
    U80064CA4 *u = s->p0->work->u;
    if (o->state != 3) {
        if (u->kind != s->s80) {
            if (s->s80 != 7) {
                o->state = 2;
            } else {
                (*(G80064CA4 **)&lbl_80346BD8)->v[0] = 0.0f;
                (*(G80064CA4 **)&lbl_80346BD8)->v[1] = 0.0f;
                (*(G80064CA4 **)&lbl_80346BD8)->v[2] = 0.0f;
                o->state = 3;
            }
        }
    }
    if ((*(G80064CA4 **)&lbl_80346BD8)->f7c & 0x40000000) {
        return;
    }
    switch (o->state) {
    case 0:
        o->state = 1;
    case 1:
        (*(G80064CA4 **)&lbl_80346BD8)->v[0] = (*(G80064CA4 **)&lbl_80346BD8)->v[0] + s->v[0];
        (*(G80064CA4 **)&lbl_80346BD8)->v[1] = (*(G80064CA4 **)&lbl_80346BD8)->v[1] + s->v[1];
        (*(G80064CA4 **)&lbl_80346BD8)->v[2] = (*(G80064CA4 **)&lbl_80346BD8)->v[2] + s->v[2];
        break;
    case 2: {
        s32 i;
        s32 n = 0;
        for (i = 0; i < 3; i++) {
            f32 x = (*(G80064CA4 **)&lbl_80346BD8)->v[i];
            if (x > 0.0f) {
                (*(G80064CA4 **)&lbl_80346BD8)->v[i] += 10.0f;
                if ((*(G80064CA4 **)&lbl_80346BD8)->v[i] >= 360.0f) {
                    (*(G80064CA4 **)&lbl_80346BD8)->v[i] = 0.0f;
                    n++;
                }
            } else {
                (*(G80064CA4 **)&lbl_80346BD8)->v[i] = x - 10.0f;
                if ((*(G80064CA4 **)&lbl_80346BD8)->v[i] <= 0.0f) {
                    (*(G80064CA4 **)&lbl_80346BD8)->v[i] = 0.0f;
                    n++;
                }
            }
        }
        if (n == 3) {
            o->state = 3;
        }
        break;
    }
    case 3:
        o->flags |= 0x40;
        break;
    }
}

void fn_8007181C(void) {
    if (lbl_80309174[0].x0 == 8) {
        lbl_80347330--;
        lbl_8034733C = 2;
        lbl_80347338 = 0;
        fn_8007D32C();
        lbl_80309174[1].x0 = 11;
        lbl_80309174[2].x0 = 11;
        lbl_80309174[3].x0 = 11;
        return;
    }
    if (lbl_80347330 < 0) {
        lbl_80347330 = 0;
        lbl_8034732C = 0;
    }
    while (1) {
        u32 bits;
        if (lbl_80347330 > 3) {
            lbl_80347330--;
            lbl_8034733C = 2;
            lbl_80347338 = 0;
            fn_8007D32C();
            return;
        }
        if ((s8)lbl_8030B7F4[lbl_80347330 + 0x328] == -1) {
            lbl_80347330--;
            lbl_8034733C = 2;
            lbl_80347338 = 0;
            fn_8007D32C();
            return;
        }
        bits = (*(Chr*(*)[12])&lbl_80309DE4)[lbl_80347330]->bits;
        if (!(bits & 0x6D00)) {
            lbl_80347338 = 2;
            lbl_80347318->state = 1;
            return;
        }
        if (bits & 0x800) {
            lbl_80309174[lbl_80347330].x0 = 3;
            lbl_80309174[lbl_80347330].x4 = -1;
        }
        lbl_80347330++;
        lbl_8034732C++;
    }
}

void fn_80071D0C(f32 dist, NJS_POINT3* out, NJS_POINT3* pos, Angle* ang) {
    NJS_POINT3 zero;
    NJS_POINT3 res;
    f32 x, y, z;

    x = -njSin(ang[1]) * njCos(ang[0]);
    y = njSin(ang[0]);
    z = -njCos(ang[1]) * njCos(ang[0]);
    x *= -dist;
    y *= -dist;
    z *= -dist;
    njPushMatrixEx();
    fn_80286EE8();
    fn_8028B498();
    zero.x = 0.0f;
    zero.y = 0.0f;
    zero.z = 0.0f;
    njUnitMatrix(0);
    njTranslate(0, pos->x, pos->y, pos->z);
    njTranslate(0, x, y, z);
    njCalcPoint(0, &zero, &res);
    out->x = res.x;
    out->y = res.y;
    out->z = res.z;
    njPopMatrixEx();
}

static inline u32 get_f8(s16 idx) {
    if (idx >= 4) {
        return 0;
    }
    return lbl_80309E88[idx].f8;
}

void fn_8006B46C(Task* t) {
    Eff* e = (Eff*)(t->work + 0x28);
    switch (t->state) {
    case 0:
        memset(e, 0, 0x64);
        e->x8 = 1;
        e->x30 = 0.1f;
        e->x34 = 0.5f;
        e->x38 = 0.3f;
        e->x10 = 60.0f;
        e->x48 = 80.0f;
        e->x4c = 300.0f;
        t->state = 1;
    case 1:
        e->x4 |= 0x40000000;
        t->state = 3;
        break;
    case 3:
        fn_8006B8A8(e);
        if (get_f8(e->x8) == 1) {
            t->state = 5;
        }
        break;
    case 5:
        if (get_f8(e->x8) == 0) {
            t->state = 3;
        }
        break;
    }
}

void fn_8005BF30(O5BF30 *o) {
    f32 tmp;
    V5BF30 b = lbl_802AD3C8;
    V5BF30 a = lbl_802AD3D4[0];
    S5BF30 *s = o->s;
    switch (o->state) {
    case 0:
        s->vc.x = s->d->v1c.x;
        s->vc.y = s->d->v1c.y;
        s->vc.z = s->d->v1c.z;
        s->f18 = 0.0f;
        s->f1c = 0.1f;
        s->u20 = fn_8022DFFC(&s->vc);
        if (s->u20 > 300) {
            s->u20 = 300;
        }
        o->state = 1;
    case 1:
        if (s->cnt >= s->d->s18) {
            if (s->s8 >= s->u20) {
                o->state = 0xfa;
            } else {
                fn_8022E18C(&s->vc, s->s8, &tmp);
                if (s->d->flags & 0x40000000) {
                    b.x = tmp;
                }
                if (s->d->flags & 0x80000000) {
                    b.y = tmp;
                }
                if (s->d->flags & 0x20000000) {
                    b.z = tmp;
                }
                fn_80012078(&b);
                if (s->d->flags & 0x8000000) {
                    a.x = tmp;
                }
                if (s->d->flags & 0x10000000) {
                    a.y = tmp;
                }
                if (s->d->flags & 0x4000000) {
                    a.z = tmp;
                }
                fn_80012020(&a);
            }
            s->s8 = s->s8 + 1;
        }
        if (s->d->s18 < s->d->s1a && s->cnt >= s->d->s1a) {
            o->state = 0xfa;
        }
        break;
    case 0xf9:
    case 0xfa:
        fn_80012078(&b);
        o->flags |= 0x40;
        (*(H5BF30*)&lbl_8030A10C).count--;
        return;
    }
    s->cnt = s->cnt + 1;
    fn_80037FD8(s->d, &o->state);
}

void fn_8005D8F8(O5D8F8 *o) {
    W5D8F8 *w;
    T5D8F8 *t;
    U5D8F8 *u;
    u8 mode;
    M5D8F8 *m;
    f32 scale;
    DrawState ds;
    if (o->kind >= 0) {
        t = o->t;
        w = t->work;
        u = w->u;
        fn_80299040(w->tex);
        scale = u->f68;
        m = *(M5D8F8 **)t->work;
        DrawStateDefault2D(&ds);
        if (!(o->flags & 0x8000)) {
            fn_8007E678(u->p154, &ds);
            ds.colour.a = o->alpha;
        } else {
            u8 v = 255 - (s32)(255.0f * o->alpha);
            if (v >= 255) {
                v = 254;
            }
            fn_80032AD8(m, v | 0xffffff00, -1, 0);
        }
        mode = o->mode;
        ds.control3d |= 0x8000;
        fn_8029D008(o->tex);
        njPushMatrixEx();
        fn_80286EE8();
        fn_8028B498();
        if (DrawStatePush(&ds) != 0) {
            njTranslate(0, w->px, w->py, w->pz);
            njRotateXYZ(0, w->rx, w->ry, w->rz);
            njScale(0, w->sx, w->sy, w->sz);
            if (fn_8002F52C() != 0) {
                fn_8002F4BC(m, scale, u->p5c);
            } else {
                switch (o->kind) {
                case 0:
                    fn_80035468(m, u->a74, u->a84, mode, scale);
                    break;
                case 1:
                    fn_80035228(m, u->a74, mode, scale);
                    break;
                case 2:
                    fn_800353F4(m, u->p5c, u->p60, mode, scale);
                    break;
                case 4:
                    fn_8003529C(m, u->p5c, mode, scale);
                    break;
                case 3:
                    fn_80035380(m, u->p5c, mode, scale);
                    break;
                }
            }
            DrawStatePop(&ds);
        }
        njPopMatrixEx();
    }
}

void fn_80061ABC(NJS_POINT3 *out, f32 ay, f32 az, NJS_POINT3 *p, NJS_POINT3 *q) {
    extern f32 fn_80071E9C(NJS_POINT3 *, NJS_POINT3 *);
    extern void fn_80071F84(Angle *, NJS_POINT3 *, NJS_POINT3 *);
    extern void fn_80061450(NJS_POINT3 *, NJS_POINT3 *, NJS_POINT3 *);
    NJS_POINT3 v38;
    NJS_POINT3 v2c;
    NJS_POINT3 v20;
    NJS_POINT3 v14;
    Angle ang[3];
    f32 d = fn_80071E9C(p, q);
    d *= 0.5f;
    v38.x = 0.0f;
    v38.y = 0.0f;
    if (p->z > q->z) {
        v38.z = d;
        fn_80071F84(ang, p, q);
    } else {
        v38.z = -d;
        fn_80071F84(ang, q, p);
    }
    njPushMatrixEx();
    fn_80286EE8();
    fn_8028B498();
    njUnitMatrix(0);
    njRotateY(0, (s32)(182.04445f * az));
    njRotateZ(0, (s32)(182.04445f * ay));
    njCalcPoint(0, &v38, &v20);
    njPopMatrixEx();
    njPushMatrixEx();
    fn_80286EE8();
    fn_8028B498();
    njUnitMatrix(0);
    njRotateX(0, ang[0]);
    njRotateY(0, ang[1]);
    njCalcPoint(0, &v20, &v2c);
    njPopMatrixEx();
    fn_80061450(p, q, &v14);
    if (out->y < 0.0f) {
        out->y *= -1.0f;
    }
    out->x = v2c.x + v14.x;
    out->y = v2c.y + v14.y;
    out->z = v2c.z + v14.z;
}

void fn_80062F70(O62F70 *o) {
    S62F70 *s = o->s;
    U62F70 *pp = s->p0->work->u;
    switch (o->state) {
    case 0:
        o->state = 1;
        (*(G62F70 **)&lbl_80346BD8)->s88 = 1;
        (*(G62F70 **)&lbl_80346BD8)->s8a = 0;
        (*(G62F70 **)&lbl_80346BD8)->s8c = s->s0e;
        if ((*(G62F70 **)&lbl_80346BD8)->f28 >= 180.0f) {
            s->s14 = 1;
            s->f8 = (*(G62F70 **)&lbl_80346BD8)->f28 - 180.0f;
        } else {
            s->s14 = 2;
            s->f8 = (*(G62F70 **)&lbl_80346BD8)->f28;
        }
        s->f4 = ((*(G62F70 **)&lbl_80346BD8)->f18 + (*(G62F70 **)&lbl_80346BD8)->fc) / (f32)s->s0c;
    case 1:
        if (s->s14 != 0) {
            (*(G62F70 **)&lbl_80346BD8)->f28 = (*(G62F70 **)&lbl_80346BD8)->f28 - s->f8 / (f32)s->s0c;
            switch (s->s14) {
            case 2:
                if ((*(G62F70 **)&lbl_80346BD8)->f28 <= 0.0f) {
                    (*(G62F70 **)&lbl_80346BD8)->f28 = 0.0f;
                    s->s14 = 0;
                }
                break;
            case 1:
                if ((*(G62F70 **)&lbl_80346BD8)->f28 <= 180.0f) {
                    (*(G62F70 **)&lbl_80346BD8)->f28 = 180.0f;
                    s->s14 = 0;
                }
                break;
            }
        }
        (*(G62F70 **)&lbl_80346BD8)->f20 = (*(G62F70 **)&lbl_80346BD8)->f20 - s->f4;
        if ((*(G62F70 **)&lbl_80346BD8)->f20 + (*(G62F70 **)&lbl_80346BD8)->fc <= 0.0f) {
            (*(G62F70 **)&lbl_80346BD8)->f20 = -(*(G62F70 **)&lbl_80346BD8)->fc;
            o->state = 3;
            (*(G62F70 **)&lbl_80346BD8)->s8a = s->s10;
            (*(G62F70 **)&lbl_80346BD8)->s8c = pp->p5c->f4;
        }
        break;
    case 2:
        if (pp->s6 != s->s12) {
            (*(G62F70 **)&lbl_80346BD8)->s88 = 0;
            o->state = 3;
        }
        break;
    case 3:
        o->state = 4;
        break;
    case 4:
        o->flags |= 0x40;
        break;
    }
}

void fn_800715F0(void) {
    switch (lbl_80347338) {
    case 0: {
        s32 i;
        s32 idx;
        u32 f;
        i = 0;
        do {
            (*(C715F0(*)[12])&lbl_80309174)[i].w0 = -1;
            (*(C715F0(*)[12])&lbl_80309174)[i].b4 = i;
            (*(C715F0(*)[12])&lbl_80309174)[i].s6 = -1;
            (*(D715F0(*)[12])&lbl_80309730)[i].b4 = i;
            (*(C715F0(*)[12])&lbl_80309174)[i].bd = 0;
            (*(C715F0(*)[12])&lbl_80309174)[i].be = 0;
            (*(D715F0(*)[12])&lbl_80309730)[i].b8 = -1;
            i++;
        } while (i < 12);
        lbl_80347330 = 0;
        lbl_8034732C = 0;
        fn_8007D3D0();
        idx = lbl_80347330;
        for (;;) {
            if ((*(G715F0*)&lbl_8030B7F4).a[idx] == -1) {
                lbl_8034733C = 2;
                lbl_80347338 = 0;
                fn_8007D32C();
                break;
            }
            f = (*(U715F0 *(*)[12])&lbl_80309DE4)[idx]->f1c;
            if (f & 0x6d00) {
                if (f & 0x800) {
                    (*(C715F0(*)[12])&lbl_80309174)[idx].w0 = 3;
                    (*(C715F0(*)[12])&lbl_80309174)[idx].b4 = -1;
                }
                lbl_80347330 = lbl_80347330 + 1;
                lbl_8034732C = lbl_8034732C + 1;
                idx++;
            } else {
                lbl_80347338 = 2;
                break;
            }
        }
        break;
    }
    case 4: {
        if (lbl_80347330 > 0) {
            lbl_80347330 = lbl_80347330 - 1;
            lbl_8034732C = lbl_8034732C - 1;
        }
        for (;;) {
            if (lbl_80347330 < 0) {
                lbl_80347330 = 0;
                lbl_8034732C = 0;
                break;
            }
            if (!((*(U715F0 *(*)[12])&lbl_80309DE4)[lbl_80347330]->f1c & 0x6d00)) {
                break;
            }
            lbl_80347330 = lbl_80347330 - 1;
            lbl_8034732C = lbl_8034732C - 1;
        }
        lbl_80347338 = 1;
        fn_8007181C();
        break;
    }
    case 3:
        lbl_80347330 = lbl_80347330 + 1;
        lbl_8034732C = lbl_8034732C + 1;
        lbl_80347338 = 1;
    case 1:
        fn_8007181C();
        break;
    case 5:
        lbl_8034733C = 2;
        lbl_80347338 = 0;
        fn_8007D32C();
        break;
    }
}

void fn_80064FE0(O64FE0 *o) {
    S64FE0 *s = o->s;
    s16 v = s->s80;
    if (s->p0->work->u->s6 != v && o->state != 3) {
        if (v != 7) {
            o->state = 2;
        } else {
            (*(G64FE0 **)&lbl_80346BD8)->fc = 0.0f;
            (*(G64FE0 **)&lbl_80346BD8)->w60 = 0;
            o->state = 3;
        }
    }
    if ((*(G64FE0 **)&lbl_80346BD8)->f7c & 0x40000000) {
        return;
    }
    switch (o->state) {
    case 0:
        o->state = 1;
    case 1:
        (*(G64FE0 **)&lbl_80346BD8)->fc = s->f68 * njSin((*(G64FE0 **)&lbl_80346BD8)->w60);
        (*(G64FE0 **)&lbl_80346BD8)->w60 += (s32)(182.04445f * s->f64);
        break;
    case 2:
        if ((*(G64FE0 **)&lbl_80346BD8)->fc > 0.0f) {
            (*(G64FE0 **)&lbl_80346BD8)->fc = s->f68 * njSin((*(G64FE0 **)&lbl_80346BD8)->w60);
            (*(G64FE0 **)&lbl_80346BD8)->w60 += 0x71c;
            if ((*(G64FE0 **)&lbl_80346BD8)->fc <= 0.0f) {
                (*(G64FE0 **)&lbl_80346BD8)->fc = 0.0f;
                (*(G64FE0 **)&lbl_80346BD8)->w60 = 0;
                o->state = 3;
            }
        } else {
            (*(G64FE0 **)&lbl_80346BD8)->fc = s->f68 * njSin((*(G64FE0 **)&lbl_80346BD8)->w60);
            (*(G64FE0 **)&lbl_80346BD8)->w60 += 0x71c;
            if ((*(G64FE0 **)&lbl_80346BD8)->fc >= 0.0f) {
                (*(G64FE0 **)&lbl_80346BD8)->fc = 0.0f;
                (*(G64FE0 **)&lbl_80346BD8)->w60 = 0;
                o->state = 3;
            }
        }
        break;
    case 3:
        o->flags |= 0x40;
        break;
    }
}

void fn_8006BEFC(O6BEFC *o) {
    char buf[0x40];
    char name[0x20];
    void *out;
    S6BEFC *s = o->s;
    switch (o->state) {
    case 0:
        o->state = 1;
    case 1:
        fn_8001C6CC(s->p94, s->s98, s->s9a, name);
        fn_80061048(name);
        fn_8025CB24(buf, lbl_802B0678, name, s->s8c);
        if (fn_801CC62C(buf) == 0 && s->s8c == 0) {
            fn_8025CB24(buf, lbl_802B068C, name);
        }
        if (fn_801CC62C(buf) == 0) {
            o->state = 5;
            break;
        }
        s->p8 = fn_801CC1B4(buf);
        o->state = 2;
        break;
    case 2:
        if (fn_801CC1A4(s->p8) == 1) {
            s->p9c = fn_801CC0A0(s->p8);
            if (fn_8006E5BC(s->p9c) != 0) {
                o->state = 3;
            } else {
                fn_8001C6CC(s->p94, s->s98, s->s9a, name);
                o->state = 4;
            }
        }
        break;
    case 3:
        if (fn_8006E4CC(s->p9c, &s->sa0, 10, &out) == 0) {
            s->p9c = out;
            fn_801E17E0(s->p9c);
            s->sa0 = 0;
            s->s8c = s->s8c + 1;
            o->state = 1;
        } else {
            s->p9c = out;
        }
        break;
    case 4:
        if (fn_8006E640(s->p9c, s->fa4, &s->sa0, 10) == 0) {
            fn_801E17E0(s->p9c);
            s->sa0 = 0;
            s->s8c = s->s8c + 1;
            o->state = 1;
        }
        break;
    case 5:
        s->s8c = 0;
        o->state = 6;
        break;
    case 6:
        (*(H6BEFC*)&lbl_8030A10C).f6c &= 0x7fffffff;
        o->flags |= 0x40;
        break;
    }
}

void fn_8006DDBC(O6DDBC *o) {
    char buf2[0x4c];
    char buf[0x20];
    s32 v;
    S6DDBC *s = o->s;
    switch (o->state) {
    case 0:
        o->state = 1;
    case 1:
        if (s->p4[s->s8c].f0 > 0) {
            if (fn_8003DBAC(s->p4[s->s8c].f0, s->name) == 0) {
                fn_8025F120(s->name, s->p4[s->s8c].f8);
            }
            switch (fn_80046BB0(s->name, &v)) {
            case 0:
            default:
                fn_8025CB24(buf, lbl_802B069C);
                break;
            case 1:
                switch (v / 100000) {
                case 99:
                    fn_8025CB24(buf, lbl_802B069C);
                    break;
                default:
                    fn_8025CB24(buf, "/BEFF/");
                    break;
                }
                break;
            case 2:
            case 3:
                fn_8025CB24(buf, "/BEFF/");
                break;
            }
            fn_8025CB24(buf2, "%s%s", buf, s->name);
            s->p8 = fn_801CC1B4(buf2);
            s->s8c = s->s8c + 1;
            o->state = 2;
        } else {
            o->state = 4;
        }
        break;
    case 2:
        if (fn_801CC1A4(s->p8) == 1) {
            s->p4[s->s8c - 1].f4 = fn_801CC0A0(s->p8);
            if (s->s8c - 1 < 12) {
                (*(H6DDBC*)&lbl_8030A10C).a104[s->s8c] = fn_80035C38(s->p4[s->s8c - 1].f4);
                (*(H6DDBC*)&lbl_8030A10C).a134[s->s8c] = s->p4[s->s8c - 1].f18;
            }
            o->state = 1;
        }
        break;
    case 4:
        (*(H6DDBC*)&lbl_8030A10C).f6c &= 0x7fffffff;
        o->flags |= 0x40;
        break;
    }
}

void fn_8006E00C(O6E00C *o) {
    char buf2[0x4c];
    char buf[0x20];
    s32 v;
    u32 x;
    S6E00C *s = o->s;
    switch (o->state) {
    case 0:
        o->state = 1;
    case 1:
        if (s->p4[s->s8c].f0 > 0) {
            if (fn_8003DBAC(s->p4[s->s8c].f0, s->name) == 0) {
                fn_8025F120(s->name, s->p4[s->s8c].f8);
            }
            x = fn_8022ABEC(s->name);
            if (x != 0xffffffff) {
                void *q = fn_8022ACA8(x);
                if (q != 0) {
                    s->p4[s->s8c].f4 = q;
                    s->s8c = s->s8c + 1;
                    break;
                }
            }
            switch (fn_80046BB0(s->name, &v)) {
            case 0:
            default:
                fn_8025CB24(buf, lbl_802B069C);
                break;
            case 1:
                switch (v / 100000) {
                case 99:
                    fn_8025CB24(buf, lbl_802B069C);
                    break;
                default:
                    fn_8025CB24(buf, "/BEFF/");
                    break;
                }
                break;
            case 2:
            case 3:
                fn_8025CB24(buf, "/BEFF/");
                break;
            }
            fn_8025CB24(buf2, "%s%s", buf, s->name);
            s->p8 = fn_801CC1B4(buf2);
            s->s8c = s->s8c + 1;
            o->state = 2;
        } else {
            o->state = 4;
        }
        break;
    case 2:
        if (fn_801CC1A4(s->p8) == 1) {
            s->p4[s->s8c - 1].f4 = fn_801CC0A0(s->p8);
            o->state = 1;
        }
        break;
    case 4:
        (*(H6E00C*)&lbl_8030A10C).f6c &= 0x7fffffff;
        o->flags |= 0x40;
        break;
    }
}

void fn_80057BD0(O57BD0 *o) {
    S57BD0 *s = o->s;
    P57BD0 *t = fn_8001E05C(s->p4);
    U57BD0 *u = t->work->u;
    switch (o->state) {
    case 0:
        fn_80040150(s->d->d10, s->p4, s->d->s1c, &s->f8);
        o->state = 1;
        break;
    case 1:
        if (s->cnt < s->d->s18) {
            break;
        }
        if (!(u->ff0 & 0x40000000)) {
            fn_80071CF0((void *)(&t->work->v1c), (void *)(&s->vc));
            fn_800614FC((void *)(&t->work->v28), (void *)(&s->v18));
            u->ff0 |= 0x40000000;
            s->f28 = 1;
        } else {
            s->f28 = 0;
        }
        u->f1fc = s->f8;
        o->state = 2;
    case 2:
        if (s->cnt >= s->d->s1a) {
            if (s->f28 != 0) {
                fn_80071CF0((void *)(&s->vc), (void *)(&s->p4->work->v1c));
                fn_800614FC((void *)(&s->v18), (void *)(&s->p4->work->v28));
                u->ff0 &= ~0x40000000;
            }
            u->f1fc = 0;
            o->state = 0xfa;
        }
        if (lbl_80347394 != 0 && (lbl_80347394->work->f3c & 0x40) && s->f8 != 0) {
            V57BD0 a;
            V57BD0 b = lbl_802AD3B8;
            fn_80061518((void *)(&a), (void *)(&b), (void *)(s->f8));
        }
        break;
    case 0xf9:
    case 0xfa:
        fn_800400D8(s->d->d10, s->p4, s->d->s1c, &s->f8);
        o->flags |= 0x40;
        (*(H57BD0*)&lbl_8030A10C).count--;
        return;
    }
    s->cnt = s->cnt + 1;
    fn_80037FD8((void *)(s->d), (void *)(&o->state));
}

void fn_8006065C(O6065C *o) {
    S6065C *s = o->s;
    u8 *w = s->p4->work->u->p154 + s->d->s18 * 0x34;
    switch (o->state) {
    case 0: {
        s32 n;
        s->c = fn_8022E258(w, 0, 0, 0);
        s->e = s->e + fn_8022E258(w, 0, 1, 0);
        n = s->c + s->e;
        if (n == 0) {
            o->state = 0xfa;
            return;
        }
        fn_80061F58(&s->p8, n * 4, 0);
        fn_8022E258(w, s->p8, 0, 0);
        fn_8022E258(w, s->p8 + s->c, 1, 0);
        o->state = 1;
        break;
    }
    case 1:
        if (s->cnt < s->d->s14) {
            break;
        }
        fn_8022F580(w, 0x800, 0);
        fn_8022E4CC(w, -0x100, 0, 1, 0, 0);
        fn_8022E4CC(w, -0x100, 0, 1, 1, 0);
        o->state = 2;
        break;
    case 2:
        if (s->cnt < s->d->s16) {
            break;
        }
        fn_8022E258(w, s->p8, 0, 1);
        fn_8022E258(w, s->p8 + s->c, 1, 1);
        o->state = 0xfa;
        break;
    case 0xf9:
        fn_8022E258(w, s->p8, 0, 1);
        fn_8022E258(w, s->p8 + s->c, 1, 1);
    case 0xfa:
        if (s->p8 != 0) {
            fn_801E17E0(s->p8);
        }
        o->flags |= 0x40;
        (*(H6065C*)&lbl_8030A10C).count--;
        return;
    }
    s->cnt = s->cnt + 1;
    fn_80037FD8((void *)(s->d), (void *)(&o->state));
}

static inline void *crew_6EB88(char *name) {
    s16 j;
    for (j = 0; (*(Ent6EB88 **)&lbl_80347398)[j].f0 > 0; j++) {
        if ((*(Ent6EB88 **)&lbl_80347398)[j].f0 == 9999999 && fn_8025EF88((void *)(name), (void *)((*(Ent6EB88 **)&lbl_80347398)[j].f8)) == 0) {
            return (*(Ent6EB88 **)&lbl_80347398)[j].f4;
        }
    }
    return 0;
}

static inline s32 iscr_6EB88(s8 *s) {
    if (s[0] == 'c' || s[0] == 'C') {
        if (s[1] == 'r' || s[1] == 'R') {
            return 1;
        }
    }
    return 0;
}

void fn_8006EB88(char *a, char *b, Out6EB88 *out) {
    char buf[0x40];
    char buf2[0x40];
    s32 v;
    s16 i;
    if (a[0] != '/') {
        fn_8025F120(buf, "/");
        fn_8025F0B0((void *)(buf), (void *)(a));
        fn_8025F0B0((void *)(buf), (void *)(b));
    } else {
        fn_8025CB24(buf, "%s%s", a, b);
    }
    i = 0;
    if (iscr_6EB88((s8 *)b)) {
        void *found;
        fn_8025CB24(buf2, "%s.MLD", b);
        found = crew_6EB88(buf2);
        if (found != 0) {
            out->f8 = fn_801DB124(found);
        } else {
            fn_801DBE1C(lbl_802B06DC);
        }
    } else {
        fn_80046BB0((void *)(b), (void *)(&v));
        if ((*(H6EB88*)&lbl_8030A10C).pf8 != 0) {
            out->f8 = fn_801DB124((*(H6EB88*)&lbl_8030A10C).pf8);
            (*(H6EB88*)&lbl_8030A10C).pf8 = 0;
        } else {
            Ent6EB88 *p;
            s32 f;
            Ent6EB88 *tbl;
            p = tbl = (*(Ent6EB88 **)&lbl_80347398);
            for (; (f = p->f0) > 0; p++, i++) {
                if (v == f) {
                    void *q = tbl[i].f4;
                    if (q != 0) {
                        out->f8 = fn_801DB124(q);
                    }
                    break;
                }
            }
        }
    }
    if (out->f8 == 0) {
        out->f8 = fn_801DB244(buf);
    }
    fn_8006CF54(out);
}

void fn_80073D0C(void) {
}

void fn_80073D10(void) {
}

void fn_80073D14(void) {
}

void fn_80071CF0(V3 *src, V3 *dst) {
    dst->x = src->x;
    dst->y = src->y;
    dst->z = src->z;
}

void fn_8006EA90(s32 a, void *b, s32 c) {
    fn_8006E924(a, b, (void *)c, 0);
}

s32 fn_8006DC6C(void)

{
    s32 r;
    ObjA *obj;

    if (*(u32 *)(lbl_8030A10C + 0x6C) & 0x80000000) {
        r = 0;
    } else {
        *(u32 *)(lbl_8030A10C + 0x6C) |= 0x80000000;
        r = 1;
    }
    if (r == 0) {
        return 0;
    }
    obj = fn_802268E8(lbl_803475A8, fn_8006E00C);
    fn_80061F58(&obj->sub, 0xac, 0);
    obj->sub->v4 = (u32)lbl_80347398;
    return 1;
}
