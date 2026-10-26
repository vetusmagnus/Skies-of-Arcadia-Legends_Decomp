#include "types.h"
#include "ninja.h"
#include "game/drawstate.h"
#include <dolphin/os.h>
#include "game/menu.h"
void VISetNextFrameBuffer(void *fb);
void VIFlush(void);
void VIWaitForRetrace(void);
extern void *lbl_803476AC;
extern u32 *lbl_803476C0;
void fn_801D4A2C(s32 a, s32 b, s32 c, void *d, s32 e, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5, f32 f6);
extern s32 lbl_80347568[2];
typedef struct Sub { u8 pad[0x20]; s32 val; } Sub;
typedef struct Outer { u8 pad[4]; Sub *sub; } Outer;
void fn_801D5A50(s32 a, s32 b, s32 c, s32 d, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5, f32 f6);
extern Outer *lbl_80347618;
void fn_802275A4(s32 v, s32 flag);
void fn_801E17E0(void *p);
extern Outer *lbl_80347614;
void *fn_801E1BDC(s32 size);
extern s32 lbl_8034761C;
typedef struct Thing { u8 pad[8]; void *f8; void *fc; } Thing;
typedef struct Quad {
    s32 type;  /* 0x00 */
    f32 f04;   /* 0x04 */
    s32 f08;   /* 0x08 */
    void *f0c; /* 0x0C */
    f32 f10;   /* 0x10 */
    f32 f14;   /* 0x14 */
    f32 f18;   /* 0x18 */
    f32 f1c;   /* 0x1C */
    f32 f20;   /* 0x20 */
    f32 f24;   /* 0x24 */
    f32 f28;   /* 0x28 */
    f32 f2c;   /* 0x2C */
} Quad;
typedef struct Ctx {
    u8 pad0[0x50];
    s32 f50;
    u8 pad1[0x18];
    f32 f6c;
    f32 f70;
    f32 f74;
} Ctx;
void fn_802871D8(void *p);
extern Ctx lbl_8030E830;
typedef struct Ent { u32 key; u32 next; s16 val; s16 pad; } Ent;
typedef struct Req { u32 key; void *next; } Req;
extern Ent lbl_802F65C0[8];
typedef struct RelocEnt { u32 ptr; u32 b; u32 c; } RelocEnt;
typedef struct RelocTbl { RelocEnt *ents; s32 count; } RelocTbl;
extern u32 lbl_80312D00[16];
void *memcpy(void *dst, const void *src, u32 n);
extern s32 lbl_8034754C;
extern u8 lbl_8030EA1C[];
typedef struct Ob { u8 pad0[2]; s16 s2; u8 pad1[0x48]; void *p4c; } Ob;
void fn_801DFA9C(void *p, s32 v);
typedef struct Mo { u8 pad0[4]; u8 m4[0x28]; u8 m2c[0x1C]; s32 x48; void *x4c; } Mo;
void njPushMatrixEx(void);
void njPopMatrixEx(void);
void fn_80286EE8(void);
void fn_8028B498(void);
void fn_801E04E8(void *m, s32 a, void *b, void *c);
void *fn_801E184C(void *obj, s32 idx, void *src, s32 n);
extern u8 lbl_802F6748[];
void fn_8024DF5C(u32 a);
void GXClearGPMetric(void);
void GXInvalidateVtxCache(void);
void GXInvalidateTexAll(void);
extern u8 lbl_80311B00[];
void fn_801E1718(void *p);
extern u8 *lbl_80347608;
void fn_801D843C(void *a, s32 b, s32 c, s32 d, s32 e, s32 f);
extern u8 *lbl_80347654;
extern u8 *lbl_80347660;
extern u32 lbl_80312D40[4];
void fn_801E1A74(s32 a, s32 b);
extern s32 lbl_80347550;
typedef struct {
    s32 active;
    u8 pad4[0x14 - 4];
    u32 x14;
} Obj_80311C30;
extern Obj_80311C30 lbl_80311C30;
/* word 0 is compared as a key and also returned as a pointer */
typedef struct ReqB { union { u32 key; void *obj; } u; void *next; } ReqB;
typedef struct Obj { u8 pad[0x18]; u8 mtx[1]; } Obj;
typedef struct Node {
    Obj* obj;
    u8 pad4[4];
    f32 pos[3];
    f32 rot[3];
    f32 scl[3];
    struct Node* child;
    struct Node* next;
} Node;
extern void njTranslateEx(f32* p);
extern void njRotateEx(f32* r, s32 a);
extern void njScaleEx(f32* s);
extern void fn_80291C44(void* m);
void fn_801D25DC(Node* n);
#define BODY(n)     njPushMatrixEx();     fn_80286EE8();     fn_8028B498();     njTranslateEx((n)->pos);     njRotateEx((n)->rot, 0);     njScaleEx((n)->scl);     if ((n)->obj != 0) {         fn_80291C44((n)->obj->mtx);     }
typedef struct Vtx { u16 idx; s16 flag; } Vtx;
typedef struct Mesh {
    f32 cx;
    u8 pad4[4];
    f32 cz;
    f32 r2;
    f32* verts;
    s32 count;
    u8 pad18[0x58 - 0x18];
} Mesh;
typedef struct Node_801D30DC {
    Mesh* mesh;
    u8 pad4[2];
    s16 id;
    f32 pos[3];
    f32 rot[3];
    f32 scl[3];
    struct Node_801D30DC* child;
    struct Node_801D30DC* next;
} Node_801D30DC;
typedef struct Hit {
    NJS_POINT3 a;
    NJS_POINT3 b;
    NJS_POINT3 c;
    s16 flag;
    u8 pad26[0x32 - 0x26];
    s16 id;
} Hit;
extern void njInvertMatrix(void* m);
extern s32 fn_801D48BC(f32* pt, f32* a, f32* b, f32* c);
extern void fn_80290668(f32* a, f32* b, f32* c, f32* n);
s32 fn_801D30DC(NJS_POINT3* p, Node_801D30DC* n, Hit* out);
typedef struct { u8 d[0x50]; } Anim;
typedef struct {
    s8 b0, b1, b2, b3, b4, b5, b6, b7, b8; /* 0x00 */
    u8 pad09[3];
    s32 wc;       /* 0x0c */
    s16 w10;      /* 0x10 */
    u8 pad12[2];
    Anim a0;      /* 0x14 */
    Anim a[3];    /* 0x64 */
    Anim b[3];    /* 0x154 */
    s32 w244;     /* 0x244 */
} State801D;
extern State801D* lbl_8034765C;
extern f32 lbl_80311DF0[];
extern s32 fn_801A3510(void);
extern void fn_801D89D4(void* p, s32 a, s32 b, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5, f32 f6, f32 f7, f32 f8);
extern void fn_801D8AB4(void* p, s32 a, s32 b, f32 f1, f32 f2);
typedef struct {
    s8 b[9];      /* 0x00 */
    u8 pad09[3];
    s32 wc;       /* 0x0c */
    s16 w10;      /* 0x10 */
    u8 pad12[2];
    u8 anim[0x230]; /* 0x14 */
    s32 w244;     /* 0x244 */
} State801D_801D91F4;
typedef struct { u8 pad[0x8]; u32 x8; } PadState;
typedef struct { PadState* pad; u8 pad4[0x14]; } PadInfo;
extern s32 lbl_80347658;
extern PadInfo lbl_80311A60;
typedef struct Node801D Node801D;
typedef struct { u8 pad[0x10]; u32 x10; } Inner;
struct Node801D {
    Inner* a;       /* 0x00 */
    u8 pad04[0x28];
    Node801D* c1;   /* 0x2c */
    Node801D* c2;   /* 0x30 */
};
void fn_801DA748(Node801D* n);
typedef struct Node801DF6 Node801DF6;
typedef struct { void* x0; } Data801DF6;
struct Node801DF6 {
    u32 flags;       /* 0x00 */
    Data801DF6* d;   /* 0x04 */
    u8 pad08[0x24];
    Node801DF6* c1;  /* 0x2c */
    Node801DF6* c2;  /* 0x30 */
};
extern s32 fn_801CB1AC(void* p);
void fn_801DF600(Node801DF6* n, s32* count, s32* total);
typedef struct {
    f32 dist;          /* 0x00 */
    NJS_POINT3 pos;    /* 0x04 */
    NJS_VECTOR dir;    /* 0x10 */
} Hit801E;
typedef struct {
    NJS_POINT3 min;  /* 0x00 */
    NJS_POINT3 max;  /* 0x0C */
    f32 flag;        /* 0x18 */
} Box801E;
typedef struct {
    NJS_POINT3 c;     /* 0x00 */
    NJS_POINT3 d;     /* 0x0C */
} Ref801E;
extern void njUnitVector(NJS_VECTOR* v);
extern void njCalcVector(f32* m, NJS_VECTOR* v, NJS_VECTOR* out);
extern void fn_802900C0(NJS_POINT3* p, NJS_POINT3* c, NJS_POINT3* out);
extern f32 fn_80291A5C(f32 v);
extern f32 fn_801DFE48(NJS_POINT3* p, Box801E* box);
typedef struct DataEntry {
    void *base;
    s32 offset;
} DataEntry;
typedef struct DataTable {
    u8 *base;
    s32 count;
    s32 *offsets;
    s32 *work;
    s32 *data;
} DataTable;
extern s32 *fn_8022ACA8(s32);
extern void *fn_801E1C7C(s32);

void fn_801D1AE8(void) {
    VISetNextFrameBuffer(lbl_803476AC);
    VIFlush();
    VIWaitForRetrace();
    if (*lbl_803476C0 & 1) {
        VIWaitForRetrace();
    }
}

void fn_801D49E4(s32 a, s32 b, s32 c, s32 d, f32 p1, f32 p2, f32 p3, f32 p4) {
    fn_801D4A2C(a, b, c, lbl_80347568, d, 1.0f, 1.0f, p1, p2, p3, p4);
}

typedef struct {
    s32 idx;
    f32 x, y, w, h;
    u32 colour;
    u8 pad[0x34 - 0x18];
} Elem;

typedef struct {
    f32 pad0;
    f32 u, v, u2, v2;
} Cell; /* 0x14 */

typedef struct {
    Cell* cells;
    Elem* elems;
    u32 count;
    u8 pad[8];
    f32 x, y;
} Layout;

void fn_801D4C9C(Layout* lay, u32 flags, u32 mode, s32* tex, s32 vmode, f32 f1, f32 f2, f32 base, f32 f4, f32 a, f32 b);
void fn_801D4C54(Layout* a, u32 b, u32 c, s32 d, f32 p1, f32 p2, f32 p3, f32 p4) {
    fn_801D4C9C(a, b, c, lbl_80347568, d, 1.0f, 1.0f, p1, p2, p3, p4);
}

void fn_801D4F54(Layout* lay, u32 flags, u32 mode, s32* tex, s32 vmode, f32 f1, f32 f2, f32 base, f32 f4, f32 a, f32 b);
typedef struct {
    u8 pad[0xc];
    s32** tex;
} TexInfo;
typedef struct {
    s32 unused0;
    s32 unused4;
    TexInfo* info;
} TexHolder;
typedef struct {
    f32 x, y, z, u, v;
    u32 colour;
} VertexTex;
extern s32 fn_801E7554(void);
extern s32 fn_80299040(void* p);
extern s32 fn_80297DC8(s32 id);
extern VertexTex lbl_80308E30[4];
extern f32 fn_801DBD9C(f32);
extern void fn_801D65B4(u32 colour, u8* out, f32 a, f32 b);
extern void fn_80291064(VertexTex* v, s32 n, s32 mode);
void fn_801D4C9C(Layout* lay, u32 flags, u32 mode, s32* tex, s32 vmode, f32 f1, f32 f2, f32 base, f32 f4, f32 a, f32 b)
{
    DrawState st;
    u8 col[4];
    u32 oldc;
    s32 i;
    VertexTex* v;
    Cell* c;
    Elem* e;

    if (fn_801E7554() != 0)
        return;
    DrawStateDefault2D(&st);
    st.attr_or |= flags;
    if (mode == 1) {
        st.blend_src = 8;
        st.blend_dst = 10;
    }
    DrawStatePush(&st);
    {
        TexHolder* h = (TexHolder*)tex[0];
        TexHolder* t = *(TexHolder**)((u8*)h + 8);
        fn_80299040(tex);
        fn_80297DC8(**(s32**)((u8*)t + 0xc));
    }
    v = lbl_80308E30;
    for (i = 0; i < lay->count; i++) {
        f32 z = fn_801DBD9C(base + 0.0001f * i);
        e = &lay->elems[i];
        c = &lay->cells[e->idx];
        oldc = e->colour;
        fn_801D65B4(oldc, col, a, b);
        e->colour = (col[0] << 24) + (col[1] << 16) + (col[2] << 8) + col[3];
        v[0].x = lay->x + e->x;
        v[0].y = lay->y + e->y;
        v[0].z = z;
        v[0].u = c->u;
        v[0].v = c->v;
        v[0].colour = e->colour;
        v[2].x = lay->x + e->w;
        v[2].y = v[0].y;
        v[2].z = z;
        v[2].u = c->u2;
        v[2].v = c->v;
        v[2].colour = e->colour;
        v[3].x = v[2].x;
        v[3].y = lay->y + e->h;
        v[3].z = z;
        v[3].u = c->u2;
        v[3].v = c->v2;
        v[3].colour = e->colour;
        v[1].x = v[0].x;
        v[1].y = v[3].y;
        v[1].z = z;
        v[1].u = c->u;
        v[1].v = c->v2;
        v[1].colour = e->colour;
        fn_80291064(v, 4, vmode);
        e->colour = oldc;
    }
    DrawStatePop(0);
    DrawStateRestore();
}

void fn_801D4F0C(Layout* a, u32 b, u32 c, s32 d, f32 p1, f32 p2, f32 p3, f32 p4) {
    fn_801D4F54(a, b, c, lbl_80347568, d, 1.0f, 1.0f, p1, p2, p3, p4);
}

void fn_801D4F54(Layout* lay, u32 flags, u32 mode, s32* tex, s32 vmode, f32 f1, f32 f2, f32 base, f32 f4, f32 a, f32 b)
{
    DrawState st;
    u8 col[4];
    u32 oldc;
    s32 i;
    VertexTex* v;
    Cell* c;
    Elem* e;

    if (fn_801E7554() != 0)
        return;
    DrawStateDefault2D(&st);
    st.attr_or |= flags;
    if (mode == 1) {
        st.blend_src = 8;
        st.blend_dst = 10;
    }
    DrawStatePush(&st);
    {
        TexHolder* h = (TexHolder*)tex[0];
        TexHolder* t = *(TexHolder**)((u8*)h + 8);
        fn_80299040(tex);
        fn_80297DC8(**(s32**)((u8*)t + 0xc));
    }
    v = lbl_80308E30;
    for (i = 0; i < lay->count; i++) {
        f32 z = fn_801DBD9C(base + 0.05f
 * i);
        e = &lay->elems[i];
        c = &lay->cells[e->idx];
        oldc = e->colour;
        fn_801D65B4(oldc, col, a, b);
        e->colour = (col[0] << 24) + (col[1] << 16) + (col[2] << 8) + col[3];
        v[0].x = lay->x + e->x;
        v[0].y = lay->y + e->y;
        v[0].z = z;
        v[0].u = c->u;
        v[0].v = c->v;
        v[0].colour = e->colour;
        v[2].x = lay->x + e->w;
        v[2].y = v[0].y;
        v[2].z = z;
        v[2].u = c->u2;
        v[2].v = c->v;
        v[2].colour = e->colour;
        v[3].x = v[2].x;
        v[3].y = lay->y + e->h;
        v[3].z = z;
        v[3].u = c->u2;
        v[3].v = c->v2;
        v[3].colour = e->colour;
        v[1].x = v[0].x;
        v[1].y = v[3].y;
        v[1].z = z;
        v[1].u = c->u;
        v[1].v = c->v2;
        v[1].colour = e->colour;
        fn_80291064(v, 4, vmode);
        e->colour = oldc;
    }
    DrawStatePop(0);
    DrawStateRestore();
}

void fn_801D51C4(s32 a, s32 b, s32 c, f32 p1, f32 p2, f32 p3, f32 p4) {
    fn_801D5A50(a, b, c, lbl_80347618->sub->val, 1.0f, 1.0f, p1, p2, p3, p4);
}

void fn_801D538C(s32 a, s32 b, s32 c, s32 d, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5, f32 f6);
void fn_801D5210(s32 a, s32 b, s32 c, f32 p1, f32 p2, f32 p3, f32 p4) {
    fn_801D538C(a, b, c, lbl_80347614->sub->val, 1.0f, 1.0f, p1, p2, p3, p4);
}

void fn_801D56C8(s32 a, s32 b, s32 c, s32 d, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5, f32 f6);
void fn_801D525C(s32 a, s32 b, s32 c, f32 p1, f32 p2, f32 p3, f32 p4) {
    fn_801D56C8(a, b, c, lbl_80347614->sub->val, 1.0f, 1.0f, p1, p2, p3, p4);
}

void fn_801D52A8(s32 a, s32 b, s32 c, f32 p1, f32 p2, f32 p3, f32 p4) {
    fn_801D5A50(a, b, c, lbl_80347614->sub->val, 1.0f, 1.0f, p1, p2, p3, p4);
}

extern Outer *lbl_80347610;
void fn_801D5DD8(s32 a, s32 b, s32 c, s32 d, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5, f32 f6);
void fn_801D52F4(s32 a, s32 b, s32 c, f32 p1, f32 p2, f32 p3, f32 p4) {
    fn_801D5DD8(a, b, c, lbl_80347610->sub->val, 1.0f, 1.0f, p1, p2, p3, p4);
}

extern Outer *lbl_8034760C;
void fn_801D5340(s32 a, s32 b, s32 c, f32 p1, f32 p2, f32 p3, f32 p4) {
    fn_801D5DD8(a, b, c, lbl_8034760C->sub->val, 1.0f, 1.0f, p1, p2, p3, p4);
}

void fn_801D668C(void) {
    if (lbl_80347614 != 0) {
        fn_802275A4(lbl_80347614->sub->val, 1);
        fn_801E17E0(lbl_80347614);
        lbl_80347614 = 0;
    }
}

void fn_801D6850(void) {
    if (lbl_80347608 == 0) {
        lbl_80347608 = fn_801E1BDC(0x10000 - 0x600);
    }
    lbl_8034761C = -1;
}

void fn_801D6890(void) {
    if (lbl_80347608 != 0) {
        fn_801E1718(lbl_80347608);
        lbl_80347608 = 0;
    }
}

void fn_801D6944(Thing *t) {
    if (t->f8 != 0) {
        t->f8 = 0;
    }
    if (t->fc != 0) {
        fn_801E17E0(t->fc);
        t->fc = 0;
    }
}

extern s32 lbl_80347634;
void fn_801D71BC(s32 v) {
    lbl_80347634 = v;
}

void fn_801D7868(Quad *q, void *p, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5, f32 f6, f32 f7) {
    q->type = 3;
    q->f04 = f1;
    q->f08 = 1;
    q->f0c = p;
    q->f10 = f2;
    q->f20 = f3;
    q->f14 = f4;
    q->f24 = f5;
    q->f18 = f6;
    q->f28 = f7;
    q->f1c = 0.0f;
    q->f2c = 0.0f;
}

void fn_801D78A8(Quad *q, void *p, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5) {
    f32 a = f2 + f4;
    f32 b = f3 + f5;
    q->type = 4;
    q->f04 = f1;
    q->f08 = 1;
    q->f0c = p;
    q->f10 = f2;
    q->f20 = f3;
    q->f14 = a;
    q->f24 = f3;
    q->f18 = a;
    q->f28 = b;
    q->f1c = f2;
    q->f2c = b;
}

typedef struct Msg {
    s16 x0;
    s16 x2;
    s16 x4;
    s16 x6;
    s32 x8;
    s32 xc;
} Msg;
extern void fn_80291424(Msg*, s16);
void fn_801D8080(Msg* a, s16 i) {
    fn_80291424(a, i);
}

void fn_801D9CF0(f32 f1, f32 f2, f32 f3) {
    lbl_8030E830.f50 = 1;
    lbl_8030E830.f6c = f1;
    lbl_8030E830.f70 = f2;
    lbl_8030E830.f74 = f3;
    fn_802871D8(&lbl_8030E830);
}

s32 fn_801DA66C(Req *p) {
    s32 i = 8;
    Ent *e = lbl_802F65C0;
    do {
        if (p->key == e->key) {
            return e->val;
        }
        e++;
    } while (--i > 0);
    return -1;
}

void fn_801DAE18(RelocTbl *t, u32 off) {
    RelocEnt *e;
    s32 i;
    if (t->ents == 0) {
        return;
    }
    e = (RelocEnt *)((u32)t->ents + off);
    t->ents = e;
    for (i = 0; i < t->count; i++, e++) {
        e->ptr += off;
    }
}

void fn_801DBA0C(void) {
    lbl_80312D00[0] = 0;
    lbl_80312D00[1] = 0;
    lbl_80312D00[2] = 0;
    lbl_80312D00[3] = 0;
    lbl_80312D00[4] = 0;
    lbl_80312D00[5] = 0;
    lbl_80312D00[6] = 0;
    lbl_80312D00[7] = 0;
    lbl_80312D00[8] = 0;
    lbl_80312D00[9] = 0;
    lbl_80312D00[10] = 0;
    lbl_80312D00[11] = 0;
    lbl_80312D00[12] = 0;
    lbl_80312D00[13] = 0;
    lbl_80312D00[14] = 0;
    lbl_80312D00[15] = 0;
}

extern s32 lbl_803476D8;
s32 fn_801DBCCC(void) {
    return lbl_803476D8;
}

void fn_801DBE1C(const char *fmt, ...) {
}

void fn_801DBF90(void) {
}

extern u32 lbl_803476D4;
extern s32 lbl_803475AC;
extern const char lbl_802C4628[];
extern int OSGetResetButtonState(void);
extern void OSReport(const char *msg, ...);
void fn_801DC214(void) {
    int reset = OSGetResetButtonState();
    u32 flags = lbl_803476D4;
    if (flags & 1) {
        if (reset == 0) {
            lbl_803476D4 = flags & ~1u;
            lbl_803476D4 = lbl_803476D4 | 2;
        }
    } else {
        if (reset != 0) {
            int msg =
 lbl_803475AC;
            lbl_803476D4 = flags | 1;
            if (msg != 0) {
                OSReport(lbl_802C4628);
            }
        }
    }
}

void fn_801DC3AC(void) {
    int reset = OSGetResetButtonState();
    u32 flags = lbl_803476D4;
    if (flags & 1) {
        if (reset == 0) {
            lbl_803476D4 = flags & ~1u;
            lbl_803476D4 = lbl_803476D4 | 2;
        }
    } else {
        if (reset != 0) {
            int msg =
 lbl_803475AC;
            lbl_803476D4 = flags | 1;
            if (msg != 0) {
                OSReport(lbl_802C4628);
            }
        }
    }
}

void fn_801DD71C(void *dst) {
    s32 idx;
    if (lbl_8034754C > 0) {
        idx = lbl_8034754C - 1;
        lbl_8034754C = idx;
        if (dst != 0) {
            memcpy(dst, lbl_8030EA1C + idx * 0x40, 0x40);
        }
    }
}

void fn_801DD7CC(void) {
    lbl_8034754C = 0;
}

void fn_801DD95C(void *p)
{
    if (p != 0) {
        fn_801E17E0(p);
    }
}

void fn_801DF94C(Ob *o) {
    fn_801DFA9C(o->p4c, o->s2);
    fn_801E17E0(o);
}

void fn_801E06E0(Mo *o) {
    njPushMatrixEx();
    fn_80286EE8();
    fn_8028B498();
    njUnitMatrix(0);
    fn_801E04E8(&o->m4, o->x48, o->x4c, &o->m2c);
    njPopMatrixEx();
}

void fn_801E0CB8(Mo *o) {
    njPushMatrixEx();
    fn_80286EE8();
    fn_8028B498();
    njUnitMatrix(0);
    fn_801E0AC0(&o->m4, o->x48, o->x4c, &o->m2c);
    njPopMatrixEx();
}

extern char lbl_802C4710[];
extern void fn_801E15FC(void*, void*);
void fn_801E1784(void* p) {
    if (p != 0) {
        if (*(u32*)((u8*)p - 0x10) != 0) {
            fn_801DBE1C(lbl_802C4710, p);
        }
        fn_801E15FC(lbl_802F6748, p);
    }
}

extern char lbl_802C4734[];
void fn_801E17E0(void* p) {
    if (p != 0) {
        if (*(u32*)((u8*)p - 0x10) != 0) {
            fn_801DBE1C(lbl_802C4734, p);
        }
        fn_801E15FC(lbl_802F6748, p);
    }
}

void fn_801E1A2C(void *src, u32 n) {
    void *q;
    if (n == 0) {
        n = 0x20;
    }
    q = fn_801E184C(lbl_802F6748, -1, src, n);
    *(u32 *)((u8 *)q - 0x10) = 0;
}

void fn_801D23E0(void)
{
    fn_8024DF5C(0x10000 - 0x115);
    GXClearGPMetric();
    GXInvalidateVtxCache();
    GXInvalidateTexAll();
}

void fn_801D4954(void *p)
{
    if (p != 0) {
        fn_801E17E0(p);
    }
}

void fn_801D61C4(void *p)
{
    if (p != lbl_80311B00) {
        fn_801E1718(p);
    }
}

void *fn_801D665C(void)
{
    lbl_8034761C = lbl_8034761C + 1;
    if ((u32)lbl_8034761C > 0x7cf) {
        lbl_8034761C = 0;
    }
    return lbl_80347608 + (lbl_8034761C << 5);
}

void fn_801D7A08(u8 *p, f32 a, f32 b)
{
    *(f32 *)(p + 0x44) = a;
    *(f32 *)(p + 0x48) = b;
}

void fn_801D7A14(u8 *p, f32 a, f32 b, f32 c, f32 d)
{
    *(f32 *)(p + 0x34) = a;
    *(f32 *)(p + 0x38) = b;
    *(f32 *)(p + 0x3c) = c;
    *(f32 *)(p + 0x40) = d;
}

void fn_801D8818(void *a, s32 b, s32 c, s32 d, s32 e)
{
    fn_801D843C(a, b, c, d, 0, e);
}

void *fn_801D8D18(void)
{
    u8 *p = lbl_80347654;
    if (p[0x19] == 7) {
        return *(void **)(*(u8 **)(p + 0x24) + 4);
    }
    return (void *)-1;
}

void fn_801D8D3C(void)
{
    u8 *p = lbl_80347660;
    if (p != 0) {
        p[0x19] = 10;
    }
}

s32 fn_801D8EE8(void)
{
    u8 *p = lbl_80347660;
    if (p[0x19] == 10) {
        return *(s8 *)(*(u8 **)(p + 0x24) + 1);
    }
    return *(s8 *)(*(u8 **)(p + 0x24) + 5);
}

void fn_801DBA58(u32 a, u32 b, u32 c)
{
    lbl_80312D40[0] = a;
    lbl_80312D40[1] = b;
    lbl_80312D40[2] = c;
    lbl_80312D40[3] = c;
}

void fn_801DD984(void)
{
    fn_801E1A74(0x14, 1);
}

void fn_801E0D50(u32 *dst, u32 *src, s32 size)
{
    u32 t;
    s32 n = size / 4;
    do {
        t = *dst;
        *dst++ = *src;
        *src++ = t;
        n--;
    } while (n != 0);
}

s32 fn_801E183C(void)
{
    return lbl_80347550 == 0;
}

void fn_801E0D0C(char *s)
{
    if (s == NULL) {
        return;
    }
    for (; *s != 0; s++) {
        if (*s >= 'A' && *s <= 'Z') {
            *s += 0x20;
        }
    }
}

s32 fn_801D6DE8(s32 a, s32 n)
{
    Obj_80311C30 *o = &lbl_80311C30;

    if (o->active == 0) {
        return -2;
    }
    n = (n + 1) * 250;
    o->x14 = OSMillisecondsToTicks(n);
    return 0;
}

/* same loop as fn_801DA66C, inlined */
inline s16 EntFindVal(ReqB *p) {
    s32 i = 8;
    Ent *e = lbl_802F65C0;
    do {
        if (p->u.key == e->key) {
            return e->val;
        }
        e++;
    } while (--i > 0);
    return -1;
}

void *fn_801DA484(ReqB *p) {
    if (EntFindVal(p) < 0) {
        return p->next;
    }
    return p->next;
}

void *fn_801DA4D0(ReqB *p) {
    if (EntFindVal(p) < 0) {
        return p->u.obj;
    }
    return 0;
}

inline void Draw2(Node* n)
{
    BODY(n)
    if (n->child != 0) {
        fn_801D25DC(n->child);
    }
    njPopMatrixEx();
    if (n->next != 0) {
        fn_801D25DC(n->next);
    }
}

inline void Draw1(Node* n)
{
    BODY(n)
    if (n->child != 0) {
        Draw2(n->child);
    }
    njPopMatrixEx();
    if (n->next != 0) {
        Draw2(n->next);
    }
}

void fn_801D25DC(Node* n)
{
    BODY(n)
    if (n->child != 0) {
        Draw1(n->child);
    }
    njPopMatrixEx();
    if (n->next != 0) {
        Draw1(n->next);
    }
}

s32 fn_801D30DC(NJS_POINT3* p, Node_801D30DC* n, Hit* out)
{
    Mesh* m;
    s32 cnt;
    s32 tri;
    Vtx* r;
    f32 *va, *vb, *vc;
    f32* base;
    s32 hit;
    f32 loc[2];
    NJS_POINT3 q;
    f32 nrm[3];

    hit = 0;
    njPushMatrixEx();
    fn_80286EE8();
    fn_8028B498();
    njTranslateEx(n->pos);
    njRotateEx(n->rot, 0);
    njScaleEx(n->scl);
    m = n->mesh;
    if (m != 0) {
        cnt = m->count;
        if (cnt > 0) {
            njPushMatrixEx();
            fn_80286EE8();
            fn_8028B498();
            njInvertMatrix(0);
            njCalcPoint(0, p, &q);
            njPopMatrixEx();
            loc[0] = q.x - m->cx;
            loc[1] = q.z - m->cz;
            if (m->r2 >= loc[0] * loc[0] + loc[1] * loc[1]) {
                loc[0] = q.x;
                loc[1] = q.z;
                r = (Vtx*)((u8*)m + 0x58);
                base = m->verts;
                do {
                    tri = r->idx - 2;
                    r++;
                    do {
                        s16 fl = r[2].flag;
                        s32 i1 = r[1].idx;
                        s32 i0 = r[0].idx;
                        s32 i2 = r[2].idx;
                        vb = (f32*)((u8*)base + (i1 << 2));
                        if (fl < 0) {
                            va = (f32*)((u8*)base + (i2 << 2));
                            vc = (f32*)((u8*)base + (i0 << 2));
                        } else {
                            va = (f32*)((u8*)base + (i0 << 2));
                            vc = (f32*)((u8*)base + (i2 << 2));
                        }
                        hit = fn_801D48BC(loc, va, vb, vc);
                        if (hit != 0) {
                            fn_80290668(va, vb, vc, nrm);
                            if (-0.0001f > nrm[0] * (loc[0] - va[0]) + nrm[1] * (q.y - va[1]) + nrm[2] * (loc[1] - va[2])) {
                                hit = 0;
                            } else {
                                break;
                            }
                        }
                        r++;
                    } while (--tri > 0 && hit == 0);
                    if (hit != 0) {
                        if (out != 0) {
                            njCalcPoint(0, (NJS_POINT3*)va, &out->a);
                            njCalcPoint(0, (NJS_POINT3*)vb, &out->b);
                            njCalcPoint(0, (NJS_POINT3*)vc, &out->c);
                            out->id = n->id;
                            out->flag = r[2].flag & 0x7FFF;
                        }
                        break;
                    }
                    r += 2;
                } while (--cnt > 0 && hit == 0);
            }
        }
    }
    if (n->child != 0 && hit == 0) {
        hit = fn_801D30DC(p, n->child, out);
    }
    njPopMatrixEx();
    if (n->next != 0 && hit == 0) {
        hit = fn_801D30DC(p, n->next, out);
    }
    return hit;
}

void fn_801D8F18(void) {
    s32 i;
    lbl_8034765C->b0 = 0;
    lbl_8034765C->b1 = 0;
    lbl_8034765C->b2 = 0;
    lbl_8034765C->b3 = 0;
    lbl_8034765C->b4 = 0;
    lbl_8034765C->b5 = -1;
    lbl_8034765C->wc = -1;
    lbl_8034765C->w244 = 0;
    fn_801D89D4(&lbl_8034765C->a0, 10, 0, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    for (i = 0; i < 3; i++) {
        fn_801D89D4(&lbl_8034765C->a[i], 10, 0, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f);
        fn_801D89D4(&lbl_8034765C->b[i], 1, 0, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f);
        lbl_80311DF0[i] = 1.0f;
    }
    if (fn_801A3510() == 1) {
        lbl_8034765C->b3 = 1;
        fn_801D8AB4(&lbl_8034765C->b[1], 1, 0, 1.0f, 1.0f);
        lbl_80311DF0[1] = 1.0f;
        if (lbl_8034765C->b7 == 0) lbl_8034765C->b1 = 1;
        lbl_8034765C->b7 = 1;
    } else {
        lbl_8034765C->b3 = 0;
        lbl_8034765C->b7 = 0;
        fn_801D8AB4(&lbl_8034765C->b[1], 1, 0, 0.7f, 0.7f);
        lbl_80311DF0[1] = 0.7f;
    }
    if (lbl_8034765C->b3 == 1) lbl_8034765C->b1 = 1;
    lbl_8034765C->b4 = 0;
    lbl_8034765C->b6 = 1;
    if (lbl_8034765C->b3 == 1) {
        lbl_8034765C->b7 = 1;
    } else {
        lbl_8034765C->b7 = 0;
        fn_801D8AB4(&lbl_8034765C->b[1], 1, 0, 0.7f, 0.7f);
        lbl_80311DF0[1] = 0.7f;
    }
    if (lbl_8034765C->b4 == 1) {
        lbl_8034765C->b8 = 1;
    } else {
        lbl_8034765C->b8 = 0;
        fn_801D8AB4(&lbl_8034765C->b[2], 1, 0, 0.7f, 0.7f);
        lbl_80311DF0[2] = 0.7f;
    }
    lbl_8034765C->w10 = 2;
}

s32 fn_801D91F4(void) {
    s16 i;
    s32 sel;
    if (fn_801A3510() == 1) {
        (*(State801D_801D91F4**)&lbl_8034765C)->b[3] = 1;
        fn_801D8AB4(&(*(State801D_801D91F4**)&lbl_8034765C)->anim[0x190], 1, 0, 1.0f, 1.0f);
        lbl_80311DF0[1] = 1.0f;
        if ((*(State801D_801D91F4**)&lbl_8034765C)->b[7] == 0) (*(State801D_801D91F4**)&lbl_8034765C)->b[1] = 1;
        (*(State801D_801D91F4**)&lbl_8034765C)->b[7] = 1;
    } else {
        (*(State801D_801D91F4**)&lbl_8034765C)->b[3] = 0;
        (*(State801D_801D91F4**)&lbl_8034765C)->b[7] = 0;
        fn_801D8AB4(&(*(State801D_801D91F4**)&lbl_8034765C)->anim[0x190], 1, 0, 0.7f, 0.7f);
        lbl_80311DF0[1] = 0.7f;
    }
    (*(State801D_801D91F4**)&lbl_8034765C)->b[5] = -1;
    if (lbl_80311A60.pad->x8 & 0x100) {
        lbl_80347658 = SePlay(1, 1, 2);
        sel = (*(State801D_801D91F4**)&lbl_8034765C)->b[1];
        switch (sel) {
        case 0:
            return sel;
        case 1:
            return sel;
        case 2:
            return sel;
        default:
            (*(State801D_801D91F4**)&lbl_8034765C)->b[5] = -2;
            break;
        }
    } else if (lbl_80311A60.pad->x8 & 8) {
        lbl_80347658 = SePlay(1, 1, 0);
        if ((*(State801D_801D91F4**)&lbl_8034765C)->b[1] > 0) (*(State801D_801D91F4**)&lbl_8034765C)->b[1]--;
        else (*(State801D_801D91F4**)&lbl_8034765C)->b[1] = (*(State801D_801D91F4**)&lbl_8034765C)->w10;
        if ((*(State801D_801D91F4**)&lbl_8034765C)->b[(*(State801D_801D91F4**)&lbl_8034765C)->b[1] + 6] == 0) {
            for (i = 0; i < 3; i++) {
                if ((*(State801D_801D91F4**)&lbl_8034765C)->b[1] > 0) (*(State801D_801D91F4**)&lbl_8034765C)->b[1]--;
                else (*(State801D_801D91F4**)&lbl_8034765C)->b[1] = (*(State801D_801D91F4**)&lbl_8034765C)->w10;
                if ((*(State801D_801D91F4**)&lbl_8034765C)->b[(*(State801D_801D91F4**)&lbl_8034765C)->b[1] + 6] == 1) break;
            }
        }
        (*(State801D_801D91F4**)&lbl_8034765C)->b[5] = -2;
    } else if (lbl_80311A60.pad->x8 & 4) {
        lbl_80347658 = SePlay(1, 1, 0);
        if ((*(State801D_801D91F4**)&lbl_8034765C)->b[1] < (*(State801D_801D91F4**)&lbl_8034765C)->w10) (*(State801D_801D91F4**)&lbl_8034765C)->b[1]++;
        else (*(State801D_801D91F4**)&lbl_8034765C)->b[1] = 0;
        if ((*(State801D_801D91F4**)&lbl_8034765C)->b[(*(State801D_801D91F4**)&lbl_8034765C)->b[1] + 6] == 0) {
            for (i = 0; i < 3; i++) {
                if ((*(State801D_801D91F4**)&lbl_8034765C)->b[1] < (*(State801D_801D91F4**)&lbl_8034765C)->w10) (*(State801D_801D91F4**)&lbl_8034765C)->b[1]++;
                else (*(State801D_801D91F4**)&lbl_8034765C)->b[1] = 0;
                if ((*(State801D_801D91F4**)&lbl_8034765C)->b[(*(State801D_801D91F4**)&lbl_8034765C)->b[1] + 6] == 1) break;
            }
        }
        (*(State801D_801D91F4**)&lbl_8034765C)->b[5] = -2;
    }
    if ((*(State801D_801D91F4**)&lbl_8034765C)->b[(*(State801D_801D91F4**)&lbl_8034765C)->b[1] + 6] == 0) (*(State801D_801D91F4**)&lbl_8034765C)->b[1] = 0;
    return (*(State801D_801D91F4**)&lbl_8034765C)->b[5];
}

inline void NodeFixSelf(Node801D* n) {
    Inner* p;
    if (n->a != 0) {
        p = (Inner*)((u8*)n->a + (u32)n);
        n->a = p;
        if (p->x10 != 0) {
            p->x10 += (u32)p + 0x10;
        }
    }
}

inline void NodeFix3(Node801D* n) {
    Node801D* c;
    NodeFixSelf(n);
    c = n->c1;
    if (c != 0) {
        n->c1 = (Node801D*)((u32)n + 0x2c + (u32)c);
        fn_801DA748(n->c1);
    }
    c = n->c2;
    if (c != 0) {
        n->c2 = (Node801D*)((u32)n + 0x30 + (u32)c);
        fn_801DA748(n->c2);
    }
}

inline void NodeFix2(Node801D* n) {
    Node801D* c;
    NodeFixSelf(n);
    c = n->c1;
    if (c != 0) {
        n->c1 = (Node801D*)((u32)n + 0x2c + (u32)c);
        NodeFix3(n->c1);
    }
    c = n->c2;
    if (c != 0) {
        n->c2 = (Node801D*)((u32)n + 0x30 + (u32)c);
        NodeFix3(n->c2);
    }
}

void fn_801DA748(Node801D* n) {
    Node801D* c;
    NodeFixSelf(n);
    c = n->c1;
    if (c != 0) {
        n->c1 = (Node801D*)((u32)n + 0x2c + (u32)c);
        NodeFix2(n->c1);
    }
    c = n->c2;
    if (c != 0) {
        n->c2 = (Node801D*)((u32)n + 0x30 + (u32)c);
        NodeFix2(n->c2);
    }
}

inline void CountNode(Node801DF6* n, s32* count, s32* total) {
    s32 v;
    if (!(n->flags & 8) && n->d != 0) {
        v = fn_801CB1AC(n->d->x0);
        if (v != 0) {
            *total += v;
            *count += 1;
        }
    }
}

inline void CountNode3(Node801DF6* n, s32* count, s32* total) {
    CountNode(n, count, total);
    if (n->c1 != 0 && !(n->flags & 0x10)) fn_801DF600(n->c1, count, total);
    if (n->c2 != 0) fn_801DF600(n->c2, count, total);
}

inline void CountNode2(Node801DF6* n, s32* count, s32* total) {
    Node801DF6* c;
    CountNode(n, count, total);
    c = n->c1;
    if (c != 0 && !(n->flags & 0x10)) CountNode3(c, count, total);
    c = n->c2;
    if (c != 0) CountNode3(c, count, total);
}

void fn_801DF600(Node801DF6* n, s32* count, s32* total) {
    Node801DF6* c;
    CountNode(n, count, total);
    c = n->c1;
    if (c != 0 && !(n->flags & 0x10)) CountNode2(c, count, total);
    c = n->c2;
    if (c != 0) CountNode2(c, count, total);
}

void fn_801E0204(Hit801E* hit, Ref801E* ref, f32* mtx, Box801E* box) {
    NJS_POINT3 p;
    NJS_POINT3 q;
    NJS_VECTOR v;
    f32 s;
    njCalcPoint(NULL, &hit->pos, &p);
    if (p.x > box->min.x && p.y > box->min.y && p.z > box->min.z && p.x < box->max.x && p.y < box->max.y &&
        p.z < box->max.z) {
        fn_802900C0(&p, &ref->c, &q);
        v.x = q.x - ref->c.x;
        v.y = q.y - ref->c.y;
        v.z = q.z - ref->c.z;
        hit->dist = fn_80291A5C(v.x * v.x + v.y * v.y + v.z * v.z);
        v.x = p.x - q.x;
        v.y = p.y - q.y;
        v.z = p.z - q.z;
        if (v.x == 0.0f && v.y == 0.0f && v.z == 0.0f) {
            v.x = ref->d.x;
            v.y = ref->d.y;
            v.z = ref->d.z;
        }
        njUnitVector(&v);
        njCalcVector(mtx, &v, &hit->dir);
    } else if (box->flag == 0.0f) {
        hit->dir.z = 0.0f;
        hit->dir.y = 0.0f;
        hit->dir.x = 0.0f;
    } else {
        s = fn_801DFE48(&p, box);
        if (s == 0.0f) {
            hit->dir.z = 0.0f;
            hit->dir.y = 0.0f;
            hit->dir.x = 0.0f;
        } else {
            fn_802900C0(&p, &ref->c, &q);
            v.x = q.x - ref->c.x;
            v.y = q.y - ref->c.y;
            v.z = q.z - ref->c.z;
            hit->dist = fn_80291A5C(v.x * v.x + v.y * v.y + v.z * v.z);
            v.x = p.x - q.x;
            v.y = p.y - q.y;
            v.z = p.z - q.z;
            if (v.x == 0.0f && v.y == 0.0f && v.z == 0.0f) {
                v.x = ref->d.x;
                v.y = ref->d.y;
                v.z = ref->d.z;
            }
            njUnitVector(&v);
            v.x *= s;
            v.y *= s;
            v.z *= s;
            njCalcVector(mtx, &v, &hit->dir);
        }
    }
}

static inline void ClearWork(DataTable *t)
{
    s32 i;
    for (i = 0; i < t->count; i++) {
        t->work[i] = 0;
    }
}

static inline void Relocate(DataTable *t)
{
    DataEntry *e;
    s32 i;
    for (i = 0; i < t->count; i++) {
        e = (DataEntry *)(t->base + t->offsets[i]);
        e->base = t->base;
        e->offset += (s32)t->data;
    }
}

void fn_801D6A74(DataTable *t, s32 id)
{
    t->data = fn_8022ACA8(id);
    t->count = t->data[0];
    t->base = (u8 *)t->data + (t->count + 1) * 4;
    t->offsets = t->data + 1;
    t->work = fn_801E1C7C(t->count * 4);
    ClearWork(t);
    Relocate(t);
}
