#include "types.h"
#include "ninja.h"
#include "game/drawstate.h"
#include <dolphin/os.h>
#include "game/menu.h"
#include <dolphin/vi.h>
#include <dolphin/gx.h>
#include <dolphin/types.h>
#include "game/task.h"
void VISetNextFrameBuffer(void *fb);
void VIFlush(void);
void VIWaitForRetrace(void);
extern void *lbl_803476AC;
extern u32 *lbl_803476C0;
void fn_801D4A2C(s32 a, s32 b, s32 c, void *d, s32 e, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5, f32 f6);
extern s32 lbl_80347568[2];
typedef struct Sub { u8 pad[0x20]; s32 val; } Sub;
typedef struct Outer { u8 pad[4]; Sub *sub; } Outer;
void fn_801D5A50(s32 a, s32 b, s32 c, s32 d, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5, f32 f6);
extern Outer *lbl_80347618;
void fn_802275A4(s32 v, s32 flag);
void fn_801E17E0(void *p);
extern Outer *lbl_80347614;
void *fn_801E1BDC(s32 size);
extern s32 lbl_8034761C;
typedef struct Thing { u8 pad[8]; void *f8; void *fc; } Thing;
typedef struct Quad {
    s32 type;  /* 0x00 */
    f32 f04;   /* 0x04 */
    s32 f08;   /* 0x08 */
    void *f0c; /* 0x0C */
    f32 f10;   /* 0x10 */
    f32 f14;   /* 0x14 */
    f32 f18;   /* 0x18 */
    f32 f1c;   /* 0x1C */
    f32 f20;   /* 0x20 */
    f32 f24;   /* 0x24 */
    f32 f28;   /* 0x28 */
    f32 f2c;   /* 0x2C */
} Quad;
typedef struct Ctx {
    u8 pad_0[0x4];
    s32 f4;
    f32 f8;
    f32 fc;
    f32 f10;
    f32 f14;
    f32 f18;
    f32 f1c;
    f32 f20;
    f32 f24;
    u8 f28[0x28];
    s32 f50;
    u8 pad1[0x18];
    f32 f6c;
    f32 f70;
    f32 f74;
    u8 pad78[0xa0];
    s32 f118;
    u8 pad11c[0x18];
    f32 f134;
    f32 f138;
    f32 f13c;
} Ctx;
void fn_802871D8(void *p);
extern Ctx lbl_8030E830;
typedef struct Ent { u32 key; u32 next; s16 val; s16 pad; } Ent;
typedef struct Req { u32 key; void *next; } Req;
extern Ent lbl_802F65C0[8];
typedef struct RelocEnt { u32 ptr; u32 b; u32 c; } RelocEnt;
typedef struct RelocTbl { RelocEnt *ents; s32 count; } RelocTbl;
/* The work of a model-load task (fn_801DB818); lbl_80312D00 holds the live tasks. */
typedef struct MldWork {
    u32 w00;
    char *name;
    void *x8;
    u8 pad0c[4];
    u32 w10;
    s32 w14;
    u32 w18;
} MldWork;
extern Task *lbl_80312D00[16];
void *memcpy(void *dst, const void *src, u32 n);
extern s32 lbl_8034754C;
extern u8 lbl_8030EA1C[];
typedef struct Ob { u8 pad0[2]; s16 s2; u8 pad1[0x48]; void *p4c; } Ob;
typedef struct { u16 size; u16 type; } Hdr;
typedef struct { u16 cnt; u16 pad; } Cnt;
typedef struct { u8 pad[4]; f32 x, y, z; u8 pad2[0x1c - 0x10]; } Ent_801DFA9C;
typedef struct { Hdr* stream; Ent_801DFA9C* ent; u8 pad[4]; } Item_801DFA9C;
extern s32 fn_801CB0A4(s32 type);
s32 fn_801DFA9C(Item_801DFA9C* items, s32 count);
typedef struct Mo { u8 pad0[4]; u8 m4[0x28]; u8 m2c[0x1C]; s32 x48; void *x4c; } Mo;
void njPushMatrixEx(void);
void njPopMatrixEx(void);
void fn_80286EE8(void);
void fn_8028B498(void);
void fn_801E04E8(void *m, s32 a, void *b, void *c);
/* A heap block's 0x20-byte header (the user pointer is 0x20 past it). */
typedef struct MemBlk {
    void *data;
    u32 size;
    u8 pad8[0x14 - 8];
    struct MemBlk *prev;
    struct MemBlk *next;
    u8 pad1c;
    s8 tag;
    u8 tag2;
    s8 flag;
} MemBlk;
typedef struct MemHeap {
    MemBlk *first;
} MemHeap;
void *fn_801E184C(MemHeap *heap, s32 idx, s32 mode, u32 n);
extern MemHeap lbl_802F6748[];
void GXInvalidateVtxCache(void);
void GXInvalidateTexAll(void);
extern u8 lbl_80311B00[];
void fn_801E1718(void *p);
extern u8 *lbl_80347608;
void fn_801D843C(void *a, s32 b, s32 c, s32 d, s32 e, s32 f);
typedef struct Holder801D { u8 pad_0[0x18];
 u8 b18; u8 b19; u8 pad1a[0x24 - 0x1a]; void *f24; } Holder801D;
extern Holder801D *lbl_80347654;
extern Holder801D *lbl_80347660;
extern u32 lbl_80312D40[4];
void *fn_801E1A74(s32 a, u32 n);
extern s32 lbl_80347550;
typedef struct {
    s32 active;
    s32 x4, x8, xc, x10;
    u32 x14;
    s32 x18;
} Obj_80311C30;
extern Obj_80311C30 lbl_80311C30;
/* word 0 is compared as a key and also returned as a pointer */
typedef struct ReqB { union { u32 key; void *obj; } u; void *next; } ReqB;
typedef struct Obj { u8 pad[0x18]; u8 mtx[1]; } Obj;
typedef struct Node {
    Obj* obj;
    u8 pad4[4];
    f32 pos[3];
    f32 rot[3];
    f32 scl[3];
    struct Node* child;
    struct Node* next;
} Node;
extern void njTranslateEx(f32* p);
extern void njRotateEx(f32* r, s32 a);
extern void njScaleEx(f32* s);
extern void fn_80291C44(void* m);
void fn_801D25DC(Node* n);
#define BODY(n)     njPushMatrixEx();     fn_80286EE8();     fn_8028B498();     njTranslateEx((n)->pos);     njRotateEx((n)->rot, 0);     njScaleEx((n)->scl);     if ((n)->obj != 0) {         fn_80291C44((n)->obj->mtx);     }
typedef struct Vtx { u16 idx; s16 flag; } Vtx;
typedef struct Mesh {
    f32 cx;
    u8 pad4[4];
    f32 cz;
    f32 r2;
    f32* verts;
    s32 count;
    u8 pad18[0x58 - 0x18];
} Mesh;
typedef struct Node_801D30DC {
    Mesh* mesh;
    u8 pad4[2];
    s16 id;
    f32 pos[3];
    f32 rot[3];
    f32 scl[3];
    struct Node_801D30DC* child;
    struct Node_801D30DC* next;
} Node_801D30DC;
typedef struct Hit {
    NJS_POINT3 a;
    NJS_POINT3 b;
    NJS_POINT3 c;
    s16 flag;
    u8 pad26[0x32 - 0x26];
    s16 id;
} Hit;
extern void njInvertMatrix(void* m);
extern s32 fn_801D48BC(f32* pt, f32* a, f32* b, f32* c);
extern void fn_80290668(f32* a, f32* b, f32* c, f32* n);
s32 fn_801D30DC(NJS_POINT3* p, Node_801D30DC* n, Hit* out);
typedef struct Anim {
    u32 flags;
    f32 start[4];
    f32 end[4];
    f32 delta[4];
    f32 cur[4];
    s32 total;
    s32 count;
    s32 delay;
} Anim;
typedef struct {
    s8 st[9];     /* 0x00 */
    u8 pad09[3];
    s32 wc;       /* 0x0c */
    s16 w10;      /* 0x10 */
    u8 pad12[2];
    Anim a0;      /* 0x14 */
    Anim a[3];    /* 0x64 */
    Anim b[3];    /* 0x154 */
    s32 w244;     /* 0x244 */
} State801D;
extern State801D* lbl_8034765C;
extern f32 lbl_80311DF0[];
extern s32 fn_801A3510(void);
extern void fn_801D89D4(void* p, s32 a, s32 b, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5, f32 f6, f32 f7, f32 f8);
extern void fn_801D8AB4(Anim* p, s32 a, s32 b, f32 f1, f32 f2);
typedef struct { u8 pad[0x8]; u32 x8; } PadState;
typedef struct { PadState* pad; u8 pad4[0x14]; } PadInfo;
extern s32 lbl_80347658;
extern PadInfo lbl_80311A60;
typedef struct Node801D Node801D;
typedef struct { u8 pad[0x10]; u32 x10; } Inner;
struct Node801D {
    Inner* a;       /* 0x00 */
    u8 pad04[0x28];
    Node801D* c1;   /* 0x2c */
    Node801D* c2;   /* 0x30 */
};
void fn_801DA748(Node801D* n);
typedef struct Node801DF6 Node801DF6;
typedef struct { void* x0; } Data801DF6;
struct Node801DF6 {
    u32 flags;       /* 0x00 */
    Data801DF6* d;   /* 0x04 */
    u8 pad08[0x24];
    Node801DF6* c1;  /* 0x2c */
    Node801DF6* c2;  /* 0x30 */
};
extern s32 fn_801CB1AC(void* p);
void fn_801DF600(Node801DF6* n, s32* count, s32* total);
typedef struct {
    f32 dist;          /* 0x00 */
    NJS_POINT3 pos;    /* 0x04 */
    NJS_VECTOR dir;    /* 0x10 */
} Hit801E;
typedef struct {
    NJS_POINT3 min;  /* 0x00 */
    NJS_POINT3 max;  /* 0x0C */
    f32 flag;        /* 0x18 */
} Box801E;
typedef struct {
    NJS_POINT3 c;     /* 0x00 */
    NJS_POINT3 d;     /* 0x0C */
} Ref801E;
extern void njUnitVector(NJS_VECTOR* v);
extern void njCalcVector(f32* m, NJS_VECTOR* v, NJS_VECTOR* out);
extern void fn_802900C0(NJS_POINT3* p, NJS_POINT3* c, NJS_POINT3* out);
extern f32 fn_80291A5C(f32 v);
extern f32 fn_801DFE48(NJS_POINT3* p, Box801E* box);
typedef struct DataEntry {
    void *base;
    s32 offset;
} DataEntry;
typedef struct DataTable {
    u8 *base;
    s32 count;
    s32 *offsets;
    s32 *work;
    s32 *data;
} DataTable;
extern s32 *fn_8022ACA8(s32);
extern void *fn_801E1C7C(s32);
extern void *fn_801CC3C4(const char *name);
extern f32 lbl_80347F28;
extern f32 lbl_80347F2C;
extern const char lbl_802C456C[];
void fn_801DBE1C(const char *fmt, ...);
extern s32 lbl_803475CC;
extern s32 lbl_80311AD4[11];
void njRotateZXY(NJS_MATRIX m, s32 x, s32 y, s32 z);
extern NJS_VECTOR lbl_802F66AC;
extern NJS_VECTOR lbl_802F6694;
extern NJS_VECTOR lbl_802F66A0;
extern NJS_VECTOR lbl_802F6688;
extern s32 lbl_8030EA10[3];
double atan2(double y, double x);
extern const char lbl_802C4698[];
typedef struct TblEnt {
    s16 a;
    s16 b;
} TblEnt;
typedef struct Cursor {
    s16 out0;
    s16 count;
    TblEnt *tbl;
    u32 f8;
    s16 idx;
    s16 outB;
    s16 pad10;
    s16 mode;
} Cursor;
typedef struct Holder {
    void *a;
    u32 pad04;
    u32 pad08;
    void *c;
    u32 pad10;
    void *e;
} Holder;
void fn_801E8580(void *p);
typedef struct Ctx_801DDECC {
    void *r0;
    void *a;
    u32 b;
    u32 zero0c;
    void *c;
    void *r14;
    u8 sub[2];
    s16 k1a;
    s16 k1c;
    s16 k1e;
} Ctx_801DDECC;
void *fn_801E84C0(void *p);
void *fn_801DDF48(void *sub, void *c, s16 x, s16 y);
extern s32 DVDGetDriveStatus(void);
extern u32 lbl_80347268;
typedef struct {
    s32 a;
    s32 b;
    s32 c;
} Vec3i;
typedef struct {
    Vec3i cur;
    Vec3i next;
} Pair3i;
typedef struct {
    s32 a;
    s32 b;
    s32 c;
    f32 d;
    f32 e;
    f32 f;
    f32 g;
} Rec28;
typedef struct {
    s32 a0;
    s32 a4;
    u32 a8;
    void* ac;
    void* b0;
} Obj68DC;
typedef struct {
    unsigned char pad[0xa];
    s8 err;
} PadStatus71C4;
extern PadStatus71C4* lbl_8034763C;
extern void PADControlMotor(s32 chan, u32 cmd);
extern s32 PADRecalibrate(u32 mask);
extern u32 PADRead(PadStatus71C4* status);
extern u32 lbl_802F6558[];
extern u32 lbl_80311A00[];
extern s32 lbl_8034757C;
extern s32 lbl_80347630;
extern s32 lbl_80347634;
extern s32 lbl_80347640;
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
extern void *lbl_80347650;
extern void *lbl_803475A8;
void *fn_802268E8(void *a, void *b);
void fn_801D8B94(void);
void *memset(void *d, s32 c, u32 n);
void fn_801D8DBC(void);
typedef struct {
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    s32 e;
    s32 f;
    s32 g;
} PadMotor6C3C;
extern s32 lbl_80347668;
extern u8 lbl_80311E00[];
extern const char lbl_802C44A8[];
void MemCopy(void *dst, void *src, u32 n);
void fn_8028B784(void *p, f32 a, f32 b, f32 c);
extern const char lbl_802C46EC[];
extern s32 lbl_80347700;
void fn_801E15FC(MemHeap *h, void *p);
typedef struct Ent_801DDCA8 {
    s32 x0;
    void* x4;
    u8 pad8[8];
    void* x10;
    u8 pad14[4];
    void* x18;
    u8 pad1c[0x24 - 0x1c];
} Ent_801DDCA8;
typedef struct Pool_801DDCA8 {
    Ent_801DDCA8* ents;
    s16 count;
    s16 x6;
} Pool_801DDCA8;
extern u8 lbl_80302A00[];
extern u8 lbl_8031693C[];
extern u8 lbl_80346A80[];
extern u8 lbl_80347888[];
extern u8 lbl_8034D460[];
extern u8 lbl_8034D484[];
extern u8* lbl_8034767C;
extern u32 lbl_80347678;
extern void* lbl_803476B0;
extern void* lbl_803476B4;
extern u32 lbl_803475B8;
extern u32 lbl_803475BC;
extern u32 lbl_803475C0;
extern u32 lbl_803475C4;
extern u32 lbl_803475C8;
extern u32 lbl_8034768C;
extern u8 lbl_80347690;
extern void fn_801D22CC(void);
extern void fn_801C62D8(void);
extern void fn_801C6248(s32 a);
extern void fn_80296F48(void);
void fn_801DD5E8(Angle *rot, NJS_POINT3 *p);
extern void njRotateX(NJS_MATRIX m, s32 a);
extern void njRotateY(NJS_MATRIX m, s32 a);
typedef struct { u8 pad[4]; f32 x, y, z; u8 pad2[0x1c - 0x10]; } Ent_801DFB7C;
typedef struct { Hdr* stream; Ent_801DFB7C* ent; u8 pad[4]; } Item_801DFB7C;
typedef struct Slot { s32 key; u8 pad[0x20]; } Slot;
typedef struct SlotTab {
    Slot *slots;
    s16 count;
    s16 used;
} SlotTab;
extern s32 lbl_803475AC;
extern void OSReport(const char *msg, ...);
typedef struct { s16 a; s16 b; s32 off; } Ent_801DE504;
typedef struct {
    void* list;
    void* model;
    NJS_TEXLIST* texlist;
    u32 xc;
    NJS_TEXNAME** base;
    Ent_801DE504* ents;
    s16 count;
    s16 cur;
} Obj_801DE504;
extern void fn_801E85BC(void* list, s16 dx, s16 dy);
void fn_801E7194(s32 id, void* model, void* motion, void* shape, f32 frame);
void fn_801E4CB0(s32 id, void* model);
typedef struct { f32 a, r, g, b; } Argb4;
typedef struct {
    NJS_POINT3 p0, p1;      /* 0x00, 0x0C */
    NJS_POINT3 s0, s1;      /* 0x18, 0x24 */
    Argb4 c0, c1;           /* 0x30, 0x40 */
} Key_801DE8C0;
typedef struct { Key_801DE8C0* keys; s32 count; } Keys_801DE8C0;
typedef struct {
    u8 pad0[0x1C];
    Argb4 colour;
    u8 pad2C[0x50 - 0x2C];
    NJS_POINT3 scl;
    u8 pad5C[0xB4 - 0x5C];
    NJS_POINT3 pos;
} Obj_801DE8C0;
extern void fn_801E66E0(Obj_801DE8C0* o);
typedef struct Payload {
    void *x0;
    u8 pad4[8];
    void *xc;
    u8 pad10[4];
    void *x14;
    u8 pad18[8];
} Payload;
typedef struct Entry {
    s32 ref;
    Payload data;
} Entry;
typedef struct Pool {
    Entry *base;
    s16 count;
    s16 live;
} Pool;
typedef struct Node_801D24D0 {
    Obj* obj;
    u8 pad4[2];
    s16 id;
    f32 pos[3];
    f32 rot[3];
    f32 scl[3];
    struct Node_801D24D0* child;
    struct Node_801D24D0* next;
} Node_801D24D0;
typedef struct Ctx_801D24D0 { u8 pad[0x32]; s16 id; } Ctx_801D24D0;
extern void njPushMatrix(void* m);
typedef struct Frm { s16 val; s16 dur; } Frm;
typedef struct Anim_801DD7D8 {
    s16 val;     /* 0x00 */
    s16 count;   /* 0x02 */
    Frm *frames; /* 0x04 */
    s32 flag;    /* 0x08 */
    s16 idx;     /* 0x0c */
    s16 timer;   /* 0x0e */
    u8 pad10[2];
    s16 step;    /* 0x12 */
} Anim_801DD7D8;
typedef struct E12 { f32 a, b, c; } E12;
typedef struct Res {
    s16 x0;
    s16 x2;
    f32 x4, x8, xc, x10, x14, x18, x1c, x20, x24, x28, x2c, x30, x34, x38, x3c, x40, x44;
    Node801DF6 *x48;
    E12 *x4c;
} Res;
extern void fn_801DF500(Node801DF6 *n, E12 **p, E12 *end);
typedef struct Anim_801D78EC {
    u32 f00;
    f32 f04;
    s32 f08;
    u32 f0c;
    f32 f10;
    f32 f14;
    f32 f18;
    f32 f1c;
    f32 f20;
    f32 f24;
    f32 f28;
    f32 f2c;
} Anim_801D78EC;
typedef struct Vtx_801D78EC { f32 x, y, z; u32 c; } Vtx_801D78EC;
extern f32 fn_801DBD9C(f32 z);
extern void fn_8028A26C(s32 a);
extern void fn_8028A0F4(Vtx_801D78EC *v, s32 n);
extern void fn_8028A268(void);
typedef struct { s32 map; s32 unk4; char room; } MapInfo;
extern MapInfo lbl_80311AC0;
extern s32 lbl_803474E0;
extern s32 lbl_803475D4;
extern s32 lbl_803475B0;
extern char lbl_802C4590[];
extern char lbl_802C45A0[];
extern void sndOutputMode(s32 mode);
extern u32 OSGetSoundMode(void);
extern void fn_80219378(char*);
extern void fn_801DBE88(void);
extern void fn_801D77B8(void);
extern void fn_80228A20(void);
extern void fn_80101828(void);
extern void fn_8000A118(void);
extern void fn_801F7B04(s32 v);
extern void fn_801C8DF0(void);
extern void fn_801CC3A4(void);
extern void fn_80218678(void);
extern void* heap_main;
extern void* heap_font;
extern void* lbl_80346720;
extern void* lbl_8034769C;
extern void* lbl_803476A0;
extern void* lbl_803476A4;
extern void* lbl_803475E4;
extern void* lbl_803475E8;
extern void* lbl_803475EC;
extern void* lbl_803475F0;
extern void* lbl_803475F4;
extern s32 lbl_803476DC;
extern void fn_80005AD8(void* heap, void* p);
extern void fn_80005954(void* heap);
extern void fn_801DC420(void);
extern void fn_800976F8(void);
extern void fn_80230F28(void);
extern void fn_801CAE90(void);
extern void fn_8022807C(void);
extern void fn_801D13D8(void);
extern void fn_801E1EE4(void);
extern void FontFree(void);
extern void fn_80299058(void);
extern void fn_80228984(void);
extern void fn_801A473C(void);
extern void fn_801D71C4(void);
extern void fn_80219C84(void);
extern u8 lbl_802F8CF0[], lbl_802F8E80[], lbl_802F8D40[], lbl_802F8D90[];
void fn_801D8840(Anim *a);
f32 fn_8022975C(void *a, s32 b, s32 c, f32 x, f32 y, f32 z, f32 w);
typedef struct Key {
    f32 a[3];
    f32 da[0x3];
    f32 b[3];
    f32 db[0x3];
    f32 c[4];
    f32 dc[0x4];
} Key;
/* 0x50 */
typedef struct KeySet {
    Key* keys;
    s32 count;
} KeySet;
/* Needs include/game/sprite.h to declare `Sprite* fn_801D68C4(void* bank, s32 index)`:
   the original does not mask the index (u16 adds clrlslwi). */
typedef struct Sprite Sprite;
typedef struct SpriteBank {
    u8* base;      /* 0x0 sprite data */
    s32 x4;        /* 0x4 */
    s32* offsets;  /* 0x8 offset of each sprite from base */
} SpriteBank;
/* Relocates a block's self-relative offsets into pointers (0 stays 0). */
typedef struct E18 { u8 pad0[0xc]; u32 f0c; u32 f10; u8 pad14[4]; } E18;
typedef struct E8 { u32 pad0; u32 f4; } E8;
typedef struct Hdr_801DA6A8 { u32 f0; u32 f4; u8 pad8[0x10]; s16 n18; s16 n1a; } Hdr_801DA6A8;
typedef struct KeyEnt {
    u32 a;
    u32 b;
    u32 key;
} KeyEnt;
typedef struct KeyList {
    KeyEnt *ents;
    u32 count;
} KeyList;
typedef struct L3 {
    u8 pad[0x20];
    u32 f20;
} L3;
typedef struct L2 {
    u8 pad[0xc];
    L3 *fc;
} L2;
typedef struct L1 {
    u8 pad[8];
    L2 *f8;
} L1;
typedef struct Top {
    L1 *f0;
} Top;
extern s32 fn_80299040(void *p);
extern void fn_80291428(s32 a);
extern void fn_802913E8(s32 a, s32 b);
typedef struct {
    u32 a;
    u32 b;
    u32 c;
} Triple616C;
s32 fn_80227AF0(s32 i, void *p);
void *fn_801E13B0(void *p, u32 size);
void fn_801DAEB8(void *p);
typedef struct TexHdr {
    u8 pad0[0x10];
    u32 off;
} TexHdr;
typedef struct SpinObj {
    u8 pad00[0x2];
    s16 k02;
    u8 pad04[0x18];
    f32 angle;     /* 0x1c */
    f32 speed;     /* 0x20 */
    f32 rate;      /* 0x24 */
    u8 pad28[0x24];
    void *model;   /* 0x4c */
} SpinObj;
void fn_801DFC5C(void *a, void *b, s16 c, f32 d);
typedef struct {
    s16 w, h, hw, hh, x, y, x1, y1, z0, z1;
} Rect14;
typedef struct {
    f32 x, y;      /* 0x00 */
    f32 pad08;     /* 0x08 */
    f32 sx, sy;    /* 0x0C */
    u32 colour;    /* 0x14 */
    NJS_TEXLIST* texlist; /* 0x18 */
    Rect14* data;  /* 0x1C */
} Obj20;
typedef struct {
    u16 enable;    /* 0x00 */
    u8 pad02[6];
    f32 z;         /* 0x08 */
    f32 colour;    /* 0x0C */
    u32 attr;      /* 0x10 */
    u32 blend;     /* 0x14 */
    f32 ca, cb;    /* 0x18 */
    u8 pad20[4];
    u32 col;       /* 0x24 */
    u8 pad28[0x34 - 0x28];
    f32 x, y;      /* 0x34 */
    f32 w, h;      /* 0x3C */
    f32 ox, oy;    /* 0x44 */
} Desc;
extern void fn_801D6528(u32 colour, NJS_ARGB* out, f32 a, f32 b);
void fn_80005D98(Obj20* obj, s32 a, s32 b, f32 z);
void fn_801D8F18(void);
s32 fn_801D91F4(void);
void fn_801D9508(void);
extern s32 MemEqual(const void *a, const void *b, s32 size);
extern char *strncpy(char *dst, const char *src, u32 n);
extern s32 lbl_803476E0;
extern void *lbl_803476F0;
extern u32 lbl_803476FC;
extern s32 lbl_803476E4;
void *fn_801E1138(MemHeap *heap, void *p, u32 size, s32 mode);
extern s32 lbl_803474DC;
extern void fn_801DB2C8(Task *t);
extern Task *fn_802267AC(void *parent, TaskFunc fn);
extern u32 strlen(const char*);
extern char* strcpy(char*, const char*);
extern const char lbl_802C46C0[];
typedef struct Key_801DEBE4 {
    f32 a[3];
    f32 da[3];
    f32 b[3];
    f32 db[3];
    f32 c[4];
    f32 dc[4];
} Key_801DEBE4;
/* 0x50 */
typedef struct KeySet_801DEBE4 {
    Key_801DEBE4* keys;
    s32 count;
} KeySet_801DEBE4;
typedef struct Key_801DEDC0 {
    f32 a[3];
    f32 da[3];
    f32 b[3];
    f32 db[3];
    f32 c[4];
    f32 dc[4];
} Key_801DEDC0;
/* 0x50 */
typedef struct KeySet_801DEDC0 {
    Key_801DEDC0* keys;
    s32 count;
} KeySet_801DEDC0;

void fn_801D49E4(s32 a, s32 b, s32 c, s32 d, f32 p1, f32 p2, f32 p3, f32 p4) {
    fn_801D4A2C(a, b, c, lbl_80347568, d, 1.0f, 1.0f, p1, p2, p3, p4);
}

typedef struct {
    s32 idx;
    f32 x, y, w, h;
    u32 colour;
    u8 pad[0x34 - 0x18];
} Elem;

typedef struct {
    f32 pad0;
    f32 u, v, u2, v2;
} Cell; /* 0x14 */

typedef struct {
    Cell* cells;
    Elem* elems;
    u32 count;
    u8 pad[8];
    f32 x, y;
} Layout;

void fn_801D4C9C(Layout* lay, u32 flags, u32 mode, s32* tex, s32 vmode, f32 f1, f32 f2, f32 base, f32 f4, f32 a, f32 b);
void fn_801D4C54(Layout* a, u32 b, u32 c, s32 d, f32 p1, f32 p2, f32 p3, f32 p4) {
    fn_801D4C9C(a, b, c, lbl_80347568, d, 1.0f, 1.0f, p1, p2, p3, p4);
}

void fn_801D4F54(Layout* lay, u32 flags, u32 mode, s32* tex, s32 vmode, f32 f1, f32 f2, f32 base, f32 f4, f32 a, f32 b);
typedef struct {
    u8 pad[0xc];
    s32** tex;
} TexInfo;
typedef struct {
    s32 unused0;
    s32 unused4;
    TexInfo* info;
} TexHolder;
typedef struct {
    f32 x, y, z, u, v;
    u32 colour;
} VertexTex;
extern s32 fn_801E7554(void);
extern s32 fn_80299040(void* p);
extern s32 fn_80297DC8(s32 id);
extern VertexTex lbl_80308E30[4];
extern f32 fn_801DBD9C(f32);
extern void fn_801D65B4(u32 colour, u8* out, f32 a, f32 b);
extern void fn_80291064(VertexTex* v, s32 n, s32 mode);
void fn_801D4C9C(Layout* lay, u32 flags, u32 mode, s32* tex, s32 vmode, f32 f1, f32 f2, f32 base, f32 f4, f32 a, f32 b)
{
    DrawState st;
    u8 col[4];
    u32 oldc;
    s32 i;
    VertexTex* v;
    Cell* c;
    Elem* e;

    if (fn_801E7554() != 0)
        return;
    DrawStateDefault2D(&st);
    st.attr_or |= flags;
    if (mode == 1) {
        st.blend_src = 8;
        st.blend_dst = 10;
    }
    DrawStatePush(&st);
    {
        TexHolder* h = (TexHolder*)tex[0];
        TexHolder* t = *(TexHolder**)((u8*)h + 8);
        fn_80299040(tex);
        fn_80297DC8(**(s32**)((u8*)t + 0xc));
    }
    v = lbl_80308E30;
    for (i = 0; i < lay->count; i++) {
        f32 z = fn_801DBD9C(base + 0.0001f * i);
        e = &lay->elems[i];
        c = &lay->cells[e->idx];
        oldc = e->colour;
        fn_801D65B4(oldc, col, a, b);
        e->colour = (col[0] << 24) + (col[1] << 16) + (col[2] << 8) + col[3];
        v[0].x = lay->x + e->x;
        v[0].y = lay->y + e->y;
        v[0].z = z;
        v[0].u = c->u;
        v[0].v = c->v;
        v[0].colour = e->colour;
        v[2].x = lay->x + e->w;
        v[2].y = v[0].y;
        v[2].z = z;
        v[2].u = c->u2;
        v[2].v = c->v;
        v[2].colour = e->colour;
        v[3].x = v[2].x;
        v[3].y = lay->y + e->h;
        v[3].z = z;
        v[3].u = c->u2;
        v[3].v = c->v2;
        v[3].colour = e->colour;
        v[1].x = v[0].x;
        v[1].y = v[3].y;
        v[1].z = z;
        v[1].u = c->u;
        v[1].v = c->v2;
        v[1].colour = e->colour;
        fn_80291064(v, 4, vmode);
        e->colour = oldc;
    }
    DrawStatePop(0);
    DrawStateRestore();
}

void fn_801D4F0C(Layout* a, u32 b, u32 c, s32 d, f32 p1, f32 p2, f32 p3, f32 p4) {
    fn_801D4F54(a, b, c, lbl_80347568, d, 1.0f, 1.0f, p1, p2, p3, p4);
}

void fn_801D4F54(Layout* lay, u32 flags, u32 mode, s32* tex, s32 vmode, f32 f1, f32 f2, f32 base, f32 f4, f32 a, f32 b)
{
    DrawState st;
    u8 col[4];
    u32 oldc;
    s32 i;
    VertexTex* v;
    Cell* c;
    Elem* e;

    if (fn_801E7554() != 0)
        return;
    DrawStateDefault2D(&st);
    st.attr_or |= flags;
    if (mode == 1) {
        st.blend_src = 8;
        st.blend_dst = 10;
    }
    DrawStatePush(&st);
    {
        TexHolder* h = (TexHolder*)tex[0];
        TexHolder* t = *(TexHolder**)((u8*)h + 8);
        fn_80299040(tex);
        fn_80297DC8(**(s32**)((u8*)t + 0xc));
    }
    v = lbl_80308E30;
    for (i = 0; i < lay->count; i++) {
        f32 z = fn_801DBD9C(base + 0.05f
 * i);
        e = &lay->elems[i];
        c = &lay->cells[e->idx];
        oldc = e->colour;
        fn_801D65B4(oldc, col, a, b);
        e->colour = (col[0] << 24) + (col[1] << 16) + (col[2] << 8) + col[3];
        v[0].x = lay->x + e->x;
        v[0].y = lay->y + e->y;
        v[0].z = z;
        v[0].u = c->u;
        v[0].v = c->v;
        v[0].colour = e->colour;
        v[2].x = lay->x + e->w;
        v[2].y = v[0].y;
        v[2].z = z;
        v[2].u = c->u2;
        v[2].v = c->v;
        v[2].colour = e->colour;
        v[3].x = v[2].x;
        v[3].y = lay->y + e->h;
        v[3].z = z;
        v[3].u = c->u2;
        v[3].v = c->v2;
        v[3].colour = e->colour;
        v[1].x = v[0].x;
        v[1].y = v[3].y;
        v[1].z = z;
        v[1].u = c->u;
        v[1].v = c->v2;
        v[1].colour = e->colour;
        fn_80291064(v, 4, vmode);
        e->colour = oldc;
    }
    DrawStatePop(0);
    DrawStateRestore();
}

void fn_801D51C4(s32 a, s32 b, s32 c, f32 p1, f32 p2, f32 p3, f32 p4) {
    fn_801D5A50(a, b, c, lbl_80347618->sub->val, 1.0f, 1.0f, p1, p2, p3, p4);
}

void fn_801D538C(s32 a, s32 b, s32 c, s32 d, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5, f32 f6);
void fn_801D5210(s32 a, s32 b, s32 c, f32 p1, f32 p2, f32 p3, f32 p4) {
    fn_801D538C(a, b, c, lbl_80347614->sub->val, 1.0f, 1.0f, p1, p2, p3, p4);
}

void fn_801D56C8(s32 a, s32 b, s32 c, s32 d, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5, f32 f6);
void fn_801D525C(s32 a, s32 b, s32 c, f32 p1, f32 p2, f32 p3, f32 p4) {
    fn_801D56C8(a, b, c, lbl_80347614->sub->val, 1.0f, 1.0f, p1, p2, p3, p4);
}

void fn_801D52A8(s32 a, s32 b, s32 c, f32 p1, f32 p2, f32 p3, f32 p4) {
    fn_801D5A50(a, b, c, lbl_80347614->sub->val, 1.0f, 1.0f, p1, p2, p3, p4);
}

extern Outer *lbl_80347610;
void fn_801D5DD8(s32 a, s32 b, s32 c, s32 d, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5, f32 f6);
void fn_801D52F4(s32 a, s32 b, s32 c, f32 p1, f32 p2, f32 p3, f32 p4) {
    fn_801D5DD8(a, b, c, lbl_80347610->sub->val, 1.0f, 1.0f, p1, p2, p3, p4);
}

extern Outer *lbl_8034760C;
void fn_801D5340(s32 a, s32 b, s32 c, f32 p1, f32 p2, f32 p3, f32 p4) {
    fn_801D5DD8(a, b, c, lbl_8034760C->sub->val, 1.0f, 1.0f, p1, p2, p3, p4);
}

void fn_801D668C(void) {
    if (lbl_80347614 != 0) {
        fn_802275A4(lbl_80347614->sub->val, 1);
        fn_801E17E0(lbl_80347614);
        lbl_80347614 = 0;
    }
}

void fn_801D6850(void) {
    if (lbl_80347608 == 0) {
        lbl_80347608 = fn_801E1BDC(0x10000 - 0x600);
    }
    lbl_8034761C = -1;
}

void fn_801D6890(void) {
    if (lbl_80347608 != 0) {
        fn_801E1718(lbl_80347608);
        lbl_80347608 = 0;
    }
}

void fn_801D6944(Thing *t) {
    if (t->f8 != 0) {
        t->f8 = 0;
    }
    if (t->fc != 0) {
        fn_801E17E0(t->fc);
        t->fc = 0;
    }
}

extern s32 lbl_80347634;
void fn_801D71BC(s32 v) {
    lbl_80347634 = v;
}

void fn_801D7868(Quad *q, void *p, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5, f32 f6, f32 f7) {
    q->type = 3;
    q->f04 = f1;
    q->f08 = 1;
    q->f0c = p;
    q->f10 = f2;
    q->f20 = f3;
    q->f14 = f4;
    q->f24 = f5;
    q->f18 = f6;
    q->f28 = f7;
    q->f1c = 0.0f;
    q->f2c = 0.0f;
}

void fn_801D78A8(Quad *q, void *p, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5) {
    f32 a = f2 + f4;
    f32 b = f3 + f5;
    q->type = 4;
    q->f04 = f1;
    q->f08 = 1;
    q->f0c = p;
    q->f10 = f2;
    q->f20 = f3;
    q->f14 = a;
    q->f24 = f3;
    q->f18 = a;
    q->f28 = b;
    q->f1c = f2;
    q->f2c = b;
}

typedef struct Msg {
    s16 x0;
    s16 x2;
    s16 x4;
    s16 x6;
    s32 x8;
    s32 xc;
} Msg;
extern void fn_80291424(Msg*, s16);
void fn_801D8080(Msg* a, s16 i) {
    fn_80291424(a, i);
}

void fn_801D9CF0(f32 f1, f32 f2, f32 f3) {
    lbl_8030E830.f50 = 1;
    lbl_8030E830.f6c = f1;
    lbl_8030E830.f70 = f2;
    lbl_8030E830.f74 = f3;
    fn_802871D8(&lbl_8030E830);
}

s32 fn_801DA66C(Req *p) {
    s32 i = 8;
    Ent *e = lbl_802F65C0;
    do {
        if (p->key == e->key) {
            return e->val;
        }
        e++;
    } while (--i > 0);
    return -1;
}

void fn_801DAE18(RelocTbl *t, u32 off) {
    RelocEnt *e;
    s32 i;
    if (t->ents == 0) {
        return;
    }
    e = (RelocEnt *)((u32)t->ents + off);
    t->ents = e;
    for (i = 0; i < t->count; i++, e++) {
        e->ptr += off;
    }
}

void fn_801DBA0C(void) {
    lbl_80312D00[0] = 0;
    lbl_80312D00[1] = 0;
    lbl_80312D00[2] = 0;
    lbl_80312D00[3] = 0;
    lbl_80312D00[4] = 0;
    lbl_80312D00[5] = 0;
    lbl_80312D00[6] = 0;
    lbl_80312D00[7] = 0;
    lbl_80312D00[8] = 0;
    lbl_80312D00[9] = 0;
    lbl_80312D00[10] = 0;
    lbl_80312D00[11] = 0;
    lbl_80312D00[12] = 0;
    lbl_80312D00[13] = 0;
    lbl_80312D00[14] = 0;
    lbl_80312D00[15] = 0;
}

extern s32 lbl_803476D8;
s32 fn_801DBCCC(void) {
    return lbl_803476D8;
}

void fn_801DBE1C(const char *fmt, ...) {
}

void fn_801DBF90(void) {
}

extern u32 lbl_803476D4;
extern s32 lbl_803475AC;
extern const char lbl_802C4628[];
extern int OSGetResetButtonState(void);
extern void OSReport(const char *msg, ...);
void fn_801DC214(void) {
    int reset = OSGetResetButtonState();
    u32 flags = lbl_803476D4;
    if (flags & 1) {
        if (reset == 0) {
            lbl_803476D4 = flags & ~1u;
            lbl_803476D4 = lbl_803476D4 | 2;
        }
    } else {
        if (reset != 0) {
            int msg =
 lbl_803475AC;
            lbl_803476D4 = flags | 1;
            if (msg != 0) {
                OSReport(lbl_802C4628);
            }
        }
    }
}

void fn_801DC3AC(void) {
    int reset = OSGetResetButtonState();
    u32 flags = lbl_803476D4;
    if (flags & 1) {
        if (reset == 0) {
            lbl_803476D4 = flags & ~1u;
            lbl_803476D4 = lbl_803476D4 | 2;
        }
    } else {
        if (reset != 0) {
            int msg =
 lbl_803475AC;
            lbl_803476D4 = flags | 1;
            if (msg != 0) {
                OSReport(lbl_802C4628);
            }
        }
    }
}

void fn_801DD71C(void *dst) {
    s32 idx;
    if (lbl_8034754C > 0) {
        idx = lbl_8034754C - 1;
        lbl_8034754C = idx;
        if (dst != 0) {
            memcpy(dst, lbl_8030EA1C + idx * 0x40, 0x40);
        }
    }
}

void fn_801DD7CC(void) {
    lbl_8034754C = 0;
}

void fn_801DD95C(void *p)
{
    if (p != 0) {
        fn_801E17E0(p);
    }
}

void fn_801DF94C(Ob *o) {
    fn_801DFA9C(o->p4c, o->s2);
    fn_801E17E0(o);
}

void fn_801E06E0(Mo *o) {
    njPushMatrixEx();
    fn_80286EE8();
    fn_8028B498();
    njUnitMatrix(0);
    fn_801E04E8(&o->m4, o->x48, o->x4c, &o->m2c);
    njPopMatrixEx();
}

void fn_801E0CB8(Mo *o) {
    njPushMatrixEx();
    fn_80286EE8();
    fn_8028B498();
    njUnitMatrix(0);
    fn_801E0AC0(&o->m4, o->x48, o->x4c, &o->m2c);
    njPopMatrixEx();
}

extern char lbl_802C4710[];
void fn_801E1784(void* p) {
    if (p != 0) {
        if (*(u32*)((u8*)p - 0x10) != 0) {
            fn_801DBE1C(lbl_802C4710, p);
        }
        fn_801E15FC(lbl_802F6748, p);
    }
}

extern char lbl_802C4734[];
void fn_801E17E0(void* p) {
    if (p != 0) {
        if (*(u32*)((u8*)p - 0x10) != 0) {
            fn_801DBE1C(lbl_802C4734, p);
        }
        fn_801E15FC(lbl_802F6748, p);
    }
}

void fn_801E1A2C(s32 mode, u32 n) {
    void *q;
    if (n == 0) {
        n = 0x20;
    }
    q = fn_801E184C(lbl_802F6748, -1, mode, n);
    *(u32 *)((u8 *)q - 0x10) = 0;
}

void fn_801D4954(void *p)
{
    if (p != 0) {
        fn_801E17E0(p);
    }
}

void fn_801D61C4(void *p)
{
    if (p != lbl_80311B00) {
        fn_801E1718(p);
    }
}

void *fn_801D665C(void)
{
    lbl_8034761C = lbl_8034761C + 1;
    if ((u32)lbl_8034761C > 0x7cf) {
        lbl_8034761C = 0;
    }
    return lbl_80347608 + (lbl_8034761C << 5);
}

void fn_801D7A08(u8 *p, f32 a, f32 b)
{
    *(f32 *)(p + 0x44) = a;
    *(f32 *)(p + 0x48) = b;
}

void fn_801D7A14(u8 *p, f32 a, f32 b, f32 c, f32 d)
{
    *(f32 *)(p + 0x34) = a;
    *(f32 *)(p + 0x38) = b;
    *(f32 *)(p + 0x3c) = c;
    *(f32 *)(p + 0x40) = d;
}

void fn_801D8818(void *a, s32 b, s32 c, s32 d, s32 e)
{
    fn_801D843C(a, b, c, d, 0, e);
}

void *fn_801D8D18(void)
{
    Holder801D *p = lbl_80347654;
    if (p->b19 == 7) {
        return *(void **)((u8 *)p->f24 + 4);
    }
    return (void *)-1;
}

void fn_801D8D3C(void)
{
    Holder801D *p = lbl_80347660;
    if (p != 0) {
        p->b19 = 10;
    }
}

s32 fn_801D8EE8(void)
{
    Holder801D *p = lbl_80347660;
    if (p->b19 == 10) {
        return *(s8 *)((u8 *)p->f24 + 1);
    }
    return *(s8 *)((u8 *)p->f24 + 5);
}

void fn_801DBA58(u32 a, u32 b, u32 c)
{
    lbl_80312D40[0] = a;
    lbl_80312D40[1] = b;
    lbl_80312D40[2] = c;
    lbl_80312D40[3] = c;
}

void fn_801DD984(void)
{
    fn_801E1A74(0x14, 1);
}

void fn_801E0D50(u32 *dst, u32 *src, s32 size)
{
    u32 t;
    s32 n = size / 4;
    do {
        t = *dst;
        *dst++ = *src;
        *src++ = t;
        n--;
    } while (n != 0);
}

s32 fn_801E183C(void)
{
    return lbl_80347550 == 0;
}

void fn_801E0D0C(char *s)
{
    if (s == NULL) {
        return;
    }
    for (; *s != 0; s++) {
        if (*s >= 'A' && *s <= 'Z') {
            *s += 0x20;
        }
    }
}

s32 fn_801D6DE8(s32 a, s32 n)
{
    Obj_80311C30 *o = &lbl_80311C30;

    if (o->active == 0) {
        return -2;
    }
    n = (n + 1) * 250;
    o->x14 = OSMillisecondsToTicks(n);
    return 0;
}

/* same loop as fn_801DA66C, inlined */
inline s16 EntFindVal(ReqB *p) {
    s32 i = 8;
    Ent *e = lbl_802F65C0;
    do {
        if (p->u.key == e->key) {
            return e->val;
        }
        e++;
    } while (--i > 0);
    return -1;
}

void *fn_801DA484(ReqB *p) {
    if (EntFindVal(p) < 0) {
        return p->next;
    }
    return p->next;
}

void *fn_801DA4D0(ReqB *p) {
    if (EntFindVal(p) < 0) {
        return p->u.obj;
    }
    return 0;
}

inline void Draw2(Node* n)
{
    BODY(n)
    if (n->child != 0) {
        fn_801D25DC(n->child);
    }
    njPopMatrixEx();
    if (n->next != 0) {
        fn_801D25DC(n->next);
    }
}

inline void Draw1(Node* n)
{
    BODY(n)
    if (n->child != 0) {
        Draw2(n->child);
    }
    njPopMatrixEx();
    if (n->next != 0) {
        Draw2(n->next);
    }
}

void fn_801D25DC(Node* n)
{
    BODY(n)
    if (n->child != 0) {
        Draw1(n->child);
    }
    njPopMatrixEx();
    if (n->next != 0) {
        Draw1(n->next);
    }
}

s32 fn_801D30DC(NJS_POINT3* p, Node_801D30DC* n, Hit* out)
{
    Mesh* m;
    s32 cnt;
    s32 tri;
    Vtx* r;
    f32 *va, *vb, *vc;
    f32* base;
    s32 hit;
    f32 loc[2];
    NJS_POINT3 q;
    f32 nrm[3];

    hit = 0;
    njPushMatrixEx();
    fn_80286EE8();
    fn_8028B498();
    njTranslateEx(n->pos);
    njRotateEx(n->rot, 0);
    njScaleEx(n->scl);
    m = n->mesh;
    if (m != 0) {
        cnt = m->count;
        if (cnt > 0) {
            njPushMatrixEx();
            fn_80286EE8();
            fn_8028B498();
            njInvertMatrix(0);
            njCalcPoint(0, p, &q);
            njPopMatrixEx();
            loc[0] = q.x - m->cx;
            loc[1] = q.z - m->cz;
            if (m->r2 >= loc[0] * loc[0] + loc[1] * loc[1]) {
                loc[0] = q.x;
                loc[1] = q.z;
                r = (Vtx*)((u8*)m + 0x58);
                base = m->verts;
                do {
                    tri = r->idx - 2;
                    r++;
                    do {
                        s16 fl = r[2].flag;
                        s32 i1 = r[1].idx;
                        s32 i0 = r[0].idx;
                        s32 i2 = r[2].idx;
                        vb = (f32*)((u8*)base + (i1 << 2));
                        if (fl < 0) {
                            va = (f32*)((u8*)base + (i2 << 2));
                            vc = (f32*)((u8*)base + (i0 << 2));
                        } else {
                            va = (f32*)((u8*)base + (i0 << 2));
                            vc = (f32*)((u8*)base + (i2 << 2));
                        }
                        hit = fn_801D48BC(loc, va, vb, vc);
                        if (hit != 0) {
                            fn_80290668(va, vb, vc, nrm);
                            if (-0.0001f > nrm[0] * (loc[0] - va[0]) + nrm[1] * (q.y - va[1]) + nrm[2] * (loc[1] - va[2])) {
                                hit = 0;
                            } else {
                                break;
                            }
                        }
                        r++;
                    } while (--tri > 0 && hit == 0);
                    if (hit != 0) {
                        if (out != 0) {
                            njCalcPoint(0, (NJS_POINT3*)va, &out->a);
                            njCalcPoint(0, (NJS_POINT3*)vb, &out->b);
                            njCalcPoint(0, (NJS_POINT3*)vc, &out->c);
                            out->id = n->id;
                            out->flag = r[2].flag & 0x7FFF;
                        }
                        break;
                    }
                    r += 2;
                } while (--cnt > 0 && hit == 0);
            }
        }
    }
    if (n->child != 0 && hit == 0) {
        hit = fn_801D30DC(p, n->child, out);
    }
    njPopMatrixEx();
    if (n->next != 0 && hit == 0) {
        hit = fn_801D30DC(p, n->next, out);
    }
    return hit;
}

void fn_801D8F18(void) {
    s32 i;
    lbl_8034765C->st[0] = 0;
    lbl_8034765C->st[1] = 0;
    lbl_8034765C->st[2] = 0;
    lbl_8034765C->st[3] = 0;
    lbl_8034765C->st[4] = 0;
    lbl_8034765C->st[5] = -1;
    lbl_8034765C->wc = -1;
    lbl_8034765C->w244 = 0;
    fn_801D89D4(&lbl_8034765C->a0, 10, 0, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    for (i = 0; i < 3; i++) {
        fn_801D89D4(&lbl_8034765C->a[i], 10, 0, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f);
        fn_801D89D4(&lbl_8034765C->b[i], 1, 0, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f);
        lbl_80311DF0[i] = 1.0f;
    }
    if (fn_801A3510() == 1) {
        lbl_8034765C->st[3] = 1;
        fn_801D8AB4(&lbl_8034765C->b[1], 1, 0, 1.0f, 1.0f);
        lbl_80311DF0[1] = 1.0f;
        if (lbl_8034765C->st[7] == 0) lbl_8034765C->st[1] = 1;
        lbl_8034765C->st[7] = 1;
    } else {
        lbl_8034765C->st[3] = 0;
        lbl_8034765C->st[7] = 0;
        fn_801D8AB4(&lbl_8034765C->b[1], 1, 0, 0.7f, 0.7f);
        lbl_80311DF0[1] = 0.7f;
    }
    if (lbl_8034765C->st[3] == 1) lbl_8034765C->st[1] = 1;
    lbl_8034765C->st[4] = 0;
    lbl_8034765C->st[6] = 1;
    if (lbl_8034765C->st[3] == 1) {
        lbl_8034765C->st[7] = 1;
    } else {
        lbl_8034765C->st[7] = 0;
        fn_801D8AB4(&lbl_8034765C->b[1], 1, 0, 0.7f, 0.7f);
        lbl_80311DF0[1] = 0.7f;
    }
    if (lbl_8034765C->st[4] == 1) {
        lbl_8034765C->st[8] = 1;
    } else {
        lbl_8034765C->st[8] = 0;
        fn_801D8AB4(&lbl_8034765C->b[2], 1, 0, 0.7f, 0.7f);
        lbl_80311DF0[2] = 0.7f;
    }
    lbl_8034765C->w10 = 2;
}

s32 fn_801D91F4(void) {
    s16 i;
    s32 sel;
    if (fn_801A3510() == 1) {
        lbl_8034765C->st[3] = 1;
        fn_801D8AB4(&lbl_8034765C->b[1], 1, 0, 1.0f, 1.0f);
        lbl_80311DF0[1] = 1.0f;
        if (lbl_8034765C->st[7] == 0) lbl_8034765C->st[1] = 1;
        lbl_8034765C->st[7] = 1;
    } else {
        lbl_8034765C->st[3] = 0;
        lbl_8034765C->st[7] = 0;
        fn_801D8AB4(&lbl_8034765C->b[1], 1, 0, 0.7f, 0.7f);
        lbl_80311DF0[1] = 0.7f;
    }
    lbl_8034765C->st[5] = -1;
    if (lbl_80311A60.pad->x8 & 0x100) {
        lbl_80347658 = SePlay(1, 1, 2);
        sel = lbl_8034765C->st[1];
        switch (sel) {
        case 0:
            return sel;
        case 1:
            return sel;
        case 2:
            return sel;
        default:
            lbl_8034765C->st[5] = -2;
            break;
        }
    } else if (lbl_80311A60.pad->x8 & 8) {
        lbl_80347658 = SePlay(1, 1, 0);
        if (lbl_8034765C->st[1] > 0) lbl_8034765C->st[1]--;
        else lbl_8034765C->st[1] = lbl_8034765C->w10;
        if (lbl_8034765C->st[lbl_8034765C->st[1] + 6] == 0) {
            for (i = 0; i < 3; i++) {
                if (lbl_8034765C->st[1] > 0) lbl_8034765C->st[1]--;
                else lbl_8034765C->st[1] = lbl_8034765C->w10;
                if (lbl_8034765C->st[lbl_8034765C->st[1] + 6] == 1) break;
            }
        }
        lbl_8034765C->st[5] = -2;
    } else if (lbl_80311A60.pad->x8 & 4) {
        lbl_80347658 = SePlay(1, 1, 0);
        if (lbl_8034765C->st[1] < lbl_8034765C->w10) lbl_8034765C->st[1]++;
        else lbl_8034765C->st[1] = 0;
        if (lbl_8034765C->st[lbl_8034765C->st[1] + 6] == 0) {
            for (i = 0; i < 3; i++) {
                if (lbl_8034765C->st[1] < lbl_8034765C->w10) lbl_8034765C->st[1]++;
                else lbl_8034765C->st[1] = 0;
                if (lbl_8034765C->st[lbl_8034765C->st[1] + 6] == 1) break;
            }
        }
        lbl_8034765C->st[5] = -2;
    }
    if (lbl_8034765C->st[lbl_8034765C->st[1] + 6] == 0) lbl_8034765C->st[1] = 0;
    return lbl_8034765C->st[5];
}

inline void NodeFixSelf(Node801D* n) {
    Inner* p;
    if (n->a != 0) {
        p = (Inner*)((u8*)n->a + (u32)n);
        n->a = p;
        if (p->x10 != 0) {
            p->x10 += (u32)p + 0x10;
        }
    }
}

inline void NodeFix3(Node801D* n) {
    Node801D* c;
    NodeFixSelf(n);
    c = n->c1;
    if (c != 0) {
        n->c1 = (Node801D*)((u32)n + 0x2c + (u32)c);
        fn_801DA748(n->c1);
    }
    c = n->c2;
    if (c != 0) {
        n->c2 = (Node801D*)((u32)n + 0x30 + (u32)c);
        fn_801DA748(n->c2);
    }
}

inline void NodeFix2(Node801D* n) {
    Node801D* c;
    NodeFixSelf(n);
    c = n->c1;
    if (c != 0) {
        n->c1 = (Node801D*)((u32)n + 0x2c + (u32)c);
        NodeFix3(n->c1);
    }
    c = n->c2;
    if (c != 0) {
        n->c2 = (Node801D*)((u32)n + 0x30 + (u32)c);
        NodeFix3(n->c2);
    }
}

void fn_801DA748(Node801D* n) {
    Node801D* c;
    NodeFixSelf(n);
    c = n->c1;
    if (c != 0) {
        n->c1 = (Node801D*)((u32)n + 0x2c + (u32)c);
        NodeFix2(n->c1);
    }
    c = n->c2;
    if (c != 0) {
        n->c2 = (Node801D*)((u32)n + 0x30 + (u32)c);
        NodeFix2(n->c2);
    }
}

inline void CountNode(Node801DF6* n, s32* count, s32* total) {
    s32 v;
    if (!(n->flags & 8) && n->d != 0) {
        v = fn_801CB1AC(n->d->x0);
        if (v != 0) {
            *total += v;
            *count += 1;
        }
    }
}

inline void CountNode3(Node801DF6* n, s32* count, s32* total) {
    CountNode(n, count, total);
    if (n->c1 != 0 && !(n->flags & 0x10)) fn_801DF600(n->c1, count, total);
    if (n->c2 != 0) fn_801DF600(n->c2, count, total);
}

inline void CountNode2(Node801DF6* n, s32* count, s32* total) {
    Node801DF6* c;
    CountNode(n, count, total);
    c = n->c1;
    if (c != 0 && !(n->flags & 0x10)) CountNode3(c, count, total);
    c = n->c2;
    if (c != 0) CountNode3(c, count, total);
}

void fn_801DF600(Node801DF6* n, s32* count, s32* total) {
    Node801DF6* c;
    CountNode(n, count, total);
    c = n->c1;
    if (c != 0 && !(n->flags & 0x10)) CountNode2(c, count, total);
    c = n->c2;
    if (c != 0) CountNode2(c, count, total);
}

void fn_801E0204(Hit801E* hit, Ref801E* ref, f32* mtx, Box801E* box) {
    NJS_POINT3 p;
    NJS_POINT3 q;
    NJS_VECTOR v;
    f32 s;
    njCalcPoint(NULL, &hit->pos, &p);
    if (p.x > box->min.x && p.y > box->min.y && p.z > box->min.z && p.x < box->max.x && p.y < box->max.y &&
        p.z < box->max.z) {
        fn_802900C0(&p, &ref->c, &q);
        v.x = q.x - ref->c.x;
        v.y = q.y - ref->c.y;
        v.z = q.z - ref->c.z;
        hit->dist = fn_80291A5C(v.x * v.x + v.y * v.y + v.z * v.z);
        v.x = p.x - q.x;
        v.y = p.y - q.y;
        v.z = p.z - q.z;
        if (v.x == 0.0f && v.y == 0.0f && v.z == 0.0f) {
            v.x = ref->d.x;
            v.y = ref->d.y;
            v.z = ref->d.z;
        }
        njUnitVector(&v);
        njCalcVector(mtx, &v, &hit->dir);
    } else if (box->flag == 0.0f) {
        hit->dir.z = 0.0f;
        hit->dir.y = 0.0f;
        hit->dir.x = 0.0f;
    } else {
        s = fn_801DFE48(&p, box);
        if (s == 0.0f) {
            hit->dir.z = 0.0f;
            hit->dir.y = 0.0f;
            hit->dir.x = 0.0f;
        } else {
            fn_802900C0(&p, &ref->c, &q);
            v.x = q.x - ref->c.x;
            v.y = q.y - ref->c.y;
            v.z = q.z - ref->c.z;
            hit->dist = fn_80291A5C(v.x * v.x + v.y * v.y + v.z * v.z);
            v.x = p.x - q.x;
            v.y = p.y - q.y;
            v.z = p.z - q.z;
            if (v.x == 0.0f && v.y == 0.0f && v.z == 0.0f) {
                v.x = ref->d.x;
                v.y = ref->d.y;
                v.z = ref->d.z;
            }
            njUnitVector(&v);
            v.x *= s;
            v.y *= s;
            v.z *= s;
            njCalcVector(mtx, &v, &hit->dir);
        }
    }
}

static inline void ClearWork(DataTable *t)
{
    s32 i;
    for (i = 0; i < t->count; i++) {
        t->work[i] = 0;
    }
}

static inline void Relocate(DataTable *t)
{
    DataEntry *e;
    s32 i;
    for (i = 0; i < t->count; i++) {
        e = (DataEntry *)(t->base + t->offsets[i]);
        e->base = t->base;
        e->offset += (s32)t->data;
    }
}

void fn_801D6A74(DataTable *t, s32 id)
{
    t->data = fn_8022ACA8(id);
    t->count = t->data[0];
    t->base = (u8 *)t->data + (t->count + 1) * 4;
    t->offsets = t->data + 1;
    t->work = fn_801E1C7C(t->count * 4);
    ClearWork(t);
    Relocate(t);
}

void fn_801D6B58(DataTable *t, const char *name)
{
    t->data = fn_801CC3C4(name);
    t->count = t->data[0];
    t->base = (u8 *)t->data + (t->count + 1) * 4;
    t->offsets = t->data + 1;
    t->work = fn_801E1C7C(t->count * 4);
    ClearWork(t);
    Relocate(t);
}

void fn_801DB9B4(void) {
    s32 i;
    for (i = 0; i < 16; i++) {
        if (lbl_80312D00[i] != 0) TaskDelete(lbl_80312D00[i]);
    }
}

f32 fn_801DBD9C(f32 z) {
    if (z > -1.0f) z = -1.0f;
    if (z < -65535.0f) fn_801DBE1C(lbl_802C456C, z);
    return lbl_80347F28 - ((z + 1.0f) / -65535.0f) * (lbl_80347F28 - lbl_80347F2C);
}

void fn_801DBE6C(s32 i) {
    lbl_803475CC = i;
    lbl_80311AD4[i] = 0;
}

void fn_801DCEB0(NJS_VECTOR *out, s32 *rot, f32 d) {
    NJS_MATRIX m;
    NJS_VECTOR v;
    v.y = 0.0f;
    v.x = 0.0f;
    v.z = -d;
    njUnitMatrix(m);
    njRotateZXY(m, rot[0], rot[1], rot[2]);
    njCalcVector(m, &v, out);
}

void fn_801DCF24(NJS_VECTOR *out, s32 *rot, s32 rz, f32 y) {
    NJS_MATRIX m;
    lbl_802F66AC.y = y;
    njUnitMatrix(m);
    njRotateZXY(m, rot[0], rot[1], rz);
    njCalcVector(m, &lbl_802F66AC, out);
}

void fn_801DD334(NJS_VECTOR *a, NJS_VECTOR *b, s32 *rot) {
    NJS_MATRIX m;
    njUnitMatrix(m);
    njRotateZXY(m, rot[0], rot[1], rot[2]);
    njCalcVector(m, &lbl_802F6694, a);
    njCalcVector(m, &lbl_802F66A0, b);
}

void fn_801DD460(NJS_VECTOR *out, s32 *rot) {
    NJS_MATRIX m;
    njUnitMatrix(m);
    njRotateZXY(m, rot[0], rot[1], rot[2]);
    njCalcVector(m, &lbl_802F6688, out);
}

s32 fn_801DD4C4(f32 x, f32 z) {
    f32 a;
    if (x != 0.0f || z != 0.0f) {
        a = (f32)atan2(x, z);
        lbl_8030EA10[1] = 0;
        return ((s32)(10430.381f * a) + 0x8000) & 0xffff;
    }
    lbl_8030EA10[1] = 1;
    return 0;
}

void fn_801DD76C(const void *src) {
    s32 n;
    memcpy(lbl_8030EA1C + (lbl_8034754C << 6), src, 0x40);
    n = lbl_8034754C + 1;
    lbl_8034754C = n;
    if (n > 0x80) fn_801DBE1C(lbl_802C4698);
}

void fn_801DD8EC(Cursor *c, TblEnt *tbl, s32 count, s32 mode) {
    if (tbl != NULL && count > 0) {
        c->tbl = tbl;
        c->count = count;
        c->mode = mode;
        c->f8 = 0;
        c->idx = (mode >= 0) ? 0 : c->count - 1;
        c->out0 = tbl[c->idx].a;
        c->outB = tbl[c->idx].b;
    } else {
        c->out0 = 0;
    }
}

void fn_801DDE5C(Holder *h) {
    if (h->a != NULL) {
        fn_801E8580(h->a);
        h->a = NULL;
    }
    if (h->c != NULL) {
        fn_801E17E0(h->c);
        h->c = NULL;
    }
    if (h->e != NULL) {
        fn_801E17E0(h->e);
        h->e = NULL;
    }
}

void fn_801DDECC(Ctx_801DDECC *o, void *a, u32 b, void *c) {
    o->r0 = NULL;
    o->a = a;
    o->b = b;
    o->c = c;
    o->r14 = NULL;
    o->k1a = -1;
    o->zero0c = 0;
    o->r0 = fn_801E84C0((u8 *)a + 8);
    o->r14 = fn_801DDF48(o->sub, c, o->k1c, o->k1e);
}

s32 fn_801D168C(void) {
    switch (DVDGetDriveStatus() + 1) {
    case 0:
        return 0;
    case 5:
        lbl_80347268 = 1;
        return 1;
    case 6:
        lbl_80347268 = 1;
        return 2;
    case 7:
        lbl_80347268 = 1;
        return 3;
    case 12:
        return 4;
    default:
        return -1;
    }
}

void fn_801D3E58(Pair3i* out, s32 idx, Vec3i* tbl) {
    s32 n;

    if (idx < 0) {
        return;
    }
    n = idx + 1;
    if (n > 2) {
        n = 0;
    }
    out->cur = tbl[idx];
    out->next = tbl[n];
}

void* fn_801D497C(Rec28* src) {
    Rec28* dst = fn_801E1C7C(0x1c);

    dst->a = src->a;
    dst->b = src->b;
    dst->c = src->c;
    dst->d = src->d;
    dst->e = src->e;
    dst->f = src->f;
    dst->g = src->g;
    return dst;
}

void fn_801D68DC(Obj68DC* o) {
    if (o == 0) {
        return;
    }
    if (o->a8 != 0) {
        o->a8 = 0;
    }
    if (o->ac != 0) {
        fn_801E17E0(o->ac);
        o->ac = 0;
    }
    fn_801E17E0(o->b0);
    o->b0 = 0;
}

void fn_801D71C4(void) {
    s32 done;

    PADControlMotor(0, 2);
    do {
        done = PADRecalibrate(0x80000000);
        if (done == 0) {
            PADRead(lbl_8034763C);
            if (lbl_8034763C->err == -1) {
                done = 1;
            }
        }
    } while (done == 0);
}

void fn_801D7810(void) {
    s32 i;

    lbl_8034757C = 0;
    lbl_80347640 = 1;
    lbl_80347630 = 0;
    i = 5;
    while (--i >= 0) {
        lbl_80311A00[i] = lbl_802F6558[i];
    }
    lbl_80347634 = 0;
}

void fn_801D7A28(Obj7A28* obj, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5, f32 f6, f32 f7) {
    obj->a = 1;
    obj->b = 256.0f;
    obj->c = f1;
    obj->d = 0.0f;
    obj->e = 0;
    obj->f = 0;
    obj->g = 1.0f;
    obj->h = 1.0f;
    obj->i = 1;
    obj->j = -1;
    obj->k = -1;
    obj->l = -1;
    obj->m = -1;
    obj->n = f2;
    obj->o = f3;
    obj->p = f4;
    obj->q = f5;
    obj->r = f6;
    obj->s = f7;
}

void fn_801D8B2C(void) {
    lbl_80347654 = fn_802268E8(lbl_803475A8, fn_801D8B94);
    lbl_80347654->f24 = fn_801E1C7C(0xc);
    *(u8 *)lbl_80347654->f24 = 0;
    lbl_80347650 = lbl_80347654->f24;
    memset(lbl_80347650, 0, 0xc);
}

void fn_801D8D54(void) {
    lbl_80347660 = fn_802268E8(lbl_803475A8, fn_801D8DBC);
    lbl_80347660->f24 = fn_801E1C7C(0x248);
    *(u8 *)lbl_80347660->f24 = 0;
    lbl_8034765C = lbl_80347660->f24;
    memset(lbl_8034765C, 0, 0x248);
}

s32 fn_801D6C3C(s32 chan) {
    if (lbl_80311C30.active == 0) {
        return -2;
    }
    if (lbl_80311C30.x4 != 0) {
        PADControlMotor(chan, 0);
        lbl_80311C30.x4 = 0;
        lbl_80311C30.x14 = 0;
        lbl_80311C30.x8 = 0;
        lbl_80311C30.xc = 0;
        lbl_80311C30.x10 = 0;
        lbl_80311C30.x14 = 0;
        lbl_80311C30.x18 = 0;
    }
    return 0;
}

void fn_801D9BFC(void) {
    if (lbl_80347668 == 8) fn_801DBE1C(lbl_802C44A8);
    MemCopy(lbl_80311E00 + lbl_80347668 * 0x1e0, &lbl_8030E830, 0x1e0);
    lbl_80347668 = lbl_80347668 + 1;
}

void fn_801D9C64(f32 f1, f32 f2, f32 f3) {
    lbl_8030E830.f50 = 1;
    lbl_8030E830.f6c = f1;
    lbl_8030E830.f70 = f2;
    lbl_8030E830.f74 = f3;
    fn_802871D8(&lbl_8030E830);
    lbl_8030E830.f118 = 1;
    lbl_8030E830.f134 = f1;
    lbl_8030E830.f138 = f2;
    lbl_8030E830.f13c = f3;
    fn_8028B784(&lbl_8030E830, f1, f2, f3);
}

void fn_801D8AB4(Anim *p, s32 a, s32 b, f32 f1, f32 f2) {
    p->count = 0;
    if ((u32)a == 0) p->total = 1; else p->total = a;
    p->delay = b;
    p->start[0] = f1;
    p->cur[0] = f1;
    p->end[0] = f2;
    p->delta[0] = (f1 - f2) / (f32)(u32)a;
    p->delta[1] = 0.0f;
    p->delta[2] = 0.0f;
    p->delta[3] = 0.0f;
    p->flags = 1;
}

void fn_801E1718(void *p) {
    if (p != NULL) {
        if (*(u32 *)((u8 *)p - 0x10) != 2) {
            fn_801DBE1C(lbl_802C46EC, p);
        }
        fn_801E15FC(&lbl_802F6748[2], p);
        lbl_80347700--;
    }
}

void fn_801DDCA8(Pool_801DDCA8* p) {
    if (p->x6 != 0) {
        Ent_801DDCA8* e = p->ents;
        s32 n = p->count;
        for (; n > 0; e++, n--) {
            if (e->x0 > 0) {
                if (e->x4 != NULL) {
                    fn_801E8580(e->x4);
                    e->x4 = NULL;
                }
                if (e->x10 != NULL) {
                    fn_801E17E0(e->x10);
                    e->x10 = NULL;
                }
                if (e->x18 != NULL) {
                    fn_801E17E0(e->x18);
                    e->x18 = NULL;
                }
            }
        }
    }
    fn_801E17E0(p->ents);
    p->ents = NULL;
    p->count = 0;
    p->x6 = 0;
}

void *fn_801DB528(Task *t)
{
    s32 i;
    Task **p = lbl_80312D00;
    MldWork *w;
    void *r;

    for (i = 0; i < 16; p++, i++) {
        if (*p == t) {
            break;
        }
    }
    if (i >= 16) {
        return NULL;
    }
    w = t->work;
    r = NULL;
    if (w->w14 == 1) {
        r = w->x8;
        w->x8 = NULL;
    }
    return r;
}

void fn_801DBBF0(void) {
    lbl_8034767C = lbl_80302A00;
    lbl_80347678 = lbl_8031693C - lbl_80302A00;
    while (lbl_80347678-- != 0) {
        *lbl_8034767C++ = 0;
    }
    lbl_8034767C = lbl_80346A80;
    lbl_80347678 = lbl_80347888 - lbl_80346A80;
    while (lbl_80347678-- != 0) {
        *lbl_8034767C++ = 0;
    }
    lbl_8034767C = lbl_8034D460;
    lbl_80347678 = lbl_8034D484 - lbl_8034D460;
    while (lbl_80347678-- != 0) {
        *lbl_8034767C++ = 0;
    }
}

void fn_801DC420(void) {
    u32 now;
    lbl_803475C8 = OSGetTick();
    now = lbl_803475C8 / OS_TIMER_CLOCK;
    lbl_803475C8 = now;
    if (now - lbl_803475C4 >= 500000) {
        lbl_803475C4 = now;
        lbl_803475B8 = (lbl_803475C0 - lbl_803475BC) * 2;
        lbl_803475BC = lbl_803475C0;
    }
    GXCopyDisp(lbl_803476AC, 1);
    fn_801D22CC();
    fn_801C62D8();
    do {
        fn_801C6248(0);
    } while (VIGetRetraceCount() - lbl_8034768C < 1);
    if (lbl_80347690 != 0) {
        VISetBlack(0);
        lbl_80347690 = 0;
    }
    VISetNextFrameBuffer(lbl_803476AC);
    VIFlush();
    fn_80296F48();
    VIWaitForRetrace();
    lbl_803476AC = (lbl_803476AC == lbl_803476B4) ? lbl_803476B0 : lbl_803476B4;
}

void fn_801DD14C(Angle* rot, NJS_POINT3* p, NJS_VECTOR* in) {
    NJS_MATRIX m;
    NJS_VECTOR v;
    s32 r;
    fn_801DD5E8(rot, p);
    njUnitMatrix(m);
    njRotateX(m, -rot[0]);
    njRotateY(m, -rot[1]);
    njCalcVector(m, in, &v);
    if (v.x != 0.0f || v.y != 0.0f) {
        f32 a = atan2(v.x, v.y);
        lbl_8030EA10[2] = 0;
        r = -(s32)(10430.381f * a);
        r &= 0xffff;
    } else {
        lbl_8030EA10[2] = 1;
        r = 0;
    }
    rot[2] = r;
}

s32 fn_801DFA9C(Item_801DFA9C* items, s32 count) {
    s32 type;
    s32 size;
    s32 cnt;
    s32 total;
    Ent_801DFA9C* e;
    Hdr* src;
    f32* in;
    f32* q;
    s32 n;
    if (count == 0) {
        return 0;
    }
    total = 0;
    do {
        if (items->stream != NULL) {
            src = items->stream;
            e = items->ent;
            do {
                size = src->size;
                type = src->type & 0xff;
                in = (f32*)(src + 1);
                src = (Hdr*)in;
                n = fn_801CB0A4(type);
                if (n >= 0) {
                    cnt = ((Cnt*)in)->cnt;
                    in += 1;
                } else {
                    size = n & 0xffff;
                }
                if (n > 0) {
                    total += cnt;
                    q = in;
                    do {
                        q[0] = e->x;
                        q[1] = e->y;
                        q[2] = e->z;
                        e++;
                        q += n;
                    } while (--cnt > 0);
                }
                src += size;
            } while (type != 0xff);
        }
        items++;
    } while (--count > 0);
    return total;
}

s32 fn_801DFB7C(Item_801DFB7C* items, s32 count) {
    s32 type;
    s32 size;
    s32 cnt;
    s32 total;
    Ent_801DFB7C* e;
    Hdr* src;
    f32* in;
    f32* q;
    s32 n;
    if (count == 0) {
        return 0;
    }
    total = 0;
    do {
        if (items->stream != NULL) {
            src = items->stream;
            e = items->ent;
            do {
                size = src->size;
                type = src->type & 0xff;
                in = (f32*)(src + 1);
                src = (Hdr*)in;
                n = fn_801CB0A4(type);
                if (n >= 0) {
                    cnt = ((Cnt*)in)->cnt;
                    in += 1;
                } else {
                    size = n & 0xffff;
                }
                if (n > 0) {
                    total += cnt;
                    q = in;
                    do {
                        e->x = q[0];
                        e->y = q[1];
                        e->z = q[2];
                        e++;
                        q += n;
                    } while (--cnt > 0);
                }
                src += size;
            } while (type != 0xff);
        }
        items++;
    } while (--count > 0);
    return total;
}

s32 fn_801DDD74(SlotTab *t, s16 n) {
    s32 i;
    Slot *s;
    s = fn_801E1C7C(n * (s32)sizeof(Slot));
    t->slots = s;
    if (s == 0) return 0;
    for (i = 0; i < n; i++) {
        s->key = -1;
        s++;
    }
    t->count = n;
    t->used = 0;
    return 1;
}

void fn_801D9634(NJS_POINT3* v, s32* out) {
    f32 xz = v->x * v->x + v->z * v->z;
    if (0.0f == xz + v->y * v->y) {
        out[0] = 0;
        out[1] = 0;
    } else {
        f32 a = (f32)atan2(-v->y, fn_80291A5C(xz));
        out[0] = (s32)(10430.381f * a);
        if (0.0f == v->x && 0.0f == v->z) {
            out[1] = 0;
        } else {
            a = (f32)atan2(v->x, v->z);
            out[1] = (s32)(10430.381f * a);
        }
    }
    out[2] = 0;
}

void fn_801DE504(s32 id, Obj_801DE504* o, s16 idx, void* motion, f32 frame) {
    NJS_TEXLIST tl;
    void* model;
    NJS_TEXLIST* t = o->texlist;
    NJS_TEXNAME** base = o->base;
    s32 off;
    tl.nbTexture = t->nbTexture;
    if (idx >= o->count) {
        idx = 0;
    }
    if (o->list != NULL) {
        Ent_801DE504* e = &o->ents[idx];
        model = o->model;
        off = e->off;
        if (idx != o->cur) {
            o->cur = idx;
            fn_801E85BC(o->list, e->a, e->b);
        }
    } else if (o->xc == 0) {
        model = o->model;
        off = t->nbTexture * idx;
    }
    GXInvalidateVtxCache();
    tl.textures = *base + off;
    fn_80299040(&tl);
    fn_801E7194(id, model, motion, NULL, frame);
}

void fn_801DE5F8(s32 id, Obj_801DE504* o, s16 idx) {
    NJS_TEXLIST tl;
    void* model;
    NJS_TEXLIST* t;
    NJS_TEXNAME** base;
    s32 off;
    if (idx < 0) {
        return;
    }
    t = o->texlist;
    base = o->base;
    tl.nbTexture = t->nbTexture;
    if (idx >= o->count) {
        idx = 0;
    }
    if (o->list != NULL) {
        Ent_801DE504* e = &o->ents[idx];
        model = o->model;
        off = e->off;
        if (idx != o->cur) {
            o->cur = idx;
            fn_801E85BC(o->list, e->a, e->b);
        }
    } else if (o->xc == 0) {
        model = o->model;
        off = t->nbTexture * idx;
    }
    GXInvalidateVtxCache();
    tl.textures = *base + off;
    fn_80299040(&tl);
    fn_801E4CB0(id, model);
}

void fn_801DE8C0(Obj_801DE8C0* o, Keys_801DE8C0* k) {
    Key_801DE8C0* e = k->keys;
    s32 n = k->count;
    if (n > 0) {
        do {
            o->pos.x = e->p0.x + e->p1.x;
            o->pos.y = e->p0.y + e->p1.y;
            o->pos.z = e->p0.z + e->p1.z;
            o->scl.x = e->s0.x + e->s1.x;
            o->scl.y = e->s0.y + e->s1.y;
            o->scl.z = e->s0.z + e->s1.z;
            o->colour.a = e->c0.a + e->c1.a;
            o->colour.r = e->c0.r + e->c1.r;
            o->colour.g = e->c0.g + e->c1.g;
            o->colour.b = e->c0.b + e->c1.b;
            fn_801E66E0(o);
            e++;
        } while (--n > 0);
    }
}

s32 fn_801DD9AC(Pool *pool, Payload *p) {
    s32 r = -1;
    Entry *e = (Entry *)((u8 *)p - 4);
    if ((u32)e >= (u32)pool->base && (u32)e < (u32)(pool->base + pool->count)
        && ((u32)e - (u32)pool->base) % sizeof(Entry) == 0) {
        if (e->ref > 0) {
            e->ref--;
            r = e->ref;
            if (r == 0) {
                e->ref = -1;
                if (p->x0 != 0) {
                    fn_801E8580(p->x0);
                    p->x0 = 0;
                }
                if (p->xc != 0) {
                    fn_801E17E0(p->xc);
                    p->xc = 0;
                }
                if (p->x14 != 0) {
                    fn_801E17E0(p->x14);
                    p->x14 = 0;
                }
                pool->live--;
            }
        }
    }
    return r;
}

s32 fn_801D24D0(NJS_POINT3* out, NJS_POINT3* in, Node_801D24D0* n, Ctx_801D24D0* c) {
    s32 hit = 0;
    NJS_POINT3 q;
    njPushMatrixEx();
    fn_80286EE8();
    fn_8028B498();
    njTranslateEx(n->pos);
    njRotateEx(n->rot, 0);
    njScaleEx(n->scl);
    if (c->id == n->id && n->obj != 0) {
        njPushMatrix(n->obj->mtx);
        njInvertMatrix(0);
        njCalcPoint(0, in, &q);
        njPopMatrixEx();
        njCalcPoint(0, &q, out);
        hit = 1;
    }
    if (hit == 0 && n->child != 0) {
        hit = fn_801D24D0(out, in, n->child, c);
    }
    njPopMatrixEx();
    if (hit == 0 && n->next != 0) {
        hit = fn_801D24D0(out, in, n->next, c);
    }
    return hit;
}

void fn_801DD7D8(Anim_801DD7D8 *a) {
    Frm *f = a->frames;
    if (f == 0) {
        return;
    }
    a->timer--;
    if (a->timer > 0) {
        return;
    }
    a->idx += a->step;
    if (a->idx < 0) {
        a->idx = a->count - 1;
        a->flag = 1;
    } else if (a->count <= a->idx) {
        a->idx = 0;
        a->flag = 1;
    }
    f += a->idx;
    a->val = f->val;
    if ((a->timer = f->dur) >= 0) {
        return;
    }
    if (f->dur == -2) {
        a->step = 0;
        if (a->idx > 0) {
            a->idx--;
        }
    } else if (a->step < 0) {
        a->idx = a->count - 1;
    } else {
        a->idx = 0;
    }
    f = &a->frames[a->idx];
    a->val = f->val;
    a->timer = f->dur;
    a->flag = 1;
}

Res *fn_801DF988(Node801DF6 *n) {
    s32 tot;
    s32 cnt;
    Res *r;
    E12 *p;
    E12 *base;
    s32 t;
    cnt = 0;
    tot = 0;
    fn_801DF600(n, &tot, &cnt);
    if (cnt == 0) {
        return 0;
    }
    r = fn_801E1C7C(0x50 + tot * 0xc + cnt * 0x1c);
    if (r != 0) {
        base = (E12 *)((u8 *)r + 0x50);
        p = base;
        t = tot;
        r->x2 = t;
        r->x48 = n;
        r->x4c = p;
        fn_801DF500(n, &p, base + t);
        r->x0 = 0;
        r->xc = 0.0f;
        r->x4 = 0.0f;
        r->x8 = -32768.0f;
        r->x18 = 0.0f;
        r->x10 = 0.0f;
        r->x14 = 1.0f;
        r->x1c = 0.0f;
        r->x20 = 0.25f;
        r->x24 = 45.0f;
        r->x28 = 1.0f;
        r->x34 = -32768.0f;
        r->x30 = -32768.0f;
        r->x2c = -32768.0f;
        r->x40 = 32768.0f;
        r->x3c = 32768.0f;
        r->x38 = 32768.0f;
        r->x44 = 0.0f;
    }
    return r;
}

f32 fn_801D78EC(Anim_801D78EC *a) {
    Vtx_801D78EC v[4];
    s32 n;
    f32 z = fn_801DBD9C(a->f04);
    if (a->f00 == 3) {
        n = 3;
        v[0].x = a->f10; v[0].y = a->f20; v[0].z = z; v[0].c = a->f0c;
        v[1].x = a->f14; v[1].y = a->f24; v[1].z = z; v[1].c = a->f0c;
        v[2].x = a->f18; v[2].y = a->f28; v[2].z = z; v[2].c = a->f0c;
    } else {
        n = 4;
        v[0].x = a->f10; v[0].y = a->f20; v[0].z = z; v[0].c = a->f0c;
        v[1].x = a->f1c; v[1].y = a->f2c; v[1].z = z; v[1].c = a->f0c;
        v[2].x = a->f14; v[2].y = a->f24; v[2].z = z; v[2].c = a->f0c;
        v[3].x = a->f18; v[3].y = a->f28; v[3].z = z; v[3].c = a->f0c;
    }
    fn_8028A26C(a->f08);
    fn_8028A0F4(v, n);
    fn_8028A268();
    return a->f04;
}

void fn_801DC288(void)
{
    switch (lbl_803475CC) {
    case 0:
        fn_801DBE88();
        lbl_803475CC = 2;
        lbl_80311AD4[2] = 0;
        break;
    case 2:
        lbl_803474E0 = 1;
        fn_80219378(lbl_802C4590);
        sndOutputMode(OSGetSoundMode() == 1);
        fn_80219378(lbl_802C45A0);
        if (lbl_803475D4 == 0) {
            lbl_80311AC0.map = 2;
            lbl_80311AC0.unk4 = 2;
            lbl_80311AC0.room = 0x61;
        }
        lbl_803475CC = 3;
        lbl_80311AD4[3] = 0;
        break;
    case 3:
        fn_801D77B8();
        fn_80228A20();
        break;
    case 6:
        fn_80101828();
        break;
    case 7:
        fn_8000A118();
        fn_801F7B04(10000);
        lbl_803475B0 = 1;
        break;
    case 9:
        fn_801C8DF0();
        break;
    }
    fn_801CC3A4();
    if (lbl_803474E0 == 1) {
        fn_80218678();
    }
    lbl_803475C0 = lbl_803475C0 + 1;
}

void fn_801DC504(void)
{
    fn_801DC420();
    VISetBlack(1);
    VIFlush();
    VIWaitForRetrace();
    fn_800976F8();
    fn_80230F28();
    fn_801CAE90();
    fn_8022807C();
    fn_801D13D8();
    fn_801E1EE4();
    FontFree();
    fn_80299058();
    fn_80228984();
    fn_801A473C();
    fn_801D71C4();
    fn_80219C84();
    if (lbl_803475E4 != 0) {
        fn_80005AD8(lbl_80346720, lbl_803475E4);
    }
    if (lbl_803475EC != 0) {
        fn_80005AD8(lbl_80346720, lbl_803475EC);
    }
    if (lbl_803475E8 != 0) {
        fn_80005AD8(lbl_80346720, lbl_803475E8);
    }
    if (lbl_803475F0 != 0) {
        fn_80005AD8(lbl_80346720, lbl_803475F0);
    }
    if (lbl_803475F4 != 0) {
        fn_80005AD8(lbl_80346720, lbl_803475F4);
    }
    fn_80005954(heap_font);
    fn_80005954(heap_main);
    fn_80005954(lbl_8034769C);
    fn_80005954(lbl_803476A0);
    fn_80005954(lbl_803476A4);
    if (lbl_803475AC != 0) {
        OSReport("[System] Exit Mode ... %s. (%s:%d)\n", lbl_803476DC != 0 ? "Restart" : "Shutdown", "main.c", 0x4ba);
    }
}

void fn_801D9508(void)
{
    s16 i;
    f32 r;
    fn_801D8840(&lbl_8034765C->a0);
    for (i = 0; i < 3; i++) {
        fn_801D8840(&lbl_8034765C->a[i]);
        fn_801D8840(&lbl_8034765C->b[i]);
    }
    r = fn_8022975C(lbl_802F8CF0, 0, 0, -1.001f, 0.0f, lbl_8034765C->b[0].cur[0], lbl_8034765C->a[0].cur[0]);
    r = fn_8022975C(lbl_802F8E80, 0, 0, r, 0.0f, lbl_8034765C->b[1].cur[0], lbl_8034765C->a[1].cur[0]);
    switch (lbl_8034765C->st[1]) {
    case 0:
        fn_8022975C(lbl_802F8D40, 0, 0, r, 0.0f, 1.0f, lbl_8034765C->a0.cur[0]);
        break;
    case 1:
        fn_8022975C(lbl_802F8D90, 0, 0, r, 0.0f, 1.0f, lbl_8034765C->a0.cur[0]);
        break;
    }
}

void fn_801D6998(DataTable *t, s32 *data)
{
    t->data = data;
    t->count = t->data[0];
    t->base = (u8 *)t->data + (t->count + 1) * 4;
    t->offsets = t->data + 1;
    t->work = fn_801E1C7C(t->count * 4);
    ClearWork(t);
    Relocate(t);
}

s32 fn_801D3360(NJS_POINT3* p, Node_801D30DC* n, Hit* out)
{
    Mesh* m;
    s32 tri;
    f32 *va, *vb, *vc;
    s32 cnt;
    Vtx* r;
    f32* base;
    s32 hit;
    f32 loc[2];
    NJS_POINT3 q;

    hit = 0;
    njPushMatrixEx();
    fn_80286EE8();
    fn_8028B498();
    njTranslateEx(n->pos);
    njRotateEx(n->rot, 0);
    njScaleEx(n->scl);
    m = n->mesh;
    if (m != 0) {
        cnt = m->count;
        if (cnt > 0) {
            njPushMatrixEx();
            fn_80286EE8();
            fn_8028B498();
            njInvertMatrix(0);
            njCalcPoint(0, p, &q);
            njPopMatrixEx();
            loc[0] = q.x - m->cx;
            loc[1] = q.z - m->cz;
            if (m->r2 >= loc[0] * loc[0] + loc[1] * loc[1]) {
                loc[0] = q.x;
                loc[1] = q.z;
                r = (Vtx*)((u8*)m + 0x58);
                base = m->verts;
                do {
                    tri = r->idx - 2;
                    r++;
                    do {
                        s16 fl = r[2].flag;
                        s32 i1 = r[1].idx;
                        s32 i0 = r[0].idx;
                        s32 i2 = r[2].idx;
                        vb = (f32*)((u8*)base + (i1 << 2));
                        if (fl < 0) {
                            va = (f32*)((u8*)base + (i2 << 2));
                            vc = (f32*)((u8*)base + (i0 << 2));
                        } else {
                            va = (f32*)((u8*)base + (i0 << 2));
                            vc = (f32*)((u8*)base + (i2 << 2));
                        }
                        hit = fn_801D48BC(loc, va, vb, vc);
                        if (hit != 0) {
                            if (out != 0) {
                                njCalcPoint(0, (NJS_POINT3*)va, &out->a);
                                njCalcPoint(0, (NJS_POINT3*)vb, &out->b);
                                njCalcPoint(0, (NJS_POINT3*)vc, &out->c);
                                out->id = n->id;
                                out->flag = r[2].flag & 0x7FFF;
                            }
                            break;
                        }
                        r++;
                    } while (--tri > 0);
                    r += 2;
                } while (--cnt > 0 && hit == 0);
            }
        }
    }
    if (n->child != 0 && hit == 0) {
        hit = fn_801D3360(p, n->child, out);
    }
    njPopMatrixEx();
    if (n->next != 0 && hit == 0) {
        hit = fn_801D3360(p, n->next, out);
    }
    return hit;
}

s32 fn_801DE6F0(f32* a, f32* b, f32* c, f32 t, KeySet* ks) {
    Key* k = ks->keys;
    s32 n = ks->count;
    s32 i;
    f32 frac;
    if ((f32)(n - 1) >= t) {
        i = (s32)t;
        k += i;
        frac = t - (f32)i;
        if (frac == 0.0f) {
            if (a != NULL) {
                a[0] = k->a[0];
                a[1] = k->a[1];
                a[2] = k->a[2];
            }
            if (b != NULL) {
                b[0] = k->b[0];
                b[1] = k->b[1];
                b[2] = k->b[2];
            }
            if (c != NULL) {
                c[0] = k->c[0];
                c[1] = k->c[1];
                c[2] = k->c[2];
                c[3] = k->c[3];
            }
        } else {
            if (a != NULL) {
                a[0] = k->a[0] + frac * (k[1].a[0] - k->a[0]);
                a[1] = k->a[1] + frac * (k[1].a[1] - k->a[1]);
                a[2] = k->a[2] + frac * (k[1].a[2] - k->a[2]);
            }
            if (b != NULL) {
                b[0] = k->b[0] + frac * (k[1].b[0] - k->b[0]);
                b[1] = k->b[1] + frac * (k[1].b[1] - k->b[1]);
                b[2] = k->b[2] + frac * (k[1].b[2] - k->b[2]);
            }
            if (c != NULL) {
                c[0] = k->c[0] + frac * (k[1].c[0] - k->c[0]);
                c[1] = k->c[1] + frac * (k[1].c[1] - k->c[1]);
                c[2] = k->c[2] + frac * (k[1].c[2] - k->c[2]);
                c[3] = k->c[3] + frac * (k[1].c[3] - k->c[3]);
            }
        }
        return 1;
    }
    return 0;
}

Sprite* fn_801D68C4(void* bank, s32 index)
{
    SpriteBank* b = bank;
    return (Sprite*)(b->base + b->offsets[index]);
}

void fn_801DA6A8(Hdr_801DA6A8 *h) {
    if (h->f0 != 0) {
        E18 *e;
        s32 n;
        u32 v = h->f0 + (u32)h;
        h->f0 = v;
        e = (E18 *)v;
        n = h->n18;
        do {
            if (e->f0c != 0) e->f0c = (u32)&e->f0c + e->f0c;
            if (e->f10 != 0) e->f10 = (u32)&e->f10 + e->f10;
            e++;
        } while (--n > 0);
    }
    if (h->f4 != 0) {
        s32 n;
        E8 *q;
        q = (E8 *)(h->f4 = (u32)&h->f4 + h->f4);
        n = h->n1a;
        do {
            if (q->f4 != 0) q->f4 = (u32)&q->f4 + q->f4;
            q++;
        } while (--n > 0);
    }
}

s32 fn_801DDC48(KeyList *x, KeyList *y) {
    s32 i;
    s32 n;
    s32 ok;
    KeyEnt *p;
    KeyEnt *q;

    n = x->count;
    if (n == y->count) {
        p = x->ents;
        ok = 1;
        q = y->ents;
        for (i = 0; i < n; i++) {
            if (p->key == 0 || p->key != q->key) {
                ok = 0;
                break;
            }
            p++;
            q++;
        }
        return ok;
    }
    return 0;
}

/* fn_80299040 takes t itself (it stores its argument), which is what kept r3 live. */
s32 fn_801D80A0(Top *t) {
    s32 r = 0;
    if (t != 0 && t->f0 != 0 && t->f0->f8 != 0 && t->f0->f8->fc != 0 && t->f0->f8->fc->f20 != 0) {
        fn_80299040(t);
        fn_80291428(1);
        fn_802913E8(0, -1);
        r = 1;
    }
    return r;
}

s32 fn_801D616C(Triple616C* p) {
    if (p == 0) {
        return 0;
    }
    if (p->a == 0) {
        return 0;
    }
    if (p->b == 0) {
        return 0;
    }
    return p->c >= 1;
}

void *fn_801DB124(void *p) {
    s32 i;
    u32 off, cnt;
    GXInvalidateTexAll();
    i = 0;
    for (;;) {
        if (fn_80227AF0(i, p) == 0) {
            off = *(u32 *)((u8 *)p + 0x10);
            cnt = *(u32 *)((u8 *)off + (u32)p);
            p = fn_801E13B0(p, off + (cnt * 0x2c + 4));
            break;
        }
        i++;
    }
    fn_801DAEB8(p);
    return p;
}

void* fn_801DB244(const char* name)
{
    s32 i;
    TexHdr* p;

    p = fn_801CC3C4(name);
    GXInvalidateTexAll();
    i = 0;
    for (;;) {
        if (fn_80227AF0(i, p) == 0) {
            u32 off = p->off;
            p = fn_801E13B0(p, *(u32*)(off + (u32)p) * 0x2c + 4 + off);
            break;
        }
        i++;
    }
    fn_801DAEB8(p);
    return p;
}

/* Rotates `in` about Y by `ang` into `out` (in and out may be the same vector). */
void fn_801DCE18(NJS_VECTOR *out, NJS_VECTOR *in, Angle ang)
{
    NJS_MATRIX m;

    njUnitMatrix(m);
    njRotateY(m, ang);
    if (out != in) {
        njCalcVector(m, in, out);
    } else {
        NJS_VECTOR tmp;
        tmp.x = in->x;
        tmp.y = in->y;
        tmp.z = in->z;
        njCalcVector(m, &tmp, out);
    }
}

void fn_801DFDB0(SpinObj *o) {
    s32 t;
    o->angle += o->speed;
    t = (s32)((o->angle * o->rate) / 360.0f);
    if (t != 0) {
        o->angle -= (360.0f * (f32)t) / o->rate;
    }
    fn_801DFC5C((u8 *)o + 0x24, o->model, o->k02, o->angle);
}

void fn_801D7A90(NJS_TEXLIST* tex, Desc* d)
{
    DrawState st;
    Obj20 obj;
    Rect14 rect;
    NJS_ARGB argb;

    if (tex != 0 && d->enable != 0) {
        DrawStateDefault2D(&st);
        st.attr_or |= d->attr;
        if (d->blend != 0) {
            st.blend_src = 8;
            st.blend_dst = 10;
        }
        DrawStatePush(&st);
        rect.w = d->w;
        rect.h = d->h;
        rect.hw = d->w / 2.0f;
        rect.hh = d->h / 2.0f;
        rect.x = d->x;
        rect.y = d->y;
        rect.x1 = d->x + d->w;
        rect.y1 = d->y + d->h;
        rect.z0 = 0;
        rect.z1 = 0;
        obj.texlist = tex;
        obj.colour = (s32)d->colour;
        obj.sx = 1.0f;
        obj.sy = 1.0f;
        obj.x = d->w / 2.0f + d->ox;
        obj.y = d->h / 2.0f + d->oy;
        obj.data = &rect;
        fn_801D6528(d->col, &argb, d->ca, d->cb);
        njSetConstantMaterial(&argb);
        fn_80005D98(&obj, 0, 0x23, fn_801DBD9C(d->z));
        DrawStatePop(0);
        DrawStateRestore();
    }
}

void fn_801D8DBC(void)
{
    Holder801D *p = lbl_80347660;
    u16 go = 1;
    switch (p->b19) {
    case 0:
    case 0xfe:
        fn_801D8F18();
        go = 0;
        p->b19 = 1;
        break;
    case 1:
    case 3:
    case 4:
        p->b19 = 5;
    case 5:
        if (fn_801D91F4() >= 0) {
            p->b19 = 8;
        }
        break;
    case 8:
    case 9:
        p->b19 = 10;
        break;
    case 10:
        p->b19 = 11;
        go = 0;
        break;
    case 11:
    case 0xff:
        p->b18 |= 0x40;
        lbl_80347660 = 0;
        go = 0;
        break;
    default:
        go = 0;
        break;
    }
    if (go == 1) {
        fn_801D9508();
    }
    lbl_8034765C->w244++;
}

void fn_801D9A0C(s32 a, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5, f32 f6, f32 f7, f32 f8)
{
    Ctx *c = &lbl_8030E830;
    s32 flag = 0;
    if (a == 0x7fffffff || a == 1) {
        flag = 1;
    }
    c->f4 = flag != 0;
    c->f8 = (f1 != 3.4028235e38f) ? f1 : 0.0f;
    c->fc = (f2 != 3.4028235e38f) ? f2 : 0.0f;
    c->f10 = (f3 != 3.4028235e38f) ? f3 : 0.0f;
    c->f14 = (f4 != 3.4028235e38f) ? f4 : 1.0f;
    c->f18 = (f5 != 3.4028235e38f) ? f5 : 0.2f;
    c->f1c = (f6 != 3.4028235e38f) ? f6 : 1.0f;
    c->f20 = (f7 != 3.4028235e38f) ? f7 : 1.0f;
    c->f24 = (f8 != 3.4028235e38f) ? f8 : 1.0f;
    memcpy(lbl_8030E830.f28, c, 0x28);
}

void fn_801DE9BC(KeySet* ks, f32 s) {
    Key* k = ks->keys;
    s32 n = ks->count - 1;
    if (n <= 0) return;
    if (0.0f <= s) {
        do {
            k->da[0] = s * (k[1].a[0] - k->a[0]);
            k->da[1] = s * (k[1].a[1] - k->a[1]);
            k->da[2] = s * (k[1].a[2] - k->a[2]);
            k->db[0] = s * (k[1].b[0] - k->b[0]);
            k->db[1] = s * (k[1].b[1] - k->b[1]);
            k->db[2] = s * (k[1].b[2] - k->b[2]);
            k->dc[0] = s * (k[1].c[0] - k->c[0]);
            k->dc[1] = s * (k[1].c[1] - k->c[1]);
            k->dc[2] = s * (k[1].c[2] - k->c[2]);
            k->dc[3] = s * (k[1].c[3] - k->c[3]);
            k++;
        } while (--n > 0);
        k->da[2] = 0.0f;
        k->da[1] = 0.0f;
        k->da[0] = 0.0f;
        k->db[2] = 0.0f;
        k->db[1] = 0.0f;
        k->db[0] = 0.0f;
        k->dc[3] = 0.0f;
        k->dc[2] = 0.0f;
        k->dc[1] = 0.0f;
        k->dc[0] = 0.0f;
    } else {
        f32 ns;
        k->da[2] = 0.0f;
        ns = -s;
        k->da[1] = 0.0f;
        k->da[0] = 0.0f;
        k->db[2] = 0.0f;
        k->db[1] = 0.0f;
        k->db[0] = 0.0f;
        k->dc[3] = 0.0f;
        k->dc[2] = 0.0f;
        k->dc[1] = 0.0f;
        k->dc[0] = 0.0f;
        do {
            k[1].da[0] = ns * (k->a[0] - k[1].a[0]);
            k[1].da[1] = ns * (k->a[1] - k[1].a[1]);
            k[1].da[2] = ns * (k->a[2] - k[1].a[2]);
            k[1].db[0] = ns * (k->b[0] - k[1].b[0]);
            k[1].db[1] = ns * (k->b[1] - k[1].b[1]);
            k[1].db[2] = ns * (k->b[2] - k[1].b[2]);
            k[1].dc[0] = ns * (k->c[0] - k[1].c[0]);
            k[1].dc[1] = ns * (k->c[1] - k[1].c[1]);
            k[1].dc[2] = ns * (k->c[2] - k[1].c[2]);
            k[1].dc[3] = ns * (k->c[3] - k[1].c[3]);
            k++;
        } while (--n > 0);
    }
}

void fn_801D8840(Anim *a) {
    u16 done = 0;
    if (a->flags & 0x80) {
        a->delay = 0;
        done = 1;
        a->flags &= ~0x81;
    } else if (a->flags & 1) {
        if (a->delay > 0) {
            a->delay--;
        } else if (a->count < a->total) {
            if (a->flags & 8) {
                a->cur[0] += a->delta[0];
                a->cur[1] += a->delta[1];
                a->cur[2] += a->delta[2];
                a->cur[3] += a->delta[3];
            } else {
                a->cur[0] -= a->delta[0];
                a->cur[1] -= a->delta[1];
                a->cur[2] -= a->delta[2];
                a->cur[3] -= a->delta[3];
            }
            a->count++;
        } else if (a->flags & 2) {
            if (!(a->flags & 4)) {
                a->cur[0] = a->start[0];
                a->cur[1] = a->start[1];
                a->cur[2] = a->start[2];
                a->cur[3] = a->start[3];
            } else if (a->flags & 8) {
                a->flags &= ~8;
            } else {
                a->flags |= 8;
            }
            a->count = 0;
        } else {
            a->flags &= ~1;
            done = 1;
        }
    }
    if (done == 1) {
        a->cur[0] = a->end[0];
        a->cur[1] = a->end[1];
        a->cur[2] = a->end[2];
        a->cur[3] = a->end[3];
    }
}

void *fn_801DAE58(const char *name) {
    s32 i;
    void *p;
    p = fn_801CC3C4(name);
    i = 0;
    for (;;) {
        if (fn_80227AF0(i, p) == 0) break;
        i++;
    }
    fn_801DAEB8(p);
    return p;
}

void fn_801DD5E8(s32 *rot, NJS_VECTOR *v) {
    f32 len = fn_80291A5C(v->x * v->x + v->z * v->z);
    if (v->y != 0.0f || len != 0.0f) {
        f32 a = (f32)atan2(v->y, len);
        rot[0] = (s32)(10430.381f * a) & 0xffff;
        lbl_8030EA10[0] = 0;
    } else {
        rot[0] = 0;
        lbl_8030EA10[0] = 1;
    }
    if (v->x != 0.0f || v->z != 0.0f) {
        f32 a = (f32)atan2(v->x, v->z);
        rot[1] = ((s32)(10430.381f * a) + 0x8000) & 0xffff;
        lbl_8030EA10[1] = 0;
    } else {
        rot[1] = 0;
        lbl_8030EA10[1] = 1;
    }
    rot[2] = 0;
}

void fn_801DD22C(Angle *out, NJS_POINT3 *p, NJS_VECTOR *v) {
    NJS_POINT3 n;
    NJS_VECTOR r;
    NJS_MATRIX m;
    Angle a;
    n.x = -p->x;
    n.y = -p->y;
    n.z = -p->z;
    fn_801DD5E8(out, &n);
    njUnitMatrix(m);
    njRotateX(m, -out[0]);
    njRotateY(m, -out[1]);
    njCalcVector(m, v, &r);
    if (r.x != 0.0f || r.y != 0.0f) {
        a = (s32)(10430.381f * (f32)atan2(r.x, r.y));
        a = -a;
        a &= 0xffff;
        lbl_8030EA10[2] = 0;
    } else {
        lbl_8030EA10[2] = 1;
        a = 0;
    }
    out[2] = a;
}

void fn_801E15FC(MemHeap *h, void *p) {
    MemBlk *b;
    void *saved;
    lbl_803476F0 = p;
    lbl_803476E0 = lbl_803476E0 - 1;
    if (p != 0) {
        b = (MemBlk *)((u8 *)p - 0x20);
        if (MemEqual(&b->tag2, "_AMEM", 1) != 1) {
            fn_801DBE1C("memFree Error");
        }
        if (b->tag == 'M' || b->tag == 'R') {
            if (b->prev == 0) {
                h->first = b->next;
                if (b->next != 0) {
                    b->next->prev = 0;
                }
            } else {
                b->prev->next = b->next;
            }
            if (b->next != 0) {
                b->next->prev = b->prev;
            }
            saved = lbl_80346720;
            lbl_803476FC = lbl_803476FC - b->size;
            if (b->flag == 1) {
                lbl_80346720 = lbl_803476A0;
            }
            strncpy((char *)&b->tag, "D_AMEM", 2);
            fn_80005AD8(lbl_80346720, b);
            lbl_80346720 = saved;
        }
    }
}

void fn_801E150C(void *p, u32 v) {
    if (p != NULL) {
        fn_801E1138(lbl_802F6748, p, v, 0);
    } else {
        if (v == 0) {
            v = 0x20;
        }
        lbl_803476E4 = 1;
        p = fn_801E184C(lbl_802F6748, -1, 1, v);
        *(s32 *)((u8 *)p - 0x10) = 0;
        lbl_803476E4 = 0;
    }
}

void fn_801E1584(void *p, u32 v) {
    if (p != NULL) {
        fn_801E1138(lbl_802F6748, p, v, 1);
    } else {
        if (v == 0) {
            v = 0x20;
        }
        lbl_803476E4 = 1;
        p = fn_801E184C(lbl_802F6748, -1, 1, v);
        *(s32 *)((u8 *)p - 0x10) = 0;
        lbl_803476E4 = 0;
    }
}

Task *fn_801DB818(void *parent, const char *name) {
    Task *h;
    s32 i;
    for (i = 0; i < 16; i++) {
        if (lbl_80312D00[i] == NULL) break;
    }
    if (i >= 16) {
        fn_801DBE1C("MLD FAST HANDLE IS EMPTY");
    }
    h = fn_802267AC(parent, fn_801DB2C8);
    lbl_80312D00[i] = h;
    h->work = fn_801E1A74(1, strlen(name) + 0x29);
    if (h->work == NULL) {
        fn_801DBE1C("mldTaskLoadMldDataAll Malloc Error");
    }
    ((MldWork *)h->work)->name = (char *)h->work + 0x20;
    strcpy(((MldWork *)h->work)->name, name);
    ((MldWork *)h->work)->w00 = 0;
    ((MldWork *)h->work)->w10 = 0;
    ((MldWork *)h->work)->w14 = 0;
    ((MldWork *)h->work)->w18 = 0;
    lbl_803474DC++;
    return h;
}

/* The size of p's block when p was allocated from heap h, else 0. */
static inline u32 MemOwns(MemHeap *h, void *p) {
    MemBlk *n = h->first;
    while (n != NULL) {
        if (n->data == p) break;
        n = n->next;
    }
    if (n == NULL) return 0;
    return n->size;
}

void *fn_801E13B0(void *p, u32 size) {
    s32 idx;
    if (MemOwns(&lbl_802F6748[2], p) != 0) {
        idx = 2;
    } else if (MemOwns(&lbl_802F6748[0], p) != 0) {
        idx = 0;
    } else if (MemOwns(&lbl_802F6748[1], p) != 0) {
        idx = 1;
    } else {
        idx = -1;
    }
    if (idx == -1) {
        fn_801DBE1C(lbl_802C46C0);
    }
    return fn_801E1138(&lbl_802F6748[idx], p, size, 1);
}

s32 fn_801DCFA0(NJS_POINT3* v, Angle* a)
{
    NJS_MATRIX m;
    NJS_POINT3 r;
    s32 res;
    njUnitMatrix(m);
    njRotateX(m, -a[0]);
    njRotateY(m, -a[1]);
    njCalcVector(m, v, &r);
    if (r.x != 0.0f || r.y != 0.0f) {
        res = -(s32)(10430.381f * (f32)atan2(r.x, r.y));
        lbl_8030EA10[2] = 0;
        res &= 0xffff;
    } else {
        lbl_8030EA10[2] = 1;
        res = 0;
    }
    return res;
}

/* Heading (16-bit angle) of v seen from the rotation fn_801DD5E8 derives from p. */
s32 fn_801DD078(NJS_POINT3 *v, NJS_POINT3 *p)
{
    NJS_POINT3 r;
    Angle a[3];
    NJS_MATRIX m;
    s32 res;
    fn_801DD5E8(a, p);
    njUnitMatrix(m);
    njRotateX(m, -a[0]);
    njRotateY(m, -a[1]);
    njCalcVector(m, v, &r);
    if (r.x != 0.0f || r.y != 0.0f) {
        f32 ang = atan2(r.x, r.y);
        lbl_8030EA10[2] = 0;
        res = -(s32)(10430.381f * ang);
        res &= 0xffff;
    } else {
        lbl_8030EA10[2] = 1;
        res = 0;
    }
    return res;
}

/* Fills b[0..2] of every key from (time, value) pairs, linearly between the pair times. */
void fn_801DEBE4(KeySet_801DEBE4* ks, f32* tv, s32 n) {
    f32 t0;
    f32 v0;
    f32 last;
    f32 slope;
    f32 f;
    f32 dt;
    s32 i1, i, cnt;
    Key_801DEBE4* k;
    if (n < 1 || (cnt = ks->count) < 3) return;
    {
        v0 = tv[1];
        last = (f32)cnt - 1.0f;
        ks->keys[0].b[2] = v0;
        ks->keys[0].b[1] = v0;
        ks->keys[0].b[0] = v0;
        t0 = 0.0f;
        while (last >= tv[0]) {
            dt = tv[0] - t0;
            i = (s32)t0;
            f = 1.0f - (t0 - (f32)i);
            i++;
            k = ks->keys + i;
            i1 = (s32)tv[0];
            slope = tv[1] - v0;
            if (0.0f < dt) {
                slope /= dt;
            }
            while (i1 >= i++) {
                k->b[0] = k->b[1] = k->b[2] = slope * f + v0;
                f += 1.0f;
                k++;
            }
            if (--n <= 0) break;
            t0 = tv[0];
            v0 = tv[1];
            tv += 2;
        }
        i = (s32)tv[0];
        f = tv[1];
        i++;
        k = ks->keys + i;
        for (cnt = ks->count - i; cnt > 0; cnt--) {
            k->b[2] = f;
            k->b[1] = f;
            k->b[0] = f;
            k++;
        }
    }
}

/* Fills b[0..2] of every key from (time, value) pairs, linearly between the pair times. */
void fn_801DEDC0(KeySet_801DEDC0* ks, f32* tv, s32 n) {
    f32 t0;
    f32 v0;
    f32 last;
    f32 slope;
    f32 f;
    f32 dt;
    s32 i1, i, cnt;
    Key_801DEDC0* k;
    if (n < 1 || (cnt = ks->count) < 3) return;
    {
        v0 = tv[1];
        ks->keys[0].c[0] = v0;
        t0 = 0.0f;
        last = (f32)cnt - 1.0f;
        while (last >= tv[0]) {
            dt = tv[0] - t0;
            i = (s32)t0;
            f = 1.0f - (t0 - (f32)i);
            i++;
            k = ks->keys + i;
            i1 = (s32)tv[0];
            slope = tv[1] - v0;
            if (0.0f < dt) {
                slope /= dt;
            }
            while (i1 >= i++) {
                k->c[0] = slope * f + v0;
                f += 1.0f;
                k++;
            }
            if (--n <= 0) break;
            t0 = tv[0];
            v0 = tv[1];
            tv += 2;
        }
        i = (s32)tv[0];
        f = tv[1];
        i++;
        k = ks->keys + i;
        for (cnt = ks->count - i; cnt > 0; cnt--) {
            k->c[0] = f;
            k++;
        }
    }
}
