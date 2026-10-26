

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
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
extern void *lbl_8034731C;
void fn_80027C04(void);
void fn_8000A3A4(void *p);
typedef struct Ent { u32 w0; u32 w4; u8 pad[0x3c-8]; u16 h3c; u16 h3e; u8 pad2[0x44-0x40]; u16 h44; u8 pad3[0x6e-0x46]; u16 h6e; } Ent;
extern Ent *lbl_80302AB0[];

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

void fn_80022AAC(void *p) {
  lbl_80346BA0 = fn_802268E8(lbl_803475A8, fn_80022B04);
  ((Holder *)lbl_80346BA0)->ptr = fn_801E1C7C(4);
  *(void **)((Holder *)lbl_80346BA0)->ptr = p;
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
