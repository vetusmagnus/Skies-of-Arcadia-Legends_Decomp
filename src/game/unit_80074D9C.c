#include "types.h"
#include "game/drawstate.h"
#include <math.h>
extern s16 lbl_803097F0[];
extern u32 lbl_802B0830[];
extern s32 lbl_80347330;
typedef struct { s8 pad[0x16]; u8 x16; u8 pad17[0x30 - 0x17]; } T30;
typedef struct { s8 pad[0x13]; u8 x13; u8 pad14[0x24 - 0x14]; } T24c;
typedef struct { s8 pad[0x17]; u8 x17; u8 pad18[0x24 - 0x18]; } T24;
extern T24 lbl_802AD440[];
extern T24c lbl_802C7C34[];
extern T30 lbl_802C4BF0[];
extern void fn_8006B774(void* p);
extern u8* fn_80021658(s32 i);
extern s16 lbl_80302BF0[];
extern s8 lbl_80347334;
typedef struct ChrState {
    s32 x0;
    s8 x4;
    u8 pad5;
    s16 x6;
    s8 x8;
    u8 pad9[3];
    u8 xc;
    u8 xd;
    u8 pade[0x20 - 0xe];
} ChrState;
extern ChrState lbl_80309174[12];
typedef struct Req {
    s16 idx;
    u8 pad0[2];
    u32 flags;
    u8 pad1[0x34];
    s32 x3c;
    u8 pad2[0x10];
    u8 f50;
} Req;
typedef struct Sub { u32 x0; u32 x4; f32 x8; f32 xc; } Sub;
typedef struct EntU {
    union {
        struct { u8 pad0[6]; s16 x6; } a;
        struct { u8 pad0[8]; u32 flags; u8 padc[8]; f32 x14; } b;
    };
} EntU;
typedef struct Unit {
    u8 pad0[0x5c];
    u32 x5c;
    u32 x60;
    u8 pad64[4];
    f32 x68;
    f32 x6c;
    u32 x70;
    u32 x74;
    u32 x78;
    f32 x7c;
    f32 x80;
    Sub x84;
    u8 pad94[0xdc - 0x94];
    EntU* xdc;
    u8 pade0[0xe6 - 0xe0];
    s16 xe6;
    u8 padE8[0xf0 - 0xe8];
    u32 xf0;
    u8 padf4[0x204 - 0xf4];
    s16 x204;
} Unit;
typedef struct Wk {
    s16 idx;
    s16 x2;
    u32 flags;
    u8 pad8[8];
    u32 x10;
    u8 pad14[0x37 - 0x14];
    s8 x37;
    u8 pad38[4];
    s32 x3c;
    u8 pad40[4];
    s16 x44;
    s16 x46;
    s16 x48;
    s16 x4a;
    Unit* u;
    s8 x50;
} Wk;
typedef struct Slot {
    void (*update)(void);
    u8 pad1[0x15];
    u8 flag19;
    u8 pad2[0x0a];
    union {
        Req *req;
        Wk *work;
    } un;
} Slot;
extern Slot *lbl_80309700[12];
extern s32 fn_80081FEC(s16 i);
extern s32 fn_80083BAC(s32 a, s32 b);
typedef struct Stat {
    u8 pad0[0x56];
    s16 s56;
} Stat;
typedef struct Chr_UNIT0000 {
    u8 pad[0x10];
    u32 x10;
    s32 score;
    u8 pad2[0x4];
    u32 w1c;
    u8 pad20[0xae - 0x20];
    s16 xae;
    u8 padb0[4];
    s16 xb4;
    u8 padb6[4];
    s16 xba;
    u8 padbc[0x110 - 0xbc];
    Stat* p110;
} Chr_UNIT0000;
extern Chr_UNIT0000* lbl_80309DE4[12];
typedef struct Inner { u8 pad0[0x6]; s16 f6; s16 f8; u8 pad1[0xa]; s16 f14; s16 f16; u8 pad2[0x68-0x18]; float f68; u8 pad3[0xec-0x6c]; u32 fec; u32 ff0; } Inner;
typedef struct Mid { u8 pad[0x4c]; Inner *inner; } Mid;
typedef struct Top { u8 pad[0x24]; Mid *mid; } Top;
typedef struct Node { struct Node *next; u32 key; u8 pad[0x4]; u8 flag; } Node;
extern Node lbl_80309E14;
s32 fn_8006C9AC(s32 a, s32 b);
void fn_800763D0(s32 a, s32 b);
typedef struct R16 { s32 w0; s8 x4; u8 pad5; s16 x6; u8 b8; u8 b9; u8 pad2[3]; u8 xd; u8 pade[2]; } R16;
extern R16 lbl_80309730[];
extern s32 fn_8001FDD8();
extern s32 fn_80078610(s8 idx);
extern void fn_8007D42C(void);
typedef struct Obj_8007DE54 {
    u8 pad[0x18];
    u8 flags18;
    u8 state;
    u8 pad2[0x0a];
    void *buf;
} Obj_8007DE54;
extern void fn_8007DE54(Obj_8007DE54 *p);
extern void *lbl_803475A8;
extern void *lbl_8034736C;
extern void *fn_802268E8(void *, void *);
extern void fn_8007CAB0(void);
typedef struct Map_800840BC { u8 pad0[0x24]; u8* cells; } Map_800840BC;
extern void fn_802AC710(void* dst, void* src, int n);
extern void* fn_801E1C7C(int size);
extern void fn_80217830(s32 arg);
typedef struct Ctx_80080438 {
    u8 pad[0x24];
    Req *req;
} Ctx_80080438;
extern s32 lbl_8034733C;
extern s32 lbl_80347348;
extern s16 lbl_80347374;
extern void fn_800801A8(void);
typedef struct Node_80080278 { u8 pad[0x24]; s16* work; } Node_80080278;
s32 fn_80080278(Node_80080278* t);
void fn_800840BC(void);
extern void fn_80010CF4(void);
extern void fn_80084570(void);
extern void fn_800842A0(s32 idx);
extern u8* lbl_80347354;
extern void* lbl_80347350;
extern u8 lbl_80347340;
typedef struct Req_80085C88 {
    s16 idx;
    u8 pad[2];
    u32 flags;
} Req_80085C88;
typedef struct Ctx_80085C88 {
    u8 pad[0x24];
    Req_80085C88 *req;
} Ctx_80085C88;
extern void fn_80086C48();
extern u8 *lbl_803472FC;
extern u8 *lbl_80347300;
extern u8 *lbl_80347304;
extern u8 *lbl_80347308;
extern u8 *lbl_8034730C;
extern u8 *lbl_80347310;
extern u8 *lbl_80347314;
extern u8 *lbl_80347318;
typedef struct { s8 x0; u8 pad1[3]; s32 x4; s32 x8; } E12;
extern E12 lbl_80302C08[12];
extern void fn_800839D8(s32 a, void *p, s32 b);
extern s32 lbl_80302C98[8];
extern s32 fn_8025ECC4(void);
extern s32 fn_80075DAC(f32 f1, f32 f2, void* w, u16 a, u32 flags, s32 k, s32 j);
extern f32 lbl_80348A70;
typedef struct Hdr { void* x0; } Hdr;
typedef struct Rec {
    void* x0;
    u8 pad4[4];
    struct Hdr* x8;
    u8 padc[4];
    void* x10;
    u8 pad14[2];
    s16 x16;
    s16 x18;
    u8 pad1a[0x40 - 0x1a];
    void* x40;
    u8 pad44[0x4c - 0x44];
} Rec;
typedef struct Src8 { u8 pad0[8]; s32* x8; } Src8;
typedef struct Ent_8007E13C { Rec* recs; Src8* src; u8 pad8[4]; u8 count; u8 pad0d[7]; } Ent_8007E13C;
typedef struct G_8007E13C {
    u8 pad0[8];
    u32 f8;
    u8 pad0c[0x14];
    s32 idx;
    u8 pad24[4];
    Ent_8007E13C* tab;
} G_8007E13C;
typedef struct Arg { u8 pad0[0xc]; Rec* recs; } Arg;
extern G_8007E13C lbl_80309E5C;
extern void fn_8007E9E0(u8 i);
extern void fn_8002DD8C(s16 a, s32 b, s8 c);
extern s16 lbl_8034734E;
extern u8 lbl_80309300[0x400];
extern s32 fn_80082AC0(s8 x, s8 y, u8* grid, s32 k);
extern s32 fn_8008328C(void* a, void* b, s8 x, s8 y);
typedef struct Src {
    u8 pad0[0x15];
    u8 x15;
    u8 x16;
    u8 pad17[3];
    s16 x1a;
    s16 x1c;
    u8 pad1e[0x24 - 0x1E];
    s32 x24;
    f32 x28;
    s16 x2c[6];
    s16 x38[16];
    s16 x58;
    s16 x5a;
    s16 x5c[5];
    s16 x66[6];
} Src;
typedef struct Chr {
    s16 x0;
    s16 x2;
    s8 x4;
    s8 x5;
    s8 x6;
    u8 pad7;
    s16 x8;
    s16 xa;
    s16 xc;
    s16 xe;
    s32 x10;
    s32 x14;
    s32 x18;
    s32 x1c;
    s16 x20[4];
    s16 x28[6];
    s16 x34[6];
    s16 x40[16];
    s16 x60[16];
    s16 x80[5];
    s16 x8a[5];
    s16 x94[6];
    s16 xa0[6];
    s8 xac;
    s8 xad;
    s16 xae;
    f32 xb0;
    s16 xb4;
    s16 xb6;
    s8 xb8;
    s8 xb9;
    s16 xba;
    s16 xbc[6];
    s16 xc8[16];
    s16 xe8[5];
    s16 xf2[6];
    u8 padfe[0x10A - 0xFE];
    s16 x10a;
    s16 x10c;
    Src* x110;
} Chr;
typedef struct Ent {
    u8 on;      /* 0x0 */
    s8 id;      /* 0x1 */
    u8 pad2[2];
    s16 type;   /* 0x4 */
    u8 pad6[2];
    void* p;    /* 0x8 */
    u32 w;      /* 0xC */
} Ent;
typedef struct List {
    u8 count;   /* 0x0 */
    u8 x1;
    u8 x2;
    u8 pad3[3];
    u8 x6;
    u8 x7;
    Ent e[8];   /* 0x8 */
} List;
typedef struct Lim { u8 pad[8]; s16 x8; s16 xa; } Lim;
extern s8 lbl_80346C0C;
extern Lim* lbl_80347390;
extern u32 lbl_802F6918[];
typedef struct Eff {
    u8 pad0[0xC];
    f32 xc;
    f32 x10;
    u8 pad14[0x40 - 0x14];
    s32 x40;
    s32 x44;
    f32 x48;
} Eff;
typedef struct Wk_8007E88C { u8 pad0[8]; void* x8; u8 pad[0x4C - 0xC]; Eff* eff; } Wk_8007E88C;
typedef struct Tk_8007E88C { u8 pad[0x19]; u8 state; u8 pad1a[0x24 - 0x1A]; Wk_8007E88C* work; } Tk_8007E88C;
typedef struct Tbl {
    u8 pad0[8];
    u32 flags;
    u8 padc[0x14 - 0xC];
    f32 x14;
    s32 x18;
    f32 x1c;
} Tbl;
extern int fn_80018B80(void*);
extern void fn_80018C94(void);
extern void fn_80299040(void*);
extern void fn_800342BC(void*);
extern int fn_80082840(s8 x, s8 y, u8 c, u8* grid, void* extra);
typedef struct Obj24 {
    u8 pad0[0xE];
    u8 xe;
    u8 pad0f[7];
    u8 x16;
} Obj24;
typedef struct Obj {
    u8 pad0[0x24];
    Obj24* d;
} Obj;
typedef struct Slot_80083728 {
    u8 pad0[0xAE];
    s16 flags;
} Slot_80083728;
extern s32 fn_80083558(s32 a, s32 b);
extern s32 fn_80083398(s32 a, s32 b);
extern s32 fn_80082D8C(s32 a, s32 b);
typedef struct Hd74E2C {
    u32 f0;
    u32 f4;
} Hd74E2C;
typedef struct Ent74E2C {
    u8 pad0[0x20];
    Hd74E2C *f20;
} Ent74E2C;
typedef struct Sub74E2C {
    u8 pad0[4];
    Ent74E2C *f4;
} Sub74E2C;
typedef struct Rec74E2C {
    u8 pad0[8];
    Sub74E2C *f8;
    u8 pad_c[0x2c - 0xc];
    u32 f2c;
    u8 pad30[0x3c - 0x30];
    u32 f3c;
} Rec74E2C;
typedef struct Out74E2C {
    s32 *f0;
    u8 pad4[4];
    s32 *f8;
    u8 pad_c[4];
    Rec74E2C *f10;
    s16 f14;
    s16 f16;
    u8 pad18[0x34 - 0x18];
    f32 f34;
    f32 f38;
    f32 f3c;
    s32 f40;
    u8 pad44[4];
    Hd74E2C *f48;
} Out74E2C;
extern void *memset(void *, int, unsigned long);
extern s32 fn_8006EA90(void *, void *, Rec74E2C **);
extern void fn_8006CF28(Sub74E2C *, s32 **, s32);
extern void fn_80074394(s32 *, s16 *);
extern void fn_80074968(s32 *, u32 *);
extern void fn_80074D9C(void *, s32 *);
extern s32 fn_80227810(void *);
extern char* lbl_80347320;
typedef struct Eff_8007E690 {
    u8 pad0[0xC];
    f32 xc;
    f32 x10;
    u8 pad14[0x40 - 0x14];
    s32 x40;
    s32 x44;
    f32 x48;
} Eff_8007E690;
typedef struct Wk_8007E690 { void* x0; u32 x4; void* x8; u8 padc[0x4C - 0xC]; Eff_8007E690* eff; } Wk_8007E690;
typedef struct Tk_8007E690 { u8 pad[0x19]; u8 state; u8 pad1a[0x24 - 0x1A]; Wk_8007E690* work; } Tk_8007E690;
typedef struct Tbl_8007E690 {
    u8 pad0[8];
    u32 flags;
    u8 padc[0x10 - 0xC];
    f32 x10;
    u8 pad14[4];
    s32 x18;
    f32 x1c;
} Tbl_8007E690;
typedef struct Pos_8007E690 { u8 pad0[8]; f32 x8; f32 xc; f32 x10; } Pos_8007E690;
typedef struct Vec_8007E690 { f32 x; f32 y; f32 z; } Vec_8007E690;
extern void sndAuxCallbackShutdownReverbSTD(void* a, Pos_8007E690** out);
extern int fn_80011E50(Vec_8007E690* v, f32* out, int flag);
extern s16 lbl_80309DCC[12];
extern s32 fn_8007FFE8(s32 i, s32 k);
void fn_800811E4(s16 id, int mode);
extern s32 fn_80010340(s32 i);
extern void fn_80087054(Slot*);
typedef struct Node_800804B8 { u8 pad[0x24]; s16* work; } Node_800804B8;
int fn_80078478(s32 a);
extern int fn_8007EBBC(int a, int b, u8 k, u32 st);
extern int fn_8007F270(int a, int b, u8 k, u32 st);
extern void fn_80082134(s16 v);
extern int fn_8006D1C4(int v);
extern s16 fn_80010CBC(s32 id);
typedef struct Blob { u32 w[16]; } Blob;
typedef struct Req_8007DFC0 {
    s16 a;          /* 0x00 */
    s16 b;          /* 0x02 */
    Blob data;      /* 0x04 */
} Req_8007DFC0;
typedef struct Cmd_8007DFC0 { u8 pad[0xC]; Req_8007DFC0* req; } Cmd_8007DFC0;
typedef struct Rec_8007DFC0 {
    void* x0;
    u8 pad4[0x48];
    struct Rec2* x4c;
} Rec_8007DFC0;
typedef struct Rec2 {
    u8 pad0[4];
    s16 x4;
    u8 pad6[6];
    Blob x0c;
} Rec2;
typedef struct Node_8007DFC0 { u8 pad[0x24]; Rec_8007DFC0* work; } Node_8007DFC0;
extern s32 fn_800300C4(s16);
extern void fn_80061F58(void*, int, int);
typedef struct Wk_E9E0 {
    Rec item;
    void* x4c;
    u8 pad50[8];
} Wk_E9E0;
typedef struct Node_8007E9E0 { u8 pad[0x24]; Wk_E9E0* work; } Node_8007E9E0;
extern void fn_8022F00C(void*);
extern void fn_8022F030(void*, int, int);
extern u8* lbl_80346C14;
extern s32 lbl_80347338;
extern void fn_8007C344(void);
extern void fn_800794D8(void);
extern void fn_8007B5B0(void);
extern void fn_8007A890(void);
extern void fn_8007BEB4(void);

typedef struct Msg {
    s16 x0;
    s16 x2;
    s16 x4;
    s16 x6;
    s32 x8;
    s32 xc;
} Msg;
extern void fn_80075060(Msg*, s16);
void fn_80075040(Msg* a, s16 i) {
    fn_80075060(a, i);
}

extern void fn_8007578C(Msg*, s16);
void fn_8007576C(Msg* a, s16 i) {
    fn_8007578C(a, i);
}

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
    return lbl_802AD440[i].pad[0x526];
}

s32 fn_80078370(s32 i) {
    return lbl_802C7C34[i].pad[-0x21ae];
}

s32 fn_8007838C(s32 i) {
    return lbl_802C4BF0[i].pad[0x15];
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
    lbl_80309E5C.f8 |= 0x04000000;
  } else {
    lbl_80309E5C.f8 &= ~0x04000000;
  }
}

typedef struct E0D8Anim {
    u16 cur;
    u16 end;
    s16 sub;
    u8 pad6[2];
    u32 val;
    u8 mat[0x14];
    void *p20;
    u8 pad24[8];
    void *p2c;
} E0D8Anim;
typedef struct E0D8Obj {
    u8 pad0[0x18];
    u8 flags;
    u8 state;
    u8 pad1A[10];
    struct { void *p0; u8 pad4[0x48]; E0D8Anim *anim; } *inner;
} E0D8Obj;
extern void fn_80230634(void *, void *);
extern void fn_80230280(void *, void *);
extern s32 fn_800179E4(s16);
extern void fn_8022FDA0(f32, void *, void *);
extern void fn_801E17E0(void* p);
void fn_8007E4F8(E0D8Obj *obj) {
    E0D8Anim *a;
    void *p;
    p = obj->inner->p0;
    a = obj->inner->anim;
    if (p == 0) {
        obj->state = 3;
    }
    switch (obj->state) {
    case 0:
        if (a->cur >= a->end) {
            obj->state = 1;
            a->val = *(u32 *)((u8 *)p + 4);
        } else {
            a->cur = a->cur + 1;
        }
        break;
    case 1:
        fn_80230634(p, a->mat);
        fn_80230280(p, a->mat);
        obj->state = 2;
        break;
    case 2:
        if (a->sub >= 0 && fn_800179E4(a->sub) == 0) {
            obj->state = 3;
        }
        fn_8022FDA0((f32)a->cur, p, a->mat);
        a->cur += 1.0f;
        break;
    case 3:
        if (a->p20 != 0) {
            fn_801E17E0(a->p20);
        }
        if (a->p2c != 0) {
            fn_801E17E0(a->p2c);
        }
        obj->flags |= 0x40;
        break;
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
        r = t->un.req->x3c;
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

void fn_80088F60(void) {
}

void fn_8008999C(void* a) {
    fn_80083BAC((s32)a, 3);
}

extern void fn_80083ACC(s16 id, u32 kind);
void fn_8008A12C(s32 p) {
    fn_80083BAC(p, 1);
}

void fn_8008A150(s16 p) {
    fn_80083ACC(p, 1);
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

s16 fn_800760EC(Slot* t, s16 k) {
    Wk* w = t->un.work;
    Unit* u = w->u;
    s32 idx = fn_8001FDD8(w);
    if (k == 2 || k == 7) {
        s16 j = u->x204;
        if (j != 0) {
            return u->xdc[j].a.x6;
        }
    }
    return u->xdc[(s16)idx].a.x6;
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
        lbl_80309700[idx]->update = (void (*)())fn_80080278;
        lbl_80309700[idx]->flag19 = 0;
        p->req->f50 = 0;
        return 1;
    }
    return 0;
}

void fn_80081168(s16 idx, s32 val) {
    Req *req = lbl_80309700[idx]->un.req;
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

static inline s16 pick(Slot* t, s32 k, s32 j) {
    Wk* w = t->un.work;
    Unit* u = w->u;
    s32 idx = fn_8001FDD8(w, k, j);
    if (((s16)k == 2 || (s16)k == 7) && u->x204 != 0) {
        return u->xdc[u->x204].a.x6;
    }
    return u->xdc[(s16)idx].a.x6;
}

s32 fn_80075FF0(Slot* t, s32 k, s32 j) {
    Wk* w = t->un.work;
    Unit* u = w->u;
    s32 idx;
    s32 r;
    if (u->xf0 & 0x80000) return 0;
    if (u->xf0 & 0x800) return 0;
    idx = fn_8001FDD8(w);
    r = fn_80075DAC(0.0f, u->xdc[(s16)idx].b.x14, w, pick(t, k, j), u->xdc[(s16)idx].b.flags, k, j);
    u->xe6 = idx;
    return r;
}

s32 fn_80076170(f32 a, f32 b, Wk* o, s32 id, s32 k, s32 j) {
    Unit* u = o->u;
    Sub* p = 0;
    u32 fl = 0;
    s32 r;
    s32 idx;
    u->x74 = u->x5c;
    u->x7c = u->x68;
    if (u->x60 != 0) {
        p = &u->x84;
        fl = 0x40000000;
        p->x0 = u->x60;
        p->x8 = u->x68;
    }
    idx = fn_8001FDD8(o, k, j);
    if (u->xdc[(s16)idx].b.flags & 0x80000) {
        fl |= 0x80000;
    }
    r = fn_80075DAC(a, 1.0f, o, id, fl, k, j);
    if (r == 0) return r;
    u->x78 = u->x5c;
    u->x80 = a;
    if (u->x60 != 0) {
        p->x4 = u->x60;
        p->xc = a;
    }
    u->x68 = 0.0f;
    u->x6c = b;
    u->x70 = 0;
    return r;
}

void fn_8007E13C(Arg* a) {
    Rec* r;
    s32 i;
    lbl_80309E5C.tab[lbl_80309E5C.idx].count = *lbl_80309E5C.tab[lbl_80309E5C.idx].src->x8;
    lbl_80309E5C.tab[lbl_80309E5C.idx].recs = fn_801E1C7C(lbl_80309E5C.tab[lbl_80309E5C.idx].count * sizeof(Rec));
    r = a->recs;
    for (i = 0; i < lbl_80309E5C.tab[lbl_80309E5C.idx].count; i++) {
        lbl_80309E5C.tab[lbl_80309E5C.idx].recs[i] = r[i];
        lbl_80309E5C.tab[lbl_80309E5C.idx].recs[i].x10 = lbl_80309E5C.tab[lbl_80309E5C.idx].src;
        fn_8007E9E0(i);
    }
}

void fn_80081EF4(s16 a, s32 b) {
    s32 c = fn_80081FEC(lbl_80347334);
    Wk* w;
    if ((s8)c == 0x1b || (s8)c == 0x1c || (s8)c == 0x2f || (s8)c == 0x27 || fn_80078610(a)) {
        w = lbl_80309700[a]->un.work;
        if (w->x37 != 0) {
            if (w->x3c != -1 || w->x44 != -1 || w->x46 != -1 || w->x48 != -1 || w->x4a != -1) {
                w->x37 = 0;
                fn_8002DD8C(a, b, c);
            }
        }
    }
}

s32 fn_80081FEC(s16 k) {
    if (k == lbl_80309174[lbl_80347334].x4 && lbl_80309174[lbl_80347334].x0 == 3) {
        return 0;
    }
    switch (lbl_80309174[k].x0) {
    case 3:
        return 0;
    case 1:
    case 2:
    case 8:
        {
            s16 j = lbl_80309174[k].x6;
            if (k < 4) {
                return (s8)lbl_802C4BF0[j].pad[0x15];
            }
            return (s8)lbl_802AD440[j].pad[0x16];
        }
    case 5:
        return (s8)lbl_802C7C34[lbl_80309174[k].x6].pad[-0x21ae];
    case 12:
        return (s8)lbl_802AD440[lbl_80309174[k].x6].pad[0x526];
    }
    return 0;
}

void fn_80082C98(s8 x, s8 y, u8* grid, s32 a, s32 b) {
    void* wa;
    void* wb;
    if (x >= 0 && x <= 10 && y >= 0 && y <= 10) {
        wa = lbl_80309700[a]->un.work;
        wb = lbl_80309700[b]->un.work;
        if (fn_80082AC0(x, y, grid, a) == 0) return;
        if (fn_8008328C(wa, wb, x, y) == 0) return;
        lbl_80309300[lbl_8034734E * 2] = x;
        lbl_80309300[lbl_8034734E * 2 + 1] = y;
        *(grid + y * 11 + x) = 1;
        lbl_8034734E++;
        if (lbl_8034734E >= 0x200) lbl_8034734E = 0;
    }
}

s32 fn_8008A738(void) {
    s32 i;
    s16 sum = 0;
    for (i = 4; i < 12; i++) {
        if (sum > 3000) {
            break;
        }
        if (lbl_80309DE4[i] == NULL) {
            return 1;
        }
        if (lbl_80309700[i] != 0) {
            sum = sum + lbl_80309DE4[i]->p110->s56;
        }
    }
    return 0;
}

void fn_800770B8(Chr* c, Src* s) {
    s32 i;
    c->x0 = 0;
    c->xb8 = 0;
    c->x2 = 0;
    c->x4 = 0;
    c->x5 = 1;
    c->xb9 = 1;
    c->x6 = 0;
    c->x14 = s->x24;
    c->x18 = s->x24;
    c->xba = s->x1c;
    c->x8 = s->x1c;
    c->xa = 0;
    c->xc = 0;
    c->xe = 0;
    i = 0;
    do {
        c->xbc[i] = s->x2c[i];
        c->x28[i] = s->x2c[i];
        c->x34[i] = 0;
        i++;
    } while (i < 6);
    i = 0;
    do {
        c->xc8[i] = s->x38[i];
        c->x40[i] = s->x38[i];
        c->x60[i] = 0;
        i++;
    } while (i < 16);
    i = 0;
    do {
        c->xe8[i] = s->x5c[i];
        c->x80[i] = s->x5c[i];
        c->x8a[i] = 0;
        i++;
    } while (i < 5);
    i = 0;
    do {
        c->xf2[i] = s->x66[i];
        c->x94[i] = s->x66[i];
        c->xa0[i] = 0;
        i++;
    } while (i < 6);
    c->xac = s->x15;
    c->xad = s->x16;
    c->xae = s->x1a;
    c->xb4 = 0;
    c->xb6 = 0;
    c->x10 = 0;
    c->x1c = 0;
    c->xb0 = s->x28;
    c->x10a = 0;
    c->x10c = 0;
    c->x110 = s;
}

void fn_8007C194(List* l) {
    Ent* e;
    s32 n = 0;
    s16 v;
    s32 i;
    l->x1 = 0;
    v = lbl_80347390->xa;
    if (lbl_80346C0C == 2 || lbl_80346C0C == 5) {
        l->e[0].type = 0x3D;
        n = 1;
        l->e[0].p = &(*(u8(*)[])&lbl_802C4BF0)[0xB70];
        l->e[0].id = v;
        l->e[0].w = lbl_802F6918[0xF4 / 4];
        l->e[0].on = 1;
    }
    if (lbl_80346C0C == 3 || lbl_80346C0C == 5) {
        e = &l->e[n];
        e->type = 0x3C;
        e->p = &(*(u8(*)[])&lbl_802C4BF0)[0xB40];
        e->id = v;
        e->w = lbl_802F6918[0xF0 / 4];
        e->on = 1;
        n++;
    }
    l->count = n;
    for (i = n; i < 8; i++) {
        l->e[i].type = -1;
        l->e[i].p = 0;
        l->e[i].id = -1;
        l->e[i].on = 0;
    }
    l->x2 = 1;
    l->x6 = 0;
    l->x7 = 0;
}

void fn_8007E88C(Tk_8007E88C* t) {
    Wk_8007E88C* w = t->work;
    Eff* e = w->eff;
    DrawState ds;
    switch (t->state) {
    case 0:
        t->state = 1;
        e->xc = 0.0f;
        break;
    default:
        DrawStateDefault2D(&ds);
        if ((*(Tbl*)&lbl_80309E5C).flags & 0x20000000) {
            e->x10 += (*(Tbl*)&lbl_80309E5C).x14;
            if (e->x10 <= -1.0f) {
                e->x10 = -1.0f;
            }
        } else if ((*(Tbl*)&lbl_80309E5C).flags & 0x10000000) {
            e->x10 += (*(Tbl*)&lbl_80309E5C).x14;
            if (e->x10 >= 0.0f) {
                e->x10 = 0.0f;
                (*(Tbl*)&lbl_80309E5C).flags &= ~0x10000000;
            }
        } else {
            e->x10 = 0.0f;
        }
        if ((*(Tbl*)&lbl_80309E5C).flags & 0x08000000) {
            e->x40 = 1;
            e->x44 = (*(Tbl*)&lbl_80309E5C).x18;
            e->x48 = (*(Tbl*)&lbl_80309E5C).x1c;
        } else {
            e->x40 = 0;
        }
        if (fn_80018B80(&e->x10)) {
            fn_80299040(w->x8);
            if (e->x10 > -1.0f) {
                fn_800342BC(w);
            }
            fn_80018C94();
        }
        break;
    }
}

void fn_80082948(s8 x, s8 y, u8* grid, void* extra) {
    u8 c = *(grid + y * 11 + x);
    s8 m = 0;
    if (!fn_80082840(x - 1, y, c, grid, extra)) {
        m = 4;
    }
    if (!fn_80082840(x, y - 1, c, grid, extra)) {
        m += 1;
    }
    if (!fn_80082840(x, y + 1, c, grid, extra)) {
        m += 2;
    }
    if (!fn_80082840(x + 1, y, c, grid, extra)) {
        m += 8;
    }
    if (!(m & 5)) {
        fn_80082840(x - 1, y - 1, c, grid, extra);
    }
    if (!(m & 6)) {
        fn_80082840(x - 1, y + 1, c, grid, extra);
    }
    if (!(m & 9)) {
        fn_80082840(x + 1, y - 1, c, grid, extra);
    }
    if (!(m & 0xA)) {
        fn_80082840(x + 1, y + 1, c, grid, extra);
    }
}

s32 fn_80083728(s32 a, s32 b)
{
    Obj24* d = (*(Obj*(*)[12])&lbl_80309700)[a]->d;
    d->x16 = 0;
    if (!fn_80078610(b)) return 0;
    if (fn_80083558(a, b)) {
        d->x16 = 1;
        return 1;
    }
    if (!fn_80083398(a, b)) return 0;
    if (!((*(Slot_80083728*(*)[12])&lbl_80309DE4)[a]->flags & 1)) return 0;
    if (fn_80083558(a, b)) {
        d->x16 = 2;
        return 2;
    }
    if (fn_80082D8C(a, b)) {
        d->x16 = 4;
        return 4;
    }
    d->xe = 0;
    if (fn_80082D8C(a, b)) {
        d->x16 = 4;
        return 4;
    }
    return 0;
}

Rec74E2C *fn_80074E2C(void *a, void *b, Out74E2C *out, s16 id, u8 kind) {
    Rec74E2C *rec;
    s32 *loc;
    s32 r;
    memset(out, 0, 0x4c);
    out->f16 = id;
    out->f34 = 1.0f;
    out->f38 = 1.0f;
    out->f3c = 1.0f;
    r = fn_8006EA90(a, b, &rec);
    if ((s16)r != 0) {
        out->f10 = rec;
        out->f16 = id;
    } else {
        return 0;
    }
    fn_8006CF28(rec->f8, &loc, id);
    if (loc != 0) {
        out->f0 = (s32 *)*loc;
        out->f8 = loc + 2;
        fn_80074394(out->f0, &out->f14);
    }
    if (out->f8 != 0) {
        Ent74E2C *t = rec->f8->f4;
        if (kind == 3) {
            if (t->f20->f4 != 0) {
                out->f48 = t->f20;
            }
        } else if (loc != 0 && t->f20->f4 != 0) {
            out->f8 = (s32 *)t->f20;
        } else if (loc == 0 && t->f20->f4 != 0) {
            out->f8 = (s32 *)t->f20;
        } else if (loc == 0) {
            return 0;
        }
    }
    if ((s16)r == 1) {
        if (out->f8 != 0) {
            if ((u32)*out->f8 != 0) {
                if (!(rec->f3c & 0x20000000)) {
                    out->f40 = fn_80227810(out->f8);
                }
            } else {
                out->f8 = 0;
            }
        }
        if (out->f0 != 0) {
            fn_80074D9C(b, out->f0);
            fn_80074968(out->f0, &rec->f2c);
            if (out->f48 != 0 && !(rec->f3c & 0x20000000)) {
                fn_80227810(out->f48);
            }
        }
    } else {
        if (out->f0 != 0 && rec->f2c == 0) {
            fn_80074968(out->f0, &rec->f2c);
        }
    }
    return rec;
}

void fn_80078AD4(char* src)
{
    int n;
    int left;
    int right;
    int pad;
    int i;
    char* dst;

    for (n = 0; n < 0x12; n += 2) {
        if ((s8)src[n] == 0) break;
    }
    pad = 16 - n;
    dst = lbl_80347320 + 0xb;
    left = pad / 2;
    right = pad - left;
    for (i = 0; i < left; i++) {
        *dst++ = ' ';
    }
    for (i = 0; i < n; i++) {
        *dst++ = *src++;
    }
    for (i = 0; i < right; i++) {
        *dst++ = ' ';
    }
    *dst = 0;
}

void fn_8007E690(Tk_8007E690* t)
{
    Wk_8007E690* w = t->work;
    Eff_8007E690* e = w->eff;
    Pos_8007E690* pos;
    Vec_8007E690 v;
    f32 hit;

    switch (t->state) {
    case 0:
        t->state = 1;
        e->xc = 0.0f;
        break;
    default:
        if ((*(Tbl_8007E690*)&lbl_80309E5C).flags & 0x80000000) {
            e->x10 += (*(Tbl_8007E690*)&lbl_80309E5C).x10;
            if (e->x10 <= -1.0f) {
                e->x10 = -1.0f;
            }
        } else if ((*(Tbl_8007E690*)&lbl_80309E5C).flags & 0x40000000) {
            e->x10 += (*(Tbl_8007E690*)&lbl_80309E5C).x10;
            if (e->x10 >= 0.0f) {
                e->x10 = 0.0001f;
                (*(Tbl_8007E690*)&lbl_80309E5C).flags &= ~0x40000000;
            }
        } else {
            e->x10 = 0.0001f;
        }
        if ((*(Tbl_8007E690*)&lbl_80309E5C).flags & 0x08000000) {
            e->x40 = 1;
            e->x44 = (*(Tbl_8007E690*)&lbl_80309E5C).x18;
            e->x48 = (*(Tbl_8007E690*)&lbl_80309E5C).x1c;
        } else {
            e->x40 = 0;
        }
        if (!((*(Tbl_8007E690*)&lbl_80309E5C).flags & 0x04000000)) {
            sndAuxCallbackShutdownReverbSTD(w->x0, &pos);
            v.x = pos->x8;
            v.y = pos->xc;
            v.z = pos->x10;
            if (fn_80011E50(&v, &hit, (f32)fabs(v.x) > (f32)fabs(v.z) ? 0 : 1) != 0) {
                if ((*(Tbl_8007E690*)&lbl_80309E5C).flags & 0x40000000) {
                    if (hit < e->x10) {
                        e->x10 = hit;
                        (*(Tbl_8007E690*)&lbl_80309E5C).flags &= ~0x40000000;
                    }
                } else {
                    e->x10 = hit;
                }
            }
        }
        if (fn_80018B80(&e->x10)) {
            fn_80299040(w->x8);
            if (e->x10 > -1.0f) {
                fn_800342BC(w);
            }
            fn_80018C94();
        }
        break;
    }
}

void fn_800840BC(void)
{
    u8* src;
    u8* dst;
    u8* map;
    u8* row;
    u8* p;
    s16 i;
    s16 j;

    if (lbl_80347354 == 0) {
        lbl_80347354 = fn_801E1C7C(0x79);
    }
    row = lbl_80347354;
    map = (*(Map_800840BC*)&lbl_80309E5C).cells;
    for (i = 0; i < 9; i++) {
        src = map;
        dst = row;
        for (j = 0; j < 9; j++) {
            switch (*src) {
            case 1:
                dst[12] = 0x7D;
                break;
            case 2:
            case 4:
                dst[12] = 0x7C;
                break;
            default:
                dst[12] = 0;
                break;
            }
            src++;
            dst++;
        }
        map += 9;
        row += 11;
    }
    p = lbl_80347354;
    for (i = 0; i < 11; i++) {
        *p++ = 0x7F;
    }
    for (i = 0; i < 9; i++) {
        p[0] = 0x7F;
        p[10] = 0x7F;
        p += 11;
    }
    for (i = 0; i < 11; i++) {
        *p++ = 0x7F;
    }
    if (lbl_80347350 == 0) {
        lbl_80347350 = fn_801E1C7C(0x79);
    }
    fn_802AC710(lbl_80347350, lbl_80347354, 0x79);
}

void fn_800858B8(Slot* self) {
    s32 i;
    Wk* sub;
    sub = self->un.work;
    i = sub->idx;
    switch (self->flag19) {
    case 0:
        if (fn_8007FFE8(i, 0) != 0) {
            self->flag19 = 10;
        }
        break;
    case 10:
        fn_80081168(i, 10);
        if (fn_80010340(i) != 0) {
            self->flag19 = 1;
            lbl_80309730[i].b8 = 1;
        } else {
            self->flag19 = 2;
            lbl_80309730[i].b8 = 0;
        }
        break;
    case 1:
        if (fn_8007FFE8(i, 10) != 0) {
            lbl_80309DE4[i]->w1c |= 0x2000;
            lbl_80309DCC[i] = -3;
            sub->flags |= 0x10;
            lbl_80309700[i]->update = fn_80086C48;
            lbl_80309700[i]->flag19 = 0;
        }
        break;
    case 2:
        if (fn_8007FFE8(i, 10) != 0) {
            s32 j;
            for (j = 0; j <= 3; j++) {
                if (fn_80078610(j) != 0) {
                    lbl_80309DE4[j]->w1c |= 1;
                }
            }
            fn_800811E4(i, 0);
            self->flag19 = 3;
        }
        break;
    case 3:
        if (fn_8007FFE8(i, 0) != 0) {
            sub->flags |= 1;
            lbl_80309700[i]->update = fn_80086C48;
            lbl_80309700[i]->flag19 = 0;
        }
        break;
    }
}

void fn_80088B14(Slot* self) {
    s32 i;
    Wk* sub;
    sub = self->un.work;
    i = sub->idx;
    switch (self->flag19) {
    case 0:
        fn_80081168(i, 10);
        if (fn_80010340(i) != 0) {
            self->flag19 = 1;
            lbl_80309730[i].b8 = 1;
        } else {
            lbl_80309730[i].b8 = 0;
            self->flag19 = 2;
        }
        break;
    case 1:
        if (fn_8007FFE8(i, 10) != 0) {
            lbl_80309DCC[i] = -3;
            lbl_80309DE4[i]->w1c |= 0x2000;
            sub->flags |= 0x10;
            lbl_80309700[i]->update = (void *)fn_80087054;
            lbl_80309700[i]->flag19 = 0;
        }
        break;
    case 2:
        if (fn_8007FFE8(i, 10) != 0) {
            self->flag19 = 3;
            fn_800811E4(i, 0);
            lbl_80309DE4[i]->w1c |= 1;
        }
        break;
    case 3:
        if (fn_8007FFE8(i, 0) != 0) {
            sub->flags |= 1;
            lbl_80309700[i]->update = (void *)fn_80087054;
            lbl_80309700[i]->flag19 = 0;
        }
        break;
    }
}

s32 fn_80080278(Node_80080278* t) {
    s16 id = *t->work;
    s32 v;
    if (lbl_80309700[id]->un.work->x10 != 0) {
    lbl_80309700[id]->update = fn_800801A8;
    lbl_80309700[id]->flag19 = 0;
    if (fn_8007FFE8(id, 0x16)) {
        if (id <= 3) {
            lbl_80302C08[0].x4 = 0x7F;
            lbl_80302C08[0].x0 = -1;
            lbl_80302C08[1].x4 = 0x7F;
            lbl_80302C08[1].x0 = -1;
            lbl_80302C08[2].x4 = 0x7F;
            lbl_80302C08[2].x0 = -1;
            lbl_80302C08[3].x4 = 0x7F;
            lbl_80302C08[3].x0 = -1;
            lbl_80302C08[4].x4 = 0x7F;
            lbl_80302C08[4].x0 = -1;
            lbl_80302C08[5].x4 = 0x7F;
            lbl_80302C08[5].x0 = -1;
            lbl_80302C08[6].x4 = 0x7F;
            lbl_80302C08[6].x0 = -1;
            lbl_80302C08[7].x4 = 0x7F;
            lbl_80302C08[7].x0 = -1;
            lbl_80302C08[8].x4 = 0x7F;
            lbl_80302C08[8].x0 = -1;
            lbl_80302C08[9].x4 = 0x7F;
            lbl_80302C08[9].x0 = -1;
            lbl_80302C08[10].x4 = 0x7F;
            lbl_80302C08[10].x0 = -1;
            lbl_80302C08[11].x4 = 0x7F;
            lbl_80302C08[11].x0 = -1;
            fn_800839D8(id, lbl_80302C08, 2);
            v = lbl_80302C08[0].x0;
        } else {
            lbl_80302C08[0].x4 = 0x7F;
            lbl_80302C08[0].x0 = -1;
            lbl_80302C08[1].x4 = 0x7F;
            lbl_80302C08[1].x0 = -1;
            lbl_80302C08[2].x4 = 0x7F;
            lbl_80302C08[2].x0 = -1;
            lbl_80302C08[3].x4 = 0x7F;
            lbl_80302C08[3].x0 = -1;
            lbl_80302C08[4].x4 = 0x7F;
            lbl_80302C08[4].x0 = -1;
            lbl_80302C08[5].x4 = 0x7F;
            lbl_80302C08[5].x0 = -1;
            lbl_80302C08[6].x4 = 0x7F;
            lbl_80302C08[6].x0 = -1;
            lbl_80302C08[7].x4 = 0x7F;
            lbl_80302C08[7].x0 = -1;
            lbl_80302C08[8].x4 = 0x7F;
            lbl_80302C08[8].x0 = -1;
            lbl_80302C08[9].x4 = 0x7F;
            lbl_80302C08[9].x0 = -1;
            lbl_80302C08[10].x4 = 0x7F;
            lbl_80302C08[10].x0 = -1;
            lbl_80302C08[11].x4 = 0x7F;
            lbl_80302C08[11].x0 = -1;
            fn_800839D8(id, lbl_80302C08, 1);
            v = lbl_80302C08[0].x0;
        }
        lbl_80309730[id].xd = v;
        fn_800811E4(id, 2);
    }
    return 1;
    }
    return 0;
}

void fn_800804B8(Node_800804B8* t) {
    s16 id = *t->work;
    s32 v;
    if (lbl_80309700[id]->un.work->x10 != 0) {
    lbl_80309700[id]->update = fn_800801A8;
    lbl_80309700[id]->flag19 = 0;
    if (fn_8007FFE8(id, 0x16)) {
        if (id <= 3) {
            lbl_80302C08[0].x4 = 0x7F;
            lbl_80302C08[0].x0 = -1;
            lbl_80302C08[1].x4 = 0x7F;
            lbl_80302C08[1].x0 = -1;
            lbl_80302C08[2].x4 = 0x7F;
            lbl_80302C08[2].x0 = -1;
            lbl_80302C08[3].x4 = 0x7F;
            lbl_80302C08[3].x0 = -1;
            lbl_80302C08[4].x4 = 0x7F;
            lbl_80302C08[4].x0 = -1;
            lbl_80302C08[5].x4 = 0x7F;
            lbl_80302C08[5].x0 = -1;
            lbl_80302C08[6].x4 = 0x7F;
            lbl_80302C08[6].x0 = -1;
            lbl_80302C08[7].x4 = 0x7F;
            lbl_80302C08[7].x0 = -1;
            lbl_80302C08[8].x4 = 0x7F;
            lbl_80302C08[8].x0 = -1;
            lbl_80302C08[9].x4 = 0x7F;
            lbl_80302C08[9].x0 = -1;
            lbl_80302C08[10].x4 = 0x7F;
            lbl_80302C08[10].x0 = -1;
            lbl_80302C08[11].x4 = 0x7F;
            lbl_80302C08[11].x0 = -1;
            fn_800839D8(id, lbl_80302C08, 2);
            v = lbl_80302C08[0].x0;
        } else {
            lbl_80302C08[0].x4 = 0x7F;
            lbl_80302C08[0].x0 = -1;
            lbl_80302C08[1].x4 = 0x7F;
            lbl_80302C08[1].x0 = -1;
            lbl_80302C08[2].x4 = 0x7F;
            lbl_80302C08[2].x0 = -1;
            lbl_80302C08[3].x4 = 0x7F;
            lbl_80302C08[3].x0 = -1;
            lbl_80302C08[4].x4 = 0x7F;
            lbl_80302C08[4].x0 = -1;
            lbl_80302C08[5].x4 = 0x7F;
            lbl_80302C08[5].x0 = -1;
            lbl_80302C08[6].x4 = 0x7F;
            lbl_80302C08[6].x0 = -1;
            lbl_80302C08[7].x4 = 0x7F;
            lbl_80302C08[7].x0 = -1;
            lbl_80302C08[8].x4 = 0x7F;
            lbl_80302C08[8].x0 = -1;
            lbl_80302C08[9].x4 = 0x7F;
            lbl_80302C08[9].x0 = -1;
            lbl_80302C08[10].x4 = 0x7F;
            lbl_80302C08[10].x0 = -1;
            lbl_80302C08[11].x4 = 0x7F;
            lbl_80302C08[11].x0 = -1;
            fn_800839D8(id, lbl_80302C08, 1);
            v = lbl_80302C08[0].x0;
        }
        lbl_80309730[id].xd = v;
        fn_800811E4(id, 2);
    }
    }
}

void fn_800811E4(s16 id, int mode) {
    int r;
    int k = 0;
    if (lbl_80309700[id] == 0) {
        return;
    }
    if (lbl_80309700[id]->un.work->flags & 0x20) {
        lbl_80309700[id]->un.work->flags &= ~0x20;
        lbl_80309730[id].w0 = 0x12;
    }
    if (lbl_80309DE4[id]->w1c & 0x8000) {
        k = 1;
    }
    switch (mode) {
    case 0:
    case 1:
        r = k != 0;
        break;
    case 2:
    case 3:
        r = 2;
        if (k != 0) {
            r = 3;
        }
        break;
    }
    switch (lbl_80309730[id].w0) {
    case 0:
    case 2:
        if (r == 0 || r == 2) {
            lbl_80309730[id].w0 = r;
            return;
        }
        break;
    case 1:
    case 3:
        if (r == 1 || r == 3) {
            lbl_80309730[id].w0 = r;
            return;
        }
        break;
    }
    if (lbl_80309700[id]->un.work->flags & 0x20) {
        lbl_80309700[id]->un.work->flags &= ~0x20;
        lbl_80309730[id].w0 = 0x12;
    }
    if (r != lbl_80309730[id].w0) {
        lbl_80309730[id].w0 = r;
        lbl_80309730[id].b9 = 0;
        lbl_80302BF0[id] = 0;
    }
}

int fn_8007FAB0(int a, int b)
{
    int v = 0;
    u32 st;
    u8 k;
    int i;

    lbl_80309700[a]->un.work->x50 = 3;
    if (b == -1) {
        if (lbl_80309DE4[a]->w1c & 0x400000) {
            b = a;
        } else {
            return 1;
        }
    }
    st = lbl_80309174[a].x0;
    k = fn_80078478(a);
    switch (st) {
    case 2:
        if (fn_8007838C(lbl_80309174[a].x6) == 0x2f) {
            for (i = 0; i < 4; i++) {
                if (lbl_80309700[i] != 0) {
                    s8 x = lbl_80309700[i]->un.work->x50;
                    if (x != 3 && x != 1) goto done;
                }
            }
            {
                i = 0;
                do {
                    if (lbl_80309700[i] != 0) {
                        lbl_80309700[i]->un.work->flags |= 0x20;
                        lbl_80309700[i]->un.work->x50 = 4;
                        fn_80082134(i);
                        if (a != i) {
                            lbl_80309730[i].b9 = 0;
                        }
                    }
                    i++;
                } while (i <= 3);
                v = 1;
            }
        } else {
            v = fn_8007EBBC(a, b, k, st);
        }
        break;
    case 3:
    case 5:
    case 8:
    case 12:
        v = fn_8007EBBC(a, b, k, st);
        break;
    case 1:
        v = fn_8007F270(a, b, k, st);
        break;
    }
done:
    return v;
}

void fn_80084C78(Slot* t)
{
    int a;
    int c;
    Wk* wk;
    int r;
    s16 saved;

    wk = t->un.work;
    a = wk->idx;
    c = lbl_80309174[a].x4;

    switch (t->flag19) {
    case 0:
        if (fn_8007FFE8(a, 0x16) != 0) {
            fn_800811E4(a, 0);
            t->flag19 = 1;
        }
        break;
    case 1:
        if (fn_8007FFE8(0, 0) != 0) {
            if (fn_8007FAB0(a, c) != 0) {
                saved = wk->x3c;
                wk->x3c = lbl_80347390->x8;
                lbl_80309174[a].xd = 0;
                fn_8002DD8C(a, 0, 100);
                wk->x3c = saved;
                fn_80081168(a, 0xC);
                lbl_80309730[a].x4 = c;
                lbl_80309730[a].x6 = 0x3C;
                t->flag19 = 0xB;
            }
        }
        break;
    case 11:
        if (fn_8007FFE8(a, 0x15) != 0) {
            fn_800811E4(a, 0);
            t->flag19 = 0xC;
        }
        break;
    case 12:
        r = fn_8007FFE8(a, 0x16);
        if (r != 0) {
            if (fn_8006D1C4(r) == 1) {
                wk->flags |= 1;
                lbl_80309700[a]->update = fn_80086C48;
                lbl_80309700[a]->flag19 = 0;
            }
        }
        break;
    }
}

int fn_80078478(s32 a) {
    int v;
    s16 idx;
    s16 k;
    switch (lbl_80309174[a].x0) {
    case 3:
        if (lbl_80309174[a].x4 < 4) {
            return 1;
        }
        return 3;
    case 12:
        return lbl_802AD440[(s16)(lbl_80309174[a].x6 + 0x24)].x17;
    case 8:
        idx = lbl_80309174[a].x6 - 0x3C;
        return lbl_802C4BF0[(s16)(idx + 0x3C)].x16;
    case 1:
    case 2:
        k = lbl_80309174[a].x6;
        if (a >= 4) {
            return lbl_802AD440[k].x17;
        }
        v = lbl_802C4BF0[k].x16;
        if (lbl_80309DE4[a]->w1c & 0x00400000) {
            switch (v) {
            case 3:
                v = 1;
                break;
            case 4:
                v = 2;
                break;
            default:
                if (v >= 0x20 && v < 0x60) {
                    v = 0x60;
                }
                break;
            }
        }
        return (u8)v;
    case 5:
        return lbl_802C7C34[lbl_80309174[a].x6 - 0xF0].x13;
    default:
        return 0;
    }
}

void fn_80085ADC(Slot* o)
{
    s32 id;
    Wk* d = o->un.work;
    id = d->idx;
    switch (o->flag19) {
    case 0:
        if (fn_8007FFE8(id, 0)) {
            fn_800811E4(id, 0);
            o->flag19 = 10;
        }
        break;
    case 10:
        if (fn_8007FFE8(id, 0)) {
            fn_80081168(id, 9);
            if (lbl_80309DE4[id]->w1c & 0x3100) {
                lbl_80309730[id].b8 = 0;
                d->x3c = 0;
            } else {
                lbl_80309730[id].b8 = 1;
                d->x3c = fn_80010CBC(id);
            }
            fn_8002DD8C(id, 0xF, 0x65);
            o->flag19 = 1;
        }
        break;
    case 1:
        if (fn_8007FFE8(id, 9)) {
            fn_800811E4(id, 0);
            o->flag19 = 2;
        }
        break;
    case 2:
        if (fn_8007FFE8(id, 0)) {
            d->flags |= 1;
            lbl_80309700[id]->update = fn_80086C48;
            lbl_80309700[id]->flag19 = 0;
        }
        break;
    }
}

void fn_8007DFC0(Cmd_8007DFC0* c) {
    G_8007E13C* t = &lbl_80309E5C;
    Req_8007DFC0* r = c->req;
    Node_8007DFC0* n;
    Rec_8007DFC0* w;
    if (r->a < t->tab[t->idx].count) {
        n = fn_802268E8(lbl_803475A8, (void*)fn_800300C4(4));
        fn_80061F58(&n->work, 0x58, 0);
        w = n->work;
        w->x0 = (void *)fn_8006C9AC(*(s32*)((u8*)t->tab[t->idx].recs + r->a * 0x4c), r->b & 0xFFFF);
        fn_80061F58(&w->x4c, 0x4c, 0);
        w->x4c->x0c = r->data;
        w->x4c->x4 = -1;
    }
}

void fn_8007E9E0(u8 i) {
    G_8007E13C* t = &lbl_80309E5C;
    Hdr* h;
    Node_8007E9E0* n;
    Wk_E9E0* w;
    s16 a;

    a = t->tab[t->idx].recs[i].x18;
    fn_8006CF28((void *)t->tab[t->idx].src->x8, (void *)&h, t->tab[t->idx].recs[i].x16);
    n = fn_802268E8(lbl_803475A8, (void*)fn_800300C4(a));
    fn_80061F58(&n->work, 0x58, 0);
    w = n->work;
    w->item = t->tab[t->idx].recs[i];
    w->item.x8 = (Hdr*)((u8*)h + 8);
    if (w->item.x8->x0 != 0) {
        w->item.x40 = (void *)fn_80227810((void *)w->item.x8);
    } else {
        w->item.x8 = 0;
    }
    w->item.x0 = h->x0;
    t->tab[t->idx].recs[i] = w->item;
    if (a != 0xFF) {
        fn_80061F58(&w->x4c, 0x54, 0);
        fn_8022F00C(w->item.x0);
        fn_8022F030(w->item.x0, -1, 1);
    }
}

int fn_800819D0(s16 a, s16 b)
{
    Chr_UNIT0000* chr = lbl_80309DE4[b];
    u32 bits = chr->w1c;

    if (bits & 0x6D00) return 0;
    if ((b < 4 && a < 4) || (b >= 4 && a >= 4)) return 0;
    if ((int)lbl_80309730[b].b8 == 2) return 0;
    if ((bits & 2) == 0 && (bits & 0x800000) == 0) {
        if (chr->xba == 0) return 0;
        if (fn_8025ECC4() % 100 >= chr->xb4) return 0;
    }
    if (lbl_80309730[a].w0 == 7) {
        if ((lbl_80309DE4[b]->xae & 0x80) == 0) return 0;
        lbl_80309174[b].xc = 1;
    } else if ((lbl_80309DE4[b]->xae & 0x40) == 0) {
        lbl_80309174[b].xc = 1;
    } else {
        lbl_80309174[b].xc = 0;
    }
    if ((chr->w1c & 2) || (chr->w1c & 0x800000)) {
        chr->xb4 = 100;
    } else {
        chr->xb4 = 0;
    }
    return 1;
}

void fn_8007C600(u32 arg)
{
    s32 slot;
    if ((s8)lbl_80346C14[arg] == 0) return;
    slot = lbl_80347330;
    switch (arg) {
    case 0:
    case 4:
        lbl_80347338 = 3;
        lbl_80309174[slot].x4 = slot;
        lbl_80309174[slot].x6 = -1;
        break;
    case 6:
        if ((int)lbl_80346C14[6] == 2) {
            if (lbl_80347300 == 0) {
                lbl_80347318[0x19] = 4;
                lbl_80347300 = fn_802268E8(lbl_80347318, fn_8007C344);
            }
        } else {
            lbl_8034733C = 2;
            lbl_80347338 = 0;
            fn_8007D32C();
            lbl_80309174[0].x0 = 4;
            lbl_80309174[0].x4 = 0;
            lbl_80309174[0].x6 = -1;
            lbl_80309174[1].x0 = 4;
            lbl_80309174[1].x4 = 1;
            lbl_80309174[1].x6 = -1;
            lbl_80309174[2].x0 = 4;
            lbl_80309174[2].x4 = 2;
            lbl_80309174[2].x6 = -1;
            lbl_80309174[3].x0 = 4;
            lbl_80309174[3].x4 = 3;
            lbl_80309174[3].x6 = -1;
        }
        break;
    case 3:
        if (lbl_80347310 == 0) {
            lbl_80347318[0x19] = 5;
            lbl_80347310 = fn_802268E8(lbl_80347318, fn_800794D8);
        }
        break;
    case 1:
        if (lbl_80347314 == 0) {
            lbl_80347318[0x19] = 4;
            lbl_80347314 = fn_802268E8(lbl_80347318, fn_8007B5B0);
        }
        break;
    case 5:
        if (lbl_80347308 == 0) {
            lbl_80347318[0x19] = 4;
            lbl_80347308 = fn_802268E8(lbl_80347318, fn_8007A890);
        }
        break;
    case 2:
        if (lbl_80347304 == 0) {
            lbl_80347318[0x19] = 4;
            lbl_80347304 = fn_802268E8(lbl_80347318, fn_8007BEB4);
        }
        break;
    }
    lbl_80309174[lbl_80347330].x0 = arg;
}

void fn_80087054(Slot* s) {
    fn_800804B8((Node_800804B8*)s);
}

void fn_8007EB9C(s32 a, s32 b) {
    fn_80083558(a, b);
}

void fn_80086C48(Node_800804B8* t) {
    fn_800804B8(t);
}

void fn_80088ABC(Ctx_80085C88 *c) {
    Req_80085C88 *req = c->req;
    void (*fp)(void) = (void (*)(void))fn_80087054;
    s16 idx = req->idx;
    Chr_UNIT0000 *o = lbl_80309DE4[idx];
    o->w1c |= 1;
    req->flags |= 1;
    lbl_80309700[idx]->update = fp;
    lbl_80309700[idx]->flag19 = 0;
}
