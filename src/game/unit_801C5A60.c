#include "types.h"
#include "ninja.h"
void fn_801E5DF0(void *o);
void fn_801E5148(void *o);
extern u32 lbl_8030A6D4[36];
void *memset(void *dst, int c, u32 n);
extern s32 lbl_803471CC;
extern s32 DVDGetDriveStatus(void);
typedef struct Table { u32 count; s32 vals[1]; } Table;
typedef struct Sub { u8 pad[0x10]; Table *tab; } Sub;
typedef struct Obj { u8 pad[0x1c8]; Sub *sub; } Obj;
extern f32 njInnerProduct(NJS_VECTOR* a, NJS_VECTOR* b);
typedef struct Rec {
    u8 pad0[0x50];
    f32 v[3];
} Rec;
typedef struct Obj_801C5AB4 {
    u8 pad0[0x1c8];
    Rec* rec;
} Obj_801C5AB4;
typedef struct Sub_801C5DEC {
    u8 pad0[0x18];
    f32* posf;
    u8 pad1[4];
    s32* posi;
} Sub_801C5DEC;
typedef struct Obj_801C5DEC {
    u8 pad0[0x38];
    f32 pos[3];
    s32 ipos[3];
    u8 pad1[0x1bc - 0x50];
    Sub_801C5DEC* sub;
} Obj_801C5DEC;
extern void fn_80222838(Sub_801C5DEC* s);
typedef struct Sub_801C610C {
    s32 w00;
    s32 w04;
    s32 w08;
    f32 f0c;
    f32 f10;
    s32 w14;
    s32 w18;
    u8 pad1c[0x2c - 0x1c];
    s32 w2c;
    s32 w30;
    s32 w34;
    u8 pad38[0x50 - 0x38];
    f32 f50;
    f32 f54;
    f32 f58;
    u8 pad5c[0x190 - 0x5c];
    f32 f190;
    u8 pad194[0x1a8 - 0x194];
    f32 f1a8;
} Sub_801C610C;
typedef struct Node { s32 kind; u8 pad_4[0x40];
 s32 f44;
 u8 pad_48[0x3c]; struct Node* next; } Node;
extern Node* lbl_803471C8;
extern void fn_801C6714(Node* n);
typedef struct Obj_801C6384 {
    u8 pad0[0x70];
    void* p70;
    u8 pad1[4];
    void* p78;
} Obj_801C6384;
extern void fn_8023A8E0(void* p);
extern void fn_801E17E0(void* p);
typedef struct AkFio {
    s32 state;
    u8 info[0x34];
    s32 w38;
    u8 pad3c[8];
    s32 w44;
    s32 w48;
    s32 w4c;
    s32 w50;
    s32 w54;
    u8 pad58[4];
    u8 b5c;
    u8 pad5d[3];
    s32 w60;
    u8 pad64[0xc];
    s32 w70;
    u8 pad74[4];
    void* buf;
    u8 pad7c[8];
    s32 w84;
    u8 pad88[0x18];
} AkFio;
extern void* fn_801E1C7C(s32 size);
extern void OSPanic(const char* file, int line, const char* msg, ...);
extern s32 fn_8023A4B0(s32 h);
extern s32 fn_8023A7A4(s32 h, void* out);
typedef struct Rect8 {
    s32 tex;
    f32 f4, f8, fc, f10;
    f32 f14, f18, f1c, f20;
} Rect8;
extern void fn_80299040(void);
extern void fn_80291428(s32 a);
extern void fn_802913E8(s32 a, s32 b);
extern void fn_802911CC(f32 *v, f32 s);
extern void fn_80291424(void);
typedef struct DVDFileInfo DVDFileInfo;
typedef struct Stream {
    u8 pad0[4];
    u8 info[0x54];
    s32 off;         /* 0x58 */
    u8 pad5c[4];
    s32 size;        /* 0x60 */
    s32 pos;         /* 0x64 */
    u8 pad68[4];
    u32 bpos;        /* 0x6c */
    u8 *buf;         /* 0x70 */
} Stream;
extern s32 fn_8023AB88(void *info, void *addr, s32 len, s32 offset, void (*cb)(void), s32 prio);
extern s32 fn_8023CD10(void *info);
extern void fn_801DBF94(s32);
extern s32 fn_801D168C(void);
extern void fn_801D150C(s32 v);
typedef struct Ent_802EE7C0 {
    char name[0x10];
    s16 len;
    s16 flag;
    char pat[4];
    s32 val;
} Ent_802EE7C0;
extern Ent_802EE7C0 lbl_802EE7C0[];
extern int strncmp(const char *a, const char *b, u32 n);
extern int fn_8025EF88(const char *a, const char *b);
/* lbl_80308428: 8 pairs of 3-word vectors (0xc0 bytes). */
typedef struct Pair_801C86D8 {
    void* a[3];
    s32 b[3];
} Pair_801C86D8;
extern Pair_801C86D8 lbl_80308428[8];
extern void fn_801C8590(void);
extern void fn_802938C0(void (*cb)(void));
typedef struct Rec_801C5D88 {
    u8 pad0[0x1c];
    u32* lst;
} Rec_801C5D88;
typedef struct Obj_801C5D88 {
    u8 pad0[0x1c8];
    Rec_801C5D88* rec;
} Obj_801C5D88;
extern u32 lbl_802EE798[];
extern f32 njScalor(NJS_VECTOR *v);
typedef struct Wk {
    u8 pad0[0x20];
    s32 w[0x24];
} Wk;
typedef struct Tk {
    u8 pad0[0x24];
    Wk* work;
} Tk;
extern s32 lbl_802C3EA8[];
extern s32 fn_801E4BF4(s8 i);
typedef struct NJS_MOTION NJS_MOTION;
typedef struct { u32 count; NJS_MOTION *items[1]; } MotionList;
typedef struct { u8 pad0[0x1c]; MotionList *motions; } EvExt;
typedef struct {
    u8 pad0[0xe8]; NJS_MOTION *motion; u8 padEC[4]; NJS_MOTION *prev;
    u8 padF4[0x18c - 0xf4]; f32 x18c; u8 pad190[0x198 - 0x190];
    s32 x198; s32 x19c; f32 x1a0; f32 x1a4; u8 pad1A8[0x1c8 - 0x1a8]; EvExt *ext;
} EvObj;
typedef struct AkRd {
    s32 state;
    u8 info[0x3c];
    s32 mode;
    u8 pad44[4];
    void* dst;
    u8 pad4c[8];
    s32 size;
    u8 pad58[4];
    u8 b5c;
    u8 b5d;
    u8 pad5e[6];
    s32 w64;
    s32 w68;
    s32 w6c;
    u8 pad70[4];
    s32 w74;
    u8* buf;
    u8 pad7c[4];
    s32 w80;
} AkRd;
extern void fn_801C74D0(AkRd* f);
typedef struct { f32 x, y, z; } Vtx;
typedef struct { s16 i[4]; } Quad;

void fn_801C5A60(NJS_MATRIX m, NJS_POINT3 *p, NJS_POINT3 *out)
{
    if (m && p && out) {
        NJS_POINT3 tmp;
        tmp.x = p->x;
        tmp.y = p->y;
        tmp.z = p->z;
        njCalcPoint(m, &tmp, out);
    }
}

void fn_801C5B44(u8 *o, float *out)
{
    s32 ok = 0;
    if (o != 0) {
        if (*(u8 **)(o + 0x1c8) != 0) {
            ok = 1;
        }
    }
    if (ok == 0) {
        return;
    }
    if (out == 0) {
        return;
    }
    out[0] = *(float *)(*(u8 **)(o + 0x1c8) + 0x44);
    out[1] = *(float *)(*(u8 **)(o + 0x1c8) + 0x48);
    out[2] = *(float *)(*(u8 **)(o + 0x1c8) + 0x4c);
}

void fn_801C5B98(u8 *o)
{
    if (o != 0) {
        if (*(s32 *)(o + 0x19c) != 0) {
            fn_801E5DF0(o);
        } else {
            fn_801E5148(o);
        }
    }
}

typedef struct Obj12 {
    u8 pad_00[0x12];
    u16 v12;
} Obj12;
BOOL fn_801C5E80(void *unused, Obj12 *p)
{
    return p->v12 == 1;
}

u32 fn_801C5F40(u8 *o, u32 n)
{
    u8 *p;
    u32 v;
    s32 r = 0;
    if (o != 0) {
        p = *(u8 **)(o + 0x1c8);
        if (p != 0) {
            p = *(u8 **)(p + 0x1c);
            if (p != 0) {
                v = *(u32 *)p;
                if (v != 0) {
                    if (v > n) {
                        r = 1;
                    }
                }
            }
        }
    }
    return r;
}

s32 fn_801C5F84(u8 *o)
{
    u8 *p;
    s32 r = 0;
    if (o != 0) {
        p = *(u8 **)(o + 0x1c8);
        if (p != 0) {
            p = *(u8 **)(p + 0x1c);
            if (p != 0) {
                if (*(u32 *)p != 0) {
                    r = 1;
                }
            }
        }
    }
    return r;
}

s32 fn_801C5FC0(u8 *o)
{
    u8 *p;
    s32 r = 0;
    if (o != 0) {
        p = *(u8 **)(o + 0x1c8);
        if (p != 0) {
            p = *(u8 **)(p + 0x20);
            if (p != 0) {
                if (*(u32 *)(p + 0x4) != 0) {
                    r = 1;
                }
            }
        }
    }
    return r;
}

u32 fn_801C602C(u8 *o, u32 n)
{
    u8 *p;
    s32 r = 0;
    if (o != 0) {
        p = *(u8 **)(o + 0x1c8);
        if (p != 0) {
            p = *(u8 **)(p + 0x10);
            if (p != 0) {
                if (*(u32 *)p > n) {
                    r = 1;
                }
            }
        }
    }
    return r;
}

u32 fn_801C6068(u8 *o, u32 n)
{
    u8 *p;
    s32 r = 0;
    if (o != 0) {
        p = *(u8 **)(o + 0x1c8);
        if (p != 0) {
            p = *(u8 **)(p + 0x10);
            if (p != 0) {
                if (*(u32 *)p >= n) {
                    r = 1;
                }
            }
        }
    }
    return r;
}

float fn_801C60C8(float a, float b)
{
    float s = a + b;
    if (b >= 0.0f && s > 0.0f) {
        return 0.0f;
    }
    if (!(b < 0.0f)) {
        return s;
    }
    if (!(s < -1.0f)) {
        return s;
    }
    return -1.0f;
}

extern u32 lbl_803471D0;
s32 fn_801C621C(void) {
    return lbl_803471CC;
}

void fn_801C62D8(void) {
    lbl_803471D0 = 0;
}

extern void fn_8023AB28(const char*);
extern char lbl_8034BC10;
void fn_801C62E4(void) {
    fn_8023AB28(&lbl_8034BC10);
}

void fn_801C78B4(void) {
}

void fn_801C78B8(void)
{
    memset(lbl_8030A6D4, 0, 0x90);
    lbl_8030A6D4[5] = 6;
    lbl_8030A6D4[14] = 6;
    lbl_8030A6D4[23] = 6;
    lbl_8030A6D4[32] = 6;
}

void fn_801C5BD4(u8 *p) {
    if (p == 0) {
        return;
    }
    *(f32 *)(p + 0x1a4) = 0.0f;
    *(u32 *)(p + 0x198) = 0;
    *(u32 *)(p + 0x19c) = 0;
}

int fn_801C5FFC(u8 *p) {
    u8 *q;
    int r = 0;

    if (p != 0) {
        q = *(u8 **)(p + 0x100);
        if (q != 0 && *(u32 *)(q + 0x4) != 0) {
            r = 1;
        }
    }
    return r;
}

int fn_801C60A4(u8 *p) {
    int r = 0;

    if (p != 0 && *(u32 *)(p + 0x1c8) != 0) {
        r = 1;
    }
    return r;
}

void fn_801C6170(u8 *p) {
    p[0x18] |= 0x40;
}

void fn_801C6224(void) {
    lbl_803471CC = DVDGetDriveStatus();
}

typedef struct { float x, y, z; } Vec3;
void fn_801C7A2C(Vec3 *v)
{
    int i, j;
    Vec3 t1, t7, t6, t5, t4, t3, t2;

    for (i = 0; i < 7; i++) {
        for (j = i + 1; j < 8; j++) {
            if (v[i].y < v[j].y) {
                t1 = v[j];
                v[j] = v[i];
                v[i] = t1;
            }
        }
    }
    for (i = 0; i < 3; i++) {
        for (j = i + 1; j < 4; j++) {
            if (v[i].x > v[j].x) {
                t2 = v[j];
                v[j] = v[i];
                v[i] = t2;
            }
        }
    }
    for (i = 4; i < 7; i++) {
        for (j = i + 1; j < 8; j++) {
            if (v[i].x > v[j].x) {
                t3 = v[j];
                v[j] = v[i];
                v[i] = t3;
            }
        }
    }
    if (v[0].z < v[1].z) { t4 = v[1]; v[1] = v[0]; v[0] = t4; }
    if (v[2].z > v[3].z) { t5 = v[3]; v[3] = v[2]; v[2] = t5; }
    if (v[4].z < v[5].z) { t6 = v[5]; v[5] = v[4]; v[4] = t6; }
    if (v[6].z > v[7].z) { t7 = v[7]; v[7] = v[6]; v[6] = t7; }
}

extern void fn_801D9634(Vec3 *v, void *out);
void fn_801C588C(Vec3 *a, Vec3 *b, void *out) {
    Vec3 d;
    if (a != 0 && b != 0 && out != 0) {
        d.x = b->x - a->x;
        d.y = b->y - a->y;
        d.z = b->z - a->z;
        fn_801D9634(&d, out);
    }
}

static inline BOOL HasVal(Obj *obj, u32 idx) {
    return obj != NULL && obj->sub != NULL && obj->sub->tab != NULL && obj->sub->tab->count > idx;
}

f32 fn_801C5C80(Obj *obj, u32 idx) {
    f32 result = 0.0f;
    if (HasVal(obj, idx)) {
        result = (f32)obj->sub->tab->vals[idx] / 100.0f;
    }
    return result;
}

f32 fn_801C5D04(Obj *obj, u32 idx) {
    f32 result = 0.0f;
    if (HasVal(obj, idx)) {
        result = (f32)obj->sub->tab->vals[idx] / 100.0f;
    }
    return result;
}

s32 fn_801C5758(NJS_POINT3* a, NJS_POINT3* b, NJS_POINT3* n) {
    s32 r = 1;
    if (n && a && b) {
        NJS_POINT3 d;
        NJS_POINT3 nn;
        d.x = b->x - a->x;
        d.y = 0.0f;
        d.z = b->z - a->z;
        nn.x = n->x;
        nn.y = 0.0f;
        nn.z = n->z;
        if (njInnerProduct(&d, &nn) > 0.0f) {
            r = 0;
        }
    }
    return r;
}

void fn_801C5AB4(Obj_801C5AB4* obj, s32* out) {
    s32 ok = 0;
    if (obj && obj->rec) {
        ok = 1;
    }
    if (ok && out) {
        out[0] = (s32)(obj->rec->v[0] * 182.04445f);
        out[1] = (s32)(obj->rec->v[1] * 182.04445f);
        out[2] = (s32)(obj->rec->v[2] * 182.04445f);
    }
}

void fn_801C5DEC(Obj_801C5DEC* o) {
    if (o && o->sub) {
        o->sub->posf[0] = o->pos[0];
        o->sub->posf[1] = o->pos[1];
        o->sub->posf[2] = o->pos[2];
        o->sub->posi[0] = o->ipos[0];
        o->sub->posi[1] = o->ipos[1];
        o->sub->posi[2] = o->ipos[2];
        fn_80222838(o->sub);
    }
}

void fn_801C610C(Sub_801C610C* s) {
    s->f58 = 1.0f;
    s->f54 = 1.0f;
    s->f50 = 1.0f;
    s->f190 = 1.0f;
    s->w14 = -1;
    s->w18 = 0;
    s->w30 = 8;
    s->w34 = 6;
    s->w2c = 1;
    s->w04 = 1;
    s->f0c = 9000.0f;
    s->f10 = 10000.0f;
    s->w08 = 0;
    s->f190 = 1.0f;
    s->f1a8 = 0.2f;
}

void fn_801C6248(void) {
    Node* node = lbl_803471C8;
    while (node) {
        fn_801C6714(node);
        if (node->kind == 4 && lbl_803471C8) {
            if (lbl_803471C8 == node) {
                lbl_803471C8 = lbl_803471C8->next;
            } else {
                Node* p = lbl_803471C8;
                Node* q;
                do {
                    q = p->next;
                    if (q == node) {
                        p->next = node->next;
                        break;
                    }
                    p = q;
                } while (q);
            }
        }
        node = node->next;
    }
}

void fn_801C6384(Obj_801C6384* o) {
    fn_8023A8E0((u8*)o + 4);
    if (o->p70) {
        fn_801E17E0(o->p70);
        o->p70 = 0;
    }
    if (o->p78) {
        fn_801E17E0(o->p78);
        o->p78 = 0;
    }
    fn_801E17E0(o);
}

AkFio* fn_801C63EC(s32 h)
{
    AkFio* f = fn_801E1C7C(0xa0);
    s32 id;
    if (f == 0) {
        OSPanic("akFIO.c", 0x425, 0);
    }
    id = fn_8023A4B0(h);
    if (id == -1) {
        return 0;
    }
    if (fn_8023A7A4(id, f->info) != 1) {
        return 0;
    }
    f->w60 = f->w38;
    f->w70 = 0;
    f->buf = fn_801E1C7C(0x1000);
    if (f->buf == 0) {
        OSPanic("akFIO.c", 0x447, 0);
    }
    f->w54 = 0;
    f->b5c = 1;
    f->w44 = 0;
    f->w84 = 0;
    f->state = 2;
    f->w48 = 0;
    f->w4c = 0;
    f->w50 = 0;
    return f;
}

void fn_801C8BC0(f32 a, f32 b, f32 s, s32 unused, Rect8 *r, s32 n) {
    f32 v[8];
    if (!(b < -512.0f || b > 512.0f)) {
        fn_80299040();
        v[0] = r->f4 + a;
        v[1] = r->f8 + b;
        v[2] = r->fc + a;
        v[3] = r->f10 + b;
        v[4] = r->f14;
        v[5] = r->f18;
        v[6] = r->f1c;
        v[7] = r->f20;
        fn_80291428(1);
        fn_802913E8(r->tex, n);
        fn_802911CC(v, s);
        fn_80291424();
    }
}

s32 fn_801C6E14(Stream *s, u8 *out) {
    s32 len;
    s32 r;
    if (s->pos >= s->size) {
        return 0;
    }
    s->bpos &= 0x1ffff;
    if (s->bpos == 0) {
        len = (s->off + 0x20000 < s->size) ? 0x20000 : s->size - s->off;
        len = (len + 31) & ~31;
        fn_8023AB88(s->info, s->buf, len, s->off, 0, 2);
        while (fn_8023CD10(s->info) != 0) {
            fn_801DBF94(0);
            r = fn_801D168C();
            if (r != -1) {
                fn_801D150C(r);
            }
        }
        s->off += len;
    }
    *out = s->buf[s->bpos++];
    s->pos++;
    return 1;
}

s32 fn_801C8A0C(char *s) {
    Ent_802EE7C0 *e = lbl_802EE7C0;
    char *p = s;
    s32 n = 55;
    s32 len;
    char c;
    do {
        if (e->name[0] == p[0]) {
            len = e->len;
            if (len > 0 && strncmp(p, e->name, len) == 0) {
                c = p[len];
                if (c == 0 && e->flag == 0) {
                    return e->val;
                }
                if (c != 0 && e->flag > 0) {
                    p += len;
                    do {
                        if (fn_8025EF88(p, e->pat) == 0) {
                            return e->val;
                        }
                        n--;
                        e++;
                    } while (e->len == 0 && n > 0);
                    p = s;
                    n++;
                    e--;
                }
            }
        } else if (e->name[0] > p[0]) {
            break;
        }
    } while (n--, e++, n > 0);
    return -1;
}

extern char lbl_802C3BE8[];
extern void fn_801DBE1C(const char* fmt, ...);
static inline void SlotRemove(Pair_801C86D8* tab, void* id) {
    s32 i;
    for (i = 0; i < 8; i++) {
        if (tab[i].a[1] == id) {
            lbl_80308428[i].a[0] = 0;
            lbl_80308428[i].a[1] = 0;
            lbl_80308428[i].a[2] = 0;
            return;
        }
    }
    fn_801DBE1C(lbl_802C3BE8);
}
void fn_801C83B4(void* id) {
    if (!id) {
        fn_801DBE1C(lbl_802C3BE8);
    }
    SlotRemove(lbl_80308428, id);
}

/* Clears the 8 vector pairs and registers fn_801C8590 as a callback. */
void fn_801C86D8(void)
{
    s32 i, j;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 3; j++) {
            lbl_80308428[i].a[j] = 0;
            lbl_80308428[i].b[j] = 0;
        }
    }
    fn_802938C0(fn_801C8590);
}

u32 fn_801C5D88(Obj_801C5D88* obj, u32 idx) {
    s32 ok;
    u32 val;
    val = 0;
    ok = 0;
    if (obj && obj->rec) {
        u32* lst = obj->rec->lst;
        if (lst && lst[0] != 0 && lst[0] > idx) {
            ok = 1;
        }
    }
    if (ok) {
        val = obj->rec->lst[idx + 1];
    }
    return val;
}

static inline int fn_801C8930_known(s32 id) {
    u32 *q;
    if (id > 0) {
        q = lbl_802EE798;
        while (*q != 0 && id != *q) {
            q++;
        }
        return *q != 0;
    }
    return 0;
}

void *fn_801C8930(void *h) {
    if (h == NULL) {
        return NULL;
    }
    if (fn_801C8930_known(*(s32 *)h) == 1) {
        return (u8 *)h + 8;
    }
    return h;
}

void fn_801C8828(u8 *base) {
    u8 *hdr;
    u8 *end;
    u32 c;
    u8 *p;
    u32 off;
    u8 *a;
    u8 *b;
    u32 *slot;
    a = base + 8;
    hdr = a;
    b = a + *(u32 *)(base + 4);
    p = b + 8;
    end = p + *(u32 *)(b + 4);
    while (end > p) {
        c = *p;
        switch (c & 0xc0) {
        case 0:
            p += 1;
            continue;
        case 0x40:
            off = (c & ~0xc0) << 2;
            *p = 0;
            p += 1;
            break;
        case 0x80:
            off = (c & ~0xc0) << 8;
            *p = 0;
            off += p[1];
            p[1] = 0;
            off <<= 2;
            p += 2;
            break;
        case 0xc0:
            off = (c & 0x3f) << 24;
            *p = 0;
            off += p[1] << 16;
            p[1] = 0;
            off += p[2] << 8;
            p[2] = 0;
            off += p[3];
            p[3] = 0;
            off <<= 2;
            p += 4;
            break;
        }
        slot = (u32 *)(a + off);
        if (*slot != 0) {
            *slot = (u32)hdr + *slot;
        }
        a = (u8 *)slot;
    }
}

f32 fn_801C599C(NJS_POINT3 *a, NJS_POINT3 *b) {
    f32 r = 0.0f;
    if (a && b) {
        NJS_POINT3 d;
        d.x = a->x - b->x;
        d.y = r;
        d.z = a->z - b->z;
        r = njScalor(&d);
    }
    return r;
}

/* Same shape as CalcPointSafe/RotateVector in src/game/uiobj.c. */
static inline void CalcPointSafe(f32* m, NJS_VECTOR* v, NJS_VECTOR* out) {
    NJS_VECTOR t;
    if (m != NULL && v != NULL && out != NULL) {
        t.x = v->x;
        t.y = v->y;
        t.z = v->z;
        njCalcPoint(m, &t, out);
    }
}

void fn_801C58FC(NJS_VECTOR* v, NJS_VECTOR* out, Angle x, Angle y, Angle z) {
    NJS_MATRIX m;
    if (v != NULL && out != NULL) {
        njUnitMatrix(m);
        njRotateXYZ(m, x, y, z);
        CalcPointSafe(m, v, out);
    }
}

u8* fn_801C87C8(u8 code, u8* base) {
    switch (code) {
    case 0x29:
        return base + 0x18;
    case 0x22:
        return base + 0xc;
    case 0x23: case 0x24: case 0x25: case 0x26: case 0x27: case 0x28:
    case 0x30:
        return base + 0x10;
    case 0x2a: case 0x2b: case 0x2c: case 0x2d: case 0x2e: case 0x2f:
        return base + 0x1c;
    case 0x31: case 0x32:
        return base + 0x14;
    }
}

void fn_801CA66C(Tk* t) {
    int i;
    s32 j;

    for (i = 0; i < 0x21; i++) {
        t->work->w[i] = i;
    }
    for (; i < 0x24; i++) {
        t->work->w[i] = 0;
    }
    for (j = 0, i = 8; j < 0x16; i++, j++) {
        if (fn_801E4BF4(j) != 0) {
            t->work->w[i] = lbl_802C3EA8[j];
        } else {
            t->work->w[i] = 0;
        }
    }
}

s32 fn_801C6308(Node* n) {
    n->f44 = 1;
    fn_801C6714(n);
    if (lbl_803471C8) {
        if (lbl_803471C8 == n) {
            lbl_803471C8 = lbl_803471C8->next;
        } else {
            Node* p = lbl_803471C8;
            Node* q;
            do {
                q = p->next;
                if (q == n) {
                    p->next = n->next;
                    break;
                }
                p = q;
            } while (q);
        }
    }
    return 1;
}

static inline s32 MotionValid(EvObj *obj, u32 i)
{
    return obj != NULL && obj->ext != NULL && obj->ext->motions != NULL &&
        obj->ext->motions->count != 0 && obj->ext->motions->count > i;
}

static inline NJS_MOTION *MotionGet(EvObj *obj, u32 i)
{
    NJS_MOTION *m = NULL;
    if (MotionValid(obj, i)) {
        m = obj->ext->motions->items[i];
    }
    return m;
}
void fn_801C5BF4(EvObj *obj, u32 i)
{
    if (obj == NULL) {
        return;
    }
    obj->x1a0 = obj->x18c;
    obj->x18c = 0.0f;
    obj->x1a4 = 0.0f;
    obj->x198 = 0;
    obj->x19c = 0;
    obj->prev = obj->motion;
    obj->motion = MotionGet(obj, i);
}

s32 fn_801C6C7C(AkRd* f) {
    int i;
    s32 r;

    if (f->state == 2) {
        f->state = 0;
        OSPanic("akFIO.c", 0x1db, "akFioRead() : Invalid FileOpenMode");
        return f->state;
    }
    if (f->mode == 0) {
        fn_8023AB88(f->info, f->dst, f->size, 0, 0, 2);
        while (fn_8023CD10(f->info) != 0) {
            fn_801DBF94(0);
            r = fn_801D168C();
            if (r != -1) {
                fn_801D150C(r);
            }
        }
        f->state = 4;
        return f->size;
    }
    f->w64 = 0x10;
    f->w6c = f->w68 = i = 0;
    f->w74 = 0xfee;
    for (; i < 0xfee; i++) {
        f->buf[i] = 0;
    }
    f->w80 = 0;
    f->b5c = 6;
    f->b5d = 1;
    fn_801C74D0(f);
    f->state = 4;
    return f->size;
}

/* Is (px, pz) inside the quad? (2D cross product of each edge, using the vertices' y and z.) */
s32 fn_801C81DC(Quad* q, Vtx* v, f32 px, f32 pz)
{
    f32 zero = 0.0f;
    f32 ax, az;
    f32 t0, t1;
    az = v[q->i[0]].z - pz;
    ax = v[q->i[0]].y - px;
    t0 = az * (v[q->i[1]].y - px);
    t1 = v[q->i[1]].z - pz;
    t1 *= ax;
    if (zero > t1 - t0) {
        return 0;
    }
    t0 = (v[q->i[1]].z - pz) * (v[q->i[2]].y - px);
    t1 = (v[q->i[2]].z - pz) * (v[q->i[1]].y - px);
    if (zero > t1 - t0) {
        return 0;
    }
    t0 = (v[q->i[2]].z - pz) * (v[q->i[3]].y - px);
    t1 = (v[q->i[3]].z - pz) * (v[q->i[2]].y - px);
    if (zero > t1 - t0) {
        return 0;
    }
    t1 = (v[q->i[3]].z - pz) * (v[q->i[0]].y - px);
    t0 = (v[q->i[0]].z - pz) * (v[q->i[3]].y - px);
    return !(zero > t0 - t1);
}

/* Is (px, pz) inside the quad? (2D cross product of each edge, using the vertices' x and y.) */
s32 fn_801C82C8(Quad* q, Vtx* v, f32 px, f32 pz)
{
    f32 zero = 0.0f;
    f32 ax, az;
    f32 t0, t1;
    az = v[q->i[0]].y - pz;
    ax = v[q->i[0]].x - px;
    t0 = az * (v[q->i[1]].x - px);
    t1 = v[q->i[1]].y - pz;
    t1 *= ax;
    if (zero > t1 - t0) {
        return 0;
    }
    t0 = (v[q->i[1]].y - pz) * (v[q->i[2]].x - px);
    t1 = (v[q->i[2]].y - pz) * (v[q->i[1]].x - px);
    if (zero > t1 - t0) {
        return 0;
    }
    t0 = (v[q->i[2]].y - pz) * (v[q->i[3]].x - px);
    t1 = (v[q->i[3]].y - pz) * (v[q->i[2]].x - px);
    if (zero > t1 - t0) {
        return 0;
    }
    t1 = (v[q->i[3]].y - pz) * (v[q->i[0]].x - px);
    t0 = (v[q->i[0]].y - pz) * (v[q->i[3]].x - px);
    return !(zero > t0 - t1);
}
