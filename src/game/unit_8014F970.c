#include "types.h"
#include "ninja.h"
#include "game/drawstate.h"
#include "game/work_8030CEA0.h"
#include "game/btlside.h"
#include "game/task.h"
#include <math.h>
#include <dolphin/types.h>
#include "game/battle.h"
#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))
typedef struct BtlShip BtlShip;
typedef struct { u8 pad0[4]; s32 f4; u8 pad8[4]; s32 fc; } Ev;
typedef struct { u8 pad0[0x2d8]; s32 f2d8; } Ctx;
typedef struct { s32 f0; u8 pad4; s8 f5; } Ent_UNIT0000;
typedef struct { s32 a, b; s32 c; u32 p; char name[1]; } St_UNIT0000;
typedef struct { u32 idx; u32 a, b, c, d; } Src_UNIT0000;
typedef struct { u32 a, b; void* p; } E12;
typedef struct { s32 flag; u8 pad[0x10]; f32 pos[3]; s32 ints[3]; } Obj_80158200;
typedef struct {
    u8 pad0[0x1a];
    s16 id;                 /* 0x1a */
    u8 pad1c[2];
    s16 mode;               /* 0x1e */
    u8 pad20[2];
    u8 v22;                 /* 0x22 */
    u8 pad23;
} Slot_8015854C;                     /* 0x24 */
typedef struct {
    u32 flags;
    s32 f4;
    u8 pad8[8];
    s16 h10;
    s16 h12;
    s32 f14;
    u8 pad18[0x10];
    s32 f28;
    s32 f2c;
    u8 pad30[4];
    s32 f34;
    u8 pad38[4];
    u16 h3c;
    u16 h3e;
    u16 h40;
    u8 pad_42[0x2];
    s16 h44;
    s16 h46;
    s16 h48;
    u8 pad_4a[0x22];
    s16 h6c;
    s16 h6e;
    u8 pad70[0x9c - 0x70];
    Slot_8015854C slot[8];   /* 0x9C */
    u8 pad1bc[0x1ee - 0x1bc];
    s16 h1ee;
} Obj_8015854C;
typedef struct Inner_UNIT0000 { u8 pad[0x8]; void *x8; } Inner_UNIT0000;
typedef struct Obj_8015C6F0_UNIT0000 { u8 pad[0x1d8]; Inner_UNIT0000 *x1d8; } Obj_8015C6F0_UNIT0000;
typedef struct Sub_UNIT0000 { u8 pad[0x260]; u32 f260; } Sub_UNIT0000;
typedef struct Obj_8015C8B8_UNIT0000 { u8 pad[0x1d8]; Sub_UNIT0000 *x1d8; } Obj_8015C8B8_UNIT0000;
typedef struct { u8 pad0[4]; void* p4; u8 pad8[4]; u32 f0c; } Obj_80153270;
typedef struct { s32 flag; void *a; void *b; void *c; u32 d; } E14;
typedef struct { s32 f0; u8 b4; } E40;
typedef struct { u8 pad[0x1ec]; u8 f1ec; u8 pad2[2]; u8 f1ef; } In_UNIT0000;
typedef struct { u8 pad[0x24]; In_UNIT0000 *p24; } Mid_UNIT0000;
typedef struct { u8 pad0[0x28]; Mid_UNIT0000 *p28; u8 pad1[0x40]; void *p6c; } Obj_80152AFC_UNIT0000;
typedef struct { u8 pad[0x17a]; u16 h17a; } Rec_UNIT0000;
typedef struct { u8 pad[0x24]; Rec_UNIT0000 *p24; } Holder_UNIT0000;
typedef struct { Holder_UNIT0000 *p0; u8 pad[0x10]; } Slot_UNIT0000_UNIT0000;
/* A battle-side's partner state: the ship task it follows, its sound/model keys and their handles. */
typedef struct EvTask {
    u8 pad0[0x19];
    u8 state;               /* 0x19 */
    u8 pad1a[0x24 - 0x1a];
    EvObj *work;            /* 0x24 */
} EvTask;
typedef struct Obj_8015259C {
    s32 idx;                /* 0x00 */
    s32 f04;                /* 0x04 */
    s32 mode;               /* 0x08 */
    f32 pos[3];             /* 0x0c */
    u8 pad18[0xc];
    s32 f24;                /* 0x24 */
    EvTask *partner;        /* 0x28 */
    s32 ready;              /* 0x2c */
    s32 keyB;               /* 0x30 */
    s32 x34;                /* 0x34 */
    s32 keyA;               /* 0x38 */
    s32 x3c;                /* 0x3c */
    u8 pad40[4];
    u32 resA;               /* 0x44 */
    s32 f48;                /* 0x48 */
    s32 keyC;               /* 0x4c */
    s32 x50;                /* 0x50 */
    s32 keyD;               /* 0x54 */
    s32 x58;                /* 0x58 */
    u32 resB;               /* 0x5c */
    u32 resC;               /* 0x60 */
    u32 resD;               /* 0x64 */
    s32 f68;                /* 0x68 */
    void *x6c;              /* 0x6c */
} Obj_8015259C;
typedef struct { u32 f0; s32 f4; s8 f8; u8 pad[0xb]; } Gx;
typedef struct { u32 a, b, c; } Blk;
typedef struct { Blk *p0; } Xh;
typedef struct { u8 pad[0x20]; Xh *p20; } M;
typedef struct { u8 pad[0x1c]; u32 f1c; } Src_8015DBE4;
typedef struct { u8 pad[0x1e]; s16 h1e; u8 pad2[0x78 - 0x20]; Blk b78; } State;
typedef struct { u8 pad[0x1c8]; M *p1c8; u8 pad2[0x1d8 - 0x1cc]; State *p1d8; } Self;
void fn_80153270(void *p);
s32 fn_80155CD8(void);
void fn_80155D74(void);
void *memcpy(void *dst, const void *src, u32 n);
void *memset(void *p, s32 c, u32 n);
extern s8 lbl_803067A8[];
extern s8 lbl_80306938[];
typedef struct {
    s8 v[4];
} Cell;
typedef struct {
    s8 active;
    s8 b1, b2, b3;
    u8 pad4[2];
    Cell cell[8][4][2];
} Tab;
extern Tab *lbl_80346FB8;
extern E14 *lbl_80346FE8;
extern void *lbl_80346FAC;
extern s32 lbl_8034704C;
extern Ent_UNIT0000 *lbl_802E6ACC[];
extern E40 *lbl_802E6A40[];
extern s32 *lbl_802E6AB0[];
extern char lbl_802B3B9C[];
extern char lbl_802B3B80[];
extern char lbl_802B3BB8[];
extern char lbl_802B3F38[];
extern char lbl_802B4104[];
extern const char lbl_802B3F24[];
extern s32 lbl_80347024;
extern u32 lbl_80347008;
extern void *lbl_8034702C;
extern u8 lbl_80306C98[];
extern E12 lbl_80306B14[];
extern E12 lbl_80308F98[];
extern Obj_8015854C* lbl_80306DB8[];
extern s32 lbl_8034729C;
extern u32 lbl_802E7090[];
extern void *lbl_80346FA0;
extern void *lbl_80346F9C;
extern void *lbl_80346FB0;
extern void *lbl_80346FB4;
extern u32 lbl_80346FBC;
extern St_UNIT0000* lbl_80347000;
extern void *lbl_80347048;
extern s32 lbl_8034746C;
extern Gx lbl_80311AC0;
extern Slot_UNIT0000_UNIT0000 lbl_80308EF8[];
extern f32 lbl_803472DC;
extern f32 lbl_803472E0;
void fn_801E17E0(void *x);
void fn_80150CB0(void *a, void *b);
void fn_8015C4D8(void);
void fn_80144680(void);
void fn_801453D0(void);
void fn_80158374(void *p);
void fn_8015757C(s32 a, s32 b);
void fn_8020EF30(void *p);
void fn_80155A8C(void *p);
void fn_80109A94(void *p);
void *fn_801E1C7C(s32 size);
void fn_80217830(u32 h);
void *fn_801E1A74(s32 a, s32 size);
void fn_80153978(void);
void fn_80152284(void *p);
void fn_80154B6C(void);
void fn_801539C4(void);
void fn_80153730(void);
void fn_8014F4E8(void *p);
void fn_801DBE1C(const char *fmt, ...);
void sprintf(void *p, ...);
void fn_80158690(s16 idx);
void fn_80167690(void *p);
void fn_80150A80(u8 *p);
void fn_8014F72C(u8 *p, s32 n);
s32 fn_80156A3C(void);
void *fn_80158394(void);
void fn_80152B58(Obj_8015259C *h, s32 a4, s32 idx, s32 f68, s32 mode, s32 ship, s32 keyA, s32 keyB, s32 keyC, s32 keyD, s32 f48, s32 unused);
void fn_8015823C(u8 *p);
u32 fn_80153790(s32 a, s32 b, s32 c);
void fn_8014836C(s32 a, void *b);
void fn_80148228(s32 a, void *b);
s32 fn_801523A4(void *p, s32 a, s32 b, s32 c, s32 d);
s32 fn_8010CED4(void);
void fn_8012F72C(s32 a);
s32 fn_8015BB58(s32 a);
void fn_8015B358(void);
s32 fn_801CC62C(void *p);
void *fn_801CC3C4(void *p);
Blk *fn_8016748C(void *a, u32 v);
void *fn_8010A164(s32 a);
s32 fn_80129CA8(void *p);
void *memset(void *d, s32 c, u32 n);
void fn_8020EFD4(void *p);
void fn_801575C4(void *a);
typedef struct Slot_80154C34 {
    s32 active;
    s16 id;
    s16 timer;
} Slot_80154C34;
typedef struct Ent_80155AB4 {
    s32 id;
    u32 p;
} Ent_80155AB4;
extern char lbl_802B3EBC[];
extern u32 fn_80215F14(s32, s32, s32, s32, s32, s32, char*);
extern void printf(const char*, ...);
extern Ent_80155AB4 lbl_80346FF8[1];
extern s32 lbl_80346FF0;
extern char lbl_802B3E84[];
extern char lbl_802B3EA4[];
s32 fn_80215F8C(u32 h);
void fn_80215F94(u32 h);
extern char lbl_802B3EDC[];
s32 fn_80216CA4(void *p);
s32 fn_80216F1C(s32 a, s32 b);
void *memcpy(void *d, const void *s, u32 n);
void fn_8014FCF0(BtlShip *dst, s32 a, s32 b);
typedef struct {
    u8 pad0[0x1c];
    f32 scale;        /* 0x1C, must be > 0 to draw */
    u8 pad1[0x38 - 0x20];
    f32 pos[3];       /* 0x38 */
    u8 pad2[0xe4 - 0x44];
    void* model;      /* 0xE4 */
    u8 pad3[0x100 - 0xe8];
    void* texlist;    /* 0x100 */
    u8 pad4[0x176 - 0x104];
    u16 flags176;     /* 0x176 */
    u8 pad5[0x184 - 0x178];
    s32 hidden;       /* 0x184 */
} Obj80156DA0;
extern f32 lbl_8034A900;
extern void fn_80286EE8(void);
extern void fn_8028B498(void);
extern void fn_802974E0(void* v);
extern void fn_801E4FD4(Obj80156DA0* self);
extern void fn_801E4CB0(u16 a, void* b);
extern void njPushMatrixEx(void);
extern void njPopMatrixEx(void);
extern void njMultiMatrix(s32 a, void* m);
typedef struct {
    u8 pad0[0x24];
    Obj_8015854C* inner; /* 0x24 */
} Obj80159020;
typedef struct {
    u8 pad0[0xc];
    f32 value;        /* 0x0C */
} Entry80159020;
extern f32 lbl_8034A940;
extern f32 lbl_8034A95C;
extern u8 fn_801590F4(Obj_8015854C* in, s32 v);
extern u8* lbl_8034727C;
extern void* lbl_803472AC;
extern void* lbl_803472B0;
extern s32 lbl_803472B4;
extern void* fn_80129D40(void* p);
typedef struct Inner_8014FA10 { u8 pad[0x28]; s32 x28; u8 pad2[0x18]; s32 x44; u8 pad3[0x18]; s32 x60; u8 pad4[0x18]; s32 x7c; } Inner_8014FA10;
typedef struct Mid_8014FA10 { u8 pad[0x1e4]; Inner_8014FA10 *x1e4; } Mid_8014FA10;
typedef struct Sub10_8014FA10 { u8 pad[0x24]; Mid_8014FA10 *x24; } Sub10_8014FA10;
typedef struct Sub8_8014FA10 { u8 pad[0x10]; Sub10_8014FA10 *x10; } Sub8_8014FA10;
typedef struct Obj_8014FA10 {
    u8 pad0[8];
    Sub8_8014FA10 *x8;
    u8 padc[0x18 - 0xc];
    s32 x18;
    s32 x1c;
    s16 x20;
    s16 x22;
    u8 pad24[2];
    s16 x26;
    s32 x28;
    u8 pad2c[0x38 - 0x2c];
    s16 x38;
    s16 x3a;
    s16 x3c;
    s16 x3e;
    u8 pad40[4];
    s32 x44;
    u8 pad48[0xe0 - 0x48];
    s16 xe0;
    s16 xe2;
    s16 xe4;
    s16 xe6;
    u8 pade8[0x188 - 0xe8];
    s16 x188;
    s16 x18a;
    s16 x18c;
    s16 x18e;
    u8 pad190[4];
    s32 x194;
    u8 pad198[0x230 - 0x198];
    s16 x230;
    s16 x232;
    s16 x234;
    s16 x236;
    u8 pad238[4];
    s32 x23c;
    u8 pad240[0x2d8 - 0x240];
    s32 x2d8;
    u8 buf[0x680];
    u8 pad95c[0x9a8 - 0x95c];
    s32 x9a8;
    s32 x9ac;
    s32 x9b0;
    s32 x9b4;
    s32 x9b8;
    s32 x9bc;
    u8 pad9c0[0x9f0 - 0x9c0];
    s32 x9f0;
} Obj_8014FA10;
extern s32 lbl_803472C0;
extern s32 fn_8014FB58(void*o, s32 i);
typedef struct Pl { u8 pad[0xe]; s16 xe; } Pl;
extern s32 lbl_80346FC0;
extern s32 lbl_803472BC;
extern u8 *lbl_80346FD0;
extern s32 lbl_803472B8;
/* Battle camera pose (0x4c bytes; lbl_80306AC8 has the same layout, see fn_80150014). */
typedef struct CamPose {
    NJS_POINT3 pos;         /* 0x00 */
    Angle ang[3];           /* 0x0C */
    f32 x18;                /* 0x18 */
    NJS_POINT3 x1c;         /* 0x1C */
    NJS_POINT3 x28;         /* 0x28 */
    NJS_POINT3 x34;         /* 0x34 */
    Angle ang2[3];          /* 0x40 */
} CamPose;
typedef struct Fx {
    s32 mode;            /* 0x000 */
    f32 x04[12];         /* 0x004 saved copy of x34..x60 */
    f32 ca[12];          /* 0x034 four xyz points */
    f32 cb[12];          /* 0x064 */
    f32 loa[12];         /* 0x094 lower bounds of ca */
    f32 hia[12];         /* 0x0c4 upper bounds of ca */
    f32 lob[12];         /* 0x0f4 lower bounds of cb */
    f32 hib[12];         /* 0x124 upper bounds of cb */
    Angle *ang;          /* 0x154 */
    NJS_POINT3 *pos;     /* 0x158 */
    NJS_POINT3 *ofs2;    /* 0x15c */
    NJS_POINT3 *ofs1;    /* 0x160 */
    NJS_POINT3 *target;  /* 0x164 */
    s32 init;            /* 0x168 */
    Angle prev[3];       /* 0x16c */
    Angle dir[3];        /* 0x178 */
    u8 pad184[0x190 - 0x184];
    NJS_POINT3 look;     /* 0x190 */
    NJS_POINT3 eye;      /* 0x19c */
    CamPose pose;        /* 0x1a8: pos = at, ang = rot, x1c = cur, x28 = old, x34 = oldAt, ang2 = oldRot */
} Fx;
extern void fn_8015184C(Fx *o);
extern void fn_80151610(Fx *o, s32 a);
void fn_80216CB4(char *s);
char *strcpy(char *dst, const char *src);
extern s32 lbl_803472D0;
extern s32 lbl_80346FC4;
s32 fn_80153BBC(void);
void fn_801541D8(s32 a);
void fn_80150258(void);
void fn_80154404(void);
void fn_801539C8(void);
typedef struct { f32 pos[3]; s32 v[3]; } Rec_80157684;
/* One unit's precomputed track (0x8468): a pose per frame, the aim angles per frame, lane flags. */
typedef struct BtlTrack {
    Rec_80157684 rec[0x3AD];  /* 0x0000 */
    Angle aim[0x3AD][3];      /* 0x5838 */
    s8 f[4];                  /* 0x8454 */
    s32 count;                /* 0x8458 */
    s32 head;                 /* 0x845C */
    s32 tail;                 /* 0x8460 */
    s32 total;                /* 0x8464 */
} BtlTrack;
typedef struct {
    BtlTrack ent[4];
    s32 x211a0;
} BtlTrackSide;
/* *lbl_80346FD4: both sides' tracks. */
typedef struct {
    BtlTrackSide side[2];
    s32 ready;                /* 0x42348 */
} BtlTracks;
void fn_801577CC(BtlTracks *base, s32 a, s32 b, s32 i);
/* What fn_80157684 fills (unit_8010E164.c's Rec_80125820): position and angles of a frame. */
typedef struct Rec_80125820 {
    f32 pos[3];
    s32 v[3];
    f32 extra[3];
} Rec_80125820;
extern BtlTracks* lbl_80346FD4;
typedef struct { s32 f0; s32 f4; s16 h8; s16 ha; s16 hc; s16 he; s32 f10; } Dst;
typedef struct { u8 pad[0x1ef]; s8 b1ef; u8 pad2[0x40]; u16 h230; } In_80158250;
typedef struct { u8 pad[0x24]; In_80158250 *p24; } Mid_80158250;
typedef struct { u8 pad0[4]; s32 f4; u8 pad8[4]; s32 fc; s32 f10; } Ent_80158250;
typedef struct {
    s32 f0;
    s16 h4;
    s16 h6;
    s32 idx;
    u8 *tbl;
    Dst *dst;
    u8 pad14[0x28];
    s32 f3c;
    s32 f40;
    Mid_80158250 *p44;
} Obj_80158250;
typedef struct {
    u32 flags;
    s32 f4;
    u8 pad8[4];
    f32 fc;
    s16 h10;
    s16 h12;
    u8 pad14[0x5e];
    s16 h72;
    NJS_TEXLIST *f74;
    u8 pad78[0x10];
    f32 f88;
    f32 f8c;
    u8 pad90[8];
    NJS_TEXLIST *f98;
    u8 pad9c[0x14c];
    f32 f1e8;
    s16 h1ec;
    u8 pad1ee[0xe];
    s16 h1fc;
} Sub_8015887C;
typedef struct {
    u8 pad0[0x18];
    u8 flags;          /* 0x18 */
    u8 state;          /* 0x19 */
    u8 pad1a[0x24 - 0x1a];
    Sub_8015887C *s;   /* 0x24 */
} Obj_8015887C;
extern NJS_TEXLIST *lbl_80347034;
u8 fn_80159020(void *o);
void fn_80158DB4(Obj_8015887C *o);
void fn_80158BE8(Obj_8015887C *o);
void fn_8021C62C(Sub_8015887C *s, NJS_TEXLIST *tex, s32 b);
void fn_80159610(Sub_8015887C *s);
typedef struct { u8 pad[0x19]; u8 b19; } Ent_80158A80;
extern Ent_80158A80* lbl_80306D98[8];
typedef struct { u8 pad[0x20]; NJS_TEXLIST *texlist; } S80158B7Cb;
typedef struct { u8 pad[0x4]; S80158B7Cb *p4; } S80158B7Ca;
extern S80158B7Ca *lbl_80347028;
extern NJS_TEXLIST *lbl_80347030;
void fn_8012F744(void);
void fn_8022642C(void);
void fn_802275A4(NJS_TEXLIST *texlist, s32 a);
typedef struct { u8 pad0[0x10]; s32 f10; } Q;
typedef struct {
    s32 x0;
    s32 len;
    s32 t8;
    s32 tc;
    s32 t10;
    s32 t14;
    s32 t18;
    s32 f1c;
    void *f20;
    s32 f24;
    s32 f28;
    s32 f2c;
    s32 f30;
    u8 pad34[0x14];
    s32 f48;
    s32 f4c;
    s32 f50;
    s32 f54;
} E;
extern s32 lbl_802E6F58[];
extern s32 lbl_802E6FFC[];
extern E* lbl_803472A4;
typedef struct { u8 pad[0x1c]; f32 f1c; u8 pad2[0x168 - 0x20]; s16 mode; u8 pad3[0x1bc - 0x16a]; void *h1bc; } A_8015D234;
typedef struct { u32 flags; u8 pad[4]; A_8015D234 *a; } S_8015D234;
typedef struct { u8 pad[0x1d8]; S_8015D234 *s; } Obj_8015D234;
typedef struct { u8 pad[0x1c]; u32 cnt; } St_8015D234;
void fn_80222964(void *p);
void fn_80167374(void *obj);
typedef struct { u8 pad[0x1bc]; void *h1bc; u8 pad2[0x1d8 - 0x1c0]; S_8015D234 *s; } Obj_8015D340;
void fn_802229F8(void *p);
typedef struct { u8 pad[8]; } A_8015D54C;
typedef struct {
    u8 pad0[8];
    A_8015D54C *a;
    u8 pad0b[0x94 - 0xc];
    s32 f94;
    u8 pad98[0xd8 - 0x98];
    NJS_TEXLIST *fd8;
    void *fdc;
    s32 fe0;
    u8 pade4[0x124 - 0xe4];
    NJS_TEXLIST *f124;
    void *f128;
    s32 f12c;
    u8 pad130[0x170 - 0x130];
    NJS_TEXLIST *f170;
    void *f174;
} S_8015D54C;
typedef struct { u8 pad[0x17a]; u16 h17a; u8 pad2[0x1d8 - 0x17c]; S_8015D54C *s; } Obj_8015D54C;
typedef struct { u8 pad[0x1c]; s32 kind; u32 arg; } St_8015D54C;
extern char lbl_802B42C8[];
void *fn_80167604(Obj_8015D54C *o, u32 arg);
NJS_TEXLIST *fn_80167578(A_8015D54C *a, u32 arg);
s32 fn_80227810(NJS_TEXLIST *texlist);
typedef struct {
    u8 pad0[8];
    u32 f8;
    u8 pad1[0x6c - 0xc];
    Blk *f6c;
    u32 pad70;
    Blk *f74;
} S_8015DACC;
typedef struct { u8 pad[0x1c8]; M *m; u8 pad2[0x1d8 - 0x1cc]; S_8015DACC *s; } Obj_8015DACC;
typedef struct { u8 pad[0x1c]; s32 k; } St_8015DACC;
Blk *fn_80167428(Obj_8015DACC *o, s32 k);
typedef struct {
    u8 pad00[4];
    s32 kind;
    u8 pad08[0x10];
    u8* x18;
    u8 pad1c[0];
} Ent;
typedef struct {
    u8 pad00[0x58];
    s32 x58;
    s32 x5c;
    s32 x60;
    s32 pad64;
    Ent* x68;
} Obj;
extern f32 fn_801568F8(s32, s32, f32, f32);
struct Obj_801512DC;
typedef struct {
    s32 x0;
    s32 x4;
    s32 x8;
    s32 xc;
    s32 v[9];
} Ent_80151128;
typedef struct {
    struct Obj_801512DC *x0;
    Ent_80151128 ents[0x80];
    s32 x1a04;
    s32 x1a08;
    s32 x1a0c;
    s32 x1a10;
} Tab_80151128;
typedef struct {
    s32 idx;
    s32 v[9];
} Src;
typedef struct {
    u8 pad00[0x24];
    struct {
        u8 pad00[0x38];
        NJS_POINT3 pos;  /* 0x38 */
        Angle ang[3];    /* 0x44 */
    }* inner;
} Model;
typedef struct {
    s32 on;
} Flag;
typedef struct {
    u8 pad00[0xC];
    NJS_POINT3 src;   /* 0x0C */
    NJS_POINT3 dst;   /* 0x18 */
    u8 pad24[0x44 - 0x24];
    Model* model;     /* 0x44 */
    u8 pad48[0x6C - 0x48];
    Flag* flag;       /* 0x6C */
} Obj_8015275C;
typedef struct {
    u8 pad00[4];
    s32 x4;
    s32 count;        /* 0x08 */
    Model* model;     /* 0x0C */
    u8 x10[0x24 - 0x10];
} Obj_80153060;
/* One lane of the battle field: a cell row indexed by position + 0x54, and its bounds. */
typedef struct {
    s8 cell[0xA0];   /* 0x00 */
    s32 min;         /* 0xA0 */
    s32 max;         /* 0xA4 */
} Lane;
void fn_8014F770(Lane *p);
extern s32 lbl_80347010;
/* A side's state (BtlSide.ship, 0xA00 bytes, set up by fn_8014FCF0). */
struct BtlShip {
    u8* x0;                  /* 0x000 */
    u8* x4;                  /* 0x004 */
    u32 x8;                  /* 0x008 */
    s16 xc;                  /* 0x00C */
    s16 idx;                 /* 0x00E side index */
    u8 pad10[8];
    u8 x18[0x20];            /* 0x018 handed to fn_80158358 */
    Lane lane[2];            /* 0x038 */
    u8 pad188[0x95C - 0x188];
    Obj_80153060 fx[2];      /* 0x95C */
    s32 x9a4;                /* 0x9A4 */
    u8 pad9a8[0x9C0 - 0x9A8];
    u8 x9c0[0x30];           /* 0x9C0 fn_8014F72C */
    u8 pad9f0[0xA00 - 0x9F0];
};
void fn_801532B4(Obj_80153060 *p);
typedef struct {
    u8 a;
    s8 b;
    u16 c;
} Key;
typedef struct {
    s32 w[2];
} Pair;
typedef struct {
    s32 a, b, c;
} KeyIn;
typedef struct {
    s32 x0;
    s32 x4;
    s16 x8;
    s16 xa;
    s32 xc;
    s32 x10;
    u8 pad14[8];
    u8 x1c;
    u8 x1d;
    u8 x1e;
    u8 x1f;
    u8 x20;
    u8 pad21[3];
    Key keys[31];   /* 0x24 */
    Pair pairs[31]; /* 0xA0 */
} Anim;
typedef struct {
    u8 pad[0x18];
    u8 flags;
    u8 pad19[0x24 - 0x19];
    Anim* anim;
} Handle;
extern s32 lbl_80347588;
extern s32 fn_801D6E38(void);
extern Handle* fn_80226704(s32, void*, s32);
extern void* fn_801E1A2C(s32, s32);
typedef struct {
    void *x0;
    u32 x4;
    u16 x8;
    u8 pad_a[2];
    u32 xc;
    u32 x10;
    u32 x14;
    u32 x18;
    u8 x1c;
    u8 x1d;
    u8 x1e;
    u8 x1f;
    u8 pad20[4];
    Key keys[31];
    Pair pairs[31];
} Anim_80155438;
typedef struct {
    u8 pad[0x18];
    u8 flags;
    u8 pad19[0x24 - 0x19];
    Anim_80155438 *anim;
} Handle_80155438;
void fn_801D6CBC(void *a, void *b);
void fn_801D6C3C(void *a);
void fn_801E1784(void *a);
void fn_80155438(Handle_80155438 *h);
typedef struct {
    s32 x0;
    s32 x4;
    u16 x8;
    u8 pad[0x1E - 0xA];
    u8 x1e;
    u8 x1f;
    u8 pad20[4];
    Key keys[31]; /* 0x24 */
} Anim_80155624;
/* lbl_80346FE0 (0x1d8 bytes): the battle sequence state, its keys and the pending events. */
typedef struct Seq_80346FE0 {
    s32 x0;
    u8 pad4[2];
    s16 x6;
    s32 x8;
    u16 xc;
    u16 xe;
    u32 x10;              /* events queued */
    Key keys[31];         /* 0x14 */
    Pair pairs[31];       /* 0x90 */
    Slot_80154C34 pend[10]; /* 0x188 */
} Seq_80346FE0;
extern Seq_80346FE0 *lbl_80346FE0;
typedef struct {
    u8 pad00[0x44];
    f32 pos[3];  /* 0x44 */
    f32 rot[3];  /* 0x50 */
} Part;
typedef struct {
    u8 pad00[0x38];
    NJS_POINT3 pos; /* 0x38 */
    Angle rot[3];   /* 0x44 */
    u8 pad50[0x1C8 - 0x50];
    Part* part;     /* 0x1C8 */
} Obj_80156B04;
extern void njSetMatrix(f32* dst, f32* src);
extern void njTranslate(f32* m, f32 x, f32 y, f32 z);
extern void njRotateZXY(f32* m, Angle x, Angle y, Angle z);
extern void njGetTranslation(f32* m, NJS_POINT3* out);
extern void fn_80291C44(void* p);
extern f32 fn_80291A5C(f32 x);
extern s32 lbl_8030EA10[];
typedef struct {
    f32 x, y, z;
    f32 h;
    s16 a;
    u16 b;
} Probe;
typedef struct {
    u8 pad0[0x38];
    f32 x38, x3c, x40;
    u8 pad44[0x1b8 - 0x44];
    void *x1b8;
} Obj_8015D768;
typedef struct {
    u8 pad0[8];
    Obj_8015D768 *x8;
} Hold_8015D768;
typedef struct {
    u8 pad0[0x38];
    f32 x38, x3c, x40;
    u8 pad44[0x104 - 0x44];
    f32 x104, x108, x10c;
    u8 pad110[0x1d8 - 0x110];
    Hold_8015D768 *x1d8;
} Ent_8015D768;
typedef struct {
    u8 pad_0[0x8];
    u32 f8;
    u8 pad_c[0x10];
    f32 x1c, x20, x24, x28, x2c, x30;
    s32 x34;
} Arg;
extern s32 fn_802254A0(f32 *p, void *q);
extern s32 fn_80224588(s32 a, Probe *p, s32 b);
extern void fn_801673D8(Obj_8015D768 *o, s32 a);
extern void fn_801671C0(Obj_8015D768 *o);
extern void fn_802135B4(NJS_POINT3 *v, f32 *out);
typedef struct {
    u8 pad0[0x38];
    f32 x38, x3c, x40;
    s32 x44, x48, x4c;
    u8 pad50[0x1b8 - 0x50];
    void *x1b8;
} Obj_8015D910;
typedef struct {
    u8 pad0[8];
    Obj_8015D910 *x8;
} Hold_8015D910;
typedef struct {
    u8 pad0[0x38];
    f32 x38, x3c, x40;
    u8 pad44[0x104 - 0x44];
    f32 x104, x108, x10c;
    u8 pad110[0x1d8 - 0x110];
    Hold_8015D910 *x1d8;
} Ent_8015D910;
typedef struct { u8 pad0[0x24]; void *x24; } Node;
typedef struct { s32 f0; s32 f4; s16 h8; s32 fc; s32 f10; } In;
typedef struct {
    u8 pad0[4];
    s32 f4;
    s32 f8;
    f32 fc;
    s16 h10;
    s16 h12;
    u8 pad14[4];
    s32 f18;
    u8 pad1c[4];
    f32 f20;
    u8 pad24[4];
    s32 f28;
    s32 f2c;
    s32 f30;
    s32 f34;
    u8 pad38[0x4a - 0x38];
    s16 h4a;
    u8 pad4c[0x6e - 0x4c];
    s16 h6e;
    u8 pad70[2];
    s16 h72;
    s32 f74;
    u8 pad78[0xb4 - 0x78];
    s16 hb4;
    u8 padb6[0xd8 - 0xb6];
    s16 hd8;
    u8 padda[0xfc - 0xda];
    s16 hfc;
    u8 padfe[0x120 - 0xfe];
    s16 h120;
    u8 pad122[0x144 - 0x122];
    s16 h144;
    u8 pad146[0x168 - 0x146];
    s16 h168;
    u8 pad16a[0x18c - 0x16a];
    s16 h18c;
    u8 pad18e[0x1b0 - 0x18e];
    s16 h1b0;
    u8 pad1b2[0x1d4 - 0x1b2];
    s16 h1d4;
    u8 pad1d6[0x1f4 - 0x1d6];
    Node *x1f4;
} Obj_80158708;
extern void *lbl_803475A8;
extern Node *fn_802268E8(void *, void *);
extern void *fn_801E1C7C(s32);
void fn_801589BC(Obj_8015887C *t);
extern void fn_801580A4(s32 *out, f32 *v);
typedef struct {
    s32 f0;
    u8 pad4[0x34 - 4];
    f32 curA[12];
    f32 curB[12];
    f32 loA[12];
    f32 hiA[12];
    f32 loB[12];
    f32 hiB[12];
    u8 pad154[0x1f4 - 0x154];
} Obj_8015205C;
typedef struct {
    u8 pad0[0x38];
    NJS_POINT3 pos;
    Angle ang[3];
    u8 pad50[0x1ec - 0x50];
    u8 b1ec;
    u8 b1ed;
    u8 b1ee;
    u8 b1ef;
    u8 b1f0;
    u8 b1f1;
    u8 pad1f2[0x22c - 0x1f2];
    s16 h22c;
    s16 h22e;
    s16 h230;
} Inner_801528AC;
typedef struct {
    u8 pad0[0x24];
    Inner_801528AC* inner;
} Model_801528AC;
typedef struct {
    u8 pad0[0xc];
    s32 fc;
    u8 pad10[0x1c - 0x10];
} Row_801528AC;
typedef struct {
    u8 pad0[0x20];
    Row_801528AC rows[1];
} Tab_801528AC;
typedef struct {
    s32 f0;
    u8 pad4[4];
    s32 f8;
    NJS_POINT3 src;
    NJS_POINT3 dst;
    u8 pad24[4];
    Model_801528AC* model;
    s32 f2c;
    u8 pad30[4];
    s32 f34;
    u8 pad38[4];
    u8* f3c;
    s32 f40;
    u32 f44;
    s32 f48;
    u8 pad4c[4];
    s32 f50;
    u8 pad54[4];
    s32 f58;
    u8 pad5c[0x68 - 0x5c];
    Tab_801528AC* f68;
    void* f6c;
} Obj_801528AC;
typedef struct {
    u8 pad0[4];
    s32 f4;
    s32 f8;
    u8 padc[0x34 - 0xc];
    f32 f34;
    f32 f38;
    f32 f3c;
    f32 f40;
    u8 pad44[0x58 - 0x44];
} Ent_80157150;
typedef struct {
    s32 count;
    u8 pad4[4];
    Ent_80157150 *ents;
} Cnt_80157150;
extern Cnt_80157150* lbl_803472A8;
typedef struct {
    u8 pad0[4];
    u32 cnt;
    u16 type;
} Anim_80157EA8;
typedef struct {
    u8 pad_0[0x10];
    struct Mode_80157948* mode;
    u8 pad_14[0x30];
    f32 pos[3];
    f32 rot[3];
} Part_80157EA8;
typedef struct {
    u8 pad0[0xe8];
    Anim_80157EA8 *anim;
    u8 padec[0x18c - 0xec];
    f32 frame;     /* 0x18c */
    u8 pad190[0x1c8 - 0x190];
    Part_80157EA8 *part;
} Obj_80157EA8;
extern Obj_80157EA8 *lbl_80347014[2];
extern Obj_80157EA8 *lbl_8034701C[2];
typedef struct {
    f32 pos[3];
    s32 ang[3];
    s32 off[3];
} Out_80157EA8;
extern s32 fn_801E78C8(Anim_80157EA8 *a, void *p, void *ang, void *off, f32 frame);
extern void njRotateZXY(NJS_MATRIX m, s32 x, s32 y, s32 z);
typedef struct {
    s16 n;
    s16 a;
    s16 b;
} Rec_80150DAC;
extern s16 lbl_802E5EF0[];
typedef struct {
    Holder_UNIT0000 *p0;
    u8 pad4[0xc];
    s32 f10;
} Ent_8015A888;
extern s32 fn_80145CA4(s32 a, s32 b, s32 c);
extern void fn_8015854C(s16 i, u16 flags);
extern void fn_801586D4(s16 i);
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    u8 buf[0x4c - 0xc];
    s32 f4c;
} Obj_80153518;
extern Obj_80153518 lbl_80306758;
extern char lbl_802B3BCC[];
extern s32 fn_80109E7C(u8* b, s32 n);
typedef struct {
    u8 pad0[4];
    s32 f4;
    u8 pad8[0xc - 8];
    u8 padc[6];
    s16 h12;
    s32 f14;
    s32 f18;
    u8 pad1c[4];
    f32 f20;
    f32 f24;
    s32 f28;
    s32 f2c;
    u8 pad30[4];
    s32 f34;
    u8 pad38[0x78 - 0x38];
    char buf[0x1e4 - 0x78];
    f32 f1e4;
    u8 pad1e8[6];
    s16 h1ee;
} S_80158DB4;
typedef struct {
    u8 pad0[4];
    s32 f4;
    u8 pad8[0x44 - 8];
    s16 h44;
    s16 h46;
    s16 h48;
    u8 pad4a[0x6e - 0x4a];
    s16 h6e;
    u8 pad70[0xbe - 0x70];
    u8 b_be;
    u8 pad_bf[0xe2 - 0xbf];
    u8 b_e2;
    u8 pad_e3[0x106 - 0xe3];
    u8 b_106;
    u8 pad_107[0x12a - 0x107];
    u8 b_12a;
    u8 pad_12b[0x14e - 0x12b];
    u8 b_14e;
    u8 pad_14f[0x172 - 0x14f];
    u8 b_172;
    u8 pad_173[0x196 - 0x173];
    u8 b_196;
    u8 pad_197[0x1ba - 0x197];
    u8 b_1ba;
    u8 pad_1bb[0x1f0 - 0x1bb];
    u8 b_1f0;
} S_80158BE8;
typedef struct {
    f32 x, y, z, u, v;
    u32 colour;
} Vtx_80159610;
typedef struct {
    u8 pad0[0x10];
    s16 h10;
    u8 pad12[0x72 - 0x12];
    s16 h72;
    void *p74;
    u8 pad78[0x1f0 - 0x78];
    u8 alpha;
} Obj_80159610;
extern u32 lbl_802E6F00[5];
extern f32 fn_801DBD9C(f32 z);
extern void fn_8021EDE0(void *t, s16 a);
extern s32 fn_8021EE1C(void *t, u32 a);
extern void fn_80291064(Vtx_80159610 *v, s32 n, s32 mode);
extern char lbl_802B3BD8[];
typedef struct {
    u8 pad0[4];
    u32 cnt;
} Anim_80156E54;
typedef struct {
    u8 pad0[0x1c];
    f32 scale;
    u8 pad20[0x38 - 0x20];
    f32 pos[3];
    u8 pad44[0xe4 - 0x44];
    void *model;
    Anim_80156E54 *anim;
    void *xec;
    u8 padf0[0x100 - 0xf0];
    NJS_TEXLIST *texlist;
    u8 pad104[0x176 - 0x104];
    u16 flags176;
    u8 pad178[0x184 - 0x178];
    s32 hidden;
    u8 pad188[4];
    f32 frame;
    f32 speed;
    u8 pad194[4];
    s32 done;
} Obj_80156E54;
extern f32 lbl_8034A8F8;
extern f32 lbl_8034A904;
void fn_801E7194(u16 a, void *model, Anim_80156E54 *anim, void *c, f32 frame);
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fc;
    s32 f10;
    f32 f[12];
} In_801512DC;
typedef struct Obj_801512DC {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fc;
    u8 pad10[0x20 - 0x10];
    Fx sub;
} Obj_801512DC;
/* *lbl_80346FA4: the battle camera: the current and previous shot, the shot table, the output view. */
typedef struct {
    s32 f0;                  /* 0x000 current shot */
    s32 f4;                  /* 0x004 previous shot */
    s32 f8;
    s32 fc;
    Obj_801512DC* f10;       /* 0x010 shots */
    CamPose *pose[128];      /* 0x014 */
    CamPose out;             /* 0x214 */
} BtlCam;
extern BtlCam *lbl_80346FA4;
extern char lbl_802B3B18[];
/* lbl_8034727C: rows of 0x3E bytes starting at +0x3A (fn_8015A780 reads +0x50/+0x68
 * of the same rows). Fields come in pairs 0x18 apart, picked by a 0/1 flag. */
typedef struct Row {
    s8 x00;          /* +0x3A */
    u8 pad01[0x05 - 0x01];
    s8 x05;          /* +0x3F */
    u8 pad06[0x18 - 0x06];
    s8 x18;          /* +0x52 */
    u8 pad19[0x1D - 0x19];
    s8 x1D;          /* +0x57 */
    u8 pad1E[0x3E - 0x1E];
} Row;
typedef struct RowTable {
    u8 pad00[0x3A];
    Row row[1];
} RowTable;
extern s32 lbl_80346FF4;
typedef struct {
    u8 a[4][2];
    u8 b[4][2];
} Row_80157E04;
typedef struct Item {
    u8 pad0[0x24];
    s16 h24;
    s16 h26;
    s8 b28;
    u8 pad29[3];
    s32 w2c;
} Item;
typedef struct {
    s32 x0;
    s32 x4;
    s32 x8;
    s32 xc;
    s32 x10;
    s32 x14;
    Item *x18;
} Ent_80150800;
typedef struct {
    s32 w0;
    s32 w4;
    s32 w8;
    s32 wc;
    s32 w10;
    s32 w14;
    s32 w18;
    s32 w1c;
    Ent_80150800 ent[2];
} Obj_80150800;
/* *lbl_80346FA8: the battle camera's mode state (0x6C, fn_80150A80). */
extern Obj_80150800 *lbl_80346FA8;
typedef struct {
    u8 pad0[0x58];
    s32 w58;
    s32 w5c;
    s32 w60;
    s32 w64;
    u32 w68;
} Tail;
typedef struct {
    s16 v;
    s16 pad[2];
} S6;
extern void fn_801536E0(void);
extern void fn_8014F714(Item *p);
extern u32 lbl_80310B3C[];
extern s32 fn_80212050(void);
extern Anim* fn_801552B0(s32 owner, KeyIn* in1, Pair* in2);
extern char lbl_802B3C34[];
extern s32 SePlay(s32 bank, s8 arg1, s8 id);
struct Pose {
    u8 pad[0x38];
    f32 tx, ty, tz;
    s32 rx, ry, rz;
};
/* Defined ahead of the file's other .rodata users: its three initializers are read through the
 * section base, and in the original they start that base (lbl_802B3F00 + 0). */
extern void *lbl_80346FD8[2];
void fn_801539C0(void);
void fn_80155D28(void);
void fn_80155F5C(void);
void fn_80153498(void);
void fn_801558EC(void);
void fn_8014FD9C(void);
void fn_80154B04(void);
void fn_801539D0(void);
void fn_80149070(void);
void fn_8010A094(void);
typedef struct Mode_80157948 {
    s32 n;
    s32 v[8];
} Mode_80157948;
s32 fn_80157EA8(Out_80157EA8 *out, Obj_80157EA8 *obj, f32 frame);
extern s32 fn_8015AAF0(s32 x);
extern s32 fn_8015AA88(u32 x);
extern void* lbl_80346FD8[2];
extern void fn_80153A04(void);
extern void fn_80154B38(void);
extern void fn_80155910(void);
extern void fn_801534E8(void);
extern void fn_80155F80(void);
extern void fn_80155D2C(void);
extern void fn_801539CC(void);

/* Frees the 32 resource slots of lbl_80306B14. As an inline its counter's zero is copied for the
 * NULL store (li r30 / mr r31), as the original has. */
static inline void ClearAll(void) {
    s32 i;
    for (i = 0; i < 0x20; i++) {
        if (lbl_80306B14[i].p != 0) {
            fn_801E17E0(lbl_80306B14[i].p);
        }
        lbl_80306B14[i].p = 0;
    }
}

/* Shutdown: frees the slot resources and buffers and calls the subsystems' exit functions. */
extern void fn_80154CC4(s16 id);

void fn_80153060(Obj_80153060* o, f32* mtx);

void fn_8014F99C(BtlShip *o, f32 *m) {
    BtlSide *p = lbl_80346FC8[o->idx];
    if (p->lead.target != 0) {
        EvExt *r = p->lead.target->ext;
        njTranslate(m, r->target.x, r->target.y, r->target.z);
    }
    fn_80153060(o->fx, m);
}

s32 fn_80150800(Obj_80150800 *o);
void fn_801517EC(Fx *p);
void fn_801515EC(Fx *p);
void fn_801514C4(Fx *o, s32 flag);
typedef struct In_80150014 {
    NJS_POINT3 pos;
    Blk w;
} In_80150014;
extern CamPose lbl_80306AC8;
extern void* lbl_80346F98;
extern void fn_8015073C(Obj_80150800 *o, s16 (*tab)[4][2][8][25], Tab_80151128 *t);
extern s32 fn_80150EF8(Tab_80151128 *t, s32 idx, Item *in);
extern void fn_801502B8(BtlCam* m);

static inline void Select(s32 t) {
    BtlCam* m = lbl_80346FA4;
    m->f4 = m->f0;
    m->f0 = t;
    if (m->f4 != m->f0) {
        if (m->f0 != 0) {
            Obj_801512DC* e = m->f10 + m->f0;
            fn_801517EC(&e->sub);
            fn_801515EC(&e->sub);
        }
        m->fc = 0;
        m->f8 = 0;
    } else {
        m->fc = 0;
        m->f8 = 0;
        m->f4 = 0;
    }
}

void fn_80150014(In_80150014* a, f32* b, NJS_POINT3* c) {
    BtlCam* m;

    lbl_80306AC8.x28.x = lbl_80306AC8.x1c.x;
    lbl_80306AC8.x28.y = lbl_80306AC8.x1c.y;
    lbl_80306AC8.x28.z = lbl_80306AC8.x1c.z;
    lbl_80306AC8.x1c.x = c->x;
    lbl_80306AC8.x1c.y = c->y;
    lbl_80306AC8.x1c.z = c->z;
    lbl_80306AC8.x34.x = lbl_80306AC8.pos.x;
    lbl_80306AC8.x34.y = lbl_80306AC8.pos.y;
    lbl_80306AC8.x34.z = lbl_80306AC8.pos.z;
    lbl_80306AC8.pos.x = a->pos.x;
    lbl_80306AC8.pos.y = a->pos.y;
    lbl_80306AC8.pos.z = a->pos.z;
    lbl_80306AC8.ang2[0] = lbl_80306AC8.ang[0];
    lbl_80306AC8.ang2[1] = lbl_80306AC8.ang[1];
    lbl_80306AC8.ang2[2] = lbl_80306AC8.ang[2];
    lbl_80306AC8.ang[0] = a->w.a;
    lbl_80306AC8.ang[1] = a->w.b;
    lbl_80306AC8.ang[2] = a->w.c;
    lbl_80306AC8.x18 = 60.0f;
    if (fn_80150800(lbl_80346FA8) != 0) {
        fn_8015073C(lbl_80346FA8, lbl_80346FAC, lbl_80346FB0);
        Select(lbl_80346FA8->w18);
    }
    m = lbl_80346FA4;
    if (m->fc != 0) {
        m->fc--;
    }
    if (m->f0 != 0) {
        fn_801514C4(&m->f10[m->f0].sub, 1);
    }
    if (m->f4 != 0) {
        fn_801514C4(&m->f10[m->f4].sub, 1);
    }
    lbl_80346F98 = &lbl_80346FA4->f10[lbl_80346FA4->f0].sub;
    fn_801502B8(lbl_80346FA4);
    a->pos.x = lbl_80346FA4->out.pos.x;
    a->pos.y = lbl_80346FA4->out.pos.y;
    a->pos.z = lbl_80346FA4->out.pos.z;
    a->w.a = lbl_80346FA4->out.ang[0];
    a->w.b = lbl_80346FA4->out.ang[1];
    a->w.c = lbl_80346FA4->out.ang[2];
    *b = lbl_80346FA4->out.x18;
}

void fn_8015073C(Obj_80150800 *o, s16 (*tab)[4][2][8][25], Tab_80151128 *t)
{
    Ent_80150800 *e = &o->ent[o->w1c];
    s32 v;
    s32 r;

    v = tab[lbl_803472BC][lbl_80346FC0][lbl_803472B8][e->x4][o->w0];
    if (v == -1) {
        v = o->w10;
    }
    e->x8 = v;
    o->w14 = v;
    o->w10 = v;
    r = fn_80150EF8(t, v, e->x18);
    e->xc = r;
    e->x10 = t->x1a08;
    e->x14 = t->x1a0c;
    o->w18 = r;
}

s32 fn_80153BBC(void)
{
    s8 en;
    s32 a;
    s32 b;
    s32 c;
    en = lbl_80346FB8->active;
    if (en == 0) {
        return 0;
    }
    a = lbl_803472BC;
    b = lbl_803472C0;
    c = lbl_803472B8;
    if (lbl_80346FB8->b1 == a && lbl_80346FB8->b2 == b && lbl_80346FB8->b3 == c) {
        return 0;
    }
    if (en != 0) {
        lbl_80346FC8[1]->a[0] = lbl_80346FC8[1]->b[lbl_80346FB8->cell[a][b][c].v[0]];
        lbl_80346FC8[1]->a[1] = lbl_80346FC8[1]->b[lbl_80346FB8->cell[a][b][c].v[1]];
        lbl_80346FC8[1]->a[2] = lbl_80346FC8[1]->b[lbl_80346FB8->cell[a][b][c].v[2]];
        lbl_80346FC8[1]->a[3] = lbl_80346FC8[1]->b[lbl_80346FB8->cell[a][b][c].v[3]];
    }
    lbl_80346FB8->b1 = lbl_803472BC;
    lbl_80346FB8->b2 = lbl_803472C0;
    lbl_80346FB8->b3 = lbl_803472B8;
    return 1;
}

/* An angle as a signed value in [-0x8000, 0x8000). */
static inline s32 wrap(u16 a) {
    s32 x = a;
    if (x >= 0x8000) {
        x = -(0x10000 - x);
    }
    return x;
}

static inline s32 ToAngle(f32 deg) {
    return 182.04445f * deg;
}

s32 fn_8015432C(s32 side, s32 ang) {
    s32 best = 0;
    f32 max = 0.0f;
    s32 i;
    s32 v;
    s32 d;
    f32 f;
    f32 df;
    for (i = 0; i < 8; i++) {
        EvObj *t = lbl_80346FC8[side]->a[i].target;
        if (t != 0) {
            v = wrap(ToAngle(t->ext->rot.y));
            d = wrap(v - ang);
            df = d;
            f = fabs(df);
            if (f > max) {
                max = f;
                best = i;
            }
        }
    }
    return best;
}

/* A unit's info record as the gauges read it (count-prefixed, see EvInfo). */
typedef struct {
    s32 count;              /* 0x00 */
    u8 pad4[0x48 - 4];
    u32 x48;
    u32 x4c;
} StatInfo;

typedef struct {
    f32 f[21];
} Gauges;


static inline f32 HalfHi(EvObj *w) {
    StatInfo *i = w->ext->info;
    u32 v;
    if (i->count > 0x12) {
        v = i->x4c;
    } else {
        v = 0;
    }
    return v >> 1;
}

static inline f32 HalfLo(EvObj *w) {
    StatInfo *i = w->ext->info;
    u32 v;
    if (i->count > 0x11) {
        v = i->x48;
    } else {
        v = 0;
    }
    return v >> 1;
}

void fn_801545EC(s32 idx, Gauges *g) {
    BtlSide *o = lbl_80346FC8[idx];

    if (o->valid == 0) {
        g->f[2] = 0.0f;
        g->f[3] = 0.0f;
        g->f[0] = 0.0f;
        g->f[1] = 0.0f;
        g->f[4] = 0.0f;
        g->f[5] = 3.0f;
        g->f[6] = 3.0f;
        g->f[7] = 3.0f;
        g->f[8] = 3.0f;
        g->f[9] = 3.0f;
        g->f[10] = 3.0f;
        g->f[11] = 3.0f;
        g->f[12] = 3.0f;
        g->f[17] = 3.0f;
        g->f[18] = 3.0f;
        g->f[19] = 8.0f;
        g->f[20] = 8.0f;
        g->f[13] = 3.0f;
        g->f[14] = 3.0f;
        g->f[15] = 8.0f;
        g->f[16] = 8.0f;
    } else {
        g->f[2] = o->a[0].target->ext->target.x;
        g->f[3] = -o->a[1].target->ext->target.x;
        g->f[0] = o->a[2].target->ext->target.z;
        g->f[1] = -o->a[3].target->ext->target.z;
        g->f[4] = o->centre.y;
        g->f[5] = HalfHi(o->a[2].target);
        g->f[6] = HalfHi(o->a[2].target);
        g->f[7] = HalfLo(o->a[2].target);
        g->f[8] = HalfLo(o->a[2].target);
        g->f[9] = HalfHi(o->a[3].target);
        g->f[10] = HalfHi(o->a[3].target);
        g->f[11] = HalfLo(o->a[3].target);
        g->f[12] = HalfLo(o->a[3].target);
        g->f[13] = HalfHi(o->a[0].target);
        g->f[14] = HalfHi(o->a[0].target);
        g->f[15] = HalfLo(o->a[0].target);
        g->f[16] = HalfLo(o->a[0].target);
        g->f[17] = HalfHi(o->a[1].target);
        g->f[18] = HalfHi(o->a[1].target);
        g->f[19] = HalfLo(o->a[1].target);
        g->f[20] = HalfLo(o->a[1].target);
    }
}

void fn_80154B6C(void) {
    Seq_80346FE0* g = lbl_80346FE0;
    if (g != NULL) {
        int i;
        Slot_80154C34* p = g->pend;
        g->x10 = 0;
        for (i = 0; i < 10; i++, p++) {
            if (p->active != 0) {
                p->timer--;
                if (p->timer < 0) {
                    fn_80212050();
                    if (fn_801D6E38() != 0) {
                        fn_80154CC4(p->id);
                        if (lbl_8030CEA0.x82c != 0) {
                            lbl_8030CEA0.x82c = 4;
                        }
                    }
                    p->active = 0;
                    p->id = 0;
                    p->timer = 0;
                }
            }
        }
    }
}

void fn_80156024(void) {
    s32 i;
    ClearAll();
    fn_801539C0();
    fn_80155D28();
    fn_80155F5C();
    lbl_80347024 = 0xC350;
    fn_801E17E0(lbl_80346FD8[0]);
    fn_801E17E0(lbl_80346FD8[1]);
    for (i = 0; i < 2; i++) {
        fn_801E17E0(lbl_80346FC8[i]);
    }
    fn_80153498();
    fn_801558EC();
    fn_8014FD9C();
    fn_80154B04();
    fn_801539D0();
    fn_801E17E0(lbl_80346FD0);
    fn_80149070();
    fn_8010A094();
}

void fn_80157684(Rec_80125820 *out, s32 a, f32 t);
extern f32 njScalor(NJS_VECTOR *v);

static inline s32 Wrap16(u16 x)
{
    s32 d = x;
    if (d >= 0x8000) {
        d = -(0x10000 - d);
    }
    return d;
}

static inline s32 AngWrap(s32 a, s32 b)
{
    return Wrap16(a - b);
}

/* Declared s32 with no return statement (callers ignore r3): that keeps r3 out of the
   allocator in the tail, which is what the original's r4-r6 registers show. */
s32 fn_80156768(s32 a, s32 b, s32* out1, s32* out2, f32 t)
{
    BtlSide* o = lbl_80346FC8[b];
    NJS_MATRIX m;
    Rec_80125820 pb;
    Rec_80125820 pa;
    f32 v[3];
    Angle ang[3];
    NJS_POINT3 p;

    fn_80157684(&pb, b, t);
    njUnitMatrix(m);
    njRotateZXY(m, pb.v[0], pb.v[1], pb.v[2]);
    njCalcPoint(m, &o->centre, &p);
    pb.pos[0] += p.x;
    pb.pos[1] += p.y;
    pb.pos[2] += p.z;
    fn_80157684(&pa, a, t);
    v[0] = pb.pos[0] - pa.pos[0];
    v[1] = 0.0f;
    v[2] = pb.pos[2] - pa.pos[2];
    v[0] = -v[0];
    v[1] = -v[1];
    v[2] = -v[2];
    fn_801580A4(ang, v);
    if (out1 != NULL) {
        *out1 = AngWrap(ang[1], pa.v[1]);
    }
    if (out2 != NULL) {
        *out2 = AngWrap(ang[1], pb.v[1]);
    }
}

f32 fn_801568F8(s32 a, s32 b, f32 ta, f32 tb) {
    Rec_80125820 ra;
    Rec_80125820 rb;
    NJS_VECTOR v;
    fn_80157684(&ra, b, ta);
    fn_80157684(&rb, a, tb);
    v.x = ra.pos[0] - rb.pos[0];
    v.y = 0.0f;
    v.z = ra.pos[2] - rb.pos[2];
    v.x = -v.x;
    v.y = -v.y;
    v.z = -v.z;
    return njScalor(&v);
}

void fn_80156CC4(Obj_80157EA8 *o, struct Pose *p)
{
    f32 off[3] = { 0.0f, 0.0f, 0.0f };
    f32 pos[3] = { 0.0f, 0.0f, 0.0f };
    s32 ang[3] = { 1, 1, 1 };

    fn_801E78C8(o->anim, pos, ang, off, o->frame);
    p->tx = pos[0];
    p->ty = pos[1];
    p->tz = pos[2];
    p->rx = ang[0];
    p->ry = ang[1];
    p->rz = ang[2];
}
typedef struct Flags { u32 w; } Flags;
typedef struct Owner_8015C8F4 { u8 pad[0x1d8]; Flags *fl; } Owner_8015C8F4;
typedef struct Arg_8015C8F4 { u8 pad[0x1c]; u32 on; } Arg_8015C8F4;
typedef struct Sub { u8 pad[8]; void *p; } Sub;
typedef struct Owner_8015C928 { u8 pad[0x1d8]; Sub *fl; } Owner_8015C928;
typedef struct Arg_8015C928 { u8 pad[0x1c]; s32 v; } Arg_8015C928;
void fn_801E5EA4(void *p, s16 v);
extern void *fn_80109D74(s32 h);
typedef void (*CmdFn)(s32 n, f32 *args);
extern CmdFn lbl_802E6EF0[4];
float fn_801F6120(float **p);
typedef struct {
    u8 pad0[0x34];
    f32 x34, x38, x3c, x40;
    u8 pad44[0x58 - 0x44];
} Rec58;
extern void fn_80157E54(s32 i, s32 j);
extern void fn_80157E04(s32 i, s32 j, u8 a0, u8 a1, u8 b0, u8 b1);
typedef struct KeyEnt {
    u8 pad00[0x14];
    s32 x, y, z; /* 0x14: angle units */
    u8 pad20[0x0c];
} KeyEnt;
typedef struct KeyAnim {
    u8 pad00[0x168];
    s16 state;
} KeyAnim;
typedef struct KeyHolder {
    u8 pad00[8];
    KeyAnim* anim;
    u8 pad0c[0x60 - 0x0c];
    s32 out[3]; /* 0x60 */
} KeyHolder;
typedef struct KeyObj {
    u8 pad00[0x1d8];
    KeyHolder* holder;
} KeyObj;
typedef struct KeyStep {
    u8 pad00[0x1c];
    u32 idx;      /* 0x1c */
    f32 to[3];    /* 0x20 */
    f32 from[3];  /* 0x2c */
    s32 ease;     /* 0x38 */
    u32 duration; /* 0x3c */
    u32 count;    /* 0x40 */
} KeyStep;
extern KeyEnt* fn_8009FDA0(KeyAnim* a, u32 idx, s32 b, s32 c, s32 d, s32 e, s32 f);
extern f32 fn_80212A78(s32 type, f32 x, f32 t);
typedef struct PadSlot {
    s32 on;
    u8 pad[0x18];
} PadSlot;
typedef struct PadState {
    u8 pad[0x28];
    PadSlot slot[4]; /* 0x28 */
} PadState;
typedef struct SeqItem {
    s8 type;         /* 0x00 */
    s8 id;           /* 0x01 */
    u8 pad2[0xe];
} SeqItem;
typedef struct SeqRec {
    s16 n;           /* 0x00 item count */
    u8 pad2[0xa];
    s32 xc;
    SeqItem items[8]; /* 0x10 */
} SeqRec;
extern s32 lbl_80347288;
extern s32 lbl_80347044;
extern s32 lbl_80347040;
extern s32 lbl_8034703C;
extern s32 lbl_80347064;
extern s32 lbl_80347060;
extern PadState *lbl_80347050[2];
extern SeqRec lbl_80306E38[2];
extern u8 lbl_80310A1C[0x120];
extern void fn_8015C1E4(void);
extern void fn_80156584(void);
extern void fn_8015983C(s32 on, s32 who, SeqRec *rec, s32 flag);
extern void fn_8012F72C(s32 a);
extern void fn_8012F6F8(s8 idx, s8 val);
extern void fn_8012F710(s8 idx, char *str);
extern void fn_8012F6E0(s8 idx, s8 val);
extern char *fn_80159D48(s32 page, SeqItem *it);
extern s8 fn_80159948(s8 idx, SeqRec *l, SeqItem *it);
typedef struct { char text[0x18]; } MenuLine;
extern MenuLine lbl_80306DD8[];
extern void fn_80159F28(s32 who);
extern void fn_8015A36C(s32 who);
typedef struct A_8015D124 {
    u8 pad[0x50];
    NJS_POINT3 pos;
    u8 pad2[0x168 - 0x5c];
    s16 mode;
} A_8015D124;
typedef struct S_8015D124 {
    u8 pad[8];
    A_8015D124* a;
} S_8015D124;
typedef struct Obj_8015D124 {
    u8 pad[0x1d8];
    S_8015D124* s;
} Obj_8015D124;
typedef struct St_8015D124 {
    u8 pad[0x1c];
    NJS_POINT3 v;
    u32 cnt;
} St_8015D124;

void fn_8014F970(BtlShip *self) {
    fn_80153270(self->fx);
    fn_80155CD8();
    fn_80155D74();
}

s32 fn_8014FC9C(Ctx* c, Ev* e) {
    if (e->fc == 6 && e->f4 == -1 && c->f2d8 == 0) {
        c->f2d8 = 1;
        return 1;
    }
    return 0;
}

void fn_8014FCD8(u8 *base, s32 i, u16 v) {
    u8 *e = base + i * 0xa8;
    *(u16 *)(e + 0x48) = v;
    *(u16 *)(e + 0x4a) = 0;
}

void fn_801515EC(Fx *p) {
    p->init = 0;
}

void fn_801515F8(Fx *p, NJS_POINT3 *a, Angle *b, NJS_POINT3 *c, NJS_POINT3 *d, NJS_POINT3 *e) {
    p->ang = b;
    p->pos = a;
    p->ofs1 = c;
    p->ofs2 = d;
    p->target = e;
}

void fn_801517EC(Fx *p) {
    memcpy(p->ca, p->x04, 0x30);
}

void fn_8015181C(Fx *p) {
    memcpy(p->x04, p->ca, 0x30);
}

void fn_8015271C(Obj_8015259C* o) {
    if (o->x6c != 0) {
        fn_80158374(o->x6c);
        o->x6c = 0;
    }
}

void fn_80152EE8(u8 *p, u32 v) {
    *(u32 *)(p + 0x48) = v;
}

void fn_80152EF0(Obj_8015259C* o)
{
    memset(o, 0, 0x70);
    o->x3c = fn_80156A3C();
    o->x34 = fn_80156A3C();
    o->x50 = fn_80156A3C();
    o->x58 = fn_80156A3C();
    o->x6c = fn_80158394();
}

s32 fn_80152FC4(s32 idx) {
    if (idx > 0x18) {
        fn_8015757C((s32)lbl_802B3B9C, idx);
        idx = 0;
    }
    return lbl_802E6ACC[idx]->f5;
}

s32 fn_80153014(s32 idx) {
    if (idx > 0x18) {
        fn_8015757C((s32)lbl_802B3B9C, idx);
        idx = 0;
    }
    return lbl_802E6ACC[idx]->f0;
}

void fn_80153270(void *p) {
    Obj_80153270* o = p;
    if (o->f0c != 0) {
        fn_8020EF30(o->p4);
        o->f0c = 0;
    }
}

void fn_801532B4(Obj_80153060* p) {
    memset(p, 0, 0x24);
    fn_80155A8C(p->x10);
}

void fn_80153498(void) {
    if (lbl_80306758.f8 != 0) {
        fn_80109A94(lbl_80306758.buf);
    }
    lbl_80306758.f8 = 0;
    lbl_80306758.f0 = 0;
}

void fn_801534E8(void) {
    memset(&lbl_80306758, 0, 0x50);
}

void fn_801536E0(void) {
    if (lbl_80306758.f8 != 0) {
        fn_80109A94(lbl_80306758.buf);
    }
    lbl_80306758.f8 = 0;
    lbl_80306758.f0 = 0;
}

extern void fn_80155FD0(s32);
void fn_80153958(s32 a, s16 i) {
    fn_80155FD0(a);
}

void fn_80153978(void) {
    memcpy(lbl_803067A8, lbl_80306938, 0x190);
    memset(lbl_80306938, 0, 0x190);
}

void fn_801539C0(void) {
}

void fn_801539C4(void) {
}

void fn_801539C8(void) {
}

void fn_801539CC(void) {
}

void fn_801539D0(void) {
    if (lbl_80346FB8 != 0) {
        fn_801E17E0(lbl_80346FB8);

        lbl_80346FB8 = 0;
    }
}

void fn_80153A04(void) {
    void* p = fn_801E1C7C(0x406);
    memset(p, 0, 0x406);
    lbl_80346FB8 = p;
}

u8 fn_80153DA8(s32 i) {
    u8 *b = (u8 *)lbl_80346FB8;
    return (i + b)[4];
}

void fn_80153DB8(s32 i, u8 v) {
    u8 *b = (u8 *)lbl_80346FB8;
    (i + b)[4] = v;
}

void fn_80154B04(void) {
    if (lbl_80346FE0 != 0) {
        fn_801E17E0(lbl_80346FE0);

        lbl_80346FE0 = 0;
    }
}

void fn_801558B0(Src_UNIT0000* s) {
    E14* e = lbl_80346FE8 + s->idx;
    e->a = (void*)s->a;
    e->b = (void*)s->b;
    e->c = (void*)s->c;
    e->d = s->d;
    e->flag = 1;
}

void fn_801558EC(void) {
    fn_801E17E0(lbl_80346FE8);
}

void fn_80155944(void *p) {
    fn_80150CB0(lbl_80346FAC, p);
}

void fn_80155A88(void) {
}

void fn_80155A8C(void *p) {
    memset(p, 0, 0x14);
}

void fn_80155D28(void) {
}

void fn_80155D74(void) {
    St_UNIT0000* o = lbl_80347000;
    if (o->p != 0) {
        fn_80217830(o->p);
        o->p = 0;
    }
}

void fn_80155F5C(void) {
    fn_801E17E0(lbl_80347000);
}

void fn_80155F80(void) {
    St_UNIT0000* s;
    lbl_80347000 = fn_801E1A74(1, 0x90);
    memset(lbl_80347000, 0, 0x90);
    s = lbl_80347000;
    s->b = -1;
    s->a = -1;
    s->c = 0;
}

extern void fn_80216EFC(s32);
void fn_80155FD0(s32 a) {
    fn_80216EFC(a);
}

void fn_80156250(void) {
    lbl_80346FBC = lbl_80346FBC + 1;
    fn_80153978();
    fn_80152284(&lbl_80346FC8[0]->cue);
    fn_80152284(&lbl_80346FC8[1]->cue);
    fn_80154B6C();
    fn_801539C4();
    fn_80153730();
}

void fn_80156324(void) {
    fn_8014F4E8(lbl_80346FC8[0]->ship);
    fn_8014F4E8(lbl_80346FC8[1]->ship);
}

void fn_80156584(void) {
}

s32 fn_80156A3C(void) {
    if (lbl_80347024 >= 0xFDE8) {
        fn_801DBE1C(lbl_802B3F24);
    }
    return (lbl_80347024 += 0x1e) - 0x1e;
}

void fn_80157360(s32 idx) {
    BtlShip *fld = lbl_80346FC8[idx]->ship;
    Lane *p = &fld->lane[0];
    Lane *q = &fld->lane[1];
    s32 i;
    s32 n;
    if (lbl_803472A8 == 0) {
        return;
    }
    n = lbl_803472A8->count;
    for (i = 0; i < n; i++) {
        BtlTrack *e = &lbl_80346FD4->side[idx].ent[i];
        s32 iy;
        s32 ix;
        s32 x;
        s32 y;
        s8 *f = e->f;
        f[0] = 0;
        f[1] = 0;
        f[2] = 0;
        f[3] = 0;
        ix = (e->aim[199][1] << 7) / 0x10000;
        iy = (e->aim[439][1] << 7) / 0x10000;
        if (p->cell[ix + 0x54] == 0) e->f[0] |= 1;
        if (q->cell[ix + 0x54] == 0) e->f[1] |= 1;
        if (p->cell[iy + 0x54] == 0) e->f[2] |= 1;
        if (q->cell[iy + 0x54] == 0) e->f[3] |= 1;
        x = e->aim[199][0];
        y = e->aim[439][0];
        if (x < p->min || x > p->max) e->f[0] |= 1;
        if (x < q->min || x > q->max) e->f[1] = 1;
        if (y < p->min || y > p->max) e->f[2] = 1;
        if (y < q->min || y > q->max) e->f[3] = 1;
    }
}

void fn_80157510(In_80150014* a, f32* b, NJS_POINT3* c) {
    fn_80150014(a, b, c);
}

void fn_80157530(s32 a, s32 b, s32 c) {
    if (lbl_80347008 == 0) {
        lbl_80347008 = (u32)lbl_80306C98;
        sprintf(lbl_80306C98, a, b, c);
    }
}

void fn_8015757C(s32 a, s32 b) {
    if (lbl_80347008 == 0) {
        lbl_80347008 = (u32)lbl_80306C98;
        sprintf(lbl_80306C98, a, b);
    }
}

void fn_801575C0(s32 a) {
}

void fn_80157E54(s32 i, s32 j) {
    memcpy((u8*)lbl_80306B14[i].p + j * 0x58, (u8*)lbl_80308F98[i].p + j * 0x58, 0x58);
}

void fn_80158200(Obj_80158200* o, f32* v, s32* w) {
    o->flag = 1;
    o->pos[0] = v[0];
    o->pos[1] = v[1];
    o->pos[2] = v[2];
    o->ints[0] = w[0];
    o->ints[1] = w[1];
    o->ints[2] = w[2];
}

void fn_8015823C(u8 *p) {
    *(u32 *)(p + 0) = 0;
    *(u16 *)(p + 6) = 0;
    *(u16 *)(p + 4) = 0;
}

typedef struct Obj_80158358 {
    u8 pad0[8];
    u32 x8;                 /* 0x08 */
    u32 xc;                 /* 0x0c */
    void *x10;              /* 0x10 */
    u8 pad14[0x3c - 0x14];
    u32 x3c;                /* 0x3c */
    u32 x40;                /* 0x40 */
    EvTask *x44;            /* 0x44 */
} Obj_80158358;

void fn_80158358(Obj_80158358 *p, void *a, u32 b, u32 c, u32 d, u32 e, EvTask *f) {
    p->x10 = a;
    p->x8 = b;
    p->xc = e;
    p->x3c = c;
    p->x40 = d;
    p->x44 = f;
}

void* fn_80158394(void) {
    void* p = fn_801E1A74(1, 0x54);
    memset(p, 0, 0x54);
    return p;
}

void fn_8015854C(s16 idx, u16 bits) {
    Obj_8015854C* o = lbl_80306DB8[idx];
    if (o == 0) {
        return;
    }
    o->flags |= 0x20000000;
    lbl_80306DB8[idx]->h3e = bits;
    lbl_80306DB8[idx]->h3c |= bits;
}

void fn_80158650(s16 idx, s16 val) {
    u8 *p = (u8 *)lbl_80306DB8[idx];
    if (p == 0) return;
    *(s16 *)(p + 0x12) = val;
    if (val == 9) {
        *(u32 *)lbl_80306DB8[idx] |= 0x02000000;
    }
}

void fn_80158690(s16 idx) {
    u32 *p = (u32 *)lbl_80306DB8[idx];
    if (p == 0) return;
    if (p[0] & 0x40000000) return;
    p[1] = 0;
    *(s16 *)((u8 *)lbl_80306DB8[idx] + 0x3e) = 0;
    *(s16 *)((u8 *)lbl_80306DB8[idx] + 0x3c) = 0;
}

void fn_801584DC(s16 idx, u16 bits, s32 mode);
void fn_80158650(s16 idx, s16 val);
void fn_801583D8(s16 idx, s32 delta);
void fn_80158590(s16 idx, s8 mode, s16 a, s16 b);

typedef struct PartyMem {
    u8 pad0[0x18];
    s32 f18;
    u8 pad1c[0x10c - 0x1c];
} PartyMem;
typedef struct Sys80135598 {
    u8 pad0[0x238];
    PartyMem party;
} Sys80135598;
typedef struct Pad80129D40 {
    void *obj;
    u16 h4;
    u8 pad6[2];
    s32 f8;
    s32 fc;
    s32 f10;
} Pad80129D40;


extern PartyMem *fn_8013558C(void);
extern Sys80135598 *fn_80135598(void);

void fn_80159F28(s32 side) {
    SeqRec *slot = &lbl_80306E38[0];
    SeqRec *sel = &lbl_80306E38[1];
    s32 d;
    s32 idx;
    PartyMem *q;
    Pad80129D40 *p;
    u16 c;
    u16 b;
    u16 a;
    s32 r;
    s32 code;

    if (slot->items[0].id == side) {
        sel = slot;
    }
    c = b = a = 0;
    if (side == 0) {
        d = -sel->xc;
        p = fn_80129D40(lbl_803472AC);
        q = &fn_8013558C()[p->f10];
        r = fn_80145CA4(1, lbl_802E6F58[p->f10], 2);
        if (r) b |= 0x400;
        if (!r) a |= 0x400;
        r = fn_80145CA4(1, lbl_802E6F58[p->f10], 3);
        if (r) b |= 0x200;
        if (!r) a |= 0x200;
        r = fn_80145CA4(1, lbl_802E6F58[p->f10], 8);
        if (r) c |= 0x80;
        if (!r) a |= 0x80;
        r = fn_80145CA4(1, lbl_802E6F58[p->f10], 12);
        if (r) c |= 0x20;
        if (!r) a |= 0x80;
        idx = 1;
    } else {
        d = -sel->xc;
        p = fn_80129D40(lbl_803472B0);
        q = &fn_80135598()->party;
        r = fn_80145CA4(0, 0, 2);
        if (r) b |= 0x400;
        if (!r) a |= 0x400;
        r = fn_80145CA4(0, 0, 3);
        if (r) b |= 0x200;
        if (!r) a |= 0x200;
        r = fn_80145CA4(0, 0, 8);
        if (r) c |= 0x80;
        if (!r) a |= 0x80;
        r = fn_80145CA4(0, 0, 12);
        if (r) c |= 0x20;
        if (!r) a |= 0x20;
        idx = 0;
    }
    if ((p->f8 += d) < 0) {
        p->f8 = 0;
    }
    if (p->f8 <= 0 || q->f18 <= 0) {
        q->f18 = 0;
    }
    if (d >= 0 && c == (p->h4 & 0xa0)) {
        return;
    }
    if (d < 0 && c != (p->h4 & 0xa0)) {
        code = 4;
    } else if (d < 0 && c == (p->h4 & 0xa0)) {
        code = 3;
    } else if (d >= 0 && c != (p->h4 & 0xa0)) {
        code = 5;
    } else {
        code = 1;
    }
    if ((c & 0x80) && (c & 0x80) != (p->h4 & 0x80)) {
        fn_8015854C(idx, 0x80);
        fn_801584DC(idx, a, 0);
        p->h4 &= b;
        p->h4 |= c;
    } else if ((c & 0x20) && (c & 0x20) != (p->h4 & 0x20)) {
        fn_8015854C(idx, 0x20);
        fn_801584DC(idx, a, 0);
        p->h4 &= b;
        p->h4 |= c;
    } else {
        fn_801584DC(idx, a, 0);
        p->h4 &= b;
        p->h4 |= c;
        fn_8015854C(idx, p->h4);
    }
    if (!(lbl_80310B3C[34] & 0x40000000)) {
        fn_80158650(idx, code);
        fn_801583D8(idx, d);
        fn_801586D4(idx);
        fn_80158590(idx, 2, 10, 60);
    }
}

void fn_8015A844(void) {
    s32 i;
    for (i = 0; i < lbl_8034729C; i++) {
        fn_80158690((s16)i);
    }
}

void fn_8015C5F4(void) {
    fn_8015C4D8();
    fn_80144680();
}

extern void fn_80144E60(Msg*, s16);
void fn_8015C618(void) {
    fn_801E17E0(lbl_80347048);
    lbl_80347048 = NULL;
}

void fn_8015C6A8(Msg* a, s16 i) {
    fn_80144E60(a, i);
}

void fn_8015C6C8(void) {
    lbl_8034704C = 0;
    fn_801453D0();
}

s32 fn_8015C6F0(Obj_8015C6F0_UNIT0000 *p) {
    if (p && p->x1d8 && p->x1d8->x8) {
        fn_80167690(p->x1d8->x8);
        return 1;
    }
    return 0;
}

s32 fn_8015C73C(Obj_8015C6F0_UNIT0000 *p) {
    if (p && p->x1d8 && p->x1d8->x8) {
        fn_801E5E2C(p->x1d8->x8);
        return 1;
    }
    return 0;
}

s32 fn_8015C788(Obj_8015C6F0_UNIT0000 *p) {
    if (p && p->x1d8 && p->x1d8->x8) {
        fn_801E5E54(p->x1d8->x8);
        return 1;
    }
    return 0;
}

s32 fn_8015C7D4(Obj_8015C6F0_UNIT0000 *p) {
    if (p && p->x1d8 && p->x1d8->x8) {
        fn_801E5DF0(p->x1d8->x8);
        return 1;
    }
    return 0;
}

s32 fn_8015C820(Obj_8015C6F0_UNIT0000 *p) {
    if (p && p->x1d8 && p->x1d8->x8) {
        fn_801E5E7C(p->x1d8->x8);
        return 1;
    }
    return 0;
}

s32 fn_8015C86C(Obj_8015C6F0_UNIT0000 *p) {
    if (p && p->x1d8 && p->x1d8->x8) {
        fn_801E66E0(p->x1d8->x8);
        return 1;
    }
    return 0;
}

void fn_8015C8B8(Obj_8015C8B8_UNIT0000 *obj, s32 idx) {
    Sub_UNIT0000 *s = obj->x1d8;
    u32 v;
    if (s == 0) return;
    if (idx >= 6) return;
    if (idx < 0) {
        v = 0;
    } else {
        v = lbl_802E7090[idx];
    }
    s->f260 = v;
}

s32 fn_8015CF8C(u8 *p, u8 *q) {
    u32 v = *(u32 *)(q + 0x1c);
    u8 *dst = *(u8 **)(p + 0x1d8);
    *(u16 *)(dst + 0x18) = v;
    return 0;
}

s32 fn_8015D464(Obj_8015D234 *o, St_8015D234 *a) {
    S_8015D234 *h = o->s;
    A_8015D234 *s = h->a;
    h->flags |= 0x100;
    if (a->cnt == 0) {
        s->f1c = -1.0f;
        return 0;
    }
    switch (s->mode) {
    case 0:
        fn_80167374(o);
        fn_80222964(s->h1bc);
        s->h1bc = 0;
        s->mode = 1;
    case 1:
        s->f1c = s->f1c - 1.0f / a->cnt;
        if (s->f1c < -1.0f) {
            s->f1c = -1.0f;
            return 0;
        }
    }
    return 1;
}

s32 fn_8015D688(void *unused, u8 *q) {
    s32 v = *(s32 *)(q + 0x1c) - 1;
    *(s32 *)(q + 0x1c) = v;
    return v != 0;
}

s32 fn_8015DC54(u8 *p) {
    u32 *flags = *(u32 **)(p + 0x1d8);
    *flags &= ~0x80;
    return 0;
}

void fn_8014FD9C(void)
{
    void *r31;
    fn_801E17E0(lbl_80346FA0);
    fn_801E17E0(lbl_80346FA4);
    fn_801E17E0(lbl_80346FA8);
    r31 = lbl_80346FAC;
    fn_801E17E0(lbl_80346F9C);
    fn_801E17E0(r31);
    fn_801E17E0(lbl_80346FB0);
    fn_801E17E0(lbl_80346FB4);
}

void fn_80150258(void)
{
    memset((void*)lbl_80346FA0, 0, 0x1616);
    fn_80150A80((u8 *)lbl_80346FA8);
    fn_8014F72C(lbl_80346FC8[0]->ship->x9c0, 0);
    fn_8014F72C(lbl_80346FC8[1]->ship->x9c0, 1);
}

typedef struct {
    s16 a;
    s16 b;
    s16 c;
    s16 d;
    s16 e;
} Row_801523A4;

extern Row_801523A4 lbl_802E5F28[];

extern void fn_80154C34(s32 val, s32 delay);
extern s32 fn_80155FF0(s32, s32, s32, s32);
extern void fn_801677D0(u32 id, s32 x, f32 f1, f32 f2, f32 f3, f32 f4, s8 k, s32 w);

static inline s32 Play_80152284(s32 bank, s32 id, s32 v, s32 n, s32 b)
{
    s32 h = fn_80155FF0(7, id, bank, 0);
    f32 time = n;
    f32 scale = lbl_802E5F28[id].b;
    fn_801677D0(h, lbl_802E5F28[id].a + 0x1c + v, 0.0f, 0.0f, 0.0f,
                time * scale / 1000.0f, lbl_802E5F28[id].c, b);
    fn_80154C34(lbl_802E5F28[id].d, lbl_802E5F28[id].e);
    return h;
}

void fn_80152284(void *p)
{
    BtlCue *s = p;
    if (s->x4 == 1 && s->x18 != 0 && s->x1c != 0) {
        fn_80155FD0(s->x24);
        s->x24 = Play_80152284(0xf, s->xc, s->x10, s->x14, s->x8);
        s->x20 = 1;
        s->x18 = 0;
    }
}

static inline s32 Play_801523A4(BtlCue *o, s32 a, s32 b, s32 c)
{
    s32 x8 = o->x8;
    s32 id = fn_80155FF0(7, a, 0, 0);
    fn_801677D0(id, lbl_802E5F28[a].a + 0x1C + b, 0.0f, 0.0f, 0.0f,
                (f32)c * (f32)lbl_802E5F28[a].b / 1000.0f, lbl_802E5F28[a].c, x8);
    fn_80154C34(lbl_802E5F28[a].d, lbl_802E5F28[a].e);
    o->x20 = 1;
    o->x24 = id;
    return id;
}

s32 fn_801523A4(void *p, s32 flag, s32 a, s32 b, s32 c)
{
    BtlCue *o = p;
    s32 ret = 0;

    if (o->x4 == 0) {
        if (flag != 0) {
            if (o->x20 == 0) {
                ret = Play_801523A4(o, a, b, c);
            }
        } else {
            o->x20 = 0;
            fn_80155FD0(o->x24);
        }
    }
    if (o->x4 == 1) {
        if (flag != 0) {
            if (o->x20 == 0) {
                o->xc = a;
                o->x10 = b;
                o->x14 = c;
                o->x1c = 1;
                o->x20 = 0;
            }
        } else {
            o->xc = 0;
            o->x10 = 0;
            o->x14 = 0;
            o->x1c = 0;
            o->x20 = 0;
            fn_80155FD0(o->x24);
        }
        o->x18 = 0;
    }
    return ret;
}

void fn_80152538(void* dst, s32 a, s32 b, s32 c)
{
    s32* d;
    memset(dst, 0, 0x28);
    d = (s32*)dst;
    d[0] = a;
    d[1] = b;
    d[2] = c;
}

void fn_8015259C(Obj_8015259C* o)
{
    memset(o, 0, 0x70);
    o->x3c = fn_80156A3C();
    o->x34 = fn_80156A3C();
    o->x50 = fn_80156A3C();
    o->x58 = fn_80156A3C();
    o->x6c = fn_80158394();
}

void fn_801526C4(void *a, s32 b, s32 c) {
    fn_80152B58(a, 0, 1, b, 0, c, 0, 0x891C, 0x76C0, 0, 0, 0);
}

void fn_80152AFC(Obj_80152AFC_UNIT0000 *o) {
    if (o->p6c != 0) {
        fn_8015823C(o->p6c);
    }
    if (o->p28 != 0) {
        o->p28->p24->f1ec = 0;
        o->p28->p24->f1ef = 0;
    }
}

void fn_80152F4C(s32 idx, s32 a, s32 b) {
    if (idx != -1) {
        if (idx > 0x18) {
            fn_8015757C((s32)lbl_802B3B80, idx);
            idx = 0;
        }
        fn_80153790(lbl_802E6ACC[idx]->f0, a, b);
    }
}

s32 fn_801533C4(s32 idx) {
    E40 *e;
    s32 r = 0;
    if (idx > 0x1a) {
        fn_8015757C((s32)lbl_802B3BB8, idx);
        return 0;
    }
    e = lbl_802E6A40[idx];
    if ((s8)e->b4 != 0) {
        r = e->f0;
    }
    return r;
}

s32 fn_80153428(s32 idx, s32 sub) {
    if (idx > 0x1a) {
        fn_8015757C((s32)lbl_802B3BB8, idx);
        return 0;
    }
    if (idx == 4) {
        return *lbl_802E6AB0[sub];
    }
    return lbl_802E6A40[idx]->f0;
}

void fn_80155848(s32 idx) {
    E14 *e = &lbl_80346FE8[idx];
    if (e->flag != 0) {
        fn_8014836C(0, e->a);
        fn_8014836C((u16)e->d, e->b);
        fn_80148228(0x7fffffff, e->c);
    }
}

void fn_801562A4(s32 unused, f32 *v) {
    fn_801523A4(&lbl_80346FC8[(s32)v[0]]->cue, (s32)v[1], (s32)v[2], (s32)v[3], (s32)v[4]);
}

s32 fn_80156A8C(s32 x) {
    s32 i;
    for (i = 0; i < lbl_8034729C; i++) {
        if (x == lbl_80308EF8[i].p0->p24->h17a) {
            return i;
        }
    }
    fn_801DBE1C(lbl_802B3F38, x);
    return -1;
}

void fn_801584DC(s16 idx, u16 bits, s32 mode) {
    if (lbl_80306DB8[idx] == 0) {
        return;
    }
    if (mode == 1) {
        bits &= lbl_80306DB8[idx]->h3c;
        if ((u16)bits == 0) {
            return;
        }
        lbl_80306DB8[idx]->h40 |= bits;
        lbl_80306DB8[idx]->h6c = 0xff;
        lbl_80306DB8[idx]->flags |= 0x08000000;
    } else {
        lbl_80306DB8[idx]->h3c &= ~bits;
    }
}

void fn_8015AA18(void) {
    if (lbl_803472A8 == 0 || 0.0f == lbl_803472DC) {
        if (fn_8010CED4() == 1) {
            fn_8012F72C(1);
        }
    } else {
        if (fn_8015BB58((s32)lbl_803472E0) != 0) {
            fn_8015B358();
        }
    }
}

s32 fn_8015AA88(u32 x) {
    s32 r = -1;
    if (x == 0x1e4) {
        r = 0x17;
    } else if (x == 0x1e5) {
        r = 0x1a;
    } else if (x == 0x1e6) {
        r = 0x2;
    } else if (x == 0x1e7) {
        r = 0x20;
    } else if (x == 0x1e8) {
        r = 0x4;
    } else if (x == 0x1e9) {
        r = 0x14;
    }
    return r;
}

s32 fn_8015AAF0(s32 x) {
    s32 r = 1;
    if (x == 6) {
        r = 7;
    } else if (x == 7) {
        r = 8;
    } else if (x == 8) {
        r = 9;
    } else if (x == 9) {
        r = 10;
    } else if (x == 0) {
        r = 11;
    } else if (x == 1) {
        r = 12;
    } else if (x == 0xd) {
        r = 13;
    }
    return r;
}

void fn_8015C644(void) {
    u8 buf[0x20];
    sprintf(buf, lbl_802B4104, lbl_8034746C, lbl_80311AC0.f4, lbl_80311AC0.f8);
    if (fn_801CC62C(buf) == 1) {
        lbl_80347048 = fn_801CC3C4(buf);
    }
}

s32 fn_8015DBE4(Self *self, Src_8015DBE4 *src) {
    State *st = self->p1d8;
    Blk *b;
    st->h1e = src->f1c;
    if (st->b78.a == 0) {
        b = fn_8016748C(self, (u32)self->p1c8->p20->p0);
        if (b != 0) {
            st->b78 = *b;
        }
    }
    return 0;
}

void fn_8014FCF0(BtlShip *dst, s32 a, s32 b)
{
    s32 i;
    u8 *x = (u8 *)fn_8010A164(a);
    u8 *y = AT(u8 *, x, 0x24);

    memset(dst, 0, 0xa00);
    dst->x0 = x;
    dst->x4 = y;
    dst->x8 = AT(u32, y, 0x1e4);
    dst->xc = fn_80129CA8(y);
    dst->idx = b;
    for (i = 0; i < 2; i++) {
        fn_801532B4(&dst->fx[i]);
    }
    dst->x9a4 = 0;
}

void fn_80150A80(u8 *p)
{
    memset(p, 0, 0x6c);
    AT(u8 *, p, 0x38) = lbl_80346FC8[0]->ship->x9c0;
    AT(s32, p, 0x20) = 0;
    AT(u8 *, p, 0x54) = lbl_80346FC8[1]->ship->x9c0;
    AT(s32, p, 0x3c) = 1;
    AT(s32, p, 0x1c) = 0;
    AT(s32, p, 0) = -1;
    AT(s32, p, 0x24) = 6;
    AT(s32, p, 0x28) = 0;
    AT(s32, p, 0x2c) = 0;
    AT(s32, p, 0x40) = 6;
    AT(s32, p, 0x44) = 0;
    AT(s32, p, 0x48) = 0;
    AT(s32, p, 4) = -1;
    AT(s32, p, 8) = 0;
    AT(s32, p, 0xc) = 0;
    AT(s32, p, 0x64) = 0;
    AT(s32, p, 0x68) = 0;
}

s32 fn_801531DC(u8 *obj, void *ptr)
{
    void *r;

    if (ptr != 0) {
        if (AT(u32, obj, 0xc) != 0) {
            fn_8020EF30(AT(void *, obj, 4));
            AT(s32, obj, 0xc) = 0;
        }
        r = fn_8010A164((s32)ptr);
        if (r != 0) {
            AT(void *, obj, 0xc) = r;
            AT(void *, obj, 4) = ptr;
            fn_8020EFD4(AT(void *, obj, 4));
            AT(s32, obj, 8) = 0x78;
        } else {
            fn_801575C4(ptr);
            return 0;
        }
    }
    return 1;
}

void fn_80153324(s32 idx, s32 *pa, s32 *pb, s32 *pc)
{
    if (idx > 0x1a) {
        fn_8015757C((s32)lbl_802B3BB8, idx);
    }
    *pa = AT(s8, lbl_802E6A40[idx], 5);
    *pb = AT(s8, lbl_802E6A40[idx], 6);
    *pc = AT(s8, lbl_802E6A40[idx], 0xa);
}

void fn_80154C34(s32 val, s32 delay)
{
    Seq_80346FE0 *g = lbl_80346FE0;
    Slot_80154C34 *s;
    s32 i;
    u32 cnt;

    if (g == 0) {
        return;
    }
    s = g->pend;
    for (i = 0; i < 10; i++) {
        if (s->active == 0) {
            if (val >= 0x48) {
                val = 1;
            }
            if (val <= 0) {
                s->active = 0;
                return;
            }
            s->active = 1;
            s->id = (s16)val;
            cnt = lbl_80346FE0->x10;
            if (cnt != 0) {
                s->timer = (s16)(cnt + delay);
            } else {
                s->timer = (s16)delay;
            }
            lbl_80346FE0->x10 = lbl_80346FE0->x10 + 1;
            return;
        }
        s++;
    }
}

u32 fn_80155AB4(s32 id)
{
    s32 n;
    Ent_80155AB4 *e = &lbl_80346FF8[lbl_80346FF0];

    if (e->id != id) {
        fn_8015757C((s32)lbl_802B3E84, id);
        return 0;
    }
    if (e->p != 0) {
        if (fn_80215F8C(e->p) == 0) {
            fn_80217830(e->p);
            fn_8015757C((s32)lbl_802B3EA4, id);
            return 0;
        }
        fn_80215F94(e->p);
    }
    n = lbl_80346FF0 + 1;
    lbl_80346FF0 = n;
    if (n >= 1) {
        lbl_80346FF0 = 0;
    }
    return e->p;
}

s32 fn_80155DB4(s32 id, s32 v)
{
    u8 *st = (u8 *)lbl_80347000;

    if (AT(s32, st, 0) != id) {
        fn_80157530((s32)lbl_802B3EDC, id, v);
        return 0;
    }
    if (AT(s32, st, 8) != 0) {
        if (fn_80216CA4(st + 0x10) != 0) {
            AT(s32, st, 8) = 0;
        } else {
            return 0;
        }
    }
    AT(s32, st, 0xc) = fn_80216F1C((s8)id, (s8)v);
    return AT(s32, st, 0xc);
}

void fn_801566B4(s32 a, void *p4, void *p5)
{
    if (lbl_80346FC8[a]->m14 != 0) {
        memcpy(lbl_80346FC8[a]->m1c, lbl_80346FC8[a]->m14, 0x40);
        memcpy(lbl_80346FC8[a]->m5c, lbl_80346FC8[a]->m18, 0x40);
    } else {
        memcpy(lbl_80346FC8[a]->m1c, p4, 0x40);
        memcpy(lbl_80346FC8[a]->m5c, p5, 0x40);
    }
    lbl_80346FC8[a]->m14 = p4;
    lbl_80346FC8[a]->m18 = p5;
}

void fn_80156994(s32 a, EvObj *obj, BtlShip *b, void (*c)(EvObj *))
{
    void *r29 = fn_8010A164(obj->x17a);

    lbl_80346FC8[a]->task = r29;
    lbl_80346FC8[a]->obj = obj;
    lbl_80346FC8[a]->cb = c;
    lbl_80346FC8[a]->xc = fn_80129CA8(obj);
    lbl_80346FC8[a]->ship = b;
    fn_8014FCF0(b, obj->x17a, a);
    fn_80152538(&lbl_80346FC8[a]->cue, a, fn_80129CA8(obj), (s32)r29);
}

void fn_80156DA0(Obj80156DA0* self, void* m) {
    if (self->model == 0 || self->scale <= lbl_8034A900 || self->hidden != 0) {
        return;
    }
    if (self->texlist != 0) {
        fn_80299040(self->texlist);
    }
    njPushMatrixEx();
    fn_80286EE8();
    fn_8028B498();
    fn_802974E0(self->pos);
    fn_801E4FD4(self);
    njMultiMatrix(0, m);
    fn_801E4CB0(self->flags176, self->model);
    DrawStatePop(0);
    njPopMatrixEx();
}

u8 fn_80159020(void *p) {
    Obj80159020* self = p;
    Obj_8015854C* in = self->inner;
    Entry80159020* e;
    u8 r;
    if (in->h12 != 9) {
        r = fn_801590F4(in, 1);
        if (in->h12 == 5 || in->h12 == 3 || in->h12 == 7 || in->h12 == 10) {
            return 0;
        }
        if (r != 0) {
            e = (Entry80159020 *)lbl_80306DB8[in->h10];
            if (e != 0) {
                e->value = lbl_8034A95C;
            }
        } else {
            e = (Entry80159020 *)lbl_80306DB8[in->h10];
            if (e != 0) {
                e->value = lbl_8034A940;
            }
        }
        return r;
    }
    fn_801590F4(in, 0);
    return 0;
}

u8 fn_801590F4(Obj_8015854C *o, s32 mode) {
    Slot_8015854C *s;
    s32 extra;
    u16 m;
    u8 n;
    u8 i;

    s = o->slot;
    extra = 0;
    n = 0;
    if (mode != 0) {
        if (o->h12 != 4 && o->h12 != 5) {
            m = o->h3c;
        } else {
            m = o->h3e;
            if (m != 0) {
                extra = 1;
            }
        }
    if (m & 0x1) {
        s[n].id = 0;
        if (o->h40 & 0x1) {
            s[n].v22 = o->h6c;
            s[n].mode = 2;
        } else {
            s[n].v22 = 0xff;
            s[n].mode = extra;
        }
        n++;
        if (n >= 8) {
            return 8;
        }
    }
    if (m & 0x2) {
        s[n].id = 1;
        if (o->h40 & 0x2) {
            s[n].v22 = o->h6c;
            s[n].mode = 2;
        } else {
            s[n].v22 = 0xff;
            s[n].mode = extra;
        }
        n++;
        if (n >= 8) {
            return 8;
        }
    }
    if (m & 0x4) {
        s[n].id = 2;
        if (o->h40 & 0x4) {
            s[n].v22 = o->h6c;
            s[n].mode = 2;
        } else {
            s[n].v22 = 0xff;
            s[n].mode = extra;
        }
        n++;
        if (n >= 8) {
            return 8;
        }
    }
    if (m & 0x8) {
        s[n].id = 3;
        if (o->h40 & 0x8) {
            s[n].v22 = o->h6c;
            s[n].mode = 2;
        } else {
            s[n].v22 = 0xff;
            s[n].mode = extra;
        }
        n++;
        if (n >= 8) {
            return 8;
        }
    }
    if (m & 0x10) {
        s[n].id = 4;
        if (o->h40 & 0x10) {
            s[n].v22 = o->h6c;
            s[n].mode = 2;
        } else {
            s[n].v22 = 0xff;
            s[n].mode = extra;
        }
        n++;
        if (n >= 8) {
            return 8;
        }
    }
    if (m & 0x20) {
        s[n].id = 5;
        if (o->h40 & 0x20) {
            s[n].v22 = o->h6c;
            s[n].mode = 2;
        } else {
            s[n].v22 = 0xff;
            s[n].mode = extra;
        }
        n++;
        if (n >= 8) {
            return 8;
        }
    }
    if (m & 0x40) {
        s[n].id = 6;
        if (o->h40 & 0x40) {
            s[n].v22 = o->h6c;
            s[n].mode = 2;
        } else {
            s[n].v22 = 0xff;
            s[n].mode = extra;
        }
        n++;
        if (n >= 8) {
            return 8;
        }
    }
    if (m & 0x80) {
        s[n].id = 7;
        if (o->h40 & 0x80) {
            s[n].v22 = o->h6c;
            s[n].mode = 2;
        } else {
            s[n].v22 = 0xff;
            s[n].mode = extra;
        }
        n++;
        if (n >= 8) {
            return 8;
        }
    }
    if (m & 0x100) {
        s[n].id = 8;
        if (o->h40 & 0x100) {
            s[n].v22 = o->h6c;
            s[n].mode = 2;
        } else {
            s[n].v22 = 0xff;
            s[n].mode = extra;
        }
        n++;
        if (n >= 8) {
            return 8;
        }
    }
    if (m & 0x200) {
        s[n].id = 9;
        if (o->h40 & 0x200) {
            s[n].v22 = o->h6c;
            s[n].mode = 2;
        } else {
            s[n].v22 = 0xff;
            s[n].mode = extra;
        }
        n++;
        if (n >= 8) {
            return 8;
        }
    }
    if (m & 0x400) {
        s[n].id = 10;
        if (o->h40 & 0x400) {
            s[n].v22 = o->h6c;
            s[n].mode = 2;
        } else {
            s[n].v22 = 0xff;
            s[n].mode = extra;
        }
        n++;
        if (n >= 8) {
            return 8;
        }
    }
    } else {
        s[0].id = 0xb;
        s[0].v22 = 0xff;
        s[0].mode = 3;
        n = 1;
    }
    for (i = n; i < 8; i++) {
        s[i].id = -1;
    }
    if (o->h6c <= 0) {
        o->h40 = 0;
    }
    return n;
}

void fn_8015A780(s32 flag) {
    u8 v;
    u16 bits = 0;
    s32 idx;
    void* p;
    idx = lbl_803472B4;
    if (flag == 0) {
        v = lbl_8034727C[idx * 0x3e + 0x50];
    } else {
        v = lbl_8034727C[idx * 0x3e + 0x68];
    }
    if (flag == 0) {
        p = fn_80129D40(lbl_803472B0);
    } else {
        p = fn_80129D40(lbl_803472AC);
    }
    if ((s8)v & 0x2) {
        bits |= 0x400;
    }
    if ((s8)v & 0x1) {
        bits |= 0x200;
    }
    if ((s8)v & 0x4) {
        bits |= 0x80;
    }
    if ((s8)v & 0x8) {
        bits |= 0x20;
    }
    *(u16*)((u8*)p + 0x4) = bits;
}

void fn_8014FA10(Obj_8014FA10 *o) {
    Obj_8014FA10 *p;
    s32 i = 0;
    s32 z = 0;
    o->x20 = z;
    p = o;
    o->x18 = z;
    o->x1c = z;
    o->x22 = z;
    o->x3e = z;
    o->x3c = z;
    o->x3a = z;
    o->x38 = lbl_803472C0;
    o->xe6 = z;
    o->xe4 = z;
    o->xe2 = z;
    o->xe0 = lbl_803472C0;
    o->x18e = z;
    o->x18c = z;
    o->x18a = z;
    o->x188 = lbl_803472C0;
    o->x236 = z;
    o->x234 = z;
    o->x232 = z;
    o->x230 = lbl_803472C0;
    o->x194 = z;
    o->x23c = z;
    do {
        p->x44 = fn_8014FB58(o, i);
        i++;
        p = (Obj_8014FA10 *)((u8 *)p + 0xa8);
    } while (i < 2);
    memset(o->buf, 0, 0x680);
    o->x9a8 = 0;
    o->x9ac = 0;
    o->x9b0 = 0;
    o->x9b4 = -1;
    o->x9b8 = 0;
    o->x9bc = 0;
    o->x2d8 = 0;
    o->x26 = 0;
    o->x28 = -1;
    if (o != NULL) {
        if (o->x8 != NULL) {
            Sub10_8014FA10 *s = o->x8->x10;
            if (s != NULL) {
                Inner_8014FA10 *n = s->x24->x1e4;
                n->x28 = 0;
                n->x44 = 0;
                n->x60 = 0;
                n->x7c = 0;
            }
        }
    }
    o->x9f0 = 1;
}

s32 fn_8014FB58(void *p, s32 which) {
    Pl *pl = p;
    s16 a = pl->xe;
    u8 *p1 = lbl_80346FD0 + lbl_803472BC * 16 + a * 8 + lbl_80346FC0 * 2;
    s8 *p2 = lbl_80346FD4->side[a].ent[lbl_80346FC0].f;
    s32 flag = lbl_803472B8;
    s32 r = 0;

    if (a != 0) flag ^= 1;
    if (flag == 0) {
        if (which == 0 && (p1[0] & 2)) r |= 1;
        if (which == 1 && (p1[0] & 1)) r |= 2;
    } else {
        if (which == 0 && (p1[1] & 2)) r |= 1;
        if (which == 1 && (p1[1] & 1)) r |= 2;
    }
    if (flag == 0) {
        if (which == 0 && p2[0]) r |= 1;
        if (which == 1 && p2[1]) r |= 2;
    } else {
        if (which == 0 && p2[2]) r |= 1;
        if (which == 1 && p2[3]) r |= 2;
    }
    return r;
}

void fn_80150CB0(void *p, void *q) {
    u8 *base = p;
    s32 *s = q;
    s16 *d = (s16 *)(base + s[0] * 0xc80 + s[1] * 0x320 + s[2] * 0x190 + s[3] * 0x32);
    d[0x00 / 2] = s[4];
    d[0x02 / 2] = s[5];
    d[0x04 / 2] = s[5];
    d[0x06 / 2] = s[6];
    d[0x08 / 2] = s[7];
    d[0x2a / 2] = s[8];
    d[0x2c / 2] = s[9];
    d[0x0a / 2] = s[10];
    d[0x0c / 2] = s[11];
    d[0x0e / 2] = s[12];
    d[0x10 / 2] = s[13];
    d[0x12 / 2] = s[14];
    d[0x14 / 2] = s[14];
    d[0x16 / 2] = s[15];
    d[0x18 / 2] = s[15];
    d[0x1a / 2] = s[16];
    d[0x1c / 2] = s[17];
    d[0x2e / 2] = s[18];
    d[0x30 / 2] = s[19];
    d[0x1e / 2] = s[20];
    d[0x20 / 2] = s[21];
    d[0x22 / 2] = s[22];
    d[0x24 / 2] = s[23];
    d[0x26 / 2] = s[24];
    d[0x28 / 2] = s[24];
}

void fn_801514C4(Fx *o, s32 flag) {
    fn_8015184C(o);
    if (flag != 0) {
        o->ca[0] += o->cb[0];
        o->ca[1] += o->cb[1];
        o->ca[2] += o->cb[2];
        o->ca[3] += o->cb[3];
        o->ca[4] += o->cb[4];
        o->ca[5] += o->cb[5];
        o->ca[6] += o->cb[6];
        o->ca[7] += o->cb[7];
        o->ca[8] *= 1.0 + o->cb[8] - 1.0;
        o->ca[9] += o->cb[9];
        o->ca[10] += o->cb[10];
        o->ca[11] *= 1.0 + o->cb[11] - 1.0;
        fn_80151610(o, 0);
    }
}

void fn_801540D0(s32 which, s32 type, s32 idx, EvObj *val, f32 a, f32 b)
{
    BtlSlot *e;
    if (type != 2) {
        idx &= 7;
    }
    switch (type) {
    case 0:
        e = &lbl_80346FC8[which]->lead;
        break;
    case 1:
        e = &lbl_80346FC8[which]->c[idx];
        break;
    case 2:
        idx &= 0x1f;
        e = &lbl_80346FC8[which]->b[idx];
        break;
    case 3:
        e = &lbl_80346FC8[which]->d[idx];
        break;
    }
    e->type = type;
    e->idx = idx;
    e->b = b;
    e->a = a;
    e->target = val;
    if (type == 2 && idx < 8) {
        BtlSide *b2 = lbl_80346FC8[which];
        BtlSide *b3 = lbl_80346FC8[which];
        b2->a[idx] = b3->b[idx];
    }
}

void fn_80155E60(s32 a, s32 b)
{
    char buf[20] = "/SOUND/F3000012.mlt";
    St_UNIT0000 *s = lbl_80347000;
    if (s->a != a || s->b != b) {
        s->a = a;
        s->b = b;
        buf[8] = a + '0';
        buf[13] = b % 100 / 10 + '0';
        buf[14] = b % 10 + '0';
        fn_80216CB4(buf);
        strcpy(s->name, buf);
        s->c = 1;
    }
}

void fn_80156588(void)
{
    s32 j;
    s32 m;
    s32 i;
    s32 n;
    if (fn_80153BBC() == 1) {
        fn_801541D8(0);
        fn_801541D8(1);
        if (lbl_803472A8 != 0) {
            n = lbl_803472A8->count;
            for (i = 0; i < n; i++) {
                fn_801577CC(lbl_80346FD4, 0, 1, i);
            }
        }
        if (lbl_803472A8 != 0) {
            m = lbl_803472A8->count;
            for (j = 0; j < m; j++) {
                fn_801577CC(lbl_80346FD4, 1, 0, j);
            }
        }
    }
    lbl_80346FC4 = (s32)lbl_803472E0;
    lbl_80346FC0 = lbl_803472C0 % lbl_803472D0;
    if (lbl_80346FC8[0]->cb != 0) {
        lbl_80346FC8[0]->cb(lbl_80346FC8[0]->obj);
    }
    if (lbl_80346FC8[1]->cb != 0) {
        lbl_80346FC8[1]->cb(lbl_80346FC8[1]->obj);
    }
    fn_80150258();
    fn_80154404();
    fn_801539C8();
}

void fn_801575C8(Rec_80125820 *out, s32 b, f64 t)
{
    Rec_80125820 next;
    Angle ang[3];
    f32 v[3];

    fn_80157684(out, b, t);
    fn_80157684(&next, b, t + 1.0);
    v[0] = out->pos[0] - next.pos[0];
    v[1] = out->pos[1] - next.pos[1];
    v[2] = out->pos[2] - next.pos[2];
    fn_801580A4(ang, v);
    out->v[0] = ang[0];
    out->v[1] = ang[1];
    out->v[2] = ang[2];
}

void fn_80157684(Rec_80125820 *out, s32 a, f32 t)
{
    BtlTracks *base = lbl_80346FD4;
    f32 f = t + (120.0f + (lbl_803472E0 - (f32)lbl_80346FC4));
    if (base != 0 && base->ready != 0) {
        Rec_80157684 *src = &base->side[a].ent[lbl_80346FC0].rec[(s32)f];
        out->pos[0] = src->pos[0];
        out->pos[1] = src->pos[1];
        out->pos[2] = src->pos[2];
        out->v[0] = (s32)(f32)src->v[0];
        out->v[1] = (s32)(f32)src->v[1];
        out->v[2] = (s32)(f32)src->v[2];
    } else {
        out->pos[0] = 0.0f;
        out->pos[1] = 0.0f;
        out->pos[2] = 0.0f;
        out->v[0] = 0;
        out->v[1] = 0;
        out->v[2] = 0;
    }
}

void fn_80158250(Obj_80158250 *o)
{
    Dst *d = o->dst;
    Ent_80158250 *e;
    o->h4 = 0;
    if (o->f0 == 0) return;
    e = (Ent_80158250 *)(o->tbl + o->idx * 0x1c + 0x14);
    if (e->f10 == 0) return;
    if (o->p44->p24->b1ef == 0) return;
    if (o->h6 != 0) return;
    o->h6 = 1;
    o->h4 = 1;
    if (e->f4 == -1) {
        d->h8 |= 1;
        if (e->fc >= 0 && e->fc <= 6) {
            d->f0 = d->f0 > e->fc ? d->f0 : e->fc;
            if (o->p44->p24->h230 != 0) {
                d->f4 = o->f40;
            } else {
                d->f4 = o->f3c;
            }
        }
        d->ha = 1;
    } else {
        d->h8 |= 1;
        if (d->he == 0) {
            d->hc = 1;
            d->f10 = e->f4;
        }
        d->he = 1;
    }
}

void fn_801583D8(s16 idx, s32 delta)
{
    s32 cur;
    if (lbl_80306DB8[idx] == 0) {
        return;
    }
    if (delta == 0) {
        lbl_80306DB8[idx]->h1ee = 0;
    } else if (delta < 0) {
        lbl_80306DB8[idx]->h1ee = 1;
    } else if (delta > 0) {
        lbl_80306DB8[idx]->h1ee = 2;
    }
    lbl_80306DB8[idx]->f34 = delta + lbl_80306DB8[idx]->f28;
    cur = lbl_80306DB8[idx]->f34;
    if (cur >= lbl_80306DB8[idx]->f2c) {
        lbl_80306DB8[idx]->f34 = lbl_80306DB8[idx]->f2c;
    } else if (cur <= 0) {
        lbl_80306DB8[idx]->f34 = 0;
    }
    lbl_80306DB8[idx]->f14 = (s32)fabsf((f32)delta);
    switch (lbl_80306DB8[idx]->h12) {
    case 5:
    case 7:
    case 9:
        lbl_80306DB8[idx]->flags |= 0x800000;
        break;
    case 3:
    case 4:
    case 6:
    case 8:
    case 10:
        break;
    }
}

void fn_8015887C(Obj_8015887C *o)
{
    Sub_8015887C *s = o->s;
    s32 f = 1;
    if (lbl_8034702C == 0) {
        f = 0;
    }
    if (s->flags & 0x200000) {
        s->h1fc--;
        if (s->h1fc < 0) {
            s->flags &= 0xC01FFFFF;
        }
    }
    if (f) {
        fn_80159020(o);
    }
    if (s->h10 == 0) {
        s->f88 = 42.0f;
        s->f8c = 114.0f;
    } else {
        s->f88 = 502.0f;
        s->f8c = (f32)(s->h10 * 0x28 + 0x4a);
    }
    if (f) {
        fn_80158DB4(o);
    }
    if (s->f4 == 1) {
        fn_80158BE8(o);
        s->f1e8 = s->fc;
        if (f) {
            s->f98 = s->f74;
            s->h1ec = s->h72;
            fn_8021C62C(s, lbl_80347034, s->h12);
            fn_80159610(s);
        }
    }
}

void fn_801589BC(Obj_8015887C *t)
{
    Sub_8015887C *w = t->s;

    switch (t->state) {
    case 0:
        if (w->f74 != NULL) {
            fn_80227810(w->f74);
        }
        t->state = 1;
    case 1:
        fn_8015887C(t);
        break;
    case 2:
        if (w->f74 != NULL) {
            fn_802275A4(w->f74, 1);
        }
        t->state = 3;
    case 3:
        {
            s16 i = w->h10;
            t->flags |= 0x40;
            lbl_80306D98[i] = NULL;
        }
        break;
    }
}

void fn_80158A80(void)
{
    s32 i;
    lbl_8034702C = 0;
    lbl_80347034 = 0;
    fn_8012F744();
    for (i = 0; i < 8; i++) {
        if (lbl_80306D98[i] != 0) {
            lbl_80306D98[i]->b19 = 2;
        }
    }
    fn_8022642C();
    fn_8022642C();
    fn_8022642C();
    fn_8022642C();
    fn_8022642C();
    fn_8022642C();
    if (lbl_80347028 != 0) {
        fn_802275A4(lbl_80347030, 1);
        lbl_80347030 = 0;
        fn_801E17E0(lbl_80347028);
        lbl_80347028 = 0;
    }
}

void fn_80159C50(s32 n, char *dst, char *src)
{
    char *q;
    s32 len;
    s32 pad;
    s32 i;
    char *p;
    char c;
    s32 j;
    for (q = src, len = 0; len < n + 1; len++, q++) {
        if (*q == 0) break;
    }
    pad = (n - len) / 2;
    for (i = 0; i < pad; i++) {
        dst[i] = ' ';
    }
    j = i;
    p = dst + i;
    while (j < n && (c = *src) != 0) {
        *p = c;
        j++;
        p++;
        src++;
    }
    dst[j] = 0;
}

void fn_8015C4D8(void)
{
    Q *q;
    s32 off;
    E *e;
    s32 i;
    for (i = 0, off = 0, e = lbl_803472A4; i < lbl_803472D0; e++, off += 0x3e, i++) {
        q = (Q *)fn_80129D40(e->f20);
        *(u8 *)(lbl_8034727C + off + 0x54) = lbl_802E6F58[q->f10];
        *(s16 *)(lbl_8034727C + off + 0x30) = lbl_802E6FFC[e->f1c];
        *(s16 *)(lbl_8034727C + off + 0x32) = e->f24;
        *(s16 *)(lbl_8034727C + off + 0x34) = e->f2c;
        *(s16 *)(lbl_8034727C + off + 0x36) = e->f28;
        *(s16 *)(lbl_8034727C + off + 0x38) = e->f30;
        if (e->f48 != -1) {
            *(u8 *)(lbl_8034727C + off + 0x52) = e->f48;
            *(s16 *)(lbl_8034727C + off + 0x58) = e->f4c;
            *(s16 *)(lbl_8034727C + off + 0x5e) = e->f50;
            *(u8 *)(lbl_8034727C + off + 0x5a) = e->f54;
        }
    }
}

s32 fn_8015D234(Obj_8015D234 *o, St_8015D234 *st)
{
    S_8015D234 *s = o->s;
    A_8015D234 *a = s->a;
    if (st->cnt == 0) {
        a->f1c = -1.0f;
        s->flags |= 8;
        fn_80222964(a->h1bc);
        a->h1bc = 0;
        return 0;
    }
    switch (a->mode) {
    case 0:
        fn_80167374(o);
        fn_80222964(a->h1bc);
        a->h1bc = 0;
        s->flags |= 8;
        a->mode = 1;
    case 1:
        a->f1c = a->f1c - 1.0f / (f32)st->cnt;
        if (a->f1c < -1.0f) {
            a->f1c = -1.0f;
            return 0;
        }
    }
    return 1;
}

s32 fn_8015D340(Obj_8015D340 *o, St_8015D234 *st)
{
    S_8015D234 *s = o->s;
    A_8015D234 *a = s->a;
    if (st->cnt == 0) {
        a->f1c = 0.0f;
        s->flags &= ~8;
        s->flags &= ~0x100;
        return 0;
    }
    switch (a->mode) {
    case 0:
        fn_80167374(o);
        if (a->h1bc == 0) {
            fn_802229F8(o->h1bc);
            a->h1bc = o->h1bc;
        }
        s->flags &= ~8;
        a->mode = 1;
    case 1:
        a->f1c = a->f1c + 1.0f / (f32)st->cnt;
        if (a->f1c >= 0.0f) {
            a->f1c = 0.0f;
            return 0;
        }
    }
    return 1;
}

s32 fn_8015D54C(Obj_8015D54C *o, St_8015D54C *st)
{
    S_8015D54C *s = o->s;
    A_8015D54C *a = s->a;
    void *r = fn_80167604(o, st->arg);
    if (r == 0) {
        fn_801DBE1C(lbl_802B42C8, o->h17a);
        return 0;
    }
    switch (st->kind) {
    case 0:
        if (st->arg == 0) {
            s->fe0 = 0;
        } else {
            s->f124 = fn_80167578(a, st->arg);
            fn_80227810(s->f124);
            s->f128 = r;
            s->fe0 = 1;
        }
        break;
    case 1:
        if (st->arg == 0) {
            s->f12c = 0;
        } else {
            s->f170 = fn_80167578(a, st->arg);
            fn_80227810(s->f170);
            s->f174 = r;
            s->f12c = 1;
        }
        break;
    case 2:
        if (st->arg == 0) {
            s->f94 = 0;
        } else {
            s->fd8 = fn_80167578(a, st->arg);
            fn_80227810(s->fd8);
            s->fdc = r;
            s->f94 = 1;
        }
        break;
    }
    return 0;
}

s32 fn_8015DACC(Obj_8015DACC *o, St_8015DACC *st)
{
    S_8015DACC *s = o->s;
    s32 k = st->k;
    if (s->f8 == 0) {
        return 0;
    }
    if (fn_80167428(o, k) == 0) {
        return 0;
    }
    if (s->f74 == 0) {
        s->f74 = fn_8016748C(o, (u32)o->m->p20->p0);
    }
    if (k == 0) {
        if (s->f74 != 0) {
            *s->f74 = *o->m->p20->p0;
        }
        return 0;
    }
    if (s->f74 != 0) {
        s->f6c = fn_80167428(o, k);
        if (s->f6c != 0) {
            *s->f74 = *s->f6c;
        }
    }
    return 0;
}

void fn_80150B24(Obj* o, int idx, s32 a, s32 b)
{
    Ent* e = (Ent*)((u8*)o + 0x20 + idx * 0x1C);
    f32 d;

    o->x58 = 0;
    o->x5c = 0;
    switch (e->kind) {
    case 0:
    case 4:
    case 6:
        return;
    }
    {
        f32 r = fn_801568F8(0, 1, 0.0f, 10.0f);
        switch (e->kind) {
        case 1:
        case 2:
        case 3:
        case 7:
            d = 10.0f;
            break;
        case 5:
            d = 5.0f;
            break;
        }
        o->x58 = (s32)(4.0f * r / d / 5.0f);
    }
    o->x58 = (10 < o->x58) ? o->x58 : 10;
    o->x58 = (0x2C > o->x58) ? o->x58 : 0x2C;
    if (e->kind == 7) {
        e->x18[e->kind * 2 + 1] = 1;
    }
    if ((s8)e->x18[e->kind * 2 + 1] != 0) {
        o->x60 = a;
    } else {
        o->x60 = b;
    }
    o->x68 = e;
}

void fn_80151128(Tab_80151128* t, Src* s)
{
    extern char lbl_802B3AE0[];
    extern void fn_8015757C(const char*, s32);
    s32 idx = s->idx;
    Ent_80151128* e;
    int i;

    if (idx >= 0x80) {
        fn_8015757C(lbl_802B3AE0, idx);
        return;
    }
    if (idx > 0) {
        e = &t->ents[idx];
        e->x4 = idx;
        e->x0 = 1;
        for (i = 0; i < 9; i++) {
            e->v[i] = s->v[i];
        }
        if (e->v[1]) {
            e->x8++;
        }
        if (e->v[2]) {
            e->x8++;
        }
        if (e->v[3]) {
            e->x8++;
        }
        if (e->v[4]) {
            e->x8++;
        }
        if (e->v[5]) {
            e->x8++;
        }
        if (e->v[6]) {
            e->x8++;
        }
        if (e->v[7]) {
            e->x8++;
        }
        if (e->v[8]) {
            e->x8++;
        }
    }
}

void fn_8015275C(Obj_8015275C* o, f32* mtx)
{
    extern NJS_VECTOR lbl_802B3B68;
    extern NJS_VECTOR lbl_802B3B74;
    extern void njSetMatrix(NJS_MATRIX dst, NJS_MATRIX src);
    extern void njUnitTransPortion(NJS_MATRIX m);
    extern void fn_801580A4(Angle* out, NJS_VECTOR* v);
    extern void fn_80158250(Flag* f);
    NJS_VECTOR va = lbl_802B3B68;
    NJS_VECTOR vb = lbl_802B3B74;
    Angle ang[3];
    NJS_MATRIX m;

    njCalcPoint(mtx, &o->src, &o->dst);
    if (o->model != NULL) {
        o->model->inner->pos.x = o->dst.x;
        o->model->inner->pos.y = o->dst.y;
        o->model->inner->pos.z = o->dst.z;
        njSetMatrix(m, mtx);
        njUnitTransPortion(m);
        njCalcPoint(m, &va, &vb);
        vb.x = -vb.x;
        vb.y = -vb.y;
        vb.z = -vb.z;
        fn_801580A4(ang, &vb);
        o->model->inner->ang[0] = ang[0];
        o->model->inner->ang[1] = ang[1];
        o->model->inner->ang[2] = ang[2];
    }
    if (o->flag->on != 0) {
        fn_80158250(o->flag);
    }
}

void fn_80153060(Obj_80153060* o, f32* mtx)
{
    extern NJS_VECTOR lbl_802B3B38;
    extern NJS_VECTOR lbl_802B3B44;
    extern void njSetMatrix(NJS_MATRIX dst, NJS_MATRIX src);
    extern void njUnitTransPortion(NJS_MATRIX m);
    extern void fn_801580A4(Angle* out, NJS_VECTOR* v);
    extern void fn_8020EF30(s32);
    NJS_VECTOR va = lbl_802B3B38;
    NJS_VECTOR vb = lbl_802B3B44;
    Angle ang[3];
    NJS_MATRIX m;

    if (o->model != NULL && o->model->inner != NULL && o->count != 0) {
        o->count--;
        if (o->count == 0) {
            o->model = NULL;
            fn_8020EF30(o->x4);
            return;
        }
        njCalcPoint(mtx, &va, &vb);
        o->model->inner->pos.x = vb.x;
        o->model->inner->pos.y = vb.y;
        o->model->inner->pos.z = vb.z;
        njSetMatrix(m, mtx);
        njUnitTransPortion(m);
        njCalcPoint(m, &va, &vb);
        vb.x = -vb.x;
        vb.y = -vb.y;
        vb.z = -vb.z;
        fn_801580A4(ang, &vb);
        o->model->inner->ang[0] = ang[0];
        o->model->inner->ang[1] = ang[1];
        o->model->inner->ang[2] = ang[2];
    }
}

void fn_80154404(void)
{
    int i;

    for (i = 0; i < 8; i++) {
        if (lbl_80346FC8[0]->a[i].target != NULL) {
            lbl_80346FC8[0]->a[i].active = 0;
            lbl_80346FC8[0]->a[i].target->x1ec = 0;
        }
        if (lbl_80346FC8[1]->a[i].target != NULL) {
            lbl_80346FC8[1]->a[i].active = 0;
            lbl_80346FC8[1]->a[i].target->x1ec = 0;
        }
    }
    for (i = 0; i < 32; i++) {
        if (lbl_80346FC8[0]->b[i].target != NULL) {
            lbl_80346FC8[0]->b[i].active = 0;
            lbl_80346FC8[0]->b[i].target->x1ec = 0;
        }
        if (lbl_80346FC8[1]->b[i].target != NULL) {
            lbl_80346FC8[1]->b[i].active = 0;
            lbl_80346FC8[1]->b[i].target->x1ec = 0;
        }
    }
}

Anim* fn_801552B0(s32 owner, KeyIn* in1, Pair* in2)
{
    Anim* buf;
    Handle* h;
    int i;
    Anim* a;
    Key* k;
    Pair* p;

    if (fn_801D6E38() == 0) {
        return NULL;
    }
    h = fn_80226704(lbl_80347588, fn_80155438, 0x28);
    if (h == NULL) {
        return NULL;
    }
    buf = fn_801E1A2C(1, 0x198);
    h->anim = buf;
    if (buf == NULL) {
        h->flags |= 0x40;
        return NULL;
    }
    a = h->anim;
    a->x0 = owner;
    a->x8 = 0;
    a->xc = 0;
    a->x4 = 0;
    k = a->keys;
    p = a->pairs;
    for (i = 0; i < 31; i++) {
        k->a = in1->a;
        k->b = in1->b;
        k->c = in1->c;
        p->w[0] = in2->w[0];
        p->w[1] = in2->w[1];
        if (k->c == 0) {
            a->x10 = k->b;
            a->xa = i + 1;
            break;
        }
        k++;
        in1++;
        p++;
        in2++;
    }
    if (i >= 31) {
        k[-1].c = 0;
        a->xa = 31;
        a->x10 = k[-1].b;
    }
    a->x1c = 1;
    a->x1d = 0;
    a->x20 = 0;
    a->x1e = a->keys[0].a;
    a->x1f = a->keys[0].b;
    return (Anim*)h;
}

void fn_80155624(Anim_80155624* a)
{
    int i;
    int j;
    Key* dst;
    Key* src;

    lbl_80346FE0->x8 = a->x4;
    lbl_80346FE0->xc = a->x8;
    lbl_80346FE0->xe = a->keys[a->x8].c;
    if (lbl_80346FE0->x6 == 0) {
        return;
    }
    src = lbl_80346FE0->keys;
    dst = a->keys;
    for (i = 0; i < 31;) {
        *dst = *src;
        if (src->c > 0xB4) {
            src->c = 0;
        }
        if (src->c == 0) {
            break;
        }
        i++;
        dst++;
        src++;
    }
    for (j = 0; j < 31 - i; j++) {
        dst->a = 0;
        dst->b = 0;
        dst->c = 0;
    }
    a->x4 = 0;
    lbl_80346FE0->x8 = 0;
    a->x8 = 0;
    lbl_80346FE0->xc = 0;
    a->x1e = a->keys[0].a;
    a->x1f = a->keys[0].b;
    lbl_80346FE0->x6 = 0;
}

void fn_80156B04(f32* mtx, Obj_80156B04* o, NJS_POINT3* off, Angle* rot, void* out)
{
    njPushMatrixEx();
    fn_80286EE8();
    fn_8028B498();
    njSetMatrix(NULL, mtx);
    o->pos.x = o->part->pos[0];
    o->pos.y = o->part->pos[1];
    o->pos.z = o->part->pos[2];
    o->rot[0] = (Angle)(182.04445f * o->part->rot[0]);
    o->rot[1] = (Angle)(182.04445f * o->part->rot[1]);
    o->rot[2] = (Angle)(182.04445f * o->part->rot[2]);
    if (off != NULL) {
        o->pos.x += off->x;
        o->pos.y += off->y;
        o->pos.z += off->z;
    }
    njTranslate(NULL, o->pos.x, o->pos.y, o->pos.z);
    njRotateZXY(NULL, o->rot[0], o->rot[1], o->rot[2]);
    if (rot != NULL) {
        njRotateZXY(NULL, rot[0], rot[1], rot[2]);
    }
    njGetTranslation(NULL, &o->pos);
    if (out != NULL) {
        fn_80291C44(out);
    }
    njPopMatrixEx();
}

void fn_801580A4(s32 *out, f32 *v) {
    f32 t = v[2];
    f32 z;
    f32 r;
    if ((f32)fabs(t) < 0.0001) {
        z = 0.0f;
    } else {
        z = t;
    }
    r = fn_80291A5C(z * z + v[0] * v[0]);
    if (0.0f != v[1] || 0.0f != r) {
        out[0] = (u16)(s32)(10430.381f * (f32)atan2(v[1], r));
        lbl_8030EA10[0] = 0;
    } else {
        out[0] = 0;
        lbl_8030EA10[0] = 1;
    }
    if (0.0f != v[0] || 0.0f != z) {
        out[1] = (u16)((s32)(10430.381f * (f32)atan2(v[0], z)) + 0x8000);
        lbl_8030EA10[1] = 0;
    } else {
        out[1] = 0;
        lbl_8030EA10[1] = 1;
    }
    out[2] = 0;
}

s32 fn_8015D768(Ent_8015D768 *self, Arg *a) {
    Obj_8015D768 *o = self->x1d8->x8;
    f32 y;
    NJS_POINT3 v;
    Probe p;
    if (3.4028235e38f != a->x1c) {
        o->x38 = a->x1c;
    }
    if (3.4028235e38f != a->x20) {
        o->x3c = a->x20;
    }
    if (3.4028235e38f != a->x24) {
        o->x40 = a->x24;
    }
    y = o->x3c;
    if (1.17549435e-38f == a->x20) {
        if (o->x1b8 != 0) {
            if (fn_802254A0(&o->x38, o->x1b8) == 0) {
                o->x3c = y;
            }
        } else {
            p.x = o->x38;
            p.y = y;
            p.z = o->x40;
            if (fn_80224588(0xffff, &p, 1) != 0) {
                o->x3c = (p.a != 0) ? p.h : y;
            }
        }
    } else {
        o->x3c = a->x20;
    }
    if (a->x34 != 0x7fffffff) {
        fn_801673D8(o, a->x34);
    }
    v.x = a->x28 - o->x38;
    v.y = (1.17549435e-38f == a->x2c) ? 0.0f : a->x2c - o->x3c;
    v.z = a->x30 - o->x40;
    fn_802135B4(&v, &o->x40 + 1);
    fn_801671C0(o);
    self->x104 = self->x38;
    self->x108 = self->x3c;
    self->x10c = self->x40;
    return 0;
}

s32 fn_8015D910(Ent_8015D910 *self, Arg *a) {
    extern void fn_801673D8(Obj_8015D910 *o, s32 a);
    extern void fn_801671C0(Obj_8015D910 *o);
    Obj_8015D910 *o = self->x1d8->x8;
    f32 y;
    Probe p;
    if (a->x34 != 0x7fffffff) {
        fn_801673D8(o, a->x34);
    }
    if (3.4028235e38f != a->x1c) {
        o->x38 = a->x1c;
    }
    y = o->x3c;
    if (1.17549435e-38f == a->x20) {
        if (o->x1b8 != 0) {
            if (fn_802254A0(&o->x38, o->x1b8) == 0) {
                o->x3c = y;
            }
        } else {
            p.x = o->x38;
            p.y = y;
            p.z = o->x40;
            if (fn_80224588(0xffff, &p, 1) != 0) {
                o->x3c = (p.a != 0) ? p.h : y;
            }
        }
    } else {
        o->x3c = a->x20;
    }
    if (3.4028235e38f != a->x24) {
        o->x40 = a->x24;
    }
    if (3.4028235e38f != a->x28) {
        o->x44 = (s32)(182.04445f * a->x28);
    }
    if (3.4028235e38f != a->x2c) {
        o->x48 = (s32)(182.04445f * a->x2c);
    }
    if (3.4028235e38f != a->x30) {
        o->x4c = (s32)(182.04445f * a->x30);
    }
    fn_801671C0(o);
    self->x104 = self->x38;
    self->x108 = self->x3c;
    self->x10c = self->x40;
    return 0;
}

void fn_80158708(In *in) {
    Node *node = 0;
    Obj_80158708 *o;
    s32 v;
    f32 fv;
    s32 iv;
    if (lbl_80306DB8[in->h8] == 0) {
        node = fn_802268E8(lbl_803475A8, fn_801589BC);
        node->x24 = fn_801E1C7C(0x204);
        memset(node->x24, 0, 0x204);
        lbl_80306DB8[in->h8] = node->x24;
    }
    o = (Obj_80158708 *)node->x24;
    o->x1f4 = node;
    o->h4a = 1;
    o->f8 = 1;
    o->h10 = in->h8;
    o->f4 = 0;
    o->h12 = 1;
    o->fc = -1.1f;
    o->h6e = 0xff;
    o->f2c = in->fc;
    v = in->f10;
    o->f30 = v;
    fv = (f32)v;
    o->f20 = fv;
    iv = (s32)fv;
    o->f28 = iv;
    o->f34 = iv;
    o->f18 = 0;
    o->f74 = in->f0;
    o->h72 = in->f4;
    o->hb4 = in->h8;
    o->hd8 = in->h8;
    o->hfc = in->h8;
    o->h120 = in->h8;
    o->h144 = in->h8;
    o->h168 = in->h8;
    o->h18c = in->h8;
    o->h1b0 = in->h8;
    o->h1d4 = in->h8;
}

void fn_801577CC(BtlTracks *base, s32 a, s32 b, s32 i) {
    NJS_MATRIX m;
    f32 v[3];
    f32 p[3];
    BtlSide *o = lbl_80346FC8[b];
    s32 k = 0;
    BtlTrack *pa = &base->side[a].ent[i];
    Rec_80157684 *A = pa->rec;
    Rec_80157684 *B = base->side[b].ent[i].rec;
    s32 *out = pa->aim[0];
    s32 t;
    for (; k < 0x3ad; k++) {
        njUnitMatrix(m);
        njRotateZXY(m, B->v[0], B->v[1], B->v[2]);
        njCalcPoint(m, &o->centre, (NJS_POINT3 *)p);
        v[0] = B->pos[0] + p[0] - A->pos[0];
        v[1] = B->pos[1] + p[1] - A->pos[1];
        v[2] = B->pos[2] + p[2] - A->pos[2];
        v[0] = -v[0];
        v[1] = -v[1];
        v[2] = -v[2];
        fn_801580A4(out, v);
        out[0] -= A->v[0];
        out[1] -= A->v[1];
        t = out[0] & 0xffff;
        if (t >= 0x8000) {
            t = -(0x10000 - t);
        }
        out[0] = t;
        t = out[1] & 0xffff;
        if (t >= 0x8000) {
            t = -(0x10000 - t);
        }
        out[1] = t;
        A++;
        B++;
        out += 3;
    }
}

void fn_8015205C(Obj_8015205C* o) {
    extern void* memset(void*, int, u32);
    memset(o, 0, 0x1f4);
    o->f0 = 0;
    o->curA[0] = 0.0f;
    o->curA[1] = 0.0f;
    o->curA[2] = 0.0f;
    o->curA[3] = 0.0f;
    o->curA[4] = 0.0f;
    o->curA[5] = 0.0f;
    o->curA[6] = -30.0f;
    o->curA[7] = 0.0f;
    o->curA[8] = 100.0f;
    o->curA[9] = 0.0f;
    o->curA[10] = 0.0f;
    o->curA[11] = 60.0f;
    o->curB[0] = 0.0f;
    o->curB[1] = 0.0f;
    o->curB[2] = 0.0f;
    o->curB[3] = 0.0f;
    o->curB[4] = 0.0f;
    o->curB[5] = 0.0f;
    o->curB[6] = 0.0f;
    o->curB[7] = 0.0f;
    o->curB[8] = 1.0f;
    o->curB[9] = 0.0f;
    o->curB[10] = 0.0f;
    o->curB[11] = 1.0f;
    o->loA[0] = -1000.0f;
    o->hiA[0] = 1000.0f;
    o->loA[1] = -1000.0f;
    o->hiA[1] = 1000.0f;
    o->loA[2] = -1000.0f;
    o->hiA[2] = 1000.0f;
    o->loA[3] = -1000.0f;
    o->hiA[3] = 1000.0f;
    o->loA[4] = 0.0f;
    o->hiA[4] = 100.0f;
    o->loA[5] = 0.0f;
    o->hiA[5] = 100.0f;
    o->loA[6] = -85.0f;
    o->hiA[6] = 85.0f;
    o->loA[7] = -3600.0f;
    o->hiA[7] = 3600.0f;
    o->loA[8] = 20.0f;
    o->hiA[8] = 8000.0f;
    o->loA[9] = 0.0f;
    o->hiA[9] = 100.0f;
    o->loA[10] = -1000.0f;
    o->hiA[10] = 1000.0f;
    o->loA[11] = 2.0f;
    o->hiA[11] = 100.0f;
    o->loB[0] = -10.0f;
    o->hiB[0] = 10.0f;
    o->loB[1] = -10.0f;
    o->hiB[1] = 10.0f;
    o->loB[2] = -10.0f;
    o->hiB[2] = 10.0f;
    o->loB[3] = -10.0f;
    o->hiB[3] = 10.0f;
    o->loB[4] = -50.0f;
    o->hiB[4] = 50.0f;
    o->loB[5] = -50.0f;
    o->hiB[5] = 50.0f;
    o->loB[6] = -2.0f;
    o->hiB[6] = 2.0f;
    o->loB[7] = -4.0f;
    o->hiB[7] = 4.0f;
    o->loB[8] = 0.91f;
    o->hiB[8] = 1.1f;
    o->loB[9] = -50.0f;
    o->hiB[9] = 50.0f;
    o->loB[10] = -4.0f;
    o->hiB[10] = 4.0f;
    o->loB[11] = 0.91f;
    o->hiB[11] = 1.1f;
}

void fn_801528AC(Obj_801528AC* o, f32* mtx, s32 a, s32 flag) {
    extern NJS_VECTOR lbl_802B3B50;
    extern NJS_VECTOR lbl_802B3B5C;
    extern void njSetMatrix(NJS_MATRIX dst, NJS_MATRIX src);
    extern void njUnitTransPortion(NJS_MATRIX m);
    extern void fn_8020EFD4(u8* p);
    extern void fn_801580A4(Angle* out, NJS_VECTOR* v);
    extern void fn_80158200(void* a, NJS_POINT3* b, Angle* c, s32 d);
    NJS_VECTOR va = lbl_802B3B50;
    NJS_VECTOR vb = lbl_802B3B5C;
    Angle ang[3];
    NJS_MATRIX m;

    if (o->f44 != 0) {
        fn_8020EFD4(o->f3c);
        o->f40 = 180;
    }
    njCalcPoint(mtx, &o->src, &o->dst);
    if (o->f2c != 0) {
        o->model->inner->pos.x = o->dst.x;
        o->model->inner->pos.y = o->dst.y;
        o->model->inner->pos.z = o->dst.z;
        njSetMatrix(m, mtx);
        njUnitTransPortion(m);
        njCalcPoint(m, &va, &vb);
        vb.x = -vb.x;
        vb.y = -vb.y;
        vb.z = -vb.z;
        fn_801580A4(ang, &vb);
        o->model->inner->ang[0] = ang[0];
        o->model->inner->ang[1] = ang[1];
        o->model->inner->ang[2] = ang[2];
        o->model->inner->b1ec = 1;
        o->model->inner->b1ed = o->f8;
        o->model->inner->b1ee = 0;
        o->model->inner->b1ef = 0;
        o->model->inner->b1f0 = o->f48;
        o->model->inner->b1f1 = o->f0;
        o->model->inner->h22c = o->f34;
        if (flag != 0) {
            o->model->inner->h22e = o->f58;
            o->model->inner->h230 = 1;
        } else {
            o->model->inner->h22e = o->f50;
            o->model->inner->h230 = 0;
        }
        fn_80158200(o->f6c, &o->dst, ang, a);
        o->f68->rows[o->f8].fc++;
    }
}

void fn_80157150(s32 a)
{
    s32 i;
    s32 n;
    Ent_80157150 *e;
    s32 f;
    BtlTrack *q;

    if (lbl_803472A8 == 0) {
        return;
    }
    n = lbl_803472A8->count;
    e = lbl_803472A8->ents;
    for (i = 0; i < n; i++) {
        q = &lbl_80346FD4->side[a].ent[i];
        if (a == 0) {
            f = 0;
            if ((*(s8 **)&lbl_80346FD0) != 0) {
                f = (*(s8 **)&lbl_80346FD0)[lbl_803472BC * 16 + i * 2 + a * 8];
            }
            f |= q->f[1] | (q->f[0] << 1);
            e->f34 = f;
            if ((*(s8 **)&lbl_80346FD0) != 0) {
                f = (*(s8 **)&lbl_80346FD0)[lbl_803472BC * 16 + i * 2 + a * 8 + 1];
            }
            f |= q->f[3] | (q->f[2] << 1);
            e->f38 = f;
        } else {
            f = 0;
            if ((*(s8 **)&lbl_80346FD0) != 0) {
                f = (*(s8 **)&lbl_80346FD0)[lbl_803472BC * 16 + i * 2 + a * 8];
            }
            f |= q->f[1] | (q->f[0] << 1);
            e->f3c = f;
            if ((*(s8 **)&lbl_80346FD0) != 0) {
                f = (*(s8 **)&lbl_80346FD0)[lbl_803472BC * 16 + i * 2 + a * 8 + 1];
            }
            f |= q->f[3] | (q->f[2] << 1);
            e->f40 = f;
        }
        e++;
    }
}

s32 fn_80157EA8(Out_80157EA8 *out, Obj_80157EA8 *obj, f32 frame)
{
    NJS_MATRIX m;
    NJS_POINT3 p;
    s32 flags = 0;
    Anim_80157EA8 *anim = obj->anim;

    if (anim != 0) {
        if (frame >= anim->cnt) {
            frame = anim->cnt - 1.0;
        } else if (frame < 0.0f) {
            frame = 0.0f;
        }
        fn_801E78C8(anim, out->pos, out->ang, out->off, frame);
        flags = obj->anim->type & 7;
    } else {
        out->pos[0] = 0.0f;
        out->pos[1] = 0.0f;
        out->pos[2] = 0.0f;
        out->ang[0] = 0;
        out->ang[1] = 0;
        out->ang[2] = 0;
    }
    njUnitMatrix(m);
    njRotateZXY(m, (s32)(182.04445f * obj->part->rot[0]), (s32)(182.04445f * obj->part->rot[1]), (s32)(182.04445f * obj->part->rot[2]));
    njCalcPoint(m, (NJS_POINT3 *)out->pos, &p);
    out->pos[0] = p.x + obj->part->pos[0];
    out->pos[1] = p.y + obj->part->pos[1];
    out->pos[2] = p.z + obj->part->pos[2];
    out->ang[0] += (s32)(182.04445f * obj->part->rot[0]);
    out->ang[1] += (s32)(182.04445f * obj->part->rot[1]);
    out->ang[2] += (s32)(182.04445f * obj->part->rot[2]);
    return flags;
}

void fn_80150DAC(void)
{
    int lo, hi;
    s16* tp;
    int i;
    s32 n = 0;

    (*(Rec_80150DAC**)&lbl_80346F9C) = ((Rec_80150DAC*)fn_801E1C7C(0xBF4));
    tp = lbl_802E5EF0;
    lo = tp[0];
    hi = tp[1];
    for (i = 0; i < 510; i++) {
        if (i >= hi) {
            lo = tp[1];
            n++;
            hi = tp[2];
            tp++;
        }
        (*(Rec_80150DAC**)&lbl_80346F9C)[i].a = (s16)i - lo;
        (*(Rec_80150DAC**)&lbl_80346F9C)[i].b = (s16)hi - lo;
        (*(Rec_80150DAC**)&lbl_80346F9C)[i].n = n;
    }
}

void fn_8015A888(void) {
    s32 i;
    s32 n = 0;
    s32 j;
    for (i = 0; i < lbl_8034729C; i++) {
        Ent_8015A888 *e = &(*(Ent_8015A888(*)[])&lbl_80308EF8)[i];
        u16 flags = 0;
        if (e->p0->p24->h17a == 0) {
            fn_80145CA4(0, 0, 2);
            fn_80145CA4(0, 0, 3);
            fn_80145CA4(0, 0, 8);
            fn_80145CA4(0, 0, 0xc);
        } else {
            if (fn_80145CA4(1, lbl_802E6F58[e->f10], 2) != 0) flags |= 0x400;
            if (fn_80145CA4(1, lbl_802E6F58[e->f10], 3) != 0) flags |= 0x200;
            if (fn_80145CA4(1, lbl_802E6F58[e->f10], 8) != 0) flags |= 0x80;
            if (fn_80145CA4(1, lbl_802E6F58[e->f10], 0xc) != 0) flags |= 0x20;
            j = n + 1;
            n++;
            fn_8015854C(j, flags);
            fn_80158650(j, 1);
            fn_801586D4(j);
        }
    }
}

void fn_80153518(s32 n) {
    u8* b;

    b = lbl_80306758.buf;
    if (fn_8010A164(n) == NULL) {
        if (lbl_80306758.f8 != 0) {
            fn_80109A94((void *)(b));
        }
        lbl_80306758.f8 = 0;
        lbl_80306758.f0 = 0;
        strcpy((void *)(b), (void *)(lbl_802B3BCC));
        b[0xa] = n / 10000 + '0';
        b[0xb] = n % 10000 / 1000 + '0';
        b[0xc] = n % 1000 / 100 + '0';
        b[0xd] = n % 100 / 10 + '0';
        b[0xe] = n % 10 + '0';
        b[0xf] = '.';
        b[0x10] = 'm';
        b[0x11] = 'l';
        b[0x12] = 'd';
        b[0x13] = 0;
        lbl_80306758.f4c = fn_80109E7C(b, 0x7fff);
        lbl_80306758.f4 = 1;
        lbl_80306758.f8 = 0;
        lbl_80306758.f0 = n;
    }
}

void fn_80155438(Handle_80155438 *h)
{
    Anim_80155438 *a = h->anim;
    int i;
    Key *k;
    Pair *p;

    fn_80155624((void *)(a));
    a->x14 = a->pairs[a->x8].w[0];
    a->x18 = a->pairs[a->x8].w[1];
    a->x4++;
    if (a->x4 % (a->keys[a->x8].c + 1) != 0) {
        if (a->x14 != 0 && a->x4 % a->x14 != 0) {
            a->keys[a->x8].a *= -1;
        }
        if (a->x18 == 0 || a->x4 % a->x18 >= a->x18 / 2) {
            fn_801D6CBC(a->x0, &a->x1c);
        }
    } else {
        a->x8++;
        if (a->keys[a->x8].c == 0) {
            a->xc++;
            if (a->xc >= a->x10) {
                fn_801D6C3C(a->x0);
                if (h->anim != 0) {
                    fn_801E1784(h->anim);
                    h->anim = 0;
                }
                h->flags |= 0x40;
                k = lbl_80346FE0->keys;
                p = lbl_80346FE0->pairs;
                for (i = 31; i != 0; i--) {
                    k->a = 0;
                    k->b = 0;
                    k->c = 0;
                    p->w[0] = 0;
                    p->w[1] = 0;
                    k++;
                    p++;
                }
                lbl_80346FE0->x0 = 0;
                return;
            }
            a->x8 = 0;
        }
        fn_801D6CBC(a->x0, &a->x1c);
        a->x4 = 0;
        a->x1e = a->keys[a->x8].a;
        a->x1f = a->keys[a->x8].b;
    }
}

void fn_80158DB4(Obj_8015887C *o)
{
    S_80158DB4 *s = (S_80158DB4 *)o->s;
    s32 d;

    if (s->f28 != s->f34 && s->f18 == 0) {
        if (s->f28 > s->f34) {
            s->f18 = 1;
        } else if (s->f28 < s->f34) {
            s->f18 = 2;
        }
        d = s->f28 - s->f34;
        s->f28 = s->f34;
        s->f24 = (f32)(s32)(f32)fabs((f32)d) / 20.0f;
    }
    switch (s->h12) {
    case 3:
    case 4:
    case 6:
    case 8:
        if ((s->h12 == 6 || s->h12 == 8) && s->f14 == 0) {
            sprintf(s->buf, "");
        } else {
            sprintf(s->buf, "%d", s->f14);
        }
        if (s->f4 == 1) {
            if (s->f18 == 1) {
                s->f20 = s->f20 - s->f24;
                if (s->f20 <= (f32)s->f34) {
                    s->f20 = (f32)s->f34;
                    s->f18 = 0;
                }
            } else if (s->f18 == 2) {
                s->f20 = s->f20 + s->f24;
                if (s->f20 >= (f32)s->f34) {
                    s->f20 = (f32)s->f34;
                    s->f18 = 0;
                }
            }
        }
        break;
    case 10:
        sprintf(s->buf, "%d", s->f14);
        s->h1ee = 3;
        break;
    default:
        sprintf(s->buf, "");
        break;
    }
    s->f1e4 = s->f20 / (f32)s->f2c;
}

void fn_80158BE8(Obj_8015887C *o)
{
    S_80158BE8 *s = (S_80158BE8 *)o->s;

    if (s->h44 == 0) {
        s->b_1f0 = 0xff;
        return;
    }
    if (s->h48 > 0) {
        s->h48--;
        if (s->h44 == 1) {
            s->b_1f0 = 0;
        } else {
            s->b_1f0 = 0xff;
        }
    } else if (s->h44 == 1) {
        s->h6e = (s16)((f32)s->h6e + (f32)floor((f32)(0x100 / s->h46)));
        if (s->h6e >= 0xff) {
            s->h6e = 0xff;
            s->h44 = 0;
        }
    } else {
        s->h6e = (s16)((f32)s->h6e - (f32)floor((f32)(0x100 / s->h46)));
        if (s->h6e <= 0) {
            s->h6e = 0;
            s->h44 = 0;
            s->f4 = 0;
        }
    }
    s->b_1f0 = s->h6e;
    s->b_be = s->h6e;
    s->b_e2 = s->h6e;
    s->b_106 = s->h6e;
    s->b_12a = s->h6e;
    s->b_14e = s->h6e;
    s->b_172 = s->h6e;
    s->b_196 = s->h6e;
    s->b_1ba = s->h6e;
}

void fn_80159610(Sub_8015887C *o_)
{
    Obj_80159610 *o = (Obj_80159610 *)o_;
    DrawState ds;
    Vtx_80159610 v[4];
    f32 y0, y1, x0, x1, z;
    s32 i;
    u32 col;
    u8 tex;

    DrawStateDefault2D(&ds);
    if (DrawStatePush(&ds) != 0) {
        if (o->h10 == 0) {
            x0 = 10.0f;
            y0 = 114.0f;
        } else {
            y0 = 40.0f * (f32)o->h10 + 74.0f;
            x0 = 598.0f;
        }
        x1 = 32.0f + x0;
        y1 = 32.0f + y0;
        if (o->p74 != 0) {
            fn_80299040(o->p74);
            fn_8021EDE0(o->p74, o->h72);
        } else {
            fn_80299040(lbl_80347034);
            fn_8021EDE0(lbl_80347034, fn_8021EE1C(lbl_80347034, lbl_802E6F00[2]));
        }
        z = fn_801DBD9C(-2.0f);
        col = o->alpha | 0xffffff00;
        v[0].x = x0;
        v[0].y = y0;
        v[0].u = 0.0f;
        v[0].v = 0.0f;
        v[1].x = x0;
        v[1].y = y1;
        v[1].u = 0.0f;
        v[1].v = 0.5019608f;
        v[2].x = x1;
        v[2].y = y0;
        v[2].u = 0.5019608f;
        v[2].v = 0.0f;
        v[3].x = x1;
        v[3].y = y1;
        v[3].u = 0.5019608f;
        v[3].v = 0.5019608f;
        for (i = 0; i < 4; i++) {
            v[i].z = z;
            v[i].colour = col;
        }
        fn_80291064(v, 4, 1);
        fn_80299040(lbl_80347034);
        tex = fn_8021EE1C(lbl_80347034, lbl_802E6F00[3]);
        fn_8021EDE0(lbl_80347034, tex);
        z = fn_801DBD9C(-1.5f);
        col = o->alpha | 0xdcdcdc00;
        v[1].v = 1.0f;
        v[2].u = 1.0f;
        v[3].u = 1.0f;
        v[3].v = 1.0f;
        for (i = 0; i < 4; i++) {
            v[i].z = z;
            v[i].colour = col;
        }
        fn_80291064(v, 4, 1);
        DrawStatePop(0);
    }
}

void fn_80153A44(s32 unused, f32* f)
{
    s32 a = (s32)f[0];
    s32 b = (s32)f[1];
    s32 c = (s32)f[2];
    s32 v0 = (s32)f[3];
    s32 v1 = (s32)f[4];
    s32 v2 = (s32)f[5];
    s32 v3 = (s32)f[6];

    if (v0 >= 0x20) {
        fn_8015757C((s32)lbl_802B3BD8, v0);
    }
    if (v1 >= 0x20) {
        fn_8015757C((s32)lbl_802B3BD8, v1);
    }
    if (v2 >= 0x20) {
        fn_8015757C((s32)lbl_802B3BD8, v2);
    }
    if (v3 >= 0x20) {
        fn_8015757C((s32)lbl_802B3BD8, v3);
    }
    lbl_80346FB8->active = 1;
    lbl_80346FB8->b1 = -1;
    lbl_80346FB8->b2 = -1;
    lbl_80346FB8->b3 = -1;
    lbl_80346FB8->cell[a][b][c].v[0] = v0;
    lbl_80346FB8->cell[a][b][c].v[1] = v1;
    lbl_80346FB8->cell[a][b][c].v[2] = v2;
    lbl_80346FB8->cell[a][b][c].v[3] = v3;
}

static inline void Advance(Obj_80156E54 *self)
{
    f32 zero = lbl_8034A8F8;
    self->frame += self->speed;
    if (zero > self->speed) {
        if (zero > self->frame) {
            self->done = 1;
            self->frame = (f32)self->anim->cnt - lbl_8034A904;
        }
    } else {
        if (self->frame > (f32)self->anim->cnt - lbl_8034A904) {
            self->done = 1;
            self->frame = zero;
        }
    }
}

void fn_80156E54(Obj_80156E54 *self, void *m)
{
    NJS_TEXLIST t;
    NJS_TEXLIST *tex = self->texlist;
    u32 tex4;

    if (tex != 0) {
        tex4 = tex->nbTexture;
    } else {
        tex4 = 0;
    }
    if (self->model == 0) {
        return;
    }
    if (self->hidden != 0 || lbl_8034A900 >= self->scale) {
        if (self->anim != 0) {
            Advance(self);
        } else {
            self->done = 1;
        }
        return;
    }
    if (tex != 0) {
        t.nbTexture = tex4;
        t.textures = self->texlist->textures;
        fn_80299040(&t);
    }
    njPushMatrixEx();
    fn_80286EE8();
    fn_8028B498();
    fn_802974E0(self->pos);
    fn_801E4FD4((void *)self);
    njMultiMatrix(0, m);
    if (self->anim != 0) {
        fn_801E7194(self->flags176, self->model, self->anim, self->xec, self->frame);
        Advance(self);
    } else {
        fn_801E4CB0(self->flags176, self->model);
        self->done = 1;
    }
    DrawStatePop(0);
    njPopMatrixEx();
}

static inline EvObj* TaskWork(struct Task* t) {
    return t->work;
}

void fn_801512DC(Obj_801512DC* o, In_801512DC* in) {
    Fx* s;
    NJS_POINT3* c;
    BtlSide* sl;
    struct Task* r;
    EvObj* a;
    EvObj* b;
    s32 t;

    s = &o->sub;
    switch (in->f4) {
    case 0:
        c = NULL;
        memset(o, 0, 0x214);
        fn_8015205C((void *)s);
        o->fc = 1;
        o->f0 = in->f0;
        o->f4 = in->f8;
        o->f8 = in->fc;
        t = o->f4;
        sl = lbl_80346FC8[t];
        if (sl->lead.target != NULL) {
            c = &sl->lead.target->ext->target;
        }
        a = sl->obj;
        b = lbl_80346FC8[t ^ 1]->obj;
        r = fn_8010A164(o->f8);
        if (r == NULL) {
            fn_8015757C((s32)lbl_802B3B18, TaskWork(r)->x178);
        }
        fn_801515F8(s, &a->pos, a->ang, c, &TaskWork(r)->ext->target, &b->pos);
        s->mode = in->f10;
        s->ca[0] = in->f[0];
        s->ca[1] = in->f[1];
        s->ca[2] = in->f[2];
        s->ca[3] = in->f[3];
        s->ca[4] = in->f[4];
        s->ca[5] = in->f[5];
        s->ca[6] = in->f[6];
        s->ca[7] = in->f[7];
        s->ca[8] = in->f[8];
        s->ca[9] = in->f[9];
        s->ca[10] = in->f[10];
        s->ca[11] = in->f[11];
        break;
    case 1:
        s->cb[0] = in->f[0];
        s->cb[1] = in->f[1];
        s->cb[2] = in->f[2];
        s->cb[3] = in->f[3];
        s->cb[4] = in->f[4];
        s->cb[5] = in->f[5];
        s->cb[6] = in->f[6];
        s->cb[7] = in->f[7];
        s->cb[8] = in->f[8];
        s->cb[9] = in->f[9];
        s->cb[10] = in->f[10];
        s->cb[11] = in->f[11];
        break;
    }
    fn_80151610((void *)s, 1);
    fn_8015181C((void *)s);
}

void fn_80158374(void *p) {
    fn_801E17E0(p);
}

void fn_801575C4(void *a) {
}

void fn_8015596C(void *p) {
    fn_80151128((Tab_80151128*)lbl_80346FB0, (Src*)p);
}

extern char lbl_802B3AFC[];
void fn_8015128C(Obj_801512DC *objs, In_801512DC *in) {
    s32 idx = in->f0;

    if (idx >= 0x80) {
        fn_8015757C((s32)lbl_802B3AFC, idx);
        return;
    }
    if (idx > 0) {
        fn_801512DC(&objs[idx], in);
    }
}

void fn_80155994(void *p) {
    fn_8015128C((void*)lbl_80346FB4, p);
}

inline BtlSlot *GetLink(s32 side, s32 i)
{
    return &lbl_80346FC8[side]->a[i];
}

void fn_801545AC(s32 side, s32 i)
{
    if (GetLink(side, i)->target != NULL) {
        lbl_80346FC8[side]->a[i].active = 1;
        lbl_80346FC8[side]->a[i].target->x1ec = 1;
    }
}

s32 fn_8015C468(s32 which, s32 i)
{
    if (which == 0) {
        return (*(RowTable **)&lbl_8034727C)->row[i].x05;
    }
    return (*(RowTable **)&lbl_8034727C)->row[i].x1D;
}

s32 fn_8015C4A0(s32 which, s32 i)
{
    if (which == 0) {
        return (*(RowTable **)&lbl_8034727C)->row[i].x00;
    }
    return (*(RowTable **)&lbl_8034727C)->row[i].x18;
}

void fn_80155D2C(void)
{
    Ent_80155AB4 *e;
    s32 i;

    memset(lbl_80346FF8, 0, sizeof(lbl_80346FF8));
    lbl_80346FF4 = 0;
    lbl_80346FF0 = 0;
    for (e = lbl_80346FF8, i = 0; i < 1; i++, e++) {
        e->id = -1;
        e->p = NULL;
    }
}

void fn_80157E04(s32 i, s32 j, u8 a0, u8 a1, u8 b0, u8 b1)
{
    if ((*(Row_80157E04 **)&lbl_80346FD0) != NULL) {
        (*(Row_80157E04 **)&lbl_80346FD0)[i].a[j][0] = a0;
        (*(Row_80157E04 **)&lbl_80346FD0)[i].a[j][1] = a1;
        (*(Row_80157E04 **)&lbl_80346FD0)[i].b[j][0] = b0;
        (*(Row_80157E04 **)&lbl_80346FD0)[i].b[j][1] = b1;
    }
}

s32 fn_80150800(Obj_80150800 *o)
{
    s32 changed;
    s32 st;
    Item *a;
    Item *b;
    s32 ia;
    s32 ib;
    Tail *tl;
    s32 t;

    changed = 0;
    tl = (Tail *)o;
    o->w4 = o->wc;
    o->wc = (*(S6 **)&lbl_80346F9C)[(s32)lbl_803472E0 - lbl_80346FC4].v;
    st = o->wc;
    if (st != o->w4 && (st == 10 || st == 20)) {
        fn_8014F970(lbl_80346FC8[0]->ship);
        fn_8014F970(lbl_80346FC8[1]->ship);
        fn_801536E0();
        tl->w64 = 0;
        tl->w68 = 0;
        o->w8 = 0;
    }
    if (st == 0) o->w1c = lbl_803472B8;
    if (st == 11) o->w1c = lbl_803472B8 ^ 1;
    if (tl->w68 != 0) {
        if (tl->w58 != 0) {
            tl->w58--;
            if (tl->w58 == 0) {
                tl->w64 = tl->w60;
                tl->w5c = 0x13;
            }
        }
        if (tl->w5c != 0) {
            tl->w5c--;
            if (tl->w5c == 0) {
                tl->w64 = 0;
                tl->w68 = 0;
            }
        }
    }
    t = tl->w64;
    if (t != 0) {
        o->w8 = t;
        st = t;
    } else if (o->w8 != 0) {
        if (o->w4 == o->wc) {
            st = o->w8;
        } else {
            o->w8 = 0;
        }
    }
    if (o->w0 != st) {
        a = NULL;
        b = NULL;
        if (st == 2) a = o->ent[o->w1c].x18;
        if (st == 0xc) a = o->ent[o->w1c].x18;
        if (st == 4) {
            ia = 0x15;
            ib = 0x16;
            b = o->ent[o->w1c].x18;
        }
        if (st == 0xe) {
            ia = 0x17;
            ib = 0x18;
            b = o->ent[o->w1c].x18;
        }
        if (b != NULL) {
            fn_80150B24((void *)(o), o->w1c, ia, ib);
        }
        if (a != NULL) {
            if (a->b28 == 0) {
                fn_8014F714(a);
                st = o->w0;
            } else {
                o->ent[o->w1c].x4 = a->w2c;
            }
        }
        if (st == 0) {
            o->ent[0].x4 = 6;
            o->ent[1].x4 = 6;
        }
        if (st != o->w0) {
            o->w0 = st;
            changed = 1;
        }
    }
    return changed;
}

extern S80158B7Ca *fn_801DB244(char *name);
extern char lbl_802B3F8C[];

void fn_80158B7C(void) {
    s32 i;

    lbl_8034702C = lbl_80347028 = fn_801DB244(lbl_802B3F8C);
    lbl_80347034 = lbl_80347030 = lbl_80347028->p4->texlist;
    fn_80227810(lbl_80347030);
    for (i = 0; i < 8; i++) {
        lbl_80306DB8[i] = 0;
    }
}

void fn_801525F8(Obj_801528AC* o, f32 x, f32 y, f32 z)
{
    if (o->f2c != 0) {
        o->model->inner->pos.x = x;
        o->model->inner->pos.y = y;
        o->model->inner->pos.z = z;
        o->model->inner->b1ec = 1;
        o->model->inner->b1ed = o->f8;
        o->model->inner->b1ee = 1;
        o->model->inner->b1ef = 0;
        o->model->inner->b1f0 = o->f48;
        o->model->inner->b1f1 = o->f0;
        o->model->inner->h22c = o->f34;
        o->model->inner->h22e = o->f50;
        o->f68->rows[o->f8].fc++;
    }
}

void fn_8015519C(KeyIn* in1, Pair* in2)
{
    Key* k = lbl_80346FE0->keys;
    Pair* p = lbl_80346FE0->pairs;
    Anim* a;
    Key* sk;
    Pair* sp;
    int i;

    if (lbl_80310B3C[34] & 0x10) {
        a = ((Handle*)fn_801552B0(fn_80212050(), in1, in2))->anim;
        sk = a->keys;
        sp = a->pairs;
        for (i = 0; i < 31; i++) {
            k->a = sk->a;
            k->b = sk->b;
            k->c = sk->c;
            p->w[0] = sp->w[0];
            p->w[1] = sp->w[1];
            if (k->c == 0) {
                return;
            }
            k++;
            sk++;
            p++;
            sp++;
        }
    } else {
        k = lbl_80346FE0->keys;
        p = lbl_80346FE0->pairs;
        for (i = 0; i < 31; i++, k++, p++) {
            k->a = 0;
            k->b = 0;
            k->c = 0;
            p->w[0] = 0;
            p->w[1] = 0;
        }
        lbl_80346FE0->x0 = 0;
    }
}

void fn_801541D8(s32 idx)
{
    BtlSide* o = lbl_80346FC8[idx];

    if (o->a[0].target != NULL && o->a[1].target != NULL && o->a[2].target != NULL && o->a[3].target != NULL) {
        o->centre.x = (o->a[0].target->ext->target.x + o->a[1].target->ext->target.x + o->a[2].target->ext->target.x + o->a[3].target->ext->target.x) / 4.0f;
        o->centre.y = (o->a[0].target->ext->target.y + o->a[1].target->ext->target.y + o->a[2].target->ext->target.y + o->a[3].target->ext->target.y) / 4.0f;
        o->centre.z = (o->a[0].target->ext->target.z + o->a[1].target->ext->target.z + o->a[2].target->ext->target.z + o->a[3].target->ext->target.z) / 4.0f;
        o->valid = 1;
    } else {
        fn_8015757C((s32)lbl_802B3C34, idx);
        o->centre.x = 0.0f;
        o->centre.y = 0.0f;
        o->centre.z = 0.0f;
        o->valid = 0;
    }
}

s32 fn_80155FF0(s32 a, s32 b, s32 bank, s32 unused) {
    return SePlay(bank, a, b);
}

void fn_80156C6C(void *m, struct Pose *p) {
    njTranslate(m, p->tx, p->ty, p->tz);
    njRotateZXY(m, p->rx, p->ry, p->rz);
}

s32 fn_8015C8F4(Owner_8015C8F4 *o, Arg_8015C8F4 *a) {
    Flags *f = o->fl;
    if (a->on) {
        f->w |= 0x10;
    } else {
        f->w &= ~0x10;
    }
    return 0;
}

s32 fn_8015C928(Owner_8015C928 *o, Arg_8015C928 *a) {
    fn_801E5EA4(o->fl->p, (s16)a->v);
    return 0;
}

void fn_80154B38(void) {
    lbl_80346FE0 = fn_801E1C7C(0x1d8);
    memset(lbl_80346FE0, 0, 0x1d8);
}

void fn_80155910(void) {
    lbl_80346FE8 = fn_801E1C7C(0x280);
    memset(lbl_80346FE8, 0, 0x280);
}

void fn_801586D4(s16 idx) {
    if (lbl_80306DB8[idx] == 0) return;
    lbl_80306DB8[idx]->f4 = 1;
    lbl_80306DB8[idx]->h6e = 0xff;
}

void fn_80153730(void) {
    if (lbl_80306758.f4 != 0) {
        if (fn_80109D74(lbl_80306758.f4c) != 0) {
            lbl_80306758.f4 = 0;
            lbl_80306758.f8 = 1;
        }
    }
}

typedef struct Ent_80153790 {
    u8 pad0[5];
    s8 f5;
    s8 f6;
    s8 f7;
    s8 f8;
    s8 f9;
    s8 fa;
    s8 fb;
    s16 fc;
    s8 fe;
    s8 ff;
    s8 f10;
} Ent_80153790;
extern Ent_80153790 *lbl_802E6608[];

u32 fn_80153790(s32 id, s32 a, s32 b)
{
    s32 r;
    s32 x;
    s32 y;
    s32 idx = (id - 10000) / 100;
    u32 obj = 0;
    Ent_80153790 *e;

    if (id == 0) {
        return 0;
    }
    e = lbl_802E6608[idx];
    if (e->f9 != 0) {
        x = lbl_80306938[idx];
        y = lbl_803067A8[idx];
        lbl_80306938[idx] = 1;
        r = x != 0 || y != 0;
        if (r) {
            return 0;
        }
    }
    if (e == 0) {
        return 0;
    }
    if (e->fa != -1) {
        obj = fn_80155FF0(7, e->fa, e->f7, e->f8);
    } else {
        if (e->f6 >= 0) {
            obj = fn_80155DB4(3, 0);
        }
        if (e->f5 >= 0) {
            obj = fn_80155AB4(e->f5);
        }
    }
    if (obj != 0) {
        fn_801677D0(obj, e->fb + 0x80, 0.0f, 0.0f, 0.0f, e->fc, e->fe, a);
        if (e->ff > 0 && (s16)b == 0) {
            fn_80154C34(e->ff, e->f10);
        }
    }
    return obj;
}

void fn_801532F0(s32 idx, s32 a, s32 b) {
    fn_80153790(lbl_802E6A40[idx]->f0, a, b);
}

void fn_801559BC(float *p) {
    f32 args[128] = {0.0f};
    f32 *a;
    s32 i;
    s32 n;

    n = *(s32 *)p++;
    for (i = 0, a = args; i < n; i++) {
        *a++ = fn_801F6120(&p);
    }
    lbl_802E6EF0[(s32)args[0]](n - 1, &args[1]);
}

void fn_801557A8(s32 i, s32 j)
{
    Rec58 *r;

    fn_80157E54(i, j);
    r = (Rec58 *)lbl_80308F98[i].p + j;
    fn_80157E04(i, j, r->x34, r->x38, r->x3c, r->x40);
}

void fn_80158590(s16 idx, s8 mode, s16 a, s16 b) {
    Obj_8015854C* o = lbl_80306DB8[idx];
    if (o == 0) return;
    if (o->flags & 0x40000000) return;
    switch (mode) {
    case 1:
        if (o->f4 == 0) {
            o->f4 = 1;
            o->h44 = 1;
            o->h6e = 0;
            o->h46 = a;
            o->h48 = b;
        }
        break;
    case 3:
        if (o->f4 == 1 && idx >= 4) {
            o->flags |= 0x40000000;
        }
    case 2:
        if (o->f4 == 1) {
            o->h44 = 2;
            o->h6e = 0xff;
            o->h46 = a;
            o->h48 = b;
        }
        break;
    }
}

s32 fn_8015CC20(KeyObj* obj, KeyStep* k) {
    KeyHolder* hold = obj->holder;
    KeyAnim* anim = hold->anim;
    KeyEnt* e = fn_8009FDA0(anim, k->idx, 0, 0, 0, 0, 0);

    if (e == 0) return 0;
    if (k->idx < 1000) e = *(KeyEnt**)((u8*)e + 0x2c);

    switch (anim->state) {
    case 0:
        if (k->duration <= 1) {
            e->x = 182.04445f * k->to[0];
            e->y = 182.04445f * k->to[1];
            e->z = 182.04445f * k->to[2];
            if (k->idx == 0) {
                hold->out[0] = 182.04445f * k->to[0];
                hold->out[1] = 182.04445f * k->to[1];
                hold->out[2] = 182.04445f * k->to[2];
            }
            return 0;
        }
        k->from[0] = 0.005493164f * (f32)e->x;
        k->from[1] = 0.005493164f * (f32)e->y;
        k->from[2] = 0.005493164f * (f32)e->z;
        {
            f32 dx = k->to[0] - k->from[0];
            f32 dy = k->to[1] - k->from[1];
            f32 dz = k->to[2] - k->from[2];
            k->to[0] = dx;
            k->to[1] = dy;
            k->to[2] = dz;
        }
        k->count = 0;
        anim->state = 1;
        /* fallthrough */
    case 1:
        if (++k->count == k->duration) {
            e->x = 182.04445f * (k->from[0] + k->to[0]);
            e->y = 182.04445f * (k->from[1] + k->to[1]);
            e->z = 182.04445f * (k->from[2] + k->to[2]);
            if (k->idx == 0) {
                hold->out[0] = e->x;
                hold->out[1] = e->y;
                hold->out[2] = e->z;
            }
            return 0;
        } else {
            f32 t = fn_80212A78(k->ease, (f32)k->count, (f32)k->duration);
            e->x = 182.04445f * (k->to[0] * t + k->from[0]);
            e->y = 182.04445f * (k->to[1] * t + k->from[1]);
            e->z = 182.04445f * (k->to[2] * t + k->from[2]);
            if (k->idx == 0) {
                hold->out[0] = e->x;
                hold->out[1] = e->y;
                hold->out[2] = e->z;
            }
        }
        break;
    }
    return 1;
}

inline s32 PadAny(PadState *p)
{
    s32 r = 0;
    if (p->slot[0].on != 0) {
        r = 1;
    } else if (p->slot[1].on != 0) {
        r = 1;
    } else if (p->slot[2].on != 0) {
        r = 1;
    } else if (p->slot[3].on != 0) {
        r = 1;
    }
    return r;
}

inline void StartSeq(s32 who)
{
    lbl_80310B3C[0x3a] &= ~1;
    if (who == 0) {
        lbl_80310A1C[0x109] = 6;
    } else {
        lbl_80310A1C[0x109] = 5;
    }
    fn_80159F28(who);
}

s32 fn_8015BB58(s32 t)
{
    s32 r = 0;

    if (t >= lbl_803472A4->t8 && t < lbl_803472A4->tc) {
        if (t == lbl_803472A4->t8) {
            r = 1;
        }
        if (lbl_80347288 == 1 && lbl_8034704C == 0) {
            fn_8015C1E4();
            lbl_8034704C = 1;
            fn_80156584();
        }
    } else if (t >= lbl_803472A4->tc && t < lbl_803472A4->t10) {
        lbl_80347044 = 0;
        lbl_80347040 = 0;
        lbl_8034703C = 0;
        if (t == lbl_803472A4->tc) {
            r = 2;
        }
    } else if (t >= lbl_803472A4->t10 && t < lbl_803472A4->t14) {
        if (t >= lbl_803472A4->t10 && t < lbl_803472A4->t10 + 60 && fn_8010CED4() != 1) {
            if (PadAny(lbl_80347050[1]) == 1 || (lbl_80310B3C[0x3a] & 1) ||
                t >= lbl_803472A4->t10 + 30) {
                lbl_8034703C = 1;
            }
            fn_8015983C(1, lbl_80347064, &lbl_80306E38[0], lbl_8034703C);
            lbl_80347040 = 1;
        } else if (lbl_80347040 == 1) {
            fn_8015983C(0, lbl_80347064, &lbl_80306E38[0], 0);
            lbl_80347040 = 0;
        }
        if ((t >= lbl_803472A4->t14 - lbl_803472DC - 10.0f && lbl_80306E38[0].xc != 0) ||
            PadAny(lbl_80347050[0]) == 1 || (lbl_80310B3C[0x3a] & 1)) {
            if (lbl_80347044 == 0) {
                StartSeq(lbl_80347064);
                lbl_80347044 = 1;
            }
        }
        if (t == lbl_803472A4->t10) {
            fn_8015A36C(lbl_80347064);
        }
        if (t == lbl_803472A4->t10) {
            r = 3;
        }
    } else if (t >= lbl_803472A4->t14 && t < lbl_803472A4->t18) {
        if (t == lbl_803472A4->t18 - 1) {
            fn_80158690(0);
            fn_80158690(1);
        }
        lbl_80347044 = 0;
        lbl_80347040 = 0;
        lbl_8034703C = 0;
        if (t == lbl_803472A4->t14) {
            r = 4;
        }
    } else if (t >= lbl_803472A4->t18 && t < lbl_803472A4->t8 + lbl_803472A4->len - 2) {
        if (t >= lbl_803472A4->t18 && t < lbl_803472A4->t18 + 60 && fn_8010CED4() != 1) {
            if (PadAny(lbl_80347050[1]) == 1 || (lbl_80310B3C[0x3a] & 1) ||
                t >= lbl_803472A4->t18 + 30) {
                lbl_8034703C = 1;
            }
            fn_8015983C(1, lbl_80347060, &lbl_80306E38[1], lbl_8034703C);
            lbl_80347040 = 1;
        } else if (lbl_80347040 == 1) {
            fn_8015983C(0, lbl_80347060, &lbl_80306E38[1], 0);
            lbl_80347040 = 0;
        }
        if ((t >= lbl_803472A4->t8 + lbl_803472A4->len - 10.0f - lbl_803472DC && lbl_80306E38[1].xc != 0) ||
            PadAny(lbl_80347050[1]) == 1 || (lbl_80310B3C[0x3a] & 1)) {
            if (lbl_80347044 == 0) {
                StartSeq(lbl_80347060);
                lbl_80347044 = 1;
            }
        }
        if (t == lbl_803472A4->t18) {
            fn_8015A36C(lbl_80347060);
        }
        if (t == lbl_803472A4->t18) {
            r = 5;
        }
    } else {
        if (t == lbl_803472A4->t8 + lbl_803472A4->len - 1.0f) {
            lbl_8034704C = 0;
            r = 0;
        }
    }
    return r;
}

s32 fn_8015D124(Obj_8015D124* o, St_8015D124* st)
{
    A_8015D124* a = o->s->a;
    f32 inv;
    f32 x;
    f32 y;
    f32 z;

    switch (a->mode) {
    case 0:
        if (st->cnt <= 1) {
            x = st->v.x;
            y = st->v.y;
            z = st->v.z;
            a->pos.z = z;
            a->pos.y = y;
            a->pos.x = x;
            return 0;
        }
        x = st->v.x - a->pos.x;
        y = st->v.y - a->pos.y;
        z = st->v.z - a->pos.z;
        inv = 1.0f / st->cnt;
        st->v.x = x * inv;
        st->v.y = y * inv;
        st->v.z = z * inv;
        a->mode = 1;
    case 1:
        {
            f32 px;
            f32 py;
            f32 pz;
            f32 vx;
            f32 vy;
            f32 vz;
            px = a->pos.x;
            vx = st->v.x;
            py = a->pos.y;
            vy = st->v.y;
            pz = a->pos.z;
            vz = st->v.z;
            a->pos.z = pz + vz;
            a->pos.y = py + vy;
            a->pos.x = px + vx;
        }
        if (st->cnt <= 1) {
            return 0;
        }
        st->cnt--;
    }
    return 1;
}

s32 fn_80155CD8(void) {
    Ent_80155AB4 *s = &lbl_80346FF8[lbl_80346FF4];
    if (s->p != NULL) {
        fn_80217830(s->p);
        s->p = NULL;
    }
}
extern void fn_801580A4(s32 *out, f32 *v);

/* (1 - c) * d, computed in double and stored as a float. */
static inline f32 Ease(f32 c, f32 d)
{
    return (1.0 - c) * d;
}

/* Degrees to an angle. */
static inline s32 DegAng(f32 d)
{
    return 65536.0f * d / 360.0f;
}

static inline s32 AngNorm(u16 a)
{
    s32 v = a;

    return v >= 0x8000 ? -(0x10000 - v) : v;
}

void fn_8015184C(Fx *o)
{
    f32 px;
    f32 py;
    f32 pz;
    f32 da0;
    f32 da1;
    f32 db0;
    f32 db1;
    f32 d;
    f32 c;
    f32 b;
    f32 a;
    f32 lx;
    f32 ly;
    f32 lz;
    s32 a2;
    s32 a1;
    s32 a0;
    s32 b0;
    s32 b1;
    s32 b2;
    s32 e0;
    s32 e1;
    NJS_POINT3 w;
    NJS_POINT3 v;
    s32 ang2[3];
    s32 dir[3];
    NJS_POINT3 dv;

    d = o->ca[4] / 100.0f;
    c = o->ca[5] / 100.0f;
    b = o->ca[9] / 100.0f;
    a = o->ca[3] / 100.0f;
    njPushMatrixEx();
    fn_80286EE8();
    fn_8028B498();
    px = o->pos->x;
    py = o->pos->y;
    pz = o->pos->z;
    v.x = o->ca[1];
    v.y = o->ca[2];
    v.z = o->ca[0];
    if (o->ofs1 != NULL) {
        v.x += o->ofs1->x;
        v.y += o->ofs1->y;
        v.z += o->ofs1->z;
    }
    if (o->ofs2 != NULL) {
        v.x += o->ofs2->x;
        v.y += o->ofs2->y;
        v.z += o->ofs2->z;
    }
    njUnitMatrix(NULL);
    njRotateZXY(NULL, o->ang[0], o->ang[1], o->ang[2]);
    njCalcPoint(NULL, &v, &w);
    px += w.x;
    py += w.y;
    pz += w.z;
    if (o->target != NULL && 0.0f != a) {
        px = a * (o->target->x - px) + px;
        py = a * (o->target->y - py) + py;
        pz = a * (o->target->z - pz) + pz;
    }
    if (o->init != 0 && 0.0 != d) {
        if (1.0 == d) {
            px = o->eye.x;
            py = o->eye.y;
            pz = o->eye.z;
        } else {
            px = (1.0 - d) * (px - o->eye.x) + o->eye.x;
            py = (1.0 - d) * (py - o->eye.y) + o->eye.y;
            pz = (1.0 - d) * (pz - o->eye.z) + o->eye.z;
        }
    }
    o->eye.x = px;
    o->eye.y = py;
    o->eye.z = pz;
    a0 = AngNorm(o->ang[0]);
    a1 = AngNorm(o->ang[1]);
    a2 = AngNorm(o->ang[2]);
    if (o->init != 0) {
        e0 = a0 - o->prev[0];
        e1 = a1 - o->prev[1];
        e0 = AngNorm(e0);
        e1 = AngNorm(e1);
        da0 = e0;
        da1 = e1;
    }
    o->prev[0] = a0;
    o->prev[1] = a1;
    o->prev[2] = a2;
    dv.x = o->target->x;
    dv.y = o->target->y;
    dv.z = o->target->z;
    dv.x -= o->pos->x;
    dv.y -= o->pos->y;
    dv.z -= o->pos->z;
    fn_801580A4(dir, &dv.x);
    b0 = AngNorm(dir[0]);
    b1 = AngNorm(dir[1]);
    b2 = AngNorm(dir[2]);
    if (o->init != 0) {
        e0 = b0 - o->dir[0];
        e1 = b1 - o->dir[1];
        db0 = AngNorm(e0);
        db1 = AngNorm(e1);
    }
    o->dir[0] = b0;
    o->dir[1] = b1;
    o->dir[2] = b2;
    if (b) {
        c *= 1.0 - b / 100.0f;
    }
    {
    s32 rot[3] = {0, 0, 0};
    NJS_POINT3 u;
    NJS_POINT3 w2;
    NJS_POINT3 d3;

    switch (o->mode) {
    case 0:
        rot[0] = a0;
        rot[1] = a1;
        rot[2] = a2;
        o->ca[6] -= 360.0f * Ease(c, da0) / 65536.0f;
        o->ca[7] -= 360.0f * Ease(c, da1) / 65536.0f;
        rot[0] = a0 + DegAng(o->ca[6]);
        rot[1] = a1 + DegAng(o->ca[7]);
        break;
    case 1:
        rot[0] = b0;
        rot[1] = b1;
        rot[2] = b2;
        o->ca[6] -= 360.0f * Ease(c, db0) / 65536.0f;
        o->ca[7] -= 360.0f * Ease(c, db1) / 65536.0f;
        rot[0] = b0 + DegAng(o->ca[6]);
        rot[1] = b1 + DegAng(o->ca[7]);
        break;
    }
    njUnitMatrix(NULL);
    njTranslate(NULL, px, py, pz);
    njRotateZXY(NULL, rot[0], rot[1], 0);
    if (b < 1.0) {
        u.x = 0.0f;
        u.y = 0.0f;
        u.z = o->ca[8];
        njCalcPoint(NULL, &u, &w2);
        if (o->init != 0 && 0.0 != b) {
            lx = (1.0 - b) * (w2.x - o->look.x) + o->look.x;
            ly = (1.0 - b) * (w2.y - o->look.y) + o->look.y;
            lz = (1.0 - b) * (w2.z - o->look.z) + o->look.z;
        } else {
            lx = w2.x;
            ly = w2.y;
            lz = w2.z;
        }
        o->look.x = lx;
        o->look.y = ly;
        o->look.z = lz;
    } else {
        lx = o->look.x;
        ly = o->look.y;
        lz = o->look.z;
    }
    ly += o->ca[10];
    d3.x = px - lx;
    d3.y = py - ly;
    d3.z = pz - lz;
    fn_801580A4(ang2, &d3.x);
    o->pose.x28.x = o->pose.x1c.x;
    o->pose.x28.y = o->pose.x1c.y;
    o->pose.x28.z = o->pose.x1c.z;
    o->pose.x1c.x = px;
    o->pose.x1c.y = py;
    o->pose.x1c.z = pz;
    o->pose.x34.x = o->pose.pos.x;
    o->pose.x34.y = o->pose.pos.y;
    o->pose.x34.z = o->pose.pos.z;
    o->pose.pos.x = lx;
    o->pose.pos.y = ly;
    o->pose.pos.z = lz;
    o->pose.ang2[0] = o->pose.ang[0];
    o->pose.ang2[1] = o->pose.ang[1];
    o->pose.ang2[2] = o->pose.ang[2];
    o->pose.ang[0] = ang2[0];
    o->pose.ang[1] = ang2[1];
    o->pose.ang[2] = ang2[2];
    o->pose.x18 = o->ca[11];
    o->init = 1;
    njPopMatrixEx();
    }
}

#ifdef NONMATCHING
typedef struct Cmd {
    s8 type;
    u8 pad1[3];
    s8 f4;
    u8 pad5[2];
    s8 f7;
    s16 h8;
    u8 padA[2];
    u32 fc;
} Cmd;
extern void fn_8012F6C4(s8 idx, u32 val);
extern char lbl_802B40D4[];
extern s8 lbl_802E7018[0x11];
extern s8 lbl_802E7008[0xf];
#endif



#ifdef NONMATCHING
s32 fn_80159948(s8 a, Arg *b, Cmd *c)
{
    s32 k;
    s32 t;
    u32 i;

    if (c->type == 4) {
        if (c->f7 == 0) {
            return 0;
        } else if (c->f7 == 4) {
            return 1;
        } else if (c->f7 != 3) {
            fn_8012F6C4(a, c->fc);
            return 2;
        } else {
            if (c->f4 != 2) {
                fn_801DBE1C(lbl_802B40D4, c->f4);
            }
            return -1;
        }
    } else if (c->type == 5) {
        k = fn_8015AAF0(c->h8);
        if (k == 1) {
            if (c->f7 == 0) {
                return 0;
            } else if (c->f7 == 4) {
                return 1;
            } else if (c->h8 == 4 || c->h8 == 5 || c->h8 == 2) {
                return -1;
            } else {
                fn_8012F6C4(a, c->fc);
                return 2;
            }
        } else if (k == 11 || k == 12 || k == 13) {
            if (c->f7 == 0) {
                return 0;
            } else if (c->f7 == 4) {
                return 1;
            } else {
                return -1;
            }
        } else {
            fn_8012F6C4(a, b->f8);
            return 3;
        }
    } else if (c->type == 1) {
        k = fn_8015AA88(c->h8);
        if (k != -1 || c->h8 == 0x1e0 || c->h8 == 0x1e1 || c->h8 == 0x1e2 || c->h8 == 0x1e3) {
            if (c->f7 == 0) {
                return 0;
            } else if (c->f7 == 4) {
                return 1;
            } else {
                fn_8012F6C4(a, c->fc);
                return 2;
            }
        } else {
            i = c->h8 - 0x1ea;
            if (i >= 0x11) {
                t = 1;
            } else {
                t = lbl_802E7018[i];
            }
            if (t == 7 || (t >= 8 && t <= 9) || t == 10) {
                fn_8012F6C4(a, b->f8);
                return 3;
            } else if ((t == 11 || t == 12 || t == 13) && c->f7 == 0) {
                return 0;
            } else {
                return -1;
            }
        }
    } else if (c->type == 2) {
        return -1;
    } else if (c->type == 7) {
        i = c->h8 - 7;
        if (i >= 0xf) {
            t = 1;
        } else {
            t = lbl_802E7008[i];
        }
        if (t == 10) {
            fn_8012F6C4(a, b->f8);
            return 3;
        } else if (t == 11 && c->f7 == 0) {
            return 0;
        } else {
            return -1;
        }
    } else {
        return -1;
    }
}
#endif












