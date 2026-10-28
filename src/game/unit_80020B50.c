#include "types.h"
#include "ninja.h"
#include "game/task.h"
#include "game/save_8030B7F4.h"
#include "game/sprite.h"
#include <math.h>
/* The argument block fn_80023D14 hands the task: a vertical list with a cursor. */
typedef struct ListArg {
    s8 count;   /* 0x00 */
    s8 kind;    /* 0x01: which list (picks the sprites) */
    u8 pad2;
    s8 cursor;  /* 0x03 */
    u8 pad4[2];
    s8 input;   /* 0x06: 0 none, 1 up, 2 down */
    u8 flags;   /* 0x07: 1 input pending, 2 x */
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
typedef struct StArg {
    s8 x0;
} StArg;
typedef struct StHolder {
    StArg* arg;
} StHolder;
/* The task fn_80022F1C creates. */
typedef struct StTask {
    Task task;
    void** tab; /* 0x28: 28 model pointers per party member */
} StTask;
typedef struct Inner { u8 pad0[0x6]; s16 f6; s16 f8; u8 pad1[0xa]; s16 f14; s16 f16; u8 pad2[0x68-0x18]; float f68; u8 pad3[0xec-0x6c]; u32 fec; u32 ff0; } Inner;
typedef struct Mid { u8 pad[0x4c]; Inner *inner; } Mid;
typedef struct Top { u8 pad[0x24]; Mid *mid; } Top;
void fn_8002E5D0(Top *t);
extern void *lbl_803475A8;
extern void *lbl_80346BA0;
typedef struct Holder { u8 pad[0x24]; void *ptr; } Holder;
void *fn_802268E8(void *a, void *b);
void *fn_801E1C7C(s32 n);
void fn_80022B04(void);
extern void *lbl_80346AA0;
typedef struct Ob { u8 pad[0x19]; u8 mode; } Ob;
extern Ob* lbl_8034731C;
void fn_80027C04(void);
void fn_8000A3A4(void *p);
typedef struct Ent {
    u32 w0;
    s32 w4;
    s32 w8;
    u8 pad_c[0x6];
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
    u8 pad_4a[0xe];
    f32 f58;
    f32 f5c;
    u8 pad_60[0xc];
    s16 x6c;
    s16 h6e;
    s16 s70;
    u8 pad_72[0x17c];
    s16 x1ee;
    u8 pad_1f0[0x4];
    Ob* x1f4;
} Ent;
extern Ent *lbl_80302AB0[];
extern Ob* lbl_80346BAC;
extern void fn_8000A38C(void);
typedef struct {
    u8 pad_0[0x4];
    s32 w4;
    u8 pad_8[0x8];
    s16 s10;
    s16 s12;
    f32 x14;
    f32 x18;
    u8 pad_1c[0x3c];
    f32 f58;
    f32 f5c;
    u8 pad_60[0x4];
    f32 f64;
    u8 pad_68[0x8];
    s16 s70;
} Obj;
extern Obj* fn_80023FEC(s16);
extern void fn_801D52F4(Obj*, f32, f32, f32, f32, int, int);
typedef struct HudEnt {
    u8 pad_0[0x14];
    s32 x14;
    s32 s18;
    u8 pad_1c[0xe4];
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
extern f32 fn_800177C0(s32, void*);
extern s32 fn_80015B94(s32, void*);
extern s32 fn_80020FF0(s32 idx);
extern s32 lbl_80302A38[6];
extern void fn_80028E28(s32 *p);
typedef struct Ent80025518 {
    u8 pad0[0x4];
    s32 *out_ptr;
} Ent80025518;
extern s32 lbl_8034732C;
typedef struct Dat {
    u8 pad_00[4];
    u8 x4;
    u8 pad_05;
    s16 x6;
    s16 x8;
    u8 pad_0a[8];
    s16 x12;
    u8 pad_14[4];
    s16 x18;
    s16 x1a;
    s16 x1c;
    u8 pad_1e[0xe4 - 0x1e];
    s16 xe4;
    s16 xe6_pad;
    s16 xe8;
    u8 pad_ea[2];
    u32 xec;
    u8 pad_f0[0x134 - 0xf0];
    s32 x134;
} Dat;
typedef struct Wk { u8 pad_00[0x4c]; Dat *x4c; } Wk;
typedef struct Tsk { u8 pad_00[0x24]; Wk *work; } Tsk;
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
typedef struct D21 { s8 kind; } D21;
typedef struct W21 { u8 pad00[0x4c]; D21 *d; } W21;
typedef struct T21 { u8 pad00[0x24]; W21 *work; } T21;
extern T21 *lbl_80309E24[14];
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
extern void fn_8002356C(StArg* arg, void** tab, s8 a, s8 b);
extern s8 lbl_80346AC0;
extern s32 lbl_80346AD8;
extern s32 lbl_80346AE4;
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
} Rec28B90;
typedef struct Item36 { u8 pad0[0x12]; s8 f12; u8 pad13[0x24 - 0x13]; } Item36;
typedef struct Item48 { u8 pad0[0x15]; s8 f15; u8 pad16[0x30 - 0x16]; } Item48;
extern s32 lbl_8034733C;
extern s32 lbl_80346B78;
extern Item36 lbl_802C7C34[];
extern Item48 lbl_802C4BF0[];
extern Rec28B90 *fn_800786C0(void);

void fn_80020B50(Top *t, s16 *out1, s16 *out2) {
  Inner *i = t->mid->inner;
  if (i->fec & 0x8000) {
    *out1 = i->f14;
    *out2 = i->f16;
  } else {
    *out1 = i->f6;
    *out2 = i->f8;
  }
}

void fn_80021784(Top *t) {
  Mid *m = t->mid;
  Inner *i = m->inner;
  if (i->fec & 0x8000) {
    i->fec = i->fec & ~0x8000;
    i->f6 = i->f14;
    i->f8 = i->f16;
  }
  fn_8002E5D0(t);
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
    Obj* o = fn_80023FEC(d);
    o->x14 = off + x;
    o->x18 = y;
    fn_801D52F4(o, -1.1999f, 0.0f, 1.0f, 1.0f, 0, 0);
}

inline void Draw0(s16 d, f32 x, f32 y)
{
    Obj* o = fn_80023FEC(d);
    o->x14 = x;
    o->x18 = y;
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
    fn_80028E28(lbl_80302A38);
}

void fn_80028E0C(void)
{
    if (lbl_80302A38[0] == 1) {
        lbl_80302A38[0] = 2;
    }
}

void fn_80025518(Ent80025518 *self)
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
    *(s32 *)((u8 *)self->out_ptr + 0x14) = v;
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

Obj* fn_80023FEC(s16 a) {
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

void fn_80029980(Obj* p) {
    s32 i;
    f32 dx;
    f32 dz;

    if (p->s12 != 2 && p->w4 == 1) {
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

static inline T21 *Find21(s8 id)
{
    s8 i;
    for (i = 0; i < 14; i++) {
        T21 *t = lbl_80309E24[i];
        if (t != NULL && t->work->d->kind == id) {
            return lbl_80309E24[i];
        }
    }
    return NULL;
}
T21 *fn_80021658(s8 id)
{
    T21 *r = Find21(id);
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
