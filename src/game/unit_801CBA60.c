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
s32 fn_801C6BC8(void);
extern u32 lbl_80347518;
extern f32 lbl_80347510;
extern u32 lbl_80347508;
extern u32 lbl_80347504;
extern s32 fn_8023A4B0(void);
extern u32 lbl_803474F4;
s32 fn_801CB0A4(s32 c);
extern f32 lbl_80347514;
void fn_801C6C7C(void* p);
typedef struct { u16 size; u16 type; } Hdr;
typedef struct { u16 cnt; u16 pad; } Cnt;
typedef struct FioReq {
    s32 w00, w04, w08, w0c, w10, w14, w18, w1c, w20;
    char* name;
    s32 w28, w2c;
    struct FioReq* next;
} FioReq;
typedef struct { char* str; s32 w4; } FioName;
extern FioReq* lbl_80347200;
extern u32 strlen(const char*);
extern void* fn_801E1BDC(s32 size);
extern void fn_801DBE1C(const char*, ...);
extern void fn_8025F120(char*, const char*);
extern u32 lbl_80310B3C[0x356];
extern u8 lbl_80310A1C[0x120];

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
extern void fn_801CBC90(Msg*, s16);
extern u32 lbl_803471F8;
void fn_801CBBF8(void) {
    lbl_803471F8 = 1;
}

void fn_801CBC04(void) {
    lbl_803474F8 = 0;
}

void fn_801CBC10(Msg* a, s16 i) {
    fn_801CBC90(a, i);
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

extern void fn_801CBE38(Msg*, s16);
void fn_801CC3A4(Msg* a, s16 i) {
    fn_801CBE38(a, i);
}

extern void fn_8023AB28();
void fn_801CC578(Msg* a, s32 i) {
    fn_8023AB28(a, i);
}

extern char lbl_8034BD14;
void fn_801CC598(void) {
    fn_8023AB28(&lbl_8034BD14);

}

s32 fn_801CC5BC(void)
{
    s32 r = fn_801C6BC8();
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

extern void fn_801C6384(Msg*, s16);
void fn_801CC65C(Msg* a, s16 i) {
    fn_801C6384(a, i);
}

extern void fn_801C63EC(Msg*, s16);
void fn_801CC67C(Msg* a, s16 i) {
    fn_801C63EC(a, i);
}

extern void fn_801C64DC(Msg*, s16);
void fn_801CC69C(Msg* a, s16 i) {
    fn_801C64DC(a, i);
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

void fn_801CC608(u8* p, s32 v) {
    *(s32*)(p + 0x48) = v;
    fn_801C6C7C(p);
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
    fn_8025F120(n->str, name);
    n->w4 = 0;
    req = fn_801E1BDC(0x34);
    if (req == 0) {
        fn_801DBE1C("s_FioReadReq Error (memory allocate)");
    }
    req->w00 = 0;
    req->w04 = 0;
    req->w08 = 0;
    req->w18 = 0;
    req->w0c = 0;
    req->w10 = 0;
    req->w1c = 0;
    req->w14 = 0;
    req->w20 = 0;
    req->name = (char*)n;
    req->w28 = 0;
    req->w2c = 0;
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
