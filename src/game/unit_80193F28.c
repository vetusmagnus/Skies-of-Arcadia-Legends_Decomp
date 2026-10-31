#include "types.h"
#include "game/gamedata.h"
#include "game/save_8030B7F4.h"
extern void fn_801DBE1C(const char *fmt, ...);
extern void fn_801F2860(s16 v);
/* A cursor of a camp menu screen (unit_8015DC6C.c). */
typedef struct CampCur {
    s32 x0;     /* 0x00 */
    s32 sel;    /* 0x04 */
    s32 x8;     /* 0x08 */
    u32 mask;   /* 0x0C */
} CampCur;
/* The control block of one camp menu screen (lbl_80307638 has one per screen). */
typedef struct CampCtrl {
    CampCur cur[7]; /* 0x00 */
    s32 state;      /* 0x70 */
    f32 f74;        /* 0x74 */
} CampCtrl;
typedef struct CampHold {
    CampCtrl *ctrl; /* 0x00 */
} CampHold;
/* The camp menu task (lbl_8034710C). */
typedef struct CampTask {
    u8 pad0[0x24];
    CampHold *holder; /* 0x24 */
} CampTask;
/* One entry of a camp menu request (fn_80195EA4 fills six). */
typedef struct CampEnt {
    s8 x0;            /* 0x00 */
    u8 x1;            /* 0x01 */
    u8 x2;            /* 0x02 */
    u8 pad3;
    s16 x4;           /* 0x04 */
    s16 x6;           /* 0x06 */
    u8 pad8[4];
    u32 xc;           /* 0x0C */
    const char *x10;  /* 0x10 */
} CampEnt;
/* A camp menu request (0x88): who, which list and page, then the entries. */
typedef struct CampReq {
    s32 a;            /* 0x00 */
    s32 b;            /* 0x04 */
    u8 d;             /* 0x08 */
    s8 count;         /* 0x09 */
    u8 x0a;           /* 0x0A */
    s8 x0b;           /* 0x0B */
    s32 xc;           /* 0x0C */
    CampEnt e[6];     /* 0x10 */
} CampReq;
extern CampCtrl lbl_80307638[22];
extern CampTask *lbl_8034710C;
extern u32 lbl_80347144;
extern u8 lbl_802E98A0[];
extern u32 lbl_802F7298[];
extern u32 lbl_803473EC;
extern s32 lbl_803467D0;
void fn_801F4EA0(s32 a, s32 v);
void fn_8021A1C4(void *out);
void fn_8021ADA0(void *p, void *buf);
extern const char lbl_802B4864[];
extern u32 lbl_80310B3C[];
extern void sndOutputMode(s32 mode);
extern void OSSetSoundMode(s32 mode);
extern s8 lbl_80347148[4];
extern u32 OSGetSoundMode(void);
extern s32 fn_801EE344(s16 a, s32 b);
extern u8 lbl_80310A1C[];
extern u8 lbl_8030B4D4[];
extern int sprintf(char*, const char*, ...);
extern char lbl_802B4870[];
extern char lbl_802B4880[];
extern s32 fn_801E4BF4(s8 a);
extern s32 fn_801E4BBC(s8 a);
extern s32 fn_801F3F88(void *p, s8 i);
extern s32 fn_801E4BF4(s8 v);
extern s32 fn_801E4BBC(s8 v);
/* story-flag bitset */
static inline s32 FlagGet(u32 b) {
    return lbl_80310B3C[b >> 5] & (1 << (b & 31));
}

static inline s32 FlagTest(u32 b) {
    s32 f = (lbl_80310B3C[b >> 5] & (1 << (b & 31))) != 0;
    f = f != 0;
    return f;
}
typedef struct Dst {
    u32 pad0;
    u8 *ptr;
} Dst;
typedef struct {
    u8 pad0[0x14];
    f32 x; /* 0x14 */
    f32 y; /* 0x18 */
} Spr;
typedef struct {
    u8 pad0[0x2C];
    f32 x; /* 0x2C */
    f32 y; /* 0x30 */
} Self;
extern void* lbl_803470F0;
extern s16 lbl_8034711C;
extern s16 lbl_8034711E;
extern Spr* fn_801D68C4(void* bank, u32 n);
extern void fn_800FF348(void* src, s32 id, f32 a, f32 b, f32 c);
typedef struct { u8 pad[0xbc]; u8* p; } In;
typedef struct { u8 pad[0x24]; In* in; } Ob;
typedef struct { u8 pad[0x9c]; Ob* o[15]; } CW_80195804;
extern void fn_801F224C(CampReq* r);
extern void fn_801F1774(CampReq* r);
extern void fn_801F1280(CampReq* r);
extern void fn_801F2518(CampReq* r);
typedef struct Sub1c {
    s32 x0, x4, x8, xc;
    u8 x10[4];
    u8 x14;
    u8 x15[3];
    s32 x18;
} Sub1c;
typedef struct Body {
    s32 x0;
    s32 x4;
    u8 pad08[4];
    f32 xc, x10, x14, x18, x1c, x20, x24, x28, x2c, x30, x34, x38, x3c, x40;
    s32 x44;
    u8 x48, x49;
    s16 x4a, x4c, x4e;
    u8 pad50[0x74 - 0x50];
    u8 x74[0xbc - 0x74];
    void* xbc;
} Body;
typedef struct Node {
    u8 pad[0x24];
    Body* body;
} Node;
typedef struct { s32 a, b; } Pair;
typedef struct CampWork {
    s8 *p0;
    void *p4;
    u8 *p8;
    u8 b0c;
    u8 pad0d[3];
    Node *objs[0xd0]; /* indexed by object kind id */
    u8 pad350[0x10];
} CampWork;
extern CampWork camp_work;
extern void fn_8016E220(void);
extern Node* fn_802268E8(void*, void*);
extern void* fn_801E1C7C(s32);
extern void fn_8016E818(void*, s32);
extern void fn_8018A16C(void);
extern void fn_8018DABC(void*, s8, s32, s32, s8);
extern void fn_8018C6A8(void*, f32);
extern void fn_80187FB4(void);
extern void fn_80187F30(void*, CampCtrl*);
extern void fn_801884C4(void*);
extern void fn_80189B70(void);
extern void fn_80189CF0(void*);
extern void fn_80186A60(void);
extern void fn_801869B8(void*, Pair*);
extern void fn_80186D2C(void*);
extern void fn_8018E82C();
extern void fn_8018E81C(void *buf, s32 a, s8 b);
extern void fn_80191D78(void*);
typedef struct {
    u8 x0;
    u8 x1;
    u8 pad2[2];
    s32 x4;
    s32 x8;
    u32 xc;
    s32 x10, x14, x18, x1c, x20, x24, x28;
} Ent2c;
typedef struct CampSub {
    s32 x0;
    s32 x4;
    u8 pad8[4];
    f32 xc, x10, x14, x18, x1c, x20, x24, x28, x2c, x30, x34, x38, x3c, x40;
    s32 x44;
    u8 x48, x49;
    s16 x4a, x4c, x4e;
    u8 pad50[0x74 - 0x50];
    u8 x74[0xbc - 0x74];
    void *xbc;
} CampSub;
typedef struct CampObj {
    u8 pad[0x24];
    CampSub *sub;
} CampObj;
typedef struct { u8 pad[0x10]; CampObj *objs[1]; } CampWork_80199508;
extern void fn_80191A04(void *p, s32 a);
typedef struct Sub1c_80199678 {
    s32 x0, x4, x8, xc;
    s32 x10;
    u8 x14;
    u8 x15[3];
    s32 x18;
} Sub1c_80199678;
typedef struct Body_80199678 {
    s32 x0;
    s32 x4;
    u8 pad08[4];
    f32 xc, x10, x14, x18, x1c, x20, x24, x28, x2c, x30, x34, x38, x3c, x40;
    s32 x44;
    u8 x48, x49;
    s16 x4a, x4c, x4e;
    u8 pad50[0x74 - 0x50];
    u8 x74[0xbc - 0x74];
    void* xbc;
} Body_80199678;
typedef struct Node_80199678 {
    u8 pad[0x24];
    Body_80199678* body;
} Node_80199678;
typedef struct CampWork_80199678 {
    u8 *p0;
    u8 *p4;
    u8 *p8;
    u8 b0c;
    u8 pad0d[3];
    Node_80199678 *objs[0xd0];
    u8 pad350[0x10];
} CampWork_80199678;
typedef struct Sub1c_80197270 {
    s32 x0, x4, x8, xc;
    u8 x10[4];
    u8 x14;
    u8 x15[3];
    s32 x18;
} Sub1c_80197270;
typedef struct Body_80197270 {
    s32 x0;
    s32 x4;
    u8 pad08[4];
    f32 xc, x10, x14, x18, x1c, x20, x24, x28, x2c, x30, x34, x38, x3c, x40;
    s32 x44;
    u8 x48, x49;
    s16 x4a, x4c, x4e;
    u8 pad50[0x74 - 0x50];
    u8 x74[0xbc - 0x74];
    void* xbc;
} Body_80197270;
typedef struct Node_80197270 {
    u8 pad[0x24];
    Body_80197270* body;
} Node_80197270;
typedef struct CampWork_80197270 {
    u8 *p0;
    u8 *p4;
    u8 *p8;
    u8 b0c;
    u8 pad0d[3];
    Node_80197270 *objs[0xd0];
    u8 pad350[0x10];
} CampWork_80197270;
extern s32 lbl_803467CC;
typedef struct Body_801957D8 {
    u8 pad[0xbc];
    u8* xbc;
} Body_801957D8;
typedef struct Node_801957D8 {
    u8 pad[0x24];
    Body_801957D8* body;
} Node_801957D8;
typedef struct CampWork_801957D8 {
    u8 *p0;
    u8 *p4;
    u8 *p8;
    u8 b0c;
    u8 pad0d[3];
    Node_801957D8 *objs[0xd0]; /* indexed by object kind id */
    u8 pad350[0x10];
} CampWork_801957D8;
typedef struct Node_801968B8 {
    u8 pad[0x19];
    u8 x19;
} Node_801968B8;
typedef struct CampWork_801968B8 {
    u8 *p0;
    u8 *p4;
    u8 *p8;
    u8 b0c;
    u8 pad0d[3];
    Node_801968B8 *objs[0xd0]; /* indexed by object kind id */
    u8 pad350[0x10];
} CampWork_801968B8;
typedef struct {
    u8 pad0[8];
    s32 x8;
} Struct80307628;
extern Struct80307628 lbl_80307628;
extern s32 fn_801D6E38(s32 a);
CampCtrl *fn_80195540(CampReq *r);
extern void fn_80195F9C(void);
extern void fn_801D6CBC(void *h, void *p);
extern void fn_801D6C3C(void *h);
extern s32 camp_screen;
extern void (*camp_screen_funcs[21])(void);
extern void *lbl_80347140;
extern u8 lbl_80347134[8];
extern s32 lbl_8034713C;

int fn_80193F28(void) {
    fn_801DBE1C("Nothing VM Tanken.");
    return 0;
}

u16 fn_80193F58(void) {
    u8 *p = ((u8*)camp_work.objs[154]);
    p = *(u8 **)(p + 0x24);
    p = *(u8 **)(p + 0xbc);
    p = *(u8 **)(p + 0x4);
    return *(u16 *)(p + 0x18);
}

s32 fn_80193F78(void) {
    return 1;
}

void fn_80193F80(void) {
    fn_801F2860(lbl_8030B7F4.x348);
}

char *fn_80193FAC(void) {
    return lbl_8030B7F4.x331;
}

void fn_80193FBC(s32 unused, s32 toggle) {
    if (toggle != 0) {
        lbl_803467D0 = (lbl_803467D0 == 0);
    }
    fn_801F4EA0(unused, lbl_803467D0);
}

void fn_80194028(void) {
    u8 buf[0x20];
    void *p = camp_work.p4;
    fn_8021A1C4(buf);
    fn_8021ADA0(p, buf);
}

int fn_8019406C(void) {
    fn_801DBE1C(lbl_802B4864);
    fn_801DBE1C(lbl_802B4864);
    return 0;
}

s32 fn_801940FC(void) {
    return 1;
}

s32 fn_80194104(void) {
    return 1;
}

void fn_8019410C(void) {
    if (lbl_80307638[18].cur[4].sel == 0) {
        lbl_80310B3C[0x22] |= 0x20;
    } else {
        lbl_80310B3C[0x22] &= ~0x20;
    }
}

void fn_80194210(void) {
    if (lbl_80307638[18].cur[4].sel == 0) {
        lbl_80310B3C[0x22] &= ~0x8;
    } else {
        lbl_80310B3C[0x22] |= 0x8;
    }
}

void fn_80194254(void) {
    lbl_80347144 = lbl_80307638[18].cur[4].sel;
}

void fn_80194268(void) {
    sndOutputMode(lbl_80347144 == 0);
    OSSetSoundMode(lbl_80347144 == 0);
}

void fn_801942A4(void)
{
    lbl_80347148[0] = lbl_80347144 != 0;
    if (FlagTest(0x443)) lbl_80347148[1] = 1; else lbl_80347148[1] = 0;
    if (FlagGet(0x444)) lbl_80347148[2] = 0; else lbl_80347148[2] = 1;
    if (FlagGet(0x445)) lbl_80347148[3] = 1; else lbl_80347148[3] = 0;
}

void fn_80194334(void) {
    if (OSGetSoundMode() == 1) {
        lbl_80347148[0] = 0;
        lbl_80347144 = 0;
    } else {
        lbl_80347148[0] = 1;
        lbl_80347144 = 1;
    }
}

u32 fn_801944C4(void) {
    return lbl_80307638[15].cur[0].sel;
}

typedef struct Msg {
    s16 x0;
    s16 x2;
    s16 x4;
    s16 x6;
    s32 x8;
    s32 xc;
} Msg;
extern void fn_8021A11C(Msg*, s16);
void fn_801949F8(Msg* a, s16 i) {
    fn_8021A11C(a, i);
}

u8 *fn_80194C00(s8 idx) {
    return lbl_802E98A0 + idx * 9;
}

u32 fn_80194C38(s8 idx) {
    return lbl_802F7298[idx];
}

CrewData *fn_80194C50(s8 idx) {
    return &lbl_802D8E64[idx];
}

void fn_80194C68(u8 *base, u32 i, u32 j, u32 v) {
    *(u32 *)(base + i * 8 + j * 4) = v;
}

u32 fn_80194C7C(u8 *base, u32 i, u32 j) {
    u32 v = *(u32 *)(base + i * 8 + j * 4);
    return ((-1 - v) | (v + 1)) >> 31;
}

extern void fn_8021B2B4(Msg*, s16);
s32 fn_80194CA0(void) {
    return 1;
}

s32 fn_80194CA8(void) {
    return 1;
}

s32 fn_80194CB0(void) {
    return 1;
}

s32 fn_80194CB8(void) {
    return 1;
}

s32 fn_80194CC0(void) {
    return 1;
}

s32 fn_80194E64(void) {
    return 1;
}

void fn_80194F3C(Msg* a, s16 i) {
    fn_8021B2B4(a, i);
}

u32 fn_80194F5C(s32 a, s32 b) {
    u32 r;
    if (a > b) {
        r = 0xff2b5000;
    } else if (a < b) {
        r = 0xff800000;
    } else {
        r = 0xff201008;
    }
    return r;
}

s32 fn_801950D0(s32 x) {
    s16 v = x;
    if (v == -1) {
        return 0;
    }
    return (s16)fn_801EE344(v, 6);
}

s32 fn_8019510C(s32 x) {
    s16 v = x;
    if (v == -1) {
        return 0;
    }
    return (s16)fn_801EE344(v, 4);
}

s32 fn_80195148(s32 x) {
    s16 v = x;
    if (v == -1) {
        return 0;
    }
    return (s16)fn_801EE344(v, 3);
}

s32 fn_80195184(s32 x) {
    s16 v = x;
    if (v == -1) {
        return 0;
    }
    return (s16)fn_801EE344(v, 2);
}

s32 fn_801951C0(s32 x) {
    if (x >= 0x190 && x <= 0x1b7) {
        return lbl_802D7E4C[x - 0x190].type;
    }
    if (x >= 0x1b8 && x <= 0x1df) {
        return -1;
    }
    return -2;
}

s32 fn_801953B0(void) {
    return 0;
}

s32 fn_801953B8(void) {
    s32 v = (s8)lbl_80310A1C[6];
    switch (v) {
    case 0: case 1: case 2: case 3: case 4: case 12:
        return 0;
    }
    return lbl_8030B7F4.party[0] == 0;
}

void fn_8019540C(void) {
}

void fn_801954D0(u32 v) {
    u8 *p = (u8 *)camp_work.objs[96];
    p = *(u8 **)(p + 0x24);
    p = *(u8 **)(p + 0xbc);
    *(u32 *)(p + 0x4) = v;
}

void fn_801959D4(s32 idx) {
    lbl_8034710C->holder->ctrl = &lbl_80307638[idx];
}

void fn_80195B34(void) {
}

void fn_80195F90(void) {
    lbl_803473EC = 1;
}

void fn_80199B60(void) {
    u8 v = lbl_8030B4D4[0x2d4];
    camp_work.b0c = v;
    camp_work.p0 = lbl_8030B7F4.party;
    camp_work.p4 = &lbl_8030B7F4.x1568;
    camp_work.p8 = lbl_8030B4D4 + 0x2dc;
}

s32 fn_801944D4(char* buf, s32 id)
{
    s32 mode = lbl_80307638[15].cur[0].sel;
    switch (mode) {
    case 0:
        return (s8)sprintf(buf, lbl_802B4870, id);
    case 1:
        return (s8)sprintf(buf, lbl_802B4880, id);
    }
    return (s32)buf;
}

s32 fn_80194A18(s32 a)
{
    s32 x = a * 2;
    if (fn_801E4BF4((s8)x) == 0) {
        return -1;
    }
    if (fn_801E4BF4((s8)(x + 1)) == 0) {
        return -1;
    }
    if (fn_801E4BBC((s8)x) == 0) {
        return x;
    }
    return x + 1;
}

void fn_80194B84(s8* out)
{
    s32 i;
    for (i = 0; i < 0x16; i++) {
        s8 v;
        if (fn_801E4BF4((s8)i) == 1) {
            if (fn_801E4BBC((s8)i) == 1) {
                v = 1;
            } else {
                v = 0;
            }
        } else {
            v = -1;
        }
        out[i] = v;
    }
}

s32 fn_8019576C(s32 idx) {
    s32 i = 0;
    SaveChar *p = &lbl_8030B7F4.chr[idx];

    for (; i < 0x24; i++) {
        if (fn_801F3F88(p, (s8)i) != 0) {
            return 1;
        }
    }
    return 0;
}

void fn_801959F4(void) {
    CampCtrl *p = lbl_80307638;
    s32 i;

    for (i = 0; i < 0x16; i++) {
        p->cur[0].x0 = 0;
        p->cur[0].sel = 0;
        p->cur[0].x8 = 0;
        p->cur[0].mask = 0;
        p->cur[1].x0 = 0;
        p->cur[1].sel = 0;
        p->cur[1].x8 = 0;
        p->cur[1].mask = 0;
        p->cur[2].x0 = 0;
        p->cur[3].sel = 0;
        p->cur[3].x8 = 0;
        p->cur[3].mask = 0;
        p->cur[4].x0 = 0;
        p->cur[2].sel = 0;
        p->cur[2].x8 = 0;
        p->cur[2].mask = 0;
        p->cur[3].x0 = 0;
        p->cur[4].sel = 0;
        p->cur[4].x8 = 0;
        p->cur[4].mask = 0;
        p->cur[5].x0 = 0;
        p++;
    }
}

s32 fn_80194A8C(s32 a) {
    s32 v = a << 1;

    if (fn_801E4BF4((s8)v) == 0) {
        if (fn_801E4BF4((s8)(v + 1)) == 0) {
            return -1;
        }
        return v + 1;
    }
    if (fn_801E4BF4((s8)(v + 1)) == 0) {
        return v;
    }
    if (fn_801E4BBC((s8)v) == 0) {
        return v + 1;
    }
    return v;
}

s32 fn_80194DA0(void) {
    s32 i;
    s8 t;

    for (i = 0; i < 0x16; i++) {
        if (fn_801E4BF4((s8)i) == 1) {
            break;
        }
    }
    if (i == 0x16) {
        return 0;
    }
    t = (s8)lbl_80310A1C[6];
    {
        s32 v = 0;
        switch (t) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 7:
        case 0xc:
            v = 0;
            break;
        default:
            if (lbl_8030B7F4.party[0] != 0) {
                v = 0;
            } else {
                v = 1;
            }
            break;
        }
        return v == 1;
    }
}

void fn_8019520C(s32 idx, Dst *d) {
    SaveChar *c = &lbl_8030B7F4.chr[(s8)idx];
    s8 t = c->xf;

    switch (t) {
    case 0:
        *(u32 *)(d->ptr + 0x14) = 0xFF20FF0A;
        break;
    case 1:
        *(u32 *)(d->ptr + 0x14) = 0xFFFF4020;
        break;
    case 2:
        *(u32 *)(d->ptr + 0x14) = 0xFFC800FF;
        break;
    case 3:
        *(u32 *)(d->ptr + 0x14) = 0xFF0096FF;
        break;
    case 4:
        *(u32 *)(d->ptr + 0x14) = 0xFFFFC800;
        break;
    case 5:
        *(u32 *)(d->ptr + 0x14) = 0xFFDCDCDC;
        break;
    }
}

void fn_80195A68(u32 *p, s8 a, s8 b, s8 c, s8 d, s8 e) {
    if (a == 1) {
        *p |= 1;
    } else {
        *p &= ~1;
    }
    if (b == 1) {
        *p |= 2;
    } else {
        *p &= ~2;
    }
    if (c == 1) {
        *p |= 4;
    } else {
        *p &= ~4;
    }
    if (d == 1) {
        *p |= 8;
    } else {
        *p &= ~8;
    }
    if (e == 1) {
        *p |= 0x10;
    } else {
        *p &= ~0x10;
    }
}

void fn_80194F88(Self* self) {
    Spr* s;
    s = fn_801D68C4(lbl_803470F0, 0x5e);
    s->x = 83.0f + self->x;
    s->y = self->y - 11.0f;
    fn_800FF348(s, 0, -4000.0f, 1.0f, 1.0f);
    lbl_8034711E++;
    if (lbl_8034711E >= 0x3c) {
        lbl_8034711E = 0;
    }
    lbl_8034711C = lbl_8034711E / 4;
    if (lbl_8034711C <= 12) {
        s = fn_801D68C4(lbl_803470F0, 0x5f);
        s->x = 83.0f + self->x;
        s->y = (self->y - 11.0f) + lbl_8034711C;
        fn_800FF348(s, 0, -3990.0f, 1.0f, 1.0f);
    }
    s = fn_801D68C4(lbl_803470F0, 0x60);
    s->x = 83.0f + self->x;
    s->y = self->y - 11.0f;
    fn_800FF348(s, 0, -3980.0f, 1.0f, 1.0f);
}

void fn_80195804(u8 v) {
    Ob** o = (Ob**)&camp_work.objs[35];
    u32 i;
    for (i = 0; i < 15; ++i) {
        o[i]->in->p[3] = v;
    }
}

s32 fn_80195D8C(s8 a, s8 b, s8 c, u8 d) {
    CampReq r;
    s32 i = 0;
    r.a = a;
    r.b = b;
    r.d = d;
    switch (c) {
    case 1:
        fn_801F224C(&r);
        break;
    case 0:
        fn_801F1774(&r);
        break;
    case 3:
        fn_801F1280(&r);
        break;
    case 2:
        fn_801F2518(&r);
        break;
    case 4:
        fn_801F1280(&r);
        break;
    }
    if (r.b != -1) {
        for (i = 0; i < 6; i++) {
            if (r.e[i].xc == 0) break;
        }
    }
    return i;
}

void fn_80196B08(void) {
    Node* n;
    Body* b;
    Sub1c* s;
    n = fn_802268E8(lbl_8034710C, fn_8016E220);
    n->body = fn_801E1C7C(0xc0);
    b = n->body;
    b->x0 = 0;
    s = fn_801E1C7C(0x1c);
    b->xbc = s;
    s->x0 = 0;
    s->x8 = 0;
    s->x4 = 0;
    s->xc = -1;
    s->x14 = 0;
    s->x18 = 3;
    fn_8016E818(b->x74, 3);
    b->x14 = 0.0f;
    b->x18 = 0.0f;
    b->xc = 0.0f;
    b->x10 = 0.0f;
    b->x2c = 0.0f;
    b->x30 = 0.0f;
    b->x34 = 0.0f;
    b->x38 = 0.0f;
    b->x1c = 0.0f;
    b->x20 = 0.0f;
    b->x24 = 0.0f;
    b->x28 = 0.0f;
    b->x4a = 0;
    b->x4e = 0;
    b->x4c = 0;
    b->x48 = 0;
    b->x3c = 1.0f;
    b->x40 = 1.0f;
    b->x44 = 0;
    b->x49 = 0;
    camp_work.objs[50] = n;
    n->body->x4 = 0x32;
}

void fn_80196E20(void) {
    s32 i;
    for (i = 0; i < 2; i++) {
        Node* n;
        Body* b;
        Sub1c* s;
        n = fn_802268E8(lbl_8034710C, fn_8016E220);
        n->body = fn_801E1C7C(0xc0);
        b = n->body;
        b->x0 = 0;
        s = fn_801E1C7C(0x1c);
        b->xbc = s;
        s->x0 = 0;
        s->x8 = 0;
        s->x4 = 0;
        s->xc = -1;
        s->x14 = i;
        s->x18 = 0;
        fn_8016E818(b->x74, 0);
        b->x14 = 0.0f;
        b->x18 = 0.0f;
        b->xc = 0.0f;
        b->x10 = 0.0f;
        b->x2c = 0.0f;
        b->x30 = 0.0f;
        b->x34 = 0.0f;
        b->x38 = 0.0f;
        b->x1c = 0.0f;
        b->x20 = 0.0f;
        b->x24 = 0.0f;
        b->x28 = 0.0f;
        b->x4a = 0;
        b->x4e = 0;
        b->x4c = 0;
        b->x48 = 1;
        b->x3c = 1.0f;
        b->x40 = 1.0f;
        b->x44 = 0;
        b->x49 = 0;
        camp_work.objs[106 + i] = n;
        n->body->x4 = 0x6a + i;
    }
}

void fn_80196F58(s32 a) {
    s32 i;
    for (i = 0; i < 2; i++) {
        Node* n;
        Body* b;
        void* t;
        n = fn_802268E8(lbl_8034710C, fn_8018A16C);
        n->body = fn_801E1C7C(0xc0);
        b = n->body;
        b->x0 = 0;
        t = fn_801E1C7C(0xb4);
        b->xbc = t;
        fn_8018DABC(t, a, 0, 0, i + 2);
        fn_8018C6A8(b, 0.0f);
        b->x14 = 0.0f;
        b->x18 = 0.0f;
        b->xc = 0.0f;
        b->x10 = 0.0f;
        b->x2c = 0.0f;
        b->x30 = 0.0f;
        b->x34 = 0.0f;
        b->x38 = 0.0f;
        b->x1c = 0.0f;
        b->x20 = 0.0f;
        b->x24 = 0.0f;
        b->x28 = 0.0f;
        b->x4a = 0;
        b->x4e = 0;
        b->x4c = 0;
        b->x48 = 0;
        b->x3c = 1.0f;
        b->x40 = 1.0f;
        b->x44 = 0;
        b->x49 = 0;
        camp_work.objs[104 + i] = n;
        n->body->x4 = 0x68 + i;
    }
}

void fn_80197088(void) {
    Node* n;
    Body* b;
    void* t;
    n = fn_802268E8(lbl_8034710C, fn_80187FB4);
    n->body = fn_801E1C7C(0xc0);
    b = n->body;
    b->x0 = 0;
    t = fn_801E1C7C(8);
    b->xbc = t;
    fn_80187F30(t, lbl_8034710C->holder->ctrl);
    fn_801884C4(b->x74);
    b->x14 = 0.0f;
    b->x18 = 400.0f;
    b->xc = 0.0f;
    b->x10 = 400.0f;
    b->x2c = 0.0f;
    b->x30 = 0.0f;
    b->x34 = 0.0f;
    b->x38 = 0.0f;
    b->x1c = 0.0f;
    b->x20 = 0.0f;
    b->x24 = 0.0f;
    b->x28 = 0.0f;
    b->x4a = 0;
    b->x4e = 0;
    b->x4c = 0;
    b->x48 = 0;
    b->x3c = 1.0f;
    b->x40 = 1.0f;
    b->x44 = 0;
    b->x49 = 0;
    camp_work.objs[95] = n;
    n->body->x4 = 0x5f;
}

void fn_8019717C(void) {
    Node* n;
    Body* b;
    void* t;
    n = fn_802268E8(lbl_8034710C, fn_80189B70);
    n->body = fn_801E1C7C(0xc0);
    b = n->body;
    b->x0 = 0;
    t = fn_801E1C7C(8);
    b->xbc = t;
    fn_80189CF0(b->x74);
    b->x14 = 0.0f;
    b->x18 = 256.0f;
    b->xc = 0.0f;
    b->x10 = 256.0f;
    b->x2c = 0.0f;
    b->x30 = 0.0f;
    b->x34 = 0.0f;
    b->x38 = 0.0f;
    b->x1c = 0.0f;
    b->x20 = 0.0f;
    b->x24 = 0.0f;
    b->x28 = 0.0f;
    b->x4a = 0;
    b->x4e = 0;
    b->x4c = 0;
    b->x48 = 0;
    b->x3c = 1.0f;
    b->x40 = 1.0f;
    b->x44 = 0;
    b->x49 = 0;
    camp_work.objs[96] = n;
    n->body->x4 = 0x60;
    ((Sub1c*)camp_work.objs[96]->body->xbc)->x4 = 0;
}

void fn_801988F8(void) {
    CampWork* w = &camp_work;
    Node* n;
    Body* b;
    Pair arr[13];
    s32 i;
    Pair* p;
    void* t;
    n = fn_802268E8(lbl_8034710C, fn_80186A60);
    n->body = fn_801E1C7C(0xc0);
    b = n->body;
    b->x0 = 0;
    t = fn_801E1C7C(0x64);
    b->xbc = t;
    for (i = 0, p = arr; i < 11; i++, p++) {
        p->a = -1;
        p->b = -1;
    }
    fn_801869B8(t, arr);
    fn_80186D2C(n->body->x74);
    b->x14 = 0.0f;
    b->x18 = 0.0f;
    b->xc = 0.0f;
    b->x10 = 0.0f;
    b->x2c = 0.0f;
    b->x30 = 0.0f;
    b->x34 = 0.0f;
    b->x38 = 0.0f;
    b->x1c = 0.0f;
    b->x20 = 0.0f;
    b->x24 = 0.0f;
    b->x28 = 0.0f;
    b->x4a = 0;
    b->x4e = 0;
    b->x4c = 0;
    b->x48 = 0;
    b->x3c = 1.0f;
    b->x40 = 1.0f;
    b->x44 = 0;
    b->x49 = 0;
    w->objs[130] = n;
    n->body->x4 = 0x82;
}

void fn_801998B8(void) {
    Node* n;
    Body* b;
    void* t;
    n = fn_802268E8(lbl_8034710C, fn_8018E82C);
    n->body = fn_801E1C7C(0xc0);
    n->body->x0 = 0;
    t = fn_801E1C7C(0xc);
    n->body->xbc = t;
    fn_8018E81C(t, 0, -1);
    fn_80191D78(n->body->x74);
    b = n->body;
    b->x14 = 0.0f;
    b->x18 = 256.0f;
    b->xc = 0.0f;
    b->x10 = 256.0f;
    b->x2c = 0.0f;
    b->x30 = 0.0f;
    b->x34 = 0.0f;
    b->x38 = 0.0f;
    b->x1c = 0.0f;
    b->x20 = 0.0f;
    b->x24 = 0.0f;
    b->x28 = 0.0f;
    b->x4a = 0;
    b->x4e = 0;
    b->x4c = 0;
    b->x48 = 1;
    b->x3c = 0.7f;
    b->x40 = 1.0f;
    b->x44 = 0;
    b->x49 = 0;
    camp_work.objs[4] = n;
    n->body->x4 = 4;
}

void fn_80195B38(s8 idx, s32 id, u8 flag)
{
    extern Ent2c lbl_803072E8[];
    extern u8 fn_801F4C24(s16 id);
    extern s32 fn_801F4AE4(s16 id);
    extern s32 fn_801F3FD0(s32 j, s16 id);
    extern s16 fn_801EE344(s16 id, s32 k);
    u32 *m;
    Ent2c *e = &lbl_803072E8[idx];
    s32 j;

    e->x0 = flag;
    lbl_803072E8[idx].x1 = fn_801F4C24(id);
    lbl_803072E8[idx].x4 = id;
    lbl_803072E8[idx].x8 = fn_801F4AE4(id);
    lbl_803072E8[idx].xc = 0;
    m = &e->xc;
    for (j = 0; j < 6; j++) {
        if (fn_801F3FD0(j, id)) {
            *m |= 1 << j;
        }
    }
    lbl_803072E8[idx].x10 = fn_801EE344(id, 0x10);
    lbl_803072E8[idx].x14 = fn_801EE344(id, 0x11);
    lbl_803072E8[idx].x18 = fn_801EE344(id, 1);
    lbl_803072E8[idx].x1c = fn_801EE344(id, 0x12);
    lbl_803072E8[idx].x20 = fn_801EE344(id, 0x13);
    lbl_803072E8[idx].x24 = fn_801EE344(id, 0x14);
    lbl_803072E8[idx].x28 = fn_801EE344(id, 4);
}
extern void fn_801867B8();
extern void fn_8018DD24();
extern void fn_8018858C();
extern void fn_80186908(void *p);
extern void fn_8018DEFC(void *p);
extern void fn_8018873C(void *p);

void fn_80197838(s8 kind)
{
    Node *obj;
    Body *s;
    u8 *p;
    Node **cw = (Node **)&camp_work;
    if (kind == 0x66) {
        obj = fn_802268E8(lbl_8034710C, fn_801867B8);
    } else if (kind == 0x67) {
        obj = fn_802268E8(lbl_8034710C, fn_8018DD24);
    } else {
        obj = fn_802268E8(lbl_8034710C, fn_8018858C);
    }
    obj->body = fn_801E1C7C(0xc0);
    s = obj->body;
    s->x0 = 0;
    s->xbc = 0;
    p = obj->body->x74;
    if (kind == 0x66) {
        fn_80186908(p);
    } else if (kind == 0x67) {
        fn_8018DEFC(p);
    } else {
        fn_8018873C(p);
    }
    s->x14 = 0.0f;
    s->x18 = 0.0f;
    s->xc = 0.0f;
    s->x10 = 0.0f;
    s->x2c = 0.0f;
    s->x30 = 0.0f;
    s->x34 = 0.0f;
    s->x38 = 0.0f;
    s->x1c = 0.0f;
    s->x20 = 0.0f;
    s->x24 = 0.0f;
    s->x28 = 0.0f;
    s->x4a = 0;
    s->x4e = 0;
    s->x4c = 0;
    s->x48 = 0;
    s->x3c = 1.0f;
    s->x40 = 1.0f;
    s->x44 = 0;
    s->x49 = 0;
    cw[kind + 4] = obj;
    obj->body->x4 = kind;
}
extern void fn_801887EC();
extern void fn_80189900(void *buf, s8 a, s8 b, s32 c, s32 d);
extern void fn_80189834(void *p, f32 f);
extern void fn_80189788(void *buf, void *p, f32 f, s8 a);

void fn_80197998(s8 arg)
{
    s32 i;
    for (i = 0; i < 7; i++) {
        Node *obj = fn_802268E8(lbl_8034710C, fn_801887EC);
        Body *s;
        void *buf;
        void *w;
        obj->body = fn_801E1C7C(0xc0);
        s = obj->body;
        s->x0 = 0;
        buf = fn_801E1C7C(0x64);
        s->xbc = buf;
        fn_80189900(buf, arg, i - 1, 3, 0);
        w = obj->body->x74;
        if (i == 0) {
            fn_80189834(w, 0.0f);
        } else {
            fn_80189788(buf, w, -0.5f, i - 1);
        }
        s->x14 = 320.0f;
        s->x18 = 200.0f;
        s->xc = 320.0f;
        s->x10 = 200.0f;
        s->x2c = 0.0f;
        s->x30 = 0.0f;
        s->x34 = 0.0f;
        s->x38 = 0.0f;
        s->x1c = 0.0f;
        s->x20 = 0.0f;
        s->x24 = 0.0f;
        s->x28 = 0.0f;
        s->x4a = 0;
        s->x4e = 0;
        s->x4c = 0;
        s->x48 = 0;
        s->x3c = 1.0f;
        s->x40 = 1.0f;
        s->x44 = 0;
        s->x49 = 0;
        camp_work.objs[i + 0x41] = obj;
        obj->body->x4 = i + 0x41;
    }
}
extern void fn_80189214(void *buf, void *p, f32 f, s8 a);
extern void fn_8018968C(void *buf, void *p, f32 f, s8 a, s8 b);
extern void fn_801895C0(void *buf, void *p, f32 f, s8 a);

void fn_80197CC4(s8 arg)
{
    s32 i;
    for (i = 0; i < 7; i++) {
        Node *obj = fn_802268E8(lbl_8034710C, fn_801887EC);
        Body *s;
        void *buf;
        void *w;
        obj->body = fn_801E1C7C(0xc0);
        s = obj->body;
        s->x0 = 0;
        buf = fn_801E1C7C(0x64);
        s->xbc = buf;
        fn_80189900(buf, arg, i - 1, 1, 0);
        w = obj->body->x74;
        if (i == 0) {
            fn_80189834(w, 0.0f);
        } else {
            fn_80189214(buf, w, -0.5f, i - 1);
        }
        s->x14 = 320.0f;
        s->x18 = 200.0f;
        s->xc = 320.0f;
        s->x10 = 200.0f;
        s->x2c = 0.0f;
        s->x30 = 0.0f;
        s->x34 = 0.0f;
        s->x38 = 0.0f;
        s->x1c = 0.0f;
        s->x20 = 0.0f;
        s->x24 = 0.0f;
        s->x28 = 0.0f;
        s->x4a = 0;
        s->x4e = 0;
        s->x4c = 0;
        s->x48 = 0;
        s->x3c = 1.0f;
        s->x40 = 1.0f;
        s->x44 = 0;
        s->x49 = 0;
        camp_work.objs[i + 58] = obj;
        obj->body->x4 = i + 58;
    }
}

void fn_80197E48(s8 arg)
{
    s32 i;
    for (i = 0; i < 7; i++) {
        Node *obj = fn_802268E8(lbl_8034710C, fn_801887EC);
        Body *s;
        void *buf;
        void *w;
        obj->body = fn_801E1C7C(0xc0);
        s = obj->body;
        s->x0 = 0;
        buf = fn_801E1C7C(0x64);
        s->xbc = buf;
        fn_80189900(buf, arg, i - 1, 0, 0);
        w = obj->body->x74;
        if (i == 0) {
            fn_80189834(w, 0.0f);
        } else {
            fn_80189214(buf, w, -0.5f, i - 1);
        }
        s->x14 = 320.0f;
        s->x18 = 200.0f;
        s->xc = 320.0f;
        s->x10 = 200.0f;
        s->x2c = 0.0f;
        s->x30 = 0.0f;
        s->x34 = 0.0f;
        s->x38 = 0.0f;
        s->x1c = 0.0f;
        s->x20 = 0.0f;
        s->x24 = 0.0f;
        s->x28 = 0.0f;
        s->x4a = 0;
        s->x4e = 0;
        s->x4c = 0;
        s->x48 = 0;
        s->x3c = 1.0f;
        s->x40 = 1.0f;
        s->x44 = 0;
        s->x49 = 0;
        camp_work.objs[i + 51] = obj;
        obj->body->x4 = i + 51;
    }
}
extern void fn_80189DBC();
extern void fn_80189DB0(void *buf, s8 a);
extern void fn_8018A07C(void *p, s8 a);

void fn_80197FCC(void)
{
    s32 i = 0;
    do {
        Node *obj = fn_802268E8(lbl_8034710C, fn_80189DBC);
        Body *s;
        void *buf;
        obj->body = fn_801E1C7C(0xc0);
        s = obj->body;
        s->x0 = 0;
        buf = fn_801E1C7C(4);
        s->xbc = buf;
        fn_80189DB0(buf, i);
        fn_8018A07C(obj->body->x74, i);
        s->x14 = 0.0f;
        s->x18 = 264.0f;
        s->xc = 0.0f;
        s->x10 = 264.0f;
        s->x2c = 0.0f;
        s->x30 = 0.0f;
        s->x34 = 0.0f;
        s->x38 = 0.0f;
        s->x1c = 0.0f;
        s->x20 = 0.0f;
        s->x24 = 0.0f;
        s->x28 = 0.0f;
        s->x4a = 0;
        s->x4e = 0;
        s->x4c = 0;
        s->x48 = 1;
        s->x3c = 0.7f;
        s->x40 = 1.0f;
        s->x44 = 0;
        s->x49 = 0;
        camp_work.objs[i + 0x91] = obj;
        obj->body->x4 = i + 0x91;
        i++;
    } while (i < 4);
}
extern void fn_8016F138();
extern void fn_8016F128(void *buf, s8 a, s8 b, f32 f);
extern void fn_8016F21C(void *p, s8 a, f32 f);

void fn_80198CF4(void)
{
    Node *obj;
    f32 y;
    s32 i;
    Body *s;
    void *buf;
    for (i = 0; i < 4; i++) {
        obj = fn_802268E8(lbl_8034710C, fn_8016F138);
        obj->body = fn_801E1C7C(0xc0);
        s = obj->body;
        s->x0 = 0;
        buf = fn_801E1C7C(8);
        s->xbc = buf;
        fn_8016F128(buf, i + 1, i + 6, 1.0f);
        fn_8016F21C(obj->body->x74, i + 6, 1.0f);
        s->x14 = 0.0f;
        y = 200.0f + (f32)(i * 64);
        s->x18 = y;
        s->xc = 0.0f;
        s->x10 = y;
        s->x2c = 0.0f;
        s->x30 = 0.0f;
        s->x34 = 0.0f;
        s->x38 = 0.0f;
        s->x1c = 0.0f;
        s->x20 = 0.0f;
        s->x24 = 0.0f;
        s->x28 = 0.0f;
        s->x4a = 0;
        s->x4e = 0;
        s->x4c = 0;
        s->x48 = 1;
        s->x3c = 0.7f;
        s->x40 = 1.0f;
        s->x44 = 0;
        s->x49 = 0;
        camp_work.objs[i + 26] = obj;
        obj->body->x4 = i + 26;
    }
}

void fn_80198E90(void)
{
    Node *obj;
    f32 y;
    s32 i;
    Body *s;
    void *buf;
    for (i = 0; i < 4; i++) {
        obj = fn_802268E8(lbl_8034710C, fn_8016F138);
        obj->body = fn_801E1C7C(0xc0);
        s = obj->body;
        s->x0 = 0;
        buf = fn_801E1C7C(8);
        s->xbc = buf;
        fn_8016F128(buf, i + 1, i, 1.0f);
        fn_8016F21C(obj->body->x74, i, 1.0f);
        s->x14 = 0.0f;
        y = 200.0f + (f32)(i * 64);
        s->x18 = y;
        s->xc = 0.0f;
        s->x10 = y;
        s->x2c = 0.0f;
        s->x30 = 0.0f;
        s->x34 = 0.0f;
        s->x38 = 0.0f;
        s->x1c = 0.0f;
        s->x20 = 0.0f;
        s->x24 = 0.0f;
        s->x28 = 0.0f;
        s->x4a = 0;
        s->x4e = 0;
        s->x4c = 0;
        s->x48 = 1;
        s->x3c = 0.7f;
        s->x40 = 1.0f;
        s->x44 = 0;
        s->x49 = 0;
        camp_work.objs[i + 31] = obj;
        obj->body->x4 = i + 31;
    }
}

void fn_8019936C(void)
{
    Node *obj;
    f32 y;
    s32 i;
    Body *s;
    void *buf;
    for (i = 0; i < 2; i++) {
        obj = fn_802268E8(lbl_8034710C, fn_8016F138);
        obj->body = fn_801E1C7C(0xc0);
        s = obj->body;
        s->x0 = 0;
        buf = fn_801E1C7C(8);
        s->xbc = buf;
        fn_8016F128(buf, i + 1, i + 4, 1.0f);
        fn_8016F21C(obj->body->x74, i + 4, 1.0f);
        s->x14 = 0.0f;
        y = 200.0f + (f32)(i * 64);
        s->x18 = y;
        s->xc = 0.0f;
        s->x10 = y;
        s->x2c = 0.0f;
        s->x30 = 0.0f;
        s->x34 = 0.0f;
        s->x38 = 0.0f;
        s->x1c = 0.0f;
        s->x20 = 0.0f;
        s->x24 = 0.0f;
        s->x28 = 0.0f;
        s->x4a = 0;
        s->x4e = 0;
        s->x4c = 0;
        s->x48 = 1;
        s->x3c = 0.7f;
        s->x40 = 1.0f;
        s->x44 = 0;
        s->x49 = 0;
        camp_work.objs[i + 120] = obj;
        obj->body->x4 = i + 120;
    }
}
extern void fn_8016EE2C();
extern void fn_8016F0D4(void *buf, u8 a, f32 f);
extern void fn_8016EC3C(void *p, u8 a, f32 f, s8 b);

void fn_801999B4(void)
{
    CampWork *cw = &camp_work;
    s32 i;
    for (i = 0; i < (s8)cw->b0c; i++) {
        u8 t = lbl_8030B7F4.party[i];
        Node *obj = fn_802268E8(lbl_8034710C, fn_8016EE2C);
        Body *s;
        void *buf;
        obj->body = fn_801E1C7C(0xc0);
        obj->body->x0 = 0;
        buf = fn_801E1C7C(0x20);
        obj->body->xbc = buf;
        fn_8016F0D4(buf, t, 1.0f);
        fn_8016EC3C(obj->body->x74, t, 1.0f, i);
        s = obj->body;
        s->x14 = 0.0f;
        s->x18 = (f32)(i * 64);
        s->xc = 0.0f;
        s->x10 = (f32)(i * 64);
        s->x2c = 0.0f;
        s->x30 = 0.0f;
        s->x34 = 0.0f;
        s->x38 = 0.0f;
        s->x1c = 0.0f;
        s->x20 = 0.0f;
        s->x24 = 0.0f;
        s->x28 = 0.0f;
        s->x4a = 0;
        s->x4e = 0;
        s->x4c = 0;
        s->x48 = 1;
        s->x3c = 0.7f;
        s->x40 = 1.0f;
        s->x44 = 0;
        s->x49 = 0;
        cw->objs[i] = obj;
        obj->body->x4 = i;
    }
}

void fn_80198A0C(void)
{
    Node *obj;
    s32 i;
    s32 a;
    s32 id;
    Body *s;
    void *buf;
    u8 *cw = (u8*)&camp_work;
    for (i = 0; i < 2; i++) {
        if (i == 0) {
            a = 18;
            id = 155;
        } else {
            a = 19;
            id = 156;
        }
        obj = fn_802268E8(lbl_8034710C, fn_8016F138);
        obj->body = fn_801E1C7C(0xc0);
        s = obj->body;
        s->x0 = 0;
        buf = fn_801E1C7C(8);
        s->xbc = buf;
        fn_8016F128(buf, 1, a, 1.0f);
        fn_8016F21C(obj->body->x74, a, 1.0f);
        s->x14 = 0.0f;
        s->x18 = 264.0f;
        s->xc = 0.0f;
        s->x10 = 264.0f;
        s->x2c = 0.0f;
        s->x30 = 0.0f;
        s->x34 = 0.0f;
        s->x38 = 0.0f;
        s->x1c = 0.0f;
        s->x20 = 0.0f;
        s->x24 = 0.0f;
        s->x28 = 0.0f;
        s->x4a = 0;
        s->x4e = 0;
        s->x4c = 0;
        s->x48 = 1;
        s->x3c = 0.7f;
        s->x40 = 1.0f;
        s->x44 = 0;
        s->x49 = 0;
        *(Node **)(cw + id * 4 + 0x10) = obj;
        obj->body->x4 = id;
    }
}

void fn_80198B80(void)
{
    Node *obj;
    s32 i;
    s32 a;
    s32 id;
    Body *s;
    void *buf;
    u8 *cw = (u8*)&camp_work;
    for (i = 0; i < 2; i++) {
        if (i == 0) {
            a = 10;
            id = 5;
        } else {
            a = 11;
            id = 30;
        }
        obj = fn_802268E8(lbl_8034710C, fn_8016F138);
        obj->body = fn_801E1C7C(0xc0);
        s = obj->body;
        s->x0 = 0;
        buf = fn_801E1C7C(8);
        s->xbc = buf;
        fn_8016F128(buf, 1, a, 1.0f);
        fn_8016F21C(obj->body->x74, a, 1.0f);
        s->x14 = 0.0f;
        s->x18 = 264.0f;
        s->xc = 0.0f;
        s->x10 = 264.0f;
        s->x2c = 0.0f;
        s->x30 = 0.0f;
        s->x34 = 0.0f;
        s->x38 = 0.0f;
        s->x1c = 0.0f;
        s->x20 = 0.0f;
        s->x24 = 0.0f;
        s->x28 = 0.0f;
        s->x4a = 0;
        s->x4e = 0;
        s->x4c = 0;
        s->x48 = 1;
        s->x3c = 0.7f;
        s->x40 = 1.0f;
        s->x44 = 0;
        s->x49 = 0;
        *(Node **)(cw + id * 4 + 0x10) = obj;
        obj->body->x4 = id;
    }
}

void fn_801991EC(void)
{
    s32 i;
    for (i = 0; i < 7; i++) {
        Node *obj = fn_802268E8(lbl_8034710C, fn_801887EC);
        Body *s;
        void *buf;
        void *w;
        obj->body = fn_801E1C7C(0xc0);
        s = obj->body;
        s->x0 = 0;
        buf = fn_801E1C7C(0x64);
        s->xbc = buf;
        fn_80189900(buf, i, i - 1, 4, 0);
        w = obj->body->x74;
        if (i == 0) {
            fn_80189834(w, 0.0f);
        } else {
            fn_80189788(buf, w, -0.5f, i - 1);
        }
        s->x14 = 320.0f;
        s->x18 = 200.0f;
        s->xc = 320.0f;
        s->x10 = 200.0f;
        s->x2c = 0.0f;
        s->x30 = 0.0f;
        s->x34 = 0.0f;
        s->x38 = 0.0f;
        s->x1c = 0.0f;
        s->x20 = 0.0f;
        s->x24 = 0.0f;
        s->x28 = 0.0f;
        s->x4a = 0;
        s->x4e = 0;
        s->x4c = 0;
        s->x48 = 0;
        s->x3c = 1.0f;
        s->x40 = 1.0f;
        s->x44 = 0;
        s->x49 = 0;
        camp_work.objs[i + 0x4f] = obj;
        obj->body->x4 = i + 0x4f;
    }
}

void fn_80197B1C(s32 arg)
{
    s32 i;
    for (i = 0; i < 7; i++) {
        Node *obj = fn_802268E8(lbl_8034710C, fn_801887EC);
        Body *s;
        void *buf;
        void *w;
        obj->body = fn_801E1C7C(0xc0);
        s = obj->body;
        s->x0 = 0;
        buf = fn_801E1C7C(0x64);
        s->xbc = buf;
        fn_80189900(buf, arg, i - 1, 2, 0);
        w = obj->body->x74;
        if (i == 0) {
            fn_80189834(w, 0.0f);
        } else if (i == 1) {
            fn_8018968C(buf, w, -0.5f, arg, i - 1);
        } else {
            fn_801895C0(buf, w, -0.5f, i - 1);
        }
        s->x14 = 320.0f;
        s->x18 = 200.0f;
        s->xc = 320.0f;
        s->x10 = 200.0f;
        s->x2c = 0.0f;
        s->x30 = 0.0f;
        s->x34 = 0.0f;
        s->x38 = 0.0f;
        s->x1c = 0.0f;
        s->x20 = 0.0f;
        s->x24 = 0.0f;
        s->x28 = 0.0f;
        s->x4a = 0;
        s->x4e = 0;
        s->x4c = 0;
        s->x48 = 0;
        s->x3c = 1.0f;
        s->x40 = 1.0f;
        s->x44 = 0;
        s->x49 = 0;
        camp_work.objs[i + 72] = obj;
        obj->body->x4 = i + 72;
    }
}

void fn_80199508(void)
{
    s32 i;
    for (i = 0; i < 8; i++) {
        CampObj *obj = ((CampObj *)fn_802268E8(lbl_8034710C, fn_8018E82C));
        void *buf;
        CampSub *s;
        obj->sub = fn_801E1C7C(0xc0);
        obj->sub->x0 = 0;
        buf = fn_801E1C7C(0xc);
        obj->sub->xbc = buf;
        fn_8018E81C(buf, 5, i);
        fn_80191A04(obj->sub->x74, 5);
        s = obj->sub;
        s->x14 = 0.0f;
        s->x18 = 256.0f;
        s->xc = 0.0f;
        s->x10 = 256.0f;
        s->x2c = 0.0f;
        s->x30 = 0.0f;
        s->x34 = 0.0f;
        s->x38 = 0.0f;
        s->x1c = 0.0f;
        s->x20 = 0.0f;
        s->x24 = 0.0f;
        s->x28 = 0.0f;
        s->x4a = 0;
        s->x4e = 0;
        s->x4c = 0;
        s->x48 = 1;
        s->x3c = 0.7f;
        s->x40 = 1.0f;
        s->x44 = 0;
        s->x49 = 0;
        (*(CampWork_80199508*)&camp_work).objs[i + 0x7a] = obj;
        obj->sub->x4 = i + 0x7a;
    }
}

void fn_80199678(void) {
    Body_80199678* b;
    Node_80199678* n;
    void* pos;
    void* t;
    s32 i;
    for (i = 0; i < 12; i++) {
        n = ((Node_80199678*)fn_802268E8(lbl_8034710C, fn_8018E82C));
        n->body = fn_801E1C7C(0xc0);
        n->body->x0 = 0;
        t = fn_801E1C7C(0xc);
        n->body->xbc = t;
        pos = n->body->x74;
        switch (i) {
        case 0:
        case 2:
            fn_8018E81C((void *)(t), 1, -1);
            fn_80191A04((void *)(pos), 3);
            break;
        case 1:
        case 3:
            fn_8018E81C((void *)(t), 2, -1);
            fn_80191A04((void *)(pos), 4);
            break;
        case 4:
        case 5:
            fn_8018E81C((void *)(t), 7, -1);
            fn_80191A04((void *)(pos), 7);
            break;
        case 6:
        case 7:
            fn_8018E81C((void *)(t), 8, -1);
            fn_80191A04((void *)(pos), 8);
            break;
        case 8:
            fn_8018E81C((void *)(t), 9, -1);
            fn_80191A04((void *)(pos), 9);
            break;
        case 9:
            fn_8018E81C((void *)(t), 0xa, -1);
            fn_80191A04((void *)(pos), 0xa);
            break;
        case 10:
            fn_8018E81C((void *)(t), 0xd, -1);
            fn_80191A04((void *)(pos), 0xd);
            break;
        case 11:
            fn_8018E81C((void *)(t), 0xe, -1);
            fn_80191A04((void *)(pos), 0xe);
            break;
        }
        b = n->body;
        b->x14 = 0.0f;
        b->x18 = 256.0f;
        b->xc = 0.0f;
        b->x10 = 256.0f;
        b->x2c = 0.0f;
        b->x30 = 0.0f;
        b->x34 = 0.0f;
        b->x38 = 0.0f;
        b->x1c = 0.0f;
        b->x20 = 0.0f;
        b->x24 = 0.0f;
        b->x28 = 0.0f;
        b->x4a = 0;
        b->x4e = 0;
        b->x4c = 0;
        b->x48 = 0;
        b->x3c = 1.0f;
        b->x40 = 1.0f;
        b->x44 = 0;
        b->x49 = 0;
        (*(CampWork_80199678*)&camp_work).objs[0x6c + i] = n;
        n->body->x4 = 0x6c + i;
    }
}

void fn_80197270(s8 a) {
    extern void fn_8018B278(void*, s8, s8, f32);
    extern void fn_8018DABC(void*, s8, s8, s8, s8);
    s32 j;
    s32 i;
    Node_80197270 **objs = (Node_80197270 **)&camp_work;
    for (j = 0; j < 3; j++) {
        for (i = 0; i < 6; i++) {
            Node_80197270* n;
            Body_80197270* b;
            void* t;
            f32 y;
            switch (j) {
            case 0:
                if (i >= 4) continue;
                break;
            case 1:
                if (i >= 5) continue;
                break;
            case 2:
                break;
            }
            n = (Node_80197270 *)fn_802268E8(lbl_8034710C, fn_8018A16C);
            n->body = fn_801E1C7C(0xc0);
            b = n->body;
            b->x0 = 0;
            t = fn_801E1C7C(0xb4);
            b->xbc = t;
            fn_8018DABC(t, a, i, j, 1);
            fn_8018B278(b, j, i, 1.0f);
            b->x14 = 320.0f;
            b->x18 = 120.0f + (f32)(i * 0x40);
            b->xc = 320.0f;
            b->x10 = 120.0f + (f32)(i * 0x40);
            b->x2c = 0.0f;
            b->x30 = 0.0f;
            b->x34 = 0.0f;
            b->x38 = 0.0f;
            b->x1c = 0.0f;
            b->x20 = 0.0f;
            b->x24 = 0.0f;
            b->x28 = 0.0f;
            b->x4a = 0;
            b->x4e = 0;
            b->x4c = 0;
            b->x48 = 0;
            b->x3c = 1.0f;
            b->x40 = 1.0f;
            b->x44 = 0;
            b->x49 = 0;
            switch (j) {
            case 0:
                if (i == 3) {
                    b->x14 = 320.0f;
                    y = 120.0f + (f32)((i + 2) << 6);
                    b->x18 = y;
                    b->xc = 320.0f;
                    b->x10 = y;
                }
                objs[0x27 + i] = n;
                n->body->x4 = i + 0x23;
                break;
            case 1:
                if (i == 4) {
                    b->x14 = 320.0f;
                    y = 120.0f + (f32)((i + 1) << 6);
                    b->x18 = y;
                    b->xc = 320.0f;
                    b->x10 = y;
                }
                objs[0x2b + i] = n;
                n->body->x4 = i + 0x27;
                break;
            case 2:
                objs[0x30 + i] = n;
                n->body->x4 = i + 0x2c;
                break;
            }
        }
    }
}

extern void fn_80186E4C(void);
extern void fn_80187D78(void *p, f32 f);
extern void fn_80187E68(void *p);
extern void fn_80186E20(void *p, u8 c, s8 b, u8 a, f32 v);

void fn_801974B4(s32 arg)
{
    s8 who = arg;
    s32 i;
    for (i = 0; i < 2; i++) {
        Node *n;
        Body *b;
        void *w;
        void *buf;
        CampReq r;
        n = fn_802268E8(lbl_8034710C, fn_80186E4C);
        n->body = fn_801E1C7C(0xc0);
        b = n->body;
        b->x0 = 0;
        buf = fn_801E1C7C(0xc);
        b->xbc = buf;
        w = b->x74;
        r.a = who;
        r.b = 1;
        r.d = 0;
        fn_801F1280(&r);
        if (i == 0) {
            fn_80187D78(w, 1.0f);
            fn_80195B38(3, r.e[0].x6, 1);
            fn_80186E20(buf, 0, 3, 1, 1.0f);
        } else {
            fn_80187E68(w);
            fn_80195B38(4, r.e[0].x6, 1);
            fn_80186E20(buf, 0, 4, 1, 1.0f);
        }
        b->x14 = 0.0f;
        b->x18 = 0.0f;
        b->xc = 0.0f;
        b->x10 = 0.0f;
        b->x2c = 0.0f;
        b->x30 = 0.0f;
        b->x34 = 0.0f;
        b->x38 = 0.0f;
        b->x1c = 0.0f;
        b->x20 = 0.0f;
        b->x24 = 0.0f;
        b->x28 = 0.0f;
        b->x4a = 0;
        b->x4e = 0;
        b->x4c = 0;
        b->x48 = 0;
        b->x3c = 1.0f;
        b->x40 = 1.0f;
        b->x44 = 0;
        b->x49 = 0;
        camp_work.objs[0x5d + i] = n;
        n->body->x4 = i + 0x5d;
    }
}

extern void fn_8019ADA0(void);
extern void fn_8019B44C(void);
extern void fn_8019AD94(void *p, u32 a, u32 b);
extern void fn_8019B36C(u8 *o);
extern void fn_8019B42C(void *p, u32 a);
extern void fn_8019BD2C(void *o, s32 mode);

/* The common placement of a camp panel at y 264. */
static inline void BodyInit264(Body *b, u8 en, f32 sx) {
    b->x14 = 0.0f;
    b->x18 = 264.0f;
    b->xc = 0.0f;
    b->x10 = 264.0f;
    b->x2c = 0.0f;
    b->x30 = 0.0f;
    b->x34 = 0.0f;
    b->x38 = 0.0f;
    b->x1c = 0.0f;
    b->x20 = 0.0f;
    b->x24 = 0.0f;
    b->x28 = 0.0f;
    b->x4a = 0;
    b->x4e = 0;
    b->x4c = 0;
    b->x48 = en;
    b->x3c = sx;
    b->x40 = 1.0f;
    b->x44 = 0;
    b->x49 = 0;
}

void fn_80198118(void) {
    CampWork *cw = &camp_work;
    s32 i;
    s32 a;
    s32 k;
    Node *n;
    Body *b;
    for (i = 0; i < 4; i++) {
        switch (i) {
        case 0: a = 0xe; k = 0x89; break;
        case 1: a = 0xf; k = 0x8a; break;
        case 2: a = 0x10; k = 0x8b; break;
        case 3:
        default: a = 0x11; k = 0x8c; break;
        }
        n = fn_802268E8(lbl_8034710C, fn_8016F138);
        n->body = fn_801E1C7C(0xc0);
        b = n->body;
        b->x0 = 0;
        fn_8016F128(b->xbc = fn_801E1C7C(8), 1, a, 1.0f);
        fn_8016F21C(n->body->x74, a, 1.0f);
        BodyInit264(b, 1, 0.7f);
        cw->objs[k] = n;
        n->body->x4 = k;
    }
    n = fn_802268E8(lbl_8034710C, fn_8019ADA0);
    n->body = fn_801E1C7C(0xc0);
    b = n->body;
    b->x0 = 0;
    fn_8019AD94(b->xbc = fn_801E1C7C(8), 0, 0);
    fn_8019B36C(n->body->x74);
    BodyInit264(b, 0, 1.0f);
    cw->objs[0x97] = n;
    n->body->x4 = 0x97;
    for (i = 0; i < 3; i++) {
        n = fn_802268E8(lbl_8034710C, fn_8019B44C);
        n->body = fn_801E1C7C(0xc0);
        b = n->body;
        b->x0 = 0;
        fn_8019B42C(b->xbc = fn_801E1C7C(0xc), i);
        fn_8019BD2C(n->body->x74, i);
        BodyInit264(b, 0, 1.0f);
        cw->objs[0x98 + i] = n;
        n->body->x4 = 0x98 + i;
    }
}

void fn_80193FF8(s32 n) {
    lbl_803467CC = (lbl_803467CC == 0);
    fn_801F4EA0(n, lbl_803467CC);
}

void fn_801957D8(u8 v) {
    (*(CampWork_801957D8*)&camp_work).objs[104]->body->xbc[3] = v;
    (*(CampWork_801957D8*)&camp_work).objs[105]->body->xbc[3] = v;
}

void fn_801968B8(void) {
    s32 i;
    for (i = 0; i < 157; i++) {
        if ((*(CampWork_801968B8*)&camp_work).objs[i] != 0) {
            (*(CampWork_801968B8*)&camp_work).objs[i]->x19 = 100;
        }
    }
}

s32 fn_801940AC(void)
{
    s32 r = fn_801D6E38(0);
    s32 ok = (r == 1) ? 1 : 0;
    lbl_80307628.x8 = r;
    if (ok == 1) {
        return 1;
    } else {
        return 0;
    }
}

s32 fn_801949AC(void)
{
    CampCtrl *p;
    s32 n;
    switch (lbl_80307638[15].cur[0].sel) {
    case 0:
        p = &lbl_80307638[16];
        n = 6;
        break;
    case 1:
        n = 8;
        p = &lbl_80307638[16];
        break;
    }
    return p->cur[0].sel + p->cur[4].sel * n;
}

s32 fn_801954EC(CampReq *r)
{
    CampCtrl *c = lbl_8034710C->holder->ctrl;

    fn_80195540(r);
    return r->e[c->cur[0].sel].x0;
}

s32 fn_80194B18(s32 id) {
    s32 i;

    for (i = 0; i < 0x16; i++) {
        if (fn_801E4BF4(i) == 1) {
            fn_801E4BBC(i);
        }
    }
    if (fn_801E4BBC(id) == 1) {
        return 1;
    }
    return 0;
}

static inline s32 HasAny(s32 idx) {
    s32 i = 0;
    SaveChar *p = &lbl_8030B7F4.chr[idx];

    for (; i < 0x24; i++) {
        if (fn_801F3F88(p, (s8)i) != 0) {
            return 1;
        }
    }
    return 0;
}
s32 fn_801956EC(s32 idx) {
    if (HasAny(idx) == 1) {
        return 0xf;
    }
    return 0xd;
}

int fn_80194378(s8 i)
{
    return lbl_80347148[i];
}

s8 fn_80194C18(s8 idx)
{
    return lbl_802D8E64[idx].post;
}


s32 fn_80194CC8(void) {
    s32 n = 0;
    s32 i;
    for (i = 0; i < 8; i++) {
        if (FlagTest(i + 0xac8)) {
            n++;
        }
    }
    return n;
}

s32 fn_8019438C(void) {
    s32 r = 0;
    switch (lbl_80307638[15].cur[0].sel) {
    case 0:
        r = 0;
        break;
    case 1:
        r = 1;
        break;
    }
    return r;
}

s32 fn_801943C0(void) {
    s32 r = 0x10;
    switch (lbl_80307638[15].cur[0].sel) {
    case 0:
        r = 0x10;
        break;
    case 1:
        return 0x10;
    }
    return r;
}

s32 fn_801943F4(void) {
    s32 r = 6;
    switch (lbl_80307638[15].cur[0].sel) {
    case 0:
        r = 6;
        break;
    case 1:
        r = 8;
        break;
    }
    return r;
}

s32 fn_80194428(void) {
    s32 r = 0x8e;
    switch (lbl_80307638[15].cur[0].sel) {
    case 0:
        r = 0x8e;
        break;
    case 1:
        r = 0x90;
        break;
    }
    return r;
}

s32 fn_8019445C(void) {
    s32 r = 0x8d;
    switch (lbl_80307638[15].cur[0].sel) {
    case 0:
        r = 0x8d;
        break;
    case 1:
        r = 0x8f;
        break;
    }
    return r;
}

s32 fn_80194490(void) {
    s32 r = 0x87;
    switch (lbl_80307638[15].cur[0].sel) {
    case 0:
        r = 0x87;
        break;
    case 1:
        r = 0x88;
        break;
    }
    return r;
}

/* fn_80195EA4's body. */
static inline void CampReqRun(CampReq *r, s8 a, s32 b, s32 c, s8 mode)
{
    r->a = a;
    r->b = b;
    r->d = c;
    switch (mode) {
    case 1:
        fn_801F224C(r);
        break;
    case 0:
        fn_801F1774(r);
        break;
    case 3:
        fn_801F1280(r);
        break;
    case 2:
        fn_801F2518(r);
        break;
    case 4:
        fn_801F1280(r);
        break;
    }
}

s32 fn_80194E6C(void)
{
    CampReq req;
    CampCtrl *ctl = lbl_8034710C->holder->ctrl;
    CampCtrl *s = &lbl_80307638[11];
    CampReqRun(&req, s->cur[0].sel, s->cur[2].sel + 6, ctl->cur[4].sel, 3);
    return req.count;
}

CampCtrl *fn_80195540(CampReq *r)
{
    s32 a = lbl_8030B7F4.party[lbl_80307638[1].cur[0].sel];
    s32 idx;
    s8 kind;
    CampCtrl *e;

    switch (lbl_80307638[3].cur[0].sel) {
    case 0:
        idx = 7;
        kind = 0;
        break;
    case 1:
        idx = 5;
        kind = 1;
        break;
    case 2:
        idx = 10;
        kind = 2;
        break;
    case 3:
        idx = 8;
        kind = 3;
        break;
    }
    e = &lbl_80307638[idx];
    CampReqRun(r, a, e->cur[1].sel, e->cur[4].sel, kind);
    return e;
}

void fn_80195EA4(CampReq *o, s8 a, s32 b, s32 c, s8 mode) {
    o->a = a;
    o->b = b;
    o->d = c;
    switch (mode) {
    case 1:
        fn_801F224C(o);
        break;
    case 0:
        fn_801F1774(o);
        break;
    case 3:
        fn_801F1280(o);
        break;
    case 2:
        fn_801F2518(o);
        break;
    case 4:
        fn_801F1280(o);
        break;
    }
}

s32 fn_80195CD0(s8 a0, s8 a1, s8 a2, u8 a3) {
    CampReq r;
    s32 res = 1;

    r.a = a0;
    r.b = a1;
    r.d = a3;
    switch (a2) {
    case 1:
        fn_801F224C(&r);
        break;
    case 0:
        fn_801F1774(&r);
        break;
    case 3:
        fn_801F1280(&r);
        break;
    case 2:
        fn_801F2518(&r);
        break;
    case 4:
        fn_801F1280(&r);
        break;
    }
    if (r.b != -1) {
        res = r.count;
    }
    return res;
}

void CampMenuRunScreen(void) {
    fn_80195F9C();
    camp_screen_funcs[camp_screen]();
    if (lbl_8034713C != 0) {
        fn_801D6CBC(lbl_80347140, lbl_80347134);
        lbl_8034713C -= 1;
        if (lbl_8034713C <= 0) {
            fn_801D6C3C(lbl_80347140);
        }
    }
}

s8 fn_801952D0(u32 mask)
{
    s8 count = 0;
    s32 i;
    for (i = 0; i < 32; i++) {
        if (mask & (1 << i)) {
            count++;
        }
    }
    return count;
}
