#include "types.h"
#include "ninja.h"
#include "game/task.h"
#include "game/save_8030B7F4.h"
#include "game/sprite.h"
#include "game/text.h"
#include "game/menu.h"
#include <math.h>

/* These strings open the file's .rodata, but no function left in the DOL uses them. */
const char lbl_802ACFA0[0x10] = "D%02d%03d00.MLK";
const char lbl_802ACFB0[0xC] = "PCWIN.MLK";
const char lbl_802ACFBC[0x14] = "%c%02d%03d%02X.MLK";

s32 fn_80020E10(const char* name) {
    if (strcmp(name, "MA000.MLD") == 0 || strcmp(name, "ma000.mld") == 0) {
        return 0;
    }
    if (strcmp(name, "MA001.MLD") == 0 || strcmp(name, "ma001.mld") == 0) {
        return 1;
    }
    if (strcmp(name, "MA002.MLD") == 0 || strcmp(name, "ma002.mld") == 0) {
        return 2;
    }
    if (strcmp(name, "MA003.MLD") == 0 || strcmp(name, "ma003.mld") == 0) {
        return 3;
    }
    if (strcmp(name, "MA004.MLD") == 0 || strcmp(name, "ma004.mld") == 0) {
        return 4;
    }
    if (strcmp(name, "MA005.MLD") == 0 || strcmp(name, "ma005.mld") == 0) {
        return 5;
    }
    return -1;
}

/* One row of the list: its label, the help line shown for the cursor row. */
typedef struct HudRow {
    s8 kind;
    s8 b;
    u8 pad2[2];
    s16 x4;
    u8 pad6[2];
    char* text;
    char* help; /* 0x0c */
} HudRow;
/* The argument block fn_80023D14 hands the task: a vertical list with a cursor. */
typedef struct ListArg {
    s8 count;   /* 0x00 */
    s8 kind;    /* 0x01: which list (picks the sprites) */
    s8 mask;    /* 0x02: entries shown */
    s8 cursor;  /* 0x03 */
    u8 pad4;
    s8 pages;   /* 0x05 */
    s8 input;   /* 0x06: 0 none, 1 up, 2 down */
    u8 flags;   /* 0x07: 1 input pending, 2 x */
    HudRow rows[1]; /* 0x08 */
} ListArg;
typedef struct ListHolder {
    ListArg* arg;
} ListHolder;
/* The task fn_80023D14 creates (a Task with its work typed and the sprite table after it). */
typedef struct ListTask {
    u8 pad0[0x18];
    u8 flags;           /* 0x18 */
    u8 state;           /* 0x19 */
    u8 pad1A[6];
    f32 f20;            /* 0x20 */
    ListHolder* work;   /* 0x24 */
    Sprite** tab;       /* 0x28 */
} ListTask;
/* The argument block fn_80022F1C hands the task (work points at a pointer to it). */
typedef struct StRow {
    s16 x0;     /* 0x00 */
    s16 x2;     /* 0x02 */
    s16 x4;     /* 0x04 */
    s16 x6;     /* 0x06 */
    s16 x8;     /* 0x08 */
    s16 flags;  /* 0x0A: one bit per status icon */
    s8 kind;    /* 0x0C: picks the name colour */
    u8 padD;
} StRow;
typedef struct StArg {
    s8 x0;
    u8 pad1;
    StRow rows[4];
} StArg;
typedef struct StHolder {
    StArg* arg;
} StHolder;
/* The task fn_80022F1C creates. */
typedef struct StTask {
    Task task;
    Sprite** tab; /* 0x28: 28 sprites per party member */
} StTask;
struct Tsk;
void fn_8002E5D0(struct Tsk *t);
extern void *lbl_803475A8;
extern void *lbl_80346BA0;
typedef struct Holder { u8 pad[0x24]; void *ptr; } Holder;
void *fn_802268E8(void *a, void *b);
void *fn_801E1C7C(s32 n);
typedef struct Sel {
    s8 x0;
    s8 x1;
    s8 x2;
} Sel;
typedef struct W {
    Sel* x0;
} W;
typedef struct Tk {
    u8 pad0[0x18];
    u8 flags;
    u8 state;
    u8 pad1a[6];
    f32 x20;
    W* work;
    Sprite** x28;
} Tk;
extern f32 lbl_80346AC4;
extern s8 lbl_80346AC8;
void fn_80022B04(Tk* t);
extern void *lbl_80346AA0;
typedef struct Ob {
    u8 pad0[0x18];
    u8 flags;     /* 0x18 */
    u8 mode;      /* 0x19 */
    u8 pad1a[6];
    f32 f20;      /* 0x20 */
    Sprite** tab; /* 0x24 */
} Ob;
extern Ob* lbl_8034731C;
void fn_80027C04(Ob* o);
void fn_8000A3A4(void *p);
typedef struct Ent {
    u32 w0;
    s32 w4;
    s32 w8;
    u8 pad_c[0x4];
    s16 s10;         /* 0x10 slot */
    s16 x12;
    s32 x14;
    u8 pad_18[0x8];
    f32 f20;
    u8 pad_24[0x4];
    s32 x28;
    u8 pad_2c[0x10];
    u16 h3c;
    u16 h3e;
    u16 h40;
    u8 pad_42[0x2];
    s16 h44;
    s16 h46;
    s16 h48;
    u8 pad_4a[0x2];
    NJS_POINT3 pos;  /* 0x4C */
    f32 f58;         /* 0x58 screen x */
    f32 f5c;         /* 0x5C screen y */
    f32 f60;         /* 0x60 */
    f32 f64;         /* 0x64 overlap shift */
    f32 f68;         /* 0x68 height */
    s16 x6c;
    s16 h6e;
    s16 s70;
    u8 pad_72[0x88 - 0x72];
    f32 f88;         /* 0x88 */
    f32 f8c;         /* 0x8C */
    u8 pad_90[0x1ee - 0x90];
    s16 x1ee;
    u8 pad_1f0[0x4];
    Ob* x1f4;
    s16 s1f8;        /* 0x1F8 */
} Ent;
extern Ent *lbl_80302AB0[];
extern Ob* lbl_80346BAC;
extern void fn_8000A38C(void);
extern Sprite* fn_80023FEC(s16);
extern void fn_801D52F4(Sprite*, f32, f32, f32, f32, int, int);
typedef struct HudEnt {
    u8 pad_0[0x14];
    s32 x14;
    s32 s18;
    u8 pad_1c[0xb6 - 0x1c];
    s16 xb6;
    u8 padb8[0x100 - 0xb8];
    s8 kind;
    u8 pad_101[0x3];
} HudEnt;
typedef struct HudSlot {
    u8 pad0[0x24];
    struct HudWork* work;
} HudNode;
typedef struct HudWork {
    u32 flags;
    s32 s4;
    s32 s8;
    f32 fc;
    s16 id10;
    s16 s12;
    u8 pad14[4];
    s32 s18;
    s32 s1c;
    f32 f20;
    u8 pad24[4];
    s32 s28;
    s32 s2c;
    u8 pad30[0x4a - 0x30];
    s16 s4a;
    u8 pad4c[0x68 - 0x4c];
    f32 f68;
    u8 pad6c[2];
    s16 s6e;
    s16 s70;
    u8 s72[2];
    s32 s74;
    u8 pad78[0xb4 - 0x78];
    s16 ids[0x140 / 2];
    HudNode* node;
    s16 s1f8;
} HudWork;
extern HudEnt* lbl_80309DE4[12];
extern s16 lbl_80309DCC[12];
extern void* lbl_80347394;
extern void BattleHudDraw(void);
extern void fn_80061F58(void*, s32, s32);
extern void* memset(void*, int, u32);
extern f32 fn_800177C0(u8, void*);
extern s32 fn_80015B94(s32, void*);
extern s32 fn_80020FF0(s32 idx);
/* lbl_80302A38: the scrolling state fn_80028E28 runs. */
typedef struct Scroll {
    s32 state;
    f32 f4;
    f32 f8;
    f32 fc;
    f32 f10;
    u8 pad14[4];
} Scroll;
extern Scroll lbl_80302A38;
f32 fn_80028E28(Scroll *p);
typedef struct Ent80025518 {
    u8 pad0[0x4];
    s32 *out_ptr;
} Ent80025518;
extern s32 lbl_8034732C;
struct Tsk;
typedef struct Res2c { u8 pad[0x2c]; void* p2c; } Res2c;
/* A character's record (its task work's 0x4C). */
typedef struct Dat {
    s8 kind;
    u8 pad_01[3];
    u8 x4;
    u8 pad_05;
    s16 x6;
    s16 x8;
    s16 xa;
    s16 xc;
    s16 xe;
    s16 x10;
    s16 x12;
    s16 x14;
    s16 x16;
    s16 x18;
    s16 x1a;
    s16 x1c;
    u8 pad_1e[2];
    s16 x20;
    u8 pad_22[2];
    s16 x24;
    s16 x26;
    u8 pad_28[0x50 - 0x28];
    u32 x50;
    u8 pad54[0x5a - 0x54];
    u8 x5a;
    u8 pad5b[0xe0 - 0x5b];
    void (*xe0)(struct Tsk*);
    s16 xe4;
    s16 xe6_pad;
    s16 xe8;
    u8 pad_ea[2];
    u32 xec;
    u32 xf0;
    u8 pad_f4[0x134 - 0xf4];
    s32 x134;
    u8 pad138[0x154 - 0x138];
    u8 x154[4];
    u8 x158[4];
    f32 x15c;
    u8 pad160[0x1dc - 0x160];
    u32 x1dc;
    u8 pad1e0[0x20c - 0x1e0];
    s16 x20c;
    s16 x20e;
    s16 x210;
    s16 x212;
} Dat;
typedef struct Wk {
    u8 pad_00[0x10];
    Res2c* x10;
    u8 pad14[0x1c - 0x14];
    f32 px;             /* 0x1C */
    u8 pad20[4];
    f32 pz;             /* 0x24 */
    u8 pad28[0x4c - 0x28];
    Dat *x4c;
} Wk;
typedef struct Tsk {
    u8 pad_00[0x18];
    u8 flags;           /* 0x18 */
    u8 state;           /* 0x19 */
    u8 pad1a[0x24 - 0x1a];
    Wk *work;
} Tsk;
extern s32 fn_80020470(Tsk *t, s16 st);
extern s16 fn_80020094(Wk *w, s16 a, s16 b, s16 c);
typedef struct Rec_80021AE0 { u8 pad[0x30]; struct Std_80021AE0* std; } Rec_80021AE0;
typedef struct Ent_80021AE0 { s16 id; s16 type; u8 pad[0x14]; } Ent_80021AE0;
typedef struct Std_80021AE0 {
    u8 pad0[8];
    s32 count;
    Ent_80021AE0* ents;
    s16 s10;
    s16 s12;
    s32 w14;
    s32 w18;
    s32 w1c;
} Std_80021AE0;
typedef struct Ref_80021AE0 { Rec_80021AE0* rec; void* out; } Ref_80021AE0;
typedef struct Out { u8 pad[0x50]; } Out;
extern Rec_80021AE0* fn_80074E2C(char* a, char* b, Out* out, s32 id, s32 kind);
extern s32 fn_8006EAB4(Rec_80021AE0* r);
extern char* strcpy(char* dst, const char* src);
extern char* strcat(char* dst, const char* src);
extern int sprintf(char*, const char*, ...);
extern void fn_80061048(char* s);
extern void* fn_801CC69C(char* name);
extern void fn_801CC608(void* h, void* buf, s32 size);
extern void fn_801CC65C(void* h);
extern void fn_80009860(Ref_80021AE0* r, Std_80021AE0* s);
extern void fn_800091A4(Std_80021AE0* s);
extern void fn_80009750(char* name, char* path, Std_80021AE0** slot);
typedef struct Info { s16 id; u8 pad2[2]; f32 t; } Info;
typedef struct Res { s32 w0; u32 w4; } Res;
typedef struct Res10 { u8 pad[8]; void* p8; } Res10;
typedef struct Work21CBC {
    void* w0;
    u8 pad4[4];
    void* w8;
    u8 padC[4];
    Res10* w10;
    u8 pad14[2];
    s16 s16_;
    u8 pad18[4];
    f32 px, py, pz;
    s32 rx, ry, rz;
    f32 sx, sy, sz;
    u8 pad40[4];
    u8 b44;
    u8 pad45[7];
    Info* info;
} Work21CBC;
extern void njPushMatrixEx(void);
extern void njPopMatrixEx(void);
extern void fn_80286EE8(void);
extern void fn_8028B498(void);
extern void njTranslate(NJS_MATRIX m, f32 x, f32 y, f32 z);
extern void njScale(NJS_MATRIX m, f32 x, f32 y, f32 z);
extern s32 fn_8006CEEC(void* a, Res** out, s32 b, s32 c);
extern void fn_80035380(void* a, Res* r, f32 t, s32 b);
extern void fn_80035140(void* a, s32 b);
extern void fn_8007E264(f32* p, f32 a, f32 b);
extern void fn_801E17E0(void* p);
extern Tsk *lbl_80309E24[14];
extern void* lbl_80347628;
extern s32 lbl_80346B4C;
extern s32 lbl_80346B98;
typedef struct KindRec {
    u8 kind;          /* 0x00 */
    u8 pad1[0x23];
    s16 mode;         /* 0x24 */
} KindRec;
extern int fn_80014C90(u8 id, int flags);
extern s32 lbl_80346AD0;
extern s32 lbl_80346ACC;
extern s32 lbl_80347324;
extern void* lbl_8034762C;
extern void fn_8002356C(StArg* arg, Sprite** tab, s8 a, s8 b);
extern s8 lbl_80346AC0;
extern s32 lbl_80346AD8;
extern s32 lbl_80346ADC;
extern s32 lbl_80346AE0;
extern int lbl_80346AE4;
extern s32 lbl_80346AEC;
extern s32 lbl_80346AF0;
extern f32 lbl_80346AF4;
extern s8 lbl_80346AF8;
extern s8 lbl_80346AF9;
extern s16 lbl_80346AFA;
extern s16 lbl_80346AFC;
extern s16 lbl_80346AFE;
extern s16 lbl_80346B00;
extern s16 lbl_80346B02;
extern s16 lbl_80346B04;
extern s16 lbl_80346B06;
extern s16 lbl_80346B08;
extern s16 lbl_80346B0A;
extern s16 lbl_80346B0C;
extern s16 lbl_80346B0E;
extern s16 lbl_80346B10;
extern Sprite* fn_801D497C(Sprite* p);
extern void fn_801D4954(Sprite* p);
extern void fn_8002468C(ListTask* t);
extern s8 fn_800176DC(s8 kind);
typedef struct Rec28B90 {
    u8 pad0[4];
    s16 s4;
    s16 s6;
    u8 pad8[2];
    s8 kind;
    char name[1]; /* 0x0B */
} Rec28B90;
typedef struct Item36 { u8 pad0[0x12]; s8 f12; u8 pad13[0x24 - 0x13]; } Item36;
typedef struct Item48 { u8 pad0[0x15]; s8 f15; u8 pad16[0x30 - 0x16]; } Item48;
extern s32 lbl_8034733C;
extern s32 lbl_80346B78;
extern Item36 lbl_802C7C34[];
extern Item48 lbl_802C4BF0[];
extern Rec28B90 *fn_800786C0(void);
/* Takes the task, a command and its argument (fn_80020250 extends the command as s16). */
extern s32 fn_80020250(Tsk *t, s16 cmd, s32 arg);
extern void njRotate(NJS_MATRIX m, NJS_VECTOR* axis, Angle a);
extern void fn_801D5340(Sprite* m, s32 c, s32 d, f32 z, f32 ang, f32 a, f32 b);
extern void fn_800277F4(Sprite** m, s32 n, f32* ang);

void fn_80020B50(Tsk *t, s16 *out1, s16 *out2) {
  Dat *d = t->work->x4c;
  if (d->xec & 0x8000) {
    *out1 = d->x14;
    *out2 = d->x16;
  } else {
    *out1 = d->x6;
    *out2 = d->x8;
  }
}

static inline Tsk *Find21(s8 id)
{
    s8 i;
    for (i = 0; i < 14; i++) {
        Tsk *t = lbl_80309E24[i];
        if (t != NULL && t->work->x4c->kind == id) {
            return lbl_80309E24[i];
        }
    }
    return NULL;
}

static inline Tsk *F2(s8 id)
{
    Tsk *r = Find21(id);
    if (r != NULL) return r;
    return Find21(0);
}

static inline void Take(Tsk* t) {
    Dat* d = t->work->x4c;
    if (d->xec & 0x8000) {
        d->xec &= ~0x8000;
        d->x6 = d->x14;
        d->x8 = d->x16;
    }
}

void fn_80020B8C(Tsk* t, s16 a, s16 b, s32 flag) {
    Dat* u = t->work->x4c;
    s16 sx;
    s16 sy;
    s32 key;
    if (flag != 0) {
        key = u->x4;
        if (u->xec & 0x80) key = u->x5a;
        F2(key)->work->x4c->xec |= 0x2000;
    }
    if (u->xec & 0x8000) {
        Take(t);
        fn_8002E5D0(t);
    } else {
        sx = u->x6;
        sy = u->x8;
        u->x6 = a;
        u->x8 = b;
        Take(t);
        fn_8002E5D0(t);
        u->x6 = sx;
        u->x8 = sy;
    }
}


s32 fn_8002111C(s8 id, s32 arg, s16 sel)
{
    Tsk* o = F2(id);
    s32 r;

    o->work->x4c->xec &= ~1;
    switch (sel) {
    case 8:
    case 0x18:
    case 0x1d:
        o = F2(id);
        if (fn_80020250(o, 0x20, arg) == 0) {
            o = F2(id);
            r = fn_80020250(o, 0xb, arg);
        } else {
            r = 1;
        }
        break;
    default:
        o = F2(id);
        r = fn_80020250(o, 0xb, arg);
        break;
    }
    return r;
}

void fn_80021784(Tsk *t) {
  Dat *d = t->work->x4c;
  if (d->xec & 0x8000) {
    d->xec = d->xec & ~0x8000;
    d->x6 = d->x14;
    d->x8 = d->x16;
  }
  fn_8002E5D0(t);
}

void fn_80020D50(Tsk* t);
s32 fn_80021EB8(Tsk *t);

extern void fn_80074968(void* a, void* b);

inline s8 FindSlot(Tsk* task) {
    s8 i;
    for (i = 0; i < 14; i++) {
        if (lbl_80309E24[i] == task) return i;
        if (lbl_80309E24[i] == 0) return i;
    }
    return i;
}

inline void InitSlotPos(Tsk* task) {
    s8 idx = 0;
    Wk* w2 = task->work;
    Dat* d2 = w2->x4c;
    if (d2->x1dc == 0) {
        idx = FindSlot(task);
        if (d2->kind != idx && d2->kind < 12) {
            d2->kind = idx;
        }
    }
    w2->px = (f32)(s8)(idx % 3) * 15.0f * 3.0f;
    w2->pz = (f32)(s8)(idx / 3) * 15.0f * 3.0f;
    w2->px -= 60.0f;
    w2->pz -= 60.0f;
}

void fn_80021FCC(Tsk* task) {
    Wk* w = task->work;
    Dat* d = w->x4c;

    switch (task->state) {
    case 0:
        task->state = 1;
        InitSlotPos(task);
        fn_80074968(w->x10->p2c, d->x154);
        fn_80074968(w->x10->p2c, d->x158);
        d->x6 = 1;
        {
            Dat* d3 = w->x4c;
            s16 k = fn_80020094(w, d3->x6, 0, 0);
            if (k >= 0) {
                d3->x1c = d3->x6;
                d3->x12 = 0;
                d3->xe8 = d3->xe4;
                d3->xe4 = k;
                d3->x134 = 0;
            }
        }
        d->x134 = 0;
        break;
    case 1:
        fn_80021EB8(task);
        d->xe0(task);
        if (d->xec & 0x400000) {
            task->state = 2;
        }
        break;
    case 2:
        fn_80020D50(task);
        fn_801E17E0(d);
        task->flags |= 0x40;
        break;
    }
}

void fn_80020D50(Tsk* t);
s32 fn_80021EB8(Tsk *t);

extern s32 fn_800221FC(Tsk* t);

extern void fn_80074968(void* a, void* b);





void fn_80022850(Tsk* task) {
    Wk* w = task->work;
    Dat* d = w->x4c;
    s32 tmp[4];

    switch (task->state) {
    case 0:
        task->state = 1;
        InitSlotPos(task);
        fn_80074968(w->x10->p2c, d->x154);
        fn_80074968(w->x10->p2c, d->x158);
        d->x15c = fn_800177C0(d->kind, tmp);
        d->x6 = 1;
        {
            Dat* d3 = w->x4c;
            s16 k = fn_80020094(w, d3->x6, 0, 0);
            if (k >= 0) {
                d3->x1c = d3->x6;
                d3->x12 = 0;
                d3->xe8 = d3->xe4;
                d3->xe4 = k;
                d3->x134 = 0;
            }
        }
        d->x134 = 0;
        break;
    case 1:
        fn_800221FC(task);
        d->xe0(task);
        if ((d->xec & 0x400000) && !(d->x50 & 0x80000)) {
            task->state = 2;
        }
        break;
    case 2:
        fn_80020D50(task);
        fn_801E17E0(d);
        task->flags |= 0x40;
        break;
    }
}

void fn_80022A9C(void) {
    ((u8*)lbl_80346BA0)[0x19] = 2;
}

void fn_80022AAC(void *p) {
  lbl_80346BA0 = fn_802268E8(lbl_803475A8, fn_80022B04);
  ((Holder *)lbl_80346BA0)->ptr = fn_801E1C7C(4);
  *(void **)((Holder *)lbl_80346BA0)->ptr = p;
}

typedef struct {
    u8 pad0[0x24];
    void *tab;
} Mgr_800C8F3C;
extern Mgr_800C8F3C *lbl_80346BA4;
void fn_80022F0C(void) {
    ((u8*)lbl_80346BA4)[0x19] = 2;
}

extern Mgr_800C8F3C *lbl_80346BA8;
void fn_80022F74(StTask* t);
void fn_80022F1C(void *p) {
  lbl_80346BA4 = fn_802268E8(lbl_803475A8, fn_80022F74);
  ((Holder *)lbl_80346BA4)->ptr = fn_801E1C7C(4);
  *(void **)((Holder *)lbl_80346BA4)->ptr = p;
}

void fn_80023D04(void) {
    ((u8*)lbl_80346BA8)[0x19] = 2;
}

void fn_800240EC(ListTask* t);
void fn_80023D14(void *p) {
  lbl_80346BA8 = fn_802268E8(lbl_803475A8, fn_800240EC);
  ((Holder *)lbl_80346BA8)->ptr = fn_801E1C7C(4);
  *(void **)((Holder *)lbl_80346BA8)->ptr = p;
}

struct RingTask;
extern void fn_80025624(struct RingTask *o);
void fn_800255CC(void *p) {
  lbl_80346BAC = fn_802268E8(lbl_803475A8, fn_80025624);
  ((Holder *)lbl_80346BAC)->ptr = fn_801E1C7C(4);
  *(void **)((Holder *)lbl_80346BAC)->ptr = p;
}

typedef struct Lim {
    u8 pad[6];
    s16 x6;
    s16 x8;
    s16 xa;
} Lim;

extern Lim* lbl_80347390;
extern f32 lbl_80346B7C;
extern f32 lbl_80346B80;
extern f32 lbl_80346B84;
extern f32 lbl_80346B88;
extern s32 lbl_80346B8C;
extern s32 lbl_80346B90;
extern s32 lbl_80346B94;

extern f32 lbl_80346B58;
extern f32 lbl_80346B5C;
extern s32 lbl_80346B60;
extern s32 lbl_80346B64;
extern s32 lbl_80346B68;
extern s32 lbl_80346B6C;
extern s32 lbl_80346B70;
extern s32 lbl_80346B74;
extern s32 fn_80028B90(void);
extern s32 fn_8007833C(void);

/* The gauge's digit colour: green when full, through yellow, to red when empty. */
inline u32 GaugeColour(f32 ratio) {
    u8 cb;
    u8 cg;
    u8 cr;
    u8 ca;
    if (ratio > 0.5f) {
        f32 t = 1.0f - ratio;
        ca = 0xfa;
        cb = 0x20;
        cr = (s32)(376.0f * t) + 0x20;
        cg = 0xfa - (s32)(100.0f * t);
    } else {
        ca = 0xfa;
        cb = 0x20;
        cr = (s32)(30.0f * (1.0f - 2.0f * ratio)) + 0xdc;
        cg = 0xc8 - (s32)(168.0f * (1.0f - 2.0f * ratio));
    }
    return (ca << 24) + (cr << 16) + (cg << 8) + cb;
}

/* The SP gauge. */
void fn_80027C04(Ob* o) {
    NJS_POINT3 in;
    NJS_POINT3 out;
    NJS_VECTOR axis;
    NJS_MATRIX m;
    s32 i;
    f32 lost;
    f32 kept;
    SpritePiece* pc;
    f32 cur;
    s32 n;
    s32 c;
    Sprite* s;
    f32 ang;
    f32 z;
    f32 x;
    f32 z2;
    Rec28B90* rec;
    f32 ratio;
    s32 max;
    s32 sp;
    s32 part;
    s32 w;
    s32 mode;
    s32 tens;
    s32 ones;
    SpritePiece* bp;
    f32 a;
    u32 colour;

    max = lbl_80347390->x6;
    sp = lbl_80347390->xa;
    switch (o->mode) {
    case 0:
    case 0xfe:
        o->tab = fn_801E1C7C(0x4c); /* 19 entries, though 21 are written below */
        o->tab[0] = fn_801D497C(fn_801D68C4(lbl_80347628, 8));
        o->tab[1] = fn_801D497C(fn_801D68C4(lbl_80347628, 0));
        o->tab[2] = fn_801D497C(fn_801D68C4(lbl_80347628, 1));
        o->tab[3] = fn_801D497C(fn_801D68C4(lbl_80347628, 2));
        o->tab[4] = fn_801D497C(fn_801D68C4(lbl_80347628, 3));
        o->tab[5] = fn_801D497C(fn_801D68C4(lbl_80347628, 5));
        o->tab[6] = fn_801D497C(fn_801D68C4(lbl_80347628, 6));
        o->tab[7] = fn_801D497C(fn_801D68C4(lbl_80347628, 7));
        o->tab[8] = fn_801D497C(fn_801D68C4(lbl_80347628, 7));
        o->tab[9] = fn_801D497C(fn_801D68C4(lbl_80347628, 8));
        o->tab[10] = fn_801D497C(fn_801D68C4(lbl_80347628, 4));
        o->tab[11] = fn_801D497C(fn_801D68C4(lbl_80347628, 0x23));
        o->tab[12] = fn_801D497C(fn_801D68C4(lbl_80347628, 0x24));
        o->tab[13] = fn_801D497C(fn_801D68C4(lbl_80347628, 0x25));
        o->tab[14] = fn_801D497C(fn_801D68C4(lbl_80347628, 0x26));
        o->tab[15] = fn_801D497C(fn_801D68C4(lbl_80347628, 0x27));
        o->tab[16] = fn_801D497C(fn_801D68C4(lbl_80347628, 0x28));
        o->tab[17] = fn_801D497C(fn_801D68C4(lbl_80347628, 0x29));
        o->tab[18] = fn_801D497C(fn_801D68C4(lbl_80347628, 0x2a));
        o->tab[19] = fn_801D497C(fn_801D68C4(lbl_80347628, 0x2b));
        o->tab[20] = fn_801D497C(fn_801D68C4(lbl_80347628, 0x2c));
        i = 0;
        c = 0;
        for (; c != -1 && i < 4; i++) {
            c = lbl_8030B7F4.party[i];
        }
        n = i;
        if (c == -1) {
            n = i - 1;
        }
        lbl_80346B68 = n;
        lbl_80346B64 = -1;
        lbl_80346B60 = 1;
        lbl_80302A38.state = 0;
        lbl_80302A38.f4 = lbl_80347390->x6;
        lbl_80302A38.f8 = lbl_80347390->x8;
        lbl_80302A38.fc = lbl_80347390->xa;
        o->f20 = -1.3f;
    case 1:
        lbl_80346B58 = 1.0f;
        lbl_80346B5C = -121.4f;
        lbl_80346B6C = 0;
        o->tab[0]->x = 84.0f;
        o->tab[0]->y = 37.0f;
        lbl_80346B74 = lbl_80347324;
        lbl_80346B70 = -1;
        o->mode = 2;
        break;
    case 2:
        cur = lbl_80347390->x8;
        mode = lbl_80347324;
        switch (fn_80028B90()) {
        case 0:
            cur = fn_80028E28(&lbl_80302A38);
            lbl_80346B60 = 1;
            break;
        case 1:
            lbl_80346B60 = 0;
            break;
        case 2:
            cur = fn_80028E28(&lbl_80302A38);
            lbl_80346B60 = 1;
            break;
        case 3:
            rec = fn_800786C0();
            z = TextGetZ();
            TextSetZ(-1.199f);
            TextPrint(0xe0, 0x27, rec->name);
            TextSetZ(z);
            fn_801D5340(fn_801D68C4(lbl_80347628, 0x67), 0, 0, -1.2f, 0.0f, 1.0f, 1.0f);
            lbl_80346B60 = 0;
            break;
        case 4:
            cur = fn_80028E28(&lbl_80302A38);
            lbl_80346B60 = 1;
            break;
        default:
            lbl_80346B60 = 1;
            break;
        }
        part = fn_8007833C();
        if (lbl_80346B70 != part) {
            fn_801D4954(o->tab[9]);
            o->tab[9] = 0;
            switch (part) {
            case 3:
                o->tab[9] = fn_801D497C(fn_801D68C4(lbl_80347628, 0xb));
                break;
            case 1:
                o->tab[9] = fn_801D497C(fn_801D68C4(lbl_80347628, 0xf));
                break;
            case 4:
                o->tab[9] = fn_801D497C(fn_801D68C4(lbl_80347628, 0xc));
                break;
            case 5:
                o->tab[9] = fn_801D497C(fn_801D68C4(lbl_80347628, 0xe));
                break;
            case 0:
                o->tab[9] = fn_801D497C(fn_801D68C4(lbl_80347628, 0xd));
                break;
            case 6:
                if (lbl_80346B98 == 1 && lbl_8034732C == 0) {
                    o->tab[9] = fn_801D497C(fn_801D68C4(lbl_80347628, 0x12));
                } else {
                    o->tab[9] = fn_801D497C(fn_801D68C4(lbl_80347628, 0x10));
                }
                break;
            case 2:
                o->tab[9] = fn_801D497C(fn_801D68C4(lbl_80347628, 0x11));
                break;
            case 12:
            default:
                o->tab[9] = fn_801D497C(fn_801D68C4(lbl_80347628, 0xb));
                break;
            }
        }
        lbl_80346B70 = part;
        if (lbl_80346B74 != mode) {
            if (mode == 1) {
                lbl_80346B6C = -1;
                lbl_80346B5C = -121.4f;
                o->tab[0]->x = 84.0f;
                o->tab[0]->y = 37.0f;
            } else {
                lbl_80346B6C = 1;
            }
        }
        s = o->tab[0];
        axis.x = 0.0f;
        axis.y = 0.0f;
        axis.z = 1.0f;
        in.x = (19.0f + s->x) - 51.0f;
        in.y = (19.0f + s->y) - 57.0f;
        in.z = 0.0f;
        njUnitMatrix(m);
        njRotate(m, &axis, lbl_80346B6C * -0xa4f);
        njCalcPoint(m, &in, &out);
        s->x = 51.0f + (out.x - 19.0f);
        s->y = 57.0f + (out.y - 19.0f);
        a = -40.466667f * lbl_80346B6C + lbl_80346B5C;
        lbl_80346B5C = a;
        ang = (s32)(182.04445f * a);
        if (-20.233334f + a <= -121.4f || 0.0f <= a - -20.233334f) {
            lbl_80346B6C = 0;
            if ((s32)a == 0) {
                lbl_80346B5C = 0.0f;
            }
            if ((s32)lbl_80346B5C == -0x79) {
                lbl_80346B70 = -1;
                lbl_80346B5C = -121.4f;
            }
        }
        lbl_80346B74 = mode;
        w = 500.0f * cur / max;
        pc = o->tab[4]->pieces;
        pc->x1 = pc->x0 + w;
        o->tab[9]->x = o->tab[0]->x;
        o->tab[9]->y = o->tab[0]->y;
        if (lbl_80346B60 == 1) {
            fn_801D5340(o->tab[9], 0, 0, -1.199f, ang, 1.0f, 1.0f);
            lost = 500.0f * (s32)(sp - cur);
            kept = 500.0f * (cur - (s32)(cur - sp));
            for (i = 0; i < 10; i++) {
                if (i == 9 || i == 0) {
                    continue;
                }
                if (i == 4) {
                    if (lbl_80346B68 > lbl_8034732C) {
                        s = o->tab[10];
                        bp = s->pieces;
                        x = w + fn_801D68C4(lbl_80347628, 3)->x;
                        w = lost / max;
                        s->x = x;
                        bp->x1 = bp->x0 + w;
                        if (w < 0) {
                            bp->colour = 0xb4ff6400;
                            if (lbl_80346B60 == 1) {
                                fn_801D5340(o->tab[10], 0, 1, -1.189f, 0.0f, 1.0f, 1.0f);
                            }
                            pc = o->tab[4]->pieces;
                            w = kept / max;
                            pc->x1 = pc->x0 + w;
                        }
                    }
                    fn_801D5340(o->tab[i], 0, 1, 0.001f * (i + 1) + -1.2f, 0.0f, 1.0f, 1.0f);
                } else {
                    fn_801D5340(o->tab[i], 0, 0, 0.001f * (i + 1) + -1.2f, 0.0f, 1.0f, 1.0f);
                }
            }
        }
        if (lbl_80346B68 > lbl_8034732C && sp != (s32)cur) {
            tens = sp / 10;
            ones = sp % 10;
            if (lbl_80346B58 > 1.0 || 0.0 > lbl_80346B58) {
                lbl_80346B64 *= -1;
            }
            ratio = (f32)sp / (f32)max;
            colour = GaugeColour(ratio);
            lbl_80346B58 = lbl_80346B58 + lbl_80346B64 / 15.0f;
        } else {
            lbl_80346B58 = 1.0f;
            lbl_80346B64 = -1;
            tens = (s32)cur / 10;
            ones = (s32)cur % 10;
            ratio = cur / max;
            colour = GaugeColour(ratio);
        }
        if (tens != 0) {
            s = fn_801D68C4(lbl_80347628, 0x23);
            o->tab[tens + 11]->x = s->x;
            o->tab[tens + 11]->pieces->colour = colour;
            if (lbl_80346B60 == 1) {
                fn_801D5340(o->tab[tens + 11], 0, 0, -1.189f, 0.0f, 1.0f, lbl_80346B58);
            }
        }
        o->tab[ones + 11]->x = 16.0f + fn_801D68C4(lbl_80347628, 0x23)->x;
        o->tab[ones + 11]->pieces->colour = colour;
        if (lbl_80346B60 == 1) {
            fn_801D5340(o->tab[ones + 11], 0, 0, -1.189f, 0.0f, 1.0f, lbl_80346B58);
            z2 = TextGetZ();
            TextSetZ(-1.188f);
            TextPrint(0x45, 0x28, "/");
            TextPrintNumber(0x51, 0x28, max, 0xc002);
            TextSetZ(z2);
        }
        break;
    case 3:
        for (w = 0; w < 0x13; w++) {
            fn_801D4954(o->tab[w]);
            o->tab[w] = 0;
        }
        o->mode = 0xff;
    case 0xff:
        o->flags |= 0x40;
        lbl_8034731C = 0;
        break;
    }
}

f32 fn_80028E28(Scroll* p) {
    p->f4 = lbl_80347390->x6;
    p->f8 = lbl_80347390->x8;
    p->fc = lbl_80347390->xa;
    switch (p->state) {
    case 0:
        lbl_80346B94 = 0;
        lbl_80346B90 = 0;
        lbl_80346B8C = 0;
        lbl_80346B7C = p->f8;
        lbl_80346B84 = p->f8;
        p->state = 1;
        break;
    case 1: {
        s32 whole = lbl_80346B84;
        if (p->f8 != whole) {
            f32 d = lbl_80346B84 - p->f8;
            lbl_80346B94 = 1;
            lbl_80346B88 = d;
            lbl_80346B80 = d / 39.0f;
        }
        if (lbl_80346B94 == 1) {
            lbl_80346B90++;
        }
        if (lbl_80346B90 > 1) {
            lbl_80346B8C = 1;
        }
        if (lbl_80346B8C == 1) {
            lbl_80346B7C = lbl_80346B7C - lbl_80346B80;
            if (lbl_80346B80 > 0.0f) {
                if (lbl_80346B7C <= p->f8) {
                    lbl_80346B80 = 0.0f;
                    lbl_80346B84 = p->f8;
                    lbl_80346B7C = p->f8;
                    lbl_80346B8C = 0;
                    lbl_80346B90 = 0;
                }
            } else if (lbl_80346B7C >= p->f8) {
                lbl_80346B80 = 0.0f;
                lbl_80346B84 = p->f8;
                lbl_80346B7C = p->f8;
                lbl_80346B8C = 0;
                lbl_80346B90 = 0;
            }
        } else {
            lbl_80346B94 = 0;
        }
        break;
    }
    case 2:
        lbl_80346B80 = 0.0f;
        lbl_80346B84 = p->f8;
        lbl_80346B7C = p->f8;
        lbl_80346B8C = 0;
        lbl_80346B90 = 0;
        p->state = 1;
        break;
    }
    p->f10 = lbl_80346B7C;
    return lbl_80346B7C;
}

void fn_80029070(void) {
  lbl_8034731C = fn_802268E8(lbl_803475A8, fn_80027C04);
  fn_8000A3A4(lbl_80346AA0);
}

u32 fn_800290A8(s16 idx, u16 mask) {
  Ent *e = lbl_80302AB0[idx];
  u32 v;
  if (e == 0) return 0;
  v = mask & e->h3c;
  return v != 0;
}

void fn_800295E0(s16 idx) {
  Ent *e = lbl_80302AB0[idx];
  if (e == 0) return;
  if (e->w0 & 0x40000000) return;
  e->w4 = 0;
  lbl_80302AB0[idx]->h3e = 0;
  lbl_80302AB0[idx]->h44 = 0;
  lbl_80302AB0[idx]->h6e = 0;
}

void fn_8002962C(s16 idx) {
  Ent *e = lbl_80302AB0[idx];
  if (e == 0) return;
  if (e->w0 & 0x40000000) return;
  e->w4 = 1;
  lbl_80302AB0[idx]->h6e = 0xff;
  lbl_80302AB0[idx]->h44 = 0;
}

void fn_800255BC(void) {
    lbl_80346BAC->mode = 5;
}

void fn_8002903C(void) {
    if (lbl_8034731C != 0) {
        lbl_8034731C->mode = 3;
        fn_8000A38C();
    }
}

s32 fn_80029678(s16 i) {
    return lbl_80302AB0[i] != 0;
}

inline void Draw(s16 d, f32 off, f32 x, f32 y)
{
    Sprite* o = fn_80023FEC(d);
    o->x = off + x;
    o->y = y;
    fn_801D52F4(o, -1.1999f, 0.0f, 1.0f, 1.0f, 0, 0);
}

inline void Draw0(s16 d, f32 x, f32 y)
{
    Sprite* o = fn_80023FEC(d);
    o->x = x;
    o->y = y;
    fn_801D52F4(o, -1.1999f, 0.0f, 1.0f, 1.0f, 0, 0);
}

void fn_80023D6C(s16 n, f32 x, f32 y)
{
    int lead = 1;
    s16 d3 = n / 1000 % 10;
    s16 d2 = n / 100 % 10;
    s16 d1 = n / 10 % 10;
    s16 d0 = n % 10;

    if (d3 > 0) {
        lead = 0;
        Draw(d3, -36.0f, x, y);
    }
    if (d2 > 0) {
        lead = 0;
        Draw(d2, -24.0f, x, y);
    } else if (lead != 1) {
        Draw(d2, -24.0f, x, y);
    }
    if (d1 > 0) {
        lead = 0;
        Draw(d1, -12.0f, x, y);
    } else if (lead != 1) {
        Draw(d1, -12.0f, x, y);
    }
    Draw0(d0, x, y);
}

void fn_8002969C(s16 id) {
    HudNode* node;
    HudWork* w;
    s32 i;
    f32 tmp[4];
    if (((HudWork**)lbl_80302AB0)[id] == 0) {
        node = ((HudNode*)fn_802268E8((void *)((*(void**)&lbl_803475A8)), (void *)(BattleHudDraw)));
        fn_80061F58(&node->work, 0x204, 0);
        ((HudWork**)lbl_80302AB0)[id] = node->work;
    } else {
        node = ((HudWork**)lbl_80302AB0)[id]->node;
        memset(node->work, 0, 0x204);
        ((u8*)node)[0x19] = 0;
    }
    w = node->work;
    w->node = node;
    w->s4a = 0;
    w->s8 = 1;
    w->id10 = id;
    w->s4 = 0;
    w->s12 = 1;
    w->fc = -1.1f;
    w->s6e = 0xff;
    w->flags &= ~0x40000000;
    if (lbl_80347394 == 0) {
        w->s2c = lbl_80309DE4[id]->s18;
        w->s28 = lbl_80309DE4[id]->x14;
        w->f20 = (f32)lbl_80309DE4[id]->x14;
        w->f68 = fn_800177C0((u8)id, tmp);
    } else {
        w->s2c = 0xff;
        w->s28 = 0xff;
        w->f20 = 255.0f;
        w->f68 = 10.0f;
    }
    w->s18 = 0;
    w->s1c = 0;
    w->s74 = fn_80015B94((s8)id, w->s72);
    if (id < 4) {
        w->s1f8 = 1;
    } else if (lbl_80309DCC[id] < 0x80) {
        w->s1f8 = 2;
    } else {
        w->s1f8 = 3;
    }
    w->ids[0] = id;
    w->ids[18] = id;
    w->ids[36] = id;
    w->ids[54] = id;
    w->ids[72] = id;
    w->ids[90] = id;
    w->ids[108] = id;
    w->ids[126] = id;
    w->ids[144] = id;
    w->s70 = i = 0;
    for (; i < 12; i++) {
        if (i != id && ((HudWork**)lbl_80302AB0)[i] != 0) {
            w->s70++;
        }
    }
}

s32 fn_80020F68(void)
{
    switch (fn_80020FF0(0)) {
    default:
        return 0;
    case 17:
        return 1;
    case 11:
        return 2;
    case 19:
        return 3;
    case 35:
        return 4;
    case 9:
        return 5;
    case 1:
        return 6;
    case 33:
        return 7;
    case 2:
        return 8;
    }
}

void fn_80028DE4(void)
{
    fn_80028E28(&lbl_80302A38);
}

void fn_80028E0C(void)
{
    if (lbl_80302A38.state == 1) {
        lbl_80302A38.state = 2;
    }
}

extern char* lbl_80346AE8;
extern f32 lbl_80346AD4;
extern s16 lbl_80346B0C;
extern s16 lbl_80346B0A;
extern s16 lbl_80346B08;
extern s16 lbl_80346B06;

void fn_80025518(Sprite* self);

void fn_800250F4(ListTask* t)
{
    Sprite* o;
    int i;
    s8 b;

    for (i = 0; i < t->work->arg->count; i++) {
        lbl_80346AE8 = t->work->arg->rows[i].text;
        switch (t->work->arg->rows[i].kind) {
        case 1:
            TextPrint(lbl_80346B0C, lbl_80346B0A + i * 24, lbl_80346AE8);
            b = t->work->arg->rows[i].b;
            if (b == -1) {
                TextPrint(lbl_80346B08, lbl_80346B06 + i * 24, "E");
            } else if (b != -2) {
                TextPrintf(lbl_80346B08, lbl_80346B06 + i * 24, "%2d", b);
            }
            lbl_80346AD4 = 1.0f;
            break;
        case 0:
            TextPushColor();
            TextSetColor(0xff606060);
            TextPrint(lbl_80346B0C, lbl_80346B0A + i * 24, lbl_80346AE8);
            b = t->work->arg->rows[i].b;
            if (b == -1) {
                TextPrint(lbl_80346B08, lbl_80346B06 + i * 24, "\x82\x64");
            } else if (b != -2) {
                TextPrintf(lbl_80346B08, lbl_80346B06 + i * 24, "%2d", b);
            }
            TextPopColor(1);
            lbl_80346AD4 = 0.5f;
            break;
        }
        switch (t->work->arg->kind) {
        case 4:
            o = fn_801D68C4(lbl_80347628, 0x4e);
            break;
        case 6:
            o = fn_801D68C4(lbl_80347628, 0x50);
            break;
        case 7:
            o = fn_801D68C4(lbl_80347628, 0x51);
            break;
        case 3:
            o = fn_801D68C4(lbl_80347628, 0x4d);
            break;
        case 5:
            o = fn_801D68C4(lbl_80347628, 0x4f);
            break;
        case 8:
            o = fn_801D68C4(lbl_80347628, 0x52);
            break;
        case 0:
        case 10:
            switch (lbl_8030B7F4.party[lbl_8034732C]) {
            case 0:
                o = fn_801D68C4(lbl_80347628, 0x53);
                break;
            case 1:
                o = fn_801D68C4(lbl_80347628, 0x54);
                break;
            case 2:
                o = fn_801D68C4(lbl_80347628, 0x55);
                break;
            case 3:
                o = fn_801D68C4(lbl_80347628, 0x56);
                break;
            case 4:
                o = fn_801D68C4(lbl_80347628, 0x57);
                break;
            case 5:
                o = fn_801D68C4(lbl_80347628, 0x58);
                break;
            case -1:
            case 6:
                o = fn_801D68C4(lbl_80347628, 0x53);
                break;
            }
            if (t->work->arg->rows[i].x4 == lbl_80309DE4[lbl_8034732C]->xb6 && t->work->arg->kind == 10) {
                fn_80025518(o);
            } else {
                o->pieces->colour = -1;
            }
            break;
        case 11:
            o = fn_801D68C4(lbl_80347628, 0x5a);
            break;
        case 12:
            o = fn_801D68C4(lbl_80347628, 0x5b);
            break;
        case 9:
            o = fn_801D68C4(lbl_80347628, 0x59);
            break;
        case 1:
        case 2:
        case 13:
        case 14:
        default:
            o = fn_801D68C4(lbl_80347628, 0x59);
            break;
        }
        o->x = 284.0f;
        o->y = 301 + i * 24;
        fn_801D5340(o, 0, 0, -1.188f, 0.0f, lbl_80346AD4, 1.0f);
    }
}

void fn_80025518(Sprite *self)
{
    HudEnt *s = lbl_80309DE4[lbl_8034732C];
    s32 v;
    switch (s->kind) {
    case 0:
        v = 0xFF20FF0A;
        break;
    case 1:
        v = 0xFFFF4020;
        break;
    case 2:
        v = 0xFFC800FF;
        break;
    case 3:
        v = 0xFF0096FF;
        break;
    case 4:
        v = -0x3800;
        break;
    case 5:
        v = 0xFFDCDCDC;
        break;
    default:
        v = -1;
        break;
    }
    self->pieces->colour = v;
}

void fn_800294E8(void) {
    s32 i;
    for (i = 0; i < 12; i++) {
        if (lbl_80302AB0[i] != NULL && !(lbl_80302AB0[i]->w0 & 0x40000000)) {
            lbl_80302AB0[i]->w4 = 0;
            lbl_80302AB0[i]->h3e = 0;
            lbl_80302AB0[i]->h44 = 0;
            lbl_80302AB0[i]->h6e = 0;
        }
    }
}

s32 fn_80021EB8(Tsk *t) {
    Wk *w = t->work;
    Dat *d = w->x4c;
    s16 st = 2;
    s16 b = -1;
    s16 k;
    if (d->xec & 0x40000000) {
        st = d->x18;
        switch (st) {
        case 0x18:
        case 0x19:
        case 0x1d:
        case 0x1e:
            b = d->x1a;
            break;
        default:
            b = -1;
            break;
        }
    }
    if (fn_80020470(t, st) == 0) {
        return 0;
    }
    k = fn_80020094(w, st, b, 0);
    if (k >= 0 && d->x6 != st) {
        d->x4 = 0;
        d->x1c = d->x6;
        d->x6 = st;
        d->x8 = b;
        d->x12 = 0;
        d->xe8 = d->xe4;
        d->xe4 = k;
        d->x134 = 0;
        d->xec &= ~0x20000;
        return 1;
    }
    return 0;
}

extern void* lbl_8034762C;

/* Draws one party member's status panel: the portrait and name sprites, the HP and MP numbers, the
 * HP bar coloured by what is left, and one icon per set status bit. */
void fn_8002356C(StArg* arg, Sprite** tab, s8 a, s8 b)
{
    s32 i;
    s32 n;
    f32 r;
    f32 z;
    Sprite* s;
    Colour4 c;

    for (i = a * 0x1c; i < a * 0x1c + 7; i++) {
        s = tab[i];
        s->x += (f32)(b * 0x96);
        fn_801D52F4(s, 0.0001f * (f32)(i - a * 0x1c) + -1.3f, 0.0f, 1.0f, 1.0f, 0, 0);
        s->x -= (f32)(b * 0x96);
    }
    fn_80023D6C(arg->rows[a].x0, 56.0f + (f32)(b * 0x96), 153.0f);
    fn_80023D6C(arg->rows[a].x4, 143.0f + (f32)(b * 0x96), 172.0f);
    fn_80023D6C(-1, 96.0f + (f32)(b * 0x96), 172.0f);
    fn_80023D6C(arg->rows[a].x2, 85.0f + (f32)(b * 0x96), 172.0f);
    fn_80023D6C(arg->rows[a].x8, 143.0f + (f32)(b * 0x96), 153.0f);
    fn_80023D6C(-1, 122.0f + (f32)(b * 0x96), 153.0f);
    fn_80023D6C(arg->rows[a].x6, 111.0f + (f32)(b * 0x96), 153.0f);

    r = (f32)arg->rows[a].x2 / (f32)arg->rows[a].x4;
    s = fn_801D68C4(lbl_8034762C, 0x21);
    s->pieces->x1 = 80.0f * r + s->pieces->x0;
    fn_801D65B4(s->pieces->colour, &c, 1.0f, 1.0f);
    if (r > 0.5f) {
        c.c[0] = 0xfa;
        c.c[3] = 0x20;
        c.c[1] = (s32)(376.0f * (1.0f - r)) + 0x20;
        c.c[2] = 0xfa - (s32)(100.0f * (1.0f - r));
    } else {
        c.c[0] = 0xfa;
        c.c[3] = 0x20;
        c.c[1] = (s32)(30.0f * (1.0f - 2.0f * r)) + 0xdc;
        c.c[2] = 0xc8 - (s32)(168.0f * (1.0f - 2.0f * r));
    }
    s->pieces->colour = (c.c[0] << 24) + (c.c[1] << 16) + (c.c[2] << 8) + c.c[3];
    s->x += (f32)(b * 0x96);
    z = 0.01f * (f32)a + -1.2f;
    fn_801D52F4(s, z, 0.0f, 1.0f, 1.0f, 0, 1);
    s->x -= (f32)(b * 0x96);

    s = fn_801D68C4(lbl_8034762C, 0x28);
    switch (arg->rows[a].kind) {
    case 0:
        s->pieces->colour = 0xff20ff0a;
        break;
    case 1:
        s->pieces->colour = 0xffff4020;
        break;
    case 2:
        s->pieces->colour = 0xffc800ff;
        break;
    case 3:
        s->pieces->colour = 0xff0096ff;
        break;
    case 4:
        s->pieces->colour = 0xffffc800;
        break;
    case 5:
        s->pieces->colour = 0xffdcdcdc;
        break;
    default:
        s->pieces->colour = 0xffdcdcdc;
        break;
    }
    s->x += (f32)(b * 0x96);
    fn_801D52F4(s, z, 0.0f, 1.0f, 1.0f, 0, 0);
    s->x -= (f32)(b * 0x96);

    for (i = 0, n = 0; i < 11; i++) {
        if (arg->rows[a].flags & (1 << i)) {
            switch (i) {
            case 0:
                s = fn_801D68C4(lbl_8034762C, 0x15);
                break;
            case 1:
                s = fn_801D68C4(lbl_8034762C, 0x16);
                break;
            case 2:
                s = fn_801D68C4(lbl_8034762C, 0x1a);
                break;
            case 3:
                s = fn_801D68C4(lbl_8034762C, 0x18);
                break;
            case 4:
                s = fn_801D68C4(lbl_8034762C, 0x19);
                break;
            case 5:
                s = fn_801D68C4(lbl_8034762C, 0x1b);
                break;
            case 6:
                s = fn_801D68C4(lbl_8034762C, 0x17);
                break;
            case 7:
                s = fn_801D68C4(lbl_8034762C, 0x1e);
                break;
            case 8:
                s = fn_801D68C4(lbl_8034762C, 0x20);
                break;
            case 9:
                s = fn_801D68C4(lbl_8034762C, 0x1c);
                break;
            case 10:
                s = fn_801D68C4(lbl_8034762C, 0x1d);
                break;
            }
            s->x += (f32)(n % 4 * 0x1e + b * 0x96);
            s->y += (f32)(n / 4 * 0x1a);
            fn_801D52F4(s, -1.2998999f, 0.0f, 1.0f, 1.0f, 0, 0);
            s->x -= (f32)(n % 4 * 0x1e + b * 0x96);
            s->y -= (f32)(n / 4 * 0x1a);
            n++;
        }
    }
}

Sprite* fn_80023FEC(s16 a) {
    switch (a) {
    case -1:
        fn_801D68C4(lbl_8034762C, 7);
        break;
    case 0:
        fn_801D68C4(lbl_8034762C, 8);
        break;
    case 1:
        fn_801D68C4(lbl_8034762C, 9);
        break;
    case 2:
        fn_801D68C4(lbl_8034762C, 10);
        break;
    case 3:
        fn_801D68C4(lbl_8034762C, 11);
        break;
    case 4:
        fn_801D68C4(lbl_8034762C, 12);
        break;
    case 5:
        fn_801D68C4(lbl_8034762C, 13);
        break;
    case 6:
        fn_801D68C4(lbl_8034762C, 14);
        break;
    case 7:
        fn_801D68C4(lbl_8034762C, 15);
        break;
    case 8:
        fn_801D68C4(lbl_8034762C, 16);
        break;
    case 9:
        fn_801D68C4(lbl_8034762C, 17);
        break;
    default:
        fn_801D68C4(lbl_8034762C, 7);
        break;
    }
}

void fn_80021AE0(char* path, char* name) {
    Ref_80021AE0 ref;
    Out out;
    void* h;
    Ent_80021AE0* ents;
    Std_80021AE0* std;

    ref.rec = fn_80074E2C(path, name, &out, 0, 3);
    if (ref.rec != 0) {
        ref.out = &out;
        if (fn_8006EAB4(ref.rec) != 0) {
            char buf10[0x40];
            char buf50[0x80];
            strcpy(buf10, name);
            fn_80061048(buf10);
            if (path[0] != '/') {
                strcpy(buf50, "/");
                strcat(buf50, path);
                strcat(buf50, buf10);
                strcat(buf50, ".STD");
            } else {
                sprintf(buf50, "%s%s.STD", path, buf10);
            }
            std = fn_801E1C7C(0x20);
            h = fn_801CC69C(buf50);
            fn_801CC608(h, std, 0x10);
            ents = fn_801E1C7C((std->count + 1) * 0x18);
            fn_801CC608(h, ents, std->count * 0x18);
            ents[std->count].id = 0x26;
            ents[std->count].type = 3;
            fn_801CC65C(h);
            std->ents = ents;
            std->s10 = -1;
            std->s12 = -1;
            std->w14 = 0;
            std->w18 = 0;
            std->w1c = 0;
            fn_80009860(&ref, std);
            fn_800091A4(std);
            ref.rec->std = std;
            strcat(buf10, "0.STD");
            fn_80009750(path, buf10, &ref.rec->std);
        } else {
            fn_80009860(&ref, ref.rec->std);
            fn_800091A4(ref.rec->std);
        }
    }
}

void fn_80021CBC(Task* task) {
    Work21CBC* w = task->work;
    Info* info = w->info;
    Res* r;

    switch (task->state) {
    case 0:
        task->state = 1;
        break;
    case 1:
        fn_80299040(w->w8);
        njPushMatrixEx();
        fn_80286EE8();
        fn_8028B498();
        njTranslate(0, w->px, w->py, w->pz);
        njRotateXYZ(0, (Angle)(w->rx * 182.04445f), (Angle)(w->ry * 182.04445f), (Angle)(w->rz * 182.04445f));
        njScale(0, w->sx, w->sy, w->sz);
        if (fn_8006CEEC(w->w10->p8, &r, info->id, w->s16_)) {
            fn_80035380(w->w0, r, info->t, w->b44);
        } else {
            fn_80035140(w->w0, w->b44);
        }
        fn_8007E264(&w->py, w->px, w->pz);
        njPopMatrixEx();
        if (info != 0) {
            info->t += 1.0f;
            if (info->t >= (f32)r->w4) {
                info->t = 0.0f;
            }
        }
        break;
    case 2:
        fn_801E17E0(info);
        task->flags |= 0x40;
        break;
    }
}

s16 fn_800290E8(s16 idx)
{
    Ent* e = lbl_80302AB0[idx];
    if (e == NULL) {
        return -1;
    }
    if (e->w4 == 0) {
        return -1;
    }
    if (e->h44 != 0) {
        return e->h44;
    }
    if (e->w0 & 0x10000000 || e->w0 & 0x04000000 || e->w0 & 0x01000000 || e->w0 & 0x00400000 || e->w0 & 0x00200000) {
        return 3;
    }
    return 0;
}

void fn_80029168(s16 idx, s32 v)
{
    Ent *e = lbl_80302AB0[idx];

    if (e == NULL) {
        return;
    }
    if (e->w0 & 0x40000000) {
        return;
    }
    if (v == 0) {
        e->x1ee = 0;
    } else if (v < 0) {
        e->x1ee = 1;
    } else if (v > 0) {
        e->x1ee = 2;
    }
    lbl_80302AB0[idx]->x14 = (s32)(f32)fabs((f32)v);
    e = lbl_80302AB0[idx];
    switch (e->x12) {
    case 3:
    case 4:
    case 6:
    case 8:
    case 10:
        e->w0 |= 0x800000;
        break;
    }
}

void fn_800292F8(s16 idx, u16 bits)
{
    Ent *e = lbl_80302AB0[idx];
    if (e == 0) {
        return;
    }
    if (e->w0 & 0x40000000) {
        return;
    }
    switch (e->x12) {
    case 4:
    case 5:
        e->w0 |= 0x20000000;
        break;
    }
    lbl_80302AB0[idx]->h3e |= bits;
    lbl_80302AB0[idx]->h3c |= bits;
}

void fn_80029364(s16 idx, s8 mode, s16 a, s16 b) {
    Ent* e = lbl_80302AB0[idx];
    if (e == NULL) {
        return;
    }
    if (e->w0 & 0x40000000) {
        return;
    }
    switch (mode) {
    case 1:
        if (e->w4 == 0) {
            e->w4 = 1;
            e->h44 = 1;
            e->h6e = 0;
            e->h46 = a;
            e->h48 = b;
        }
        break;
    case 3:
        if (e->w4 == 1) {
            e->w0 |= 0x40000000;
        } else {
            e->x1f4->mode = 1;
        }
    case 2:
        if (e->w4 == 1) {
            e->h44 = 2;
            e->h6e = 0xff;
            e->h46 = a;
            e->h48 = b;
        }
        break;
    }
}

void fn_80029980(Ent* p) {
    s32 i;
    f32 dx;
    f32 dz;

    if (p->x12 != 2 && p->w4 == 1) {
        for (i = 0; i < 12; i++) {
            Ent* e = lbl_80302AB0[i];
            if (e != 0 && i != p->s10 && p->s70 < e->s70 && e->w8 == 1 && e->w4 == 1) {
                dx = floor(p->f58 - e->f58);
                dz = floor(p->f5c - lbl_80302AB0[i]->f5c);
                if ((f32)fabs(dx) < 96.0f && (f32)fabs(dz) < 24.0f) {
                    if (dz < 0.0f) {
                        if (p->f64 == 1.0f) {
                            p->f64 = 0.0f;
                        }
                        if (p->f64 <= 0.0f) {
                            p->f64 = p->f64 + (-1.0f + p->f64);
                        } else {
                            p->f64 = p->f64 - 1.0f;
                        }
                        if (p->f64 < -(24.0f + dz)) {
                            p->f64 = -(24.0f + dz);
                        }
                    } else {
                        if (p->f64 == -1.0f) {
                            p->f64 = 0.0f;
                        }
                        if (p->f64 >= 0.0f) {
                            p->f64 = p->f64 + (1.0f + p->f64);
                        } else {
                            p->f64 += 1.0f;
                        }
                        if (p->f64 > 24.0f) {
                            p->f64 = 24.0f;
                        }
                    }
                }
            }
        }
        p->f5c = p->f5c + p->f64;
    }
}

extern s32 lbl_80347328;
void fn_80012130(NJS_POINT3* p);
void fn_80012100(NJS_POINT3* p);
f32 fn_8000ACF0(NJS_POINT3* v);
f32 njInnerProduct(NJS_POINT3* a, NJS_POINT3* b);
void njProjectScreen(void* m, NJS_POINT3* p, f32* out);

static inline s32 LabelFacing(Ent* e) {
    NJS_POINT3 v;
    NJS_POINT3 d;
    NJS_POINT3 a;
    NJS_POINT3 b;
    f32 len;
    f32 ac;
    Angle ang;

    if (e->w4 == 0) {
        return 1;
    }
    fn_80012130(&a);
    fn_80012100(&b);
    d.x = b.x - a.x;
    d.y = b.y - a.y;
    d.z = b.z - a.z;
    v.x = e->pos.x - a.x;
    v.y = e->pos.y - a.y;
    v.z = e->pos.z - a.z;
    
    ac = acos(njInnerProduct(&d, &v) / (fn_8000ACF0(&d) * fn_8000ACF0(&v)));
    ang = 10430.381f * ac;
    if (0.005493164f * ang <= 90.0f) {
        return 1;
    }
    return 0;
}

void BattleLabelPlace(Ent* e, s8 mode, u32 c) {
    NJS_POINT3 p;
    f32 scr[2];
    s32 vis;
    s16 x;
    s16 y;
    s32 i;

    e->w0 &= 0x7fffffff;
    switch (mode) {
    case 1:
        e->pos.y += e->f68;
    case 0:
        vis = LabelFacing(e);
        if (vis == 1 || ((e->w0 & 0x40000000) && e->s1f8 != 1) || (e->w0 & 0x3fe00000) || e->w8 == 0) {
            p.x = e->pos.x;
            p.y = e->pos.y + e->f68 / 4;
            p.z = e->pos.z;
            njProjectScreen(0, &p, scr);
            x = floorf(scr[0]);
            y = floorf(scr[1]);
            if (mode == 1) {
                y -= ((c >> 2) & 0x3f) * 0x18 + 8;
            }
        } else {
            e->w0 |= 0x80000000;
            if (e->w0 & 0x40000000) {
                e->x1f4->mode = 1;
            }
            break;
        }
            if (((e->w0 & 0x40000000) && e->s1f8 != 1) || (e->w0 & 0x3fe00000) || e->w8 == 0) {
                if (y > 400) {
                    y = 400;
                } else if (y < 0x60) {
                    y = 0x60;
                }
            } else {
                if (y > 400 && y < 500) {
                    y = 400;
                }
            }
            x -= 0x30;
            e->f58 = x;
            e->f5c = y;
            fn_80029980(e);
            if ((e->w0 & 0x40000000) || e->w0 != 0 || e->w8 == 0) {
                if (e->f58 <= 0.0f) {
                    e->f58 = 0.0f;
                } else if (e->f58 >= 544.0f) {
                    e->f58 = 544.0f;
                }
            } else {
                if (-96.0f <= e->f58 && e->f58 <= 0.0f) {
                    e->f58 = 0.0f;
                } else if (544.0f <= e->f58 && e->f58 <= 640.0f) {
                    e->f58 = 544.0f;
                }
            }
        break;
    case 2:
        if (e->s10 < 4) {
            y = e->s10 * 0x28 + 0x4a;
            if (e->s10 == lbl_8034732C && lbl_80347328 != e->s10) {
                e->w4 = 0;
            }
        } else {
            y = 0x4a;
            for (i = 0; i < e->s10 - 4; i++) {
                if (lbl_80302AB0[i + 4] == 0) {
                    y += 0x1e;
                } else if (lbl_80302AB0[i + 4]->s1f8 == 3) {
                    y += 0x26;
                } else {
                    y += 0x1e;
                }
            }
        }
        e->f58 = 502.0f;
        e->f5c = y;
        break;
    }
    e->f88 = e->f58;
    e->f8c = e->f5c;
    if (e->w4 == 0) {
        e->f58 = 0.0f;
        e->f5c = 0.0f;
        e->f60 = 0.0f;
        e->f64 = 0.0f;
        e->x14 = 0;
    }
}


static inline Tsk* FindFrom(Tsk** p, s8 id)
{
    s8 i;
    Tsk** q;
    for (i = 0, q = p; i < 14; q++, i++) {
        if (*q != NULL && (*q)->work->x4c->kind == id) {
            return lbl_80309E24[i];
        }
    }
    return NULL;
}

Tsk* fn_800215EC(s8 id)
{
    return FindFrom(lbl_80309E24, id);
}



static inline s32 ExistsFrom(Tsk** p, s8 id)
{
    s8 i;
    Tsk** q;
    for (i = 0, q = p; i < 14; q++, i++) {
        if (*q != NULL && (*q)->work->x4c->kind == id) {
            return 1;
        }
    }
    return 0;
}

s32 fn_80021728(s8 id)
{
    return ExistsFrom(lbl_80309E24, id);
}

Tsk *fn_80021658(s8 id)
{
    Tsk *r = Find21(id);
    if (r != NULL) {
        return r;
    }
    return Find21(0);
}

/* fn_80025624: the seven-item ring menu. The items sit on a ring that turns 60 degrees a step
 * (lbl_80302A00 holds each item's angle); the task loads the item models, turns the ring when
 * the cursor moves and draws the items, the highlighted item and the arrows. */
typedef struct RingMenu {
    s8* avail;  /* 0x0: per item, 0 when it can't be chosen */
    s8 count;   /* 0x4 */
    s8 cursor;  /* 0x5: -1 while turning */
    s8 cmd;     /* 0x6: 1 turn left, 2 turn right */
    s8 lock;    /* 0x7 */
    s8 side;    /* 0x8 */
    s8 arrows;  /* 0x9 */
} RingMenu;

typedef struct RingHolder {
    RingMenu* menu;
} RingHolder;

typedef struct RingTask {
    u8 pad0[0x18];
    u8 flags;           /* 0x18 */
    u8 state;           /* 0x19 */
    u8 pad1a[6];
    f32 z;              /* 0x20 */
    RingHolder* holder; /* 0x24 */
    Sprite** mdl;      /* 0x28 */
} RingTask;

extern void* lbl_80347628;
extern RingTask* lbl_80346B48;
extern s8 lbl_80346B12;
extern f32 lbl_80346B14;
extern f32 lbl_80346B18;
extern f32 lbl_80346B1C;
extern f32 lbl_80346B20;
extern f32 lbl_80346B24;
extern f32 lbl_80346B28;
extern f32 lbl_80346B2C;
extern s32 lbl_80346B30;
extern s32 lbl_80346B34;
extern s32 lbl_80346B38;
extern s32 lbl_80346B3C;
extern s32 lbl_80346B40;
extern f32 lbl_80346B44;
extern s32 lbl_80346B4C;
extern s32 lbl_80346B98;
extern s32 lbl_80346B9C;
extern s32 lbl_80347324;
extern s32 lbl_8034733C;
extern f32 lbl_80302A00[7];
extern Sprite* fn_801D497C(Sprite* p);
extern void fn_801D4954(Sprite* m);
extern void fn_801D5340(Sprite* m, s32 c, s32 d, f32 z, f32 ang, f32 a, f32 b);
extern void fn_800277F4(Sprite** m, s32 n, f32* ang);
extern void fn_80027484(Sprite** m, s32 n, s32 step);
extern s32 fn_80026FEC(RingTask* o, s32* p);
extern void fn_80026B20(RingTask* o, Sprite** a, Sprite** b, Sprite** c, s32 dir);

#define RING_LOAD(n) fn_801D497C(fn_801D68C4(lbl_80347628, n))
#define RING_Z(k) (0.001f * (k) + -1.2f)

/* A colour as 0xAARRGGBB. */
static inline u32 RingColor(u8 a, u8 r, u8 g, u8 b)
{
    return (a << 24) + (r << 16) + (g << 8) + b;
}

void fn_80025624(RingTask* o)
{
    NJS_POINT3 p;
    NJS_POINT3 q;
    NJS_POINT3 axis;
    NJS_MATRIX m;
    Sprite* sel;
    Sprite* next;
    Sprite* prev;
    RingMenu* menu;
    s32 i;
    s32 k;
    f32 a;
    f32 fade;
    u8 c;

    switch (o->state) {
    case 0:
    case 0xfe:
        lbl_80346B48 = o;
        o->mdl = fn_801E1C7C(0x58);
        o->mdl[0] = RING_LOAD(0xd);
        o->mdl[1] = RING_LOAD(0xf);
        o->mdl[2] = RING_LOAD(0x11);
        o->mdl[3] = RING_LOAD(0xb);
        o->mdl[4] = RING_LOAD(0xc);
        o->mdl[5] = RING_LOAD(0xe);
        o->mdl[6] = RING_LOAD(0x10);
        o->mdl[7] = RING_LOAD(0x34);
        o->mdl[8] = RING_LOAD(0x36);
        o->mdl[9] = RING_LOAD(0x38);
        o->mdl[10] = RING_LOAD(0x32);
        o->mdl[11] = RING_LOAD(0x33);
        o->mdl[12] = RING_LOAD(0x35);
        o->mdl[13] = RING_LOAD(0x37);
        o->mdl[14] = RING_LOAD(0x15);
        o->mdl[17] = RING_LOAD(0x15);
        o->mdl[15] = RING_LOAD(0x1f);
        o->mdl[16] = RING_LOAD(0x20);
        o->mdl[18] = RING_LOAD(0xa);
        o->mdl[19] = RING_LOAD(0x9);
        o->mdl[20] = RING_LOAD(0x1d);
        o->mdl[21] = RING_LOAD(0x1e);
        fn_800277F4(o->mdl, o->holder->menu->count, lbl_80302A00);
        lbl_80346B40 = 0;
        lbl_80346B3C = 0;
        lbl_80346B4C = 0;
        lbl_80346B12 = o->holder->menu->side;
        lbl_80346B28 = 0.0f;
        lbl_80346B24 = 1.0f;
        lbl_80346B20 = 1.0f;
        lbl_80346B34 = 1;
        lbl_80346B18 = 1.0f;
        lbl_80346B14 = 1.0f;
        lbl_80346B2C = 0.0f;
        lbl_80346B1C = 0.0f;
        lbl_80346B38 = 0;
        lbl_80346B44 = 0.0f;
        lbl_80346B30 = 0;
        lbl_80346B9C = 0;
        lbl_80346B98 = 0;
        o->z = -1.3f;
        o->state = 4;
        break;
    case 1:
        break;
    case 2:
        if (fn_80026FEC(o, &lbl_80346B9C) == 1) {
            o->holder->menu->cursor = 3;
            o->state = 4;
            lbl_80346B98 = 1;
        }
        break;
    case 3:
        if (lbl_80346B48 != o) {
            lbl_80346B48 = NULL;
        }
        lbl_80346B38++;
        fn_80027484(o->mdl, o->holder->menu->count, lbl_80346B38);
        fn_800277F4(o->mdl, o->holder->menu->count, lbl_80302A00);
        if (lbl_80346B38 == 2) {
            for (i = 0; i < 7; i++) {
                fn_801D4954(o->mdl[i]);
                o->mdl[i] = NULL;
            }
            o->mdl[0] = RING_LOAD(0xd);
            o->mdl[1] = RING_LOAD(0xf);
            o->mdl[2] = RING_LOAD(0x11);
            o->mdl[3] = RING_LOAD(0xb);
            o->mdl[4] = RING_LOAD(0xc);
            o->mdl[5] = RING_LOAD(0xe);
            if (lbl_80346B98 == 1 && o->holder->menu->side == 0) {
                o->mdl[6] = RING_LOAD(0x12);
            } else {
                o->mdl[6] = RING_LOAD(0x10);
            }
            fn_800277F4(o->mdl, o->holder->menu->count, lbl_80302A00);
            o->state = 4;
        }
        break;
    case 4:
        if (lbl_80347324 == 0) {
            if (lbl_80346B9C == 0 && o->holder->menu->avail[6] == 2) {
                o->holder->menu->cursor = -1;
                o->state = 2;
                o->holder->menu->cmd = 0;
            }
            menu = o->holder->menu;
            if (lbl_80346B12 != menu->side) {
                lbl_80346B2C = 0.0f;
                lbl_80346B1C = 0.0f;
                o->state = 3;
                lbl_80346B38 = 0;
                if (lbl_80346B98 == 1) {
                    if (o->holder->menu->side != 0) {
                        fn_801D4954(o->mdl[6]);
                        o->mdl[6] = RING_LOAD(0x10);
                        fn_801D4954(o->mdl[13]);
                        o->mdl[13] = RING_LOAD(0x37);
                    } else {
                        fn_801D4954(o->mdl[6]);
                        o->mdl[6] = RING_LOAD(0x12);
                        fn_801D4954(o->mdl[13]);
                        o->mdl[13] = RING_LOAD(0x39);
                    }
                }
                fn_80027484(o->mdl, o->holder->menu->count, lbl_80346B38);
                fn_800277F4(o->mdl, o->holder->menu->count, lbl_80302A00);
                for (i = 0; i < 7; i++) {
                    sel = o->mdl[i];
                    if (o->holder->menu->avail[i] == 0) {
                        fn_801D5340(sel, 0, 0, RING_Z(i), lbl_80302A00[i], 0.5f, 1.0f);
                    } else {
                        fn_801D5340(sel, 0, 0, RING_Z(i), lbl_80302A00[i], 1.0f, 1.0f);
                    }
                }
                fn_801D5340(o->mdl[20], 0, 0, -1.1880001f, 0.0f, 1.0f, 1.0f);
                fn_801D5340(o->mdl[21], 0, 0, -1.1880001f, 0.0f, 1.0f, 1.0f);
                fn_801D5340(o->mdl[19], 0, 0, RING_Z(i), 0.0f, 1.0f, 1.0f);
                fn_801D5340(o->mdl[18], 0, 0, RING_Z(i + 1), 0.0f, 1.0f, 1.0f);
                lbl_80346B12 = o->holder->menu->side;
                break;
            }
            switch (menu->cmd) {
            case 0:
                break;
            case 1:
                lbl_80346B40 = -1;
                lbl_80346B3C = 3;
                lbl_80346B4C = o->holder->menu->cursor;
                break;
            case 2:
                lbl_80346B40 = 1;
                lbl_80346B3C = 3;
                lbl_80346B4C = o->holder->menu->cursor;
                break;
            }
            if (lbl_80346B40 != 0) {
                lbl_80346B3C--;
                axis.x = 0.0f;
                axis.y = 0.0f;
                axis.z = 1.0f;
                for (i = 0; i < o->holder->menu->count; i++) {
                    p.x = 19.0f + o->mdl[i]->x - 102.0f;
                    p.y = 19.0f + o->mdl[i]->y - 381.0f;
                    p.z = 0.0f;
                    njUnitMatrix(m);
                    njRotate(m, &axis, -lbl_80346B40 * -0x71c);
                    njCalcPoint(m, &p, &q);
                    o->mdl[i]->x = 102.0f + (q.x - 19.0f);
                    o->mdl[i]->y = 381.0f + (q.y - 19.0f);
                }
                k = lbl_80346B40;
                lbl_80346B2C = 60.0f * k + lbl_80346B2C;
                for (i = 0; i < 7; i++) {
                    lbl_80302A00[i] = (s32)(182.04445f * (lbl_80346B2C + -180.0f * (i + 1)));
                }
                if (30.0f + lbl_80346B2C <= 180.0f || 0.0f <= lbl_80346B2C - 30.0f) {
                    if ((s32)lbl_80346B2C == 0) {
                        lbl_80346B2C = 0.0f;
                    }
                    if ((s32)lbl_80346B2C == -121) {
                        lbl_80346B2C = 180.0f;
                    }
                }
                if (lbl_80346B3C <= 0) {
                    o->holder->menu->cursor = lbl_80346B4C + k;
                    if (o->holder->menu->cursor < 0) {
                        o->holder->menu->cursor = 6;
                    }
                    if (o->holder->menu->cursor >= 7) {
                        o->holder->menu->cursor = 0;
                    }
                    lbl_80346B40 = 0;
                } else {
                    o->holder->menu->cursor = -1;
                }
                lbl_80346B1C = lbl_80346B2C / 6.0f / 2.0f;
                lbl_80346B44 = (s32)(182.04445f * (-15.0f * lbl_80346B1C / 15.0f));
            }
            prev = NULL;
            next = NULL;
            sel = NULL;
            fn_80026B20(o, &sel, &next, &prev, lbl_80346B40);
            if ((u32)o->mdl[14] > 0x8CFFFFFF) {
                o->mdl[14] = NULL;
                o->mdl[14] = NULL;
            }
            fn_801D4954(o->mdl[14]);
            o->mdl[14] = NULL;
            if (sel == NULL) { /* the original stores the 0 back */
                sel = NULL;
            }
            o->mdl[14] = fn_801D497C(sel);
            if (lbl_80346B40 != 0) {
                if (next == NULL) { /* as above */
                    next = NULL;
                }
                fn_801D4954(o->mdl[17]);
                o->mdl[17] = NULL;
                o->mdl[17] = fn_801D497C(next);
            }
            for (i = 0; i < 7; i++) {
                sel = o->mdl[i];
                if (o->holder->menu->avail[i] == 0) {
                    fn_801D5340(sel, 0, 0, RING_Z(i), lbl_80302A00[i], 0.5f, 1.0f);
                } else {
                    fn_801D5340(sel, 0, 0, RING_Z(i), lbl_80302A00[i], 1.0f, 1.0f);
                }
            }
            sel = o->mdl[20];
            fn_801D5340(sel, 0, 0, -1.1880001f, 0.0f, 1.0f, 1.0f);
            sel = o->mdl[21];
            fn_801D5340(sel, 0, 0, -1.1880001f, 0.0f, 1.0f, 1.0f);
            sel = o->mdl[19];
            fn_801D5340(sel, 0, 0, RING_Z(i), lbl_80346B44, 1.0f, 1.0f);
            sel = o->mdl[18];
            fn_801D5340(sel, 0, 0, RING_Z(i + 1), 0.0f, 1.0f, 1.0f);
            if (o->holder->menu->cursor != -1) {
                lbl_80346B18 = 1.0f;
                sel = o->mdl[7 + o->holder->menu->cursor];
                if (o->holder->menu->lock != 0) {
                    sel->pieces->colour = RingColor(0xff, 0xc8, 0xc8, 0xc8);
                    fn_801D5340(sel, 0, 0, RING_Z(i + 2), 0.0f, 1.0f, 1.0f);
                    lbl_80346B30 = 0;
                } else {
                    if (lbl_80346B30 >= 0 && lbl_80346B30 < 3) {
                        c = (3 - lbl_80346B30) * 0x15 + 0xc0;
                        sel->pieces->colour = RingColor(0xff, c, c, 0xc0);
                        fn_801D5340(sel, 0, 0, RING_Z(i + 2), 0.0f, 1.0f, 1.0f);
                    } else {
                        sel->pieces->colour = RingColor(0xff, 0xc8, 0xc8, 0xc8);
                        fn_801D5340(sel, 0, 0, RING_Z(i + 2), 0.0f, 1.0f, 1.0f);
                        lbl_80346B30 = 4;
                    }
                    lbl_80346B30++;
                }
            } else {
                fade = lbl_80346B18 - 0.33333334f;
                lbl_80346B30 = 0;
                lbl_80346B18 = fade;
                lbl_80346B14 = 1.0f - fade;
                if (o->holder->menu->cursor == -1) {
                    a = o->holder->menu->avail[lbl_80346B4C] == 0 ? 0.5f : 1.0f;
                } else {
                    lbl_80346B18 = 1.0f;
                    a = 0.5f;
                }
                sel = prev;
                sel->pieces->colour = RingColor(0xff, 0xc8, 0xc8, 0xc8);
                fn_801D5340(sel, 0, 0, RING_Z(i + 2), 0.0f, a, fade);
            }
            if (o->holder->menu->cursor == -1 || o->holder->menu->avail[o->holder->menu->cursor] == 0) {
                lbl_80346B24 -= 0.33333334f;
                lbl_80346B20 = 1.0f - lbl_80346B24;
                if (o->holder->menu->cursor == -1) {
                    if (o->holder->menu->avail[lbl_80346B4C] == 0) {
                        a = 0.5f;
                    } else {
                        a = 1.0f;
                    }
                } else {
                    lbl_80346B24 = 1.0f;
                    a = 0.5f;
                }
            } else {
                a = 1.0f;
                lbl_80346B24 = a;
            }
            fn_801D5340(o->mdl[14], 0, 0, RING_Z(i + 3), 0.0f, a, lbl_80346B24);
            if (lbl_80346B40 != 0) {
                k = lbl_80346B4C + lbl_80346B40;
                if (k < 0) {
                    k += 7;
                } else if (k > 6) {
                    k -= 7;
                }
                fn_801D5340(o->mdl[17], 0, 0, RING_Z(i + 4), 0.0f, o->holder->menu->avail[k] == 0 ? 0.5f : 1.0f, lbl_80346B20);
            }
            if (o->holder->menu->arrows == 1) {
                switch (lbl_80346B40) {
                case 0:
                    if (lbl_80346B28 > 1.0 || 0.0 > lbl_80346B28) {
                        lbl_80346B34 *= -1;
                    }
                    fn_801D5340(o->mdl[15], 0, 1, -1.09f, 0.0f, 1.0f, lbl_80346B28);
                    fn_801D5340(o->mdl[16], 0, 1, -1.09f, 0.0f, 1.0f, lbl_80346B28);
                    lbl_80346B28 += lbl_80346B34 / 15.0f;
                    break;
                case 1:
                    lbl_80346B34 = 1;
                    lbl_80346B28 = 1.0f;
                    fn_801D5340(o->mdl[16], 0, 1, -1.09f, 0.0f, 1.0f, lbl_80346B28);
                    lbl_80346B28 = 0.0f;
                    break;
                case -1:
                    lbl_80346B34 = 1;
                    lbl_80346B28 = 1.0f;
                    fn_801D5340(o->mdl[15], 0, 1, -1.09f, 0.0f, 1.0f, lbl_80346B28);
                    lbl_80346B28 = 0.0f;
                    break;
                }
            } else {
                lbl_80346B34 = -1;
                lbl_80346B28 = 0.0f;
            }
            lbl_80346B12 = o->holder->menu->side;
        }
        if (lbl_8034733C == 4) {
            lbl_80346B9C = 0;
            lbl_80346B98 = 0;
        }
        break;
    case 5:
        for (i = 0; i < 22; i++) {
            fn_801D4954(o->mdl[i]);
        }
        o->state = 0xff;
        break;
    case 0xff:
        o->flags |= 0x40;
        break;
    }
}

void fn_80026B20(RingTask* o, Sprite** a, Sprite** b, Sprite** c, s32 dir)
{
    RingMenu* menu = o->holder->menu;

    switch (menu->cursor) {
    case 3:
        *a = fn_801D68C4(lbl_80347628, 0x15);
        break;
    case 4:
        *a = fn_801D68C4(lbl_80347628, 0x16);
        break;
    case 0:
        *a = fn_801D68C4(lbl_80347628, 0x17);
        break;
    case 1:
        *a = fn_801D68C4(lbl_80347628, 0x19);
        break;
    case 6:
        if (lbl_80346B98 == 1 && menu->side == 0) {
            *a = fn_801D68C4(lbl_80347628, 0x1c);
        } else {
            *a = fn_801D68C4(lbl_80347628, 0x1a);
        }
        break;
    case 5:
        *a = fn_801D68C4(lbl_80347628, 0x18);
        break;
    case 2:
        *a = fn_801D68C4(lbl_80347628, 0x1b);
        break;
    case -1:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    default:
        switch (lbl_80346B4C) {
        case 3:
            *a = fn_801D68C4(lbl_80347628, 0x15);
            *c = fn_801D68C4(lbl_80347628, 0x32);
            if (dir == 1) {
                *b = fn_801D68C4(lbl_80347628, 0x16);
            } else if (dir == -1) {
                *b = fn_801D68C4(lbl_80347628, 0x1b);
            }
            break;
        case 4:
            *a = fn_801D68C4(lbl_80347628, 0x16);
            *c = fn_801D68C4(lbl_80347628, 0x33);
            if (dir == 1) {
                *b = fn_801D68C4(lbl_80347628, 0x18);
            } else if (dir == -1) {
                *b = fn_801D68C4(lbl_80347628, 0x15);
            }
            break;
        case 0:
            *a = fn_801D68C4(lbl_80347628, 0x17);
            *c = fn_801D68C4(lbl_80347628, 0x34);
            if (dir == 1) {
                *b = fn_801D68C4(lbl_80347628, 0x19);
            } else if (dir == -1) {
                if (lbl_80346B98 == 1 && o->holder->menu->side == 0) {
                    *b = fn_801D68C4(lbl_80347628, 0x1c);
                } else {
                    *b = fn_801D68C4(lbl_80347628, 0x1a);
                }
            }
            break;
        case 1:
            *a = fn_801D68C4(lbl_80347628, 0x19);
            *c = fn_801D68C4(lbl_80347628, 0x36);
            if (dir == 1) {
                *b = fn_801D68C4(lbl_80347628, 0x1b);
            } else if (dir == -1) {
                *b = fn_801D68C4(lbl_80347628, 0x17);
            }
            break;
        case 6:
            if (lbl_80346B98 == 1 && menu->side == 0) {
                *a = fn_801D68C4(lbl_80347628, 0x1c);
            } else {
                *a = fn_801D68C4(lbl_80347628, 0x1a);
            }
            if (lbl_80346B98 == 1 && o->holder->menu->side == 0) {
                *c = fn_801D68C4(lbl_80347628, 0x39);
            } else {
                *c = fn_801D68C4(lbl_80347628, 0x37);
            }
            if (dir == 1) {
                *b = fn_801D68C4(lbl_80347628, 0x17);
            } else if (dir == -1) {
                *b = fn_801D68C4(lbl_80347628, 0x18);
            }
            break;
        case 5:
            *a = fn_801D68C4(lbl_80347628, 0x18);
            *c = fn_801D68C4(lbl_80347628, 0x35);
            if (dir == 1) {
                if (lbl_80346B98 == 1 && o->holder->menu->side == 0) {
                    *b = fn_801D68C4(lbl_80347628, 0x1a);
                } else {
                    *b = fn_801D68C4(lbl_80347628, 0x1c);
                }
            } else if (dir == -1) {
                *b = fn_801D68C4(lbl_80347628, 0x16);
            }
            break;
        case 2:
            *a = fn_801D68C4(lbl_80347628, 0x1b);
            *c = fn_801D68C4(lbl_80347628, 0x38);
            if (dir == 1) {
                *b = fn_801D68C4(lbl_80347628, 0x15);
            } else if (dir == -1) {
                *b = fn_801D68C4(lbl_80347628, 0x19);
            }
            break;
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        default:
            *a = fn_801D68C4(lbl_80347628, 0x15);
            *c = fn_801D68C4(lbl_80347628, 0x32);
            if (dir == 1) {
                *b = fn_801D68C4(lbl_80347628, 0x19);
            } else if (dir == -1) {
                *b = fn_801D68C4(lbl_80347628, 0x16);
            }
            break;
        }
        break;
    }
}

s16 fn_800217D0(u32 id, u32 *flags) {
    s16 r = -1;
    switch (id) {
    case 0:
    case 2:
        r = 2;
        break;
    case 1:
    case 3:
        r = 7;
        break;
    case 4:
        r = 6;
        break;
    case 5:
        r = 4;
        break;
    case 6:
        r = 8;
        break;
    case 7:
        r = 5;
        break;
    case 8:
        r = 0xc;
        break;
    case 9:
        r = 0x11;
        break;
    case 10:
        r = 0x14;
        break;
    case 11:
        r = 0x1d;
        break;
    case 15:
        r = 0x13;
        break;
    case 12:
        r = 0x18;
        break;
    case 13:
        r = 0x19;
        break;
    case 17:
        *flags |= 0x100000;
        r = 4;
        break;
    case 14:
        r = 0xe;
        break;
    case 19:
        r = 0xf;
        break;
    case 16:
    case 18:
    case 20:
    case 21:
    case 22:
        break;
    }
    while (r < 0) {
    }
    return r;
}

int fn_8002188C(KindRec *p) {
    if ((s8)p->kind >= 12) {
        return 0x23;
    }
    if (fn_80014C90(p->kind, 0x400)) {
        return 0x23;
    }
    if (fn_80014C90(p->kind, 0x800)) {
        switch (p->mode) {
        default:
            return 0x24;
        case 1:
        case 3:
            return 0x25;
        }
    }
    return 0x23;
}

void fn_8002923C(s16 id, u32 mask, s32 mode) {
    Ent *e;
    s32 bits;
    e = lbl_80302AB0[id];
    if (e == 0) {
        return;
    }
    if (e->w0 & 0x40000000) {
        return;
    }
    if (mode == 1) {
        switch (e->x12) {
        case 1:
        case 2:
        case 6:
        case 8:
            bits = mask & e->h3c;
            if ((u16)bits == 0) {
                return;
            }
            e->h40 = e->h40 | bits;
            lbl_80302AB0[id]->x6c = 0xff;
            lbl_80302AB0[id]->w0 = lbl_80302AB0[id]->w0 | 0x08000000;
            return;
        default:
            e->h3c = e->h3c & ~mask;
            return;
        }
    }
    e->h3c = e->h3c & ~mask;
}

void fn_8002942C(s16 id, s16 n) {
    Ent *e;
    HudEnt *s;
    s32 v;
    if (lbl_80302AB0[id] == 0) {
        return;
    }
    if (lbl_80302AB0[id]->w0 & 0x40000000) {
        return;
    }
    lbl_80302AB0[id]->x12 = n;
    switch (n) {
    case 2:
        if (lbl_80347394 == 0) {
            e = lbl_80302AB0[id];
            s = lbl_80309DE4[id];
            v = s->x14;
            if (e->x28 != v) {
                e->x28 = v;
                lbl_80302AB0[id]->f20 = (f32)v;
            }
        }
        break;
    case 9:
        lbl_80302AB0[id]->w0 = lbl_80302AB0[id]->w0 | 0x02000000;
        break;
    }
}

void fn_80022F74(StTask* t)
{
    StHolder* h = t->task.work;
    StArg* arg = h->arg;
    s32 i;
    s32 n;
    s32 c;
    s32 cur;
    void* a;
    void* b;

    switch (t->task.state) {
    case 0:
    case 0xfe:
        n = 0;
        c = 0;
        while (c != -1 && n < 4) {
            c = lbl_8030B7F4.party[n];
            n++;
        }
        i = n;
        if (c == -1) {
            i = n - 1;
        }
        lbl_80346AD0 = i;
        t->tab = fn_801E1C7C(i * 0x70);
        for (i = 0; i < lbl_80346AD0; i++) {
            t->tab[i * 0x1c] = fn_801D497C(fn_801D68C4(lbl_8034762C, 0));
            switch (lbl_8030B7F4.party[i]) {
            case 0:
                a = fn_801D68C4(lbl_8034762C, 0x22);
                b = fn_801D68C4(lbl_8034762C, 1);
                break;
            case 1:
                a = fn_801D68C4(lbl_8034762C, 0x23);
                b = fn_801D68C4(lbl_8034762C, 2);
                break;
            case 2:
                a = fn_801D68C4(lbl_8034762C, 0x24);
                b = fn_801D68C4(lbl_8034762C, 3);
                break;
            case 3:
                a = fn_801D68C4(lbl_8034762C, 0x25);
                b = fn_801D68C4(lbl_8034762C, 4);
                break;
            case 4:
                a = fn_801D68C4(lbl_8034762C, 0x26);
                b = fn_801D68C4(lbl_8034762C, 5);
                break;
            case 5:
                a = fn_801D68C4(lbl_8034762C, 0x27);
                b = fn_801D68C4(lbl_8034762C, 6);
                break;
            case -1:
            case 6:
                a = fn_801D68C4(lbl_8034762C, 0x22);
                b = fn_801D68C4(lbl_8034762C, 1);
                break;
            }
            t->tab[i * 0x1c + 1] = fn_801D497C(a);
            t->tab[i * 0x1c + 2] = fn_801D497C(b);
            t->tab[i * 0x1c + 3] = fn_801D497C(fn_801D68C4(lbl_8034762C, 0x14));
            t->tab[i * 0x1c + 4] = fn_801D497C(fn_801D68C4(lbl_8034762C, 0x12));
            t->tab[i * 0x1c + 5] = fn_801D497C(fn_801D68C4(lbl_8034762C, 0x13));
            t->tab[i * 0x1c + 6] = fn_801D497C(fn_801D68C4(lbl_8034762C, 0x1f));
            t->tab[i * 0x1c + 7] = fn_801D497C(fn_801D68C4(lbl_8034762C, 7));
            t->tab[i * 0x1c + 8] = fn_801D497C(fn_801D68C4(lbl_8034762C, 8));
            t->tab[i * 0x1c + 9] = fn_801D497C(fn_801D68C4(lbl_8034762C, 9));
            t->tab[i * 0x1c + 10] = fn_801D497C(fn_801D68C4(lbl_8034762C, 10));
            t->tab[i * 0x1c + 11] = fn_801D497C(fn_801D68C4(lbl_8034762C, 11));
            t->tab[i * 0x1c + 12] = fn_801D497C(fn_801D68C4(lbl_8034762C, 12));
            t->tab[i * 0x1c + 13] = fn_801D497C(fn_801D68C4(lbl_8034762C, 13));
            t->tab[i * 0x1c + 14] = fn_801D497C(fn_801D68C4(lbl_8034762C, 14));
            t->tab[i * 0x1c + 15] = fn_801D497C(fn_801D68C4(lbl_8034762C, 15));
            t->tab[i * 0x1c + 16] = fn_801D497C(fn_801D68C4(lbl_8034762C, 16));
            t->tab[i * 0x1c + 17] = fn_801D497C(fn_801D68C4(lbl_8034762C, 0x15));
            t->tab[i * 0x1c + 18] = fn_801D497C(fn_801D68C4(lbl_8034762C, 0x16));
            t->tab[i * 0x1c + 19] = fn_801D497C(fn_801D68C4(lbl_8034762C, 0x17));
            t->tab[i * 0x1c + 20] = fn_801D497C(fn_801D68C4(lbl_8034762C, 0x18));
            t->tab[i * 0x1c + 21] = fn_801D497C(fn_801D68C4(lbl_8034762C, 0x19));
            t->tab[i * 0x1c + 22] = fn_801D497C(fn_801D68C4(lbl_8034762C, 0x1a));
            t->tab[i * 0x1c + 23] = fn_801D497C(fn_801D68C4(lbl_8034762C, 0x1b));
            t->tab[i * 0x1c + 24] = fn_801D497C(fn_801D68C4(lbl_8034762C, 0x1c));
            t->tab[i * 0x1c + 25] = fn_801D497C(fn_801D68C4(lbl_8034762C, 0x1d));
            t->tab[i * 0x1c + 26] = fn_801D497C(fn_801D68C4(lbl_8034762C, 0x1e));
            t->tab[i * 0x1c + 27] = fn_801D497C(fn_801D68C4(lbl_8034762C, 0x20));
        }
        lbl_80346ACC = 0;
        t->task.f20 = -1.3f;
        t->task.state = 1;
        break;
    case 1:
        if (lbl_80347324 != 0) {
            break;
        }
        cur = lbl_8034732C;
        if ((lbl_80346ACC = arg->x0) == 0) {
            fn_8002356C(arg, t->tab, cur, 0);
        } else {
            for (i = 0; i < lbl_80346AD0; i++) {
                fn_8002356C(arg, t->tab, i, i);
            }
        }
        break;
    case 2:
        for (i = 0; i < lbl_80346AD0 * 0x1c; i++) {
            fn_801D4954(t->tab[i]);
            t->tab[i] = NULL;
        }
        t->task.state = 0xff;
        break;
    case 0xff:
        t->task.flags |= 0x40;
        break;
    }
}

void fn_800240EC(ListTask* t)
{
    switch (t->state) {
    case 0:
    case 0xfe:
        lbl_80346AF0 = 0;
        lbl_80346AEC = 0;
        switch (t->work->arg->kind) {
        case 0:
            lbl_80346AC0 = 2;
            t->tab = fn_801E1C7C(8);
            t->tab[1] = fn_801D497C(fn_801D68C4(lbl_80347628, 0x2f));
            lbl_80346B10 = 0x115;
            lbl_80346B0E = 0x12a;
            lbl_80346B0C = 0x144;
            lbl_80346B0A = 0x12d;
            lbl_80346B08 = 0x21c;
            lbl_80346B06 = 0x12d;
            break;
        case 1:
            lbl_80346AC0 = 2;
            t->tab = fn_801E1C7C(8);
            t->tab[1] = fn_801D497C(fn_801D68C4(lbl_80347628, 0x2f));
            lbl_80346B10 = 0x115;
            lbl_80346B0E = 0x12a;
            lbl_80346B0C = 0x144;
            lbl_80346B0A = 0x12d;
            lbl_80346B08 = 0x21c;
            lbl_80346B06 = 0x12d;
            break;
        case 2:
            lbl_80346AC0 = 2;
            t->tab = fn_801E1C7C(8);
            t->tab[1] = fn_801D497C(fn_801D68C4(lbl_80347628, 0x2e));
            lbl_80346B10 = 0x115;
            lbl_80346B0E = 0x12a;
            lbl_80346B0C = 0x144;
            lbl_80346B0A = 0x12d;
            lbl_80346B08 = 0x21c;
            lbl_80346B06 = 0x12d;
            break;
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
            lbl_80346AC0 = 7;
            t->tab = fn_801E1C7C(0x1c);
            t->tab[1] = fn_801D497C(fn_801D68C4(lbl_80347628, 0x3e));
            t->tab[2] = fn_801D497C(fn_801D68C4(lbl_80347628, 0x3f));
            t->tab[3] = fn_801D497C(fn_801D68C4(lbl_80347628, 0x40));
            t->tab[4] = fn_801D497C(fn_801D68C4(lbl_80347628, 0x41));
            t->tab[5] = fn_801D497C(fn_801D68C4(lbl_80347628, 0x42));
            t->tab[6] = fn_801D497C(fn_801D68C4(lbl_80347628, 0x43));
            lbl_80346B10 = 0x115;
            lbl_80346B0E = 0x12a;
            lbl_80346B0C = 0x144;
            lbl_80346B0A = 0x12d;
            lbl_80346B08 = 0x21c;
            lbl_80346B06 = 0x12d;
            lbl_80346B04 = 0x113;
            lbl_80346B02 = 0x111;
            lbl_80346B00 = 0x10e;
            lbl_80346AFE = 0x10b;
            break;
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
            lbl_80346AC0 = 5;
            t->tab = fn_801E1C7C(0x14);
            t->tab[1] = fn_801D497C(fn_801D68C4(lbl_80347628, 0x44));
            t->tab[2] = fn_801D497C(fn_801D68C4(lbl_80347628, 0x45));
            t->tab[3] = fn_801D497C(fn_801D68C4(lbl_80347628, 0x4b));
            t->tab[4] = fn_801D497C(fn_801D68C4(lbl_80347628, 0x4c));
            lbl_80346B10 = 0x115;
            lbl_80346B0E = 0x12a;
            lbl_80346B0C = 0x144;
            lbl_80346B0A = 0x12d;
            lbl_80346B08 = 0x21c;
            lbl_80346B06 = 0x12d;
            lbl_80346B04 = 0x113;
            lbl_80346B02 = 0x111;
            lbl_80346B00 = 0x10e;
            lbl_80346AFE = 0x10b;
            break;
        }
        lbl_80346AF8 = 1;
        lbl_80346AF4 = 0.0f;
        t->tab[0] = fn_801D497C(fn_801D68C4(lbl_80347628, 0x3b));
        lbl_80346AFC = 0x20;
        lbl_80346AFA = 0x18d;
        lbl_80346AF9 = 0;
        t->state = 1;
        t->f20 = -1.3f;
        break;
    case 1:
        if (lbl_80347324 != 0) {
            break;
        }
        lbl_80346AD8 = 0;
        lbl_80346AF0 = (t->work->arg->flags >> 1) & 1;
        if (lbl_80346AF4 > 1.0 || 0.0 > lbl_80346AF4) {
            lbl_80346AF8 *= -1;
        }
        lbl_80346AF4 = lbl_80346AF4 + lbl_80346AF8 / 15.0f;
        if (t->work->arg->flags & 1) {
            switch (t->work->arg->input) {
            case 0:
                lbl_80346AF9 = 0;
                break;
            case 1:
                lbl_80346AF9 = -1;
                t->work->arg->cursor--;
                if (t->work->arg->cursor < 0) {
                    t->work->arg->cursor = t->work->arg->count - 1;
                }
                break;
            case 2:
                lbl_80346AF9 = 1;
                t->work->arg->cursor++;
                if (t->work->arg->cursor >= t->work->arg->count) {
                    t->work->arg->cursor = 0;
                }
                break;
            }
            fn_8002468C(t);
        }
        break;
    case 2:
        for (lbl_80346AE4 = 0; lbl_80346AE4 < lbl_80346AC0; lbl_80346AE4++) {
            fn_801D4954(t->tab[lbl_80346AE4]);
            t->tab[lbl_80346AE4] = NULL;
        }
        lbl_80346AC0 = 0;
        t->state = 0xff;
        break;
    case 0xff:
        t->flags |= 0x40;
        break;
    }
}

#define ARROWS()                                                        \
    s = fn_801D68C4(lbl_80347628, 0x5c);                                \
    s->x = lbl_80346B04 + lbl_80346ADC * 0x30;                          \
    s->y = lbl_80346B02;                                                \
    fn_801D5340(s, 0, 0, -1.09f, 0.0f, 1.0f, 1.0f);                     \
    s = fn_801D68C4(lbl_80347628, 0x5d);                                \
    s->x = lbl_80346B00 + lbl_80346ADC * 0x30;                          \
    s->y = lbl_80346AFE;                                                \
    fn_801D5340(s, 0, 1, -1.07f, 0.0f, 1.0f, lbl_80346AF4)

void fn_8002468C(ListTask* t)
{
    Sprite* s;
    Sprite* s2;
    Sprite* p;
    f32 savez;
    f32 savez2;

    switch (t->work->arg->kind) {
    case 0:
    case 1:
    case 2:
        if ((lbl_80346AE0 = t->work->arg->count) <= 0) {
            break;
        }
        fn_801D4954(t->tab[1]);
        t->tab[1] = NULL;
        switch (lbl_80346AE0) {
        case 1:
            t->tab[1] = fn_801D497C(fn_801D68C4(lbl_80347628, 0x2d));
            break;
        case 2:
            t->tab[1] = fn_801D497C(fn_801D68C4(lbl_80347628, 0x2e));
            break;
        case 3:
            t->tab[1] = fn_801D497C(fn_801D68C4(lbl_80347628, 0x2f));
            break;
        case 4:
            t->tab[1] = fn_801D497C(fn_801D68C4(lbl_80347628, 0x30));
            break;
        case 5:
            t->tab[1] = fn_801D497C(fn_801D68C4(lbl_80347628, 0x31));
            break;
        default:
            t->tab[1] = fn_801D497C(fn_801D68C4(lbl_80347628, 0x31));
            break;
        }
        fn_801D5340(t->tab[1], 0, 0, 0.001f * lbl_80346AE4 + -1.199f, 0.0f, 1.0f, 1.0f);
        break;
    case 3: case 4: case 5: case 6: case 7: case 8:
    case 9: case 10: case 11: case 12: case 13: case 14:
    default:
        s2 = fn_801D68C4(lbl_80347628, 0x22);
        s = fn_801D68C4(lbl_80347628, 0x21);
        switch (t->work->arg->kind) {
        case 4:
            s->pieces->colour = 0xc8400000;
            break;
        case 6:
            s->pieces->colour = 0xc8000040;
            break;
        case 7:
            s->pieces->colour = 0xc82a2000;
            break;
        case 3:
            s->pieces->colour = 0xc8004000;
            break;
        case 5:
            s->pieces->colour = 0xc820002a;
            break;
        case 8:
            s->pieces->colour = 0xdc101820;
            break;
        case 14:
        default:
            s->pieces->colour = 0xc8101010;
            break;
        }
        fn_801D5340(s, 0, 0, -1.191f, 0.0f, 1.0f, 1.0f);
        fn_801D5340(s2, 0, 0, -1.191f, 0.0f, 1.0f, 1.0f);
        break;
    }
    savez = TextGetZ();
    TextSetZ(-1.0899f);
    fn_800250F4(t);
    TextSetZ(savez);
    switch (t->work->arg->kind) {
    case 0: case 1: case 2:
        break;
    case 3: case 4: case 5: case 6: case 7: case 8:
    case 9: case 10: case 11: case 12: case 13: case 14:
        for (lbl_80346AE4 = 0; lbl_80346AE4 < lbl_80346AC0; lbl_80346AE4++) {
            switch (t->work->arg->kind) {
            case 3: case 4: case 5: case 6: case 7: case 8:
                lbl_80346ADC = t->work->arg->kind - 3;
                if (lbl_80346AE4 != 0 && (t->work->arg->mask & (1 << (lbl_80346AE4 - 1)))) {
                    lbl_80346AD8++;
                    if (lbl_80346AE4 == t->work->arg->kind - 2) {
                        fn_801D5340(t->tab[lbl_80346AE4], 0, 0, -1.188f, 0.0f, 1.0f, 1.0f);
                    } else {
                        fn_801D5340(t->tab[lbl_80346AE4], 0, 0, 0.001f * lbl_80346AE4 + -1.199f, 0.0f, 0.5f, 1.0f);
                    }
                }
                break;
            case 9: case 10: case 11: case 12: case 13: case 14:
                switch (lbl_8030B7F4.party[lbl_8034732C]) {
                case 0:
                    p = fn_801D68C4(lbl_80347628, 0x45);
                    break;
                case 1:
                    p = fn_801D68C4(lbl_80347628, 0x46);
                    break;
                case 2:
                    p = fn_801D68C4(lbl_80347628, 0x47);
                    break;
                case 3:
                    p = fn_801D68C4(lbl_80347628, 0x48);
                    break;
                case 4:
                    p = fn_801D68C4(lbl_80347628, 0x49);
                    break;
                case 5:
                    p = fn_801D68C4(lbl_80347628, 0x4a);
                    break;
                case -1:
                case 6:
                    p = fn_801D68C4(lbl_80347628, 0x45);
                    break;
                }
                fn_801D4954(t->tab[2]);
                t->tab[2] = fn_801D497C(p);
                lbl_80346ADC = t->work->arg->kind - 9;
                if (lbl_80346AE4 != 0 && (t->work->arg->mask & (1 << (lbl_80346AE4 - 1)))) {
                    if (lbl_80346AE4 == t->work->arg->kind - 8) {
                        fn_801D5340(t->tab[lbl_80346AE4], 0, 0, -1.188f, 0.0f, 1.0f, 1.0f);
                    } else {
                        fn_801D5340(t->tab[lbl_80346AE4], 0, 0, 0.001f * lbl_80346AE4 + -1.199f, 0.0f, 0.5f, 1.0f);
                    }
                }
                break;
            }
        }
        switch (t->work->arg->kind) {
        case 3: case 4: case 5: case 6: case 7: case 8:
            if (lbl_80346AD8 > 1) {
                ARROWS();
            }
            break;
        case 9: case 10: case 11: case 12: case 13: case 14:
            if (t->work->arg->cursor == -1) {
                ARROWS();
            }
            break;
        }
        break;
    }
    if (t->work->arg->cursor != -1) {
        s = fn_801D68C4(lbl_80347628, 0x5e);
        s->x = lbl_80346B10;
        s->y = lbl_80346B0E + t->work->arg->cursor * 0x18;
        fn_801D5340(s, 0, 1, -1.09f, 0.0f, 1.0f, 1.0f);
        if (t->work->arg->pages > 1) {
            s = fn_801D68C4(lbl_80347628, 0x3a);
            fn_801D5340(s, 0, 0, -1.09f, 0.0f, 1.0f, 1.0f);
            s = fn_801D68C4(lbl_80347628, 0x3c);
            fn_801D5340(s, 0, 1, -1.08f, 0.0f, 1.0f, 1.0f);
            s = fn_801D68C4(lbl_80347628, 0x3d);
            fn_801D5340(s, 0, 1, -1.07f, 0.0f, 1.0f, lbl_80346AF4);
        }
    }
    if (lbl_80346AF0 == 1) {
        p = t->tab[0];
        if (t->work->arg->cursor > 2) {
            p->y = -108.0f + fn_801D68C4(lbl_80347628, 0x3b)->y;
        } else {
            p->y = fn_801D68C4(lbl_80347628, 0x3b)->y;
        }
        fn_801D5340(p, 0, 0, -1.0500001f, 0.0f, 1.0f, 1.0f);
        savez2 = TextGetZ();
        TextSetZ(-1.0499f);
        lbl_80346AE8 = t->work->arg->rows[t->work->arg->cursor].help;
        if (t->work->arg->cursor > 2) {
            TextPrint(lbl_80346AFC, -108.0f + lbl_80346AFA, lbl_80346AE8);
        } else {
            TextPrint(lbl_80346AFC, lbl_80346AFA, lbl_80346AE8);
        }
        TextSetZ(savez2);
    }
}

s32 fn_80020FF0(s32 idx) {
    s32 r = 0;
    if (idx != 0) {
        s8 i;
        for (i = 0; i < 4; i++) {
            switch (lbl_8030B7F4.party[i]) {
            case 0:
                r |= 0x1;
                break;
            case 1:
                r |= 0x2;
                break;
            case 2:
                r |= 0x4;
                break;
            case 3:
                r |= 0x8;
                break;
            case 4:
                r |= 0x10;
                break;
            case 5:
                r |= 0x20;
                break;
            }
        }
        return r;
    }
    if (fn_800176DC(0) >= 0) r |= 0x1;
    if (fn_800176DC(1) >= 0) r |= 0x2;
    if (fn_800176DC(3) >= 0) r |= 0x8;
    if (fn_800176DC(4) >= 0) r |= 0x10;
    if (fn_800176DC(5) >= 0) r |= 0x20;
    return r;
}

s32 fn_80028B90(void)
{
    Rec28B90 *r;
    s32 c;
    switch (lbl_8034733C) {
    case 1:
        return 0;
    case 4:
        r = fn_800786C0();
        if (r == NULL) {
            lbl_80346B78 = 0;
            return 1;
        }
        c = ++lbl_80346B78;
        if (r->kind == 1) {
            switch (r->s4) {
            case 9:
                if (c >= 0 && c < 0x27) {
                    return 3;
                } else if (c >= 0x27 && c < 0x4e) {
                    return 2;
                } else {
                    return 2;
                }
            case 13:
                switch (lbl_802C7C34[r->s6].f12) {
                case 0x22:
                case 0x23:
                    if (c >= 0 && c < 0x27) {
                        return 3;
                    } else if (c >= 0x27 && c < 0x4e) {
                        return 2;
                    } else {
                        return 2;
                    }
                default:
                    if (lbl_80346B78 >= 0 && lbl_80346B78 < 0x4e) {
                        return 3;
                    } else {
                        return 3;
                    }
                }
            case 12:
                switch (lbl_802C4BF0[r->s6].f15) {
                case 0x29:
                    if (c >= 0 && c < 0x27) {
                        return 3;
                    } else if (c >= 0x27 && c < 0x75) {
                        return 3;
                    } else {
                        return 2;
                    }
                default:
                    if (c >= 0 && c < 0x27) {
                        return 2;
                    } else if (c >= 0x27 && c < 0x4e) {
                        return 4;
                    } else {
                        return 3;
                    }
                }
            default:
                if (lbl_80346B78 >= 0 && lbl_80346B78 < 0x27) {
                    return 2;
                } else if (lbl_80346B78 >= 0x27 && lbl_80346B78 < 0x4e) {
                    return 4;
                } else {
                    return 3;
                }
            }
        } else {
            if (c >= 0 && c < 0x4e) {
                return 3;
            } else {
                return 3;
            }
        }
    default:
        return 1;
    }
}


/* Passes cmd/arg to fn_80020250 for the task of kind id (or kind 0's when there is none). */
s32 fn_800214FC(s8 id, s16 cmd, s32 arg)
{
    return fn_80020250(F2(id), cmd, arg);
}

extern f32 lbl_80302A1C[7];
extern s32 lbl_80346B50;
extern f32 lbl_80346B54;

s32 fn_80026FEC(RingTask* t, s32* state)
{
    s32 done = 0;
    s32 i;
    switch (*state) {
    case 0:
        lbl_80346B50 = 0;
        for (i = 0; i < 7; i++)
            fn_801D4954(t->mdl[i]);
        t->mdl[0] = RING_LOAD(0xd);
        t->mdl[1] = RING_LOAD(0xf);
        t->mdl[2] = RING_LOAD(0x11);
        t->mdl[3] = RING_LOAD(0xb);
        t->mdl[4] = RING_LOAD(0xc);
        t->mdl[5] = RING_LOAD(0xe);
        t->mdl[6] = RING_LOAD(0x10);
        lbl_80346B54 = 0.0f;
        *state = 1;
        break;
    case 1:
        fn_801D4954(t->mdl[6]);
        t->mdl[6] = RING_LOAD(0x13);
        *state = 2;
        lbl_80346B54 += 0.1f;
        break;
    case 2:
        fn_801D4954(t->mdl[6]);
        t->mdl[6] = RING_LOAD(0x14);
        lbl_80346B50++;
        if (lbl_80346B50 > 10)
            *state = 4;
        else
            *state = 3;
        lbl_80346B54 += 0.1f;
        break;
    case 3:
        fn_801D4954(t->mdl[6]);
        t->mdl[6] = RING_LOAD(8);
        t->mdl[6]->x = fn_801D68C4(lbl_80347628, 0x10)->x;
        t->mdl[6]->y = fn_801D68C4(lbl_80347628, 0x10)->y;
        *state = 1;
        lbl_80346B54 += 0.1f;
        break;
    case 4:
        SePlay(0, 7, 0x35);
        fn_801D4954(t->mdl[6]);
        t->mdl[6] = RING_LOAD(0x12);
        fn_801D4954(t->mdl[13]);
        t->mdl[13] = RING_LOAD(0x39);
        done = 1;
        lbl_80346B54 += 0.1f;
        break;
    default:
        done = 1;
        break;
    }
    fn_800277F4(t->mdl, t->holder->menu->count, lbl_80302A1C);
    for (i = 0; i < 7; i++) {
        Sprite* sp = t->mdl[i];
        if (t->holder->menu->avail[i] == 0)
            fn_801D5340(sp, 0, 0, RING_Z(i), lbl_80302A1C[i], 0.5f, 1.0f);
        else
            fn_801D5340(sp, 0, 0, RING_Z(i), lbl_80302A1C[i], 1.0f, 1.0f);
    }
    fn_801D5340(t->mdl[20], 0, 0, -1.1880001f, 0.0f, 1.0f, 1.0f);
    fn_801D5340(t->mdl[21], 0, 0, -1.1880001f, 0.0f, 1.0f, 1.0f);
    fn_801D5340(t->mdl[19], 0, 0, RING_Z(i), 0.0f, 1.0f, 1.0f);
    fn_801D5340(t->mdl[18], 0, 0, RING_Z(i + 1), 0.0f, 1.0f, 1.0f);
    return done;
}

void fn_80027484(Sprite** objs, s32 count, s32 mode)
{
    f32 buf[8];
    s32 i;
    switch (mode) {
    case 0:
        break;
    case 1:
        for (i = 0; i < count; i++) {
            fn_801D4954(objs[i]);
            objs[i] = 0;
            objs[i] = fn_801D497C(fn_801D68C4(lbl_80347628, 0x13));
        }
        fn_800277F4(objs, count, buf);
        for (i = 0; i < 7; i++) {
            fn_801D5340(objs[i], 0, 0, 0.001f * i + -1.2f, 0.0f, 1.0f, 1.0f);
        }
        fn_801D5340(objs[20], 0, 0, -1.1880001f, 0.0f, 1.0f, 1.0f);
        fn_801D5340(objs[21], 0, 0, -1.1880001f, 0.0f, 1.0f, 1.0f);
        fn_801D5340(objs[19], 0, 0, 0.001f * i + -1.2f, 0.0f, 1.0f, 1.0f);
        fn_801D5340(objs[18], 0, 0, 0.001f * (i + 1) + -1.2f, 0.0f, 1.0f, 1.0f);
        break;
    case 2:
        for (i = 0; i < count; i++) {
            fn_801D4954(objs[i]);
            objs[i] = 0;
            objs[i] = fn_801D497C(fn_801D68C4(lbl_80347628, 0x14));
        }
        fn_800277F4(objs, count, buf);
        for (i = 0; i < 7; i++) {
            fn_801D5340(objs[i], 0, 0, 0.001f * i + -1.2f, 0.0f, 1.0f, 1.0f);
        }
        fn_801D5340(objs[20], 0, 0, -1.1880001f, 0.0f, 1.0f, 1.0f);
        fn_801D5340(objs[21], 0, 0, -1.1880001f, 0.0f, 1.0f, 1.0f);
        fn_801D5340(objs[19], 0, 0, 0.001f * i + -1.2f, 0.0f, 1.0f, 1.0f);
        fn_801D5340(objs[18], 0, 0, 0.001f * (i + 1) + -1.2f, 0.0f, 1.0f, 1.0f);
        break;
    case 3:
        break;
    }
}

/* Sets the ring: places the n sprites around the circle, then turns them; out gets each item's angle. */
#define ANG(d) ((s32)(182.04445f * (d)))

void fn_800277F4(Sprite** objs, s32 count, f32* out)
{
    NJS_MATRIX m;
    NJS_VECTOR in;
    NJS_VECTOR res;
    NJS_VECTOR axis;
    s32 i, j, k;

    axis.x = 0.0f;
    axis.y = 0.0f;
    axis.z = 1.0f;
    for (i = 0; i < count; i++) {
        in.x = 67.0f;
        in.y = -46.0f;
        in.z = 0.0f;
        njUnitMatrix(m);
        njRotate(m, &axis, ANG(-30.0f * i));
        njCalcPoint(m, &in, &res);
        objs[i]->x = (res.x - in.x) + fn_801D68C4(lbl_80347628, 11)->x;
        objs[i]->y = (res.y - in.y) + fn_801D68C4(lbl_80347628, 11)->y;
    }
    for (k = 0; k < 7; k++) {
        out[k] = ANG(-180 * k);
    }
    for (j = 0; j < 3; j++) {
        axis.x = 0.0f;
        axis.y = 0.0f;
        axis.z = 1.0f;
        for (i = 0; i < count; i++) {
            in.x = (19.0f + objs[i]->x) - 102.0f;
            in.y = (19.0f + objs[i]->y) - 381.0f;
            in.z = 0.0f;
            njUnitMatrix(m);
            njRotate(m, &axis, 0x1555);
            njCalcPoint(m, &in, &res);
            objs[i]->x = 102.0f + (res.x - 19.0f);
            objs[i]->y = 381.0f + (res.y - 19.0f);
        }
        for (k = 0; k < 7; k++) {
            out[k] = ANG(-180 * (k + 1));
        }
    }
}

extern void fn_8000FBA8(Tsk* t);

/* Removes t from the character task table, shifting the later entries down. */
void fn_80020D50(Tsk* t) {
    s8 i;
    s8 j;

    fn_8000FBA8(t);
    for (i = 0; i < 14; i++) {
        if (lbl_80309E24[i] == t) {
            lbl_80309E24[i] = NULL;
            for (j = i; j < 11; j++) {
                lbl_80309E24[j] = lbl_80309E24[j + 1];
            }
            if (i < 12) {
                lbl_80309E24[j] = NULL;
            }
        }
    }
}

void fn_80022B04(Tk* t)
{
    f32 y;
    s32 j;

    switch (t->state) {
    case 0:
    case 0xfe:
        lbl_80346AC4 = 0.0f;
        lbl_80346AC8 = 1;
        t->x28 = fn_801E1C7C(0x38);
        t->x28[0] = fn_801D497C(fn_801D68C4(lbl_80347628, 0x5f));
        t->x28[1] = fn_801D497C(fn_801D68C4(lbl_80347628, 0x60));
        t->x28[3] = fn_801D497C(fn_801D68C4(lbl_80347628, 0x62));
        t->x28[4] = fn_801D497C(fn_801D68C4(lbl_80347628, 0x63));
        t->x28[2] = fn_801D497C(fn_801D68C4(lbl_80347628, 0x61));
        t->x28[5] = fn_801D497C(fn_801D68C4(lbl_80347628, 0x64));
        t->x28[6] = fn_801D497C(fn_801D68C4(lbl_80347628, 0x65));
        t->x28[7] = fn_801D497C(fn_801D68C4(lbl_80347628, 0x60));
        t->x28[9] = fn_801D497C(fn_801D68C4(lbl_80347628, 0x62));
        t->x28[10] = fn_801D497C(fn_801D68C4(lbl_80347628, 0x63));
        t->x28[8] = fn_801D497C(fn_801D68C4(lbl_80347628, 0x61));
        t->x28[11] = fn_801D497C(fn_801D68C4(lbl_80347628, 0x64));
        t->x28[12] = fn_801D497C(fn_801D68C4(lbl_80347628, 0x65));
        t->x28[13] = fn_801D497C(fn_801D68C4(lbl_80347628, 0x66));
        t->state = 1;
        t->x20 = -1.3f;
        break;
    case 1:
        if (lbl_80346AC4 > 1.0 || 0.0 > lbl_80346AC4) {
            lbl_80346AC8 *= -1;
        }
        y = -1.1003001f;
        lbl_80346AC4 = lbl_80346AC4 + lbl_80346AC8 / 15.0f;
        fn_801D5340(t->x28[0], 0, 0, y, 0.0f, 1.0f, 1.0f);
        y += 0.0001f;
        for (j = 0; j < 6; j++) {
            if (t->work->x0->x2 & (1 << j)) {
                fn_801D5340(t->x28[j + 1], 0, 0, y, 0.0f, 1.0f, 1.0f);
                fn_801D5340(t->x28[j + 7], 0, 0, y, 0.0f, j == t->work->x0->x1 ? 1.0f : 0.5f, 1.0f);
            }
        }
        y += 0.0001f;
        t->x28[13]->x = t->work->x0->x1 * 0x18 + fn_801D68C4(lbl_80347628, 0x66)->x;
        fn_801D5340(t->x28[13], 0, 1, y, 0.0f, 1.0f, lbl_80346AC4);
        break;
    case 2:
        for (j = 0; j < 14; j++) {
            fn_801D4954(t->x28[j]);
            t->x28[j] = 0;
        }
        t->state = 0xff;
        break;
    case 0xff:
        t->flags |= 0x40;
        break;
    }
}
