#include "types.h"
#include "game/camera_803119E0.h"
#include "game/save_8030B7F4.h"
#include "game/drawstate.h"
#include "game/stat_8030B4D4.h"
#include "ninja.h"
#include <dolphin/os.h>
#include "game/text.h"
#include "game/menu.h"
extern void fn_802193BC(s32 a, s32 b);
extern s32 fn_801D168C(void);
extern void fn_801D150C(s32 v);
extern s32 fn_80219B7C(void);
typedef struct Obj_UNIT0000 { u8 pad[4]; u32 count; } Obj_UNIT0000;
extern void fn_80298FE4(s32 v);
typedef void (*VoidFn)(void);
typedef struct Node_UNIT0000 {
    void *w0;
    struct Node_UNIT0000 *next;
    void *w8;
    u32 wc;
    u32 w10;
    s32 w14;
    u8 b18;
    u8 pad19[2];
    u8 b1b;
    u8 pad1c[4];
    f32 f20;
    u8 pad24[0x1c];
} Node_UNIT0000;
typedef struct Blk_UNIT0000 {
    Node_UNIT0000 *head;
    Node_UNIT0000 *cur;
    Node_UNIT0000 sentinel;
} Blk_UNIT0000;
extern Blk_UNIT0000 lbl_80311A78;
typedef struct Rec_UNIT0000 {
    u32 active;
    s32 a;
    f32 b;
    s32 c;
    s32 h;
    f32 d;
    f32 e;
    f32 f;
    f32 g;
    u8 pad[0x5c - 0x24];
} Rec_UNIT0000;
typedef struct Owner_UNIT0000 { u8 pad[0x18]; Rec_UNIT0000 *recs; } Owner_UNIT0000;
extern s32 lbl_803474A4;
extern s32 lbl_803475CC;
extern s32 lbl_80347808;
extern s32 lbl_803474A0;
extern s32 lbl_80347858;
extern s32 lbl_80347818;
extern s32 lbl_8034781C;
extern s32 lbl_8034782C;
extern void fn_801D0B2C(void);
extern u8 lbl_802D9724[];
extern void fn_80100178(u8 *p);
extern void fn_801DBE6C(s32 a);
extern void fn_801E1D94(void);
extern void fn_801D14F8(void);
extern u8 lbl_802D9730[];
extern void fn_801D0B38(s32 a);
typedef struct Blk2_UNIT0000 { s32 f0; s32 f4; s32 f8; u8 padc[0x18 - 0xc]; s32 f18; s32 f1c; } Blk2_UNIT0000;
extern Blk2_UNIT0000 lbl_803167F0;
typedef struct P_UNIT0000 { u8 pad[0x1c]; s32 f1c; } P_UNIT0000;
extern void fn_801CBBAC(f32 f);
extern void fn_801CBB9C(f32 f);
extern s32 lbl_80347EB0;
extern s32 lbl_80347EA8;
extern s32 lbl_80347EB4;
extern void fn_8028BAEC(void *p);
typedef struct Pos_UNIT0000 { u8 pad0[0x1c]; s32 f1c; s32 f20; u8 pad1[0x10]; s32 f34; } Pos_UNIT0000;
extern Pos_UNIT0000 lbl_80311970;
extern void njRotateZXY(void *m, s32 x, s32 y, s32 z);
typedef NJS_POINT3 Vec;
extern double atan2(double y, double x);
extern s32 lbl_80347520;
typedef struct Node {
    s32 (*cb)(struct Node *, struct Node *);
    u8 pad4[0xc];
    u16 mask10;
    u16 id12;
    s16 flag14;
    u8 pad16[0x2c - 0x16];
    struct Node *prev;
    struct Node *next;
} Node;
extern Node *lbl_80347524;
extern u16 lbl_8034751C;
void fn_80222964(void *p);
void fn_801E17E0(void *p);
typedef struct Rec_80225930 {
    u8 pad0[0x24];
    s16 f24;
    s16 f26;
    s16 f28;
    s16 f2a;
    s16 f2c;
    s16 f2e;
    s16 f30;
} Rec_80225930;
typedef unsigned int u32_80226240;
extern u32_80226240 lbl_80347580;
typedef unsigned int u32_80226268;
extern u32_80226268 lbl_80347588;
extern void fn_80226984(void *p);
typedef unsigned int u32_80226298;
extern u32_80226298 lbl_8034758C;
extern u32_80226298 lbl_803475A4;
typedef unsigned int u32_80226318;
extern u32_80226318 lbl_803475A4;
extern u32_80226318 lbl_80347580;
extern u32_80226318 lbl_8034758C;
typedef unsigned int u32_80226334;
extern u32_80226334 lbl_803475A8;
extern u32_80226334 lbl_80347590;
extern u32_80226334 lbl_80347594;
extern u32_80226334 lbl_80347598;
typedef int s32_80227E74;
extern s32_80227E74 lbl_803477FC;
typedef unsigned long u32_8022823C;
extern void *memset(void *dst, int c, u32_8022823C n);
typedef struct Unk_8022828C {
    int unk0;
    f32 f4;
    f32 f8;
    f32 fc;
    f32 f10;
    f32 f14;
    f32 f18;
} Unk_8022828C;
typedef struct Unk_802282A8 {
    int unk0;
    int unk4;
    int unk8;
    int unkc;
    f32 f10;
} Unk_802282A8;
typedef unsigned int u32_802282B0;
typedef unsigned int u32_80228374;
extern void fn_801E17E0(void *p);
typedef struct Unk_80228418 {
    u8 pad[0x18];
    u8 *table;
} Unk_80228418;
extern OSAlarm lbl_80316578;
extern void fn_801D8B2C(void);
extern void fn_8022642C(void);
typedef struct SoalState { u8 pad[0xc]; s32 state; } SoalState;
extern SoalState lbl_80311AD4;
typedef unsigned int u32_8022A36C;
extern u32_8022A36C lbl_80347820;
extern u32_8022A36C lbl_80347824;
extern void *memcpy(void *dst, const void *src, unsigned long n);
extern u8 lbl_803165C8[];
typedef int s32_8022B014;
extern s32_8022B014 lbl_80347508;
typedef int s32_8022B064;
extern s32_8022B064 lbl_80347508;
extern s32 fn_801DCFA0(void *a, void *b);
typedef struct Fx {
    u8 pad0[0xc];
    f32 f0c;
    f32 f10;
    f32 f14;
    f32 f18;
} Fx;
s32 fn_80225958(s32 c);
s32 fn_8022377C(void *a, void *b, s32 r, s32 c);
typedef struct Ent68 {
    u8 pad0[0x18];
    u32 *list;
    u8 pad1c[0x68 - 0x1c];
} Ent68;
typedef struct Thing {
    u8 pad0[0x24];
    s16 a24;
    s16 a26;
    s16 a28;
    s16 a2a;
    s16 a2c;
    s16 a2e;
    s16 a30;
} Thing;
void *fn_801E1C7C(u32 size);
/* A model's collision parts (lbl_8034752C: the live ones, keyed by key8). */
typedef struct Slot {
    struct Xf_80224F28 *p0;
    void *ptr4;
    u16 key8;
    s16 count;
    u8 pad[4];
} Slot;
extern Slot *lbl_8034752C;
extern s16 lbl_8034752A;
extern s16 lbl_80347528;
s16 fn_80225E58(Slot *tbl, s16 n, u32 key);
typedef struct Sub802281DC { s32 a; s32 b[8]; u8 pad[0x44 - 0x24]; s32 z44; } Sub802281DC;
typedef struct Ctx802281DC { s32 a0; s32 a4; s32 a8; Sub802281DC *sub; s32 a10; s32 a14; } Ctx802281DC;
typedef struct C2 { u8 pad[0x20]; void *p20; } C2;
typedef struct C1 { u8 pad[4]; C2 *p4; } C1;
typedef struct Z { u8 pad[8]; u32 f8; } Z;
typedef struct Y { u8 pad[4]; Z *p4; } Y;
typedef struct EntA { u8 pad[0x14]; Y *y; u8 pad18[0x68 - 0x18]; } EntA;
typedef struct TblRoot { u8 pad[4]; EntA *p4; } TblRoot;
typedef struct C0 { u8 pad[0x358]; TblRoot *p358; C1 *p35c; } C0;
extern C0 *lbl_8034784C;
extern f32 lbl_8034C640;
extern f32 lbl_8034C65C;
extern void fn_801D5DD8(void *a, s32 b, s32 c, void *p, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5, f32 f6);
typedef struct TexInner { u8 pad[0x20]; void *list; } TexInner;
typedef struct TexRoot { u8 pad[4]; TexInner *inner; } TexRoot;
typedef struct Spr { u8 pad[0x14]; f32 f14; u8 pad18[0x50 - 0x18]; } Spr;
typedef struct Obj8 { s32 pad0; s32 a4; s32 a8; } Obj8;
extern TexRoot *lbl_80347854;
extern void fn_802275A4(void *list, s32 a);
extern void fn_801CBBF8(void);
typedef struct Flags8 { u8 pad[8]; u32 f8; } Flags8;
typedef struct Ref { Flags8 *p; u8 pad[0x18 - 4]; } Ref;
extern Ref lbl_80311A60;
extern const char *lbl_802F9238[];
typedef struct Obj1E4 { u8 pad[8]; s32 a8; u8 pad2[0x10]; s32 a1c; } Obj1E4;
s32 fn_80222B30(Node *a, Node *b);
extern s32 lbl_80347848;
extern s32 fn_801D8D18(void);
typedef struct Flags88 { u8 pad[0x88]; u32 f88; } Flags88;
extern Flags88 lbl_80310B3C;
extern s32 lbl_803475D4;
extern u8 lbl_8030A794[];
extern void fn_801CAF30(void);
extern void fn_801F01E4(void);
extern void fn_801E0FD4(void *p, s32 n);
extern void fn_801F7B04(s32 a);
extern void fn_8022AFD0(void);
extern TexRoot *lbl_80347850;
extern void fn_801A372C(void);
extern u8 lbl_802D973C[];
extern u8 lbl_802D9750[];
extern TexRoot *fn_801DB244(void *p);
extern void fn_80227810(void *list);
extern void fn_801DBA58(u32 a, u32 b, u32 c);
extern void fn_801CBC30(void);
extern void fn_801CBBBC(void);
typedef struct Pos { f32 x, y, z; } Pos;
typedef struct Ang { s32 x, y, z; } Ang;
typedef struct Anim {
    u8 pad0[6];
    u16 flags;
    u8 pad8[4];
    void* motion;
    f32 frame;
    u8 pad14[0x28 - 0x14];
    Pos* pos;
    Ang* ang;
    u8 pad30[0x54 - 0x30];
    Pos lastPos;
    Ang lastAng;
} Anim;
extern s32 fn_801E7B2C(void* o, f32 frame, void* a, void* b);
extern u32 strlen(const char *s);
typedef struct NameEnt { char *name; u8 pad4[8]; } NameEnt;
typedef struct NameList { NameEnt *ents; u32 count; } NameList;
extern s32 fn_801E4BBC(s8 n);
extern void fn_8021AF94(s32 *a, void *b, s8 *list);
typedef struct Ent { u8 pad[0x20]; f32 key; } Ent;
extern Ent *lbl_80315530[];
extern s32 lbl_803477F0;
typedef struct { u8 pad0[0x54]; u32 stream; u8 pad58[8]; void *buf; u8 pad64[0x80 - 0x64]; } Stream_803148C0;
typedef struct { void *buf; u8 pad4[0xc]; s32 group; u8 pad14[0x3c - 0x14]; } Group_803148C0;
typedef struct {
    u8 pad0[0x2c0];
    Stream_803148C0 streams[4];   /* 0x2c0 */
    u8 pad4c0[0x4f4 - 0x4c0];
    u8 chorus[0x590 - 0x4f4];     /* 0x4f4 */
    u8 reverb[0x860 - 0x590];     /* 0x590 */
    Group_803148C0 groups[11];    /* 0x860 */
} Snd_803148C0;
extern Snd_803148C0 lbl_803148C0;
extern s32 lbl_803474E0;
extern void *lbl_80346720;
extern void *lbl_8034769C;
extern void sndAuxCallbackShutdownReverbHI(void *rev);
extern void sndAuxCallbackShutdownChorus(void *ch);
extern void sndSetAuxProcessingCallbacks(u8 studio, void (*auxA)(u8, void *, void *), void *userA, u8 midiA, u16 seqIDA, void (*auxB)(u8, void *, void *), void *userB, u8 midiB, u16 seqIDB);
extern void fn_80217CB0(void);
extern void sndStreamFree(u32 id);
extern void fn_80005AD8(void *heap, void *p);
extern s32 sndPopGroup(void);
extern void sndQuit(void);
typedef struct IVec { s32 x; s32 y; s32 z; } IVec;
typedef struct Obj128 {
    s32 f0;
    u8 pad4[0x8];
    s16 sc;
    u16 sd;
    u8 pad10[8];
    Vec *p18;
    Vec *p1c;
    IVec *p20;
    s32 f24;
    s32 f28;
    s32 f2c;
    s32 f30;
    s32 f34;
    Vec f38;
    f32 f44;
    u8 pad48[0x10];
    Vec vecs[3];
} Obj128;
extern void* fn_801E1A74(s32 a, s32 b);
extern f32 njScalor(Vec *v);
extern void njUnitVector(Vec *v);
extern char lbl_802D98B8[];
extern s8 lbl_8034C6C4[8];
extern s32 fn_801A28F4(s32 *p);
typedef struct Obj {
    s32 x0;
    u8 pad4[4];
    s32 x8;
    s32 xc;
    s32 x10;
    u8 pad14[8];
    s32 x1c;
} Obj;
typedef struct V3f_80224768 { f32 x, y, z; } V3f_80224768;
typedef struct V3i_80224768 { s32 x, y, z; } V3i_80224768;
typedef struct Mdl_80224768 { s32 x0; s16 x4; } Mdl_80224768;
typedef struct Obj_80224768 {
    u8 pad0[8];
    Mdl_80224768 *mdl;
    u8 padc[0x1c - 0xc];
    V3f_80224768 *pos;
    V3f_80224768 *scl;
    V3i_80224768 *rot;
    V3f_80224768 *pos2;
    V3i_80224768 *rot2;
    u8 pad_30[0x5e];
    u16 x8e;
} Obj_80224768;
typedef struct B_80224768 { u8 pad[0x24]; u16 x24;
    u8 pad_26[0x4];
    u16 x2a;
    u16 x2c;
    u16 x2e; } B_80224768;
extern void njPushMatrixEx(void);
extern void njPopMatrixEx(void);
extern void fn_80286EE8(void);
extern void fn_8028B498(void);
extern void njTranslate(void *m, f32 x, f32 y, f32 z);
extern void njScale(void *m, f32 x, f32 y, f32 z);
extern s32 fn_801D2A64(void *a, void *c, s32 d, void *b);
extern s16 fn_80223228(u16 v);
extern void fn_80297DB4(void *a, void *b, s32 c, s32 d, s32 e);
extern void fn_80297DA4(void *a, void *b, void *c, s32 d);
extern void fn_80297B5C(void *p);
typedef struct Hdr_80227D5C { u8 *base; } Hdr_80227D5C;
typedef struct Src_80227D5C {
    Hdr_80227D5C *hdr;
} Src_80227D5C;
typedef struct Arg_80227D5C { Src_80227D5C *src; s32 n; } Arg_80227D5C;
extern s32 fn_80007528(Arg_80227D5C *p);
typedef struct Cfg_80227D5C {
    u8 pad0[8];
    void *p8;
    u16 wc;
    u16 we;
    u8 pad10[1];
} Cfg_80227D5C;
typedef struct Obj_80227D5C {
    Hdr_80227D5C *hdr;
    u8 pad[4];
    void *p8;
} Obj_80227D5C;
typedef struct Sub_UNIT0000 { s32 f0; f32 f4; f32 f8; f32 fc; f32 f10; f32 f14; f32 f18; } Sub_UNIT0000;
typedef struct Ent_UNIT0000 {
    s32 active; u8 p4[4]; f32 f8; u8 pc[8];
    f32 f14; f32 f18; f32 f1c; f32 f20; f32 f24; f32 f28; f32 f2c;
    f32 f30; f32 f34; f32 f38; f32 f3c; f32 f40; f32 f44; f32 f48; u8 p4c[0x5c-0x4c];
} Ent_UNIT0000;
typedef struct Sys_UNIT0000 { s32 f0; s16 f4; s16 f6; f32 f8; f32 fc; u8 p10[4]; s16 f14; u8 p16[2]; Ent_UNIT0000 *ents; } Sys_UNIT0000;
typedef struct Slot_80219998 { u8 pad_00[0x38]; u8 x38; u8 pad39[3]; } Slot_80219998;
extern Slot_80219998 lbl_80315120[];
typedef struct {
    u8 pad0[0x12];
    s8 kind;
    u8 pad13;
    s16 x14;
    s16 x16;
    u8 a18;
    u8 a19;
    u8 pad1a[0x24 - 0x1a];
} TblC;
extern TblC lbl_802D7E4C[];
typedef struct { s16 x0; s16 x2; s8 x4; s8 x5; } Out;
typedef struct { s8 id; u8 pad1[0x17]; s16 ids[5]; } Src;
s32 fn_8021A6E8(Src* a, void* b, TblC* c);
s32 fn_8021A620(Src* a, void* b, TblC* c);
typedef struct {
    s32 type;
    u8 pad04[0x10];
    f32 x14[3];
    f32 x20[0x44 / 4];
    f32 x64[3];
} Shape;
void fn_80221E24(f32* out, f32* a);
void fn_80220B14(f32* out, f32* a, f32* b);
void fn_80221D04(f32* out, f32* a, f32* b);
void fn_80221AAC(f32* out, f32* a, f32* b);
void fn_802205E0(f32* out, f32* a, f32* b);
void fn_80221328(f32* out, f32* a, f32* b);
typedef struct { f32 x, y; } NJS_POINT2;
typedef struct {
    NJS_POINT2* p;
    u32* col;
    NJS_POINT2* tex;
    u32 num;
} NJS_POINT2COL;
extern f32 fn_801DBD9C(f32 z);
extern void fn_8000610C(NJS_POINT2COL* p, s32 n, s32 attr);
typedef struct { s16 x, y; } Pt;
typedef struct {
    Pt a;       /* 0x00 */
    Pt b;       /* 0x04 */
    s16 r[4];   /* 0x08 */
    s16 h10;    /* 0x10 */
    s16 h12;    /* 0x12 */
} Box;
typedef struct {
    u8 pad0[4];
    s32 w4;
    s32 w8;
    u8 padc[0x24 - 0xc];
    s32 w24;
    Box* box;   /* 0x28 */
    Box b;      /* 0x2c */
} Obj_8021EF80;
typedef union Shape_802226A8 {
    s32 kind;
    struct { /* kind 0: eight points */
        s32 kind;
        NJS_POINT3 src[8];
        NJS_POINT3 dst[8];
        u8 end[4];
    } box;
    struct { /* kind 1: sphere */
        s32 kind;
        NJS_POINT3 c;
        f32 r;
        NJS_POINT3 wc;
        f32 wr;
        u8 end[4];
    } sph;
    struct { /* kind 2: segment */
        s32 kind;
        NJS_POINT3 a;
        NJS_POINT3 b;
        f32 r;
        NJS_POINT3 wa;
        NJS_POINT3 wb;
        f32 wr;
        u8 end[4];
    } seg;
} Shape_802226A8;
typedef struct { Angle x, y, z; } Ang3;
typedef struct {
    u8 pad0[0x1c];
    NJS_POINT3* pos;   /* 0x1c */
    NJS_POINT3* scale; /* 0x20 */
    Ang3* ang;         /* 0x24 */
    NJS_POINT3* pos2;  /* 0x28 */
    Ang3* ang2;        /* 0x2c */
    NJS_POINT3 oPos;   /* 0x30 */
    NJS_POINT3 oScale; /* 0x3c */
    Ang3 oAng;         /* 0x48 */
    NJS_POINT3 oPos2;  /* 0x54 */
    Ang3 oAng2;        /* 0x60 */
} Obj_80223628;
extern void njInvertMatrix(NJS_MATRIX m);
typedef struct V3p {
    f32 x, y, z;
} V3p;
typedef struct A3 {
    Angle x, y, z;
} A3;
typedef struct Shape_80224F28 {
    void *p0;
    s16 kind;
} Shape_80224F28;
typedef struct Xf_80224F28 {
    u8 pad0[8];
    Shape_80224F28 *shape;
    u8 padc[0x10];
    V3p *pos;
    V3p *scale;
    A3 *rot;
    V3p *pos2;
    A3 *rot2;
    u8 pad30[0x6c - 0x30];
    s16 near[0x10];     /* 0x6c: the parts to try next when this one misses */
    s16 nnear;          /* 0x8c */
    u16 key;            /* 0x8e */
} Xf_80224F28;
/* A collision query's result: the triangle hit and what it belongs to. */
typedef struct Cmp {
    NJS_POINT3 v[3];
    u16 id;         /* 0x24 */
    u8 pad26[4];
    u16 key;        /* 0x2a */
    u8 pad2c[2];
    s16 idx;        /* 0x2e */
    u16 flags;      /* 0x30 */
    s16 w32;
} Cmp;
extern s32 fn_801D38D4(NJS_POINT3 *, void *, Cmp *);
extern s32 fn_801D3574(NJS_POINT3 *, void *, Cmp *);
extern s32 fn_801D3BC8(NJS_POINT3 *, void *, Cmp *);
extern s32 fn_801D3360(NJS_POINT3 *, void *, Cmp *);
extern s32 fn_801D30DC(NJS_POINT3 *, void *, Cmp *);
s32 fn_80224F28(Xf_80224F28 *x, NJS_POINT3 *p, Cmp *c);
s32 fn_801C812C(NJS_POINT3 *tri, f32 x, f32 z, f32 *y);
typedef struct Item {
    s32 active;
    s32 mode;
    f32 cur;
    f32 *target;
    s32 delay;
    f32 delta;
    u8 pad_18[0x4];
    f32 init;
    u8 pad_20[0x4];
    f32 prev;
    f32 a;
    f32 da;
    f32 b;
    f32 db;
    f32 c;
    f32 dc;
    s32 wave;
    f32 out;
    f32 rate;
    f32 damp;
    f32 amp;
    f32 ampcur;
    f32 phase;
} Item;
typedef struct Anim_8022842C {
    u32 flags;
    u8 pad4[2];
    s16 len;
    f32 t;
    f32 dt;
    u8 pad10[4];
    s16 count;
    u8 pad16[2];
    Item *items;
} Anim_8022842C;
extern void fn_802285AC(Item *, f32);
typedef struct Cfg {
    f32 a;
    f32 b;
    f32 c;
    f32 d;
    f32 e;
} Cfg;
typedef struct Sub {
    u8 pad0[0x34];
    f32 f34;
    f32 f38;
    f32 f3c;
    f32 f40;
    u8 pad44[0x50 - 0x44];
} Sub;
typedef struct Obj_80229BEC {
    u8 pad0[0xf4];
    u16 state;
    u8 padf6[2];
    u8 prev;
    u8 cur;
    s16 timer;
    u8 padfc[4];
    f32 fade;
    u8 pad104[0x2b8 - 0x104];
    Sub sub;
    Sub sub2;
} Obj_80229BEC;
extern Cfg lbl_802F915C[];
extern f32 lbl_8034C648;
extern f32 lbl_8034C688;
extern f32 lbl_8034C68C;
extern void fn_801D89D4(void *p, s32 a, s32 b, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5, f32 f6, f32 f7, f32 f8);
extern void fn_801D8AB4(void *p, s32 a, s32 b, f32 f1, f32 f2);
typedef struct Spec {
    u8 pad0[0x3c];
    f32 amp1;
    s32 ang1;
    f32 amp2;
    s32 ang2;
} Spec;
extern void njCalcVector(NJS_MATRIX m, NJS_POINT3 *v, NJS_POINT3 *out);
extern f32 njCos(Angle a);
typedef struct Vec3_80222838 { f32 x, y, z; } Vec3_80222838;
typedef struct Ang3_80222838 { Angle x, y, z; } Ang3_80222838;
/* A collision object: its transform is built from two translate/rotate pairs,
   then each of its `count` parts is transformed in turn. */
typedef struct Obj_80222838 {
    u8 pad0[0xc];
    s16 count;               /* 0x0c */
    u8 pade[0x18 - 0xe];
    Vec3_80222838 *pos;      /* 0x18 */
    void *parts;             /* 0x1c */
    Ang3_80222838 *rot;      /* 0x20 */
    Vec3_80222838 *pos2;     /* 0x24 */
    Ang3_80222838 *rot2;     /* 0x28 */
    u8 pad2c[0x34 - 0x2c];
    u8 data[1];              /* 0x34 */
} Obj_80222838;
extern Slot lbl_803154B0[8];
extern u32 lbl_803474C0;
extern u32 lbl_803474C4;
void fn_8022291C(void);
typedef struct Obj_80219ACC { u8 pad[0x34]; u32 flags; } Obj_80219ACC;
extern Obj_80219ACC *lbl_803477E8;
extern void fn_8023A8E0(void *p);
typedef struct Blk {
    u8 pad0[0x30];
    struct Blk *next;
} Blk;
extern void *heap_main;
extern Blk *lbl_80347804;
extern u32 lbl_80347800;
typedef struct { s32 x0, x4, x8, state; } State_80311AD4;
extern u8 lbl_802D96CC[];
extern s32 fn_8022AE94(void);
extern void fn_80228914(void);
typedef struct Link {
    u32 flags;      /* 0x00 */
    u8 pad4[0x2c - 4];
    struct Link* next; /* 0x2c */
    struct Link* sib;  /* 0x30 */
} Link;
typedef struct {
    u8 pad0[8];
    Link link;       /* 0x08 */
} Node_80222C80;
typedef struct {
    s32 w0;
    void* owner;     /* 0x04 */
    s32 w8;
    u8 padc[4];
    u32 id;          /* 0x10 */
    u8 pad14[4];
    void* v18;       /* 0x18 */
    void* v1c;       /* 0x1c */
    void* v20;       /* 0x20 */
} Inst;
typedef struct {
    u8 pad0[0x38];
    u8 v38[0xc];     /* 0x38 */
    u8 v44[0xc];     /* 0x44 */
    u8 v50[0xc];     /* 0x50 */
    u8 pad5c[0xe4 - 0x5c];
    Node_80222C80* node;      /* 0xe4 */
    u8 pade8[0x1bc - 0xe8];
    Inst* inst;      /* 0x1bc */
} Src_80222C80;
typedef struct {
    u32 on;
    s32 key;
} Res;
typedef struct {
    u8 pad0[4];
    s32 w4;
    u8 pad8[0x14 - 8];
    Res* res;        /* 0x14 */
    u8 pad18[0x24 - 0x18];
    u8 id24[0x20];   /* 0x24 */
    u8 v44[0x18];    /* 0x44 */
    u8 v5c[0xc];     /* 0x5c */
} Req;
extern u32 fn_801C8A0C(void* p);
extern Inst* fn_801C7D0C(Link* l);
extern Node_80222C80* fn_801DA4D0(s32 key);
extern void fn_80222838(void *p);
extern void fn_802229F8(Inst* i);
typedef struct List {
    u32 count;
    u32 items[1];
} List;
typedef struct Cnt {
    u32 n;
} Cnt;
typedef struct Ent_80224040 {
    u32 id;
    u32 key;
    List *list;
    u8 padc[0xc];
    Cnt *cnt;
    u8 pad1c[0x4c];
} Ent_80224040;
typedef struct Tab_80224040 {
    s32 count;
    Ent_80224040 *ents;
} Tab_80224040;
extern s16 fn_80223B88(s32, Tab_80224040 *);
extern s32 fn_80223A34(s32, u16 *);
extern void fn_801DBE1C(const char *, ...);
extern char lbl_802D9608[];
extern char lbl_802D95D4[];
typedef struct List_80224674 { Obj_80224768 *head; u8 pad4[6]; s16 count; } List_80224674;
extern Ctx802281DC *lbl_803475EC;
extern s32 lbl_803477F8;
extern s32 lbl_80347EC4;
extern struct { u8 pad[8]; s32 x8; } lbl_80311894;
extern s32 fn_80298700(Ctx802281DC *e);
extern void fn_802281DC(Ctx802281DC *e);
void fn_802979B8(void);
extern DrawState lbl_803165A0;
extern f32 lbl_8034C6A0;
extern f32 lbl_80346788;
extern f32 lbl_8034678C;
extern s32 lbl_80346E48;
extern void fn_80226170(void);
extern void fn_802281BC(s32 a);
extern void fn_8022DCC4(void);
extern void fn_801DA1C0(void);
extern void fn_8028BB90(Camera803119E0 *cam);
extern void njClipZ(f32 n, f32 f);
extern void TextReset(void);
typedef struct MenuEnt {
    u8 pad0[0x18];
    s16 a18;
    s16 a1a;
    u8 pad_1c[0x8];
    s16 v[0x6];
    u8 pad_30[0x10];
    s32 f40;
    u8 pad44[0x8];
    s16 a4c;
    s16 a4e;
    u8 pad50[0x14];
} MenuEnt;
extern MenuEnt lbl_802D6740[5];
typedef struct Seg {
    NJS_POINT3 pos;
    f32 y;          /* the ground height found */
    s16 found;
    u16 id;
    u16 group;
    u16 key;
} Seg;
s32 fn_802250E4(Slot *o, NJS_POINT3 *p, Cmp *res);
extern OSTime lbl_80347810;
extern void fn_80228948(OSAlarm* alarm, OSContext* context);
typedef struct Menu {
    s32 mode;
    u8 pad4[4];
    s32 x8;
    s32 xc;
    s32 x10;
    s32 x14;
    u8 pad18[4];
    s32 x1c;
} Menu;
extern s32 lbl_803475D0;
extern void fn_801A289C(void);

void fn_80219378(s32 a)
{
    fn_802193BC(a, 0);
    while (fn_80219B7C() != 0) {
        s32 v = fn_801D168C();
        if (v != -1) {
            fn_801D150C(v);
        }
    }
}

extern void *lbl_80346720;
extern void fn_80005AD8(void *p, void *q);
void fn_8021A044(void *p) {
    fn_80005AD8(lbl_80346720, p);
}

extern void fn_80005B50(void *p, void *q);
void fn_8021A06C(void *p) {
    fn_80005B50(lbl_80346720, p);
}

s32 fn_8021A094(void) {
    return 0;
}

void fn_8021EDE0(Obj_UNIT0000 *p, s32 n)
{
    if (p->count <= (u16)n) {
        n = (s16)(p->count - 1);
    }
    fn_80298FE4((s16)n);
}

extern u32 lbl_802F89A8[];
u32 fn_802205C8(s16 i)
{
    return lbl_802F89A8[i];
}

typedef struct { float x, y, z; } Vec3;
void fn_80221048(Vec3 *v)
{
    int i, j;
    Vec3 t1, t7, t6, t5, t4, t3, t2;

    for (i = 0; i < 7; i++) {
        for (j = i + 1; j < 8; j++) {
            if (v[i].y < v[j].y) {
                t1 = v[j];
                v[j] = v[i];
                v[i] = t1;
            }
        }
    }
    for (i = 0; i < 3; i++) {
        for (j = i + 1; j < 4; j++) {
            if (v[i].x > v[j].x) {
                t2 = v[j];
                v[j] = v[i];
                v[i] = t2;
            }
        }
    }
    for (i = 4; i < 7; i++) {
        for (j = i + 1; j < 8; j++) {
            if (v[i].x > v[j].x) {
                t3 = v[j];
                v[j] = v[i];
                v[i] = t3;
            }
        }
    }
    if (v[0].z < v[1].z) { t4 = v[1]; v[1] = v[0]; v[0] = t4; }
    if (v[2].z > v[3].z) { t5 = v[3]; v[3] = v[2]; v[2] = t5; }
    if (v[4].z < v[5].z) { t6 = v[5]; v[5] = v[4]; v[4] = t6; }
    if (v[6].z > v[7].z) { t7 = v[7]; v[7] = v[6]; v[6] = t7; }
}

void fn_802260E8(void *p)
{
    if (p) {
        VoidFn f = *(VoidFn *)p;
        if (f) {
            f();
        }
    }
}

extern u32_80226240 lbl_80347584;
void fn_80226254(void *p) {
    if (p == 0) {
        for (;;) {}
    }
    lbl_80347584 = (u32_80226240)p;
}

void fn_802262B0(void *p) {
    if (p == 0) {
        for (;;) {}
    }
    lbl_80347590 = (u32_80226298)p;
    lbl_803475A8 = (u32_80226298)p;
}

void fn_802262C8(void *p) {
    if (p == 0) {
        for (;;) {}
    }
    lbl_80347594 = (u32_80226240)p;
}

void fn_802262DC(void *p) {
    if (p == 0) {
        for (;;) {}
    }
    lbl_80347598 = (u32_80226240)p;
}

extern u32_80226240 lbl_8034759C;
void fn_802262F0(void *p) {
    if (p == 0) {
        for (;;) {}
    }
    lbl_8034759C = (u32_80226240)p;
}

extern u32_80226240 lbl_803475A0;
void fn_80226304(void *p) {
    if (p == 0) {
        for (;;) {}
    }
    lbl_803475A0 = (u32_80226240)p;
}

void *fn_80226354(void *target)
{
    Node_UNIT0000 *n = &lbl_80311A78.sentinel;
    lbl_80311A78.head = n;
    while ((n = n->next) != 0) {
        if (n == target) {
            return n;
        }
    }
    return 0;
}

void fn_802979B8(void);
extern s32 lbl_803477F4;
void fn_8022697C(s32 v) {
    lbl_803477F4 = v;
}

void fn_802281BC(s32 n) {
    fn_802979B8();
}

void fn_80228264(void *p) {
    memset(p, 0, 0x1c);
}

void fn_802287BC(Owner_UNIT0000 *o, s32 idx, s32 a, f32 b, s32 c, f32 d, f32 e, f32 f, f32 g, s32 h)
{
    Rec_UNIT0000 *r = &o->recs[idx];
    r->active = 1;
    r->a = a;
    r->b = b;
    r->c = c;
    r->d = d;
    r->e = e;
    r->f = f;
    r->g = g;
    r->h = h;
}

void fn_80228914(void) {
    lbl_803474A0 = 0;
}

void fn_80228920(s32 v) {
    lbl_803474A0 = v;
}

s32 fn_80228928(void) {
    return lbl_803474A0;
}

void fn_80228930(void) {
    lbl_80347808 = 0;
}

void fn_8022893C(void) {
    lbl_80347808 = 1;
}

void fn_80228948(OSAlarm *alarm, OSContext *context)
{
    lbl_803474A4 = lbl_803474A4 + 1;
    if (lbl_803475CC == 6 || lbl_803475CC == 7) {
        if (lbl_80347808 != 1) {
            lbl_803474A0 = lbl_803474A0 + 1;
        }
    }
}

void fn_80228A98(void)
{
    lbl_80347858 = -1;
    lbl_80347818 = 0;
    lbl_8034781C = 0;
    lbl_8034782C = 0;
    fn_801D0B2C();
}

void fn_80228AD0(void) {
}

void fn_8022A25C(void)
{
    lbl_8034782C = 1;
    fn_80100178(lbl_802D9724);
    fn_801DBE6C(6);
    fn_801E1D94();
    fn_801D14F8();
}

void fn_8022A29C(void)
{
    lbl_8034782C = 1;
    fn_80100178(lbl_802D9730);
    fn_801DBE6C(6);
    fn_801D0B38(0x5000);
    fn_801E1D94();
    fn_801D14F8();
}

extern u32 lbl_80347860;
void fn_8022AE88(void) {
    lbl_80347860 = 1;
}

void fn_8022AFD0(void)
{
    memset(&lbl_803167F0, 0, 0x20);
    lbl_803167F0.f4 = -1;
}

void fn_8022B010(void) {
}

void fn_8022B02C(P_UNIT0000 *p)
{
    fn_801CBBAC(20.0f);
    p->f1c = 4;
}

void fn_8022B07C(P_UNIT0000 *p)
{
    fn_801CBB9C(15.0f);
    p->f1c = 2;
}

void fn_8022B0B4(void) {
}

void fn_8022B960(void *p)
{
    lbl_80347EB4 = lbl_80347EB0;
    lbl_80347EA8 = 1;
    njUnitMatrix(0);
    fn_8028BAEC(p);
}

extern u8 lbl_80316810[0x20];
void fn_8022B9A8(void) {
    MemCopy(&lbl_803119E0, lbl_80316810, 0x20);
}

void fn_8022B9DC(void) {
    MemCopy(lbl_80316810, &lbl_803119E0, 0x20);
}

void fn_8022BB5C(void *a, s32 b, s32 c, s32 d)
{
    njRotateZXY(a, lbl_80311970.f1c + b, lbl_80311970.f20 + c, d);
}

void fn_8022BC24(void *a, s32 b, s32 c, s32 d)
{
    njRotateZXY(a, lbl_80311970.f1c + b, lbl_80311970.f20 + c, lbl_80311970.f34 + d);
}

s32 fn_8022BD30(Vec *a, Vec *b)
{
    f32 ang = (f32)atan2(a->z - b->z, a->x - b->x);
    return (s32)(10430.381f * ang);
}

s32 fn_8022BD80(Vec *a, Vec *b)
{
    f32 ang = (f32)atan2(a->y - b->y, a->z - b->z);
    return (s32)(10430.381f * ang);
}

s32 fn_8021A09C(s32 v) {
    s32 r = 0;
    if (v >= 0 && v < 0x2d) {
        r = 1;
    }
    return r;
}

s32 fn_8021A0DC(s32 v) {
    s32 r = 0;
    if (v >= 0x190 && v <= 0x1b7) {
        r = 1;
    }
    return r;
}

s32 fn_8021A0FC(s32 v) {
    s32 r = 0;
    if (v >= 0 && v < 5) {
        r = 1;
    }
    return r;
}

s32 fn_8021A5F0(s32 a, s32 b, u8 *p) {
    s32 r = 0;
    if (p != 0) {
        r = *(s8 *)(p + 0x19);
    }
    return r;
}

s32 fn_8021A608(s32 a, s32 b, u8 *p) {
    s32 r = 0;
    if (p != 0) {
        r = *(s8 *)(p + 0x18);
    }
    return r;
}

void fn_8022291C(void) {
    lbl_80347520 = 0;
    lbl_80347524 = 0;
    lbl_8034751C = 0;
}

void fn_80222930(void *p) {
    fn_80222964(p);
    fn_801E17E0(p);
}

void fn_80225930(s16 a, s16 b, Rec_80225930 *r) {
    r->f26 = 0;
    r->f24 = 0;
    r->f2a = b;
    r->f28 = a;
    r->f2e = -1;
    r->f2c = -1;
    r->f30 = 0;
}

void fn_80226240(void *p) {
    if (p == 0) {
        for (;;) {}
    }
    lbl_80347580 = (u32_80226240)p;
}

void fn_80226268(void *p) {
    if (p == 0) {
        for (;;) {}
    }
    lbl_80347588 = (u32_80226268)p;
    fn_80226984(p);
}

void fn_80226298(void *p) {
    if (p == 0) {
        for (;;) {}
    }
    lbl_8034758C = (u32_80226298)p;
    lbl_803475A4 = (u32_80226298)p;
}

void fn_80226318(void *p) {
    if (p == 0) {
        for (;;) {}
    }
    lbl_803475A4 = (u32_80226318)p;
    lbl_80347580 = (u32_80226318)p;
    lbl_8034758C = (u32_80226318)p;
}

void fn_80226334(void *p) {
    if (p == 0) {
        for (;;) {}
    }
    lbl_803475A8 = (u32_80226334)p;
    lbl_80347590 = (u32_80226334)p;
    lbl_80347594 = (u32_80226334)p;
    lbl_80347598 = (u32_80226334)p;
}

void fn_80227E74(void) {
    lbl_803477FC++;
}

void fn_8022823C(void *p) {
    memset(p, 0, 0x1c);
}

void fn_8022828C(Unk_8022828C *p, f32 a, f32 b, f32 c, f32 d, f32 e, f32 g) {
    p->f4 = a;
    p->f8 = b;
    p->fc = c;
    p->f10 = d;
    p->f14 = e;
    p->f18 = g;
}

void fn_802282A8(Unk_802282A8 *p, f32 a) {
    p->f10 = a;
}

void fn_802282B0(u32_802282B0 *p) {
    *p = 1;
}

void fn_80228374(u32_80228374 *p) {
    *p = 0;
    fn_801E17E0(p);
}

f32 fn_80228418(Unk_80228418 *p, int i) {
    return *(f32 *)(p->table + i * 0x5c + 8);
}

void fn_80228984(void) {
    OSCancelAlarm(&lbl_80316578);
}

void fn_80228B40(void) {
    fn_801D8B2C();
    fn_8022642C();
    lbl_80311AD4.state = 0x11;
}

void fn_8022A36C(void) {
    lbl_80311AD4.state = 6;
    lbl_80347820 = 0;
    lbl_80347824 = 0;
}

void fn_8022A7F4(void) {
    memcpy(lbl_803165C8, (void *)0x80800000, 0x204);
}

void fn_8022A824(void) {
    memcpy((void *)0x80800000, lbl_803165C8, 0x204);
}

void fn_8022B014(u8 *p) {
    if (lbl_80347508 != 0) {
        return;
    }
    *(s32_8022B014 *)(p + 0x1c) = 5;
}

void fn_8022B064(u8 *p) {
    if (lbl_80347508 != 0) {
        return;
    }
    *(s32_8022B064 *)(p + 0x1c) = 0;
}

static inline s32 InRange(s32 v)
{
    s32 r = 0;
    if (v >= 0 && v < 5) {
        r = 1;
    }
    return r;
}

static inline s32 InRange4(s32 v)
{
    s32 r = 0;
    if (v >= 0 && v < 4) {
        r = 1;
    }
    return r;
}

s32 fn_8021A83C(s8 *a, void *b)
{
    s32 ret = 0;

    if (a != NULL && b != NULL) {
        if (InRange(*a)) {
            ret = 0;
        }
    }
    return ret;
}

s32 fn_8022BA10(void *a, void *b)
{
    s32 x = fn_801DCFA0(b, a);
    return (0 <= x) ? (u16)-x : 0;
}

void fn_8021EEF4(Fx *t, s16 kind, f32 v)
{
    t->f0c = v;
    switch (kind) {
    case 1:
        t->f10 = 0.9019608f;
        t->f14 = 0.1254902f;
        t->f18 = 0.1254902f;
        break;
    case 2:
        t->f10 = 0.1254902f;
        t->f14 = 0.98039216f;
        t->f18 = 0.1254902f;
        break;
    case 3:
        t->f10 = 0.078431375f;
        t->f14 = 0.8627451f;
        t->f18 = 0.98039216f;
        break;
    default:
        t->f10 = 1.0f;
        t->f14 = 1.0f;
        t->f18 = 1.0f;
        break;
    }
}

s32 fn_802238E4(void *a, void *b, s32 c)
{
    s32 r = fn_80225958(c);
    if (r != 0) {
        return fn_8022377C(a, b, r, c);
    }
    return 0;
}

s32 fn_80223FB4(Ent68 *t, u32 key, s32 n, s32 m)
{
    Ent68 *p = t;
    s32 i;
    for (i = 0; i < n - 1; i++) {
        u32 *list = p->list;
        s32 c = list[0];
        if (c != 0) {
            u32 *it = list + 1;
            do {
                if (key == *it) {
                    return 1;
                }
                c--;
                it++;
            } while (c > 0);
        }
        p++;
    }
    {
        u32 *list = p->list;
        u32 *it;
        if (list[0] != 0) {
            it = list + 1;
            for (i = 0; i < m; i++) {
                if (key == *it) {
                    return 1;
                }
                it++;
            }
        }
    }
    return 0;
}

Thing *fn_802258BC(s16 x28, s16 x2a, s16 x30)
{
    Thing *p = (Thing *)fn_801E1C7C(0x34);
    if (p != NULL) {
        p->a26 = 0;
        p->a24 = 0;
        p->a2a = x2a;
        p->a28 = x28;
        p->a2e = -1;
        p->a2c = -1;
        p->a30 = x30;
    }
    return p;
}

void fn_80225EDC(void)
{
    Slot *s;
    s32 i;
    for (i = 0; i < lbl_8034752A; i++) {
        s = lbl_8034752C + i;
        if (s->p0 != NULL) {
            fn_801E17E0(s->ptr4);
            s->p0 = NULL;
            s->key8 = 0xFFFF;
        }
    }
    lbl_80347528 = 0;
}

s16 fn_80225F58(u32 key)
{
    Slot *s;
    s16 idx = fn_80225E58(lbl_8034752C, lbl_8034752A, key);
    if (idx >= 0) {
        s = lbl_8034752C + idx;
        fn_801E17E0(s->ptr4);
        s->p0 = NULL;
        s->key8 = 0xFFFF;
        lbl_80347528 = lbl_80347528 - 1;
    }
    return idx;
}

void fn_802281DC(Ctx802281DC *c) {
    Sub802281DC *s = c->sub;
    if (s != 0) {
        s->a = -1;
        s->b[0] = 0; s->b[1] = 0; s->b[2] = 0; s->b[3] = 0;
        s->b[4] = 0; s->b[5] = 0; s->b[6] = 0; s->b[7] = 0;
        s->z44 = 0;
    }
    c->a8 = -1;
    c->a0 = 0;
    c->a4 = 0;
    c->sub = 0;
    c->a14 = 0;
    c->a10 = 0;
}

void *fn_8022839C(s32 n) {
    u8 *p = fn_801E1C7C(n * 0x5c + 0x1c);
    memset(p, 0, 0x1c);
    memset(p, 0, n * 0x5c);
    *(s32 *)p = 1;
    *(u8 **)(p + 0x18) = p + 0x1c;
    *(s16 *)(p + 0x14) = n;
    return p;
}

f32 fn_8022975C(void *a, s32 b, s32 c, f32 x, f32 y, f32 z, f32 w) {
    fn_801D5DD8(a, b, c, lbl_8034784C->p35c->p4->p20, lbl_8034C640, lbl_8034C640, x, y, z, w);
    return lbl_8034C65C + x;
}

void fn_8022B0B8(Obj8 *o) {
    if (lbl_80347854 != 0) {
        fn_802275A4(lbl_80347854->inner->list, 1);
        fn_801E17E0(lbl_80347854);
        lbl_80347854 = 0;
    }
    fn_801CBBF8();
    fn_8022642C();
    fn_8022642C();
    if (o->a4 != -1) {
        o->a8 = o->a4;
    }
}

void fn_8022B1E4(Obj1E4 *o) {
    TextPrint(0x18, 0xf8, lbl_802F9238[23]);
    if (o->a1c == 0) {
        if (lbl_80311A60.p->f8 & 0x100) {
            o->a1c = 3;
            o->a8 = 0;
        }
    }
}

Node *fn_80223104(u16 id, Node *stop)
{
    Node *n;
    for (n = lbl_80347524; n != NULL; n = n->next) {
        if (n == stop) {
            continue;
        }
        if (n->flag14 >= 0 && id == n->id12) {
            if (fn_80222B30(stop, n) == 1) {
                return n;
            }
        }
    }
    return NULL;
}

Node *fn_80223194(u16 id, Node *stop)
{
    Node *n;
    for (n = lbl_80347524; n != NULL; n = n->next) {
        if (n == stop) {
            continue;
        }
        if (n->flag14 >= 0 && (id & n->mask10) == id) {
            if (fn_80222B30(stop, n) == 1) {
                return n;
            }
        }
    }
    return NULL;
}

void fn_80228AD4(void) {
    s32 r = fn_801D8D18();
    lbl_80347848 = r;
    if (r != -1) {
        if (r == 1) {
            lbl_80311AD4.state = 9;
        } else {
            lbl_80311AD4.state = 0x12;
            fn_801DBE6C(6);
        }
        fn_8022642C();
        fn_8022642C();
    }
    fn_8022642C();
}

void fn_80228BE4(void) {
    fn_801CAF30();
    fn_801F01E4();
    fn_801E0FD4(lbl_8030A794, 0xcc0);
    fn_801F7B04(0);
    lbl_803475D4 = 1;
    lbl_80310B3C.f88 |= 0x20;
    fn_8022AFD0();
    lbl_80311AD4.state = 0xf;
}

void fn_8022A2E4(void) {
    s32 st;
    s32 v;
    fn_802275A4(lbl_80347854->inner->list, 1);
    fn_801E17E0(lbl_80347854);
    lbl_80347854 = 0;
    fn_802275A4(lbl_80347850->inner->list, 1);
    fn_801E17E0(lbl_80347850);
    lbl_80347850 = 0;
    fn_801A372C();
    v = lbl_8034781C;
    st = (v & 1) + 7;
    lbl_8034781C = v + 1;
    lbl_80311AD4.state = st;
}

void fn_8022A548(void) {
    lbl_80347854 = fn_801DB244(lbl_802D973C);
    fn_80227810(lbl_80347854->inner->list);
    lbl_80347850 = fn_801DB244(lbl_802D9750);
    fn_80227810(lbl_80347850->inner->list);
    fn_801DBA58(0xff000000, 0xff000000, 0xff000000);
    fn_801CBC30();
    fn_801CBBBC();
    lbl_80311AD4.state = 3;
    lbl_80347820 = 0;
    lbl_80347824 = 0;
}

void fn_8022BB94(void *m, s32 x, s32 y, s32 z) {
    njRotateXYZ(m, x, y, lbl_80311970.f34 + z);
}

void fn_8022BBC4(void *m, s32 x, s32 y, s32 z) {
    njRotateXYZ(m, x, lbl_80311970.f20 + y, z);
}

void fn_8022BBF4(void *m, s32 x, s32 y, s32 z) {
    njRotateXYZ(m, lbl_80311970.f1c + x, y, z);
}

typedef struct Obj_8022394C {
    u8 pad0[0x1c];
    Vec3 *p1c;
    Vec3 *p20;
    u32 *p24;
    Vec3 *p28;
    u32 *p2c;
    Vec3 v30;
    Vec3 v3c;
    u32 w48[3];
    Vec3 v54;
    u32 w60[3];
} Obj_8022394C;

void fn_8022394C(Obj_8022394C *o)
{
    Vec3 *s = o->p1c;
    u32 *w;
    o->v30.x = s->x;
    o->v30.y = s->y;
    o->v30.z = s->z;
    s = o->p20;
    o->v3c.x = s->x;
    o->v3c.y = s->y;
    o->v3c.z = s->z;
    w = o->p24;
    o->w48[0] = w[0];
    o->w48[1] = w[1];
    o->w48[2] = w[2];
}

typedef struct Sub_802239A4 { s32 f0; s16 f4; } Sub_802239A4;
typedef struct Obj_802239A4 {
    u8 pad0[8];
    Sub_802239A4 *sub;
    u8 pad_c[0x1c - 0xc];
    Vec3 *p1c;
    Vec3 *p20;
    u32 *p24;
    Vec3 *p28;
    u32 *p2c;
    Vec3 v30;
    Vec3 v3c;
    u32 w48[3];
    Vec3 v54;
    u32 w60[3];
} Obj_802239A4;

void fn_802239A4(Obj_802239A4 *o)
{
    Vec3 *s = o->p1c;
    u32 *w;
    o->v30.x = s->x;
    o->v30.y = s->y;
    o->v30.z = s->z;
    s = o->p20;
    o->v3c.x = s->x;
    o->v3c.y = s->y;
    o->v3c.z = s->z;
    s = o->p28;
    o->v54.x = s->x;
    o->v54.y = s->y;
    o->v54.z = s->z;
    w = o->p24;
    o->w48[0] = w[0];
    o->w48[1] = w[1];
    o->w48[2] = w[2];
    w = o->p2c;
    o->w60[0] = w[0];
    o->w60[1] = w[1];
    o->w60[2] = w[2];
}

extern void (*lbl_802F91AC[])(void);
extern void fn_801A3510(void);

void fn_80228A20(void) {
    s32 st = lbl_80311AD4.state;
    if (st >= 9 && st <= 13) {
        fn_801A3510();
    }
    if (lbl_80347858 != (st = lbl_80311AD4.state)) {
        lbl_80347818 = 0;
    }
    lbl_80347858 = st;
    lbl_802F91AC[st]();
}

void fn_80223324(Anim* a) {
    if (a->motion != NULL) {
        fn_801E7B2C(a->motion, a->frame, a->pos, a->ang);
        if (a->pos->x != a->lastPos.x || a->pos->y != a->lastPos.y || a->pos->z != a->lastPos.z) {
            a->flags |= 2;
        } else if (a->ang->x != a->lastAng.x || a->ang->y != a->lastAng.y || a->ang->z != a->lastAng.z) {
            a->flags |= 2;
        }
    }
}

s32 fn_8021EE1C(NameList *l, char *s) {
    s32 i;
    s16 j;
    s16 len;
    if (l == 0 || l->ents == 0 || l->count == 0) {
        return -1;
    }
    len = strlen(s);
    for (i = 0; i < l->count; i++) {
        char *n = l->ents[i].name;
        j = 0;
        while (j < len) {
            if (n[j] != s[j]) break;
            j++;
        }
        if (j == len) {
            return i;
        }
    }
    return -1;
}

static inline void collect(s8 *out) {
    s32 i;
    s32 n;
    s8 *p;
    s8 *q;
    if (out != 0) {
        i = 0;
        n = 0;
        p = out;
        for (; i < 0x16 && n < 0x16; i++) {
            if (fn_801E4BBC((s8)i)) {
                *p = i;
                n++;
                p++;
            }
        }
        q = out + n;
        for (; n < 0x16; n++) {
            *q++ = -1;
        }
    }
}

void fn_8021B1CC(s32 *a, void *b) {
    s8 list[0x16];
    collect(list);
    fn_8021AF94(a, b, list);
}

void fn_80226AE8(Ent *e) {
    s32 i;
    s32 j;
    s32 n = lbl_803477F0;
    for (i = 0; i < n && e->key >= lbl_80315530[i]->key; i++) {
    }
    for (j = n; j > i; j--) {
        lbl_80315530[j] = lbl_80315530[j - 1];
    }
    lbl_80315530[i] = e;
    lbl_803477F0++;
}

void fn_80219C84(void) {
    Snd_803148C0 *b = &lbl_803148C0;
    s32 i;
    Stream_803148C0 *st;
    Group_803148C0 *g;
    if (lbl_803474E0 != 0) {
        sndAuxCallbackShutdownReverbHI(b->reverb);
        sndAuxCallbackShutdownChorus(b->chorus);
        sndSetAuxProcessingCallbacks(0, NULL, NULL, 0xff, 0, NULL, NULL, 0xff, 0);
        fn_80217CB0();
        for (i = 0, st = b->streams; (u32)i < 4; i++, st++) {
            sndStreamFree(st->stream);
            fn_80005AD8(lbl_80346720, st->buf);
        }
        for (i = 0, g = b->groups; i < 11; i++, g++) {
            if (g->group >= 0) {
                sndPopGroup();
                fn_80005AD8(lbl_8034769C, g->buf);
            }
        }
        sndQuit();
        lbl_803474E0 = 0;
    }
}

void fn_80222128(Vec *src) {
    Obj128 *o = fn_801E1A74(1, 0x7c);
    if (o != 0) {
        o->p18 = o->vecs;
        o->p1c = o->p18 + 1;
        o->p20 = (IVec*)(o->p1c + 1);
        o->f24 = 0;
        o->f28 = 0;
        o->p18->z = 0.0f;
        o->p18->y = 0.0f;
        o->p18->x = 0.0f;
        o->p20->z = 0;
        o->p20->y = 0;
        o->p20->x = 0;
        o->p1c->z = 1.0f;
        o->p1c->y = 1.0f;
        o->p1c->x = 1.0f;
        o->sc = 1;
        o->sd = 0xFFFF;
        o->f0 = 0;
        o->f30 = 0;
        o->f2c = 0;
        o->f38 = *src;
        o->f44 = ((f32*)src)[3];
        o->f34 = 1;
    }
}

void fn_8022C46C(Vec *p, Vec *base, f32 r) {
    Vec d;
    f32 dy;
    d.x = p->x - base->x;
    dy = p->y - base->y;
    d.y = dy;
    d.z = p->z - base->z;
    d.y = 0.0f;
    if (njScalor(&d) < r) {
        njUnitVector(&d);
        p->x = d.x * r;
        p->y = d.y * r;
        p->z = d.z * r;
        p->y = dy;
        p->x += base->x;
        p->y += base->y;
        p->z += base->z;
    }
}

void fn_8022B6F4(Obj *o) {
    char *b = lbl_802D98B8;
    if (o->xc == 7) {
        TextPrintf(0x18, 0xc8, b + 0x5d4, lbl_8034C6C4[o->x10]);
        TextPrint(0x18, 0x110, b + 0x624);
        TextPrint(0x18, 0x158, b + 0x678);
        TextPrint(0x18, 0x188, b + 0x6a8);
    } else {
        TextPrint(0x18, 0x140, lbl_802F9238[18]);
    }
    o->xc = fn_801A28F4(&o->x10);
    if (o->xc != 0 && o->xc != 7) {
        o->x0 = 2;
    } else if (o->x1c == 0) {
        if (lbl_80311A60.p->f8 & 0x100) {
            o->x1c = 3;
            o->x8 = 0;
        }
    }
}

s32 fn_80224768(void *a, B_80224768 *b, void *c, Obj_80224768 *o) {
    Mdl_80224768 *m = o->mdl;
    s32 r;
    if (m == 0) {
        return 0;
    }
    if (m->x4 == 2) {
        njPushMatrixEx();
        fn_80286EE8();
        fn_8028B498();
        njUnitMatrix(0);
        njTranslate(0, o->pos->x, o->pos->y, o->pos->z);
        njRotateZXY(0, o->rot->x, o->rot->y, o->rot->z);
        njScale(0, o->scl->x, o->scl->y, o->scl->z);
        njTranslate(0, o->pos2->x, o->pos2->y, o->pos2->z);
        njRotateZXY(0, o->rot2->x, o->rot2->y, o->rot2->z);
        r = fn_801D2A64(a, c, m->x0, b);
        njPopMatrixEx();
        if (r != 0) {
            b->x24 = fn_80223228(b->x24);
        }
    } else {
        r = 0;
    }
    return r;
}

s32 fn_80227D5C(Obj_80227D5C *obj, void *dst, Cfg_80227D5C *cfg) {
    u8 tmp[0x50];
    Arg_80227D5C arg;
    Hdr_80227D5C *h;
    s8 *p;
    s32 i;
    s32 found;
    s32 ret;
    fn_80297DB4(tmp, (u8 *)cfg + 0x10, (s32)cfg->p8, cfg->wc, cfg->we);
    fn_80297DA4((void *)obj, tmp, dst, 0x40800000);
    h = obj->hdr;
    i = 0;
    found = 0;
    do {
        p = (s8 *)h->base - i;
        if (p[0] == 'G' && p[1] == 'V' && p[2] == 'R' && p[3] == 'T') {
            found = 1;
        } else {
            i += 0x10;
        }
    } while (!found && (u32)i <= 0x20);
    if (found) {
        h->base -= i + 0x10;
    }
    arg.src = (Src_80227D5C *)obj;
    arg.n = 1;
    ret = fn_80007528(&arg);
    if (ret == -1) {
        fn_80297B5C(dst);
        obj->p8 = 0;
    }
    return ret;
}

void fn_802287F4(Sys_UNIT0000 *o, s32 n, f32 g)
{
    Ent_UNIT0000 *e = o->ents;
    Sub_UNIT0000 *s = (Sub_UNIT0000 *)&e->f40;
    s32 i;
    s32 cnt = o->f14;
    o->f0 = 1;
    o->f6 = n;
    o->f8 = 0.0f;
    o->fc = g;
    for (i = 0; i < cnt; i++, e++) {
        if (e->active != 0) {
            f32 d;
            e->f2c = g * ((e->f1c - e->f8) / (f32)n);
            e->f24 = e->f8;
            e->f28 = e->f8;
            d = e->f18 - e->f14;
            if (d) {
                e->f14 = e->f18;
                if (s->f8) {
                    s->f4 = 0.0f;
                    s->f14 = 1.0f;
                    s->f10 = -d;
                    s->f18 = 0.0f;
                    s->f0 = 1;
                }
            }
            e->f34 = e->f14;
            e->f30 = e->f8;
            e->f3c = e->f20;
            e->f38 = e->f1c - e->f3c * (f32)n;
        }
    }
}

s32 fn_80219998(const u8 *path)
{
    s32 id = 0;
    const u8 *name = path;
    s32 val = 0x7f;
    while ((s8)*path != 0) {
        if ((s32)*path++ == '/') name = path;
    }
    switch ((s8)*name) {
    case 't':
        id = 0;
        break;
    case 'S':
    case 's':
        if ((s32)name[1] == '1') {
            id = 1;
            val = 0x78;
        } else {
            id = 9;
        }
        break;
    case 'M':
    case 'm':
        if ((s32)name[1] == '5') {
            id = 5;
        } else if ((s8)name[2] >= '2' && (s8)name[2] <= '4') {
            id = (s8)name[2] - '0';
            val = 100;
        }
        break;
    case 'E':
    case 'e':
        id = 6;
        break;
    case 'C':
    case 'c':
        id = ((s8)name[2] == '0') ? 11 : 10;
        break;
    case 'B':
    case 'b':
        id = 7;
        break;
    case 'F':
    case 'f':
        id = ((s32)name[1] == '3') ? 3 : 7;
        break;
    case 'K':
    case 'k':
        if ((s32)name[1] == '8') id = 8;
        break;
    }
    lbl_80315120[id].x38 = val;
    return id;
}

static inline s32 valid_slot(s32 i) { return i >= 0 && i < 5; }
static inline s32 valid_id(s32 i) { return i >= 0x190 && i <= 0x1b7; }

void fn_8021AE68(Out* out, Src* src, void* b, s32 slot)
{
    s32 id;
    TblC* t;
    if (out == 0) return;
    if (src == 0 || !valid_slot(slot) || !valid_id(id = src->ids[slot])) {
        if (out != 0) {
            out->x0 = 0;
            out->x2 = 0;
            out->x4 = 0;
            out->x5 = 0;
        }
        return;
    }
    t = &lbl_802D7E4C[id - 0x190];
    out->x0 = fn_8021A6E8(src, b, t);
    out->x2 = fn_8021A620(src, b, t);
    {
        s8 v = 0;
        if (t) v = t->a18;
        out->x4 = v;
    }
    {
        s8 v = 0;
        if (t) v = t->a19;
        out->x5 = v;
    }
}

void fn_80221EDC(f32* out, Shape* a, Shape* b)
{
    switch (a->type) {
    case 0:
        fn_80221E24(out, a->x64);
        break;
    case 1:
        switch (b->type) {
        case 0:
            fn_80220B14(out, a->x14, b->x64);
            break;
        case 1:
            fn_80221D04(out, a->x14, b->x14);
            break;
        case 2:
            fn_80221AAC(out, a->x14, b->x20);
            break;
        }
        break;
    case 2:
        switch (b->type) {
        case 0:
            fn_802205E0(out, a->x20, b->x64);
            break;
        case 1:
            fn_80221AAC(out, b->x14, a->x20);
            out[0] *= -1.0f;
            out[1] *= -1.0f;
            out[2] *= -1.0f;
            break;
        case 2:
            fn_80221328(out, a->x20, b->x20);
            break;
        }
        break;
    }
}

extern s32 fn_8021A2B0(Src* a, void* b, s32 code);

s32 fn_8021A620(Src* a, void* b, TblC* c)
{
    s32 ret = 0;
    if (c != NULL) {
        ret = c->x16;
    }
    if (c != NULL && a != NULL && b != NULL) {
        s32 k = c->kind;
        if (InRange4(k)) {
            s32 code;
            switch (k) {
            case 0:
                code = 0x31;
                break;
            case 1:
                code = 0x41;
                break;
            case 2:
                code = 0x51;
                break;
            case 3:
                code = 0x61;
                break;
            default:
                code = 0x62;
                break;
            }
            ret += fn_8021A2B0(a, b, code);
        }
    }
    return ret;
}

extern s32 fn_8021A2B0(Src* a, void* b, s32 code);

s32 fn_8021A6E8(Src* a, void* b, TblC* c)
{
    s32 ret = 0;
    if (c != NULL) {
        ret = c->x14;
    }
    if (c != NULL && a != NULL && b != NULL) {
        s32 k = c->kind;
        if (InRange4(k)) {
            s32 code;
            switch (k) {
            case 0:
                code = 0x30;
                break;
            case 1:
                code = 0x40;
                break;
            case 2:
                code = 0x50;
                break;
            case 3:
                code = 0x60;
                break;
            default:
                code = 0x62;
                break;
            }
            ret += fn_8021A2B0(a, b, code);
        }
    }
    return ret;
}

void fn_80221D04(f32 *out, f32 *a, f32 *b) {
    Vec d;
    d.x = a[0] - b[0];
    d.y = a[1] - b[1];
    d.z = a[2] - b[2];
    if (0.0f == d.x && 0.0f == d.y && 0.0f == d.z) {
        out[2] = 0.0f;
        out[1] = 0.0f;
        out[0] = 0.0f;
    } else {
        f32 s;
        njUnitVector(&d);
        s = 0.1f + (a[3] + b[3]);
        d.x = d.x * s;
        d.y = d.y * s;
        d.z = d.z * s;
        out[0] = (b[0] + d.x) - a[0];
        out[1] = (b[1] + d.y) - a[1];
        out[2] = (b[2] + d.z) - a[2];
    }
}

extern void fn_801D25DC(s32 v);

void fn_802233EC(Obj_802239A4 *o) {
    Sub_802239A4 *s = o->sub;
    if (s != 0 && s->f4 == 2) {
        njPushMatrixEx();
        fn_80286EE8();
        fn_8028B498();
        njUnitMatrix(0);
        njTranslate(0, o->p1c->x, o->p1c->y, o->p1c->z);
        njRotateZXY(0, o->p24[0], o->p24[1], o->p24[2]);
        njScale(0, o->p20->x, o->p20->y, o->p20->z);
        njTranslate(0, o->p28->x, o->p28->y, o->p28->z);
        njRotateZXY(0, o->p2c[0], o->p2c[1], o->p2c[2]);
        fn_801D25DC(s->f0);
        njPopMatrixEx();
    }
    fn_802239A4(o);
}

Node *fn_80222F14(Node *self, Node *head) {
    Node *n;
    for (n = head->next; n != NULL; n = n->next) {
        if (n == self) {
            continue;
        }
        if (n->flag14 >= 0 && fn_80222B30(self, n) == 1) {
            if (self->cb != NULL) {
                if (self->cb(self, n) != 0) {
                    self->flag14 |= 0x4000;
                }
            } else {
                self->flag14 |= 0x4000;
            }
            if (n->cb != NULL) {
                if (n->cb(n, self) != 0) {
                    n->flag14 |= 0x4000;
                }
            } else {
                n->flag14 |= 0x4000;
            }
            return n;
        }
    }
    return NULL;
}

Node *fn_8022300C(Node *self) {
    Node *n;
    for (n = lbl_80347524; n != NULL; n = n->next) {
        if (n == self) {
            continue;
        }
        if (n->flag14 >= 0 && fn_80222B30(self, n) == 1) {
            if (self->cb != NULL) {
                if (self->cb(self, n) != 0) {
                    self->flag14 |= 0x4000;
                }
            } else {
                self->flag14 |= 0x4000;
            }
            if (n->cb != NULL) {
                if (n->cb(n, self) != 0) {
                    n->flag14 |= 0x4000;
                }
            } else {
                n->flag14 |= 0x4000;
            }
            return n;
        }
    }
    return NULL;
}

typedef struct Screen8022BC64 {
    u8 pad00[8];
    f32 x08, x0c;
    u8 pad10[8];
    f32 z;
    u8 pad1c[0xc];
    f32 x28, x2c;
} Screen8022BC64;
extern Screen8022BC64 lbl_803118AC;
extern f32 lbl_80347570;
extern void njSetScreen(Screen8022BC64 *s);

void fn_8022BC64(void)
{
    s32 v;
    lbl_803118AC.z = 500.0f;
    lbl_803118AC.x28 = 640.0f;
    lbl_803118AC.x2c = 480.0f;
    lbl_803118AC.x08 = 320.0f;
    lbl_803118AC.x0c = 240.0f;
    v = (s32)(10430.381f * (f32)atan2(320.0, 500.0));
    lbl_80347570 = 0.005493164f * (f32)((v << 1) & 0xffff);
    njSetScreen(&lbl_803118AC);
    lbl_803119E0.x1a = (s16)(182.04445f * lbl_80347570);
}

extern void fn_801CBBD8(void);

s32 fn_8022A728(u32_8022A36C *state, u32_8022A36C *cnt, s32 lim)
{
    s32 ret = 0;
    switch (*state) {
    case 0:
        *state = *state + 1;
        fn_801CBBD8();
        fn_801CBB9C(15.0f);
        break;
    case 1:
        if (lbl_80347508 != 1) {
            *state = *state + 1;
        }
        break;
    case 2:
        *cnt = *cnt + 1;
        if (*cnt > lim) {
            *state = *state + 1;
            fn_801CBBAC(15.0f);
        }
        break;
    case 3:
        if (lbl_80347508 != 1) {
            ret = 1;
        }
        break;
    }
    fn_8022642C();
    return ret;
}

typedef struct Sub_80222010 { f32 x, y, z; } Sub_80222010;
typedef struct V3_80222010 { s32 a, b, c; } V3_80222010;
typedef struct Rec_80222010 {
    s32 f0;
    u8 pad4[8];
    s16 fc;
    u16 fe;
    u8 pad10[8];
    Sub_80222010 *p18;
    Sub_80222010 *p1c;
    Sub_80222010 *p20;
    s32 f24;
    s32 f28;
    s32 f2c;
    s32 f30;
    s32 f34;
    V3_80222010 v38;
    V3_80222010 v44;
    f32 f50;
    u8 pad54[0x94 - 0x54];
} Rec_80222010;
typedef struct In_80222010 { V3_80222010 v; V3_80222010 w; f32 g; } In_80222010;

void fn_80222010(In_80222010 *in) {
    Rec_80222010 *r = fn_801E1A74(1, 0x94);
    if (r) {
        r->p18 = (Sub_80222010 *)((u8 *)r + 0x70);
        r->p1c = (Sub_80222010 *)((u8 *)r->p18 + 0xc);
        r->p20 = (Sub_80222010 *)((u8 *)r->p1c + 0xc);
        r->f24 = 0;
        r->f28 = 0;
        r->p18->z = 0.0f;
        r->p18->y = 0.0f;
        r->p18->x = 0.0f;
        *(s32 *)&r->p20->z = 0;
        *(s32 *)&r->p20->y = 0;
        *(s32 *)&r->p20->x = 0;
        r->p1c->z = 1.0f;
        r->p1c->y = 1.0f;
        r->p1c->x = 1.0f;
        r->fc = 1;
        r->fe = 0xFFFF;
        r->f0 = 0;
        r->f30 = 0;
        r->f2c = 0;
        r->v38 = in->v;
        r->v44 = in->w;
        r->f50 = in->g;
        r->f34 = 2;
    }
}

/* A height probe: the ceiling and floor found above and below pos, with their triangle id,
 * part key and model key. */
typedef struct Arr {
    NJS_POINT3 pos;
    f32 ceil;
    f32 floor;
    s16 hasCeil;    /* 0x14 */
    s16 hasFloor;
    u16 ceilId;
    u16 floorId;
    u16 ceilGrp;
    u16 ceilKey;
    u16 floorGrp;
    u16 floorKey;
} Arr;
extern void fn_802241B0(Slot* s, Arr* a, s32 n);

s32 fn_8022436C(u32 id, Arr* arr, s32 count)
{
    Slot* s;
    Arr* q;
    s32 n;
    s32 ret;
    s32 i;
    u32 key;
    if (count <= 0) {
        return 0;
    }
    i = count;
    q = arr;
    do {
        q->hasFloor = 0;
        q->hasCeil = 0;
        q++;
    } while (--i > 0);
    key = (u16)id;
    s = lbl_8034752C;
    n = lbl_80347528;
    ret = 0;
    if (key == 0xffff) {
        do {
            if (s->p0 != 0) {
                fn_802241B0(s, arr, count);
                ret = 1;
                n--;
            }
            s++;
        } while (n > 0);
    } else {
        do {
            if (s->p0 != 0 && key == s->key8) {
                fn_802241B0(s, arr, count);
                return 1;
            }
            s++;
        } while (n > 0);
    }
    return ret;
}

static inline void fill(s8 *out) {
    if (out != 0) {
        s32 i = 0;
        s32 n = 0;
        s8 *p = out;
        while (i < 22 && n < 22) {
            if (fn_801E4BBC(i) != 0) {
                *p = i;
                n++;
                p++;
            }
            i++;
        }
        p = out + n;
        for (; n < 22; n++) {
            *p++ = -1;
        }
    }
}

void fn_8021B2B4(void) {
    s8 buf[22];
    fill(buf);
    fn_8021AF94(&lbl_8030B4D4.limit, &lbl_8030B7F4.b1568, buf);
}

typedef struct { f32 x, y, z; u32 colour; } VertexCol;
extern u32_8022A36C lbl_80347828;
extern VertexCol lbl_802F911C[4];
extern DrawState lbl_803165A0;
extern Spr lbl_802F9038;
extern void fn_80290ED4(VertexCol* v, s32 count, s32 flag);
extern void fn_80296ED4(s32 v);
extern s32 fn_8022A854(u32_8022A36C* p);

void fn_8022A38C(void) {
    s32 r;
    fn_80290ED4(lbl_802F911C, 4, 0);
    DrawStatePush(&lbl_803165A0);
    fn_80296ED4(0x2000);
    lbl_802F9038.f14 = 37.0f;
    fn_801D5DD8(&lbl_802F9038, 0, 0, lbl_80347854->inner->list, 1.1f, 1.0f, -1000.0f, 0.0f, 1.0f, 1.0f);
    DrawStatePop(&lbl_803165A0);
    r = fn_8022A854(&lbl_80347828);
    if (fn_8022A728(&lbl_80347820, &lbl_80347824, 0x96) != 0 && r != 0) {
        lbl_80311AD4.state = 5;
        lbl_80347820 = 0;
        lbl_80347824 = 0;
    }
}

extern Spr lbl_802F8FE8;
extern s32 FontUpdate(void);

void fn_8022A46C(void) {
    s32 r;
    fn_80290ED4(lbl_802F911C, 4, 0);
    DrawStatePush(&lbl_803165A0);
    fn_80296ED4(0x2000);
    lbl_802F8FE8.f14 = 140.0f;
    fn_801D5DD8(&lbl_802F8FE8, 0, 0, lbl_80347854->inner->list, 1.1f, 1.0f, -1000.0f, 0.0f, 1.0f, 1.0f);
    DrawStatePop(&lbl_803165A0);
    r = FontUpdate();
    if (fn_8022A728(&lbl_80347820, &lbl_80347824, 0x96) != 0 && r != 0) {
        lbl_80311AD4.state = 4;
        lbl_80347820 = 0;
        lbl_80347824 = 0;
    }
}

void fn_80229D74(void) {
    u16 i;
    fn_8022642C();
    fn_8022642C();
    fn_8022642C();
    if (lbl_8034784C->p35c != 0) {
        fn_802275A4(lbl_8034784C->p35c->p4->p20, 1);
        fn_801E17E0(lbl_8034784C->p35c);
        lbl_8034784C->p35c = 0;
    }
    for (i = 0; i < 5; i++) {
        fn_802275A4(&lbl_8034784C->p358->p4[i].y->p4->f8, 1);
    }
    fn_801E17E0(lbl_8034784C->p358);
    lbl_8034784C->p358 = 0;
    fn_801CBBF8();
    fn_8022642C();
    fn_8022642C();
    fn_8022642C();
    fn_8022642C();
    fn_8022642C();
    fn_8022642C();
}

typedef struct { f32 pad; f32 r; } Lim_8022C364;

s32 fn_8022C364(NJS_POINT3 *out, NJS_POINT3 *a, NJS_POINT3 *b, Lim_8022C364 *lim) {
    NJS_VECTOR d;
    s32 ret = 0;
    d.x = a->x - b->x;
    d.y = a->y - b->y;
    d.z = a->z - b->z;
    if (njScalor(&d) > lim->r) {
        njUnitVector(&d);
        out->x = d.x * lim->r;
        out->y = d.y * lim->r;
        out->z = d.z * lim->r;
        out->x = b->x + out->x;
        out->y = b->y + out->y;
        out->z = b->z + out->z;
    } else {
        ret = 1;
        out->x = a->x;
        out->y = a->y;
        out->z = a->z;
    }
    return ret;
}

void fn_80226848(Node_UNIT0000 *a, void *b, u32 c)
{
    Node_UNIT0000 *n = fn_801E1A74(1, c + 0x40);
    if (n != NULL) {
        Node_UNIT0000 *t;
        n->f20 = 0.0f;
        t = lbl_80311A78.cur;
        n->next = t->next;
        t->next = n;
        lbl_80311A78.cur = n;
        n->w0 = b;
        n->w8 = a;
        n->w10 = c;
        n->w14 = a->w14;
        n->b18 = 0;
        n->b1b = a->b1b + 1;
    }
}

typedef struct {
    u16 a;
    u16 pad;
    f32 b;
    f32 c;
    f32 d;
    s32 e;
    s32 f;
    f32 g;
    f32 h;
    s32 i;
    s32 j;
    s32 k;
    s32 l;
    s32 m;
    f32 n;
    f32 o;
    f32 p;
    f32 q;
    f32 r;
    f32 s;
} Obj7A28;
extern f32 lbl_80345878[];
extern void (*lbl_802F929C[])(Blk2_UNIT0000*);
extern void (*lbl_802F92BC[])(Blk2_UNIT0000*);
void fn_801D7A28(Obj7A28* obj, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5, f32 f6, f32 f7);
void fn_801D7C44(void* list, Obj7A28* obj);
void TextSetColor(u32 colour);
f32 TextGetZ(void);
void TextSetZ(f32 z);

s32 fn_8022AE94(void) {
    Blk2_UNIT0000* b = &lbl_803167F0;
    Obj7A28 o;
    f32 z;
    if (b->f0 != 0 && b->f0 != 7) {
        fn_801D7A28(&o, -10000.0f, 0.0f, 0.0f, lbl_80345878[10], lbl_80345878[11], 0.0f, 0.0f);
        o.j = 0xff000000;
        o.k = 0xff808080;
        o.l = 0xff808080;
        o.m = 0xff000000;
        fn_801D7C44(lbl_80347854->inner->list, &o);
    }
    TextSetColor(-1);
    z = TextGetZ();
    TextSetZ(-100.0f);
    lbl_802F929C[b->f0](b);
    TextSetZ(z);
    if (b->f18 != 0) {
        lbl_802F92BC[b->f1c](b);
        if (b->f1c != 5) return 2;
        return b->f8;
    }
    return b->f8;
}

s32 fn_8021A1C4(s8* out)
{
    s32 ret = 0;
    if (out != 0) {
        s8* p = out;
        s32 i = 0;
        s32 n = 0;
        for (; i < 22 && n < 22; i++) {
            if (fn_801E4BBC(i) != 0) {
                *p = i;
                n++;
                p++;
            }
        }
        ret = n;
        for (i = n; i < 22; i++) {
            out[i] = -1;
        }
    }
    return ret;
}

void fn_8021C36C(s16 x0, s16 y0, s16 x1, s16 y1, u32* colors, f32 z)
{
    NJS_POINT2COL p2c;
    u32 col[4];
    NJS_POINT2 pts[4];
    p2c.p = pts;
    p2c.col = col;
    p2c.tex = NULL;
    p2c.num = 4;
    p2c.p[0].x = x0;
    p2c.p[0].y = y0;
    p2c.col[0] = colors[0];
    p2c.p[1].x = x1;
    p2c.p[1].y = y0;
    p2c.col[1] = colors[1];
    p2c.p[2].x = x1;
    p2c.p[2].y = y1;
    p2c.col[2] = colors[2];
    p2c.p[3].x = x0;
    p2c.p[3].y = y1;
    p2c.col[3] = colors[3];
    fn_801DBD9C(z);
    fn_8000610C(&p2c, 4, 0);
}

void fn_8021C4D4(s16 x0, s16 y0, s16 x1, s16 y1, u32 color, f32 z)
{
    NJS_POINT2COL p2c;
    u32 col[4];
    NJS_POINT2 pts[4];
    p2c.p = pts;
    p2c.col = col;
    p2c.tex = NULL;
    p2c.num = 4;
    p2c.p[0].x = x0;
    p2c.p[0].y = y0;
    p2c.col[0] = color;
    p2c.p[1].x = x1;
    p2c.p[1].y = y0;
    p2c.col[1] = color;
    p2c.p[2].x = x1;
    p2c.p[2].y = y1;
    p2c.col[2] = color;
    p2c.p[3].x = x0;
    p2c.p[3].y = y1;
    p2c.col[3] = color;
    fn_801DBD9C(z);
    fn_8000610C(&p2c, 4, 0);
}

void fn_8021EF80(Obj_8021EF80* o, Pt* p, s16* r, s16 mode)
{
    o->b.a.x = p->x;
    o->b.a.y = p->y;
    switch (mode) {
    default:
    case 0:
        o->b.b.x = p->x / 2;
        o->b.b.y = p->y / 2;
        break;
    case 1:
        o->b.b.x = 0;
        o->b.b.y = 0;
        break;
    case 2:
        o->b.b.x = p->x;
        o->b.b.y = 0;
        break;
    case 3:
        o->b.b.x = 0;
        o->b.b.y = p->y;
        break;
    case 4:
        o->b.b.x = p->x;
        o->b.b.y = p->y;
        break;
    case 5:
        o->b.b.x = p->x / 2;
        o->b.b.y = 0;
        break;
    case 6:
        o->b.b.x = p->x / 2;
        o->b.b.y = p->y;
        break;
    case 7:
        o->b.b.x = 0;
        o->b.b.y = p->y / 2;
        break;
    case 8:
        o->b.b.x = p->x;
        o->b.b.y = p->y / 2;
        break;
    }
    o->b.r[0] = r[0];
    o->b.r[1] = r[1];
    o->b.r[2] = r[2];
    o->b.r[3] = r[3];
    o->b.h10 = o->w8;
    o->b.h12 = 0;
    o->w24 = o->w4;
    o->box = &o->b;
}

static inline s32 KindOf(Shape_802226A8* s)
{
    return s->kind;
}

void* fn_802226A8(NJS_MATRIX m, NJS_POINT3* scale, void* p)
{
    switch (KindOf(p)) {
    case 0: {
        Shape_802226A8* q = p;
        if (scale != 0) {
            njScale(m, scale->x, scale->y, scale->z);
        }
        njCalcPoint(m, &q->box.src[0], &q->box.dst[0]);
        njCalcPoint(m, &q->box.src[1], &q->box.dst[1]);
        njCalcPoint(m, &q->box.src[2], &q->box.dst[2]);
        njCalcPoint(m, &q->box.src[3], &q->box.dst[3]);
        njCalcPoint(m, &q->box.src[4], &q->box.dst[4]);
        njCalcPoint(m, &q->box.src[5], &q->box.dst[5]);
        njCalcPoint(m, &q->box.src[6], &q->box.dst[6]);
        njCalcPoint(m, &q->box.src[7], &q->box.dst[7]);
        p = q->box.end;
        break;
    }
    case 1: {
        Shape_802226A8* q = p;
        f32 k;
        njCalcPoint(m, &q->sph.c, &q->sph.wc);
        if (scale != 0) {
            k = scale->x;
            if (k < scale->y) {
                k = scale->y;
            }
            if (k < scale->z) {
                k = scale->z;
            }
        } else {
            k = 1.0f;
        }
        q->sph.wr = q->sph.r * k;
        p = q->sph.end;
        break;
    }
    case 2: {
        Shape_802226A8* q = p;
        njCalcPoint(m, &q->seg.a, &q->seg.wa);
        njCalcPoint(m, &q->seg.b, &q->seg.wb);
        q->seg.wr = q->seg.r;
        p = q->seg.end;
        break;
    }
    }
    return p;
}

void fn_80223628(NJS_POINT3* out, NJS_POINT3* in, Obj_80223628* o)
{
    NJS_MATRIX m;
    NJS_POINT3 p;
    njUnitMatrix(m);
    njTranslate(m, o->oPos.x, o->oPos.y, o->oPos.z);
    njRotateZXY(m, o->oAng.x, o->oAng.y, o->oAng.z);
    njScale(m, o->oScale.x, o->oScale.y, o->oScale.z);
    njTranslate(m, o->oPos2.x, o->oPos2.y, o->oPos2.z);
    njRotateZXY(m, o->oAng2.x, o->oAng2.y, o->oAng2.z);
    njInvertMatrix(m);
    njCalcPoint(m, in, &p);
    njUnitMatrix(m);
    njTranslate(m, o->pos->x, o->pos->y, o->pos->z);
    njRotateZXY(m, o->ang->x, o->ang->y, o->ang->z);
    njScale(m, o->scale->x, o->scale->y, o->scale->z);
    njTranslate(m, o->pos2->x, o->pos2->y, o->pos2->z);
    njRotateZXY(m, o->ang2->x, o->ang2->y, o->ang2->z);
    njCalcPoint(m, &p, out);
}

s32 fn_80224F28(Xf_80224F28 *x, NJS_POINT3 *b, Cmp *c) {
    Shape_80224F28 *sh = x->shape;
    s32 r;

    if (sh == 0) return 0;
    njPushMatrixEx();
    fn_80286EE8();
    fn_8028B498();
    njUnitMatrix(0);
    njTranslate(0, x->pos->x, x->pos->y, x->pos->z);
    njRotateZXY(0, x->rot->x, x->rot->y, x->rot->z);
    njScale(0, x->scale->x, x->scale->y, x->scale->z);
    njTranslate(0, x->pos2->x, x->pos2->y, x->pos2->z);
    njRotateZXY(0, x->rot2->x, x->rot2->y, x->rot2->z);
    switch (sh->kind) {
    case 1:
        if (c->flags & 1) {
            r = fn_801D38D4(b, sh->p0, c);
        } else if (c->flags & 4) {
            r = fn_801D3574(b, sh->p0, c);
        } else {
            r = fn_801D3BC8(b, sh->p0, c);
        }
        break;
    case 2:
        if (!(c->flags & 1)) {
            r = fn_801D3360(b, sh->p0, c);
        } else {
            r = fn_801D30DC(b, sh->p0, c);
        }
        break;
    default:
        r = 0;
        break;
    }
    njPopMatrixEx();
    if (r != 0) c->id = fn_80223228(c->id);
    return r;
}

s32 fn_8022842C(Anim_8022842C *a) {
    f32 r;
    s32 i;
    Item *it;
    s32 n;

    if (a->t > a->len) return -1;
    a->t = a->t + a->dt;
    n = a->count;
    r = a->t / a->len;
    if (n < 0) return -1;
    it = a->items;
    for (i = 0; i < n; i++, it++) {
        if (it->active != 0) fn_802285AC(it, r);
    }
    if (a->t >= a->len) {
        a->flags |= 2;
        it = a->items;
        for (i = 0; i < n; i++, it++) {
            if (it->active != 0) {
                it->cur = it->init;
                if (it->target != 0) *it->target = it->cur;
            }
        }
        return 0;
    }
    return 1;
}

void fn_80229BEC(Obj_80229BEC *o) {
    u32 lim[5] = {0, 0x30c, 0xf0, 0x30c, 0x10e};
    Sub *s;
    s32 i;
    switch (o->state) {
    case 0:
        if (o->timer < lim[o->cur]) {
            o->timer++;
        } else {
            o->fade = lbl_8034C648;
            o->prev = o->cur;
            if (o->cur < 4) {
                o->cur++;
            } else {
                o->cur = 1;
            }
            o->timer = 0;
            o->state = 1;
            s = &o->sub;
            i = (u8)(o->cur - 1);
            fn_801D89D4(s, 200, 10, s->f34, s->f38, s->f3c, s->f40, lbl_802F915C[i].a, lbl_802F915C[i].b, lbl_802F915C[i].c, lbl_802F915C[i].d);
            fn_801D8AB4(&s[1], 0x104, 0x1e, s[1].f34, lbl_802F915C[i].e);
        }
        break;
    case 1:
        if (o->fade > lbl_8034C688) {
            o->fade -= lbl_8034C68C;
        } else {
            o->state = 0;
        }
        break;
    default:
        o->state = 0;
        break;
    }
}

void fn_8022D1F8(NJS_POINT3 *out, Spec *s, Angle *rot) {
    NJS_MATRIX m;
    NJS_POINT3 v;
    NJS_POINT3 r;
    f32 k;
    if (0.0f != s->amp1 || 0.0f != s->amp2) {
        njUnitMatrix(m);
        njRotateXYZ(m, rot[0], rot[1], rot[2]);
        v.z = 0.0f;
        if (0.0f != s->amp1) {
            v.x = 0.0f;
            v.y = 1.0f;
            njCalcVector(m, &v, &r);
            k = s->amp1 * njCos(s->ang1);
            out->x += r.x * k;
            out->y += r.y * k;
            out->z += r.z * k;
        }
        if (0.0f != s->amp2) {
            v.y = 0.0f;
            v.x = 1.0f;
            njCalcVector(m, &v, &r);
            k = s->amp2 * njCos(s->ang2);
            out->x += r.x * k;
            out->y += r.y * k;
            out->z += r.z * k;
        }
    }
}

void fn_80222838(void *p)
{
    Obj_80222838 *o = p;
    NJS_MATRIX m;
    void *q;
    s32 i;

    njUnitMatrix(m);
    if (o->pos != NULL) {
        njTranslate(m, o->pos->x, o->pos->y, o->pos->z);
    }
    if (o->rot != NULL) {
        njRotateZXY(m, o->rot->x, o->rot->y, o->rot->z);
    }
    if (o->pos2 != NULL) {
        njTranslate(m, o->pos2->x, o->pos2->y, o->pos2->z);
    }
    if (o->rot2 != NULL) {
        njRotateZXY(m, o->rot2->x, o->rot2->y, o->rot2->z);
    }
    q = o->data;
    for (i = 0; i < o->count; i++) {
        q = fn_802226A8(m, o->parts, q);
    }
}

s16 fn_80225E58(Slot *tbl, s16 n, u32 key_)
{
    u16 key = key_;
    s32 i;
    if (key != 0xFFFF) {
        for (i = 0; i < n; tbl++, i++) {
            if (tbl->p0 != NULL && tbl->key8 == key) {
                return i;
            }
        }
    } else {
        for (i = 0; i < n; tbl++, i++) {
            if (tbl->p0 != NULL) {
                return i;
            }
        }
    }
    return -1;
}

/* Points the slot table at tbl (n entries) and empties every slot; as an inline its own
 * counter gets the register the original has (written out in place, i and the offset swap). */
static inline void SlotInit(Slot *tbl, s16 n) {
    s32 i;
    lbl_8034752C = tbl;
    lbl_8034752A = n;
    for (i = 0; i < lbl_8034752A; i++) {
        lbl_8034752C[i].p0 = NULL;
        lbl_8034752C[i].key8 = 0xFFFF;
    }
    lbl_80347528 = 0;
}
/* Resets the sound/stream slot system: counters, the 8-slot table, then fn_8022291C. */
void fn_80225FDC(void)
{
    lbl_803474C4 = 0;
    lbl_803474C0 = 0;
    SlotInit(lbl_803154B0, 8);
    fn_8022291C();
}

void *fn_80226704(Node_UNIT0000 *a, void *b, u32 c)
{
    Node_UNIT0000 *n = fn_801E1A74(1, c + 0x40);
    if (n != NULL) {
        n->f20 = 0.0f;
        n->next = a->next;
        a->next = n;
        if (lbl_80311A78.cur == a) {
            lbl_80311A78.cur = n;
        }
        n->w0 = b;
        n->w8 = a;
        n->w10 = c;
        n->w14 = a->w14;
        n->b18 = 0;
        n->b1b = a->b1b + 1;
    }
    return n;
}

void fn_8022638C(void **list) {
    Node_UNIT0000 *cur = &lbl_80311A78.sentinel;
    void *v;
    s32 i = 0;
    while ((v = *list++) != NULL) {
        Node_UNIT0000 *n = fn_801E1A74(1, 0x40);
        if (n == NULL) {
            break;
        }
        n->f20 = 0.0f;
        n->next = cur->next;
        cur->next = n;
        cur = n;
        n->w0 = v;
        n->w14 = i++;
        n->b18 = 0;
        n->b1b = 0;
    }
}

void fn_80219ACC(s32 x, void *p)
{
    fn_8023A8E0(p);
    if (lbl_803477E8 != 0) {
        lbl_803477E8->flags |= (x > 0) ? 2 : 0x12;
    }
}

static inline void FreeAll(Blk *p)
{
    Blk *nx;
    while (p != NULL) {
        nx = p->next;
        fn_80005AD8(heap_main, p);
        p = nx;
    }
}

void fn_8022807C(void)
{
    if (lbl_80347804 != NULL) {
        FreeAll(lbl_80347804);
        lbl_80347800 = 0;
        lbl_80347804 = NULL;
    }
}

/* Create a task running fn, linked right after parent a (a child inherits a's w14, depth + 1). */
void *fn_802267AC(void *a, void *fn)
{
    Node_UNIT0000 *p = a;
    Node_UNIT0000 *n = fn_801E1A74(1, 0x40);
    if (n != NULL) {
        n->f20 = 0.0f;
        n->next = p->next;
        p->next = n;
        if (lbl_80311A78.cur == p) {
            lbl_80311A78.cur = n;
        }
        n->w0 = fn;
        n->w8 = p;
        n->w10 = 0;
        n->w14 = p->w14;
        n->b18 = 0;
        n->b1b = p->b1b + 1;
    }
    return n;
}

void fn_80228B74(void) {
    switch (fn_8022AE94()) {
    case 0: fn_80228914(); fn_80100178(lbl_802D96CC); fn_801DBE6C(6); break;
    case 1: fn_801CBC30(); lbl_80311AD4.state = 2; break;
    case 2: break;
    }
    fn_8022642C();
}

Node_UNIT0000 *fn_80226670(Node_UNIT0000 *a, void *b)
{
    Node_UNIT0000 *n = fn_801E1A74(1, 0x40);
    if (n != NULL) {
        Node_UNIT0000 *t;
        n->f20 = 0.0f;
        t = lbl_80311A78.head;
        n->next = t->next;
        t->next = n;
        lbl_80311A78.head = n;
        n->w0 = b;
        n->w8 = a;
        n->w10 = 0;
        n->w14 = a->w14;
        n->b18 = 0;
        n->b1b = a->b1b + 1;
    }
    return n;
}

static inline void LinkFlags(Link* l, u32 clr, u32 set)
{
    l->flags &= ~clr;
    l->flags |= set;
}

Inst* fn_80222C80(Req* req, Src_80222C80* src)
{
    Inst* inst;
    Node_80222C80* node;
    u32 id;
    s32 i;
    Link* l;
    if (src != 0) {
        src->inst = 0;
    }
    id = fn_801C8A0C(req->id24);
    if (id == 0xFFFFFFFF || (id >> 16) == 0) {
        return 0;
    }
    inst = 0;
    if (src != 0) {
        if (src->node != 0) {
            node = src->node;
            inst = src->inst = fn_801C7D0C(&node->link);
            if (src->inst != 0) {
                inst->v18 = src->v38;
                inst->v1c = src->v50;
                inst->v20 = src->v44;
            }
        }
    } else if (req->res->on != 0) {
        node = fn_801DA4D0(req->res->key);
        if (node != 0) {
            inst = fn_801C7D0C(&node->link);
            if (inst != 0) {
                inst->v18 = req->v44;
                inst->v1c = req->v5c;
            }
        }
    }
    if (inst != 0) {
        if (src != 0) {
            inst->owner = src;
        } else {
            inst->owner = 0;
        }
        inst->w8 = req->w4;
        inst->id = id;
        fn_80222838(inst);
        fn_802229F8(inst);
        l = &node->link;
        for (i = 0; i != 1 && l != 0; i++) {
            l = l->next;
        }
        while (l != 0) {
            LinkFlags(l, 0, 8);
            l = l->sib;
        }
    }
    return inst;
}

static inline Ent_80224040 *ent_find(Tab_80224040 *t, u32 id) {
    Ent_80224040 *p;
    s32 n;
    if (t->count > id) {
        p = t->ents;
        if (id != p[id].id) {
            for (n = t->count; n > 0; p++, n--) {
                if (id == p->id) return p;
            }
        } else {
            p += id;
            return p;
        }
    }
    return 0;
}

s16 fn_80224040(s32 a, Tab_80224040 *b) {
    Ent_80224040 *nd;
    List *l;
    s16 r;
    s32 i;
    s32 j;
    u16 buf[0x12];
    Ent_80224040 *e;
    u32 id;
    u32 *ip;

    Ent_80224040 *ents;
    r = fn_80223B88(a, b);
    ents = b->ents;
    if (r >= 0) {
        for (nd = ents, i = 0; i < b->count; nd++, i++) {
            l = nd->list;
            if (l->count != 0 && nd->cnt->n != 0) {
                buf[0] = nd->key;
                buf[1] = l->count;
                if ((s16)l->count > 0x10) fn_801DBE1C(lbl_802D9608, buf[0]);
                j = 0;
                ip = l->items;
                do {
                    id = *ip;
                    e = ent_find(b, id);
                    if (e) {
                        buf[j + 2] = e->key;
                    } else {
                        fn_801DBE1C(lbl_802D95D4, buf[0], id & 0x7fffffff);
                        buf[1] = j;
                        break;
                    }
                    ip++;
                    j++;
                } while (j < (s32)l->count);
                fn_80223A34(a, buf);
            }
        }
    }
    return r;
}

void fn_80219B24(s32 x, void *p)
{
    Obj_80219ACC *q;

    fn_8023A8E0(p);
    q = lbl_803477E8;
    if (q != 0) {
        q->flags |= (x > 0) ? 1 : 0x11;
    }
}

void *fn_802268E8(void *parent, void *cb)
{
    Node_UNIT0000 *a = parent;
    Node_UNIT0000 *n = fn_801E1A74(1, 0x40);
    if (n != NULL) {
        Node_UNIT0000 *t;
        n->f20 = 0.0f;
        t = lbl_80311A78.cur;
        n->next = t->next;
        t->next = n;
        lbl_80311A78.cur = n;
        n->w0 = cb;
        n->w8 = a;
        n->w10 = 0;
        n->w14 = a->w14;
        n->b18 = 0;
        n->b1b = a->b1b + 1;
    }
    return n;
}

void fn_802285AC(Item *it, f32 u) {
    f32 res;
    f32 w = 1.0 - u;
    f32 p;
    f32 q;
    f32 old;
    f32 rate = it->rate;

    if (rate) {
        if (it->wave != 0) {
            it->phase = it->phase + rate;
            if (it->phase >= 65536.0) it->phase -= 65536.0;
            if (it->phase <= 65536.0) it->phase += 65536.0;
            if (1.0 != it->damp) {
                it->ampcur = it->ampcur * it->damp;
                if (it->ampcur < 0.03) it->wave = 0;
            }
            it->out = it->ampcur * (it->amp * njCos(it->phase));
        }
    }
    if (it->active & 1) {
        it->a = it->a + it->da;
        switch (it->mode) {
        case 2:
            it->b = it->b + it->db;
            it->c = it->c + it->dc;
            p = w * (it->b - it->a) + it->a;
            q = u * (it->c - it->a) + it->a;
            res = u * (q - p) + p;
            break;
        case 1:
            res = it->a;
            break;
        }
        old = it->prev;
        it->prev = res;
        res = res - old;
        if (it->delay != 0) it->delay--;
    }
    if (it->delay == 0) {
        it->cur = it->prev + it->out;
        it->delta = res;
    }
    if (it->active != 0 && it->target != 0) *it->target = it->cur;
}

s32 fn_80224674(NJS_POINT3 *out, B_80224768 *obj, NJS_POINT3 *pos, List_80224674 *list) {
    Obj_80224768 *e;
    s32 i;
    s32 found;
    f32 best;
    s32 r;

    e = list->head;
    r = 0;
    found = 0;
    for (i = 0; i < list->count; e++, i++) {
        NJS_POINT3 hit;
        r = fn_80224768(&hit, obj, pos, e);
        if (r == 1) {
            f32 dx = pos->x - hit.x;
            f32 dy = pos->y - hit.y;
            f32 dz = pos->z - hit.z;
            f32 d = dx * dx + dy * dy + dz * dz;
            if (found == 0 || best > d) {
                obj->x2e = i;
                best = d;
                obj->x2a = e->x8e;
                out->x = hit.x;
                out->y = hit.y;
                out->z = hit.z;
            }
            found++;
        }
    }
    return r;
}

static inline Ctx802281DC *FindEnt(void) {
    Ctx802281DC *e = lbl_803475EC;
    s32 i;
    for (i = 0; i < 1024; e++, i++) {
        if (e->sub != 0 && e->sub->a == 0x1869E) {
            lbl_803477F8 = i;
            return e;
        }
    }
    return 0;
}

void fn_80226DC4(void) {
    Ctx802281DC *e = FindEnt();
    if (e != 0) {
        if (fn_80298700(e) == 1) {
            fn_802281DC(e);
            lbl_80311894.x8 = 0;
            if (lbl_80347EC4 == lbl_803477F8 + 1) {
                lbl_80347EC4 = lbl_80347EC4 - 1;
            }
        }
    }
}

void fn_80228014(void)
{
    Blk *p;
    fn_802979B8();
    if ((p = lbl_80347804) != NULL) {
        while (p != NULL) {
            Blk *nx = p->next;
            fn_80005AD8(heap_main, p);
            p = nx;
        }
        lbl_80347804 = NULL;
    }
    lbl_80347800 = 0;
    lbl_803477FC = 0x10000;
}

void fn_8022A68C(void) {
    fn_801E1D94();
    fn_80226170();
    fn_802281BC(0x400);
    fn_8022DCC4();
    fn_801DA1C0();
    fn_801DBA58(0xff000000, 0xff000000, 0xff000000);
    fn_8028BB90(&lbl_803119E0);
    lbl_80346788 = lbl_8034C688;
    lbl_8034678C = lbl_8034C6A0;
    njClipZ(lbl_8034C688, lbl_8034C6A0);
    DrawStateDefault(1, &lbl_803165A0);
    TextReset();
    if (lbl_80346E48 == 1) {
        lbl_80346E48 = 0;
    }
    lbl_80311AD4.state = 1;
}

static inline MenuEnt* GetEnt(s32 idx)
{
    MenuEnt* e = NULL;
    if (InRange(idx)) {
        e = &lbl_802D6740[idx];
    }
    return e;
}
s32 fn_8021A2B0(Src* a, void* b, s32 code);

s32 fn_8021A7B0(Src* p, void* q)
{
    s32 r = 0;
    if (p != NULL && q != NULL) {
        MenuEnt* e = GetEnt(p->id);
        if (e != NULL) {
            r = e->f40;
            r += fn_8021A2B0(p, q, 7);
        }
    }
    return r;
}

static inline s32 InRange6(s32 v)
{
    s32 r = 0;
    if (v >= 0 && v < 6) {
        r = 1;
    }
    return r;
}


s32 fn_8021A2B0(Src* a, void* b, s32 code);

s32 fn_8021AA48(Src* p, void* q, s32 k)
{
    s32 r = 0;
    if (p != NULL && q != NULL) {
        MenuEnt* e = GetEnt(p->id);
        if (e != NULL && InRange6(k)) {
            s32 code;
            r = e->v[k];
            switch (k) {
            case 0: code = 0x20; break;
            case 1: code = 0x21; break;
            case 2: code = 0x22; break;
            case 3: code = 0x23; break;
            case 4: code = 0x24; break;
            case 5: code = 0x25; break;
            default: code = 0x20; break;
            }
            r += fn_8021A2B0(p, q, code);
        }
    }
    return r;
}

void fn_8022445C(Slot* g, Seg* segs, s32 count)
{
    Cmp hit;
    f32 hy;
    Xf_80224F28* p;
    Seg* seg;
    s32 found;
    s32 n;
    u16 id;
    f32 best;
    hit.flags = 1;
    seg = segs;
    id = g->key8;
    do {
        found = seg->found;
        p = g->p0;
        if (found != 0) {
            best = seg->pos.y - seg->y;
        }
        n = g->count;
        for (; n > 0; p++, n--) {
            if (fn_80224F28(p, &seg->pos, &hit) != 0 && fn_801C812C(hit.v, seg->pos.x, seg->pos.z, &hy) != 0 && seg->pos.y > hy) {
                f32 d = seg->pos.y - hy;
                if (found == 0) {
                    seg->y = hy;
                    best = d;
                    found = 1;
                    seg->found = 1;
                    seg->id = hit.id;
                    seg->key = p->key;
                    seg->group = id;
                } else if (best > d) {
                    seg->y = hy;
                    best = d;
                    seg->id = hit.id;
                    seg->key = p->key;
                    seg->group = id;
                }
            }
        }
        seg++;
    } while (--count > 0);
}

s32 fn_802250E4(Slot *o, NJS_POINT3 *p, Cmp *res) {
    Xf_80224F28 *r = o->p0;
    s32 ret = 0;
    s32 i;
    f32 best;
    f32 d;
    f32 out;
    NJS_POINT3 p2;
    Cmp tmp;

    if (res->flags & 1) {
        i = 0;
        tmp.flags = 1;
        p2.x = p->x;
        p2.y = p->y;
        p2.z = p->z;
        for (; i < o->count; r++, i++) {
            if (fn_80224F28(r, &p2, &tmp) == 0) continue;
            fn_801C812C(tmp.v, p2.x, p2.z, &out);
            if (ret != 0) {
                if (0.0f <= (d = p2.y - out) && best > d) {
                    best = d;
                    res->v[0] = tmp.v[0];
                    res->v[1] = tmp.v[1];
                    res->v[2] = tmp.v[2];
                    res->id = tmp.id;
                    res->key = r->key;
                    res->idx = i;
                    res->w32 = tmp.w32;
                    p->y = out;
                }
            } else {
                if (0.0f <= (best = p2.y - out)) {
                    ret = 1;
                    res->v[0] = tmp.v[0];
                    res->v[1] = tmp.v[1];
                    res->v[2] = tmp.v[2];
                    res->id = tmp.id;
                    res->key = r->key;
                    res->idx = i;
                    res->w32 = tmp.w32;
                    p->y = out;
                }
            }
        }
    } else {
        for (i = 0; i < o->count; i++) {
            ret = fn_80224F28(r, p, res);
            if (ret == 1) {
                fn_801C812C(res->v, p->x, p->z, &p->y);
                res->idx = i;
                res->key = r->key;
                break;
            }
            r++;
        }
    }
    return ret;
}

static inline s16 XfFind(Xf_80224F28 *r, u16 key, s16 n) {
    int i;
    for (i = 0; i < n; r++, i++) {
        if (r->key == key) return i;
    }
    return -1;
}

s32 fn_80225330(Slot *o, NJS_POINT3 *p, Cmp *res) {
    u16 key = res->key;
    s32 ret;
    Xf_80224F28 *rec;
    s32 s;
    s32 k;

    if (key == 0xffff) return fn_802250E4(o, p, res);
    if (res->idx < 0) res->idx = XfFind(o->p0, key, o->count);
    if (res->idx < 0) {
        ret = 0;
    } else {
        rec = &o->p0[res->idx];
        ret = fn_80224F28(rec, p, res);
    }
    if (ret == 0 && res->idx >= 0 && !(res->flags & 2)) {
        for (k = 0; k < rec->nnear; k++) {
            s = rec->near[k];
            ret = fn_80224F28(&o->p0[s], p, res);
            if (ret != 0) {
                res->key = o->p0[s].key;
                res->idx = s;
                break;
            }
        }
        if (ret == 0) return 0;
    } else if (ret == 0) {
        return 0;
    }
    return fn_801C812C(res->v, p->x, p->z, &p->y);
}

void fn_802241B0(Slot *o, Arr *h, s32 n) {
    f32 out;
    Cmp tmp;
    Xf_80224F28 *r;
    Arr *p;
    int hasB;
    int hasA;
    int m;
    u16 w;
    f32 db, da, d, nd;

    p = h;
    tmp.flags = 0;
    w = o->key8;
    do {
        hasA = p->hasCeil;
        r = o->p0;
        if (hasA != 0) da = p->ceil - p->pos.y;
        hasB = p->hasFloor;
        if (hasB != 0) db = p->pos.y - p->floor;
        m = o->count;
        for (; m > 0; r++, m--) {
            if (!fn_80224F28(r, &p->pos, &tmp)) continue;
            if (!fn_801C812C(tmp.v, p->pos.x, p->pos.z, &out)) continue;
            d = p->pos.y - out;
            if (-0.0f <= d) {
                if (hasB == 0) {
                    p->floor = out;
                    hasB = 1;
                    db = d;
                    p->hasFloor = 1;
                    p->floorId = tmp.id;
                    p->floorKey = r->key;
                    p->floorGrp = w;
                } else if (db > d) {
                    p->floor = out;
                    db = d;
                    p->floorId = tmp.id;
                    p->floorKey = r->key;
                    p->floorGrp = w;
                }
            } else {
                nd = -d;
                if (hasA == 0) {
                    p->ceil = out;
                    hasA = 1;
                    da = nd;
                    p->hasCeil = 1;
                    p->ceilId = tmp.id;
                    p->ceilKey = r->key;
                    p->ceilGrp = w;
                } else if (da > nd) {
                    p->ceil = out;
                    da = nd;
                    p->ceilId = tmp.id;
                    p->ceilKey = r->key;
                    p->ceilGrp = w;
                }
            }
        }
        p++;
    } while (--n > 0);
}

void fn_802289AC(void) {
    OSCreateAlarm(&lbl_80316578);
    lbl_80347810 = OSGetTime();
    OSSetPeriodicAlarm(&lbl_80316578, lbl_80347810, OS_TIMER_CLOCK, fn_80228948);
    lbl_803474A4 = 0;
    lbl_803474A0 = 0;
    lbl_80347808 = 0;
}

void fn_8022B318(Menu *m) {
    TextPrint(0x18, 0xb0, lbl_802F9238[11 + m->x10]);
    TextPrint(0x18, 0xf8, lbl_802F9238[15]);
    TextPrint(0x18, 0x140, lbl_802F9238[19]);
    TextSetColor(m->x14 == 0 ? -1 : 0xff808080);
    TextPrint(0xe0, 0x188, lbl_802F9238[0]);
    TextSetColor(m->x14 == 1 ? -1 : 0xff808080);
    TextPrint(0x158, 0x188, lbl_802F9238[1]);
    if (m->x1c == 0) {
        m->xc = fn_801A28F4(&m->x10);
        if (m->xc == 2) {
            u32 btn = lbl_80311A60.p->f8;
            if (((btn & 1) && m->x14 == 1) || ((btn & 2) && m->x14 == 0)) {
                MenuPlaySe(0);
                m->x14 = (m->x14 == 0);
            } else if (btn & 0x100) {
                MenuPlaySe(2);
                if (m->x14 == 0) {
                    lbl_803475D0 = 1;
                    fn_801A289C();
                    m->mode = 4;
                } else {
                    m->x1c = 3;
                    m->x8 = 0;
                }
            }
        } else if (m->xc == 0) {
            m->mode = 1;
        } else {
            m->mode = 2;
        }
    }
}
