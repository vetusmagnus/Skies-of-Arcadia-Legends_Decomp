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
    u16 sf4;
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
extern void fn_801D5DD8(void *a, f32 f1, f32 f2, f32 f3, f32 f4, s32 b, s32 c, f32 f5, f32 f6, void *p);
/* A sprite: its texture coordinates, parts and placement (0x1C bytes). */
typedef struct Spr {
    void *p0;
    void *p4;
    s32 n;
    f32 fc, f10, f14, f18;
} Spr;
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

extern Spr lbl_802F8C50;

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

void fn_8022A68C(void);
void fn_8022A5D0(void);
void fn_8022A548(void);
void fn_8022A46C(void);
void fn_8022A38C(void);
void fn_8022A36C(void);
void fn_8022A2E4(void);
void fn_8022A29C(void);
void fn_8022A25C(void);
void fn_80229E54(void);
void fn_802293E0(void);
void fn_80229124(void);
void fn_80228E00(void);
void fn_80228C50(void);
void fn_80228BE4(void);
void fn_80228B74(void);
void fn_80228B40(void);
void fn_80228AD4(void);
void fn_80228AD0(void);

u32 lbl_802F8A78[65] = {
    0x00000000, 0x3BA3D70A, 0x3C75C28F, 0x3F1BA5E3, 0x3F072B02, 0x00000000,
    0x3E54FDF4, 0x3F0B4396, 0x3EE76C8B, 0x3F1CAC08, 0x00000000, 0x3E353F7D,
    0x3F2E5604, 0x3EEC8B44, 0x3F4353F8, 0x00000000, 0x3EA4DD2F, 0x3F5020C5,
    0x3F1BE76D, 0x3F5DF3B6, 0x00000000, 0x3CBC6A7F, 0x3F08F5C3, 0x3E1DB22D,
    0x3F1B645A, 0x00000000, 0x3F056042, 0x3F31EB85, 0x3F1126E9, 0x3F441893,
    0x00000000, 0x3F056042, 0x3F31EB85, 0x3F1126E9, 0x3F441893, 0x00000000,
    0x3F056042, 0x3F31EB85, 0x3F1126E9, 0x3F441893, 0x00000000, 0x3E2C0831,
    0x3F4D0E56, 0x3E9C28F6, 0x3F600000, 0x00000000, 0x3CBC6A7F, 0x3F1C6A7F,
    0x3E1FBE77, 0x3F2E147B, 0x00000000, 0x3E2C0831, 0x3F4D0E56, 0x3E9C28F6,
    0x3F600000, 0x00000000, 0x3C656042, 0x3F2F1AA0, 0x3E29FBE7, 0x3F43126F,
    0x00000000, 0x3EB8D4FE, 0x3F639581, 0x3F1126E9, 0x3F716873,
};
u32 lbl_802F8B7C[13] = {
    0x00000000, 0x00000000, 0x00000000, 0x441A8000, 0x43838000, 0xFFFFFFFF,
    0x00000000, 0xFFFFFFFF, 0x00000000, 0xFFFFFFFF, 0x00000000, 0xFFFFFFFF,
    0x00000000,
};
Spr lbl_802F8BB0 = {lbl_802F8A78, lbl_802F8B7C, 1, 618.0f, 263.0f, 8.0f, 30.0f};
u32 lbl_802F8BCC[13] = {
    0x00000001, 0x00000000, 0x00000000, 0x437A0000, 0x420C0000, 0xFFFFFFFF,
    0x00000000, 0xFFFFFFFF, 0x00000000, 0xFFFFFFFF, 0x00000000, 0xFFFFFFFF,
    0x00000000,
};
Spr lbl_802F8C00 = {lbl_802F8A78, lbl_802F8BCC, 1, 250.0f, 35.0f, 216.0f, 261.0f};
u32 lbl_802F8C1C[13] = {
    0x00000002, 0x00000000, 0x00000000, 0x43920000, 0x42280000, 0xFFFFFFFF,
    0x00000000, 0xFFFFFFFF, 0x00000000, 0xFFFFFFFF, 0x00000000, 0xFFFFFFFF,
    0x00000000,
};
Spr lbl_802F8C50 = {lbl_802F8A78, lbl_802F8C1C, 1, 292.0f, 42.0f, 180.0f, 323.0f};
u32 lbl_802F8C6C[13] = {
    0x00000003, 0x00000000, 0x00000000, 0x43930000, 0x41E00000, 0xFFFFFFFF,
    0x00000000, 0xFFFFFFFF, 0x00000000, 0xFFFFFFFF, 0x00000000, 0xFFFFFFFF,
    0x00000000,
};
Spr lbl_802F8CA0 = {lbl_802F8A78, lbl_802F8C6C, 1, 294.0f, 28.0f, 334.0f, 416.0f};
u32 lbl_802F8CBC[13] = {
    0x00000004, 0x00000000, 0x00000000, 0x43060000, 0x42140000, 0xFFFFFFFF,
    0x00000000, 0xFFFFFFFF, 0x00000000, 0xFFFFFFFF, 0x00000000, 0xFFFFFFFF,
    0x00000000,
};
Spr lbl_802F8CF0 = {lbl_802F8A78, lbl_802F8CBC, 1, 134.0f, 37.0f, 258.0f, 297.0f};
u32 lbl_802F8D0C[13] = {
    0x00000005, 0x00000000, 0x00000000, 0x42400000, 0x42100000, 0xFFFFFFFF,
    0x00000000, 0xFFFFFFFF, 0x00000000, 0xFFFFFFFF, 0x00000000, 0xFFFFFFFF,
    0x00000000,
};
Spr lbl_802F8D40 = {lbl_802F8A78, lbl_802F8D0C, 1, 48.0f, 36.0f, 202.0f, 295.0f};
u32 lbl_802F8D5C[13] = {
    0x00000006, 0x00000000, 0x00000000, 0x42400000, 0x42100000, 0xFFFFFFFF,
    0x00000000, 0xFFFFFFFF, 0x00000000, 0xFFFFFFFF, 0x00000000, 0xFFFFFFFF,
    0x00000000,
};
Spr lbl_802F8D90 = {lbl_802F8A78, lbl_802F8D5C, 1, 48.0f, 36.0f, 202.0f, 335.0f};
u32 lbl_802F8DAC[13] = {
    0x00000007, 0x00000000, 0x00000000, 0x42400000, 0x42100000, 0xFFFFFFFF,
    0x00000000, 0xFFFFFFFF, 0x00000000, 0xFFFFFFFF, 0x00000000, 0xFFFFFFFF,
    0x00000000,
};
Spr lbl_802F8DE0 = {lbl_802F8A78, lbl_802F8DAC, 1, 48.0f, 36.0f, 202.0f, 373.0f};
u32 lbl_802F8DFC[13] = {
    0x00000008, 0x00000000, 0x00000000, 0x430C0000, 0x42180000, 0xFFFFFFFF,
    0x00000000, 0xFFFFFFFF, 0x00000000, 0xFFFFFFFF, 0x00000000, 0xFFFFFFFF,
    0x00000000,
};
Spr lbl_802F8E30 = {lbl_802F8A78, lbl_802F8DFC, 1, 140.0f, 38.0f, 258.0f, 335.0f};
u32 lbl_802F8E4C[13] = {
    0x00000009, 0x00000000, 0x00000000, 0x43080000, 0x420C0000, 0xFFFFFFFF,
    0x00000000, 0xFFFFFFFF, 0x00000000, 0xFFFFFFFF, 0x00000000, 0xFFFFFFFF,
    0x00000000,
};
Spr lbl_802F8E80 = {lbl_802F8A78, lbl_802F8E4C, 1, 136.0f, 35.0f, 255.0f, 337.0f};
u32 lbl_802F8E9C[13] = {
    0x0000000A, 0x00000000, 0x00000000, 0x430C0000, 0x42980000, 0xFFFFFFFF,
    0x00000000, 0xFFFFFFFF, 0x00000000, 0xFFFFFFFF, 0x00000000, 0xFFFFFFFF,
    0x00000000,
};
Spr lbl_802F8ED0 = {lbl_802F8A78, lbl_802F8E9C, 1, 140.0f, 76.0f, 161.0f, 554.0f};
u32 lbl_802F8EEC[13] = {
    0x0000000B, 0x00000000, 0x00000000, 0x431C0000, 0x42200000, 0xFFFFFFFF,
    0x00000000, 0xFFFFFFFF, 0x00000000, 0xFFFFFFFF, 0x00000000, 0xFFFFFFFF,
    0x00000000,
};
Spr lbl_802F8F20 = {lbl_802F8A78, lbl_802F8EEC, 1, 156.0f, 40.0f, 257.0f, 371.0f};
u32 lbl_802F8F3C[13] = {
    0x0000000C, 0x00000000, 0x00000000, 0x43530000, 0x41E00000, 0xFFFFFFFF,
    0x00000000, 0xFFFFFFFF, 0x00000000, 0xFFFFFFFF, 0x00000000, 0xFFFFFFFF,
    0x00000000,
};
Spr lbl_802F8F70 = {lbl_802F8A78, lbl_802F8F3C, 1, 211.0f, 28.0f, 419.0f, 396.0f};
u32 lbl_802F8F8C[10] = {
    0x00000000, 0x3CB43958, 0x3D1BA5E3, 0x3EB8D4FE, 0x3EBA5E35, 0x00000000,
    0x3ED3F7CF, 0x00000000, 0x3F7645A2, 0x3F800000,
};
u32 lbl_802F8FB4[13] = {
    0x00000000, 0x00000000, 0x00000000, 0x43AE0000, 0x43270000, 0xFFFFFFFF,
    0x00000000, 0xFFFFFFFF, 0x00000000, 0xFFFFFFFF, 0x00000000, 0xFFFFFFFF,
    0x00000000,
};
Spr lbl_802F8FE8 = {lbl_802F8F8C, lbl_802F8FB4, 1, 348.0f, 167.0f, 148.0f, 142.0f};
u32 lbl_802F9004[13] = {
    0x00000001, 0x00000000, 0x00000000, 0x440C4000, 0x44000000, 0xFFFFFFFF,
    0x00000000, 0xFFFFFFFF, 0x00000000, 0xFFFFFFFF, 0x00000000, 0xFFFFFFFF,
    0x00000000,
};
Spr lbl_802F9038 = {lbl_802F8F8C, lbl_802F9004, 1, 561.0f, 512.0f, 45.0f, -32.0f};
u32 lbl_802F9054[5] = {
    0x00000000, 0x00000000, 0x00000000, 0x3F200000, 0x3EF020C5,
};
u32 lbl_802F9068[13] = {
    0x00000000, 0x00000000, 0x00000000, 0x44200000, 0x43F00000, 0xFFFFFFFF,
    0x00000000, 0xFFFFFFFF, 0x00000000, 0xFFFFFFFF, 0x00000000, 0xFFFFFFFF,
    0x00000000,
};
Spr lbl_802F909C = {lbl_802F9054, lbl_802F9068, 1, 640.0f, 480.0f, 0.0f, 0.0f};
u32 lbl_802F90B8[5] = {
    0x00000000, 0x00000000, 0x00000000, 0x3F200000, 0x3EF020C5,
};
u32 lbl_802F90CC[13] = {
    0x00000000, 0x00000000, 0x00000000, 0x44200000, 0x43F00000, 0xFFFFFFFF,
    0x00000000, 0xFFFFFFFF, 0x00000000, 0xFFFFFFFF, 0x00000000, 0xFFFFFFFF,
    0x00000000,
};
Spr lbl_802F9100 = {lbl_802F90B8, lbl_802F90CC, 1, 640.0f, 480.0f, 0.0f, 0.0f};
VertexCol lbl_802F911C[4] = {
    {0.0f, 0.0f, 90.0f, 0x00FFFFFF},
    {0.0f, 480.0f, 90.0f, 0x00FFFFFF},
    {640.0f, 0.0f, 90.0f, 0x00FFFFFF},
    {640.0f, 480.0f, 90.0f, 0x00FFFFFF},
};
Cfg lbl_802F915C[4] = {
    {1.0f, 1.0f, 1.0f, 1.0f, 1.0f},
    {1.0f, 0.9f, 0.5f, 0.3f, 1.0f},
    {0.6f, 0.7f, 0.6f, 1.0f, 0.572f},
    {0.8f, 1.0f, 0.8f, 0.7f, 0.8f},
};
void (*lbl_802F91AC[19])(void) = {
    fn_8022A68C,
    fn_8022A5D0,
    fn_8022A548,
    fn_8022A46C,
    fn_8022A38C,
    fn_8022A36C,
    fn_8022A2E4,
    fn_8022A29C,
    fn_8022A25C,
    fn_80229E54,
    fn_802293E0,
    fn_80229124,
    fn_80228E00,
    fn_80228C50,
    fn_80228BE4,
    fn_80228B74,
    fn_80228B40,
    fn_80228AD4,
    fn_80228AD0,
};

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
    fn_801D5DD8(&lbl_802F8FE8, 1.1f, 1.0f, -1000.0f, 0.0f, 0, 0, 1.0f, 1.0f, lbl_80347854->inner->list);
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
    fn_801D5DD8(&lbl_802F9038, 1.1f, 1.0f, -1000.0f, 0.0f, 0, 0, 1.0f, 1.0f, lbl_80347854->inner->list);
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

void fn_80229BEC(C0 *o) {
    u32 lim[5] = {0, 0x30c, 0xf0, 0x30c, 0x10e};
    Lerp4 *s;
    s32 i;
    switch (o->blkf4.sf4) {
    case 0:
        if (o->blkf4.sfa < lim[o->blkf4.idx[1]]) {
            o->blkf4.sfa++;
        } else {
            o->blkf4.f100 = lbl_8034C648;
            o->blkf4.idx[0] = o->blkf4.idx[1];
            if (o->blkf4.idx[1] < 4) {
                o->blkf4.idx[1]++;
            } else {
                o->blkf4.idx[1] = 1;
            }
            o->blkf4.sfa = 0;
            o->blkf4.sf4 = 1;
            s = &o->items[5];
            i = (u8)(o->blkf4.idx[1] - 1);
            fn_801D89D4(s, 200, 10, s->cur[0], s->cur[1], s->cur[2], s->cur[3], lbl_802F915C[i].a, lbl_802F915C[i].b, lbl_802F915C[i].c, lbl_802F915C[i].d);
            fn_801D8AB4(&s[1], 0x104, 0x1e, s[1].cur[0], lbl_802F915C[i].e);
        }
        break;
    case 1:
        if (o->blkf4.f100 > lbl_8034C688) {
            o->blkf4.f100 -= lbl_8034C68C;
        } else {
            o->blkf4.sf4 = 0;
        }
        break;
    default:
        o->blkf4.sf4 = 0;
        break;
    }
}

const u8 lbl_802D969C[0x30] = {0};
const char lbl_802D96CC[0xC] = "ME201A.sct";
const char lbl_802D96D8[0x10] = "/sound/m02s.p16";

f32 fn_8022975C(void *a, s32 b, s32 c, f32 x, f32 y, f32 z, f32 w) {
    fn_801D5DD8(a, lbl_8034C640, lbl_8034C640, x, y, b, c, z, w, lbl_8034784C->p35c->inner->list);
    return lbl_8034C65C + x;
}

s32 fn_802295D0(void) {
    s32 r = 0;
    s32 n;
    lbl_802F8C50.f14 = 172.0f;
    fn_801D5DD8(&lbl_802F8C50, 1.0f, 1.0f, 99.99f, 0.0f, 0, 0, 1.0f, lbl_8034784C->items[2].cur[0], lbl_8034784C->p35c->inner->list);
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

extern s32 lbl_80347838;


static inline f32 TitleSpr(Spr *s, s32 b, s32 c, f32 x, f32 y, f32 z, f32 w) {
    fn_801D5DD8(s, 1.0f, 1.0f, x, y, b, c, z, w, lbl_8034784C->p35c->inner->list);
    return 0.05f + x;
}

static inline void TitleDraw(void) {
    s32 i;
    f32 z;
    Lerp4 *c = lbl_8034784C->items;
    for (i = 0; i < 5; i++) {
        fn_801D8840(&lbl_8034784C->items[i]);
    }
    z = 99.99f;
    z = TitleSpr(&lbl_802F8BB0, 0, 0, z, 0.0f, 1.0f, c[0].cur[0]);
    z = TitleSpr(&lbl_802F8CA0, 0, 0, z, 0.0f, 1.0f, c[4].cur[0]);
    z = TitleSpr(&lbl_802F8F70, 0, 0, z, 0.0f, 1.0f, c[4].cur[0]);
}


static inline s32 TitleReady(void)
{
    s32 r;
    if (lbl_80347840 > 0x1686b) {
        r = fn_80216F48(lbl_80347834);
    } else {
        r = 1;
    }
    return r;
}


void fn_802293E0(void) {
    fn_802297C4();
    TitleDraw();
    if (fn_802295D0()) {
        lbl_80311AD4[3] = 11;
    }
    lbl_80347840 = OSTicksToMilliseconds(OSGetTick() - lbl_80347844);
    if (lbl_80347840 < 0x1686b && lbl_80347840 > 1000 && fn_80216F48(lbl_80347834) == 0) {
        lbl_80347844 = OSGetTick();
        lbl_80347840 = 0;
        lbl_80347834 = fn_80215EA0(1, 0xac44, 2, 0, 0, 0, lbl_802D96D8, 0x3c000);
        if (lbl_80347834 != 0) {
            fn_80215F94(lbl_80347834);
        } else {
            lbl_8034783C = -1;
        }
    }
    fn_8022642C();
}


void fn_80229124(void)
{
    u32 ms;
    void *h;

    fn_802297C4();
    TitleDraw();
    fn_802295D0();
    if (!TitleReady()) {
        lbl_80311AD4[3] = 0xd;
        fn_801CBBBC();
        fn_801CBBAC(15.0f);
        lbl_80347820 = 3;
        lbl_80347824 = 0;
        fn_8022642C();
        if (TitleReady()) {
            fn_8021730C(lbl_80347834, 0x1a);
        }
        lbl_8034784C->b18 = 0x77;
    } else {
        if (lbl_80311A60.p->f8 & 0x1000) {
            lbl_80311AD4[3] = 0xc;
            fn_801D8D54();
            lbl_80347838 = SePlay(0xe, 5, 1);
        }
    }
    ms = OSTicksToMilliseconds(OSGetTick() - lbl_80347844);
    lbl_80347840 = ms;
    if (ms < 0x1686b && ms > 0x3e8) {
        if (fn_80216F48(lbl_80347834) == 0) {
            lbl_80347844 = OSGetTick();
            lbl_80347840 = 0;
            h = fn_80215EA0(1, 0xAC44, 2, 0, 0, 0, lbl_802D96D8, 0x3C000);
            lbl_80347834 = h;
            if (h != 0) {
                fn_80215F94(h);
            } else {
                lbl_8034783C = -1;
            }
        }
    }
    fn_8022642C();
}


void fn_80228E00(void)
{
    s8 v;
    u32 ms;
    void *h;

    fn_802297C4();
    TitleDraw();
    fn_8022642C();
    if (!TitleReady()) {
        lbl_80311AD4[3] = 0xd;
        fn_801CBBBC();
        fn_801CBBAC(15.0f);
        lbl_80347820 = 3;
        lbl_80347824 = 0;
        fn_8022642C();
        if (TitleReady()) {
            fn_8021730C(lbl_80347834, 0x1a);
        }
        fn_801D8D3C();
        fn_8022642C();
        fn_8022642C();
        fn_8022642C();
        lbl_8034784C->b18 = 0x77;
        return;
    }
    ms = OSTicksToMilliseconds(OSGetTick() - lbl_80347844);
    lbl_80347840 = ms;
    if (ms < 0x1686b && ms > 0x3e8) {
        if (fn_80216F48(lbl_80347834) == 0) {
            lbl_80347844 = OSGetTick();
            lbl_80347840 = 0;
            h = fn_80215EA0(1, 0xAC44, 2, 0, 0, 0, lbl_802D96D8, 0x3C000);
            lbl_80347834 = h;
            if (h != 0) {
                fn_80215F94(h);
            } else {
                lbl_8034783C = -1;
            }
        }
    }
    v = fn_801D8EE8();
    lbl_8034784C->b18 = v;
    if (v >= 0) {
        lbl_80311AD4[3] = 0xd;
        fn_801CBBBC();
        fn_801CBBAC(15.0f);
        lbl_80347820 = 3;
        lbl_80347824 = 0;
        fn_8022642C();
        if (TitleReady()) {
            fn_8021730C(lbl_80347834, 0x1a);
        }
    } else if (lbl_8034784C->b18 == -2) {
        lbl_8034784C->blkf4.w10c = 0;
    }
}


void fn_80228C50(void) {
    fn_802297C4();
    TitleDraw();
    if (fn_8022A728(&lbl_80347820, &lbl_80347824, 0)) {
        fn_80217830((s32)lbl_80347834);
        fn_80229D74();
        switch (lbl_8034784C->b18) {
        case 0x77:
            lbl_80311AD4[3] = 2;
            break;
        case 0:
        default:
            fn_801D71BC(1);
            lbl_80311AD4[3] = 14;
            break;
        case 1:
            fn_801D71BC(1);
            lbl_80311AD4[3] = 16;
            break;
        }
    }
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
