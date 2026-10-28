/* Quad, billboard and model drawing helpers (0x80032E78 - 0x80035918). Screen-space quads
 * (Quad2D: four 2D corners, ARGB colours, uv), billboards (Billboard: a camera-facing quad at a
 * world position, uv corners from lbl_802DC178), coloured/textured 3D quads built in a QuadBuf,
 * and model draws through the fn_801CEExx / fn_801CF0xx families picked by a mode byte
 * (2, 4, 1, 0). An object's texlist entries can be swapped to the front around a draw.
 * lbl_8034674C and lbl_80346748 are the draw flags these pass on (fn_800358F8 - fn_80035910). */
#include "types.h"
#include "ninja.h"
#include "game/drawstate.h"

typedef struct {
    f32 x, y;
} NJS_POINT2;

typedef struct {
    f32 x, y, z, u, v;
    u32 colour;
} VertexTex;

typedef struct {
    f32 x, y, z;
    u32 colour;
} VertexCol;

typedef struct {
    u8 c[4];
} Col4;

typedef struct {
    s16 u, v;
} UV;

/* An ARGB colour, as bytes or as one word. */
typedef union {
    struct {
        u8 a, r, g, b;
    } c;
    u32 argb;
} ColARGB;

/* A screen quad (fn_800331CC, fn_800333A0). */
typedef struct {
    NJS_POINT2 p[4];    /* 0x00 */
    u8 pad20[8];
    ColARGB col[4];     /* 0x28 */
    NJS_POINT2 uv[4];   /* 0x38 */
    u8 pad58[8];
} Quad2D;

/* fn_80034690's quad has no tail (its frame only fits 0x58 bytes). */
typedef struct {
    NJS_POINT2 p[4];    /* 0x00 */
    u8 pad20[8];
    ColARGB col[4];     /* 0x28 */
    NJS_POINT2 uv[4];   /* 0x38 */
} Quad_80034690;

/* Quad corner arrays: positions, colours, 8-bit-scaled s16 (u, v) pairs. */
typedef struct {
    NJS_POINT3* pos;
    u32* col;
    s16* uv;
    s32 count;
} QuadBuf;

/* A model object: model, texlist, transform, draw mode. */
typedef struct {
    void* model;        /* 0x00 */
    u8 pad4[4];
    NJS_TEXLIST* texlist; /* 0x08 */
    u8 padC[0x1C - 0xC];
    NJS_POINT3 pos;     /* 0x1C */
    Angle ang[3];       /* 0x28 */
    NJS_POINT3 scl;     /* 0x34 */
    u8 pad40[4];
    u8 kind;            /* 0x44 */
} DrawObj;

typedef struct {
    u8 type;            /* 0x00 */
    u8 pad1[3];
    NJS_POINT3 pos;     /* 0x04 */
    NJS_POINT3 pos2;    /* 0x10 */
    u8 pad1c[0x28 - 0x1C];
    f32 w;              /* 0x28 */
    f32 h;              /* 0x2C */
    Angle roll;         /* 0x30 */
    s16 id;             /* 0x34 */
    u8 pad36[0x3C - 0x36];
    u8 col[4][4];       /* 0x3C */
    void* tex;          /* 0x4C */
} Billboard; /* 0x50 */

/* A 3D quad: four corners, colours, uv. */
typedef struct {
    u8 pad0[4];
    NJS_POINT3 pos[4];  /* 0x04 */
    s16 id;             /* 0x34 */
    u8 pad36[6];
    Col4 col[4];        /* 0x3C */
    UV uv[4];           /* 0x4C */
    void* data;         /* 0x5C */
} Quad3D;

/* A screen rectangle. */
typedef struct {
    s16 x0, y0, x1, y1; /* 0x00 */
    s16 id;             /* 0x08 */
    u8 pad0a[6];
    Col4 col[4];        /* 0x10 */
    UV uv[4];           /* 0x20 */
    void* data;         /* 0x30 */
} Rect2D;

typedef struct {
    f32* in;
    s32* mid;
    s32* out;
    s32 n;
} Args;

typedef struct {
    s32 i[4];
} Order;

typedef struct {
    s16 v[8];
} Rect8;

typedef struct {
    u8 pad0[0x10];
    f32 alpha;          /* 0x10 */
    f32 w;              /* 0x14 */
    f32 h;              /* 0x18 */
    u8 pad1c[4];
    f32 z;              /* 0x20 */
    s16 mode;           /* 0x24 */
    s16 blendSrc;       /* 0x26 */
    s16 blendDst;       /* 0x28 */
} Fade;

typedef struct {
    DrawObj* obj;       /* 0x00 */
    void* a;            /* 0x04 */
    void* b;            /* 0x08 */
    f32 f;              /* 0x0C */
    f32 alpha;          /* 0x10 */
    f32 sx, sy, sz;     /* 0x14 */
} Disp;

#define PACK(k) (((k).c[0] << 24) | ((k).c[1] << 16) | ((k).c[2] << 8) | (k).c[3])

extern Order lbl_802AD210;
extern Rect8 lbl_802DC138[4];
extern f32 lbl_802DC178[4][8];
extern struct { u8 pad[0x6c]; u32 flags; } lbl_8030A10C;
extern struct { u8 pad[0x18]; f32 z; } lbl_803118AC;
extern s32 lbl_80346748;
extern s32 lbl_8034674C;
extern NJS_TEXLIST lbl_80347568;

extern void* memset(void*, int, unsigned long);
extern void njPushMatrixEx(void);
extern void njPopMatrixEx(void);
extern void njTranslate(NJS_MATRIX m, f32 x, f32 y, f32 z);
extern void njScale(NJS_MATRIX m, f32 x, f32 y, f32 z);
extern void njRotateZXY(NJS_MATRIX m, Angle x, Angle y, Angle z);
extern void njMultiMatrix(NJS_MATRIX m, NJS_MATRIX src);
extern void fn_80012130(NJS_POINT3* v);
extern void fn_8001E138(Angle* ang, NJS_POINT3* pos, NJS_MATRIX m);
extern void fn_8002F448(void);
extern s32 fn_8002F46C(DrawState* s, s32* flag);
extern s32 fn_8002F52C(void);
extern void fn_80040044(DrawState* s, f32 alpha, u32 mask, u8* flag);
extern void fn_800614FC(Angle* src, Angle* dst);
extern void fn_80061518(NJS_POINT3* pos, NJS_POINT3* dst, NJS_MATRIX m);
extern void fn_80061F3C(NJS_POINT3* src, NJS_POINT3* dst);
extern void fn_80071CF0(NJS_POINT3* src, NJS_POINT3* dst);
extern void fn_80071F84(Angle* rot, NJS_POINT3* pos, NJS_POINT3* src);
extern void fn_801CD118(void* data, s16 id, VertexTex* v, s32 n, s32 a, s32 flags);
extern void fn_801CD73C(VertexCol* v, s32 n, s32 a, s32 flags);
extern void fn_801CE1A4(VertexCol* v, s32 n, s32 a, s32 flags);
extern void fn_801CE6D0(void* tex, s32 id, VertexTex* v, s32 n, s32 a, s32 flags);
extern void fn_801CED24(void* model, void* a, void* b, f32 f, s32 v);
extern void fn_801CED60(void* model, void* a, void* b, f32 f, s32 v);
extern void fn_801CED9C(void* model, void* a, void* b, f32 f, s32 v);
extern void fn_801CEDD8(void* model, void* a, void* b, f32 f, s32 v);
extern void fn_801CEE14(void* model, void* a, f32 f, s32 v);
extern void fn_801CEE4C(void* model, void* a, f32 f, s32 v);
extern void fn_801CEE84(void* model, void* a, f32 f, s32 v);
extern void fn_801CEEBC(void* model, void* a, f32 f, s32 v);
extern void fn_801CEEF4(void* model, void* a, void* b, f32 f, s32 v);
extern void fn_801CEF30(void* model, void* a, void* b, f32 f, s32 v);
extern void fn_801CEF6C(void* model, void* a, void* b, f32 f, s32 v);
extern void fn_801CEFA8(void* model, void* a, void* b, f32 f, s32 v);
extern void fn_801CEFE4(void* model, void* a, f32 f, s32 v);
extern void fn_801CF020(void* model, void* a, f32 f, s32 v);
extern void fn_801CF058(void* model, void* a, f32 f, s32 v);
extern void fn_801CF090(void* model, void* a, f32 f, s32 v);
extern void fn_801CF0C8(void* model, s32 v);
extern void fn_801CF0F8(void* model, s32 v);
extern void fn_801CF128(void* model, s32 v);
extern void fn_801CF158(void* model, s32 v);
extern f32 fn_801DBD9C(f32 z);
extern void fn_801DBCD4(void);
extern NJS_POINT3 fn_801DCDC0(f32 x, f32 y, f32 z);
extern void* fn_801E1A74(s32 size, s32 n);
extern void fn_801E17E0(void* p);
extern void fn_80286EE8(void);
extern void fn_80289EC8(f32* pts, s32 n);
extern void fn_8028A054(void);
extern void fn_8028A058(u32 color, s32 a, f32 width);
extern void fn_8028A8C0(VertexTex* v, s32 count, s32 flag);
extern void fn_8028B498(void);
extern void fn_80290ED4(VertexCol* v, s32 count, s32 flag);
extern void fn_80291064(VertexTex* v, s32 count, s32 mode);
extern void fn_802947CC(s32);
extern void fn_80297DC8(void* tex);
extern void fn_80298FE4(s32 i);
extern void fn_80299040(NJS_TEXLIST* t);
extern void fn_802AA2F0(Args*, s32, s32);

void fn_80033A18(Billboard* o, s16 idx, NJS_MATRIX m, s8 level);
void fn_80033EA0(QuadBuf* q, f32 w, f32 h, Billboard* s, u8 mode);
void fn_80035708(void* tex, s32 id, QuadBuf* src, s32 textured);

void fn_80032E78(s32 blend, DrawObj* o, s16 x, NJS_MATRIX m, s16 idx, s8 level, f32 f) {
    DrawState st;
    Billboard q;
    s16 al;
    DrawStateDefault2D(&st);
    if (blend != 0) {
        st.blend_src = 8;
        st.blend_dst = 10;
    }
    if (DrawStatePush(&st) != 0) {
        memset(&q, 0, sizeof(q));
        q.w = o->scl.x;
        q.h = o->scl.x;
        q.tex = o->texlist;
        if (x < 0) x = 0;
        q.id = x;
        q.roll = o->ang[2];
        fn_80071CF0(&o->pos, &q.pos);
        fn_80012130(&q.pos2);
        al = (s16)(s32)(255.0f * f);
        q.col[0][0] = al + 255;
        q.col[0][1] = 255;
        q.col[0][2] = 255;
        q.col[0][3] = 255;
        q.col[1][0] = al + 255;
        q.col[1][1] = 255;
        q.col[1][2] = 255;
        q.col[1][3] = 255;
        q.col[2][0] = al + 255;
        q.col[2][1] = 255;
        q.col[2][2] = 255;
        q.col[2][3] = 255;
        q.col[3][0] = al + 255;
        q.col[3][1] = 255;
        q.col[3][2] = 255;
        q.col[3][3] = 255;
        fn_80033A18(&q, idx, m, level);
        DrawStatePop(NULL);
    }
}

void fn_80032FC4(NJS_POINT3* a, NJS_POINT3* b, s32* c, s32* d) {
    f32 in[6];
    s32 mid[2];
    s32 out[2];
    Args args;
    args.in = in;
    args.mid = mid;
    args.out = out;
    args.n = 2;
    in[0] = a->x;
    in[1] = a->y;
    in[2] = a->z;
    in[3] = b->x;
    in[4] = b->y;
    in[5] = b->z;
    mid[0] = *c;
    mid[1] = *d;
    fn_802AA2F0(&args, 2, 0x40);
}

void fn_80033050(Quad3D* o) {
    Order order = lbl_802AD210;
    VertexTex v[4];
    s32* ip;
    VertexTex* pv;
    s32 n;
    pv = v;
    ip = order.i;
    for (n = 0; n < 4; n++) {
        s32 i = *ip;
        pv->x = o->pos[i].x;
        pv->y = o->pos[i].y;
        pv->z = o->pos[i].z;
        pv->u = 0.003921569f * o->uv[i].u;
        pv->v = 0.003921569f * o->uv[i].v;
        pv->colour = PACK(o->col[i]);
        pv++;
        ip++;
    }
    fn_801CE6D0(o->data, o->id, v, 4, 1, lbl_8034674C);
}

void fn_8003316C(Quad3D* o) {
    QuadBuf q;
    q.pos = o->pos;
    q.col = (u32*)o->col;
    fn_80035708(o->data, o->id, &q, 0);
}

void fn_800331B0(u32* p) {
    p[0] = 0x00F00F00;
    p[1] = 0x94062000;
}

void fn_800331CC(Quad2D* q, f32 d, s8 mode) {
    VertexTex v2[4];
    VertexCol v3[4];
    f32 scale;
    s32 flag = 0;
    s32 i;
    NJS_POINT3 p;
    VertexCol* pv3;
    VertexTex* pv2;
    scale = -1.0f / d;
    if (scale > -1.1f) scale = -1.1f;
    if (mode == 1) flag = 1;
    if (mode == 2) {
        pv3 = v3;
        for (i = 0; i < 4; i++) {
            p = fn_801DCDC0(q->p[i].x, q->p[i].y, scale);
            pv3->x = p.x;
            pv3->y = p.y;
            pv3->z = p.z;
            pv3->colour = (q->col[i].c.a << 24) | (q->col[i].c.r << 16) | (q->col[i].c.g << 8) | q->col[i].c.b;
            if (q->col[i].c.a < 0xff) flag = 1;
            pv3++;
        }
        fn_80290ED4(v3, 4, flag);
    } else {
        pv2 = v2;
        for (i = 0; i < 4; i++) {
            p = fn_801DCDC0(q->p[i].x, q->p[i].y, scale);
            pv2->x = p.x;
            pv2->y = p.y;
            pv2->z = p.z;
            pv2->u = q->uv[i].x;
            pv2->v = q->uv[i].y;
            pv2->colour = (q->col[i].c.a << 24) | (q->col[i].c.r << 16) | (q->col[i].c.g << 8) | q->col[i].c.b;
            if (q->col[i].c.a < 0xff) flag = 1;
            pv2++;
        }
        fn_80297DC8((void*)0x1869E);
        njPushMatrixEx();
        fn_80286EE8();
        fn_8028B498();
        njUnitMatrix(0);
        fn_8028A8C0(v2, 4, flag);
        njPopMatrixEx();
    }
}

void fn_800333A0(Quad2D* q, f32 z) {
    VertexTex v[4];
    f32 zz;
    s32 i;
    fn_80299040(&lbl_80347568);
    fn_80297DC8((void*)0x1869E);
    zz = fn_801DBD9C(z);
    for (i = 0; i < 4; i++) {
        v[i].x = q->p[i].x;
        v[i].y = q->p[i].y;
        v[i].z = zz;
        v[i].u = q->uv[i].x;
        v[i].v = q->uv[i].y;
        v[i].colour = q->col[i].argb;
    }
    fn_80291064(v, 4, 1);
}

void fn_800334B8(Rect2D* o) {
    f32 z;
    f32 x0, y0, x1, y1;
    if (lbl_8030A10C.flags & 0x20000) z = 100.0f;
    else z = 99.98f;
    if (o->data != NULL) {
        VertexTex v[4];
        v[0].x = x0 = o->x0;
        v[0].y = y0 = o->y0;
        v[0].z = z;
        v[0].u = 0.003921569f * o->uv[0].u;
        v[0].v = 0.003921569f * o->uv[0].v;
        v[0].colour = PACK(o->col[0]);
        v[1].x = x0;
        v[1].y = y1 = o->y1;
        v[1].z = z;
        v[1].u = 0.003921569f * o->uv[3].u;
        v[1].v = 0.003921569f * o->uv[3].v;
        v[1].colour = PACK(o->col[1]);
        v[2].x = x1 = o->x1;
        v[2].y = y0;
        v[2].z = z;
        v[2].u = 0.003921569f * o->uv[1].u;
        v[2].v = 0.003921569f * o->uv[1].v;
        v[2].colour = PACK(o->col[2]);
        v[3].x = x1;
        v[3].y = y1;
        v[3].z = z;
        v[3].u = 0.003921569f * o->uv[2].u;
        v[3].v = 0.003921569f * o->uv[2].v;
        v[3].colour = PACK(o->col[3]);
        fn_801CD118(o->data, o->id, v, 4, 1, lbl_8034674C);
    } else {
        VertexCol v[4];
        v[0].x = x0 = o->x0;
        v[0].y = y0 = o->y0;
        v[0].z = z;
        v[0].colour = PACK(o->col[0]);
        v[1].x = x0;
        v[1].y = y1 = o->y1;
        v[1].z = z;
        v[1].colour = PACK(o->col[1]);
        v[2].x = x1 = o->x1;
        v[2].y = y0;
        v[2].z = z;
        v[2].colour = PACK(o->col[2]);
        v[3].x = x1;
        v[3].y = y1;
        v[3].z = z;
        v[3].colour = PACK(o->col[3]);
        fn_801CD73C(v, 4, 1, lbl_8034674C);
    }
}

void fn_80033888(s16 a, s16 b, s16 c, s16 d, u32 colour, f32 scale, f32 z) {
    VertexCol v[4];
    f32 zz = fn_801DBD9C(z);
    f32 fa = a * scale;
    f32 fb = b * scale;
    f32 fc = c * scale;
    f32 fd = d * scale;
    v[0].x = fa;
    v[0].y = fb;
    v[0].z = zz;
    v[0].colour = colour;
    v[1].x = fa;
    v[1].y = fd;
    v[1].z = zz;
    v[1].colour = colour;
    v[2].x = fc;
    v[2].y = fb;
    v[2].z = zz;
    v[2].colour = colour;
    v[3].x = fb;
    v[3].y = fd;
    v[3].z = zz;
    v[3].colour = colour;
    fn_801CD73C(v, 4, 1, lbl_8034674C & ~0x4000);
}

void fn_800339B0(Rect8* out, s16 idx) {
    Rect8* src;
    if (idx >= 4) idx = 0;
    src = &lbl_802DC138[idx];
    out->v[0] = src->v[0];
    out->v[1] = src->v[1];
    out->v[2] = src->v[2];
    out->v[3] = src->v[3];
    out->v[4] = src->v[4];
    out->v[5] = src->v[5];
    out->v[6] = src->v[6];
    out->v[7] = src->v[7];
}

void fn_80033A18(Billboard* o, s16 idx, NJS_MATRIX m, s8 level) {
    NJS_POINT3 pos;
    Angle rot[3];
    VertexTex v[4];
    f32 z;
    f32 w2, h2;
    f32* t;
    s16 n;

    if (o->tex == 0) {
        return;
    }
    switch (level) {
    case 1:
        z = -5.0f;
        break;
    case 2:
        z = -10.0f;
        break;
    case 3:
        z = -15.0f;
        break;
    default:
        z = 0.0f;
        break;
    }
    if (m != NULL) {
        fn_80061518(&o->pos, &pos, m);
    } else {
        fn_80071CF0(&o->pos, &pos);
    }
    fn_80071F84(rot, &pos, &o->pos2);
    w2 = o->w / 2;
    h2 = o->h / 2;
    n = idx;
    if (n >= 4) {
        n = 0;
    }
    t = lbl_802DC178[n];
    v[0].u = t[0];
    v[0].v = t[1];
    v[1].u = t[2];
    v[1].v = t[3];
    v[2].u = t[4];
    v[2].v = t[5];
    v[3].u = t[6];
    v[3].v = t[7];
    v[0].x = -w2;
    v[0].y = h2;
    v[1].x = -w2;
    v[1].y = -h2;
    v[2].x = w2;
    v[2].y = h2;
    v[3].x = w2;
    v[3].y = -h2;
    v[0].z = z;
    v[0].colour = (o->col[0][0] << 24) | (o->col[0][1] << 16) | (o->col[0][2] << 8) | o->col[0][3];
    v[1].z = z;
    v[1].colour = (o->col[1][0] << 24) | (o->col[1][1] << 16) | (o->col[1][2] << 8) | o->col[1][3];
    v[2].z = z;
    v[2].colour = (o->col[2][0] << 24) | (o->col[2][1] << 16) | (o->col[2][2] << 8) | o->col[2][3];
    v[3].z = z;
    v[3].colour = (o->col[3][0] << 24) | (o->col[3][1] << 16) | (o->col[3][2] << 8) | o->col[3][3];
    njPushMatrixEx();
    fn_80286EE8();
    fn_8028B498();
    njTranslate(0, pos.x, pos.y, pos.z);
    if (o->roll != 0) {
        njRotateZXY(0, rot[0], rot[1], o->roll);
    } else if (idx > 3) {
        rot[2] = (s32)(182.04445f * (f32)((idx - 4) * 90 + 45));
        njRotateZXY(0, rot[0], rot[1], rot[2]);
    } else {
        njRotateXYZ(0, rot[0], rot[1], rot[2]);
    }
    fn_801CE6D0(o->tex, o->id, v, 4, 1, lbl_8034674C);
    njPopMatrixEx();
}

void fn_80033CF8(Billboard* o) {
    s32 flag;
    QuadBuf* q;
    f32 w, h;

    flag = 0;
    if (o->tex != 0) {
        flag = 1;
    }
    q = fn_801E1A74(0x10, 1);
    q->pos = fn_801E1A74(0x30, 1);
    q->col = fn_801E1A74(0x10, 1);
    q->uv = fn_801E1A74(0x10, 1);
    q->count = 4;
    w = o->w / 2;
    h = o->h / 2;
    njPushMatrixEx();
    fn_80286EE8();
    fn_8028B498();
    switch (o->type) {
    case 2:
        fn_80033EA0(q, w, h, o, 2);
        fn_80035708(o->tex, o->id, q, flag);
    case 0:
        fn_80033EA0(q, w, h, o, 0);
        fn_80035708(o->tex, o->id, q, flag);
        break;
    case 1:
        fn_80033EA0(q, w, h, o, 1);
        fn_80035708(o->tex, o->id, q, flag);
        break;
    }
    njPopMatrixEx();
    fn_801E17E0(q->pos);
    fn_801E17E0(q->col);
    fn_801E17E0(q->uv);
    fn_801E17E0(q);
}

void fn_80033EA0(QuadBuf* q, f32 w, f32 h, Billboard* s, u8 mode) {
    fn_80061F3C(&s->pos, &q->pos[0]);
    switch (mode) {
    default:
        q->pos[0].y -= h;
        break;
    case 1:
        q->pos[0].x -= w;
        break;
    case 2:
        q->pos[0].x -= w;
        q->pos[0].z -= h;
        break;
    }
    q->uv[0] = 0;
    q->uv[1] = 0;
    q->col[0] = (s->col[0][1] << 24) | (s->col[0][2] << 16) | (s->col[0][3] << 8) | s->col[0][0];
    fn_80061F3C(&s->pos, &q->pos[1]);
    switch (mode) {
    default:
        q->pos[1].y += h;
        break;
    case 1:
        q->pos[1].x += w;
        break;
    case 2:
        q->pos[1].x += w;
        q->pos[1].z += h;
        break;
    }
    q->uv[2] = 0xff;
    q->uv[3] = 0;
    q->col[1] = (s->col[1][1] << 24) | (s->col[1][2] << 16) | (s->col[1][3] << 8) | s->col[1][0];
    fn_80061F3C(&s->pos2, &q->pos[2]);
    switch (mode) {
    default:
        q->pos[2].y += h;
        break;
    case 1:
        q->pos[2].x += w;
        break;
    case 2:
        q->pos[2].x += w;
        q->pos[2].z += h;
        break;
    }
    q->uv[4] = 0xff;
    q->uv[5] = 0xff;
    q->col[2] = (s->col[2][1] << 24) | (s->col[2][2] << 16) | (s->col[2][3] << 8) | s->col[2][0];
    fn_80061F3C(&s->pos2, &q->pos[3]);
    switch (mode) {
    default:
        q->pos[3].y -= h;
        break;
    case 1:
        q->pos[3].x -= w;
        break;
    case 2:
        q->pos[3].x -= w;
        q->pos[3].z -= h;
        break;
    }
    q->uv[6] = 0;
    q->uv[7] = 0xff;
    q->col[3] = (s->col[3][1] << 24) | (s->col[3][2] << 16) | (s->col[3][3] << 8) | s->col[3][0];
}

/* Draws a small 3-axis cross at p; colour index and size given. */
void fn_800341B0(f32* p, u8 colorIdx, u8 size) {
    u32 colors[4] = {0xFFFFFFFF, 0xFFFF0000, 0xFF00FF00, 0xFF0000FF};
    f32 pts[27];
    f32 d;
    if (colorIdx >= 4) {
        colorIdx = 1;
    }
    d = 1.5f * size;
    pts[0] = p[0] + d;
    pts[1] = p[1];
    pts[2] = p[2];
    pts[3] = p[0] - d;
    pts[4] = p[1];
    pts[5] = p[2];
    pts[6] = p[0];
    pts[7] = p[1] + d;
    pts[8] = p[2];
    pts[9] = p[0];
    pts[10] = p[1] - d;
    pts[11] = p[2];
    pts[12] = p[0];
    pts[13] = p[1];
    pts[14] = p[2] + d;
    pts[15] = p[0];
    pts[16] = p[1];
    pts[17] = p[2] - d;
    fn_8028A058(colors[colorIdx], 0, 0.5f);
    fn_80289EC8(pts, 9);
    fn_8028A054();
}

/* Draws d->model with its angles given in degrees. */
void fn_800342BC(DrawObj* d) {
    njPushMatrixEx();
    fn_80286EE8();
    fn_8028B498();
    njTranslate(0, d->pos.x, d->pos.y, d->pos.z);
    njRotateXYZ(0, (s32)(182.04445f * d->ang[0]), (s32)(182.04445f * d->ang[1]), (s32)(182.04445f * d->ang[2]));
    njScale(0, d->scl.x, d->scl.y, d->scl.z);
    if (d->model != 0) {
        switch (d->kind) {
        case 2: fn_801CF0F8(d->model, lbl_80346748); break;
        case 4: fn_801CF0C8(d->model, lbl_80346748); break;
        case 1: fn_801CF158(d->model, lbl_80346748); break;
        case 0: fn_801CF128(d->model, lbl_80346748); break;
        }
    }
    njPopMatrixEx();
}

void fn_8003440C(DrawObj* o, s16 idx, NJS_MATRIX m, void* a, void* b, f32 f) {
    njPushMatrixEx();
    fn_80286EE8();
    fn_8028B498();
    if (m != NULL) {
        njMultiMatrix(NULL, m);
    }
    njTranslate(NULL, o->pos.x, o->pos.y, o->pos.z);
    njRotateXYZ(NULL, o->ang[0], o->ang[1], o->ang[2]);
    njScale(NULL, o->scl.x, o->scl.y, o->scl.z);
    if (idx >= 0 && (u16)idx < o->texlist->nbTexture) {
        NJS_TEXLIST* l = o->texlist;
        NJS_TEXNAME t = l->textures[0];
        l->textures[0] = l->textures[(u16)idx];
        l->textures[(u16)idx] = t;
    }
    if (o->model != NULL) {
        if (a != NULL && b != NULL) {
            switch (o->kind) {
            case 2: fn_801CEF30(o->model, a, b, f, lbl_80346748); break;
            case 4: fn_801CEEF4(o->model, a, b, f, lbl_80346748); break;
            case 1: fn_801CEFA8(o->model, a, b, f, lbl_80346748); break;
            case 0: fn_801CEF6C(o->model, a, b, f, lbl_80346748); break;
            }
        } else {
            switch (o->kind) {
            case 2: fn_801CF0F8(o->model, lbl_80346748); break;
            case 4: fn_801CF0C8(o->model, lbl_80346748); break;
            case 1: fn_801CF158(o->model, lbl_80346748); break;
            case 0: fn_801CF128(o->model, lbl_80346748); break;
            }
        }
    }
    njPopMatrixEx();
    if (idx >= 0 && (u16)idx < o->texlist->nbTexture) {
        NJS_TEXLIST* l = o->texlist;
        NJS_TEXNAME t = l->textures[0];
        l->textures[0] = l->textures[(u16)idx];
        l->textures[(u16)idx] = t;
    }
}

void fn_80034690(Fade* p) {
    DrawState s;
    s32 flag;
    s32 ret;
    Quad_80034690 q;
    s16 i;

    DrawStateDefault2D(&s);
    if (fn_8002F52C() != 0) {
        ret = fn_8002F46C(&s, &flag);
    } else {
        s.blend_src = p->blendSrc;
        s.blend_dst = p->blendDst;
    }
    if (DrawStatePush(&s) != 0) {
        q.p[0].x = -(p->w - 1.0f);
        q.p[0].y = -(p->h - 1.0f);
        q.uv[0].x = 0.0f;
        q.uv[0].y = 0.0f;
        q.p[1].x = -(p->w - 1.0f);
        q.p[1].y = 480.0f + (p->h - 1.0f);
        q.uv[1].x = 0.0f;
        q.uv[1].y = 0.9375f;
        q.p[2].x = 640.0f + (p->w - 1.0f);
        q.p[2].y = -(p->h - 1.0f);
        q.uv[2].x = 0.625f;
        q.uv[2].y = 0.0f;
        q.p[3].x = 640.0f + (p->w - 1.0f);
        q.p[3].y = 480.0f + (p->h - 1.0f);
        q.uv[3].x = 0.625f;
        q.uv[3].y = 0.9375f;
        for (i = 0; i < 4; i++) {
            q.col[i].c.a = (s32)(255.0f * p->alpha) + 255;
            switch (p->mode) {
            default:
                q.col[i].c.r = 255;
                q.col[i].c.g = 255;
                q.col[i].c.b = 255;
                break;
            case 2:
                q.col[i].c.r = 128;
                q.col[i].c.g = 128;
                q.col[i].c.b = 128;
                break;
            }
        }
        if (fn_8002F52C() != 0) {
            if (ret != 0) {
                fn_800331CC((Quad2D*)&q, p->z, p->mode);
                if (flag != 0) {
                    fn_801DBCD4();
                }
            }
        } else {
            fn_800331CC((Quad2D*)&q, p->z, p->mode);
        }
        DrawStatePop(NULL);
        fn_8002F448();
    }
}

void fn_8003484C(Disp* p) {
    DrawState s;
    Quad2D q;

    if (p->obj != NULL) {
        DrawStateDefault2D(&s);
        fn_80040044(&s, p->alpha, 0x800000, &p->obj->kind);
        if (DrawStatePush(&s) != 0) {
            njPushMatrixEx();
            fn_80286EE8();
            fn_8028B498();
            njUnitMatrix(NULL);
            njTranslate(NULL, 0.0f, 0.0f, -lbl_803118AC.z);
            njRotateXYZ(NULL, p->obj->ang[0], p->obj->ang[1], p->obj->ang[2]);
            if (!p->sx) {
                p->sx = 1.0f;
            }
            if (!p->sy) {
                p->sy = 1.0f;
            }
            if (!p->sz) {
                p->sz = 1.0f;
            }
            njScale(NULL, p->sx, p->sy, p->sz);
            fn_80299040(&lbl_80347568);
            if (p->obj->model != NULL) {
                if (p->a != NULL && p->b != NULL) {
                    fn_801CEF30(p->obj->model, p->a, p->b, p->f, lbl_80346748);
                } else if (p->a != NULL) {
                    fn_801CF020(p->obj->model, p->a, p->f, lbl_80346748);
                } else {
                    fn_801CF0F8(p->obj->model, lbl_80346748);
                }
            }
            njPopMatrixEx();
            DrawStatePop(NULL);
        }
    } else {
        DrawStateDefault2D(&s);
        if (DrawStatePush(&s) != 0) {
            q.p[0].x = -(p->sx - 1.0f);
            q.p[0].y = -(p->sy - 1.0f);
            q.uv[0].x = 0.0f;
            q.uv[0].y = 0.0f;
            q.p[1].x = -(p->sx - 1.0f);
            q.p[1].y = 480.0f + (p->sy - 1.0f);
            q.uv[1].x = 0.0f;
            q.uv[1].y = 0.9375f;
            q.p[2].x = 640.0f + (p->sx - 1.0f);
            q.p[2].y = -(p->sy - 1.0f);
            q.uv[2].x = 0.625f;
            q.uv[2].y = 0.0f;
            q.p[3].x = 640.0f + (p->sx - 1.0f);
            q.p[3].y = 480.0f + (p->sy - 1.0f);
            q.uv[3].x = 0.625f;
            q.uv[3].y = 0.9375f;
            q.col[0].c.a = (s32)(255.0f * p->alpha) + 255;
            q.col[0].c.r = 255; q.col[0].c.g = 255; q.col[0].c.b = 255;
            q.col[1].c.a = (s32)(255.0f * p->alpha) + 255;
            q.col[1].c.r = 255; q.col[1].c.g = 255; q.col[1].c.b = 255;
            q.col[2].c.a = (s32)(255.0f * p->alpha) + 255;
            q.col[2].c.r = 255; q.col[2].c.g = 255; q.col[2].c.b = 255;
            q.col[3].c.a = (s32)(255.0f * p->alpha) + 255;
            q.col[3].c.r = 255; q.col[3].c.g = 255; q.col[3].c.b = 255;
            fn_800333A0(&q, -1.5f);
            DrawStatePop(NULL);
        }
    }
}

void fn_80034AF0(DrawObj* o, s16 idx, NJS_MATRIX m, void* a, void* b, s32 flag, f32 f) {
    Angle ang[3];
    NJS_POINT3 pos;
    njPushMatrixEx();
    fn_80286EE8();
    fn_8028B498();
    fn_80071CF0(&o->pos, &pos);
    fn_800614FC(o->ang, ang);
    if (m != NULL) {
        if (flag != 0) {
            fn_8001E138(ang, &o->pos, m);
            ang[2] = o->ang[2];
            fn_80061518(&o->pos, &pos, m);
        } else {
            njMultiMatrix(NULL, m);
        }
    } else if (flag != 0) {
        fn_8001E138(ang, &o->pos, m);
        ang[2] = o->ang[2];
    }
    njTranslate(NULL, pos.x, pos.y, pos.z);
    njRotateZXY(NULL, ang[0], ang[1], ang[2]);
    njScale(NULL, o->scl.x, o->scl.y, o->scl.z);
    if (idx >= 0 && (u16)idx < o->texlist->nbTexture) {
        NJS_TEXLIST* l = o->texlist;
        NJS_TEXNAME t = l->textures[0];
        l->textures[0] = l->textures[(u16)idx];
        l->textures[(u16)idx] = t;
    }
    if (o->model != NULL) {
        if (a != NULL && b != NULL) {
            switch (o->kind) {
            case 2: fn_801CEF30(o->model, a, b, f, lbl_80346748); break;
            case 4: fn_801CEEF4(o->model, a, b, f, lbl_80346748); break;
            case 1: fn_801CEFA8(o->model, a, b, f, lbl_80346748); break;
            case 0: fn_801CEF6C(o->model, a, b, f, lbl_80346748); break;
            }
        } else if (a != NULL) {
            switch (o->kind) {
            case 2: fn_801CF020(o->model, a, f, lbl_80346748); break;
            case 4: fn_801CEFE4(o->model, a, f, lbl_80346748); break;
            case 1: fn_801CF090(o->model, a, f, lbl_80346748); break;
            case 0: fn_801CF058(o->model, a, f, lbl_80346748); break;
            }
        } else {
            switch (o->kind) {
            case 2: fn_801CF0F8(o->model, lbl_80346748); break;
            case 4: fn_801CF0C8(o->model, lbl_80346748); break;
            case 1: fn_801CF158(o->model, lbl_80346748); break;
            case 0: fn_801CF128(o->model, lbl_80346748); break;
            }
        }
    }
    njPopMatrixEx();
    if (idx >= 0 && (u16)idx < o->texlist->nbTexture) {
        NJS_TEXLIST* l = o->texlist;
        NJS_TEXNAME t = l->textures[0];
        l->textures[0] = l->textures[(u16)idx];
        l->textures[(u16)idx] = t;
    }
}

void fn_80034E6C(DrawObj* o, s16 idx, NJS_MATRIX m, void* a, f32 f) {
    njPushMatrixEx();
    fn_80286EE8();
    fn_8028B498();
    if (m != NULL) {
        njMultiMatrix(NULL, m);
    }
    njTranslate(NULL, o->pos.x, o->pos.y, o->pos.z);
    njRotateXYZ(NULL, o->ang[0], o->ang[1], o->ang[2]);
    njScale(NULL, o->scl.x, o->scl.y, o->scl.z);
    if (idx >= 0 && (u16)idx < o->texlist->nbTexture) {
        NJS_TEXLIST* l = o->texlist;
        NJS_TEXNAME t = l->textures[0];
        l->textures[0] = l->textures[(u16)idx];
        l->textures[(u16)idx] = t;
    }
    if (o->model != NULL) {
        if (a != NULL) {
            switch (o->kind) {
            case 2: fn_801CF020(o->model, a, f, lbl_80346748); break;
            case 4: fn_801CEFE4(o->model, a, f, lbl_80346748); break;
            case 1: fn_801CF090(o->model, a, f, lbl_80346748); break;
            case 0: fn_801CF058(o->model, a, f, lbl_80346748); break;
            }
        } else {
            switch (o->kind) {
            case 2: fn_801CF0F8(o->model, lbl_80346748); break;
            case 4: fn_801CF0C8(o->model, lbl_80346748); break;
            case 1: fn_801CF158(o->model, lbl_80346748); break;
            case 0: fn_801CF128(o->model, lbl_80346748); break;
            }
        }
    }
    njPopMatrixEx();
    if (idx >= 0 && (u16)idx < o->texlist->nbTexture) {
        NJS_TEXLIST* l = o->texlist;
        NJS_TEXNAME t = l->textures[0];
        l->textures[0] = l->textures[(u16)idx];
        l->textures[(u16)idx] = t;
    }
}

/* Copies texture entry src of list b over entry dst of list a, bounds checked. */
void fn_800350EC(NJS_TEXLIST* a, u16 dst, NJS_TEXLIST* b, u16 src) {
    if (dst >= a->nbTexture) return;
    if (src >= b->nbTexture) return;
    a->textures[dst] = b->textures[src];
}

void fn_80035140(void* model, u8 mode) {
    switch (mode) {
    case 2: fn_801CF0F8(model, lbl_80346748); break;
    case 4: fn_801CF0C8(model, lbl_80346748); break;
    case 1: fn_801CF158(model, lbl_80346748); break;
    case 0: fn_801CF128(model, lbl_80346748); break;
    }
}

void fn_800351B4(void* model, void* a, f32 f, u8 mode) {
    switch (mode) {
    case 2: fn_801CEE4C(model, a, f, lbl_80346748); break;
    case 4: fn_801CEE14(model, a, f, lbl_80346748); break;
    case 1: fn_801CEEBC(model, a, f, lbl_80346748); break;
    case 0: fn_801CEE84(model, a, f, lbl_80346748); break;
    }
}

void fn_80035228(void* model, void* a, f32 f, u8 mode) {
    switch (mode) {
    case 2: fn_801CEE4C(model, a, f, lbl_80346748); break;
    case 4: fn_801CEE14(model, a, f, lbl_80346748); break;
    case 1: fn_801CEEBC(model, a, f, lbl_80346748); break;
    case 0: fn_801CEE84(model, a, f, lbl_80346748); break;
    }
}

static inline void DrawModelMotion(void* model, void* a, f32 f, u8 mode) {
    switch (mode) {
    case 2: fn_801CF020(model, a, f, lbl_80346748); break;
    case 4: fn_801CEFE4(model, a, f, lbl_80346748); break;
    case 1: fn_801CF090(model, a, f, lbl_80346748); break;
    case 0: fn_801CF058(model, a, f, lbl_80346748); break;
    }
}

void fn_8003529C(void* model, void* a, f32 f, u8 mode) {
    fn_802947CC(0);
    DrawModelMotion(model, a, f, mode);
    fn_802947CC(1);
}

void fn_80035380(void* model, void* a, f32 f, u8 mode) {
    switch (mode) {
    case 2: fn_801CF020(model, a, f, lbl_80346748); break;
    case 4: fn_801CEFE4(model, a, f, lbl_80346748); break;
    case 1: fn_801CF090(model, a, f, lbl_80346748); break;
    case 0: fn_801CF058(model, a, f, lbl_80346748); break;
    }
}

void fn_800353F4(void* model, void* a, void* b, f32 f, u8 mode) {
    switch (mode) {
    case 2: fn_801CEF30(model, a, b, f, lbl_80346748); break;
    case 4: fn_801CEEF4(model, a, b, f, lbl_80346748); break;
    case 1: fn_801CEFA8(model, a, b, f, lbl_80346748); break;
    case 0: fn_801CEF6C(model, a, b, f, lbl_80346748); break;
    }
}

void fn_80035468(void* model, void* a, void* b, f32 f, u8 mode) {
    switch (mode) {
    case 2: fn_801CED60(model, a, b, f, lbl_80346748); break;
    case 4: fn_801CED24(model, a, b, f, lbl_80346748); break;
    case 1: fn_801CEDD8(model, a, b, f, lbl_80346748); break;
    case 0: fn_801CED9C(model, a, b, f, lbl_80346748); break;
    }
}

void fn_800354DC(NJS_TEXLIST* t, s16 i) {
    if (t->nbTexture <= (u16)i) i = t->nbTexture - 1;
    fn_80298FE4(i);
}

void fn_80035518(void* tex, s32 id, QuadBuf* src, s32 textured, s32 flags) {
    u32 idx[4] = {0, 3, 1, 2};
    s32 i;
    if (textured) {
        VertexTex v[4];
        for (i = 0; i < 4; i++) {
            u32 k = idx[i];
            v[i].x = src->pos[k].x;
            v[i].y = src->pos[k].y;
            v[i].z = src->pos[k].z;
            v[i].u = 0.003921569f * src->uv[k * 2];
            v[i].v = 0.003921569f * src->uv[k * 2 + 1];
            v[i].colour = src->col[k];
        }
        fn_801CE6D0(tex, id, v, 4, 1, flags);
    } else {
        VertexCol v[4];
        for (i = 0; i < 4; i++) {
            u32 k = idx[i];
            v[i].x = src->pos[k].x;
            v[i].y = src->pos[k].y;
            v[i].z = src->pos[k].z;
            v[i].colour = src->col[k];
        }
        fn_801CE1A4(v, 4, 1, flags);
    }
}

void fn_80035708(void* tex, s32 id, QuadBuf* src, s32 textured) {
    u32 idx[4] = {0, 3, 1, 2};
    s32 i;
    if (textured) {
        VertexTex v[4];
        VertexTex* p = v;
        for (i = 0; i < 4; i++, p++) {
            u32 k = idx[i];
            p->x = src->pos[k].x;
            p->y = src->pos[k].y;
            p->z = src->pos[k].z;
            p->u = 0.003921569f * src->uv[k * 2];
            p->v = 0.003921569f * src->uv[k * 2 + 1];
            p->colour = src->col[k];
        }
        fn_801CE6D0(tex, id, v, 4, 1, lbl_8034674C);
    } else {
        VertexCol v[4];
        for (i = 0; i < 4; i++) {
            u32 k = idx[i];
            VertexCol* p = &v[i];
            p->x = src->pos[k].x;
            p->y = src->pos[k].y;
            p->z = src->pos[k].z;
            p->colour = src->col[k];
        }
        fn_801CE1A4(v, 4, 1, lbl_8034674C);
    }
}

s32 fn_800358F8(void) {
    return lbl_8034674C;
}

void fn_80035900(s32 v) {
    lbl_8034674C = v;
}

s32 fn_80035908(void) {
    return lbl_80346748;
}

void fn_80035910(s32 v) {
    lbl_80346748 = v;
}
