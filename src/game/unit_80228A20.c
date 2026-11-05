#include "game/unit_80219378.h"

extern s32 lbl_80347858;
extern s32 lbl_80347818;
extern s32 lbl_8034781C;
extern s32 lbl_8034782C;
extern void fn_801D0B2C(void);
extern void fn_80100178(const void *p);
extern void fn_801DBE6C(s32 a);
extern void fn_801E1D94(void);
extern void fn_801D14F8(void);
extern void fn_801D0B38(s32 a);
extern void fn_801D8B2C(void);
typedef unsigned int u32_8022A36C;
extern u32_8022A36C lbl_80347820;
extern u32_8022A36C lbl_80347824;
typedef struct Y { u8 pad[4]; Z *p4; } Y;
typedef struct EntA { u8 pad[0x14]; Y *y; u8 pad18[0x68 - 0x18]; } EntA;
typedef struct TblRoot { u8 pad[4]; EntA *p4; } TblRoot;
/* A four-channel interpolator (unit_801D24D0.c's fn_801D89D4/fn_801D8AB4 set it up). */
typedef struct Lerp4 {
    u32 flags;
    f32 start[4];
    f32 end[4];
    f32 delta[4];
    f32 cur[4];
    s32 total;
    s32 count;
    s32 delay;
} Lerp4;
typedef struct PartPos { f32 rx, ry, rz, tx, ty, tz, pad; } PartPos;
typedef struct Blk3c {                    /* 0x3c .. 0xc8, cleared together */
    u32 w3c;
    PartPos pp[3];                        /* 0x40 */
    u8 pad94[0xc8 - 0x94];
} Blk3c;
typedef struct Blkf4 {                    /* 0xf4 .. 0x128, cleared together */
    s16 sf4;
    u16 hf6;
    u8 idx[2];                            /* 0xf8 */
    s16 sfa;
    u8 padfc[4];
    f32 f100;
    u8 pad104[4];
    s32 w108, w10c;
    u8 b110;
    u8 pad111[0x128 - 0x111];
} Blkf4;
typedef struct C0 {
    u8 pad0[2];
    u8 b2;
    u8 pad3[5];
    f32 f8;
    s32 wc;
    f32 f10;
    s32 w14;
    s8 b18;
    u8 pad19[0x34 - 0x19];
    f32 f34;
    s8 sel;
    u8 pad39[3];
    Blk3c blk3c;         /* 0x3c */
    f32 fc8, fcc, fd0, fd4, fd8, fdc, fe0, fe4, fe8, fec, ff0;   /* 0xc8 */
    Blkf4 blkf4;         /* 0xf4 */
    Lerp4 items[7];      /* 0x128 */
    TblRoot *p358;
    struct TexRoot *p35c;
} C0;
extern C0 *lbl_8034784C;
extern f32 lbl_8034C640;
extern f32 lbl_8034C65C;
extern void fn_801D5DD8(void *a, s32 b, s32 c, void *p, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5, f32 f6);
typedef struct Spr { u8 pad[0x14]; f32 f14; u8 pad18[0x50 - 0x18]; } Spr;
extern s32 lbl_80347848;
extern s32 fn_801D8D18(void);
extern s32 lbl_803475D4;
extern u8 lbl_8030A794[];
extern void fn_801CAF30(void);
extern void fn_801F01E4(void);
extern void fn_801E0FD4(void *p, s32 n);
extern void fn_801F7B04(s32 a);
extern TexRoot *lbl_80347850;
extern void fn_801A372C(void);
extern void fn_801DBA58(u32 a, u32 b, u32 c);
extern void fn_801CBBBC(void);
typedef struct Cfg {
    f32 a;
    f32 b;
    f32 c;
    f32 d;
    f32 e;
} Cfg;
typedef struct Obj_80229BEC {
    u8 pad0[0xf4];
    u16 state;
    u8 padf6[2];
    u8 prev;
    u8 cur;
    s16 timer;
    u8 padfc[4];
    f32 fade;
    u8 pad104[0x2b8 - 0x104];
    Lerp4 sub;
    Lerp4 sub2;
} Obj_80229BEC;
extern Cfg lbl_802F915C[];
extern f32 lbl_8034C648;
extern f32 lbl_8034C688;
extern f32 lbl_8034C68C;
extern void fn_801D89D4(Lerp4 *p, u32 a, s32 b, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5, f32 f6, f32 f7, f32 f8);
extern void fn_801D8AB4(Lerp4 *p, s32 a, s32 b, f32 f1, f32 f2);
extern DrawState lbl_803165A0;
extern f32 lbl_8034C6A0;
extern f32 lbl_80346788;
extern f32 lbl_8034678C;
extern s32 lbl_80346E48;
extern void fn_8022DCC4(void);
extern void fn_801DA1C0(void);
extern void fn_8028BB90(Camera803119E0 *cam);
extern void njClipZ(f32 n, f32 f);
extern void TextReset(void);
extern s32 lbl_80347830;

extern f32 lbl_802F8C50[];

extern void fn_801D71BC(s32 a);
extern void fn_801D8840(Lerp4 *p);
extern TblRoot *fn_801DAE58(const char *name);
extern void *fn_80215EA0(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, const char *g, s32 h);
extern void fn_80215F94(void *p);
extern void fn_801A37C4(void);
extern u32 lbl_80347840;
extern u32 lbl_80347844;
extern void *lbl_80347834;
extern s32 lbl_8034783C;
extern void fn_801A3510(void);

extern u32_8022A36C lbl_80347828;
extern VertexCol lbl_802F911C[4];
extern DrawState lbl_803165A0;
extern Spr lbl_802F9038;
extern void fn_80290ED4(VertexCol* v, s32 count, s32 flag);
extern void fn_80296ED4(s32 v);
extern s32 fn_8022A854(u32_8022A36C* p);

extern Spr lbl_802F8FE8;
extern s32 FontUpdate(void);

extern const char lbl_802D96CC[];
extern const char lbl_802D96D8[];

s32 fn_8022A728(u32_8022A36C *state, u32_8022A36C *cnt, s32 lim)
{
    s32 ret = 0;
    switch (*state) {
    case 0:
        *state = *state + 1;
        fn_801CBBD8();
        fn_801CBB9C(15.0f);
        break;
    case 1:
        if (lbl_80347508 != 1) {
            *state = *state + 1;
        }
        break;
    case 2:
        *cnt = *cnt + 1;
        if (*cnt > lim) {
            *state = *state + 1;
            fn_801CBBAC(15.0f);
        }
        break;
    case 3:
        if (lbl_80347508 != 1) {
            ret = 1;
        }
        break;
    }
    fn_8022642C();
    return ret;
}

void fn_8022A68C(void) {
    fn_801E1D94();
    fn_80226170();
    fn_802281BC(0x400);
    fn_8022DCC4();
    fn_801DA1C0();
    fn_801DBA58(0xff000000, 0xff000000, 0xff000000);
    fn_8028BB90(&lbl_803119E0);
    lbl_80346788 = lbl_8034C688;
    lbl_8034678C = lbl_8034C6A0;
    njClipZ(lbl_8034C688, lbl_8034C6A0);
    DrawStateDefault(1, &lbl_803165A0);
    TextReset();
    if (lbl_80346E48 == 1) {
        lbl_80346E48 = 0;
    }
    lbl_80311AD4[3] = 1;
}

void fn_8022A5D0(void)
{
    fn_801D0B2C();
    if (lbl_80347830 != 0) {
        lbl_80347830 = 0;
        lbl_80311AD4[3] = 2;
        lbl_8034781C = 0;
    } else {
        if (FontIsReady() == 0) {
            lbl_80311AD4[3] = 2;
        } else {
            if (lbl_8034782C != 0) {
                lbl_8034782C = 0;
                lbl_80311AD4[3] = 9;
                fn_801D0B2C();
            } else {
                s32 n;
                s32 v;
                fn_801A372C();
                n = lbl_8034781C;
                v = (n & 1) + 7;
                lbl_8034781C = n + 1;
                lbl_80311AD4[3] = v;
            }
        }
    }
}

void fn_8022A548(void) {
    lbl_80347854 = fn_801DB244("/title/ts900026.mld");
    fn_80227810(lbl_80347854->inner->list);
    lbl_80347850 = fn_801DB244("/title/warning.mld");
    fn_80227810(lbl_80347850->inner->list);
    fn_801DBA58(0xff000000, 0xff000000, 0xff000000);
    fn_801CBC30();
    fn_801CBBBC();
    lbl_80311AD4[3] = 3;
    lbl_80347820 = 0;
    lbl_80347824 = 0;
}

void fn_8022A46C(void) {
    s32 r;
    fn_80290ED4(lbl_802F911C, 4, 0);
    DrawStatePush(&lbl_803165A0);
    fn_80296ED4(0x2000);
    lbl_802F8FE8.f14 = 140.0f;
    fn_801D5DD8(&lbl_802F8FE8, 0, 0, lbl_80347854->inner->list, 1.1f, 1.0f, -1000.0f, 0.0f, 1.0f, 1.0f);
    DrawStatePop(&lbl_803165A0);
    r = FontUpdate();
    if (fn_8022A728(&lbl_80347820, &lbl_80347824, 0x96) != 0 && r != 0) {
        lbl_80311AD4[3] = 4;
        lbl_80347820 = 0;
        lbl_80347824 = 0;
    }
}

void fn_8022A38C(void) {
    s32 r;
    fn_80290ED4(lbl_802F911C, 4, 0);
    DrawStatePush(&lbl_803165A0);
    fn_80296ED4(0x2000);
    lbl_802F9038.f14 = 37.0f;
    fn_801D5DD8(&lbl_802F9038, 0, 0, lbl_80347854->inner->list, 1.1f, 1.0f, -1000.0f, 0.0f, 1.0f, 1.0f);
    DrawStatePop(&lbl_803165A0);
    r = fn_8022A854(&lbl_80347828);
    if (fn_8022A728(&lbl_80347820, &lbl_80347824, 0x96) != 0 && r != 0) {
        lbl_80311AD4[3] = 5;
        lbl_80347820 = 0;
        lbl_80347824 = 0;
    }
}

void fn_8022A36C(void) {
    lbl_80311AD4[3] = 6;
    lbl_80347820 = 0;
    lbl_80347824 = 0;
}

void fn_8022A2E4(void) {
    s32 st;
    s32 v;
    fn_802275A4(lbl_80347854->inner->list, 1);
    fn_801E17E0(lbl_80347854);
    lbl_80347854 = 0;
    fn_802275A4(lbl_80347850->inner->list, 1);
    fn_801E17E0(lbl_80347850);
    lbl_80347850 = 0;
    fn_801A372C();
    v = lbl_8034781C;
    st = (v & 1) + 7;
    lbl_8034781C = v + 1;
    lbl_80311AD4[3] = st;
}

void fn_8022A29C(void)
{
    lbl_8034782C = 1;
    fn_80100178("ME299A.SCT");
    fn_801DBE6C(6);
    fn_801D0B38(0x5000);
    fn_801E1D94();
    fn_801D14F8();
}

void fn_8022A25C(void)
{
    lbl_8034782C = 1;
    fn_80100178("ME297A.SCT");
    fn_801DBE6C(6);
    fn_801E1D94();
    fn_801D14F8();
}

void fn_80229E54(void) {
    Lerp4 *th;
    s32 i;

    fn_801D71BC(0);
    lbl_80347840 = 0;
    lbl_80347844 = OSGetTick();
    fn_801CBC30();
    fn_801CBBBC();
    fn_801CBBD8();
    fn_801CBB9C(15.0f);
    fn_8022642C();
    lbl_8034784C = fn_801E1C7C(0x360);
    lbl_8034784C->b2 = 0;
    memset(&lbl_8034784C->blkf4, 0, sizeof(Blkf4));
    lbl_8034784C->p358 = fn_801DAE58("/title/title0.mld");
    for (i = 0; i < 5; i++) {
        fn_80227810(&lbl_8034784C->p358->p4[i].y->p4->texlist);
    }
    memset(&lbl_8034784C->blk3c, 0, sizeof(Blk3c));
    memset(&lbl_8034784C->blkf4, 0, sizeof(Blkf4));
    memset(lbl_8034784C->items, 0, sizeof(lbl_8034784C->items));
    lbl_8034784C->blk3c.pp[0].tz = -700.0f;
    lbl_8034784C->blk3c.pp[1].tz = -3100.0f;
    lbl_8034784C->blk3c.pp[2].tz = -5500.0f;
    lbl_8034784C->sel = 1;
    if (lbl_8034784C->sel < 0 || lbl_8034784C->sel > 4) {
        lbl_8034784C->sel = 1;
    }
    lbl_8034784C->blkf4.hf6 = 0;
    lbl_8034784C->blkf4.idx[0] = 4;
    lbl_8034784C->blkf4.idx[1] = 1;
    lbl_8034784C->blkf4.f100 = -1.0f;
    lbl_8034784C->blkf4.w108 = 0;
    lbl_8034784C->blkf4.w10c = 0;
    th = &lbl_8034784C->items[5];
    fn_801D89D4(th, 1, 0, 1.0f, 0.0f, 0.0f, 0.0f, lbl_802F915C[0].a, lbl_802F915C[0].b, lbl_802F915C[0].c, lbl_802F915C[0].d);
    fn_801D8840(th);
    lbl_8034784C->fd8 = th->cur[0];
    lbl_8034784C->fdc = th->cur[1];
    lbl_8034784C->fe0 = th->cur[2];
    lbl_8034784C->fe4 = th->cur[3];
    lbl_8034784C->fe8 = 1.0f;
    lbl_8034784C->fec = 1.0f;
    lbl_8034784C->ff0 = 1.0f;
    fn_801D8AB4(&th[1], 1, 0, 1.0f, lbl_802F915C[0].e);
    fn_801D8840(&th[1]);
    lbl_8034784C->fd4 = th[1].cur[0];
    lbl_8034784C->fc8 = 0.0f;
    lbl_8034784C->fcc = 0.0f;
    lbl_8034784C->fd0 = 1.0f;
    lbl_8034784C->f8 = 1.0f;
    lbl_8034784C->wc = 1;
    lbl_8034784C->f10 = 1.0f;
    lbl_8034784C->w14 = 0;
    lbl_8034784C->f34 = 0.0f;
    lbl_8034784C->b18 = -1;
    lbl_8034784C->blkf4.b110 = 0xff;
    lbl_8034784C->blkf4.b110 &= ~2;
    lbl_8034784C->blkf4.sfa = 0;
    lbl_8034784C->blkf4.sf4 = 0;
    fn_801D8AB4(&lbl_8034784C->items[0], 0x3c, 0xb4, 0.0f, 1.0f);
    fn_801D8AB4(&lbl_8034784C->items[1], 0x3c, 0x12c, 0.0f, 1.0f);
    fn_801D8AB4(&lbl_8034784C->items[2], 0x3c, 0x168, 0.0f, 1.0f);
    fn_801D8AB4(&lbl_8034784C->items[3], 0x3c, 0x12c, 0.0f, 1.0f);
    fn_801D8AB4(&lbl_8034784C->items[4], 0x3c, 0x12c, 0.0f, 1.0f);
    fn_8022BC64();
    lbl_8034784C->p35c = fn_801DB244("/title/ts900000.mld");
    fn_80227810(lbl_8034784C->p35c->inner->list);
    fn_80219378("/sound/m5000000.mlt");
    lbl_80347834 = fn_80215EA0(1, 0xac44, 2, 0, 0, 0, lbl_802D96D8, 0x3c000);
    if (lbl_80347834 != 0) {
        fn_80215F94(lbl_80347834);
    } else {
        lbl_8034783C = -1;
    }
    fn_801A37C4();
    lbl_80311AD4[3] = 10;
}

void fn_80229D74(void) {
    u16 i;
    fn_8022642C();
    fn_8022642C();
    fn_8022642C();
    if (lbl_8034784C->p35c != 0) {
        fn_802275A4(lbl_8034784C->p35c->inner->list, 1);
        fn_801E17E0(lbl_8034784C->p35c);
        lbl_8034784C->p35c = 0;
    }
    for (i = 0; i < 5; i++) {
        fn_802275A4(&lbl_8034784C->p358->p4[i].y->p4->texlist, 1);
    }
    fn_801E17E0(lbl_8034784C->p358);
    lbl_8034784C->p358 = 0;
    fn_801CBBF8();
    fn_8022642C();
    fn_8022642C();
    fn_8022642C();
    fn_8022642C();
    fn_8022642C();
    fn_8022642C();
}

void fn_80229BEC(Obj_80229BEC *o) {
    u32 lim[5] = {0, 0x30c, 0xf0, 0x30c, 0x10e};
    Lerp4 *s;
    s32 i;
    switch (o->state) {
    case 0:
        if (o->timer < lim[o->cur]) {
            o->timer++;
        } else {
            o->fade = lbl_8034C648;
            o->prev = o->cur;
            if (o->cur < 4) {
                o->cur++;
            } else {
                o->cur = 1;
            }
            o->timer = 0;
            o->state = 1;
            s = &o->sub;
            i = (u8)(o->cur - 1);
            fn_801D89D4(s, 200, 10, s->cur[0], s->cur[1], s->cur[2], s->cur[3], lbl_802F915C[i].a, lbl_802F915C[i].b, lbl_802F915C[i].c, lbl_802F915C[i].d);
            fn_801D8AB4(&s[1], 0x104, 0x1e, s[1].cur[0], lbl_802F915C[i].e);
        }
        break;
    case 1:
        if (o->fade > lbl_8034C688) {
            o->fade -= lbl_8034C68C;
        } else {
            o->state = 0;
        }
        break;
    default:
        o->state = 0;
        break;
    }
}

const u8 lbl_802D969C[0x30] = {0};
const char lbl_802D96CC[0xC] = "ME201A.sct";
const char lbl_802D96D8[0x10] = "/sound/m02s.p16";

f32 fn_8022975C(void *a, s32 b, s32 c, f32 x, f32 y, f32 z, f32 w) {
    fn_801D5DD8(a, b, c, lbl_8034784C->p35c->inner->list, lbl_8034C640, lbl_8034C640, x, y, z, w);
    return lbl_8034C65C + x;
}

s32 fn_802295D0(void) {
    s32 r = 0;
    s32 n;
    lbl_802F8C50[5] = 172.0f;
    fn_801D5DD8(lbl_802F8C50, 0, 0, lbl_8034784C->p35c->inner->list, 1.0f, 1.0f, 99.99f, 0.0f, 1.0f, lbl_8034784C->items[2].cur[0]);
    if (lbl_80311A60.p->f8 & 0x1000) {
        if (lbl_8034784C->items[0].flags & 1) lbl_8034784C->items[0].flags |= 0x80;
        if (lbl_8034784C->items[1].flags & 1) lbl_8034784C->items[1].flags |= 0x80;
        if (lbl_8034784C->items[2].flags & 1) lbl_8034784C->items[2].flags |= 0x80;
        if (lbl_8034784C->items[3].flags & 1) lbl_8034784C->items[3].flags |= 0x80;
        if (lbl_8034784C->items[4].flags & 1) lbl_8034784C->items[4].flags |= 0x80;
    }
    n = 0;
    { s32 i; for (i = 0; i < 5; i++) if (lbl_8034784C->items[i].flags & 1) n++; }
    if (n == 0) {
        fn_801D8AB4(&lbl_8034784C->items[2], 0x1e, 0x14, 1.0f, 0.0f);
        r = 1;
        lbl_8034784C->items[2].flags |= 6;
    }
    return r;
}

void fn_80228BE4(void) {
    fn_801CAF30();
    fn_801F01E4();
    fn_801E0FD4(lbl_8030A794, 0xcc0);
    fn_801F7B04(0);
    lbl_803475D4 = 1;
    lbl_80310B3C.f88 |= 0x20;
    fn_8022AFD0();
    lbl_80311AD4[3] = 0xf;
}

void fn_80228B74(void) {
    switch (fn_8022AE94()) {
    case 0: fn_80228914(); fn_80100178(lbl_802D96CC); fn_801DBE6C(6); break;
    case 1: fn_801CBC30(); lbl_80311AD4[3] = 2; break;
    case 2: break;
    }
    fn_8022642C();
}

void fn_80228B40(void) {
    fn_801D8B2C();
    fn_8022642C();
    lbl_80311AD4[3] = 0x11;
}

void fn_80228AD4(void) {
    s32 r = fn_801D8D18();
    lbl_80347848 = r;
    if (r != -1) {
        if (r == 1) {
            lbl_80311AD4[3] = 9;
        } else {
            lbl_80311AD4[3] = 0x12;
            fn_801DBE6C(6);
        }
        fn_8022642C();
        fn_8022642C();
    }
    fn_8022642C();
}

void fn_80228AD0(void) {
}

void fn_80228A98(void)
{
    lbl_80347858 = -1;
    lbl_80347818 = 0;
    lbl_8034781C = 0;
    lbl_8034782C = 0;
    fn_801D0B2C();
}

void fn_80228A20(void) {
    s32 st = lbl_80311AD4[3];
    if (st >= 9 && st <= 13) {
        fn_801A3510();
    }
    if (lbl_80347858 != (st = lbl_80311AD4[3])) {
        lbl_80347818 = 0;
    }
    lbl_80347858 = st;
    lbl_802F91AC[st]();
}
