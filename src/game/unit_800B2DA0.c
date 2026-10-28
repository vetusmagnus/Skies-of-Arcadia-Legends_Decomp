#include "types.h"
#include "game/work_8030CEA0.h"
#include "ninja.h"
#include "game/sprite.h"
#include "game/util.h"
#include "game/task.h"
#include "game/drawstate.h"
#include <math.h>
#include "game/evobj.h"
extern s32 lbl_803473C8;
extern s32 lbl_803473CC;
extern s32 lbl_803473D0;
extern s32 lbl_803473D4;
extern s32 lbl_803473D8;
extern s32 lbl_80346D4C;
extern s32 lbl_80346D5C;
extern void* fn_801DB124(void* a);
extern f32 lbl_802E1118[];
extern s32 lbl_80346D8C;
extern u8 lbl_80305BA8[];
extern u8 lbl_80310A1C[];
typedef struct Sub2 {
    s32 f0;
    u32 f4;
} Sub2;
typedef struct Sub_800C34C8 {
    u8 pad[0x20];
    Sub2 *f20;
} Sub_800C34C8;
typedef struct Obj_800C34C8 {
    u8 pad0[0x1c8];
    Sub_800C34C8 *f1c8;
} Obj_800C34C8;
typedef struct Sub_800C3518 {
    s32 f0;
    u32 f4;
} Sub_800C3518;
typedef struct Obj_800C3518 {
    u8 pad0[0x100];
    Sub_800C3518 *f100;
} Obj_800C3518;
typedef struct Obj_800CB610 { u8 pad0[0x260]; void *f260; } Obj_800CB610;
typedef struct Src_UNIT0000 {
    u8 pad0[0x14];
    s16 f14;
    s16 f16;
    s16 f18;
    s16 f1a;
    s16 f1c;
    u16 f1e;
} Src_UNIT0000;
typedef struct Obj_800CB68C_UNIT0000 {
    u8 pad0[0x1e8];
    u8 pad1e8[4];
    s8 b1ec;
    s8 b1ed;
    s8 b1ee;
    s8 b1ef;
    u8 pad1f0[0x1fe - 0x1f0];
    s16 f1fe;
    s16 f200;
    u8 pad202[0x204 - 0x202];
    s16 f204;
    u8 pad206[0x22c - 0x206];
    u16 f22c;
    u8 pad22e[0x264 - 0x22e];
    Src_UNIT0000 *p264;
} Obj_800CB68C_UNIT0000;
typedef struct Fx {
    void *p00;
    u32 w04;
    s16 h08;
    s16 h0a;
    s16 h0c;
    s16 h0e;
} Fx;
extern Fx lbl_80305B08;
extern void fn_801E1784(void *p);
typedef struct Obj_800CF8F8 {
    u8 pad0[0x38];
    f32 f38;
    f32 f3c;
    f32 f40;
    u32 f44;
    s32 f48;
} Obj_800CF8F8;
extern struct MapObj* lbl_80347450;
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
typedef struct Node_UNIT0000 {
    u8 pad0[0x48];
    f32 f48;
    u8 pad4c[0x4];
    f32 f50;
    s16 h54;
    s16 h56;
    u8 pad58[0x7c - 0x58];
    struct Node_UNIT0000* next;
} Node_UNIT0000;
typedef struct {
    u8 pad[0x108];
    Node_UNIT0000* list; /* 0x108 */
} Owner_UNIT0000;
typedef struct {
    u8 pad[0x268];
    Owner_UNIT0000* owner; /* 0x268 */
} Ctx_800B2E84_UNIT0000;
extern void fn_801D6944(void*);
extern void fn_801E17E0(void*);
typedef struct {
    u8 pad[0x20];
    NJS_TEXLIST* texlist; /* 0x20 */
} SpriteInner;
typedef struct {
    u8 pad[0x4];
    SpriteInner* inner; /* 0x4 */
} SpriteOuter;
extern void* lbl_80346D30;
extern void* lbl_80346D34;
extern void* lbl_80346D38;
extern SpriteOuter* lbl_80347614;
typedef struct {
    s32 x;
    u32 y;
} Sub_UNIT0000;
typedef struct {
    s32 value;      /* 0x00 */
    u8 pad[0x4];
    Sub_UNIT0000 sub;        /* 0x08 */
} Ent_UNIT0000;
typedef struct {
    s32 count;      /* 0x00 */
    Ent_UNIT0000* items[1];  /* 0x04 */
} ItemList_UNIT0000;
typedef struct {
    u8 pad[0x14];
    ItemList_UNIT0000* list; /* 0x14 */
} Ctx_800C355C_UNIT0000;
typedef struct {
    f32 x, y, z;
} Vec3;
typedef struct {
    u8 pad0[0xc];
    Vec3 a;         /* 0x0c */
    u8 pad1[0x24 - 0x18];
    Vec3 sum;       /* 0x24 */
} Obj_800C4B18;
typedef struct V3_800C3648 {
    f32 x, y, z;
} V3_800C3648;
typedef struct A3_800C3648 {
    s32 x, y, z;
} A3_800C3648;
typedef struct Cam_800C3648 {
    u8 pad0[2];
    s16 h2;
    u8 pad4[0xc - 4];
    V3_800C3648 pos;        /* 0x0c */
    u8 pad18[0x24 - 0x18];
    f32 f24, f28, f2c;
    u8 pad30[0x34 - 0x30];
    f32 f34;
    u8 pad38[0x3c - 0x38];
    s32 w3c;
    s32 w40;
    s32 w44;
    f32 f48;
    f32 f4c, f50, f54;
    u8 pad58[0x64 - 0x58];
    f32 f64, f68, f6c;
    s32 w70;
    s32 w74;
    u8 pad78[0xd0 - 0x78];
    f32 fd0;
    u8 padd4[0xf0 - 0xd4];
    f32 ff0, ff4, ff8;
    u8 padfc[0x10c - 0xfc];
    s32 w10c;
} Cam_800C3648;
extern s32 fn_80090DBC(s32 a);
extern s32 fn_8009761C(s32 a, s32 b);
extern void fn_80095360(void *p, void *q);
extern void fn_8022BAA0(void* a, void* b, void* c, void* d);
extern void fn_801E66E0();
extern u32 lbl_80346D48;
typedef struct {
    u8 pad0[0x100];
    void* f100;
} Inner_UNIT0000;
typedef struct {
    u8 pad0[0x19];
    u8 state;       /* 0x19 */
    u8 pad1[0x24 - 0x1a];
    Inner_UNIT0000* inner;   /* 0x24 */
} Obj_800C6724_UNIT0000;
typedef struct {
    u8 pad0[0x19];
    u8 state;       /* 0x19 */
    u8 pad1[0x24 - 0x1a];
    Inner_UNIT0000* inner;   /* 0x24 */
} Obj_800C67A8_UNIT0000;
typedef struct {
    u8 pad[8];
    u32 flags;      /* 0x08 */
} Ctrl;
extern Ctrl* lbl_80311A60[6];
typedef struct {
    u8 pad0[0x19];
    u8 state;       /* 0x19 */
} Obj_800C682C;
extern void fn_801002D0(const char* name);
extern u8 lbl_802B1448[];
extern Vec3 lbl_8030A2E8;
extern u32 lbl_8030A2DC[3];
extern s32 lbl_803473B8;
extern void* fn_801E1A2C(u32 size, u32 align);
typedef struct Node_800B2DC0 {
    u8 pad0[0x48];
    f32 f48;
    f32 f4c;
    f32 f50;
    s16 h54;
    s16 h56;
    u8 pad58[0x7c - 0x58];
    struct Node_800B2DC0 *next; /* 0x7c */
} Node_800B2DC0;
typedef struct Owner_800B2DC0 {
    u8 pad0[0x108];
    Node_800B2DC0 *list; /* 0x108 */
} Owner_800B2DC0;
typedef struct Ctx_800B2DC0 {
    u8 pad0[0x268];
    Owner_800B2DC0 *owner; /* 0x268 */
} Ctx_800B2DC0;
typedef struct X_800BC02C {
    u8 pad0[0x50];
    u32 w50;
    u32 w54;
    u32 w58;
    u32 w5c;
    u8 pad60[0xe8 - 0x60];
    u32 we8;
} X_800BC02C;
typedef struct Inner_800BC02C {
    u8 pad0[0x10];
    X_800BC02C *p10; /* 0x10 */
} Inner_800BC02C;
typedef struct Self_800BC02C {
    u8 pad0[0x100];
    u32 w100;
    u8 pad104[0x1c8 - 0x104];
    Inner_800BC02C *p1c8; /* 0x1c8 */
} Self_800BC02C;
typedef struct Out {
    u8 pad0[0x7a];
    s16 h7a;
    u32 w7c;
    u32 w80;
    u8 pad84;
    u8 b85;
    u8 b86;
    u8 b87;
    u8 pad88[0x8c - 0x88];
    u32 w8c;
} Out;
extern u32 fn_800A1AE8(void *s, s32 a);
extern u32 fn_800A1ABC(void *s, s32 a);
extern s32 fn_800A10A8(u32 a, u32 b, u32 c);
typedef struct X_800BD904 {
    u8 pad0[0x6c];
    u32 w6c;
} X_800BD904;
typedef struct Inner_800BD904 {
    u8 pad0[0x10];
    X_800BD904 *p10; /* 0x10 */
} Inner_800BD904;
typedef struct Sub_800BD904 {
    u8 pad0[0x50];
    f32 f50;
    f32 f54;
    u8 pad58[0x1c8 - 0x58];
    Inner_800BD904 *p1c8; /* 0x1c8 */
} Sub_800BD904;
typedef struct Actor_800BD904 {
    u8 pad0[0x24];
    Sub_800BD904 *sub; /* 0x24 */
} Actor_800BD904;
typedef struct Rec_UNIT0000 {
    u32 w0;
    u32 w4;
    u32 w8;
    u32 wc;
    u32 w10;
    u32 w14;
    f32 f18;
    f32 f1c;
    f32 f20;
} Rec_UNIT0000;
extern f32 njCos(Angle a);
extern f32 njSin(Angle a);
extern void *fn_801E49D8(void *s);
extern void *fn_801E4974(void *p, s32 n);
extern u32 fn_801E48A8(void *p);
extern void *fn_801E1C7C(u32 n);
extern void *fn_801E4984(void *p, s32 n);
extern void *fn_801E1584(void *p, u32 n);
extern void fn_801D6998(void *p, void *q);
extern char lbl_802B13BC[];
extern void *lbl_80346D40;
extern void *lbl_80346D44;
extern void *lbl_80346D3C;
extern void fn_801DD9AC(void *a, void *b);
extern void fn_801DD95C(void *p);
extern void fn_80100B74(void *self);
extern s32 lbl_803474EC;
typedef struct Node_800C3428 {
    u8 pad0[0x4];
    u32 w4;
} Node_800C3428;
typedef struct Sub_800C3428 {
    u8 pad0[0x100];
    Node_800C3428 *p100; /* 0x100 */
    u8 pad104[0x1ac - 0x104];
    void *p1ac; /* 0x1ac */
    void *p1b0; /* 0x1b0 */
} Sub_800C3428;
typedef struct Self_800C3428 {
    u8 pad0[0x24];
    Sub_800C3428 *sub; /* 0x24 */
} Self_800C3428;
extern void fn_80091040(void *a, void *b);
extern s32 fn_80095110(void);
extern s32 fn_800912A8(s32 a, s32 b, s32 c, s32 d);
extern void fn_801DCEB0(void *a, void *b, f32 c);
typedef struct Obj_800C40EC {
    u8 pad_0[0xc];
    u8 box[0x24 - 0xc];
    f32 f24;
    f32 f28;
    f32 f2c;
    f32 f30;
    f32 f34;
    f32 f38;
    u8 pad3c[0x8];
    s32 w44;
    u8 pad48[0x4];
    f32 f4c;
    f32 f50;
    f32 f54;
    u8 pad58[0x1c];
    s32 w74;
    u8 pad78[0x34];
    f32 fac;
    f32 fb0;
    f32 fb4;
    u8 padb8[0x14];
    f32 fcc;
    u8 padd0[0x8];
    s32 wd8;
} Obj_800C40EC;
extern void fn_800967F0(void *self, s32 a, s32 b);
typedef struct Part {
    u8 pad0[0x14];
    s16 h14;
} Part;
typedef struct Other {
    u8 pad0[0x2];
    s16 h2;
} Other;
typedef struct Obj_800C4B90 {
    s16 h0;
    s16 h2;
    u8 pad4[0x8];
    f32 fc;
    f32 f10;
    f32 f14;
    u8 pad18[0x24 - 0x18];
    f32 f24;
    f32 f28;
    f32 f2c;
    f32 f30;
    f32 f34;
    f32 f38;
    u8 pad3c[0x4c - 0x3c];
    f32 f4c;
    f32 f50;
    f32 f54;
    u8 pad58[0x64 - 0x58];
    f32 f64;
    f32 f68;
    f32 f6c;
    u8 pad70[0x108 - 0x70];
    Part *p108;
} Obj_800C4B90;
extern void fn_8022BAA0(void *a, void *b, void *c, void *d);
typedef struct Obj_800C5108 {
    u8 pad_0[0xc];
    u8 box[0x24 - 0xc];
    f32 f24;
    f32 f28;
    f32 f2c;
    f32 f30;
    f32 f34;
    f32 f38;
    u8 pad3c[0x4c - 0x3c];
    f32 f4c;
    f32 f50;
    f32 f54;
    f32 f58;
    f32 f5c;
    f32 f60;
    u8 pad64[0xa0 - 0x64];
    f32 fa0;
    f32 fa4;
    f32 fa8;
    f32 fac;
    f32 fb0;
    f32 fb4;
} Obj_800C5108;
extern void fn_801E7DF0(void *p);
typedef struct Ctl_800C5B58 {
    s16 h0;
    s16 h2;
} Ctl_800C5B58;
typedef struct Obj_800C5B58 {
    u8 pad0[0x188];
    u32 w188;
    u8 pad18c[0x1b0 - 0x18c];
    u32 w1b0;
    u8 pad1b4[0x1e4 - 0x1b4];
} Obj_800C5B58;
typedef struct Key_800C5D78 {
    s16 v;
    s16 frames;
} Key_800C5D78;
typedef struct KeyTable_800C5D78 {
    u8 count;
    u8 pad1[3];
    Key_800C5D78 keys[1];
} KeyTable_800C5D78;
typedef struct Key2 {
    u8 pad0;
    u8 r;
    u8 g;
    u8 b;
    s32 frames;
} Key2;
typedef struct Obj_800C5D78 {
    u8 pad0[0x1c];
    f32 f1c;
    u8 padc0[0xc4];
    void* pe4;
    void* pe8;
    u8 pade[0x9c];
    u32 flags;
    u8 pad18c[0x24];
    void* p1b0;
    u8 pad1b4[0x48];
    s16 h1fc;
    s16 h1fe;
    u8 pad200[0x4c];
    f32 f24c;
    u8 pad250[0xc];
    KeyTable_800C5D78* tbl;
} Obj_800C5D78;
extern void fn_801E5E2C(void);
extern void fn_801E5E7C();
extern void fn_801DD7D8(void* p);
s32 fn_800C5D78(Obj_800C5D78* o);
extern void fn_800C5EE8(void *p);
typedef struct Obj_800C6310 {
    u8 pad0[0x19];
    u8 b19;
    u8 pad1a[0x24 - 0x1a];
    void *p24;
} Obj_800C6310;
void fn_80226AE8();
typedef struct Ent_800C86EC {
    void (*fn)(struct Ent_800C86EC *);
    u8 pad4[0x14];
    u8 flags;
    u8 pad19[7];
    f32 val;
    u8 pad24[0x2C0 - 0x24];
} Ent_800C86EC;
typedef struct Host_800C86EC {
    u8 pad0[0x10];
    struct {
        u32 count;
    } *hdr;
    u8 pad14[4];
    Ent_800C86EC *ents;
} Host_800C86EC;
extern u32 lbl_80305A5C[];
typedef struct {
    s32 unk0;
    s32 map;
    char room;
} MapInfo2;
extern MapInfo2 lbl_80311AC0;
typedef struct {
    u8 pad0[0x24];
    void *tab;
} Mgr_800C8F3C;
extern Mgr_800C8F3C *lbl_80346D70;
void *fn_8015F1A0(s32 id);
void fn_801003F4(void *p);
extern void *lbl_803475A8;
void *fn_802268E8(void *list, void *fn);
void fn_800C9144(void);
typedef struct {
    u32 a;
    u32 b;
    u32 key;
    u8 pad1[4];
} Entry_UNIT0000;
extern s32 lbl_80346D80;
typedef struct {
    u8 pad0[0x8];
    void *a8;
    u8 padc[0x14];
    void *f20;
    void *f24;
    u8 pad28[4];
} Elem;
typedef struct {
    u8 pad0[0x18];
    Elem elems[1];
} List_UNIT0000;
typedef struct {
    u8 pad0[0x1ac];
    s32 f1ac;
    s32 f1b0;
    u8 pad1b4[0x218 - 0x1b4];
    s32 count;
    u8 pad21c[0x25c - 0x21c];
    List_UNIT0000 *list;
} Self_800D1268_UNIT0000;
void fn_801DD9AC(void *a, void *b);
typedef struct {
    u8 pad0[0x34];
    s32 v34;
} Sub_800D2924;
typedef struct {
    u8 pad0[0x184];
    s32 f184;
    u8 pad188[0x1c8 - 0x188];
    Sub_800D2924 *p1c8;
} Self_800D2924;
s32 fn_800D2924(Self_800D2924 *self);
typedef struct {
    u8 pad0[0x34];
    s32 v34;
    u8 rest[0x68 - 0x38];
} Item68;
typedef struct {
    s32 count;
    s32 ids[1];
} IdList;
typedef struct {
    u8 pad0[0xc];
    IdList *list;
} Group;
typedef struct {
    u8 pad0[0x6];
    s16 a6;
    u8 pad8[0x18 - 0x8];
    f32 f18;
    f32 f1c;
    f32 f20;
    f32 f24;
    u8 pad28[0x2a - 0x28];
    u16 u2a;
    u32 u2c;
    Group *grp;
    u32 u34;
    u32 u38;
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
typedef struct {
    u8 pad[0x1fc];
    s16 x1fc;
    u8 pad1fe[0x200 - 0x1fe];
    s16 x200;
    s16 x202;
    u8 pad204[0x22e - 0x204];
    s16 x22e;
    s16 x230;
} Work_800B4038;
typedef struct {
    u8 pad0[0x48];
    f32 x48;
    f32 x4c;
    u8 pad50[0x5c - 0x50];
    s16 x5c;
    u8 pad5e[0x68 - 0x5e];
    u16 x68;
    u8 pad6a[2];
    s16 x6c;
    u8 pad6e;
    u8 x6f;
    u8 pad70[0x108 - 0x70];
    s32 x108;
    u8 pad10c[4];
    s32 x110;
} Obj_800B4038;
typedef struct Node_800B77E4 {
    u8 pad[0x10];
    struct Node_800B77E4* next;
    u8 pad14[4];
} Node_800B77E4;
typedef struct {
    u8 pad[0xb0];
    s32 xb0;
} Cfg_800B77E4;
typedef struct {
    u8 pad[0x10];
    Cfg_800B77E4* cfg;
} Link_800B77E4;
typedef struct {
    u8 pad[0x1c8];
    Link_800B77E4* link;
    u8 pad1cc[0x22c - 0x1cc];
    u16 x22c;
    u8 pad22e[0x258 - 0x22e];
    f32 x258;
    Node_800B77E4* list;
} Work_800B77E4;
extern void fn_801E1784(void* p);
typedef struct Part_800BA444 {
    u8 pad0[0xc];
    u8 posb[0xc];
    f32 x18;
    f32 x1c;
    u8 pad20[4];
    f32 x24;
    f32 x28;
    s16 x2c;
    s16 life; /* 0x2e */
    u8 pad30[4];
    struct Part_800BA444* next; /* 0x34 */
} Part_800BA444;
typedef struct {
    f32 x;
    f32 y;
    u8 pad[0xc];
    u8 x14;
    u8 pad15[3];
} Emit_800BA444;
typedef struct {
    u8 pad0[0x70];
    Emit_800BA444 emit;
    u8 pad88[0x110 - 0x88];
    s16 x110;
    u8 pad112[0x118 - 0x112];
    s32 x118;
    f32 x11c;
} Work_800BA444;
typedef struct {
    u8 pad[0x260];
    Part_800BA444* parts;
} Obj_800BA444;
void fn_800D208C(u32 col, f32 start);
extern void fn_800D2048(void);
extern u8 fn_8009E4D4(f32 v);
extern void fn_800A2830(Emit_800BA444* e, Part_800BA444* p, void* q);
typedef struct {
    u8 pad[0x20];
    void* x20;
} Inner_800C2F4C;
typedef struct {
    u8 pad[4];
    Inner_800C2F4C* inner;
} Obj_800C2F4C;
extern u8 lbl_802B13A0[0x19];
typedef struct {
    u8 pad0[0x24];
    f32 x24, x28, x2c;
    f32 x30, x34, x38;
    u8 pad3c[0x4c - 0x3c];
    f32 x4c, x50, x54;
    u8 pad58[0x70 - 0x58];
    u8 x70[0xc];
    u8 pad7c[0xcc - 0x7c];
    f32 xcc, xd0;
} Cam_800C3A50;
extern void fn_80094F90(void* out, void* c);
f32 njTan(Angle a);
typedef struct {
    u8 pad0[0x14];
    s16 x14;
} Sub_800C3B58;
typedef struct {
    u8 pad0[2];
    s16 flags;
    u8 pad4[0x54 - 4];
    f32 x54;
    u8 pad58[4];
    f32 x5c;
    u16 x60;
} Src_800C3B58;
typedef struct {
    u8 pad0[2];
    s16 flags;
    u8 pad4[0x30 - 4];
    f32 x30, x34, x38;
    u8 pad3c[4];
    s32 x40, x44, x48;
    u8 pad4c[0x70 - 0x4c];
    s32 x70, x74, x78;
    u8 pad7c[0xcc - 0x7c];
    f32 xcc, xd0;
    u8 padd4[0xe8 - 0xd4];
    s32 xe8, xec;
    u8 padf0[0x108 - 0xf0];
    Sub_800C3B58* x108;
    u8 pad10c[0x158 - 0x10c];
    f32 x158;
} Obj_800C3B58;
typedef struct {
    s32 x, y, z;
} Ang3_800C47BC;
typedef struct {
    u8 pad0[0xc];
    NJS_VECTOR pos;      /* 0x0c */
    u8 pad18[0x24 - 0x18];
    f32 x24, x28, x2c;
    f32 x30, x34, x38;
    u8 pad3c[0x40 - 0x3c];
    u8 x40[4];
    s32 x44;
    u8 pad48[0x4c - 0x48];
    f32 x4c, x50, x54;
    u8 pad58[0x70 - 0x58];
    s32 x70;
    u8 pad74[0xa0 - 0x74];
    u8 xa0[0xc];
    f32 xac, xb0, xb4;
    u8 padb8[0xcc - 0xb8];
    f32 xcc;
    u8 padd0[0xd8 - 0xd0];
    s32 xd8;
} Cam_800C47BC;
extern void fn_80090F9C(Ang3_800C47BC* out, f32* a, NJS_VECTOR* b);
typedef struct {
    u8 pad0[0xc];
    NJS_VECTOR pos;      /* 0x0c */
    u8 pad18[0x24 - 0x18];
    u8 x24[0xc];
    u8 pad30[0x40 - 0x30];
    u8 x40[4];
    u8 pad44[0x4c - 0x44];
    NJS_VECTOR tgt;      /* 0x4c */
    u8 pad58[0xa0 - 0x58];
    u8 xa0[0xc];
} Cam_800C4F1C;
extern void fn_800C4C54(NJS_VECTOR* out, void* c);
extern void fn_800914D8(NJS_VECTOR* a, NJS_VECTOR* b, f32 p, f32 q);
typedef struct {
    u8 pad0[0x14];
    s16 x14;
} Sub_800C5014;
typedef struct {
    u8 pad0[2];
    s16 flags;
    u8 pad4[0x54 - 4];
    f32 x54;
    u8 pad58[4];
    f32 x5c;
    u8 pad60[2];
    s16 x62;
} Src_800C5014;
typedef struct {
    u8 pad0[2];
    s16 flags;
    u8 pad4[0x34 - 4];
    f32 x34;
    u8 pad38[0x4c - 0x38];
    NJS_VECTOR tgt;      /* 0x4c */
    u8 pad58[0xcc - 0x58];
    f32 xcc, xd0;
    u8 padd4[0xe6 - 0xd4];
    s16 xe6;
    u8 pade8[0x108 - 0xe8];
    Sub_800C5014* x108;
} Obj_800C5014;
typedef struct {
    u8 pad0[0x14];
    s16 x14;
} Sub_800C51BC;
typedef struct {
    u8 pad0[2];
    s16 flags;
    u8 pad4[0x4c - 4];
    f32 x4c, x50;
} Src_800C51BC;
typedef struct {
    u8 pad0[2];
    s16 flags;
    u8 pad4[0xc - 4];
    NJS_VECTOR pos;      /* 0x0c */
    u8 pad18[0x24 - 0x18];
    NJS_VECTOR x24;
    NJS_VECTOR x30;
    u8 pad3c[0x4c - 0x3c];
    NJS_VECTOR tgt;      /* 0x4c */
    NJS_VECTOR x58;
    u8 pad64[0xac - 0x64];
    NJS_VECTOR xac;
    f32 xb8, xbc;
    u8 padc0[0x108 - 0xc0];
    Sub_800C51BC* x108;
} Obj_800C51BC;
typedef struct {
    u8 pad0[0xC];
    f32 pos[3];     /* 0x0C */
    u8 pad18[0xC];
    f32 out[3];     /* 0x24 */
    f32 off[3];     /* 0x30 */
    u8 pad3C[0x10];
    f32 res[3];     /* 0x4C */
    u8 pad58[0xC];
    f32 tgt[3];     /* 0x64 */
} Obj_800C52F0;
typedef struct {
    s16 pad0;
    s16 flags;        /* 0x02 */
    u8 pad4[0x30 - 4];
    f32 x30;          /* 0x30 */
    f32 x34;          /* 0x34 */
    f32 x38;          /* 0x38 */
    u8 pad3C[0x4C - 0x3C];
    f32 out[3];       /* 0x4C */
    f32 vel[3];       /* 0x58 */
    f32 pos[3];       /* 0x64 */
    u8 pad70[0xE8 - 0x70];
    s32 xe8;          /* 0xE8 */
    s32 xec;          /* 0xEC */
} Ent_800C540C;
typedef struct {
    u8 pad0[0x14];
    s16 flags;        /* 0x14 */
} Sub;
typedef struct {
    s16 pad0;
    s16 flags;        /* 0x02 */
    u8 pad4[0x60 - 4];
    u16 x60;          /* 0x60 */
    u16 pad62;
    f32 x64;          /* 0x64 */
} Src_800C540C;
typedef struct {
    s16 pad0;
    s16 flags;        /* 0x02 */
    u8 pad4[0x30 - 4];
    f32 x30;          /* 0x30 */
    f32 x34;          /* 0x34 */
    f32 x38;          /* 0x38 */
    u8 pad3C[0x4C - 0x3C];
    f32 out[3];       /* 0x4C */
    f32 vel[3];       /* 0x58 */
    f32 pos[3];       /* 0x64 */
    u8 pad70[0xE8 - 0x70];
    s32 xe8;          /* 0xE8 */
    s32 xec;          /* 0xEC */
    u8 padF0[0x108 - 0xF0];
    Sub* sub;         /* 0x108 */
} Obj_800C540C;
extern f32 fn_80116028(void);
typedef struct {
    u8 pad0[0x14];
    u32** items;      /* 0x14 */
} Ext_800C6890;
typedef struct {
    u8 pad0[0x1C];
    f32 x1c;          /* 0x1C */
    u8 pad20[0xE4 - 0x20];
    u32 model;        /* 0xE4 */
    u8 padE8[0x168 - 0xE8];
    s16 idx;          /* 0x168 */
    u8 pad16A[0x180 - 0x16A];
    s32 count;        /* 0x180 */
    u8 pad184[0x1C8 - 0x184];
    Ext_800C6890* ext;         /* 0x1C8 */
} Ent_800C6890;
extern f32 lbl_802E1020[4][13];
typedef struct { u8 pad[8]; u32 x8; } PadState;
typedef struct { PadState* pad; u8 pad4[0x14]; } PadInfo;
typedef struct {
    u8 pad0[0x38];
    f32 f38[9];       /* 0x38 */
    u8 pad5C[0x100 - 0x5C];
    NJS_TEXLIST* texlist; /* 0x100 */
    u8 pad104[0x168 - 0x104];
    s16 idx;          /* 0x168 */
    u8 pad16A[0x16E - 0x16A];
    s16 x16e;         /* 0x16E */
    u8 pad170[0x180 - 0x170];
    s32 count;        /* 0x180 */
    u8 pad184[0x1C8 - 0x184];
    void* x1c8;       /* 0x1C8 */
} Ent_800C69CC;
extern void fn_802275A4(NJS_TEXLIST* texlist, s32 a);
extern Task* fn_801C6180(Task* parent, void (*func)(Task*));
extern void fn_800C6890(Task* task);
extern void MemCopy(void* dst, const void* src, s32 size);
typedef struct {
    u8 pad0[8];
    s32 x8;           /* 0x08 */
    u8 pad0C[0x18 - 0x0C];
    s32 x18;          /* 0x18 */
    u8 pad1C[0x2C - 0x1C];
    s32 x2c;          /* 0x2C */
    u8 pad30[8];
    NJS_POINT3 pos;   /* 0x38 */
    u8 pad44[0x100 - 0x44];
    NJS_TEXLIST* texlist; /* 0x100 */
    u8 pad104[0x176 - 0x104];
    s16 x176;         /* 0x176 */
} Ent_800C7230;
extern f32 lbl_80346788;
extern f32 lbl_8034678C;
extern f32 lbl_8030E830[];
extern void fn_801D9BFC(void);
extern void fn_801D9B34(void);
extern void fn_801D9C64(f32 a, f32 b, f32 c);
typedef struct {
    u8 pad0[0x104];
    f32 x104;         /* 0x104 */
    u8 pad108[4];
    f32 x10c;         /* 0x10C */
    u8 pad110[0x16A - 0x110];
    u8 x16a;          /* 0x16A */
    u8 x16b;          /* 0x16B */
    u8 pad16C[0x25C - 0x16C];
    void* x25c;       /* 0x25C */
    void* x260;       /* 0x260 */
} Work;
typedef struct {
    u8 pad0[0x24];
    Work* work;       /* 0x24 */
    u8 pad28[0x2C0 - 0x28];
} Obj_800C879C;
/* 0x2C0 bytes */
typedef struct {
    u32 count;
} List_800C879C;
typedef struct {
    u8 pad0[4];
    s32 x4;           /* 0x04 */
    u8 pad8[4];
    s32 xc;           /* 0x0C */
    List_800C879C* list;       /* 0x10 */
    u8 pad14[4];
    Obj_800C879C* objs;        /* 0x18 */
    s32 x1c;          /* 0x1C */
    u32 cur;          /* 0x20 */
} State_800C879C;
extern void (*lbl_80347498)(void);
extern s32 lbl_80346D60;
extern void fn_800C79C4(void);
extern void fn_8010092C(void);
extern void fn_801C610C(Work* w);
extern void fn_80101060(void* o, u32 i, void* list);
typedef struct {
    u16 base;         /* 0x00 */
    u16 range;        /* 0x02 */
    u32 pad4;
} Entry_800CC3D4;
typedef struct {
    s16 count;        /* 0x00 */
    s16 mode;         /* 0x02 */
    Entry_800CC3D4 entries[1]; /* 0x04 */
} Table_800CC3D4;
typedef struct {
    u8 pad0[0x180];
    s32 x180;         /* 0x180 */
    u8 pad184[0x1FC - 0x184];
    s16 x1fc;         /* 0x1FC */
} Ent_800CC3D4;
extern int rand(void);
typedef struct {
    u8 pad0[0x38];
    f32 x38, x3c, x40;  /* 0x38 */
    u32 x44, x48;       /* 0x44 */
    u8 pad4C[0xE4 - 0x4C];
    void* model;        /* 0xE4 */
    u8 padE8[0x16E - 0xE8];
    s16 x16e;           /* 0x16E */
    u8 pad170[0x184 - 0x170];
    s32 x184;           /* 0x184 */
} Ent_800CD924;
extern void fn_800C35C4(void* e, s32 n);
extern void fn_801E7E14(void* model, s32 a, s32 b, s32 c);
extern void fn_800C3428(Self_800C3428* self);
typedef struct {
    f32 x, y, z;
} V3;
extern void fn_800CF7BC(V3* a, V3* b, f32 c);
typedef struct {
    u8 pad0[8];
    f32 x8;           /* 0x08 */
    f32 xc;           /* 0x0C */
    f32 x10;          /* 0x10 */
} Src_800CFAB8;
typedef struct {
    u8 pad0[0x44];
    s32 x44;          /* 0x44 */
    u8 pad48[0x6C - 0x48];
    s32 x6c;          /* 0x6C */
    u8 pad70[0x164 - 0x70];
    f32 x164;         /* 0x164 */
} Ent_800CFAB8;
extern s32 fn_80091228(s32 a, s32 b, f32 c);
typedef struct {
    s16 x0;           /* 0x00 */
    u8 pad2[6];
    f32 x8;           /* 0x08 */
    f32 xc, x10, x14; /* 0x0C */
} Aux;
typedef struct {
    u8 pad0[0x38];
    f32 x38, x3c, x40; /* 0x38 */
    u8 pad44[4];
    s32 x48;          /* 0x48 */
    u8 pad4C[0x60 - 0x4C];
    f32 x60;          /* 0x60 */
    u8 pad64[0x6C - 0x64];
    s32 x6c;          /* 0x6C */
    u8 pad70[0xB8 - 0x70];
    f32 xb8;          /* 0xB8 */
    u8 padBC[0xC0 - 0xBC];
    u32 xc0;          /* 0xC0 */
    u8 padC4[0x104 - 0xC4];
    f32 x104, x108, x10c; /* 0x104 */
    u8 pad110[0x164 - 0x110];
    f32 x164;         /* 0x164 */
    u8 pad168[0x16C - 0x168];
    s16 x16c;         /* 0x16C */
    u8 pad16E[0x25C - 0x16E];
    Aux* x25c;        /* 0x25C */
} Ent_800D1028;
extern void fn_800D0E78(void* e);
typedef struct Handle {
    u8 pad0[4];
    u32 w4;
} Handle;
/* A collision node (unit_80219378.c's Node). */
typedef struct HitNode {
    s32 (*cb)(struct HitNode *, struct HitNode *);
    struct HitNode *p4;  /* 0x04 */
    u8 pad8[0x10 - 8];
    u16 mask10;          /* 0x10 */
    u16 id12;            /* 0x12 */
    s16 h14;             /* 0x14 */
    u16 h16;             /* 0x16 */
} HitNode;
/* The field-map object: lbl_80347450 (the player) and the work of the map-object tasks. */
typedef struct MapObj {
    u8 pad0[8];
    s32 x8;             /* 0x08 */
    f32 f0c, f10;       /* 0x0c */
    u8 pad14[0x1c - 0x14];
    f32 f1c;            /* 0x1c */
    u8 pad20[0x2c - 0x20];
    s32 x2c;            /* 0x2c */
    u8 pad30[0x38 - 0x30];
    f32 pos[3];         /* 0x38 */
    s32 w44;            /* 0x44 */
    s32 s48;            /* 0x48 */
    s32 w4c;            /* 0x4c */
    u8 pad50[0xe4 - 0x50];
    void* pe4;          /* 0xe4 */
    void* pe8;          /* 0xe8 */
    void* pec;          /* 0xec */
    u8 padf0[0x100 - 0xf0];
    NJS_TEXLIST* texlist; /* 0x100 */
    f32 save[3];        /* 0x104 */
    u8 pad110[0x16a - 0x110];
    u8 b16a, b16b;      /* 0x16a */
    u8 pad16c[2];
    s16 x16e;           /* 0x16e */
    u8 pad170[0x176 - 0x170];
    u16 flags176;       /* 0x176 */
    u8 pad178[0x184 - 0x178];
    s32 w184;           /* 0x184 */
    u8 pad188[0x18c - 0x188];
    f32 f18c;           /* 0x18c */
    f32 f190;           /* 0x190 */
    u8 pad194[0x198 - 0x194];
    s32 w198;           /* 0x198 */
    u8 pad19c[0x1ac - 0x19c];
    s32 w1ac;           /* 0x1ac */
    s32 w1b0;           /* 0x1b0 */
    void* p1b4;         /* 0x1b4 */
    struct Sub_800C5530* p1b8; /* 0x1b8 */
    HitNode* p1bc;      /* 0x1bc */
    u8 pad1c0[0x1C4 - 0x1C0];
    void* p1c4;         /* 0x1c4 */
    struct MapSub* p1c8; /* 0x1c8 */
    u8 pad1cc[0x1ec - 0x1cc];
    s8 b1ec;            /* 0x1ec */
    u8 pad1ed[0x1fc - 0x1ed];
    s16 h1fc;           /* 0x1fc */
    u8 pad1fe[2];
    s16 h200;           /* 0x200 */
    u8 pad202[0x248 - 0x202];
    void* p248;         /* 0x248 */
    u8 pad24c[0x25c - 0x24c];
    struct Script* p25c; /* 0x25c */
    struct Cmd* p260;   /* 0x260 */
} MapObj;
typedef struct Entry {
    s16 h0;
    s16 h2;
    f32 f4;
    NJS_TEXLIST* w8;
    void* wc;
    Handle* w10;
    void* w14;
    f32 f18;
    f32 f1c;
    s32 w20;
    s32 w24;
    u8 pad28[4];
} Entry;
typedef struct Script {
    s16 h0;
    s16 h2;
    u8 pad4[0x14];
    Entry entries[1];
} Script;
extern s32 lbl_8034753C;
extern void fn_801E6438(MapObj* a);
extern void fn_801E6744(MapObj* a);
void fn_800D0CC8(MapObj* a);
typedef struct {
    u8 pad0[0x48];
    s32 x48;          /* 0x48 */
    u8 pad4C[0x6C - 0x4C];
    s32 x6c;          /* 0x6C */
    u8 pad70[0xB8 - 0x70];
    f32 xb8;          /* 0xB8 */
    u8 padBC[0xC0 - 0xBC];
    u32 xc0;          /* 0xC0 */
    u8 padC4[0x164 - 0xC4];
    f32 x164;         /* 0x164 */
    u8 pad168[0x16C - 0x168];
    s16 x16c;         /* 0x16C */
    u8 pad16E[0x25C - 0x16E];
    Aux* x25c;        /* 0x25C */
} Ent_800D1174;
typedef struct {
    u8 pad0[0x38];
    f32 x38, x3c, x40; /* 0x38 */
    u32 x44;          /* 0x44 */
    s32 x48;          /* 0x48 */
    u32 x4c;          /* 0x4C */
    u8 pad50[0x60 - 0x50];
    f32 x60;          /* 0x60 */
    u8 pad64[0x6C - 0x64];
    s32 x6c;          /* 0x6C */
    u8 pad70[0x104 - 0x70];
    f32 x104, x108, x10c; /* 0x104 */
    u8 pad110[0x164 - 0x110];
    f32 x164;         /* 0x164 */
} Ent_800D1A34;
typedef struct {
    u8 pad0[0x54];
    f32 x54, x58, x5c; /* 0x54 */
    u32 x60, x64, x68; /* 0x60 */
    u8 pad6C[0xCC0 - 0x6C];
} Snap;
extern Snap lbl_8030A794;
extern s32 lbl_803473EC;
extern s32 lbl_80347408;
extern void fn_8016B96C(f32 x);
extern void fn_8016C7F0(s32 x);
extern void fn_8016C7D8(s32 x);
extern void fn_8016C780(s32 a, s32 b);
extern s32 fn_8015E600(void* e);
extern void fn_80118368(void* e);
extern void fn_800D1174(Ent_800D1174* e);
typedef struct {
    s16 len;          /* 0x00 */
    s16 id;           /* 0x02 */
    s32 args[1];      /* 0x04 */
} Rec_800D5210;
typedef struct {
    u32 count;        /* 0x00 */
    u8 pad4[0x24 - 4];
    Rec_800D5210 first;        /* 0x24 */
} Blob_800D5210;
typedef struct {
    u8 pad0[0x10];
    Blob_800D5210* blob;       /* 0x10 */
} Ext_800D5210;
typedef struct {
    u8 pad0[0x1C8];
    Ext_800D5210* ext;         /* 0x1C8 */
} Ent_800D5210;
typedef struct Handler Handler;
struct Handler {
    s16 id;
    s16 arg;
    s32 (*func)(Task* task, Ent_800D5210* e, s32* args, s32 len);
};
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
    u8 pad0[0x20];
    f32 c0, c1, c2;
    s32 mode;
    s32 size;
} Dst6138;
typedef struct {
    s16 n;          /* 0x00 */
    s16 pad2[3];
    f32 timer;      /* 0x08 */
    s16 en[3];      /* 0x0C */
    s16 pad12;
    f32 f14[3][2];  /* 0x14 */
    f32 f2c[3][2];  /* 0x2C */
} Obj7D60;
typedef struct {
    u32 flags;
    u8 pad4[0x78 - 4];
    u8 col[4];
} Obj;
typedef struct {
    u8 pad0[0x50];
    u32 x50, x54, x58, x5c;
    u8 pad60[4];
    u32 x64;
    u8 pad68[0xa0 - 0x68];
    u32 xa0;
    u8 pad_a4[0x140 - 0xa4];
    u32 x140;
} Cfg;
typedef struct {
    u8 pad[0x10];
    Cfg *cfg;
} Link;
typedef struct {
    u8 pad0[0x20];
    f32 x20, x24, x28;
    u8 pad2c[0x100 - 0x2c];
    u32 x100;
    u8 pad104[0x176 - 0x104];
    s16 x176;
    u8 pad178[0x1c8 - 0x178];
    Link *link;
} A;
typedef struct {
    u32 flags;
    u8 pad4[0x7a - 4];
    s16 x7a;
    s32 x7c;
    s32 x80;
    u8 pad84;
    u8 x85, x86, x87;
    u8 pad88[0x8c - 0x88];
    u32 x8c;
    u8 x90[0xf9 - 0x90];
    u8 xf9;
} B;
extern void fn_8009E910(void *dst, u32 a, u8 *p);
extern f32 fn_8009E4F8(u8 v);
typedef struct {
    u8 pad[0x74];
    f32 x74;
} Cfg_800BB3DC;
typedef struct {
    u8 pad[0x10];
    Cfg_800BB3DC *cfg;
} Link_800BB3DC;
typedef struct {
    u8 pad0[0x2c];
    u32 x2c;
    u8 pad30[0x50 - 0x30];
    V3 v50;
    u8 pad5c[0xe4 - 0x5c];
    void *xe4;
    u8 padE8[0x11c - 0xe8];
    V3 v11c;
    u8 pad128[0x176 - 0x128];
    s16 x176;
    u8 pad178[0x18c - 0x178];
    f32 x18c, x190;
    u8 pad194[4];
    s32 x198;
    u8 pad19c[0x1c8 - 0x19c];
    Link_800BB3DC *link;
    u8 pad1cc[0x1fc - 0x1cc];
    s16 x1fc;
    u8 pad1fe[0x208 - 0x1fe];
    s16 x208, x20a;
    V3 v20c;
    u8 pad218[0x21d - 0x218];
    u8 x21d;
    u8 pad21e[0x24c - 0x21e];
    V3 v24c;
    u8 pad258[0x25c - 0x258];
    void *x25c;
} W_800BB3DC;
typedef struct {
    u32 flags;
    s32 x4;
    s32 x8;
    s32 xc;
    s32 x10;
    s32 x14;
    u8 pad18[0x28 - 0x18];
    V3 a;
    V3 b;
    u8 pad40[0x64 - 0x40];
    s32 x64, x68, x6c;
    u8 pad70[0xb4 - 0x70];
    u32 xb4;
    u8 padb8[0xfe - 0xb8];
    s16 xfe;
} N;
typedef struct {
    u8 pad0[0x24];
    W_800BB3DC *work;
} Obj_800BB3DC;
typedef struct {
    u8 pad0[0x48];
    u32 x48;
} Cfg_800BBD4C;
typedef struct {
    u32 count;
    u8 pad4[0x48 - 4];
    u32 x48;
} CfgFull;
typedef struct {
    u8 pad[0x10];
    CfgFull *cfg;
} Link_800BBD4C;
typedef struct {
    u8 pad0[0x1a0];
    u32 x1a0;
    u8 pad1a4[0x260 - 0x1a4];
    void *x260;
    u8 pad264[0x31c - 0x264];
    void *x31c;
} Hook;
typedef struct {
    u8 pad0[0x18];
    u32 x18;
    u8 pad1c[0x100 - 0x1c];
    void *x100;
    u8 pad104[0x1c8 - 0x104];
    Link_800BBD4C *link;
    u8 pad1cc[0x1d8 - 0x1cc];
    Hook *hook;
    u8 pad1dc[0x1fa - 0x1dc];
    u8 x1fa, x1fb;
    u8 pad1fc[0x268 - 0x1fc];
    void *x268;
    u8 x26c;
} W_800BBD4C;
typedef struct {
    u8 pad0[0x19];
    u8 state;
    u8 x1a;
    u8 x1b;
    u8 pad1c[0x24 - 0x1c];
    W_800BBD4C *work;
} Obj_800BBD4C;
typedef struct {
    u32 count;
} Cnt;
typedef struct {
    u8 pad[0x10];
    Cnt *cnt;
} Link_800BBEAC;
typedef struct {
    u8 pad0[8];
    u32 x8;
} Hdr;
typedef struct {
    Hdr *hdr;
} Hk;
typedef struct Node_800BBEAC {
    u8 pad0[0x34];
    struct Node_800BBEAC *next;
} Node_800BBEAC;
typedef struct {
    u8 pad0[0x100];
    Hk *x100;
    u8 pad104[0x1c8 - 0x104];
    Link_800BBEAC *link;
    u8 pad1cc[0x25c - 0x1cc];
    void *x25c;
    Node_800BBEAC *x260;
    s32 x264;
    void *x268;
} W_800BBEAC;
typedef struct {
    u8 pad0[0x18];
    u8 flags;
    u8 state;
    u8 pad1a[0x24 - 0x1a];
    W_800BBEAC *work;
} Obj_800BBEAC;
typedef struct Sub_800C5530 {
    u8 pad0[0x24];
    u16 h24;
} Sub_800C5530;
typedef struct Info {
    u8 pad0[4];
    s32 id;
    u8 pad8[0xc];
} Info;
extern f32 lbl_80346D88;
extern u16 lbl_802E0F00[];
extern s32 fn_8015F1F0(struct MapObj* p);
typedef struct Key {
    u8 pad0;
    u8 r;
    u8 g;
    u8 b;
    s32 frames;
} Key;
typedef struct KeyTable {
    u8 pad0[4];
    s16 count;
    u8 pad6[2];
    Key keys[1];
} KeyTable;
typedef struct Obj_800C5C14 {
    u8 pad0[0x20];
    f32 f20;
    f32 f24;
    f32 f28;
    u8 pad2c[0x1d4];
    s16 h200;
    s16 h202;
    u8 pad204[0x4c];
    f32 f250;
    f32 f254;
    f32 f258;
    u8 pad25c[8];
    KeyTable* tbl;
} Obj_800C5C14;
extern void* lbl_80346D50[2];
extern s32 lbl_80346D58;
extern void* lbl_803056E8[6][7];
extern s32 fn_801CC1A4(void* p);
extern void* fn_80109D74(void* p);
extern void* fn_801CC0A0(void* p);
typedef struct Vec3_800CB1D0 {
    f32 x;
    f32 y;
    f32 z;
} Vec3_800CB1D0;
typedef struct Obj_800CB1D0 {
    u8 pad0[0x38];
    f32 f38;
    f32 f3c;
    f32 f40;
    s32 w44;
    s32 w48;
    u8 pad4c[0x10];
    f32 f5c;
    f32 f60;
    f32 f64;
    u8 pad68[0x58];
    s32 wc0;
    s32 wc4;
    u8 padc8[0x1c];
    void* pe4;
    u8 padec[0x1c];
    f32 f104;
    f32 f108;
    f32 f10c;
    u8 pad110[0xa8];
    void* p1b8;
    u8 pad1bc[0x40];
    s16 h1fc;
    u8 pad1fe[0x3e];
    void* p23c;
    u8 pad240[0xc];
    f32 f24c;
    u8 pad250[0xc];
    void* p25c;
    void* p260;
} Obj_800CB1D0;
typedef struct Ent {
    u32 a;
    u32 b;
    u32 c;
    u32 d;
} Ent;
typedef struct Tbl {
    Ent* list;
    u8 pad4[6];
    s16 count;
    s16 base;
    s16 out;
} Tbl;
typedef struct Cfg_800CDEF4 {
    s32 w0;
    s32 w4;
    u8 pad8[0x24 - 8];
    s32 w24;
} Cfg_800CDEF4;
typedef struct MapLst { s32 count; void* w4; void* w8; } MapLst;
typedef struct MapSub {
    u8 pad_00[0x10];
    Cfg_800CDEF4* p10;  /* 0x10 */
    u8 pad14[0x1c - 0x14];
    MapLst *p1c;        /* 0x1c */
} MapSub;
typedef struct Holder_800CDEF4 {
    u8 pad0[0x18];
    u8 flags;
    u8 pad19[0xb];
    MapObj* p24;
} Holder_800CDEF4;
typedef struct Task_800CDEF4 {
    u8 pad0[8];
    Holder_800CDEF4* p8;
    u8 pad_c[0xc];
    u8 flags18;
    u8 state;
    u8 pad1a[0xa];
    MapObj* p24;
} Task_800CDEF4;
typedef struct Row {
    f32 f0;
    u32 w4;
    u8 pad8[8];
    u32 w10;
    u8 pad14[0xc];
} Row;
typedef struct A_800CE4E8 {
    u8 pad0[4];
    f32 f4;
} A_800CE4E8;
typedef struct B_800CE4E8 {
    u8 pad0[0x24];
    u16 h24;
} B_800CE4E8;
extern Row lbl_802E1154[];
typedef struct Pos {
    f32 x;
    u8 pad4[4];
    f32 z;
} Pos;
typedef struct Q {
    u8 pad0[4];
    f32 f4;
} Q;
typedef struct Mover {
    u8 pad0[0x5c];
    f32 f5c;
    u8 pad60[4];
    f32 f64;
} Mover;
typedef struct Flags {
    u8 pad0[0x24];
    u16 h24;
} Flags;
extern f32 lbl_80346D90;
extern s32 fn_800CEDDC(Q* q, Mover* m, Flags* f);
extern s32 fn_800CE67C(Q* q, Mover* m, Flags* f);
typedef struct Part_800D29B4 {
    u8 pad0[0x34];
    s32 w34;
} Part_800D29B4;
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
typedef struct { u8 pad[8]; u32 flags; } Pad;
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
typedef struct Lim_800BA04C {
    u32 w0;
    u32 w4;
} Lim_800BA04C;
typedef struct W_800BA04C {
    u8 pad0[0x50];
    f32 x50, y50, z50;
    u8 pad5c[0xe8 - 0x5c];
    Lim_800BA04C *lim;      /* 0xe8 */
    u8 padec[0x11c - 0xec];
    f32 x11c, y11c, z11c;
    u8 pad128[0x18c - 0x128];
    f32 cur;                /* 0x18c */
    f32 vel;                /* 0x190 */
    u8 pad194[0x1fc - 0x194];
    s16 h1fc;
    u8 pad1fe[0x21d - 0x1fe];
    u8 mode;                /* 0x21d */
} W_800BA04C;
typedef struct S_800BA04C {
    u32 flags;
    u8 pad4[0xc - 4];
    s32 wc;
    s32 w10;
    s32 w14;
    u8 pad18[0xfa - 0x18];
    s16 hfa;
} S_800BA04C;
typedef struct V3_800BA220 {
    f32 x, y, z;
} V3_800BA220;
typedef struct Node_800BA220 {
    V3_800BA220 a;          /* 0x00 */
    V3_800BA220 b;          /* 0x0c */
    V3_800BA220 c;          /* 0x18 */
    f32 f24;
    f32 f28;
    s16 h2c;
    s16 h2e;
    f32 f30;
    struct Node_800BA220 *next; /* 0x34 */
} Node_800BA220;
typedef struct Hdr_800BA220 {
    u8 pad0[4];
    s32 w4;
} Hdr_800BA220;
typedef struct W_800BA220 {
    u8 pad0[0x1c];
    f32 f1c;
    u8 pad20[0x2c - 0x20];
    s32 w2c;
    u8 pad30[0x38 - 0x30];
    V3_800BA220 a;          /* 0x38 */
    V3_800BA220 b;          /* 0x44 */
    V3_800BA220 c;          /* 0x50 */
    u8 pad5c[0x100 - 0x5c];
    Hdr_800BA220 *hdr;      /* 0x100 */
    u8 pad104[0x18c - 0x104];
    f32 f18c;
    u8 pad190[0x260 - 0x190];
    Node_800BA220 *list;    /* 0x260 */
} W_800BA220;
typedef struct X_800BA220 {
    u8 pad0[0x110];
    s16 h110;
    u8 pad112[0x118 - 0x112];
    s32 w118;
    f32 f11c;
} X_800BA220;
extern void fn_8009D994(W_800BA220 *w, s32 id, s32 q);
typedef struct V3_800BBA70 {
    f32 x, y, z;
} V3_800BBA70;
typedef struct Hook_800BBA70 {
    u8 pad0[0x1a0];
    s32 w1a0;
} Hook_800BBA70;
typedef struct Buf_800BBA70 {
    u32 flags;
    u8 pad4[0x40 - 4];
    V3_800BBA70 a40;
    V3_800BBA70 a4c;
} Buf_800BBA70;
typedef struct W_800BBA70 {
    u8 pad0[0x38];
    V3_800BBA70 a;          /* 0x38 */
    V3_800BBA70 b;          /* 0x44 */
    V3_800BBA70 c;          /* 0x50 */
    u8 pad5c[0x11c - 0x5c];
    V3_800BBA70 d;          /* 0x11c */
    u8 pad128[0x1d8 - 0x128];
    Hook_800BBA70 *hook;    /* 0x1d8 */
    u8 pad1dc[0x1fa - 0x1dc];
    s8 b1fa;
    u8 pad1fb[0x268 - 0x1fb];
    Buf_800BBA70 *buf;      /* 0x268 */
} W_800BBA70;
typedef struct Obj_800BBA70 {
    u8 pad0[0x19];
    u8 state;
} Obj_800BBA70;
typedef struct Spr_800C2650 {
    u8 pad0[0x14];
    f32 f14;
    f32 f18;
} Spr_800C2650;
typedef struct Arg_800C2650 {
    f32 f0;
    s16 h4;
    s16 h6;
    f32 f8;
    f32 fc;
} Arg_800C2650;
typedef struct V3_800C381C {
    f32 x, y, z;
} V3_800C381C;
typedef struct A3_800C381C {
    s32 x, y, z;
} A3_800C381C;
typedef struct Sub_800C381C {
    u8 pad0[0x14];
    s16 h14;
} Sub_800C381C;
typedef struct Src_800C381C {
    u8 pad0[2];
    s16 flags;
    u8 pad4[0x5c - 4];
    f32 f5c;
} Src_800C381C;
typedef struct Obj_800C381C {
    u8 pad0[2];
    s16 flags;
    u8 pad4[0xc - 4];
    V3_800C381C pos;        /* 0x0c */
    u8 pad18[0x30 - 0x18];
    f32 f30, f34, f38;
    u8 pad3c[0x40 - 0x3c];
    s32 w40, w44, w48;
    V3_800C381C v4c;        /* 0x4c */
    V3_800C381C v58;        /* 0x58 */
    V3_800C381C v64;        /* 0x64 */
    s32 w70, w74, w78;
    u8 pad7c[0xcc - 0x7c];
    f32 fcc, fd0, fd4;
    u8 padd8[0xf0 - 0xd8];
    V3_800C381C vf0;        /* 0xf0 */
    u8 padfc[0x108 - 0xfc];
    Sub_800C381C *sub;      /* 0x108 */
    s32 w10c;
} Obj_800C381C;
typedef struct V3_800C41D0 {
    f32 x, y, z;
} V3_800C41D0;
typedef struct Sub_800C41D0 {
    u8 pad0[0x14];
    s16 h14;
} Sub_800C41D0;
typedef struct Src_800C41D0 {
    u8 pad0[2];
    s16 flags;
    u8 pad4[0x4c - 4];
    f32 f4c, f50, f54;
} Src_800C41D0;
typedef struct Obj_800C41D0 {
    u8 pad0[2];
    s16 flags;
    u8 pad4[0xc - 4];
    V3_800C41D0 pos;        /* 0x0c */
    u8 pad18[0x24 - 0x18];
    V3_800C41D0 v24;        /* 0x24 */
    V3_800C41D0 v30;        /* 0x30 */
    u8 pad3c[0x40 - 0x3c];
    s32 w40, w44, w48;
    V3_800C41D0 v4c;        /* 0x4c */
    u8 pad58[0x70 - 0x58];
    s32 w70, w74, w78;
    u8 pad7c[0xac - 0x7c];
    V3_800C41D0 vac;        /* 0xac */
    f32 fb8, fbc;
    u8 padc0[0xcc - 0xc0];
    f32 fcc;
    u8 padd0[0xd8 - 0xd0];
    s32 wd8;
    u8 padd8[0x108 - 0xdc];
    Sub_800C41D0 *sub;      /* 0x108 */
} Obj_800C41D0;
typedef struct V3_800C43A0 {
    f32 x, y, z;
} V3_800C43A0;
typedef struct Mot_800C43A0 {
    u8 pad0[4];
    u32 count;
} Mot_800C43A0;
typedef struct Obj_800C43A0 {
    u8 pad0[0xc];
    V3_800C43A0 pos;        /* 0x0c */
    u8 pad18[0x24 - 0x18];
    V3_800C43A0 v24;        /* 0x24 */
    V3_800C43A0 v30;        /* 0x30 */
    u8 pad3c[0x58 - 0x3c];
    V3_800C43A0 v58;        /* 0x58 */
    V3_800C43A0 v64;        /* 0x64 */
    s32 w70;
    s32 w74;
    s32 w78;
    V3_800C43A0 v7c;        /* 0x7c */
    s32 w88, w8c;
    u8 pad90[0xd8 - 0x90];
    s32 wd8;
    u8 padd8[0x110 - 0xdc];
    Mot_800C43A0 *mA;       /* 0x110 */
    f32 frameA;
    f32 speedA;
    Mot_800C43A0 *mB;       /* 0x11c */
    f32 frameB;
    f32 speedB;
} Obj_800C43A0;
typedef struct V3_800C4584 {
    f32 x, y, z;
} V3_800C4584;
typedef struct Tbl_800C4584 {
    s32 count;
    void *items[1];
} Tbl_800C4584;
typedef struct R_800C4584 {
    u8 pad0[0x1c];
    Tbl_800C4584 *tbl;      /* 0x1c */
    u8 pad20[0x44 - 0x20];
    V3_800C4584 v44;
    u8 pad50[0x54 - 0x50];
    f32 f54;
} R_800C4584;
typedef struct Sub_800C4584 {
    u8 pad0[0x14];
    s16 h14;
} Sub_800C4584;
typedef struct Src_800C4584 {
    u8 pad0[2];
    s16 flags;
    u8 pad4[0x58 - 4];
    u16 u58;
    u8 pad5a[0x60 - 0x5a];
    u16 u60;
    s16 h62;
    f32 f64;
    u16 u68;
    s16 h6a;
    f32 f6c;
} Src_800C4584;
typedef struct Obj_800C4584 {
    u8 pad0[4];
    s16 h4;
    u8 pad6[0xc - 6];
    V3_800C4584 pos;        /* 0x0c */
    u8 pad18[0x30 - 0x18];
    V3_800C4584 v30;        /* 0x30 */
    u8 pad3c[0x40 - 0x3c];
    s32 w40, w44, w48;
    V3_800C4584 v4c;        /* 0x4c */
    V3_800C4584 v58;        /* 0x58 */
    V3_800C4584 v64;        /* 0x64 */
    s32 w70, w74, w78;
    u8 pad7c[0xd8 - 0x7c];
    s32 wd8;
    u8 padd8[0x108 - 0xdc];
    Sub_800C4584 *sub;      /* 0x108 */
    u8 pad10c[0x110 - 0x10c];
    void *mA;               /* 0x110 */
    f32 frameA;
    f32 speedA;
    void *mB;               /* 0x11c */
    f32 frameB;
    f32 speedB;
} Obj_800C4584;
extern R_800C4584 *fn_801092C0(u16 id, s32 a);
typedef struct V3_800C48C4 {
    f32 x, y, z;
} V3_800C48C4;
typedef struct A3_800C48C4 {
    s32 x, y, z;
} A3_800C48C4;
typedef struct Sub_800C48C4 {
    u8 pad0[0x14];
    s16 h14;
} Sub_800C48C4;
typedef struct Src_800C48C4 {
    u8 pad0[2];
    s16 flags;
    u8 pad4[0x4c - 4];
    f32 f4c, f50, f54;
    u16 u58;
} Src_800C48C4;
typedef struct Obj_800C48C4 {
    u8 pad0[2];
    s16 flags;
    u8 pad4[0xc - 4];
    V3_800C48C4 pos;        /* 0x0c */
    u8 pad18[0x24 - 0x18];
    V3_800C48C4 v24;        /* 0x24 */
    V3_800C48C4 v30;        /* 0x30 */
    u8 pad3c[0x40 - 0x3c];
    s32 w40, w44, w48;
    V3_800C48C4 v4c;        /* 0x4c */
    u8 pad58[0x64 - 0x58];
    V3_800C48C4 v64;        /* 0x64 */
    s32 w70, w74, w78;
    u8 pad7c[0xac - 0x7c];
    V3_800C48C4 vac;        /* 0xac */
    f32 fb8, fbc;
    u8 padc0[0xcc - 0xc0];
    f32 fcc;
    f32 fd0;
    f32 fd4;
    s32 wd8;
    u8 paddc[0x108 - 0xdc];
    Sub_800C48C4 *sub;      /* 0x108 */
} Obj_800C48C4;
typedef struct V3_800CAF6C {
    f32 x, y, z;
} V3_800CAF6C;
typedef struct Obj_800CAF6C {
    u8 pad0[0x38];
    f32 f38, f3c, f40;
    s32 w44, w48;
    u8 pad4c[0x5c - 0x4c];
    f32 f5c, f60, f64;
    u8 pad68[0xc0 - 0x68];
    s32 wc0, wc4;
    u8 padc8[0x104 - 0xc8];
    f32 f104, f108, f10c;
    s32 w110;
    u8 pad114[0x158 - 0x114];
    f32 f158, f15c, f160;
    u8 pad164[0x1b8 - 0x164];
    void *p1b8;
    u8 pad1bc[0x24c - 0x1bc];
    f32 f24c;
} Obj_800CAF6C;
typedef struct Ref_800CD56C {
    u8 pad0[0x18];
    u8 flags18;
} Ref_800CD56C;
typedef struct Tbl_800CD56C {
    u8 pad0[0x18];
    s16 h18;
} Tbl_800CD56C;
typedef struct W_800CD56C {
    u8 pad0[0x1c];
    f32 f1c;
    u8 pad20[0x38 - 0x20];
    f32 f38, f3c, f40;
    u8 pad44[0x4c - 0x44];
    s32 w4c;
    f32 f50, f54, f58, f5c, f60, f64;
    u8 pad68[0x70 - 0x68];
    s32 w70;
    u8 pad74[0x11c - 0x74];
    f32 f11c, f120, f124;
    u8 pad128[0x15c - 0x128];
    f32 f15c;
    u8 pad160[0x180 - 0x160];
    s32 w180;
    u8 pad184[0x1ac - 0x184];
    Tbl_800CD56C *p1ac;
    s16 *p1b0;
} W_800CD56C;
typedef struct Obj_800CD56C {
    u8 pad0[8];
    Ref_800CD56C *ref;
    u8 pad0c[0x18 - 0xc];
    u8 flags18;
    u8 state;
    u8 pad1a[0x24 - 0x1a];
    W_800CD56C *w;
} Obj_800CD56C;
typedef struct {
    u32* p0;
} Cnt_800CE064;
typedef struct {
    u8 pad0[0x10];
    u32* c10;
    u32* c14;
    u8 pad18[4];
    u32* c1c;
} Lim_800CE064;
typedef struct {
    u8 pad0[0x10];
    struct { u8 pad[0x28]; s32 v28; }* p10;
    u8 pad14[0x1C - 0x14];
    u32 p1c;
} Lim2_800CE064;
typedef struct {
    u8 pad0[0x24];
    struct Child_800CE064* c24;
} Hd_800CE064;
typedef struct Child_800CE064 {
    u8 pad0[0x38];
    f32 pos[3];
    u8 pad44[0x200 - 0x44];
    s16 s200;
} Child_800CE064;
typedef struct {
    u8 pad0[0x24];
    Child_800CE064* c24;
} Ent_800CE064;
typedef struct {
    u8 pad0[0x38];
    f32 pos[3];
    u8 pad44[0x178 - 0x44];
    u16 u178;
    u8 pad17a[0x180 - 0x17A];
    s32 s180;
    u8 pad184[0x1C8 - 0x184];
    Lim_800CE064* p1c8;
    u8 pad1cc[0x1FC - 0x1CC];
    s16 s1fc;
    s16 s1fe;
    u8 pad200[0x206 - 0x200];
    s16 s206;
} Work_800CE064;
typedef struct {
    u8 pad0[0x19];
    u8 state;
    u8 pad1a[0x24 - 0x1A];
    Work_800CE064* work;
} Obj_800CE064;
typedef struct {
    u8 pad0[0x44];
    s32 rot[3];
    u8 pad50[0x6C - 0x50];
    s32 s6c;
    u8 pad70[0x164 - 0x70];
    f32 f164;
} Obj_800CFBF4;
typedef struct {
    u8 pad0[8];
    f32 f8;
    f32 fc;
    f32 f10;
    f32 f14;
} Inp_800CFBF4;
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
    u32 count;
    u8 pad4[0x20 - 4];
    s32 v20;
    s32 v24;
    s32 v28;
    s32 v2c;
} Tbl_800D5584;
typedef struct {
    u8 pad0[0x10];
    Tbl_800D5584* c10;
    u8 pad14[0x20 - 0x14];
    s32 v20;
} Src_800D5584;
typedef struct {
    u32 w0;
    u8 pad4[0x14 - 4];
    u32 w14;
    u8 pad18[2];
    s16 s1a;
    s16 s1c;
    s16 s1e;
} Hnd_800D5584;
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
    u8 pad0[0xE4];
    s32 e4;
    u8 pade8[0x100 - 0xE8];
    s32 p100;
    u8 pad104[0x1AC - 0x104];
    Hnd_800D5584* h1ac;
    void* h1b0;
    u8 pad1b4[0x1C8 - 0x1B4];
    Src_800D5584* p1c8;
    u8 pad1cc[0x1FC - 0x1CC];
    s16 s1fc;
    s16 s1fe;
    s16 s200;
    s16 s202;
    u8 pad204[0x25C - 0x204];
    s16* p25c;
    s32* p260;
} Work_800D5584;
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
typedef struct {
    s32 v0;
    u8 pad4[0x1C - 4];
    s32 v1c;
} Sub_800D6E1C;
typedef struct {
    u8 pad0[8];
    u32 kind;
    Sub_800D6E1C* sub;
} Ent_800D6E1C;
typedef struct {
    u8 pad0[4];
    s32 v4;
} Lim_800D6E1C;
typedef struct {
    u8 pad0[0x188];
    u32 flags188;
    u8 pad18c[0x1C8 - 0x18C];
    Lim_800D6E1C* p1c8;
    u8 pad1cc[0x1EC - 0x1CC];
    u8 b1ec;
    u8 b1ed;
    s8 s1ee;
    u8 b1ef;
} Obj_800D6E1C;
extern Ent_800D6E1C* fn_800CCA6C(s32 a, s32 b);
extern void fn_800D6C04(void* o);
extern void fn_800D6974(void* o);
typedef struct Ent_800C7F64 {
    char *name;
    s32 idx;
} Ent_800C7F64;
typedef struct Arg_800C7F64 {
    s32 a;
    s32 b;
    s32 c;
} Arg_800C7F64;
extern s32 lbl_80347464;
extern char *lbl_8034746C;
extern s32 lbl_803475B0;
extern s32 lbl_803474B0[2];
extern char lbl_802B1410[0xB];
extern char lbl_802B141C[0xE];
extern char lbl_803491AC[5];
extern f32 lbl_8030A77C[6];
extern char lbl_80305790[0x2CC];
extern Ent_800C7F64 lbl_802E0F40[28];
extern int sprintf(char *buf, const char *fmt, ...);
extern int strncmp(const char *a, const char *b, u32 n);
extern void *fn_80109E7C(char *name, s32 a);
extern void *fn_801CC2A0(char *name, void *cb, s32 a);
extern s8 fn_800C8C54(f32 *p, Arg_800C7F64 *a);
typedef struct P_800C7058 {
    u8 pad0[0x38];
    f32 f38;
    u8 pad3c[4];
    f32 f40;
    u8 pad44[0x104 - 0x44];
    f32 f104;
    u8 pad108[4];
    f32 f10c;
} P_800C7058;
typedef struct W_800C7058 {
    u8 pad0[0x2c];
    s32 w2c;
    u8 pad30[0x38 - 0x30];
    f32 f38;
    u8 pad3c[4];
    f32 f40;
    u8 pad44[4];
    s32 w48;
    u8 pad4c[0xe4 - 0x4c];
    void *pe4;
    u8 pade8[0x100 - 0xe8];
    void *p100;
    u8 pad104[0x176 - 0x104];
    s16 h176;
    u8 pad178[0x24c - 0x178];
    f32 f24c;
    f32 f250;
} W_800C7058;
typedef struct Obj_800C7058 {
    u8 pad0[0x19];
    u8 state;
    u8 pad1a[0x24 - 0x1a];
    W_800C7058 *w;
} Obj_800C7058;
extern f32 lbl_80347560;
extern void ClipZPush(void);
extern void ClipZPop(void);
extern void njClipZ(f32 near, f32 far);
extern f32 fn_80291888(f32 x);
typedef struct {
    u8 pad0[0x10];
    void* tbl[4];
    u8 pad20[0x20 - 0x20];
} Ent_800CE2B4;
typedef struct {
    u8 pad0[0x38];
    f32 pos[3];
    u8 pad44[4];
    s32 v48;
} Cam_800CE2B4;
typedef struct {
    u8 pad0[4];
    s32 id;
    s8 ch;
    u8 pad9[0x14 - 9];
} Key_800CE2B4;
extern u8 lbl_8030B7F4[0x16A0];
extern s32 fn_8021A1C4(void* buf);
extern s32 fn_8021ADA0(void* a, void* b);
extern void fn_80100178(void* p);
extern void fn_801F7B04(s32 v);
extern void fn_800EB58C(s32 v);
typedef struct {
    u8 pad0[0x19];
    u8 state;
    u8 pad1a[0x20 - 0x1A];
    f32 f20;
    MapObj* work;
} MapTask;
extern MapTask* lbl_80347454;
extern s32 lbl_803473A8;
extern u32 lbl_80310B3C[0x356];
extern void fn_800D1B5C(void* o);
extern void fn_8016B9B0(s32 a);
extern void fn_8016B998(s32 a);
extern void fn_8016C870(s32 a);
extern void fn_8016C808(s32 a);
extern void fn_8016B950(f32 a, f32 b);
extern void fn_8016C7AC(s32 a, s32 b);
extern void fn_800D1630(void);
extern void fn_80217830(void* p);
extern void fn_8015EBF4(void* w);
extern void fn_8016ABEC(void);
extern void fn_80097660(void);
typedef struct Pos_800C2D18 {
    f32 x;
    s16 u;
    s16 v;
    f32 a;
    f32 b;
} Pos_800C2D18;
extern void fn_800FF348(Sprite* s, s32 a, f32 x, f32 y, f32 z);
extern void fn_801D4C54(Sprite* s, s32 a, s32 b, s32 c, f32 f1, f32 f2, f32 f3, f32 f4);
extern void fn_801D525C(Sprite* s, s32 a, s32 b, f32 f1, f32 f2, f32 f3, f32 f4);
typedef struct {
    u8 pad0[0x18];
    s16 count;
} Cnt_800CD72C;
typedef struct {
    u8 pad0[0x38];
    f32 pos[3];
    s32 rot[3];
    u8 pad50[0x100 - 0x50];
    s32 p100;
    u8 pad104[0x184 - 0x104];
    s32 flag184;
} Src_800CD72C;
typedef struct {
    u8 pad0[0x38];
    f32 pos[3];
    s32 rot[3];
    u8 pad50[0xE4 - 0x50];
    s32 e4;
    u8 pade8[0x100 - 0xE8];
    s32 p100;
    u8 pad104[0x16E - 0x104];
    s16 s16e;
    u8 pad170[0x1AC - 0x170];
    Cnt_800CD72C* cnt;
    s16* cur;
    u8 pad1b4[0x202 - 0x1B4];
    s16 s202;
} Work_800CD72C;
typedef struct {
    u8 pad0[0x18];
    u8 flags;
    u8 pad19[0x24 - 0x19];
    Src_800CD72C* src;
} Par_800CD72C;
typedef struct {
    u8 pad0[8];
    Par_800CD72C* par;
    u8 pad0c[0x19 - 0xC];
    u8 state;
    u8 pad1a[0x24 - 0x1A];
    Work_800CD72C* work;
} Obj_800CD72C;
extern void* fn_801DDAB0(void* a, s32 b, s32 c, s32 d, s16* e);
/* Motion callback (registered with fn_8015EB8C id 0xd): copies src+0xC0 into ctx->dst+0xC0.
 * Declared s32 like its sibling callbacks (fn_8010A530) but the original has no return
 * statement: r3 stays live as the result, so the dst pointer lands in r4. */
typedef struct CbObj {
    char pad0[0x24];
    struct CbObj* dst; /* 0x24 */
    char pad28[0xc0 - 0x28];
    int valC0;         /* 0xC0 */
} CbObj;
typedef struct { u8 pad[0x4c]; void *x4c; } B_800BE430;
typedef struct { u8 pad[0x10]; B_800BE430 *x10; } A_800BE430;
typedef struct { u8 pad[0xe4]; void *xe4; u8 pad2[0x1c8 - 0xe8]; A_800BE430 *x1c8; } Obj_800BE430;
typedef struct {
    u8 pad[0x1BC];
    void *unk1BC;
} Unk80347450;
extern s32 fn_80222B30(HitNode *a, HitNode *b);
extern void GXSetFog(s32 type, f32 startz, f32 endz, f32 nearz, f32 farz, GXColor color);
extern void fn_80296F28(void);
typedef struct Obj_800BF7AC {
    u8 pad0[0x25C];
    void *f25C;
    void *f260;
} Obj_800BF7AC;
typedef struct Entry_800CCC48 {
    u32 a;
    u32 b;
    u32 c;
    u32 d;
} Entry_800CCC48;
typedef struct Table_800CCC48 {
    Entry_800CCC48 *entries;
    u32 unk4;
    s16 max;
    s16 count;
    s16 unkC;
    s16 unkE;
} Table_800CCC48;
typedef struct { u8 pad[0x20]; void *p20; } S800C32D8b;
typedef struct { u8 pad[0x4]; S800C32D8b *p4; } S800C32D8a;
typedef struct Mgr_800C8EC0 {
    u8 pad0[0x24];
    void **tab;
} Mgr_800C8EC0;
s32 fn_8010038C(void *p);
typedef struct {
    u32 a;
    u32 b;
    u32 key;
    u8 pad1[4];
} Entry_800CC9EC;
typedef struct Tbl_800CD16C {
    Ent *list;      /* 0x00 */
    Ent *pending;   /* 0x04 */
    s16 cap;        /* 0x08 */
    s16 count;      /* 0x0A */
    s16 npending;   /* 0x0C */
    s16 out;        /* 0x0E */
} Tbl_800CD16C;
typedef struct Node_800B4184 {
    u32 flags;
    u8 pad4[0x44 - 4];
    f32 f44;
    u8 pad48[0x58 - 0x48];
    s32 w58;
    u8 pad5c[0x60 - 0x5c];
    f32 f60;
    u8 pad64[0x74 - 0x64];
    struct Node_800B4184* p74;
    u8 pad78[0x7c - 0x78];
    struct Node_800B4184* p7c;
} Node_800B4184;
typedef struct Emit_800B4184 {
    u32 flags;
    u8 pad4[0x44 - 4];
    f32 f44;
    u8 pad48[0x5c - 0x48];
    s16 s5c, s5e, s60, s62;
    u8 pad64[0x6b - 0x64];
    u8 b6b;
    s16 s6c;
    u8 pad6e;
    u8 b6f;
    u8 b70;
    u8 pad71[0x74 - 0x71];
    s16 s74;
    u8 pad76[0x110 - 0x76];
    Node_800B4184* p110;
} Emit_800B4184;
typedef struct Work_800B4184 {
    u8 pad0[0x1fc];
    s16 s1fc;
    u8 pad1fe[0x22e - 0x1fe];
    u16 h22e;
    u16 h230;
} Work_800B4184;
typedef struct V3_800BA564 { u32 x, y, z; } V3_800BA564;
typedef struct Buf_800BA564 {
    V3_800BA564 a, b, c;
    f32 f24, f28;
    s16 h2c, h2e;
    f32 f30;
    struct Buf_800BA564* next;
} Buf_800BA564;
typedef struct Hdr_800BA564 { u8 pad0[4]; s32 w4; } Hdr_800BA564;
typedef struct Work_800BA564 {
    u8 pad0[0x1c];
    f32 f1c;
    u8 pad20[0x38 - 0x20];
    V3_800BA564 a, b, c;
    u8 pad5c[0x68 - 0x5c];
    s32 w68;
    u8 pad6c[0x100 - 0x6c];
    Hdr_800BA564* hdr;
    u8 pad104[0x18c - 0x104];
    f32 f18c;
    u8 pad190[0x20c - 0x190];
    s32 w20c;
    u8 pad210[0x260 - 0x210];
    Buf_800BA564* list;
} Work_800BA564;
typedef struct Emit {
    u32 flags;
    s32 w4, w8, wc, w10, w14;
    u8 pad18[0x34 - 0x18];
    s32 w34;
    u8 pad38[0xf8 - 0x38];
    s8 mode;
    u8 padf9[0x110 - 0xf9];
    s16 h110, h112, h114, h116;
    u8 pad118[0x120 - 0x118];
    f32 f120;
} Emit;
extern void fn_800A1948(void* a, void* b, s32 flags);
extern void njRotateEx(void* ang, s32 order);
extern void fn_800A13D8(s32, void*);
extern void fn_800A1690(s32, void*);
extern s32 fn_800A10C4(s32 base, s32 i, s32 n);
extern void fn_801DBE1C(const char* fmt, ...);
typedef struct Src {
    u8 pad0[0x78];
    s32 w78, w7c, w80, w84;
    u8 pad88[0x8c - 0x88];
    s32 w8c, w90, w94, w98, w9c, wa0, wa4, wa8;
    u8 pad_ac[0xb0 - 0xac];
    f32 fb0, fb4, fb8;
    s32 wbc, wc0, wc4;
    f32 fc8, fcc, fd0, fd4, fd8, fdc;
} Src;
typedef struct Cfg_800BD668 {
    u8 pad0[0x10];
    Src* p10;
} Cfg_800BD668;
typedef struct Work_800BD668 {
    u8 pad0[0x1c8];
    Cfg_800BD668* cfg;
} Work_800BD668;
typedef struct Dst {
    u32 flags;
    u8 pad4[0xb8 - 4];
    f32 fb8, fbc, fc0;
    s16 hc4, hc6;
    s32 wc8, wcc, wd0;
    s16 hd4, hd6;
    f32 fd8, fdc, fe0;
    s16 he4, he6;
    f32 fe8, fec, ff0;
    s16 hf4, hf6;
    u8 padf8[0xfa - 0xf8];
    s16 hfa, hfc, hfe, h100, h102;
    f32 f104, f108;
} Dst;
typedef struct V3_800C6474 { f32 x, y, z; } V3_800C6474;
typedef struct Target { u8 pad0[0x38]; f32 x38, y38, z38; } Target;
typedef struct Work_800C6474 {
    u8 pad0[0x1b8];
    void* p1b8;
    u8 pad1bc[0x23c - 0x1bc];
    u32 w23c;
} Work_800C6474;
typedef struct Obj_800C6474 {
    u8 pad0[0x19];
    u8 state;
    u8 pad1a[0x24 - 0x1a];
    Work_800C6474* work;
} Obj_800C6474;
extern s32 fn_8015F218(Work_800C6474*);
extern s32 fn_800C63A4(void *);
extern s32 fn_802254A0(V3_800C6474* p, void* q);
typedef struct Cell { s32 a, b4, b; } Cell;
typedef struct Cmd { s32 w0; } Cmd;
typedef struct Work_800C7744 {
    u8 pad0[0x38];
    f32 f38, f3c, f40;
    u8 pad44[0x104 - 0x44];
    f32 f104, f108, f10c;
    u8 pad110[0x16a - 0x110];
    u8 b16a, b16b;
    u8 pad16c[0x260 - 0x16c];
    Cmd* p260;
} Work_800C7744;
typedef struct Obj_800C7744 {
    u8 pad0[0x19];
    u8 state;
    u8 pad1a[0x24 - 0x1a];
    Work_800C7744* work;
} Obj_800C7744;
typedef struct P114 { float r, base, range, a, b, c; } P114;
#define RND (3.0517578125e-05f * rand())
extern void fn_800CBE98(void);
extern void fn_800CBBBC(void);
extern void fn_800CB90C(void);
typedef struct E4F0Ent { s16 pad0; s16 base; s16 spread; } E4F0Ent;
typedef struct E4F0Tab { s16 pad; E4F0Ent ent[1]; } E4F0Tab;
typedef struct E4F0 {
    u8 pad0[0x180]; int timer;
    u8 pad184[0x1ed - 0x184]; s8 kind; s8 baseB; s8 spreadB;
    u8 pad1f0[0x1fc - 0x1f0]; s16 idx; s16 baseT; s16 spreadT; s16 count; s16 limit;
    u8 pad206[0x260 - 0x206]; void *tab;
} E4F0;
extern char lbl_802E10F0[];
typedef struct T770 { u16 pad0; u16 pad2; u16 base; u16 spread; } T770;
typedef struct E770 {
    u8 pad0[0x5c]; float f5c; u8 pad60[4]; float f64;
    u8 pad68[0x180 - 0x68]; int timer;
    u8 pad184[0x1ec - 0x184]; s8 a; s8 kind; s8 baseB; s8 spreadB;
    u8 pad1f0[0x1fc - 0x1f0]; s16 idx;
    u8 pad1fe[0x22c - 0x1fe]; u16 flags;
    u8 pad22e[0x260 - 0x22e]; T770 *tab;
} E770;
extern void fn_801DCF24(NJS_POINT3 *p, Angle *ang, s32 yaw, f32 scale);
extern void *fn_801DD984(void);
typedef struct E270 {
    u8 pad0[0x38]; NJS_POINT3 pos;
    u8 pad44[0x4c - 0x44]; int i4c;
    float f50, f54, f58;
    NJS_POINT3 vel;
    u8 pad68[0x70 - 0x68]; int i70;
    u8 pad74[0xcc - 0x74]; NJS_POINT3 dir;
    u8 padd8[0xe4 - 0xd8]; int e4;
    u8 pade8[0x100 - 0xe8]; int p100;
    u8 pad104[0x11c - 0x104]; float f11c, f120, f124;
    u8 pad128[0x15c - 0x128]; float f15c;
    u8 pad160[0x16e - 0x160]; s16 s16e;
    u8 pad170[0x180 - 0x170]; int timer;
    u8 pad184[0x1ac - 0x184]; void *p1ac; void *p1b0;
    u8 pad1b4[0x206 - 0x1b4]; s16 s206;
    u8 pad208[0x20c - 0x208]; int i20c;
    u8 pad210[0x24c - 0x210]; float f24c;
} E270;
typedef struct Hnd {
    u8 pad0[6]; u16 flags; u8 pad8[0x1c - 8];
    void *p1c; u8 pad20[4]; void *p24, *p28, *p2c; u8 pad30[0x48 - 0x30];
    u8 v48[0xc]; u8 v54[0xc]; u8 v60[0xc];
} Hnd;
typedef struct Scr { u8 pad[4]; s32 i4; } Scr;
typedef struct Ent_800D3C00 { f32 a; s32 b; f32 c; } Ent_800D3C00;
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
typedef struct Sub_800D3C00 { u8 pad0[0x4]; s32 w4; u8 pad8; } Sub_800D3C00;
extern Hnd *fn_80225B74(s32 mask, u16 id);
extern void fn_802233EC(Hnd *h);
extern void fn_802234D4(Hnd *h);
extern Ent_800D3C00 *fn_80100684(u32 id, s32 n);
extern s32 MemEqual(const void *a, const void *b, s32 size);
typedef struct {
    u8 pad0[0x10];
    u32 x10;
    u8 pad14[0x44 - 0x14];
    s32 x44;
} Cfg_800B4EEC;
typedef struct {
    u8 pad[0x10];
    Cfg_800B4EEC *cfg;
} Link_800B4EEC;
typedef struct {
    u8 pad0[4];
    V3 a;
    V3 b;
    u8 pad1c[0x6f - 0x1c];
    s8 x6f;
} Pool;
typedef struct {
    u8 pad0[0x1c8];
    Link_800B4EEC *link;
    u8 pad1cc[0x1d8 - 0x1cc];
    void *hook;
    u8 pad1dc[0x1fa - 0x1dc];
    s8 x1fa;
    u8 x1fb;
    u8 pad1fc[0x20c - 0x1fc];
    V3 v20c;
    u8 pad218[0x24c - 0x218];
    V3 v24c;
    u8 pad258[0x268 - 0x258];
    Pool *x268;
} Work_800B4EEC;
typedef struct {
    u8 pad0[0x19];
    u8 state;
    u8 pad1a[0x24 - 0x1a];
    Work_800B4EEC *work;
} Obj_800B4EEC;
extern void fn_800ADED0(Work_800B4EEC *w, void *h);
extern void fn_800A0E1C(Work_800B4EEC *w);
extern void fn_800B444C(Work_800B4EEC *w, Pool *p);
extern void fn_800B3D78(Work_800B4EEC *w, Pool *p);
extern void fn_800B304C(Work_800B4EEC *w, Pool *p);
typedef struct Node_800BBC3C {
    u8 pad_00[0x34];
    struct Node_800BBC3C *next;
} Node_800BBC3C;
typedef struct Work_800BBC3C {
    u8 pad_000[0x1fa];
    s8 x1fa;
    s8 x1fb;
    u8 pad_1fc[0x23a - 0x1fc];
    u16 x23a;
    u8 pad_23c[0x25c - 0x23c];
    void *x25c;
    Node_800BBC3C *x260;
} Work_800BBC3C;
typedef struct Obj_800BBC3C {
    u8 pad_00[0x19];
    u8 state;
    u8 pad_1a[0x24 - 0x1a];
    Work_800BBC3C *work;
} Obj_800BBC3C;
extern void fn_801E8580(void *p);
typedef struct Particle {
    u8 pad_00[0x24];
    f32 x24;
    f32 x28;
    u8 pad_2c[0x80 - 0x2c];
} Particle;
typedef struct Emitter {
    u8 pad_00[4];
    f32 spreadX;
    f32 spreadY;
    u8 pad_0c[0x88 - 0x0c];
    Particle tmpl;
} Emitter;
typedef struct SlotTable {
    s16 count;
    u8 pad2[0x404 - 2];
    void *buf[32];
    void *res[32];
} SlotTable;
extern SlotTable lbl_803098C8;
extern s32 lbl_803473DC;
extern void *lbl_80346D20;
extern void *lbl_80346D24;
extern void *lbl_80346CD0;
extern void *lbl_803474B8;
extern u8 lbl_803036E8[0x2000];
extern void fn_801CC0E4(void *p);
typedef struct Ent_800C6E68 {
    u8 pad0[8];
    s32 x8;
    f32 xc;
    f32 x10;
    u8 pad14[0x2c - 0x14];
    s32 x2c;
    u8 pad30[0x38 - 0x30];
    f32 x38;
    f32 x3c;
    f32 x40;
    u8 pad44[0x50 - 0x44];
    f32 x50;
    f32 x54;
    f32 x58;
    u8 pad5c[0x100 - 0x5c];
    void *texlist;
    u8 pad104[0x16e - 0x104];
    s16 x16e;
    u8 pad170[0x176 - 0x170];
    s16 x176;
} Ent_800C6E68;
typedef struct Task_800C6E68 {
    u8 pad0[0x19];
    u8 state;
    u8 pad1a[0x24 - 0x1a];
    Ent_800C6E68 *ent;
} Task_800C6E68;
extern f32 njScalor2(NJS_VECTOR *v);
extern void fn_801D9CF0(f32 x, f32 y, f32 z);
typedef struct V3_800CF988 {
    f32 x, y, z;
} V3_800CF988;
typedef struct {
    u8 pad0[8];
    f32 x8;
    f32 xc;
    f32 x10;
} Src_800CF988;
typedef struct {
    u8 pad0[0x44];
    s32 x44;
    u8 pad48[0x60 - 0x48];
    f32 x60;
} Ent_800CF988;
typedef struct V3_800D07F8 {
    f32 x;
    f32 y;
    f32 z;
} V3_800D07F8;
typedef struct Sub_800D07F8 {
    u8 pad0[0x8];
    f32 f8;
    u8 pad_c[0x18];
    u16 h24;
    u8 pad26[0xa];
    s16 h30;
} Sub_800D07F8;
typedef struct Obj_800D07F8 {
    u8 pad0[0x38];
    f32 f38;
    f32 f3c;
    f32 f40;
    u8 pad44[0x120];
    f32 f164;
    u8 pad168[0x50];
    Sub_800D07F8* p1b8;
    u8 pad1bc[0xa0];
    Sub_800D07F8* p25c;
} Obj_800D07F8;
extern u32 lbl_8030A3C8[3];
extern u16 lbl_8034740E;
extern f32 lbl_80347410;
extern s32 fn_802256A0(V3_800D07F8* v, Sub_800D07F8* s, u32 a, u32 b);
typedef struct Param {
    u8 pad0[0x2c];
    f32 pos[3];
    s32 rot[3];
    u32 mode;
    u8 pad48[0x68 - 0x48];
    f32 f68;
} Param;
typedef struct Info_800C09E4 {
    u8 pad0[0x10];
    Param *param;
} Info_800C09E4;
typedef struct Obj_800C09E4 {
    u8 pad0[0xb4];
    f32 pos[3];
    s32 rot[3];
    u8 padcc[0x16c - 0xcc];
    s16 f16c;
    u8 pad16e[0x1c8 - 0x16e];
    Info_800C09E4 *info;
    u8 pad1cc[0x1fa - 0x1cc];
    u8 f1fa;
    u8 f1fb;
    s16 f1fc;
    u8 pad1fe[0x25c - 0x1fe];
    void *f25c;
} Obj_800C09E4;
extern void fn_800C04D8(Obj_800C09E4 *o);
extern void fn_8009D6C0(Obj_800C09E4 *o, s32 idx, f32 f);
typedef struct HookCmd {
    u32 type;
    u8 pad4[0x24 - 4];
    u32 flag;
} HookCmd;
typedef struct HookInfo {
    u8 pad0[4];
    u32 id;
    u8 pad8[0x10 - 8];
    HookCmd *cmd;
} HookInfo;
typedef struct Obj_800C63A4 {
    u8 pad0[0x1b8];
    void *hook;
    u8 pad1bc[0x1c8 - 0x1bc];
    HookInfo *info;
    u8 pad1cc[0x23c - 0x1cc];
    u32 flag;
} Obj_800C63A4;
extern void *fn_802258BC(s32 a, u16 id, s32 c);
typedef struct Work_800C3C78 {
    u8 pad0[0xc];
    u8 sub[0x24 - 0xc];
    f32 f24, f28, f2c;
    u8 pad30[0x4c - 0x30];
    f32 f4c, f50, f54;
    u8 pad58[0x64 - 0x58];
    f32 f64, f68, f6c;
    u8 pad70[0x94 - 0x70];
    f32 f94, f98, f9c;
    f32 fa0, fa4, fa8;
    f32 fac, fb0, fb4;
} Work_800C3C78;
extern void fn_8009519C(void* a, void* b);
extern void fn_80225930(u16 a, u16 b, void* c);
extern void fn_80224D08(void* a, void* b, void* c, void* d);
extern void fn_80290668(NJS_POINT3* a, NJS_POINT3* b, NJS_POINT3* c, NJS_POINT3* out);
extern s32 fn_801DCFA0(NJS_POINT3* v, Angle* a);
typedef struct Ang { s32 x, y, z; } Ang;
typedef struct Work_800C4C54 {
    u8 pad0[0xc];
    f32 fc, f10, f14;
    u8 pad18[0x24 - 0x18];
    f32 f24, f28, f2c, f30, f34, f38;
    u8 pad3c[0x58 - 0x3c];
    f32 f58, f5c, f60;
    f32 f64, f68, f6c;
    u8 pad70[0xa0 - 0x70];
    f32 fa0, fa4, fa8;
    u8 padac[0xcc - 0xac];
    f32 fcc, fd0;
    u8 paddc[0xe6 - 0xd4];
    s16 he6;
    u8 pade8[0x128 - 0xe8];
    void* p128;
} Work_800C4C54;
extern s32 fn_800912FC(f32* pos, void* o);
extern s32 fn_801DD4C4(f32 x, f32 z);
typedef struct {
    void *base;
    u8 pad4[4];
    s16 cap;
    s16 cur;
    s16 step;
    s16 used;
} Queue;
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
/* Same layouts as unit_800B2DA0.c (fn_800D5F94). */
typedef struct {
    s16 frames;       /* 0x00 */
    s16 value;        /* 0x02 */
    u8 pad4[4];
} Key_800D5F94_800D62DC;
typedef struct {
    u16 mode;         /* 0x00 */
    s16 count;        /* 0x02 */
    Key_800D5F94_800D62DC keys[1];      /* 0x04 */
} Script_800D5F94_800D62DC;
typedef struct {
    u8 pad0[0xC];
    u32* data;        /* 0x0C */
} Node_800D62DC;
typedef struct {
    u8 pad0[8];
    Node_800D62DC* node;       /* 0x08 */
} Rec_800D5F94_800D62DC;
typedef struct {
    Rec_800D5F94_800D62DC* recs;        /* 0x00 */
} Table_800D5F94_800D62DC;
typedef struct {
    u8 pad0[0x34];
    s32 x34;          /* 0x34 */
    u8 pad38[0x100 - 0x38];
    Table_800D5F94_800D62DC* x100;      /* 0x100 */
    u8 pad104[0x188 - 0x104];
    u32 x188;         /* 0x188 */
    u8 pad18c[0x200 - 0x18c];
    s16 x200;         /* 0x200 */
    s16 x202;         /* 0x202 */
    u8 pad204[0x23C - 0x204];
    s32 x23c;         /* 0x23C */
    u8 pad240[0x260 - 0x240];
    Script_800D5F94_800D62DC* x260;     /* 0x260 */
} Ent_800D62DC;
typedef struct { s32 a; u32 ang; } Sub44;
typedef struct {
    u8 pad0[0x44];
    Sub44 s44;
    u8 pad4C[0xb4 - 0x4c];
    NJS_POINT3 p_b4;
    u8 padc0[0xe8 - 0xc0];
    void* e8;
    u8 pad_ec[0x18c - 0xec];
    f32 f18c;
    u8 pad190[0x210 - 0x190];
    s32 i210;
    u8 pad214[0x250 - 0x214];
    f32 f250;
    f32 f254;
    f32 f258;
} Obj_800D3668;
extern void* lbl_803470E8;
extern void* lbl_803470F0;
extern void* lbl_803470F4;
extern void fn_801D4F0C(Sprite* s, s32 a, s32 b, s32 c, f32 f1, f32 f2, f32 f3, f32 f4);
extern void fn_801D52A8(Sprite* s, s32 a, s32 b, f32 f1, f32 f2, f32 f3, f32 f4);
typedef struct V3_800D3F00 { f32 x, y, z; } V3_800D3F00;
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
typedef struct Rec { f32 a; s32 b; f32 c; } Rec;
typedef struct Obj_800D3F00 {
    u8 pad_00[0x38];
    u8 pos38[0xc];
    u8 v44[0xc];
    u8 pad_50[0xb4 - 0x50];
    V3_800D3F00 vb4;
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
typedef struct MapInfo {
    s32 unk0;
    s32 map;
    char room;
} MapInfo;
typedef struct Node_800B63A4 {
    u8 pad0[0x58];
    struct Node_800B63A4* next;
} Node_800B63A4;
typedef struct {
    u32 count;
    u8 pad4[0x48 - 4];
    u32 x48;
    u8 pad4c[0xCC - 0x4C];
    s32 xcc;
} Cnt_800B63A4;
typedef struct {
    u8 pad[0x10];
    Cnt_800B63A4* cnt;
} Link_800B63A4;
typedef struct {
    Hdr* hdr;
} Hk_800B63A4;
typedef struct {
    u8 pad0[0x1A0];
    s32 x1a0;
    u8 pad1a4[0x260 - 0x1A4];
    void* x260;
    u8 pad264[0x31C - 0x264];
    void* x31c;
} Sub_800B63A4;
typedef struct {
    u8 pad0[0x18];
    u32 flags;
    u8 pad1c[0x100 - 0x1C];
    Hk_800B63A4* x100;
    u8 pad104[0x184 - 0x104];
    s32 x184;
    u8 pad188[0x1C8 - 0x188];
    Link_800B63A4* link;
    u8 pad1cc[0x1D8 - 0x1CC];
    Sub_800B63A4* x1d8;
    u8 pad1dc[0x1FA - 0x1DC];
    s8 x1fa;
    s8 x1fb;
    s16 x1fc;
    u8 pad1fe[0x208 - 0x1FE];
    s16 x208;
    s16 x20a;
    u8 pad20c[0x25C - 0x20C];
    Node_800B63A4* x25c;
    void* x260;
    void* x264;
    u8 pad268[4];
    u8 x26c;
} Work_800B63A4;
typedef struct Obj_800B63A4 {
    u8 pad0[0x18];
    u8 flags;
    u8 state;
    u8 x1a;
    u8 x1b;
    f32 x1c_;
    f32 x20;
    Work_800B63A4* work;
} Obj_800B63A4;
extern s32 lbl_80311AD4[];
extern f32 lbl_80348F48;
extern void fn_8015ED90(Obj_800B63A4*);
extern void fn_800ABEB0(void);
extern void fn_800ABE9C(void);
extern Hk_800B63A4* fn_800A1B50(Work_800B63A4*);
extern void fn_800ADF98(Work_800B63A4*);
extern void fn_800B5A04(Work_800B63A4*);
extern void fn_800B522C(Work_800B63A4*);
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
typedef struct Node_800B88F8 {
    u8 pad0[0x58];
    struct Node_800B88F8* next;
} Node_800B88F8;
typedef struct {
    u32 count;
    u8 pad4[0x48 - 4];
    u32 x48;
    u8 pad4c[0x90 - 0x4C];
    s32 x90;
} Cnt_800B88F8;
typedef struct {
    u8 pad[0x10];
    Cnt_800B88F8* cnt;
} Link_800B88F8;
typedef struct {
    Hdr* hdr;
} Hk_800B88F8;
typedef struct {
    u8 pad0[0x1A0];
    s32 x1a0;
    u8 pad1a4[0x260 - 0x1A4];
    void* x260;
    u8 pad264[0x31C - 0x264];
    void* x31c;
} Sub_800B88F8;
typedef struct {
    u8 pad0[0x18];
    u32 flags;
    u8 pad1c[0x100 - 0x1C];
    Hk_800B88F8* x100;
    u8 pad104[0x184 - 0x104];
    s32 x184;
    u8 pad188[0x1C8 - 0x188];
    Link_800B88F8* link;
    u8 pad1cc[0x1D8 - 0x1CC];
    Sub_800B88F8* x1d8;
    u8 pad1dc[0x1FA - 0x1DC];
    s8 x1fa;
    s8 x1fb;
    s16 x1fc;
    u8 pad1fe[0x208 - 0x1FE];
    s16 x208;
    s16 x20a;
    u8 pad20c[0x24C - 0x20C];
    NJS_POINT3 x24c;
    u8 pad258[4];
    Node_800B88F8* x25c;
    void* x260;
    void* x264;
    u8 pad268[4];
    u8 x26c;
} Work_800B88F8;
typedef struct Obj_800B88F8 {
    u8 pad0[0x18];
    u8 flags;
    u8 state;
    u8 x1a;
    u8 x1b;
    f32 x1c_;
    f32 x20;
    Work_800B88F8* work;
} Obj_800B88F8;
extern f32 lbl_80348F38;
extern void fn_800B847C(Work_800B88F8*);
extern void fn_800B8028(Work_800B88F8*);
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
extern void njSetMatrix(NJS_MATRIX md, NJS_MATRIX ms);
extern void njRotateX(NJS_MATRIX m, Angle a);
extern void njTranslate(NJS_MATRIX m, f32 x, f32 y, f32 z);
extern void fn_80291C44(NJS_MATRIX m);
typedef struct Col_800B45D4 {
    u8 a, r, g, b;
} Col_800B45D4;
typedef struct Mtx_800B45D4 {
    NJS_MATRIX m;
} Mtx_800B45D4;
extern const Mtx_800B45D4 lbl_802B1128;
typedef struct Bone_800B45D4 {
    u32 x00;
    Mtx_800B45D4 mtx;               /* 0x04 */
    f32 x44;                        /* 0x44 */
    u8 pad48[0x6c - 0x48];
    Angle rotY;                     /* 0x6C */
    u8 pad70[0x74 - 0x70];
    struct Bone_800B45D4 *parent;   /* 0x74 */
    struct Bone_800B45D4 *child;    /* 0x78 */
    struct Bone_800B45D4 *next;     /* 0x7C */
} Bone_800B45D4;
typedef struct Vtx_800B45D4 {
    NJS_POINT3 p;
    Col_800B45D4 col;
} Vtx_800B45D4;
typedef struct Cfg_800B45D4 {
    u8 pad0[0x48];
    f32 x48;
    s32 x4c;
    s32 x50;
    s32 x54, x58, x5c;
    s32 x60, x64, x68;
    u32 x6c;
    u32 x70;
    s32 x74;
    u32 x78;
    s32 x7c;
    u32 x80;
    s32 x84;
    f32 x88, x8c, x90;
    s32 x94;
    s32 x98, x9c, xa0;
    s32 xa4;
    s32 xa8;
    s32 xac;
    s32 xb0;
    s32 xb4;
    s32 xb8;
    s32 xbc;
    s32 xc0;
    s32 xc4;
    s32 xc8;
    u32 xcc;
    f32 xd0;
    u32 xd4;
    f32 xd8;
} Cfg_800B45D4;
typedef struct Link_800B45D4 {
    u8 pad[0x10];
    Cfg_800B45D4 *cfg;
} Link_800B45D4;
typedef struct Lt_800B45D4 {
    u32 flags;                      /* 0x00 */
    u8 pad4[0x78 - 0x04];
    s32 x78;                        /* 0x78 */
} Lt_800B45D4;
typedef struct Work_800B45D4 {
    u8 pad0[0x1c8];
    Link_800B45D4 *link;            /* 0x1C8 */
    u8 pad1cc[0x200 - 0x1cc];
    s16 x200;                       /* 0x200 */
    s16 x202;                       /* 0x202 */
    u8 pad204[0x268 - 0x204];
    Lt_800B45D4 *x268;              /* 0x268 */
} Work_800B45D4;
typedef struct Fx_800B45D4 {
    u32 flags;                      /* 0x00 */
    u8 pad4[0x1c - 0x04];
    f32 radius;                     /* 0x1C */
    f32 x20;                        /* 0x20 */
    u8 pad24[0x28 - 0x24];
    f32 x28;                        /* 0x28 */
    f32 x2c;                        /* 0x2C */
    f32 x30, x34, x38;              /* 0x30 */
    f32 x3c;                        /* 0x3C */
    Angle x40;                      /* 0x40 */
    f32 x44;                        /* 0x44 */
    f32 x48;                        /* 0x48 */
    f32 x4c;                        /* 0x4C */
    s32 x50, x54, x58;              /* 0x50 */
    s16 x5c;                        /* 0x5C */
    u8 pad5e[0x60 - 0x5e];
    s16 x60;                        /* 0x60 */
    u8 pad62[0x64 - 0x62];
    s16 x64;                        /* 0x64 */
    s16 x66;                        /* 0x66 */
    u16 x68;                        /* 0x68 */
    u8 x6a;                         /* 0x6A */
    u8 x6b;                         /* 0x6B */
    s16 x6c;                        /* 0x6C */
    u8 x6e;                         /* 0x6E */
    u8 pad6f;
    u8 x70;                         /* 0x70 */
    u8 x71;                         /* 0x71 */
    u8 x72;                         /* 0x72 */
    u8 x73;                         /* 0x73 */
    s16 x74;                        /* 0x74 */
    s16 x76;                        /* 0x76 */
    u8 pad78[0x7c - 0x78];
    s32 x7c;                        /* 0x7C */
    Vtx_800B45D4 v[6];              /* 0x80 */
    DrawState ds;                   /* 0xE0 */
    u8 padds[0x100 - 0xe0 - sizeof(DrawState)];
    s32 x100;                       /* 0x100 */
    u8 pad104[0x108 - 0x104];
    Bone_800B45D4 *first;           /* 0x108 */
    Bone_800B45D4 *last;            /* 0x10C */
} Fx_800B45D4;
/* A dropped money/item pickup on the field map (task work). */
typedef struct ItemMotion {
    u8 pad0[4];
    u32 nframes;             /* 0x04 */
} ItemMotion;
typedef struct ItemWork {
    Task* owner;             /* 0x00 */
    void* model;             /* 0x04 */
    NJS_TEXLIST* texlist;    /* 0x08 */
    ItemMotion* motion;      /* 0x0C */
    void* shape;             /* 0x10 */
    NJS_POINT3* base;        /* 0x14 */
    f32 ofs[3];              /* 0x18 */
    f32 vel[3];              /* 0x24 */
    f32 range;               /* 0x30: wander range */
    Angle* srcAng;           /* 0x34 */
    Angle ang[3];            /* 0x38 */
    NJS_POINT3 scl;          /* 0x44 */
    f32 frame;               /* 0x50 */
    f32 speed;               /* 0x54 */
    f32 pickDist;            /* 0x58 */
    f32 wander;              /* 0x5C */
    s32 x60;                 /* 0x60 */
    u8 pad64[4];
    s32 timer;               /* 0x68 */
    s32 x6c;                 /* 0x6C */
    u8 pad70[4];
    s32 mode;                /* 0x74 */
    s32 item;                /* 0x78 */
    s32 got;                 /* 0x7C */
    s32* fade;               /* 0x80 */
    s32* flag;               /* 0x84 */
} ItemWork;
extern u8 lbl_802DFEF0[0x2c];
extern s32 lbl_80346D78;
extern s32 lbl_80346D7C;
extern void* memcpy(void* dst, const void* src, u32 n);
extern void fn_80293544(void* model, ItemMotion* motion, void* shape, f32 frame);
extern void fn_80292D88(void* model, ItemMotion* motion, f32 frame);
extern void fn_8009009C(f32* v, f32 len);
extern u32 fn_801B90E4(u16 id);
extern s8 fn_801F452C(s16 id);
extern void fn_801EFF0C(s16 id);
extern void fn_8009D190(s32 a);
#define ATAN_ANG(y, x) (((x) == 0.0f && (y) == 0.0f) ? 0 : (Angle)(10430.378f * (f32)atan2((y), (x))))

void fn_800B2DA0(u8* p, u32 v) {
    u8* q = *(u8**)(p + 0x268);
    if (q == NULL) {
        return;
    }
    *(u32*)(q + 0x78) = v;
    *(u32*)q |= 0x200;
}

void fn_800C1A34(s32 a, s32 b, s32 c, s32 d) {
    lbl_803473D0 = a;
    lbl_803473D4 = 1;
    lbl_803473CC = b;
    lbl_803473C8 = c;
    lbl_803473D8 = d;
}

typedef struct Msg {
    s16 x0;
    s16 x2;
    s16 x4;
    s16 x6;
    s32 x8;
    s32 xc;
} Msg;
f32 fn_800C2A88(Arg_800C2650 *a);
f32 fn_800C285C(Arg_800C2650 *a) {
    return fn_800C2A88(a);
}

f32 fn_800C287C(Arg_800C2650 *a)
{
    extern void *lbl_803470E8;
    extern void *lbl_803470F0;
    extern void *lbl_803470F4;
    extern Spr_800C2650 *fn_801D68C4(void *bank, s32 n);
    extern void fn_801D4F0C(Spr_800C2650 *s, s32 a, s32 b, s32 c, f32 f1, f32 f2, f32 f3, f32 f4);
    extern void fn_801D52A8(Spr_800C2650 *s, s32 a, s32 b, f32 f1, f32 f2, f32 f3, f32 f4);
    f32 x = a->f0;
    Spr_800C2650 *s;

    s = fn_801D68C4(lbl_803470F0, 0x51);
    s->f14 = a->h4;
    s->f18 = a->h6;
    fn_801D4F0C(s, 0, 0, 1, x, 0.0f, a->fc, a->f8);
    x += 10.0f;
    s = fn_801D68C4(lbl_803470E8, 7);
    s->f14 = a->h4;
    s->f18 = a->h6;
    fn_801D4F0C(s, 0, 0, 0, x, 0.0f, a->fc, a->f8);
    x += 100.0f;
    s = fn_801D68C4(lbl_803470F0, 0x54);
    s->f14 = a->h4;
    s->f18 = a->h6;
    fn_801D4F0C(s, 0, 0, 1, x, 0.0f, a->fc, a->f8);
    x += 20.0f;
    s = fn_801D68C4(lbl_803470F4, 0x47);
    s->f14 = a->h4;
    s->f18 = a->h6;
    fn_801D52A8(s, 0, 0, x, 0.0f, a->fc, a->f8);
    x += 20.0f;
    return x;
}

s32 fn_800C34C8(Obj_800C34C8 *obj) {
    Sub_800C34C8 *s = obj->f1c8;
    if (s != NULL && s->f20 != NULL && s->f20->f4 != 0) {
        fn_80227810((NJS_TEXLIST*)s->f20);
        return 1;
    }
    return 0;
}

s32 fn_800C3518(Obj_800C3518 *obj) {
    Sub_800C3518 *s = obj->f100;
    if (s != NULL && s->f4 != 0) {
        fn_80227810((NJS_TEXLIST*)s);
        return 1;
    }
    return 0;
}

extern void fn_8029CE6C(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
extern void fn_801E6B5C(MapObj *w);

void fn_800C6B04(MapTask *t)
{
    MapObj *w = t->work;
    Arg_800C7F64 arg;
    f32 x, z;
    f32 near, far;

    arg.a = w->b16a;
    arg.b = 0;
    arg.c = w->b16b;
    x = (8400.0f + 2400.0f * -(f32)arg.a) - 1200.0f;
    z = (7200.0f + 2400.0f * -(f32)arg.c) - 1200.0f;
    if (lbl_80347450 != NULL) {
        fn_800C8C54(lbl_80347450->pos, &arg);
    } else {
        return;
    }
    ClipZPush();
    near = lbl_80347560;
    far = -1200.0f;
    lbl_80346788 = near;
    lbl_8034678C = far;
    njClipZ(near, far);
    switch (t->state) {
    case 0:
        if (w->p260->w0 != 1) {
        if (w->texlist != NULL) {
            w->b1ec = 1;
            fn_80227810(w->texlist);
        } else {
            w->b1ec = 0;
        }
        w->f0c = -1100.0f;
        w->f10 = -1200.0f;
        w->x8 = 1;
        w->x2c = 1;
        w->pos[0] = w->pos[0] - x;
        w->pos[2] = w->pos[2] - z;
        w->save[0] = w->pos[0];
        w->save[1] = w->pos[1];
        w->save[2] = w->pos[2];
        w->x16e = 1;
        t->f20 = -60000.0f;
        w->flags176 = w->flags176 & 0xff;
        t->state = 1;
        } else {
            t->state = 0xff;
            t->f20 = 0.0f;
        }
        break;
    case 1:
        if (w->p260->w0 != 1) {
            s32 dx = (s32)((8400.0f - lbl_80347450->pos[0]) / 2400.0f);
            s32 dz = (s32)((7200.0f - lbl_80347450->pos[2]) / 2400.0f);
            f32 ox = 8400.0f + (-(2400.0f * (f32)dx) - 1200.0f);
            f32 oz = 7200.0f + (-(2400.0f * (f32)dz) - 1200.0f);
            w->pos[0] = w->save[0] + ox - 2400.0f * (f32)arg.a;
            w->pos[1] = w->save[1];
            w->pos[2] = w->save[2] + oz - 2400.0f * (f32)arg.c;
            fn_8029CE6C(6, 0x80, 0, 6, 0x80, 1);
            fn_801E6B5C(w);
            fn_8029CE6C(4, 0, 0, 7, 0, 1);
            break;
        } else {
            t->state = 0xff;
            t->f20 = 0.0f;
        }
    case 0xff:
        if (w->texlist != NULL && w->b1ec == 1) {
            fn_802275A4(w->texlist, 0);
        }
        fn_80100B74(t);
        break;
    case 0xfe:
        break;
    }
    ClipZPop();
}

void fn_800C6FD8(void) { fn_800C79C4(); }

void fn_800C6FF8(void) { fn_800C79C4(); }

void fn_800C7378(void* p) {
    fn_80100B74(p);
}

extern void fn_801E5DF0(MapObj *w);

void fn_800C7398(MapTask *t)
{
    MapObj *w = t->work;
    Arg_800C7F64 arg;
    f32 x, z;
    f32 near, far;

    arg.a = w->b16a;
    arg.b = 0;
    arg.c = w->b16b;
    x = (8400.0f + 2400.0f * -(f32)arg.a) - 1200.0f;
    z = (7200.0f + 2400.0f * -(f32)arg.c) - 1200.0f;
    if (lbl_80347450 != NULL) {
        fn_800C8C54(lbl_80347450->pos, &arg);
    } else {
        return;
    }
    ClipZPush();
    near = lbl_80347560;
    far = -1200.0f;
    lbl_80346788 = near;
    lbl_8034678C = far;
    njClipZ(near, far);
    switch (t->state) {
    case 0xfe:
    case 0:
        if (w->p260->w0 != 1) {
            if (w->texlist != NULL) {
                w->b1ec = 1;
                fn_80227810(w->texlist);
            } else {
                w->b1ec = 0;
            }
            w->f0c = -1100.0f;
            w->f10 = -1200.0f;
            w->x8 = 0;
            w->x8 = 1;
            w->x2c = 0;
            w->x2c = 1;
            w->flags176 = 0;
            w->pos[0] = w->pos[0] - x;
            w->pos[2] = w->pos[2] - z;
            w->save[0] = w->pos[0];
            w->save[1] = w->pos[1];
            w->save[2] = w->pos[2];
            t->state = 1;
        } else {
            t->state = 0xff;
        }
        break;
    case 1:
        w->flags176 = w->flags176 | 0x2000;
        if (w->p260->w0 != 1) {
            s32 dx = (s32)((8400.0f - lbl_80347450->pos[0]) / 2400.0f);
            s32 dz = (s32)((7200.0f - lbl_80347450->pos[2]) / 2400.0f);
            f32 ox = 8400.0f + (-(2400.0f * (f32)dx) - 1200.0f);
            f32 oz = 7200.0f + (-(2400.0f * (f32)dz) - 1200.0f);
            w->pos[0] = w->save[0] + ox - 2400.0f * (f32)arg.a;
            w->pos[1] = w->save[1];
            w->pos[2] = w->save[2] + oz - 2400.0f * (f32)arg.c;
            fn_801D9BFC();
            fn_801D9CF0(1.0f, 1.0f, 1.0f);
            fn_801E7E14(w->pe4, 3, 0, 0);
            w->pec = (w->p1c8->p1c->count > 0) ? w->p1c8->p1c->w4 : 0;
            if (w->pe8 == NULL) {
                fn_801E66E0(w);
            } else {
                w->pec = (w->p1c8->p1c->count > 1) ? w->p1c8->p1c->w8 : 0;
                fn_801E5DF0(w);
            }
            fn_801D9B34();
            break;
        } else {
            t->state = 0xff;
        }
    case 0xff:
        if (w->texlist != NULL && w->b1ec == 1) {
            fn_802275A4(w->texlist, 0);
        }
        fn_80100B74(t);
        break;
    }
    ClipZPop();
}

int fn_800C7DD4(void) {
    if (lbl_80346D5C == 1 || lbl_80346D4C > 0) {
        return 1;
    }
    return 0;
}

void fn_800C81BC(int unused, u8* p) {
    *(void**)(p + 4) = fn_801DB124(*(void**)(p + 4));
}

void fn_800C9060(void) {
    ((u8*)lbl_80346D70)[0x19] = 2;
}

s32 fn_800CB610(void *unused, Obj_800CB610 *obj, s16 *data, s16 n) {
    s32 ret = 0;
    s32 v = (((s32)data[0] - 1) * 8 + 12) / 4;
    if (v == n) {
        obj->f260 = data;
        ret = 1;
    } else {
        obj->f260 = NULL;
    }
    return ret;
}

int fn_800CB650(int unused, u8* p, u32 v) {
    p[0x1ed] = 2;
    *(u32*)(p + 0x268) = v;
    return 1;
}

int fn_800CB664(int unused, u8* p, u32 v) {
    p[0x1ed] = 1;
    *(u32*)(p + 0x268) = v;
    return 1;
}

int fn_800CB678(int unused, u8* p, u32 v) {
    p[0x1ed] = 0;
    *(u32*)(p + 0x268) = v;
    return 1;
}

s32 fn_800CB68C(void *unused, Obj_800CB68C_UNIT0000 *obj, Src_UNIT0000 *src) {
    obj->p264 = src;
    obj->b1ec = 0;
    obj->f22c = src->f1e;
    obj->f1fe = src->f14;
    obj->f200 = src->f16;
    obj->b1ee = src->f18;
    obj->b1ef = src->f1a;
    obj->f204 = src->f1c;
    return 1;
}

void fn_800CD11C(void) {
    if (lbl_80305B08.p00 != NULL) {
        fn_801E1784(lbl_80305B08.p00);
    }
    lbl_80305B08.p00 = NULL;
    lbl_80305B08.h0e = 0;
    lbl_80305B08.h0c = 0;
    lbl_80305B08.h0a = 0;
    lbl_80305B08.h08 = 0;
}

void fn_800CF8C4(void* p, f32 max) {
    lbl_80346D8C = 1;
    fn_800CF7BC((V3*)lbl_802E1118, (V3*)p, max);
}

void fn_800CF8F8(f32 *pos, s32 *val) {
    if (lbl_80347450 == NULL) {
        return;
    }
    if (pos != NULL) {
        lbl_80347450->pos[0] = pos[0];
        lbl_80347450->pos[1] = pos[1];
        lbl_80347450->pos[2] = pos[2];
    }
    if (val != NULL) {
        lbl_80347450->s48 = *val;
    }
}

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

s32 fn_800D2BF0(u32 id) {
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
    *(u16*)(lbl_80305BA8 + 0x28) = v;
}

void fn_800D2C60(f32 a, f32 b) {
    *(f32*)(lbl_80305BA8 + 0x18) = a;
    *(f32*)(lbl_80305BA8 + 0x20) = b;
}

void fn_800D2C74(u32 v) {
    *(u32*)(lbl_80305BA8 + 0x10) = v;
}

void fn_800D2C84(u8 v) {
    lbl_80305BA8[0x2] = v;
}

void fn_800D2C94(s8 v) {
    *(s16*)(lbl_80305BA8 + 0x4) = v;
}

void fn_800D2CA8(u8 v) {
    lbl_80305BA8[0x1] = v;
}

void fn_800D2CB8(u8 v) {
    lbl_80305BA8[0] = v;
}

extern void fn_800D4690(Msg*, s16);
void fn_800D4944(Msg* a, s16 i) {
    fn_800D4690(a, i);
}

void fn_800D4964(Msg* a, s16 i) {
    fn_800D4690(a, i);
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
extern void fn_800D6580(HitNode *s, void *p);
extern s32 fn_8020F3D4(s32 id, s32 n, Ent_800D6618 *e, ...);
extern s32 fn_8020F934(s32 id);
s32 fn_800CCCA4(u32 a, u32 b, u32 c);
s32 fn_800CD0B8(s32 a, s32 b, s32 c, s32 d);

void fn_800D6618(MapTask *t)
{
    MapObj *e = t->work;
    HitNode *s = e->p1bc;
    s32 ok;
    Cfg_800CDEF4 *q;
    void *r;
    Ent_800D6618 ent;

    switch (t->state) {
    case 0:
        ok = 0;
        if (e->p1c8 != NULL) {
            if (e->p1c8->p10->w0 >= 9) {
                if (e->p1c8->p10->w4 >= 0) {
                    e->p1b4 = fn_80225B74(0xffff, e->p1c8->p10->w4);
                }
                if (e->p1bc != NULL) {
                    e->p1bc->h16 = 0;
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
        fn_800CCCA4(8, e->p1c8->p10->w24, 0x50000);
        t->state = 2;
    case 2:
        if (e->p1b4 != NULL) {
            MemCopy(e->save, e->pos, 12);
            fn_80223628(e->pos, e->pos, e->p1b4);
            if (MemEqual(e->save, e->pos, 12) == 0) {
                fn_80222838(e->p1bc);
            }
        }
        if (s->h16 == 0 && lbl_80347450 != NULL && lbl_80347450->p1bc != NULL
            && fn_80222B30(s, lbl_80347450->p1bc) != 0) {
            r = fn_80223104(0x15, s);
            if (r != NULL && fn_80222B30(r, lbl_80347450->p1bc) != 0) {
                fn_800D6580(s, r);
            }
        }
        if (s->h16 != 0) {
            s->h14 = -0x8000;
            if (s->h16 == 1) {
                q = e->p1c8->p10;
                fn_800CD0B8(8, q->w24, 0x40000, 0);
                ent.x = e->pos[0];
                ent.y = 1.17549435e-38f;
                ent.z = e->pos[2];
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
        fn_800CCCA4(8, e->p1c8->p10->w24, 0x40000);
        t->state = 4;
    case 4:
        if (fn_8015F1F0(lbl_80347450) != 0) {
            t->state = 5;
        }
        break;
    case 5:
        if (fn_8015F1F0(lbl_80347450) == 0) {
            s = e->p1bc;
            s->h16 = 0;
            s->h14 = 0;
            s->p4->h16 = 0;
            s->p4 = NULL;
            fn_800CD0B8(8, e->p1c8->p10->w24, 0x50000, 0);
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

int fn_800D7B04(void) {
    return (s8)lbl_80310A1C[0x11] != 2;
}

s32 fn_800B2E84(Ctx_800B2E84_UNIT0000* ctx, s32 index, s16 value) {
    s32 i = 0;
    Node_UNIT0000* node = ctx->owner->list;
    if (node == 0) {
        return 0;
    }
    while (i < index && node != 0) {
        node = node->next;
        i++;
    }
    if (node != 0) {
        node->h54 = value;
        node->h56 = 0;
        node->f48 = 1.0f;
        node->f50 = 1.0f;
        return 1;
    }
    return 0;
}

void fn_800C2EAC(void) {
    if (lbl_80346D34 != 0) {
        fn_801D6944(lbl_80346D34);
    }
    if (lbl_80346D30 != 0) {
        fn_801D6944(lbl_80346D30);
    }
    if (lbl_80347614 != 0) {
        fn_802275A4(lbl_80347614->inner->texlist, 1);
        fn_801E17E0(lbl_80347614);
        lbl_80347614 = 0;
    }
    if (lbl_80346D38 != 0) {
        fn_801E17E0(lbl_80346D38);
        lbl_80346D38 = 0;
    }
}

s32 fn_800C355C(Sub_UNIT0000** out, Ctx_800C355C_UNIT0000* ctx, s32 idx) {
    ItemList_UNIT0000* list;
    s32 value = 0;
    Sub_UNIT0000* sub = 0;
    if (idx >= 0) {
        list = ctx->list;
        if (idx <= list->count - 1) {
            Ent_UNIT0000* e = list->items[idx];
            if (e != 0) {
                sub = &e->sub;
                value = e->value;
                if (sub != 0 && sub->y == 0) {
                    sub = 0;
                }
            }
        }
    }
    if (out != 0) {
        *out = sub;
    }
    return value;
}

void fn_800C4B18(Obj_800C4B18* self) {
    fn_80095360(&self->a, 0);
    self->sum.x = self->a.x + *(f32*)((u8*)self + 0x30);
    self->sum.y = self->a.y + *(f32*)((u8*)self + 0x34);
    self->sum.z = self->a.z + *(f32*)((u8*)self + 0x38);
    fn_8022BAA0((u8*)self + 0x40, &self->sum, (u8*)self + 0x4c, (u8*)self + 0xa0);
}

void fn_800C6724(Obj_800C6724_UNIT0000* self) {
    Inner_UNIT0000* inner = self->inner;
    switch (self->state) {
    case 0:
        if (inner->f100 != 0) {
            fn_80227810(inner->f100);
        }
        self->state = 1;
        break;
    case 2:
    case 0xfe:
        break;
    case 1:
        if (lbl_80346D48 == 0) {
            fn_801E66E0();
        }
        break;
    }
}

void fn_800C67A8(Obj_800C67A8_UNIT0000* self) {
    Inner_UNIT0000* inner = self->inner;
    switch (self->state) {
    case 0:
        if (inner->f100 != 0) {
            fn_80227810(inner->f100);
        }
        self->state = 1;
        break;
    case 2:
    case 0xfe:
        break;
    case 1:
        if (lbl_80346D48 != 0) {
            fn_801E66E0();
        }
        break;
    }
}

void fn_800C682C(Obj_800C682C* self) {
    switch (self->state) {
    case 0:
        lbl_80346D48 = 0;
        self->state = 1;
    case 1:
        if (lbl_80311A60[0]->flags & 0x100) {
            lbl_80346D48 = ~lbl_80346D48;
        }
        break;
    case 2:
    case 0xfe:
        break;
    }
}

void fn_800C8E44(f32 a, f32 b, f32 c) {
    fn_801002D0((const char*)lbl_802B1448);
    lbl_8030A2E8.x = a;
    lbl_8030A2E8.y = b;
    lbl_8030A2E8.z = c;
    lbl_8030A2DC[0] = 0;
    lbl_8030A2DC[1] = 0;
    lbl_8030A2DC[2] = 0;
    lbl_803473B8 = 1;
}

void fn_800CD1F0(s16 n) {
    void* p = fn_801E1A2C((u32)(s32)n * 2, 0x10);
    lbl_80305B08.p00 = p;
    if (p != 0) {
        lbl_80305B08.h08 = n;
        lbl_80305B08.w04 = (u32)((u8*)p + n * 16);
    } else {
        lbl_80305B08.h08 = 0;
    }
    lbl_80305B08.h0a = 0;
    lbl_80305B08.h0c = 0;
    lbl_80305B08.h0e = 0;
}

s32 fn_800B2DC0(Ctx_800B2DC0 *c, s32 idx, s32 a, s16 b, f32 f)
{
    Node_800B2DC0 *p = c->owner->list;
    s32 i = 0;
    if (p == 0) {
        return 0;
    }
    while (i < idx && p != 0) {
        p = p->next;
        i++;
    }
    if (p != 0) {
        if (a != 0) {
            p->h54 = -a;
            p->h56 = b;
            if (p->f48 > 0.0f) {
                p->f50 = 1.0f - p->f48;
                if (p->f50 < 0.001f) {
                    p->f50 = 0.001f;
                }
            } else {
                p->f50 = 1.0f;
                p->f48 = 0.0f;
            }
        } else {
            p->h54 = b;
            p->h56 = 0;
            p->f48 = 1.0f;
            p->f50 = 1.0f;
        }
        p->f4c = f;
        return 1;
    }
    return 0;
}

void fn_800BC02C(Self_800BC02C *self, Out *out)
{
    X_800BC02C *x = self->p1c8->p10;
    out->w8c = self->w100;
    out->b85 = x->w54;
    out->b86 = x->w58;
    out->b87 = x->w5c;
    if (out->b85 != 0 || out->b86 != 0 || out->b87 != 0) {
        out->w80 = 1;
    } else {
        out->w80 = 0;
    }
    out->h7a = x->we8;
    if (x->w50 == 3) {
        out->w7c = 1;
    } else {
        out->w7c = 0;
    }
}

void fn_800BD904(Actor_800BD904 *a, Rec_UNIT0000 *r)
{
    Sub_800BD904 *s = a->sub;
    X_800BD904 *x = s->p1c8->p10;
    if (s != 0 && r != 0) {
        if (x->w6c != 0) {
            r->w0 |= 2;
        } else {
            r->w0 &= ~2;
        }
        r->w4 = fn_800A1AE8(s, 0x3b);
        r->w8 = fn_800A1ABC(s, 0x3b);
        r->w14 = 0;
        r->wc = 0;
        r->w10 = fn_800A10A8(r->w8, r->w14, r->w4) + 1;
        r->f1c = s->f50;
        r->f20 = s->f54;
        r->w0 &= ~0x80;
        fn_800BC02C((Self_800BC02C *)s, (Out *)r);
    }
}

void fn_800BE464(NJS_VECTOR *a, NJS_VECTOR *b, Angle ang)
{
    f32 dx = a->x - b->x;
    f32 dz = a->z - b->z;
    f32 s, c, nx, nz;
    f32 zero = 0.0f;
    if (dx != zero || dz != zero) {
        s = njSin(ang);
        c = njCos(ang);
        nx = dx * c - dz * s;
        nz = dx * s + dz * c;
        a->x = nx;
        a->z = nz;
        a->x = a->x + b->x;
        a->z = a->z + b->z;
    }
}

void fn_800C3348(void)
{
    void *a;
    u32 sz;
    void *dst;
    void *b;
    void *src;
    void *obj;

    lbl_80346D40 = fn_801E49D8(lbl_802B13BC);
    b = fn_801E4974(lbl_80346D40, 1);
    sz = fn_801E48A8(lbl_80346D40);
    dst = fn_801E1C7C((u32)b);
    src = fn_801E4984(lbl_80346D40, 1);
    MemCopy(dst, src, (u32)b);
    lbl_80346D40 = fn_801E1584(lbl_80346D40, sz - (u32)b);
    lbl_80346D44 = fn_801DB124(dst);
    obj = lbl_80346D44;
    fn_80227810(*(void **)((u8 *)*(void **)((u8 *)obj + 0x4) + 0x20));
    lbl_80346D3C = fn_801E1C7C(0x14);
    a = fn_801E4984(lbl_80346D40, 0);
    fn_801D6998(lbl_80346D3C, a);
}

void fn_800C3428(Self_800C3428 *self)
{
    Sub_800C3428 *s = self->sub;
    if (s != 0 && s->p100 != 0) {
        if (s->p100->w4 != 0) {
            fn_802275A4((NJS_TEXLIST *)s->p100, 0);
        }
        s->p100 = 0;
    }
    if (s->p1ac != 0) {
        fn_801DD9AC((void *)&lbl_803474EC, s->p1ac);
        s->p1ac = 0;
    }
    if (s->p1b0 != 0) {
        fn_801DD95C(s->p1b0);
        s->p1b0 = 0;
    }
    fn_80100B74(self);
}

void fn_800C40EC(Obj_800C40EC *self)
{
    s32 r;
    fn_80095360(self->box, 0);
    fn_80091040(self->box, &self->fac);
    self->f24 = self->fac + self->f30;
    self->f28 = self->fb0 + self->f34;
    self->f2c = self->fb4 + self->f38;
    r = fn_80095110();
    if (r >= 0) {
        self->w74 = r + self->wd8;
    }
    self->w44 = fn_800912A8(self->w74, self->w44, 0x80, 0x400);
    fn_801DCEB0((u8 *)self + 0x4c, (u8 *)self + 0x40, -self->fcc);
    self->f4c = self->f4c + self->f24;
    self->f50 = self->f50 + self->f28;
    self->f54 = self->f54 + self->f2c;
}

void fn_800C4B90(Obj_800C4B90 *self, Other *other)
{
    if (self->p108 != 0) {
        self->p108->h14 |= 0x8000;
    }
    if ((self->h2 & 4) == 0 && (other->h2 & 4) == 0) {
        f32 c0 = 0.0f;
        f32 c1 = 14.0f;
        self->f38 = c0;
        self->f30 = c0;
        self->f34 = c1;
    }
    self->f24 = self->fc + self->f30;
    self->f28 = self->f10 + self->f34;
    self->f2c = self->f14 + self->f38;
    self->f4c = self->f64;
    self->f50 = self->f68;
    self->f54 = self->f6c;
    fn_800967F0(self, (self->h2 & 1) ? 6 : 4, 6);
}

void fn_800C5108(Obj_800C5108 *self)
{
    fn_80095360(self->box, 0);
    fn_80091040(self->box, &self->fac);
    self->f4c = self->fac + self->f58;
    self->f50 = self->fb0 + self->f5c;
    self->f54 = self->fb4 + self->f60;
    self->f24 = self->fac + self->f30;
    self->f28 = self->fb0 + self->f34;
    self->f2c = self->fb4 + self->f38;
    fn_8022BAA0((u8 *)self + 0x40, &self->f24, &self->f4c, (u8 *)self + 0xa0);
}

void fn_800C5B58(Obj_800C5B58 *self, Ctl_800C5B58 *c)
{
    if (self->w1b0 == 0) {
        if (c->h0 != 0 || c->h2 != 0) {
            s16 a;
            fn_801E7DF0(*(void **)((u8 *)self + 0xe4));
            a = c->h0;
            if (a != 0 && c->h2 != 0) {
                *(s16 *)((u8 *)self + 0x204) = 2;
            } else if (a != 0) {
                *(s16 *)((u8 *)self + 0x204) = 0;
            } else {
                *(s16 *)((u8 *)self + 0x204) = 1;
            }
            *(s16 *)((u8 *)self + 0x206) = c->h0;
            *(s16 *)((u8 *)self + 0x208) = c->h2;
            self->w188 |= 8;
        }
    }
}

void fn_800C6310(Obj_800C6310 *self)
{
    s32 t = self->b19;
    void *sub = self->p24;
    switch (t) {
    case 0:
    case 0xfe:
        fn_800C5EE8(sub);
        self->b19 = 1;
        break;
    case 1:
        if (fn_800D2924(sub) != 0) {
            fn_800C5D78(sub);
        }
        break;
    default:
        fn_800C3428((Self_800C3428 *)self);
        break;
    }
}

s32 fn_800C86EC(Host_800C86EC *h, s32 arg) {
    Ent_800C86EC *e;
    u32 i;
    s32 result = 0;

    e = h->ents;
    for (i = 0; i < h->hdr->count; i++) {
        if (e->fn != 0 && !(e->flags & 0x40)) {
            if (arg != 0 && e->val < 0.0f) {
                fn_80226AE8(e);
            } else {
                e->fn(e);
            }
            if (!(e->flags & 0x40)) {
                result = 1;
            }
        }
        e = (Ent_800C86EC *)((u8 *)e + 0x2C0);
    }
    return result;
}

void fn_800C88E4(void) {
    lbl_80305A5C[0] = 0;
    lbl_80305A5C[1] = 0;
    lbl_80305A5C[2] = 0;
    lbl_80305A5C[3] = 0;
    lbl_80305A5C[4] = 0;
    lbl_80305A5C[5] = 0;
    lbl_80305A5C[6] = 0;
    lbl_80305A5C[7] = 0;
    lbl_80305A5C[8] = 0;
    lbl_80305A5C[9] = 0;
    lbl_80305A5C[10] = 0;
    lbl_80305A5C[11] = 0;
    lbl_80305A5C[12] = 0;
    lbl_80305A5C[13] = 0;
    lbl_80305A5C[14] = 0;
    lbl_80305A5C[15] = 0;
    lbl_80305A5C[16] = 0;
    lbl_80305A5C[17] = 0;
    lbl_80305A5C[18] = 0;
    lbl_80305A5C[19] = 0;
    lbl_80305A5C[20] = 0;
    lbl_80305A5C[21] = 0;
    lbl_80305A5C[22] = 0;
    lbl_80305A5C[23] = 0;
    lbl_80305A5C[24] = 0;
    lbl_80305A5C[25] = 0;
    lbl_80305A5C[26] = 0;
    lbl_80305A5C[27] = 0;
    lbl_80305A5C[28] = 0;
    lbl_80305A5C[29] = 0;
    lbl_80305A5C[30] = 0;
    lbl_80305A5C[31] = 0;
    lbl_80305A5C[32] = 0;
    lbl_80305A5C[33] = 0;
    lbl_80305A5C[34] = 0;
    lbl_80305A5C[35] = 0;
    lbl_80305A5C[36] = 0;
    lbl_80305A5C[37] = 0;
    lbl_80305A5C[38] = 0;
    lbl_80305A5C[39] = 0;
    lbl_80305A5C[40] = 0;
    lbl_80305A5C[41] = 0;
}

s32 fn_800C8D90(void) {
    if (lbl_80311AC0.map == 0x63 ||
        (lbl_80311AC0.map == 0x7a && lbl_80311AC0.room == 'a') ||
        (lbl_80311AC0.map == 0x7d && lbl_80311AC0.room == 'a') ||
        (lbl_80311AC0.map == 0x7d && lbl_80311AC0.room == 'b') ||
        (lbl_80311AC0.map == 0x7d && lbl_80311AC0.room == 'd') ||
        (lbl_80311AC0.map == 0x7f && (lbl_80311AC0.room == 'a' || lbl_80311AC0.room == 'b'))) {
        return 1;
    }
    return 0;
}

void fn_800C8F3C(s32 idx) {
    void *p;
    void *a;

    if (((void**)lbl_80346D70->tab)[idx] != 0) {
        p = fn_8015F1A0(0x752f);
        if (p != 0) {
            a = *(void **)((u8 *)p + 0x1cc);
            a = *(void **)((u8 *)a + 4);
            fn_802275A4(*(void **)((u8 *)a + 0x20), 0);
        }
        fn_801003F4(((void**)lbl_80346D70->tab)[idx]);
        fn_801E17E0(((void**)lbl_80346D70->tab)[idx]);
        ((void**)lbl_80346D70->tab)[idx] = 0;
    }
}

void fn_800C9070(void) {
    s32 i;

    lbl_80346D70 = fn_802268E8(lbl_803475A8, fn_800C9144);
    lbl_80346D70->tab = fn_801E1C7C(0x80);
    for (i = 0; i < 0x80; i += 0x20) {
        *(s32 *)((u8*)lbl_80346D70->tab + i + 0) = 0;
        *(s32 *)((u8*)lbl_80346D70->tab + i + 4) = 0;
        *(s32 *)((u8*)lbl_80346D70->tab + i + 8) = 0;
        *(s32 *)((u8*)lbl_80346D70->tab + i + 0xc) = 0;
        *(s32 *)((u8*)lbl_80346D70->tab + i + 0x10) = 0;
        *(s32 *)((u8*)lbl_80346D70->tab + i + 0x14) = 0;
        *(s32 *)((u8*)lbl_80346D70->tab + i + 0x18) = 0;
        *(s32 *)((u8*)lbl_80346D70->tab + i + 0x1c) = 0;
    }
}

void *fn_800CCAE4(s32 (*cb)(void *, void *), void *arg, u32 best) {
    Entry_UNIT0000 *e;
    void *result = 0;

    if (cb != 0 && arg != 0) {
        lbl_80346D80 = 0;
        e = (Entry_UNIT0000*)lbl_80305B08.p00;
        while (lbl_80346D80 < lbl_80305B08.h0a) {
            if (cb(e, arg) != 0) {
                u32 k = (u16)e->key;
                if (k <= best) {
                    result = e;
                    best = k;
                }
            }
            lbl_80346D80++;
            e++;
        }
    }
    return result;
}

void *fn_800CCB94(s32 (*cb)(void *, void *), void *arg) {
    Entry_UNIT0000 *e;
    void *result = 0;
    u32 best = 0xFFFF;

    if (cb != 0 && arg != 0) {
        lbl_80346D80 = 0;
        e = (Entry_UNIT0000*)lbl_80305B08.p00;
        while (lbl_80346D80 < lbl_80305B08.h0a) {
            if (cb(e, arg) != 0) {
                u32 k = (u16)e->key;
                if (k <= best) {
                    result = e;
                    best = k;
                }
            }
            lbl_80346D80++;
            e++;
        }
    }
    return result;
}

void fn_800D1268(Self_800D1268_UNIT0000 *self) {
    s32 n;
    List_UNIT0000 *list;
    Elem *el;

    n = self->count;
    if (n > 0) {
        list = self->list;
        if (list != 0) {
            el = list->elems;
            do {
                if (el->f20 != 0) {
                    fn_801DD9AC(&lbl_803474EC, el->f20);
                }
                if (el->f24 != 0) {
                    fn_801DD95C(el->f24);
                }
                if (el->a8 != 0) {
                    fn_802275A4(el->a8, 0);
                }
                n--;
                el++;
            } while (n > 0);
            fn_801E17E0(list);
            self->list = 0;
        }
    }
    self->f1ac = 0;
    self->f1b0 = 0;
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

s32 fn_800D2924(Self_800D2924 *self) {
    s32 ret;

    if (lbl_80305BE8.a6 == 0) {
        self->f184 = 0;
        ret = 1;
    } else if (lbl_80305BE8.u2a == 0xFFFF) {
        self->f184 = 1;
        ret = 0;
    } else if (self->p1c8 != 0) {
        if (lbl_80305BE8.w3c == self->p1c8->v34) {
            self->f184 = 0;
            ret = 1;
        } else {
            self->f184 = 1;
            ret = 0;
        }
    } else {
        self->f184 = 0;
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
        MapObj *t = lbl_80347450;

        if (t != 0) {
            f32 dy = self->fb4 - t->pos[0];
            f32 dx = self->fb8 - t->pos[1];
            f32 dz = self->fbc - t->pos[2];
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

void fn_800B4038(Work_800B4038* w, Obj_800B4038* o) {
    s32 hi;
    s32 lo;
    o->x5c++;
    hi = w->x200;
    lo = w->x202;
    if (o->x5c >= o->x68 * 2) {
        o->x5c = 0;
    }
    o->x4c = 0.5f * (f32)(hi + lo) + 0.5f * (f32)(hi - lo) * njCos((s32)(10430.37835 * (o->x48 * (f32)o->x5c)));
    if (o->x6c != 0) {
        if (w->x1fc == 0) {
            o->x5c = 0;
            w->x230 = 0;
            o->x6f = 2;
            o->x110 = o->x108;
            w->x1fc = 0;
            w->x22e = 1;
        } else {
            w->x1fc--;
        }
    }
}

void fn_800B77E4(Work_800B77E4* w) {
    Node_800B77E4* p;
    Node_800B77E4* q;
    s32 done = 0;
    s32 i;
    s32 n;
    p = w->list;
    while (p != NULL) {
        q = p;
        p = p->next;
        if (q != NULL) {
            fn_801E1784(q);
        }
    }
    w->list = NULL;
    w->x22c = 0;
    p = fn_801E1A2C(1, 0x18);
    p->next = NULL;
    i = 2;
    w->list = p;
    n = w->link->cfg->xb0 + 1;
    if (n <= 1) {
        n = 2;
    }
    w->x22c = n;
    w->x258 = 1.0f / (f32)(s32)(w->x22c - 1);
    while (!done) {
        if (i > w->x22c) {
            done = 1;
        } else {
            q = fn_801E1A2C(1, 0x18);
            q->next = p;
            p = q;
            i++;
            w->list = q;
        }
    }
}

void fn_800BA444(Obj_800BA444* o, Work_800BA444* w) {
    Emit_800BA444* e = &w->emit;
    Part_800BA444* p = o->parts;
    Part_800BA444* prev = NULL;
    Part_800BA444* next;
    f32 zero = 0.0f;
    if (w->x11c != zero) {
        fn_800D208C(w->x118, w->x11c);
    }
    while (p != NULL) {
        p->life--;
        if (p->life <= w->x110) {
            e->x = p->x18;
            e->y = p->x1c;
            e->x14 = fn_8009E4D4(p->x24);
            fn_800A2830(e, p, p->posb);
            next = p->next;
            if (p->life <= 0) {
                if (p != NULL) {
                    fn_801E1784(p);
                    p = NULL;
                }
                if (prev != NULL) {
                    prev->next = NULL;
                } else {
                    o->parts = NULL;
                }
            } else {
                prev = p;
                p->x24 = p->x24 - p->x28;
                p = next;
            }
        } else {
            prev = p;
            p = p->next;
        }
    }
    if (w->x11c != zero) {
        fn_800D2048();
    }
}

void* fn_800C2F4C(void) {
    void* buf;
    void* src;
    void* d0;
    s32 size;
    s32 total;
    lbl_80346D38 = fn_801E49D8(lbl_802B13A0);
    size = (s32)fn_801E4974(lbl_80346D38, 2);
    total = fn_801E48A8(lbl_80346D38);
    buf = fn_801E1C7C(size);
    src = fn_801E4984(lbl_80346D38, 2);
    MemCopy(buf, src, size);
    lbl_80346D38 = fn_801E1584(lbl_80346D38, total - size);
    lbl_80347614 = fn_801DB124(buf);
    fn_80227810(lbl_80347614->inner->texlist);
    lbl_80346D34 = fn_801E1C7C(0x14);
    d0 = fn_801E4984(lbl_80346D38, 0);
    fn_801D6998(lbl_80346D34, d0);
    lbl_80346D30 = fn_801E1C7C(0x14);
    fn_801D6998(lbl_80346D30, fn_801E4984(lbl_80346D38, 1));
    return lbl_80346D38;
}

void fn_800C3A50(Cam_800C3A50* c) {
    NJS_VECTOR b;
    NJS_VECTOR a;
    NJS_VECTOR d;
    f32 lim;
    f32 r;
    fn_80094F90(&a, c);
    fn_80095360(&b, 0);
    d.x = b.x - a.x;
    d.y = b.y - a.y;
    d.z = b.z - a.z;
    c->x24 = c->x30 + a.x + 0.5f * d.x;
    c->x28 = c->x34 + a.y + 0.5f * d.y;
    c->x2c = c->x38 + a.z + 0.5f * d.z;
    r = fn_80291A5C(d.x * d.x + d.y * d.y + d.z * d.z);
    lim = r * c->xcc;
    if (c->xd0 > lim) {
        lim = c->xd0;
    }
    fn_801DCEB0(&b, c->x70, -lim);
    c->x4c = c->x24 + b.x;
    c->x50 = c->x28 + b.y;
    c->x54 = c->x2c + b.z;
}

void fn_800C3B58(Obj_800C3B58* o, Src_800C3B58* s) {
    s32 a;
    f32 half = 0.5f;
    if (o->x108 != NULL) {
        o->x108->x14 |= 0x8000;
    }
    if (!(o->flags & 4)) {
        if (!(s->flags & 0x20)) {
            o->x78 = 0;
            o->x74 = 0;
            o->x70 = 0;
        }
        if (!(s->flags & 4)) {
            o->x30 = o->x34 = o->x38 = 0.0f;
        }
        if (s->flags & 0x1000) {
            o->xec = 0;
            o->xe8 = s->x60;
            o->xcc = s->x54;
            o->xd0 = s->x5c;
        }
        o->xcc = half / njTan((Angle)(182.04445f * (o->x158 * half))) / o->xcc;
    }
    o->x40 = o->x70;
    o->x44 = o->x74;
    o->x48 = o->x78;
    if (o->flags & 1) {
        a = 6;
    } else {
        a = 4;
    }
    fn_800967F0(o, a, 6);
}

void fn_800C47BC(Cam_800C47BC* c) {
    NJS_VECTOR v;
    Ang3_800C47BC a;
    fn_80095360(&c->pos, 0);
    v.x = c->xac;
    v.y = c->pos.y;
    v.z = c->xb4;
    fn_80091040(&v, &c->xac);
    fn_80090F9C(&a, &c->xac, &c->pos);
    c->x44 = a.y + c->xd8;
    a.x = c->x70;
    fn_801DCEB0(&v, &a, -c->xcc);
    c->x24 = c->xac + c->x30;
    c->x28 = c->xb0 + c->x34;
    c->x2c = c->xb4 + c->x38;
    c->x4c = c->x24 + v.x;
    c->x50 = c->x28 + v.y;
    c->x54 = c->x2c + v.z;
    fn_8022BAA0(c->x40, &c->x24, &c->x4c, c->xa0);
}

void fn_800C4F1C(Cam_800C4F1C* c) {
    NJS_VECTOR t;
    NJS_VECTOR d;
    NJS_VECTOR e;
    d.x = c->tgt.x - c->pos.x;
    d.y = c->tgt.y - c->pos.y;
    d.z = c->tgt.z - c->pos.z;
    fn_80095360(&c->pos, 0);
    fn_800C4C54(&t, c);
    e.x = t.x - c->pos.x;
    e.y = t.y - c->pos.y;
    e.z = t.z - c->pos.z;
    fn_800914D8(&d, &e, 1.5f, 3.0f);
    c->tgt.x = c->pos.x + d.x;
    c->tgt.y = c->pos.y + d.y;
    c->tgt.z = c->pos.z + d.z;
    fn_8022BAA0(c->x40, c->x24, &c->tgt, c->xa0);
}

void fn_800C5014(Obj_800C5014* o, Src_800C5014* s) {
    NJS_VECTOR t;
    s32 a;
    if (o->x108 != NULL) {
        o->x108->x14 |= 0x8000;
    }
    if (!(o->flags & 4)) {
        if (!(s->flags & 4)) {
            o->x34 = 14.0f;
        }
        if (s->flags & 0x800) {
            o->xcc = s->x54;
            o->xd0 = s->x5c;
        } else {
            o->xcc = 30.0f;
            o->xd0 = 10.0f;
        }
        if (!(s->flags & 0x1000)) {
            o->xe6 = 8;
        } else {
            o->xe6 = s->x62;
        }
    }
    fn_800C4C54(&t, o);
    o->tgt.x = t.x;
    o->tgt.y = t.y;
    o->tgt.z = t.z;
    if (o->flags & 1) {
        a = 6;
    } else {
        a = 4;
    }
    fn_800967F0(o, a, 6);
}

void fn_800C51BC(Obj_800C51BC* o, Src_800C51BC* s) {
    s32 a;
    if (o->x108 != NULL) {
        o->x108->x14 |= 0x8000;
    }
    if (!(o->flags & 4)) {
        if (s->flags & 0x40) {
            o->xb8 = s->x4c;
        } else {
            o->xb8 = 8.0f;
        }
        if (s->flags & 0x80) {
            o->xbc = s->x50;
        } else {
            o->xbc = 11.0f;
        }
        if (!(s->flags & 4)) {
            o->x30.x = 0.0f;
            o->x30.y = 14.0f;
            o->x30.z = 0.0f;
        }
    }
    o->xac.x = o->pos.x;
    o->xac.y = o->pos.y;
    o->xac.z = o->pos.z;
    o->tgt.x = o->pos.x + o->x58.x;
    o->tgt.y = o->pos.y + o->x58.y;
    o->tgt.z = o->pos.z + o->x58.z;
    o->x24.x = o->pos.x + o->x30.x;
    o->x24.y = o->pos.y + o->x30.y;
    o->x24.z = o->pos.z + o->x30.z;
    if (o->flags & 1) {
        a = 6;
    } else {
        a = 4;
    }
    fn_800967F0(o, a, 6);
}

void fn_800C52F0(Obj_800C52F0* o)
{
    f32 dx, dy, dz, d2, s;

    fn_80094F90(o->pos, o);
    o->out[0] = o->pos[0] + o->off[0];
    o->out[1] = o->pos[1] + o->off[1];
    o->out[2] = o->pos[2] + o->off[2];
    dx = o->tgt[0] - o->out[0];
    dy = o->tgt[1] - o->out[1];
    dz = o->tgt[2] - o->out[2];
    d2 = dx * dx + dy * dy + dz * dz;
    if (256.0f > d2) {
        s = fn_80291A5C(d2);
        s = (16.0f - s) / s;
        o->res[0] = dx * s + o->tgt[0];
        o->res[1] = dy * s + o->tgt[1];
        o->res[2] = dz * s + o->tgt[2];
    } else {
        o->res[0] = o->tgt[0];
        o->res[1] = o->tgt[1];
        o->res[2] = o->tgt[2];
    }
}

void fn_800C540C(Obj_800C540C* a, Src_800C540C* b)
{
    if (a->sub != NULL) {
        a->sub->flags |= 0x8000;
    }
    if ((a->flags & 4) == 0) {
        if (b->flags & 0x1000) {
            a->xec = 0;
            a->xe8 = b->x60;
            a->x30 = a->x38 = 0.0f;
            a->x34 = b->x64;
        }
        if ((b->flags & 0x10) == 0) {
            a->vel[0] = a->vel[2] = 0.0f;
            a->vel[1] = fn_80116028() - 2.0f;
        }
        if ((b->flags & 8) == 0) {
            fn_80095360(a->pos, 0);
        }
    }
    a->out[0] = a->pos[0] = a->pos[0] + a->vel[0];
    a->out[1] = a->pos[1] = a->pos[1] + a->vel[1];
    a->out[2] = a->pos[2] = a->pos[2] + a->vel[2];
    fn_800967F0(a, (a->flags & 1) ? 6 : 4, 6);
}

void fn_800C6890(Task* task) {
    Ent_800C6890* e = task->work;
    s32 i;

    switch (task->state) {
    case 0:
        for (i = 0; i < 4; i++) {
            if (0.0f != lbl_802E1020[i][e->count / 2]) {
                e->model = *e->ext->items[e->idx * 4 + i + 1];
                e->x1c = lbl_802E1020[i][e->count / 2] / 100.0f - 1.0f;
                fn_801E66E0(e);
            }
        }
        if (++e->count >= 0x18) {
            task->state = 0xFF;
        }
        break;
    case 0xFE:
        break;
    case 0xFF:
        fn_80100B74(task);
        break;
    }
}

void fn_800C69CC(Task* task) {
    Ent_800C69CC* e;
    Ent_800C69CC* n;

    switch (task->state) {
    case 0:
        fn_80227810(((Ent_800C69CC*)task->work)->texlist);
        task->state = 1;
        break;
    case 1:
        if (lbl_80311A60[0]->flags & 0x400) {
            n = fn_801C6180(task, fn_800C6890)->work;
            n->x16e = 3;
            MemCopy(n->f38, lbl_80347450->pos, 0x24);
            n->f38[1] = 200.0f;
            n->f38[7] = 1.0f;
            n->f38[8] = 1.0f;
            n->f38[6] = 1.0f;
            n->texlist = ((Ent_800C69CC*)task->work)->texlist;
            n->x1c8 = ((Ent_800C69CC*)task->work)->x1c8;
            e = task->work;
            n->idx = e->count++;
            if (((Ent_800C69CC*)task->work)->count > 2) {
                ((Ent_800C69CC*)task->work)->count = 0;
            }
        }
        break;
    case 0xFE:
        break;
    case 0xFF:
        fn_802275A4(((Ent_800C69CC*)task->work)->texlist, 0);
        fn_80100B74(task);
        break;
    }
}

void fn_800C7230(Task* task) {
    Ent_800C7230* e;

    ClipZPush();
    lbl_80346788 = -1.0f;
    lbl_8034678C = -60000.0f;
    njClipZ(-1.0f, -60000.0f);
    ClipZSet(-1.0f, -65535.0f);
    e = task->work;
    switch (task->state) {
    case 0:
        if (e->texlist != NULL) {
            fn_80227810(e->texlist);
        }
        e->x176 = 4;
        e->x176 = 3;
        e->x176 = 0;
        e->x18 = 0x100;
        e->x2c = 0;
        e->x8 = 0;
        task->state = 1;
        break;
    case 1:
        if (lbl_80347450 != NULL) {
            e->pos.x = lbl_80347450->pos[0];
            e->pos.y = lbl_80347450->pos[1];
            e->pos.z = lbl_80347450->pos[2];
        }
        fn_801D9BFC();
        fn_801D9C64(lbl_8030E830[0x94 / 4], lbl_8030E830[0x98 / 4], lbl_8030E830[0x9C / 4]);
        fn_801E66E0(e);
        fn_801D9B34();
        break;
    case 0xFE:
        break;
    case 0xFF:
        if (e->texlist != NULL) {
            fn_802275A4(e->texlist, 0);
        }
        fn_80100B74(task);
        break;
    }
    ClipZPop();
}

s32 fn_800C879C(Task* task, u32 n) {
    u32 i;
    State_800C879C* s = task->work;
    Obj_800C879C* o;
    s32 a;
    s32 b;
    List_800C879C* l;

    i = s->cur;
    o = s->objs + i;

    s->cur = i + n;
    while (i < s->list->count && i < s->cur) {
        o->work = (Work*)((u8*)o + 0x40);
        fn_801C610C(o->work);
        l = s->list;
        b = s->xc;
        a = s->x4;
        lbl_80347498 = fn_800C79C4;
        fn_80101060(o, i, l);
        i++;
        lbl_80347498 = fn_8010092C;
        o->work->x104 = (f32)a;
        o->work->x10c = (f32)b;
        o->work->x16a = s->x4;
        o->work->x16b = s->xc;
        o->work->x25c = s->list;
        o->work->x260 = &s->x1c;
        o++;
        lbl_80346D60++;
    }
    if (i >= s->list->count) {
        return 1;
    }
    return 0;
}

s32 fn_800CC3D4(Ent_800CC3D4* e, Table_800CC3D4* t) {
    s32 r = 1;
    Entry_800CC3D4* p;

    e->x1fc++;
    if (t->count <= e->x1fc) {
        switch (t->mode) {
        case 0:
            e->x1fc = t->count - 1;
            break;
        case 1:
            e->x1fc = 0;
            break;
        default:
            e->x1fc = t->count - 1;
            r = 0;
            break;
        }
    }
    p = t->entries;
    p += e->x1fc;
    e->x180 = p->base;
    if (p->range != 0) {
        e->x180 += (s32)((f32)p->range * (0.000030517578125f * (f32)rand()));
    }
    return r;
}

void fn_800CD924(Task* task) {
    Task* parent = task->parent;
    Ent_800CD924* e = task->work;
    Ent_800CD924* src;

    if ((parent->flags & 0x40) == 0) {
        src = parent->work;
        if (src->x184 != 0) {
            task->state = 0xFF;
        }
    } else {
        task->state = 0xFF;
        src = NULL;
    }
    switch (task->state) {
    case 0:
    case 0xFE:
        fn_800C35C4(e, 7);
        fn_800C3518((Obj_800C3518*)e);
        e->x16e = 0;
        fn_801E7DF0(e->model);
        task->state = 1;
        break;
    case 1:
        e->x38 = src->x38;
        e->x3c = src->x3c;
        e->x40 = src->x40;
        e->x44 = src->x44;
        e->x48 = src->x48;
        fn_801E66E0(e);
        fn_801E7E14(e->model, 0, -8, 1);
        break;
    default:
        fn_800C3428((Self_800C3428*)task);
        break;
    }
}

void fn_800CF7BC(V3* v, V3* d, f32 max) {
    f32 nx, ny, nz;
    f32 cur2, new2, max2;

    ny = v->y + d->y;
    nx = v->x + d->x;
    nz = v->z + d->z;
    cur2 = v->x * v->x + v->y * v->y + v->z * v->z;
    new2 = nx * nx + ny * ny + nz * nz;
    if (cur2 > new2) {
        v->x = nx;
        v->y = ny;
        v->z = nz;
    } else {
        max2 = max * max;
        if (9.999999e-09f < max2) {
            if (new2 < max2) {
                v->x = nx;
                v->y = ny;
                v->z = nz;
            } else {
                f32 k = max / fn_80291A5C(new2);
                v->x = nx * k;
                v->y = ny * k;
                v->z = nz * k;
            }
        }
    }
}

f32 fn_800CFAB8(V3* out, Ent_800CFAB8* a, Src_800CFAB8* b, f32 p) {
    f32 v;
    f32 t;

    a->x44 = fn_80091228(0, a->x44, 4.0f);
    a->x6c = fn_80091228(0, a->x6c, 4.0f);
    b->xc = 0.0f;
    if (0.0f > p) {
        t = p / 128.0f;
        v = 0.1f * t + a->x164;
        if (v < 0.5f * -b->x8) {
            v = 0.5f * -b->x8;
        }
        fn_801DCEB0(out, &a->x44, -v);
    } else {
        if (0.0f < p) {
            t = p / 128.0f;
        } else {
            t = 0.15625f + (f32)fabs(b->x10);
        }
        v = 0.5f * t + a->x164;
        if (0.0f <= v) {
            out->z = 0.0f;
            out->y = 0.0f;
            out->x = 0.0f;
            v = 0.0f;
        } else {
            fn_801DCEB0(out, &a->x44, -v);
        }
    }
    a->x164 = v;
    return v;
}

s32 fn_800D1028(Ent_800D1028* e) {
    s32 save;
    u32 ang;
    Aux* a = e->x25c;
    f32 k;

    a->x0 = 0;
    a->xc = a->x10 = a->x14 = 0.0f;
    e->x6c = fn_80091228(0, e->x6c, 4.0f);
    e->x104 = e->x38;
    e->x108 = e->x3c;
    e->x10c = e->x40;
    e->x60 = e->x164 = 0.0f;
    save = e->x48;
    e->x48 = save + e->x6c;
    e->x16c = 1;
    fn_800D0E78(e);
    ang = e->xc0;
    e->xc0 = 0;
    k = (f32)fabs(e->x164);
    k /= a->x8;
    k = 1.0f - k;
    k *= 0.3f;
    e->xb8 = k * njSin(ang);
    if (0.0f < e->x164) {
        if ((ang & 0x7FFFF) != 0) {
            ang = (ang + 0x100) & 0xFFFF;
        }
    } else {
        ang = (ang + 0x100) & 0xFFFF;
    }
    fn_800D0CC8((void *)e);
    e->x16c = 0;
    e->xc0 = ang;
    e->x48 = save;
    return 1;
}

void fn_800D1174(Ent_800D1174* e) {
    s32 save = e->x48;
    u32 ang;
    Aux* a = e->x25c;
    f32 k;

    e->x48 = save + e->x6c;
    e->x16c = 1;
    fn_800D0E78(e);
    ang = e->xc0;
    e->xc0 = 0;
    k = (f32)fabs(e->x164);
    k /= a->x8;
    k = 1.0f - k;
    k *= 0.3f;
    e->xb8 = k * njSin(ang);
    if (0.0f < e->x164) {
        if ((ang & 0x7FFFF) != 0) {
            ang = (ang + 0x100) & 0xFFFF;
        }
    } else {
        ang = (ang + 0x100) & 0xFFFF;
    }
    fn_800D0CC8((void *)e);
    e->x16c = 0;
    e->xc0 = ang;
    e->x48 = save;
}

void fn_800D1A34(Task* task) {
    s32 old;
    Ent_800D1A34* e = task->work;

    fn_8016B96C(e->x3c);
    fn_8016C7F0(e->x6c);
    fn_8016C7D8(e->x48);
    lbl_80347408 = 1;
    lbl_803473EC = 1;
    if (fn_8015E600(e) == 0) {
        old = e->x48;
        fn_80118368(e);
        if (old != e->x48) {
            fn_8016C780(e->x48, e->x48);
        }
        fn_800D1174((Ent_800D1174*)e);
        lbl_8030A794.x54 = e->x38;
        lbl_8030A794.x58 = e->x3c;
        lbl_8030A794.x5c = e->x40;
        lbl_8030A794.x60 = e->x44;
        lbl_8030A794.x64 = e->x48;
        lbl_8030A794.x68 = e->x4c;
    }
    e->x104 = e->x38;
    e->x108 = e->x3c;
    e->x10c = e->x40;
    e->x60 = 0.0f;
    e->x164 = 0.0f;
    if (lbl_80346D8C == 0) {
        lbl_802E1118[0] *= 0.9f;
        lbl_802E1118[1] *= 0.9f;
        lbl_802E1118[2] *= 0.9f;
    }
    lbl_80346D8C = 0;
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

u32 fn_800B2EEC(Obj *o, u32 src, s32 keep0, f32 t) {
    f32 a0;
    f32 a1;
    f32 a2;
    f32 a3;
    f32 inv;
    u32 out;
    u8 *s = (u8 *)&src;
    u8 *d = (u8 *)&out;
    inv = 1.0f - t;
    if (o->flags & 0x200) {
        a0 = (f32)o->col[0] * t;
        a1 = (f32)o->col[1] * t;
        a2 = (f32)o->col[2] * t;
        a3 = (f32)o->col[3] * t;
    } else {
        a3 = 255.0f * t;
        a2 = a3;
        a1 = a3;
        a0 = a3;
    }
    d[3] = (u8)((f32)s[3] * inv + a3);
    d[2] = (u8)((f32)s[2] * inv + a2);
    d[1] = (u8)((f32)s[1] * inv + a1);
    d[0] = keep0 != 0 ? s[0] : (u8)((f32)s[0] * inv + a0);
    return out;
}

void fn_800B9ED8(A *a, B *b) {
    Cfg *cfg = a->link->cfg;
    if (b->flags & 4) {
        b->xf9 = 0;
        fn_8009E910(b->x90, cfg->x50, &b->xf9);
        if (cfg->xa0 == 3) {
            b->x7c = 1;
        } else {
            b->x7c = 0;
        }
        b->x85 = cfg->x54;
        b->x86 = cfg->x58;
        b->x87 = cfg->x5c;
        if (b->x85 != 0 || b->x86 != 0 || b->x87 != 0) {
            b->x80 = 1;
        } else {
            b->x80 = 0;
        }
        b->x8c = a->x100;
        b->x7a = cfg->x140;
    } else {
        a->x20 = fn_8009E4F8(cfg->x54);
        a->x24 = fn_8009E4F8(cfg->x58);
        a->x28 = fn_8009E4F8(cfg->x5c);
        if (-1.0f == a->x20 && -1.0f == a->x24 && -1.0f == a->x28) {
            a->x28 = 0.0f;
            a->x24 = 0.0f;
            a->x20 = 0.0f;
        }
        if (cfg->x64 != 0) {
            a->x176 = 0;
        } else {
            a->x176 = 3;
        }
    }
}

void fn_800BB3DC(Obj_800BB3DC *o, N *n) {
    extern s32 fn_800A10A8(s32 a, s32 b, s32 c);
    extern void fn_800A0E1C(W_800BB3DC *w);
    extern void fn_801C8930(void *p);
    extern void *fn_8009D5BC(void);
    Cfg_800BB3DC *cfg;
    W_800BB3DC *w;
    w = o->work;
    cfg = w->link->cfg;
    if (n->flags & 0x800) {
        w->x176 = 0;
    } else {
        w->x176 = 3;
    }
    n->flags &= ~0x80;
    n->flags &= ~1;
    n->flags &= ~0x2000;
    n->x14 = 0;
    n->xc = 0;
    if (n->x4 > 1) {
        n->x10 = fn_800A10A8(n->x8, n->x14, n->x4) + 1;
    } else {
        n->x10 = -1;
    }
    w->x21d = 0;
    fn_800A0E1C(w);
    w->v11c = w->v50;
    n->a = w->v24c;
    n->b = w->v20c;
    n->x6c = 0;
    n->x68 = 0;
    n->x64 = 0;
    w->x20a = 0;
    w->x208 = 0;
    n->xb4 = w->x2c;
    w->x190 = cfg->x74;
    w->x18c = 0.0f;
    w->x198 = 0;
    if (n->xfe == 1) {
        w->x1fc = -1;
    } else {
        w->x1fc = 0;
    }
    if (!(n->flags & 4) && w->xe4 != NULL && w->x25c == NULL) {
        fn_801C8930(w->xe4);
        w->x25c = fn_8009D5BC();
    }
}

void fn_800BBD4C(Obj_800BBD4C *o, W_800BBD4C *w) {
    extern void fn_800ABEB0();
    extern void fn_800ABE9C();
    extern void fn_8015ED90(Obj_800BBD4C *o);
    extern void *fn_801E1A2C(s32 a, s32 b);
    extern void *fn_800A1B50(W_800BBD4C *w);
    extern void fn_80227810(void *p);
    extern void *fn_8008F8FC(W_800BBD4C *w, s32 i);
    extern void fn_8015FE60(s32 a, W_800BBD4C *w, f32 f);
    extern void fn_8015FB98(s32 a, W_800BBD4C *w);
    extern void fn_800BB574(W_800BBD4C *w, void *p);
    CfgFull *cfg;
    Hook *h;
    cfg = w->link->cfg;
    o->x1b = 0xfa;
    w->x26c = 1;
    if (w->link->cfg->count < 0x3c) {
        o->state = 4;
        return;
    }
    fn_8015ED90(o);
    h = w->hook;
    if (h != NULL) {
        h->x1a0 = 0;
        h->x260 = fn_800ABEB0;
        h->x31c = fn_800ABE9C;
    }
    w->x268 = fn_801E1A2C(1, 0x124);
    w->x100 = fn_800A1B50(w);
    if (w->x100 != NULL) {
        fn_80227810(w->x100);
    }
    if (fn_8008F8FC(w, 0) != NULL) {
        fn_8015FE60(0, w, 0.0f);
    }
    if (fn_8008F8FC(w, 1) != NULL) {
        fn_8015FB98(1, w);
    }
    w->x18 |= 0x1800;
    fn_800BB574(w, w->x268);
    if (cfg->x48 != 0) {
        o->work->x1fa = 1;
        o->state = 2;
    } else {
        o->work->x1fb = 1;
        o->state = 1;
    }
}

void fn_800BBEAC(Obj_800BBEAC *o) {
    extern void fn_800BBD4C(Obj_800BBEAC *o, W_800BBEAC *w);
    extern void fn_800BBC3C(Obj_800BBEAC *o, W_800BBEAC *w);
    extern void fn_800BBA70(Obj_800BBEAC *o, W_800BBEAC *w);
    extern void fn_8015EBF4(W_800BBEAC *w);
    extern void fn_801E8580(void *p);
    extern void fn_802275A4(Hk *h, s32 a);
    extern void fn_80100B74(Obj_800BBEAC *o);
    Node_800BBEAC *n;
    W_800BBEAC *w = o->work;
    if (o->flags & 0x20) {
        o->state = 0xff;
    }
    switch (o->state) {
    case 0:
        fn_800BBD4C(o, w);
    case 1:
        fn_800BBC3C(o, w);
        break;
    case 2:
        fn_800BBA70(o, w);
        break;
    case 3:
    case 0xff: {
        Node_800BBEAC *p;
        fn_8015EBF4(w);
        if (w->x25c != NULL) {
            fn_801E8580(w->x25c);
        }
        if (w->x100 != NULL && w->x100->hdr->x8 != 0) {
            fn_802275A4(w->x100, 0);
        }
        if (w->x268 != NULL) {
            if (w->x268 != NULL) {
                fn_801E1784(w->x268);
                w->x268 = NULL;
            }
        }
        p = w->x260;
        if (p != NULL) {
            while (p != NULL) {
                n = p->next;
                if (p != NULL) {
                    fn_801E1784(p);
                }
                p = n;
            }
        }
        w->x268 = NULL;
        w->x264 = 0;
        w->x260 = NULL;
        w->x25c = NULL;
        fn_80100B74(o);
        break;
    }
    case 4:
        if (w->link->cnt->count >= 0x3c) {
            o->state = 0;
        }
        break;
    case 5:
        break;
    }
}

s32 fn_800C5530(s32 a, s32 b) {
    if (lbl_80347450 != NULL && lbl_80347450->p1b8 != NULL) {
        f32 y = lbl_80347450->pos[1];
        if (16.0f > y - lbl_80346D88) {
            u32 t = lbl_80347450->p1b8->h24 & 0xFF00;
            if (t == 0x8B00 || t == 0x8C00) {
                return 4;
            }
        }
        if (-234.0f > y) {
            if ((*(Info*)&lbl_80311AC0).id == 99) {
                return 4;
            }
        }
    }
    if (lbl_80347408 == 0 && fn_8015F1F0(lbl_80347450) == 0) {
        s32 e = lbl_802E0F00[a];
        s32 d;
        if (b & 0xC) {
            if (b & 4) {
                e = (e >> 12) & 3;
                d = 3;
            } else {
                e = (e >> 10) & 3;
                d = -3;
            }
        } else if (b & 3) {
            if (b & 1) {
                e = (e >> 14) & 3;
                d = -1;
            } else {
                e = (e >> 8) & 3;
                d = 1;
            }
        } else {
            d = 0;
        }
        if (d != 0 && e != 3) {
            if (e != 0) {
                s32 t = lbl_802E0F00[a + d] & 0xFF;
                if (e == 1) {
                    a += t;
                } else {
                    a -= t;
                }
            } else {
                a += d;
            }
        }
    }
    return a;
}

s32 fn_800C5C14(Obj_800C5C14* o) {
    s16 n = o->h202;
    if (n <= 1) {
        Key* k;
        o->f20 = o->f250;
        o->f24 = o->f254;
        o->f28 = o->f258;
        k = o->tbl->keys;
        o->h200++;
        if (o->tbl->count <= o->h200) {
            o->h200 = 0;
        }
        k += o->h200;
        o->f250 = (f32)(k->r - 255) / 255.0f;
        o->f254 = (f32)(k->g - 255) / 255.0f;
        o->f258 = (f32)(k->b - 255) / 255.0f;
        o->h202 = k->frames;
    } else {
        f32 t = n;
        o->f20 += (o->f250 - o->f20) / t;
        o->f24 += (o->f254 - o->f24) / t;
        o->f28 += (o->f258 - o->f28) / t;
        o->h202--;
    }
    return 3;
}

s32 fn_800C7DFC(void) {
    s32 b;
    s32 d;
    s32 f;
    s32 e;
    s32 c;
    s32 a;
    s32 ok = 1;
    if (lbl_80346D4C != 0) {
        for (a = 0; a < lbl_80346D4C; a++) {
            if (fn_801CC1A4(lbl_80346D50[a]) == 0) {
                ok = 0;
            }
        }
        if (ok == 1) {
            for (b = 0; b < lbl_80346D4C; b++) {
                lbl_80346D50[b] = fn_80109D74(lbl_80346D50[b]);
            }
            lbl_80346D4C = 0;
        }
    }
    if (lbl_80346D5C == 1 && lbl_80346D58 != 1) {
        for (c = 0; c < 6; c++) {
            for (d = 0; d < 7; d++) {
                if (lbl_803056E8[c][d] != NULL) {
                    if (lbl_803056E8[c][d] != NULL && fn_801CC1A4(lbl_803056E8[c][d]) == 0) {
                        ok = 0;
                    }
                }
            }
        }
        if (ok == 1) {
            for (e = 0; e < 6; e++) {
                for (f = 0; f < 7; f++) {
                    if (lbl_803056E8[e][f] != NULL) {
                        lbl_803056E8[e][f] = fn_801CC0A0(lbl_803056E8[e][f]);
                    }
                }
            }
            lbl_80346D58 = 1;
        }
    }
    return ok;
}

void fn_800CB1D0(Obj_800CB1D0* o) {
    extern s32 fn_802254A0(Vec3_800CB1D0* v, void* p);
    extern void fn_801E17E0(void* p);
    extern s32 fn_800D2924(Obj_800CB1D0* o);
    extern void njPushMatrixEx(void);
    extern void njPopMatrixEx(void);
    extern void fn_80286EE8(void);
    extern void fn_8028B498(void);
    extern void fn_802968BC(void* p);
    extern void fn_8029681C(void* p, s32 a, f32 f);
    extern void fn_802968B8(void);
    extern void fn_801E66E0(Obj_800CB1D0* o);
    Vec3_800CB1D0 v;
    o->f38 += o->f5c;
    o->f3c += o->f60;
    o->f40 += o->f64;
    o->w44 += o->wc0;
    o->w48 += o->wc4;
    if (o->p1b8 != NULL) {
        v.x = o->f38;
        v.y = o->f3c;
        v.z = o->f40;
        if (fn_802254A0(&v, o->p1b8) == 0) {
            v.x = o->f104;
            o->f38 = v.x;
            v.z = o->f10c;
            o->f40 = v.z;
            if (fn_802254A0(&v, o->p1b8) == 0) {
                o->f3c = o->f108;
                o->wc4 = 0;
                o->wc0 = 0;
                o->f64 = 0.0f;
                o->f60 = 0.0f;
                o->f5c = 0.0f;
                fn_801E17E0(o->p1b8);
                o->p1b8 = NULL;
            }
        }
    }
    if (fn_800D2924(o) != 0) {
        if (o->p25c != NULL) {
            njPushMatrixEx();
            fn_80286EE8();
            fn_8028B498();
            fn_802968BC(o->p23c);
            fn_8029681C(o->p260, o->h1fc, o->f24c);
            fn_802968B8();
            njPopMatrixEx();
        }
        if (o->pe4 != NULL) {
            fn_801E66E0(o);
        }
    }
}

s32 fn_800CCCA4(u32 a, u32 b, u32 c) {
    Tbl* t = &(*(Tbl*)&lbl_80305B08);
    Ent* e = t->list;
    s32 n;
    for (n = t->count; n > 0; e++, n--) {
        if (a == e->a && b == e->b && c == e->c) {
            s32 k;
            for (k = --n; k > 0; k--) {
                Ent* nx = e + 1;
                *e = *nx;
                e = nx;
            }
            t->count = t->count - 1;
            (*(Tbl*)&lbl_80305B08).out = t->count + (*(Tbl*)&lbl_80305B08).base;
            return 1;
        }
    }
    return 0;
}

s32 fn_800CCE0C(u32 a, u32 b) {
    Tbl* t = &(*(Tbl*)&lbl_80305B08);
    Ent* e = t->list;
    s32 n;
    for (n = t->count; n > 0; e++, n--) {
        if (a == e->a && b == e->b) {
            s32 k;
            for (k = --n; k > 0; k--) {
                Ent* nx = e + 1;
                *e = *nx;
                e = nx;
            }
            t->count = t->count - 1;
            (*(Tbl*)&lbl_80305B08).out = t->count + (*(Tbl*)&lbl_80305B08).base;
            return 1;
        }
    }
    return 0;
}

s32 fn_800CCF68(u32 a) {
    Tbl* t = &(*(Tbl*)&lbl_80305B08);
    Ent* e = t->list;
    s32 n;
    for (n = t->count; n > 0; e++, n--) {
        if (a == e->a) {
            s32 k;
            for (k = --n; k > 0; k--) {
                Ent* nx = e + 1;
                *e = *nx;
                e = nx;
            }
            t->count = t->count - 1;
            (*(Tbl*)&lbl_80305B08).out = t->count + (*(Tbl*)&lbl_80305B08).base;
            return 1;
        }
    }
    return 0;
}

void fn_800CDEF4(Task_800CDEF4* t) {
    extern void fn_800C35C4(MapObj* a, s32 i);
    extern void* fn_801C5D88(MapObj* a, s32 i);
    extern void fn_800C3518(MapObj* a);
    extern void fn_800C3428(Task_800CDEF4* t);
    extern void fn_801E5DF0(MapObj* a);
    Holder_800CDEF4* h = t->p8;
    MapObj* a = t->p24;
    MapObj* r4;
    s32 i;
    if (!(h->flags & 0x40)) {
        r4 = h->p24;
    } else {
        t->state = 0xFF;
        r4 = NULL;
    }
    switch (t->state) {
    case 0:
    case 0xFE:
        i = a->h200 % 3;
        fn_800C35C4(a, i);
        a->pe8 = fn_801C5D88(a, i);
        a->pec = fn_801C5D88(a, i + 3);
        a->f190 = 0.01f * (f32)a->p1c8->p10->w24;
        fn_800C3518(a);
        t->state = 1;
        break;
    case 1:
        if (r4->w184 == 0) {
            fn_801E5DF0(a);
            if (a->w198 != 0) {
                t->state = 3;
            }
        } else {
            t->state = 3;
        }
        break;
    default:
        if (r4 != NULL) {
            r4->h1fc--;
        }
        fn_800C3428(t);
        break;
    }
}

f32 fn_800CE4E8(A_800CE4E8* a, B_800CE4E8* b) {
    u16 h = b->h24;
    Row* row = &lbl_802E1154[(*(s8(*)[0x120])&lbl_80310A1C)[6]];
    f32 r = 0.0f;
    if (h & 0x8000) {
        switch ((h >> 8) & 0x7F) {
        case 0:
        case 1:
        case 30:
            if (!(row->w4 & 1)) {
                r = 2.0f * row->f0;
            } else if (150.0f >= a->f4) {
                r = 0.5f * row->f0;
            }
            break;
        case 2:
        case 3:
            if (!(row->w4 & 2)) {
                r = 2.0f * row->f0;
            } else if (150.0f >= a->f4) {
                r = 2.0f * row->f0;
            }
            break;
        case 4:
        case 5:
            if (!(row->w4 & 4)) {
                r = 2.0f * row->f0;
            } else if (150.0f >= a->f4 && -150.0f <= a->f4) {
                r = 0.5f * row->f0;
            }
            break;
        case 6:
        case 7:
            if (!(row->w4 & 8)) {
                r = 2.0f * row->f0;
            } else if (150.0f >= a->f4 && -150.0f <= a->f4) {
                r = 0.5f * row->f0;
            }
            break;
        }
    }
    return r;
}

void fn_800CF554(Pos* p, Q* q, Mover* m, Flags* f) {
    s32 hit = 0;
    if (150.0f >= q->f4 && (f->h24 & 0x8000)) {
        s32 sel;
        switch ((f->h24 >> 8) & 0x7F) {
        case 0:
        case 2:
            sel = 1;
            break;
        case 1:
        case 3:
        case 30:
            sel = 2;
            break;
        case 4:
        case 6:
            if (-150.0f <= q->f4) {
                sel = 1;
            } else {
                sel = 0;
            }
            break;
        case 5:
        case 7:
            if (-150.0f <= q->f4) {
                sel = 2;
            } else {
                sel = 0;
            }
            break;
        default:
            sel = 0;
            break;
        }
        if (sel == 1) {
            hit = fn_800CEDDC(q, m, f);
        } else if (sel == 2) {
            hit = fn_800CE67C(q, m, f);
        }
    }
    if (hit == 0) {
        m->f5c *= 0.9f;
        m->f64 *= 0.9f;
    } else {
        lbl_80346D90 = -1.0f;
    }
    p->x += m->f5c;
    p->z += m->f64;
}

void fn_800D29B4(s32 val, Part_800D29B4* group, s32* list) {
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
    if (list != NULL && (n = list[0]) > 0) {
        p = list + 1;
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
        flags = (*(Pad*(*)[])&lbl_80311A60)[lbl_8034757C]->flags;
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
        if ((lbl_80311A00[1] & (flags = (*(Pad*(*)[])&lbl_80311A60)[lbl_8034757C]->flags)) || (flags & 0x1000)) {
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

void fn_800BA04C(W_800BA04C *w, S_800BA04C *s)
{
    if (s->wc >= s->hfa && w->h1fc == 0) {
        if (s->flags & 0x400) {
            s->wc = 0;
            s->w14 = 0;
            s->w10 = 0;
            w->mode = 0;
            s->flags &= ~0x80;
            s->flags &= ~0x2000;
            w->x11c = w->x50;
            w->y11c = w->y50;
            w->z11c = w->z50;
        } else {
            s->flags |= 1;
        }
    } else {
        s->wc++;
    }
    if (!(s->flags & 1) && !(s->flags & 0x200) && w->lim != 0 && w->mode != 3) {
        if (w->mode == 1) {
            w->cur = 0.0f;
        } else if (w->mode == 2) {
            w->cur = (f32)w->lim->w4 - 1.0f;
        }
        if (0.0f < w->vel) {
            if (w->cur >= (f32)w->lim->w4 - 1.001f) {
                w->vel = 0.0f;
                w->mode = 3;
            } else if (w->cur + w->vel > (f32)w->lim->w4 - 1.0f) {
                w->mode = 2;
            }
        } else {
            if (w->cur < fabs(w->vel)) {
                if (0.0f != w->cur) {
                    w->mode = 1;
                } else {
                    w->vel = 0.0f;
                    w->mode = 3;
                }
            } else if (w->cur + w->vel < 0.0f) {
                w->mode = 1;
            }
        }
    }
}

void fn_800BA220(W_800BA220 *w, X_800BA220 *x)
{
    V3_800BA220 sa;
    V3_800BA220 sc;
    V3_800BA220 sb;
    f32 save = w->f1c;
    f32 zero = 0.0f;
    Node_800BA220 *n = w->list;
    Node_800BA220 *prev = 0;

    sa = w->a;
    sb = w->b;
    sc = w->c;
    w->w2c = 0;
    if (x->f11c != zero) {
        fn_800D208C(x->w118, x->f11c);
    }
    while (n != 0) {
        n->h2e--;
        if (n->h2e <= x->h110) {
            Node_800BA220 *next;
            w->a = n->a;
            w->b = n->b;
            w->c = n->c;
            w->f18c = n->f30;
            w->f1c = n->f24;
            fn_8009D994(w, n->h2c, w->hdr->w4);
            next = n->next;
            if (n->h2e <= 0) {
                if (n != 0) {
                    fn_801E1784(n);
                    n = 0;
                }
                if (prev != 0) {
                    prev->next = 0;
                } else {
                    w->list = 0;
                }
            } else {
                prev = n;
                n->f24 = n->f24 - n->f28;
                n = next;
            }
        } else {
            prev = n;
            n = n->next;
        }
    }
    if (x->f11c != zero) {
        fn_800D2048();
    }
    w->f1c = save;
    w->a = sa;
    w->b = sb;
    w->c = sc;
}

void fn_800BBA70(Obj_800BBA70 *o, W_800BBA70 *w)
{
    extern void fn_800ADED0(W_800BBA70 *w, Hook_800BBA70 *h);
    extern void fn_8015E600(W_800BBA70 *w);
    extern void fn_800BB3DC(Obj_800BBA70 *o, Buf_800BBA70 *b);
    extern void fn_800BAC88(W_800BBA70 *w, Buf_800BBA70 *b);
    extern void fn_800BA820(W_800BBA70 *w, Buf_800BBA70 *b);
    extern void fn_800BA564(W_800BBA70 *w, Buf_800BBA70 *b);
    extern void fn_800BA04C(W_800BBA70 *w, Buf_800BBA70 *b);
    Hook_800BBA70 *h = w->hook;
    Buf_800BBA70 *b = w->buf;
    s32 t;
    if (w->b1fa != 0) {
        fn_800ADED0(w, h);
    }
    fn_8015E600(w);
    if (w->b1fa != 0) {
        fn_800BB3DC(o, b);
        w->b1fa = 0;
    }
    fn_800BAC88(w, b);
    t = w->hook != 0 ? w->hook->w1a0 : 1;
    if (t == 0) {
        V3_800BBA70 sb;
        V3_800BBA70 sc;
        V3_800BBA70 sa;
        sa = w->a;
        sb = w->b;
        sc = w->c;
        w->a = b->a40;
        w->b = b->a4c;
        w->c = w->d;
        if (b->flags & 4) {
            fn_800BA820(w, b);
        } else {
            fn_800BA564(w, b);
        }
        w->a = sa;
        w->b = sb;
        w->c = sc;
    }
    fn_800BA04C(w, b);
    if (b->flags & 1) {
        o->state = 1;
    }
}

f32 fn_800C2650(Arg_800C2650 *a)
{
    extern void *lbl_803470E8;
    extern void *lbl_803470F0;
    extern void *lbl_803470F4;
    extern Spr_800C2650 *fn_801D68C4(void *bank, s32 n);
    extern void fn_801D4F0C(Spr_800C2650 *s, s32 a, s32 b, s32 c, f32 f1, f32 f2, f32 f3, f32 f4);
    extern void fn_801D52A8(Spr_800C2650 *s, s32 a, s32 b, f32 f1, f32 f2, f32 f3, f32 f4);
    f32 x = a->f0;
    Spr_800C2650 *s;

    s = fn_801D68C4(lbl_803470F0, 0x51);
    s->f14 = a->h4;
    s->f18 = a->h6;
    fn_801D4F0C(s, 0, 0, 1, x, 0.0f, a->fc, a->f8);
    x += 10.0f;
    s = fn_801D68C4(lbl_803470E8, 7);
    s->f14 = a->h4;
    s->f18 = a->h6;
    fn_801D4F0C(s, 0, 0, 0, x, 0.0f, a->fc, a->f8);
    x += 100.0f;
    s = fn_801D68C4(lbl_803470F0, 0x54);
    s->f14 = a->h4;
    s->f18 = a->h6;
    fn_801D4F0C(s, 0, 0, 1, x, 0.0f, a->fc, a->f8);
    x += 20.0f;
    s = fn_801D68C4(lbl_803470F4, 0x47);
    s->f14 = a->h4;
    s->f18 = a->h6;
    fn_801D52A8(s, 0, 0, x, 0.0f, a->fc, a->f8);
    x += 20.0f;
    return x;
}

void fn_800C381C(Obj_800C381C *o, Src_800C381C *s)
{
    extern void fn_8009539C(void *a, void *b);
    extern void fn_80090F9C(A3_800C381C *out, V3_800C381C *a, V3_800C381C *b);
    extern f32 fn_80090FF0(V3_800C381C *a, V3_800C381C *b);
    V3_800C381C t;
    A3_800C381C ang;
    s32 a;

    if (o->sub != 0) {
        o->sub->h14 |= 0x8000;
    }
    o->w10c = 0;
    o->flags &= ~0x20;
    t.x = o->pos.x;
    t.y = o->pos.y + o->f34;
    t.z = o->pos.z;
    if (!(o->flags & 4)) {
        if (!(s->flags & 4)) {
            o->f30 = o->f38 = 0.0f;
            o->f34 = 14.0f;
        }
        o->w78 = 0;
        o->fd0 = (s->flags & 0x800) ? s->f5c : 50.0f;
        fn_8009539C(&o->v4c, &o->w40);
        t.x = o->pos.x;
        t.y = o->pos.y + o->f34;
        t.z = o->pos.z;
        if (s->flags & 0x10) {
            o->v64.x = o->pos.x + o->v58.x;
            o->v64.y = o->pos.y + o->v58.y;
            o->v64.z = o->pos.z + o->v58.z;
            s->flags &= ~0x10;
            s->flags |= 8;
        }
        if (s->flags & 8) {
            fn_80090F9C(&ang, &t, &o->v64);
            if (!(s->flags & 0x800)) {
                o->fd0 = fn_80090FF0(&t, &o->v64);
            }
        } else {
            fn_80090F9C(&ang, &t, &o->v4c);
        }
        if (!(s->flags & 0x20)) {
            o->w70 = ang.x;
            o->w74 = ang.y;
        } else {
            o->w74 = ang.y;
        }
    }
    o->vf0.x = t.x;
    o->vf0.y = t.y;
    o->vf0.z = t.z;
    o->fcc = o->fd4 = o->fd0;
    o->v4c.x = o->v64.x;
    o->v4c.y = o->v64.y;
    o->v4c.z = o->v64.z;
    o->w40 = o->w70;
    o->w44 = o->w74;
    o->w48 = o->w78;
    if (o->flags & 1) {
        a = 6;
    } else {
        a = 4;
    }
    fn_800967F0(o, a, 6);
}

void fn_800C41D0(Obj_800C41D0 *o, Src_800C41D0 *s)
{
    s32 a;
    s32 r;

    if (o->sub != 0) {
        o->sub->h14 |= 0x8000;
    }
    o->vac.x = o->pos.x;
    o->vac.y = o->pos.y;
    o->vac.z = o->pos.z;
    if (!(o->flags & 4)) {
        if (s->flags & 0x40) {
            o->fb8 = s->f4c;
        } else {
            o->fb8 = 8.0f;
        }
        if (s->flags & 0x80) {
            o->fbc = s->f50;
        } else {
            o->fbc = 11.0f;
        }
        if (!(s->flags & 4)) {
            o->v30.x = 0.0f;
            o->v30.y = 14.0f;
            o->v30.z = 0.0f;
        }
        if (s->flags & 0x20) {
            o->wd8 = o->w74;
        } else {
            o->wd8 = o->w70 = o->w78 = 0;
        }
        if (s->flags & 0x100) {
            o->fcc = s->f54;
        } else {
            o->fcc = 100.0f;
        }
    }
    o->v24.x = o->pos.x + o->v30.x;
    o->v24.y = o->pos.y + o->v30.y;
    o->v24.z = o->pos.z + o->v30.z;
    r = fn_80095110();
    if (r >= 0) {
        o->w74 = r + o->wd8;
    }
    o->w40 = o->w70;
    o->w44 = o->w74;
    o->w48 = o->w78;
    fn_801DCEB0(&o->v4c, &o->w40, -o->fcc);
    o->v4c.x = o->v4c.x + o->v24.x;
    o->v4c.y = o->v4c.y + o->v24.y;
    o->v4c.z = o->v4c.z + o->v24.z;
    if (o->flags & 1) {
        a = 6;
    } else {
        a = 4;
    }
    fn_800967F0(o, a, 6);
}

void fn_800C43A0(Obj_800C43A0 *o)
{
    extern s32 lbl_8030EA10[3];
    extern s32 fn_801E7B2C(Mot_800C43A0 *m, void *a, void *b, f32 frame);
    extern void fn_801DCE18(void *in, void *out, s32 ang);
    extern void fn_80090F9C(void *out, V3_800C43A0 *a, V3_800C43A0 *b);
    s32 ang[3];
    V3_800C43A0 tmp;
    f32 lim;

    if (o->mA != 0) {
        fn_801E7B2C(o->mA, &tmp, 0, o->frameA);
        fn_801DCE18(&o->v58, &tmp, o->w74);
        if (0.0f == o->speedA) {
            o->mA = 0;
        } else {
            o->frameA = o->frameA + o->speedA;
            lim = (f32)(o->mA->count - 1);
            if (o->frameA > lim) {
                o->frameA = lim;
                o->speedA = 0.0f;
            }
        }
    }
    o->v7c.x = o->v64.x + o->v58.x;
    o->v7c.y = o->v64.y + o->v58.y;
    o->v7c.z = o->v64.z + o->v58.z;
    if (o->mB != 0) {
        fn_801E7B2C(o->mB, &tmp, 0, o->frameB);
        fn_801DCE18(&o->v30, &tmp, o->wd8);
        if (0.0f == o->speedB) {
            o->mB = 0;
        } else {
            o->frameB = o->frameB + o->speedB;
            lim = (f32)(o->mB->count - 1);
            if (o->frameB > lim) {
                o->frameB = lim;
                o->speedB = 0.0f;
            }
        }
    }
    o->v24.x = o->pos.x + o->v30.x;
    o->v24.y = o->pos.y + o->v30.y;
    o->v24.z = o->pos.z + o->v30.z;
    fn_80090F9C(ang, &o->v24, &o->v7c);
    if (lbl_8030EA10[0] == 0) {
        o->w88 = ang[0];
    }
    if (lbl_8030EA10[1] == 0) {
        o->w8c = ang[1];
    }
}

void fn_800C4584(Obj_800C4584 *o, Src_800C4584 *s)
{
    R_800C4584 *r;
    Tbl_800C4584 *t;

    if (o->sub != 0) {
        o->sub->h14 |= 0x8000;
    }
    o->v30.z = 0.0f;
    o->v30.y = 0.0f;
    o->v30.x = 0.0f;
    o->v58.z = 0.0f;
    o->v58.y = 0.0f;
    o->v58.x = 0.0f;
    o->mB = 0;
    o->mA = 0;
    o->h4 = 0;
    if (s->flags & 0x1000) {
        r = fn_801092C0(s->u60, 0);
        if (r != 0) {
            if (!(s->flags & 8)) {
                o->v64.x = r->v44.x;
                o->v64.y = r->v44.y;
                o->v64.z = r->v44.z;
            }
            if (!(s->flags & 0x20)) {
                o->w78 = 0;
                o->w70 = 0;
                o->w74 = (s32)(182.04445f * r->f54);
            }
            t = r->tbl;
            o->mA = (t->count > s->h62) ? t->items[s->h62] : 0;
            if (o->mA != 0) {
                o->frameA = 0.0f;
                o->speedA = s->f64;
                o->h4 = 5;
            }
        }
    }
    if (s->flags & 0x2000) {
        r = fn_801092C0(s->u68, 0);
        if (r != 0) {
            if (!(s->flags & 2)) {
                o->pos.x = r->v44.x;
                o->pos.y = r->v44.y;
                o->pos.z = r->v44.z;
            }
            if (s->flags & 0x200) {
                o->wd8 = s->u58;
            } else {
                o->wd8 = (s32)(182.04445f * r->f54);
            }
            t = r->tbl;
            o->mB = (t->count > s->h6a) ? t->items[s->h6a] : 0;
            if (o->mB != 0) {
                o->frameB = 0.0f;
                o->speedB = s->f6c;
                o->h4 = 5;
            }
        }
    }
    o->v4c.x = o->v64.x;
    o->v4c.y = o->v64.y;
    o->v4c.z = o->v64.z;
    o->w40 = o->w70;
    o->w44 = o->w74;
    o->w48 = o->w78;
}

void fn_800C48C4(Obj_800C48C4 *o, Src_800C48C4 *s)
{
    extern void fn_80095360(void *p, s32 mode);
    extern void fn_80090F9C(A3_800C48C4 *out, V3_800C48C4 *a, V3_800C48C4 *b);
    extern f32 fn_80291A5C(f32 x);
    A3_800C48C4 ang;
    V3_800C48C4 tmp;
    s32 a;

    if (o->sub != 0) {
        o->sub->h14 |= 0x8000;
    }
    fn_80095360(&tmp, 0);
    o->vac.x = o->pos.x;
    o->vac.y = tmp.y;
    o->vac.z = o->pos.z;
    if (!(o->flags & 4)) {
        if (!(s->flags & 4)) {
            o->v30.y = 14.0f;
        }
        o->fb8 = (s->flags & 0x40) ? s->f4c : 4.0f;
        o->fbc = (s->flags & 0x80) ? s->f50 : 8.0f;
        if (s->flags & 0x100) {
            o->fcc = s->f54;
        } else {
            f32 dx = (o->pos.x + o->v30.x) - o->v64.x;
            f32 dy = (o->pos.y + o->v30.y) - o->v64.y;
            f32 dz = (o->pos.z + o->v30.z) - o->v64.z;
            o->fcc = fn_80291A5C(dx * dx + dy * dy + dz * dz);
        }
        o->fd4 = o->fcc;
        if (!(s->flags & 0x20)) {
            o->w70 = 0;
        }
        o->wd8 = (s->flags & 0x200) ? s->u58 : 0;
    }
    fn_80090F9C(&ang, &o->vac, &tmp);
    o->w74 = ang.y + o->wd8;
    ang.x = o->w70;
    fn_801DCEB0(&tmp, &ang, -o->fcc);
    o->v24.x = o->vac.x + o->v30.x;
    o->v24.y = o->vac.y + o->v30.y;
    o->v24.z = o->vac.z + o->v30.z;
    o->v64.x = o->v24.x + tmp.x;
    o->v64.y = o->v24.y + tmp.y;
    o->v64.z = o->v24.z + tmp.z;
    o->v4c.x = o->v64.x;
    o->v4c.y = o->v64.y;
    o->v4c.z = o->v64.z;
    o->w40 = o->w70;
    o->w44 = o->w74;
    o->w48 = o->w78;
    if (o->flags & 1) {
        a = 6;
    } else {
        a = 4;
    }
    fn_800967F0(o, a, 6);
}

void fn_800CAF6C(Obj_800CAF6C *o)
{
    extern s32 fn_8009761C(s32 a, s32 b);
    extern s32 fn_802254A0(V3_800CAF6C *v, void *p);
    extern void fn_801E17E0(void *p);
    extern s32 fn_800D2924(Obj_800CAF6C *o);
    extern void fn_801E66E0(Obj_800CAF6C *o);
    V3_800CAF6C v;
    s32 d;
    s32 e;
    s32 b;
    s32 a;

    o->f38 = o->f38 + (o->f158 * o->f24c + o->f5c);
    o->f3c = o->f3c + o->f60;
    o->f40 = o->f40 + (o->f160 * o->f24c + o->f64);
    o->w44 = o->w44 + o->wc0;
    o->w48 = o->w48 + o->wc4;
    fn_801DCEB0(&v, &o->w44, o->f60);
    if (0.0f > v.y) {
        v.x = -v.x;
        v.y = -v.y;
        v.z = -v.z;
    }
    if (0.0001f < v.y) {
        o->f5c = v.x;
        o->f60 = o->f60 + v.y;
        o->f64 = v.z;
    }
    o->f60 = o->f60 + o->f15c;
    d = fn_8009761C(0x4000, o->w44);
    e = fn_8009761C(0x10000 - 0x4000, o->w44);
    a = d;
    if (0 > a) {
        a = -a;
    }
    b = e;
    if (0 > b) {
        b = -b;
    }
    if (a > b) {
        d = e;
    }
    if (d != 0) {
        o->w110 = d / 32;
    }
    o->wc0 = o->wc0 + o->w110;
    if (1.0f > o->f24c) {
        o->f24c += 0.016666668f;
    }
    if (o->p1b8 != 0) {
        v.x = o->f38;
        v.y = o->f3c;
        v.z = o->f40;
        if (fn_802254A0(&v, o->p1b8) == 0) {
            v.x = o->f104;
            o->f38 = v.x;
            v.z = o->f10c;
            o->f40 = v.z;
            if (fn_802254A0(&v, o->p1b8) == 0) {
                o->f3c = o->f108;
                o->w44 = o->w44 + d;
                o->w110 = 0;
                o->wc0 = 0;
                o->wc4 = 0;
                o->f64 = 0.0f;
                o->f60 = 0.0f;
                o->f5c = 0.0f;
                o->f160 = 0.0f;
                o->f15c = 0.0f;
                o->f158 = 0.0f;
                fn_801E17E0(o->p1b8);
                o->p1b8 = 0;
            }
        }
    }
    fn_800D2924(o);
    fn_801E66E0(o);
}

void fn_800CD56C(Obj_800CD56C *o)
{
    extern void fn_800CD270(W_800CD56C *w);
    extern void fn_801E5E7C(W_800CD56C *w);
    extern void fn_801E66E0(W_800CD56C *w);
    extern void fn_800C3428(Obj_800CD56C *o);
    W_800CD56C *w = o->w;

    if (o->ref->flags18 & 0x40) {
        o->state = 0xff;
    }
    switch (o->state) {
    case 0:
    case 0xfe:
        fn_800CD270(w);
        o->state = 1;
        break;
    case 1:
        if (w->p1b0 != 0) {
            fn_801E5E7C(w);
            *w->p1b0 = *w->p1b0 + 1;
            if (*w->p1b0 >= w->p1ac->h18) {
                *w->p1b0 = 0;
            }
        } else {
            fn_801E66E0(w);
        }
        if (w->w180 > 0) {
            w->f38 = w->f38 + w->f5c;
            w->f3c = w->f3c + w->f60;
            w->f40 = w->f40 + w->f64;
            w->f60 = w->f60 + w->f15c;
            w->f1c = w->f1c + (-1.0f - w->f1c) / (f32)w->w180;
            w->f50 = w->f50 + w->f11c;
            w->f54 = w->f54 + w->f120;
            w->f58 = w->f58 + w->f124;
            w->w4c = w->w4c + w->w70;
            w->w180 = w->w180 - 1;
        } else {
            o->state = 3;
        }
        break;
    default:
        fn_800C3428(o);
        break;
    }
}

void fn_800CE064(Obj_800CE064* o) {
    extern s32 fn_800D2924(void* w);
    extern Ent_800CE064* fn_80100E10(void* o, void* fn, u16 id, void* p);
    extern void fn_800CDEF4(void);
    extern void fn_800CDA38(void);
    extern void fn_80100B74(void* o);
    extern void fn_801687E0(s32 a, s32 b, s32 c, s32 d, void* e, f32 f1, f32 f2, f32 f3, f32 f4);
    Work_800CE064* w = o->work;
    switch (o->state) {
    case 0:
    case 0xFE: {
        s32 ok = 0;
        Lim_800CE064* p = w->p1c8;
        if (p != 0) {
            if (*p->c10 >= 0xE && *p->c14 >= 0xC && *p->c1c >= 6) {
                ok = 1;
            }
        }
        {
            u8 ns = 1;
            if (ok == 0) {
                ns = 3;
            }
            o->state = ns;
        }
        break;
    }
    case 1:
        w->s180 = ((Lim2_800CE064*)w->p1c8)->p10->v28;
        o->state = 2;
    case 2:
        if (fn_800D2924(w) != 0) {
            s32 t = w->s180;
            if (t > 0) {
                t--;
            }
            w->s180 = t;
            if (t <= 0) {
                if (w->s1fc == 0 && w->s1fe == 0 && w->s206 == 0) {
                    s32 i;
                    Ent_800CE064* e;
                    o->state = 1;
                    for (i = 0; i < 3; i++) {
                        e = fn_80100E10(o, fn_800CDEF4, w->u178, w->p1c8);
                        if (e != 0 && e->c24 != 0) {
                            e->c24->pos[0] = w->pos[0];
                            e->c24->pos[1] = w->pos[1];
                            e->c24->pos[2] = w->pos[2];
                            e->c24->s200 = i;
                            w->s1fc++;
                            if (i == 0) {
                                fn_801687E0(1, 5, 7, 0, e, 0.0f, 0.0f, 0.0f, 500.0f);
                            }
                        }
                    }
                    e = fn_80100E10(o, fn_800CDA38, w->u178, w->p1c8);
                    if (e != 0 && e->c24 != 0) {
                        w->s1fe++;
                    }
                } else {
                    w->s180 = 1;
                }
            }
        }
        break;
    case 4:
    case 0xFF:
        fn_80100B74(o);
        break;
    }
}

f32 fn_800CFBF4(f32 a, f32* out, Obj_800CFBF4* o, Inp_800CFBF4* q) {
    extern s32 fn_8009761C(s32 a, s32 b);
    extern void fn_801DCEB0(f32* out, s32* rot, f32 f);
    f32 r;
    if (0.0f < a) {
        r = 0.1f * (a / 128.0f) + o->f164;
        if (q->f8 < r) {
            r = q->f8;
        }
        o->rot[1] = o->rot[1] - (s32)q->fc;
        o->s6c = fn_80091228((s32)(4.0f * -q->fc), o->s6c, 4.0f);
        o->rot[0] = fn_80091228((s32)(-3712.0f * q->f10), o->rot[0], 4.0f);
        if (0.0f != q->fc) {
            f32 t = -o->f164 / q->f8;
            q->f14 = t * (f32)fn_8009761C(0, o->s6c);
        }
        fn_801DCEB0(out, o->rot, -r);
    } else {
        f32 d;
        if (0.0f > a) {
            d = a / 128.0f;
        } else {
            d = -fabsf(q->f10) - 0.15625f;
        }
        r = 0.5f * d + o->f164;
        o->rot[0] = fn_80091228(0, o->rot[0], 4.0f);
        o->s6c = fn_80091228(0, o->s6c, 4.0f);
        q->fc = 0.0f;
        if (0.0f >= r) {
            out[2] = 0.0f;
            r = 0.0f;
            out[1] = 0.0f;
            out[0] = 0.0f;
        } else {
            fn_801DCEB0(out, o->rot, -r);
        }
    }
    o->f164 = r;
    return r;
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

void fn_800D5584(Work_800D5584* w) {
    extern s32 fn_800C34C8(void* w);
    extern s32 fn_800C3518(void* w);
    extern void fn_801E7DF0(s32 v);
    extern void* fn_801E1C7C(u32 size);
    extern void fn_801DDECC(void* h, s32 a, s32 b, s32 c);
    extern void* fn_801DD984(void);
    extern void fn_801DDE5C(void* h);
    extern void fn_801E17E0(void* p);
    extern void* fn_800D51C0(void* p, s32 k);
    extern void fn_801DD8EC(void* a, s32* b, s32 c, s32 d);
    Src_800D5584* t;
    Tbl_800D5584* tbl;
    s32 flag = 0;
    t = w->p1c8;
    tbl = t->c10;
    if (fn_800C34C8(w) != 0) {
        flag = 1;
    } else if (fn_800C3518(w) != 0) {
        flag = 1;
        t = 0;
    }
    if (flag != 0) {
        fn_801E7DF0(w->e4);
        w->h1ac = fn_801E1C7C(0x20);
        if (w->h1ac != 0) {
            w->h1ac->w0 = 0;
            if (tbl->count > 10) {
                w->s1fc = tbl->v2c;
                w->s202 = 1;
                w->h1ac->s1c = tbl->v24;
                w->h1ac->s1e = tbl->v28;
                if (w->h1ac->s1c > 0 && w->h1ac->s1e > 0) {
                    if (t != 0) {
                        fn_801DDECC(w->h1ac, w->e4, w->p100, t->v20);
                    } else {
                        fn_801DDECC(w->h1ac, w->e4, w->p100, w->p100);
                    }
                }
            }
            w->h1b0 = 0;
            if (w->h1ac->w0 != 0 && w->h1ac->w14 != 0) {
                w->h1b0 = fn_801DD984();
            }
            if (w->h1b0 == 0) {
                fn_801DDE5C(w->h1ac);
                fn_801E17E0(w->h1ac);
                w->h1ac = 0;
            }
        }
    }
    {
        Tbl_800D5584* t2 = w->p1c8->c10;
        BlkA_800D5584* e;
        if (t2->count > 11) {
            e = fn_800D51C0((u8*)t2 + 0x30, 2);
        } else {
            e = 0;
        }
        if (e != 0) {
            s32* d = &e->b;
            s32 n = e->n;
            if (n == ((*d - 1) * 4 + 8) / 4) {
                if (w->h1b0 != 0) {
                    w->p260 = d;
                    fn_801DD8EC(w->h1b0, d + 1, *d, 1);
                }
            }
        }
    }
    {
        Tbl_800D5584* t3 = w->p1c8->c10;
        BlkB_800D5584* e;
        if (t3->count > 11) {
            e = fn_800D51C0((u8*)t3 + 0x30, 3);
        } else {
            e = 0;
        }
        if (e != 0) {
            s32 n = e->n;
            s16* d = &e->b;
            if (n == ((*d - 1) * 4 + 8) / 4) {
                w->p25c = d;
                w->s1fe = 0;
                w->s202 = d[2];
                w->s200 = d[3];
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

s32 fn_800D6E1C(Obj_800D6E1C* o) {
    s8 d;
    s32 res = -1;
    Ent_800D6E1C* e = fn_800CCA6C(8, o->p1c8->v4);
    s8 t;
    s32 r;
    if (e != 0) {
        Sub_800D6E1C* sub = e->sub;
        if (sub != 0) {
            s32 k;
            if (sub->v1c == 0) {
                k = o->s1ee;
            } else {
                k = sub->v1c - 1;
            }
            d = k;
            sub->v0 = 2;
        }
        switch (e->kind >> 16) {
        case 0:
            t = ((s8)d == 0) ? 6 : 8;
            o->b1ed = 0;
            o->b1ec = 1;
            if (t == 6) {
                o->b1ef = 1;
                r = 5;
            } else {
                r = 7;
                o->b1ef = 0;
            }
            res = r;
            break;
        case 1:
            t = ((s8)d == 0) ? 6 : 8;
            o->b1ed = 1;
            o->b1ec = 1;
            if (t == 6) {
                o->b1ef = 1;
                r = 5;
            } else {
                r = 7;
                o->b1ef = 0;
            }
            res = r;
            o->b1ed = 0;
            o->b1ec = 0;
            break;
        case 2:
            t = ((s8)d == 0) ? 6 : 8;
            o->b1ed = 1;
            o->b1ec = 1;
            if (t == 6) {
                o->b1ef = 1;
                r = 5;
            } else {
                r = 7;
                o->b1ef = 0;
            }
            res = r;
            break;
        case 3:
            o->b1ed = 0;
            o->b1ec = 0;
            d = (s8)d;
            if (d == 0) {
                fn_800D6C04(o);
            } else {
                fn_800D6974(o);
            }
            o->s1ee = d;
            res = 2;
            o->b1ef = d;
            break;
        case 4:
            o->flags188 |= 1;
            break;
        case 5:
            o->flags188 &= ~1;
            break;
        }
    }
    return res;
}

void fn_800C3648(Cam_800C3648 *c)
{
    A3_800C3648 ang;
    V3_800C3648 v;
    s32 d;

    if (!(c->h2 & 0x10)) {
        if (fn_8015F1F0(lbl_80347450) == 0) {
            c->w10c = fn_80090DBC(1);
        }
    }
    fn_80095360(&c->pos, &ang);
    c->w3c = ang.y + 0x8000;
    c->ff0 = c->f24 = c->pos.x;
    c->ff4 = c->f28 = c->pos.y + c->f34;
    c->ff8 = c->f2c = c->pos.z;
    if (c->w10c != 0) {
        d = fn_8009761C(c->w74, c->w44);
        if (0 > d) {
            d = -d;
        }
        if (d < 0x1000) {
            if (c->w10c == 0x10000) {
                s32 t;
                c->w10c = fn_8009761C(c->w3c, c->w74);
                t = c->w10c;
                if (t > 0x200) {
                    c->w10c = 0x200;
                } else if (t < -0x200) {
                    c->w10c = -0x200;
                }
            }
            c->w74 = c->w74 + c->w10c;
        }
        c->w10c = 0;
    }
    fn_801DCEB0(&v, &c->w70, -c->fd0);
    c->f64 = c->ff0 + v.x;
    c->f68 = c->ff4 + v.y;
    c->f6c = c->ff8 + v.z;
    c->w40 = fn_80091228(c->w70, c->w40, 6.0f);
    c->w44 = fn_80091228(c->w74, c->w44, 6.0f);
    fn_801DCEB0(&v, &c->w40, -c->fd0);
    c->f4c = c->ff0 + v.x;
    c->f50 = c->ff4 + v.y;
    c->f54 = c->ff8 + v.z;
}

void fn_800C7F64(void)
{
    char buf2[0x40];
    char buf1[0x44];
    Arg_800C7F64 arg;
    s32 j;
    s32 i;
    f32 *p;
    char *sub;
    s32 k;

    lbl_80346D4C = 0;
    if (lbl_80347464 == 1 && (*(s32(*)[5])&lbl_80311AC0)[1] == 99) {
        sprintf(buf1, lbl_803491AC, lbl_8034746C, lbl_802B1410);
        (*(void *(*)[2])&lbl_80346D50)[0] = fn_80109E7C(buf1, 0x7fff);
        lbl_80346D4C = lbl_80346D4C + 1;
    }
    if (lbl_80347464 == 1 && (*(s32(*)[5])&lbl_80311AC0)[1] == 99
        && ((lbl_803475B0 == 1 && lbl_803474B0[1] == 1) || lbl_803473B8 == 1)) {
        lbl_80346D5C = 1;
        lbl_80346D58 = 0;
        if (lbl_803475B0 == 1 && lbl_803474B0[1] == 1) {
            p = &lbl_8030A77C[3];
        } else {
            p = (*(f32(*)[3])&lbl_8030A2E8);
        }
        for (i = 0; i < 6; i++) {
            for (j = 0; j < 7; j++) {
                char *name = lbl_80305790 + i * 0x70 + j * 16;
                sprintf(name, lbl_802B141C, 5 - i, j);
                sub = name + 4;
                for (k = 0; lbl_802E0F40[k].name != 0; k++) {
                    if (strncmp(sub, lbl_802E0F40[k].name, 2) == 0) {
                        name[6] = (*(u8(*)[0x120])&lbl_80310A1C)[lbl_802E0F40[k].idx] + 0x61;
                        break;
                    }
                }
                arg.a = j;
                arg.b = 0;
                arg.c = i;
                if (fn_800C8C54(p, &arg) != 0x4e) {
                    sprintf(buf2, lbl_803491AC, lbl_8034746C, name);
                    (*(void *(*)[6][7])&lbl_803056E8)[i][j] = fn_801CC2A0(buf2, ((void(*)(void))fn_800C81BC), 0);
                } else {
                    (*(void *(*)[6][7])&lbl_803056E8)[i][j] = 0;
                }
            }
        }
    } else {
        lbl_80346D5C = 0;
    }
}

s32 fn_800C5D78(Obj_800C5D78* o) {
    if (o->flags & 1) {
        if (o->pe8 != NULL) {
            fn_801E5E2C();
        } else {
            fn_801E5E7C();
        }
        fn_801DD7D8(o->p1b0);
    } else {
        fn_801E66E0();
    }
    if (o->flags & 2) {
        s16 n = o->h1fe;
        if (n <= 1) {
            Key_800C5D78* k;
            o->f1c = o->f24c;
            k = o->tbl->keys;
            o->h1fc++;
            if (o->h1fc >= (s16)o->tbl->count) {
                o->h1fc = 0;
            }
            k += o->h1fc;
            o->f24c = (f32)(k->v - 255) / 255.0f;
            o->h1fe = k->frames;
        } else {
            f32 t = n;
            o->f1c += (o->f24c - o->f1c) / t;
            o->h1fe--;
        }
    }
    if (o->flags & 4) {
        fn_800C5C14((void *)(o));
    }
    if (o->flags & 8) {
        fn_801E7E14((void *)(o->pe4), ((s16*)o)[0x206 / 2], ((s16*)o)[0x208 / 2], ((s16*)o)[0x204 / 2]);
    }
    return 1;
}

void fn_800C7058(Obj_800C7058 *o)
{
    W_800C7058 *w;
    f32 near;
    f32 far;

    ClipZPush();
    near = lbl_80347560;
    far = -1200.0f;
    lbl_80346788 = near;
    lbl_8034678C = far;
    njClipZ(near, far);
    w = o->w;
    switch (o->state) {
    case 0:
        if (w->p100 != 0) {
            fn_80227810((void *)(w->p100));
        }
        w->w2c = 0;
        w->h176 = 1;
        w->f24c = 0.0f;
        w->f250 = 0.0f;
        w->w48 = 0;
        o->state = 1;
        break;
    case 1: {
        f32 a;
        f32 b;
        s32 m;
        w->f38 = lbl_80347450->pos[0];
        w->f40 = lbl_80347450->pos[2];
        w->f24c = w->f24c + (lbl_80347450->pos[0] - lbl_80347450->save[0]);
        w->f250 = w->f250 - (lbl_80347450->pos[2] - lbl_80347450->save[2]);
        a = fn_80291888(w->f24c);
        w->f24c = w->f24c - a;
        b = fn_80291888(w->f250);
        w->f250 = w->f250 - b;
        m = -1;
        if (0.0f != a && 0.0f != b) {
            m = 2;
        } else if (0.0f != a) {
            m = 0;
        } else if (0.0f != b) {
            m = 1;
        }
        if (m != -1) {
            fn_801E7E14((void *)(w->pe4), (s32)a, (s32)b, m);
        }
        fn_801E66E0((void *)(w));
        break;
    }
    case 0xfe:
        break;
    case 0xff:
        if (w->p100 != 0) {
            fn_802275A4((void *)(w->p100), 0);
        }
        fn_80100B74((void *)(o));
        break;
    }
    ClipZPop();
}

void fn_800CE2B4(void) {
    Ent_800CE2B4* ent = &(*(Ent_800CE2B4(*)[20])&lbl_802E1154)[(*(s8(*)[0x120])&lbl_80310A1C)[6]];
    s32 kind = 0;
    if (ent->tbl[1] != 0) {
        if (((*(Key_800CE2B4*)&lbl_80311AC0).id == 0x7A && (*(Key_800CE2B4*)&lbl_80311AC0).ch == 0x61) || ((*(Key_800CE2B4*)&lbl_80311AC0).id == 0x7D && ((*(Key_800CE2B4*)&lbl_80311AC0).ch == 0x61 || (*(Key_800CE2B4*)&lbl_80311AC0).ch == 0x62 || (*(Key_800CE2B4*)&lbl_80311AC0).ch == 0x64)) || ((*(Key_800CE2B4*)&lbl_80311AC0).id == 0x7F && ((*(Key_800CE2B4*)&lbl_80311AC0).ch == 0x61 || (*(Key_800CE2B4*)&lbl_80311AC0).ch == 0x62))) {
            kind = 3;
        } else {
            u8 buf[24];
            s32 n = fn_8021A1C4(buf);
            s32 m = fn_8021ADA0(&lbl_8030B7F4[0x1568], buf);
            f32 ratio;
            f32 thr = 0.3f;
            s32 v = *(s32*)&lbl_8030B7F4[0x157C];
            if (m > 0) {
                ratio = (f32)v / (f32)m;
            } else {
                ratio = 1.0f;
            }
            if (thr >= ratio) {
                kind = 2;
            } else if (n >= 10) {
                if (rand() & 1) {
                    kind = 0;
                } else {
                    kind = 1;
                }
            } else {
                kind = 0;
            }
        }
    }
    {
        MapObj* c = lbl_80347450;
        lbl_8030CEA0.x1774 = c->pos[0];
        lbl_8030CEA0.x1778 = c->pos[1];
        lbl_8030CEA0.x177c = c->pos[2];
        lbl_8030CEA0.x1780 = 0.005493164f * (f32)(c->s48 & 0xFFFF);
    }
    fn_80100178(ent->tbl[kind]);
    fn_801F7B04(0x7530);
    fn_800EB58C(3);
}

void fn_800D1E58(MapTask* o) {
    MapObj* w = o->work;
    lbl_80347454 = o;
    lbl_80347450 = w;
    switch (o->state) {
    case 0:
    case 0xFE:
        fn_800D1B5C(o);
        lbl_80347408 = 1;
        lbl_803473EC = 1;
        o->state = 1;
        o->f20 = -15000.0f;
        break;
    case 1:
        lbl_80347408 = 1;
        lbl_803473EC = 1;
        if (fn_8015E600((void *)(w)) == 0) {
            fn_80118368((void *)(w));
        }
        if (3.4028235e38f != w->pos[0] && 3.4028235e38f != w->pos[1] && 3.4028235e38f != w->pos[2]) {
            lbl_803473A8 = 1;
            w->save[0] = w->pos[0];
            w->save[1] = w->pos[1];
            w->save[2] = w->pos[2];
            if (!(lbl_80310B3C[0x22] & 0x20000)) {
                fn_8016B9B0(0);
                fn_8016B998(0);
                fn_8016C870(0);
                fn_8016C808(2);
            }
            fn_8016B950(w->pos[1], w->pos[1]);
            fn_8016C7AC(0, 0);
            fn_8016C780(w->s48, w->s48);
            o->state = 2;
        }
        break;
    case 2:
        if (lbl_80310B3C[0x22] & 0x10000) {
            o->state = 3;
        }
        fn_800D1A34((void *)(o));
        w->flags176 |= 0x1000;
        break;
    case 3:
        fn_800D1630();
        break;
    case 0xFF:
        w = o->work;
        if (w->p248 != 0) {
            fn_80217830(w->p248);
            w->p248 = 0;
        }
        fn_8015EBF4(o->work);
        fn_8016ABEC();
        fn_80097660();
        fn_801E17E0((void *)(w->p1c4));
        fn_800D1268((void *)(w));
        fn_80100B74((void *)(o));
        break;
    }
}

f32 fn_800C2D18(Pos_800C2D18* p) {
    Sprite* s;
    f32 x = p->x;

    s = fn_801D68C4(lbl_80346D34, 1);
    s->x = p->u;
    s->y = p->v;
    fn_800FF348(s, 1, x, p->b, p->a);
    x += 0.010000001f;
    s = fn_801D68C4(lbl_80346D34, 3);
    s->x = p->u;
    s->y = p->v;
    fn_801D4C54(s, 0, 0, 1, x, 0.0f, p->b, p->a);
    x += 0.010000001f;
    x += 0.002f;
    s = fn_801D68C4(lbl_80346D30, 1);
    s->x = p->u;
    s->y = p->v;
    fn_801D525C(s, 0, 0, x, 0.0f, p->b, p->a);
    x += 0.002f;
    return x;
}

void fn_800D0CC8(MapObj* a) {
    Script* s = a->p25c;
    Entry* e = s->entries;
    s32 n = s->h2;
    do {
        if (e->h0 != 0) {
            switch (e->h2) {
            case 0: {
                f32 f;
                a->texlist = e->w8;
                a->pe4 = e->wc;
                a->pe8 = e->w10;
                a->pec = e->w14;
                a->f18c = e->f18;
                a->f190 = e->f1c;
                fn_801E5DF0(a);
                e->f18 = a->f18c;
                if (e->w10 != NULL) {
                    f = (f32)(e->w10->w4 - 1);
                    if (e->f18 > f) {
                        e->f18 -= f;
                    }
                }
                break;
            }
            case 1:
            case 2:
            case 5:
                a->texlist = e->w8;
                a->pe4 = e->wc;
                fn_801E66E0(a);
                break;
            case 3: {
                f32 save = a->f1c;
                a->f1c = e->f4;
                a->w1ac = e->w20;
                a->w1b0 = e->w24;
                a->flags176 |= 0x4000;
                fn_801E6438(a);
                a->flags176 &= ~0x4000;
                a->f1c = save;
                break;
            }
            case 4: {
                s32 t4c;
                s32 t44;
                s32 saved;
                t44 = a->w44;
                t4c = a->w4c;
                a->w4c = 0;
                a->w44 = 0;
                saved = lbl_8034753C;
                lbl_8034753C = 1;
                a->texlist = 0;
                a->pe4 = e->wc;
                fn_801E6744(a);
                lbl_8034753C = saved;
                a->w44 = t44;
                a->w4c = t4c;
                break;
            }
            }
        }
        e++;
    } while (--n > 0);
}

void fn_800CD72C(Obj_800CD72C* o) {
    Par_800CD72C* par = o->par;
    Work_800CD72C* w = o->work;
    Src_800CD72C* src;
    if (!(par->flags & 0x40)) {
        src = par->src;
        if (src->flag184 != 0) {
            o->state = 0xFF;
        }
    } else {
        o->state = 0xFF;
        src = 0;
    }
    switch (o->state) {
    case 0:
    case 0xFE:
        fn_800C35C4(w, w->s202 + 4);
        if (fn_800C3518((void *)w) != 0) {
            s16 sz[2];
            sz[1] = 0x20;
            sz[0] = 0x20;
            w->cnt = fn_801DDAB0(&lbl_803474EC, w->e4, w->p100, w->p100, sz);
            w->cur = (s16 *)fn_801DD984();
            if (w->cnt != 0 && w->cur != 0) {
                *w->cur = (s16)((f32)(w->cnt->count - 1) * (0.000030517578f * (f32)rand()));
            }
        }
        w->s16e = 0;
        o->state = 1;
        break;
    case 1:
        w->pos[0] = src->pos[0];
        w->pos[1] = src->pos[1];
        w->pos[2] = src->pos[2];
        w->rot[0] = src->rot[0];
        w->rot[1] = src->rot[1];
        w->rot[2] = src->rot[2];
        fn_801E5E7C(w);
        if (w->cnt != 0 && w->cur != 0) {
            *w->cur += 1;
            if (*w->cur >= w->cnt->count) {
                *w->cur = 0;
            }
        }
        break;
    default:
        fn_800C3428((void *)o);
        break;
    }
}

void fn_800C2F2C(void) { fn_800C2F4C(); }

void fn_800C7018(void* p) {
    fn_800C7058(p);
}

void fn_800C7038(void* p) {
    fn_800C7058(p);
}

s8 fn_800C8C54(f32* pos, Arg_800C7F64* arg) {
    s32* dir = (s32*)arg;
    s32 dx = (s32)((8400.0f - pos[0]) / 2400.0f);
    s32 a;
    s32 dz = (s32)((7200.0f - pos[2]) / 2400.0f);

    dir[0] -= dx;
    if (dir[0] <= -6) {
        dir[0] = 1;
    } else if (dir[0] >= 6) {
        dir[0] = -1;
    }
    dir[2] -= dz;
    if (dir[2] <= -5) {
        dir[2] = 1;
    } else if (dir[2] >= 5) {
        dir[2] = -1;
    }
    a = dir[0];
    if (a == 0 && dir[2] == 0) {
        return 'C';
    }
    if (fabsf((f32)a) <= 1.0f && fabsf((f32)dir[2]) <= 1.0f) {
        return 'A';
    }
    return 'N';
}

int fn_800D1018(CbObj* ctx, CbObj* src) {
    ctx->dst->valC0 = src->valC0;
}

s32 fn_800BE430(Obj_800BE430 *o) {
    s32 r = 0;
    void *p = o->x1c8->x10->x4c;
    /* the redundant p != NULL test is what leaves the dead second beq */
    if (p == NULL || (p != NULL && o->xe4 == NULL)) {
        r = 1;
    }
    return r;
}

s32 fn_800CF944(HitNode *arg)
{
    s32 ret = 0;

    if (lbl_80347450 != NULL && lbl_80347450->p1bc != NULL) {
        ret = fn_80222B30(arg, lbl_80347450->p1bc);
    }
    return ret;
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

static inline void FreeIf(void *p)
{
    if (p != NULL) {
        fn_801E1784(p);
    }
}

void fn_800BF7AC(Obj_800BF7AC *obj)
{
    void *a = obj->f25C;
    void *b = obj->f260;

    if (a != NULL) {
        FreeIf(a);
    }
    if (b != NULL) {
        FreeIf(b);
    }
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

Entry_800CCC48 *fn_800CCC48(u32 a, u32 b)
{
    Entry_800CCC48 *e = (*(Table_800CCC48*)&lbl_80305B08).entries;
    s16 n;

    (*(int*)&lbl_80346D80) = 0;
    n = (*(Table_800CCC48*)&lbl_80305B08).count;
    for (; (*(int*)&lbl_80346D80) < n; (*(int*)&lbl_80346D80)++, e++) {
        if (a == e->a && b == e->b) {
            return e;
        }
    }
    return NULL;
}

void fn_800C32D8(void) {
    if (lbl_80346D3C != 0) {
        fn_801D6944((void *)(lbl_80346D3C));
        fn_801E17E0((void *)(lbl_80346D3C));
        lbl_80346D3C = 0;
    }
    fn_802275A4((void *)((*(S800C32D8a **)&lbl_80346D44)->p4->p20), 0);
    fn_801E17E0((void *)((*(S800C32D8a **)&lbl_80346D44)));
    (*(S800C32D8a **)&lbl_80346D44) = 0;
    fn_801E17E0((void *)(lbl_80346D40));
    lbl_80346D40 = 0;
}

/* The original has no return on the empty-slot path: r3 still holds idx there. */
s32 fn_800C8EC0(s32 idx) {
    void *p;
    void *a;

    if ((*(Mgr_800C8EC0 **)&lbl_80346D70)->tab[idx] != 0) {
        if (fn_8010038C((*(Mgr_800C8EC0 **)&lbl_80346D70)->tab[idx]) == 1) {
            p = fn_8015F1A0(0x752f);
            if (p != 0) {
                a = *(void **)((u8 *)p + 0x1cc);
                a = *(void **)((u8 *)a + 4);
                fn_80227810((void *)(*(void **)((u8 *)a + 0x20)));
            }
            return idx;
        }
        return -1;
    }
}

void *fn_800CC9EC(u32 a, u32 b, u32 min) {
    Entry_800CC9EC *e;
    void *result = 0;
    u32 best = 0xFFFF;

    lbl_80346D80 = 0;
    e = (Entry_800CC9EC*)lbl_80305B08.p00;
    while (lbl_80346D80 < lbl_80305B08.h0a) {
        if (a == e->a && b == e->b) {
            u32 k = (u16)e->key;
            if (k >= min && k <= best) {
                result = e;
                best = k;
            }
        }
        lbl_80346D80++;
        e++;
    }
    return result;
}

void fn_800CD16C(void) {
    Tbl_800CD16C *t = &(*(Tbl_800CD16C*)&lbl_80305B08);
    s16 n = t->npending;
    Ent *dst;
    Ent *src;
    s32 i;
    if (n == 0) {
        return;
    }
    i = n;
    dst = t->list + t->count;
    src = t->pending;
    do {
        *dst++ = *src++;
    } while (--i > 0);
    t->count = t->count + t->npending;
    t->npending = 0;
    (*(Tbl_800CD16C*)&lbl_80305B08).out = t->count;
}

void fn_800B4184(Work_800B4184* w, Emit_800B4184* o) {
    s32 i;
    Node_800B4184* found;
    Node_800B4184* cur;
    Node_800B4184* p;
    s32 n;
    if (o->s5c == 0) {
        if (w->h230 != 0) {
            w->h230--;
            return;
        }
        w->h230 = o->b70;
    }
    if (w->h22e != 0) {
        for (i = 0; i < o->s74; i++) {
            found = 0;
            if (w->h22e == 0) break;
            while (found == 0) {
                p = o->p110;
                cur = p;
                n = (s32)((f32)(w->s1fc * 6) * (0.000030517578125f * (f32)rand()));
                for (; n != 0; n--) {
                    if (cur->p7c == 0 || cur->p7c->p74 != 0) break;
                    cur = cur->p7c;
                }
                if (-1.0f == cur->f44 && p->w58 != 0) {
                    found = cur;
                    w->h22e--;
                    if (o->flags & 2) {
                        cur->flags |= 2;
                        cur->f60 = o->f44 * (0.000030517578125f * (f32)rand());
                    }
                    if (o->flags & 4) cur->flags |= 4;
                    if (o->flags & 8) cur->flags |= 8;
                }
            }
            found->f44 = 0.0f;
            if (w->h22e == 0 && w->s1fc != 0) {
                w->s1fc--;
                w->h22e = w->s1fc * 6;
                if (w->h22e == 0) w->h22e = 1;
                o->p110 = o->p110->p74;
            }
        }
    }
    if (o->s60 <= o->s5e) {
        if (o->flags & 0x20) {
            if (o->s5c >= o->b6b) {
                o->s5c = 0;
                o->s62 = 0;
                o->s5e = 0;
                o->b6f = 1;
            }
        } else {
            o->s5c = 0;
            o->s62 = 0;
            o->s5e = 0;
            o->b6f = 1;
        }
        w->s1fc = o->s6c;
    }
}

void fn_800BA564(Work_800BA564* w, Emit* x) {
    switch (x->mode) {
    case 1:
    case 2:
        fn_800A1948(&w->a, &w->b, 3);
        break;
    case 3:
        fn_800A1948(&w->a, &w->b, 1);
        break;
    case 4:
        fn_800A1948(&w->a, &w->b, 2);
        break;
    case 5:
        fn_800A1948(&w->a, &w->b, 4);
        break;
    }
    njPushMatrixEx();
    fn_80286EE8();
    fn_8028B498();
    njUnitMatrix((void *)(0));
    if (x->mode == 0) {
        njRotateEx(&x->w34, 0);
        njRotateEx(&w->b, 1);
        fn_800A13D8(0, &w->b);
    }
    njRotateEx(&w->w20c, 0);
    njRotateEx(&w->b, 1);
    fn_800A1690(0, &w->w68);
    njPopMatrixEx();
    x->w14 = fn_800A10C4(x->w8, x->w14, x->w4);
    if (x->flags & 0x100) {
        f32 save = w->f18c;
        fn_800BA220((void *)(w), (void *)(x));
        w->f18c = save;
        if ((x->flags & 0x1000) || (x->flags & 0x2000)) {
            if (x->h114 == 0) {
                Buf_800BA564* b = fn_801E1A2C(1, 0x38);
                f32 t;
                if (b == 0) fn_801DBE1C("eff_putmodelEx: Can't allocate memory.");
                b->a = w->a;
                b->b = w->b;
                b->c = w->c;
                t = x->f120 * (1.0f + w->f1c);
                b->f24 = t - 1.0f;
                b->f28 = t / (f32)x->h110;
                b->h2c = x->w14;
                b->h2e = x->h110 + x->h112;
                b->f30 = w->f18c;
                b->next = w->list;
                w->list = b;
                x->h114 = x->h116;
            } else {
                x->h114--;
            }
        }
    }
    {
        s32 q = w->hdr ? w->hdr->w4 : 0;
        if (x->w10 >= 0) {
            fn_8009D994((void *)(w), x->w14, q);
        } else {
            fn_8009D994((void *)(w), 0, q);
        }
    }
}

void fn_800BD668(Work_800BD668* w, Dst* d) {
    Src* s = w->cfg->p10;
    d->hfe = s->w84 + 1;
    d->hfa = s->w84 + s->w80;
    d->hfc = s->w78;
    d->h100 = s->w7c + 1;
    d->h102 = s->w80 + 1;
    d->f104 = 1.0f / (f32)d->h100;
    d->f108 = -1.0f / (f32)d->h102;
    d->hc4 = s->w8c;
    d->hc6 = s->w90;
    d->fb8 = s->fb0;
    d->fbc = s->fb4;
    d->fc0 = s->fb8;
    if (fabs(d->fb8) >= 0.001f || fabs(d->fbc) >= 0.001f || fabs(d->fc0) >= 0.001f) {
        d->flags |= 8;
    } else {
        d->flags &= ~8;
    }
    d->hd4 = s->wa4;
    d->hd6 = s->wa8;
    d->wc8 = s->wbc;
    d->wcc = s->wc0;
    d->wd0 = s->wc4;
    if (d->wd0 != 0 || d->wcc != 0 || d->wc8 != 0) {
        d->flags |= 0x10;
    } else {
        d->flags &= ~0x10;
    }
    d->he4 = s->w94;
    d->he6 = s->w98 + 1;
    d->fd8 = s->fc8;
    d->fdc = s->fcc;
    d->fe0 = s->fd0;
    if (fabs(d->fd8) >= 0.001f || fabs(d->fdc) >= 0.001f || fabs(d->fe0) >= 0.001f) {
        d->flags |= 0x20;
    } else {
        d->flags &= ~0x20;
    }
    d->hf4 = s->w9c;
    d->hf6 = s->wa0 + 1;
    d->fe8 = s->fd4;
    d->fec = s->fd8;
    d->ff0 = s->fdc;
    if (fabs(d->fe8) >= 0.001f || fabs(d->fec) >= 0.001f || fabs(d->ff0) >= 0.001f) {
        d->flags |= 0x40;
    } else {
        d->flags &= ~0x40;
    }
}

static inline s32 FlagTest(u32 b) {
    s32 f = (((u32*)lbl_80310B3C)[b >> 5] & (1 << (b & 31))) != 0;
    f = f != 0;
    return f;
}
static inline void FlagSet(u32 b) {
    ((u32*)lbl_80310B3C)[b >> 5] |= 1 << (b & 31);
}

void fn_800C6474(Obj_800C6474* o) {
    Work_800C6474* w = o->work;
    u32 r = fn_8015F218(w);
    switch (o->state) {
    case 0:
    case 1:
    case 0xfe:
        if (lbl_80347450 == 0 || lbl_803473A8 == 0) {
            o->state = 1;
            break;
        }
    case 2:
        if (fn_800C63A4(w) != 0) {
            if (r == 2) {
                o->state = 5;
            } else {
                o->state = 3;
            }
        } else {
            o->state = 6;
        }
        break;
    case 3:
        if (r == 2) {
            o->state = 5;
        } else {
            V3_800C6474 p;
            r = 0;
            p.x = lbl_80347450->pos[0];
            p.y = lbl_80347450->pos[1];
            p.z = lbl_80347450->pos[2];
            if (fn_802254A0(&p, w->p1b8) != 0) {
                r = 1;
                FlagSet(w->w23c);
            }
            if ((s32)r != 0) o->state = 4;
        }
        break;
    case 4:
        if (r == 2) {
            o->state = 5;
        } else {
            V3_800C6474 p;
            r = 0;
            p.x = lbl_80347450->pos[0];
            p.y = lbl_80347450->pos[1];
            p.z = lbl_80347450->pos[2];
            if (fn_802254A0(&p, w->p1b8) == 0) r = 1;
            if ((s32)r != 0) o->state = 3;
        }
        break;
    case 5:
        if (!FlagTest(w->w23c) && r == 1) {
            V3_800C6474 p;
            r = 0;
            p.x = lbl_80347450->pos[0];
            p.y = lbl_80347450->pos[1];
            p.z = lbl_80347450->pos[2];
            if (fn_802254A0(&p, w->p1b8) != 0) {
                r = 1;
                FlagSet(w->w23c);
            }
            if ((s32)r != 0) {
                o->state = 4;
            } else {
                o->state = 3;
            }
        }
        break;
    case 6:
        break;
    default:
        if (w->p1b8 != 0) {
            fn_801E17E0(w->p1b8);
            w->p1b8 = 0;
        }
        fn_80100B74((void *)(o));
        break;
    }
}

void fn_800C7744(Obj_800C7744* o) {
    Work_800C7744* w = o->work;
    Cell c;
    f32 fx, fz;
    c.a = w->b16a;
    c.b4 = 0;
    c.b = w->b16b;
    fx = 2400.0f * -(f32)c.a + 8400.0f - 1200.0f;
    fz = 2400.0f * -(f32)c.b + 7200.0f - 1200.0f;
    if (lbl_80347450 != 0) {
        fn_800C8C54((void *)(&lbl_80347450->pos[0]), (void *)(&c));
    } else {
        return;
    }
    switch (o->state) {
    case 0:
    case 0xfe:
        if (w->p260->w0 != 1) {
            w->f38 -= fx;
            w->f40 -= fz;
            w->f104 = w->f38;
            w->f108 = w->f3c;
            w->f10c = w->f40;
            o->state = 1;
        } else {
            o->state = 0xff;
        }
        break;
    case 1:
        if (w->p260->w0 != 1) {
            MapObj* t = lbl_80347450;
            f32 px = 8400.0f + (-(2400.0f * (f32)(s32)((8400.0f - t->pos[0]) / 2400.0f)) - 1200.0f);
            f32 pz = 7200.0f + (-(2400.0f * (f32)(s32)((7200.0f - t->pos[2]) / 2400.0f)) - 1200.0f);
            w->f38 = w->f104 + px - 2400.0f * (f32)c.a;
            w->f3c = w->f108;
            w->f40 = w->f10c + pz - 2400.0f * (f32)c.b;
            break;
        }
        o->state = 0xff;
    case 0xff:
        fn_80100B74((void *)(o));
        break;
    }
}

void fn_800CC114(void *p, char *o)
{
    P114 *par = *(P114 **)((char *)p + 0x264);
    int ang;
    float f, g;
    ang = (int)(65536.0f * RND);
    f = par->r * RND;
    *(float *)(o + 0x38) += f * njCos(ang);
    *(float *)(o + 0x40) += f * njSin(ang);
    g = par->base + par->range * RND;
    *(float *)(o + 0x58) = g;
    *(float *)(o + 0x54) = g;
    *(float *)(o + 0x50) = g;
    f = (0.4f < RND) ? -par->a : par->a;
    *(int *)(o + 0xc0) = (int)(182.04445f * (f * RND));
    f = (0.4f < RND) ? -par->b : par->b;
    *(int *)(o + 0xc4) = (int)(182.04445f * (f * RND));
    *(int *)(o + 0x44) = (int)(182.04445f * (360.0f * RND));
    *(int *)(o + 0x48) = (int)(182.04445f * (360.0f * RND));
}

void fn_800CC4F0(void *self, E4F0 *e)
{
    int n;
    int m;
    char *t;
    void *r;
    char *self2 = self;

    e->timer--;
    if (e->timer > 0) return;
    if (fn_800D2924((void *)(e))) {
        if (e->tab != 0) {
            char *ent = (char *)e->tab + 4;
            ent += e->idx * 8;
            n = *(s16 *)(ent + 4) + (int)(*(s16 *)(ent + 6) * RND);
        } else {
            n = e->baseB + (int)(e->spreadB * RND);
        }
        m = e->limit - e->count;
        while (n-- > 0 && m-- > 0) {
            switch (e->kind) {
            case 0: r = fn_801C6180((void *)(self), (void *)(fn_800CBE98)); break;
            case 1: r = fn_801C6180((void *)(self), (void *)(fn_800CBBBC)); break;
            case 2: r = fn_801C6180((void *)(self), (void *)(fn_800CB90C)); break;
            default: r = 0; break;
            }
            if (r != 0) {
                MemCopy((void *)(*(void **)((char *)r + 0x24)), (void *)(e), 0x270);
                fn_800CC114((void *)(e), (void *)(*(void **)((char *)r + 0x24)));
                e->count++;
            }
        }
    }
    if (e->tab != 0) {
        if (fn_800CC3D4((void *)(e), (void *)(e->tab)) == 0) {
            *((u8 *)self + 0x19) = 3;
        }
        return;
    }
    e->timer = e->baseT + (int)(e->spreadT * RND);
}

void fn_800CC770(void *self, int unused)
{
    E770 *e = *(E770 **)((char *)self + 0x24);
    T770 *t;
    u8 *st = (u8 *)self + 0x19;
    int r;

    switch (*st) {
    case 0:
        fn_800C3518((void *)(e));
        e->a = 1;
        e->kind = 3;
        fn_800D5210((void *)(self), (void *)(lbl_802E10F0), 5);
        if (e->a != 1 && e->kind != 3) {
            e->f5c = e->f64 = 0.0f;
            switch (fn_8015F218((void *)(e))) {
            case 0:
                r = 3;
                if (e->flags & 2) r = 1;
                *st = r;
                break;
            case 1: *st = 1; break;
            case 2: *st = 3; break;
            }
        } else {
            *st = 4;
        }
        break;
    case 1:
        t = e->tab;
        if (t != 0) {
            e->idx = 0;
            e->timer = t->base;
            if (t->spread != 0) {
                e->timer += (int)(t->spread * RND);
            }
        } else {
            e->timer = e->baseB + (int)(e->spreadB * RND);
        }
        *st = 2;
    case 2:
        if (fn_8015F218((void *)(e)) == 2) {
            *st = 3;
        } else {
            fn_800CC4F0((void *)(self), (void *)(e));
        }
        break;
    case 3:
        if (fn_8015F218((void *)(e)) == 1) {
            *st = 1;
        }
        break;
    case 4:
    case 0xfe:
        break;
    default:
        fn_800C3428((void *)(self));
        break;
    }
}

void fn_800CD270(E270 *e)
{
    Angle ang[3];
    float s;
    s16 sz[2];

    s = 0.3f * RND + 0.1f;
    e->f24c = s;
    fn_801DD5E8((void *)(ang), (void *)(&e->dir));
    fn_801DCF24(&e->vel, ang, e->i20c, s);
    s = 4.0f / s;
    e->pos.x += e->vel.x * s;
    e->pos.y += e->vel.y * s;
    e->pos.z += e->vel.z * s;
    e->f50 = RND;
    e->f54 = RND;
    e->f58 = RND;
    e->f11c = (1.0f - e->f50) / 30.0f;
    e->f120 = (1.0f - e->f54) / 30.0f;
    e->f124 = (1.0f - e->f58) / 30.0f;
    e->i4c = (int)(65536.0f * RND);
    if (0.0f < e->vel.y) {
        fn_800C35C4((void *)(e), 8);
        if (fn_800C3518((void *)(e))) {
            sz[1] = 0x20;
            sz[0] = 0x20;
            e->p1ac = fn_801DDAB0((void *)(((u8*)&lbl_803474EC)), e->e4, e->p100, e->p100, (void *)(sz));
            e->p1b0 = fn_801DD984();
        }
        e->timer = 10;
        e->s16e = 1;
        e->f15c = 0.0f;
        e->i70 = 0;
        e->f54 = e->f58 = e->f50;
    } else {
        fn_800C35C4((void *)(e), e->s206 % 3 + 9);
        fn_800C3518((void *)(e));
        e->f15c = -0.2f;
        e->i70 = (int)(8192.0f * RND);
        if (0x8000 < e->i4c) {
            e->i70 = -e->i70;
        }
    }
    e->s16e = 5;
    e->timer = 30;
}

void fn_800D3C00(Task_800D3C00 *self)
{
    Obj_800D3C00 *e = *(Obj_800D3C00 **)((char *)self + 0x24);
    Hnd *h;
    Ent_800D3C00 *p;
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

Ent_800D6E1C *fn_800CCA6C(s32 a, s32 b) {
    Entry_UNIT0000 *e;
    Ent_800D6E1C *result = 0;
    u32 best = 0xFFFF;

    lbl_80346D80 = 0;
    e = (Entry_UNIT0000*)lbl_80305B08.p00;
    while (lbl_80346D80 < lbl_80305B08.h0a) {
        if (a == e->a && b == e->b) {
            u32 k = (u16)e->key;
            if (k <= best) {
                result = (Ent_800D6E1C *)e;
                best = k;
            }
        }
        lbl_80346D80++;
        e++;
    }
    return result;
}

u32 fn_800CE4B4(void) {
    u32 v = lbl_802E1154[(s8)lbl_80310A1C[6]].w10;
    return (v | -v) >> 31;
}

void fn_800B4EEC(Obj_800B4EEC *o, Work_800B4EEC *w) {
    Cfg_800B4EEC *cfg;
    void *hook;
    Pool *p;
    cfg = w->link->cfg;
    hook = w->hook;
    p = w->x268;
    if (w->x1fa != 0) {
        fn_800ADED0(w, hook);
    }
    fn_8015E600((void *)(w));
    fn_800A0E1C(w);
    if (w->x1fa != 0) {
        fn_800B444C(w, p);
        w->x1fa = 0;
    } else if (cfg->x44 <= 0) {
        p->a = w->v24c;
        p->b = w->v20c;
    }
    switch (p->x6f) {
    case 0:
        fn_800B4184((void *)(w), (void *)(p));
        break;
    case 1:
        fn_800B4038((void *)(w), (void *)(p));
        break;
    case 2:
        fn_800B3D78(w, p);
        break;
    }
    if (p->x6f == 3) {
        if (cfg->x10 != 0) {
            fn_800B444C(w, p);
        } else {
            o->work->x1fb = 1;
            o->state = 1;
        }
    } else {
        fn_800B304C(w, p);
    }
}

static inline BOOL MapInRange(void) {
    s32 in = 0;
    if (lbl_80311AC0.map >= 500 && lbl_80311AC0.map < 600) {
        in = 1;
    }
    return in ? TRUE : FALSE;
}

void fn_800BBC3C(Obj_800BBC3C *o, Work_800BBC3C *w) {
    Node_800BBC3C *p;
    Node_800BBC3C *n;

    if (w->x1fb) {
        if (w->x25c != NULL) {
            fn_801E8580(w->x25c);
            w->x25c = NULL;
        }
        p = w->x260;
        if (p != NULL) {
            while (p != NULL) {
                n = p->next;
                if (p != NULL) {
                    fn_801E1784(p);
                }
                p = n;
            }
            w->x260 = NULL;
        }
        w->x1fb = 0;
    }
    if (!MapInRange() && fn_8015E600((void *)(w)) && (w->x23a & 4) && fn_8015F218((void *)(w)) == 1) {
        o->work->x1fa = 1;
        o->state = 2;
    }
}

void fn_800BF0CC(Emitter *e, Particle *p) {
    *p = e->tmpl;
    p->x24 += e->spreadX * RND;
    p->x28 += e->spreadY * RND;
}

static inline void SlotsRelease(void)
{
    SlotTable *t;
    s32 i;

    if (lbl_803473DC != 0) {
        t = &lbl_803098C8;
        for (i = 0; i < t->count; i++) {
            if (t->buf[i] != NULL) {
                fn_801E17E0(t->buf[i]);
                t->buf[i] = NULL;
            } else {
                fn_801CC0E4(t->res[i]);
            }
        }
    }
}

void fn_800C23CC(void)
{
    if (lbl_803473DC != 0) {
        SlotsRelease();
    }
    if (lbl_80346D20 != NULL && lbl_803474B8 != NULL) {
        MemCopy(lbl_803036E8, lbl_803474B8, 0x2000);
        lbl_803474B8 = lbl_803036E8;
    }
    if (lbl_80346D20 != NULL) {
        fn_801E17E0(lbl_80346D20);
    }
    if (lbl_80346D20 != NULL) {
        fn_801E17E0(lbl_80346D24);
    }
    lbl_80346D24 = NULL;
    lbl_80346D20 = NULL;
    lbl_80346CD0 = NULL;
}

void fn_800C6E68(Task_800C6E68 *task)
{
    Ent_800C6E68 *e;
    struct MapObj *t;
    NJS_VECTOR v;
    f32 d;

    ClipZPush();
    ClipZSet(-1.1f, -5000.0f);
    e = task->ent;
    switch (task->state) {
    case 0:
        if (e->texlist != NULL) {
            fn_80227810(e->texlist);
        }
        e->x176 = 4;
        e->x176 = 0;
        e->x176 = 0;
        e->x2c = 0;
        e->xc = -2000.0f;
        e->x10 = -2100.0f;
        e->x8 = 1;
        e->x16e = 1;
        e->x50 = 5.0f;
        e->x54 = 5.0f;
        e->x58 = 5.0f;
        task->state = 10;
        break;
    case 10:
        t = lbl_80347450;
        if (t == NULL) {
            return;
        }
        v.x = t->pos[0] - e->x38;
        v.y = 0.0f;
        v.z = t->pos[2] - e->x40;
        d = njScalor2(&v);
        if (d <= 4000000.0f) {
            e->x3c = fn_80291A5C(4064256.0f - d);
        }
        fn_801D9BFC();
        fn_801D9CF0(1.0f, 1.0f, 1.0f);
        fn_801E66E0(e);
        fn_801D9B34();
        break;
    case 0xFE:
        break;
    case 0xFF:
        if (e->texlist != NULL) {
            fn_802275A4(e->texlist, 0);
        }
        fn_80100B74(task);
        break;
    }
    ClipZPop();
}

f32 fn_800CF988(V3_800CF988 *out, Ent_800CF988 *a, Src_800CF988 *b, f32 p)
{
    f32 v;
    f32 lim;
    f32 d;

    a->x44 = fn_80091228(0, a->x44, 4.0f);
    if (b->x10 != 0.0f) {
        v = 0.1f * b->x10 + a->x60;
        lim = b->x8 / 2.0f;
        if (v > lim) {
            v = lim;
        } else if (v < -lim) {
            v = -lim;
        }
    } else if (a->x60 != 0.0f) {
        v = a->x60;
        if (0.0f >= p) {
            d = 0.078125f;
        } else {
            d = 0.5f * (p / 128.0f);
        }
        if (0.0f < v) {
            v = v - d;
            if (0.0f > v) {
                v = 0.0f;
            }
        } else {
            v = v + d;
            if (0.0f < v) {
                v = 0.0f;
            }
        }
    } else {
        v = 0.0f;
    }
    a->x60 = v;
    out->y = v;
    out->z = 0.0f;
    out->x = 0.0f;
    return v;
}

s32 fn_800D07F8(Obj_800D07F8* o) {
    V3_800D07F8 v;
    s32 res = 0;
    if (o->p1b8 != NULL) {
        o->p1b8->h30 = 1;
        v.x = o->f38;
        v.y = 1.0f + o->f3c;
        v.z = o->f40;
        res = fn_802256A0(&v, o->p1b8, 0xFFFF, lbl_8030A3C8[0] & 0xFFFF);
        o->p1b8->h30 = 4;
        if (res != 0) {
            lbl_8034740E = o->p1b8->h24 & 0xF;
            lbl_80346D88 = v.y;
        }
        if ((o->p1b8->h24 & 0xFF00) == 0x8300) {
            if (150.0f < o->f3c && 170.0f >= o->f3c) {
                v.x = 0.0f;
                v.y = 0.5f;
                v.z = 0.0f;
                lbl_80346D8C = 1;
                fn_800CF7BC((void *)(lbl_802E1118), (void *)(&v), 4.0f);
            }
        }
    }
    if (lbl_8034740E < 1 || lbl_8034740E > 9) {
        lbl_80347410 = 0.0f;
    } else {
        f32 a = (f32)fabs(o->f164);
        if (0.0f < a) {
            a = a / o->p25c->f8;
            lbl_80347410 += 1.7f * a;
        }
    }
    return res;
}

void fn_800C09E4(Obj_800C09E4 *o)
{
    Param *prm = o->info->param;

    o->f1fa = 0;
    o->f1fb = 0;
    o->f1fc = 0;
    if (o->f25c != NULL) {
        FreeIf(o->f25c);
        o->f25c = NULL;
    }
    fn_800C04D8(o);
    fn_8009D6C0(o, 0, prm->f68);
    if (prm->mode == 1) {
        o->pos[0] = prm->pos[0];
        o->pos[1] = prm->pos[1];
        o->pos[2] = prm->pos[2];
        o->rot[0] = prm->rot[0];
        o->rot[1] = prm->rot[1];
        o->rot[2] = prm->rot[2];
        o->f16c = 1;
    } else {
        o->pos[0] = o->pos[1] = o->pos[2] = 0.0f;
        o->rot[0] = o->rot[1] = o->rot[2] = 0;
        o->f16c = 0;
    }
}

s32 fn_800C63A4(void *o_) {
    Obj_800C63A4 * o = o_;
    s32 ok = 0;
    HookInfo *info = o->info;
    HookCmd *cmd;

    if (info != NULL && (cmd = info->cmd) != NULL) {
        if (cmd->type == 9) {
            if (cmd->flag >= 0x600 && cmd->flag <= 0x77f) {
                o->flag = cmd->flag;
                o->hook = fn_802258BC(0xFFFF, info->id, 2);
                if (o->hook != NULL) {
                    ok = 1;
                }
            } else {
                fn_801DBE1C("eventhook %d setflag %d", info->id, cmd->flag);
            }
        } else {
            fn_801DBE1C("NoOption eventhook %d", info->id);
        }
    }
    return ok;
}

void fn_800C3C78(Work_800C3C78* w) {
    u8 buf[0x34];
    NJS_POINT3 d0;
    NJS_POINT3 d1;
    NJS_POINT3 cross;
    Angle ang[3];
    NJS_POINT3 zero = {0.0f, 0.0f, 0.0f};
    f32 l0, l1, a, t, dx, dy, dz;
    s32 r0, r1;

    fn_80095360(w->sub, 0);
    fn_8009519C(&w->f94, &w->fa0);
    fn_80091040(w->sub, &w->fac);
    w->f24 = 14.0f * w->fa0 + w->fac;
    w->f28 = 14.0f * w->fa4 + w->fb0;
    w->f2c = 14.0f * w->fa8 + w->fb4;
    w->f64 = 20.0f * w->fa0 + w->fac - 40.0f * w->f94;
    w->f68 = 20.0f * w->fa4 + w->fb0 - 40.0f * w->f98;
    w->f6c = 20.0f * w->fa8 + w->fb4 - 40.0f * w->f9c;
    fn_80225930(0xffff, 0xffff, buf);
    fn_80224D08(&w->f64, &w->f24, &w->f64, buf);
    dx = w->f64 - w->f24;
    d0.x = dx;
    dy = w->f68 - w->f28;
    d0.y = dy;
    dz = w->f6c - w->f2c;
    d0.z = dz;
    l0 = fn_80291A5C(dx * dx + dy * dy + dz * dz);
    dx = w->f4c - w->f24;
    d1.x = dx;
    dy = w->f50 - w->f28;
    d1.y = dy;
    dz = w->f54 - w->f2c;
    d1.z = dz;
    l1 = fn_80291A5C(dx * dx + dy * dy + dz * dz);
    fn_80290668(&d0, &zero, &d1, &cross);
    fn_801DD5E8(ang, &cross);
    r0 = fn_801DCFA0(&d0, ang);
    r1 = fn_801DCFA0(&d1, ang);
    if (r0 != r1) {
        a = (f32)fn_8009761C(r0, r1);
        if (0.0f > a) a = -a;
        r1 = fn_800912A8(r0, r1, 0x400, 0x1000);
        t = (f32)fn_8009761C(r0, r1);
        if (0.0f > t) t = -t;
        l0 = (t / a) * (l1 - l0) + l0;
    }
    fn_801DCF24(&d0, ang, r1, l0);
    w->f4c = w->f24 + d0.x;
    w->f50 = w->f28 + d0.y;
    w->f54 = w->f2c + d0.z;
}

void fn_800C4C54(NJS_VECTOR* out, void* c) {
    Work_800C4C54* w = c;
    s32 i;
    NJS_POINT3 v;
    Ang a;
    w->f24 = w->fc + w->f30;
    w->f28 = w->f10 + w->f34;
    w->f2c = w->f14 + w->f38;
    w->f64 = w->fc + w->f58;
    w->f68 = w->f10 + w->f5c;
    w->f6c = w->f14 + w->f60;
    if (fn_800912FC(&w->f64, w->p128)) {
        out->x = w->f64;
        out->y = w->f68;
        out->z = w->f6c;
        return;
    }
    out->x = w->f64 - w->fa0 * w->fd0;
    out->y = w->f68 - w->fa4 * w->fd0;
    out->z = w->f6c - w->fa8 * w->fd0;
    if (fn_800912FC(&out->x, w->p128)) return;
    a.y = fn_801DD4C4(w->f58, w->f60);
    a.y += 0x4000;
    a.z = 0;
    a.x = 0;
    fn_801DCEB0(&v, &a, w->fcc / 5.0f);
    for (i = 1; ; ) {
        out->x = w->f64 + v.x * (f32)i;
        out->y = w->f68 + v.y * (f32)i;
        out->z = w->f6c + v.z * (f32)i;
        if (fn_800912FC(&out->x, w->p128)) break;
        out->x = w->f64 - v.x * (f32)i;
        out->y = w->f68 - v.y * (f32)i;
        out->z = w->f6c - v.z * (f32)i;
        if (fn_800912FC(&out->x, w->p128)) break;
        i++;
        if (w->he6 < i) break;
    }
    if (i == w->he6 + 1) {
        out->x = w->f64 + w->fa0 * w->fd0;
        out->y = w->f68 + w->fa4 * w->fd0;
        out->z = w->f6c + w->fa8 * w->fd0;
    }
}

s32 fn_800CD0B8(s32 a, s32 b, s32 c, s32 d) {
    if (lbl_80305B08.h0e < lbl_80305B08.h08) {
        s32 *e = (s32 *)((u8 *)lbl_80305B08.p00 + (lbl_80305B08.h0a << 4));
        e[0] = a;
        e[1] = b;
        e[2] = c;
        e[3] = d;
        lbl_80305B08.h0a = lbl_80305B08.h0a + 1;
        lbl_80305B08.h0e = lbl_80305B08.h0a + lbl_80305B08.h0c;
        return 1;
    }
    return 0;
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
s32 fn_800D62DC(void* unused, Ent_800D62DC* e, Script_800D5F94_800D62DC* s, s16 words)
{
    s32 ok = 0;
    s32 size = ((s->count - 1) * 8 + 0xc) / 4;
    s32 mode;
    Key_800D5F94_800D62DC* k;
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
            e->x23c = *(*(Node_800D62DC**)((u8*)e->x100->recs + v * 12 + 8))->data;
        } else {
            e->x23c = -1;
        }
        e->x188 |= 1;
        ok = 1;
    }
    return ok;
}

void fn_800D3668(Obj_800D3668* o) {
    NJS_POINT3 v1, v2;
    f32 c;
    s32 q;
    f32 p;
    void *e;
    f32 x;
    x = o->f254;
    p = o->f258;
    q = (s32)(x / p);
    if (q != 0) x = x - p * (f32)q;
    o->f18c = x;
    njPushMatrixEx();
    fn_80286EE8();
    fn_8028B498();
    fn_801E7B2C(o->e8, &v1, 0, o->f18c);
    njUnitMatrix(0);
    njRotateY(0, -(q << 13));
    njCalcPoint(0, &v1, &o->p_b4);
    c = o->f254 + o->f250;
    if (0.0f > o->f250 && 0.0f > c) c += (f32)o->i210;
    p = o->f258;
    e = o->e8;
    q = (s32)(c / p);
    if (q != 0) c = c - p * (f32)q;
    fn_801E7B2C(e, &v1, 0, c);
    njUnitMatrix(0);
    njRotateY(0, -(q << 13));
    njCalcPoint(0, &v1, &v2);
    njPopMatrixEx();
    v2.x = v2.x - o->p_b4.x;
    v2.y = 0.0f;
    v2.z = v2.z - o->p_b4.z;
    fn_801DD5E8(&o->s44, &v2);
    o->s44.ang = (u16)(-o->s44.ang);
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

f32 fn_800C2A88(Arg_800C2650* a) {
    f32 x = a->f0;
    Sprite* s;

    s = fn_801D68C4(lbl_803470F0, 0x50);
    s->x = a->h4;
    s->y = a->h6;
    fn_801D4F0C(s, 0, 0, 1, x, 0.0f, a->fc, a->f8);
    x += 10.0f;
    s = fn_801D68C4(lbl_803470E8, 6);
    s->x = a->h4;
    s->y = a->h6;
    fn_801D4F0C(s, 0, 0, 0, x, 0.0f, a->fc, a->f8);
    x += 100.0f;
    s = fn_801D68C4(lbl_803470F0, 0x53);
    s->x = a->h4;
    s->y = a->h6;
    fn_801D4F0C(s, 0, 0, 1, x, 0.0f, a->fc, a->f8);
    x += 20.0f;
    s = fn_801D68C4(lbl_803470F4, 0x46);
    s->x = a->h4 + 0x20;
    s->y = a->h6 + 0x1f;
    fn_801D52A8(s, 0, 0, x, 0.0f, a->fc, a->f8);
    x += 20.0f;
    s = fn_801D68C4(lbl_803470F0, 0x70);
    s->x = a->h4 + 0x1d0;
    s->y = a->h6 - 0x1b;
    fn_801D4F0C(s, 0, 0, 1, x, 0.0f, a->fc, a->f8);
    x += 20.0f;
    return x;
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

void fn_800B63A4(Obj_800B63A4* o) {
    Work_800B63A4* w = o->work;
    Sub_800B63A4* s;
    f32 t;
    s16 k;
    if (o->flags & 0x20) {
        o->state = 0xff;
    }
    if (lbl_80311AD4[6] == 0xf) {
        o->state = 0xff;
    }
    switch (o->state) {
    case 0:
        o->x1b = 0xfa;
        w->x26c = 1;
        if (w->link->cnt->count < 0x3e) {
            o->state = 4;
            break;
        }
        fn_8015ED90(o);
        s = w->x1d8;
        if (s != NULL) {
            s->x1a0 = 0;
            s->x260 = fn_800ABEB0;
            s->x31c = fn_800ABE9C;
        }
        w->x100 = fn_800A1B50(w);
        if (w->x100 != NULL) {
            fn_80227810((void *)(w->x100));
        }
        fn_800ADF98(w);
        t = lbl_80348F48;
        w->flags |= 0x1000;
        o->x20 = t;
        if (w->link->cnt->x48 == 1) {
            o->work->x1fa = 1;
            o->state = 2;
        } else {
            o->work->x1fb = 1;
            o->state = 1;
        }
    case 1:
        if (w->x1fb != 0) {
            FREE_CHAIN(w);
            w->x1fb = 0;
        }
        if (fn_8015E600((void *)(w)) != 0 && fn_8015F218((void *)(w)) == 1) {
            o->work->x1fa = 1;
            o->state = 2;
        } else {
            break;
        }
    case 2:
        fn_800ADED0((void *)(w), (void *)(w->x1d8));
        fn_8015E600((void *)(w));
        fn_800A0E1C((void *)(w));
        if (w->x1fa == 1) {
            w->x1fa = 0;
            w->x1fb = 0;
            w->x1fc = w->link->cnt->xcc;
            if (w->x1fc == 0) {
                w->x1fc = -1;
            }
            w->x208 = 0;
            w->x20a = 0;
            FREE_CHAIN(w);
        } else {
            fn_800B5A04(w);
            if ((w->x1d8 != NULL ? w->x1d8->x1a0 : 1) == 0 && w->x184 == 0) {
                fn_800B522C(w);
            }
            k = w->x1fc;
            if (k > 0) {
                w->x1fc = k - 1;
            } else if (k == 0) {
                o->work->x1fb = 1;
                o->state = 1;
            } else if (-(k + 1) <= (s16)w->link->cnt->xcc) {
                w->x1fc = k - 1;
            }
        }
        break;
    case 3:
    case 0xff:
        fn_8015EBF4((void *)(w));
        if (w->x100 != NULL && w->x100->hdr->x8 != 0) {
            fn_802275A4((void *)(w->x100), 0);
        }
        FREE_CHAIN(w);
        w->x264 = NULL;
        w->x260 = NULL;
        w->x25c = NULL;
        fn_80100B74((void *)(o));
        break;
    case 4:
        if (w->link->cnt->count >= 0x3e) {
            o->state = 0;
        }
        break;
    case 5:
        break;
    }
}

void fn_800B88F8(Obj_800B88F8* o) {
    Work_800B88F8* w = o->work;
    Sub_800B88F8* s;
    NJS_POINT3 pt;
    s16 k;
    if (o->flags & 0x20) {
        o->state = 0xff;
    }
    if (lbl_80311AD4[6] == 0xf) {
        o->state = 0xff;
    }
    switch (o->state) {
    case 0:
        o->x1b = 0xfa;
        w->x26c = 1;
        if (w->link->cnt->count < 0x27) {
            o->state = 4;
            break;
        }
        fn_8015ED90((void *)(o));
        s = w->x1d8;
        if (s != NULL) {
            s->x1a0 = 0;
            s->x260 = fn_800ABEB0;
            s->x31c = fn_800ABE9C;
        }
        w->x100 = ((Hk_800B88F8*)fn_800A1B50((void *)(w)));
        if (w->x100 != NULL) {
            fn_80227810((void *)(w->x100));
        }
        fn_800ADF98((void *)(w));
        w->x100 = ((Hk_800B88F8*)fn_800A1B50((void *)(w)));
        w->flags |= 0x1000;
        if (w->link->cnt->x48 == 1) {
            o->work->x1fa = 1;
            o->state = 2;
        } else {
            o->work->x1fb = 1;
            o->state = 1;
        }
    case 1:
        if (w->x1fb == 1) {
            FREE_CHAIN_800B88F8(w);
            w->x1fb = 0;
        }
        if (fn_8015E600((void *)(w)) != 0 && fn_8015F218((void *)(w)) == 1) {
            o->work->x1fa = 1;
            o->state = 2;
        } else {
            break;
        }
    case 2:
        fn_800ADED0((void *)(w), (void *)(w->x1d8));
        fn_8015E600((void *)(w));
        fn_800A0E1C((void *)(w));
        if (w->x1fa == 1) {
            w->x1fa = 0;
            w->x1fb = 0;
            w->x1fc = w->link->cnt->x90;
            if (w->x1fc == 0) {
                w->x1fc = -1;
            }
            w->x208 = 0;
            w->x20a = 0;
            FREE_CHAIN_800B88F8(w);
        } else {
            fn_800B847C(w);
            njCalcPoint(0, &w->x24c, &pt);
            o->x20 = lbl_80348F38 + pt.z;
            if ((w->x1d8 != NULL ? w->x1d8->x1a0 : 1) == 0 && w->x184 == 0) {
                fn_800B8028(w);
            }
            k = w->x1fc;
            if (k > 0) {
                w->x1fc = k - 1;
            } else if (k == 0) {
                o->work->x1fb = 1;
                o->state = 1;
            }
        }
        break;
    case 3:
    case 0xff:
        fn_8015EBF4((void *)(w));
        FREE_CHAIN_800B88F8(w);
        if (w->x100 != NULL && w->x100->hdr->x8 != 0) {
            fn_802275A4((void *)(w->x100), 0);
        }
        w->x264 = NULL;
        w->x260 = NULL;
        w->x25c = NULL;
        fn_80100B74((void *)(o));
        break;
    case 4:
        if (w->link->cnt->count >= 0x27) {
            o->state = 0;
        }
        break;
    case 5:
        break;
    }
}

void fn_800B45D4(Work_800B45D4 *w, Fx_800B45D4 *q)
{
    s32 odd;
    s32 per;
    Angle acc;
    Bone_800B45D4 *cur;
    Bone_800B45D4 *prev;
    Bone_800B45D4 *row;
    Bone_800B45D4 *head;
    Angle rx;
    s32 j;
    s32 ring;
    s32 total;
    s32 col;
    s32 idx;
    s32 found;
    Bone_800B45D4 *ref;
    s32 i;
    s32 n;
    Cfg_800B45D4 *cfg = w->link->cfg;
    Lt_800B45D4 *lt;
    s32 lim;
    u8 a1;
    u8 a2;
    Col_800B45D4 c1;
    Col_800B45D4 c0;
    f32 inv;
    Angle rz;
    NJS_POINT3 pt;
    Angle ang[3];
    f32 y;
    s32 cnt;
    Bone_800B45D4 *tail;
    Bone_800B45D4 *p;
    Bone_800B45D4 *nb;

    q->flags = 0;
    lt = w->x268;
    if (lt != NULL) {
        lt->x78 = -1;
        lt->flags |= 0x200;
    }
    q->radius = cfg->x48;
    q->x64 = cfg->x4c;
    lim = cfg->x50;
    if (lim > q->x64) {
        lim = q->x64;
    }
    q->x64 *= 2;
    c0.r = cfg->x54;
    c0.g = cfg->x58;
    c0.b = cfg->x5c;
    c1.r = cfg->x60;
    c1.g = cfg->x64;
    c1.b = cfg->x68;
    a1 = cfg->x6c;
    c1.a = a1;
    c0.a = a1;
    a2 = cfg->x70;
    q->x68 = cfg->x74;
    q->x4c = a1;
    DrawStateDefault2D(&q->ds);
    if (cfg->x78 != 0) {
        q->x100 = 10;
    } else {
        q->x100 = 6;
    }
    q->x6c = cfg->x7c;
    if (cfg->x80 != 0) {
        q->flags |= 1;
    }
    q->x73 = cfg->x84;
    q->x30 = cfg->x88;
    q->x34 = cfg->x8c;
    q->x38 = cfg->x90;
    q->x6e = cfg->x94;
    q->x50 = cfg->x98;
    q->x54 = cfg->x9c;
    q->x58 = cfg->xa0;
    q->x71 = cfg->xa4;
    q->x76 = cfg->xa8;
    q->x7c = cfg->xac;
    q->x2c = cfg->xb0 == 0 ? 1.0f : 1.0f / cfg->xb0;
    q->x72 = cfg->xb4;
    q->x28 = cfg->xb8 == 0 ? 1.0f : 1.0f / cfg->xb8;
    q->x70 = cfg->xbc;
    q->x74 = cfg->xc0;
    q->x6a = cfg->xc4;
    q->x6b = cfg->xc8;
    if (cfg->xcc != 0) {
        q->flags |= 0x40;
    }
    q->x3c = cfg->xd0;
    q->x40 = 182.04445f * cfg->xd4;
    q->x44 = cfg->xd8;
    if (q->x6a) {
        q->flags |= 0x10;
    }
    if (q->x6b) {
        q->flags |= 0x20;
    }
    if (q->x40 != 0) {
        q->flags |= 4;
    }
    if (q->x3c) {
        q->flags |= 8;
    }
    if (q->x44) {
        q->flags |= 2;
    }
    if (q->x50 != 0 || q->x54 != 0 || q->x58 != 0) {
        q->flags |= 0x100;
    }
    if (q->x30 || q->x34 || q->x38) {
        q->flags |= 0x80;
    }
    q->x5c = 0;
    q->x30 = q->x30 - q->x34;
    q->x48 = 3.1415927f / q->x68;
    w->x200 = a1;
    w->x202 = a2;
    inv = 1.0f / q->x64;
    rx = 10430.37835 * (7.2551975f * inv);
    rz = 10430.37835 * (4.1887903f * inv);

    njPushMatrixEx();
    fn_80286EE8();
    fn_8028B498();
    njUnitMatrix(NULL);
    njPushMatrixEx();
    fn_80286EE8();
    fn_8028B498();
    njPushMatrixEx();
    fn_80286EE8();
    fn_8028B498();
    pt.z = 0.0f;
    pt.x = 0.0f;
    pt.y = q->radius;
    ang[1] = 0;
    ang[0] = 0;
    ang[2] = rz;
    q->x20 = q->radius * njCos(rz);
    njRotateEx(ang, 1);
    njCalcPoint(NULL, &pt, &q->v[0].p);
    njPopMatrixEx();
    ang[1] = 0x2aaa;
    ang[2] = 0;
    ring = 1;
    cnt = lim > q->x64 ? 0.21650635f * q->x64 + 1.0f : lim;
    q->x66 = cnt;
    njRotateEx(ang, 1);
    njCalcPoint(NULL, &q->v[0].p, &q->v[1].p);
    njCalcPoint(NULL, &q->v[1].p, &q->v[3].p);
    njCalcPoint(NULL, &q->v[3].p, &q->v[5].p);
    njCalcPoint(NULL, &q->v[5].p, &q->v[4].p);
    njCalcPoint(NULL, &q->v[4].p, &q->v[2].p);
    q->v[5].col = c1;
    q->v[3].col = c1;
    q->v[2].col = c1;
    q->v[4].col = c0;
    q->v[1].col = c0;
    q->v[0].col = c0;
    y = q->v[0].p.y;
    q->v[5].p.y = 0.0f;
    q->v[4].p.y = 0.0f;
    q->v[3].p.y = 0.0f;
    q->v[2].p.y = 0.0f;
    q->v[1].p.y = 0.0f;
    q->v[0].p.y = 0.0f;
    njPopMatrixEx();

    cur = fn_801E1A2C(1, 0x80);
    cur->mtx = lbl_802B1128;
    cur->x44 = 0.0f;
    tail = row = cur;
    acc = rx;
    total = 1;
    per = 6;
    q->first = tail;
    while (ring < cnt) {
        total += per;
        col = 0;
        idx = 0;
        for (i = 0; i < per; i++) {
            prev = cur;
            cur = fn_801E1A2C(1, 0x80);
            if (i == 0) {
                row->child = cur;
                head = cur;
                cur->parent = row;
            } else {
                prev->next = cur;
            }
            cur->x44 = row->x44;
        }
        tail->next = head;
        ang[0] = 0;
        prev = cur;
        tail = cur;
        cur = head;
        ang[1] = 0x2aaa;
        found = 0;
        njSetMatrix(NULL, row->mtx.m);
        odd = ring % 2;
        while (row->child == NULL || !(row->child != NULL && found)) {
            if (row->child != NULL) {
                ref = row;
                found = 1;
            }
            n = 1;
            if (ring != 1) {
                if (col % (ring - 1) == 0) {
                    n = 2;
                }
            } else {
                n = 6;
            }
            for (j = 0; j < n; j++) {
                if (idx % ring > 1 && odd == 0) {
                    njPushMatrixEx();
                    fn_80286EE8();
                    fn_8028B498();
                    if (row->next == head) {
                        njSetMatrix(cur->mtx.m, ref->mtx.m);
                    } else {
                        njSetMatrix(cur->mtx.m, row->next->mtx.m);
                    }
                    njRotateY(cur->mtx.m, -0x2aaa);
                    njRotateX(cur->mtx.m, rx);
                    njRotateY(cur->mtx.m, 0x2aaa);
                    njPopMatrixEx();
                    cur->rotY = 0x2aaa;
                } else {
                    fn_80291C44(cur->mtx.m);
                    njRotateX(cur->mtx.m, rx);
                }
                prev = cur;
                cur = cur->next;
                idx++;
                njRotateEx(ang, 1);
            }
            if (cur == NULL) {
                break;
            }
            row = row->next;
            njSetMatrix(NULL, row->mtx.m);
            col++;
        }
        acc += rx;
        row = head;
        per += 6;
        ring++;
        njSin(acc);
    }
    q->last = head;
    nb = fn_801E1A2C(1, 0x80);
    nb->parent = q->last;
    q->last->child = nb;
    prev->next = nb;
    q->x60 = total;
    if (q->x74 == 0) {
        q->x74 = total;
    }
    if (q->x76 == 0) {
        q->x76 = total;
    }
    for (p = q->first; p != NULL; p = p->next) {
        njTranslate(p->mtx.m, 0.0f, y, 0.0f);
    }
    njPopMatrixEx();
    for (p = q->first; p != NULL; p = p->next) {
        if (p->rotY != 0) {
            njRotateY(p->mtx.m, p->rotY);
            p->rotY = 0;
        }
    }
}

static inline void ItemDraw(ItemWork* w)
{
    fn_80299040(w->texlist);
    njPushMatrixEx();
    fn_80286EE8();
    fn_8028B498();
    njTranslate(NULL, w->base->x + w->ofs[0], w->base->y + w->ofs[1], w->base->z + w->ofs[2]);
    njRotateXYZ(NULL, w->ang[0], w->ang[1], w->ang[2]);
    njScale(NULL, w->scl.x, w->scl.y, w->scl.z);
    if (w->shape != NULL) {
        fn_80293544(w->model, w->motion, w->shape, w->frame);
    } else {
        fn_80292D88(w->model, w->motion, w->frame);
    }
}

void fn_800CA3C0(Task* t)
{
    u32 money;
    DrawState ds;
    DrawState ds2;
    ItemWork* w;
    s32 i;
    f32 v;
    f32 a;
    f32 d;

    w = t->work;
    if ((t->parent->flags & 0x40) || (w->owner->flags & 0x40)) {
        t->flags |= 0x40;
        return;
    }
    if (*w->fade == -30) {
        return;
    }
    if (lbl_80347450 == NULL) {
        return;
    }
    if (t->state != 0xff && lbl_803473A8 == 0) {
        return;
    }
    switch (t->state) {
    case 0:
        switch (w->mode) {
        case 0:
            if (!(lbl_80310B3C[0x88 / 4] & 0x8000)) {
                for (i = 0; i < 3; i += 2) {
                    v = w->vel[i];
                    a = (v < 0.0f) ? -v : v;
                    if (a < 0.1 || ((d = w->ofs[i] + v) < 0.0f ? -d : d) > w->range) {
                        w->vel[i] = w->wander * (3.0517578e-05f * rand() - 0.5f);
                    } else {
                        w->ofs[i] += v;
                        w->ang[1] = 0x4000 - ATAN_ANG(w->vel[2], w->vel[0]);
                    }
                }
            }
            break;
        case 1:
            memcpy(w->ang, w->srcAng, 12);
            break;
        }
        if (*w->fade == 0) {
            DrawStateDefault2D(&ds);
        } else {
            njMemCopy(&ds, lbl_802DFEF0, 10);
            ds.colour.a = 0.033333335f * (f32)*w->fade;
        }
        DrawStatePush(&ds);
        ItemDraw(w);
        lbl_80346D78++;
        njPopMatrixEx();
        DrawStatePop(NULL);
        w->frame += w->speed;
        if (w->frame > (f32)w->motion->nframes - 1.0f) {
            w->frame = 0.0f;
        }
        d = w->base->x + w->ofs[0] - lbl_80347450->pos[0];
        if (d < 0.0f) {
            d = -d;
        }
        if (d < w->pickDist) {
            d = w->base->y + w->ofs[1] - lbl_80347450->pos[1];
            if (d < 0.0f) {
                d = -d;
            }
            if (d < w->pickDist) {
                d = w->base->z + w->ofs[2] - lbl_80347450->pos[2];
                if (d < 0.0f) {
                    d = -d;
                }
                if (d < w->pickDist) {
                    w->timer = 30;
                    t->state = 1;
                }
            }
        }
        if (w->flag != NULL && *w->flag != 0) {
            w->vel[0] = w->base->x + w->ofs[0] - lbl_80347450->pos[0];
            w->vel[1] = w->base->y + w->ofs[1] - lbl_80347450->pos[1];
            w->vel[2] = w->base->z + w->ofs[2] - lbl_80347450->pos[2];
            fn_8009009C(w->vel, 3.0f);
            w->ang[1] = 0x4000 - ATAN_ANG(w->vel[2], w->vel[0]);
            w->speed = 5.0f;
            w->timer = 30;
            t->state = 3;
        }
        break;
    case 1:
        if (lbl_80346D7C != 0) {
            break;
        }
        lbl_80346D7C = 1;
        SePlay(8, 5, 7);
        memcpy(&money, &lbl_8030CEA0.x17a0, 4);
        if (money < 99999999) {
            money++;
        }
        memcpy(&lbl_8030CEA0.x17a0, &money, 4);
        memcpy(&money, &lbl_8030CEA0.x17a4, 4);
        {
            u32 add = fn_801B90E4(w->item);
            if (money + add < 99999999) {
                money = money + add;
            } else {
                money = 99999999;
            }
        }
        memcpy(&lbl_8030CEA0.x17a4, &money, 4);
        if (fn_801F452C(w->item) < 99) {
            fn_801EFF0C(w->item);
            w->got = 1;
            fn_8009D190(w->x60);
        } else {
            w->got = 0;
        }
        t->state++;
        break;
    case 2:
        w->timer--;
        if (30 - w->timer == w->x6c && w->flag != NULL) {
            *w->flag = 1;
        }
        if (w->timer <= 0) {
            t->flags |= 0x40;
        }
        if (w->timer == 25) {
            lbl_80346D7C = 0;
        }
        break;
    case 3:
        w->ofs[0] += w->vel[0];
        w->ofs[2] += w->vel[2];
        njMemCopy(&ds2, lbl_802DFEF0, 10);
        ds2.colour.a = -(f32)(30 - w->timer) / 30.0f;
        DrawStatePush(&ds2);
        ItemDraw(w);
        njPopMatrixEx();
        DrawStatePop(NULL);
        w->frame += w->speed;
        if (w->frame > (f32)w->motion->nframes - 1.0f) {
            w->frame = 0.0f;
        }
        w->timer--;
        if (w->timer <= 0) {
            t->flags |= 0x40;
        }
        break;
    }
}
