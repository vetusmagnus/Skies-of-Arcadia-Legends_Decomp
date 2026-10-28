#include "types.h"
#include "ninja.h"
#include "game/drawstate.h"
#include <dolphin/os.h>
#include "game/task.h"
#include <string.h>
#define PTR(p, off) (*(void**)((u8*)(p) + (off)))
extern void* fn_80005B9C(void* heap);
extern void fn_800090F8(s32 packed, s16* p);
extern void* lbl_803475A8;
extern void* fn_802268E8(void* a, void (*cb)(void*));
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
    int xc;
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
typedef struct ChrRec { u8 pad0[0x1c]; u32 bits; } ChrRec;
extern ChrRec* lbl_80309DE4[];
extern s32 fn_8000F718(void* p, s32 a, s32 b);
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
extern u32 lbl_803478A0;
extern u32 lbl_803478A4;
extern u8 *lbl_803478DC;
extern void fn_8000832C(s32 a, s32 b, s32 c);
extern void fn_800086BC(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
typedef struct {
    u8 pad0[0x10];
    void* x10;
    u8 pad14[0x68 - 0x14];
    void* x68;
    u32 x6c;
    u8 pad70[0xf0 - 0x70];
    s16 xf0;
    u8 padf2[0x1c4 - 0xf2];
    s32 x1c4;
} GS;
extern GS lbl_8030A10C;
typedef struct {
    s16 id;
    s16 pad;
    void *ptr;
} Ent_80009860;
extern u8 *lbl_80346AA4;
typedef void (*TaskFn)(void*);
extern TaskFn lbl_802DAFA8[];
extern u8 lbl_8030B7F4[];
/* lbl_80309EC8: the 0x244-byte battle/system block (memset in battle.c). */
typedef struct {
    u8 pad_0[0x40];
    u32 x40;
    u32 x44;
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
typedef struct Ent_80020060 { s16 x0; s16 x2; u8 pad[0x14]; } Ent_80020060;
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
    u8 pad10[8];
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
extern void fn_80015138(int);
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
extern s16 fn_80009030(void*, s16, s16, int, int);
extern void fn_800312F0(Tk_8001CED0*, s16, s16, s8);
extern void fn_80031254(Tk_8001CED0*);
typedef struct {
    u8 pad0[8];
    s32 mode;
    f32 b1[3];
    u8 pad18[4];
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
typedef struct {
    u8 pad0[0x48];
    u32 x48;
    u8 x4c[12];
    u8 x58[12];
    u8 x64[0xc0 - 0x64];
    f32 xc0[3];
    u8 padcc[0x110 - 0xcc];
    f32 x110;
    u8 pad114[0x160 - 0x114];
    f32 x160;
    u8 pad164[0x19a - 0x164];
    s16 x19a;
} G_80014474;
typedef struct {
    u8 pad0[8];
    f32 x8;
    f32 xc;
    u8 pad10[0x30 - 0x10];
    s16 state;
} U_80014474;
typedef struct {
    u8 pad0[0x20];
    f32 x20[3];
    f32 x2c[3];
    f32 x38[3];
    u8 pad44[0x6c - 0x44];
    U_80014474* u;
} W_80014474;
typedef struct {
    u8 pad[0x164];
    f32 x164;
    u8 pad168[0x1ec - 0x168];
    u32 x1ec;
} Unit_80014474;
typedef struct {
    u8 pad[0x4c];
    Unit_80014474* w;
} UW_80014474;
typedef struct Tk_80014474 {
    u8 pad[0x24];
    union {
        W_80014474* w;
        UW_80014474* uw;
    } work;
} Tk_80014474;
extern int fn_8006D1C4(void);
extern f32 fn_800114AC(void*, f32*, f32*, int);
extern void fn_800608C8(void*);
extern void fn_80061C80(void*, f32, f32, f32, int);
extern void fn_80071F84(void*, void*, void*);
extern void fn_80014AB8(s32, void*);
typedef struct {
    f32 x, y, z;
} Vec;
typedef struct {
    s16 kind;
    u8 pad2[6];
    u32 flags;
    u8 padc[0x18 - 0xc];
} Ent_8001FABC;
typedef struct {
    u8 pad0[6];
    s16 x6;
    u8 pad8[0xdc - 8];
    Ent_8001FABC* ents;
    u8 pade0[4];
    s16 xe4;
    u8 padq[6];
    u32 xec;
    u32 xf0;
    u8 padf4[0x104 - 0xf4];
    f32 x104[3];
    Vec x110;
    f32 x11c;
    f32 x120;
    f32 x124;
    f32 x128;
    f32 x12c;
    f32 x130;
} Unit_8001FABC;
typedef struct {
    u8 pad0[0x1c];
    f32 x1c;
    u8 pad20[4];
    f32 x24;
    u8 pad28[4];
    s32 x2c;
    u8 pad30[0x4c - 0x30];
    Unit_8001FABC* w;
} Wk_8001FABC;
typedef struct Tk_8001FABC {
    u8 pad[0x24];
    Wk_8001FABC* work;
} Tk_8001FABC;
extern int fn_8001EE24(Tk_8001FABC*, Vec*);
extern s8 fn_80017A14(Unit_8001FABC*);
extern int fn_80071C74(Wk_8001FABC*, f32, f32);
extern int fn_80071C34(f32, f32, f32, f32);
extern void fn_80071BCC(void*, int, f32);
extern f32 fn_8006116C(int);
extern void fn_80061080(f32*, f32*);
typedef struct Cx_BB28 {
    u8 pad[0x2c];
    struct { u8 pad[0x2c]; void* x2c; }* x2c;
} Cx_BB28;
extern TaskFn fn_8000F0A4(s16 i);
extern void fn_80061F58(void*, int, int);
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
extern s32 fn_80007BFC(void* a, void* b);
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
void fn_8001DD00(void* o, s8 v);
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
    void* data;
} Obj_80014784;
extern void fn_800136DC(void*);
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
typedef struct Top_80019D7C { u8 pad[0x24]; Work_80019D7C* w; } Top_80019D7C;
typedef struct Blk_80019D7C { u8 pad[4]; Top_80019D7C* a; Top_80019D7C* b; s16 c; s16 d; } Blk_80019D7C;
typedef struct Obj_80019D7C { u8 pad[0x24]; Blk_80019D7C* blk; } Obj_80019D7C;
extern void fn_80019B70(void*);
extern void fn_80018CBC(Top_80019D7C*, int, int, int, int);
typedef struct W_8001C348 {
    u8 pad0[0x4a];
    s16 x4a;
    u8 pad4c[0xec - 0x4c];
    u32 xec;
    u8 padf0[4];
    u32 xf4;
} W_8001C348;
typedef struct Mid_8001C348 { u8 pad[0x4c]; W_8001C348* w; } Mid_8001C348;
typedef struct Tk_8001C348 { u8 pad[0x24]; Mid_8001C348* mid; } Tk_8001C348;
extern s32 fn_8001C1F0(void* t);
typedef struct Cmd { u8 pad0[0x10]; s16 x10; s16 x12; } Cmd;
typedef struct Item { s16 lo; s16 hi; u8 pad4[8]; Cmd* obj; } Item;
typedef struct Work_8001DE78 { u8 pad0[0x138]; s16 x138; } Work_8001DE78;
typedef struct Mid_8001DE78 { u8 pad[0x4c]; Work_8001DE78* w; } Mid_8001DE78;
typedef struct Task_8001DE78 { u8 pad[0x24]; Mid_8001DE78* mid; } Task_8001DE78;
typedef struct Sub143 { u8 pad00[0x30]; s16 state; } Sub143;
typedef struct Wk143 {
    u8 pad00[0x20];
    f32 x20[3];
    f32 x2c[3];
    f32 x38[3];
    u8 pad44[0x28];
    Sub143 *sub;
} Wk143;
typedef struct Tk143 { u8 pad00[0x24]; Wk143 *work; } Tk143;
extern s32 fn_8006EDA0(void);
extern void fn_80011400(s16 a, s32 b);
extern void fn_8005535C(void *a, void *v, void *t, f32 x);
extern void fn_80011208(s32 a, s32 b, s32 c);
typedef struct B { u32 x0; u8 pad[0x24]; s32 x28; s32 x2c; s32 x30; } B;
typedef struct A { s32 x0; s32 x4; s32 x8; s32 xc; u8 pad[0xc]; B* x1c; } A;
typedef struct D { u8 pad[0x4c]; A* x4c; } D;
typedef struct Obj_8000DF50 { u8 pad[0x18]; u8 flags; u8 state; u8 pad1a[0xa]; D* x24; } Obj_8000DF50;
typedef struct Ent18 {
    s16 x0;
    s16 x2;
    s16 x4;
    u8 pad_06[6];
    s16 xc;
    s16 xe;
    f32 x10;
    u8 pad_14[4];
} Ent18;
typedef struct Dat {
    u8 pad_00[2];
    s16 x2;
    u8 pad_04[0x58];
    u32 x5c;
    u8 pad_60[4];
    s16 x64;
    u8 pad_66[0xdc - 0x66];
    Ent18 *xdc;
    s32 xe0;
    u8 pad_e4[0xec - 0xe4];
    u32 xec;
    u32 xf0;
    u8 pad_f4[0x204 - 0xf4];
    s16 x204;
} Dat;
typedef struct Wk_80017018 { u8 pad_00[0x34]; f32 x34, x38, x3c; u8 pad_40[0xc]; Dat *x4c; } Wk_80017018;
typedef struct Tsk_80017018 { u8 pad_00[0x24]; Wk_80017018 *work; } Tsk_80017018;
extern s16 fn_80020094(Wk_80017018 *w, s16 a, s16 b, s8 flag);
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
typedef struct Node_80008800 {
    s16 x0;
    s16 x2;
    s16 x4;
    s16 x6;
    struct Node_80008800* x8;
    struct Node_80008800* xc;
} Node_80008800;
typedef struct { s16 x0; u8 pad2[2]; s16 x4; } Key;
typedef struct { s16 x0; u8 pad2[0xa]; Key* xc; } Ent_80008800;
extern s16 fn_800089F0(Ent_80008800* t, s16 a, s16 b, s16* lo, s16* hi, s16 start);
typedef struct {
    u32 keyframe;
    f32 key[3];
} NJS_MKEY_F_80006C00;
typedef struct {
    void** mdata;
    void** keys;
    void** counts;
    f32 frame;
    u32 nbFrame;
    s32 unk14;
    f32* matrix;
    s32 unk1C;
} MotionState_80006C00;
typedef struct Vec3_8001E3D8 { f32 x, y, z; } Vec3_8001E3D8;
typedef struct Joint { u8 pad[8]; u8 data[0x34 - 8]; } Joint;
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
extern s32 fn_80298798(ArcHdr* hdr, s32* c, ArcInfo* info);
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
extern s32 fn_80018398(V3* v, s32 a);
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
typedef struct ChrMot {
    u8 pad0[4];
    u32 x4;
} ChrMot;
typedef struct ChrAnim {
    u8 pad0[8];
    u32 flags;
    u8 padc[8];
    f32 x14;
} ChrAnim;
typedef struct ChrInfo {
    s8 id;              /* 0x00 */
    u8 pad1[3];
    s8 target;          /* 0x04 */
    u8 pad5;
    s16 x6;             /* 0x06 */
    s16 x8;             /* 0x08 */
    u8 padA[8];
    s16 state;          u8 pad_14[0x34];
          s8 x48;
          u8 pad_49[0x13];
    ChrMot* x5c;        /* 0x5c */
    void* x60;          /* 0x60 */
    u8 pad64[4];
    f32 x68;            /* 0x68 */
    u8 pad6c[4];
    s32 x70;            /* 0x70 */
    u8 pad74[0xdc - 0x74];
    ChrAnim* anims;     /* 0xdc */
    u8 pade0[4];
    s16 xe4;            /* 0xe4 */
    u8 pade6[2];
    s16 xe8;            /* 0xe8 */
    s16 xea;            /* 0xea */
    u32 xec;            /* 0xec */
    u32 xf0;            /* 0xf0 */
    u8 padf4[4];
    NJS_POINT3 pos;     /* 0xf8 */
    u8 pad104[0x134 - 0x104];
    s32 x134;           /* 0x134 */
    s16 x138;           /* 0x138 */
    u8 pad13a[0x154 - 0x13a];
    void* x154;         /* 0x154 */
    u8 pad158[0x164 - 0x158];
    f32 x164;           /* 0x164 */
    u8 pad168[0x1ec - 0x168];
    u32 x1ec;           /* 0x1ec */
} ChrInfo;
typedef struct Obj_80017B18 {
    u8 pad0[0x30];
    u8 *x30;
} Obj_80017B18;
typedef struct ChrWork {
    u8 pad0[8];
    void* x8;           /* 0x08 */
    u8 padc[4];
    Obj_80017B18 *x10; /* 0x10 */
    s16 x14;            /* 0x14 */
    u8 pad16[0x1c - 0x16];
    NJS_POINT3 pos;     /* 0x1c */
    Angle rx, ry, rz;   /* 0x28 */
    NJS_POINT3 scl;     /* 0x34 */
    u8 pad40[4];
    u8 x44;             /* 0x44 */
    u8 pad45[0x4c - 0x45];
    ChrInfo *st; /* 0x4c */
} ChrWork;
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
typedef struct Row_8001EBA4 {
    s16 x0;
    s16 pad2[2];
    s16 x6;
    s16 pad8[2];
    s16 xc;
    s16 pade;
    f32 x10;
    u8 pad14[4];
} Row_8001EBA4;
typedef struct C_8001EBA4 {
    u8 pad0[6];
    s16 x6;
    u8 pad8[0x64 - 8];
    s16 x64;
    u8 pad66[0xdc - 0x66];
    Row_8001EBA4 *tab;
    u8 pade0[0xec - 0xe0];
    u32 xec;
    u32 xf0;
    u8 padf4[0x204 - 0xf4];
    s16 x204;
} C_8001EBA4;
typedef struct W_8001EBA4 {
    u8 pad0[0x4c];
    C_8001EBA4 *c;
} W_8001EBA4;
typedef struct O_8001EBA4 {
    u8 pad0[0x24];
    W_8001EBA4 *w;
} O_8001EBA4;
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
    Wk_8001FABC *ent;
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
    u8 pad0[8];
    f32 x8;
    f32 xc;
    u8 pad10[0x2c - 0x10];
    s16 x2c;
    u8 pad2e[2];
    s16 state;
    u8 pad32[2];
    u32 x34;
} U_80013FD0;
typedef struct {
    u8 pad0[0x20];
    f32 x20[3];
    f32 x2c[3];
    f32 x38[3];
    u8 pad44[0x6c - 0x44];
    U_80013FD0* u;
} W_80013FD0;
typedef struct {
    u8 pad[0x24];
    W_80013FD0* work;
} Tk_80013FD0;
typedef struct {
    u16 x0;
    u8 pad2[0x2a];
} Sys;
typedef struct {
    u8 pad0[0x190];
    u32 x190;
} Gs;
typedef struct Slot24 { u32 flags; u8 pad[0x20]; } Slot24;
/* ADD: lbl_8030A6D4 entries (0x24 bytes) */
extern Slot24 lbl_8030A6D4[];

void* fn_80005B50(void* heap, u32 size) {
    void* p = fn_80005B9C(heap);
    if (p != 0) {
        memset(p, 0, size);
    }
    return p;
}

typedef struct {
    u32 keyframe;
    f32 key[3];
} NJS_MKEY_F;
typedef void (*MotionInterpFn)(void* keys, u32 i, u32 nbKeys, void* out);
typedef struct {
    void** mdata;  /* 0x00 current node's channel data */
    void** keys;   /* 0x04 key array pointers for the node */
    void** counts; /* 0x08 key counts for the node */
    f32 frame;     /* 0x0C */
    u32 nbFrame;   /* 0x10 */
    s32 unk14;
    f32* matrix;   /* 0x18 extra matrix applied after each node, or NULL */
    s32 unk1C;
} MotionState;
extern MotionState lbl_80316940;
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

void fn_80008170(void) {
    fn_8023A8E0((s32)lbl_803478DC);
}

void fn_800091A4(s16* p) {
    s16 x = p[0];
    s16 y = p[1];
    if (x >= 0) {
        fn_800090F8((y << 16) | x, p);
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

void fn_8000CC84(s32 flag) {
    if (flag == 1) {
        lbl_80309E5C.x8 |= 0x01000000;
    } else {
        lbl_80309E5C.x8 &= ~0x01000000;
    }
}

s32 fn_8000F86C(s32 idx) {
    void* p = lbl_80347394;
    if (p != 0) {
        return (s8)*(s16*)((u8*)PTR(p, 0x24) + 0x5c);
    }
    return *(u8*)((u8*)lbl_80309DE4[(s8)idx] + 0x100);
}

void fn_8000F8A4(void* obj, void* x) {
    s32 v = fn_8000F718(x, 0, 0);
    fn_8000F6F8(obj, 0x40, v, -1, 0);
}

void fn_80010538(s16 idx) {
    s32 mode = lbl_80309730[idx].mode;
    void* q;
    if (mode == 0) {
        return;
    }
    if (mode == 4) {
        return;
    }
    q = lbl_80309DE4[idx];
    *(s16*)((u8*)q + 0xb4) += *(s16*)((u8*)q + 8);
}

extern void fn_80011208(s32 a, s32 b, s32 c);
s32 fn_80010B5C(void) {
    return 1;
}

void fn_80011370(s32 a, s32 b)
{
    fn_80011208(a, b, 0);
}

typedef struct {
    u8 pad0[8];
    f32 x8;
    f32 xc;
    u8 pad10[0x30 - 0x10];
    s16 state;
} U_800121D8;
typedef struct {
    u8 pad0[0x20];
    f32 x20[3];
    f32 x2c[3];
    f32 x38[3];
    u8 pad44[0x6c - 0x44];
    U_800121D8* u;
} W_800121D8;

extern int fn_80016B20(s8);
void fn_80014D0C(void);
void fn_80014CFC(void);
void fn_800152A0(void);
extern void SoundLoadStageSamp(void);
extern Task* fn_8003DB34(void* fn);
void fn_80016580(Tk_80016580* t);

inline int HitCached(W_800121D8* w, U_800121D8* u, f32 xc)
{
    switch (lbl_80309EC8.x19a) {
    case 10:
    case 11:
        if (lbl_80309EC8.x110 == xc && lbl_80309EC8.xc0[0] == w->x38[0] && lbl_80309EC8.xc0[1] == w->x38[1]
            && lbl_80309EC8.xc0[2] == w->x38[2]) {
            u->x8 = lbl_80309EC8.x160;
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
                o->x164 = 0.0f;
                o->x1ec |= 0x20000000;
            }
        }
    }
}

void fn_800121D8(Task* t)
{
    W_800121D8* w = t->work;
    U_800121D8* u = w->u;
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
    lbl_80309EC8.x19a = 11;
    lbl_80309EC8.x110 = d;
    fn_80071CF0(w->x38, lbl_80309EC8.xc0);
    lbl_80309EC8.x160 = c;
    c = u->xc;
    fn_80061C80(w->x20, 0.0f, u->x8, c, 0);
    w->x20[0] = w->x20[0] + w->x38[0];
    w->x20[2] = w->x20[2] + w->x38[2];
    w->x20[1] = c;
    fn_80071F84(w->x2c, w->x38, w->x20);
    u->x8 += 1.0f;
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

void fn_80017320(void) {
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
extern int fn_80018B80(f32*);
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
    f = u->x164;
    njPushMatrixEx();
    fn_80286EE8();
    fn_8028B498();
    if (fn_80018B80(&u->x164)) {
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

void fn_80007514(u32 *a, u32 *b)
{
    *b = lbl_803478A0;
    *a = lbl_803478A4;
}

s32 fn_80008258(u32 *out)
{
    u32 n = *(u32 *)(lbl_803478DC + 0x34);
    *out = (n + 0x1f) & ~0x1fu;
    return 1;
}

void fn_80008308(s32 a, s32 b)
{
    fn_8000832C(a, b, 0);
}

void fn_80008694(s32 a, s32 b, s32 c, s32 d)
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

void fn_80009FBC(u8 *p)
{
    if (p[0x19] == 0xff) p[0x18] |= 0x40;
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
    s8 k = (s8)lbl_8030B7F4[i + 0x328];
    return *(s16 *)(lbl_8030B7F4 + k * 0x5c + 0x1c);
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
    fn_80071CF0(lbl_80309EC8.x58, a);
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

s32 fn_80020060(Ent_80020060* p) {
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

inline int Hit(W_80014474* w, U_80014474* u, f32 xc)
{
    switch ((*(G_80014474*)&lbl_80309EC8).x19a) {
    case 10:
    case 11:
        if ((*(G_80014474*)&lbl_80309EC8).x110 == xc && (*(G_80014474*)&lbl_80309EC8).xc0[0] == w->x38[0] && (*(G_80014474*)&lbl_80309EC8).xc0[1] == w->x38[1]
            && (*(G_80014474*)&lbl_80309EC8).xc0[2] == w->x38[2]) {
            u->x8 = (*(G_80014474*)&lbl_80309EC8).x160;
            return 1;
        }
    }
    return 0;
}

inline void Reset(void)
{
    Tk_80014474** p;
    s8 i;
    for (i = 0, p = ((Tk_80014474**)lbl_80309E24); i < 14; p++, i++) {
        if (*p != NULL) {
            Unit_80014474* o = (*p)->work.uw->w;
            o->x164 = 0.0f;
            o->x1ec |= 0x20000000;
        }
    }
    fn_80011208(-1, -1, 0);
}

void fn_80014474(Tk_80014474* t)
{
    W_80014474* w = t->work.w;
    U_80014474* u = w->u;
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
            fn_80071CF0(lbl_80309EC8.x4c, w->x20);
            fn_80071CF0(lbl_80309EC8.x58, w->x38);
            fn_800614FC(lbl_80309EC8.x64, w->x2c);
            break;
        }
    case 1:
        Reset();
        d = u->xc;
        c = u->x8;
        lbl_80309EC8.x19a = 11;
        lbl_80309EC8.x110 = d;
        fn_80071CF0(w->x38, lbl_80309EC8.xc0);
        lbl_80309EC8.x160 = c;
        break;
    case 2:
        Reset();
        break;
    }
}

int fn_8001FABC(Tk_8001FABC* t)
{
    Unit_8001FABC* u;
    Wk_8001FABC* w;
    Vec pos;
    f32 d;
    int ang0;
    int ang;
    s16 kind;

    w = t->work;
    u = w->w;
    if (fn_8001EE24(t, &pos) == 0) {
        return 0;
    }
    fn_80071CF0(&pos, &u->x110);
    if ((u->ents[u->xe4].flags & 0x10000000) || (u->xec & 0x800000) || fn_80017A14(u) != 0) {
        return 0;
    }
    if (pos.x == w->x1c && pos.z == w->x24) {
        return 0;
    }
    kind = u->ents[u->xe4].kind;
    ang = fn_80071C74(w, pos.x, pos.z);
    ang0 = ang;
    switch (kind) {
    case 0x13:
        ang = fn_80071C34(pos.x, pos.z, w->x1c, w->x24);
        break;
    }
    if ((u->ents[u->xe4].flags & 0x1000000) || (u->xf0 & 0x20000000)) {
        switch (u->x6) {
        case 0x13:
            fn_80071BCC(u->x104, ang0, u->x130);
            break;
        default:
            fn_80071BCC(u->x104, ang0, u->x12c);
            break;
        }
    }
    if (u->ents[u->xe4].flags & 0x10000) {
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
    d = fn_8006116C(ang - w->x2c);
    if (d < 0.0f) {
        d = -1.0f * d;
    }
    if (d < u->x128) {
        w->x2c = ang;
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
        u->x11c = fn_8006116C(w->x2c);
        u->x120 = fn_8006116C(ang);
        u->x124 = 0.0f;
        w->x2c = ang;
        u->xf0 |= 0x200;
        return 0;
    default:
        u->x11c = fn_8006116C(w->x2c);
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

s32 fn_8000810C(void* a, void* b) {
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

s32 fn_8001DDE0(Task* t, u8* list) {
    u8* p;
    void* d = FLD(t->work, 0x4c, void*);
    if (list) {
        for (p = list;; p += 0x10) {
            s16 lo = FLD(p, 0, s16);
            s16 hi = FLD(p, 2, s16);
            void* obj;
            if (lo < 0) {
                break;
            }
            if ((((s32)hi << 16) | lo) == 0x30032) {
                obj = FLD(p, 0xc, void*);
                if (fn_8003DCF4(obj, d)) {
                    return FLD(obj, 0x10, s16);
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

void fn_8001DCA0(u8* o) {
    if (FLD(o, 0x1dc, void*)) {
        fn_8001DD00(o, (s8)FLD(o, 0x20, s16));
        lbl_80309730[(s8)o[0]].b9 = 1;
    }
}

void fn_8001D14C(u8* o) {
    if (FLD(o, 0xec, u32) & 0x10) {
        if (FLD(o, 0x1dc, void*)) {
            fn_8001DD00(o, (s8)FLD(o, 0x20, s16));
            lbl_80309730[(s8)o[0]].b9 = 1;
        }
        FLD(o, 0xec, u32) &= ~0x10;
        FLD(o, 0x134, s32) = 1;
    }
    FLD(o, 0xec, u32) &= ~0x40000;
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
    fn_80071CF0(lbl_80309EC8.x4c, p);
}

f32 fn_8001359C(Vec3* obj, f32* out) {
    f32 b;
    f32 a;
    Vec3 v;
    f32 r;

    r = fn_800114AC(&v, &a, &b, 1);
    if (a > b) {
        *out = a;
    } else {
        *out = b;
    }
    *out = 2.0f * *out;
    v.y = 0.0f;
    fn_80071CF0(&v, obj);
    return r;
}

f32 fn_8001363C(Vec3* obj, f32* out) {
    f32 b;
    f32 a;
    Vec3 v;
    f32 r;

    r = fn_800114AC(&v, &a, &b, 0);
    if (a > b) {
        *out = a;
    } else {
        *out = b;
    }
    *out = 2.0f * *out;
    v.y = 0.0f;
    fn_80071CF0(&v, obj);
    return r;
}

void fn_8001E4A0(void *a, NJS_POINT3 *v, void *c, void *d)
{
    Ctx8001E4 *o = *(Ctx8001E4 **)((u8 *)c + 0x24);
    fn_800615B4(a, &v->x, o->sub);
    v->x = v->x + o->off.x;
    v->y = v->y + o->off.y;
    v->z = v->z + o->off.z;
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
            fn_80061F58((u8*)o->data + 0x6c, 0x38, 0);
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

void fn_80019D7C(Top_80019D7C* t) {
    Inner_80019D7C* in = t->w->in;
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

void fn_8001C348(Tk_8001C348* t) {
    W_8001C348* w = t->mid->w;
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

void fn_8001DE78(Task_8001DE78* t, s8 which, Item* list) {
    Item* p;
    Work_8001DE78* d = t->mid->w;
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

void fn_800143A0(Tk143 *t)
{
    Wk143 *w = t->work;
    Sub143 *sub = w->sub;
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
    Dat *d;
    s16 k;
    s16 m;
    if (t == 0) {
        return 0;
    }
    d = t->work->x4c;
    k = fn_80020094(t->work, 1, -1, 1);
    if (k < 0) {
        return 0;
    }
    if (fn_80008274(d->x2) == 0xe9) {
        f32 s = 0.8f;
        t->work->x34 = s;
        t->work->x38 = s;
        t->work->x3c = s;
        return 1;
    }
    m = d->xdc[k].xe;
    if (m == 0) {
        return 0;
    }
    {
        f32 s = 0.1f * m + 1.0f;
        t->work->x34 = s;
        t->work->x38 = s;
        t->work->x3c = s;
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

Node_80008800* fn_80008800(Ent_80008800* t)
{
    Node_80008800* head = 0;
    Node_80008800* cur = 0;
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
                Node_80008800* prev;
                fn_80061F58(&cur->x8, 0x10, 0);
                prev = cur;
                cur = cur->x8;
                cur->xc = prev;
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

void fn_80006C00(NJS_MKEY_F_80006C00* keys, u32 i, u32 nbKeys, f32* out) {
    f32 div[2] = {1.0f, 1.0f};
    NJS_MKEY_F_80006C00* k1 = &keys[i];
    NJS_MKEY_F_80006C00* k2 = &keys[(i + 1) % nbKeys];
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
    s32 id;
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
            if ((s8)id >= 0 && (s8)id < 12 && (s8)id == want) {
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

s16 fn_80020094(Wk_80017018 *w, s16 a, s16 b, s8 flag) {
    s16 i = 0;
    Dat *u = w->x4c;
    Ent18 *r;

    if (a == 0x16) a = 0x15;
    for (; u->xdc[i].x2 != 3; i++) {
        r = &u->xdc[i];
        if (a != r->x0) continue;
        switch (a) {
        case 24:
        case 29:
        case 30:
            if (b != r->xc) continue;
            if (flag == 0) u->xe0 = fn_800300C4(u->xdc[i].x4);
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
            if (flag == 0) u->xe0 = fn_800300C4(u->xdc[i].x4);
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

static inline s16 FindRec(Dat* u, s16 a, s16 b) {
    s16 i;
    for (i = 0; u->xdc[i].x2 != 3; i++) {
        if (a == u->xdc[i].x0) {
            if (b >= 0) {
                if (b == u->xdc[i].xc) return i;
            } else {
                return i;
            }
        }
    }
    return -1;
}

s32 fn_8001ECB4(Task* t, s16 a, s16* out, s16 b) {
    Wk_80017018* wk = t->work;
    Dat* u = wk->x4c;
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
    if (u->xdc[k].x10 || (u->xf0 & 0x40000)) {
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

extern s32 fn_800205B8(s32 id);
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
                m->x164 = 0.0f;
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

s32 fn_8001EBA4(O_8001EBA4 *o, s16 idx) {
    C_8001EBA4 *c = o->w->c;
    s32 v;
    f32 f;
    if (c->x64 == idx) {
        return 0;
    }
    if ((c->x6 == 2 || c->x6 == 7) && c->x204 != 0) {
        v = c->tab[c->x204].x6;
    } else {
        v = c->tab[idx].x6;
    }
    f = c->tab[idx].x10;
    if (f < 1.0f && (c->xf0 & 0x40000)) {
        f = 5.0f;
    }
    f = 1.0f / f;
    if (fn_80076170(0.0f, f, o->w, v, c->tab[idx].x0, c->tab[idx].xc)) {
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
s32 fn_80014A54(u8 sel, u32 val) {
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
    Wk_8001FABC *e = w->ent;
    Unit_8001FABC *in = e->w;
    if (in->ents[in->xe4].flags & 0x10000) {
        e->x2c = fn_80071C74(e, 0.0f, 0.0f);
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

void fn_80013FD0(Tk_80013FD0* t)
{
    W_80013FD0* w = t->work;
    U_80013FD0* u = w->u;

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
