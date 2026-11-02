#include "types.h"
#include "game/work_8030CEA0.h"
#include "ninja.h"
#include "game/sprite.h"
#include "game/util.h"
#include "game/task.h"
#include "game/drawstate.h"
#include <math.h>
#include "game/evobj.h"
#include "game/unit_800B2DA0.h"
typedef struct {
    u8 b0;
    u8 b1;
    u8 b2;
    s8 b3;
    s16 h4;
    u8 pad6[0x10 - 0x6];
    u32 w10;
    u8 pad14[0x18 - 0x14];
    f32 f18;
    u8 pad1c[0x20 - 0x1c];
    f32 f20;
    u8 pad24[0x28 - 0x24];
    u16 h28;
} Src_80305BA8;
extern Src_80305BA8 lbl_80305BA8;
extern s8 lbl_80310A1C[0x120];
extern void fn_801E1784(void *p);
extern EvObj* lbl_80347450;
typedef struct FxState {
    s16 mode;
    s16 flag;
    f32 f04;
    f32 f08;
    f32 f0c;
    s32 i10;
    s32 i14;
    s32 i18;
    f32 f1c;
    f32 f20;
    s32 pad24[2];
    s32 i2c;
    s32 i30;
} FxState;
extern FxState lbl_80305B28;
extern f32 lbl_80349408;
void fn_800D249C(s32 a, f32 b, f32 c, f32 d, f32 e);
typedef struct {
    u8 pad0[0x8];
    f32 f8;
    f32 fc;
    f32 f10;
    u8 pad14[0x4];
    f32 f18;
    f32 f1c;
    f32 f20;
    s32 n24;
    f32 f28;
    f32 f2c;
    f32 f30;
    f32 f34;
    f32 f38;
    f32 f3c;
    f32 f40;
    f32 f44;
    s32 n48;
} Unk80305B5C;
extern Unk80305B5C lbl_80305B5C;
extern void fn_801E17E0(void*);
extern void fn_801E66E0();
extern Ctrl* lbl_80311A60[6];
extern void *fn_801E1C7C(u32 n);
extern void fn_801DD95C(void *p);
extern void fn_80100B74(void *self);
extern void fn_801E7DF0(void *p);
extern void fn_801DD7D8(void* p);
typedef struct {
    s32 unk0;
    s32 map;
    char room;
} MapInfo;
extern MapInfo lbl_80311AC0;
s32 fn_800D2924(EvObj *self);
typedef struct {
    u8 pad0[0x34];
    s32 v34;
    u8 rest[0x68 - 0x38];
} Item68;
typedef struct {
    u8 pad0[0x6];
    s16 a6;
    u8 pad8[0x18 - 0x8];
    f32 f18;
    f32 f1c;
    f32 f20;
    f32 f24;
    u16 h28;
    u16 u2a;
    struct R_800C4584 *u2c;
    struct R_800C4584 *grp;
    struct Part_800D29B4 *u34;
    struct Part_800D29B4 *u38;
    s32 w3c;
} Ctl_80305BE8;
extern Ctl_80305BE8 lbl_80305BE8;
typedef struct {
    s32 n0;
    Item68 *items;
} Self_800D2B1C;
void *fn_801005F8(Self_800D2B1C *self, u16 id);
typedef struct {
    u8 pad0[0x1c];
    f32 f1c;
    u8 pad20[0xb4 - 0x20];
    f32 fb4;
    f32 fb8;
    f32 fbc;
    u8 pad_c0[0x184 - 0xc0];
    s32 f184;
} Self_800D3598;
f32 fn_80291A5C(f32 x);
extern void fn_801E1784(void* p);
void fn_800D208C(u32 col, f32 start);
extern void fn_800D2048(void);
extern s32 fn_802275A4(NJS_TEXLIST* texlist, s32 a);
extern Task* fn_801C6180(Task* parent, void (*func)(Task*));
extern void MemCopy(void* dst, const void* src, s32 size);
extern f32 lbl_80346788;
extern f32 lbl_8034678C;
extern int rand(void);
void fn_800C3428(Task* self);
extern void fn_801E6438(EvObj* a);
typedef struct {
    s16 frames;       /* 0x00 */
    s16 value;        /* 0x02 */
} Key_800D5E78;
typedef struct {
    u16 mode;         /* 0x00 */
    u8 pad2;
    u8 count;         /* 0x03 */
    Key_800D5E78 keys[1];      /* 0x04 */
} Script_800D5E78;
typedef struct {
    u8 pad0[0x1C];
    f32 x1c;          /* 0x1C */
    u8 pad20[0x1FC - 0x20];
    s16 x1fc;         /* 0x1FC */
    s16 x1fe;         /* 0x1FE */
    u8 pad200[0x24C - 0x200];
    f32 x24c;         /* 0x24C */
    u8 pad250[0x25C - 0x250];
    Script_800D5E78* x25c;     /* 0x25C */
} Ent_800D5E78;
/* Same layouts as unit_800B2DA0.c (fn_800D5F94). */
typedef struct {
    s16 frames;       /* 0x00 */
    s16 value;        /* 0x02 */
    u8 pad4[4];
} Key_800D5F94;
typedef struct {
    u16 mode;         /* 0x00 */
    s16 count;        /* 0x02 */
    Key_800D5F94 keys[1];      /* 0x04 */
} Script_800D5F94;
typedef struct {
    u8 pad0[0xC];
    u32* data;        /* 0x0C */
} Node;
typedef struct {
    u8 pad0[8];
    Node* node;       /* 0x08 */
} Rec_800D5F94;
typedef struct {
    Rec_800D5F94* recs;        /* 0x00 */
} Table_800D5F94;
typedef struct {
    u8 pad0[0x100];
    Table_800D5F94* x100;      /* 0x100 */
    u8 pad104[0x200 - 0x104];
    s16 x200;         /* 0x200 */
    s16 x202;         /* 0x202 */
    u8 pad204[0x23C - 0x204];
    s32 x23c;         /* 0x23C */
    u8 pad240[0x260 - 0x240];
    Script_800D5F94* x260;     /* 0x260 */
} Ent_800D5F94;
typedef struct {
    u8 pad0[1];
    u8 r, g, b;
    u16 flags;
    s16 count;
    u8 pad8;
    u8 r2, g2, b2;
    s32 val;
} Src6138;
typedef struct {
    s16 n;          /* 0x00 */
    s16 pad2[3];
    f32 timer;      /* 0x08 */
    s16 en[3];      /* 0x0C */
    s16 pad12;
    f32 f14[3][2];  /* 0x14 */
    f32 f2c[3][2];  /* 0x2C */
} Obj7D60;
extern s32 fn_8015F1F0(EvObj* p);
typedef struct Group_800D29B4 {
    u8 pad0[4];
    Part_800D29B4* part;
    u8 pad8[0x28];
    struct Group_800D29B4* next;
} Group_800D29B4;
typedef struct {
    u8 pad0;
    u8 r, g, b;
    u32 time;
} Key_800D5CF4;
typedef struct {
    u8 pad0[4];
    u16 type;
    s16 count;
    Key_800D5CF4 keys[1];
} KeyList_800D5CF4;
typedef struct {
    u8 pad[0x20];
    f32 cur[3];
    u8 padc[0x204 - 0x2c];
    s16 idx;
    s16 timer;
    u8 pad2[0x250 - 0x208];
    f32 tgt[3];
    u8 pad3[0x264 - 0x25c];
    KeyList_800D5CF4* list;
} Obj_800D5CF4;
typedef struct { u8 b0, b1; s8 b2, b3; u8 pad[8]; } Stick;
typedef struct {
    s16 cur;
    s16 count;
    s32 sel;
    u8 pad8[4];
    s16 vis[3];
} Menu;
extern s32 lbl_8034757C;
extern Stick lbl_80311A14[];
extern u32 lbl_80311A00[];
s32 SePlay(s32 bank, s8 arg1, s8 id);
typedef struct V3_800C4584 {
    f32 x, y, z;
} V3_800C4584;
typedef struct R_800C4584 {
    u8 pad0[4];
    s32 w4;                 /* 0x04 */
    u8 pad8[0xc - 0x8];
    IdList *list;           /* 0x0c */
    IdList *p10;            /* 0x10 */
    u8 pad14[0x1c - 0x14];
    Tbl_800C4584 *tbl;      /* 0x1c */
    u8 pad20[0x34 - 0x20];
    s32 w34;                /* 0x34 */
    u8 pad38[0x44 - 0x38];
    V3_800C4584 v44;
    u8 pad50[0x54 - 0x50];
    f32 f54;
} R_800C4584;
extern R_800C4584 *fn_801092C0(u16 id, Part_800D29B4 **out);
extern R_800C4584 *fn_801091F8(u16 id, Part_800D29B4 **out);
typedef struct {
    u8 pad0[0x48];
    s32 s48;
    u8 pad4c[0xB4 - 0x4C];
    f32 pos[3];
    f32 off[3];
    u8 padcc[0xE8 - 0xCC];
    void* motion;
    u8 padec[0x18C - 0xEC];
    f32 f18c;
    u8 pad190[0x210 - 0x190];
    s32 s210;
    u8 pad214[0x250 - 0x214];
    f32 f250;
    f32 f254;
    f32 f258;
} Obj_800D3824;
typedef struct {
    u8 pad0[0x24];
    Obj_800D3824* c24;
} Hd_800D3824;
extern Hd_800D3824* lbl_8034749C;
extern void njPushMatrixEx(void);
extern void njPopMatrixEx(void);
extern void njRotateY(NJS_MATRIX m, Angle a);
extern void fn_80286EE8(void);
extern void fn_8028B498(void);
extern s32 fn_801E7B2C(void* o, void* a, void* b, f32 frame);
extern void fn_801DD5E8(void* dst, void* src);
typedef struct {
    s32 count;
    u8 pad4[0x24 - 4];
    s32 v24;
    s32 v28;
    s32 v2c;
    s32 v30;
} Tbl_800D3A20;
typedef struct {
    u8 pad0[4];
    u32 id;
    u8 pad8[8];
    Tbl_800D3A20* tbl;
} Src_800D3A20;
typedef struct {
    u8 pad0[4];
    s32 nframes;
} Mot_800D3A20;
typedef struct {
    f32 f0;
    s32 s4;
    f32 f8;
} Ent_800D3A20;
typedef struct {
    u8 pad0[0xB4];
    f32 pos[3];
    u8 padc0[0xE8 - 0xC0];
    Mot_800D3A20* motion;
    u8 padec[0x15C - 0xEC];
    f32 f15c;
    u8 pad160[0x16C - 0x160];
    s16 s16c;
    u8 pad16e[0x180 - 0x16E];
    s32 s180;
    u8 pad184[0x1C8 - 0x184];
    Src_800D3A20* p1c8;
    u8 pad1cc[0x20C - 0x1CC];
    s32 s20c;
    s32 s210;
    u8 pad214[0x24C - 0x214];
    f32 f24c;
    f32 f250;
    f32 f254;
    f32 f258;
} Obj_800D3A20;
typedef struct {
    s16 n;
    s16 pad2;
    s32 b;
    s32 d1;
} BlkA_800D5584;
typedef struct {
    s16 n;
    s16 pad2;
    s16 b;
    s16 pad6;
    s16 d1;
    s16 d2;
} BlkB_800D5584;
typedef struct {
    u8 pad0[0x20];
    s32 v20;
} Lim_800D6390;
typedef struct {
    u8 pad0[0x1C];
    f32 f1c;
    f32 f20;
    f32 f24;
    f32 f28;
    u8 pad2c[0x100 - 0x2C];
    s32 s100;
    u8 pad104[0x188 - 0x104];
    u32 flags188;
    u8 pad18c[0x1C8 - 0x18C];
    Lim_800D6390* p1c8;
    u8 pad1cc[0x268 - 0x1CC];
    void* p268;
} Work_800D6390;
typedef struct {
    u8 pad0[0x19];
    u8 state;
    u8 pad1a[0x20 - 0x1A];
    f32 f20;
    Work_800D6390* work;
} Obj_800D6390;
extern Ent_800D6E1C* fn_800CCA6C(s32 a, s32 b);
extern void fn_800D6C04(EvObj* o);
extern void fn_800D6974(EvObj* o);
extern f32 lbl_80347560;
extern void njClipZ(f32 near, f32 far);
extern s32 lbl_803473A8;
extern u32 lbl_80310B3C[0x356];
extern s32 fn_80222B30(EvColl *a, EvColl *b);
extern void GXSetFog(s32 type, f32 startz, f32 endz, f32 nearz, f32 farz, GXColor color);
extern void fn_80296F28(void);
extern void fn_801DBE1C(const char* fmt, ...);
extern s32 fn_8015F218(Work_800C6474*);
#define RND (3.0517578125e-05f * rand())
extern void *fn_801DD984(void);
typedef struct Hnd {
    u8 pad0[6]; u16 flags; u8 pad8[0xc - 8];
    NJS_MOTION *motion; f32 frame; u8 pad14[0x1c - 0x14];
    void *p1c; u8 pad20[4]; void *p24, *p28, *p2c;
    NJS_POINT3 pos; /* 0x30 */
    u8 pad3c[0x48 - 0x3c];
    u8 v48[0xc]; u8 v54[0xc]; u8 v60[0xc];
} Hnd;
typedef struct Scr { u8 pad[4]; s32 i4; } Scr;
typedef struct Rec { f32 a; s32 b; f32 c; } Rec;
typedef struct Obj_800D3C00 {
    u8 pad0[0x38]; u8 pos38[0xc]; u8 v44[0xc];
    u8 pad50[0xb4 - 0x50]; u8 vb4[0xc]; u8 vc0[0xc];
    u8 padcc[0xe8 - 0xcc]; u32 ie8;
    u8 padec[0x15c - 0xec]; f32 f15c;
    u8 pad160[0x180 - 0x160]; s32 timer;
    u8 pad184[0x1b4 - 0x184]; Hnd *p1b4; u8 pad1b8[0x1c8 - 0x1b8]; Scr *p1c8;
    u8 pad1cc[0x210 - 0x1cc]; s32 i210;
    u8 pad214[0x24c - 0x214]; f32 f24c; u8 pad250[4]; f32 f254;
} Obj_800D3C00;
typedef struct Task_800D3C00 { u8 pad0[0x19]; u8 state; u8 pad1a[0xa]; Obj_800D3C00 *obj; } Task_800D3C00;
typedef struct Hd { u8 pad[0x19]; u8 state; } Hd;
extern Hnd *fn_80225B74(s32 mask, u16 id);
extern void fn_802233EC(Hnd *h);
extern void fn_802234D4(Hnd *h);
extern Rec *fn_80100684(u32 id, s32 n);
extern s32 MemEqual(const void *a, const void *b, s32 size);
/* An animation/sequence record: header (4 bytes) then b3 words; its size in words is passed in. */
typedef struct Seq_800D6240 {
    u8 b0;
    u8 b1;
    u8 b2;   /* 0x02 */
    u8 n;    /* 0x03 */
    s16 h4;  /* 0x04 */
    s16 h6;  /* 0x06 */
    u32 w[1];
} Seq_800D6240;
typedef struct Obj_800D6240 {
    u8 pad0[0x1c];
    f32 x1c;
    u8 pad20[0x188 - 0x20];
    u32 x188;
    u8 pad18c[0x1fc - 0x18c];
    s16 x1fc;
    s16 x1fe;
    u8 pad200[0x24c - 0x200];
    f32 x24c;
    u8 pad250[0x25c - 0x250];
    Seq_800D6240* seq;
} Obj_800D6240;
typedef struct {
    u8 pad0[0x34];
    s32 x34;          /* 0x34 */
    u8 pad38[0x100 - 0x38];
    Table_800D5F94* x100;      /* 0x100 */
    u8 pad104[0x188 - 0x104];
    u32 x188;         /* 0x188 */
    u8 pad18c[0x200 - 0x18c];
    s16 x200;         /* 0x200 */
    s16 x202;         /* 0x202 */
    u8 pad204[0x23C - 0x204];
    s32 x23c;         /* 0x23C */
    u8 pad240[0x260 - 0x240];
    Script_800D5F94* x260;     /* 0x260 */
} Ent_800D62DC;
typedef struct Hnd_800D3F00 {
    u8 pad_00[6];
    u16 flags;
    u8 pad_08[0x1c - 8];
    void *p1c;
    u8 pad_20[4];
    void *p24, *p28, *p2c;
    u8 pad_30[0x48 - 0x30];
    u8 v48[0xc];
    u8 v54[0xc];
    u8 v60[0xc];
} Hnd_800D3F00;
typedef struct Scr_800D3F00 { u8 pad_00[4]; s32 i4; } Scr_800D3F00;
typedef struct Obj_800D3F00 {
    u8 pad_00[0x38];
    u8 pos38[0xc];
    u8 v44[0xc];
    u8 pad_50[0xb4 - 0x50];
    V3_800C4584 vb4;
    u8 vc0[0xc];
    u8 pad_cc[0xe8 - 0xcc];
    u32 ie8;
    u8 pad_ec[0x15c - 0xec];
    f32 f15c;
    u8 pad_160[0x180 - 0x160];
    s32 timer;
    u8 pad_184[0x1b4 - 0x184];
    Hnd_800D3F00 *p1b4;
    u8 pad_1b8[0x1c8 - 0x1b8];
    Scr_800D3F00 *p1c8;
    u8 pad_1cc[0x210 - 0x1cc];
    s32 i210, i214;
    u8 pad_218[0x24c - 0x218];
    f32 f24c;
    u8 pad_250[4];
    f32 f254;
} Obj_800D3F00;
typedef struct Task_800D3F00 {
    u8 pad_00[0x19];
    u8 state;
    u8 pad_1a[0xa];
    Obj_800D3F00 *obj;
} Task_800D3F00;
typedef struct Hd_800D3F00 { u8 pad_00[0x19]; u8 state; } Hd_800D3F00;
#define FREE_CHAIN(w) do { \
    Node_800B63A4* p = (w)->x25c; \
    if (p != NULL) { \
        while (p != NULL) { \
            Node_800B63A4* q = p; \
            p = p->next; \
            if (q) fn_801E1784(q); \
        } \
        (w)->x25c = NULL; \
    } \
} while (0)
#define FREE_CHAIN_800B88F8(w) do { \
    Node_800B88F8* p = (w)->x25c; \
    if (p != NULL) { \
        while (p != NULL) { \
            Node_800B88F8* q = p; \
            p = p->next; \
            if (q) fn_801E1784(q); \
        } \
        (w)->x25c = NULL; \
    } \
} while (0)
extern void njTranslate(NJS_MATRIX m, f32 x, f32 y, f32 z);
#define ATAN_ANG(y, x) (((x) == 0.0f && (y) == 0.0f) ? 0 : (Angle)(10430.378f * (f32)atan2((y), (x))))
extern struct Task_800BE6EC;
/* The emitter's slots for its particle tasks. */
typedef struct Slots_800BE6EC {
    struct Task_800BE6EC **items; /* 0x00 */
    u32 count;          /* 0x04 */
} Slots_800BE6EC;
/* The effect task work (0x270 bytes, see fn_8009D760), for both the emitter and its
 * particles. */
typedef struct Work_800BE6EC {
    u8 pad0[0x18];
    u32 flags;          /* 0x018 */
    NJS_ARGB col;       /* 0x01C */
    u8 pad2c[0x38 - 0x2C];
    NJS_POINT3 x38;     /* 0x038 */
    Ang3_800C47BC rot;  /* 0x044 */
    NJS_POINT3 scl;     /* 0x050 */
    NJS_POINT3 dscl;    /* 0x05C */
    u8 pad68[0xE8 - 0x68];
    void *xe8;          /* 0x0E8 */
    void *xec;          /* 0x0EC */
    u8 padf0[0x100 - 0xF0];
    NJS_TEXLIST *x100;  /* 0x100 */
    u8 pad104[0x176 - 0x104];
    u16 x176;           /* 0x176 */
    u16 x178;           /* 0x178 */
    u8 pad17a[0x184 - 0x17A];
    s32 x184;           /* 0x184 */
    u8 pad188[0x18C - 0x188];
    f32 x18c;           /* 0x18C */
    f32 x190;           /* 0x190 */
    u8 pad194[0x19C - 0x194];
    s32 x19c;           /* 0x19C */
    u8 pad1a0[0x1C8 - 0x1A0];
    Link_800BE6EC *link; /* 0x1C8 */
    u8 pad1cc[0x1D8 - 0x1CC];
    Sub_800BE6EC *x1d8; /* 0x1D8 */
    u8 pad1dc[0x1EC - 0x1DC];
    u8 x1ec;            /* 0x1EC */
    u8 pad1ed[0x1FA - 0x1ED];
    s8 x1fa;            /* 0x1FA */
    s8 x1fb;            /* 0x1FB */
    s16 x1fc;           /* 0x1FC */
    s16 x1fe;           /* 0x1FE */
    u8 pad200[0x20C - 0x200];
    Ang3_800C47BC x20c; /* 0x20C */
    u8 pad218[0x22C - 0x218];
    u16 x22c;           /* 0x22C */
    u8 pad22e[0x236 - 0x22E];
    u16 x236;           /* 0x236 */
    u16 x238;           /* 0x238 */
    u8 pad23a[0x24C - 0x23A];
    NJS_POINT3 x24c;    /* 0x24C */
    f32 x258;           /* 0x258 */
    Spot_800BE6EC *x25c; /* 0x25C */
    void *x260;         /* 0x260 */
    Slots_800BE6EC *x264; /* 0x264 */
    u8 pad268[0x26C - 0x268];
    u8 x26c;            /* 0x26C */
} Work_800BE6EC;
typedef struct Task_800BE6EC {
    u8 pad0[8];
    struct Task_800BE6EC *parent; /* 0x08 */
    struct Task_800BE6EC *xc;     /* 0x0C */
    u8 pad10[8];
    u8 flags;           /* 0x18 */
    u8 state;           /* 0x19 */
    u8 pad1a;
    u8 x1b;             /* 0x1B */
    f32 x1c;            /* 0x1C */
    f32 x20;            /* 0x20 */
    Work_800BE6EC *work; /* 0x24 */
} Task_800BE6EC;
extern struct NJS_MOTION;
extern struct NJS_MOTION;
#define FREE(p) if ((p) != NULL) { fn_801E1784(p); (p) = NULL; }
extern struct NJS_MOTION;

void fn_800D23A8(s32 a, f32 b, f32 c, s32 n) {
    if (lbl_80349408 > c && n > 1) {
        lbl_80305B28.mode = 2;
        lbl_80305B28.f04 = b;
        lbl_80305B28.f0c = c;
        lbl_80305B28.i10 = a;
        lbl_80305B28.i14 = 0x10000 / n;
    } else {
        lbl_80305B28.mode = 0;
    }
}

void fn_800D2554(f32 x, f32 y) {
    fn_800D249C(1, x, lbl_80305BE8.f1c, y, lbl_80305BE8.f24);
}

void fn_800D258C(s32 n, f32 a, f32 b) {
    f32 f0 = lbl_80305BE8.f18;
    f32 f3 = lbl_80305BE8.f20;
    if (n < 1) {
        return;
    }
    lbl_80305B5C.f28 = f0;
    lbl_80305B5C.f38 = f3;
    lbl_80305B5C.f2c = a;
    lbl_80305B5C.f3c = b;
    lbl_80305B5C.n48 = n;
}

s32 fn_800D2BF0(Part_800D29B4 *id) {
    s32 found = 0;
    if (lbl_80305BE8.u38 == id) {
        lbl_80305BE8.u38 = 0;
        found = 1;
        lbl_80305BE8.grp = 0;
    }
    if (lbl_80305BE8.u34 == id) {
        lbl_80305BE8.u34 = 0;
        found = 1;
        lbl_80305BE8.u2c = 0;
    }
    return found;
}

void fn_800D2C44(u16 v) {
    if (v == 0xffff) {
        return;
    }
    lbl_80305BA8.h28 = v;
}

void fn_800D2C60(f32 a, f32 b) {
    lbl_80305BA8.f18 = a;
    lbl_80305BA8.f20 = b;
}

void fn_800D2C74(u32 v) {
    lbl_80305BA8.w10 = v;
}

void fn_800D2C84(u8 v) {
    lbl_80305BA8.b2 = v;
}

void fn_800D2C94(s8 v) {
    lbl_80305BA8.h4 = v;
}

void fn_800D2CA8(u8 v) {
    lbl_80305BA8.b1 = v;
}

void fn_800D2CB8(u8 v) {
    lbl_80305BA8.b0 = v;
}

void fn_800D3668(EvObj* o);
extern void fn_801E735C(s32 a, void* o, f32 f);

void fn_800D4690(Task *self)
{
    EvObj *e = self->work;
    EvInfoMap *c;
    s32 n;
    s32 m;
    s32 ok;
    f32 t;
    MapInfo *tb;

    switch (self->state) {
    case 0:
    case 0xfe:
        ok = 0;
        tb = &lbl_80311AC0;
        if (tb->map == 0x6b) {
            if (tb->room == 0x64) ok = 1;
        } else if (tb->map == 0xd1) {
            if (tb->room == 0x61) ok = 1;
        }
        if (ok != 0) {
            self->state = 2;
        } else {
            self->state = 1;
        }
        break;
    case 3:
        if (lbl_80347450 != 0 && lbl_80347450->hit != 0) {
            c = EvMapInfo(e);
            n = (c->count > 8) ? c->nearDist : 0;
            t = n / 100.0f;
            e->x24c.x = t;
            fn_801E735C(0, e, 0.0f);
            m = (c->count > 0xc) ? c->x34 : 0;
            if (0.0f > t) m = -m;
            e->x24c.y = m / 100.0f;
            if (e->motion != 0) {
                n = e->motion->nbFrame - 1;
                e->x258 = n;
                e->x210 = n << 3;
            }
            fn_800D3668(e);
            self->state = 4;
        }
        break;
    case 4:
        fn_800D3668(e);
        if (lbl_80310B3C[0x3a] & 1) {
            e->x24c.z = e->x24c.z + e->x24c.x;
            if (0.0f <= e->x24c.x) {
                if (e->x24c.z > e->x210) {
                    e->x24c.z = e->x24c.z - e->x210;
                }
            } else {
                if (e->x24c.z < 0.0f) {
                    e->x24c.z = e->x24c.z + e->x210;
                }
            }
        }
        break;
    case 1:
    case 2:
        break;
    default:
        fn_80100B74(self);
        break;
    }
}

void fn_800D4944(Task* t) {
    fn_800D4690(t);
}

void fn_800D4964(Task* t) {
    fn_800D4690(t);
}

void *fn_800D5184(s16 *tbl, s16 idx) {
    void *ret = 0;
    if (tbl != 0 && tbl[1] != 0) {
        s16 n = tbl[0];
        if (idx > n + 1) {
            ret = (u8 *)tbl + ((n + 1) << 2);
        }
    }
    return ret;
}

void *fn_800D51C0(s16 *rec, s16 key) {
    s32 want;
    s16 k;
    if (rec != 0) {
        want = key;
        while ((k = rec[1]) != 0) {
            if (want == k) {
                break;
            }
            rec += (rec[0] + 1) * 2;
        }
        if (key == k) {
            return rec;
        }
        return 0;
    }
    return 0;
}

/* One 0x30-byte entry of fn_8020F3D4's list. */
typedef struct Ent_800D6618 {
    f32 x, y, z;
    u8 pad_0c[0x18 - 0xc];
    f32 f18;
    s32 w1c;
    s32 w20;
    f32 f24;
    s32 w28;
    s32 w2c;
} Ent_800D6618;

extern void fn_80223628(void *a, void *b, void *c);
extern void fn_80222838(void *p);
extern void *fn_80223104(s32 a, void *p);
extern void fn_800D6580(EvColl *s, void *p);
extern s32 fn_8020F3D4(s32 id, s32 n, Ent_800D6618 *e, ...);
extern s32 fn_8020F934(s32 id);
s32 fn_800CCCA4(u32 a, u32 b, u32 c);
s32 fn_800CD0B8(s32 a, s32 b, s32 c, s32 d);

s32 fn_800C8D90(void);
extern f32 fn_80090598(f32 x, s32 cx, f32 z, s32 cz);
extern void fn_80100700(u32 col);
extern void fn_801006E0(f32 a, f32 b);

/* The colour-zone object's info record is a float table (7 zones of 7 words, then the fallback). */
static inline f32* ZoneInfo(EvObj* e) {
    return e->ext->info;
}

void fn_800D5348(Task* o) {
    EvObj* w = o->work;
    f32* p = ZoneInfo(w) + 1;
    if (fn_800C8D90() != 0) {
        o->state = 0xFF;
    }
    if (lbl_80347450 != 0 && (o->state == 0xFF || lbl_803473A8 != 0)) {
        switch (o->state) {
        case 0: {
            f32 sum = 0.0f;
            f32 a0 = sum;
            f32 a1 = sum;
            f32 a2 = sum;
            f32 a3 = sum;
            f32 a4 = sum;
            f32 cx = lbl_80347450->pos.x;
            f32 cz = lbl_80347450->pos.z;
            u32 r, g, b;
            if (lbl_80347450->pos.y > -150.0f) {
                s32 i = 0;
                do {
                    f32 wt = fn_80090598(cx, p[0], cz, p[1]);
                    a0 = wt * p[2] + a0;
                    sum = sum + wt;
                    a1 = wt * p[3] + a1;
                    a2 = wt * p[4] + a2;
                    a3 = wt * p[5] + a3;
                    a4 = wt * p[6] + a4;
                    p += 7;
                    i++;
                } while (i < 7);
                a0 = a0 / sum;
                a1 = a1 / sum;
                r = a2 / sum;
                g = a3 / sum;
                b = a4 / sum;
            } else {
                a0 = p[51];
                a1 = p[52];
                r = p[53];
                g = p[54];
                b = p[55];
            }
            fn_80100700(0xFF000000 | (r << 16) | (g << 8) | b);
            fn_801006E0(a0, a1);
            break;
        }
        case 1:
            break;
        case 0xFF:
            fn_80100B74(o);
            break;
        }
    }
}

extern void fn_801E8004(void* a, s32 b);
extern void fn_801E7E5C(void* a, s32 b);
extern void GXInvalidateVtxCache(void);
extern void fn_801DDE5C(void* h);
void fn_800D5584(EvObj* w);

/* A looping frame sequence: count, loop flag, then (frame, hold) pairs (EvObj.x25c). */
typedef struct {
    s16 count;
    s16 loop;
    s16 ent[2];
} EvFrameSeq;

static inline EvFrameSeq* FrameSeq(EvObj* e) {
    return e->x25c;
}

void fn_800D57E8(Task* o) {
    EvObj* w = o->work;
    switch (o->state) {
    case 0:
    case 0xFE:
        fn_800D5584(w);
        if (w->x1ac != 0) {
            o->state = 1;
        } else {
            o->state = 2;
        }
        break;
    case 1:
        if (fn_800D2924(w) != 0) {
            fn_801E6438(w);
            if (w->x1ac != 0 && w->x202 != 0) {
                w->x1ac->s1a = -1;
                if (w->x1fc == 0) {
                    fn_801E8004(w->x1ac->w0, w->x202);
                } else {
                    fn_801E7E5C(w->x1ac->w0, w->x202);
                }
            }
            if (w->x260 != 0) {
                fn_801DD7D8(w->x1b0);
            }
            if (FrameSeq(w) != 0) {
                if (w->x200 <= 1) {
                    s16* ent = FrameSeq(w)->ent;
                    w->x1fe = w->x1fe + 1;
                    {
                        s16 n = FrameSeq(w)->count;
                        if (n <= w->x1fe) {
                            if (FrameSeq(w)->loop == 0) {
                                w->x1fe = 0;
                            } else {
                                w->x1fe = n - 1;
                            }
                        }
                    }
                    ent = ent + w->x1fe * 2;
                    w->x202 = ent[0];
                    w->x200 = ent[1];
                } else {
                    w->x200 = w->x200 - 1;
                }
            }
            GXInvalidateVtxCache();
        }
        break;
    case 2:
        break;
    default:
        if (w->x1ac != 0) {
            fn_802275A4(w->x1ac->w10, 0);
            fn_801DDE5C(w->x1ac);
            fn_801E17E0(w->x1ac);
            w->x1ac = 0;
        }
        if (w->x1b0 != 0) {
            fn_801DD95C(w->x1b0);
            w->x1b0 = 0;
        }
        fn_80100B74(o);
        break;
    }
}

void fn_800D6618(MapTask *t)
{
    EvObj *e = t->work;
    EvColl *s = e->coll;
    s32 ok;
    EvInfoMap *q;
    void *r;
    Ent_800D6618 ent;

    switch (t->state) {
    case 0:
        ok = 0;
        if (e->ext != NULL) {
            if (EvMapInfo(e)->count >= 9) {
                if (EvMapInfo(e)->w4 >= 0) {
                    e->x1b4 = fn_80225B74(0xffff, EvMapInfo(e)->w4);
                }
                if (e->coll != NULL) {
                    e->coll->h16 = 0;
                    ok = 1;
                }
            }
        }
        if (ok != 0) {
            t->state = 2;
        } else {
            t->state = 7;
        }
        break;
    case 1:
        fn_800CCCA4(8, EvMapInfo(e)->nearDist, 0x50000);
        t->state = 2;
    case 2:
        if (e->x1b4 != NULL) {
            MemCopy(&e->home, &e->pos, 12);
            fn_80223628(&e->pos, &e->pos, e->x1b4);
            if (MemEqual(&e->home, &e->pos, 12) == 0) {
                fn_80222838(e->coll);
            }
        }
        if (s->h16 == 0 && lbl_80347450 != NULL && lbl_80347450->coll != NULL
            && fn_80222B30(s, lbl_80347450->coll) != 0) {
            r = fn_80223104(0x15, s);
            if (r != NULL && fn_80222B30(r, lbl_80347450->coll) != 0) {
                fn_800D6580(s, r);
            }
        }
        if (s->h16 != 0) {
            s->h14 = -0x8000;
            if (s->h16 == 1) {
                q = e->ext->info;
                fn_800CD0B8(8, q->nearDist, 0x40000, 0);
                ent.x = e->pos.x;
                ent.y = 1.17549435e-38f;
                ent.z = e->pos.z;
                ent.f18 = 0.7f;
                ent.w1c = 2;
                ent.w20 = 0x7fffffff;
                ent.f24 = 1.0f;
                ent.w28 = q->w4;
                ent.w2c = 1;
                fn_8020F3D4(-1, 1, &ent);
                fn_8020F934(-1);
                t->state = 3;
            } else {
                t->state = 6;
            }
        }
        break;
    case 3:
        fn_800CCCA4(8, EvMapInfo(e)->nearDist, 0x40000);
        t->state = 4;
    case 4:
        if (fn_8015F1F0(lbl_80347450) != 0) {
            t->state = 5;
        }
        break;
    case 5:
        if (fn_8015F1F0(lbl_80347450) == 0) {
            s = e->coll;
            s->h16 = 0;
            s->h14 = 0;
            s->p4->h16 = 0;
            s->p4 = NULL;
            fn_800CD0B8(8, EvMapInfo(e)->nearDist, 0x50000, 0);
            t->state = 1;
        }
        break;
    case 6:
        if (s->h16 == 0) {
            s->h14 = 0;
            t->state = 2;
        }
        break;
    case 7:
    case 0xfe:
        break;
    default:
        fn_80100B74(t);
        break;
    }
}

extern void fn_80223324(Hnd *h);
extern void fn_801E735C(s32 a, void* o, f32 f);
extern void fn_801E7C6C(NJS_POINT3 *out, f32 a, f32 b, NJS_MOTION *o);
extern void njCalcVector(NJS_MATRIX m, NJS_VECTOR *v, NJS_VECTOR *out);
extern NJS_POINT3 lbl_802B15A0;
static inline s32 MapInfoSpeed(EvInfoMap* c, s32 def) {
    if (c->count > 11) {
        return c->speed;
    }
    return def;
}

static inline s32 MapInfoActDist(EvInfoMap* c, s32 def) {
    if (c->count > 9) {
        return c->actDist;
    }
    return def;
}

void fn_800D6C04(EvObj* o) {
    NJS_MATRIX m60;
    NJS_MATRIX m20;
    NJS_POINT3 v14;
    NJS_POINT3 v8;
    NJS_MOTION* e;
    EvInfoMap* lim;
    ItemList* list;
    EvExt* a;
    Hnd* sub;
    f32 f31;
    sub = o->x1b4;
    a = o->ext;
    lim = a->info;
    f31 = 0.01f * MapInfoSpeed(lim, 100);
    list = a->items;
    if (list->count > 2) {
        NJS_MOTION* t = list->items[2];
        e = 0;
        if (t != 0) {
            e = t;
        }
    } else {
        e = 0;
    }
    sub->motion = e;
    o->x24c.x = f31;
    if (0.0f > f31) {
        sub->frame = e->nbFrame - 1.0f;
    } else {
        sub->frame = 0.0f;
    }
    fn_80223324(sub);
    fn_801E735C(0, o, 0.01f * MapInfoActDist(lim, 0));
    o->x1ee = 0;
    fn_801E7C6C(&v14, 10.0f * f31 + sub->frame, sub->frame, e);
    njUnitMatrix(m60);
    njRotateXYZ(m60, o->ang[0], o->ang[1], o->ang[2]);
    njCalcVector(m60, &v14, &o->vel);
    v8 = lbl_802B15A0;
    njUnitMatrix(m20);
    njTranslate(m20, o->pos.x, o->pos.y, o->pos.z);
    njRotateXYZ(m20, o->ang[0], o->ang[1], o->ang[2]);
    njTranslate(m20, o->pivotPos.x, o->pivotPos.y, o->pivotPos.z);
    njCalcPoint(m20, &v8, &o->x158);
}

int fn_800D7B04(void) {
    return lbl_80310A1C[0x11] != 2;
}

void fn_800D249C(s32 n, f32 a, f32 b, f32 c, f32 d) {
    if (n < 1) {
        return;
    }
    if (1.0f < a) {
        a = 1.0f;
    } else if (0.0f > a) {
        a = 0.0f;
    }
    if (1.0f < b) {
        b = 1.0f;
    } else if (0.0f > b) {
        b = 0.0f;
    }
    if (1.0f < c) {
        c = 1.0f;
    } else if (0.0f > c) {
        c = 0.0f;
    }
    if (1.0f < d) {
        d = 1.0f;
    } else if (0.0f > d) {
        d = 0.0f;
    }
    lbl_80305B5C.f30 = b;
    lbl_80305B5C.f40 = d;
    lbl_80305B5C.f34 = a;
    lbl_80305B5C.f44 = c;
    lbl_80305B5C.n48 = n;
}

void fn_800D25C4(u32 rgb, s32 n) {
    u32 w = *(u32 *)((u8*)&lbl_80305BE8 + 0x10);

    if (n >= 1) {
        u32 w0 = w & 0xFF;
        u32 w1 = (w >> 8) & 0xFF;
        u32 w2 = (w >> 16) & 0xFF;
        u32 c0 = rgb & 0xFF;
        u32 c1 = (rgb >> 8) & 0xFF;
        u32 c2 = (rgb >> 16) & 0xFF;

        lbl_80305B5C.f10 = (f32)w0;
        lbl_80305B5C.fc = (f32)w1;
        lbl_80305B5C.f8 = (f32)w2;
        lbl_80305B5C.f20 = (f32)c0;
        lbl_80305B5C.f1c = (f32)c1;
        lbl_80305B5C.f18 = (f32)c2;
        lbl_80305B5C.n24 = n;
    }
}

s32 fn_800D2924(EvObj *self) {
    s32 ret;

    if (lbl_80305BE8.a6 == 0) {
        self->hidden = 0;
        ret = 1;
    } else if (lbl_80305BE8.u2a == 0xFFFF) {
        self->hidden = 1;
        ret = 0;
    } else if (self->ext != 0) {
        if (lbl_80305BE8.w3c == self->ext->x34) {
            self->hidden = 0;
            ret = 1;
        } else {
            self->hidden = 1;
            ret = 0;
        }
    } else {
        self->hidden = 0;
        ret = 1;
    }
    return ret;
}

void fn_800D2B1C(Self_800D2B1C *self) {
    s32 n = self->n0;
    Ctl_80305BE8 *ctl = &lbl_80305BE8;
    s32 val = ctl->w3c - 1;
    Item68 *p;
    IdList *list;
    s32 *ids;
    s32 cnt;
    Item68 *hit;
    s32 w;
    s32 w29;

    if (n > 0) {
        p = self->items;
        do {
            p->v34 = val;
            p++;
            n--;
        } while (n > 0);
    }

    if (lbl_80305BE8.grp != 0) {
        list = lbl_80305BE8.grp->list;
        w29 = lbl_80305BE8.w3c;
        if (list != 0) {
            cnt = list->count;
            if (cnt > 0) {
                ids = list->ids;
                do {
                    w = *ids;
                    if (w < 0) {
                        hit = fn_801005F8(self, (u16)w);
                        if (hit != 0) {
                            hit->v34 = w29;
                        }
                    }
                    cnt--;
                    ids++;
                } while (cnt > 0);
            }
        }
    }
}

s32 fn_800D3598(Self_800D3598 *self) {
    s32 r = self->f184;

    if (r == 0) {
        EvObj *t = lbl_80347450;

        if (t != 0) {
            f32 dy = self->fb4 - t->pos.x;
            f32 dx = self->fb8 - t->pos.y;
            f32 dz = self->fbc - t->pos.z;
            f32 d = dy * dy + dx * dx + dz * dz;

            if (12250000.0f < d) {
                self->f1c = -1.0f;
                r = 1;
            } else if (9000000.0f >= d) {
                self->f1c = 0.0f;
            } else {
                self->f1c = -(fn_80291A5C(d) - 3000.0f) / 500.0f;
            }
        }
    }
    return r;
}

s32 fn_800D5210(Task* task, Handler* tbl, s32 n) {
    Ent_800D5210* e = task->work;
    s32 ok = 0;
    Blob_800D5210* b;
    Rec_800D5210* cur;
    Rec_800D5210* next;
    Handler* h;
    s32 rem;
    s32 len;
    s32 k;
    s16 id;

    if (e == NULL || n <= 0) {
        return 0;
    }
    if (e->ext != NULL) {
        b = e->ext->blob;
        if (b->count > 8) {
            rem = b->count - 8;
            cur = &b->first;
            do {
                id = cur->id;
                if (id == 0) {
                    break;
                }
                len = cur->len;
                ok = 0;
                k = n;
                h = tbl;
                do {
                    if (id == h->id) {
                        if (h->arg < 0 || len == h->arg) {
                            if (h->func != NULL) {
                                ok = h->func(task, e, cur->args, len);
                            } else {
                                ok = 1;
                            }
                        }
                        break;
                    }
                    h++;
                } while (--k > 0);
                next = NULL;
                if (cur != NULL && cur->id != 0) {
                    s32 step = cur->len + 1;
                    if ((s16)rem > step) {
                        next = (Rec_800D5210*)((s32*)cur + step);
                    }
                }
                cur = next;
                rem -= len + 1;
            } while (rem > 0 && ok != 0);
        }
    }
    return ok;
}

s32 fn_800D5E78(Ent_800D5E78* e) {
    Key_800D5E78* k;
    s32 r = 0;

    if (e->x1fe <= 1) {
        e->x1c = e->x24c;
        k = e->x25c->keys;
        e->x1fc++;
        if (e->x1fc >= e->x25c->count) {
            r = e->x25c->mode & 0xFF;
            switch (r) {
            case 1:
                e->x1fc = e->x25c->count - 1;
                break;
            case 2:
                e->x1fc = 0;
                break;
            case 3:
                e->x1fc = e->x25c->count - 1;
                break;
            }
        }
        k += e->x1fc;
        e->x24c = (f32)(k->value & 0xFF);
        e->x1fe = k->frames;
    } else {
        e->x1c = e->x1c + (e->x24c - e->x1c) / (f32)e->x1fe;
        e->x1fe--;
    }
    return r;
}

s32 fn_800D5F94(Ent_800D5F94* e) {
    Key_800D5F94* k;
    s16 v;
    s32 r = 0;

    if (e->x202 <= 1) {
        k = e->x260->keys;
        e->x200++;
        if (e->x260->count <= e->x200) {
            r = e->x260->mode & 0xFF;
            switch (r) {
            case 1:
                e->x200 = e->x260->count - 1;
                break;
            case 2:
                e->x200 = 0;
                break;
            case 3:
                e->x200 = e->x260->count - 1;
                break;
            }
        }
        e->x202 = k[e->x200].frames;
        k = e->x260->keys;
        k += e->x200;
        v = k->value;
        if (v >= 0) {
            e->x23c = *(*(Node**)((u8*)e->x100->recs + v * 12 + 8))->data;
        } else {
            e->x23c = -1;
        }
    } else {
        e->x202--;
    }
    return r;
}

s32 fn_800D6138(s32 unused, u8* d, Src6138* s, s16 n)
{
    s32 ret = 0;
    s32 mode;
    s32 size;
    size = ((s->count - 1) * 8 + 0x10) / 4;
    if (size == n) {
        *(Src6138**)(d + 0x264) = s;
        *(s16*)(d + 0x204) = 0;
        mode = 6;
        if (s->flags & 0x8000) {
            mode = 10;
        }
        *(s32*)(d + 0x34) = mode;
        ret = 1;
        *(f32*)(d + 0x20) = s->r;
        *(f32*)(d + 0x24) = s->g;
        *(f32*)(d + 0x28) = s->b;
        *(f32*)(d + 0x250) = s->r2;
        *(f32*)(d + 0x254) = s->g2;
        *(f32*)(d + 0x258) = s->b2;
        *(s16*)(d + 0x206) = s->val;
        *(u32*)(d + 0x188) |= 4;
    }
    return ret;
}

void fn_800D7D60(Obj7D60* o)
{
    s32 i;
    s32 n;
    f32 a, b, c, d, cur, dur;

    if (1.0f > o->timer) {
        o->timer += 0.33333334f;
        if (1.0f < o->timer) {
            o->timer = 1.0f;
        }
    }
    n = o->n;
    i = 0;
    do {
        if (o->en[i] != 0) {
            if (n == 0) {
                dur = 2.0f;
                a = -3.0f;
                b = -6.0f;
                c = 1.0f;
                d = dur;
            } else {
                d = 0.0f;
                dur = -2.0f;
                c = d;
                b = d;
                a = d;
            }
            cur = o->f14[i][0];
            if (a != cur) {
                o->f14[i][0] = cur + -3.0f / dur;
                cur = cur - a;
                if (0.0f < cur * (o->f14[i][0] - a)) {
                    o->f14[i][1] = o->f14[i][1] + -6.0f / dur;
                    o->f2c[i][0] = o->f2c[i][0] + 1.0f / dur;
                    o->f2c[i][1] = o->f2c[i][1] + 2.0f / dur;
                } else {
                    o->f14[i][0] = a;
                    o->f14[i][1] = b;
                    o->f2c[i][0] = c;
                    o->f2c[i][1] = d;
                }
            }
            n--;
        }
        i++;
    } while (i < 3);
}

void fn_800D29B4(s32 val, Part_800D29B4* group, IdList* list) {
    extern s32 lbl_8034745C;
    extern Group_800D29B4* lbl_80347460;
    extern Part_800D29B4* fn_8010062C(Part_800D29B4* group, u16 id);
    extern Part_800D29B4* fn_801005F8(Part_800D29B4* group, u16 id);
    extern void fn_801DBE1C(const char* fmt, ...);
    Group_800D29B4* g;
    s32 n;
    s32 id;
    Part_800D29B4* sub;
    s32* p;
    Part_800D29B4* prev = NULL;
    if (list != NULL && (n = list->count) > 0) {
        p = list->ids;
        do {
            Part_800D29B4* r;
            id = *p;
            if (id >= 0) {
                r = fn_8010062C(group, (u16)id);
                if (r != NULL) {
                    r->w34 = val;
                } else {
                    fn_801DBE1C("OVER MAP INDEX(SIGHT)%d", id);
                }
            } else {
                if (prev != NULL) {
                    r = fn_801005F8(prev, (u16)id);
                } else {
                    r = NULL;
                }
                if (r == NULL) {
                    if (lbl_8034745C > 0) {
                        if (prev == NULL) {
                            for (g = lbl_80347460; g != NULL && r == NULL; g = g->next) {
                                sub = g->part;
                                if (sub != NULL && group != sub) {
                                    r = fn_801005F8(sub, (u16)id);
                                }
                            }
                        } else {
                            for (g = lbl_80347460; g != NULL && r == NULL; g = g->next) {
                                sub = g->part;
                                if (sub != NULL && group != sub && prev != sub) {
                                    r = fn_801005F8(sub, (u16)id);
                                }
                            }
                        }
                        if (r != NULL) {
                            r->w34 = val;
                            prev = sub;
                        }
                    }
                } else {
                    r->w34 = val;
                }
            }
            p++;
        } while (--n > 0);
    }
}

u8 fn_800D5CF4(Obj_800D5CF4* o) {
    Key_800D5CF4* k;
    u8 ret = 0;
    if (o->timer <= 1) {
        o->cur[0] = o->tgt[0];
        o->cur[1] = o->tgt[1];
        o->cur[2] = o->tgt[2];
        k = o->list->keys;
        o->idx++;
        if (o->list->count <= o->idx) {
            ret = (u8)o->list->type;
            switch (ret) {
            case 1:
                o->idx = o->list->count - 1;
                break;
            case 2:
                o->idx = 0;
                break;
            case 3:
                o->idx = o->list->count - 1;
                break;
            }
        }
        k += o->idx;
        o->tgt[0] = k->r;
        o->tgt[1] = k->g;
        o->tgt[2] = k->b;
        o->timer = k->time;
    } else {
        f32 t = o->timer;
        o->cur[0] += (o->tgt[0] - o->cur[0]) / t;
        o->cur[1] += (o->tgt[1] - o->cur[1]) / t;
        o->cur[2] += (o->tgt[2] - o->cur[2]) / t;
        o->timer--;
    }
    return ret;
}

s32 fn_800D7E7C(Menu* m) {
    s32 ret;
    if (m->count > 1) {
        u32 flags;
        s16 old = m->cur;
        flags = (*(Ctrl*(*)[])&lbl_80311A60)[lbl_8034757C]->flags;
        if ((flags & 8) || lbl_80311A14[lbl_8034757C].b3 > 30) {
            m->cur--;
        } else if ((flags & 4) || lbl_80311A14[lbl_8034757C].b2 > 30) {
            m->cur++;
        }
        if (m->cur < 0) {
            m->cur = m->count - 1;
        } else if (m->count <= m->cur) {
            m->cur = 0;
        }
        if (old != m->cur) {
            SePlay(1, 1, 0);
        }
    }
    {
        u32 flags;
        if ((lbl_80311A00[1] & (flags = (*(Ctrl*(*)[])&lbl_80311A60)[lbl_8034757C]->flags)) || (flags & 0x1000)) {
            ret = -1;
        } else if (lbl_80311A00[0] & flags) {
            s16* p = &m->cur;
            s32 i = 0;
            s32 n = m->cur;
            do {
                if (p[6] != 0) {
                    if (n == 0) m->sel = i;
                    n--;
                }
                i++;
                p++;
            } while (i < 3);
            ret = 1;
            SePlay(1, 1, 2);
        } else {
            ret = 0;
        }
    }
    return ret;
}

void fn_800D3824(Obj_800D3824* o) {
    NJS_POINT3 v14;
    NJS_POINT3 v8;
    f32 f2;
    f32 f3 = o->f254;
    s32 n;
    Obj_800D3824* c;
    f32 f1;
    s32 n2;
    f2 = o->f258;
    n = (s32)(f3 / f2);
    c = lbl_8034749C->c24;
    if (n != 0) {
        f3 = f3 - f2 * (f32)n;
    }
    o->f18c = f3;
    njPushMatrixEx();
    fn_80286EE8();
    fn_8028B498();
    fn_801E7B2C(o->motion, &v14, 0, o->f18c);
    njUnitMatrix(0);
    njRotateY(0, -(n << 13));
    njCalcPoint(0, &v14, (NJS_POINT3*)o->pos);
    f1 = o->f254;
    f2 = o->f250;
    f1 = f1 + f2;
    if (0.0f > f2 && 0.0f > f1) {
        f1 = f1 + (f32)o->s210;
    }
    f3 = o->f258;
    {
        void* mo = o->motion;
    n2 = (s32)(f1 / f3);
    if (n2 != 0) {
        f1 = f1 - f3 * (f32)n2;
    }
    fn_801E7B2C(mo, &v14, 0, f1);
    }
    njUnitMatrix(0);
    njRotateY(0, -(n2 << 13));
    njCalcPoint(0, &v14, &v8);
    njPopMatrixEx();
    v8.x = v8.x - o->pos[0];
    v8.y = v8.y - o->pos[1];
    v8.z = v8.z - o->pos[2];
    fn_801DD5E8(o->off, &v8);
    o->s48 = c->s48;
    o->pos[0] = o->pos[0] - c->pos[0];
    o->pos[1] = o->pos[1] - c->pos[1];
    o->pos[2] = o->pos[2] - c->pos[2];
}
s32 fn_800C3518(EvObj *obj);

void fn_800D3A20(Obj_800D3A20* o) {
    extern void fn_800C3518(void* o);
    extern void fn_801E735C(s32 a, void* o, f32 f);
    extern Ent_800D3A20* fn_80100684(u32 id, s32 n);
    extern s32 fn_801E183C(void);
    Tbl_800D3A20* t;
    Ent_800D3A20* e;
    s32 v;
    f32 f;
    fn_800C3518(o);
    o->pos[2] = 0.0f;
    o->pos[1] = 0.0f;
    o->pos[0] = 0.0f;
    o->f15c = 0.0f;
    o->s16c = 1;
    t = (Tbl_800D3A20*)o->p1c8->tbl;
    if (t->count > 8) {
        v = t->v24;
    } else {
        v = 0;
    }
    f = (f32)v / 100.0f;
    o->f24c = f;
    fn_801E735C(0, o, 0.0f);
    if (t->count > 9) {
        v = t->v28;
    } else {
        v = 0;
    }
    if (0.0f > f) {
        v = -v;
    }
    o->f250 = (f32)v / 100.0f;
    if (t->count > 10) {
        v = t->v2c;
    } else {
        v = 0;
    }
    o->f254 = (f32)v / 100.0f;
    if (t->count > 11) {
        v = t->v30;
    } else {
        v = 0;
    }
    o->s20c = v;
    o->s180 = v;
    if (o->motion != 0) {
        s32 n = o->motion->nframes - 1;
        o->f258 = (f32)n;
        o->s210 = n << 3;
    }
    e = fn_80100684((u16)o->p1c8->id, 12);
    if (fn_801E183C() == 0) {
        o->f254 = e->f0;
        o->s180 = e->s4;
        o->f15c = e->f8;
    }
}
s32 fn_800C34C8(Obj_800C34C8 *obj);

void fn_800D5584(EvObj* w) {
    extern s32 fn_800C34C8(void* w);
    extern s32 fn_800C3518(void* w);
    extern void fn_801E7DF0(void* p);
    extern void* fn_801E1C7C(u32 size);
    extern void fn_801DDECC(EvDraw* h, void* model, NJS_TEXLIST* a, NJS_TEXLIST* b);
    extern void* fn_801DD984(void);
    extern void fn_801DDE5C(void* h);
    extern void fn_801E17E0(void* p);
    extern void* fn_800D51C0(void* p, s32 k);
    extern void fn_801DD8EC(void* a, s32* b, s32 c, s32 d);
    EvExt* t;
    EvInfoDraw* tbl;
    s32 flag = 0;
    t = w->ext;
    tbl = t->info;
    if (fn_800C34C8(w) != 0) {
        flag = 1;
    } else if (fn_800C3518(w) != 0) {
        flag = 1;
        t = 0;
    }
    if (flag != 0) {
        fn_801E7DF0(w->model);
        w->x1ac = fn_801E1C7C(0x20);
        if (w->x1ac != 0) {
            w->x1ac->w0 = 0;
            if (tbl->count > 10) {
                w->x1fc = tbl->v2c;
                w->x202 = 1;
                w->x1ac->s1c = tbl->v24;
                w->x1ac->s1e = tbl->v28;
                if (w->x1ac->s1c > 0 && w->x1ac->s1e > 0) {
                    if (t != 0) {
                        fn_801DDECC(w->x1ac, w->model, w->texlist, t->texlist);
                    } else {
                        fn_801DDECC(w->x1ac, w->model, w->texlist, w->texlist);
                    }
                }
            }
            w->x1b0 = 0;
            if (w->x1ac->w0 != 0 && w->x1ac->w14 != 0) {
                w->x1b0 = fn_801DD984();
            }
            if (w->x1b0 == 0) {
                fn_801DDE5C(w->x1ac);
                fn_801E17E0(w->x1ac);
                w->x1ac = 0;
            }
        }
    }
    {
        EvInfoDraw* t2 = w->ext->info;
        BlkA_800D5584* e;
        if (t2->count > 11) {
            e = fn_800D51C0(t2->recs, 2);
        } else {
            e = 0;
        }
        if (e != 0) {
            s32* d = &e->b;
            s32 n = e->n;
            if (n == ((*d - 1) * 4 + 8) / 4) {
                if (w->x1b0 != 0) {
                    w->x260 = d;
                    fn_801DD8EC(w->x1b0, d + 1, *d, 1);
                }
            }
        }
    }
    {
        EvInfoDraw* t3 = w->ext->info;
        BlkB_800D5584* e;
        if (t3->count > 11) {
            e = fn_800D51C0(t3->recs, 3);
        } else {
            e = 0;
        }
        if (e != 0) {
            s32 n = e->n;
            s16* d = &e->b;
            if (n == ((*d - 1) * 4 + 8) / 4) {
                w->x25c = d;
                w->x1fe = 0;
                w->x202 = d[2];
                w->x200 = d[3];
            }
        }
    }
}

void fn_800D6390(Obj_800D6390* o) {
    extern u8 lbl_802E1450[];
    extern s32 fn_800C3518(void* w);
    extern void fn_800D6088(void* w);
    extern s32 fn_8015F218(void* w);
    extern void fn_800D5210(void* o, void* tbl, s32 k);
    extern void fn_800D59CC(void* w);
    extern s32 fn_800D5F94(void* w);
    extern s32 fn_800D5E78(void* w);
    extern s32 fn_800D5CF4(void* w);
    extern void fn_800C3428(void* o);
    s32 ok;
    Work_800D6390* w = o->work;
    switch (o->state) {
    case 0: {
        f32 z;
        w->s100 = w->p1c8->v20;
        if (fn_800C3518(w) == 0) {
            w->s100 = 0;
        }
        z = 255.0f;
        w->f28 = z;
        w->f24 = z;
        w->f20 = z;
        w->f1c = z;
        fn_800D6088(w);
        switch (fn_8015F218(w)) {
        case 0:
            o->state = 1;
            break;
        case 1:
            o->state = 2;
            break;
        case 2:
            o->state = 1;
            break;
        }
        o->f20 = -1.0f;
        break;
    }
    case 1:
        if (fn_8015F218(w) == 1) {
            o->state = 2;
        }
        break;
    case 2:
        fn_800D5210(o, lbl_802E1450, 3);
        o->state = 3;
    case 3:
        if (fn_8015F218(w) != 2) {
            ok = 1;
            fn_800D59CC(w);
            if (w->flags188 & 1) {
                if (fn_800D5F94(w) == 3) {
                    ok = 0;
                }
            }
            if (w->flags188 & 2) {
                if (fn_800D5E78(w) == 3) {
                    ok = 0;
                }
            }
            if (w->flags188 & 4) {
                if (fn_800D5CF4(w) == 3) {
                    ok = 0;
                }
            }
            if (ok == 0) {
                o->state = 1;
            }
        } else {
            o->state = 1;
        }
        break;
    case 0xFE:
        break;
    default:
        if (w->p268 != 0) {
            fn_801E1784(w->p268);
        }
        fn_800C3428(o);
        break;
    }
}

s32 fn_800D6E1C(EvObj* o) {
    s8 d;
    s32 res = -1;
    Ent_800D6E1C* e = fn_800CCA6C(8, o->ext->x04);
    s8 t;
    s32 r;
    if (e != 0) {
        Sub_800D6E1C* sub = e->sub;
        if (sub != 0) {
            s32 k;
            if (sub->v1c == 0) {
                k = o->x1ee;
            } else {
                k = sub->v1c - 1;
            }
            d = k;
            sub->v0 = 2;
        }
        switch (e->kind >> 16) {
        case 0:
            t = ((s8)d == 0) ? 6 : 8;
            o->x1ed = 0;
            o->x1ec = 1;
            if (t == 6) {
                o->x1ef = 1;
                r = 5;
            } else {
                r = 7;
                o->x1ef = 0;
            }
            res = r;
            break;
        case 1:
            t = ((s8)d == 0) ? 6 : 8;
            o->x1ed = 1;
            o->x1ec = 1;
            if (t == 6) {
                o->x1ef = 1;
                r = 5;
            } else {
                r = 7;
                o->x1ef = 0;
            }
            res = r;
            o->x1ed = 0;
            o->x1ec = 0;
            break;
        case 2:
            t = ((s8)d == 0) ? 6 : 8;
            o->x1ed = 1;
            o->x1ec = 1;
            if (t == 6) {
                o->x1ef = 1;
                r = 5;
            } else {
                r = 7;
                o->x1ef = 0;
            }
            res = r;
            break;
        case 3:
            o->x1ed = 0;
            o->x1ec = 0;
            d = (s8)d;
            if (d == 0) {
                fn_800D6C04(o);
            } else {
                fn_800D6974(o);
            }
            o->x1ee = d;
            res = 2;
            o->x1ef = d;
            break;
        case 4:
            o->x188 |= 1;
            break;
        case 5:
            o->x188 &= ~1;
            break;
        }
    }
    return res;
}

void fn_800D2048(void)
{
    GXColor color = { 0, 0, 0, 0 };

    GXSetFog(0, 0.0f, 0.0f, 0.0f, 0.0f, color);
    fn_80296F28();
}

void FogOff(void)
{
    GXColor color = { 0, 0, 0, 0 };

    GXSetFog(0, 0.0f, 0.0f, 0.0f, 0.0f, color);
    fn_80296F28();
}

void fn_800D23F8(s32 n, f32 a, f32 b, s32 m)
{
    lbl_80305B28.flag = 1;
    lbl_80305B28.f1c = a;
    lbl_80305B28.f20 = b;
    lbl_80305B28.i30 = n > 1 ? n : 1;
    if (m < 2) {
        lbl_80305B28.f20 = 0.0f;
    } else {
        lbl_80305B28.i2c = 0x10000 / m;
    }
}

void fn_800D244C(s32 n, f32 a, f32 b, s32 m)
{
    lbl_80305B28.mode = 1;
    lbl_80305B28.f04 = a;
    lbl_80305B28.f08 = b;
    lbl_80305B28.i18 = n > 1 ? n : 1;
    if (m < 2) {
        lbl_80305B28.f08 = 0.0f;
    } else {
        lbl_80305B28.i14 = 0x10000 / m;
    }
}

void fn_800D3C00(Task_800D3C00 *self)
{
    Obj_800D3C00 *e = *(Obj_800D3C00 **)((char *)self + 0x24);
    Hnd *h;
    Rec *p;
    s32 ok;
    s32 *tb;

    fn_800D2924((void *)(e));
    switch (*((u8 *)self + 0x19)) {
    case 0:
    case 0xfe:
        fn_800D3A20((void *)(e));
        if (e->ie8 != 0) {
            ok = 0;
            tb = ((s32*)&lbl_80311AC0);
            if (tb[1] == 0x6b) {
                if (((s8 *)tb)[8] == 0x64) ok = 1;
            } else if (tb[1] == 0xd1) {
                if (((s8 *)tb)[8] == 0x61) ok = 1;
            }
            if (ok != 0) {
                *((u8 *)self + 0x19) = 1;
                break;
            }
        }
        *((u8 *)self + 0x19) = 3;
        break;
    case 1:
        if ((*(Hd **)&lbl_8034749C)->state == 4) {
            fn_800D3824((void *)(e));
            if (e->p1c8 != 0) {
                h = fn_80225B74(0xffff, (u16)e->p1c8->i4);
                e->p1b4 = h;
                if (h != 0) {
                    h->p1c = e->pos38;
                    h->p24 = e->v44;
                    h->p28 = e->vb4;
                    h->p2c = e->vc0;
                    fn_802233EC(h);
                }
            }
            *((u8 *)self + 0x19) = 2;
        }
        break;
    case 2:
        if (e->p1b4 != 0) {
            fn_802234D4(e->p1b4);
        }
        if (e->timer <= 0) {
            fn_800D3824((void *)(e));
            if (*(u32 *)(((u8*)lbl_80310B3C) + 0xe8) & 1) {
                e->f254 = e->f254 + e->f24c;
                if (0.0f <= e->f24c) {
                    if (e->f254 > (f32)e->i210) {
                        e->f254 = e->f254 - (f32)e->i210;
                    }
                } else {
                    if (e->f254 < 0.0f) {
                        e->f254 = e->f254 + (f32)e->i210;
                    }
                }
            }
            h = e->p1b4;
            if (h != 0) {
                if (MemEqual(h->p24, h->v48, 12) == 0) {
                    h->flags |= 1;
                }
                if (MemEqual(h->p28, h->v54, 12) == 0 || MemEqual(h->p2c, h->v60, 12) == 0) {
                    h->flags |= 2;
                }
            }
        } else {
            e->timer = e->timer - 1;
        }
        fn_800D3598((void *)(e));
        fn_801E66E0((void *)(e));
        break;
    case 3:
        fn_801E66E0((void *)(e));
        break;
    default:
        p = fn_80100684((u16)e->p1c8->i4, 0xc);
        p->a = e->f254;
        p->b = e->timer;
        p->c = e->f15c;
        fn_800C3428((void *)(self));
        break;
    }
}

/* Installs seq on o when its size in words matches: resets the step, copies the speed (b2),
 * h6's low byte and h4, and sets flag 2. Returns 1 if installed. */
s32 fn_800D6240(void* unused, Obj_800D6240* o, Seq_800D6240* seq, s16 words) {
    s32 ok = 0;
    s32 size = ((seq->n - 1) * 4 + 8) / 4; /* header + n words, in words */

    if (size == words) {
        o->seq = seq;
        o->x1fc = 0;
        ok = 1;
        o->x1c = seq->b2;
        o->x24c = seq->h6 & 0xff;
        o->x1fe = seq->h4;
        o->x188 |= 2;
    }
    return ok;
}

/* Installs script s on e when its size in words matches, starts it at key 0. */
s32 fn_800D62DC(void* unused, Ent_800D62DC* e, Script_800D5F94* s, s16 words)
{
    s32 ok = 0;
    s32 size = ((s->count - 1) * 8 + 0xc) / 4;
    s32 mode;
    Key_800D5F94* k;
    s16 v;

    if (size == words) {
        e->x260 = s;
        mode = 6;
        if (s->mode & 0x8000) {
            mode = 10;
        }
        e->x34 = mode;
        e->x200 = 0;
        e->x202 = s->keys[0].frames;
        k = e->x260->keys;
        k += e->x200;
        v = k->value;
        if (v >= 0) {
            e->x23c = *(*(Node**)((u8*)e->x100->recs + v * 12 + 8))->data;
        } else {
            e->x23c = -1;
        }
        e->x188 |= 1;
        ok = 1;
    }
    return ok;
}

void fn_800D3668(EvObj* o) {
    NJS_POINT3 v1, v2;
    f32 c;
    s32 q;
    f32 p;
    void *e;
    f32 x;
    x = o->x24c.z;
    p = o->x258;
    q = (s32)(x / p);
    if (q != 0) x = x - p * (f32)q;
    o->x18c = x;
    njPushMatrixEx();
    fn_80286EE8();
    fn_8028B498();
    fn_801E7B2C(o->motion, &v1, 0, o->x18c);
    njUnitMatrix(0);
    njRotateY(0, -(q << 13));
    njCalcPoint(0, &v1, &o->pivotPos);
    c = o->x24c.z + o->x24c.y;
    if (0.0f > o->x24c.y && 0.0f > c) c += (f32)o->x210;
    p = o->x258;
    e = o->motion;
    q = (s32)(c / p);
    if (q != 0) c = c - p * (f32)q;
    fn_801E7B2C(e, &v1, 0, c);
    njUnitMatrix(0);
    njRotateY(0, -(q << 13));
    njCalcPoint(0, &v1, &v2);
    njPopMatrixEx();
    v2.x = v2.x - o->pivotPos.x;
    v2.y = 0.0f;
    v2.z = v2.z - o->pivotPos.z;
    fn_801DD5E8(o->ang, &v2);
    o->ang[1] = (u16)(-o->ang[1]);
}

void fn_800D208C(u32 col, f32 start) {
    GXColor c;
    c.r = col >> 8;
    c.g = col >> 16;
    c.b = col >> 24;
    c.a = 0xff;
    GXSetFog(2, -20000.0f * start, -lbl_8034678C, -lbl_80346788, -lbl_8034678C, c);
    fn_80296F28();
}

void fn_800D3F00(Task_800D3F00 *self)
{
    Obj_800D3F00 *e = self->obj;
    Hnd_800D3F00 *h;
    Rec *p;
    s32 ok;

    fn_800D2924((void *)(e));
    switch (self->state) {
    case 0:
    case 0xfe:
        fn_800D3A20((void *)(e));
        if (e->ie8 != 0) {
            ok = 0;
            if ((*(MapInfo*)&lbl_80311AC0).map == 0x6b) {
                if ((*(MapInfo*)&lbl_80311AC0).room == 0x64) ok = 1;
            } else if ((*(MapInfo*)&lbl_80311AC0).map == 0xd1) {
                if ((*(MapInfo*)&lbl_80311AC0).room == 0x61) ok = 1;
            }
            if (ok != 0) {
                self->state = 1;
                break;
            }
        }
        self->state = 3;
        break;
    case 1:
        if ((*(Hd_800D3F00 **)&lbl_8034749C)->state == 4) {
            fn_800D3824((void *)(e));
            if (e->p1c8 != NULL) {
                h = ((Hnd_800D3F00 *)fn_80225B74(0xffff, (u16)e->p1c8->i4));
                e->p1b4 = h;
                if (h != NULL) {
                    h->p1c = e->pos38;
                    h->p24 = e->v44;
                    h->p28 = &e->vb4;
                    h->p2c = e->vc0;
                    fn_802233EC((void *)(h));
                }
            }
            self->state = 2;
        }
        break;
    case 2:
        if (e->p1b4 != NULL) {
            fn_802234D4((void *)(e->p1b4));
        }
        fn_800D3824((void *)(e));
        if (((u32*)lbl_80310B3C)[0xe8 / 4] & 1) {
            e->f254 = e->f254 + e->f24c;
            if (0.0f <= e->f24c) {
                if (e->f254 > (f32)e->i210) {
                    e->f254 = e->f254 - (f32)e->i210;
                }
            } else {
                if (e->f254 < 0.0f) {
                    e->f254 = e->f254 + (f32)e->i210;
                }
            }
        }
        if ((((u32*)lbl_80310B3C)[0xe8 / 4] & 1) == 0) {
            e->vb4.y = e->vb4.y + e->f15c;
        } else {
            if (e->timer <= 0) {
                if (e->i214 == 0) {
                    e->i214 = e->i214 + 1;
                    e->f15c = 0.25f;
                    e->timer = 5;
                } else {
                    e->i214 = 0;
                    e->f15c = 0.2f;
                    e->timer = 30;
                }
            } else {
                e->timer = e->timer - 1;
            }
            e->vb4.y = e->vb4.y + e->f15c;
            if (0.2f < e->f15c) {
                e->f15c = -0.25f;
            } else if (-0.2f > e->f15c) {
                e->f15c = 0.0f;
            } else if (0.0f < e->f15c) {
                e->f15c = -0.2f;
            } else if (0.0f > e->f15c) {
                e->f15c = 0.0f;
            }
        }
        h = e->p1b4;
        if (h != NULL) {
            if (MemEqual(h->p24, h->v48, 12) == 0) {
                h->flags |= 1;
            }
            if (MemEqual(h->p28, h->v54, 12) == 0 || MemEqual(h->p2c, h->v60, 12) == 0) {
                h->flags |= 2;
            }
        }
        fn_801E66E0((void *)(e));
        break;
    case 3:
        fn_801E66E0((void *)(e));
        break;
    default:
        p = ((Rec *)fn_80100684((u16)e->p1c8->i4, 12));
        p->a = e->f254;
        p->b = e->timer;
        p->c = e->f15c;
        fn_800C3428((void *)(self));
        break;
    }
}

void fn_800D2CC4(void) {
    Ctl_80305BE8* st = &lbl_80305BE8;
    Src_80305BA8* sr = &lbl_80305BA8;
    Part_800D29B4* key = st->u38;
    Part_800D29B4* tmp;
    R_800C4584* n = fn_801092C0(sr->h28, &key);
    if (n != NULL) {
        R_800C4584* m;
        u16 id;
        s32 raw;
        lbl_80305BE8.h28 = sr->h28;
        lbl_80305BE8.w3c = lbl_80305BE8.w3c + 1;
        if (n->p10->count > 0) {
            raw = n->p10->ids[0];
        } else {
            raw = -1;
        }
        id = raw;
        if (id != 0xFFFF) {
            tmp = key;
            m = fn_801091F8(id, &tmp);
        } else {
            m = NULL;
        }
        if (m != NULL) {
            lbl_80305BE8.u2a = m->w4;
            lbl_80305BE8.grp = m;
            st->u38 = tmp;
            m->w34 = lbl_80305BE8.w3c;
            lbl_80305BE8.u34 = key;
            lbl_80305BE8.u2c = n;
            if (lbl_80305BA8.b3 != 0) {
                fn_800D29B4(lbl_80305BE8.w3c, key, n->list);
            }
        } else {
            lbl_80305BE8.u2a = sr->h28;
            lbl_80305BE8.u2c = NULL;
            lbl_80305BE8.grp = n;
            lbl_80305BE8.u34 = 0;
            st->u38 = key;
        }
        n->w34 = lbl_80305BE8.w3c;
        fn_800D29B4(lbl_80305BE8.w3c, st->u38, lbl_80305BE8.grp->list);
    } else {
        lbl_80305BE8.h28 = 0xFFFF;
        lbl_80305BE8.u2a = 0xFFFF;
        lbl_80305BE8.grp = NULL;
        lbl_80305BE8.u2c = NULL;
        st->u38 = 0;
        lbl_80305BE8.u34 = 0;
    }
}

typedef struct {
    u8 pad0[4];
    u8 st4[0x58];
    u32 *col;           /* 0x5c */
    u8 pad60[8];
    NJS_POINT3 pos;     /* 0x68 */
    u8 pad74[0x8c - 0x74];
    f32 vx, vy, vz;     /* 0x8c */
    s32 n, total, k, end, amax;
    s32 *counter;
} Work_800D4F00;
extern void fn_80296EEC(s32 a, s32 b, s32 c);
extern void fn_8009076C(s32 a, void *p);

void fn_800D4F00(Task *t)
{
    Work_800D4F00 *e;
    NJS_POINT3 p;
    s32 v;
    u32 c;
    s32 n;
    s32 k;

    e = t->work;
    if (t->parent->flags & 0x40) {
        t->flags |= 0x40;
        return;
    }
    if (lbl_80347450 == 0) return;
    switch (t->state) {
    case 0:
        e->pos.x += e->vx;
        e->pos.y += e->vy;
        e->pos.z += e->vz;
        njCalcPoint(0, &e->pos, &p);
        t->f20 = p.z / 256.0f + (-16.0f);
        if (t->f20 > -16.0f) {
            t->f20 = -16.0f;
        }
        if (lbl_80347450->pos.x - lbl_80347450->home.x > 8400.0f) {
            e->pos.x += 16800.0f;
        } else if (lbl_80347450->pos.x - lbl_80347450->home.x < -8400.0f) {
            e->pos.x -= 16800.0f;
        }
        if (lbl_80347450->pos.z - lbl_80347450->home.z > 7200.0f) {
            e->pos.z += 14400.0f;
        } else if (lbl_80347450->pos.z - lbl_80347450->home.z < -7200.0f) {
            e->pos.z -= 14400.0f;
        }
        lbl_80346788 = lbl_80347560;
        lbl_8034678C = -1200.0f;
        njClipZ(lbl_80347560, -1200.0f);
        fn_80296EEC(1, 3, 0);
        fn_8009076C(0, e->st4);
        fn_80296EEC(1, 3, 1);
        if (e->n < e->total) {
            v = e->amax * e->n / e->total;
        } else {
            if (e->n > e->k) {
                v = e->amax + (-e->amax * (e->n - e->k)) / (e->end - e->k);
            } else {
                v = e->amax;
            }
        }
        c = (v << 24) | 0xffffff;
        e->col[0] = c;
        e->col[1] = c;
        e->col[2] = c;
        e->col[3] = c;
        e->n++;
        if (e->n >= e->end) {
            t->state = 0xff;
            t->f20 = 0.0f;
        }
        break;
    case 0xff:
        (*e->counter)--;
        t->flags |= 0x40;
        break;
    }
}

static inline NJS_MOTION *PickMotion(ItemList *l, s32 i)
{
    NJS_MOTION *p;
    NJS_MOTION *r;
    if (l->count > i) {
        p = l->items[i];
        r = 0;
        if (p != 0) r = p;
    } else {
        r = 0;
    }
    return r;
}

extern void fn_80223324(Hnd *h);
extern void fn_801E735C(s32 a, void* o, f32 f);
extern void fn_801E7C6C(NJS_POINT3 *out, f32 a, f32 b, NJS_MOTION *o);
extern void njCalcVector(NJS_MATRIX m, NJS_VECTOR *v, NJS_VECTOR *out);
extern NJS_POINT3 lbl_802B15A0;

void fn_800D6974(EvObj *self)
{
    Hnd *h;
    EvInfoMap *c;
    NJS_MOTION *mot;
    s32 n;
    f32 f;
    NJS_MATRIX m;
    NJS_MATRIX m2;
    NJS_POINT3 tmp;
    NJS_POINT3 v;

    h = self->x1b4;
    mot = PickMotion(self->ext->items, 3);
    c = self->ext->info;
    if (mot != 0) {
        n = (c->count > 0xc) ? c->x34 : 100;
        f = 0.01f * n;
    } else {
        n = (c->count > 0xc) ? c->x34 : -100;
        f = 0.01f * n;
        mot = PickMotion(self->ext->items, 2);
    }
    h->motion = mot;
    self->x24c.x = f;
    if (0.0f > f) {
        h->frame = mot->nbFrame - 1.0f;
    } else {
        h->frame = 0.0f;
    }
    fn_80223324(h);
    n = (c->count > 10) ? c->x2c : 0;
    fn_801E735C(1, self, 0.01f * n);
    self->x1ee = 1;
    fn_801E7C6C(&tmp, 10.0f * f + h->frame, h->frame, mot);
    njUnitMatrix(m);
    njRotateXYZ(m, self->ang[0], self->ang[1], self->ang[2]);
    njCalcVector(m, &tmp, &self->vel);
    v = lbl_802B15A0;
    njUnitMatrix(m2);
    njTranslate(m2, self->pos.x, self->pos.y, self->pos.z);
    njRotateXYZ(m2, self->ang[0], self->ang[1], self->ang[2]);
    njTranslate(m2, self->pivotPos.x, self->pivotPos.y, self->pivotPos.z);
    njCalcPoint(m2, &v, &self->x158);
}

extern char lbl_8030A5D4[0x100]; /* a text buffer (sprintf target) */

s32 fn_800D701C(EvObj* o) {
    EvExt* src = o->ext;
    Hnd* h;
    NJS_MOTION* p;
    EvInfo* inf;
    s32 ret = 1;
    if (src == 0) return 1;
    h = fn_80225B74(0xFFFF, src->x04);
    o->x1b4 = h;
    o->x1ed = o->x1ec = 0;
    if (h != 0) {
        h->p1c = &o->pos;
        h->p24 = o->ang;
        p = PickMotion(src->items, 2);
        if (p != 0) {
            h->p28 = &o->pivotPos;
            h->p2c = o->pivotAng;
            o->pivot = 1;
            o->x1ee = 0;
            {
                s32 r = fn_800D6E1C(o);
                s8 st = r;
                if (st < 0) {
                    if (lbl_8030A5D4[0] == 0) {
                        o->x24c.y = 1.0f;
                        o->x1ed = 0;
                        o->x1ec = 1;
                        o->x1ef = 1;
                        ret = 5;
                    } else {
                        ret = 2;
                    }
                } else {
                    ret = r;
                }
            }
        }
        fn_802233EC(h);
    }
    inf = src->info;
    if (inf->count > 0) {
        s32 id = inf->w4;
        if (id >= 0) {
            o->x25c = fn_80225B74(0xFFFF, id);
        } else {
            o->x25c = 0;
        }
    }
    return ret;
}

#ifdef NONMATCHING
typedef struct Menu_800D8014 {
    s16 s0;
    s16 s2;
    s32 p4;
    f32 alpha;
    s16 on[3];
    u8 pad12[2];
    f32 pos[3][2];
    f32 d[3][2];
} Menu_800D8014;
extern char lbl_802B15BC[];
extern char lbl_802B15CC[];
extern s32 fn_800CE4B4(void);
#endif

#ifdef NONMATCHING
void fn_800D8014(Menu_800D8014* o) {
    s32 d = lbl_80310A1C[0x11];
    s32 i;
    s32 found;
    switch (d) {
    case 0:
        if (fn_800CE4B4() == 0) {
            fn_801DBE1C(lbl_802B15BC, lbl_80310A1C[6], d);
        }
        o->on[2] = 1;
        o->on[1] = 1;
        o->on[0] = 1;
        o->s2 = 3;
        break;
    case 1:
        o->on[0] = 1;
        o->on[1] = 0;
        o->on[2] = 1;
        o->s2 = 2;
        break;
    case 2:
        if (fn_800CE4B4() == 0) {
            fn_801DBE1C(lbl_802B15BC, lbl_80310A1C[6], d);
        }
        o->on[0] = 0;
        o->on[1] = 1;
        o->on[2] = 0;
        o->s2 = 1;
        break;
    default:
        fn_801DBE1C(lbl_802B15CC, d);
        break;
    }
    found = 0;
    o->s0 = 0;
    o->p4 = 0;
    i = 0;
    do {
        if (found == 0 && o->on[i] != 0) {
            o->pos[i][0] = -3.0f;
            found++;
            o->pos[i][1] = -6.0f;
            o->d[i][0] = 1.0f;
            o->d[i][1] = 2.0f;
        } else {
            o->d[i][1] = 0.0f;
            o->d[i][0] = 0.0f;
            o->pos[i][1] = 0.0f;
            o->pos[i][0] = 0.0f;
        }
        i++;
    } while (i < 3);
    lbl_80311A14[lbl_8034757C].b3 = 0;
    lbl_80311A14[lbl_8034757C].b2 = 0;
    o->alpha = 0.0f;
}
#endif
