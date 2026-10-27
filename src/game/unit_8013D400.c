#include "types.h"
#include "game/work_8030CEA0.h"
#include <dolphin/types.h>
extern void fn_80136A28(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
extern void fn_8013DA50(s32 a, s32 b);
typedef struct { u8 pad0[1]; s8 kind; } KindObj;
extern s32 lbl_80346F70;
extern s32 lbl_80346F6C;
extern s32 lbl_80346F68;
extern s32 lbl_80346F64;
extern s32 fn_801E4BBC(s32 n);
extern s32 fn_8025ECC4(void);
typedef struct {
    u8 pad0;
    s8 idx; /* 0x01 */
} IdxArg;
extern void fn_80100270();
extern void fn_801F7B04(s32 n);
extern char lbl_802E5E68[];
typedef struct {
    u8 pad0[8];
    s32 f8;
} Inner;
typedef struct {
    u8 pad0[0x24];
    Inner* inner; /* 0x24 */
} Outer_8013D400;
extern Outer_8013D400* lbl_803472A0;
extern f32 lbl_803472E0;
extern void* lbl_803472CC;
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
typedef struct { u8 pad0[2]; s8 count; } CountObj;
extern void fn_8013F6E0(void);
extern void SePlay(s32 id, s32 a, s32 b);
extern void fn_80097294(s32 a);
extern s32 lbl_80346F80;
extern s32 lbl_80347290;
extern void* lbl_80346F88;
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
extern u8 lbl_80306738[];
extern u8 lbl_80346F61;
extern u8 lbl_80346F60;
typedef struct Ent {
    u8 pad[0x2c];
    s16 x2c;
    u8 rest[0x10];
} Ent;
extern void fn_8014549C(s32 a, s32 b);
typedef struct Obj24 { u8 pad[0x24]; s16 x24; } Obj24;
typedef struct Obj7 { u8 pad[7]; u8 x7; } Obj7;
typedef struct Sub_80146FD4 { u8 pad[0x14]; s32 x14; s32 x18; } Sub_80146FD4;
typedef struct Req_UNIT0000 { s8 x0; s8 x1; } Req_UNIT0000;
typedef struct MapInfo { s32 map; s32 unk4; char room; } MapInfo;
extern void fn_800FF908(void);
extern void fn_801002D0(s32 a);
extern int fn_8025CB24(char* buf, const char* fmt, ...);
extern MapInfo lbl_80311AC0;
extern s32 lbl_80311AD4[11];
extern s32 lbl_803472E4;
extern char lbl_802B3578[];
extern u32 lbl_80346F74;
extern s32 lbl_8034728C;
extern s32 lbl_80347294;
extern void fn_80143060(s32* p);
extern u8 lbl_80310A1C[];
typedef struct Node {
    u8 pad0[4];
    struct Node* x4;
    struct Node* x8;
    struct Node* xc;
    struct Node* x10;
    struct Node* x14;
} Node;
extern void fn_80131500(s8 a);
extern void fn_80131658(s8 *p);
extern void fn_80140264(void);
extern void fn_8013FB48(s32 a, s32 b);
extern s32 fn_80140D04(s32 a);
extern u8 *fn_80135598(void);
extern u8 lbl_8030B4D4[];
extern Ent* lbl_8034727C;
extern s32 lbl_80347278;
extern void *fn_801E1A74(s32 a, s32 b);
extern u8 *fn_8013558C(void);
extern u8 lbl_80308F98[];
extern s32 lbl_803472BC;
extern u8 *lbl_803472A8;
extern s32 lbl_803472C0;
extern s32 lbl_803472D4;
extern s32 fn_801298E8(void);
extern void fn_801299A0(void);
extern void fn_80129BD4(void);
extern void fn_8015635C(void);
extern u8 lbl_80308E90[];
extern u32 fn_8013FCF0(s32 a, s32 key, s32 n);
typedef struct { u8 pad[0x2a]; s16 v; u8 pad2[4]; } E30;
typedef struct { u8 pad[0x24]; } E24;
typedef struct { s16 v; u8 pad[0x22]; } E24c;
typedef struct { u8 pad[0x1c]; s16 v; u8 pad2[6]; } E24b;
extern E30 lbl_802C4BF0[];
extern E24 lbl_802D8A2C[];
extern E24 lbl_802C7C34[];
extern E24b lbl_802D8E64[];
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
    u8 x0, x1, x2, x3;
    u8 x4, x5, x6, x7;
    s16 x8;
    s16 xa;
    u8 pad_c[4];
} Slot_8014359C;
typedef struct {
    u8 x0, x1, x2, x3;
    u8 pad4;
    s8 x5;
    s16 x6;
    u8 pad8;
    u8 x9;
    u8 padA[2];
    s16 xc;
    u8 padE[6];
    s16 x14;
} In;
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
    u8 pad[0x3C];
    f32 f3c;
    f32 f40;
} Cfg;
extern Cfg* lbl_803472A4;
extern s32 fn_80145E0C(Slot_8014359C* s, s32 a);
extern void fn_80145F50(Slot_8014359C* s, s32 a);
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
typedef struct {
    s16 h[0x84];
} Obj_80144A7C;
typedef struct {
    u8 pad0[0x48];
    s32 f48;
    s32 f4c;
    s32 f50;
    s32 f54;
} Item_80148790;
typedef struct {
    Item_80148790* items;
    u8 pad4[8];
} Tbl_80148790;
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
    u8 pad00[0x8];
    s16 x8;
} Base;
typedef struct {
    u8 pad00[0x14];
    s32 x14;
    u8 pad18[0x1C - 0x18];
    s16 x1c;
    u8 pad1e[2];
    s16 x20;
    u8 pad22[2];
    s16 x24;
    u8 pad26[0x76 - 0x26];
    s16 x76;
    u8 pad78[2];
    s16 x7a;
    u8 pad7c[0x98 - 0x7C];
    s16 x98;
    u8 pad9a[2];
    s16 x9c;
    u8 pad9e[0xBA - 0x9E];
    s16 xba;
    u8 padbc[2];
    s16 xbe;
    u8 padc0[0xDC - 0xC0];
    s16 xdc;
    u8 padde[2];
    s16 xe0;
} Ent_80147EAC;
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
    u8 pad0[0x34];
    f32 f34;
    f32 f38;
} Flt_80143FA4;
typedef struct {
    u8 b[0xc];
    s32 xc;
    u8 b2[6];
    u16 h[5];
} Struct80306738;
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
typedef struct {
    u8 pad[6];
    s16 x6;
    s16 x8;
} Info_80146DE4;
typedef struct Stat {
    u8 pad0[0x14];
    s32 max;
    s32 cur;
} Stat;
typedef struct Ent_80143200 {
    u8 pad0[0x20];
    Stat *stat;
} Ent_80143200;
typedef struct Node_80149070 Node_80149070;
void fn_80148EDC(Node_80149070 *n);
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
    u8 pad0[6];
    s16 s6;
    s16 s8;
} Cur;
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
extern s32 fn_8013D718(s32 kind, u8 *tbl, s32 id);
typedef struct {
    s8 kind;
    s8 key;
    s8 member;
    u8 pad3;
    s8 level;
} Rec5;
typedef struct {
    u8 pad0[0x14];
    s8 state;
    u8 pad15[0x22 - 0x15];
} Member;
typedef struct {
    u8 pad0[0x60];
    Member mem[5];
} Party;
typedef struct {
    u8 pad0[0x18];
    u8 flags;
    u8 pad19[0x24 - 0x19];
    s32 x24;
    s32 x28;
} Task;
typedef struct {
    u8 pad0[0xc];
    Task *task;
} Struct80306738_80143060;
extern void fn_8012AEB8(s32 a);
extern void fn_8012AED0(s32 a);
extern void fn_8012C648(s32 a);
extern void fn_8012E5C0(s32 a);
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
typedef struct {
    u8 pad[0x20];
    s32 id;
} Cfg_80148024;
extern s32 lbl_803472B4;
extern s32 lbl_802E5EA8[4];
extern s32 fn_8015C4A0(s32 a, s32 b);
extern s32 fn_8015C468(s32 a, s32 b);
typedef struct {
    u8 pad0[0x24];
    char name[1];
} Node_80148228;
typedef struct {
    u8 pad0[0xe8];
    void* motion;
    u8 padec[0x1c8 - 0xec];
    Node_80148228* node;
} Model_80148228;
typedef struct {
    u8 pad0[0x24];
    Model_80148228* model;
} Path_80148228;
typedef struct {
    Path_80148228* ship;
    Path_80148228* path;
} Cam_80148228;
typedef struct {
    u8 pad0[0x24];
    Cam_80148228* cam;
} Outer_80148228;
extern Path_80148228* fn_801094C8(s32 id);
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
} Info;
typedef struct {
    u8 pad0[0x10];
    Info *x10;
} Sub;
typedef struct Ctx_8014D398 {
    u8 pad0[0xe8];
    struct Ctx_8014D398 *xe8;
    u8 pade8[0x100 - 0xec];
    void *x100;
    u8 pad104[0x17a - 0x104];
    u16 h17a;
    u8 pad17c[0x18c - 0x17c];
    f32 f18c;
    f32 f190;
    u8 pad194[0x1c8 - 0x194];
    Sub *x1c8;
    u8 pad1cc[0x1e8 - 0x1cc];
    struct Task_8014D398 *x1e8;
    u8 pad1ec[0x23c - 0x1ec];
    Node_8014D398 *x23c;
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
    u8 pad0[0x11];
    s8 x11;
    u8 pad12[0x58 - 0x12];
    u32 x58;
    u8 pad5c[0xfc - 0x5c];
    s8 xfc;
} Sys_80141390;
typedef struct {
    u32 x0;
    u8 pad4[4];
    u32 x8;
} Pad_80141390;
typedef struct {
    u8 pad0[3];
    s8 b3;
    u8 pad4[7];
    u8 bb;
} Obj_80141390;
extern Pad_80141390 *lbl_80311A60[6];
extern s32 fn_8012C5DC(void);
extern s8 fn_80141314(s32 v);
extern void fn_8012C5FC(s8 v);
extern void fn_8012C614(s32 v);
extern void fn_8012C390(s32 v);

void fn_8013D400(s32 a, s32 b) {
    fn_80136A28(a, b, 3, -1, -1, -1);
}

s32 fn_8013D708(u8* p) {
    p[0x1] = 0;
    return 2;
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

s32 fn_8013F664(KindObj* o) {
    s32 r = 0;
    s32 k = o->kind;
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

void fn_801415C4(CountObj* o) {
    if (o != 0) {
        if (o->count > 0) {
            o->count--;
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
    return (fn_8025ECC4() & 1) ^ 1;
}

s32 fn_8014329C(void) {
    return fn_8025ECC4() % 5 == 0;
}

s32 fn_801432E4(void) {
    return fn_8025ECC4() % 10 == 0;
}

s32 fn_8014332C(void) {
    return fn_8025ECC4() % 100 == 0;
}

s32 fn_80143374(void) {
    return 1;
}

void fn_80144E5C(void) {
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
    lbl_803472A0->inner->f8 = 0;
}

void fn_80148124(void) {
    if (lbl_803472A0 != 0) {
        lbl_803472A0->inner->f8 = 1;
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

void fn_801490F4(void) {
    void* p = fn_801E1A74(0x1f4, 4);
    lbl_80346F88 = p;
    memset(p, 0, 0x7d0);
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
    u8* p = lbl_80306738;
    p[0] = 0;
    lbl_80346F61 = 0;
    p[0x1] = 0;
    p[0x2] = 0;
    p[0x3] = 0;
    p[0x4] = 0;
    p[0x5] = 0;
    p[0x6] = 0;
    p[0x7] = 0;
    p[0x8] = 0;
    p[0x9] = 0;
    p[0xa] = 0;
    p[0xb] = 0;
    p[0x10] = 0;
    p[0x11] = 0;
    p[0x12] = 0;
    p[0x13] = 0;
    p[0x14] = 0;
    p[0x15] = 0;
    *(u16*)(p + 0x16) = 0;
    *(u16*)(p + 0x18) = 0;
    *(u16*)(p + 0x1a) = 0;
    *(u16*)(p + 0x1c) = 0;
    *(u16*)(p + 0x1e) = 0;
    lbl_80346F60 = 0;
}

void fn_801457C4(s32 a, s32 b)
{
    if (b == 0) {
        if (lbl_8034727C[a].x2c == 1) {
            fn_8014549C(a, 0);
        } else {
            fn_8014549C(a, 1);
        }
    } else {
        if (lbl_8034727C[a].x2c == 1) {
            fn_8014549C(a, 1);
        } else {
            fn_8014549C(a, 0);
        }
    }
}

s32 fn_80145D84(Obj7* dst, Obj24* a, Obj24* b)
{
    s32 v = 0x50 - b->x24 + a->x24;
    s32 r = fn_8025ECC4() % 100;
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
    fn_8025CB24(lbl_802E5E68, lbl_802B3578, lbl_80311AC0.unk4, lbl_80311AC0.room);
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
    s8 s[5];

    fn_80131500((s8)rows);
    for (i = 0; i < rows; i++) {
        fill = -1;
        for (j = 0; j < cols; j++) {
            for (k = 0; k < 4; k++) {
                s[0] = j;
                s[1] = i;
                s[2] = k;
                s[4] = fill;
                s[3] = fill;
                fn_80131658(s);
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
    u8 *base;
    u8 *q;
    u8 *t;

    if (fn_80140D04(x) != 0) {
        over = 0;
        lim = 100;
        base = fn_80135598();
        active = 0;
        q = base + 0x238;
        if (q != NULL && (s8)q[0xfc] >= 0) {
            active = 1;
        }
        if (active) {
            t = base + 0x320;
            lim = 100;
            if (t != NULL) {
                lim = (s8)t[0x1f] + (s8)t[0x20];
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
    u8 *base;
    u8 *r;

    lbl_8034727C = (Ent*)fn_801E1A74(1, 0xab4);
    *(u8 *)((u8*)lbl_8034727C + 0x28) = lbl_8030B4D4[0x2d4];
    *(s16 *)((u8*)lbl_8034727C + 0x4) = 0;
    *(s32 *)((u8*)lbl_8034727C + 0x18) = 0;
    *(s32 *)((u8*)lbl_8034727C + 0x1c) = 0;
    *(s16 *)((u8*)lbl_8034727C + 0x6) = -1;
    *(s16 *)((u8*)lbl_8034727C + 0x8) = 0;
    *(s16 *)((u8*)lbl_8034727C + 0xa) = -1;
    *(s16 *)((u8*)lbl_8034727C + 0xc) = 0;
    *(s16 *)((u8*)lbl_8034727C + 0xe) = -1;
    *(s16 *)((u8*)lbl_8034727C + 0x10) = 0;
    *(s16 *)((u8*)lbl_8034727C + 0x12) = -1;
    *(s16 *)((u8*)lbl_8034727C + 0x14) = 0;
    base = fn_80135598();
    r = fn_8013558C();
    *(u8 **)((u8*)lbl_8034727C + 0x20) = base + 0x238;
    *(u8 **)((u8*)lbl_8034727C + 0x24) = r;
    lbl_80347278 = 0;
}

s32 fn_80145CA4(s32 p, s32 idx, s32 kind)
{
    s32 result = 0;
    u8 *base;
    s16 v;

    if (p == 0) {
        base = fn_80135598() + 0x238;
    } else {
        base = fn_8013558C() + idx * 0x10c;
    }
    switch (kind) {
    case 2:
        v = *(s16 *)(base + 0x52);
        if (v > 0) {
            result = 1;
        }
        break;
    case 3:
        v = *(s16 *)(base + 0x50);
        if (v > 0) {
            result = 1;
        }
        break;
    case 8:
        v = *(s16 *)(base + 0x54);
        if (v > 0) {
            result = 1;
        }
        break;
    case 12:
        v = *(s16 *)(base + 0x56);
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
    lbl_803472A8 = lbl_80308F98 + lbl_80346F80 * 12;
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
    s8 *p = (s8 *)fn_80135598();
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

    if (a >= 0 && a < n && (s8)lbl_80308E90[a * 5 + 0x14] != -1 &&
        key == (s8)lbl_80308E90[a * 5 + 0x15]) {
        flags = 1;
    } else {
        if (a >= 0 && a < n && (s8)lbl_80308E90[a * 5 + 0x14] != -1) {
            flags = 2;
        } else if (a >= n) {
            flags = 0x10;
        }
        flags |= fn_8013FCF0(a, key, n);
    }
    return flags;
}

void fn_801462D0(Req_801462D0 *o) {
    u8 *p = fn_80135598() + o->slot * 0x1c + 0x1c6;
    s32 d;

    switch (o->kind) {
    case 5:
        d = lbl_802C4BF0[o->id].v;
        break;
    case 1:
        d = ((E24c *)((u8 *)lbl_802D8A2C - 0x4364))[o->id].v;
        break;
    case 2:
        d = ((E24c *)((u8 *)lbl_802C7C34 - 0x21a4))[o->id].v;
        break;
    case 7:
        d = lbl_802D8E64[o->id].v;
        break;
    }
    p[0xe] += d;
    if ((s8)p[0xe] > (s8)p[0xd]) p[0xe] = p[0xd];
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

void fn_8014359C(In* in, s32 a, s32 b)
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
        mode = (s32)lbl_803472A4->f3c;
    else
        mode = (s32)lbl_803472A4->f40;
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
        o->f9 = (*(u8(*)[])&lbl_802C4BF0)[o->fc * 0x30 + 0x11];
        o->f14 = *(s16*)((*(u8(*)[])&lbl_802C4BF0) + o->fc * 0x30 + 0x26);
        break;
    default:
        o->f9 = 6;
        break;
    }
}

void fn_80144A7C(Obj_80144A7C* p, s32 which) {
    s16* fl;

    if (which == 0) {
        fl = (*(s16**)&lbl_8034727C);
    } else {
        fl = (s16*)((u8*)(*(s16**)&lbl_8034727C) + 2);
    }
    if (p->h[40] > 0) {
        p->h[40]--;
        if (p->h[40] == 0) {
            *fl &= ~1;
            p->h[14] = p->h[14] - p->h[15];
            p->h[15] = 0;
            p->h[59] = p->h[59] - p->h[60];
            p->h[60] = 0;
            p->h[76] = p->h[76] - p->h[77];
            p->h[77] = 0;
            p->h[93] = p->h[93] - p->h[94];
            p->h[94] = 0;
            p->h[110] = p->h[110] - p->h[111];
            p->h[111] = 0;
            p->h[127] = p->h[127] - p->h[128];
            p->h[128] = 0;
        }
    }
    if (p->h[41] > 0) {
        p->h[41]--;
        if (p->h[41] == 0) {
            *fl &= ~2;
            p->h[18] = p->h[18] - p->h[19];
            p->h[19] = 0;
        }
    }
    if (p->h[42] > 0) {
        p->h[42]--;
        if (p->h[42] == 0) {
            *fl &= ~4;
            p->h[14] = p->h[14] - p->h[15];
            p->h[15] = 0;
            p->h[16] = p->h[16] - p->h[17];
            p->h[17] = 0;
            p->h[32] = p->h[32] - p->h[33];
            p->h[33] = 0;
            p->h[59] = p->h[59] - p->h[60];
            p->h[60] = 0;
            p->h[61] = p->h[61] - p->h[62];
            p->h[62] = 0;
            p->h[76] = p->h[76] - p->h[77];
            p->h[77] = 0;
            p->h[78] = p->h[78] - p->h[79];
            p->h[79] = 0;
            p->h[93] = p->h[93] - p->h[94];
            p->h[94] = 0;
            p->h[95] = p->h[95] - p->h[96];
            p->h[96] = 0;
            p->h[110] = p->h[110] - p->h[111];
            p->h[111] = 0;
            p->h[112] = p->h[112] - p->h[113];
            p->h[113] = 0;
            p->h[127] = p->h[127] - p->h[128];
            p->h[128] = 0;
            p->h[129] = p->h[129] - p->h[130];
            p->h[130] = 0;
        }
    }
    if (p->h[43] > 0) {
        p->h[43]--;
        if (p->h[43] == 0) {
            *fl &= ~8;
        }
    }
}

void fn_80148790(s32 n, s32 mode, s32 kind, s32 a, s32 b) {
    char* fmt;
    s32 rem;
    Tbl_80148790* tbl;

    fmt = lbl_802B3578;
    if (lbl_803472C4 == -1) {
        fn_801DBE1C(fmt + 0x124);
    }
    rem = n % lbl_803472D0;
    if ((u32)n >= lbl_80347298) {
        fn_801DBE1C(fmt + 0x168);
    }
    tbl = (Tbl_80148790*)(lbl_80308F98 + 8);
    if (tbl[lbl_803472C4].items[n].f48 != -1) {
        fn_801DBE1C(fmt + 0x190, lbl_803472C4, n);
    }
    if (mode == 0) {
        if (kind < 0) {
            fn_801DBE1C(fmt + 0x1c4, lbl_803472C4, n);
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
    tbl[lbl_803472C4].items[n].f48 = mode;
    tbl[lbl_803472C4].items[n].f4c = kind;
    tbl[lbl_803472C4].items[n].f50 = a;
    tbl[lbl_803472C4].items[n].f54 = b;
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
    Ent_80147EAC* e;

    if (id == 0 || id == 0xFFFF) {
        Base* b = ((Base*)fn_80135598());
        e = (Ent_80147EAC*)((u8*)b + 0x238);
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
            fn_801DBE1C((void *)(lbl_802B3588), id);
        }
        e = (Ent_80147EAC*)(((u8*)fn_8013558C()) + found * 0x10C);
        lbl_8030CEA0.x160c = 0;
        lbl_8030CEA0.x1610 = fn_80148024(1, id);
    }
    lbl_8030CEA0.x15d8 = fn_80129D40(id)[2];
    lbl_8030CEA0.x15dc = e->x14;
    lbl_8030CEA0.x15e0 = e->x76;
    lbl_8030CEA0.x15e4 = e->x98;
    lbl_8030CEA0.x15e8 = e->xba;
    lbl_8030CEA0.x15ec = e->xdc;
    lbl_8030CEA0.x15f0 = e->x7a;
    lbl_8030CEA0.x15f4 = e->x9c;
    lbl_8030CEA0.x15f8 = e->xbe;
    lbl_8030CEA0.x15fc = e->xe0;
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
        v = (s32)(*(Flt_80143FA4**)&lbl_803472A4)->f34;
    } else {
        v = (s32)(*(Flt_80143FA4**)&lbl_803472A4)->f38;
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
    (*(Struct80306738*)&lbl_80306738).xc = 0;
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
    Info_80146DE4 *info = ((Info_80146DE4 *)fn_80135598());

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
        if ((*(Node_80149070 ***)&lbl_80346F88) != NULL) {
            if ((*(Node_80149070 ***)&lbl_80346F88)[i] != NULL) {
                fn_80148EDC((*(Node_80149070 ***)&lbl_80346F88)[i]);
            }
            (*(Node_80149070 ***)&lbl_80346F88)[i] = NULL;
        }
    }
}

void fn_80149070(void) {
    FreeSlots(500);
    fn_801E17E0((void *)((*(Node_80149070 ***)&lbl_80346F88)));
    (*(Node_80149070 ***)&lbl_80346F88) = NULL;
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
    Cur *c;

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
    c = ((Cur *)fn_80135598());
    out->s0 = cnt;
    out->s2 = b1->s2;
    if (out->s2 > c->s6 - c->s8) out->s2 = c->s6 - c->s8;
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
    u8 *tbl;
    s32 res;
    int ok;
    u8 *p;

    ok = 0;
    tbl = NULL;
    res = -1;

    switch (kind) {
    case 0:
        p = fn_80135598();
        if (p != NULL) {
            tbl = p + 0x14e;
        }
        break;
    case 1:
        p = fn_80135598();
        if (p != NULL) {
            tbl = p + 0xe;
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

    p = (Party *)(fn_80135598() + 0x238);
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
        if (((Rec5*)lbl_80308E90)[i + 4].kind == 4 && key == ((Rec5*)lbl_80308E90)[i + 4].key) {
            st = MemberStatus(((Rec5*)lbl_80308E90)[i + 4].member);
            level = ((Rec5*)lbl_80308E90)[i + 4].level;
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
    Struct80306738_80143060 *w;

    if (p != NULL) {
        *p = -1;
        (*(s32 **)&lbl_80346F74) = NULL;
        fn_8012AEB8(1);
        fn_8012AED0(1);
        fn_8012C648(1);
        fn_8012E5C0(1);
        fn_80130350(1);
        fn_801316B4(1);
        fn_8013312C(1);
        fn_8015A844();
        fn_8012C048(0x16);
        w = &(*(Struct80306738_80143060*)&lbl_80306738);
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
    if ((*(s32 **)&lbl_80346F74) != NULL) {
        Close((*(s32 **)&lbl_80346F74));
    }
    (*(s32 **)&lbl_80346F74) = p;
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
        if ((*(Cfg_80148024**)&lbl_803472A4) == NULL) {
            return 0;
        }
        if ((*(Cfg_80148024**)&lbl_803472A4)->id != id) {
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
    char* fmt = lbl_802B3578;

    if (path != 0x7fffffff) {
        if (((*(Outer_80148228**)&lbl_803472A0)->cam->path = fn_801094C8(path)) == NULL) {
            fn_801DBE1C(fmt + 0x34, path);
        }
        if (fn_8025EF88((*(Outer_80148228**)&lbl_803472A0)->cam->path->model->node->name, fmt + 0x50) != 0) {
            fn_801DBE1C(fmt + 0x5c, path, (*(Outer_80148228**)&lbl_803472A0)->cam->path->model->node->name);
        }
        if ((*(Outer_80148228**)&lbl_803472A0)->cam->path->model->motion == NULL) {
            fn_801DBE1C(fmt + 0x74, path);
        }
    } else {
        (*(Outer_80148228**)&lbl_803472A0)->cam->path = NULL;
    }
    if (ship != 0x7fffffff) {
        if (((*(Outer_80148228**)&lbl_803472A0)->cam->ship = fn_801094C8(ship)) != NULL) {
            (*(Outer_80148228**)&lbl_803472A0)->cam->ship = NULL;
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

void fn_8014D398(Task_8014D398 *t)
{
    Ctx_8014D398 *ctx;
    Node_8014D398 *p;
    s32 loc[16];
    void *r;
    Info *info;

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
        ctx->x1e8 = (Task_8014D398 *)r;
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
                    if (p->x8->f18c >= (f32)((W4 *)p->x8->xe8)->w4 - 1.0f) {
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
    Sys_80141390 *b = (Sys_80141390 *)(fn_80135598() + 0x238);
    s32 ok;
    k = 4;
    ok = 0;
    if (b != 0 && b->xfc >= 0) {
        ok = 1;
    }
    if (ok != 0) {
        k = b->xfc;
    }
    return k;
}

static inline s32 Pick_80141390(void) {
    Sys_80141390 *a;
    s32 bit;
    s32 count;
    s32 sel;
    s32 k;
    s32 ok;
    Sys_80141390 *b;
    s32 i;
    s32 flag2;
    s32 flag;
    s32 ok2;

    flag = 0;
    a = (Sys_80141390 *)(fn_80135598() + 0x238);
    if (a != 0 && a->x11 >= 2) {
        count = 0;
        i = count;
        do {
            bit = 0;
            a = (Sys_80141390 *)(fn_80135598() + 0x238);
            if (a != 0) {
                ok = 0;
                if (i >= 0 && i < 0x16) {
                    ok = 1;
                }
                if (ok != 0) {
                    bit = (a->x58 & (1 << i)) != 0;
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
        b = (Sys_80141390 *)(fn_80135598() + 0x238);
        ok2 = 0;
        if (b != 0 && b->xfc >= 0) {
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

s32 fn_80141390(Obj_80141390 *o) {
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
