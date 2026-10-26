#include "types.h"
#include "game/util.h"
#include "ninja.h"

extern void fn_80117748(void);
extern void fn_80114C84(void *a, void *b, void *c, void *d, void *e, void *f);
extern void fn_80114A44(void);
extern void fn_80114AB8(void);
extern s32 lbl_80346E80;
extern s32 fn_801161B4(void);
extern u8 lbl_802E54B0[];
typedef struct {
    u8 pad0[0x2c];
    f32 f2c; /* 0x2C */
    u8 pad30[0xa4 - 0x30];
} Entry;
typedef struct {
    s32 type;   /* 0x00 */
    void *ptr;  /* 0x04 */
    f32 a;      /* 0x08 */
    f32 b;      /* 0x0C */
    f32 c;      /* 0x10 */
    f32 d;      /* 0x14 */
    f32 e;      /* 0x18 */
    f32 f;      /* 0x1C */
} Req;
extern Req lbl_8030A380;
extern f32 lbl_80349E90;
extern void fn_80109E7C(const char *s, s32 n);
extern char lbl_802B31A8[];
extern void *lbl_80346EB0;
extern void *lbl_80346EB4;
extern s32 lbl_803473B4;
extern s32 lbl_803473B0;
extern s32 TaskDelete(void *task);
extern void *lbl_80346EC0;
extern void fn_8014FA10(void *p);
extern u8 *lbl_803472A8;
extern u8 *lbl_803472CC;
extern f32 lbl_8034A398;
extern f32 lbl_803472DC;
extern f32 lbl_8034A380;
extern f32 lbl_8034A3A4;
extern f32 lbl_803472E0;
extern f32 lbl_80346EE4;
extern u8 lbl_80311AC0[];
void fn_802238E4(void *dst, void *src, s32 n);
s32 fn_802254A0(s32 a);
void fn_80123CBC(void);
void *fn_802267AC(void *a, void *b);
void *fn_801E1C7C(s32 size);
extern void *lbl_803475A0;
extern u8 lbl_80310A1C[0x120];
void fn_801248C4(s32 a, u8 *obj, s32 flag);
void fn_8020EFD4(s32 v);
void fn_80156C6C(NJS_MATRIX m, void *a);
void fn_8014F99C(void *b, NJS_MATRIX m);
void fn_8014FA10(void *m);
void fn_80127BC0(void *self);
s32 fn_801CC5BC(void *a);
void fn_801CC65C(void *a);
void fn_80218D84(void *a, s32 b, s32 c);
extern void *lbl_80346ED8;
extern s32 lbl_80346ED4;
extern s32 lbl_80346ED0;
extern u8 lbl_80305F60[0x20];
void fn_8012C060(void);
void fn_80133144(void);
void fn_801323F0(void);
void fn_801316CC(void);
void fn_80130368(void);
void fn_8012F744(void);
void fn_8012F490(void);
void fn_8012E5D8(void);
void fn_8012C660(void);
void fn_8012AEE8(void);
void fn_8012AA8C(void);
void fn_80156DA0(void *a, void *b);
void fn_80156E54(void *a, void *b);
void fn_801E5148(void *a, void *b);
void fn_801E5DF0(void *a, void *b);
extern u8 lbl_80311970[];
extern s32 fn_8010E270(u8 *obj, u32 v);
extern void fn_801E7414(s32 id, u8 *obj);
extern void fn_801189F0(u8 *obj);
extern s32 lbl_80346E68;
extern u8 lbl_80311A60[];
extern void SePlay(s32 a, s8 id, s8 vol);
extern s32 lbl_80347404;
extern void fn_80222838(void *p);
extern void fn_80117BE4(s32 a, void *self, void *out);
extern s32 lbl_80347440;
extern s32 lbl_80347444;
extern f32 lbl_80349EDC, lbl_80349EA4, lbl_80349E18;
extern f32 fn_80090EEC(void *p, f32 v);
extern void fn_801E17E0(void *p);
extern void *memset(void *s, int c, unsigned long n);
extern void *lbl_803472A4;
typedef struct Fn80129560Obj {
    u8 pad0[0x19];
    u8 state;
    u8 pad1[0x0a];
    void *inner;
} Fn80129560Obj;
extern void fn_8015ED90(Fn80129560Obj *);
extern void fn_8015E600(void *);
extern void fn_8015EBF4(void *);
extern void fn_80100B74(Fn80129560Obj *);
typedef struct Fn80129750Inner {
    u8 pad0[0x38];
    f32 pos[3];
    Angle ang[3];
    f32 scale[3];
    u8 pad1[0xb4 - 0x5c];
    f32 pos2[3];
    u8 pad2[0x16c - 0xc0];
    s16 f16c;
    s16 f16e;
} Fn80129750Inner;
typedef struct Fn80129750Obj {
    u8 pad0[0x24];
    Fn80129750Inner *inner;
} Fn80129750Obj;
extern void fn_801E6EC0(NJS_MATRIX m, s32 a, s32 b, s32 c, s32 d);
extern void fn_801E6DD4(NJS_MATRIX m, Fn80129750Inner *in);
typedef struct Fn801298E8Rec {
    u8 pad0[0x8];
    s32 f8;
} Fn801298E8Rec;
extern s32 lbl_803472C0;
extern s32 lbl_803472D0;
typedef struct Fn80129BD4Item {
    u8 pad0[0x4];
    s32 f4;
    u8 pad1[0x18];
    s32 f20;
    u8 pad2[0x58 - 0x24];
} Fn80129BD4Item;
typedef struct Fn80129BD4Head {
    s32 count;
    s32 f4;
    Fn80129BD4Item *items;
} Fn80129BD4Head;
extern s32 lbl_803472B4;
extern s32 lbl_803472AC;
typedef struct Fn80129CA8Mid {
    u8 pad0[0x24];
} Fn80129CA8Mid;
typedef struct Fn80129CA8Inner {
    u8 pad0[0x17a];
    u16 f17a;
    u8 pad1[0x1c8 - 0x17c];
    Fn80129CA8Mid *mid;
} Fn80129CA8Inner;
extern u8 lbl_802B3388[];
extern void fn_8025F120(void *, void *);
extern s32 fn_8025EF88(void *, const char *);
extern void fn_8015757C(void *, u16);
typedef struct Fn80129D40Inner {
    u8 pad0[0x17a];
    u16 f17a;
} Fn80129D40Inner;
typedef struct Fn80129D40Obj {
    u8 pad0[0x24];
    Fn80129D40Inner *inner;
} Fn80129D40Obj;
typedef struct Fn80129D40Entry {
    Fn80129D40Obj *obj;
    s32 a;
    s32 b;
    s32 c;
    s32 d;
} Fn80129D40Entry;
extern s32 lbl_803472B0;
extern s32 lbl_8034729C;
extern Fn80129D40Entry lbl_80308EF8[];
extern char lbl_802B33EC[];
extern void fn_801DBE1C(const char *, ...);

void fn_8010E164(u8 *obj) {
    if (obj[0x19] == 0xff) {
        fn_80117748();
    }
}

void fn_801150DC(void *a, void *b, void *c, void *d) {
    fn_80114C84(a, b, c, d, fn_80114A44, fn_80114AB8);
}

void fn_80116020(s32 n) {
    lbl_80346E80 = n;
}

f32 fn_80116028(void) {
    s32 i = fn_801161B4();
    return ((Entry *)lbl_802E54B0)[i].f2c;
}

void fn_801165C4(u8 *self) {
    fn_802238E4(self + 0x38, self + 0x38, *(s32 *)(self + 0x1b8));
    MemCopy(self + 0x104, self + 0x38, 0x24);
}

s32 fn_8011698C(s32 a, u8 *obj) {
    s32 r = fn_802254A0(a);
    if (r == 1 && (*(u16 *)(obj + 0x24) & 0x4800) == 0x4800) {
        r = 0;
    }
    return r;
}

void fn_80118540(void) {
    f32 big = 3.4028235e38f;
    s32 mx = 0x80000000;
    mx -= 1;
    lbl_8030A380.type = 0;
    lbl_8030A380.ptr = (void *)mx;
    lbl_8030A380.a = big;
    lbl_8030A380.b = big;
    lbl_8030A380.c = big;
    lbl_8030A380.d = big;
    lbl_8030A380.e = big;
    lbl_8030A380.f = big;
}

void fn_80118578(void *ptr, f32 f1, f32 f2, f32 f3, f32 f4) {
    lbl_8030A380.type = 1;
    lbl_8030A380.ptr = ptr;
    lbl_8030A380.a = f1;
    lbl_8030A380.b = f2;
    lbl_8030A380.c = f3;
    lbl_8030A380.d = lbl_80349E90;
    lbl_8030A380.e = f4;
    lbl_8030A380.f = lbl_80349E90;
}

void fn_801185A8(void *ptr, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5, f32 f6) {
    lbl_8030A380.type = 2;
    lbl_8030A380.ptr = ptr;
    lbl_8030A380.a = f1;
    lbl_8030A380.b = f2;
    lbl_8030A380.c = f3;
    lbl_8030A380.d = f4;
    lbl_8030A380.e = f5;
    lbl_8030A380.f = f6;
}

void fn_8011A2A8(void) {
    fn_80109E7C(lbl_802B31A8, 0x7fff);
}

void fn_8011B238(s32 a, ...) {
}

void fn_8011BAA4(u8 *p) {
    lbl_80346EB0 = p;
    if (!(p[0x18] & 0x20)) {
        return;
    }
    lbl_80346EB4 = 0;
    lbl_80346EB0 = 0;
    p[0x18] |= 0x40;
}

void fn_80120A50(f32 *out, const f32 *a, const f32 *b, f32 t) {
    f32 az = a[2];
    f32 bz = b[2];
    f32 ax = a[0];
    f32 ay = a[1];
    f32 by = b[1];
    f32 bx = b[0];
    out[2] = az + t * (bz - az);
    out[1] = ay + t * (by - ay);
    out[0] = ax + t * (bx - ax);
}

void fn_80123E8C(void) {
    lbl_803473B4 = 1;
    lbl_803473B0 = 1;
}

void fn_80123E9C(void) {
    lbl_803473B4 = 1;
    lbl_803473B0 = 0;
}

void fn_80123EB0(void) {
    if (lbl_80346EC0 != 0) {
        TaskDelete(lbl_80346EC0);
    }
    lbl_80346EC0 = 0;
}

void fn_80123EE4(void) {
    lbl_803473B4 = 0;
    lbl_803473B0 = 0;
    lbl_80346EC0 = fn_802267AC(lbl_803475A0, fn_80123CBC);
    *(void **)((u8 *)lbl_80346EC0 + 0x24) = fn_801E1C7C(0x20);
}

void fn_80124390(u8 *p) {
    u8 *src = *(u8 **)(*(u8 **)(p + 0x1d8) + 0x8);
    MemCopy(p + 0x38, src + 0x38, 0x24);
}

void fn_801243C4(u8 *p) {
    fn_8014FA10(*(u8 **)(p + 0x23c) + 0xf0);
}

s32 fn_801243EC(s32 a) {
    if (a == 0x1c) {
        return 1;
    }
    if (a == 0x1d) {
        if ((s8)lbl_80310A1C[0xc0] == 0) {
            return 2;
        }
    }
    return 0;
}

void fn_80124870(s32 a, u8 *obj) {
    switch (obj[4]) {
    case 0x18:
        fn_801248C4(a, obj, 1);
        if (*(s16 *)(obj + 0x34) == 1) {
            fn_8020EFD4(0x74cc);
        }
        break;
    }
}

void fn_80126408(void *a, void *b) {
    NJS_MATRIX m;
    njUnitMatrix(m);
    fn_80156C6C(m, a);
    fn_8014F99C(b, m);
}

void fn_8012645C(u8 *self) {
    u8 *p = *(u8 **)(self + 0x23c);
    if (p != 0) {
        fn_8014FA10((u8 *)*(void **)(p + 4) + 0x80);
        fn_80127BC0(self);
    }
}

void fn_80126E1C(u8 *p, u8 v) {
    p[7] = v;
}

s32 fn_80128F2C(void) {
    s32 r;
    if (fn_801CC5BC(lbl_80346ED8) != 2) {
        r = 0;
    } else {
        fn_801CC65C(lbl_80346ED8);
        fn_80218D84(lbl_80305F60, lbl_80346ED4, lbl_80346ED0);
        r = 1;
    }
    return r;
}

void *fn_801298CC(void) {
    u8 *inner = *(u8 **)(lbl_803472A8 + 0x8);
    return lbl_803472CC + (*(u16 *)(inner + 0x46) << 2);
}

void fn_80129988(void) {
    lbl_803472DC = lbl_8034A398;
}

void fn_801299A0(void) {
    lbl_803472E0 = lbl_8034A380;
    lbl_80346EE4 = lbl_8034A3A4;
}

s32 fn_8012A8DC(void) {
    s32 v = *(s32 *)(lbl_80311AC0 + 0x4);
    return v >= 500;
}

void fn_8012A9FC(void) {
    fn_8012C060();
    fn_80133144();
    fn_801323F0();
    fn_801316CC();
    fn_80130368();
    fn_8012F744();
    fn_8012F490();
    fn_8012E5D8();
    fn_8012C660();
    fn_8012AEE8();
    fn_8012AA8C();
}

void fn_80124C68(void *p3, void **pp) {
    u8 *o = (u8 *)*pp;
    if (*(u32 *)(o + 0x24) & 0x2000) {
        s32 v = *(s32 *)o;
        u8 *in = *(u8 **)(o + 0x13c);
        if (v == 0) {
            return;
        }
        if (*(u32 *)((u8 *)p3 + 0xe8) != 0) {
            fn_80156E54(p3, in);
        } else {
            fn_80156DA0(p3, in);
        }
    } else {
        if (*(s32 *)o != 0) {
            if (*(s8 *)(o + 7) != 0) {
                fn_801E5148(p3, o);
            } else {
                fn_801E5DF0(p3, o);
            }
        }
    }
}

void fn_80126F0C(void *a, void *b) {
    u8 *pa = (u8 *)a;
    u8 *pb = (u8 *)b;
    if (*(u32 *)(pb + 0x24) & 0x400) {
        return;
    }
    *(f32 *)(pb + 0x38) = *(f32 *)(pa + 0x38);
    *(f32 *)(pb + 0x3c) = *(f32 *)(pa + 0x3c);
    *(f32 *)(pb + 0x40) = *(f32 *)(pa + 0x40);
    if (!(*(u32 *)(pb + 0x24) & 0x80)) {
        *(u32 *)(pb + 0x44) = *(u32 *)(pa + 0x44);
    }
    if (!(*(u32 *)(pb + 0x24) & 0x100)) {
        *(u32 *)(pb + 0x48) = *(u32 *)(pa + 0x48);
    }
    if (!(*(u32 *)(pb + 0x24) & 0x200)) {
        *(u32 *)(pb + 0x4c) = *(u32 *)(pa + 0x4c);
    }
}

void fn_801119D4(u8 *obj) {
    s32 r;

    *(f32 *)(obj + 0x190) = 1.0f;
    fn_801189F0(obj);
    switch (*(u16 *)(obj + 0x172)) {
    case 0:
        r = fn_8010E270(obj, *(u32 *)(lbl_80311970 + 0x20));
        if (r == 0) {
            fn_801E7414(0x2b, obj);
            *(u16 *)(obj + 0x170) = 0x11;
            *(u16 *)(obj + 0x172) = 0;
        } else if (r == 2) {
            fn_801E7414(0x2a, obj);
            *(u16 *)(obj + 0x170) = 0x12;
            *(u16 *)(obj + 0x172) = 0;
        }
        break;
    }
}

void fn_8011356C(u8 *obj) {
    s16 r;

    *(f32 *)(obj + 0x190) = 1.0f;
    fn_801189F0(obj);
    if (lbl_80346E68 == 0) {
        r = *(s16 *)(*(u8 **)lbl_80311A60 + 0x16);
        if (r > 0) {
            fn_801E7414(0x1c, obj);
            SePlay(0xf, 5, 0x1b);
            *(u16 *)(obj + 0x170) = 7;
            *(u16 *)(obj + 0x172) = 0;
        } else if (r < 0) {
            fn_801E7414(0x1b, obj);
            SePlay(0xf, 5, 0x1b);
            *(u16 *)(obj + 0x170) = 7;
            *(u16 *)(obj + 0x172) = 0;
        }
    }
    lbl_80346E68 = 0;
}

void fn_8011816C(u8 *self, u8 *out) {
    u8 **o = (u8 **)out;
    if (lbl_80347404 == 0) {
        o[6] = self + 0x38;
        o[8] = self + 0x44;
        o[9] = 0;
        o[10] = 0;
    } else {
        o[6] = self + 0x38;
        o[8] = self + 0x44;
        o[9] = self + 0xb4;
        o[10] = self + 0xc0;
    }
    fn_80222838(out);
    fn_80117BE4(0, self, out);
}

void fn_80119A28(u8 *p) {
    s32 n;
    f32 v;
    if (lbl_80347440 == 0) {
        return;
    }
    n = fn_801161B4();
    v = fn_80090EEC(p, *(f32 *)(lbl_802E54B0 + n * 0xa4 + 0x2c));
    n = lbl_80347440;
    if (n == 1) {
        if (v < lbl_80349EDC) {
            *(f32 *)(p + 0x1c) = lbl_80349EA4;
        } else {
            *(f32 *)(p + 0x1c) = lbl_80349E18;
        }
        return;
    }
    if (n < 2) {
        return;
    }
    if (v >= lbl_80349EDC) {
        goto reset;
    }
    {
        s32 m = n + 1;
        lbl_80347440 = m;
        if (m < 10) {
            goto ea4;
        }
    }
reset:
    *(f32 *)(p + 0x1c) = lbl_80349E18;
    lbl_80347444 = 0;
    lbl_80347440 = 0;
    return;
ea4:
    *(f32 *)(p + 0x1c) = lbl_80349EA4;
}

void fn_80125750(u8 *dst, u8 *src) {
    if (*(s32 *)(src + 0x24) & 0x80) {
        if (*(s32 *)(src + 0x44) >= 0x8000) {
            *(s32 *)(src + 0x44) -= 0x10000;
        }
        if (*(s32 *)(src + 0x44) <= -0x8000) {
            *(s32 *)(src + 0x44) += 0x10000;
        }
        *(s32 *)(dst + 0x44) = *(s32 *)(src + 0x44);
    }
    if (*(s32 *)(src + 0x24) & 0x100) {
        if (*(s32 *)(src + 0x48) >= 0x8000) {
            *(s32 *)(src + 0x48) -= 0x10000;
        }
        if (*(s32 *)(src + 0x48) <= -0x8000) {
            *(s32 *)(src + 0x48) += 0x10000;
        }
        *(s32 *)(dst + 0x48) = *(s32 *)(src + 0x48);
    }
    if (*(s32 *)(src + 0x24) & 0x200) {
        if (*(s32 *)(src + 0x4c) >= 0x8000) {
            *(s32 *)(src + 0x4c) -= 0x10000;
        }
        if (*(s32 *)(src + 0x4c) <= -0x8000) {
            *(s32 *)(src + 0x4c) += 0x10000;
        }
        *(s32 *)(dst + 0x4c) = *(s32 *)(src + 0x4c);
    }
}

void fn_80125C90(u8 *p) {
    if (p == 0) {
        return;
    }
    fn_801E17E0(*(void **)(p + 0x0));
    fn_801E17E0(*(void **)(p + 0x4));
    if (*(void **)(p + 0xc) != 0) {
        fn_801E17E0(*(void **)(p + 0xc));
    }
    if (*(u8 **)(p + 0x8) != 0) {
        u8 *q = *(u8 **)(p + 0x8);
        memset(q + 0x14, 0, 0x1c);
        memset(q + 0x4c, 0, 0x1c);
        memset(q + 0x30, 0, 0x1c);
        fn_801E17E0(q);
    }
    memset(p, 0, 0x10);
    fn_801E17E0(p);
}

void fn_801278F0(u8 *p, u8 *out) {
    if (*(s32 *)(p + 0x2e4) != 0) {
        *(s16 *)(p + 0x3c) += 1;
        if (*(s32 *)((u8 *)lbl_803472A4 + 0x4c) == 0) {
            s32 v = *(s32 *)(*(u8 **)(p + 0x8) + 0x24);
            *(s8 *)(out + 0x10) = -0x7f;
            out[0x11] = 0;
            if (v != 0) {
                out[0x16] = 1;
            }
        }
    }
    if (*(s32 *)(p + 0x2f0) == 0) {
        return;
    }
    *(s16 *)(p + 0x3e) += 1;
    if (*(s32 *)((u8 *)lbl_803472A4 + 0x4c) != 0) {
        return;
    }
    {
        s32 v = *(s32 *)(*(u8 **)(p + 0x8) + 0x24);
        *(s8 *)(out + 0x10) = -0x7e;
        out[0x11] = 0;
        if (v != 0) {
            out[0x16] = 1;
        }
    }
}

void fn_80129560(Fn80129560Obj *p) {
    switch (p->state) {
    case 0xfe:
    case 0x0:
        fn_8015ED90(p);
        p->state = 1;
        break;
    case 0x1:
        fn_8015E600(p->inner);
        break;
    case 0xff:
        fn_8015EBF4(p->inner);
        fn_80100B74(p);
        break;
    }
}

void fn_80129750(NJS_MATRIX m, Fn80129750Obj *o) {
    Fn80129750Inner *in;

    in = o->inner;
    if (in->f16c == 0) {
        njTranslate(m, in->pos[0], in->pos[1], in->pos[2]);
        fn_801E6EC0(m, in->f16e, in->ang[0], in->ang[1], in->ang[2]);
    } else {
        njTranslate(m, in->pos[0], in->pos[1], in->pos[2]);
        njRotateZXY(m, in->ang[0], in->ang[1], in->ang[2]);
        njTranslate(m, in->pos2[0], in->pos2[1], in->pos2[2]);
        fn_801E6DD4(m, in);
    }
    njScale(m, in->scale[0], in->scale[1], in->scale[2]);
}

s32 fn_801298E8(void) {
    if (lbl_803472E0 == 0.0f) {
        return (lbl_803472C0 % lbl_803472D0 == 0) + 1;
    }
    if (lbl_803472A8 != 0) {
        if (lbl_803472E0 == (f32)((Fn801298E8Rec *)lbl_803472A4)->f8) {
            return (lbl_803472C0 % lbl_803472D0 == 0) + 1;
        }
    }
    return 0;
}

void fn_80129BD4(void) {
    Fn80129BD4Head *h;
    s32 i;
    s32 sum;
    Fn80129BD4Item *p;

    h = (Fn80129BD4Head *)lbl_803472A8;
    if (lbl_803472E0 >= (f32)h->f4) {
        lbl_803472E0 = 0.0f;
        lbl_80346EE4 = -1.0f;
    }
    sum = 0;
    for (i = 0; i < h->count; i++) {
        sum += h->items[i].f4;
        if ((f32)sum > lbl_803472E0) {
            lbl_803472B4 = i;
            break;
        }
    }
    p = h->items + lbl_803472B4;
    lbl_803472A4 = p;
    lbl_803472AC = p->f20;
}

s32 fn_80129CA8(Fn80129CA8Inner *o) {
    u8 fi[0x38];
    char *base;

    base = (char *)lbl_802B3388;
    fn_8025F120(fi, (char *)o->mid + 0x24);
    fi[8] = 0;
    if (fn_8025EF88(fi, base + 0x7c) == 0) {
        return 0;
    }
    if (fn_8025EF88(fi, base + 0x58) == 0) {
        return 1;
    }
    fn_8015757C(base + 0x88, o->f17a);
    return 0;
}

Fn80129D40Entry *fn_80129D40(s32 id) {
    Fn80129D40Entry *found;
    s32 i;

    if (id == 0xffff) {
        id = lbl_803472B0;
    }
    found = 0;
    for (i = 0; i < lbl_8034729C; i++) {
        if (id == lbl_80308EF8[i].obj->inner->f17a) {
            found = &lbl_80308EF8[i];
        }
    }
    if (found == 0) {
        fn_801DBE1C(lbl_802B33EC, id);
    }
    return found;
}
