#include "game/scptact.h"

void fn_800FF9FC(void *p);
extern u8 lbl_8030B4D4[];
void fn_801003F4(void *p);
void fn_800D2CA8(s32 a);
void fn_80210CE4(void);
void fn_800976EC(u32 a);
extern void fn_80097294(u8 a);
extern void fn_80097270(f32 a, f32 b, f32 c);
extern void fn_8009724C(f32 a, f32 b, f32 c);
extern void fn_800971C4(f32 a);
extern void fn_800971E0(s32 a, s32 b, s32 c);
extern void fn_80097150(s32 a);
extern void fn_80097118(f32 a);
extern void fn_800970FC(f32 a);
extern void fn_80097318(s8 x);
void fn_80216E38(u32 n, char *p);
void fn_8016D904(s32 n);
void fn_801E749C(float *v);
void fn_800FF780(u8 *p);
extern s32 lbl_803473B4;
void fn_800D2C44(u16 v);
void fn_8022D34C(s32 a, f32 b);
void fn_801002D0(void *p);
s32 fn_8011768C(u32 flags);
extern void *lbl_8034759C;
extern s32 lbl_803473C0;
void fn_801BEA70(void *a, u32 idx, u8 mode);
typedef struct { u8 pad0[0x190]; f32 f190; } Obj_80207630;
s32 fn_8015F1F0(void *o);
extern void fn_8009701C(s8 a);
void fn_80097204(f32 a, f32 b, f32 c);
void fn_800972E0(s32 a);
void fn_80225CAC(s32 a, u16 b, s16 c);
void fn_80118578(s32 a, f32 f1, f32 f2, f32 f3, f32 f4);
extern void fn_801CBBBC(void);
extern s32 lbl_80347508;
extern f32 lbl_80347510;
extern f32 lbl_80347514;
extern u32 lbl_80347518;
extern void fn_8015F654(void* p);
extern s32 rand(void);
extern void fn_801D995C(s32 n, f32 a, f32 b, f32 c);
extern void fn_800D2554(f32 x, f32 y);
extern void fn_800D25C4(u32 rgb, s32 n);
extern void fn_800D258C(s32 n, f32 a, f32 b);
extern void fn_80097094(u16 a, f32 b);
extern void fn_80097228(f32 a, f32 b, f32 c);
extern void fn_800971A8(f32 a);
extern void fn_80097134(s32 a);
extern void fn_800970D8(u16 a, f32 b, s32 c);
extern void fn_800970B4(u16 a, f32 b, s32 c);
extern void fn_80097188(f32 a, f32 b);
extern void fn_8009716C(s16 a);
extern void fn_801185A8(s32 a, f32 b, f32 c, f32 d, f32 e, f32 f, f32 g);
typedef struct Pad {
    u8 pad0[8];
    u32 flags;
} Pad;
typedef struct PadInfo {
    Pad* pad;
    u8 pad4[0x14];
} PadInfo;
extern PadInfo lbl_80311A60;
extern void fn_801D9864(s32 n, f32 a, f32 b, f32 c, f32 d, f32 e, f32 g);
extern void fn_801D9A0C(s32 n, f32 a, f32 b, f32 c, f32 d, f32 e, f32 f, f32 g, f32 h);
s32 fn_8009763C(void);
void fn_800972AC(void);
s32 fn_8010038C(void *p);
extern void fn_800C1A34(s32 a, s32 b, s32 c, s32 d);
extern void fn_801D9728(s32 n, s32 mode, f32 a, f32 b, f32 c, f32 d, f32 e, f32 f, f32 g, f32 h);
extern s32 fn_801F3F88(void* p, s8 i);
typedef struct Info_801FE06C {
    u8 pad0[0x38];
    f32 x38;
    f32 x3c;
    f32 x40;
    s32 x44;
    s32 x48;
    s32 x4c;
    f32 x50;
    f32 x54;
    f32 x58;
} Info_801FE06C;
void fn_801BEAE4(void *a, s32 b);
void fn_801E74C8(s32 v);
s32 fn_80100424(void *p);
typedef struct ScrObj {
    u8 pad0[0x1c];
    f32* script;
} ScrObj;
extern void fn_8015F6C0(void* obj, u16 a, s32 c, f32* pos, s32* ivec);

void fn_8021331C(s32 n, f32 **in, f32 **out);
void fn_80213718(f32 *pt, s32 *ang, f32 *out, f32 d);
f32 fn_80212A78(s32 kind, f32 t, f32 dur);

void fn_8021331C(s32 n, f32 **in, f32 **out);
void fn_80213718(f32 *pt, s32 *ang, f32 *out, f32 d);
f32 fn_80212A78(s32 kind, f32 t, f32 dur);
extern f32 njTan(s32 a);

extern s16 fn_80207830(u16, Scpt *);
extern u32 fn_802107A4(Scpt *s, s32 id);

extern s16 fn_80209028(u16, Scpt *);
extern void fn_801165BC(s32 v);

extern s16 fn_80209330(u32, Scpt *);

extern void fn_800D2C94(s32 v);

extern void fn_800D2C84(s32 v);

extern void fn_800FF4EC(s32 v);

extern void fn_800FF5D0(s32 v);

extern void fn_800FF6B4(s32 v);

extern void fn_80216D98(s32 v);

void fn_80097294(u8 a);
void fn_80097204(f32 a, f32 b, f32 c);
void fn_80097318(s8 x);

void fn_80097228(f32 a, f32 b, f32 c);
void fn_80210EA4(u32 id, s32 v);

/* Defined in unit_8020EEE8.c; this file passes the id as an s32 (the callers there pass a u16). */
extern u32 fn_80210860(Scpt *s, s32 id);

/* lbl_8030E830: the twelve light records; the camera paths start from records 0, 7 and n + 8. */
typedef struct {
    s32 on;
    s32 mode;
    f32 a[3];
    f32 c[2];
    f32 b[3];
} PathInit;
extern PathInit lbl_8030E830[12];
s32 fn_80212050(void);
extern s32 fn_80210064(s32 a);

extern void fn_801CBBD8(void);

#ifdef NONMATCHING
/* A script command's argument stream (unit_801F5334.c). */
typedef struct Scpt_802074B0 {
    s32 kind;       /* 0x00 */
    s32 flags;      /* 0x04 */
    s32 handle;     /* 0x08 */
    void *ev;       /* 0x0c */
    s16 cnt;        /* 0x10 */
    u16 x12;        /* 0x12 */
    s32 x14;        /* 0x14 */
    s32 owner;      /* 0x18 */
    f32 *cur;       /* 0x1c */
} Scpt_802074B0;
void fn_800C8E44(f32 a, f32 b, f32 c);
/* One running script command (unit_801F5334.c); its argument stream mixes floats, ints and
 * length-prefixed strings, so the cursor is kept as a float pointer and the string helpers
 * take it as void*. */
typedef struct Track {
    u32 kind;       /* 0x00 */
    u8 pad04[0x14];
    u32 total;      /* 0x18 */
    f32 dist;       /* 0x1c */
    u32 step;       /* 0x20 */
    f32 start[3];   /* 0x24 */
} Track;
typedef struct Script {
    u8 pad00[0x1c];
    f32* cursor;    /* 0x1C */
    u8 pad20[0x10];
    Track* work;    /* 0x30 */
} Script;
extern f32 lbl_802F7528[4];
extern void fn_802136A8(f32* tab, f32* out, s32 a, s32 b, s32 c);
#endif

#define FREEALL(s, v) \
    for (v = 0; v < s->n; v++) { \
        if (s->xc[v] != NULL) { \
            fn_801E1784(s->xc[v]); \
            s->xc[v] = NULL; \
        } \
        if (s->x14[v] != NULL) { \
            fn_801E1784(s->x14[v]); \
            s->x14[v] = NULL; \
        } \
        if (s->x10[2 * v] != NULL) { \
            fn_801E1784(s->x10[2 * v]); \
            s->x10[2 * v] = NULL; \
        } \
        if (s->x10[2 * v + 1] != NULL) { \
            fn_801E1784(s->x10[2 * v + 1]); \
            s->x10[2 * v + 1] = NULL; \
        } \
        if (s->x18[2 * v] != NULL) { \
            fn_801E1784(s->x18[2 * v]); \
            s->x18[2 * v] = NULL; \
        } \
        if (s->x18[2 * v + 1] != NULL) { \
            fn_801E1784(s->x18[2 * v + 1]); \
            s->x18[2 * v + 1] = NULL; \
        } \
    } \
    if (s->xc != NULL) { \
        fn_801E1784(s->xc); \
        s->xc = NULL; \
    } \
    if (s->x14 != NULL) { \
        fn_801E1784(s->x14); \
        s->x14 = NULL; \
    } \
    if (s->x10 != NULL) { \
        fn_801E1784(s->x10); \
        s->x10 = NULL; \
    } \
    if (s->x18 != NULL) { \
        fn_801E1784(s->x18); \
        s->x18 = NULL; \
    } \
    if (s->times != NULL) { \
        fn_801E1784(s->times); \
        s->times = NULL; \
    } \
    if (s->angles != NULL) { \
        fn_801E1784(s->angles); \
        s->angles = NULL; \
    } \
    if (s->x20 != NULL) { \
        fn_801E1784(s->x20); \
        s->x20 = NULL; \
    } \
    lbl_8030CEA0.x15cc = 0;

#define FREEALL_802034B0(s, v) \
if (s->xc[0] != NULL) { \
    fn_801E1784(s->xc[0]); \
    s->xc[0] = NULL; \
} \
if (s->x14[0] != NULL) { \
    fn_801E1784(s->x14[0]); \
    s->x14[0] = NULL; \
} \
for (v = 0; v < s->n - 1; v++) { \
    if (s->xc[v + 1] != NULL) { \
        fn_801E1784(s->xc[v + 1]); \
        s->xc[v + 1] = NULL; \
    } \
    if (s->x14[v + 1] != NULL) { \
        fn_801E1784(s->x14[v + 1]); \
        s->x14[v + 1] = NULL; \
    } \
    if (s->x10[2 * v] != NULL) { \
        fn_801E1784(s->x10[2 * v]); \
        s->x10[2 * v] = NULL; \
    } \
    if (s->x10[2 * v + 1] != NULL) { \
        fn_801E1784(s->x10[2 * v + 1]); \
        s->x10[2 * v + 1] = NULL; \
    } \
    if (s->x18[2 * v] != NULL) { \
        fn_801E1784(s->x18[2 * v]); \
        s->x18[2 * v] = NULL; \
    } \
    if (s->x18[2 * v + 1] != NULL) { \
        fn_801E1784(s->x18[2 * v + 1]); \
        s->x18[2 * v + 1] = NULL; \
    } \
} \
if (s->angles != NULL) { \
    fn_801E1784(s->angles); \
    s->angles = NULL; \
} \
if (s->xc != NULL) { \
    fn_801E1784(s->xc); \
    s->xc = NULL; \
} \
if (s->x14 != NULL) { \
    fn_801E1784(s->x14); \
    s->x14 = NULL; \
} \
if (s->x10 != NULL) { \
    fn_801E1784(s->x10); \
    s->x10 = NULL; \
} \
if (s->x18 != NULL) { \
    fn_801E1784(s->x18); \
    s->x18 = NULL; \
} \
if (s->times != NULL) { \
    fn_801E1784(s->times); \
    s->times = NULL; \
} \
lbl_8030CEA0.x15cc = 0;

#define FREEALL_80203FFC(s, v) \
if (s->xc[0] != NULL) { \
    fn_801E1784(s->xc[0]); \
    s->xc[0] = NULL; \
} \
if (s->x14[0] != NULL) { \
    fn_801E1784(s->x14[0]); \
    s->x14[0] = NULL; \
} \
for (v = 0; v < s->n - 1; v++) { \
    if (s->xc[v + 1] != NULL) { \
        fn_801E1784(s->xc[v + 1]); \
        s->xc[v + 1] = NULL; \
    } \
    if (s->x14[v + 1] != NULL) { \
        fn_801E1784(s->x14[v + 1]); \
        s->x14[v + 1] = NULL; \
    } \
    if (s->x10[2 * v] != NULL) { \
        fn_801E1784(s->x10[2 * v]); \
        s->x10[2 * v] = NULL; \
    } \
    if (s->x10[2 * v + 1] != NULL) { \
        fn_801E1784(s->x10[2 * v + 1]); \
        s->x10[2 * v + 1] = NULL; \
    } \
    if (s->x18[2 * v] != NULL) { \
        fn_801E1784(s->x18[2 * v]); \
        s->x18[2 * v] = NULL; \
    } \
    if (s->x18[2 * v + 1] != NULL) { \
        fn_801E1784(s->x18[2 * v + 1]); \
        s->x18[2 * v + 1] = NULL; \
    } \
} \
if (s->xc != NULL) { \
    fn_801E1784(s->xc); \
    s->xc = NULL; \
} \
if (s->x14 != NULL) { \
    fn_801E1784(s->x14); \
    s->x14 = NULL; \
} \
if (s->x10 != NULL) { \
    fn_801E1784(s->x10); \
    s->x10 = NULL; \
} \
if (s->x18 != NULL) { \
    fn_801E1784(s->x18); \
    s->x18 = NULL; \
} \
if (s->times != NULL) { \
    fn_801E1784(s->times); \
    s->times = NULL; \
} \
lbl_8030CEA0.x15cc = 0;

static inline s32 rdi(float **pp) {
    if (3.4028235e38f == **pp) {
        (*pp)++;
        return 0x7FFFFFFF;
    }
    return (s32)fn_801F6120(pp);
}
/* One word of the script stream at a byte position. */
static inline u32 StrWord(char* p)
{
    ScptCur c;
    c.s = p;
    return *c.u;
}
static inline void ReleaseAll(void)
{
    s32 i;
    for (i = 0; i < 256; i++) {
        if (lbl_8030CEA0.ent[i][0]) {
            fn_8020F934(lbl_8030CEA0.ent[i][1]);
        }
    }
}


s32 fn_801FCFF0(u16 flags, Scpt* o) {
    if (flags & 1) {
        f32* p;
        s32 who, chr;
        u32 bit;
        p = o->cur.f + 1;
        who = ReadInt(&p);
        chr = ReadInt(&p);
        bit = ReadInt(&p);
        o->cur.f = p;
        if (who == 6) {
            s32 i;
            lbl_80310B3C[bit >> 5] &= ~(1 << (bit & 31));
            for (i = 0; i < 4; i++) {
                if (fn_801F3F88(&lbl_8030B7F4.chr[lbl_8030B7F4.party[i]], chr)) {
                    lbl_80310B3C[bit >> 5] |= 1 << (bit & 31);
                }
            }
        } else if (fn_801F3F88(&lbl_8030B7F4.chr[who], chr)) {
            lbl_80310B3C[bit >> 5] |= 1 << (bit & 31);
        } else {
            lbl_80310B3C[bit >> 5] &= ~(1 << (bit & 31));
        }
    }
    return 0;
}


s32 fn_801FD1D0(u32 flags, Scpt *st) {
    if (flags & 1) {
        float *p = st->cur.f + 1;
        s32 n;
        if (*p == 3.4028235e38f) {
            p++;
            n = 0x7FFFFFFF;
        } else {
            n = (s32)fn_801F6120(&p);
        }
        st->cur.f = p;
        lbl_8030CEA0.x82c = 2;
        lbl_8030CEA0.x834 = n;
    }
    return 0;
}

s32 fn_801FD264(u16 flags, Scpt* o) {
    if (flags & 1) {
        f32* p;
        s32 i, cnt;
        PatStep* e;
        f32 v;
        p = o->cur.f + 1;
        cnt = *(s32 *)p++;
        lbl_8030CEA0.x828 = fn_80212050();
        lbl_8030CEA0.x842 = 0;
        lbl_8030CEA0.x844 = 0;
        lbl_8030CEA0.x83c = 0;
        e = lbl_8030CEA0.steps;
        for (i = 0; i < cnt; i++) {
            e->a = ReadInt(&p);
            e->b = ReadInt(&p);
            e->c = ReadInt(&p);
            if (e->c == 0) {
                lbl_8030CEA0.x838 = (s8)e->b;
                lbl_8030CEA0.x840 = i + 1;
                break;
            }
            e++;
        }
        if (i >= cnt) {
            e[-1].c = 0;
            lbl_8030CEA0.x840 = cnt;
            lbl_8030CEA0.x838 = (s8)e[-1].b;
        }
        v = (s8)lbl_8030CEA0.steps[0].a;
        lbl_8030CEA0.x830 = v;
        lbl_8030CEA0.x82c = 3;
        o->cur.f = p;
    }
    return 0;
}

s32 fn_801FD44C(u32 flags, Scpt *c) {
    u16 f = flags;
    if (flags & 1) {
        ScptCur cur;
        s32 i;
        s32 n;
        s32 t;
        Obj10A *a;
        cur.f = c->cur.f;
        cur.f++;
        n = *cur.i++;
        for (i = 0; i < n; i++) {
            u16 id;
            if (*cur.f == 3.4028235e38f) {
                cur.f++;
                t = 0x7FFFFFFF;
            } else {
                t = fn_801F6120(&cur.f);
            }
            id = t;
            a = fn_8010A164(id);
            if (a != 0) {
                a->x19 = 0xff;
                a->fn(a);
            }
        }
        c->cur.f = cur.f;
        return 0;
    }
    return !(f & 8);
}

s32 fn_801FD54C(u32 a, Scpt *st) {
    if (a & 1) {
        u8 *c = st->cur.b;
        st->cur.b = c + 4;
        fn_800FF9FC(c);
    }
    return 0;
}

s32 fn_801FD584(u32 flags, Scpt* c) {
    float* p;
    s32 t;
    Obj10A* o;
    if (flags & 1) {
        p = c->cur.f + 1;
        RDI(p);
        t = RDI(p);
        c->cur.f = p;
        o = fn_8010A164(t);
        if (o == 0) {
            fn_801DBE1C("scptParentOffD: task nothing #%d", t);
        }
        fn_8015F654(o->x24);
        return 0;
    }
    return 1;
}

s32 fn_801FD668(u16 flags, ScrObj* o) {
    if (flags & 1) {
        f32* p;
        s32 iv[3];
        struct {
            u16 a;
            u16 b;
            s32 c;
            f32 f[10];
        } m;
        Obj10A* t;
        p = o->script + 1;
        m.a = ReadInt(&p);
        m.c = ReadInt(&p);
        m.b = ReadInt(&p);
        m.f[0] = fn_801F6120(&p);
        m.f[1] = fn_801F6120(&p);
        m.f[2] = fn_801F6120(&p);
        m.f[3] = fn_801F6120(&p);
        m.f[4] = fn_801F6120(&p);
        m.f[5] = fn_801F6120(&p);
        iv[0] = 182.04445f * m.f[3];
        iv[1] = 182.04445f * m.f[4];
        iv[2] = 182.04445f * m.f[5];
        o->script = p;
        t = fn_8010A164(m.b);
        if (t == 0) {
            fn_801DBE1C("scptParentOnD: task nothing #%d", m.b);
        }
        fn_8015F6C0(t->x24, m.a, m.c, m.f, iv);
        return 0;
    }
    return 1;
}

s32 fn_801FD850(u32 flags, Scpt *st) {
    u16 f = flags;
    if (flags & 1) {
        float *p = st->cur.f + 1;
        s32 n;
        if (*p == 3.4028235e38f) {
            p++;
            n = 0x7FFFFFFF;
        } else {
            n = (s32)fn_801F6120(&p);
        }
        fn_8016D904(n);
        st->cur.f = p;
    }
    if (f & 8) return 1;
    return 0;
}

s16 fn_801FD8F0(u32 a, Scpt *s) {
    u16 f = a;
    u32 flags;
    s16 r;
    if (a & 1) {
        s->cur.u += 1;
        flags = lbl_80310B3C[32];
        if ((flags >> 8) & 1) lbl_8030B7F4.chr[0].mp = lbl_8030B7F4.chr[0].mpMax;
        if (flags & 0x200) lbl_8030B7F4.chr[1].mp = lbl_8030B7F4.chr[1].mpMax;
        if (flags & 0x400) lbl_8030B7F4.chr[2].mp = lbl_8030B7F4.chr[2].mpMax;
        if (flags & 0x800) lbl_8030B7F4.chr[3].mp = lbl_8030B7F4.chr[3].mpMax;
        if (flags & 0x1000) lbl_8030B7F4.chr[4].mp = lbl_8030B7F4.chr[4].mpMax;
        if (flags & 0x2000) lbl_8030B7F4.chr[5].mp = lbl_8030B7F4.chr[5].mpMax;
    }
    r = (f >> 3) & 1;
    return r;
}

s16 fn_801FD9B0(u32 a, Scpt *s) {
    u16 f = a;
    u32 flags;
    s16 r;
    if (a & 1) {
        s->cur.u += 1;
        flags = lbl_80310B3C[32];
        if ((flags >> 8) & 1) lbl_8030B7F4.chr[0].hp = lbl_8030B7F4.chr[0].hpMax;
        if (flags & 0x200) lbl_8030B7F4.chr[1].hp = lbl_8030B7F4.chr[1].hpMax;
        if (flags & 0x400) lbl_8030B7F4.chr[2].hp = lbl_8030B7F4.chr[2].hpMax;
        if (flags & 0x800) lbl_8030B7F4.chr[3].hp = lbl_8030B7F4.chr[3].hpMax;
        if (flags & 0x1000) lbl_8030B7F4.chr[4].hp = lbl_8030B7F4.chr[4].hpMax;
        if (flags & 0x2000) lbl_8030B7F4.chr[5].hp = lbl_8030B7F4.chr[5].hpMax;
    }
    r = (f >> 3) & 1;
    return r;
}

s32 fn_801FDA70(u32 a, Scpt *st) {
    u16 f = a;
    if (a & 1) {
        st->cur.b += 4;
        *(u32 *)&lbl_8030B7F4.x1568.x157c = *(u32 *)(lbl_8030B4D4 + 0x2dc);
    }
    if (f & 8) return 1;
    return 0;
}

s32 fn_801FDAB8(u16 flags, Scpt* o) {
    if (flags & 1) {
        f32* p = o->cur.f + 1;
        ScrState* s = fn_801E1A2C(1, 0x44);
        if (s == 0) {
            fn_801DBE1C("scptKeyWait: malloc failed");
        }
        o->work.scrState = s;
        s->mode = ReadInt(&p);
        s->count = ReadInt(&p);
        o->cur.f = p;
    }
    if (flags & 2) {
        ScrState* s = o->work.scrState;
        if (--s->count == 0) {
            return 0;
        }
        switch (s->mode) {
        case 0:
            if (lbl_80311A60.pad->flags & 0x100) {
                return 0;
            }
        case 1:
            if (lbl_80311A60.pad->flags & 0x1000) {
                return 0;
            }
        case 2:
            if (lbl_80311A60.pad->flags & 0x1f00) {
                return 0;
            }
        }
    }
    return !(flags & 8);
}

s32 fn_801FDC70(u32 flags, Scpt *st) {
    if (flags & 1) {
        float *p = st->cur.f + 1;
        if (*p == 3.4028235e38f) {
            p++;
        } else {
            fn_801F6120(&p);
        }
        st->cur.f = p;
    }
    return 0;
}

s32 fn_801FDCDC(u32 flags, Scpt *st) {
    s32 n;
    u16 f = flags;
    if (flags & 1) {
        float *p = st->cur.f + 1;
        if (*p == 3.4028235e38f) {
            p++;
            n = 0x7FFFFFFF;
        } else {
            n = (s32)fn_801F6120(&p);
        }
        st->cur.f = p;
        fn_801BEA70(lbl_8034759C, n, fn_8020E984());
    }
    if ((f & 2) && lbl_803473C0 == 0) return 0;
    if (f & 8) return 0;
    return 1;
}

s32 fn_801FDDB0(u32 a, Scpt *s) {
    u16 f = a;
    f32 *p;
    s32 v;
    if (a & 1) {
        p = s->cur.f + 1;
        if (3.4028235e38f == *p) {
            p++;
            v = 0x7FFFFFFF;
        } else {
            v = (s32)fn_801F6120(&p);
        }
        s->cur.f = p;
        fn_801BEAE4(lbl_8034759C, v);
    }
    if ((f & 2) && lbl_803473C0 == 0) return 0;
    if (f & 8) return 0;
    return 1;
}

s32 fn_801FDE70(u32 flags, Scpt *st) {
    u16 f = flags;
    if (flags & 1) {
        float a[4];
        float *p = st->cur.f + 1;
        a[0] = fn_801F6120(&p);
        a[1] = fn_801F6120(&p);
        a[2] = fn_801F6120(&p);
        a[3] = fn_801F6120(&p);
        st->cur.f = p;
        fn_801E749C(a);
    }
    if (f & 8) return 1;
    return 0;
}

s32 fn_801FDF0C(u32 a, Scpt *s) {
    u16 f = a;
    f32 *p;
    s32 v;
    if (a & 1) {
        p = s->cur.f + 1;
        if (3.4028235e38f == *p) {
            p++;
            v = 0x7FFFFFFF;
        } else {
            v = (s32)fn_801F6120(&p);
        }
        s->cur.f = p;
        if (v != 0) v = -1;
        fn_801E74C8(v);
    }
    if (f & 8) return 1;
    return 0;
}

s32 fn_801FDFB8(u32 a, Scpt *s) {
    u16 f = a;
    f32 *p;
    s32 v;
    if (a & 1) {
        p = s->cur.f + 1;
        if (3.4028235e38f == *p) {
            p++;
            v = 0x7FFFFFFF;
        } else {
            v = fn_801F6120(&p);
        }
        s->cur.f = p;
        lbl_8030CEA0.x15d4 = fn_801F452C(v);
    }
    if (f & 8) return 1;
    return 0;
}

s32 fn_801FE06C(u16 flags, Scpt* o) {
    if (flags & 1) {
        f32* p = o->cur.f + 1;
        void* q;
        u16 id;
        Info_801FE06C* n;
        f32 f;
        id = ReadInt(&p);
        o->cur.f = p;
        q = fn_8015F1A0(id);
        if (q == 0) {
            return 0;
        }
        n = fn_8015F180(q);
        f = n->x38;
        lbl_8030CEA0.x1584[8] = *(s32*)&f;
        f = n->x3c;
        lbl_8030CEA0.x1584[9] = *(s32*)&f;
        f = n->x40;
        lbl_8030CEA0.x1584[10] = *(s32*)&f;
        f = 0.005493164f * (f32)(n->x44 & 0xffff);
        lbl_8030CEA0.x1584[11] = *(s32*)&f;
        f = 0.005493164f * (f32)(n->x48 & 0xffff);
        lbl_8030CEA0.x1584[12] = *(s32*)&f;
        f = 0.005493164f * (f32)(n->x4c & 0xffff);
        lbl_8030CEA0.x1584[13] = *(s32*)&f;
        f = n->x50;
        lbl_8030CEA0.x1584[14] = *(s32*)&f;
        f = n->x54;
        lbl_8030CEA0.x1584[15] = *(s32*)&f;
        f = n->x58;
        lbl_8030CEA0.x1584[16] = *(s32*)&f;
    }
    if (flags & 8) {
        return 1;
    }
    return 0;
}

s32 fn_801FE21C(u16 flags, Scpt *st) {
    s32 i;
    if (flags & 1) {
        float *p = st->cur.f + 1;
        i = (*p == 3.4028235e38f) ? (p++, 0x7FFFFFFF) : (s32)fn_801F6120(&p);
        st->cur.f = p;
        lbl_8030CEA0.x1584[i] = (s32)(9999.0f * (3.0517578e-05f * (f32)rand()));
    }
    if (flags & 8) {
        return 1;
    }
    return 0;
}

s32 fn_801FE310(u16 flags, Scpt* o) {
    if (flags & 1) {
        f32* p;
        s32 r, g, b;
        u32 n;
        p = o->cur.f + 1;
        r = ReadInt(&p);
        g = ReadInt(&p);
        b = ReadInt(&p);
        lbl_8030CEA0.xc64 = fn_801F6120(&p);
        n = ReadInt(&p);
        o->cur.f = p;
        if (n == 0) {
            n = 1;
        }
        if (n == 0x7fffffff) {
            n = 30;
        }
        lbl_8030CEA0.xc54 = 0;
        lbl_8030CEA0.xc50 = n;
        lbl_8030CEA0.xc60.b[0] = 0;
        lbl_8030CEA0.xc60.b[1] = r;
        lbl_8030CEA0.xc60.b[2] = g;
        lbl_8030CEA0.xc60.b[3] = b;
    }
    if (flags & 2) {
        s32 cur;
        f32 v;
        lbl_8030CEA0.xc5c = 1;
        lbl_8030CEA0.xc54++;
        cur = lbl_8030CEA0.xc54;
        v = 255.0f * ((f32)cur / (f32)lbl_8030CEA0.xc50);
        lbl_8030CEA0.xc58 = v;
        if (v > 255.0f) {
            lbl_8030CEA0.xc60.b[0] = 0xff;
            return 0;
        }
        lbl_8030CEA0.xc60.b[0] = (u8)v;
        if (lbl_8030CEA0.xc50 == cur) {
            return 0;
        }
    }
    if (flags & 8) {
        lbl_8030CEA0.xc5c = 0;
        return 1;
    }
    return 1;
}

s32 fn_801FE560(u16 flags, Scpt* o) {
    if (flags & 1) {
        f32* p;
        s32 r, g, b;
        u32 n;
        p = o->cur.f + 1;
        r = ReadInt(&p);
        g = ReadInt(&p);
        b = ReadInt(&p);
        lbl_8030CEA0.xc64 = fn_801F6120(&p);
        n = ReadInt(&p);
        o->cur.f = p;
        if (n == 0) {
            n = 1;
        }
        if (n == 0x7fffffff) {
            n = 30;
        }
        lbl_8030CEA0.xc50 = lbl_8030CEA0.xc54 = n;
        lbl_8030CEA0.xc60.b[0] = 0xff;
        lbl_8030CEA0.xc60.b[1] = r;
        lbl_8030CEA0.xc60.b[2] = g;
        lbl_8030CEA0.xc60.b[3] = b;
    }
    if (flags & 2) {
        s32 cur;
        f32 v;
        lbl_8030CEA0.xc5c = 1;
        lbl_8030CEA0.xc54--;
        cur = lbl_8030CEA0.xc54;
        v = 255.0f * ((f32)cur / (f32)lbl_8030CEA0.xc50);
        lbl_8030CEA0.xc58 = v;
        if (v < 0.0f) {
            lbl_8030CEA0.xc60.b[0] = 0;
            lbl_8030CEA0.xc5c = 0;
            return 0;
        }
        lbl_8030CEA0.xc60.b[0] = (u8)v;
        if (cur == 0) {
            lbl_8030CEA0.xc5c = 0;
            return 0;
        }
    }
    return 1;
}

s32 fn_801FE7A0(u16 flags, Scpt* o) {
    if (flags & 1) {
        f32* p;
        u32 n;
        p = o->cur.f + 1;
        n = ReadInt(&p);
        o->cur.f = p;
        if (FlagTest(0x31) == 1) {
            return 0;
        }
        lbl_8030CEA0.xc60.w = 0xc0c0c0;
        lbl_8030CEA0.xc58 = 0.0f;
        if (n == 0) {
            n = 1;
        }
        if (n == 0x7fffffff) {
            n = 30;
        }
        lbl_8030CEA0.xc50 = n;
        lbl_8030CEA0.xc54 = 0;
        lbl_8030CEA0.xc64 = -1.0f;
    }
    if (flags & 2) {
        s32 cur;
        f32 v;
        lbl_8030CEA0.xc5c = 1;
        lbl_8030CEA0.xc54++;
        cur = lbl_8030CEA0.xc54;
        v = 255.0f * ((f32)cur / (f32)lbl_8030CEA0.xc50);
        lbl_8030CEA0.xc58 = v;
        if (v > 255.0f) {
            lbl_8030CEA0.xc60.b[0] = 0xff;
            return 0;
        }
        lbl_8030CEA0.xc60.b[0] = (u8)v;
        if (lbl_8030CEA0.xc50 == cur) {
            return 0;
        }
    }
    if (flags & 8) {
        lbl_8030CEA0.xc5c = 0;
        return 1;
    }
    return 1;
}

s32 fn_801FE960(u16 flags, Scpt* o) {
    if (flags & 1) {
        f32* p;
        u32 n;
        p = o->cur.f + 1;
        n = ReadInt(&p);
        o->cur.f = p;
        lbl_8030CEA0.xc60.w = 0xffc0c0c0;
        if (n == 0) {
            n = 1;
        }
        if (n == 0x7fffffff) {
            n = 30;
        }
        lbl_8030CEA0.xc50 = lbl_8030CEA0.xc54 = n;
        lbl_8030CEA0.xc64 = -1.0f;
    }
    if (flags & 2) {
        s32 cur;
        f32 v;
        lbl_8030CEA0.xc5c = 1;
        lbl_8030CEA0.xc54--;
        cur = lbl_8030CEA0.xc54;
        v = 255.0f * ((f32)cur / (f32)lbl_8030CEA0.xc50);
        lbl_8030CEA0.xc58 = v;
        if (v < 0.0f) {
            lbl_8030CEA0.xc60.b[0] = 0;
            lbl_8030CEA0.xc5c = 0;
            return 0;
        }
        lbl_8030CEA0.xc60.b[0] = (u8)v;
        if (cur == 0) {
            lbl_8030CEA0.xc5c = 0;
            return 0;
        }
    }
    if (flags & 8) {
        lbl_8030CEA0.xc5c = 0;
        return 1;
    }
    return 1;
}

s32 fn_801FEB08(u32 a, Scpt *st) {
    if (a & 1) {
        u8 *c = st->cur.b;
        st->cur.b = c + 4;
        fn_801F3148(c);
    }
    return 0;
}

s32 fn_801FEB40(u32 a, Scpt *st) {
    if (a & 1) {
        u8 *c = st->cur.b;
        st->cur.b = c + 4;
        fn_801F35A0(c);
    }
    return 0;
}
s32 fn_801FEB78(s32 flags, Scpt *s) {
    f32 *cur;
    s32 v;
    if (flags & 1) {
        cur = s->cur.f + 1;
        if (3.4028235e38f == *cur) {
            cur++;
            v = 0x7FFFFFFF;
        } else {
            v = (s32)fn_801F6120(&cur);
        }
        s->cur.f = cur;
        fn_800FF4EC(v);
    }
    return 0;
}
s32 fn_801FEBFC(s32 flags, Scpt *s) {
    f32 *cur;
    s32 v;
    if (flags & 1) {
        cur = s->cur.f + 1;
        if (3.4028235e38f == *cur) {
            cur++;
            v = 0x7FFFFFFF;
        } else {
            v = (s32)fn_801F6120(&cur);
        }
        s->cur.f = cur;
        fn_800FF5D0(v);
    }
    return 0;
}
s32 fn_801FEC80(s32 flags, Scpt *s) {
    f32 *cur;
    s32 v;
    if (flags & 1) {
        cur = s->cur.f + 1;
        if (3.4028235e38f == *cur) {
            cur++;
            v = 0x7FFFFFFF;
        } else {
            v = (s32)fn_801F6120(&cur);
        }
        s->cur.f = cur;
        fn_800FF6B4(v);
    }
    return 0;
}

s32 fn_801FED04(u32 a, Scpt *st) {
    if (a & 1) {
        u8 *c = st->cur.b;
        st->cur.b = c + 4;
        fn_800FF7A0(c);
    }
    return 0;
}

s32 fn_801FED3C(s32 flag, Scpt *c) {
    if (flag & 1) {
        c->cur.u = c->cur.u + 1;
    }
    return 0;
}

s32 fn_801FED58(u32 flags, Scpt *st) {
    u16 f = flags;
    if (flags & 1) {
        u8 *c = st->cur.b;
        st->cur.b = c + 4;
        fn_800FF780(c);
        return 1;
    }
    if ((f & 2) && lbl_803473B4 == 0) {
        return 0;
    }
    if (f & 8) {
        return 0;
    }
    return 1;
}

s32 fn_801FEDC8(void) {
    return 1;
}
s32 fn_801FEDD0(s32 flags, Scpt *s) {
    f32 *cur;
    s32 v;
    if (flags & 1) {
        cur = s->cur.f + 1;
        if (3.4028235e38f == *cur) {
            cur++;
            v = 0x7FFFFFFF;
        } else {
            v = (s32)fn_801F6120(&cur);
        }
        s->cur.f = cur;
        fn_80216D98(v);
    }
    return 0;
}

s32 fn_801FEE54(u32 flags, Scpt *st) {
    if (flags & 1) {
        float *p = st->cur.f + 1;
        s32 n;
        if (*p == 3.4028235e38f) {
            p++;
            n = 0x7FFFFFFF;
        } else {
            n = (s32)fn_801F6120(&p);
        }
        {
            u32 w;
            char *q = (char *)p;
            w = *(u32 *)q;
            p = (float *)(q + 4);
            st->cur.f = p;
            fn_80216E38(n, q + w);
        }
    }
    return 0;
}

int fn_801FEEE8(void) {
    fn_801DBE1C("scptDELL BG: SYNTAX ERROR!!!");
    return 0;
}

int fn_801FEF18(void) {
    fn_801DBE1C("scptINS BG: SYNTAX ERROR!!!");
    return 0;
}

s32 fn_801FEF48(u32 a, Scpt *st) {
    if (a & 1) {
        u8 *c = st->cur.b;
        st->cur.b = c + 4;
        fn_800FFA18(c);
    }
    return 0;
}

s32 fn_801FEF80(u32 flags, Scpt *c) {
    float *p;
    u16 a;
    s32 t;
    s32 b;
    if (flags & 1) {
        p = c->cur.f + 1;
        if (*p == 3.4028235e38f) {
            p++;
            t = 0x7FFFFFFF;
        } else {
            t = (s32)fn_801F6120(&p);
        }
        a = t;
        if (*p == 3.4028235e38f) {
            p++;
            b = 0x7FFFFFFF;
        } else {
            b = (s32)fn_801F6120(&p);
        }
        c->cur.f = p;
        fn_80225CAC(0xffff, a, b);
    }
    return 0;
}

s32 fn_801FF05C(u32 flags, Scpt *st) {
    u16 f = flags;
    if (flags & 1) {
        u8 *c = st->cur.b;
        u8 *q = c + 4;
        u32 w = *(u32 *)(c + 4);
        u8 *e = q + w;
        st->cur.b = q + 4;
        st->flags = 0;
        st->work.b = e;
    }
    if (f & 2) {
        if (fn_8010038C(st->work.b) == 1) {
            st->work.b = 0;
            return 0;
        }
    }
    if (f & 8) return 0;
    return 1;
}

s32 fn_801FF0F8(u32 a, Scpt *st) {
    if (a & 1) {
        u8 *c = st->cur.b;
        u8 *q = c + 4;
        u32 off = *(u32 *)(c + 4);
        st->cur.b = q + 4;
        fn_801003F4(q + off);
    }
    return 0;
}

s32 fn_801FF13C(u32 a, Scpt *s) {
    u16 f = a;
    u8 *q;
    u8 *end;
    if (a & 1) {
        q = s->cur.b + 4;
        end = q + s->cur.u[1];
        s->cur.b = q + 4;
        fn_80100424(end);
        s->work.p = end;
    }
    if (f & 2) {
        if (fn_8010038C(s->work.p) == 1) {
            s->work.p = 0;
            return 0;
        }
    }
    if (f & 8) return 0;
    return 1;
}

int fn_801FF1E0(void) {
    fn_801DBE1C("scptKill: SYNTAX ERROR!!!");
    return 0;
}

s32 fn_801FF210(u16 flags, Scpt *st) {
    if (flags & 1) {
        float *p = st->cur.f + 1;
        int a, b, c, d;
        a = RDI(p);
        b = RDI(p);
        c = RDI(p);
        d = RDI(p);
        st->cur.f = p;
        fn_800C1A34(a, b, c, d);
        st->flags = 0;
    }
    return 0;
}

s32 fn_801FF380(u32 flags, Scpt *cmd)
{
    if (flags & 1) {
        float *p;
        s32 a, b;
        Obj10A* c;
    Actor* m;
        p = cmd->cur.f + 1;
        a = RDI(p);
        b = RDI(p);
        cmd->cur.f = p;
        c = fn_8010A164(b);
        if (c != 0 && (m = c->x24) != 0 && m->b26c == 1) {
            m->x1d8->x1a0 = a;
        }
    }
    return 0;
}
s32 fn_801FF470(u16 flags, Scpt* o) {
    if (flags & 1) {
        f32* p = o->cur.f;
        Obj10A* t;
        u16 id;
        p++;
        id = ReadInt(&p);
        o->cur.f = p;
        t = fn_8010A164(id);
        if (t != 0) {
            s32 n;
            s32 size;
            Actor* e;
            s32 i;
            u32* copy;
            s32 j;
            e = t->x24;
            n = e->x1c8->x10[0];
            size = n * 4;
            copy = fn_801E1A2C(1, size);
            memcpy(copy, e->x1c8->x10 + 1, size);
            for (i = 1; i < n - 1; i += 2) {
                for (j = i + 2; j < n - 1; j += 2) {
                    if (copy[i] == copy[j]) {
                        copy[j] = 0;
                    }
                }
            }
            for (i = 1; i < n - 1; i += 2) {
                u16 id = copy[i];
                if (id != 0) {
                    Actor* q = fn_8015F1A0(id);
                    if (q != 0 && q->b26c == 1) {
                        fn_8020F934(id);
                    }
                }
            }
            if (copy != 0) {
                fn_801E1784(copy);
            }
        }
    }
    return 0;
}
/* Entry i of a counted list (count first, then the entries), or 0 past the end. */
static inline s32 LstGet(s32* l, s32 i) {
    if (l[0] > i) {
        l += i;
        return l[1];
    }
    return 0;
}
s32 fn_801FF604(u16 flags, Scpt* o) {
    if (flags & 1) {
        f32* p = o->cur.f;
        Obj10A* t;
        u16 id;
        p++;
        id = ReadInt(&p);
        o->cur.f = p;
        t = fn_8010A164(id);
        if (t != 0) {
            s32 n;
            s32 i;
            Actor* e;
            e = t->x24;
            n = e->x1c8->x10[0];
            for (i = 1; i < n - 1; i += 2) {
                u16 id2 = LstGet(e->x1c8->x10, i);
                Actor* q = fn_8015F1A0(id2);
                if (q != 0 && q->b26c == 1) {
                    fn_80210064(id2);
                }
            }
        }
    }
    return 0;
}
s32 fn_801FF714(u16 flags, Scpt* o) {
    if (flags & 1) {
        f32* p = o->cur.f;
        Work801F8* s;
        s32 i, cnt;
        p++;
        cnt = *(s32 *)p++;
        for (i = 0; i < cnt; i++) {
            s = fn_801E1A2C(1, 0x44);
            if (s == 0) {
                fn_801DBE1C("TaskOff: malloc failed %d", i);
            }
            o->work.work801F8 = s;
            s->ev.hd.kind = 0;
            s->n = ReadInt(&p);
            s->x1c = s->n;
            fn_80211058(o, 9, s->n, 2, lbl_8030CEA0.x08, &s->ev);
            o->kind = 1;
            o->cnt = 0;
            fn_80210F74(o);
        }
        o->flags = 1;
        o->cur.f = p;
        return 0;
    }
    if (flags & 2) {
        Work801F8* st = o->work.work801F8;
        if (o->handle == 0) {
            o->handle = fn_800CD0B8(o->a20, o->a24, o->a28, o->a2c);
            o->cnt++;
            if (o->cnt == 5) {
                fn_801DBE1C("TaskOff: message post time out");
            }
        } else if (st->ev.hd.kind == 2) {
            return 0;
        }
    }
    return !(flags & 8);
}

s32 fn_801FF8D4(u16 flags, Scpt* o) {
    if (flags & 1) {
        f32* p = o->cur.f;
        Work801F8* s;
        s32 i, cnt;
        p++;
        cnt = *(s32 *)p++;
        for (i = 0; i < cnt; i++) {
            s = fn_801E1A2C(1, 0x44);
            o->work.work801F8 = s;
            s->ev.hd.kind = 0;
            s->n = ReadInt(&p);
            s->x1c = s->n;
            fn_80211058(o, 9, s->n, 1, lbl_8030CEA0.x08, &s->ev);
            o->kind = 1;
            o->cnt = 0;
            fn_80210F74(o);
        }
        o->cur.f = p;
        o->flags = 1;
        return 0;
    }
    if (flags & 2) {
        Work801F8* st = o->work.work801F8;
        if (o->handle == 0) {
            o->handle = fn_800CD0B8(o->a20, o->a24, o->a28, o->a2c);
            o->cnt++;
        } else if (st->ev.hd.kind == 2) {
            return 0;
        }
    }
    return !(flags & 8);
}
s32 fn_801FFA60(u16 flags, Scpt* o) {
    if (flags & 1) {
        f32* p = o->cur.f;
        Work801F8* s;
        s32 i, cnt;
        p++;
        cnt = *(s32 *)p++;
        for (i = 0; i < cnt; i++) {
            s = fn_801E1A2C(1, 0x44);
            if (s == 0) {
                fn_801DBE1C("TaskOff: malloc failed %d", i);
            }
            o->work.work801F8 = s;
            s->ev.hd.kind = 0;
            s->n = ReadInt(&p);
            s->x1c = s->n;
            fn_80211058(o, 9, s->n, 2, lbl_8030CEA0.x08, &s->ev);
            o->kind = 1;
            o->cnt = 0;
            fn_80210F74(o);
        }
        o->flags = 0;
        o->cur.f = p;
        return 0;
    }
    if (flags & 2) {
        Work801F8* st = o->work.work801F8;
        if (o->handle == 0) {
            o->handle = fn_800CD0B8(o->a20, o->a24, o->a28, o->a2c);
            o->cnt++;
            if (o->cnt == 5) {
                fn_801DBE1C("TaskOff: message post time out");
            }
        } else if (st->ev.hd.kind == 2) {
            return 0;
        }
    }
    return !(flags & 8);
}

s32 fn_801FFC20(u16 flags, Scpt* o) {
    if (flags & 1) {
        f32* p = o->cur.f;
        Work801F8* s;
        s32 i, cnt;
        p++;
        cnt = *(s32 *)p++;
        for (i = 0; i < cnt; i++) {
            s = fn_801E1A2C(1, 0x44);
            o->work.work801F8 = s;
            s->ev.hd.kind = 0;
            s->n = ReadInt(&p);
            s->x1c = s->n;
            fn_8010A164(s->n);
            fn_80211058(o, 9, s->n, 1, lbl_8030CEA0.x08, &s->ev);
            o->kind = 1;
            o->cnt = 0;
            fn_80210F74(o);
        }
        o->cur.f = p;
        o->flags = 0;
        return 0;
    }
    if (flags & 2) {
        Work801F8* st = o->work.work801F8;
        if (o->handle == 0) {
            o->handle = fn_800CD0B8(o->a20, o->a24, o->a28, o->a2c);
            o->cnt++;
        } else if (st->ev.hd.kind == 2) {
            return 0;
        }
    }
    return !(flags & 8);
}

s32 fn_801FFDB4(u32 flags, Scpt *st) {
    if (flags & 1) {
        float *p = st->cur.f + 1;
        s32 n;
        if (*p == 3.4028235e38f) {
            p++;
            n = 0x7FFFFFFF;
        } else {
            n = (s32)fn_801F6120(&p);
        }
        fn_800D2C44((u16)n);
        st->cur.f = p;
    }
    return 0;
}
s32 fn_801FFE3C(u32 flags, Scpt *s)
{
    if (flags & 1) {
        u8 *p = s->cur.b + 4;
        u32 v;
        if (3.4028235e38f == *(f32 *)p) {
            p += 4;
            v = 0x7FFFFFFF;
        } else {
            v = (s32)fn_801F6120((f32**)&p);
        }
        s->cur.b = p;
        if (v == 0x7FFFFFFF) {
            fn_800D2C94(1);
        } else if (v == 1) {
            fn_800D2C94(1);
        } else {
            fn_800D2C94(0);
        }
    }
    return 0;
}
s32 fn_801FFEF0(u32 flags, Scpt *s)
{
    if (flags & 1) {
        u8 *p = s->cur.b + 4;
        u32 v;
        if (3.4028235e38f == *(f32 *)p) {
            p += 4;
            v = 0x7FFFFFFF;
        } else {
            v = (s32)fn_801F6120((f32**)&p);
        }
        s->cur.b = p;
        if (v == 0x7FFFFFFF) {
            fn_800D2C84(1);
        } else if (v == 1) {
            fn_800D2C84(1);
        } else {
            fn_800D2C84(0);
        }
    }
    return 0;
}

s32 fn_801FFFA4(u32 flags, Scpt *st) {
    if (flags & 1) {
        float *p = st->cur.f + 1;
        s32 i = RDI(p);
        s32 a = RDI(p);
        f32 b = fn_801F6120(&p);
        st->cur.f = p;
        lbl_8030CEA0.x14b8[i] = a;
        lbl_8030CEA0.x14cb[i] = b;
    }
    return 0;
}

s32 fn_802000A0(u32 a, Scpt *s) {
    f32 *p;
    s32 v;
    s32 w;
    if (a & 1) {
        p = s->cur.f + 1;
        if (3.4028235e38f == *p) {
            p++;
            v = 0x7FFFFFFF;
        } else {
            v = fn_801F6120(&p);
        }
        w = fn_801F6120(&p);
        s->cur.f = p;
        lbl_8030CEA0.x14b0 = v;
        lbl_8030CEA0.x14c9 = w;
    }
    return 0;
}

s32 fn_8020014C(u32 flags, Scpt *s)
{
    float *p;
    s32 a;
    s32 b;
    if (flags & 1) {
        p = s->cur.f + 1;
        if (3.4028235e38f == *p) {
            p++;
            a = 0x7FFFFFFF;
        } else {
            a = fn_801F6120(&p);
        }
        b = fn_801F6120(&p);
        s->cur.f = p;
        lbl_8030CEA0.x14b4 = a;
        lbl_8030CEA0.x14ca = b;
    }
    return 0;
}

s16 fn_802001F8(u32 flags, Scpt *st) {
    s32 n;
    u16 f = flags;
    s32 i;
    s32 cnt;
    s32 sum;
    if (flags & 1) {
        float *p = st->cur.f + 1;
        cnt = *(s32 *)p++ + 1;
        n = (*p == 3.4028235e38f) ? (p++, 0x7FFFFFFF) : (s32)fn_801F6120(&p);
        lbl_8030CEA0.xca0[n] = 0;
        lbl_8030CEA0.xc8a[n] = cnt;
        lbl_8030CEA0.path[n][0].b[0] = lbl_8030E830[n + 8].b[0];
        lbl_8030CEA0.path[n][0].b[1] = lbl_8030E830[n + 8].b[1];
        lbl_8030CEA0.path[n][0].b[2] = lbl_8030E830[n + 8].b[2];
        lbl_8030CEA0.path[n][0].c[0] = lbl_8030E830[n + 8].c[0];
        lbl_8030CEA0.path[n][0].c[1] = lbl_8030E830[n + 8].c[1];
        lbl_8030CEA0.path[n][0].a[0] = lbl_8030E830[n + 8].a[0];
        lbl_8030CEA0.path[n][0].a[1] = lbl_8030E830[n + 8].a[1];
        lbl_8030CEA0.path[n][0].a[2] = lbl_8030E830[n + 8].a[2];
        sum = 0;
        for (i = 0; i < cnt - 1; i++) {
            lbl_8030CEA0.path[n][i + 1].a[0] = fn_801F6120(&p);
            lbl_8030CEA0.path[n][i + 1].a[1] = fn_801F6120(&p);
            lbl_8030CEA0.path[n][i + 1].a[2] = fn_801F6120(&p);
            lbl_8030CEA0.path[n][i + 1].c[0] = fn_801F6120(&p);
            lbl_8030CEA0.path[n][i + 1].c[1] = fn_801F6120(&p);
            lbl_8030CEA0.path[n][i + 1].b[0] = fn_801F6120(&p);
            lbl_8030CEA0.path[n][i + 1].b[1] = fn_801F6120(&p);
            lbl_8030CEA0.path[n][i + 1].b[2] = fn_801F6120(&p);
            lbl_8030CEA0.path[n][i].w = (*p == 3.4028235e38f) ? (p++, 0x7FFFFFFF) : (s32)fn_801F6120(&p);
            sum += lbl_8030CEA0.path[n][i].w;
        }
        lbl_8030CEA0.path[n][cnt - 1].w = lbl_8030CEA0.path[n][0].w;
        sum += lbl_8030CEA0.path[n][0].w;
        lbl_8030CEA0.xcbc[n] = sum;
        st->cur.f = p;
        if (lbl_8030CEA0.path[n][0].w == 0) {
            lbl_8030CEA0.xc74[n] = 0;
            lbl_8030CEA0.xc8a[n] = 0;
            fn_801D9728(n, 1, lbl_8030CEA0.path[n][1].a[0], lbl_8030CEA0.path[n][1].a[1], lbl_8030CEA0.path[n][1].a[2], lbl_8030CEA0.path[n][1].c[0], lbl_8030CEA0.path[n][1].c[1], lbl_8030CEA0.path[n][1].b[0], lbl_8030CEA0.path[n][1].b[1], lbl_8030CEA0.path[n][1].b[2]);
        } else {
            lbl_8030CEA0.xc74[n] = 1;
        }
    }
    return (f >> 3) & 1;
}
s32 fn_80200460(u16 flags, Scpt *st) {
    if (flags & 1) {
        ScptCur p;
        s32 cnt;
        s32 i;
        s32 sum;
        p.f = st->cur.f + 1;
        lbl_8030CEA0.xc9c = 0;
        lbl_8030CEA0.xc88 = *p.i++ + 1;
        cnt = lbl_8030CEA0.xc88;
        lbl_8030CEA0.path2[0].b[0] = lbl_8030E830[8].b[0];
        lbl_8030CEA0.path2[0].b[1] = lbl_8030E830[8].b[1];
        lbl_8030CEA0.path2[0].b[2] = lbl_8030E830[8].b[2];
        lbl_8030CEA0.path2[0].a[0] = lbl_8030E830[8].a[0];
        lbl_8030CEA0.path2[0].a[1] = lbl_8030E830[8].a[1];
        lbl_8030CEA0.path2[0].a[2] = lbl_8030E830[8].a[2];
        sum = 0;
        for (i = 0; i < cnt - 1; i++) {
            lbl_8030CEA0.path2[i + 1].a[0] = fn_801F6120(&p.f);
            lbl_8030CEA0.path2[i + 1].a[1] = fn_801F6120(&p.f);
            lbl_8030CEA0.path2[i + 1].a[2] = fn_801F6120(&p.f);
            lbl_8030CEA0.path2[i + 1].b[0] = fn_801F6120(&p.f);
            lbl_8030CEA0.path2[i + 1].b[1] = fn_801F6120(&p.f);
            lbl_8030CEA0.path2[i + 1].b[2] = fn_801F6120(&p.f);
            lbl_8030CEA0.path2[i].w = ReadInt(&p.f);
            sum += lbl_8030CEA0.path2[i].w;
        }
        lbl_8030CEA0.path2[cnt - 1].w = lbl_8030CEA0.path2[0].w;
        sum += lbl_8030CEA0.path2[0].w;
        lbl_8030CEA0.xcb8 = sum;
        st->cur.f = p.f;
        if (lbl_8030CEA0.path2[0].w == 0) {
            lbl_8030CEA0.xc70 = 0;
            lbl_8030CEA0.xc88 = 0;
            fn_801D9864(1, lbl_8030CEA0.path2[1].a[0], lbl_8030CEA0.path2[1].a[1], lbl_8030CEA0.path2[1].a[2], lbl_8030CEA0.path2[1].b[0], lbl_8030CEA0.path2[1].b[1], lbl_8030CEA0.path2[1].b[2]);
        } else {
            lbl_8030CEA0.xc70 = 1;
        }
    }
    return 0;
}
s32 fn_80200634(u16 flags, Scpt *st) {
    if (flags & 1) {
        ScptCur p;
        s32 cnt;
        s32 i;
        s32 sum;
        p.f = st->cur.f + 1;
        lbl_8030CEA0.xc98 = 0;
        lbl_8030CEA0.xc86 = *p.i++ + 1;
        cnt = lbl_8030CEA0.xc86;
        lbl_8030CEA0.path1[0].b[0] = lbl_8030E830[7].b[0];
        lbl_8030CEA0.path1[0].b[1] = lbl_8030E830[7].b[1];
        lbl_8030CEA0.path1[0].b[2] = lbl_8030E830[7].b[2];
        sum = 0;
        for (i = 0; i < cnt - 1; i++) {
            lbl_8030CEA0.path1[i + 1].b[0] = fn_801F6120(&p.f);
            lbl_8030CEA0.path1[i + 1].b[1] = fn_801F6120(&p.f);
            lbl_8030CEA0.path1[i + 1].b[2] = fn_801F6120(&p.f);
            lbl_8030CEA0.path1[i].w = ReadInt(&p.f);
            sum += lbl_8030CEA0.path1[i].w;
        }
        lbl_8030CEA0.path1[cnt - 1].w = lbl_8030CEA0.path1[0].w;
        sum += lbl_8030CEA0.path1[0].w;
        lbl_8030CEA0.xcb4 = sum;
        st->cur.f = p.f;
        if (lbl_8030CEA0.path1[0].w == 0) {
            lbl_8030CEA0.xc6c = 0;
            lbl_8030CEA0.xc86 = 0;
            fn_801D995C(1, lbl_8030CEA0.path1[1].b[0], lbl_8030CEA0.path1[1].b[1], lbl_8030CEA0.path1[1].b[2]);
        } else {
            lbl_8030CEA0.xc6c = 1;
        }
    }
    return 0;
}
s32 fn_802007C0(u16 flags, Scpt *st) {
    if (flags & 1) {
        ScptCur p;
        s32 cnt;
        s32 i;
        s32 sum;
        p.f = st->cur.f + 1;
        lbl_8030CEA0.xc94 = 0;
        lbl_8030CEA0.xc84 = *p.i++ + 1;
        cnt = lbl_8030CEA0.xc84;
        lbl_8030CEA0.path0[0].b[0] = lbl_8030E830[0].b[0];
        lbl_8030CEA0.path0[0].b[1] = lbl_8030E830[0].b[1];
        lbl_8030CEA0.path0[0].b[2] = lbl_8030E830[0].b[2];
        lbl_8030CEA0.path0[0].a[0] = lbl_8030E830[0].a[0];
        lbl_8030CEA0.path0[0].a[1] = lbl_8030E830[0].a[1];
        lbl_8030CEA0.path0[0].a[2] = lbl_8030E830[0].a[2];
        lbl_8030CEA0.path0[0].c[0] = lbl_8030E830[0].c[0];
        lbl_8030CEA0.path0[0].c[1] = lbl_8030E830[0].c[1];
        sum = 0;
        for (i = 0; i < cnt - 1; i++) {
            lbl_8030CEA0.path0[i + 1].a[0] = fn_801F6120(&p.f);
            lbl_8030CEA0.path0[i + 1].a[1] = fn_801F6120(&p.f);
            lbl_8030CEA0.path0[i + 1].a[2] = fn_801F6120(&p.f);
            lbl_8030CEA0.path0[i + 1].c[0] = fn_801F6120(&p.f);
            lbl_8030CEA0.path0[i + 1].c[1] = fn_801F6120(&p.f);
            lbl_8030CEA0.path0[i + 1].b[0] = fn_801F6120(&p.f);
            lbl_8030CEA0.path0[i + 1].b[1] = fn_801F6120(&p.f);
            lbl_8030CEA0.path0[i + 1].b[2] = fn_801F6120(&p.f);
            lbl_8030CEA0.path0[i].w = ReadInt(&p.f);
            sum += lbl_8030CEA0.path0[i].w;
        }
        lbl_8030CEA0.path0[cnt - 1].w = lbl_8030CEA0.path0[0].w;
        sum += lbl_8030CEA0.path0[0].w;
        lbl_8030CEA0.xcb0 = sum;
        st->cur.f = p.f;
        if (lbl_8030CEA0.path0[0].w == 0) {
            lbl_8030CEA0.xc68 = 0;
            lbl_8030CEA0.xc84 = 0;
            fn_801D9A0C(1, lbl_8030CEA0.path0[1].a[0], lbl_8030CEA0.path0[1].a[1], lbl_8030CEA0.path0[1].a[2], lbl_8030CEA0.path0[1].c[0], lbl_8030CEA0.path0[1].c[1], lbl_8030CEA0.path0[1].b[0], lbl_8030CEA0.path0[1].b[1], lbl_8030CEA0.path0[1].b[2]);
        } else {
            lbl_8030CEA0.xc68 = 1;
        }
    }
    return 0;
}




s32 fn_802009C4(u32 flags, Scpt *st) {
    if (flags & 1) {
        float *p = st->cur.f + 1;
        int n, m;
        f32 a, b, c, d, e, f, g, h;
        n = rdi(&p);
        m = rdi(&p);
        a = fn_801F6120(&p);
        b = fn_801F6120(&p);
        c = fn_801F6120(&p);
        d = fn_801F6120(&p);
        e = fn_801F6120(&p);
        f = fn_801F6120(&p);
        g = fn_801F6120(&p);
        h = fn_801F6120(&p);
        fn_801D9728(n, m, a, b, c, d, e, f, g, h);
        st->cur.f = p;
    }
    return 0;
}

s16 fn_80200B90(u32 flags, Scpt *st) {
    s32 n;
    if (flags & 1) {
        float *p = st->cur.f + 1;
        f32 a, b, c, d, e, g;
        if (*p == 3.4028235e38f) {
            p++;
            n = 0x7FFFFFFF;
        } else {
            n = (s32)fn_801F6120(&p);
        }
        a = fn_801F6120(&p);
        b = fn_801F6120(&p);
        c = fn_801F6120(&p);
        d = fn_801F6120(&p);
        e = fn_801F6120(&p);
        g = fn_801F6120(&p);
        fn_801D9864(n, a, b, c, d, e, g);
        st->cur.f = p;
        lbl_8030CEA0.xc70 = 0;
        lbl_8030CEA0.xc88 = 0;
    }
    return 0;
}

s16 fn_80200CE4(u32 flags, Scpt *st) {
    s32 n;
    u16 f = flags;
    if (flags & 1) {
        float *p = st->cur.f + 1;
        f32 a, b, c;
        if (*p == 3.4028235e38f) {
            p++;
            n = 0x7FFFFFFF;
        } else {
            n = (s32)fn_801F6120(&p);
        }
        a = fn_801F6120(&p);
        b = fn_801F6120(&p);
        c = fn_801F6120(&p);
        fn_801D995C(n, a, b, c);
        st->cur.f = p;
        lbl_8030CEA0.xc6c = 0;
        lbl_8030CEA0.xc86 = 0;
    }
    if (f & 8) {
        return 0;
    }
    return 0;
}

s32 fn_80200DF4(u32 flags, Scpt *st) {
    if (flags & 1) {
        float *p = st->cur.f + 1;
        s32 n;
        f32 a, b, c, d, e, f, g, h;
        if (*p == 3.4028235e38f) {
            p++;
            n = 0x7FFFFFFF;
        } else {
            n = (s32)fn_801F6120(&p);
        }
        a = fn_801F6120(&p);
        b = fn_801F6120(&p);
        c = fn_801F6120(&p);
        d = fn_801F6120(&p);
        e = fn_801F6120(&p);
        f = fn_801F6120(&p);
        g = fn_801F6120(&p);
        h = fn_801F6120(&p);
        fn_801D9A0C(n, a, b, c, d, e, f, g, h);
        st->cur.f = p;
        lbl_8030CEA0.xc68 = 0;
        lbl_8030CEA0.xc84 = 0;
    }
    return 0;
}

s32 fn_80200F88(u32 a, Scpt *st) {
    if (a & 1) {
        u8 *c = st->cur.b;
        st->cur.b = c + 4;
        fn_800D2CA8(0);
    }
    return 0;
}

s32 fn_80200FC4(u32 flags, Scpt *st) {
    if (flags & 1) {
        float *p = st->cur.f + 1;
        s32 r, g, b;
        u32 d, e;
        u32 rgb;
        f32 f1, f3, f2, f4;
        r = RDI(p);
        g = RDI(p);
        b = RDI(p);
        d = RDI(p);
        f1 = fn_801F6120(&p);
        f2 = fn_801F6120(&p);
        e = RDI(p);
        f3 = fn_801F6120(&p);
        f4 = fn_801F6120(&p);
        rgb = ((r & 0xff) << 16) | ((g & 0xff) << 8) | (b & 0xff);
        if (d == 0x7FFFFFFF || d == 0) {
            d = 1;
        }
        if (f1 == 3.4028235e38f) {
            f1 = 1.0f;
        }
        if (e == 0x7FFFFFFF || e == 0) {
            e = 1;
        }
        if (f3 == 3.4028235e38f) {
            f3 = 200.0f;
        }
        st->cur.f = p;
        fn_800D2554(f2, f4);
        fn_800D25C4(rgb, d);
        fn_800D258C(e, f1, f3);
        fn_800D2CA8(1);
    }
    return 0;
}

s32 fn_80201228(u32 flags, Scpt *st) {
    if (flags & 1) {
        float *p = st->cur.f + 1;
        s32 r, g, b;
        u32 d, e;
        u32 rgb;
        f32 f1, f2;
        r = RDI(p);
        g = RDI(p);
        b = RDI(p);
        d = RDI(p);
        f1 = fn_801F6120(&p);
        f2 = fn_801F6120(&p);
        e = RDI(p);
        rgb = ((r & 0xff) << 16) | ((g & 0xff) << 8) | (b & 0xff);
        if (d == 0x7FFFFFFF) {
            d = 1;
        }
        if (f1 == 3.4028235e38f) {
            f1 = 1.0f;
        }
        if (f2 == 3.4028235e38f) {
            f2 = 200.0f;
        }
        if (e == 0x7FFFFFFF) {
            e = 1;
        }
        st->cur.f = p;
        fn_800D2554(0.0f, 1.0f);
        fn_800D25C4(rgb, d);
        fn_800D258C(e, f1, f2);
        fn_800D2CA8(1);
    }
    return 0;
}

s32 fn_80201458(u32 flags, Scpt *st) {
    if (flags & 1) {
        float *p = st->cur.f;
        s32 v, n, i;
        Actor *a;
        p++;
        v = RDI(p);
        n = *(s32 *)p++;
        for (i = 0; i < n; i++) {
            a = fn_8015F1A0(RDI(p));
            if (a == 0) {
                st->cur.f = p;
                return 0;
            }
            a->x2c = v;
            if (a->x1d8 != 0 && a->x1d8->x8 != 0) {
                a->x1d8->x8->x2c = v;
            }
        }
        st->cur.f = p;
        return 0;
    }
    return 1;
}
s32 fn_802015AC(u32 flags, Scpt *st) {
    u16 f = flags;
    if (flags & 1) {
        float *p = st->cur.f;
        u32 n;
        p++;
        n = RDI(p);
        st->cur.f = p;
        st->work.n = 0;
        if (FlagTest(0x31) == 1) {
            return 0;
        }
        if (n == 0) {
            fn_801CBBD8();
            return 0;
        }
        lbl_80347510 = 0.0f;
        lbl_80347514 = (n == 0x7FFFFFFF) ? 30.0f : (f32)(n + 1);
        lbl_80347518 = 1;
    }
    if (f & 2) {
        if (st->work.n != 0) {
            if (lbl_80347508 == 0) {
                st->work.n = 0;
                return 0;
            }
        } else {
            st->work.n = 1;
        }
    }
    if (f & 8) {
        st->work.n = 0;
        return 0;
    }
    return 1;
}

s32 fn_8020170C(u16 flags, Scpt *c) {
    float *p;
    u32 t;
    if (flags & 1) {
        p = c->cur.f;
        p++;
        if (*p == 3.4028235e38f) {
            p++;
            t = 0x7FFFFFFF;
        } else {
            t = (s32)fn_801F6120(&p);
        }
        c->cur.f = p;
        c->work.n = 0;
        if (t == 0) {
            fn_801CBBBC();
            return 0;
        }
        if (t == 0x7FFFFFFF) {
            lbl_80347514 = 30.0f;
        } else {
            lbl_80347514 = (f32)(t + 1);
        }
        lbl_80347510 = 1.0f;
        lbl_80347518 = 0;
    }
    if (flags & 2) {
        if (c->work.n != 0) {
            if (lbl_80347508 == 0) {
                c->work.n = 0;
                return 0;
            }
        } else {
            c->work.n = 1;
        }
    }
    if (flags & 8) {
        c->work.n = 0;
        return 0;
    }
    return 1;
}

s32 fn_8020184C(u32 flags, Scpt* s) {
    u16 f = flags;
    Work_8020184C* w;
    f32* cur;
    if (flags & 1) {
        cur = s->cur.f + 1;
        w = fn_801E1A2C(1, 0x44);
        if (w == NULL) fn_801DBE1C("HCLR: malloc failed");
        s->work.work_8020184C = w;
        w->ev.hd.kind = 0;
        w->n = ReadInt(&cur);
        w->x1c = (u16)ReadInt(&cur);
        s->cur.f = cur;
        fn_80211058(s, 6, w->n, 0x27, lbl_8030CEA0.x08, &w->ev);
    }
    if (f & 2) {
        w = s->work.work_8020184C;
        if (s->handle == 0) {
            s->handle = fn_800CD0B8(s->a20, s->a24, s->a28, s->a2c);
            s->cnt += 1;
            if (s->cnt == 5) fn_801DBE1C("HCLR: message post timed out");
        } else if (w->ev.hd.kind == 2) {
            return 0;
        }
    }
    return !(f & 8);
}

s32 fn_802019F8(u32 flags, Scpt* s) {
    u16 f = flags;
    Work_802019F8* w;
    f32* cur;
    if (flags & 1) {
        cur = s->cur.f;
        cur = cur + 1;
        w = fn_801E1A2C(1, 0x44);
        if (w == NULL) fn_801DBE1C("scptHset: malloc failed");
        s->work.work_802019F8 = w;
        w->x18 = ReadInt(&cur);
        w->x20 = 0;
        w->x1c = 0;
        s->cur.f = cur;
        w->hd.kind = 0;
        fn_802110E8(s, 7, w->x18, 2, lbl_8030CEA0.x08, &w->hd);
    }
    if (f & 2) {
        w = s->work.work_802019F8;
        if (s->handle == 0) {
            s->handle = fn_800CD0B8(s->a20, s->a24, s->a28, s->a2c);
            s->cnt += 1;
            if (s->cnt == 5) fn_801DBE1C("scptHset: message post time out");
        } else if (w->hd.kind == 2) {
            return 0;
        }
    }
    return !(f & 8);
}

s32 fn_80201B6C(u32 flags, Scpt* s) {
    u16 f = flags;
    Work_802019F8* w;
    f32* cur;
    if (flags & 1) {
        cur = s->cur.f;
        cur = cur + 1;
        w = fn_801E1A2C(1, 0x44);
        if (w == NULL) fn_801DBE1C("scptHSetTask: malloc failed");
        s->work.work_802019F8 = w;
        w->x18 = ReadInt(&cur);
        w->x20 = 0;
        w->x1c = 0;
        s->cur.f = cur;
        w->hd.kind = 0;
        fn_802110E8(s, 7, w->x18, 5, lbl_8030CEA0.x08, &w->hd);
    }
    if (f & 2) {
        w = s->work.work_802019F8;
        if (s->handle == 0) {
            s->handle = fn_800CD0B8(s->a20, s->a24, s->a28, s->a2c);
            s->cnt += 1;
            if (s->cnt == 5) fn_801DBE1C("scptHtaskset: message post time out");
        } else if (w->hd.kind == 2) {
            return 0;
        }
    }
    return !(f & 8);
}

s32 fn_80201CE0(u32 flags, Scpt* s) {
    u16 f = flags;
    Work_802019F8* w;
    f32* cur;
    if (flags & 1) {
        cur = s->cur.f;
        cur = cur + 1;
        w = fn_801E1A2C(1, 0x44);
        if (w == NULL) fn_801DBE1C("scptHread: malloc failed");
        s->work.work_802019F8 = w;
        w->x18 = ReadInt(&cur);
        w->x20 = 0;
        w->x1c = 0;
        s->cur.f = cur;
        w->hd.kind = 0;
        fn_802110E8(s, 7, w->x18, 3, lbl_8030CEA0.x08, &w->hd);
    }
    if (f & 2) {
        w = s->work.work_802019F8;
        if (s->handle == 0) {
            s->handle = fn_800CD0B8(s->a20, s->a24, s->a28, s->a2c);
            s->cnt += 1;
            if (s->cnt == 5) fn_801DBE1C("scptHread: message post time out");
        } else if (w->hd.kind == 2) {
            return 0;
        }
    }
    return !(f & 8);
}

s32 fn_80201E54(u32 flags, Scpt* s) {
    u16 f = flags;
    Work_802019F8* w;
    f32* cur;
    if (flags & 1) {
        cur = s->cur.f;
        cur = cur + 1;
        w = fn_801E1A2C(1, 0x44);
        if (w == NULL) fn_801DBE1C("scptHchange: malloc failed");
        s->work.work_802019F8 = w;
        w->x18 = ReadInt(&cur);
        w->x1c = ReadInt(&cur);
        w->x20 = 0;
        s->cur.f = cur;
        w->hd.kind = 0;
        fn_802110E8(s, 7, w->x18, 4, lbl_8030CEA0.x08, &w->hd);
    }
    if (f & 2) {
        w = s->work.work_802019F8;
        if (s->handle == 0) {
            s->handle = fn_800CD0B8(s->a20, s->a24, s->a28, s->a2c);
            s->cnt += 1;
            if (s->cnt == 5) fn_801DBE1C("scptHchange: message post time out");
        } else if (w->hd.kind == 2) {
            return 0;
        }
    }
    return !(f & 8);
}

s32 fn_80202004(u32 flags, Scpt* s)
{
    Work_80202004* w;
    f32* p;
    u16 f = flags;
    if (f & 1) {
        p = s->cur.f;
        p++;
        w = fn_801E1A2C(1, 0x44);
        if (w == NULL) fn_801DBE1C("scptHclose: malloc failed");
        s->work.work_80202004 = w;
        w->x18 = RDI(p);
        w->x1c = 0;
        w->x20 = RDI(p);
        s->cur.f = p;
        w->hd.kind = 0;
        fn_802110E8(s, 7, w->x18, 1, lbl_8030CEA0.x08, &w->hd);
    }
    if (f & 2) {
        w = s->work.work_80202004;
        if (s->handle == 0) {
            s->handle = fn_800CD0B8(s->a20, s->a24, s->a28, s->a2c);
            s->cnt += 1;
            if (s->cnt == 5) fn_801DBE1C("scptHclose: message post time out");
        } else if (w->hd.kind == 2) {
            return 0;
        }
    }
    return !(f & 8);
}

s32 fn_802021B8(u32 flags, Scpt* s)
{
    Work_80202004* w;
    f32* p;
    u16 f = flags;
    if (f & 1) {
        p = s->cur.f;
        p++;
        w = fn_801E1A2C(1, 0x44);
        if (w == NULL) fn_801DBE1C("scptHopen: malloc failed");
        s->work.work_80202004 = w;
        w->x18 = RDI(p);
        w->x1c = RDI(p);
        w->x20 = RDI(p);
        s->cur.f = p;
        if (w->x20 == 0x7FFFFFFF) w->x20 = 0;
        w->hd.kind = 0;
        fn_802110E8(s, 7, w->x18, 0, lbl_8030CEA0.x08, &w->hd);
    }
    if (f & 2) {
        w = s->work.work_80202004;
        if (s->handle == 0) {
            s->handle = fn_800CD0B8(s->a20, s->a24, s->a28, s->a2c);
            s->cnt += 1;
            if (s->cnt == 5) fn_801DBE1C("scptHopen: message post time out");
        } else if (w->hd.kind == 2) {
            return 0;
        }
    }
    return !(f & 8);
}

s32 fn_802023BC(u16 f, Scpt *c)
{
    Script_801F773C *s;
    ScptCur cur;
    f32 out[3];
    s32 ang[3];
    u32 i;
    u32 j;
    u32 k;

    if (f & 1) {
        cur = c->cur;
        fn_801F7500();
        cur.f++;
        s = fn_801E1A2C(1, 0x24);
        if (s == NULL) {
            fn_801DBE1C("scptMVCA3: malloc failed");
        }
        c->work.p = s;
        s->idx = 0;
        s->n = *cur.u++;
        s->xc = fn_801E1A2C(1, s->n * 4);
        s->x14 = fn_801E1A2C(1, s->n * 4);
        s->x10 = fn_801E1A2C(1, s->n * 8);
        s->x18 = fn_801E1A2C(1, s->n * 8);
        s->times = fn_801E1A2C(1, s->n * 4);
        s->angles = fn_801E1A2C(1, s->n * 4);
        s->x20 = fn_801E1A2C(1, s->n);
        for (i = 0; i < s->n; i++) {
            s->xc[i] = fn_801E1A2C(1, 0xc);
            s->x14[i] = fn_801E1A2C(1, 0xc);
            s->x10[2 * i] = fn_801E1A2C(1, 0xc);
            s->x10[2 * i + 1] = fn_801E1A2C(1, 0xc);
            s->x18[2 * i] = fn_801E1A2C(1, 0xc);
            s->x18[2 * i + 1] = fn_801E1A2C(1, 0xc);
            s->xc[i][0] = fn_801F6120(&cur.f);
            s->xc[i][1] = fn_801F6120(&cur.f);
            s->xc[i][2] = fn_801F6120(&cur.f);
            if (0.0f == s->xc[i][0]) {
                s->xc[i][0] = 0.1f;
            }
            if (0.0f == s->xc[i][1]) {
                s->xc[i][1] = 0.1f;
            }
            if (0.0f == s->xc[i][2]) {
                s->xc[i][2] = 0.1f;
            }
            ang[0] = 182.04445f * fn_801F6120(&cur.f);
            ang[1] = 182.04445f * fn_801F6120(&cur.f);
            s->angles[i] = fn_801F6120(&cur.f);
            ang[2] = 182.04445f * s->angles[i];
            s->times[i] = RDI(cur.f);
            if (s->times[i] <= 0) {
                s->times[i] = 1;
            }
            s->x20[i] = RDI(cur.f);
            fn_80213718(s->xc[i], ang, out, 100.0f);
            s->x14[i][0] = out[0];
            if (0.0f == s->x14[i][0]) {
                s->x14[i][0] = 0.1f;
            }
            s->x14[i][1] = out[1];
            if (0.0f == s->x14[i][1]) {
                s->x14[i][1] = 0.1f;
            }
            s->x14[i][2] = out[2];
            if (0.0f == s->x14[i][2]) {
                s->x14[i][2] = 0.1f;
            }
        }
        fn_8021331C(s->n, s->xc, s->x10);
        fn_8021331C(s->n, s->x14, s->x18);
        c->cur = cur;
        lbl_8030CEA0.x15cc = 1;
    }
    if (f & 2) {
        f32 tmp[3];
        f32 e;
        f32 t;
        s32 t1;
        s = c->work.p;
        if (c->cnt == s->times[s->idx + 1]) {
            c->cnt = 0;
            if (++s->idx == s->n - 1) {
                fn_80213478(s->x14[s->idx], s->xc[s->idx], &lbl_8030CEA0.x1908);
                lbl_8030CEA0.x18fc = s->xc[s->idx][0];
                lbl_8030CEA0.x1900 = s->xc[s->idx][1];
                lbl_8030CEA0.x1904 = s->xc[s->idx][2];
                lbl_8030CEA0.x1910 = 182.04445f * s->angles[s->idx];
                FREEALL(s, j)
                return 0;
            }
        }
        e = fn_80212A78(s->x20[s->idx + 1], c->cnt + 1, s->times[s->idx + 1]);
        t1 = s->times[s->idx + 1];
        t = t1 * e;
        fn_80213178(t, t1, s->xc[s->idx], s->x10[2 * s->idx], s->x10[2 * s->idx + 1],
                    s->xc[s->idx + 1], &lbl_8030CEA0.x18fc);
        fn_80213178(t, t1, s->x14[s->idx], s->x18[2 * s->idx], s->x18[2 * s->idx + 1],
                    s->x14[s->idx + 1], tmp);
        fn_80213478(tmp, &lbl_8030CEA0.x18fc, &lbl_8030CEA0.x1908);
        lbl_8030CEA0.x1910 = 182.04445f * (e * (s->angles[s->idx + 1] - s->angles[s->idx]) + s->angles[s->idx]);
        c->cnt++;
    }
    if (f & 8) {
        s = c->work.p;
        FREEALL(s, k)
    }
    return 1;
}

s32 fn_80202DEC(u32 flags, Scpt *c)
{
    Script_801F773C *s;
    ScptCur cur;
    f32 out[3];
    s32 ang[3];
    s32 i;
    s32 m;

    if (flags & 1) {
        cur = c->cur;
        fn_801F7500();
        cur.f++;
        s = fn_801E1A2C(1, 0x20);
        lbl_8030CEA0.x1914 = s;
        if (s == NULL) {
            fn_801DBE1C("scptMVCALP: malloc failed");
        }
        c->work.p = s;
        m = *cur.u++ + 1;
        s->n = m + 2;
        s->idx = 0;
        s->xc = fn_801E1A2C(1, s->n * 4);
        s->x10 = fn_801E1A2C(1, s->n * 8);
        s->x14 = fn_801E1A2C(1, s->n * 4);
        s->x18 = fn_801E1A2C(1, s->n * 8);
        s->times = fn_801E1A2C(1, s->n * 4);
        s->angles = fn_801E1A2C(1, s->n * 4);
        s->xc[0] = fn_801E1A2C(1, 0xc);
        s->x14[0] = fn_801E1A2C(1, 0xc);
        s->xc[0][0] = lbl_80311970.f[0];
        s->xc[0][1] = lbl_80311970.f[1];
        s->xc[0][2] = lbl_80311970.f[2];
        fn_80213718(s->xc[0], &lbl_8030CEA0.x1908, s->x14[0],
                    320.0f / njTan(182.04445f * (0.5f * lbl_80311970.x50)));
        s->angles[0] = 0.005493164f * lbl_8030CEA0.x1910;
        for (i = 0; i < s->n - 3; i++) {
            s->xc[i + 1] = fn_801E1A2C(1, 0xc);
            s->x14[i + 1] = fn_801E1A2C(1, 0xc);
            s->x10[2 * i] = fn_801E1A2C(1, 0xc);
            s->x10[2 * i + 1] = fn_801E1A2C(1, 0xc);
            s->x18[2 * i] = fn_801E1A2C(1, 0xc);
            s->x18[2 * i + 1] = fn_801E1A2C(1, 0xc);
            s->xc[i + 1][0] = fn_801F6120(&cur.f);
            if (0.0f == s->xc[i + 1][0]) {
                s->xc[i + 1][0] = 0.1f;
            }
            s->xc[i + 1][1] = fn_801F6120(&cur.f);
            if (0.0f == s->xc[i + 1][1]) {
                s->xc[i + 1][1] = 0.1f;
            }
            s->xc[i + 1][2] = fn_801F6120(&cur.f);
            if (0.0f == s->xc[i + 1][2]) {
                s->xc[i + 1][2] = 0.1f;
            }
            ang[0] = 182.04445f * fn_801F6120(&cur.f);
            ang[1] = 182.04445f * fn_801F6120(&cur.f);
            s->angles[i + 1] = fn_801F6120(&cur.f);
            ang[2] = 182.04445f * s->angles[i + 1];
            s->times[i] = RDI(cur.f);
            if (s->times[i] <= 0) {
                s->times[i] = 1;
            }
            fn_80213718(s->xc[i + 1], ang, out, 100.0f);
            s->x14[i + 1][0] = out[0];
            if (0.0f == s->x14[i + 1][0]) {
                s->x14[i + 1][0] = 0.1f;
            }
            s->x14[i + 1][1] = out[1];
            if (0.0f == s->x14[i + 1][1]) {
                s->x14[i + 1][1] = 0.1f;
            }
            s->x14[i + 1][2] = out[2];
            if (0.0f == s->x14[i + 1][2]) {
                s->x14[i + 1][2] = 0.1f;
            }
        }
        c->cur = cur;
        s->x10[2 * i] = fn_801E1A2C(1, 0xc);
        s->x10[2 * i + 1] = fn_801E1A2C(1, 0xc);
        s->x18[2 * i] = fn_801E1A2C(1, 0xc);
        s->x18[2 * i + 1] = fn_801E1A2C(1, 0xc);
        for (i = 0; i < 2; i++) {
            s32 k;
            f32* p = fn_801E1A2C(1, 0xc);
            k = i + m;
            s->xc[k] = p;
            s->x14[k] = fn_801E1A2C(1, 0xc);
            s->x10[2 * k] = fn_801E1A2C(1, 0xc);
            s->x10[2 * k + 1] = fn_801E1A2C(1, 0xc);
            s->x18[2 * k] = fn_801E1A2C(1, 0xc);
            s->x18[2 * k + 1] = fn_801E1A2C(1, 0xc);
            s->xc[k][0] = s->xc[i + 1][0];
            s->xc[k][1] = s->xc[i + 1][1];
            s->xc[k][2] = s->xc[i + 1][2];
            s->x14[k][0] = s->x14[i + 1][0];
            s->x14[k][1] = s->x14[i + 1][1];
            s->x14[k][2] = s->x14[i + 1][2];
            s->times[k - 1] = s->times[i];
        }
        fn_8021331C(s->n, s->xc, s->x10);
        fn_8021331C(s->n, s->x14, s->x18);
        lbl_8030CEA0.x15cc = 1;
        lbl_8030CEA0.x1918 = 0;
    }
    return 0;
}


s32 fn_802034B0(u16 f, Scpt *c)
{
    Script_801F773C *s;
    ScptCur cur;
    f32 out[3];
    s32 ang[3];
    u32 i;
    u32 j;
    u32 k;

    if (f & 1) {
        cur = c->cur;
        fn_801F7500();
        cur.f++;
        s = fn_801E1A2C(1, 0x20);
        if (s == NULL) {
            fn_801DBE1C("scptMVCA: malloc failed");
        }
        c->work.p = s;
        s->n = *cur.u++ + 1;
        s->idx = 0;
        s->xc = fn_801E1A2C(1, s->n * 4);
        s->x10 = fn_801E1A2C(1, s->n * 8);
        s->x14 = fn_801E1A2C(1, s->n * 4);
        s->x18 = fn_801E1A2C(1, s->n * 8);
        s->times = fn_801E1A2C(1, s->n * 4);
        s->angles = fn_801E1A2C(1, s->n * 4);
        s->xc[0] = fn_801E1A2C(1, 0xc);
        s->x14[0] = fn_801E1A2C(1, 0xc);
        s->xc[0][0] = lbl_80311970.f8[0];
        s->xc[0][1] = lbl_80311970.f8[1];
        s->xc[0][2] = lbl_80311970.f8[2];
        fn_80213718(s->xc[0], &lbl_8030CEA0.x1908, s->x14[0],
                    320.0f / njTan((182.04445f * (0.5f * lbl_80311970.x50))));
        s->angles[0] = 0.005493164f * lbl_8030CEA0.x1910;
        for (i = 0; i < s->n - 1; i++) {
            s->xc[i + 1] = fn_801E1A2C(1, 0xc);
            s->x14[i + 1] = fn_801E1A2C(1, 0xc);
            s->x10[2 * i] = fn_801E1A2C(1, 0xc);
            s->x10[2 * i + 1] = fn_801E1A2C(1, 0xc);
            s->x18[2 * i] = fn_801E1A2C(1, 0xc);
            s->x18[2 * i + 1] = fn_801E1A2C(1, 0xc);
            s->xc[i + 1][0] = fn_801F6120(&cur.f);
            if (0.0f == s->xc[i + 1][0]) {
                s->xc[i + 1][0] = 0.1f;
            }
            s->xc[i + 1][1] = fn_801F6120(&cur.f);
            if (0.0f == s->xc[i + 1][1]) {
                s->xc[i + 1][1] = 0.1f;
            }
            s->xc[i + 1][2] = fn_801F6120(&cur.f);
            if (0.0f == s->xc[i + 1][2]) {
                s->xc[i + 1][2] = 0.1f;
            }
            ang[0] = 182.04445f * fn_801F6120(&cur.f);
            ang[1] = 182.04445f * fn_801F6120(&cur.f);
            s->angles[i + 1] = fn_801F6120(&cur.f);
            ang[2] = 182.04445f * s->angles[i + 1];
            s->times[i] = RDI(cur.f);
            if (s->times[i] <= 0) {
                s->times[i] = 1;
            }
            fn_80213718(s->xc[i + 1], ang, out, 100.0f);
            s->x14[i + 1][0] = out[0];
            if (0.0f == s->x14[i + 1][0]) {
                s->x14[i + 1][0] = 0.1f;
            }
            s->x14[i + 1][1] = out[1];
            if (0.0f == s->x14[i + 1][1]) {
                s->x14[i + 1][1] = 0.1f;
            }
            s->x14[i + 1][2] = out[2];
            if (0.0f == s->x14[i + 1][2]) {
                s->x14[i + 1][2] = 0.1f;
            }
        }
        fn_8021331C(s->n, s->xc, s->x10);
        fn_8021331C(s->n, s->x14, s->x18);
        c->cur = cur;
        lbl_8030CEA0.x15cc = 1;
    }
    if (f & 2) {
        f32 tmp[3];
        s = c->work.p;
        if (c->cnt == s->times[s->idx]) {
            c->cnt = 0;
            s->idx++;
            if (s->idx >= s->n - 1) {
                fn_80213478(s->x14[s->idx], s->xc[s->idx], &lbl_8030CEA0.x1908);
                lbl_8030CEA0.x18fc = s->xc[s->idx][0];
                lbl_8030CEA0.x1900 = s->xc[s->idx][1];
                lbl_8030CEA0.x1904 = s->xc[s->idx][2];
                FREEALL_802034B0(s, j)
                return 0;
            }
        }
        fn_80213178(c->cnt, s->times[s->idx], s->xc[s->idx], s->x10[2 * s->idx], s->x10[2 * s->idx + 1],
                    s->xc[s->idx + 1], &lbl_8030CEA0.x18fc);
        fn_80213178(c->cnt, s->times[s->idx], s->x14[s->idx], s->x18[2 * s->idx], s->x18[2 * s->idx + 1],
                    s->x14[s->idx + 1], tmp);
        fn_80213478(tmp, &lbl_8030CEA0.x18fc, &lbl_8030CEA0.x1908);
        lbl_8030CEA0.x1910 = 182.04445f * ((f32)c->cnt / (f32)s->times[s->idx] * (s->angles[s->idx + 1] - s->angles[s->idx]) + s->angles[s->idx]);
        c->cnt++;
    }
    if (f & 8) {
        s = c->work.p;
        FREEALL_802034B0(s, k)
        return 1;
    }
    return 1;
}


s32 fn_80203FFC(u16 f, Scpt *c)
{
    Script_801F773C *s;
    ScptCur cur;
    u32 i;
    u32 j;
    u32 k;

    if (f & 1) {
        cur = c->cur;
        fn_801F7500();
        cur.f++;
        s = fn_801E1A2C(1, 0x1c);
        if (s == NULL) {
            fn_801DBE1C("scptMVCB2: malloc failed");
        }
        c->work.p = s;
        s->n = *cur.u++ + 1;
        s->idx = 0;
        s->xc = fn_801E1A2C(1, s->n * 4);
        s->x10 = fn_801E1A2C(1, s->n * 8);
        s->x14 = fn_801E1A2C(1, s->n * 4);
        s->x18 = fn_801E1A2C(1, s->n * 8);
        s->times = fn_801E1A2C(1, s->n * 4);
        s->xc[0] = fn_801E1A2C(1, 0xc);
        s->x14[0] = fn_801E1A2C(1, 0xc);
        s->xc[0][0] = lbl_80311970.f8[0];
        s->xc[0][1] = lbl_80311970.f8[1];
        s->xc[0][2] = lbl_80311970.f8[2];
        fn_80213718(s->xc[0], &lbl_8030CEA0.x1908, s->x14[0],
                    320.0f / njTan((182.04445f * (0.5f * lbl_80311970.x50))));
        for (i = 0; i < s->n - 1; i++) {
            s->xc[i + 1] = fn_801E1A2C(1, 0xc);
            s->x14[i + 1] = fn_801E1A2C(1, 0xc);
            s->x10[2 * i] = fn_801E1A2C(1, 0xc);
            s->x10[2 * i + 1] = fn_801E1A2C(1, 0xc);
            s->x18[2 * i] = fn_801E1A2C(1, 0xc);
            s->x18[2 * i + 1] = fn_801E1A2C(1, 0xc);
            s->xc[i + 1][0] = fn_801F6120(&cur.f);
            if (0.0f == s->xc[i + 1][0]) {
                s->xc[i + 1][0] = 0.00001f;
            }
            s->xc[i + 1][1] = fn_801F6120(&cur.f);
            if (0.0f == s->xc[i + 1][1]) {
                s->xc[i + 1][1] = 0.00001f;
            }
            s->xc[i + 1][2] = fn_801F6120(&cur.f);
            if (0.0f == s->xc[i + 1][2]) {
                s->xc[i + 1][2] = 0.00001f;
            }
            s->x14[i + 1][0] = fn_801F6120(&cur.f);
            if (0.0f == s->x14[i + 1][0]) {
                s->x14[i + 1][0] = 0.00001f;
            }
            s->x14[i + 1][1] = fn_801F6120(&cur.f);
            if (0.0f == s->x14[i + 1][1]) {
                s->x14[i + 1][1] = 0.00001f;
            }
            s->x14[i + 1][2] = fn_801F6120(&cur.f);
            if (0.0f == s->x14[i + 1][2]) {
                s->x14[i + 1][2] = 0.00001f;
            }
            s->times[i] = RDI(cur.f);
            if (s->times[i] <= 0) {
                s->times[i] = 1;
            }
        }
        fn_8021331C(s->n, s->xc, s->x10);
        fn_8021331C(s->n, s->x14, s->x18);
        c->cur = cur;
        lbl_8030CEA0.x15cc = 1;
    }
    if (f & 2) {
        f32 tmp[3];
        s = c->work.p;
        if (c->cnt == s->times[s->idx]) {
            c->cnt = 0;
            s->idx++;
            if (s->idx >= s->n - 1) {
                fn_80213478(s->x14[s->idx], s->xc[s->idx], &lbl_8030CEA0.x1908);
                lbl_8030CEA0.x18fc = s->xc[s->idx][0];
                lbl_8030CEA0.x1900 = s->xc[s->idx][1];
                lbl_8030CEA0.x1904 = s->xc[s->idx][2];
                FREEALL_80203FFC(s, j)
                return 0;
            }
        }
        fn_80213178(c->cnt, s->times[s->idx], s->xc[s->idx], s->x10[2 * s->idx], s->x10[2 * s->idx + 1],
                    s->xc[s->idx + 1], &lbl_8030CEA0.x18fc);
        fn_80213178(c->cnt, s->times[s->idx], s->x14[s->idx], s->x18[2 * s->idx], s->x18[2 * s->idx + 1],
                    s->x14[s->idx + 1], tmp);
        fn_80213478(tmp, &lbl_8030CEA0.x18fc, &lbl_8030CEA0.x1908);
        c->cnt++;
    }
    if (f & 8) {
        s = c->work.p;
        FREEALL_80203FFC(s, k)
    }
    return 1;
}

s16 fn_802049BC(u16 a, Scpt *st) {
    if (a & 1) {
        f32 *cur = st->cur.f;
        f32 f0, f1, f2, f3, f4, f5;
        u16 id;
        u16 v;
        fn_801F7500();
        cur++;
        f0 = fn_801F6120(&cur);
        f1 = fn_801F6120(&cur);
        f2 = fn_801F6120(&cur);
        id = RDI(cur);
        f3 = fn_801F6120(&cur);
        f4 = fn_801F6120(&cur);
        f5 = fn_801F6120(&cur);
        v = RDI(cur);
        st->cur.f = cur;
        if (f3 == 3.4028235e38f) {
            f3 = 0.0f;
        }
        if (f4 == 3.4028235e38f) {
            f4 = 14.0f;
        }
        if (f5 == 3.4028235e38f) {
            f5 = 0.0f;
        }
        fn_80097294(2);
        fn_80097094(id, f4);
        fn_80097204(0.0f, 0.0f, 0.0f);
        fn_8009724C(f3, f4, f5);
        fn_80097228(f0, f1, f2);
        if (v == 0) {
            fn_80097318(1);
        } else {
            fn_80097318(0);
        }
    }
    return (a >> 3) & 1;
}

s32 fn_80204BE8(u16 flags, Scpt *c) {
    float *p;
    f32 a[3];
    f32 b[3];
    if (flags & 1) {
        p = c->cur.f;
        fn_801F7500();
        p++;
        a[0] = fn_801F6120(&p);
        a[1] = fn_801F6120(&p);
        a[2] = fn_801F6120(&p);
        b[0] = fn_801F6120(&p);
        b[1] = fn_801F6120(&p);
        b[2] = fn_801F6120(&p);
        c->cur.f = p;
        lbl_8030CEA0.x18fc = a[0];
        lbl_8030CEA0.x1900 = a[1];
        lbl_8030CEA0.x1904 = a[2];
        fn_80213478(b, a, &lbl_8030CEA0.x1908);
    }
    if (flags & 8) return 1;
    return 0;
}

s32 fn_80204CD0(u16 a, Scpt *st) {
    if (a & 1) {
        f32 *cur = st->cur.f;
        f32 f0, f1, f2, f3, f4, f5;
        fn_801F7500();
        cur++;
        f0 = fn_801F6120(&cur);
        f1 = fn_801F6120(&cur);
        f2 = fn_801F6120(&cur);
        f3 = fn_801F6120(&cur);
        f4 = fn_801F6120(&cur);
        f5 = fn_801F6120(&cur);
        st->cur.f = cur;
        lbl_8030CEA0.x18fc = f0;
        lbl_8030CEA0.x1900 = f1;
        lbl_8030CEA0.x1904 = f2;
        lbl_8030CEA0.x1908 = (s32)(182.04445f * f3);
        lbl_8030CEA0.x190c = (s32)(182.04445f * f4);
        lbl_8030CEA0.x1910 = (s32)(182.04445f * f5);
    }
    if (a & 8) {
        return 1;
    }
    return 0;
}

s16 fn_80204E28(u32 a0, Scpt *st) {
    u32 n;
    u16 a = a0;
    f32 x;
    if (a0 & 1) {
        u8 *p = st->cur.b + 4;
        x = fn_801F6120((f32**)&p);
        if (3.4028235e38f == *(f32 *)p) {
            p += 4;
            n = 0x7fffffff;
        } else {
            n = (s32)fn_801F6120((f32**)&p);
        }
        st->cur.b = p;
        if (n == 0) {
            n = 1;
        }
        if (3.4028235e38f == x) {
            fn_8022D34C(n, 60.0f);
        } else {
            fn_8022D34C(n, x);
        }
    }
    return (a >> 3) & 1;
}

s16 fn_80204F04(u32 flags, Scpt *st) {
    u16 f = flags;
    if (flags & 1) {
        float *p = st->cur.f;
        float v;
        p++;
        v = fn_801F6120(&p);
        st->cur.f = p;
        if (v == 3.4028235e38f) {
            fn_8022D34C(1, 60.0f);
        } else {
            fn_8022D34C(1, v);
        }
    }
    return (f >> 3) & 1;
}

s32 fn_80204F8C(u32 flags, Scpt* s)
{
    Lerp* w;
    f32* p;
    f32 a[3];
    s32 n;
    s32 d[3];
    u32 f = flags & 0xffff;
    if (f & 1) {
        p = s->cur.f;
        fn_801F7500();
        p++;
        a[0] = fn_801F6120(&p);
        a[1] = fn_801F6120(&p);
        a[2] = fn_801F6120(&p);
        if (*p == 3.4028235e38f) {
            p++;
            n = 0x7FFFFFFF;
        } else {
            n = (s32)fn_801F6120(&p);
        }
        s->cur.f = p;
        fn_80213478(a, &lbl_8030CEA0.x18fc, d);
        if (n <= 0 || n == 1) {
            lbl_8030CEA0.x1908 = d[0];
            lbl_8030CEA0.x190c = d[1];
            lbl_8030CEA0.x1910 = d[2];
            return 0;
        }
        lbl_8030CEA0.x15cc = 1;
        w = fn_801E1A2C(1, 0x1c);
        w->total = n;
        w->step[0] = (s16)(d[0] - lbl_8030CEA0.x1908) / n;
        w->step[1] = (s16)(d[1] - lbl_8030CEA0.x190c) / n;
        w->step[2] = (s16)(d[2] - lbl_8030CEA0.x1910) / n;
        w->dest[0] = d[0];
        w->dest[1] = d[1];
        w->dest[2] = d[2];
        s->work.lerp = w;
    }
    if (f & 2) {
        w = s->work.lerp;
        lbl_8030CEA0.x1908 += w->step[0];
        lbl_8030CEA0.x190c += w->step[1];
        lbl_8030CEA0.x1910 += w->step[2];

        if (++s->cnt == w->total) {
            lbl_8030CEA0.x1908 = w->dest[0];
            lbl_8030CEA0.x190c = w->dest[1];
            lbl_8030CEA0.x1910 = w->dest[2];
            lbl_8030CEA0.x15cc = 0;
            return 0;
        }
    }
    if (f & 8) {
        lbl_8030CEA0.x15cc = 0;
    }
    return 1;
}

s32 fn_802051D0(u16 flags, Scpt *s)
{
    float *p = s->cur.f;
    s32 v;
    if (flags & 1) {
        p = p + 1;
        if (3.4028235e38f == *p) {
            p++;
            v = 0x7FFFFFFF;
        } else {
            v = fn_801F6120(&p);
        }
        lbl_8030CEA0.x1574 = v;
        s->cur.f = p;
    }
    if (flags & 8) {
        return 1;
    }
    return 0;
}

#ifdef NONMATCHING
s32 fn_8020527C(u32 flags, Script* s)
{
    f32* p;
    f32 dist;
    u32 n;
    f32 out[3];
    u16 f = flags;
    if (f & 1) {
        Track* w;
        p = s->cursor + 1;
        dist = fn_801F6120(&p);
        n = (*p == 3.4028235e38f ? (p++, 0x7FFFFFFF) : (s32)fn_801F6120(&p));
        if (n == 0 || n == 1) {
            return 0;
        }
        lbl_8030CEA0.x15cc = 1;
        w = fn_801E1A2C(1, 0x44);
        if (w == NULL) fn_801DBE1C("TrackUp: malloc failed");
        s->work = w;
        w->kind = 0;
        w->step = 0;
        w->total = n;
        w->dist = dist;
        w->start[0] = lbl_8030CEA0.x18fc;
        w->start[1] = lbl_8030CEA0.x1900;
        w->start[2] = lbl_8030CEA0.x1904;
        s->cursor = p;
    }
    if (f & 2) {
        Track* w = s->work;
        f32 t;
        lbl_802F7528[2] = w->dist;
        fn_802136A8(lbl_802F7528, out, lbl_8030CEA0.x1908, lbl_8030CEA0.x190c, lbl_8030CEA0.x1910);
        t = (f32)w->step / (f32)w->total;
        lbl_8030CEA0.x18fc = w->start[0] - out[0] * t;
        lbl_8030CEA0.x1900 = w->start[1] - out[1] * t;
        lbl_8030CEA0.x1904 = w->start[2] - out[2] * t;
        if (w->step++ == w->total) {
            lbl_8030CEA0.x15cc = 0;
            return 0;
        }
    }
    if (f & 8) {
        lbl_8030CEA0.x15cc = 0;
    }
    return 1;
}
#endif

s32 fn_8020549C(u32 flags, Scpt* s)
{
    Lerp* w;
    f32* p;
    s32 n;
    u32 f = flags & 0xffff;
    s32 d0, d1, d2;
    if (f & 1) {
        p = s->cur.f;
        fn_801F7500();
        p++;
        d0 = 182.04445f * fn_801F6120(&p);
        d1 = 182.04445f * fn_801F6120(&p);
        d2 = 182.04445f * fn_801F6120(&p);
        if (*p == 3.4028235e38f) {
            p++;
            n = 0x7FFFFFFF;
        } else {
            n = (s32)fn_801F6120(&p);
        }
        s->cur.f = p;
        if (n <= 0 || n == 1) {
            lbl_8030CEA0.x1908 = d0;
            lbl_8030CEA0.x190c = d1;
            lbl_8030CEA0.x1910 = d2;
            return 0;
        }
        lbl_8030CEA0.x15cc = 1;
        w = fn_801E1A2C(1, 0x1c);
        w->total = n;
        w->step[0] = (s16)(d0 - lbl_8030CEA0.x1908) / n;
        w->step[1] = (s16)(d1 - lbl_8030CEA0.x190c) / n;
        w->step[2] = (s16)(d2 - lbl_8030CEA0.x1910) / n;
        w->dest[0] = d0;
        w->dest[1] = d1;
        w->dest[2] = d2;
        s->work.lerp = w;
    }
    if (f & 2) {
        w = s->work.lerp;
        lbl_8030CEA0.x1908 += w->step[0];
        lbl_8030CEA0.x190c += w->step[1];
        lbl_8030CEA0.x1910 += w->step[2];

        if (s->cnt++ == w->total) {
            lbl_8030CEA0.x15cc = 0;
            return 0;
        }
    }
    if (f & 8) {
        lbl_8030CEA0.x15cc = 0;
    }
    return 1;
}

s16 fn_802056A8(u32 a0, Scpt *st) {
    s32 n;
    u16 a = a0;
    s8 r;
    if (a0 & 1) {
        u8 *p = st->cur.b;
        fn_801F7500();
        p += 4;
        if (3.4028235e38f == *(f32 *)p) {
            p += 4;
            n = 0x7fffffff;
        } else {
            n = (s32)fn_801F6120((f32**)&p);
        }
        st->cur.b = p;
        r = fn_8009763C();
        fn_800972AC();
        if (n == 0) {
            fn_80097318(1);
        } else {
            fn_80097318(0);
        }
        if (r == 2) {
            st->a20 = 2;
            st->flags = 0;
            return 1;
        }
    }
    if (a & 2) {
        if (--st->a20 == 0) {
            lbl_80310B3C[34] &= ~2;
            st->a20 = 0;
            return 0;
        }
        return 1;
    }
    return (a >> 3) & 1;
}

s16 fn_802057E0(u32 flags, Scpt *st) {
    u16 f = flags;
    if (flags & 1) {
        float *p = st->cur.f;
        s8 a;
        s32 b;
        fn_801F7500();
        p++;
        a = RDI(p);
        b = RDI(p);
        st->cur.f = p;
        fn_80097294(0xd);
        fn_8009701C(a);
        if (b == 0) {
            fn_80097318(1);
        } else {
            fn_80097318(0);
        }
    }
    return (f >> 3) & 1;
}

s16 fn_802058F8(u32 a0, Scpt *st) {
    s32 n;
    u16 a = a0;
    f32 x, y, z;
    if (a0 & 1) {
        u8 *p = st->cur.b;
        fn_801F7500();
        p += 4;
        x = fn_801F6120((f32**)&p);
        y = fn_801F6120((f32**)&p);
        z = fn_801F6120((f32**)&p);
        if (3.4028235e38f == *(f32 *)p) {
            p += 4;
            n = 0x7fffffff;
        } else {
            n = (s32)fn_801F6120((f32**)&p);
        }
        st->cur.b = p;
        fn_80097294(1);
        if (3.4028235e38f != x) {
            fn_80097204(x, y, z);
        }
        fn_800972E0(0);
        if (n == 0) {
            fn_80097318(1);
        } else {
            fn_80097318(0);
        }
    }
    return (a >> 3) & 1;
}

s16 fn_80205A3C(u16 a, Scpt *st) {
    if (a & 1) {
        f32 *cur = st->cur.f;
        f32 f0, f1, f2, f3, f4, f5;
        s32 v;
        fn_801F7500();
        cur++;
        f0 = fn_801F6120(&cur);
        f1 = fn_801F6120(&cur);
        f2 = fn_801F6120(&cur);
        f3 = fn_801F6120(&cur);
        f4 = fn_801F6120(&cur);
        f5 = fn_801F6120(&cur);
        v = RDI(cur);
        st->cur.f = cur;
        fn_80097294(11);
        if (f0 != 3.4028235e38f) {
            fn_80097204(f0, f1, f2);
        }
        if (f3 == 3.4028235e38f) {
            f3 = 14.0f;
        }
        fn_8009724C(0.0f, f3, 0.0f);
        if (f4 == 3.4028235e38f) {
            f4 = 40.0f;
        }
        fn_800971A8(f4);
        if (f5 == 3.4028235e38f) {
            f5 = 348.0f;
        }
        fn_80097134((s32)f5);
        if (v == 0) {
            fn_80097318(1);
        } else {
            fn_80097318(0);
        }
    }
    return (a >> 3) & 1;
}

s32 fn_80205C24(u16 a, Scpt *st) {
    if (a & 1) {
        f32 *cur = st->cur.f;
        f32 f0, f1, f2, f3, f4, f5, f6;
        u16 id;
        s32 v;
        fn_801F7500();
        id = RDI(cur);
        f0 = fn_801F6120(&cur);
        f1 = fn_801F6120(&cur);
        f2 = fn_801F6120(&cur);
        f3 = fn_801F6120(&cur);
        f4 = fn_801F6120(&cur);
        f5 = fn_801F6120(&cur);
        f6 = fn_801F6120(&cur);
        v = RDI(cur);
        fn_80097294(10);
        fn_8009703C(id, f0, f1);
        fn_8009724C(f2, f3, f4);
        fn_800971E0(182.04445f * f5, 182.04445f * f6, 0);
        if ((u16)v == 0) {
            fn_80097318(1);
        } else {
            fn_80097318(0);
        }
        st->cur.f = cur;
    }
    if (a & 8) {
        return 1;
    }
    return 0;
}


s32 fn_80205E48(u32 a0, Scpt *st) {
    s32 n;
    u16 a = a0;
    if (a0 & 1) {
        f32 *p = st->cur.f;
        fn_801F7500();
        if (3.4028235e38f == *p) {
            p++;
            n = 0x7fffffff;
        } else {
            n = (s32)fn_801F6120(&p);
        }
        fn_80097294(9);
        if ((u16)n == 0) {
            fn_80097318(1);
        } else {
            fn_80097318(0);
        }
        st->cur.f = p;
    }
    if (a & 8) return 1;
    return 0;
}

s32 fn_80205F14(u16 a, Scpt *st) {
    if (a & 1) {
        f32 *cur = st->cur.f;
        f32 f0, f1, f2, f3;
        u32 v;
        fn_801F7500();
        f0 = fn_801F6120(&cur);
        if (f0 == 3.4028235e38f) {
            f0 = 14.0f;
        }
        f1 = fn_801F6120(&cur);
        if (f1 == 3.4028235e38f) {
            f1 = 200.0f;
        }
        f2 = fn_801F6120(&cur);
        if (f2 == 3.4028235e38f) {
            f2 = 337.5f;
        }
        f3 = fn_801F6120(&cur);
        if (f3 == 3.4028235e38f) {
            f3 = 337.5f;
        }
        v = RDI(cur);
        fn_80097294(8);
        fn_800971C4(f1);
        fn_8009724C(0.0f, f0, 0.0f);
        fn_800971E0(182.04445f * f2, 182.04445f * f3, 0);
        if (v == 0) {
            fn_80097318(1);
        } else {
            fn_80097318(0);
        }
        st->cur.f = cur;
    }
    if (a & 8) {
        return 1;
    }
    return 0;
}

s32 fn_802060D4(u16 a, Scpt *st) {
    if (a & 1) {
        s32 id;
        s32 v;
        f32 f;
        f32 *cur = st->cur.f;
        fn_801F7500();
        cur++;
        id = (u16)RDI(cur);
        v = RDI(cur);
        if (v == 0x7fffffff) {
            v = 100;
        }
        st->cur.f = cur;
        fn_80097294(7);
        f = v / 100.0f;
        fn_800970D8(id, f, 0);
        fn_800970B4(id, f, 1);
    }
    if (a & 8) {
        return 1;
    }
    return 0;
}

s16 fn_8020623C(u16 a, Scpt *st) {
    if (a & 1) {
        f32 *cur = st->cur.f;
        f32 f0, f1, f2, f3, f4, f5;
        s32 v;
        fn_801F7500();
        cur++;
        f0 = fn_801F6120(&cur);
        f1 = fn_801F6120(&cur);
        f2 = fn_801F6120(&cur);
        f3 = fn_801F6120(&cur);
        f4 = fn_801F6120(&cur);
        f5 = fn_801F6120(&cur);
        v = ReadInt(&cur);
        st->cur.f = cur;
        fn_80097294(1);
        if (f0 != 3.4028235e38f) {
            fn_80097204(f0, f1, f2);
        }
        if (f3 == 3.4028235e38f) {
            f3 = 14.0f;
        }
        fn_8009724C(0.0f, f3, 0.0f);
        if (f4 == 3.4028235e38f) {
            f4 = 40.0f;
        }
        fn_800971A8(f4);
        if (f5 == 3.4028235e38f) {
            f5 = 348.0f;
        }
        fn_80097134((s32)f5);
        if (v == 0) {
            fn_80097318(1);
        } else {
            fn_80097318(0);
        }
    }
    return (a >> 3) & 1;
}

s16 fn_80206424(u16 a, Scpt *st) {
    if (a & 1) {
        f32 *cur = st->cur.f;
        f32 f0, f1, f2, f3, f4, f5;
        s32 v;
        fn_801F7500();
        cur++;
        f0 = fn_801F6120(&cur);
        f1 = fn_801F6120(&cur);
        f2 = fn_801F6120(&cur);
        f3 = fn_801F6120(&cur);
        f4 = fn_801F6120(&cur);
        f5 = fn_801F6120(&cur);
        v = ReadInt(&cur);
        st->cur.f = cur;
        fn_80097294(1);
        if (f0 != 3.4028235e38f) {
            fn_80097228(f0, f1, f2);
        }
        if (f3 == 3.4028235e38f) {
            f3 = 14.0f;
        }
        fn_8009724C(0.0f, f3, 0.0f);
        if (f4 == 3.4028235e38f) {
            f4 = 40.0f;
        }
        fn_800971A8(f4);
        if (f5 == 3.4028235e38f) {
            f5 = 348.0f;
        }
        fn_80097134((s32)f5);
        if (v == 0) {
            fn_80097318(1);
        } else {
            fn_80097318(0);
        }
    }
    return (a >> 3) & 1;
}

s16 fn_8020660C(u16 f, Scpt* s) {
    f32 d, a1, a2, a3, b1, b2, b3, c, e, g, h;
    f32* cur;
    s32 i;
    if (f & 1) {
        cur = s->cur.f;
        fn_801F7500();
        cur = cur + 1;
        a1 = fn_801F6120(&cur);
        a2 = fn_801F6120(&cur);
        a3 = fn_801F6120(&cur);
        b1 = fn_801F6120(&cur);
        b2 = fn_801F6120(&cur);
        b3 = fn_801F6120(&cur);
        c = fn_801F6120(&cur);
        d = fn_801F6120(&cur);
        e = (f32)ReadInt(&cur);
        g = fn_801F6120(&cur);
        h = fn_801F6120(&cur);
        i = ReadInt(&cur);
        s->cur.f = cur;
        fn_80097294(6);
        if (a1 != 3.4028235e38f) fn_80097270(a1, a2, a3);
        if (b1 != 3.4028235e38f) fn_8009724C(b1, b2, b3);
        fn_800971C4(c);
        fn_800971E0(d, 0, 0);
        if (e == 0.0f) fn_80097150(0);
        if (e == 1.0f) fn_80097150(0x8000);
        if (g != 3.4028235e38f) fn_80097118(g);
        if (h != 3.4028235e38f) fn_800970FC(h);
        if (i == 0) fn_80097318(1);
        else fn_80097318(0);
    }
    return (f >> 3) & 1;
}

s16 fn_80206904(u16 a, Scpt *st) {
    if (a & 1) {
        f32 *cur = st->cur.f;
        f32 f0, f1, f2, f3, f4, f5;
        s32 v;
        fn_801F7500();
        cur++;
        f0 = fn_801F6120(&cur);
        f1 = fn_801F6120(&cur);
        f2 = fn_801F6120(&cur);
        f3 = fn_801F6120(&cur);
        f4 = fn_801F6120(&cur);
        f5 = fn_801F6120(&cur);
        v = RDI(cur);
        st->cur.f = cur;
        fn_80097294(5);
        if (f0 != 3.4028235e38f) {
            fn_80097228(f0, f1, f2);
        }
        if (f3 != 3.4028235e38f) {
            fn_8009724C(f3, f4, f5);
        }
        if (v == 0) {
            fn_80097318(1);
        } else {
            fn_80097318(0);
        }
    }
    return (a >> 3) & 1;
}

s16 fn_80206AB0(u16 a, Scpt *st) {
    if (a & 1) {
        f32 *cur = st->cur.f;
        f32 f0, f1, f2, f3, f4, f5, f6, f7;
        s32 v;
        fn_801F7500();
        fn_80097294(4);
        cur++;
        f0 = fn_801F6120(&cur);
        f1 = fn_801F6120(&cur);
        f2 = fn_801F6120(&cur);
        fn_80097204(f0, f1, f2);
        f3 = fn_801F6120(&cur);
        f4 = fn_801F6120(&cur);
        f5 = fn_801F6120(&cur);
        fn_8009724C(f3, f4, f5);
        f6 = fn_801F6120(&cur);
        f7 = fn_801F6120(&cur);
        fn_80097188(f6, f7);
        v = RDI(cur);
        fn_8009716C(RDI(cur));
        st->cur.f = cur;
        if (f0 != 3.4028235e38f) {
            fn_80097204(f0, f1, f2);
        }
        if (v == 0) {
            fn_80097318(1);
        } else {
            fn_80097318(0);
        }
    }
    return (a >> 3) & 1;
}

s16 fn_80206CBC(u16 a, Scpt *st) {
    if (a & 1) {
        f32 *cur = st->cur.f;
        Eff *w;
        fn_801F7500();
        cur++;
        w = fn_801E1A2C(1, 0x24);
        w->f[0] = fn_801F6120(&cur);
        w->f[1] = fn_801F6120(&cur);
        w->f[2] = fn_801F6120(&cur);
        w->f[3] = fn_801F6120(&cur);
        w->f[4] = fn_801F6120(&cur);
        w->f[5] = fn_801F6120(&cur);
        w->f[6] = fn_801F6120(&cur);
        w->f[7] = fn_801F6120(&cur);
        w->x20 = RDI(cur);
        st->work.eff = w;
        st->cur.f = cur;
        st->a20 = 2;
        st->flags = 0;
        return 1;
    }
    if (a & 2) {
        Eff *w;
        if (--st->a20 == 0) {
            w = st->work.eff;
            st->a20 = 0;
            fn_80097294(3);
            if (w->f[0] != 3.4028235e38f) {
                fn_80097204(w->f[0], w->f[1], w->f[2]);
            }
            if (w->f[3] != 3.4028235e38f) {
                fn_8009724C(w->f[3], w->f[4], w->f[5]);
            }
            if (w->f[6] != 3.4028235e38f) {
                fn_80097118(w->f[6]);
            }
            if (w->f[7] != 3.4028235e38f) {
                fn_800970FC(w->f[7]);
            }
            if (w->x20 == 0) {
                fn_80097318(1);
            } else {
                fn_80097318(0);
            }
            return 0;
            }
        return 1;
    }
    return (a >> 3) & 1;
}

s16 fn_80206EA8(u16 a, Scpt *st) {
    if (a & 1) {
        f32 *cur = st->cur.f;
        s32 v;
        u16 id;
        f32 f;
        fn_801F7500();
        lbl_80310B3C[34] |= 2;
        cur++;
        id = RDI(cur);
        f = fn_801F6120(&cur);
        v = RDI(cur);
        st->cur.f = cur;
        fn_80097294(2);
        fn_80097094(id, f);
        if ((u16)v == 0) {
            fn_80097318(1);
        } else {
            fn_80097318(0);
        }
    }
    return (a >> 3) & 1;
}
s16 fn_80206FF4(u32 a0, Scpt *st) {
    s32 n;
    u16 a = a0;
    f32 x, y, z;
    if (a0 & 1) {
        u8 *p = st->cur.b;
        fn_801F7500();
        p += 4;
        x = fn_801F6120((f32**)&p);
        y = fn_801F6120((f32**)&p);
        z = fn_801F6120((f32**)&p);
        if (3.4028235e38f == *(f32 *)p) {
            p += 4;
            n = 0x7fffffff;
        } else {
            n = (s32)fn_801F6120((f32**)&p);
        }
        st->cur.b = p;
        fn_80097294(1);
        if (3.4028235e38f != x) {
            fn_80097204(x, y, z);
        }
        if (n == 0) {
            fn_80097318(1);
        } else {
            fn_80097318(0);
        }
    }
    return (a >> 3) & 1;
}
s16 fn_80207130(u32 a0, Scpt *st) {
    s32 n;
    u16 a = a0;
    f32 x, y, z;
    if (a0 & 1) {
        u8 *p = st->cur.b;
        fn_801F7500();
        p += 4;
        x = fn_801F6120((f32**)&p);
        y = fn_801F6120((f32**)&p);
        z = fn_801F6120((f32**)&p);
        if (3.4028235e38f == *(f32 *)p) {
            p += 4;
            n = 0x7fffffff;
        } else {
            n = (s32)fn_801F6120((f32**)&p);
        }
        st->cur.b = p;
        fn_80097294(1);
        if (3.4028235e38f != x) {
            fn_80097228(x, y, z);
        }
        if (n == 0) {
            fn_80097318(1);
        } else {
            fn_80097318(0);
        }
    }
    return (a >> 3) & 1;
}


s32 fn_8020726C(u16 flags, Scpt *s)
{
    u8 *c;
    if (flags & 1) {
        c = s->cur.b;
        fn_801F7500();
        s->cur.b = c + 4;
        lbl_8030CEA0.x18fc = lbl_80311970.f[0];
        lbl_8030CEA0.x1900 = lbl_80311970.f[1];
        lbl_8030CEA0.x1904 = lbl_80311970.f[2];
        lbl_8030CEA0.x1908 = lbl_80311970.w[0];
        lbl_8030CEA0.x190c = lbl_80311970.w[1];
        lbl_8030CEA0.x1910 = lbl_80311970.w[2];
        fn_80097294(0);
    }
    if (flags & 8) {
        return 1;
    }
    return 0;
}

s32 fn_8020731C(u32 a, Scpt *st) {
    if (a & 1) {
        u8 *c = st->cur.b;
        st->cur.b = c + 4;
        fn_80210CE4();
        fn_801F7500();
        lbl_8030CEA0.x15cc = 0;
    }
    return 0;
}

s32 fn_80207368(u32 a, Scpt *st) {
    if (a & 1) {
        u8 *c = st->cur.b;
        fn_800976EC(a);
        st->cur.b = c + 4;
    }
    return 0;
}

s32 fn_802073B4(u32 flags, Scpt *st) {
    u16 f = flags;
    if (flags & 1) {
        u8 *c = st->cur.b;
        u32 w = *(u32 *)(c + 4);
        u8 *q = c + 4;
        fn_801002D0(q + w);
        st->cur.b = q + 4;
    }
    if (f & 8) return 1;
    return 0;
}

s32 fn_80207428(u32 flags, Scpt *st) {
    u16 f = flags;
    if (flags & 1) {
        u8 *c = st->cur.b;
        u32 w = *(u32 *)(c + 4);
        u8 *q = c + 4;
        fn_801002D0(q + w);
        st->cur.b = q + 4;
        fn_801F7B04(0x9C40);
        lbl_80347474 = 1;
    }
    if (f & 8) return 1;
    return 0;
}

/* Script command: reads three floats and passes them to fn_800C8E44. */
void fn_800C8E44(f32 a, f32 b, f32 c);
s32 fn_802074B0(u32 flags, Scpt *s) {
    ScptCur cur;
    f32 v[3];
    u16 f = flags;
    if (f & 1) {
        cur.f = s->cur.f + 1;
        v[0] = fn_801F6120(&cur.f);
        v[1] = fn_801F6120(&cur.f);
        v[2] = fn_801F6120(&cur.f);
        s->cur.f = cur.f;
        fn_800C8E44(v[0], v[1], v[2]);
    }
    if (f & 8) return 1;
    return 0;
}

s32 fn_80207554(u32 flags, Scpt *c) {
    ScptCur cur;
    s32 i;
    s32 n;
    s32 v;
    if (flags & 1) {
        cur.f = c->cur.f;
        cur.f++;
        n = *cur.i++;
        for (i = 0; i < n; i++) {
            u16 id;
            if (*cur.f == 3.4028235e38f) {
                cur.f++;
                v = 0x7FFFFFFF;
            } else {
                v = fn_801F6120(&cur.f);
            }
            id = v;
            fn_80210EA4(id, 5);
        }
        c->cur.f = cur.f;
    }
    return 0;
}

s32 fn_80207630(u32 flags, Scpt *st) {
    if (flags & 1) {
        float *p = st->cur.f;
        s32 i;
        s32 cnt;
        s32 *q = (s32 *)++p;
        p++;
        cnt = *q;
        for (i = 0; i < cnt; i++) {
            s32 n;
            u16 id;
            void *a;
            if (*p == 3.4028235e38f) {
                p++;
                n = 0x7FFFFFFF;
            } else {
                n = (s32)fn_801F6120(&p);
            }
            id = n;
            fn_80210EA4(id, 2);
            a = fn_8015F1A0(id);
            if (fn_8015F1F0(a) == 1) {
                Obj_80207630 *o = fn_8015F180(a);
                o->f190 = 0.0f;
            }
        }
        st->cur.f = p;
    }
    return 0;
}
void fn_80207738(s32 a, s32 b)
{
    Scpt s;
    s32 i;

    for (i = 0; i < 256; i++) {
        if (lbl_8030CEA0.ent[i][0] != 0) {
            s32 args[5] = { 0, 0, 0x1D, 0, 0x1D };
            s.cur.i = args;
            args[0] = a;
            args[1] = b + 0x8000000;
            args[3] = i + 0x8000000;
            s.work.n = 0;
            s.owner = a;
            if (fn_80207830(1, &s) == 1) {
                s.kind = 1;
                s.cnt = 0;
                s.handle = 0;
                fn_80210F74(&s);
            }
        }
    }
}

s16 fn_80207830(u16 f, Scpt* s) {
    ScptCur cur;
    Work801F8* w;
    s32 b;
    u32 n;
    s32 a;
    u32 i;
    if (f & 1) {
        cur.f = s->cur.f;
        a = *cur.u++;
        b = ReadInt(&cur.f);
        n = *cur.u++;
        if (n == 0x10000) {
            fn_80207738(a, b);
            return 0;
        }
        for (i = 0; i < n; i++) {
            w = fn_801E1A2C(1, 0x44);
            if (w == NULL) fn_801DBE1C("Cl: malloc failed %d", i);
            s->work.p = w;
            w->ev.hd.kind = 0;
            w->n = ReadInt(&cur.f);
            w->x1c = b;
            fn_80211058(s, 6, w->n, 15, lbl_8030CEA0.x08, &w->ev);
            s->kind = 1;
            s->cnt = 0;
            fn_80210F74(s);
        }
        s->cur.f = cur.f;
        return 0;
    }
    if (f & 2) {
        w = s->work.p;
        if (s->handle == 0) {
            s->handle = fn_800CD0B8(s->a20, s->a24, s->a28, s->a2c);
            s->cnt += 1;
            if (s->cnt == 5) fn_801DBE1C("scptCl: message post time out");
        } else if (w->ev.hd.kind == 2) {
            return 0;
        }
    }
    if (f & 8) return 1;
    return 1;
}

s32 fn_80207A40(u32 flags, Scpt* s)
{
    f32* p;
    s32 id;
    s16 k;
    u16 f = flags;
    if (f & 1) {
        p = s->cur.f;
        p++;
        id = RDI(p);
        s->cur.f = p;
        if (id == 0x10000) {
            ReleaseAll();
            return 0;
        }
        fn_802107A4(s, id);
    }
    if (f & 2) {
        Work801F8* w = s->work.work801F8;
        if (s->handle == 0) {
            s->handle = fn_800CD0B8(s->a20, s->a24, s->a28, s->a2c);
            s->cnt += 1;
            if (s->cnt == 5) fn_801DBE1C("scptRet: message post time out %d", w->n);
        } else if (w->ev.hd.kind == 2) {
            k = fn_801F6EC8(w->n);
            if (k != -1) {
                lbl_8030CEA0.ent[k][0] = 0;
            } else {
                fn_801DBE1C("scptRet: no use enter table!!! No:%d", w->n);
            }
            return 0;
        }
    }
    if (f & 8) {
        Work801F8* w = s->work.work801F8;
        k = fn_801F6EC8(w->n);
        if (k != -1) {
            lbl_8030CEA0.ent[k][0] = 0;
        } else {
            fn_801DBE1C("scptRet: no use enter table!!! No:%d", w->n);
        }
    }
    return 1;
}

s32 fn_80207C2C(u16 flags, Scpt *s)
{
    float *p;
    s32 v;
    if (flags & 1) {
        p = s->cur.f;
        p++;
        if (3.4028235e38f == *p) {
            p++;
            v = 0x7FFFFFFF;
        } else {
            v = fn_801F6120(&p);
        }
        s->cur.f = p;
        fn_801165BC(v);
    }
    if (flags & 8) {
        return 1;
    }
    return 0;
}

s32 fn_80207CD0(u32 flags, Scpt* s)
{
    Work_80207CD0* w;
    f32* p;
    s32 id;
    s32 v;
    f32 f0, f1, f2;
    u16 f = flags;
    if (f & 1) {
        p = s->cur.f;
        p++;
        id = (u16)RDI(p);
        v = (u16)RDI(p);
        f0 = fn_801F6120(&p);
        f1 = fn_801F6120(&p);
        f2 = fn_801F6120(&p);
        s->cur.f = p;
        w = fn_801E1A2C(1, 0x44);
        if (w == NULL) fn_801DBE1C("NecM: malloc failed");
        s->work.work_80207CD0 = w;
        w->ev.hd.kind = 0;
        w->id = id;
        w->v = v;
        w->f0 = f0;
        w->f1 = f1;
        w->f2 = f2;
        fn_80211058(s, 6, id, 0x1b, lbl_8030CEA0.x08, &w->ev);
    }
    if (f & 2) {
        w = s->work.work_80207CD0;
        if (s->handle == 0) {
            s->handle = fn_800CD0B8(s->a20, s->a24, s->a28, s->a2c);
            s->cnt += 1;
            if (s->cnt == 5) fn_801DBE1C("necM: message post timed out");
        } else if (w->ev.hd.kind == 2) {
            return 0;
        }
    }
    if (f & 8) {
        return 1;
    }
    return 1;
}

s32 fn_80207ED0(u16 flags, Scpt* c)
{
    Rec* r;
    f32* p;
    if (flags & 1) {
        p = c->cur.f;
        p++;
        r = fn_801E1A2C(1, 0x44);
        if (r == 0) {
            fn_801DBE1C("scptNecA: malloc failed");
        }
        c->work.rec = r;
        r->n = RDI(p);
        r->f1c = fn_801F6120(&p);
        c->cur.f = p;
        r->ev.hd.kind = 0;
        fn_80211058(c, 6, r->n, 8, lbl_8030CEA0.x08, &r->ev);
    }
    if (flags & 2) {
        Rec* w = c->work.rec;
        if (c->handle == 0) {
            c->handle = fn_800CD0B8(c->a20, c->a24, c->a28, c->a2c);
            c->cnt++;
            if (c->cnt == 5) {
                fn_801DBE1C("scptNecA: message post time out");
            }
        } else if (w->ev.hd.kind == 2) {
            return 0;
        }
    }
    if (flags & 8) {
        return 1;
    }
    return 1;
}

s32 fn_80208044(u16 flags, Scpt* c)
{
    Rec* r;
    f32* p;
    if (flags & 1) {
        p = c->cur.f;
        p++;
        r = fn_801E1A2C(1, 0x44);
        if (r == 0) {
            fn_801DBE1C("scptPutP: malloc failed");
        }
        c->work.rec = r;
        r->n = RDI(p);
        r->f1c = fn_801F6120(&p);
        r->f20 = fn_801F6120(&p);
        r->f24 = fn_801F6120(&p);
        r->f28 = fn_801F6120(&p);
        r->f2c = fn_801F6120(&p);
        r->f30 = fn_801F6120(&p);
        r->i34 = RDI(p);
        c->cur.f = p;
        r->ev.hd.kind = 0;
        fn_80211058(c, 6, r->n, 5, lbl_8030CEA0.x08, &r->ev);
    }
    if (flags & 2) {
        Rec* w = c->work.rec;
        if (c->handle == 0) {
            c->handle = fn_800CD0B8(c->a20, c->a24, c->a28, c->a2c);
            c->cnt++;
            if (c->cnt == 5) {
                fn_801DBE1C("scptPutP: message post time out");
            }
        } else if (w->ev.hd.kind == 2) {
            return 0;
        }
    }
    if (flags & 8) {
        return 1;
    }
    return 1;
}

s32 fn_80208234(u16 flags, Scpt* c)
{
    Rec* r;
    f32* p;
    if (flags & 1) {
        p = c->cur.f;
        p++;
        r = fn_801E1A2C(1, 0x44);
        if (r == 0) {
            fn_801DBE1C("scptPutA: malloc failed");
        }
        c->work.rec = r;
        r->n = RDI(p);
        r->f1c = fn_801F6120(&p);
        r->f20 = fn_801F6120(&p);
        r->f24 = fn_801F6120(&p);
        r->f28 = fn_801F6120(&p);
        r->f2c = fn_801F6120(&p);
        r->f30 = fn_801F6120(&p);
        r->i34 = RDI(p);
        c->cur.f = p;
        r->ev.hd.kind = 0;
        fn_80211058(c, 6, r->n, 4, lbl_8030CEA0.x08, &r->ev);
    }
    if (flags & 2) {
        Rec* w = c->work.rec;
        if (c->handle == 0) {
            c->handle = fn_800CD0B8(c->a20, c->a24, c->a28, c->a2c);
            c->cnt++;
            if (c->cnt == 5) {
                fn_801DBE1C("scptPutA: message post time out");
            }
        } else if (w->ev.hd.kind == 2) {
            return 0;
        }
    }
    if (flags & 8) {
        return 1;
    }
    return 1;
}

s32 fn_80208424(u16 flags, Scpt* c)
{
    Rec_80208424* r;
    f32* p;
    if (flags & 1) {
        p = c->cur.f;
        p++;
        r = fn_801E1A2C(1, 0x44);
        if (r == 0) {
            fn_801DBE1C("scptNormalFace: malloc failed");
        }
        c->work.rec_80208424 = r;
        r->n = RDI(p);
        r->i1c = RDI(p);
        c->cur.f = p;
        r->ev.hd.kind = 0;
        fn_80211058(c, 6, r->n, 0x2d, lbl_8030CEA0.x08, &r->ev);
    }
    if (flags & 2) {
        Rec_80208424* w = c->work.rec_80208424;
        if (c->handle == 0) {
            c->handle = fn_800CD0B8(c->a20, c->a24, c->a28, c->a2c);
            c->cnt++;
            if (c->cnt == 5) {
                fn_801DBE1C("scptNormalFace: message post time out");
            }
        } else if (w->ev.hd.kind == 2) {
            return 0;
        }
    }
    if (flags & 8) {
        return 1;
    }
    return 1;
}

s32 fn_802085CC(u16 flags, Scpt* c)
{
    Rec_80208424* r;
    f32* p;
    if (flags & 1) {
        p = c->cur.f;
        p++;
        r = fn_801E1A2C(1, 0x44);
        if (r == 0) {
            fn_801DBE1C("scptFace: malloc failed");
        }
        c->work.rec_80208424 = r;
        r->n = RDI(p);
        r->i1c = RDI(p);
        c->cur.f = p;
        r->ev.hd.kind = 0;
        fn_80211058(c, 6, r->n, 3, lbl_8030CEA0.x08, &r->ev);
    }
    if (flags & 2) {
        Rec_80208424* w = c->work.rec_80208424;
        if (c->handle == 0) {
            c->handle = fn_800CD0B8(c->a20, c->a24, c->a28, c->a2c);
            c->cnt++;
            if (c->cnt == 5) {
                fn_801DBE1C("scptFace: message post time out");
            }
        } else if (w->ev.hd.kind == 2) {
            return 0;
        }
    }
    if (flags & 8) {
        return 1;
    }
    return 1;
}

s32 fn_80208774(u16 flags, Scpt* c)
{
    Rec* r;
    f32* p;
    if (flags & 1) {
        p = c->cur.f;
        r = fn_801E1A2C(1, 0x44);
        if (r == 0) {
            fn_801DBE1C("scptLet'sTalk: malloc failed");
        }
        c->work.rec = r;
        p++;
        r->n = RDI(p);
        r->ev.hd.kind = 0;
        fn_80211058(c, 6, r->n, 0x11, lbl_8030CEA0.x08, &r->ev);
        c->cur.f = p;
    }
    if (flags & 2) {
        Rec* w = c->work.rec;
        if (c->handle == 0) {
            c->handle = fn_800CD0B8(c->a20, c->a24, c->a28, c->a2c);
            c->cnt++;
            if (c->cnt == 5) {
                fn_801DBE1C("scptLetsTalk: message post time out");
            }
        } else if (w->ev.hd.kind == 2) {
            return 0;
        }
    }
    return 1;
}

/* Script "enter": waits for the event id given by the argument, then posts its message. */
s32 fn_802088D8(u32 flags, Scpt* s) {
    Work801F8* w;
    f32* cur;
    u16 f = flags;
    s32 t;
    if (f & 1) {
        cur = s->cur.f;
        cur = cur + 1;
        if (*cur == 3.4028235e38f) {
            cur++;
            t = 0x7fffffff;
        } else {
            t = fn_801F6120(&cur);
        }
        s->cur.f = cur;
        if (fn_80210860(s, t) == 0) return 0;
    }
    if (f & 2) {
        w = s->work.work801F8;
        if (s->handle == 0) {
            s->handle = fn_800CD0B8(s->a20, s->a24, s->a28, s->a2c);
            s->cnt += 1;
            if (s->cnt == 5) fn_801DBE1C("scptEnter: message post time out %d", w->n);
        } else if (w->ev.hd.kind == 2) {
            lbl_8030CEA0.ent[w->x1c][0] = 2;
            return 0;
        }
    }
    return !(f & 8);
}

s32 fn_80208A20(u16 flags, Scpt* c)
{
    Rec_80208A20* r;
    f32* p;
    if (flags & 1) {
        p = c->cur.f;
        p++;
        r = fn_801E1A2C(1, 0x44);
        if (r == 0) {
            fn_801DBE1C("scptChangeParts: malloc failed");
        }
        c->work.rec_80208A20 = r;
        r->n = RDI(p);
        r->i1c = RDI(p);
        r->i20 = RDI(p);
        c->cur.f = p;
        r->ev.hd.kind = 0;
        fn_80211058(c, 6, r->n, 0xe, lbl_8030CEA0.x08, &r->ev);
    }
    if (flags & 2) {
        Rec_80208A20* w = c->work.rec_80208A20;
        if (c->handle == 0) {
            c->handle = fn_800CD0B8(c->a20, c->a24, c->a28, c->a2c);
            c->cnt++;
            if (c->cnt == 5) {
                fn_801DBE1C("ChangeParts: message post time out");
            }
        } else if (w->ev.hd.kind == 2) {
            return 0;
        }
    }
    if (flags & 8) {
        return 1;
    }
    return 1;
}

s32 fn_80208C08(u16 flags, Scpt* c)
{
    Rec_80208424* r;
    f32* p;
    if (flags & 1) {
        u16 n;
        s32 v;
        p = c->cur.f + 1;
        n = RDI(p);
        v = RDI(p);
        r = fn_801E1A2C(1, 0x44);
        if (r == 0) {
            fn_801DBE1C("TextChabne: malloc failed");
        }
        c->work.rec_80208424 = r;
        r->ev.hd.kind = 0;
        r->n = n;
        r->i1c = v;
        fn_80211058(c, 6, r->n, 0x10, lbl_8030CEA0.x08, &r->ev);
        c->cur.f = p;
    }
    if (flags & 2) {
        Rec_80208424* w = c->work.rec_80208424;
        if (c->handle == 0) {
            c->handle = fn_800CD0B8(c->a20, c->a24, c->a28, c->a2c);
            c->cnt++;
            if (c->cnt == 5) {
                fn_801DBE1C("TextChange: message post timed out");
            }
        } else if (w->ev.hd.kind == 2) {
            return 0;
        }
    }
    if (flags & 8) {
        return 1;
    }
    return 1;
}

s32 fn_80208D9C(u16 flags, Scpt* c)
{
    Rec_80208424* r;
    f32* p;
    if (flags & 1) {
        u16 n;
        s32 v;
        p = c->cur.f + 1;
        n = RDI(p);
        v = RDI(p);
        r = fn_801E1A2C(1, 0x44);
        if (r == 0) {
            fn_801DBE1C("CWait: malloc failed");
        }
        c->work.rec_80208424 = r;
        r->ev.hd.kind = 0;
        r->n = n;
        r->i1c = v;
        fn_80211058(c, 6, r->n, 0x1c, lbl_8030CEA0.x08, &r->ev);
        c->cur.f = p;
    }
    if (flags & 2) {
        Rec_80208424* w = c->work.rec_80208424;
        if (c->handle == 0) {
            c->handle = fn_800CD0B8(c->a20, c->a24, c->a28, c->a2c);
            c->cnt++;
            if (c->cnt == 5) {
                fn_801DBE1C("CWait: message post timed out");
            }
        } else if (w->ev.hd.kind == 2) {
            return 0;
        }
    }
    if (flags & 8) {
        return 1;
    }
    return 1;
}

void fn_80208F30(s32 a, s32 b)
{
    Scpt s;
    s32 i;

    for (i = 0; i < 256; i++) {
        if (lbl_8030CEA0.ent[i][0] != 0) {
            s32 args[5] = { 0, 0, 0x1D, 0, 0x1D };
            s.cur.i = args;
            args[0] = a;
            args[1] = b + 0x8000000;
            args[3] = i + 0x8000000;
            s.work.n = 0;
            s.owner = a;
            if (fn_80209028(1, &s) == 1) {
                s.kind = 1;
                s.cnt = 0;
                s.handle = 0;
                fn_80210F74(&s);
            }
        }
    }
}
s16 fn_80209028(u16 f, Scpt* s) {
    ScptCur cur;
    Work801F8* w;
    s32 b;
    u32 n;
    s32 a;
    u32 i;
    
    if (f & 1) {
        cur.f = s->cur.f;
        a = *cur.u++;
        b = ReadInt(&cur.f);
        n = *cur.u++;
        if (n == 0x10000) {
            fn_80208F30(a, b);
            return 0;
        }
        for (i = 0; i < n; i++) {
            w = fn_801E1A2C(1, 0x44);
            if (w == NULL) fn_801DBE1C("ClF: malloc failed %d", i);
            s->work.p = w;
            w->ev.hd.kind = 0;
            w->n = ReadInt(&cur.f);
            w->x1c = b;
            fn_80211058(s, 6, w->n, 30, lbl_8030CEA0.x08, &w->ev);
            s->kind = 1;
            s->cnt = 0;
            fn_80210F74(s);
        }
        s->cur.f = cur.f;
        return 0;
    }
    if (f & 2) {
        w = s->work.p;
        if (s->handle == 0) {
            s->handle = fn_800CD0B8(s->a20, s->a24, s->a28, s->a2c);
            s->cnt += 1;
            if (s->cnt == 5) fn_801DBE1C("scptClF: message post time out");
        } else if (w->ev.hd.kind == 2) {
            return 0;
        }
    }
    if (f & 8) return 1;
    return 1;
}

void fn_80209238(s32 a, s32 b)
{
    Scpt s;
    s32 i;

    for (i = 0; i < 256; i++) {
        if (lbl_8030CEA0.ent[i][0] != 0) {
            s32 args[5] = { 0, 0, 0x1D, 0, 0x1D };
            s.cur.i = args;
            args[0] = a;
            args[1] = b + 0x8000000;
            args[3] = i + 0x8000000;
            s.work.n = 0;
            s.owner = a;
            if (fn_80209330(1, &s) == 1) {
                s.kind = 1;
                s.cnt = 0;
                s.handle = 0;
                fn_80210F74(&s);
            }
        }
    }
}

s16 fn_80209330(u32 flags, Scpt *s)
{
    u16 f = flags;
    ScptCur cur;
    Work801F8 *w;
    if (flags & 1) {
        Work801F8 *w;
        Work801F8 *lw;
        s32 b;
        u32 n;
        u32 a;
        u32 i;
        cur = s->cur;
        a = *cur.u++;
        b = ReadInt(&cur.f);
        n = *cur.u++;
        if (n == 0x10000) {
            fn_80209238(a, b);
            return 0;
        }
        for (i = 0; i < n; i++) {
            lw = fn_801E1A2C(1, 0x44);
            if (lw == NULL) {
                fn_801DBE1C("fin: malloc failed %d", i);
            }
            s->work.work801F8 = lw;
            lw->ev.hd.kind = 0;
            lw->n = ReadInt(&cur.f);
            lw->x1c = b;
            fn_80211058(s, 6, lw->n, 0x1d, lbl_8030CEA0.x08, &lw->ev);
            s->kind = 1;
            s->cnt = 0;
            fn_80210F74(s);
        }
        s->cur = cur;
        return 0;
    }
    if (f & 2) {
        w = s->work.work801F8;
        if (s->handle == 0) {
            s->handle = fn_800CD0B8(s->a20, s->a24, s->a28, s->a2c);
            s->cnt += 1;
            if (s->cnt == 5) {
                fn_801DBE1C("scptFin: message post time out");
            }
        }
        if (w->ev.hd.kind == 2) {
            return 0;
        }
    }
    if (f & 8) {
        return 1;
    }
    return 1;
}

s32 fn_80209548(u32 flags, Scpt* s) {
    Work8020* w;
    f32* cur;
    u16 f = flags;
    if (f & 1) {
        cur = s->cur.f + 1;
        w = fn_801E1A2C(1, 0x44);
        if (w == NULL) fn_801DBE1C("Proll: malloc failed");
        s->work.work8020 = w;
        w->n = ReadInt(&cur);
        w->x1c = ReadInt(&cur);
        w->x20 = fn_801F6120(&cur);
        w->x24 = fn_801F6120(&cur);
        w->x28 = fn_801F6120(&cur);
        w->x38 = ReadInt(&cur);
        w->x3c = ReadInt(&cur);
        s->cur.f = cur;
        if (w->x38 == 0x7fffffff) w->x38 = 0;
        if (w->x1c == 0x7fffffff) w->x1c = 0;
        w->ev.hd.kind = 0;
        fn_80211058(s, 6, w->n, 0x22, lbl_8030CEA0.x08, &w->ev);
    }
    if (f & 2) {
        w = s->work.work8020;
        if (s->handle == 0) {
            s->handle = fn_800CD0B8(s->a20, s->a24, s->a28, s->a2c);
            s->cnt += 1;
            if (s->cnt == 5) fn_801DBE1C("Proll: message post timed out");
        } else if (w->ev.hd.kind == 2) {
            return 0;
        }
    }
    if (f & 8) return 1;
    return 1;
}

s32 fn_802097C0(u16 flags, Scpt* c)
{
    Rec_80208A20* r;
    f32* p;
    if (flags & 1) {
        p = c->cur.f;
        r = fn_801E1A2C(1, 0x44);
        if (r == 0) {
            fn_801DBE1C("scptMapDefMO: malloc failed");
        }
        c->work.rec_80208A20 = r;
        p++;
        r->n = RDI(p);
        r->i1c = RDI(p);
        r->f24 = fn_801F6120(&p);
        r->ev.hd.kind = 0;
        fn_80211058(c, 6, r->n, 0x2a, lbl_8030CEA0.x08, &r->ev);
        c->cur.f = p;
    }
    if (flags & 2) {
        Rec_80208A20* w = c->work.rec_80208A20;
        if (c->handle == 0) {
            c->handle = fn_800CD0B8(c->a20, c->a24, c->a28, c->a2c);
            c->cnt++;
            if (c->cnt == 5) {
                fn_801DBE1C("scptMapDefMO: message post time out");
            }
        } else if (w->ev.hd.kind == 2) {
            return 0;
        }
    }
    if (flags & 8) {
        return 1;
    }
    return 1;
}

s32 fn_80209974(u16 flags, Scpt* c)
{
    Rec_80209974* r;
    f32* p;
    if (flags & 1) {
        p = c->cur.f + 1;
        r = fn_801E1A2C(1, 0x44);
        if (r == 0) {
            fn_801DBE1C("PartsScale: malloc failed");
        }
        c->work.rec_80209974 = r;
        r->n = RDI(p);
        r->n2 = RDI(p);
        r->f1c = fn_801F6120(&p);
        r->f20 = fn_801F6120(&p);
        r->f24 = fn_801F6120(&p);
        r->i28 = RDI(p);
        c->cur.f = p;
        if (r->i28 == 0x7FFFFFFF) {
            r->i28 = 1;
        }
        r->ev.hd.kind = 0;
        fn_80211058(c, 6, r->n, 0x29, lbl_8030CEA0.x08, &r->ev);
    }
    if (flags & 2) {
        Rec_80209974* w = c->work.rec_80209974;
        if (c->handle == 0) {
            c->handle = fn_800CD0B8(c->a20, c->a24, c->a28, c->a2c);
            c->cnt++;
            if (c->cnt == 5) {
                fn_801DBE1C("PartsScale: message post timed out");
            }
        } else if (w->ev.hd.kind == 2) {
            return 0;
        }
    }
    if (flags & 8) {
        return 1;
    }
    return 1;
}

s32 fn_80209B94(u16 flags, Scpt* c)
{
    Rec_80209974* r;
    f32* p;
    if (flags & 1) {
        p = c->cur.f + 1;
        r = fn_801E1A2C(1, 0x44);
        if (r == 0) {
            fn_801DBE1C("Scale: malloc failed");
        }
        c->work.rec_80209974 = r;
        r->n = RDI(p);
        r->f1c = fn_801F6120(&p);
        r->f20 = fn_801F6120(&p);
        r->f24 = fn_801F6120(&p);
        r->i28 = RDI(p);
        c->cur.f = p;
        if (r->i28 == 0x7FFFFFFF) {
            r->i28 = 1;
        }
        r->ev.hd.kind = 0;
        fn_80211058(c, 6, r->n, 0x23, lbl_8030CEA0.x08, &r->ev);
    }
    if (flags & 2) {
        Rec_80209974* w = c->work.rec_80209974;
        if (c->handle == 0) {
            c->handle = fn_800CD0B8(c->a20, c->a24, c->a28, c->a2c);
            c->cnt++;
            if (c->cnt == 5) {
                fn_801DBE1C("Scale: message post timed out");
            }
        } else if (w->ev.hd.kind == 2) {
            return 0;
        }
    }
    if (flags & 8) {
        return 1;
    }
    return 1;
}

s32 fn_80209D74(u16 flags, Scpt* c)
{
    Rec_80209974* r;
    f32* p;
    if (flags & 1) {
        p = c->cur.f + 1;
        r = fn_801E1A2C(1, 0x44);
        if (r == 0) {
            fn_801DBE1C("ReSetShadow: malloc failed");
        }
        c->work.rec_80209974 = r;
        r->n = RDI(p);
        c->cur.f = p;
        r->ev.hd.kind = 0;
        fn_80211058(c, 6, r->n, 0x2c, lbl_8030CEA0.x08, &r->ev);
    }
    if (flags & 2) {
        Rec_80209974* w = c->work.rec_80209974;
        if (c->handle == 0) {
            c->handle = fn_800CD0B8(c->a20, c->a24, c->a28, c->a2c);
            c->cnt++;
            if (c->cnt == 5) {
                fn_801DBE1C("ReSetShadow: message post timed out");
            }
        } else if (w->ev.hd.kind == 2) {
            return 0;
        }
    }
    if (flags & 8) {
        return 1;
    }
    return 1;
}

s32 fn_80209ED8(u16 flags, Scpt* c)
{
    Rec_80209974* r;
    f32* p;
    if (flags & 1) {
        p = c->cur.f + 1;
        r = fn_801E1A2C(1, 0x44);
        if (r == 0) {
            fn_801DBE1C("Scale: malloc failed");
        }
        c->work.rec_80209974 = r;
        r->n = RDI(p);
        r->f1c = fn_801F6120(&p);
        c->cur.f = p;
        r->ev.hd.kind = 0;
        fn_80211058(c, 6, r->n, 0x2b, lbl_8030CEA0.x08, &r->ev);
    }
    if (flags & 2) {
        Rec_80209974* w = c->work.rec_80209974;
        if (c->handle == 0) {
            c->handle = fn_800CD0B8(c->a20, c->a24, c->a28, c->a2c);
            c->cnt++;
            if (c->cnt == 5) {
                fn_801DBE1C("SetShadow: message post timed out");
            }
        } else if (w->ev.hd.kind == 2) {
            return 0;
        }
    }
    if (flags & 8) {
        return 1;
    }
    return 1;
}

s32 fn_8020A048(u32 flags, Scpt *c) {
    float *p;
    s32 a;
    f32 x;
    f32 y;
    f32 z;
    f32 w;
    u16 fl = flags;
    p = c->cur.f;
    if (flags & 1) {
        p++;
        if (*p == 3.4028235e38f) {
            p++;
            a = 0x7FFFFFFF;
        } else {
            a = (s32)fn_801F6120(&p);
        }
        x = fn_801F6120(&p);
        y = fn_801F6120(&p);
        z = fn_801F6120(&p);
        w = fn_801F6120(&p);
        fn_80118578(a, x, y, z, w);
        c->cur.f = p;
    }
    if (fl & 8) {
        return 1;
    }
    return 0;
}

s32 fn_8020A168(u16 flags, Scpt* c)
{
    f32* p = c->cur.f;
    if (flags & 1) {
        s32 n;
        f32 a, b, d, e, f, g;
        p++;
        n = RDI(p);
        a = fn_801F6120(&p);
        b = fn_801F6120(&p);
        d = fn_801F6120(&p);
        e = fn_801F6120(&p);
        f = fn_801F6120(&p);
        g = fn_801F6120(&p);
        fn_801185A8(n, a, b, d, e, f, g);
        c->cur.f = p;
    }
    if (flags & 8) {
        return 1;
    }
    return 0;
}

s16 fn_8020A2C8(u32 flags, Scpt *st) {
    u16 f = flags;
    u8 *c = st->cur.b;
    if (flags & 1) {
        s32 v;
        st->cur.b = c + 4;
        v = fn_8011768C(flags);
        if (v != -1) {
            lbl_8030CEA0.x1574 = v;
        } else {
            lbl_8030CEA0.x1574 = 0;
        }
    }
    return (f >> 3) & 1;
}
s32 fn_8020A338(u16 flags, Scpt* c)
{
    ScptCur p;
    Work_8020A584* r;
    char* q;
    s32 n1;
    s32 n2;
    if (flags & 1) {
        p.f = c->cur.f + 1;
        n1 = RDI(p.f);
        q = p.s;
        p.f++;
        n2 = RDI(p.f);
        c->cur.f = p.f;
        q += StrWord(q) & ~3;
        if (StrWord(q) == 9) {
            q += 4;
            while (StrWord(q) != 0x1d) q += 4;
            q += 4;
        } else {
            fn_801DBE1C("scptSELECT CHOSE: NO LABEL!");
        }
        lbl_8030CEA0.x15c8 = 1;
        r = fn_801E1A2C(1, 0x10);
        if (r == 0) {
            fn_801DBE1C("scptSELECT1: malloc failed");
        }
        c->work.work_8020A584 = r;
        r->hd.kind = 0;
        r->x08 = n1;
        r->hd.x04 = n2;
        if (n2 != 0x7FFFFFFF) {
            u32 len = strlen(q);
            q[len - 2] = 0x5c;
            q[len - 1] = 0x63;
        }
        r->x0c = q;
        fn_802110E8(c, 5, 0, 1, lbl_8030CEA0.x08, &r->hd);
    }
    if (flags & 2) {
        Work_8020A584* w = c->work.work_8020A584;
        if (c->handle == 0) {
            c->handle = fn_800CD0B8(c->a20, c->a24, c->a28, c->a2c);
            c->cnt++;
            if (c->cnt == 5) {
                fn_801DBE1C("scptPRINT: message post timed out");
            }
        } else if (w->hd.kind == 2) {
            lbl_8030CEA0.x15c8 = 0;
            lbl_8030CEA0.x1568 = w->x08;
            return 0;
        }
    }
    if (flags & 8) {
        lbl_8030CEA0.x15c8 = 0;
        return 0;
    }
    return 1;
}
s32 fn_8020A584(u16 flags, Scpt* c)
{
    Work_8020A584* r;
    f32* p;
    if (flags & 1) {
        s32 n;
        char* s;
        p = c->cur.f + 1;
        n = RDI(p);
        s = (char*)p + *(s32*)p;
        p++;
        c->cur.f = p;
        lbl_8030CEA0.x15c8 = 1;
        r = fn_801E1A2C(1, 0x10);
        if (r == 0) {
            fn_801DBE1C("scptSELECT1: malloc failed");
        }
        c->work.work_8020A584 = r;
        r->hd.kind = 0;
        r->x08 = n;
        r->x0c = s;
        fn_802110E8(c, 5, 0, 1, lbl_8030CEA0.x08, &r->hd);
    }
    if (flags & 2) {
        Work_8020A584* w = c->work.work_8020A584;
        if (c->handle == 0) {
            c->handle = fn_800CD0B8(c->a20, c->a24, c->a28, c->a2c);
            c->cnt++;
            if (c->cnt == 5) {
                fn_801DBE1C("scptPRINT: message post timed out");
            }
        } else if (w->hd.kind == 2) {
            lbl_8030CEA0.x15c8 = 0;
            lbl_8030CEA0.x1568 = w->x08;
            return 0;
        }
    }
    if (flags & 8) {
        lbl_8030CEA0.x15c8 = 0;
        return 0;
    }
    return 1;
}

s32 fn_8020A72C(void) {
    return 0;
}

s32 fn_8020A734(u16 flags, Scpt* s)
{
    ScptCur base;
    f32* p;
    s32 v;
    Work_8020A938* w;
    char* str;
    if (flags & 1) {
        base.f = s->cur.f + 1;
        p = base.f;
        p++;
        if (*p == 3.4028235e38f) {
            p++;
            v = 0x7FFFFFFF;
        } else {
            v = (s32)fn_801F6120(&p);
        }
        s->cur.f = p;
        str = base.s;
        str += StrWord(str) & ~3;
        if (StrWord(str) == 9) {
            str += 4;
            while (StrWord(str) != 0x1d) str += 4;
            str += 4;
        } else {
            fn_801DBE1C("scptPRINT MES: NO LABEL!");
        }
        lbl_8030CEA0.x15c8 = 1;
        w = fn_801E1A2C(1, 0xc);
        if (w == NULL) fn_801DBE1C("scptPRINT MES: malloc failed 1");
        s->work.work_8020A938 = w;
        w->hd.kind = 0;
        w->hd.x04 = v;
        if (v != 0x7FFFFFFF) {
            int len = strlen(str);
            str[len - 2] = 0x5c;
            str[len - 1] = 0x63;
        }
        w->x08 = str;
        fn_802110E8(s, 5, 0, 0, lbl_8030CEA0.x08, &w->hd);
    }
    if (flags & 2) {
        w = s->work.work_8020A938;
        if (s->handle == 0) {
            s->handle = fn_800CD0B8(s->a20, s->a24, s->a28, s->a2c);
            s->cnt += 1;
            if (s->cnt == 5) fn_801DBE1C("scptPRINT(MES): message post timed out");
        } else if (w->hd.kind == 2) {
            lbl_8030CEA0.x15c8 = 0;
            return 0;
        }
    }
    if (flags & 8) {
        lbl_8030CEA0.x15c8 = 0;
        return 0;
    }
    return 1;
}
s32 fn_8020A938(u32 flags, Scpt* s)
{
    Work_8020A938* w;
    s32* cur;
    u16 f = flags;
    if (f & 1) {
        cur = s->cur.i + 1;
        {
            u8* end = (u8*)cur;
            end += *cur;
            s->cur.i = cur + 1;
            lbl_8030CEA0.x15c8 = 1;
            w = fn_801E1A2C(1, 0xc);
            if (w == NULL) fn_801DBE1C("scptPRINT: malloc failed 1");
            s->work.work_8020A938 = w;
            w->hd.kind = 0;
            w->x08 = end;
        }
        fn_802110E8(s, 5, 0, 0, lbl_8030CEA0.x08, &w->hd);
    }
    if (f & 2) {
        w = s->work.work_8020A938;
        if (s->handle == 0) {
            s->handle = fn_800CD0B8(s->a20, s->a24, s->a28, s->a2c);
            s->cnt += 1;
            if (s->cnt == 5) fn_801DBE1C("scptPRINT: message post timed out");
        } else if (w->hd.kind == 2) {
            lbl_8030CEA0.x15c8 = 0;
            return 0;
        }
    }
    if (f & 8) {
        lbl_8030CEA0.x15c8 = 0;
        return 0;
    }
    return 1;
}
