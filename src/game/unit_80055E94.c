#include "types.h"
#include "game/task.h"
#include <math.h>
#include "game/stat_8030B4D4.h"
#include "ninja.h"
#include "game/drawstate.h"
/* One declaration per global / prototype. Tk and Chr tables are read through raw offsets
   (same offsets and widths as the per-function struct views they replace). */
typedef struct Lim { u8 pad_0[0x4];
 s8 x4;
 u8 pad_5[0x1]; s16 x6; s16 x8; s16 xa; } Lim;
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
    u8 pad70[4];
    u32 x74;
    u32 x78;
    u32 x7c;
    u32 x80;
    u8 x84[0x20];
    u8 xa4[0xCC - 0xA4];
    Slot_8030A10C e[2];
    u8 pad_ec[0xF8 - 0xEC];
    void *pf8;
    u8 padfc[0x104 - 0xFC];
    u32 a104[12];
    u32 a134[12];
    u8 pad164[4];
    void *f168;
    u8 b16c;
    u8 b16d;
    u8 b16e;
    u8 b16f;
    u8 b170;
    u8 pad171[0x1C4 - 0x171];
    s32 count;
    u8 pad1c8[4];
    u32 f1cc;
} Sys_8030A10C;
extern Sys_8030A10C lbl_8030A10C;
typedef struct WorkRec {
    s16 x0;
    s16 x2;
    u32 x04;
    u8 pad8[0x3c - 8];
    s32 x3c;
    s32 x40;
    s16 x44;
    s16 x46;
    s16 x48;
    s16 x4a;
} WorkRec;
typedef struct TkRec {
    u8 pad_0[0x18];
    u8 flags;
    u8 pad_19[0xb];
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
    u8 pad_84[0x32];
    s16 xb6;
    u8 pad_b8[0x46];
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
typedef NJS_POINT3 Vec3;
typedef struct Ent { s32 x0; u32 x4; s32 x8; s32 xc; } Ent;
typedef struct Hdr { u8 pad0[4]; s16 count; u8 pad6[2]; Ent e[1]; } Hdr;
void fn_800D208C(void *obj, f32 f);
void fn_8006AFD0(s16 i, void *a, void *b, s32 c);
extern void fn_8006AC68(s16 i);
extern void fn_800696A8(s32 a, s16 i, s32 b, s8 v);
s16 fn_8006E924(char* path, char* name, Node** out, void* key);
s32 rand(void);
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
char* strcat(char* d, const char* s);
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
extern s32 sprintf(char *, char *, ...);
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
extern void strcpy(char *, char *);
extern u8 fn_80046BB0(char *, s32 *);
extern u32 fn_80035C38(void *);
extern s32 fn_8003DBAC(s32, char *);
int fn_8025EF88(char* a, const char* b);
void fn_80015554(void);
typedef NJS_POINT3 V3;
/* Model table entry of a battle character record. */
typedef struct Rec18 {
    u32 flags;          /* 0x00 */
    u8 pad4[4];
    u32 flags8;         /* 0x08 */
    u8 padc[0x18 - 0xC];
} Rec18;
/* Battle character record (character task work +0x4C). */
typedef struct U5C188 {
    u8 id;              /* 0x000 */
    u8 pad1[5];
    s16 kind;           /* 0x006 */
    u8 pad_8[0xa];
    s16 state;          /* 0x012 */
    u8 pad_14[0x3c];
    u32 f50;            /* 0x050 */
    u8 pad_54[0x5c - 0x54];
    void *p5c;          /* 0x05C */
    void *p60;          /* 0x060 */
    u8 pad64[4];
    f32 f68;            /* 0x068 */
    f32 f6c;            /* 0x06C */
    s32 x70;            /* 0x070 */
    u8 a74[0x10];       /* 0x074 */
    u8 a84[0xdc - 0x84]; /* 0x084 */
    Rec18 *tbl;         /* 0x0DC */
    u8 pad_e0[4];
    s16 xe4;            /* 0x0E4 */
    u8 pad_e6[2];
    s16 xe8;            /* 0x0E8 */
    s16 xea;            /* 0x0EA */
    u32 xec;            /* 0x0EC */
    u32 ff0;            /* 0x0F0 */
    u8 pad_f4[0x40];
    s32 x134;           /* 0x134 */
    s16 x138;           /* 0x138 */
    u8 pad_13a[0x154 - 0x13a];
    void *p154;         /* 0x154 */
    u8 pad158[0x164 - 0x158];
    f32 f164;           /* 0x164 */
    u8 pad168[0x1f4 - 0x168];
    void *x1f4;         /* 0x1F4 */
    s16 x1f8;           /* 0x1F8 */
    u8 pad_1fa[2];
    NJS_MATRIX *x1fc;   /* 0x1FC */
    u8 pad200[4];
    s16 s204;           /* 0x204 */
} U5C188;
typedef struct M5D8F8 {
    void *model;
} M5D8F8;
/* Work of a battle character task. */
typedef struct W5C188 {
    M5D8F8 *mdl;        /* 0x00 */
    u8 pad4[4];
    NJS_TEXLIST *tex;   /* 0x08 */
    u8 padc[4];
    struct P_80065F1C* x10; /* 0x10 */
    u8 pad14[0x1c - 0x14];
    V3 pos;             /* 0x1C */
    u32 rot[3];         /* 0x28 */
    f32 scl[3];         /* 0x34 */
    u8 pad40[4];
    u8 b44;             /* 0x44 */
    u8 pad45[0x4c - 0x45];
    U5C188 *u;          /* 0x4C */
} W5C188;
typedef struct T5C188 {
    u8 pad0[0x24];
    W5C188 *work;
} T5C188;
/* The battle character task as fn_800631B0 and fn_800565B0 see it (position as an array). */
typedef struct {
    s8 b0;               /* 0x00 */
    u8 pad1[3];
    u8 b4;               /* 0x04 */
    u8 pad5;
    s16 h6;              /* 0x06 */
    s16 h8;              /* 0x08 */
    u8 padA[0x5a - 0xa];
    u8 b5a;              /* 0x5A */
    u8 pad5b;
    struct { u8 pad[4]; u32 w4; }* p5c; /* 0x5C */
    u8 pad60[0x8c];
    u32 fec;             /* 0xEC */
    u32 ff0;             /* 0xF0 */
    u8 padF4[0x154 - 0xf4];
    void* p154;          /* 0x154 */
    u8 pad158[0x164 - 0x158];
    f32 f164;            /* 0x164 */
    u8 pad168[0x94];
    void* p1fc;          /* 0x1FC */
    u8 pad200[8];
    f32 f208;            /* 0x208 */
} CamChr;
typedef struct {
    u8 pad0[0x1c];
    f32 pos[3];          /* 0x1C */
    s32 rot[3];          /* 0x28 */
    f32 scale[3];        /* 0x34 */
    u8 pad40[0xc];
    CamChr* chr;         /* 0x4C */
} CamBody;
typedef struct {
    u8 pad0[0x24];
    CamBody* body;       /* 0x24 */
} CamObj;
extern void fn_80020B8C(CamObj* o, s16 a, s16 b, s32 c);
extern void fn_8001D14C(CamChr* c);
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
extern s32 rand(void);
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
    u8 pad_0[0x4];
    s32 w4;
    f32 v8[3];
    f32 x14;
    f32 x18;
    f32 x1c;
    f32 x20;
    f32 ang[3]; /* degrees */
    u8 pad_30[0xc];
    f32 v[3];
    u8 pad_48[0x8];
    f32 f50;
    u8 pad_54[0x18];
    f32 f6c;
    u8 pad_70[0xc];
    u32 f7c;
    u8 pad_80[0x2];
    s16 h82;
    u8 pad_84[0x2];
    s16 h86;
    s16 x88;
    s16 x8a;
    s16 x8c;
    s16 x8e;
    s16 x90;
    s16 x92;
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
/* Light effect work (fn_8006B8A8): kind, flags, light number, position and colours. */
typedef struct Eff {
    s8 kind;            /* 0x00 */
    u8 pad1[3];
    u32 x4;             /* 0x04 */
    s16 x8;             /* 0x08 light number */
    u8 padA[2];
    V3 pos;             /* 0x0C */
    u8 pad18[0x30 - 0x18];
    f32 x30;            /* 0x30 */
    f32 x34;            /* 0x34 */
    f32 x38;            /* 0x38 */
    f32 x3c;            /* 0x3C */
    f32 x40;            /* 0x40 */
    f32 x44;            /* 0x44 */
    f32 x48;            /* 0x48 */
    f32 x4c;            /* 0x4C */
    u8 pad50[0x64 - 0x50];
} Eff;
typedef struct Wk_8006B46C {
    u8 pad0[0x28];
    Eff eff;
} Wk_8006B46C;
typedef struct TblEnt_8006B46C { void* f0; void* f4; u32 f8; u8 fc; u8 pad[3]; } TblEnt_8006B46C;
extern void* memset(void*, int, u32);
extern void fn_8006B8A8(Eff*);
typedef NJS_POINT3 V5BF30;
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
typedef struct O5D8F8 {
    T5C188 *t;
    s8 kind;
    u8 mode;
    u8 pad6[2];
    u32 flags;
    u8 padc[4];
    f32 alpha;
    NJS_TEXLIST *tex;
} O5D8F8;
extern void fn_8029D008(NJS_TEXLIST *);
extern void fn_8007E678(void *, DrawState *);
extern void fn_80032AD8(void *, s32, s32, s32);
extern void njScale(NJS_MATRIX m, f32 x, f32 y, f32 z);
extern s32 fn_8002F52C(void);
extern void fn_8002F4BC(void *, f32, void *);
extern void fn_80035468(void *, void *, void *, f32, u8);
extern void fn_80035228(void *, void *, f32, u8);
extern void fn_800353F4(void *, void *, void *, f32, u8);
extern void fn_8003529C(void *, void *, f32, u8);
extern void fn_80035380(void *, void *, f32, u8);
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
typedef struct ChrInfo {
    u8 pad0[0xf0];
    u32 ff0;
    u8 pad_f4[0x1fc - 0xf4];
    void *f1fc;
} ChrInfo;
typedef struct ChrWork {
    u8 pad0[0x1c];
    V3 v1c;
    u32 rot[3];
    u8 pad34[0x4c - 0x34];
    ChrInfo *u;
} ChrWork;
typedef struct ChrTask {
    u8 pad0[0x24];
    ChrWork *work;
} ChrTask;
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
    ChrTask *p4;
    void *f8;
    V3 vc;
    u32 v18[3];
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
extern V3 lbl_802AD3B8;
extern ChrTask *fn_8001E05C(ChrTask *);
extern void fn_80040150(void *, ChrTask *, s32, void **);
extern void fn_800400D8(void *, ChrTask *, s32, void **);
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
extern T5C188 *fn_80021658(s8);
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
/* Node of a model tree (child at 0x2C, sibling at 0x30). */
typedef struct MdlNode {
    u8 pad0[0x2C];
    struct MdlNode* child;   /* 0x2C */
    struct MdlNode* sibling; /* 0x30 */
} MdlNode;
void fn_8006C9E4(MdlNode* n, u16 target, u16* count, MdlNode** out);
typedef struct Motion {
    void* data;
    u32 nbFrame;
} Motion;
typedef struct Tab_8006CEEC {
    u32 count;
    Motion* v[1];
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
typedef struct { s8 pad[0x18]; s8 x18; s8 x19;
 u8 pad_1a[0x2];
 s16 v;
 u8 pad_1e[0x12]; } T30;
extern T30 lbl_802C4BF0[];
extern s16 fn_80078354(s16);
extern void fn_8021A1C4(s8 *buf);
typedef struct { u8 pad[0x14]; s16 x14; s16 x16; } D_8005CBA4;
typedef struct { u8 pad0[4]; s16 cnt; u8 pad6[2]; D_8005CBA4 *d; } S_8005CBA4;
typedef struct {
    u8 pad0[0x6c];
    u32 f6c;
    u8 pad70[0x1c4 - 0x70];
    s32 count;
} Sys_8030A10C_8005CBA4;
typedef NJS_POINT3 Vec3f;
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
typedef struct Sys_8030A10C_8005CCB0 { u8 pad[0x1c4]; s32 count; } Sys_8030A10C_8005CCB0;
typedef struct Lim_8005CCB0 { u8 pad[0x14]; s16 x14; s16 x16; } Lim_8005CCB0;
typedef struct St { u8 pad0[4]; s16 t; u8 pad6[2]; Lim_8005CCB0* lim; } St;
extern s32 lbl_80347508;
extern f32 lbl_80347510;
extern void fn_801CBC30(void);
extern void fn_801CBBAC(f32);
extern void fn_801CBB9C(f32);
extern void fn_801CBBF8(void);
typedef struct Lim_8006EF48 { u8 pad[6]; s16 x6; s16 x8; s16 xa; } Lim_8006EF48;
extern s16 lbl_80309DCC[];
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
extern void fn_8007201C(s32 *out, Vec3f *v);
extern char lbl_802B0708[];
extern void fn_80068190(char *);
extern void fn_80009500(Ent6EB88 *, s32, s32);
extern void fn_8006E75C(Ent6EB88 *, char *, s32);
typedef struct { s32 pad; s32 v[1]; } Tab_8006801C;
typedef struct { u8 pad0[0x24]; Tab_8006801C *tab; } O_8006801C;
typedef struct Ctr_8006D02C {
    u8 pad0[4];
    s16 x4;
} Ctr_8006D02C;
extern void fn_8006D080(void *p, s32 free);
typedef struct U5B094 {
    u8 id;
} U5B094;
typedef struct X5B094 {
    void *x0;
    u8 pad4[0x44 - 4];
    u8 f44;
    u8 pad45[0x4c - 0x45];
    U5B094 *u;
} X5B094;
typedef struct K5B094 {
    u8 pad0[0x24];
    X5B094 *work;
} K5B094;
typedef struct D5B094 {
    u8 pad0[0x14];
    s16 s14;
    u8 pad16[2];
    s16 s18;
    u8 pad1a[2];
    u8 u1c;
} D5B094;
typedef struct S5B094 {
    u8 pad0[0x4c];
    s16 cnt;
    u8 v;
    u8 pad4f;
    K5B094 *p50;
    D5B094 *p54;
} S5B094;
typedef struct O5B094 {
    u8 pad0[0x18];
    u8 flags;
    u8 state;
    u8 pad1A[10];
    S5B094 *s;
} O5B094;
typedef struct H5B094 {
    u8 pad[0x1c4];
    s32 count;
} H5B094;
typedef struct V60B98 { f32 x, y, z; } V60B98;
typedef struct P60B98 { f32 x, z; } P60B98;
typedef struct Seg60B98 {
    P60B98 a, b;
    f32 m, c;
} Seg60B98;
typedef struct Sub { u32 w[25]; } Sub;
typedef struct Wk_8006BDB4 { u8 pad0[0x28]; Sub sub; void* x8c; } Wk_8006BDB4;
typedef struct Node_8006BDB4 { u8 pad0[0x19]; u8 x19; u8 pad1a[0xa]; Wk_8006BDB4* work; } Node_8006BDB4;
extern void* lbl_803475A8;
extern void* lbl_802DF6C8[];
extern void fn_8007E13C(void *a);
extern void fn_8007E118(void *a);
extern void fn_8007DFC0(void *a);
extern void fn_8007DEE0(void *a);
/* The unit's .rodata string pool (lbl_802B0610 + 0x18 etc. from its start, MWCC's pooled base). */
extern char lbl_802B04C8[];
extern const u8 lbl_803489B0[8];
extern void fn_8008F75C(void *, void *, void *, const void *);
typedef struct T24 { u8 pad[0x15]; u8 x15; u8 pad16[2]; s16 v; u8 pad2[0xA]; } T24;
typedef struct T24b { u8 pad[0x1C]; s16 v; u8 pad2[0x6]; } T24b;
extern T24 lbl_802AD440[];
extern const T24b lbl_802C7C34[];
extern s16 lbl_8034736A;
extern s32 lbl_80346A90;
extern u32 lbl_80347364;
void fn_80217380(s32 a);
typedef struct P_80065F1C { u8 pad0[0x30]; s32 x30; } P_80065F1C;
extern void fn_80008308(void *o, s32 v);
void fn_80065AB0(T5C188 *o, s16 v);
typedef struct Src_80064C00 {
    u8 pad0[0x14];
    f32 x14;
    f32 x18;
    f32 x1c;
} Src_80064C00;
extern void fn_800692D8(void);
extern void fn_8008066C(s32);
typedef void (*Fn683D8)(s16, s16, s32, s8);
extern Fn683D8 lbl_802DF570[0x4f];
typedef NJS_POINT3 Vec3_80057DFC;
typedef struct Info { u8 pad[0xec]; u32 flags; } Info;
typedef struct Par_80057DFC { u8 pad[0x34]; Vec3_80057DFC v; u8 pad40[0x4c - 0x40]; Info* x4c; } Par_80057DFC;
typedef struct Obj_80057DFC { u8 pad[0x24]; Par_80057DFC* p24; } Obj_80057DFC;
typedef struct Data_80057DFC {
    u8 pad0[0x18];
    s16 x18;
    s16 x1a;
    s16 x1c;
    s16 x1e;
    s16 x20;
    u8 pad22[2];
    f32 x24;
    f32 x28;
    f32 x2c;
    Vec3_80057DFC x30;
} Data_80057DFC;
typedef struct Work_80057DFC {
    s16 t;
    u8 pad2[6];
    Vec3_80057DFC v8;
    Vec3_80057DFC v14;
    Vec3_80057DFC v20;
    s16 x2c;
    u8 pad2e[2];
    Vec3_80057DFC v30;
    f32 x3c;
    f32 x40;
    u16 x44;
    u8 pad46[2];
    Data_80057DFC* d;
} Work_80057DFC;
typedef struct { u8 pad[0x1c4]; s32 count; } Game;
typedef NJS_POINT3 Vec3_8005D108;
typedef struct Info_8005D108 { s8 id; } Info_8005D108;
typedef struct Par_8005D108 { u8 pad[0x4c]; Info_8005D108* x4c; } Par_8005D108;
typedef struct Data_8005D108 {
    u8 pad0[0x10];
    u32 x10;
    s16 x14;
    u8 pad16[2];
    s16 x18;
    u8 pad1a[2];
    Vec3_8005D108 v1c;
    Vec3_8005D108 v28;
    Vec3_8005D108 v34;
    u8 pad40[4];
    f32 x44;
    u8 pad48[4];
    f32 x4c;
    u8 pad50[0x68 - 0x50];
    Vec3_8005D108 v68;
    f32 x74;
} Data_8005D108;
typedef struct W_8005D108 {
    u8 pad0[0x20];
    f32 x20;
    f32 x24;
    u8 pad28[0x2c - 0x28];
    Vec3_8005D108 v2c;
    Vec3_8005D108 v38;
    u8 pad44[0x70 - 0x44];
    s16 t;
    s16 state;
    u8 pad74[4];
    Task* owner;
    void* x7c;
    f32 x80;
    f32 x84;
    f32 x88;
    f32 x8c;
    f32 x90;
    f32 x94;
    f32 x98;
    u8 pad9c[0xac - 0x9c];
    f32 xac;
    u8 padb0[4];
    Data_8005D108* d;
} W_8005D108;
extern Vec3_8005D108 lbl_802AD434;
extern void fn_8001D1D8(Task*, Vec3_8005D108*);
extern void fn_8001D288(f32*, s32, f32, f32);
typedef struct Sys_8030A10C_8005DB1C {
    u8 pad0[0x6c];
    u32 f6c;
    u8 pad70[0x1c4 - 0x70];
    s32 count;
} Sys_8030A10C_8005DB1C;
typedef struct Tb_8005DB1C {
    u8 pad0[0x10];
    u32 f10;
    s16 s14;
    s16 s16;
    u8 pad18[4];
    s16 s1c;
    s16 s1e;
    s16 s20;
    s16 s22;
    s16 s24;
    u8 pad26[2];
    f32 f28;
    f32 f2c;
    s16 s30;
    s16 s32;
    s16 s34;
    s16 s36;
    f32 f38;
    f32 f3c;
    f32 f40;
} Tb_8005DB1C;
typedef struct St_8005DB1C {
    s16 cnt;
    u8 pad2[0xe];
    u8 p10[4];
    u8 pad14[0xc];
    f32 f20;
    f32 f24;
    f32 f28;
    u8 pad2c[4];
    f32 f30;
    s16 s34;
    s16 s36;
    s16 s38;
    u8 pad3a[2];
    Tb_8005DB1C* tab;
} St_8005DB1C;
typedef struct Ob_8005DB1C {
    u8 pad0[0x18];
    u8 flags;
    u8 state;
    u8 pad1a[0xa];
    St_8005DB1C* s;
} Ob_8005DB1C;
extern s32 fn_800553B4(void);
extern void fn_80034690(void*);
extern void fn_80226DC4(void);
typedef struct Cmd {
    u8 pad0[0x10];
    u32 flags;          /* 0x10 */
    u8 pad14[4];
    s16 s18;            /* 0x18 */
    s16 s1a;            /* 0x1A */
    s16 s1c;            /* 0x1C */
    s16 s1e;            /* 0x1E */
    s16 s20;            /* 0x20 */
    s16 s22;            /* 0x22 type */
    s16 s24;            /* 0x24 */
    u8 pad26[2];
    f32 f28;            /* 0x28 */
    f32 f2c;            /* 0x2C */
    f32 f30;            /* 0x30 */
    f32 f34;            /* 0x34 */
    f32 f38;            /* 0x38 */
} Cmd;
/* Screen shake parameters (fn_8006097C). */
typedef struct Shake {
    u8 b0;
    u8 kind;
    s8 amp;
    u8 dur;
    u8 b4;
    u8 pad5[3];
} Shake;
typedef struct Work {
    s16 cnt;            /* 0x00 */
    u8 pad2[2];
    void* x4;           /* 0x04 */
    s16 timer;          /* 0x08 */
    u8 pada[2];
    f32 f0c;            /* 0x0C */
    f32 f10;            /* 0x10 */
    f32 f14;            /* 0x14 */
    f32 f18;            /* 0x18 */
    f32 f1c;            /* 0x1C */
    u8 pad20[4];
    f32 f24;            /* 0x24 */
    f32 f28;            /* 0x28 */
    f32 f2c;            /* 0x2C */
    Shake shake;        /* 0x30 */
    Cmd* cmd;           /* 0x38 */
} Work;
extern void fn_80060A54(void);
extern void fn_8006097C(Shake* s);
extern s32 fn_80075C70(void*, s32, s32);
extern s32 fn_8022E068(f32* p, s32 i, f32* a, f32* b, f32* c, f32* d);
/* 12-byte block descriptor: a heap array of 16- or 24-byte records, chosen by the low nibble of kind. */
typedef struct Block {
    void* data;         /* 0x00 */
    u32 x4;             /* 0x04 */
    u16 x8;             /* 0x08 */
    u16 kind;           /* 0x0A */
} Block;
typedef struct Rec16 { s32 w[4]; } Rec16;
typedef struct Rec24 { s32 w[6]; } Rec24;
/* Work of this task: p0 links to a record whose 0x24 link holds the 0x4c link to a record with s16 at 0x6. */
typedef struct WkLink2 {
    u8 pad_0[0x6];
    s16 s6;
} WkLink2;
typedef struct WkLink1 {
    u8 pad_0[0x4c];
    WkLink2 *p4c;
} WkLink1;
typedef struct WkTop {
    u8 pad_0[0x24];
    WkLink1 *p24;
} WkTop;
typedef struct Work62 {
    WkTop *p0;
    s16 s4;
} Work62;
s16 fn_80010CBC(s16 i);
typedef struct TblObj {
    s8 kind;
    u8 pad1[7];
    s16 x8;
} TblObj;
typedef struct TblEnt_8006B5B8 {
    TblObj *f0;
    void *f4;
    u32 f8;
    u8 fc;
    u8 pad[3];
} TblEnt_8006B5B8;
extern void *fn_802268E8(void *a, void *fp);
void fn_8006BEFC(O6BEFC *o);
extern s8 lbl_803092F4[12];
extern s8 lbl_80347335;
extern void fn_8006C8DC(char *, char *);
extern void fn_80074E2C(char *, char *, void *, int, int);

void fn_80055E94(u8 *p) {
    p[0x18] |= 0x40;
    lbl_8030A10C.count -= 1;
}

typedef struct Ob_80056B6C {
    u8 pad0[8];
    Ctx_8006CEEC* x8;
} Ob_80056B6C;
typedef struct A_80056B6C {
    u8 pad0[8];
    s32 x8;
    u8 pad_c[4];
    u32 flags;
    s16 s14;
    s16 s16_;
    u8 pad18[2];
    s16 s1a;
    s16 s1c;
    u8 pad1e[2];
    f32 f20;
    f32 f24;
    f32 f28;
    f32 f2c;
} A_80056B6C;
/* fn_8003484C's draw request: the object, two motions, the frame, alpha and scale. */
typedef struct {
    void* obj;          /* 0x00 */
    Motion* a;          /* 0x04 */
    Motion* b;          /* 0x08 */
    f32 f;              /* 0x0C */
    f32 alpha;          /* 0x10 */
    f32 sx, sy, sz;     /* 0x14 */
} Disp;
typedef struct W_80056B6C {
    u8 pad0[0xc];
    Motion* tex;
    Ob_80056B6C* x10;
    u8 pad14[2];
    s16 s16_;
    u8 pad18[0x28 - 0x18];
    s32 a28, a2c, a30;
    u8 pad34[0x4c - 0x34];
    f32 f4c;
    s16 cnt;
    u8 pad52[6];
    f32 f58;
    u8 pad5c[4];
    Disp x60;
    u8 pad80[0x8c - 0x80];
    A_80056B6C* a;
} W_80056B6C;
extern s32 fn_80227068(s32);
s32 fn_8006CEEC(Ctx_8006CEEC *c, Motion **out, u32 idx, s32 slot);
extern void fn_8003484C(Disp*);

static inline s32 Btn(void)
{
    if (fn_80227068(1) == 0) {
        if (fn_80227068(1) != 0) {
            return 1;
        }
        return 0;
    }
    return 1;
}

static inline s32 FadeStep(W_80056B6C* w)
{
    s16 d = w->a->s1a;
    if (d == 0) {
        return 0;
    }
    w->f58 = w->f58 - 1.0f / d;
    if (w->f58 <= -1.0f) {
        w->f58 = -1.0f;
        return 0;
    }
    return 1;
}

/* Command of the sweep-hit effect task fn_800565B0. */
typedef struct {
    u8 pad0[6];
    s16 flags6;            /* 0x06 */
    u8 pad8[8];
    u32 flags10;           /* 0x10 */
    s16 s14;
    s16 s16;
    s16 s18;
    u8 pad1A[2];
    V3 p1c;        /* 0x1C */
    f32 f28;               /* 0x28 */
    u32 flags2c;           /* 0x2C */
    f32 f30;               /* 0x30 */
} Cfg_800565B0;

typedef struct {
    u16 frame;             /* 0x00 */
    u8 pad2[2];
    CamObj *a;          /* 0x04 */
    NJS_MATRIX *m;         /* 0x08 */
    s8 seen[14];           /* 0x0C */
    s16 s1a, s1c;          /* 0x1A */
    u8 pad1E[2];
    V3 p20[2];     /* 0x20 */
    Vec3 dir;        /* 0x38 */
    Cfg_800565B0 *cfg;              /* 0x44 */
} W_800565B0;

typedef struct {
    u8 pad0[0x18];
    u8 flags;              /* 0x18 */
    u8 state;              /* 0x19 */
    u8 pad1A[0x24 - 0x1A];
    W_800565B0 *work;               /* 0x24 */
} O800565B0;

typedef struct { u8 r, g, b, a; } Col_800565B0;
extern u32 lbl_803472F4;
void fn_80017778(void);
void fn_80060B20(Vec3 *v, f32 x);
void fn_80020B50(CamObj *t, s16 *a, s16 *b);
void fn_80076478(void *p, void *q, u16 a, s32 b);
void fn_8007638C(void *p, void *q, u16 a);
s32 fn_80018498(V3 *p);
s8 fn_80018178(V3 *a, V3 *b, V3 *c, s8 *ids);
s32 fn_8001DC7C(u8 id, CamObj *t);
s32 fn_8001D944(u8 id, CamObj *t);
void fn_8004BFD8(CamObj *t);
void fn_80032FC4(V3 *a, V3 *b, Col_800565B0 *c, Col_800565B0 *d);

static inline void Hit(O800565B0 *t, W_800565B0 *w, CamChr *self, s32 flag)
{
    if (w->cfg->flags2c & 0x400) {
        fn_8004BFD8(w->a);
    } else {
        self->fec |= 0x80;
        fn_80020B8C(w->a, w->s1a, w->s1c, flag);
        self->fec &= ~0x80;
    }
}

void fn_800565B0(O800565B0 *t)
{
    s16 k;
    s16 m;
    s8 cnt;
    W_800565B0 *w;
    CamChr *self;
    s16 n;
    s32 flag;
    V3 loc44[2];
    V3 loc38;
    s8 ids[16];
    V3 loc1c;
    V3 loc10;
    Col_800565B0 ca;
    Col_800565B0 cb;

    w = t->work;
    flag = 0;
    self = w->a->body->chr;
    if (w->cfg->flags10 & 0x400)
        flag = 1;

    switch (t->state) {
    case 0:
        self->fec |= 0x80000;
        self->fec |= 0x40000;
        fn_80017778();
        fn_80020B50(w->a, &w->s1a, &w->s1c);
        t->state = 1;
    case 1:
        if (w->frame < w->cfg->s14)
            break;
        t->state = 2;
        switch (w->cfg->flags10 & 0xF) {
        case 2:
            w->m = fn_801E1C7C(0x40);
            fn_80076478(w->m, self->p154, w->cfg->s18, 0);
        }
        fn_80071CF0(&w->cfg->p1c, &w->p20[0]);
        fn_80071CF0(&w->cfg->p1c, &w->p20[1]);
        fn_80060B20(&w->dir, w->cfg->f30);
        break;
    case 2:
        n = 3;
        for (k = 0; k < 2; k++) {
            if (w->m != NULL) {
                fn_80061518(&w->p20[k], &loc44[k], w->m);
                fn_80061518(&w->cfg->p1c, &loc38, w->m);
            } else {
                fn_8001E4A0(&w->p20[k], &loc44[k], w->a);
                fn_8001E4A0(&w->cfg->p1c, &loc38, w->a);
            }
            if (fn_80018498(&loc44[k]) == 0)
                n--;
        }
        fn_80071CF0(&w->p20[0], &loc1c);
        loc1c.x = 0.0f;
        if (w->m != NULL)
            fn_80061518(&loc1c, &loc10, w->m);
        else
            fn_8001E4A0(&loc1c, &loc10, w->a);
        if (fn_80018498(&loc10) == 0)
            n--;
        cnt = fn_80018178(&loc38, &loc44[0], &loc44[1], ids);
        for (m = 0; m < cnt; m++) {
            if (ids[m] < 0)
                break;
            if (ids[m] == self->b0)
                continue;
            if (w->seen[ids[m]] != 0)
                continue;
            w->seen[ids[m]] = 1;
            self->b5a = ids[m];
            if (fn_8001DC7C(ids[m], w->a) != 0) {
                if (!(w->cfg->flags2c & 0x4000))
                    t->state = 0xfa;
                Hit(t, w, self, flag);
            } else if (w->cfg->flags2c & 0x2000) {
                if (fn_8001D944(ids[m], w->a) != 0)
                    Hit(t, w, self, flag);
            }
            if (w->cfg->flags2c & 0x8000)
                t->state = 0xfa;
        }
        if ((lbl_80347394 != NULL && (lbl_80347394->work->f3c & 0x40)) || (lbl_803472F4 & 0x20000000)) {
            ca.r = 255;
            ca.g = 255;
            ca.b = 0;
            ca.a = 0;
            cb.r = 255;
            cb.g = 255;
            cb.b = 0;
            cb.a = 0;
            fn_80032FC4(&loc38, &loc44[0], &ca, &cb);
            fn_80032FC4(&loc38, &loc44[1], &ca, &cb);
            fn_80032FC4(&loc44[0], &loc44[1], &ca, &cb);
        }
        if (w->frame >= w->cfg->s16 && w->cfg->s16 != 0) {
        } else {
            w->p20[0].x = w->dir.x * w->cfg->f28 + w->p20[0].x;
            w->p20[0].z = w->dir.z * w->cfg->f28 + w->p20[0].z;
            w->p20[1].x = w->p20[1].x - w->dir.x * w->cfg->f28;
            w->p20[1].z = w->dir.z * w->cfg->f28 + w->p20[1].z;
        }
        if (n <= 0)
            t->state = 0xfa;
        break;
    case 4:
        if (lbl_8030A10C.f1cc & 0x20) {
            t->state = 1;
            w->frame = w->cfg->s14;
        }
        break;
    case 0xfa:
        fn_8001D14C(self);
        if (w->m != NULL) {
            fn_8007638C(w->m, self->p154, w->cfg->s18);
            fn_801E17E0(w->m);
        }
        t->flags |= 0x40;
        lbl_8030A10C.count--;
        return;
    }
    w->frame++;
    if (w->cfg->flags6 & 0x2000) {
        switch (t->state) {
        case 1:
            break;
        default:
            lbl_8030A10C.f1cc |= 0x10;
        }
        if ((lbl_8030A10C.f1cc & 0x80) && !(lbl_8030A10C.f1cc & 0x20)) {
            switch (t->state) {
            case 1:
                t->state = 4;
            }
        }
    }
}

void fn_80056B6C(Task* o)
{
    W_80056B6C* w = o->work;
    switch (o->state) {
    case 0:
        fn_8006D954(w->a->x8);
        w->a28 = 182.04445f * w->a->f20;
        w->a2c = 182.04445f * w->a->f24;
        w->a30 = 182.04445f * w->a->f28;
        o->state = 1;
        if (!Btn()) {
            o->state = 3;
            return;
        }
    case 1:
        if (w->cnt != w->a->s14) {
            break;
        }
        lbl_8030A10C.f6c |= 0x40000000;
        fn_8006CEEC(w->x10->x8, &w->tex, 0, w->s16_);
        w->f4c = w->a->f2c;
        if (!Btn()) {
            o->state = 3;
            return;
        }
        o->state = 2;
    case 2:
        if (w->cnt == w->a->s1c && w->a->s1c != 0) {
            lbl_8030A10C.f6c &= ~0x40000000;
        }
        if (w->cnt >= w->a->s14) {
            if (w->tex != 0) {
                w->f4c += 1.0f;
                if (w->f4c >= (f32)w->tex->nbFrame - 1.0f) {
                    if (w->a->flags & 0x8000000) {
                        w->f4c = (f32)w->tex->nbFrame - 1.0f;
                    } else {
                        w->f4c = 0.0f;
                    }
                }
            }
            w->x60.a = w->tex;
            fn_8006CEEC(w->x10->x8, &w->x60.b, 1, w->s16_);
            w->x60.obj = w;
            w->x60.f = w->f4c;
            fn_8002FEB0(fn_8003484C, &w->x60, 0);
        }
        if (w->cnt >= w->a->s16_) {
            if (!FadeStep(w)) {
                lbl_8030A10C.f6c &= ~0x40000000;
                o->state = 0xfa;
            }
            w->x60.alpha = w->f58;
        }
        break;
    case 0xf9:
        lbl_8030A10C.f6c &= ~0x40000000;
    case 0xfa:
        fn_80226DC4();
    case 3:
        fn_8006D8DC(w->a->x8);
        o->flags |= 0x40;
        lbl_8030A10C.count--;
        return;
    }
    w->cnt = w->cnt + 1;
    fn_80037FD8(w->a, &o->state);
}

void fn_80056FA4(f32 *out, s16 flag) {
    if (flag) {
        *out = -1.0f;
    } else {
        *out = 0.0f;
    }
}

typedef struct A_8005ACD4 {
    u8 pad0[8];
    s32 x8;
    u8 pad_c[4];
    u32 flags;
    u8 pad14[4];
    s16 id;
    u8 pad1a[2];
    V3 v1c;
    f32 v28[3];
    f32 f34;
    s16 s38;
    s16 s3a;
} A_8005ACD4;
typedef struct S_8005ACD4 {
    s16 cnt;
    u8 pad2[6];
    void* x8;
    f32 fc;
    u8 pad10[0xc];
    V3 v1c;
    u32 v28[3];
    A_8005ACD4* a;
    s32 x38;
} S_8005ACD4;
typedef struct EvMotWork {
    void* x0;
    u8 pad4[4];
    void* x8;
    Motion* tex;
    Ob_80056B6C* x10;
    u8 pad14[2];
    s16 s16_;
    u8 pad18[4];
    V3 v1c;
    s32 a28, a2c, a30;
    u8 pad34[0x4c - 0x34];
    void* s;
    s32 x50;
    s32 x54;
} EvMotWork;
typedef struct EvMotTask {
    u8 pad0[0x18];
    u8 flags;
    u8 state;
    u8 pad1A[10];
    EvMotWork* w;
} EvMotTask;
extern ChrTask* fn_800215EC(s8);
void fn_800614FC(u32 *src, u32 *dst);
extern void fn_8004034C(void*, u32, void**);
extern void fn_800402FC(void*, u32, void**);
extern void fn_80032E44(void*);
extern void fn_80034AF0(void*, s16, void*, void*, void*, s32, f32);

typedef struct {
    u8 pad0[0x6];
    s16 flags;          /* 0x06 */
    s32 src;            /* 0x08 */
    u8 pad0c[0x4];
} CmdHead;

/* Particle (the layout of Part in effect.c). */
typedef struct {
    s16 timer;          /* 0x000 */
    s16 start;          /* 0x002 */
    s16 life;           /* 0x004 */
    u8 pad6[2];
    V3 pos;            /* 0x008 */
    V3 vel0;           /* 0x014 */
    V3 vel;            /* 0x020 */
    f32 gravity;        /* 0x02C */
    f32 drag;           /* 0x030 */
    f32 scale;          /* 0x034 */
    u8 pad38[0x40 - 0x38];
    u32 flags;          /* 0x040 */
    u32 type;           /* 0x044 */
    u8 alpha;           /* 0x048 */
    u8 alphaStep;       /* 0x049 */
    s16 bounces;        /* 0x04A */
    s16 maxBounces;     /* 0x04C */
    u8 pad4e[2];
    f32 bounce;         /* 0x050 */
    u8 pad54[0x98 - 0x54];
    f32 x98;            /* 0x098 */
    f32 x9c;            /* 0x09C */
    f32 xa0;            /* 0x0A0 */
    u8 pada4[0x1DC - 0xA4];
    s32 src;            /* 0x1DC */
    CmdHead hdr;        /* 0x1E0 */
} Part;

/* Work of a particle task. */
typedef struct {
    u8 pad0[0x8];
    void* model;        /* 0x08 */
    u8 pad0c[0x1C - 0xC];
    V3 pos;            /* 0x1C */
    s32 ang[3];         /* 0x28 */
    f32 sc[3];          /* 0x34 */
    u8 pad40[4];
    u8 col;             /* 0x44 */
    u8 pad45[0x4C - 0x45];
    Part* part;         /* 0x4C */
    s32 x50;
    s32 x54;
} PartWork;

/* A task whose work is a PartWork. */
typedef struct {
    u8 pad0[0x18];
    u8 flags;           /* 0x18 */
    u8 state;           /* 0x19 */
    u8 pad1A[0x24 - 0x1A];
    PartWork* work;     /* 0x24 */
} PartTask;

extern s32 lbl_80346BD0;
extern int fn_8007E264(f32* out, f32 x, f32 z);
extern void fn_80040044(DrawState* s, f32 alpha, u32 mask, u8* flag);
extern s32 fn_80035908(void);
extern void fn_80035910(s32);

void fn_8005A7B8(PartTask* node)
{
    PartWork* w = node->work;
    Part* d = w->part;
    DrawState st;
    u8 col;
    f32 save = 0.0f;

    switch (node->state) {
    case 0:
        fn_8006D954(d->src);
        w->sc[0] = d->scale;
        w->sc[1] = d->scale;
        w->sc[2] = d->scale;
        w->ang[0] += (s32)(182.04445f * d->x98);
        w->ang[1] += (s32)(182.04445f * d->x9c);
        w->ang[2] += (s32)(182.04445f * d->xa0);
        node->state = 1;
        node->work->x50 = d->src;
        node->work->x54 = -1;
    case 1:
        if (d->timer < d->start) {
            break;
        }
        node->state = 2;
        fn_80071CF0(&d->vel0, &d->vel);
    case 2:
        w->ang[0] += (s32)(182.04445f * d->x98);
        w->ang[1] += (s32)(182.04445f * d->x9c);
        w->ang[2] += (s32)(182.04445f * d->xa0);
        d->pos.x += d->vel.x;
        d->pos.y += d->vel.y;
        d->pos.z += d->vel.z;
        d->vel.x *= d->drag;
        d->vel.y += d->gravity;
        d->vel.z *= d->drag;
        if (d->timer >= d->life) {
            if (d->alpha <= d->alphaStep) {
                d->alpha = 0;
                node->state = 0xFA;
            } else {
                d->alpha -= d->alphaStep;
            }
        }
        if (d->flags & 0x80000000) {
            fn_8007E264(&w->pos.y, d->pos.x, d->pos.z);
            if (w->pos.y >= d->pos.y) {
                d->pos.y = w->pos.y;
                if (d->vel0.y < 0.0f) {
                    if (d->bounce) {
                        d->vel.y = d->vel.y * d->bounce;
                    } else {
                        d->vel.y = d->vel.y * d->drag;
                    }
                } else {
                    if (d->bounce) {
                        d->vel.y = d->vel0.y * d->bounce;
                    } else {
                        d->vel.y = d->vel0.y * d->drag;
                    }
                }
                if (d->vel.y < 0.0f) {
                    d->vel.y *= -1.0f;
                }
                d->pos.y = 0.0f;
                d->bounces++;
            }
            if (d->flags & 0x400000) {
                if (d->x98) {
                    save = d->x98;
                    d->x98 = 0.0f;
                } else if (d->x9c) {
                    save = d->x9c;
                    d->x9c = 0.0f;
                } else if (d->xa0) {
                    save = d->xa0;
                    d->xa0 = 0.0f;
                }
                switch (rand() % 3) {
                case 0:
                    d->x98 = save;
                    break;
                case 1:
                    d->x9c = save;
                    break;
                case 2:
                    d->xa0 = save;
                    break;
                }
            }
        }
        fn_80071CF0(&d->pos, &w->pos);
        if (node->work->x50 == 0x1D3C61) {
            lbl_80346BD0 = fn_80035908();
            fn_80035910(0x1004000);
        }
        DrawStateDefault2D(&st);
        col = w->col;
        fn_80040044(&st, -1.0f + d->alpha / 255.0f, d->type, &w->col);
        if (DrawStatePush(&st) != 0) {
            fn_80032E44(w->model);
            fn_80034AF0(w, -1, NULL, NULL, NULL, 0, 0.0f);
            DrawStatePop(NULL);
        }
        w->col = col;
        if (node->work->x50 == 0x1D3C61) {
            fn_80035910(lbl_80346BD0);
        }
        break;
    case 0xF9:
    case 0xFA:
        fn_8006D8DC(d->src);
        fn_801E17E0(d);
        node->flags |= 0x40;
        lbl_8030A10C.count--;
        return;
    }
    d->timer++;
    if ((d->flags & 0x20000000) && d->bounces >= d->maxBounces) {
        d->timer = d->life;
    }
    fn_80037FD8(&d->hdr, &node->state);
}

void fn_8005ACD4(EvMotTask* o)
{
    EvMotWork* w;
    S_8005ACD4* s;
    ChrInfo* unit;
    ChrTask* task;
    unit = 0;
    w = o->w;
    s = w->s;
    task = fn_800215EC(s->a->id);
    if (task != 0) {
        unit = task->work->u;
    }
    switch (o->state) {
    case 0:
        if (task == 0) {
            o->state = 3;
            return;
        }
        fn_8006D954(s->a->x8);
        fn_8004034C(w->x0, 0, &s->x8);
        fn_8006CEEC(w->x10->x8, &w->tex, 0, w->s16_);
        fn_80071CF0(&s->a->v1c, &w->v1c);
        w->a28 = 182.04445f * s->a->v28[0];
        w->a2c = 182.04445f * s->a->v28[1];
        w->a30 = 182.04445f * s->a->v28[2];
        o->state = 1;
        o->w->x50 = s->a->x8;
        o->w->x54 = -1;
        break;
    case 1:
        if (task == 0) {
            o->state = 0xfa;
            return;
        }
        if (s->cnt >= s->a->s38) {
            if (!(unit->ff0 & 0x40000000)) {
                fn_80071CF0(&task->work->v1c, &s->v1c);
                fn_800614FC(task->work->rot, s->v28);
                unit->ff0 |= 0x40000000;
                s->x38 = 1;
            } else {
                s->x38 = 0;
            }
            unit->f1fc = s->x8;
            o->state = 2;
        } else {
            break;
        }
    case 2:
        if (task == 0) {
            o->state = 0xfa;
            return;
        }
        if (w->tex != 0) {
            s->fc += s->a->f34;
            if (s->fc >= (f32)w->tex->nbFrame - 1.0f) {
                if (s->a->flags & 0x8000000) {
                    s->fc = (f32)w->tex->nbFrame - 1.0f;
                } else {
                    s->fc = 0.0f;
                }
            }
        }
        if (s->cnt >= s->a->s3a) {
            unit->f1fc = 0;
            if (s->x38 != 0) {
                fn_80071CF0(&s->v1c, &task->work->v1c);
                fn_800614FC(s->v28, task->work->rot);
                unit->ff0 &= ~0x40000000;
            }
            o->state = 0xfa;
        }
        break;
    case 0xf9:
        if (unit != 0) {
            unit->f1fc = 0;
        }
    case 0xfa:
        fn_8006D8DC(s->a->x8);
        fn_800402FC(w->x0, 0, &s->x8);
        fn_801E17E0(s);
        o->flags |= 0x40;
        lbl_8030A10C.count--;
        return;
    case 3:
        fn_801E17E0(s);
        o->flags |= 0x40;
        lbl_8030A10C.count--;
        return;
    }
    {
        DrawState st;
        DrawStateDefault2D(&st);
        if (DrawStatePush(&st) != 0) {
            fn_80032E44(w->x8);
            fn_80034AF0(w, -1, 0, w->tex, 0, 0, s->fc);
            DrawStatePop(0);
        }
    }
    s->cnt = s->cnt + 1;
    fn_80037FD8(s->a, &o->state);
}

typedef struct Data_8005BBC4 {
    u8 pad0[8];
    s32 x8;
    u8 padc[4];
    u32 x10;
    u8 pad14[4];
    V3 v18;
    f32 x24;
    s16 x28;
    s16 x2a;
} Data_8005BBC4;
typedef struct Sub_8005BBC4 {
    s16 t;
    u8 pad2[2];
    ChrTask* owner;
    void* x8;
    f32 xc;
    V3 v10;
    V3 v1c;
    u32 v28[3];
    Data_8005BBC4* d;
    s32 x38;
} Sub_8005BBC4;


/* Command of the fade-in effect task fn_8005B648. */
typedef struct {
    u8 pad0[8];
    s32 src;            /* 0x08 */
    u8 padc[4];
    u32 flags;          /* 0x10 */
    u8 pad14[4];
    s16 s18;            /* 0x18 */
    s16 s1a;            /* 0x1A */
    u8 pad1c[2];
    s16 s1e;            /* 0x1E */
    f32 f20;            /* 0x20 */
    f32 f24;            /* 0x24 */
    f32 f28;            /* 0x28 */
    f32 f2c;            /* 0x2C */
    f32 f30;            /* 0x30 */
    f32 f34;            /* 0x34 */
    f32 f38;            /* 0x38 */
} Cmd_8005B648;

typedef struct W_8005B648 {
    void* x0;
    u8 pad4[0x28 - 4];
    s32 ang[3];         /* 0x28 */
    u8 pad34[0x50 - 0x34];
    s16 cnt;            /* 0x50 */
    u8 pad52[6];
    f32 step;           /* 0x58 */
    Disp d1;            /* 0x5C */
    u8 pad7C[0x88 - 0x7C];
    Disp d2;            /* 0x88 */
    u8 padA8[0xB4 - 0xA8];
    Cmd_8005B648* a;    /* 0xB4 */
} W_8005B648;

void fn_8005B648(Task* o)
{
    W_8005B648* w = o->work;
    W_8005B648* s = NULL;

    if (w->x0 != NULL) {
        s = w;
    }
    switch (o->state) {
    case 0:
        if (w->a->src != 0) {
            fn_8006D954(w->a->src);
        } else {
            fn_8006D954(1);
        }
        if (s != NULL) {
            s->ang[0] = 182.04445f * w->a->f30;
            s->ang[1] = 182.04445f * w->a->f34;
            s->ang[2] = 182.04445f * w->a->f38;
        }
        o->state = 1;
        if (fn_800553B4() == 0) {
            o->state = 3;
            return;
        }
    case 1:
        if (w->cnt != w->a->s18) {
            break;
        }
        if (fn_800553B4() == 0) {
            o->state = 3;
            return;
        }
        lbl_8030A10C.f6c |= 0x40000000;
        w->d1.a = NULL;
        w->d1.obj = s;
        w->d1.alpha = 0.0f;
        w->d1.sx = 1.0f;
        w->d1.sy = 1.0f;
        w->d1.sz = 1.0f;
        fn_8002FEB0(fn_8003484C, &w->d1, 0);
        w->d2.a = NULL;
        w->d2.obj = s;
        w->d2.alpha = w->a->f2c;
        if (w->d2.alpha < -1.0f) {
            w->d2.alpha = -1.0f;
        }
        if (w->d2.alpha > 0.0f) {
            w->d2.alpha = 0.0f;
        }
        w->d2.sx = 1.0f + w->a->f20;
        w->d2.sy = 1.0f + w->a->f24;
        w->d2.sz = 1.0f;
        o->state = 2;
        if (w->a->s1e != 0) {
            w->step = w->a->f28;
        } else {
            w->step = w->a->f2c;
        }
        break;
    case 2:
        if (w->cnt == w->a->s1e && w->a->s1e != 0) {
            lbl_8030A10C.f6c &= ~0x40000000;
        }
        if (w->cnt >= w->a->s18) {
            fn_8002FEB0(fn_8003484C, &w->d2, 0x80000000);
            if (lbl_8030A10C.f6c & 0x40000000) {
                fn_8002FEB0(fn_8003484C, &w->d1, 0);
            }
        }
        if (w->cnt >= w->a->s1a + (s16)(-1.0f * (1.0f / w->step))) {
            lbl_8030A10C.f6c &= ~0x40000000;
            o->state = 4;
        }
        if (w->cnt >= w->a->s1a) {
            w->d2.alpha += w->step;
            if (w->d2.alpha < -1.0f) {
                w->d2.alpha = -1.0f;
            }
            if (w->d2.alpha > 0.0f) {
                w->d2.alpha = 0.0f;
            }
        }
        break;
    case 0xF9:
        lbl_8030A10C.f6c &= ~0x40000000;
    case 4:
        fn_80226DC4();
    case 3:
        if (w->a->src != 0) {
            fn_8006D8DC(w->a->src);
        } else {
            fn_8006D8DC(1);
        }
        if (w->a->flags & 0x8000) {
            lbl_8030A10C.f6c |= 0x800;
        }
        o->flags |= 0x40;
        lbl_8030A10C.count--;
        return;
    case 5:
        fn_80226DC4();
        if (w->a->flags & 0x8000) {
            lbl_8030A10C.f6c |= 0x800;
        }
        o->flags |= 0x40;
        lbl_8030A10C.count--;
        return;
    }
    w->cnt++;
    fn_80037FD8(w->a, &o->state);
}

void fn_8005BBC4(EvMotTask* t)
{
    EvMotWork* w;
    Sub_8005BBC4* s;
    ChrInfo* info;
    ChrTask* obj;
    DrawState ds;
    info = 0;
    w = t->w;
    s = w->s;
    obj = fn_8001E05C(s->owner);
    if (obj) info = obj->work->u;
    switch (t->state) {
    case 0:
        if (obj == 0) {
            t->state = 3;
            return;
        }
        fn_8006D954(s->d->x8);
        fn_8004034C(w->x0, 0, &s->x8);
        fn_8006CEEC(w->x10->x8, &w->tex, 0, w->s16_);
        fn_80071CF0(&s->d->v18, &s->v10);
        t->state = 1;
        t->w->x50 = s->d->x8;
        t->w->x54 = -1;
        break;
    case 1:
        if (obj == 0) {
            t->state = 0xfa;
            return;
        }
        if (s->t < s->d->x28) break;
        if (!(info->ff0 & 0x40000000)) {
            fn_80071CF0(&obj->work->v1c, &s->v1c);
            fn_800614FC(obj->work->rot, s->v28);
            info->ff0 |= 0x40000000;
            s->x38 = 1;
        } else {
            s->x38 = 0;
        }
        info->f1fc = s->x8;
        t->state = 2;
    case 2:
        if (obj == 0) {
            t->state = 0xfa;
            return;
        }
        fn_80071CF0(&s->v10, &w->v1c);
        if (w->tex != 0) {
            s->xc = s->xc + s->d->x24;
            if (s->xc >= (f32)w->tex->nbFrame - 1.0f) {
                if (s->d->x10 & 0x08000000) s->xc = (f32)w->tex->nbFrame - 1.0f;
                else s->xc = 0.0f;
            }
        }
        if (s->t < s->d->x2a) break;
        info->f1fc = 0;
        if (s->x38 != 0) {
            fn_80071CF0(&s->v1c, &obj->work->v1c);
            fn_800614FC(s->v28, obj->work->rot);
            info->ff0 &= ~0x40000000;
        }
        t->state = 0xfa;
        break;
    case 0xf9:
        if (info != 0) info->f1fc = 0;
    case 0xfa:
        fn_8006D8DC(s->d->x8);
        fn_800402FC(w->x0, 0, &s->x8);
        fn_801E17E0(s);
        t->flags |= 0x40;
        lbl_8030A10C.count--;
        return;
    case 3:
        fn_801E17E0(s);
        t->flags |= 0x40;
        lbl_8030A10C.count--;
        return;
    }
    DrawStateDefault2D(&ds);
    if (DrawStatePush(&ds)) {
        fn_80032E44(w->x8);
        fn_80034AF0(w, -1, 0, w->tex, 0, 0, s->xc);
        DrawStatePop(0);
    }
    s->t++;
    fn_80037FD8(s->d, &t->state);
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

extern void fn_80065498(T5C188*, T5C188*);
extern int fn_80018B80(f32*);
extern void fn_80018C94(void);
extern void fn_80018AFC(void*, void*, void*);
extern void fn_800657A0(T5C188*, s16);
extern void fn_80035140(void* a, u8 b);
extern void fn_800351B4(void*, void*, f32, u8);
extern void njMultiMatrix(NJS_MATRIX m, NJS_MATRIX src);

static inline s32 TypeA(s16 t)
{
    switch (t) {
    case 0x1A:
    case 0x1B:
    case 0x1C:
        return 1;
    default:
        return 0;
    }
}

static inline s32 TypeB(s16 t)
{
    switch (t) {
    case 4:
    case 5:
    case 8:
        return 1;
    default:
        return 0;
    }
}

void fn_80065AB0(T5C188* o, s16 idx)
{
    U5C188* tob;
    T5C188* t;
    W5C188* d;
    U5C188* ob;
    W5C188* td;
    f32 f;
    V3 pos;
    u32 rot[3];

    d = o->work;
    ob = d->u;
    t = fn_80021658(lbl_80346BD8->x90);
    tob = t->work->u;
    td = t->work;

    if (lbl_80346BD8->x8e & 3) {
        if (tob->x1f4 != NULL) {
            fn_80299040(tob->x1f4);
        } else {
            fn_80299040(d->tex);
        }
    } else {
        fn_80299040(d->tex);
    }
    ob->xea = idx;
    if (tob->f164 < 0.0f && !(lbl_80346BD8->f7c & 0x10000000)) {
        ob->f164 = tob->f164;
    } else {
        ob->f164 = lbl_80346BD8->f6c;
    }
    f = ob->f164;
    if (!(lbl_80346BD8->f7c & 0x2000000)) {
        fn_80071CF0(&td->pos, &pos);
    } else {
        fn_80071CF0(&d->pos, &pos);
    }
    if (TypeA(ob->kind) == 1) {
        fn_800614FC(td->rot, d->rot);
    } else if (ob->kind != 6 && ob->kind != 0x13 && TypeB(ob->kind) != 1) {
        fn_80065498(o, t);
    }
    fn_800614FC(d->rot, rot);
    njPushMatrixEx();
    fn_80286EE8();
    fn_8028B498();
    if (fn_80018B80(&ob->f164)) {
        if (ob->x1fc != NULL) {
            njMultiMatrix(NULL, *ob->x1fc);
        } else {
            njTranslate(NULL, pos.x, pos.y, pos.z);
            njRotateXYZ(NULL, rot[0], rot[1], rot[2]);
            njTranslate(NULL, 0.0f, lbl_80346BD8->x20, 0.0f);
            njRotateY(NULL, 182.04445f * lbl_80346BD8->ang[1]);
            njTranslate(NULL, lbl_80346BD8->v8[0], lbl_80346BD8->v8[1], lbl_80346BD8->v8[2]);
            njRotateXYZ(NULL, 182.04445f * lbl_80346BD8->v[0], 182.04445f * lbl_80346BD8->v[1], 182.04445f * lbl_80346BD8->v[2]);
            njRotateZ(NULL, 182.04445f * lbl_80346BD8->f50);
        }
        njScale(NULL, d->scl[0], d->scl[1], d->scl[2]);
        if (ob->xec & 0x80000000) {
            if (ob->p60 != NULL) {
                if (f > -1.0f) {
                    fn_80035468(ob->p154, ob->a74, ob->a84, ob->f68, d->b44);
                }
            } else if ((ob->tbl[idx].flags8 & 0x200000) || (ob->tbl[ob->xe8].flags8 & 0x200000)) {
                if (f > -1.0f) {
                    fn_800351B4(ob->p154, ob->a74, ob->f68, d->b44);
                }
            } else {
                if (f > -1.0f) {
                    fn_80035228(ob->p154, ob->a74, ob->f68, d->b44);
                }
            }
            ob->f68 = ob->f68 + ob->f6c;
            if (ob->f68 > 1.0f) {
                ob->f68 = 1.0f;
            }
        } else if (ob->p5c != NULL) {
            if (ob->p60 != NULL) {
                if (f > -1.0f) {
                    fn_800353F4(ob->p154, ob->p5c, ob->p60, ob->f68, d->b44);
                }
            } else {
                if (f > -1.0f) {
                    fn_80035380(ob->p154, ob->p5c, ob->f68, d->b44);
                }
                if (ob->xec & 0x2000000) {
                    fn_80018AFC(o, ob, d);
                }
            }
            fn_800657A0(o, idx);
        } else {
            fn_80035140(ob->p154, d->b44);
            ob->x70 = 1;
        }
        fn_80018C94();
    }
    njPopMatrixEx();
    if (ob->x70 != 0 && (ob->xec & 1)) {
        ob->xec &= ~1;
        fn_80075F2C(o);
    }
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

extern void fn_800341B0(V3*, u8, u8);
extern void fn_8028708C(s32, f32, f32, f32);
extern void fn_8028703C(s32, f32, f32, f32);
extern void fn_80286FEC(s32, f32, f32);
extern void fn_80287124(s32, f32, f32, f32);
extern void fn_802871D8(f32, f32, f32);
extern void fn_8028B63C(s32, f32, f32, f32);
extern void fn_8028B6D4(s32, f32, f32, f32);
extern void fn_8028B784(f32, f32, f32);

#define CLAMP3(a, b, c)    \
    if ((a) < 0.0f) {      \
        (a) = 0.0f;        \
    }                      \
    if ((b) < 0.0f) {      \
        (b) = 0.0f;        \
    }                      \
    if ((c) < 0.0f) {      \
        (c) = 0.0f;        \
    }                      \
    if ((a) > 1.0f) {      \
        (a) = 1.0f;        \
    }                      \
    if ((b) > 1.0f) {      \
        (b) = 1.0f;        \
    }                      \
    if ((c) > 1.0f) {      \
        (c) = 1.0f;        \
    }

void fn_8006B8A8(Eff* e)
{
    V3 v;
    f32 px;
    f32 py;
    f32 pz;
    f32 r;
    f32 g;
    f32 b;
    s32 n;

    switch (e->kind) {
    case 4:
        if (e->x4 & 0x40000000) {
            fn_80287274(e->x8 + 1, 1);
            fn_8028B820(e->x8 + 1, 1);
            if (e->x8 == 0) {
                if (e->x4 & 0x20000000) {
                    fn_80071CF0(&e->pos, &v);
                    v.y += 30.0f;
                    fn_800341B0(&v, 0, 4);
                    v.z = 0.0f;
                    v.x = 0.0f;
                    v.y = 30.0f;
                    fn_800341B0(&v, 0, 4);
                }
                px = e->pos.x;
                py = e->pos.y;
                pz = e->pos.z;
                fn_8028708C(1, px, py, pz);
                r = e->x30;
                b = e->x38;
                g = e->x34;
                CLAMP3(r, g, b)
                fn_80287124(1, r, g, b);
                r = e->x3c;
                b = e->x44;
                g = e->x40;
                CLAMP3(r, g, b)
                fn_802871D8(r, g, b);
                fn_8028B63C(1, px, py, pz);
                r = e->x30;
                b = e->x38;
                g = e->x34;
                CLAMP3(r, g, b)
                fn_8028B6D4(1, r, g, b);
                r = e->x3c;
                b = e->x44;
                g = e->x40;
                CLAMP3(r, g, b)
                fn_8028B784(r, g, b);
            } else {
                if (e->x4 & 0x20000000) {
                    fn_800341B0(&e->pos, 0, 4);
                }
                fn_8028703C(e->x8 + 1, e->pos.x, e->pos.y, e->pos.z);
                r = e->x4c;
                fn_80286FEC(e->x8 + 1, e->x48, 8.0f * r);
                r = e->x30;
                n = e->x8 + 1;
                b = e->x38;
                g = e->x34;
                CLAMP3(r, g, b)
                fn_80287124(n, r, g, b);
            }
        } else {
            fn_80287274(e->x8 + 1, 0);
            fn_8028B820(e->x8 + 1, 0);
        }
        break;
    case 3:
        r = e->x3c;
        b = e->x44;
        g = e->x40;
        CLAMP3(r, g, b)
        fn_802871D8(r, g, b);
        r = e->x3c;
        b = e->x44;
        g = e->x40;
        CLAMP3(r, g, b)
        fn_8028B784(r, g, b);
        break;
    }
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
extern void *fn_802268E8(void *a, void *fp);
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
    *p = (f32)(rand() % 6) * 70.0f;
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
    strcat(buf, a);
    strcat(buf, b);
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
            idx = rand() % s->rec->count;
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
            o->b74 = rand() % 3;
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
        s->f4 = (lbl_80346BD8->x18 + lbl_80346BD8->v8[1]) / (f32)s->s0e;
        s->f8 = (lbl_80346BD8->x18 + lbl_80346BD8->v8[1]) / (f32)(s->s10 - s->s0e);
    case 1:
        lbl_80346BD8->x20 = lbl_80346BD8->x20 - s->f4;
        if (lbl_80346BD8->x20 + lbl_80346BD8->v8[1] <= 0.0f) {
            lbl_80346BD8->x20 = -lbl_80346BD8->v8[1];
            o->state = 2;
            fn_80075FF0(p, 0xf, -1);
        }
        break;
    case 2:
        lbl_80346BD8->x20 = lbl_80346BD8->x20 + s->f8;
        if (lbl_80346BD8->x20 >= lbl_80346BD8->x18) {
            lbl_80346BD8->x20 = lbl_80346BD8->x18;
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
    Wk_8006B46C* w = t->work;
    Eff* e = &w->eff;
    switch (t->state) {
    case 0:
        memset(e, 0, 0x64);
        e->x8 = 1;
        e->x30 = 0.1f;
        e->x34 = 0.5f;
        e->x38 = 0.3f;
        e->pos.y = 60.0f;
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
    W5C188 *w;
    T5C188 *t;
    U5C188 *u;
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
        m = t->work->mdl;
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
            njTranslate(0, w->pos.x, w->pos.y, w->pos.z);
            njRotateXYZ(0, w->rot[0], w->rot[1], w->rot[2]);
            njScale(0, w->scl[0], w->scl[1], w->scl[2]);
            if (fn_8002F52C() != 0) {
                fn_8002F4BC(m, scale, u->p5c);
            } else {
                switch (o->kind) {
                case 0:
                    fn_80035468(m, u->a74, u->a84, scale, mode);
                    break;
                case 1:
                    fn_80035228(m, u->a74, scale, mode);
                    break;
                case 2:
                    fn_800353F4(m, u->p5c, u->p60, scale, mode);
                    break;
                case 4:
                    fn_8003529C(m, u->p5c, scale, mode);
                    break;
                case 3:
                    fn_80035380(m, u->p5c, scale, mode);
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
        sprintf(buf, lbl_802B0678, name, s->s8c);
        if (fn_801CC62C(buf) == 0 && s->s8c == 0) {
            sprintf(buf, lbl_802B068C, name);
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
                strcpy(s->name, s->p4[s->s8c].f8);
            }
            switch (fn_80046BB0(s->name, &v)) {
            case 0:
            default:
                sprintf(buf, lbl_802B069C);
                break;
            case 1:
                switch (v / 100000) {
                case 99:
                    sprintf(buf, lbl_802B069C);
                    break;
                default:
                    sprintf(buf, "/BEFF/");
                    break;
                }
                break;
            case 2:
            case 3:
                sprintf(buf, "/BEFF/");
                break;
            }
            sprintf(buf2, "%s%s", buf, s->name);
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
                strcpy(s->name, s->p4[s->s8c].f8);
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
                sprintf(buf, lbl_802B069C);
                break;
            case 1:
                switch (v / 100000) {
                case 99:
                    sprintf(buf, lbl_802B069C);
                    break;
                default:
                    sprintf(buf, "/BEFF/");
                    break;
                }
                break;
            case 2:
            case 3:
                sprintf(buf, "/BEFF/");
                break;
            }
            sprintf(buf2, "%s%s", buf, s->name);
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
    ChrTask *t = fn_8001E05C(s->p4);
    ChrInfo *u = t->work->u;
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
            fn_80071CF0(&t->work->v1c, &s->vc);
            fn_800614FC(t->work->rot, s->v18);
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
                fn_80071CF0(&s->vc, &s->p4->work->v1c);
                fn_800614FC(s->v18, s->p4->work->rot);
                u->ff0 &= ~0x40000000;
            }
            u->f1fc = 0;
            o->state = 0xfa;
        }
        if (lbl_80347394 != 0 && (lbl_80347394->work->f3c & 0x40) && s->f8 != 0) {
            V3 a;
            V3 b = lbl_802AD3B8;
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
        strcpy(buf, "/");
        strcat(buf, a);
        strcat(buf, b);
    } else {
        sprintf(buf, "%s%s", a, b);
    }
    i = 0;
    if (iscr_6EB88((s8 *)b)) {
        void *found;
        sprintf(buf2, "%s.MLD", b);
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

void fn_80061FCC(Task *o) {
    S_80061FCC *s;
    U5C188 *u;
    if (lbl_80346BD8 == 0) {
        o->state = 0xfa;
    } else {
        s = o->work;
        u = fn_80021658(lbl_80346BD8->x92)->work->u;
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
            lbl_80346BD8->f6c = lbl_80346BD8->f6c - s->f8;
            if (lbl_80346BD8->f6c <= -1.0f) {
                lbl_80346BD8->f6c = -1.0f;
            }
        } else {
            lbl_80346BD8->f6c = lbl_80346BD8->f6c + s->f8;
            if (lbl_80346BD8->f6c >= 0.0f) {
                lbl_80346BD8->f6c = 0.0f;
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
    strcpy(recs[i].f8, name);
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
    sprintf(buf, lbl_802B06A8, c);
    AddName(buf);
    if (SetOnce()) {
        t = fn_802268E8(lbl_803475A8, fn_8006C124);
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
        t = fn_802268E8(lbl_803475A8, fn_8006C124);
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
        strcpy((char*)n->name, name);
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
    strcpy((char*)m->name, name);
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


typedef struct Src80067CA4 {
    u8 pad0[4];
    Base80067CA4 *base;
} Src80067CA4;

typedef struct Arg80067CA4 {
    s16 x0;
    s16 x2;
    Src80067CA4 *src;
    u8 pad8[4];
    Ent80067CA4 *list;
} Arg80067CA4;

extern void *lbl_802DF2B8[18];
extern Task *lbl_80309E24[14];

extern s16 fn_80020060(Ent80067CA4 *);

void fn_80067CA4(Arg80067CA4 *arg) {
    Ent80067CA4 *list = arg->list;
    Task *task;
    U80067CA4 *u;
    W80067CA4 *w;
    Src80067CA4 *src = arg->src;
    s16 idx;
    idx = fn_80020060(list);
    while (idx < 0) {
    }
    task = fn_802268E8(lbl_803475A8, lbl_802DF2B8[list[idx].type]);
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

extern s16 fn_80060F6C(s16, void*, int);

void fn_80072190(Task* t) {
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

void fn_8005C480(Task *o) {
    S_8005C480 *s;
    Un_8005C480 *u;
    s8 i;
    s8 found;
    s32 ok;
    found = -1;
    ok = 0;
    s = o->work;
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

void fn_8005D614(Task *o) {
    S_8005D614 *s = o->work;
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

/* Finds the target-th node (pre-order) of a model tree. */
MdlNode* fn_8006C9AC(MdlNode* root, u16 target)
{
    u16 count = 0;
    MdlNode* found = NULL;

    fn_8006C9E4(root, target, &count, &found);
    return found;
}

inline void fn_8006C9E4(MdlNode* n, u16 target, u16* count, MdlNode** out)
{
    if (target == *count) {
        if (*out == NULL) {
            *out = n;
        }
        return;
    }
    (*count)++;
    if (n->child != NULL) {
        fn_8006C9E4(n->child, target, count, out);
    }
    if (n->sibling != NULL) {
        fn_8006C9E4(n->sibling, target, count, out);
    }
}

s32 fn_8006CEEC(Ctx_8006CEEC *c, Motion **out, u32 idx, s32 slot)
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
        fn_801D6CBC(lbl_8030A10C.f168, &lbl_8030A10C.b16c);
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
        sprintf(buf, lbl_802B069C);
        break;
    case 1:
        switch (v / 100000) {
        case 99:
            sprintf(buf, lbl_802B069C);
            break;
        default:
            sprintf(buf, "/BEFF/");
            break;
        }
        break;
    case 2:
    case 3:
        sprintf(buf, "/BEFF/");
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

void fn_8005CBA4(Task *o) {
    S_8005CBA4 *s = o->work;
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

void fn_8005A694(Task *o)
{
    S_8005A694 *s = o->work;
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

void fn_8005BAA0(Task *o)
{
    S_8005BAA0 *s = o->work;
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

void fn_8005CCB0(Task* t) {
    St* s = t->work;
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
                sum += lbl_8030B4D4.chr[lbl_80309DCC[i]].x6;
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
        s->f4 = (lbl_80346BD8->x18 - lbl_80346BD8->x20) / (f32)s->s8;
    case 1:
        lbl_80346BD8->x20 = lbl_80346BD8->x20 + s->f4;
        if (lbl_80346BD8->x20 >= lbl_80346BD8->x18) {
            lbl_80346BD8->x20 = lbl_80346BD8->x18;
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

void fn_80062318(Task* o)
{
    S_80062318* s = o->work;
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

extern int strncmp(const char *a, const char *b, u32 n);
extern void fn_80075040(char *p, s32 a, s32 b);
typedef struct Cursor { char *cur; } Cursor;
typedef struct Link { u8 pad0[4]; Cursor *c; } Link;
typedef struct Item { u8 pad0[0x14]; Link *link; u8 pad18[0x68 - 0x18]; } Item;
typedef struct Items { u32 count; Item *items; } Items;

void fn_8006CF54(Out6EB88 *out) {
    u8 i;
    Item *items;
    Items *list;
    list = out->f8;
    items = list->items;
    for (i = 0; i < list->count; i++) {
        Cursor *c = items[i].link->c;
        if (c != 0) {
            if (strncmp(c->cur, "NJCM", 4) == 0) {
                c->cur += 8;
                fn_80075040(c->cur, 0x80000000, 0);
            } else if (strncmp(c->cur, "NJBM", 4) == 0) {
                c->cur += 8;
            }
        }
    }
}

extern void njSetMatrix(void *m, void *arg);

void fn_80061518(V3 *src, V3 *out, void *m) {
    NJS_POINT3 a;
    NJS_POINT3 b;

    if (m == 0) {
        fn_80071CF0(src, out);
        return;
    }
    a.x = src->x;
    a.y = src->y;
    a.z = src->z;
    njPushMatrixEx();
    fn_80286EE8();
    fn_8028B498();
    njSetMatrix(0, m);
    njCalcPoint(0, &a, &b);
    njPopMatrixEx();
    out->x = b.x;
    out->y = b.y;
    out->z = b.z;
}

/* Moves pos (x/z only) towards the target (x, z) by step; returns 1 when it is there.
   A zero step snaps that axis. */
u8 fn_80061340(f32 *pos, f32 *step, f32 x, f32 z)
{
    f32 t[3];
    f32 zero = 0.0f;
    s32 i;
    s32 k;
    s32 ret = 0;

    if (step[0] == zero) {
        pos[0] = x;
    }
    if (step[2] == zero) {
        pos[2] = z;
    }
    if (pos[0] == x && pos[2] == z) {
        return 1;
    }
    t[0] = x;
    t[1] = zero;
    t[2] = z;
    i = 3;
    for (k = 0; k < 3; k++) {
        i--;
        if (i == 1) {
            continue;
        }
        pos[i] += step[i];
        if (step[i] > zero) {
            if (pos[i] >= t[i]) {
                pos[i] = t[i];
            }
        } else {
            if (pos[i] <= t[i]) {
                pos[i] = t[i];
            }
        }
    }
    if (pos[0] == x && pos[2] == z) {
        ret = 1;
    }
    return ret;
}

/* fn_8007201C on b->a with components inside +-0.00001 snapped to 0 (the sibling of
 * fn_80071F84, same arguments). Literals, not the sdata2 labels: the extern loads
 * schedule differently. */
void fn_80071EEC(s32 *out, NJS_POINT3 *a, NJS_POINT3 *b) {
    Vec3f d;
    s8 i;
    f32 *p;
    d.x = a->x - b->x;
    d.y = a->y - b->y;
    d.z = a->z - b->z;
    p = &d.x;
    for (i = 0; i < 3; i++) {
        if (*p < 0.00001f && *p > -0.00001f) {
            *p = 0.0f;
        }
        p++;
    }
    fn_8007201C(out, &d);
}

/* Angle compare: wraps a and b into (-180, 180] when they are more than 180 degrees apart. */
s32 fn_80061080(f32 *a, f32 *b)
{
    f32 av;
    f32 bv;
    f32 d;
    bv = *b;
    av = *a;
    d = bv - av;
    if (d < 0.0f) {
        d *= -1.0f;
    }
    if (d > 180.0f) {
        if (av > 180.0f) {
            *a = -(360.0f - av);
        }
        if (*b > 180.0f) {
            *b = -(360.0f - *b);
        }
        if (*b > *a) {
            return 1;
        }
        return 0;
    }
    return bv < av;
}

void fn_80072E8C(s16 k, s16 b, s16 c, char *d) {
    switch (k) {
    case 0x18:
    case 0x19:
    case 0x1d:
    case 0x1e:
        sprintf(d, lbl_802B0708, b, k);
        break;
    default:
        sprintf(d, lbl_802B0708, c, k);
        break;
    }
}

s16 fn_8006801C(O_8006801C *o, s32 n) {
    char a[0x20];
    char b[0x20];
    char c[0x20];
    s32 v;
    fn_80068190(a);
    strcpy(b, a);
    strcpy(c, a);
    fn_80061048(b);
    fn_80046BB0(a, &v);
    fn_80009500(lbl_80347398, v, v);
    o->tab->v[n] = v;
    n++;
    sprintf(a, "%s.STD", b);
    fn_8006E75C(lbl_80347398, a, v);
    o->tab->v[n] = v;
    n++;
    sprintf(a, "%s0.STD", b);
    fn_8006E75C(lbl_80347398, a, v);
    o->tab->v[n] = v;
    n++;
    return n;
}

s32 fn_8006D02C(Ctr_8006D02C *p, s32 free)
{
    s16 n;

    if (p->x4 == 0) {
        return 0;
    }
    p->x4--;
    n = p->x4;
    if (n == 0) {
        fn_8006D080(p, free);
        return 0;
    }
    return n;
}

void fn_8005B094(O5B094 *o) {
    S5B094 *s = o->s;
    U5B094 *u = s->p50->work->u;
    switch (o->state) {
    case 0:
        if (s->cnt >= s->p54->s14) {
            if (s->p54->s18 != 0) {
                s32 q = s->p54->u1c / s->p54->s18;
                if ((u16)(s->v + (u16)q) >= s->p54->u1c) {
                    s->v = s->p54->u1c;
                    o->state = 1;
                } else {
                    s->v = s->v + (u8)q;
                }
                if (s->v >= s->p54->u1c) {
                    o->state = 1;
                }
            } else {
                o->state = 1;
                s->v = s->p54->u1c;
            }
        }
        if (s->v > 0xfe) {
            s->v = 0xfe;
        }
        fn_80032AD8(s->p50->work->x0, s->v | 0xffffff00, -1, 0);
        s->p50->work->f44 = 4;
        break;
    case 1:
        if (fn_80014C90(u->id, 0x10) == 0) {
            fn_80032AD8(s->p50->work->x0, -0x100, -1, 0);
            s->p50->work->f44 = 0;
            o->state = 3;
        }
        break;
    case 2:
        if (s->v > 10) {
            s->v = s->v - 10;
        } else {
            s->v = 0;
        }
        if (s->v == 0) {
            s->v = 0;
            s->p50->work->f44 = 0;
            o->state = 3;
        }
        fn_80032AD8(s->p50->work->x0, s->v | 0xffffff00, -1, 0);
        break;
    case 3:
        o->flags |= 0x40;
        lbl_8030A10C.count--;
        return;
    }
    s->cnt = s->cnt + 1;
}

static inline void mkseg_60B98(Seg60B98 *s, V60B98 *p, V60B98 *q) {
    s->a.x = p->x;
    s->a.z = p->z;
    s->b.x = q->x;
    s->b.z = q->z;
    if (s->a.x > s->b.x) {
        P60B98 t = s->a;
        s->a = s->b;
        s->b = t;
    }
    s->m = (s->a.z - s->b.z) / (s->a.x - s->b.x);
    s->c = s->a.z - s->m * s->a.x;
}

static inline f32 segy_60B98(Seg60B98 *s, s32 i, f32 x) {
    return x * s[i].m + s[i].c;
}

s32 fn_80060B98(V60B98 *p0, V60B98 *p1, V60B98 *p2, V60B98 *pt) {
    Seg60B98 seg[3];
    s8 a = -1;
    s8 b = -1;
    s8 i;
    mkseg_60B98(&seg[0], p0, p1);
    mkseg_60B98(&seg[1], p1, p2);
    mkseg_60B98(&seg[2], p2, p0);
    for (i = 0; i < 3; i++) {
        if (pt->x >= seg[i].a.x && pt->x < seg[i].b.x) {
            if (a < 0) {
                a = i;
            } else {
                b = i;
                break;
            }
        }
    }
    if (b < 0) {
        return 0;
    } else {
        f32 y1 = segy_60B98(seg, a, pt->x);
        f32 y2 = segy_60B98(seg, b, pt->x);
        if (y1 < y2) {
            if (pt->z >= y1 && pt->z < y2) {
                return 1;
            }
        } else {
            if (pt->z < y1 && pt->z >= y2) {
                return 1;
            }
        }
        return 0;
    }
}

s32 fn_8006BDB4(s16 type, Node_8006BDB4** out, Sub* src) {
    s32 t = type;
    u8 idx;
    Node_8006BDB4* n;
    switch (t) {
    case 0: idx = 0; break;
    case 1: idx = 1; break;
    case 2: idx = 2; break;
    case 3: idx = 3; break;
    default: return 0;
    }
    *out = fn_802268E8(lbl_803475A8, lbl_802DF6C8[idx]);
    n = *out;
    n->work = fn_801E1C7C(0x90);
    memset(n->work, 0, 0x90);
    if (src != 0) {
        n->work->sub = *src;
        n->x19 = 1;
    }
    switch (t) {
    case 0:
    case 1:
        fn_80061F58(&n->work->x8c, 3, 0);
        break;
    default:
        n->work->x8c = 0;
        break;
    }
    return 1;
}

void fn_8006228C(O800624FC *self)
{
    switch (self->state) {
    case 0:
        self->state = 1;
    case 1:
        lbl_80346BD8->ang[1] = lbl_80346BD8->ang[1] - 10.0f;
        if (lbl_80346BD8->ang[1] <= 0.0f) {
            lbl_80346BD8->ang[1] = 0.0f;
            self->state = 3;
        }
        break;
    case 2:
        self->state = 3;
        break;
    case 3:
        self->flags |= 0x40;
        break;
    }
}

void fn_80067DFC(Arg80067CA4 *p)
{
    s16 lo = p->x0;
    s16 hi = p->x2;

    if (lo < 0) {
        return;
    }
    switch ((hi << 16) | lo) {
    case 0:
        fn_8007E13C(p);
        break;
    case 1:
        fn_8007E118(p);
        break;
    case 2:
        fn_8007DFC0(p);
        break;
    case 3:
        fn_8007DEE0(p);
        break;
    case 4:
        break;
    case 0x10000:
        fn_80067CA4(p);
        break;
    }
}

/* Character idx's xb6 as a 0-based number (xb6 - 0x16); out of 10..25 it reports the bad
 * number ("...%d") through fn_8008F75C and returns 10. */
s32 fn_80068348(s16 idx)
{
    char buf[0x100];
    char *base = lbl_802B04C8;
    s32 r;

    r = lbl_80309DE4[idx]->xb6 - 0x16;
    if ((s16)r < 10 || (s16)r > 25) {
        r = 10;
        sprintf(buf, base + 0x160, lbl_80309DE4[idx]->xb6);
        fn_8008F75C(base + 0x174, buf, base + 0x188, lbl_803489B0);
    }
    return r;
}

s32 fn_80068640(s16 a, s16 b) {
    ChrRec *ca = lbl_80309DE4[a];
    ChrRec *cb = lbl_80309DE4[b];
    u32 bits;
    s32 f8;
    lbl_80309730[b].x8 = 1;
    if (ca->bits & 0x200) {
        lbl_80309730[b].x8 = 0;
        lbl_80309730[a].x8 = 0;
        return 0;
    }
    if (a <= 3) {
        T30 *t = &lbl_802C4BF0[lbl_80309174[a].x6];
        if (t->x19 > lbl_80347390->x8) {
            lbl_80309730[b].x8 = 6;
            lbl_80309730[a].x8 = 6;
            return 0;
        }
    }
    bits = cb->bits;
    f8 = bits & 8;
    if (f8) {
        lbl_80309730[b].x8 = 4;
        return 0;
    }
    if (a <= 3) {
        if (b <= 3) return 1;
    } else {
        if (b >= 4) return 1;
    }
    if (bits & 0x10) {
        lbl_80309730[b].x8 = 2;
        return 0;
    }
    if (f8) {
        lbl_80309730[b].x8 = 3;
    }
    return 1;
}

void fn_80069E4C(s16 a, s16 slot, int mode, s8 val) {
    s16 v;
    int i;
    if (lbl_80309DE4[slot]->bits & 0x46190) {
        lbl_80309700[slot]->work->x44 = -1;
        lbl_80309700[slot]->work->x3c = -1;
        return;
    }
    switch (mode) {
    case 1:
        if (a < 4) {
            const T30* t = lbl_802C4BF0 + lbl_80309174[a].x6;
            v = t->v;
        } else {
            const T24* t = lbl_802AD440 + lbl_80309174[a].x6;
            v = t->v;
        }
        break;
    case 4:
        i = lbl_80309174[a].x6 - 0xF0;
        {const T24b* t = lbl_802C7C34 + i; v = t->v;}
        break;
    case 5:
        {const T24* t = lbl_802AD440 + (s16)(lbl_80309174[a].x6 + 0x24); v = t->v;}
        break;
    case 2:
    case 6:
    default:
        break;
    }
    lbl_80309700[slot]->work->x3c = v;
    lbl_80309700[slot]->work->x44 = val;
    lbl_80309174[slot].x8 = 1;
    lbl_80309730[slot].x8 = 1;
}

void fn_8006F424(void)
{
    fn_80217380(1);
    lbl_80347364 = 0xffff;
    lbl_8034737C = 6;
    switch (lbl_80347390->x4) {
    case 2:
        lbl_8034736A = 3;
        break;
    case 1:
        lbl_8034736A = 1;
        lbl_8034737C = 9;
        lbl_80346A90 = 0;
        break;
    case 0:
    default:
        lbl_8034736A = 2;
        break;
    }
}

void fn_80065F1C(T5C188 *o) {
    U5C188 *c = o->work->u;
    switch (c->state) {
    case 0:
        c->state = 1;
        break;
    case 1:
        c->state = 2;
        break;
    case 2:
        fn_80075F2C(o);
        fn_80008308(o, o->work->x10->x30);
        c->state = 3;
        break;
    case 3:
        if ((c->xec & 0x40000) == 0) {
            c->state = 4;
        }
        break;
    case 4:
        c->x134 = 1;
        c->state = 7;
        break;
    case 9:
        if (c->x1f8 == 0) {
            c->xec |= 0x400000;
        } else {
            c->x1f8--;
        }
        return;
    }
    if (c->x138 != 0) {
        c->x138--;
    }
    fn_80065AB0(o, c->xe4);
}

void fn_80064C00(Task *o)
{
    Src_80064C00 *s = o->work;

    switch (o->state) {
    case 0:
        lbl_80346BD8->v8[0] = s->x14;
        lbl_80346BD8->x14 = s->x14;
        lbl_80346BD8->v8[1] = s->x18;
        lbl_80346BD8->x18 = s->x18;
        lbl_80346BD8->v8[2] = s->x1c;
        lbl_80346BD8->x1c = s->x1c;
        lbl_80346BD8->v8[1] = 0.0f;
        lbl_80346BD8->x20 = s->x18;
        o->state = 2;
    case 2:
        o->flags |= 0x40;
        break;
    case 1:
        break;
    }
}

/* fn_800631B0: a battle action that moves its actor (work->p0) to a target and back: the move, an
 * attack by kind (work->kind), the return and the fade. */

typedef struct {
    CamObj* p0;          /* 0x00 */
    f32 v4[3];           /* 0x04 start */
    f32 v10[3];          /* 0x10 target */
    f32 v1c[3];          /* 0x1C */
    u8 pad28[0xc];
    f32 v34[3];          /* 0x34 step */
    f32 v40[3];          /* 0x40 */
    f32 v4c[3];          /* 0x4C */
    f32 v58[3];          /* 0x58 */
    f32 v64[3];          /* 0x64 */
    f32 f70;             /* 0x70 */
    f32 f74;             /* 0x74 */
    f32 f78;             /* 0x78 */
    f32 f7c;             /* 0x7C */
    s16 h80;             /* 0x80 */
    s16 h82;             /* 0x82 frames */
    s16 kind;            /* 0x84 */
    s16 h86;             /* 0x86 counter */
    void* mtx;           /* 0x88 */
    s32 rx, ry, rz;      /* 0x8C */
    s16 h98;             /* 0x98 */
    s16 h9a;             /* 0x9A */
    s16 h9c;             /* 0x9C */
    s16 h9e;             /* 0x9E */
    s32 a0;              /* 0xA0 */
} CamWork;


extern f32 fn_80071E9C(NJS_POINT3 *, NJS_POINT3 *);
extern void fn_80061450(NJS_POINT3 *, NJS_POINT3 *, NJS_POINT3 *);
extern s32 fn_80012F24(s32 idx);
extern void fn_8001F814(u8 id, s8 b);
extern void fn_8001D200(CamObj* o, f32* out);
extern f32 fn_800177C0(s32 id, f32* out);
extern void fn_80048DF0(void* mtx, f32* pos, s32* rot, s32 a);

#define CAM_ABS_SMALL(v) ((f32)fabs(v) <= 0.01f)

void fn_800631B0(Task* t)
{
    CamBody* b3;
    CamWork* w;
    CamObj* actor;
    CamObj* o3;
    CamObj* tgt;
    CamChr* chr;
    CamChr* c3;
    CamChr* tchr;
    CamBody* body;
    s32 i;
    NJS_POINT3 a;
    NJS_POINT3 b;
    s32 rot[3];

    w = t->work;
    actor = w->p0;
    chr = w->p0->body->chr;
    body = actor->body;
    tgt = (CamObj*)fn_80021658((s8)lbl_80346BD8->x90);
    tchr = tgt->body->chr;
    o3 = (CamObj*)fn_8001E05C((ChrTask*)tgt);
    b3 = o3->body;
    c3 = b3->chr;

    lbl_80346BD8->f7c &= ~0x02000000;
    switch (t->state) {
    case 0:
        lbl_80346BD8->f7c |= 0x02000000;
        t->state = 1;
        lbl_80346BD8->w4 = 1;
        lbl_80346BD8->h86 = w->h82;
        w->h86 = 0;
        tchr->fec |= 0x80000;
        tchr->fec |= 0x40000;
        w->h98 = tchr->h6;
        w->h9a = tchr->h8;
        lbl_80346BD8->x88 = 0;
        chr->ff0 |= 0x80000000;
        if (lbl_80346BD8->f7c & 0x80000000) {
            w->a0 = 1;
        } else {
            w->a0 = 0;
        }
        lbl_80347378 |= 1 << lbl_80346BD8->x90;
        if (w->kind == 1) {
            if (fn_80012F24(chr->b4) == 1) {
                fn_8001F814(chr->b4, tchr->b0);
            }
            break;
        }
    case 1:
        lbl_80346BD8->f7c |= 0x02000000;
        switch (w->kind) {
        case 0:
        case 3:
        case 5:
        case 6:
            t->state = 3;
            break;
        default:
            t->state = 2;
            break;
        }
        lbl_80346BD8->h82 = 0;
        fn_80071CF0((V3*)body->pos, (V3*)w->v4);
        rot[0] = (s32)(182.04445f * lbl_80346BD8->ang[0]) + body->rot[0];
        rot[1] = (s32)(182.04445f * lbl_80346BD8->ang[1]) + body->rot[1];
        rot[2] = (s32)(182.04445f * lbl_80346BD8->ang[2]) + body->rot[2];
        fn_800615B4((NJS_POINT3*)lbl_80346BD8->v8, (NJS_POINT3*)w->v58, rot);
        switch (w->kind) {
        default:
            if (w->kind != 6) {
                fn_8001D200(o3, w->v10);
                w->v10[0] -= w->v58[0];
                w->v10[2] -= w->v58[2];
                if (w->kind != 3) {
                    w->v10[1] -= lbl_80346BD8->x20 - lbl_80346BD8->v8[1];
                } else {
                    w->v10[1] -= (lbl_80346BD8->x20 - lbl_80346BD8->v8[1]) - w->f78;
                }
            } else {
                fn_800177C0(chr->b4, w->v10);
                w->v10[0] -= w->v58[0];
                w->v10[1] -= (lbl_80346BD8->x20 + lbl_80346BD8->v8[1]) - w->f78;
                w->v10[2] -= w->v58[2];
            }
            for (i = 0; i < 3; i++) {
                w->v1c[i] = w->v10[i] - w->v4[i];
                if (0.0f == w->v1c[i]) {
                    w->v34[i] = 0.0f;
                } else {
                    w->v34[i] = w->v1c[i] / (f32)w->h82;
                }
                if (CAM_ABS_SMALL(w->v34[i])) {
                    w->v34[i] = 0.0f;
                }
            }
            fn_80061450((NJS_POINT3*)w->v4, (NJS_POINT3*)w->v10, (NJS_POINT3*)w->v4c);
            break;
        case 4:
            fn_800177C0(chr->b4, w->v10);
            w->v10[0] -= w->v58[0];
            w->v10[1] -= (lbl_80346BD8->x20 + lbl_80346BD8->v8[1]) - w->f78;
            w->v10[2] -= w->v58[2];
            a.x = 10.0f;
            a.y = 0.0f;
            a.z = 0.0f;
            fn_800615B4(&a, (NJS_POINT3*)w->v1c, body->rot);
            w->v34[0] = w->v1c[0] / 10.0f;
            if (CAM_ABS_SMALL(w->v34[0])) {
                w->v34[0] = 0.0f;
            }
            w->v34[1] = 0.0f;
            w->v34[2] = w->v1c[2] / 10.0f;
            if (CAM_ABS_SMALL(w->v34[2])) {
                w->v34[2] = 0.0f;
            }
            w->v1c[0] += w->v10[0];
            w->v1c[1] += w->v10[1];
            w->v1c[2] += w->v10[2];
            fn_80061450((NJS_POINT3*)w->v10, (NJS_POINT3*)w->v1c, (NJS_POINT3*)w->v4c);
            break;
        case 5:
            if (w->a0 == 1) {
                w->mtx = fn_801E1C7C(0x40);
                fn_80048DF0(w->mtx, b3->pos, b3->rot, 0);
                c3->ff0 |= 0x40000000;
                c3->p1fc = w->mtx;
            }
            fn_80071CF0((V3*)b3->pos, (V3*)w->v10);
            w->v10[0] -= w->v58[0];
            w->v10[2] -= w->v58[2];
            for (i = 0; i < 3; i++) {
                w->v1c[i] = w->v10[i] - w->v4[i];
                w->v34[i] = w->v1c[i] / 37.0f;
                if (CAM_ABS_SMALL(w->v34[i])) {
                    w->v34[i] = 0.0f;
                }
                w->v64[i] = b3->scale[i];
            }
            fn_80061450((NJS_POINT3*)w->v4, (NJS_POINT3*)w->v10, (NJS_POINT3*)w->v4c);
            w->f7c = c3->f208;
            break;
        }
        a.x = w->v4c[0];
        a.y = 0.0f;
        a.z = w->v4c[2];
        b.x = w->v10[0];
        b.y = 0.0f;
        b.z = w->v10[2];
        w->f70 = fn_80071E9C(&a, &b);
        w->h86 = 0;
        w->h9c = 0;
        if (w->kind == 3 || w->kind == 6) {
            fn_80075FF0(actor, 0x1d, 0);
            w->h98 = chr->h6;
            w->h9a = chr->h8;
        } else if (w->kind == 2) {
            lbl_80346BD8->x88 = 1;
            lbl_80346BD8->x8a = 0;
            lbl_80346BD8->x8c = (f32)chr->p5c->w4 - 1.0f;
        }
        break;
    case 2:
        lbl_80346BD8->f7c |= 0x02000000;
        w->h86++;
        switch (w->kind) {
        case 2:
            lbl_80346BD8->v8[1] += w->f78 / (f32)w->h80;
            break;
        }
        if (w->h86 >= w->h80) {
            t->state = 3;
            w->h86 = 0;
        }
        break;
    case 3:
        lbl_80346BD8->f7c |= 0x02000000;
        switch (w->kind) {
        case 1:
            lbl_80346BD8->f50 += 30.0f;
        case 0:
            w->h86++;
            for (i = 0; i < 3; i++) {
                body->pos[i] += w->v34[i];
                if ((s32)w->v10[i] != (s32)w->v4[i] && !CAM_ABS_SMALL(w->v34[i])) {
                    if (w->v10[i] >= w->v4[i]) {
                        if (body->pos[i] > w->v10[i] && w->a0 == 1) {
                            body->pos[i] = w->v10[i];
                        }
                    } else {
                        if (body->pos[i] < w->v10[i] && w->a0 == 1) {
                            body->pos[i] = w->v10[i];
                        }
                    }
                }
            }
            if (w->h86 < w->h82) {
                break;
            }
            if (w->a0 == 1) {
                t->state = 4;
                w->h86 = 0;
                fn_80071CF0((V3*)body->pos, (V3*)w->v40);
                fn_80020B8C(tgt, w->h98, w->h9a, 0);
            } else {
                if (w->h86 == w->h82) {
                    fn_80020B8C(tgt, w->h98, w->h9a, 0);
                }
                lbl_80346BD8->f6c -= 0.2f;
                if (lbl_80346BD8->f6c <= -1.0f) {
                    lbl_80346BD8->f6c = -1.0f;
                    t->state = 5;
                    w->h86 = 0;
                    fn_80071CF0((V3*)w->v4, (V3*)body->pos);
                    lbl_80346BD8->f50 = 0.0f;
                    if (lbl_80346BD8->x8e == -1) {
                        fn_80075FF0(actor, 2, -1);
                    } else {
                        fn_80075FF0(actor, 0x1d, lbl_80346BD8->x8e);
                    }
                    lbl_80346BD8->h82 = -1;
                }
            }
            fn_8001D14C(tchr);
            break;
        case 2:
        case 7:
            w->h86++;
            if (w->h86 > 20 && w->h86 < w->h9e) {
                lbl_80346BD8->v8[1] -= (10.0f + w->f78) / (f32)(w->h9e - 20);
            } else if (w->h86 == w->h9e) {
                fn_80020B8C(tgt, w->h98, w->h9a, 0);
            }
            if (w->h86 > w->h82) {
                fn_8001D14C(tchr);
                t->state = 4;
                w->h86 = 0;
                lbl_80346BD8->h82 = -1;
            }
            break;
        case 3:
        case 6:
            switch (w->h9c) {
            case 0:
                w->h86++;
                if (w->h86 > 7) {
                    lbl_80346BD8->f6c -= 0.125f;
                }
                if (w->h86 > 15) {
                    w->h9c++;
                    w->h86 = 0;
                    lbl_80346BD8->f6c = -1.0f;
                    body->pos[0] = w->v10[0] - w->v58[0] * w->f74;
                    body->pos[1] = w->v10[1];
                    body->pos[2] = w->v10[2] - w->v58[2] * w->f74;
                    fn_80075FF0(actor, w->h98, w->h9a);
                    lbl_80346BD8->x88 = 4;
                }
                break;
            case 1:
                lbl_80346BD8->f6c += 1.0f / (f32)w->h80;
                if (lbl_80346BD8->f6c >= 0.0f) {
                    w->h9c++;
                    lbl_80346BD8->f6c = 0.0f;
                    if (w->kind != 6 || w->a0 != 0) {
                        lbl_80346BD8->x88 = 0;
                    } else {
                        lbl_80346BD8->x88 = 1;
                        lbl_80346BD8->x8a = 0;
                        lbl_80346BD8->x8c = 27;
                    }
                }
                break;
            default:
                w->h86++;
                if (w->h86 == w->h9e) {
                    fn_80020B8C(tgt, w->h98, w->h9a, 0);
                }
                if (w->h86 > w->h82) {
                    fn_8001D14C(tchr);
                    t->state = 4;
                }
                break;
            }
            break;
        case 4:
            switch (w->h86) {
            case 0:
                lbl_80346BD8->f6c -= 1.0f / (f32)w->h80;
                if (lbl_80346BD8->f6c <= -1.0f) {
                    w->h86++;
                    chr->f164 = -1.0f;
                    lbl_80346BD8->f6c = -1.0f;
                    body->pos[0] = w->v10[0];
                    body->pos[1] = 32.0f + w->v10[1];
                    body->pos[2] = w->v10[2];
                }
                break;
            case 1:
                lbl_80346BD8->f6c = 0.0f;
            default:
                body->pos[1] = (32.0f + w->v10[1]) - 0.5f * (f32)(w->h86 * w->h86);
                w->h86++;
                if (w->a0 == 1) {
                    if (body->pos[1] <= w->v10[1]) {
                        body->pos[1] = w->v10[1];
                        w->h86 = 0;
                        fn_80071CF0((V3*)body->pos, (V3*)w->v40);
                        t->state = 4;
                        fn_80020B8C(tgt, w->h98, w->h9a, 0);
                        fn_8001D14C(tchr);
                    }
                } else {
                    if (w->h86 == 8) {
                        fn_80020B8C(tgt, w->h98, w->h9a, 0);
                        fn_8001D14C(tchr);
                    }
                    if (body->pos[1] <= w->f78 - lbl_80346BD8->x20) {
                        body->pos[1] = w->f78 - lbl_80346BD8->x20;
                        w->h86 = 0;
                        t->state = 4;
                    }
                }
                break;
            }
            break;
        case 5:
            if (w->h86 <= 0x11) {
                body->pos[1] += 0.5f;
                body->scale[0] += 0.2f;
                body->scale[1] += 0.2f;
                body->scale[2] += 0.2f;
            } else if (w->h86 <= 0x36) {
                if (w->h86 == 0x12) {
                    o3->body->rot[1] = fn_80071C74((Pt*)o3->body, actor->body->pos[0], actor->body->pos[2]);
                }
                if (w->a0 == 1) {
                    fn_80048DF0(w->mtx, b3->pos, b3->rot, 0);
                    w->v40[0] = 0.0f;
                    w->v40[1] = 26.0f;
                    w->v40[2] = 0.0f;
                    njTranslate(w->mtx, w->v40[0], w->v40[1], w->v40[2]);
                    w->v40[0] = 0.0f;
                    w->v40[1] = -26.0f + 26.0f * (((f32)w->h86 - 18.0f) / 36.0f);
                    w->v40[2] = (w->f70 * (f32)(w->h86 - 18)) / 18.0f;
                    w->rx = 0;
                    w->ry = 0;
                    w->rz += (s32)(182.04445f * ((f32)w->h86 - 18.0f));
                    njRotateXYZ(w->mtx, w->rx, w->ry, w->rz);
                    njTranslate(w->mtx, w->v40[0], w->v40[1], w->v40[2]);
                    b3->scale[0] = w->v64[0] - w->v64[0] * (((f32)w->h86 - 18.0f) / 37.0f);
                    b3->scale[1] = w->v64[1] - w->v64[1] * (((f32)w->h86 - 18.0f) / 37.0f);
                    b3->scale[2] = w->v64[2] - w->v64[2] * (((f32)w->h86 - 18.0f) / 37.0f);
                    c3->f208 -= (1.0f + w->f7c) / 10.0f;
                    if (c3->f208 <= -1.0f) {
                        c3->f208 = -1.0f;
                    }
                } else if (w->h86 == 0x13) {
                    fn_80020B8C(tgt, w->h98, w->h9a, 0);
                }
            } else if (w->h86 > 0x51) {
                if (w->h86 <= 0x58) {
                    if (w->a0 == 1) {
                        fn_80048DF0(w->mtx, b3->pos, b3->rot, 0);
                        w->v40[0] = 0.0f;
                        w->v40[1] = 26.0f - 26.0f * (((f32)w->h86 - 82.0f) / 6.0f);
                        w->v40[2] = 2.0f * w->f70 - (w->f70 * (f32)(w->h86 - 82)) / 3.0f;
                        njTranslate(w->mtx, w->v40[0], w->v40[1], w->v40[2]);
                        b3->scale[0] = w->v64[0] * (((f32)w->h86 - 82.0f) / 7.0f);
                        b3->scale[1] = w->v64[1] * (((f32)w->h86 - 82.0f) / 7.0f);
                        b3->scale[2] = w->v64[2] * (((f32)w->h86 - 82.0f) / 7.0f);
                        c3->f208 += (1.0f + w->f7c) / 5.0f;
                        if (c3->f208 >= w->f7c) {
                            c3->f208 = w->f7c;
                        }
                    }
                } else {
                    fn_8001D14C(tchr);
                    t->state = 4;
                    w->h86 = 0;
                    lbl_80346BD8->h82 = -1;
                    c3->ff0 &= ~0x40000000;
                    b3->scale[0] = w->v64[0];
                    b3->scale[1] = w->v64[1];
                    b3->scale[2] = w->v64[2];
                    c3->p1fc = 0;
                    if (w->a0 == 1) {
                        fn_80020B8C(tgt, w->h98, w->h9a, 0);
                    }
                }
            }
            w->h86++;
            break;
        }
        break;
    case 4:
        lbl_80346BD8->f7c |= 0x02000000;
        switch (w->kind) {
        case 0:
            for (i = 0; i < 3; i++) {
                w->v40[i] -= w->v34[i];
                body->pos[i] = w->v40[i];
                if ((s32)w->v4[i] != (s32)w->v10[i] && !CAM_ABS_SMALL(w->v34[i])) {
                    if (w->v4[i] < w->v10[i]) {
                        if (body->pos[i] < w->v4[i]) {
                            body->pos[i] = w->v40[i] = w->v4[i];
                        }
                    } else {
                        if (body->pos[i] > w->v4[i]) {
                            body->pos[i] = w->v40[i] = w->v4[i];
                        }
                    }
                }
            }
            w->h86++;
            a.x = w->v4c[0];
            a.y = 0.0f;
            a.z = w->v4c[2];
            b.x = body->pos[0];
            b.y = 0.0f;
            b.z = body->pos[2];
            body->pos[1] += 0.5f * (w->f70 * njSin((s32)(10430.381f * (f32)acos(fn_80071E9C(&a, &b) / w->f70))));
            if (w->h86 >= w->h82) {
                t->state = 6;
                lbl_80346BD8->h82 = -1;
            }
            break;
        case 1:
            lbl_80346BD8->f50 += 30.0f;
        case 3:
        case 6:
            w->h86++;
            if (w->h86 > w->h80) {
                lbl_80346BD8->f6c -= 1.0f / (f32)w->h82;
                if (lbl_80346BD8->f6c <= -1.0f) {
                    lbl_80346BD8->f6c = -1.0f;
                    body->pos[0] = w->v4[0];
                    body->pos[1] = w->v4[1];
                    body->pos[2] = w->v4[2];
                    t->state = 5;
                    w->h86 = 0;
                    if (lbl_80346BD8->x8e == -1) {
                        fn_80075FF0(actor, 2, -1);
                    } else {
                        fn_80075FF0(actor, 0x1d, lbl_80346BD8->x8e);
                    }
                    lbl_80346BD8->x88 = 0;
                    lbl_80346BD8->h82 = -1;
                    lbl_80346BD8->f50 = 0.0f;
                }
            }
            break;
        case 2:
        case 7:
            w->h86++;
            lbl_80346BD8->v8[1] += 10.0f / (f32)w->h80;
            if (lbl_80346BD8->v8[1] >= 0.0f) {
                lbl_80346BD8->v8[1] = 0.0f;
            }
            if (w->h86 > w->h80) {
                t->state = 6;
                lbl_80346BD8->x88 = 0;
            }
            break;
        case 4:
            if (w->a0 == 1) {
                f32 d;
                w->v40[0] += w->v34[0];
                body->pos[0] = w->v40[0];
                w->v40[1] += w->v34[1];
                body->pos[1] = w->v40[1];
                w->v40[2] += w->v34[2];
                body->pos[2] = w->v40[2];
                lbl_80346BD8->f50 -= 10.0f;
                a.x = w->v4c[0];
                a.y = 0.0f;
                a.z = w->v4c[2];
                b.x = body->pos[0];
                b.y = 0.0f;
                b.z = body->pos[2];
                d = fn_80071E9C(&a, &b);
                body->pos[1] += 5.0f - 0.2f * d * d;
            }
            if (w->h86 > 10) {
                lbl_80346BD8->f6c -= 0.2f;
                if (lbl_80346BD8->f6c <= -1.0f) {
                    lbl_80346BD8->f6c = -1.0f;
                    body->pos[0] = w->v4[0];
                    body->pos[1] = w->v4[1];
                    body->pos[2] = w->v4[2];
                    lbl_80346BD8->f50 = 0.0f;
                    t->state = 5;
                    w->h86 = 0;
                    if (lbl_80346BD8->x8e == -1) {
                        fn_80075FF0(actor, 2, -1);
                    } else {
                        fn_80075FF0(actor, 0x1d, lbl_80346BD8->x8e);
                    }
                    lbl_80346BD8->h82 = -1;
                }
            }
            w->h86++;
            break;
        case 5:
            body->pos[1] -= 0.9f;
            body->scale[0] -= 0.36f;
            body->scale[1] -= 0.36f;
            body->scale[2] -= 0.36f;
            w->h86++;
            if (w->h86 >= 10) {
                c3->p1fc = 0;
                body->pos[0] = w->v4[0];
                body->pos[1] = w->v4[1];
                body->pos[2] = w->v4[2];
                body->scale[0] = 1.0f;
                body->scale[1] = 1.0f;
                body->scale[2] = 1.0f;
                t->state = 6;
                w->h86 = 0;
            }
            break;
        default:
            body->pos[0] = w->v4[0];
            body->pos[1] = w->v4[1];
            body->pos[2] = w->v4[2];
            lbl_80346BD8->h82 = -1;
            break;
        }
        break;
    case 5:
        lbl_80346BD8->f7c |= 0x02000000;
        lbl_80346BD8->f6c += 1.0f / (f32)w->h80;
        if (lbl_80346BD8->f6c >= 0.0f) {
            lbl_80346BD8->f6c = 0.0f;
            t->state = 6;
        }
        break;
    case 6:
        lbl_80346BD8->f7c |= 0x02000000;
        lbl_80346BD8->v[1] -= 9.0f;
        if (lbl_80346BD8->v[1] <= 0.0f) {
            lbl_80346BD8->v[1] = 0.0f;
            t->state = 7;
        }
        break;
    case 7:
        chr->ff0 &= ~0x80000000;
        lbl_80347378 &= ~(1 << lbl_80346BD8->x90);
        if (w->mtx != 0) {
            fn_801E17E0(w->mtx);
            w->mtx = 0;
        }
        lbl_80346BD8->w4 = 0;
        t->flags |= 0x40;
        break;
    }
}

f32 fn_8006116C(int x)
{
    f32 r;
    r = (360.0 * (s32)(u16)x) / 65536.0;
    if (r < 0.0f) {
        r = 360.0f + r;
    }
    return r;
}

void fn_80068E20(s16 a, s16 b) {
    s32 j;
    s16 id;
    s16 v;
    s16 k;
    fn_800692D8();
    if (lbl_80309700[b]->work->x44 != -1) {
        id = a;
        k = lbl_80309174[id].x6 + 0x24;
        {
            T24 *t = &lbl_802AD440[k];
            v = t->v;
        }
        for (j = 4; j <= 11; j++) {
            if (fn_80078610(j) != 0 && v != lbl_80309700[j]->work->x2) {
                lbl_80309DCC[j] = -3;
                lbl_80309DE4[j]->bits |= 0x2000;
                if (id != j) {
                    fn_8008066C(j);
                    lbl_80309700[j]->flags |= 0x40;
                    lbl_80309700[j] = 0;
                    lbl_80347374 &= ~(1 << j);
                    lbl_80309DE4[j]->bits |= 0x100;
                }
            }
        }
    }
}

void fn_80068F68(s16 idx, s16 p2, void *unused, s8 v)
{
    s16 k = lbl_80309174[idx].x6 + 0x24;
    const T24 *t = &lbl_802AD440[k];
    lbl_80309700[idx]->work->x44 = v;
    lbl_80309700[idx]->work->x3c = t->v;
    lbl_80309DE4[p2]->bits |= 0x01000000;
    lbl_80309DE4[p2]->bits |= 0x400;
    lbl_80309DE4[p2]->bits |= 0x00040000;
}

s32 fn_800683D8(s16 a, s16 b, s32 c, s8 d) {
    s32 k;
    lbl_80309700[b]->work->x44 = -1;
    lbl_80309700[b]->work->x46 = -1;
    lbl_80309700[b]->work->x48 = -1;
    lbl_80309700[b]->work->x4a = -1;
    lbl_80309700[b]->work->x3c = -1;
    if (d != 0x1b && d != 0x1c && d != 0x2f && d != 0x27 && fn_80078610(b) == 0) {
        return 0;
    }
    if (lbl_80309DE4[b]->bits & 0x10) {
        lbl_80309730[b].x8 = 4;
        return 0;
    }
    if (c == 1 || c == 2 || c == 3) {
        lbl_80309730[a].x8 = 1;
        k = lbl_80309174[a].x6;
        if (a < 4) {
            T30 *r = &lbl_802C4BF0[k];
            if (r->x18 == 0 && fn_80068640(a, b) == 0) {
                return 0;
            }
        } else {
            T24 *q = &lbl_802AD440[k];
            s32 v = q->x15;
            if (v == 1 && fn_80068640(a, b) == 0) {
                return 0;
            }
        }
    }
    if (c == 5) {
        T24 *q = &lbl_802AD440[lbl_80309174[a].x6 + 0x24];
        s8 v = q->x15;
        if (v == 1 && fn_80068640(a, b) == 0) {
            return 0;
        }
    }
    if (d < 0) {
        return 0;
    }
    if (d >= 0 && d <= 0x4e) {
        lbl_802DF570[d](a, b, c, d);
        return 1;
    }
    return 0;
}

void fn_80057DFC(Task* t)
{
    Work_80057DFC* w = t->work;
    Obj_80057DFC* obj = ((Obj_80057DFC*)fn_8001E05C((void *)(*(void**)((u8*)w + 4))));
    Info* info;
    f32 tmp;
    if (obj == 0) {
        t->state = 0xfa;
        info = 0;
    } else {
        info = obj->p24->x4c;
    }
    switch (t->state) {
    case 0:
        w->v20.x = obj->p24->v.x * w->d->x24;
        w->v20.y = obj->p24->v.y * w->d->x28;
        w->v20.z = obj->p24->v.z * w->d->x2c;
        fn_80071CF0((void *)(&obj->p24->v), (void *)(&w->v8));
        fn_80061014((void *)(&w->v8), (void *)(&w->v20), (void *)(&w->v14));
        w->v14.x = w->v14.x / (f32)w->d->x1a;
        w->v14.y = w->v14.y / (f32)w->d->x1a;
        w->v14.z = w->v14.z / (f32)w->d->x1a;
        w->v30.x = w->d->x30.x;
        w->v30.y = w->d->x30.y;
        w->v30.z = w->d->x30.z;
        w->x3c = 0.0f;
        w->x40 = 0.1f;
        w->x44 = fn_8022DFFC((void *)(&w->v30));
        if (w->x44 > 100) w->x44 = 100;
        t->state = 1;
    case 1:
        if (w->t >= w->d->x18 && w->t < w->d->x18 + w->d->x1a) {
            fn_80071CBC((void *)(&w->v14), (void *)(&obj->p24->v));
            break;
        }
        if (w->t < w->d->x18 + w->d->x1a) break;
        t->state = 2;
    case 2:
        if (w->t != w->d->x1c) break;
        w->x2c = 0;
        t->state = 4;
    case 4:
        if (w->x2c >= w->x44) {
            t->state = 5;
        } else {
            fn_8022E18C((void *)(&w->v30), w->x2c, (void *)(&tmp));
            obj->p24->v.y = w->v8.y + tmp;
        }
        w->x2c++;
        break;
    case 5:
        if (w->d->x1e < w->d->x20) {
            if (w->t > w->d->x20) {
                fn_80071CF0((void *)(&w->v8), (void *)(&obj->p24->v));
                t->state = 0xfa;
            }
        } else {
            fn_80071CF0((void *)(&w->v8), (void *)(&obj->p24->v));
            t->state = 0xfa;
        }
        break;
    case 0xf9:
        fn_80071CF0((void *)(&w->v8), (void *)(&obj->p24->v));
        info->flags &= ~0x20000000;
    case 0xfa:
        t->flags |= 0x40;
        (*(Game*)&lbl_8030A10C).count--;
        return;
    }
    if (w->d->x1e < w->d->x20) {
        if (w->t == w->d->x1e) info->flags |= 0x20000000;
        else if (w->t == w->d->x20) info->flags &= ~0x20000000;
    }
    w->t++;
    fn_80037FD8((void *)(w->d), (void *)(&t->state));
}

void fn_8005D108(W_8005D108* w)
{
    Vec3_8005D108 base = lbl_802AD434;
    Vec3_8005D108 v8;
    Par_8005D108* p = w->owner->work;
    Info_8005D108* info = p->x4c;
    switch (w->state) {
    case 0:
        if (w->t < w->d->x14) break;
        fn_80014AB8(1, (void *)(w));
        w->x80 = fn_80071E5C((void *)(&base), (void *)(&w->d->v1c));
        if (w->d->x10 & 0x40000) {
            w->x84 = fn_80071E5C((void *)(&base), (void *)(&w->d->v34));
            w->x8c = (w->x84 - w->x80) / (f32)w->d->x18;
        }
        if (w->d->x10 & 0x4000) {
            w->x94 = (w->d->v34.y - w->d->v1c.y) / (f32)w->d->x18;
        }
        if (w->d->x10 & 0x20000) {
            w->xac = (w->d->x44 - w->d->v28.y) / (f32)w->d->x18;
            fn_8001D1D8(w->owner, &v8);
            w->v38.x = v8.x;
            w->v38.z = v8.z;
            w->v38.y = w->d->v28.y;
        }
        if (w->d->x4c) w->x90 = w->d->x4c;
        w->x98 = w->d->x74;
        if (w->d->x10 & 0x2000) {
            if (rand() % 2 != 0) w->x98 = -1.0f * w->d->x74;
        }
        w->x88 = w->x80;
        w->state = 1;
    case 1:
        fn_8001D288(&w->x20, info->id, w->x90, w->x88);
        w->x24 = w->d->v1c.y;
        if (w->d->x10 & 0x4000) w->x24 = w->x94 * (f32)(w->t - w->d->x14) + w->x24;
        if ((w->d->x10 & 0x80000) && w->x7c != 0) {
            fn_80061518((void *)(&w->d->v68), (void *)(&w->v38), (void *)(w->x7c));
        } else if (w->d->x10 & 0x20000) {
            if (w->t < w->d->x14 + w->d->x18) w->v38.y = w->v38.y + w->xac;
        } else {
            fn_8001E4A0((void *)(&w->d->v28), (void *)(&w->v38), (void *)(w->owner));
            fn_8001D1D8(w->owner, &v8);
            w->v38.x = v8.x;
            w->v38.z = v8.z;
        }
        fn_80071F84((void *)(&w->v2c), (void *)(&w->v38), (void *)(&w->x20));
        if (w->t < w->d->x14 + w->d->x18 && (w->d->x10 & 0x40000)) w->x88 = w->x88 + w->x8c;
        w->x90 = w->x90 + w->x98;
    }
}

void fn_8005DB1C(Ob_8005DB1C* o) {
    St_8005DB1C* s = o->s;
    switch (o->state) {
    case 0:
        s->f20 = s->tab->f28;
        s->s34 = s->tab->s20;
        s->s36 = s->tab->s22;
        s->s38 = s->tab->s24;
        s->f30 = s->tab->f38;
        o->state = 1;
        if (fn_800553B4() == 0) {
            o->state = 3;
            return;
        }
    case 1:
        if (s->cnt < s->tab->s14) {
            break;
        }
        if (!(lbl_8030A10C.f6c & 0x40000000)) {
            if (fn_800553B4() == 0) {
                o->state = 3;
                return;
            }
            o->state = 2;
            lbl_8030A10C.f6c |= 0x40000000;
        } else {
            o->state = 2;
        }
    case 2:
        s->f24 = s->tab->s30;
        s->f28 = s->tab->s32;
        if (s->tab->s34 != 0) {
            f32 v = njSin((s32)(182.04445f * (s->tab->f2c * s->cnt)));
            s->f24 = s->tab->s34 * v + s->f24;
        }
        if (s->tab->s36 != 0) {
            f32 v = njSin((s32)(182.04445f * (s->tab->f2c * s->cnt)));
            s->f28 = s->tab->s36 * v + s->f28;
        }
        if (s->cnt == s->tab->s1c && s->tab->f38 != s->tab->f40 && s->tab->f3c) {
            s->f30 = s->tab->f40;
        }
        if (s->cnt >= s->tab->s1c && s->cnt < s->tab->s1e) {
            s->f30 = s->f30 + s->tab->f3c;
        }
        if (!(lbl_8030A10C.f6c & 0x40000000)) {
            o->state = 0xfa;
            break;
        }
        if (s->cnt >= s->tab->s16 && s->tab->s16 < 900) {
            o->state = 0xfa;
        }
        fn_8002FEB0(fn_80034690, s->p10, 0);
        break;
    case 0xf9:
    case 0xfa:
        if (s->tab->f10 & 0x8000) {
            lbl_8030A10C.f6c &= ~0x40000000;
            fn_80226DC4();
        }
    case 3:
        o->flags |= 0x40;
        lbl_8030A10C.count--;
        return;
    }
    s->cnt++;
    fn_80037FD8(s->tab, &o->state);
}

void fn_8005DEB8(Task* o)
{
    Work* w = o->work;
    s32 ok = 0;
    void* t;
    s16 i;
    f32 fl;
    Shake s = w->shake;

    switch (o->state) {
    case 0:
        if (lbl_8030A10C.f6c & 0x10000) {
            o->state = 0xFA;
            return;
        }
        fn_80060A54();
        o->state = 1;
    case 1:
        if (w->cmd->flags & 0x8000) {
            t = fn_8001E05C(w->x4);
            if (fn_80075C70(t, 0xB, -1) || fn_80075C70(t, 0x20, -1) || fn_80075C70(t, 0xC, -1)) {
                ok = 1;
            }
        } else if (w->cnt >= w->cmd->s20) {
            ok = 1;
        }
        if (ok) {
            w->f0c = w->cmd->f28;
            w->f18 = w->cmd->f34;
            w->f10 = w->cmd->f2c;
            w->f14 = w->cmd->f30;
            if (!(w->cmd->flags & 0x2000)) {
                w->f1c = w->cmd->f38;
            }
            w->timer = w->cmd->s1a;
            w->cnt = 0;
            if (w->cmd->s1c != 0) {
                switch (w->cmd->s22) {
                case 0:
                case 1:
                case 4:
                case 5:
                    fl = 0.0f;
                    for (i = 0; i < w->cmd->s1c; i++) {
                        fn_8022E068(&w->f0c, i, &w->f24, &w->f28, &w->f2c, &fl);
                    }
                    if (i != 0) {
                        w->cnt = 1;
                    }
                    break;
                }
            }
            o->state = 2;
        } else {
            w->cnt++;
        }
        break;
    case 2:
        if (w->cnt >= w->cmd->s1e - w->cmd->s1c) {
            o->state = 0xFA;
            s.kind = 0;
            s.amp = 0;
            s.b4 = 0;
            fn_8006097C(&s);
        } else {
            switch (w->cmd->s22) {
            case 0:
            case 1:
            case 4:
            case 5:
                fl = s.amp;
                if (!fn_8022E068(&w->f0c, w->cnt, &w->f24, &w->f28, &w->f2c, &fl)) {
                    s.amp = 0;
                    s.kind = 0;
                    s.b4 = 0;
                    o->state = 0xFA;
                } else {
                    s.kind = 0;
                    s.b4 = 0;
                    switch (w->cmd->s22) {
                    case 0:
                    case 4:
                    default:
                        s.amp = fl;
                        if (w->cmd->s22 < 4) {
                            s.kind = 1;
                        }
                        break;
                    case 1:
                    case 5:
                        s.amp = fl;
                        if (s.amp < 0) {
                            s.amp *= -1;
                        }
                        if (w->cmd->s22 < 4) {
                            s.kind = 1;
                        }
                        break;
                    }
                }
                break;
            default:
                s.amp = w->cmd->f30;
                s.b4 = w->cmd->s24;
                switch (w->cmd->s22) {
                case 2:
                case 6:
                    if (w->cmd->s22 < 4) {
                        s.kind = 9;
                    } else {
                        s.kind = 8;
                    }
                    break;
                case 3:
                case 7:
                    if (w->cmd->s22 < 4) {
                        s.kind = 0x81;
                    } else {
                        s.kind = 0x80;
                    }
                    break;
                }
                o->state = 3;
                break;
            }
        }
        s.dur = w->cmd->s18;
        w->shake = s;
        fn_8006097C(&s);
        w->timer--;
        if (w->timer <= 0) {
            w->cnt++;
            w->timer = w->cmd->s1a;
        }
        break;
    case 3:
        if (w->cnt >= w->cmd->s1e - w->cmd->s1c) {
            o->state = 0xFA;
            s.kind = 0;
            s.amp = 0;
            s.b4 = 0;
            fn_8006097C(&s);
        }
        w->timer--;
        if (w->timer <= 0) {
            w->cnt++;
            w->timer = w->cmd->s1a;
        }
        break;
    case 0xF9:
        s.kind = 0;
        s.amp = 0;
        s.b4 = 0;
        fn_8006097C(&s);
    case 0xFA:
        o->flags |= 0x40;
        lbl_8030A10C.count--;
        return;
    default:
        break;
    }
    fn_80037FD8(w->cmd, &o->state);
}

void fn_80072318(Block* src, Block* dst, s16 n)
{
    Rec16* d16;
    Rec24* d24;
    Rec24* s24;
    s32 i;
    Rec16* s16p;
    s32 kind = src->kind & 0xF;

    *dst = *src;
    switch (kind) {
    case 2:
        fn_80061F58(dst, n * 16, 0);
        d16 = dst->data;
        s16p = src->data;
        for (i = 0; i < n; i++) {
            d16[i] = s16p[i];
        }
        break;
    case 3:
        fn_80061F58(dst, n * 24, 0);
        d24 = dst->data;
        s24 = src->data;
        for (i = 0; i < n; i++) {
            d24[i] = s24[i];
        }
        break;
    }
}

void fn_80062444(Task *task) {
    Work62 *w;
    w = task->work;
    if (w->p0->p24->p4c->s6 != w->s4) {
        task->state = 2;
    }
    switch (task->state) {
    case 0:
        task->state = 1;
        fn_80075FF0(w->p0, 0x20, -1);
        lbl_80346BD8->x88 = 1;
        lbl_80346BD8->x8a = 0;
        lbl_80346BD8->x8c = 0xf;
        break;
    case 1:
        break;
    case 2:
    case 3:
        task->flags |= 0x40;
        break;
    }
}

void fn_80069C24(s16 a, s16 i, s32 b, s8 v) {
    lbl_80309700[i]->work->x3c = 0;
    if (lbl_80309DE4[i]->bits & 0x6100 || lbl_80309DE4[i]->bits & 0x1000) {
        lbl_80309700[i]->work->x44 = -1;
    } else {
        lbl_80309700[i]->work->x3c = fn_80010CBC(a) * 2;
        lbl_80309700[i]->work->x44 = v;
    }
}

s32 fn_8006B5B8(void *key) {
    s32 i;
    TblObj *o = 0;
    for (i = 0; i < 4; i++) {
        if (lbl_80309E88[i].f4 == key) {
            o = lbl_80309E88[i].f0;
            break;
        }
    }
    if (o == 0) {
        return 0;
    }
    switch (o->kind) {
    case 4:
        fn_80287274(o->x8 + 1, 0);
        break;
    }
    memset(&lbl_80309E88[i], 0, 0x10);
    return 0;
}

s32 fn_8006DCFC(void *a, s16 b, s16 c)
{
    O6BEFC *obj;
    s32 r;

    if (lbl_8030A10C.f6c & 0x80000000) {
        r = 0;
    } else {
        lbl_8030A10C.f6c |= 0x80000000;
        r = 1;
    }
    if (r == 0) {
        return 0;
    }
    obj = fn_802268E8(lbl_803475A8, fn_8006BEFC);
    fn_80061F58(&obj->s, 0xac, 0);
    obj->s->p94 = a;
    obj->s->s98 = b;
    obj->s->s9a = c;
    return 1;
}

s32 fn_8006EDA0(void)
{
    s8 *p;
    s32 c;
    s32 i;

    i = lbl_80347335;
    p = &lbl_803092F4[i];
    for (;;) {
        i++;
        p++;
        if (i >= 12) {
            return -1;
        }
        c = *p;
        if (c == -1) {
            return -1;
        }
        if (fn_80078610(c) == 0) {
            continue;
        }
        if (lbl_80309DE4[c]->bits & 0x6500) {
            continue;
        }
        if (lbl_80309174[c].x0 == 0xb) {
            continue;
        }
        return c;
    }
}

s32 fn_80072DD4(s16 a, s16 b, s16 c, void *d)
{
    char buf2[0x20];
    char buf1[0x20];

    switch (a) {
    case 0x18:
    case 0x19:
    case 0x1d:
    case 0x1e:
        sprintf(buf2, lbl_802B0708, b, a);
        break;
    default:
        sprintf(buf2, lbl_802B0708, c, a);
        break;
    }
    fn_8006C8DC(buf1, buf2);
    fn_80074E2C(buf1, buf2, d, 0, 1);
    return 1;
}
