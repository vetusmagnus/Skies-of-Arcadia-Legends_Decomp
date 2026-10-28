#include "types.h"
#include "game/work_8030CEA0.h"
#include "game/util.h"
#include "ninja.h"
#include <stdarg.h>
#include "game/drawstate.h"
#include <math.h>
#include "game/task.h"
#include <string.h>
#include "string.h"
extern void fn_80117748();
extern void fn_80114C84(void *a, void *b, void *c, void *d, void *e, void *f);
extern void fn_80114A44(void);
extern void fn_80114AB8(void);
extern s32 lbl_80346E80;
extern s32 fn_801161B4(void);
extern u8 lbl_802E54B0[];
typedef struct {
    u8 pad0[0x2c];
    f32 f2c; /* 0x2C */
    u8 pad30[0xa4 - 0x30];
} Entry;
typedef struct {
    s32 type;   /* 0x00 */
    void *ptr;  /* 0x04 */
    f32 a;      /* 0x08 */
    f32 b;      /* 0x0C */
    f32 c;      /* 0x10 */
    f32 d;      /* 0x14 */
    f32 e;      /* 0x18 */
    f32 f;      /* 0x1C */
} Req;
extern Req lbl_8030A380;
extern f32 lbl_80349E90;
extern void fn_80109E7C(const char *s, s32 n);
extern char lbl_802B31A8[];
extern void *lbl_80346EB0;
extern void *lbl_80346EB4;
extern s32 lbl_803473B4;
extern s32 lbl_803473B0;
extern void *lbl_80346EC0;
extern void fn_8014FA10(void *p);
extern u8 *lbl_803472A8;
extern u8 *lbl_803472CC;
extern f32 lbl_8034A398;
extern f32 lbl_803472DC;
extern f32 lbl_8034A380;
extern f32 lbl_8034A3A4;
extern f32 lbl_803472E0;
extern f32 lbl_80346EE4;
extern s32 lbl_80311AC0[5];
void fn_802238E4(void *dst, void *src, s32 n);
s32 fn_802254A0(s32 a);
void fn_80123CBC(void);
void *fn_802267AC(void *a, void *b);
void *fn_801E1C7C(s32 size);
extern void *lbl_803475A0;
extern u8 lbl_80310A1C[0x120];
void fn_801248C4(s32 a, u8 *obj, s32 flag);
void fn_8020EFD4(s32 v);
void fn_80156C6C(NJS_MATRIX m, void *a);
void fn_8014F99C(void *b, NJS_MATRIX m);
void fn_8014FA10(void *m);
void fn_80127BC0(struct M_80127BC0 *self);
s32 fn_801CC5BC(void *a);
void fn_801CC65C(void *a);
void fn_80218D84(void *a, s32 b, s32 c);
extern void *lbl_80346ED8;
extern s32 lbl_80346ED4;
extern s32 lbl_80346ED0;
extern u8 lbl_80305F60[0x20];
void fn_8012C060(void);
void fn_80133144(void);
void fn_801323F0(void);
void fn_801316CC(void);
void fn_80130368(void);
void fn_8012F744(void);
void fn_8012F490(void);
void fn_8012E5D8(void);
void fn_8012C660(void);
void fn_8012AEE8(void);
void fn_8012AA8C(void);
void fn_80156DA0(void *a, void *b);
void fn_80156E54(void *a, void *b);
void fn_801E5148(void *a, void *b);
void fn_801E5DF0(void *a, void *b);
extern u8 lbl_80311970[];
extern s32 fn_8010E270(void *obj, u32 v);
extern void fn_801E7414(s32 id, void *obj);
extern void fn_801189F0(void *);
extern s32 lbl_80346E68;
extern s32 SePlay(s32 a, s32 id, s32 vol);
struct Pad_80311A60;
extern struct Pad_80311A60 *lbl_80311A60[];
extern s32 lbl_80347404;
extern void fn_80222838(void *p);
extern void fn_80117BE4(s32 a, void *self, void *out);
extern s32 lbl_80347440;
extern s32 lbl_80347444;
extern f32 lbl_80349EDC, lbl_80349EA4, lbl_80349E18;
extern f32 fn_80090EEC(void *p, f32 v);
extern void fn_801E17E0(void *p);
extern void *memset(void *s, int c, unsigned long n);
typedef struct {
    u8 pad0[4];
    s32 v4;
    s32 v8;
} Rec;
extern Rec *lbl_803472A4;
typedef struct Fn80129560Obj {
    u8 pad0[0x19];
    u8 state;
    u8 pad1[0x0a];
    void *inner;
} Fn80129560Obj;
extern void fn_8015ED90(void *p);
extern s32 fn_8015E600(void *p);
extern void fn_8015EBF4(void *);
extern void fn_80100B74(Fn80129560Obj *);
typedef struct Fn80129750Inner {
    u8 pad0[0x38];
    f32 pos[3];
    Angle ang[3];
    f32 scale[3];
    u8 pad1[0xb4 - 0x5c];
    f32 pos2[3];
    u8 pad2[0x16c - 0xc0];
    s16 f16c;
    s16 f16e;
} Fn80129750Inner;
typedef struct Fn80129750Obj {
    u8 pad0[0x24];
    Fn80129750Inner *inner;
} Fn80129750Obj;
extern void fn_801E6EC0(NJS_MATRIX m, s32 a, s32 b, s32 c, s32 d);
extern void fn_801E6DD4(NJS_MATRIX m, Fn80129750Inner *in);
typedef struct Fn801298E8Rec {
    u8 pad0[0x8];
    s32 f8;
} Fn801298E8Rec;
extern s32 lbl_803472C0;
extern s32 lbl_803472D0;
typedef struct Fn80129BD4Item {
    u8 pad0[0x4];
    s32 f4;
    u8 pad1[0x18];
    s32 f20;
    u8 pad2[0x58 - 0x24];
} Fn80129BD4Item;
typedef struct Fn80129BD4Head {
    s32 count;
    s32 f4;
    Fn80129BD4Item *items;
} Fn80129BD4Head;
extern s32 lbl_803472B4;
extern s32 lbl_803472AC;
typedef struct Fn80129CA8Mid {
    u8 pad0[0x24];
} Fn80129CA8Mid;
typedef struct Fn80129CA8Inner {
    u8 pad0[0x17a];
    u16 f17a;
    u8 pad1[0x1c8 - 0x17c];
    Fn80129CA8Mid *mid;
} Fn80129CA8Inner;
extern u8 lbl_802B3388[];
extern s32 fn_8025EF88(void *, const char *);
extern void fn_8015757C(void *, u16);
typedef struct Fn80129D40Inner {
    u8 pad0[0x17a];
    u16 f17a;
} Fn80129D40Inner;
typedef struct Fn80129D40Obj {
    u8 pad0[0x24];
    Fn80129D40Inner *inner;
} Fn80129D40Obj;
typedef struct Fn80129D40Entry {
    Fn80129D40Obj *obj;
    s32 a;
    s32 b;
    s32 c;
    s32 d;
} Fn80129D40Entry;
extern s32 lbl_803472B0;
extern s32 lbl_8034729C;
extern Fn80129D40Entry lbl_80308EF8[];
extern char lbl_802B33EC[];
extern void fn_801DBE1C(const char *, ...);
typedef struct {
    u8 pad00[0x28];
    u16 s28, s2a;
} Sub_801109AC;
typedef struct {
    u8 pad00[0x38];
    f32 x, y, z;            /* 0x38 */
    u8 pad44[0x174];
    Sub_801109AC* sub;               /* 0x1B8 */
} Obj_801109AC;
typedef struct {
    u8 pad00[0x24];
    u16 flags;      /* 0x24 */
} Sub_801185D4;
typedef struct {
    u8 pad00[0x170];
    u16 type;       /* 0x170 */
    u8 pad172[0x1A];
    f32 f18c;
    f32 f190;
    u8 pad194[8];
    s32 s19c;
    u8 pad1a0[0x18];
    Sub_801185D4* sub;       /* 0x1B8 */
} Obj_801185D4;
extern f32 lbl_802E5078[];
extern u8 lbl_80346798[8];
typedef struct {
    f32 v[3];   /* 0x00 */
    s32 w[3];   /* 0x0C */
} Out;
typedef struct {
    void* p0;
    void* p4;
} Inner;
typedef struct {
    u8 pad00[0x44];
    Angle rx, ry, rz;   /* 0x44 */
    f32 sx, sy, sz;     /* 0x50 */
} Src_80119744;
extern void njScale(f32* m, f32 x, f32 y, f32 z);
extern void njCalcVector(f32* m, NJS_VECTOR* v, NJS_VECTOR* out);
extern void fn_800071D8(Inner** h);
extern void fn_80007080(NJS_VECTOR* v, s32 a);
extern void fn_80006F1C(s32* w, s32 a);
extern s32 fn_8025CC04(char* buf, const char* fmt, va_list ap);
extern char* fn_8025EDDC(char* s, const char* delim);
typedef struct {
    u32 flags;      /* 0x00 */
    s32 cur;        /* 0x04 */
    u8 pad08[4];
    s32 total;      /* 0x0C */
    f32 curve[4];   /* 0x10 */
    u8 pad20[8];
    f32 x0, y0, x1, y1;   /* 0x28 */
    f32 c38, c3c;   /* 0x38 */
    u8 pad40[0x10];
    f32 c50, c54;
    u8 pad58[0x10];
    f32 c68, c6c;
    u8 pad70[0x10];
    f32 c80, c84;
} Anim_8011B6E0;
void fn_8011B024(f32 *pts, int n, int deg, f32 *out, f32 t);
typedef struct {
    u8 pad00[0x50];
    f32 f50, f54, f58;
} Sub_8011F44C;
typedef struct {
    u32 flags;      /* 0x00 */
    u8 pad04[4];
    s32 state;      /* 0x08 */
    u8 pad0c[4];
    s32 frame;      /* 0x10 */
    u8 pad14[0x14];
    f32* curve;     /* 0x28 */
    u8 pad2c[0x14];
    Sub_8011F44C* sub;       /* 0x40 */
} Obj_8011F44C;
typedef struct {
    f32 m[16];
} Item;
typedef struct {
    u32 flags;      /* 0x00 */
    u8 pad04[0x14];
    s32 frame;      /* 0x18 */
    Item* items;    /* 0x1C */
    u8 pad20[4];
    s32 count;      /* 0x24 */
} Obj_8012092C;
extern void fn_801202C4(void* o);
extern void fn_8012061C(void* o);
extern void fn_8012048C(void* o);
extern void fn_8028A3E0(s32 a);
extern void fn_8028A2A8(Item* p, s32 a);
extern void fn_8028A2A4(void);
typedef struct {
    u8 a, b;
    u16 dur;
} Frame;
typedef struct {
    void* handle;   /* 0x00 */
    u32 timer;      /* 0x04 */
    u16 idx;        /* 0x08 */
    u8 pad0a[2];
    u32 loops;      /* 0x0C */
    u32 max_loops;  /* 0x10 */
    u8 s14[2];      /* 0x14 */
    u8 b16, b17;    /* 0x16 */
    u8 pad18[4];
    Frame frames[1]; /* 0x1C */
} Anim_80122778;
typedef struct {
    u8 pad00[0x18];
    u8 flags;       /* 0x18 */
    u8 pad19[0xB];
    Anim_80122778* anim;     /* 0x24 */
} Obj_80122778;
extern void fn_801D6CBC(void* h, void* p);
extern void fn_801D6C3C(void* h);
extern void fn_801E1784(void* p);
typedef struct {
    void* handle;   /* 0x00 */
    u32 timer;      /* 0x04 */
    u16 idx;        /* 0x08 */
    u16 count;      /* 0x0A */
    u32 loops;      /* 0x0C */
    s32 max_loops;  /* 0x10 */
    u8 b14, b15;    /* 0x14 */
    u8 b16, b17;    /* 0x16 */
    u8 b18;         /* 0x18 */
    u8 pad19[3];
    Frame frames[31]; /* 0x1C */
} Anim_80122A00;
typedef struct {
    s32 a, b, dur;
} SrcFrame;
typedef struct {
    void* handle;       /* 0x00 */
    SrcFrame* frames;   /* 0x04 */
    Anim_80122A00* anim;         /* 0x08 */
} Src_80122A00;
typedef struct {
    u8 pad00[0x24];
    Src_80122A00* src;       /* 0x24 */
    Anim_80122A00* anim;     /* 0x28 */
} Obj_80122A00;
extern void* lbl_80347588;
extern s32 fn_801D6E38(void* h);
extern void* fn_80226704(void* list, void *, s32 size);
typedef struct Ent_80122D5C {
    u8 a;
    u8 b;
    u16 c;
} Ent_80122D5C;
typedef struct Anim_80122D5C {
    s32 id;
    u32 x4;
    u16 x8;
    u16 xa;
    u32 xc;
    u32 x10;
    u8 x14[2];
    u8 x16;
    u8 x17;
    u8 x18;
    u8 pad19[3];
    Ent_80122D5C ent[31];
} Anim_80122D5C;
typedef struct Info_80122D5C {
    u8 pad0[0x19];
    u8 x19;
} Info_80122D5C;
typedef struct Parent_80122D5C {
    void *x0;
    u8 pad4[8];
    Info_80122D5C *xc;
} Parent_80122D5C;
typedef struct Task_80122D5C {
    u8 pad0[0x18];
    u8 flags;
    u8 pad19[0x24 - 0x19];
    Parent_80122D5C *parent;
    Anim_80122D5C *anim;
} Task_80122D5C;
extern char lbl_802B32A0[];
extern char lbl_802B32D4[];
extern void fn_8011B238(s32 color, ...);
void fn_80122D5C(Task_80122D5C *t);
typedef struct {
    u8 pad0[0x10];
    s16 s10;
    u8 pad12[2];
    s16 s14;
    u8 pad16[0x20 - 0x16];
    s16 s20;
} In;
typedef struct {
    u8 pad0[0x12];
    u8 b12;
    u8 b13;
    u8 b14;
    u8 b15;
    u8 pad16;
    s8 b17;
    u8 pad18[0x24 - 0x18];
    u32 flags;
    u8 pad28[0x118 - 0x28];
    s8 tbl[8];
} Obj_80126014;
extern void fn_8014EF34(In *in);
extern void fn_801276E8(struct Obj_801276E8 *a, struct In_801276E8 *o);
extern void fn_80126118(struct Obj_80126118 *a, struct In_80126118 *o);
typedef struct {
    u8 b;
    u8 pad[0x13];
} Ent_801275E0;
typedef struct {
    u8 pad0[0x58];
    Ent_801275E0 e58[1];
    u8 pad59[0xc0 - 0x58 - 0x14];
    f32 f0c0;
} Sub_801275E0;
typedef struct {
    u8 pad0[5];
    s8 b5;
    s8 b6;
    u8 pad7[0x14 - 7];
    s8 b14;
    s8 b15;
    u8 pad16;
    s8 b17;
    u8 pad18[2];
    s16 s1a;
    u8 pad1c[0x6c - 0x1c];
    Sub_801275E0 sub;
} Obj_801275E0;
typedef struct {
    u8 pad0[4];
    u32 tick;
} Clock;
typedef struct {
    u8 pad0[0xe8];
    Clock *clock;
    u8 pade8[0x18c - 0xec];
    f32 f18c;
    f32 f190;
} Ctx_801275E0;
extern void fn_801275E0(Ctx_801275E0 *c, Obj_801275E0 *o);
typedef struct {
    u8 pad0[0x24];
    u32 flags;
    u8 pad28[0x44 - 0x28];
    s32 v44;
    s32 v48;
    s32 v4c;
    s32 v50;
    u8 pad54[0x60 - 0x54];
    s32 v60;
    s32 v64;
    s32 v68;
} Obj_80127E24;
typedef struct {
    u8 pad0[0x44];
    s32 v44;
    s32 v48;
    s32 v4c;
} Ctx_80127E24;
extern void fn_801264A4(void *p, s32 n, f32 f);
extern s32 fn_80126E24(void*c, f32 a, f32 b);
/* A battle formation: up to 12 slots (id, then the slot data), the camera distance and angles. */
typedef struct FormEnt {
    u8 id;
    u8 pad1;
    u8 d[12];
} FormEnt;
typedef struct FormTbl {
    FormEnt e[12];      /* 0x00 */
    u8 padA8[0xac - 0xa8];
    u8 b_ac;
    u8 b_ad;
    u8 padae[2];
    f32 f_b0;
    f32 f_b4;
    u8 padb8[4];
    f32 f_bc;
    f32 f_c0;
    f32 f_c4;
} FormTbl;
extern s32 lbl_80347290;
extern s32 lbl_80347294;
extern s32 lbl_803472D8;
extern void fn_80156250(void);
extern void fn_80144E5C(void);
typedef struct {
    u8 pad0[4];
    struct {
        u8 pad0[0x20];
        void *x20;
    } *x4;
} Obj_8012AA8C;
extern void *lbl_80346EFC;
extern void *lbl_80346F00;
extern void *lbl_80346F04;
extern void *lbl_80346F08;
extern Obj_8012AA8C *lbl_80346EF0;
extern Obj_8012AA8C *lbl_80346EF4;
extern Obj_8012AA8C *lbl_80346EF8;
extern void *lbl_80346F0C;
extern void fn_801D6944(void *p);
extern void fn_802275A4(void *p, s32 n);
typedef struct {
    u8 pad0[4];
    s32 f4;
    u8 pad8[0x14 - 8];
    s16 flags;      /* 0x14 */
} Attach;
typedef struct {
    u8 pad0[0x38];
    NJS_POINT3 pos; /* 0x38 */
} Other;
typedef struct {
    u8 pad0[0x38];
    NJS_POINT3 pos; /* 0x38 */
    u8 pad44[0x100 - 0x44];
    void *res;      /* 0x100 */
    u8 pad104[0x1bc - 0x104];
    Attach *attach; /* 0x1BC */
} Obj;
typedef struct {
    u8 pad0[0x19];
    u8 f19;
    u8 pad1a[0x24 - 0x1a];
    Obj *obj;   /* 0x24 */
} Parent;
typedef struct {
    u8 pad0[0x38];
    NJS_POINT3 pos;     /* 0x38 */
    u8 pad44[0xcc - 0x44];
    NJS_POINT3 dir;     /* 0xCC */
    NJS_POINT3 target;  /* 0xD8 */
} Obj_801147E8;
extern s32 fn_801DD078(NJS_POINT3 *a, NJS_POINT3 *b);
extern void fn_801DD5E8(Angle *out, NJS_POINT3 *p);
extern void fn_801DCF24(NJS_POINT3 *p, Angle *ang, s32 yaw, f32 scale);
extern s32 fn_801144A4(Obj_801147E8 *o, s32 yaw, Angle *ang);
extern s32 fn_80114138(Obj_801147E8 *o, s32 yaw, Angle *ang);
typedef struct {
    u32 pad0;
    u32 flags;      /* 4 */
    u8 pad8[0x20 - 8];
} Row;
typedef struct {
    u8 pad0[0x24];
    u16 flags;      /* 0x24 */
} Src;
extern Row lbl_802E1154[];
typedef struct HitObj {
    u8 pad0[0x24];
    u16 x24;
    u8 pad26[0xA];
    u16 x30;
    u8 pad32[2];
} HitObj;
extern u32 lbl_8030A3C8[];
extern int fn_802256A0(f32 *pos, HitObj *obj, u32 mask, u32 id);
typedef struct Chr {
    u8 pad0[0x1B8];
    void *x1b8;
    struct Res *x1bc;
} Chr;
typedef struct Res {
    u8 pad0[0x18];
    f32 *x18;
} Res;
extern s16 lbl_8034740C;
extern int fn_80115BBC(f32 *pos, f32 *to, void *a);
typedef struct Res_801157E4 {
    u8 pad0[0x18];
    f32 *x18;
} Res_801157E4;
typedef struct Chr_801157E4 {
    u8 pad0[0x1bc];
    Res_801157E4 *x1bc;
} Chr_801157E4;
extern struct { s32 pad0; s32 x4; s32 pad8; } lbl_8030EA10;
extern f32 njSin(Angle a);
extern f32 njCos(Angle a);
extern s32 fn_801DD4C4(f32 x, f32 z);
extern void fn_801DCE18(f32 *in, f32 *out, s32 ang);
s32 fn_801157E4(f32 *out, f32 *from, f32 *to, void *a);
extern u32 fn_80222E00(s32 a, void *p);
typedef struct PosBlk {
    NJS_POINT3 pos;
    u8 pad0[4];
    Angle ang;
    u8 pad[0x24 - 0x14];
} PosBlk;
extern u8 lbl_8030A35C[];
extern void njRotateY(NJS_MATRIX m, Angle y);
extern int fn_80116B84(int n, PosBlk *blk, void *tbl, void *p);
typedef struct Chr_80116F2C {
    u8 pad0[0x38];
    PosBlk cur;
    u8 pad5C[0x104 - 0x5C];
    PosBlk prev;
    u8 pad128[0x1B8 - 0x128];
    void *x1b8;
} Chr_80116F2C;
extern f32 lbl_80347434;
extern int fn_801169D4(int sel, PosBlk *pos, void *p, f32 maxd, f32 step);
extern int fn_80117088(PosBlk *a, PosBlk *b, f32 x, f32 y, f32 z, void *p);
typedef struct Child {
    u8 pad0[0x10];
    u16 flags;
} Child;
typedef struct Chr_80117290 {
    u8 pad0[0x38];
    f32 pos[3];
    u8 pad44[0x1BC - 0x44];
    Res *res;
} Chr_80117290;
typedef struct Tbl {
    u8 pad0[0x10];
    u32 x10;
    u8 pad14[8];
    u32 x1c;
    u8 pad20[4];
} Tbl;
typedef struct Tpl {
    s16 x0;
    s16 x2;
    f32 x4;
    f32 x8;
    f32 xc;
    s32 x10;
    f32 x14[3];
    f32 x20;
    f32 x24;
    s32 x28;
    f32 x2c;
    s32 x30;
    s32 x34;
    s32 x38;
    s32 x3c;
} Tpl;
typedef struct Chr_801173DC {
    u8 pad0[0x74];
    Tpl tpl;
} Chr_801173DC;
extern Tpl lbl_8031191C;
typedef struct Chr_8011753C {
    u8 pad0[0x38];
    f32 pos[3];
    u8 pad44[0x1BC - 0x44];
    Res *res;
} Chr_8011753C;
typedef struct Chr_80119E50 {
    u8 pad0[0x44];
    s32 x44;
    u8 pad48[0xE8 - 0x48];
    u32 xe8;
    u8 padEC[4];
    u32 xf0;
    u8 padF4[0x170 - 0xF4];
    u16 id;
    u16 x172;
    u8 pad174[0x18C - 0x174];
    f32 x18c;
    u8 pad190[0x19C - 0x190];
    s32 x19c;
    f32 x1a0;
} Chr_80119E50;
typedef struct Owner_80119E50 {
    u8 pad0[0x24];
    Chr_80119E50 *chr;
} Owner_80119E50;
typedef struct G6 {
    f32 a[5];
    s32 n;
} G6;
typedef struct G4 {
    f32 a[3];
    s32 n;
} G4;
typedef struct Big {
    G6 g[4];
} Big;
typedef struct Small {
    G4 g[4];
} Small;
typedef struct Rec_8011D7BC {
    G6 g[4];
    u32 big;
    u8 pad[0x64 - 0x60 - 4];
} Rec_8011D7BC;
extern Rec_8011D7BC *lbl_80346EB8;
extern s32 lbl_80346EBC;
typedef struct Info {
    u8 pad0[0x28];
    s32 x28;
    s32 x2c[3];
    u8 pad38[4];
    s32 x3c;
    s32 x40[3];
} Info;
typedef struct Ext {
    u8 pad0[0x10];
    Info *info;
} Ext;
typedef struct Path {
    NJS_POINT3 p0[50];
    NJS_POINT3 p1[50];
    NJS_POINT3 z[50];
    NJS_POINT3 a;
    u8 pad714[0xC];
    NJS_POINT3 b;
    u8 pad72c[0x73C - 0x72C];
    s32 x73c;
    s32 x740;
} Path;
typedef struct Chr_80122ED8 {
    u8 pad0[0x1C8];
    Ext *ext;
    u8 pad1CC[0x25C - 0x1CC];
    Path *path;
} Chr_80122ED8;
extern void fn_8009FDA0(s32 a, s32 b, NJS_POINT3 *out, s32 c, s32 *d, s32 e, s32 f);
typedef struct Vec_80110AA0 {
    f32 x, y, z;
} Vec_80110AA0;
typedef struct Eff_80110AA0 {
    u8 pad0[8];
    void *w8;
    u8 pad_c[4];
    u16 h10;
    u16 h12;
    u8 pad_14[4];
    f32 *p18;
    u8 pad_1c[4];
    u32 *p20;
} Eff_80110AA0;
typedef struct Tgt_80110AA0 {
    u8 pad0[0x18];
    f32 *pos;
    u8 pad_1c[4];
    u32 *rot;
} Tgt_80110AA0;
typedef struct Cfg_80110AA0 {
    u8 pad0[4];
    void *w4;
} Cfg_80110AA0;
typedef struct Self_80110AA0 {
    u8 pad0[0x38];
    f32 x38;
    f32 y3c;
    f32 z40;
    s32 r44;
    s32 r48;
    s32 r4c;
    u8 pad_50[0x1C8 - 0x50];
    Cfg_80110AA0 *cfg;
} Self_80110AA0;
typedef struct Node_80110AA0 {
    u8 pad0[0x12];
    u16 kind;
    u8 pad_14[4];
    f32 *p18;
} Node_80110AA0;
typedef struct Cnt_801117C4 {
    s32 count;
    u8 pad4[0x20];
    s32 w24;
} Cnt_801117C4;
typedef struct D_801117C4 {
    u8 pad0[0x10];
    Cnt_801117C4 *cnt;
} D_801117C4;
typedef struct C_801117C4 {
    u8 pad0[4];
    u8 pad4[0x1C8 - 4];
} C_801117C4;
typedef struct B_801117C4 {
    u8 pad0[4];
    struct { u8 pad0[0x1C8]; D_801117C4 *d; } *c;
} B_801117C4;
typedef struct A_801117C4 {
    u8 pad0[0x10];
    B_801117C4 *b;
} A_801117C4;
typedef struct Obj_801117C4 {
    u8 pad0[0x38];
    f32 f38, f3c, f40;
    s32 w44, w48, w4c;
    u8 pad_50[0xE8 - 0x50];
    void *pe8;
    u8 pad_ec[0x104 - 0xEC];
    f32 f104, f108, f10c;
    s32 w110, w114, w118;
    u8 pad_11c[0x170 - 0x11C];
    s16 h170;
    u16 h172;
    u8 pad_174[0x18C - 0x174];
    f32 f18c;
    f32 f190;
    u8 pad_194[0x198 - 0x194];
    s32 w198;
    s32 w19c;
    u8 pad_1a0[0x1B8 - 0x1A0];
    void *w1b8;
    u8 pad_1bc[0x1C4 - 0x1BC];
    A_801117C4 *p1c4;
} Obj_801117C4;
typedef struct Delta_801117C4 {
    f32 x, y, z;
    s32 rx, ry, rz;
    s32 rest[3];
} Delta_801117C4;
typedef struct Ev_801177A4 {
    u8 pad0[0x12];
    u16 x12;
    u8 pad14[4];
    s32 x18;
    u8 pad1c[4];
    s32 x20;
} Ev_801177A4;
typedef struct Inner_801177A4 {
    u8 pad0[0x10];
    Ev_801177A4 *x10;
} Inner_801177A4;
typedef struct Obj_801177A4 {
    u8 pad0[0x38];
    f32 pos[3];
    u8 pad44[0xb4 - 0x44];
    f32 xb4;
    f32 xb8;
    f32 xbc;
    s32 xc0;
    s32 xc4;
    s32 xc8;
    u8 padcc[0x164 - 0xcc];
    f32 x164;
    u8 pad168[4];
    s16 x16c;
    u8 pad16e[2];
    s16 x170;
    s16 x172;
    u8 pad174[0x1c4 - 0x174];
    Inner_801177A4 *x1c4;
} Obj_801177A4;
extern u32 lbl_80310B3C[0x356];
extern Ev_801177A4 *lbl_8034741C;
extern s32 fn_8011768C(void);
extern s32 fn_8010E41C(s32 a, s32 b, f32 *pos);
typedef struct Ev_801179B8 {
    u8 pad0[0x12];
    u16 x12;
    u8 pad14[4];
    s32 x18;
    u8 pad1c[4];
    s32 x20;
} Ev_801179B8;
typedef struct Inner_801179B8 {
    u8 pad0[0x10];
    Ev_801179B8 *x10;
} Inner_801179B8;
typedef struct Obj_801179B8 {
    u8 pad0[0x38];
    f32 pos[3];
    u8 pad44[0xb4 - 0x44];
    f32 xb4;
    f32 xb8;
    f32 xbc;
    s32 xc0;
    s32 xc4;
    s32 xc8;
    u8 padcc[0x164 - 0xcc];
    f32 x164;
    u8 pad168[4];
    s16 x16c;
    u8 pad16e[2];
    u16 x170;
    s16 x172;
    u8 pad174[0x1c4 - 0x174];
    Inner_801179B8 *x1c4;
} Obj_801179B8;
typedef struct Req_80118368 {
    s32 type;
    s32 ptr;
    f32 a;
    f32 b;
    f32 c;
    f32 d;
    f32 e;
    f32 f;
} Req_80118368;
typedef struct Sub_80118368 {
    u8 pad0[0x30];
    u16 x30;
} Sub_80118368;
typedef struct Obj_80118368 {
    u8 pad0[0x38];
    f32 x38;
    f32 x3c;
    f32 x40;
    s32 x44;
    s32 x48;
    s32 x4c;
    u8 pad50[0x104 - 0x50];
    f32 x104;
    f32 x108;
    f32 x10c;
    s32 x110;
    s32 x114;
    s32 x118;
    u8 pad11c[0x170 - 0x11c];
    s16 x170;
    s16 x172;
    u8 pad174[0x1b8 - 0x174];
    Sub_80118368 *x1b8;
    void *x1bc;
} Obj_80118368;
extern void fn_80225930(u16 a, u16 b, Sub_80118368 *c);
typedef struct Res_8011BAE8 {
    u8 pad0[0x24];
    s32 x24;
    s32 x28;
    f32 x2c;
    f32 x30;
    f32 x34;
    u32 x38;
    u32 x3c;
    u32 x40;
    s32 x44;
    s32 x48;
    s32 x4c;
    s32 x50;
    s32 x54;
    s32 x58;
    s32 x5c;
    s32 x60;
    s32 x64;
    s32 x68;
    s32 x6c;
    s32 x70;
    u32 x74;
    f32 x78;
    u32 x7c;
} Res_8011BAE8;
typedef struct Sub_8011BAE8 {
    u8 pad0[0x10];
    Res_8011BAE8 *x10;
} Sub_8011BAE8;
typedef struct Obj_8011BAE8 {
    u8 pad0[0x17a];
    u16 x17a;
    u8 pad17c[0x1c8 - 0x17c];
    Sub_8011BAE8 *x1c8;
    u8 pad1cc[0x1dc - 0x1cc];
    s32 x1dc;
} Obj_8011BAE8;
typedef struct Out_8011BAE8 {
    u32 flags;
    s16 s4;
    u16 s6;
    s16 s8;
    s16 sa;
    u8 bc;
    u8 bd;
    u8 be;
    u8 bf;
    u8 b10;
    u8 b11;
    u8 b12;
    u8 b13;
    f32 f14;
} Out_8011BAE8;
extern void *fn_8015F1A0(u16 a);
extern void fn_8015F6C0(void *a, s32 b, s32 c, f32 *p, f32 *q);
typedef struct Task_8011C858 {
    u8 pad0[0x18];
    u8 flags;
    u8 state;
    u8 pad1a;
    u8 x1b;
    u8 pad1c[0x24 - 0x1c];
    void *work;
} Task_8011C858;
typedef struct Rec_8011C858 {
    u32 flags;
    s16 s4;
    u16 s6;
    u8 pad8[0x24 - 8];
    void *x24;
    void *x28;
} Rec_8011C858;
typedef struct Res_8011C858 {
    u32 x0;
} Res_8011C858;
typedef struct Sub_8011C858 {
    u8 pad0[0x10];
    Res_8011C858 *x10;
} Sub_8011C858;
typedef struct Sub2_8011C858 {
    u8 pad0[0x1a0];
    s32 x1a0;
} Sub2_8011C858;
typedef struct Work_8011C858 {
    u8 pad0[0x1c8];
    Sub_8011C858 *x1c8;
    u8 pad1cc[0x1d8 - 0x1cc];
    Sub2_8011C858 *x1d8;
    u8 pad1dc[0x1fa - 0x1dc];
    u8 x1fa;
    u8 pad1fb[0x25c - 0x1fb];
    Rec_8011C858 *x25c;
    u8 pad260[0x26c - 0x260];
    u8 x26c;
} Work_8011C858;
typedef struct Res_8011CA68 {
    u8 pad0[0x24];
    s32 x24;
    s32 x28;
    s32 x2c;
    f32 x30;
    f32 x34;
    u32 x38;
    u32 x3c;
    s32 x40;
    s32 x44;
    s32 x48;
    s32 x4c;
    u32 x50;
    s32 x54;
    s32 x58;
    u32 x5c;
} Res_8011CA68;
typedef struct Sub_8011CA68 {
    u8 pad0[0x10];
    Res_8011CA68 *x10;
} Sub_8011CA68;
typedef struct Obj_8011CA68 {
    u8 pad0[0x1c8];
    Sub_8011CA68 *x1c8;
} Obj_8011CA68;
typedef struct Out_8011CA68 {
    u32 flags;
    u8 pad4[4];
    s32 x8;
    s16 sc;
    s16 se;
    s32 x10;
    f32 f14;
    f32 f18;
    s16 s1c;
    s16 s1e;
    u32 color;
    s32 x24;
    s32 x28;
    u8 pad2c[0x88 - 0x2c];
    s32 x88;
    f32 f8c;
} Out_8011CA68;
extern s16 lbl_802B31E8[12];
typedef struct VertexTex_8011CE6C {
    f32 x, y, z, u, v;
    u32 colour;
} VertexTex_8011CE6C;
typedef struct Par_8011CE6C {
    u8 pad0[0x19];
    u8 state;
} Par_8011CE6C;
typedef struct Task_8011CE6C {
    u8 pad0[0x18];
    u8 flags;
    u8 state;
    u8 pad1a[0x24 - 0x1a];
    u8 *work;
    u8 pad28[4];
    Par_8011CE6C *x2c;
} Task_8011CE6C;
typedef struct Rec_8011CE6C {
    u8 pad0[8];
    s32 x8;
    u8 pad_c[8];
    f32 f14;
    u8 pad18[0x24 - 0x18];
    void *x24;
    void *x28;
} Rec_8011CE6C;
extern void fn_80290EA8(s32 n);
extern void fn_80226D14(void);
extern void fn_8009E910(DrawState *o, s32 mode, u8 *out);
extern void fn_80296ED4(s32 v);
extern void fn_80297DC8(void *tex);
extern void fn_80291064(VertexTex_8011CE6C *v, s32 n, s32 mode);
typedef struct VertexTex_8011D2D8 {
    f32 x, y, z, u, v;
    u32 colour;
} VertexTex_8011D2D8;
typedef struct Rec_8011D2D8 {
    u32 flags;
    u32 x4;
    u8 pad8[4];
    s16 sc;
    s16 se;
    u8 pad10[8];
    f32 f18;
    u8 pad1c[4];
    u32 color;
    void *x24;
    void *x28;
    void *x2c;
    NJS_TEXNAME name;    /* 0x30 */
    NJS_TEXLIST texlist; /* 0x3c */
    u8 x44[0x88 - 0x44];
    s32 x88;
} Rec_8011D2D8;
typedef struct Task_8011D2D8 {
    u8 pad0[0x24];
    Rec_8011D2D8 *work;
} Task_8011D2D8;
extern void *fn_80227E74(void);
extern void fn_80297DB4(void *a, void *b, s32 c, s32 d, s32 e);
extern void fn_80297DA4(void *a, void *b, void *c, s32 d);
extern void *fn_80227268(void *a, s32 b, s32 c, s32 d);
extern void fn_80298ED0(s32 a);
extern void fn_8024E020(void);
extern void fn_8011D02C(Rec_8011D2D8 *rec);
extern void fn_802990BC(void *a, void *b, s32 c);
extern void fn_80297BD8(s32 a, void *b, s32 c);
void fn_8011D2D8(Task_8011D2D8 *t);
extern void fn_801E1784(void *p);
extern void fn_802978F4(void *p);
typedef struct Obj_8011E048 {
    u32 x0;
    f32 x4;
    f32 x8;
    u8 padc[0x44 - 0xc];
    f32 x44;
    f32 x48;
    u8 pad4c[0x98 - 0x4c];
    u32 x98;
    u8 pad9c[0xa8 - 0x9c];
    u32 xa8;
    u8 pad_ac[0xb8 - 0xac];
    u32 xb8;
    u8 pad_bc[0xc8 - 0xbc];
    u32 xc8;
    u8 padcc[0xd0 - 0xcc];
    s32 xd0;
    s32 xd4;
} Obj_8011E048;
typedef struct Item_8011F000 {
    u8 pad0[0x40];
} Item_8011F000;
typedef struct Rec_8011F000 {
    u32 flags;
    s32 x4;
    s32 frame;
    s32 xc;
    s32 x10;
    s32 x14;
    s32 x18;
    Item_8011F000 *items;
    u8 pad20[4];
    s32 count;
    void *x28;
    u8 pad2c[0x38 - 0x2c];
    s32 x38;
    s32 x3c;
    void *x40;
} Rec_8011F000;
typedef struct Obj_8011F000 {
    u8 pad0[0x1c];
    f32 x1c;
    u8 pad20[0x50 - 0x20];
    f32 x50;
    f32 x54;
    f32 x58;
    u8 pad5c[0x168 - 0x5c];
    s16 x168;
    u8 pad16a[0x180 - 0x16a];
    s32 x180;
    u8 pad184[0x208 - 0x184];
    s16 x208;
    u8 pad20a[0x25c - 0x20a];
    Rec_8011F000 *x25c;
} Obj_8011F000;
typedef struct Hold_8011F000 {
    u8 pad0[8];
    Obj_8011F000 *obj;
} Hold_8011F000;
typedef struct Arg1_8011F000 {
    u8 pad0[0x1d8];
    Hold_8011F000 *x1d8;
} Arg1_8011F000;
typedef struct Arg2_8011F000 {
    u8 pad0[0x1c];
    Rec_8011F000 *x1c;
} Arg2_8011F000;
typedef struct Sub_8011F274 {
    u8 pad0[0x50];
    f32 x50;
    f32 x54;
    f32 x58;
} Sub_8011F274;
typedef struct Rec_8011F274 {
    u32 flags;
    u8 pad4[0xc];
    s32 x10;
    s32 x14;
    u8 pad18[0x2c - 0x18];
    f32 x2c;
    f32 x30;
    f32 x34;
    s32 x38;
    s32 x3c;
    Sub_8011F274 *x40;
} Rec_8011F274;
extern f32 lbl_802B3214[9];
extern f32 lbl_802B3238[9];
typedef struct Pt_8011FC10 {
    f32 x, y, z;
    u32 col;
} Pt_8011FC10;
typedef struct Item_8011FC10 {
    Pt_8011FC10 p[4];
} Item_8011FC10;
typedef struct Part_8011FC10 {
    f32 cx, cy, cz;
    f32 xc;
    f32 x10;
    f32 x14;
    f32 x18;
    u8 pad1c[0x2c - 0x1c];
    s32 r[3];
    u8 pad38[0x50 - 0x38];
    f32 x50;
    u32 x54;
} Part_8011FC10;
typedef struct Rec_8011FC10 {
    u32 flags;
    u8 pad4[0x18];
    Item_8011FC10 *items;
    Part_8011FC10 *parts;
    s32 count;
} Rec_8011FC10;
typedef union Col_8011FC10 {
    u32 u;
    u8 b[4];
} Col_8011FC10;
extern const u32 lbl_8034A030;
extern s32 rand(void);
typedef struct Pt_8011FE2C {
    f32 x, y, z, w;
} Pt_8011FE2C;
typedef struct Item_8011FE2C {
    Pt_8011FE2C p[4];
} Item_8011FE2C;
typedef struct Part_8011FE2C {
    f32 cx, cy, cz;
    u8 pad0c[0x2c - 0xc];
    s32 ax;
    s32 ay;
    s32 az;
    u8 pad38[0x58 - 0x38];
} Part_8011FE2C;
typedef struct Rec_8011FE2C {
    u8 pad0[0x1c];
    Item_8011FE2C *items;
    Part_8011FE2C *parts;
    s32 count;
} Rec_8011FE2C;
void fn_8011FE2C(Rec_8011FE2C *r);
typedef struct W_80120A90 {
    u32 flags;
    u8 _04[8];
    s32 v;
    u8 _10[0x60];
    void* owner;
    u8 _74[8];
} W_80120A90;
typedef struct Sub_80120A90 {
    u8 _00[0x1a0];
    s32 f1a0;
} Sub_80120A90;
typedef struct M_80120A90 {
    u8 _00[0x1d8];
    Sub_80120A90* sub;
    u8 _1dc[0x10];
    s8 f1ec;
    u8 _1ed[4];
    s8 f1f1;
    u8 _1f2[8];
    u8 f1fa;
    u8 f1fb;
    u8 _1fc[0x60];
    W_80120A90* work;
    u8 _260[0xc];
    u8 f26c;
} M_80120A90;
typedef struct T_80120A90 {
    u8 _00[0x18];
    u8 flags;
    u8 state;
    u8 _1a;
    u8 f1b;
    u8 _1c[8];
    M_80120A90* m;
} T_80120A90;
typedef struct W_80121918 {
    u32 flags;
    u8 _04[8];
    s32 v;
    u8 _10[0x20];
    void* buf;
    u8 _34[0x48];
    void* owner;
    u8 _80[4];
} W_80121918;
typedef struct M_80121918 {
    u8 _00[0x1ec];
    s8 f1ec;
    u8 _1ed[4];
    s8 f1f1;
    u8 _1f2[8];
    u8 f1fa;
    u8 f1fb;
    u8 _1fc[0x60];
    W_80121918* work;
    u8 _260[0xc];
    u8 f26c;
} M_80121918;
typedef struct T_80121918 {
    u8 _00[0x18];
    u8 flags;
    u8 state;
    u8 _1a;
    u8 f1b;
    u8 _1c[8];
    M_80121918* m;
} T_80121918;
typedef struct Obj_80124428 {
    u8 _00[0x18c];
    f32 f18c;
} Obj_80124428;
typedef struct In_80124428 {
    u8 _00[4];
    s8 kind;
    s8 arg;
} In_80124428;
extern u8* lbl_80346FC8[2];
typedef struct Obj_80124A7C {
    u8 _00[0x50];
    f32 f50;
    u8 _54[4];
    f32 f58;
    u8 _5c[0x5c];
    f32 fb8;
    u8 _bc[0xd0];
    f32 f18c;
} Obj_80124A7C;
typedef struct In_80124A7C {
    u8 _00[5];
    s8 f5;
    u8 _06[0x2a];
    s16 h30;
} In_80124A7C;
typedef struct Rec_80125820 {
    f32 pos[3];
    s32 v[3];
    f32 extra[3];
} Rec_80125820;
typedef struct Obj_80125820 {
    u8 _00[0x38];
    f32 pos[3];
} Obj_80125820;
typedef struct In_80125820 {
    u8 _00[5];
    s8 f5;
    u8 _06[4];
    s16 h0a;
    u8 _0c[0xb];
    s8 b17;
    u8 _18[8];
    s16 h20;
    u8 _22[0x16];
    f32 pos[3];
    u8 _44[0xdc];
    f32 f120;
} In_80125820;
extern void fn_80157684(Rec_80125820* out, s32 a, f32 t);
extern void fn_80126F0C(void* o, void* in);
typedef struct Ship_80127F20 {
    u8 _00[4];
    u8 f4;
    u8 _05[0x2f];
    s16 h34;
} Ship_80127F20;
typedef struct Pl_80127F20 {
    u8 _00[0xa70];
    s32 fa70;
} Pl_80127F20;
typedef struct W_80127F20 {
    Ship_80127F20* ship;
    u8* f4;
} W_80127F20;
typedef struct M_80127F20 {
    u8 _00[0x100];
    void* f100;
    u8 _104[0xe0];
    void* f1e4;
    u8 _1e8[0x54];
    W_80127F20* f23c;
} M_80127F20;
typedef struct T_80127F20 {
    u8 _00[0x19];
    u8 state;
    u8 _1a[0xa];
    M_80127F20* m;
} T_80127F20;
typedef struct Tbl_801186D8 {
    f32 t[2];
    f32 pos[2][3];
    s32 count;
    s32 a[3];
    s32 b[3];
    f32 c[3];
    f32 d[3];
    f32 e[3];
    f32 f[3];
} Tbl_801186D8;
typedef struct New_801186D8 {
    f32 x38;
    f32 x3c;
    f32 x40;
    s32 x44;
    s32 x48;
    s32 x4c;
} New_801186D8;
typedef struct Spawn_801186D8 {
    u8 pad0[0x38];
    f32 x38;
    f32 x3c;
    f32 x40;
    s32 x44;
    s32 x48;
    s32 x4c;
    u8 pad50[0xb4 - 0x50];
    f32 xb4;
    f32 xb8;
    f32 xbc;
    u8 padc0[0xe4 - 0xc0];
    s32 xe4;
    s32 xe8;
    u8 padec[0x100 - 0xec];
    s32 *x100;
    u8 pad104[0x16c - 0x104];
    s16 x16c;
    u8 pad16e[0x190 - 0x16e];
    f32 x190;
    u8 pad194[0x24c - 0x194];
    f32 x24c;
    f32 x250;
    f32 x254;
    f32 x258;
} Spawn_801186D8;
typedef struct Res_801186D8 {
    u8 pad0[0x14];
    s32 **x14;
    u8 pad18[4];
    s32 *x1c;
} Res_801186D8;
typedef struct Hdr_801186D8 {
    u8 pad0[0x24];
    u16 x24;
} Hdr_801186D8;
typedef struct Obj_801186D8 {
    u8 pad0[0x38];
    f32 x38;
    f32 x3c;
    f32 x40;
    s32 x44;
    s32 x48;
    s32 x4c;
    u8 pad50[0x170 - 0x50];
    u16 x170;
    u8 pad172[0x18c - 0x172];
    f32 x18c;
    f32 x190;
    u8 pad194[0x19c - 0x194];
    s32 x19c;
    u8 pad1a0[0x1b8 - 0x1a0];
    Hdr_801186D8 *x1b8;
    u8 pad1bc[0x1c8 - 0x1bc];
    Res_801186D8 *x1c8;
} Obj_801186D8;
extern Task *lbl_80347454;
extern void fn_8010DEE8(Task *t);
extern Task *fn_801C6180(Task *parent, void (*func)(Task *));
typedef struct Len_8010ECD8 {
    u32 w0;
    u32 len;
} Len_8010ECD8;
typedef struct Obj_8010ECD8 {
    u8 pad0[0x38];
    u8 vec38[0x24];
    u8 pad_5c[0xC8 - 0x5C];
    s32 wc8;
    u8 pad_cc[0xE8 - 0xCC];
    Len_8010ECD8 *pe8;
    u8 pad_ec[0x104 - 0xEC];
    u8 vec104[0x24];
    u8 pad_128[0x164 - 0x128];
    f32 pos;
    u8 pad_168[0x16C - 0x168];
    s16 h16c;
    u8 pad_16e[0x170 - 0x16E];
    s16 h170;
    s16 h172;
    u8 pad_174[0x18C - 0x174];
    f32 f18c;
    f32 f190;
    u8 pad_194[0x1A0 - 0x194];
    f32 f1a0;
    u8 pad_1a4[0x1A8 - 0x1A4];
    f32 f1a8;
} Obj_8010ECD8;
extern s32 lbl_80347504;
extern s32 lbl_8034743C;
extern f32 lbl_8034742C;
extern f32 fn_8010EB88(void *p);
extern s32 MemEqual(const void *a, const void *b, s32 size);
typedef struct Len_8010F198 {
    u32 w0;
    u32 len;
} Len_8010F198;
typedef struct Obj_8010F198 {
    u8 pad0[0x38];
    u8 vec38[0x24];
    u8 pad_5c[0xC8 - 0x5C];
    s32 wc8;
    u8 pad_cc[0xE8 - 0xCC];
    Len_8010F198 *pe8;
    u8 pad_ec[0x104 - 0xEC];
    u8 vec104[0x24];
    u8 pad_128[0x164 - 0x128];
    f32 pos;
    u8 pad_168[0x16C - 0x168];
    s16 h16c;
    u8 pad_16e[0x170 - 0x16E];
    s16 h170;
    s16 h172;
    u8 pad_174[0x18C - 0x174];
    f32 f18c;
    f32 f190;
    u8 pad_194[0x1A0 - 0x194];
    f32 f1a0;
    u8 pad_1a4[0x1A8 - 0x1A4];
    f32 f1a8;
} Obj_8010F198;
extern f32 lbl_80347430;
typedef struct Obj_801115EC {
    u8 pad0[0xC8];
    s32 wc8;
    u8 pad_cc[0x164 - 0xCC];
    f32 f164;
    u8 pad_168[0x16C - 0x168];
    s16 h16c;
    u8 pad_16e[0x170 - 0x16E];
    s16 h170;
    s16 h172;
    u8 pad_174[0x18C - 0x174];
    f32 f18c;
    f32 f190;
    u8 pad_194[0x1E0 - 0x194];
    f32 f1e0;
} Obj_801115EC;
extern s32 lbl_803474F4;
extern s32 lbl_80347578;
extern f32 fn_801D72A0(s32 a, s32 b);
typedef struct Task_8011B448 {
    u8 pad0[0x18];
    u8 flags;
    u8 state;
    u8 pad1a;
    u8 x1b;
    u8 pad1c[0x24 - 0x1c];
    void *work;
} Task_8011B448;
typedef struct Rec_8011B448 {
    u8 pad0[0x24];
    void *x24;
} Rec_8011B448;
typedef struct Sub_8011B448 {
    u8 pad0[0x1a0];
    s32 x1a0;
} Sub_8011B448;
typedef struct Work_8011B448 {
    u8 pad0[0x1d8];
    Sub_8011B448 *x1d8;
    u8 pad1dc[0x1fa - 0x1dc];
    u8 x1fa;
    u8 x1fb;
    u8 pad1fc[0x25c - 0x1fc];
    void *x25c;
    u8 pad260[0x26c - 0x260];
    u8 x26c;
} Work_8011B448;
extern void *fn_801E1A2C(s32 a, u32 size);
extern void fn_8015EB8C(void *p, s32 id, void *cb);
extern int fn_8011B290();
extern int fn_8011B288();
extern s32 fn_8011B298(void *work, void *rec);
typedef struct Task_8011CC74 {
    u8 pad0[0x18];
    u8 flags;
    u8 state;
    u8 pad1a;
    u8 x1b;
    u8 pad1c[0x24 - 0x1c];
    void *work;
} Task_8011CC74;
typedef struct Rec_8011CC74 {
    s32 x0;
    s32 x4;
} Rec_8011CC74;
typedef struct Res_8011CC74 {
    u32 x0;
} Res_8011CC74;
typedef struct Sub_8011CC74 {
    u8 pad0[0x10];
    Res_8011CC74 *x10;
} Sub_8011CC74;
typedef struct Sub2_8011CC74 {
    u8 pad0[0x1a0];
    s32 x1a0;
} Sub2_8011CC74;
typedef struct Spawn_8011CC74 {
    u8 pad0[0x24];
    Rec_8011CC74 *x24;
    void *x28;
    Task_8011CC74 *x2c;
} Spawn_8011CC74;
typedef struct Work_8011CC74 {
    u8 pad0[0x1c8];
    Sub_8011CC74 *x1c8;
    u8 pad1cc[0x1d8 - 0x1cc];
    Sub2_8011CC74 *x1d8;
    u8 pad1dc[0x1fa - 0x1dc];
    u8 x1fa;
    u8 pad1fb[0x25c - 0x1fb];
    void *x25c;
    u8 pad260[0x264 - 0x260];
    Spawn_8011CC74 *x264;
} Work_8011CC74;
extern int fn_8011CE64();
extern int fn_8011CC6C();
typedef struct Obj_80126BF0 {
    u8 _00[0x190];
    f32 f190;
} Obj_80126BF0;
typedef struct In_80126BF0 {
    u8 _00[4];
    s8 kind;
    u8 _05[0x12];
    u8 b17;
    u8 b18;
    u8 _19[0xb];
    s32 f24;
    u8 _28[0x44];
    FormTbl tab;
} In_80126BF0;
extern s32 fn_80128B34(FormTbl* t);
extern s32 fn_80128E7C(FormTbl* t);
extern s32 fn_80128DA4(FormTbl *t);
extern s32 fn_80128938(FormTbl* t);
extern u8 fn_801286F4(FormTbl* t);
extern u8 fn_8012813C(FormTbl* t);
extern u8 fn_80128670(FormTbl* t);
extern u8 fn_801285D8(FormTbl* t);
extern s32 fn_801282C4(FormTbl *t);
extern s32 fn_801281E8(FormTbl *t);
extern u8 fn_80128414(FormTbl* t);
extern s32 fn_801283A4(FormTbl *t);
extern u8 fn_80128108(FormTbl *t);
typedef struct {
    f32 x, y, z;
    s32 a, b, c;
    s32 pad[3];
} Xf;
typedef struct {
    u8 pad0[0x38];
    f32 x, y, z;    /* 0x38 */
    s32 ra, rb, rc; /* 0x44 */
    u8 pad50[0xe8 - 0x50];
    void *anim;     /* 0xE8 */
    u8 padec[0x104 - 0xec];
    f32 px, py, pz; /* 0x104 */
    s32 pra, prb, prc; /* 0x110 */
    u8 pad11c[0x170 - 0x11c];
    s16 f170;
    u16 f172;
    u8 pad174[0x18c - 0x174];
    f32 f18c;
    f32 f190;
    u8 pad194[4];
    s32 state;      /* 0x198 */
    s32 f19c;
} Obj_80111C38;
typedef struct Obj_80111A78 {
    u8 pad0[0x38];
    f32 f38, f3c, f40;
    s32 w44, w48, w4c;
    u8 pad_50[0xE8 - 0x50];
    void *pe8;
    u8 pad_ec[0x104 - 0xEC];
    f32 f104, f108, f10c;
    s32 w110, w114, w118;
    u8 pad_11c[0x170 - 0x11C];
    s16 h170;
    u16 h172;
    u8 pad_174[0x18C - 0x174];
    f32 f18c;
    f32 f190;
    u8 pad_194[0x198 - 0x194];
    s32 w198;
    s32 w19c;
    u8 pad_1c4[4];
} Obj_80111A78;
typedef struct Delta_80111A78 {
    f32 x, y, z;
    s32 rx, ry, rz;
    s32 rest[3];
} Delta_80111A78;
typedef struct Y_80111DE8 {
    s32 count;
    u8 pad4[0xA8];
    void *wac;
} Y_80111DE8;
typedef struct Obj_80111DE8 {
    u8 pad0[0x38];
    f32 f38, f3c, f40;
    s32 w44, w48, w4c;
    u8 pad_50[0xE8 - 0x50];
    void *pe8;
    u8 pad_ec[0x104 - 0xEC];
    f32 f104, f108, f10c;
    s32 w110, w114, w118;
    u8 pad_11c[0x170 - 0x11C];
    s16 h170;
    u16 h172;
    u8 pad_174[0x18C - 0x174];
    f32 f18c;
    f32 f190;
    u8 pad_194[0x198 - 0x194];
    s32 w198;
    s32 w19c;
    u8 pad_1a0[0x1C8 - 0x1A0];
    struct { u8 pad0[0x1C]; Y_80111DE8 *y; } *p1c8;
} Obj_80111DE8;
typedef struct Delta_80111DE8 {
    f32 x, y, z;
    s32 rx, ry, rz;
    s32 rest[3];
} Delta_80111DE8;
typedef struct {
    u8 pad0[0x38];
    f32 x, y, z;    /* 0x38 */
    s32 ra, rb, rc; /* 0x44 */
    u8 pad50[0xe8 - 0x50];
    void *anim;     /* 0xE8 */
    u8 padec[0x104 - 0xec];
    f32 px, py, pz; /* 0x104 */
    s32 pra, prb, prc; /* 0x110 */
    u8 pad11c[0x170 - 0x11c];
    s16 f170;
    u16 f172;
    u8 pad174[0x18c - 0x174];
    f32 f18c;
    f32 f190;
    u8 pad194[4];
    s32 state;      /* 0x198 */
    s32 f19c;
} Obj_80113934;
extern f32 lbl_80347424;
typedef struct Pad_80311A60 {
    u8 pad0[8];
    u32 x8;
    u8 padc[0x14 - 0xC];
    s16 x;      /* 0x14 */
    s16 y;      /* 0x16 */
} Pad_80311A60;
extern double atan2(double y, double x);
extern f32 fn_80291A5C(f32 v);
typedef struct Res_8011605C {
    u8 pad0[8];
    u32 x8;
    u8 padC[4];
    u16 x10;
    s16 x12;
    u8 pad14[4];
    f32 *x18;
    u8 pad1C[4];
    u32 *x20;
} Res_8011605C;
typedef struct Ext_8011605C {
    u8 pad0[4];
    u32 x4;
} Ext_8011605C;
typedef struct Chr_8011605C {
    u8 pad0[0x38];
    f32 pos[3];
    u32 ang[3];
    u8 pad50[0x1C0 - 0x50];
    Res_8011605C *res;
    u8 pad1C4[4];
    Ext_8011605C *ext;
} Chr_8011605C;
typedef struct Cfg {
    u8 a[0x34];
    u8 b[0x60];
    u8 pad[0xA4 - 0x94];
} Cfg;
extern u8 lbl_80305E18[];
extern void fn_80222964(void *p);
extern Res_8011605C *fn_80222224(void *p);
typedef struct V_80124634 {
    f32 x, y, z;
} V_80124634;
typedef struct Rec_80124634 {
    f32 pos[3];
    s32 v[3];
} Rec_80124634;
typedef struct Tbl_80124634 {
    s32 n;
    s32 e[1];
} Tbl_80124634;
typedef struct Own_80124634 {
    u8 _00[0x1c];
    Tbl_80124634* tbl;
} Own_80124634;
typedef struct Obj2_80124634 {
    u8 _00[0x38];
    V_80124634 pos;
    u8 _44[0xa4];
    s32 fe8;
    u8 _ec[4];
    s32 ff0;
    u8 _f4[0x98];
    f32 f18c;
    u8 _190[8];
    s32 f198;
    s32 f19c;
    f32 f1a0;
    f32 f1a4;
    u8 _1a8[0x20];
    Own_80124634* own;
} Obj2_80124634;
typedef struct In_80124634 {
    u8 _00[4];
    s8 kind;
    s8 f5;
    s8 f6;
    s8 f7;
    u8 _08[0xf];
    u8 b17;
    u8 _18[2];
    s16 h1a;
    u8 _1c[0x18];
    s16 h34;
    u8 _36[0x1e];
    V_80124634 v54;
} In_80124634;
typedef struct Tbl_80126118 {
    s32 n;
    s32 e[1];
} Tbl_80126118;
typedef struct Own_80126118 {
    u8 _00[0x1c];
    Tbl_80126118* tbl;
} Own_80126118;
typedef struct Cur_80126118 {
    u8 _00[4];
    s32 f4;
} Cur_80126118;
typedef struct Obj_80126118 {
    u8 _00[0xe8];
    Cur_80126118* fe8;
    u8 _ec[4];
    s32 ff0;
    u8 _f4[0x98];
    f32 f18c;
    f32 f190;
    s32 f194;
    s32 f198;
    s32 f19c;
    f32 f1a0;
    f32 f1a4;
    u8 _1a8[0x20];
    Own_80126118* own;
} Obj_80126118;
typedef struct In_80126118 {
    u8 _00[5];
    s8 f5;
    s8 f6;
    s8 f7;
    u8 _08[0xa];
    s8 f12;
    s8 f13;
    u8 _14[3];
    s8 f17;
    u8 _18[2];
    s16 h1a;
    u8 _1c[0x50];
    s8 tab[0xc0];
    f32 f12c;
    f32 f130;
} In_80126118;
typedef struct Cur_801276E8 {
    u8 _00[4];
    s32 f4;
} Cur_801276E8;
typedef struct Obj_801276E8 {
    u8 _00[0xe8];
    Cur_801276E8* fe8;
    u8 _ec[0xa0];
    f32 f18c;
    f32 f190;
} Obj_801276E8;
typedef struct Rec_801276E8 {
    u8 _00;
    u8 b1;
    u8 b2;
    u8 _03;
    s8 b4;
    s8 b5;
    s16 h6;
    s16 h8;
    u8 _0a[2];
    s32 w0c;
    u8 _10[4];
} Rec_801276E8;
typedef struct In_801276E8 {
    u8 _00[5];
    s8 f5;
    s8 f6;
    u8 _07;
    s16 h8;
    u8 _0a[2];
    s16 h0c;
    s16 h0e;
    s8 f10;
    s8 f11;
    u8 _12[5];
    s8 f17;
    u8 _18[2];
    s16 h1a;
    s16 h1c;
    s16 h1e;
    u8 _20[0xc];
    s32 f2c;
    u8 _30[0x3c];
    u8 tab[0xc4];
} In_801276E8;
typedef struct Ship_80127994 {
    u8 _00[4];
    u8 f4;
    u8 _05[0x12f];
    s32 f134;
    u8 _138[4];
    void* f13c;
} Ship_80127994;
typedef struct W_80127994 {
    Ship_80127994* ship;
    u8* f4;
} W_80127994;
typedef struct Cfg_80127994 {
    s32 count;
    u8 _04[0x34];
    s32 f38;
    s32 f3c;
} Cfg_80127994;
typedef struct Foe_80127994 {
    u8 _00[0x24];
    struct {
        u8 _00[0x23c];
        void* f23c;
    }* data;
} Foe_80127994;
typedef struct Aux_80127994 {
    u8 _00[4];
    u8* f4;
} Aux_80127994;
typedef struct M_80127994 {
    u8 _00[0x100];
    void* f100;
    u8 _104[0x76];
    u16 h17a;
    u8 _17c[0x4c];
    struct {
        u8 _00[0x10];
        Cfg_80127994* cfg;
    }* src;
    u8 _1cc[0x1c];
    Foe_80127994* foe;
    u8 _1ec[0x50];
    W_80127994* f23c;
    Aux_80127994* f240;
} M_80127994;
typedef struct T_80127994 {
    u8 _00[0x19];
    u8 state;
    u8 _1a[0xa];
    M_80127994* m;
} T_80127994;
extern void fn_80227810(void* texlist);
extern W_80127994* fn_80125D40(void* m);
extern void* fn_801094C8(u32 key);
extern void fn_80156B04(void*, void*, s32, s32, void*);
extern void fn_80124CE4(void* m, void* w);
typedef struct Rec_80127BC0 {
    f32 pos[3];
    s32 v[3];
    f32 extra[3];
} Rec_80127BC0;
typedef struct Ship_80127BC0 {
    u8 _00[4];
    s8 kind;
    s8 f5;
    s8 f6;
    u8 _07[0x10];
    s8 b17;
    u8 _18[2];
    s16 h1a;
    u8 _1c[4];
    s16 h20;
    u8 _22[0x10];
    s16 h32;
    u8 _34[0x1c];
    s32 f50;
    f32 pos[3];
    s32 v[3];
} Ship_80127BC0;
typedef struct W_80127BC0 {
    Ship_80127BC0* ship;
    u8 _04[4];
    s32* f8;
} W_80127BC0;
typedef struct M_80127BC0 {
    u8 _00[0x23c];
    W_80127BC0* f23c;
} M_80127BC0;
typedef struct Res_80118204 {
    u8 pad0[0x18];
    f32 *x18;
    u8 pad1C[4];
    s32 *x20;
    f32 *x24;
    f32 *x28;
} Res_80118204;
typedef struct Chr_80118204 {
    u8 pad0[0x38];
    f32 pos[3];
    s32 ang[3];
    u8 pad50[0xB4 - 0x50];
    f32 b4[3];
    f32 c0[3];
    u8 padCC[0x1BC - 0xCC];
    Res_80118204 *x1bc;
    Res_80118204 *x1c0;
} Chr_80118204;
typedef struct PadInfo_80118204 { Pad_80311A60 *pad; u8 pad4[0x14]; } PadInfo_80118204;
extern s32 lbl_80347508;
extern s8 fn_8009763C(void);
typedef struct { f32 x, y, z; } Vec3;
typedef struct Obj_80117B9C {
    u8 pad0[0xb4];
    f32 xb4;
    f32 xb8;
    f32 xbc;
    s32 xc0;
    s32 xc4;
    s32 xc8;
    u8 padcc[0x16c - 0xcc];
    s16 x16c;
} Obj_80117B9C;
typedef struct { u8 pad[0x20]; s32 x20; } Sub_8012A900;
typedef struct { u8 pad[4]; Sub_8012A900 *x4; } Obj_8012A900;
typedef struct {
    s32 x0;
    f32 x4;
    f32 x8;
    s32 xc;
    s32 x10;
    f32 x14;
    f32 x18;
} Arg_8012A900;
extern void fn_801D5DD8(s32 a, f32 e, f32 f, f32 g, f32 h, s32 b, s32 c, f32 i, f32 j, s32 d);
typedef struct Hdr { u32 n; u8 pad4[0x20]; s32 w24; } Hdr;
typedef struct Cfg_8011DD9C { u8 pad0[0x10]; Hdr *hdr; } Cfg_8011DD9C;
typedef struct Sub { u32 flags; u8 pad4[0x84]; void *p88; u8 pad8c[0xd8 - 0x8c]; } Sub;
typedef struct C1d8 { u8 pad0[0x1a0]; s32 w1a0; } C1d8;
typedef struct Ctx_8011DD9C {
    u8 pad0[0x17a];
    u16 u17a;
    u8 pad17c[0x1c8 - 0x17c];
    Cfg_8011DD9C *cfg;
    u8 pad1cc[0x1d8 - 0x1cc];
    C1d8 *p1d8;
    u8 pad1dc[0x1fa - 0x1dc];
    char b1fa;
    char b1fb;
    u8 pad1fc[0x25c - 0x1fc];
    Sub *sub;
    u8 pad260[0x26c - 0x260];
    u8 b26c;
} Ctx_8011DD9C;
typedef struct Obj_8011DD9C {
    u8 pad0[0x18];
    u8 flags;
    u8 state;
    u8 pad1a;
    u8 b1b;
    u8 pad1c[4];
    f32 f20;
    Ctx_8011DD9C *ctx;
} Obj_8011DD9C;
extern void *lbl_80346720;
extern f32 lbl_80349FF8;
extern void *fn_80005B50(void *a, s32 n);
extern void fn_80005AD8(void *a, void *b);
extern void fn_8011E72C(void);
extern void fn_8020F154(s32 a, s32 b);
extern s32 fn_8011D958(Ctx_8011DD9C *c, Sub *s, s32 a);
extern f32 fn_8011A8B0(Vec3 *a, Vec3 *b);
extern s32 fn_80156A8C(s32 x);
extern void fn_801575C8(void *a, s32 b, f32 c);
extern void fn_80120C64(void *o, void *p);
typedef struct {
    u8 pad0[0x10];
    struct { u8 pad[0x24]; } *x10;
    struct {
        u8 x0[0x10];
        s32 x10;
        u8 x14[8];
    } ent[1];
} B;
typedef struct {
    u32 flags;
    u8 pad4[4];
    s32 x8;
    u8 padc[8];
    s16 x14;
    s16 x16;
    Vec3 pos;
    u8 pad24[0x38];
    u8 *x5c;
    u8 *x60;
    u8 *x64;
    u8 *x68;
    u8 *x6c;
} O;
typedef struct {
    u8 pad0[0x38];
    Vec3 pos;
    u8 pad44[0x1e4 - 0x44];
    B *x1e4;
    u8 pad1e8[5];
    s8 x1ed;
    s8 x1ee;
    u8 pad1ef;
    s8 x1f0;
    u8 pad1f1[0x22c - 0x1f1];
    u16 x22c;
    u16 x22e;
} A;
typedef struct {
    u32 x0;
    u8 pad4[0x20];
    s32 x24;
    u8 pad28[0x10];
    s32 x38;
    u8 pad3c[0x10];
    f32 x4c, x50, x54, x58;
} Inner_80123A44;
typedef struct {
    u8 pad0[0x1c8];
    struct { u8 pad0[0x10]; Inner_80123A44 *x10; } *x1c8;
    u8 pad1cc[0x20c - 0x1cc];
    s32 x20c;
    s32 x210;
    u8 pad214[0x25c - 0x214];
    void *x25c;
    u8 pad260[0xc];
    u8 x26c;
} Q_80123A44;
typedef struct {
    u8 pad0[0x19];
    u8 state;
    u8 pad1a[0xa];
    Q_80123A44 *q;
} P_80123A44;
extern s32 lbl_803473AC;
extern void fn_801237EC(Q_80123A44 *q);
extern s32 fn_8015F218(Q_80123A44 *q);
extern void fn_801231F8(Q_80123A44 *q);
typedef struct {
    f32 x, y, z;
} Vec3_8010F3A8;
typedef struct {
    s32 x, y, z;
} Ang3_8010F3A8;
typedef struct {
    u8 pad0[0x44];
    Ang3_8010F3A8 ang;
    u8 pad50[0xc0 - 0x50];
    Ang3_8010F3A8 start;
    Vec3_8010F3A8 xcc;
    Vec3_8010F3A8 xd8;
    u8 pad_e4[0x170 - 0xe4];
    u16 h170;
    u16 h172;
    u8 pad_174[0x18c - 0x174];
    f32 f18c;
} Obj_8010F3A8;
extern void fn_801DD3B8(void* a, void* b, void* c);
extern void fn_801DD22C(void* a, void* b, void* c);
extern void fn_8010E5BC(Obj_8010F3A8* o);
typedef struct {
    f32 x, y, z;
} Vec3_80114950;
typedef struct {
    f32 height;
    u32 flags;
    u8 pad8[0x20 - 8];
} Row_80114950;
typedef struct {
    u8 pad0[0x38];
    Vec3_80114950 pos;
    u8 pad44[0x1bc - 0x44];
    void* x1bc;
} Chr_80114950;
extern int fn_80115A4C(f32* pos, u16* out, HitObj* obj);
typedef struct {
    f32 x, y, z;
} Vec3_80116898;
extern f32 lbl_80305DF8[8];
/* last 4 (x, z) samples */
extern s32 lbl_80346EA0;
typedef struct {
    u8 pad0[0x14];
    NJS_POINT3 pos;
} Out_801222A8;
typedef struct {
    u8 pad0[0x38];
    NJS_POINT3 pos;
} Src_801222A8;
extern f32 lbl_80345878[];
extern void fn_80291C44(NJS_MATRIX m);
typedef struct {
    u8 pad0[0x10];
    u8* x10;
} Mdl_8012239C;
typedef struct {
    u8 pad0[0x38];
    Vec3 pos;
    u8 pad44[0x17a - 0x44];
    u16 x17a;
    u8 pad17c[0x1c8 - 0x17c];
    Mdl_8012239C* x1c8;
} Chr_8012239C;
typedef struct {
    u8 pad0[0x24];
    Chr_8012239C* x24;
} B10_8012239C;
typedef struct {
    u8 pad0[0x10];
    s32 x10;
} Sub_8012239C;
typedef struct {
    u8 pad0[0x10];
    B10_8012239C* x10;
    u8 pad14[0x68 - 0x14];
    Sub_8012239C sub;
} B_8012239C;
typedef struct {
    u8 pad0[0x38];
    Vec3 pos;
    u8 pad44[0x1e4 - 0x44];
    B_8012239C* x1e4;
    u8 pad1e8[0x22c - 0x1e8];
    u16 x22c;
    u16 x22e;
} A_8012239C;
typedef struct {
    u32 flags;
    u8 pad4[0x8 - 0x4];
    s32 x8;
    u8 padc[0x14 - 0xc];
    Vec3 pos;
    u8 pad20[0x2c - 0x20];
    u8* x2c;
    u8 pad30[0x38 - 0x30];
    u8 x38[0x64 - 0x38];
    u16 x64;
    u16 x66;
    Chr_8012239C* x68;
    u8* x6c;
    u8* x70;
    Sub_8012239C* x74;
    u8* x78;
} O_8012239C;
extern void fn_80121B24(O_8012239C* o, u8* p);
typedef struct {
    u8 pad0[0xe8];
    Clock* clock;
    u8 padec[0x18c - 0xec];
    f32 f18c;
    f32 f190;
} Ctx_80125B60;
typedef struct {
    s8 id;
    u8 pad1;
    s8 seq[12];
} Row_80125B60;
typedef struct {
    Row_80125B60 rows[1];
    u8 pad0e[0xc0 - 0xe];
    f32 f0c0;
    f32 f0c4;
} Sub_80125B60;
typedef struct {
    u8 pad0[5];
    s8 b5;
    s8 b6;
    s8 b7;
    u8 pad8[0xe - 8];
    s16 se;
    u8 b10;
    u8 pad11;
    s8 b12;
    u8 pad13[0x17 - 0x13];
    s8 b17;
    u8 pad18[2];
    s16 s1a;
    u8 pad1c[0x6c - 0x1c];
    Sub_80125B60 sub;
} Obj_80125B60;
typedef struct {
    u8 pad0[8];
    void* p;
} Ent_80308F98;
typedef struct {
    u8 pad0[0x2e];
    s16 kind;
    u8 pad30[0xe];
} Ent_8034727C;
extern s32 lbl_80347280;
extern s32 lbl_80346EE8;
extern s32 lbl_803472C8;
extern void* lbl_803472A0;
extern s32 lbl_803473EC;
extern s32 lbl_803473E8;
extern Ent_8034727C* lbl_8034727C;
extern Ent_80308F98 lbl_80308F98[];
extern void fn_80158A80(void);
extern void fn_8015C6A8(void);
extern void fn_80156024(void);
extern void fn_80142F88(void);
extern void fn_8012A9FC(void);
extern void fn_8015C618(void);
extern void fn_80148DDC(void);
extern void fn_80217CB0(void);
extern void fn_801CBC10(void);
typedef struct {
    u8 pad0[0x20c];
    s32 frame;
} Obj_801295EC;
typedef struct {
    u8 pad0[0x19];
    u8 state;
    u8 pad1[0x0a];
    Obj_801295EC* inner;
} Parent_801295EC;
extern void fn_801E735C(u32 index, f32 speed, Obj_801295EC* obj);
typedef struct {
    f32 x, y, z;
} Vec3_8010F924;
typedef struct {
    s32 x, y, z;
} Ang3_8010F924;
typedef struct {
    u8 pad0[0x20];
    Ang3_8010F924* ang;
} Model_8010F924;
typedef struct {
    u8 pad0[0x38];
    Vec3_8010F924 pos;
    Ang3_8010F924 ang;
    u8 pad50[0x100 - 0x50];
    void* texlist;
    Vec3_8010F924 prev;
    u8 pad110[0x1b8 - 0x110];
    void* x1b8;
    Model_8010F924* model;
    u8 pad1c0[0x20c - 0x1c0];
    Ang3_8010F924 ang2;
} Work_8010F924;
typedef struct {
    u8 pad0[0x19];
    u8 state;
    u8 pad1a[0x24 - 0x1a];
    void* work;
} Obj_8010F924;
extern void* fn_802258BC(s32 a, s32 b, s32 c);
extern void fn_801E66E0(Work_8010F924* w);
typedef struct Hdr_8010F648 {
    s32 n;
    s32 a[11];
} Hdr_8010F648;
typedef struct Cfg_8010F648 {
    u8 pad0[0x10];
    Hdr_8010F648 *hdr;
    u8 pad14[0x44 - 0x14];
    NJS_POINT3 pos;
} Cfg_8010F648;
typedef struct Ctx_8010F648 {
    u8 pad0[0x38];
    NJS_POINT3 pos;     /* 0x38 */
    NJS_POINT3 rot;     /* 0x44 */
    u8 pad50[0x100 - 0x50];
    void *tex;          /* 0x100 */
    NJS_POINT3 pos2;    /* 0x104 */
    u8 pad110[0x17a - 0x110];
    u16 u17a;
    u8 pad17c[0x1bc - 0x17c];
    void *p1bc;
    u8 pad1c0[8];
    Cfg_8010F648 *cfg;
} Ctx_8010F648;
typedef struct Obj_8010F648 {
    u8 pad0[0x19];
    u8 state;
    u8 pad1a[0xa];
    Ctx_8010F648 *ctx;
} Obj_8010F648;
typedef struct Rec_8010F648 { u8 pad0[0x24]; Ctx_8010F648 *ctx; } Rec_8010F648;
typedef struct Gfx { u8 pad0[0x1c]; NJS_POINT3 *p1c; u8 pad20[4]; NJS_POINT3 *p24; } Gfx;
extern char lbl_802B30FC[];
extern Gfx *fn_80225B74(s32 a, s32 b);
typedef struct Obj_80112868 {
    u8 pad0[0x38];
    f32 f38, f3c, f40;
    s32 w44, w48, w4c;
    u8 pad_50[0xb4 - 0x50];
    f32 fb4[3];
    f32 fc0[3];
    u8 pad_cc[0x104 - 0xcc];
    f32 f104, f108, f10c;
    s32 w110, w114, w118;
    u8 pad_11c[0x170 - 0x11C];
    u16 h170;
    u8 pad172[0x18C - 0x172];
    f32 f18c;
    f32 f190;
    u8 pad_194[0x19c - 0x194];
    s32 w19c;
    u8 pad_1a0[0x1bc - 0x1A0];
    void *p1bc;
    u8 pad1c0[0x1ec - 0x1c0];
    char u1ec;
    u8 pad1ed[0x23c - 0x1ed];
    s32 p23c;
} Obj_80112868;
extern char lbl_80346E70, lbl_80346E71;
extern void fn_80217830(s32 h);
extern void fn_801C6170(void *p);
struct Sub_80117748 {
    u8 pad[0x1bc];
    void *anim;
};
struct Obj_80117748 {
    u8 pad[0x24];
    struct Sub_80117748 *sub;
};
extern char lbl_802B339C[];
typedef struct SndMap { s16 a; s16 b; s16 c; } SndMap;
extern SndMap lbl_802E5900[];
typedef struct Cur { u8 pad0[4]; s32 x4; s8 x8; u8 pad9[3]; } Cur;
extern void fn_80219324(s32 i);
extern void fn_80219378(void *p);
extern void fn_80100150(Cur *c);
extern int sprintf(char *, const char *, ...);
extern void *fn_801CC67C(void *name);
extern void fn_801CC600(void *h, s32 *a, s32 b);
typedef struct Row_80125B60_80125B60 {
    s8 id;
    u8 pad1;
    s8 list[12];
} Row_80125B60_80125B60;
typedef struct Set_80125B60_80125B60 {
    Row_80125B60_80125B60 row[13];
    u8 padb6[0xc0 - 0xb6];
    f32 xc0;
    f32 xc4;
} Set_80125B60_80125B60;
typedef struct In_80125B60_80125B60 {
    u8 _00[5];
    s8 f5;
    s8 f6;
    u8 _07[7];
    s16 h0e;
    s8 b10;
    u8 _11;
    s8 b12;
    u8 _13[4];
    s8 b17;
    u8 _18[2];
    s16 h1a;
    u8 _1c[0x6c - 0x1c];
    Set_80125B60_80125B60 set;
} In_80125B60_80125B60;
typedef struct Anim_80125B60 {
    u8 _00[4];
    u32 cnt;
} Anim_80125B60;
typedef struct Obj_80125B60_80125B60 {
    u8 _00[0xe8];
    Anim_80125B60 *anim;
    u8 _ec[0x18c - 0xec];
    f32 f18c;
    f32 f190;
} Obj_80125B60_80125B60;
typedef struct { f32 x, y; } Pt2;
/* B-spline basis N(i,k)(t) on a uniform clamped knot vector; k2 is the spline order (knots),
   k the recursion degree. The mixed int/s32 is what makes the caller allocate like the original:
   with k and k2 of the same type, out/q/k rotate registers. */
extern f32 fn_8011A994(int i, int n, int k, s32 k2, f32 t);
typedef struct Ent_8012048C {
    f32 pos[3];
    f32 acc[3];
    f32 x18;
    f32 vel[3];
    u8 pad28[0x54 - 0x28];
    u32 x54;
} Ent_8012048C;
typedef struct Elem {
    u8 pad[0x40];
} Elem;
typedef struct Eff_8012048C {
    u32 flags;
    u8 pad4[0x18 - 4];
    s32 x18;
    Elem *elems;
    Ent_8012048C *ents;
    s32 count;
} Eff_8012048C;
extern void fn_8011FFF0(f32 *pos, f32 *v, Elem *el, f32 t, void *w);
extern f32 fn_8011A994(int i, int n, int k, s32 k2, f32 t);

void fn_8010E164(u8 *obj) {
    if (obj[0x19] == 0xff) {
        fn_80117748();
    }
}

void fn_8010E190(u8 *obj) {
    if (obj[0x19] == 0xff) {
        fn_80117748();
    }
}

void fn_8010E1BC(u8 *obj) {
    if (obj[0x19] == 0xff) {
        fn_80117748();
    }
}

void fn_8010E1E8(u8 *obj) {
    if (obj[0x19] == 0xff) {
        fn_80117748();
    }
}

void fn_8010E214(u8 *obj) {
    if (obj[0x19] == 0xff) {
        fn_80117748();
    }
}

void fn_8010E240(u8 *obj) {
    if (obj[0x19] == 0xff) {
        fn_80117748();
    }
}

void fn_8010E26C(void) {
}

void fn_801150DC(void *a, void *b, void *c, void *d) {
    fn_80114C84(a, b, c, d, fn_80114A44, fn_80114AB8);
}

void fn_8011510C(void *a, void *b, void *c, void *d) {
    fn_80114C84(a, b, c, d, fn_80114AB8, fn_80114A44);
}

void fn_80116020(s32 n) {
    lbl_80346E80 = n;
}

f32 fn_80116028(void) {
    s32 i = fn_801161B4();
    return ((Entry *)lbl_802E54B0)[i].f2c;
}

extern s32 lbl_80347400;
void fn_801165BC(s32 v) {
    lbl_80347400 = v;
}

void fn_801165C4(u8 *self) {
    fn_802238E4(self + 0x38, self + 0x38, *(s32 *)(self + 0x1b8));
    MemCopy(self + 0x104, self + 0x38, 0x24);
}

s32 fn_8011698C(s32 a, u8 *obj) {
    s32 r = fn_802254A0(a);
    if (r == 1 && (*(u16 *)(obj + 0x24) & 0x4800) == 0x4800) {
        r = 0;
    }
    return r;
}

void fn_80118540(void) {
    f32 big = 3.4028235e38f;
    s32 mx = 0x80000000;
    mx -= 1;
    lbl_8030A380.type = 0;
    lbl_8030A380.ptr = (void *)mx;
    lbl_8030A380.a = big;
    lbl_8030A380.b = big;
    lbl_8030A380.c = big;
    lbl_8030A380.d = big;
    lbl_8030A380.e = big;
    lbl_8030A380.f = big;
}

void fn_80118578(void *ptr, f32 f1, f32 f2, f32 f3, f32 f4) {
    lbl_8030A380.type = 1;
    lbl_8030A380.ptr = ptr;
    lbl_8030A380.a = f1;
    lbl_8030A380.b = f2;
    lbl_8030A380.c = f3;
    lbl_8030A380.d = lbl_80349E90;
    lbl_8030A380.e = f4;
    lbl_8030A380.f = lbl_80349E90;
}

void fn_801185A8(void *ptr, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5, f32 f6) {
    lbl_8030A380.type = 2;
    lbl_8030A380.ptr = ptr;
    lbl_8030A380.a = f1;
    lbl_8030A380.b = f2;
    lbl_8030A380.c = f3;
    lbl_8030A380.d = f4;
    lbl_8030A380.e = f5;
    lbl_8030A380.f = f6;
}

void fn_8011A2A8(void) {
    fn_80109E7C(lbl_802B31A8, 0x7fff);
}

void fn_8011B238(s32 a, ...) {
}

int fn_8011B288(void* h, void* arg) {
    return 1;
}

int fn_8011B290(void* h, void* arg) {
    return 1;
}

void fn_8011BAA4(u8 *p) {
    lbl_80346EB0 = p;
    if (!(p[0x18] & 0x20)) {
        return;
    }
    lbl_80346EB4 = 0;
    lbl_80346EB0 = 0;
    p[0x18] |= 0x40;
}

void fn_8011BAD0(void)
{
    lbl_80346EB0 = 0;
    lbl_80346EB4 = 0;
}

s32 fn_8011BAE0(void) {
    return 1;
}

int fn_8011CC6C(void* h, void* arg) {
    return 1;
}

int fn_8011CE64(void* h, void* arg) {
    return 1;
}

s32 fn_8011E040(void) {
    return 1;
}

void fn_80120A50(f32 *out, const f32 *a, const f32 *b, f32 t) {
    f32 az = a[2];
    f32 bz = b[2];
    f32 ax = a[0];
    f32 ay = a[1];
    f32 by = b[1];
    f32 bx = b[0];
    out[2] = az + t * (bz - az);
    out[1] = ay + t * (by - ay);
    out[0] = ax + t * (bx - ax);
}

s32 fn_801213E8(void) {
    return 1;
}

s32 fn_80121B1C(void) {
    return 1;
}

s32 fn_80122768(void) {
    return 1;
}

s32 fn_80122770(void) {
    return 1;
}

void fn_80123E8C(void) {
    lbl_803473B4 = 1;
    lbl_803473B0 = 1;
}

void fn_80123E9C(void) {
    lbl_803473B4 = 1;
    lbl_803473B0 = 0;
}

void fn_80123EB0(void) {
    if (lbl_80346EC0 != 0) {
        TaskDelete(lbl_80346EC0);
    }
    lbl_80346EC0 = 0;
}

void fn_80123EE4(void) {
    lbl_803473B4 = 0;
    lbl_803473B0 = 0;
    lbl_80346EC0 = fn_802267AC(lbl_803475A0, fn_80123CBC);
    *(void **)((u8 *)lbl_80346EC0 + 0x24) = fn_801E1C7C(0x20);
}

void fn_80124390(u8 *p) {
    u8 *src = *(u8 **)(*(u8 **)(p + 0x1d8) + 0x8);
    MemCopy(p + 0x38, src + 0x38, 0x24);
}

void fn_801243C4(u8 *p) {
    fn_8014FA10(*(u8 **)(p + 0x23c) + 0xf0);
}

s32 fn_801243EC(s32 a) {
    if (a == 0x1c) {
        return 1;
    }
    if (a == 0x1d) {
        if ((s8)lbl_80310A1C[0xc0] == 0) {
            return 2;
        }
    }
    return 0;
}

void fn_80124870(s32 a, u8 *obj) {
    switch (obj[4]) {
    case 0x18:
        fn_801248C4(a, obj, 1);
        if (*(s16 *)(obj + 0x34) == 1) {
            fn_8020EFD4(0x74cc);
        }
        break;
    }
}

void fn_80126408(void *a, void *b) {
    NJS_MATRIX m;
    njUnitMatrix(m);
    fn_80156C6C(m, a);
    fn_8014F99C(b, m);
}

void fn_8012645C(u8 *self) {
    u8 *p = *(u8 **)(self + 0x23c);
    if (p != 0) {
        fn_8014FA10((u8 *)*(void **)(p + 4) + 0x80);
        fn_80127BC0((void *)self);
    }
}

void fn_80126E1C(u8 *p, u8 v) {
    p[7] = v;
}

void fn_80127B8C(u8 *p) {
    u8 *src = *(u8 **)(*(u8 **)(p + 0x1d8) + 0x8);
    MemCopy(p + 0x38, src + 0x38, 0x24);
}

s32 fn_80128F2C(void) {
    s32 r;
    if (fn_801CC5BC(lbl_80346ED8) != 2) {
        r = 0;
    } else {
        fn_801CC65C(lbl_80346ED8);
        fn_80218D84(lbl_80305F60, lbl_80346ED4, lbl_80346ED0);
        r = 1;
    }
    return r;
}

void fn_801296C4(Fn80129560Obj *p) {
    switch (p->state) {
    case 0xfe:
    case 0x0:
        fn_8015ED90(p);
        p->state = 1;
        break;
    case 0x1:
        fn_8015E600(p->inner);
        break;
    case 0xff:
        fn_8015EBF4(p->inner);
        fn_80100B74(p);
        break;
    }
}

void *fn_801298CC(void) {
    u8 *inner = *(u8 **)(lbl_803472A8 + 0x8);
    return lbl_803472CC + (*(u16 *)(inner + 0x46) << 2);
}

void fn_80129988(void) {
    lbl_803472DC = lbl_8034A398;
}

void fn_80129994(void) {
    lbl_803472DC = lbl_8034A380;
}

void fn_801299A0(void) {
    lbl_803472E0 = lbl_8034A380;
    lbl_80346EE4 = lbl_8034A3A4;
}

s32 fn_8012A8DC(void) {
    s32 v = lbl_80311AC0[1];
    return v >= 500;
}

void fn_8012A9FC(void) {
    fn_8012C060();
    fn_80133144();
    fn_801323F0();
    fn_801316CC();
    fn_80130368();
    fn_8012F744();
    fn_8012F490();
    fn_8012E5D8();
    fn_8012C660();
    fn_8012AEE8();
    fn_8012AA8C();
}

void fn_80124C68(void *p3, void **pp) {
    u8 *o = (u8 *)*pp;
    if (*(u32 *)(o + 0x24) & 0x2000) {
        s32 v = *(s32 *)o;
        u8 *in = *(u8 **)(o + 0x13c);
        if (v == 0) {
            return;
        }
        if (*(u32 *)((u8 *)p3 + 0xe8) != 0) {
            fn_80156E54(p3, in);
        } else {
            fn_80156DA0(p3, in);
        }
    } else {
        if (*(s32 *)o != 0) {
            if (*(s8 *)(o + 7) != 0) {
                fn_801E5148(p3, o);
            } else {
                fn_801E5DF0(p3, o);
            }
        }
    }
}

void fn_80126F0C(void *a, void *b) {
    u8 *pa = (u8 *)a;
    u8 *pb = (u8 *)b;
    if (*(u32 *)(pb + 0x24) & 0x400) {
        return;
    }
    *(f32 *)(pb + 0x38) = *(f32 *)(pa + 0x38);
    *(f32 *)(pb + 0x3c) = *(f32 *)(pa + 0x3c);
    *(f32 *)(pb + 0x40) = *(f32 *)(pa + 0x40);
    if (!(*(u32 *)(pb + 0x24) & 0x80)) {
        *(u32 *)(pb + 0x44) = *(u32 *)(pa + 0x44);
    }
    if (!(*(u32 *)(pb + 0x24) & 0x100)) {
        *(u32 *)(pb + 0x48) = *(u32 *)(pa + 0x48);
    }
    if (!(*(u32 *)(pb + 0x24) & 0x200)) {
        *(u32 *)(pb + 0x4c) = *(u32 *)(pa + 0x4c);
    }
}

void fn_801119D4(u8 *obj) {
    s32 r;

    *(f32 *)(obj + 0x190) = 1.0f;
    fn_801189F0(obj);
    switch (*(u16 *)(obj + 0x172)) {
    case 0:
        r = fn_8010E270(obj, *(u32 *)(lbl_80311970 + 0x20));
        if (r == 0) {
            fn_801E7414(0x2b, obj);
            *(u16 *)(obj + 0x170) = 0x11;
            *(u16 *)(obj + 0x172) = 0;
        } else if (r == 2) {
            fn_801E7414(0x2a, obj);
            *(u16 *)(obj + 0x170) = 0x12;
            *(u16 *)(obj + 0x172) = 0;
        }
        break;
    }
}

void fn_8011356C(u8 *obj) {
    s16 r;

    *(f32 *)(obj + 0x190) = 1.0f;
    fn_801189F0(obj);
    if (lbl_80346E68 == 0) {
        r = lbl_80311A60[0]->y;
        if (r > 0) {
            fn_801E7414(0x1c, obj);
            SePlay(0xf, 5, 0x1b);
            *(u16 *)(obj + 0x170) = 7;
            *(u16 *)(obj + 0x172) = 0;
        } else if (r < 0) {
            fn_801E7414(0x1b, obj);
            SePlay(0xf, 5, 0x1b);
            *(u16 *)(obj + 0x170) = 7;
            *(u16 *)(obj + 0x172) = 0;
        }
    }
    lbl_80346E68 = 0;
}

void fn_8011816C(Obj_80112868 *self, void **out) {
    if (lbl_80347404 == 0) {
        out[6] = &self->f38;
        out[8] = &self->w44;
        out[9] = 0;
        out[10] = 0;
    } else {
        out[6] = &self->f38;
        out[8] = &self->w44;
        out[9] = &self->fb4;
        out[10] = &self->fc0;
    }
    fn_80222838(out);
    fn_80117BE4(0, self, out);
}

void fn_80119A28(u8 *p) {
    s32 n;
    f32 v;
    if (lbl_80347440 == 0) {
        return;
    }
    n = fn_801161B4();
    v = fn_80090EEC(p, *(f32 *)(lbl_802E54B0 + n * 0xa4 + 0x2c));
    n = lbl_80347440;
    if (n == 1) {
        if (v < lbl_80349EDC) {
            *(f32 *)(p + 0x1c) = lbl_80349EA4;
        } else {
            *(f32 *)(p + 0x1c) = lbl_80349E18;
        }
        return;
    }
    if (n < 2) {
        return;
    }
    if (v >= lbl_80349EDC) {
        goto reset;
    }
    {
        s32 m = n + 1;
        lbl_80347440 = m;
        if (m < 10) {
            goto ea4;
        }
    }
reset:
    *(f32 *)(p + 0x1c) = lbl_80349E18;
    lbl_80347444 = 0;
    lbl_80347440 = 0;
    return;
ea4:
    *(f32 *)(p + 0x1c) = lbl_80349EA4;
}

void fn_80125750(u8 *dst, u8 *src) {
    if (*(s32 *)(src + 0x24) & 0x80) {
        if (*(s32 *)(src + 0x44) >= 0x8000) {
            *(s32 *)(src + 0x44) -= 0x10000;
        }
        if (*(s32 *)(src + 0x44) <= -0x8000) {
            *(s32 *)(src + 0x44) += 0x10000;
        }
        *(s32 *)(dst + 0x44) = *(s32 *)(src + 0x44);
    }
    if (*(s32 *)(src + 0x24) & 0x100) {
        if (*(s32 *)(src + 0x48) >= 0x8000) {
            *(s32 *)(src + 0x48) -= 0x10000;
        }
        if (*(s32 *)(src + 0x48) <= -0x8000) {
            *(s32 *)(src + 0x48) += 0x10000;
        }
        *(s32 *)(dst + 0x48) = *(s32 *)(src + 0x48);
    }
    if (*(s32 *)(src + 0x24) & 0x200) {
        if (*(s32 *)(src + 0x4c) >= 0x8000) {
            *(s32 *)(src + 0x4c) -= 0x10000;
        }
        if (*(s32 *)(src + 0x4c) <= -0x8000) {
            *(s32 *)(src + 0x4c) += 0x10000;
        }
        *(s32 *)(dst + 0x4c) = *(s32 *)(src + 0x4c);
    }
}

void fn_80125C90(u8 *p) {
    if (p == 0) {
        return;
    }
    fn_801E17E0(*(void **)(p + 0x0));
    fn_801E17E0(*(void **)(p + 0x4));
    if (*(void **)(p + 0xc) != 0) {
        fn_801E17E0(*(void **)(p + 0xc));
    }
    if (*(u8 **)(p + 0x8) != 0) {
        u8 *q = *(u8 **)(p + 0x8);
        memset(q + 0x14, 0, 0x1c);
        memset(q + 0x4c, 0, 0x1c);
        memset(q + 0x30, 0, 0x1c);
        fn_801E17E0(q);
    }
    memset(p, 0, 0x10);
    fn_801E17E0(p);
}

void fn_801278F0(u8 *p, u8 *out) {
    if (*(s32 *)(p + 0x2e4) != 0) {
        *(s16 *)(p + 0x3c) += 1;
        if (*(s32 *)((u8 *)lbl_803472A4 + 0x4c) == 0) {
            s32 v = *(s32 *)(*(u8 **)(p + 0x8) + 0x24);
            *(s8 *)(out + 0x10) = -0x7f;
            out[0x11] = 0;
            if (v != 0) {
                out[0x16] = 1;
            }
        }
    }
    if (*(s32 *)(p + 0x2f0) == 0) {
        return;
    }
    *(s16 *)(p + 0x3e) += 1;
    if (*(s32 *)((u8 *)lbl_803472A4 + 0x4c) != 0) {
        return;
    }
    {
        s32 v = *(s32 *)(*(u8 **)(p + 0x8) + 0x24);
        *(s8 *)(out + 0x10) = -0x7e;
        out[0x11] = 0;
        if (v != 0) {
            out[0x16] = 1;
        }
    }
}

void fn_80129560(Fn80129560Obj *p) {
    switch (p->state) {
    case 0xfe:
    case 0x0:
        fn_8015ED90(p);
        p->state = 1;
        break;
    case 0x1:
        fn_8015E600(p->inner);
        break;
    case 0xff:
        fn_8015EBF4(p->inner);
        fn_80100B74(p);
        break;
    }
}

void fn_80129750(NJS_MATRIX m, Fn80129750Obj *o) {
    Fn80129750Inner *in;

    in = o->inner;
    if (in->f16c == 0) {
        njTranslate(m, in->pos[0], in->pos[1], in->pos[2]);
        fn_801E6EC0(m, in->f16e, in->ang[0], in->ang[1], in->ang[2]);
    } else {
        njTranslate(m, in->pos[0], in->pos[1], in->pos[2]);
        njRotateZXY(m, in->ang[0], in->ang[1], in->ang[2]);
        njTranslate(m, in->pos2[0], in->pos2[1], in->pos2[2]);
        fn_801E6DD4(m, in);
    }
    njScale(m, in->scale[0], in->scale[1], in->scale[2]);
}

s32 fn_801298E8(void) {
    if (lbl_803472E0 == 0.0f) {
        return (lbl_803472C0 % lbl_803472D0 == 0) + 1;
    }
    if (lbl_803472A8 != 0) {
        if (lbl_803472E0 == (f32)(*(s32 *)((u8 *)lbl_803472A4 + 0x8))) {
            return (lbl_803472C0 % lbl_803472D0 == 0) + 1;
        }
    }
    return 0;
}

void fn_80129BD4(void) {
    Fn80129BD4Head *h;
    s32 i;
    s32 sum;
    Fn80129BD4Item *p;

    h = (Fn80129BD4Head *)lbl_803472A8;
    if (lbl_803472E0 >= (f32)h->f4) {
        lbl_803472E0 = 0.0f;
        lbl_80346EE4 = -1.0f;
    }
    sum = 0;
    for (i = 0; i < h->count; i++) {
        sum += h->items[i].f4;
        if ((f32)sum > lbl_803472E0) {
            lbl_803472B4 = i;
            break;
        }
    }
    p = h->items + lbl_803472B4;
    lbl_803472A4 = (Rec *)p;
    lbl_803472AC = p->f20;
}

s32 fn_80129CA8(Fn80129CA8Inner *o) {
    char fi[0x38];
    char *base;

    base = (char *)lbl_802B3388;
    strcpy(fi, (char *)o->mid + 0x24);
    fi[8] = 0;
    if (fn_8025EF88(fi, base + 0x7c) == 0) {
        return 0;
    }
    if (fn_8025EF88(fi, base + 0x58) == 0) {
        return 1;
    }
    fn_8015757C(base + 0x88, o->f17a);
    return 0;
}

Fn80129D40Entry *fn_80129D40(s32 id) {
    Fn80129D40Entry *found;
    s32 i;

    if (id == 0xffff) {
        id = lbl_803472B0;
    }
    found = 0;
    for (i = 0; i < lbl_8034729C; i++) {
        if (id == lbl_80308EF8[i].obj->inner->f17a) {
            found = &lbl_80308EF8[i];
        }
    }
    if (found == 0) {
        fn_801DBE1C(lbl_802B33EC, id);
    }
    return found;
}

s32 fn_801109AC(Angle ang, Obj_801109AC* o) {
    NJS_MATRIX m;
    NJS_POINT3 p, d;
    s32 ok;
    njUnitMatrix(m);
    njRotateXYZ(m, 0, ang, 0);
    p.x = 0.0f;
    p.y = 0.0f;
    p.z = 24.0f;
    njCalcPoint(m, &p, &d);
    p.x = o->x + d.x;
    p.y = 24.0f + (o->y + d.y);
    p.z = o->z + d.z;
    o->sub->s28 = 0xFFFF;
    o->sub->s2a = 0xFFFF;
    ok = 1;
    fn_8011698C((s32)&p, (u8 *)o->sub);
    if (1.0f + o->y < p.y) {
        ok = 0;
    }
    return ok;
}

void fn_801185D4(Obj_801185D4* o) {
    f32* p;
    f32* base;
    s32 i;
    u16 t = o->type;
    if (t == 2 || t == 0x17) {
        base = lbl_802E5078;
    } else if ((u16)(t - 3) <= 1 || t == 0x18 || t == 0x19) {
        base = lbl_802E5078 + 27;
    } else {
        return;
    }
    i = 0;
    p = base;
    do {
        if (p[0] <= o->f18c && o->f190 + p[0] > o->f18c && o->s19c == 1) {
            u16 k = (o->sub->flags >> 4) & 0xF;
            if (k >= 7) {
                k = 6;
            }
            SePlay(15, 5, lbl_80346798[k]);
        }
        i++;
        p++;
    } while (i < 2);
}

void fn_80119744(Out* out, Src_80119744* a, Inner** h) {
    NJS_VECTOR v;
    NJS_MATRIX m;
    Inner* in;
    if (h == NULL) {
        out->v[0] = 0.0f;
        out->v[1] = 0.0f;
        out->v[2] = 0.0f;
        out->w[0] = 0;
        out->w[1] = 0;
        out->w[2] = 0;
        return;
    }
    fn_800071D8(h);
    in = *h;
    if (in->p0 != NULL) {
        fn_80007080(&v, 1);
        njUnitMatrix(m);
        njRotateXYZ(m, a->rx, a->ry, a->rz);
        njScale(m, a->sx, a->sy, a->sz);
        njCalcVector(m, &v, (NJS_VECTOR*)out);
    } else {
        out->v[0] = 0.0f;
        out->v[1] = 0.0f;
        out->v[2] = 0.0f;
    }
    if (in->p4 != NULL) {
        fn_80006F1C(out->w, 1);
    } else {
        out->w[0] = 0;
        out->w[1] = 0;
        out->w[2] = 0;
    }
}

s32 fn_8011B128(s32 unused, const char* fmt, ...) {
    va_list ap;
    char buf[256];
    s32 n;
    char* p;
    if (fmt != NULL && *fmt != 0) {
        va_start(ap, fmt);
        n = fn_8025CC04(buf, fmt, ap);
        p = strchr(fn_8025EDDC(buf, "\n"), '\r');
        if (p != NULL) {
            *p = 0;
        }
        while ((p = fn_8025EDDC(NULL, "\n")) != NULL) {
            p = strchr(p, '\r');
            if (p != NULL) {
                *p = 0;
            }
        }
        return n;
    }
    return 0;
}

void fn_8011B6E0(Anim_8011B6E0* a) {
    f32 t = (f32)a->cur / (f32)a->total;
    f32 v;
    f32 dx, dy;
    if (a->flags & 0x200) {
        fn_8011B024(a->curve, 4, 3, &v, t);
        t = 0.01f * v;
    }
    dx = 640.0f * t;
    dy = 480.0f * t;
    if (a->flags & 0x1000000) {
        a->x0 = -dx;
        a->x1 = 640.0f - dx;
    } else if (a->flags & 0x2000000) {
        a->x0 = dx;
        a->x1 = 640.0f + dx;
    }
    if (a->flags & 0x4000000) {
        a->y0 = -dy;
        a->y1 = 480.0f - dy;
    } else if (a->flags & 0x8000000) {
        a->y0 = dy;
        a->y1 = 480.0f + dy;
    }
    a->c38 = a->c50 = a->x0;
    a->c3c = a->c6c = a->y0;
    a->c68 = a->c80 = a->x1;
    a->c54 = a->c84 = a->y1;
}

void fn_8011F44C(Obj_8011F44C* o) {
    Sub_8011F44C* sub = o->sub;
    f32 t;
    f32 v;
    f32 tmp;
    if (o->state < 0) {
        t = 0.0f;
    } else {
        t = (f32)o->frame / 15.0f;
        if (o->flags & 0x100) {
            fn_8011B024(o->curve, 5, 3, &tmp, t);
            v = 0.01f * (0.8f * tmp);
        } else {
            v = 0.0f;
        }
    }
    sub->f50 = v;
    sub->f54 = 0.5f * t + v;
    sub->f58 = v;
    if (o->state >= 0) {
        if (++o->frame >= 15) {
            o->frame = 0;
            o->flags |= 8;
            o->flags &= ~4;
        }
    }
}

void fn_8012092C(Obj_8012092C* o) {
    DrawState st;
    Item* p;
    s32 n;
    s32 i;
    if (o->frame != 0) {
        fn_801202C4(o);
    } else {
        fn_8012061C(o);
    }
    fn_8012048C(o);
    if (o->flags & 0x80000) {
        DrawStateDefault2D(&st);
        st.blend_src = 8;
        st.blend_dst = 10;
        DrawStatePush(&st);
    }
    n = o->count;
    p = o->items;
    fn_8028A3E0(1);
    for (i = 0; i < n; i++) {
        fn_8028A2A8(p++, 4);
    }
    fn_8028A2A4();
    if (o->flags & 0x80000) {
        DrawStatePop(NULL);
    }
    if (++o->frame >= 15) {
        o->flags |= 2;
        o->flags &= ~0x40001;
        fn_801202C4(o);
        fn_8012048C(o);
        o->frame = 0;
    }
}

void fn_80122778(Obj_80122778* o) {
    Anim_80122778* a = o->anim;
    a->timer++;
    if (a->timer % (a->frames[a->idx].dur + 1) != 0) {
        fn_801D6CBC(a->handle, a->s14);
        return;
    }
    a->idx++;
    if (a->frames[a->idx].dur == 0) {
        a->loops++;
        if (a->loops >= a->max_loops) {
            fn_801D6C3C(a->handle);
            if (o->anim != NULL) {
                fn_801E1784(o->anim);
                o->anim = NULL;
            }
            o->flags |= 0x40;
            return;
        }
        a->idx = 0;
    }
    fn_801D6CBC(a->handle, a->s14);
    a->timer = 0;
    a->b16 = a->frames[a->idx].a;
    a->b17 = a->frames[a->idx].b;
}

Obj_80122A00* fn_80122A00(s32 unused, Src_80122A00* s) {
    Obj_80122A00* o;
    s32 i;
    SrcFrame* sf;
    Anim_80122A00* a;
    Frame* f;
    if (fn_801D6E38(s->handle) == 0) {
        return NULL;
    }
    o = fn_80226704(lbl_80347588, fn_80122D5C, 8);
    if (o == NULL) {
        return NULL;
    }
    o->src = s;
    o->anim = s->anim;
    a = s->anim;
    sf = s->frames;
    f = a->frames;
    a->handle = s->handle;
    a->idx = 0;
    a->loops = 0;
    a->timer = 0;
    for (i = 0; i < 31; i++) {
        f->a = sf->a;
        f->b = sf->b;
        f->dur = sf->dur;
        sf++;
        if (f->dur == 0) {
            a->count = i + 1;
            a->max_loops = (s8)f->b;
            break;
        }
        f++;
    }
    if (i >= 31) {
        f[-1].dur = 0;
        a->count = 31;
        a->max_loops = (s8)f[-1].b;
    }
    a->b14 = 1;
    a->b15 = 0;
    a->b18 = 0;
    a->b16 = a->frames[0].a;
    a->b17 = a->frames[0].b;
    return o;
}

void fn_80126014(void *a, In *in, Obj_80126014 *o)
{
    fn_8014EF34(in);
    if (o->flags & 1) {
        fn_801278F0((u8 *)in, (u8 *)o);
        fn_801276E8((void *)a, (void *)o);
    }
    if (o->flags & 4) {
        if (in->s14 != 0 && in->s10 == 2) {
            o->b14 = 1;
            o->b15 = 0;
        }
        fn_801275E0((Ctx_801275E0 *)a, (Obj_801275E0 *)o);
    }
    if (o->flags & 2) {
        if (in->s20 != 0) {
            if (o->tbl[o->b17] == -1) {
                o->b13 = 0;
            } else {
                o->b13 = o->b17;
            }
            o->b12 = 1;
        }
        fn_80126118((void *)a, (void *)o);
    }
}

void fn_801275E0(Ctx_801275E0 *c, Obj_801275E0 *o)
{
    Sub_801275E0 *s = &o->sub;
    if (o->b14 != 0) {
        if (o->b14 == 1) {
            o->b14 = 2;
            o->s1a = 1;
            fn_80126F0C(c, o);
            o->b5 = s->e58[o->b15].b;
        }
        if (!(c->f18c < (f32)c->clock->tick - s->f0c0 * c->f190)) {
            fn_80126F0C(c, o);
            o->b14 = 0;
            o->s1a = 0;
            if (o->b5 == o->b6) {
                o->b6 = -1;
            }
            o->b5 = ((u8 *)s)[o->b17 * 0xe];
        }
    }
}

void fn_80127E24(Ctx_80127E24 *c, Obj_80127E24 *o, u32 mask)
{
    s32 t;
    fn_801264A4((u8 *)c + 0x38, 1, 0.0f);
    if (fn_80126E24(c, 10.0f, 12.0f)) {
        o->v44 = c->v44;
        o->v48 = c->v48;
        o->v4c = c->v4c;
        o->flags &= ~mask;
        o->flags |= 0x20;
    } else if (o->v50 != 0) {
        if (mask & 0x80) {
            t = o->v60;
            c->v44 = t;
            o->v44 = t;
        }
        if (mask & 0x100) {
            t = o->v64;
            c->v48 = t;
            o->v48 = t;
        }
        if (mask & 0x200) {
            t = o->v68;
            c->v4c = t;
            o->v4c = t;
        }
        o->flags &= ~0x20;
        o->flags |= mask;
    }
}

s32 fn_801284C0(FormTbl *t)
{
    u8 ids[3] = { 0, 1, 2 };
    u8 a0[6] = { 2, 0, 0x32, 1, 0x33, 0 };
    u8 a1[6] = { 2, 1, 0x33, 0, 0x32, 1 };
    u8 a2[4] = { 1, 2, 0, 2 };
    s32 i;
    for (i = 0; i < 3; i++) {
        t->e[i].id = ids[i];
    }
    for (i = 0; i < 6; i++) {
        t->e[0].d[i] = a0[i];
    }
    for (i = 0; i < 6; i++) {
        t->e[1].d[i] = a1[i];
    }
    for (i = 0; i < 4; i++) {
        t->e[2].d[i] = a2[i];
    }
    t->b_ac = 0x14;
    t->b_ad = 0x15;
    t->f_b0 = 31.0f;
    t->f_b4 = 40.0f;
    t->f_bc = 41.0f;
    t->f_c0 = 1.0f;
    t->f_c4 = 1.0f;
    return 3;
}

s32 fn_80128A1C(FormTbl *t)
{
    u8 ids[4] = { 0, 1, 2, 3 };
    u8 a0[3] = { 1, 0x35, 0 };
    u8 a1[3] = { 0, 0x34, 1 };
    u8 a2[6] = { 0, 2, 1, 2, 3, 2 };
    u8 a3[3] = { 2, 0x36, 3 };
    s32 i;
    for (i = 0; i < 4; i++) {
        t->e[i].id = ids[i];
    }
    for (i = 0; i < 3; i++) {
        t->e[0].d[i] = a0[i];
    }
    for (i = 0; i < 3; i++) {
        t->e[1].d[i] = a1[i];
    }
    for (i = 0; i < 6; i++) {
        t->e[2].d[i] = a2[i];
    }
    for (i = 0; i < 3; i++) {
        t->e[3].d[i] = a3[i];
    }
    t->f_b0 = 31.0f;
    t->f_b4 = 40.0f;
    t->f_bc = 41.0f;
    t->f_c0 = 1.0f;
    t->f_c4 = 1.0f;
    return 4;
}

void fn_801299B4(void)
{
    s32 ready;
    ready = lbl_80311AC0[1] >= 500;
    if (ready != 0) {
        lbl_80346EE4 = lbl_803472E0;
        if (lbl_80347294 == 1) {
            lbl_80347290 = 0;
        }
        lbl_803472E0 = lbl_803472E0 + lbl_803472DC;
        fn_80156250();
        if (lbl_803472E0 >= (f32)(lbl_803472A4->v8 + lbl_803472A4->v4) && lbl_80346EE4 != lbl_803472E0) {
            fn_80144E5C();
            lbl_803472C0 = lbl_803472C0 + 1;
            if (lbl_803472C0 % lbl_803472D0 == 0) {
                lbl_803472DC = 0.0f;
                lbl_803472D8 = lbl_803472D8 + 1;
            }
        }
    }
}

extern void fn_8012C070(void);
void fn_8012AA44(void) {
    fn_8012AB84();
    fn_8012AEF8();
    fn_8012C670();
    fn_8012E5E8();
    fn_8012F4A0();
    fn_8012F75C();
    fn_80130378();
    fn_801316DC();
    fn_80132400();
    fn_80133154();
    fn_8012C070();
}

void fn_8012AA8C(void)
{
    if (lbl_80346EFC != NULL) {
        fn_801D6944(lbl_80346EFC);
    }
    if (lbl_80346F00 != NULL) {
        fn_801D6944(lbl_80346F00);
    }
    if (lbl_80346F04 != NULL) {
        fn_801D6944(lbl_80346F04);
    }
    if (lbl_80346F08 != NULL) {
        fn_801D6944(lbl_80346F08);
    }
    if (lbl_80346EF0 != NULL) {
        fn_802275A4(lbl_80346EF0->x4->x20, 1);
        fn_801E17E0(lbl_80346EF0);
        lbl_80346EF0 = NULL;
    }
    if (lbl_80346EF4 != NULL) {
        fn_802275A4(lbl_80346EF4->x4->x20, 1);
        fn_801E17E0(lbl_80346EF4);
        lbl_80346EF4 = NULL;
    }
    if (lbl_80346EF8 != NULL) {
        fn_802275A4(lbl_80346EF8->x4->x20, 1);
        fn_801E17E0(lbl_80346EF8);
        lbl_80346EF8 = NULL;
    }
    if (lbl_80346F0C != NULL) {
        fn_801E17E0(lbl_80346F0C);
        lbl_80346F0C = NULL;
    }
}

void fn_8010F4F4(Parent *p) {
    extern Other *lbl_80347450;
    extern void fn_80222838(Attach *a);
    extern void fn_8015ED90(Parent *p);
    extern s32 fn_8015E600(Obj *o);
    extern void fn_8015EBF4(Obj *o);
    extern void fn_80117748(Parent *p);
    extern void fn_802275A4(void *p, s32 a);
    extern void fn_80100B74(Parent *p);
    extern f32 fn_80290008(NJS_POINT3 *a, NJS_POINT3 *b);
    u8 st = p->f19;
    Obj *o = p->obj;

    switch (st) {
    case 0:
    case 0xfe:
        fn_80222838(o->attach);
        fn_8015ED90(p);
        p->f19 = 1;
        break;
    case 1:
        if (fn_8015E600(o) == 0 && o->attach != 0) {
            f32 sy = o->pos.y;
            f32 oy = lbl_80347450->pos.y;
            lbl_80347450->pos.y = 0.0f;
            o->pos.y = 0.0f;
            o->attach->f4 = 0;
            if (30.0f > fn_80290008(&o->pos, &lbl_80347450->pos)) {
                o->attach->flags &= ~0x8000;
            }
            o->pos.y = sy;
            lbl_80347450->pos.y = oy;
            fn_80222838(o->attach);
        }
        break;
    case 0xff:
        fn_8015EBF4(o);
        fn_80117748(p);
        if (o->res != 0) {
            fn_802275A4(o->res, 0);
        }
        fn_80100B74(p);
        break;
    }
}

s32 fn_801147E8(Obj_801147E8 *o, f32 step, s32 turn) {
    Angle ang[3];
    s32 yaw;
    s32 ret;

    yaw = fn_801DD078(&o->dir, &o->target);
    yaw += turn;
    fn_801DD5E8(ang, &o->target);
    fn_801DCF24(&o->dir, ang, yaw, 1.0f);
    if (step != 0.0f) {
        o->pos.x = o->dir.x * step + o->pos.x;
        o->pos.y = o->dir.y * step + o->pos.y;
        o->pos.z = o->dir.z * step + o->pos.z;
    }
    ret = fn_801144A4(o, yaw, ang);
    yaw = fn_801DD078(&o->dir, &o->target);
    fn_801DD5E8(ang, &o->target);
    fn_801DCF24(&o->dir, ang, yaw, 1.0f);
    if (fn_80114138(o, yaw, ang) != 0) {
        ret = fn_801144A4(o, yaw, ang);
        yaw = fn_801DD078(&o->dir, &o->target);
        fn_801DD5E8(ang, &o->target);
        fn_801DCF24(&o->dir, ang, yaw, 1.0f);
    }
    return ret;
}

s32 fn_80114B24(s32 a, NJS_POINT3 *p, Src *src, f32 y) {
    s32 r = 0;
    Row *row;
    u16 fl;
    f32 d;
    u32 w;

    if (a == 0) {
        if ((src->flags & 0x1800) == 0x1800) {
            return 1;
        }
        d = p->y - y;
        if (0.0f > d) {
            d = -d;
        }
        if (8.0f <= d) {
            r = 1;
        }
        return r;
    }
    fl = src->flags;
    row = &lbl_802E1154[(*(s8(*)[])&lbl_80310A1C)[6]];
    if ((fl & 0x8000)) {
        switch ((fl >> 8) & 0x7f) {
        case 1:
        case 30:
            if (!(row->flags & 1)) {
                r = 1;
            }
            break;
        case 3:
            if (!(row->flags & 2)) {
                r = 1;
            } else if (150.0f >= p->y) {
                r = 1;
            }
            break;
        case 5:
            if (!(row->flags & 4)) {
                r = 1;
            }
            break;
        case 7:
            if (!(row->flags & 8)) {
                r = 1;
            }
            break;
        }
    }
    if ((*(s32(*)[])&lbl_80311AC0)[1] != 99) {
        return r;
    }
    w = row->flags;
    if (!(w & 0x10) && 150.0f < p->y) {
        r = 1;
    }
    if (w & 0x20) {
        return r;
    }
    if (-150.0f > p->y) {
        r = 1;
    }
    return r;
}

int fn_80115A4C(f32 *pos, u16 *out, HitObj *obj) {
    f32 a[3];
    f32 b[3];
    HitObj tmp;
    int hit;
    int r = 1;

    a[0] = pos[0];
    a[1] = pos[1];
    a[2] = pos[2];
    hit = fn_802256A0(a, obj, 0xFFFF, lbl_8030A3C8[0] & 0xFFFF) != 0;
    b[0] = pos[0];
    b[1] = pos[1];
    b[2] = pos[2];
    tmp.x30 = 4;
    if (fn_802256A0(b, &tmp, 0xFFFF, lbl_8030A3C8[1] & 0xFFFF) != 0) {
        hit |= 2;
    }
    if (hit == 3) {
        if ((f32)fabs(a[1] - pos[1]) > (f32)fabs(b[1] - pos[1])) {
            hit = 2;
        } else {
            hit = 1;
        }
    }
    if (hit == 1) {
        if (a[1] > pos[1]) {
            pos[1] = a[1];
            if (out != 0) {
                *out = obj->x24;
            }
        }
    } else if (hit == 2) {
        if (b[1] < pos[1]) {
            pos[1] = b[1];
            if (out != 0) {
                *out = tmp.x24;
            }
        }
    } else {
        r = 0;
    }
    return r;
}

int fn_80115EAC(Chr *chr, f32 *from, f32 *to) {
    f32 p[3];
    f32 *save;
    int r;

    lbl_8034740C = 0;
    p[0] = from[0];
    p[1] = from[1];
    p[2] = from[2];
    r = fn_80115BBC(p, to, chr->x1b8);
    if (r != 0) {
        save = chr->x1bc->x18;
        chr->x1bc->x18 = p;
        fn_80222838(chr->x1bc);
        if (fn_80222E00(0x4800, chr->x1bc) != 0) {
            r = 0;
        }
        chr->x1bc->x18 = save;
    }
    if (r == 0) {
        r = fn_801157E4(p, from, to, chr->x1b8);
    }
    if (r == 0) {
        if (from[1] != to[1]) {
            p[0] = to[0];
            p[2] = to[2];
            p[1] = from[1];
            r = fn_80115BBC(p, to, chr->x1b8);
            if (r != 0) {
                from[0] = p[0];
                from[1] = p[1];
                from[2] = p[2];
            } else {
                from[0] = to[0];
                from[1] = to[1];
                from[2] = to[2];
            }
        } else {
            from[0] = to[0];
            from[1] = to[1];
            from[2] = to[2];
        }
    } else {
        from[0] = p[0];
        from[1] = p[1];
        from[2] = p[2];
    }
    return r;
}

int fn_801169D4(int sel, PosBlk *pos, void *p, f32 maxd, f32 step) {
    f32 x = 0.0f;
    f32 z = x;
    NJS_MATRIX m;
    PosBlk buf;
    NJS_POINT3 v;
    NJS_POINT3 out;
    f32 d;
    f32 y;

    if (sel == 0) {
        x = 1.7f;
    } else if (sel == 1) {
        x = -1.7f;
    } else {
        z = -0.85f;
    }
    MemCopy(&buf, pos, 0x24);
    y = 0.0f;
    for (d = step; d <= maxd; d += step) {
        njUnitMatrix(m);
        njRotateY(m, pos->ang);
        v.x = x * d;
        v.y = y * d;
        v.z = z * d;
        njCalcPoint(m, &v, &out);
        buf.pos.x = pos->pos.x + out.x;
        buf.pos.y = pos->pos.y + out.y;
        buf.pos.z = pos->pos.z + out.z;
        if (fn_80116B84(3, &buf, lbl_8030A35C, p) == 0) {
            pos->pos.x = buf.pos.x;
            pos->pos.y = buf.pos.y;
            pos->pos.z = buf.pos.z;
            return 1;
        }
    }
    return 0;
}

int fn_80116F2C(Chr_80116F2C *chr) {
    PosBlk tmp;
    int r;

    MemCopy(&tmp, &chr->cur, 0x24);
    r = fn_80116B84(3, &chr->cur, lbl_8030A35C, chr->x1b8);
    if (r == 0) {
        return 1;
    }
    if (r >= 3) {
        if (fn_801169D4(2, &chr->cur, chr->x1b8, lbl_80347434, 0.1f) == 1) {
            return 1;
        }
    } else if (r == 1) {
        if (fn_80117088(&chr->prev, &chr->cur, -10.0f, -170.0f, -10.0f, chr->x1b8) == 1) {
            return 1;
        }
        if (fn_801169D4(1, &chr->cur, chr->x1b8, 2.0f, 0.1f) == 1) {
            return 1;
        }
    } else if (r == 2) {
        if (fn_80117088(&chr->prev, &chr->cur, 10.0f, 170.0f, 10.0f, chr->x1b8) == 1) {
            return 1;
        }
        if (fn_801169D4(0, &chr->cur, chr->x1b8, 2.0f, 0.1f) == 1) {
            return 1;
        }
    }
    MemCopy(&chr->cur, &chr->prev, 0x24);
    return 0;
}

void fn_80117290(Chr_80117290 *c) {
    extern Tbl lbl_8030E7F0;
    extern void fn_80222838(Res *r);
    extern Child *fn_8022300C(Res *r);
    extern Child *fn_80222F14(Res *r, Child *c);
    extern void fn_80221EDC(NJS_POINT3 *out, u32 a, u32 b);
    Child *ch;
    Res *r;
    NJS_POINT3 v;

    if (c->res != 0) {
        c->res->x18[0] = c->pos[0];
        c->res->x18[1] = c->pos[1];
        c->res->x18[2] = c->pos[2];
        fn_80222838(c->res);
        r = c->res;
        if (r != 0) {
            ch = fn_8022300C(r);
            if (ch != 0) {
                do {
                    if ((ch->flags & 0x4800) == 0x4800) {
                        fn_80221EDC(&v, lbl_8030E7F0.x10, lbl_8030E7F0.x1c);
                        r->x18[0] += v.x;
                        r->x18[1] += v.y;
                        r->x18[2] += v.z;
                        fn_80222838(r);
                    }
                    ch = fn_80222F14(r, ch);
                } while (ch != 0);
            }
        }
        c->pos[0] = c->res->x18[0];
        c->pos[1] = c->res->x18[1];
        c->pos[2] = c->res->x18[2];
    }
}

void fn_801173DC(int sel, Chr_801173DC *c) {
    c->tpl = lbl_8031191C;
    c->tpl.x0 = 4;
    if (sel == 0) {
        c->tpl.x2 = 4;
        c->tpl.x4 = 1.9666667f;
        c->tpl.x4 = 35.333332f;
        c->tpl.xc = 600.0f;
        c->tpl.x10 = 0x10000 - 0x18e4;
        c->tpl.x20 = 4.0f;
        c->tpl.x2c = 5.5f;
        c->tpl.x30 = 0x8000;
        c->tpl.x34 = 0x8000;
    } else if (sel == 1) {
        c->tpl.x2 = 7;
        c->tpl.x4 = 1.9666667f;
        c->tpl.x4 = 0.8f;
        c->tpl.xc = 20.0f;
        c->tpl.x10 = -0x71c;
        c->tpl.x20 = 5.0f;
        c->tpl.x2c = 60.0f;
    } else if (sel == 2) {
        c->tpl.x2 = 8;
        c->tpl.x4 = 0.1f;
        c->tpl.xc = 15.0f;
        c->tpl.x10 = 0;
        c->tpl.x20 = 5.0f;
        c->tpl.x2c = 60.0f;
    }
}

void fn_8011753C(Chr_8011753C *c) {
    extern Tbl lbl_8030E7F0;
    extern void fn_80222838(Res *r);
    extern Child *fn_8022300C(Res *r);
    extern Child *fn_80222F14(Res *r, Child *c);
    extern void fn_80221EDC(NJS_POINT3 *out, u32 a, u32 b);
    extern int fn_80116F2C(Chr_8011753C *c);
    Child *ch;
    Res *r;
    NJS_POINT3 v;

    fn_80116F2C(c);
    if (c->res != 0) {
        c->res->x18[0] = c->pos[0];
        c->res->x18[1] = c->pos[1];
        c->res->x18[2] = c->pos[2];
        fn_80222838(c->res);
        r = c->res;
        if (r != 0) {
            ch = fn_8022300C(r);
            if (ch != 0) {
                do {
                    if ((ch->flags & 0x4800) == 0x4800) {
                        fn_80221EDC(&v, lbl_8030E7F0.x10, lbl_8030E7F0.x1c);
                        r->x18[0] += v.x;
                        r->x18[1] += v.y;
                        r->x18[2] += v.z;
                        fn_80222838(r);
                    }
                    ch = fn_80222F14(r, ch);
                } while (ch != 0);
            }
        }
        c->pos[0] = c->res->x18[0];
        c->pos[1] = c->res->x18[1];
        c->pos[2] = c->res->x18[2];
    }
}

void fn_80119E50(Owner_80119E50 *o, Chr_80119E50 *src) {
    extern f32 lbl_80305DF8[8];
    extern s32 lbl_80346E9C;
    extern int fn_8011768C(void);
    extern void fn_801E7414(int n, Chr_80119E50 *c);
    Chr_80119E50 *c;
    u16 id;
    u16 id2;

    lbl_80305DF8[0] = 0.0f;
    lbl_80305DF8[1] = 0.0f;
    lbl_80305DF8[2] = 0.0f;
    lbl_80305DF8[3] = 0.0f;
    lbl_80305DF8[4] = 0.0f;
    lbl_80305DF8[5] = 0.0f;
    lbl_80305DF8[6] = 0.0f;
    lbl_80305DF8[7] = 0.0f;
    c = o->chr;
    id = c->id;
    if (id < 0x16 || id > 0x19) {
        c->x44 = 0;
    }
    if (lbl_80346E9C == 1) {
        lbl_80346E9C = 0;
    } else {
        c = o->chr;
        id = c->id;
        if ((id >= 1 && id <= 4) || (id >= 0x16 && id <= 0x19)) {
            c->xe8 = src->xe8;
            o->chr->x18c = src->x18c;
            id2 = o->chr->id;
            if (id2 >= 1 && id2 <= 4) {
                o->chr->id = 1;
            } else {
                o->chr->id = 0x16;
            }
            o->chr->x172 = 0;
            fn_801E7414(1, o->chr);
        } else if (id >= 7 && id <= 8) {
            c->xe8 = src->xe8;
            o->chr->x18c = src->x18c;
            fn_801E7414(0x1d, o->chr);
        } else if (fn_8011768C() == 4) {
            o->chr->xf0 = src->xe8;
            o->chr->x1a0 = src->x18c;
            o->chr->x19c = 0;
        } else {
            o->chr->xe8 = src->xe8;
            o->chr->x18c = src->x18c;
            o->chr->x19c = 0;
        }
    }
}

void fn_8011D7BC(void *src, u32 big) {
    Rec_8011D7BC *r;
    int i;
    if (lbl_80346EBC >= 20) {
        return;
    }
    r = &lbl_80346EB8[lbl_80346EBC];
    if (big != 0) {
        Big *s = src;
        r->g[0].a[0] = s->g[0].a[0];
        r->g[0].a[1] = s->g[0].a[1];
        r->g[0].a[2] = s->g[0].a[2];
        r->g[0].a[3] = s->g[0].a[3];
        r->g[0].a[4] = s->g[0].a[4];
        r->g[0].n = s->g[0].n;
        r->g[1].a[0] = s->g[1].a[0];
        r->g[1].a[1] = s->g[1].a[1];
        r->g[1].a[2] = s->g[1].a[2];
        r->g[1].a[3] = s->g[1].a[3];
        r->g[1].a[4] = s->g[1].a[4];
        r->g[1].n = s->g[1].n;
        r->g[2].a[0] = s->g[2].a[0];
        r->g[2].a[1] = s->g[2].a[1];
        r->g[2].a[2] = s->g[2].a[2];
        r->g[2].a[3] = s->g[2].a[3];
        r->g[2].a[4] = s->g[2].a[4];
        r->g[2].n = s->g[2].n;
        r->g[3].a[0] = s->g[3].a[0];
        r->g[3].a[1] = s->g[3].a[1];
        r->g[3].a[2] = s->g[3].a[2];
        r->g[3].a[3] = s->g[3].a[3];
        r->g[3].a[4] = s->g[3].a[4];
        r->g[3].n = s->g[3].n;
    } else {
        Small *s = src;
        r->g[0].a[0] = s->g[0].a[0];
        r->g[0].a[1] = s->g[0].a[1];
        r->g[0].a[2] = s->g[0].a[2];
        r->g[0].a[3] = 0.0f;
        r->g[0].a[4] = 0.0f;
        r->g[0].n = s->g[0].n;
        r->g[1].a[0] = s->g[1].a[0];
        r->g[1].a[1] = s->g[1].a[1];
        r->g[1].a[2] = s->g[1].a[2];
        r->g[1].a[3] = 0.0f;
        r->g[1].a[4] = 0.0f;
        r->g[1].n = s->g[1].n;
        r->g[2].a[0] = s->g[2].a[0];
        r->g[2].a[1] = s->g[2].a[1];
        r->g[2].a[2] = s->g[2].a[2];
        r->g[2].a[3] = 0.0f;
        r->g[2].a[4] = 0.0f;
        r->g[2].n = s->g[2].n;
        r->g[3].a[0] = s->g[3].a[0];
        r->g[3].a[1] = s->g[3].a[1];
        r->g[3].a[2] = s->g[3].a[2];
        r->g[3].a[3] = 0.0f;
        r->g[3].a[4] = 0.0f;
        r->g[3].n = s->g[3].n;
    }
    r->big = big;
    lbl_80346EBC++;
}

void fn_80122ED8(Chr_80122ED8 *c) {
    Info *info = c->ext->info;
    Path *p = c->path;
    NJS_POINT3 *a = &p->a;
    NJS_POINT3 *b = &p->b;
    NJS_POINT3 *qz;
    NJS_POINT3 *q1;
    NJS_POINT3 *q0;
    f32 dx, dy, dz;
    int i;

    fn_8009FDA0(p->x73c, info->x28, a, 0, info->x2c, 0, 1);
    fn_8009FDA0(p->x740, info->x3c, b, 0, info->x40, 0, 1);
    dx = b->x - a->x;
    dy = b->y - a->y;
    dz = b->z - a->z;
    q0 = p->p0;
    qz = p->z;
    q1 = p->p1;
    for (i = 0; i < 50; i++) {
        f32 t = (f32)i / 50.0f;
        f32 x, y, z;
        qz->z = 0.0f;
        qz->y = 0.0f;
        qz->x = 0.0f;
        x = a->x + dx * t;
        q1->x = x;
        q0->x = x;
        y = a->y + dy * t;
        q1->y = y;
        q0->y = y;
        z = a->z + dz * t;
        q1->z = z;
        q0->z = z;
        qz++;
        q1++;
        q0++;
    }
}

s32 fn_80128C1C(FormTbl* t)
{
    u8 a[4] = { 0x00, 0x01, 0x33, 0x34 };
    u8 b[6] = { 0x01, 0x00, 0x33, 0x00, 0x34, 0x00 };
    u8 c[7] = { 0x00, 0x32, 0x01, 0x33, 0x01, 0x34, 0x01 };
    u8 d[6] = { 0x00, 0x33, 0x01, 0x33, 0x34, 0x33 };
    u8 e[6] = { 0x00, 0x33, 0x01, 0x33, 0x33, 0x33 };
    s32 i;
    for (i = 0; i < 4; i++)
        t->e[i].id = a[i];
    for (i = 0; i < 6; i++)
        t->e[0].d[i] = b[i];
    for (i = 0; i < 7; i++)
        t->e[1].d[i] = c[i];
    for (i = 0; i < 6; i++)
        t->e[2].d[i] = d[i];
    for (i = 0; i < 6; i++)
        t->e[3].d[i] = e[i];
    t->b_ac = 0x14;
    t->f_b0 = 31.0f;
    t->f_b4 = 40.0f;
    t->f_bc = 41.0f;
    t->f_c0 = 1.0f;
    t->f_c4 = 1.0f;
    return 4;
}

Node_80110AA0 *fn_80110AA0(Self_80110AA0 *self, Tgt_80110AA0 *tgt, s32 ang, s32 flag)
{
    extern Vec_80110AA0 lbl_802B30F0;
    extern u8 lbl_802E4CB0[0x84];
    extern Node_80110AA0 *lbl_80347414;
    extern Eff_80110AA0 *fn_80222224(void *p);
    extern void njUnitMatrix(f32 *m);
    extern void njTranslate(f32 *m, f32 x, f32 y, f32 z);
    extern void njRotateXYZ(f32 *m, s32 x, s32 y, s32 z);
    extern void njCalcPoint(f32 *m, Vec_80110AA0 *p, Vec_80110AA0 *out);
    extern void njUnitVector(Vec_80110AA0 *v);
    extern f32 njInnerProduct(Vec_80110AA0 *a, Vec_80110AA0 *b);
    extern double acos(double x);
    extern Node_80110AA0 *fn_8022300C(void *list);
    extern Node_80110AA0 *fn_80222F14(void *list, void *n);
    extern void fn_80222964(void *p);
    extern void fn_801E1784(void *p);
    Vec_80110AA0 out;
    Vec_80110AA0 v = lbl_802B30F0;
    f32 m[16];
    Eff_80110AA0 *e;
    Node_80110AA0 *found;
    Node_80110AA0 *n;
    s32 a;

    e = fn_80222224(lbl_802E4CB0);
    e->h10 = 0x8000;
    e->h12 = 0x2F;
    e->w8 = self->cfg->w4;
    njUnitMatrix(m);
    njTranslate(m, tgt->pos[0], tgt->pos[1], tgt->pos[2]);
    njRotateXYZ(m, tgt->rot[0], ang, tgt->rot[2]);
    njTranslate(m, 0.0f, 0.0f, 24.0f);
    njCalcPoint(m, &v, &out);
    e->p18[0] = out.x;
    e->p18[1] = out.y;
    e->p18[2] = out.z;
    e->p20[0] = tgt->rot[0];
    e->p20[1] = tgt->rot[1];
    e->p20[2] = tgt->rot[2];
    fn_80222838(e);
    found = 0;
    n = fn_8022300C(e);
    if (n != 0) {
        do {
            if (n->kind == 0x28 || n->kind == 0x14 || n->kind == 0x1D) {
                found = n;
                break;
            }
            n = fn_80222F14(e, n);
        } while (n != 0);
    }
    if (found != 0 && flag == 1 && lbl_80347414->kind != 0x1D) {
        njUnitMatrix(m);
        njRotateXYZ(m, self->r44, self->r48, self->r4c);
        v.z = 1.0f;
        njCalcPoint(m, &v, &out);
        v.x = found->p18[0] - self->x38;
        v.y = found->p18[1] - self->y3c;
        v.z = found->p18[2] - self->z40;
        njUnitVector(&v);
        a = (u16)(s32)(10430.381f * (f32)acos(njInnerProduct(&out, &v)));
        if (a > 0x2000) {
            found = 0;
        }
    }
    fn_80222964(e);
    fn_801E1784(e);
    return found;
}

void fn_801117C4(Obj_801117C4 *o)
{
    extern void MemCopy(void *dst, const void *src, s32 size);
    extern void fn_80118AA4(void *p);
    extern void fn_80118948(void *p);
    extern void fn_80119744(Delta_801117C4 *out, void *obj, void *h, f32 f);
    extern void fn_801E7414(s32 id, void *obj);
    extern s32 fn_802256A0(f32 *pos, void *obj, u32 mask, u16 id);
    Delta_801117C4 d;
    u8 save[0x24];
    D_801117C4 *dd;
    s32 n;

    o->f190 = 1.0f;
    MemCopy(save, &o->f38, 0x24);
    MemCopy(&o->f38, &o->f104, 0x24);
    fn_80118AA4(o);
    fn_80119744(&d, o, o->pe8, o->f18c);
    fn_80118948(o);
    lbl_80347404 = 1;
    MemCopy(&o->f38, save, 0x24);
    o->f38 = o->f104 + d.x;
    o->f3c = o->f108 + d.y;
    o->f40 = o->f10c + d.z;
    o->w44 = o->w110 + d.rx;
    o->w48 = o->w114 + d.ry;
    o->w4c = o->w118 + d.rz;
    switch (o->h172) {
    case 0:
        if (o->w198 == 1) {
            o->f104 = o->f38;
            o->f108 = o->f3c;
            o->f10c = o->f40;
            o->w110 = o->w44;
            o->w114 = o->w48;
            o->w118 = o->w4c;
            fn_801E7414(0x29, o);
            o->w19c = 1;
            o->h172 = 0x10;
        }
        break;
    case 0x10:
        if (o->w198 == 1) {
            o->f104 = o->f38;
            o->f108 = o->f3c;
            o->f10c = o->f40;
            o->w110 = o->w44;
            o->w114 = o->w48;
            o->w118 = o->w4c;
            fn_801E7414(1, o);
            o->w19c = 1;
            dd = o->p1c4->b->c->d;
            n = dd->cnt->count > 8 ? dd->cnt->w24 : 0;
            if (fn_802256A0(&o->f38, o->w1b8, 0xFFFF, n) == 1) {
                o->h170 = 1;
                o->h172 = 0;
            }
        }
        break;
    }
}

s32 fn_801177A4(Obj_801177A4 *obj, Ev_801177A4 *ev) {
    s32 r;
    s32 z;
    switch (ev->x12) {
    case 0x30:
        if (fn_8011768C() != 3) {
            obj->x164 = 0.0f;
            z = 0;
            obj->x170 = 0xf;
            obj->x172 = z;
            obj->x16c = z;
                                                obj->xb4 = obj->xb8 = obj->xbc = (f32)(obj->xc0 = obj->xc4 = obj->xc8 = z);
            obj->x1c4->x10 = ev;
            lbl_8034741C = ev;
            return 1;
        }
        break;
    case 0x22:
    case 0x23:
        r = fn_801161B4();
        if (r == 0 || r == 1) {
            if (fn_8011768C() != 2) {
                obj->x164 = 0.0f;
                z = 0;
                obj->x170 = 0xa;
                obj->x172 = z;
                obj->x16c = z;
                                                                obj->xb4 = obj->xb8 = obj->xbc = (f32)(obj->xc0 = obj->xc4 = obj->xc8 = z);
                obj->x1c4->x10 = ev;
                lbl_8034741C = ev;
                return 1;
            }
        }
        break;
    case 0xe:
    case 0xf:
    case 0x10:
        r = fn_801161B4();
        if (r == 0 || r == 1) {
            if (fn_8011768C() != 1) {
                if (fn_8010E41C(ev->x18, ev->x20, obj->pos) == 2) {
                    z = 0;
                    lbl_80310B3C[0x22] |= 1;
                    obj->x164 = 0.0f;
                    obj->x170 = 5;
                    obj->x172 = z;
                    obj->x16c = z;
                                                                                obj->xb4 = obj->xb8 = obj->xbc = (f32)(obj->xc0 = obj->xc4 = obj->xc8 = z);
                    obj->x1c4->x10 = ev;
                    lbl_8034741C = ev;
                    return 1;
                }
            }
        }
        break;
    }
    return 0;
}

s32 fn_801179B8(Obj_801179B8 *obj, Ev_801179B8 *ev) {
    extern Ev_801179B8 *lbl_80347414;
    extern Ev_801179B8 *lbl_80347418;
    u16 st;
    s32 z;
    switch (ev->x12) {
    case 0x28:
        if (fn_8011768C() == 0) {
            lbl_80347414 = ev;
            z = 0;
            obj->x16c = z;
            obj->xb4 = obj->xb8 = obj->xbc = (f32)(obj->xc0 = obj->xc4 = obj->xc8 = z);
            obj->x170 = 0x15;
            obj->x172 = z;
            return 1;
        }
        break;
    case 0x30:
        st = obj->x170;
        if (fn_8011768C() == 3 && st != 0xf && st != 0x10 && st != 0x14) {
            obj->x170 = 0x14;
            obj->x172 = 0;
            obj->x1c4->x10 = ev;
            lbl_80347418 = ev;
            return 1;
        }
        break;
    case 0x22:
    case 0x23:
        st = obj->x170;
        if (fn_8011768C() == 2 && st != 0xa && st != 0xb && st != 0xc && st != 0xe) {
            obj->x170 = 0xe;
            obj->x172 = 0;
            obj->x1c4->x10 = ev;
            lbl_80347418 = ev;
            return 1;
        }
        break;
    case 0xe:
    case 0xf:
    case 0x10:
        st = obj->x170;
        if (fn_8011768C() == 1 && st != 5 && st != 9 && st != 6) {
            lbl_80310B3C[0x22] &= ~1;
            obj->x170 = 6;
            obj->x16c = 0;
            obj->x1c4->x10 = ev;
            lbl_80347418 = ev;
            return 1;
        }
        break;
    }
    return 0;
}

void fn_80118368(Obj_80118368 *obj) {
    u16 save;
    s32 id;
    if ((*(Req_80118368*)&lbl_8030A380).type != 0) {
        if (3.4028235e38f != (*(Req_80118368*)&lbl_8030A380).a) {
            obj->x38 = obj->x104 = (*(Req_80118368*)&lbl_8030A380).a;
            (*(Req_80118368*)&lbl_8030A380).a = 3.4028235e38f;
        }
        if (3.4028235e38f != (*(Req_80118368*)&lbl_8030A380).b) {
            obj->x3c = obj->x108 = (*(Req_80118368*)&lbl_8030A380).b;
            (*(Req_80118368*)&lbl_8030A380).b = 3.4028235e38f;
        }
        if (3.4028235e38f != (*(Req_80118368*)&lbl_8030A380).c) {
            obj->x40 = obj->x10c = (*(Req_80118368*)&lbl_8030A380).c;
            (*(Req_80118368*)&lbl_8030A380).c = 3.4028235e38f;
        }
        if (3.4028235e38f != (*(Req_80118368*)&lbl_8030A380).d) {
            obj->x44 = obj->x110 = (s32)(182.04445f * (*(Req_80118368*)&lbl_8030A380).d);
            (*(Req_80118368*)&lbl_8030A380).d = 3.4028235e38f;
        }
        if (3.4028235e38f != (*(Req_80118368*)&lbl_8030A380).e) {
            obj->x48 = obj->x114 = (s32)(182.04445f * (*(Req_80118368*)&lbl_8030A380).e);
            (*(Req_80118368*)&lbl_8030A380).e = 3.4028235e38f;
        }
        if (3.4028235e38f != (*(Req_80118368*)&lbl_8030A380).f) {
            obj->x4c = obj->x118 = (s32)(182.04445f * (*(Req_80118368*)&lbl_8030A380).f);
            (*(Req_80118368*)&lbl_8030A380).f = 3.4028235e38f;
        }
        if ((*(Req_80118368*)&lbl_8030A380).type != 1) {
            obj->x170 = 0x16;
            obj->x172 = 0;
        }
        id = (*(Req_80118368*)&lbl_8030A380).ptr;
        if (id != 0x7fffffff) {
            save = obj->x1b8->x30;
            fn_80225930(0xffff, id, obj->x1b8);
            obj->x1b8->x30 = save;
            (*(Req_80118368*)&lbl_8030A380).ptr = 0x7fffffff;
        }
        if (obj->x1bc != 0) {
            fn_80222838(obj->x1bc);
        }
        (*(Req_80118368*)&lbl_8030A380).type = 0;
    }
}

void fn_8011BAE8(Obj_8011BAE8 *obj, Out_8011BAE8 *out) {
    f32 p[3];
    f32 q[3];
    s16 base;
    Res_8011BAE8 *r;
    base = obj->x1dc;
    out->flags = 0;
    if (obj->x1c8->x10->x38 != 0) {
        out->flags |= 1;
    }
    if (obj->x1c8->x10->x3c != 0) {
        out->flags |= 2;
    }
    if (obj->x1c8->x10->x40 != 0) {
        out->flags |= 0x10;
    }
    if (obj->x1c8->x10->x74 != 0) {
        out->flags |= 0x20;
    }
    if (obj->x1c8->x10->x7c != 0) {
        out->flags |= 0x40;
    }
    out->flags |= 0x100;
    out->s4 = obj->x1c8->x10->x4c;
    out->s6 = obj->x1c8->x10->x50;
    if (out->s6 == 0) {
        out->s6 = 1;
    }
    out->s8 = obj->x1c8->x10->x44;
    out->sa = obj->x1c8->x10->x48;
    out->bc = obj->x1c8->x10->x60;
    out->bd = obj->x1c8->x10->x54;
    out->be = obj->x1c8->x10->x58;
    out->bf = obj->x1c8->x10->x5c;
    out->b10 = obj->x1c8->x10->x70;
    out->b11 = obj->x1c8->x10->x64;
    out->b12 = obj->x1c8->x10->x68;
    out->b13 = obj->x1c8->x10->x6c;
    out->f14 = obj->x1c8->x10->x78;
    r = obj->x1c8->x10;
    p[0] = r->x2c;
    p[1] = r->x30;
    p[2] = r->x34;
    q[0] = 0.005493164f * (f32)(s32)r->x38;
    q[1] = 0.005493164f * (f32)(s32)r->x3c;
    q[2] = 0.005493164f * (f32)(s32)r->x40;
    fn_8015F6C0(fn_8015F1A0(obj->x17a + base), r->x24, r->x28, p, q);
}

void fn_8011C858(Task_8011C858 *t) {
    extern void *fn_801E1A2C(s32 a, u32 size);
    extern void fn_801E1784(void *p);
    extern void fn_8015ED90(Task_8011C858 *t);
    extern void fn_8015EB8C(void *p, s32 id, void *cb);
    extern s32 fn_8015E600(void *p);
    extern void fn_8015EBF4(void *p);
    extern void fn_8011BAE0(void);
    extern void fn_8011BAE8(void *work, Rec_8011C858 *rec);
    extern void fn_8011BD5C(void *work, s32 a);
    Work_8011C858 *work = t->work;
    Rec_8011C858 *rec;
    Rec_8011C858 *m;

    if (t->flags & 0x20) {
        t->state = 0xff;
    }
    switch (t->state) {
    case 4:
        if (work != 0) {
            if (work->x1c8->x10->x0 >= 0x1f) {
                t->state = 0;
            }
        }
        break;
    case 0:
        t->x1b = 0xfa;
        work->x26c = 1;
        if (work->x1c8->x10->x0 < 0x1f) {
            t->state = 4;
        } else {
            m = fn_801E1A2C(1, 0x30);
            m->x24 = 0;
            m->x28 = 0;
            work->x25c = m;
            work->x1fa = 0;
            fn_8015ED90(t);
            fn_8015EB8C(work, 0xd, fn_8011BAE0);
            work->x1d8->x1a0 = 0;
            t->state = 1;
        }
        break;
    case 1:
        fn_8015E600(work);
        break;
    case 2:
        rec = work->x25c;
        if ((s32)work->x1fa == 1) {
            fn_8011BAE8(work, rec);
            work->x1fa = 0;
            rec->x24 = fn_801E1A2C(1, rec->s6 * 8);
            rec->x28 = fn_801E1A2C(1, rec->s6 * 12);
            rec->flags |= 0x200;
        }
        if (fn_8015E600(work) == 0) {
            fn_8011BD5C(work, 0);
        }
        break;
    case 3:
        rec = work->x25c;
        if (rec != 0) {
            if (rec->x24 != 0) {
                fn_801E1784(rec->x24);
                rec->x24 = 0;
            }
            if (rec->x28 != 0) {
                fn_801E1784(rec->x28);
                rec->x28 = 0;
            }
            if (work->x25c != 0) {
                fn_801E1784(work->x25c);
                work->x25c = 0;
            }
        }
        fn_8015EBF4(work);
        break;
    case 0xfe:
        break;
    }
}

void fn_8011CA68(Obj_8011CA68 *obj, Out_8011CA68 *out) {
    u8 a;
    u8 b;
    u8 c;
    u8 d;
    out->x8 = obj->x1c8->x10->x24;
    out->f14 = -1.0f / obj->x1c8->x10->x30;
    out->f18 = -1.0f / obj->x1c8->x10->x34;
    a = obj->x1c8->x10->x40;
    b = obj->x1c8->x10->x44;
    c = obj->x1c8->x10->x48;
    d = obj->x1c8->x10->x4c;
    if (d == 0xff) {
        out->x88 = 0;
    } else if (d == 0) {
        out->x88 = 0;
    } else {
        out->x88 = 1;
    }
    out->color = (a << 24) | (b << 16) | (c << 8) | d;
    out->s1c = obj->x1c8->x10->x54;
    out->s1e = obj->x1c8->x10->x58;
    out->f8c = 2.0f;
    out->sc = obj->x1c8->x10->x28;
    out->se = obj->x1c8->x10->x2c;
    if (out->sc > 10) {
        out->sc = 10;
    }
    out->sc = lbl_802B31E8[out->sc];
    if (out->se > 9) {
        out->se = 9;
    }
    out->se = lbl_802B31E8[out->se];
    out->x10 = out->sc * out->se * 2;
    out->flags = 0;
    if (obj->x1c8->x10->x38 != 0 && out->se == out->sc) {
        out->flags |= 1;
    }
    if (obj->x1c8->x10->x50 != 0) {
        out->flags |= 2;
    }
    if (obj->x1c8->x10->x3c != 0) {
        out->flags |= 4;
    }
    if (obj->x1c8->x10->x5c != 0) {
        out->flags |= 8;
    }
    out->x28 = 0;
    out->x24 = 0;
}

void fn_8011CE6C(Task_8011CE6C *t) {
    VertexTex_8011CE6C v[4];
    DrawState ds;
    u8 b;
    f32 z;
    Rec_8011CE6C *rec;
    b = 0xff;
    if (t->flags & 0x20) {
        t->flags |= 0x40;
        return;
    }
    rec = (Rec_8011CE6C *)t->work;
    fn_80290EA8(12);
    if (t->x2c->state == 2) {
        fn_80226D14();
        DrawStateDefault2D(&ds);
        fn_8009E910(&ds, 0, &b);
        DrawStatePush(&ds);
        z = rec->f14;
        v[0].x = v[1].x = 0.0f;
        v[2].x = v[3].x = 640.0f;
        v[0].y = v[2].y = 0.0f;
        v[1].y = v[3].y = 480.0f;
        v[0].z = v[1].z = v[2].z = v[3].z = z;
        v[0].u = v[1].u = 0.0f;
        v[2].u = v[3].u = 0.625f;
        v[0].v = v[2].v = 0.0f;
        v[1].v = v[3].v = 0.9375f;
        v[0].colour = v[1].colour = v[2].colour = v[3].colour = -1;
        fn_80296ED4(0);
        fn_80297DC8((void *)0x1869E);
        fn_80291064(v, 4, 0);
        fn_80296ED4(0x2000);
        DrawStatePop(0);
        switch (rec->x8) {
        case 0:
            fn_8011D2D8((void *)t);
            break;
        case 1:
        case 2:
            break;
        }
    } else {
        switch (rec->x8) {
        case 0:
        case 1:
            if (rec->x24 != 0) {
                fn_801E1784(rec->x24);
                rec->x24 = 0;
            }
            if (rec->x28 != 0) {
                fn_801E1784(rec->x28);
                rec->x28 = 0;
            }
            fn_802978F4(t->work + 0x3c);
            break;
        }
        t->flags |= 0x40;
    }
}

f32 fn_8011E048(Obj_8011E048 *o, f32 x, f32 z) {
    f32 dist;
    f32 t;
    f32 inv;
    f32 near;
    f32 far;
    u32 c;
    f32 dx = x - o->x4;
    f32 dz = z - o->x8;
    dist = sqrtf(fabs(dx * dx + dz * dz));
    near = o->x44;
    far = o->x48;
    t = dist;
    if (dist < 0.025f) {
        t = 0.0f;
    }
    if (t >= far) {
        return 0.0f;
    }
    if (t <= near) {
        t = t / near;
        if (o->x0 & 0x100) {
            c = o->x98 & 0xffffff;
            if (o->x0 & 0x200) {
                c |= (o->xd4 + (s32)((1.0f - t) * (f32)(o->xd0 - o->xd4))) << 24;
            } else {
                c |= (s32)((f32)o->xd0 * (1.0f - t)) << 24;
            }
            o->x98 = o->xa8 = o->xb8 = o->xc8 = c;
            o->x0 |= 0x20000;
        }
        return t;
    }
    inv = 1.0f - (t - near) / (far - near);
    if (o->x0 & 0x200) {
        c = ((s32)((f32)o->xd4 * inv) << 24) | (o->x98 & 0xffffff);
        o->x98 = o->xa8 = o->xb8 = o->xc8 = c;
        o->x0 |= 0x20000;
    }
    return inv;
}

s32 fn_8011F000(Arg1_8011F000 *a, Arg2_8011F000 *b) {
    extern u8 lbl_802B3200[0x14];
    extern void fn_8028A2A8(Item_8011F000 *p, s32 a);
    extern void fn_8012092C(Rec_8011F000 *r);
    extern void fn_8011F560(Rec_8011F000 *r);
    extern void fn_8011FC10(Rec_8011F000 *r);
    extern void fn_8011F8A8(Rec_8011F000 *r);
    extern void fn_8011F44C(Rec_8011F000 *r);
    extern void fn_8011F274(Rec_8011F000 *r);
    Obj_8011F000 *obj = a->x1d8->obj;
    Rec_8011F000 *rec = obj->x25c;
    DrawState ds;
    Item_8011F000 *p;
    Rec_8011F000 *m;
    s32 n;
    s32 i;
    if (obj == 0) {
        return 0;
    }
    switch (obj->x168) {
    case 0:
        m = b->x1c;
        obj->x25c = m;
        rec = m;
        m->flags = 0x11E0105;
        m->x4 = 2;
        m->frame = 0;
        m->xc = 0;
        m->x10 = 0;
        m->x14 = 0;
        m->x18 = 0;
        m->count = 0xfa;
        m->x28 = lbl_802B3200;
        m->x38 = 8;
        m->x3c = 0;
        m->x40 = obj;
        obj->x168 = 1;
        obj->x1c = 0.0f;
    case 1:
        if (rec != 0) {
            rec->frame++;
            if (rec->flags & 1) {
                fn_8012092C(rec);
            }
            if (rec->flags & 2) {
                if (rec->x18 != 0) {
                    fn_8011F560(rec);
                } else {
                    fn_8011FC10(rec);
                }
                fn_8011F8A8(rec);
                if (rec->flags & 0x80000) {
                    DrawStateDefault2D(&ds);
                    ds.blend_src = 8;
                    ds.blend_dst = 10;
                    DrawStatePush(&ds);
                }
                n = rec->count;
                p = rec->items;
                fn_8028A3E0(1);
                for (i = 0; i < n; i++) {
                    fn_8028A2A8(p++, 4);
                }
                fn_8028A2A4();
                if (rec->flags & 0x80000) {
                    DrawStatePop(0);
                }
                if (++rec->x18 >= 30) {
                    rec->flags &= ~2;
                }
            }
            if (rec->flags & 4) {
                fn_8011F44C(rec);
            }
            if (rec->flags & 8) {
                fn_8011F274(rec);
            }
            if (rec->frame >= 0x23 && (rec->flags & 7) == 0) {
                rec->flags = 0x80000000;
            }
            if (rec->flags & 0x80000000) {
                obj->x168 = 2;
                obj->x50 = obj->x54 = obj->x58 = 1.0f;
            }
        }
        break;
    case 2:
        return 0;
    case 0x100:
        if (--obj->x180 <= 0) {
            obj->x168 = obj->x208;
            obj->x208 = -1;
        }
        break;
    default:
        obj->x168 = 0;
        break;
    }
    return 1;
}

void fn_8011F274(Rec_8011F274 *rec) {
    f32 v;
    s32 n;
    f32 total;
    f32 t;
    f32 fade;
    f32 a;
    f32 b;
    Sub_8011F274 *obj;
    total = (f32)rec->x38;
    t = (f32)rec->x10 / total;
    fade = 1.0f - (f32)rec->x14 / 20.0f;
    obj = rec->x40;
    fn_8011B024(lbl_802B3214, 9, 3, &v, t);
    v = v * fade;
    a = 0.01f * (100.0f + v);
    fn_8011B024(lbl_802B3238, 9, 3, &v, t);
    v = v * fade;
    b = 0.01f * (100.0f + v);
    rec->x2c = obj->x50 = a;
    rec->x30 = obj->x54 = b;
    rec->x34 = obj->x58 = a;
    n = rec->x10 + 1;
    rec->x10 = n;
    if ((f32)n >= total) {
        rec->x10 = 0;
        rec->x38 = (s32)(total - (f32)rec->x3c);
    }
    if (++rec->x14 >= 20) {
        rec->flags &= ~8;
    }
}

void fn_8011FC10(Rec_8011FC10 *rec) {
    Col_8011FC10 col;
    s32 n;
    Part_8011FC10 *part;
    Item_8011FC10 *it;
    Item_8011FC10 *item;
    f32 ox, oy, oz;
    f32 h;
    f32 t;
    s32 *q;
    s32 k;
    n = rec->count;
    item = rec->items;
    part = rec->parts;
    col.u = lbl_8034A030;
    col.b[0] = 0;
    do {
        it = item;
        item++;
        if (rec->flags & 0x1000000) {
            col.b[0] = rand() % 127 + 128;
            col.b[1] = rand();
            col.b[2] = rand();
            col.b[3] = rand();
            part->x54 = col.u;
            col.b[0] = 0;
        }
        ox = part->cx;
        oy = part->cy;
        oz = part->cz;
        t = 0.000030517578f * (f32)rand();
        part->x50 = 2.0f - t;
        h = 0.5 * part->x50;
        it->p[0].x = ox - h;
        it->p[0].y = oy;
        it->p[0].z = oz - h;
        it->p[0].col = col.u;
        it->p[1].x = ox - h;
        it->p[1].y = oy;
        it->p[1].z = oz + h;
        it->p[1].col = col.u;
        it->p[2].x = ox + h;
        it->p[2].y = oy;
        it->p[2].z = oz - h;
        it->p[2].col = col.u;
        it->p[3].x = ox + h;
        it->p[3].y = oy;
        it->p[3].z = oz + h;
        it->p[3].col = col.u;
        q = (s32 *)part;
        for (k = 0; k < 3; k++) {
            q[11] = rand();
            q++;
        }
        part->xc = 0.0f;
        part->x10 = 0.0f;
        part->x14 = 0.0f;
        part->x18 = 0.0f;
        part++;
    } while (--n != 0);
    fn_8011FE2C((void *)rec);
}

void fn_80120A90(T_80120A90* t) {
    extern void* fn_801E1A2C(s32 a, u32 size);
    extern void* memset(void* p, int c, u32 n);
    extern void fn_8015ED90(void* t);
    extern void fn_8015EB8C(void* m, s32 id, void* cb);
    extern s32 fn_8015E600(void* m);
    extern void fn_8015EBF4(void* m);
    extern void fn_80121680(void* m);
    extern void fn_801213E8(void);
    M_80120A90* m = t->m;
    W_80120A90* w = m->work;

    if (t->flags & 0x20) {
        t->state = 0xFF;
    }
    switch (t->state) {
    case 0:
        t->f1b = 0xFA;
        m->f26c = 1;
        w = fn_801E1A2C(1, 0x7C);
        memset(w, 0, 0x7C);
        m->work = w;
        m->f1fa = 0;
        fn_8015ED90(t);
        fn_8015EB8C(m, 0, fn_801213E8);
        fn_8015EB8C(m, 0xD, fn_801213E8);
        m->sub->f1a0 = 0;
        t->state = 1;
        break;
    case 1:
        fn_8015E600(m);
        { s32 q = m->f1fb; if (q == 1) {
            memset(w, 0, 0x7C);
            m->f1fb = 0;
        } }
        if (m->f1ec != 0) {
            m->f1fa = 1;
            t->state = 2;
            w->v = m->f1f1;
        }
        break;
    case 2:
        { s32 q = m->f1fa; if (q == 1) {
            w->owner = m;
            m->f1fa = 0;
        } }
        fn_8015E600(m);
        fn_80121680(m);
        if (w->flags & 0x80000000) {
            m->f1ec = 0;
            m->f1fb = 1;
            t->state = 1;
        }
        break;
    case 0xFF:
        if (m->work != 0) {
            fn_801E1784(m->work);
            m->work = 0;
        }
        fn_8015EBF4(m);
        t->flags |= 0x40;
        break;
    case 0xFE:
    default:
        break;
    }
}

void fn_80121918(T_80121918* t) {
    extern void* fn_801E1A2C(s32 a, u32 size);
    extern void* memset(void* p, int c, u32 n);
    extern void fn_8015ED90(void* t);
    extern void fn_8015EB8C(void* m, s32 id, void* cb);
    extern s32 fn_8015E600(void* m);
    extern void fn_8015EBF4(void* m);
    extern void fn_80122508(void* m);
    extern void fn_80121B1C(void);
    M_80121918* m = t->m;
    W_80121918* w = m->work;

    if (t->flags & 0x20) {
        t->state = 0xFF;
    }
    switch (t->state) {
    case 0:
        t->f1b = 0xFA;
        m->f26c = 1;
        w = fn_801E1A2C(1, 0x84);
        memset(w, 0, 0x84);
        w->v = m->f1f1;
        m->work = w;
        m->f1fa = 0;
        fn_8015ED90(t);
        fn_8015EB8C(m, 0, fn_80121B1C);
        fn_8015EB8C(m, 0xD, fn_80121B1C);
        t->state = 1;
        break;
    case 1:
        fn_8015E600(m);
        { s32 q = m->f1fb; if (q == 1) {
            memset(w, 0, 0x84);
            m->f1fb = 0;
        } }
        if (m->f1ec != 0) {
            m->f1fa = 1;
            t->state = 2;
            w->v = m->f1f1;
        }
        break;
    case 2:
        { s32 q = m->f1fa; if (q == 1) {
            w->owner = m;
            m->f1fa = 0;
        } }
        fn_8015E600(m);
        fn_80122508(m);
        if (w->flags & 0x80000000) {
            if (w->buf != 0) {
                fn_801E1784(w->buf);
                w->buf = 0;
            }
            m->f1ec = 0;
            m->f1fb = 1;
            t->state = 1;
        }
        break;
    case 0xFF:
        if (w != 0) {
            if (w->buf != 0) {
                fn_801E1784(w->buf);
                w->buf = 0;
            }
            if (m->work != 0) {
                fn_801E1784(m->work);
                m->work = 0;
            }
        }
        t->flags |= 0x40;
        break;
    case 0xFE:
    default:
        break;
    }
}

void fn_80124428(Obj_80124428* o, In_80124428* in) {
    switch (in->kind) {
    case 0x18:
        if (in->arg == 1) {
            f32 tbl[4] = { 15.0f, 51.0f, 70.5f, 112.5f };
            s16 i;
            for (i = 0; i < 4; i++) {
                f32 tmp[4] = { 15.0f, 51.0f, 70.5f, 112.5f };
                if (o->f18c == tmp[i]) {
                    *(s32*)(lbl_80346FC8[1] + 0x61c) = 1;
                    break;
                }
            }
        }
        break;
    case 0x19: {
        s8 v = in->arg;
        if ((v == 1) | (v == 3)) {
            f32 xa[2] = { 30.0f, 90.0f };
            f32 ya[2] = { 2.0f, 64.0f };
            s16 i;
            for (i = 0; i < 2; i++) {
                f32 sel[2];
                f32 xb[2] = { 30.0f, 90.0f };
                f32 yb[2] = { 2.0f, 64.0f };
                if (in->arg == 1) {
                    sel[0] = xb[0];
                    sel[1] = xb[1];
                } else {
                    sel[0] = yb[0];
                    sel[1] = yb[1];
                }
                if (o->f18c == sel[i]) {
                    *(s32*)(lbl_80346FC8[1] + 0x61c) = 1;
                    break;
                }
            }
        }
        break;
    }
    case 0x23: {
        if (in->arg != 1) {
            u8* p = lbl_80346FC8[1];
            if (15.0f == o->f18c) {
                *(s32*)(p + 0x61c) = 1;
            }
        }
        break;
    }
    case 0x1A: {
        s8 v = in->arg;
        if (v != 0) {
            f32 t;
            u8* p;
            if (v == 1) {
                t = 20.0f;
            }
            if (v == 3) {
                t = 32.0f;
            }
            p = lbl_80346FC8[1];
            if (o->f18c == t) {
                *(s32*)(p + 0x61c) = 1;
            }
        }
        break;
    }
    }
}

void fn_80124A7C(Obj_80124A7C* o, In_80124A7C* in, s32 mode) {
    if (mode != 0) {
        f32 v;
        s16 p;
        in->h30++;
        if (0.0f == o->f18c) {
            in->h30 = 0;
        }
        if (in->f5 == 0) {
            v = 0.0f;
            if (mode == 1) {
                p = 0x28;
                if (in->h30 >= 0x50) {
                    in->h30 = 0;
                }
            } else {
                p = 0x3C;
                if (in->h30 >= 0x78) {
                    in->h30 = 0;
                }
            }
            if (in->h30 / p == 0) {
                v = v - 0.002f * (f32)in->h30;
            } else {
                v = -(0.002f * (f32)p);
                v += 0.002f * (f32)(in->h30 - p);
            }
            o->f50 += v;
            o->f58 += v;
        }
        if (in->f5 == 4) {
            o->fb8 = o->fb8 - 0.15f * (f32)in->h30;
        }
        if (in->f5 == 1) {
            o->fb8 = o->fb8 - 6.0f;
            o->fb8 = o->fb8 - 0.15f * (f32)in->h30;
        }
        if (in->f5 == 5) {
            o->fb8 = o->fb8 - 6.0f;
            o->fb8 = o->fb8 + 0.15f * (f32)in->h30;
        }
    }
}

static inline s32 Sync_80125820(Obj_80125820* o, In_80125820* in) {
    s16 i;
    s32 changed = 0;
    for (i = 0; i < 3; i++) {
        f32 d = o->pos[i] - in->pos[i];
        f32 cur = o->pos[i];
        if ((d <= -0.01f) | (d >= 0.01f)) {
            changed = 1;
            in->pos[i] = cur;
        }
    }
    return changed;
}

static inline s32 Out_80125820(f32* p, f32* q) {
    s16 i;
    for (i = 0; i < 3; i++) {
        f32 d = p[i] - q[i];
        if ((d <= -0.01f) | (d >= 0.01f)) {
            return 1;
        }
    }
    return 0;
}

void fn_80125820(Obj_80125820* o, In_80125820* in) {
    if (in->h0a == 0) {
        if (in->b17 == 0 && in->f5 == 0) {
            s32 changed = Sync_80125820(o, in);
            if (changed) {
                in->b17 = 1;
                lbl_80310A1C[0xC0] = in->b17;
            }
        }
        if (in->b17 == 1 && in->f5 == 1) {
            Rec_80125820 b;
            Rec_80125820 a;
            f32 t = 1.0f + in->f120;
            fn_80157684(&a, 1, in->f120);
            fn_80157684(&b, 1, t);
            if (!Out_80125820(a.pos, b.pos) && lbl_803472B4 == in->h20 - 1) {
                fn_80126F0C(o, in);
                in->b17 = 0;
                lbl_80310A1C[0xC0] = in->b17;
            }
        }
    }
}

void fn_80127F20(T_80127F20* t) {
    extern s32 lbl_80346EC8[2];
    extern void fn_80227810(void* texlist);
    extern void* fn_801E1A74(s32 size, s32 n);
    extern void fn_8015ED90(void* t);
    extern void fn_8015EB8C(void* m, s32 id, void* cb);
    extern W_80127F20* fn_80125D40(void* m);
    extern void fn_80156994(s32 a, void* m, void* b, void* cb);
    extern void fn_801566B4(s32 a, void* p4, void* p5);
    extern s32 fn_8015E600(void* m);
    extern void fn_80124634(void* m, void* ship);
    extern void fn_80156C6C(void* mtx, void* m);
    extern void fn_80124870(void* m, void* ship);
    extern void fn_80124C68(void* m, void* w);
    extern void fn_801264A4(void* out, s32 a, f32 t);
    extern void fn_80126014(void* m, void* p, void* ship);
    extern void fn_80124CE4(void* m, void* w);
    extern void fn_80124428(void* m, void* ship, void* t);
    extern void fn_80126408(void* m, void* p, u32 v);
    extern void fn_80125C90(void* w);
    extern void fn_801E17E0(void* p);
    extern void fn_8015EBF4(void* m);
    extern void fn_802275A4(void* texlist, s32 a);
    extern void fn_80100B74(void* task);
    extern void fn_80127B8C(void);
    extern void fn_8012645C(void);
    M_80127F20* m = t->m;
    W_80127F20* w;
    u8* q;
    u8* p;
    Ship_80127F20* ship;

    switch (t->state) {
    case 0:
    case 0xFE: {
        fn_80227810(m->f100);
        m->f1e4 = fn_801E1A74(1, 0x88);
        fn_8015ED90(t);
        fn_8015EB8C(m, 1, fn_80127B8C);
        w = fn_80125D40(m);
        m->f23c = w;
        q = w->f4;
        fn_80156994(1, m, q + 0x80, fn_8012645C);
        fn_801566B4(1, q, q + 0x40);
        t->state = 1;
        break;
    }
    case 1: {
        w = m->f23c;
        q = w->f4;
        ship = w->ship;
        if (fn_8015E600(t->m) != 0) {
            njUnitMatrix((f32*)(q + 0x40));
            fn_80124634(m, ship);
            fn_80156C6C(q + 0x40, m);
        } else {
            p = q + 0x80;
            fn_80124870(m, ship);
            fn_80124C68(m, w);
            fn_801264A4((u8*)m + 0x38, 1, 0.0f);
            fn_80126014(m, p, ship);
            fn_80124CE4(m, w);
            fn_80124428(m, ship, t);
            fn_80126408(m, p, ship->f4);
            ship->h34 = 0;
            if (((Pl_80127F20*)q)->fa70 != 0) {
                ((Pl_80127F20*)q)->fa70--;
            }
        }
        break;
    }
    case 0xFF:
        fn_80125C90(m->f23c);
        m->f23c = 0;
        fn_801E17E0(m->f1e4);
        m->f1e4 = 0;
        lbl_80346EC8[0] = 0;
        fn_8015EBF4(t->m);
        if (m->f100 != 0) {
            fn_802275A4(m->f100, 0);
        }
        fn_80100B74(t);
        break;
    }
}

u8 fn_801286F4(FormTbl* t) {
    u8 x[5] = { 0x00, 0x01, 0x02, 0x34, 0x35 };
    u8 y[10] = { 0x01, 0x32, 0x00, 0x02, 0x33, 0x00, 0x34, 0x00, 0x35, 0x02 };
    u8 z[6] = { 0x00, 0x32, 0x01, 0x02, 0x33, 0x00 };
    u8 w[6] = { 0x00, 0x33, 0x02, 0x01, 0x32, 0x00 };
    u8 v[8] = { 0x00, 0x34, 0x01, 0x32, 0x00, 0x02, 0x33, 0x00 };
    u8 u[8] = { 0x02, 0x35, 0x00, 0x33, 0x02, 0x01, 0x32, 0x00 };
    s8 i;

    t->e[0].id = x[0];
    t->e[1].id = x[1];
    t->e[2].id = x[2];
    t->e[3].id = x[3];
    t->e[4].id = x[4];
    for (i = 0; i < 10; i++) {
        t->e[0].d[i] = y[i];
    }
    t->e[1].d[0] = z[0];
    t->e[1].d[1] = z[1];
    t->e[1].d[2] = z[2];
    t->e[1].d[3] = z[3];
    t->e[1].d[4] = z[4];
    t->e[1].d[5] = z[5];
    t->e[2].d[0] = w[0];
    t->e[2].d[1] = w[1];
    t->e[2].d[2] = w[2];
    t->e[2].d[3] = w[3];
    t->e[2].d[4] = w[4];
    t->e[2].d[5] = w[5];
    t->e[3].d[0] = v[0];
    t->e[3].d[1] = v[1];
    t->e[3].d[2] = v[2];
    t->e[3].d[3] = v[3];
    t->e[3].d[4] = v[4];
    t->e[3].d[5] = v[5];
    t->e[3].d[6] = v[6];
    t->e[3].d[7] = v[7];
    t->e[4].d[0] = u[0];
    t->e[4].d[1] = u[1];
    t->e[4].d[2] = u[2];
    t->e[4].d[3] = u[3];
    t->e[4].d[4] = u[4];
    t->e[4].d[5] = u[5];
    t->e[4].d[6] = u[6];
    t->e[4].d[7] = u[7];
    t->b_ac = 0x14;
    t->b_ad = 0x15;
    t->f_b0 = 31.0f;
    t->f_b4 = 40.0f;
    t->f_bc = 41.0f;
    t->f_c0 = 1.0f;
    t->f_c4 = 1.0f;
    return 5;
}

void fn_80122D5C(Task_80122D5C *t) {
    Anim_80122D5C *a = t->anim;
    Parent_80122D5C *p = t->parent;
    u16 j;
    u32 idx;
    u32 cnt;
    u32 n;
    u32 lim;

    if (a == 0 || p == 0) {
        fn_8011B238(0xFFC0C0C0, lbl_802B32A0, lbl_802B32D4, 0x9f);
        a->xa = 0;
        t->flags |= 0x40;
    } else if ((t->flags & 0x20) != 0 || p->xc->x19 != 2) {
        a->xa = 0;
        t->flags |= 0x40;
    } else {
        fn_801D6CBC(p->x0, a->x14);
        cnt = a->x4 + 1;
        a->x4 = cnt;
        idx = a->x8;
        if (cnt % a->ent[idx].c == 0) {
            j = idx + 1;
            a->x8 = j;
            if (a->ent[j].c == 0) {
                lim = a->x10;
                if (lim != 0) {
                    n = a->xc + 1;
                    a->xc = n;
                    if (n >= lim) {
                        a->xa = 0;
                        t->flags |= 0x40;
                        return;
                    }
                }
                a->x8 = 0;
            }
            a->x4 = 0;
            a->x16 = a->ent[a->x8].a;
            a->x17 = a->ent[a->x8].b;
        }
    }
}

s32 fn_801186D8(Obj_801186D8 *obj) {
    u8 type;
    Tbl_801186D8 *tbl;
    s32 j;
    s32 k;
    Task *t;
    type = (obj->x1b8->x24 >> 4) & 0xf;
    if (type != 1) {
        return type;
    }
    if (fn_801161B4() != 0) {
        return type;
    }
    if (obj->x170 == 2) {
        tbl = &(*(Tbl_801186D8(*)[10])&lbl_802E5078)[0];
    } else if (obj->x170 == 4 || obj->x170 == 3) {
        tbl = &(*(Tbl_801186D8(*)[10])&lbl_802E5078)[1];
    } else {
        return type;
    }
    for (j = 0; j < 2; j++) {
        if (tbl->t[j] <= obj->x18c && obj->x190 + tbl->t[j] > obj->x18c && obj->x19c == 1) {
            for (k = 0; k < tbl->count; k++) {
                t = fn_801C6180(lbl_80347454, fn_8010DEE8);
                ((Spawn_801186D8 *)t->work)->xe4 = *obj->x1c8->x14[tbl->a[k] + 1];
                ((Spawn_801186D8 *)t->work)->x100 = obj->x1c8->x14[tbl->a[k] + 1] + 2;
                ((Spawn_801186D8 *)t->work)->xe8 = obj->x1c8->x1c[tbl->b[k] + 1];
                if (k == 1) {
                    ((Spawn_801186D8 *)t->work)->x190 = 2.0f;
                }
                ((Spawn_801186D8 *)t->work)->x190 = 1.0f;
                ((Spawn_801186D8 *)t->work)->x38 = obj->x38;
                ((Spawn_801186D8 *)t->work)->x3c = obj->x3c;
                ((Spawn_801186D8 *)t->work)->x40 = obj->x40;
                ((Spawn_801186D8 *)t->work)->x44 = obj->x44;
                ((Spawn_801186D8 *)t->work)->x48 = obj->x48;
                ((Spawn_801186D8 *)t->work)->x4c = obj->x4c;
                ((Spawn_801186D8 *)t->work)->xb4 = ((f32 *)tbl)[j * 3 + 2];
                ((Spawn_801186D8 *)t->work)->xb8 = ((f32 *)tbl)[j * 3 + 3];
                ((Spawn_801186D8 *)t->work)->xbc = ((f32 *)tbl)[j * 3 + 4];
                ((Spawn_801186D8 *)t->work)->x16c = 1;
                ((Spawn_801186D8 *)t->work)->x24c = tbl->c[k];
                ((Spawn_801186D8 *)t->work)->x250 = tbl->d[k];
                ((Spawn_801186D8 *)t->work)->x254 = tbl->e[k];
                ((Spawn_801186D8 *)t->work)->x258 = tbl->f[k];
            }
        }
    }
    return type;
}

static inline s32 Busy_8010ECD8(void)
{
    s32 c;
    s32 b;
    s32 a;
    a = 1;
    b = 1;
    c = 1;
    if (lbl_80347444 != 1 && (lbl_80310B3C[33] & 0x80000000) == 0) {
        c = 0;
    }
    if (c == 0 && lbl_80347440 != -1) {
        b = 0;
    }
    if (b == 0 && lbl_80347504 != 1) {
        a = 0;
    }
    return a;
}

void fn_8010ECD8(Obj_8010ECD8 *o)
{
    f32 t;
    fn_801165C4((void *)(o));
    o->f190 = o->pos / 1.1f;
    o->f1a8 = 0.33333334f;
    fn_801189F0((void *)(o));
    if (Busy_8010ECD8() == 0) {
        o->pos = fn_8010EB88(o);
    }
    if (Busy_8010ECD8() == 0) {
        if (MemEqual(o->vec38, o->vec104, 0x24) == 1 && 0.0f == o->pos) {
            lbl_8034743C = lbl_8034743C + 1;
            if (lbl_8034743C >= 5) {
                o->h170 = 0x16;
                o->h172 = 0x10;
                o->h16c = 0;
                o->wc8 = 0;
                fn_801E7414(1, (void *)(o));
                lbl_8034743C = 0;
            }
        } else if (o->pos <= lbl_8034742C) {
            o->h170 = 0x18;
            o->h172 = 0;
            o->h16c = 0;
            o->wc8 = 0;
            fn_801E7414(10, (void *)(o));
            t = o->f1a0 + o->f190;
            o->f18c = t;
            if (t >= (f32)o->pe8->len) {
                o->f18c = o->f18c - (f32)o->pe8->len;
            }
        }
    }
}

static inline s32 Busy_8010F198(void)
{
    s32 c;
    s32 b;
    s32 a;
    a = 1;
    b = 1;
    c = 1;
    if (lbl_80347444 != 1 && (lbl_80310B3C[33] & 0x80000000) == 0) {
        c = 0;
    }
    if (c == 0 && lbl_80347440 != -1) {
        b = 0;
    }
    if (b == 0 && lbl_80347504 != 1) {
        a = 0;
    }
    return a;
}

void fn_8010F198(Obj_8010F198 *o)
{
    f32 t;
    fn_801165C4((void *)(o));
    o->f190 = o->pos / 0.4f;
    o->f1a8 = 0.33333334f;
    fn_801189F0((void *)(o));
    if (Busy_8010F198() == 0) {
        o->pos = fn_8010EB88(o);
    }
    if (Busy_8010F198() == 0) {
        if (MemEqual(o->vec38, o->vec104, 0x24) == 1 && 0.0f == o->pos) {
            lbl_8034743C = lbl_8034743C + 1;
            if (lbl_8034743C >= 5) {
                o->h170 = 0x16;
                o->h172 = 0x10;
                fn_801E7414(1, (void *)(o));
                lbl_8034743C = 0;
            }
        } else if (o->pos > lbl_80347430) {
            o->h170 = 0x18;
            o->h172 = 0;
            fn_801E7414(10, (void *)(o));
            t = o->f1a0 + o->f190;
            o->f18c = t;
            if (t >= (f32)o->pe8->len) {
                o->f18c = o->f18c - (f32)o->pe8->len;
            }
        }
    }
}

static inline s32 Busy_801115EC(void)
{
    s32 c;
    s32 b;
    s32 a;
    a = 1;
    b = 1;
    c = 1;
    if (lbl_80347444 != 1 && (lbl_80310B3C[33] & 0x80000000) == 0) {
        c = 0;
    }
    if (c == 0 && lbl_80347440 != -1) {
        b = 0;
    }
    if (b == 0 && lbl_80347504 != 1) {
        a = 0;
    }
    return a;
}

void fn_801115EC(Obj_801115EC *o)
{
    f32 f;

    fn_801165C4((void *)(o));
    o->f164 = 0.0f;
    o->f190 = 1.0f;
    if (lbl_803474F4 >= 0x384) {
        if (fn_801161B4() == 0) {
            fn_801E7414(0xB, (void *)(o));
            o->f190 = 0.8f;
        } else {
            fn_801E7414(1, (void *)(o));
        }
    } else {
        fn_801E7414(1, (void *)(o));
    }
    if (0.0f != o->f1e0 && o->wc8 != 0) {
        if (o->f1e0 < 0.0f) {
            f = o->f1e0;
            f += 2.0;
            o->f1e0 = f;
            if (f > 0.0f) {
                o->f1e0 = 0.0f;
            }
        } else {
            f = o->f1e0;
            f -= 2.0;
            o->f1e0 = f;
            if (f < 0.0f) {
                o->f1e0 = 0.0f;
            }
        }
        o->wc8 = (s32)(182.04445f * o->f1e0);
        o->h16c = 1;
    } else {
        o->h16c = 0;
    }
    fn_801189F0((void *)(o));
    fn_8011753C((void *)(o));
    if (Busy_801115EC() == 0) {
        f = fn_801D72A0(0, 10);
        if (0.0f != f && lbl_80347578 == 0) {
            o->h170 = 2;
            o->h172 = 0;
            fn_801E7414(2, (void *)(o));
            o->f18c = 16.0f;
        }
    }
}

void fn_8011B448(Task_8011B448 *t) {
    Work_8011B448 *work = t->work;
    void *rec = work->x25c;
    Rec_8011B448 *p;

    if (t->flags & 0x20) {
        t->state = 0xff;
    }
    switch (t->state) {
    case 0:
        t->x1b = 0xfa;
        work->x26c = 1;
        rec = fn_801E1A2C(1, 0x98);
        memset(rec, 0, 0x98);
        work->x25c = rec;
        work->x1fa = 0;
        fn_8015ED90((void *)(t));
        fn_8015EB8C(work, 0, fn_8011B290);
        fn_8015EB8C(work, 0xd, fn_8011B288);
        work->x1d8->x1a0 = 0;
        t->state = 1;
        break;
    case 1:
        fn_8015E600((void *)(work));
        if ((s32)work->x1fb == 1) {
            memset(rec, 0, 0x98);
            work->x1fb = 0;
        }
        break;
    case 2:
        if ((s32)work->x1fa == 1) {
            if (fn_8011B298(work, rec) == 0) {
                break;
            }
            p = ((Rec_8011B448 *)fn_80226704((void *)((*(void **)&lbl_80347588)), (void *)(fn_8011BAA4), 0x28));
            if (p != 0) {
                (*(s32*)&lbl_80346EB4) = 1;
                p->x24 = rec;
            }
            work->x1fa = 0;
        }
        fn_8015E600((void *)(work));
        break;
    case 4:
        break;
    case 0xfe:
        break;
    case 0xff:
        if (work->x25c != 0) {
            fn_801E1784(work->x25c);
            work->x25c = 0;
        }
        fn_8015EBF4((void *)(work));
        t->flags |= 0x40;
        lbl_80346EB0 = 0;
        (*(s32*)&lbl_80346EB4) = 0;
        break;
    }
}

static inline Spawn_8011CC74 *Mk_8011CC74(Rec_8011CC74 *rec, Task_8011CC74 *t) {
    Spawn_8011CC74 *p = ((Spawn_8011CC74 *)fn_80226704((void *)((*(void **)&lbl_80347588)), (void *)(fn_8011CE6C), 0x30));
    if (p == 0) {
        return 0;
    }
    p->x24 = rec;
    p->x28 = t->work;
    p->x2c = t;
    return p;
}

void fn_8011CC74(Task_8011CC74 *t) {
    Work_8011CC74 *work = t->work;
    Rec_8011CC74 *rec = work->x25c;
    Spawn_8011CC74 *p;

    if (t->flags & 0x20) {
        t->state = 0xff;
    }
    switch (t->state) {
    case 4:
        if (work != 0) {
            if (work->x1c8->x10->x0 >= 0x17) {
                t->state = 0;
            }
        }
        break;
    case 0:
        t->x1b = 0xfa;
        *(u8 *)((u8 *)work + 0x26c) = 1;
        if (work->x1c8->x10->x0 < 0x17) {
            t->state = 4;
        } else {
            work->x25c = fn_801E1A2C(1, 0x90);
            work->x1fa = 0;
            fn_8015ED90((void *)(t));
            fn_8015EB8C(work, 0, fn_8011CE64);
            fn_8015EB8C(work, 0xd, fn_8011CC6C);
            work->x1d8->x1a0 = 0;
            t->state = 1;
        }
        break;
    case 1:
        fn_8015E600((void *)(work));
        break;
    case 2:
        if ((s32)work->x1fa == 1) {
            fn_8011CA68((void *)(work), (void *)(rec));
            work->x264 = Mk_8011CC74(rec, t);
            rec->x4 = 0;
            work->x1fa = 0;
        }
        fn_8015E600((void *)(work));
        break;
    case 0xfe:
        break;
    case 0xff:
        if (work->x25c != 0) {
            fn_801E1784(work->x25c);
            work->x25c = 0;
        }
        fn_8015EBF4((void *)(work));
        t->flags |= 0x40;
        break;
    }
}

void fn_80126BF0(Obj_80126BF0* o, In_80126BF0* in) {
    memset(&in->tab, 0xFF, 200);
    switch (in->kind) {
    case 0x18:
        in->b18 = fn_80128B34(&in->tab);
        o->f190 *= 1.5f;
        in->f24 = 0x8000;
        break;
    case 0x19:
        in->b18 = fn_80128A1C(&in->tab);
        in->f24 = 0x8000;
        break;
    case 0x23:
        in->b18 = fn_80128E7C(&in->tab);
        in->f24 = 0x6A;
        break;
    case 0x1A:
        in->b18 = fn_80128DA4(&in->tab);
        in->f24 = 0x68;
        in->b17 = 1;
        break;
    case 0x1B:
        in->b18 = fn_80128938(&in->tab);
        o->f190 *= 1.5f;
        in->f24 = 0x60;
        break;
    case 0x24:
        in->b18 = fn_801286F4(&in->tab);
        in->f24 = 0x6E2;
        break;
    case 0x25:
        in->b18 = fn_80128C1C(&in->tab);
        in->f24 = 0x62;
        break;
    case 0x26:
        in->b18 = fn_8012813C(&in->tab);
        in->f24 = 0x20;
        break;
    case 0x28:
    case 0x29:
        in->b18 = fn_80128670(&in->tab);
        in->f24 = 0x62;
        break;
    case 0x1D:
        in->b18 = fn_801285D8(&in->tab);
        in->f24 = 0x10062;
        break;
    case 0x1E:
    case 0x1F:
        in->b18 = fn_801284C0(&in->tab);
        in->f24 = 0x62;
        break;
    case 0x20:
        in->b18 = fn_801282C4(&in->tab);
        in->f24 = 0x1062;
        break;
    case 0x33:
        in->b18 = fn_801281E8(&in->tab);
        in->f24 = 0x3060;
        break;
    case 0x1C:
        in->b18 = fn_80128414(&in->tab);
        in->f24 = 0x14840;
        break;
    case 0x32:
        in->b18 = fn_801283A4(&in->tab);
        in->f24 = 0x2040;
        break;
    default:
        in->kind = 0;
        in->b18 = fn_80128108(&in->tab);
        in->f24 = 0x40;
        break;
    }
}

void fn_80111C38(Obj_80111C38 *o) {
    extern void fn_80119744(Xf *out, Obj_80111C38 *o, void *anim, f32 t);
    Xf delta;
    Xf saved;
    s32 r;

    o->f190 = 1.0f;
    MemCopy(&saved, &o->x, 0x24);
    MemCopy(&o->x, &o->px, 0x24);
    fn_80118AA4(o);
    fn_80119744(&delta, o, o->anim, o->f18c);
    fn_80118948(o);
    lbl_80347404 = 1;
    MemCopy(&o->x, &saved, 0x24);
    o->x = o->px + delta.x;
    o->y = o->py + delta.y;
    o->z = o->pz + delta.z;
    o->ra = o->pra + delta.a;
    o->rb = o->prb + delta.b;
    o->rc = o->prc + delta.c;
    switch (o->f172) {
    case 0:
        if (o->state == 1) {
            o->px = o->x;
            o->py = o->y;
            o->pz = o->z;
            o->pra = o->ra;
            o->prb = o->rb;
            o->prc = o->rc;
            r = fn_8010E270(o, *(u32 *)((u8 *)lbl_80311970 + 0x20));
            if (r == 0) {
                fn_801E7414(0x2b, o);
            } else if (r == 2) {
                fn_801E7414(0x2c, o);
                o->f170 = 0x12;
                o->f172 = 0;
            } else {
                fn_801E7414(0x2a, o);
                o->f19c = 1;
                o->f170 = 0x13;
                o->f172 = 0;
            }
        }
        break;
    }
}

void fn_80111A78(Obj_80111A78 *o)
{
    extern void fn_80119744(Delta_80111A78 *out, void *obj, void *h, f32 f);
    Delta_80111A78 d;
    u8 save[0x24];
    s32 r;

    o->f190 = 1.0f;
    MemCopy(save, &o->f38, 0x24);
    MemCopy(&o->f38, &o->f104, 0x24);
    fn_80118AA4(o);
    fn_80119744(&d, o, o->pe8, o->f18c);
    fn_80118948(o);
    lbl_80347404 = 1;
    MemCopy(&o->f38, save, 0x24);
    o->f38 = o->f104 + d.x;
    o->f3c = o->f108 + d.y;
    o->f40 = o->f10c + d.z;
    o->w44 = o->w110 + d.rx;
    o->w48 = o->w114 + d.ry;
    o->w4c = o->w118 + d.rz;
    switch (o->h172) {
    case 0:
        if (o->w198 == 1) {
            o->f104 = o->f38;
            o->f108 = o->f3c;
            o->f10c = o->f40;
            o->w110 = o->w44;
            o->w114 = o->w48;
            o->w118 = o->w4c;
            r = fn_8010E270(o, *(u32 *)((u8 *)lbl_80311970 + 0x20));
            if (r == 0) {
                fn_801E7414(0x2B, o);
                o->w19c = 1;
                o->h170 = 0x11;
                o->h172 = 0;
            } else if (r == 2) {
                fn_801E7414(0x2C, o);
                o->w19c = 1;
            } else {
                fn_801E7414(0x2A, o);
                o->w19c = 1;
                o->h170 = 0x13;
                o->h172 = 0;
            }
        }
        break;
    }
}

void fn_80111DE8(Obj_80111DE8 *o)
{
    extern void fn_80119744(Delta_80111DE8 *out, void *obj, void *h, f32 f);
    Delta_80111DE8 d;
    u8 save[0x24];
    s32 r;

    o->f190 = 1.0f;
    MemCopy(save, &o->f38, 0x24);
    MemCopy(&o->f38, &o->f104, 0x24);
    fn_80118AA4(o);
    fn_80119744(&d, o, o->pe8, o->f18c);
    fn_80118948(o);
    lbl_80347404 = 1;
    MemCopy(&o->f38, save, 0x24);
    o->f38 = o->f104 + d.x;
    o->f3c = o->f108 + d.y;
    o->f40 = o->f10c + d.z;
    o->w44 = o->w110 + d.rx;
    o->w48 = o->w114 + d.ry;
    o->w4c = o->w118 + d.rz;
    switch (o->h172) {
    case 0:
        if (o->w198 == 1 || o->pe8 == (o->p1c8->y->count > 0x2A ? o->p1c8->y->wac : 0)) {
            o->f104 = o->f38;
            o->f108 = o->f3c;
            o->f10c = o->f40;
            o->w110 = o->w44;
            o->w114 = o->w48;
            o->w118 = o->w4c;
            r = fn_8010E270(o, *(u32 *)((u8 *)lbl_80311970 + 0x20));
            if (r == 0) {
                fn_801E7414(0x2B, o);
                o->h170 = 0x11;
                o->h172 = 0;
            } else if (r == 2) {
                fn_801E7414(0x2C, o);
                o->h170 = 0x12;
                o->h172 = 0;
            } else {
                fn_801E7414(0x2A, o);
                o->w19c = 1;
            }
        }
        break;
    }
}

void fn_80113934(Obj_80113934 *o) {
    extern void fn_80119744(Xf *out, Obj_80113934 *o, void *anim, f32 t);
    Xf delta;
    Xf saved;
    s16 stick;

    o->f190 = lbl_80347424;
    MemCopy(&saved, &o->x, 0x24);
    MemCopy(&o->x, &o->px, 0x24);
    fn_80118AA4(o);
    fn_80119744(&delta, o, o->anim, o->f18c);
    fn_80118948(o);
    lbl_80347404 = 1;
    MemCopy(&o->x, &saved, 0x24);
    delta.x = 0.0f;
    delta.z = 0.0f;
    o->x = o->px + delta.x;
    o->y = o->py + delta.y;
    o->z = o->pz + delta.z;
    o->ra = o->pra + delta.a;
    o->rb = o->prb + delta.b;
    o->rc = o->prc + delta.c;
    if (o->state == 1) {
        o->px = o->x;
        o->py = o->y;
        o->pz = o->z;
        o->pra = o->ra;
        o->prb = o->rb;
        o->prc = o->rc;
        stick = lbl_80311A60[0]->y;
        if (stick <= -10) {
            fn_801E7414(0x1b, o);
            SePlay(0xf, 5, 0x1b);
            o->f18c = lbl_80347424;
        } else if (stick >= 10) {
            fn_801E7414(0x1c, o);
            SePlay(0xf, 5, 0x1b);
            o->f18c = lbl_80347424;
        } else {
            fn_801E7414(0x1d, o);
            o->f170 = 8;
            o->f172 = 0;
        }
    }
}

s32 fn_8010E270(void *o, u32 base) {
    f32 a;
    s32 ang;
    f32 yy = -lbl_80311A60[0]->y;
    f32 xx = lbl_80311A60[0]->x;

    a = (f32)atan2(yy, xx);
    ang = (u16)(*(s32 *)((u8 *)o + 0x48) - (s32)base - 0x4000 - (s32)(10430.381f * a));
    if (fn_80291A5C((f32)lbl_80311A60[0]->x * (f32)lbl_80311A60[0]->x
                    + (f32)-lbl_80311A60[0]->y * (f32)-lbl_80311A60[0]->y) > 10.0f) {
        if (ang < 0x2000 || ang >= 0x10000 - 0x2000) {
            return 0;
        } else if (ang >= 0x2000 && ang < 0x6000) {
            return 1;
        } else if (ang >= 0x6000 && ang < 0x10000 - 0x6000) {
            return 2;
        } else if (ang >= 0x10000 - 0x6000 && ang < 0x10000 - 0x2000) {
            return 3;
        }
    }
    return -1;
}

s32 fn_801157E4(f32 *out, f32 *from, f32 *to, void *a) {
    extern Chr_801157E4 *lbl_80347450;
    f32 v[3];
    f32 p[3];
    f32 dy;
    f32 dist;
    f32 ndist;
    f32 k;
    f64 c;
    f32 cf;
    s32 r;
    s32 ang;
    s32 a2;
    s32 i;
    s32 na;
    Res_801157E4 *res;
    f32 *save;

    r = 0;
    v[0] = from[0] - to[0];
    dy = from[1] - to[1];
    v[1] = dy;
    v[2] = from[2] - to[2];
    ang = fn_801DD4C4(v[0], v[2]);
    if (lbl_8030EA10.x4 == 0) {
        dist = fn_80291A5C(v[0] * v[0] + v[2] * v[2]);
        ndist = -dist;
        k = 0.4f * dist;
        res = lbl_80347450->x1bc;
        save = res->x18;
        res->x18 = p;
        i = 1;
        a2 = 0x400;
        do {
            v[0] = k * njSin(a2);
            c = v[2] = njCos(a2);
            cf = c;
            v[1] = cf * dy;
            v[2] = cf * ndist;
            fn_801DCE18(v, v, ang);
            p[0] = v[0] + to[0];
            p[1] = v[1] + to[1];
            p[2] = v[2] + to[2];
            r = fn_80115BBC(p, to, a);
            if (r != 0) {
                fn_80222838(res);
                if (fn_80222E00(0x4800, res) == 0) {
                    break;
                }
            }
            na = -a2;
            v[0] = k * njSin(na);
            v[2] = ndist * njCos(na);
            fn_801DCE18(v, v, ang);
            p[0] = v[0] + to[0];
            p[1] = v[1] + to[1];
            p[2] = v[2] + to[2];
            r = fn_80115BBC(p, to, a);
            if (r != 0) {
                fn_80222838(res);
                if (fn_80222E00(0x4800, res) == 0) {
                    break;
                }
                r = 0;
            }
            i++;
            a2 += 0x400;
        } while (i < 16);
        if (r != 0) {
            out[0] = p[0];
            out[1] = p[1];
            out[2] = p[2];
        }
        res->x18 = save;
    }
    return r;
}

void fn_8011605C(int idx) {
    extern Chr_8011605C *lbl_80347450;
    Cfg *cfg = &((Cfg *)lbl_802E54B0)[idx];
    MemCopy(lbl_8030A35C, cfg, 0x24);
    if (lbl_80347450->res != 0) {
        fn_80222964(lbl_80347450->res);
        fn_801E1784(lbl_80347450->res);
        lbl_80347450->res = 0;
    }
    MemCopy(lbl_80305E18, cfg->b, 0x60);
    lbl_80347450->res = fn_80222224(lbl_80305E18);
    lbl_80347450->res->x10 = 0x8000;
    lbl_80347450->res->x12 = 0x2f;
    lbl_80347450->res->x8 = lbl_80347450->ext->x4;
    lbl_80347450->res->x18[0] = lbl_80347450->pos[0];
    lbl_80347450->res->x18[1] = lbl_80347450->pos[1];
    lbl_80347450->res->x18[2] = lbl_80347450->pos[2];
    lbl_80347450->res->x20[0] = lbl_80347450->ang[0];
    lbl_80347450->res->x20[1] = lbl_80347450->ang[1];
    lbl_80347450->res->x20[2] = lbl_80347450->ang[2];
    fn_80222838(lbl_80347450->res);
}

void fn_8011D2D8(Task_8011D2D8 *t) {
    VertexTex_8011D2D8 v[4];
    DrawState ds;
    void *p;
    Rec_8011D2D8 *rec = t->work;
    if ((rec->x4 & 1) == 0) {
        p = fn_801E1A2C(1, rec->se * rec->sc * 2);
        rec->x24 = p;
        if (p == 0) {
            return;
        }
        if (rec->flags & 1) {
            p = fn_801E1A2C(1, rec->se * rec->sc * 2);
            rec->x28 = p;
            if (p == 0) {
                if (rec->x24 != 0) {
                    fn_801E1784(rec->x24);
                    rec->x24 = 0;
                }
                return;
            }
        }
        rec->x2c = fn_80227E74();
        fn_80297DB4(rec->x44, rec->x24, 5, rec->sc, rec->se);
        fn_80297DA4(&rec->name, rec->x44, rec->x2c, 0x40800000);
        rec->name.texaddr = fn_80227268(rec->x2c, 5, rec->sc, rec->se);
        rec->texlist.textures = &rec->name;
        rec->texlist.nbTexture = 1;
        rec->x4 |= 1;
    } else {
        fn_80299040(&rec->texlist);
        fn_80298ED0(0);
        fn_8024E020();
        fn_8011D02C(rec);
        if (rec->flags & 1) {
            fn_802990BC(rec->x28, rec->x24, rec->sc);
            fn_80297BD8(0, rec->x24, 0);
        } else {
            fn_80297BD8(0, rec->x24, 0);
        }
        DrawStateDefault2D(&ds);
        if (rec->flags & 2) {
            ds.blend_src = 8;
            ds.blend_dst = 10;
            DrawStatePush(&ds);
        }
        if (rec->flags & 4) {
            fn_80296ED4(0x2000);
        } else {
            fn_80296ED4(0);
        }
        v[0].x = v[1].x = 0.0f;
        v[2].x = v[3].x = 640.0f;
        v[0].y = v[2].y = 0.0f;
        v[1].y = v[3].y = 480.0f;
        v[0].z = v[1].z = v[2].z = v[3].z = rec->f18;
        v[0].u = v[1].u = 0.0f;
        v[2].u = v[3].u = 1.0f;
        v[0].v = v[2].v = 0.0f;
        v[1].v = v[3].v = 1.0f;
        v[0].colour = v[1].colour = v[2].colour = v[3].colour = rec->color;
        fn_80297DC8(rec->x2c);
        fn_80291064((void *)v, 4, rec->x88);
        if (rec->flags & 2) {
            DrawStatePop(0);
        }
        if ((rec->flags & 4) == 0) {
            fn_80296ED4(0x2000);
        }
    }
}

void fn_8011FE2C(Rec_8011FE2C *r) {
    s32 n = r->count;
    Item_8011FE2C *item = r->items;
    Part_8011FE2C *part = r->parts;
    f32 sx, cx, sy, cy, sz, cz;
    f32 ox, oy, oz;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 A;
    f32 B;
    f32 C;
    f32 D;
    Pt_8011FE2C *pt;
    s32 j;
    do {
        sx = njSin(part->ax);
        cx = njCos(part->ax);
        sy = njSin(part->ay);
        cy = njCos(part->ay);
        sz = njSin(part->az);
        cz = njCos(part->az);
        ox = part->cx;
        oy = part->cy;
        oz = part->cz;
        pt = item->p;
        item++;
        for (j = 0; j < 4; j++) {
            dx = pt->x - ox;
            dy = pt->y - oy;
            dz = pt->z - oz;
            B = dz * sy + dx * cy;
            A = dz * cy - dx * sy;
            C = dy * cx - A * sx;
            D = dy * sx + A * cx;
            pt->z = oz + D;
            pt->x = ox + (B * cz - C * sz);
            pt->y = oy + (B * sz + C * cz);
            pt++;
        }
        part++;
    } while (--n != 0);
}

static inline void VecCopy_80124634(V_80124634* d, V_80124634* s) {
    f32 x = s->x;
    f32 y = s->y;
    f32 z = s->z;
    d->z = z;
    d->y = y;
    d->x = x;
}

extern void* fn_8008F8FC(void* o, s32 i);
extern void fn_8020EF30(s32 id);

void fn_80124634(Obj2_80124634* o, In_80124634* in) {
    s8 idx;
    Own_80124634* own;
    switch (in->kind) {
    case 0x18: {
        V_80124634 saved;
        V_80124634* ps = &saved;
        Rec_80124634 res;
        s32 flag;
        VecCopy_80124634(ps, &o->pos);
        fn_80157684((void *)&res, 1, 0.0f);
        if (res.pos[0] != in->v54.x || res.pos[1] != in->v54.y || res.pos[2] != in->v54.z) {
            if (in->h34 == 0) {
                fn_8020EF30(0x74CC);
            }
            flag = 0;
        } else {
            flag = 2;
        }
        fn_801248C4((s32)o, (void *)in, flag);
        VecCopy_80124634(&o->pos, ps);
        break;
    }
    case 0x1D:
        if ((s8)lbl_80310A1C[0xC0] == 1) {
            if (in->f5 == 0) {
                in->f5 = 1;
                in->f6 = -1;
                in->b17 = 1;
                in->h1a = 0;
            }
        } else if (in->f5 == 1) {
            in->f5 = 0;
            in->f6 = -1;
            in->b17 = 0;
            in->h1a = 0;
        }
        if (in->h1a == 0 && in->f5 != in->f6) {
            in->h1a = 1;
            if (in->f5 == -1) {
                in->f5 = 0;
            }
            in->f6 = in->f5;
            idx = in->f5;
            own = o->own;
            if (in->f7 != 0) {
                void* m = fn_8008F8FC(o, idx);
                o->f198 = 0;
                o->ff0 = o->fe8;
                o->fe8 = (s32)m;
                o->f19c = 0;
                o->f1a0 = o->f18c;
                o->f18c = 0.0f;
                o->f1a4 = 0.0f;
            } else {
                Tbl_80124634* t;
                o->f18c = 0.0f;
                t = own->tbl;
                o->fe8 = t->n > idx ? t->e[idx] : 0;
            }
            fn_80126F0C(o, in);
        }
        break;
    }
    in->h34 = 1;
}

static inline s32 Check_80126118(Obj_80126118* o, In_80126118* in) {
    Cur_80126118* m = o->fe8;
    if (m == 0) {
        return 0;
    }
    if (o->f18c > ((f32)(u32)m->f4 - in->f12c * o->f190) - in->f130) {
        return 1;
    }
    return 0;
}

void fn_80126118(Obj_80126118* o, In_80126118* in) {
    s8* tab = in->tab;

    if (in->f12 != 0) {
        if (in->f12 == 1) {
            in->f12 = 2;
            fn_80126F0C(o, in);
            if (in->f5 != tab[0xAC + in->f13]) {
                in->h1a = 0;
                {
                    s8 t = tab[0xAC + in->f13];
                    if (t == -1) {
                        in->f5 = tab[0xAC];
                    } else {
                        in->f5 = t;
                    }
                }
            } else {
                if (o->f18c < (f32)((s16)o->fe8->f4 >> 1)) {
                    return;
                }
                in->h1a = 1;
                in->f6 = in->f5;
                {
                    s8 idx = in->f5;
                    Own_80126118* own = o->own;
                    if (in->f7 != 0) {
                        void* m = fn_8008F8FC(o, idx);
                        o->f198 = 0;
                        o->ff0 = (s32)o->fe8;
                        o->fe8 = m;
                        o->f19c = 0;
                        o->f1a0 = o->f18c;
                        o->f18c = 0.0f;
                        o->f1a4 = 0.0f;
                    } else {
                        Tbl_80126118* t;
                        o->f18c = 0.0f;
                        t = own->tbl;
                        o->fe8 = (Cur_80126118*)(t->n > idx ? t->e[idx] : 0);
                    }
                }
            }
        }
        if (Check_80126118(o, in) == 1) {
            fn_80126F0C(o, in);
            in->f12 = 0;
            in->h1a = 0;
            if (in->f5 == in->f6) {
                in->f6 = -1;
            }
            in->f5 = tab[in->f17 * 0xE];
        }
    }
}

void fn_801276E8(Obj_801276E8* o, In_801276E8* in) {
    u8 c;
    u8 d;
    Rec_801276E8* r;
    s16 e;
    s32 a;
    s32 b;
    u8* tab;
    s16 g;
    s32 fl;

    tab = in->tab;
    r = (Rec_801276E8*)(tab + in->f11 * 0x14 + 0x48);
    if (in->h1c != 0) {
        in->h1c--;
        if (in->h1c == 0 && in->f2c != 0) {
            fn_8020EF30(in->f2c);
            in->f2c = 0;
        }
    }
    if (in->h1e != 0) {
        in->h1e--;
        if (in->h1e <= 0) {
            in->h1e = 0;
            in->f2c = r->w0c;
            fn_8020EFD4(in->f2c);
        }
    }
    fl = in->f10;
    if (fl & 0x7F) {
        a = r->b4;
        b = r->b5;
        c = r->b1;
        d = r->b2;
        e = r->h6;
        g = r->h8;
        if (fl & 0x80) {
            in->f10 &= 0x7F;
            in->h1a = 0;
            if (in->f5 == in->f6) {
                in->f6 = -1;
            }
            fn_80126F0C(o, in);
            if ((in->f10 & 0x7F) == 1) {
                in->h0e = 0;
                in->h0c = 0;
                in->f5 = c;
                in->h1e = g;
                in->h1c = e;
            } else {
                in->h0e = 2;
                in->h0c = (u8)b;
                in->f5 = d;
            }
        } else {
            if (!(o->f18c < (f32)(u32)o->fe8->f4 - *(f32*)(tab + 0xC0) * o->f190)) {
                fn_80126F0C(o, in);
                in->f10 = 0;
                in->h8 = 0;
                in->h1a = 0;
                if (in->f5 == (s8)d) {
                    in->h0c = (u8)a;
                    in->h0e = 4;
                } else {
                    in->h0e = 1;
                }
                in->f5 = tab[in->f17 * 0xE];
            }
        }
    }
}

void fn_80127994(T_80127994* t) {
    extern s32 fn_8015E600(void* m);
    extern void fn_80126408(void* m, void* p, u32 v);
    M_80127994* m = t->m;
    void* c;
    W_80127994* w;
    u8* base;
    u8* q;
    Foe_80127994* foe;
    void* buf;
    Ship_80127994* ship;

    switch (t->state) {
    case 0:
    case 0xFE:
        fn_80227810(m->f100);
        fn_8015ED90((void *)t);
        t->state = 1;
        break;
    case 1: {
        w = fn_80125D40(m);
        m->f23c = w;
        ship = w->ship;
        buf = fn_801E1C7C(0x40);
        memset(buf, 0, 0x40);
        ship->f13c = buf;
        ship->f134 = m->src->cfg->count > 13 ? m->src->cfg->f38 : 0;
        foe = fn_801094C8(m->src->cfg->count > 14 ? (u32)m->src->cfg->f3c : 0);
        m->foe = foe;
        if (foe == 0) {
            fn_801DBE1C("Leader Ship Is Nothing %d", m->h17a);
        }
        m->f240 = (Aux_80127994*)m->foe->data->f23c;
        t->state = 2;
    }
    case 2:
        if (fn_8015E600(t->m) == 0) {
            w = m->f23c;
            ship = w->ship;
            q = w->f4 + 0x80;
            c = ship->f13c;
            base = m->f240->f4;
            fn_80124C68(m, (void **)w);
            fn_80156B04(base + 0x40, m, 0, 0, c);
            fn_80124CE4(m, w);
            fn_80126408(m, q, ship->f4);
        }
        break;
    case 0xFF: {
        w = m->f23c;
        ship = w->ship;
        if (ship != 0 && ship->f13c != 0) {
            fn_801E17E0(ship->f13c);
            ship->f13c = 0;
        }
        fn_80125C90((void *)w);
        m->f23c = 0;
        fn_8015EBF4(t->m);
        if (m->f100 != 0) {
            fn_802275A4(m->f100, 0);
        }
        fn_80100B74((void *)t);
        break;
    }
    }
}

void fn_80127BC0(M_80127BC0* m) {
    W_80127BC0* w = m->f23c;
    Ship_80127BC0* ship = w->ship;

    if (w->f8 != 0) {
        *w->f8 = 0;
    }
    if (ship->f50 == 0) {
        Rec_80127BC0 rec;
        fn_801264A4(&rec, 1, 0.0f);
        if (0.0f != rec.pos[0] || 0.0f != rec.pos[1] || 0.0f != rec.pos[2] || rec.v[0] != 0 || rec.v[1] != 0 || rec.v[2] != 0) {
            ship->pos[0] = rec.pos[0];
            ship->pos[1] = rec.pos[1];
            ship->pos[2] = rec.pos[2];
            ship->v[0] = rec.v[0];
            ship->v[1] = rec.v[1];
            ship->v[2] = rec.v[2];
            ship->f50 = 1;
        }
    }
    switch (ship->kind) {
    case 0x19: {
        s8 v = ship->b17;
        s32 n;
        if (v == 2) {
            break;
        }
        n = lbl_803472B4;
        if (!((n == 0) | (n == ship->h20))) {
            break;
        }
        if (v == 3) {
            ship->h32 = 0;
            ship->b17 = 2;
            lbl_80310A1C[0xC0] = ship->b17;
            ship->h1a = 0;
            ship->f6 = -1;
            ship->f5 = 2;
            fn_80126E1C((void *)ship, 0);
            break;
        }
    }
    case 0x18:
        if (ship->b17 != 0) {
            if ((lbl_803472B4 == 0) | (lbl_803472B4 == ship->h20)) {
                ship->b17 = 0;
                lbl_80310A1C[0xC0] = ship->b17;
                ship->h1a = 0;
                ship->f6 = -1;
                ship->f5 = 0;
                fn_80126E1C((void *)ship, 0);
                fn_8020EF30(0x74CC);
            }
        }
        break;
    case 0x1D:
        if (lbl_803472B4 == 0) {
            fn_80127E24((void *)m, (void *)ship, 0x100);
        }
        break;
    case 0x1B:
        if (ship->b17 != 0) {
            if ((lbl_803472B4 == 0) | (lbl_803472B4 == ship->h20)) {
                ship->b17 = 0;
            }
        }
        break;
    }
}

int fn_80118204(Chr_80118204 *c) {
    extern int fn_80117BE4(int n, Chr_80118204 *c, Res_80118204 *r);
    Res_80118204 *r;
    Res_80118204 *r2;
    int result;

    if ((lbl_80310B3C[0x21] & 0x80000000) == 0 && fn_8009763C() != 12 && lbl_80347508 != 1) {
        r = c->x1bc;
        if (lbl_80347404 == 0) {
            r->x18 = c->pos;
            r->x20 = c->ang;
            r->x24 = 0;
            r->x28 = 0;
        } else {
            r->x18 = c->pos;
            r->x20 = c->ang;
            r->x24 = c->b4;
            r->x28 = c->c0;
        }
        fn_80222838(r);
        result = fn_80117BE4(0, (void *)c, r);
        if ((lbl_80311A60[0]->x8 & 0x100) && fn_8011768C() == 0) {
            r2 = c->x1c0;
            r2->x18[0] = c->pos[0];
            r2->x18[1] = c->pos[1];
            r2->x18[2] = c->pos[2];
            r2->x20[0] = c->ang[0];
            r2->x20[1] = c->ang[1];
            r2->x20[2] = c->ang[2];
            fn_80222838(r2);
            result |= fn_80117BE4(1, c, r2);
        }
    }
    return result;
}

void fn_801264A4(void *p, s32 n, f32 f) {
    fn_80157684((Rec_80125820*)p, n, f);
}

/* out = a - b */
void fn_8011A960(Vec3 *out, Vec3 *a, Vec3 *b) {
    f32 ax = a->x, ay = a->y, az = a->z;
    f32 bx = b->x, by = b->y, bz = b->z;
    out->z = az - bz;
    out->y = ay - by;
    out->x = ax - bx;
}

void fn_80117B9C(Obj_80117B9C *obj)
{
    s32 z = 0;
    obj->x16c = z;
    obj->xb4 = obj->xb8 = obj->xbc = (f32)(obj->xc0 = obj->xc4 = obj->xc8 = z);
}

void fn_8012A900(Arg_8012A900 *p)
{
    fn_801D5DD8(p->x0, 1.0f, 1.0f, p->x4, p->x8, p->xc, p->x10, p->x14, p->x18, (*(Obj_8012A900 **)&lbl_80346EF8)->x4->x20);
}

void fn_8011DD9C(Obj_8011DD9C *self) {
    Ctx_8011DD9C *c = self->ctx;
    Sub *sub = c->sub;
    if (self->flags & 0x20) self->state = 0xff;
    switch (self->state) {
    case 0:
        if ((*(void **)&lbl_80346EB8) == 0) {
            (*(void **)&lbl_80346EB8) = fn_80005B50(lbl_80346720, 2000);
            lbl_80346EBC = 0;
        }
        self->b1b = 0xfa;
        c->b26c = 1;
        if (c->cfg->hdr->n < 0x3d) {
            self->state = 4;
            break;
        }
        sub = fn_801E1A2C(1, 0xd8);
        memset(sub, 0, 0xd8);
        c->sub = sub;
        c->b1fa = 0;
        fn_8015ED90((void *)(self));
        fn_8015EB8C((void *)(c), 0, (void *)(fn_8011E72C));
        fn_8015EB8C((void *)(c), 0xd, (void *)(fn_8011E040));
        c->p1d8->w1a0 = 0;
        self->state = 1;
        break;
    case 1:
        fn_8015E600((void *)(c));
        if (c->b1fb == 1) {
            if (sub->p88 != 0) {
                fn_801E1784(sub->p88);
                sub->p88 = 0;
            }
            memset(sub, 0, 0xd8);
            fn_8020F154(c->cfg->hdr->w24, c->u17a);
            c->b1fb = 0;
        }
        break;
    case 2:
        if (c->b1fa == 1) {
            if (fn_8011D958(c, sub, 0) == 0) break;
            c->b1fa = 0;
        }
        if (sub->flags & 0x1000000) fn_8011D958(c, sub, 1);
        fn_8015E600((void *)(c));
        break;
    case 3:
        break;
    case 4:
        if (c != 0) {
            if (c->cfg->hdr->n >= 0x3d) self->state = 0;
        }
        break;
    case 5:
        break;
    case 0xff:
        if ((*(void **)&lbl_80346EB8) != 0) {
            fn_80005AD8(lbl_80346720, (*(void **)&lbl_80346EB8));
            (*(void **)&lbl_80346EB8) = 0;
        }
        if (sub != 0) {
            if (sub->p88 != 0) {
                fn_801E1784(sub->p88);
                sub->p88 = 0;
            }
        }
        if (c->sub != 0) {
            fn_801E1784(c->sub);
            c->sub = 0;
        }
        fn_8015EBF4((void *)(c));
        self->flags |= 0x40;
        break;
    }
    self->f20 = lbl_80349FF8;
}

void fn_801213F0(O *o, A *a) {
    s32 s;
    s32 idx;
    s32 t;
    u16 id;
    u8 *r31;
    B *b = a->x1e4;
    Vec3 *ap;
    void *w;
    u8 *p6c;
    u8 *p68;
    if (b == NULL) return;
    id = a->x22e;
    o->x16 = id;
    p6c = fn_8015F1A0(id);
    o->x6c = p6c;
    if (p6c == NULL) return;
    id = a->x22c;
    o->x14 = id;
    p68 = fn_8015F1A0(id);
    o->x68 = p68;
    if (p68 == NULL) return;
    idx = a->x1ed;
    if (idx != 0) {
        o->flags |= 0x10200;
    } else if (a->x1ee != 0) {
        o->flags |= 0x10000;
    } else {
        fn_8020EFD4(id);
    }
    if (a->x1f0 != 0) {
        o->flags |= 0x20000;
    }
    ap = &a->pos;
    o->x60 = (u8 *)b + idx * 0x1c + 0x14;
    r31 = *(u8 **)((u8 *)b->x10 + 0x24);
    o->x5c = r31;
    o->x64 = *(u8 **)(*(u8 **)(r31 + 0x1c8) + 0x10) + 0x3c;
    s = (s32)(0.1f * fn_8011A8B0((Vec3 *)(r31 + 0x38), ap) + 1.0f);
    if (s > 50) s = 50;
    w = (u8 *)o + 0x24;
    t = b->ent[idx].x10;
    o->x8 = s;
    if (t == 0) {
        if (rand() & 1) {
            s = (s32)((f32)s + (20.0f * (3.0517578125e-05f * (f32)rand()) + 10.0f));
        } else {
            s = (s32)((f32)s - (20.0f * (3.0517578125e-05f * (f32)rand()) + 10.0f));
        }
    } else {
        o->flags |= 0x100;
    }
    {
        Vec3 v;
        fn_801575C8(w, fn_80156A8C(*(u16 *)(r31 + 0x17a)), (f32)s);
        fn_8011A960((void *)(&v), (void *)(w), (void *)(ap));
        fn_801DD5E8((void *)(o->x68 + 0x44), (void *)(&v));
    }
    fn_80120C64(o, o->x68);
    {
        f32 x = ap->x, y = ap->y, z = ap->z;
        o->pos.z = z;
        o->pos.y = y;
        o->pos.x = x;
    }
    o->flags |= 1;
}

void fn_80123A44(P_80123A44 *p) {
    Q_80123A44 *q = p->q;
    switch (p->state) {
    case 0:
    case 0xfe:
        q->x25c = fn_801E1A2C(1, 0x744);
        fn_801237EC(q);
        lbl_803473AC = 0;
        q->x26c = 1;
        fn_8015ED90((void *)(p));
        if (q->x1c8->x10->x0 < 0x16) {
            p->state = 4;
            break;
        }
        q->x20c = q->x1c8->x10->x24;
        q->x210 = q->x1c8->x10->x38;
        p->state = 1;
    case 1:
        p->state = 2;
        break;
    case 2:
        if (lbl_803473AC == 1) {
            p->state = 0x96;
            fn_80122ED8((void *)(q));
            lbl_803473AC = 0;
        }
        switch (fn_8015F218(q)) {
        case 1:
            fn_80122ED8((void *)(q));
            break;
        case 2:
            p->state = 1;
            break;
        }
        fn_801231F8(q);
        break;
    case 3:
    case 0xff:
        fn_8015EBF4((void *)(q));
        if (q->x25c != NULL) {
            fn_801E1784(q->x25c);
            q->x25c = NULL;
        }
        fn_80100B74((void *)(p));
        break;
    case 4: {
        Inner_80123A44 *in = q->x1c8->x10;
        if (in->x0 >= 0x16) {
            p->state = 1;
            q->x20c = q->x1c8->x10->x24;
            q->x210 = q->x1c8->x10->x38;
            in->x4c = 0.06f;
            in->x50 = 0.0f;
            in->x54 = 0.75f;
            in->x58 = 1.0f;
        }
        break;
    }
    case 0x96:
        lbl_803473AC = 0;
        fn_80122ED8((void *)(q));
        fn_801231F8(q);
        if (fn_8015F218(q) == 2) p->state = 1;
        break;
    case 0x97:
        if (lbl_803473AC == 0) p->state = 2;
        lbl_803473AC = 0;
        fn_80122ED8((void *)(q));
        fn_801231F8(q);
        if (fn_8015F218(q) == 2) p->state = 1;
        break;
    }
}

s32 fn_801283A4(FormTbl *t)
{
    u8 ids[2] = { 0, 1 };
    u8 a0[1] = { 0 };
    u8 a1[2] = { 0, 1 };
    s32 i;
    for (i = 0; i < 2; i++) {
        t->e[i].id = ids[i];
    }
    for (i = 0; i < 1; i++) {
        t->e[0].d[i] = a0[i];
    }
    for (i = 0; i < 2; i++) {
        t->e[1].d[i] = a1[i];
    }
    t->f_b0 = 31.0f;
    t->f_b4 = 40.0f;
    t->f_bc = 41.0f;
    t->f_c0 = 1.0f;
    t->f_c4 = 1.0f;
    return 2;
}

u8 fn_80128108(FormTbl *t) {
    t->e[0].id = 0;
    t->f_b0 = 31.0f;
    t->f_b4 = 40.0f;
    t->f_bc = 41.0f;
    t->f_c0 = 1.0f;
    t->f_c4 = 1.0f;
    return 1;
}

static inline s32 Busy_8010F3A8(void) {
    s32 c;
    s32 b;
    s32 a;
    a = 1;
    b = 1;
    c = 1;
    if (lbl_80347444 != 1 && (lbl_80310B3C[0x21] & 0x80000000) == 0) {
        c = 0;
    }
    if (c == 0 && lbl_80347440 != -1) {
        b = 0;
    }
    if (b == 0 && lbl_80347504 != 1) {
        a = 0;
    }
    return a;
}

void fn_8010F3A8(Obj_8010F3A8* o) {
    switch (o->h172) {
    case 0:
        o->start.x = o->ang.x;
        o->start.y = o->ang.y;
        o->start.z = o->ang.z;
        fn_801DD3B8(&o->xcc, &o->xd8, &o->start);
        fn_8010E5BC(o);
        o->h172 = 0x10;
    case 0x10:
        fn_801147E8((void *)(o), 0.0f, 0);
        fn_801DD22C(&o->ang, &o->xcc, &o->xd8);
        fn_801189F0((void *)(o));
        if (Busy_8010F3A8() == 0 && fn_801D72A0(0, 0) >= 10.0f) {
            o->h170 = 0x17;
            o->h172 = 0;
            fn_801E7414(2, (void *)(o));
            o->f18c = 16.0f;
        }
        break;
    }
}

s32 fn_80114950(Chr_80114950* o) {
    f32 p[3];
    HitObj h;
    s32 r;

    p[0] = o->pos.x;
    p[1] = o->pos.y;
    p[2] = o->pos.z;
    h.x30 = 4;
    r = fn_80115A4C(p, NULL, &h);
    if (r != 0) {
        if (fn_80114B24(1, (void *)(&o->pos), (void *)(&h), o->pos.y) != 0) {
            r = 0;
        } else if ((f32)fabs(o->pos.y - p[1]) > ((Row_80114950*)lbl_802E1154)[((s8*)lbl_80310A1C)[6]].height / 2) {
            r = 0;
        } else if (fn_80222E00(0x4800, (void *)(o->x1bc)) != 0) {
            r = 0;
        }
    }
    return r;
}

void fn_80116898(Vec3_80116898* in, Vec3_80116898* out) {
    s32 i;

    out->x = in->x;
    out->y = 0.0f;
    out->z = in->z;
    for (i = 0; i < 4; i++) {
        out->x += lbl_80305DF8[i * 2];
        out->z += lbl_80305DF8[i * 2 + 1];
    }
    out->x /= 5.0f;
    out->z /= 5.0f;
    lbl_80305DF8[lbl_80346EA0 * 2] = in->x;
    lbl_80305DF8[lbl_80346EA0 * 2 + 1] = in->z;
    if (++lbl_80346EA0 >= 4) {
        lbl_80346EA0 = 0;
    }
}

void fn_801222A8(Out_801222A8* o, Src_801222A8* s) {
    NJS_POINT3* pos = &s->pos;
    f32 h = lbl_80345878[3];
    NJS_MATRIX m;
    NJS_POINT3 v;
    NJS_POINT3 t;
    f32 scale;

    fn_80291C44(m);
    njCalcVector(m, pos, &v);
    njGetTranslation(m, &t);
    v.x += t.x;
    v.y += t.y;
    v.z += t.z;
    scale = 1.0f / (lbl_80345878[6] * (1.0f / v.z * lbl_80345878[8]));
    o->pos.x = pos->x;
    o->pos.z = pos->z;
    o->pos.y = pos->y + fabs(-h * scale);
}

void fn_8012239C(O_8012239C* o, A_8012239C* a) {
    u8* p6c;
    u8* p70;
    u16 id;
    Chr_8012239C* r;
    s32 s;
    Vec3* ap;
    void* w;
    B_8012239C* b;
    Sub_8012239C* sub;
    Vec3 v;

    b = a->x1e4;
    if (b == NULL) return;
    id = a->x22e;
    o->x66 = id;
    p70 = fn_8015F1A0(id);
    o->x70 = p70;
    if (p70 == NULL) return;
    id = a->x22c;
    o->x64 = id;
    p6c = fn_8015F1A0(id);
    o->x6c = p6c;
    if (p6c == NULL) return;
    o->x2c = o->x70 + 0x38;
    fn_8020EFD4(id);
    sub = &b->sub;
    o->x74 = sub;
    if (sub->x10 != 0) {
        o->flags |= 1;
    }
    r = b->x10->x24;
    o->x68 = r;
    o->x78 = r->x1c8->x10 + 0x3c;
    fn_801222A8((void *)(o), (void *)(a));
    ap = &o->pos;
    s = (s32)(0.2f * fn_8011A8B0(&r->pos, ap) + 1.0f);
    if (s > 50) s = 50;
    o->x8 = s;
    w = o->x38;
    fn_801575C8((void *)(w), fn_80156A8C(r->x17a), (f32)s);
    fn_8011A960((void *)(&v), (void *)(w), (void *)(ap));
    fn_801DD5E8((void *)(o->x6c + 0x44), (void *)(&v));
    fn_80121B24(o, o->x6c);
    o->flags |= 0x40000000;
}

inline s32 IsExpired(Ctx_80125B60* c, Sub_80125B60* s)
{
    if (c->clock == NULL) {
        return 0;
    }
    if (c->f18c > (f32)c->clock->tick - s->f0c0 * c->f190 - s->f0c4) {
        return 1;
    }
    return 0;
}

extern void fn_8020EFD4(s32 id);

void fn_80125A08(Ctx_80125B60* c, Obj_80125B60* o)
{
    s32 k;
    s16 j;
    Sub_80125B60* s;

    s = &o->sub;
    k = o->b17;
    if (o->b5 == s->rows[k].id) {
        return;
    }
    if (IsExpired(c, s) == 1) {
        o->s1a = 0;
        for (j = 0; j < 12; j++) {
            if (s->rows[k].seq[j] == 0xff) {
                return;
            }
            if (o->b6 == s->rows[k].seq[j]) {
                o->b5 = s->rows[k].seq[j + 1];
                o->b7 = 2;
                return;
            }
        }
    } else if (k == 1) {
        if (o->b5 == s->rows[1].seq[0]) {
            o->s1a = 0;
            o->b6 = -2;
            o->b5 = s->rows[1].seq[1];
            o->b7 = 5;
            fn_8020EFD4(0x74cc);
        }
    }
}

s32 fn_80126E24(void* c, f32 t0, f32 t1)
{
    Rec_80125820 a;
    Rec_80125820 b;
    s16 i;
    s32* p = a.v;
    s32* q = b.v;
    fn_80157684(&a, 1, t0);
    fn_80157684(&b, 1, t1);
    for (i = 0; i < 3; i++) {
        if (((f32)(p[i] - q[i]) <= -10.0f) | ((f32)(p[i] - q[i]) >= 10.0f)) {
            return 1;
        }
    }
    return 0;
}

void fn_8012A26C(void)
{
    s32 ready;
    s32 i;

    ready = lbl_80311AC0[1] >= 500;
    if (ready == 0) {
        lbl_80347280 = 0;
        return;
    }
    fn_80158A80();
    fn_8015C6A8();
    fn_80156024();
    fn_80142F88();
    if (lbl_80346EE8 == 1) {
        fn_8012A9FC();
        lbl_80346EE8 = 0;
    }
    fn_8015C618();
    fn_80148DDC();
    for (i = 0; i < lbl_803472C8; i++) {
        if (lbl_80308F98[i].p != NULL) {
            if (lbl_80308F98[i].p != NULL) {
                fn_801E17E0(lbl_80308F98[i].p);
            }
            lbl_80308F98[i].p = NULL;
        }
    }
    lbl_803472C8 = 0;
    TaskDelete(lbl_803472A0);
    lbl_803473EC = 0;
    lbl_803473E8 = 1;
    fn_80217CB0();
    fn_801CBC10();
    lbl_8030CEA0.xc5c = 0;
    if (lbl_8034727C[lbl_803472B4].kind != 2) {
        lbl_80347280 = 1;
    }
}

s32 fn_801281E8(FormTbl *t)
{
    u8 ids[3] = { 0, 1, 2 };
    u8 a0[4] = { 1, 0, 2, 0 };
    u8 a1[4] = { 0, 1, 2, 1 };
    u8 a2[4] = { 0, 2, 1, 2 };
    s32 i;
    for (i = 0; i < 3; i++) {
        t->e[i].id = ids[i];
    }
    for (i = 0; i < 4; i++) {
        t->e[0].d[i] = a0[i];
    }
    for (i = 0; i < 4; i++) {
        t->e[1].d[i] = a1[i];
    }
    for (i = 0; i < 4; i++) {
        t->e[2].d[i] = a2[i];
    }
    t->b_ac = 0x14;
    t->b_ad = 0x14;
    t->f_b0 = 31.0f;
    t->f_b4 = 40.0f;
    t->f_bc = 41.0f;
    t->f_c0 = 1.0f;
    t->f_c4 = 1.0f;
    return 3;
}

s32 fn_801282C4(FormTbl *t)
{
    u8 ids[3] = { 0, 1, 2 };
    u8 a0[4] = { 1, 0, 2, 0 };
    u8 a1[4] = { 0, 1, 2, 1 };
    u8 a2[4] = { 0, 2, 1, 2 };
    s32 i;
    for (i = 0; i < 3; i++) {
        t->e[i].id = ids[i];
    }
    for (i = 0; i < 4; i++) {
        t->e[0].d[i] = a0[i];
    }
    for (i = 0; i < 4; i++) {
        t->e[1].d[i] = a1[i];
    }
    for (i = 0; i < 4; i++) {
        t->e[2].d[i] = a2[i];
    }
    t->b_ac = 0x14;
    t->b_ad = 0x15;
    t->f_b0 = 31.0f;
    t->f_b4 = 40.0f;
    t->f_bc = 41.0f;
    t->f_c0 = 1.0f;
    t->f_c4 = 1.0f;
    return 3;
}

s32 fn_80128DA4(FormTbl *t)
{
    u8 ids[3] = { 1, 0, 3 };
    u8 a0[4] = { 0x35, 0, 0x34, 1 };
    u8 a1[4] = { 0x34, 1, 0x35, 0 };
    u8 a2[4] = { 1, 0x35, 0, 3 };
    s32 i;
    for (i = 0; i < 3; i++) {
        t->e[i].id = ids[i];
    }
    for (i = 0; i < 4; i++) {
        t->e[0].d[i] = a0[i];
    }
    for (i = 0; i < 4; i++) {
        t->e[1].d[i] = a1[i];
    }
    for (i = 0; i < 4; i++) {
        t->e[2].d[i] = a2[i];
    }
    t->b_ac = 0x14;
    t->f_b0 = 31.0f;
    t->f_b4 = 40.0f;
    t->f_bc = 41.0f;
    t->f_c0 = 1.0f;
    t->f_c4 = 1.0f;
    return 3;
}

void fn_801295EC(Parent_801295EC* p)
{
    extern s32 fn_8015E600(Obj_801295EC* o);
    extern void fn_8015EBF4(Obj_801295EC* o);
    Obj_801295EC* o = p->inner;

    switch (p->state) {
    case 0:
    case 0xfe:
        fn_8015ED90((void *)(p));
        o->frame = -1;
        p->state = 1;
        break;
    case 1:
        if (fn_8015E600(p->inner) == 0 && o->frame != lbl_803472C0) {
            o->frame = lbl_803472C0;
            fn_801E735C(lbl_803472C0 % lbl_803472D0, 1.0f, o);
        }
        break;
    case 0xff:
        fn_8015EBF4(p->inner);
        fn_80100B74((void *)(p));
        break;
    }
}

void fn_8010F924(Obj_8010F924* o) {
    extern s32 fn_8015E600(void* work);
    void* work = o->work;
    Work_8010F924* w = work;

    switch (o->state) {
    case 0:
    case 0xfe:
        if (w->texlist != NULL) {
            fn_80227810(w->texlist);
        }
        w->x1b8 = fn_802258BC(0xFFFF, 0xFFFF, 1);
        w->prev.x = w->pos.x;
        w->prev.y = w->pos.y;
        w->prev.z = w->pos.z;
        w->ang2.x = 0;
        w->ang2.y = w->ang.y;
        w->ang2.z = w->ang.z;
        w->model->ang = &w->ang2;
        fn_8015ED90((void *)(o));
        o->state = 1;
        break;
    case 1:
        if (fn_8015E600(work) == 0) {
            fn_80222838((void *)(w->model));
            w->ang2.x = 0;
            w->ang2.y = w->ang.y;
            w->ang2.z = w->ang.z;
            fn_801E66E0(w);
        }
        break;
    case 0xff:
        if (fn_8015E600(work) == 0) {
            if (w->texlist != NULL) {
                fn_802275A4((void *)(w->texlist), 0);
            }
            fn_801E17E0((void *)(w->x1b8));
            fn_80117748(o);
        }
        break;
    }
}

static inline s32 FlagTest(u32 idx) {
    return (lbl_80310B3C[idx >> 5] & (1 << (idx & 31))) != 0;
}

static inline s32 HArg(Hdr_8010F648 *h, s32 k) {
    return h->n > k ? h->a[k] : 0;
}

void fn_8010F648(Obj_8010F648 *self) {
    Ctx_8010F648 *c2;
    Ctx_8010F648 *c;
    Gfx *g;
    Hdr_8010F648 *h;
    s32 n;
    Rec_8010F648 *rec;
    s32 idx;
    s32 on;
    c = self->ctx;
    rec = fn_801094C8(HArg(c->cfg->hdr, 8));
    if (rec == 0) fn_801DBE1C(lbl_802B30FC);
    c2 = rec->ctx;
    switch (self->state) {
    case 0:
    case 0xfe:
        if (c->tex != 0) fn_80227810(c->tex);
        g = fn_80225B74(0xffff, c->u17a);
        g->p1c = &c->pos;
        g->p24 = &c->rot;
        h = c2->cfg->hdr;
        n = h->n;
        idx = n > 12 ? h->a[12] : 0;
        if (idx != -1) {
            on = FlagTest(idx);
            if (on) {
                c2->pos2.x = c2->pos.x = (f32)(n > 8 ? h->a[8] : 0);
                c2->pos2.y = c2->pos.y = (f32)HArg(c2->cfg->hdr, 9);
                c2->pos2.z = c2->pos.z = (f32)HArg(c2->cfg->hdr, 10);
                c->pos2.x = c->pos.x = c2->pos.x;
                c->pos2.y = c->pos.y = 12.0f + c2->pos.y;
                c->pos2.z = c->pos.z = c2->pos.z;
            } else {
                c->pos2.x = c->pos.x = c->cfg->pos.x;
                c->pos2.y = c->pos.y = c->cfg->pos.y;
                c->pos2.z = c->pos.z = c->cfg->pos.z;
                c2->pos2.x = c2->pos.x = c2->cfg->pos.x;
                c2->pos2.y = c2->pos.y = c2->cfg->pos.y;
                c2->pos2.z = c2->pos.z = c2->cfg->pos.z;
            }
        }
        fn_8015ED90(self);
        self->state = 1;
        break;
    case 1:
        if (fn_8015E600(self->ctx) == 0) fn_80222838(c->p1bc);
        break;
    case 0xff:
        fn_8015EBF4(self->ctx);
        if (c->tex != 0) fn_802275A4(c->tex, 0);
        fn_80117748(self);
        break;
    }
}

static inline s32 SameSe(s32 id) {
    s32 d = 1;
    if (lbl_80346E71 == 5 && lbl_80346E70 == id) d = 0;
    return d;
}

static inline void StopSe(Obj_80112868 *o) {
    if (o->u1ec == 1) {
        fn_80217830(o->p23c);
        o->u1ec = 0;
    }
}

void fn_80112868(Obj_80112868 *o) {
    f32 t, lim, step;
    s32 diff;
    o->f190 = 1.0f;
    fn_801189F0(o);
    if (lbl_80311A60[0]->y < -10) {
        diff = SameSe(0x1c);
        if (!(o->u1ec == 1 && diff == 0)) {
            if ((s8)o->u1ec == 1 && diff != 0) StopSe(o);
            o->p23c = SePlay(0xf, 5, 0x1c);
            lbl_80346E71 = 5;
            lbl_80346E70 = 0x1c;
            o->u1ec = 1;
        }
        fn_801E7414(0x1f, o);
        if (o->w19c == 1) {
            if (lbl_80311A60[0]->x > 0x20) {
                o->w48 += 0x2d8;
                o->w114 = o->w48;
            } else if (lbl_80311A60[0]->x < -0x20) {
                o->w48 -= 0x2d8;
                o->w114 = o->w48;
            }
            t = 0.0f;
            step = 0.1f;
            lim = 0.3f;
            while (t <= lim) {
                o->f3c += step;
                fn_8011816C(o, o->p1bc);
                if (o->h170 == 0xe) break;
                t += step;
            }
        }
    } else if (lbl_80311A60[0]->y > 10) {
        diff = SameSe(0x1d);
        if (!(o->u1ec == 1 && diff == 0)) {
            if ((s8)o->u1ec == 1 && diff != 0) StopSe(o);
            o->p23c = SePlay(0xf, 5, 0x1d);
            lbl_80346E71 = 5;
            lbl_80346E70 = 0x1d;
            o->u1ec = 1;
        }
        fn_801E7414(0x20, o);
        if (o->w19c == 1) {
            if (lbl_80311A60[0]->x > 0x20) {
                o->w48 += 0x2d8;
                o->w114 = o->w48;
            } else if (lbl_80311A60[0]->x < -0x20) {
                o->w48 -= 0x2d8;
                o->w114 = o->w48;
            }
            t = 0.0f;
            step = 0.1f;
            lim = 1.0f;
            while (t <= lim) {
                o->f3c -= step;
                fn_8011816C(o, o->p1bc);
                if (o->h170 == 0xe) break;
                t += step;
            }
        }
    } else {
        StopSe(o);
        fn_801E7414(0x1e, o);
    }
    o->f104 = o->f38;
    o->f108 = o->f3c;
    o->f10c = o->f40;
    o->w110 = o->w44;
    o->w114 = o->w48;
    o->w118 = o->w4c;
}

void fn_80117748(struct Obj_80117748 *o) {
    if (o->sub->anim != 0) {
        fn_80222964(o->sub->anim);
        fn_801E1784(o->sub->anim);
        o->sub->anim = 0;
    }
    fn_801C6170(o);
}

void fn_80128F80(void) {
    Cur cur;
    s32 x;
    s32 y;
    s16 id;
    s32 i;
    fn_80219324(3);
    fn_80219378(lbl_802B3388);
    fn_80100150(&cur);
    x = cur.x4;
    y = cur.x8;
    id = 30;
    for (i = 0; lbl_802E5900[i].a != -1; i++) {
        if (x == lbl_802E5900[i].a && y == lbl_802E5900[i].b) {
            id = lbl_802E5900[i].c;
            break;
        }
    }
    sprintf((char *)lbl_80305F60, lbl_802B339C, id);
    lbl_80346ED8 = fn_801CC67C(lbl_80305F60);
    lbl_80346ED4 = 0;
    fn_801CC600(lbl_80346ED8, &lbl_80346ED4, lbl_80346ED0);
}

static inline s32 AtEnd(Obj_80125B60_80125B60 *o, Set_80125B60_80125B60 *s)
{
    if (o->anim == NULL) {
        return 0;
    }
    if (o->f18c > (f32)o->anim->cnt - s->xc0 * o->f190 - s->xc4) {
        return 1;
    }
    return 0;
}

void fn_80125B60(Obj_80125B60_80125B60 *o, In_80125B60_80125B60 *in)
{
    Set_80125B60_80125B60 *s = &in->set;
    s8 k;
    s16 i;

    if (((in->b10 & 0x7f) != 0) | (in->h0e != 0)) {
        return;
    }
    if (in->b12 != 0) {
        return;
    }
    k = in->b17;
    if (in->f5 == s->row[k].id) {
        return;
    }
    if (AtEnd(o, s) != 1) {
        return;
    }
    in->h1a = 0;
    for (i = 0; i < 12; i++) {
        if (s->row[k].list[i] == 0xff) {
            return;
        }
        if (in->f6 == s->row[k].list[i]) {
            in->f5 = s->row[k].list[i + 1];
            return;
        }
    }
}

/* B-spline curve point: out = sum_i N(i)(t * (n - 2)) * p[i]; clamps to the end points. */
void fn_8011AEE4(Pt2* p, int n, int k, Pt2* out, f32 t)
{
    f32 b;
    f32 u;
    f32 x;
    f32 y;
    int i;
    Pt2* q;

    out->x = 0.0f;
    out->y = 0.0f;
    if (n <= 3) {
        return;
    }
    u = (f32)(n - 2) * t;
    if (t <= 0.0f) {
        *out = p[0];
        return;
    }
    if (t >= 1.0f) {
        s32 j = n - 1;
        *out = p[j];
        return;
    }
    x = 0.0f;
    y = 0.0f;
    q = p;
    for (i = 0; i <= n - 1; i++) {
        b = fn_8011A994(i, n - 1, k, k, u);
        x += q->x * b;
        y += q->y * b;
        q++;
    }
    out->x = x;
    out->y = y;
}

void fn_8012048C(void *o) {
    Eff_8012048C *e = o;
    s32 n = e->count;
    Ent_8012048C *ent = e->ents;
    Elem *el = e->elems;
    do {
        u32 flags = e->flags;
        f32 t;
        void *w;
        f32 v[3];
        s32 i;
        f32 *p;
        f32 *q;
        if (flags & 0x100000) {
            s32 d = e->x18 - 14;
            if (d >= 0) {
            } else {
                d = -d;
            }
            if (d <= 10) {
                t = (f32)d / 10.0f;
            } else {
                t = 1.0f;
            }
        } else {
            t = 1.0f - ent->x18;
        }
        if (flags & 0x1000000) {
            w = &ent->x54;
        } else {
            w = 0;
        }
        p = ent->pos; q = ent->vel;
        if (flags & 2) {
            f32 k = 5.0f;
            for (i = 0; i < 3; i++) { v[i] = *p++ + *q++ * k; }
        } else {
            for (i = 0; i < 3; i++) { v[i] = *p++ + *q++; }
        }
        p -= 3;
        q -= 3;
        for (i = 0; i < 3; i++) { q[i] += ent->acc[i]; }
        fn_8011FFF0(p, v, el, t, w);
        el++;
        ent++;
    } while (--n != 0);
}

u8 fn_80128670(FormTbl *t)
{
    u8 ids[2] = { 0, 1 };
    u8 a0[2] = { 1, 0 };
    u8 a1[2] = { 0, 1 };
    s32 i;
    for (i = 0; i < 2; i++) {
        t->e[i].id = ids[i];
    }
    for (i = 0; i < 2; i++) {
        t->e[0].d[i] = a0[i];
    }
    for (i = 0; i < 2; i++) {
        t->e[1].d[i] = a1[i];
    }
    t->b_ac = 0x14;
    t->f_b0 = 31.0f;
    t->f_b4 = 40.0f;
    t->f_bc = 41.0f;
    t->f_c0 = 1.0f;
    t->f_c4 = 1.0f;
    return 2;
}

s32 fn_80128938(FormTbl *t)
{
    u8 ids[2] = { 0, 1 };
    u8 a0[3] = { 1, 0x33, 0 };
    u8 a1[3] = { 0, 0x32, 1 };
    s32 i;
    for (i = 0; i < 2; i++) {
        t->e[i].id = ids[i];
    }
    for (i = 0; i < 7; i++) {
        t->e[0].d[i] = a0[i];
    }
    for (i = 0; i < 7; i++) {
        t->e[1].d[i] = a1[i];
    }
    t->f_b0 = 31.0f;
    t->f_b4 = 40.0f;
    t->f_bc = 41.0f;
    t->f_c0 = 1.0f;
    t->f_c4 = 1.0f;
    t->f_c0 = 1.5f;
    t->f_c4 = -0.5f;
    return 2;
}

s32 fn_80128B34(FormTbl *t)
{
    u8 ids[2] = { 0, 1 };
    u8 a0[7] = { 1, 5, 0, 3, 0, 2, 0 };
    u8 a1[7] = { 0, 4, 1, 3, 1, 2, 1 };
    s32 i;
    for (i = 0; i < 2; i++) {
        t->e[i].id = ids[i];
    }
    for (i = 0; i < 7; i++) {
        t->e[0].d[i] = a0[i];
    }
    for (i = 0; i < 7; i++) {
        t->e[1].d[i] = a1[i];
    }
    t->f_b0 = 31.0f;
    t->f_b4 = 40.0f;
    t->f_bc = 41.0f;
    t->f_c0 = 1.5f;
    t->f_c4 = -0.5f;
    return 2;
}

s32 fn_80128E7C(FormTbl *t)
{
    u8 ids[2] = { 0, 1 };
    u8 a0[4] = { 0x32, 0x34, 1, 0 };
    u8 a1[5] = { 0, 1, 0x32, 0x34, 1 };
    s32 i;
    for (i = 0; i < 2; i++) {
        t->e[i].id = ids[i];
    }
    for (i = 0; i < 4; i++) {
        t->e[0].d[i] = a0[i];
    }
    for (i = 0; i < 5; i++) {
        t->e[1].d[i] = a1[i];
    }
    t->b_ac = 20;
    t->f_b0 = 31.0f;
    t->f_b4 = 40.0f;
    t->f_bc = 41.0f;
    t->f_c0 = 1.0f;
    t->f_c4 = 1.0f;
    return 2;
}

/* 1-D B-spline value: out = sum_i N(i)(t * (n - 2)) * p[i]; clamps to the end values. */
void fn_8011B024(f32* p, int n, int k, f32* out, f32 t)
{
    f32 b;
    f32 u;
    f32 x;
    int i;
    f32* q;

    if (n <= 3) {
        return;
    }
    u = (f32)(n - 2) * t;
    if (t <= 0.0f) {
        *out = p[0];
        return;
    }
    if (t >= 1.0f) {
        s32 j = n - 1;
        *out = p[j];
        return;
    }
    x = 0.0f;
    q = p;
    for (i = 0; i <= n - 1; i++) {
        b = fn_8011A994(i, n - 1, k, k, u);
        x += *q++ * b;
    }
    *out = x;
}
