#include "types.h"
#include "ninja.h"

/* Motion evaluation and Ninja chunk-model helpers (0x801E7654 - 0x801E8CA4): sampling a motion
 * into position / angle / offset (fn_801E7654, fn_801E78C8, fn_801E7B2C, fn_801E7C6C), shifting
 * the UV pairs of a chunk strip list in place (fn_801E7E5C, fn_801E8004), building the strip list
 * of a chunk object tree (fn_801E8360, fn_801E81AC, fn_801E84C0) and shifting chunk UVs per
 * object tree (fn_801E85BC .. fn_801E89D0). */

/* Ninja NJS_MOTION: type is the channel mask, inp_fn the layout (low 4 bits) and flags. */
typedef struct NJS_MOTION {
    void** mdata;
    u32 nbFrame;
    u16 type;
    u16 inp_fn;
} NJS_MOTION;

typedef struct { s32 frame; f32 v[3]; } KeyVec;
typedef struct { s32 frame; s32 val; } KeyInt;

/* A chunk model's vertex/strip list. */
typedef struct {
    u32 flags;  /* 0x00 */
    s16* plist; /* 0x04 chunk data */
} CnkModel;

/* A chunk object tree node (NJS_CNK_OBJECT). */
typedef struct CnkObject {
    u32 flags;                /* 0x00 bit 3: no model, bit 4: no children */
    CnkModel* model;          /* 0x04 */
    u8 pad8[0x2C - 8];
    struct CnkObject* child;   /* 0x2C */
    struct CnkObject* sibling; /* 0x30 */
} CnkObject;

/* One model's strip data (len shorts of offsets/deltas into plist). */
typedef struct {
    s32 len;      /* 0x00 */
    s16* plist;   /* 0x04 chunk data */
    s16* offsets; /* 0x08 stream of chunk offsets and per-vertex deltas */
} ChunkSet;

/* The list built by fn_801E84C0: num sets, then the sets and their offset streams. */
typedef struct {
    s32 num;          /* 0x00 */
    ChunkSet* sets;   /* 0x04 */
    CnkObject* owner; /* 0x08 */
} ChunkSetList;

typedef struct {
    u8 pad0[8];
    CnkObject sub; /* 0x08 */
} ModelObj;

extern void fn_800071D8(NJS_MOTION* m, f32 frame);
extern void fn_80007080(void* dst, s32 flag);
extern void fn_80006F1C(void* dst, s32 flag);
extern void fn_80006DA0(void* dst, s32 flag);
extern s32 fn_801CB460(s32 type);
extern s16* fn_801CB6A0(s16* p, s32 type);
extern s16* fn_801CB51C(s16* p, s32 type);
extern void* fn_801E1C7C(s32 size);
extern void fn_801E17E0(void* p);
extern void DCStoreRange(void* addr, u32 nBytes);
extern void DCStoreRangeNoSync(void* addr, u32 nBytes);
extern void PPCSync(void);
extern void GXInvalidateVtxCache(void);
extern NJS_POINT3 lbl_802F6800;

void fn_801E86A0(CnkObject* obj);
void fn_801E85BC(ChunkSetList* list, s16 dx, s16 dy);
void fn_801E89D0(CnkObject* obj, s16 dx, s16 dy);

u16 fn_801E7654(NJS_MOTION* a, f32* d0, f32* d6, s32* d7, s32* d8, f32 frame) {
    void** base;
    void** cnt;
    s32 flag;
    s32 bit;
    s32 n;
    s32 kind = a->inp_fn & 0xF;
    void** t;
    void** p0;
    void** p1;
    if (kind == 1) { t = a->mdata; p0 = t; p1 = (void**)((u8*)t + 4); }
    else if (kind == 2) { t = a->mdata; p0 = t; p1 = (void**)((u8*)t + 8); }
    else if (kind == 3) { t = a->mdata; p0 = t; p1 = (void**)((u8*)t + 0xC); }
    else if (kind == 4) { t = a->mdata; p0 = t; p1 = (void**)((u8*)t + 0x10); }
    else if (kind == 5) { t = a->mdata; p0 = t; p1 = (void**)((u8*)t + 0x14); }
    flag = (a->inp_fn >> 6) & 1;
    fn_800071D8(a, frame);
    base = p0; cnt = p1;
    n = 0;
    for (bit = 0; bit < 12; bit++) {
        if (a->type & (1 << bit)) {
            switch (bit) {
            case 0:
                fn_80007080(d0, flag);
                break;
            case 6: {
                s32 i = (s32)(frame * ((f32)(u32)*cnt / (f32)a->nbFrame));
                f32* q = ((KeyVec*)*base)[i].v;
                d6[0] = q[0]; d6[1] = q[1]; d6[2] = q[2];
                break; }
            case 7: {
                KeyInt* t = (KeyInt*)*base;
                s32 i = (s32)(frame * ((f32)(u32)*cnt / (f32)a->nbFrame));
                *d7 = t[i].val;
                break; }
            case 8: {
                KeyInt* t = (KeyInt*)*base;
                s32 i = (s32)(frame * ((f32)(u32)*cnt / (f32)a->nbFrame));
                *d8 = t[i].val;
                break; }
            }
            base++; cnt++; n++;
        }
    }
    return (u16)n;
}

s32 fn_801E78C8(NJS_MOTION* a, void* d1, void* d2, void* d4, f32 frame) {
    s32 kind = a->inp_fn & 0xF;
    s32 m = a->type & 7;
    s32 i;
    void** tbl;
    u8 flag;
    if (kind == 1) {
        if (a->mdata[0] == 0) return 0;
        flag = (a->inp_fn >> 6) & 1;
        fn_800071D8(a, frame);
        if (d1 != NULL && (m & 1)) {
            fn_80007080(d1, flag);
        } else if (d2 != NULL && (m & 2)) {
            fn_80006F1C(d2, flag);
        } else if (d4 != NULL && (m & 4)) {
            fn_80006DA0(d4, flag);
        } else {
            m = 0;
        }
    } else if (kind == 2) {
        tbl = a->mdata;
        flag = (a->inp_fn >> 6) & 1;
        i = 0;
        fn_800071D8(a, frame);
        if (a->type & 1) {
            if (d1 != NULL && tbl[0] != NULL) {
                fn_80007080(d1, flag);
            } else {
                m &= 0xFFFE;
            }
            i = 1;
        }
        if (m & 2) {
            if (d2 != NULL && tbl[i] != NULL) {
                fn_80006F1C(d2, flag);
            } else {
                m &= 0xFFFD;
            }
            i++;
        }
        if (m & 4) {
            if (d4 != NULL && tbl[i] != NULL) {
                fn_80006DA0(d4, flag);
            } else {
                m &= 0xFFFB;
            }
        }
    } else if (kind == 3) {
        tbl = a->mdata;
        flag = (a->inp_fn >> 6) & 1;
        i = 0;
        fn_800071D8(a, frame);
        if (a->type & 1) {
            if (d1 != NULL && tbl[0] != NULL) {
                fn_80007080(d1, flag);
            } else {
                m &= 0xFFFE;
            }
            i = 1;
        }
        if (m & 2) {
            if (d2 != NULL && tbl[i] != NULL) {
                fn_80006F1C(d2, flag);
            } else {
                m &= 0xFFFD;
            }
            i++;
        }
        if (m & 4) {
            if (d4 != NULL && tbl[i] != NULL) {
                fn_80006DA0(d4, flag);
            } else {
                m &= 0xFFFB;
            }
        }
    } else {
        return 0;
    }
    return m;
}

s32 fn_801E7B2C(NJS_MOTION* o, void* a, void* b, f32 frame) {
    s32 flag;
    s32 idx;
    s32 kind = o->inp_fn & 0xF;
    void** t;
    s32 m = (u16)(o->type & 3);
    if (kind == 1) {
        if (o->mdata[0] == 0) return 0;
        flag = (o->inp_fn >> 6) & 1;
        fn_800071D8(o, frame);
        if (a != 0 && (m & 1)) {
            fn_80007080(a, flag);
        } else if (b != 0 && (m & 2)) {
            fn_80006F1C(b, flag);
        } else {
            m = 0;
        }
    } else if (kind == 2) {
        t = o->mdata;
        flag = (o->inp_fn >> 6) & 1;
        idx = 0;
        fn_800071D8(o, frame);
        if (m & 1) {
            if (a != 0 && t[0] != 0) {
                fn_80007080(a, flag);
            } else {
                m &= 0xFFFE;
            }
            idx = 1;
        }
        if (t[idx] != 0 && (m & 2) && b != 0) {
            fn_80006F1C(b, flag);
        } else {
            m &= 0xFFFD;
        }
    } else {
        return 0;
    }
    return m;
}

void fn_801E7C6C(NJS_POINT3* out, f32 a, f32 b, NJS_MOTION* o) {
    NJS_POINT3 p0;
    NJS_POINT3 p1;
    NJS_POINT3 pos;
    Angle ang[3];
    NJS_POINT3 off;
    NJS_MATRIX m;
    u32 f1;
    u32 f2;
    u32 f4;
    u16 flags;
    flags = fn_801E78C8(o, &pos, ang, &off, b);
    njUnitMatrix(m);
    f1 = flags & 1;
    if (f1) njTranslate(m, pos.x, pos.y, pos.z);
    f2 = flags & 2;
    if (f2) njRotateXYZ(m, ang[0], ang[1], ang[2]);
    f4 = flags & 4;
    if (f4) njTranslate(m, off.x, off.y, off.z);
    njCalcPoint(m, &lbl_802F6800, &p0);
    fn_801E78C8(o, &pos, ang, &off, a);
    njUnitMatrix(m);
    if (f1) njTranslate(m, pos.x, pos.y, pos.z);
    if (f2) njRotateXYZ(m, ang[0], ang[1], ang[2]);
    if (f4) njTranslate(m, off.x, off.y, off.z);
    njCalcPoint(m, &lbl_802F6800, &p1);
    out->x = p1.x - p0.x;
    out->y = p1.y - p0.y;
    out->z = p1.z - p0.z;
}

void fn_801E7DF0(ModelObj* o) { fn_801E86A0(&o->sub); }

void fn_801E7E14(ModelObj* o, s16 a, s16 b, s32 mode) {
    if (mode == 0) b = 0;
    else if (mode == 1) a = 0;
    fn_801E89D0(&o->sub, a, b);
    PPCSync();
    GXInvalidateVtxCache();
}

void fn_801E7E5C(ChunkSetList* list, s32 delta) {
    s32 groups;
    s32 n;
    s32 stride;
    s16* p;
    s16* idx;
    s16* data;
    s32 count;
    s32 left;
    ChunkSet* s;
    s16 bad;
    s16 add;
    s32 left2;
    s16* data2;
    bad = 0;
    count = list->num;
    s = list->sets;
    do {
        data = s->plist;
        idx = s->offsets;
        left = s->len - 1;
        do {
            left--;
            p = data + *idx++;
            stride = fn_801CB460(p[0] & 0xFF);
            groups = p[2] & ~0xC000;
            p += 3;
            do {
                n = *p++;
                if (n >= 0) ; else n = -n;
                p += stride * n;
                left -= n * 2;
                do {
                    idx[1] += delta;
                    if (idx[1] <= -0x4000 || idx[1] >= 0x800) bad = idx[1];
                    idx += 2;
                } while (--n > 0);
            } while (--groups > 0);
        } while (left > 0);
        s++;
    } while (--count > 0);
    if (bad != 0) {
        count = list->num;
        s = list->sets;
        { s32 fix = -0x4000; if (bad < 0x4000) fix = 0x4000; add = fix; }
        do {
            data2 = s->plist;
            idx = s->offsets;
            left2 = s->len - 1;
            do {
                left2--;
                p = data2 + *idx++;
                stride = fn_801CB460(p[0] & 0xFF);
                groups = p[2] & ~0xC000;
                p += 3;
                do {
                    n = *p++;
                    if (n >= 0) ; else n = -n;
                    p += stride * n;
                    left2 -= n * 2;
                    do {
                        idx[1] += add;
                        idx += 2;
                    } while (--n > 0);
                } while (--groups > 0);
            } while (left2 > 0);
            s++;
        } while (--count > 0);
    }
}

void fn_801E8004(ChunkSetList* list, s32 delta) {
    s32 groups;
    s32 n;
    s32 stride;
    s16* p;
    s16* idx;
    s16* data;
    s32 count;
    s32 left;
    ChunkSet* s;
    s16 bad;
    s16 add;
    s32 left2;
    s16* data2;
    bad = 0;
    count = list->num;
    s = list->sets;
    do {
        data = s->plist;
        idx = s->offsets;
        left = s->len - 1;
        do {
            left--;
            p = data + *idx++;
            stride = fn_801CB460(p[0] & 0xFF);
            groups = p[2] & ~0xC000;
            p += 3;
            do {
                n = *p++;
                if (n >= 0) ; else n = -n;
                p += stride * n;
                left -= n * 2;
                do {
                    idx[0] += delta;
                    if (idx[0] <= -0x4000 || idx[0] >= 0x800) bad = idx[0];
                    idx += 2;
                } while (--n > 0);
            } while (--groups > 0);
        } while (left > 0);
        s++;
    } while (--count > 0);
    if (bad != 0) {
        count = list->num;
        s = list->sets;
        { s32 fix = -0x4000; if (bad < 0x4000) fix = 0x4000; add = fix; }
        do {
            data2 = s->plist;
            idx = s->offsets;
            left2 = s->len - 1;
            do {
                left2--;
                p = data2 + *idx++;
                stride = fn_801CB460(p[0] & 0xFF);
                groups = p[2] & ~0xC000;
                p += 3;
                do {
                    n = *p++;
                    if (n >= 0) ; else n = -n;
                    p += stride * n;
                    left2 -= n * 2;
                    do {
                        idx[0] += add;
                        idx += 2;
                    } while (--n > 0);
                } while (--groups > 0);
            } while (left2 > 0);
            s++;
        } while (--count > 0);
    }
}

void fn_801E81AC(CnkObject* o, ChunkSet** strips, s16** out) {
    if (o->model != 0 && !(o->flags & 8)) {
    s32 c;
    s32 total;
    s16* start;
    s16* d;
    s16* dst;
    s16* head;
    s32 skip;
    s32 stride;
        d = o->model->plist;
        total = 0;
        dst = *out;
        start = d;
        do {
            head = d;
            c = *d++ & 0xFF;
            stride = fn_801CB460(c);
            if (stride >= 0) skip = *d++;
            else skip = stride & 0xFFFF;
            if (stride > 0) {
                switch (c) {
                case 0x41: case 0x42: case 0x44: case 0x45:
                case 0x47: case 0x48: {
                    s16* q;
                    s32 groups;
                    *dst++ = (u32)((u8*)head - (u8*)start) >> 1;
                    q = d;
                    total++;
                    groups = *q++ & ~0xC000;
                    do {
                        s32 n = *q++;
                        if (n >= 0) ; else n = -n;
                        total += n * 2;
                        do {
                            dst[0] = q[1];
                            dst[1] = q[2];
                            q += stride;
                            dst += 2;
                        } while (--n > 0);
                    } while (--groups > 0);
                    break;
                }
                }
            }
            d += skip;
        } while (c != 0xFF);
        if (total != 0) {
            *dst = -1;
            (*strips)->len = total + 1;
            (*strips)->plist = start;
            (*strips)->offsets = *out;
            *out = dst + 1;
            *strips = *strips + 1;
        }
    }
    if (o->child != 0 && !(o->flags & 0x10)) fn_801E81AC(o->child, strips, out);
    if (o->sibling != 0) fn_801E81AC(o->sibling, strips, out);
}

void fn_801E8360(CnkObject* o, s32* nodes, s32* shorts) {
    if (o->model != 0 && !(o->flags & 8)) {
    s32 c;
    s32 skip;
    s32 stride;
    s32 total;
    s16* d;
        d = o->model->plist;
        total = 0;
        do {
            c = *d++ & 0xFF;
            stride = fn_801CB460(c);
            if (stride >= 0) skip = *d++;
            else skip = stride & 0xFFFF;
            if (stride > 0) {
                switch (c) {
                case 0x41: case 0x42: case 0x44: case 0x45:
                case 0x47: case 0x48: {
                    s32 groups = d[0] & ~0xC000;
                    s16* q = d + 1;
                    total++;
                    do {
                        s32 n = *q;
                        if (n >= 0) ; else n = -n;
                        total += n * 2;
                        q += stride * n + 1;
                    } while (--groups > 0);
                    break;
                }
                }
            }
            d += skip;
        } while (c != 0xFF);
        if (total != 0) {
            *shorts = total + 1 + *shorts;
            (*nodes)++;
        }
    }
    if (o->child != 0 && !(o->flags & 0x10)) fn_801E8360(o->child, nodes, shorts);
    if (o->sibling != 0) fn_801E8360(o->sibling, nodes, shorts);
}

ChunkSetList* fn_801E84C0(CnkObject* o) {
    s32 nodes;
    s32 shorts;
    ChunkSetList* h;
    ChunkSet* p;
    s16* q;
    shorts = 0;
    nodes = 0;
    fn_801E8360(o, &nodes, &shorts);
    if (nodes == 0 || shorts == 0) return 0;
    h = fn_801E1C7C((nodes * 12 + 12) + shorts * 2);
    if (h != 0) {
        p = (ChunkSet*)(h + 1);
        q = (s16*)(p + nodes);
        h->num = nodes;
        h->sets = p;
        h->owner = o;
        fn_801E81AC(o, &p, &q);
    }
    return h;
}

void fn_801E8580(ChunkSetList* o) { fn_801E85BC(o, 0, 0); fn_801E17E0(o); }

void fn_801E85BC(ChunkSetList* list, s16 dx, s16 dy) {
    ChunkSet* set;
    s16* src;
    s16* base;
    s32 n;
    s32 remaining;
    s16* p;

    n = list->num;
    set = list->sets;
    do {
        base = set->plist;
        src = set->offsets;
        remaining = set->len - 1;
        do {
            s32 stride;
            s32 strips;
            remaining--;
            p = base + *src++;
            stride = fn_801CB460(p[0] & 0xFF);
            strips = p[2] & ~0xC000;
            p += 3;
            do {
                s32 cnt = *p++;
                if (cnt >= 0) {
                } else {
                    cnt = -cnt;
                }
                remaining -= cnt * 2;
                do {
                    p[1] = src[0] + dx;
                    p[2] = src[1] + dy;
                    src += 2;
                    p += stride;
                } while (--cnt > 0);
            } while (--strips > 0);
        } while (remaining > 0);
        DCStoreRange(base, (u8*)p - (u8*)base);
        set++;
    } while (--n > 0);
    PPCSync();
}

inline void CnkClearChunks(CnkObject* obj) {
    CnkModel* m = obj->model;
    if (m != NULL && !(obj->flags & 8)) {
        s16* p;
        for (p = fn_801CB6A0(m->plist, 8); p != NULL; p = fn_801CB51C(p, 8)) {
            *p &= ~0x3000;
        }
    }
}

inline void CnkWalk2(CnkObject* obj) {
    CnkClearChunks(obj);
    if (obj->child != NULL && !(obj->flags & 0x10)) {
        fn_801E86A0(obj->child);
    }
    if (obj->sibling != NULL) {
        fn_801E86A0(obj->sibling);
    }
}

inline void CnkWalk1(CnkObject* obj) {
    CnkClearChunks(obj);
    if (obj->child != NULL && !(obj->flags & 0x10)) {
        CnkWalk2(obj->child);
    }
    if (obj->sibling != NULL) {
        CnkWalk2(obj->sibling);
    }
}

void fn_801E86A0(CnkObject* obj) {
    CnkClearChunks(obj);
    if (obj->child != NULL && !(obj->flags & 0x10)) {
        CnkWalk1(obj->child);
    }
    if (obj->sibling != NULL) {
        CnkWalk1(obj->sibling);
    }
}

void fn_801E89D0(CnkObject* obj, s16 dx, s16 dy) {
    s16* p;
    s16 ox;
    s16 oy;
    s32 type;
    s32 size;
    s32 len;

    if (obj->model != NULL && !(obj->flags & 8) && obj->model->plist != NULL) {
        p = obj->model->plist;
        oy = 0;
        ox = 0;
        do {
            type = *p++ & 0xFF;
            size = fn_801CB460(type);
            if (size >= 0) {
                len = *p++;
            } else {
                len = size & 0xFFFF;
            }
            if (size > 0) {
                switch (type) {
                case 0x41: case 0x42: case 0x44: case 0x45: case 0x47: case 0x48: {
                    s32 strips = p[0] & ~0xC000;
                    s32 cnt;
                    s16* q;
                    size = (size - 1) * 2;
                    q = p + 1;
                    do {
                        cnt = *q;
                        if (cnt >= 0) {
                        } else {
                            cnt = -cnt;
                        }
                        q += 2;
                        do {
                            s16 t;
                            q[0] += dx;
                            t = q[0];
                            if (t <= -0x4000 || t >= 0x4000) {
                                ox = t;
                            }
                            q[1] += dy;
                            t = *++q;
                            if (t <= -0x4000 || t >= 0x4000) {
                                oy = t;
                            }
                            q = (s16*)((u8*)q + size);
                        } while (--cnt > 0);
                        q--;
                    } while (--strips > 0);
                    break;
                }
                }
            }
            p += len;
        } while (type != 0xFF);
        DCStoreRangeNoSync(obj->model->plist, (u8*)p - (u8*)obj->model->plist);
        if (ox != 0 || oy != 0) {
            p = obj->model->plist;
            if (ox != 0) {
                s32 v = -0x4000;
                if (ox < 0x4000) {
                    v = 0x4000;
                }
                ox = v;
            }
            if (oy != 0) {
                s32 v = -0x4000;
                if (oy < 0x4000) {
                    v = 0x4000;
                }
                oy = v;
            }
            do {
                type = *p++ & 0xFF;
                size = fn_801CB460(type);
                if (size >= 0) {
                    len = *p++;
                } else {
                    len = size & 0xFFFF;
                }
                if (size > 0) {
                    switch (type) {
                    case 0x41: case 0x42: case 0x44: case 0x45: case 0x47: case 0x48: {
                        s32 strips = p[0] & ~0xC000;
                        s16* q;
                        size = (size - 1) * 2;
                        q = p + 1;
                        do {
                            s32 cnt = *q;
                            if (cnt >= 0) {
                            } else {
                                cnt = -cnt;
                            }
                            q += 2;
                            do {
                                q[0] += ox;
                                *++q += oy;
                                q = (s16*)((u8*)q + size);
                            } while (--cnt > 0);
                            q--;
                        } while (--strips > 0);
                        break;
                    }
                    }
                }
                p += len;
            } while (type != 0xFF);
        }
        DCStoreRangeNoSync(obj->model->plist, (u8*)p - (u8*)obj->model->plist);
    }
    if (obj->child != NULL && !(obj->flags & 0x10)) {
        fn_801E89D0(obj->child, dx, dy);
    }
    if (obj->sibling != NULL) {
        fn_801E89D0(obj->sibling, dx, dy);
    }
}
