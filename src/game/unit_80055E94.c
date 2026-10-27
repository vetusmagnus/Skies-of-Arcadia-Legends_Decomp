#include "types.h"
#include "ninja.h"
#include "game/drawstate.h"
/* One declaration per global / prototype. Tk and Chr tables are read through raw offsets
   (same offsets and widths as the per-function struct views they replace). */
typedef struct Lim { u8 pad[6]; s16 x6; s16 x8; s16 xa; } Lim;
typedef struct Node {
    u8 pad0[4];
    s16 count;           /* 0x04 reference count */
    u8 pad6[2];
    u32 x8;              /* 0x08 */
    u8 name[0x28];       /* 0x0C */
    struct Node* prev;   /* 0x34 */
    struct Node* x38;    /* 0x38 next */
    u8 pad3c[8];
} Node;
typedef struct { void *ptr; s8 id; u8 kind; s16 s; u8 pad8[8]; } Slot_8030A10C;
typedef struct {
    u32 f0;
    u8 pad4[0x64];
    u32 f68;
    u32 f6c;
    u8 pad70[0xCC - 0x70];
    Slot_8030A10C e[2];
    u8 pad_ec[0xF8 - 0xEC];
    void *pf8;
    u8 padfc[0x104 - 0xFC];
    u32 a104[12];
    u32 a134[12];
    u8 pad164[4];
    void *f168;
    u8 p16c[2];
    u8 b16e;
    u8 pad16f[0x1C4 - 0x16F];
    s32 count;
    u8 pad1c8[4];
    u32 f1cc;
} Sys_8030A10C;
extern Sys_8030A10C lbl_8030A10C;
typedef struct WorkRec {
    u8 pad0[4];
    u32 x04;
    u8 pad8[0x3c - 8];
    s32 x3c;
    s32 x40;
    s16 x44;
    s16 x46;
    s16 x48;
} WorkRec;
typedef struct TkRec {
    u8 pad0[0x24];
    WorkRec *work;
} TkRec;
typedef struct ChrRec {
    u8 pad0[0xc];
    s16 x0c;
    s16 flags;
    u8 pad10[4];
    s32 x14;
    s32 x18;
    u32 bits;
    u8 pad20[0x82 - 0x20];
    s16 x82;
    u8 pad84[0xfe - 0x84];
    s8 xfe;
    s8 xff;
    u8 pad100[0xc];
    s16 x10c;
} ChrRec;
extern TkRec *lbl_80309700[12];
extern ChrRec *lbl_80309DE4[12];
typedef struct Ent6EB88 {
    s32 f0;
    void *f4;
    char f8[0x10];
    s32 f18;
} Ent6EB88;
extern Ent6EB88 *lbl_80347398;
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
typedef struct ChrState { s32 x0; s8 x4; u8 pad5; s16 x6; s8 x8; u8 pad9[4]; u8 xd; u8 xe; u8 padf[0x11]; } ChrState;
extern ChrState lbl_80309174[12];
typedef struct Row16 { u8 pad[4]; u8 x4; u8 pad5[3]; s8 x8; u8 pad9[7]; } Row16;
extern Row16 lbl_80309730[12];
typedef struct Vec3 { f32 x; f32 y; f32 z; } Vec3;
typedef struct Ent { s32 x0; u32 x4; s32 x8; s32 xc; } Ent;
typedef struct Hdr { u8 pad0[4]; s16 count; u8 pad6[2]; Ent e[1]; } Hdr;
void fn_800D208C(void *obj, f32 f);
void fn_8006AFD0(s16 i, void *a, void *b, s32 c);
extern void fn_8006AC68(s16 i);
extern void fn_800696A8(s32 a, s16 i, s32 b, s8 v);
s16 fn_8006E924(char* path, char* name, Node** out, void* key);
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
extern char lbl_802B0678[];
extern char lbl_802B068C[];
extern void fn_8001C6CC(void *, s16, s16, char *);
extern void fn_80061048(char *);
extern s32 fn_8025CB24(char *, char *, ...);
extern void *fn_801CC1B4(char *);
extern s32 fn_801CC1A4(void *);
extern void *fn_801CC0A0(void *);
typedef struct Entry {
    u32 id;
    u8 pad4[0xc];
} Entry;
typedef struct EntryList {
    u8 pad0[4];
    s16 count;      /* 0x04 */
    u8 pad6[2];
    Entry entries[1]; /* 0x08 */
} EntryList;
BOOL fn_8006E5BC(EntryList *list);
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
    u8 pad24[0x3c - 0x24];
    f32 v[3];
    u8 pad48[0x7c - 0x48];
    u32 f7c;
    u8 pad80[8];
    s16 x88;
    s16 x8a;
    s16 x8c;
    s16 x8e;
    s16 x90;
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
extern V5BF30 lbl_802AD3C8;
extern V5BF30 lbl_802AD3D4[7];
extern void fn_80037FD8(void *, u8 *);
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
extern s32 fn_8022E258(void *, void *, u8, s32);
extern void fn_80061F58(void *, s32, s32);
extern void fn_8022F580(void *, s32, s32);
extern void fn_8022E4CC(void *, s32, s32, s32, s32, s32);
typedef struct Out6EB88 {
    u8 pad0[8];
    void *f8;
} Out6EB88;
extern char lbl_802B06DC[];
extern void *fn_801DB124(void *);
extern void *fn_801DB244(char *);
extern void fn_801DBE1C(char *, ...);
extern void fn_8006CF54(Out6EB88 *);
typedef struct Un {
    u8 id;
    u8 pad1[0x153];
    s32 f154;
} Un;
typedef struct Wk {
    u8 pad0[8];
    s32 f8;
    u8 padc[0x44 - 0xc];
    u8 b44;
    u8 pad45[7];
    Un *unit;
} Wk;
typedef struct Nd {
    u8 pad0[0x24];
    Wk *wk;
} Nd;
typedef struct Tb {
    u8 pad0[6];
    s16 s6;
    u8 pad8[0xc];
    s16 s14;
} Tb;
typedef struct S {
    s16 cnt;
    u8 b2;
    u8 pad3;
    void *p4;
    void *p8;
    s32 fc;
    Nd *node;
    Tb *tab;
} S;
typedef struct W {
    void *p0;
    u8 pad4[4];
    s32 f8;
    u8 padc[0x44 - 0xc];
    u8 b44;
    u8 pad45[7];
    S *s;
} W;
typedef struct O {
    u8 pad0[0x18];
    u8 flags;
    u8 state;
    u8 pad1a[10];
    W *w;
} O;
typedef struct G {
    u8 pad[0x78];
    u32 f78;
} G;
extern G lbl_8030A6D4;
extern void fn_80074968(void *, void *);
extern void fn_80073D3C(void *, s32, s32, void *);
extern void fn_80014D1C(Nd *, s32);
extern s32 fn_8001BCC8(s32, Nd *);
typedef struct Un_80061FCC {
    u8 pad0[0xf0];
    u32 ff0;
} Un_80061FCC;
typedef struct Wk_80061FCC {
    u8 pad0[0x4c];
    Un_80061FCC *unit;
} Wk_80061FCC;
typedef struct Nd_80061FCC {
    u8 pad0[0x24];
    Wk_80061FCC *wk;
} Nd_80061FCC;
typedef struct Tb_80061FCC {
    u8 pad0[0x10];
    s16 s10;
    s16 s12;
    s16 s14;
} Tb_80061FCC;
typedef struct S_80061FCC {
    u8 pad0[4];
    Tb_80061FCC *tab;
    f32 f8;
    s16 c;
} S_80061FCC;
typedef struct G_80061FCC {
    u8 pad0[0x6c];
    f32 f6c;
    u8 pad70[0x92 - 0x70];
    s16 s92;
} G_80061FCC;
typedef struct O_80061FCC {
    u8 pad0[0x18];
    u8 flags;
    u8 state;
    u8 pad1a[10];
    S_80061FCC *s;
} O_80061FCC;
extern Nd_80061FCC *fn_80021658(s32);
typedef struct Un_8005C480 {
    u8 id;
    u8 pad1[5];
    s16 s6;
} Un_8005C480;
typedef struct Wk_8005C480 {
    u8 pad0[0x4c];
    Un_8005C480 *unit;
} Wk_8005C480;
typedef struct Nd_8005C480 {
    u8 pad0[0x24];
    Wk_8005C480 *wk;
} Nd_8005C480;
typedef struct Ad {
    u8 pad0[0x1c];
    s16 s1c;
} Ad;
typedef struct S_8005C480 {
    s16 cnt;
    s16 idx;
    Nd_8005C480 *p;
    Ad *a;
} S_8005C480;
typedef struct O_8005C480 {
    u8 pad0[0x18];
    u8 flags;
    u8 state;
    u8 pad1a[10];
    S_8005C480 *s;
} O_8005C480;
extern void fn_8006D954(s32);
extern void fn_8006D8DC(s32);
extern void fn_80215F94(void *);
extern s32 fn_80216F48(void *);
extern void fn_80217830(void *);
typedef struct Un_8005D614 {
    u8 pad0[2];
    s16 s2;
    u8 pad4[0x4c];
    u32 f50;
    u8 pad54[0x164 - 0x54];
    f32 f164;
    u8 pad168[0x296 - 0x168];
    u8 b296;
} Un_8005D614;
typedef struct Wk_8005D614 {
    u8 pad0[0x4c];
    Un_8005D614 *unit;
} Wk_8005D614;
typedef struct Nd_8005D614 {
    u8 pad0[0x24];
    Wk_8005D614 *wk;
} Nd_8005D614;
typedef struct Tb_8005D614 {
    u8 pad0[0x10];
    u32 f10;
    s16 s14;
    s16 s16;
    f32 f18;
    f32 f1c;
    s16 s20;
    s16 s22;
    s16 s24;
    s16 s26;
    s16 s28;
    s16 s2a;
} Tb_8005D614;
typedef struct S_8005D614 {
    s16 cnt;
    u8 pad2[2];
    Nd_8005D614 *p;
    Nd_8005D614 *p8;
    u8 pc;
    u8 pd;
    u8 pade[2];
    u32 f10;
    u8 pad14[4];
    f32 f18;
    u32 f1c;
    Tb_8005D614 *tab;
} S_8005D614;
typedef struct O_8005D614 {
    u8 pad0[0x18];
    u8 flags;
    u8 state;
    u8 pad1a[10];
    S_8005D614 *s;
} O_8005D614;
extern s32 lbl_8034737C;
extern void fn_8002FEB0(void *, void *, s32);
extern void fn_8002F53C(void);
extern void fn_802A75C8(f32, f32, f32);
extern void fn_802A75B0(f32, f32);
extern void fn_802A7598(f32, f32, f32);
extern void fn_802A210C(f32, f32, f32);
extern void fn_802A20F4(f32, f32);
extern void fn_802A20DC(f32, f32, f32);
typedef struct TblEnt_8006B71C {
    void *f0;
    void *f4;
    u32 f8;
    u8 fc;
    u8 pad[3];
} TblEnt_8006B71C;
extern void fn_802872C4(s32);
extern void fn_80287274(s32, s32);
extern void fn_8028B870(s32);
extern void fn_8028B820(s32, s32);
extern void fn_8006C9E4(void *, s32, s16 *, s32 *);
typedef struct Tab_8006CEEC {
    u32 count;
    u32 v[1];
} Tab_8006CEEC;
typedef struct Ent_8006CEEC {
    u8 pad0[0x1c];
    Tab_8006CEEC *x1c;
    u8 pad20[0x68 - 0x20];
} Ent_8006CEEC;
typedef struct Ctx_8006CEEC {
    u8 pad0[4];
    Ent_8006CEEC *x4;
} Ctx_8006CEEC;
typedef struct Node_8006D888 {
    s32 x0;
    s32 x4;
    u8 pad8[8];
    struct Node_8006D888 *x10;
} Node_8006D888;
extern Node_8006D888 *lbl_8034739C;
extern f64 atan2(f64 y, f64 x);
extern f32 lbl_80348A1C;
typedef struct {
    u8 pad0[0x1c];
    f32 x;
    u8 pad1[4];
    f32 y;
} Pt;
extern f32 fn_80291A5C(f32 x);
extern void njUnitVector(NJS_VECTOR *v);
typedef struct Ent80055EB8 {
    u8 pad0[0x18];
    u8 flags;
} Ent80055EB8;
typedef struct Wrap80055EB8 {
    u8 pad0[0x24];
    struct Inner80055EB8 *inner;
} Wrap80055EB8;
typedef struct Inner80055EB8 {
    u8 pad0[0x4c];
    void *sub;
} Inner80055EB8;
typedef struct Gl80060AB4 {
    u8 pad0[0x6c];
    u32 flags;
    u8 pad1[0xf8];
    void *p168;
    u8 p16c[2];
    u8 b16e;
} Gl80060AB4;
extern void fn_801D6CBC(void *p, void *q);
extern char lbl_802B06C0[];
typedef struct WorkRec_8006A114 {
    u8 pad0[4];
    u32 x04;
    u8 pad8[0x3c - 8];
    s32 x3c;
    s32 x40;
    s16 x44;
    s16 x46;
    s16 x48;
    s16 x4a;
} WorkRec_8006A114;
typedef struct TkRec_8006A114 {
    u8 pad0[0x24];
    WorkRec_8006A114 *work;
} TkRec_8006A114;
typedef struct { s8 pad[0x18]; u8 x18; u8 pad19[0x30 - 0x19]; } T30;
extern T30 lbl_802C4BF0[];
extern s16 fn_80078354(s16);
extern void fn_8021A1C4(s8 *buf);
typedef struct { u8 pad[0x14]; s16 x14; s16 x16; } D_8005CBA4;
typedef struct { u8 pad0[4]; s16 cnt; u8 pad6[2]; D_8005CBA4 *d; } S_8005CBA4;
typedef struct { u8 pad0[0x18]; u8 flags; u8 state; u8 pad1A[10]; S_8005CBA4 *s; } O_8005CBA4;
typedef struct {
    u8 pad0[0x6c];
    u32 f6c;
    u8 pad70[0x1c4 - 0x70];
    s32 count;
} Sys_8030A10C_8005CBA4;
typedef struct Vec3f { f32 x, y, z; } Vec3f;
typedef struct { u8 pad[0x1c4]; s32 count; } Sys_8030A10C_8005A694;
typedef struct { u8 pad0[0x4c]; u8 pad4c[0x154 - 0x4c]; } Dummy_8005A694;
typedef struct W_8005A694 { u8 f0; u8 pad1[0x153]; u8 *f154; } W_8005A694;
typedef struct { u8 pad0[0x4c]; W_8005A694 *w; } Q_8005A694;
typedef struct { u8 pad0[0x24]; Q_8005A694 *q; } P4_8005A694;
typedef struct { u8 pad0[0x18]; s16 f18; s16 f1a; s16 f1c; } C_8005A694;
typedef struct S_8005A694 {
    s8 f0;
    u8 pad1[3];
    P4_8005A694 *f4;
    u8 *f8;
    C_8005A694 *fc;
} S_8005A694;
typedef struct O_8005A694 {
    u8 pad0[0x18];
    u8 flags;
    u8 state;
    u8 pad1A[10];
    S_8005A694 *s;
} O_8005A694;
extern void fn_8022EF58(void *p, s32 v);
extern s32 fn_800179E4(s32 id);
extern void fn_8023080C(void *p, s16 *v, s32 n);
typedef struct { u8 pad[0x1c4]; s32 count; } Sys_8030A10C_8005BAA0;
typedef struct { u8 pad0[0x3c]; u32 f3c; } T_8005BAA0;
typedef struct S_8005BAA0 {
    s16 f0;
    u8 pad2[0x16];
    T_8005BAA0 *f18;
    u8 pad1c[0x54 - 0x1c];
    u8 f54[8];
    s32 f5c;
    u8 pad60[8];
    s16 f68;
    s16 f6a;
} S_8005BAA0;
typedef struct O_8005BAA0 {
    u8 pad0[0x18];
    u8 flags;
    u8 state;
    u8 pad1A[10];
    S_8005BAA0 *s;
} O_8005BAA0;
typedef struct Sys_8030A10C_8005CCB0 { u8 pad[0x1c4]; s32 count; } Sys_8030A10C_8005CCB0;
typedef struct Lim_8005CCB0 { u8 pad[0x14]; s16 x14; s16 x16; } Lim_8005CCB0;
typedef struct St { u8 pad0[4]; s16 t; u8 pad6[2]; Lim_8005CCB0* lim; } St;
typedef struct Tk_8005CCB0 { u8 pad0[0x18]; u8 flags; u8 state; u8 pad1a[0xa]; St* s; } Tk_8005CCB0;
extern s32 lbl_80347508;
extern f32 lbl_80347510;
extern void fn_801CBC30(void);
extern void fn_801CBBAC(f32);
extern void fn_801CBB9C(f32);
extern void fn_801CBBF8(void);
typedef struct Lim_8006EF48 { u8 pad[6]; s16 x6; s16 x8; s16 xa; } Lim_8006EF48;
typedef struct Stat { u8 pad[6]; s16 x6; u8 pad8[0x78 - 8]; } Stat;
extern s16 lbl_80309DCC[];
extern Stat lbl_8030B4D4[];
extern s32 fn_80078610(s8 i);
typedef struct S62E94 {
    void *p0;
    f32 f4;
    s16 s8;
} S62E94;
typedef struct O62E94 {
    u8 pad0[0x18];
    u8 flags;
    u8 state;
    u8 pad1A[10];
    S62E94 *s;
} O62E94;
typedef struct { u8 pad0[4]; u32 x4; } Src_80062318;
typedef struct {
    u8 pad0[6];
    s16 kind;
    u8 pad8[0x5c - 8];
    Src_80062318* x5c;
    u8 pad60[8];
    f32 x68;
} Work_80062318;
typedef struct { u8 pad0[0x4c]; Work_80062318* w; } Body_80062318;
typedef struct { u8 pad0[0x24]; Body_80062318* body; } Tgt_80062318;
typedef struct {
    Tgt_80062318* target;
    s16 x4;
    s16 x6;
    s16 x8;
    s16 xa;
} S_80062318;
typedef struct {
    u8 pad0[0x18];
    u8 flags;
    u8 state;
    u8 pad1A[10];
    S_80062318* s;
} O_80062318;
extern s32 lbl_80347344;
extern s32 lbl_80347328;
extern s16 lbl_80347378;
extern s16 lbl_80347376;
extern s16 lbl_80347374;
extern u8 lbl_80347340;
extern void* lbl_80347320;
extern void fn_801CBBBC(void);
extern void fn_80029070(void);
extern void* fn_801E1C7C(s32 size);

void fn_80055E94(u8 *p) {
    p[0x18] |= 0x40;
    lbl_8030A10C.count -= 1;
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
    TkRec *p = lbl_80309700[idx];
    p->work->x44 = v;
}

void fn_80069684(s16 a, void *b, s32 c) {
    fn_8006AFD0(a, b, (void *)c, 0);
}

void fn_80069CD8(void* a, s16 i, void* b, s8 v) {
    lbl_80309700[i]->work->x3c = -1;
    if (lbl_80309DE4[i]->bits & 0x6100) {
        lbl_80309700[i]->work->x44 = -1;
    } else {
        lbl_80309700[i]->work->x44 = v;
    }
}

void fn_8006A7DC(s32 a, s16 i, s32 b, s8 v) {
    ChrRec *c = lbl_80309DE4[i];
    if (c->bits & 0x6950) {
        lbl_80309700[i]->work->x44 = -1;
        lbl_80309700[i]->work->x3c = -1;
    } else {
        fn_800696A8(a, i, b, v);
    }
    if (v == lbl_80309700[i]->work->x44) {
        c->x0c = lbl_80309DE4[(s16)a]->x82;
    }
}

void fn_8006A8A8(s32 a, s16 i, s32 b, s8 v) {
    ChrRec *c = lbl_80309DE4[i];
    if (c->bits & 0x6950) {
        lbl_80309700[i]->work->x44 = -1;
        lbl_80309700[i]->work->x3c = -1;
    } else {
        fn_800696A8(a, i, b, v);
    }
    if (v == lbl_80309700[i]->work->x44) {
        c->x0c = lbl_80309DE4[(s16)a]->x82;
    }
}

void fn_8006A974(s32 a, s16 i, s32 b, s8 v) {
    ChrRec *c = lbl_80309DE4[i];
    if (c->bits & 0x6950) {
        lbl_80309700[i]->work->x44 = -1;
        lbl_80309700[i]->work->x3c = -1;
    } else {
        fn_800696A8(a, i, b, v);
    }
    if (v == lbl_80309700[i]->work->x44) {
        c->x0c = lbl_80309DE4[(s16)a]->x82;
    }
}

void fn_8006B3C4(void *a, s16 idx) {
    ChrRec *p = lbl_80309DE4[idx];
    p->bits |= 1;
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
    lbl_80347398->f0 = -1;
}

s32 fn_8006C8C4(void) {
    return lbl_8030A10C.f68 == 0;
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

    if (lbl_8030A10C.f6c & 0x80000000) {
        r = 0;
    } else {
        lbl_8030A10C.f6c |= 0x80000000;
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

void fn_8006EA70(char* path, char* name, Node** out, void* key) {
    fn_8006E924(path, name, out, key);
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
        lbl_8030A10C.f6c |= 0x100000;
        lbl_8030A10C.f168 = 0;
    } else {
        lbl_8030A10C.f6c &= ~0x100000;
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
    lbl_80309700[i]->work->x3c = -1;
    if (lbl_80309DE4[i]->bits & 0x6100) {
        lbl_80309700[i]->work->x44 = -1;
    } else {
        lbl_80309700[i]->work->x44 = v;
    }
}

void fn_80069008(s16 i) {
    fn_8006AC68(i);
    lbl_80309700[i]->work->x44 = 0;
    lbl_80309700[i]->work->x3c = lbl_80309DE4[i]->x14;
}

void fn_80069070(s16 i, void* a, void* b) {
    fn_8006AFD0(i, a, b, 0);
    lbl_80309700[i]->work->x44 = 0;
    lbl_80309700[i]->work->x3c = lbl_80309DE4[i]->x14;
}

void fn_800690DC(void* a, s16 i, void* b, s8 v) {
    lbl_80309700[i]->work->x3c = (s16)(lbl_80309DE4[i]->x18 - lbl_80309DE4[i]->x14);
    lbl_80309700[i]->work->x40 = (s16)(lbl_80309DE4[i]->xff - lbl_80309DE4[i]->xfe);
    lbl_80309700[i]->work->x44 = v;
}

void fn_80069AE4(void* a, s16 idx, void* b, s8 v) {
    lbl_80309700[idx]->work->x3c = lbl_80309DE4[idx]->x18 - lbl_80309DE4[idx]->x14;
    lbl_80309700[idx]->work->x44 = v;
    lbl_80309174[idx].x8 = 1;
    lbl_80309730[idx].x8 = 1;
}

void fn_80069D34(void* a, s16 idx, void* b, s8 v) {
    lbl_80309700[idx]->work->x3c = lbl_80347390->x6 - lbl_80347390->x8;
    lbl_80309700[idx]->work->x44 = v;
    lbl_80309174[idx].x8 = 1;
    lbl_80309730[idx].x8 = 1;
}

void fn_80069FF4(s32 a, s16 i, s32 b, s8 v) {
    lbl_80309700[i]->work->x3c = -1;
    if (lbl_80309DE4[i]->bits & 0x2100) {
        lbl_80309700[i]->work->x44 = -1;
    } else if (v == 0x1e) {
        lbl_80309700[i]->work->x44 = v;
    } else {
        fn_800696A8(a, i, b, v);
    }
}

void fn_8006A388(s32 a, s16 i, s32 b, s8 v) {
    lbl_80309700[i]->work->x3c = -1;
    if (lbl_80309DE4[i]->bits & 0x2100) {
        lbl_80309700[i]->work->x44 = -1;
    } else {
        lbl_80309700[i]->work->x44 = v;
    }
}

void fn_8006A70C(s32 a, s16 i, s32 b, s8 v) {
    if (lbl_80309DE4[i]->bits & 0x7150) {
        lbl_80309700[i]->work->x44 = -1;
        lbl_80309700[i]->work->x3c = -1;
    } else {
        fn_800696A8(a, i, b, v);
    }
}

void fn_8006A774(s32 a, s16 i, s32 b, s8 v) {
    if (lbl_80309DE4[i]->bits & 0x6350) {
        lbl_80309700[i]->work->x44 = -1;
        lbl_80309700[i]->work->x3c = -1;
    } else {
        fn_800696A8(a, i, b, v);
    }
}

void fn_8006AB04(s32 a, s16 i, s32 b, s8 v) {
    if (lbl_80309DE4[i]->bits & 0x2150) {
        lbl_80309700[i]->work->x44 = -1;
        lbl_80309700[i]->work->x3c = -1;
    } else {
        fn_800696A8(a, i, b, v);
    }
}

void fn_8006AC00(s32 a, s16 i, s32 b, s8 v) {
    fn_800696A8(a, i, b, v);
    if (lbl_80309700[i]->work->x44 != -1) {
        lbl_80309730[i].x8 = 5;
    }
}

void fn_8006AD44(s32 a, s16 i, s32 b, s8 v) {
    if (lbl_80309DE4[i]->bits & 0x61d0) {
        lbl_80309700[i]->work->x44 = -1;
        lbl_80309700[i]->work->x3c = -1;
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
    TkRec *t = lbl_80309700[lbl_80347334];
    if (t == 0) {
        lbl_8034733C = 5;
        lbl_80347338 = 0;
        fn_80015554();
    } else if (t->work->x04 & 0x13) {
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
        lbl_8030A10C.count--;
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
        lbl_8030A10C.count--;
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
                lbl_80346BD8->v[0] = 0.0f;
                lbl_80346BD8->v[1] = 0.0f;
                lbl_80346BD8->v[2] = 0.0f;
                o->state = 3;
            }
        }
    }
    if (lbl_80346BD8->f7c & 0x40000000) {
        return;
    }
    switch (o->state) {
    case 0:
        o->state = 1;
    case 1:
        lbl_80346BD8->v[0] = lbl_80346BD8->v[0] + s->v[0];
        lbl_80346BD8->v[1] = lbl_80346BD8->v[1] + s->v[1];
        lbl_80346BD8->v[2] = lbl_80346BD8->v[2] + s->v[2];
        break;
    case 2: {
        s32 i;
        s32 n = 0;
        for (i = 0; i < 3; i++) {
            f32 x = lbl_80346BD8->v[i];
            if (x > 0.0f) {
                lbl_80346BD8->v[i] += 10.0f;
                if (lbl_80346BD8->v[i] >= 360.0f) {
                    lbl_80346BD8->v[i] = 0.0f;
                    n++;
                }
            } else {
                lbl_80346BD8->v[i] = x - 10.0f;
                if (lbl_80346BD8->v[i] <= 0.0f) {
                    lbl_80346BD8->v[i] = 0.0f;
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
        lbl_8030A10C.count--;
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
        lbl_8030A10C.f6c &= 0x7fffffff;
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
                lbl_8030A10C.a104[s->s8c] = fn_80035C38(s->p4[s->s8c - 1].f4);
                lbl_8030A10C.a134[s->s8c] = s->p4[s->s8c - 1].f18;
            }
            o->state = 1;
        }
        break;
    case 4:
        lbl_8030A10C.f6c &= 0x7fffffff;
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
        lbl_8030A10C.f6c &= 0x7fffffff;
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
        lbl_8030A10C.count--;
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
        lbl_8030A10C.count--;
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
        if (lbl_8030A10C.pf8 != 0) {
            out->f8 = fn_801DB124(lbl_8030A10C.pf8);
            lbl_8030A10C.pf8 = 0;
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

void fn_8006EA90(char* path, char* name, Node** out) {
    fn_8006E924(path, name, out, 0);
}

s32 fn_8006DC6C(void)

{
    s32 r;
    ObjA *obj;

    if (lbl_8030A10C.f6c & 0x80000000) {
        r = 0;
    } else {
        lbl_8030A10C.f6c |= 0x80000000;
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

void fn_8006BD84(s16 idx, void *a, void *b) {
    lbl_80309E88[idx].f0 = a;
    lbl_80309E88[idx].f4 = b;
    lbl_80309E88[idx].f8 = 0;
    lbl_80309E88[idx].fc = 1;
}

s32 fn_80061114(f32 *v, f32 target, f32 step)
{
    *v += step;
    if (step > 0.0f) {
        if (*v >= target) {
            *v = target;
            return 1;
        }
    } else {
        if (*v <= target) {
            *v = target;
            return 1;
        }
    }
    return 0;
}

void fn_8006ADAC(void* a, s16 idx, void* b, s8 v) {
    s32 d = lbl_80309DE4[idx]->x18 - lbl_80309DE4[idx]->x14;
    lbl_80309174[idx].x8 = 1;
    lbl_80309730[idx].x8 = 1;
    lbl_80309700[idx]->work->x3c = d;
    lbl_80309700[idx]->work->x44 = v;
}

s32 fn_80056F30(f32 *val, s16 frames) {
    if (frames == 0) {
        return 0;
    }
    *val += 1.0f / frames;
    if (*val >= 0.0f) {
        *val = 0.0f;
        return 0;
    }
    return 1;
}

BOOL fn_8006E5BC(EntryList *list) {
    s16 count = list->count;
    Entry *e = list->entries;
    u32 id;
    s16 i;
    s16 j;
    if (count <= 1) {
        return TRUE;
    }
    for (i = 0; i < count - 1; i++) {
        id = e[i].id;
        for (j = i + 1; j < count; j++) {
            if (id == e[j].id) {
                return FALSE;
            }
        }
    }
    return TRUE;
}

void fn_8005F640(O *o) {
    S *s;
    W *w;
    Un *u;
    w = o->w;
    s = w->s;
    u = s->node->wk->unit;
    switch (o->state) {
    case 0:
        o->state = 1;
    case 1:
        if (s->cnt < s->tab->s14) {
            break;
        }
        o->state = 2;
        w->b44 = 4;
        s->fc = s->node->wk->f8;
        s->b2 = s->node->wk->b44;
        fn_80074968(w->p0, &s->p8);
        fn_80073D3C(s->p8, u->f154, 0, &s->p4);
        s->node->wk->f8 = w->f8;
        s->node->wk->b44 = 4;
    case 2:
        if ((*(void **)&lbl_80347394) != 0) {
            if (lbl_8030A6D4.f78 & 0x20) {
                o->state = 0xfa;
            }
        } else {
            if (fn_80014C90(u->id, 0x10) == 0) {
                o->state = 0xfa;
            }
        }
        break;
    case 3:
        if (lbl_8030A10C.f1cc & 0x40) {
            o->state = 1;
            s->cnt = s->tab->s14;
        }
        break;
    case 0xfa:
        s->node->wk->f8 = s->fc;
        fn_80014D1C(s->node, -1);
        s->node->wk->b44 = s->b2;
        fn_80073D3C(s->p8, u->f154, 2, &s->p4);
        fn_801E17E0(s->p4);
        fn_801E17E0(s->p8);
        fn_801E17E0(s);
        o->flags |= 0x40;
        lbl_8030A10C.count--;
        return;
    }
    s->cnt++;
    if (s->tab->s6 & 0x2000) {
        switch (o->state) {
        case 2:
            if (fn_8001BCC8(*(s8 *)&u->id, s->node) == 0) {
                break;
            }
        default:
            lbl_8030A10C.f1cc |= 0x10;
        case 1:
            break;
        }
        if ((lbl_8030A10C.f1cc & 0x80) && !(lbl_8030A10C.f1cc & 0x40)) {
            switch (o->state) {
            case 1:
                o->state = 3;
            }
        }
    }
}

void fn_80061FCC(O_80061FCC *o) {
    S_80061FCC *s;
    Un_80061FCC *u;
    if ((*(G_80061FCC **)&lbl_80346BD8) == 0) {
        o->state = 0xfa;
    } else {
        s = o->s;
        u = fn_80021658((s8)(*(G_80061FCC **)&lbl_80346BD8)->s92)->wk->unit;
    }
    switch (o->state) {
    case 0:
        switch (s->tab->s10) {
        case 0:
            u->ff0 |= 0x80000000;
        }
        if (s->tab->s14 > 0) {
            s->f8 = 1.0f / (f32)s->tab->s14;
        } else {
            s->f8 = 1.0f;
        }
        if (s->tab->s12 != 0) {
            s->c = 0;
            o->state = 1;
        } else {
            s->c = 0;
            o->state = 3;
        }
        break;
    case 1:
        if ((lbl_8030A10C.f1cc & 0x80) && !(lbl_8030A10C.f1cc & 0x10)) {
            if (s->tab->s12 > s->c + 30) {
                s->c = 30;
                o->state = 2;
            }
        }
        if (s->c >= s->tab->s12 - 1) {
            s->c = 0;
            o->state = 3;
        }
        s->c++;
        break;
    case 2:
        s->c--;
        if (s->c == 0) {
            o->state = 3;
        }
        break;
    case 3:
        if (s->tab->s10 == 0) {
            (*(G_80061FCC **)&lbl_80346BD8)->f6c = (*(G_80061FCC **)&lbl_80346BD8)->f6c - s->f8;
            if ((*(G_80061FCC **)&lbl_80346BD8)->f6c <= -1.0f) {
                (*(G_80061FCC **)&lbl_80346BD8)->f6c = -1.0f;
            }
        } else {
            (*(G_80061FCC **)&lbl_80346BD8)->f6c = (*(G_80061FCC **)&lbl_80346BD8)->f6c + s->f8;
            if ((*(G_80061FCC **)&lbl_80346BD8)->f6c >= 0.0f) {
                (*(G_80061FCC **)&lbl_80346BD8)->f6c = 0.0f;
            }
        }
        if (s->c >= s->tab->s14) {
            o->state = 4;
        }
        s->c++;
        break;
    case 4:
        if (s->tab->s10 == 1) {
            u->ff0 &= 0x7fffffff;
        }
        o->state = 0xfa;
    case 0xfa:
        o->flags |= 0x40;
        lbl_8030A10C.count--;
        break;
    }
}

typedef struct Work6C124 { u8 pad0[4]; u32 recs; u8 pad8[0xa0]; u8 xa8; } Work6C124;
typedef struct Task6C124 { u8 pad0[0x24]; Work6C124* work; } Task6C124;
extern s8 fn_80020F68(void);
extern void fn_8006C124(void*);
extern void fn_8002FE10(void);
extern void fn_8002FD58(void);
extern char lbl_802B06A8[];
extern char lbl_802B06B4[];

/* Adds NAME to the loaded-name table lbl_80347398 (terminated by id -1, at most 0x80) unless present. */
inline void AddName(char* name) {
    Ent6EB88* recs = lbl_80347398;
    s16 i = 0;
    while (recs[i].f0 > 0) {
        if (fn_8025EF88(name, recs[i].f8) == 0) {
            return;
        }
        i++;
        if (i >= 0x80) {
            return;
        }
    }
    fn_8025F120(recs[i].f8, name);
    recs[i].f0 = 9999999;
    recs[i].f4 = 0;
    recs[i].f18 = 0;
    recs[i + 1].f0 = -1;
}

/* Sets the top bit of the battle flags word; 1 if it was clear. */
inline s32 SetOnce(void) {
    if (lbl_8030A10C.f6c & 0x80000000) {
        return 0;
    }
    lbl_8030A10C.f6c |= 0x80000000;
    return 1;
}

void fn_8006C5B4(void) {
    char buf[0x18];
    Task6C124* t;
    s8 c;

    lbl_80347398->f0 = -1;
    c = fn_80020F68();
    fn_8025CB24(buf, lbl_802B06A8, c);
    AddName(buf);
    if (SetOnce()) {
        t = (Task6C124*)fn_802268E8(lbl_803475A8, fn_8006C124);
        fn_80061F58(&t->work, 0xac, 0);
        t->work->recs = (u32)lbl_80347398;
        t->work->xa8 = 0;
    }
}

void fn_8006C710(s8 mode, u8 flag) {
    Task6C124* t;

    lbl_80347398->f0 = -1;
    if (mode == 0) {
        AddName(lbl_802B06B4);
        lbl_80347398->f4 = fn_8022ACA8(7);
    }
    fn_8002FE10();
    fn_8002FD58();
    if (SetOnce()) {
        t = (Task6C124*)fn_802268E8(lbl_803475A8, fn_8006C124);
        fn_80061F58(&t->work, 0xac, 0);
        t->work->recs = (u32)lbl_80347398;
        t->work->xa8 = flag;
    }
}

extern void* fn_801E1C7C(s32 size);

s16 fn_8006E924(char* path, char* name, Node** out, void* key) {
    Node* m;
    Node* n = lbl_803473A0;
    if (n->x8 == 0) {
        if (key == 0) {
            fn_8006EB88(path, name, (Out6EB88*)n);
        } else {
            n->x8 = (u32)fn_801DB124(key);
            fn_8006CF54((Out6EB88*)n);
        }
        fn_8025F120((char*)n->name, name);
        n->count = 1;
        *out = n;
        return n->count;
    }
    while (1) {
        if (n->x8 != 0 && fn_8025EF88(name, (char*)n->name) == 0) {
            *out = n;
            n->count++;
            return n->count;
        }
        if (n->x38 == 0) {
            break;
        }
        n = n->x38;
    }
    n->x38 = fn_801E1C7C(0x44);
    m = n->x38;
    memset(m, 0, 0x44);
    m->prev = n;
    if (key == 0) {
        fn_8006EB88(path, name, (Out6EB88*)m);
    } else {
        m->x8 = (u32)fn_801DB124(key);
        fn_8006CF54((Out6EB88*)m);
    }
    fn_8025F120((char*)m->name, name);
    m->count = 1;
    *out = m;
    return m->count;
}

typedef struct Ent80067CA4 {
    u8 pad0[4];
    s16 type;
    u8 pad6[0xa];
    f32 f10;
    f32 f14;
} Ent80067CA4;

typedef struct U80067CA4 {
    s8 slot;
    u8 pad1;
    s16 s2;
    u8 pad4[0xdc - 4];
    Ent80067CA4 *list;
    u8 pade0[0x128 - 0xe0];
    f32 f128;
    f32 f12c;
    u8 pad130[0x29c - 0x130];
} U80067CA4;

typedef struct Base80067CA4 {
    u8 d[0x4c];
} Base80067CA4;

typedef struct W80067CA4 {
    Base80067CA4 base;
    U80067CA4 *u;
    u8 pad50[8];
} W80067CA4;

typedef struct Tk80067CA4 {
    u8 pad0[0x24];
    W80067CA4 *work;
} Tk80067CA4;

typedef struct Src80067CA4 {
    u8 pad0[4];
    Base80067CA4 *base;
} Src80067CA4;

typedef struct Arg80067CA4 {
    u8 pad0[4];
    Src80067CA4 *src;
    u8 pad8[4];
    Ent80067CA4 *list;
} Arg80067CA4;

extern void *lbl_802DF2B8[18];
extern Tk80067CA4 *lbl_80309E24[14];

extern s16 fn_80020060(Ent80067CA4 *);

void fn_80067CA4(Arg80067CA4 *arg) {
    Ent80067CA4 *list = arg->list;
    Tk80067CA4 *task;
    U80067CA4 *u;
    W80067CA4 *w;
    Src80067CA4 *src = arg->src;
    s16 idx;
    idx = fn_80020060(list);
    while (idx < 0) {
    }
    task = (Tk80067CA4 *)fn_802268E8(lbl_803475A8, lbl_802DF2B8[list[idx].type]);
    fn_80061F58(&task->work, 0x58, 0);
    w = task->work;
    w->base = *src->base;
    fn_80061F58(&w->u, 0x29c, 0);
    u = w->u;
    u->list = list;
    u->f128 = list[idx].f14;
    u->f12c = list[idx].f10;
    if (lbl_80347394 == 0) {
        lbl_80309E24[12] = task;
        u->slot = 12;
        u->s2 = 0;
    } else {
        s8 i = 0;
        while (i < 12) {
            if (lbl_80309E24[i] == 0) {
                lbl_80309E24[i] = task;
                u->slot = i;
                u->s2 = 0;
                break;
            }
            i++;
        }
    }
}

typedef struct E10_72190 { u8 pad0[4]; void* x4; u8 pad8[8]; } E10_72190;
typedef struct E18_72190 { u8 pad0[4]; void* x4; u8 pad8[0x10]; } E18_72190;
typedef struct Obj_72190 {
    u8 pad0[0x94];
    u32 x94[15];
    void* xd0;
    u8 padd4[6];
    u16 xda;
} Obj_72190;
typedef struct Wk_72190 { u8 pad0[0x14]; s16 x14; u8 pad16[0x4C - 0x16]; Obj_72190* obj; } Wk_72190;
typedef struct Tk_72190 { u8 pad[0x24]; Wk_72190* work; } Tk_72190;

extern s16 fn_80060F6C(s16, void*, int);

void fn_80072190(Tk_72190* t) {
    Wk_72190* w = t->work;
    Obj_72190* o = w->obj;
    u8 type;
    E10_72190* a;
    s16 n;
    s16 i;
    int found;
    E18_72190* b;

    found = 0;
    for (i = 0; i < 15; i++) {
        if (o->x94[i] != 0) {
            found = 1;
            break;
        }
    }
    if (found) {
        n = 0x1E0;
        if (w->x14 <= 0x1E0) {
            n = w->x14;
        }
        type = o->xda & 0xF;
        switch (type) {
        case 2:
            a = (E10_72190*)o->xd0;
            break;
        case 3:
            b = (E18_72190*)o->xd0;
            break;
        default:
            return;
        }
        for (i = 0; i < n; i++) {
            if (fn_80060F6C(i, o->x94, 2) != 0) {
                switch (type) {
                case 2:
                    fn_801E17E0(a->x4);
                    break;
                case 3:
                    fn_801E17E0(b->x4);
                    break;
                }
            }
            switch (type) {
            case 2:
                a++;
                break;
            case 3:
                b++;
                break;
            }
        }
        fn_801E17E0(o->xd0);
        for (i = 0; i < 15; i++) {
            o->x94[i] = 0;
        }
    }
}

void fn_8005C480(O_8005C480 *o) {
    S_8005C480 *s;
    Un_8005C480 *u;
    s8 i;
    s8 found;
    s32 ok;
    found = -1;
    ok = 0;
    s = o->s;
    u = s->p->wk->unit;
    switch (o->state) {
    case 0:
        for (i = 0; i < 2; i++) {
            if ((s8)u->id == lbl_8030A10C.e[i].id && lbl_8030A10C.e[i].ptr != 0) {
                switch (lbl_8030A10C.e[i].kind) {
                case 5:
                    if (u->s6 == 1) {
                        ok = 1;
                    }
                    break;
                default:
                    if (lbl_8030A10C.e[i].s == u->s6) {
                        ok = 1;
                    } else if (u->s6 == 0x17 && lbl_8030A10C.e[i].s == 0x10) {
                        ok = 1;
                    }
                    break;
                }
                if (ok) {
                    found = i;
                    break;
                }
            }
        }
        if (found < 0) {
            o->state = 4;
        } else {
            s->idx = found;
        }
    }
    switch (o->state) {
    case 0:
        fn_8006D954(1);
        o->state = 1;
    case 1:
        if (s->cnt < s->a->s1c) {
            break;
        }
        fn_80215F94(lbl_8030A10C.e[s->idx].ptr);
        o->state = 3;
        break;
    case 3:
        if (fn_80216F48(lbl_8030A10C.e[s->idx].ptr) == 0) {
            lbl_8030A10C.e[s->idx].ptr = 0;
            lbl_8030A10C.e[s->idx].id = -1;
            o->state = 0xfa;
        }
        break;
    case 0xf9:
        if (fn_80216F48(lbl_8030A10C.e[s->idx].ptr) != 0) {
            fn_80217830(lbl_8030A10C.e[s->idx].ptr);
        }
        lbl_8030A10C.e[s->idx].ptr = 0;
        lbl_8030A10C.e[s->idx].id = -1;
    case 0xfa:
        fn_8006D8DC(1);
    case 4:
        o->flags |= 0x40;
        lbl_8030A10C.count--;
        return;
    }
    s->cnt = s->cnt + 1;
    fn_80037FD8(s->a, &o->state);
}

void fn_8005D614(O_8005D614 *o) {
    S_8005D614 *s = o->s;
    Un_8005D614 *u = s->p->wk->unit;
    switch (o->state) {
    case 0:
        s->p8 = s->p;
        s->f1c = s->tab->s26 << 11;
        s->f1c = s->f1c | (s->tab->s28 << 8);
        s->f18 = s->tab->f1c;
        s->pd = s->tab->s20;
        s->f10 = s->tab->f10;
        o->state = 1;
    case 1:
        if (s->cnt < s->tab->s14) {
            break;
        }
        o->state = 2;
        u->f50 |= 0x2000000;
        break;
    case 2:
        if (s->tab->s2a != 0 && s->cnt >= s->tab->s2a && s->f18 >= 0.0f) {
            s->f18 = 0.0f;
        } else {
            s->f18 = 1.0f - njSin((s32)(1.5f * ((f32)(s32)(182.04445f * (f32)s->cnt) * s->tab->f18)));
            if (s->f18 > 0.0f) {
                if (s->tab->s2a != 0 && s->cnt >= s->tab->s2a) {
                    s->f18 = 0.0f;
                } else {
                    s->f18 *= -1.0f;
                }
            }
        }
        u->f50 |= 0x2000000;
        s->pc = u->b296;
        if (s->tab->s22 > s->tab->s14 && s->cnt >= s->tab->s22) {
            s->pd = s->tab->s24;
        }
        if (s->cnt >= s->tab->s16 && s->tab->s16 < 900) {
            u->f50 &= ~0x2000000;
            u->f164 = 0.0f;
            o->state = 0xfa;
        }
        fn_8002FEB0(fn_8005D8F8, &s->p8, 0);
        if (lbl_8034737C == 4 && u->s2 == 0x9d) {
            fn_8002F53C();
        }
        break;
    case 0xf9:
        u->f50 &= ~0x2000000;
    case 0xfa:
        o->flags |= 0x40;
        lbl_8030A10C.count--;
        return;
    }
    s->cnt++;
    fn_80037FD8(s->tab, &o->state);
}

void fn_80061048(char *s)
{
    s8 i = 0;
    while (s[i] != 0) {
        if (s[i] == '.') {
            s[i] = 0;
            return;
        }
        i++;
    }
}

void fn_800615B4(NJS_POINT3 *src, NJS_POINT3 *out, Angle *rot)
{
    NJS_POINT3 a;
    NJS_POINT3 b;

    a.x = src->x;
    a.y = src->y;
    a.z = src->z;
    njPushMatrixEx();
    fn_80286EE8();
    fn_8028B498();
    njUnitMatrix(0);
    njRotateXYZ(0, rot[0], rot[1], rot[2]);
    njCalcPoint(0, &a, &b);
    njPopMatrixEx();
    out->x = b.x;
    out->y = b.y;
    out->z = b.z;
}

void fn_8006B3EC(void)
{
    fn_802A75C8(0.0f, 0.0f, 1.0f);
    fn_802A75B0(0.2f, 0.8f);
    fn_802A7598(1.0f, 1.0f, 1.0f);
    fn_802A210C(0.0f, 0.0f, 1.0f);
    fn_802A20F4(0.0f, 0.0f);
    fn_802A20DC(0.0f, 0.0f, 0.0f);
}

void fn_8006B71C(void)
{
    memset(lbl_80309E88, 0, 0x40);
    fn_802872C4(4);
    fn_80287274(0, 0);
    fn_8028B870(4);
    fn_8028B820(0, 0);
}

s32 fn_8006C9AC(void *p, s32 x)
{
    s16 a = 0;
    s32 b = 0;

    fn_8006C9E4(p, x, &a, &b);
    return b;
}

s32 fn_8006CEEC(Ctx_8006CEEC *c, u32 *out, u32 idx, s32 slot)
{
    Tab_8006CEEC *t = c->x4[slot].x1c;

    if (idx >= t->count) {
        return 0;
    }
    *out = t->v[idx];
    return 1;
}

s32 fn_8006D888(void)
{
    Node_8006D888 *n = lbl_8034739C;

    if (n == 0) {
        return 0;
    }
    for (;;) {
        if (n->x4 != 0 && n->x0 > 0) {
            return 0;
        }
        if (n->x10 == 0) {
            break;
        }
        n = n->x10;
    }
    return 1;
}

s32 fn_80071C34(f32 x0, f32 y0, f32 x1, f32 y1) {
    f32 dx = x1 - x0;
    f32 dy = y1 - y0;
    return (s32)(lbl_80348A1C * (f32)atan2(dx, dy));
}

s32 fn_80071C74(Pt *p, f32 x, f32 y) {
    f32 dx = x - p->x;
    f32 dy = y - p->y;
    return (s32)(lbl_80348A1C * (f32)atan2(dx, dy));
}

f32 fn_80071E5C(NJS_VECTOR *a, NJS_VECTOR *b) {
    f32 dx = b->x - a->x;
    f32 dz = b->z - a->z;
    return fn_80291A5C(dx * dx + dz * dz);
}

void fn_80072130(NJS_VECTOR *v) {
    NJS_VECTOR t;
    t.x = v->x;
    t.y = v->y;
    t.z = v->z;
    njUnitVector(&t);
    v->x = t.x;
    v->y = t.y;
    v->z = t.z;
}

void fn_80055EB8(Ent80055EB8 *self)
{
    Wrap80055EB8 *w = (Wrap80055EB8 *)self;
    fn_801E17E0(w->inner->sub);
    self->flags |= 0x40;
    lbl_8030A10C.count--;
}

s32 fn_80060AB4(void)
{
    if ((lbl_8030A10C.f6c & 0x200000) && (lbl_8030A10C.f6c & 0x100000)) {
        fn_801D6CBC(lbl_8030A10C.f168, lbl_8030A10C.p16c);
        lbl_8030A10C.f6c &= ~0x200000;
    }
    lbl_8030A10C.b16e = 0;
    return 1;
}

void fn_8006EB04(void) {
    lbl_803473A0 = fn_801E1C7C(0x44);
    memset(lbl_803473A0, 0, 0x44);
    lbl_8030A10C.f0 = 0x100;
    lbl_8034739C = fn_801E1C7C(0x14);
    memset(lbl_8034739C, 0, 0x14);
    *(s32 *)lbl_8034739C = -1;
    fn_80061F58(&lbl_80347398, 0xe00, 0);
    *(s32 *)lbl_80347398 = -1;
}

void fn_80068778(void *unused, s16 idx)
{
    if ((lbl_80309DE4[idx]->flags >> 3) & 1) {
        return;
    }
    lbl_80309700[idx]->work->x3c = 500;
    lbl_80309700[idx]->work->x44 = 0x21;
    lbl_80309700[idx]->work->x46 = 0x15;
    lbl_80309700[idx]->work->x48 = 0x14;
    lbl_80309174[idx].x8 = 1;
    lbl_80309730[idx].x8 = 1;
}

void fn_80068944(void *unused0, s16 idx, void *unused1, s8 v)
{
    lbl_80309700[idx]->work->x44 = v;
    lbl_80309174[idx].x8 = 1;
    lbl_80309730[idx].x8 = 1;
}

void fn_8006A078(void *unused0, s16 idx, void *unused1, s8 v)
{
    lbl_80309700[idx]->work->x3c = -1;
    if (!(lbl_80309DE4[idx]->bits & 0x2100)) {
        lbl_80309700[idx]->work->x44 = -1;
        return;
    }
    lbl_80309700[idx]->work->x44 = v;
    lbl_80309700[idx]->work->x3c = lbl_80309DE4[idx]->x18;
    lbl_80309174[idx].x8 = 1;
    lbl_80309730[idx].x8 = 1;
}

void fn_800691D8(void *unused, s16 idx, void *unused2, s8 v)
{
    ChrRec *c = lbl_80309DE4[idx];

    lbl_80309700[idx]->work->x3c = (s16)(c->xff - c->xfe);
    lbl_80309700[idx]->work->x44 = v;
}

void fn_80065608(void)
{
    u32 bits = lbl_80309DE4[lbl_80346BD8->x90]->bits;

    if (bits & 0x4000) {
        lbl_80346BD8->x8e = 3;
    } else if (bits & 0x800) {
        lbl_80346BD8->x8e = 5;
    } else if (bits & 0x400) {
        lbl_80346BD8->x8e = 4;
    } else if (bits & 0x200) {
        lbl_80346BD8->x8e = 6;
    } else if (bits & 0x1000) {
        lbl_80346BD8->x8e = 7;
    } else if (bits & 0x80) {
        lbl_80346BD8->x8e = 1;
    } else {
        lbl_80346BD8->x8e = -1;
    }
}

void fn_8006D8DC(s32 key)
{
    Node_8006D888 *n = lbl_8034739C;

    if (n == 0) {
        return;
    }
    for (;;) {
        if (n->x0 == key) {
            n->x4 = n->x4 - 1;
            if (n->x4 < 0) {
                fn_801DBE1C(lbl_802B06C0);
            }
            return;
        }
        if (n->x10 == 0) {
            return;
        }
        n = n->x10;
    }
}

void *fn_8006DAF8(void *self)
{
    s16 i = 0;

    while (lbl_80347398[i].f0 > 0) {
        if (lbl_80347398[i].f0 == 0x0098967F) {
            if (fn_8025EF88(self, lbl_80347398[i].f8) == 0) {
                return (void *)lbl_80347398[i].f4;
            }
        }
        i++;
    }
    return 0;
}

s32 fn_8006EAB4(Node *target)
{
    Node *p = lbl_803473A0;

    if (p->x8 == 0) {
        return 0;
    }
    for (;;) {
        if (p == target) {
            return p->count == 1;
        }
        if (p->x38 != 0) {
            p = p->x38;
        } else {
            return 0;
        }
    }
}

void fn_8006A1F4(s32 a, s16 i, s32 b, s8 v)
{
    ChrRec *c = lbl_80309DE4[i];
    s16 fl;

    if ((c->bits & 0x6100) == 0) {
        fl = c->flags;
        if (((fl & (1 << (v - 0x12))) ? 1 : 0) == 0) {
            switch (v) {
            case 0x14:
            case 0x15:
                if ((fl & 0x100) == 0) {
                    lbl_80309700[i]->work->x44 = v;
                    lbl_80309700[i]->work->x3c = -1;
                    return;
                }
                break;
            default:
                fn_800696A8(a, i, b, v);
                return;
            }
        }
    }
    lbl_80309700[i]->work->x44 = -1;
    lbl_80309700[i]->work->x3c = -1;
}

void fn_8006C8DC(char *buf, char *name)
{
    s32 v;
    switch (fn_80046BB0(name, &v)) {
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
}

void fn_8006A114(s32 a, s16 i, s32 b, s8 v) {
    lbl_80309700[i]->work->x3c = -1;
    if (!(lbl_80309DE4[i]->bits & 0x2100)) {
        lbl_80309700[i]->work->x44 = -1;
    } else {
        fn_800696A8(a, i, b, v);
        if (lbl_80309700[i]->work->x44 != -1) {
            lbl_80309700[i]->work->x3c = lbl_80309DE4[i]->x18 / 2;
            lbl_80309174[i].x8 = 1;
            lbl_80309730[i].x8 = 1;
        }
    }
}

s32 fn_8006DA04(s32 x)
{
    s32 q = x / 100;
    s32 p;
    switch (q) {
    case 0:
    case 1:
    case 5:
    case 1002:
        return 1;
    }
    p = x / 100000;
    switch (p) {
    case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10:
    case 13: case 14:
    case 17: case 18:
    case 21: case 22:
    case 50: case 51:
    case 99:
        return 1;
    }
    switch (q) {
    case 23034:
        return 1;
    }
    return 0;
}

int fn_8006EE54(int idx) {
    switch (lbl_80309174[idx].x0) {
    case 4:
        return 1;
    case 6:
        if (idx <= 3) return 2;
        break;
    case 2:
        if ((s32)lbl_802C4BF0[(u8)lbl_80309174[idx].x6].x18 == 2) return 2;
        break;
    case 12: {
        switch ((u8)fn_80078354(lbl_80309174[idx].x6)) {
        case 0x25: case 0x26: case 0x27: case 0x28: case 0x2a: case 0x43:
            return 2;
        }
        break;
    }
    case 8:
        if (lbl_80309174[idx].x6 == 0x3d) return 2;
        break;
    }
    return 0;
}

void fn_80073B48(s8 *out) {
    s8 pat[] = { 0, 4, 5, 6, 10, 11, 14, 16, 18, 17, 21, 1, 2, 3, 7, 8, 9, 12, 13, 15, 19, 20, -1 };
    s8 buf[0x20];
    s32 i = 0;
    s8 *b;
    s8 *p;
    s8 j;
    s8 n = 0;
    fn_8021A1C4(buf);
    for (p = pat; *p >= 0; p++, i++) {
        b = buf;
        for (j = 0; j < 0x16; b++, j++) {
            if (*b < 0) break;
            if (*b == *p) {
                out[n++] = i;
            }
        }
    }
    out[n] = -1;
}

void fn_8005CBA4(O_8005CBA4 *o) {
    S_8005CBA4 *s = o->s;
    switch (o->state) {
    case 0:
        if (s->cnt >= s->d->x14) {
            lbl_8030A10C.f6c |= 0x100;
            o->state = 1;
        }
        break;
    case 1:
        if (s->cnt >= s->d->x16) {
            lbl_8030A10C.f6c &= ~0x100;
            o->state = 0xfa;
        }
        break;
    case 0xf9:
        lbl_8030A10C.f6c &= ~0x100;
    case 0xfa:
        o->flags |= 0x40;
        lbl_8030A10C.count--;
        return;
    }
    s->cnt = s->cnt + 1;
    fn_80037FD8(s->d, &o->state);
}

void fn_80061E34(NJS_POINT3 *out, s32 *rot, f32 angle, f32 z, f32 y) {
    NJS_POINT3 p;
    NJS_POINT3 q;
    p.x = 0.0f;
    p.y = y;
    p.z = z;
    njPushMatrixEx();
    fn_80286EE8();
    fn_8028B498();
    njUnitMatrix(0);
    njRotateY(0, (s32)(182.04445f * angle));
    njCalcPoint(0, &p, &q);
    njPopMatrixEx();
    p.x = q.x;
    p.y = q.y;
    p.z = q.z;
    njPushMatrixEx();
    fn_80286EE8();
    fn_8028B498();
    njUnitMatrix(0);
    njRotateXYZ(0, rot[0], rot[1], rot[2]);
    njCalcPoint(0, &p, &q);
    njPopMatrixEx();
    out->x = q.x;
    out->y = q.y;
    out->z = q.z;
}

inline s32 AngWrap(s32 a) {
    if (a > 0x7fff) {
        a -= 0x10000;
    } else if (a < -0x8000) {
        a += 0x10000;
    }
    return a;
}

void fn_8007201C(s32 *out, Vec3f *v) {
    out[0] = AngWrap((s32)(lbl_80348A1C * (f32)atan2(v->y, fn_80291A5C(v->x * v->x + v->z * v->z))));
    if (v->x == 0.0f) {
        out[1] = 0;
        if (v->z > 0.0f) {
            out[1] = 0x8000;
        }
    } else {
        out[1] = AngWrap(-(s32)(lbl_80348A1C * (f32)atan2(v->x, -v->z)));
    }
    out[2] = 0;
}

void fn_8005A694(O_8005A694 *o)
{
    S_8005A694 *s = o->s;
    switch (o->state) {
    case 0: {
        W_8005A694 *w = s->f4->q->w;
        s->f8 = w->f154 + s->fc->f18 * 0x34;
        fn_8022EF58(s->f8, 0);
        s->f0 = w->f0;
        o->state = 1;
    }
    case 1:
        if (fn_800179E4(s->f0) == 0) {
            o->state = 0xfa;
        } else {
            s16 v[2];
            v[0] = s->fc->f1a;
            v[1] = s->fc->f1c;
            fn_8023080C(s->f8, v, 0);
        }
        break;
    case 0xf9:
    case 0xfa:
        o->flags |= 0x40;
        lbl_8030A10C.count--;
        return;
    }
    fn_80037FD8(s->fc, &o->state);
}

void fn_8005BAA0(O_8005BAA0 *o)
{
    S_8005BAA0 *s = o->s;
    switch (o->state) {
    case 0:
        fn_8006D954(s->f5c);
        o->state = 1;
    case 1:
        if (s->f0 < s->f68) {
            break;
        }
        s->f18->f3c |= 0x40000000;
        o->state = 2;
    case 2:
        if (s->f0 >= s->f6a) {
            s->f18->f3c &= ~0x40000000;
            o->state = 0xfa;
        }
        break;
    case 0xf9:
        s->f18->f3c &= ~0x40000000;
    case 0xfa:
        fn_8006D8DC(s->f5c);
        o->flags |= 0x40;
        lbl_8030A10C.count--;
        return;
    }
    s->f0 = s->f0 + 1;
    fn_80037FD8(s->f54, &o->state);
}

void fn_8005CCB0(Tk_8005CCB0* t) {
    St* s = t->s;
    switch (t->state) {
    case 0:
        if (s->t < s->lim->x14) break;
        fn_801CBC30();
        fn_801CBBAC(7.5f);
        lbl_80347508 = 1;
        lbl_80347510 = 0.0f;
        if (lbl_80347394 == 0) {
            t->state = 0xfa;
        } else {
            t->state = 2;
        }
        break;
    case 2:
        if (s->t < s->lim->x16) break;
        fn_801CBB9C(30.0f);
        lbl_80347510 = 0.0f;
        lbl_80347508 = 1;
        t->state = 0xfa;
        break;
    case 3:
        if (lbl_80347508 != 0) break;
        fn_801CBBF8();
        t->state = 0xfa;
        break;
    case 0xfa:
        t->flags |= 0x40;
        lbl_8030A10C.count--;
        return;
    }
    s->t++;
}

void fn_8006EF48(void) {
    s32 sum;
    s32 i = 0;
    for (sum = 0; i <= 3; i++) {
        if (fn_80078610(i)) {
            ChrRec *c = lbl_80309DE4[i];
            if (!(c->bits & 0x3100)) {
                sum += lbl_8030B4D4[lbl_80309DCC[i]].x6;
                sum += c->x10c;
            }
        }
    }
    lbl_80347390->x8 += sum;
    lbl_80347390->xa += sum;
    if (lbl_80347390->x8 > lbl_80347390->x6) {
        lbl_80347390->x8 = lbl_80347390->x6;
    }
    lbl_80347390->xa = lbl_80347390->x8;
}

void fn_80062E94(O62E94 *o) {
    S62E94 *s = o->s;
    switch (o->state) {
    case 0:
        o->state = 1;
        lbl_80346BD8->x88 = 0;
        s->f4 = (lbl_80346BD8->f18 - lbl_80346BD8->f20) / (f32)s->s8;
    case 1:
        lbl_80346BD8->f20 = lbl_80346BD8->f20 + s->f4;
        if (lbl_80346BD8->f20 >= lbl_80346BD8->f18) {
            lbl_80346BD8->f20 = lbl_80346BD8->f18;
            o->state = 2;
        }
        break;
    case 2:
        o->state = 3;
        break;
    case 3:
        o->flags |= 0x40;
        break;
    }
}

void fn_80062318(O_80062318* o)
{
    S_80062318* s = o->s;
    Work_80062318* w = s->target->body->w;
    if (o->state != 3 && w->kind != s->x4) {
        o->state = 2;
    }
    switch (o->state) {
    case 0:
        o->state = 1;
        lbl_80346BD8->x88 = s->x6;
        lbl_80346BD8->x8a = s->x8;
        lbl_80346BD8->x8c = s->xa;
        switch (s->x6) {
        case 2:
            w->x68 = (f32)w->x5c->x4 - 1.0f;
            break;
        case 3:
            w->x68 = (f32)s->x8;
            break;
        }
        break;
    case 2:
        lbl_80346BD8->x88 = 0;
        o->state = 3;
        break;
    case 3:
        o->flags |= 0x40;
        break;
    }
}

void fn_80071990(void) {
    s32 i;
    if (lbl_80347508 != 1) {
        fn_801CBBBC();
        fn_801CBBF8();
        if (lbl_80347344 == 0) {
            lbl_8034733C = 2;
            lbl_80347338 = 0;
        } else {
            lbl_8034733C = 1;
            lbl_80347338 = 0;
        }
        fn_80029070();
        lbl_80347330 = 0;
        lbl_8034732C = 0;
        lbl_80347328 = -1;
        lbl_80347334 = 0;
        lbl_80347378 = 0;
        lbl_80347376 = 0;
        lbl_80347374 = 0;
        lbl_80347340 = 1;
        lbl_80347320 = fn_801E1C7C(0x1c);
        i = 0;
        do {
            lbl_80309174[i].x0 = -1;
            lbl_80309174[i].x4 = i;
            lbl_80309174[i].x6 = -1;
            lbl_80309730[i].x4 = i;
            lbl_80309174[i].xd = 0;
            lbl_80309174[i].xe = 0;
            lbl_80309730[i].x8 = -1;
            i++;
        } while (i < 12);
    }
}
