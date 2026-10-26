#include "types.h"

extern s16 lbl_803097F0[];
extern u32 lbl_802B0830[];
typedef struct ChrState {
    s32 x0;
    u8 pad[0x1c];
} ChrState;
extern s32 lbl_80347330;
extern ChrState lbl_80309174[12];
extern s8 lbl_802AD440[];
extern s8 lbl_802C7C34[];
extern s8 lbl_802C4BF0[];
extern void fn_8006B774(void* p);
typedef struct Req {
    s16 idx;
    u8 pad0[2];
    u32 flags;
    u8 pad1[0x34];
    s32 x3c;
    u8 pad2[0x10];
    u8 f50;
} Req;
typedef struct Slot {
    void (*update)(void);
    u8 pad1[0x15];
    u8 flag19;
    u8 pad2[0x0a];
    Req *req;
} Slot;
extern Slot *lbl_80309700[12];
extern u8* fn_80021658(s32 i);
extern s16 lbl_80302BF0[];
extern void fn_80081FEC(s32 i);
extern s8 lbl_80347334;
extern s32 fn_80083BAC(s32 a, s32 b);
typedef struct Chr_UNIT0000 {
    u8 pad[0x10];
    u32 x10;
    s32 score;
    u8 pad2[0x4];
    u32 w1c;
} Chr_UNIT0000;
extern Chr_UNIT0000* lbl_80309DE4[12];
typedef struct Inner { u8 pad0[0x6]; s16 f6; s16 f8; u8 pad1[0xa]; s16 f14; s16 f16; u8 pad2[0x68-0x18]; float f68; u8 pad3[0xec-0x6c]; u32 fec; u32 ff0; } Inner;
typedef struct Mid { u8 pad[0x4c]; Inner *inner; } Mid;
typedef struct Top { u8 pad[0x24]; Mid *mid; } Top;
typedef struct Node { struct Node *next; u32 key; u8 pad[0x4]; u8 flag; } Node;
extern Node lbl_80309E14;
s32 fn_8006C9AC(s32 a, s32 b);
void fn_800763D0(s32 a, s32 b);
extern u32 lbl_80309E5C[];
typedef struct R16 { s32 w0; u8 pad[5]; u8 b9; u8 pad2[6]; } R16;
extern R16 lbl_80309730[];
typedef struct Ent { u8 pad[6]; s16 x6; u8 pad8[0x10]; } Ent;
typedef struct Unit { u8 pad0[0xdc]; Ent* xdc; u8 pade0[0x204 - 0xe0]; s16 x204; } Unit;
typedef struct Wk { u8 pad0[0x4c]; Unit* u; } Wk;
typedef struct Tk_800760EC { u8 pad0[0x24]; Wk* work; } Tk_800760EC;
s32 fn_8001FDD8(Wk* w);
typedef struct Unk30 {
    u8 pad[0x1c];
    u32 flags;
} Unk30;
extern s32 fn_80078610(s8 idx);
extern void fn_8007D42C(void);
extern void fn_8007DE54(struct Obj_8007DE54 *p);
extern void *lbl_803475A8;
extern void *lbl_8034736C;
extern void *fn_802268E8(void *, void *);
extern void fn_8007CAB0(void);
typedef struct Obj_8007DE54 {
    u8 pad[0x18];
    u8 flags18;
    u8 state;
    u8 pad2[0x0a];
    void *buf;
} Obj_8007DE54;
extern void *fn_801E1C7C(s32 size);
extern void fn_80217830(s32 arg);
typedef struct Ctx_80080438 {
    u8 pad[0x24];
    Req *req;
} Ctx_80080438;
extern s32 lbl_8034733C;
extern s32 lbl_80347348;
extern s16 lbl_80347374;
extern void fn_80080278(void);
extern void fn_800840BC(void);
extern void fn_80010CF4(void);
extern void fn_80084570(void);
extern void fn_800842A0(s32 idx);
extern s32 lbl_80347354;
extern s32 lbl_80347350;
extern u8 lbl_80347340;
typedef struct Obj_80085C88 {
    u8 pad[0x1c];
    u32 flags;
} Obj_80085C88;
typedef struct Req_80085C88 {
    s16 idx;
    u8 pad[2];
    u32 flags;
} Req_80085C88;
typedef struct Ctx_80085C88 {
    u8 pad[0x24];
    Req_80085C88 *req;
} Ctx_80085C88;
typedef struct Slot_80085C88 {
    void (*update)(void);
    u8 pad1[0x15];
    u8 flag19;
} Slot_80085C88;
extern void fn_80086C48(void);
typedef struct Obj_80089E3C {
    u8 pad[0x14];
    s32 score;
    s32 pad18;
    u32 flags;
} Obj_80089E3C;
typedef struct Obj_8008A004 {
    u8 pad[0x14];
    s32 score;
    s32 pad18;
    u32 flags;
} Obj_8008A004;
extern u8 *lbl_803472FC;
extern u8 *lbl_80347300;
extern u8 *lbl_80347304;
extern u8 *lbl_80347308;
extern u8 *lbl_8034730C;
extern u8 *lbl_80347310;
extern u8 *lbl_80347314;
extern u8 *lbl_80347318;
typedef struct { s8 x0; u8 pad1[3]; s32 x4; u8 pad8[4]; } E12;
extern E12 lbl_80302C08[12];
extern void fn_800839D8(s32 a, void *p, s32 b);
extern s32 lbl_80302C98[8];
extern s32 fn_8025ECC4(void);

void fn_80075D24(Top *t) {
  Inner *i = t->mid->inner;
  if (i->f68 == 0.0f) {
    i->ff0 |= 2;
    return;
  }
  if ((i->ff0 & 2) == 0) return;
  i->ff0 &= ~2;
}

s32 fn_80075D64(Top *t) {
  Inner *i = t->mid->inner;
  if (!(i->fec & 0x80000000)) return 1;
  if (i->f68 >= 1.0f) {
    i->fec = i->fec & 0x7fffffff;
    return 1;
  }
  return 0;
}

u32 fn_80075FCC(u8* p) {
    u8* a = *(u8**)(p + 0x24);
    u8* b = *(u8**)(a + 0x4c);
    s16 i = *(s16*)(b + 0xe4);
    u8* e = *(u8**)(b + 0xdc);
    e = e + i * 0x18;
    return (*(u32*)(e + 8) >> 19) & 1;
}

void fn_80076344(u32 key) {
  Node *p = &lbl_80309E14;
  Node *q;
  while (p->next != 0) {
    if (p->next->key == key) p->next->flag ^= 0x80;
    q = p->next;
    if (q == 0) return;
    p = q;
  }
}

void fn_8007638C(s32 a, s32 b, s32 c) {
  s32 x = fn_8006C9AC(b, c);
  fn_800763D0(a, x);
}

s32 fn_80077E34(void) {
    s16 i = lbl_803097F0[0];
    if (i == -1) {
        return -1;
    }
    return lbl_802B0830[i];
}

s32 fn_8007833C(void) {
    return lbl_80309174[lbl_80347330].x0;
}

s32 fn_80078354(s32 i) {
    return lbl_802AD440[i * 0x24 + 0x526];
}

s32 fn_80078370(s32 i) {
    return lbl_802C7C34[i * 0x24 - 0x21ae];
}

s32 fn_8007838C(s32 i) {
    return lbl_802C4BF0[i * 0x30 + 0x15];
}

s32 fn_800785EC(u8* p) {
    if (p != 0) {
        if ((*(u32*)(p + 0x1c) & 0x2100) == 0) {
            return 1;
        }
    }
    return 0;
}

s32 fn_80078610(s8 idx) {
  Chr_UNIT0000 *e;
  if (idx < 0) goto zero;
  if (idx > 11) goto zero;
  e = lbl_80309DE4[idx];
  if (e == 0) goto zero;
  if (e->w1c & 0x2100) goto zero;
  return 1;
zero:
  return 0;
}

s32 fn_800786B0(s16* a, s16* b) {
    s16 bv = b[1];
    return a[1] - bv;
}

void fn_8007D318(u8* p) {
    if (p == 0) {
        return;
    }
    p[0x19] = 7;
}

void fn_8007E118(u8* p) {
    fn_8006B774(*(void**)(p + 0xc));
}

s32 fn_8007E264(f32* p) {
    *p = 0.0f;
    return 1;
}

void fn_8007E414(s32 on) {
  if (on) {
    lbl_80309E5C[2] |= 0x04000000;
  } else {
    lbl_80309E5C[2] &= ~0x04000000;
  }
}

void fn_8007E678(s32 a, u32* b) {
    b[0] |= 0x800;
    b[2] = 0x800;
}

s32 fn_8007EB74(s32 i) {
    s32 r = 0;
    Slot* t = lbl_80309700[i];
    if (t != 0) {
        r = t->req->x3c;
    }
    return r;
}

s16 fn_8007FCF0(s8 i) {
    u8* a = fn_80021658(i);
    u8* b = *(u8**)(*(u8**)(a + 0x24) + 0x4c);
    return *(s16*)(b + 6);
}

void fn_800810FC(s16 idx) {
  lbl_80309730[idx].w0 = 4;
  lbl_80309730[idx].b9 = 0;
  lbl_80302BF0[idx] = 0;
}

void fn_80081134(s16 i, u32 v) {
    s32 off = i * 16;
    *(u32*)((u8*)lbl_80309730 + off) = v;
    ((u8*)lbl_80309730 + off)[9] = 0;
    lbl_80302BF0[i] = 0;
}

void fn_8008210C(void) {
    fn_80081FEC(lbl_80347334);
}

void fn_8008999C(void* a) {
    fn_80083BAC((s32)a, 3);
}

s32 fn_8008A880(s32 i) {
    Chr_UNIT0000* e = lbl_80309DE4[i];
    u32 f = e->x10;
    if (f & 0x20000) {
        e->x10 = f & ~0x20000;
        return 1;
    }
    return 0;
}

s16 fn_800760EC(Tk_800760EC* t, s16 k) {
    Wk* w = t->work;
    Unit* u = w->u;
    s32 idx = fn_8001FDD8(w);
    if (k == 2 || k == 7) {
        s16 j = u->x204;
        if (j != 0) {
            return u->xdc[j].x6;
        }
    }
    return u->xdc[(s16)idx].x6;
}

s32 fn_80077CCC(void) {
    s32 i;
    for (i = 0; i <= 3; i++) {
        if (fn_80078610(i) && (lbl_80309DE4[i]->w1c & 0x10000)) {
            return 1;
        }
    }
    return 0;
}

void fn_80078658(s32 mode) {
    if (mode == 1) {
        lbl_8034736C = (void *)fn_802268E8(lbl_803475A8, (void *)fn_8007D42C);
    } else if (mode == 0) {
        lbl_8034736C = (void *)fn_802268E8(lbl_803475A8, (void *)fn_8007DE54);
    }
}

void fn_8007D3D0(void) {
    lbl_80347318 = fn_802268E8(lbl_803475A8, fn_8007CAB0);
    if (lbl_80347318 == 0) {
        for (;;) {
        }
    }
    lbl_80347314 = 0;
    lbl_80347308 = 0;
    lbl_80347304 = 0;
    lbl_803472FC = 0;
    lbl_80347310 = 0;
    lbl_8034730C = 0;
    lbl_80347300 = 0;
}

void fn_8007DE54(Obj_8007DE54 *p) {
    switch (p->state) {
    case 0:
        p->buf = fn_801E1C7C(4);
        p->state = 1;
    case 1:
        p->state = 2;
        break;
    case 0xff:
        fn_80217830(1);
        p->flags18 |= 0x40;
        lbl_8034736C = 0;
        break;
    }
}

s32 fn_80080438(Ctx_80080438 *p) {
    s32 mode = lbl_8034733C;
    s32 idx = p->req->idx;
    if (((u32)(mode - 5) <= 1) || mode == 3 || lbl_80347348 == 1) {
        lbl_80347374 = lbl_80347374 & ~(1 << idx);
        lbl_80309700[idx]->update = fn_80080278;
        lbl_80309700[idx]->flag19 = 0;
        p->req->f50 = 0;
        return 1;
    }
    return 0;
}

void fn_80081168(s16 idx, s32 val) {
    Req *req = lbl_80309700[idx]->req;
    if (req->flags & 0x20) {
        req->flags &= ~0x20;
        lbl_80309730[idx].w0 = 0x12;
    }
    if (lbl_80309730[idx].w0 != val) {
        lbl_80309730[idx].w0 = val;
        lbl_80309730[idx].b9 = 0;
        lbl_80302BF0[idx] = 0;
    }
}

void fn_800849A8(void) {
    s32 i;
    lbl_80347354 = 0;
    lbl_80347350 = 0;
    fn_800840BC();
    fn_80010CF4();
    fn_80084570();
    i = 0;
    do {
        fn_800842A0(i);
        i++;
    } while ((s16)i < 12);
    lbl_80347340 = 1;
}

void fn_80085C88(Ctx_80085C88 *c) {
    Req_80085C88 *req = c->req;
    void (*fp)(void) = fn_80086C48;
    s16 idx = req->idx;
    Chr_UNIT0000 *o = lbl_80309DE4[idx];
    o->w1c |= 1;
    req->flags |= 1;
    lbl_80309700[idx]->update = fp;
    lbl_80309700[idx]->flag19 = 0;
}

s32 fn_80089E3C(void) {
    s32 i;
    s32 best;
    s32 bestScore = 0;
    for (i = 4; i <= 11; i++) {
        if (fn_80078610(i)) {
            if (bestScore < lbl_80309DE4[i]->score) {
                best = i;
                bestScore = lbl_80309DE4[i]->score;
            }
        }
    }
    return best;
}

s32 fn_8008A004(void) {
    s32 i;
    s32 best;
    s32 bestScore = 0;
    for (i = 0; i <= 3; i++) {
        if (fn_80078610(i)) {
            if (bestScore < lbl_80309DE4[i]->score) {
                best = i;
                bestScore = lbl_80309DE4[i]->score;
            }
        }
    }
    return best;
}

void fn_8007D32C(void)
{
    if (lbl_80347318 != 0) {
        lbl_80347318[0x19] = 7;
    }
    if (lbl_80347314 != 0) {
        lbl_80347314[0x19] = 7;
    }
    if (lbl_80347310 != 0) {
        lbl_80347310[0x19] = 7;
    }
    if (lbl_8034730C != 0) {
        lbl_8034730C[0x19] = 7;
    }
    if (lbl_80347308 != 0) {
        lbl_80347308[0x19] = 7;
    }
    if (lbl_80347304 != 0) {
        lbl_80347304[0x19] = 7;
    }
    if (lbl_80347300 != 0) {
        lbl_80347300[0x19] = 7;
    }
    if (lbl_803472FC != 0) {
        lbl_803472FC[0x19] = 7;
    }
}

s32 fn_80083BAC(s32 a, s32 b) {
    lbl_80302C08[0].x4 = 0x7f;
    lbl_80302C08[0].x0 = -1;
    lbl_80302C08[1].x4 = 0x7f;
    lbl_80302C08[1].x0 = -1;
    lbl_80302C08[2].x4 = 0x7f;
    lbl_80302C08[2].x0 = -1;
    lbl_80302C08[3].x4 = 0x7f;
    lbl_80302C08[3].x0 = -1;
    lbl_80302C08[4].x4 = 0x7f;
    lbl_80302C08[4].x0 = -1;
    lbl_80302C08[5].x4 = 0x7f;
    lbl_80302C08[5].x0 = -1;
    lbl_80302C08[6].x4 = 0x7f;
    lbl_80302C08[6].x0 = -1;
    lbl_80302C08[7].x4 = 0x7f;
    lbl_80302C08[7].x0 = -1;
    lbl_80302C08[8].x4 = 0x7f;
    lbl_80302C08[8].x0 = -1;
    lbl_80302C08[9].x4 = 0x7f;
    lbl_80302C08[9].x0 = -1;
    lbl_80302C08[10].x4 = 0x7f;
    lbl_80302C08[10].x0 = -1;
    lbl_80302C08[11].x4 = 0x7f;
    lbl_80302C08[11].x0 = -1;
    fn_800839D8(a, lbl_80302C08, b);
    return lbl_80302C08[0].x0;
}

s32 fn_80089DAC(void) {
    s32 i;
    s32 idx;
    s32 best;
    best = 0x1869F;
    for (i = 4; i <= 11; i++) {
        if (fn_80078610(i)) {
            if (best > lbl_80309DE4[i]->score) {
                idx = i;
                best = lbl_80309DE4[i]->score;
            }
        }
    }
    return idx;
}

s32 fn_80089EC8(s32 a) {
    s32 *out;
    s32 i;
    s32 n;
    out = lbl_80302C98;
    out[0] = -1;
    out[1] = -1;
    out[2] = -1;
    out[3] = -1;
    out[4] = -1;
    out[5] = -1;
    out[6] = -1;
    out[7] = -1;
    n = 0;
    for (i = 4; i <= 11; i++) {
        if (fn_80078610(i)) {
            out[n] = i;
            n++;
        }
    }
    return lbl_80302C98[fn_8025ECC4() % n];
}

s32 fn_80089F78(void) {
    s32 i;
    s32 idx;
    s32 best;
    best = 0x1869F;
    for (i = 0; i <= 3; i++) {
        if (fn_80078610(i)) {
            if (best > lbl_80309DE4[i]->score) {
                idx = i;
                best = lbl_80309DE4[i]->score;
            }
        }
    }
    return idx;
}

s32 fn_8008A08C(void) {
    s32 *out;
    s32 i;
    s32 n;
    out = lbl_80302C98;
    out[0] = -1;
    out[1] = -1;
    out[2] = -1;
    out[3] = -1;
    n = 0;
    for (i = 0; i <= 3; i++) {
        if (fn_80078610(i)) {
            out[n] = i;
            n++;
        }
    }
    return lbl_80302C98[fn_8025ECC4() % n];
}
