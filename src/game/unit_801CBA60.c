#include "types.h"
typedef struct Ent {
    float a;
    s32 b;
    float c;
} Ent;
extern Ent lbl_8030E7C0[4];
extern s32 lbl_803474F8;
extern s32 lbl_8034750C;
void fn_801E1718(void *o);
extern u32 lbl_80347518;
extern f32 lbl_80347510;
extern u32 lbl_80347508;
extern u32 lbl_80347504;
extern s32 fn_8023A4B0(void);
extern u32 lbl_803474F4;
s32 fn_801CB0A4(s32 c);
extern f32 lbl_80347514;
typedef struct { u16 size; u16 type; } Hdr;
typedef struct { u16 cnt; u16 pad; } Cnt;
/* What a request's callback sees and may change. */
typedef struct FioCb {
    char* name;
    s32 addr;
    s32 size;
} FioCb;
/* akFIO.c's open file (unit_801C5A60.c). */
typedef struct AkFio {
    s32 state;
    u8 pad04[0x48 - 0x04];
    void* buf;      /* 0x48 */
    void* x4c;
    u8 pad50[0x54 - 0x50];
    s32 size;       /* 0x54 */
    u8 pad58[0x88 - 0x58];
    s32 prio;       /* 0x88 */
    s32 prio0;      /* 0x8c */
} AkFio;
typedef struct { char* str; s32 w4; } FioName;
typedef struct FioOut {
    s32 addr;
    u32 own;        /* addr was allocated for the request */
} FioOut;
typedef struct FioReq {
    s32 w00;
    AkFio* fio;     /* 0x04 */
    FioOut out;     /* 0x08: where the file reads into (the open file's x4c) */
    s32 w10;
    s32 state;      /* 0x14 */
    s32 w18, w1c;
    s32 cancel;     /* 0x20 */
    FioName* name;  /* 0x24 */
    void (*cb)(void* arg, struct FioCb* io);
    void* cbArg;
    struct FioReq* next;
} FioReq;
s32 fn_801C6BC8(AkFio* f);
AkFio* fn_801C63EC(const char* name);
void fn_801C6384(AkFio* f);
AkFio* fn_801C64DC(const char* name);
void fn_801C6C7C(AkFio* f);
extern s32 fn_801CB460(s32 type);

/* 1 once the open file is done (state 3), 2 on an error (state 4), else 0. */
static inline s32 FioResult(AkFio* f) {
    s32 r = fn_801C6BC8(f);
    s32 v;
    if (r == 3) {
        v = 1;
    } else if (r == 4) {
        v = 2;
    } else {
        v = 0;
    }
    return v;
}
extern FioReq* lbl_80347200;
extern u32 strlen(const char*);
extern void* fn_801E1BDC(s32 size);
extern void fn_801DBE1C(const char*, ...);
extern void strcpy(char*, const char*);
extern u32 lbl_80310B3C[0x356];
extern u8 lbl_80310A1C[0x120];
s32 fn_801CB460(s32 c);
typedef union Vec3 { f32 f[3]; s32 i[3]; } Vec3;
extern char* fn_8025ED74(const char*, const char*);
extern char* strncpy(char*, const char*, u32);
extern void fn_801E0D0C(char*);
extern s32 lbl_803475CC;
extern s32 lbl_803475A0;
extern s32 lbl_80347500;
extern f32 lbl_803471F0;
extern f32 lbl_803471F4;
void fn_801CBC90(void);
void fn_801CB744(void);
void fn_802267AC(s32 a, void* b);
typedef struct FadeVtx {
    f32 x, y, z;
    u32 col;
} FadeVtx;
extern f32 fn_801DBD9C(f32 z);
extern void fn_801CBA98(void);
extern FadeVtx lbl_80308C78[4];
extern u32 lbl_803471F8;
void* fn_801E1C7C(s32 size);
s32 fn_801CBD48(FioReq *s);

s32 fn_801CAE84(void) {
    return 1;
}

void fn_801CAE8C(void) {
}

void fn_801CAE90(void) {
}

void fn_801CAE94(void) {
}

void fn_801CB738(void) {
    lbl_803474F4 = 0;
}

void fn_801CBA60(float a, float c)
{
    s32 i = lbl_803474F8;
    if (i >= 4) {
        return;
    }
    lbl_8030E7C0[i].a = a;
    lbl_8030E7C0[i].b = lbl_8034750C;
    lbl_803474F8 = i + 1;
    lbl_8030E7C0[i].c = c;
}

typedef struct Msg {
    s16 x0;
    s16 x2;
    s16 x4;
    s16 x6;
    s32 x8;
    s32 xc;
} Msg;
void fn_801CBBF8(void) {
    lbl_803471F8 = 1;
}

void fn_801CBC04(void) {
    lbl_803474F8 = 0;
}

void fn_801CBC10(void) {
    fn_801CBC90();
}

u32 fn_801CC0A0(u32 *o)
{
    u32 v;
    if (o[0] != 0) {
        return 0;
    }
    v = o[1];
    fn_801E1718(o);
    return v;
}

s32 fn_801CBE38(void);
void fn_801CC3A4(void) {
    fn_801CBE38();
}

extern void fn_8023AB28();
void fn_801CC578(Msg* a, s32 i) {
    fn_8023AB28(a, i);
}

extern char lbl_8034BD14;
void fn_801CC598(void) {
    fn_8023AB28(&lbl_8034BD14);

}

s32 fn_801CC5BC(AkFio* f)
{
    return FioResult(f);
}

void fn_801CBBBC(void) {
    lbl_80347518 = 0;
    lbl_80347510 = 0.0f;
    lbl_80347508 = 0;
    lbl_80347504 = 0;
}

void fn_801CBBD8(void) {
    lbl_80347518 = 1;
    lbl_80347510 = 1.0f;
    lbl_80347508 = 0;
    lbl_80347504 = 1;
}

void fn_801CC600(u8 *p, u32 v) {
    *(u32 *)(p + 0x4c) = v;
}

u32 fn_801CC62C(void) {
    return fn_8023A4B0() != -1;
}

void fn_801CC65C(AkFio* f) {
    fn_801C6384(f);
}

AkFio* fn_801CC67C(const char* name) {
    return fn_801C63EC(name);
}

AkFio* fn_801CC69C(const char* name) {
    return fn_801C64DC(name);
}

typedef struct DrawVtx {
    f32 x, y, z, w;
} DrawVtx;
extern s32 lbl_8034720C;
extern s16 lbl_80347256;
extern u32 lbl_80347218;
extern u32 lbl_80347258;
extern s32 lbl_80347208;
extern s32 lbl_803475D8;
extern void *lbl_8034725C;
extern s32 lbl_8034721C;
void fn_802A8E50(void *p, u32 len, s32 mode);
void fn_802A8D64(void *p, u32 len, s32 mode);
void fn_8024DE74(void);
void fn_80290ED4(DrawVtx *v, s32 n, s32 a);
void fn_802A8F40(s32 a);
void fn_801D0BC0(s32 a, f32 b);
void fn_8029CEA4(s32 a, s32 b);
extern u8 lbl_80346820;
void fn_8029CE6C(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
void fn_80296EEC(s32 a, s32 b, s32 c);
static inline void FogBuf(s32 mode) {
    u32 len;
    void *p;
    if (lbl_80347256 < 0x400 && lbl_80347218 > lbl_80347258 && lbl_80347208 != 0 && lbl_8034720C != 0) {
        len = lbl_80347218 - lbl_80347258;
        p = lbl_8034725C;
        if (lbl_803475D8 != 0) {
            p = 0;
        }
        if (p != 0) {
            GXFlush();
            if (lbl_8034721C == 0) {
                fn_802A8E50(p, lbl_80347218, mode);
                lbl_8034721C = 1;
            } else {
                fn_802A8D64(p, len, mode);
            }
            fn_8024DE74();
        } else {
            fn_802A8E50(p, len, mode);
        }
        DrawStateApplyFog();
    }
}
void fn_801CD73C(DrawVtx *v, s32 n, s32 a, u32 flags) {
    f32 avg;
    s32 i;

    if (n <= 0) {
        return;
    }
    if (!(flags & 0x800000)) {
        avg = 0.0f;
        for (i = 0; i < n; i++) {
            avg += v[i].z;
        }
        avg /= (f32)n;
    } else {
        avg = v[0].z;
    }
    if (lbl_8034720C != 0 && (flags & 0x1000)) {
        if (a == 0) {
            if (flags & 0x100) {
                FogBuf(2);
                DrawStateReapply();
                fn_80290ED4(v, n, a);
                fn_802A8F40(1);
                if (lbl_80347256 < 0x400 && lbl_80347218 > lbl_80347258 && lbl_80347208 != 0 && lbl_8034720C != 0) {
                    fn_801D0BC0(0, 10000.0f + avg);
                }
                fn_802A8F40(0);
            } else {
                DrawStateReapply();
                fn_80290ED4(v, n, a);
            }
        } else if (flags & 0x8000) {
            FogBuf(3);
            fn_8029CEA4(0, 1);
            fn_8029CE6C(6, lbl_80346820, 0, 6, lbl_80346820, 1);
            DrawStateReapply();
            fn_80290ED4(v, n, a);
            fn_8029CEA4(0, 1);
            fn_8029CE6C(4, 0, 0, 7, 0, 1);
            fn_802A8F40(1);
            if (lbl_80347256 < 0x400 && lbl_80347218 > lbl_80347258 && lbl_80347208 != 0 && lbl_8034720C != 0) {
                fn_801D0BC0(1, 10000.0f + avg);
            }
            fn_802A8F40(0);
        } else {
            FogBuf(3);
            if (flags & 0x4000) {
                fn_80296EEC(1, 3, 0);
            }
            DrawStateReapply();
            fn_80290ED4(v, n, a);
            fn_80296EEC(1, 3, 1);
            fn_802A8F40(1);
            if (lbl_80347256 < 0x400 && lbl_80347218 > lbl_80347258 && lbl_80347208 != 0 && lbl_8034720C != 0) {
                fn_801D0BC0(8, 10000.0f + avg);
            }
            fn_802A8F40(0);
        }
    } else {
        DrawStateReapply();
        fn_80290ED4(v, n, a);
    }
}

typedef struct DrawPt {
    f32 x, y, z;
} DrawPt;
typedef struct LineArgs {
    DrawPt* pts;
} LineArgs;
void fn_802AA2F0(LineArgs *v, s32 n, s32 a);

void fn_801CDC68(LineArgs *v, s32 n, s32 a, u32 flags) {
    f32 avg;
    s32 i;

    if (n <= 0) {
        return;
    }
    if (!(flags & 0x800000)) {
        avg = 0.0f;
        for (i = 0; i < n; i++) {
            avg += v->pts[i].z;
        }
        avg /= (f32)n;
    } else {
        avg = v->pts[0].z;
    }
    if (lbl_8034720C != 0 && (flags & 0x1000)) {
        if (!(a & 0x40)) {
            if (flags & 0x100) {
                FogBuf(2);
                DrawStateReapply();
                fn_802AA2F0(v, n, a);
                fn_802A8F40(1);
                if (lbl_80347256 < 0x400 && lbl_80347218 > lbl_80347258 && lbl_80347208 != 0 && lbl_8034720C != 0) {
                    fn_801D0BC0(0, 10000.0f + avg);
                }
                fn_802A8F40(0);
            } else {
                DrawStateReapply();
                fn_802AA2F0(v, n, a);
            }
        } else if (flags & 0x8000) {
            FogBuf(3);
            fn_8029CEA4(0, 1);
            fn_8029CE6C(6, lbl_80346820, 0, 6, lbl_80346820, 1);
            DrawStateReapply();
            fn_802AA2F0(v, n, a);
            fn_8029CEA4(0, 1);
            fn_8029CE6C(4, 0, 0, 7, 0, 1);
            fn_802A8F40(1);
            if (lbl_80347256 < 0x400 && lbl_80347218 > lbl_80347258 && lbl_80347208 != 0 && lbl_8034720C != 0) {
                fn_801D0BC0(1, 10000.0f + avg);
            }
            fn_802A8F40(0);
        } else {
            FogBuf(3);
            if (flags & 0x4000) {
                fn_80296EEC(1, 3, 0);
            }
            DrawStateReapply();
            fn_802AA2F0(v, n, a);
            fn_80296EEC(1, 3, 1);
            fn_802A8F40(1);
            if (lbl_80347256 < 0x400 && lbl_80347218 > lbl_80347258 && lbl_80347208 != 0 && lbl_8034720C != 0) {
                fn_801D0BC0(8, 10000.0f + avg);
            }
            fn_802A8F40(0);
        }
    } else {
        DrawStateReapply();
        fn_802AA2F0(v, n, a);
    }
}

void fn_8028A418(DrawVtx *v, s32 n, s32 a);
void fn_801CE1A4(DrawVtx *v, s32 n, s32 a, u32 flags) {
    f32 avg;
    s32 i;

    if (n <= 0) {
        return;
    }
    if (!(flags & 0x800000)) {
        avg = 0.0f;
        for (i = 0; i < n; i++) {
            avg += v[i].z;
        }
        avg /= (f32)n;
    } else {
        avg = v[0].z;
    }
    if (lbl_8034720C != 0 && (flags & 0x1000)) {
        if (a == 0) {
            if (flags & 0x100) {
                FogBuf(2);
                DrawStateReapply();
                fn_8028A418(v, n, a);
                fn_802A8F40(1);
                if (lbl_80347256 < 0x400 && lbl_80347218 > lbl_80347258 && lbl_80347208 != 0 && lbl_8034720C != 0) {
                    fn_801D0BC0(0, 10000.0f + avg);
                }
                fn_802A8F40(0);
            } else {
                DrawStateReapply();
                fn_8028A418(v, n, a);
            }
        } else if (flags & 0x8000) {
            FogBuf(3);
            fn_8029CEA4(0, 1);
            fn_8029CE6C(6, lbl_80346820, 0, 6, lbl_80346820, 1);
            DrawStateReapply();
            fn_8028A418(v, n, a);
            fn_8029CEA4(0, 1);
            fn_8029CE6C(4, 0, 0, 7, 0, 1);
            fn_802A8F40(1);
            if (lbl_80347256 < 0x400 && lbl_80347218 > lbl_80347258 && lbl_80347208 != 0 && lbl_8034720C != 0) {
                fn_801D0BC0(1, 10000.0f + avg);
            }
            fn_802A8F40(0);
        } else {
            FogBuf(3);
            if (flags & 0x4000) {
                fn_80296EEC(1, 3, 0);
            }
            DrawStateReapply();
            fn_8028A418(v, n, a);
            fn_80296EEC(1, 3, 1);
            fn_802A8F40(1);
            if (lbl_80347256 < 0x400 && lbl_80347218 > lbl_80347258 && lbl_80347208 != 0 && lbl_8034720C != 0) {
                fn_801D0BC0(8, 10000.0f + avg);
            }
            fn_802A8F40(0);
        }
    } else {
        DrawStateReapply();
        fn_8028A418(v, n, a);
    }
}

void* fn_801CB12C(u16* p) {
    s32 c;
    u16* q;
    u16* next;
    s32 r;
    if (p == 0) return 0;
    q = p;
    do {
        c = (u8)q[1];
        next = q + 2;
        r = fn_801CB0A4(c);
        if (r >= 0) return q;
        q = (u16*)((u8*)next + ((u16)r << 2));
    } while (c != 0xff);
    return 0;
}

void fn_801CBB9C(f32 f) {
    lbl_80347514 = f;
    lbl_80347518 = 0;
}

void fn_801CBBAC(f32 f) {
    lbl_80347514 = f;
    lbl_80347518 = 1;
}

void fn_801CC608(AkFio* f, void* buf, u32 size) {
    f->buf = buf;
    fn_801C6C7C(f);
}

s32 fn_801CB380(f32* dst_, Hdr* src_, s32 max) {
    s32 type;
    s32 size;
    s32 cnt;
    Hdr* src;
    f32* dst;
    f32* in;
    s32 i;
    s32 n;
    f32* q;
    if (src_ == NULL || max == 0) {
        return 0;
    }
    dst = dst_;
    src = src_;
    i = 0;
    do {
        size = src->size;
        type = src->type & 0xff;
        in = (f32*)(src + 1);
        src = (Hdr*)in;
        n = fn_801CB0A4(type);
        if (n >= 0) {
            cnt = ((Cnt*)in)->cnt;
            in += 1;
        } else {
            size = n & 0xffff;
        }
        if (n > 0) {
            q = in;
            do {
                dst[0] = q[0];
                dst[1] = q[1];
                dst[2] = q[2];
                q += n;
                dst += 3;
                if (--cnt <= 0) break;
                i++;
            } while (i < max);
        }
        src += size;
        if (type == 0xff) break;
    } while (i < max);
    return i;
}

FioName* fn_801CC1B4(const char* name)
{
    FioName* n = fn_801E1BDC(strlen(name) + 9);
    FioReq* req;
    FioReq** pp;
    if (n == 0) {
        fn_801DBE1C("Fio Auto Error (memory allocate): %s", name);
    }
    n->str = (char*)n + 8;
    strcpy(n->str, name);
    n->w4 = 0;
    req = fn_801E1BDC(0x34);
    if (req == 0) {
        fn_801DBE1C("s_FioReadReq Error (memory allocate)");
    }
    req->w00 = 0;
    req->fio = 0;
    req->out.addr = 0;
    req->w18 = 0;
    req->out.own = 0;
    req->w10 = 0;
    req->w1c = 0;
    req->state = 0;
    req->cancel = 0;
    req->name = n;
    req->cb = 0;
    req->cbArg = 0;
    req->next = 0;
    pp = &lbl_80347200;
    for (;;) {
        FioReq* t = *pp;
        if (t == 0) break;
        pp = &t->next;
    }
    *pp = req;
    return n;
}

void fn_801CAF30(void) {
    u32 i;
    for (i = 0; i < 0x356; i++) {
        lbl_80310B3C[i] = 0;
    }
    for (i = 0; i < 0x120; i++) {
        lbl_80310A1C[i] = 0;
    }
}

s32 fn_801CB0A4(s32 c) {
    switch (c) {
    case 0x22: return 3;
    case 0x23: case 0x24: case 0x25: case 0x26: case 0x27: case 0x28: return 4;
    case 0x29: return 6;
    case 0x2a: case 0x2b: case 0x2c: case 0x2d: case 0x2e: case 0x2f: return 7;
    case 0x30: return 4;
    case 0x31: case 0x32: return 5;
    case 0x0: case 0xff: return 0x80000000;
    default: return 0;
    }
}

void fn_801CAE98(void) {
    int i;
    for (i = 0x3a; i < 0x40; i++) {
        lbl_80310B3C[i] = 0;
    }
    for (i = 0x80; i < 0x11f; i++) {
        lbl_80310A1C[i] = 0;
    }
}

s32 fn_801CB1AC(u16* p) {
    s32 c;
    s32 lo;
    s32 n;
    s32 r;
    u32 w;
    u16* q;
    s32 sum;
    if (p == 0) return 0;
    lo = 0;
    sum = 0;
    do {
        q = p + 2;
        n = p[0];
        c = (u8)p[1];
        r = fn_801CB0A4(c);
        if (r >= 0) {
            w = q[0];
        }
        if (!(lo <= r)) {
            n = r & 0xffff;
        }
        if (r > 0) {
            sum += w;
        }
        p = q + n * 2;
    } while (c != 0xff);
    return sum;
}

s16 *fn_801CB6A0(s16 *p, s16 want)
{
    u8 c;
    s32 r;
    s32 step;
    if (p == NULL) {
        return NULL;
    }
    do {
        c = (u8)*p;
        if (want == c) {
            return p;
        }
        p++;
        r = fn_801CB460(c);
        if (r >= 0) {
            step = *p;
            p++;
        } else {
            step = (u16)r;
        }
        p = (s16 *)((u8 *)p + (step << 1));
    } while ((s32)c != 0xff);
    return NULL;
}

s32 fn_801CB244(Vec3* out, u16* p, s32 max) {
    u32 size;
    u16* next;
    Vec3* v;
    s32 r;
    s32 i;
    s32 c;
    s32 cnt;
    u16* cur;
    Vec3* dst;
    s32 n;
    if (p == 0 || max == 0) return 0;
    dst = out;
    cur = p;
    n = 0;
    do {
        size = cur[0];
        c = (u8)cur[1];
        next = cur + 2;
        cur = next;
        r = fn_801CB0A4(c);
        if (r >= 0) {
            cnt = *next;
            next += 2;
        } else {
            size = r & 0xffff;
        }
        if (r > 0) {
            v = (Vec3*)next;
            do {
                for (i = 0; i < n; i++) {
                    Vec3* o = &out[i];
                    if (o->i[0] == v->i[0] && o->i[1] == v->i[1] && o->i[2] == v->i[2]) break;
                }
                if (i == n) {
                    dst->f[0] = v->f[0];
                    dst->f[1] = v->f[1];
                    dst->f[2] = v->f[2];
                    n++;
                    dst++;
                }
                cnt--;
                v = (Vec3*)((u16*)v + r * 2);
            } while (cnt > 0 && n < max);
        }
        cur += size * 2;
    } while (c != 0xff && n < max);
    return n;
}

void fn_801CC434(char* path, char* dir, char* name) {
    s32 i;
    s32 ok = 1;
    char* p;
    s32 n;
    if (path == 0 || *path == 0) return;
    do {
        p = fn_8025ED74(path, "\\");
        if (p == 0) {
            ok = 0;
        } else {
            *p = '/';
        }
    } while (ok != 0);
    if (name != 0) {
        for (i = strlen(path) - 1; i >= 0; i--) {
            if (path[i] == '/') break;
        }
        if (i < 0) {
            strcpy(name, path);
        } else {
            strcpy(name, &path[i + 1]);
            fn_801E0D0C(name);
        }
    }
    if (dir != 0) {
        *dir = 0;
        if (i >= 0) {
            strncpy(dir, path, i + 1);
            dir[i + 1] = 0;
        }
        fn_801E0D0C(dir);
        n = strlen(dir);
        if (n > 1) {
            p = &dir[n - 1];
            if (*p == '/') *p = 0;
        }
    }
}

void fn_801CBC30(void) {
    if (lbl_803475CC == 6 || lbl_803475CC == 7) {
        lbl_80347500 = 0;
        lbl_803474F4 = 0;
        lbl_803471F4 = 0.0f;
        lbl_803471F0 = 30.0f;
        fn_802267AC(lbl_803475A0, fn_801CB744);
    }
    fn_801CBC90();
}

void fn_801CBC90(void) {
    f32 z = fn_801DBD9C(-1.0f);
    lbl_80347514 = 30.0f;
    lbl_80347518 = 1;
    lbl_80347510 = 1.0f;
    lbl_80347508 = 0;
    lbl_803471F8 = 0;
    lbl_8034750C = 0xff000000;
    lbl_80308C78[0].x = 0.0f;
    lbl_80308C78[0].y = 0.0f;
    lbl_80308C78[0].z = z;
    lbl_80308C78[0].col = lbl_8034750C;
    lbl_80308C78[1].x = 0.0f;
    lbl_80308C78[1].y = 480.0f;
    lbl_80308C78[1].z = z;
    lbl_80308C78[1].col = lbl_8034750C;
    lbl_80308C78[2].x = 640.0f;
    lbl_80308C78[2].y = 0.0f;
    lbl_80308C78[2].z = z;
    lbl_80308C78[2].col = lbl_8034750C;
    lbl_80308C78[3].x = 640.0f;
    lbl_80308C78[3].y = 480.0f;
    lbl_80308C78[3].z = z;
    lbl_80308C78[3].col = lbl_8034750C;
    lbl_803474F8 = 0;
    fn_802267AC(lbl_803475A0, fn_801CBA98);
}

void* fn_801CC3C4(const char* name) {
    AkFio* o = fn_801C64DC(name);
    void* r;
    if (o == 0) {
        return 0;
    }
    r = fn_801E1C7C(o->size);
    if (r == 0) {
        return 0;
    }
    o->buf = r;
    fn_801C6C7C(o);
    fn_801C6384(o);
    return r;
}

/* Returns 2 once the task reaches state 4, else 1. */
s32 fn_801CBD48(FioReq *s) {
    s32 done = 0;
    AkFio *p;
    if (s->cancel == 1) {
        s->state = 4;
    }
    p = s->fio;
    if (p != 0) {
        p->prio = 5;
    }
    switch (s->state) {
    case 0:
        p->x4c = &s->out;
        s->state = 2;
        break;
    case 2:
        if (FioResult(p) == 2) {
            s->w10 = -1;
            s->state = 4;
        }
        break;
    case 4:
        done = 1;
        break;
    }
    if (done) {
        return 2;
    }
    return 1;
}

s32 fn_801CBE38(void) {
    while (lbl_80347200 != 0) {
        FioReq **pp;
        s32 r;
        {
            FioReq *h = lbl_80347200;
            pp = 0;
            if (h != 0) {
                FioReq *c;
                FioReq **link = &h->next;
                pp = &lbl_80347200;
                while ((c = *link) != 0) {
                    s32 a = (*pp)->fio != 0 ? (*pp)->fio->prio : 1;
                    s32 b = c->fio != 0 ? c->fio->prio : 1;
                    if (a < b) {
                        pp = link;
                    }
                    link = &c->next;
                }
            }
        }
        if ((*pp)->name != 0 && (*pp)->fio == 0 && (*pp)->w10 != -1) {
            (*pp)->out.addr = 0;
            (*pp)->fio = fn_801C63EC((*pp)->name->str);
            (*pp)->fio->prio0 = 1;
            (*pp)->fio->prio = 1;
        }
        r = fn_801CBD48(*pp);
        if (r == 1) {
            s32 v = (*pp)->fio->size;
            (*pp)->w10 = v;
            (*pp)->w1c = v;
            v = (*pp)->out.addr;
            (*pp)->name->w4 = v;
            (*pp)->w18 = v;
            return 4;
        }
        if ((*pp)->fio != 0) {
            (*pp)->fio->prio = (*pp)->fio->prio0;
        }
        if ((*pp)->cb != 0 && (*pp)->cancel == 0 && r != -1) {
            FioCb io;
            io.name = (*pp)->name != 0 ? (*pp)->name->str : 0;
            io.addr = (*pp)->w18;
            io.size = (*pp)->w1c;
            (*pp)->cb((*pp)->cbArg, &io);
            {
                s32 v = io.addr;
                (*pp)->w18 = v;
                (*pp)->name->w4 = v;
            }
            (*pp)->w1c = io.size;
        }
        if ((*pp)->name != 0) {
            (*pp)->name->str = 0;
            if ((*pp)->fio != (AkFio *)(*pp)->name && (*pp)->fio != 0) {
                fn_801C6384((*pp)->fio);
                (*pp)->fio = 0;
            }
        }
        if ((*pp)->out.own != 0) {
            fn_801E1718((void *)(*pp)->out.addr);
        }
        {
            FioReq *dead = *pp;
            fn_801E1718(dead);
            *pp = dead->next;
        }
    }
    return 3;
}

s16* fn_801CB5F4(s16* p, s16 lo, s16 hi) {
    s32 c;
    s32 n;
    s32 stride;
    if (p == NULL) {
        return NULL;
    }
    do {
        c = p[0] & 0xFF;
        if (lo <= c && hi >= c) {
            return p;
        }
        p++;
        stride = fn_801CB460(c);
        if (stride >= 0) {
            n = p[0];
            p++;
        } else {
            n = (u16)stride;
        }
        p += n;
    } while (c != 0xFF);
    return NULL;
}
