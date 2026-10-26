#include "types.h"
#include "ninja.h"
#include "game/drawstate.h"
#include <math.h>
#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))
typedef struct { u8 pad0[4]; s32 f4; u8 pad8[4]; s32 fc; } Ev;
typedef struct { u8 pad0[0x2d8]; s32 f2d8; } Ctx;
typedef struct { u8 pad0[0x6c]; void* p6c; } Obj_8015271C;
typedef struct { s32 f0; u8 pad4; s8 f5; } Ent_UNIT0000;
typedef struct { s32 a, b; s32 c; void* p; char name[1]; } St_UNIT0000;
typedef struct { u32 idx; u32 a, b, c, d; } Src_UNIT0000;
typedef struct { u32 a, b; void* p; } E12;
typedef struct { s32 flag; u8 pad[0x10]; f32 pos[3]; s32 ints[3]; } Obj_80158200;
typedef struct {
    u32 flags;
    u8 pad4[0xe];
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
    u8 pad42[0x2a];
    s16 h6c;
    u8 pad6e[0x1ee - 0x6e];
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
typedef struct Owner { u8 pad[0x10]; u8* x10; } Owner;
typedef struct Obj_8015259C {
    u8 pad0[0x34];
    s32 x34;
    u8 pad1[4];
    s32 x3c;
    u8 pad2[0x10];
    s32 x50;
    u8 pad3[4];
    s32 x58;
    u8 pad4[0x10];
    void *x6c;
} Obj_8015259C;
typedef struct { u32 f0; s32 f4; s8 f8; u8 pad[0xb]; } Gx;
typedef struct { u32 a, b, c; } Blk;
typedef struct { Blk *p0; } Xh;
typedef struct { u8 pad[0x20]; Xh *p20; } M;
typedef struct { u8 pad[0x1c]; u32 f1c; } Src_8015DBE4;
typedef struct { u8 pad[0x1e]; s16 h1e; u8 pad2[0x78 - 0x20]; Blk b78; } State;
typedef struct { u8 pad[0x1c8]; M *p1c8; u8 pad2[0x1d8 - 0x1cc]; State *p1d8; } Self;
void fn_80153270(void *p);
void fn_80155CD8(void);
void fn_80155D74(void);
void *memcpy(void *dst, const void *src, u32 n);
void *memset(void *p, s32 c, u32 n);
extern u8 lbl_803067A8[];
extern u8 lbl_80306938[];
extern s32 lbl_80306758[];
extern u8 *lbl_80346FB8;
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
extern u32 lbl_8034702C;
extern u8 lbl_80306C98[];
extern E12 lbl_80306B14[];
extern E12 lbl_80308F98[];
extern Obj_8015854C* lbl_80306DB8[];
extern s32 lbl_8034729C;
extern u32 lbl_802E7090[];
extern s32 lbl_80346FA0;
extern s32 lbl_80346FA4;
extern s32 lbl_80346FA8;
extern s32 lbl_80346F9C;
extern s32 lbl_80346FB0;
extern s32 lbl_80346FB4;
extern u32 lbl_80346FBC;
extern u8* lbl_80346FC8[2];
extern St_UNIT0000* lbl_80347000;
extern void *lbl_80347048;
extern s32 lbl_8034746C;
extern Gx lbl_80311AC0;
extern Slot_UNIT0000_UNIT0000 lbl_80308EF8[];
extern f32 lbl_803472DC;
extern f32 lbl_803472E0;
void fn_801E17E0(s32 x);
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
void fn_80217830(void *p);
void *fn_801E1A74(s32 a, s32 size);
void fn_80153978(void);
void fn_80152284(void *p);
void fn_80154B6C(void);
void fn_801539C4(void);
void fn_80153730(void);
void fn_8014F4E8(void *p);
void fn_801DBE1C(const char *fmt, ...);
void fn_8025CB24(void *p, ...);
void fn_80158690(s16 idx);
void fn_80167690(void *p);
void fn_80150A80(u8 *p);
void fn_8014F72C(u8 *p, s32 n);
s32 fn_80156A3C(void);
void *fn_80158394(void);
void fn_80152B58(void *a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h, s32 i, s32 j, s32 k, s32 l);
void fn_8015823C(u8 *p);
void fn_80153790(s32 a, s32 b, s32 c);
void fn_8014836C(s32 a, void *b);
void fn_80148228(s32 a, void *b);
void fn_801523A4(void *p, s32 a, s32 b, s32 c, s32 d);
s32 fn_8010CED4(void);
void fn_8012F72C(s32 a);
s32 fn_8015BB58(s32 a);
void fn_8015B358(void);
s32 fn_801CC62C(void *p);
void *fn_801CC3C4(void *p);
Blk *fn_8016748C(void *a, u32 v);
void *fn_8010A164(s32 a);
s32 fn_80129CA8(void *p);
void fn_801532B4(u8 *p);
void *memset(void *d, s32 c, u32 n);
void fn_8020EFD4(void *p);
void fn_801575C4(void *a);
typedef struct Slot_80154C34 {
    s32 active;
    s16 id;
    s16 timer;
} Slot_80154C34;
extern u8 *lbl_80346FE0;
typedef struct Ent_80155AB4 {
    s32 id;
    void *p;
} Ent_80155AB4;
extern Ent_80155AB4 lbl_80346FF8[1];
extern s32 lbl_80346FF0;
extern char lbl_802B3E84[];
extern char lbl_802B3EA4[];
s32 fn_80215F8C(void *p);
void fn_80215F94(void *p);
extern char lbl_802B3EDC[];
s32 fn_80216CA4(void *p);
s32 fn_80216F1C(s32 a, s32 b);
void *memcpy(void *d, const void *s, u32 n);
void fn_8014FCF0(u8 *dst, s32 a, s32 b);
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
extern void fn_80299040(void* texlist);
extern void fn_80286EE8(void);
extern void fn_8028B498(void);
extern void fn_802974E0(void* v);
extern void fn_801E4FD4(Obj80156DA0* self);
extern void fn_801E4CB0(u16 a, void* b);
extern void njPushMatrixEx(void);
extern void njPopMatrixEx(void);
extern void njMultiMatrix(s32 a, void* m);
typedef struct {
    u8 pad0[0x10];
    s16 index;        /* 0x10 */
    s16 type;         /* 0x12 */
} Inner80159020;
typedef struct {
    u8 pad0[0x24];
    Inner80159020* inner; /* 0x24 */
} Obj80159020;
typedef struct {
    u8 pad0[0xc];
    f32 value;        /* 0x0C */
} Entry80159020;
extern f32 lbl_8034A940;
extern f32 lbl_8034A95C;
extern s32 fn_801590F4(Inner80159020* in, s32 v);
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
extern u8 *lbl_80346FD4;
extern s32 lbl_803472B8;
typedef struct Fx {
    u8 pad0[0x34];
    f32 x34, x38, x3c, x40, x44, x48, x4c, x50, x54, x58, x5c, x60;
    f32 x64, x68, x6c, x70, x74, x78, x7c, x80, x84, x88, x8c, x90;
} Fx;
extern void fn_8015184C(Fx *o);
extern void fn_80151610(Fx *o, s32 a);
typedef struct { s32 type; s32 idx; f32 a; f32 b; s32 val; s32 pad; } Ent_801540D0;
typedef struct {
    u8 pad0[0x9c];
    Ent_801540D0 e9c;
    Ent_801540D0 eb4[8];
    Ent_801540D0 e174[8];
    Ent_801540D0 e234[32];
    Ent_801540D0 e534[8];
} Base_801540D0;
void fn_80216CB4(char *s);
char *fn_8025F120(char *dst, const char *src);
typedef struct { s32 count; } Cnt;
typedef struct { u8 pad0[4]; void *arg; void (*fn)(void *); } Cb;
extern Cnt* lbl_803472A8;
extern s32 lbl_803472D0;
extern s32 lbl_80346FC4;
s32 fn_80153BBC(void);
void fn_801541D8(s32 a);
void fn_801577CC(void *p, s32 a, s32 b, s32 i);
void fn_80150258(void);
void fn_80154404(void);
void fn_801539C8(void);
typedef struct { f32 pos[3]; s32 v[3]; } Rec_80157684;
typedef struct { Rec_80157684 r[1]; } Dummy_80157684;
extern u8* lbl_80346FD4;
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
    s32 f74;
    u8 pad78[0x10];
    f32 f88;
    f32 f8c;
    u8 pad90[8];
    s32 f98;
    u8 pad9c[0x14c];
    f32 f1e8;
    s16 h1ec;
    u8 pad1ee[0xe];
    s16 h1fc;
} Sub_8015887C;
typedef struct { u8 pad[0x24]; Sub_8015887C *s; } Obj_8015887C;
extern s32 lbl_80347034;
s32 fn_80159020(void *o);
void fn_80158DB4(Obj_8015887C *o);
void fn_80158BE8(Obj_8015887C *o);
void fn_8021C62C(Sub_8015887C *s, s32 a, s32 b);
void fn_80159610(Sub_8015887C *s);
typedef struct { u8 pad[0x19]; u8 b19; } Ent_80158A80;
extern Ent_80158A80* lbl_80306D98[8];
extern void* lbl_80347028;
extern s32 lbl_80347030;
void fn_8012F744(void);
void fn_8022642C(void);
void fn_802275A4(s32 a, s32 b);
typedef struct { u8 pad0[0x10]; s32 f10; } Q;
typedef struct {
    u8 pad0[0x1c];
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
void fn_80167374(void);
typedef struct { u8 pad[0x1c]; f32 f1c; u8 pad2[0x168 - 0x20]; s16 mode; u8 pad3[0x1bc - 0x16a]; void *h1bc; } A_8015D340;
typedef struct { u32 flags; u8 pad[4]; A_8015D340 *a; } S_8015D340;
typedef struct { u8 pad[0x1bc]; void *h1bc; u8 pad2[0x1d8 - 0x1c0]; S_8015D340 *s; } Obj_8015D340;
typedef struct { u8 pad[0x1c]; u32 cnt; } St_8015D340;
void fn_802229F8(void *p);
typedef struct { u8 pad[8]; } A_8015D54C;
typedef struct {
    u8 pad0[8];
    A_8015D54C *a;
    u8 pad0b[0x94 - 0xc];
    s32 f94;
    u8 pad98[0xd8 - 0x98];
    s32 fd8;
    void *fdc;
    s32 fe0;
    u8 pade4[0x124 - 0xe4];
    s32 f124;
    void *f128;
    s32 f12c;
    u8 pad130[0x170 - 0x130];
    s32 f170;
    void *f174;
} S_8015D54C;
typedef struct { u8 pad[0x17a]; u16 h17a; u8 pad2[0x1d8 - 0x17c]; S_8015D54C *s; } Obj_8015D54C;
typedef struct { u8 pad[0x1c]; s32 kind; u32 arg; } St_8015D54C;
extern char lbl_802B42C8[];
void *fn_80167604(Obj_8015D54C *o, u32 arg);
s32 fn_80167578(A_8015D54C *a, u32 arg);
void fn_80227810(s32 h);
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
    u8 pad00[0x20];
    Ent ents[1];
} ObjHead;
typedef struct {
    u8 pad00[0x58];
    s32 x58;
    s32 x5c;
    s32 x60;
    s32 pad64;
    Ent* x68;
} Obj;
extern f32 fn_801568F8(s32, s32, f32, f32);
typedef struct {
    s32 x0;
    s32 x4;
    s32 x8;
    s32 xc;
    s32 v[9];
} Ent_80151128;
typedef struct {
    s32 x0;
    Ent_80151128 ents[1];
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
} Obj_80153060;
typedef struct Obj_80154404 Obj_80154404;
typedef struct {
    Obj_80154404* target;
    s32 x4;
    u8 pad8[0x10];
} Link_80154404;
struct Obj_80154404 {
    u8 pad00[0x184];
    Link_80154404 a[8];      /* 0x184 */
    Link_80154404 b[32];     /* 0x244 */
};
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
extern void fn_80155438(void);
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
typedef struct {
    u8 pad0[6];
    s16 x6;
    s32 x8;
    u16 xc;
    u16 xe;
    u8 pad10[4];
    Key keys[31]; /* 0x14 */
} State_80155624;
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
typedef struct { f32 x, y, z; } Vec;
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
    u8 pad0[0x1c];
    f32 x1c, x20, x24, x28, x2c, x30;
    s32 x34;
} Arg;
extern s32 fn_802254A0(f32 *p, void *q);
extern s32 fn_80224588(s32 a, Probe *p, s32 b);
extern void fn_801673D8(Obj_8015D768 *o, s32 a);
extern void fn_801671C0(Obj_8015D768 *o);
extern void fn_802135B4(Vec *v, f32 *out);
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

void fn_8014F970(u8 *self) {
    fn_80153270(self + 0x95c);
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

void fn_801515EC(u8 *p) {
    *(u32 *)(p + 0x168) = 0;
}

void fn_801515F8(u8 *p, u32 a, u32 b, u32 c, u32 d, u32 e) {
    *(u32 *)(p + 0x154) = b;
    *(u32 *)(p + 0x158) = a;
    *(u32 *)(p + 0x160) = c;
    *(u32 *)(p + 0x15c) = d;
    *(u32 *)(p + 0x164) = e;
}

void fn_801517EC(u8 *p) {
    memcpy(p + 0x34, p + 4, 0x30);
}

void fn_8015181C(u8 *p) {
    memcpy(p + 4, p + 0x34, 0x30);
}

void fn_8015271C(Obj_8015271C* o) {
    if (o->p6c != 0) {
        fn_80158374(o->p6c);
        o->p6c = 0;
    }
}

void fn_80152EE8(u8 *p, u32 v) {
    *(u32 *)(p + 0x48) = v;
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

void fn_801532B4(u8* p) {
    memset(p, 0, 0x24);
    fn_80155A8C(p + 0x10);
}

void fn_80153498(void) {
    if (lbl_80306758[2] != 0) {
        fn_80109A94((u8*)lbl_80306758 + 0xc);
    }
    lbl_80306758[2] = 0;
    lbl_80306758[0] = 0;
}

void fn_801534E8(void) {
    memset(lbl_80306758, 0, 0x50);
}

void fn_80153978(void) {
    memcpy(lbl_803067A8, lbl_80306938, 0x190);
    memset(lbl_80306938, 0, 0x190);
}

void fn_80153A04(void) {
    void* p = fn_801E1C7C(0x406);
    memset(p, 0, 0x406);
    lbl_80346FB8 = p;
}

u8 fn_80153DA8(s32 i) {
    u8 *b = lbl_80346FB8;
    return (i + b)[4];
}

void fn_80153DB8(s32 i, u8 v) {
    u8 *b = lbl_80346FB8;
    (i + b)[4] = v;
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
    fn_801E17E0((s32)lbl_80346FE8);
}

void fn_80155944(void *p) {
    fn_80150CB0(lbl_80346FAC, p);
}

void fn_80155A8C(void *p) {
    memset(p, 0, 0x14);
}

void fn_80155D74(void) {
    St_UNIT0000* o = lbl_80347000;
    if (o->p != 0) {
        fn_80217830(o->p);
        o->p = 0;
    }
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

void fn_80156250(void) {
    lbl_80346FBC = lbl_80346FBC + 1;
    fn_80153978();
    fn_80152284(lbl_80346FC8[0] + 0x604);
    fn_80152284(lbl_80346FC8[1] + 0x604);
    fn_80154B6C();
    fn_801539C4();
    fn_80153730();
}

void fn_80156324(void) {
    fn_8014F4E8(*(void**)(lbl_80346FC8[0] + 0x10));
    fn_8014F4E8(*(void**)(lbl_80346FC8[1] + 0x10));
}

s32 fn_80156A3C(void) {
    if (lbl_80347024 >= 0xFDE8) {
        fn_801DBE1C(lbl_802B3F24);
    }
    return (lbl_80347024 += 0x1e) - 0x1e;
}

void fn_80157530(s32 a, s32 b, s32 c) {
    if (lbl_80347008 == 0) {
        lbl_80347008 = (u32)lbl_80306C98;
        fn_8025CB24(lbl_80306C98, a, b, c);
    }
}

void fn_8015757C(s32 a, s32 b) {
    if (lbl_80347008 == 0) {
        lbl_80347008 = (u32)lbl_80306C98;
        fn_8025CB24(lbl_80306C98, a, b);
    }
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

void fn_80158358(u8 *p, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f) {
    *(u32 *)(p + 0x10) = a;
    *(u32 *)(p + 0x8) = b;
    *(u32 *)(p + 0xc) = e;
    *(u32 *)(p + 0x3c) = c;
    *(u32 *)(p + 0x40) = d;
    *(u32 *)(p + 0x44) = f;
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
    s32 r31;
    fn_801E17E0(lbl_80346FA0);
    fn_801E17E0(lbl_80346FA4);
    fn_801E17E0(lbl_80346FA8);
    r31 = (s32)lbl_80346FAC;
    fn_801E17E0(lbl_80346F9C);
    fn_801E17E0(r31);
    fn_801E17E0(lbl_80346FB0);
    fn_801E17E0(lbl_80346FB4);
}

void fn_80150258(void)
{
    memset((void*)lbl_80346FA0, 0, 0x1616);
    fn_80150A80((u8 *)lbl_80346FA8);
    fn_8014F72C(((Owner*)lbl_80346FC8[0])->x10 + 0x9c0, 0);
    fn_8014F72C(((Owner*)lbl_80346FC8[1])->x10 + 0x9c0, 1);
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
    fn_801523A4(lbl_80346FC8[(s32)v[0]] + 0x604, (s32)v[1], (s32)v[2], (s32)v[3], (s32)v[4]);
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

void fn_801584DC(s16 idx, u32 bits, s32 mode) {
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
    fn_8025CB24(buf, lbl_802B4104, lbl_8034746C, lbl_80311AC0.f4, lbl_80311AC0.f8);
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

void fn_8014FCF0(u8 *dst, s32 a, s32 b)
{
    s32 i;
    u8 *x = (u8 *)fn_8010A164(a);
    u8 *y = AT(u8 *, x, 0x24);

    memset(dst, 0, 0xa00);
    AT(u8 *, dst, 0) = x;
    AT(u8 *, dst, 4) = y;
    AT(u32, dst, 8) = AT(u32, y, 0x1e4);
    AT(s16, dst, 0xc) = fn_80129CA8(y);
    AT(s16, dst, 0xe) = b;
    for (i = 0; i < 2; i++) {
        fn_801532B4(dst + 0x95c + i * 0x24);
    }
    AT(s32, dst, 0x9a4) = 0;
}

void fn_80150A80(u8 *p)
{
    memset(p, 0, 0x6c);
    AT(s32, p, 0x38) = AT(s32, lbl_80346FC8[0], 0x10) + 0x9c0;
    AT(s32, p, 0x20) = 0;
    AT(s32, p, 0x54) = AT(s32, lbl_80346FC8[1], 0x10) + 0x9c0;
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
    u8 *g = lbl_80346FE0;
    Slot_80154C34 *s;
    s32 i;
    u32 cnt;

    if (g == 0) {
        return;
    }
    s = (Slot_80154C34 *)(g + 0x188);
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
            cnt = AT(u32, lbl_80346FE0, 0x10);
            if (cnt != 0) {
                s->timer = (s16)(cnt + delay);
            } else {
                s->timer = (s16)delay;
            }
            AT(u32, lbl_80346FE0, 0x10) = AT(u32, lbl_80346FE0, 0x10) + 1;
            return;
        }
        s++;
    }
}

void *fn_80155AB4(s32 id)
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
    if (AT(void *, lbl_80346FC8[a], 0x14) != 0) {
        memcpy((u8 *)lbl_80346FC8[a] + 0x1c, AT(void *, lbl_80346FC8[a], 0x14), 0x40);
        memcpy((u8 *)lbl_80346FC8[a] + 0x5c, AT(void *, lbl_80346FC8[a], 0x18), 0x40);
    } else {
        memcpy((u8 *)lbl_80346FC8[a] + 0x1c, p4, 0x40);
        memcpy((u8 *)lbl_80346FC8[a] + 0x5c, p5, 0x40);
    }
    AT(void *, lbl_80346FC8[a], 0x14) = p4;
    AT(void *, lbl_80346FC8[a], 0x18) = p5;
}

void fn_80156994(s32 a, u8 *obj, u8 *b, s32 c)
{
    void *r29 = fn_8010A164(AT(u16, obj, 0x17a));

    AT(void *, lbl_80346FC8[a], 0) = r29;
    AT(void *, lbl_80346FC8[a], 4) = obj;
    AT(s32, lbl_80346FC8[a], 8) = c;
    AT(s32, lbl_80346FC8[a], 0xc) = fn_80129CA8(obj);
    AT(u8 *, lbl_80346FC8[a], 0x10) = b;
    fn_8014FCF0(b, AT(u16, obj, 0x17a), a);
    fn_80152538((u8 *)lbl_80346FC8[a] + 0x604, a, fn_80129CA8(obj), (s32)r29);
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

s32 fn_80159020(void *p) {
    Obj80159020* self = p;
    Inner80159020* in = self->inner;
    Entry80159020* e;
    s32 r;
    if (in->type != 9) {
        r = fn_801590F4(in, 1);
        if (in->type == 5 || in->type == 3 || in->type == 7 || in->type == 10) {
            return 0;
        }
        if ((u8)r != 0) {
            e = (Entry80159020 *)lbl_80306DB8[in->index];
            if (e != 0) {
                e->value = lbl_8034A95C;
            }
        } else {
            e = (Entry80159020 *)lbl_80306DB8[in->index];
            if (e != 0) {
                e->value = lbl_8034A940;
            }
        }
        return r;
    }
    fn_801590F4(in, 0);
    return 0;
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
    s8 *p2 = (s8 *)(lbl_80346FD4 + a * 0x211a4 + lbl_80346FC0 * 0x8468 + 0x10000 - 0x7bac);
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
        o->x34 += o->x64;
        o->x38 += o->x68;
        o->x3c += o->x6c;
        o->x40 += o->x70;
        o->x44 += o->x74;
        o->x48 += o->x78;
        o->x4c += o->x7c;
        o->x50 += o->x80;
        o->x54 *= 1.0 + o->x84 - 1.0;
        o->x58 += o->x88;
        o->x5c += o->x8c;
        o->x60 *= 1.0 + o->x90 - 1.0;
        fn_80151610(o, 0);
    }
}

void fn_801540D0(s32 which, s32 type, s32 idx, s32 val, f32 a, f32 b)
{
    Ent_801540D0 *e;
    if (type != 2) {
        idx &= 7;
    }
    switch (type) {
    case 0:
        e = &((Base_801540D0 *)lbl_80346FC8[which])->e9c;
        break;
    case 1:
        e = &((Base_801540D0 *)lbl_80346FC8[which])->eb4[idx];
        break;
    case 2:
        idx &= 0x1f;
        e = &((Base_801540D0 *)lbl_80346FC8[which])->e234[idx];
        break;
    case 3:
        e = &((Base_801540D0 *)lbl_80346FC8[which])->e534[idx];
        break;
    }
    e->type = type;
    e->idx = idx;
    e->b = b;
    e->a = a;
    e->val = val;
    if (type == 2 && idx < 8) {
        Base_801540D0 *b2 = (Base_801540D0 *)lbl_80346FC8[which];
        Base_801540D0 *b3 = (Base_801540D0 *)lbl_80346FC8[which];
        b2->e174[idx] = b3->e234[idx];
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
        fn_8025F120(s->name, buf);
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
    if (((Cb *)lbl_80346FC8[0])->fn != 0) {
        ((Cb *)lbl_80346FC8[0])->fn(((Cb *)lbl_80346FC8[0])->arg);
    }
    if (((Cb *)lbl_80346FC8[1])->fn != 0) {
        ((Cb *)lbl_80346FC8[1])->fn(((Cb *)lbl_80346FC8[1])->arg);
    }
    fn_80150258();
    fn_80154404();
    fn_801539C8();
}

void fn_80157684(Rec_80157684 *out, s32 a, f32 t)
{
    u8 *base = lbl_80346FD4;
    f32 f = t + (120.0f + (lbl_803472E0 - (f32)lbl_80346FC4));
    if (base != 0 && *(s32 *)(base + 0x42348) != 0) {
        Rec_80157684 *src = (Rec_80157684 *)(base + a * 0x211a4 + lbl_80346FC0 * 0x8468 + (s32)f * 0x18);
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
        fn_801E17E0((s32)lbl_80347028);
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
        fn_80167374();
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

s32 fn_8015D340(Obj_8015D340 *o, St_8015D340 *st)
{
    S_8015D340 *s = o->s;
    A_8015D340 *a = s->a;
    if (st->cnt == 0) {
        a->f1c = 0.0f;
        s->flags &= ~8;
        s->flags &= ~0x100;
        return 0;
    }
    switch (a->mode) {
    case 0:
        fn_80167374();
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
        if ((*(Obj_80154404*(*)[2])&lbl_80346FC8)[0]->a[i].target != NULL) {
            (*(Obj_80154404*(*)[2])&lbl_80346FC8)[0]->a[i].x4 = 0;
            *(u8*)((u8*)(*(Obj_80154404*(*)[2])&lbl_80346FC8)[0]->a[i].target + 0x1EC) = 0;
        }
        if ((*(Obj_80154404*(*)[2])&lbl_80346FC8)[1]->a[i].target != NULL) {
            (*(Obj_80154404*(*)[2])&lbl_80346FC8)[1]->a[i].x4 = 0;
            *(u8*)((u8*)(*(Obj_80154404*(*)[2])&lbl_80346FC8)[1]->a[i].target + 0x1EC) = 0;
        }
    }
    for (i = 0; i < 32; i++) {
        if ((*(Obj_80154404*(*)[2])&lbl_80346FC8)[0]->b[i].target != NULL) {
            (*(Obj_80154404*(*)[2])&lbl_80346FC8)[0]->b[i].x4 = 0;
            *(u8*)((u8*)(*(Obj_80154404*(*)[2])&lbl_80346FC8)[0]->b[i].target + 0x1EC) = 0;
        }
        if ((*(Obj_80154404*(*)[2])&lbl_80346FC8)[1]->b[i].target != NULL) {
            (*(Obj_80154404*(*)[2])&lbl_80346FC8)[1]->b[i].x4 = 0;
            *(u8*)((u8*)(*(Obj_80154404*(*)[2])&lbl_80346FC8)[1]->b[i].target + 0x1EC) = 0;
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

    (*(State_80155624**)&lbl_80346FE0)->x8 = a->x4;
    (*(State_80155624**)&lbl_80346FE0)->xc = a->x8;
    (*(State_80155624**)&lbl_80346FE0)->xe = a->keys[a->x8].c;
    if ((*(State_80155624**)&lbl_80346FE0)->x6 == 0) {
        return;
    }
    src = (*(State_80155624**)&lbl_80346FE0)->keys;
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
    (*(State_80155624**)&lbl_80346FE0)->x8 = 0;
    a->x8 = 0;
    (*(State_80155624**)&lbl_80346FE0)->xc = 0;
    a->x1e = a->keys[0].a;
    a->x1f = a->keys[0].b;
    (*(State_80155624**)&lbl_80346FE0)->x6 = 0;
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
    Vec v;
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
