#include "types.h"
#include "ninja.h"
#include "game/drawstate.h"
#include <math.h>
#include "game/task.h"
#include "game/save_8030B7F4.h"
#include "game/stat_8030B4D4.h"
#include "game/gamedata.h"
#include "game/unit_80074D9C.h"
extern u32 lbl_802B0830[];
extern s32 lbl_80347330;
extern ChrState lbl_80309174[12];
extern PosTbl lbl_803097F0;
s32 fn_8006CEEC(Ctx_8006CEEC *c, Motion **out, u32 idx, s32 slot);
s32 fn_8006E898(char* s);
void fn_80072E8C(s16 k, s16 b, s16 c, char *d);
s32 fn_80072DD4(s16 a, s16 b, s16 c, void *d);
extern void fn_8006D080(void *p, s32 free);
extern s16 fn_8001FDD8(Mdl *w, s16 id, s16 sub);
struct Slot;
extern Slot *lbl_80309700[12];
extern s32 fn_80081FEC(s16 i);
extern Chr_UNIT0000* lbl_80309DE4[12];
typedef struct Inner { u8 pad0[0x6]; s16 f6; s16 f8; u8 pad1[0xa]; s16 f14; s16 f16; u8 pad2[0x68-0x18]; float f68; u8 pad3[0xec-0x6c]; u32 fec; u32 ff0; } Inner;
typedef struct Mid { u8 pad[0x4c]; Inner *inner; } Mid;
typedef struct Top { u8 pad[0x24]; Mid *mid; } Top;
/* lbl_80309E14: list of matrices attached to an owner (a model node). */
typedef struct Node {
    struct Node *next;  /* 0x0 */
    f32 *mtx;           /* 0x4 */
    void *owner;        /* 0x8 */
    u8 flag;            /* 0xc 0: camera-relative, 1: absolute */
} Node;
extern Node lbl_80309E14;
/* lbl_80309EC8: the 0x244-byte battle/system block; its first 0x40 bytes are a matrix here. */
typedef struct {
    NJS_MATRIX m;
    u8 pad40[0x244 - 0x40];
} Sys_80309EC8;
extern Sys_80309EC8 lbl_80309EC8;
extern void njSetMatrix(NJS_MATRIX dst, NJS_MATRIX src);
extern void njInvertMatrix(NJS_MATRIX m);
extern void njMultiMatrix(NJS_MATRIX m, NJS_MATRIX src);
extern void fn_80291C44(NJS_MATRIX m);
void *fn_8006C9AC(void *root, s32 target);
void fn_800763D0(f32 *a, void *b);
extern s32 fn_80078610(s8 idx);
void fn_8007D42C(Obj_8007DE54_8007D42C* p);
extern void fn_8007DE54(Obj_8007DE54 *p);
extern void *lbl_803475A8;
extern void *lbl_8034736C;
extern void *fn_802268E8(void *, void *);
extern void* fn_801E1C7C(int size);
s32 fn_80075DAC(f32 f1, f32 f2, Mdl* o, u16 id, u32 flags, s16 a, s16 b);
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
extern Lim* lbl_80347390;
typedef struct Rec74E2C {
    u8 pad0[8];
    Sub74E2C *f8;
    u8 pad_c[0x2c - 0xc];
    u32 f2c;
    u8 pad30[0x3c - 0x30];
    u32 f3c;
} Rec74E2C;
/* A 4-character model/chunk tag: "MA?0" or "CR??" (either case) marks the object. */
typedef struct {
    char c0;
    char c1;
    char c2;
    u8 c3;
} Name74D9C;
typedef struct Out74E2C {
    Obj74D9C *f0;
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
extern void fn_8006CF28(Sub74E2C *, Loc74E2C **, s32);
extern void fn_80074394(void *, s16 *);
extern void fn_80074968(void *, u32 *);
void fn_80074D9C(Name74D9C *n, Obj74D9C *o);
extern s32 fn_80227810(void *);
u8 fn_80078478(int a);
typedef struct TNode {
    u32 flags;          /* 8: hidden */
    void* mesh;         /* 0x04 */
    u8 pad8[0x2c - 0x8];
    struct TNode* child;
    struct TNode* next;
} TNode;
void fn_80075060(TNode* n, u32 mask, u8 op);
extern void fn_801DBE1C(const char* fmt, ...);
extern void fn_801E17E0(void *p);
void fn_8007629C(void *owner);
extern f32 *lbl_80346BF0;
void* fn_801E1A74(s32 count, s32 size);
extern s32 fn_801F4C24(s16 id);
extern s8 fn_801F452C(s16 id);

void fn_80075040(TNode* n, u32 mask, u8 op) {
    fn_80075060(n, mask, op);
}

#define NODE_OP(n)                     \
    switch (op) {                      \
    case 0: (n)->flags |= mask; break; \
    case 1: (n)->flags &= mask; break; \
    case 2: (n)->flags ^= mask; break; \
    }

static inline void flag_walk3(TNode* n, u32 mask, u8 op) {
    NODE_OP(n);
    if (n->child) {
        fn_80075060(n->child, mask, op);
    }
    if (n->next) {
        fn_80075060(n->next, mask, op);
    }
}

static inline void flag_walk2(TNode* n, u32 mask, u8 op) {
    NODE_OP(n);
    if (n->child) {
        flag_walk3(n->child, mask, op);
    }
    if (n->next) {
        flag_walk3(n->next, mask, op);
    }
}

static inline void flag_walk1(TNode* n, u32 mask, u8 op) {
    NODE_OP(n);
    if (n->child) {
        flag_walk2(n->child, mask, op);
    }
    if (n->next) {
        flag_walk2(n->next, mask, op);
    }
}

/* Applies mask to the flags of a node tree (0: set, 1: and, 2: toggle). */
void fn_80075060(TNode* n, u32 mask, u8 op) {
    NODE_OP(n);
    if (n->child) {
        flag_walk1(n->child, mask, op);
    }
    if (n->next) {
        flag_walk1(n->next, mask, op);
    }
}

void fn_8007578C(TNode* p, u8 show);
void fn_8007576C(TNode* a, u8 i) {
    fn_8007578C(a, i);
}

/* Shows or hides every node of a tree that has a mesh. */
inline void fn_8007578C(TNode* p, u8 show) {
    if (p->mesh != 0) {
        if (show == 0) {
            p->flags |= 8;
        } else {
            p->flags &= ~8;
        }
    }
    if (p->child != 0) fn_8007578C(p->child, show);
    if (p->next != 0) fn_8007578C(p->next, show);
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

void fn_8007629C(void *owner)
{
    Node *p;

    for (p = lbl_80309E14.next; p != NULL; p = p->next) {
        if (owner != p->owner) {
            continue;
        }
        switch (p->flag) {
        case 0:
            njSetMatrix(p->mtx, lbl_80309EC8.m);
            njInvertMatrix(p->mtx);
            fn_80291C44(lbl_80346BF0);
            njMultiMatrix(p->mtx, lbl_80346BF0);
            break;
        case 1:
            fn_80291C44(p->mtx);
            break;
        }
    }
}

void fn_80076344(f32 *key) {
  Node *p = &lbl_80309E14;
  Node *q;
  while (p->next != 0) {
    if (p->next->mtx == key) p->next->flag ^= 0x80;
    q = p->next;
    if (q == 0) return;
    p = q;
  }
}

void fn_8007638C(f32 *a, void *b, s32 c) {
  void *x = fn_8006C9AC(b, c);
  fn_800763D0(a, x);
}

s32 fn_80077E34(void) {
    s16 i = lbl_803097F0.x0;
    if (i == -1) {
        return -1;
    }
    return lbl_802B0830[i];
}

s32 fn_800783A8(s32 i)
{
    s8 k;
    switch (lbl_80309174[i].x0) {
    case 3:
        if (i <= 3) {
            k = lbl_802C5790[lbl_80309DE4[i]->xb6].effect;
            if (k == -1) {
                return 0;
            }
            return lbl_802C7A90[k].effect;
        } else {
            s32 v = lbl_80309DE4[i]->p110->x58;
            if (v == -1) {
                v = 0;
            }
            return v;
        }
    }
    k = fn_80081FEC(i);
    return k;
}

s32 fn_8007833C(void) {
    return lbl_80309174[lbl_80347330].x0;
}

s32 fn_80078354(s32 i) {
    return lbl_802AD440[i + 0x24].effect;
}

s32 fn_80078370(s32 i) {
    return lbl_802C7C34[i - 0xF0].effect;
}

s32 fn_8007838C(s32 i) {
    return lbl_802C4BF0[i].effect;
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
extern void fn_801E17E0(void* p);

#define CLEAR(b)                          \
    lbl_80309700[b]->work->x3c = 0;       \
    lbl_80309700[b]->work->x40 = 0;       \
    lbl_80309700[b]->work->x44 = -1;      \
    lbl_80309700[b]->work->x46 = -1;      \
    lbl_80309700[b]->work->x48 = -1;      \
    lbl_80309700[b]->work->x4a = -1

#define SETFN(f)                       \
    lbl_80309700[id]->update = f;        \
    lbl_80309700[id]->state = 0


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




static inline s16 pick(MdlTask *t, s16 k, s16 j) {
    Mdl *w = t->work;
    Unit *u = w->u;
    s16 idx = fn_8001FDD8(w, k, j);
    if ((k == 2 || k == 7) && u->x204 != 0) {
        return u->xdc[u->x204].x6;
    }
    return u->xdc[idx].x6;
}

s32 fn_80075C70(MdlTask *t, s16 k, s16 j) {
    Unit *u = t->work->u;
    if (u->xf0 & 2) {
        if (u->x64 == pick(t, k, j)) {
            return 1;
        }
        return 0;
    }
    return 0;
}

s32 fn_80075DAC(f32 f1, f32 f2, Mdl* o, u16 id, u32 flags, s16 a, s16 b) {
    Motion* vc;
    Motion* v8 = 0;
    char buf[0x20];
    Unit* u = o->u;
    Ctx_8006CEEC* p;
    s16 k;

    if (id == u->x64 && !(flags & 0x04000000) && !(u->xec & 1) && !(u->xf0 & 0x00080000)) {
        return 1;
    }
    if (flags & 0x00080000) {
        fn_80072E8C(u->x6, u->x8, u->x2, buf);
        if (!fn_8006E898(buf) && u->x228 != 0) {
            fn_8006D080(u->x228, 1);
        }
        fn_80072DD4(a, b, u->x2, u->x218);
        p = u->x228->x8;
        k = 0;
    } else {
        p = o->x10->x8;
        k = id;
    }
    if (!fn_8006CEEC(p, &vc, k, o->x16)) {
        return 0;
    }
    if (flags & 0x40000000) {
        if (!fn_8006CEEC(p, &v8, k + 1, o->x16)) {
            return 0;
        }
    }
    u->x5c = vc;
    u->x64 = id;
    u->x68 = f1;
    u->x6c = f2;
    u->x70 = 0;
    u->x60 = v8;
    return 1;
}

s32 fn_80075F2C(MdlTask* t)
{
    Mdl* w = t->work;
    Unit* u = w->u;
    s16 id;

    if (u->xdc[u->xe4].x2 != 1) {
        return 0;
    }
    if ((u->x6 == 2 || u->x6 == 7) && u->x204 != 0) {
        id = u->xdc[u->x204].x6;
    } else {
        id = u->xdc[u->xe4].x6;
    }
    fn_80075DAC(0.0f, u->xdc[u->xe4].x14, w, id, u->xdc[u->xe4].flags, u->x6, u->x8);
    return 1;
}

s32 fn_80075FF0(MdlTask* t, s16 k, s16 j) {
    Mdl* w = t->work;
    Unit* u = w->u;
    s16 idx;
    s32 r;
    if (u->xf0 & 0x80000) return 0;
    if (u->xf0 & 0x800) return 0;
    idx = fn_8001FDD8(w, k, j);
    r = fn_80075DAC(0.0f, u->xdc[idx].x14, w, pick(t, k, j), u->xdc[idx].flags, k, j);
    u->xe6 = idx;
    return r;
}

s16 fn_800760EC(MdlTask* t, s16 k, s16 j) {
    return pick(t, k, j);
}

s32 fn_80076170(f32 a, f32 b, Mdl* o, s32 id, s16 k, s16 j) {
    Unit* u = o->u;
    Sub* p = 0;
    u32 fl = 0;
    s32 r;
    s16 idx;
    u->x74 = u->x5c;
    u->x7c = u->x68;
    if (u->x60 != 0) {
        p = &u->x84;
        fl = 0x40000000;
        p->x0 = u->x60;
        p->x8 = u->x68;
    }
    idx = fn_8001FDD8(o, k, j);
    if (u->xdc[idx].flags & 0x80000) {
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

/* Sets flag 8 on o for an "MA.0" or "CR" tag. The digit is read into an s32 local and compared
 * as an int (cmpwi on the unextended byte); comparing the u8 field directly gives cmplwi. */
void fn_80074D9C(Name74D9C *n, Obj74D9C *o) {
    s32 f = 0;
    if ((n->c0 == 'M' || n->c0 == 'm') && (n->c1 == 'A' || n->c1 == 'a')) {
        s32 digit = n->c3;
        if (digit == '0') {
            f = 1;
        }
    } else if ((n->c0 == 'C' || n->c0 == 'c') && (n->c1 == 'R' || n->c1 == 'r')) {
        f = 1;
    }
    if (f) {
        o->flags |= 8;
    }
}

Rec74E2C *fn_80074E2C(void *a, void *b, Out74E2C *out, s16 id, u8 kind) {
    Rec74E2C *rec;
    Loc74E2C *loc;
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
        out->f0 = loc->obj;
        out->f8 = loc->data;
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

u8 fn_80078478(int a) {
    int v;
    s16 idx;
    s16 k;
    switch (lbl_80309174[a].x0) {
    case 3:
        if (lbl_80309174[a].b4 < 4) {
            return 1;
        }
        return 3;
    case 12:
        return lbl_802AD440[(s16)(lbl_80309174[a].x6 + 0x24)].target;
    case 8:
        idx = lbl_80309174[a].x6 - 0x3C;
        return lbl_802C4BF0[(s16)(idx + 0x3C)].target;
    case 1:
    case 2:
        k = lbl_80309174[a].x6;
        if (a >= 4) {
            return lbl_802AD440[k].target;
        }
        v = lbl_802C4BF0[k].target;
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
        return v;
    case 5:
        return lbl_802C7C34[lbl_80309174[a].x6 - 0xF0].target;
    default:
        return 0;
    }
}

/* Drops one reference from the slot holding id; frees the slot (id = -1) when it reaches 0. */
void fn_80077D40(s16 id)
{
    ItemSlot *s = lbl_80347390->e;
    int i = 0;

    do {
        if (id == s[i].id) {
            s[i].count--;
            if (s[i].count <= 0) {
                s[i].id = -1;
            }
            return;
        }
        i++;
    } while (i < 80);
}

void fn_80077DA0(s16 id)
{
    ItemSlot *e = lbl_80347390->e;
    s32 i;
    i = 0;
    do {
        if (id == e[i].id) {
            if (e[i].count < 99) e[i].count++;
            return;
        }
        i++;
    } while (i < 80);
    i = 0;
    do {
        if (e[i].id == -1) {
            e[i].id = id;
            e[i].count = 1;
            return;
        }
        i++;
    } while (i < 80);
}

void fn_8007651C(void) {
    void *p = 0;
    lbl_80309E14.next = 0;
    while (p != 0) {
        void *nx = *(void **)p;
        fn_801E17E0(p);
        p = nx;
    }
    fn_802938C0(fn_8007629C);
    lbl_80346BF0 = fn_801E1C7C(0x40);
}


/* bDelGetMotMat: unlinks and frees every node with keys (a, b). */
void fn_800763D0(f32 *a, void *b) {
    Node *p = &lbl_80309E14;
    Node *q;

    if (p->next == 0) {
        fn_801DBE1C("Error > bDelGetMotMat() > Can't Del");
    }
    while ((q = p->next) != 0) {
        if (q->mtx == a && q->owner == b) {
            p->next = q->next;
            fn_801E17E0(q);
        }
        if (p->next == 0) {
            return;
        }
        p = p->next;
    }
}

s32 fn_80076478(f32 *key, void *a, s32 b, u8 flag)
{
    void *mat;
    Node *head;
    Node *n;

    mat = fn_8006C9AC(a, b);
    head = &lbl_80309E14;
    if (key == 0 || mat == 0) {
        fn_801DBE1C("Error: bAddGetMotMat");
    }
    n = fn_801E1A74(1, 0x10);
    if (n == NULL) {
        fn_801DBE1C("Error: bAddGetMotMat");
    }
    n->mtx = key;
    n->owner = mat;
    n->flag = flag;
    n->next = head->next;
    head->next = n;
    return 1;
}


/* The battle copy of a character, filled by fn_80077228. */
typedef struct Dst_80077228 {
    s16 x0; s16 x2; u8 x4; u8 x5; u8 x6; u8 pad7; s16 x8; s16 xa; s16 xc; s16 xe; u8 pad10[4];
    s32 x14; s32 x18; s32 x1c; s32 x20; u8 pad24[4];
    s16 x28[6]; s16 x34[6]; s16 x40[16]; s16 x60[16]; s16 x80[5]; s16 x8a[5]; s16 x94[6]; s16 xa0[6];
    u8 xac; u8 xad; s16 xae; f32 xb0; s16 xb4; s16 xb6; u8 xb8; u8 xb9; s16 xba;
    s16 xbc[6]; s16 xc8[16]; s16 xe8[5]; s16 xf2[6];
    u8 xfe; u8 xff; u8 x100; u8 pad101; s16 x102; s16 x104; u8 x106; u8 pad107; s16 x108; s16 x10a; s16 x10c; u8 pad10e[2];
    CharParam* x110;
} Dst_80077228;

void fn_80077228(s8 idx, Dst_80077228* d)
{
    StatRec* a = &lbl_8030B4D4.chr[idx];
    SaveChar* b = &lbl_8030B7F4.chr[idx];
    CharParam* c = &lbl_802C4860[idx];
    int i;
    s8 cd;
    u8 ce;
    s16 ca;
    f32 fv;
    d->xb8 = a->x0;
    d->x0 = (s8)a->x0;
    d->x2 = 0;
    d->x4 = 0;
    d->xb9 = a->x2;
    d->x5 = a->x2;
    d->x6 = 0;
    d->x14 = b->hp;
    d->x18 = b->hpMax;
    d->xba = a->xe;
    d->x8 = a->xe;
    d->xa = 0;
    d->xc = 0;
    d->xe = 0;
    i = 0;
    do {
        d->xbc[i] = a->x1c[i];
        d->x28[i] = a->x1c[i];
        d->x34[i] = 0;
        i++;
    } while (i < 6);
    i = 0;
    do {
        d->xc8[i] = a->x28[i];
        d->x40[i] = a->x28[i];
        d->x60[i] = 0;
        i++;
    } while (i < 16);
    i = 0;
    do {
        d->xe8[i] = a->x48[i];
        d->x80[i] = a->x48[i];
        d->x8a[i] = 0;
        i++;
    } while (i < 5);
    i = 0;
    do {
        d->xf2[i] = a->x52[i];
        d->x94[i] = a->x52[i];
        d->xa0[i] = 0;
        i++;
    } while (i < 6);
    cd = c->width;
    ce = c->depth;
    d->xac = cd;
    ca = c->moves;
    d->xad = ce;
    fv = c->x30;
    d->xae = ca;
    d->xb4 = b->x20;
    d->xb6 = b->slot0;
    d->x1c = a->x14;
    d->x20 = a->x14;
    d->x10a = a->xa;
    d->x10c = a->xc;
    d->xb0 = fv;
    d->xfe = b->mp;
    d->xff = b->mpMax;
    d->x100 = b->xf;
    d->x102 = b->slot1;
    d->x104 = b->slot2;
    d->x106 = b->xc;
    d->x108 = b->x22;
    d->x110 = c;
}

static inline s8 WeaponOwner(s16 id)
{
    return lbl_802C5790[id].owner;
}

static inline s8 ArmourOwners(s16 idx)
{
    return lbl_802C6190[idx].owners;
}

static inline s8 AccOwners(s16 idx)
{
    return lbl_802C6E10[idx].owners;
}

s32 fn_80077E60(s32 p, s16 id) {
    Chr_UNIT0000* c;
    s32 i;
    s32 j;
    s32 kind;
    s32 rem;
    s32 base;
    s8 cnt;

    base = lbl_8030B7F4.party[p];
    rem = 5 - base;
    kind = fn_801F4C24(id);
    cnt = fn_801F452C(id);
    switch (kind) {
    case 0:
        if (base == WeaponOwner(id)) {
            return 1;
        }
        break;
    case 1:
        if ((1 << rem) & ArmourOwners(id - 0x50)) {
            for (i = 0; i < 4; i++) {
                c = lbl_80309DE4[i];
                if (c != 0 && id == c->x102 && p != i) {
                    cnt--;
                    if (cnt <= 0) {
                        return 0;
                    }
                }
            }
            return 1;
        }
        break;
    case 2:
        if ((1 << rem) & AccOwners(id - 0xa0)) {
            for (j = 0; j < 4; j++) {
                c = lbl_80309DE4[j];
                if (c != 0 && id == c->x104 && p != j) {
                    cnt--;
                    if (cnt <= 0) {
                        return 0;
                    }
                }
            }
            return 1;
        }
        break;
    }
    return 0;
}

/* fn_8007D42C (unit_80074D9C): the battle music task (fn_80078658 mode 1). It snapshots the enemy
 * slots, then keeps comparing the party's and the enemies' remaining HP and switches between the
 * calm (state 2), pinch (3) and winning (4) phrase sets of the battle track (fn_802182F4). */
