#include "types.h"
#include "game/util.h"
#include "ninja.h"
#include <stdarg.h>
#include "game/drawstate.h"

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
extern s32 lbl_80311AC0[5];
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
extern void SePlay(s32 a, s32 id, s32 vol);
extern s32 lbl_80347404;
extern void fn_80222838(void *p);
extern void fn_80117BE4(s32 a, void *self, void *out);
extern s32 lbl_80347440;
extern s32 lbl_80347444;
extern f32 lbl_80349EDC, lbl_80349EA4, lbl_80349E18;
extern f32 fn_80090EEC(void *p, f32 v);
extern void fn_801E17E0(void *p);
extern void *memset(void *s, int c, unsigned long n);
typedef struct {
    u8 pad0[4];
    s32 v4;
    s32 v8;
} Rec;
extern Rec *lbl_803472A4;
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
typedef struct {
    u8 pad00[0x28];
    u16 s28, s2a;
} Sub_801109AC;
typedef struct {
    u8 pad00[0x38];
    f32 x, y, z;            /* 0x38 */
    u8 pad44[0x174];
    Sub_801109AC* sub;               /* 0x1B8 */
} Obj_801109AC;
typedef struct {
    u8 pad00[0x24];
    u16 flags;      /* 0x24 */
} Sub_801185D4;
typedef struct {
    u8 pad00[0x170];
    u16 type;       /* 0x170 */
    u8 pad172[0x1A];
    f32 f18c;
    f32 f190;
    u8 pad194[8];
    s32 s19c;
    u8 pad1a0[0x18];
    Sub_801185D4* sub;       /* 0x1B8 */
} Obj_801185D4;
extern f32 lbl_802E5078[];
extern u8 lbl_80346798[8];
typedef struct {
    f32 v[3];   /* 0x00 */
    s32 w[3];   /* 0x0C */
} Out;
typedef struct {
    void* p0;
    void* p4;
} Inner;
typedef struct {
    u8 pad00[0x44];
    Angle rx, ry, rz;   /* 0x44 */
    f32 sx, sy, sz;     /* 0x50 */
} Src_80119744;
extern void njScale(f32* m, f32 x, f32 y, f32 z);
extern void njCalcVector(f32* m, NJS_VECTOR* v, NJS_VECTOR* out);
extern void fn_800071D8(Inner** h);
extern void fn_80007080(NJS_VECTOR* v, s32 a);
extern void fn_80006F1C(s32* w, s32 a);
extern s32 fn_8025CC04(char* buf, const char* fmt, va_list ap);
extern char* fn_8025EDDC(char* s, const char* delim);
extern char* strchr(const char* s, s32 c);
typedef struct {
    u32 flags;      /* 0x00 */
    s32 cur;        /* 0x04 */
    u8 pad08[4];
    s32 total;      /* 0x0C */
    f32 curve[4];   /* 0x10 */
    u8 pad20[8];
    f32 x0, y0, x1, y1;   /* 0x28 */
    f32 c38, c3c;   /* 0x38 */
    u8 pad40[0x10];
    f32 c50, c54;
    u8 pad58[0x10];
    f32 c68, c6c;
    u8 pad70[0x10];
    f32 c80, c84;
} Anim_8011B6E0;
extern void fn_8011B024(f32 t, f32* pts, s32 n, s32 deg, f32* out);
typedef struct {
    u8 pad00[0x50];
    f32 f50, f54, f58;
} Sub_8011F44C;
typedef struct {
    u32 flags;      /* 0x00 */
    u8 pad04[4];
    s32 state;      /* 0x08 */
    u8 pad0c[4];
    s32 frame;      /* 0x10 */
    u8 pad14[0x14];
    f32* curve;     /* 0x28 */
    u8 pad2c[0x14];
    Sub_8011F44C* sub;       /* 0x40 */
} Obj_8011F44C;
typedef struct {
    f32 m[16];
} Item;
typedef struct {
    u32 flags;      /* 0x00 */
    u8 pad04[0x14];
    s32 frame;      /* 0x18 */
    Item* items;    /* 0x1C */
    u8 pad20[4];
    s32 count;      /* 0x24 */
} Obj_8012092C;
extern void fn_801202C4(void* o);
extern void fn_8012061C(void* o);
extern void fn_8012048C(void* o);
extern void fn_8028A3E0(s32 a);
extern void fn_8028A2A8(Item* p, s32 a);
extern void fn_8028A2A4(void);
typedef struct {
    u8 a, b;
    u16 dur;
} Frame;
typedef struct {
    void* handle;   /* 0x00 */
    u32 timer;      /* 0x04 */
    u16 idx;        /* 0x08 */
    u8 pad0a[2];
    u32 loops;      /* 0x0C */
    u32 max_loops;  /* 0x10 */
    u8 s14[2];      /* 0x14 */
    u8 b16, b17;    /* 0x16 */
    u8 pad18[4];
    Frame frames[1]; /* 0x1C */
} Anim_80122778;
typedef struct {
    u8 pad00[0x18];
    u8 flags;       /* 0x18 */
    u8 pad19[0xB];
    Anim_80122778* anim;     /* 0x24 */
} Obj_80122778;
extern void fn_801D6CBC(void* h, void* p);
extern void fn_801D6C3C(void* h);
extern void fn_801E1784(void* p);
typedef struct {
    void* handle;   /* 0x00 */
    u32 timer;      /* 0x04 */
    u16 idx;        /* 0x08 */
    u16 count;      /* 0x0A */
    u32 loops;      /* 0x0C */
    s32 max_loops;  /* 0x10 */
    u8 b14, b15;    /* 0x14 */
    u8 b16, b17;    /* 0x16 */
    u8 b18;         /* 0x18 */
    u8 pad19[3];
    Frame frames[31]; /* 0x1C */
} Anim_80122A00;
typedef struct {
    s32 a, b, dur;
} SrcFrame;
typedef struct {
    void* handle;       /* 0x00 */
    SrcFrame* frames;   /* 0x04 */
    Anim_80122A00* anim;         /* 0x08 */
} Src_80122A00;
typedef struct {
    u8 pad00[0x24];
    Src_80122A00* src;       /* 0x24 */
    Anim_80122A00* anim;     /* 0x28 */
} Obj_80122A00;
extern void* lbl_80347588;
extern s32 fn_801D6E38(void* h);
extern void* fn_80226704(void* list, void (*cb)(void), s32 size);
extern void fn_80122D5C(void);
typedef struct {
    u8 pad0[0x10];
    s16 s10;
    u8 pad12[2];
    s16 s14;
    u8 pad16[0x20 - 0x16];
    s16 s20;
} In;
typedef struct {
    u8 pad0[0x12];
    u8 b12;
    u8 b13;
    u8 b14;
    u8 b15;
    u8 pad16;
    s8 b17;
    u8 pad18[0x24 - 0x18];
    u32 flags;
    u8 pad28[0x118 - 0x28];
    s8 tbl[8];
} Obj_80126014;
extern void fn_8014EF34(In *in);
extern void fn_801276E8(void *a, void*o);
extern void fn_80126118(void *a, void*o);
typedef struct {
    u8 b;
    u8 pad[0x13];
} Ent_801275E0;
typedef struct {
    u8 pad0[0x58];
    Ent_801275E0 e58[1];
    u8 pad59[0xc0 - 0x58 - 0x14];
    f32 f0c0;
} Sub_801275E0;
typedef struct {
    u8 pad0[5];
    s8 b5;
    s8 b6;
    u8 pad7[0x14 - 7];
    s8 b14;
    s8 b15;
    u8 pad16;
    s8 b17;
    u8 pad18[2];
    s16 s1a;
    u8 pad1c[0x6c - 0x1c];
    Sub_801275E0 sub;
} Obj_801275E0;
typedef struct {
    u8 pad0[4];
    u32 tick;
} Clock;
typedef struct {
    u8 pad0[0xe8];
    Clock *clock;
    u8 pade8[0x18c - 0xec];
    f32 f18c;
    f32 f190;
} Ctx_801275E0;
extern void fn_801275E0(Ctx_801275E0 *c, Obj_801275E0 *o);
typedef struct {
    u8 pad0[0x24];
    u32 flags;
    u8 pad28[0x44 - 0x28];
    s32 v44;
    s32 v48;
    s32 v4c;
    s32 v50;
    u8 pad54[0x60 - 0x54];
    s32 v60;
    s32 v64;
    s32 v68;
} Obj_80127E24;
typedef struct {
    u8 pad0[0x44];
    s32 v44;
    s32 v48;
    s32 v4c;
} Ctx_80127E24;
extern void fn_801264A4(void *p, s32 n, f32 f);
extern s32 fn_80126E24(void*c, f32 a, f32 b);
typedef struct {
    u8 id;
    u8 pad1;
    u8 a[6];
    u8 pad8[6];
} Ent_801284C0;
typedef struct {
    Ent_801284C0 e[4];
    u8 pad38[0xac - 0x38];
    u8 b_ac;
    u8 b_ad;
    u8 padae[2];
    f32 f_b0;
    f32 f_b4;
    u8 padb8[4];
    f32 f_bc;
    f32 f_c0;
    f32 f_c4;
} Tbl_801284C0;
typedef struct {
    u8 id;
    u8 pad1;
    u8 a[6];
    u8 pad8[6];
} Ent_80128A1C;
typedef struct {
    Ent_80128A1C e[4];
    u8 pad38[0xb0 - 0x38];
    f32 f_b0;
    f32 f_b4;
    u8 padb8[4];
    f32 f_bc;
    f32 f_c0;
    f32 f_c4;
} Tbl_80128A1C;
extern s32 lbl_80347290;
extern s32 lbl_80347294;
extern s32 lbl_803472D8;
extern void fn_80156250(void);
extern void fn_80144E5C(void);
typedef struct {
    u8 pad0[4];
    struct {
        u8 pad0[0x20];
        void *x20;
    } *x4;
} Obj_8012AA8C;
extern void *lbl_80346EFC;
extern void *lbl_80346F00;
extern void *lbl_80346F04;
extern void *lbl_80346F08;
extern Obj_8012AA8C *lbl_80346EF0;
extern Obj_8012AA8C *lbl_80346EF4;
extern Obj_8012AA8C *lbl_80346EF8;
extern void *lbl_80346F0C;
extern void fn_801D6944(void *p);
extern void fn_802275A4(void *p, s32 n);

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
    s32 v = lbl_80311AC0[1];
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
        if (lbl_803472E0 == (f32)(*(s32 *)((u8 *)lbl_803472A4 + 0x8))) {
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
    lbl_803472A4 = (Rec *)p;
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

s32 fn_801109AC(Angle ang, Obj_801109AC* o) {
    NJS_MATRIX m;
    NJS_POINT3 p, d;
    s32 ok;
    njUnitMatrix(m);
    njRotateXYZ(m, 0, ang, 0);
    p.x = 0.0f;
    p.y = 0.0f;
    p.z = 24.0f;
    njCalcPoint(m, &p, &d);
    p.x = o->x + d.x;
    p.y = 24.0f + (o->y + d.y);
    p.z = o->z + d.z;
    o->sub->s28 = 0xFFFF;
    o->sub->s2a = 0xFFFF;
    ok = 1;
    fn_8011698C((s32)&p, (u8 *)o->sub);
    if (1.0f + o->y < p.y) {
        ok = 0;
    }
    return ok;
}

void fn_801185D4(Obj_801185D4* o) {
    f32* p;
    f32* base;
    s32 i;
    u16 t = o->type;
    if (t == 2 || t == 0x17) {
        base = lbl_802E5078;
    } else if ((u16)(t - 3) <= 1 || t == 0x18 || t == 0x19) {
        base = lbl_802E5078 + 27;
    } else {
        return;
    }
    i = 0;
    p = base;
    do {
        if (p[0] <= o->f18c && o->f190 + p[0] > o->f18c && o->s19c == 1) {
            u16 k = (o->sub->flags >> 4) & 0xF;
            if (k >= 7) {
                k = 6;
            }
            SePlay(15, 5, lbl_80346798[k]);
        }
        i++;
        p++;
    } while (i < 2);
}

void fn_80119744(Out* out, Src_80119744* a, Inner** h) {
    NJS_VECTOR v;
    NJS_MATRIX m;
    Inner* in;
    if (h == NULL) {
        out->v[0] = 0.0f;
        out->v[1] = 0.0f;
        out->v[2] = 0.0f;
        out->w[0] = 0;
        out->w[1] = 0;
        out->w[2] = 0;
        return;
    }
    fn_800071D8(h);
    in = *h;
    if (in->p0 != NULL) {
        fn_80007080(&v, 1);
        njUnitMatrix(m);
        njRotateXYZ(m, a->rx, a->ry, a->rz);
        njScale(m, a->sx, a->sy, a->sz);
        njCalcVector(m, &v, (NJS_VECTOR*)out);
    } else {
        out->v[0] = 0.0f;
        out->v[1] = 0.0f;
        out->v[2] = 0.0f;
    }
    if (in->p4 != NULL) {
        fn_80006F1C(out->w, 1);
    } else {
        out->w[0] = 0;
        out->w[1] = 0;
        out->w[2] = 0;
    }
}

s32 fn_8011B128(s32 unused, const char* fmt, ...) {
    va_list ap;
    char buf[256];
    s32 n;
    char* p;
    if (fmt != NULL && *fmt != 0) {
        va_start(ap, fmt);
        n = fn_8025CC04(buf, fmt, ap);
        p = strchr(fn_8025EDDC(buf, "\n"), '\r');
        if (p != NULL) {
            *p = 0;
        }
        while ((p = fn_8025EDDC(NULL, "\n")) != NULL) {
            p = strchr(p, '\r');
            if (p != NULL) {
                *p = 0;
            }
        }
        return n;
    }
    return 0;
}

void fn_8011B6E0(Anim_8011B6E0* a) {
    f32 t = (f32)a->cur / (f32)a->total;
    f32 v;
    f32 dx, dy;
    if (a->flags & 0x200) {
        fn_8011B024(t, a->curve, 4, 3, &v);
        t = 0.01f * v;
    }
    dx = 640.0f * t;
    dy = 480.0f * t;
    if (a->flags & 0x1000000) {
        a->x0 = -dx;
        a->x1 = 640.0f - dx;
    } else if (a->flags & 0x2000000) {
        a->x0 = dx;
        a->x1 = 640.0f + dx;
    }
    if (a->flags & 0x4000000) {
        a->y0 = -dy;
        a->y1 = 480.0f - dy;
    } else if (a->flags & 0x8000000) {
        a->y0 = dy;
        a->y1 = 480.0f + dy;
    }
    a->c38 = a->c50 = a->x0;
    a->c3c = a->c6c = a->y0;
    a->c68 = a->c80 = a->x1;
    a->c54 = a->c84 = a->y1;
}

void fn_8011F44C(Obj_8011F44C* o) {
    Sub_8011F44C* sub = o->sub;
    f32 t;
    f32 v;
    f32 tmp;
    if (o->state < 0) {
        t = 0.0f;
    } else {
        t = (f32)o->frame / 15.0f;
        if (o->flags & 0x100) {
            fn_8011B024(t, o->curve, 5, 3, &tmp);
            v = 0.01f * (0.8f * tmp);
        } else {
            v = 0.0f;
        }
    }
    sub->f50 = v;
    sub->f54 = 0.5f * t + v;
    sub->f58 = v;
    if (o->state >= 0) {
        if (++o->frame >= 15) {
            o->frame = 0;
            o->flags |= 8;
            o->flags &= ~4;
        }
    }
}

void fn_8012092C(Obj_8012092C* o) {
    DrawState st;
    Item* p;
    s32 n;
    s32 i;
    if (o->frame != 0) {
        fn_801202C4(o);
    } else {
        fn_8012061C(o);
    }
    fn_8012048C(o);
    if (o->flags & 0x80000) {
        DrawStateDefault2D(&st);
        st.blend_src = 8;
        st.blend_dst = 10;
        DrawStatePush(&st);
    }
    n = o->count;
    p = o->items;
    fn_8028A3E0(1);
    for (i = 0; i < n; i++) {
        fn_8028A2A8(p++, 4);
    }
    fn_8028A2A4();
    if (o->flags & 0x80000) {
        DrawStatePop(NULL);
    }
    if (++o->frame >= 15) {
        o->flags |= 2;
        o->flags &= ~0x40001;
        fn_801202C4(o);
        fn_8012048C(o);
        o->frame = 0;
    }
}

void fn_80122778(Obj_80122778* o) {
    Anim_80122778* a = o->anim;
    a->timer++;
    if (a->timer % (a->frames[a->idx].dur + 1) != 0) {
        fn_801D6CBC(a->handle, a->s14);
        return;
    }
    a->idx++;
    if (a->frames[a->idx].dur == 0) {
        a->loops++;
        if (a->loops >= a->max_loops) {
            fn_801D6C3C(a->handle);
            if (o->anim != NULL) {
                fn_801E1784(o->anim);
                o->anim = NULL;
            }
            o->flags |= 0x40;
            return;
        }
        a->idx = 0;
    }
    fn_801D6CBC(a->handle, a->s14);
    a->timer = 0;
    a->b16 = a->frames[a->idx].a;
    a->b17 = a->frames[a->idx].b;
}

Obj_80122A00* fn_80122A00(s32 unused, Src_80122A00* s) {
    Obj_80122A00* o;
    s32 i;
    SrcFrame* sf;
    Anim_80122A00* a;
    Frame* f;
    if (fn_801D6E38(s->handle) == 0) {
        return NULL;
    }
    o = fn_80226704(lbl_80347588, fn_80122D5C, 8);
    if (o == NULL) {
        return NULL;
    }
    o->src = s;
    o->anim = s->anim;
    a = s->anim;
    sf = s->frames;
    f = a->frames;
    a->handle = s->handle;
    a->idx = 0;
    a->loops = 0;
    a->timer = 0;
    for (i = 0; i < 31; i++) {
        f->a = sf->a;
        f->b = sf->b;
        f->dur = sf->dur;
        sf++;
        if (f->dur == 0) {
            a->count = i + 1;
            a->max_loops = (s8)f->b;
            break;
        }
        f++;
    }
    if (i >= 31) {
        f[-1].dur = 0;
        a->count = 31;
        a->max_loops = (s8)f[-1].b;
    }
    a->b14 = 1;
    a->b15 = 0;
    a->b18 = 0;
    a->b16 = a->frames[0].a;
    a->b17 = a->frames[0].b;
    return o;
}

void fn_80126014(void *a, In *in, Obj_80126014 *o)
{
    fn_8014EF34(in);
    if (o->flags & 1) {
        fn_801278F0((u8 *)in, (u8 *)o);
        fn_801276E8(a, o);
    }
    if (o->flags & 4) {
        if (in->s14 != 0 && in->s10 == 2) {
            o->b14 = 1;
            o->b15 = 0;
        }
        fn_801275E0((Ctx_801275E0 *)a, (Obj_801275E0 *)o);
    }
    if (o->flags & 2) {
        if (in->s20 != 0) {
            if (o->tbl[o->b17] == -1) {
                o->b13 = 0;
            } else {
                o->b13 = o->b17;
            }
            o->b12 = 1;
        }
        fn_80126118(a, o);
    }
}

void fn_801275E0(Ctx_801275E0 *c, Obj_801275E0 *o)
{
    Sub_801275E0 *s = &o->sub;
    if (o->b14 != 0) {
        if (o->b14 == 1) {
            o->b14 = 2;
            o->s1a = 1;
            fn_80126F0C(c, o);
            o->b5 = s->e58[o->b15].b;
        }
        if (!(c->f18c < (f32)c->clock->tick - s->f0c0 * c->f190)) {
            fn_80126F0C(c, o);
            o->b14 = 0;
            o->s1a = 0;
            if (o->b5 == o->b6) {
                o->b6 = -1;
            }
            o->b5 = ((u8 *)s)[o->b17 * 0xe];
        }
    }
}

void fn_80127E24(Ctx_80127E24 *c, Obj_80127E24 *o, u32 mask)
{
    s32 t;
    fn_801264A4((u8 *)c + 0x38, 1, 0.0f);
    if (fn_80126E24(c, 10.0f, 12.0f)) {
        o->v44 = c->v44;
        o->v48 = c->v48;
        o->v4c = c->v4c;
        o->flags &= ~mask;
        o->flags |= 0x20;
    } else if (o->v50 != 0) {
        if (mask & 0x80) {
            t = o->v60;
            c->v44 = t;
            o->v44 = t;
        }
        if (mask & 0x100) {
            t = o->v64;
            c->v48 = t;
            o->v48 = t;
        }
        if (mask & 0x200) {
            t = o->v68;
            c->v4c = t;
            o->v4c = t;
        }
        o->flags &= ~0x20;
        o->flags |= mask;
    }
}

s32 fn_801284C0(Tbl_801284C0 *t)
{
    u8 ids[3] = { 0, 1, 2 };
    u8 a0[6] = { 2, 0, 0x32, 1, 0x33, 0 };
    u8 a1[6] = { 2, 1, 0x33, 0, 0x32, 1 };
    u8 a2[4] = { 1, 2, 0, 2 };
    s32 i;
    for (i = 0; i < 3; i++) {
        t->e[i].id = ids[i];
    }
    for (i = 0; i < 6; i++) {
        t->e[0].a[i] = a0[i];
    }
    for (i = 0; i < 6; i++) {
        t->e[1].a[i] = a1[i];
    }
    for (i = 0; i < 4; i++) {
        t->e[2].a[i] = a2[i];
    }
    t->b_ac = 0x14;
    t->b_ad = 0x15;
    t->f_b0 = 31.0f;
    t->f_b4 = 40.0f;
    t->f_bc = 41.0f;
    t->f_c0 = 1.0f;
    t->f_c4 = 1.0f;
    return 3;
}

s32 fn_80128A1C(Tbl_80128A1C *t)
{
    u8 ids[4] = { 0, 1, 2, 3 };
    u8 a0[3] = { 1, 0x35, 0 };
    u8 a1[3] = { 0, 0x34, 1 };
    u8 a2[6] = { 0, 2, 1, 2, 3, 2 };
    u8 a3[3] = { 2, 0x36, 3 };
    s32 i;
    for (i = 0; i < 4; i++) {
        t->e[i].id = ids[i];
    }
    for (i = 0; i < 3; i++) {
        t->e[0].a[i] = a0[i];
    }
    for (i = 0; i < 3; i++) {
        t->e[1].a[i] = a1[i];
    }
    for (i = 0; i < 6; i++) {
        t->e[2].a[i] = a2[i];
    }
    for (i = 0; i < 3; i++) {
        t->e[3].a[i] = a3[i];
    }
    t->f_b0 = 31.0f;
    t->f_b4 = 40.0f;
    t->f_bc = 41.0f;
    t->f_c0 = 1.0f;
    t->f_c4 = 1.0f;
    return 4;
}

void fn_801299B4(void)
{
    s32 ready;
    ready = lbl_80311AC0[1] >= 500;
    if (ready != 0) {
        lbl_80346EE4 = lbl_803472E0;
        if (lbl_80347294 == 1) {
            lbl_80347290 = 0;
        }
        lbl_803472E0 = lbl_803472E0 + lbl_803472DC;
        fn_80156250();
        if (lbl_803472E0 >= (f32)(lbl_803472A4->v8 + lbl_803472A4->v4) && lbl_80346EE4 != lbl_803472E0) {
            fn_80144E5C();
            lbl_803472C0 = lbl_803472C0 + 1;
            if (lbl_803472C0 % lbl_803472D0 == 0) {
                lbl_803472DC = 0.0f;
                lbl_803472D8 = lbl_803472D8 + 1;
            }
        }
    }
}

void fn_8012AA8C(void)
{
    if (lbl_80346EFC != NULL) {
        fn_801D6944(lbl_80346EFC);
    }
    if (lbl_80346F00 != NULL) {
        fn_801D6944(lbl_80346F00);
    }
    if (lbl_80346F04 != NULL) {
        fn_801D6944(lbl_80346F04);
    }
    if (lbl_80346F08 != NULL) {
        fn_801D6944(lbl_80346F08);
    }
    if (lbl_80346EF0 != NULL) {
        fn_802275A4(lbl_80346EF0->x4->x20, 1);
        fn_801E17E0(lbl_80346EF0);
        lbl_80346EF0 = NULL;
    }
    if (lbl_80346EF4 != NULL) {
        fn_802275A4(lbl_80346EF4->x4->x20, 1);
        fn_801E17E0(lbl_80346EF4);
        lbl_80346EF4 = NULL;
    }
    if (lbl_80346EF8 != NULL) {
        fn_802275A4(lbl_80346EF8->x4->x20, 1);
        fn_801E17E0(lbl_80346EF8);
        lbl_80346EF8 = NULL;
    }
    if (lbl_80346F0C != NULL) {
        fn_801E17E0(lbl_80346F0C);
        lbl_80346F0C = NULL;
    }
}
