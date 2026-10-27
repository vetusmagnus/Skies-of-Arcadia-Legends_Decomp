#include "types.h"
#include "ninja.h"
#include "game/task.h"
#include <math.h>
typedef struct Inner { u8 pad0[0x6]; s16 f6; s16 f8; u8 pad1[0xa]; s16 f14; s16 f16; u8 pad2[0x68-0x18]; float f68; u8 pad3[0xec-0x6c]; u32 fec; u32 ff0; } Inner;
typedef struct Mid { u8 pad[0x4c]; Inner *inner; } Mid;
typedef struct Top { u8 pad[0x24]; Mid *mid; } Top;
void fn_8002E5D0(Top *t);
extern void *lbl_803475A8;
extern void *lbl_80346BA0;
typedef struct Holder { u8 pad[0x24]; void *ptr; } Holder;
void *fn_802268E8(void *a, void (*b)(void));
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
    u8 pad_18[0x24];
    u16 h3c;
    u16 h3e;
    u8 pad_40[0x4];
    s16 h44;
    s16 h46;
    s16 h48;
    u8 pad_4a[0xe];
    f32 f58;
    f32 f5c;
    u8 pad_60[0xe];
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
    u8 pad0[0x14];
    s32 s14;
    s32 s18;
    u8 pad1c[0x100 - 0x1c];
    s8 kind;
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
extern char* fn_8025F120(char* dst, const char* src);
extern char* fn_8025F0B0(char* dst, const char* src);
extern int fn_8025CB24(char*, const char*, ...);
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
extern void fn_80299040(void* p);
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
extern void fn_80022F74(void);
void fn_80022F1C(void *p) {
  lbl_80346BA4 = fn_802268E8(lbl_803475A8, fn_80022F74);
  ((Holder *)lbl_80346BA4)->ptr = fn_801E1C7C(4);
  *(void **)((Holder *)lbl_80346BA4)->ptr = p;
}

void fn_80023D04(void) {
    ((u8*)lbl_80346BA8)[0x19] = 2;
}

extern void fn_800240EC(void);
void fn_80023D14(void *p) {
  lbl_80346BA8 = fn_802268E8(lbl_803475A8, fn_800240EC);
  ((Holder *)lbl_80346BA8)->ptr = fn_801E1C7C(4);
  *(void **)((Holder *)lbl_80346BA8)->ptr = p;
}

extern void fn_80025624(void);
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
        w->s28 = lbl_80309DE4[id]->s14;
        w->f20 = (f32)lbl_80309DE4[id]->s14;
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

extern void fn_801D68C4(s32 a, s32 b);
extern s32 lbl_8034762C;

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
            fn_8025F120(buf10, name);
            fn_80061048(buf10);
            if (path[0] != '/') {
                fn_8025F120(buf50, "/");
                fn_8025F0B0(buf50, path);
                fn_8025F0B0(buf50, buf10);
                fn_8025F0B0(buf50, ".STD");
            } else {
                fn_8025CB24(buf50, "%s%s.STD", path, buf10);
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
            fn_8025F0B0(buf10, "0.STD");
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
