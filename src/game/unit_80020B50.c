#include "types.h"
#include "ninja.h"
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
typedef struct Ent { u32 w0; u32 w4; u8 pad[0x3c-8]; u16 h3c; u16 h3e; u8 pad2[0x44-0x40]; u16 h44; u8 pad3[0x6e-0x46]; u16 h6e; } Ent;
extern Ent *lbl_80302AB0[];
extern Ob* lbl_80346BAC;
extern void fn_8000A38C(void);
typedef struct {
    u8 pad[0x14];
    f32 x14;
    f32 x18;
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
