#include "types.h"
#include "game/work_8030CEA0.h"
#include "game/gamedata.h"
#include "game/save_8030B7F4.h"
#include "game/stat_8030B4D4.h"
#include <dolphin/types.h>
extern void fn_80136A28(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
extern s32 fn_8013DA50(s32 a, s32 b);
/* A battle menu window's state. */
typedef struct MenuObj {
    u8 pad0;
    s8 state;   /* 0x01 */
    s8 b2;
    s8 b3;
    s8 b4;
    u8 pad5[3];
    s8 b8;
    s8 b9;
    u8 ba;
    u8 bb;
    u8 padc[0x16 - 0xc];
    s16 x16;
} MenuObj;
/* A menu cell (fn_80131658). */
typedef struct Cell {
    s8 x;
    s8 y;
    s8 a;
    s8 b;
    s8 c;
} Cell;
extern s32 lbl_80346F70;
extern s32 lbl_80346F6C;
extern s32 lbl_80346F68;
extern s32 lbl_80346F64;
extern s32 fn_801E4BBC(s32 n);
extern s32 rand(void);
typedef struct {
    u8 pad0;
    s8 idx; /* 0x01 */
} IdxArg;
extern void fn_80100270();
extern void fn_801F7B04(s32 n);
extern char lbl_802E5E68[];
extern f32 lbl_803472E0;
/* lbl_803472CC: 0xf00 (hi, lo) pairs (fn_80148E08 allocates them). */
typedef struct Pair_80148464 {
    s16 a;
    s16 b;
} Pair_80148464;
extern Pair_80148464* lbl_803472CC;
extern void fn_801E17E0(void* p);
typedef struct {
    u8 pad0[0x7C];
    s32 f7c;
} Sub_UNIT0000;
typedef struct {
    u8 pad0[0x23C];
    Sub_UNIT0000* sub; /* 0x23C */
} Obj_UNIT0000;
extern void fn_8014FA10(void* p);
typedef struct {
    u8 pad0[0x18];
    s32 f18;
    s32 f1c;
    s16 f20;
    u8 pad22[2];
    s16 f24;
    u8 pad26[6];
    s16 f2c;
    s16 f2e;
} Timer;
typedef struct {
    u8 pad0[0x28];
    s8 f28;
    u8 f29;
} Flags;
extern s32 fn_8013E42C(s32 a);
extern void fn_8013F6E0(void);
extern void SePlay(s32 id, s32 a, s32 b);
extern void fn_80097294(s32 a);
extern s32 lbl_80346F80;
extern s32 lbl_80347290;
extern void* memset(void* dst, s32 c, u32 n);
typedef struct Slot {
    u32 flags;
    u32 x4;
    u32 x8;
    u32 xc;
    u8 pad[0x24 - 0x10];
} Slot;
extern Slot lbl_8030A6D4[];
extern s32 lbl_8034757C;
extern s32 fn_8013E730(s32 i);
extern u8 lbl_80346F61;
extern u8 lbl_80346F60;
typedef struct {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    u8 b4;
    u8 b5;
    u8 b6;
    u8 b7;
    s16 s8;
    s16 sa;
    u32 wc;
} Rec;
typedef struct {
    s16 s0;
    s16 s2;
    u8 pad4[4];
    u32 w8;
    u32 wc;
    Rec e[8];
} Blk;
/* A ship's crew member in battle (0x22). */
typedef struct Member {
    u8 pad0[0x12];
    s16 id;         /* 0x12 */
    s8 state;       /* 0x14: < 0 empty */
    u8 pad15;
    s16 x16;
    s16 x18;        /* x16's boost */
    s16 x1a;        /* -1: none */
    s16 x1c;        /* x1a's boost */
    s8 b1e;
    s8 b1f;
    s8 b20;
    u8 pad21;
} Member;
/* A ship in battle (0x10C): the player's at 0x238 of the battle menu record, the enemies' from
   fn_8013558C. Stats come in pairs (value, boost). */
typedef struct Party {
    s32 x0;
    u8 pad4[0x11 - 0x4];
    s8 b11;
    u8 pad12[2];
    s32 hp_max;     /* 0x14 */
    s32 hp;         /* 0x18 */
    s16 x1c;
    s16 x1e;
    s16 x20;
    s16 x22;
    s16 x24;
    s16 x26;
    s16 x28[6];     /* 0x28 */
    u8 pad34[0x40 - 0x34];
    s16 x40;
    s16 x42;
    u8 pad44[0x50 - 0x44];
    s16 x50;        /* status turns */
    s16 x52;
    s16 x54;
    s16 x56;
    u32 flags;      /* 0x58 */
    u32 x5c;        /* 0x5C */
    Member mem[5];  /* 0x60 */
    u8 pad10a[2];
} Party;
typedef struct MenuItem {
    u8 pad0[0xd];
    s8 b0d;         /* max */
    s8 b0e;
    u8 pad0f[0x1c - 0x0f];
} MenuItem;
/* lbl_803063F0: the battle menu's system record (fn_80135598). */
typedef struct Big {
    s8 order[4];
    u8 pad4[2];
    s16 x6;
    s16 x8;
    u8 padA[2];
    s16 xc;
    InvEnt xe[0x50];    /* 0x00E: usable items (fn_8013D718 kind 1) */
    InvEnt x14e[0x1e];  /* 0x14E: ship items (kind 0) */
    MenuItem items[4];  /* 0x1C6 */
    u8 pad236[2];
    Party party;        /* 0x238 */
} Big;
/* A ship battle command (0x18): what a slot does this turn. */
typedef struct BtlCmd {
    char x0;            /* 0x00: kind */
    s8 x1;              /* 0x01 */
    s8 x2;              /* 0x02 */
    s8 x3;              /* 0x03 */
    u8 pad4;
    s8 x5;              /* 0x05: scope */
    s16 x6;             /* 0x06 */
    s8 x8;              /* 0x08 */
    u8 x9;              /* 0x09 */
    u8 padA[2];
    s16 xc;             /* 0x0C: skill id */
    s16 xe;             /* 0x0E */
    s16 x10;            /* 0x10 */
    s16 x12;            /* 0x12 */
    s16 x14;            /* 0x14 */
    u8 pad16[2];
} BtlCmd;
typedef struct BtlSlot {
    s16 mode;
    u8 pad2[4];
    s16 x6;
    s16 x8;
    s16 xa;             /* 0x0A */
    s16 xc;             /* 0x0C */
    BtlCmd head;        /* 0x0E */
    BtlCmd body;        /* 0x26 */
} BtlSlot;
/* *lbl_8034727C: the ship battle state (0xAB4). */
typedef struct BtlWork {
    s16 flag[2];        /* 0x000: player, enemy */
    s16 x4;
    s16 x6;
    s16 x8;
    s16 xa;
    s16 xc;
    s16 xe;
    s16 x10;
    s16 x12;
    s16 x14;
    u8 pad16[2];
    s32 x18;
    s32 x1c;
    Party *x20;         /* 0x020: the player's ship */
    Party *x24;         /* 0x024: the enemy's */
    s8 count;           /* 0x028 */
    u8 b29;
    u8 b2a;
    u8 pad2b;
    BtlSlot slot[4];    /* 0x02C */
    Blk a[8];           /* 0x124 */
    Blk b[8];           /* 0x5A4 */
    Blk out;            /* 0xA24 */
} BtlWork;
extern void fn_8014549C(s32 a, s32 b);
typedef struct Obj24 { u8 pad[0x24]; s16 x24; } Obj24;
typedef struct Obj7 { u8 pad[7]; u8 x7; } Obj7;
typedef struct Sub_80146FD4 { u8 pad[0x14]; s32 x14; s32 x18; } Sub_80146FD4;
typedef struct Req_UNIT0000 { s8 x0; s8 x1; } Req_UNIT0000;
typedef struct MapInfo { s32 map; s32 unk4; char room; } MapInfo;
extern void fn_800FF908(void);
extern void fn_801002D0(s32 a);
extern int sprintf(char* buf, const char* fmt, ...);
extern MapInfo lbl_80311AC0;
extern s32 lbl_80311AD4[11];
extern s32 lbl_803472E4;
/* The unit's message pool in .rodata (the unit does not own its .rodata): one string literal per
   field, each 4-aligned as the compiler laid the pool out. */
typedef struct StrPool_8013D400 {
    char sct[0x10];           /* "me%03d%c.sct" */
    char shipInfo[0x24];      /* "ShipIs Not Found BtlCmd sbGetInfo %d" */
    char camPath[0x1C];       /* "Camera Path Is Not Found %d" */
    char croot[0xC];          /* "sb_croot" */
    char notCamPath[0x18];    /* "Not Camera Path %d - %s" */
    char camMotion[0x24];     /* "Camera Path Motion Is Nothing %d" */
    char path[0x18];          /* "Path Is Not Found %d" */
    char ship[0x18];          /* "Ship Is Not Found %d" */
    char btArea[0x24];        /* "sbBT Error : Set Area is Over !!" */
    char curScene[0x38];      /* "sbSetCurrentScene Error : Scene Table Is Nothing !! %d" */
    char enemyStart[0x44];    /* "SbCommandEnemy Error : sbSceneTableStart function does not exist !!" */
    char enemyPhase[0x28];    /* "SbCommandEnemy Error : phase over !!" */
    char enemyDup[0x34];      /* "Duplicate Scene !! in SbCommandEnemy  %d area %d" */
    char gunKind[0x30];       /* "Gun Kind Error in SbCommandEnemy  %d area %d" */
    char sceneStart[0x40];    /* "SbScene Error : sbSceneTableStart function does not exist !!" */
    char scenePhase[0x20];    /* "SbScene Error : phase over !!" */
    char sceneDup[0x2C];      /* "Duplicate Scene !! in SbScene  %d area %d" */
    char endStart[0x40];      /* "sbSceneTableEnd  Error : sbSceneTableStart is Not alival !! %d" */
    char endIncomplete[0x34]; /* "sbSceneTableEnd  Error : Table Set incomplete !! %d" */
    char startEnd[0x40];      /* "sbSceneTableStart Error : sbSceneTableEnd is Not alival !! %d" */
    char startOver[0x34];     /* "sbSceneTableStart Error : Scene Number Over !! %d" */
    char startDup[0x34];      /* "sbSceneTableStart Error : Scene Duplicate Set !! %d" */
} StrPool_8013D400;
extern const StrPool_8013D400 lbl_802B3578;
extern s32* lbl_80346F74;
extern s32 lbl_8034728C;
extern s32 lbl_80347294;
extern void fn_80143060(s32* p);
extern u8 lbl_80310A1C[];
typedef struct Node {
    s32 x0;
    struct Node* x4;
    struct Node* x8;
    struct Node* xc;
    struct Node* x10;
    struct Node* x14;
} Node;
/* lbl_80346F88: 500 node slots (fn_801490F4 allocates them). */
extern Node** lbl_80346F88;
void fn_80148E4C(Node *p);
extern void fn_801E17E0(void*);
void fn_80148EDC(Node* n);
extern void fn_80131500(s8 a);
extern void fn_80131658(Cell *c);
extern void fn_80140264(void);
extern void fn_8013FB48(s32 a, s32 b);
extern s32 fn_80140D04(s32 a);
extern Big *fn_80135598(void);
extern BtlWork *lbl_8034727C;
extern s32 lbl_80347278;
extern void *fn_801E1A74(s32 a, s32 b);
extern Party *fn_8013558C(void);
/* lbl_80308F98: 32 lists of 0x58 records. */
typedef struct BtlItem {
    s32 f0;
    s32 w4;
    s32 w8;
    s32 wc;
    s32 w10;
    s32 w14;
    s32 w18;
    s32 w1c;
    s32 w20;
    s32 w24;
    s32 w28;
    s32 w2c;
    s32 w30;
    f32 f34;
    f32 f38;
    f32 f3c;
    f32 f40;
    u16 s44;
    u16 s46;
    s32 f48;
    s32 f4c;
    s32 f50;
    s32 f54;
} BtlItem;
typedef struct Entry {
    s32 n;
    s32 count;
    BtlItem *items;
} Entry;
extern Entry lbl_80308F98[32];
extern s32 lbl_803472BC;
extern Entry *lbl_803472A8;
extern s32 lbl_803472C0;
extern s32 lbl_803472D4;
extern s32 fn_801298E8(void);
extern void fn_801299A0(void);
extern void fn_80129BD4(void);
extern void fn_8015635C(void);
/* lbl_80308E90: 8 records, indexed by i + 4 for i in [-4, 4). */
typedef struct {
    s8 kind;
    s8 key;
    s8 member;
    s8 x3;
    s8 level;
} Rec5;
extern Rec5 lbl_80308E90[8];
extern u32 fn_8013FCF0(s32 a, s32 key, s32 n);
typedef struct {
    s8 kind;
    u8 pad1;
    s8 slot;
    u8 pad3[5];
    s16 id;
} Req_801462D0;
typedef struct Cnt { s32 x0; s32 x4; } Cnt;
typedef struct Body {
    u8 pad0[0xe8];
    Cnt *xe8;
    u8 pad1[0x18c - 0xec];
    f32 x18c;
    f32 x190;
    u8 pad2[4];
    s32 x198;
} Body;
typedef struct Owner {
    Body *p;
    s32 x4;
    s32 x8;
    s32 xc;
    s32 x10;
    f32 x14;
    s32 x18;
} Owner;
extern void fn_8014EE4C(void *,  s32 a,  s32 b,  s32 c,  s32 d);
typedef struct {
    s8 x0;
    s8 x1;
    u8 x2;
    s8 x3;
    s8 x4;
    s8 x5;
    u8 x6, x7;
    s16 x8;
    s16 xa;
    u8 pad_c[4];
} Slot_8014359C;
typedef struct {
    u8 pad[0x2C];
    s16 mode;
    u8 pad2E[0x3E - 0x2E];
} Ent_8014359C;
typedef struct {
    u8 pad[0x134];
    Slot_8014359C slots[1];
} Sys_8014359C;
typedef struct {
    u8 pad[0x20];
    s32 id;
    u8 pad24[0x34 - 0x24];
    f32 f34;
    f32 f38;
    f32 f3c;
    f32 f40;
} Cfg;
extern Cfg* lbl_803472A4;
extern s32 fn_80145E0C(Slot_8014359C* s, s32 a);
extern s32 fn_80145F50(Slot_8014359C* s, s32 a);
typedef struct {
    u8 pad[0x24];
    struct { u8 pad[0x23C]; void* x23c; } * x24;
} Obj1E8;
typedef struct {
    s32 kind;
    u8 pad4[0x38];
    void* x3c;
} Cfg_8014D1F4;
typedef struct {
    u8 pad[0x10];
    Cfg_8014D1F4* x10;
} Link_8014D1F4;
typedef struct {
    u8 pad00[0x100];
    void* x100;
    u8 pad104[0x17A - 0x104];
    u16 id;
    u8 pad17c[0x1C8 - 0x17C];
    Link_8014D1F4* x1c8;
    u8 pad1cc[0x1E8 - 0x1CC];
    Obj1E8* x1e8;
    u8 pad1ec[0x23C - 0x1EC];
    struct {
        s32 x0;
        struct { u8 pad[0x1D4]; } * x4;
        s32 x8;
    } * x23c;
} Work_8014D1F4;
typedef struct {
    u8 pad00[0x19];
    u8 state;
    u8 pad1a[0x24 - 0x1A];
    Work_8014D1F4* work;
} Task_8014D1F4;
typedef struct {
    s32 a, b, c, d;
} Blk_80143734;
typedef struct {
    s16 f0;
    s16 f2;
    s16 f4;
    s16 f6;
} Src_80143734;
typedef struct {
    s8 f0;
    s8 f1;
    u8 pad2;
    u8 f3;
    u8 f4;
    u8 f5;
    s16 f6;
    s8 f8;
    u8 f9;
    u8 padA[2];
    s16 fc;
    u8 padE[6];
    s16 f14;
} Out_80143734;
typedef struct {
    u8 pad0[0x90];
} Row_80143734;
typedef struct {
    u8 pad0[0x20];
    u8* x20;
    u8* x24;
    s8 f28;
    u8 pad29[0x124 - 0x29];
    Row_80143734 rows[1];
} Game_80143734;
extern Src_80143734* fn_80145844(s32 a);
extern void fn_801E0FD4(void* p, s32 n);
extern s32 lbl_803472C4;
extern s32 lbl_803472D0;
extern u32 lbl_80347298;
extern void fn_801DBE1C(const char* fmt, ...);
typedef struct {
    f32 x, y, z, u, v;
    u32 col;
} Vtx_8014B510;
typedef struct {
    u8 pad0[4];
    u32 f4;
} Tex_8014B510;
typedef struct {
    f32 f0;
    f32 f4;
    s16 f8;
    u8 pad_a[2];
    s32 fc;
    s32 f10;
    u8 f14;
    u8 f15;
    u8 f16;
    u8 f17;
    u8 pad18[4];
    Tex_8014B510* f1c;
} Obj_8014B510;
extern void fn_80298FE4(s16 idx);
extern void fn_8028A8C0(void* v, s32 n, s32 m);
typedef struct {
    s8 e0;
    u8 pad1;
    s8 e2;
    u8 pad3;
    s8 e4;
    u8 pad5;
    s8 e6;
    u8 pad7;
    s8 e8;
    u8 pad9;
    s8 ea;
    u8 padb;
    s8 ec;
    u8 padd[3];
    s16 f10;
    u8 pad12[2];
    s32 f14;
    s32 f18;
    f32 f1c;
    f32 f20;
    s16 f24;
    s16 f26;
    s8 f28;
    s8 f29;
    u8 pad2a[2];
    s32 f2c;
} Obj_8014F518;
extern void fn_80156768(s32 a, s32 b, f32* c, f32* d, f32 e);
extern void fn_80154404(void);
extern s16 fn_8015432C(s32 a, s32 b);
extern void fn_801545AC(s32 a, s32 b);
extern void fn_80153DB8(s32 a, s32 b);
typedef struct {
    u8 pad00[0x24];
    struct { u8 pad[0x17A]; u16 id; } * obj;
} Item;
typedef struct {
    Item* it;
    u8 pad4[0xC];
    s32 idx;
} Slot_80147EAC;
extern Slot_80147EAC lbl_80308EF8[];
extern s32 lbl_8034729C;
extern char lbl_802B3588[];
extern s32 fn_80148024(s32, s32);
extern s32* fn_80129D40(s32);
typedef struct {
    u8 pad[0x10];
} Slot_80143FA4;
typedef struct {
    Slot_80143FA4 slots[9];
} Row_80143FA4;
typedef struct {
    u8 pad0[0x5b4];
    Row_80143FA4 rows[1];
} Rows_80143FA4;
typedef struct {
    u8 pad[0x90];
} R90_80143FA4;
typedef struct {
    u8 pad0[0x2c];
    s16 f2c;
    u8 pad2e[0x3e - 0x2e];
} Ent_80143FA4;
typedef struct {
    u8 pad[0x22];
} R22_80143FA4;
typedef struct {
    u8 pad0[0x20];
    R22_80143FA4* x20;
} H_80143FA4;
typedef struct {
    u8 pad0[2];
    s16 f2;
    u8 pad4[0x90 - 4];
} Big_80143FA4;
typedef struct {
    u8 pad0[0x124];
    Big_80143FA4 rows[1];
} Bigs_80143FA4;
typedef union {
    Bigs_80143FA4 b;
    Ent_80143FA4 ents[1];
    R90_80143FA4 rows[1];
    H_80143FA4 h;
    Rows_80143FA4 r5;
} G_80143FA4;
typedef struct {
    u8 pad0[0x18];
    u8 flags;
    u8 pad19[0x24 - 0x19];
    s32 x24;
    s32 x28;
} Task;
/* lbl_80306738: cleared by fn_80142F18; the task at 0xc is stopped when a menu closes. */
typedef struct {
    u8 b[0xc];
    Task* task;
    u8 b2[6];
    u16 h[5];
} Struct80306738;
extern Struct80306738 lbl_80306738;
extern void fn_80142F18(void);
typedef struct {
    u8 pad0;
    s8 idx; /* 0x01 */
    u8 pad2[5];
    s8 x7;  /* 0x07 */
} IdxArg_801464B4;
typedef struct {
    s16 x0;
    s16 x2;
    u8 pad[0x90 - 4];
} Rec_80146DE4;
typedef struct {
    u8 pad[0x124];
    Rec_80146DE4 rec[1];
} Mgr_80146DE4;
typedef struct Stat {
    u8 pad0[0x14];
    s32 max;
    s32 cur;
} Stat;
typedef struct Ent_80143200 {
    u8 pad0[0x20];
    Stat *stat;
} Ent_80143200;
typedef struct {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    u8 pad4;
    u8 b5;
    s16 s6;
    u8 pad8;
    u8 b9;
    u8 padA[2];
    s16 sc;
    u8 padE[6];
    s16 s14;
} Src;
typedef struct {
    u8 pad0[0x124];
    Blk a;
} SysA;
typedef struct {
    u8 pad0[7];
    u8 b7;
} Obj;
typedef struct {
    u8 pad0[0x1c];
    s16 s1c;
    u8 pad1e[2];
    s16 s20;
    u8 pad22[0x40 - 0x22];
    s16 s40;
    u8 pad42[0x76 - 0x42];
    s16 s76;
    u8 pad78[2];
    s16 s7a;
    u8 pad7c[0x98 - 0x7c];
    s16 s98;
    u8 pad9a[2];
    s16 s9c;
    u8 pad9e[0xba - 0x9e];
    s16 sba;
    u8 padbc[2];
    s16 sbe;
    u8 padc0[0xdc - 0xc0];
    s16 sdc;
    u8 paddE[2];
    s16 se0;
    u8 pade2[0xfe - 0xe2];
    s16 sfe;
    u8 pad100[2];
    s16 s102;
} Ent_8014654C;
typedef struct {
    u8 pad0[0x20];
    Ent_8014654C *x20;
    Ent_8014654C *x24;
    u8 pad28;
    u8 b29;
    u8 b2a;
} Sys_8014654C;
s32 fn_8013D718(s32 kind, InvEnt *tbl, s32 idx);
extern void fn_8012AEB8(s32 a);
extern void fn_8012AED0(s32 a);
extern void fn_8012C648(s32 a);
extern void fn_8012E5C0(s8 a);
extern void fn_80130350(s32 a);
extern void fn_801316B4(s32 a);
extern void fn_8013312C(s32 a);
extern void fn_8015A844(void);
extern void fn_8012C048(s32 a);
typedef struct {
    u32 w[0x24];
} Rec90;
typedef struct {
    u8 pad0[0xe];
    u8 head[0x18];
    u8 body[0x18];
} Slot3E;
typedef struct {
    u8 pad0[0x28];
    s8 count;
    u8 pad29[3];
    Slot3E slot[4];
    Rec90 a[8];
    Rec90 b[8];
} Work_80144680;
extern s32 lbl_80346F78;
extern void fn_80144400(void *p, s32 idx);
extern s32 lbl_803472B4;
extern s32 lbl_802E5EA8[4];
extern s32 fn_8015C4A0(s32 a, s32 b);
extern s32 fn_8015C468(s32 a, s32 b);
typedef struct TblEnt {
    u32 off;
    u32 x4;
} TblEnt;
typedef struct Tbl {
    s32 n;
    u32 pad4;
    TblEnt e[1];
} Tbl;
typedef struct {
    u8 pad0[0x10];
    Tbl *tbl;
    u8 pad14[0x24 - 0x14];
    char name[1];
} Node_80148228;
typedef struct {
    u8 pad0[0x84];
    struct Path_80148228 *path;
} Ctl_80148228;
typedef struct {
    u8 pad0[0xe8];
    void* motion;
    u8 padec[0x1c8 - 0xec];
    Node_80148228* node;
    u8 pad1cc[0x1dc - 0x1cc];
    u32 b1dc;           /* id base */
    u8 pad1e0[0x1e4 - 0x1e0];
    Ctl_80148228 *ctl;
    u8 pad1e8[0x1fb - 0x1e8];
    u8 f1fb;
    s16 f1fc;
    u8 pad1fe[0x26c - 0x1fe];
    u8 f26c;
} Model_80148228;
typedef struct Path_80148228 {
    u8 pad0[0x19];
    u8 f19;
    u8 pad1a[0x24 - 0x1a];
    Model_80148228* model;
} Path_80148228;
typedef struct {
    Path_80148228* ship;
    Path_80148228* path;
    s32 f8;
} Cam_80148228;
typedef struct {
    u8 pad0[0x24];
    Cam_80148228* cam;
} Outer_80148228;
extern Outer_80148228 *lbl_803472A0;
extern Path_80148228* fn_801094C8(u32 id);
extern s32 fn_8025EF88(const char* a, const char* b);
typedef struct {
    u8 pad0[0x14];
    u8 mask[0x80];
    u8 pad94[0xa0 - 0x94];
    s32 lo;
    s32 hi;
} Range_8014F834;
struct Ctx_8014D398;
typedef struct Node_8014D398 {
    s32 w0;
    void *x4;
    struct Ctx_8014D398 *x8;
    s32 xc;
    s32 x10;
    s32 x14;
    s32 x18;
    f32 f1c;
    s32 x20;
} Node_8014D398;
typedef struct {
    s32 w0;
    u8 pad4[0x3c - 4];
    void *x3c;
    s32 x40;
    s32 x44;
    s32 x48;
    s32 x4c;
    s32 x50;
    s32 x54;
} Info;
typedef struct {
    u8 pad0[0x10];
    Info *x10;
} Sub;
/* The leader ship's task and its work (the task's 0x23c) */
typedef struct {
    u8 pad0[0x10];
    void *x10;
    u8 pad14[0x68 - 0x14];
    u8 x68[1];
} LeaderSub;
typedef struct {
    u8 pad0[0x70];
    s32 x70;
    u8 pad74[0x7c - 0x74];
    s32 x7c;
    u8 pad80[4];
    s32 x84;
    u8 pad88[0xa4 - 0x88];
    s32 xa4;
    u8 pada8[0xc0 - 0xa8];
    s32 xc0;
    u8 padc4[0xd0 - 0xc4];
} LeaderRec;
typedef struct {
    char name[8];       /* 0x000 */
    s32 x8;             /* 0x008 */
    u8 padc[0x1d4 - 0xc];
    u8 x1d4[0x214 - 0x1d4];
    u8 x214[8];         /* 0x214 */
    LeaderSub *x21c;    /* 0x21c */
    u8 pad220[0x3a0 - 0x220];
    s16 x3a0;
    s16 x3a2;
    s16 x3a4;
    u8 pad3a6[0x448 - 0x3a6];
    s16 x448;
    s16 x44a;
    u8 pad44c[0x4f0 - 0x44c];
    LeaderRec rec[1];   /* 0x4f0 */
    u8 pad5c0[0xc04 - 0x5c0];
    s32 xc04;
    u8 xc08[1];
} Leader;
typedef struct Ctx_8014D398 {
    u8 pad0[0xe8];
    void *xe8;
    u8 pade8[0x100 - 0xec];
    void *x100;
    u8 pad104[0x17a - 0x104];
    u16 h17a;
    u8 pad17c[0x18c - 0x17c];
    f32 f18c;
    f32 f190;
    u8 pad194[0x1c8 - 0x194];
    Sub *x1c8;
    u8 pad1cc[0x1e4 - 0x1cc];
    s32 x1e4;
    struct Task_8014D398 *x1e8;
    u8 pad1ec[0x23c - 0x1ec];
    void *x23c;     /* the per-type record: Node_8014D398, CamNode, Leader */
} Ctx_8014D398;
typedef struct Task_8014D398 {
    u8 pad0[0x19];
    u8 b19;
    u8 pad1a[0x24 - 0x1a];
    Ctx_8014D398 *x24;
} Task_8014D398;
typedef struct {
    u8 pad0[4];
    u32 w4;
} W4;
extern void fn_80227810(void *p);
extern void fn_8015ED90(Task_8014D398 *t);
extern void *fn_8010A164(void *p);
extern void fn_80156B04(void *a, Ctx_8014D398 *c, s32 d, s32 e, void *f);
extern s32 fn_8015E600(Ctx_8014D398 *c);
extern void fn_80156E54(Ctx_8014D398 *c, void *a);
extern void fn_80156DA0(Ctx_8014D398 *c, void *a);
extern void fn_8015EBF4(Ctx_8014D398 *c);
extern void fn_802275A4(void *p, s32 a);
extern void fn_80100B74(Task_8014D398 *t);
extern void fn_8012E5B0(s8 v);
extern void fn_8012E560(s8 v);
extern s32 fn_8013EA10(void);
extern void fn_8012E5A0(s16 v);
extern void fn_8012E590(s8 v);
extern void fn_8012E414(s8 v);
extern void fn_8012E404(s8 v);
extern void fn_8013E0BC(s8 a, s8 b, void *p);
typedef struct {
    u32 x0;
    u8 pad4[4];
    u32 x8;
} Pad_80141390;
extern Pad_80141390 *lbl_80311A60[6];
extern s32 fn_8012C5DC(void);
extern s32 fn_801410D4(s32 a, s32 d);
s32 fn_80141314(s32 a);
extern void fn_8012C5FC(s8 v);
extern void fn_8012C614(s32 v);
extern void fn_8012C390(s32 v);
extern void fn_80140750(s32 cols, s32 rows);
extern int fn_80136B10(s8 *dst, Big *src);
extern void fn_801315A8(s8 *src);
extern void fn_80131598(s8 v);
extern void fn_801315EC(s8 v);
extern void fn_801315FC(s8 v);
typedef struct Obj_8014F770 {
    u8 pad0[0x14];
    s8 seq[0x81];
    u8 pad95;
    s16 x96;
    s16 x98;
    s16 x9a;
    s16 x9c;
    s16 x9e;
} Obj_8014F770;
typedef struct Model2C {
    u8 pad0[0x14];
    u32 x14;
    u32 x18;
    u32 x1c;
} Model2C;
typedef struct ResHdr {
    u8 pad0[0x2c];
    Model2C *x2c;
} ResHdr;
typedef struct GeffEntry {
    void *fn;
    u32 pad;
} GeffEntry;
typedef struct Geff {
    u32 flags;
    void *x4;
    s32 x8;
    s16 xc;
    s16 xe;
    s32 x10;
    s16 x14;
    s16 x16;
    s16 x18;
    u8 pad1a[4];
    s16 x1e;
    u8 pad20[0x48 - 0x20];
    u32 x48;
    u32 x4c;
    u32 x50;
    u8 pad54[0x6c - 0x54];
    s32 x6c;
    s32 x70;
    s32 x74;
    u8 pad78[0x84 - 0x78];
    ResHdr *x84;
    ResHdr *x88;
    ResHdr *x8c;
    s32 x90;
    s32 x94;
    u8 pad98[0xd8 - 0x98];
    s32 xd8;
    u8 padDC[4];
    s32 xe0;
    u8 padE4[0x124 - 0xe4];
    s32 x124;
    u8 pad128[4];
    s32 x12c;
    u8 pad130[0x170 - 0x130];
    s32 x170;
    u8 pad174[4];
    s32 x178;
    s32 x17c;
    s32 x180;
    u8 pad184[0x19c - 0x184];
    f32 x19c;
    u8 pad1a0[0x1a4 - 0x1a0];
    u8 x1a4[0xbc];
    void *handlers[47];
    s32 x31c;
} Geff;
typedef struct Sub1b8 {
    u8 pad0[0x2a];
    u16 x2a;
} Sub1b8;
typedef struct Sub1c8 {
    u8 pad0[0x20];
    void *x20;
    char name[1];
} Sub1c8;
typedef struct Owner_801493EC {
    u8 pad0[0xe4];
    void *xe4;
    u8 padE8[0x17a - 0xe8];
    u16 x17a;
    u8 pad17c[0x1b8 - 0x17c];
    Sub1b8 *x1b8;
    u8 pad1bc[0x1c8 - 0x1bc];
    Sub1c8 *x1c8;
    u8 pad1cc[0x1d8 - 0x1cc];
    Geff *x1d8;
} Owner_801493EC;
typedef struct Parent_801493EC {
    u8 pad0[0x24];
    Owner_801493EC *x24;
} Parent_801493EC;
extern const GeffEntry lbl_802B4118[47];
extern void *fn_801E1A2C(s32 a, u32 size);
extern s32 fn_800DE554(s32 id);
extern s16 fn_800DE5EC(s32 id);
extern s16 fn_800DE598(s32 id);
extern s32 fn_800E0C38(s32 id);
extern void *fn_801C8930(void *h);
extern void *fn_80167244(void *a, u32 mask);
extern s32 fn_8025ECC4(void);
typedef struct Arg { u8 pad[4]; s16 mode; } Arg;
#define DECAY(v, d) { d = -v / 4; v += d; }

void fn_8013D400(s32 a, s32 b) {
    fn_80136A28(a, b, 3, -1, -1, -1);
}

s32 fn_8013D708(u8* p) {
    p[0x1] = 0;
    return 2;
}

static inline s32 party_count(void) {
    s32 n = 0;
    Big *p = fn_80135598();
    if (p != 0) {
        for (n = 0; n < 4; n++) {
            if (p->order[n] < 0) {
                break;
            }
        }
    }
    return n;
}

static inline s32 fn_used(s32 kind, InvEnt *tbl, s32 idx) {
    s32 used = 0;
    s32 n;
    s32 want;
    s32 i;
    if (tbl != 0) {
        n = party_count();
        want = -1;
        switch (kind) {
        case 0:
            want = 1;
            break;
        case 1:
            want = 2;
            break;
        }
        if (n > 0 && n <= 4 && want != -1) {
            for (i = 0; i < n; i++) {
                if (want == lbl_80308E90[i + 4].kind && idx == lbl_80308E90[i + 4].member) {
                    used++;
                }
            }
        }
        used = tbl[idx].cnt - used;
    }
    return used;
}

s32 fn_8013D718(s32 kind, InvEnt *tbl, s32 idx) {
    s32 limit = 0;
    s32 res = -1;
    s32 used;
    s32 j;
    s32 ok;
    s32 id;

    switch (kind) {
    case 0:
        limit = 0x1e;
        break;
    case 1:
        limit = 0x50;
        break;
    }
    if (tbl != 0 && idx >= 0 && idx < limit) {
        used = fn_used(kind, tbl, idx);
        if (used > 0) {
            id = tbl[idx].id;
            switch (kind) {
            case 0:
                ok = 0;
                if (id >= 0x1e0 && id <= 0x1fd) {
                    j = id - 0x1e0;
                    if (lbl_802D8A2C[j].use_mask & 1) {
                        ok = 1;
                    }
                }
                if (ok != 0) {
                    res = id;
                }
                break;
            case 1:
                ok = 0;
                if (id >= 0xf0 && id <= 0x13f) {
                    j = id - 0xf0;
                    if (lbl_802C7C34[j].use_mask & 1) {
                        ok = 1;
                    }
                }
                if (ok != 0) {
                    res = id;
                }
                break;
            }
        }
    }
    return res;
}

void fn_8013DB64(void) {
    fn_8013DA50(0, 1);
}

s32 fn_8013DB8C(s32 a, s32 b, s32 d) {
    s32 n = fn_8013E42C(a);
    s32 idx = b;
    if (b < 0) idx = n - 1;
    if (idx > n - 1) idx = 0;
    return idx;
}

s32 fn_8013F624(u8* p) {
    p[0x1] = 0;
    return 2;
}

void fn_8013F634(s32 a, s32 b) {
    fn_80136A28(a, b, 0, -1, -1, -1);
}

s32 fn_8013F664(MenuObj* o) {
    s32 r = 0;
    s32 k = o->state;
    if (k == 1) { goto end; }
    if (k >= 1) { goto out; }
    if (k < 0) { goto out; }
    r = 1;
    goto out;
end:
    r = 2;
out:
    return r;
}

s32 fn_8013F694(u8* p) {
    p[0x1] = 0;
    return 2;
}

void fn_8013F6A4(s32 i) {
    if (i >= -4 && i < 4) {
        lbl_80308E90[i + 4].kind = -1;
        lbl_80308E90[i + 4].key = -1;
        lbl_80308E90[i + 4].member = -1;
        lbl_80308E90[i + 4].x3 = -1;
        lbl_80308E90[i + 4].level = -1;
    }
}

void fn_801415C4(MenuObj* o) {
    if (o != 0) {
        if (o->b2 > 0) {
            o->b2--;
            fn_8013F6E0();
            SePlay(0xf, 1, 7);
        }
    }
}

void fn_80142F04(s32 a, s32 b) {
    lbl_80346F70 = a;
    lbl_80346F6C = b;
    lbl_80346F68 = a;
    lbl_80346F64 = b;
}

s32 fn_801431A0(void) {
    return fn_801E4BBC(8) != 0;
}

s32 fn_801431D0(void) {
    return fn_801E4BBC(9) != 0;
}

s32 fn_80143274(void) {
    return (rand() & 1) ^ 1;
}

s32 fn_8014329C(void) {
    return rand() % 5 == 0;
}

s32 fn_801432E4(void) {
    return rand() % 10 == 0;
}

s32 fn_8014332C(void) {
    return rand() % 100 == 0;
}

s32 fn_80143374(void) {
    return 1;
}

void fn_80144E5C(void) {
}

s32 fn_80145F50(Slot_8014359C *o, s32 a) {
    s32 roll = rand() % 100;
    s32 thr;

    if (o->x1 == 0) {
        thr = lbl_8030B7F4.chr[o->x3].s40;
    } else {
        thr = lbl_802D6934[o->x3].agile;
    }
    if (roll <= thr) {
        o->x7 = 2;
        return 1;
    }
    return 0;
}

void fn_801463E4(IdxArg* a) {
    if (a->idx == 0) {
        ((u8*)lbl_8034727C)[0x29] |= 0x40;
    } else {
        ((u8*)lbl_8034727C)[0x2a] |= 0x40;
    }
}

void fn_80146418(IdxArg* a) {
    if (a->idx == 0) {
        ((u8*)lbl_8034727C)[0x29] |= 0x20;
    } else {
        ((u8*)lbl_8034727C)[0x2a] |= 0x20;
    }
}

void fn_8014644C(IdxArg* a) {
    if (a->idx == 0) {
        ((u8*)lbl_8034727C)[0x29] |= 0x10;
    } else {
        ((u8*)lbl_8034727C)[0x2a] |= 0x10;
    }
}

void fn_80146480(IdxArg* a) {
    if (a->idx == 0) {
        ((u8*)lbl_8034727C)[0x29] |= 0x8;
    } else {
        ((u8*)lbl_8034727C)[0x2a] |= 0x8;
    }
}

s32 fn_80146BF4(s32 a, s32 b, s32 c, s32 idx, Req_UNIT0000 *p) {
    s32 d;
    s32 flag;
    Party *arr;
    s32 k;
    f32 f;
    f32 t;
    s32 cnt;
    f32 g;

    d = a * 2 - b;
    flag = 0;
    if (d < 0) {
        d = 0;
    }
    if (p->x1 == 0) {
        arr = lbl_8034727C->x24;
        k = lbl_8034727C->slot[idx].xc;
        if (lbl_8034727C->slot[idx].body.x0 == 3) {
            flag = 1;
        }
    } else {
        arr = lbl_8034727C->x20;
        k = lbl_8034727C->slot[idx].xa;
        if (lbl_8034727C->slot[idx].head.x0 == 3) {
            flag = 1;
        }
    }
    f = d;
    f *= k;
    f /= 10.0f;
    t = f * (0.000030517578125f * rand());
    cnt = 0.05 * t;
    f *= 0.975;
    cnt += f;
    if ((rand() & 7) == 0) {
        cnt++;
    }
    if (c < 0) {
        c = 0;
    }
    g = cnt;
    if (c < 6) {
        g *= arr->x28[c];
        g /= 10.0f;
    }
    if (flag != 0) {
        g *= 0.5f;
    }
    return g;
}

void fn_80146EF4(Slot_8014359C* r, s32 idx) {
    Blk* dst;
    s32 d;
    if (r->x1 == 0) {
        dst = &lbl_8034727C->a[idx];
    } else {
        dst = &lbl_8034727C->b[idx];
    }
    switch (r->x0) {
    case 5:
        d = lbl_802C4BF0[r->x8].ship_power;
        break;
    case 1:
        d = lbl_802D8A2C[r->x8 - 480].power;
        break;
    case 2:
        d = lbl_802C7C34[r->x8 - 240].power;
        break;
    case 7:
        d = lbl_802D8E64[r->x8].power;
        break;
    }
    dst->w8 = d * 10;
}

void fn_80147184(Slot_8014359C *c) {
    Party *f;
    s16 *flags;
    s32 k;

    if (c->x1 == 0) {
        f = lbl_8034727C->x20;
        flags = &lbl_8034727C->flag[0];
    } else {
        f = lbl_8034727C->x24;
        flags = &lbl_8034727C->flag[1];
    }
    if (*flags & 4) {
        c->x7 = 0;
        return;
    }
    switch (c->x0) {
    case 2:
        break;
    case 5:
        if (f->x54 > 0) {
            c->x7 = 0;
            return;
        }
        if (f->x50 > lbl_802C4BF0[c->x8].ship_turns) {
            c->x7 = 0;
            return;
        }
        if (f->x50 == 0) {
            f->x1e = f->x1c / 2;
            f->x1c = f->x1c + f->x1e;
            f->mem[0].x18 = f->mem[0].x16 / 2;
            f->mem[0].x16 = f->mem[0].x16 + f->mem[0].x18;
            f->mem[1].x18 = f->mem[1].x16 / 2;
            f->mem[1].x16 = f->mem[1].x16 + f->mem[1].x18;
            f->mem[2].x18 = f->mem[2].x16 / 2;
            f->mem[2].x16 = f->mem[2].x16 + f->mem[2].x18;
            f->mem[3].x18 = f->mem[3].x16 / 2;
            f->mem[3].x16 = f->mem[3].x16 + f->mem[3].x18;
            f->mem[4].x18 = f->mem[4].x16 / 2;
            f->mem[4].x16 = f->mem[4].x16 + f->mem[4].x18;
        }
        f->x50 = lbl_802C4BF0[c->x8].ship_turns;
        *flags |= 1;
        c->x7 = 1;
        break;
    case 1:
        k = c->x8 - 0x1e0;
        if (f->x54 > 0) {
            c->x7 = 0;
            return;
        }
        if (f->x50 > lbl_802D8A2C[k].turns) {
            c->x7 = 0;
            return;
        }
        if (f->x50 == 0) {
            f->x1e = f->x1c / 2;
            f->x1c = f->x1c + f->x1e;
            f->mem[0].x18 = f->mem[0].x16 / 2;
            f->mem[0].x16 = f->mem[0].x16 + f->mem[0].x18;
            f->mem[1].x18 = f->mem[1].x16 / 2;
            f->mem[1].x16 = f->mem[1].x16 + f->mem[1].x18;
            f->mem[2].x18 = f->mem[2].x16 / 2;
            f->mem[2].x16 = f->mem[2].x16 + f->mem[2].x18;
            f->mem[3].x18 = f->mem[3].x16 / 2;
            f->mem[3].x16 = f->mem[3].x16 + f->mem[3].x18;
            f->mem[4].x18 = f->mem[4].x16 / 2;
            f->mem[4].x16 = f->mem[4].x16 + f->mem[4].x18;
        }
        f->x50 = lbl_802D8A2C[k].turns;
        *flags |= 1;
        c->x7 = 1;
        break;
    case 7:
        if (f->x54 > 0) {
            c->x7 = 0;
            return;
        }
        if (f->x50 > lbl_802D8E64[c->x8].turns) {
            c->x7 = 0;
            return;
        }
        if (f->x50 == 0) {
            f->x1e = f->x1c / 2;
            f->x1c = f->x1c + f->x1e;
            f->mem[0].x18 = f->mem[0].x16 / 2;
            f->mem[0].x16 = f->mem[0].x16 + f->mem[0].x18;
            f->mem[1].x18 = f->mem[1].x16 / 2;
            f->mem[1].x16 = f->mem[1].x16 + f->mem[1].x18;
            f->mem[2].x18 = f->mem[2].x16 / 2;
            f->mem[2].x16 = f->mem[2].x16 + f->mem[2].x18;
            f->mem[3].x18 = f->mem[3].x16 / 2;
            f->mem[3].x16 = f->mem[3].x16 + f->mem[3].x18;
            f->mem[4].x18 = f->mem[4].x16 / 2;
            f->mem[4].x16 = f->mem[4].x16 + f->mem[4].x18;
        }
        f->x50 = lbl_802D8E64[c->x8].turns;
        *flags |= 1;
        c->x7 = 1;
        break;
    default:
        break;
    }
}

void fn_80147CC4(void) {
}

void fn_80147DC8(void) {
}

void fn_80147DCC(void) {
    fn_80100270();
    fn_801F7B04(0x10000 - 0x63C0);
}

void fn_80147DF8(void) {
    fn_80100270(lbl_802E5E68);
    fn_801F7B04(0x10000 - 0x63C0);
}

void fn_80147EA4(void) {
}

void fn_80147EA8(void) {
}

void fn_80148108(void) {
    if (lbl_803472A0 == 0) {
        return;
    }
    lbl_803472A0->cam->f8 = 0;
}

void fn_80148124(void) {
    if (lbl_803472A0 != 0) {
        lbl_803472A0->cam->f8 = 1;
    }
    fn_80097294(0);
}

void fn_80148160(void) {
    lbl_8030CEA0.x1614 = (s32)lbl_803472E0;
}

typedef struct Msg {
    s16 x0;
    s16 x2;
    s16 x4;
    s16 x6;
    s32 x8;
    s32 xc;
} Msg;
extern void fn_80129994(Msg*, s16);
void fn_80148188(void) {
}

void fn_8014818C(void) {
}

void fn_80148190(Msg* a, s16 i) {
    fn_80129994(a, i);
}

extern void fn_80129988(Msg*, s16);
void fn_801481B0(Msg* a, s16 i) {
    fn_80129988(a, i);
}

typedef struct Obj_80148464 {
    s32 idx;
    u8 lo[8];
    u8 hi[8];
} Obj_80148464;
extern const char lbl_802B3640[];

void fn_80148464(Obj_80148464* o) {
    s32 i;
    if (o->idx > 0xef8) {
        fn_801DBE1C(lbl_802B3640);
    }
    for (i = 0; i < 8; i++) {
        lbl_803472CC[o->idx + i].a = o->hi[i];
        lbl_803472CC[o->idx + i].b = o->lo[i];
    }
}

/* The record a scene script command hands fn_80148954. */
typedef struct {
    s32 w0;
    s32 w4;
    s32 w8;
    s32 wc;
    s32 w10;
    s32 w14;
    s32 w18;
    s32 w1c;
    s32 w20;
    u16 h24;
    u16 h26;
    u16 h28;
    u16 h2a;
    f32 f2c;
    f32 f30;
    f32 f34;
    f32 f38;
    u16 h3c;
    u16 h3e;
} Src_80148954;
extern void fn_801557A8(s32 cur, s32 id);

void fn_80148954(Src_80148954 *s)
{
    const StrPool_8013D400* msg = &lbl_802B3578;
    u16 id = s->w0;
    s32 a = s->w4;
    s32 b = s->w8;
    s32 c = s->wc;
    s32 d = s->w10;
    s32 e = s->w14;
    s32 f = s->w18;
    s32 g = s->w1c;
    u16 h = s->w20;
    u16 i = s->h24;
    u16 j = s->h26;
    u16 k = s->h28;
    u16 l = s->h2a;

    if (lbl_803472C4 == -1) {
        fn_801DBE1C(msg->sceneStart);
    }
    if (id >= 4) {
        fn_801DBE1C(msg->scenePhase);
    }
    if (lbl_80308F98[lbl_803472C4].items[id].f0 != -1) {
        fn_801DBE1C(msg->sceneDup, lbl_803472C4, id);
    }
    lbl_80308F98[lbl_803472C4].items[id].f0 = id;
    lbl_80308F98[lbl_803472C4].items[id].w4 = a;
    lbl_80308F98[lbl_803472C4].items[id].w8 = b;
    lbl_80308F98[lbl_803472C4].items[id].wc = c;
    lbl_80308F98[lbl_803472C4].items[id].w10 = d;
    lbl_80308F98[lbl_803472C4].items[id].w14 = e;
    lbl_80308F98[lbl_803472C4].items[id].w18 = f;
    lbl_80308F98[lbl_803472C4].items[id].w1c = g;
    lbl_80308F98[lbl_803472C4].items[id].w20 = h;
    lbl_80308F98[lbl_803472C4].items[id].w24 = i;
    lbl_80308F98[lbl_803472C4].items[id].w28 = j;
    lbl_80308F98[lbl_803472C4].items[id].w2c = k;
    lbl_80308F98[lbl_803472C4].items[id].w30 = l;
    lbl_80308F98[lbl_803472C4].items[id].f34 = s->f2c;
    lbl_80308F98[lbl_803472C4].items[id].f38 = s->f30;
    lbl_80308F98[lbl_803472C4].items[id].f3c = s->f34;
    lbl_80308F98[lbl_803472C4].items[id].f40 = s->f38;
    lbl_80308F98[lbl_803472C4].items[id].s44 = s->h3c;
    lbl_80308F98[lbl_803472C4].items[id].s46 = s->h3e;
    lbl_80308F98[lbl_803472C4].n += 1;
    lbl_80308F98[lbl_803472C4].count += a;
    fn_801557A8(lbl_803472C4, id);
}

void fn_80148DDC(void) {
    if (lbl_803472CC != 0) {
        fn_801E17E0(lbl_803472CC);
    }
}

void fn_80148E08(void) {
    lbl_80346F80 = -1;
    lbl_80347290 = 0;
    lbl_803472CC = fn_801E1A74(0xf00, 4);
    lbl_803472A8 = 0;
}

void fn_80148E80(Node* n);

void fn_80148E4C(Node *p) {
    fn_80148E80(p);
    p->x0 = 0;
}

void fn_801490F4(void) {
    void* p = fn_801E1A74(0x1f4, 4);
    lbl_80346F88 = p;
    memset(p, 0, 0x7d0);
}

extern void *fn_8010A214(u32 idx);
static inline void FreeSlot(s32 i)
{
    if (lbl_80346F88 != NULL) {
        if (lbl_80346F88[i] != NULL) {
            fn_80148EDC(lbl_80346F88[i]);
        }
        lbl_80346F88[i] = NULL;
    }
}
void fn_8014912C(void)
{
    u32 i;
    if (lbl_80346F88 != NULL) {
        for (i = 0; i < 500; i++) {
            if (lbl_80346F88[i] != NULL && fn_8010A214(i * 100) == NULL) {
                FreeSlot(i);
            }
        }
    }
}

void fn_8014E0B0(u8 *p) {
    u8 *src = *(u8 **)(*(u8 **)(p + 0x1d8) + 0x8);
    MemCopy(p + 0x38, src + 0x38, 0x24);
}

void fn_8014ED2C(Obj_UNIT0000* o) {
    Sub_UNIT0000* s = o->sub;
    s->f7c = 0;
    fn_8014FA10((u8*)s + 0x214);
}

void fn_8014F4E8(Timer* t) {
    s32 n;
    t->f20 = 0;
    t->f18 = 0;
    t->f1c = 0;
    t->f24 = 0;
    t->f2c = 0;
    n = t->f2e;
    if (n != 0) {
        t->f2e = n - 1;
    }
}

void fn_8014F714(Flags* p) {
    if (p->f28 == 0) {
        p->f29 = 1;
    }
}

void fn_8014F72C(void* p, s32 v) {
    memset(p, 0, 0x30);
    *(s16*)((u8*)p + 0x10) = v;
}

void fn_8013DB0C(s32 a)
{
    s32 d = 0;
    u32 f = lbl_8030A6D4[lbl_8034757C].xc;
    if (f & 1) d = -1;
    if (f & 2) d++;
    fn_8013DA50(a + d, d);
}

s32 fn_80141078(void)
{
    s32 r31 = 0;
    s32 i = 0;
    do {
        if (fn_8013E730(i) > 0) {
            r31 = 1;
            break;
        }
        i++;
    } while (i < 2);
    return r31;
}

void fn_80142F18(void)
{
    Struct80306738* p = &lbl_80306738;
    p->b[0] = 0;
    lbl_80346F61 = 0;
    p->b[1] = 0;
    p->b[2] = 0;
    p->b[3] = 0;
    p->b[4] = 0;
    p->b[5] = 0;
    p->b[6] = 0;
    p->b[7] = 0;
    p->b[8] = 0;
    p->b[9] = 0;
    p->b[10] = 0;
    p->b[11] = 0;
    p->b2[0] = 0;
    p->b2[1] = 0;
    p->b2[2] = 0;
    p->b2[3] = 0;
    p->b2[4] = 0;
    p->b2[5] = 0;
    p->h[0] = 0;
    p->h[1] = 0;
    p->h[2] = 0;
    p->h[3] = 0;
    p->h[4] = 0;
    lbl_80346F60 = 0;
}

void fn_801457C4(s32 a, s32 b)
{
    if (b == 0) {
        if (lbl_8034727C->slot[a].mode == 1) {
            fn_8014549C(a, 0);
        } else {
            fn_8014549C(a, 1);
        }
    } else {
        if (lbl_8034727C->slot[a].mode == 1) {
            fn_8014549C(a, 1);
        } else {
            fn_8014549C(a, 0);
        }
    }
}

s32 fn_80145D84(Obj7* dst, Obj24* a, Obj24* b)
{
    s32 v = 0x50 - b->x24 + a->x24;
    s32 r = rand() % 100;
    if (v >= r) {
        dst->x7 = 1;
        return 1;
    } else {
        dst->x7 = 0;
        return 0;
    }
}

void fn_80146FD4(Req_UNIT0000* r, s32 idx)
{
    u8* dst;
    Sub_80146FD4* s;
    s32 v = (s32)r;
    if (r->x1 == 0) {
        dst = (u8*)lbl_8034727C + idx * 0x90 + 0x124;
        s = *(Sub_80146FD4**)((u8*)lbl_8034727C + 0x20);
    } else {
        dst = (u8*)lbl_8034727C + idx * 0x90 + 0x5a4;
        s = *(Sub_80146FD4**)((u8*)lbl_8034727C + 0x24);
    }
    switch (r->x0) {
    case 1:
    case 2:
    case 5:
    case 7:
        v = s->x14 - s->x18;
        break;
    }
    *(s32*)(dst + 8) = v;
}

void fn_80147E2C(s32 a)
{
    fn_800FF908();
    sprintf(lbl_802E5E68, lbl_802B3578.sct, lbl_80311AC0.unk4, lbl_80311AC0.room);
    fn_801002D0(a);
    lbl_803472E4 = 1;
    lbl_80311AD4[6] = 0xc;
}

void fn_801481D0(void)
{
    if (lbl_80346F74 == 0 && lbl_80347290 == 0) {
        fn_80143060(&lbl_80347294);
        lbl_80310A1C[0x102] = 0;
        lbl_80347290 = 1;
        lbl_8034728C = 1;
    }
}

void fn_80148E80(Node* n)
{
    Node* b = n->x10;
    Node* a = n->x8;
    Node* c = n->x14;
    if (c != 0) {
        c->x10 = b;
    } else if (a != 0) {
        a->x4 = b;
    }
    if (b != 0) {
        b->x14 = c;
    }
    if (a != 0 && b == 0) {
        a->xc = c;
    }
    n->x8 = 0;
    n->x10 = 0;
    n->x14 = 0;
}

void fn_80140750(s32 cols, s32 rows)
{
    s32 j;
    s32 fill;
    s32 k;
    s32 i;
    Cell s;

    fn_80131500((s8)rows);
    for (i = 0; i < rows; i++) {
        fill = -1;
        for (j = 0; j < cols; j++) {
            for (k = 0; k < 4; k++) {
                s.x = j;
                s.y = i;
                s.a = k;
                s.c = fill;
                s.b = fill;
                fn_80131658(&s);
            }
        }
    }
    fn_80140264();
    for (fill = 0; fill < rows; fill++) {
        fn_8013FB48(fill, cols);
    }
}

s32 fn_80140FBC(s32 x)
{
    s32 over;
    s32 lim;
    s32 result = 0;
    s32 active;
    Big *base;
    Party *q;
    Member *t;

    if (fn_80140D04(x) != 0) {
        over = 0;
        lim = 100;
        base = fn_80135598();
        active = 0;
        q = &base->party;
        if (q != NULL && q->mem[4].state >= 0) {
            active = 1;
        }
        if (active) {
            t = &base->party.mem[4];
            lim = 100;
            if (t != NULL) {
                lim = t->b1f + t->b20;
            }
        }
        if (x >= lim) {
            over = 1;
        }
        if (over) {
            result = 1;
        }
    }
    return result;
}

void fn_801453D0(void)
{
    Big *base;
    Party *r;

    lbl_8034727C = fn_801E1A74(1, 0xab4);
    lbl_8034727C->count = lbl_8030B4D4.x2d4;
    lbl_8034727C->x4 = 0;
    lbl_8034727C->x18 = 0;
    lbl_8034727C->x1c = 0;
    lbl_8034727C->x6 = -1;
    lbl_8034727C->x8 = 0;
    lbl_8034727C->xa = -1;
    lbl_8034727C->xc = 0;
    lbl_8034727C->xe = -1;
    lbl_8034727C->x10 = 0;
    lbl_8034727C->x12 = -1;
    lbl_8034727C->x14 = 0;
    base = fn_80135598();
    r = fn_8013558C();
    lbl_8034727C->x20 = &base->party;
    lbl_8034727C->x24 = r;
    lbl_80347278 = 0;
}

s32 fn_80145CA4(s32 p, s32 idx, s32 kind)
{
    s32 result = 0;
    Party *base;
    s16 v;

    if (p == 0) {
        base = &fn_80135598()->party;
    } else {
        base = &fn_8013558C()[idx];
    }
    switch (kind) {
    case 2:
        v = base->x52;
        if (v > 0) {
            result = 1;
        }
        break;
    case 3:
        v = base->x50;
        if (v > 0) {
            result = 1;
        }
        break;
    case 8:
        v = base->x54;
        if (v > 0) {
            result = 1;
        }
        break;
    case 12:
        v = base->x56;
        if (v > 0) {
            result = 1;
        }
        break;
    }
    return result;
}

void fn_80148640(void)
{
    s32 sum;

    if (lbl_80346F80 == -1) {
        return;
    }
    if (fn_801298E8() == 0) {
        return;
    }
    lbl_803472BC = lbl_80346F80;
    lbl_803472A8 = &lbl_80308F98[lbl_80346F80];
    fn_801299A0();
    sum = lbl_803472D4 + lbl_803472C0;
    lbl_803472C0 = 0;
    lbl_803472D4 = sum;
    lbl_80310A1C[0x101] = 0;
    lbl_80310A1C[0x100] = 0;
    fn_80129BD4();
    lbl_80346F80 = -1;
    fn_8015635C();
}

static inline s32 NameCount(void) {
    s32 n = 0;
    s8 *p = fn_80135598()->order;
    if (p != NULL) {
        n = 0;
        if (p[0] >= 0) {
            n = 1;
            if (p[1] >= 0) {
                n = 2;
                if (p[2] >= 0) {
                    n = 3;
                    if (p[3] >= 0) {
                        n = 4;
                    }
                }
            }
        }
    }
    return n;
}

u32 fn_8013FE10(s32 a, s32 key) {
    u32 flags = 0;
    s32 n = NameCount();

    if (a >= 0 && a < n && lbl_80308E90[a + 4].kind != -1 &&
        key == lbl_80308E90[a + 4].key) {
        flags = 1;
    } else {
        if (a >= 0 && a < n && lbl_80308E90[a + 4].kind != -1) {
            flags = 2;
        } else if (a >= n) {
            flags = 0x10;
        }
        flags |= fn_8013FCF0(a, key, n);
    }
    return flags;
}

void fn_801462D0(Req_801462D0 *o) {
    MenuItem *p = &fn_80135598()->items[o->slot];
    s32 d;

    switch (o->kind) {
    case 5:
        d = lbl_802C4BF0[o->id].ship_power;
        break;
    case 1:
        d = lbl_802D8A2C[o->id - 0x1E0].power;
        break;
    case 2:
        d = lbl_802C7C34[o->id - 0xF0].power;
        break;
    case 7:
        d = lbl_802D8E64[o->id].power;
        break;
    }
    p->b0e += d;
    if (p->b0e > p->b0d) p->b0e = p->b0d;
}

void fn_8014ED5C(Owner *o, f32 v) {
    if (o->x8 == o->x10) {
        o->p->x190 = v;
    } else {
        o->p->x190 = o->x14;
    }
    if (o->p->x198 == 1) {
        o->x4 = 0;
        if (o->x18 != 0) {
            Body *b = o->p;
            s32 m = (s32)(100.0f * b->x18c);
            m = m % ((b->xe8->x4 - 1) * 100);
            b->x18c = (f32)m / 100.0f;
        } else {
            o->p->x190 = 0.0f;
        }
        if (o->x8 >= 0) {
            fn_8014EE4C(o, o->x8, 1, 1, 10);
        }
    }
}

void fn_8014359C(BtlCmd* in, s32 a, s32 b)
{
    Slot_8014359C* d = (Slot_8014359C*)((u8*)(*(Ent_8014359C**)&lbl_8034727C) + 0x134 + a * 0x90 + b * 0x10);
    s32 mode;
    d->x0 = in->x0;
    d->x1 = in->x1;
    d->x2 = in->x2;
    d->x3 = in->x3;
    d->x4 = in->x5;
    d->x5 = in->x6;
    d->x6 = in->x9;
    d->x8 = in->xc;
    d->xa = in->x14;
    if ((*(Ent_8014359C**)&lbl_8034727C)[b].mode == 2)
        mode = lbl_803472A4->f3c;
    else
        mode = lbl_803472A4->f40;
    switch (in->x5) {
    case 1:
        if (mode & 1) {
            d->x7 = 4;
        } else if (fn_80145E0C(d, a) != 0) {
            fn_80145F50(d, a);
        }
        break;
    case 0:
        if (mode & 2) {
            d->x7 = 4;
        } else if (fn_80145E0C(d, a) != 0) {
            fn_80145F50(d, a);
        }
        break;
    case 2:
        if (fn_80145E0C(d, a) != 0)
            fn_80145F50(d, a);
        break;
    case 3:
    default:
        d->x7 = 1;
        break;
    }
}

void fn_8014D1F4(Task_8014D1F4* t)
{
    extern char lbl_802B39DC[];
    extern void fn_80227810(void*);
    extern void fn_8015ED90(Task_8014D1F4*);
    extern Obj1E8* fn_8010A164(void*);
    extern void fn_801DBE1C(const char*, ...);
    extern void* fn_801E1A74(s32, s32);
    extern void* memset(void*, int, u32);
    extern void fn_801E735C(s32, Work_8014D1F4*, f32);
    extern void fn_80156B04(void*, Work_8014D1F4*, s32, s32, void*);
    extern s32 fn_8015E600(Work_8014D1F4*);
    extern void fn_80156DA0(Work_8014D1F4*, void*);
    extern void fn_801E17E0(void*);
    extern void fn_8015EBF4(Work_8014D1F4*);
    extern void fn_802275A4(void*, s32);
    extern void fn_80100B74(Task_8014D1F4*);
    Work_8014D1F4* w = t->work;
    u8 buf[0x3C];

    switch (t->state) {
    case 0:
    case 0xFE:
        fn_80227810(w->x100);
        fn_8015ED90(t);
        t->state = 1;
        break;
    case 1: {
        Cfg_8014D1F4* c = w->x1c8->x10;
        s32* p;
        Obj1E8* o = fn_8010A164(c->kind > 0xE ? c->x3c : NULL);
        w->x1e8 = o;
        if (o == NULL) {
            fn_801DBE1C(lbl_802B39DC, w->id);
        }
        t->state = 2;
        p = fn_801E1A74(1, 0xC);
        w->x23c = (void*)p;
        memset(p, 0, 0xC);
        p[1] = (s32)w->x1e8->x24->x23c;
        if (w->x1c8->x10->kind >= 0xF) {
            p[0] = 1;
            fn_801E735C(0, w, 1.0f);
        }
    }
    case 2:
        fn_80156B04((u8*)w->x23c->x4 + 0x1D4, w, 0, 0, buf);
        if (fn_8015E600((Work_8014D1F4*)t->work) == 0) {
            fn_80156DA0(w, buf);
        }
        break;
    case 0xFF:
        fn_801E17E0(w->x23c);
        fn_8015EBF4((Work_8014D1F4*)t->work);
        if (w->x100 != NULL) {
            fn_802275A4(w->x100, 0);
        }
        fn_80100B74(t);
        break;
    }
}

void fn_80143734(Out_80143734* o, s32 idx) {
    Src_80143734* src;
    u8* base;
    s32 i;
    s32 n;
    u8* dst;
    u8* sp;

    src = fn_80145844(lbl_803472BC);
    switch (src->f0) {
    case 0:
        o->f0 = 4;
        break;
    case 1:
        o->f0 = 5;
        break;
    case 2:
        o->f0 = 6;
        break;
    case 3:
        o->f0 = 3;
        break;
    default:
        o->f0 = -1;
        break;
    }
    o->f6 = src->f2;
    o->fc = src->f4;
    n = (*(Game_80143734**)&lbl_8034727C)->f28;
    o->f8 = src->f6 + idx;
    o->f1 = 1;
    o->f3 = (*(Game_80143734**)&lbl_8034727C)->x24[0x11];
    o->f5 = (*(Game_80143734**)&lbl_8034727C)->x24[o->f6 * 0x22 + 0x74];
    o->f4 = 0;
    o->f14 = 0;
    i = 0;
    base = (u8*)&(*(Game_80143734**)&lbl_8034727C)->rows[idx];
    dst = base;
    for (; i < n; i++) {
        sp = base + ((i + n) << 4);
        *(Blk_80143734*)(dst + 0x10) = *(Blk_80143734*)(sp + 0x10);
        fn_801E0FD4(sp + 0x10, 0x10);
        dst += 0x10;
    }
    switch (o->f0) {
    case 0:
    case 3:
        break;
    case 4:
        o->f9 = (*(Game_80143734**)&lbl_8034727C)->x24[o->f6 * 0x22 + 0x75];
        o->f14 = 0x6b;
        break;
    case 5:
        o->f9 = lbl_802C4BF0[o->fc].element;
        o->f14 = lbl_802C4BF0[o->fc].ship_effect;
        break;
    default:
        o->f9 = 6;
        break;
    }
}

void fn_80144A7C(Party* p, s32 which) {
    s16* fl;

    if (which == 0) {
        fl = &lbl_8034727C->flag[0];
    } else {
        fl = &lbl_8034727C->flag[1];
    }
    if (p->x50 > 0) {
        p->x50--;
        if (p->x50 == 0) {
            *fl &= ~1;
            p->x1c = p->x1c - p->x1e;
            p->x1e = 0;
            p->mem[0].x16 = p->mem[0].x16 - p->mem[0].x18;
            p->mem[0].x18 = 0;
            p->mem[1].x16 = p->mem[1].x16 - p->mem[1].x18;
            p->mem[1].x18 = 0;
            p->mem[2].x16 = p->mem[2].x16 - p->mem[2].x18;
            p->mem[2].x18 = 0;
            p->mem[3].x16 = p->mem[3].x16 - p->mem[3].x18;
            p->mem[3].x18 = 0;
            p->mem[4].x16 = p->mem[4].x16 - p->mem[4].x18;
            p->mem[4].x18 = 0;
        }
    }
    if (p->x52 > 0) {
        p->x52--;
        if (p->x52 == 0) {
            *fl &= ~2;
            p->x24 = p->x24 - p->x26;
            p->x26 = 0;
        }
    }
    if (p->x54 > 0) {
        p->x54--;
        if (p->x54 == 0) {
            *fl &= ~4;
            p->x1c = p->x1c - p->x1e;
            p->x1e = 0;
            p->x20 = p->x20 - p->x22;
            p->x22 = 0;
            p->x40 = p->x40 - p->x42;
            p->x42 = 0;
            p->mem[0].x16 = p->mem[0].x16 - p->mem[0].x18;
            p->mem[0].x18 = 0;
            p->mem[0].x1a = p->mem[0].x1a - p->mem[0].x1c;
            p->mem[0].x1c = 0;
            p->mem[1].x16 = p->mem[1].x16 - p->mem[1].x18;
            p->mem[1].x18 = 0;
            p->mem[1].x1a = p->mem[1].x1a - p->mem[1].x1c;
            p->mem[1].x1c = 0;
            p->mem[2].x16 = p->mem[2].x16 - p->mem[2].x18;
            p->mem[2].x18 = 0;
            p->mem[2].x1a = p->mem[2].x1a - p->mem[2].x1c;
            p->mem[2].x1c = 0;
            p->mem[3].x16 = p->mem[3].x16 - p->mem[3].x18;
            p->mem[3].x18 = 0;
            p->mem[3].x1a = p->mem[3].x1a - p->mem[3].x1c;
            p->mem[3].x1c = 0;
            p->mem[4].x16 = p->mem[4].x16 - p->mem[4].x18;
            p->mem[4].x18 = 0;
            p->mem[4].x1a = p->mem[4].x1a - p->mem[4].x1c;
            p->mem[4].x1c = 0;
        }
    }
    if (p->x56 > 0) {
        p->x56--;
        if (p->x56 == 0) {
            *fl &= ~8;
        }
    }
}

void fn_80148790(s32 n, s32 mode, s32 kind, s32 a, s32 b) {
    const StrPool_8013D400* msg;
    s32 rem;

    msg = &lbl_802B3578;
    if (lbl_803472C4 == -1) {
        fn_801DBE1C(msg->enemyStart);
    }
    rem = n % lbl_803472D0;
    if ((u32)n >= lbl_80347298) {
        fn_801DBE1C(msg->enemyPhase);
    }
    if (lbl_80308F98[lbl_803472C4].items[n].f48 != -1) {
        fn_801DBE1C(msg->enemyDup, lbl_803472C4, n);
    }
    if (mode == 0) {
        if (kind < 0) {
            fn_801DBE1C(msg->gunKind, lbl_803472C4, n);
        }
        if (kind == 1) {
            if (b < 0) {
                b = 1;
            } else if (b + rem > lbl_803472D0) {
                b = lbl_803472D0 - rem;
            }
        } else if (kind == 2) {
            if (b < rem) {
                b = rem;
            } else if (b >= lbl_803472D0) {
                b = lbl_803472D0 - 1;
            }
        }
    }
    if (mode == 0) {
        mode = 4;
    } else if (mode == 1) {
        mode = 5;
    } else if (mode == 2) {
        mode = 6;
    } else if (mode == 3) {
        mode = 3;
    }
    lbl_80308F98[lbl_803472C4].items[n].f48 = mode;
    lbl_80308F98[lbl_803472C4].items[n].f4c = kind;
    lbl_80308F98[lbl_803472C4].items[n].f50 = a;
    lbl_80308F98[lbl_803472C4].items[n].f54 = b;
}

void fn_8014B510(Obj_8014B510* o) {
    union {
        u8 b[4];
        u32 w;
    } c;
    Vtx_8014B510 v[4];
    f32 hx;
    f32 hy;
    f32 k;
    s32 idx;
    u8 c0;
    f32 neg = -1.0f;
    f32 zero = 0.0f;
    f32 one = 1.0f;
    u32 cnt;

    hx = 0.5f * o->f0;
    hy = 0.5f * o->f4;
    c0 = o->f14;
    c.b[0] = c0;
    if (o->f10 != 0) {
        c.b[1] = o->f15;
        c.b[2] = o->f16;
        c.b[3] = o->f17;
    } else {
        c.b[3] = 0xff;
        c.b[2] = 0xff;
        c.b[1] = 0xff;
    }
    if (o->fc != 0) {
        k = 0.003921569f * c0;
        c.b[1] = c.b[1] * k;
        c.b[2] = c.b[2] * k;
        c.b[3] = c.b[3] * k;
    }
    if (o->f1c != NULL) {
        idx = o->f8;
        cnt = o->f1c->f4;
        if (cnt <= idx) {
            idx = (s16)(cnt - 1);
        }
        fn_80298FE4((s16)idx);
        v[3].x = hx;
        v[2].x = hx;
        v[2].y = hy;
        v[0].y = hy;
        v[2].v = zero;
        v[0].v = zero;
        v[1].u = zero;
        v[0].u = zero;
        v[3].v = one;
        v[1].v = one;
        v[3].u = one;
        v[2].u = one;
        v[1].z = zero;
        v[3].z = zero;
        v[2].z = zero;
        v[0].z = zero;
        hx *= neg;
        hy *= neg;
        v[1].x = hx;
        v[0].x = hx;
        v[1].y = hy;
        v[3].y = hy;
        v[3].col = c.w;
        v[2].col = c.w;
        v[1].col = c.w;
        v[0].col = c.w;
        fn_8028A8C0(v, 4, 1);
    }
}

void fn_8014F518(Obj_8014F518* o) {
    s32 best;
    s32 cnt;
    s32 v;
    s32 i;

    best = -1;
    cnt = 0;
    fn_80156768(o->f10, o->f10 ^ 1, &o->f1c, &o->f20, 12.0f);
    if (o->f29 != 0 && o->f28 == 0) {
        o->f28 = 1;
        for (i = 0; i < 7; i++) {
            if (((s8*)o)[i * 2] != 0) {
                if (best < 0) best = i;
                cnt++;
            }
        }
        if (cnt == 0) {
            o->f2c = 6;
        } else {
            v = o->f14;
            if (v >= 0x1555) {
                if (v <= 0x6aaa) {
                    o->f24 = 0;
                } else {
                    o->f24 = 3;
                }
            } else if (v <= -0x1555) {
                if (v <= -0x6aaa) {
                    o->f24 = 3;
                } else {
                    o->f24 = 1;
                }
            } else {
                o->f24 = 2;
            }
            fn_80154404();
            o->f26 = fn_8015432C(o->f10 ^ 1, o->f18);
            fn_801545AC(o->f10 ^ 1, o->f26);
            fn_80153DB8(o->f10 ^ 1, o->f26);
            if (cnt == 1) {
                o->f2c = best;
            } else {
                o->f2c = 7;
            }
        }
    }
}

void fn_80147EAC(s32 id)
{
    Party* e;

    if (id == 0 || id == 0xFFFF) {
        Big* b = fn_80135598();
        e = &b->party;
        lbl_8030CEA0.x160c = b->x8;
        lbl_8030CEA0.x1610 = fn_80148024(0, id);
    } else {
        int i;
        int found = -1;
        for (i = 0; i < lbl_8034729C; i++) {
            Slot_80147EAC* s = &lbl_80308EF8[i];
            if (id == s->it->obj->id) {
                found = s->idx;
            }
        }
        if (found == -1) {
            fn_801DBE1C(lbl_802B3588, id);
        }
        e = &fn_8013558C()[found];
        lbl_8030CEA0.x160c = 0;
        lbl_8030CEA0.x1610 = fn_80148024(1, id);
    }
    lbl_8030CEA0.x15d8 = fn_80129D40(id)[2];
    lbl_8030CEA0.x15dc = e->hp_max;
    lbl_8030CEA0.x15e0 = e->mem[0].x16;
    lbl_8030CEA0.x15e4 = e->mem[1].x16;
    lbl_8030CEA0.x15e8 = e->mem[2].x16;
    lbl_8030CEA0.x15ec = e->mem[3].x16;
    lbl_8030CEA0.x15f0 = e->mem[0].x1a;
    lbl_8030CEA0.x15f4 = e->mem[1].x1a;
    lbl_8030CEA0.x15f8 = e->mem[2].x1a;
    lbl_8030CEA0.x15fc = e->mem[3].x1a;
    lbl_8030CEA0.x1600 = e->x1c;
    lbl_8030CEA0.x1604 = e->x20;
    lbl_8030CEA0.x1608 = e->x24;
}

void fn_80143FA4(u8* s, s32 idx, s32 slot) {
    u8* rec;
    s32 v;
    s32 neg;
    s8 t;

    rec = (u8*)&(*(G_80143FA4**)&lbl_8034727C)->r5.rows[idx].slots[slot];
    rec[0] = s[0];
    rec[1] = s[1];
    rec[2] = s[2];
    rec[3] = s[3];
    rec[4] = s[5];
    *(s16*)(rec + 8) = *(s16*)(s + 0xc);
    rec[6] = s[9];
    rec[5] = *(s16*)(s + 6);
    *(s16*)(rec + 0xa) = *(s16*)(s + 0x14);
    t = (*(G_80143FA4**)&lbl_8034727C)->h.x20[*(s16*)(s + 6)].pad[0x7f];
    neg = -t;
    if ((s8)s[5] == 2) {
        (*(G_80143FA4**)&lbl_8034727C)->b.rows[slot].f2 += neg;
    } else {
        (*(G_80143FA4**)&lbl_8034727C)->b.rows[idx].f2 += neg;
    }
    if ((*(G_80143FA4**)&lbl_8034727C)->ents[slot].f2c == 1) {
        v = lbl_803472A4->f34;
    } else {
        v = lbl_803472A4->f38;
    }
    switch ((s8)s[5]) {
    case 1:
        if (v & 1) {
            rec[7] = 4;
        } else if (fn_80145E0C((void *)(rec), idx) != 0) {
            fn_80145F50((void *)(rec), idx);
        }
        break;
    case 0:
        if (v & 2) {
            rec[7] = 4;
        } else if (fn_80145E0C((void *)(rec), idx) != 0) {
            fn_80145F50((void *)(rec), idx);
        }
        break;
    case 2:
        if (fn_80145E0C((void *)(rec), idx) != 0) {
            fn_80145F50((void *)(rec), idx);
        }
        break;
    case 3:
        rec[7] = 1;
        break;
    }
}

void fn_80147DA8(s32 a, s32 b) {
    fn_80142F04(a, b);
}

void fn_80143158(void)
{
    lbl_80346F74 = 0;
    lbl_80306738.task = 0;
    lbl_80346F70 = -1;
    lbl_80346F6C = -1;
    lbl_80346F68 = -1;
    lbl_80346F64 = -1;
    fn_80142F18();
}

void fn_801464B4(IdxArg_801464B4 *a)
{
    if (a->x7 != 0 && a->x7 != 4) {
        if (a->idx == 0) {
            (*(u8 **)&lbl_8034727C)[0x29] |= 0x4;
        } else {
            (*(u8 **)&lbl_8034727C)[0x2a] |= 0x4;
        }
    }
}

void fn_80146500(IdxArg_801464B4 *a)
{
    if (a->x7 != 0 && a->x7 != 4) {
        if (a->idx == 0) {
            (*(u8 **)&lbl_8034727C)[0x29] |= 0x2;
        } else {
            (*(u8 **)&lbl_8034727C)[0x2a] |= 0x2;
        }
    }
}

void fn_80146DE4(s32 a, s32 idx)
{
    Big *info = fn_80135598();

    (*(Mgr_80146DE4 **)&lbl_8034727C)->rec[idx].x2 += info->x6 - info->x8;
}

/* TRUE while cur is at least 70% of max. */
s32 fn_80143200(void) {
    s32 low = !((f64)(*(Ent_80143200 **)&lbl_8034727C)->stat->cur >= 0.7 * (*(Ent_80143200 **)&lbl_8034727C)->stat->max);
    return low == 0;
}

static inline void FreeSlots(s32 n) {
    s32 i;
    for (i = 0; i < n; i++) {
        if (lbl_80346F88 != NULL) {
            if (lbl_80346F88[i] != NULL) {
                fn_80148EDC(lbl_80346F88[i]);
            }
            lbl_80346F88[i] = NULL;
        }
    }
}

void fn_80149070(void) {
    FreeSlots(500);
    fn_801E17E0(lbl_80346F88);
    lbl_80346F88 = NULL;
}

static inline void copyrec(Rec *d, Rec *s)
{
    d->b0 = s->b0;
    d->b1 = s->b1;
    d->b2 = s->b2;
    d->b3 = s->b3;
    d->b4 = s->b4;
    d->b5 = s->b5;
    d->b6 = s->b6;
    d->s8 = s->s8;
    d->b7 = s->b7;
    d->sa = s->sa;
    d->wc = s->wc;
}

void fn_8014549C(s32 idx, s32 flag)
{
    u8 *sys;
    Blk *out;
    Blk *b1;
    Blk *b2;
    Src *q;
    Rec *e;
    s32 cnt;
    s32 k;
    Big *c;

    cnt = 0;
    sys = (*(u8 **)&lbl_8034727C);
    out = (Blk *)(sys + 0xa24);
    if (flag == 0) {
        q = (Src *)(sys + idx * 0x3e + 0x3a);
        b1 = (Blk *)(sys + idx * 0x90 + 0x124);
        b2 = (Blk *)(sys + idx * 0x90 + 0x5a4);
    } else {
        q = (Src *)(sys + idx * 0x3e + 0x52);
        b1 = (Blk *)(sys + idx * 0x90 + 0x5a4);
        b2 = (Blk *)(sys + idx * 0x90 + 0x124);
    }
    switch ((s8)q->b0) {
    case 0:
        out->e[0].b0 = q->b0;
        cnt = 1;
        out->e[0].b1 = q->b1;
        out->e[0].b2 = q->b2;
        out->e[0].b3 = q->b3;
        out->e[0].b4 = q->b5;
        out->e[0].b5 = q->s6;
        out->e[0].b6 = q->b9;
        out->e[0].s8 = q->sc;
        out->e[0].sa = q->s14;
        out->e[0].wc = 0;
        out->e[0].b7 = b1->e[0].b7;
        break;
    case -1:
    case 3:
    case 6:
        out->e[0].b0 = q->b0;
        cnt = 1;
        out->e[0].b1 = q->b1;
        out->e[0].b2 = q->b2;
        out->e[0].b3 = q->b3;
        out->e[0].b4 = q->b5;
        out->e[0].b5 = q->s6;
        out->e[0].b6 = q->b9;
        out->e[0].s8 = q->sc;
        out->e[0].sa = q->s14;
        out->e[0].wc = 0;
        break;
    case 4:
        if ((s32)q->b5 == 2) {
            out->e[0].b0 = q->b0;
            cnt = 1;
            out->e[0].b1 = q->b1;
            out->e[0].b2 = q->b2;
            out->e[0].b3 = q->b3;
            out->e[0].b4 = q->b5;
            out->e[0].b5 = q->s6;
            out->e[0].b6 = q->b9;
            out->e[0].s8 = q->sc;
            out->e[0].sa = q->s14;
            out->e[0].wc = 0;
            out->e[0].b7 = 3;
        }
        break;
    }
    for (k = 0; k < 8; k++) {
        e = &b2->e[k];
        if ((s8)e->b0 != 0) {
            if (k == idx) {
                switch ((s8)q->b0) {
                case 3:
                case -1:
                case 6:
                    break;
                default:
                    copyrec(&out->e[cnt], e);
                    cnt++;
                    break;
                }
            } else {
                copyrec(&out->e[cnt], e);
                cnt++;
            }
        }
    }
    c = fn_80135598();
    out->s0 = cnt;
    out->s2 = b1->s2;
    if (out->s2 > c->x6 - c->x8) out->s2 = c->x6 - c->x8;
    out->w8 = b1->w8;
    out->wc = b2->wc;
}

static inline void boost(Ent_8014654C *e)
{
    e->s1c += e->s1c / 2;
    e->s20 += e->s20 / 2;
    e->s40 += e->s40 / 2;
    e->s76 += e->s76 / 2;
    e->s7a += e->s7a / 2;
    e->s98 += e->s98 / 2;
    e->s9c += e->s9c / 2;
    e->sba += e->sba / 2;
    e->sbe += e->sbe / 2;
    e->sdc += e->sdc / 2;
    e->se0 += e->se0 / 2;
    e->sfe += e->sfe / 2;
    e->s102 += e->s102 / 2;
}

void fn_8014654C(Obj *o)
{
    Ent_8014654C *e;
    o->b7 = 0;
    if (*((s8 *)o + 1) == 0) {
        if ((*(Sys_8014654C **)&lbl_8034727C)->b29 & 1) return;
        (*(Sys_8014654C **)&lbl_8034727C)->b29 |= 1;
        e = (*(Sys_8014654C **)&lbl_8034727C)->x20;
        o->b7 = 1;
        boost(e);
    } else {
        if ((*(Sys_8014654C **)&lbl_8034727C)->b2a & 1) return;
        (*(Sys_8014654C **)&lbl_8034727C)->b2a |= 1;
        e = (*(Sys_8014654C **)&lbl_8034727C)->x24;
        o->b7 = 1;
        boost(e);
    }
}

s32 fn_8013DBDC(s32 a, s32 b)
{
    s32 d = 0;
    u32 f = lbl_8030A6D4[lbl_8034757C].xc;
    if (f & 1) d = -1;
    if (f & 2) d++;
    return fn_8013DB8C(a, b + d, d);
}

static inline s32 KindMode(s32 kind)
{
    s32 mode = -1;

    switch (kind) {
    case 0:
        mode = 1;
        break;
    case 1:
        mode = 2;
        break;
    }
    return mode;
}

static inline int KindUsable(s32 kind, s8 *list, s32 idx)
{
    InvEnt *tbl;
    s32 res;
    int ok;
    Big *p;

    ok = 0;
    tbl = NULL;
    res = -1;

    switch (kind) {
    case 0:
        p = fn_80135598();
        if (p != NULL) {
            tbl = p->x14e;
        }
        break;
    case 1:
        p = fn_80135598();
        if (p != NULL) {
            tbl = p->xe;
        }
        break;
    }
    if (tbl != NULL && list != NULL && idx >= 0 && idx < 6) {
        res = fn_8013D718(kind, tbl, list[idx]);
    }
    if (res >= 0) {
        ok = 1;
    }
    return ok;
}

void fn_8013D938(s32 a, s32 b, s32 kind, s8 *list, s32 idx)
{
    s32 mode;
    s32 v;

    if (KindUsable(kind, list, idx)) {
        v = list[idx];
        mode = KindMode(kind);
        if (mode != -1) {
            fn_80136A28(a, b, mode, v, -1, -1);
        }
    }
}

static inline int StateValid(Party *p, s32 m)
{
    int ok = 0;

    if (p != NULL && m >= 0 && m < 5 && p->mem[m].state >= 0) {
        ok = 1;
    }
    return ok;
}

static inline s32 MemberStatus(s32 m)
{
    s32 st;
    Party *p;

    p = &fn_80135598()->party;
    st = 4;

    if (StateValid(p, m)) {
        st = p->mem[m].state;
    }
    return st;
}

u32 fn_8013FCF0(s32 a, s32 key, s32 n)
{
    s32 end;
    u32 flags = 0;
    s32 i;
    s32 st;
    s32 level;

    end = a > n ? n : a;
    for (i = -n; i < end; i++) {
        if (lbl_80308E90[i + 4].kind == 4 && key == lbl_80308E90[i + 4].key) {
            st = MemberStatus(lbl_80308E90[i + 4].member);
            level = lbl_80308E90[i + 4].level;
            switch (st) {
            case 1:
                if (a <= level) {
                    flags |= 4;
                }
                break;
            case 2:
                if (a == level) {
                    flags |= 8;
                }
                break;
            }
        }
    }
    return flags;
}

static inline void TaskStop(Task *t)
{
    if (t != NULL) {
        t->x24 = 0;
        t->x28 = 0;
        t->flags |= 0x40;
    }
}

static inline void Close(s32 *p)
{
    Struct80306738 *w;

    if (p != NULL) {
        *p = -1;
        lbl_80346F74 = NULL;
        fn_8012AEB8(1);
        fn_8012AED0(1);
        fn_8012C648(1);
        fn_8012E5C0(1);
        fn_80130350(1);
        fn_801316B4(1);
        fn_8013312C(1);
        fn_8015A844();
        fn_8012C048(0x16);
        w = &lbl_80306738;
        if (w != NULL && w->task != NULL) {
            TaskStop(w->task);
            w->task = NULL;
        }
        lbl_80346F68 = lbl_80346F70;
        lbl_80346F64 = lbl_80346F6C;
        lbl_80346F70 = -1;
        lbl_80346F6C = -1;
        fn_80142F18();
    }
}

void fn_80143060(s32 *p)
{
    if (lbl_80346F74 != NULL) {
        Close(lbl_80346F74);
    }
    lbl_80346F74 = p;
    *p = 0;
    fn_80142F18();
}

void fn_80144680(void)
{
    s32 i;
    s32 n;

    lbl_80346F78 = 0;
    n = (*(Work_80144680 **)&lbl_8034727C)->count;
    for (i = 0; i < n; i++) {
        (*(Work_80144680 **)&lbl_8034727C)->a[i] = (*(Work_80144680 **)&lbl_8034727C)->a[i + n];
        fn_801E0FD4((void *)(&(*(Work_80144680 **)&lbl_8034727C)->a[i + n]), 0x90);
        fn_80144400((*(Work_80144680 **)&lbl_8034727C)->slot[i].head, i);
        (*(Work_80144680 **)&lbl_8034727C)->b[i] = (*(Work_80144680 **)&lbl_8034727C)->b[i + n];
        fn_801E0FD4((void *)(&(*(Work_80144680 **)&lbl_8034727C)->b[i + n]), 0x90);
        fn_80143734((void *)((*(Work_80144680 **)&lbl_8034727C)->slot[i].body), i);
    }
}

s32 fn_80148024(s32 side, s32 id)
{
    s32 type;
    s32 r;

    if (lbl_80347290 == 1) {
        return 0;
    }
    if (side != 0) {
        if (lbl_803472A4 == NULL) {
            return 0;
        }
        if (lbl_803472A4->id != id) {
            return 0;
        }
    }
    type = fn_8015C4A0(side, lbl_803472B4);
    r = 0;
    switch (type) {
    case 4:
        r = lbl_802E5EA8[fn_8015C468(side, lbl_803472B4)];
        break;
    case 5:
        r = 3;
        break;
    case 1:
    case 2:
        r = 4;
        break;
    case 3:
    case 6:
        r = 2;
        break;
    case 0:
        r = 5;
        break;
    case 7:
        r = 10;
        break;
    }
    return r;
}

void fn_80148228(s32 ship, s32 path)
{
    const StrPool_8013D400* msg = &lbl_802B3578;

    if (path != 0x7fffffff) {
        if ((lbl_803472A0->cam->path = fn_801094C8(path)) == NULL) {
            fn_801DBE1C(msg->camPath, path);
        }
        if (fn_8025EF88(lbl_803472A0->cam->path->model->node->name, msg->croot) != 0) {
            fn_801DBE1C(msg->notCamPath, path, lbl_803472A0->cam->path->model->node->name);
        }
        if (lbl_803472A0->cam->path->model->motion == NULL) {
            fn_801DBE1C(msg->camMotion, path);
        }
    } else {
        lbl_803472A0->cam->path = NULL;
    }
    if (ship != 0x7fffffff) {
        if ((lbl_803472A0->cam->ship = fn_801094C8(ship)) != NULL) {
            lbl_803472A0->cam->ship = NULL;
        }
    }
}

void fn_8014F834(Range_8014F834* r, u16 ang, s32 a0, s32 a1, s32 lo, s32 hi, s32 b0, s32 b1)
{
    s32 a = ang;
    s32 top;
    s32 bot;
    s32 i;

    if (a >= 0x8000) {
        a = -(0x10000 - a);
    }
    top = (a + a0 + b0 + 0x7f) / 512;
    bot = (a + a1 + b1 - 0x7f) / 512;
    top = (top < 0x3f) ? top : 0x3f;
    bot = (bot > -0x3f) ? bot : -0x3f;
    top += 0x40;
    bot += 0x40;
    for (i = bot; i <= top; i++) {
        r->mask[i] = 1;
    }
    lo = (lo > -0x3fff) ? lo : -0x3fff;
    hi = (hi < 0x3fff) ? hi : 0x3fff;
    r->hi = (r->hi > hi) ? r->hi : hi;
    r->lo = (r->lo < lo) ? r->lo : lo;
}

typedef struct { u8 pad[0x1ef]; s8 f1ef; } In_8014B6F8;
typedef struct { u8 pad[0x24]; In_8014B6F8 *p24; } Mid_8014B6F8;
typedef struct {
    u8 pad0[0x28];
    Mid_8014B6F8 *p28;
    u8 pad2c[4];
    s32 x30;
    u8 pad34[4];
    s32 x38;
    u8 pad3c[0x44 - 0x3c];
    s32 x44;
    u8 pad48[0x5c - 0x48];
    s32 x5c;
    u8 pad60[0x70 - 0x60];
} CamPart;
typedef struct CamNode {
    s32 active;                 /* 0x000 */
    Leader *x4;                 /* 0x004 */
    s32 x8;                     /* 0x008 */
    Ctx_8014D398 *ctx;          /* 0x00c */
    s32 x10;
    s32 x14;
    s32 x18;
    s32 x1c;
    f32 f20;
    s32 x24;
    CamPart a;                  /* 0x028 */
    CamPart b;                  /* 0x098 */
    void *x108;
    s32 x10c;
} CamNode;
extern s32 strcmp(const char *a, const char *b);
extern void fn_8014FCD8(void *p, s32 a, s32 b);
extern void fn_80152EF0(CamPart *p);
extern void fn_80152B58(CamPart *p, s32 id, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h, s32 i, s32 j, s32 k, s32 l);
extern void fn_80153958(void *p);
extern void fn_80152AFC(CamPart *p);
extern void *fn_80153790(s32 a, s32 b, s16 c);
extern void fn_801528AC(CamPart *p, void *loc, void *c, s32 d);
extern s32 fn_8014FC9C(void *a, void *b);
extern void fn_8015275C(CamPart *p, void *loc, s32 c);
extern void fn_8015271C(CamPart *p);

void fn_8014B6F8(Task_8014D398 *t)
{
    CamNode *p;
    CamPart *a;
    CamPart *b;
    Ctx_8014D398 *ctx;
    s32 v1;
    s32 v2;
    s32 v3;
    s32 v0;
    LeaderRec *rec;
    Info *info;
    void *r;
    W4 *w4;
    s32 loc[16];

    ctx = t->x24;
    switch (t->b19) {
    case 0:
    case 0xfe:
        fn_80227810(ctx->x100);
        fn_8015ED90(t);
        t->b19 = 1;
        break;
    case 1:
        info = ctx->x1c8->x10;
        r = fn_8010A164(info->w0 > 0xe ? info->x3c : NULL);
        ctx->x1e8 = r;
        if (r == NULL) {
            fn_801DBE1C("Leader Ship Is Nothing %d", ctx->h17a);
        }
        t->b19 = 2;
        p = fn_801E1A74(1, 0x110);
        ctx->x23c = p;
        a = &p->a;
        b = &p->b;
        memset(p, 0, 0x110);
        p->x4 = ctx->x1e8->x24->x23c;
        if (p->x4 == NULL || (p->x4 != NULL && strcmp(p->x4->name, "shp") != 0)) {
            fn_801DBE1C("Leader Ship Miss {%d} opt=%d", ctx->h17a, ctx->x1e8->x24->h17a);
        }
        fn_8014FCD8(p->x4->x214, 2, 0x46);
        p->active = 1;
        memset(&p->ctx, 0, 0x1c);
        p->ctx = ctx;
        p->x1c = -1;
        p->x14 = -1;
        p->x14 = 0;
        fn_8014EE4C(&p->ctx, 0, 1, 0, 0xa);
        v1 = ctx->x1c8->x10->w0 > 0x12 ? ctx->x1c8->x10->x4c : 0;
        v2 = ctx->x1c8->x10->w0 > 0x13 ? ctx->x1c8->x10->x50 : 0;
        v3 = ctx->x1c8->x10->w0 > 0x14 ? ctx->x1c8->x10->x54 : 0;
        if (v1 == 0) {
            v1 = 0x87f0;
        }
        if (v2 == 0) {
            v2 = 0x75f8;
        }
        if (v3 == 0) {
            v3 = 0x7724;
        }
        fn_80152EF0(a);
        info = ctx->x1c8->x10;
        fn_80152B58(a, ctx->h17a, p->x4->x8 ^ 1, ctx->x1e8->x24->x1e4, 2,
                    info->w0 > 0xf ? info->x40 : 0, info->w0 > 0x10 ? info->x44 : 0, 0, 0, 0, 0, 0);
        fn_80152EF0(b);
        v0 = ctx->x1c8->x10->w0 > 0x11 ? ctx->x1c8->x10->x48 : 0;
        fn_80152B58(b, ctx->h17a, p->x4->x8 ^ 1, ctx->x1e8->x24->x1e4, 3,
                    v0, 0, v1, v2, v3, 0, 0);
        p->x4->x3a4++;
    case 2:
        p = ctx->x23c;
        a = &p->a;
        b = &p->b;
        if (p->x4->xc04 != 0) {
            p->x8 = (ctx->h17a & 3) * 2 + (s32)(2.0 * (0.99 * (3.0517578e-5f * rand())));
            if (p->x108 != NULL) {
                fn_80153958(p->x108);
                p->x108 = NULL;
            }
            fn_80152AFC(a);
            fn_80152AFC(b);
        }
        fn_80156B04(p->x4->x1d4, ctx, 0, 0, loc);
        if (p->active != 0) {
            rec = &p->x4->rec[p->x8];
            if (p->x4->x21c->x10 != NULL) {
                if (rec->x70 != 0) {
                    p->x10c = 1;
                    fn_8014EE4C(&p->ctx, 0x14, 1, 0, 0xa);
                    p->x4->x3a0++;
                }
                if (rec->x84 != 0) {
                    fn_8014EE4C(&p->ctx, 0x1e, 1, 0, 0xa);
                    p->x10c = 0;
                }
                if (rec->x7c != 0) {
                    p->x10c = 0;
                    fn_80153790(a->x38, a->x44, p->x4->x8);
                    fn_801528AC(a, loc, p->x4->xc08, 0);
                    p->x4->x3a2++;
                }
                if (rec->xa4 != 0) {
                    p->x4->x448++;
                }
                if (rec->xc0 != 0) {
                    fn_801528AC(b, loc, p->x4->xc08, fn_8014FC9C(p->x4->x214, p->x4->x21c->x68));
                    p->x108 = fn_80153790(b->x30, b->x5c, p->x4->x8);
                    p->x4->x44a++;
                }
            }
        }
        fn_8015275C(a, loc, p->x10c);
        fn_8015275C(b, loc, 0);
        if (p->x108 != NULL && b->p28 != NULL && b->p28->p24->f1ef != 0) {
            b->p28->p24->f1ef = 0;
            fn_80153958(p->x108);
            p->x108 = NULL;
        }
        if (fn_8015E600(t->x24) == 0) {
            if (ctx->xe8 != NULL) {
                if (p->x24 != 0) {
                    if (p->x14 == p->x1c) {
                        p->ctx->f190 = 1.0f;
                    } else {
                        p->ctx->f190 = p->f20;
                    }
                }
                if (p->x24 == 0) {
                    w4 = p->ctx->xe8;
                    if (p->ctx->f18c >= (f32)w4->w4 - 1.0f) {
                        p->ctx->f190 = 0.0f;
                        p->x10 = 0;
                    }
                }
                fn_80156E54(ctx, loc);
            } else {
                fn_80156DA0(ctx, loc);
            }
        }
        break;
    case 0xff:
        p = ctx->x23c;
        fn_8015271C(&p->a);
        fn_8015271C(&p->b);
        fn_801E17E0(p);
        fn_8015EBF4(t->x24);
        if (ctx->x100 != NULL) {
            fn_802275A4(ctx->x100, 0);
        }
        fn_80100B74(t);
        break;
    }
}

void fn_8014D398(Task_8014D398 *t)
{
    Ctx_8014D398 *ctx;
    Node_8014D398 *p;
    s32 loc[16];
    void *r;
    Info *info;
    W4 *w4;

    ctx = t->x24;
    switch (t->b19) {
    case 0:
    case 0xfe:
        fn_80227810(ctx->x100);
        fn_8015ED90(t);
        t->b19 = 1;
        break;
    case 1:
        info = ctx->x1c8->x10;
        r = fn_8010A164(info->w0 > 0xe ? info->x3c : NULL);
        ctx->x1e8 = r;
        if (r == NULL) {
            fn_801DBE1C("Leader Ship Is Nothing %d", ctx->h17a);
        }
        t->b19 = 2;
        p = fn_801E1A74(1, 0x24);
        ctx->x23c = p;
        memset(p, 0, 0x24);
        p->x4 = ctx->x1e8->x24->x23c;
        if (p->x4 == NULL || (p->x4 != NULL && fn_8025EF88(p->x4, "shp") != 0)) {
            fn_801DBE1C("Leader Ship Miss {%d} opt=%d", ctx->h17a, ctx->x1e8->x24->h17a);
        }
        if (ctx->x1c8->x10->w0 >= 0xf) {
            p->w0 = 1;
            memset(&p->x8, 0, 0x1c);
            p->x8 = ctx;
            p->x18 = -1;
            p->x10 = -1;
            p->x10 = 0;
            fn_8014EE4C(&p->x8, 0, 1, 1, 0xa);
        }
    case 2:
        p = ctx->x23c;
        fn_80156B04((u8 *)p->x4 + 0x1d4, ctx, 0, 0, loc);
        if (fn_8015E600(t->x24) == 0) {
            if (ctx->xe8 != NULL) {
                if (p->x20 != 0) {
                    if (p->x10 == p->x18) {
                        p->x8->f190 = 1.0f;
                    } else {
                        p->x8->f190 = p->f1c;
                    }
                }
                if (p->x20 == 0) {
                    w4 = p->x8->xe8;
                    if (p->x8->f18c >= (f32)w4->w4 - 1.0f) {
                        p->x8->f190 = 0.0f;
                        p->xc = 0;
                    }
                }
                fn_80156E54(ctx, loc);
            } else {
                fn_80156DA0(ctx, loc);
            }
        }
        break;
    case 0xff:
        fn_801E17E0(ctx->x23c);
        fn_8015EBF4(t->x24);
        if (ctx->x100 != NULL) {
            fn_802275A4(ctx->x100, 0);
        }
        fn_80100B74(t);
        break;
    }
}

void fn_8013ECF4(s8 a, s8 b, s32 c, void *p) {
    fn_8012E5B0(1);
    fn_8012E560(c);
    fn_8012E5A0(fn_8013EA10());
    fn_8012E590(a + 6);
    fn_8012E414(c < 0);
    fn_8012E404(!(c < 0));
    fn_8013E0BC(a, b, p);
    fn_8012E5C0(0);
}

static inline s32 Mode_80141390(void) {
    s32 k;
    Party *b = &fn_80135598()->party;
    s32 ok;
    k = 4;
    ok = 0;
    if (b != 0 && b->mem[4].state >= 0) {
        ok = 1;
    }
    if (ok != 0) {
        k = b->mem[4].state;
    }
    return k;
}

static inline s32 Pick_80141390(void) {
    Party *a;
    s32 bit;
    s32 count;
    s32 sel;
    s32 k;
    s32 ok;
    Party *b;
    s32 i;
    s32 flag2;
    s32 flag;
    s32 ok2;

    flag = 0;
    a = &fn_80135598()->party;
    if (a != 0 && a->b11 >= 2) {
        count = 0;
        i = count;
        do {
            bit = 0;
            a = &fn_80135598()->party;
            if (a != 0) {
                ok = 0;
                if (i >= 0 && i < 0x16) {
                    ok = 1;
                }
                if (ok != 0) {
                    bit = (a->flags & (1 << i)) != 0;
                }
            }
            if (bit != 0) {
                count++;
            }
            i++;
        } while (i < 0x16);
        if (count > 0) {
            flag = 1;
        }
    }
    if (flag != 0) {
        sel = 7;
    } else {
        flag2 = 0;
        b = &fn_80135598()->party;
        ok2 = 0;
        if (b != 0 && b->mem[4].state >= 0) {
            ok2 = 1;
        }
        if (ok2 != 0) {
            if (Mode_80141390() == 3) {
                flag2 = 1;
            }
        }
        if (flag2 != 0) {
            sel = 6;
        } else {
            sel = 5;
        }
    }
    return sel;
}

s32 fn_80141390(MenuObj *o) {
    s32 res;
    s32 sel;
    s32 v;
    s32 bb;
    u32 f;

    res = 9;
    if (fn_8012C5DC() == 0) {
        v = o->b3;
        o->b3 = fn_80141314(v);
        if (o->b3 != v) {
            fn_8012C5FC(v - o->b3);
            fn_8012C614(3);
            o->bb = 1;
            SePlay(0xf, 1, 0xf);
        } else {
            sel = Pick_80141390();
            bb = o->bb;
            if (bb == 1) {
                if (o->b3 == 0 || sel == o->b3 || (lbl_80311A60[0]->x0 & 0xf) == 0) {
                    fn_8012C390(1);
                    o->bb = 0;
                }
            }
            f = lbl_80311A60[0]->x8;
            if (f & 0x200) {
                res = 8;
            } else if (f & 0x100) {
                res = o->b3;
            }
        }
    }
    return res;
}

s32 fn_80141314(s32 a)
{
    u32 f = lbl_8030A6D4[lbl_8034757C].xc;
    s32 d = 0;
    if (f & 8) d = -1;
    if (f & 4) d++;
    if (d == 0) {
        d = 0;
        if (f & 1) d = -1;
        if (f & 2) d++;
    }
    return fn_801410D4(a + d, d);
}

void fn_80140800(s32 mode)
{
    s32 cols;
    s32 m;
    s32 n;
    s8 *p;
    s8 buf[8];
    Big *w;

    w = fn_80135598();
    n = 0;
    p = fn_80135598()->order;
    if (p != NULL) {
        for (n = 0; n < 4; n++) {
            if (p[n] < 0) {
                break;
            }
        }
    }
    cols = n * 2;
    m = 0;
    p = fn_80135598()->order;
    if (p != NULL) {
        for (m = 0; m < 4; m++) {
            if (p[m] < 0) {
                break;
            }
        }
    }
    fn_80140750(cols, m);
    if (w != NULL) {
        fn_80136B10(buf, w);
        fn_801315A8(buf);
    }
    fn_80131598(mode);
    fn_801315EC(mode);
    fn_801315FC(1);
    fn_801316B4(0);
}

void fn_8014F770(Obj_8014F770 *p)
{
    s32 i;
    s32 state;
    s8 cur;
    s8 prev;
    s8 *q;

    p->x96 = 0;
    p->x98 = 0;
    p->x9a = 0;
    p->x9c = 0;
    p->x9e = 0;
    state = 0;
    prev = -1;
    q = p->seq;
    for (i = 0; i < 0x81; i++) {
        cur = *q;
        if (prev != cur) {
            switch (state) {
            case 0:
                if (cur != 0) {
                    p->x98 = i;
                    state++;
                }
                break;
            case 1:
                p->x9a = i;
                p->x96 = 1;
                state++;
                break;
            case 2:
                p->x9c = i;
                state++;
                break;
            case 3:
                p->x9e = i;
                p->x96 = 2;
                state++;
                break;
            }
        }
        prev = cur;
        q++;
    }
}

s32 fn_801493EC(Parent_801493EC *self) {
    Owner_801493EC *o = self->x24;
    Geff *g;
    int i;
    u32 id;

    if (o->x1d8 != NULL) {
        fn_801DBE1C("ERROR:sb_geff_scptTskInit twice call!! #%d (%s)", o->x17a, o->x1c8->name);
    }
    if (o->x1d8 == NULL) {
        o->x1d8 = fn_801E1A2C(1, 0x320);
        if (o->x1d8 == NULL) {
            return 0;
        }
    }
    g = o->x1d8;
    g->x4 = self;
    for (i = 0; i < 47; i++) {
        g->handlers[i] = lbl_802B4118[i].fn;
    }
    g->x31c = 0;
    g->x8 = 0;
    g->x90 = 0;
    g->x18 = -1;
    g->flags &= ~0x100;
    g->flags &= ~0x8;
    g->flags &= ~0x2;
    g->flags &= ~0x80;
    g->x178 = 0;
    g->x180 = 0;
    g->x17c = 0;
    if (o->x1c8 != NULL) {
        id = o->x17a;
        if ((id >= 3000 && id <= 3999) || (id >= 0xc3b4 && id <= 0xc737) ||
            fn_8025EF88("man", o->x1c8->name) == 0) {
            g->flags |= 0x80;
            g->x19c = 1.0f;
        }
    }
    g->x1e = -1;
    g->x6c = 0;
    g->x70 = 1;
    g->x74 = 0;
    if (o->x1c8->x20 != NULL) {
        fn_80227810(o->x1c8->x20);
    }
    if (o->x1b8 != NULL) {
        id = o->x1b8->x2a;
        if (id == 0xffff) {
            id = o->x17a;
        }
    } else {
        id = o->x17a;
    }
    g->x10 = fn_800DE554(id);
    g->x14 = fn_800DE5EC(id);
    g->x16 = fn_800DE598(id);
    g->xe = 0;
    if (fn_800E0C38(id) != 0) {
        g->flags |= 0x40;
    } else {
        g->flags &= ~0x40;
    }
    if (g->flags & 0x40) {
        s32 v = 0;
        if (g->x10 == 1) {
            v = 3;
        }
        g->xe = v;
    }
    g->flags |= 0x10;
    g->x84 = fn_80167244(fn_801C8930(o->xe4), 0xff0000);
    g->x88 = fn_80167244(fn_801C8930(o->xe4), 0xff00);
    g->x8c = fn_80167244(fn_801C8930(o->xe4), 0xff);
    g->xe0 = 0;
    g->x12c = 0;
    g->x94 = 0;
    g->x124 = 0;
    g->x170 = 0;
    g->xd8 = 0;
    g->xc = 0;
    fn_801E0FD4(g->x1a4, 0xbc);
    if (g->x84 != NULL && g->x84->x2c != NULL) {
        g->x48 = g->x84->x2c->x14;
        g->x4c = g->x84->x2c->x18;
        g->x50 = g->x84->x2c->x1c;
    }
    return 1;
}

static inline s32 Wrap(s32 x, s32 lo, s32 hi) {
    if (x < lo) {
        x = hi;
    }
    if (x > hi) {
        x = lo;
    }
    return x;
}

static inline s32 Clamp(s32 v, s32 lo, s32 hi) {
    v = v > lo ? v : lo;
    return v < hi ? v : hi;
}

s32 fn_8013DA50(s32 a, s32 b) {
    s32 d;
    s32 i;

    a = Wrap(a, 0, 1);
    d = Clamp(b, -1, 1);
    if (d != 0) {
        for (i = 0; i < 2; i++) {
            if (fn_8013E730(a) > 0) {
                break;
            }
            a = Wrap(a + d, 0, 1);
        }
    }
    return a;
}

extern void fn_8013160C(s8 a, s8 b, u8 v);

void fn_8013FB48(s32 y, s32 n)
{
    Cell c0;
    Cell c1;
    s32 code;
    s32 i;
    s32 idx;
    s32 j;
    s32 level;
    s32 v;

    for (i = -n; i < 0; i++) {
        if (lbl_80308E90[i + 4].kind == 4 && y == lbl_80308E90[i + 4].key) {
            idx = lbl_80308E90[i + 4].member;
            v = MemberStatus(idx);
            level = lbl_80308E90[i + 4].level;
            switch (v) {
            case 1:
                if (level >= 0) {
                    switch (level) {
                    case 0:
                        code = 0x16;
                        break;
                    case 1:
                        code = 0x17;
                        break;
                    case 2:
                        code = 0x18;
                        break;
                    default:
                        code = 0x16;
                        break;
                    }
                    c0.x = 0;
                    c0.y = y;
                    c0.a = 2;
                    c0.c = 2;
                    c0.b = code;
                    fn_80131658(&c0);
                    for (j = 1; j <= level; j++)
                        fn_8013160C(j, y, 2);
                }
                break;
            case 2:
                if (level >= 0) {
                    c1.x = level;
                    c1.y = y;
                    c1.a = 2;
                    c1.c = 2;
                    c1.b = 0xC;
                    fn_80131658(&c1);
                }
                break;
            }
        }
    }
}

typedef struct Pair { s16 kind; s16 val; } Pair;

void fn_8014093C(Pair *a, s32 n, s32 *kinds, s32 *vals) {
    s32 flag;
    if (a != 0 && kinds != 0 && vals != 0 && n > 0 && n <= 8) {
        Pair *p = a;
        s32 *k = kinds;
        s32 *v = vals;
        s32 i;
        for (i = 0; i < n; p++, k++, i++, v++) {
            if (p->kind == 2) {
                Party *c;
                flag = 0;
                c = &fn_80135598()->party;
                if (c != 0 && c->b11 >= 2) {
                    flag = 1;
                }
                if (flag) {
                    *k = 3;
                } else {
                    *k = 2;
                }
            } else {
                *k = p->kind;
            }
            *v = p->val;
        }
    }
}

extern u32 lbl_80310B3C[0x356];
extern s32 fn_801358A0(s32 idx, s32 b, s32 c, s32 d, s32 n);
extern s32 fn_80138930(void *buf, MenuItem *ent, s32 i);
extern void fn_8012C474(s8 v);

static inline MenuItem *SlotEnt(s32 a) {
    MenuItem *e = NULL;
    if (a >= 0 && a < 4) {
        e = &fn_80135598()->items[a];
    }
    return e;
}

static inline int SlotFree(s32 a) {
    int ok = 0;
    if ((lbl_80310B3C[0x3f] & 0x80000000) == 0 && a >= 0 && a < 4) {
        Big *p = fn_80135598();
        if (p->order[a] == 0) {
            ok = 1;
        }
    }
    return ok;
}

static inline s32 SlotFind(s32 a, s32 n) {
    s32 i;
    s32 res;

    for (i = 0; i >= 0 && i < n && fn_801358A0(i, a, 3, 0, n) == 0; i++) {
    }
    res = i > -1 ? i : -1;
    i = n;
    if (res < n) {
        i = res;
    }
    if (i < 0 || i >= n) {
        i = -1;
    }
    return i;
}

static inline int SlotUsable(s32 a) {
    int ok = 0;
    if (SlotFind(a, NameCount()) >= 0) {
        ok = 1;
    }
    return ok;
}

static inline int NonNeg(s32 b) {
    int ok = 0;
    if (b >= 0) {
        ok = 1;
    }
    return ok;
}

static inline int SlotHas(s32 a) {
    u8 buf[0x10];
    int has = 0;
    MenuItem *e = SlotEnt(a);
    s32 i;

    if (e != NULL) {
        for (i = 0; i < 6; i++) {
            if (fn_80138930(buf, e, i) > 0) {
                has = 1;
                break;
            }
        }
    }
    return has;
}

static inline s32 SlotVal(s32 a) {
    s32 v = 0;
    MenuItem *e = SlotEnt(a);

    if (e != NULL) {
        v = e->b0e;
    }
    return v;
}

void fn_8013F8F8(s32 a, s32 b) {
    s32 flags = 0xff;

    if (!SlotFree(a)) {
        flags &= ~1;
    }
    if (!SlotUsable(a)) {
        flags &= ~0xFE;
    } else {
        if (fn_80141078() == 0) {
            flags &= ~2;
        }
        if (!NonNeg(b)) {
            flags &= ~4;
        }
        if (!SlotHas(a) || SlotVal(a) < 1) {
            flags &= ~0x10;
        }
        if (fn_80140FBC(b) == 0) {
            flags &= ~0x40;
        }
    }
    fn_8012C474(flags);
}

extern s32 fn_801365D8(s32 a, s32 b, s32 c, s32 d, s32 e);
extern void fn_8012F478(s32 a);
extern void fn_8012ADE8(s32 a);
extern void fn_80130304(s32 a);

static inline s32 MenuFind(MenuObj *o)
{
    s32 i;
    s32 n;
    s32 t;
    s32 r;
    s32 cy = o->b2;
    n = NameCount();
    i = 0;
    while (i >= 0 && i < n && fn_801358A0(i, cy, 3, 0, n) == 0) {
        i++;
    }
    t = i > -1 ? i : -1;
    r = n;
    if (t < n) r = t;
    if (r < 0 || r >= n) r = -1;
    return r;
}

static inline void Commit(MenuObj *o)
{
    Cell cb;
    Cell ca;
    s32 n;
    s32 cy;
    s32 x;
    n = NameCount();
    if (o != NULL) {
        cy = o->b2;
        x = o->b8;
        ca.x = x; ca.y = cy; ca.a = 1; ca.c = -1; ca.b = -1;
        fn_80131658(&ca);
        cb.x = x; cb.y = cy; cb.a = 3; cb.c = -1; cb.b = -1;
        fn_80131658(&cb);
        fn_8013FB48(o->b2, n);
        if (o != NULL) o->ba = 0;
        fn_8012F478(1);
    }
}

s32 fn_8013D430(MenuObj *o)
{
    s32 ret;

    ret = 0;
    switch (o->state) {
    case 0:
        o->b8 = MenuFind(o);
        fn_801315FC(0);
        fn_8012ADE8(o->x16);
        o->state = 1;
    case 1:
        o->b8 = fn_801365D8(o->b8, o->b2, 3, 0, 2);
        if (lbl_80311A60[0]->x8 & 0x200) {
            fn_8012ADE8(o->x16);
            Commit(o);
            fn_80130304(-1);
            fn_801315FC(1);
            SePlay(0xf, 1, 7);
            ret = 1;
        } else if (lbl_80311A60[0]->x8 & 0x100) {
            fn_8013D400(o->b2, o->b8);
            fn_80130304(-1);
            fn_801315FC(1);
            SePlay(0xf, 1, 2);
            o->state = 2;
        }
        break;
    case 2:
        ret = 2;
        break;
    }
    return ret;
}

static inline void scale(Party *a)
{
    s32 k;
    a->x1c = a->x1c / 1.5;
    a->x20 = a->x20 / 1.5;
    a->x40 = a->x40 / 1.5;
    for (k = 0; k < 5; k++) {
        a->mem[k].x16 = a->mem[k].x16 / 1.5;
        if (a->mem[k].x1a != -1) a->mem[k].x1a = a->mem[k].x1a / 1.5;
    }
}

void fn_801447A0(void)
{
    Big *c;
    Party *t;
    u8 flags;

    c = fn_80135598();
    t = fn_8013558C();
    flags = lbl_8034727C->b29;
    c->x8 = c->x8 + c->xc;
    if (flags & 0x40) {
        c->x8 = c->x8 + c->xc;
    }
    if (c->x8 > c->x6) {
        c->x8 = c->x6;
    }
    if (lbl_8034727C->b29 & 1) {
        scale(lbl_8034727C->x20);
    }
    if (lbl_8034727C->b2a & 1) {
        scale(lbl_8034727C->x24);
    }
    fn_80144A7C(&c->party, 0);
    fn_80144A7C(t, 1);
    lbl_8034727C->b29 = 0;
    lbl_8034727C->b2a = 0;
}

extern s32 fn_8025ECC4(void);

s32 fn_80145E0C(Slot_8014359C *act, s32 a)
{
    s32 base;
    s32 rate;
    s32 bonus;
    Member *m;

    if (act->x1 == 0) {
        m = &lbl_8034727C->x20->mem[act->x5];
        rate = m->x1a;
        bonus = lbl_8034727C->x24->x40;
        base = lbl_8034727C->slot[a].x8;
    } else {
        rate = lbl_802D6934[act->x3].arm[act->x5].accuracy;
        bonus = lbl_8034727C->x20->x40;
        base = lbl_8034727C->slot[a].x6;
    }
    if (rate == -1) {
        act->x7 = 1;
        return 1;
    }
    base *= (100 - rate + bonus) / 2;
    if (fn_8025ECC4() % 100 > base / 10) {
        act->x7 = 1;
        return 1;
    }
    act->x7 = 0;
    return 0;
}

extern void (*lbl_802E5DB0[])(Slot_8014359C *, s32);

void fn_80146000(Slot_8014359C *o, s32 idx)
{
    s32 id;
    s32 x;
    s32 r;
    s32 thr;
    s16 *p;
    s16 v;
    s32 k;

    id = o->xa;
    switch (id) {
    case 0x23:
        id = 0x67;
        break;
    case 0x30:
        id = 0x75;
        break;
    }
    if (id >= 0x64 && id < 0x76) {
        switch (o->x0) {
        case 5:
            if (o->x1 == 0) {
                p = &lbl_8034727C->flag[0];
            } else {
                p = &lbl_8034727C->flag[1];
            }
            if (*p & 8) {
                o->x7 = 0;
                return;
            }
            break;
        case 4:
            if (o->x4 == 2 || o->x4 == 1) {
                v = lbl_8034727C->slot[idx].mode;
                if (o->x1 == 0) {
                    if (v == 1) {
                        x = lbl_803472A4->f34;
                    } else {
                        x = lbl_803472A4->f38;
                    }
                } else {
                    if (v == 2) {
                        x = lbl_803472A4->f3c;
                    } else {
                        x = lbl_803472A4->f40;
                    }
                }
                if (o->x4 == 2) {
                    if (fn_80145E0C(o, idx) != 0) {
                        r = rand() % 100;
                        if (o->x1 == 0) {
                            thr = lbl_8030B7F4.chr[o->x3].s40;
                        } else {
                            thr = lbl_802D6934[o->x3].agile;
                        }
                        if (r <= thr) {
                            o->x7 = 2;
                        }
                    }
                } else if (x & 1) {
                    o->x7 = 4;
                    return;
                } else {
                    if (fn_80145E0C(o, idx) != 0) {
                        r = rand() % 100;
                        if (o->x1 == 0) {
                            thr = lbl_8030B7F4.chr[o->x3].s40;
                        } else {
                            thr = lbl_802D6934[o->x3].agile;
                        }
                        if (r <= thr) {
                            o->x7 = 2;
                        }
                    }
                }
            }
            break;
        }
        k = id - 0x64;
        lbl_802E5DB0[k](o, idx);
    }
}

void fn_80147600(Slot_8014359C *c)
{
    Party *e;
    s16 *fl;

    if (c->x1 == 0) {
        fl = &lbl_8034727C->flag[0];
        e = lbl_8034727C->x20;
    } else {
        e = lbl_8034727C->x24;
        fl = &lbl_8034727C->flag[1];
    }
    if (*fl & 4) {
        c->x7 = 0;
        return;
    }
    switch (c->x0) {
    case 5:
        if (e->x54 > 0) {
            c->x7 = 0;
            return;
        }
        if (e->x52 > lbl_802C4BF0[c->x8].ship_turns) {
            c->x7 = 0;
            return;
        }
        if (e->x26 <= 0) {
            e->x26 = e->x24;
            e->x24 = e->x24 + e->x26;
        }
        c->x7 = 1;
        e->x52 = lbl_802C4BF0[c->x8].ship_turns;
        *fl |= 2;
        break;
    case 2:
    case 7:
        break;
    case 1:
        {
            int idx = c->x8 - 0x1E0;
            if (e->x54 > 0) {
                c->x7 = 0;
                return;
            }
            if (e->x52 > lbl_802D8A2C[idx].turns) {
                c->x7 = 0;
                return;
            }
            if (e->x26 <= 0) {
                e->x26 = e->x24;
                e->x24 = e->x24 + e->x26;
            }
            e->x52 = lbl_802D8A2C[idx].turns;
            *fl |= 2;
            c->x7 = 1;
        }
        break;
    }
}

extern const char lbl_802B3664[];
extern void fn_80155848(void);

void fn_801486CC(s32 v)
{
    s32 sum;

    fn_80155848();
    if (lbl_80308F98[v].items == NULL) {
        fn_801DBE1C(lbl_802B3664, v);
    }
    lbl_80346F80 = v;
    if (lbl_803472A8 == NULL) {
        lbl_803472BC = v;
        lbl_803472A8 = &lbl_80308F98[v];
        fn_801299A0();
        sum = lbl_803472D4 + lbl_803472C0;
        lbl_803472C0 = 0;
        lbl_803472D4 = sum;
        lbl_80310A1C[0x101] = 0;
        lbl_80310A1C[0x100] = 0;
        fn_80129BD4();
        lbl_80346F80 = -1;
        fn_8015635C();
    }
}

extern char lbl_802B37F8[];
extern char lbl_802B3838[];
extern void *fn_801E1584(void *p, u32 size);

void fn_80148BE8(s32 id)
{
    s32 i;
    if (lbl_803472C4 != id) {
        fn_801DBE1C(lbl_802B37F8, id);
    }
    lbl_80308F98[id].items = fn_801E1584(lbl_80308F98[id].items, lbl_80308F98[id].n * 0x58);
    for (i = 0; i < lbl_80308F98[id].n; i++) {
        if (lbl_80308F98[id].items[i].f0 == -1) {
            fn_801DBE1C(lbl_802B3838, id);
        }
    }
    lbl_803472C4 = -1;
}

extern s32 lbl_803472C8;

void fn_80148CAC(s32 id)
{
    const StrPool_8013D400* msg = &lbl_802B3578;
    s32 i;

    if (lbl_803472C4 != -1) {
        fn_801DBE1C(msg->startEnd, id);
    }
    if (id < 0 || id >= 32) {
        fn_801DBE1C(msg->startOver, id);
    }
    if (lbl_80308F98[id].items != NULL) {
        fn_801DBE1C(msg->startDup, id);
    }
    lbl_803472C4 = id;
    lbl_80308F98[id].items = fn_801E1A74(1, 0x160);
    lbl_80347298 = 4;
    lbl_80308F98[id].count = 0;
    for (i = 0; i < 4; i++) {
        lbl_80308F98[id].items[i].f0 = -1;
        lbl_80308F98[id].items[i].f48 = -1;
    }
    lbl_803472C8++;
}

extern s32 fn_800A35E0(Model_80148228 *p);

void fn_801497CC(Model_80148228 *obj)
{
    Path_80148228 *r;
    TblEnt *e;
    s32 i;
    Tbl *t;
    s32 n;
    u32 base;

    t = obj->node->tbl;
    if (t != NULL) {
        n = t->n;
        base = obj->b1dc;
        e = t->e;
        obj->f1fc = 0;
        for (i = 1; i < n - 1; e++, i += 2) {
            r = fn_801094C8(base + e->off);
            if (r != NULL && r->model->f26c == 1 && fn_800A35E0(r->model) == 1) {
                r->model->f1fb = 1;
                r->f19 = 1;
            }
        }
    }
}

extern void fn_801570BC(s32 id, Model_80148228* model);

void fn_8014836C(u16 ship, s32 path)
{
    const StrPool_8013D400* msg = &lbl_802B3578;
    Path_80148228* p;
    Path_80148228* s;

    p = fn_801094C8(path);
    if (p == NULL) {
        fn_801DBE1C(msg->path, ship);
    }
    if (ship != 0xfffe) {
        s = fn_801094C8(ship);
        if (s == NULL) {
            fn_801DBE1C(msg->ship, ship);
        }
        s->model->ctl->path = p;
        fn_801570BC(ship, p->model);
    } else {
        lbl_803472A0->cam->path = p;
        lbl_803472A0->cam->ship = NULL;
        if (lbl_803472A0->cam->path->model->motion == NULL) {
            fn_801DBE1C(msg->camMotion, path);
        }
    }
}

s16 fn_80147CC8(Arg* a) {
    s32 res;
    s16 x;
    s16 y;
    s16 n;
    s32 t;
    switch (a->mode) {
    case 1:
        res = 1;
        break;
    case 2:
        res = 2;
        break;
    case 0:
    default:
        if (lbl_8034727C->b29 & 8) {
            res = 1;
        } else {
            x = lbl_8034727C->x20->x24;
            y = lbl_8034727C->x24->x24;
            n = (x + y) / 4 + 1;
            t = y + fn_8025ECC4() % n;
            if (x + fn_8025ECC4() % n >= t) {
                res = 1;
            } else {
                res = 2;
            }
        }
        break;
    }
    return res;
}
void fn_80142F88(void) {
    Close(lbl_80346F74);
}

void fn_80142C78(void)
{
    Struct80306738 *h;
    fn_80130350(1);
    h = &lbl_80306738;
    if (h != 0) {
        if (h->task != 0) {
            TaskStop(h->task);
            h->task = 0;
        }
    }
}

/* Frees a node chain. Declared inline, so MWCC expands the self-call eight levels deep in
 * this (out-of-line, since its callers come first) copy. */
inline void fn_80148EDC(Node* n)
{
    if (n != NULL) {
        if (n->x4 != NULL) {
            fn_80148EDC(n->x4);
            n->x4 = NULL;
        }
        fn_80148E4C(n);
        fn_801E17E0(n);
    }
}

#ifdef NONMATCHING
#include "game/drawstate.h"
#include <math.h>
s32 fn_8013A538(s32 a, s32 b, s32 cur, s32 step, s32 d);
void fn_80131630(s8 a, s8 b, u8 v);
/* Config record of an effect emitter (Link.cfg). */
typedef struct Cfg_8014A1FC {
    u8 pad0[0x50];
    u32 mode;      /* 0x50 */
    s32 r, g, b;   /* 0x54 */
    u32 x60;       /* 0x60 */
    s32 x64;       /* 0x64 */
    u8 pad68[4];
    f32 x6c;       /* 0x6c */
    u8 pad70[0x7c - 0x70];
    s32 count;     /* 0x7c */
    u8 pad80[4];
    f32 x84, x88, x8c, x90, x94, x98, x9c;
    s32 xa0;
    u8 pada4[4];
    s32 xa8, xac, xb0;
    u8 padb4[4];
    u32 xb8;
    s32 xbc;
    u8 padc0[4];
    f32 xc4;
    u8 padc8[0xd0 - 0xc8];
    f32 xd0;
    u32 xd4;
    u32 xd8;
    u8 xdc[1];
} Cfg_8014A1FC;
typedef struct Link_8014A1FC {
    u8 pad[0x10];
    Cfg_8014A1FC* cfg;
} Link_8014A1FC;
typedef struct Slot18 {
    u8 pad0[0x14];
    f32 x14;
    u8 pad18[4];
} Slot18;
/* Per-emitter state, 0x108 bytes */
typedef struct Emit {
    u32 flags;     /* 0x00 */
    f32 x4, x8;
    s32 xc, x10;
    s16 x14, x16, x18, x1a;
    f32 x1c, x20, x24;
    s32 x28;
    void* x2c;
    f32 x30, x34;
    s32 x38;
    f32 x3c;
    u8 pad40[0x4a - 0x40];
    s16 x4a;
    s32 x4c;
    s32 x50;
    u8 pad54;
    u8 cr, cg, cb;
    s16 x58, x5a;
    s32 x5c;
    DrawState ds;  /* 0x60 */
    u8 pad88[0xac - 0x88];
    f32 xac, xb0;
    s32 xb4;
    s16 xb8, xba;
    s32 xbc;
    u8 padc0[0x100 - 0xc0];
    f32 x100;
} Emit;
typedef struct Fx {
    u8 pad0[0x20];
    f32 x20, x24, x28;
    s32 x2c;
    u8 pad30[0x50 - 0x30];
    f32 x50, x54;
    u8 pad58[0xe4 - 0x58];
    void* xe4;
    u8 padE8[0x100 - 0xe8];
    void* x100;
    u8 pad104[0x176 - 0x104];
    s16 x176;
    u8 pad178[0x1c8 - 0x178];
    Link_8014A1FC* link;
    u8 pad1cc[0x202 - 0x1cc];
    s16 x202;
    u8 pad204[0x22c - 0x204];
    u16 x22c;
    u8 pad22e[0x236 - 0x22e];
    u16 x236;
    u8 pad238[0x258 - 0x238];
    f32 x258;
    Slot18* x25c;
    u8 pad260[4];
    void* x264;
} Fx;
extern void fn_801E1784(void* p);
extern void fn_8009E910(DrawState* o, s32 mode, u8* out);
extern f32 fn_8009E4F8(u8 v);
extern f32 njSin(s32 a);
extern f32 njCos(s32 a);
extern s32 fn_800A1AE8(void* o, s32 idx);
extern s32 fn_800A10A8(void* base, s32 i, s32 n);
extern s32 fn_800BE430(Fx* o);
extern f32 fn_80291A5C(f32 x);
extern f32 fn_8009E3D0(s32 kind, void* model, f32* v);
extern void* fn_8009E8B0(s32 n);

static inline void DecayAll(Party* f) {
    s32 k;
    DECAY(f->x1c, f->x1e);
    DECAY(f->x20, f->x22);
    DECAY(f->x40, f->x42);
    for (k = 0; k < 5; k++) {
        DECAY(f->mem[k].x16, f->mem[k].x18);
        DECAY(f->mem[k].x1a, f->mem[k].x1c);
    }
}
#endif

#ifdef NONMATCHING
void fn_801477A8(Slot_8014359C *c) {
    Party *f;
    s16 *flags;
    const s8* t;

    if (c->x1 == 0) {
        f = lbl_8034727C->x24;
        flags = &lbl_8034727C->flag[1];
    } else {
        f = lbl_8034727C->x20;
        flags = &lbl_8034727C->flag[0];
    }
    switch (c->x0) {
    case 5:
        if (c->x7 == 0) {
            return;
        }
        if (c->x7 == 4) {
            return;
        }
        if (f->x54 > lbl_802C4BF0[c->x8].ship_turns) {
            c->x7 = 0;
            return;
        }
        if (f->x54 == 0) {
            DecayAll(f);
        }
        c->x7 = 1;
        f->x54 = lbl_802C4BF0[c->x8].ship_turns;
        *flags &= ~3;
        f->x52 = 0;
        f->x50 = 0;
        *flags |= 4;
        break;
    case 1:
        t = &lbl_802D8A2C[c->x8 - 0x1e0].turns;
        if (f->x54 > *t) {
            c->x7 = 0;
            return;
        }
        if (f->x54 == 0) {
            DecayAll(f);
        }
        c->x7 = 1;
        f->x54 = *t;
        *flags &= ~3;
        f->x52 = 0;
        f->x50 = 0;
        *flags |= 4;
        break;
    case 2:
        break;
    case 7:
        break;
    }
}
#endif

#ifdef NONMATCHING
inline s32 PartyCount(void) {
    s32 i = 0;
    s8* p = fn_80135598()->order;
    if (p != NULL) {
        for (i = 0; i < 4; i++) {
            if (p[i] < 0) {
                break;
            }
        }
    }
    return i;
}

inline s32 Valid(Party* p, s32 m) {
    s32 ok = 0;
    if (p != NULL && m >= 0 && m < 5 && p->mem[m].state >= 0) {
        ok = 1;
    }
    return ok;
}

inline s32 Status(s32 m) {
    s32 st;
    Party* p = &fn_80135598()->party;
    st = 4;
    if (Valid(p, m)) {
        st = p->mem[m].state;
    }
    return st;
}

inline s32 Span(s32 m) {
    Party* p = &fn_80135598()->party;
    s32 st = -1;
    if (Valid(p, m)) {
        st = p->mem[m].b1e;
    }
    return st;
}

inline s32 Range(s32 lo, s32 k, s32 n, s32 hi) {
    s32 r;
    s32 m;
    if (lo + 1 < 0 || k - 1 < 0 || n <= 0) {
        r = hi;
    } else {
        r = n - 1;
        if (k + lo < r) r = k + lo;
        m = hi > 0 ? hi : 0;
        if (m < r) r = m;
        if (r < lo + 1 || r >= n) r = hi;
    }
    return r;
}
#endif

#ifdef NONMATCHING
void fn_8013FF50(s32 who, s32 lo, s32 mem, s32 pts)
{
    s32 hi;
    s32 n;
    s32 k;
    s32 end;

    hi = PartyCount() * 2 - 1;
    switch (Status(who)) {
    case 1:
        hi = fn_8013A538(who, lo, hi, 0, pts);
        break;
    case 2:
        k = Span(who);
        n = PartyCount() * 2;
        hi = Range(lo, k, n, hi);
        break;
    }
    end = PartyCount() - 1;
    n = hi;
    if (hi > end) n = end;
    lo++;
    for (; lo <= n; lo++) {
        if (lbl_80308E90[lo + 4].kind != -1 && mem != lbl_80308E90[lo + 4].key) {
            fn_80131630(lo, mem, 0x11);
        }
    }
    for (; lo <= hi; lo++) {
        fn_80131630(lo, mem, 0x11);
    }

}
#endif

#ifdef NONMATCHING
void fn_8014A1FC(Fx* o, Emit* s)
{
    Cfg_8014A1FC* c = o->link->cfg;
    u8 col[4];
    f32 v;
    u8 r, g, b;
    s32 ang, deg;
    s32 n;
    s16 sh;
    f32 inv, a;

    if (o->x25c != NULL) {
        fn_801E1784(o->x25c);
        o->x25c = NULL;
    }
    DrawStateDefault2D(&s->ds);
    fn_8009E910(&s->ds, c->mode, col);
    s->cr = r = c->r;
    s->cg = g = c->g;
    s->cb = b = c->b;
    if (s->cr == 0 && s->cg == 0 && s->cb == 0) {
        s->x50 = 0;
    } else {
        s->x50 = 1;
    }
    o->x20 = fn_8009E4F8(r);
    o->x24 = fn_8009E4F8(g);
    o->x28 = fn_8009E4F8(b);
    if (o->x20 == -1.0f && o->x24 == -1.0f && o->x28 == -1.0f) {
        o->x20 = o->x24 = o->x28 = 0.0f;
    }
    if (c->x60 != 0) {
        o->x176 = 0;
    } else {
        o->x176 = 3;
    }
    s->x1a = c->x64;
    { f32 t = c->x6c; v = t == 0.0f ? 360.0f : t; }
    o->x22c = c->count;
    if (o->x22c != 0) {
        o->x25c = fn_801E1A2C(1, o->x22c * 0x18);
    } else {
        o->x25c = NULL;
    }
    if (o->x25c != NULL) {
        o->x25c->x14 = v;
        o->x258 = c->x84;
        s->xac = c->x88;
        s->x4 = c->x8c;
        s->xb0 = c->x90;
        s->x8 = c->x94;
        s->xb4 = 182.04445f * c->x98;
        s->xc = 182.04445f * c->x9c;
        s->x10 = 182.04445f * -(f32)c->xa0;
        s->x14 = c->xa8;
        s->x16 = c->xac;
        s->x18 = c->xb0;
        s->x1c = s->x14 == 0 ? 1.0f : 1.0f / s->x14;
        s->x20 = s->x18 == 0 ? 1.0f : 1.0f / s->x18;
        s->x24 = c->xc4;
        if (s->x24 == 0.0f) {
            s->x24 = 1.0f;
        }
        s->x38 = 182.04445f * c->xd0;
        if (c->xd4 != 0) {
            s->flags |= 1;
        }
        ang = 182.04445f * (f32)c->xa0;
        s->x30 = njCos(ang);
        s->x34 = njSin(ang);
        s->x2c = c->xdc;
        s->x28 = fn_800A1AE8(o, 0x36);
        s->xbc = 0;
        s->xb8 = 0;
        s->xba = fn_800A10A8(s->x2c, s->xbc, s->x28);
        if (s->x28 >= 1) {
            s->flags |= 4;
        }
        s->x5a = 0;
        s->x58 = 0;
        s->x5c = (s32)o->x100;
        s->x4a = 0;
        s->x3c = 0.003921569f * col[0];
        c = o->link->cfg;
        s->ds.fog = o->x2c;
        if (c->mode == 3) {
            s->x4c = 1;
        } else {
            s->x4c = 0;
        }
        if (fn_800BE430(o)) {
            s->flags |= 2;
        }
        if (s->flags & 2) {
            s->x100 = fn_80291A5C((f32)pow(o->x50, 2.0) + (f32)pow(o->x54, 2.0));
        } else {
            s->x100 = fn_8009E3D0(7, fn_801C8930(o->xe4), &o->x50);
        }
        sh = c->xbc;
        o->x202 = sh;
        inv = c->xb8;
        if ((s32)inv <= 0) {
            inv = 1.0f;
        }
        inv = 1.0f / inv;
        if (c->xd8 != 0) {
            if ((u32)s->x16 > c->xd8) {
                a = c->xd8;
            } else {
                a = s->x16;
            }
        } else {
            a = s->x16;
        }
        n = 1.0f + (f32)ceil(inv * ((f32)(o->x22c + 1) * (2.0f + ((f32)sh + a))));
        if (n < o->x22c) {
            n = o->x22c;
        }
        o->x264 = fn_8009E8B0(n);
        o->x236 = n;
    }
}
#endif
