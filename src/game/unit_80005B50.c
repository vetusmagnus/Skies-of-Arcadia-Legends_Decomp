#include "types.h"
#include "ninja.h"
#include "game/drawstate.h"
#include <dolphin/os.h>
#include "game/task.h"
#include "game/save_8030B7F4.h"
#include "game/stat_8030B4D4.h"
#include "game/gamedata.h"
#include <string.h>
#define PTR(p, off) (*(void**)((u8*)(p) + (off)))
extern void fn_8007E13C(void* a);
extern void fn_8007E118(void* a);
extern void fn_8007DFC0(void* a);
extern void fn_8007DEE0(void* a);
extern void fn_8001FE44(void* a);
s32 fn_800090F8(s32 packed, s16* p);
extern void* lbl_803475A8;
extern void* fn_802268E8(void* a, void* cb);
extern void* fn_801E1C7C(u32 size);
extern void fn_8000A3FC(void* p);
extern u32 lbl_803474E4[2];
extern void* lbl_80346AA0;
extern void fn_801DDCA8(void* p);
extern void fn_802275A4(void* a, s32 b);
extern void fn_801E17E0(void* p);
extern void* fn_801DB1A4(u32 size);
extern s32 fn_80227810(void* p);
extern void fn_801DDD74(void* p, s32 n);
typedef struct Vec3 {
    f32 x;
    f32 y;
    f32 z;
} Vec3;
extern f32 fn_80291A5C(f32 v);
typedef struct Sub2_BB28 {
    u8 pad[0x4C];
    void* x4c;
    u32 x50;
} Sub2_BB28;
typedef struct Rec_BB28 {
    void* x0;
    u8 pad4[4];
    u32* x8;
    u32 xc;
    u8 pad10[6];
    s16 x16;
    s16 x18;
    u8 pad1a[0x40 - 0x1A];
    u32 x40;
    u8 pad44[0x4C - 0x44];
} Rec_BB28;
typedef struct Work_BB28 {
    Rec_BB28 r;
    Sub2_BB28* x4c;
    u8 pad50[8];
} Work_BB28;
typedef struct Node_BB28 {
    u8 pad[0x24];
    Work_BB28* work;
} Node_BB28;
typedef struct Ent_BB28 {
    Rec_BB28* recs;
    struct { u8 pad[8]; void* x8; }* x4;
    Work_BB28** ptrs;
    u8 xc;              /* 0x0c record count */
    u8 padd[3];
    void* x10;
} Ent_BB28;
typedef struct {
    u16 x0;
    u8 pad2[6];
    u32 x8;
    u8 padc[0x18 - 0xc];
    s32 x18;
    f32 x1c;
    int cur;
    int pad24;
    Ent_BB28* tbl;
} Sys_80309E5C;
extern Sys_80309E5C lbl_80309E5C;
extern Task* lbl_80347394;
typedef struct ChrRec {
    u8 pad_0[8];
    s16 x8;             /* 0x08 */
    u8 pada[0x14 - 0xa];
    s32 x14;
    s32 x18;
    u32 bits;           /* 0x1c */
    u8 pad20[0x40 - 0x20];
    s16 stat[4];        /* 0x40 */
    u8 pad48[0x86 - 0x48];
    s16 x86;            /* 0x86 */
    u8 pad88[0x94 - 0x88];
    s16 x94;            /* 0x94 */
    s16 x96;            /* 0x96 */
    u8 pad98[0x9a - 0x98];
    s16 x9a;            /* 0x9a */
    s16 x9c;            /* 0x9c */
    u8 pad9e[0xae - 0x9e];
    s16 xae;            /* 0xae */
    u8 padb0[0xb4 - 0xb0];
    s16 xb4;            /* 0xb4 */
    s16 xb6;            /* 0xb6: weapon id */
    u8 padb8[0x100 - 0xb8];
    u8 x100;            /* 0x100 */
    u8 pad101[0x110 - 0x101];
    struct ChrAux* x110; /* 0x110 */
} ChrRec;
extern ChrRec* lbl_80309DE4[];
u32 fn_8000F718(s8 idx, s8 alt, u8* out);
typedef struct HNode {
    u8 pad0[0x2c];
    struct HNode* child;   /* 0x2c */
    struct HNode* sibling; /* 0x30 */
} HNode;
extern void fn_8000F6F8(HNode* n, u8 kind, s32 a, s32 b, s32 c);
typedef struct Entry16 {
    u8 pad[8];
    s8 mode;
    u8 b9;
    u8 pad2[6];
} Entry16;
extern Entry16 lbl_80309730[];
extern s32 lbl_8034733C;
typedef struct Pair {
    u32 a;
    u32 b;
} Pair;
extern Task* lbl_80309E24[];
extern void fn_8028AB48(void);
extern void fn_802A9B94(s32 a, s32 b, s32 c, void (*f)(void));
extern s32 lbl_803478A0;
extern s32* lbl_803478A4;
extern u8 *lbl_803478DC;
/* A linked condition record (fn_800085EC walks the list). */
typedef struct CondLink {
    s16 x0;
    s16 x2;
    s16 x4;                 /* 0x4: first table index (fn_8000832C) */
    s16 x6;                 /* 0x6: end index */
    struct CondLink* next;  /* 0x8 */
    struct CondLink* prev;  /* 0xc */
} CondLink;
typedef struct {
    u8 pad0[0xc];
    void* xc;           /* 0x0c */
    void* x10;
    s8 x14[9][9];       /* 0x14 party grid */
    u8 pad65[0x68 - 0x65];
    void* x68;
    u32 x6c;
    u8 pad70[0xec - 0x70];
    f32 xec;            /* 0xec speed scale */
    s16 xf0;
    u8 padf2[0x180 - 0xf2];
    void* x180;         /* 0x180 */
    void* x184;         /* 0x184 */
    u8 pad188[0x1c4 - 0x188];
    s32 x1c4;
} GS;
extern GS lbl_8030A10C;
typedef struct ChrMot {
    u8 pad0[4];
    u32 x4;
} ChrMot;
/* One motion entry of a character (0x18 bytes). */
typedef struct ChrAnim {
    s16 x0;
    s16 x2;             /* 3 ends the table */
    s16 x4;
    s16 x6;
    u32 flags;
    s16 xc;
    s16 xe;
    f32 x10;
    f32 x14;
} ChrAnim;
/* A character's draw parameters (fn_80018B80 turns them into a DrawState). */
typedef struct ChrDraw {
    f32 a;              /* 0x00 colour */
    f32 r;
    f32 g;
    f32 b;
    u8 pad10[8];
    s32 blend_src;      /* 0x18 */
    s32 blend_dst;      /* 0x1c */
    u8 pad20[8];
    s32 x28;            /* 0x28: not 1 clears control3d 0x40 */
    s32 fog;            /* 0x2c */
    s32 x30;            /* 0x30: nonzero calls fn_80060950 */
} ChrDraw;
/* One 0x34-byte joint of a character's skeleton (ChrInfo 0x154). */
typedef struct Joint { u8 pad[8]; u8 data[0x34 - 8]; } Joint;
typedef struct ChrInfo {
    s8 id;              /* 0x00 */
    u8 pad1;
    s16 x2;             /* 0x02 kind */
    s8 target;          /* 0x04 */
    u8 pad5;
    s16 x6;             /* 0x06 */
    s16 x8;             /* 0x08 */
    u8 padA[8];
    s16 state;          /* 0x12 */
    s16 x14;            /* 0x14 */
    s16 x16;            /* 0x16 */
    u8 pad_18[8];
    s16 x20;            /* 0x20 */
    u8 pad22[6];
    s8 x28[10];         /* 0x28 recent ids, -1 = free */
    u8 pad32[0x44 - 0x32];
    u32 x44;            /* 0x44 status bits */
    s8 x48;             /* 0x48 */
    u8 pad_49;
    s16 x4a;            /* 0x4a */
    u8 pad4c[4];
    u32 x50;            /* 0x50 draw flags */
    u8 pad54[0x8];
    ChrMot* x5c;        /* 0x5c */
    void* x60;          /* 0x60 */
    s16 x64;            /* 0x64 */
    u8 pad66[2];
    f32 x68;            /* 0x68 */
    f32 x6c;            /* 0x6c frame step */
    s32 x70;            /* 0x70 */
    u8 x74[0x10];       /* 0x74 */
    u8 x84[0x10];       /* 0x84 */
    u8 pad94[0xdc - 0x94];
    ChrAnim* anims;     /* 0xdc */
    s32 xe0;            /* 0xe0 */
    s16 xe4;            /* 0xe4 */
    s16 xe6;            /* 0xe6 */
    s16 xe8;            /* 0xe8 */
    s16 xea;            /* 0xea */
    u32 xec;            /* 0xec */
    u32 xf0;            /* 0xf0 */
    u32 xf4;            /* 0xf4 */
    NJS_POINT3 pos;     /* 0xf8 */
    f32 x104[3];        /* 0x104 */
    NJS_POINT3 x110;    /* 0x110 target */
    f32 x11c;           /* 0x11c turn from */
    f32 x120;           /* 0x120 turn to */
    f32 x124;           /* 0x124 turn step */
    f32 x128;           /* 0x128 turn speed */
    f32 x12c;
    f32 x130;
    s32 x134;           /* 0x134 */
    s16 x138;           /* 0x138 */
    u8 pad13a[2];
    NJS_POINT3 x13c;    /* 0x13c saved pos */
    Angle x148[3];      /* 0x148 saved angles */
    Joint* x154;        /* 0x154 joints */
    u8 pad158[0x15c - 0x158];
    f32 x15c;           /* 0x15c */
    f32 x160;           /* 0x160 alpha */
    ChrDraw draw;       /* 0x164 */
    u8 pad198[0x1dc - 0x198];
    void* x1dc;         /* 0x1dc */
    u8 pad1e0[0x1ec - 0x1e0];
    u32 x1ec;           /* 0x1ec */
    u8 pad1f0[4];
    NJS_TEXLIST* x1f4;  /* 0x1f4 */
    s16 x1f8;           /* 0x1f8 timer */
    u8 pad1fa[2];
    void* x1fc;         /* 0x1fc matrix */
    u8 pad200[0x204 - 0x200];
    s16 x204;           /* 0x204 */
    u8 pad206[0x20c - 0x206];
    s16 x20c;           /* 0x20c */
    s16 x20e;           /* 0x20e */
    u8 pad210[0x294 - 0x210];
    s16 x294;           /* 0x294 texture variant */
    s8 x296;            /* 0x296 draw kind */
    u8 pad297;
    void* x298;         /* 0x298 voice data */
} ChrInfo;
/* Event-target object referenced by an id record (x0 type, x4 id, x10 result). */
typedef struct Key {
    s16 x0;
    s16 x2;
    s16 x4;
    u8 pad6[0x10 - 6];
    s16 x10;
} Key;
/* 0x10-byte id record; lists end at a negative x0. */
typedef struct Ent_80008800 {
    s16 x0;
    s16 x2;
    u8 pad4[8];
    Key* xc;
} Ent_80008800;
s32 fn_8000832C(Task* obj, Ent_80008800* tbl, CondLink* range);
s16 fn_800086BC(Task* t, s16 a, s16 b, Ent_80008800* tbl, CondLink* e, u8 f);
typedef struct Obj_80017B18 {
    u8 pad0[0xc];
    char xc[0x24];      /* 0x0c name */
    Ent_80008800 *x30;
    u8 pad34[0x40 - 0x34];
    f32 x40;            /* 0x40 cached height (fn_800177C0) */
} Obj_80017B18;
typedef struct ChrWork {
    void* x0;           /* 0x00 model */
    u8 pad4[4];
    NJS_TEXLIST* x8;    /* 0x08 */
    u8 padc[4];
    Obj_80017B18 *x10; /* 0x10 */
    s16 x14;            /* 0x14 */
    u8 pad16[0x1c - 0x16];
    NJS_POINT3 pos;     /* 0x1c */
    Angle rx, ry, rz;   /* 0x28 */
    NJS_POINT3 scl;     /* 0x34 */
    u8 pad40[4];
    u8 x44;             /* 0x44 */
    u8 pad45[0x48 - 0x45];
    NJS_TEXLIST* x48;   /* 0x48 */
    ChrInfo *st; /* 0x4c */
} ChrWork;
typedef struct Key7 {
    u16 x0;
    u8 x2;
    u8 x3;
    u8 x4;
    u8 x5;
    u8 x6;
} Key7;
typedef struct Key16 {
    u32 frame;
    f32 v[3];
} Key16;
typedef struct Track {
    Key16* keys;
    u32 pad4;
    u32 count;
} Track;
typedef struct AnimHdr {
    Track* track;
    u32 length;
} AnimHdr;
typedef struct AnimPlay {
    AnimHdr* anim;
    u8 pad4[4];
    u32 end;
    u32 idx;
    u8 pad10[4];
    f32 speed;
    f32 time;
    f32 out[3];
} AnimPlay;
int fn_8003DE8C(s16 type, s16 id, s16 wtype, s16 wid);
typedef struct WorkRec {
    s16 x0;
    s16 x2;
} WorkRec;
typedef struct TkRec {
    u8 pad_0[0x24];
    WorkRec *work;
} TkRec;
extern TkRec *lbl_80309700[12];
/* The character record a character task's work points at (0x4c). */
typedef struct Unit_8001D288 {
    s8 id;              /* 0x000 */
    u8 pad1[0xEC - 0x1];
    u32 xec;            /* 0x0EC: 0x200000 = large */
    u8 padf0[0x15C - 0xF0];
    f32 x15c;           /* 0x15C: ground height */
} Unit_8001D288;
/* A character task's work: position at 0x1c, rotation at 0x28. */
typedef struct Wk_8001D288 {
    u8 pad0[0x1C];
    f32 x;              /* 0x1C */
    f32 y;              /* 0x20 */
    f32 z;              /* 0x24 */
    f32 rot[3];         /* 0x28 */
    u8 pad34[0x4C - 0x34];
    Unit_8001D288* w;   /* 0x4C */
} Wk_8001D288;
extern void fn_80061C80(void*, f32, f32, f32, int);
extern void fn_800615B4(void* p, void* v, void* b);

inline ChrWork* ChrW(Task* t)
{
    return t->work;
}
typedef struct {
    s16 id;
    s16 pad;
    void *ptr;
} Ent_80009860;
extern u8 *lbl_80346AA4;
typedef void (*TaskFn)(void*);
extern TaskFn lbl_802DAFA8[];
/* The 0x70-byte objects lbl_80309EC8 keeps at 0x40/0x44 (fn_80014AB8); 0x20000000 in flags
 * releases one. */
/* The 0x38-byte block at SysObj 0x6c. */
typedef struct SysSub {
    u8 pad0[2];
    s16 x2;             /* 0x02 */
    u8 pad4[0x38 - 4];
} SysSub;
typedef struct SysObj {
    u8 pad0[0x5a];
    s16 x5a;            /* 0x5a */
    s16 x5c;            /* 0x5c */
    u8 pad5e[0x68 - 0x5e];
    u32 flags;          /* 0x68 */
    SysSub x6c;         /* 0x6c: cleared as a whole by fn_80061F58 */
} SysObj;
/* lbl_80309EC8 0x88..0x204, cleared as one block by fn_80014AB8. */
typedef struct SysMove {
    u8 pad0[0xC0 - 0x88];
    f32 xc0[3];
    u8 padcc[0x110 - 0xCC];
    f32 x110;
    u8 pad114[0x160 - 0x114];
    f32 x160;
    u8 pad164[0x19A - 0x164];
    s16 x19a;
    u8 pad19c[0x204 - 0x19C];
} SysMove;
/* lbl_80309EC8: the 0x244-byte battle/system block (memset in battle.c). */
typedef struct Sys_80309EC8 {
    u8 pad_0[0x40];
    SysObj* x40;
    SysObj* x44;
    u32 x48;
    NJS_POINT3 x4c;     /* 0x4c eye */
    NJS_POINT3 x58;     /* 0x58 target */
    s32 x64[3];         /* 0x64 angles */
    f32 va[3];
    f32 vb[3];
    SysMove mv;         /* 0x88 */
    s8 a[10];
    u8 pad20e[2];
    u32 w[10];
    s8 b[10];
    u8 pad242[2];
} Sys_80309EC8;
extern Sys_80309EC8 lbl_80309EC8;
extern void fn_800614FC(void *p, void *v);
extern void fn_80071CF0(void *p, void *v);
extern void *fn_80021658(s8 idx);
extern s16 lbl_80347378;
extern u32 lbl_803472F4;
extern void fn_80015580(void);
typedef struct Unit { u8 pad[0xEC]; u32 xec; u32 xf0; u32 xf4; } Unit;
typedef struct Wk_8001C31C { u8 pad[0x4C]; Unit* w; } Wk_8001C31C;
typedef struct Tk_8001C31C { u8 pad[0x24]; Wk_8001C31C* work; } Tk_8001C31C;
extern void fn_8001C6CC(void* a, void* b, void* c, void* d);
extern void fn_8006C860(const char* s, void* p);
typedef struct Wk_8001D1D8 { u8 pad[0x1C]; } Wk_8001D1D8;
typedef struct Tk_8001D1D8 { u8 pad[0x24]; Wk_8001D1D8* work; } Tk_8001D1D8;
typedef struct E0D8Anim {
    u16 cur;
    u16 end;
    s16 sub;
    u8 pad6[2];
    u32 val;
    u8 mat[0x14];
    void *p20;
    u8 pad24[8];
    void *p2c;
} E0D8Anim;
typedef struct E0D8Obj {
    u8 pad0[0x18];
    u8 flags;
    u8 state;
    u8 pad1A[10];
    struct { void *p0; u8 pad4[0x48]; E0D8Anim *anim; } *inner;
} E0D8Obj;
extern void fn_80230634(void *, void *);
extern void fn_80230280(void *, void *);
extern s32 fn_800179E4(s16);
extern void fn_8000B320(f32, void *, void *);
extern void fn_801E17E0(void *);
typedef struct { s16 id; } Wk;
typedef struct { u8 pad[0x24]; Wk* work; } Tk;
/* lbl_803097F0 (.bss, 0xD8 bytes): s16 header (x0 read as a state id in battle.c),
   then 12 per-character 16-byte entries from 0x18. */
typedef struct { f32 x0; f32 x4; f32 x8; f32 xc; } Ent;
typedef struct { s16 x0; u8 pad[0x16]; Ent ent[12]; } Tbl;
extern Tbl lbl_803097F0;
/* lbl_80309730: 12 rows of 16 bytes, one per character slot; +0x8 is the slot mode
 * (0 = unused, see fn_80010538). */
typedef struct Entry16B {
    u8 pad[8];
    s8 mode;
    u8 pad2[7];
} Entry16B;
typedef struct Work {
    s8 idx; /* 0x00: slot index */
} Work;
typedef struct Inner {
    u8 pad[0x4c];
    Work *work; /* 0x4C */
} Inner;
typedef struct Obj {
    u8 pad[0x24];
    Inner *inner; /* 0x24 */
} Obj;
typedef struct {
    f32 x0;
    u8 pad4[8];
    f32 xc;
    f32 x10;
    f32 x14;
    f32 x18;
    f32 x1c;
    u8 pad20[0x40 - 0x20];
    s32 x40;
    s32 x44;
    f32 x48;
    void* x4c;
    u32 x50;
} U;
typedef struct {
    void* x0;
    u8 pad4[4];
    void* x8;
    struct { u8 pad[4]; u32 x4; }* xc;
    struct { u8 pad[8]; void* x8; }* x10;
    u8 pad14[2];
    s16 x16;
    s16 x18;
    u8 pad1a[0x1c - 0x1a];
    f32 tx;
    f32 ty;
    f32 tz;
    s32 rx;
    s32 ry;
    s32 rz;
    f32 sx;
    f32 sy;
    f32 sz;
    u8 pad40[4];
    u8 x44;
    u8 pad45[0x4c - 0x45];
    U* u;
} W;
typedef struct {
    u8 pad0[0x19];
    u8 state;
    u8 pad1a[0x24 - 0x1a];
    W* work;
} Tk_8000E664;
extern int fn_8000CCBC(Tk_8000E664*, int);
extern void fn_8000B77C(void*, void*);
extern void fn_80060950(void*);
extern int fn_80035908(void);
extern void fn_80035910(int);
extern void fn_8000F0BC(void);
extern void fn_8000B6F0(W*);
extern void fn_8000B5F4(W*, f32);
extern void fn_800D2048(void);
typedef struct {
    u8 pad0[0x19];
    u8 state;
    u8 pad1a[0x24 - 0x1a];
    W* work;
} Tk_8000EDE4;
typedef struct {
    s8 id;
    u8 pad1[0x44 - 1];
    u32 x44;
    u8 pad48[0x50 - 0x48];
    u32 x50;
    u8 pad54[0x1dc - 0x54];
    void* x1dc;
} Unit_80016580;
typedef struct {
    u8 pad[0x4c];
    Unit_80016580* w;
} UW_80016580;
typedef struct Tk_80016580 {
    u8 pad0[0x18];
    u8 flags;
    u8 state;
    u8 pad1a[0x24 - 0x1a];
    union {
        void* v;
        UW_80016580* uw;
    } work;
} Tk_80016580;
typedef struct {
    s16 x0;
    u8 pad2[2];
    u32 x4;
} W_80016580;
typedef struct {
    u8 pad[0x1c];
    u32 x1c;
} Chr;
typedef struct {
    u8 pad[0x44];
    u32 x44;
} U44;
extern int fn_80016A18(s8);
void fn_80015138(u8 flag);
extern void fn_80032B4C(void);
extern int fn_800168D8(int, void*, u8);
typedef struct {
    u8 pad0[0x5c];
    void* x5c;
    void* x60;
    u8 pad64[0x74 - 0x64];
    u8 x74[0x10];
    u8 x84[4];
    u8 pad88[0x154 - 0x88];
    void* x154;
    u8 pad158[0x264 - 0x158];
    f32 x264;
    f32 x268;
    f32 x26c;
    f32 x270;
    f32 x274;
    f32 x278;
    f32 x27c;
    s32 x280;
    s32 x284;
    s32 x288;
    u8 x28c;
} U_80018868;
typedef struct {
    void* x0;
    u8 pad4[0x4c - 4];
    U_80018868* u;
} W_80018868;
typedef struct {
    u8 pad[0x24];
    W_80018868* work;
} Tk_80018868;
extern u8 lbl_80346ABC;
extern u8 lbl_80346ABD;
extern void fn_8007E678(void*, void*);
extern void fn_8029D008(s32);
extern void njTranslate(void*, f32, f32, f32);
extern void njRotateX(void*, s32);
extern void njRotateY(void*, s32);
extern void njRotateZ(void*, s32);
extern void njScale(void*, f32, f32, f32);
extern void fn_80035468(void*, void*, void*, int, f32);
extern void fn_80035228(void*, void*, int, f32);
extern void fn_800353F4(void*, void*, void*, f32, u8);
extern void fn_80035380(void*, void*, f32, u8);
extern void fn_8003529C(void*, void*, f32, u8);
typedef struct {
    s8 id;
    u8 pad1[5];
    s16 x6;
    s16 x8;
    u8 padA[0x10 - 0xA];
    s16 x10;
    u8 pad12[2];
    s16 x14;
    s16 x16;
    u8 pad18[0xec - 0x18];
    u32 xec;
    u8 padf0[0x20c - 0xf0];
    s16 x20c;
    s16 x20e;
} Unit_8001CED0;
typedef struct {
    u8 pad[0x3c];
    u32 x3c;
    u8 pad40[0x4c - 0x40];
    Unit_8001CED0* w;
} Wk_8001CED0;
typedef struct Tk_8001CED0 {
    u8 pad[0x24];
    Wk_8001CED0* work;
} Tk_8001CED0;
extern u32 fn_800153E0(s32, s16);
extern s16 fn_800760EC(void*, s16, s16);
extern s8 fn_8002EEFC(Tk_8001CED0*, u32*);
extern s8 fn_80030AE8(u32, Unit_8001CED0*);
extern s16 fn_80009030(Ent_80008800* list, s16 p1, s16 p2, s16 c, s16 d);
extern void fn_800312F0(Tk_8001CED0*, s16, s16, s8);
extern void fn_80031254(Tk_8001CED0*);
/* The camera object fn_8006B6F4 returns; its position is at 0x3c. */
typedef struct CamObj {
    u8 pad0[0x3C];
    f32 pos[3];         /* 0x3c */
} CamObj;
typedef struct {
    u8 pad0[4];
    CamObj* cam;        /* 0x04 */
    s32 mode;
    f32 b1[3];
    s16 steps;          /* 0x18 */
    u8 pad1a[2];
    f32 vel[3];
    f32 b2[3];
    s16 state;
} Bounce;
typedef struct {
    struct {
        u8 pad0[8];
        f32 v[3];
        u8 pad14[4];
    } e[4];
} Q4;
typedef struct Nd {
    Q4* x0;
    struct Nd* x4;
    f32 v[3];
    u8 pad14[0x2c - 0x14];
    struct Nd* x2c;
} Nd;
typedef struct {
    Nd* x0;
    u8 pad4[0x1c - 4];
    f32 x1c[3];
    u8 pad28[4];
    s32 x2c;
} N0;
typedef struct {
    N0* x0;
    s16 x4;
} U_8000D8FC;
typedef struct {
    u8 pad[0x4C];
    U_8000D8FC* w;
} Wk_8000D8FC;
typedef struct {
    u8 pad0[0x18];
    u8 flags;
    u8 state;
    u8 pad1a[0x24 - 0x1a];
    Wk_8000D8FC* work;
} Tk_8000D8FC;
extern void fn_800120D0(s32*);
typedef struct {
    u8 pad0[0x48];
    u32 x48;
    u8 pad4c[0x204 - 0x4c];
    s8 a[10];
    u8 pad20e[2];
    u32 w[10];
    s8 b[10];
    u8 pad242[2];
} Tbl_80013D58;
extern s8 lbl_80347334;
extern int fn_80078610(u8);
extern void fn_80290EA8(int);
extern void fn_80290E98(u32);
/* The camera task's state block (its work's x6c). */
typedef struct CamState {
    s8 mode;            /* 0x00 camera mode */
    s8 prev;            /* 0x01 previous mode */
    s16 x2;             /* 0x02 current character */
    s16 x4;             /* 0x04 second character */
    u8 pad6[2];
    f32 x8;
    f32 xc;
    u8 pad10[0x2c - 0x10];
    s16 x2c;
    u8 x2e;
    s8 x2f;             /* 0x2f camera kind */
    s16 state;          /* 0x30 */
    u8 pad32[2];
    u32 x34;
} CamState;
/* The camera task's work: eye at 0x20, angles at 0x2c, target at 0x38. */
typedef struct CamWork {
    u8 pad0[0x20];
    f32 x20[3];
    f32 x2c[3];
    f32 x38[3];
    u8 pad44[0x68 - 0x44];
    u32 x68;            /* 0x68 flags */
    CamState* u;        /* 0x6c */
} CamWork;
extern int fn_8006D1C4(void);
f32 fn_800114AC(f32* out, f32* w, f32* h, s8 flag);
extern void fn_800608C8(void*);
extern void fn_80061C80(void*, f32, f32, f32, int);
extern void fn_80071F84(void*, void*, void*);
void fn_80014AB8(u8 kind, SysObj* o);
typedef struct {
    f32 x, y, z;
} Vec;
extern int fn_8001EE24(Task*, Vec*);
extern s8 fn_80017A14(ChrInfo*);
extern int fn_80071C74(ChrWork*, f32, f32);
extern int fn_80071C34(f32, f32, f32, f32);
extern void fn_80071BCC(void*, int, f32);
extern f32 fn_8006116C(int);
extern void fn_80061080(f32*, f32*);
typedef struct Cx_BB28 {
    u8 pad[0x2c];
    struct { u8 pad[0x2c]; void* x2c; }* x2c;
} Cx_BB28;
extern TaskFn fn_8000F0A4(s16 i);
extern int fn_80061F58(void*, int, int);
extern void fn_8006CF28(void*, void*, s16);
extern void fn_8006CEEC(void*, void*, int, s16);
extern void fn_8022F00C(void*);
extern int fn_8000CF94(void*);
extern void fn_8000B8E4(void*, void*);
/* Packed date stamp filled from the RTC (OSGetTime). Field names are ours. */
typedef struct CalendarStamp {
    s16 year;
    u8 month;
    u8 day;
    u8 hour;
    u8 minute;
    u8 second;
    u8 weekday;
    u8 pad;
} CalendarStamp;
extern s32 fn_80007BFC(void* a, s32 b);
typedef struct Slot {
    s16 id;
    u8 pad[0xa];
    void* ptr;
} Slot;
#define FLD(p, off, T) (*(T*)((u8*)(p) + (off)))
s8 fn_80020E10(void* p);
s16 fn_80008274(s16 v);
void fn_800615B4(void *p, void *v, void *b);
s32 fn_8003DCF4(void* a, void* b);
void fn_80061518(void* a, NJS_POINT3* b);
typedef struct Ctx {
    u8 pad0[0x40];
    u32 a40;
    u32 b44;
    u8 pad1[4];
    u8 x4c[0x24];
    f32 f70;
    f32 f74;
    f32 f78;
} Ctx;
void fn_80012130(void* p);
typedef struct {
    u8 pad[0x1c];
    NJS_POINT3 pos;
} Ctx8001E19C;
typedef struct {
    u8 pad[0x24];
    Ctx8001E19C *obj;
} Ctx8001E19C_outer;
extern void fn_80071D0C(NJS_POINT3 *out, NJS_POINT3 *a, NJS_POINT3 *b, f32 s);
typedef struct Inner8001FA18 {
    u8 pad0[0xf0];
    u32 flags;
    u8 pad1[0x10];
    NJS_POINT3 v104;
    NJS_POINT3 v110;
    NJS_POINT3 v11c;
} Inner8001FA18;
typedef struct Obj8001FA18 {
    u8 pad0[0x24];
    struct Obj8001FA18 *sub;
    u8 pad1[0x4];
    u32 f2c;
    u8 pad2[0x1c];
    Inner8001FA18 *inner;
} Obj8001FA18;
typedef struct Obj80020B28 {
    u8 pad0[0x6];
    s16 x6;
    s16 x8;
    u8 pad1[0xa];
    s16 x14;
    s16 x16;
    u8 pad2[0xd4];
    u32 flags;
} Obj80020B28;
Task* fn_800215EC(s8 id);
void fn_80015020(s8 id);
void fn_8001DD00(ChrInfo* o, s8 v);
extern s32 lbl_80347330;
extern s32 lbl_80347328;
/* The original temporarily writes two halfwords in a shape record, calls fn_80008DF4, and restores them. */
typedef struct Rec {
    u8 pad[6];
    s16 x;
    s16 y;
} Rec;
typedef struct Mid {
    u8 pad[0x4c];
    Rec* rec;
} Mid;
typedef struct Ent8C00 {
    u8 pad[0x24];
    Mid* mid;
} Ent8C00;
extern void fn_80008DF4(Ent8C00* obj, s32 a, s32 b, s32 c);
typedef struct Ref3 {
    u8 pad[0x28];
    u32 flags;
} Ref3;
typedef struct Ref {
    u8 pad[0x4c];
    Ref3* m;
} Ref;
typedef struct Ent8C00_8000FBA8 {
    u8 pad[0x24];
    Ref* r;
} Ent8C00_8000FBA8;
typedef struct Owner_8000FBA8 {
    u8 pad[0x1e0];
    Ent8C00_8000FBA8* a;
    Ent8C00_8000FBA8* b;
    Ent8C00_8000FBA8* c;
} Owner_8000FBA8;
typedef struct Actor {
    u8 pad[0x24];
    Ref* r;
} Actor;
typedef struct {
    u8 pad[0x1c];
    NJS_POINT3 off;
    u8 sub[4];
} Ctx8001E4;
extern void njPushMatrixEx(void);
extern void njPopMatrixEx(void);
extern void fn_80286EE8(void);
extern void fn_8028B498(void);
extern void fn_80035140(void* model, u8 flag);
typedef struct Obj_80014784 {
    u8 pad[0x24];
    SysObj* data;
} Obj_80014784;
void fn_800136DC(Task* t);
typedef s32 Angle;
typedef struct Dst { u32 x0; u8 pad4[0x20 - 4]; f32 x20; } Dst;
typedef struct Par { f32 x0; f32 x4; f32 x8; Dst* xc; } Par;
typedef struct Work_8000DDFC { u8 pad0[0x4c]; Par* x4c; } Work_8000DDFC;
typedef struct Task_8000DDFC { u8 pad0[0x18]; u8 flags; u8 mode; u8 pad1a[0x24 - 0x1a]; Work_8000DDFC* work; } Task_8000DDFC;
extern f32 njSin(Angle a);
typedef struct Entry { char* name; u8 pad[8]; } Entry;
typedef struct Table { Entry* ents; u32 count; } Table;
extern u32 strlen(const char* s);
typedef struct Inner_80019D7C { u8 pad0[2]; s16 x2; u8 pad4[0xe]; s16 x12; u8 pad14[0xe8-0x14]; s16 xe8; } Inner_80019D7C;
typedef struct Node { u8 pad[0x24]; void* w; } Node;
typedef struct Work_80019D7C { u8 pad[0x4c]; Inner_80019D7C* in; } Work_80019D7C;
/* The 0x18-byte work of the fn_80019B70 task: two character tasks and up to three (kind, value) pairs. */
typedef struct Blk_80019D7C { u8 pad[4]; Task* a; Task* b; s16 c; s16 d; s16 x10; s16 x12; s16 x14; s16 x16; } Blk_80019D7C;
typedef struct Obj_80019D7C { u8 pad[0x24]; Blk_80019D7C* blk; } Obj_80019D7C;
extern void fn_80019B70(void*);
extern void fn_80018CBC(Task*, int, int, int, int);
s32 fn_8001C1F0(Task* o);
typedef struct Cmd { u8 pad0[0x10]; s16 x10; s16 x12; } Cmd;
typedef struct Item { s16 lo; s16 hi; u8 pad4[8]; Cmd* obj; } Item;
extern s32 fn_8006EDA0(void);
s32 fn_80011400(s16 id, s8 val);
extern void fn_8005535C(void *a, void *v, void *t, f32 x);
extern void fn_80011208(s8 a, s8 b, s32 c);
typedef struct B { u32 x0; u8 pad[0x24]; s32 x28; s32 x2c; s32 x30; } B;
typedef struct A { s32 x0; s32 x4; s32 x8; s32 xc; u8 pad[0xc]; B* x1c; } A;
typedef struct D { u8 pad[0x4c]; A* x4c; } D;
typedef struct Obj_8000DF50 { u8 pad[0x18]; u8 flags; u8 state; u8 pad1a[0xa]; D* x24; } Obj_8000DF50;
typedef struct Tsk_80017018 { u8 pad_00[0x24]; ChrWork *work; } Tsk_80017018;
extern s16 fn_80020094(ChrWork *w, s16 a, s16 b, s8 flag);
extern s32 fn_800300C4(s16 i);
extern s32 rand(void);
typedef struct SlotTable {
    s16 count;
    u8 pad2[0x404 - 2];
    void *buf[32];
    void *res[32];
} SlotTable;
extern SlotTable lbl_803098C8;
void fn_801E1718(void *p);
typedef struct { u8 pad0[8]; u32 flags; u8 pad0c[0x18 - 0xc]; } Ent18_8001BAC0;
typedef struct {
    u8 pad0[6];
    s16 x6;
    s16 x8;
    u8 pad0a[0x20 - 0xa];
    s16 x20;
    u8 pad22[0x26 - 0x22];
    s16 x26;
    u8 pad28[0xdc - 0x28];
    Ent18_8001BAC0* xdc;
    u8 pade0[0xec - 0xe0];
    u32 xec;
} Unit_8001BAC0;
extern s32 lbl_803478B8;
extern s32 lbl_803478B4;
extern s32 lbl_803478B0;
extern s32 lbl_803478C0;
extern s32 lbl_803478C4;
extern s32 lbl_803478C8;
s32 fn_8023CD10(u8* h);
s32 fn_8023AC78(u8* h);
typedef struct Tk_80009FD8 { u8 pad0[4]; struct Tk_80009FD8* next; u8 pad8[0x10]; u8 flags; } Tk_80009FD8;
typedef struct Sys_80310A1C { u8 pad0[0x18]; u8 f18; } Sys_80310A1C;
extern Tk_80009FD8* lbl_80346A98;
extern s32 lbl_80347370;
extern s32 lbl_8034737C;
extern s16 lbl_8034736A;
extern Sys_80310A1C lbl_80310A1C;
extern s32 lbl_803475D4;
extern s32 lbl_80347704;
extern s32 lbl_80346A90;
extern u32 lbl_80347364;
extern char lbl_802ACC98[];
extern void fn_8002903C(void);
extern void fn_801D6738(void);
extern void fn_8000AA08(void);
extern void fn_8000AA98(void);
extern void fn_801CBBF8(void);
extern void fn_8022642C(void);
extern void fn_801E1D94(void);
extern void fn_801DBE6C(s32);
extern void fn_80228014(void);
extern void fn_80217830(s32);
extern void fn_80100178(char*);
extern void *memcpy(void *d, const void *s, u32 n);
typedef struct Ent_800095D0 { s32 a; s32 b; s32 size; s32 off; } Ent_800095D0;
typedef struct EntD { s32 a; s32 b; s32 size; void *data; } EntD;
extern void fn_80035918(void *p);
extern s16 fn_800364F4(void *p);
extern s32 fn_800364B8(void *e);
extern s16 fn_800089F0(Ent_80008800* t, s16 a, s16 b, s16* lo, s16* hi, s16 start);
typedef struct Vec3_8001E3D8 { f32 x, y, z; } Vec3_8001E3D8;
typedef struct Model { u8 pad[0x154]; Joint* joints; } Model;
typedef struct Work_8001E3D8 {
    u8 pad0[0x14];
    s16 idx;
    u8 pad16[6];
    Vec3_8001E3D8 off;
    Vec3_8001E3D8 pos;
    u8 pad34[0x4c - 0x34];
    Model* model;
} Work_8001E3D8;
typedef struct Task_8001E3D8 { u8 pad[0x24]; Work_8001E3D8* work; } Task_8001E3D8;
typedef struct P3 { f32 x, y, z; } P3;
typedef struct Dat1E { u8 pad00[0x154]; u8 *tbl; } Dat1E;
typedef struct Wk1E {
    u8 pad00[0x14];
    s16 idx;
    u8 pad16[6];
    f32 x1c, x20, x24;
    P3 x28;
    u8 pad34[0x18];
    Dat1E *d;
} Wk1E;
typedef struct Tk1E { u8 pad00[0x24]; Wk1E *work; } Tk1E;
typedef struct Wk1E_8001E238 {
    u8 pad00[0x14];
    s16 idx;
    u8 pad16[6];
    f32 x1c, x20, x24;
    NJS_POINT3 x28;
    u8 pad34[0x18];
    Dat1E *d;
} Wk1E_8001E238;
typedef struct Tk1E_8001E238 { u8 pad00[0x24]; Wk1E_8001E238 *work; } Tk1E_8001E238;
typedef struct Wk_80014BA8 { u8 pad[0x4c]; u8* x4c; } Wk_80014BA8;
extern void fn_8002923C(s8 id, u16 mask, s32 c);
typedef struct ArcInfo {
    s32 x0;
    s32 x4;
    u8 pad8[8];
    s32 x10;
    s32 x14;
} ArcInfo;
typedef struct ArcSlot {
    ArcInfo* info;
    s32 x4;
    s32 x8;
} ArcSlot;
typedef struct ArcSet {
    ArcSlot* slots;
} ArcSet;
typedef struct ArcHdr {
    s32 x0;
    s16 x4;
    s16 x6;
} ArcHdr;
extern void fn_80298E48(void);
extern s32 fn_80297558(ArcSet* set, s32 idx, u32* a, s32* b);
extern u32 fn_80298798(ArcHdr* hdr, s32* c, void* info);
extern s32 fn_80298A04(ArcSet* set, s32 idx, s32 c, s32 b, ArcHdr* hdr, s32* out);
extern s32 fn_80298BF8(s32 out, s32 x);
extern void fn_80298BCC(s32 out);
typedef struct Fn108EC {
    u8 pad0[0x1c];
    u32 flags;
    u8 pad1[0x28 - 0x20];
    s16 stat[6];
} Fn108EC;
extern s32 fn_8001604C(void* t, s8* arr, s32 a, s32 b);
extern s32 fn_80016234(void* t, s8 flag, s32 a, s32 b, s32 c);
extern s32 fn_80015EC8(void* t, s8* arr, s8 flag);
typedef struct { f32 x, y, z; } V3;
typedef struct F163A4Unit {
    s8 x0;
    u8 pad1[3];
    s8 x4;
} F163A4Unit;
typedef struct F163A4Work {
    u8 pad0[0x4c];
    F163A4Unit* unit;
} F163A4Work;
typedef struct F163A4Task {
    u8 pad0[0x24];
    F163A4Work* wk;
} F163A4Task;
extern void fn_8001E6DC(V3* out, s8 v);
extern s8 fn_80018398(V3* v, s32 a);
extern s32 fn_8001D944(s8 id, void* t);
typedef struct Node_800102C8 {
    u8 pad[0x24];
    void* val;
} Node_800102C8;
typedef struct Mid_800102C8 {
    u8 pad0[0x1e0];
    Node_800102C8* e0;
    Node_800102C8* e4;
} Mid_800102C8;
typedef struct Holder_800102C8 {
    u8 pad[0x4c];
    Mid_800102C8* mid;
} Holder_800102C8;
typedef struct Ent_800102C8 {
    u8 pad[0x24];
    Holder_800102C8* h;
} Ent_800102C8;
extern void fn_80075F2C(void *t);
extern s32 fn_8006DB94(void);
extern void fn_80032C68(void);
extern void fn_80017CB8(Task *t, s16 v);
typedef struct Self { u8 pad[0x18]; u8 flags; u8 state; } Self;
/* lbl_80309E24: the character task table (void* in unit_80005B50.c). */
extern Task* lbl_80309E24[];
extern void fn_8001BE2C(Task* t);
typedef struct Sub {
    void* link;
    u8 pad[0x1c];
    f32 pos;
} Sub;
typedef struct Mid_8000DEC8 {
    f32 speed;
    s16 mode;
    u8 pad[2];
    Sub* sub;
} Mid_8000DEC8;
typedef struct Holder_8000DEC8 {
    u8 pad[0x4c];
    Mid_8000DEC8* mid;
} Holder_8000DEC8;
typedef struct Actor_8000DEC8 {
    u8 pad0[0x18];
    u8 flags;
    u8 state;
    u8 pad1[0xa];
    Holder_8000DEC8* holder;
} Actor_8000DEC8;
typedef struct { u8 pad[0xec]; u32 xec; } Flags;
typedef struct { u8 pad[0x1c]; NJS_POINT3 pos; u8 pad28[0x4c - 0x28]; Flags* x4c; } Work_800171F0;
typedef struct { u8 pad[0x24]; Work_800171F0* work; } Obj_800171F0;
extern f32 fn_80071E9C(void*, void*);
void fn_8001E19C(NJS_POINT3 *self, NJS_POINT3 *out, void *ctx, NJS_POINT3 *v);
extern s32 fn_8023AB88(void *info, void *addr, s32 len, s32 offset, void (*cb)(void), s32 prio);
typedef struct { s32 a; s32 b; s32 err; } Err_803457F8;
extern Err_803457F8 lbl_803457F8;
extern s32 lbl_803478AC;
extern s32 lbl_80346738;
extern s32 lbl_803478D4;
extern s32 lbl_803478BC;
extern void *lbl_803478D8;
extern s32 lbl_803478D0;
extern s32 lbl_803478CC;
extern s32 lbl_803478A8;
typedef struct Vec3_80015A58 { f32 x, y, z; } Vec3_80015A58;
extern void fn_802917C8(Vec3_80015A58 *pts, Vec3_80015A58 *out, Vec3_80015A58 *tmp, f32 t);
typedef struct {
    s32 key;
    s32 val;
} LblEnt;
extern LblEnt lbl_802ACDF0[];
extern s32 fn_80076170(f32 a, f32 b, void *o, s32 id, s32 k, s32 j);
extern void fn_80072770(void *o);
/* lbl_80309EC8: the 0x244-byte battle/system block (Sys_80309EC8_80012078 in unit_80005B50.c). */
typedef struct {
    u8 pad0[0x48];
    u32 x48;
    u8 x4c[12];
    u8 x58[12];
    u8 x64[12];
    f32 va[3];
    f32 vb[3];
    u8 pad88[0xC0 - 0x88];
    f32 xc0[3];
    u8 padcc[0x110 - 0xCC];
    f32 x110;
    u8 pad114[0x160 - 0x114];
    f32 x160;
    u8 pad164[0x19A - 0x164];
    s16 x19a;
    u8 pad19c[0x204 - 0x19C];
    s8 a[10];
    u8 pad20e[2];
    u32 w[10];
    s8 b[10];
    u8 pad242[2];
} Sys_80309EC8_80012078;
typedef struct V5BF30 { f32 x, y, z; } V5BF30;
typedef struct ModelCache {
    u8 pad0[4];
    s16 x4;
    u8 pad6[2];
    void* x8;
    char name[0x28];
    struct ModelCache* x34;
    struct ModelCache* x38;
    u8 pad3c[8];
} ModelCache;
typedef struct ModelSrc {
    s32 id;
    void* data;
    s32 size;
} ModelSrc;
typedef struct { u16 x0; u8 pad2[0x2a]; } Sys_80309E5C_8000C8AC;
extern char lbl_802ACCE8[];
extern ModelCache* lbl_803473A0;
extern int sprintf(char* s, const char* fmt, ...);
extern void* memset(void* dst, int c, u32 n);
extern int fn_8025EF88(const char* a, const char* b);
extern char* strcpy(char* d, const char* s);
extern void* fn_801DB124(void* data);
extern void fn_8006CF54(ModelCache* c);
typedef struct Inner_80007640 { s32 x0; u8 pad[0xc - 4]; s32 xc; } Inner_80007640;
typedef struct Mid_80007640 { u8 pad[0xc]; Inner_80007640 *xc; } Mid_80007640;
extern s32 fn_80298CAC(u32 v, s32 b, s32 c, s32 *out);
extern s32 fn_80298210(Mid_80007640 **a, Inner_80007640 **b);
extern void fn_80298C78(ArcSet *o, s32 idx, s32 v);
extern s32 lbl_80347EC4;
typedef struct Wrap8001FD7C {
    u8 pad0[0x24];
    ChrWork *ent;
} Wrap8001FD7C;
typedef struct Ent8001FDD8 {
    s16 key0;
    s16 type;
    u8 pad0[8];
    s16 key12;
    u8 pad1[10];
} Ent8001FDD8;
typedef struct Inner8001FDD8 {
    u8 pad0[0xdc];
    Ent8001FDD8 *tab;
} Inner8001FDD8;
typedef struct Obj8001FDD8 {
    u8 pad0[0x4c];
    Inner8001FDD8 *inner;
} Obj8001FDD8;
typedef struct {
    u8 pad0[0x48];
    u32 x48;
    u8 x4c[12];
    u8 x58[12];
    u8 x64[12];
} G;
typedef struct {
    u16 x0;
    u8 pad2[0x2a];
} Sys;
typedef struct {
    u8 pad0[0x190];
    u32 x190;
} Gs;
/* One controller's state: x8 held buttons, xc newly pressed buttons. */
typedef struct Slot24 { u32 flags; u32 x4; u32 x8; u32 xc; u8 pad10[0x10]; u32 x20; } Slot24;
/* ADD: lbl_8030A6D4 entries (0x24 bytes) */
extern Slot24 lbl_8030A6D4[];
extern void fn_80061048(char* s);
extern void fn_80035FC0(char* name, void* slot, s32 flag);
typedef struct CE8Pos {
    u8 pad0[0x1C];
    NJS_POINT3 p1c;
} CE8Pos;
typedef struct CE8Ext {
    u8 pad0[0x10];
    f32 x10;
} CE8Ext;
typedef struct CE8State {
    CE8Pos* x0;
    CE8Ext* x4;
    u8 pad8[2];
    s16 xa;
    u8 padc[0x18 - 0xC];
    NJS_POINT3 p18;
    u8 pad24[0x44 - 0x24];
    f32 x44;
    s16 x48;
    u8 pad4a[2];
    s16 x4c;
    s16 x4e;
} CE8State;
typedef struct CE8Work {
    u8 pad0[0x4C];
    CE8State* st;
} CE8Work;
extern void fn_802307EC(void* p, void* v, s32 n);
typedef struct E02Ctr {
    u16 cur;
    u16 max;
    void* x4;
} E02Ctr;
typedef struct E02Work {
    void* x0;
    u8 pad4[0x4C - 0x4];
    E02Ctr* ctr;
} E02Work;
/* Object reached through extra->obj: a position at 0x1c and three s32 angles at 0x28. */
typedef struct RotObj {
    u8 pad0[0x1c];
    NJS_POINT3 pos;   /* 0x1c */
    s32 rot[3];       /* 0x28 */
} RotObj;
typedef struct RotRef {
    u8 pad0[0x24];
    RotObj *obj;      /* 0x24 */
} RotRef;
typedef struct Ent_BB28_8000AE08 Ent_BB28_8000AE08;
extern void fn_80012100(void* a);
extern s32 fn_8000AD30(u8 dir);
#define LIMIT() \
    switch (lbl_80309E5C.x0) { \
    case 0x46: case 0x47: case 0x49: case 0x4b: \
    case 0x80: case 0x81: case 0x82: \
    case 0x92: case 0x93: case 0x94: case 0x95: \
        *out = -0.9f; \
        break; \
    default: \
        *out = -1.0f; \
        break; \
    } \
    return 1;
extern void fn_80032BBC(s8, s32);
extern void fn_80032B6C(s8, s32);
extern s16 fn_8001D41C(s16* cur, s16* other);
extern void fn_80053F38(s8, s32);

typedef struct {
    u32 keyframe;
    f32 key[3];
} NJS_MKEY_F;
/* Ninja motion node data with one to four channels: key arrays, then key counts. */
typedef struct { void* p[1]; u32 nb[1]; } NJS_MDATA1;
typedef struct { void* p[2]; u32 nb[2]; } NJS_MDATA2;
typedef struct { void* p[3]; u32 nb[3]; } NJS_MDATA3;
typedef struct { void* p[4]; u32 nb[4]; } NJS_MDATA4;
typedef void (*MotionInterpFn)(void* keys, u32 i, u32 nbKeys, void* out);
typedef struct {
    void* mdata;   /* 0x00 current node's NJS_MDATAn */
    void** keys;   /* 0x04 key array pointers for the node */
    u32* counts;   /* 0x08 key counts for the node */
    f32 frame;     /* 0x0C */
    u32 nbFrame;   /* 0x10 */
    s32 unk14;
    f32* matrix;   /* 0x18 extra matrix applied after each node, or NULL */
    s32 unk1C;
} MotionState;
extern MotionState lbl_80316940;
extern u16 lbl_8034789A;
extern u16 lbl_8034789C;
extern MotionInterpFn lbl_80346730[2];

/* Steps the motion cursor past the current node's NJS_MDATAn, then applies the extra matrix. */
void fn_80006CE0(void) {
    switch (lbl_8034789C) {
    case 1: {
        NJS_MDATA1* m = lbl_80316940.mdata;
        lbl_80316940.mdata = m + 1;
        break;
    }
    case 2: {
        NJS_MDATA2* m = lbl_80316940.mdata;
        lbl_80316940.mdata = m + 1;
        break;
    }
    case 3: {
        NJS_MDATA3* m = lbl_80316940.mdata;
        lbl_80316940.mdata = m + 1;
        break;
    }
    case 4: {
        NJS_MDATA4* m = lbl_80316940.mdata;
        lbl_80316940.mdata = m + 1;
        break;
    }
    }
    if (lbl_80316940.matrix != 0) {
        njMultiMatrix(0, lbl_80316940.matrix);
    }
}

s32 fn_80006F1C(s32* out, s32 type) {
    NJS_MKEY_F* keys;
    u32 count;
    u32 lo;
    u32 hi;
    u32 f;
    s32 idx = lbl_8034789A & 1;
    switch (lbl_8034789C) {
    case 1: {
        NJS_MDATA1* m = lbl_80316940.mdata;
        lbl_80316940.keys = m->p;
        lbl_80316940.counts = m->nb;
        break;
    }
    case 2: {
        NJS_MDATA2* m = lbl_80316940.mdata;
        lbl_80316940.keys = m->p;
        lbl_80316940.counts = m->nb;
        break;
    }
    case 3: {
        NJS_MDATA3* m = lbl_80316940.mdata;
        lbl_80316940.keys = m->p;
        lbl_80316940.counts = m->nb;
        break;
    }
    case 4: {
        NJS_MDATA4* m = lbl_80316940.mdata;
        lbl_80316940.keys = m->p;
        lbl_80316940.counts = m->nb;
        break;
    }
    }
    lo = 0;
    keys = lbl_80316940.keys[idx];
    count = lbl_80316940.counts[idx];
    hi = count;
    f = lbl_80316940.frame;
    while (hi - lo > 1) {
        u32 mid = (lo + hi) >> 1;
        if (f >= keys[mid].keyframe) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    if (keys != NULL) {
        lbl_80346730[type](keys, lo, count, out);
        return 1;
    }
    out[0] = 0;
    out[1] = 0;
    out[2] = 0;
    return 0;
}

void fn_800068C4(NJS_MKEY_F* keys, u32 i, u32 nbKeys, f32* out) {
    NJS_MKEY_F* k1 = &keys[i];
    f32 div[2] = {1.0f, 1.0f};
    NJS_MKEY_F* k0 = &keys[(i + nbKeys - 1) % nbKeys];
    NJS_MKEY_F* k2 = &keys[(i + 1) % nbKeys];
    NJS_MKEY_F* k3 = &keys[(i + 2) % nbKeys];
    f32 t, t2, t3;
    f32 c0, c1, c2, c3;

    div[1] = (f32)(k2->keyframe - k1->keyframe);
    t = (lbl_80316940.frame - (f32)k1->keyframe) / div[(s32)(k2->keyframe - k1->keyframe) > 0];
    t2 = t * t;
    t3 = t2 * t;
    c0 = 0.5f * (-t3 + 2.0f * t2 - t);
    c1 = 1.5f * t3 - 2.5f * t2 + 1.0f;
    c2 = -1.5f * t3 + 2.0f * t2 + 0.5f * t;
    c3 = 0.5f * (t3 - t2);
    out[0] = c0 * k0->key[0] + c1 * k1->key[0] + c2 * k2->key[0] + c3 * k3->key[0];
    out[1] = c0 * k0->key[1] + c1 * k1->key[1] + c2 * k2->key[1] + c3 * k3->key[1];
    out[2] = c0 * k0->key[2] + c1 * k1->key[2] + c2 * k2->key[2] + c3 * k3->key[2];
}

extern void fn_802A9338(s32 a, s32 b, s32 c, void (*f)(void));
typedef struct {
    u32 keyframe;
    Angle key[3];
} NJS_MKEY_A;
void fn_80006A70(NJS_MKEY_A* keys, u32 i, u32 nbKeys, Angle* out) {
    f32 div[2] = {1.0f, 1.0f};
    NJS_MKEY_A* k1 = &keys[i];
    NJS_MKEY_A* k2 = &keys[(i + 1) % nbKeys];
    f32 t;
    f32 u;

    div[1] = (f32)(k2->keyframe - k1->keyframe);
    t = (lbl_80316940.frame - (f32)k1->keyframe) / div[(s32)(k2->keyframe - k1->keyframe) > 0];
    u = 1.0f - t;
    out[0] = k1->key[0] * u + k2->key[0] * t;
    out[1] = k1->key[1] * u + k2->key[1] * t;
    out[2] = k1->key[2] * u + k2->key[2] * t;
}

extern u16 lbl_80347898;

void fn_800071D8(NJS_MOTION* m, f32 frame) {
    if (m != NULL) {
        if (frame >= m->nbFrame) {
            return;
        }
        lbl_8034789C = m->inp_fn & ~0xC0;
        lbl_80347898 = (m->inp_fn & 0xC0) > 0;
        lbl_8034789A = m->type;
        lbl_80316940.mdata = m->mdata;
        lbl_80316940.nbFrame = m->nbFrame;
    } else {
        lbl_8034789C = 0;
        lbl_80347898 = 0;
        lbl_8034789A = 0;
    }
    lbl_80316940.frame = frame;
    lbl_80316940.unk14 = 0;
    lbl_80316940.matrix = NULL;
}

void fn_800072A8(s32 a, s32 b, s32 c)
{
    fn_802A9338(a, b, c, fn_8028AB48);
}

extern void fn_80287C14(void);
void fn_800072D0(s32 a, s32 b, s32 c)
{
    fn_802A9B94(a, b, c, fn_80287C14);
}

void fn_800072F8(s32 a, s32 b, s32 c)
{
    fn_802A9338(a, b, c, fn_80287C14);
}

extern void fn_802873BC(void);
void fn_80007320(s32 a, s32 b, s32 c)
{
    fn_802A9B94(a, b, c, fn_802873BC);
}

void fn_80007348(s32 a, s32 b, s32 c)
{
    fn_802A9338(a, b, c, fn_802873BC);
}

extern void fn_802890A4(void);
void fn_80007370(s32 a, s32 b, s32 c)
{
    fn_802A9B94(a, b, c, fn_802890A4);
}

void fn_80007398(s32 a, s32 b, s32 c)
{
    fn_802A9338(a, b, c, fn_802890A4);
}

void fn_80008170(void);
extern NjTexRef* lbl_80347ED4;
extern char lbl_80348060[5];
extern char lbl_80348068[5];
extern char lbl_802DADC0[];
extern void fn_80298034(char* out, ArcInfo* info, char* ext);
extern s32 fn_80008194(char* name);
s32 fn_80008258(s32* out);
void fn_80007514(s32** buf, s32* size);
s32 fn_8000810C(void* a, s32 b);
s32 fn_800079AC(ArcSet* set, s32 idx) {
    char name[256];
    char path[256];
    ArcHdr hdr;
    s32 n;
    s32 c;
    u32 a;
    s32 b;
    s32 out;
    s32* ptr;
    s32 m;
    s32 r;
    fn_80298E48();
    r = fn_80297558(set, idx, &a, &b);
    if (r != 0) return r;
    fn_80298034(path, set->slots[idx].info, lbl_80348060);
    strcpy(name, lbl_802DADC0);
    strcat(name, path);
    if (fn_80008194(name) < 0) {
        fn_80298034(path, set->slots[idx].info, lbl_80348068);
        strcpy(name, lbl_802DADC0);
        strcat(name, path);
        if (fn_80008194(name) < 0) {
            lbl_803457F8.err = 2;
            return -1;
        }
    }
    fn_80008258(&n);
    fn_80007514(&ptr, &m);
    if (m < n) {
        fn_80008170();
        return -1;
    }
    if (fn_8000810C(ptr, 0x20) < 0) {
        fn_80008170();
        lbl_803457F8.err = 5;
        return -1;
    }
    if (fn_80298798(&hdr, &c, ptr) == 0) return -1;
    if (*ptr == 0x47434958) { /* "GCIX" */
        if (a != -1) c = a;
        r = fn_80298A04(set, idx, c, b, &hdr, &out);
        if (r != 0) return r;
        if (fn_8000810C(lbl_80347ED4[out].mem->body.data, lbl_80347ED4[out].mem->body.size) < 0) {
            fn_80008170();
            fn_80298BCC(out);
            set->slots[idx].x4 &= ~0x200000;
            set->slots[idx].x8 = 0;
            lbl_803457F8.err = 8;
            return -1;
        }
        fn_80008170();
    } else {
        return -1;
    }
    return 1;
}

void fn_80008170(void) {
    fn_8023A8E0((s32)lbl_803478DC);
}

s32 fn_80008C68(s32 key, Task* obj);
extern s32 fn_800367E8(s32 key, Ent_80008800* e, Task* obj);
extern s32 fn_8003732C(s32 key, Ent_80008800* e, Task* obj);
static inline s32 CmdAllowed(Task* obj, s16 id, s16 g) {
    s16 grp = lbl_8030A10C.xf0;
    ChrInfo* work = ChrW(obj)->st;
    if (grp != 0 && g != grp) {
        switch (id) {
        case 0x36:
            return 1;
        default:
            return 0;
        }
    }
    if (work->xf0 & 0x8000) {
        switch ((g << 16) | id) {
        case 0x30009:
        case 0x3001F:
        case 0x3002A:
        case 0x30036:
        case 0x3003B:
        case 0x30042:
        case 0x30058:
            return 0;
        }
    }
    return 1;
}
s32 fn_8000832C(Task* obj, Ent_80008800* tbl, CondLink* range) {
    Ent_80008800* e;
    s32 count = 0;
    s16 i = 0;
    s32 v;
    s32 key;
    if (range != 0) i = range->x4;
    if (tbl != 0) {
        e = &tbl[i];
        do {
            s16 id = e->x0;
            s16 g = e->x2;
            if (id < 0) break;
            if (CmdAllowed(obj, id, g) != 0) {
                key = (g << 16) | id;
                v = 0;
                if (fn_80008C68(key, obj) == 0) {
                    v = 0;
                } else {
                    switch (key) {
                    case 0x30007:
                    case 0x30032:
                    case 0x30041:
                    case 0x3004E:
                        break;
                    default:
                        v = fn_800367E8(key, e, obj);
                        break;
                    }
                }
                if (v == 0) v = fn_8003732C(key, e, obj);
                if (v != 0) count++;
            }
            e++;
            i++;
        } while (range == 0 || i < range->x6);
    }
    return count;
}

static inline s16 EntScore(Task* a, Ent_80008800* d, CondLink* e)
{
    return fn_8000832C(a, d, e);
}
s16 fn_80008530(Task* a, s16 b, s16 c, Ent_80008800* d, CondLink* p) {
    CondLink* cur = p;
    s16 sum = 0;
    if (p == NULL) {
        return fn_800086BC(a, b, c, d, 0, 0);
    }
    while (cur != NULL) {
        if (fn_8003DE8C(cur->x0, cur->x2, b, c) != 0) {
            sum += (cur != NULL) ? EntScore(a, d, cur) : fn_8000832C(a, d, 0);
        }
        cur = cur->next;
    }
    return sum;
}

s16 fn_800085EC(Task* a, s16 b, s16 c, Ent_80008800* d, CondLink* p) {
    CondLink* cur = p;
    s16 sum = 0;
    if (p == NULL) {
        return fn_800086BC(a, b, c, d, 0, 0);
    }
    while (cur != NULL) {
        if (fn_8003DE8C(cur->x0, cur->x2, b, c) != 0) {
            sum += fn_800086BC(a, b, c, d, cur, 0);
        }
        cur = cur->next;
    }
    return sum;
}

CondLink* fn_80008938(Ent_80008800* t, s16 a, s16 b) {
    CondLink* out = 0;
    s16 lo;
    s16 hi;
    if (t != 0) {
        if (fn_800089F0(t, a, b, &lo, &hi, 0) != 0) {
            if (fn_80061F58(&out, 0x10, 0) != 0) {
                out->x0 = a;
                out->x2 = b;
                out->x4 = lo;
                out->x6 = hi;
                return out;
            }
            return 0;
        }
        return 0;
    }
    return 0;
}

extern f32 lbl_80348070;
extern s32 fn_80014C90(s8 id, s32 flags);

s32 fn_80008C68(s32 key, Task* obj) {
    ChrInfo* w = ChrW(obj)->st;
    u32 flags;

    if (w->id >= 12) return 1;
    if (fn_80017A14(w) == 2) {
        switch (key) {
        case 0x3000E:
            return 0;
        }
    }
    flags = w->xec;
    if (flags & 8) {
        switch (key) {
        case 0x30055:
            return 0;
        }
    }
    if (flags & 0x100000) {
        switch (key) {
        case 0x30036:
            return w->draw.a > lbl_80348070;
        case 0x30004:
            return 1;
        case 0x3000E:
            if (lbl_80347394 != 0) return 1;
            if (fn_80014C90(w->id, 0x800) != 0) return 0;
            break;
        }
        return 0;
    }
    if (fn_80014C90(w->id, 0x800) != 0 && lbl_8034733C != 7) {
        switch (key) {
        case 0x3000E:
            return 0;
        }
    }
    return 1;
}

void fn_800091A4(s16* p) {
    s16 x = p[0];
    s16 y = p[1];
    if (x >= 0) {
        fn_800090F8((y << 16) | x, p);
    }
}

void fn_8000AA58(void);
s32 fn_8000ACE8(void);
void fn_80009FBC(void *p);
extern void (*lbl_802DAE50[])(void);
void fn_80009FD8(void);

extern s32 lbl_803475D8;
extern s32 lbl_80346A94;
extern s16 lbl_80347368;
extern void* lbl_8034731C;
extern s32 lbl_80347380;
extern s32 lbl_80347338;
extern s32 lbl_80347508;
extern s32 lbl_80347518;
extern f32 lbl_80347510;
extern char lbl_803480D8[8];

extern void fn_8002F35C(void);
extern void StvSampLoadBlocking(void);
extern void fn_801DBA58(u32 a, u32 b, u32 c);
extern void fn_8025ECBC(void);
extern void fn_80226170(void);
extern void fn_801CBC30(void);
extern void fn_801C78B8(void);
extern void DrawStateInit(void);
extern void fn_800300DC(void);
extern void fn_80030100(void);
extern void TextReset(void);
extern s32 fn_80065490(void);
extern void fn_8005121C(void);
extern void fn_8002F54C(void);
extern void fn_801CC578(char* s);
extern void fn_80077428(void);
extern void fn_80030ABC(void);
extern void fn_800309C0(void);
extern void fn_800849A8(void);
extern void fn_801D67DC(void);
extern void fn_800308A8(void);
extern void fn_800309E4(void);
extern void fn_8002F6D4(void);
extern void fn_801CBBAC(f32 v);
extern void fn_801CBBD8(void);
extern void fn_80009874(void);

typedef struct Slot1C {
    s32 id;
    s32 x4;
    u8 pad8[0x10];
    s32 x18;
} Slot1C;

extern u32 fn_8006E810(s32 id);

s32 fn_80009500(Slot1C* tbl, s32 id, s32 val)
{
    s16 i = 0;
    Slot1C* s;
    s32 v;

    if (fn_8006E810(id) == 0) goto set;
    return 0;
loop:
    while ((v = s->id) > 0) {
        if (id == v) return 0;
        i++;
        s++;
        if (i >= 0x80) return 0;
    }
    tbl[i].id = id;
    tbl[i].x4 = 0;
    tbl[i].x18 = val;
    tbl[i + 1].id = -1;
    return 1;
set:
    s = tbl;
    goto loop;
}

void fn_8000A118(void) {
    if (lbl_803475D8 == 1) {
        lbl_8034737C = 8;
        lbl_80346A94 = 0;
    }
    if (lbl_80347368 != 0) fn_8002F35C();
    switch (lbl_8034737C) {
    case 0:
        lbl_80346A98 = 0;
        if (lbl_80346A94 == 0 && lbl_80347370 != 0) {
            lbl_80346A94 = 1;
            StvSampLoadBlocking();
        }
        fn_801DBA58(0, 0, 0);
        lbl_8034737C = 1;
    case 1:
        lbl_80347704 = 1;
        lbl_8034731C = 0;
        lbl_80346AA4 = 0;
        OSGetTick();
        fn_8025ECBC();
        OSGetTick();
        fn_8025ECBC();
        fn_80226170();
        lbl_80346A98 = fn_802268E8(lbl_803475A8, fn_80009FBC);
        fn_801CBC30();
        fn_801C78B8();
        DrawStateInit();
        fn_800300DC();
        fn_80030100();
        fn_801C78B8();
        TextReset();
        fn_8022642C();
        lbl_80347380 = 0;
        if (lbl_80347370 != 0) {
            lbl_8034737C = 2;
        } else {
            lbl_8034737C = 3;
        }
        break;
    case 2:
        lbl_8034737C = 3;
        break;
    case 11:
        if (fn_8000ACE8() != 0) lbl_8034737C = 12;
        break;
    case 12:
        if (fn_80065490() != 0) lbl_8034737C = 3;
        break;
    case 3:
        fn_8005121C();
        fn_8002F54C();
        fn_801CC578(lbl_803480D8);
        fn_80077428();
        fn_80030ABC();
        fn_800309C0();
        fn_800849A8();
        fn_801D67DC();
        fn_8000AA58();
        lbl_8034733C = 0;
        lbl_80347338 = 0;
        if (lbl_80347370 != 0) StvSampLoadBlocking();
        fn_800308A8();
        lbl_8034737C = 4;
        break;
    case 4:
        fn_800309E4();
        break;
    case 5:
        lbl_802DAE50[lbl_8034733C]();
        fn_800309E4();
        fn_8002F6D4();
        break;
    case 6:
        if (lbl_80347508 != 1) {
            if (lbl_80347518 == 0) {
                fn_801CBC30();
                fn_801CBBAC(7.5f);
                lbl_80347508 = 1;
                lbl_80347510 = 0.0f;
            }
            lbl_8034737C = 7;
        }
        fn_800309E4();
        break;
    case 7:
        if (lbl_80347508 != 1) {
            if (lbl_80347518 == 0) fn_801CBBD8();
            lbl_8034737C = 8;
        }
        fn_800309E4();
        break;
    case 8:
        fn_80009FD8();
        break;
    case 9:
        fn_80009874();
        break;
    case 10:
        break;
    }
}

void fn_8000A3A4(void* obj) {
    lbl_80346AA4 = fn_802268E8(lbl_803475A8, fn_8000A3FC);
    PTR(lbl_80346AA4, 0x24) = fn_801E1C7C(12);
    *(void**)PTR(lbl_80346AA4, 0x24) = obj;
}

void fn_8000AA08(void) {
    fn_801DDCA8(lbl_803474E4);
    if (lbl_80346AA0 != 0) {
        fn_802275A4(PTR(PTR(lbl_80346AA0, 4), 0x20), 1);
        fn_801E17E0(lbl_80346AA0);
        lbl_80346AA0 = 0;
    }
}

void fn_8000AA58(void) {
    lbl_80346AA0 = fn_801DB1A4(4);
    fn_80227810(PTR(PTR(lbl_80346AA0, 4), 0x20));
    fn_801DDD74(lbl_803474E4, 1);
}

s32 fn_8000ACE8(void) {
    return 1;
}

f32 fn_8000ACF0(Vec3* v) {
    return fn_80291A5C(v->z * v->z + (v->x * v->x + v->y * v->y));
}

/* A loaded resource file handle (fn_801CC69C). */
typedef struct ResHandle {
    u8 pad0[0x54];
    u32 size;
} ResHandle;
extern char lbl_802ACCC4[];
extern char lbl_802ACCD0[];
extern int sprintf(char* s, const char* fmt, ...);
extern ResHandle* fn_801CC69C(char* name);
extern void fn_801CC608(ResHandle* h, void* buf, u32 size);
extern void fn_801CC65C(ResHandle* h);
extern void fn_801E1DF8(s32 a, void* b);

/* The work of the effect task fn_8000BF48 starts (fn_8000F0A4(11)), and its 0x38-byte parameters. */
typedef struct Par_8000BF48 { u8 pad0[8]; u32 x8; f32 xc; f32 x10; f32 x14; s16 x18; u8 pad1a[0x38 - 0x1a]; } Par_8000BF48;
typedef struct Work_8000BF48 { u8 pad0[0x4c]; Par_8000BF48* x4c; u8 pad50[8]; } Work_8000BF48;
typedef struct Src_8000BF48 { s16 x0; u8 pad2[2]; u32 x4; f32 x8; f32 xc; f32 x10; s16 x14; } Src_8000BF48;
typedef struct Owner_8000BF48 { u8 pad[0xc]; Src_8000BF48* src; } Owner_8000BF48;

void fn_8000B5F4(W *o, f32 frame) {
    void *aux = NULL;
    njPushMatrixEx();
    fn_80286EE8();
    fn_8028B498();
    njTranslate(0, o->tx, o->ty, o->tz);
    njRotateXYZ(0, o->rx, o->ry, o->rz);
    njScale(0, o->sx, o->sy, o->sz);
    fn_8006CEEC(o->x10->x8, &aux, 1, o->x16);
    if (o->x0 != NULL) {
        if (o->xc != NULL && aux != NULL) {
            fn_800353F4(o->x0, o->xc, aux, frame, o->x44);
        } else if (o->xc != NULL) {
            fn_80035380(o->x0, o->xc, frame, o->x44);
        } else {
            fn_80035140(o->x0, o->x44);
        }
    }
    njPopMatrixEx();
}

/* The work parameters of the effect task fn_8000BE28 starts (fn_8000F0A4(12)), 0x50 bytes. */
typedef struct Par_8000BE28 {
    Work_BB28* x0;       /* the first of the current table's works */
    void* x4;
    s16 x8;
    s16 xa;
    f32 xc;
    f32 x10;
    f32 x14;
    u8 pad18[0x24 - 0x18];
    s16 x24;
    s16 x26;
    s16 x28;
    u8 pad2a[0x50 - 0x2a];
} Par_8000BE28;
typedef struct Work_8000BE28 { u8 pad0[0x4c]; Par_8000BE28* x4c; u8 pad50[8]; } Work_8000BE28;
typedef struct Src_8000BE28 {
    s16 x0;
    u8 pad2[2];
    s16 x4;
    s16 x6;
    f32 x8;
    f32 xc;
    f32 x10;
    u8 pad14[0x20 - 0x14];
    s16 x20;
    s16 x22;
    s16 x24;
} Src_8000BE28;
typedef struct Owner_8000BE28 { u8 pad[0xc]; Src_8000BE28* src; } Owner_8000BE28;

void fn_8000BE28(Owner_8000BE28 *a) {
    Src_8000BE28 *s = a->src;
    Task *n;
    Work_8000BE28 *w;
    Par_8000BE28 *d;
    if (s->x0 < lbl_80309E5C.tbl[lbl_80309E5C.cur].xc && s->x20 != 0) {
        n = fn_802268E8(lbl_803475A8, fn_8000F0A4(0xc));
        fn_80061F58(&n->work, 0x58, 0);
        w = n->work;
        fn_80061F58(&w->x4c, 0x50, 0);
        d = w->x4c;
        d->x26 = s->x22;
        d->x8 = s->x4;
        d->x24 = s->x20;
        d->xa = s->x6;
        d->x28 = s->x24;
        d->xc = s->x8;
        d->x10 = s->xc;
        d->x14 = s->x10;
        d->x0 = *lbl_80309E5C.tbl[lbl_80309E5C.cur].ptrs;
        d->x4 = lbl_80309E5C.tbl[lbl_80309E5C.cur].x10;
    }
}

void fn_8000BF48(Owner_8000BF48* ow) {
    Src_8000BF48* s = ow->src;
    if (s->x0 < lbl_80309E5C.tbl[lbl_80309E5C.cur].xc && s->x14 != 0) {
        Task* o = fn_802268E8(lbl_803475A8, fn_8000F0A4(11));
        Work_8000BF48* w;
        Par_8000BF48* sub;
        fn_80061F58(&o->work, 0x58, 0);
        w = o->work;
        fn_80061F58(&w->x4c, 0x38, 0);
        sub = w->x4c;
        sub->xc = s->x8;
        sub->x10 = s->xc;
        sub->x14 = s->x10;
        sub->x8 = s->x4;
        sub->x18 = s->x14;
    }
}

void fn_8000C9F8(void** out1, void** out2) {
    char name[0x20];

    if (lbl_803098C8.buf[0] == 0) {
        ResHandle* h;
        u32 size;
        sprintf(name, lbl_802ACCC4, lbl_80309E5C.x0);
        h = fn_801CC69C(name);
        size = h->size;
        *out1 = fn_801E1C7C(size);
        fn_801CC608(h, *out1, size);
        fn_801CC65C(h);
    } else {
        fn_801E1DF8(0, lbl_803098C8.buf[0]);
        *out1 = lbl_803098C8.buf[0];
        lbl_803098C8.buf[0] = 0;
    }
    if (lbl_803098C8.buf[1] == 0) {
        ResHandle* h2;
        u32 size2;
        sprintf(name, lbl_802ACCD0, lbl_80309E5C.x0);
        h2 = fn_801CC69C(name);
        size2 = h2->size;
        *out2 = fn_801E1C7C(size2);
        fn_801CC608(h2, *out2, size2);
        fn_801CC65C(h2);
    } else {
        fn_801E1DF8(0, lbl_803098C8.buf[1]);
        *out2 = lbl_803098C8.buf[1];
        lbl_803098C8.buf[1] = 0;
    }
}

void fn_8000CC84(s32 flag) {
    if (flag == 1) {
        lbl_80309E5C.x8 |= 0x01000000;
    } else {
        lbl_80309E5C.x8 &= ~0x01000000;
    }
}

s32 fn_80015828(const char* s);
static inline int FindNamedChr(Task** out) {
    Task* e;
    u8 i;
    for (i = 0; i < 0xe; i++) {
        e = lbl_80309E24[i];
        if (e != 0) {
            ChrWork* w = e->work;
            if (fn_80015828(w->x10->xc) != 0) {
                *out = e;
                return 1;
            }
        }
    }
    return 0;
}

/* The work of the camera task fn_8000D734 runs (its Bounce at 0x4c). */
typedef struct CamTaskWork {
    u8 pad0[0x4C];
    Bounce* move;
} CamTaskWork;
/* What lbl_80309E88[0].f4's work points at. */
typedef struct CamInfo {
    u8 pad0[0x30];
    s16 x30;
    u8 pad32[0x64 - 0x32];
    f32 x64[3];
} CamInfo;
/* lbl_80309E88: four 0x10-byte slots (TblEnt in unit_80055E94.c). */
typedef struct TblEnt_80309E88 {
    void* f0;
    Task* f4;
    u32 f8;
    u8 fc;
    u8 pad[3];
} TblEnt_80309E88;
extern TblEnt_80309E88 lbl_80309E88[4];
extern CamObj* fn_8006B6F4(s32 a);
extern void* fn_8006B6C8(s16 a);
void fn_8000D488(Bounce* o, f32* pos);

void fn_8000D734(Task* t) {
    CamInfo* info;
    Bounce* m;
    CamObj* o;
    CamTaskWork* w;
    Task* h;
    f32 dx, dy, dz;
    if (lbl_80309E5C.x8 & 0x02000000) return;
    w = t->work;
    m = w->move;
    h = lbl_80309E88[0].f4;
    info = h->work;
    switch (t->state) {
    case 0:
        m->cam = fn_8006B6F4(0);
        fn_80071CF0(m->cam->pos, m->b2);
        o = m->cam;
        dx = m->b1[0] - o->pos[0];
        dy = m->b1[1] - o->pos[1];
        dz = m->b1[2] - o->pos[2];
        m->vel[0] = dx / m->steps;
        m->vel[1] = dy / m->steps;
        m->vel[2] = dz / m->steps;
        if (m->mode == 1) {
            fn_80071CF0(m->b1, m->cam->pos);
            m->vel[0] = -1.0f * m->vel[0];
            m->vel[1] = -1.0f * m->vel[1];
            m->vel[2] = -1.0f * m->vel[2];
            m->state = 1;
        } else {
            m->state = 0;
        }
        t->state = 1;
    case 1:
        if (fn_8006B6C8(info->x30) == 0) fn_8000D488(m, info->x64);
        break;
    case 2:
        break;
    case 3:
        t->flags |= 0x40;
        break;
    }
}

void fn_8000F168(NJS_TEXLIST* d) {
    Task* hit;
    if (FindNamedChr(&hit)) {
        ChrWork* w = hit->work;
        d->textures->texaddr = w->x8->textures->texaddr;
    }
}

static inline u32 Pack(u8 r, u8 g, u8 b, u8 a) {
    return (b << 24) | (g << 16) | (r << 8) | a;
}

u32 fn_8000F718(s8 idx, s8 alt, u8* out) {
    f32 tabA[6][3] = {
        {0.231f, 1.0f, 0.655f}, {1.0f, 0.146f, 0.468f}, {0.711f, 0.446f, 1.0f},
        {0.0f, 1.0f, 1.0f}, {1.0f, 1.0f, 0.446f}, {1.0f, 1.0f, 1.0f}
    };
    f32 tabB[6][3] = {
        {0.0f, 0.5f, 0.0f}, {0.5f, 0.0f, 0.0f}, {0.25f, 0.0f, 0.5f},
        {0.0f, 0.5f, 1.0f}, {0.5f, 0.5f, 0.0f}, {0.5f, 0.5f, 0.5f}
    };
    u8 r, g, b, a;
    if (idx > 5) idx = 5;
    if (alt == 0) {
        r = tabA[idx][0] * 255.0f;
        g = tabA[idx][1] * 255.0f;
        b = tabA[idx][2] * 255.0f;
        a = 0x7f;
    } else {
        r = tabB[idx][0] * 255.0f;
        g = tabB[idx][1] * 255.0f;
        b = tabB[idx][2] * 255.0f;
        a = 0x7f;
    }
    if (out != 0) {
        out[1] = r;
        out[2] = g;
        out[3] = b;
    }
    return Pack(r, g, b, a);
}

s32 fn_8000F86C(s32 idx) {
    Task* p = lbl_80347394;
    if (p != 0) {
        SysObj* s = p->work;
        return (s8)s->x5c;
    }
    return lbl_80309DE4[(s8)idx]->x100;
}

void fn_8000F8A4(void* obj, s8 x) {
    s32 v = fn_8000F718(x, 0, 0);
    fn_8000F6F8(obj, 0x40, v, -1, 0);
}

s8 fn_8000FA30(s8 idx) {
    s8 v;
    SysObj* s;
    if (lbl_80347394 == 0) {
        v = lbl_80309DE4[idx]->xb6;
        if (v >= 0 && v < 0x10) {
        } else if (v >= 0x10 && v < 0x20) {
            v = v - 0x10;
        } else if (v >= 0x20 && v < 0x30) {
            v = v - 0x20;
        } else if (v >= 0x30 && v < 0x3a) {
            v = v - 0x30;
        } else if (v >= 0x3a && v < 0x40) {
            v = v - 0x3a;
        } else if (v >= 0x40 && v < 0x47) {
            v = v - 0x40;
        } else if (v == 0x47 || v == 0x48) {
            v = 0x10;
        } else if (v == 0x49) {
            v = 0x11;
        } else {
            v = -1;
        }
        if (v < 0) {
            v = 0;
        }
        if (v > 0x11) {
            v = 0x11;
        }
        return v;
    }
    s = lbl_80347394->work;
    return s->x5a;
}

void fn_80010538(s16 idx) {
    s32 mode = lbl_80309730[idx].mode;
    ChrRec* q;
    if (mode == 0) {
        return;
    }
    if (mode == 4) {
        return;
    }
    q = lbl_80309DE4[idx];
    q->xb4 += q->x8;
}

extern void fn_80011208(s8 a, s8 b, s32 c);
/* What a character record's x110 points at: the counter it applies (fn_80010584). */
typedef struct ChrAux {
    u8 pad0[0x58];
    s8 x58;        /* counter id */
    s8 x59;        /* stat index */
    s8 x5a;        /* threshold */
} ChrAux;
/* lbl_80309174: per-character battle state (0x20). */
typedef struct ChrStat {
    u8 pad[6];
    s16 x6;             /* 0x06 */
    u8 pad8;
    s8 x9;
    u8 pada[0xe - 0xa];
    s8 xe;              /* 0x0e */
    u8 padf[0x20 - 0xf];
} ChrStat;
extern ChrStat lbl_80309174[12];
static inline int Gt(s16 x, int y) { return x > y ? 1 : 0; }

static inline int Roll(ChrRec* p, ChrRec* q, int lim, s16 v)
{
    s16 den;
    s16 num;
    s16 res;
    s16 rnd;
    den = q->x96;
    num = p->x94;
    rnd = rand() % 100;
    if (rnd >= 90) rnd = 100;
    if (rnd < 10) rnd = 0;
    if (den == 0) den = 1;
    res = v / 10.0f * (num * rnd) / den;
    return Gt(res, lim);
}

s8 fn_80010584(s16 a, s16 b)
{
    ChrRec* p = lbl_80309DE4[a];
    ChrRec* q = lbl_80309DE4[b];
    int r = -1;
    int lim;
    s16 num;
    s16 den;
    s16 res;
    s16 rnd;
    s16 v;
    int c;
    s8 k;
    WeaponFx* e;
    ChrAux* t;

    if (b >= 4 && a < 4) {
        k = lbl_802C5790[p->xb6].effect;
        if (k != -1) {
            e = &lbl_802C7A90[k];
            r = e->effect;
            c = Roll(p, q, e->status_rate, q->stat[e->status]);
            if (c == 1) lbl_80309174[b].x9 = r;
            else r = -1;
        }
    } else if (b < 4 && a >= 4) {
        t = p->x110;
        r = t->x58;
        if (r != -1) {
            lim = t->x5a;
            den = q->x96;
            num = p->x94;
            v = q->stat[t->x59];
            rnd = rand() % 100;
            if (rnd >= 90) rnd = 100;
            if (rnd < 10) rnd = 0;
            if (den == 0) den = 1;
            res = v / 10.0f * (num * rnd) / den;
            c = Gt(res, lim);
            if (c == 1) lbl_80309174[b].x9 = r;
            else r = -1;
        }
    }
    if (lbl_80309DE4[b]->bits & 0x40) {
        switch (r) {
        case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10: case 11: case 12: case 13: case 14:
        case 0x1a: case 0x3e: case 0x44: case 0x45: case 0x46: case 0x47: case 0x48: case 0x49:
            r = -1;
        }
    }
    lbl_80309174[b].x9 = r;
    return r;
}

s32 fn_80010B5C(void) {
    return 1;
}

/* What lbl_80347390 points at: its first byte is the level fn_80010CF4 compares with. */
typedef struct Lim_80347390 { u8 v; } Lim_80347390;
extern Lim_80347390* lbl_80347390;
extern s32 lbl_80347344;
extern s32 fn_8025ECC4(void);

extern s8 fn_801EF300(void);

s32 fn_80010B64(s16 a, s16 b) {
    s16 u = lbl_80309DE4[a]->x9a;
    s16 w = lbl_80309DE4[b]->x9c;
    s32 res;
    s16 hit;
    if (b <= 3 && lbl_8030B7F4.party[b] == 0) {
        w += lbl_802C8E54[fn_801EF300()].dodge;
    }
    hit = (100 - u + w) / 2;
    if (fn_8025ECC4() % 101 >= hit) {
        res = 1;
        if (lbl_80309174[a].x6 == 0) {
            if (fn_8025ECC4() % 101 <= lbl_80309DE4[a]->x86) {
                res = 2;
            }
        }
    } else {
        res = 0;
        if (!(lbl_80309DE4[b]->xae & 0x800) || (lbl_80309DE4[b]->bits & 0x4c00)) {
            res = 1;
        }
    }
    return res;
}

void fn_80010CF4(void) {
    s32 a;
    s32 r;
    if (lbl_803097F0.x0 != -1) {
        lbl_80347344 = 1;
        return;
    }
    a = lbl_8030B4D4.x2d5[0];
    r = fn_8025ECC4() % 101;
    if (a == -1) {
        a = lbl_8030B7F4.chr[lbl_8030B7F4.party[0]].xb * 4 + 30 - lbl_80347390->v;
        if (a < 0) {
            a = 0;
        }
        if (a > 30) {
            a = 30;
        }
    }
    if (a > r) {
        lbl_80347344 = 2;
        return;
    }
    a = lbl_8030B4D4.x2d5[1];
    r = fn_8025ECC4() % 101;
    if (a == -1) {
        a = lbl_80347390->v - lbl_8030B7F4.chr[lbl_8030B7F4.party[0]].xb * 4;
        if (a < 0) {
            a = 0;
        }
        if (a > 70) {
            a = 70;
        }
    }
    if (a > r) {
        lbl_80347344 = 0;
        return;
    }
    lbl_80347344 = 1;
}

void fn_80011208(s8 a, s8 b, s32 c) {
    s8 m;
    f32 d;
    f32 r;
    f32 t;
    f32 v;
    f32 n;
    NJS_POINT3 tmp;
    s8 i;
    fn_80071CF0(&lbl_80309EC8.x4c, &tmp);
    m = c;
    for (i = 0; i < 13; i++) {
        Task* u = lbl_80309E24[i];
        ChrWork* q;
        ChrInfo* chr;
        if (u == 0) {
            continue;
        }
        q = u->work;
        chr = q->st;
        if (chr->xf0 & 0x80000000) {
            continue;
        }
        if (chr->id == a) {
            continue;
        }
        if (chr->id == b) {
            continue;
        }
        tmp.y = q->pos.y;
        d = fn_80071E9C(&tmp, &q->pos);
        r = 7.5f;
        if (chr->xec & 0x200000) {
            r *= 3.0f;
        } else {
            r *= 1.5f;
        }
        d -= r;
        if (d < 0.0f) {
            d = 0.0f;
        }
        d = d / 7.5f;
        t = 1.0f - d;
        n = -t;
        if (n < 0.0f) {
            v = chr->draw.a;
            if (v > 3.0f * n) {
                v = 3.0f * n;
            }
            if (v < -1.0f) {
                v = -1.0f;
            }
        } else {
            v = 0.0f;
        }
        if (m != 1) {
            chr->draw.a = v;
        } else if (chr->draw.a > v) {
            chr->draw.a = v;
        }
    }
}

void fn_80011370(s8 a, s8 b)
{
    fn_80011208(a, b, 0);
}


extern int fn_80016B20(s8);
void fn_80014D0C(void);
void fn_80014CFC(void);
void fn_800152A0(void);
extern void SoundLoadStageSamp(void);
extern Task* fn_8003DB34(void* fn);
void fn_80016580(Tk_80016580* t);

inline int HitCached(CamWork* w, CamState* u, f32 xc)
{
    switch (lbl_80309EC8.mv.x19a) {
    case 10:
    case 11:
        if (lbl_80309EC8.mv.x110 == xc && lbl_80309EC8.mv.xc0[0] == w->x38[0] && lbl_80309EC8.mv.xc0[1] == w->x38[1]
            && lbl_80309EC8.mv.xc0[2] == w->x38[2]) {
            u->x8 = lbl_80309EC8.mv.x160;
            return 1;
        }
    }
    return 0;
}

inline void ResetChrs(int idle)
{
    Task** p;
    s8 i;
    for (i = 0, p = lbl_80309E24; i < 14; p++, i++) {
        if (*p != NULL) {
            ChrWork* w = (*p)->work;
            ChrInfo* o = w->st;
            if (!idle || !(o->xf0 & 0x80000000)) {
                o->draw.a = 0.0f;
                o->x1ec |= 0x20000000;
            }
        }
    }
}

extern s32 fn_8025ECC4(void);
s32 fn_800117EC(NJS_POINT3* a, NJS_POINT3* b, f32* out, NJS_POINT3* c);

s32 fn_80011400(s16 id, s8 val)
{
    Task* t;
    ChrWork* w;
    ChrInfo* c;
    t = fn_800215EC(id);
    if (t == NULL) {
        return 0;
    }
    w = t->work;
    c = w->st;
    if (c->x50 & 0x40000) {
        return 0;
    }
    if (c->xf0 & 0x80000000) {
        if (val != 0) {
            c->draw.a = 0.0f;
            c->x1ec |= 0x20000000;
            return 0;
        }
        return 0;
    }
    c->draw.a = 0.0f;
    c->x1ec |= 0x20000000;
    return 1;
}

f32 fn_800114AC(f32* out, f32* w, f32* h, s8 flag) {
    f32 v[3];
    f32 maxx = -500.0f;
    f32 minx = 500.0f;
    f32 maxz = maxx;
    f32 top = 0.0f;
    f32 minz = minx;
    f32 r;
    f32 dx, dz;
    Task* t;
    ChrInfo* c;
    ChrWork* o;
    s16 i;
    for (i = 0; i < 12; i++) {
        t = lbl_80309E24[i];
        if (t == 0) {
            continue;
        }
        o = t->work;
        c = o->st;
        if ((c->xec & 0x100) && fn_80020E10(o->x10->xc) < 0) {
            continue;
        }
        o = t->work;
        if (flag == 0) {
            fn_80071CF0(&o->pos, v);
        } else {
            fn_80071CF0(&c->x13c, v);
        }
        if (c->xec & 0x200000) {
            r = 22.5f;
        } else {
            r = 7.5f;
        }
        if (v[0] + r > maxx) {
            maxx = v[0] + r;
        }
        if (v[0] - r < minx) {
            minx = v[0] - r;
        }
        if (v[2] + r > maxz) {
            maxz = v[2] + r;
        }
        if (v[2] - r < minz) {
            minz = v[2] - r;
        }
        if (top < c->x15c) {
            top = c->x15c;
        }
    }
    dx = maxx - minx;
    if (dx < 0.0f) {
        dx = -1.0f * dx;
    }
    dz = maxz - minz;
    if (dz < 0.0f) {
        dz = -1.0f * dz;
    }
    dx *= 0.5f;
    dz *= 0.5f;
    *w = dx;
    *h = dz;
    out[0] = minx + dx;
    out[2] = minz + dz;
    out[1] = 0.0f;
    return top;
}

f32 fn_80011694(NJS_POINT3* mtx, s16 id, NJS_POINT3* v, s8* out) {
    f32 sum = 0.0f;
    f32 best = 0.0f;
    s8 i;
    ChrWork* q;
    ChrInfo* chr;
    f32 d;
    f32 r;
    *out = -1;
    for (i = 0; i < 12; i++) {
        if (lbl_80309E24[i] != 0) {
            q = lbl_80309E24[i]->work;
            chr = q->st;
            if (!(chr->xf0 & 0x80000000) && chr->id != id && fn_800117EC(mtx, &q->pos, &d, v) != 0) {
                r = 7.5f;
                if (chr->xec & 0x200000) {
                    r *= 3.0f;
                }
                d -= r;
                sum += d;
                if (best <= chr->x15c) {
                    *out = chr->id;
                    best = chr->x15c;
                }
            }
        }
    }
    if (sum == 0.0f) {
        return 5000.0f + 0.000030517578f * fn_8025ECC4();
    }
    return sum;
}

/* A line through o with direction d (fn_8028FEA4). */
typedef struct Line3 {
    NJS_POINT3 o;
    NJS_POINT3 d;
} Line3;
extern void fn_80071B98(NJS_POINT3* a, NJS_POINT3* b, NJS_POINT3* out);
extern f32 fn_8028FEA4(NJS_POINT3* p, Line3* l, NJS_POINT3* out);

s32 fn_800117EC(NJS_POINT3* a, NJS_POINT3* b, f32* out, NJS_POINT3* c) {
    Line3 l;
    NJS_POINT3 pt;
    NJS_POINT3 cl;
    NJS_POINT3 p;
    NJS_POINT3 t;
    s32 rb[3];
    s32 ra[3];
    f32 dist;
    f32 d1;
    f32 d2;
    f32 diff;
    if (c != 0) {
        fn_80071CF0(c, &p);
    } else {
        fn_80071CF0(&lbl_80309EC8.x4c, &p);
    }
    p.y = a->y;
    l.o.x = p.x;
    l.o.y = p.y;
    l.o.z = p.z;
    fn_80071B98(&p, a, &t);
    l.d.x = t.x;
    l.d.y = t.y;
    l.d.z = t.z;
    pt.x = b->x;
    pt.y = b->y;
    pt.z = b->z;
    dist = fn_8028FEA4(&pt, &l, &cl);
    d1 = fn_80071E9C(&p, b);
    d2 = fn_80071E9C(&p, a);
    if (d1 <= d2) {
        fn_80071F84(rb, b, &p);
        fn_80071F84(ra, a, &p);
        d1 = fn_8006116C(rb[1]);
        diff = d1 - fn_8006116C(ra[1]);
        if (diff < 0.0f) {
            diff = -1.0f * diff;
        }
        if (diff < 45.0f) {
            *out = dist;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
    return 1;
}

s32 fn_80011E50(f32* v, f32* out, u8 mode) {
    f32 pos[3];
    f32 c58[3];
    f32 tmp[3];
    f32 ang[3];
    f32 d;
    fn_80071CF0(&lbl_80309EC8.x4c, pos);
    fn_800614FC(lbl_80309EC8.x64, ang);
    fn_80071CF0(&lbl_80309EC8.x58, c58);
    fn_80071CF0(v, tmp);
    switch (mode) {
    case 0:
        tmp[2] = pos[2];
        if (v[0] < 0.0f && pos[0] <= v[0]) {
            *out = -1.0f;
            return 1;
        }
        if (v[0] > 0.0f && pos[0] >= v[0]) {
            *out = -1.0f;
            return 1;
        }
        break;
    case 1:
        tmp[0] = pos[0];
        if (v[2] < 0.0f && pos[2] <= v[2]) {
            *out = -1.0f;
            return 1;
        }
        if (v[2] > 0.0f && pos[2] >= v[2]) {
            *out = -1.0f;
            return 1;
        }
        break;
    }
    tmp[1] = pos[1];
    d = fn_80071E9C(pos, tmp) - 7.5f;
    if (d < 0.0f) {
        d = 0.0001f;
    }
    d = d / 7.5f;
    d = -(1.0f - d);
    if (d < 0.0001f) {
        *out = 3.0f * d;
        return 1;
    }
    return 0;
}

void fn_800121D8(Task* t)
{
    CamWork* w = t->work;
    CamState* u = w->u;
    f32 b, a;
    f32 v[3];
    Task** p;
    s8 i;
    f32 c, d;

    switch (u->state) {
    case 0:
        if (lbl_8030A10C.x6c & 0x20000) {
            return;
        }
        fn_80014AB8(2, 0);
        fn_800114AC(v, &a, &b, 0);
        if (a > b) {
            u->xc = a;
        } else {
            u->xc = b;
        }
        u->xc = 2.0f * u->xc;
        v[1] = 0.0f;
        fn_80071CF0(v, w->x38);
        if (!HitCached(w, u, u->xc)) {
            fn_800608C8(&u->x8);
        }
        u->state = 1;
        break;
    case 1:
        fn_80014D0C();
        fn_80032B4C();
        if (fn_80016B20(2) || fn_80016A18(2)) {
            u->state = 4;
        } else {
            fn_800152A0();
            u->state = 6;
        }
        break;
    case 2:
        ResetChrs(1);
        break;
    case 3:
        fn_80011208(-1, -1, 0);
        break;
    case 4:
        if (!(lbl_8030A10C.x6c & 0x80000000)) {
            if (lbl_8030A10C.x6c & 0x200) {
                return;
            }
            SoundLoadStageSamp();
            u->state = 5;
        }
        break;
    case 5:
        if (!(lbl_8030A10C.x6c & 0x80000000)) {
            fn_80061F58(&fn_8003DB34(fn_80016580)->work, 8, 0);
            u->state = 2;
        }
        break;
    case 6:
        if (!(lbl_8030A10C.x6c & 0x80000000)) {
            SoundLoadStageSamp();
            u->state = 7;
        }
        break;
    case 7:
        if (!(lbl_8030A10C.x6c & 0x80000000)) {
            fn_80014CFC();
            u->state = 3;
        }
        break;
    }
    ResetChrs(0);
    switch (u->state) {
    case 3:
    case 6:
    case 7:
        return;
    }
    d = u->xc;
    c = u->x8;
    lbl_80309EC8.mv.x19a = 11;
    lbl_80309EC8.mv.x110 = d;
    fn_80071CF0(w->x38, lbl_80309EC8.mv.xc0);
    lbl_80309EC8.mv.x160 = c;
    c = u->xc;
    fn_80061C80(w->x20, 0.0f, u->x8, c, 0);
    w->x20[0] = w->x20[0] + w->x38[0];
    w->x20[2] = w->x20[2] + w->x38[2];
    w->x20[1] = c;
    fn_80071F84(w->x2c, w->x38, w->x20);
    u->x8 += 1.0f;
}

extern void fn_8028BB90(void* p);

void fn_80013504(Vec3* obj, Vec3* src, void* p5, f32 a, f32 b) {
    fn_80061C80(obj, 0.0f, b, a, 0);
    obj->x = obj->x + src->x;
    obj->z = obj->z + src->z;
    obj->y = a;
    fn_80071F84(p5, src, obj);
}

/* The view camera fn_800149AC hands to fn_80014808 and fn_8022B960. */
typedef struct ViewCam {
    NJS_POINT3 pos;     /* 0x00 */
    NJS_POINT3 up;      /* 0x0c */
    s16 roll;           /* 0x18 */
    u8 pad1a[6];
    NJS_POINT3 eye;     /* 0x20 */
    s32 ang[3];         /* 0x2c */
    NJS_POINT3 at;      /* 0x38 */
} ViewCam;
extern void fn_801DD460(NJS_POINT3* dst, s32* ang);
extern void fn_801DD334(NJS_POINT3* dir, NJS_POINT3* up, s32* rot);
extern s16 fn_8022BA58(NJS_POINT3* a, NJS_POINT3* b);
extern void fn_8022B960(ViewCam* c);
extern void fn_80291C44(void* m);

void fn_80014808(ViewCam* c, void* m) {
    NJS_POINT3 uv[2];
    NJS_POINT3 v;
    s32 ang[3];
    fn_80071CF0(&c->eye, &v);
    v.x = v.x + lbl_80309EC8.va[0];
    v.y = v.y + lbl_80309EC8.va[1];
    v.z = v.z + lbl_80309EC8.va[2];
    fn_80071CF0(&v, &lbl_80309EC8.x4c);
    fn_80071CF0(&c->at, &lbl_80309EC8.x58);
    ang[0] = c->ang[0];
    ang[1] = c->ang[1];
    ang[2] = c->ang[2];
    {
        s32 ax = 182.04445f * lbl_80309EC8.vb[0];
        s32 ay = 182.04445f * lbl_80309EC8.vb[1];
        ang[0] -= ax;
        ang[1] -= ay;
    }
    fn_800614FC(ang, lbl_80309EC8.x64);
    c->pos.x = v.x;
    c->pos.y = v.y;
    c->pos.z = v.z;
    fn_801DD460(&c->up, ang);
    fn_801DD334(&uv[0], &uv[1], ang);
    c->roll = fn_8022BA58(&uv[0], &uv[1]);
    c->up.x = -c->up.x;
    c->up.y = -c->up.y;
    c->up.z = -c->up.z;
    fn_8022B960(c);
    fn_80291C44(m);
    fn_80286EE8();
    fn_8028B498();
    memset(lbl_80309EC8.va, 0, 12);
    memset(lbl_80309EC8.vb, 0, 12);
}

void fn_80014AB8(u8 kind, SysObj* o) {
    if (o != NULL) {
        fn_8028BB90(o);
    }
    switch (kind) {
    case 0:
        if (lbl_80309EC8.x44 != NULL) {
            lbl_80309EC8.x44->flags |= 0x20000000;
        }
        lbl_80309EC8.x44 = o;
        break;
    case 1:
        if (lbl_80309EC8.x40 != NULL) {
            lbl_80309EC8.x40->flags |= 0x20000000;
        }
        lbl_80309EC8.x40 = o;
        memset(&lbl_80309EC8.mv, 0, sizeof(SysMove));
        break;
    case 2:
        if (lbl_80309EC8.x40 != NULL) {
            lbl_80309EC8.x40->flags |= 0x20000000;
        }
        break;
    }
}

s32 fn_80014CC0(void* obj) {
    u8* p = PTR(PTR(obj, 0x24), 0x4c);
    s16 id = *(s16*)(p + 6);
    switch (id) {
    case 0x1a:
    case 0x1b:
    case 0x1c:
        if (lbl_8034733C == 7) {
            return 1;
        }
        break;
    }
    return 0;
}

extern void fn_800350EC(NJS_TEXLIST* a, u16 dst, NJS_TEXLIST* b, u16 src);
static inline s16 FindSkin(NJS_TEXLIST* l) {
    s16 i;
    for (i = 0; i < l->nbTexture; i++) {
        char* n = l->textures[i].filename;
        if (n[0] == 't' || n[0] == 'T') {
            if (n[1] == 'k' || n[1] == 'K' || n[1] == 'x' || n[1] == 'X') {
                return i;
            }
        }
    }
    return -1;
}
void fn_80014D1C(Task* t, s16 id) {
    ChrWork* w;
    ChrInfo* u;
    NJS_TEXLIST* list;
    NJS_TEXLIST* p;
    s16 i;
    s32 ok;
    s16 val;
    s32 f;
    if (id >= 12) {
        return;
    }
    w = t->work;
    u = w->st;
    if (fn_80017A14(u) == 2) {
        return;
    }
    p = w->x48;
    if (p == 0) {
        ok = 0;
    } else if (p->textures == 0) {
        ok = 0;
    } else if (p->nbTexture <= 1) {
        ok = 0;
    } else {
        ok = 1;
    }
    if (ok == 0) {
        return;
    }
    list = w->x8;
    i = FindSkin(list);
    if (i < 0) {
        return;
    }
    if (id < 0) {
        val = u->anims[u->xe4].xe;
    } else {
        val = id;
    }
    if (lbl_80347394 == 0) {
        if (u->id < 12) {
            f = lbl_80309DE4[u->id]->bits & 0x800;
        } else {
            f = 0;
        }
        if (f != 0 && val == 0) {
            return;
        }
    }
    fn_800350EC(list, i, p, val);
    u->x294 = val;
}

s32 fn_80014EC4(ChrInfo* u)
{
    Task* t;
    ChrWork* w;

    if (u->x48 != u->id) {
        if (!fn_8006D1C4()) {
            return 0;
        }
        t = fn_800215EC(u->x48);
        if (t != NULL) {
            w = t->work;
            return w->st->x134 != 0;
        }
        return 1;
    }
    return 1;
}

s32 fn_800153A0(Pair* p) {
    if (p == 0) {
        return 0;
    }
    if (p->a == 0) {
        return 0;
    }
    return p->b > 1;
}

void fn_8001545C(void) {
}

s32 fn_80015728(void) {
    s16 id;
    ChrInfo *a;
    Task *o;
    s8 i;
    if (fn_8006D1C4() == 0) {
        return 0;
    }
    if (lbl_80347378 != 0) {
        return 0;
    }
    if (lbl_8030A10C.x6c & 0x400) {
        return 0;
    }
    if (fn_8006EDA0() < 0) {
        return 0;
    }
    if (lbl_8034733C == 7) {
        return 0;
    }
    for (i = 0; i < 12; i++) {
        o = lbl_80309E24[i];
        if (o != 0) {
            ChrWork *w = o->work;
            a = w->st;
            id = a->x6;
            if (id == 0xe && a->x134 != 1) {
                return 0;
            }
            if ((a->x50 & 0x40000000) && id != 0xe) {
                return 0;
            }
        }
    }
    return 1;
}

s32 fn_80015828(const char* s) {
    if (s[0] == 'M' || s[0] == 'm') {
        if (s[1] == 'A' || s[1] == 'a') {
            if (s[3] == '1' || s[3] == '2') {
                return 1;
            }
        }
    }
    return 0;
}

extern Vec3_80015A58 lbl_802DB110[];
void fn_8001E4A0(void *a, NJS_POINT3 *v, Task *c);
void fn_80015A58(Vec3_80015A58 *base, s16 n, Vec3_80015A58 *out, f32 ang);

s32 fn_80015880(s8 a, f32 f, NJS_POINT3* b, NJS_POINT3* c) {
    Vec3_80015A58* tbl = lbl_802DB110;
    Vec3_80015A58 v0;
    Vec3_80015A58 v1;
    Task* t = fn_80021658(a);
    ChrWork* w = t->work;
    s8 kind = fn_80020E10(w->x10->xc);
    if (kind < 0) {
        return 0;
    }
    switch (kind) {
    case 0:
    default:
        fn_80015A58(&tbl[12], 4, &v0, f);
        fn_80015A58(&tbl[16], 4, &v1, f);
        break;
    case 1:
        fn_80015A58(&tbl[20], 5, &v0, f);
        fn_80015A58(&tbl[25], 5, &v1, f);
        break;
    case 2:
        fn_80015A58(&tbl[30], 4, &v0, f);
        fn_80015A58(&tbl[34], 4, &v1, f);
        break;
    case 3:
        fn_80015A58(&tbl[38], 4, &v0, f);
        fn_80015A58(&tbl[42], 4, &v1, f);
        break;
    case 4:
        fn_80015A58(&tbl[46], 4, &v0, f);
        fn_80015A58(&tbl[50], 4, &v1, f);
        break;
    case 5:
        fn_80015A58(&tbl[54], 4, &v0, f);
        fn_80015A58(&tbl[58], 4, &v1, f);
        break;
    }
    fn_8001E4A0(&v0, b, t);
    fn_8001E4A0(&v1, c, t);
    return 1;
}

void fn_80017320(void) {
}

extern int fn_800214FC(s8, s16, s8);
static inline s8 PartyChrId(s8 s)
{
    s8 i;
    for (i = 0; i < 12; i++) {
        if (lbl_80309E24[i] != NULL) {
            ChrWork* w = lbl_80309E24[i]->work;
            if (s == fn_80020E10(w->x10->xc)) {
                return w->st->id;
            }
        }
    }
    return -1;
}
static inline int ChrBits(s8 i, u32 mask)
{
    if (i < 12) {
        return lbl_80309DE4[i]->bits & mask;
    }
    return 0;
}
static inline int PartyCanAct(void)
{
    s8 s;
    s8 idx;
    for (s = 0; s < 6; s++) {
        idx = PartyChrId(s);
        if (idx >= 0 && ChrBits(idx, 0xcd80) != 0) {
            return 0;
        }
    }
    return 1;
}
void fn_80017430(s8 sel)
{
    ChrInfo* u;
    f32 ratio;
    s8 c;
    s8 idx;
    s8 s;
    int f;
    s16 hp;
    s16 max;

    f = PartyCanAct();
    for (s = 0; s < 6; s++) {
        idx = PartyChrId(s);
        if (idx >= 0) {
            Task* t = fn_80021658(idx);
            ChrWork* w = t->work;
            u = w->st;
            u->target = u->id;
            if (idx != sel) {
                u->xf0 |= 0x8000;
            } else {
                u->xf0 |= 0x20;
            }
            if (u->xec & 0x100) {
                fn_800214FC(idx, 0xf, idx);
            } else {
                if (f != 0) {
                    hp = lbl_80309DE4[idx]->x14;
                    max = lbl_80309DE4[idx]->x18;
                    ratio = (f32)hp / max;
                    if (ratio >= 0.75f) {
                        c = 1;
                    } else {
                        c = 0;
                    }
                } else if (ChrBits(idx, 0x8000) != 0) {
                    c = 2;
                } else {
                    c = 0;
                }
                fn_800214FC(idx, c + 0x1a, idx);
            }
        }
    }
}

void fn_80017778(void) {
    s8 i;
    for (i = 0; i < 14; i++) {
        Task* t = lbl_80309E24[i];
        if (t != 0) {
            ChrWork* w = t->work;
            w->st->xf0 &= ~0x00400000;
        }
    }
}

extern Task* fn_800215EC(s8);
int fn_800179B4(int a) {
    return fn_800215EC((s8)a) != 0;
}

s32 fn_800179E4(s16 a) {

    return fn_800215EC((s8)a) != 0;
}

extern s32 lbl_80346AB8;
int fn_80018B80(ChrDraw* a);
extern void fn_80036584(void*, int);
extern int fn_8007E264(f32* out, f32 x, f32 z);

void fn_80017CB8(Task* t, s16 idx)
{
    ChrWork* w = t->work;
    ChrInfo* u = w->st;
    f32 f = 0.0f;
    f32 ground;
    DrawState s;

    fn_80299040(w->x8);
    u->xea = idx;
    f = u->draw.a;
    njPushMatrixEx();
    fn_80286EE8();
    fn_8028B498();
    if (fn_80018B80(&u->draw)) {
        njTranslate(0, w->pos.x, w->pos.y, w->pos.z);
        njRotateXYZ(0, w->rx, w->ry, w->rz);
        njScale(0, w->scl.x, w->scl.y, w->scl.z);
        lbl_80346AB8 = fn_80035908();
        switch (w->x14) {
        case 0x4d:
            fn_80035910(0x8000);
            break;
        case 0x2f:
        case 0x76:
            fn_80035910(0x20000000);
            break;
        }
        if (u->x5c != NULL) {
            if (u->x60 != NULL) {
                if (f > -1.0f) {
                    fn_800353F4(u->x154, u->x5c, u->x60, u->x68, w->x44);
                }
            } else {
                if ((u->anims[idx].flags & 0x200000) || (u->anims[u->xe8].flags & 0x200000)) {
                    if (f > -1.0f) {
                        fn_8003529C(u->x154, u->x5c, u->x68, w->x44);
                    }
                } else {
                    if (f > -1.0f) {
                        fn_80035380(u->x154, u->x5c, u->x68, w->x44);
                    }
                }
                if (u->xec & 0x2000000) {
                    fn_80036584(t, -1);
                    DrawStateDefault2D(&s);
                    fn_8007E678(u->x154, &s);
                    s.colour.a = -0.8f;
                    if (DrawStatePush(&s)) {
                        fn_80035380(u->x154, u->x5c, u->x68, w->x44);
                        DrawStatePop(&s);
                    }
                }
            }
            if (!(u->xec & 0x20000000) || (u->xec & 0x10000000)) {
                u->x68 += u->anims[idx].x14;
            }
            if ((u->xec & 0x20000000) && (u->xec & 0x8000000)) {
                if (u->x68 >= u->anims[idx].x14) {
                    u->x68 -= u->anims[idx].x14;
                }
            }
            if (u->x68 > (f32)u->x5c->x4 - 1.0f) {
                if (u->anims[idx].flags & 0x8000000) {
                    u->x68 = (f32)u->x5c->x4 - 1.0f;
                } else {
                    u->x68 = 0.0f;
                }
                u->x70 = 1;
            }
            if (u->anims[idx].flags & 0x800000) {
                u->x70 = 1;
            }
        } else {
            fn_80035140(u->x154, w->x44);
            u->x70 = 1;
        }
        fn_8007E264(&ground, w->pos.x, w->pos.z);
        if (u->xec & 0x200) {
            if (ground > w->pos.y) {
                w->pos.y = ground;
            }
        } else {
            w->pos.y = ground;
        }
        switch (w->x14) {
        case 0x4d:
        case 0x2f:
        case 0x76:
            fn_80035910(lbl_80346AB8);
            break;
        }
        DrawStatePop(0);
        fn_800D2048();
    }
    njPopMatrixEx();
    if (u->x70 != 0 && (u->xec & 1)) {
        u->xec &= ~1;
        fn_80075F2C(t);
    }
}

extern void fn_80060950(void*);

int fn_8001FABC(Task* t);

void fn_80018084(Task* t)
{
    Work_80019D7C* w = t->work;
    Inner_80019D7C* u = w->in;
    switch (u->x12) {
    case 0: {
        Obj_80019D7C* o;
        fn_8001FABC(t);
        o = fn_802268E8(lbl_803475A8, fn_80019B70);
        fn_80061F58(&o->blk, 0x18, 0);
        o->blk->a = t;
        o->blk->b = t;
        o->blk->c = 30;
        o->blk->x12 = 2;
        o->blk->d = 30;
        o->blk->x14 = 3;
        o->blk->x10 = 30;
        o->blk->x16 = 4;
        u->x12 = 1;
        break;
    }
    case 1:
    default:
        break;
    }
    fn_80018CBC(t, u->xe8, 0, 0, u->x2);
}

s32 fn_80020060(ChrAnim* p);
s32 fn_80017018(s8 idx);
extern void fn_8001712C(s8 k, void *p);

extern s32 fn_80060B98(void*, void*, void*, f32*);

s32 fn_80018178(void* a, void* b, void* c, s8* list) {
    s32 cnt;
    s8 i;
    s8 v;
    s8 j;
    s8 k;
    f32 pos[3];
    cnt = 0;
    for (i = 0; i < 14; i++) {
        list[i] = -1;
    }
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            v = lbl_8030A10C.x14[j][i];
            if (v >= 0) {
                pos[0] = 15.0f * j + 7.5f - 67.5f;
                pos[2] = 15.0f * i + 7.5f - 67.5f;
                pos[1] = 0.0f;
                if (fn_80060B98(a, b, c, pos) != 0) {
                    for (k = 0; k < 14; k++) {
                        if (list[k] < 0) {
                            list[k] = v;
                            cnt++;
                            break;
                        }
                        if (v == list[k]) break;
                    }
                }
            }
        }
    }
    return cnt;
}

void fn_80018700(s8 id) {
    s16 i;
    s16 j;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            s8 v = lbl_8030A10C.x14[i][j];
            if (v == id) {
                lbl_8030A10C.x14[i][j] = -1;
            }
        }
    }
}

void fn_80018798(Task *t)
{
    ChrWork *w = t->work;
    ChrInfo *d = w->st;
    ChrAnim *tbl = d->anims;
    s16 idx;
    s16 idx2;
    f32 f;
    idx = fn_80020060(tbl);
    d->x128 = tbl[idx].x14;
    d->x12c = lbl_8030A10C.xec * tbl[idx].x10;
    idx2 = fn_80020094(w, 1, -1, 1);
    f = tbl[idx2].x10;
    if (f) {
        d->x130 = lbl_8030A10C.xec * f;
    } else {
        d->x130 = d->x12c;
    }
    fn_8001712C(d->id, &d->x15c);
    fn_80017018(d->id);
}

void fn_80018AFC(void* t, ChrInfo* u, ChrWork* w)
{
    DrawState s;

    fn_80036584(t, -1);
    DrawStateDefault2D(&s);
    fn_8007E678(u->x154, &s);
    s.colour.a = -0.8f;
    if (DrawStatePush(&s)) {
        fn_80035380(u->x154, u->x5c, u->x68, w->x44);
        DrawStatePop(&s);
    }
}

int fn_80018B80(ChrDraw* a) {
    DrawState s;
    DrawStateGet(&s);
    s.control3d |= 0x800;
    s.colour.a = a->a;
    s.colour.r = a->r;
    s.colour.g = a->g;
    s.colour.b = a->b;
    if (lbl_80347394 != 0) {
        s.attr_and &= ~0x700;
    } else {
        s.attr_and &= ~0x700;
    }
    if (a->a < 0.0f) {
        s.attr_or |= 0x800;
    } else {
        s.attr_and &= ~0x500;
    }
    if (a->x28 != 1) {
        s.control3d &= ~0x40;
    }
    s.blend_src = a->blend_src;
    s.blend_dst = a->blend_dst;
    s.fog = a->fog;
    if (!DrawStatePush(&s)) {
        return 0;
    }
    if (a->x30 != 0) {
        fn_80060950(a);
    }
    return 1;
}

void fn_80019E44(Task* t) {
    Work_80019D7C* w = t->work;
    Inner_80019D7C* in = w->in;
    switch (in->x12) {
    case 0: {
        Obj_80019D7C* o = fn_802268E8(lbl_803475A8, fn_80019B70);
        fn_80061F58(&o->blk, 0x18, 0);
        o->blk->a = t;
        o->blk->b = t;
        o->blk->c = 11;
        o->blk->d = 4;
        in->x12 = 1;
        break;
    }
    case 1:
        break;
    }
    fn_80018CBC(t, in->xe8, 0, 0, in->x2);
}

s32 fn_8001BBF8(void* obj) {
    u8* p = PTR(PTR(obj, 0x24), 0x4c);
    s16 id = *(s16*)(p + 0x10);
    switch (id) {
    case 0x10:
    case 0x17:
    case 0x1d:
        return 0;
    default:
        return 1;
    }
}


s32 fn_8001C1F0(Task* o)
{
    ChrWork* cw = o->work;
    ChrInfo* w = cw->st;
    switch (w->x6) {
    default:
        if ((w->xf0 & 4) && fn_80014C90(w->id, 4) != 0 && fn_80014C90(w->id, 0x800000) != 0) {
            return 1;
        }
        return 0;
    case 9:
    case 10:
        if (fn_80014C90(w->id, 4) != 0 && fn_80014C90(w->id, 0x800000) != 0) {
            return 1;
        }
        return 0;
    case 11:
    case 32:
        if (fn_80014C90(w->id, 4) != 0 && fn_80014C90(w->id, 0x800000) != 0) {
            switch (w->x4a) {
            case 4:
            case 5:
            case 8:
                return 1;
            default:
                return 0;
            }
        }
        return 0;
    }
}

void fn_8001DD00(ChrInfo* o, s8 v) {
    s8 i;
    s8 j;
    s8 val;
    switch (o->x6) {
    case 0x20:
    case 0xb:
        if (v <= 3) {
            val = 0x12;
        }
        break;
    default:
        val = v;
        break;
    }
    for (i = 0; i < 10; i++) {
        if (o->x28[i] < 0) {
            o->x28[i] = val;
            break;
        }
    }
    if (i == 10) {
        for (j = 0; j < 9; j++) {
            o->x28[j] = o->x28[j + 1];
        }
        o->x28[j] = val;
    }
}

static inline Task *FindChrId(s8 id) {
    s8 i;
    for (i = 0; i < 14; i++) {
        Task *t = lbl_80309E24[i];
        if (t != 0) {
            ChrWork *w = t->work;
            if (w->st->id == id) {
                return lbl_80309E24[i];
            }
        }
    }
    return 0;
}

void fn_8001E5C8(Angle *v, s8 id) {
    Task *t = FindChrId(id);
    ChrWork *w;
    t = t != NULL ? t : FindChrId(0);
    if (t == NULL) {
        v[0] = 0;
        v[1] = 0;
        v[2] = 0;
    }
    w = t->work;
    fn_800614FC(&w->rx, v);
}

void fn_8001E6DC(V3 *out, s8 id) {
    Task *t = FindChrId(id);
    t = t ? t : FindChrId(0);
    if (t == 0) {
        out->x = 0.0f;
        out->y = 0.0f;
        out->z = 0.0f;
    } else {
        ChrWork *w = t->work;
        fn_80071CF0(&w->st->x13c, out);
    }
}

/* The character task with this id, or else the one with id 0. */
static inline Task* FindChrIdOr0(s8 idx)
{
    Task* t = FindChrId(idx);
    if (t != NULL) {
        return t;
    }
    return FindChrId(0);
}

void fn_8001E7F8(f32* out, s8 idx)
{
    Task* t = FindChrIdOr0(idx);
    if (t == NULL) {
        out[0] = 0.0f;
        out[1] = 0.0f;
        out[2] = 0.0f;
    } else {
        ChrWork* w = t->work;
        fn_80071CF0(&w->pos, out);
    }
}

s32 fn_8001EB6C(void* obj) {
    s16 type = *(s16*)((u8*)obj + 6);
    switch (type) {
    case 4:
    case 5:
    case 8:
    case 15:
    case 24:
        return 1;
    default:
        return 0;
    }
}

void fn_80007280(s32 a, s32 b, s32 c)
{
    fn_802A9B94(a, b, c, fn_8028AB48);
}

void fn_80007514(s32 **a, s32 *b)
{
    *b = lbl_803478A0;
    *a = lbl_803478A4;
}

s32 fn_80008258(s32 *out)
{
    u32 n = *(u32 *)(lbl_803478DC + 0x34);
    *out = (n + 0x1f) & ~0x1fu;
    return 1;
}

void fn_80008308(Task* a, Ent_80008800* b)
{
    fn_8000832C(a, b, 0);
}

void fn_80008694(Task* a, s16 b, s16 c, Ent_80008800* d)
{
    fn_800086BC(a, b, c, d, 0, 0);
}

void fn_80008DE4(s16 v)
{
    lbl_8030A10C.xf0 = v;
}

void fn_80009860(void *v, Ent_80009860 *e)
{
    if (e->id < 0) return;
    e->ptr = v;
}

void fn_80009FBC(void *p)
{
    Task *t = p;
    if (t->state == 0xff) t->flags |= 0x40;
}

void fn_8000A38C(void)
{
    if (lbl_80346AA4 != NULL) lbl_80346AA4[0x19] = 3;
}

TaskFn fn_8000F0A4(s16 i)
{
    return lbl_802DAFA8[i];
}

s16 fn_80010CBC(s16 i)
{
    s8 k = lbl_8030B7F4.party[i];
    return lbl_8030B7F4.chr[k].x1c;
}

s32 fn_80010CE4(u8 *a, u8 *b)
{
    return *(s32 *)(a + 4) - *(s32 *)(b + 4);
}

void fn_800120D0(s32 *a)
{
    fn_800614FC(lbl_80309EC8.x64, a);
}

void fn_80012100(void *a)
{
    fn_80071CF0(&lbl_80309EC8.x58, a);
}

s32 fn_80012F24(s32 idx)
{
    u8 *p = (u8 *)fn_80021658((s8)idx);
    u8 *q = *(u8 **)(p + 0x24);
    u8 *r = *(u8 **)(q + 0x4c);
    u32 v = *(u32 *)(r + 0xec);
    return (v >> 21) & 1;
}

void fn_80014CFC(void)
{
    lbl_80347378 &= ~0xf;
}

void fn_80014D0C(void)
{
    lbl_80347378 |= 0xf;
}

s32 fn_8001552C(u8 *p)
{
    u32 v = *(u32 *)(p + 0xec);
    if (v & 0x20) return 1;
    else return (v & 0x40) ? 2 : 0;
}

void fn_80015554(void)
{
    if (!(lbl_803472F4 & 0x8000)) fn_80015580();
}

void fn_8001C31C(Tk_8001C31C* t) {
    Unit* u = t->work->w;
    u->xec &= ~0x60;
    u->xf0 &= ~0x04000000;
    u->xf4 = 0;
}

void fn_8001C7B8(void* a, void* b, void* c) {
    Vec3 v;
    fn_8001C6CC(a, b, c, &v);
    fn_8006C860("/BEFF/", &v);
}

void fn_8001D1D8(Tk_8001D1D8* t, void *v) {
    fn_80071CF0((u8*)t->work + 0x1C, v);
}

s32 fn_80020060(ChrAnim* p) {
    s32 i = 0;
    for (;;) {
        if (p->x2 == 3) break;
        if (p->x2 == 0) return i;
        p++;
        i++;
    }
    return -1;
}

void fn_8000E0D8(E0D8Obj *obj) {
    E0D8Anim *a;
    void *p;
    p = obj->inner->p0;
    a = obj->inner->anim;
    if (p == 0) {
        obj->state = 3;
    }
    switch (obj->state) {
    case 0:
        if (a->cur >= a->end) {
            obj->state = 1;
            a->val = *(u32 *)((u8 *)p + 4);
        } else {
            a->cur = a->cur + 1;
        }
        break;
    case 1:
        fn_80230634(p, a->mat);
        fn_80230280(p, a->mat);
        obj->state = 2;
        break;
    case 2:
        if (a->sub >= 0 && fn_800179E4(a->sub) == 0) {
            obj->state = 3;
        }
        fn_8000B320((f32)a->cur, p, a->mat);
        a->cur += 1.0f;
        break;
    case 3:
        if (a->p20 != 0) {
            fn_801E17E0(a->p20);
        }
        if (a->p2c != 0) {
            fn_801E17E0(a->p2c);
        }
        obj->flags |= 0x40;
        break;
    }
}

extern s32 fn_8022E734(u8 kind, void* p, void* a, void* b, s32 f1, s32 f2, s32 f3);
extern void fn_8022E4CC(HNode* o, s32 a, s32 b, s32 c, s32 d, s32 e);
void fn_8000F2A0(HNode* n, u8 kind, s32 a, s32 b, s32 c);

static inline void visit(HNode* n, u8 kind, s32 a, s32 b, s32 c) {
    s32 s0 = 0, s1;
    if (fn_8022E734(kind, n, &s0, &s1, 1, 0, 0)) {
        fn_8022E4CC(n, a, b, c, 0, 0);
        fn_8022E4CC(n, a, b, c, 1, 0);
    }
}

static inline void walk0(HNode* n, u8 kind, s32 a, s32 b, s32 c) {
    visit(n, kind, a, b, c);
    if (n->child != 0) {
        fn_8000F2A0(n->child, kind, a, b, c);
    }
    if (n->sibling != 0) {
        fn_8000F2A0(n->sibling, kind, a, b, c);
    }
}

static inline void walk1(HNode* n, u8 kind, s32 a, s32 b, s32 c) {
    visit(n, kind, a, b, c);
    if (n->child != 0) {
        walk0(n->child, kind, a, b, c);
    }
    if (n->sibling != 0) {
        walk0(n->sibling, kind, a, b, c);
    }
}

void fn_8000F2A0(HNode* n, u8 kind, s32 a, s32 b, s32 c) {
    s32 s0 = 0, s1;
    if (fn_8022E734(kind, n, &s0, &s1, 1, 0, 0)) {
        fn_8022E4CC(n, a, b, c, 0, 0);
        fn_8022E4CC(n, a, b, c, 1, 0);
    }
    if (n->child != 0) {
        walk1(n->child, kind, a, b, c);
    }
    if (n->sibling != 0) {
        walk1(n->sibling, kind, a, b, c);
    }
}

void fn_8000F6F8(HNode* n, u8 kind, s32 a, s32 b, s32 c) {
    fn_8000F2A0(n, kind, a, b, c);
}

void fn_80018764(Tk* t, f32* a, f32* b) {
    s16 i;
    if (t == NULL) {
        return;
    }
    i = t->work->id;
    *a = lbl_803097F0.ent[i].x4;
    *b = lbl_803097F0.ent[i].x8;
}

void fn_80012020(f32 *v)
{
    f32 x;
    x = v[0];
    if (x) lbl_80309EC8.vb[0] = x;
    x = v[1];
    if (x) lbl_80309EC8.vb[1] = x;
    x = v[2];
    if (x) lbl_80309EC8.vb[2] = x;
}

s32 fn_80018498(f32 *v)
{
    if (v[0] > 67.5f) return 0;
    if (v[0] < -67.5f) return 0;
    if (v[2] > 67.5f) return 0;
    return !(v[2] < -67.5f);
}

s32 fn_80014F50(Obj *o)
{
    switch (lbl_80309730[o->inner->work->idx].mode) {
    case 0:
        return 0;
    default:
        return 1;
    }
}

void fn_8000E664(Tk_8000E664* t)
{
    W* w = t->work;
    U* u = w->u;
    DrawState s;
    int ok;
    int saved;

    switch (t->state) {
    case 0:
        t->state = 1;
        u->xc = 0.0f;
        break;
    case 1:
        t->state = 2;
        break;
    default:
        DrawStateDefault2D(&s);
        w->x44 = 2;
        s.control3d |= 0x800;
        s.attr_or |= 0x300;
        if (u->x10 != 0.0f) {
            s.attr_or |= 0x800;
        }
        ok = fn_8000CCBC(t, 0);
        s.colour.a = u->x10;
        s.colour.r = u->x14;
        s.colour.g = u->x18;
        s.colour.b = u->x1c;
        if (!(lbl_80309E5C.x8 & 0x1000000)) {
            if (lbl_80309E5C.x8 & 0x8000000) {
                u->x40 = 1;
                u->x44 = lbl_80309E5C.x18;
                u->x48 = lbl_80309E5C.x1c;
            } else {
                u->x40 = 0;
                u->x48 = 0.0f;
            }
            if (u->x50 & 0x40000000) {
                if (0.0f == u->x10) {
                    if (u->x50 & 0x20000000) {
                        fn_8000B77C(u->x4c, w->x0);
                        u->x50 &= ~0x20000000;
                    }
                } else if (u->x10 < 0.0f && u->x10 > -1.0f) {
                    fn_8000B77C(u->x4c, w->x0);
                    u->x50 |= 0x20000000;
                }
            }
        }
        if (u->x10 <= -1.0f) {
            ok = 0;
        }
        if (u->x40 != 0 && ok == 1) {
            fn_80060950(&u->x10);
        }
        if (ok == 1) {
            if (DrawStatePush(&s)) {
                saved = fn_80035908();
                fn_8000F0BC();
                fn_80299040(w->x8);
                if (w->x18 == 6) {
                    fn_8000B6F0(w);
                } else if (w->x18 == 8) {
                    if (lbl_80309E5C.x0 == 6) {
                        fn_80035910(0x5000);
                    }
                    fn_8000B5F4(w, u->x0);
                    u->x0 += 1.0f;
                    if (u->x0 >= (f32)w->xc->x4) {
                        u->x0 = u->x0 - (f32)w->xc->x4;
                    }
                } else if (w->x18 == 0x10) {
                    fn_8000B5F4(w, u->x0);
                    if (u->x0 < (f32)w->xc->x4 - 1.0f) {
                        u->x0 += 1.0f;
                    }
                }
                fn_80035910(saved);
                DrawStatePop(&s);
            }
        }
        break;
    }
    fn_800D2048();
}

void fn_8000EDE4(Tk_8000EDE4* t)
{
    W* w = t->work;
    U* u = w->u;
    DrawState s;
    int ok;
    int saved;
    u8 flag = 0;

    switch (t->state) {
    case 0:
        t->state = 1;
        u->xc = 0.0f;
        break;
    case 1:
        t->state = 2;
        break;
    default:
        DrawStateDefault2D(&s);
        s.control3d |= 0x800;
        if (w->x44 == 2) {
            flag = 1;
            s.attr_or |= 0x200;
            if (u->x10 != 0.0f) {
                s.attr_or |= 0x800;
            }
            w->x44 = 0;
        } else {
            s.attr_and &= ~0x700;
            if (u->x10 != 0.0f) {
                s.attr_or |= 0x800;
            }
        }
        ok = fn_8000CCBC((void *)(t), 0);
        if (!(lbl_80309E5C.x8 & 0x1000000)) {
            if (lbl_80309E5C.x8 & 0x8000000) {
                u->x40 = 1;
                u->x44 = lbl_80309E5C.x18;
                u->x48 = lbl_80309E5C.x1c;
            } else {
                u->x40 = 0;
                u->x48 = 0.0f;
            }
        }
        s.colour.a = u->x10;
        s.colour.r = u->x14;
        s.colour.g = u->x18;
        s.colour.b = u->x1c;
        if (u->x10 <= -1.0f) {
            ok = 0;
        }
        if (u->x40 != 0 && ok == 1) {
            fn_80060950(&u->x10);
        }
        saved = fn_80035908();
        fn_8000F0BC();
        if (ok == 1) {
            if (DrawStatePush(&s)) {
                fn_80299040(w->x8);
                if (w->x18 == 1) {
                    fn_8000B6F0(w);
                } else if (w->x18 == 7) {
                    fn_8000B5F4(w, u->x0);
                    u->x0 += 1.0f;
                    if (u->x0 >= (f32)w->xc->x4) {
                        u->x0 = u->x0 - (f32)w->xc->x4;
                    }
                } else if (w->x18 == 0xf) {
                    fn_8000B5F4(w, u->x0);
                    if (u->x0 < (f32)w->xc->x4 - 1.0f) {
                        u->x0 += 1.0f;
                    }
                }
                DrawStatePop(&s);
            }
        }
        fn_80035910(saved);
        fn_800D2048();
        if (flag == 1) {
            w->x44 = 2;
        }
        break;
    }
}

void fn_80016580(Tk_80016580* t)
{
    W_80016580* w = t->work.v;
    s8 k;

    lbl_80347378 |= 1;
    lbl_80347378 |= 2;
    lbl_80347378 |= 4;
    lbl_80347378 |= 8;
    switch (t->state) {
    case 0:
        t->state = 0x14;
        break;
    case 20:
        if (fn_80016A18(0)) {
            fn_80015138(0);
            w->x0 = 0x78;
        } else {
            w->x0 = 0;
        }
        t->state = 0x15;
        break;
    case 21:
        if (w->x0 == 0) {
            if (fn_80016A18(1)) {
                fn_80032B4C();
                fn_80015138(1);
                w->x0 = 0x78;
            }
            t->state = 0x16;
        } else {
            w->x0--;
        }
        break;
    case 22:
        if (w->x0 == 0) {
            t->state = 1;
        } else {
            w->x0--;
        }
        break;
    case 1:
        if (fn_800168D8(0x40000, w, 0)) {
            t->state = 2;
            w->x4 |= 0x80000000;
        } else {
            t->state = 3;
        }
        break;
    case 2:
        if (!(w->x4 & 0x80000000)) {
            t->state = 3;
        }
        break;
    case 3:
        if (fn_800168D8(0x80, w, 0)) {
            t->state = 4;
            w->x4 |= 0x80000000;
        } else {
            t->state = 5;
        }
        break;
    case 4:
        if (!(w->x4 & 0x80000000)) {
            t->state = 5;
        }
        break;
    case 5:
        if (fn_800168D8(0x40000, w, 1)) {
            t->state = 6;
            w->x4 |= 0x80000000;
        } else {
            t->state = 7;
        }
        break;
    case 6:
        if (!(w->x4 & 0x80000000)) {
            t->state = 7;
        }
        break;
    case 7:
        if (fn_800168D8(0x80, w, 1)) {
            t->state = 8;
            w->x4 |= 0x80000000;
        } else {
            t->state = 9;
        }
        break;
    case 8:
        if (!(w->x4 & 0x80000000)) {
            t->state = 9;
        }
        break;
    case 9:
        lbl_80347378 &= ~1;
        lbl_80347378 &= ~2;
        lbl_80347378 &= ~4;
        lbl_80347378 &= ~8;
        for (k = 0; k < 12; k++) {
            Tk_80016580* o = ((Tk_80016580*)fn_800215EC(k));
            if (o != NULL && !(o->work.uw->w->x50 & 0x1000000)) {
                o = ((Tk_80016580*)fn_800215EC(k));
                if (o != NULL) {
                    Unit_80016580* u = o->work.uw->w;
                    if (u->x1dc != NULL) {
                        u->x44 = ((Chr**)lbl_80309DE4)[u->id]->x1c;
                    }
                }
            }
        }
        t->flags |= 0x40;
        lbl_8030A10C.x1c4 -= 1;
        break;
    }
}

void fn_80018868(Tk_80018868* t, s8 mode, f32 frame)
{
    W_80018868* w;
    U_80018868* u;
    void* x0;
    DrawState s;
    u16 a;
    u16 b;

    if (mode >= 0) {
        w = t->work;
        u = w->u;
        x0 = w->x0;
        DrawStateDefault2D(&s);
        fn_8007E678(u->x154, &s);
        s.colour.a = u->x264;
        s.control3d |= 0x8000;
        switch (lbl_80346ABD) {
        case 0:
        default:
            a = 0;
            break;
        case 1: a = 0x800; break;
        case 2: a = 0x1000; break;
        case 3: a = 0x1800; break;
        case 4: a = 0x2000; break;
        case 5: a = 0x2800; break;
        case 6: a = 0x3000; break;
        case 7: a = 0x3800; break;
        }
        switch (lbl_80346ABC) {
        case 0:
        default:
            b = 0;
            break;
        case 1: b = 0x100; break;
        case 2: b = 0x200; break;
        case 3: b = 0x300; break;
        case 4: b = 0x400; break;
        case 5: b = 0x500; break;
        case 6: b = 0x600; break;
        case 7: b = 0x700; break;
        }
        fn_8029D008(b | a);
        if (DrawStatePush(&s)) {
            njTranslate(0, u->x274, u->x278, u->x27c);
            switch (u->x28c) {
            case 0:
            case 1:
                njRotateY(0, u->x284);
                njRotateZ(0, u->x288);
                break;
            case 3:
            case 4:
                njRotateX(0, u->x280);
                break;
            }
            njScale(0, u->x268, u->x26c, u->x270);
            switch (mode) {
            case 0:
                fn_80035468(x0, u->x74, u->x84, 1, frame);
                break;
            case 1:
                fn_80035228(x0, u->x74, 1, frame);
                break;
            case 2:
                fn_800353F4(x0, u->x5c, u->x60, frame, 1);
                break;
            case 4:
                fn_8003529C(x0, u->x5c, frame, 1);
                break;
            case 3:
                fn_80035380(x0, u->x5c, frame, 1);
                break;
            }
            DrawStatePop(&s);
        }
    }
}

inline int Match(Tk_8001CED0* t, Unit_8001CED0* u)
{
    s16 a;
    s16 b;
    s16 x;
    s16 y;

    if (u->xec & 0x8000) {
        a = u->x14;
        b = u->x16;
    } else {
        a = u->x6;
        b = u->x8;
    }
    switch (u->x20c) {
    case 0x1d:
        if (fn_800153E0(0x1d, u->x20e) != 0) {
            return 1;
        }
    }
    if (a != 0x18) {
        return 0;
    }
    x = fn_800760EC(t, 0x15, -1);
    y = fn_800760EC(t, a, b);
    if (x == y) {
        return 1;
    }
    return 0;
}

inline int Kind(Unit_8001CED0* u)
{
    switch (u->x10) {
    case 0x10:
    case 0x17:
    case 0x1d:
        return 0;
    }
    return 1;
}


inline int Both(Tk_8001CED0* t)
{
    Unit_8001CED0* u2 = t->work->w;
    if (!Kind(u2)) {
        return 0;
    }
    return Match(t, u2);
}

int fn_8001CED0(Tk_8001CED0* t)
{
    u32 flags = 0;
    Unit_8001CED0* u = t->work->w;
    s8 r;
    s16 a;
    s16 b;
    Unit_8001CED0* u2;

    r = fn_8002EEFC(t, &flags);
    if (!Kind(t->work->w)) {
        flags &= ~0x20000000;
    }
    if (r == 2) {
        r = 1;
    }
    if (fn_80030AE8(flags, u) && Both(t)) {
        u2 = t->work->w;
        if (u2->xec & 0x8000) {
            a = u2->x14;
            b = u2->x16;
        } else {
            a = u2->x6;
            b = u2->x8;
        }
        if (fn_80009030(lbl_8030A10C.x10, a, b, -1, -1)) {
            fn_800312F0(t, a, b, r);
            u->xec &= ~0x8000;
        }
    } else {
        u2 = t->work->w;
        if (u2->xec & 0x8000) {
            a = u2->x14;
            b = u2->x16;
        } else {
            a = u2->x6;
            b = u2->x8;
        }
        if (fn_80009030(lbl_8030A10C.x10, a, b, -1, -1)) {
            fn_80031254(t);
            u->xec |= 0x80000;
        }
    }
}

void fn_8000D488(Bounce* o, f32* pos)
{
    s16 axis = 0;
    int hit;

    pos[0] += o->vel[0];
    pos[1] += o->vel[1];
    pos[2] += o->vel[2];
    if (o->vel[0] != 0.0f) {
        axis = 0;
    } else if (o->vel[1] != 0.0f) {
        axis = 1;
    } else if (o->vel[2] != 0.0f) {
        axis = 2;
    }
    switch (o->mode) {
    case 0:
        if (o->vel[axis] >= 0.0f) {
            if (pos[axis] >= o->b1[axis]) {
                fn_80071CF0(o->b2, pos);
            }
        } else if (pos[axis] <= o->b1[axis]) {
            fn_80071CF0(o->b2, pos);
        }
        break;
    case 1:
        if (o->vel[axis] >= 0.0f) {
            if (pos[axis] >= o->b2[axis]) {
                fn_80071CF0(o->b1, pos);
            }
        } else if (pos[axis] <= o->b2[axis]) {
            fn_80071CF0(o->b1, pos);
        }
        break;
    case 2:
        hit = 0;
        if (o->state == 0) {
            if (o->vel[axis] >= 0.0f) {
                if (pos[axis] >= o->b1[axis]) {
                    fn_80071CF0(o->b1, pos);
                    hit = 1;
                    o->state = 1;
                }
            } else if (pos[axis] <= o->b1[axis]) {
                fn_80071CF0(o->b1, pos);
                hit = 1;
                o->state = 1;
            }
        } else {
            if (o->vel[axis] >= 0.0f) {
                if (pos[axis] >= o->b2[axis]) {
                    fn_80071CF0(o->b2, pos);
                    hit = 1;
                    o->state = 0;
                }
            } else if (pos[axis] <= o->b2[axis]) {
                fn_80071CF0(o->b2, pos);
                hit = 1;
                o->state = 0;
            }
        }
        if (hit == 1) {
            o->vel[0] = -1.0f * o->vel[0];
            o->vel[1] = -1.0f * o->vel[1];
            o->vel[2] = -1.0f * o->vel[2];
        }
        break;
    }
}

void fn_8000D8FC(Tk_8000D8FC* t)
{
    U_8000D8FC* u = t->work->w;
    N0* n = u->x0;
    Nd* a = (Nd*)n->x0;
    Nd* c = a->x2c->x2c;
    Q4* e = c->x4->x0;
    s32 ang[3];
    f32 tmp[3];
    int k;

    if (a == NULL) {
        t->state = 3;
    }
    switch (t->state) {
    case 0:
        for (k = 0; k < 3; k++) {
            tmp[k] = ((Nd*)n->x0)->x2c->x2c->v[k] + (((Nd*)n->x0)->x2c->v[k] + (n->x1c[k] + ((Nd*)n->x0)->v[k]));
            if (k == 0) {
                e->e[0].v[0] -= c->x4->v[0];
                e->e[1].v[0] -= c->x4->v[0];
                e->e[2].v[0] -= c->x4->v[0];
                e->e[3].v[0] -= c->x4->v[0];
                tmp[k] += c->x4->v[0];
                c->x4->v[0] = 0.0f;
            } else if (k == 2) {
                e->e[0].v[2] -= c->x4->v[2];
                e->e[1].v[2] -= c->x4->v[2];
                e->e[2].v[2] -= c->x4->v[2];
                e->e[3].v[2] -= c->x4->v[2];
                tmp[k] += c->x4->v[2];
                c->x4->v[2] = 0.0f;
            }
            ((Nd*)n->x0)->v[k] = 0.0f;
            ((Nd*)n->x0)->x2c->v[k] = 0.0f;
            ((Nd*)n->x0)->x2c->x2c->v[k] = 0.0f;
            n->x1c[k] = tmp[k];
        }
        t->state = 1;
    case 1:
        fn_800120D0(ang);
        switch (u->x4) {
        case 0:
            n->x2c = ang[1] + 0x8000;
            break;
        case 1:
            n->x2c = ang[1] + 0x4000;
            break;
        case 2:
            n->x2c = ang[1];
            break;
        case 3:
            n->x2c = ang[1] - 0x4000;
            break;
        }
        break;
    case 3:
        t->flags |= 0x40;
        break;
    }
}

void fn_80013D58(s8 id, s8 flag)
{
    s8 i;
    s8 j;
    s8 k;

    if (flag != 0) {
        for (i = 0; i < 10; i++) {
            if (lbl_80309EC8.a[i] == 0) {
                k = i;
                break;
            }
        }
        if (i == 10) {
            for (j = 0; j < 9; j++) {
                lbl_80309EC8.a[j] = lbl_80309EC8.a[j + 1];
                lbl_80309EC8.w[j] = lbl_80309EC8.w[j + 1];
                lbl_80309EC8.b[j] = lbl_80309EC8.b[j + 1];
            }
            k = j;
        }
        lbl_80309EC8.a[k] = id;
        lbl_80309EC8.w[k] = lbl_80309EC8.x48;
        lbl_80309EC8.b[k] = lbl_80347334;
        if (k != 0 && id == 7) {
            if (fn_80078610(lbl_80309EC8.b[k]) == 0 || fn_800179E4(lbl_80309EC8.b[k]) == 0) {
                if (lbl_80309EC8.a[k - 1] == 8 && (lbl_80309EC8.w[k - 1] & 0x8000000)) {
                    lbl_80309EC8.x48 |= 0x8000000;
                    lbl_80309EC8.w[k] |= 0x4000000;
                }
            }
        }
    } else {
        fn_80290EA8(8);
        for (i = 0; i < 10; i++) {
            if (lbl_80309EC8.a[i] > 11 || lbl_80309EC8.a[i] < 0) {
                lbl_80309EC8.a[i] = 12;
            }
            switch (lbl_80309EC8.a[i]) {
            case 11:
                fn_80290E98(0x8080FFFF);
                break;
            default:
                if (lbl_80309EC8.w[i] & 0x4000000) {
                    fn_80290E98(0xFF80FFFF);
                } else {
                    fn_80290E98(-1);
                }
                break;
            }
        }
    }
}

inline int Hit(CamWork* w, CamState* u, f32 xc)
{
    switch (lbl_80309EC8.mv.x19a) {
    case 10:
    case 11:
        if (lbl_80309EC8.mv.x110 == xc && lbl_80309EC8.mv.xc0[0] == w->x38[0] && lbl_80309EC8.mv.xc0[1] == w->x38[1]
            && lbl_80309EC8.mv.xc0[2] == w->x38[2]) {
            u->x8 = lbl_80309EC8.mv.x160;
            return 1;
        }
    }
    return 0;
}

extern s32 fn_80075D64(Task*);

s32 fn_80020470(Task* t, s16 x) {
    ChrWork* cw = t->work;
    ChrInfo* w = cw->st;
    if (fn_80075D64(t) == 0) return 0;
    if (x == 14 && (lbl_8030A10C.x6c & 0x20000)) return 0;
    if ((w->x134 == 0 && !(w->xec & 1)) || (w->xf0 & 0x80000)) return 0;
    if (w->xec & 0x100) {
        if (x != 15) return 0;
        if (lbl_8030A10C.x6c & 0x100) return 0;
        w->xec &= ~0x100;
    }
    if (lbl_8030A10C.x68 != 0) {
        switch (x) {
        case 2:
        case 7:
            break;
        default:
            return 0;
        }
    }
    if (lbl_80347394 == 0) {
        switch (w->x6) {
        case 0x1a:
        case 0x1b:
        case 0x1c:
            return 0;
        }
    }
    return 1;
}

s16 fn_80015460(s16 id);
static inline s16 Who(Task* t, s16 v) {
    SysObj* s;
    if (ChrW(t)->st->x1dc != 0) return fn_80015460(v);
    if (lbl_80347394 != 0) {
        s = lbl_80347394->work;
        return s->x6c.x2;
    }
    return 0;
}
static inline s32 Hit20(Task* t, ChrInfo* u, s16 e, s16 k) {
    switch (u->x20c) {
    case 0x1D:
        if (fn_800153E0(0x1D, u->x20e) != 0) return 1;
    }
    if (e != 0x18) return 0;
    {
        s16 a = fn_800760EC(t, 0x15, -1);
        s16 b = fn_800760EC(t, e, k);
        if (a == b) return 1;
        return 0;
    }
}
int fn_80020700(s16 a, s16 b, Task* t) {
    ChrWork* w = t->work;
    ChrInfo* in = w->st;
    switch (in->x20c) {
    case 0x1d:
        if (fn_800153E0(0x1d, in->x20e) != 0) {
            return 1;
        }
        break;
    }
    if (a != 0x18) {
        return 0;
    }
    {
        s16 x = fn_800760EC(t, 0x15, -1);
        s16 y = fn_800760EC(t, a, b);
        return x == y;
    }
}

void fn_800208F4(s16* ev, s16* arg, Task* t) {
    ChrInfo* u = ChrW(t)->st;
    s16 k;
    s16 e;
    s32 hit;
    if (!(u->xec & 0x8000)) {
        e = *ev;
        switch (e) {
        case 0x18:
            k = *arg;
            hit = Hit20(t, u, e, k);
            if (hit != 0) {
                u->xec |= 0x8000;
                u->x14 = *ev;
                u->x16 = *arg;
                if (u->xec & 0x200000) {
                    *ev = 0x16;
                } else {
                    *ev = 0x15;
                }
                *arg = -1;
            }
            break;
        case 0x19:
            u->xec |= 0x8000;
            u->x14 = 0x18;
            u->x16 = Who(t, *arg);
            *ev = 0x10;
            if (lbl_80309174[u->id].xe != 0) *ev = 0x17;
            *arg = -1;
            break;
        case 0x1D:
            if (fn_800153E0(0x1D, *arg) != 0) {
                u->xec |= 0x8000;
                u->x14 = 0x18;
                u->x16 = Who(t, *arg);
            }
            break;
        }
    }
}

inline void Reset(void)
{
    Task** p;
    s8 i;
    for (i = 0, p = lbl_80309E24; i < 14; p++, i++) {
        if (*p != NULL) {
            ChrWork* cw = (*p)->work;
            ChrInfo* o = cw->st;
            o->draw.a = 0.0f;
            o->x1ec |= 0x20000000;
        }
    }
    fn_80011208(-1, -1, 0);
}

void fn_80014474(Task* t)
{
    CamWork* w = t->work;
    CamState* u = w->u;
    f32 b, a;
    f32 v[3];
    f32 c;
    f32 d;

    switch (u->state) {
    case 0:
        if (lbl_80309EC8.x48 & 0x8000000) {
            lbl_80309EC8.x48 &= ~0x8000000;
            u->state = 2;
            break;
        }
        if (fn_8006D1C4()) {
            fn_800114AC(v, &a, &b, 0);
            if (a > b) {
                u->xc = a;
            } else {
                u->xc = b;
            }
            u->xc = 2.0f * u->xc;
            v[1] = 0.0f;
            fn_80071CF0(v, w->x38);
            if (!Hit(w, u, u->xc)) {
                fn_800608C8(&u->x8);
            }
            c = u->xc;
            fn_80061C80(w->x20, 0.0f, u->x8, c, 0);
            w->x20[0] = w->x20[0] + w->x38[0];
            w->x20[2] = w->x20[2] + w->x38[2];
            w->x20[1] = c;
            fn_80071F84(w->x2c, w->x38, w->x20);
            fn_80014AB8(2, 0);
            u->state = 1;
        } else {
            fn_80071CF0(&lbl_80309EC8.x4c, w->x20);
            fn_80071CF0(&lbl_80309EC8.x58, w->x38);
            fn_800614FC(lbl_80309EC8.x64, w->x2c);
            break;
        }
    case 1:
        Reset();
        d = u->xc;
        c = u->x8;
        lbl_80309EC8.mv.x19a = 11;
        lbl_80309EC8.mv.x110 = d;
        fn_80071CF0(w->x38, lbl_80309EC8.mv.xc0);
        lbl_80309EC8.mv.x160 = c;
        break;
    case 2:
        Reset();
        break;
    }
}

int fn_8001FABC(Task* t)
{
    ChrInfo* u;
    ChrWork* w;
    Vec pos;
    f32 d;
    int ang0;
    int ang;
    s16 kind;

    w = t->work;
    u = w->st;
    if (fn_8001EE24(t, &pos) == 0) {
        return 0;
    }
    fn_80071CF0(&pos, &u->x110);
    if ((u->anims[u->xe4].flags & 0x10000000) || (u->xec & 0x800000) || fn_80017A14(u) != 0) {
        return 0;
    }
    if (pos.x == w->pos.x && pos.z == w->pos.z) {
        return 0;
    }
    kind = u->anims[u->xe4].x0;
    ang = fn_80071C74(w, pos.x, pos.z);
    ang0 = ang;
    switch (kind) {
    case 0x13:
        ang = fn_80071C34(pos.x, pos.z, w->pos.x, w->pos.z);
        break;
    }
    if ((u->anims[u->xe4].flags & 0x1000000) || (u->xf0 & 0x20000000)) {
        switch (u->x6) {
        case 0x13:
            fn_80071BCC(u->x104, ang0, u->x130);
            break;
        default:
            fn_80071BCC(u->x104, ang0, u->x12c);
            break;
        }
    }
    if (u->anims[u->xe4].flags & 0x10000) {
        ang = fn_80071C74(w, 0.0f, 0.0f);
    }
    switch (kind) {
    case 0xb:
    case 0xc:
    case 0xd:
    case 0x20:
        if (u->xf0 & 0x40000000) {
            u->xf0 |= 0x200;
            return 0;
        }
    }
    d = fn_8006116C(ang - w->ry);
    if (d < 0.0f) {
        d = -1.0f * d;
    }
    if (d < u->x128) {
        w->ry = ang;
        u->xf0 |= 0x200;
        return 0;
    }
    switch (kind) {
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 0x20:
        u->x11c = fn_8006116C(w->ry);
        u->x120 = fn_8006116C(ang);
        u->x124 = 0.0f;
        w->ry = ang;
        u->xf0 |= 0x200;
        return 0;
    default:
        u->x11c = fn_8006116C(w->ry);
        u->x120 = fn_8006116C(ang);
        fn_80061080(&u->x11c, &u->x120);
        if (u->x120 - u->x11c < 0.0f) {
            u->x124 = -1.0f * u->x128;
        } else {
            u->x124 = u->x128;
        }
        return 1;
    }
}

void fn_8000BB28(u8 idx)
{
    int k = idx;
    Node_BB28* o = NULL;
    s16 a;
    s16 kind;
    Work_BB28* w;
    Sub2_BB28* u;
    u32* p0;
    u32 p8;

    a = lbl_80309E5C.tbl[lbl_80309E5C.cur].recs[k].x16;
    kind = lbl_80309E5C.tbl[lbl_80309E5C.cur].recs[k].x18;
    fn_8006CF28(lbl_80309E5C.tbl[lbl_80309E5C.cur].x4->x8, &p0, a);
    switch (kind) {
    case 7:
    case 8:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
        fn_8006CEEC(lbl_80309E5C.tbl[lbl_80309E5C.cur].x4->x8, &p8, 0, a);
        break;
    }
    switch (kind) {
    case 1:
    case 7:
    case 15:
        o = fn_802268E8(lbl_803475A8, fn_8000F0A4(0));
        break;
    case 2:
    case 3:
    case 4:
    case 5:
    case 13:
    case 17:
    case 18:
    case 19:
    case 20:
        o = fn_802268E8(lbl_803475A8, fn_8000F0A4(1));
        break;
    case 6:
    case 8:
    case 16:
        o = fn_802268E8(lbl_803475A8, fn_8000F0A4(2));
        break;
    case 9:
    case 10:
    case 11:
    case 12:
    case 14:
        o = fn_802268E8(lbl_803475A8, fn_8000F0A4(3));
        break;
    }
    fn_80061F58(&o->work, 0x58, 0);
    w = o->work;
    w->r = lbl_80309E5C.tbl[lbl_80309E5C.cur].recs[k];
    w->r.x8 = (u32*)((u32)p0 + 8);
    lbl_80309E5C.tbl[lbl_80309E5C.cur].ptrs[k] = w;
    if (*w->r.x8 != 0) {
        w->r.x40 = fn_80227810(w->r.x8);
    } else {
        w->r.x8 = 0;
    }
    w->r.x0 = (void*)*p0;
    switch (kind) {
    case 7:
    case 8:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
        w->r.xc = p8;
        break;
    }
    lbl_80309E5C.tbl[lbl_80309E5C.cur].recs[k] = w->r;
    if (kind != 0xff) {
        fn_80061F58(&w->x4c, 0x54, 0);
        lbl_80309E5C.tbl[lbl_80309E5C.cur].x10 = w->x4c;
        fn_8022F00C(w->r.x0);
    }
    switch (kind) {
    case 6:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 14:
    case 16:
        if (fn_8000CF94(((Cx_BB28*)w->r.x0)->x2c->x2c) == 1) {
            u = w->x4c;
            fn_80061F58(&u->x4c, 0xc, 0);
            fn_8000B8E4(u->x4c, w->r.x0);
            w->x4c->x50 |= 0x40000000;
        }
        break;
    }
}

s32 fn_800073C0(CalendarStamp* out) {
    OSCalendarTime td;

    OSTicksToCalendarTime(OSGetTime(), &td);
    out->year = td.year;
    out->month = td.mon + 1;
    out->day = td.mday;
    out->hour = td.hour;
    out->minute = td.min;
    out->second = td.sec;
    out->weekday = td.wday;
    out->pad = 0;
    return 1;
}

s32 fn_8000810C(void* a, s32 b) {
    s32 r = 0;
    while (r == 0) {
        r = fn_80007BFC(a, b);
        if (r < 0) {
            return -1;
        }
    }
    return 1;
}

void fn_80009800(Slot* list) {
    Slot* s = list;

    for (;;) {
        if (s->id < 0) {
            break;
        }
        if (s->ptr != 0) {
            fn_801E17E0(s->ptr);
        }
        s++;
    }
    fn_801E17E0(list);
}

s32 fn_80012160(void) {
    if (lbl_80347394 != 0) {
        return -1;
    }
    switch (lbl_8034733C) {
    case 0:
        return 1;
    case 1:
        return 2;
    case 2:
        return 5;
    case 3:
        return 4;
    case 4:
        return 7;
    case 5:
        return 8;
    case 6:
        return 9;
    case 7:
    case 8:
    default:
        return -1;
    }
}

s32 fn_80015CFC(void* x) {
    u32 n = FLD(x, 4, u32);
    s32 i;
    for (i = 0; (u32)(s16)i < n; i++) {
        char* s = *(char**)((u8*)FLD(x, 0, void*) + i * 12);
        if (s[0] == 't' || s[0] == 'T') {
            if (s[1] == 'k' || s[1] == 'K' || s[1] == 'x' || s[1] == 'X') {
                return i;
            }
        }
    }
    return -1;
}

s32 fn_800176DC(s8 kind) {
    s32 i;
    for (i = 0; (s8)i < 0xc; i++) {
        Task* t = lbl_80309E24[i];
        if (t) {
            void* w = t->work;
            s8 id = fn_80020E10((u8*)FLD(w, 0x10, void*) + 0xc);
            if (kind == id) {
                return FLD(FLD(w, 0x4c, void*), 0, u8);
            }
        }
    }
    return -1;
}

void fn_80018C94(void) {
    DrawStatePop(0);
    fn_800D2048();
}

s32 fn_8001BC38(Task* t) {
    s16 v = fn_80008274(FLD(FLD(t->work, 0x4c, void*), 2, s16));
    switch (v) {
    case 0x8d:
    case 0x95:
    case 0x97:
    case 0x99:
    case 0x9d:
    case 0xee:
        return 1;
    default:
        return 0;
    }
}

void fn_8001D200(Task* t, f32* v) {
    u8* w = t->work;
    u8* d = FLD(w, 0x4c, u8*);
    s16 idx = FLD(w, 0x14, s16);
    fn_800615B4(FLD(d, 0x154, u8*) + (idx - 1) * 0x34 + 8, v, w + 0x28);
    v[0] = v[0] + FLD(w, 0x1c, f32);
    v[1] = v[1] + FLD(w, 0x20, f32);
    v[2] = v[2] + FLD(w, 0x24, f32);
}

s32 fn_8001DDE0(Task* t, Ent_80008800* list) {
    Ent_80008800* p;
    ChrWork* w = t->work;
    ChrInfo* d = w->st;
    if (list) {
        for (p = list;; p++) {
            s16 lo = p->x0;
            s16 hi = p->x2;
            Key* obj;
            if (lo < 0) {
                break;
            }
            if ((((s32)hi << 16) | lo) == 0x30032) {
                obj = p->xc;
                if (fn_8003DCF4(obj, d)) {
                    return obj->x10;
                }
            }
        }
    }
    return 0;
}

void fn_8001E138(void* a, void* b, u32 c) {
    NJS_POINT3 v14;
    NJS_POINT3 v8;
    if (c) {
        fn_80061518(b, &v8);
    } else {
        fn_80071CF0(b, &v8);
    }
    fn_80012130(&v14);
    fn_80071F84(a, &v8, &v14);
}

void fn_8001E19C(NJS_POINT3 *self, NJS_POINT3 *out, void *ctx, NJS_POINT3 *v)
{
    NJS_POINT3 b;
    NJS_POINT3 d;
    NJS_POINT3 a;
    NJS_POINT3 c;
    Ctx8001E19C *o = ((Ctx8001E19C_outer *)ctx)->obj;

    fn_80071CF0(&o->pos, &a);
    a.y = a.y + self->y;
    fn_80071CF0(v, &b);
    fn_80071F84(&c, v, &a);
    fn_80071D0C(out, &a, &c, self->x);
    fn_80071CF0(out, &d);
}

int fn_8001FA18(Obj8001FA18 *a, Obj8001FA18 *b)
{
    Inner8001FA18 *in_b;
    Inner8001FA18 *in_a;
    Obj8001FA18 *o;
    o = b->sub;
    in_b = o->inner;
    in_a = a->sub->inner;

    fn_80071CF0(&in_a->v110, &in_b->v110);
    fn_80071CF0(&in_a->v104, &in_b->v104);
    fn_80071CF0(&in_a->v11c, &in_b->v11c);
    if (in_a->flags & 0x200) {
        o->f2c = a->sub->f2c;
    }
    if (!(in_a->flags & 0x400)) {
        return 0;
    }
    return 1;
}

void fn_80020B28(Obj80020B28 *o)
{
    if (o->flags & 0x8000) {
        o->flags = o->flags & ~0x8000;
        o->x6 = o->x14;
        o->x8 = o->x16;
    }
}

void fn_80014F90(u8 flag) {
    s8 i;
    s8 start;
    s8 end;
    if (flag) {
        start = 4;
        end = 0xc;
    } else {
        start = 0;
        end = 4;
    }
    for (i = start; i < end; i++) {
        Task* t = fn_800215EC(i);
        if (t) {
            void* d = FLD(t->work, 0x4c, void*);
            if (!(FLD(d, 0x50, u32) & 0x01000000)) {
                fn_80015020(i);
            }
        }
    }
}

void fn_800152A0(void) {
    s8 i;
    for (i = 0; i < 0xc; i++) {
        Task* t = fn_800215EC(i);
        void* d;
        if (t == 0) {
            continue;
        }
        if (FLD(FLD(t->work, 0x4c, void*), 0x50, u32) & 0x01000000) {
            continue;
        }
        t = fn_800215EC(i);
        if (t == 0) {
            continue;
        }
        d = FLD(t->work, 0x4c, void*);
        if (FLD(d, 0x1dc, void*) == 0) {
            continue;
        }
        FLD(d, 0x44, s32) = FLD(lbl_80309DE4[FLD(d, 0, s8)], 0x1c, s32);
    }
}

void fn_80015344(s8 id) {
    Task* t = fn_800215EC(id);
    if (t) {
        void* d = FLD(t->work, 0x4c, void*);
        if (FLD(d, 0x1dc, void*)) {
            FLD(d, 0x44, s32) = FLD(lbl_80309DE4[FLD(d, 0, s8)], 0x1c, s32);
        }
    }
}

void fn_8001DCA0(ChrInfo* o) {
    if (o->x1dc) {
        fn_8001DD00(o, o->x20);
        lbl_80309730[o->id].b9 = 1;
    }
}

void fn_8001D14C(ChrInfo* o) {
    if (o->xec & 0x10) {
        if (o->x1dc) {
            fn_8001DD00(o, o->x20);
            lbl_80309730[o->id].b9 = 1;
        }
        o->xec &= ~0x10;
        o->x134 = 1;
    }
    o->xec &= ~0x40000;
}

void fn_8001D5C0(s16* a, s16* b) {
    if (lbl_80347394) {
        Task* t2 = FLD(lbl_80347394->work, 0x50, Task*);
        u8* d = FLD(t2->work, 0x4c, u8*);
        *a = (s8)d[0];
        *b = (s8)d[4];
        return;
    }
    *a = lbl_80347330;
    *b = lbl_80347328;
    if (*b < 0 || *b >= 0xc) {
        *b = *a;
    }
}

void fn_80008C00(Ent8C00* obj, s16 x, s16 y, s32 a6, s32 a7, s32 a8) {
    Rec* r = obj->mid->rec;
    s16 sx = r->x;
    s16 sy = r->y;

    r->x = x;
    r->y = y;
    fn_80008DF4(obj, a8, a6, a7);
    r->x = sx;
    r->y = sy;
}

void fn_8000FBA8(Actor* o) {
    Owner_8000FBA8* ow = (Owner_8000FBA8*)o->r->m;

    if (ow->a != 0) {
        ow->a->r->m->flags |= 0x400000;
    }
    if (ow->b != 0) {
        ow->b->r->m->flags |= 0x400000;
    }
    if (ow->c != 0) {
        ow->c->r->m->flags |= 0x400000;
    }
}

void fn_80012130(void* p) {
    fn_80071CF0(&lbl_80309EC8.x4c, p);
}

f32 fn_8001359C(Vec3* obj, f32* out) {
    f32 b;
    f32 a;
    f32 v[3];
    f32 r;

    r = fn_800114AC(v, &a, &b, 1);
    if (a > b) {
        *out = a;
    } else {
        *out = b;
    }
    *out = 2.0f * *out;
    v[1] = 0.0f;
    fn_80071CF0(v, obj);
    return r;
}

f32 fn_8001363C(Vec3* obj, f32* out) {
    f32 b;
    f32 a;
    f32 v[3];
    f32 r;

    r = fn_800114AC(v, &a, &b, 0);
    if (a > b) {
        *out = a;
    } else {
        *out = b;
    }
    *out = 2.0f * *out;
    v[1] = 0.0f;
    fn_80071CF0(v, obj);
    return r;
}

void fn_8001E4A0(void *a, NJS_POINT3 *v, Task *c)
{
    ChrWork *o = c->work;
    fn_800615B4(a, v, &o->rx);
    v->x = v->x + o->pos.x;
    v->y = v->y + o->pos.y;
    v->z = v->z + o->pos.z;
}

void fn_8000B6F0(W* o) {
    if (o->x0 != 0) {
        njPushMatrixEx();
        fn_80286EE8();
        fn_8028B498();
        njTranslate(0, o->tx, o->ty, o->tz);
        njRotateXYZ(0, o->rx, o->ry, o->rz);
        njScale(0, o->sx, o->sy, o->sz);
        fn_80035140(o->x0, o->x44);
        njPopMatrixEx();
    }
}

void fn_80014784(void) {
    Obj_80014784* o;

    if (lbl_80347394 == 0) {
        o = fn_802268E8(lbl_803475A8, fn_800136DC);
        if (o != 0) {
            o->data = fn_801E1C7C(0x70);
            memset(o->data, 0, 0x70);
            fn_80061F58(&o->data->x6c, 0x38, 0);
            fn_80014AB8(0, o->data);
        }
    }
}

void fn_8000DDFC(Task_8000DDFC* t) {
    Par* p = t->work->x4c;
    Dst* d = p->xc;
    if (d->x0 == 0) {
        t->mode = 3;
    }
    switch (t->mode) {
    case 0:
        p->x8 = p->x8 + p->x4;
        if (p->x8 >= 360.0f) {
            p->x8 = p->x8 - 360.0f;
        }
        d->x20 = p->x0 * njSin((Angle)(182.04445f * p->x8));
        break;
    case 3:
        t->flags |= 0x40;
        break;
    }
}

s16 fn_80015C30(Table* t, const char* str) {
    s16 i;
    s16 j;
    s16 len;
    if (t == NULL || t->ents == NULL) {
        return -1;
    }
    len = strlen(str);
    for (i = 0; i < t->count; i++) {
        const char* n = t->ents[i].name;
        j = 0;
        while (j < len) {
            if (n[j] != str[j]) {
                break;
            }
            j++;
        }
        if (j == len) {
            return i;
        }
    }
    return -1;
}

void fn_80019D7C(Task* t) {
    Work_80019D7C* w = t->work;
    Inner_80019D7C* in = w->in;
    switch (in->x12) {
    case 0: {
        Obj_80019D7C* o = fn_802268E8(lbl_803475A8, fn_80019B70);
        fn_80061F58(&o->blk, 0x18, 0);
        o->blk->a = t;
        o->blk->b = t;
        o->blk->c = 11;
        o->blk->d = 5;
        in->x12 = 1;
        break;
    }
    case 1:
        break;
    }
    fn_80018CBC(t, in->xe8, 0, 0, in->x2);
}

void fn_8001C348(Task* t) {
    ChrWork* cw = t->work;
    ChrInfo* w = cw->st;
    if (fn_8001C1F0(t) != 0) {
        w->xf4 &= 0x7FFFFFFF;
    }
    if (w->xf4 & 0x80000000) {
        w->xec |= 0x40;
    } else {
        w->xec &= ~0x40;
    }
    if (w->xf4 & 0x40000000) {
        switch (w->x4a) {
        case 4:
        case 5:
        case 8:
            w->xec |= 0x20;
            break;
        default:
            w->xec &= ~0x20;
            break;
        }
    } else {
        w->xec &= ~0x20;
    }
}

void fn_8001DE78(Task* t, s8 which, Item* list) {
    Item* p;
    ChrInfo* d = ChrW(t)->st;
    Cmd* obj;
    if (list != NULL) {
        for (p = list;; p++) {
            s16 lo = p->lo;
            s16 hi = p->hi;
            if (lo < 0) {
                break;
            }
            if ((((s32)hi << 16) | lo) == 0x30007) {
                obj = p->obj;
                if (fn_8003DCF4(obj, d)) {
                    switch (which) {
                    case 0:
                        d->x138 = obj->x10;
                        break;
                    case 1:
                        d->x138 = obj->x12;
                        break;
                    }
                    break;
                }
            }
        }
    }
}

void fn_800143A0(Task *t)
{
    CamWork *w = t->work;
    CamState *sub = w->u;
    void *e;
    s32 idx;

    switch (sub->state) {
    case 0:
        idx = fn_8006EDA0();
        if (idx < 0) {
            idx = 0;
        }
        fn_80014AB8(2, NULL);
        e = fn_80021658(idx);
        fn_80032B4C();
        fn_80011400(idx, 1);
        fn_8005535C(w->x20, w->x38, e, 0.0f);
        fn_80071F84(w->x2c, w->x38, w->x20);
        sub->state = 1;
    case 1:
        fn_80011208(-1, -1, 0);
        break;
    }
}

s32 fn_8000AD30(u8 dir)
{
    NJS_POINT3 a;
    NJS_POINT3 b;
    fn_80012130(&a);
    fn_80012100(&b);
    switch (dir) {
    case 0:
        if (b.x >= a.x) return 1;
        break;
    case 1:
        if (b.x <= a.x) return 1;
        break;
    case 2:
        if (b.z >= a.z) return 1;
        break;
    case 3:
        if (b.z <= a.z) return 1;
        break;
    }
    return 0;
}

void fn_8000DF50(Obj_8000DF50* o) {
    B* b;
    A* a = o->x24->x4c;
    b = a->x1c;
    if (b->x0 == 0) o->state = 3;
    switch (o->state) {
    case 0:
        if (a->xc == 0) b->x28 += a->x0; else b->x28 -= a->x0;
        if (a->xc == 0) b->x2c += a->x4; else b->x2c -= a->x4;
        if (a->xc == 0) b->x30 += a->x8; else b->x30 -= a->x8;
        break;
    case 3:
        o->flags |= 0x40;
        break;
    }
}

s32 fn_80017018(s8 idx) {
    Tsk_80017018 *t = fn_80021658(idx);
    ChrInfo *d;
    s16 k;
    s16 m;
    if (t == 0) {
        return 0;
    }
    d = t->work->st;
    k = fn_80020094(t->work, 1, -1, 1);
    if (k < 0) {
        return 0;
    }
    if (fn_80008274(d->x2) == 0xe9) {
        f32 s = 0.8f;
        t->work->scl.x = s;
        t->work->scl.y = s;
        t->work->scl.z = s;
        return 1;
    }
    m = d->anims[k].xe;
    if (m == 0) {
        return 0;
    }
    {
        f32 s = 0.1f * m + 1.0f;
        t->work->scl.x = s;
        t->work->scl.y = s;
        t->work->scl.z = s;
    }
    return 1;
}

s32 fn_80010F9C(s16 a, s16 b, s16 c, s16 d)
{
    s16 r = rand() % 100;
    if (r >= 90) {
        r = 100;
    }
    if (r < 10) {
        r = 0;
    }
    if (b == 0) {
        b = 1;
    }
    if ((s16)((f32)c / 10.0f * (f32)(a * r) / (f32)b) > d) {
        return 1;
    }
    return 0;
}

void fn_8000AA98(void)
{
    s32 i;
    for (i = 0; i < lbl_803098C8.count; i++) {
        if (lbl_803098C8.buf[i] != 0) {
            fn_801E1718(lbl_803098C8.buf[i]);
            lbl_803098C8.buf[i] = 0;
        }
    }
    for (i = 0; i < 32; i++) {
        if (lbl_803098C8.res[i] != 0) {
            lbl_803098C8.res[i] = 0;
        }
    }
}

s32 fn_8001BAC0(Unit_8001BAC0* u, s16 idx, s16 want, s16 other)
{
    s16 v;
    s16 t = u->x6;
    s32 bad = 0;
    u32 flags;
    if (t == 30) {
        v = u->x8;
        switch (v) {
        case 35:
            switch (u->x26) {
            case 1:
            case 3:
                switch (u->x20) {
                case 0:
                case 2:
                    bad = 1;
                    break;
                }
                break;
            }
            break;
        case 36:
        case 37:
            if (v != other) bad = 1;
            break;
        }
    }
    if (t != want) {
        if (want == 16 || want == 23) {
            if (t != 24) bad = 1;
        } else {
            bad = 1;
        }
    }
    flags = u->xdc[idx].flags;
    if (flags & 0x4000000) {
        s32 ok;
        switch (want) {
        case 4:
        case 5:
        case 8:
        case 9:
        case 10:
            ok = 1;
            break;
        default:
            ok = 0;
            break;
        }
        if (!ok) bad = 1;
    }
    if (flags & 0x1000000) {
        if (u->xec & 0x20000) bad = 1;
    }
    return bad;
}

void fn_80007EC0(void) {
    s32 r;
    if (lbl_803478B8 == 2) {
        r = fn_8023CD10(lbl_803478DC);
        switch (r) {
        case 0:
            if (lbl_803478B4 == 1) {
                s32 n = fn_8023AC78(lbl_803478DC);
                lbl_803478C4 -= n;
                lbl_803478C0 += n;
                lbl_803478C8 += n;
                if (lbl_803478C0 == 0) {
                    lbl_803478B8 = 3;
                } else {
                    lbl_803478B8 = 1;
                }
            } else {
                lbl_803478B8 = 1;
                lbl_803478B0 = 0;
            }
            break;
        case -1:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 9:
            lbl_803478B8 = 4;
            break;
        }
    } else if (lbl_803478B8 == 0) {
        r = fn_8023CD10(lbl_803478DC);
        switch (r) {
        case 0:
            lbl_803478B8 = 3;
            lbl_803478B0 = 0;
            break;
        case -1:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 9:
            lbl_803478B8 = 4;
            break;
        }
    }
}

void fn_80009FD8(void) {
    Tk_80009FD8* t;
    fn_8002903C();
    fn_801D6738();
    fn_8000AA08();
    fn_8000AA98();
    fn_801CBBF8();
    if ((t = lbl_80346A98) != 0) {
        do {
            t->flags |= 0x40;
        } while ((t = t->next) != 0);
    }
    fn_8022642C();
    lbl_8034737C = 0;
    if (lbl_80347370 != 0) {
        fn_801E1D94();
        fn_801DBE6C(7);
        fn_80228014();
        if (lbl_80347364 != 0xffff) fn_80217830(lbl_80347364);
    } else {
        switch (lbl_8034736A) {
        case 2:
            lbl_803475D4 = 1;
            lbl_80310A1C.f18 = 1;
            fn_80100178(lbl_802ACC98);
            fn_801DBE6C(6);
            lbl_80347704 = 0;
            break;
        case 0:
            fn_801E1D94();
            fn_801DBE6C(6);
            lbl_80347704 = 0;
            lbl_80310A1C.f18 = 0;
            break;
        case 1:
            lbl_80346A90 = 0;
            break;
        case 3:
        case 4:
            fn_801E1D94();
            fn_801DBE6C(6);
            lbl_80310A1C.f18 = 1;
            lbl_80347704 = 0;
            break;
        }
    }
}

EntD *fn_800095D0(void *old, u8 *src, void *extra) {
    s16 n;
    Ent_800095D0 *s;
    EntD *d;
    EntD *out;
    s16 i;
    if (old != 0) {
        fn_80035918(old);
        fn_801E17E0(old);
    }
    n = fn_800364F4(src);
    out = fn_801E1C7C(n * 16);
    s = (Ent_800095D0 *)src;
    d = out;
    for (i = 0; i < n; i++) {
        *(Ent_800095D0 *)d = *s;
        if (fn_800364B8(d)) {
            memcpy(d->data, src + s->off, d->size);
        }
        s++;
        d++;
    }
    if (extra != 0) fn_801E17E0(extra);
    else fn_801E17E0(src);
    return out;
}

CondLink* fn_80008800(Ent_80008800* t)
{
    CondLink* head = 0;
    CondLink* cur = 0;
    s16 n;
    Key* k;
    s16 lo;
    s16 hi;
    if (t != 0) {
        if (t->x0 < 0) return 0;
        k = t->xc;
        n = fn_800089F0(t, k->x0, k->x4, &lo, &hi, 0);
        while (n != 0) {
            if (head == 0) {
                fn_80061F58(&head, 0x10, 0);
                cur = head;
            } else {
                CondLink* prev;
                fn_80061F58(&cur->next, 0x10, 0);
                prev = cur;
                cur = cur->next;
                cur->prev = prev;
            }
            cur->x0 = k->x0;
            cur->x2 = k->x4;
            cur->x4 = lo;
            cur->x6 = hi;
            if ((s16)t[n].x0 < 0) break;
            k = t[n].xc;
            n = fn_800089F0(t, k->x0, k->x4, &lo, &hi, n);
        }
        return head;
    }
    return 0;
}

void fn_80006C00(NJS_MKEY_F* keys, u32 i, u32 nbKeys, f32* out) {
    f32 div[2] = {1.0f, 1.0f};
    NJS_MKEY_F* k1 = &keys[i];
    NJS_MKEY_F* k2 = &keys[(i + 1) % nbKeys];
    f32 t;
    f32 u;

    div[1] = (f32)(k2->keyframe - k1->keyframe);
    t = (lbl_80316940.frame - (f32)k1->keyframe) / div[(s32)(k2->keyframe - k1->keyframe) > 0];
    u = 1.0f - t;
    out[0] = k1->key[0] * u + k2->key[0] * t;
    out[1] = k1->key[1] * u + k2->key[1] * t;
    out[2] = k1->key[2] * u + k2->key[2] * t;
}

void fn_8001E3D8(void* a, Vec3_8001E3D8* out, Task_8001E3D8* t) {
    Vec3_8001E3D8 v;
    Work_8001E3D8* w;
    fn_800615B4(a, out, &t->work->pos);
    w = t->work;
    fn_800615B4(w->model->joints[w->idx - 1].data, &v, &w->pos);
    v.x = v.x + w->off.x;
    v.y = v.y + w->off.y;
    v.z = v.z + w->off.z;
    out->x = out->x + v.x;
    out->y = out->y + v.y;
    out->z = out->z + v.z;
}

void fn_8001E308(void *a, P3 *out, Tk1E *t)
{
    P3 v;
    Wk1E *w2;
    Wk1E *w = t->work;

    fn_800615B4(a, out, &w->x28);
    w2 = t->work;
    fn_800615B4(w2->d->tbl + (w2->idx - 1) * 0x34 + 8, &v, &w2->x28);
    v.x = v.x + w2->x1c;
    v.y = v.y + w2->x20;
    v.z = v.z + w2->x24;
    out->x = out->x + v.x;
    out->y = out->y + w->x20;
    out->z = out->z + v.z;
}

void fn_8001E238(NJS_POINT3 *self, void *out, Tk1E_8001E238 *t)
{
    NJS_POINT3 v20;
    NJS_POINT3 v14;
    NJS_POINT3 v8;
    Wk1E_8001E238 *w = t->work;

    fn_800615B4(w->d->tbl + (w->idx - 1) * 0x34 + 8, &v20, &w->x28);
    v20.x = v20.x + w->x1c;
    v20.y = v20.y + w->x20;
    v20.z = v20.z + w->x24;
    v20.y = v20.y + self->y;
    fn_80012130(&v14);
    fn_80071F84(&v8, &v14, &v20);
    fn_80071D0C(out, &v20, &v8, self->x);
}

void fn_80014BA8(void) {
    s8 i;
    for (i = 0; i < 12; i++) {
        Task* t = fn_800215EC(i);
        if (t != 0) {
            Wk_80014BA8* w = t->work;
            u8 id = *w->x4c;
            u32 fl = lbl_80309DE4[(s8)*w->x4c]->bits;
            u16 m = 0;
            if (!(fl & 0x80)) m |= 0x1;
            if (!(fl & 0x200)) m |= 0x20;
            if (!(fl & 0x400)) m |= 0x8;
            if (!(fl & 0x800)) m |= 0x10;
            if (!(fl & 0x4000)) m |= 0x4;
            if (!(fl & 0x40000)) m |= 0x100;
            if (m != 0) {
                fn_8002923C(id, m, 0);
            }
        }
    }
}

s32 fn_8000785C(ArcSet* set, s32 idx) {
    ArcHdr hdr;
    s32 c;
    u32 a;
    s32 b;
    s32 out;
    s32 r;
    s32 x;
    s32 magic;
    ArcInfo* info;

    fn_80298E48();
    r = fn_80297558(set, idx, &a, &b);
    if (r != 0) return r;
    x = fn_80298798(&hdr, &c, (ArcInfo*)set->slots[idx].info);
    if (x == 0) {
        x = fn_80298798(&hdr, &c, (ArcInfo*)set->slots[idx].info->x0);
        if (x == 0) {
            info = set->slots[idx].info;
            hdr.x4 = info->x10;
            hdr.x6 = info->x14;
            hdr.x0 = info->x4;
            x = info->x0;
        } else {
            magic = *(s32*)set->slots[idx].info->x0;
        }
    } else {
        magic = *(s32*)set->slots[idx].info;
    }
    if (magic == 0x47434958) {
        if (a != -1) c = a;
        r = fn_80298A04(set, idx, c, b, &hdr, &out);
        if (r != 0) return r;
        if (fn_80298BF8(out, x) < 0) {
            fn_80298BCC(out);
            return -1;
        }
    } else {
        return -1;
    }
    return 1;
}

s16 fn_800108EC(s32 a, s32 b, s32 unused, Fn108EC* c) {
    f32 x = a;
    f32 y;
    s32 v;
    if (x < 0.0f) {
        x = 0.0f;
    }
    y = x;
    x *= 0.975f;
    y *= 0.05f;
    x += y * (0.000030517578f * rand());
    if ((rand() & 7) == 0) {
        x += 1.0f;
    }
    if (b <= 5) {
        x *= c->stat[b];
        x /= 10.0f;
    }
    v = (s16)x;
    if (c->flags & 1) {
        v = (s16)(x / 2);
    }
    if (v >= 10000) {
        v = 9999;
    }
    return v;
}

s32 fn_80015D78(void* t, s32 id, s32 p5, s32 p6, s32 p7, s16 mode) {
    s8 arr[14];
    s8 i;
    for (i = 0; i < 14; i++) {
        arr[i] = -1;
    }
    switch (mode) {
    case 0:
        fn_8001604C(t, arr, p5, 2);
        break;
    case 1:
        return fn_80016234(t, 0, id, p6, p7);
    case 2:
        return fn_80016234(t, 1, id, p6, p7);
    case 3:
        fn_80015EC8(t, arr, 0);
        break;
    }
    for (i = 0; i < 14; i++) {
        if (arr[i] == (s16)id) {
            return 1;
        }
    }
    return 0;
}

s32 fn_800163A4(F163A4Task* t, s8 flag, s8 mode, s16 want, s16 cols, s16 rows) {
    F163A4Unit* u = t->wk->unit;
    V3 v;
    f32 step;
    f32 x0;
    s8 j;
    s8 i;
    s8 id;
    s32 sel;
    if (u->x0 == want) {
        return 0;
    }
    if (flag != 0) {
        sel = u->x4;
    } else {
        sel = u->x0;
    }
    fn_8001E6DC(&v, sel);
    step = 15.0f;
    v.x = v.x - step * (cols / 2);
    x0 = v.x;
    v.z = v.z - step * (rows / 2);
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            id = fn_80018398(&v, 1);
            if (id >= 0 && id < 12 && id == want) {
                return 1;
            }
            v.x = v.x + step;
        }
        v.x = x0;
        v.z = v.z + step;
    }
    switch (mode) {
    default:
        return 0;
    case 1:
        if (fn_8001D944(want, t) == 0) {
            return 0;
        }
        break;
    case 2:
        if (fn_8001D944(want, t) != 0) {
            return 0;
        }
        break;
    }
    return 1;
}

static inline s32 GetNode(Mid_800102C8* m, s16 sel, Node_800102C8** out) {
    switch (sel) {
    case 1:
        if (m->e0 != NULL) {
            *out = m->e0;
            return 1;
        }
        break;
    case 2:
        if (m->e4 != NULL) {
            *out = m->e4;
            return 1;
        }
        break;
    }
    return 0;
}

s32 fn_800102C8(Ent_800102C8* obj, s16 sel, void** out) {
    Node_800102C8* n;

    if (GetNode(obj->h->mid, sel, &n)) {
        *out = n->val;
        return 1;
    }
    return 0;
}

s16 fn_80020094(ChrWork *w, s16 a, s16 b, s8 flag) {
    s16 i = 0;
    ChrInfo *u = w->st;
    ChrAnim *r;

    if (a == 0x16) a = 0x15;
    for (; u->anims[i].x2 != 3; i++) {
        r = &u->anims[i];
        if (a != r->x0) continue;
        switch (a) {
        case 24:
        case 29:
        case 30:
            if (b != r->xc) continue;
            if (flag == 0) u->xe0 = fn_800300C4(u->anims[i].x4);
            return i;
        case 14:
            if (flag == 0) {
                u->xe0 = fn_800300C4(13);
            } else {
                u->xec |= 2;
            }
            return i;
        case 9:
            if (flag == 0) u->xe0 = fn_800300C4(11);
            return i;
        case 10:
            if (flag == 0) u->xe0 = fn_800300C4(12);
            return i;
        default:
            if (flag == 0) u->xe0 = fn_800300C4(u->anims[i].x4);
            return i;
        }
    }
    if (a == 14 && flag == 0) {
        u->xe0 = fn_800300C4(13);
        return 0;
    }
    if (a == 0x25 && flag == 0) {
        u->xe0 = fn_800300C4(14);
        return 0;
    }
    return -1;
}

static inline s16 FindRec(ChrInfo* u, s16 a, s16 b) {
    s16 i;
    for (i = 0; u->anims[i].x2 != 3; i++) {
        if (a == u->anims[i].x0) {
            if (b >= 0) {
                if (b == u->anims[i].xc) return i;
            } else {
                return i;
            }
        }
    }
    return -1;
}

s32 fn_8001ECB4(Task* t, s16 a, s16* out, s16 b) {
    ChrWork* wk = t->work;
    ChrInfo* u = wk->st;
    s16 k;
    s16 v;
    if (a == 0x16) a = 0x15;
    k = FindRec(u, a, b);
    if (k < 0) return 0;
    if (fn_8001C1F0(t) != 0) return 0;
    v = fn_800760EC(t, a, b);
    if (u->x5c != 0 && u->x64 == v) return 0;
    if (a == 2 || a == 7) {
        if (u->x204 != 0) k = u->x204;
    }
    if (u->anims[k].x10 || (u->xf0 & 0x40000)) {
        *out = k;
        return 2;
    }
    return 1;
}

void fn_80017A7C(Task *t)
{
    ChrWork *w = t->work;
    ChrInfo *s = w->st;

    switch (s->state) {
    case 0:
        memset(&w->pos, 0, sizeof(NJS_POINT3));
        fn_80071CF0(&w->pos, &s->pos);
        fn_80075F2C(t);
        s->state = 1;
    case 1:
        s->x134 = 1;
        break;
    }
    fn_80017CB8(t, s->xe4);
}

extern s32 fn_800205B8(s16 id);
extern s32 fn_8001ECB4(Task *t, s16 a, s16 *out, s16 b);
extern void fn_8001CAA8(Task *t);
extern s8 fn_8001E910(Task *t);

void fn_80017B18(Task* t) {
    ChrWork *w = t->work;
    ChrInfo *u = w->st;
    s32 flag = 0;
    s16 buf[4];
    if (fn_800205B8(u->id)) flag = 1;
    switch (u->state) {
    case 0:
        u->xf0 &= ~0x10000000;
        u->state = 1;
    case 1:
        if (flag != 0 && lbl_8030A10C.x68 == 0) {
            if (fn_8006DB94() != 0) {
                u->state = 2;
            } else {
                fn_80032C68();
                break;
            }
        } else {
            u->state = 2;
        }
    case 2:
        fn_8001ECB4(t, u->x6, buf, u->x8);
        fn_80075F2C(t);
        u->state = 3;
    case 3:
        w = t->work;
        u->x138 = fn_8001DDE0(t, w->x10->x30);
        u->state = 4;
    case 4:
        if (u->x138 != 0) {
            u->x138--;
            break;
        }
        u->state = 5;
    case 5:
        u->xf0 |= 0x10000000;
        fn_8001CAA8(t);
        u->state = 6;
    case 6:
        switch (fn_8001E910(t)) {
        case 1:
        case 2:
            u->state = 7;
            u->x134 = 1;
        }
    case 7:
        break;
    }
    switch (u->state) {
    case 1:
        break;
    default:
        fn_80017CB8(t, u->xe4);
        break;
    }
}

static inline Task* Find(s8 id) {
    s8 i;
    for (i = 0; i < 14; i++) {
        Task* t = lbl_80309E24[i];
        if (t != 0) {
            ChrWork* w = t->work;
            if (w->st->id == id) return lbl_80309E24[i];
        }
    }
    return 0;
}
s32 fn_8001DB44(Task* t, s8 mode) {
    ChrWork* w = t->work;
    Task* o;
    ChrInfo* u;
    o = Find(w->st->target);
    o = o ? o : Find(0);
    w = o->work;
    u = w->st;
    switch (mode) {
    case 0:
        if (u->x6 == 0xb || u->x6 == 0x20) return 1;
        break;
    case 1:
        if (u->xf0 & 0x00400000) return 1;
        break;
    }
    return 0;
}

/* Three-step task: on step 1 clears flags 0x100000 and 8 of every character that has them and
 * calls fn_8001BE2C on it, then marks itself done (flag 0x40). */
void fn_80015640(Self* o) {
    s8 i;
    switch (o->state) {
    case 0:
        o->state = 1;
        break;
    case 1:
        for (i = 0; i < 12; i++) {
            Task* t = lbl_80309E24[i];
            if (t != 0) {
                ChrWork* cw = t->work;
                ChrInfo* w = cw->st;
                if ((w->xec & 0x100000) || (w->xec & 8)) {
                    w->xec &= ~0x100000;
                    w->xec &= ~8;
                    fn_8001BE2C(t);
                }
            }
        }
        o->state = 2;
    case 2:
        o->flags |= 0x40;
        break;
    }
}

void fn_8000DEC8(Actor_8000DEC8* a) {
    Mid_8000DEC8* m = a->holder->mid;
    Sub* s = m->sub;

    if (s->link == 0) {
        a->state = 3;
    }
    if ((s32)a->state != 3) {
        if ((s32)a->state >= 3) {
            return;
        }
        if ((s32)a->state != 0) {
            return;
        }
        if (m->mode != 1) {
            return;
        }
        if (s->pos <= 0.0f) {
            s->pos = s->pos + m->speed;
        } else {
            s->pos = s->pos - m->speed;
        }
    } else {
        a->flags |= 0x40;
    }
}

void fn_800171F0(s8 ia, s8 ib, NJS_POINT3* o1, NJS_POINT3* o2)
{
    NJS_POINT3 pa;
    NJS_POINT3 pb;
    NJS_POINT3 t;
    Obj_800171F0* a = fn_80021658(ia);
    Obj_800171F0* b = fn_80021658(ib);
    f32 d;
    fn_80071CF0(&a->work->pos, &pa);
    fn_80071CF0(&b->work->pos, &pb);
    d = fn_80071E9C(&pa, &pb);
    if (a->work->x4c->xec & 0x200000) {
        d += 22.5f;
    } else {
        d += 7.5f;
    }
    t.x = d;
    t.y = 0.0f;
    fn_8001E19C(&t, o1, b, &a->work->pos);
    d = fn_80071E9C(&pa, &pb);
    if (b->work->x4c->xec & 0x200000) {
        d += 22.5f;
    } else {
        d += 7.5f;
    }
    t.x = d;
    t.y = 0.0f;
    fn_8001E19C(&t, o2, a, &b->work->pos);
}

static inline Task *FindUnit(s8 id) {
    s8 i;
    for (i = 0; i < 14; i++) {
        Task *t = lbl_80309E24[i];
        if (t != NULL) {
            ChrWork *w = t->work;
            if (w->st->id == id) {
                return lbl_80309E24[i];
            }
        }
    }
    return NULL;
}

Task *fn_8001E05C(Task *t) {
    ChrWork *w = t->work;
    Task *r = FindUnit(w->st->target);
    if (r != NULL) {
        return r;
    }
    return FindUnit(0);
}

s32 fn_80008000(s32 idx) {
    s32 blk;
    s32 bs;
    s32 q;
    if (idx >= lbl_803478AC || idx < 0) {
        return -1;
    }
    bs = lbl_80346738;
    q = idx / bs;
    blk = q * bs;
    if (blk != lbl_803478D4) {
        lbl_803478D4 = blk;
        if (lbl_803478AC > blk + bs) {
            lbl_803478BC = idx;
            lbl_803478D0 = bs;
            lbl_803478CC = bs << 11;
            if (fn_8023AB88(lbl_803478DC, lbl_803478D8, lbl_803478CC, blk << 11, 0, 2) == 0) {
                lbl_803457F8.err = 5;
                return -1;
            }
        } else {
            lbl_803478BC = idx;
            lbl_803478D0 = lbl_803478AC - blk;
            lbl_803478CC = lbl_803478A8 - (blk << 11);
            if (fn_8023AB88(lbl_803478DC, lbl_803478D8, lbl_803478CC, blk << 11, 0, 2) == 0) {
                lbl_803457F8.err = 5;
                return -1;
            }
        }
        lbl_803478B8 = 2;
        lbl_803478B4 = 0;
    }
    return 0;
}

void fn_80011394(s8 sel) {
    s8 i;

    for (i = 0; i < 0xe; i++) {
        Task* n = lbl_80309E24[i];
        if (n != 0) {
            ChrWork* w = n->work;
            ChrInfo* m = w->st;
            if ((!(m->xf0 & 0x80000000) && sel == 0) || sel != 0) {
                m->draw.a = 0.0f;
                m->x1ec |= 0x20000000;
            }
        }
    }
}

void fn_80015A58(Vec3_80015A58 *base, s16 n, Vec3_80015A58 *out, f32 ang) {
    Vec3_80015A58 tmp;
    Vec3_80015A58 pts[4];
    s32 k;
    s16 t;
    s16 d;
    Vec3_80015A58 *q;
    s16 rem;
    s16 idx;
    s16 j;
    f32 f;
    if (ang >= 360.0f) ang -= 360.0f;
    k = 360 / n;
    t = (s32)ang;
    d = t / k;
    rem = t % k;
    idx = d - 1;
    if (idx < 0) idx = n - 1;
    q = pts;
    for (j = 0; j < 4; j++) {
        fn_80071CF0(&base[idx], q);
        idx++;
        if (idx >= n) idx = 0;
        q++;
    }
    f = (f32)rem / (f32)k;
    if (f <= 0.0f) f = 0.01f;
    if (f >= 1.0f) f = 0.09f;
    fn_802917C8(pts, out, &tmp, f);
}

s16 fn_80015460(s16 id) {
    s32 k;
    s8 i;
    for (i = 0; (k = lbl_802ACDF0[i].key) >= 0; i++) {
        if (id == k - 0xf0) {
            return lbl_802ACDF0[i].val;
        }
    }
    return 0;
}

static inline Task *FindTask(s8 idx) {
    s8 i;
    for (i = 0; i < 14; i++) {
        Task *t = lbl_80309E24[i];
        if (t != 0) {
            ChrWork *w = t->work;
            if (w->st->id == idx) {
                return lbl_80309E24[i];
            }
        }
    }
    return 0;
}

static inline Task *FindTaskOrDefault(s8 idx) {
    Task *t = FindTask(idx);
    if (t != 0) {
        return t;
    }
    return FindTask(0);
}

s32 fn_8001DF44(Task *self, f32 *out) {
    ChrWork *w = self->work;
    Task *t = FindTaskOrDefault(w->st->target);
    if (t == 0) {
        return 0;
    }
    w = t->work;
    fn_80071CF0(&w->pos, out);
    return 1;
}

s32 fn_8001EBA4(Task *o, s16 idx) {
    ChrInfo *c = ChrW(o)->st;
    s32 v;
    f32 f;
    if (c->x64 == idx) {
        return 0;
    }
    if ((c->x6 == 2 || c->x6 == 7) && c->x204 != 0) {
        v = c->anims[c->x204].x6;
    } else {
        v = c->anims[idx].x6;
    }
    f = c->anims[idx].x10;
    if (f < 1.0f && (c->xf0 & 0x40000)) {
        f = 5.0f;
    }
    f = 1.0f / f;
    if (fn_80076170(0.0f, f, o->work, v, c->anims[idx].x0, c->anims[idx].xc)) {
        c->xec |= 0x80000000;
        fn_80072770(o);
    }
    c->x64 = -1;
    return 1;
}

/* Copies each non-zero component of v into lbl_80309EC8.va (the float test is `if (x)`,
 * which compares x against 0.0f in the order the original has; `x != 0.0f` swaps fcmpu). */
void fn_80012078(V5BF30* v) {
    if (v->x) {
        lbl_80309EC8.va[0] = v->x;
    }
    if (v->y) {
        lbl_80309EC8.va[1] = v->y;
    }
    if (v->z) {
        lbl_80309EC8.va[2] = v->z;
    }
}

void fn_8000C8AC(ModelSrc* src) {
    char name[0x20];
    ModelCache* c;
    ModelCache* n;

    sprintf(name, lbl_802ACCE8, lbl_80309E5C.x0, (s16)src->id);
    c = lbl_803473A0;
    if (c->x8 == 0) {
        {
            void* buf = fn_801E1C7C(src->size);
            memcpy(buf, src->data, src->size);
            c->x8 = fn_801DB124(buf);
            fn_8006CF54(c);
            strcpy(c->name, name);
            c->x4 = 0;
        }
        return;
    }
    for (;;) {
        if (c->x8 != 0) {
            if (fn_8025EF88(name, c->name) == 0) return;
        }
        if (c->x38 == 0) break;
        c = c->x38;
    }
    n = fn_801E1C7C(0x44);
    c->x38 = n;
    n = c->x38;
    memset(n, 0, 0x44);
    n->x34 = c;
    {
        void* buf = fn_801E1C7C(src->size);
        memcpy(buf, src->data, src->size);
        n->x8 = fn_801DB124(buf);
        fn_8006CF54(n);
        strcpy(n->name, name);
        n->x4 = 0;
    }
}

s32 fn_80007640(ArcSet *o, s32 idx) {
    u32 a;
    s32 b;
    s32 c;
    Mid_80007640 *m;
    Inner_80007640 *d;
    u32 v;
    s32 r;
    fn_80298E48();
    r = fn_80297558(o, idx, &a, &b);
    if (r != 0) {
        return r;
    }
    v = o->slots[idx].x8;
    if (a != -1) {
        v = a;
    }
    switch (fn_80298CAC(v, b, 0, &c)) {
    case -1:
        return -1;
    case 0:
        c = fn_80298210(&m, &d);
        if (c < 0) {
            return -1;
        }
        m->xc = d;
        if (v != -1) {
            m->xc->x0 = v;
        }
        lbl_80347EC4++;
        fn_80298C78(o, idx, c);
        break;
    }
    return 1;
}

/* Clears pending word 1 (sel 1, 0x40) or 0 (sel 0, 0x44) if it equals val; 1 if cleared. */
s32 fn_80014A54(u8 sel, SysObj* val) {
    s32 r = 0;
    switch (sel) {
    case 0:
        if (lbl_80309EC8.x44 == val) {
            lbl_80309EC8.x44 = 0;
            r = 1;
        }
        break;
    case 1:
        if (lbl_80309EC8.x40 == val) {
            lbl_80309EC8.x40 = 0;
            r = 1;
        }
        break;
    }
    return r;
}

void fn_8001FD7C(Wrap8001FD7C *w)
{
    ChrWork *e = w->ent;
    ChrInfo *in = e->st;
    if (in->anims[in->xe4].flags & 0x10000) {
        e->ry = fn_80071C74(e, 0.0f, 0.0f);
    }
}

s32 fn_8001FDD8(Obj8001FDD8 *obj, s16 a, s16 b)
{
    s32 i;
    for (i = 0; obj->inner->tab[i].type != 3; i++) {
        Ent8001FDD8 *e = &obj->inner->tab[i];
        if (a == e->key0) {
            if (b >= 0) {
                if (b == e->key12) return i;
            } else {
                return i;
            }
        }
    }
    return -1;
}

void fn_80013FD0(Task* t)
{
    CamWork* w = t->work;
    CamState* u = w->u;

    if (u->state != 0) {
        if ((*(G*)&lbl_80309EC8).x48 & 0x80000000) {
            (*(G*)&lbl_80309EC8).x48 &= ~0x80000000;
            u->state = 6;
        }
        if ((*(G*)&lbl_80309EC8).x48 & 0x40000000) {
            u->state = 7;
        }
    }
    switch (u->state) {
    case 0:
        switch ((*(Sys*)&lbl_80309E5C).x0) {
        default:
            if (rand() % 2 != 0) {
                u->state = 1;
            } else {
                u->state = 3;
            }
            break;
        case 1:
        case 3:
            u->state = 1;
            break;
        case 2:
            u->state = 3;
            break;
        }
        if ((*(Gs*)&lbl_8030A10C).x190 != 0) {
            u->xc = 1.25f;
        } else {
            u->xc = 1.0f;
        }
        break;
    case 1:
        fn_80061C80(w->x20, 0.1f, u->x8, 110.0f, 0);
        w->x20[1] = 80.0f;
        w->x38[0] = 0.0f;
        w->x38[1] = 60.0f + w->x20[1];
        w->x38[2] = 0.0f;
        u->state = 2;
        u->x34 = 0;
        if (rand() % 2 != 0) {
            u->x34 |= 1;
        }
        break;
    case 2:
        if (u->x34 & 1) {
            u->x8 += 1.5f * u->xc;
        } else {
            u->x8 -= 1.5f * u->xc;
        }
        fn_80061C80(w->x20, 0.1f, u->x8, 110.0f, 0);
        w->x20[1] = 80.0f;
        w->x38[1] -= u->xc;
        if (w->x38[1] < 0.0f) {
            w->x38[1] = 0.0f;
        }
        break;
    case 3:
        u->x2c = 0;
        fn_80061C80(w->x20, 0.1f, u->x8, u->x2c, 0);
        w->x20[1] = 80.0f;
        memset(w->x38, 0, 12);
        u->state = 4;
        u->x34 = 0;
        if (rand() % 2 != 0) {
            u->x34 |= 1;
        }
        break;
    case 4:
        if (u->x34 & 1) {
            u->x8 += 1.5f * u->xc;
        } else {
            u->x8 -= 1.5f * u->xc;
        }
        fn_80061C80(w->x20, 0.1f, u->x8, u->x2c * u->xc, 0);
        w->x20[1] = 80.0f;
        u->x2c++;
        if (u->x2c * u->xc > 110.0f) {
            u->x2c--;
        }
        break;
    case 7:
        fn_80071CF0((void *)((*(G*)&lbl_80309EC8).x4c), (void *)(w->x20));
        fn_80071CF0((void *)((*(G*)&lbl_80309EC8).x58), (void *)(w->x38));
        fn_800614FC((void *)((*(G*)&lbl_80309EC8).x64), (void *)(w->x2c));
        break;
    }
    fn_80071F84(w->x2c, w->x38, w->x20);
    fn_80032B4C();
}

s32 fn_8001F3F0(Task* t, NJS_POINT3* out)
{
    ChrWork* w = t->work;
    ChrInfo* st = w->st;
    Task* o;
    ChrWork* ow;
    ChrWork* w2;
    NJS_POINT3 tmp;
    Angle zero[3];

    switch (st->x6) {
    default:
        return 0;
    case 6:
    case 19:
        if (st->pos.x == w->pos.x && st->pos.z == w->pos.z) {
            if (lbl_8030A6D4[2].flags & 0x40) {
                fn_80061C80(&tmp, 0.1f, 90.0f, 30.0f, 0);
            } else {
                fn_80061C80(&tmp, 0.1f, 45.0f, 40.0f, 0);
            }
            tmp.y += 10.0f;
            zero[0] = 0;
            zero[1] = 0;
            zero[2] = 0;
            fn_800615B4(&tmp, out, zero);
            out->x += w->pos.x;
            out->y += w->pos.y;
            out->z += w->pos.z;
        } else {
            out->x = st->pos.x;
            out->y = w->pos.y;
            out->z = st->pos.z;
        }
        break;
    case 2:
        if (lbl_8030A6D4[2].flags & 0x40) {
            o = Find(st->target);
            o = o ? o : Find(0);
            ow = o->work;
            fn_80071CF0(&ow->pos, out);
            break;
        }
        return 0;
    case 4:
    case 5:
    case 8:
    case 16:
    case 21:
    case 22:
    case 23:
    case 24:
    case 29:
        w2 = t->work;
        o = Find(w2->st->target);
        o = o ? o : Find(0);
        ow = o->work;
            fn_80071CF0(&ow->pos, out);
        break;
    case 9:
    case 10:
    case 11:
    case 13:
    case 32:
        w2 = t->work;
        o = Find(w2->st->x48);
        o = o ? o : Find(0);
        ow = o->work;
            fn_80071CF0(&ow->pos, out);
        break;
    }
    return 1;
}

s32 fn_800090F8(s32 packed, s16* p) {
    s32 ret = 1;
    switch (packed) {
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
        fn_8001FE44(p);
        break;
    default:
        ret = 0;
        break;
    }
    return ret;
}

void fn_80009750(char* dir, char* name, void* slot) {
    char path[0x80];
    char base[0x40];
    strcpy(base, name);
    fn_80061048(base);
    if (dir[0] != '/') {
        strcpy(path, "/");
        strcat(path, dir);
        strcat(path, base);
        strcat(path, ".STD");
    } else {
        sprintf(path, "%s%s.STD", dir, base);
    }
    fn_80035FC0(path, slot, 1);
}

void fn_8000CEE8(Task* task)
{
    CE8State* st = ((CE8Work*)task->work)->st;
    CE8Pos* pos = st->x0;
    CE8Ext* ext = st->x4;

    st->x4c++;
    if (st->xa != -1 && st->x4c > st->xa) {
        task->state = 3;
    } else {
        st->x4e = 0;
        if (st->x44 != 0.0f) {
            ext->x10 = -1.0f;
            st->x48 = 0;
        } else {
            st->x48 = 1;
        }
        fn_80071CF0(&st->p18, &pos->p1c);
        task->state = 2;
    }
}

void fn_8000E02C(Task* task)
{
    E02Work* w = task->work;
    E02Ctr* c;

    c = w->ctr;
    if (w->x0 == 0) {
        task->state = 3;
    }
    switch (task->state) {
    case 0:
        if (c->cur >= c->max) {
            task->state = 1;
        } else {
            c->cur = c->cur + 1;
        }
        break;
    case 1:
        fn_802307EC(w->x0, &c->x4, 0);
        break;
    case 3:
        task->flags |= 0x40;
        break;
    }
}

void fn_8000F0BC(void)
{
    u16 id = lbl_80309E5C.x0;

    if (id == 0xf || id == 0x10 || id == 0x1f) {
        fn_80035910(0x10004000);
    } else if (id == 0x6e || id == 0x71 || id == 0x74 || id == 0x78 || id == 0x80 || id == 0x82) {
        fn_80035910(0x10104000);
    } else if (id == 0x1e) {
        fn_80035910(0x10008000);
    } else {
        fn_80035910(0x08000000);
    }
}

void fn_80011160(s8* ids)
{
    s8 i;
    s8 j;
    ChrInfo* u;
    Task* t;

    for (i = 0; i < 12; i++) {
        t = fn_800215EC(i);
        if (t != NULL) {
            u = ((ChrWork*)t->work)->st;
            for (j = 0; j < 12; j++) {
                if (u->id == ids[j]) {
                    break;
                }
            }
            if (j == 12) {
                u->draw.a = 0.0f;
            }
        }
    }
}

s32 fn_8001C12C(void)
{
    ChrInfo* st;
    s8 i;
    s8 a = 0;
    s8 b = 0;
    Task* t;
    ChrWork* w;
    s32 r;

    for (i = 0; i < 12; i++) {
        t = lbl_80309E24[i];
        if (t != NULL) {
            w = t->work;
            st = w->st;
            r = fn_80020E10(w->x10->xc);
            if ((s8)r < 0) {
                if (st->x6 != 0xe) {
                    a++;
                }
            } else {
                if (st->x6 != 0xe) {
                    b++;
                }
            }
        }
    }
    if (a == 0) {
        return 1;
    }
    return (b != 0) ? 0 : 2;
}

void fn_8001E50C(NJS_POINT3 *a, NJS_POINT3 *out, RotRef *extra) {
    NJS_POINT3 d;
    RotObj *obj = extra->obj;
    fn_80071CF0(a, &d);
    d.x = d.x - obj->pos.x;
    d.y = d.y - obj->pos.y;
    d.z = d.z - obj->pos.z;
    obj = extra->obj;
    fn_800615B4(&d, out, obj->rot);
    out->x = out->x + obj->pos.x;
    out->y = out->y + obj->pos.y;
    out->z = out->z + obj->pos.z;
}

s32 fn_8000AE08(void* obj, f32* out, u8 dir) {
    Vec3 a;
    Vec3 c;
    Vec3 p;
    s32 b[3];
    f32 f;
    f32 s;
    u16 id;
    fn_80012130(&a);
    fn_800120D0(b);
    fn_80012100(&c);
    fn_80071CF0(obj, &p);
    switch (dir) {
    case 0:
        p.z = a.z;
        p.y = a.y;
        p.x += 2.5f;
        if (a.x >= p.x) {
            LIMIT()
        }
        break;
    case 1:
        p.z = a.z;
        p.y = a.y;
        p.x -= 2.5f;
        if (a.x <= p.x) {
            LIMIT()
        }
        break;
    case 2:
        p.x = a.x;
        p.y = a.y;
        p.z += 2.5f;
        if (a.z >= p.z) {
            LIMIT()
        }
        break;
    case 3:
        p.x = a.x;
        p.y = a.y;
        p.z -= 2.5f;
        if (a.z <= p.z) {
            LIMIT()
        }
        break;
    case 4:
        p.z = a.z;
        p.x = a.x;
        p.y += 2.5f;
        if (a.y >= p.y) {
            LIMIT()
        }
        break;
    }
    if (lbl_80309E5C.x0 != 0x3e && lbl_80309E5C.x0 != 6) {
        if (fn_8000AD30(dir) == 1) {
            return 0;
        }
    }
    f = fn_80071E9C(&a, &p);
    switch (id = lbl_80309E5C.x0) {
    case 0x46: case 0x47: case 0x4b: case 0x81:
        s = 15.0f;
        break;
    default:
        s = 45.0f;
        break;
    }
    if (f < 0.0f) {
        f = 0.0f;
    }
    f = -(1.0f - f / s);
    if (f < 0.0f) {
        if (f <= -1.0) {
            f = -1.0f;
        }
        switch (id) {
        case 0x46: case 0x47: case 0x49: case 0x4b:
        case 0x80: case 0x81: case 0x82:
        case 0x92: case 0x93: case 0x94: case 0x95:
            if (f <= -0.9f) {
                f = -0.9f;
            }
            *out = f;
            break;
        default:
            *out = f;
            break;
        }
        return 1;
    }
    return 0;
}

/* The work of a character task. */



void fn_80012F58(Task* t)
{
    CamWork* w = t->work;
    CamState* u = w->u;
    Task* c;
    ChrInfo* st;
    s8 kind;
    s16 cur;
    s16 other;
    s16 r;

    r = fn_8001D41C(&cur, &other);
    if (cur != u->x2) {
        if (r) {
            u->state = 2;
        } else {
            u->state = 0;
        }
    }
    c = fn_80021658(cur);
    st = ChrW(c)->st;
    switch (st->x6) {
    case 6:
        kind = 0;
        break;
    case 4:
    case 8:
    case 9:
        kind = 2;
        break;
    case 5:
    case 10:
        kind = 3;
        break;
    case 2:
    case 7:
    case 12:
        kind = 4;
        break;
    case 29:
        if (fn_800153E0(0x1d, st->x8)) {
            kind = 1;
        } else {
            kind = 5;
        }
        break;
    default:
        kind = 1;
        break;
    }
    if (kind != u->x2f) {
        switch (st->x6) {
        case 30:
            switch (st->x8) {
            case 0x24:
            case 0x25:
                if (u->x2 != cur) {
                    u->state = 0;
                }
                break;
            }
            break;
        case 2:
        case 7:
        case 11:
            if (u->x2 != cur) {
                u->state = 0;
            }
            break;
        default:
            u->state = 0;
            break;
        }
    }
    switch (u->state) {
    case 0:
        u->x2f = kind;
        fn_80032B4C();
        ResetChrs(1);
        fn_80032B6C(cur, 1);
        fn_80032B6C(other, 1);
        if (u->x2 != cur) {
            fn_80053F38(cur, 1);
        }
        u->state = 1;
    case 1:
        if (!(st->xf0 & 0x02000000)) {
            u->state = 2;
        }
        break;
    }
    kind = u->x2f;
    u->x2 = cur;
    u->x4 = other;
    switch (kind) {
    case 0:
    case 4:
        switch (u->state) {
        case 2:
            fn_80053F38(cur, 0);
            u->state = 3;
            break;
        case 3:
            fn_80071CF0(&lbl_80309EC8.x4c, w->x20);
            fn_80071CF0(&lbl_80309EC8.x58, w->x38);
            fn_800614FC(lbl_80309EC8.x64, w->x2c);
            break;
        }
        break;
    case 1:
        switch (u->state) {
        case 2:
            u->state = 3;
            fn_80032BBC(cur, 0);
            break;
        case 3:
            fn_80071CF0(&lbl_80309EC8.x4c, w->x20);
            fn_80071CF0(&lbl_80309EC8.x58, w->x38);
            fn_800614FC(lbl_80309EC8.x64, w->x2c);
            break;
        }
        break;
    case 2:
        switch (u->state) {
        case 2:
            if (!fn_80009030(ChrW(c)->x10->x30, 4, -1, 0x2a, 3)) {
                fn_80053F38(cur, 0);
            }
            u->state = 3;
            break;
        case 3:
            fn_80071CF0(&lbl_80309EC8.x4c, w->x20);
            fn_80071CF0(&lbl_80309EC8.x58, w->x38);
            fn_800614FC(lbl_80309EC8.x64, w->x2c);
            break;
        }
        fn_80032BBC(cur, 1);
        break;
    case 3:
        switch (u->state) {
        case 2:
            if (!fn_80009030(ChrW(c)->x10->x30, 5, -1, 0x2a, 3)) {
                fn_80053F38(cur, 0);
            }
            u->state = 3;
            break;
        case 3:
            fn_80071CF0(&lbl_80309EC8.x4c, w->x20);
            fn_80071CF0(&lbl_80309EC8.x58, w->x38);
            fn_800614FC(lbl_80309EC8.x64, w->x2c);
            break;
        }
        break;
    case 5:
        switch (u->state) {
        case 2:
            if (fn_80009030(ChrW(c)->x10->x30, st->x6, st->x8, 0x2e, 3)) {
                u->state = 4;
                break;
            }
            u->state = 3;
        case 3:
            fn_80032BBC(cur, 0);
        case 4:
            fn_80071CF0(&lbl_80309EC8.x4c, w->x20);
            fn_80071CF0(&lbl_80309EC8.x58, w->x38);
            fn_800614FC(lbl_80309EC8.x64, w->x2c);
            break;
        }
        break;
    }
}

s32 fn_8000743C(Key7* a, Key7* b) {
    if (a->x0 > b->x0) return 1;
    if (a->x0 < b->x0) return -1;
    if (a->x2 > b->x2) return 1;
    if (a->x2 < b->x2) return -1;
    if (a->x3 > b->x3) return 1;
    if (a->x3 < b->x3) return -1;
    if (a->x4 > b->x4) return 1;
    if (a->x4 < b->x4) return -1;
    if (a->x5 > b->x5) return 1;
    if (a->x5 < b->x5) return -1;
    if (a->x6 > b->x6) return 1;
    if (a->x6 < b->x6) return -1;
    return 0;
}

s32 fn_80011984(AnimPlay* a) {
    s32 ret;
    Key16* k;
    u32 fr;
    f32 t;
    Track* trk;
    Key16* keys;
    ret = 0;
    a->end = a->anim->length;
    a->time = a->time + a->speed;
    if (a->time >= (f32)a->end) {
        return 1;
    }
    trk = a->anim->track;
    keys = trk->keys;
    while (trk->count > a->idx) {
        k = &keys[a->idx];
        fr = k->frame;
        t = a->time;
        if (t == (f32)fr) {
            fn_80071CF0(k->v, a->out);
            break;
        }
        if ((f32)fr > t) {
            f32 dx = k->v[0] - k[-1].v[0];
            f32 dy = k->v[1] - k[-1].v[1];
            f32 dz = k->v[2] - k[-1].v[2];
            a->out[0] = k[-1].v[0] + dx * t / (f32)fr;
            a->out[1] = (&keys[a->idx])[-1].v[1] + dy * a->time / (f32)keys[a->idx].frame;
            a->out[2] = (&keys[a->idx])[-1].v[2] + dz * a->time / (f32)keys[a->idx].frame;
            break;
        }
        ret = 2;
        a->idx++;
    }
    return ret;
}

s16 fn_800089F0(Ent_80008800* t, s16 a, s16 b, s16* lo, s16* hi, s16 start) {
    Ent_80008800* e = &t[start];
    s32 found = 0;
    s16 i = start;

    *lo = start;
    for (;;) {
        if (e->x0 < 0) {
            *hi = i;
            break;
        }
        if (fn_8003DE8C(e->xc->x0, e->xc->x4, a, b)) {
            if (found == 0) {
                *lo = i;
                found = 1;
            }
        } else if (found == 1) {
            *hi = i;
            return i;
        }
        e++;
        i++;
    }
    if (found) {
        return i;
    }
    return 0;
}

void fn_80010474(s16 i) {
    s16 v = lbl_80309DE4[i]->x18;

    if (fn_80008274(lbl_80309700[i]->work->x2) == 0xc6) {
        v /= 2;
    } else {
        v /= 4;
    }
    if (v >= lbl_80309DE4[i]->x14) {
        lbl_80309DE4[i]->bits |= 0x8000;
    } else {
        lbl_80309DE4[i]->bits &= ~0x8000;
    }
}

static inline u32 MakeId(s16 lo, s16 hi) {
    return (hi << 16) | lo;
}
s32 fn_80008F08(Ent_80008800* list, s16 p1, s16 p2, s16 c, s16 d, s8 mode, Ent_80008800** out) {
    s32 found;
    s16 i;
    s16 lo;
    s16 hi;
    Key* pt;
    found = 0;
    if (list != NULL) {
        i = 0;
        while (1) {
            lo = list[i].x0;
            hi = list[i].x2;
            if (lo < 0) break;
            pt = list[i].xc;
            switch (mode) {
            case 0:
                if (fn_8003DE8C(pt->x0, pt->x4, p1, p2)) found = 1;
                break;
            case 1:
                if (MakeId(lo, hi) == MakeId(c, d)) found = 1;
                break;
            case 2:
                if (fn_8003DE8C(pt->x0, pt->x4, p1, p2)) {
                    if (MakeId(lo, hi) == MakeId(c, d)) found = 1;
                }
                break;
            }
            if (found) {
                *out = &list[i];
                return 1;
            }
            i++;
        }
    }
    return 0;
}

s16 fn_80009030(Ent_80008800* list, s16 p1, s16 p2, s16 c, s16 d) {
    Ent_80008800* e;
    u32 key;
    s16 count;
    s32 useKey;
    s32 v;
    count = 0;
    useKey = 0;
    if (c >= 0 && d >= 0) {
        useKey = 1;
    }
    if (list != NULL) {
        key = (d << 16) | c;
        e = list;
        while (1) {
            s16 lo = e->x0;
            s16 hi = e->x2;
            if (lo < 0) break;
            if (fn_8003DE8C(e->xc->x0, e->xc->x4, p1, p2)) {
                v = (hi << 16) | lo;
                switch (v) {
                case 0x30041:
                    break;
                default:
                    if (!useKey || v == key) count++;
                    break;
                }
            }
            e++;
        }
    }
    return count;
}

static inline Task* FindOr0(s8 id) {
    Task* o = Find(id);
    if (o != NULL) {
        return o;
    }
    return Find(0);
}

/* Collects into out (-1 terminated) the ids of the characters standing on a w x h grid of
 * 15-unit cells centred on center, the task's target or the task itself; returns the count. */
s8 fn_8001D628(Task* t, s16* out, s8 w, s8 h, V3* center, s8 flag)
{
    ChrWork* tw = t->work;
    ChrInfo* u = tw->st;
    s8 cnt = 1;
    f32 x0;
    V3 pos;
    s8 v;
    Task* o;
    s8 i;
    s8 j;
    s16 id;
    s8 k;
    int ok;

    if (center == NULL) {
        if (flag == 0) {
            id = u->target;
            out[0] = id;
            tw = t->work;
            o = FindOr0(tw->st->target);
            if (o != NULL) {
                ChrWork* ow = o->work;
                fn_80071CF0(&ow->pos, &pos);
            }
        } else {
            tw = t->work;
            fn_80071CF0(&tw->pos, &pos);
            id = u->id;
            cnt = 0;
        }
    } else {
        id = u->id;
        fn_80071CF0(center, &pos);
        cnt = 0;
    }
    pos.x -= 15.0f * (w / 2);
    pos.z -= 15.0f * (h / 2);
    x0 = pos.x;
    for (j = 0; j < h; j++) {
        for (i = 0; i < w; i++) {
            v = fn_80018398(&pos, 0);
            if (v >= 0 && v != id && v < 12 && fn_8001D944(v, t)) {
                ok = 1;
                for (k = 0; k < cnt; k++) {
                    if (v == out[k]) {
                        ok = 0;
                        break;
                    }
                }
                if (ok) {
                    out[cnt] = v;
                    cnt++;
                }
            }
            pos.x += 15.0f;
        }
        pos.x = x0;
        pos.z += 15.0f;
    }
    out[cnt] = -1;
    return cnt;
}

static inline Task* Find3(s8 key) {
    Task* r = Find(key);
    if (r != 0) return r;
    return Find(0);
}

/* Point at angle ang and distance radius (30, doubled for large characters, when 0) around
 * character id, on its ground height. */
void fn_8001D288(f32* out, s8 id, f32 ang, f32 radius) {
    Task* t;
    Unit_8001D288* w;
    f32 r;
    f32 buf[3];
    Wk_8001D288* wk;
    t = Find3(id);
    wk = t->work;
    w = wk->w;
    if (radius) {
        r = radius;
    } else {
        r = 30.0f;
        if (w->xec & 0x200000) r *= 2.0f;
    }
    fn_80061C80(buf, 0.0f, ang, r, 0);
    wk = t->work;
    fn_800615B4(buf, out, wk->rot);
    wk = t->work;
    out[0] = out[0] + wk->x;
    out[1] = w->x15c;
    wk = t->work;
    out[2] = out[2] + wk->z;
}
s32 fn_800205B8(s16 id) {
    s16 a, b;
    if (lbl_8034733C == 7) {
        ChrWork *w = Find3(id)->work;
        if (!(w->st->xf0 & 0x8000)) return 1;
    }
    fn_8001D41C(&a, &b);
    if (a == id) return 1;
    return 0;
}

/* A pack of 12-byte entries; fn_80007528 hands each to one of four loaders by its flag bits. */
typedef struct ArcEnt {
    u32 x0;
    u32 flags;
    u32 x8;
} ArcEnt;
typedef struct ArcPack {
    ArcEnt* ents;
    u32 count;
} ArcPack;
typedef s32 (*ArcPackFn)(ArcPack* pk, u32 i);
extern ArcPackFn lbl_802DAE40[4];

s32 fn_80007528(ArcPack* pk) {
    u32 i;
    if (pk->count == 0) {
        lbl_803457F8.err = 1;
        return -1;
    }
    for (i = 0; i < pk->count; i++) {
        s32 kind;
        switch (pk->ents[i].flags & 0x5C000000) {
        case 0:
            kind = 0;
            break;
        case 0x40000000:
            kind = 1;
            break;
        case 0x08000000:
            kind = 2;
            break;
        case 0x04000000:
            kind = 3;
            break;
        default:
            kind = 2;
            break;
        }
        if (lbl_802DAE40[kind](pk, i) < 0) {
            lbl_803457F8.a = i;
            return -1;
        }
    }
    return 1;
}

int fn_8001BCC8(s16 id) {
    int ret = 0;
    int r;
    if (lbl_8034733C == 7) {
        Task* o = Find(id);
        ChrWork* w;
        o = o ? o : Find(0);
        w = o->work;
        if (!(w->st->xf0 & 0x8000)) {
            r = 1;
            goto done;
        }
    }
    {
        s16 b;
        s16 a;
        fn_8001D41C(&a, &b);
        if (a == id) {
            r = 1;
        } else {
            r = 0;
        }
    }
done:
    if (r) ret = 1;
    return ret;
}

