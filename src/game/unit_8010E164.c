#include "types.h"
#include "game/work_8030CEA0.h"
#include "game/util.h"
#include "ninja.h"
#include <stdarg.h>
#include "game/drawstate.h"
#include <math.h>
#include "game/task.h"
#include "game/evobj.h"
#include "game/btlside.h"
#include <string.h>
#include <dolphin/os/OSFastCast.h>
#include "game/draw2d.h"
extern void fn_80117748();
extern void fn_80114C84(void *a, void *b, void *c, void *d, void *e, void *f);
/* a wall segment: two end points */
typedef struct Seg {
    NJS_POINT3 a;
    NJS_POINT3 b;
} Seg;
typedef struct Flags {
    Seg seg;        /* 0x00 hit wall segment (written by fn_801150DC/fn_8011510C) */
    u8 pad18[0x24 - 0x18];
    u16 h24;
    u8 pad26[0x28 - 0x26];
    s32 w28;
    s16 h2c;
    s16 h2e;
    u16 h30;
} Flags;
/* 0 when the hit (id) is a wall of kind 1/3/30, or of kind 5/7 within 150 below, at a height y
   of at most 150; 1 otherwise. Same kind table as fn_800CF554. */
s32 fn_80114A44(s32 id, NJS_POINT3* p, f32 y, Flags* info);
extern f32 lbl_80349E00;
extern f32 lbl_80349E04;
/* Only the flags halfword at 0x24 is used here. */
typedef struct Src {
    u8 pad0[0x24];
    u16 flags; /* 0x24: bit 0x8000 gates the test, bits 8..14 select the case */
} Src;
s32 fn_80114AB8(s32 a, f32 t, s32 unused, Src *e);
extern s32 lbl_80346E80;
extern s32 fn_801161B4(void);
/* One playable character's movement config (0xA4 bytes, lbl_802E54B0[fn_801161B4()]). */
typedef struct CharCfg {
    u8 a[0x2c];         /* 0x00 (the first 0x24 bytes go to lbl_8030A35C) */
    f32 f2c;            /* 0x2C */
    u8 pad30[0x34 - 0x30];
    u8 b[0x60];         /* 0x34 collision template, copied to lbl_80305E18 */
    f32 f94;            /* 0x94 walk speed */
    f32 f98;            /* 0x98 */
    f32 f9c;            /* 0x9C */
    f32 fa0;            /* 0xA0 */
} CharCfg;
extern CharCfg lbl_802E54B0[];
typedef struct {
    s32 type;   /* 0x00 */
    s32 id;     /* 0x04 */
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
extern Task *lbl_80346EB0;
extern s32 lbl_80346EB4;
extern s32 lbl_803473B4;
extern s32 lbl_803473B0;
extern void *lbl_80346EC0;
extern void fn_8014FA10(void *p);
typedef struct {
    u8 pad0[4];
    s32 v4;
    s32 v8;
    u8 padc[0x20 - 0xc];
    s32 x20;        /* 0x20 */
    u8 pad24[0x46 - 0x24];
    u16 x46;
    u8 pad48[0x4c - 0x48];
    s32 x4c;        /* 0x4C */
    u8 pad50[0x58 - 0x50];
} Rec;
typedef struct Fn80129BD4Head {
    s32 count;
    s32 f4;
    Rec *items;
} Fn80129BD4Head;
extern Fn80129BD4Head *lbl_803472A8;
extern u8 *lbl_803472CC;
extern f32 lbl_8034A398;
extern f32 lbl_803472DC;
extern f32 lbl_8034A380;
extern f32 lbl_8034A3A4;
extern f32 lbl_803472E0;
extern f32 lbl_80346EE4;
/* The current map. */
typedef struct {
    s32 map;
    s32 id;
    s8 sub;
    u8 pad_9[0x3];
} MapInfo;
extern MapInfo lbl_80311AC0;
s32 fn_802238E4(NJS_POINT3 *dst, NJS_POINT3 *src, EvHit *hit);
s32 fn_802254A0(NJS_POINT3 *a, EvHit *h);
void fn_801248C4(s32 a, u8 *obj, s32 flag);
void fn_80123CBC(Task* t);
void *fn_802267AC(void *a, void *b);
void *fn_801E1C7C(s32 size);
extern void *lbl_803475A0;
extern s8 lbl_80310A1C[0x120];
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
void fn_801E5148(EvObj *obj);
void fn_801E5DF0(EvObj *obj);
/* The field camera's state. */
typedef struct CamState {
    u8 pad0[0x10];
    NJS_POINT3 pos;     /* 0x10 */
    Angle ang[3];       /* 0x1C */
} CamState;
extern CamState lbl_80311970;
extern s32 fn_8010E270(EvObj *obj, Angle yaw);
extern void fn_801E7414(s32 id, void *obj);
extern void fn_801189F0(EvObj *o);
extern void fn_80118948(EvObj *o);
extern void fn_80118AA4(EvObj *o);
extern f32 njUnitVector(NJS_POINT3 *v);
extern s32 fn_80224D08(NJS_POINT3 *out, NJS_POINT3 *a, NJS_POINT3 *b, EvHit *q);
extern void fn_80290668(NJS_POINT3 *a, NJS_POINT3 *b, NJS_POINT3 *c, NJS_POINT3 *out);
extern void njOuterProduct(NJS_POINT3 *out, NJS_POINT3 *a, NJS_POINT3 *b);
extern f32 njInnerProduct(NJS_POINT3 *a, NJS_POINT3 *b);
extern f32 fn_80290008(f32 *a, f32 *b);
extern s32 fn_8022BD30(f32 *a, f32 *b);
void fn_80117B9C(EvObj *obj);
extern s32 lbl_80346E68;
extern s32 SePlay(s32 a, s32 id, s32 vol);
struct Pad_80311A60;
extern struct Pad_80311A60 *lbl_80311A60[];
extern s32 lbl_80347404;
extern void fn_80222838(void *p);
s32 fn_80117BE4(s32 which, EvObj* self, EvColl* list);
extern s32 lbl_80347440;
extern s32 lbl_80347444;
extern f32 lbl_80349EDC, lbl_80349EA4, lbl_80349E18;
extern f32 fn_80090EEC(void *p, f32 v);
extern void fn_801E17E0(void *p);
extern void *memset(void *s, int c, unsigned long n);
extern Rec *lbl_803472A4;
extern void fn_8015ED90(void *p);
extern s32 fn_8015E600(void *p);
extern void fn_8015EBF4(void *);
extern void fn_80100B74(Task *task);
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
extern void fn_801E6EC0(NJS_MATRIX m, s32 a, s32 b, s32 c, s32 d);
extern void fn_801E6DD4(NJS_MATRIX m, Fn80129750Inner *in);
extern s32 lbl_803472C0;
extern s32 lbl_803472D0;
extern s32 lbl_80346EDC;
extern s32 lbl_803472B4;
extern s32 lbl_803472AC;
extern u8 lbl_802B3388[];
extern s32 fn_8025EF88(void *, const char *);
extern void fn_8015757C(void *, u16);
/* One arranged ship (lbl_80308EF8, up to 8): its task (work is the ship's EvObj) and four words. */
typedef struct ShipSlot {
    s16 a;
    u8 pad2[2];
    s32 b;
    s32 c;
    s32 d;
} ShipSlot;
typedef struct ShipEntry {
    Task *task;
    ShipSlot s;
} ShipEntry;
extern s32 lbl_803472B0;
extern s32 lbl_8034729C;
extern ShipEntry lbl_80308EF8[];
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
extern f32 lbl_802E5078[];
extern u8 lbl_80346798[8];
/* A position/angle/scale block (0x24 bytes, as at EvObj.pos and EvObj.home). */
typedef struct Xf {
    NJS_POINT3 pos;     /* 0x00 */
    Angle ang[3];       /* 0x0C */
    NJS_POINT3 scl;     /* 0x18 */
} Xf;
void fn_80119744(Xf *out, EvObj *a, NJS_MOTION *m, f32 frame);
extern void njScale(f32* m, f32 x, f32 y, f32 z);
extern void njCalcVector(f32* m, NJS_VECTOR* v, NJS_VECTOR* out);
extern void njGetTranslation(NJS_MATRIX m, NJS_POINT3* out);
extern void fn_800071D8(NJS_MOTION* m, f32 frame);
extern void fn_80007080(NJS_VECTOR* v, s32 a);
extern void fn_80006F1C(s32* w, s32 a);
extern s32 fn_8025CC04(char* buf, const char* fmt, va_list ap);
extern char* fn_8025EDDC(char* s, const char* delim);
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
typedef struct Pt_8011FC10 {
    f32 x, y, z;
    u32 col;
} Pt_8011FC10;
typedef struct Item_8011FC10 {
    Pt_8011FC10 p[4];
} Item_8011FC10;
typedef union Col_8011FC10 {
    u32 u;
    u8 b[4];
} Col_8011FC10;
typedef struct Part_8011FC10 {
    f32 pos[3];
    f32 sc[3];
    f32 x18;
    f32 vx, vy, vz;
    s32 start;
    s32 v[9];
    f32 x50;
    Col_8011FC10 col;
} Part_8011FC10;
typedef struct Rec_8011F000 {
    u32 flags;
    s32 x4;
    s32 frame;
    s32 xc;
    s32 x10;
    s32 x14;
    s32 x18;
    Item_8011FC10 *items;
    Part_8011FC10 *parts;
    s32 count;
    void *x28;
    u8 pad2c[0x38 - 0x2c];
    s32 x38;
    s32 x3c;
    struct Obj_8011F000 *x40;
} Rec_8011F000;
extern void fn_801202C4(Rec_8011F000* o);
extern void fn_8012061C(Rec_8011F000* o);
extern void fn_8012048C(void* o);
extern void fn_8028A3E0(s32 a);
extern void fn_8028A2A8(Item_8011FC10* p, s32 a);
extern void fn_8028A2A4(void);
typedef struct {
    u8 a;
    s8 b;           /* the last frame's b is the loop count */
    u16 dur;
} Frame;
/* A sprite animation (0x98 bytes): up to 31 frames, ended by a zero duration. */
typedef struct {
    s32 handle;     /* 0x00 pad channel */
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
} SprAnim;
extern void fn_801D6CBC(s32 h, void* p);
s32 fn_801D6C3C(s32 chan);
extern void fn_801E1784(void* p);
typedef struct {
    s32 a, b, dur;
} SrcFrame;
typedef struct {
    s32 handle;         /* 0x00 pad channel */
    SrcFrame* frames;   /* 0x04 */
    SprAnim* anim;         /* 0x08 */
    void* owner;        /* 0x0C */
} Src_80122A00;
typedef struct {
    u8 pad00[0x24];
    Src_80122A00* src;       /* 0x24 */
    SprAnim* anim;     /* 0x28 */
} Obj_80122A00;
extern void* lbl_80347588;
extern s32 fn_801D6E38(s32 chan);
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
    s32 x0;             /* pad channel */
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
extern void fn_8014EF34(void *in);
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
typedef struct FormRec {
    s8 b[6];
    s16 h6;
    s16 h8;
    u8 padA[2];
    s32 w0c;
    u8 pad10[2];
    s16 h12;
} FormRec;
typedef struct FormTbl {
    FormEnt e[5];       /* 0x00 */
    u8 pad46[2];
    FormRec r[5];       /* 0x48 */
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
extern s32 fn_801DD078(NJS_POINT3 *a, NJS_POINT3 *b);
extern void fn_801DD5E8(Angle *out, NJS_POINT3 *p);
extern void fn_801DCF24(NJS_POINT3 *p, Angle *ang, s32 yaw, f32 scale);
extern s32 fn_801144A4(EvObj *o, s32 yaw, Angle *ang);
extern s32 fn_80114138(EvObj *o, s32 yaw, Angle *ang);
s32 fn_801147E8(EvObj *o, f32 step, s32 turn);
typedef struct {
    f32 height;     /* 0 */
    u32 flags;      /* 4 */
    u8 pad8[0x20 - 8];
} Row;
extern Row lbl_802E1154[];
extern u32 lbl_8030A3C8[];
extern int fn_802256A0(f32 *pos, EvHit *obj, u32 mask, u32 id);
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
extern struct { s32 pad0; s32 x4; s32 pad8; } lbl_8030EA10;
extern f32 njSin(Angle a);
extern f32 njCos(Angle a);
extern s32 fn_801DD4C4(f32 x, f32 z);
extern void fn_801DCE18(f32 *in, f32 *out, s32 ang);
s32 fn_801157E4(f32 *out, f32 *from, f32 *to, void *a);
extern u32 fn_80222E00(s32 a, void *p);
extern u8 lbl_8030A35C[];
extern void njRotateY(NJS_MATRIX m, Angle y);
extern int fn_80116B84(int n, NJS_POINT3 *pos, void *tbl, void *p);
typedef struct Chr_80116F2C {
    u8 pad0[0x38];
    Xf cur;
    u8 pad5C[0x104 - 0x5C];
    Xf prev;
    u8 pad128[0x1B8 - 0x128];
    void *x1b8;
} Chr_80116F2C;
extern f32 lbl_80347434;
extern int fn_801169D4(int sel, Xf *pos, void *p, f32 maxd, f32 step);
extern int fn_80117088(Xf *a, Xf *b, f32 x, f32 y, f32 z, void *p);
typedef struct Tbl {
    u8 pad0[0x10];
    u32 x10;
    u8 pad14[8];
    u32 x1c;
    u8 pad20[4];
} Tbl;
extern Tpl lbl_8031191C;
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
    VertexTex v[4];
    void *tex;
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
extern u32 lbl_80310B3C[0x356];
extern EvObj *lbl_80347450; /* the player */
extern EvColl *lbl_8034741C; /* the player's current event target */
extern EvColl *lbl_80347414;
extern EvColl *lbl_80347418; /* the player's collision record */
extern s32 fn_8011768C(void);
extern s32 fn_8010E41C(f32 *pos, Angle *ang, f32 *at);
extern void fn_80225930(u16 a, u16 b, void *c);
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
typedef struct T1d8 {
    u8 pad0[0x19];
    u8 state;
} T1d8;
typedef struct Task_8011CE6C {
    u8 pad0[0x18];
    u8 flags;
    u8 state;
    u8 pad1a[0x24 - 0x1a];
    u8 *work;
    u8 pad28[4];
    T1d8 *x2c;
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
extern void fn_80291064(VertexTex *v, s32 n, s32 mode);
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
typedef struct Obj_8011F000 {
    u8 pad0[0x1c];
    f32 x1c;
    u8 pad20[0x38 - 0x20];
    f32 pos[3];
    u8 pad44[0x50 - 0x44];
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
typedef struct O O;
typedef struct Corner_80120C64 {
    f32 a, b, c, d;
} Corner_80120C64;
/* camera view filled by fn_801545EC */
typedef struct View_80120C64 {
    f32 x0, x4, x8, xc, x10;
    Corner_80120C64 q[4]; /* 0x14 */
} View_80120C64;
typedef struct Pose_80120C64 {
    NJS_POINT3 pos;
    Angle ang[3];
} Pose_80120C64;
extern void fn_801545EC(s32 i, View_80120C64 *view);
extern s8 fn_80153DA8(s32 i);
extern void fn_801D9634(NJS_POINT3 *a, Angle *out);
typedef struct Sub_80120A90 {
    u8 _00[0x1a0];
    s32 f1a0;
} Sub_80120A90;
typedef struct M_80120A90 {
    u8 _00[0x1d8];
    Sub_80120A90* sub;
    u8 _1dc[0x10];
    s8 f1ec;
    u8 _1ed[2];
    u8 f1ef;
    u8 _1f0;
    s8 f1f1;
    u8 _1f2[8];
    u8 f1fa;
    u8 f1fb;
    u8 _1fc[0x60];
    O* work;
    u8 _260[0xc];
    u8 f26c;
} M_80120A90;
extern s32 fn_80121680(M_80120A90 *m);
typedef struct T_80120A90 {
    u8 _00[0x18];
    u8 flags;
    u8 state;
    u8 _1a;
    u8 f1b;
    u8 _1c[8];
    M_80120A90* m;
} T_80120A90;
typedef struct O_8012239C O_8012239C;
typedef struct M_80121918 {
    u8 _00[0x1ec];
    s8 f1ec;
    u8 _1ed[2];
    u8 f1ef;
    u8 _1f0;
    s8 f1f1;
    u8 _1f2[8];
    u8 f1fa;
    u8 f1fb;
    u8 _1fc[0x60];
    O_8012239C* work;
    u8 _260[0xc];
    u8 f26c;
} M_80121918;
extern s32 fn_80122508(M_80121918* m);
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
    u8 _44[0xa4];
    NJS_MOTION* motion;
    u8 _ec[0xa0];
    f32 x18c;
    f32 speed;
} Obj_80125820;
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
    void *xe4;
    void *xe8;
    u8 padec[0x100 - 0xec];
    NJS_TEXLIST *x100;
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
extern Task *lbl_80347454;
extern void fn_8010DEE8(Task *t);
extern Task *fn_801C6180(Task *parent, void (*func)(Task *));
extern s32 lbl_80347504;
extern s32 lbl_8034743C;
extern f32 lbl_8034742C;
extern f32 fn_8010EB88(EvObj *o);
void fn_8011753C(EvObj *c);
void fn_801165C4(EvObj *self);
extern f32 lbl_80347438;
extern f32 lbl_80347420;
extern f32 fn_8011660C(EvObj *o, NJS_POINT3 *t);
extern void fn_80116898(NJS_POINT3 *in, NJS_POINT3 *out);
extern s32 MemEqual(const void *a, const void *b, s32 size);
extern f32 lbl_80347430;

/* 1 while the player's input is locked (event, camera or menu). */
static inline s32 PlayerBusy(void)
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
extern s32 lbl_803474F4;
extern s32 lbl_80347578;
extern f32 fn_801D72A0(s32 a, s32 b);
typedef struct Rec_8011B448 {
    u8 pad0[0x24];
    void *x24;
} Rec_8011B448;
typedef struct HdrSub {
    f32 x0;
    s32 x4;
    u32 x8;
    u32 xc;
    u32 x10;
    s32 x14;
    s32 x18;
} HdrSub;
typedef struct Hdr {
    u32 n;
    u8 pad4[0x20];
    u32 w24;
    u32 x28;
    f32 x2c[3];
    HdrSub x38;
    u32 x54;
    u32 x58;
    u32 x5c;
    u32 x60;
    u32 x64;
    u32 x68;
    u32 x6c;
    u32 x70;
    u32 x74;
    u32 x78;
    u32 x7c;
    f32 x80;
    f32 x84;
    f32 x88;
    s32 x8c;
    u32 x90;
    f32 x94;
    u32 x98;
    f32 x9c;
    f32 xa0;
    u32 xa4;
    u32 xa8;
    u32 xac;
    u32 xb0;
    s32 xb4;
    s32 xb8;
    u32 xbc;
    s32 xc0;
    s32 xc4;
    s32 xc8;
    s32 xcc;
    f32 xd0;
    u32 xd4;
    u32 xd8;
    u32 xdc;
    u32 xe0;
    u32 xe4;
    u32 xe8;
    u32 xec;
    f32 xf0;
} Hdr;
typedef struct TexC { u8 pad0[0xc]; void **xc; } TexC;
typedef struct TexB { u8 pad0[8]; TexC *x8; } TexB;
typedef struct TexA { TexB *x0; } TexA;
typedef struct Cfg_8011DD9C { u8 pad0[0x10]; Hdr *hdr; u8 pad14[0xc]; TexA *x20; } Cfg_8011DD9C;
typedef struct Work_8011B448 {
    u8 pad0[0x1c8];
    Cfg_8011DD9C *cfg;
    u8 pad1cc[0x1d8 - 0x1cc];
    Sub2_8011C858 *x1d8;
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
extern s32 fn_8011B298(Work_8011B448 *work, struct Out_8011B624 *rec);
typedef struct Rec_8011CC74 {
    s32 x0;
    s32 x4;
} Rec_8011CC74;
typedef struct Spawn_8011CC74 {
    u8 pad0[0x24];
    Rec_8011CC74 *x24;
    void *x28;
    Task_8011C858 *x2c;
} Spawn_8011CC74;
typedef struct Work_8011CC74 {
    u8 pad0[0x1c8];
    Sub_8011C858 *x1c8;
    u8 pad1cc[0x1d8 - 0x1cc];
    Sub2_8011C858 *x1d8;
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
    s8 f5;
    u8 _06[4];
    s16 h0a;
    s16 h0c;
    s16 h0e;
    s8 b10;
    s8 b11;
    u8 _12[5];
    s8 b17;
    u8 b18;
    u8 _19[7];
    s16 h20;
    u8 _22[2];
    s32 f24;
    u8 _28[0xa];
    s16 h32;
    u8 _34[4];
    f32 pos[3];
    u8 _44[0x28];
    FormTbl tab;
    u8 _134[4];
    s32 w138;
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
extern u8 lbl_80305E18[];
extern void fn_80222964(void *p);
extern EvColl *fn_80222224(void *p);
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
    NJS_POINT3 pos;
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
    NJS_POINT3 v54;
} In_80124634;
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
    Own_80124634* own;
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
typedef struct Obj_801276E8 {
    u8 _00[0xe8];
    Cur_80126118* fe8;
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
extern s32 lbl_80347508;
extern s8 fn_8009763C(void);
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
typedef struct { f32 x, y; } Pt2;
typedef struct Sub {
    u32 flags;       /* 0x00 */
    Pt2 x4;          /* 0x04 screen point the quads lean towards */
    s32 xc;          /* 0x0C size at the start of the first run */
    s32 x10;         /* 0x10 size between the runs */
    s32 x14;         /* 0x14 size at the end of the second run */
    u8 col[3][4];    /* 0x18 colours at the start, middle and end */
    s32 x24;         /* 0x24 quads in the first run */
    s32 x28;         /* 0x28 quads in the second run */
    s32 x2c;         /* 0x2C quads to draw */
    f32 x30;         /* 0x30 */
    f32 x34;         /* 0x34 */
    f32 x38;         /* 0x38 */
    f32 x3c;         /* 0x3C size scale (doubled) */
    f32 x40;         /* 0x40 depth of the last quad */
    f32 x44;         /* 0x44 */
    f32 x48;         /* 0x48 */
    Angle x4c;       /* 0x4C rotation */
    f32 x50;         /* 0x50 */
    s16 x54;         /* 0x54 blend source */
    s16 x56;         /* 0x56 blend destination */
    Pt2 x58[4];      /* 0x58 spline control points */
    Pt2 x78;         /* 0x78 spline output */
    void *x80;       /* 0x80 texture; quads use the big vertex format when set */
    u8 pad84[4];
    Big *p88;        /* 0x88 quads */
    Small x8c;       /* 0x8C */
    f32 xcc;
    s32 xd0;
    s32 xd4;
} Sub;
typedef struct C1d8 { u8 pad0[4]; T1d8 *x4; u8 pad8[0x1a0 - 8]; s32 w1a0; } C1d8;
typedef struct B B;
typedef struct Ctx_8011DD9C {
    u8 pad0[0x38];
    NJS_POINT3 pos;  /* 0x38 */
    Angle ax, ay, az;
    u8 pad50[0xb4 - 0x50];
    NJS_POINT3 xb4;  /* 0xB4 offset added to pos */
    u8 padc0[0x17a - 0xc0];
    u16 u17a;
    u8 pad17c[0x1c8 - 0x17c];
    Cfg_8011DD9C *cfg;
    u8 pad1cc[0x1d8 - 0x1cc];
    C1d8 *p1d8;
    s32 x1dc;
    u8 pad1e0[4];
    B *x1e4;
    u8 pad1e8[5];
    s8 x1ed;
    s8 x1ee;
    u8 pad1ef;
    s8 x1f0;
    u8 pad1f1[0x1fa - 0x1f1];
    char b1fa;
    char b1fb;
    u8 pad1fc[0x22c - 0x1fc];
    u16 x22c;
    u16 x22e;
    u8 pad230[0x25c - 0x230];
    Sub *sub;
    u8 pad260[0x26c - 0x260];
    u8 b26c;
} Ctx_8011DD9C;
typedef struct {
    u8 x0[0x10];
    s32 x10;
    s32 x14;
    s32 x18;
} Ent;
struct B {
    u8 pad0[0x10];
    struct { u8 pad[0x24]; Ctx_8011DD9C *x24; } *x10;
    Ent ent[4];
};
struct O {
    u32 flags;
    s32 x4;
    s32 x8;
    s32 v;
    s32 x10;
    u16 x14;
    u16 x16;
    NJS_POINT3 pos;
    Pose_80120C64 x24;
    u8 pad3c[0xc];
    NJS_POINT3 x48;
    Corner_80120C64 *x54;
    View_80120C64 *x58;
    Ctx_8011DD9C *x5c;
    Ent *x60;
    s32 *x64;
    Ctx_8011DD9C *x68;
    Ctx_8011DD9C *x6c;
    struct M_80120A90 *x70;
};
struct O_8012239C {
    u32 flags;
    s32 x4;
    s32 x8;
    s32 v;
    s32 x10;
    NJS_POINT3 pos;
    NJS_POINT3 ox;
    NJS_POINT3 *x2c;
    void *buf;
    u8 pad34[4];
    Pose_80120C64 x38;
    u8 pad50[0x5c - 0x50];
    Corner_80120C64 *x5c;
    View_80120C64 *x60;
    u16 x64;
    u16 x66;
    Ctx_8011DD9C *x68;
    Ctx_8011DD9C *x6c;
    Ctx_8011DD9C *x70;
    Ent *x74;
    s32 *x78;
    struct M_80121918 *owner;
    u8 pad80[4];
};
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
extern Ctx_8011DD9C* fn_8015F180(void);
extern void *lbl_80346720;
extern f32 lbl_80349FF8;
extern void *OSAllocFromHeapClear(void *a, s32 n);
extern void fn_80005AD8(void *a, void *b);
extern s32 fn_8011E72C(Ctx_8011DD9C *c);
extern void fn_8020F154(s32 a, s32 b);
extern s32 fn_8011D958(Ctx_8011DD9C *c, Sub *s, s32 a);
extern f32 fn_8011A8B0(NJS_POINT3 *a, NJS_POINT3 *b);
extern s32 fn_80156A8C(s32 x);
extern void fn_801575C8(void *a, s32 b, f32 c);
extern void fn_80120C64(O *o, Ctx_8011DD9C *p);
typedef struct {
    u32 x0;
    u8 pad4[0x20];
    s32 x24;
    u8 pad28[0x10];
    s32 x38;
    u8 pad3c[0x10];
    f32 x4c, x50, x54, x58;
} Inner_80123A44;
extern s32 lbl_803473AC;
extern void fn_801237EC(EvObj *q);
extern s32 fn_8015F218(EvObj *q);
extern void fn_801231F8(EvObj *q);
extern void fn_801DD3B8(void* a, void* b, void* c);
extern void fn_801DD22C(void* a, void* b, void* c);
NJS_POINT3 lbl_802E4CB0[8] = {
    { -0.5f, 3.0f, -0.5f }, { -0.5f, 3.0f, 0.5f }, { 0.5f, 3.0f, 0.5f }, { 0.5f, 3.0f, -0.5f },
    { -0.5f, 0.0f, -0.5f }, { -0.5f, 0.0f, 0.5f }, { 0.5f, 0.0f, 0.5f }, { 0.5f, 0.0f, -0.5f },
};
NJS_POINT3 lbl_802E4D10 = { -4.0f, 0.0f, -4.0f };
NJS_POINT3 lbl_802E4D1C = { 4.0f, 0.0f, -4.0f };
NJS_POINT3 lbl_802E4D28 = { 0.0f, 0.0f, 4.0f };
const char lbl_802B32E8[] = "Leader Ship Is Nothing %d";
const char lbl_802B3304[] = "sb_enemy";
const char lbl_802B3310[] = "Leader Ship Is Miss Match %s";
extern s32 lbl_80305DB0[3];
extern s32 lbl_80305DBC[3];
extern void fn_8010E5BC(EvObj* o);
typedef struct {
    f32 height;
    u32 flags;
    u8 pad8[0x20 - 8];
} Row_80114950;
typedef struct {
    u8 pad0[0x38];
    NJS_POINT3 pos;
    u8 pad44[0x1bc - 0x44];
    void* x1bc;
} Chr_80114950;
extern int fn_80115A4C(f32* pos, u16* out, EvHit* obj);
extern f32 lbl_80305DF8[8];
/* last 4 (x, z) samples */
extern s32 lbl_80346EA0;
extern f32 lbl_80345878[];
extern void fn_80291C44(NJS_MATRIX m);
extern void fn_80121B24(O_8012239C* o, Ctx_8011DD9C* p);
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
    s32 x0;
    s32 x4;
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
extern Task* lbl_803472A0;
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
    s32 x, y, z;
} Ang3_8010F3A8;
typedef struct {
    u8 pad0[0x20];
    Ang3_8010F3A8* ang;
} Model_8010F924;
typedef struct {
    u8 pad0[0x38];
    NJS_POINT3 pos;
    Ang3_8010F3A8 ang;
    u8 pad50[0x100 - 0x50];
    void* texlist;
    NJS_POINT3 prev;
    u8 pad110[0x1b8 - 0x110];
    void* x1b8;
    Model_8010F924* model;
    u8 pad1c0[0x20c - 0x1c0];
    Ang3_8010F3A8 ang2;
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
    s32 a[21];
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
typedef Item_8011FC10 Elem;
typedef struct Eff_8012048C {
    u32 flags;
    u8 pad4[0x18 - 4];
    s32 x18;
    Elem *elems;
    Ent_8012048C *ents;
    s32 count;
} Eff_8012048C;
extern void fn_8011FFF0(f32 *pos, f32 *v, Elem *el, f32 t, u32 *w);
extern f32 fn_8011A994(int i, int n, int k, s32 k2, f32 t);
extern f32 njScalor(NJS_VECTOR *v);
typedef struct Out_8011B624 {
    u32 flags;
    s32 x4;
    s32 x8;
    s32 xc;
    f32 curve[4];
    f32 x20;
    s16 x24;
    s16 x26;
    f32 x28;
    f32 x2c;
    f32 x30;
    f32 x34;
    VertexTex vtx[4];
} Out_8011B624;
extern f32 lbl_80347F28;
/* The 0x270-byte model object (EvObj in game/evobj.h, which stops at 0x264; the task work is
 * allocated and copied as 0x270 bytes). */
typedef struct Obj_80126354 {
    u8 pad0[0x38];
    NJS_POINT3 pos;     /* 0x38 */
    Angle ang[3];       /* 0x44 */
    u8 pad50[0xE8 - 0x50];
    NJS_MOTION* motion; /* 0xE8 */
    u8 padEC[0x18C - 0xEC];
    f32 x18c;           /* 0x18C */
    u8 pad190[0x270 - 0x190];
} Obj_80126354;
/* The object's world matrix and its pivot matrix. */
typedef struct MtxPair_80126354 {
    NJS_MATRIX m0;
    NJS_MATRIX m1;
} MtxPair_80126354;
extern void fn_80156CC4(void *e, void *out);
extern void fn_801566B4(s32 a, NJS_MATRIX m0, NJS_MATRIX m1);

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

extern f32 fn_801D73F0(s32 a, s32 b);
extern s32 fn_8009761C(s32 a, s32 b);

f32 fn_8010EB88(EvObj* o) {
    f32 speed;
    s32 d;

    o->home.x = o->pos.x;
    o->home.y = o->pos.y;
    o->home.z = o->pos.z;
    speed = fn_801D72A0(0, 10);
    speed = speed / 128.0f * lbl_80347434;
    if (0.0f != speed) {
        d = fn_8009761C(0, 182.04445f * fn_801D73F0(0, 10));
        speed *= 0.8f * ((0x8000 - (0 > d ? -d : d)) / 32768.0f) + 0.2f;
        if (fn_801147E8(o, speed, d / 32) == 0) {
            o->pos.x = o->home.x;
            o->pos.y = o->home.y;
            o->pos.z = o->home.z;
        }
        o->home.x = o->pos.x;
        o->home.y = o->pos.y;
        o->home.z = o->pos.z;
        fn_801DD22C(&o->ang, &o->dir, &o->up);
    }
    return speed;
}

void fn_8010EF00(EvObj *a) {
    f32 t;
    fn_801165C4(a);
    a->speed = a->x164 / 0.7f;
    a->x1a8 = 0.33333334f;
    fn_801189F0(a);
    {
        if (PlayerBusy() == 0) {
            a->x164 = fn_8010EB88(a);
        }
    }
    {
        if (PlayerBusy() == 0) {
        if (MemEqual(&a->pos, &a->home, 0x24) == 1 && 0.0f == a->x164) {
            lbl_8034743C++;
            if (lbl_8034743C >= 5) {
                a->motionId = 0x16;
                a->x172 = 0x10;
                fn_801E7414(1, a);
                lbl_8034743C = 0;
            }
        } else if (a->x164 <= lbl_80347430) {
            a->motionId = 0x17;
            a->x172 = 0;
            fn_801E7414(2, a);
            t = a->x1a0 + a->speed;
            a->x18c = t;
            if (t >= a->motion->nbFrame) {
                a->x18c = a->x18c - a->motion->nbFrame;
            }
        } else if (a->x164 > lbl_8034742C) {
            a->motionId = 0x19;
            a->x172 = 0;
            fn_801E7414(3, a);
            t = a->x1a0 + a->speed;
            a->x18c = t;
            if (t >= a->motion->nbFrame) {
                a->x18c = a->x18c - a->motion->nbFrame;
            }
        }
        }
    }
}

void fn_80110D00(EvObj *a) {
    NJS_POINT3 v;
    f32 t, k;
    v.x = a->home.x;
    v.y = a->home.y;
    v.z = a->home.z;
    fn_801165C4(a);
    a->speed = (a->x164 / 1.1f) * lbl_80347438;
    a->x1a8 = 0.33333334f / lbl_80347438;
    k = lbl_80347420 * (lbl_80311A60[0]->x / 128.0f);
    if (0.0f != k) {
        a->pivot = 1;
        a->pivotAng[2] = 182.04445f * k;
        a->x1e0 = k;
    }
    fn_801189F0(a);
    {
        if (!PlayerBusy()) {
            a->x164 = fn_8011660C(a, &v);
        }
    }
    fn_8011753C(a);
    {
        if (!PlayerBusy()) {
            if (MemEqual(&a->pos, &a->home, 0x24) == 1 && 0.0f == a->x164) {
                lbl_8034743C++;
                if (lbl_8034743C >= 5) {
                    a->motionId = 1;
                    a->x172 = 0;
                    a->pivot = 0;
                    fn_801E7414(1, a);
                    lbl_8034743C = 0;
                }
            } else if (a->x164 <= lbl_8034742C) {
                a->motionId = 3;
                a->x172 = 0;
                a->pivot = 0;
                fn_801E7414(10, a);
                t = a->x1a0 + a->speed;
                a->x18c = t;
                if (t >= a->motion->nbFrame) {
                    a->x18c = a->x18c - a->motion->nbFrame;
                }
            }
        }
    }
}

void fn_80110FBC(EvObj* w) {
    NJS_POINT3 v;
    f32 f;

    v.x = w->home.x;
    v.y = w->home.y;
    v.z = w->home.z;
    fn_801165C4(w);
    w->speed = (w->x164 / 0.7f) * lbl_80347438;
    w->x1a8 = 0.33333334f / lbl_80347438;
    f = w->x1e0;
    if (0.0f != f && w->pivotAng[2] != 0) {
        if (f < 0.0f) {
            f = w->x1e0 += 2.0;
            if (f > 0.0f) {
                w->x1e0 = 0.0f;
            }
        } else {
            f = w->x1e0 -= 2.0;
            if (f < 0.0f) {
                w->x1e0 = 0.0f;
            }
        }
        w->pivotAng[2] = 182.04445f * w->x1e0;
        w->pivot = 1;
    } else {
        w->pivot = 0;
    }
    fn_801189F0(w);
    if (!PlayerBusy()) {
        w->x164 = fn_8011660C(w, &v);
    }
    fn_8011753C(w);
    if (!PlayerBusy()) {
        if (MemEqual(&w->pos, &w->home, 0x24) == 1 && 0.0f == w->x164) {
            if (++lbl_8034743C >= 5) {
                w->motionId = 1;
                w->x172 = 0;
                fn_801E7414(1, w);
                lbl_8034743C = 0;
            }
        } else if (w->x164 <= lbl_80347430) {
            w->motionId = 2;
            w->x172 = 0;
            fn_801E7414(2, w);
            f = w->x1a0 + w->speed;
            w->x18c = f;
            if (f >= w->motion->nbFrame) {
                w->x18c -= w->motion->nbFrame;
            }
        } else if (w->x164 > lbl_8034742C) {
            w->motionId = 4;
            w->x172 = 0;
            fn_801E7414(3, w);
            f = w->x1a0 + w->speed;
            w->x18c = f;
            if (f >= w->motion->nbFrame) {
                w->x18c -= w->motion->nbFrame;
            }
        }
    }
}

void fn_80111318(EvObj *a) {
    NJS_POINT3 v;
    f32 t, cur;
    v.x = a->home.x;
    v.y = a->home.y;
    v.z = a->home.z;
    fn_801165C4(a);
    a->speed = (a->x164 / 0.4f) * lbl_80347438;
    a->x1a8 = 0.33333334f / lbl_80347438;
    cur = a->x1e0;
    if (0.0f != cur && a->pivotAng[2] != 0) {
        if (cur < 0.0f) {
            t = cur;
            t += 2.0;
            a->x1e0 = t;
            if (t > 0.0f) a->x1e0 = 0.0f;
        } else {
            t = cur;
            t -= 2.0;
            a->x1e0 = t;
            if (t < 0.0f) a->x1e0 = 0.0f;
        }
        a->pivotAng[2] = 182.04445f * a->x1e0;
        a->pivot = 1;
    } else {
        a->pivot = 0;
    }
    fn_801189F0(a);
    {
        if (PlayerBusy() == 0) {
            a->x164 = fn_8011660C(a, &v);
        }
    }
    fn_8011753C(a);
    {
        if (PlayerBusy() == 0) {
            if (MemEqual(&a->pos, &a->home, 0x24) == 1 && 0.0f == a->x164) {
                lbl_8034743C++;
                if (lbl_8034743C >= 5) {
                    a->motionId = 1;
                    a->x172 = 0;
                    fn_801E7414(1, a);
                    lbl_8034743C = 0;
                }
            } else if (a->x164 > lbl_80347430) {
                a->motionId = 3;
                a->x172 = 0;
                fn_801E7414(10, a);
                t = a->x1a0 + a->speed;
                a->x18c = t;
                if (t >= a->motion->nbFrame) {
                    a->x18c = a->x18c - a->motion->nbFrame;
                }
            }
        }
    }
}

/* One 0x30-byte entry of fn_8020F3D4's list. */
typedef struct Ent_8020F3D4 {
    NJS_POINT3 pos;     /* 0x00 */
    u8 pad0c[0x18 - 0xc];
    f32 f18;            /* 0x18 */
    s32 w1c;            /* 0x1C */
    s32 w20;            /* 0x20 */
    f32 f24;            /* 0x24 */
    s32 w28;            /* 0x28 */
    s32 w2c;            /* 0x2C */
} Ent_8020F3D4;

extern void fn_80097350(s32 x);
extern s32 fn_8020F3D4(s32 id, s32 n, Ent_8020F3D4 *e, ...);
extern void fn_8020F998(s32 a, NJS_POINT3 *v, s32 b, s32 c, s32 d, s32 e);
extern void fn_8020F934(s32 a);

void fn_80111FC4(EvObj *o) {
    Xf d;
    Ent_8020F3D4 req;
    u8 save[0x24];
    NJS_POINT3 v8;
    o->speed = 1.0f;
    if (o->x172 == 0 || o->x172 == 1) {
        fn_801189F0(o);
    } else {
        MemCopy(save, &o->pos, 0x24);
        MemCopy(&o->pos, &o->home, 0x24);
        fn_80118AA4(o);
        fn_80119744(&d, o, o->motion, o->x18c);
        fn_80118948(o);
        lbl_80347404 = 1;
        MemCopy(&o->pos, save, 0x24);
    }
    switch (o->x172) {
    case 0:
        fn_80097350(0);
        req.pos.x = lbl_8034741C->pos[0];
        req.pos.y = o->pos.y;
        req.pos.z = lbl_8034741C->pos[2];
        req.f18 = 0.7f;
        req.w1c = 2;
        req.w20 = 0x7fffffff;
        req.f24 = 1.0f;
        req.w28 = o->hit->key.id;
        req.w2c = 1;
        fn_8020F3D4(0xffff, 1, &req);
        v8.x = 0.0f;
        v8.y = 0.005493164f * (lbl_8034741C->ang[1] & 0xffff);
        v8.z = 0.0f;
        fn_8020F998(0xffff, &v8, 10, 2, 0x7fffffff, 200);
        fn_8020F934(0xffff);
        o->x172 = 1;
        break;
    case 1:
        o->home.x = o->pos.x;
        o->home.y = o->pos.y;
        o->home.z = o->pos.z;
        o->tgt[0] = o->ang[0];
        o->tgt[1] = o->ang[1];
        o->tgt[2] = o->ang[2];
        fn_801E7414(0x28, o);
        o->x172 = 5;
        break;
    case 5:
        if (o->x19c == 1) o->x172 = 0x10;
        break;
    case 0x10:
        o->pos.x = o->home.x + d.pos.x;
        o->pos.y = o->home.y + d.pos.y;
        o->pos.z = o->home.z + d.pos.z;
        o->ang[0] = o->tgt[0] + d.ang[0];
        o->ang[1] = o->tgt[1] + d.ang[1];
        o->ang[2] = o->tgt[2] + d.ang[2];
        o->motionId = 0x10;
        o->x172 = 0;
        break;
    }
}

s32 fn_8011226C(EvObj *o, NJS_MOTION *a) {
    Xf save1;
    Xf save2;
    Xf d;
    NJS_MATRIX m;
    NJS_POINT3 v;
    f32 i;
    s32 r;
    EvInfoMap *inf;
    EvObj *owner;
    s32 n;
    MemCopy(&save1, &o->pos, 0x24);
    if (o->pivot == 1) {
        njUnitMatrix(m);
        njTranslate(m, o->pos.x, o->pos.y, o->pos.z);
        njRotateXYZ(m, o->ang[0], o->ang[1], o->ang[2]);
        njTranslate(m, o->pivotPos.x, o->pivotPos.y, o->pivotPos.z);
        njRotateXYZ(m, o->pivotAng[0], o->pivotAng[1], o->pivotAng[2]);
        v.x = 0.0f;
        v.y = 0.0f;
        v.z = 0.0f;
        njCalcPoint(m, &v, &o->pos);
    }
    MemCopy(&save2, &o->pos, 0x24);
    for (i = 0.0f; i < (f32)a->nbFrame; i += 1.0f) {
        fn_80119744(&d, o, a, i);
        o->pos.x = save2.pos.x + d.pos.x;
        o->pos.y = save2.pos.y + d.pos.y;
        o->pos.z = save2.pos.z + d.pos.z;
        o->ang[0] = save2.ang[0] + d.ang[0];
        o->ang[1] = save2.ang[1] + d.ang[1];
        o->ang[2] = save2.ang[2] + d.ang[2];
    }
    owner = lbl_80347418->p4;
    n = (inf = owner->ext->info)->count > 8 ? inf->nearDist : 0;
    fn_802256A0(&o->pos.x, o->hit, 0xFFFF, n & 0xFFFF);
    r = fn_80116B84(3, &o->pos, lbl_8030A35C, o->hit) == 0;
    MemCopy(&o->pos, &save1, 0x24);
    return r;
}

extern Ent_8020F3D4 lbl_80305DC8;
void fn_80113084(EvObj* o) {
    Xf d;
    Xf q;
    u8 save[0x24];
    NJS_POINT3 v;
    NJS_POINT3 w;
    NJS_POINT3 up;
    f32 dist0;
    f32 dist1;
    f32 s;

    o->speed = 1.0f;
    if (o->x172 == 0 || o->x172 == 1) {
        fn_801189F0(o);
    } else {
        MemCopy(save, &o->pos, 0x24);
        MemCopy(&o->pos, &o->home, 0x24);
        fn_80118AA4(o);
        fn_80119744(&d, o, o->motion, o->x18c);
        fn_80118948(o);
        lbl_80347404 = 1;
        MemCopy(&o->pos, save, 0x24);
    }
    switch (o->x172) {
    case 0:
        o->x1ec = 0;
        fn_80097350(0);
        v.x = o->pos.x - lbl_8034741C->pos[0];
        v.y = 0.0f;
        v.z = o->pos.z - lbl_8034741C->pos[2];
        njUnitVector(&v);
        w.x = lbl_8034741C->pos[0];
        w.y = o->pos.y;
        w.z = lbl_8034741C->pos[2];
        dist0 = fn_80290008(&o->pos.x, &w.x);
        if (lbl_8034741C->id12 == 0x22) {
            s = 4.0f;
        } else {
            s = 12.0f;
        }
        q.pos.x = v.x * s + lbl_8034741C->pos[0];
        q.pos.y = o->pos.y;
        q.pos.z = v.z * s + lbl_8034741C->pos[2];
        dist1 = fn_80290008(&q.pos.x, &w.x);
        lbl_80305DC8.pos.x = q.pos.x;
        lbl_80305DC8.pos.y = o->pos.y;
        lbl_80305DC8.pos.z = q.pos.z;
        lbl_80305DC8.f18 = 0.7f;
        lbl_80305DC8.w1c = 2;
        lbl_80305DC8.w20 = 0x7FFFFFFF;
        lbl_80305DC8.f24 = 1.0f;
        lbl_80305DC8.w28 = o->hit->key.id;
        lbl_80305DC8.w2c = 1;
        fn_8020F3D4(0xFFFF, 1, &lbl_80305DC8);
        if (dist1 >= dist0) {
            up.x = 0.0f;
            up.y = 90.0f - 0.005493164f * (f32)fn_8022BD30(lbl_8034741C->pos, &q.pos.x);
            up.z = 0.0f;
            fn_8020F998(0xFFFF, &up, 5, 2, 0x7FFFFFFF, 200);
        }
        fn_8020F934(0xFFFF);
        o->x172 = 1;
        break;
    case 1:
        o->home.x = o->pos.x;
        o->home.y = o->pos.y;
        o->home.z = o->pos.z;
        o->tgt[0] = o->ang[0];
        o->tgt[1] = o->ang[1];
        o->tgt[2] = o->ang[2];
        if (lbl_8034741C->id12 == 0x22) {
            fn_801E7414(0x24, o);
        } else {
            fn_801E7414(0x21, o);
        }
        o->x172 = 5;
        break;
    case 5:
        if (o->x19c == 1) {
            o->x172 = 0x10;
        }
        break;
    case 0x10:
        o->pos.x = o->home.x + d.pos.x;
        o->pos.y = o->home.y + d.pos.y;
        o->pos.z = o->home.z + d.pos.z;
        o->ang[0] = o->tgt[0] + d.ang[0];
        o->ang[1] = o->tgt[1] + d.ang[1];
        o->ang[2] = o->tgt[2] + d.ang[2];
        if (o->x198 == 1) {
            fn_801E7414(0x1E, o);
            o->x18c = o->speed;
            o->x19c = 1;
            if (lbl_8034741C->id12 == 0x22) {
                o->motionId = 0xB;
            } else {
                o->motionId = 0xC;
            }
            o->x172 = 0;
            o->home.x = o->pos.x;
            o->home.y = o->pos.y;
            o->home.z = o->pos.z;
            o->tgt[0] = o->ang[0];
            o->tgt[1] = o->ang[1];
            o->tgt[2] = o->ang[2];
            v.x = lbl_8034741C->pos[0] - o->pos.x;
            v.y = 0.0f;
            v.z = lbl_8034741C->pos[2] - o->pos.z;
            o->pivotPos.z = -njUnitVector(&v);
            o->pivotPos.x = 0.0f;
            o->pivotPos.y = 0.0f;
            o->pivotAng[0] = 0;
            o->pivotAng[1] = 0;
            o->pivotAng[2] = 0;
            o->pivot = 1;
            o->pos.x = lbl_8034741C->pos[0];
            o->pos.z = lbl_8034741C->pos[2];
            o->home.x = o->pos.x;
            o->home.y = o->pos.y;
            o->home.z = o->pos.z;
            o->tgt[0] = o->ang[0];
            o->tgt[1] = o->ang[1];
            o->tgt[2] = o->ang[2];
        }
        break;
    }
}

void fn_80113630(EvObj *o) {
    EvObj *owner;
    Xf d;
    u8 save[0x24];
    EvInfoMap *inf;
    s32 n;
    s32 k;
    ItemList *l;
    o->speed = 1.0f;
    MemCopy(save, &o->pos, 0x24);
    MemCopy(&o->pos, &o->home, 0x24);
    fn_80118AA4(o);
    fn_80119744(&d, o, o->motion, o->x18c);
    fn_80118948(o);
    lbl_80347404 = 1;
    MemCopy(&o->pos, save, 0x24);
    switch (o->x172) {
    case 0:
        if (o->x198 == 1) {
            o->pos.x = o->home.x + d.pos.x;
            o->pos.y = o->home.y + d.pos.y;
            o->pos.z = o->home.z + d.pos.z;
            o->ang[0] = o->tgt[0] + d.ang[0];
            o->ang[1] = o->tgt[1] + d.ang[1];
            o->ang[2] = o->tgt[2] + d.ang[2];
            o->home.x = o->pos.x;
            o->home.y = o->pos.y;
            o->home.z = o->pos.z;
            o->tgt[0] = o->ang[0];
            o->tgt[1] = o->ang[1];
            o->tgt[2] = o->ang[2];
            o->x1a0 = o->x18c;
            o->x18c = 0.0f;
            o->x1a4 = 0.0f;
            o->x198 = 0;
            o->x19c = 1;
            o->motion2 = o->motion;
            l = o->ext->items;
            k = lbl_80347418->id12;
            o->motion = l->count > k + 10 ? l->items[k + 10] : 0;
            o->x172 = 0x10;
        }
        break;
    case 1:
        if (o->x19c == 1) o->x172 = 0x10;
        break;
    case 0x10:
        o->pos.x = o->home.x + d.pos.x;
        o->pos.y = o->home.y + d.pos.y;
        o->pos.z = o->home.z + d.pos.z;
        o->ang[0] = o->tgt[0] + d.ang[0];
        o->ang[1] = o->tgt[1] + d.ang[1];
        o->ang[2] = o->tgt[2] + d.ang[2];
        if (o->x198 == 1) {
            fn_801E7414(1, o);
            o->x19c = 1;
            o->home.x = o->pos.x;
            o->home.y = o->pos.y;
            o->home.z = o->pos.z;
            o->tgt[0] = o->ang[0];
            o->tgt[1] = o->ang[1];
            o->tgt[2] = o->ang[2];
            o->ang[0] = 0;
            o->ang[2] = 0;
            o->x172 = 0x20;
        } else {
            break;
        }
    case 0x20:
        owner = o->slots->x10->p4;
        n = (inf = owner->ext->info)->count > 8 ? inf->nearDist : 0;
        if (fn_802256A0(&o->pos.x, o->hit, 0xFFFF, n & 0xFFFF) == 1) {
            o->motionId = 1;
            o->x172 = 0;
        }
        fn_80097350(1);
        break;
    }
}

void fn_80113AF0(EvObj *o) {
    Xf d;
    u8 save[0x24];
    o->speed = lbl_80347424;
    MemCopy(save, &o->pos, 0x24);
    MemCopy(&o->pos, &o->home, 0x24);
    fn_80118AA4(o);
    fn_80119744(&d, o, o->motion, o->x18c);
    fn_80118948(o);
    lbl_80347404 = 1;
    MemCopy(&o->pos, save, 0x24);
    d.pos.x = 0.0f;
    d.pos.z = 0.0f;
    o->pos.x = o->home.x + d.pos.x;
    o->pos.y = o->home.y + d.pos.y;
    o->pos.z = o->home.z + d.pos.z;
    o->ang[0] = o->tgt[0] + d.ang[0];
    o->ang[1] = o->tgt[1] + d.ang[1];
    o->ang[2] = o->tgt[2] + d.ang[2];
    switch (o->x172) {
    case 0:
        if (lbl_8034741C->id12 == 0xe) {
            o->x172 = 1;
        } else {
            o->x172 = 2;
        }
        break;
    case 1:
        if (lbl_80311A60[0]->y < 0) {
            fn_801E7414(0x1b, o);
            SePlay(0xf, 5, 0x1b);
            o->x172 = 0x10;
        } else if (lbl_80311A60[0]->y > 0x40) {
            lbl_80346E68 = 1;
            lbl_80310B3C[0x88 / 4] &= ~1;
            o->x198 = 1;
            o->x19c = 0;
            o->x19c = 1;
            o->motionId = 8;
            o->x172 = 0;
        }
        break;
    case 2:
        if (lbl_80311A60[0]->y > 0) {
            fn_801E7414(0x1c, o);
            SePlay(0xf, 5, 0x1b);
            o->x172 = 0x10;
        } else if (lbl_80311A60[0]->y < -0x40) {
            lbl_80346E68 = 1;
            lbl_80310B3C[0x88 / 4] &= ~1;
            o->x198 = 1;
            o->x19c = 0;
            o->x19c = 1;
            o->motionId = 8;
            o->x172 = 0;
        }
        break;
    case 0x10:
        if (o->x198 == 1) {
            o->home.x = o->pos.x;
            o->home.y = o->pos.y;
            o->home.z = o->pos.z;
            o->tgt[0] = o->ang[0];
            o->tgt[1] = o->ang[1];
            o->tgt[2] = o->ang[2];
            if (lbl_80311A60[0]->y == 0) {
                fn_801E7414(0x1d, o);
                o->motionId = 8;
                o->x172 = 0;
            } else if (lbl_80311A60[0]->y > 0) {
                SePlay(0xf, 5, 0x1b);
                fn_801E7414(0x1c, o);
                o->x18c = lbl_80347424;
                o->motionId = 7;
                o->x172 = 0;
            } else {
                SePlay(0xf, 5, 0x1b);
                fn_801E7414(0x1b, o);
                o->x18c = lbl_80347424;
                o->motionId = 7;
                o->x172 = 0;
            }
        }
        break;
    }
}

void fn_80113E28(EvObj *o) {
    Xf d;
    Ent_8020F3D4 req;
    u8 save[0x24];
    NJS_POINT3 v8;
    o->speed = 1.0f;
    lbl_80346E68 = 0;
    if (o->x172 == 0 || o->x172 == 1) {
        fn_801189F0(o);
    } else {
        MemCopy(save, &o->pos, 0x24);
        MemCopy(&o->pos, &o->home, 0x24);
        fn_80118AA4(o);
        fn_80119744(&d, o, o->motion, o->x18c);
        fn_80118948(o);
        lbl_80347404 = 1;
        MemCopy(&o->pos, save, 0x24);
    }
    switch (o->x172) {
    case 0:
        fn_80097350(0);
        req.pos.x = lbl_8034741C->pos[0];
        req.pos.y = o->pos.y;
        req.pos.z = lbl_8034741C->pos[2];
        req.f18 = 0.7f;
        req.w1c = 2;
        req.w20 = 0x7fffffff;
        req.f24 = 1.0f;
        req.w28 = o->hit->key.id;
        req.w2c = 1;
        fn_8020F3D4(0xffff, 1, &req);
        v8.x = 0.0f;
        v8.y = 0.005493164f * (lbl_8034741C->ang[1] & 0xFFFF);
        v8.z = 0.0f;
        fn_8020F998(0xffff, &v8, 0, 2, 0x7fffffff, 200);
        fn_8020F934(0xffff);
        o->x172 = 1;
        break;
    case 1:
        fn_801E7414(lbl_8034741C->id12 + 7, o);
        o->home.x = o->pos.x;
        o->home.y = o->pos.y;
        o->home.z = o->pos.z;
        o->tgt[0] = o->ang[0];
        o->tgt[1] = o->ang[1];
        o->tgt[2] = o->ang[2];
        o->x172 = 5;
        break;
    case 5:
        if (o->x19c == 1) o->x172 = 0x10;
        break;
    case 0x10:
        o->pos.x = o->home.x + d.pos.x;
        o->pos.y = o->home.y + d.pos.y;
        o->pos.z = o->home.z + d.pos.z;
        o->ang[0] = o->tgt[0] + d.ang[0];
        o->ang[1] = o->tgt[1] + d.ang[1];
        o->ang[2] = o->tgt[2] + d.ang[2];
        if (o->x198 == 1) {
            fn_801E7414(0x1d, o);
            o->x18c = o->speed;
            o->x19c = 1;
            o->motionId = 9;
            o->x172 = 0;
            o->home.x = o->pos.x;
            o->home.y = o->pos.y;
            o->home.z = o->pos.z;
            o->tgt[0] = o->ang[0];
            o->tgt[1] = o->ang[1];
            o->tgt[2] = o->ang[2];
        }
        break;
    }
}

extern s32 fn_802249CC(NJS_POINT3* out, NJS_POINT3* a, NJS_POINT3* b, EvHit* h);

s32 fn_80114138(EvObj *o, s32 yaw, Angle *ang) {
    NJS_POINT3 start;
    NJS_POINT3 end;
    NJS_POINT3 hitp;
    NJS_POINT3 d;
    EvHit h;
    s32 n;
    f32 sx, sy, sz;

    fn_801DCF24(&d, ang, yaw - 0x4000, 4.0f);
    sx = 4.0f * o->up.x;
    sy = 4.0f * o->up.y;
    sz = 4.0f * o->up.z;
    n = 0;
    start.x = o->pos.x + sx;
    start.y = o->pos.y + sy;
    start.z = o->pos.z + sz;
    end.x = start.x + d.x;
    end.y = start.y + d.y;
    end.z = start.z + d.z;
    h.key = o->hit->key;
    h.x2c = o->hit->x2c;
    h.x2e = o->hit->x2e;
    h.x30 = o->hit->x30;
    if (fn_802249CC(&hitp, &start, &end, &h) != 0 && (h.h24 & 0x4800) == 0x4800) {
        n = 1;
        o->pos.x = o->pos.x + (hitp.x - end.x);
        o->pos.y = o->pos.y + (hitp.y - end.y);
        o->pos.z = o->pos.z + (hitp.z - end.z);
        start.x = o->pos.x + sx;
        start.y = o->pos.y + sy;
        start.z = o->pos.z + sz;
    }
    end.x = start.x - d.x;
    end.y = start.y - d.y;
    end.z = start.z - d.z;
    h.key = o->hit->key;
    h.x2c = o->hit->x2c;
    h.x2e = o->hit->x2e;
    h.x30 = o->hit->x30;
    if (fn_802249CC(&hitp, &start, &end, &h) != 0 && (h.h24 & 0x4800) == 0x4800) {
        n++;
        o->pos.x = o->pos.x + (hitp.x - end.x);
        o->pos.y = o->pos.y + (hitp.y - end.y);
        o->pos.z = o->pos.z + (hitp.z - end.z);
        start.x = o->pos.x + sx;
        start.y = o->pos.y + sy;
        start.z = o->pos.z + sz;
    }
    end.x = 6.0f * o->dir.x + start.x;
    end.y = 6.0f * o->dir.y + start.y;
    end.z = 6.0f * o->dir.z + start.z;
    h.key = o->hit->key;
    h.x2c = o->hit->x2c;
    h.x2e = o->hit->x2e;
    h.x30 = o->hit->x30;
    if (fn_802249CC(&hitp, &start, &end, &h) != 0 && (h.h24 & 0x4800) == 0x4800) {
        n++;
        o->pos.x = o->pos.x + (hitp.x - end.x);
        o->pos.y = o->pos.y + (hitp.y - end.y);
        o->pos.z = o->pos.z + (hitp.z - end.z);
    }
    return n != 0;
}



s32 fn_801144A4(EvObj *o, s32 yaw, Angle *ang) {
    NJS_POINT3 hit[3];
    NJS_POINT3 off[3];
    EvHit q;
    NJS_POINT3 v14, v8;
    f32 a0;
    f32 a1;
    f32 a2;
    f32 b0;
    f32 b1;
    f32 b2;
    fn_801DCF24(&off[0], ang, yaw + 0x2aaa, 6.0f);
    fn_801DCF24(&off[1], ang, yaw - 0x2aaa, 6.0f);
    fn_801DCF24(&off[2], ang, yaw + 0x8000, 6.0f);
    a0 = 4.0f * o->up.x;
    a1 = 4.0f * o->up.y;
    a2 = 4.0f * o->up.z;
    b0 = 8.0f * o->up.x;
    b1 = 8.0f * o->up.y;
    b2 = 8.0f * o->up.z;
    v14.x = a0 + (o->pos.x + off[0].x);
    v14.y = a1 + (o->pos.y + off[0].y);
    v14.z = a2 + (o->pos.z + off[0].z);
    v8.x = v14.x - b0;
    v8.y = v14.y - b1;
    v8.z = v14.z - b2;
    q.key = o->hit->key;
    q.x2c = o->hit->x2c;
    q.x2e = o->hit->x2e;
    q.x30 = o->hit->x30;
    if (fn_80224D08(&hit[0], &v14, &v8, &q) != 0) {
        v14.x = a0 + (o->pos.x + off[1].x);
        v14.y = a1 + (o->pos.y + off[1].y);
        v14.z = a2 + (o->pos.z + off[1].z);
        v8.x = v14.x - b0;
        v8.y = v14.y - b1;
        v8.z = v14.z - b2;
        q.key = o->hit->key;
        q.x2c = o->hit->x2c;
        q.x2e = o->hit->x2e;
        q.x30 = o->hit->x30;
        if (fn_80224D08(&hit[1], &v14, &v8, &q) != 0) {
            v14.x = a0 + (o->pos.x + off[2].x);
            v14.y = a1 + (o->pos.y + off[2].y);
            v14.z = a2 + (o->pos.z + off[2].z);
            v8.x = v14.x - b0;
            v8.y = v14.y - b1;
            v8.z = v14.z - b2;
            q.key = o->hit->key;
            q.x2c = o->hit->x2c;
            q.x2e = o->hit->x2e;
            q.x30 = o->hit->x30;
            if (fn_80224D08(&hit[2], &v14, &v8, &q) != 0) {
                fn_80290668(&hit[0], &hit[1], &hit[2], &o->up);
                njUnitVector(&o->up);
                v14.x = o->pos.x + a0;
                v14.y = o->pos.y + a1;
                v14.z = o->pos.z + a2;
                v8.x = v14.x - b0;
                v8.y = v14.y - b1;
                v8.z = v14.z - b2;
                return fn_80224D08(&o->pos, &v14, &v8, o->hit);
            }
        }
    }
    return 0;
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
    return lbl_802E54B0[fn_801161B4()].f2c;
}

extern u32 lbl_80347400;
extern void *lbl_803473FC;       /* the player's own model while another character stands in */
extern ItemList *lbl_80346E98;
extern void *lbl_80346E94;
extern EvColl *lbl_80346E90;
extern NJS_TEXLIST *lbl_80346E8C;
extern u32 lbl_80346E88;
extern s32 lbl_80346E9C;
extern f32 lbl_80347428;
void fn_8011605C(int idx);
void fn_80119E50(Owner_80119E50 *o, Chr_80119E50 *src);

extern void* fn_801E1A74(s32 size, s32 n);
typedef struct Sub_80123F30 {
    s32 count;
    u8 _04[0x38];
    u32 f3c;
} Sub_80123F30;
typedef struct Cfg_80123F30 {
    u8 _00[0x10];
    Sub_80123F30* sub;
} Cfg_80123F30;
typedef struct Ent_80123F30 {
    u8 _00[0xb0];
} Ent_80123F30;
typedef struct Buf_80123F30 {
    s32 f0;
    Ent_80123F30* f4;
} Buf_80123F30;
typedef struct Foe_80123F30 {
    u8 _00[0x24];
    struct {
        u8 _00[0x1c8];
        char* name;
        u8 _1cc[0x70];
        Ent_80123F30* f23c;
    }* data;
} Foe_80123F30;
typedef struct M_80123F30 {
    u8 _00[0xe8];
    u32 fe8;
    u8 _ec[0x14];
    void* f100;
    u8 _104[0x74];
    u16 h178;
    u16 h17a;
    u8 _17c[0x4c];
    Cfg_80123F30* cfg;
    u8 _1cc[0x1c];
    Foe_80123F30* foe;
    u8 _1ec[0x50];
    Buf_80123F30* f23c;
} M_80123F30;
extern void fn_80156B04(void*, void*, s32, s32, void*);
extern void fn_80156E54(void* a, void* b);
extern void fn_80156DA0(void* a, void* b);

void fn_80123F30(Task* t) {
    M_80123F30* m = t->work;
    u8 local[0x3C];

    switch (t->state) {
    case 0:
    case 0xFE:
        fn_80227810(m->f100);
        fn_8015ED90(t);
        t->state = 1;
        break;
    case 1: {
        Sub_80123F30* s = m->cfg->sub;
        Foe_80123F30* foe = fn_801094C8(s->count > 14 ? s->f3c : 0);
        m->foe = foe;
        if (foe == 0) {
            fn_801DBE1C(lbl_802B32E8, m->h17a);
        }
        t->state = 2;
        if (strncmp(m->foe->data->name + 0x24, lbl_802B3304, 8) != 0) {
            fn_801DBE1C(lbl_802B3310, m->foe->data->name + 0x24);
        }
        {
            Buf_80123F30* b = fn_801E1A74(1, 8);
            memset(b, 0, 8);
            m->f23c = b;
            b->f4 = m->foe->data->f23c;
        }
    }
    case 2:
        fn_80156B04(m->f23c->f4 + 1, m, 0, 0, local);
        if (fn_8015E600(t->work) == 0) {
            if (m->fe8 != 0) {
                fn_80156E54(m, local);
            } else {
                fn_80156DA0(m, local);
            }
        }
        break;
    case 0xFF:
        fn_801E17E0(m->f23c);
        fn_8015EBF4(t->work);
        if (m->f100 != 0) {
            fn_802275A4(m->f100, 0);
        }
        fn_80100B74(t);
        break;
    }
}

s32 fn_801161B4(void) {
    s32 n;
    u32 id = lbl_80346E88;
    if (id == 0 || id == 0xc3b4) {
        n = 0;
    } else if (id == 0xc418) {
        n = 1;
    } else if (id == 0xc47c) {
        n = 2;
    } else if (id == 0xc4e0) {
        n = 3;
    } else if (id == 0xc544) {
        n = 4;
    } else {
        n = 0;
    }
    if (n != -1) {
        lbl_80310A1C[0x10] = n;
    }
    return n;
}

void fn_8011622C(s32 v) {
    u16 id;
    Task* t;
    EvObj* w;

    if (lbl_80347400 == 0) return;
    fn_8015EBF4(lbl_80347450);
    if (v != 0x7FFFFFFF && (id = v, id != lbl_80347450->x17a)) {
        if (lbl_803473FC != 0) {
            fn_801DBE1C("Player Change Error 2 Times !!");
        }
        t = fn_801094C8(id);
        if (t == NULL) {
            fn_801DBE1C("Error !! Can't Search Player Sub Task(plchg)");
        }
        w = t->work;
        lbl_803473FC = lbl_80347450->model;
        lbl_80346E98 = lbl_80347450->ext->items;
        lbl_80346E94 = lbl_80347450->ext->info;
        lbl_80346E90 = lbl_80347450->coll;
        lbl_80346E8C = lbl_80347450->texlist;
        lbl_80346E88 = id;
        lbl_80347450->model = w->model;
        lbl_80347450->ext->items = w->ext->items;
        lbl_80347450->ext->info = w->ext->info;
        lbl_80347450->texlist = w->texlist;
        lbl_80347450->coll = w->coll;
        lbl_80347450->coll->pos = &lbl_80347450->pos.x;
        lbl_80347450->coll->scl = &lbl_80347450->scl.x;
        lbl_80347450->coll->ang = lbl_80347450->ang;
        lbl_80347450->motionId = 1;
        lbl_80347450->x172 = 0;
        lbl_80347450->pivot = 0;
        lbl_80347450->pivotAng[2] = 0;
        fn_801E7414(1, lbl_80347450);
        lbl_80347450->motion2 = lbl_80347450->motion;
        lbl_80347450->x1a0 = lbl_80347450->x18c;
        lbl_80347450->x18c = 0.0f;
        lbl_80347450->x1a4 = 0.0f;
        lbl_80347450->x19c = 1;
        lbl_8034743C = 0;
    } else if (lbl_803473FC != 0) {
        t = fn_801094C8(lbl_80346E88);
        if (t != NULL) {
            w = t->work;
            w->coll = lbl_80347450->coll;
            w->coll->pos = &w->pos.x;
            w->coll->scl = &w->scl.x;
            w->coll->ang = w->ang;
        }
        lbl_80347450->model = lbl_803473FC;
        lbl_80347450->ext->items = lbl_80346E98;
        lbl_80347450->ext->info = lbl_80346E94;
        lbl_80347450->coll = lbl_80346E90;
        lbl_80347450->texlist = lbl_80346E8C;
        lbl_80347450->motionId = 1;
        lbl_80347450->x172 = 0;
        lbl_80347450->pivot = 0;
        lbl_80347450->pivotAng[2] = 0;
        fn_801E7414(1, lbl_80347450);
        lbl_80347450->motion2 = lbl_80347450->motion;
        lbl_80347450->x1a0 = lbl_80347450->x18c;
        lbl_80347450->x18c = 0.0f;
        lbl_80347450->x1a4 = 0.0f;
        lbl_80347450->x19c = 1;
        lbl_8034743C = 0;
        lbl_803473FC = 0;
        lbl_80346E88 = 0;
    }
    lbl_80346E9C = 1;
    lbl_80347400 = 0;
    fn_8011605C(fn_801161B4());
    lbl_80347438 = lbl_802E54B0[fn_801161B4()].fa0;
    lbl_80347434 = lbl_802E54B0[fn_801161B4()].f94;
    lbl_80347428 = lbl_802E54B0[fn_801161B4()].f94;
    lbl_8034742C = lbl_802E54B0[fn_801161B4()].f98;
    lbl_80347430 = lbl_802E54B0[fn_801161B4()].f9c;
    fn_8015ED90(lbl_80347454);
    fn_8015EB8C(lbl_80347450, 0xD, fn_80119E50);
}

void fn_801165BC(s32 v) {
    lbl_80347400 = v;
}

void fn_801165C4(EvObj *self) {
    fn_802238E4(&self->pos, &self->pos, self->hit);
    MemCopy(&self->home, &self->pos, 0x24);
}


f32 fn_8011660C(EvObj *o, NJS_POINT3 *t) {
    NJS_POINT3 v14;
    NJS_POINT3 v8;
    NJS_MATRIX m;
    f32 len, dy, hd, ang;
    s32 s;
    s32 a;
    if (o->x188 == 1) return 0.0f;
    v8.z = lbl_80311A60[0]->y / 128.0f;
    s = lbl_80311A60[0]->x;
    if (lbl_80310B3C[0x84 / 4] & 0x10000000) s = -s;
    v8.x = s / 128.0f;
    v8.y = 0.0f;
    fn_80116898(&v8, &v14);
    v14.x = v14.x * lbl_80347434;
    v14.y = v14.y * lbl_80347434;
    v14.z = v14.z * lbl_80347434;
    len = njScalor(&v14);
    dy = t->y - o->pos.y;
    if (dy < 0.0f) {
        dy *= 2.0f;
    } else {
        dy *= 1.2f;
    }
    v8.x = t->x - o->pos.x;
    v8.y = 0.0f;
    v8.z = t->z - o->pos.z;
    hd = njScalor(&v8);
    ang = atan2(dy, hd);
    njUnitMatrix(m);
    a = 10430.381f * ang;
    njRotateXYZ(m, -a, lbl_80311970.ang[1], 0);
    njCalcPoint(m, &v14, &v8);
    o->pos.x = o->pos.x + v8.x;
    o->pos.y = o->pos.y + v8.y;
    o->pos.z = o->pos.z + v8.z;
    o->vel.x = v8.x;
    o->vel.y = v8.y;
    o->vel.z = v8.z;
    if (MemEqual(&o->pos, &o->home, 0x24) != 1) {
        o->pos.x = -o->pos.x;
        o->home.x = -o->home.x;
        o->ang[1] = fn_8022BD30(&o->home.x, &o->pos.x) + 0x4000;
        o->pos.x = -o->pos.x;
        o->home.x = -o->home.x;
    }
    return len;
}

s32 fn_8011698C(NJS_POINT3 *a, EvHit *obj) {
    s32 r = fn_802254A0(a, obj);
    if (r == 1 && (obj->h24 & 0x4800) == 0x4800) {
        r = 0;
    }
    return r;
}

extern s32 lbl_80347464;

s32 fn_8011768C(void) {
    s32 r;
    u16 m;

    if (lbl_80347464 == 1 || lbl_80311AC0.id >= 500) {
        return 0;
    }
    r = -1;
    if (lbl_80347450 != NULL) {
        m = lbl_80347450->motionId;
        if ((m >= 1 && m <= 4) || (m >= 22 && m <= 25)) {
            r = 0;
        } else if (m >= 5 && m <= 9) {
            r = 1;
        } else if (m >= 10 && m <= 14) {
            r = 2;
        } else if (m >= 15 && m <= 20) {
            r = 3;
        } else if (m == 21) {
            r = 4;
        }
    }
    return r;
}

s32 fn_801177A4(EvObj *obj, EvColl *ev);
s32 fn_801179B8(EvObj *obj, EvColl *ev);
extern s32 lbl_802E4F30[8];
extern EvColl* lbl_80346EA4;
extern EvColl* lbl_8034744C;
extern s32 lbl_80347408;
extern s32 fn_8021067C(u32 id);
extern void fn_80210550(u32 id);

static inline s32 Test(EvColl* e, u32 lo, u32 hi) {
    s32 found;
    s32 i;
    found = 0;
    for (i = 0; i < 8; i++) {
        if (e->id12 == lbl_802E4F30[i]) {
            lbl_80346EA4 = e;
            found = 1;
            break;
        }
    }
    if (found == 1 || (e->w8 >= lo && e->w8 <= hi && fn_8021067C(e->w8) == 1)) {
        return 1;
    }
    return 0;
}

s32 fn_80117BE4(s32 which, EvObj* self, EvColl* list) {
    extern EvColl* fn_8022300C(EvColl* l);
    extern EvColl* fn_80222F14(EvColl* l, EvColl* e);
    EvColl* e;
    EvColl* best = 0;
    f32 bestd;
    f32 d;
    s32 ok;

    e = fn_8022300C(list);
    if (e != 0) {
        do {
            if (which == 0) {
                ok = Test(e, 0x1770, 0x1b57);
            } else {
                ok = Test(e, 0xbb8, 0x1387);
            }
            if (ok != 0 && e->w8 != self->ext->x04) {
                d = fn_80290008(&self->pos.x, e->pos);
                if (best == 0 || bestd > d) {
                    best = e;
                    bestd = d;
                }
            }
        } while ((e = fn_80222F14(list, e)) != 0);
        if (best != 0) {
            if (fn_8021067C(best->w8) == 1) {
                fn_80210550(best->w8);
                lbl_80347408 = 1;
                if (which == 1) {
                    lbl_8034744C = best;
                }
            }
            if (which == 0) {
                ok = Test(best, 0x1770, 0x1b57);
                if (ok == 1 && fn_801179B8(self, best) != 1) {
                    return 0;
                }
            } else {
                ok = Test(best, 0xbb8, 0x1387);
                if (ok == 1 && fn_801177A4(self, best) != 1) {
                    return 0;
                }
            }
            if (which == 0) {
                self->slots->a4 = best;
            } else {
                self->slots->ac = best;
            }
        }
        if (which == 0) {
            self->slots->a0 = best;
        } else {
            self->slots->a8 = best;
        }
        return 1;
    }
    if (which == 0) {
        self->slots->a0 = 0;
    } else {
        self->slots->a8 = 0;
    }
    return 0;
}

void fn_80118540(void) {
    f32 big = 3.4028235e38f;
    s32 mx = 0x80000000;
    mx -= 1;
    lbl_8030A380.type = 0;
    lbl_8030A380.id = mx;
    lbl_8030A380.a = big;
    lbl_8030A380.b = big;
    lbl_8030A380.c = big;
    lbl_8030A380.d = big;
    lbl_8030A380.e = big;
    lbl_8030A380.f = big;
}

void fn_80118578(s32 id, f32 f1, f32 f2, f32 f3, f32 f4) {
    lbl_8030A380.type = 1;
    lbl_8030A380.id = id;
    lbl_8030A380.a = f1;
    lbl_8030A380.b = f2;
    lbl_8030A380.c = f3;
    lbl_8030A380.d = lbl_80349E90;
    lbl_8030A380.e = f4;
    lbl_8030A380.f = lbl_80349E90;
}

void fn_801185A8(s32 id, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5, f32 f6) {
    lbl_8030A380.type = 2;
    lbl_8030A380.id = id;
    lbl_8030A380.a = f1;
    lbl_8030A380.b = f2;
    lbl_8030A380.c = f3;
    lbl_8030A380.d = f4;
    lbl_8030A380.e = f5;
    lbl_8030A380.f = f6;
}

extern s32 lbl_80347530;

/* Draws o with lbl_80347530 forced to 1; when lbl_80347444 is set, speed/x1a8 are zeroed for
 * the draw. Everything is restored afterwards. */
void fn_80118948(EvObj *o) {
    s32 old = lbl_80347530;
    f32 a;
    f32 b;
    lbl_80347530 = 1;
    a = o->speed;
    b = o->x1a8;
    if (lbl_80347444 != 0) {
        o->speed = 0.0f;
        o->x1a8 = 0.0f;
    }
    if (o->x19c == 0) {
        fn_801E5148(o);
    } else {
        fn_801E5DF0(o);
    }
    o->speed = a;
    o->x1a8 = b;
    lbl_80347530 = old;
}

void fn_801189F0(EvObj *o)
{
    s32 save;
    f32 b;
    f32 a;

    fn_80118AA4(o);
    save = lbl_80347530;
    lbl_80347530 = 1;
    a = o->speed;
    b = o->x1a8;
    if (lbl_80347444 != 0) {
        o->speed = 0.0f;
        o->x1a8 = 0.0f;
    }
    if (o->x19c == 0) {
        fn_801E5148(o);
    } else {
        fn_801E5DF0(o);
    }
    o->speed = a;
    o->x1a8 = b;
    lbl_80347530 = save;
    lbl_80347404 = 0;
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

extern void fn_8011B6E0(Out_8011B624 *a);

void ScreenWipeDraw(void) {
    Task *task;
    Out_8011B624 *p;

    if (lbl_80346EB4 != 0) {
        if (lbl_80346EB0 != NULL) {
            njColorBlendingMode(0, 8);
            njColorBlendingMode(1, 6);
            task = lbl_80346EB0;
            p = task->work;
            if (p->flags & 0x80000000) {
                fn_80226D14();
                p->flags &= 0x7fffffff;
            }
            if (p->x8-- > 0) {
                if (p->flags & 0x100) {
                    DrawState ds;
                    DrawStateDefault2D(&ds);
                    ds.blend_src = p->x24;
                    ds.blend_dst = p->x26;
                    DrawStatePush(&ds);
                }
                fn_80297DC8((void *)0x1869E);
                fn_80291064(p->vtx, 4, 1);
                if (p->flags & 0x100) {
                    DrawStatePop(NULL);
                }
            } else {
                if (p->flags & 1) {
                    f32 t = (f32)p->x4 / (f32)p->xc;
                    u32 col = p->vtx[0].colour & 0xffffff;
                    u32 alpha;
                    if (p->flags & 0x200) {
                        f32 v;
                        fn_8011B024(p->curve, 4, 3, &v, t);
                        alpha = (u32)(255.0f * (0.01f * (100.0f - v))) << 24;
                    } else {
                        alpha = (u32)(255.0f * (1.0f - t)) << 24;
                    }
                    col |= alpha;
                    p->vtx[3].colour = col;
                    p->vtx[2].colour = col;
                    p->vtx[1].colour = col;
                    p->vtx[0].colour = col;
                }
                if (p->flags & 0x10000) {
                    fn_8011B6E0(p);
                }
                if (p->flags & 0x100) {
                    DrawState ds;
                    DrawStateDefault2D(&ds);
                    ds.blend_src = p->x24;
                    ds.blend_dst = p->x26;
                    DrawStatePush(&ds);
                }
                fn_80297DC8((void *)0x1869E);
                fn_80291064(p->vtx, 4, 1);
                if (p->flags & 0x100) {
                    DrawStatePop(NULL);
                }
                if (p->x4++ >= p->xc) {
                    lbl_80346EB4 = 0;
                    lbl_80346EB0 = NULL;
                    task->flags |= 0x40;
                }
            }
        }
    } else if ((task = lbl_80346EB0) != NULL) {
        lbl_80346EB4 = 0;
        lbl_80346EB0 = NULL;
        task->flags |= 0x40;
    }
}

void fn_8011BAA4(Task *p) {
    lbl_80346EB0 = p;
    if (!(p->flags & 0x20)) {
        return;
    }
    lbl_80346EB4 = 0;
    lbl_80346EB0 = 0;
    p->flags |= 0x40;
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

extern NJS_VECTOR lbl_802E57E8;
extern void fn_8028A8C0(VertexTex *v, s32 count, s32 flag);

extern void *fn_801E1A2C(s32 a, u32 size);
extern void fn_80122778(Task *o);

Task *fn_801228A0(s32 handle, SrcFrame *tbl) {
    int i;
    SprAnim *a;
    Frame *e;
    Task *t;

    if (fn_801D6E38(handle) == 0) {
        return 0;
    }
    t = fn_80226704(lbl_80347588, fn_80122778, 0x28);
    if (t == 0) {
        return 0;
    }
    if ((t->work = fn_801E1A2C(1, 0x98)) == 0) {
        t->flags |= 0x40;
        return 0;
    }
    a = t->work;
    e = a->frames;
    a->handle = handle;
    a->idx = 0;
    a->loops = 0;
    a->timer = 0;
    for (i = 0; i < 31; i++) {
        e->a = tbl->a;
        e->b = tbl->b;
        e->dur = tbl->dur;
        if (e->dur == 0) {
            a->max_loops = e->b;
            a->count = i + 1;
            break;
        }
        e++;
        tbl++;
    }
    if (i >= 31) {
        e[-1].dur = 0;
        a->count = 31;
        a->max_loops = e[-1].b;
    }
    a->b14 = 1;
    a->b15 = 0;
    a->b18 = 0;
    a->b16 = a->frames[0].a;
    a->b17 = a->frames[0].b;
    return t;
}

void fn_80123074(NJS_POINT3 *pts, s32 n, f32 u0, f32 v0, f32 u1, f32 v1) {
    VertexTex v[4];
    NJS_POINT3 w;
    NJS_POINT3 p0;
    NJS_POINT3 p1;
    NJS_POINT3 d;
    NJS_POINT3 side;
    int i;
    NJS_POINT3 *a;
    NJS_POINT3 *b;

    for (i = 3; i >= 0; i--) {
        v[i].colour = -1;
    }
    v[0].u = u0;
    v[0].v = v0;
    v[1].u = u0;
    v[1].v = v1;
    v[2].u = u1;
    v[2].v = v0;
    v[3].u = u1;
    v[3].v = v1;
    njCalcVector(0, &lbl_802E57E8, &w);
    n--;
    do {
        {
            f32 z1, x0, y0, x1, y1, z0;

            x0 = pts[0].x; x1 = pts[1].x;
            y0 = pts[0].y; y1 = pts[1].y;
            z0 = pts[0].z; z1 = pts[1].z;
            pts++;
            p0.z = z0; p0.y = y0; p0.x = x0;
            p1.z = z1; p1.y = y1; p1.x = x1;
            d.z = z1 - z0; d.y = y1 - y0; d.x = x1 - x0;
        }
        njOuterProduct(&w, &d, &side);
        a = &p0;
        b = &p1;
        njUnitVector(&side);
        v[0].x = a->x - side.x;
        v[0].y = a->y + side.y;
        v[0].z = a->z + side.z;
        v[2].x = a->x + side.x;
        v[2].y = a->y - side.y;
        v[2].z = a->z - side.z;
        v[1].x = b->x - side.x;
        v[1].y = b->y + side.y;
        v[1].z = b->z + side.z;
        v[3].x = b->x + side.x;
        v[3].y = b->y - side.y;
        v[3].z = b->z - side.z;
        fn_8028A8C0(v, 4, 1);
    } while (--n > 0);
}

extern s32 lbl_803473C4;
extern s32 fn_800FF438(void);
extern void fn_801CBBAC(f32 f);
extern void fn_801CBB9C(f32 f);
extern void fn_8022DBC8(void);
extern void fn_802171F0(s32 n);
extern void fn_800E3540(void);
extern void SaveLoadOpenSave(void* list, u16 id);
extern void fn_8022697C(s32 n);
extern void fn_80217134(void);

void fn_80123CBC(Task* t) {
    if (t->state > 1) {
        int h = fn_800FF438();
        if (h != -1) {
            s32 r;
            do {
                r = fn_801D6C3C(h);
                if (r == 0) {
                    break;
                }
            } while (r != -2);
        }
    }
    switch (t->state) {
    case 0:
    case 0xFE:
        t->state = 1;
    case 1:
        if (lbl_803473B4 == 1) {
            fn_801CBBAC(3.0f);
            t->state = 2;
        }
        break;
    case 2:
        if (lbl_80347508 != 1) {
            t->state = 3;
        }
        break;
    case 3: {
        s32 a;
        s32 id;
        fn_8022DBC8();
        fn_802171F0(-0x1F);
        fn_800E3540();
        a = lbl_803473B0;
        if (a == 1) {
            id = 0x3C;
        } else {
            u16 t = lbl_80310A1C[0x2C];
            id = t;
        }
        SaveLoadOpenSave(lbl_803475A0, id);
        if (lbl_80311AC0.id != 0x63) {
            fn_8022697C(t->x14);
        }
        t->state = 4;
        break;
    }
    case 4:
        if (lbl_803473C4 == 1) {
            fn_801CBB9C(3.0f);
            t->state = 5;
        }
        fn_8022DBC8();
        break;
    case 5:
        fn_80217134();
        if (lbl_80311AC0.id != 0x63) {
            fn_8022697C(0x7FFFFFFF);
        }
        lbl_803473B4 = 0;
        t->state = 1;
        break;
    case 0xFF:
        t->flags |= 0x40;
        break;
    }
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
        if (lbl_80310A1C[0xc0] == 0) {
            return 2;
        }
    }
    return 0;
}

typedef struct Z_80124108 {
    u8 pad0[0x84];
    u32 x84;
} Z_80124108;
typedef struct W_80124108 {
    Rec_80125820 r0;
    Rec_80125820 a24;
    Rec_80125820 a48;
    f32 a6c;
    NJS_MATRIX m70;
    NJS_MATRIX mb0;
    u8 xf0[0xaf0 - 0xf0];
} W_80124108;
typedef struct Q_80124108 {
    u8 pad0[0x38];
    Rec_80125820 x38;
    u8 pad5c[0xe8 - 0x5c];
    void *xe8;
    u8 padec[0x100 - 0xec];
    void *x100;
    u8 pad104[0x1e4 - 0x104];
    Z_80124108 *x1e4;
    u8 pad1e8[0x23c - 0x1e8];
    W_80124108 *x23c;
} Q_80124108;
extern void fn_80156994(s32 a, void *m, void *b, void *cb);
void fn_80129750(NJS_MATRIX m, Task *o);

void fn_80124108(Task *p) {
    Q_80124108 *q = p->work;
    W_80124108 *w;
    switch (p->state) {
    case 0:
    case 0xfe: {
        fn_80227810(q->x100);
        q->x1e4 = fn_801E1A74(1, 0x88);
        w = fn_801E1A74(1, 0xaf0);
        memset(w, 0, 0xaf0);
        q->x23c = w;
        fn_80156994(1, q, w->xf0, fn_801243C4);
        fn_801566B4(1, w->m70, w->mb0);
        fn_8015ED90(p);
        fn_8015EB8C(q, 1, fn_80124390);
        p->state = 1;
        break;
    }
    case 1: {
        u8 buf[0x270];
        NJS_POINT3 v;
        Q_80124108 *q1 = p->work;
        w = q1->x23c;
        if (fn_8015E600(q1) == 1) {
            njUnitMatrix(w->mb0);
            fn_80129750(w->mb0, p);
            break;
        }
        if (q->x1e4->x84 == 0) break;
        if (q->xe8 != NULL) {
            fn_80156E54(q, w->m70);
        } else {
            fn_80156DA0(q, w->m70);
        }
        fn_8014F99C(w->xf0, w->mb0);
        fn_8014EF34(w->xf0);
        fn_80157684(&q->x38, 1, 0.0f);
        fn_80157684(&w->r0, 1, 1.0f);
        fn_80157684(&w->a24, 1, 0.0f);
        fn_80157684(&w->a48, 1, -1.0f);
        v.x = w->a24.pos[0] - w->a48.pos[0];
        v.y = w->a24.pos[1] - w->a48.pos[1];
        v.z = w->a24.pos[2] - w->a48.pos[2];
        w->a6c = njScalor(&v);
        njUnitMatrix(w->mb0);
        fn_80156C6C(w->mb0, q);
        if (q->xe8 != NULL) {
            fn_80156CC4(q, buf);
            fn_80156C6C(w->mb0, buf);
        }
        njUnitMatrix(w->m70);
        fn_80156C6C(w->m70, q);
        fn_801566B4(1, w->m70, w->mb0);
        break;
    }
    case 0xff: {
        Q_80124108 *q2 = p->work;
        fn_801E17E0(q2->x23c);
        q->x23c = NULL;
        fn_801E17E0(q->x1e4);
        fn_8015EBF4(p->work);
        if (q->x100 != NULL) fn_802275A4(q->x100, 0);
        fn_80100B74(p);
        break;
    }
    }
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

/* The ship object's info record (EvExt.info): word 15 (present when count > 14) is its flag. */
typedef struct EvInfoShip {
    s32 count;          /* 0x00 */
    u8 pad04[0x3c - 0x04];
    s32 x3c;            /* 0x3C */
} EvInfoShip;

/* One arranged ship's texture list and flag. */
typedef struct ShipTex {
    NJS_TEXLIST* texlist;
    s32 flag;
} ShipTex;

extern ShipTex lbl_80308EB8[];

static inline EvExt* TaskExt_80129058(Task* task) {
    EvObj* w = task->work;
    return w->ext;
}
extern s32 lbl_80347284;

void fn_80129058(Task* task) {
    switch (task->state) {
    case 0:
    case 0xFE: {
        EvInfoShip* r = TaskExt_80129058(task)->info;
        lbl_80308EB8[lbl_80347284].flag = (r->count > 0xe) ? r->x3c : 0;
        lbl_80308EB8[lbl_80347284].texlist = TaskExt_80129058(task)->texlist;
        lbl_80347284++;
        task->state = 1;
        break;
    }
    case 1:
        break;
    case 0xFF:
        fn_80100B74(task);
        break;
    }
}

void fn_801296C4(Task *p) {
    switch (p->state) {
    case 0xfe:
    case 0x0:
        fn_8015ED90(p);
        p->state = 1;
        break;
    case 0x1:
        fn_8015E600(p->work);
        break;
    case 0xff:
        fn_8015EBF4(p->work);
        fn_80100B74(p);
        break;
    }
}


static inline EvExt *TaskExt_80129814(Task *t) {
    EvObj *e = t->work;
    return e->ext;
}

void fn_80129814(Task *o) {
    ShipEntry *e;
    if (lbl_8034729C >= 8) {
        fn_801DBE1C("Arrange Ship Is Over");
    }
    if (strncmp(TaskExt_80129814(o)->name, "sb_ship", 7) == 0 ||
        strncmp(TaskExt_80129814(o)->name, "sb_enemy", 7) == 0) {
        e = &lbl_80308EF8[lbl_8034729C];
        e->task = o;
        {
            ShipSlot *s = &e->s;
            s->b = 1000;
            s->c = 1000;
        }
        lbl_8034729C++;
    }
}

void *fn_801298CC(void) {
    return lbl_803472CC + (lbl_803472A8->items->x46 << 2);
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

extern s32 lbl_80346EE0;
extern s32 lbl_8034728C;
extern s32 lbl_80347288;
extern void fn_8015C5F4(void);
extern void fn_8015AA18(void);
extern void fn_80156324(void);

static inline ShipEntry *FindShip(s32 id) {
    ShipEntry *found;
    s32 i;
    s32 key = id;

    if (id == 0xffff) {
        key = lbl_803472B0;
    }
    found = 0;
    for (i = 0; i < lbl_8034729C; i++) {
        EvObj *e = lbl_80308EF8[i].task->work;
        if (key == e->x17a) {
            found = &lbl_80308EF8[i];
        }
    }
    if (found == 0) {
        fn_801DBE1C(lbl_802B33EC, key);
    }
    return found;
}

void fn_80129AA4(void)
{
    s32 ready;
    ready = lbl_80311AC0.id >= 500;
    if (ready != 0) {
        s32 v = lbl_80310A1C[0x10b];
        if (v != lbl_80346EE0) {
            ShipEntry *e;
            s32 id;
            lbl_80346EE0 = v;
            if (v == 0) {
                id = 0;
            } else {
                id = lbl_803472A4->x20;
            }
            e = FindShip(id);
            lbl_80347454 = e->task;
            lbl_80347450 = e->task->work;
        }
        if (lbl_8034728C == 1 && lbl_80347290 == 0) {
            fn_8015C5F4();
            lbl_8034728C = 0;
            lbl_80347288 = 1;
        }
        fn_8015AA18();
        fn_80156324();
    }
}

static inline s32 FlagTest(u32 idx) {
    return (lbl_80310B3C[idx >> 5] & (1 << (idx & 31))) != 0;
}

extern void fn_801C78B8(void);
extern void fn_80148E08(void);
extern void fn_8015C644(void);
extern void fn_8009766C(void);
extern void fn_8015C6C8(void);
extern void fn_801560FC(void);
extern void fn_80109F90(char* name, u16 id);
extern void fn_8012910C(Task* t);
extern char lbl_802B3428[];
extern s32 lbl_803472D0;
extern s32 lbl_80346EDC;
extern s32 lbl_803472D4;
extern s32 lbl_803472C4;
extern s32 lbl_803472B0;
typedef struct Work_8012A634 {
    s32 x0;
    u8 pad4[4];
    s32 x8;
} Work_8012A634;
static inline Work_8012A634* WorkOf(Task* t) {
    return t->work;
}

void fn_8012A634(void) {
    s32 ready;
    int i;

    ready = lbl_80311AC0.id >= 500;
    if (ready == 0) {
        return;
    }
    {
        fn_801C78B8();
        lbl_803472A4 = NULL;
        lbl_803472B0 = 0;
        lbl_803472AC = -1;
        lbl_803472E0 = lbl_8034A380;
        lbl_80346EE4 = lbl_8034A3A4;
        lbl_803472DC = lbl_8034A380;
        lbl_803472D8 = 0;
        lbl_803472D4 = 0;
        lbl_803472C0 = 0;
        lbl_803472B4 = 0;
        lbl_803472A0 = NULL;
        lbl_8034728C = 0;
        lbl_80347284 = 0;
        lbl_80346EDC = 1;
        lbl_80347288 = 0;
        fn_80148E08();
        fn_8015C644();
        lbl_803472D0 = 0;
        for (i = 0x408; i < 0x40E; i++) {
            s32 on = FlagTest(i);
            if (on) {
                lbl_803472D0++;
            }
        }
        lbl_8034729C = 0;
        for (i = 0; i < 8; i++) {
            lbl_80308EF8[i].task = NULL;
        }
        lbl_803472C4 = -1;
        lbl_803472C8 = 0;
        for (i = 0; i < 32; i++) {
            lbl_80308F98[i].x0 = 0;
            lbl_80308F98[i].x4 = 0;
            lbl_80308F98[i].p = NULL;
        }
        lbl_80347454 = NULL;
        lbl_80310A1C[0x101] = 0;
        lbl_80310A1C[0x100] = 0;
        lbl_80310A1C[0x107] = 0;
        lbl_80310A1C[0x108] = 0;
        lbl_80310A1C[0x109] = 0;
        lbl_80310A1C[0x10b] = 0;
        lbl_80310A1C[0x10d] = 0;
        lbl_80347450 = NULL;
        lbl_80346EE0 = 0;
        fn_8009766C();
        lbl_803472A0 = fn_802267AC(lbl_80347588, fn_8012910C);
        lbl_803472A0->work = fn_801E1A74(1, 0x70);
        WorkOf(lbl_803472A0)->x0 = 0;
        WorkOf(lbl_803472A0)->x8 = 1;
        fn_8015C6C8();
        fn_801560FC();
        fn_80109F90(lbl_802B3428, 0x7fff);
        fn_8022642C();
    }
}

s32 fn_8012A8DC(void) {
    s32 v = lbl_80311AC0.id;
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

extern void *fn_801E49D8(const char *path);
extern s32 fn_801E4974(void *file, s32 i);
extern s32 fn_801E48A8(void *file);
extern void *fn_801E4984(void *file, s32 i);
extern void *fn_801E1584(void *p, s32 size);
extern Obj_8012AA8C *fn_801DB124(void *data);
extern void fn_801D6998(void *bank, void *data);

static inline void *LoadPart(s32 idx, s32 *total) {
    void *buf;
    s32 b;
    s32 a;
    a = fn_801E4974(lbl_80346F0C, idx);
    b = fn_801E48A8(lbl_80346F0C) - *total;
    buf = fn_801E1C7C(a);
    MemCopy(buf, fn_801E4984(lbl_80346F0C, idx), a);
    lbl_80346F0C = fn_801E1584(lbl_80346F0C, b - a);
    *total += a;
    return buf;
}

static inline void *LoadLast(s32 idx, s32 total) {
    s32 a;
    s32 b;
    void *buf;
    a = fn_801E4974(lbl_80346F0C, idx);
    b = fn_801E48A8(lbl_80346F0C) - total;
    buf = fn_801E1C7C(a);
    MemCopy(buf, fn_801E4984(lbl_80346F0C, idx), a);
    lbl_80346F0C = fn_801E1584(lbl_80346F0C, b - a);
    return buf;
}

void fn_8012AB84(void) {
    s32 a;
    s32 total;
    void *buf;
    void *data;
    void *d0;
    lbl_80346F0C = fn_801E49D8("/field/HrsBin_sbp.mll");
    total = fn_801E4974(lbl_80346F0C, 6);
    a = fn_801E48A8(lbl_80346F0C);
    buf = fn_801E1C7C(total);
    data = fn_801E4984(lbl_80346F0C, 6);
    MemCopy(buf, data, total);
    lbl_80346F0C = fn_801E1584(lbl_80346F0C, a - total);
    lbl_80346EF8 = fn_801DB124(buf);
    fn_80227810(lbl_80346EF8->x4->x20);

    buf = LoadPart(5, &total);
    lbl_80346EF4 = fn_801DB124(buf);
    fn_80227810(lbl_80346EF4->x4->x20);

    buf = LoadLast(4, total);
    lbl_80346EF0 = fn_801DB124(buf);
    fn_80227810(lbl_80346EF0->x4->x20);

    lbl_80346EFC = fn_801E1C7C(0x14);
    d0 = fn_801E4984(lbl_80346F0C, 0);
    fn_801D6998(lbl_80346EFC, d0);
    lbl_80346F00 = fn_801E1C7C(0x14);
    fn_801D6998(lbl_80346F00, fn_801E4984(lbl_80346F0C, 1));
    lbl_80346F04 = fn_801E1C7C(0x14);
    fn_801D6998(lbl_80346F04, fn_801E4984(lbl_80346F0C, 2));
    lbl_80346F08 = fn_801E1C7C(0x14);
    fn_801D6998(lbl_80346F08, fn_801E4984(lbl_80346F0C, 3));
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
                fn_801E5148(p3);
            } else {
                fn_801E5DF0(p3);
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

void fn_801119D4(EvObj *obj) {
    s32 r;

    obj->speed = 1.0f;
    fn_801189F0(obj);
    switch (obj->x172) {
    case 0:
        r = fn_8010E270(obj, lbl_80311970.ang[1]);
        if (r == 0) {
            fn_801E7414(0x2b, obj);
            obj->motionId = 0x11;
            obj->x172 = 0;
        } else if (r == 2) {
            fn_801E7414(0x2a, obj);
            obj->motionId = 0x12;
            obj->x172 = 0;
        }
        break;
    }
}

void fn_8011356C(EvObj *obj) {
    s16 r;

    obj->speed = 1.0f;
    fn_801189F0(obj);
    if (lbl_80346E68 == 0) {
        r = lbl_80311A60[0]->y;
        if (r > 0) {
            fn_801E7414(0x1c, obj);
            SePlay(0xf, 5, 0x1b);
            obj->motionId = 7;
            obj->x172 = 0;
        } else if (r < 0) {
            fn_801E7414(0x1b, obj);
            SePlay(0xf, 5, 0x1b);
            obj->motionId = 7;
            obj->x172 = 0;
        }
    }
    lbl_80346E68 = 0;
}

void fn_8011816C(EvObj *self, EvColl *out) {
    if (lbl_80347404 == 0) {
        out->pos = &self->pos.x;
        out->ang = self->ang;
        out->pivotPos = 0;
        out->pivotAng = 0;
    } else {
        out->pos = &self->pos.x;
        out->ang = self->ang;
        out->pivotPos = &self->pivotPos.x;
        out->pivotAng = self->pivotAng;
    }
    fn_80222838(out);
    fn_80117BE4(0, self, out);
}

void fn_80119A28(EvObj *p) {
    s32 n;
    f32 v;
    if (lbl_80347440 == 0) {
        return;
    }
    v = fn_80090EEC(p, lbl_802E54B0[fn_801161B4()].f2c);
    n = lbl_80347440;
    if (n == 1) {
        if (v < lbl_80349EDC) {
            p->colour.a = lbl_80349EA4;
        } else {
            p->colour.a = lbl_80349E18;
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
    p->colour.a = lbl_80349E18;
    lbl_80347444 = 0;
    lbl_80347440 = 0;
    return;
ea4:
    p->colour.a = lbl_80349EA4;
}

void fn_80118368(EvObj *obj);
void fn_801185D4(EvObj *o);
s32 fn_801186D8(EvObj *obj);
extern s32 fn_8009578C(void);
extern void fn_8009574C(void);
extern void (*lbl_802E4F50[])(EvObj *o);
extern u16 lbl_8034740E;
extern s32 lbl_80346E84;
extern s32 lbl_80347448;
extern f32 lbl_80347410;

void fn_80119AF4(Task *t) {
    extern f32 fn_80290008(NJS_POINT3 *a, NJS_POINT3 *b);
    s32 hit;
    EvObj *o;
    if (lbl_80347448 == 1) {
        return;
    }
    o = t->work;
    fn_80118368(o);
    if (fn_8011768C() != 0) {
        lbl_80347444 = 0;
    }
    lbl_8034740E = 0;
    lbl_802E4F50[o->motionId](o);
    if (fn_8011768C() == 0) {
        if (PlayerBusy() != 1 && lbl_80347440 == 0) {
            fn_801186D8(o);
            fn_801185D4(o);
        }
    }
    if (lbl_8034740E < 1 || lbl_8034740E > 8) {
        lbl_80347410 = lbl_80349E18;
    } else {
        lbl_80347410 = lbl_80347410 + fn_80290008(&o->pos, &o->home);
    }
    if (PlayerBusy() == 0) {
        if ((lbl_80310B3C[33] & 0x80000000) == 0 && fn_8009763C() != 12 && lbl_80347508 != 1) {
            EvColl *c = o->coll;
            if (lbl_80347404 == 0) {
                c->pos = &o->pos.x;
                c->ang = o->ang;
                c->pivotPos = 0;
                c->pivotAng = 0;
            } else {
                c->pos = &o->pos.x;
                c->ang = o->ang;
                c->pivotPos = &o->pivotPos.x;
                c->pivotAng = o->pivotAng;
            }
            fn_80222838(c);
            hit = fn_80117BE4(0, o, c);
            if ((lbl_80311A60[0]->x8 & 0x100) != 0 && fn_8011768C() == 0) {
                EvColl *r = o->res;
                r->pos[0] = o->pos.x;
                r->pos[1] = o->pos.y;
                r->pos[2] = o->pos.z;
                r->ang[0] = o->ang[0];
                r->ang[1] = o->ang[1];
                r->ang[2] = o->ang[2];
                fn_80222838(r);
                hit |= fn_80117BE4(1, o, r);
            }
        }
        lbl_80346E84 = hit;
    }
    if (lbl_80347440 != -1) {
        if ((lbl_80311A60[0]->x8 & 0x800) != 0 && lbl_80346E80 == 0 && fn_8011768C() == 0) {
            if (lbl_80347440 == 0) {
                if (fn_8009578C() == 1) {
                    lbl_80347440 = 1;
                    lbl_80347444 = 1;
                }
            } else {
                fn_8009574C();
                lbl_80347440 = 2;
            }
        }
        fn_80119A28(o);
    }
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
        if (lbl_803472A4->x4c == 0) {
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
    if (lbl_803472A4->x4c != 0) {
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

void fn_80129560(Task *p) {
    switch (p->state) {
    case 0xfe:
    case 0x0:
        fn_8015ED90(p);
        p->state = 1;
        break;
    case 0x1:
        fn_8015E600(p->work);
        break;
    case 0xff:
        fn_8015EBF4(p->work);
        fn_80100B74(p);
        break;
    }
}

void fn_80129750(NJS_MATRIX m, Task *o) {
    Fn80129750Inner *in;

    in = o->work;
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
        if (lbl_803472E0 == (f32)lbl_803472A4->v8) {
            return (lbl_803472C0 % lbl_803472D0 == 0) + 1;
        }
    }
    return 0;
}

void fn_80129BD4(void) {
    Fn80129BD4Head *h;
    s32 i;
    s32 sum;
    Rec *p;

    h = lbl_803472A8;
    if (lbl_803472E0 >= (f32)h->f4) {
        lbl_803472E0 = 0.0f;
        lbl_80346EE4 = -1.0f;
    }
    sum = 0;
    for (i = 0; i < h->count; i++) {
        sum += h->items[i].v4;
        if ((f32)sum > lbl_803472E0) {
            lbl_803472B4 = i;
            break;
        }
    }
    p = h->items + lbl_803472B4;
    lbl_803472A4 = p;
    lbl_803472AC = p->x20;
}

s32 fn_80129CA8(EvObj *o) {
    char fi[0x38];
    char *base;

    base = (char *)lbl_802B3388;
    strcpy(fi, o->ext->name);
    fi[8] = 0;
    if (fn_8025EF88(fi, base + 0x7c) == 0) {
        return 0;
    }
    if (fn_8025EF88(fi, base + 0x58) == 0) {
        return 1;
    }
    fn_8015757C(base + 0x88, o->x17a);
    return 0;
}

ShipEntry *fn_80129D40(s32 id) {
    ShipEntry *found;
    s32 i;

    if (id == 0xffff) {
        id = lbl_803472B0;
    }
    found = 0;
    for (i = 0; i < lbl_8034729C; i++) {
        EvObj *e = lbl_80308EF8[i].task->work;
        if (id == e->x17a) {
            found = &lbl_80308EF8[i];
        }
    }
    if (found == 0) {
        fn_801DBE1C(lbl_802B33EC, id);
    }
    return found;
}

typedef struct Btl135598 {
    u8 pad0[0x24c];
    s32 x24c;
    s32 x250;
} Btl135598;
typedef struct Btl13558C {
    u8 pad0[0x14];
    s32 x14;
    s32 x18;
    u8 pad1c[0x10c - 0x1c];
} Btl13558C;
extern void fn_80148640(void);
extern void fn_801447A0(void);
extern void fn_80156588(s32);
extern Btl135598 *fn_80135598(void);
extern Btl13558C *fn_8013558C(void);
extern void fn_80141610(void);
extern void fn_80148160(void);
extern s32 lbl_80346EDC;
extern s32 lbl_80347288;
static inline s32 ShipPhase(void) {
    if (lbl_803472E0 == 0.0f) {
        if (lbl_803472C0 % lbl_803472D0 == 0) {
            return 2;
        }
        return 1;
    }
    if (lbl_803472A8 != 0) {
        if (lbl_803472E0 == (f32)lbl_803472A4->v8) {
            if (lbl_803472C0 % lbl_803472D0 == 0) {
                return 2;
            }
            return 1;
        }
    }
    return 0;
}

static inline void ShipSeek(void) {
    Fn80129BD4Head *h;
    s32 i;
    s32 sum;
    Rec *p;

    h = lbl_803472A8;
    if (lbl_803472E0 >= (f32)h->f4) {
        lbl_803472E0 = 0.0f;
        lbl_80346EE4 = -1.0f;
    }
    sum = 0;
    for (i = 0; i < h->count; i++) {
        sum += h->items[i].v4;
        if ((f32)sum > lbl_803472E0) {
            lbl_803472B4 = i;
            break;
        }
    }
    p = h->items + lbl_803472B4;
    lbl_803472A4 = p;
    lbl_803472AC = p->x20;
}


void fn_80129DD0(void) {
    s32 ready;
    ready = lbl_80311AC0.id >= 500;
    if (ready != 0) {
        s32 r;
        ShipEntry *e;
        s8 pct;
        lbl_803473EC = 1;
        lbl_803473E8 = 0;
        ShipSeek();
        fn_80148640();
        r = ShipPhase();
        if (r != 0) {
            s32 f = 0;
            if (r == 2) {
                lbl_80310A1C[0x101] = 0;
                f = 1;
                lbl_803472DC = 0.0f;
                if (lbl_80346EDC == 0) {
                    fn_801447A0();
                    lbl_80347288 = 0;
                }
            } else {
                lbl_80310A1C[0x101] = 1;
            }
            fn_80156588(f);
            lbl_80346EDC = 1;
            lbl_803473AC = 1;
        } else {
            if (lbl_803472E0 == (f32)(lbl_803472A4->v8 + lbl_803472A4->v4) - 1.0f) {
                lbl_80310A1C[0x101] = 3;
            } else {
                lbl_80310A1C[0x101] = 2;
            }
            lbl_80346EDC = 0;
        }
        if (0.0f == lbl_803472DC) {
            lbl_80310A1C[0x100] = 0;
        } else {
            lbl_80310A1C[0x100] = 1;
        }
        {
            Btl135598 *b;
            e = FindShip(lbl_803472B0);
            b = fn_80135598();
            pct = e->s.b * 100 / e->s.c;
            if (pct == 0 && (e->s.b != 0 || b->x250 != 0)) {
                pct = 1;
            }
            lbl_80310A1C[0x105] = pct;
        }
        {
            Btl13558C *b;
            e = FindShip(lbl_803472AC);
            b = fn_8013558C();
            pct = e->s.b * 100 / e->s.c;
            if (pct == 0 && (e->s.b != 0 || b[e->s.d].x18 != 0)) {
                pct = 1;
            }
            lbl_80310A1C[0x106] = pct;
        }
        if (lbl_803472D8 > 100) {
            lbl_80310A1C[0x107] = 100;
        } else {
            lbl_80310A1C[0x107] = lbl_803472D8;
        }
        lbl_80310A1C[0x108] = lbl_803472C0 % lbl_803472D0;
        fn_80141610();
        if (lbl_80347294 == 1) {
            lbl_80310A1C[0x102] = 1;
        } else {
            lbl_80310A1C[0x102] = 0;
        }
        fn_80148160();
    }
}

s32 fn_801109AC(Angle ang, EvObj* o) {
    NJS_MATRIX m;
    NJS_POINT3 p, d;
    s32 ok;
    njUnitMatrix(m);
    njRotateXYZ(m, 0, ang, 0);
    p.x = 0.0f;
    p.y = 0.0f;
    p.z = 24.0f;
    njCalcPoint(m, &p, &d);
    p.x = o->pos.x + d.x;
    p.y = 24.0f + (o->pos.y + d.y);
    p.z = o->pos.z + d.z;
    o->hit->key.x28 = 0xFFFF;
    o->hit->key.id = 0xFFFF;
    ok = 1;
    fn_8011698C(&p, o->hit);
    if (1.0f + o->pos.y < p.y) {
        ok = 0;
    }
    return ok;
}

void fn_801185D4(EvObj *o) {
    f32* p;
    f32* base;
    s32 i;
    u16 t = o->motionId;
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
        if (p[0] <= o->x18c && o->speed + p[0] > o->x18c && o->x19c == 1) {
            u16 k = (o->hit->h24 >> 4) & 0xF;
            if (k >= 7) {
                k = 6;
            }
            SePlay(15, 5, lbl_80346798[k]);
        }
        i++;
        p++;
    } while (i < 2);
}

void fn_80119744(Xf* out, EvObj* a, NJS_MOTION* m, f32 frame) {
    NJS_VECTOR v;
    NJS_MATRIX mt;
    void** d;
    if (m == NULL) {
        out->pos.x = 0.0f;
        out->pos.y = 0.0f;
        out->pos.z = 0.0f;
        out->ang[0] = 0;
        out->ang[1] = 0;
        out->ang[2] = 0;
        return;
    }
    fn_800071D8(m, frame);
    d = m->mdata;
    if (d[0] != NULL) {
        fn_80007080(&v, 1);
        njUnitMatrix(mt);
        njRotateXYZ(mt, a->ang[0], a->ang[1], a->ang[2]);
        njScale(mt, a->scl.x, a->scl.y, a->scl.z);
        njCalcVector(mt, &v, &out->pos);
    } else {
        out->pos.x = 0.0f;
        out->pos.y = 0.0f;
        out->pos.z = 0.0f;
    }
    if (d[1] != NULL) {
        fn_80006F1C(out->ang, 1);
    } else {
        out->ang[0] = 0;
        out->ang[1] = 0;
        out->ang[2] = 0;
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

void fn_8011B6E0(Out_8011B624* a) {
    f32 t = (f32)a->x4 / (f32)a->xc;
    f32 v;
    f32 dx, dy;
    if (a->flags & 0x200) {
        fn_8011B024(a->curve, 4, 3, &v, t);
        t = 0.01f * v;
    }
    dx = 640.0f * t;
    dy = 480.0f * t;
    if (a->flags & 0x1000000) {
        a->x28 = -dx;
        a->x30 = 640.0f - dx;
    } else if (a->flags & 0x2000000) {
        a->x28 = dx;
        a->x30 = 640.0f + dx;
    }
    if (a->flags & 0x4000000) {
        a->x2c = -dy;
        a->x34 = 480.0f - dy;
    } else if (a->flags & 0x8000000) {
        a->x2c = dy;
        a->x34 = 480.0f + dy;
    }
    a->vtx[0].x = a->vtx[1].x = a->x28;
    a->vtx[0].y = a->vtx[2].y = a->x2c;
    a->vtx[2].x = a->vtx[3].x = a->x30;
    a->vtx[1].y = a->vtx[3].y = a->x34;
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

void fn_8012092C(Rec_8011F000* o) {
    DrawState st;
    Item_8011FC10* p;
    s32 n;
    s32 i;
    if (o->x18 != 0) {
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
    if (++o->x18 >= 15) {
        o->flags |= 2;
        o->flags &= ~0x40001;
        fn_801202C4(o);
        fn_8012048C(o);
        o->x18 = 0;
    }
}

void fn_80122778(Task* o) {
    SprAnim* a = o->work;
    a->timer++;
    if (a->timer % (a->frames[a->idx].dur + 1) != 0) {
        fn_801D6CBC(a->handle, &a->b14);
        return;
    }
    a->idx++;
    if (a->frames[a->idx].dur == 0) {
        a->loops++;
        if (a->loops >= a->max_loops) {
            fn_801D6C3C(a->handle);
            if (o->work != NULL) {
                fn_801E1784(o->work);
                o->work = NULL;
            }
            o->flags |= 0x40;
            return;
        }
        a->idx = 0;
    }
    fn_801D6CBC(a->handle, &a->b14);
    a->timer = 0;
    a->b16 = a->frames[a->idx].a;
    a->b17 = a->frames[a->idx].b;
}

Obj_80122A00* fn_80122A00(void* unused, Src_80122A00* s) {
    Obj_80122A00* o;
    s32 i;
    SrcFrame* sf;
    SprAnim* a;
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
            a->max_loops = f->b;
            break;
        }
        f++;
    }
    if (i >= 31) {
        f[-1].dur = 0;
        a->count = 31;
        a->max_loops = f[-1].b;
    }
    a->b14 = 1;
    a->b15 = 0;
    a->b18 = 0;
    a->b16 = a->frames[0].a;
    a->b17 = a->frames[0].b;
    return o;
}

typedef struct Hdr_80122B34 {
    u8 pad0[0x24];
    s32 v24;
    SrcFrame d28[1];
} Hdr_80122B34;
typedef struct Cfg_80122B34 {
    u8 pad0[0x10];
    Hdr_80122B34* hdr;
} Cfg_80122B34;
typedef struct M_80122B34 {
    u8 _00[0x1c8];
    Cfg_80122B34* cfg;
    u8 _1cc[0xc];
    C1d8* sub;
    u8 _1dc[0x1e];
    u8 f1fa;
    u8 f1fb;
    u8 _1fc[0x60];
    Src_80122A00* work;
    u8 _260[0xc];
    u8 f26c;
} M_80122B34;
typedef struct T_80122B34 {
    u8 _00[0x18];
    u8 flags;
    u8 state;
    u8 _1a;
    u8 f1b;
    u8 _1c[8];
    M_80122B34* m;
} T_80122B34;
extern s32 lbl_8034757C;

void fn_80122B34(T_80122B34* t) {
    extern void* fn_801E1A2C(s32 a, u32 size);
    extern void* memset(void* p, int c, u32 n);
    extern void fn_8015ED90(void* t);
    extern void fn_8015EB8C(void* m, s32 id, void* cb);
    extern s32 fn_8015E600(void* m);
    extern void fn_8015EBF4(void* m);
    M_80122B34* m = t->m;
    Src_80122A00* w = m->work;

    if (t->flags & 0x20) {
        t->state = 0xFF;
    }
    switch (t->state) {
    case 0:
        t->f1b = 0xFA;
        m->f26c = 1;
        w = fn_801E1A2C(1, 0x10);
        memset(w, 0, 0x10);
        {
            SprAnim* b = fn_801E1A2C(1, 0x98);
            w->anim = b;
            if (b == 0) {
                if (w != 0) {
                    fn_801E1784(w);
                }
                break;
            }
        }
        m->work = w;
        w->owner = t;
        m->f1fa = 0;
        fn_8015ED90(t);
        fn_8015EB8C(m, 0, fn_80122770);
        fn_8015EB8C(m, 0xD, fn_80122768);
        m->sub->w1a0 = 0;
        t->state = 1;
        break;
    case 1:
        fn_8015E600(m);
        { s32 q = m->f1fb; if (q == 1) {
            m->f1fb = 0;
        } }
        break;
    case 2:
        { s32 q = m->f1fa; if (q == 1) {
            SrcFrame* f = m->cfg->hdr->d28;
            w->handle = m->cfg->hdr->v24;
            w->frames = f;
            if (w->handle >= 100) {
                w->handle = lbl_8034757C;
            }
            fn_80122A00(t, w);
            m->f1fa = 0;
        } }
        if (fn_8015E600(m) == 0) {
            if (w->anim->count == 0) {
                t->state = 1;
                m->f1fb = 1;
            }
        }
        break;
    case 0xFF:
        if (w->anim != 0) {
            fn_801E1784(w->anim);
            w->anim = 0;
        }
        if (m->work != 0) {
            fn_801E1784(m->work);
            m->work = 0;
        }
        fn_8015EBF4(m);
        t->flags |= 0x40;
        break;
    case 4:
    case 0xFE:
    default:
        break;
    }
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
    ready = lbl_80311AC0.id >= 500;
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
    extern void fn_80222838(Attach *a);
    extern void fn_8015ED90(Parent *p);
    extern s32 fn_8015E600(Obj *o);
    extern void fn_8015EBF4(Obj *o);
    extern void fn_80117748(Parent *p);
    extern void fn_802275A4(void *p, s32 a);
    extern void fn_80100B74(Parent *p);
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
            if (30.0f > fn_80290008(&o->pos.x, &lbl_80347450->pos.x)) {
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

s32 fn_801147E8(EvObj *o, f32 step, s32 turn) {
    Angle ang[3];
    s32 yaw;
    s32 ret;

    yaw = fn_801DD078(&o->dir, &o->up);
    yaw += turn;
    fn_801DD5E8(ang, &o->up);
    fn_801DCF24(&o->dir, ang, yaw, 1.0f);
    if (step != 0.0f) {
        o->pos.x = o->dir.x * step + o->pos.x;
        o->pos.y = o->dir.y * step + o->pos.y;
        o->pos.z = o->dir.z * step + o->pos.z;
    }
    ret = fn_801144A4(o, yaw, ang);
    yaw = fn_801DD078(&o->dir, &o->up);
    fn_801DD5E8(ang, &o->up);
    fn_801DCF24(&o->dir, ang, yaw, 1.0f);
    if (fn_80114138(o, yaw, ang) != 0) {
        ret = fn_801144A4(o, yaw, ang);
        yaw = fn_801DD078(&o->dir, &o->up);
        fn_801DD5E8(ang, &o->up);
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
    row = &lbl_802E1154[lbl_80310A1C[6]];
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
    if (lbl_80311AC0.id != 99) {
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

int fn_80115A4C(f32 *pos, u16 *out, EvHit *obj) {
    f32 a[3];
    f32 b[3];
    EvHit tmp;
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
                *out = obj->h24;
            }
        }
    } else if (hit == 2) {
        if (b[1] < pos[1]) {
            pos[1] = b[1];
            if (out != 0) {
                *out = tmp.h24;
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

int fn_801169D4(int sel, Xf *pos, void *p, f32 maxd, f32 step) {
    f32 x = 0.0f;
    f32 z = x;
    NJS_MATRIX m;
    Xf buf;
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
        njRotateY(m, pos->ang[1]);
        v.x = x * d;
        v.y = y * d;
        v.z = z * d;
        njCalcPoint(m, &v, &out);
        buf.pos.x = pos->pos.x + out.x;
        buf.pos.y = pos->pos.y + out.y;
        buf.pos.z = pos->pos.z + out.z;
        if (fn_80116B84(3, &buf.pos, lbl_8030A35C, p) == 0) {
            pos->pos.x = buf.pos.x;
            pos->pos.y = buf.pos.y;
            pos->pos.z = buf.pos.z;
            return 1;
        }
    }
    return 0;
}

int fn_80116F2C(Chr_80116F2C *chr) {
    Xf tmp;
    int r;

    MemCopy(&tmp, &chr->cur, 0x24);
    r = fn_80116B84(3, &chr->cur.pos, lbl_8030A35C, chr->x1b8);
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

void fn_80117290(EvObj *c) {
    extern Tbl lbl_8030E7F0;
    extern void fn_80222838(EvColl *r);
    extern EvColl *fn_8022300C(EvColl *r);
    extern EvColl *fn_80222F14(EvColl *r, EvColl *c);
    extern void fn_80221EDC(NJS_POINT3 *out, u32 a, u32 b);
    EvColl *ch;
    EvColl *r;
    NJS_POINT3 v;

    if (c->coll != 0) {
        c->coll->pos[0] = c->pos.x;
        c->coll->pos[1] = c->pos.y;
        c->coll->pos[2] = c->pos.z;
        fn_80222838(c->coll);
        r = c->coll;
        if (r != 0) {
            ch = fn_8022300C(r);
            if (ch != 0) {
                do {
                    if ((ch->mask10 & 0x4800) == 0x4800) {
                        fn_80221EDC(&v, lbl_8030E7F0.x10, lbl_8030E7F0.x1c);
                        r->pos[0] += v.x;
                        r->pos[1] += v.y;
                        r->pos[2] += v.z;
                        fn_80222838(r);
                    }
                    ch = fn_80222F14(r, ch);
                } while (ch != 0);
            }
        }
        c->pos.x = c->coll->pos[0];
        c->pos.y = c->coll->pos[1];
        c->pos.z = c->coll->pos[2];
    }
}

void fn_801173DC(int sel, EvObj *c) {
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

void fn_8011753C(EvObj *c) {
    extern Tbl lbl_8030E7F0;
    extern void fn_80222838(EvColl *r);
    extern EvColl *fn_8022300C(EvColl *r);
    extern EvColl *fn_80222F14(EvColl *r, EvColl *c);
    extern void fn_80221EDC(NJS_POINT3 *out, u32 a, u32 b);
    extern int fn_80116F2C(EvObj *c);
    EvColl *ch;
    EvColl *r;
    NJS_POINT3 v;

    fn_80116F2C(c);
    if (c->coll != 0) {
        c->coll->pos[0] = c->pos.x;
        c->coll->pos[1] = c->pos.y;
        c->coll->pos[2] = c->pos.z;
        fn_80222838(c->coll);
        r = c->coll;
        if (r != 0) {
            ch = fn_8022300C(r);
            if (ch != 0) {
                do {
                    if ((ch->mask10 & 0x4800) == 0x4800) {
                        fn_80221EDC(&v, lbl_8030E7F0.x10, lbl_8030E7F0.x1c);
                        r->pos[0] += v.x;
                        r->pos[1] += v.y;
                        r->pos[2] += v.z;
                        fn_80222838(r);
                    }
                    ch = fn_80222F14(r, ch);
                } while (ch != 0);
            }
        }
        c->pos.x = c->coll->pos[0];
        c->pos.y = c->coll->pos[1];
        c->pos.z = c->coll->pos[2];
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

void fn_8011D7BC(void *src, void *tex) {
    Rec_8011D7BC *r;
    int i;
    if (lbl_80346EBC >= 20) {
        return;
    }
    r = &lbl_80346EB8[lbl_80346EBC];
    if (tex != 0) {
        Big *s = src;
        r->v[0].x = s->g[0].a[0];
        r->v[0].y = s->g[0].a[1];
        r->v[0].z = s->g[0].a[2];
        r->v[0].u = s->g[0].a[3];
        r->v[0].v = s->g[0].a[4];
        r->v[0].colour = s->g[0].n;
        r->v[1].x = s->g[1].a[0];
        r->v[1].y = s->g[1].a[1];
        r->v[1].z = s->g[1].a[2];
        r->v[1].u = s->g[1].a[3];
        r->v[1].v = s->g[1].a[4];
        r->v[1].colour = s->g[1].n;
        r->v[2].x = s->g[2].a[0];
        r->v[2].y = s->g[2].a[1];
        r->v[2].z = s->g[2].a[2];
        r->v[2].u = s->g[2].a[3];
        r->v[2].v = s->g[2].a[4];
        r->v[2].colour = s->g[2].n;
        r->v[3].x = s->g[3].a[0];
        r->v[3].y = s->g[3].a[1];
        r->v[3].z = s->g[3].a[2];
        r->v[3].u = s->g[3].a[3];
        r->v[3].v = s->g[3].a[4];
        r->v[3].colour = s->g[3].n;
    } else {
        Small *s = src;
        r->v[0].x = s->g[0].a[0];
        r->v[0].y = s->g[0].a[1];
        r->v[0].z = s->g[0].a[2];
        r->v[0].u = 0.0f;
        r->v[0].v = 0.0f;
        r->v[0].colour = s->g[0].n;
        r->v[1].x = s->g[1].a[0];
        r->v[1].y = s->g[1].a[1];
        r->v[1].z = s->g[1].a[2];
        r->v[1].u = 0.0f;
        r->v[1].v = 0.0f;
        r->v[1].colour = s->g[1].n;
        r->v[2].x = s->g[2].a[0];
        r->v[2].y = s->g[2].a[1];
        r->v[2].z = s->g[2].a[2];
        r->v[2].u = 0.0f;
        r->v[2].v = 0.0f;
        r->v[2].colour = s->g[2].n;
        r->v[3].x = s->g[3].a[0];
        r->v[3].y = s->g[3].a[1];
        r->v[3].z = s->g[3].a[2];
        r->v[3].u = 0.0f;
        r->v[3].v = 0.0f;
        r->v[3].colour = s->g[3].n;
    }
    r->tex = tex;
    lbl_80346EBC++;
}

extern s32 lbl_80346EBC;
extern Rec_8011D7BC lbl_80305EF8;
extern VertexCol lbl_80305EB8[4];
extern NJS_POINT3 fn_801DCDC0(f32 x, f32 y, f32 z);
extern void fn_80296EEC(s32 a, s32 b, s32 c);
extern void fn_80286EE8(void);
extern void fn_8028B498(void);
extern void fn_8028A418(VertexCol *v, s32 n, s32 flag);

static inline void DrawFlat_8011D548(Rec_8011D7BC *p) {
    int n;
    for (n = 0; n < 4; n++) {
        lbl_80305EB8[n].x = p->v[n].x;
        lbl_80305EB8[n].y = p->v[n].y;
        lbl_80305EB8[n].z = p->v[n].z;
        lbl_80305EB8[n].colour = p->v[n].colour;
    }
    fn_8028A418(lbl_80305EB8, 4, 1);
}

void fn_8011D548(void) {
    s32 j;
    s32 i;
    Rec_8011D7BC *a;
    VertexTex *q;
    NJS_POINT3 pt;

    if (lbl_80346EBC == 0 || lbl_80346EB8 == 0) {
        return;
    }
    a = lbl_80346EB8;
    for (j = 0; j < lbl_80346EBC; j++) {
        for (i = 0; i < 4; i++) {
            q = &a->v[i];
            pt = fn_801DCDC0(q->x, q->y, q->z);
            q->x = pt.x;
            q->y = pt.y;
            q->z = pt.z;
        }
        a++;
    }
    if (lbl_80346EBC >= 2) {
        for (j = 0; j < (i = lbl_80346EBC - 1); j++) {
            for (; i >= j + 1; i--) {
                if (j != i) {
                    Rec_8011D7BC *b;
                    a = &lbl_80346EB8[j];
                    b = &lbl_80346EB8[i];
                    if (a->v[0].z > b->v[0].z) {
                        memcpy(&lbl_80305EF8, a, 0x64);
                        memcpy(a, b, 0x64);
                        memcpy(b, &lbl_80305EF8, 0x64);
                    }
                }
            }
        }
    }
    njColorBlendingMode(0, 8);
    njColorBlendingMode(1, 6);
    fn_80296EEC(0, 7, 1);
    njPushMatrixEx();
    fn_80286EE8();
    fn_8028B498();
    njUnitMatrix(0);
    a = lbl_80346EB8;
    for (j = 0; j < lbl_80346EBC; j++) {
        if (a->tex != 0) {
            fn_80297DC8(a->tex);
            fn_8028A8C0(a->v, 4, 1);
        } else {
            DrawFlat_8011D548(a);
        }
        a++;
    }
    njPopMatrixEx();
    fn_80296EEC(1, 3, 1);
    lbl_80346EBC = 0;
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

EvColl *fn_80110AA0(EvObj *self, EvColl *tgt, s32 ang, s32 flag)
{
    extern NJS_POINT3 lbl_802B30F0;
    extern EvColl *fn_80222224(void *p);
    extern void njUnitMatrix(f32 *m);
    extern void njTranslate(f32 *m, f32 x, f32 y, f32 z);
    extern void njRotateXYZ(f32 *m, s32 x, s32 y, s32 z);
    extern void njCalcPoint(f32 *m, NJS_POINT3 *p, NJS_POINT3 *out);
    extern double acos(double x);
    extern EvColl *fn_8022300C(void *list);
    extern EvColl *fn_80222F14(void *list, void *n);
    extern void fn_80222964(void *p);
    extern void fn_801E1784(void *p);
    NJS_POINT3 out;
    NJS_POINT3 v = lbl_802B30F0;
    f32 m[16];
    EvColl *e;
    EvColl *found;
    EvColl *n;
    s32 a;

    e = fn_80222224(lbl_802E4CB0);
    e->mask10 = 0x8000;
    e->id12 = 0x2F;
    e->w8 = self->ext->x04;
    njUnitMatrix(m);
    njTranslate(m, tgt->pos[0], tgt->pos[1], tgt->pos[2]);
    njRotateXYZ(m, tgt->ang[0], ang, tgt->ang[2]);
    njTranslate(m, 0.0f, 0.0f, 24.0f);
    njCalcPoint(m, &v, &out);
    e->pos[0] = out.x;
    e->pos[1] = out.y;
    e->pos[2] = out.z;
    e->ang[0] = tgt->ang[0];
    e->ang[1] = tgt->ang[1];
    e->ang[2] = tgt->ang[2];
    fn_80222838(e);
    found = 0;
    n = fn_8022300C(e);
    if (n != 0) {
        do {
            if (n->id12 == 0x28 || n->id12 == 0x14 || n->id12 == 0x1D) {
                found = n;
                break;
            }
            n = fn_80222F14(e, n);
        } while (n != 0);
    }
    if (found != 0 && flag == 1 && lbl_80347414->id12 != 0x1D) {
        njUnitMatrix(m);
        njRotateXYZ(m, self->ang[0], self->ang[1], self->ang[2]);
        v.z = 1.0f;
        njCalcPoint(m, &v, &out);
        v.x = found->pos[0] - self->pos.x;
        v.y = found->pos[1] - self->pos.y;
        v.z = found->pos[2] - self->pos.z;
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
    extern void fn_80119744(Xf *out, void *obj, void *h, f32 f);
    extern void fn_801E7414(s32 id, void *obj);
    extern s32 fn_802256A0(f32 *pos, void *obj, u32 mask, u16 id);
    Xf d;
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
    o->f38 = o->f104 + d.pos.x;
    o->f3c = o->f108 + d.pos.y;
    o->f40 = o->f10c + d.pos.z;
    o->w44 = o->w110 + d.ang[0];
    o->w48 = o->w114 + d.ang[1];
    o->w4c = o->w118 + d.ang[2];
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

s32 fn_801177A4(EvObj *obj, EvColl *ev) {
    s32 r;
    s32 z;
    switch (ev->id12) {
    case 0x30:
        if (fn_8011768C() != 3) {
            obj->x164 = 0.0f;
            z = 0;
            obj->motionId = 0xf;
            obj->x172 = z;
            obj->pivot = z;
                                                obj->pivotPos.x = obj->pivotPos.y = obj->pivotPos.z = (f32)(obj->pivotAng[0] = obj->pivotAng[1] = obj->pivotAng[2] = z);
            obj->slots->x10 = ev;
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
                obj->motionId = 0xa;
                obj->x172 = z;
                obj->pivot = z;
                                                                obj->pivotPos.x = obj->pivotPos.y = obj->pivotPos.z = (f32)(obj->pivotAng[0] = obj->pivotAng[1] = obj->pivotAng[2] = z);
                obj->slots->x10 = ev;
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
                if (fn_8010E41C(ev->pos, ev->ang, &obj->pos.x) == 2) {
                    z = 0;
                    lbl_80310B3C[0x22] |= 1;
                    obj->x164 = 0.0f;
                    obj->motionId = 5;
                    obj->x172 = z;
                    obj->pivot = z;
                                                                                obj->pivotPos.x = obj->pivotPos.y = obj->pivotPos.z = (f32)(obj->pivotAng[0] = obj->pivotAng[1] = obj->pivotAng[2] = z);
                    obj->slots->x10 = ev;
                    lbl_8034741C = ev;
                    return 1;
                }
            }
        }
        break;
    }
    return 0;
}

s32 fn_801179B8(EvObj *obj, EvColl *ev) {
    extern EvColl *lbl_80347418;
    u16 st;
    s32 z;
    switch (ev->id12) {
    case 0x28:
        if (fn_8011768C() == 0) {
            lbl_80347414 = ev;
            z = 0;
            obj->pivot = z;
            obj->pivotPos.x = obj->pivotPos.y = obj->pivotPos.z = (f32)(obj->pivotAng[0] = obj->pivotAng[1] = obj->pivotAng[2] = z);
            obj->motionId = 0x15;
            obj->x172 = z;
            return 1;
        }
        break;
    case 0x30:
        st = obj->motionId;
        if (fn_8011768C() == 3 && st != 0xf && st != 0x10 && st != 0x14) {
            obj->motionId = 0x14;
            obj->x172 = 0;
            obj->slots->x10 = ev;
            lbl_80347418 = ev;
            return 1;
        }
        break;
    case 0x22:
    case 0x23:
        st = obj->motionId;
        if (fn_8011768C() == 2 && st != 0xa && st != 0xb && st != 0xc && st != 0xe) {
            obj->motionId = 0xe;
            obj->x172 = 0;
            obj->slots->x10 = ev;
            lbl_80347418 = ev;
            return 1;
        }
        break;
    case 0xe:
    case 0xf:
    case 0x10:
        st = obj->motionId;
        if (fn_8011768C() == 1 && st != 5 && st != 9 && st != 6) {
            lbl_80310B3C[0x22] &= ~1;
            obj->motionId = 6;
            obj->pivot = 0;
            obj->slots->x10 = ev;
            lbl_80347418 = ev;
            return 1;
        }
        break;
    }
    return 0;
}

void fn_80118368(EvObj *obj) {
    u16 save;
    s32 id;
    if (lbl_8030A380.type != 0) {
        if (3.4028235e38f != lbl_8030A380.a) {
            obj->pos.x = obj->home.x = lbl_8030A380.a;
            lbl_8030A380.a = 3.4028235e38f;
        }
        if (3.4028235e38f != lbl_8030A380.b) {
            obj->pos.y = obj->home.y = lbl_8030A380.b;
            lbl_8030A380.b = 3.4028235e38f;
        }
        if (3.4028235e38f != lbl_8030A380.c) {
            obj->pos.z = obj->home.z = lbl_8030A380.c;
            lbl_8030A380.c = 3.4028235e38f;
        }
        if (3.4028235e38f != lbl_8030A380.d) {
            obj->ang[0] = obj->tgt[0] = (s32)(182.04445f * lbl_8030A380.d);
            lbl_8030A380.d = 3.4028235e38f;
        }
        if (3.4028235e38f != lbl_8030A380.e) {
            obj->ang[1] = obj->tgt[1] = (s32)(182.04445f * lbl_8030A380.e);
            lbl_8030A380.e = 3.4028235e38f;
        }
        if (3.4028235e38f != lbl_8030A380.f) {
            obj->ang[2] = obj->tgt[2] = (s32)(182.04445f * lbl_8030A380.f);
            lbl_8030A380.f = 3.4028235e38f;
        }
        if (lbl_8030A380.type != 1) {
            obj->motionId = 0x16;
            obj->x172 = 0;
        }
        id = lbl_8030A380.id;
        if (id != 0x7fffffff) {
            save = obj->hit->x30;
            fn_80225930(0xffff, id, obj->hit);
            obj->hit->x30 = save;
            lbl_8030A380.id = 0x7fffffff;
        }
        if (obj->coll != 0) {
            fn_80222838(obj->coll);
        }
        lbl_8030A380.type = 0;
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
    VertexTex v[4];
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

f32 fn_8011E048(Sub *o, f32 x, f32 z) {
    f32 dist;
    f32 t;
    f32 inv;
    f32 near;
    f32 far;
    u32 c;
    f32 dx = x - o->x4.x;
    f32 dz = z - o->x4.y;
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
        if (o->flags & 0x100) {
            c = o->x8c.g[0].n & 0xffffff;
            if (o->flags & 0x200) {
                c |= (o->xd4 + (s32)((1.0f - t) * (f32)(o->xd0 - o->xd4))) << 24;
            } else {
                c |= (s32)((f32)o->xd0 * (1.0f - t)) << 24;
            }
            o->x8c.g[0].n = o->x8c.g[1].n = o->x8c.g[2].n = o->x8c.g[3].n = c;
            o->flags |= 0x20000;
        }
        return t;
    }
    inv = 1.0f - (t - near) / (far - near);
    if (o->flags & 0x200) {
        c = ((s32)((f32)o->xd4 * inv) << 24) | (o->x8c.g[0].n & 0xffffff);
        o->x8c.g[0].n = o->x8c.g[1].n = o->x8c.g[2].n = o->x8c.g[3].n = c;
        o->flags |= 0x20000;
    }
    return inv;
}

s32 fn_8011F000(Arg1_8011F000 *a, Arg2_8011F000 *b) {
    extern u8 lbl_802B3200[0x14];
    extern void fn_8012092C(Rec_8011F000 *r);
    extern void fn_8011F560(Rec_8011F000 *r);
    extern void fn_8011FC10(Rec_8011F000 *r);
    extern void fn_8011F8A8(Rec_8011F000 *r);
    extern void fn_8011F44C(Rec_8011F000 *r);
    extern void fn_8011F274(Rec_8011F000 *r);
    Obj_8011F000 *obj = a->x1d8->obj;
    Rec_8011F000 *rec = obj->x25c;
    DrawState ds;
    Item_8011FC10 *p;
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

void fn_8011FC10(Rec_8011F000 *rec) {
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
            part->col.u = col.u;
            col.b[0] = 0;
        }
        ox = part->pos[0];
        oy = part->pos[1];
        oz = part->pos[2];
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
        part->sc[0] = 0.0f;
        part->sc[1] = 0.0f;
        part->sc[2] = 0.0f;
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
    extern void fn_801213E8(void);
    M_80120A90* m = t->m;
    O* w = m->work;

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
            w->x70 = m;
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
    extern void fn_80121B1C(void);
    M_80121918* m = t->m;
    O_8012239C* w = m->work;

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
                    lbl_80346FC8[1]->cue.x18 = 1;
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
                    lbl_80346FC8[1]->cue.x18 = 1;
                    break;
                }
            }
        }
        break;
    }
    case 0x23: {
        if (in->arg != 1) {
            BtlSide* p = lbl_80346FC8[1];
            if (15.0f == o->f18c) {
                p->cue.x18 = 1;
            }
        }
        break;
    }
    case 0x1A: {
        s8 v = in->arg;
        if (v != 0) {
            f32 t;
            BtlSide* p;
            if (v == 1) {
                t = 20.0f;
            }
            if (v == 3) {
                t = 32.0f;
            }
            p = lbl_80346FC8[1];
            if (o->f18c == t) {
                p->cue.x18 = 1;
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

static inline s32 Sync_80125820(Obj_80125820* o, In_80126BF0* in) {
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

void fn_80125820(Obj_80125820* o, In_80126BF0* in) {
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
            f32 t = 1.0f + in->tab.f_b4;
            fn_80157684(&a, 1, in->tab.f_b4);
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

s32 fn_801186D8(EvObj *obj) {
    u8 type;
    Tbl_801186D8 *tbl;
    s32 j;
    s32 k;
    Task *t;
    type = (obj->hit->h24 >> 4) & 0xf;
    if (type != 1) {
        return type;
    }
    if (fn_801161B4() != 0) {
        return type;
    }
    if (obj->motionId == 2) {
        tbl = &(*(Tbl_801186D8(*)[10])&lbl_802E5078)[0];
    } else if (obj->motionId == 4 || obj->motionId == 3) {
        tbl = &(*(Tbl_801186D8(*)[10])&lbl_802E5078)[1];
    } else {
        return type;
    }
    for (j = 0; j < 2; j++) {
        if (tbl->t[j] <= obj->x18c && obj->speed + tbl->t[j] > obj->x18c && obj->x19c == 1) {
            for (k = 0; k < tbl->count; k++) {
                t = fn_801C6180(lbl_80347454, fn_8010DEE8);
                ((Spawn_801186D8 *)t->work)->xe4 = obj->ext->files->items[tbl->a[k]]->model;
                ((Spawn_801186D8 *)t->work)->x100 = &obj->ext->files->items[tbl->a[k]]->texlist;
                ((Spawn_801186D8 *)t->work)->xe8 = obj->ext->items->items[tbl->b[k]];
                if (k == 1) {
                    ((Spawn_801186D8 *)t->work)->x190 = 2.0f;
                }
                ((Spawn_801186D8 *)t->work)->x190 = 1.0f;
                ((Spawn_801186D8 *)t->work)->x38 = obj->pos.x;
                ((Spawn_801186D8 *)t->work)->x3c = obj->pos.y;
                ((Spawn_801186D8 *)t->work)->x40 = obj->pos.z;
                ((Spawn_801186D8 *)t->work)->x44 = obj->ang[0];
                ((Spawn_801186D8 *)t->work)->x48 = obj->ang[1];
                ((Spawn_801186D8 *)t->work)->x4c = obj->ang[2];
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

void fn_8010ECD8(EvObj *o)
{
    f32 t;
    fn_801165C4(o);
    o->speed = o->x164 / 1.1f;
    o->x1a8 = 0.33333334f;
    fn_801189F0(o);
    if (PlayerBusy() == 0) {
        o->x164 = fn_8010EB88(o);
    }
    if (PlayerBusy() == 0) {
        if (MemEqual(&o->pos, &o->home, 0x24) == 1 && 0.0f == o->x164) {
            lbl_8034743C = lbl_8034743C + 1;
            if (lbl_8034743C >= 5) {
                o->motionId = 0x16;
                o->x172 = 0x10;
                o->pivot = 0;
                o->pivotAng[2] = 0;
                fn_801E7414(1, o);
                lbl_8034743C = 0;
            }
        } else if (o->x164 <= lbl_8034742C) {
            o->motionId = 0x18;
            o->x172 = 0;
            o->pivot = 0;
            o->pivotAng[2] = 0;
            fn_801E7414(10, o);
            t = o->x1a0 + o->speed;
            o->x18c = t;
            if (t >= o->motion->nbFrame) {
                o->x18c = o->x18c - o->motion->nbFrame;
            }
        }
    }
}

void fn_8010F198(EvObj *o)
{
    f32 t;
    fn_801165C4(o);
    o->speed = o->x164 / 0.4f;
    o->x1a8 = 0.33333334f;
    fn_801189F0(o);
    if (PlayerBusy() == 0) {
        o->x164 = fn_8010EB88(o);
    }
    if (PlayerBusy() == 0) {
        if (MemEqual(&o->pos, &o->home, 0x24) == 1 && 0.0f == o->x164) {
            lbl_8034743C = lbl_8034743C + 1;
            if (lbl_8034743C >= 5) {
                o->motionId = 0x16;
                o->x172 = 0x10;
                fn_801E7414(1, o);
                lbl_8034743C = 0;
            }
        } else if (o->x164 > lbl_80347430) {
            o->motionId = 0x18;
            o->x172 = 0;
            fn_801E7414(10, o);
            t = o->x1a0 + o->speed;
            o->x18c = t;
            if (t >= o->motion->nbFrame) {
                o->x18c = o->x18c - o->motion->nbFrame;
            }
        }
    }
}

void fn_801115EC(EvObj *o)
{
    f32 f;

    fn_801165C4(o);
    o->x164 = 0.0f;
    o->speed = 1.0f;
    if (lbl_803474F4 >= 0x384) {
        if (fn_801161B4() == 0) {
            fn_801E7414(0xB, o);
            o->speed = 0.8f;
        } else {
            fn_801E7414(1, o);
        }
    } else {
        fn_801E7414(1, o);
    }
    if (0.0f != o->x1e0 && o->pivotAng[2] != 0) {
        if (o->x1e0 < 0.0f) {
            f = o->x1e0;
            f += 2.0;
            o->x1e0 = f;
            if (f > 0.0f) {
                o->x1e0 = 0.0f;
            }
        } else {
            f = o->x1e0;
            f -= 2.0;
            o->x1e0 = f;
            if (f < 0.0f) {
                o->x1e0 = 0.0f;
            }
        }
        o->pivotAng[2] = 182.04445f * o->x1e0;
        o->pivot = 1;
    } else {
        o->pivot = 0;
    }
    fn_801189F0(o);
    fn_8011753C(o);
    if (PlayerBusy() == 0) {
        f = fn_801D72A0(0, 10);
        if (0.0f != f && lbl_80347578 == 0) {
            o->motionId = 2;
            o->x172 = 0;
            fn_801E7414(2, o);
            o->x18c = 16.0f;
        }
    }
}

void fn_8011B448(Task_8011C858 *t) {
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
                lbl_80346EB4 = 1;
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
        lbl_80346EB4 = 0;
        break;
    }
}

static inline Spawn_8011CC74 *Mk_8011CC74(Rec_8011CC74 *rec, Task_8011C858 *t) {
    Spawn_8011CC74 *p = ((Spawn_8011CC74 *)fn_80226704((void *)((*(void **)&lbl_80347588)), (void *)(fn_8011CE6C), 0x30));
    if (p == 0) {
        return 0;
    }
    p->x24 = rec;
    p->x28 = t->work;
    p->x2c = t;
    return p;
}

void fn_8011CC74(Task_8011C858 *t) {
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

void fn_80111C38(EvObj *o) {
    Xf delta;
    Xf saved;
    s32 r;

    o->speed = 1.0f;
    MemCopy(&saved, &o->pos, 0x24);
    MemCopy(&o->pos, &o->home, 0x24);
    fn_80118AA4(o);
    fn_80119744(&delta, o, o->motion, o->x18c);
    fn_80118948(o);
    lbl_80347404 = 1;
    MemCopy(&o->pos, &saved, 0x24);
    o->pos.x = o->home.x + delta.pos.x;
    o->pos.y = o->home.y + delta.pos.y;
    o->pos.z = o->home.z + delta.pos.z;
    o->ang[0] = o->tgt[0] + delta.ang[0];
    o->ang[1] = o->tgt[1] + delta.ang[1];
    o->ang[2] = o->tgt[2] + delta.ang[2];
    switch (o->x172) {
    case 0:
        if (o->x198 == 1) {
            o->home.x = o->pos.x;
            o->home.y = o->pos.y;
            o->home.z = o->pos.z;
            o->tgt[0] = o->ang[0];
            o->tgt[1] = o->ang[1];
            o->tgt[2] = o->ang[2];
            r = fn_8010E270(o, lbl_80311970.ang[1]);
            if (r == 0) {
                fn_801E7414(0x2b, o);
            } else if (r == 2) {
                fn_801E7414(0x2c, o);
                o->motionId = 0x12;
                o->x172 = 0;
            } else {
                fn_801E7414(0x2a, o);
                o->x19c = 1;
                o->motionId = 0x13;
                o->x172 = 0;
            }
        }
        break;
    }
}

void fn_80111A78(EvObj *o)
{
    Xf d;
    u8 save[0x24];
    s32 r;

    o->speed = 1.0f;
    MemCopy(save, &o->pos, 0x24);
    MemCopy(&o->pos, &o->home, 0x24);
    fn_80118AA4(o);
    fn_80119744(&d, o, o->motion, o->x18c);
    fn_80118948(o);
    lbl_80347404 = 1;
    MemCopy(&o->pos, save, 0x24);
    o->pos.x = o->home.x + d.pos.x;
    o->pos.y = o->home.y + d.pos.y;
    o->pos.z = o->home.z + d.pos.z;
    o->ang[0] = o->tgt[0] + d.ang[0];
    o->ang[1] = o->tgt[1] + d.ang[1];
    o->ang[2] = o->tgt[2] + d.ang[2];
    switch (o->x172) {
    case 0:
        if (o->x198 == 1) {
            o->home.x = o->pos.x;
            o->home.y = o->pos.y;
            o->home.z = o->pos.z;
            o->tgt[0] = o->ang[0];
            o->tgt[1] = o->ang[1];
            o->tgt[2] = o->ang[2];
            r = fn_8010E270(o, lbl_80311970.ang[1]);
            if (r == 0) {
                fn_801E7414(0x2B, o);
                o->x19c = 1;
                o->motionId = 0x11;
                o->x172 = 0;
            } else if (r == 2) {
                fn_801E7414(0x2C, o);
                o->x19c = 1;
            } else {
                fn_801E7414(0x2A, o);
                o->x19c = 1;
                o->motionId = 0x13;
                o->x172 = 0;
            }
        }
        break;
    }
}

void fn_80111DE8(EvObj *o)
{
    Xf d;
    u8 save[0x24];
    s32 r;

    o->speed = 1.0f;
    MemCopy(save, &o->pos, 0x24);
    MemCopy(&o->pos, &o->home, 0x24);
    fn_80118AA4(o);
    fn_80119744(&d, o, o->motion, o->x18c);
    fn_80118948(o);
    lbl_80347404 = 1;
    MemCopy(&o->pos, save, 0x24);
    o->pos.x = o->home.x + d.pos.x;
    o->pos.y = o->home.y + d.pos.y;
    o->pos.z = o->home.z + d.pos.z;
    o->ang[0] = o->tgt[0] + d.ang[0];
    o->ang[1] = o->tgt[1] + d.ang[1];
    o->ang[2] = o->tgt[2] + d.ang[2];
    switch (o->x172) {
    case 0:
        if (o->x198 == 1 || o->motion == (o->ext->items->count > 0x2A ? o->ext->items->items[42] : 0)) {
            o->home.x = o->pos.x;
            o->home.y = o->pos.y;
            o->home.z = o->pos.z;
            o->tgt[0] = o->ang[0];
            o->tgt[1] = o->ang[1];
            o->tgt[2] = o->ang[2];
            r = fn_8010E270(o, lbl_80311970.ang[1]);
            if (r == 0) {
                fn_801E7414(0x2B, o);
                o->motionId = 0x11;
                o->x172 = 0;
            } else if (r == 2) {
                fn_801E7414(0x2C, o);
                o->motionId = 0x12;
                o->x172 = 0;
            } else {
                fn_801E7414(0x2A, o);
                o->x19c = 1;
            }
        }
        break;
    }
}

void fn_80113934(EvObj *o) {
    Xf delta;
    Xf saved;
    s16 stick;

    o->speed = lbl_80347424;
    MemCopy(&saved, &o->pos, 0x24);
    MemCopy(&o->pos, &o->home, 0x24);
    fn_80118AA4(o);
    fn_80119744(&delta, o, o->motion, o->x18c);
    fn_80118948(o);
    lbl_80347404 = 1;
    MemCopy(&o->pos, &saved, 0x24);
    delta.pos.x = 0.0f;
    delta.pos.z = 0.0f;
    o->pos.x = o->home.x + delta.pos.x;
    o->pos.y = o->home.y + delta.pos.y;
    o->pos.z = o->home.z + delta.pos.z;
    o->ang[0] = o->tgt[0] + delta.ang[0];
    o->ang[1] = o->tgt[1] + delta.ang[1];
    o->ang[2] = o->tgt[2] + delta.ang[2];
    if (o->x198 == 1) {
        o->home.x = o->pos.x;
        o->home.y = o->pos.y;
        o->home.z = o->pos.z;
        o->tgt[0] = o->ang[0];
        o->tgt[1] = o->ang[1];
        o->tgt[2] = o->ang[2];
        stick = lbl_80311A60[0]->y;
        if (stick <= -10) {
            fn_801E7414(0x1b, o);
            SePlay(0xf, 5, 0x1b);
            o->x18c = lbl_80347424;
        } else if (stick >= 10) {
            fn_801E7414(0x1c, o);
            SePlay(0xf, 5, 0x1b);
            o->x18c = lbl_80347424;
        } else {
            fn_801E7414(0x1d, o);
            o->motionId = 8;
            o->x172 = 0;
        }
    }
}

s32 fn_8010E270(EvObj *o, Angle base) {
    f32 a;
    s32 ang;
    Angle turn;
    f32 yy = -lbl_80311A60[0]->y;
    f32 xx = lbl_80311A60[0]->x;

    a = atan2(yy, xx);
    turn = 10430.381f * a;
    ang = (o->ang[1] - base - 0x4000 - turn) & 0xFFFF;
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

extern NJS_POINT3 lbl_80305D98;
extern NJS_POINT3 lbl_80305DA4;
extern f32 lbl_80346E6C;

s32 fn_8010E41C(f32 *pos, Angle *ang, f32 *at) {
    NJS_MATRIX m;
    NJS_POINT3 p;
    NJS_POINT3 d;
    s32 yaw;
    s32 r;

    njUnitMatrix(m);
    njRotateXYZ(m, ang[0], ang[1], ang[2]);
    d.x = 0.0f;
    d.y = 0.0f;
    d.z = 4.0f;
    njCalcPoint(m, &d, &p);
    d.x = at[0] - (lbl_80305DA4.x = p.x + (lbl_80305D98.x = pos[0]));
    d.y = at[1] - (lbl_80305DA4.y = p.y + (lbl_80305D98.y = pos[1]));
    d.z = at[2] - (lbl_80305DA4.z = p.z + (lbl_80305D98.z = pos[2]));
    r = fn_801DD4C4(d.x, d.z);
    yaw = (u16)(r - ang[1] + 0x8000);
    lbl_80346E6C = 0.005493164f * (f32)yaw;
    if (yaw < 0x2aaa || yaw >= 0x10000 - 0x2aab) {
        r = 0;
    } else if (yaw >= 0x2aaa && yaw < 0x4000) {
        r = 1;
    } else if (yaw >= 0x471c && yaw < 0x10000 - 0x471d) {
        r = 2;
    } else if (yaw >= 0x10000 - 0x471d && yaw < 0x10000 - 0x2aab) {
        r = 3;
    }
    return r;
}

s32 fn_801157E4(f32 *out, f32 *from, f32 *to, void *a) {
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
    EvColl *res;
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
        res = lbl_80347450->coll;
        save = res->pos;
        res->pos = p;
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
        res->pos = save;
    }
    return r;
}

void fn_8011605C(int idx) {
    CharCfg *cfg = &lbl_802E54B0[idx];
    MemCopy(lbl_8030A35C, cfg, 0x24);
    if (lbl_80347450->res != 0) {
        fn_80222964(lbl_80347450->res);
        fn_801E1784(lbl_80347450->res);
        lbl_80347450->res = 0;
    }
    MemCopy(lbl_80305E18, cfg->b, 0x60);
    lbl_80347450->res = fn_80222224(lbl_80305E18);
    lbl_80347450->res->mask10 = 0x8000;
    lbl_80347450->res->id12 = 0x2f;
    lbl_80347450->res->w8 = lbl_80347450->ext->x04;
    lbl_80347450->res->pos[0] = lbl_80347450->pos.x;
    lbl_80347450->res->pos[1] = lbl_80347450->pos.y;
    lbl_80347450->res->pos[2] = lbl_80347450->pos.z;
    lbl_80347450->res->ang[0] = lbl_80347450->ang[0];
    lbl_80347450->res->ang[1] = lbl_80347450->ang[1];
    lbl_80347450->res->ang[2] = lbl_80347450->ang[2];
    fn_80222838(lbl_80347450->res);
}

void fn_8011D2D8(Task_8011D2D8 *t) {
    VertexTex v[4];
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

static inline void VecCopy_80124634(NJS_POINT3* d, NJS_POINT3* s) {
    f32 z, y, x;
    x = s->x;
    y = s->y;
    z = s->z;
    d->z = z;
    d->y = y;
    d->x = x;
}

static inline void VecAdd_801237EC(NJS_POINT3* d, NJS_POINT3* a, NJS_POINT3* b) {
    NJS_POINT3 t, u;
    VecCopy_80124634(&t, a);
    VecCopy_80124634(&u, b);
    d->z = t.z + u.z;
    d->y = t.y + u.y;
    d->x = t.x + u.x;
}

static inline void VecSub_801237EC(NJS_POINT3* d, NJS_POINT3* a, NJS_POINT3* b) {
    NJS_POINT3 t, u;
    VecCopy_80124634(&t, a);
    VecCopy_80124634(&u, b);
    d->z = t.z - u.z;
    d->y = t.y - u.y;
    d->x = t.x - u.x;
}

static inline f32 VecLen_801237EC(NJS_POINT3* v) {
    f32 xx = v->x * v->x;
    f32 yy = v->y * v->y;
    f32 zz = v->z * v->z;
    return sqrtf((f32)fabs(xx + yy + zz));
}

/* the 0x744 record behind x25c of the object fn_80123A44 runs: three rings of 50 points */
typedef struct Ring_801237EC {
    NJS_POINT3 pts[50];
    NJS_POINT3 ring[50];
    NJS_POINT3 zero[50];
    NJS_POINT3 org;
    u8 _714[0xc];
    NJS_POINT3 last;
    NJS_POINT3 org2;
    f32 len;
    s32 f73c;
    s32 f740;
} Ring_801237EC;

void fn_801237EC(EvObj* m) {
    f32 ang = 0.0f;
    f32 zero = ang;
    NJS_POINT3 d;
    NJS_POINT3* dp;
    NJS_POINT3* p;
    NJS_POINT3* r1;
    NJS_POINT3* r2;
    Ring_801237EC* w;
    s32 i = 0;

    w = m->x25c;
    p = w->pts;
    r1 = w->ring;
    r2 = w->zero;

    w->f740 = 0;
    w->f73c = 0;
    m->x20c = -1;
    m->x210 = -1;
    w->org2.x = 5.0f;
    w->org2.y = 15.0f;
    w->org2.z = 10.0f;
    VecCopy_80124634(&w->org, &w->org2);
    for (; i < 50; i++) {
        ang += 0.3926875f;
        p->x = 5.0 * cos(ang);
        p->y = -10.0f;
        p->z = 5.0 * sin(ang);
        VecAdd_801237EC(p, p, &w->org);
        VecCopy_80124634(r1, p);
        p++;
        r1++;
        r2->x = zero;
        r2->y = zero;
        r2->z = zero;
        r2++;
    }
    VecCopy_80124634(&w->last, &w->pts[49]);
    dp = &d;
    VecSub_801237EC(dp, &w->pts[1], &w->pts[0]);
    w->len = VecLen_801237EC(dp);
    m->scl.y = w->len;
    m->texlist = m->ext->texlist;
}

void fn_80126F70(Obj_80126BF0* o, In_80126BF0* in) {
    s32 f;
    s8 sel;
    s32 up, down, cap;
    FormTbl* t;
    FormRec* r;

    f = in->f5;
    t = &in->tab;
    sel = t->e[in->b17].id;
    r = &t->r[in->b11];
    up = r->b[1];
    down = r->b[2];
    cap = r->b[4];

    if (f == sel && (in->h0e & 1)) {
        return;
    }
    if (f == sel && (in->h0e & 4)) {
        in->h0c--;
        if (in->h0c <= 0) {
            in->h0c = 0;
            in->h0e = 0;
        }
        return;
    }
    if ((in->b10 & 0x7f) == 0) {
        return;
    }
    if (f == up) {
        if (in->h0c < (u8)cap) {
            in->h0c++;
        }
    } else if (f == down) {
        if (in->h0c > 0) {
            in->h0c--;
        }
    }
}

extern void* fn_8008F8FC(void* o, s32 i);
extern void fn_8020EF30(s32 id);

void fn_80124634(Obj2_80124634* o, In_80124634* in) {
    s8 idx;
    Own_80124634* own;
    switch (in->kind) {
    case 0x18: {
        NJS_POINT3 saved;
        NJS_POINT3* ps = &saved;
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
        if (lbl_80310A1C[0xC0] == 1) {
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
                    Own_80124634* own = o->own;
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
                        Tbl_80124634* t;
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
        Rec_80125820 rec;
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

int fn_80118204(EvObj *c) {
    EvColl *r;
    EvColl *r2;
    int result;

    if ((lbl_80310B3C[0x21] & 0x80000000) == 0 && fn_8009763C() != 12 && lbl_80347508 != 1) {
        r = c->coll;
        if (lbl_80347404 == 0) {
            r->pos = &c->pos.x;
            r->ang = c->ang;
            r->pivotPos = 0;
            r->pivotAng = 0;
        } else {
            r->pos = &c->pos.x;
            r->ang = c->ang;
            r->pivotPos = &c->pivotPos.x;
            r->pivotAng = c->pivotAng;
        }
        fn_80222838(r);
        result = fn_80117BE4(0, c, r);
        if ((lbl_80311A60[0]->x8 & 0x100) && fn_8011768C() == 0) {
            r2 = c->res;
            r2->pos[0] = c->pos.x;
            r2->pos[1] = c->pos.y;
            r2->pos[2] = c->pos.z;
            r2->ang[0] = c->ang[0];
            r2->ang[1] = c->ang[1];
            r2->ang[2] = c->ang[2];
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
void fn_8011A960(NJS_POINT3 *out, NJS_POINT3 *a, NJS_POINT3 *b) {
    f32 ax = a->x, ay = a->y, az = a->z;
    f32 bx = b->x, by = b->y, bz = b->z;
    out->z = az - bz;
    out->y = ay - by;
    out->x = ax - bx;
}

void fn_80117B9C(EvObj *obj)
{
    s32 z = 0;
    obj->pivot = z;
    obj->pivotPos.x = obj->pivotPos.y = obj->pivotPos.z = (f32)(obj->pivotAng[0] = obj->pivotAng[1] = obj->pivotAng[2] = z);
}

extern f32 lbl_80347410;
extern u16 lbl_80347478;
extern s32 lbl_8034747C;
extern f32 lbl_80347480;
extern f32 lbl_80347484;
extern f32 lbl_80347488;
extern s32 lbl_80347448;
void fn_80119850(EvObj *obj) {
    CharCfg *row;
    obj->slots = fn_801E1C7C(0x18);
    lbl_80347438 = lbl_802E54B0[fn_801161B4()].fa0;
    lbl_80347434 = lbl_802E54B0[fn_801161B4()].f94;
    lbl_80347428 = lbl_802E54B0[fn_801161B4()].f94;
    lbl_8034742C = lbl_802E54B0[fn_801161B4()].f98;
    row = &lbl_802E54B0[fn_801161B4()];
    lbl_80347430 = row->f9c;
    lbl_80347420 = 4.0f;
    lbl_80347424 = 1.0f;
    obj->motionId = 1;
    obj->x172 = 0;
    lbl_80347444 = 0;
    fn_801E7414(1, obj);
    obj->x1a8 = 0.2f;
    fn_801173DC(1, obj);
    obj->kind = 0;
    lbl_8034743C = 0;
    obj->ang[2] = 0;
    obj->ang[0] = 0;
    if (3.4028235e38f != lbl_80347488) {
        obj->pos.x = lbl_80347488;
        obj->pos.y = lbl_80347484;
        obj->pos.z = lbl_80347480;
        obj->ang[1] = 0.005493164f * (f32)lbl_8034747C;
    }
    fn_8011605C(fn_801161B4());
    obj->hit = fn_802258BC(0xffff, 0xffff, 0);
    if (lbl_80347478 != 0x7fffffff) {
        if (3.4028235e38f != lbl_80347488) {
            fn_80225930(0xffff, lbl_80347478, obj->hit);
        }
    }
    lbl_80347400 = 0;
    lbl_80347448 = 0;
    lbl_80347410 = 0.0f;
    lbl_80347440 = 0;
}

typedef struct PlayerSnap {
    u8 pad0[0x38];
    NJS_POINT3 pos;
    Angle ang[3];
} PlayerSnap;
extern PlayerSnap lbl_8030A794;
extern s32 lbl_803475B0;
extern void fn_80097660(void);
extern void fn_80090EE8(s32 a);
extern void fn_801CB738(void);

static inline EvObj *Player_80119FF4(Task *t) {
    return t->work;
}

void fn_80119FF4(Task *self) {
    s32 i;
    ModelFile *p;
    NJS_TEXLIST *tl;
    lbl_80347454 = self;
    lbl_80347450 = self->work;
    switch (self->state) {
    case 0:
    case 0xfe:
        fn_8009766C();
        fn_80227810(Player_80119FF4(self)->texlist);
        for (i = 1; i < 8; i++) {
            p = Player_80119FF4(self)->ext->files->items[i];
            if (p != 0) {
                tl = &p->texlist;
                if (tl != 0) {
                    fn_80227810(tl);
                }
            }
        }
        fn_80119850(Player_80119FF4(self));
        fn_8015ED90(self);
        fn_8015EB8C(Player_80119FF4(self), 0xd, fn_80119E50);
        self->state = 2;
        break;
    case 1:
    case 2:
        if (lbl_80311AC0.map == 0x83 && lbl_80311AC0.sub == 0x65 && lbl_803475B0 != 0) {
            return;
        }
        if (lbl_80311AC0.map == 0) {
            fn_80090EE8(0);
        }
        lbl_80347408 = 1;
        lbl_803473EC = 1;
        if (fn_8015E600(Player_80119FF4(self)) != 0) {
            fn_801CB738();
            fn_8009574C();
            lbl_80347440 = -1;
        } else {
            if (lbl_80347440 != -1) {
                lbl_80347408 = 0;
                lbl_803473EC = 0;
            }
            fn_8011622C(lbl_80347400);
            fn_80119AF4(self);
            lbl_8030A794.pos.x = Player_80119FF4(self)->pos.x;
            lbl_8030A794.pos.y = Player_80119FF4(self)->pos.y;
            lbl_8030A794.pos.z = Player_80119FF4(self)->pos.z;
            lbl_8030A794.ang[0] = Player_80119FF4(self)->ang[0];
            lbl_8030A794.ang[1] = Player_80119FF4(self)->ang[1];
            lbl_8030A794.ang[2] = Player_80119FF4(self)->ang[2];
            if (lbl_80347440 == -1) {
                lbl_80347440 = 0;
            }
        }
        break;
    case 0xff:
        if (lbl_803473FC != 0) {
            lbl_80347400 = 0x7fffffff;
            fn_8011622C(lbl_80347400);
        }
        fn_8015EBF4(Player_80119FF4(self));
        fn_802275A4(Player_80119FF4(self)->texlist, 0);
        for (i = 1; i < 9; i++) {
            p = Player_80119FF4(self)->ext->files->items[i];
            tl = &p->texlist;
                if (tl != 0) {
                fn_802275A4(tl, 0);
            }
        }
        fn_80222964(Player_80119FF4(self)->res);
        fn_801E1784(Player_80119FF4(self)->res);
        Player_80119FF4(self)->res = 0;
        fn_801E1784(Player_80119FF4(self)->hit);
        fn_801E17E0(Player_80119FF4(self)->slots);
        if (Player_80119FF4(self)->texlist != 0) {
            fn_802275A4(Player_80119FF4(self)->texlist, 0);
        }
        fn_80097660();
        fn_80100B74(self);
        lbl_80347450 = 0;
        break;
    }
}

void fn_8012A900(Arg_8012A900 *p)
{
    fn_801D5DD8(p->x0, 1.0f, 1.0f, p->x4, p->x8, p->xc, p->x10, p->x14, p->x18, (*(Obj_8012A900 **)&lbl_80346EF8)->x4->x20);
}

void fn_8012A954(Arg_8012A900 *p)
{
    fn_801D5DD8(p->x0, 1.0f, 1.0f, p->x4, p->x8, p->xc, p->x10, p->x14, p->x18, (*(Obj_8012A900 **)&lbl_80346EF4)->x4->x20);
}

void fn_8012A9A8(Arg_8012A900 *p)
{
    fn_801D5DD8(p->x0, 1.0f, 1.0f, p->x4, p->x8, p->xc, p->x10, p->x14, p->x18, (*(Obj_8012A900 **)&lbl_80346EF0)->x4->x20);
}

extern void fn_8020F278(s32 a, s32 b, s32 c, f32 *p, f32 *q);

s32 fn_8011D958(Ctx_8011DD9C *c, Sub *s, s32 a) {
    Hdr *h = c->cfg->hdr;
    Col_8011FC10 col;
    if (a == 0) {
        Big *b;
        f32 *p = h->x2c;
        s->flags = 0;
        fn_8020F278(h->w24, h->x28, c->u17a + c->x1dc, p, p + 3);
        s->x24 = h->x38.x4;
        s->x28 = h->x38.x8;
        s->x2c = s->x24 + s->x28;
        b = fn_801E1A2C(1, s->x2c * 0x60);
        if (b == NULL) {
            return 0;
        }
        s->p88 = b;
    } else {
        s->flags &= ~0x1fff;
    }
    s->xc = h->x38.xc;
    s->col[0][1] = h->x38.x10;
    s->col[0][2] = h->x38.x14;
    s->col[0][3] = h->x38.x18;
    s->col[0][0] = h->x54;
    s->x10 = h->x58;
    s->col[1][1] = h->x5c;
    s->col[1][2] = h->x60;
    s->col[1][3] = h->x64;
    s->col[1][0] = h->x68;
    s->x14 = h->x6c;
    s->col[2][1] = h->x70;
    s->col[2][2] = h->x74;
    s->col[2][3] = h->x78;
    s->col[2][0] = h->x7c;
    s->x34 = h->x84;
    s->x38 = h->x88;
    s->x30 = 1.0f / (1.0f + s->x34);
    s->x40 = -1.0f / h->x94;
    s->x3c = h->x80;
    s->x58[0].x = 0.0f;
    s->x58[0].y = 0.0f;
    s->x58[1].x = 30.0f;
    s->x58[1].y = (f32)h->xe4;
    s->x58[2].x = 50.0f;
    s->x58[2].y = (f32)h->xe8;
    s->x58[3].x = 100.0f;
    s->x58[3].y = 100.0f;
    s->x54 = h->xb4;
    s->x56 = h->xb8;
    s->x44 = h->x9c;
    s->x48 = h->xa0;
    s->x50 = h->xf0;
    s->x4.x = 320.0f;
    s->x4.y = 240.0f;
    switch (h->x8c) {
    case 1:
        s->flags |= 2;
        break;
    case 2:
        s->flags |= 4;
        break;
    case 3:
        s->flags |= 8;
        break;
    }
    if (h->x90 != 0) s->flags |= 0x10;
    if (h->x98 != 0) s->flags |= 0x20;
    if (h->xa4 != 0) s->flags |= 0x40;
    if (h->xa8 != 0) s->flags |= 0x80;
    if (h->xac != 0) s->flags |= 0x1000000;
    if (h->xb0 != 0) s->flags |= 1;
    if (h->xbc != 0) s->flags |= 0x100;
    if (h->xd4 != 0) s->flags |= 0x200;
    if (h->xdc != 0) s->flags |= 0x400;
    if (h->xe0 != 0) s->flags |= 0x800;
    if (h->xec != 0) s->flags |= 0x1000;
    {
        TexA *ta = c->cfg->x20;
        TexC *tc = (ta != NULL ? ta->x0->x8 : NULL);
        s->x80 = tc->xc[0];
    }
    s->xcc = h->xd0;
    s->x8c.g[1].a[0] = 0.0f;
    s->x8c.g[0].a[0] = 0.0f;
    s->x8c.g[2].a[1] = 0.0f;
    s->x8c.g[0].a[1] = 0.0f;
    s->x8c.g[3].a[0] = 640.0f;
    s->x8c.g[2].a[0] = 640.0f;
    s->x8c.g[3].a[1] = 480.0f;
    s->x8c.g[1].a[1] = 480.0f;
    {
        f32 z = s->xcc;
        s->x8c.g[3].a[2] = z;
        s->x8c.g[2].a[2] = z;
        s->x8c.g[1].a[2] = z;
        s->x8c.g[0].a[2] = z;
    }
    col.b[2] = h->xc0;
    col.b[1] = h->xc4;
    col.b[0] = h->xc8;
    col.b[3] = s->xd0 = h->xcc;
    s->x8c.g[3].n = col.u;
    s->x8c.g[2].n = col.u;
    s->x8c.g[1].n = col.u;
    s->x8c.g[0].n = col.u;
    if (s->flags & 0x200) {
        s->xd4 = h->xd8 & 0xff;
    } else {
        s->xd4 = 0;
    }
    return 1;
}

void fn_8011DD9C(Obj_8011DD9C *self) {
    Ctx_8011DD9C *c = self->ctx;
    Sub *sub = c->sub;
    if (self->flags & 0x20) self->state = 0xff;
    switch (self->state) {
    case 0:
        if ((*(void **)&lbl_80346EB8) == 0) {
            (*(void **)&lbl_80346EB8) = OSAllocFromHeapClear(lbl_80346720, 2000);
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

void fn_801213F0(O *o, Ctx_8011DD9C *a) {
    s32 s;
    s32 idx;
    s32 t;
    u16 id;
    Ctx_8011DD9C *r31;
    B *b = a->x1e4;
    NJS_POINT3 *ap;
    NJS_POINT3 *w;
    Ctx_8011DD9C *p6c;
    Ctx_8011DD9C *p68;
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
    o->x60 = &b->ent[idx];
    r31 = b->x10->x24;
    o->x5c = r31;
    o->x64 = &r31->cfg->hdr->x38.x4;
    s = (s32)(0.1f * fn_8011A8B0(&r31->pos, ap) + 1.0f);
    if (s > 50) s = 50;
    w = &o->x24.pos;
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
        NJS_POINT3 v;
        fn_801575C8(w, fn_80156A8C(r31->u17a), (f32)s);
        fn_8011A960(&v, w, ap);
        fn_801DD5E8(&o->x68->ax, &v);
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

static inline void place(O *o) {
    NJS_MATRIX m;
    Ctx_8011DD9C *h;
    Ctx_8011DD9C *t;
    t = o->x5c;
    h = o->x6c;
    njUnitMatrix(m);
    njTranslate(m, t->pos.x, t->pos.y, t->pos.z);
    njRotateZXY(m, t->ax, t->ay, t->az);
    njTranslate(m, o->x48.x, o->x48.y, o->x48.z);
    njGetTranslation(m, &h->pos);
}

#define RF (3.0517578125e-05f * (f32)rand())
void fn_80120C64(O *o, Ctx_8011DD9C *p) {
    View_80120C64 view;
    NJS_MATRIX m;
    Rec_80125820 ra;
    Rec_80125820 r1;
    Rec_80125820 r0;
    Angle ang[3];
    NJS_POINT3 diff;
    s32 kind;
    Pose_80120C64 *w = &o->x24;
    View_80120C64 *v = &view;
    s8 k;
    Corner_80120C64 *r;
    s32 d;
    s32 id;
    f32 x, y;
    f32 f;
    d = w->ang[1] - p->ay;
    if (d >= 0x8000) {
        do { d -= 0x10000; } while (d >= 0x8000);
    } else if (d < -0x8000) {
        do { d += 0x10000; } while (d < -0x8000);
    }
    id = *o->x64;
    fn_801545EC(o->v, v);
    k = fn_80153DA8(o->v) & 3;
    kind = fn_801243EC(id);
    if (kind != 0) k = 2;
    o->x58 = v;
    if (o->flags & 0x100) {
        njUnitMatrix(m);
        njTranslate(m, w->pos.x, w->pos.y, w->pos.z);
        njRotateZXY(m, w->ang[0], w->ang[1], w->ang[2]);
        if (k == 0) {
            o->x54 = &v->q[2];
            r = o->x54;
            o->x48.x = o->x58->x8;
            {
                f32 t = r->b;
                o->x48.y = -t + (t + r->a) * RF;
            }
            {
                f32 t = r->d;
                o->x48.z = -t + (t + r->c) * RF;
            }
            o->x10 = 1;
            if (o->x48.y > 0.0f) rand(); else rand();
            if (o->x48.z > 0.0f) rand(); else rand();
        }
        if (k == 1) {
            o->x54 = &v->q[3];
            r = o->x54;
            o->x48.x = -o->x58->xc;
            {
                f32 t = r->b;
                o->x48.y = -t + (t + r->a) * RF;
            }
            {
                f32 t = r->c;
                o->x48.z = -t + (t + r->d) * RF;
            }
            o->x10 = 2;
            if (o->x48.y > 0.0f) rand(); else rand();
            if (o->x48.z > 0.0f) rand(); else rand();
        }
        if (k == 2) {
            o->x54 = &v->q[0];
            r = o->x54;
            {
                f32 t = r->c;
                o->x48.x = -t + (t + r->d) * RF;
            }
            {
                f32 t = r->b;
                o->x48.y = -t + (t + r->a) * RF;
            }
            o->x48.z = o->x58->x0;
            o->x10 = 3;
            if (o->x48.y > 0.0f) rand(); else rand();
            if (o->x48.z > 0.0f) rand(); else rand();
        }
        if (k == 3) {
            o->x54 = &v->q[1];
            r = o->x54;
            {
                f32 t = r->d;
                o->x48.x = -t + (t + r->c) * RF;
            }
            {
                f32 t = r->b;
                o->x48.y = -t + (t + r->a) * RF;
            }
            o->x48.z = -o->x58->x4;
            o->x10 = 4;
            if (o->x48.y > 0.0f) rand(); else rand();
            if (o->x48.z > 0.0f) rand(); else rand();
        }
        if ((o->x10 == 3) | (o->x10 == 4)) {
            o->x48.x += (o->x58->x8 - o->x58->xc) / 2.0f;
        }
        if ((o->x10 == 1) | (o->x10 == 2)) {
            o->x48.z += (o->x58->x0 - o->x58->x4) / 2.0f;
        }
        o->x48.y += o->x58->x10;
        if (kind == 1) {
            s32 n = o->x8;
            fn_80157684(&ra, 1, (f32)n);
            fn_801264A4(&r0, 0, (f32)n);
            fn_801264A4(&r1, 1, (f32)n);
            diff.x = r0.pos[0] - r1.pos[0];
            diff.y = r0.pos[1] - r1.pos[1];
            diff.z = r0.pos[2] - r1.pos[2];
            fn_801D9634(&diff, ang);
            njTranslate(m, ra.pos[0], ra.pos[1], ra.pos[2]);
            njRotateZXY(m, ang[0], ang[1], ang[2]);
            njTranslate(m, o->x48.x, o->x48.y, o->x48.z);
        }
        if (kind == 2) {
            f32 z;
            x = o->x48.x;
            y = o->x48.y;
            if (fn_80153DA8(o->v) == 3) z = -o->x58->x4; else z = o->x48.z;
            njTranslate(m, x, y, z);
        }
        if (kind == 0) {
            njTranslate(m, o->x48.x, o->x48.y, o->x48.z);
        }
        njGetTranslation(m, &w->pos);
    } else {
        f = 5.0f * RF - 2.5f;
        if (k == 0) { o->x54 = &v->q[2]; o->x10 = 1; }
        if (k == 1) { o->x54 = &v->q[3]; o->x10 = 2; }
        if (k == 2) { o->x54 = &v->q[0]; o->x10 = 3; }
        if (k == 3) { o->x54 = &v->q[1]; o->x10 = 4; }
        r = o->x54;
        if (f >= 0.0f) f = 1.5f * r->a + f;
        else f = f - 1.5f * r->b;
        w->pos.y = w->pos.y + f;
    }
}

void fn_80121B24(O_8012239C *o, Ctx_8011DD9C *p) {
    View_80120C64 view;
    NJS_MATRIX m;
    Rec_80125820 ra;
    Rec_80125820 r1;
    Rec_80125820 r0;
    Angle ang[3];
    NJS_POINT3 diff;
    s32 kind;
    Pose_80120C64 *w = &o->x38;
    View_80120C64 *v = &view;
    s8 k;
    Corner_80120C64 *r;
    s32 d;
    s32 id;
    f32 x, y;
    f32 f;
    d = w->ang[1] - p->ay;
    if (d >= 0x8000) {
        do { d -= 0x10000; } while (d >= 0x8000);
    } else if (d < -0x8000) {
        do { d += 0x10000; } while (d < -0x8000);
    }
    id = *o->x78;
    fn_801545EC(o->v, v);
    k = fn_80153DA8(o->v) & 3;
    kind = fn_801243EC(id);
    if (kind != 0) k = 2;
    o->x60 = v;
    if (o->flags & 1) {
        njUnitMatrix(m);
        njTranslate(m, w->pos.x, w->pos.y, w->pos.z);
        njRotateZXY(m, w->ang[0], w->ang[1], w->ang[2]);
        if (k == 0) {
            o->x5c = &v->q[2];
            r = o->x5c;
            o->ox.x = o->x60->x8;
            {
                f32 t = r->b;
                o->ox.y = -t + (t + r->a) * RF;
            }
            {
                f32 t = r->d;
                o->ox.z = -t + (t + r->c) * RF;
            }
            o->x10 = 1;
            if (o->ox.y > 0.0f) rand(); else rand();
            if (o->ox.z > 0.0f) rand(); else rand();
        }
        if (k == 1) {
            o->x5c = &v->q[3];
            r = o->x5c;
            o->ox.x = -o->x60->xc;
            {
                f32 t = r->b;
                o->ox.y = -t + (t + r->a) * RF;
            }
            {
                f32 t = r->c;
                o->ox.z = -t + (t + r->d) * RF;
            }
            o->x10 = 2;
            if (o->ox.y > 0.0f) rand(); else rand();
            if (o->ox.z > 0.0f) rand(); else rand();
        }
        if (k == 2) {
            o->x5c = &v->q[0];
            r = o->x5c;
            {
                f32 t = r->c;
                o->ox.x = -t + (t + r->d) * RF;
            }
            {
                f32 t = r->b;
                o->ox.y = -t + (t + r->a) * RF;
            }
            o->ox.z = o->x60->x0;
            o->x10 = 3;
            if (o->ox.y > 0.0f) rand(); else rand();
            if (o->ox.z > 0.0f) rand(); else rand();
        }
        if (k == 3) {
            o->x5c = &v->q[1];
            r = o->x5c;
            {
                f32 t = r->d;
                o->ox.x = -t + (t + r->c) * RF;
            }
            {
                f32 t = r->b;
                o->ox.y = -t + (t + r->a) * RF;
            }
            o->ox.z = -o->x60->x4;
            o->x10 = 4;
            if (o->ox.y > 0.0f) rand(); else rand();
            if (o->ox.z > 0.0f) rand(); else rand();
        }
        if ((o->x10 == 3) | (o->x10 == 4)) {
            o->ox.x += (o->x60->x8 - o->x60->xc) / 2.0f;
        }
        if ((o->x10 == 1) | (o->x10 == 2)) {
            o->ox.z += (o->x60->x0 - o->x60->x4) / 2.0f;
        }
        o->ox.y += o->x60->x10;
        if (kind == 1) {
            s32 n = o->x8;
            fn_80157684(&ra, 1, (f32)n);
            fn_801264A4(&r0, 0, (f32)n);
            fn_801264A4(&r1, 1, (f32)n);
            diff.x = r0.pos[0] - r1.pos[0];
            diff.y = r0.pos[1] - r1.pos[1];
            diff.z = r0.pos[2] - r1.pos[2];
            fn_801D9634(&diff, ang);
            njTranslate(m, ra.pos[0], ra.pos[1], ra.pos[2]);
            njRotateZXY(m, ang[0], ang[1], ang[2]);
            njTranslate(m, o->ox.x, o->ox.y, o->ox.z);
        }
        if (kind == 2) {
            f32 z;
            x = o->ox.x;
            y = o->ox.y;
            if (fn_80153DA8(o->v) == 3) z = -o->x60->x4; else z = o->ox.z;
            njTranslate(m, x, y, z);
        }
        if (kind == 0) {
            njTranslate(m, o->ox.x, o->ox.y, o->ox.z);
        }
        njGetTranslation(m, &w->pos);
    } else {
        f = 10.0f * RF - 5.0f;
        if (k == 0) { o->x5c = &v->q[2]; o->x10 = 1; }
        if (k == 1) { o->x5c = &v->q[3]; o->x10 = 2; }
        if (k == 2) { o->x5c = &v->q[0]; o->x10 = 3; }
        if (k == 3) { o->x5c = &v->q[1]; o->x10 = 4; }
        r = o->x5c;
        if (f >= 0.0f) f = 1.5f * r->a + f;
        else f = f - 1.5f * r->b;
        w->pos.y = w->pos.y + f;
    }
}

s32 fn_80121680(M_80120A90 *m) {
    Ctx_8011DD9C *g = fn_8015F180();
    O *o;
    Ent *ent;
    NJS_POINT3 *w;
    if (g->p1d8->x4->state != 2) return 0;
    o = m->work;
    if (o == NULL) return 0;
    if (!(o->flags & 1)) {
        fn_801213F0(o, g);
        return 0;
    }
    w = &o->x24.pos;
    ent = o->x60;
    o->x4++;
    if (o->flags & 2) {
        if (o->x4 >= 0x3c) o->flags |= 0x80000000;
        place(o);
        goto done;
    }
    if (o->flags & 0x100) {
        if (o->x4 >= o->x8) {
            o->x4 = 0;
            ent->x14++;
            ent->x18--;
            o->x70->f1ef = 1;
            if (!(o->flags & 0x20000)) {
                o->flags |= 2;
                fn_8020EF30(o->x14);
                fn_8020EFD4(o->x16);
                place(o);
            } else {
                o->flags |= 0x80000000;
                fn_8020EF30(o->x14);
            }
        }
    } else {
        if (o->x4 >= o->x8 + 0x1e) {
            o->x4 = 0;
            o->flags |= 0x80000000;
            fn_8020EF30(o->x14);
            o->x70->f1ef = 1;
        }
    }
    if (!(o->flags & 0x10000)) {
        fn_80120A50(&o->x68->pos.x, &o->pos.x, &w->x, (f32)o->x4 / (f32)o->x8);
    }
done:
    return 1;
}

static inline Inner_80123A44 *Info_80123A44(EvObj *q) {
    return q->ext->info;
}

void fn_80123A44(Task *p) {
    EvObj *q = p->work;
    Inner_80123A44 *in;
    switch (p->state) {
    case 0:
    case 0xfe:
        q->x25c = fn_801E1A2C(1, 0x744);
        fn_801237EC(q);
        lbl_803473AC = 0;
        q->x26c = 1;
        fn_8015ED90((void *)(p));
        in = Info_80123A44(q);
        if (in->x0 < 0x16) {
            p->state = 4;
            break;
        }
        q->x20c = in->x24;
        q->x210 = Info_80123A44(q)->x38;
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
        in = Info_80123A44(q);
        if (in->x0 >= 0x16) {
            p->state = 1;
            q->x20c = Info_80123A44(q)->x24;
            q->x210 = Info_80123A44(q)->x38;
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

u8 fn_801285D8(FormTbl *t) {
    u8 ids[2] = { 0, 1 };
    u8 a0[3] = { 1, 0x29, 0 };
    u8 a1[2] = { 0, 1 };
    s32 i;
    for (i = 0; i < 2; i++) {
        t->e[i].id = ids[i];
    }
    for (i = 0; i < 3; i++) {
        t->e[0].d[i] = a0[i];
    }
    for (i = 0; i < 2; i++) {
        t->e[1].d[i] = a1[i];
    }
    t->b_ac = 0x14;
    t->b_ad = 0x15;
    t->f_b0 = 31.0f;
    t->f_b4 = 40.0f;
    t->f_bc = 41.0f;
    t->f_c0 = 1.0f;
    t->f_c4 = 1.0f;
    return 2;
}

u8 fn_80128414(FormTbl *t) {
    u8 ids[3] = { 0, 1, 2 };
    u8 a0[1] = { 0 };
    u8 a1[3] = { 0, 3, 1 };
    u8 a2[3] = { 1, 4, 2 };
    s32 i;
    for (i = 0; i < 3; i++) {
        t->e[i].id = ids[i];
    }
    for (i = 0; i < 1; i++) {
        t->e[0].d[i] = a0[i];
    }
    for (i = 0; i < 3; i++) {
        t->e[1].d[i] = a1[i];
    }
    for (i = 0; i < 3; i++) {
        t->e[2].d[i] = a2[i];
    }
    t->f_b0 = 31.0f;
    t->f_b4 = 40.0f;
    t->f_bc = 41.0f;
    t->f_c0 = 1.0f;
    t->f_c4 = 1.0f;
    return 3;
}

u8 fn_8012813C(FormTbl *t) {
    u8 a[1] = { 0 };
    u8 b[1] = { 0 };
    u8 c[6] = { 0, 0, 0, 0, 0, 0 };
    s32 i;
    t->e[0].id = a[0];
    t->e[0].d[0] = b[0];
    for (i = 0; i < 6; i++) {
        t->r[0].b[i] = c[i];
    }
    t->r[0].h6 = 100;
    t->r[0].w0c = 0x2904;
    t->r[0].h12 = 90;
    t->r[0].h8 = 60;
    t->f_b0 = 31.0f;
    t->f_b4 = 40.0f;
    t->f_bc = 41.0f;
    t->f_c0 = 1.0f;
    t->f_c4 = 1.0f;
    return 1;
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

void fn_8010E5BC(EvObj *o) {
    NJS_POINT3 pt[3];
    EvHit hit;
    NJS_POINT3 p;
    NJS_POINT3 q;
    Angle ang[3];

    hit = *o->hit;
    fn_801DD5E8(ang, &o->up);
    fn_801DCF24(&lbl_802E4D10, ang, o->ang[1] + 0x1800, 4.0f);
    fn_801DCF24(&lbl_802E4D1C, ang, o->ang[1] - 0x1800, 4.0f);
    fn_801DCF24(&lbl_802E4D28, ang, o->ang[1] + 0x8000, 4.0f);

    p.x = o->pos.x + lbl_802E4D10.x + 8.0f * o->up.x;
    p.y = o->pos.y + lbl_802E4D10.y + 8.0f * o->up.y;
    p.z = o->pos.z + lbl_802E4D10.z + 8.0f * o->up.z;
    q.x = p.x - 16.0f * o->up.x;
    q.y = p.y - 16.0f * o->up.y;
    q.z = p.z - 16.0f * o->up.z;
    lbl_80305DB0[0] = 0;
    lbl_80305DBC[0] = fn_80224D08(&pt[0], &p, &q, &hit);
    if (lbl_80305DBC[0] != 0 && (hit.h24 & 0x4800) == 0x4800) {
        lbl_80305DB0[0] = 1;
        lbl_80305DBC[0] = 0;
    }

    hit = *o->hit;
    p.x = o->pos.x + lbl_802E4D1C.x + 8.0f * o->up.x;
    p.y = o->pos.y + lbl_802E4D1C.y + 8.0f * o->up.y;
    p.z = o->pos.z + lbl_802E4D1C.z + 8.0f * o->up.z;
    q.x = p.x - 16.0f * o->up.x;
    q.y = p.y - 16.0f * o->up.y;
    q.z = p.z - 16.0f * o->up.z;
    lbl_80305DB0[1] = 0;
    lbl_80305DBC[1] = fn_80224D08(&pt[1], &p, &q, &hit);
    if (lbl_80305DBC[1] != 0 && (hit.h24 & 0x4800) == 0x4800) {
        lbl_80305DB0[1] = 1;
        lbl_80305DBC[1] = 0;
    }

    hit = *o->hit;
    p.x = o->pos.x + lbl_802E4D28.x + 8.0f * o->up.x;
    p.y = o->pos.y + lbl_802E4D28.y + 8.0f * o->up.y;
    p.z = o->pos.z + lbl_802E4D28.z + 8.0f * o->up.z;
    q.x = p.x - 16.0f * o->up.x;
    q.y = p.y - 16.0f * o->up.y;
    q.z = p.z - 16.0f * o->up.z;
    lbl_80305DB0[2] = 0;
    lbl_80305DBC[2] = fn_80224D08(&pt[2], &p, &q, &hit);
    if (lbl_80305DBC[2] != 0 && (hit.h24 & 0x4800) == 0x4800) {
        lbl_80305DB0[2] = 1;
        lbl_80305DBC[2] = 0;
    }

    if (lbl_80305DBC[0] != 0 && lbl_80305DBC[1] != 0 && lbl_80305DBC[2] != 0) {
        fn_80290668(&pt[0], &pt[1], &pt[2], &o->up);
        njUnitVector(&o->up);
        p.x = o->pos.x + 8.0f * o->up.x;
        p.y = o->pos.y + 8.0f * o->up.y;
        p.z = o->pos.z + 8.0f * o->up.z;
        q.x = p.x - 16.0f * o->up.x;
        q.y = p.y - 16.0f * o->up.y;
        q.z = p.z - 16.0f * o->up.z;
        fn_80224D08(&o->pos, &p, &q, o->hit);
    }
    if (lbl_80305DBC[0] == 0) {
        pt[0].x = o->pos.x + lbl_802E4D10.x;
        pt[0].y = o->pos.y + lbl_802E4D10.y;
        pt[0].z = o->pos.z + lbl_802E4D10.z;
    }
    if (lbl_80305DBC[1] == 0) {
        pt[1].x = o->pos.x + lbl_802E4D1C.x;
        pt[1].y = o->pos.y + lbl_802E4D1C.y;
        pt[1].z = o->pos.z + lbl_802E4D1C.z;
    }
    if (lbl_80305DBC[2] == 0) {
        pt[2].x = o->pos.x + lbl_802E4D28.x;
        pt[2].y = o->pos.y + lbl_802E4D28.y;
        pt[2].z = o->pos.z + lbl_802E4D28.z;
    }
    lbl_802E4D10.x = pt[0].x;
    lbl_802E4D10.y = pt[0].y;
    lbl_802E4D10.z = pt[0].z;
    lbl_802E4D1C.x = pt[1].x;
    lbl_802E4D1C.y = pt[1].y;
    lbl_802E4D1C.z = pt[1].z;
    lbl_802E4D28.x = pt[2].x;
    lbl_802E4D28.y = pt[2].y;
    lbl_802E4D28.z = pt[2].z;
}

void fn_8010F3A8(EvObj* o) {
    switch (o->x172) {
    case 0:
        o->pivotAng[0] = o->ang[0];
        o->pivotAng[1] = o->ang[1];
        o->pivotAng[2] = o->ang[2];
        fn_801DD3B8(&o->dir, &o->up, o->pivotAng);
        fn_8010E5BC(o);
        o->x172 = 0x10;
    case 0x10:
        fn_801147E8(o, 0.0f, 0);
        fn_801DD22C(o->ang, &o->dir, &o->up);
        fn_801189F0(o);
        if (PlayerBusy() == 0 && fn_801D72A0(0, 0) >= 10.0f) {
            o->motionId = 0x17;
            o->x172 = 0;
            fn_801E7414(2, o);
            o->x18c = 16.0f;
        }
        break;
    }
}

s32 fn_80114950(Chr_80114950* o) {
    f32 p[3];
    EvHit h;
    s32 r;

    p[0] = o->pos.x;
    p[1] = o->pos.y;
    p[2] = o->pos.z;
    h.x30 = 4;
    r = fn_80115A4C(p, NULL, &h);
    if (r != 0) {
        if (fn_80114B24(1, (void *)(&o->pos), (void *)(&h), o->pos.y) != 0) {
            r = 0;
        } else if ((f32)fabs(o->pos.y - p[1]) > lbl_802E1154[lbl_80310A1C[6]].height / 2) {
            r = 0;
        } else if (fn_80222E00(0x4800, (void *)(o->x1bc)) != 0) {
            r = 0;
        }
    }
    return r;
}

void fn_80116898(NJS_POINT3* in, NJS_POINT3* out) {
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

void fn_801222A8(O_8012239C* o, Ctx_8011DD9C* s) {
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

void fn_8012239C(O_8012239C* o, Ctx_8011DD9C* a) {
    Ctx_8011DD9C* p6c;
    Ctx_8011DD9C* p70;
    u16 id;
    Ctx_8011DD9C* r;
    s32 s;
    NJS_POINT3* ap;
    NJS_POINT3* w;
    B* b;
    Ent* sub;
    NJS_POINT3 v;

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
    o->x2c = &o->x70->pos;
    fn_8020EFD4(id);
    sub = &b->ent[3];
    o->x74 = sub;
    if (sub->x10 != 0) {
        o->flags |= 1;
    }
    r = b->x10->x24;
    o->x68 = r;
    o->x78 = &r->cfg->hdr->x38.x4;
    fn_801222A8(o, a);
    ap = &o->pos;
    s = (s32)(0.2f * fn_8011A8B0(&r->pos, ap) + 1.0f);
    if (s > 50) s = 50;
    o->x8 = s;
    w = &o->x38.pos;
    fn_801575C8(w, fn_80156A8C(r->u17a), (f32)s);
    fn_8011A960(&v, w, ap);
    fn_801DD5E8(&o->x6c->ax, &v);
    fn_80121B24(o, o->x6c);
    o->flags |= 0x40000000;
}

s32 fn_80122508(M_80121918* m) {
    Ctx_8011DD9C* c = fn_8015F180();
    O_8012239C* w;

    if (c->p1d8->x4->state != 2) {
        return 0;
    }
    w = m->work;
    if (w == 0) {
        return 0;
    }
    if (!(w->flags & 0x40000000)) {
        fn_8012239C(w, c);
        return 0;
    }
    w->x4++;
    if (w->flags & 0x100) {
        if (w->x4 >= 0x14) {
            fn_8020EF30(w->x64);
            w->flags |= 0x80000000;
        }
        {
            Ctx_8011DD9C* a = w->x68;
            Ctx_8011DD9C* d = w->x70;
            NJS_MATRIX mtx;
            njUnitMatrix(mtx);
            njTranslate(mtx, a->pos.x, a->pos.y, a->pos.z);
            njRotateZXY(mtx, a->ax, a->ay, a->az);
            njTranslate(mtx, w->ox.x, w->ox.y, w->ox.z);
            njGetTranslation(mtx, &d->pos);
        }
    } else {
        Ent* cn;
        NJS_POINT3* dst;
        dst = &w->x6c->pos;
        cn = w->x74;
        fn_80120A50(&dst->x, &w->pos.x, &w->x38.pos.x, (f32)w->x4 / (f32)w->x8);
        if (w->flags & 1) {
            if (w->x4 >= w->x8) {
                Ctx_8011DD9C* a;
                Ctx_8011DD9C* d;
                NJS_MATRIX mtx;
                w->x4 = 0;
                cn->x14 = cn->x14 + 1;
                cn->x18 = cn->x18 - 1;
                w->owner->f1ef = 1;
                w->flags |= 0x100;
                fn_8020EFD4(w->x66);
                a = w->x68;
                d = w->x70;
                njUnitMatrix(mtx);
                njTranslate(mtx, a->pos.x, a->pos.y, a->pos.z);
                njRotateZXY(mtx, a->ax, a->ay, a->az);
                njTranslate(mtx, w->ox.x, w->ox.y, w->ox.z);
                njGetTranslation(mtx, &d->pos);
            }
        } else {
            if (w->x4 >= w->x8 + 0x96) {
                w->flags |= 0x80000000;
                fn_8020EF30(w->x64);
                w->owner->f1ef = 1;
            }
        }
    }
    return 1;
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

    ready = lbl_80311AC0.id >= 500;
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

static inline void StopSe(EvObj *o) {
    if (o->x1ec == 1) {
        fn_80217830(o->x23c);
        o->x1ec = 0;
    }
}

extern f32 lbl_80346E74;
void fn_8011816C(EvObj *self, EvColl *out);

void fn_80112BB4(EvObj *o)
{
    s32 a;
    s32 b;
    s32 ok;
    s32 se;
    f32 i;

    o->speed = 1.0f;
    fn_801189F0(o);
    switch (o->x172) {
    case 0:
        lbl_80346E74 = 0.0f;
        o->x172 = 0x10;
    case 0x10:
        a = lbl_80311A60[0]->x;
        if (a > 0x20) {
            o->ang[1] += 0x2D8;
            o->tgt[1] = o->ang[1];
        } else if (a < -0x20) {
            o->ang[1] -= 0x2D8;
            o->tgt[1] = o->ang[1];
        }
        b = lbl_80311A60[0]->y;
        if (b > 10) {
            ok = SameSe(0x1d);
            if (!(o->x1ec == 1 && ok == 0)) {
                if (o->x1ec == 1 && ok != 0) StopSe(o);
                o->x23c = SePlay(15, 5, 0x1D);
                lbl_80346E71 = 5;
                lbl_80346E70 = 0x1D;
                o->x1ec = 1;
            }
            fn_801E7414(0x20, o);
            if (o->x19c == 1) {
                for (i = 0.0f; i <= 1.0f; i += 0.1f) {
                    o->pos.y -= 0.1f;
                    fn_8011816C(o, o->coll);
                    if (o->motionId == 0xE) {
                        break;
                    }
                }
                lbl_80346E74 = lbl_80346E74 - i;
                if (lbl_80346E74 < -3.0f) {
                    o->motionId = 0xD;
                    o->x172 = 0;
                }
            }
        } else if (b < -0x40) {
            StopSe(o);
            o->motionId = 0xD;
            o->x172 = 0;
        } else {
            StopSe(o);
            fn_801E7414(0x1E, o);
        }
        break;
    }
}

extern f32 lbl_80346E78;

void fn_80112E1C(EvObj *o) {
    s32 a;
    s32 b;
    s32 ok;
    f32 i;

    o->speed = 1.0f;
    fn_801189F0(o);
    switch (o->x172) {
    case 0:
        lbl_80346E78 = 0.0f;
        o->x172 = 0x10;
    case 0x10:
        a = lbl_80311A60[0]->x;
        if (a > 0x20) {
            o->ang[1] += 0x2D8;
            o->tgt[1] = o->ang[1];
        } else if (a < -0x20) {
            o->ang[1] -= 0x2D8;
            o->tgt[1] = o->ang[1];
        }
        b = lbl_80311A60[0]->y;
        if (b < -10) {
            ok = SameSe(0x1c);
            if (!(o->x1ec == 1 && ok == 0)) {
                if (o->x1ec == 1 && ok != 0) StopSe(o);
                o->x23c = SePlay(15, 5, 0x1C);
                lbl_80346E71 = 5;
                lbl_80346E70 = 0x1C;
                o->x1ec = 1;
            }
            fn_801E7414(0x1f, o);
            if (o->x19c == 1) {
                for (i = 0.0f; i <= 0.3f; i += 0.1f) {
                    o->pos.y += 0.1f;
                    fn_8011816C(o, o->coll);
                    if (o->motionId == 0xE) {
                        break;
                    }
                }
                lbl_80346E78 = lbl_80346E78 + i;
                if (lbl_80346E78 > 1.2f) {
                    o->motionId = 0xD;
                    o->x172 = 0;
                }
            }
        } else if (b > 0x40) {
            StopSe(o);
            o->motionId = 0xD;
            o->x172 = 0;
        } else {
            StopSe(o);
            fn_801E7414(0x1E, o);
        }
        break;
    }
}


void fn_80112868(EvObj *o) {
    f32 t, lim, step;
    s32 diff;
    o->speed = 1.0f;
    fn_801189F0(o);
    if (lbl_80311A60[0]->y < -10) {
        diff = SameSe(0x1c);
        if (!(o->x1ec == 1 && diff == 0)) {
            if (o->x1ec == 1 && diff != 0) StopSe(o);
            o->x23c = SePlay(0xf, 5, 0x1c);
            lbl_80346E71 = 5;
            lbl_80346E70 = 0x1c;
            o->x1ec = 1;
        }
        fn_801E7414(0x1f, o);
        if (o->x19c == 1) {
            if (lbl_80311A60[0]->x > 0x20) {
                o->ang[1] += 0x2d8;
                o->tgt[1] = o->ang[1];
            } else if (lbl_80311A60[0]->x < -0x20) {
                o->ang[1] -= 0x2d8;
                o->tgt[1] = o->ang[1];
            }
            t = 0.0f;
            step = 0.1f;
            lim = 0.3f;
            while (t <= lim) {
                o->pos.y += step;
                fn_8011816C(o, o->coll);
                if (o->motionId == 0xe) break;
                t += step;
            }
        }
    } else if (lbl_80311A60[0]->y > 10) {
        diff = SameSe(0x1d);
        if (!(o->x1ec == 1 && diff == 0)) {
            if (o->x1ec == 1 && diff != 0) StopSe(o);
            o->x23c = SePlay(0xf, 5, 0x1d);
            lbl_80346E71 = 5;
            lbl_80346E70 = 0x1d;
            o->x1ec = 1;
        }
        fn_801E7414(0x20, o);
        if (o->x19c == 1) {
            if (lbl_80311A60[0]->x > 0x20) {
                o->ang[1] += 0x2d8;
                o->tgt[1] = o->ang[1];
            } else if (lbl_80311A60[0]->x < -0x20) {
                o->ang[1] -= 0x2d8;
                o->tgt[1] = o->ang[1];
            }
            t = 0.0f;
            step = 0.1f;
            lim = 1.0f;
            while (t <= lim) {
                o->pos.y -= step;
                fn_8011816C(o, o->coll);
                if (o->motionId == 0xe) break;
                t += step;
            }
        }
    } else {
        StopSe(o);
        fn_801E7414(0x1e, o);
    }
    o->home.x = o->pos.x;
    o->home.y = o->pos.y;
    o->home.z = o->pos.z;
    o->tgt[0] = o->ang[0];
    o->tgt[1] = o->ang[1];
    o->tgt[2] = o->ang[2];
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

/* the four corner colours of a streak quad */
typedef struct Col4 {
    u32 v[4];
} Col4;
extern const Col4 lbl_802B325C;

void fn_8011FFF0(f32 *pos, f32 *v, Elem *el, f32 t, u32 *w) {
    Col4 cc;
    u32 *c; /* the last corner's colour */
    f32 dx, dy, dz;
    f32 inv;
    f32 d2;
    f32 px, vx, py, vy, pz, vz;
    u32 a;
    u32 k;
    if (w != 0) {
        u32 x = *w;
        c = cc.v;
        *c++ = x;
        *c++ = x;
        *c++ = x;
        *c = x;
    } else {
        cc = lbl_802B325C;
        c = &cc.v[3];
    }
    if (t < 0.0f) {
        t = 0.0f;
    }
    px = pos[0]; py = pos[1]; pz = pos[2];
    vx = v[0]; vy = v[1]; vz = v[2];
    dx = px - vx;
    dy = py - vy;
    dz = pz - vz;
    d2 = dx * dx + dy * dy + dz * dz;
    inv = 0.0f;
    if (d2 != inv) {
        inv = 1.0f / fn_80291A5C(d2);
    }
    inv = 0.04f * inv;
    dx *= inv;
    dy *= inv;
    dz *= inv;
    k = c[-3];
    a = t * (f32)(k >> 24);
    k = (a << 24) | (k & 0xFFFFFF);
    el->p[0].x = px + dx;
    el->p[0].y = py - dy;
    el->p[0].z = pz + dz;
    el->p[0].col = k;
    k = c[-2];
    a = t * (f32)(k >> 24);
    k = (a << 24) | (k & 0xFFFFFF);
    el->p[1].x = px - dx;
    el->p[1].y = py + dy;
    el->p[1].z = pz - dz;
    el->p[1].col = k;
    dx *= 15.0f;
    dy *= 15.0f;
    dz *= 15.0f;
    k = c[-1];
    a = t * (f32)(k >> 24);
    k = (a << 24) | (k & 0xFFFFFF);
    el->p[2].x = vx + dx;
    el->p[2].y = vy - dy;
    el->p[2].z = vz + dz;
    el->p[2].col = k;
    k = c[0];
    a = t * (f32)(k >> 24);
    k = (a << 24) | (k & 0xFFFFFF);
    el->p[3].x = vx - dx;
    el->p[3].y = vy + dy;
    el->p[3].z = vz - dz;
    el->p[3].col = k;
}

void fn_8012048C(void *o) {
    Eff_8012048C *e = o;
    s32 n = e->count;
    Ent_8012048C *ent = e->ents;
    Elem *el = e->elems;
    do {
        u32 flags = e->flags;
        f32 t;
        u32 *w;
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

s32 fn_80114AB8(s32 a, f32 t, s32 unused, Src *e) {
    s32 r = 0;
    if (a != 0) {
        if (lbl_80349E00 >= t) {
            if (e->flags & 0x8000) {
                switch ((e->flags >> 8) & 0x7f) {
                case 1:
                case 3:
                case 30:
                    r = 1;
                    break;
                case 5:
                case 7:
                    if (lbl_80349E04 <= t) {
                        r = 1;
                    }
                    break;
                }
            }
        }
    }
    return r;
}

f32 fn_8011A8B0(NJS_POINT3 *a, NJS_POINT3 *b) {
    f32 dx = a->x - b->x;
    f32 dy = a->y - b->y;
    f32 dz = a->z - b->z;
    f32 d2 = dx * dx + dy * dy + dz * dz;

    if (d2 < 0.025f) {
        return 0.0f;
    }
    return sqrtf(d2);
}
extern void njProjectScreen(void* m, NJS_POINT3* p, f32* out);
extern s32 fn_8011E250(Sub* s, f32 depth, f32 x, f32 y);

inline void Rot_8011E72C(G6* g, f32 x, f32 y, f32 cx, f32 cy, Angle a) {
    f32 sn = njSin(a);
    f32 cs = njCos(a);
    f32 dy = y - cy;
    f32 dx = x - cx;
    g->a[0] = cx + (dx * cs - dy * sn);
    g->a[1] = cy + (dx * sn + dy * cs);
}

s32 fn_8011E72C(Ctx_8011DD9C* c) {
    s32 i;
    Sub* s;
    Pt2* pt;
    Big* v;
    Big* b;
    Ctx_8011DD9C* o;
    f32 x0, y0;
    f32 depth;
    f32 x, y;
    f32 scale;
    f32 cx, cy;
    f32 w;
    f32 x1, y1;
    f32 scr[2];
    NJS_POINT3 p;
    NJS_POINT3 t;
    NJS_POINT3 q;
    NJS_MATRIX m;
    DrawState ds;

    s = c->sub;
    pt = &s->x4;
    v = s->p88;
    scale = 0.5f * s->x3c;
    o = fn_8015F180();
    if (o->p1d8->x4->state != 2) {
        return 0;
    }
    if (!(s->flags & 0x10000)) {
        s->flags |= 0x10000;
        return 0;
    }
    p.x = o->pos.x + o->xb4.x;
    p.y = o->pos.y + o->xb4.y;
    p.z = o->pos.z + o->xb4.z;
    fn_80291C44(m);
    njCalcVector(m, &p, &q);
    njGetTranslation(m, &t);
    depth = (q.z + t.z) - 1.0f;
    if (!(depth <= 0.0f)) {
        return 0;
    }
    njProjectScreen(NULL, &p, scr);
    x = scr[0];
    y = scr[1];
    if (s->flags & 0x10) {
        if (x < 0.0f || x > 640.0f || y < 0.0f || y > 480.0f) {
            return 0;
        }
    }
    fn_802974E0(pt);
    if (s->flags & 2) {
        pt->x = 640.0f - x;
        pt->y = 480.0f - y;
    } else if (s->flags & 4) {
        pt->x = ((320 - (s32)x) >> 1) + 320;
        pt->y = ((240 - (s32)y) >> 1) + 240;
    } else if (s->flags & 8) {
        pt->x = ((320 - (s32)x) >> 2) + 320;
        pt->y = ((240 - (s32)y) >> 2) + 240;
    }
    if (fn_8011E250(s, depth, x, y) == 0) {
        return 0;
    }
    if (s->flags & 0x40) {
        s->x4c = 10430.381f * (f32)atan2(y - pt->y, x - pt->x);
        if (s->flags & 0x80) {
            s->x4c = 0x10000 - s->x4c;
        }
    }
    for (i = 0; i < s->x24 + s->x28; i++) {
        f32 k;
        s32 spline;
        s32 n0 = s->x24;
        s32 n1 = s->x28;
        b = v;
        v++;
        if (i < n0) {
            if (n0 == 1) {
                k = s->x50;
            } else {
                k = (f32)i / (f32)(n0 - 1);
            }
            spline = s->flags & 0x400;
            if (!spline || !(s->flags & 0x800)) {
                w = scale * (k * ((f32)s->x10 - (f32)s->xc) + (f32)s->xc);
            }
            if (spline) {
                fn_8011AEE4(s->x58, 4, 3, &s->x78, k);
                k = 0.01f * s->x78.y;
            }
            if (s->flags & 0x800) {
                w = scale * (k * ((f32)s->x10 - (f32)s->xc) + (f32)s->xc);
            }
            cx = (pt->x - x) * (k * s->x30) + x;
            cy = (pt->y - y) * (k * s->x30) + y;
        } else {
            s32 j = i - n0;
            if (n1 == 1) {
                k = 1.0f - s->x50;
            } else {
                k = (f32)j / (f32)(n1 - 1);
            }
            spline = s->flags & 0x400;
            if (!spline || !(s->flags & 0x800)) {
                w = scale * (k * ((f32)s->x14 - (f32)s->x10) + (f32)s->x10);
            }
            if (spline) {
                fn_8011AEE4(s->x58, 4, 3, &s->x78, 1.0f - k);
                k = 1.0f - 0.01f * s->x78.y;
                if (s->flags & 0x800) {
                    w = scale * (k * ((f32)s->x14 - (f32)s->x10) + (f32)s->x10);
                }
                cx = (pt->x - x) * (s->x34 + k) + x;
                cy = (pt->y - y) * (s->x34 + k) + y;
            } else {
                cx = (pt->x - x) * ((1.0f + s->x38) * j + s->x34) + x;
                cy = (pt->y - y) * ((1.0f + s->x38) * j + s->x34) + y;
            }
        }
        x0 = cx - w;
        y0 = cy - w;
        y1 = cy + w;
        x1 = cx + w;
        if (s->flags & 0x40) {
            fn_802974E0(&b->g[0]);
            Rot_8011E72C(&b->g[0], x0, y0, cx, cy, s->x4c);
            Rot_8011E72C(&b->g[1], x0, y1, cx, cy, s->x4c);
            fn_802974E0(&b->g[2]);
            Rot_8011E72C(&b->g[2], x1, y0, cx, cy, s->x4c);
            Rot_8011E72C(&b->g[3], x1, y1, cx, cy, s->x4c);
        } else {
            b->g[0].a[0] = b->g[1].a[0] = x0;
            b->g[2].a[0] = b->g[3].a[0] = x1;
            b->g[0].a[1] = b->g[2].a[1] = y0;
            b->g[1].a[1] = b->g[3].a[1] = y1;
        }
    }
    if (c->p1d8->w1a0 == 0) {
        void *big;
        if ((s->flags & 0x20100) == 0x20100) {
            fn_8011D7BC(&s->x8c, 0);
        }
        if (s->flags & 1) {
            DrawStateDefault2D(&ds);
            ds.blend_src = s->x54;
            ds.blend_dst = s->x56;
            DrawStatePush(&ds);
        }
        big = s->x80;
        v = s->p88;
        for (i = 0; i < s->x2c; i++) {
            fn_8011D7BC(v++, big);
        }
        if (s->flags & 1) {
            DrawStatePop(NULL);
        }
    }
    s->flags &= ~0x20000;
    return 1;
}

/* 0 when the hit (id) is a wall of kind 1/3/30, or of kind 5/7 within 150 below, at a height y
   of at most 150; 1 otherwise. Same kind table as fn_800CF554. */
s32 fn_80114A44(s32 id, NJS_POINT3* p, f32 y, Flags* info)
{
    s32 r;
    if (id != 0) {
        r = 1;
        if (150.0f >= y && (info->h24 & 0x8000)) {
            switch ((info->h24 >> 8) & 0x7F) {
            case 1:
            case 3:
            case 30:
                r = 0;
                break;
            case 5:
            case 7:
                if (-150.0f <= y) {
                    r = 0;
                }
                break;
            }
        }
        return r;
    }
    return 0;
}

int fn_80117088(Xf *a, Xf *b, f32 x, f32 y, f32 z, void *p) {
    NJS_MATRIX m;
    NJS_POINT3 v;
    Xf tmp;
    f32 len;
    f32 ang;

    v.x = b->pos.x - a->pos.x;
    v.y = b->pos.y - a->pos.y;
    v.z = b->pos.z - a->pos.z;
    len = njScalor(&v);
    v.z = 0.8f * len;
    v.x = 0.0f;
    v.y = 0.0f;
    MemCopy(&tmp, b, 0x24);
    {
        f32 d = 0.005493164f * b->ang[1];
        ang = x + d;
        y += d;
    }
    while (fabsf(y - ang) >= fabsf(z)) {
        njUnitMatrix(m);
        njRotateY(m, 182.04445f * ang);
        njCalcPoint(m, &v, &tmp.pos);
        tmp.pos.x = tmp.pos.x + a->pos.x;
        tmp.pos.y = tmp.pos.y + a->pos.y;
        tmp.pos.z = tmp.pos.z + a->pos.z;
        if (fn_80116B84(3, &tmp.pos, lbl_8030A35C, p) == 0) {
            b->pos.x = tmp.pos.x;
            b->pos.y = tmp.pos.y;
            b->pos.z = tmp.pos.z;
            return 1;
        }
        ang += z;
    }
    return 0;
}

void fn_8011B624(Out_8011B624* o) {
    f32 u;
    f32 v;

    u = lbl_80345878[10] / 1024.0f;
    v = lbl_80345878[11] / 512.0f;
    o->x20 = lbl_80347F28 + o->x20;
    o->vtx[0].x = 0.0f;
    o->vtx[0].y = 0.0f;
    o->vtx[0].z = o->x20;
    o->vtx[0].u = 0.0f;
    o->vtx[0].v = 0.0f;
    o->vtx[0].colour = -1;
    o->vtx[1].x = 0.0f;
    o->vtx[1].y = lbl_80345878[11];
    o->vtx[1].z = o->x20;
    o->vtx[1].u = 0.0f;
    o->vtx[1].v = v;
    o->vtx[1].colour = -1;
    o->vtx[2].x = lbl_80345878[10];
    o->vtx[2].y = 0.0f;
    o->vtx[2].z = o->x20;
    o->vtx[2].u = u;
    o->vtx[2].v = 0.0f;
    o->vtx[2].colour = -1;
    o->vtx[3].x = lbl_80345878[10];
    o->vtx[3].y = lbl_80345878[11];
    o->vtx[3].z = o->x20;
    o->vtx[3].u = u;
    o->vtx[3].v = v;
    o->vtx[3].colour = -1;
}

void fn_80126354(Obj_80126354 *e, MtxPair_80126354 *mp) {
    Obj_80126354 a;
    Obj_80126354 b;

    njUnitMatrix(mp->m1);
    fn_80156C6C(mp->m1, e);
    if (e->motion != 0) {
        fn_80156CC4(e, &a);
        fn_80156C6C(mp->m1, &a);
    }
    njUnitMatrix(mp->m0);
    fn_80156C6C(mp->m0, e);
    if (e->motion != 0) {
        fn_80156CC4(e, &b);
        fn_80156C6C(mp->m0, &b);
    }
    fn_801566B4(1, mp->m0, mp->m1);
}

/* Darkening area (fn_8011A2D4): fades the screen while the player is inside the box. */
typedef struct EvInfoArea {
    u32 x0;
    f32 x4, x8;    /* 0x04 area centre (x, z) */
    f32 xc;        /* 0x0C half size */
    f32 x10, x14;  /* 0x10 height range */
    f32 x18;       /* 0x18 sound chance */
    u32 x1c;       /* 0x1C max alpha */
    s32 x20;
    s32 x24;       /* 0x24 alpha step */
} EvInfoArea;
extern EvObj *lbl_80347450;
extern VertexCol lbl_80305E78[4];
extern const char lbl_802B31B8[];
extern f32 fn_801DBD9C(f32 z);
extern void fn_80290ED4(VertexCol* v, s32 count, s32 flag);
extern s32 rand(void);

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(a) ((a) < 0.0f ? -(a) : (a))

/* the fade quad's draw, the same in every state */
#define DRAW_8011A2D4(col)                                                        v[0].colour = v[1].colour = v[2].colour = v[3].colour = (col);                DrawStateDefault2D(&st);                                                      DrawStatePush(&st);                                                           if (w->x210 != 0) {                                                               st.blend_src = 8;                                                             st.blend_dst = 10;                                                        }                                                                             fn_80290ED4(v, 4, 1);                                                         DrawStatePop(NULL)

void fn_8011A2D4(Task *task)
{
    DrawState st;
    EvInfoArea *in;
    EvObj *w;
    VertexCol *v;
    EvObj *pl;
    f32 dx, dz, ax, az;
    u32 col;

    w = task->work;
    v = lbl_80305E78;
    pl = lbl_80347450;
    in = w->ext->info;
    if (pl == NULL) {
        return;
    }
    dx = in->x4 - pl->pos.x;
    dz = in->x8 - pl->pos.z;
    ax = ABS(MIN(dx, 16800.0f - dx));
    az = ABS(MIN(dz, 14400.0f - dz));
    switch (task->state) {
    case 0:
        if (in->x0 < 10) {
            fn_801DBE1C(lbl_802B31B8);
        }
        v[0].x = 0.0f;
        v[0].y = 0.0f;
        v[1].x = 0.0f;
        v[1].y = 480.0f;
        v[2].x = 640.0f;
        v[2].y = 0.0f;
        v[3].x = 640.0f;
        v[3].y = 480.0f;
        v[0].z = v[1].z = v[2].z = v[3].z = fn_801DBD9C(-2.0f);
        v[0].colour = v[1].colour = v[2].colour = v[3].colour = -1;
        task->f20 = -15.0f;
        task->state++;
        break;
    case 1:
        if (ax < in->xc && az < in->xc && pl->pos.y < in->x10 && pl->pos.y > in->x14) {
            task->state = 2;
        }
        break;
    case 2:
        if (ax > in->xc || az > in->xc || pl->pos.y > in->x10 || pl->pos.y < in->x14) {
            task->state = 3;
        }
        if (w->x210 != 0) {
            w->x214 -= in->x24;
            if (w->x214 < 0) {
                w->x214 = 0;
                w->x210 = 0;
            }
            col = (w->x214 << 24) | 0xFFFFFF;
        } else {
            if (w->x214 + in->x24 < in->x1c) {
                w->x214 += in->x24;
            } else {
                w->x214 = in->x1c;
                task->state = 4;
            }
            col = (w->x214 << 24) | 0x202020;
        }
        DRAW_8011A2D4(col);
        break;
    case 3:
        if (ax < in->xc && az < in->xc && pl->pos.y < in->x10 && pl->pos.y > in->x14) {
            task->state = 2;
        }
        if (w->x210 != 0) {
            w->x214 -= in->x24;
            if (w->x214 < 0) {
                w->x214 = 0;
                w->x210 = 0;
                task->state = 1;
            }
            col = (w->x214 << 24) | 0xFFFFFF;
        } else {
            if (w->x214 - in->x24 > 0) {
                w->x214 -= in->x24;
            } else {
                w->x214 = 0;
                task->state = 1;
            }
            col = (w->x214 << 24) | 0x202020;
        }
        DRAW_8011A2D4(col);
        break;
    case 4:
        if (ax > in->xc || az > in->xc || pl->pos.y > in->x10 || pl->pos.y < in->x14) {
            task->state = 3;
        }
        switch (w->x20c) {
        case 0:
            if (w->x214 < in->x1c) {
                w->x214 += in->x24;
            }
            if (3.0517578125e-05f * rand() < in->x18) {
                SePlay(8, 5, 12);
                w->x20c = 1;
            }
            col = (w->x214 << 24) | 0x202020;
            break;
        case 1:
            w->x210 = 1;
            col = 0;
            w->x214 = in->x20;
            w->x20c = 2;
            break;
        case 2:
            w->x214 -= in->x24;
            if (w->x214 < 0) {
                w->x214 = 0;
                w->x210 = 0;
                w->x20c = 0;
            }
            col = (w->x214 << 24) | 0xFFFFFF;
            break;
        }
        DRAW_8011A2D4(col);
        break;
    case 0xFF:
        fn_80100B74(task);
        break;
    }
}

typedef struct Key {
    s32 id;
    s8 sub;
} Key;
typedef struct KeyEnt {
    s32 id;
    s8 sub;
    u8 pad[3];
} KeyEnt;
extern Key lbl_80346790;
extern KeyEnt lbl_802E4FB8[];
extern s32 lbl_80346EA8;

/* Uniform clamped knot j of a B-spline with control points 0..n and order `order`. */
static inline f32 Knot_8011A994(int j, int n, int order) {
    if (j < order) {
        return 0.0f;
    }
    if (j <= n) {
        return j - order + 1;
    }
    return n - order + 2;
}

/* Cox-de Boor basis function N(i, k) at t. */
f32 fn_8011A994(int i, int n, int k, s32 order, f32 t) {
    f32 d;
    f32 a;
    f32 b;
    f32 inv;
    f32 num;
    int m;

    if (k == 1) {
        if (Knot_8011A994(i, n, order) <= t && t < Knot_8011A994(i + 1, n, order)) {
            return 1.0f;
        }
        if (t == n - order + 2) {
            if (Knot_8011A994(i, n, order) <= t && t <= Knot_8011A994(i + 1, n, order)) {
                return 1.0f;
            }
        }
        return 0.0f;
    }
    m = i + k;
    d = Knot_8011A994(m - 1, n, order) - Knot_8011A994(i, n, order);
    if (d == 0.0f) {
        a = 0.0f;
    } else {
        inv = 1.0f / d;
        num = (t - Knot_8011A994(i, n, order)) * fn_8011A994(i, n, k - 1, order, t);
        a = num * inv;
    }
    d = Knot_8011A994(m, n, order) - Knot_8011A994(i + 1, n, order);
    if (d == 0.0f) {
        b = 0.0f;
    } else {
        inv = 1.0f / d;
        num = (Knot_8011A994(m, n, order) - t) * fn_8011A994(i + 1, n, k - 1, order, t);
        b = num * inv;
    }
    return a + b;
}

void fn_801195E4(void) {
    s32 id = lbl_80311AC0.id;
    s8 sub = lbl_80311AC0.sub;
    s32 s2 = sub;
    int i;
    Key *k = &lbl_80346790;
    if (id == k->id && s2 == k->sub) {
        lbl_80346EA8 = 2;
        return;
    }
    for (i = 0; i < 24; i++) {
        if (id == lbl_802E4FB8[i].id && sub == lbl_802E4FB8[i].sub) {
            lbl_80346EA8 = 1;
            return;
        }
    }
    lbl_80346EA8 = 0;
}

/* Pushes pos out of the wall hit fn_80224D08 finds along the three axes of q. */
#define SCALE(v) \
    A.x = (v).x * reach; A.y = (v).y * reach; A.z = (v).z * reach; \
    B.x = (v).x * half; B.y = (v).y * half; B.z = (v).z * half;

#define TEST_NEG(vv) \
    if (fn_80224D08(&P, &R, &Q, &pl) != 0) { \
    D.x = P.x - (pos->x + B.x); D.y = P.y - (pos->y + B.y); D.z = P.z - (pos->z + B.z); \
    if (0.0f > njInnerProduct(&D, &B)) { \
    moved = 1; any = 1; \
    pos->x = P.x - B.x; pos->y = P.y - B.y; pos->z = P.z - B.z; \
    } \
    } \
    if (moved == 0 && fn_80224D08(&P, &Q, &R, &pl) != 0) { \
    D.x = pos->x - B.x - P.x; D.y = pos->y - B.y - P.y; D.z = pos->z - B.z - P.z; \
    if (0.0f > njInnerProduct(&D, vv)) { \
    any = 1; \
    pos->x = P.x + B.x; pos->y = P.y + B.y; pos->z = P.z + B.z; \
    } \
    }

#define TEST_POS(vv) \
    if (fn_80224D08(&P, &R, &Q, &pl) != 0) { \
    D.x = pos->x - B.x - P.x; D.y = pos->y - B.y - P.y; D.z = pos->z - B.z - P.z; \
    if (0.0f > njInnerProduct(&D, &B)) { \
    moved = 1; any = 1; \
    pos->x = P.x + B.x; pos->y = P.y + B.y; pos->z = P.z + B.z; \
    } \
    } \
    if (moved == 0 && fn_80224D08(&P, &Q, &R, &pl) != 0) { \
    D.x = P.x - (pos->x + B.x); D.y = P.y - (pos->y + B.y); D.z = P.z - (pos->z + B.z); \
    if (0.0f > njInnerProduct(&D, vv)) { \
    any = 1; \
    pos->x = P.x - B.x; pos->y = P.y - B.y; pos->z = P.z - B.z; \
    } \
    }

s32 fn_8011513C(NJS_POINT3* pos, EvObj* q) {
    NJS_POINT3 R;
    NJS_POINT3 Q;
    NJS_POINT3 P;
    NJS_POINT3 D;
    NJS_POINT3 B;
    NJS_POINT3 A;
    EvHit pl;
    f32 half, reach;
    s32 moved, any;
    if (lbl_8030A3C8[2] >= 0xffff) {
        return 0;
    }
    fn_80225930(0, lbl_8030A3C8[2], &pl);
    fn_801DD3B8(&q->dir, &q->up, q->ang);
    njOuterProduct(&q->dir, &q->up, &B);
    njUnitVector(&B);
    half = lbl_802E1154[lbl_80310A1C[6]].height;
    reach = 2.0f * half + 4.0f;
    half += 2.0f;
    moved = 0;
    any = 0;
    SCALE(B)
    R.x = pos->x - A.x; R.y = pos->y - A.y; R.z = pos->z - A.z;
    Q.x = pos->x + A.x; Q.y = pos->y + A.y; Q.z = pos->z + A.z;
    TEST_NEG(&B)
    SCALE(q->up)
    moved = 0;
    R.x = pos->x + A.x; R.y = pos->y + A.y; R.z = pos->z + A.z;
    Q.x = pos->x - A.x; Q.y = pos->y - A.y; Q.z = pos->z - A.z;
    TEST_POS(&B)
    SCALE(q->dir)
    moved = 0;
    R.x = pos->x - A.x; R.y = pos->y - A.y; R.z = pos->z - A.z;
    Q.x = pos->x + A.x; Q.y = pos->y + A.y; Q.z = pos->z + A.z;
    TEST_NEG(&A)
    return any;
}

