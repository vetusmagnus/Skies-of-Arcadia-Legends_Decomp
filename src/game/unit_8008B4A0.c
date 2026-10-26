#include "types.h"
#include "ninja.h"
#include "game/sprite.h"
#include <math.h>
#include "game/drawstate.h"
typedef struct Ent_UNIT0000 {
    u8 pad[0x1C];
    u32 x1c;
} Ent_UNIT0000;
extern s8 lbl_80347340;
typedef struct {
    u8 pad0[0x10];
    u32 x10;
    u8 pad14[8];
    u32 flags;
} Unit;
extern Unit* lbl_80309DE4[12];
typedef struct {
    u32 w0;
    s8 b4;
    u8 pad5[3];
    u8 b8;
    u8 b9;
    u8 padA[3];
    u8 bd;
    u8 padE[2];
} Ent80309730;
extern Ent80309730 lbl_80309730[12];
typedef struct {
    s16 idx;
    u8 pad2[6];
    void* chr;
    u8 padc[4];
    void* fn;
    u8 pad14[0x4c - 0x14];
    s32 x4c;
    u8 b50;
} Sub80309700;
typedef struct Slot {
    void (*fn)(struct Slot*);
    u8 pad4[0x19 - 4];
    u8 state;
    u8 pad1a[0x24 - 0x1a];
    Sub80309700* sub;
} Slot;
extern Slot* lbl_80309700[12];
extern void fn_800811E4(s32 i, s32 k);
extern s32 fn_8007FFE8(s32 i, s32 k);
typedef struct Tm {
    u8 pad[0x14];
    s32 x14;
    s32 x18;
} Tm;
extern u32 lbl_80347494;
extern s32 lbl_80346C28;
extern void fn_800E3594(void);
extern s32 lbl_80346DD4;
typedef struct Rec {
    u8 pad[0x12C];
    s16 x12c;
} Rec;
typedef struct FindEntry {
    struct FindEntry *prev;
    struct FindEntry *next;
    s32 value;
    u8 pad_0c[4];
    s16 id;
} FindEntry;
extern FindEntry *lbl_80302D78[12];
extern FindEntry *fn_8008F2CC(FindEntry *head, s16 id);
extern void fn_801DD5E8(Angle *out, NJS_POINT3 *p);
extern f32 fn_80291A5C(f32 x);
typedef struct {
    u8 pad_00[0x10];
    f32 f[3];
    u32 w[3];
} Table8009539C;
extern Table8009539C lbl_80311970;
typedef struct {
    u8 mode;
    u8 flags;
    s16 field2;
    u8 pad_04[0x70 - 4];
} SeFlagBlock;
extern s16 lbl_80346C3C;
extern s16 lbl_80302F18[408];
extern SeFlagBlock lbl_802E0084;
s32 fn_80078610(s8 idx);
void fn_800804B8(void);
void fn_8008DEEC(void);
extern s16 lbl_80347374;
typedef struct {
    NJS_TEXLIST* texlist; /* 0x00 */
    void* obj;            /* 0x04 */
    f32 tx, ty, tz;       /* 0x08 */
    Angle rx, ry, rz;     /* 0x14 */
    f32 sx, sy, sz;       /* 0x20 */
} Xform;
void fn_80299040(NJS_TEXLIST* texlist);
void njPushMatrixEx(void);
void njPopMatrixEx(void);
void fn_80286EE8(void);
void fn_8028B498(void);
void fn_80288FC8(void* obj);
void njTranslate(NJS_MATRIX m, f32 x, f32 y, f32 z);
void njScale(NJS_MATRIX m, f32 x, f32 y, f32 z);
void fn_801E7E14(s32 a, s16 b, s16 c, s32 mode);
typedef struct {
    s32 x; /* 0x00 */
    s32 y; /* 0x04 */
    s32 z; /* 0x08 */
} Src;
typedef struct {
    f32 x; /* 0x00 */
    f32 y; /* 0x04 */
    f32 z; /* 0x08 */
} Vec3F;
f32 fn_802918DC(f32 x);
extern void* lbl_80347450;
s32 fn_8015F1F0(void* p);
void fn_801DD3B8(void* a, void* b, void* c);
typedef struct { f32 x, y, z; } Vec3_8008B600;
typedef struct { u8 pad[0x1c]; Vec3_8008B600 v; } Sub_8008B600;
typedef struct { u8 pad[0x24]; Sub_8008B600 *x24; } Ent_8008B600;
extern Ent_8008B600 *fn_80021658(s8 idx);
extern s32 fn_80078610(s8 idx);
extern f32 fn_80071E9C(void*a, void*b);
typedef struct { s16 x0; } SubD;
typedef struct { u8 pad[0x19]; u8 x19; u8 pad1[0x24 - 0x1a]; SubD *x24; } ObjD;
extern void *lbl_80302D48[12];
extern void fn_801E17E0(void *p);
typedef struct Vec3_8009009C { f32 x; f32 y; f32 z; } Vec3_8009009C;
extern f32 lbl_80348B38;
void fn_80095220(void *obj, f32 *a, f32 *b);
typedef struct {
    s16 idx;
    s16 s2;
    u32 flags;
    u8 pad8[0x50 - 8];
    u8 b50;
} Sub_8008BE94;
typedef struct {
    u8 pad0[0x19];
    u8 state;
    u8 pad1a[0x24 - 0x1a];
    Sub_8008BE94* sub;
} Obj_8008BE94;
extern s16 lbl_80309DCC[12];
extern s32 lbl_8034733C;
extern void fn_80081168(s32 i, s32 k);
extern s32 fn_8006D1C4(void);
extern void fn_80080438(void* o);
typedef struct {
    s16 idx;
    u8 pad2[0x4c - 2];
    u32 w4c;
    u8 b50;
} Sub_8008C124;
typedef struct {
    u8 pad0[0x19];
    u8 state;
    u8 pad1a[0x24 - 0x1a];
    Sub_8008C124* sub;
} Obj_8008C124;
typedef struct {
    s16 idx;
    u8 pad2[0x4c - 2];
    u32 w4c;
    u8 b50;
} Sub_8008C6BC;
typedef struct {
    u8 pad0[0x19];
    u8 state;
    u8 pad1a[0x24 - 0x1a];
    Sub_8008C6BC* sub;
} Obj_8008C6BC;
void fn_8008C6BC(Obj_8008C6BC* o);
typedef struct {
    s16 idx;
    u8 pad2[2];
    u32 flags;
    u8 pad8[0x4c - 8];
    u32 w4c;
    s8 b50;
} Sub_8008CAB4;
typedef struct {
    u8 pad0[0x19];
    u8 state;
    u8 pad1a[0x24 - 0x1a];
    Sub_8008CAB4* sub;
} Obj_8008CAB4;
typedef struct {
    u8 pad0[0xae];
    s16 sae;
} Chr_8008D3B0;
typedef Slot Obj_8008D3B0;
typedef Sub80309700 Sub_8008D3B0;
extern s8 lbl_80347334;
extern void fn_8008CDA8(void* o);
extern s32 memcmp(const void* a, const void* b, u32 n);
typedef struct {
    u8 pad00[0x4];
    f32 pos_buf[12];  /* 0x04 */
    s32 idx_buf[4];   /* 0x34 */
    s16 uv_buf[8];    /* 0x44 */
    f32* pos;         /* 0x54 */
    s32* idx;         /* 0x58 */
    s16* uv;          /* 0x5C */
    s32 count;        /* 0x60 */
    u8 pad64[0x70 - 0x64];
    s32 a, b, c;      /* 0x70 */
    f32 x, y, z;      /* 0x7C */
} UnitQuad;
typedef struct {
    f32 x, y, z;
    f32 h;
    s16 a;
    u16 b;
} Probe;
typedef struct {
    u8 pad00[2];
    s16 flags;       /* 0x02 */
    u8 pad04[0x0C];
    f32 y;           /* 0x10 */
    u8 pad14[0x74 - 0x14];
    void* mtx;       /* 0x74 */
    u8 pad78[0xF0 - 0x78];
    f32 ox, oy, oz;  /* 0xF0 */
    u8 padFC[4];
    s32 ang;         /* 0x100 */
    s32 ang_out;     /* 0x104 */
} Obj80094B20;
extern void fn_801DCE18(f32* in, f32* out, void* mtx);
extern s32 fn_80224588(s32 a, Probe* p, s32 b);
typedef struct {
    u8 pad0[0x14];
    s16 flags;
} Sub8009564C;
typedef struct {
    u8 pad00[2];
    s16 flags;         /* 0x02 */
    s16 mode;          /* 0x04 */
    s16 s6;            /* 0x06 */
    u8 pad08[4];
    f32 pos[3];        /* 0x0C */
    u8 pad18[0x24 - 0x18];
    f32 p24[3];        /* 0x24 */
    f32 v30[3];        /* 0x30 */
    u8 pad3C[0x4C - 0x3C];
    f32 p4C[3];        /* 0x4C */
    u8 pad58[0x70 - 0x58];
    s32 z70, z74, z78; /* 0x70 */
    u8 pad7C[0x94 - 0x7C];
    f32 a94[3];        /* 0x94 */
    f32 aA0[3];        /* 0xA0 */
    u8 padAC[0xDC - 0xAC];
    f32 fDC;           /* 0xDC */
    s32 e0;            /* 0xE0 */
    s16 e4;            /* 0xE4 */
    u8 padE6[0x108 - 0xE6];
    Sub8009564C* sub;  /* 0x108 */
} Obj8009564C;
typedef struct Data {
    s16 id;
    u8 pad2[0xA];
    s8 xc;
    s8 xd;
} Data;
typedef struct Obj {
    u8 pad0[0x19];
    u8 state;
    u8 pad1a[0xA];
    Data* d;
} Obj;
typedef struct Sub {
    u8 pad0[4];
    void* x4;
} Sub;
typedef struct Item {
    u8 pad0[8];
    Sub sub;
} Item;
typedef struct Res {
    u8 pad0[0x20];
    void* x20;
} Res;
typedef struct List {
    s32 count;
    Item* items[1];
} List;
typedef struct Info {
    u8 pad0[0x14];
    List* x14;
    u8 pad18[8];
    void* x20;
} Info;
typedef struct Data_8008F760 {
    u8 pad0[0x17C];
    void* x17c;
    u8 pad180[0x48];
    Info* x1c8;
    u8 pad1cc[4];
    struct Data_8008F760* x1d0;
} Data_8008F760;
typedef struct Other_8008F760 {
    u8 pad0[0x24];
    Data_8008F760* d;
} Other_8008F760;
typedef struct Obj_8008F760 {
    u8 pad0[0x19];
    u8 state;
    u8 pad1a[0xA];
    Data_8008F760* d;
} Obj_8008F760;
typedef struct Part {
    u8 pad0[0x38];
    NJS_POINT3 pos;     /* 0x38 */
    Angle rot[3];       /* 0x44 */
    u8 pad50[0x64];
    NJS_POINT3 pos2;    /* 0xB4 */
    Angle rot2[3];      /* 0xC0 */
    u8 padcc[0xA0];
    s16 x16c;
} Part;
typedef struct Part2 {
    u8 pad0[0x1D8];
    struct Part2* x1d8;
} Part2;
typedef struct Ref {
    u8 pad0[0x18];
    u8 flags;
    u8 pad19[0xB];
    Part* d;
} Ref;
typedef struct Actor {
    u8 pad0[0xE8];
    u32 id;
    Ref* ref;
} Actor;
extern void njTranslate(NJS_MATRIX m, f32 x, f32 y, f32 z);
extern void njRotateZXY(NJS_MATRIX m, Angle x, Angle y, Angle z);
extern Ref* fn_801094C8(u32 id);
extern s32 fn_8015F1F0(void* p);
extern void fn_801DBE1C(const char* fmt, ...);
extern char lbl_802B0D78[];
extern f32 lbl_802B0D6C[3];
typedef struct Probe_800912FC {
    f32 x, y, z;
    f32 h;
    s16 a;
    u16 b;
} Probe_800912FC;
typedef struct Obj_800912FC {
    u8 pad0[0x18];
    f32* p18;
} Obj_800912FC;
typedef struct Chr_8008CBB8 {
    u8 pad0[0xae];
    s16 flags;
} Chr_8008CBB8;
extern s32 fn_80083BAC(s32 i, s32 k);
extern void fn_80010474(s32 i);
extern void fn_8008CAB4(Obj_8008CAB4*);
/* Stores a 2D point and a value: lbl_80346C44 = *pos; lbl_80346C38 = n.
 * lbl_80346C44 must be 8 bytes (an x,y pair; symbols.txt guesses 0xC) so it stays
 * small-data and is addressed with `li r5,sym@sda21` instead of lis/stfsu. */
typedef float f32;
typedef struct Vec2_80346C44 { f32 x, y; } Vec2_80346C44;
extern Vec2_80346C44 lbl_80346C44;
extern int lbl_80346C38;
typedef struct Lim {
    u8 pad[6];
    s16 x6;
    s16 x8;
    s16 xa;
} Lim;
extern Lim* lbl_80347390;
typedef NJS_POINT3 Vec;
typedef struct {
    u8 pad0[0x1C];
    Vec pos;      /* 0x1C */
    s32 rot[3];   /* 0x28 */
    u8 pad34[0x4C - 0x34];
    void* body;   /* 0x4C */
} Unit_8008E3BC;
typedef struct {
    u8 pad[0x24];
    Unit_8008E3BC* unit;
} Owner_8008E3BC;
typedef struct {
    u8 pad0[0x12];
    s16 len;
} Info_8008E3BC;
typedef struct {
    u8 pad0[0x5C];
    s32 x5c;
    u8 pad60[8];
    f32 x68;
    u8 pad6c[0x154 - 0x6C];
    void* x154;
    u8 pad158[0x194 - 0x158];
    s32 x194;
    s32 x198;
    f32 x19c;
} Body;
typedef struct {
    Owner_8008E3BC* owner;     /* 0x00 */
    Info_8008E3BC* info;       /* 0x04 */
    void* model;      /* 0x08 */
    u8 pad0c[4];
    void* x10;        /* 0x10 */
    u8 pad14[0x24 - 0x14];
    Vec pos;          /* 0x24 */
    s32 rot[3];       /* 0x30 */
    Vec scale;        /* 0x3C */
    u8 pad48[4];
    u8 x4c;           /* 0x4C */
    u8 pad4d[0x54 - 0x4D];
    u8 x54[0x94 - 0x54];
    s32 x94;
    u8 x98[0xC8 - 0x98];
    s32 xc8;
    s32 xcc;
    f32 xd0;
    DrawState ds;     /* 0xD4 */
    s16 t;            /* 0xFC */
    s16 xfe;
} Work_8008E3BC;
typedef struct {
    u8 pad0[0x18];
    u8 flags;
    u8 state;
    u8 pad1a[0x24 - 0x1A];
    Work_8008E3BC* work;
} Node_8008E3BC;
extern void fn_8006D954(s32);
extern void fn_8006D8DC(s32);
extern void fn_8007638C(void*, void*, u16);
extern void fn_80076478(void*, void*, u16, int);
extern void fn_80071CF0(Vec*, Vec*);
extern void fn_80060950(void*);
extern void fn_8007576C(void*, s32);
extern void fn_80032E44(void*);
extern void fn_80035380(void*, s32, f32, s32);
extern void fn_800D2048(void);
typedef struct {
    u8 pad[0x38];
    f32 x38;
    u8 pad3c[4];
    f32 x40;
} Cam;
typedef struct { u8 b[0x2e]; } Rec_8008F9B8;
typedef struct {
    u8 pad[0x17A];
    u16 id;
} Ent;
extern s32 lbl_80311AD4[11];
extern u8* lbl_80347468;
extern s32 lbl_80346C2C;
extern u32 lbl_802DFF1C[0x2e];
extern Ent* lbl_80302E18[0x40];
extern char lbl_802B0D00[];
extern char lbl_802B0D20[];
extern s32 fn_8009014C(u8* arr, u8* key, s32 n, s32 size);
extern int fn_8025CB24(char* buf, const char* fmt, ...);
typedef struct Chr_8008C98C {
    u8 pad[0xae];
    s16 xae;
} Chr_8008C98C;
typedef struct Sub_8008C98C {
    s16 idx;
    u8 pad2[6];
    Chr_8008C98C* chr;
    u8 padc[0x4c - 0xc];
    s32 x4c;
    u8 b50;
} Sub_8008C98C;
typedef struct Slot_8008C98C {
    void *fn_8008C98C;
    u8 pad4[0x19 - 4];
    u8 state;
    u8 pad1a[0x24 - 0x1a];
    Sub_8008C98C* sub;
} Slot_8008C98C;
typedef struct Pt {
    f32 x;       /* 0x00 */
    f32 y;       /* 0x04 */
    f32 z;       /* 0x08 */
    f32 top;     /* 0x0C */
    f32 floor;   /* 0x10 */
    s16 lo;      /* 0x14 */
    s16 hi;      /* 0x16 */
    u16 loflags; /* 0x18 */
    u16 hiflags; /* 0x1A */
    u8 pad1c[8];
} Pt;
extern void fn_8022436C(s32 a, Pt *p, s32 b);
typedef struct CamObj CamObj;
typedef struct CamLink {
    u8 pad0[8];
    CamObj *target;     /* 0x08 */
} CamLink;
struct CamObj {
    u8 pad0[0x44];
    Angle ang[3];       /* 0x44 */
    u8 pad50[0x1D8 - 0x50];
    CamLink *link;      /* 0x1D8 */
};
typedef struct CamCtrl {
    s8 mode;            /* 0x00 */
    u8 flags;           /* 0x01 */
    s16 field2;         /* 0x02 */
    u8 pad4[0x10 - 0x4];
    f32 x10;            /* 0x10 */
    f32 x14;            /* 0x14 */
    f32 x18;            /* 0x18 */
    u8 pad1c[0x40 - 0x1C];
    Angle dir[3];       /* 0x40 */
    u8 pad4c[0x70 - 0x4C];
} CamCtrl;
typedef struct Glob {
    u8 pad0[0x84];
    u32 x84;
} Glob;
extern Glob lbl_80310B3C;
extern s32 lbl_803473DC;
extern s32 lbl_80347408;
extern void fn_801DD14C(Angle *out, Angle *a, Angle *b);
extern f32 fn_80116028(void);

u32 fn_8008B55C(void* a0, Ent_UNIT0000* e) {
    return (e->x1c >> 9) & 1;
}

s32 fn_8008B568(void) {
    return lbl_80347340 == 8;
}

s32 fn_8008B580(void) {
    return lbl_80347340 == 4;
}

s32 fn_8008B598(void) {
    return lbl_80347340 == 3;
}

s32 fn_8008B5B0(void) {
    return lbl_80347340 == 2;
}

s32 fn_8008B5C8(void) {
    return lbl_80347340 == 1;
}

s32 fn_8008B6C4(s32 a) {
    s32 i;
    Vec3_8008B600 A;
    Vec3_8008B600 B;
    Sub_8008B600 *s;
    s = fn_80021658(a)->x24;
    A.x = s->v.x;
    A.y = s->v.y;
    A.z = s->v.z;
    for (i = 0; i <= 3; i++) {
        if (fn_80078610(i)) {
            s = fn_80021658(i)->x24;
            B.x = s->v.x;
            B.y = s->v.y;
            B.z = s->v.z;
            if (fn_80071E9C(&A, &B) >= 30.0f) {
                return 1;
            }
        }
    }
    return 0;
}

s32 fn_8008B84C(s32 a) {
    s32 i;
    Vec3_8008B600 A;
    Vec3_8008B600 B;
    Sub_8008B600 *s;
    s = fn_80021658(a)->x24;
    A.x = s->v.x;
    A.y = s->v.y;
    A.z = s->v.z;
    for (i = 0; i <= 3; i++) {
        if (fn_80078610(i)) {
            s = fn_80021658(i)->x24;
            B.x = s->v.x;
            B.y = s->v.y;
            B.z = s->v.z;
            if (fn_80071E9C(&A, &B) <= 30.0f) {
                return 0;
            }
        }
    }
    return 1;
}

u32 fn_8008B910(s32 i) {
    return (lbl_80309DE4[i]->x10 >> 1) & 1;
}

u32 fn_8008B92C(s32 i) {
    return lbl_80309DE4[i]->x10 & 1;
}

s32 fn_8008B948(void* a0, Tm* t) {
    return (t->x18 / 10) >= t->x14;
}

s32 fn_8008B97C(void* a0, Tm* t) {
    return !((t->x18 / 4) < t->x14);
}

s32 fn_8008B9A0(void* a0, Tm* t) {
    return !((t->x18 / 2) < t->x14);
}

s32 fn_8008B9C8(void* a0, Tm* t) {
    return t->x18 == t->x14;
}

void fn_8008F288(s16 slot, s16 id, s32 value) {
    FindEntry *e = fn_8008F2CC(lbl_80302D78[slot], id);
    e->value = value;
}

void fn_8008F75C(void) {
}

u32 fn_8008F980(void) {
    u32 v = lbl_80347494;
    lbl_80347494 = v + 1;
    if (v > 0xffdc) {
        lbl_80347494 = 0x10000 - 0x218;
    }
    return lbl_80347494;
}

void fn_8008F9A8(void) {
    lbl_80347494 = 0x10000 - 0x218;
}

s32 fn_8008FC48(void) {
    return lbl_80346C28;
}

void fn_800906E8(Xform* o) {
    fn_80299040(o->texlist);
    njPushMatrixEx();
    fn_80286EE8();
    fn_8028B498();
    njTranslate(0, o->tx, o->ty, o->tz);
    njRotateXYZ(0, o->rx, o->ry, o->rz);
    njScale(0, o->sx, o->sy, o->sz);
    fn_802872D4(o->obj);
    njPopMatrixEx();
}

s32 fn_80090D78(void) {
    fn_800E3594();
    return lbl_80346DD4;
}

typedef struct Msg {
    s16 x0;
    s16 x2;
    s16 x4;
    s16 x6;
    s32 x8;
    s32 xc;
} Msg;
extern void fn_800E36B0(Msg*, s16);
void fn_80090D9C(Msg* a, s16 i) {
    fn_800E36B0(a, i);
}

void fn_80090EE8(void) {
}

void fn_80090F9C(Angle *out, NJS_POINT3 *a, NJS_POINT3 *b) {
    NJS_POINT3 d;
    d.x = a->x - b->x;
    d.y = a->y - b->y;
    d.z = a->z - b->z;
    fn_801DD5E8(out, &d);
}

f32 fn_80090FF0(NJS_POINT3 *a, NJS_POINT3 *b) {
    f32 dx = a->x - b->x;
    f32 dy = a->y - b->y;
    f32 dz = a->z - b->z;
    return fn_80291A5C(dz * dz + (dx * dx + dy * dy));
}

s32 fn_800912A8(s32 a, s32 b, s32 c, s32 d) {
    s32 e = (u16)(a + (0x8000 - (u16)b)) - 0x8000;
    s32 q;

    if (e == 0) {
        return a;
    }
    if (e < 0) {
        e = -e;
        c = -c;
    }
    if (d <= e) {
        return b + c;
    }
    q = c * e / d;
    return q ? b + q : a;
}

void fn_8009539C(f32 *out_f, u32 *out_w) {
    out_f[0] = lbl_80311970.f[0];
    out_f[1] = lbl_80311970.f[1];
    out_f[2] = lbl_80311970.f[2];
    out_w[0] = (u16)lbl_80311970.w[0];
    out_w[1] = (u16)lbl_80311970.w[1];
    out_w[2] = (u16)lbl_80311970.w[2];
}

s32 fn_8009574C(void) {
    s32 ret = 0;
    if (lbl_80346C3C == 2) {
        if (lbl_80302F18[0] == 0xc) {
            lbl_802E0084.mode = 0xf;
            lbl_802E0084.field2 = 0;
            ret = 1;
        }
    }
    return ret;
}

void fn_80096230(Rec* r) {
    r->x12c = 7;
}

s32 fn_8008B4F8(s32 x) {
    s32 i;
    for (i = 4; i <= 11; i++) {
        if (i != x && fn_80078610((s8)i)) return 0;
    }
    return 1;
}

void fn_8008E2B0(s32 n) {
    s32 i;
    for (i = 0; i < 12; i++) {
        if (i != n && fn_80078610((s8)i)) {
            lbl_80309700[i]->sub->fn = (void*)fn_800804B8;
        }
    }
}

void fn_8008E338(s32 n) {
    s32 i;
    for (i = 0; i < 12; i++) {
        if (i != n && fn_80078610((s8)i)) {
            lbl_80309700[i]->sub->fn = (void*)fn_8008DEEC;
            lbl_80347374 |= 1 << i;
        }
    }
}

void fn_80090664(Xform* o) {
    fn_80299040(o->texlist);
    njPushMatrixEx();
    fn_80286EE8();
    fn_8028B498();
    njTranslate(0, o->tx, o->ty, o->tz);
    njRotateXYZ(0, o->rx, o->ry, o->rz);
    njScale(0, o->sx, o->sy, o->sz);
    fn_80288FC8(o->obj);
    njPopMatrixEx();
}

void fn_80090A20(s32 a, s16 x, s16 y) {
    if (x && y) {
        fn_801E7E14(a, x, y, 2);
    } else if (x) {
        fn_801E7E14(a, x, y, 0);
    } else if (y) {
        fn_801E7E14(a, x, y, 1);
    }
}

void fn_80090B68(Src* s, f32* d) {
    d[0] = (2400.0f * -(f32)s->x + 8400.0f) - 1200.0f;
    d[1] = 0.0f;
    d[2] = (2400.0f * -(f32)s->z + 7200.0f) - 1200.0f;
}

void fn_80090D20(Vec3F* s, s32* out) {
    out[0] = (s32)((8400.0f - s->x) / 2400.0f);
    out[1] = 0;
    out[2] = (s32)((7200.0f - s->z) / 2400.0f);
}

s32 fn_80091228(s32 base, s32 val, f32 scale) {
    u16 d = (u16)(base + (0x8000 - (u16)val));
    s32 v = (s32)d - 0x8000;
    if (v == 0) return base;
    return val + (s32)fn_802918DC((f32)v / scale);
}

void fn_8009519C(void* a, void* b) {
    u8* p = (u8*)lbl_80347450;
    if (p) {
        if (fn_8015F1F0(p)) {
            u8* q = *(u8**)(p + 0x1d8);
            if (q) {
                u8* r = *(u8**)(q + 8);
                if (r) p = r;
            }
        }
        fn_801DD3B8(a, b, p + 0x44);
    }
}

s32 fn_8008B600(s32 a) {
    s32 i;
    Vec3_8008B600 A;
    Vec3_8008B600 B;
    Sub_8008B600 *s;
    s = fn_80021658(a)->x24;
    A.x = s->v.x;
    A.y = s->v.y;
    A.z = s->v.z;
    for (i = 0; i <= 3; i++) {
        if (fn_80078610(i)) {
            s = fn_80021658(i)->x24;
            B.x = s->v.x;
            B.y = s->v.y;
            B.z = s->v.z;
            if (fn_80071E9C(&A, &B) >= 45.0f) {
                return 1;
            }
        }
    }
    return 0;
}

s32 fn_8008B788(s32 a) {
    s32 i;
    Vec3_8008B600 A;
    Vec3_8008B600 B;
    Sub_8008B600 *s;
    s = fn_80021658(a)->x24;
    A.x = s->v.x;
    A.y = s->v.y;
    A.z = s->v.z;
    for (i = 0; i <= 3; i++) {
        if (fn_80078610(i)) {
            s = fn_80021658(i)->x24;
            B.x = s->v.x;
            B.y = s->v.y;
            B.z = s->v.z;
            if (fn_80071E9C(&A, &B) <= 45.0f) {
                return 0;
            }
        }
    }
    return 1;
}

void fn_8008D610(ObjD *o) {
    s32 idx;
    idx = o->x24->x0;
    switch (o->x19) {
    case 0:
        fn_800811E4(idx, 0);
        o->x19 = 1;
    case 1:
        if (fn_8007FFE8(idx, 0)) {
            lbl_80309700[idx]->fn = (void*)fn_8008C6BC;
            lbl_80309700[idx]->state = 0;
        }
        break;
    }
}

s32 fn_8008F508(s16 idx, s16 id) {
    FindEntry *e;
    if (lbl_80302D78[idx] == 0) {
        return 0;
    }
    e = fn_8008F2CC(lbl_80302D78[idx], id);
    if (e == 0) {
        return 0;
    }
    if (e->prev == 0) {
        if (e->next == 0) {
            lbl_80302D78[idx] = 0;
            fn_801E17E0(lbl_80302D48[idx]);
            lbl_80302D48[idx] = 0;
        } else {
            lbl_80302D78[idx] = e->next;
            lbl_80302D78[idx]->prev = 0;
        }
    } else {
        e->prev->next = e->next;
    }
    fn_801E17E0(e);
    return 1;
}

void fn_8009009C(Vec3_8009009C *v, f32 s) {
    f32 k;
    if (lbl_80348B38 == v->x && lbl_80348B38 == v->y && lbl_80348B38 == v->z) {
        v->x = s;
        return;
    }
    k = s / fn_80291A5C(v->z * v->z + (v->x * v->x + v->y * v->y));
    v->x = v->x * k;
    v->y = v->y * k;
    v->z = v->z * k;
}

f32 fn_80090EEC(void *obj, f32 t) {
    f32 v3[3];
    f32 v2[3];
    f32 v1[3];
    f32 v0[3];
    f32 x;
    f32 y;
    f32 z;
    fn_80095220(obj, v3, v2);
    fn_801DD3B8(v1, v0, v2);
    x = v0[0] * t + v3[0];
    y = v0[1] * t + v3[1];
    z = v0[2] * t + v3[2];
    v1[0] = lbl_80311970.f[0] - x;
    v1[1] = lbl_80311970.f[1] - y;
    v1[2] = lbl_80311970.f[2] - z;
    return v1[0] * v1[0] + v1[1] * v1[1] + v1[2] * v1[2];
}

s32 fn_80094C34(u8 *p) {
    s32 r = 0;
    s16 a = *(s16 *)(p + 0x16);
    if (a == 0) {
        goto L68;
    }
    if (*(s16 *)(p + 0x14) != 0) {
        goto L68;
    }
    if ((*(u16 *)(p + 0x1a) & 0x1800) != 0x1800) {
        r = 1;
    }
    goto end;
L68:
    if (a == 0) {
        goto end;
    }
    if (*(s16 *)(p + 0x14) == 0) {
        goto end;
    }
    if ((*(u16 *)(p + 0x1a) & 0x400) != 0) {
        r = 1;
        goto end;
    }
    if ((*(u16 *)(p + 0x1a) & 0x1800) == 0x1800) {
        goto end;
    }
    if (5.0f < *(f32 *)(p + 0xc) - *(f32 *)(p + 0x4)) {
        r = 1;
        goto end;
    }
    if ((*(u16 *)(p + 0x18) & 0x400) != 0) {
        r = 1;
        goto end;
    }
    if (5.0f < *(f32 *)(p + 0x4) - *(f32 *)(p + 0x10)) {
        r = 1;
    }
end:
    return r;
}

void fn_8008BE94(Obj_8008BE94* o) {
    Sub_8008BE94* s = o->sub;
    s32 i = s->idx;
    switch (o->state) {
    case 0:
        s->b50 = 3;
        lbl_80309730[i].b8 = 1;
        if (!(lbl_80309DE4[i]->flags & 0x2100)) {
            fn_80081168(i, 0x13);
            lbl_80347374 |= 1 << i;
            lbl_80309730[i].b9 = 1;
            o->state = 1;
        }
        break;
    case 1:
        if (lbl_8034733C != 4 && fn_8006D1C4() == 1) {
            lbl_80309DCC[i] = s->s2;
            s->flags &= ~0x20;
            fn_800811E4(i, 0);
            o->state = 10;
        }
        break;
    case 10:
        if (fn_8007FFE8(i, 0) != 0) {
            fn_80080438(o);
        }
        break;
    }
}

void fn_8008C124(Obj_8008C124* o) {
    Sub_8008C124* s = o->sub;
    s32 i = s->idx;
    switch (o->state) {
    case 0:
        fn_800811E4(i, 2);
        s->w4c = lbl_80309730[i].w0;
        s->b50 = 0;
        o->state = 1;
        break;
    case 1:
        if (fn_8007FFE8(i, 2) != 0) {
            s->b50 = 1;
            o->state = 2;
        }
        break;
    case 2:
        fn_80080438(o);
        break;
    case 20:
        if (fn_8007FFE8(i, 0x12) != 0) {
            fn_800811E4(i, s->w4c);
            o->state = 1;
        }
        break;
    }
}

void fn_8008C6BC(Obj_8008C6BC* o) {
    Sub_8008C6BC* s = o->sub;
    s32 i = s->idx;
    switch (o->state) {
    case 0:
        s->w4c = lbl_80309730[i].w0;
        fn_800811E4(i, s->w4c);
        s->b50 = 0;
        o->state = 1;
    case 1:
        if (fn_8007FFE8(i, 0) != 0) {
            s->b50 = 1;
            o->state = 2;
        }
        break;
    case 2:
        fn_80080438(o);
        break;
    case 20:
        if (fn_8007FFE8(i, 0x12) != 0) {
            fn_800811E4(i, s->w4c);
            o->state = 1;
        }
        break;
    }
}

void fn_8008CAB4(Obj_8008CAB4* o) {
    Sub_8008CAB4* s = o->sub;
    s32 i = s->idx;
    switch (o->state) {
    case 0:
        if (s->b50 == 4) {
            o->state = 1;
        }
        if (s->b50 == 5) {
            o->state = 1;
        }
        lbl_80309730[i].b9 = 1;
        break;
    case 1:
        if (lbl_8034733C != 4 && fn_8006D1C4() == 1) {
            s->flags &= ~0x20;
            fn_800811E4(i, s->w4c);
            o->state = 10;
        }
        break;
    case 10:
        if (fn_8007FFE8(i, 0) != 0) {
            fn_80080438(o);
        }
        break;
    }
}

void fn_8008D3B0(Obj_8008D3B0* o) {
    s32 i;
    s32 v;
    Sub_8008D3B0* s = o->sub;
    Chr_8008D3B0* c;
    c = (Chr_8008D3B0*)s->chr;
    i = s->idx;
    v = lbl_80347334;
    switch (o->state) {
    case 0:
        if (fn_8007FFE8(i, 0x16) != 0) {
            if (c->sae & 0x400) {
                lbl_80309730[i].b4 = v;
                fn_800811E4(i, 2);
            } else {
                fn_800811E4(i, 0);
            }
            s->b50 = 0;
            o->state = 1;
        } else {
            break;
        }
    case 1:
        if (fn_8007FFE8(i, 0) != 0) {
            lbl_80309700[i]->fn = (void*)fn_8008CDA8;
            lbl_80309700[i]->state = 0;
        }
        break;
    }
}

s32 fn_8009014C(u8* arr, u8* key, s32 n, s32 size) {
    s32 i;
    u8* p;
    switch (size) {
    case 1:
        p = arr;
        for (i = 0; i < n; i++) {
            if (memcmp(p, key, 1) == 0) {
                return i;
            }
            p += 1;
        }
        break;
    case 2:
        p = arr;
        for (i = 0; i < n; i++) {
            if (memcmp(p, key, 2) == 0) {
                return i;
            }
            p += 2;
        }
        break;
    case 4:
        p = arr;
        for (i = 0; i < n; i++) {
            if (memcmp(p, key, 4) == 0) {
                return i;
            }
            p += 4;
        }
        break;
    }
    return -1;
}

s32 fn_80090278(s32 n) {
    s32 i;
    for (i = 1; i < 15; i++) {
        n /= 10;
        if (n == 0) {
            return i;
        }
    }
    return 0;
}

void fn_80090404(void* tex, u32 colour, f32 x, f32 y, f32 z, f32 w, f32 h, f32 u, f32 v, f32 du, f32 dv) {
    Vertex2D vt[4];

    vt[0].x = x;
    vt[0].y = y;
    vt[1].x = x + w;
    vt[1].y = y;
    vt[2].x = x;
    vt[2].y = y + h;
    vt[3].x = x + w;
    vt[3].y = y + h;
    z = fn_801DBD9C(z);
    vt[3].z = z;
    vt[2].z = z;
    vt[1].z = z;
    vt[0].z = z;
    vt[0].u = u;
    vt[0].v = v;
    vt[1].u = u + du;
    vt[1].v = v;
    vt[2].u = u;
    vt[2].v = v + dv;
    vt[3].u = u + du;
    vt[3].v = v + dv;
    vt[3].colour = colour;
    vt[2].colour = colour;
    vt[1].colour = colour;
    vt[0].colour = colour;
    fn_80297DC8(tex);
    fn_80291064(vt, 4, 1);
}

void fn_8009090C(UnitQuad* q) {
    q->a = 0;
    q->b = 0;
    q->c = 0;
    q->x = 1.0f;
    q->y = 1.0f;
    q->z = 1.0f;
    q->pos = q->pos_buf;
    q->idx = q->idx_buf;
    q->uv = q->uv_buf;
    q->count = 4;
    q->pos[0] = -1.0f;
    q->pos[1] = -1.0f;
    q->pos[3] = 1.0f;
    q->pos[4] = -1.0f;
    q->pos[6] = 1.0f;
    q->pos[7] = 1.0f;
    q->pos[9] = -1.0f;
    q->pos[10] = 1.0f;
    q->uv[0] = 0;
    q->uv[1] = 0;
    q->uv[2] = 0x100;
    q->uv[3] = 0;
    q->uv[4] = 0x100;
    q->uv[5] = 0x100;
    q->uv[6] = 0;
    q->uv[7] = 0x100;
    q->pos[2] = 0.0f;
    q->idx[0] = -1;
    q->pos[5] = 0.0f;
    q->idx[1] = -1;
    q->pos[8] = 0.0f;
    q->idx[2] = -1;
    q->pos[11] = 0.0f;
    q->idx[3] = -1;
}

s32 fn_80090BE4(f32* pos, s32* dir) {
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

void fn_80094B20(Obj80094B20* o) {
    Probe p;

    if (!(o->flags & 2)) {
        o->ang_out = o->ang;
        return;
    }
    p.x = 0.0f;
    p.y = 0.0f;
    p.z = -16.0f;
    fn_801DCE18(&p.x, &p.x, o->mtx);
    p.x += o->ox;
    p.y += o->oy;
    p.z += o->oz;
    if (fn_80224588(0, &p, 1) != 0 && p.a != 0 && (p.b & 0x1800) != 0x1800) {
        f32 a = (f32)atan2(p.h - o->y, 6.0);
        s32 base = o->ang;
        o->ang_out = base + (s32)(10430.381f * a) / 3;
    }
}

void fn_8009564C(Obj8009564C* o, Obj8009564C* src) {
    s32 mode;

    if (o->sub != 0) {
        o->sub->flags |= 0x8000;
    }
    if (!(src->flags & 4)) {
        o->v30[0] = 0.0f;
        o->v30[1] = 17.0f;
        o->v30[2] = 4.0f;
    }
    o->p24[0] = o->aA0[0] * o->v30[1] + o->pos[0];
    o->p24[1] = o->aA0[1] * o->v30[1] + o->pos[1];
    o->p24[2] = o->aA0[2] * o->v30[1] + o->pos[2];
    o->p4C[0] = o->a94[0] * o->v30[2] + o->p24[0];
    o->p4C[1] = o->a94[1] * o->v30[2] + o->p24[1];
    o->p4C[2] = o->a94[2] * o->v30[2] + o->p24[2];
    o->z78 = 0;
    o->z74 = 0;
    o->z70 = 0;
    mode = 2;
    if (o->flags & 1) {
        mode = 1;
    }
    o->mode = mode;
    o->s6 = 1;
    o->fDC = 0.5f;
    o->e0 = 0x100;
    o->e4 = 0x78;
}

void fn_8008D4A4(Obj* o)
{
    extern s32 fn_8007FFE8(s32 id, s32 a);
    extern void fn_800811E4(s32 id, s32 a);
    extern void fn_8008178C(Data* d, s8 a, s8 b, s32 id);
    extern void fn_800810FC(s32 id);
    extern void fn_80081648(Data* d, s32 id);
    extern void fn_80080438(Obj* o);
    s32 id;
    Data* d = o->d;
    s32 a, b;
    id = d->id;
    switch (o->state) {
    case 0:
        if (fn_8007FFE8(id, 0)) {
            o->state = 1;
            if (d->xc == 1) {
                if (d->xd == 1) {
                    a = 1;
                    b = 7;
                } else {
                    a = 7;
                    b = 7;
                }
            } else {
                if (d->xd == 1) {
                    a = 1;
                    b = 1;
                } else {
                    a = 7;
                    b = 1;
                }
            }
            fn_8008178C(d, a, b, id);
            fn_800810FC(id);
            o->state = 1;
        }
        break;
    case 1:
        if (fn_8007FFE8(id, 4)) {
            fn_800811E4(id, 0);
            fn_80081648(d, id);
            fn_80080438(o);
            fn_800811E4(id, 0);
            o->state = 2;
        }
        break;
    case 2:
        if (fn_8007FFE8(id, 0)) {
            fn_80080438(o);
            o->state = 2;
        }
        break;
    }
}

void fn_8008F760(Obj_8008F760* o)
{
    extern Other_8008F760* fn_801094C8(void* p);
    extern void fn_80100B74(Obj_8008F760* o);
    extern void fn_80227810(void* p);
    extern void fn_802275A4(void* p, s32 a);
    Data_8008F760* d = o->d;
    Other_8008F760* p;
    Data_8008F760* t;
    Data_8008F760* n;
    List* l;
    s32 i;
    switch (o->state) {
    case 0:
    case 0xFE:
        p = fn_801094C8(d->x17c);
        if (p == 0) {
            fn_80100B74(o);
            break;
        }
        if (d->x1c8->x20 != 0) fn_80227810(d->x1c8->x20);
        l = d->x1c8->x14;
        for (i = 0; i < l->count; i++) {
            if (l->items[i] != 0) {
                Sub* s = &l->items[i]->sub;
                if (s->x4 != 0) fn_80227810(s);
            }
        }
        t = p->d;
        n = t->x1d0;
        t->x1d0 = d;
        d->x1d0 = n;
        o->state = 0xA;
        break;
    case 0xA:
        break;
    case 0xFF:
        p = fn_801094C8(d->x17c);
        if (p != 0) {
            for (t = p->d; t != 0; t = t->x1d0) {
                if (t->x1d0 == d) {
                    t->x1d0 = d->x1d0;
                    break;
                }
            }
        }
        if (d->x1c8->x20 != 0) fn_802275A4(d->x1c8->x20, 0);
        l = d->x1c8->x14;
        for (i = 0; i < l->count; i++) {
            if (l->items[i] != 0) {
                Sub* s = &l->items[i]->sub;
                if (s->x4 != 0) fn_802275A4(s, 0);
            }
        }
        fn_80100B74(o);
        break;
    }
}

void fn_80094F90(NJS_POINT3* out, Actor* o)
{
    NJS_POINT3 tmp = *(NJS_POINT3*)lbl_802B0D6C;
    NJS_MATRIX m;
    Part* p;
    if (o->ref != 0) {
        if (o->ref->flags & 0x40) {
            fn_801DBE1C(lbl_802B0D78, o->id);
            o->ref = 0;
            return;
        }
        if (*(u16*)((u8*)o->ref->d + 0x17A) != o->id) o->ref = fn_801094C8(o->id);
    } else {
        o->ref = fn_801094C8(o->id);
    }
    if (o->ref != 0) {
        p = o->ref->d;
        if (fn_8015F1F0(p)) {
            Part2* q = ((Part2*)p)->x1d8;
            if (q != 0 && *(Part**)((u8*)q + 8) != 0) p = *(Part**)((u8*)q + 8);
        }
        if (p->x16c != 0) {
            njUnitMatrix(m);
            njTranslate(m, p->pos.x, p->pos.y, p->pos.z);
            njRotateZXY(m, p->rot[0], p->rot[1], p->rot[2]);
            njTranslate(m, p->pos2.x, p->pos2.y, p->pos2.z);
            njRotateZXY(m, p->rot2[0], p->rot2[1], p->rot2[2]);
            njCalcPoint(m, &tmp, out);
        } else {
            out->x = p->pos.x;
            out->y = p->pos.y;
            out->z = p->pos.z;
        }
    }
}

s32 fn_800912FC(f32* pos, Obj_800912FC* o) {
    extern f32 njSin(s32 a);
    extern f32 njCos(s32 a);
    extern s32 fn_80224588(s32 a, Probe_800912FC* p, s32 b);
    extern void fn_80222838(void* p);
    extern s32 fn_80223194(s32 a, void* p);
    Probe_800912FC p;
    f32 r = 4.0f;
    f32 dx;
    f32 dz;
    f32 miny = pos[1];
    s32 ang;
    s32 n;
    n = 2;
    ang = 0;
    do {
        dx = r * njCos(ang);
        dz = r * njSin(ang);
        p.x = pos[0] + dx;
        p.y = pos[1];
        p.z = pos[2] + dz;
        fn_80224588(0, &p, 1);
        if (p.a == 0 || (p.b & 0x1800) == 0x1800) {
            break;
        }
        if ((p.b & 0x400) && miny > p.h) {
            miny = p.h;
        }
        p.x = pos[0] - dx;
        p.z = pos[2] - dz;
        fn_80224588(0, &p, 1);
        if (p.a == 0 || (p.b & 0x1800) == 0x1800) {
            break;
        }
        if ((p.b & 0x400) && miny > p.h) {
            miny = p.h;
        }
        ang += 0x4000;
        n--;
    } while (n > 0);
    if (n != 0) {
        return 0;
    }
    o->p18[0] = pos[0];
    o->p18[1] = miny;
    o->p18[2] = pos[2];
    fn_80222838(o);
    {
        s32 res = fn_80223194(0x1800, o);
        s32 bad = (res | -res) >> 31 & 1;
        if (bad) {
            return 0;
        }
    }
    pos[1] = miny;
    return 1;
}

void fn_8008CBB8(Slot* self) {
    s32 i;
    Sub80309700* sub;
    Chr_8008CBB8* chr;
    sub = self->sub;
    chr = sub->chr;
    i = sub->idx;
    switch (self->state) {
    case 0:
        sub->b50 = 0;
        self->state = 1;
    case 1:
        if (fn_8007FFE8(i, 0x16) != 0) {
            if ((chr->flags & 0x400) == 0) {
                fn_800811E4(i, 0);
                self->state = 2;
            } else {
                fn_800811E4(i, 2);
                self->state = 10;
                lbl_80309730[i].bd = fn_80083BAC(i, (i < 4) + 1);
            }
        }
        break;
    case 2:
        if (fn_8007FFE8(i, 0) != 0) {
            sub->x4c = 0;
            lbl_80309700[i]->fn = (void (*)(Slot *))fn_8008CAB4;
            lbl_80309700[i]->state = 0;
            sub->b50 = 3;
            fn_80010474(i);
        }
        break;
    case 10:
        if (fn_8007FFE8(i, 2) != 0) {
            sub->x4c = 2;
            lbl_80309730[i].bd = fn_80083BAC(i, (i < 4) + 1);
            sub->b50 = 3;
            lbl_80309700[i]->fn = (void (*)(Slot *))fn_8008CAB4;
            lbl_80309700[i]->state = 0;
            fn_80010474(i);
        }
        break;
    }
}

void fn_8008B5E0(s32 a) {
    fn_8008B788(a);
}

void fn_80095630(Vec2_80346C44* pos, int n) {
    lbl_80346C44.x = pos->x;
    lbl_80346C44.y = pos->y;
    lbl_80346C38 = n;
}

s32 fn_8008B4A0(void) {
    Lim* l = lbl_80347390;
    s32 over = l->x6 < l->x8 * 2;
    return !over;
}

s32 fn_8008B4D0(void) {
    Lim* l = lbl_80347390;
    s32 differ = l->x6 != l->x8;
    return !differ;
}

void fn_8008E3BC(Node_8008E3BC* node) {
    Work_8008E3BC* w = node->work;
    Info_8008E3BC* info = w->info;
    Body* body = (Body*)w->owner->unit->body;
    Unit_8008E3BC* unit = w->owner->unit;

    switch (node->state) {
    case 0:
        fn_8006D954(1);
        if (w->info->len != 0) {
            node->state = 1;
        } else {
            node->state = 2;
            return;
        }
        w->t = 0;
    case 1:
        if (w->t >= info->len) {
            w->t = 0;
            node->state = 2;
            fn_80076478(w->x54, body->x154, 0, 0);
            return;
        }
        w->t++;
        return;
    case 2:
        if (w->model != NULL) {
            fn_80071CF0(&unit->pos, &w->pos);
            w->rot[0] = unit->rot[0];
            w->rot[1] = unit->rot[1];
            w->rot[2] = unit->rot[2];
            w->x94 = body->x5c;
            w->xfe = body->x68;
            DrawStateDefault2D(&w->ds);
            node->state = 3;
        } else {
            node->state = 4;
        }
    case 3:
        w->scale.x -= 0.1f;
        w->scale.y += 0.05f * w->t;
        w->scale.z -= 0.1f;
        ((f32*)&w->ds.colour)[0] = -(0.1f * w->t);
        w->ds.control3d |= 0x800;
        w->ds.attr_or |= 0x800;
        if (((f32*)&w->ds.colour)[0] <= -1.0f) {
            ((f32*)&w->ds.colour)[0] = -1.0f;
            w->t = 0;
            node->state = 4;
        }
        w->xc8 = body->x194;
        w->xcc = body->x198;
        w->xd0 = body->x19c;
        if (w->xc8 == 1) {
            fn_80060950(&w->x98);
        }
        w->t++;
        DrawStatePush(&w->ds);
        if (w->model != NULL) {
            fn_8007576C(w->model, 1);
            fn_80032E44(w->x10);
            njPushMatrixEx();
            fn_80286EE8();
            fn_8028B498();
            njTranslate(NULL, w->pos.x, w->pos.y, w->pos.z);
            njRotateXYZ(NULL, w->rot[0], w->rot[1], w->rot[2]);
            njScale(NULL, w->scale.x, w->scale.y, w->scale.z);
            fn_80035380(w->model, w->x94, w->xfe, w->x4c);
            njPopMatrixEx();
            fn_8007576C(w->model, 0);
        }
        DrawStatePop(&w->ds);
        if (w->xc8 == 1) {
            fn_800D2048();
        }
        break;
    case 4:
        fn_8006D8DC(1);
        fn_8007638C(w->x54, body->x154, 0);
        node->state = 5;
        break;
    case 5:
        node->flags |= 0x40;
        break;
    }
}

void fn_8008F9B8(u16 key, u8* src) {
    char msg1[0x38];
    char msg2[0x34];
    int idx;
    int i;
    u8* dst;

    if (lbl_80311AD4[6] != 8) {
        idx = fn_8009014C(lbl_80347468, (u8*)&key, 0x40, 2);
        if (idx == -1) {
            fn_8025CB24(msg1, lbl_802B0D00, (s32)(*(Cam**)&lbl_80347450)->x38, (s32)(*(Cam**)&lbl_80347450)->x40);
            fn_801DBE1C((void *)(msg1));
            return;
        }
        dst = &lbl_80347468[idx * 0x2e + 0x80];
        for (i = 0; i < 0x2e; i++) {
            *dst++ = src[lbl_802DFF1C[i]];
        }
    } else {
        idx = fn_8009014C(lbl_80347468, (u8*)&key, 0x40, 2);
        if (idx == -1) {
            fn_8025CB24(msg2, lbl_802B0D20, (s32)(*(Cam**)&lbl_80347450)->x38, (s32)(*(Cam**)&lbl_80347450)->x40);
            fn_801DBE1C((void *)(msg2));
            return;
        }
        ((s16*)lbl_80347468)[idx] = 0;
        lbl_80346C2C--;
    }
    for (i = 0; i < 0x40; i++) {
        if (lbl_80302E18[i] != NULL && key == lbl_80302E18[i]->id) {
            lbl_80302E18[i] = NULL;
            break;
        }
    }
}

void fn_80095360(void *p, void *q)
{
    if (lbl_80347450 != 0) {
        fn_80095220(lbl_80347450, p, q);
    }
}

void fn_8008C98C(Slot_8008C98C* self) {
    s32 i;
    Sub_8008C98C* sub;
    Chr_8008C98C* chr;
    sub = self->sub;
    chr = sub->chr;
    i = sub->idx;
    switch (self->state) {
    case 0:
        if (fn_8007FFE8(i, 0x16) != 0) {
            if ((chr->xae & 0x400) == 0) {
                fn_800811E4(i, 0);
                self->state = 1;
            } else {
                s8 r;
                sub->x4c = 2;
                r = fn_80083BAC(i, (i < 4) + 1);
                lbl_80309730[i].bd = r;
                self->state = 1;
            }
        }
        break;
    case 1:
        if (fn_8007FFE8(i, 0) != 0) {
            ((Slot_8008C98C**)lbl_80309700)[i]->fn_8008C98C = (void *)fn_8008C6BC;
            ((Slot_8008C98C**)lbl_80309700)[i]->state = 0;
        }
        break;
    }
}

void fn_8008FFA4(f32 *in, f32 *out) {
    s32 cx;
    s32 cz;
    f32 bx;
    f32 bz;
    cx = (8400.0f - in[0]) / 2400.0f;
    cz = (7200.0f - in[2]) / 2400.0f;
    bx = 8400.0f + ((s32)-(2400.0f * cx) - 1200.0f);
    bz = 7200.0f + ((s32)-(2400.0f * cz) - 1200.0f);
    out[0] = in[0] - bx;
    out[1] = in[1];
    out[2] = in[2] - bz;
}

void fn_80091B4C(s32 n, f32 *pos, f32 *vel, Pt *p)
{
    f32 t = 1.0f;
    f32 dt = t;
    s32 cnt = n;
    f32 y;
    f32 f;

    do {
        p->x = pos[0] = pos[0] + vel[0];
        y = p->y = pos[1] + vel[1] * t;
        p->z = pos[2] = pos[2] + vel[2];
        fn_8022436C(0, p, 1);
        if (fn_80094C34((void *)(p))) {
            if (p->hi != 0 && (p->hiflags & 0x400)) {
                y = p->floor;
            } else {
                f = 9.0f + p->floor;
                if (y < f) {
                    y = f;
                    if (p->lo != 0 && (p->loflags & 0x400) && f > p->top) {
                        y = p->top;
                    }
                }
            }
            vel[1] = (y - pos[1]) / t;
        } else {
            p->hi = 0;
        }
        t += dt;
        p->y = y;
        p++;
    } while (--cnt > 0);
}

static inline void GetCamAngles(Angle *a, Angle *b)
{
    CamObj *p = (*(CamObj **)&lbl_80347450);

    if (p != NULL) {
        if (fn_8015F1F0((void *)(p)) && p->link != NULL && p->link->target != NULL) {
            p = p->link->target;
        }
        fn_801DD3B8((void *)(a), (void *)(b), (void *)(p->ang));
    }
}

s32 fn_8009578C(void)
{
    s32 ret = 0;
    f32 f;
    Angle a[3];
    Angle b[3];
    Angle v[3];

    if (lbl_80346C3C == 2) {
        if (lbl_80302F18[0] == 1 || lbl_80302F18[0] == 9) {
            if (!(lbl_80310B3C.x84 & 0x80000000) && !(lbl_80302F18[1] & 8) && lbl_803473DC == 0
                && fn_8015F1F0((void *)((*(CamObj **)&lbl_80347450))) == 0 && lbl_80347408 == 0) {
                (*(CamCtrl*)&lbl_802E0084).mode = 0xC;
                (*(CamCtrl*)&lbl_802E0084).field2 = 0;
                (*(CamCtrl*)&lbl_802E0084).flags = 0;
                GetCamAngles(a, b);
                fn_801DD14C(v, a, b);
                (*(CamCtrl*)&lbl_802E0084).field2 |= 0x4000;
                (*(CamCtrl*)&lbl_802E0084).dir[0] = v[0];
                (*(CamCtrl*)&lbl_802E0084).dir[1] = v[1];
                (*(CamCtrl*)&lbl_802E0084).dir[2] = v[2];
                f = fn_80116028();
                (*(CamCtrl*)&lbl_802E0084).field2 |= 4;
                ret = 1;
                (*(CamCtrl*)&lbl_802E0084).x10 = 0.0f;
                (*(CamCtrl*)&lbl_802E0084).x14 = f;
                (*(CamCtrl*)&lbl_802E0084).x18 = 4.0f;
                (*(CamCtrl*)&lbl_802E0084).flags &= ~1;
            }
        }
    }
    return ret;
}
