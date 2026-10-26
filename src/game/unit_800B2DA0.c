#include "types.h"
#include "ninja.h"
#include "game/sprite.h"
#include "game/util.h"
#include "game/task.h"
#include "game/drawstate.h"
#include <math.h>
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
extern void* lbl_80347450;
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
extern void fn_80095360(void* p, s32 mode);
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
extern void *fn_800912A8(s32 a, void *b, s32 c, s32 d);
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
    void *p44;
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
extern void fn_800C5D78(void *p);
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
    u8 pad0[0x8];
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
extern void fn_800D208C(s32 a);
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
extern NJS_VECTOR fn_800C4C54(void* c);
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
extern int fn_8025ECC4(void);
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
extern void fn_800D0CC8(void* e);
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
typedef struct Player_800C5530 {
    u8 pad0[0x3c];
    f32 f3c;
    u8 pad40[0x178];
    Sub_800C5530* p1b8;
} Player_800C5530;
typedef struct Info {
    u8 pad0[4];
    s32 id;
    u8 pad8[0xc];
} Info;
extern f32 lbl_80346D88;
extern u16 lbl_802E0F00[];
extern s32 fn_8015F1F0(Player_800C5530* p);
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
    u8 pad0[0x24];
    s32 w24;
} Cfg_800CDEF4;
typedef struct Cfg1c8_800CDEF4 {
    u8 pad0[0x10];
    Cfg_800CDEF4* p10;
} Cfg1c8_800CDEF4;
typedef struct Actor_800CDEF4 {
    u8 pad0[0xe8];
    void* pe8;
    void* pec;
    u8 padf0[0x94];
    s32 w184;
    u8 pad188[8];
    f32 f190;
    u8 pad194[4];
    s32 w198;
    u8 pad19c[0x2c];
    Cfg1c8_800CDEF4* p1c8;
    u8 pad1cc[0x30];
    s16 h1fc;
    u8 pad1fe[2];
    s16 h200;
} Actor_800CDEF4;
typedef struct Holder_800CDEF4 {
    u8 pad0[0x18];
    u8 flags;
    u8 pad19[0xb];
    Actor_800CDEF4* p24;
} Holder_800CDEF4;
typedef struct Task_800CDEF4 {
    u8 pad0[8];
    Holder_800CDEF4* p8;
    u8 pad_c[0xc];
    u8 flags18;
    u8 state;
    u8 pad1a[0xa];
    Actor_800CDEF4* p24;
} Task_800CDEF4;
typedef struct Row {
    f32 f0;
    u32 w4;
    u8 pad8[0x18];
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
        ((Obj_800CF8F8*)lbl_80347450)->f38 = pos[0];
        ((Obj_800CF8F8*)lbl_80347450)->f3c = pos[1];
        ((Obj_800CF8F8*)lbl_80347450)->f40 = pos[2];
    }
    if (val != NULL) {
        ((Obj_800CF8F8*)lbl_80347450)->f48 = *val;
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
    self->p44 = fn_800912A8(self->w74, self->p44, 0x80, 0x400);
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
        Obj_800CF8F8 *t = lbl_80347450;

        if (t != 0) {
            f32 dy = self->fb4 - t->f38;
            f32 dx = self->fb8 - t->f3c;
            f32 dz = self->fbc - t->f40;
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
        fn_800D208C(w->x118);
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
    t = fn_800C4C54(c);
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
    t = fn_800C4C54(o);
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
            MemCopy(n->f38, ((Ent_800C69CC*)lbl_80347450)->f38, 0x24);
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
            e->pos.x = ((Ent_800C7230*)lbl_80347450)->pos.x;
            e->pos.y = ((Ent_800C7230*)lbl_80347450)->pos.y;
            e->pos.z = ((Ent_800C7230*)lbl_80347450)->pos.z;
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
        e->x180 += (s32)((f32)p->range * (0.000030517578125f * (f32)fn_8025ECC4()));
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
    fn_800D0CC8(e);
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
    fn_800D0CC8(e);
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
    if ((*(Player_800C5530**)&lbl_80347450) != NULL && (*(Player_800C5530**)&lbl_80347450)->p1b8 != NULL) {
        f32 y = (*(Player_800C5530**)&lbl_80347450)->f3c;
        if (16.0f > y - lbl_80346D88) {
            u32 t = (*(Player_800C5530**)&lbl_80347450)->p1b8->h24 & 0xFF00;
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
    if (lbl_80347408 == 0 && fn_8015F1F0((*(Player_800C5530**)&lbl_80347450)) == 0) {
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
    extern void fn_800C35C4(Actor_800CDEF4* a, s32 i);
    extern void* fn_801C5D88(Actor_800CDEF4* a, s32 i);
    extern void fn_800C3518(Actor_800CDEF4* a);
    extern void fn_800C3428(Task_800CDEF4* t);
    extern void fn_801E5DF0(Actor_800CDEF4* a);
    Holder_800CDEF4* h = t->p8;
    Actor_800CDEF4* a = t->p24;
    Actor_800CDEF4* r4;
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
